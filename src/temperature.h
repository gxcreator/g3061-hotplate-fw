#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#define TEMPERATURE_INVALID 0xffffu

/* Returns rounded degrees C (0-400), or TEMPERATURE_INVALID. */
unsigned int temperature_from_adc(unsigned int adc);

#endif
