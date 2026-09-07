#include "board.h"
#include "ADC.h"
#include "temperature.h"
#include "voltage.h"
#include "measurements.h"
#include "realtime.h"

static uint16_t temperatures[30], supplies[30];
static uint8_t count, index;
static float temperature;
static float voltage;

uint8_t measurements_sample(void) {
    uint8_t n;
    uint16_t reference, sample;
    uint32_t tsum = 0, vsum = 0;
    float vcc = 0;
    for (n = 0; n < 30; ++n) {
        reference = get_adc(vcc_channel);
        if (!reference || reference > 4095) {
            realtime_fault();
            return 0;
        }
        vcc += ADC_REFERENCE_VOLTS * 4096 / reference;
    }
    /* Read temperature last: a blocked reference conversion must not certify
     * an old temperature as fresh when the ADC eventually returns. */
    do {
        supplies[index] = get_adc(vol_channel);
        sample = temperature_from_adc(get_adc(tem_channel));
        if (sample == TEMPERATURE_INVALID || sample >= 360) {
            realtime_fault();
            return 0;
        }
        temperatures[index] = sample;
        if (count < 30)
            ++count;
        if (++index == 30)
            index = 0;
    } while (count < 30);
    for (n = 0; n < count; ++n) {
        tsum += temperatures[n];
        vsum += supplies[n];
    }
    temperature = (float)tsum / count;
    voltage = SUPPLY_VOLTAGE_SCALE * (vcc / 30) * ((float)vsum / (4096.0f * count));
    realtime_sample();
    return 1;
}
float measurements_temperature(void) {
    return temperature;
}
float measurements_voltage(void) {
    return voltage;
}
