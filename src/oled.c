#include "oled.h"
#include "i2c.h"
#include "oledfont.h"  	
#include <math.h>
#include <stdlib.h>
#include <string.h>

uint8_t _buf[128*8]={0};

const uint8_t __code height=8;
const uint8_t __code width=128;

__BIT _OLED_Reverse = 0;
__BIT _OLED_Overlap = 1;

static uint8_t __x, __y;

void delay_ms(uint16_t ms)
{
	volatile uint16_t a;
	while(ms)
	{
		a=1800;
		while(a--);
		ms--;
	}
	return;
}

//Display inversion
void OLED_ColorTurn(uint8_t i)
{
	if(i==0)
		{
			OLED_WR_Byte(0xA6,OLED_CMD);//Normal display
		}
	if(i==1)
		{
			OLED_WR_Byte(0xA7,OLED_CMD);//Inverse display
		}
}

//Rotate display 180 degrees
void OLED_DisplayTurn(uint8_t i)
{
	if(i==0)
		{
			OLED_WR_Byte(0xC8,OLED_CMD);//Normal display
			OLED_WR_Byte(0xA1,OLED_CMD);
		}
	if(i==1)
		{
			OLED_WR_Byte(0xC0,OLED_CMD);//Rotated display
			OLED_WR_Byte(0xA0,OLED_CMD);
		}
}

//Send one byte
//Write one byte to the SSD1306.
//mode: data/command flag; 0 selects command, 1 selects data.
void OLED_WR_Byte(uint8_t dat,uint8_t mode)
{
	i2c_start();
	i2c_write_byte(0x78);
	i2c_clock_ack();
	if(mode){i2c_write_byte(0x40);}
  else{i2c_write_byte(0x00);}
	i2c_clock_ack();
	i2c_write_byte(dat);
	i2c_clock_ack();
	i2c_stop();
}

//Set coordinates
void OLED_Set_Pos(uint8_t x, uint8_t y)
{ 
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f),OLED_CMD);
}   	  
//Enable OLED display    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC command
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//Disable OLED display     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC command
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//Clear the display to black.	  
void OLED_Clear(void)  
{  
	uint8_t i,n;
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //Set page address (0-7)
		OLED_WR_Byte (0x00,OLED_CMD);      //Set display position: low column address
		OLED_WR_Byte (0x10,OLED_CMD);      //Set display position: high column address   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	} //Update display
}

//Display a character at the specified position, including partial characters
//x:0~127
//y:0~63				 
//sizey: select 6x8 or 8x16 font
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t sizey)
{      	
	uint8_t c=0,sizex=sizey/2;
	uint16_t i=0,size1;
	if(sizey==8)size1=6;
	else size1=(sizey/8+((sizey%8)?1:0))*(sizey/2);
	c=chr-' ';//Get the offset font index
	OLED_Set_Pos(x,y);
	for(i=0;i<size1;i++)
	{
		if(i%sizex==0&&sizey!=8) OLED_Set_Pos(x,y++);
		if(sizey==8) OLED_WR_Byte(asc2_0806[c][i],OLED_DATA);//6X8 font
		else if(sizey==16) OLED_WR_Byte(asc2_1608[c][i],OLED_DATA);//8x16 font
//		else if(sizey==xx) OLED_WR_Byte(asc2_xxxx[c][i],OLED_DATA);//User-defined font
		else return;
	}
}
//Compute m^n
uint16_t oled_pow(uint8_t m,uint8_t n)
{
	uint16_t result=1;
	while(n--)result*=m;    
	return result;
}				  
//Display a number
//x,y: starting coordinates
//num: number to display
//len: number of digits
//sizey: font size		  
void OLED_ShowNum(uint8_t x,uint8_t y,uint16_t num,uint8_t len,uint8_t sizey)
{         	
	uint8_t t,temp,m=0;
	uint8_t enshow=0;
	if(sizey==8)m=2;
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(sizey/2+m)*t,y,' ',sizey);
				continue;
			}else enshow=1;
		}
	 	OLED_ShowChar(x+(sizey/2+m)*t,y,temp+'0',sizey);
	}
}

//Display a string
void OLED_ShowString(uint8_t x,uint8_t y,const uint8_t *chr,uint8_t sizey)
{
	uint8_t j=0;
	while (chr[j]!='\0')
	{		
		OLED_ShowChar(x,y,chr[j++],sizey);
		if(sizey==8)x+=6;
		else x+=sizey/2;
	}
}
//Display Chinese characters
//void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t no,uint8_t sizey)
//{
//	uint16_t i,size1=(sizey/8+((sizey%8)?1:0))*sizey;
//	for(i=0;i<size1;i++)
//	{
//		if(i%sizey==0) OLED_Set_Pos(x,y++);
//		if(sizey==16) OLED_WR_Byte(Hzk[no][i],OLED_DATA);//16x16 font
////		else if(sizey==xx) OLED_WR_Byte(xxx[c][i],OLED_DATA);//User-defined font
//		else return;
//	}				
//}


