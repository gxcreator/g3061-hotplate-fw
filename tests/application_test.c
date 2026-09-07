/* Production application sources with simulated hardware. Including the sources
 * lets tests reset private state without shipping test-only firmware APIs.
 * Host integers/bit variables and scheduling do not prove the SDCC ABI. */
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#ifdef NDEBUG
#error These tests require assertions
#endif

#define BOARD_H
#define CONFIG_H
#define __BIT _Bool
#define __code
static volatile uint8_t EA = 1, heat;
#define vol_channel 0
#define tem_channel 1
#define vcc_channel 15

#include "../src/settings.c"
#include "../src/pid.c"
#include "../src/buttons.c"
#include "../src/realtime.c"
#include "../src/temperature.c"
#include "../src/measurements.c"
#include "../src/ui.c"

/* Execute the actual main-loop pipeline with scripted display/ADC callbacks. */
#define ___FW_EXTI_H___
#define INTERRUPT(name, vector) void name(void)
#define HEATER_PIN 0x10
#define BUTTON_PINS 0x0c
#define SUPPLY_ADC_PIN 1
#define TEMPERATURE_ADC_PIN 2
#define GPIO_Mode_Output_PP 1
#define GPIO_Mode_Input_HIP 2
#define GPIO_Mode_InOut_OD 3
#define HAL_State_ON 1
static uint8_t key0, key1, extended, startup_step;
static void mock_p3(uint8_t pins, uint8_t mode);
static void mock_p1(uint8_t pins, uint8_t mode);
#define GPIO_P3_SetMode(pins, mode) mock_p3(pins, mode)
#define GPIO_P1_SetMode(pins, mode) mock_p1(pins, mode)
#define SFRX_ON() (extended = 1)
#define EXTI_Global_SetIntState(value) (EA = (value))
#define main firmware_main
#include "../src/main.c"
#undef main

static uint8_t eeprom[0x800];
static unsigned erases[4], writes[7], reads[7], displays, draws;
static unsigned inverted_draws;
static struct {
    uint8_t x, y, width, height, inverted;
    const uint8_t *bmp;
} draw_log[16];
static unsigned draw_count;
static uint8_t record_draws;
static uint16_t adc_temperature = 1000, adc_reference = 1477, adc_supply = 2048;
static unsigned adc_calls[16], stall_ticks;
static uint8_t stalled_low;
static uint8_t integration, verify_resume;
static uint8_t rendered_screen;
static uint16_t rendered_target;
static jmp_buf pipeline_done;

static void mock_p3(uint8_t pins, uint8_t mode) {
    if (pins == HEATER_PIN) {
        assert(mode == GPIO_Mode_Output_PP && !heat && startup_step == 0);
        startup_step = 1;
    } else {
        assert(pins == BUTTON_PINS && mode == GPIO_Mode_InOut_OD && key0 && key1 &&
               startup_step == 2);
        startup_step = 3;
    }
}
static void mock_p1(uint8_t pins, uint8_t mode) {
    assert(pins == 3 && mode == GPIO_Mode_Input_HIP && extended && startup_step == 1);
    startup_step = 2;
}
void adc_init(void) {
    assert(startup_step == 3 && extended);
    startup_step = 4;
}
void OLED_Init(void) {
    assert(startup_step == 4);
    startup_step = 5;
}
void Timer0Init(void) {
    assert(startup_step == 5);
    startup_step = 6;
}

static void ticks(unsigned n) {
    while (n--)
        realtime_tick();
}

static void reset_realtime(void) {
    phase = pending = active = events = 0;
    age = 2000;
    enabled = fault = paused = fresh = 0;
    waiting = 1;
    heat = 0;
    EA = 1;
}

static unsigned address_index(uint16_t address) {
    unsigned n;
    for (n = 0; n < 7; ++n)
        if (address == addresses[n])
            return n;
    assert(0);
    return 0;
}

void EEPROM_read_n(uint16_t address, uint8_t *bytes, uint16_t size) {
    unsigned n = address_index(address);
    assert(size == (n == 6 ? 1 : 2));
    ++reads[n];
    memcpy(bytes, eeprom + address, size);
}
void EEPROM_write_n(uint16_t address, uint8_t *bytes, uint16_t size) {
    unsigned n = address_index(address);
    assert(size == (n == 6 ? 1 : 2));
    assert(paused && !heat);
    ticks(1100); // Model interrupts between IAP operations, not CPU-halted time.
    assert(!heat);
    ++writes[n];
    memcpy(eeprom + address, bytes, size);
    if (integration)
        verify_resume = 1;
}
void EEPROM_SectorErase(uint16_t address) {
    assert(address % 512 == 0 && address < sizeof eeprom);
    assert(paused && !heat);
    ticks(1100);
    assert(!heat);
    ++erases[address / 512];
    memset(eeprom + address, 0xff, 512);
}

uint16_t get_adc(uint16_t channel) {
    assert(channel < 16);
    if (verify_resume) {
        assert(enabled && waiting && !fresh && !paused && !heat && !integral && !previous);
        verify_resume = 0;
    }
    ++adc_calls[channel];
    if (stall_ticks) {
        ticks(stall_ticks);
        stall_ticks = 0;
        stalled_low = !heat && realtime_needs_reset();
    }
    if (channel == tem_channel)
        return adc_temperature;
    if (channel == vcc_channel)
        return adc_reference;
    assert(channel == vol_channel);
    return adc_supply;
}

