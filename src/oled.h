#ifndef __OLED_H
#define __OLED_H

#include "STC8XXXX.H"
 
#define  u8 unsigned char 
#define  u16 unsigned int
#define  u32 unsigned int
	
#define OLED_CMD  0	//Write command
#define OLED_DATA 1	//Write data

__sbit __at(0xB5) OLED_SCL;//SCL (P3^5)
__sbit __at(0xB6) OLED_SDA;//SDA (P3^6)
__sbit __at(0xA3) OLED_RES;//RES (P2^3)

//-----------------OLED port definitions----------------

#define OLED_SCL_Clr() OLED_SCL=0
#define OLED_SCL_Set() OLED_SCL=1

#define OLED_SDA_Clr() OLED_SDA=0
#define OLED_SDA_Set() OLED_SDA=1

#define OLED_RES_Clr() OLED_RES=0
#define OLED_RES_Set() OLED_RES=1



//OLED control functions
void delay_ms(unsigned int ms);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 cmd);
void OLED_Set_Pos(u8 x, u8 y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 sizey);
unsigned int oled_pow(u8 m,u8 n);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 sizey);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 sizey);
void OLED_ShowChinese(u8 x,u8 y,u8 no,u8 sizey);
void OLED_DrawBMP(int x,int y,unsigned char sizex,unsigned char sizey,unsigned char BMP[]);
void OLED_Init(void);
void OLED_Display(void);
void OLED_Write_Data(unsigned char dat);
void OLED_DrawPixel(unsigned char x,unsigned char y,unsigned char color);
void OLED_display(void);
void _swap_char(unsigned char* a,unsigned char* b);
void OLED_DrawLine(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char color);
void OLED_display_clear(void);
void OLED_Draw_Byte(unsigned char *pBuf, unsigned char mask, unsigned char offset, bit reserve_hl);
void OLED_DrawChar(u8 x, u8 y, u8 chr);
void OLED_DrawNum(unsigned char digit, unsigned char len);
void OLED_Set_Posi(unsigned char x, unsigned char y);
void OLED_DrawBMP_2(u8 x0, u8 y0, u8 x1, u8 y1, u8 *BMP);

#endif  
	 



