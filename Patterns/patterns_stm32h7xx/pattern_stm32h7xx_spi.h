/*
 * pattern_stm32h7xx_spi.h
 *
 * Created: 16.05.2019 14:29:38
 *  Author: rekuts
 */ 
//==============================================================================
#ifndef PATTERN_STM32H7XX_SPI_H_
#define PATTERN_STM32H7XX_SPI_H_
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t SpiEnable: 1; //SPI_CR1_SPE: Serial Peripheral Enable
    /* 0x00000002 */ uint32_t Free: 7; //Free
    
    /* 0x00000100 */ uint32_t SUSP_ReceiveMode: 1; //SPI_CR1_MASRX: Master automatic SUSP in Receive mode
    /* 0x00000200 */ uint32_t MasterTransferStart: 1; //SPI_CR1_CSTART: Master transfer start
    /* 0x00000400 */ uint32_t MasterSuspendRequest: 1; //SPI_CR1_CSUSP: Master SUSPend request
    /* 0x00000800 */ uint32_t HalfDuplexModeDirection: 1; //SPI_CR1_HDDIR - Rx/Tx direction at Half-duplex mode
	
    /* 0x00001000 */ uint32_t InternalNssLevel: 2; //SPI_CR1_SSI: Internal SS signal input level/32-bit CRC polynomial configuration
    /* 0x00004000 */ uint32_t CrcRxPatternControl: 1; //SPI_CR1_RCRCINI: CRC init pattern control for receiver
    /* 0x00008000 */ uint32_t CrcTxPatternControl: 1; //SPI_CR1_TCRCINI: CRC init pattern control for transmitter
	
    /* 0x00010000 */ uint32_t AF_Configuration: 1; //SPI_CR1_IOLOCK: Locking the AF configuration of associated IOs
  };
  uint32_t Value;
}SpiCR1_T;
//==============================================================================
typedef union{
  struct{
    /* 0x0000FFFF */ uint32_t CurrentDataSize: 16; //Number of data transfer extension
    /* 0xFFFF0000 */ uint32_t DataSize: 16; //Number of data at current transfer
  };
  uint32_t Value;
}SpiCR2_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t BitsNumber: 5; //DSIZE[4:0]: Bits number in single SPI data frame
	
    /* 0x00000020 */ uint32_t FIFO_ThresholdLevel: 4; //FTHVL [3:0]: FIFO threshold level
	
    /* 0x00000200 */ uint32_t BehaviorOfTransmitter : 2; //Free
    
    /* 0x00000200 */ uint32_t Free_0 : 4; //Free
  };
  uint32_t Value;
}SpiCFG1_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t SS_MasterIdleness: 4; //Master SS Idleness
	
    /* 0x00000010 */ uint32_t ID_MasterIdleness: 4; //Master Inter-Data Idleness
	
    /* 0x00000200 */ uint32_t BehaviorOfTransmitter : 2; //Free
    
    /* 0x00000200 */ uint32_t Free_0 : 4; //Free
  };
  uint32_t Value;
}SpiCFG2_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t RxNotEmpty: 1; //SPI_SR_RXP: Rx-Packet available
    /* 0x00000002 */ uint32_t TxEmpty: 1; //SPI_SR_TXP: Tx-Packet space available
    /* 0x00000004 */ uint32_t DuplexEmpty: 1; //SPI_SR_DXP: Duplex Packet available
    /* 0x00000008 */ uint32_t TxFifoEmpty: 1; //SPI_SR_EOT: Duplex Packet available
    
    /* 0x00000010 */ uint32_t TransferFilled: 1; //SPI_SR_TXTF: Transmission Transfer Filled
    /* 0x00000020 */ uint32_t Underrun: 1; //SPI_SR_UDR: UDR at Slave transmission
    /* 0x00000040 */ uint32_t Overrun: 1; //SPI_SR_OVR: Rx-Packet available
    /* 0x00000080 */ uint32_t CRC_Error: 1; //SPI_SR_CRCE: CRC Error Detected
    
    /*0x00000100*/ uint32_t FormatRrror : 1; //SPI_SR_TIFRE: TI frame format error Detected
    /*0x00000200*/ uint32_t ModeFaultDetected : 1; //SPI_SR_MODF: Mode Fault Detected
    /*0x00000400*/ uint32_t NumberSPI_Reloaded : 1; //SPI_SR_TSERF: Number of SPI data to be transacted reloaded
    /*0x00000800*/ uint32_t SUSP_Hardware : 1; //SPI_SR_SUSP: SUSP is set by hardware

    /*0x00001000*/ uint32_t TxFifoComplete : 1;//SPI_SR_TXC: TxFIFO transmission complete
    /*0x00002000*/ uint32_t RxFifoPackingLevel : 2; //SPI_SR_RXPLVL: RxFIFO Packing Level	
    /*0x00008000*/ uint32_t RxFifoNotEmpty: 1; //SPI_SR_RXWNE: Rx FIFO Word Not Empty

    /*0xFFFF0000*/ uint32_t NumberDataFrames: 16; //SPI_SR_CTSIZE: Number of data frames remaining in TSIZE
  };
  uint32_t Value;
}SpiSR_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t RxInterruptEnable: 1; //SPI_IER_RXPIE: RXP Interrupt Enable
    /* 0x00000002 */ uint32_t TxInterruptEnable: 1; //SPI_IER_TXPIE: TXP interrupt enable
    /* 0x00000004 */ uint32_t DuplexInterruptEnable: 1; //SPI_IER_DXPIE: DXP interrupt enable
    /* 0x00000008 */ uint32_t EOT_InterruptEnable: 1; //SPI_IER_EOTIE: EOT/SUSP/TXC interrupt enable
    
    /* 0x00000010 */ uint32_t TransferFilledInterruptEnable: 1; //SPI_IER_TXTFIE: TXTF interrupt enable
    /* 0x00000020 */ uint32_t UnderrunInterruptEnable: 1; //SPI_IER_UDRIE: UDR interrupt enable
    /* 0x00000040 */ uint32_t OverrunInterruptEnable: 1; //SPI_IER_OVRIE: OVR interrupt enable
    /* 0x00000080 */ uint32_t CRC_ErrorInterruptEnable: 1; //SPI_IER_CRCIE: CRC interrupt enable
    
    /*0x00000100*/ uint32_t FormatRrrorInterruptEnable : 1; //SPI_IER_TIFREIE: TI Frame Error interrupt enable
    /*0x00000200*/ uint32_t ModeFaultDetectedInterruptEnable : 1; //SPI_IER_MODFIE: MODF interrupt enable
    /*0x00000400*/ uint32_t NumberSPI_ReloadedInterruptEnable : 1; //SPI_IER_TSERIE: TSER interrupt enable
  };
  uint32_t Value;
}SpiIER_T;
//==============================================================================
typedef union{
  struct{
    /*0x00000001*/ uint32_t Free0_2: 3; // Free	
    /*0x00000008*/ uint32_t EndOfTransfer: 1; //SPI_IFCR_EOTC: End Of Transfer flag clear
    
    /*0x00000010*/ uint32_t TransferFilledClear: 1; //SPI_IFCR_TXTFC: Transmission Transfer Filled flag clear
    /*0x00000020*/ uint32_t UnderrunClear: 1; //SPI_IFCR_UDRC: Underrun flag clear
    /*0x00000040*/ uint32_t OverrunClear : 1; //SPI_IFCR_OVRC: Overrun flag clear	
    /*0x00000080*/ uint32_t CrcErrorClear : 1; //SPI_IFCR_CRCEC: CRC Error flag clear
    
    /*0x00000100*/ uint32_t FrameErrorClear : 1; //SPI_IFCR_TIFREC: TI frame format error flag clear
    /*0x00000200*/ uint32_t ModeFaultClear : 1; //SPI_IFCR_MODFC: Mode Fault flag clear
    /*0x00000400*/ uint32_t TSERFC_Clear: 1; //SPI_IFCR_TSERFC: TSERFC flag clear	
    /*0x00000800*/ uint32_t SUSPend_Clear : 1; //SPI_IFCR_SUSPC: SUSPend flag clear
  };
  uint32_t Value;
}SpiIFCR_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t CrcPolynomial: 16; //SPI_CRCPR_CRCPOLY 
  };
  uint32_t Value;
}SpiCRCPR_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t RxCrc: 16; //SPI_RXCRCR_RXCRC 
  };
  uint32_t Value;
}SpiRXCRCR_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t TxCrc: 16; //SPI_TXCRCR_TXCRC 
  };
  uint32_t Value;
}SpiTXCRCR_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t ChannelLength: 1; //SPI_I2SCFGR_CHLEN    
    /* 0x00000002 */ uint32_t DataLength: 2; //SPI_I2SCFGR_DATLEN
    /* 0x00000008 */ uint32_t ClockPolarity: 1; //SPI_I2SCFGR_CKPOL
    
    /* 0x00000010 */ uint32_t StandardSelection: 3; //I2SSTD
    /* 0x00000080 */ uint32_t PCM_FrameSynchronization: 1; //SPI_I2SCFGR_PCMSYNC
    
    /* 0x00000100 */ uint32_t ConfigurationMode: 2; //SPI_I2SCFGR_I2SCFG
    /* 0x00000400 */ uint32_t Enable: 1; //SPI_I2SCFGR_I2SE
    /* 0x00000800 */ uint32_t ModeSelection : 1; //SPI_I2SCFGR_I2SMOD
	
    /* 0x00001000 */ uint32_t AsynchronousStartEnable: 1; //SPI_I2SCFGR_ASTRTEN
  };
  uint32_t Value;
}SpiI2SCFGR_T;
//==============================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t LinearPrescaler: 8; //SPI_I2SPR_I2SDIV
    
    /* 0x00000100 */ uint32_t OddFactor: 1; //SPI_I2SPR_ODD
    /* 0x00000200 */ uint32_t MasterClockOutputEnable: 1; //SPI_I2SPR_MCKOE
  };
  uint32_t Value;
}SpiI2SPR_T;
//==============================================================================
typedef struct{
  volatile SpiCR1_T CR1; //SPI control register 1
  volatile SpiCR2_T CR2; //SPI control register 2
  
  volatile uint32_t CFG1; //SPI Status register
  volatile uint32_t CFG2; //SPI Status register
  
  volatile SpiIER_T IER; //SPI data register
  volatile SpiSR_T SR; //SPI data register
  volatile SpiIFCR_T IFCR; //SPI data register
  
  volatile uint32_t RESERVED0; //Reserved
  
  volatile uint32_t TXDR; //SPI data register
  
  volatile uint32_t RESERVED1[3]; //Reserved, 0x24-0x2C
  
  volatile uint32_t RXDR; //SPI data register
  
  volatile uint32_t RESERVED2[3]; //Reserved, 0x34-0x3C
  
  volatile uint32_t CRCPOLY; //SPI data register
  volatile uint32_t TXCRC; //SPI data register
  volatile uint32_t RXCRC; //SPI data register
  volatile uint32_t UDRDR; //SPI data register
  volatile uint32_t I2SCFGR; //SPI data register
}SpiRegT;
//==============================================================================
#endif /* PATTERN_STM32H7XX_SPI_H_ */