void OLED_display_clear(void) {}
void OLED_Clear(void) {
    if (integration) {
        assert(integration == 5 && fault && !heat);
        longjmp(pipeline_done, 1);
    }
}
void OLED_display(void) {
    ++displays;
    rendered_screen = screen;
    rendered_target = settings_get(SET_TARGET);
    if (!integration)
        return;
    assert(startup_step == 6 && extended && EA);
    if (integration == 1) {
        assert(!enabled && !heat);
        pending_button_events = BUTTON_EVENT_BOTH_TAP;
    } else if (integration == 2) {
        assert(enabled && !waiting && pending && !active);
        ticks(1000);
        assert(heat);
        pending_button_events = BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_ALL_RELEASED;
    } else if (integration == 3) {
        assert(enabled && !waiting && pending && !active && !verify_resume);
        assert(settings_get(SET_TARGET) == 301 && !settings_dirty());
        ticks(1000);
        assert(heat);
        stall_ticks = 2000;
    } else if (integration == 4) {
        assert(stalled_low && enabled && !waiting && pending);
        adc_temperature = 0;
    } else
        assert(0);
    ++integration;
}
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t c, uint8_t size) {
    assert(x < 128 && y < 8 && size == 16);
    (void)c;
}
void OLED_DrawPixel(uint8_t x, uint8_t y, uint8_t color) {
    assert(x < 128 && y < 64 && color <= 1);
}
void OLED_DrawLine(uint8_t x, uint8_t y, uint8_t x2, uint8_t y2, uint8_t color) {
    assert(x < 128 && x2 < 128 && y < 64 && y2 < 64 && color <= 1);
}
void OLED_DrawBitmap(uint8_t x, uint8_t y, uint8_t width, uint8_t height, const uint8_t *bmp,
                     uint8_t inverted) {
    unsigned n;
    volatile uint8_t byte;
    assert(inverted <= 1);
    assert(x + width <= 128 && y + height / 8 <= 8);
    if (record_draws) {
        assert(draw_count < sizeof draw_log / sizeof draw_log[0]);
        draw_log[draw_count].x = x;
        draw_log[draw_count].y = y;
        draw_log[draw_count].width = width;
        draw_log[draw_count].height = height;
        draw_log[draw_count].bmp = bmp;
        draw_log[draw_count++].inverted = inverted;
    }
    if (x == 22 && y == 0) {
        assert(width == 28 && height == 56);
        switch (screen) {
        case PID_MENU:
        case PID_EDIT:
            assert(selection < sizeof PID / sizeof PID[0]);
            assert(bmp == PID[selection]);
            assert(inverted == (screen == PID_MENU && selection != PID_BACK));
            break;
        case TEMP_MENU:
        case TEMP_EDIT:
            assert(selection < sizeof TEMP / sizeof TEMP[0]);
            assert(bmp == TEMP[selection]);
            assert(inverted == (screen == TEMP_MENU && selection != TEMP_BACK));
            break;
        case MODE_MENU:
            assert(selection < sizeof mode / sizeof mode[0]);
            assert(bmp == mode[selection]);
            assert(inverted == (selection != MODE_BACK && selection != settings_get(SET_MODE)));
            break;
        default:
            assert(0);
        }
    } else
        assert(!inverted);
    inverted_draws += inverted;
    for (n = 0; n < (unsigned)width * (height / 8); ++n)
        byte = bmp[n];
    (void)byte;
    ++draws;
}

static void seed(uint16_t target, uint16_t maximum, uint16_t minimum) {
    const uint16_t defaults[] = {target, 10, 20, 30, maximum, minimum, 0};
    unsigned n;
    memset(eeprom, 0xff, sizeof eeprom);
    for (n = 0; n < 7; ++n) {
        eeprom[addresses[n]] = (uint8_t)defaults[n];
        if (n != 6)
            eeprom[addresses[n] + 1] = defaults[n] >> 8;
    }
    settings_load();
}

static void commit(void) {
    realtime_pause();
    settings_commit();
    pid_reset();
    realtime_resume();
}

