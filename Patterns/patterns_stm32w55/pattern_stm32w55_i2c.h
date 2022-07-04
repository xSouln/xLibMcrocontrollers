/*
 * pattern_stm32wb55_i2c.h
 *
 *  Created on: 17 мая 2022 г.
 *      Author: Souln
 */

#ifndef PATTERN_STM32WB55_I2C_H_
#define PATTERN_STM32WB55_I2C_H_
//==============================================================================
#include <stdint.h>
//==============================================================================
typedef union
{
   struct
   {
      /* 0x00000001 */ uint32_t PeripheralEnable : 1; //I2C_CR1_PE
      /* 0x00000002 */ uint32_t TX_InterruptEnable : 1; //I2C_CR1_TXIE
      /* 0x00000004 */ uint32_t RX_InterruptEnable : 1; //I2C_CR1_RXIE
      /* 0x00000008 */ uint32_t AddressMatchInterruptEnable : 1; //I2C_CR1_ADDRIE

      /* 0x00000010 */ uint32_t NACK_ReceivedInterruptEnable : 1; //I2C_CR1_NACKIE
      /* 0x00000020 */ uint32_t STOP_DetectionInterruptEnable : 1; //I2C_CR1_STOPIE
      /* 0x00000040 */ uint32_t TransferCompleteInterruptEnable : 1; //I2C_CR1_TCIE
      /* 0x00000080 */ uint32_t ErrorsInterruptEnable : 1; //I2C_CR1_ERRIE

      /* 0x00000100 */ uint32_t DigitalNoiseFilter : 4; //I2C_CR1_DNF

      /* 0x00001000 */ uint32_t AnalogNoiseFilterOff : 1; //I2C_CR1_ANFOFF
      /* 0x00002000 */ uint32_t SoftwareReset : 1; //I2C_CR1_SWRST
      /* 0x00004000 */ uint32_t DMA_TransmissionRequestsEnable : 1; //I2C_CR1_TXDMAEN
      /* 0x00008000 */ uint32_t DMA_ReceptionRequestsEnable : 1; //I2C_CR1_RXDMAEN

      /* 0x00010000 */ uint32_t SlaveByteControl : 1; //I2C_CR1_SBC
      /* 0x00020000 */ uint32_t ClockStretchingDisable : 1; //I2C_CR1_NOSTRETCH
      /* 0x00040000 */ uint32_t WakeupFromSTOP_Enable : 1; //I2C_CR1_WUPEN
      /* 0x00080000 */ uint32_t GeneralCallEnable : 1; //I2C_CR1_GCEN

      /* 0x00100000 */ uint32_t SMBusHostAddressEnable : 1; //I2C_CR1_SMBHEN
      /* 0x00200000 */ uint32_t SMBusDeviceDefaultAddressEnable : 1; //I2C_CR1_SMBDEN
      /* 0x00400000 */ uint32_t SMBusAlertEnable : 1; //I2C_CR1_ALERTEN
      /* 0x00800000 */ uint32_t PEC_Enable : 1; //I2C_CR1_PECEN
   };
   uint32_t Value;

} STM32_I2C_CR1_T; //
//==============================================================================
typedef union
{
   struct
   {
      /* 0x00000001 */ uint32_t SlaveAddress : 10; //I2C_CR2_SADD (master mode)

      /* 0x00000400 */ uint32_t TransferDirection : 1; //I2C_CR2_RD_WRN (master mode)
      /* 0x00000800 */ uint32_t AddressingMode10bit : 1; //I2C_CR2_ADD10 (master mode)

      /* 0x00001000 */ uint32_t AddressHeaderOnlyReadDirection10bit : 1; //I2C_CR2_HEAD10R
      /* 0x00002000 */ uint32_t START_Generation : 1; //I2C_CR2_START
      /* 0x00004000 */ uint32_t STOP_Generation : 1; //I2C_CR2_STOP (master mode)
      /* 0x00008000 */ uint32_t NACK_Generation  : 1; //I2C_CR2_NACK (slave mode)

      /* 0x00010000 */ uint32_t NumberOfBytes : 8; //I2C_CR2_NBYTES

      /* 0x01000000 */ uint32_t NBYTES_ReloadMode : 1; //I2C_CR2_RELOAD
      /* 0x02000000 */ uint32_t AutomaticEndMode : 1; //I2C_CR2_AUTOEND (master mode)
      /* 0x04000000 */ uint32_t PacketErrorCheckingByte : 1; //I2C_CR2_PECBYTE
   };
   uint32_t Value;

} STM32_I2C_CR2_T; //
//==============================================================================
typedef union
{
   struct
   {
      /* 0x00000001 */ uint32_t Interface  : 10; //I2C_OAR1_OA1

      /* 0x00000400 */ uint32_t Mode10bit : 1; //I2C_OAR1_OA1MODE
      /* 0x00000800 */ uint32_t Enable : 1; //I2C_OAR1_OA1EN
   };
   uint32_t zBits;

} STM32_I2C_OAR1_T; //
//==============================================================================
typedef union
{
   struct
   {
      /* 0x00000001 */ uint32_t Bit0 : 1; //
      /* 0x00000002 */ uint32_t Interface : 7; //I2C_OAR2_OA2
   };
   uint32_t Value;

} STM32_I2C_OAR2_T; //
//==============================================================================
typedef union
{
   struct
   {
      /* 0x00000001 */ uint32_t TxEmpty : 1; //I2C_ISR_TXE
      /* 0x00000002 */ uint32_t TransmitInterrupt : 1; //I2C_ISR_TXIS
      /* 0x00000004 */ uint32_t RxNotEmpty : 1; //I2C_ISR_RXNE
      /* 0x00000008 */ uint32_t AddressMatched : 1; //I2C_ISR_ADDR (slave mode)

      /* 0x00000010 */ uint32_t NACK_Received : 1; //I2C_ISR_NACKF
      /* 0x00000020 */ uint32_t STOP_Detection : 1; //I2C_ISR_STOPF
      /* 0x00000040 */ uint32_t TransferComplete : 1; //I2C_ISR_TC (master mode)
      /* 0x00000080 */ uint32_t TransferCompleteReload : 1; //I2C_ISR_TCR

      /* 0x00000100 */ uint32_t BusError : 1; //I2C_ISR_BERR
      /* 0x00000200 */ uint32_t ArbitrationLost : 1; //I2C_ISR_ARLO
      /* 0x00000400 */ uint32_t OverrunOrUnderrun : 1; //I2C_ISR_OVR
      /* 0x00000800 */ uint32_t PEC_ErrorInReception : 1; //I2C_ISR_PECERR

      /* 0x00001000 */ uint32_t TimeoutOrTlowDetection : 1; //I2C_ISR_TIMEOUT
      /* 0x00002000 */ uint32_t SMBusAlert : 1; //I2C_ISR_ALERT
      /* 0x00004000 */ uint32_t Bit14 : 1; //
      /* 0x00008000 */ uint32_t BusBusy : 1; //I2C_ISR_BUSY

      /* 0x00010000 */ uint32_t TransferDirection : 1; //I2C_ISR_DIR (slave mode)
      /* 0x00020000 */ uint32_t AddressMatchCode : 7; //I2C_ISR_ADDCODE (slave mode)
   };
   uint32_t Value;

} STM32_I2C_ISR_T; //
//==============================================================================
typedef union
{
   struct
   {
      /* 0x00000001 */ uint32_t Bit0 : 1; //
      /* 0x00000002 */ uint32_t Bit1 : 1; //
      /* 0x00000004 */ uint32_t Bit2 : 1; //
      /* 0x00000008 */ uint32_t AddressMatched : 1; //I2C_ICR_ADDRCF

      /* 0x00000010 */ uint32_t NACK_Received : 1; //I2C_ICR_NACKCF
      /* 0x00000020 */ uint32_t STOP_Detection : 1; //I2C_ICR_STOPCF
      /* 0x00000040 */ uint32_t Bit6 : 1; //
      /* 0x00000080 */ uint32_t Bit7 : 1; //

      /* 0x00000100 */ uint32_t BusError : 1; //I2C_ICR_BERRCF
      /* 0x00000200 */ uint32_t ArbitrationLost : 1; //I2C_ICR_ARLOCF
      /* 0x00000400 */ uint32_t OverrunOrUnderrun : 1; //I2C_ICR_OVRCF
      /* 0x00000800 */ uint32_t PEC_ErrorInReception : 1; //I2C_ICR_PECCF

      /* 0x00001000 */ uint32_t TimeoutOrTlowDetection : 1; //I2C_ICR_TIMOUTCF
      /* 0x00002000 */ uint32_t SMBusAlert : 1; //I2C_ICR_ALERTCF
   };
   uint32_t Value;

} STM32_I2C_ICR_T; //
//==============================================================================
typedef union
{
	struct { volatile uint32_t Byte : 8; };

	struct { volatile uint32_t HalfWord : 16; };

	struct { volatile uint32_t fWord : 32; };

} STM32_I2C_RXDR_T; //
//==============================================================================
typedef union
{
	struct { volatile uint32_t Byte : 8; };

	struct { volatile uint32_t HalfWord : 16; };

	struct { volatile uint32_t fWord : 32; };

} STM32_I2C_TXDR_T; //
//==============================================================================
typedef struct
{
	volatile STM32_I2C_CR1_T Control1;
	volatile STM32_I2C_CR2_T Control2;

	volatile STM32_I2C_OAR1_T OwnAddress1;
	volatile STM32_I2C_OAR2_T OwnAddress2;

	volatile uint32_t TIMINGR;
	volatile uint32_t TIMEOUTR;

	volatile STM32_I2C_ISR_T Status;
	volatile STM32_I2C_ICR_T Clear;

	volatile uint32_t PECR;

	volatile STM32_I2C_RXDR_T RxData;
	volatile STM32_I2C_TXDR_T TxData;

} STM32_I2C_T; //I2C_TypeDef
//==============================================================================
#endif /* PATTERN_STM32WB55_I2C_H_ */
