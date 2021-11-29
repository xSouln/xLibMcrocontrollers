/*
 * BootTypes.h
 *
 * Created: 16.05.2019 14:29:38
 *  Author: rekuts
 */ 
//==============================================================================
#ifndef BOOT_TYPES_H_
#define BOOT_TYPES_H_
//==============================================================================
#include <stdint.h>
#include <stdbool.h>
//==============================================================================
enum REQUESTS_BOOT
{
  BOOT_REQUESTS_START = 0,
    
  BOOT_GET_X = 100,
  BOOT_GET_FIRMWARE,
  BOOT_GET_INFO,
  BOOT_GET_APP_INFO,
  BOOT_GET_STATUS,
  BOOT_GET_HANDLER,
  
  BOOT_SET_X = 200,
  BOOT_SET_FLASH_LOCK_STATE,
  BOOT_SET_OPTIONS,
  BOOT_SET_HANDLER,
  
  BOOT_TRY_X = 300,
  BOOT_TRY_RESET,
  BOOT_TRY_ERASE,
  BOOT_TRY_WRITE,
  BOOT_TRY_READ,
  BOOT_TRY_JUMP_TO_BOOT,
  BOOT_TRY_JUMP_TO_MAIN,
  BOOT_TRY_UPDATE_INFO,
  BOOT_TRY_READ_CRC,
  
  BOOT_EVT_X = 400,
  BOOT_EVT_WRITE_COMPLITE,
  BOOT_EVT_READ_COMPLITE,
  
  BOOT_REQUESTS_END = 500
};
//==============================================================================
#define BOOT_START_ADDRESS      0x08000000
#define BOOT_END_ADDRESS        0x08004000

#define APP_START_ADDRESS       0x080E0000
#define APP_END_ADDRESS         0x080FFFFF
//==============================================================================
#endif /* BOOT_TYPES_H_ */
