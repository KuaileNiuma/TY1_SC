/** 
 *************************************************************************************
 * @file hw_sci.h
 * @brief This file contains the definition of hw_uart driver.
 * @version 1.0.0
 *************************************************************************************
 * @copyright Copyright (c) 2025 Albatross Semiconductor(Hangzhou) Co.,Ltd.
 * BSD-3-Clause License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ************************************************************************************
 */

#ifndef _HW_UART_H
#define _HW_UART_H

//*****************************************************************************
//
// UART Register Structure
//
//*****************************************************************************
typedef struct
{
	union
	{
		__IM
		uint32_t RBR;  //!< Receive buffer register             (offset = 0x000)
		__OM
		uint32_t THR;  //!< Transmission hold register          (offset = 0x000)
		__IOM
		uint32_t DLL; //!< Clock frequency division low section register (offset = 0x000)
	};
	union
	{
		__IOM
		uint32_t DLH; //!< Clock frequency division high section register (offset = 0x004)
		__IOM
		uint32_t IER;  //!< Interrupt enable register           (offset = 0x004)
	};
	union
	{
		__IM
		uint32_t IIR;  //!< Interrupt identification register   (offset = 0x008)
		__OM
		uint32_t FCR;  //!< FIFO control register               (offset = 0x008)
	};__IOM
	uint32_t LCR;      //!< Line control register               (offset = 0x00C)
	__IOM
	uint32_t MCR;      //!< Modem control register              (offset = 0x010)
	__IM
	uint32_t LSR;      //!< Line state register                 (offset = 0x014)
	__IM
	uint32_t MSR;      //!< Modem state register                (offset = 0x018)
	uint32_t RESERVED1[21];          //!< Reserved
	__IOM
	uint32_t FAR;      //!< FIFO access register                (offset = 0x070)
	__IM
	uint32_t TFR;      //!< Transmit FIFO read                  (offset = 0x074)
	__OM
	uint32_t RFW;      //!< Receive FIFO write                  (offset = 0x078)
	__IM
	uint32_t USR;      //!< UART state register                 (offset = 0x07C)
	__IM
	uint32_t TFL;      //!< Transmit FIFO level                 (offset = 0x080)
	__IM
	uint32_t RFL;      //!< Receive FIFO level                  (offset = 0x084)
	uint32_t RESERVED2[7];           //!< Reserved
	__IOM
	uint32_t HTX;      //!< Halt TX                             (offset = 0x0A4)
} UART_TypeDef;

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define FIFO_DEPTH              (16)

//*************************************************************************************************
//
// The following are defines for the SCI register offsets
//
//*************************************************************************************************
#define SCI_O_RBR_THR_DLL   0x00   // SCI_O_LCR[7]==0?Receive Buffer Register+Transmit Holding Register:Divisor Latch low
#define SCI_O_IER_DLH       0x04   // SCI_O_LCR[7]==0?Interrupt Enable Register:Divisor Latch High
#define SCI_O_IIR_FCR       0x08   /* FIFO Control Register */
#define SCI_O_LCR           0x0C   // Line Control Register
#define SCI_O_MCR           0x10   // Modem Control Register
#define SCI_O_LSR           0x14   // Line Status Register
#define SCI_O_MSR           0x18

#define  SCI_O_FAR        0x70       /* Offset: 0x070 (R/W)  FIFO accesss register */
#define  SCI_O_TFR        0x074      /* Offset: 0x074 (R/ )  transmit FIFO read */
#define  SCI_O_RFW        0x078      /* Offset: 0x078 ( /W)  receive FIFO write */
#define  SCI_O_USR        0x07c      /* Offset: 0x07c (R/ )  UART state register */
#define  SCI_O_TFL        0x080      /* Offset: 0x080 (R/ )  transmit FIFO level */
#define  SCI_O_RFL        0x084      /* Offset: 0x084 (R/ )  receive FIFO level */

#define SCI_O_HTX         0x0a4     /* Offset: 0x0a4 (R/W)  Halt TX */

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_O_RBR_THR_DLL register
//
//*************************************************************************************************
#define SCI_LSR_ADDR_RCVD    (0x100U)
#define SCI_LSR_RFE          (0x80U)
#define SCI_LSR_TEMT         (0x40U)
#define SCI_LSR_THRE         (0x20U)
#define SCI_LSR_BI           (0x10U)
#define SCI_LSR_FE           (0x08U)
#define SCI_LSR_PE           (0x04U)
#define SCI_LSR_OE           (0x02U)
#define SCI_LSR_DR           (0x01U)

