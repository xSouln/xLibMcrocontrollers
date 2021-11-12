/*
 * xThread.c
 *
 * Created: 29.05.2019 9:32:03
 *  Author: rekuts
 */ 
#include "xThread.h"
//=================================================================================================================================
void xThread(xThreadT *Thread){
  if(!Thread->State.IsAdd){
    Thread->State.Update = true;
    if(Thread->Option.Count && !Thread->State.Pause){
      if(Thread->Lines[Thread->Option.HandlerIndex].Func) { Thread->Lines[Thread->Option.HandlerIndex].Func(Thread->Lines[Thread->Option.HandlerIndex].Object); }
      Thread->Lines[Thread->Option.HandlerIndex].Func = 0;
      if(++Thread->Option.HandlerIndex == Thread->Option.MaxCount) { Thread->Option.HandlerIndex = 0; }
      Thread->Option.Count--;
    }
    Thread->State.Update = false;
  }
}
//=================================================================================================================================
int8_t xThreadAdd(xThreadT *Thread, xEvt Func, xObject Object){
  xThreadObjectT ThreadLine = { .Func = Func, .Object = Object };
  int8_t id = -1;
  if(!Thread->State.IsAdd && Thread->Option.Count < Thread->Option.MaxCount){
    Thread->State.IsAdd = true;
    id = Thread->Option.TotalIndex;
    
    Thread->Lines[id] = ThreadLine;
    
    if(++Thread->Option.TotalIndex == Thread->Option.MaxCount) { Thread->Option.TotalIndex = 0; }
    Thread->Option.Count++;
    
    Thread->State.IsAdd = false;
    return true;
  }
  return id;
}
//=================================================================================================================================
