#ifndef PID_H
#define PID_H
#include <stdint.h>
void pid_reset(void);
/* Temperature/target 0..400 C; gains 0..1000. Returns duty 0..1000. */
uint16_t pid_step(uint16_t target, float temperature, uint16_t kp, uint16_t ki, uint16_t kd);
#endif