#define SCI_RBR_SAR_M     0xFFU     // Receive Character bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_O_IER_DLH register
//
//*************************************************************************************************
#define SCI_IER_ERBFI        (0x01U)
#define SCI_IER_ETBEI        (0x02U)
#define SCI_IER_ELSI         (0x04U)
#define SCI_IER_PTIME        (0x80U)

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_O_LCR register
//
//*************************************************************************************************
#define SCI_LCR_DLAB         (0x80U)
#define SCI_LCR_DLS_M        (0x03U)

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_O_MCR register
//
//*************************************************************************************************
#define SCI_MCR_LOOPBACK         (0x10U)
#define SCI_MCR_AFCE             (0x20U)
#define SCI_MCR_SIR              (0x40U)

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_LSR register
//
//*************************************************************************************************

#define SCI_LSR_TEMT        (0x40U)
#define SCI_LSR_THRE        (0x20U)
#define SCI_LSR_FE         (0x08U)
#define SCI_LSR_PE         (0x04U)
#define SCI_LSR_OE         (0x02U)
#define SCI_LSR_DR         (0x01U)

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_USR register
//
//*************************************************************************************************

#define SCI_USR_RFF        (0x10U)
#define SCI_USR_RFNE       (0x08U)
#define SCI_USR_TFE        (0x04U)
#define SCI_USR_TFNF       (0x02U)
#define SCI_USR_BUSY       (0x01U)

//*************************************************************************************************
//
// The following are defines for the bit fields in the USR register
//
//*************************************************************************************************

#define SCI_USR_RSVD_RFF     (0x10U)
#define SCI_USR_RSVD_RFNE    (0x08U)
#define SCI_USR_RSVD_TFE     (0x04U)
#define SCI_USR_RSVD_TFNF    (0x02U)
#define SCI_USR_BUSY         (0x01U)
#define SCI_USR_TXFF_ST_M    (0x06U)
#define SCI_USR_RXFF_ST_M    (0x18U)

//*************************************************************************************************
//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_O_IIR_FCR register
//
//*************************************************************************************************
#define SCI_IIR_RO_FIFOSE_M    (0x00C0U)
#define SCI_IIR_RO_IID_M       (0x000FU)

#define SCI_FCR_FIFOE          (0x01U)
#define SCI_FCR_RFIFOR         (0x02U)
#define SCI_FCR_XFIFOR         (0x04U)
#define SCI_FCR_DMAM           (0x08U)

#define SCI_IIR_IID_MODEM      (0x0U)
#define SCI_IIR_IID_NO_PD      (0x1U)
#define SCI_IIR_IID_THR_EMPTY  (0x2U)
#define SCI_IIR_IID_RECV       (0x4U)
#define SCI_IIR_IID_STATUS     (0x6U)
#define SCI_IIR_IID_BUSY       (0x7U)
#define SCI_IIR_IID_CH_TIMEOUT (0xCU)

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCICCR register
//
//*************************************************************************************************
#define SCI_CCR_SCICHAR_M       (0x7U)    // Character length control
#define SCI_CCR_ADDRIDLE_MODE   (0x8U)    // ADDR/IDLE Mode control
#define SCI_CCR_LOOPBKENA       (0x10U)   // Loop Back enable
#define SCI_CCR_PARITYENA       (0x20U)   // Parity enable
#define SCI_CCR_PARITY          (0x40U)   // Even or Odd Parity
#define SCI_CCR_STOPBITS        (0x80U)   // Number of Stop Bits

//*************************************************************************************************
// wfmodify
// The following are defines for the bit fields in the SCI_O_LCR_EXT register
//
//*************************************************************************************************
#define SCI_LCR_EXT_DLS_E             (0x01U)
#define SCI_LCR_EXT_ADDR_MATCH       (0x02U)
#define SCI_LCR_EXT_SEND_ADDR        (0x04U)
#define SCI_LCR_EXT_TRANSMIT_MODE    (0x08U)

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_O_TFL register
//
//*************************************************************************************************
#define SCI_TFL_M             (0x1FU)

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCI_O_RFL register
//
//*************************************************************************************************
#define SCI_RFL_M             (0x1FU)

