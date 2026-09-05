#include "STC8XXXX.H"

void Timer0Init(void)//1000us@33.1776MHz
{
	AUXR |= 0x80;
	TMOD &= 0xF0;
	TL0 = 0x66;
	TH0 = 0x7E;
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
}

void Timer2Init(void)		//50us@33.1776MHz
{
	AUXR |= 0x04;
	T2L = 0x85;
	T2H = 0xF9;
	AUXR |= 0x10;
	IE2 |= 0x04; 
}