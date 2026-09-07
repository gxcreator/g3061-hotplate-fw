#include "oled.h"
#include "fw_sys.h"
#include "i2c.h"
#include "oledfont.h"
#include <stdlib.h>
#include <string.h>

static __xdata uint8_t oled_buffer[OLED_WIDTH * OLED_PAGES];

#ifdef OLED_ENABLE_LEGACY_API
/* State used only by the optional legacy buffered text/byte helpers. */
static __BIT _OLED_Reverse = 0;
static __BIT _OLED_Overlap = 1;

static uint8_t __x, __y;
#endif

void delay_ms(uint16_t ms) {
    /* SYS_Delay uses a do/while loop, so do not pass zero. */
    if (ms) {
        SYS_Delay(ms);
    }
}

/* Co=0: all payload bytes until STOP share the command/data selection. */
static void oled_begin(uint8_t control) {
    i2c_start();
    i2c_write_byte(0x78);
    i2c_clock_ack();
    i2c_write_byte(control);
    i2c_clock_ack();
}

static void oled_command(uint8_t command) {
    oled_begin(0x00);
    i2c_write_byte(command);
    i2c_clock_ack();
    i2c_stop();
}

// Display inversion
void OLED_ColorTurn(uint8_t i) {
    if (i == 0) {
        oled_command(0xA6); // Normal display
    }
    if (i == 1) {
        oled_command(0xA7); // Inverse display
    }
}

// Rotate display 180 degrees
void OLED_DisplayTurn(uint8_t i) {
    if (i == 0) {
        oled_command(0xC8); // Normal display
        oled_command(0xA1);
    }
    if (i == 1) {
        oled_command(0xC0); // Rotated display
        oled_command(0xA0);
    }
}

// Enable OLED display
void OLED_Display_On(void) {
    oled_command(0X8D); // SET DCDC command
    oled_command(0X14); // DCDC ON
    oled_command(0XAF); // DISPLAY ON
}
#ifdef OLED_ENABLE_LEGACY_API
// Disable OLED display
void OLED_Display_Off(void) {
    oled_command(0X8D); // SET DCDC command
    oled_command(0X10); // DCDC OFF
    oled_command(0XAE); // DISPLAY OFF
}
#endif

// Buffered character output in native pixel coordinates.
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t sizey) {
    uint8_t c = chr - ' ';
    if (sizey == 8) {
        if (c >= sizeof asc2_0806 / sizeof asc2_0806[0])
            c = 0;
        OLED_DrawBMP_2(x, y, 6, 8, asc2_0806[c]);
#if defined(OLED_ENABLE_FONT_8X16) || defined(OLED_ENABLE_LEGACY_API)
    } else if (sizey == 16) {
        if (c >= sizeof asc2_1608 / sizeof asc2_1608[0])
            c = 0;
        OLED_DrawBMP_2(x, y, 8, 16, asc2_1608[c]);
#endif
    }
}
#ifdef OLED_ENABLE_LEGACY_API
// Compute m^n
uint16_t oled_pow(uint8_t m, uint8_t n) {
    uint16_t result = 1;
    while (n--)
        result *= m;
    return result;
}
// Display a number
// x,y: starting coordinates
// num: number to display
// len: number of digits
// sizey: font size
void OLED_ShowNum(uint8_t x, uint8_t y, uint16_t num, uint8_t len, uint8_t sizey) {
    uint8_t t, temp, m = 0;
    uint8_t enshow = 0;
    if ((sizey != 8 && sizey != 16) || len > 5 || x >= OLED_WIDTH || y >= OLED_HEIGHT)
        return;
    if (sizey == 8)
        m = 2;
    for (t = 0; t < len; t++) {
        if ((uint16_t)x + (sizey / 2 + m) * t >= OLED_WIDTH)
            break;
        temp = (num / oled_pow(10, len - t - 1)) % 10;
        if (enshow == 0 && t < (len - 1)) {
            if (temp == 0) {
                OLED_ShowChar(x + (sizey / 2 + m) * t, y, ' ', sizey);
                continue;
            } else
                enshow = 1;
        }
        OLED_ShowChar(x + (sizey / 2 + m) * t, y, temp + '0', sizey);
    }
}

// Display a string
void OLED_ShowString(uint8_t x, uint8_t y, const uint8_t *chr, uint8_t sizey) {
    if ((sizey != 8 && sizey != 16) || y >= OLED_HEIGHT)
        return;
    while (x < OLED_WIDTH && *chr) {
        OLED_ShowChar(x, y, *chr++, sizey);
        if (sizey == 8)
            x += 6;
        else
            x += sizey / 2;
    }
}
#endif

