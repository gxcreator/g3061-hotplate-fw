#include "board.h"
#include "ADC.h"
#include "temperature.h"
#include "voltage.h"
#include "measurements.h"
#include "realtime.h"

#if MEASUREMENT_SAMPLE_COUNT != 30 || SUPPLY_VOLTAGE_SCALE != 20 || \
    ADC_REFERENCE_MIN_MILLIVOLTS < 1000 || ADC_REFERENCE_MAX_MILLIVOLTS > 1400 || \
    ADC_REFERENCE_MIN_MILLIVOLTS > ADC_REFERENCE_MAX_MILLIVOLTS || \
    ADC_REFERENCE_FALLBACK_MILLIVOLTS < ADC_REFERENCE_MIN_MILLIVOLTS || \
    ADC_REFERENCE_FALLBACK_MILLIVOLTS > ADC_REFERENCE_MAX_MILLIVOLTS
#error Recalculate fixed-point voltage bounds before changing measurement constants
#endif

/* Highest code a 12-bit ADC can return. */
#define ADC_MAX_COUNT 4095u

/* The bandgap reads BGV_mV * 4096 / Vcc, so its count falls as the rail rises.
 * Retain the existing ADC acceptance window; its physical rail range depends
 * on calibration. It also bounds the voltage product inside uint32_t. */
#define REFERENCE_MIN_COUNT 800u
#define REFERENCE_MAX_COUNT 1900u

/* Cached once at startup; Vcc in 0.1 mV units is this over the bandgap count. */
static uint32_t vref_adc_scaled;

/* Four digits on the display. */
#define VOLTAGE_MAX_CENTIVOLTS 9990u

/* Each accumulator holds MEASUREMENT_SAMPLE_COUNT times its running mean.
 * Peaks: temperature 30*360, reference 30*1900, supply 30*4095. */
static uint32_t temperature_sum, reference_sum, supply_sum;
static uint16_t voltage_centivolts;
static uint8_t primed;

/* The mean currently held in an accumulator. */
static uint16_t average_value(uint32_t sum) {
    return (uint16_t)((sum + MEASUREMENT_SAMPLE_COUNT / 2) / MEASUREMENT_SAMPLE_COUNT);
}

/* Running approximation of a MEASUREMENT_SAMPLE_COUNT sample mean: each call
 * takes one sample's worth out of the accumulator and puts the new reading in.
 * An exact moving average would need the oldest sample, which is precisely the
 * array this avoids. Removing the rounded mean rather than the truncated one
 * keeps a constant input parked at exactly N times itself.
 *
 * It responds more gently than a true 30-deep window: 63% of a step after 30
 * calls and 95% after 88, where a window would be complete after 30. */
static void average_add(uint32_t *sum, uint16_t sample) {
    *sum = *sum - average_value(*sum) + sample;
}

void measurements_init(uint16_t bgv_mv) {
    if (bgv_mv < ADC_REFERENCE_MIN_MILLIVOLTS || bgv_mv > ADC_REFERENCE_MAX_MILLIVOLTS)
        bgv_mv = ADC_REFERENCE_FALLBACK_MILLIVOLTS;
    vref_adc_scaled = (uint32_t)bgv_mv * 4096UL * 10UL;
}

uint8_t measurements_sample(void) {
    uint16_t reference, supply, raw_temperature, reference_mean, supply_mean;
    uint32_t vcc_tenth_mv, centivolts;

    reference = get_adc(vcc_channel);
    supply = get_adc(vol_channel);
    raw_temperature = get_adc(tem_channel);

    /* The shutdown test uses the raw reading. */
    if (reference < REFERENCE_MIN_COUNT || reference > REFERENCE_MAX_COUNT ||
        supply > ADC_MAX_COUNT) {
        realtime_fault();
        return 0;
    }

    /* Prime from the first good reading instead of ramping up from zero. */
    if (!primed) {
        temperature_sum =
            (uint32_t)temperature_from_adc(raw_temperature) * MEASUREMENT_SAMPLE_COUNT;
        reference_sum = (uint32_t)reference * MEASUREMENT_SAMPLE_COUNT;
        supply_sum = (uint32_t)supply * MEASUREMENT_SAMPLE_COUNT;
        primed = 1;
    } else {
        average_add(&temperature_sum, temperature_from_adc(raw_temperature));
        average_add(&reference_sum, reference);
        average_add(&supply_sum, supply);
    }

    /* Averaging converted degrees rather than ADC codes is deliberate: the
     * whole-degree quantization dithers out across samples, so the mean tracks
     * the unrounded interpolation, which one conversion cannot. */

    reference_mean = average_value(reference_sum);
    supply_mean = average_value(supply_sum);

    /* Measure the rail against the calibrated bandgap, then scale the divider
     * reading by it. Taking the means first keeps the product
     * at most 71680 * 4095 = 293529600, inside uint32_t without splitting. */
    vcc_tenth_mv = (vref_adc_scaled + reference_mean / 2) / reference_mean;
    centivolts = (vcc_tenth_mv * supply_mean + SUPPLY_VOLTAGE_DIVISOR / 2) / SUPPLY_VOLTAGE_DIVISOR;

    voltage_centivolts =
        centivolts > VOLTAGE_MAX_CENTIVOLTS ? VOLTAGE_MAX_CENTIVOLTS : (uint16_t)centivolts;

    realtime_sample();
    return 1;
}

uint16_t measurements_temperature_sum(void) {
    return (uint16_t)temperature_sum;
}

uint16_t measurements_temperature(void) {
    return average_value(temperature_sum);
}

uint16_t measurements_voltage_centivolts(void) {
    return voltage_centivolts;
}
