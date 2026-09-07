#include "board.h"
#include "buttons.h"

static uint16_t single_hold_ticks[2], both_hold_ticks;
static uint8_t single_release_pending;
static volatile uint8_t pending_button_events = BUTTON_EVENT_ALL_RELEASED, held_states;
/* A gesture held across startup must not enable the heater on release. */
static __BIT both_gesture, gesture_blocked = 1, was_pressed;

void buttons_tick(uint8_t pressed) {
    uint8_t n, mask;
    held_states = 0;
    if (!pressed) {
        if (was_pressed)
            pending_button_events |= BUTTON_EVENT_ALL_RELEASED;
        was_pressed = 0;
        if (!gesture_blocked) {
            if (both_gesture)
                pending_button_events |= BUTTON_EVENT_BOTH_TAP;
            else
                pending_button_events |= single_release_pending;
        }
        single_hold_ticks[0] = single_hold_ticks[1] = both_hold_ticks = 0;
        single_release_pending = 0;
        both_gesture = gesture_blocked = 0;
        return;
    }
    was_pressed = 1;
    pending_button_events &= ~BUTTON_EVENT_ALL_RELEASED;
    if (gesture_blocked)
        return;
    if (pressed == 3 && single_hold_ticks[0] < 500 && single_hold_ticks[1] < 500) {
        both_gesture = 1;
        single_release_pending = 0;
        single_hold_ticks[0] = single_hold_ticks[1] = 0;
        if (both_hold_ticks < 500)
            ++both_hold_ticks;
        if (both_hold_ticks == 500) {
            pending_button_events |= BUTTON_EVENT_BOTH_HOLD;
            gesture_blocked = 1;
        }
        return;
    }
    if (both_gesture)
        return;
    for (n = 0; n < 2; ++n) {
        mask = 1 << n;
        if (pressed & mask) {
            single_release_pending |= mask;
            if (single_hold_ticks[n] < 500)
                ++single_hold_ticks[n];
            if (single_hold_ticks[n] == 500)
                held_states |= n ? BUTTON_STATE_RIGHT_HELD : BUTTON_STATE_LEFT_HELD;
        } else if (single_release_pending & mask) {
            pending_button_events |= mask;
            single_release_pending &= ~mask;
            single_hold_ticks[n] = 0;
        }
    }
}

uint8_t buttons_take(void) {
    uint8_t saved = EA, result;
    EA = 0;
    result = pending_button_events | held_states;
    pending_button_events = 0;
    EA = saved;
    return result;
}
