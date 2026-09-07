#include "config.h"
#include "fw_adc.h"
#include "fw_sys.h"
#include "ADC.h"

/*
        Configure the ADC at startup, with extended-register access enabled.
        Parameters: none.
        Returns: none.
*/
void adc_init(void) {
    ADC_SetChannelSwitchTime(0); // 1 ADC clock.
    ADC_SetChannelHoldTime(1);   // 2 ADC clocks.
    ADC_SetSampleTime(31);       // 32 ADC clocks.
    ADC_SetResultAlignmentRight();
    ADC_SetClockPrescaler(15); // ADC clock = system clock / 32.
    ADC_SetPWMTriggerState(HAL_State_OFF);
    ADC_SetPowerState(HAL_State_ON);
    /* Allow at least 1 ms for ADC power stabilization before any conversion. */
    SYS_Delay(2);
}

/*
        Read an ADC value.
        Parameter: ADC channel 0-15; channel 15 is the internal reference.
        Returns: 12-bit ADC value, or 0xffff for an invalid channel.
*/
uint16_t get_adc(uint16_t p) {
    if (p <= 15) {
        ADC_SetChannel(p);
        ADC_ClearInterrupt();
        ADC_SetPowerState(HAL_State_ON);
        return ADC_ConvertHP();
    }
    return 0xffffu;
}
