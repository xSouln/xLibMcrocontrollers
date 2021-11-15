/*
 * xType.h
 *
 * Created: 16.05.2019 14:29:38
 *  Author: rekuts
 */ 
//=================================================================================================================================
#ifndef XTYPE_H_
#define XTYPE_H_
//=================================================================================================================================
#include <stdint.h>
#include <stdbool.h>
//=================================================================================================================================
typedef union{
  struct{
    uint64_t ExponentSign : 1;
    uint64_t Exponent : 11;
    uint64_t Mantisa : 52;
  };
  double Value;
}xDoubleT;
//=================================================================================================================================
enum ERRORS{
  ACCEPT = 0,
  ERROR_DATA,
  ERROR_CONTENT_SIZE,
  ERROR_REQUEST,
  ERROR_RESOLUTION,
  UNKNOWN_COMMAND,
  BUSY,
  OUTSIDE,
  ERROR_ACTION,
  ERROR_POSITION
};
//=================================================================================================================================
typedef void* xObject;
//=================================================================================================================================
typedef xObject (*xEvt)(xObject Obj);
typedef struct { xObject obj; uint16_t key; } xContext;
typedef struct { xObject obj; uint16_t size; } xContent;
//=================================================================================================================================
typedef struct{ uint8_t Start; uint8_t Ch1; uint8_t Ch2; uint8_t Ch3; uint8_t Ch4; uint8_t End; } RequestHeaderT;
typedef struct{ uint16_t Key; uint16_t Size; } RequestInfoT;
typedef struct{ RequestHeaderT Header; RequestInfoT Info; } RequestT;

typedef struct{ uint8_t Start; uint8_t Ch1; uint8_t Ch2; uint8_t Ch3; uint8_t Ch4; uint8_t End; } ResponseHeaderT;
typedef struct{ uint16_t Key; uint16_t Size; } ResponseInfoT;
typedef struct{ ResponseHeaderT Header; ResponseInfoT Info; } ResponseT;
	
typedef struct{ uint16_t Action; uint16_t Error; } ErrorResponseT;
	
#define REQUEST_START_CHARACTER '#'
#define REQUEST_END_CHARACTER ':'
#define RESPONSE_START_CHARACTER '#'
#define RESPONSE_END_CHARACTER ':'

#define REQUEST_PREFIX_SIZE sizeof(RequestPrefixT)
static char REQUEST_PREFIX_GET[] = "#GET::";
static char REQUEST_PREFIX_SET[] = "#SET::";
static char REQUEST_PREFIX_TRY[] = "#TRY::";
static char REQUEST_PREFIX_REQ[] = "#REQ::";
#define REQUEST_PACKET_SIZE (sizeof(RequestT))
static char REQUEST_END[] = "\r";

static char REQUEST_PREFIX_BOOT[] = "#BREQ:";
static char RESPONSE_BOOT_HEADER[] = "#BRES:";
static char RESPONSE_BOOT_ACCEPT[] = "#BACC:";

static char RESPONSE_HEADER[] = "#RES::";
static char RESPONSE_ACCEPT[] = "#ACC::";
static char RESPONSE_HEADER_NOTE[] = "#NOTE:";
static char RESPONSE_END[] = "\r";

