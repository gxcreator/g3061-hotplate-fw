#ifndef __OLED_H
#define __OLED_H

#include "board.h"
#include <stdint.h>
 
	
#define OLED_CMD  0	//Write command
#define OLED_DATA 1	//Write data

//-----------------OLED port definitions----------------

#define OLED_RES_Clr() OLED_RES=0
#define OLED_RES_Set() OLED_RES=1



//OLED control functions
void delay_ms(uint16_t ms);
void OLED_ColorTurn(uint8_t i);
void OLED_DisplayTurn(uint8_t i);
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_Set_Pos(uint8_t x, uint8_t y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t sizey);
uint16_t oled_pow(uint8_t m,uint8_t n);
void OLED_ShowNum(uint8_t x,uint8_t y,uint16_t num,uint8_t len,uint8_t sizey);
void OLED_ShowString(uint8_t x,uint8_t y,const uint8_t *chr,uint8_t sizey);
void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t no,uint8_t sizey);
void OLED_DrawBMP(int16_t x,int16_t y,uint8_t sizex,uint8_t sizey,const uint8_t BMP[]);
void OLED_Init(void);
void OLED_Display(void);
void OLED_Write_Data(uint8_t dat);
void OLED_DrawPixel(uint8_t x,uint8_t y,uint8_t color);
void OLED_display(void);
void _swap_char(uint8_t* a,uint8_t* b);
void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t color);
void OLED_display_clear(void);
void OLED_Draw_Byte(uint8_t *pBuf, uint8_t mask, uint8_t offset, __BIT reserve_hl);
void OLED_DrawChar(uint8_t x, uint8_t y, uint8_t chr);
void OLED_DrawNum(uint8_t digit, uint8_t len);
void OLED_Set_Posi(uint8_t x, uint8_t y);
void OLED_DrawBMP_2(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t *BMP);

#endif  
	 