//*****************************************************************************
//
// SCI Configuration Definitions
//
//*****************************************************************************
#define SCI_CONFIG_WLEN_M   0x0003U  //!< Mask for extracting word length
#define SCI_CONFIG_WLEN_8      0x0007U  //!< 8 bit data
#define SCI_CONFIG_WLEN_7      0x0006U  //!< 7 bit data
#define SCI_CONFIG_WLEN_6      0x0005U  //!< 6 bit data
#define SCI_CONFIG_WLEN_5      0x0004U  //!< 5 bit data
#define SCI_CONFIG_WLEN_4      0x0003U  //!< 4 bit data
#define SCI_CONFIG_WLEN_3      0x0002U  //!< 3 bit data
#define SCI_CONFIG_WLEN_2      0x0001U  //!< 2 bit data
#define SCI_CONFIG_WLEN_1      0x0000U  //!< 1 bit data

#define SCI_CONFIG_STOP_M   0x0004U  //!< Mask for extracting stop bits
#define SCI_CONFIG_STOP_ONE    0x0000U  //!< One stop bit
#define SCI_CONFIG_STOP_TWO    0x0004U  //!< Two stop bits

#define SCI_CONFIG_PAR_M    0x0018U  //!< Parity Mask

//*****************************************************************************
//
// SCI Register Bit Definitions
//
//*****************************************************************************
#define SCI_RXBUF_SAR_M        0xFFU     //!< Receive Character bits

#define SCI_FFRX_RXFFIL_M      0xC0U     //!< Rx Interrupt level mask
#define SCI_FFRX_EMPTY         0x00U     //!< Tx FIFO EMPTY
#define SCI_FFTX_TXFFIL_M      0x30U     //!< Tx Interrupt level mask
#define SCI_FFTX_FULL          0x00U     //!< Tx FIFO FULL
#define SCI_FFRX_RT_S      (6)       //!< Rx trigger shift
#define SCI_FFTX_TET_S     (4)       //!< Tx empty trigger shift

//*****************************************************************************
//
// SCI Interrupt Definitions
//
//*****************************************************************************
#define SCI_RX_DATA_AVAILABLE_INT   0x01U  //!< Enable Received Data Available Interrupt
#define SCI_TX_EMPTY_INT           0x02U  //!< Enable Transmit Holding Register Empty Interrupt
#define SCI_LINE_STATUS_INT        0x04U  //!< Enable Receiver Line Status Interrupt
#define SCI_MODEN_STATUS_INT       0x08U  //!< Enable Modem Status Interrupt
#define SCI_LSR_CLEAR_METHOD       0x10U  //!< Method for clearing the status in the LSR
#define SCI_THRE_INT_MODE          0x80U  //!< Programmable THRE Interrupt Mode Enable

//*****************************************************************************
//
// SCI UART Status Definitions
//
//*****************************************************************************
#define SCI_UART_STATUS_BUSY           0x01  //!< Indicates that a serial transfer is in progress
#define SCI_UART_STATUS_TF_NOT_FULL    0x02  //!< Indicates that the transmit fifo not full
#define SCI_UART_STATUS_TF_EMPTY       0x04  //!< Indicates that the transmit fifo empty
#define SCI_UART_STATUS_RF_NOT_EMPTY   0x08  //!< Indicates that the receive fifo not empty
#define SCI_UART_SYATUS_RF_FULL        0x10  //!< Indicates that the receive is full

//*****************************************************************************
//
// Values that can be used with SCI_setParityMode() and SCI_getParityMode() to
// describe the parity of the SCI communication.
//
//*****************************************************************************
typedef enum
{
	SCI_CONFIG_PAR_NONE = 0x0000U,  //!< No parity
	SCI_CONFIG_PAR_EVEN = 0x0018U,  //!< Even parity
	SCI_CONFIG_PAR_ODD = 0x0008U   //!< Odd parity
} SCI_ParityType;

