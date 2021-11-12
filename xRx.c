//=================================================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xRx.h"
//=================================================================================================================================
//=================================================================================================================================
void xRxUpdate(xRxT* rx){
  while(rx->CircleReceiver.TotalIndex != rx->CircleReceiver.HandlerIndex){    
    rx->ObjectReceiver.Object[rx->ObjectReceiver.BytesCount] = rx->CircleReceiver.Buf[rx->CircleReceiver.HandlerIndex];        
    rx->ObjectReceiver.BytesCount++;

    if(rx->ObjectReceiver.BytesCount >= rx->ObjectReceiver.Len){
      rx->ObjectReceiver.EndLineCallback(rx->ObjectReceiver.Object, rx->ObjectReceiver.BytesCount);
      rx->ObjectReceiver.BytesCount = 0;
    }
    else if(rx->CircleReceiver.Buf[rx->CircleReceiver.HandlerIndex] == '\r'){
      if(rx->ObjectReceiver.EndLineCallback(rx->ObjectReceiver.Object, rx->ObjectReceiver.BytesCount - 1)){ rx->ObjectReceiver.BytesCount = 0; }
    }
    
    rx->CircleReceiver.HandlerIndex++;
    rx->CircleReceiver.HandlerIndex &= rx->CircleReceiver.SizeMask;
  }
}
//=================================================================================================================================
void xRxAdd(xRxT* rx, uint8_t *data, uint16_t data_size){
  for(uint16_t i = 0; i < data_size; i++){
    rx->ObjectReceiver.Object[rx->ObjectReceiver.BytesCount] = data[i];
    rx->ObjectReceiver.BytesCount++;
    
    if(rx->ObjectReceiver.BytesCount >= rx->ObjectReceiver.Len){
      rx->ObjectReceiver.EndLineCallback(rx->ObjectReceiver.Object, rx->ObjectReceiver.BytesCount);
      rx->ObjectReceiver.BytesCount = 0;
    }    
    else if(data[i] == '\r'){
      if(rx->ObjectReceiver.EndLineCallback(rx->ObjectReceiver.Object, rx->ObjectReceiver.BytesCount - 1)) { rx->ObjectReceiver.BytesCount = 0; }
    }
  }
}
//=================================================================================================================================
void xRxClear(xRxT* rx){
  rx->CircleReceiver.TotalIndex = 0;
  rx->CircleReceiver.HandlerIndex = 0;
  rx->ObjectReceiver.BytesCount = 0;
}
//=================================================================================================================================
