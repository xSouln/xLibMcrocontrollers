/*
 * Timers.c
 *
 * Created: 12.03.2020 18:33:54
 *  Author: rekuts
 */
//=================================================================================================================================
#include "xTimers.h"
#include "tim.h"
//=================================================================================================================================
TimerT Timer;

TimStm32_T *xTimer1 = (TimStm32_T*)TIM1;
TimStm32_T *xTimer2 = (TimStm32_T*)TIM2;
TimStm32_T *xTimer3 = (TimStm32_T*)TIM3;
TimStm32_T *xTimer4 = (TimStm32_T*)TIM4;
/*
TimStm32_T *xTimer5 = (TimStm32_T*)TIM5;
TimStm32_T *xTimer6 = (TimStm32_T*)TIM6;
TimStm32_T *xTimer7 = (TimStm32_T*)TIM7;
TimStm32_T *xTimer8 = (TimStm32_T*)TIM8;
TimStm32_T *xTimer9 = (TimStm32_T*)TIM9;
TimStm32_T *xTimer10 = (TimStm32_T*)TIM10;
*/
//=================================================================================================================================