#include "settings.h"
#include "EEPROM.h"

static uint16_t values[7];
static uint8_t dirty;
static const uint16_t addresses[] = {0x0000, 0x0200, 0x0204, 0x0208, 0x0400, 0x0404, 0x0600};
static const uint8_t groups[] = {1, 2, 2, 2, 4, 4, 8};

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
    for (n = 0; n < 7; ++n) {
        bytes[1] = 0;
        EEPROM_read_n(addresses[n], bytes, n == SET_MODE ? 1 : 2);
        values[n] = (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
    }
    if (values[SET_MAX] > 350)
        values[SET_MAX] = 350;
    if (values[SET_MAX] < 200)
        values[SET_MAX] = 200;
    if (values[SET_MIN] > 200)
        values[SET_MIN] = 0;
    if (values[SET_MIN] >= values[SET_MAX])
        values[SET_MIN] = values[SET_MAX] - 1;
    for (n = SET_KP; n <= SET_KD; ++n) {
        if (values[n] > 1000)
            values[n] = 500;
    }
    if (values[SET_MODE] > 1)
        values[SET_MODE] = 0;
    clamp_target();
}

uint16_t settings_get(Setting field) {
    return values[field];
}

void settings_edit(Setting field, int8_t direction) {
    uint16_t low = 0, high = 500, old = values[field];
    if (field == SET_TARGET) {
        low = values[SET_MIN];
        high = values[SET_MAX];
    } else if (field == SET_MAX) {
        low = 200;
        high = 350;
        if (low <= values[SET_MIN])
            low = values[SET_MIN] + 1;
    } else if (field == SET_MIN) {
        high = 200;
        if (high >= values[SET_MAX])
            high = values[SET_MAX] - 1;
    } else if (field == SET_MODE)
        high = 1;
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
    for (n = 0; n < 7; ++n) {
        if (!(dirty & groups[n]))
            continue;
        if (n == SET_TARGET || n == SET_KP || n == SET_MAX || n == SET_MODE)
            EEPROM_SectorErase(addresses[n]);
        bytes[0] = (uint8_t)values[n];
        bytes[1] = (uint8_t)(values[n] >> 8);
        EEPROM_write_n(addresses[n], bytes, n == SET_MODE ? 1 : 2);
    }
    dirty = 0;
}
