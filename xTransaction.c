//=================================================================================================================================
#include <string.h>
#include "xTransaction.h"
//=================================================================================================================================
xCommandT* xTransactionIdentify(xObject context, xCommandT commands[], uint8_t data[], uint16_t len)
{
  uint8_t i = 0;
  while(commands[i].Header)
  {
    if(len >= commands[i].HeaderLength)
    {
      if(memcmp(data, commands[i].Header, commands[i].HeaderLength) == 0)
      {
        ((xRequestBaseT*)context)->Context = &commands[i];
        switch(commands[i].Mode)
        {
          case TRANSACTION_MODE_OBJECT:
          data += commands[i].HeaderLength;
          len -= commands[i].HeaderLength;
          break;
        }		
        if (commands[i].Request) { commands[i].Request(context, data, len); }
        return &commands[i];
      }
    }
    i++;
  }
  return 0;
}
//=================================================================================================================================
int8_t xHeaderIdentify(xObject context, xObject header, uint8_t header_length, volatile uint8_t *data, uint16_t len){    
  if(header_length >= len)
  {
    return memcmp(header, (uint8_t*)data, header_length) == 0;
  }
  return -1;
}
//=================================================================================================================================