static void test_settings(void) {
    unsigned n;
    const uint16_t layout[] = {0, 0x200, 0x204, 0x208, 0x400, 0x404, 0x600};
    assert(!memcmp(layout, addresses, sizeof layout));
    memset(eeprom, 0xff, sizeof eeprom);
    settings_load();
    assert(settings_get(SET_TARGET) == 350 && settings_get(SET_MAX) == 350);
    assert(settings_get(SET_MIN) == 0 && settings_get(SET_MODE) == 0);
    assert(settings_get(SET_KP) == 500 && settings_get(SET_KI) == 500 &&
           settings_get(SET_KD) == 500);
    assert(settings_dirty() == 1);
    seed(300, 350, 1);
    for (n = 0; n < 7; ++n)
        assert(reads[n] == 2);
    assert(!settings_dirty());
    settings_edit(SET_TARGET, 1);
    settings_edit(SET_KP, 1);
    settings_edit(SET_KI, -1);
    settings_edit(SET_KD, 1);
    settings_edit(SET_MAX, -1);
    settings_edit(SET_MIN, 1);
    settings_edit(SET_MODE, 1);
    assert(settings_dirty() == 15);
    realtime_enable(1);
    commit();
    assert(realtime_enabled() && !heat && waiting && !fresh);
    assert(!settings_dirty());
    for (n = 0; n < 4; ++n)
        assert(erases[n] == 1);
    for (n = 0; n < 7; ++n)
        assert(writes[n] == 1);
    assert(eeprom[0] == 45 && eeprom[1] == 1);
    assert(eeprom[0x200] == 11 && eeprom[0x204] == 19 && eeprom[0x208] == 31);
    assert(eeprom[0x400] == 93 && eeprom[0x401] == 1 && eeprom[0x404] == 2 && eeprom[0x600] == 1);
    assert(eeprom[0x202] == 255 && eeprom[0x403] == 255 && eeprom[0x601] == 255);
    settings_load();
    assert(settings_get(SET_TARGET) == 301 && !settings_dirty());
    seed(300, 200, 200);
    assert(settings_get(SET_MIN) == 199 && settings_get(SET_TARGET) == 200);
    settings_edit(SET_MIN, 1);
    settings_edit(SET_MAX, -1);
    assert(settings_get(SET_MIN) == 199 && settings_get(SET_MAX) == 200);
    seed(350, 350, 0);
    settings_edit(SET_MAX, -1);
    assert(settings_get(SET_TARGET) == 349 && settings_dirty() == 5);
    for (n = 0; n < 1100; ++n) {
        settings_edit(SET_KP, 1);
        settings_edit(SET_TARGET, -1);
        settings_edit(SET_MIN, 1);
    }
    assert(settings_get(SET_KP) == 500 && settings_get(SET_MIN) == 200 &&
           settings_get(SET_TARGET) == 200);
    for (n = 0; n < 1100; ++n)
        settings_edit(SET_KP, -1);
    assert(settings_get(SET_KP) == 0);
    seed(100, 350, 0);
    eeprom[0x200] = 0xe8;
    eeprom[0x201] = 3;
    settings_load();
    assert(settings_get(SET_KP) == 1000);
    settings_edit(SET_KP, 1);
    assert(settings_get(SET_KP) == 1000);
    settings_edit(SET_KP, -1);
    assert(settings_get(SET_KP) == 999);
}

static void test_pid(void) {
    unsigned n, t, actual;
    uint32_t random = 17;
    int64_t expected_integral = 0, expected_previous = 0;
    pid_reset();
    assert(pid_step(100, 110, 1000, 1000, 1000) == 0);
    pid_reset();
    assert(pid_step(350, 0, 1000, 1000, 1000) == 1000);
    assert(previous == 350); // Term limits must not change raw previous error.
    assert(pid_step(350, 350, 0, 0, 1000) == 0);
    pid_reset();
    assert(pid_step(100, 95, 0, 1, 1000) == 1000);
    assert(integral == 5 && previous == 5);
    assert(pid_step(100, 95, 0, 1, 1000) == 10);
    pid_reset();
    assert(pid_step(100, 100.9f, 100, 0, 0) == 0 && previous == 0);
    for (n = 0; n < 1000; ++n)
        pid_step(100, 99, 0, 0, 0);
    assert(integral == 500);
    for (n = 0; n < 2000; ++n)
        pid_step(100, 101, 0, 0, 0);
    assert(integral == -500);
    assert(pid_step(0, 400, 1000, 1000, 1000) == 0);
    pid_reset();
    assert(integral == 0 && previous == 0);
    for (t = 0; t <= 350; t += 7)
        for (actual = 0; actual <= 400; ++actual)
            assert(pid_step(t, actual, 1000, 1000, 1000) <= 1000);
    pid_reset();
    assert(pid_step(100, 99, 0, 1000, 0) == 1000);
    assert(pid_step(100, 99, 0, 1000, 0) == 1000 && integral == 1);
    pid_reset();
    for (n = 0; n < 50000; ++n) {
        uint16_t gains[3], result;
        int64_t error, p, in, d, expected;
        unsigned g;
        random = random * 1664525u + 1013904223u;
        t = random % 351;
        random = random * 1664525u + 1013904223u;
        actual = random % 401;
        for (g = 0; g < 3; ++g) {
            random = random * 1664525u + 1013904223u;
            gains[g] = random % 1001;
        }
        error = (int64_t)t - actual;
        if (error > -10 && error < 10)
            expected_integral += error;
        if (expected_integral > 500)
            expected_integral = 500;
        if (expected_integral < -500)
            expected_integral = -500;
        p = gains[0] * error;
        in = gains[1] * expected_integral;
        d = gains[2] * (error - expected_previous);
        if (p > 1000)
            p = 1000;
        if (in > 1000) {
            expected_integral = 1000 / gains[1];
            in = gains[1] * expected_integral;
        }
        if (d > 1000)
            d = 1000;
        expected = p + in + d;
        if (expected < 0)
            expected = 0;
        if (expected > 1000)
            expected = 1000;
        result = pid_step(t, actual, gains[0], gains[1], gains[2]);
        assert(result == expected && integral == expected_integral && previous == error);
        expected_previous = error;
    }
}