//*****************************************************************************
//
// Values that can be used to select the number of stop bits
//
//*****************************************************************************
typedef enum
{
	SCI_STOP_1BIT = 0X00,          //!< 1 stop bit
	SCI_STOP_1_5BIT_OR_2BIT = 0X04 //!< 1.5 or 2 stop bits
} SCI_StopBit;

//*****************************************************************************
//
//! Values that can be used to select the data length
//
//*****************************************************************************
typedef enum
{
	SCI_CHAR_5BITS = 0X00,         //!< 5-bit character length
	SCI_CHAR_6BITS = 0X01,         //!< 6-bit character length
	SCI_CHAR_7BITS = 0X02,         //!< 7-bit character length
	SCI_CHAR_8BITS = 0X03          //!< 8-bit character length
} SCI_DataLenSelect;

//*****************************************************************************
//
// Values that represent different interrupt status conditions
//
//*****************************************************************************
typedef enum
{
	SCI_MODEM_STATUS = 0x00,         //!< Modem status interrupt
	SCI_NO_INTERRUPT_PENDING = 0x01,         //!< No interrupt pending
	SCI_THR_EMPTY = 0x02,         //!< Transmit holding register empty
	SCI_RX_DATA_AVAILABLE = 0x04,         //!< Receive data available
	SCI_RX_LINE_STATUS = 0x06,         //!< Receiver line status
	SCI_BUSY_DETECT = 0x07,         //!< Busy detect
	SCI_CHARACTER_TIMEOUT = 0x0c          //!< Character timeout
} SCI_INT_STATUS;

//*****************************************************************************
//
// Values that represent receive FIFO trigger levels
//
//*****************************************************************************
typedef enum
{
	RT_FIFO_CHAR_1 = 0x0,  //!< 1 character in FIFO
	RT_FIFO_QSCIER_FULL = 0x1,  //!< FIFO 1/4 full
	RT_FIFO_HALF_FULL = 0x2,  //!< FIFO 1/2 full
	RT_FIFO_FULL_2 = 0x3   //!< FIFO 2 less than full
} SCI_RCVR_TRIGGER;

//*****************************************************************************
//
// Values that represent transmit FIFO empty trigger levels
//
//*****************************************************************************
typedef enum
{
	TET_FIFO_EMPTY = 0x0,  //!< FIFO empty
	TET_FIFO_CHAR_2 = 0x1,  //!< 2 characters in FIFO
	TET_FIFO_QSCIER_FULL = 0x2,  //!< FIFO 1/4 full
	TET_FIFO_HALF_FULL = 0x3   //!< FIFO 1/2 full
} SCI_TX_EMPTY_TRIGGER;

//*****************************************************************************
//
// Values that can be passed to SCI_setFIFOInterruptLevel() as the txLevel
// parameter and returned by SCI_getFIFOInterruptLevel() and
// SCI_getTxFIFOStatus().
//
//*****************************************************************************
typedef enum
{
	SCI_FIFO_TX0 = TET_FIFO_EMPTY,         //!< FIFO empty
	SCI_FIFO_TX2 = TET_FIFO_CHAR_2,        //!< 2 characters in FIFO
	SCI_FIFO_TX4 = TET_FIFO_QSCIER_FULL,   //!< FIFO 1/4 full
	SCI_FIFO_TX8 = TET_FIFO_HALF_FULL     //!< FIFO 1/2 full
} SCI_TxFIFOLevel;

//*****************************************************************************
//
// Values that can be passed to SCI_setFIFOInterruptLevel() as the rxLevel
// parameter and returned by SCI_getFIFOInterruptLevel() and
// SCI_getRxFIFOStatus().
//
//*****************************************************************************
typedef enum
{
	SCI_FIFO_RX1 = RT_FIFO_CHAR_1,        //!< 1 character in FIFO
	SCI_FIFO_RX4 = RT_FIFO_QSCIER_FULL,   //!< FIFO 1/4 full
	SCI_FIFO_RX8 = RT_FIFO_HALF_FULL,     //!< FIFO 1/2 full
	SCI_FIFO_RX14 = RT_FIFO_FULL_2         //!< FIFO 2 less than full
} SCI_RxFIFOLevel;

