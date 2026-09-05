#include <math.h>
#include "temperature.h"

/* PT100 to ground, with a 500 ohm pull-up to the ADC reference supply. */
unsigned int temperature_from_adc(unsigned int adc)
{
	float delta, temp;
	/* ADC codes that round to 0-400 C. Reject faults before division/sqrt. */
	if(adc < 682 || adc > 1355)
	{
		return TEMPERATURE_INVALID;
	}
	delta = (500.0f * adc / (4096.0f - adc)) / 100.0f - 1.0f;
	/* Stable inverse of R/R0 = 1 + A*T + B*T*T (IEC 60751). */
	temp = 2.0f * delta / (3.9083e-3f +
		sqrtf(3.9083e-3f * 3.9083e-3f - 4.0f * 5.775e-7f * delta));
	return (unsigned int)(temp + 0.5f);
}
