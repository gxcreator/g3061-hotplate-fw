#ifndef __OLED_H
#define __OLED_H

#include "board.h"
#include <stdint.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_PAGES (OLED_HEIGHT / 8)

//-----------------OLED port definitions----------------

#define OLED_RES_Clr() OLED_RES = 0
#define OLED_RES_Set() OLED_RES = 1

// Controller configuration commands are immediate; they do not modify pixel data.
void delay_ms(uint16_t ms);
void OLED_ColorTurn(uint8_t i);
void OLED_DisplayTurn(uint8_t i);
void OLED_Display_On(void);
/* Reset/configure the controller, clear the framebuffer, and flush before display-on. */
void OLED_Init(void);
/* All drawing/clearing modifies only the framebuffer, using native pixel coordinates:
 * x 0..127, y 0..31. Call OLED_display() to publish the completed frame. */
void OLED_DrawPixel(uint8_t x, uint8_t y, uint8_t color);
/* Sole pixel-data transport: flush all four framebuffer pages. */
void OLED_display(void);
/* Inclusive endpoints; rejects either endpoint outside native bounds.
 * Diagonals use integer Bresenham rasterization. */
void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void OLED_display_clear(void);
/* Native 6x8 (sizey=8) or 8x16 (sizey=16) glyph, clipped at right/bottom.
 * 8x16 requires OLED_ENABLE_FONT_8X16 or OLED_ENABLE_LEGACY_API.
 * Unsupported font indices draw a space; unavailable/other sizes do nothing. */
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t sizey);
/* Native 6x8 text from code memory, with bottom clipping.
 * Stops before a partial glyph at the right edge; unsupported font indices draw a space. */
void OLED_DrawStringSmall(uint8_t x, uint8_t y, const __code char *text);
/* Pixel coordinates and dimensions; arbitrary y and partial heights supported.
 * Source is page-major, bit 0 at top, xsize * ceil(ysize/8) bytes.
 * Clips right/bottom, retaining source stride. Pixels outside the rectangle are preserved.
 * Nonzero inverted complements only active pixels, never final-page padding. */
void OLED_DrawBitmap(uint8_t x0, uint8_t y0, uint8_t xsize, uint8_t ysize,
                     const __code uint8_t *BMP, uint8_t inverted);
/* Macros avoid SDCC XRAM parameter storage for runtime wrappers. */
#define OLED_DrawBMP_2(x0, y0, xsize, ysize, BMP)                                                  \
    OLED_DrawBitmap((x0), (y0), (xsize), (ysize), (BMP), 0)
#define OLED_DrawBMP_2_Inverted(x0, y0, xsize, ysize, BMP)                                         \
    OLED_DrawBitmap((x0), (y0), (xsize), (ysize), (BMP), 1)

/* Default-off helpers with no production callers. Define via CPPFLAGS and rebuild with -B. */
#ifdef OLED_ENABLE_LEGACY_API
void OLED_Display_Off(void);
uint16_t oled_pow(uint8_t m, uint8_t n);
/* Buffered text uses pixel coordinates, like OLED_ShowChar. */
void OLED_ShowNum(uint8_t x, uint8_t y, uint16_t num, uint8_t len, uint8_t sizey);
void OLED_ShowString(uint8_t x, uint8_t y, const uint8_t *chr, uint8_t sizey);
void _swap_char(uint8_t *a, uint8_t *b);
void OLED_Draw_Byte(uint8_t *pBuf, uint8_t mask, uint8_t offset, __BIT reserve_hl);
/* Buffered text and cursor use native pixel coordinates. */
void OLED_DrawChar(uint8_t x, uint8_t y, uint8_t chr);
void OLED_DrawNum(uint8_t digit, uint8_t len);
void OLED_Set_Posi(uint8_t x, uint8_t y);
#endif

#endif