//Display an image
//x,y: display coordinates
//sizex,sizey: image dimensions
//BMP: image to display
void OLED_DrawBMP(int16_t x,int16_t y,uint8_t sizex, uint8_t sizey,const uint8_t BMP[])
{ 	
  int16_t j=0;
	int16_t i,m;
	sizey=sizey/8+((sizey%8)?1:0);
	for(i=0;i<sizey;i++)
	{
		OLED_Set_Pos(x,i+y);
    for(m=0;m<sizex;m++)
		{      
			OLED_WR_Byte(BMP[j++],OLED_DATA);	    	
		}
	}
} 



//Initialize				    
void OLED_Init(void)
{
	i2c_init();
	OLED_RES_Set();
	GPIO_P2_SetMode(OLED_RES_PIN, GPIO_Mode_Output_PP);
	OLED_RES_Clr();
  delay_ms(200);
	OLED_RES_Set();
	delay_ms(200);
	OLED_WR_Byte(0xAE,OLED_CMD);//--turn off oled panel
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WR_Byte(0x81,OLED_CMD);//--set contrast control register
	OLED_WR_Byte(0xff,OLED_CMD); // Set SEG Output Current Brightness
	OLED_WR_Byte(0xA1,OLED_CMD);//--Set SEG/Column Mapping     0xa0 mirrored horizontally, 0xa1 normal
	OLED_WR_Byte(0xC8,OLED_CMD);//Set COM/Row Scan Direction   0xc0 mirrored vertically, 0xc8 normal
	OLED_WR_Byte(0xA6,OLED_CMD);//--set normal display
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3f,OLED_CMD);//--1/64 duty
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WR_Byte(0x00,OLED_CMD);//-not offset
	OLED_WR_Byte(0xd5,OLED_CMD);//--set display clock divide ratio/oscillator frequency
	OLED_WR_Byte(0x80,OLED_CMD);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WR_Byte(0xD9,OLED_CMD);//--set pre-charge period
	OLED_WR_Byte(0xF1,OLED_CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WR_Byte(0xDA,OLED_CMD);//--set com pins hardware configuration
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0xDB,OLED_CMD);//--set vcomh
	OLED_WR_Byte(0x40,OLED_CMD);//Set VCOM Deselect Level
	OLED_WR_Byte(0x20,OLED_CMD);//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WR_Byte(0x02,OLED_CMD);//
	OLED_WR_Byte(0x8D,OLED_CMD);//--set Charge Pump enable/disable
	OLED_WR_Byte(0x14,OLED_CMD);//--set(0x10) disable
	OLED_WR_Byte(0xA4,OLED_CMD);// Disable Entire Display On (0xa4/0xa5)
	OLED_WR_Byte(0xA6,OLED_CMD);// Disable Inverse Display On (0xa6/a7) 
	OLED_Clear();
	OLED_WR_Byte(0xAF,OLED_CMD); /*display ON*/ 
	OLED_Clear();
	OLED_ColorTurn(0);
  OLED_DisplayTurn(0);
	OLED_Display_On();
}

void OLED_DrawPixel(uint8_t x, uint8_t y,uint8_t color)
{
    uint8_t mask;
    uint8_t *pBuf;
		if(x >= width || y >= height * 8)
		{
			return;
		}
		if(y%2 == 0)
		{
			y++;
		}
		pBuf = &_buf[(y >> 3) * width + x];
    mask = 1 << (y & 7);
    if (!color)
    {
        *pBuf++ &= ~mask;
    }
    else
    {
        *pBuf++ |= mask;
    }
}

void _swap_char(uint8_t* a,uint8_t* b)
{
	uint8_t tmp = *a;
	*a = *b;
	*b = tmp;
}

