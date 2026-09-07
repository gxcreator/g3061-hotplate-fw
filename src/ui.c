#include "oled.h"
#include "bmp.h"
#include "ui.h"
#include "settings.h"
#include "measurements.h"
#include "buttons.h"
#include "realtime.h"

enum { HOME, TOP, PID_MENU, TEMP_MENU, MODE_MENU, PID_EDIT, TEMP_EDIT };
enum { TOP_PID, TOP_TEMP, TOP_MODE, TOP_BACK };
enum { PID_KP, PID_KI, PID_KD, PID_BACK };
enum { TEMP_MAX, TEMP_MIN, TEMP_BACK };
enum { MODE_NORMAL, MODE_GRAPH, MODE_BACK };
typedef struct {
    uint8_t screen, selection;
} MenuDestination;
static const __code MenuDestination top_destinations[] = {
    {PID_MENU, PID_KP}, {TEMP_MENU, TEMP_MAX}, {MODE_MENU, MODE_NORMAL}};
static const __code uint8_t pid_fields[] = {SET_KP, SET_KI, SET_KD};
static const __code uint8_t temp_fields[] = {SET_MAX, SET_MIN};
typedef struct {
    uint8_t last_item, editor_screen;
} EditMenu;
static const __code EditMenu pid_menu = {PID_BACK, PID_EDIT};
static const __code EditMenu temp_menu = {TEMP_BACK, TEMP_EDIT};
static const __code char top_labels[][8] = {"PID", "Temp", "Display", "Back"};
static const __code char pid_labels[][7] = {"P gain", "I gain", "D gain", "Back"};
static const __code char temp_labels[][9] = {"Max temp", "Min temp", "Back"};
static const __code char mode_labels[][7] = {"Normal", "Graph", "Back"};
static uint8_t screen;
static uint8_t selection;
/* Native normalized 0..30 coordinates save 101 bytes versus uint16_t temperatures.
 * Clear history when limits change, so old and new scales never mix. */
static uint8_t history[101];
static uint16_t graph_min, graph_max;
#define DUTY_Q6_SCALE 64u
static uint16_t shown_duty; /* Q6 percent, 0..6400. */
static __BIT graph_due = 1;

uint8_t ui_home(void) {
    return screen == HOME;
}

static void back(void) {
    switch (screen) {
    case TOP:
        screen = HOME;
        realtime_enable(0);
        break;
    case PID_EDIT:
        screen = PID_MENU;
        selection = PID_KP;
        break;
    case TEMP_EDIT:
        screen = TEMP_MENU;
        selection = TEMP_MAX;
        break;
    case PID_MENU:
        selection = TOP_PID;
        screen = TOP;
        break;
    case TEMP_MENU:
        selection = TOP_TEMP;
        screen = TOP;
        break;
    case MODE_MENU:
        selection = TOP_MODE;
        screen = TOP;
        break;
    }
}

static Setting selected_setting(void) {
    switch (screen) {
    case PID_EDIT:
        if (selection < sizeof pid_fields)
            return pid_fields[selection];
        break;
    case TEMP_EDIT:
        if (selection < sizeof temp_fields)
            return temp_fields[selection];
        break;
    }
    return SET_TARGET;
}

static void edit_value(Setting field, uint8_t events) {
    if (events & (BUTTON_EVENT_LEFT_RELEASE | BUTTON_STATE_LEFT_HELD))
        settings_edit(field, 1);
    if (events & (BUTTON_EVENT_RIGHT_RELEASE | BUTTON_STATE_RIGHT_HELD))
        settings_edit(field, -1);
}

static void navigate(uint8_t events, uint8_t last_item) {
    if (events & BUTTON_EVENT_LEFT_RELEASE)
        selection = selection == last_item ? 0 : selection + 1;
    if (events & BUTTON_EVENT_RIGHT_RELEASE)
        selection = selection ? selection - 1 : last_item;
}

static void input_home(uint8_t events) {
    edit_value(SET_TARGET, events);
    if (events & BUTTON_EVENT_BOTH_HOLD) {
        screen = TOP;
        selection = TOP_PID;
        realtime_enable(0);
    } else if (events & BUTTON_EVENT_BOTH_TAP)
        realtime_enable(!realtime_enabled());
}

static void input_top(uint8_t events) {
    uint8_t item;
    navigate(events, TOP_BACK);
    if (events & BUTTON_EVENT_BOTH_HOLD)
        back();
    else if (events & BUTTON_EVENT_BOTH_TAP) {
        item = selection;
        if (item == TOP_BACK)
            back();
        else if (item < sizeof top_destinations / sizeof top_destinations[0]) {
            screen = top_destinations[item].screen;
            selection = top_destinations[item].selection;
        }
    }
}

static void input_edit_menu(uint8_t events, const __code EditMenu *menu) {
    navigate(events, menu->last_item);
    if (events & BUTTON_EVENT_BOTH_HOLD)
        back();
    else if (events & BUTTON_EVENT_BOTH_TAP) {
        if (selection == menu->last_item)
            back();
        else if (selection < menu->last_item)
            screen = menu->editor_screen;
    }
}

static void input_mode_menu(uint8_t events) {
    navigate(events, MODE_BACK);
    if (events & BUTTON_EVENT_BOTH_HOLD)
        back();
    else if (events & BUTTON_EVENT_BOTH_TAP) {
        switch (selection) {
        case MODE_NORMAL:
            settings_edit(SET_MODE, -1);
            break;
        case MODE_GRAPH:
            settings_edit(SET_MODE, 1);
            break;
        case MODE_BACK:
            back();
            break;
        }
    }
}

