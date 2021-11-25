/*
 * Bootloader.h
 *
 *  Created on: Dec 17, 2020
 *      Author: rekuts
 */

#ifndef BOOTLOADER_STM32_H_
#define BOOTLOADER_STM32_H_
//=================================================================================================================================
#include "xType.h"
#include "xPort.h"//stm32f1xx_hal_flash_ex
#include "xFlash.h"
#include "BootTypes.h"
//=================================================================================================================================
static char BOOT_FIRMWARE_VERSION[] = "boot:1.0.0";
//=================================================================================================================================
typedef void (*AppFuncT)();
//=================================================================================================================================
typedef struct RequestWriteT
{
  uint32_t StartAddress;
  uint16_t DataSize;
  uint16_t Action;
} RequestWriteT;
//=================================================================================================================================
typedef struct RequestReadT
{
  uint32_t StartAddress;
  uint16_t DataSize;
  uint16_t Action;
} RequestReadT;
//=================================================================================================================================
typedef struct RequestEraseT
{
  uint32_t StartAddress;
  uint32_t EndAddress;
  uint32_t Action;
} RequestEraseT;
//=================================================================================================================================
typedef struct RequestCrcT
{
  uint32_t StartAddress;
  uint32_t EndAddress;
  uint32_t Action;
} RequestCrcT;
//=================================================================================================================================
typedef struct FirmwareInfoT
{
  uint32_t StartAddress;
  uint32_t EndAddress;
  uint32_t Content;
  
  union
  {
    struct
    {
      uint16_t BootEnable : 1;
    };
    uint16_t Value;
  }Requests;
  
  uint16_t Crc;
} FirmwareInfoT;
//=================================================================================================================================
typedef struct AppInfoT
{
  uint32_t BootStartAddress;
  uint32_t BootEndAddress;
  
  uint32_t AppStartAddress;
  uint32_t AppEndAddress;
  
  union
  {
    struct
    {
      uint16_t BootIsEnable : 1;
      uint16_t Reset : 1;
      uint16_t JumpToMain : 1;
      uint16_t JumpToBoot : 1;
      
      uint16_t AppCrcError : 1;
      uint16_t AppErrorStartAddress : 1;
      uint16_t AppErrorDiscrepancyAddress : 1;
    };
    uint16_t Value;
  }Status;
  
  uint16_t Crc;
} AppInfoT;
//=================================================================================================================================
typedef struct BootloaderT
{
  FirmwareInfoT FirmwareInfo;
  AppInfoT AppInfo;
  
} BootloaderT;
//=================================================================================================================================
extern BootloaderT Bootloader;
//=================================================================================================================================
int16_t ActionTryWrite(xObject context, RequestWriteT* request, uint16_t object_size);
int16_t ActionTryErase(xObject context, RequestEraseT* request, uint16_t object_size);
int16_t ActionTryJumpToMain(xObject context);
int16_t ActionTryJumpToBoot(xObject context);
int16_t ActionTryReset(xObject context);
int16_t ActionTryUpdateInfo(xObject context);
int16_t ActionTryReset(xObject context);

int16_t ActionSetLockState(xObject context, uint8_t* request);

int16_t BootloaderSetFirmwareInfo(FirmwareInfoT* info);
//=================================================================================================================================
#endif /* BOOTLOADER_STM32_H_ */
