#ifndef PID_H
#define PID_H
#include <stdint.h>
void pid_reset(void);
/* Error -400..400 C, integer target minus measured temperature;
 * gains 0..1000. Returns duty 0..1000. */
uint16_t pid_step(int16_t error, uint16_t kp, uint16_t ki, uint16_t kd);
#endif
