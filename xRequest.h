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
typedef union{
  struct{
    uint16_t RequestUpdate;
    uint16_t GetResponse;
    uint16_t Error;
  };
  uint16_t Value;
}xRequestHandlerT;
//=================================================================================================================================
typedef void (*xEvtRequest)(xObject context, xTxT *tx, xObject request_obj, uint16_t request_obj_size, int16_t error);
typedef uint16_t (*xEvtControl)(xObject context, xObject object, uint16_t object_size);
//=================================================================================================================================
typedef struct{
  xEvt Control;
  xEvt Response;
}xResponseT;
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

#define NEW_REQUEST(id, response, control, content){ .Id = id, .Response = (xEvtRequest)response, .Control = (xEvtControl)control, .Content = { .obj = &content, .size = sizeof(content) } }
//=================================================================================================================================
//=================================================================================================================================
#endif /* XREQUESTS_H_ */