// Initialize
void OLED_Init(void) {
    i2c_init();
    OLED_RES_Set();
    GPIO_P2_SetMode(OLED_RES_PIN, GPIO_Mode_Output_PP);
    OLED_RES_Clr();
    delay_ms(200);
    OLED_RES_Set();
    delay_ms(200);
    oled_command(0xAE); //--turn off oled panel
    oled_command(0x00); //---set low column address
    oled_command(0x10); //---set high column address
    oled_command(0x40); //--set start line address (0x00~0x3F)
    oled_command(0x81); //--set contrast control register
    oled_command(0xff); // Set SEG Output Current Brightness
    oled_command(0xA1); // Set SEG/Column Mapping: 0xa0 mirrored, 0xa1 normal
    oled_command(0xC8); // Set COM/Row Scan Direction: 0xc0 mirrored, 0xc8 normal
    oled_command(0xA6); //--set normal display
    oled_command(0xA8); // SSD1306 multiplex ratio = argument + 1
    oled_command(0x1f); // 1/32 duty for the physical 128x32 panel
    oled_command(0xD3); // Set display offset (0x00~0x3F)
    oled_command(0x00); //-not offset
    oled_command(0xd5); //--set display clock divide ratio/oscillator frequency
    oled_command(0x80); //--set divide ratio, Set Clock as 100 Frames/Sec
    oled_command(0xD9); //--set pre-charge period
    oled_command(0xF1); // Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    oled_command(0xDA); //--set com pins hardware configuration
    oled_command(0x02); // Sequential COM pins, no left/right remap
    oled_command(0xDB); //--set vcomh
    oled_command(0x40); // Set VCOM Deselect Level
    oled_command(0x20); //-Set Page Addressing Mode (0x00/0x01/0x02)
    oled_command(0x02);
    oled_command(0x8D); //--set Charge Pump enable/disable
    oled_command(0x14); //--set(0x10) disable
    oled_command(0xA4); // Disable Entire Display On (0xa4/0xa5)
    oled_command(0xA6); // Disable Inverse Display On (0xa6/a7)
    /* Synchronize the cleared framebuffer and controller RAM before display-on. */
    OLED_display_clear();
    OLED_display();
    oled_command(0xAF); /*display ON*/
    OLED_ColorTurn(0);
    OLED_DisplayTurn(0);
    OLED_Display_On();
}

void OLED_DrawPixel(uint8_t x, uint8_t y, uint8_t color) {
    uint8_t mask;
    uint8_t *pBuf;
    if (x >= OLED_WIDTH || y >= OLED_HEIGHT) {
        return;
    }
    pBuf = &oled_buffer[(uint16_t)(y >> 3) * OLED_WIDTH + x];
    mask = 1 << (y & 7);
    if (!color) {
        *pBuf++ &= ~mask;
    } else {
        *pBuf++ |= mask;
    }
}

#ifdef OLED_ENABLE_LEGACY_API
void _swap_char(uint8_t *a, uint8_t *b) {
    uint8_t tmp = *a;
    *a = *b;
    *b = tmp;
}
#endif

/*========================================================
 * Purpose: Draw a line in the OLED buffer.
 * Parameters: x1,y1 start point; x2,y2 end point.
 *             color is the pixel color.
 * Return: None.
 *========================================================*/
void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color) {
    uint8_t i;
    int16_t dx, dy, error, twice_error;
    int8_t sy;
    if (x1 >= OLED_WIDTH || x2 >= OLED_WIDTH || y1 >= OLED_HEIGHT || y2 >= OLED_HEIGHT)
        return;
    if (x1 > x2) {
        i = x2;
        x2 = x1;
        x1 = i;
        i = y2;
        y2 = y1;
        y1 = i;
    }
    /* Keep byte-sized axis loops for the loading bars. */
    if (x1 == x2) {
        if (y1 <= y2) {
            for (y1; y1 <= y2; y1++) {
                OLED_DrawPixel(x1, y1, color);
            }
        } else if (y1 > y2) {
            for (y2; y2 <= y1; y2++) {
                OLED_DrawPixel(x1, y2, color);
            }
        }
    } else if (y1 == y2) {
        for (x1; x1 <= x2; x1++) {
            OLED_DrawPixel(x1, y1, color);
        }
    } else {
        dx = (int16_t)x2 - x1;
        dy = y1 < y2 ? (int16_t)y1 - y2 : (int16_t)y2 - y1;
        sy = y1 < y2 ? 1 : -1;
        error = dx + dy;
        for (;;) {
            OLED_DrawPixel(x1, y1, color);
            if (x1 == x2 && y1 == y2)
                break;
            /* Multiply, not a signed left shift: error can be negative. */
            twice_error = error * 2;
            if (twice_error >= dy) {
                error += dy;
                ++x1;
            }
            if (twice_error <= dx) {
                error += dx;
                y1 += sy;
            }
        }
    }
}

void OLED_display(void) {
    uint8_t page, column;
    const __xdata uint8_t *data = oled_buffer;
    for (page = 0; page < OLED_PAGES; ++page) {
        oled_begin(0x00);
        i2c_write_byte(0xb0 | page);
        i2c_clock_ack();
        i2c_write_byte(0x00);
        i2c_clock_ack();
        i2c_write_byte(0x10);
        i2c_clock_ack();
        i2c_stop();

        oled_begin(0x40);
        for (column = 0; column < OLED_WIDTH; ++column) {
            i2c_write_byte(*data++);
            i2c_clock_ack();
        }
        i2c_stop();
    }
}

