#ifndef __TIMER0_H__
#define __TIMER0_H__

void Timer0Init(void); // 1 ms at the configured system clock.
#ifdef TIMER_ENABLE_TIMER2
/* Default-off initializer only; no Timer2 ISR is supplied. Install one before calling. */
void Timer2Init(void); // 50 us at the configured system clock.
#endif
#endif
