/* Production framebuffer drawing with hardware calls forbidden.
 * Host tests do not validate SDCC code-memory pointers or physical pixels. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef NDEBUG
#error These tests require assertions
#endif

#define BOARD_H
#define __BIT _Bool
#define __code
static uint8_t reset_pin;
#define OLED_RES reset_pin
#define OLED_RES_PIN 8
#define GPIO_Mode_Output_PP 1
#define GPIO_P2_SetMode(pins, mode) assert(0)

/* Unrelated legacy line drawing has no-effect for-loop initializers. */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"
#include "../src/oled.c"
#pragma GCC diagnostic pop
#include "../src/bmp.h"

void i2c_init(void) {
    assert(0);
}
void i2c_start(void) {
    assert(0);
}
void i2c_stop(void) {
    assert(0);
}
void i2c_write_byte(uint8_t dat) {
    (void)dat;
    assert(0);
}
void i2c_clock_ack(void) {
    assert(0);
}

static void check_bitmap(uint8_t x, uint8_t page, uint8_t w, uint8_t h, const uint8_t *bmp) {
    unsigned inverted, offset, bit;
    uint8_t expected;
    for (inverted = 0; inverted < 2; ++inverted) {
        memset(_buf, 0xa5, sizeof _buf);
        if (inverted)
            OLED_DrawBMP_2_Inverted(x, page, w, h, bmp);
        else
            OLED_DrawBMP_2(x, page, w, h, bmp);
        for (offset = 0; offset < sizeof _buf; ++offset) {
            unsigned column = offset % 128, row = offset / 128;
            expected = 0xa5;
            if (column >= x && column < x + w && row >= page && row < page + h / 8) {
                expected = bmp[(row - page) * w + column - x];
                /* Independent per-pixel oracle, including the rectangle's corners. */
                if (inverted)
                    for (bit = 0; bit < 8; ++bit)
                        expected ^= (uint8_t)(1u << bit);
            }
            assert(_buf[offset] == expected);
        }
    }
}

static void test_macro_arguments(void) {
    const uint8_t bytes[] = {0x36, 0x81};
    unsigned inverted, offset;
    for (inverted = 0; inverted < 2; ++inverted) {
        uint8_t x = 17, page = 2, w = 1, h = 8;
        const uint8_t *bmp = bytes;
        memset(_buf, 0xa5, sizeof _buf);
        if (inverted)
            OLED_DrawBMP_2_Inverted(x++, page++, w++, h++, bmp++);
        else
            OLED_DrawBMP_2(x++, page++, w++, h++, bmp++);
        assert(x == 18 && page == 3 && w == 2 && h == 9 && bmp == bytes + 1);
        for (offset = 0; offset < sizeof _buf; ++offset)
            assert(_buf[offset] == (offset == 2 * 128 + 17 ? (inverted ? 0xc9 : 0x36) : 0xa5));
    }
}

int main(void) {
    uint8_t bytes[256];
    unsigned n;
    for (n = 0; n < sizeof bytes; ++n)
        bytes[n] = n;
    check_bitmap(17, 2, 64, 32, bytes); // All byte values, nonzero origin, four pages.
    check_bitmap(0, 0, 128, 16, bytes);
    check_bitmap(64, 4, 64, 32, bytes); // Right and bottom display edges.
    check_bitmap(5, 3, 0, 16, bytes);
    check_bitmap(5, 3, 16, 0, bytes);
    check_bitmap(5, 3, 16, 15, bytes); // Preserve whole-page truncation.
    for (n = 0; n < sizeof PID / sizeof PID[0]; ++n)
        check_bitmap(22, 0, 28, 56, PID[n]);
    assert(sizeof TEMP == 3 * 28 * 7 && sizeof mode == 3 * 28 * 7);
    for (n = 0; n < 3; ++n) {
        check_bitmap(22, 0, 28, 56, TEMP[n]);
        check_bitmap(100, 1, 28, 56, TEMP[n]); // Icon touches right and bottom edges.
        check_bitmap(22, 0, 28, 56, mode[n]);
        check_bitmap(100, 1, 28, 56, mode[n]);
    }
    test_macro_arguments();
    puts("OLED bitmap tests passed");
    return 0;
}
