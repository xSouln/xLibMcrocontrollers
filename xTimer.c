/*
 * Timers.c
 *
 * Created: 12.03.2020 18:33:54
 *  Author: rekuts
 */
//=================================================================================================================================
#include "xTimer.h"
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
inline void xTimerHandler(){
  Timer.Events.Time1ms = true;
  if(++Timer.Counters.Time10ms == 10){ Timer.Counters.Time10ms = 0; Timer.Events.Time10ms = true;
    if(++Timer.Counters.Time100ms == 10){ Timer.Counters.Time100ms = 0; Timer.Events.Time100ms = true;
      if(++Timer.Counters.Time1000ms == 10){ Timer.Counters.Time1000ms = 0; Timer.Events.Time1000ms = true; }
    }
  }
}
//=================================================================================================================================
inline void xTimerDecrement(xTimerT* timer)
{
  xListElementT* element = timer->Tasks.Head;
  //timer->Handler.Decrement = true;
  
  while(element){
    xTimerTaskT* task = element->Value;    
    if(task->Retention && task->State.Enable){ task->Retention--; }
    element = element->Next;
  }
  
  //timer->Handler.Decrement = false;
}
//=================================================================================================================================
inline void xTimer(xTimerT* timer)
{
  xListElementT* element = timer->Tasks.Head;
  //timer->Handler.Update = true;
  
  while(element)
  {
    xTimerTaskT* task = element->Value;
    
    if(task->Action && !task->Retention)
    {
      task->Action(timer, task);
      
      if(task->Period)
      {
        task->Retention = task->Period;
      }      
      else
      {
        element = xListRemoveElement(&timer->Tasks, element);
        free(task);
        goto end_while;
      }
    }
    element = element->Next;
  end_while:;
  }
}
//=================================================================================================================================
inline void xTimerDispose(xTimerT* timer)
{
  xListElementT* element = timer->Tasks.Head;
  xListElementT* next;
  
  while(element)
  {
    next = element->Next;
    free(element->Value);
    free(element);
    element = next;
    timer->Tasks.Count--;
  }
}
//=================================================================================================================================
xTimerTaskT* xTimerAdd(xTimerT* timer, xTimerAction action, uint32_t retention, uint32_t period){
  //timer->Handler.Add = true;
  
  xTimerTaskT* task = calloc(1, sizeof(xTimerTaskT));
  if(task)
  {
    task->Retention = retention;
    task->Period = period;
    task->Action = action;
    xListAdd(&timer->Tasks, task);
  }
  //timer->Handler.Add = false;
  return task;
}
//=================================================================================================================================