static void test_buttons(void) {
    unsigned n;
    assert(buttons_take() == BUTTON_EVENT_ALL_RELEASED);
    assert(!buttons_take() && EA == 1);
    for (n = 0; n < 600; ++n)
        buttons_tick(3);
    assert(!buttons_take());
    buttons_tick(0);
    assert(buttons_take() == BUTTON_EVENT_ALL_RELEASED);
    buttons_tick(0);
    assert(!buttons_take());
    buttons_tick(1);
    buttons_tick(0);
    assert(buttons_take() == (BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_ALL_RELEASED));
    assert(!buttons_take());
    for (n = 0; n < 499; ++n)
        buttons_tick(2);
    assert(buttons_take() == 0);
    buttons_tick(2);
    assert(buttons_take() == BUTTON_STATE_RIGHT_HELD);
    assert(buttons_take() == BUTTON_STATE_RIGHT_HELD);
    for (n = 0; n < 70000; ++n)
        buttons_tick(2);
    assert(buttons_take() == BUTTON_STATE_RIGHT_HELD);
    buttons_tick(0);
    assert(buttons_take() == (BUTTON_EVENT_RIGHT_RELEASE | BUTTON_EVENT_ALL_RELEASED));
    buttons_tick(1);
    buttons_tick(3);
    buttons_tick(2);
    buttons_tick(0);
    assert(buttons_take() == (BUTTON_EVENT_BOTH_TAP | BUTTON_EVENT_ALL_RELEASED));
    for (n = 0; n < 499; ++n)
        buttons_tick(3);
    assert(!buttons_take());
    buttons_tick(3);
    assert(buttons_take() == BUTTON_EVENT_BOTH_HOLD);
    for (n = 0; n < 70000; ++n)
        buttons_tick(3);
    assert(!buttons_take());
    buttons_tick(1);
    buttons_tick(0);
    assert(buttons_take() == BUTTON_EVENT_ALL_RELEASED);
    assert(!buttons_take());

    /* A single release can coexist with the other button's held state. */
    for (n = 0; n < 500; ++n)
        buttons_tick(1);
    buttons_tick(3);
    buttons_tick(1);
    assert(buttons_take() == (BUTTON_EVENT_RIGHT_RELEASE | BUTTON_STATE_LEFT_HELD));
    assert(buttons_take() == BUTTON_STATE_LEFT_HELD);
    buttons_tick(0);
    assert(buttons_take() == (BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_ALL_RELEASED));

    /* A release followed by a new press before take is not an idle snapshot. */
    buttons_tick(1);
    buttons_tick(0);
    buttons_tick(2);
    assert(buttons_take() == BUTTON_EVENT_LEFT_RELEASE);
    for (n = 1; n < 500; ++n)
        buttons_tick(2);
    assert(buttons_take() == BUTTON_STATE_RIGHT_HELD);
    buttons_tick(0);
    assert(buttons_take() == (BUTTON_EVENT_RIGHT_RELEASE | BUTTON_EVENT_ALL_RELEASED));
    EA = 0;
    buttons_take();
    assert(EA == 0);
    EA = 1;
}

static void test_realtime(void) {
    unsigned duty, n, on;
    for (duty = 0; duty <= 1000; ++duty) {
        reset_realtime();
        realtime_enable(1);
        realtime_sample();
        realtime_publish(duty);
        ticks(999);
        assert(!heat);
        realtime_sample();
        on = 0;
        for (n = 0; n < 1000; ++n) {
            realtime_tick();
            on += heat;
        }
        assert(on == duty);
    }
    reset_realtime();
    realtime_enable(1);
    realtime_sample();
    realtime_publish(800);
    ticks(1000);
    assert(heat && realtime_duty() == 800);
    realtime_sample();
    realtime_publish(1);
    ticks(1);
    assert(heat && realtime_duty() == 800); // No torn or mid-period latch.
    ticks(999);
    assert(heat && realtime_duty() == 1);
    ticks(1);
    assert(!heat);
    reset_realtime();
    realtime_enable(1);
    realtime_sample();
    realtime_publish(1000);
    ticks(1999);
    assert(heat);
    ticks(1);
    assert(!heat && !fault && waiting);
    realtime_publish(1000);
    ticks(1000);
    assert(!heat && waiting);
    realtime_sample();
    ticks(1);
    assert(!heat && waiting);
    pid_reset();
    realtime_publish(pid_step(350, 0, 10, 20, 30));
    ticks(999);
    assert(heat && !waiting);
    realtime_pause();
    assert(!heat && enabled);
    ticks(1000);
    assert(!heat);
    realtime_sample();
    realtime_publish(1000);
    assert(paused && waiting && !fresh);
    realtime_resume();
    realtime_publish(1000);
    ticks(1);
    assert(!heat && waiting);
    realtime_sample();
    pid_reset();
    realtime_publish(1000);
    ticks(999);
    assert(heat);
    realtime_fault();
    assert(!heat && fault);
    realtime_enable(1);
    realtime_sample();
    realtime_publish(1000);
    ticks(1000);
    assert(!heat && fault);
    reset_realtime();
    ticks(1000);
    assert(realtime_take() == (REALTIME_PID | REALTIME_GRAPH) && !realtime_take());
    EA = 0;
    realtime_enable(1);
    realtime_pause();
    realtime_resume();
    realtime_sample();
    realtime_publish(65535);
    realtime_duty();
    realtime_take();
    realtime_fault();
    assert(EA == 0);
    reset_realtime();
    realtime_enable(1);
    realtime_sample();
    realtime_publish(65535);
    ticks(1000);
    assert(realtime_duty() == 1000);
    realtime_enable(0);
    assert(!heat && !realtime_duty());
    reset_realtime();
    realtime_enable(1);
    realtime_sample();
    pid_reset();
    duty = pid_step(350, 0, 10, 20, 30);
    ticks(2000); // Stale interrupt between PID calculation and publication.
    realtime_publish(duty);
    assert(waiting && !heat && !pending);
}

