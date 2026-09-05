#include "STC8XXXX.H"
#include "oled.h"
#include "oledfont.h"  	
#include <math.h>
#include <stdlib.h>
#include <string.h>

unsigned char _buf[128*8]={0};

const unsigned char __code height=8;
const unsigned char __code width=128;

bit _OLED_Reverse = 0;     
bit _OLED_Overlap = 1;

static char __x, __y;

void delay_ms(unsigned int ms)
{
	volatile unsigned int a;
	while(ms)
	{
		a=1800;
		while(a--);
		ms--;
	}
	return;
}

//Display inversion
void OLED_ColorTurn(u8 i)
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
void OLED_DisplayTurn(u8 i)
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

//Delay
void IIC_delay(void)
{
	_nop_();
}

//Start signal
void I2C_Start(void)
{
	OLED_SDA_Set();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Clr();
	IIC_delay();
	OLED_SCL_Clr();
	 
}

//Stop signal
void I2C_Stop(void)
{
	OLED_SDA_Clr();
	IIC_delay();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Set();
	IIC_delay();
}

//Clock the ACK bit with SDA released; the response is not checked.
void I2C_WaitAck(void)
{
	OLED_SDA_Set();
	IIC_delay();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SCL_Clr();
	IIC_delay();
}

//Write one byte
void Send_Byte(u8 dat)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		OLED_SCL_Clr();//Set the clock signal low
		if(dat&0x80)//Write the eight data bits from MSB to LSB
		{
			OLED_SDA_Set();
    }
		else
		{
			OLED_SDA_Clr();
    }
		IIC_delay();
		OLED_SCL_Set();
		IIC_delay();
		OLED_SCL_Clr();
		dat<<=1;
  }
}

//Send one byte
//Write one byte to the SSD1306.
//mode: data/command flag; 0 selects command, 1 selects data.
void OLED_WR_Byte(u8 dat,u8 mode)
{
	I2C_Start();
	Send_Byte(0x78);
	I2C_WaitAck();
	if(mode){Send_Byte(0x40);}
  else{Send_Byte(0x00);}
	I2C_WaitAck();
	Send_Byte(dat);
	I2C_WaitAck();
	I2C_Stop();
}

//Set coordinates
void OLED_Set_Pos(u8 x, u8 y) 
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
	u8 i,n;		    
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
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 sizey)
{      	
	u8 c=0,sizex=sizey/2;
	u16 i=0,size1;
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
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//Display a number
//x,y: starting coordinates
//num: number to display
//len: number of digits
//sizey: font size		  
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 sizey)
{         	
	u8 t,temp,m=0;
	u8 enshow=0;
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
void OLED_ShowString(u8 x,u8 y,const u8 *chr,u8 sizey)
{
	u8 j=0;
	while (chr[j]!='\0')
	{		
		OLED_ShowChar(x,y,chr[j++],sizey);
		if(sizey==8)x+=6;
		else x+=sizey/2;
	}
}
//Display Chinese characters
//void OLED_ShowChinese(u8 x,u8 y,u8 no,u8 sizey)
//{
//	u16 i,size1=(sizey/8+((sizey%8)?1:0))*sizey;
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
void OLED_DrawBMP(int x,int y,unsigned char sizex, unsigned char sizey,const unsigned char BMP[])
{ 	
  int j=0;
	int i,m;
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
	OLED_SCL_Set();
	OLED_SDA_Set();
	//SCL is push-pull; SDA is quasi-bidirectional so ACK can pull it low.
	P3M1 &= (u8)~0x60;
	P3M0 = (P3M0 & (u8)~0x40) | 0x20;
	OLED_RES_Set();
	P2M1 &= (u8)~0x08;
	P2M0 |= 0x08;
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

void OLED_DrawPixel(unsigned char x, unsigned char y,unsigned char color)
{
    unsigned char mask;
    unsigned char *pBuf;
		if(y%2 == 0)
		{
			y++;
		}
    if (__x > width)
    {
        __x = 0;
        __y += 1;
    }
    if (__y > height * 8)
    {
        __y = 0;
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

void _swap_char(unsigned char* a,unsigned char* b)
{
	unsigned char tmp = *a;
	*a = *b;
	*b = tmp;
}

/*========================================================
* Purpose: Draw a line in the OLED buffer.
* Parameters: x1,y1 start point; x2,y2 end point.
*             color is the pixel color.
* Return: None.
*========================================================*/
void OLED_DrawLine(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2, unsigned char color)
{
	unsigned char i = 0;
	char DeltaY = 0,DeltaX = 0;
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
				OLED_DrawPixel(x1,(int)(k * x1 + b),color);
			}
		}else if((k>=1)|(k<=-1))
		{
			if(y1<=y2)
			{
				for(y1;y1<=y2;y1++)
				{
					OLED_DrawPixel((int)((y1 - b) / k),y1,color);
				}
			}else if(y1>y2)
			{
				for(y2;y2<=y1;y2++)
				{
					OLED_DrawPixel((int)((y2 - b) / k),y2,color);
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

void OLED_Draw_Byte(unsigned char *pBuf, unsigned char mask, unsigned char offset, bit reserve_hl)
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


void OLED_DrawChar(unsigned char x, unsigned char y, unsigned char chr)
{
    unsigned char c;
    unsigned char i;
    unsigned char mask;
    unsigned char *pBuf;
    unsigned char offset;
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
void OLED_Set_Posi(unsigned char x, unsigned char y)
{
    __x = x;
    __y = y;
}

void OLED_DrawNum(unsigned char digit, unsigned char len)
{
    unsigned char t, i, temp;
    unsigned char enshow = 0;
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

void OLED_DrawBMP_2(u8 x0, u8 page0, u8 xsize, u8 ysize, const u8 *BMP)
{
	u16 i, j;
	for(j = page0; j < page0+ysize/8; j++)
	{
		for(i = x0; i < x0+xsize; i++)
		{
			_buf[i+(j)*width]=BMP[(i-x0)+(j-page0)*xsize];
		}
	}
}
