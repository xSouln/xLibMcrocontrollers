/*
 * XTRANSACTION_H_.h
 *
 * Created: 28.09.2021 13:42:04
 *  Author: rekuts
 */
#ifndef XTRANSACTION_H_
#define XTRANSACTION_H_
//=================================================================================================================================
#include <stdint.h>
#include <stdbool.h>
#include "xType.h"
#include "xTx.h"
//=================================================================================================================================
typedef enum { XBASE_MODE_OBJECT, XBASE_MODE_CONTENT } XCBASE_MODE_ENUM;
//=================================================================================================================================
typedef union{
  struct{
    uint16_t RequestUpdate;
    uint16_t GetResponse;
    uint16_t Error;
  };
  uint16_t Value;
}xTransactionHandlerT;
//=================================================================================================================================
typedef void (*xTransactionRequest)(xObject context, xObject Obj, uint16_t size);
typedef void (*xTransactionResponse)(xTxT *tx, xObject context, xObject request, uint16_t request_size, int16_t error);
typedef uint16_t (*xTransactionAction)(xObject context, xObject object, uint16_t object_size);
//=================================================================================================================================
typedef struct{
  xObject Header;
  uint8_t HeaderLength;
  uint8_t Mode;
  xTransactionRequest Request;
}xCommandT;
//=================================================================================================================================
int8_t xTransactionIdentify(xObject context, xCommandT commands[], uint8_t commands_count, uint8_t data[], uint16_t data_length);
//=================================================================================================================================
typedef struct{
  xTransactionHandlerT Handler;
  //char* Header;
  //uint16_t HeaderSize;
  uint16_t Id;
  xTransactionAction Action;
  xTransactionResponse Response;
  xContent Content;
}xTransactionT;

#define NEW_TRANSACTION(id, response, control, content)\
{\
  .Id = id,\
  .Response = (xTransactionResponse)response,\
  .Action = (xTransactionAction)control,\
  .Content = { .obj = &content, .size = sizeof(content) }\
}
//=================================================================================================================================
//=================================================================================================================================
#endif /* XTRANSACTION_H_ */
