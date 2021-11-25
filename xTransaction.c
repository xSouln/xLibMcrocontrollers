//=================================================================================================================================
#include <string.h>
#include "xTransaction.h"
//=================================================================================================================================
int8_t xTransactionIdentify(xObject context, xCommandT commands[], uint8_t commands_count, uint8_t data[], uint16_t data_length){    
  for(uint8_t i = 0; i < commands_count; i++)
  {
    if(data_length >= commands[i].HeaderLength)
    {
      if(memcmp(data, commands[i].Header, commands[i].HeaderLength) == 0)
      {        
        switch(commands[i].Mode)
        {
          case XBASE_MODE_OBJECT:
          data += commands[i].HeaderLength;
          data_length -= commands[i].HeaderLength;
          break;
        }		
        if (commands[i].Request) { commands[i].Request(context, data, data_length); }
        return i;
      }
    }
  }
  return -1;
}
//=================================================================================================================================
int8_t xHeaderIdentify(xObject context, xObject header, uint8_t header_length, volatile uint8_t *data, uint16_t data_length){    
  if(header_length >= data_length)
  {
    return memcmp(header, (uint8_t*)data, header_length) == 0;
  }
  return -1;
}
//=================================================================================================================================

