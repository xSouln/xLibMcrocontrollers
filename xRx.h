//=================================================================================================================================
#ifndef X_RX_RECIVER_H
#define X_RX_RECIVER_H
//=================================================================================================================================
#include <stdint.h>
#include <stdbool.h>
#include "xType.h"
#include "xThread.h"
//=================================================================================================================================
#define xRX_SET_MASK_SIZE (size)(~(0xffff << size))
enum RX_RESULT{
  RX_STORAGE,
  RX_RESET,
};
//=================================================================================================================================
typedef struct { uint16_t size; uint8_t* ptr; } xRxObjectT;
//=================================================================================================================================
typedef int (*xRxEndLineEvent)(uint8_t* object, uint16_t size);
//=================================================================================================================================
typedef struct {
  uint16_t Storage : 1;
  uint16_t BufLoaded : 1;
  uint16_t ReceiveComlite : 1;
  uint16_t EndLineControl : 1;
}xRxStateT;
//=================================================================================================================================
typedef struct{
  uint16_t Len;
  uint16_t TotalIndex;
  uint16_t HandlerIndex;
  uint16_t SizeMask;
  volatile uint16_t ReceiveDelay;
  uint8_t *Buf;
}xRxCircleReceiverT;
//=================================================================================================================================
typedef struct{
  uint16_t Len;
  uint16_t BytesCount;
  uint8_t* Object;
  xRxEndLineEvent EndLineCallback;
}xRxObjectReceiverT;
//=================================================================================================================================
typedef struct xRxType{
    volatile xRxStateT State;
    xRxCircleReceiverT CircleReceiver;
    xRxObjectReceiverT ObjectReceiver;
}xRxT;
//=================================================================================================================================
//void xRxCircleAdd(xRxT* xRX, uint8_t Byte);
void xRxAdd(xRxT *rx, uint8_t *data, uint16_t data_size);
void xRxUpdate(xRxT* rx);
void xRxClear(xRxT* rx);
//=================================================================================================================================
#define xRxCircleAdd(xRX, byte)\
  xRX.CircleReceiver.Buf[xRX.CircleReceiver.TotalIndex] = byte;\
  xRX.CircleReceiver.TotalIndex++;\
  xRX.CircleReceiver.TotalIndex &= xRX.CircleReceiver.SizeMask
//=================================================================================================================================
#endif