static void test_measurements(void) {
    uint16_t code, cutoff = 0;
    reset_realtime();
    count = index = 0;
    assert(measurements_sample());
    assert(adc_calls[0] == 30 && adc_calls[1] == 30 && adc_calls[15] == 30);
    assert(measurements_temperature() == temperature_from_adc(adc_temperature));
    assert(fabsf(measurements_voltage() - 20 * 1.19f * 2048 / 1477) < 0.001f);
    adc_temperature = 1001;
    assert(measurements_sample());
    assert(adc_calls[0] == 31 && adc_calls[1] == 31 && adc_calls[15] == 60);
    assert(fabsf(measurements_temperature() -
                 (29 * temperature_from_adc(1000) + temperature_from_adc(1001)) / 30.0f) < 0.001f);
    realtime_enable(1);
    realtime_sample();
    realtime_publish(1000);
    ticks(1000);
    assert(heat);
    stall_ticks = 2000;
    assert(measurements_sample());
    assert(stalled_low && waiting && fresh && !heat);
    pid_reset();
    realtime_publish(1000);
    ticks(1000);
    assert(heat);
    adc_reference = 0;
    assert(!measurements_sample() && fault && !heat);
    reset_realtime();
    adc_reference = 4096;
    assert(!measurements_sample() && fault);
    adc_reference = 1477;
    for (code = 0; code < 4096; ++code) {
        uint16_t temp = temperature_from_adc(code);
        if (code < 682 || code > 1355)
            assert(temp == TEMPERATURE_INVALID);
        else
            assert(temp <= 400);
        if (!cutoff && temp != TEMPERATURE_INVALID && temp >= 360)
            cutoff = code;
    }
    reset_realtime();
    adc_temperature = cutoff - 1;
    assert(measurements_sample());
    adc_temperature = cutoff;
    assert(!measurements_sample() && fault);
    reset_realtime();
    adc_temperature = 0;
    assert(!measurements_sample() && fault);
    reset_realtime();
    adc_temperature = 4095;
    assert(!measurements_sample() && fault);
    reset_realtime();
    adc_temperature = 1000;
    assert(measurements_sample());
}

static void expect_draw(unsigned n, uint8_t x, uint8_t y, uint8_t width, uint8_t height,
                        const uint8_t *bmp, uint8_t inverted) {
    assert(n < draw_count);
    assert(draw_log[n].x == x && draw_log[n].y == y && draw_log[n].width == width &&
           draw_log[n].height == height && draw_log[n].bmp == bmp &&
           draw_log[n].inverted == inverted);
}

/* Exact ordered bitmap calls from the pre-refactor layout, with labels absent.
 * The OLED suite separately verifies the pixels produced by these calls. */
static void test_menu_rendering(void) {
    unsigned active_mode, profile, item, n, next, digits, tabs, divisor;
    uint16_t value;
    uint16_t before[7];
    const uint8_t *icon;
    uint8_t editing, inverted;
    for (profile = 0; profile < 2; ++profile) {
        seed(300, 350, 0);
        values[SET_KP] = profile ? 1000 : 0;
        values[SET_KI] = profile ? 987 : 20;
        values[SET_KD] = profile ? 654 : 30;
        for (active_mode = 0; active_mode < 2; ++active_mode) {
            values[SET_MODE] = active_mode;
            memcpy(before, values, sizeof before);
            for (screen = TOP; screen <= TEMP_EDIT; ++screen) {
                editing = screen == PID_EDIT || screen == TEMP_EDIT;
                tabs = screen == TOP || screen == PID_MENU || screen == PID_EDIT ? 4 : 3;
                for (item = 0; item < tabs; ++item) {
                    selection = item;
                    draw_count = 0;
                    record_draws = 1;
                    ui_render(0);
                    record_draws = 0;
                    expect_draw(0, 109, 1, 17, 48, editing ? page1_arrrb : page1_arrrw, 0);
                    expect_draw(1, 2, 1, 17, 48, editing ? page1_arrlb : page1_arrlw, 0);
                    if (screen == TOP) {
                        expect_draw(2, 48, 0, 32, 64, page1_icon[item], 0);
                        assert(draw_count == 3);
                        continue;
                    }
                    digits = 0;
                    value = before[SET_TARGET];
                    if (screen == PID_MENU || screen == PID_EDIT) {
                        icon = PID[item];
                        inverted = !editing && item != PID_BACK;
                        if (editing) {
                            digits = 4;
                            if (item < PID_BACK)
                                value = before[SET_KP + item];
                        }
                    } else if (screen == TEMP_MENU || screen == TEMP_EDIT) {
                        icon = TEMP[item];
                        inverted = !editing && item != TEMP_BACK;
                        if (editing) {
                            digits = 3;
                            if (item < TEMP_BACK)
                                value = before[item == TEMP_MAX ? SET_MAX : SET_MIN];
                        }
                    } else {
                        icon = mode[item];
                        inverted = item != MODE_BACK && item != active_mode;
                    }
                    expect_draw(2, 22, 0, 28, 56, icon, inverted);
                    next = 3;
                    divisor = digits == 4 ? 1000 : 100;
                    for (n = 0; n < digits; ++n) {
                        expect_draw(next++, 53 + 8 * n, 4, 8, 24, SMALLNUM[value / divisor % 10],
                                    0);
                        divisor /= 10;
                    }
                    for (n = 0; n < tabs; ++n)
                        expect_draw(next++, 22 + (tabs == 4 ? 24 : 36) * n, 7, 12, 8,
                                    n == item ? tab2 : tab, 0);
                    assert(draw_count == next);
                    assert(screen >= PID_MENU && selection == item);
                    assert(!memcmp(before, values, sizeof before));
                }
            }
        }
    }
}