#define RESPONSE_END_SIZE (sizeof(RESPONSE_END) / sizeof(RESPONSE_END[0]) - 1)
#define sizeof_str(str)(sizeof(str) / sizeof(str[0]) - 1)
#define sizeof_array(array)(sizeof(array) / sizeof(array[0]) - 1)
//=================================================================================================================================
typedef union{
  struct{
    uint8_t Free: 3;
    uint8_t TxEnable: 1;
    uint8_t RxEnable: 1;
    uint8_t TxInterruptEnable: 1;
    uint8_t TxEndTransmitInterruptEnable: 1;
    uint8_t RxInterruptEnable: 1;
  };
  uint8_t Value;
}UsartRegB_T;
//=================================================================================================================================
typedef union{
  struct{
    uint8_t MicroprocessorExchange: 1;
    uint8_t DoublingSpeed: 1;
    uint8_t ParityErrors: 1;
    uint8_t Overflowerror: 1;
    uint8_t CodingError: 1;
    uint8_t TxBufFree: 1;
    uint8_t TxComplite: 1;
    uint8_t RxComplite: 1;
  };
  uint8_t Value;
}UsartRegA_T;
//=================================================================================================================================
//=================================================================================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t SendBreak: 1; //USART_CR1_SBK    
    /* 0x00000002 */ uint32_t ReceiverWakeup: 1; //USART_CR1_RWU
    /* 0x00000004 */ uint32_t ReceiverEnable: 1; //USART_CR1_RE    
    /* 0x00000008 */ uint32_t TransmitterEnable: 1; //USART_CR1_TE
	
    /* 0x00000010 */ uint32_t IDLE_InterruptEnable: 1; //USART_CR1_IDLEIE
    /* 0x00000020 */ uint32_t RxNotEmptyInterruptEnable: 1; //USART_CR1_RXNEIE    
    /* 0x00000040 */ uint32_t TxCompleteInterruptEnable: 1; //USART_CR1_TCIE
    /* 0x00000080 */ uint32_t TxEmptyInterruptEnable: 1; //USART_CR1_TXEIE
    
    /* 0x00000100 */ uint32_t PE_InterruptEnable: 1; //USART_CR1_PEIE    
    /* 0x00000200 */ uint32_t ParitySelection: 1; //USART_CR1_PS
    /* 0x00000400 */ uint32_t ParityControlEnable: 1; //USART_CR1_PCE    
    /* 0x00000800 */ uint32_t WakeupMethod: 1; //USART_CR1_WAKE
	
    /* 0x00001000 */ uint32_t WordLength: 1; //USART_CR1_M
    /* 0x00002000 */ uint32_t USART_Enable: 2; //USART_CR1_UE
    /* 0x00008000 */ uint32_t OversamplingBy8: 1; //USART_CR1_OVER8
  };
  uint32_t Value;
}UsartCR1_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t AddressNode: 5; //USART_CR2_ADD
    
    /* 0x00000020 */ uint32_t LIN_Length: 1; //USART_CR2_LBDL
    /* 0x00000040 */ uint32_t LIN_Interrupt_Enable: 2; //USART_CR2_LBDIE
	
    /* 0x00000100 */ uint32_t LastBitClockPulse: 1; //USART_CR2_LBCL	
    /* 0x00000200 */ uint32_t ClockPhase: 1; //USART_CR2_CPHA
    /* 0x00000400 */ uint32_t ClockPolarity: 1; //USART_CR2_CPOL    
    /* 0x00000800 */ uint32_t ClockEnable: 1; //USART_CR2_CLKEN
	
    /* 0x00001000 */ uint32_t StopBit_0: 1; //USART_CR2_STOP_0    
    /* 0x00002000 */ uint32_t StopBit_1: 1; //USART_CR2_STOP_1    
    /* 0x00004000 */ uint32_t LIN_enable: 1; //USART_CR1_PS
  };
  uint32_t Value;
}UsartCR2_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t ErrorInterruptEnable: 1; //USART_CR3_EIE    
    /* 0x00000002 */ uint32_t IrDA_Enable: 1; //USART_CR3_IREN
    /* 0x00000004 */ uint32_t IrDA_LowPower : 1; //USART_CR3_IRLP
    /* 0x00000008 */ uint32_t HalfDuplexSelection: 1; //USART_CR3_HDSEL
	
    /* 0x00000010 */ uint32_t SmartcardNACK_Enable: 1; //USART_CR3_NACK	
    /* 0x00000020 */ uint32_t SmartcardEnable: 1; //USART_CR3_SCEN
    /* 0x00000040 */ uint32_t DMA_EnableReceiver: 1; //USART_CR3_DMAR    
    /* 0x00000080 */ uint32_t DMA_EnableTransmitter: 1; //USART_CR3_DMAT
	
    /* 0x00000100 */ uint32_t RTS_Enable: 1; //USART_CR3_RTSE    
    /* 0x00000200 */ uint32_t CTS_Enable: 1; //USART_CR3_CTSE    
    /* 0x00000400 */ uint32_t CTS_InterruptEnable: 1; //USART_CR3_CTSIE
    /* 0x00000800 */ uint32_t OneBitMethodEnable: 1; //USART_CR3_ONEBIT
  };
  uint32_t Value;
}UsartCR3_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t Prescaler: 8; //USART_GTPR_PSC
	
    /* 0x00000100 */ uint32_t GuardTime: 8; //USART_GTPR_GT
  };
  uint32_t Value;
}UsartGTPR_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t FractionUSARTDIV: 4; //USART_BRR_DIV_Fraction
	
    /* 0x00000010 */ uint32_t MantissaUSARTDIV: 12; //USART_BRR_DIV_Mantissa
  };
  uint32_t Value;
}UsartBRR_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t ErrorParity: 1; //USART_SR_PE
    /* 0x00000002 */ uint32_t ErrorFraming: 1;  //USART_SR_FE
    /* 0x00000004 */ uint32_t ErrorNoise: 1;  //USART_SR_NE
    /* 0x00000008 */ uint32_t ErrorOverRun: 1;  //USART_SR_ORE
    
    /* 0x00000010 */ uint32_t IDLE_Detected: 1; //USART_SR_IDLE    
    /* 0x00000020 */ uint32_t RxNotEmpty: 1; //USART_SR_RXNE    
    /* 0x00000040 */ uint32_t TxComplete: 1; //USART_SR_TC
    /* 0x00000080 */ uint32_t TxEmpty: 1; //USART_SR_TXE
    
    /* 0x00000100 */ uint32_t LIN_BreakDetection: 1; //USART_SR_LBD		
    /* 0x00000200 */ uint32_t CTS_Flag: 1; //USART_SR_CTS
  };
  uint32_t Value;
}UsartSR_T;

