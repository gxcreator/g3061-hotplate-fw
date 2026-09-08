#include "board.h"
#include "fw_exti.h"
#include "timer0.h"
#include "ADC.h"
#include "oled.h"
#include "settings.h"
#include "measurements.h"
#include "pid.h"
#include "buttons.h"
#include "realtime.h"
#include "ui.h"

INTERRUPT(timer0, EXTI_VectTimer0) {
    realtime_tick();
    buttons_tick((!key0 ? 1 : 0) | (!key1 ? 2 : 0));
}

static void update_controller(uint8_t events) {
    int16_t error;
    if (realtime_enabled() && ((events & REALTIME_PID) || realtime_needs_reset())) {
        if (realtime_needs_reset())
            pid_reset();
        error = (int16_t)settings_get(SET_TARGET) - (int16_t)measurements_temperature();
        realtime_publish(
            pid_step(error, settings_get(SET_KP), settings_get(SET_KI), settings_get(SET_KD)));
    }
}

static uint8_t run_home(void) {
    uint8_t events, keys;
    if (!measurements_sample())
        return 0;
    events = realtime_take();
    update_controller(events);
    ui_render(events & REALTIME_GRAPH);
    keys = buttons_take();
    ui_input(keys);
    return keys;
}

static uint8_t run_settings(void) {
    uint8_t events = realtime_take(), keys = buttons_take();
    ui_input(keys);
    ui_render(events & REALTIME_GRAPH);
    return keys;
}

static void run_fault(void) {
    ui_fault();
    while (1) {
    } // Faults require a power cycle, not another button gesture.
}

static void run_persistence(uint8_t keys) {
    /* Input must create dirty state before this one-shot release is handled. */
    if ((keys & BUTTON_EVENT_ALL_RELEASED) && settings_dirty()) {
        realtime_pause();
        settings_commit();
        pid_reset();
        realtime_resume();
        // The next home iteration measures and computes before publication.
    }
}

void main(void) {
    uint8_t bgv_high, bgv_low, keys;
    /* Set the off latch before enabling the heater's push-pull driver. */
    heat = 0;
    EXTI_Global_SetIntState(HAL_State_OFF);
    /* bgv_crtclear retains these bytes; copy before any calls use the stack. */
    bgv_high = *((const volatile __idata uint8_t *)0xEF);
    bgv_low = *((const volatile __idata uint8_t *)0xF0);
    GPIO_P3_SetMode(HEATER_PIN, GPIO_Mode_Output_PP);
    SFRX_ON(); // Extended-register access stays enabled globally.
    measurements_init(((uint16_t)bgv_high << 8) | bgv_low);
    settings_load();
    GPIO_P1_SetMode(SUPPLY_ADC_PIN | TEMPERATURE_ADC_PIN, GPIO_Mode_Input_HIP);
    key0 = key1 = 1;
    GPIO_P3_SetMode(BUTTON_PINS, GPIO_Mode_InOut_OD);
    adc_init();
    OLED_Init();
    Timer0Init();
    EXTI_Global_SetIntState(HAL_State_ON);
    measurements_sample();
    while (1) {
        if (realtime_faulted())
            run_fault();
        keys = ui_home() ? run_home() : run_settings();
        run_persistence(keys);
    }
}
