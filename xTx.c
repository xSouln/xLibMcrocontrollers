//=================================================================================================================================
#include <string.h>
#include "xTx.h"
//=================================================================================================================================
void xTxAdd(xTxT *Tx, xObject obj, uint16_t obj_size){
  uint8_t *ptr = (uint8_t*)obj;
  while(obj_size){
    Tx->Out.ptr[Tx->State.TotalIndex] = *ptr++;
    Tx->State.TotalIndex++;
    Tx->State.TotalIndex &= Tx->State.SizeMask;
    obj_size--;
  }
}
//=================================================================================================================================
void xTxPutByte(xTxT *Tx, uint8_t byte){
  Tx->Out.ptr[Tx->State.TotalIndex] = byte;
  Tx->State.TotalIndex++;
  Tx->State.TotalIndex &= Tx->State.SizeMask;
}
//=================================================================================================================================