typedef struct{
  volatile UsartSR_T SR; //USART Status register
  volatile uint32_t DR; //USART Data register
  volatile UsartBRR_T BRR; //USART Baud rate register
  volatile UsartCR1_T CR1; //USART Control register 1
  volatile UsartCR2_T CR2; //USART Control register 2
  volatile UsartCR3_T CR3; //USART Control register 3
  volatile UsartGTPR_T GTPR; //SART Guard time and prescaler register
}UsartReg_T; // For stm32
//=================================================================================================================================
//=================================================================================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t ClockPhase: 1; //SPI_CR1_CPHA    
    /* 0x00000002 */ uint32_t ClockPolarity: 1; //SPI_CR1_CPOL
    /* 0x00000004 */ uint32_t MasterSelection: 1; //SPI_CR1_MSTR    
    /* 0x00000008 */ uint32_t BaudRate: 3; //SPI_CR1_BR
    
    /* 0x00000040 */ uint32_t Enable: 1; //SPI_CR1_SPE
    /* 0x00000080 */ uint32_t FrameFormat: 1; //SPI_CR1_LSBFIRST
    
    /* 0x00000100 */ uint32_t SlaveSelect: 1; //SPI_CR1_SSI    
    /* 0x00000200 */ uint32_t SoftwareSlave: 1; //SPI_CR1_SSM
    /* 0x00000400 */ uint32_t ReceiveOnly: 1; //SPI_CR1_RXONLY    
    /* 0x00000800 */ uint32_t DataFrameFormat: 1; //SPI_CR1_DFF
	
    /* 0x00001000 */ uint32_t TransmitCrcNext: 1; //SPI_CR1_CRCNEXT
    /* 0x00002000 */ uint32_t HardwareCrcCalculation: 1; //SPI_CR1_CRCEN
    /* 0x00004000 */ uint32_t BidirectionalOutput: 1; //SPI_CR1_BIDIOE
    /* 0x00008000 */ uint32_t BidirectionalData: 1; //SPI_CR1_BIDIMODE
  };
  uint32_t Value;
}SpiCR1_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t RxEnableDMA: 1; //SPI_CR2_RXDMAEN    
    /* 0x00000002 */ uint32_t TxEnableDMA: 1; //SPI_CR2_TXDMAEN
    /* 0x00000004 */ uint32_t SS_OutputEnable: 1; //SPI_CR2_SSOE
    /* 0x00000008 */ uint32_t Free_3: 1; //SPI_CR2_SSOE
    
    /* 0x00000010 */ uint32_t FrameFormat: 1; //SPI_CR2_FRF    
    /* 0x00000020 */ uint32_t ErrorInterruptEnable: 1; //SPI_CR2_ERRIE
    /* 0x00000040 */ uint32_t RxNotEmptyInterruptEnable: 1; //SPI_CR2_RXNEIE
    /* 0x00000080 */ uint32_t TxEmptyInterruptEnable: 1; //SPI_CR2_TXEIE
  };
  uint32_t Value;
}SpiCR2_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t RxNotEmpty: 1; //SPI_SR_RXNE    
    /* 0x00000002 */ uint32_t TxEmpty: 1; //SPI_SR_TXE
    /* 0x00000004 */ uint32_t ChannelSide: 1; //SPI_SR_CHSIDE
    /* 0x00000008 */ uint32_t Underrun: 1; //SPI_SR_UDR
    
    /* 0x00000010 */ uint32_t CrcError: 1; //SPI_SR_CRCERR    
    /* 0x00000020 */ uint32_t ModeFault: 1; //SPI_SR_MODF
    /* 0x00000040 */ uint32_t Overrun: 1; //SPI_SR_OVR
    /* 0x00000080 */ uint32_t Busy: 1; //SPI_SR_BSY
    
    /* 0x00000100 */ uint32_t FrameFormatRrror: 1; //SPI_SR_FRE
  };
  uint32_t Value;
}SpiSR_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t CrcPolynomial: 16; //SPI_CRCPR_CRCPOLY 
  };
  uint32_t Value;
}SpiCRCPR_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t RxCrc: 16; //SPI_RXCRCR_RXCRC 
  };
  uint32_t Value;
}SpiRXCRCR_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t TxCrc: 16; //SPI_TXCRCR_TXCRC 
  };
  uint32_t Value;
}SpiTXCRCR_T;

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