//*****************************************************************************
//
// Values that represent receive FIFO status levels
//
//*****************************************************************************
typedef enum
{
	SCI_RX_FIFO_0 = 0,          //!< FIFO contains 0 characters
	SCI_RX_FIFO_1,              //!< FIFO contains 1 character
	SCI_RX_FIFO_2,              //!< FIFO contains 2 characters
	SCI_RX_FIFO_3,              //!< FIFO contains 3 characters
	SCI_RX_FIFO_4,              //!< FIFO contains 4 characters
	SCI_RX_FIFO_5,              //!< FIFO contains 5 characters
	SCI_RX_FIFO_6,              //!< FIFO contains 6 characters
	SCI_RX_FIFO_7,              //!< FIFO contains 7 characters
	SCI_RX_FIFO_8,              //!< FIFO contains 8 characters
	SCI_RX_FIFO_9,              //!< FIFO contains 9 characters
	SCI_RX_FIFO_10,             //!< FIFO contains 10 characters
	SCI_RX_FIFO_11,             //!< FIFO contains 11 characters
	SCI_RX_FIFO_12,             //!< FIFO contains 12 characters
	SCI_RX_FIFO_13,             //!< FIFO contains 13 characters
	SCI_RX_FIFO_14,             //!< FIFO contains 14 characters
	SCI_RX_FIFO_15,             //!< FIFO contains 15 characters
	SCI_RX_FIFO_16              //!< FIFO contains 16 characters
} SCI_RxFIFOStatus;

//*****************************************************************************
//
//! Values that represent receive FIFO trigger levels
//
//*****************************************************************************
typedef enum
{
	FCR_RT_1 = 0,               //!< Trigger at 1 character
	FCR_RT_1D4_FULL,            //!< Trigger at 1/4 full
	FCR_RT_1D2_FULL,            //!< Trigger at 1/2 full
	FCR_RT_FULL_SUB_2           //!< Trigger at 2 less than full
} e_RXFF_RT;

//*****************************************************************************
//
// Values that represent transmit FIFO empty trigger levels
//
//*****************************************************************************
typedef enum
{
	FCR_TET_0 = 0,              //!< Trigger when empty
	FCR_TET_2,                  //!< Trigger at 2 characters
	FCR_TET_1D4_FULL,           //!< Trigger at 1/4 full
	FCR_TET_1D2_FULL            //!< Trigger at 1/2 full
} e_TXFF_TET;

//*****************************************************************************
//
// Values that represent 9-bit transmit mode settings
//
//*****************************************************************************
typedef enum
{
	TX_9BitMode_0 = 0,          //!< 9-bit wide, software writes 9th bit
	TX_9BitMode_1               //!< 8-bit wide(SCI_O_TAR) + SEND_ADDR=1
} SCI_Mode9bit_Tx;

//*****************************************************************************
//
// Values that represent 9-bit receive mode settings
//
//*****************************************************************************
typedef enum
{
	Rx_9BitMode_0 = 0,          //!< Normal mode, 9-bit wide, software recognize
	Rx_9BitMode_1               //!< Address match by hardware
} SCI_Mode9bit_Rx;

//*****************************************************************************
//
// Values that represent DMA mode settings
//
//*****************************************************************************
typedef enum
{
	DMAM_0 = 0,                //!< Supports single DMA data transfers at a time
	DMAM_1 = 1          //!< Supports multi-DMA data transfers until FIFO filled
} SCI_DmaMode;

//*****************************************************************************
//
// Values returned from SCI_getLineStatus().  These correspond to the different
// bits and flags of the SCIRXST register.
//
//*****************************************************************************

#define SCI_RXSTATUS_READY      0x0001U  //!< Receiver ready
#define SCI_RXSTATUS_OVERRUN    0x0002U  //!< Overrun error
#define SCI_RXSTATUS_PARITY     0x0004U  //!< Parity error
#define SCI_RXSTATUS_FRAMING    0x0008U  //!< Framing error
#define SCI_RXSTATUS_BREAK      0x0010U  //!< Break detect
#define SCI_TXREG_EMPTY         0x0020U  //!< Transmit Holding Register Empty
#define SCI_TXSTATUS_EMPTY      0x0040U  //!< Transmit Holding Register Empty and Shift Register Empty
#define SCI_RXFIFO_ERROR        0x0080U  //!< Receiver error

#endif

