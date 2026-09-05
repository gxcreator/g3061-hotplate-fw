#include "STC8XXXX.H"
#include <intrins.h>
#include "ADC.h"


/*
	Delay function: 1 us at 33.1776 MHz.
	Parameter: delay duration.
	Returns: none.
*/
void delayus(unsigned int nn)
{
	unsigned int ii;
	for(ii=0;ii<nn;ii++)
	{
		_nop_();
		_nop_();
		_nop_();
	}
}
/*
	Initialize the ADC.
	Parameters: none.
	Returns: none.
*/
void adc_init(void)
{
	unsigned char __data saved_p_sw2 = P_SW2;
	P_SW2 |= 0x80;//Enable access to extended SFRs.
	ADCTIM = 0x3f;//Sample for 32 ADC clocks; default channel setup/hold times.
	P_SW2 = saved_p_sw2;
	ADCCFG = 0x2f;//Right-aligned result; ADC clock = system clock / 32.
	ADC_RES = 0;
	ADC_RESL = 0;//Clear the result register.
	delayus(20);
}

/*
	Read an ADC value.
	Parameter: ADC channel 0-14.
	Returns: 12-bit ADC value.
*/
unsigned int get_adc(unsigned int p)
{
	switch(p)
	{
		case 0 : ADC_CONTR = 0xC0; break;
		case 1 : ADC_CONTR = 0xC1; break;
		case 2 : ADC_CONTR = 0xC2; break;
		case 3 : ADC_CONTR = 0xC3; break;
		case 4 : ADC_CONTR = 0xC4; break;
		case 5 : ADC_CONTR = 0xC5; break;
		case 6 : ADC_CONTR = 0xC6; break;
		case 7 : ADC_CONTR = 0xC7; break;
		case 8 : ADC_CONTR = 0xC8; break;
		case 9 : ADC_CONTR = 0xC9; break;
		case 10: ADC_CONTR = 0XCA; break;
		case 11: ADC_CONTR = 0xCB; break;
		case 12: ADC_CONTR = 0xCC; break;
		case 13: ADC_CONTR = 0xCD; break;
		case 14: ADC_CONTR = 0xCE; break;
		case 15: ADC_CONTR = 0xCF; break;
	}
	delayus(10);
	while(!(ADC_CONTR & 0x20));//Wait for ADC conversion to complete.
	ADC_CONTR &= ~0x20;//Disable the ADC converter.
	return (ADC_RES * 256 + ADC_RESL);
}
