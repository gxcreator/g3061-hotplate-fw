#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H
#include <stdint.h>

#define MEASUREMENT_SAMPLE_COUNT 30

/* Call once before sampling with the factory BGV in mV. */
void measurements_init(uint16_t bgv_mv);
uint8_t measurements_sample(void);
/* Latest successful single reading in whole degrees C, shared by control and UI. */
uint16_t measurements_temperature(void);
/* Display-only centivolts, rounded to nearest and saturated at 9990 (99.9 V). */
uint16_t measurements_voltage_centivolts(void);
#endif
