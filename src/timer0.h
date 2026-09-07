#ifndef __TIMER0_H__
#define __TIMER0_H__

void Timer0Init(void); // 1ms@33.1776MHz
#ifdef TIMER_ENABLE_TIMER2
/* Default-off initializer only; no Timer2 ISR is supplied. Install one before calling. */
void Timer2Init(void); // 50us@33.1776MHz
#endif
#endif
