#include "config.h"
#include "fw_tim.h"
#include "timer0.h"

void Timer0Init(void) // 1000us@33.1776MHz
{
    TIM_Timer0_Set1TMode(HAL_State_ON);
    TIM_Timer0_SetGateState(HAL_State_OFF);
    TIM_Timer0_SetFuncTimer;
    TIM_Timer0_SetMode(TIM_TimerMode_16BitAuto);
    TIM_Timer0_SetInitValue(0x7E, 0x66);
    SBIT_RESET(TF0);
    TIM_Timer0_SetRunState(HAL_State_ON);
    EXTI_Timer0_SetIntState(HAL_State_ON);
}

#ifdef TIMER_ENABLE_TIMER2
/* Starts Timer2 and enables its interrupt. Install a Timer2 ISR before calling. */
void Timer2Init(void) // 50us@33.1776MHz
{
    TIM_Timer2_Set1TMode(HAL_State_ON);
    TIM_Timer2_SetInitValue(0xF9, 0x85);
    TIM_Timer2_SetRunState(HAL_State_ON);
    EXTI_Timer2_SetIntState(HAL_State_ON);
}
#endif