static void test_ui(void) {
    unsigned menu, item, n;
    static const uint8_t menus[] = {PID_MENU, TEMP_MENU, MODE_MENU};
    static const struct {
        uint8_t screen, item;
        Setting field;
    } edit_cases[] = {{PID_EDIT, PID_KP, SET_KP},
                      {PID_EDIT, PID_KI, SET_KI},
                      {PID_EDIT, PID_KD, SET_KD},
                      {TEMP_EDIT, TEMP_MAX, SET_MAX},
                      {TEMP_EDIT, TEMP_MIN, SET_MIN}};
    seed(300, 350, 1);
    for (item = PID_KP; item <= PID_BACK; ++item) {
        selection = item;
        screen = PID_MENU;
        inverted_draws = 0;
        ui_render(0);
        assert(inverted_draws == (item != PID_BACK));
        screen = PID_EDIT;
        inverted_draws = 0;
        ui_render(0);
        assert(!inverted_draws);
    }
    for (item = TEMP_MAX; item <= TEMP_BACK; ++item) {
        selection = item;
        screen = TEMP_MENU;
        draws = inverted_draws = 0;
        ui_render(0);
        assert(draws == 6 && inverted_draws == (item != TEMP_BACK));
        if (item != TEMP_BACK) {
            ui_input(BUTTON_EVENT_BOTH_TAP);
            assert(screen == TEMP_EDIT && selection == item);
            draws = inverted_draws = 0;
            ui_render(0);
            assert(draws == 9 && !inverted_draws);
            ui_input(BUTTON_EVENT_BOTH_TAP);
            assert(screen == TEMP_MENU && selection == item);
            inverted_draws = 0;
            ui_render(0);
            assert(inverted_draws == 1);
        } else {
            ui_input(BUTTON_EVENT_BOTH_TAP);
            assert(screen == TOP && selection == TOP_TEMP);
        }
    }
    for (n = MODE_NORMAL; n <= MODE_GRAPH; ++n) {
        settings_edit(SET_MODE, n == MODE_NORMAL ? -1 : 1);
        assert(settings_get(SET_MODE) == n);
        screen = MODE_MENU;
        for (item = MODE_NORMAL; item <= MODE_BACK; ++item) {
            selection = item;
            draws = inverted_draws = 0;
            ui_render(0);
            assert(draws == 6 && inverted_draws == (item != MODE_BACK && item != n));
        }
        ui_input(BUTTON_EVENT_BOTH_TAP);
        assert(screen == TOP && selection == TOP_MODE && settings_get(SET_MODE) == n);
    }
    seed(300, 350, 1);
    screen = HOME;
    ui_input(BUTTON_EVENT_BOTH_TAP);
    assert(realtime_enabled());
    ui_input(BUTTON_EVENT_BOTH_HOLD);
    assert(screen == TOP && selection == 0 && !realtime_enabled());
    ui_input(BUTTON_EVENT_RIGHT_RELEASE);
    assert(selection == 3);
    ui_input(BUTTON_EVENT_BOTH_TAP);
    assert(ui_home());
    ui_render(1); // Old icon[-1] path.
    for (menu = 0; menu < 3; ++menu) {
        ui_input(BUTTON_EVENT_BOTH_HOLD);
        for (n = 0; n < menu; ++n)
            ui_input(BUTTON_EVENT_LEFT_RELEASE);
        ui_input(BUTTON_EVENT_BOTH_TAP);
        assert(screen == menus[menu] && selection == 0);
        for (item = 0; item < (menu == 0 ? 3u : 2u); ++item) {
            ui_render(0);
            ui_input(BUTTON_EVENT_BOTH_TAP);
            ui_render(0);
            if (menu != 2) {
                ui_input(BUTTON_STATE_LEFT_HELD);
                ui_input(BUTTON_STATE_RIGHT_HELD);
                ui_render(0);
                ui_input(BUTTON_EVENT_BOTH_TAP);
                assert(selection == item);
            } else
                assert(settings_get(SET_MODE) == item);
            ui_input(BUTTON_EVENT_LEFT_RELEASE);
        }
        ui_render(0);
        ui_input(BUTTON_EVENT_LEFT_RELEASE);
        assert(selection == 0);
        ui_input(BUTTON_EVENT_RIGHT_RELEASE);
        assert(selection == (menu == 0 ? 3 : 2));
        ui_input(BUTTON_EVENT_BOTH_TAP);
        assert(screen == TOP && selection == menu);
        ui_input(BUTTON_EVENT_BOTH_HOLD);
        assert(ui_home());
        ui_render(0);
    }
    ui_input(BUTTON_EVENT_BOTH_HOLD);
    ui_input(BUTTON_EVENT_BOTH_TAP);
    ui_input(BUTTON_EVENT_LEFT_RELEASE);
    ui_input(BUTTON_EVENT_BOTH_TAP);
    assert(screen == PID_EDIT);
    ui_input(BUTTON_EVENT_BOTH_HOLD);
    assert(screen == PID_MENU && selection == 0);
    ui_input(BUTTON_EVENT_BOTH_HOLD);
    assert(screen == TOP);
    ui_input(BUTTON_EVENT_BOTH_HOLD);
    assert(ui_home());
    screen = TEMP_EDIT;
    selection = TEMP_MIN;
    ui_input(BUTTON_EVENT_BOTH_TAP);
    assert(screen == TEMP_MENU && selection == TEMP_MIN);
    ui_input(BUTTON_EVENT_BOTH_TAP);
    ui_input(BUTTON_EVENT_BOTH_HOLD | BUTTON_EVENT_BOTH_TAP);
    assert(screen == TEMP_MENU && selection == TEMP_MAX);
    ui_input(BUTTON_EVENT_BOTH_HOLD);
    assert(screen == TOP && selection == TOP_TEMP);
    ui_input(BUTTON_EVENT_BOTH_HOLD);
    assert(ui_home());
    for (n = 0; n < sizeof edit_cases / sizeof edit_cases[0]; ++n) {
        uint16_t before[7];
        seed(300, 350, 1);
        memcpy(before, values, sizeof before);
        screen = edit_cases[n].screen;
        selection = edit_cases[n].item;
        assert(selected_setting() == edit_cases[n].field);
        ui_input(BUTTON_EVENT_RIGHT_RELEASE);
        for (item = 0; item < 7; ++item)
            assert(values[item] == before[item] - (item == (unsigned)edit_cases[n].field));
        ui_input(BUTTON_STATE_LEFT_HELD);
        assert(!memcmp(before, values, sizeof before));
        ui_input(BUTTON_EVENT_BOTH_TAP);
        assert(screen == (edit_cases[n].screen == PID_EDIT ? PID_MENU : TEMP_MENU) &&
               selection == edit_cases[n].item);
        ui_input(BUTTON_EVENT_BOTH_TAP);
        assert(screen == edit_cases[n].screen && selection == edit_cases[n].item);
        ui_input(BUTTON_EVENT_BOTH_HOLD | BUTTON_EVENT_BOTH_TAP);
        assert(screen == (edit_cases[n].screen == PID_EDIT ? PID_MENU : TEMP_MENU) &&
               selection == 0);
        ui_input(BUTTON_EVENT_BOTH_HOLD | BUTTON_EVENT_BOTH_TAP);
        assert(screen == TOP &&
               selection == (edit_cases[n].screen == PID_EDIT ? TOP_PID : TOP_TEMP));
    }
    /* Invalid table indices are checked without rendering invalid asset indices. */
    for (menu = 0; menu < 3; ++menu) {
        for (item = (menu == 0   ? TOP_BACK
                     : menu == 1 ? PID_BACK
                                 : TEMP_BACK) +
                    1;
             item <= UINT8_MAX; ++item) {
            screen = menu == 0 ? TOP : menus[menu - 1];
            selection = item;
            ui_input(BUTTON_EVENT_BOTH_TAP);
            assert(screen == (menu == 0 ? TOP : menus[menu - 1]) && selection == item);
        }
    }
    for (menu = 0; menu <= TEMP_EDIT; ++menu) {
        screen = menu;
        for (item = 0; item <= UINT8_MAX; ++item) {
            selection = item;
            if ((screen == PID_EDIT && item < PID_BACK) ||
                (screen == TEMP_EDIT && item < TEMP_BACK))
                continue;
            assert(selected_setting() == SET_TARGET);
        }
    }
    for (n = 0; n < 2; ++n) {
        screen = TOP;
        selection = TOP_BACK;
        realtime_enable(1);
        ui_input(n ? BUTTON_EVENT_BOTH_HOLD | BUTTON_EVENT_BOTH_TAP : BUTTON_EVENT_BOTH_TAP);
        assert(ui_home() && !realtime_enabled() && !heat);
    }
    screen = HOME;
    seed(250, 350, 100);
    settings_edit(SET_MODE, 1);
    temperature = 300;
    ui_render(1);
    assert(history[100] == 48);
    temperature = 100;
    ui_render(0);
    assert(history[100] == 48);
    ui_render(1);
    assert(history[100] == 0);
    temperature = 359;
    ui_render(1);
    assert(history[100] == 60);
    values[SET_MAX] = values[SET_MIN];
    ui_render(1);
    assert(history[100] == 0);
    values[SET_MODE] = 0;
    voltage = 1e6f;
    ui_render(0);
    ui_fault();
    assert(displays > 20 && draws > 100);
    seed(300, 350, 1);
    for (n = 0; n < 5000; ++n) {
        static const uint8_t gestures[] = {BUTTON_EVENT_LEFT_RELEASE, BUTTON_EVENT_RIGHT_RELEASE,
                                           BUTTON_EVENT_BOTH_TAP,     BUTTON_EVENT_BOTH_HOLD,
                                           BUTTON_STATE_LEFT_HELD,    BUTTON_STATE_RIGHT_HELD};
        ui_input(gestures[(n * 17u + n / 7) % 6]);
        ui_render(n % 10 == 0);
        assert(settings_get(SET_MIN) < settings_get(SET_MAX));
        assert(settings_get(SET_TARGET) >= settings_get(SET_MIN));
        assert(settings_get(SET_TARGET) <= settings_get(SET_MAX));
    }
}