typedef union{
  struct{
    /* 0x00000001 */ uint32_t LinearPrescaler: 8; //SPI_I2SPR_I2SDIV
    
    /* 0x00000100 */ uint32_t OddFactor: 1; //SPI_I2SPR_ODD
    /* 0x00000200 */ uint32_t MasterClockOutputEnable: 1; //SPI_I2SPR_MCKOE
  };
  uint32_t Value;
}SpiI2SPR_T;

typedef struct{
  volatile SpiCR1_T CR1; //SPI control register 1
  volatile SpiCR2_T CR2; //SPI control register 2
  volatile SpiSR_T SR; //SPI status register
  volatile uint32_t DR; //SPI data register
  volatile SpiCRCPR_T CRCPR; //SPI CRC polynomial register (not used in I2S mode)
  volatile SpiRXCRCR_T RXCRCR; //SPI RX CRC register (not used in I2S mode)
  volatile SpiTXCRCR_T TXCRCR; //SPI TX CRC register (not used in I2S mode)
  volatile SpiI2SCFGR_T I2SCFGR; //SPI_I2S configuration register
  volatile SpiI2SPR_T I2SPR; //SPI_I2S prescaler register
}SpiRegT;
//=================================================================================================================================
//=================================================================================================================================
typedef union{
  struct{
    /* 0x00000001 */ uint32_t PeripheralEnable: 1; //I2C_CR1_PE    
    /* 0x00000002 */ uint32_t SMBusMode: 2; //I2C_CR1_SMBUS
    /* 0x00000008 */ uint32_t SMBusType: 1; //I2C_CR1_SMBTYPE
    
    /* 0x00000010 */ uint32_t ARPEnable: 1; //I2C_CR1_ENARP
    /* 0x00000020 */ uint32_t PECEnable: 1; //I2C_CR1_ENPEC
    /* 0x00000040 */ uint32_t GeneralCallEnable: 1; //I2C_CR1_ENGC
    /* 0x00000080 */ uint32_t SlaveMode: 1; //I2C_CR1_NOSTRETCH
    
    /* 0x00000100 */ uint32_t StartGeneration: 1; //I2C_CR1_START    
    /* 0x00000200 */ uint32_t StopGeneration: 1; //I2C_CR1_STOP
    /* 0x00000400 */ uint32_t AcknowledgeEnable: 1; //I2C_CR1_ACK    
    /* 0x00000800 */ uint32_t Acknowledge: 1; //I2C_CR1_POS
	
    /* 0x00001000 */ uint32_t PacketErrorChecking: 1; //I2C_CR1_PEC
    /* 0x00002000 */ uint32_t SMBusAlert: 2; //I2C_CR1_ALERT
    /* 0x00004000 */ //uint32_t SoftwareReset: 1; //I2C_CR1_SWRST
    /* 0x00008000 */ uint32_t SoftwareReset: 1; //I2C_CR1_SWRST
  };
  uint32_t Value;
}I2C_CR1_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t PeripheralClockFrequency: 6; //I2C_CR2_FREQ    

    /* 0x00000040 */ uint32_t Free0x40: 1; //I2C_CR1_ENGC
    /* 0x00000080 */ uint32_t Free0x80: 1; //I2C_CR1_NOSTRETCH    
    
    /* 0x00000100 */ uint32_t ErrorInterruptEnable: 1; //I2C_CR2_ITERREN    
    /* 0x00000200 */ uint32_t EventInterruptEnable: 1; //I2C_CR2_ITEVTEN
    /* 0x00000400 */ uint32_t BufferInterruptEnable: 1; //I2C_CR2_ITBUFEN    
    /* 0x00000800 */ uint32_t DMARequestsEnable: 1; //I2C_CR2_DMAEN
	
    /* 0x00001000 */ uint32_t DMALastTransfer: 1; //I2C_CR2_LAST
  };
  uint32_t Value;
}I2C_CR2_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t InterfaceAddress0x01: 1; //I2C_OAR1_ADD0    
    /* 0x00000002 */ uint32_t InterfaceAddress: 9; //I2C_OAR1_ADD1_7
    
    /* 0x00004000 */ uint32_t Free0x400_0x4000: 5; //Free0x400_0x4000
    /* 0x00008000 */ uint32_t SlaveMode: 1; //I2C_OAR1_ADDMODE
  };
  uint32_t Value;
}I2C_OAR1_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t DualAddressingModeEnable: 1; //I2C_OAR2_ENDUAL    
    /* 0x00000002 */ uint32_t InterfaceAddress: 7; //I2C_OAR1_ADD1_7
  };
  uint32_t Value;
}I2C_OAR2_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t StartBit: 1; //I2C_SR1_SB    
    /* 0x00000002 */ uint32_t AddressSent: 1; //I2C_SR1_ADDR
    /* 0x00000004 */ uint32_t ByteTransferFinished: 1; //I2C_SR1_BTF
    /* 0x00000008 */ uint32_t HeaderSent10bit: 1; //I2C_SR1_ADD10

    /* 0x00000010 */ uint32_t StopDetection: 1; //I2C_SR1_STOPF
    /* 0x00000020 */ uint32_t Free0x20: 1; //Free0x20
    /* 0x00000040 */ uint32_t RxNotEmpty: 1; //I2C_SR1_RXNE
    /* 0x00000080 */ uint32_t TxEmpty: 1; //I2C_SR1_TXE
    
    /* 0x00000100 */ uint32_t BusError: 1; //I2C_SR1_BERR    
    /* 0x00000200 */ uint32_t ArbitrationLost: 1; //I2C_SR1_ARLO
    /* 0x00000400 */ uint32_t AcknowledgeFailure: 1; //I2C_SR1_AF    
    /* 0x00000800 */ uint32_t OverrunOrUnderrun: 1; //I2C_SR1_OVR
	
    /* 0x00001000 */ uint32_t PECErrorInReception: 1; //I2C_SR1_PECERR
    /* 0x00002000 */ uint32_t Free0x2000: 1; //Free0x2000
    /* 0x00004000 */ uint32_t TimeoutOrTlowError: 1; //I2C_SR1_TIMEOUT
    /* 0x00008000 */ uint32_t SMBusAlert: 1; //I2C_SR1_SMBALERT
  };
  uint32_t Value;
}I2C_SR1_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t MasterOrSlave: 1; //I2C_SR2_MSL    
    /* 0x00000002 */ uint32_t BusBusy: 1; //I2C_SR2_BUSY
    /* 0x00000004 */ uint32_t TransmitterOrReceiver: 1; //I2C_SR1_BTF
    /* 0x00000008 */ uint32_t Free0x8: 1; //Free0x8

    /* 0x00000010 */ uint32_t GeneralCallAddress: 1; //I2C_SR2_GENCALL
    /* 0x00000020 */ uint32_t SMBusDeviceDefaultAddress: 1; //I2C_SR2_SMBDEFAULT
    /* 0x00000040 */ uint32_t SMBusHostHeader: 1; //I2C_SR2_SMBHOST
    /* 0x00000080 */ uint32_t DualFlag: 1; //I2C_SR2_DUALF
    
    /* 0x00000100 */ uint32_t PacketErrorCheckingRegister: 8; //I2C_SR2_PEC
  };
  uint32_t Value;
}I2C_SR2_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t ClockControlRegister : 12; //I2C_CCR_CCR

    /* 0x00001000 */ uint32_t Free0x1000_0x2000: 2; //Free0x1000_0x2000

    /* 0x00004000 */ uint32_t FastModeDutyCycle: 1; //I2C_CCR_DUTY
    /* 0x00008000 */ uint32_t I2CMasterModeSelection: 1; //I2C_CCR_FS
  };
  uint32_t Value;
}I2C_CCR_T;

typedef union{
  struct{
    /* 0x00000001 */ uint32_t MaximumRiseTime : 6; //I2C_CCR_CCR
  };
  uint32_t Value;
}I2C_TRISE_T;

typedef struct{
  volatile I2C_CR1_T CR1;
  volatile I2C_CR2_T CR2;
  volatile I2C_OAR1_T OAR1;
  volatile I2C_OAR2_T OAR2;
  volatile uint32_t DR;
  volatile I2C_SR1_T SR1;
  volatile I2C_SR2_T SR2;
  volatile I2C_CCR_T CCR;
  volatile I2C_TRISE_T TRISE;
}I2C_RegT;
//=================================================================================================================================
#endif /* XTYPE_H_ */
