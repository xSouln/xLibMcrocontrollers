/*
 * xPatterns.h
 *
 * Created: 16.05.2019 14:29:38
 *  Author: rekuts
 */ 
//==============================================================================
#ifndef X_PATTERNS_H_
#define X_PATTERNS_H_
//==============================================================================
#include <stdint.h>
#include <stdbool.h>
//==============================================================================
#ifdef STM32H743xx

#include "patterns_stm32h7xx/pattern_stm32h7xx_spi.h"
#include "patterns_stm32h7xx/pattern_stm32h7xx_timer.h"
#include "patterns_stm32h7xx/pattern_stm32h7xx_uart.h"
#include "patterns_stm32h7xx/pattern_stm32h7xx_dma.h"

#endif
//==============================================================================
#endif /* X_PATTERNS_H_ */
