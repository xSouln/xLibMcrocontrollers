/*
 * XREQUESTS.h
 *
 * Created: 28.09.2021 13:42:04
 *  Author: rekuts
 */
#ifndef XREQUESTS_H_
#define XREQUESTS_H_
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
}xRequestHandlerT;
//=================================================================================================================================
typedef void (*xRequestReceiver)(xObject context, xObject Obj, uint16_t size);
typedef void (*xEvtRequest)(xTxT *tx, xObject context, xObject request, uint16_t request_size, int16_t error);
typedef uint16_t (*xEvtControl)(xObject context, xObject object, uint16_t object_size);
//=================================================================================================================================
typedef struct{
  xEvt Control;
  xEvt Response;
}xResponseT;
//=================================================================================================================================
typedef struct{
  xObject Header;
  uint8_t HeaderLength;
  uint8_t Mode;
  xRequestReceiver Receiver;
}xCommandT;
//=================================================================================================================================
int8_t xRequestIdentify(xObject context, xCommandT commands[], uint8_t commands_count, uint8_t data[], uint16_t data_length);
//=================================================================================================================================
typedef struct{
  xRequestHandlerT Handler;
  //char* Header;
  //uint16_t HeaderSize;
  uint16_t Id;
  xEvtControl Control;
  xEvtRequest Response;
  xContent Content;
}xRequestT;

#define NEW_REQUEST(id, response, control, content)\
{\
  .Id = id,\
  .Response = (xEvtRequest)response,\
  .Control = (xEvtControl)control,\
  .Content = { .obj = &content, .size = sizeof(content) }\
}
//=================================================================================================================================
//=================================================================================================================================
#endif /* XREQUESTS_H_ */
