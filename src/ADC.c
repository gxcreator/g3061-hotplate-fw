#include "config.h"
#include "fw_adc.h"
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
		NOP();
		NOP();
		NOP();
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
	SFRX_ON();//Enable access to extended SFRs.
	ADCTIM = 0x3f;//Sample for 32 ADC clocks; default channel setup/hold times.
	P_SW2 = saved_p_sw2;
	ADCCFG = 0;
	ADC_SetResultAlignmentRight();
	ADC_SetClockPrescaler(15);//ADC clock = system clock / 32.
	ADC_CONTR = 0;//Disable PWM triggering and clear stale conversion state.
	ADC_RES = 0;
	ADC_RESL = 0;//Clear the result register.
	delayus(20);
}

/*
	Read an ADC value.
	Parameter: ADC channel 0-15; channel 15 is the internal reference.
	Returns: 12-bit ADC value.
*/
unsigned int get_adc(unsigned int p)
{
	if(p <= 15)
	{
		ADC_SetChannel(p);
		ADC_ClearInterrupt();
		ADC_SetPowerState(HAL_State_ON);
		ADC_Start();
	}
	delayus(10);
	while(!ADC_SamplingFinished());//Wait for ADC conversion to complete.
	ADC_ClearInterrupt();
	return (ADC_RES * 256 + ADC_RESL);
}
