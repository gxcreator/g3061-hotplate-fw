#include "temperature.h"

/* PT100 to ground, 500 ohm pull-up to the ADC reference supply.
 * Ratiometric divider, so R/R0 = 5*adc / (4096 - adc).
 * IEC 60751 positive branch: R/R0 = 1 + A*t + B*t^2,
 * A = 0.0039083, B = -0.0000005775.
 *
 * Curve sampled every 128 ADC codes, rounded to whole degrees:
 *
 *     adc     R/R0     true t   stored
 *      682  0.99883    -0.300        0
 *      810  1.23250    60.021       60
 *      938  1.48512   126.489      126
 *     1066  1.75908   200.140      200
 *     1194  2.05720   282.275      282
 *     1322  2.38284   374.551      375
 *     1450  2.73998   479.123      479
 *
 * Curve is convex, so interpolation reads high between nodes.
 * Error is -0.9 to +2.4 C over the whole range.
 *
 * The last node is one code past the valid range. It exists only so the
 * top interval is a full 128 wide; it is never used as a base index.
 */

#define ADC_FIRST_NODE 682u  /* first sampled code, 0 C */
#define ADC_LAST_VALID 1449u /* last code that still leaves a node above it */
#define NODE_SPACING 128u    /* ADC codes between table entries */

static const __code uint16_t temperature_degrees[7] = {
    0, 60, 126, 200, 282, 375, 479,
};

uint16_t temperature_from_adc(uint16_t adc) {
    uint16_t offset, index, fraction, delta, temp;

    /* Reject out of range. An open sensor reads near 4095, a shorted one 0. */
    if (adc < ADC_FIRST_NODE || adc > ADC_LAST_VALID) {
        return TEMPERATURE_INVALID;
    }

    /* Locate the reading: which interval, and how far into it. */
    offset = adc - ADC_FIRST_NODE;    /* 0..767  */
    index = offset / NODE_SPACING;    /* 0..5    */
    fraction = offset % NODE_SPACING; /* 0..127  */

    /* Straight-line interpolation between the two nodes.
     * Adding half the divisor rounds to nearest instead of down.
     * Largest delta is 104, so the numerator stays under 13272. */
    temp = temperature_degrees[index];
    delta = temperature_degrees[index + 1u] - temp;
    temp += (delta * fraction + NODE_SPACING / 2u) / NODE_SPACING;

    return temp;
}