void OLED_display_clear(void) {
    memset(oled_buffer, 0x00, sizeof oled_buffer);
}

#ifdef OLED_ENABLE_LEGACY_API
void OLED_Draw_Byte(uint8_t *pBuf, uint8_t mask, uint8_t offset, __BIT reserve_hl) {
    if (_OLED_Overlap) {
        if (_OLED_Reverse)
            *pBuf |= ~mask;
        else
            *pBuf |= mask;
    } else {
        if (_OLED_Reverse) {
            /* Reserve upper */
            if (reserve_hl) {
                *pBuf &= (~mask) | (0xFF << (8 - offset));
                *pBuf |= (~mask) & (0xFF >> offset);
            }
            /* Reserve lower */
            else {
                *pBuf &= (~mask) | (0xFF >> (8 - offset));
                *pBuf |= (~mask) & (0xFF << offset);
            }
        } else {
            /* Reserve upper */
            if (reserve_hl) {
                *pBuf &= mask | (0xFF << (8 - offset));
                *pBuf |= mask & (0xFF >> offset);
            }
            /* Reserve lower */
            else {
                *pBuf &= mask | (0xFF >> (8 - offset));
                *pBuf |= mask & (0xFF << offset);
            }
        }
    }
}

void OLED_DrawChar(uint8_t x, uint8_t y, uint8_t chr) {
    uint8_t c = chr - ' ', row, col, bit;
    if (x >= OLED_WIDTH || y >= OLED_HEIGHT)
        return;
    if (c >= sizeof asc2_1608 / sizeof asc2_1608[0])
        c = 0;
    /* Retain overlap/reverse semantics with the complete native 8x16 font. */
    for (row = 0; row < 16 && row < OLED_HEIGHT - y; ++row) {
        for (col = 0; col < 8 && col < OLED_WIDTH - x; ++col) {
            bit = ((asc2_1608[c][(row >> 3) * 8 + col] >> (row & 7)) & 1) ^ _OLED_Reverse;
            if (bit || !_OLED_Overlap)
                OLED_DrawPixel(x + col, y + row, bit);
        }
    }
}
void OLED_Set_Posi(uint8_t x, uint8_t y) {
    __x = x;
    __y = y;
}

void OLED_DrawNum(uint8_t digit, uint8_t len) {
    uint8_t t, i, temp;
    uint8_t enshow = 0;
    i = 0;
    if (len > 3 || __y >= OLED_HEIGHT)
        return;
    for (t = 0; t < len; t++) {
        temp = (digit / oled_pow(10, len - t - 1)) % 10;

        if (enshow == 0 && t < (len - 1)) {
            if (temp == 0) {
                i++;
                continue;
            } else
                enshow = 1;
        }

        if ((uint16_t)__x + 8 * (t - i) > OLED_WIDTH - 8)
            break;
        OLED_DrawChar(__x + 8 * (t - i), __y, temp + '0');
    }
    if (__x < OLED_WIDTH)
        __x += 8 * (t - i);
}
#endif

void OLED_DrawStringSmall(uint8_t x, uint8_t y, const __code char *text) {
    uint8_t c;
    if (y >= OLED_HEIGHT)
        return;
    while (x <= OLED_WIDTH - 6 && *text) {
        c = (uint8_t)*text++ - ' ';
        if (c >= sizeof asc2_0806 / sizeof asc2_0806[0])
            c = 0;
        OLED_DrawBMP_2(x, y, 6, 8, asc2_0806[c]);
        x += 6;
    }
}

void OLED_DrawBitmap(uint8_t x0, uint8_t y0, uint8_t xsize, uint8_t ysize, const uint8_t *BMP,
                     uint8_t inverted) {
    uint8_t columns, offset, rows, col, byte;
    uint16_t mask, bits;
    __xdata uint8_t *dest;
    if (x0 >= OLED_WIDTH || y0 >= OLED_HEIGHT || !xsize || !ysize)
        return;
    columns = xsize;
    if (columns > OLED_WIDTH - x0)
        columns = OLED_WIDTH - x0;
    if (ysize > OLED_HEIGHT - y0)
        ysize = OLED_HEIGHT - y0;
    offset = y0 & 7;
    while (ysize) {
        rows = ysize < 8 ? ysize : 8;
        mask = (uint16_t)(0xff >> (8 - rows)) << offset;
        dest = &oled_buffer[(uint16_t)(y0 >> 3) * OLED_WIDTH + x0];
        for (col = 0; col < columns; ++col) {
            byte = BMP[col];
            if (inverted)
                byte = (uint8_t)~byte;
            /* One source byte spans at most two destination pages. */
            bits = ((uint16_t)byte << offset) & mask;
            *dest = (*dest & (uint8_t)~mask) | (uint8_t)bits;
            /* Clipped height guarantees a second page exists when this mask is nonzero. */
            if (mask >> 8)
                dest[OLED_WIDTH] =
                    (dest[OLED_WIDTH] & (uint8_t)~(mask >> 8)) | (uint8_t)(bits >> 8);
            ++dest;
        }
        BMP += xsize;
        y0 += rows;
        ysize -= rows;
    }
}