static void test_release_persistence(void) {
    uint8_t keys;
    unsigned n, target_erases;
    reset_realtime();
    seed(300, 350, 1);
    screen = HOME;
    pending_button_events = BUTTON_EVENT_ALL_RELEASED;
    held_states = single_release_pending = 0;
    single_hold_ticks[0] = single_hold_ticks[1] = both_hold_ticks = 0;
    both_gesture = was_pressed = 0;
    gesture_blocked = 1;
    adc_temperature = 1000;

    /* Startup release commits a load-time target clamp exactly once. */
    seed(351, 350, 1);
    target_erases = erases[0];
    keys = run_home();
    assert(keys == BUTTON_EVENT_ALL_RELEASED && settings_dirty());
    run_persistence(keys);
    assert(!settings_dirty() && erases[0] == target_erases + 1);
    buttons_tick(0);
    keys = run_home();
    assert(!keys);
    run_persistence(keys);
    assert(erases[0] == target_erases + 1);
    seed(300, 350, 1);

    buttons_tick(1);
    buttons_tick(0);
    keys = run_home();
    assert(keys == (BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_ALL_RELEASED));
    assert(rendered_target == 300 && settings_get(SET_TARGET) == 301 && settings_dirty());
    assert(!buttons_take());
    run_persistence(keys);
    assert(!settings_dirty() && eeprom[0] == 45 && eeprom[1] == 1);

    /* Accumulated target release plus long entry must save on the new page. */
    buttons_tick(1);
    buttons_tick(0);
    for (n = 0; n < 500; ++n)
        buttons_tick(3);
    keys = run_home();
    assert(keys == (BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_BOTH_HOLD));
    assert(screen == TOP && rendered_screen == HOME && settings_dirty());
    run_persistence(keys);
    assert(settings_dirty());
    buttons_tick(0);
    keys = run_settings();
    assert(keys == BUTTON_EVENT_ALL_RELEASED && rendered_screen == TOP);
    run_persistence(keys);
    assert(!settings_dirty() && settings_get(SET_TARGET) == 302);

    /* Settings input precedes rendering; a release-created edit is committed. */
    screen = PID_EDIT;
    selection = PID_KI;
    buttons_tick(2);
    buttons_tick(0);
    keys = run_settings();
    assert(settings_get(SET_KI) == 19 && settings_dirty());
    assert(!buttons_take());
    run_persistence(keys);
    assert(!settings_dirty() && eeprom[0x204] == 19);

    /* Partial release while another button is held must not commit. */
    for (n = 0; n < 500; ++n)
        buttons_tick(1);
    buttons_tick(3);
    buttons_tick(1);
    keys = run_settings();
    assert(keys == (BUTTON_EVENT_RIGHT_RELEASE | BUTTON_STATE_LEFT_HELD));
    run_persistence(keys);
    assert(settings_dirty());
    buttons_tick(0);
    keys = run_settings();
    run_persistence(keys);
    assert(!settings_dirty() && settings_get(SET_KI) == 20);

    /* A settings-to-home transition forwards its release, not a second take. */
    settings_edit(SET_MODE, 1);
    screen = TOP;
    selection = TOP_BACK;
    buttons_tick(3);
    buttons_tick(0);
    keys = run_settings();
    assert(keys == (BUTTON_EVENT_BOTH_TAP | BUTTON_EVENT_ALL_RELEASED));
    assert(ui_home() && rendered_screen == HOME && !realtime_enabled());
    run_persistence(keys);
    assert(!settings_dirty() && eeprom[0x600] == 1 && !buttons_take());

    /* Entry and its final release can also coalesce into the same snapshot. */
    buttons_tick(1);
    buttons_tick(0);
    for (n = 0; n < 500; ++n)
        buttons_tick(3);
    buttons_tick(0);
    keys = run_home();
    assert(keys ==
           (BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_BOTH_HOLD | BUTTON_EVENT_ALL_RELEASED));
    assert(screen == TOP && rendered_screen == HOME && settings_dirty());
    run_persistence(keys);
    assert(!settings_dirty() && settings_get(SET_TARGET) == 303);

    /* Invalid samples leave both snapshots untouched and cannot trigger a save. */
    screen = HOME;
    settings_edit(SET_TARGET, 1);
    pending_button_events = BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_ALL_RELEASED;
    events = REALTIME_PID | REALTIME_GRAPH;
    adc_temperature = 0;
    n = displays;
    keys = run_home();
    run_persistence(keys);
    assert(!keys && fault && !heat && displays == n && settings_dirty());
    assert(pending_button_events == (BUTTON_EVENT_LEFT_RELEASE | BUTTON_EVENT_ALL_RELEASED));
    assert(events == (REALTIME_PID | REALTIME_GRAPH));
    adc_temperature = 1000;
}

static void test_pipeline(void) {
    reset_realtime();
    seed(300, 350, 1);
    pid_reset();
    screen = HOME;
    count = index = 0;
    pending_button_events = held_states = was_pressed = single_release_pending = 0;
    both_gesture = gesture_blocked = 0;
    adc_temperature = 1000;
    adc_reference = 1477;
    stalled_low = 0;
    startup_step = extended = 0;
    integration = 1;
    heat = 1; // Startup must clear the latch before configuring push-pull.
    if (!setjmp(pipeline_done))
        firmware_main();
    assert(integration == 5 && !verify_resume);
    integration = 0;
}

int main(void) {
    test_settings();
    test_pid();
    test_buttons();
    test_realtime();
    test_measurements();
    test_menu_rendering();
    test_ui();
    test_release_persistence();
    test_pipeline();
    puts("Application tests passed: settings, PID, buttons, realtime, measurements, UI");
    return 0;
}
