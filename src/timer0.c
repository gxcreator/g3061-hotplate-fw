#include "config.h"
#include "fw_sys.h"
#include "fw_tim.h"
#include "timer0.h"

#define TIMER0_COUNTS ((__SYSCLOCK + 500UL) / 1000UL)
#define TIMER0_RELOAD (65536UL - TIMER0_COUNTS)

#if TIMER0_COUNTS < 1 || TIMER0_COUNTS > 65536UL
#error Timer0 1 ms period must fit the 16-bit timer
#endif

void Timer0Init(void) // 1 ms, rounded to the nearest system clock.
{
    TIM_Timer0_Set1TMode(HAL_State_ON);
    TIM_Timer0_SetGateState(HAL_State_OFF);
    TIM_Timer0_SetFuncTimer;
    TIM_Timer0_SetMode(TIM_TimerMode_16BitAuto);
    TIM_Timer0_SetInitValue((uint8_t)(TIMER0_RELOAD >> 8), (uint8_t)TIMER0_RELOAD);
    SBIT_RESET(TF0);
    TIM_Timer0_SetRunState(HAL_State_ON);
    EXTI_Timer0_SetIntState(HAL_State_ON);
}

#ifdef TIMER_ENABLE_TIMER2
#define TIMER2_COUNTS ((__SYSCLOCK + 10000UL) / 20000UL)
#define TIMER2_RELOAD (65536UL - TIMER2_COUNTS)

#if TIMER2_COUNTS < 1 || TIMER2_COUNTS > 65536UL
#error Timer2 50 us period must fit the 16-bit timer
#endif

/* Starts Timer2 and enables its interrupt. Install a Timer2 ISR before calling. */
void Timer2Init(void) // 50 us, rounded to the nearest system clock.
{
    TIM_Timer2_Set1TMode(HAL_State_ON);
    TIM_Timer2_SetInitValue((uint8_t)(TIMER2_RELOAD >> 8), (uint8_t)TIMER2_RELOAD);
    TIM_Timer2_SetRunState(HAL_State_ON);
    EXTI_Timer2_SetIntState(HAL_State_ON);
}
#endif
