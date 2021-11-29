/*
 * Bootloader.c
 *
 *  Created on: Dec 17, 2020
 *      Author: rekuts
 */
//==============================================================================
#include <string.h>
#include <stdlib.h>
#include "Bootloader.h"
#include "xTransaction.h"
//#include "stm32f1xx_hal_flash_ex.h"
extern void AppMain();
//==============================================================================
int16_t ActionTryWrite(xObject context, RequestWriteT* request, uint16_t object_size)
{
  if(!request){ return BOOT_ERROR_REQUEST; }
  if(request->StartAddress < BOOT_END_ADDRESS){ return BOOT_OUTSIDE; }
  if((request->StartAddress + request->DataSize) > APP_END_ADDRESS){ return BOOT_OUTSIDE; }
  if(object_size - sizeof(RequestWriteT) < request->DataSize){ return BOOT_ERROR_REQUEST; }
  
  uint8_t* data = (uint8_t*)request;
  data += sizeof(RequestWriteT);
  
  return xFlashWrite(request->StartAddress, data, request->DataSize, 100);
}
//==============================================================================
int16_t ActionTryRead(xObject context, RequestReadT* request, uint16_t object_size)
{  
  return BOOT_ACCEPT;
}
//==============================================================================
int16_t ActionTryErase(xObject context, RequestEraseT* request, uint16_t object_size)
{
  if(!request){ return BOOT_ERROR_REQUEST; }
  if(request->StartAddress < BOOT_END_ADDRESS){ return BOOT_OUTSIDE; }
  if(request->StartAddress > request->EndAddress){ return BOOT_ERROR_ACTION; }
  return xFlashErasePages(request->StartAddress, request->EndAddress, 2000);
}
//==============================================================================
int16_t ActionSetLockState(xObject context, uint8_t* request)
{
  if(!request){ return BOOT_ERROR_REQUEST; }
  
  return xFlashSetLock(*request > 0);
}
//==============================================================================
int16_t ActionTryJumpToMain(xObject context)
{
  if(!Bootloader.AppInfo.Status.BootIsEnable){ return BOOT_ERROR_RESOLUTION; }  
  Bootloader.AppInfo.Status.JumpToMain = true;
  
  return BOOT_ACCEPT;
}
//==============================================================================
int16_t ActionTryUpdateInfo(xObject context)
{
  xFlashRead(BOOT_END_ADDRESS, (volatile uint8_t*)&Bootloader.FirmwareInfo, sizeof(Bootloader.FirmwareInfo));
  
  Bootloader.AppInfo.Crc = xFlashGetCrc(Bootloader.FirmwareInfo.StartAddress, Bootloader.FirmwareInfo.EndAddress);
  Bootloader.AppInfo.Status.AppCrcError = Bootloader.AppInfo.Crc != Bootloader.FirmwareInfo.Crc;
  Bootloader.AppInfo.AppStartAddress = Bootloader.FirmwareInfo.StartAddress;
  Bootloader.AppInfo.AppEndAddress = Bootloader.FirmwareInfo.EndAddress;

  Bootloader.AppInfo.Status.AppErrorDiscrepancyAddress = APP_START_ADDRESS != Bootloader.FirmwareInfo.StartAddress;
  Bootloader.AppInfo.Status.AppErrorStartAddress = Bootloader.FirmwareInfo.StartAddress == -1;
  
  if(Bootloader.AppInfo.Status.AppCrcError) { return BOOT_ERROR_CRC; }
  if(Bootloader.AppInfo.AppStartAddress != APP_START_ADDRESS) { return BOOT_ERROR_ADDRESS; }
  return BOOT_ACCEPT;
}
//==============================================================================
int16_t ActionReadCrc(xObject context, RequestEraseT* request, uint16_t object_size)
{
  if(request->StartAddress > APP_END_ADDRESS){ return BOOT_OUTSIDE; }
  if(request->StartAddress > request->EndAddress){ return BOOT_ERROR_ACTION; }
  
  uint16_t crc = xFlashGetCrc(request->StartAddress, request->EndAddress);
  
  return BOOT_ACCEPT;
}
//==============================================================================
int16_t ActionTryReset(xObject context)
{
  Bootloader.AppInfo.Status.Reset = true;
  return BOOT_ACCEPT;
}
//==============================================================================
int16_t ActionTryJumpToBoot(xObject context)
{
  if(Bootloader.AppInfo.Status.BootIsEnable){ return BOOT_ERROR_RESOLUTION; }
  Bootloader.AppInfo.Status.JumpToBoot = true;
  
  xFlashSetLock(false);
  
  FirmwareInfoT FirmwareInfo;
  xFlashRead(BOOT_END_ADDRESS, (volatile uint8_t*)&FirmwareInfo, sizeof(FirmwareInfo));
  
  FirmwareInfo.Requests.BootEnable = true;  
  
  xFlashErasePages(BOOT_END_ADDRESS, BOOT_END_ADDRESS + 1, 1000);
  xFlashWrite(BOOT_END_ADDRESS, &FirmwareInfo, sizeof(FirmwareInfo), 100);
  
  return BOOT_ACCEPT;
}
//==============================================================================
int16_t BootloaderSetFirmwareInfo(FirmwareInfoT* info)
{
  if(!Bootloader.AppInfo.Status.BootIsEnable){ return BOOT_ERROR_RESOLUTION; }
  
  xFlashSetLock(false);
  xFlashErasePages(BOOT_END_ADDRESS, BOOT_END_ADDRESS + 1, 1000);
  xFlashWrite(BOOT_END_ADDRESS, info, sizeof(FirmwareInfoT), 100);
  xFlashSetLock(true);
  
  return BOOT_ACCEPT;
}
//==============================================================================
BootloaderT Bootloader =
{
  .AppInfo =
  {
    .BootStartAddress = BOOT_START_ADDRESS,
    .BootEndAddress = BOOT_END_ADDRESS,
    
    .AppStartAddress = APP_START_ADDRESS,
    .AppEndAddress = APP_END_ADDRESS
  },
};
//==============================================================================
