#include "board.h"
#include "realtime.h"

static uint16_t phase;
static volatile uint16_t pending, active, age = 2000;
static volatile uint8_t events;
static volatile __BIT enabled, fault, paused, waiting = 1, fresh;

void realtime_tick(void) {
    if (age < 2000)
        ++age;
    if (age >= 2000) {
        waiting = 1;
        fresh = 0;
        pending = active = 0;
    }
    if (++phase == 1000) {
        phase = 0;
        active = pending;
        events |= REALTIME_PID | REALTIME_GRAPH;
    }
    heat = enabled && !fault && !paused && !waiting && active > phase;
}

uint8_t realtime_take(void) {
    uint8_t saved = EA, result;
    EA = 0;
    result = events;
    events = 0;
    EA = saved;
    return result;
}

void realtime_enable(uint8_t value) {
    uint8_t saved = EA;
    EA = 0;
    enabled = value != 0;
    waiting = 1;
    fresh = 0;
    pending = active = 0;
    heat = 0;
    EA = saved;
}
uint8_t realtime_enabled(void) {
    return enabled;
}
uint8_t realtime_faulted(void) {
    return fault;
}
void realtime_fault(void) {
    uint8_t saved = EA;
    EA = 0;
    fault = 1;
    pending = active = 0;
    heat = 0;
    EA = saved;
}
void realtime_pause(void) {
    uint8_t saved = EA;
    EA = 0;
    paused = waiting = 1;
    fresh = 0;
    pending = active = 0;
    heat = 0;
    EA = saved;
}
void realtime_resume(void) {
    uint8_t saved = EA;
    EA = 0;
    paused = 0;
    age = 2000;
    fresh = 0;
    EA = saved;
}
void realtime_sample(void) {
    uint8_t saved = EA;
    EA = 0;
    if (!paused && !fault) {
        age = 0;
        fresh = 1;
    }
    EA = saved;
}
uint8_t realtime_needs_reset(void) {
    return waiting;
}
void realtime_publish(uint16_t duty) {
    uint8_t saved = EA;
    EA = 0;
    if (enabled && !fault && !paused && fresh && age < 2000) {
        pending = duty > 1000 ? 1000 : duty;
        waiting = 0;
        fresh = 0;
    }
    EA = saved;
}
uint16_t realtime_duty(void) {
    uint8_t saved = EA;
    uint16_t result;
    EA = 0;
    result = active;
    EA = saved;
    return result;
}
