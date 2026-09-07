#ifndef VOLTAGE_H
#define VOLTAGE_H

#define SUPPLY_DIVIDER_UPPER1_OHMS 100000UL
#define SUPPLY_DIVIDER_UPPER2_OHMS 90000UL
#define SUPPLY_DIVIDER_LOWER_OHMS 10000UL

/* Input volts per volt at the tap. Value: 20. */
#define SUPPLY_VOLTAGE_SCALE                                                                       \
    ((SUPPLY_DIVIDER_UPPER1_OHMS + SUPPLY_DIVIDER_UPPER2_OHMS + SUPPLY_DIVIDER_LOWER_OHMS) /       \
     SUPPLY_DIVIDER_LOWER_OHMS)

/* Lower over lower is exactly 1, so the whole ratio is an integer whenever the
 * upper legs divide evenly. */
#if (SUPPLY_DIVIDER_UPPER1_OHMS + SUPPLY_DIVIDER_UPPER2_OHMS) % SUPPLY_DIVIDER_LOWER_OHMS
#error Supply divider must have an integer ratio
#endif

/* Turns (ADC count) * (Vcc in 0.1 mV) into centivolts. Value: 20480.
 * 409600 is 2^14 * 25, so only scales of 2^n times 1, 5 or 25 divide it
 * exactly. A scale of 11 would pass the check above and truncate here. */
#define SUPPLY_VOLTAGE_DIVISOR (409600UL / SUPPLY_VOLTAGE_SCALE)

#if 409600UL % SUPPLY_VOLTAGE_SCALE
#error Supply divider ratio must divide 409600 exactly
#endif

/* Nominal STC8H internal reference signal, measured on ADC channel 15.
 * Each chip has its own BGV value and the ISP downloader shows it at download
 * time. TOFO: read BGV from the chip */
#define ADC_REFERENCE_MILLIVOLTS 1190UL

#endif
