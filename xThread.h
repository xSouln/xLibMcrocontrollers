/*
 * xThread.h
 *
 * Created: 29.05.2019 9:35:06
 *  Author: rekuts
 */ 
#ifndef XTHREAD_H_
#define XTHREAD_H_
//=================================================================================================================================
#include <stdlib.h>
#include <string.h>
#include "xType.h"
//=================================================================================================================================
typedef struct { xEvt Func; xObject Object; uint16_t Size; } xThreadObjectT;
//=================================================================================================================================
typedef struct xThreadOptionType{
  uint8_t Count;
  uint8_t TotalIndex;
  uint8_t MaxCount;
  uint8_t HandlerIndex;
}xThreadOptionT;
//=================================================================================================================================
typedef union xThreadStateType{
  struct{
    uint8_t Update : 1;
    uint8_t Pause : 1;
    uint8_t IsAdd : 1;
  };
  uint8_t State;
} xThreadStateT;
//=================================================================================================================================
typedef struct xThreadType{
  xThreadStateT State;
  xThreadOptionT Option;
  
  void (*Activate)();
  xThreadObjectT *Lines;  
}xThreadT;
//=================================================================================================================================
void xThread(xThreadT *Thread);
int8_t xThreadAdd(xThreadT *Thread, xEvt Func, xObject Object);
//=================================================================================================================================
#endif /* XTHREAD_H_ */