/*========================================================
* Purpose: Draw a line in the OLED buffer.
* Parameters: x1,y1 start point; x2,y2 end point.
*             color is the pixel color.
* Return: None.
*========================================================*/
void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2, uint8_t color)
{
	uint8_t i = 0;
	int8_t DeltaY = 0,DeltaX = 0;
	float k = 0,b = 0;
	if(x1>x2)
	{
		i = x2;x2 = x1;x1 = i;
		i = y2;y2 = y1;y1 = i;
		i = 0;
	}
	DeltaY = y2 - y1;
	DeltaX = x2 - x1;
	if(DeltaX == 0)
	{
		if(y1<=y2)
			{
				for(y1;y1<=y2;y1++)
				{
					OLED_DrawPixel(x1,y1,color);
				}
			}else if(y1>y2)
			{
				for(y2;y2<=y1;y2++)
				{
					OLED_DrawPixel(x1,y2,color);
				}
			}
	}
	else if(DeltaY == 0)
	{
		for(x1;x1<=x2;x1++)
		{
			OLED_DrawPixel(x1,y1,color);
		}	
	}
	else
	{
		k = ((float)DeltaY)/((float)DeltaX);
		b = y2 - k * x2;
		if((k>-1&k<1))
		{
			for(x1;x1<=x2;x1++)
			{
				OLED_DrawPixel(x1,(int16_t)(k * x1 + b),color);
			}
		}else if((k>=1)|(k<=-1))
		{
			if(y1<=y2)
			{
				for(y1;y1<=y2;y1++)
				{
					OLED_DrawPixel((int16_t)((y1 - b) / k),y1,color);
				}
			}else if(y1>y2)
			{
				for(y2;y2<=y1;y2++)
				{
					OLED_DrawPixel((int16_t)((y2 - b) / k),y2,color);
				}
			}
		}
	}
}

void OLED_display(void)
{
	OLED_DrawBMP(0,0,128,64,_buf);
	//OLED_DrawBMP(0,6,width[1],heigth[1]*8,_buf1);
}

void OLED_display_clear(void)
{
	memset(_buf, 0x00, width * height);
}

void OLED_Draw_Byte(uint8_t *pBuf, uint8_t mask, uint8_t offset, __BIT reserve_hl)
{
    if (_OLED_Overlap)
    {
        if (_OLED_Reverse)
            *pBuf |= ~mask;
        else
            *pBuf |= mask;
    }
    else
    {
        if (_OLED_Reverse)
        {
            /* Reserve upper */
            if (reserve_hl) 
            {
                *pBuf &= (~mask) | (0xFF << (8 - offset));
                *pBuf |= (~mask) & (0xFF >> offset);
            }
            /* Reserve lower */
            else 
            {
                *pBuf &= (~mask) | (0xFF >> (8 - offset));
                *pBuf |= (~mask) & (0xFF << offset);
            }
        }
        else
        {
            /* Reserve upper */
            if (reserve_hl) 
            {
                *pBuf &= mask | (0xFF << (8 - offset));
                *pBuf |= mask & (0xFF >> offset);
            }
            /* Reserve lower */ 
            else 
            {
                *pBuf &= mask | (0xFF >> (8 - offset));
                *pBuf |= mask & (0xFF << offset);
            }
        }
    }
}


void OLED_DrawChar(uint8_t x, uint8_t y, uint8_t chr)
{
    uint8_t c;
    uint8_t i;
    uint8_t mask;
    uint8_t *pBuf;
    uint8_t offset;
    offset = y & 7;
    c = chr - ' ';
			pBuf = &_buf[(y >> 3) * width + x];

    for (i = 0; i < 8; i++)
    {
        mask = asc2_1608[c][i] << offset;
        OLED_Draw_Byte(pBuf++, mask, offset, 0);
    }
    if (offset && y < 56 - 8)
    {
        pBuf = &_buf[((y >> 3) + 1) * 100 + x];
        for (i = 0; i < 6; i++)
        {
            mask = asc2_0806[c][i] >> (8 - offset);
            OLED_Draw_Byte(pBuf++, mask, 8 - offset, 1);
        }
    }
}
void OLED_Set_Posi(uint8_t x, uint8_t y)
{
    __x = x;
    __y = y;
}

void OLED_DrawNum(uint8_t digit, uint8_t len)
{
    uint8_t t, i, temp;
    uint8_t enshow = 0;
    i = 0;
    for (t = 0; t < len; t++)
    {
        temp = (digit / oled_pow(10, len - t - 1)) % 10;

        if (enshow == 0 && t < (len - 1))
        {
            if (temp == 0)
            {
                i++;
                continue;
            }
            else
                enshow = 1;
        }

        if (__x > 100 - 6)
        {
            __x = 0;
            __y += 8;
        }
        if (__y > 56 - 8)
        {
            __y = 0;
        }

        OLED_DrawChar(__x + (6) * (t - i), __y, temp + '0');
    }
    __x += len;
}

void OLED_DrawBMP_2(uint8_t x0, uint8_t page0, uint8_t xsize, uint8_t ysize, const uint8_t *BMP)
{
	uint16_t i, j;
	for(j = page0; j < page0+ysize/8; j++)
	{
		for(i = x0; i < x0+xsize; i++)
		{
			_buf[i+(j)*width]=BMP[(i-x0)+(j-page0)*xsize];
		}
	}
}