static void input_edit(uint8_t events) {
    edit_value(selected_setting(), events);
    if (events & BUTTON_EVENT_BOTH_HOLD)
        back();
    else if (events & BUTTON_EVENT_BOTH_TAP) {
        switch (screen) {
        case PID_EDIT:
            screen = PID_MENU;
            break;
        case TEMP_EDIT:
            screen = TEMP_MENU;
            break;
        }
    }
}

void ui_input(uint8_t events) {
    switch (screen) {
    case HOME:
        input_home(events);
        break;
    case TOP:
        input_top(events);
        break;
    case PID_MENU:
        input_edit_menu(events, &pid_menu);
        break;
    case TEMP_MENU:
        input_edit_menu(events, &temp_menu);
        break;
    case MODE_MENU:
        input_mode_menu(events);
        break;
    case PID_EDIT:
    case TEMP_EDIT:
        input_edit(events);
        break;
    }
}

static uint8_t normalized(uint16_t value, uint8_t scale) {
    uint16_t low = settings_get(SET_MIN), high = settings_get(SET_MAX);
    if (high <= low || value <= low)
        return 0;
    if (value >= high)
        return scale;
    return ((uint32_t)(value - low) * scale) / (high - low);
}

static void render_home(void) {
    uint16_t actual = measurements_temperature(), target = settings_get(SET_TARGET);
    Draw_realnum(0, 0, actual);
    Draw_tarnum(48, 12, target, 1);
    Draw_voltage(48, 0, measurements_voltage_centivolts());
    Draw_Loading(8, 24, 0, normalized(actual, 100));
    /* Retain integer input percent; numerator <=32002 fits unsigned 16 bits. */
    shown_duty = (4u * shown_duty + DUTY_Q6_SCALE * (realtime_duty() / 10u) + 2u) / 5u;
    Draw_Loading(65, 24, 1,
                 shown_duty >= 99u * DUTY_Q6_SCALE ? 100 : shown_duty / DUTY_Q6_SCALE + 1);
    Draw_Sign(11, 24, normalized(target, 100), target, actual);
    OLED_DrawBMP_2(
        84, 0, 42, 24,
        state[!realtime_enabled() ? 2 : ((int16_t)target - (int16_t)actual > 5 ? 1 : 0)]);
}

static void render_graph(void) {
    uint8_t n;
    uint16_t actual = measurements_temperature(), target = settings_get(SET_TARGET);
    Draw_tarnum(0, 0, actual, 0);
    Draw_tarnum(0, 12, target, 0);
    OLED_DrawBMP_2(4, 24, 16, 8, realtime_enabled() ? switch_ope : switch_clo);
    OLED_DrawBMP_2(25, 0, 103, 32, xy);
    for (n = 26; n < 128; ++n)
        if ((n + 1) % 4 == 0)
            OLED_DrawPixel(n, 30 - normalized(target, 30), 1);
    if (graph_min != settings_get(SET_MIN) || graph_max != settings_get(SET_MAX)) {
        for (n = 0; n < 101; ++n)
            history[n] = 0;
        graph_min = settings_get(SET_MIN);
        graph_max = settings_get(SET_MAX);
    }
    if (graph_due) {
        for (n = 0; n < 100; ++n)
            history[n] = history[n + 1];
        history[100] = normalized(actual, 30);
        graph_due = 0;
    }
    for (n = 0; n < 101; ++n)
        OLED_DrawPixel(27 + n, 30 - history[n], 1);
}

static void render_settings(void) {
    uint8_t n, count, editing = screen == PID_EDIT || screen == TEMP_EDIT;
    const __code uint8_t *icon;
    const __code char *label;
    uint8_t inverted, digits = 0;
    OLED_DrawBMP_2(109, 4, 17, 24, editing ? page1_arrrb : page1_arrrw);
    OLED_DrawBMP_2(2, 4, 17, 24, editing ? page1_arrlb : page1_arrlw);
    switch (screen) {
    case TOP:
        OLED_DrawBMP_2(22, 0, 32, 32, page1_icon[selection]);
        OLED_DrawStringSmall(58, 8, top_labels[selection]);
        return;
    case PID_MENU:
    case PID_EDIT:
        icon = PID[selection];
        label = pid_labels[selection];
        inverted = !editing && selection != PID_BACK;
        digits = 4;
        count = PID_BACK + 1;
        break;
    case TEMP_MENU:
    case TEMP_EDIT:
        icon = TEMP[selection];
        label = temp_labels[selection];
        inverted = !editing && selection != TEMP_BACK;
        digits = 3;
        count = TEMP_BACK + 1;
        break;
    case MODE_MENU:
        icon = mode[selection];
        label = mode_labels[selection];
        inverted = selection != MODE_BACK && selection != settings_get(SET_MODE);
        count = MODE_BACK + 1;
        break;
    default:
        return;
    }
    OLED_DrawBitmap(22, 0, 28, 28, icon, inverted);
    OLED_DrawStringSmall(58, 8, label);
    if (editing)
        Draw_midnum(53, 16, settings_get(selected_setting()), digits);
    for (n = 0; n < count; ++n)
        OLED_DrawBMP_2(72 / (count - 1) * n + 22, 28, 12, 4, n == selection ? tab2 : tab);
}

void ui_render(uint8_t graph_tick) {
    if (graph_tick)
        graph_due = 1;
    OLED_display_clear();
    if (screen == HOME) {
        if (settings_get(SET_MODE) == MODE_NORMAL)
            render_home();
        else
            render_graph();
    } else {
        render_settings();
    }
    OLED_display();
}

void ui_fault(void) {
    OLED_display_clear();
    OLED_DrawStringSmall((OLED_WIDTH - 6 * (sizeof "SENSOR FAULT" - 1)) / 2, (OLED_HEIGHT - 8) / 2,
                         "SENSOR FAULT");
    OLED_display();
}
