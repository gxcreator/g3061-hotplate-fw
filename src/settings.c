#include "settings.h"
#include "EEPROM.h"

typedef struct {
    uint16_t address;
    uint16_t min;
    uint16_t max;
    uint16_t default_value;
} SettingDescriptor;

/* Entries follow the Setting enum order. */
static const __code SettingDescriptor descriptors[SET_COUNT] = {
    {0x0000, 0, 350, 190},   /* Target */
    {0x0200, 0, 1000, 112},  /* Kp */
    {0x0204, 0, 1000, 4},    /* Ki */
    {0x0208, 0, 1000, 160},  /* Kd */
    {0x0400, 200, 350, 350}, /* Maximum temperature */
    {0x0404, 0, 200, 0},     /* Minimum temperature */
    {0x0600, 0, 1, 0},       /* Display mode */
};

static uint16_t values[SET_COUNT];
static uint8_t dirty;
static const __code uint8_t groups[SET_COUNT] = {1, 2, 2, 2, 4, 4, 8};

static void clamp_target(void) {
    uint16_t old = values[SET_TARGET];
    if (old < values[SET_MIN])
        values[SET_TARGET] = values[SET_MIN];
    if (old > values[SET_MAX])
        values[SET_TARGET] = values[SET_MAX];
    if (old != values[SET_TARGET])
        dirty |= 1;
}

void settings_load(void) {
    uint8_t n, bytes[2];
    dirty = 0;
    for (n = 0; n < SET_COUNT; ++n) {
        EEPROM_read_n(descriptors[n].address, bytes, 2);
        values[n] = (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
        if (values[n] < descriptors[n].min || values[n] > descriptors[n].max) {
            values[n] = descriptors[n].default_value;
            dirty |= groups[n];
        }
    }
    /* Cross-setting limits are checked only after all settings are loaded. */
    if (values[SET_MIN] >= values[SET_MAX]) {
        values[SET_MIN] = descriptors[SET_MIN].default_value;
        dirty |= groups[SET_MIN];
    }
    if (values[SET_TARGET] > values[SET_MAX]) {
        values[SET_TARGET] = descriptors[SET_TARGET].default_value;
        dirty |= groups[SET_TARGET];
    }
    clamp_target();
}

uint16_t settings_get(Setting field) {
    return values[field];
}

void settings_edit(Setting field, int8_t direction) {
    uint16_t low = descriptors[field].min, high = descriptors[field].max, old = values[field];
    if (field == SET_TARGET) {
        low = values[SET_MIN];
        high = values[SET_MAX];
    } else if (field == SET_MAX) {
        if (low <= values[SET_MIN])
            low = values[SET_MIN] + 1;
    } else if (field == SET_MIN) {
        if (high >= values[SET_MAX])
            high = values[SET_MAX] - 1;
    }
    if (direction > 0 && old < high)
        ++values[field];
    if (direction < 0 && old > low)
        --values[field];
    if (old != values[field])
        dirty |= groups[field];
    clamp_target();
}

uint8_t settings_dirty(void) {
    return dirty;
}

void settings_commit(void) {
    uint8_t n, bytes[2];
    for (n = 0; n < SET_COUNT; ++n) {
        if (!(dirty & groups[n]))
            continue;
        if (n == SET_TARGET || n == SET_KP || n == SET_MAX || n == SET_MODE)
            EEPROM_SectorErase(descriptors[n].address);
        bytes[0] = (uint8_t)values[n];
        bytes[1] = (uint8_t)(values[n] >> 8);
        EEPROM_write_n(descriptors[n].address, bytes, 2);
    }
    dirty = 0;
}
