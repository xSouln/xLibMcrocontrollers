//==============================================================================
#include <string.h>
#include "xTransaction.h"
//==============================================================================
xRequestT* xRequestIdentify(xObject context, xRequestT request[], uint8_t data[], uint16_t len)
{
  uint8_t i = 0;
  while(request[i].Header)
  {
    if(len >= request[i].HeaderLength)
    {
      if(memcmp(data, request[i].Header, request[i].HeaderLength) == 0)
      {
        data += request[i].HeaderLength;
        len -= request[i].HeaderLength;
        
        if (request[i].Request)
        {
          request[i].Request(context, data, len);
        }
        return &request[i];
      }
    }
    i++;
  }
  return 0;
}
//==============================================================================
xTransactionT* xTransactionIdentify(xObject context, xTransactionT* transaction, uint16_t key)
{
  while(transaction && transaction->Id != (uint16_t)-1)
  {
    if(transaction->Id == key)
    {
      return transaction;
    }
    transaction++;
  }
  
  return 0;
}
//==============================================================================
