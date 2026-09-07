#ifndef REALTIME_H
#define REALTIME_H
#include <stdint.h>
#define REALTIME_PID 1
#define REALTIME_GRAPH 2
void realtime_tick(void);
uint8_t realtime_take(void);
void realtime_enable(uint8_t enabled);
uint8_t realtime_enabled(void);
void realtime_fault(void);
uint8_t realtime_faulted(void);
void realtime_pause(void);
void realtime_resume(void);
void realtime_sample(void);
/* After a successful sample, the foreground must reset PID if requested,
 * then publish only the result computed from that sample. Stale ISR ticks
 * invalidate publication even if they interrupt the PID calculation. */
uint8_t realtime_needs_reset(void);
void realtime_publish(uint16_t duty);
uint16_t realtime_duty(void);
#endif
