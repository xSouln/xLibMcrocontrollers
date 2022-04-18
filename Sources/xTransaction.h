/*
 * XTRANSACTION_H_.h
 *
 * Created: 28.09.2021 13:42:04
 *  Author: rekuts
 */
#ifndef XTRANSACTION_H_
#define XTRANSACTION_H_
//==============================================================================
#include <stdint.h>
#include <stdbool.h>
#include "xType.h"
#include "xTx.h"
#include "xRx.h"
//==============================================================================
typedef enum
{
  TRANSACTION_MODE_OBJECT,
  TRANSACTION_MODE_CONTENT
    
} TRANSACTION_MODE_E;
//==============================================================================
typedef union
{
  struct
  {
    uint16_t RequestUpdate;
    uint16_t GetResponse;
    uint16_t Error;
  };
  uint16_t Value;
}xTransactionHandlerT;
//==============================================================================
typedef void (*xTransactionResponse)(xObject context, xObject request, uint16_t request_size, int16_t error);
typedef uint16_t (*xTransactionAction)(xObject context, xObject object, uint16_t object_size);
typedef int (*xTransactionDataBuilder)(xObject context, xPacketDataAggregator aggregator, xObject object, uint16_t object_size);
//==============================================================================
typedef struct
{
  xObject Header;
  uint8_t HeaderLength;
  uint8_t Mode;
  xTransactionAction Request;
   
} xRequestT;
//==============================================================================
typedef struct
{
  uint16_t Description;
  uint16_t Id;
  xTransactionAction Action;
  xTransactionResponse Response;
  xTransactionDataBuilder Builder;
  xContent Content;
  
} xTransactionT;
//==============================================================================
xRequestT* xRequestIdentify(xObject context, xRequestT commands[], uint8_t data[], uint16_t len);
xTransactionT* xTransactionIdentify(xObject context, xTransactionT* transaction, uint16_t key);
//==============================================================================
#define NEW_TRANSACTION0(id, response, control, content)\
{\
  .Id = id,\
  .Response = (xTransactionResponse)response,\
  .Action = (xTransactionAction)control,\
  .Content = { .obj = &content, .size = sizeof(content) }\
}

#define NEW_TRANSACTION1(id, response, control)\
{\
  .Id = id,\
  .Response = (xTransactionResponse)response,\
  .Action = (xTransactionAction)control\
}

#define NEW_TRANSACTION2(id, response, control, content, content_size)\
{\
  .Id = id,\
  .Response = (xTransactionResponse)response,\
  .Action = (xTransactionAction)control,\
  .Content = { .obj = &content, .size = content_size }\
}

#define NEW_TRANSACTION3(id, response, builder)\
{\
  .Id = id,\
  .Response = (xTransactionResponse)response,\
  .Builder = (xTransactionDataBuilder)builder,\
}

#define NEW_COMMAND0(header, request, mode)\
{\
  .Header = (char*)header,\
  .HeaderLength = SIZE_STRING(header),\
  .Mode = mode,\
  .Request = (xTransactionAction)request\
}

#define NEW_COMMAND1(header, request)\
{\
  .Header = (char*)header,\
  .HeaderLength = SIZE_STRING(header),\
  .Request = (xTransactionAction)request\
}
//==============================================================================
#endif /* XTRANSACTION_H_ */
