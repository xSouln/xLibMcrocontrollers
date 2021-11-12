//=================================================================================================================================
#ifndef X_TX_H
#define X_TX_H
//=================================================================================================================================
#include <stdint.h>
#include <stdbool.h>
#include "xThread.h"
//=================================================================================================================================
#define TX_BUF_INIT(name)\
uint8_t name##_TX_CIRCLE_BUF[name##_TX_CIRCLE_BUF_SIZE + 1]

#define TX_BINDING(name)\
.State = { .SizeMask = name##_TX_CIRCLE_BUF_SIZE },\
.Out = { .ptr = name##_TX_CIRCLE_BUF }
//=================================================================================================================================
typedef struct { uint16_t size; uint8_t* ptr; } xPrintT;
//=================================================================================================================================
typedef bool (*TransmitActionT)(xPrintT *print);
//=================================================================================================================================
#define xTX_SET_MASK_SIZE (bits)(~(0xffff << bits))
//=================================================================================================================================
//=================================================================================================================================
typedef struct{
    //uint16_t BufSize;
    volatile uint16_t TotalIndex;
    uint16_t HandlerIndex;
    uint16_t UpdateDelay;
    volatile uint16_t TxDisableDelay;
    uint16_t SizeMask;
}xTxStateT;
//=================================================================================================================================
typedef union{
  struct{
    uint16_t Transmitted : 1;
    uint16_t IsAdd : 1;
    uint16_t IsUpdate : 1;
    uint16_t TransferComplite : 1;
    uint16_t TxBufFull : 1;
    uint16_t Lock : 1;
  };
  uint16_t Value;
}xTxHandlerT;
//=================================================================================================================================
typedef struct{
  volatile xTxHandlerT Handler;
  xTxStateT State;
  TransmitActionT TransmitAction;

  xPrintT Out;
  uint16_t Crc;
}xTxT;
//=================================================================================================================================
void xTxAdd(xTxT *Tx, xObject obj, uint16_t obj_size);
void xTxPutByte(xTxT *Tx, uint8_t byte);
//=================================================================================================================================
#define xTxSend(xTx, reg)\
  reg = xTx.Out.ptr[xTx.State.HandlerIndex];\
  xTx.State.HandlerIndex++;\
  xTx.State.HandlerIndex &= xTx.State.SizeMask
//=================================================================================================================================
#endif
