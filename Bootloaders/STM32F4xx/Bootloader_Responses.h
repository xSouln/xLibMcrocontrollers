/*
 * CK_Responses.h
 *
 *  Created on: 28.09.2021
 *      Author: rekuts
 */

#ifndef _BL_RESPONSES_H_
#define _BL_RESPONSES_H_
//==============================================================================
#include "xType.h"
#include "xTransaction.h"
//==============================================================================
static char BOOT_REQUEST_HEADER[] = "#RQBL:";
static char BOOT_RESPONSE_HEADER[] = "#RSBL:";
//==============================================================================
extern const xTransactionT Bootloader_Requests[];
//==============================================================================
#endif /* _BL_RESPONSES_H_ */
