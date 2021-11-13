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

#define TX_BINDING(name, transmit_action)\
.State = { .SizeMask = name##_TX_CIRCLE_BUF_SIZE },\
.Packet = { .ptr = name##_TX_CIRCLE_BUF },\
.TransmitAction = transmit_action
//=================================================================================================================================
typedef struct { uint8_t* ptr; uint16_t size; } xPacketT;
//=================================================================================================================================
typedef bool (*TransmitActionT)(xPacketT *print);
//=================================================================================================================================
#define xTX_SET_MASK_SIZE (bits)(~(0xffff << bits))
//=================================================================================================================================
//=================================================================================================================================
typedef struct{
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

  xPacketT Packet;
  uint16_t Crc;
}xTxT;
//=================================================================================================================================
void xTxAdd(xTxT *Tx, xObject obj, uint16_t obj_size);
void xTxPutByte(xTxT *Tx, uint8_t byte);
xPacketT xTxGetPacket(xTxT *Tx);
//=================================================================================================================================
#define xTxSend(xTx, reg)\
  reg = xTx.Packet.ptr[xTx.State.HandlerIndex];\
  xTx.State.HandlerIndex++;\
  xTx.State.HandlerIndex &= xTx.State.SizeMask
//=================================================================================================================================
#endif
