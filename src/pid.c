#include "pid.h"

static int16_t integral, previous;

void pid_reset(void) {
    integral = previous = 0;
}

uint16_t pid_step(int16_t error, uint16_t kp, uint16_t ki, uint16_t kd) {
    int32_t p, in, d, output;
    if (error > -10 && error < 10)
        integral += error;
    if (integral > 500)
        integral = 500;
    if (integral < -500)
        integral = -500;
    /* With 0..400 C and gains <=1000, products and their sum are bounded
     * by 1,700,000 in magnitude, including a full-scale derivative reversal. */
    p = (int32_t)kp * error;
    in = (int32_t)ki * integral;
    d = (int32_t)kd * (error - previous);
    /* Retain the original positive term limits without corrupting raw error
     * history or accidentally assigning the derivative limit to integral. */
    if (p > 1000)
        p = 1000;
    if (in > 1000) {
        integral = 1000 / ki;
        in = (int32_t)ki * integral;
    }
    if (d > 1000)
        d = 1000;
    output = p + in + d;
    previous = error;
    if (output < 0)
        return 0;
    if (output > 1000)
        return 1000;
    return (uint16_t)output;
}
