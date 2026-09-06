#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>

#define TEMPERATURE_INVALID 0xffffu

/* Returns rounded degrees C (0-400), or TEMPERATURE_INVALID. */
uint16_t temperature_from_adc(uint16_t adc);

#endif
