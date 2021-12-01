/*
 * Responses.c
 *
 *  Created on: 28.09.2021
 *      Author: rekuts
 */
//=================================================================================================================================
#include "xTransaction.h"
#include "Bootloader_Responses.h"
#include "xTx.h"
#include "Bootloader.h"
#include "xFlash.h"
//=================================================================================================================================
#define VA_ARGS_SHIFT(P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,PN,...) PN
#define VA_ARGS_COUNT(...) VA_ARGS_SHIFT(-1,##__VA_ARGS__,9,8,7,6,5,4,3,2,1,0)

//#define CONTENT_PUT(arg_obj, arg_size) {   }
#define xRequestDef(name, size1, ...) \
xContent RequestContent_##name[VA_ARGS_COUNT(__VA_ARGS__)] = { { .obj = &#__VA_ARGS__, .size = sizeof(#__VA_ARGS__) } }; \
xObject RequestObjects_##name[VA_ARGS_COUNT(__VA_ARGS__)] = { &#__VA_ARGS__ }; \
uint8_t RequestObjectSize_##name[VA_ARGS_COUNT(__VA_ARGS__)] = { sizeof(#__VA_ARGS__) }; \
xRequestT Request_##name = { .Content = { 0 }, .Contents = RequestContent_##name }
//=================================================================================================================================
void BootloaderResponse_REQUEST_GET(xTxT *tx, xTransactionT *request, xObject request_obj, uint16_t request_obj_size, int16_t error)
{
  ResponseInfoT info = { .Key = request->Id, .Size = request->Content.size };  
  xTxAdd(tx, &info, sizeof(info));  
  xTxAdd(tx, request->Content.obj, request->Content.size);
}
//=================================================================================================================================
void BootloaderResponse_REQUEST_DEFAULT(xTxT *tx, xTransactionT *request, xObject request_obj, uint16_t request_obj_size, int16_t error)
{
  ResponseInfoT info = { .Key = request->Id, .Size = request->Content.size + sizeof(error) };  
  xTxAdd(tx, &info, sizeof(info));
  xTxAdd(tx, &error, sizeof(error));
  xTxAdd(tx, request->Content.obj, request->Content.size);
}
//=================================================================================================================================
const xTransactionT BootloaderRequests[] =
{
  NEW_TRANSACTION0(BOOT_GET_INFO, BootloaderResponse_REQUEST_GET, 0, Bootloader.FirmwareInfo),
  NEW_TRANSACTION0(BOOT_GET_APP_INFO, BootloaderResponse_REQUEST_GET, 0, Bootloader.AppInfo),
  NEW_TRANSACTION0(BOOT_GET_FIRMWARE, BootloaderResponse_REQUEST_GET, 0, BOOT_FIRMWARE_VERSION),
  NEW_TRANSACTION0(BOOT_GET_STATUS, BootloaderResponse_REQUEST_GET, 0, xFlash.Status),
  
  NEW_TRANSACTION0(BOOT_SET_FLASH_LOCK_STATE, BootloaderResponse_REQUEST_DEFAULT, ActionSetLockState, xFlash.Status),
  
  NEW_TRANSACTION0(BOOT_TRY_WRITE, BootloaderResponse_REQUEST_DEFAULT, ActionTryWrite, xFlash.Status),
  NEW_TRANSACTION0(BOOT_TRY_ERASE, BootloaderResponse_REQUEST_DEFAULT, ActionTryErase, xFlash.Status),
  NEW_TRANSACTION0(BOOT_TRY_JUMP_TO_MAIN, BootloaderResponse_REQUEST_DEFAULT, ActionTryJumpToMain, Bootloader.AppInfo),
  NEW_TRANSACTION0(BOOT_TRY_JUMP_TO_BOOT, BootloaderResponse_REQUEST_DEFAULT, ActionTryJumpToBoot, Bootloader.AppInfo),
  NEW_TRANSACTION0(BOOT_TRY_RESET, BootloaderResponse_REQUEST_DEFAULT, ActionTryReset, Bootloader.AppInfo),
  NEW_TRANSACTION0(BOOT_TRY_UPDATE_INFO, BootloaderResponse_REQUEST_DEFAULT, ActionTryUpdateInfo, Bootloader.FirmwareInfo),
  //NEW_TRANSACTION(TRY_READ_CRC, Response_REQUEST_DEFAULT, ActionReadInfo, Bootloader.Info),
  { .Id = -1 }
};
//=================================================================================================================================
