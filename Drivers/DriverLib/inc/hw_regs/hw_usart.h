/**
 *************************************************************************************
 * @file hw_usart.h
 * @brief This file contains the definition of hw_usart driver.
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

#ifndef _HW_USART_H
#define _HW_USART_H

//*****************************************************************************
//
// USART Register Structure
//
//*****************************************************************************
typedef struct
{
   __IO uint16_t SR;            //!< USART Status Register
   uint16_t  RESERVED0;         //!< Reserved
   __IO uint16_t DR;            //!< USART Data Register
   uint16_t  RESERVED1;         //!< Reserved
   __IO uint16_t BRR;           //!< USART Baud Rate Register
   uint16_t  RESERVED2;         //!< Reserved
   __IO uint16_t CR1;           //!< USART Control Register 1
   uint16_t  RESERVED3;         //!< Reserved
   __IO uint16_t CR2;           //!< USART Control Register 2
   uint16_t  RESERVED4;         //!< Reserved
   __IO uint16_t CR3;           //!< USART Control Register 3
   uint16_t  RESERVED5;         //!< Reserved
   __IO uint16_t GTPR;          //!< USART Guard Time and Prescaler Register
   uint16_t  RESERVED6;         //!< Reserved
} USART_TypeDef;

#define USART_O_SR			(0x00U)
#define USART_O_DR			(0x04U)
#define USART_O_BRR			(0x08U)
#define USART_O_CR1			(0X0CU)
#define USART_O_CR2			(0x10U)
#define USART_O_CR3			(0x14U)
#define USART_O_GTPR		(0x18U)


//*****************************************************************************
//
//! USART Init Structure
//
//*****************************************************************************
typedef struct
{
  uint32_t USART_BaudRate;            //!< Configures the USART communication baud rate.
                                      //!< The baud rate is computed using the following formula:
                                      //!< - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
                                      //!< - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5

  uint16_t USART_WordLength;          //!< Specifies the number of data bits transmitted or received in a frame.
                                      //!< This parameter can be one of the USART_WordLength values.

  uint16_t USART_StopBits;            //!< Specifies the number of stop bits transmitted.
                                      //!< This parameter can be one of the USART_StopBits values.

  uint16_t USART_Parity;              //!< Specifies the parity mode.
                                      //!< This parameter can be one of the USART_Parity values.
                                      //!< Note: When parity is enabled, the computed parity is inserted
                                      //!< at the MSB position of the transmitted data (9th bit when
                                      //!< the word length is set to 9 data bits; 8th bit when the
                                      //!< word length is set to 8 data bits).

  uint16_t USART_Mode;                //!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                      //!< This parameter can be one of the USART_Mode values.

  uint16_t USART_HardwareFlowControl; //!< Specifies whether the hardware flow control mode is enabled
                                      //!< or disabled.
                                      //!< This parameter can be one of the USART_HardwareFlowControl values.
} USART_InitTypeDef;


//*****************************************************************************
//
//! USART Clock Init Structure
//
//*****************************************************************************
typedef struct
{
  uint16_t USART_Clock;   //!< Specifies whether the USART clock is enabled or disabled.
                          //!< This parameter can be one of the USART_Clock values.

  uint16_t USART_CPOL;    //!< Specifies the steady state value of the serial clock.
                          //!< This parameter can be one of the USART_CPOL values.

  uint16_t USART_CPHA;    //!< Specifies the clock transition on which the bit capture is made.
                          //!< This parameter can be one of the USART_CPHA values.

  uint16_t USART_LastBit; //!< Specifies whether the clock pulse corresponding to the last transmitted
                          //!< data bit (MSB) has to be output on the SCLK pin in synchronous mode.
                          //!< This parameter can be one of the USART_LastBit values.
} USART_ClockInitTypeDef;


//*****************************************************************************
//
// USART Word Length Definitions
//
//*****************************************************************************
#define USART_WordLength_8b                  ((uint16_t)0x0000)  //!< 8-bit word length
#define USART_WordLength_9b                  ((uint16_t)0x1000)  //!< 9-bit word length

#define IS_USART_WORD_LENGTH(LENGTH) (((LENGTH) == USART_WordLength_8b) || \
                                      ((LENGTH) == USART_WordLength_9b))


//*****************************************************************************
//
// USART Stop Bits Definitions
//
//*****************************************************************************
#define USART_StopBits_1                     ((uint16_t)0x0000)  //!< 1 stop bit
#define USART_StopBits_0_5                   ((uint16_t)0x1000)  //!< 0.5 stop bits
#define USART_StopBits_2                     ((uint16_t)0x2000)  //!< 2 stop bits
#define USART_StopBits_1_5                   ((uint16_t)0x3000)  //!< 1.5 stop bits

#define IS_USART_STOPBITS(STOPBITS) (((STOPBITS) == USART_StopBits_1) || \
                                     ((STOPBITS) == USART_StopBits_0_5) || \
                                     ((STOPBITS) == USART_StopBits_2) || \
                                     ((STOPBITS) == USART_StopBits_1_5))


//*****************************************************************************
//
// USART Parity Definitions
//
//*****************************************************************************
#define USART_Parity_No                      ((uint16_t)0x0000)  //!< No parity
#define USART_Parity_Even                    ((uint16_t)0x0400)  //!< Even parity
#define USART_Parity_Odd                     ((uint16_t)0x0600)  //!< Odd parity

#define IS_USART_PARITY(PARITY) (((PARITY) == USART_Parity_No) || \
                                 ((PARITY) == USART_Parity_Even) || \
                                 ((PARITY) == USART_Parity_Odd))  //!< Check if PARITY is valid (No, Even or Odd)


//*****************************************************************************
//
// USART Mode Definitions
//
//*****************************************************************************
#define USART_Mode_Rx                        ((uint16_t)0x0004)  //!< Receive mode
#define USART_Mode_Tx                        ((uint16_t)0x0008)  //!< Transmit mode

#define IS_USART_MODE(MODE) ((((MODE) & (uint16_t)0xFFF3) == 0x00) && ((MODE) != (uint16_t)0x00))


//*****************************************************************************
//
// USART Hardware Flow Control Definitions
//
//*****************************************************************************
#define USART_HardwareFlowControl_None       ((uint16_t)0x0000)  //!< No hardware flow control
#define USART_HardwareFlowControl_RTS        ((uint16_t)0x0100)  //!< RTS flow control
#define USART_HardwareFlowControl_CTS        ((uint16_t)0x0200)  //!< CTS flow control
#define USART_HardwareFlowControl_RTS_CTS    ((uint16_t)0x0300)  //!< RTS and CTS flow control

#define IS_USART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == USART_HardwareFlowControl_None) || \
                               ((CONTROL) == USART_HardwareFlowControl_RTS) || \
                               ((CONTROL) == USART_HardwareFlowControl_CTS) || \
                               ((CONTROL) == USART_HardwareFlowControl_RTS_CTS))


//*****************************************************************************
//
// USART Clock Definitions
//
//*****************************************************************************
#define USART_Clock_Disable                  ((uint16_t)0x0000)  //!< Clock disabled
#define USART_Clock_Enable                   ((uint16_t)0x0800)  //!< Clock enabled

#define IS_USART_CLOCK(CLOCK) (((CLOCK) == USART_Clock_Disable) || \
                               ((CLOCK) == USART_Clock_Enable))


//*****************************************************************************
//
// USART Clock Polarity Definitions
//
//*****************************************************************************
#define USART_CPOL_Low                       ((uint16_t)0x0000)  //!< Clock polarity low
#define USART_CPOL_High                      ((uint16_t)0x0400)  //!< Clock polarity high

#define IS_USART_CPOL(CPOL) (((CPOL) == USART_CPOL_Low) || ((CPOL) == USART_CPOL_High))


//*****************************************************************************
//
// USART Clock Phase Definitions
//
//*****************************************************************************
#define USART_CPHA_1Edge                     ((uint16_t)0x0000)  //!< 1st clock edge
#define USART_CPHA_2Edge                     ((uint16_t)0x0200)  //!< 2nd clock edge

#define IS_USART_CPHA(CPHA) (((CPHA) == USART_CPHA_1Edge) || ((CPHA) == USART_CPHA_2Edge))


//*****************************************************************************
//
// USART Last Bit Definitions
//
//*****************************************************************************
#define USART_LastBit_Disable                ((uint16_t)0x0000)  //!< Last bit clock pulse disabled
#define USART_LastBit_Enable                 ((uint16_t)0x0100)  //!< Last bit clock pulse enabled

#define IS_USART_LASTBIT(LASTBIT) (((LASTBIT) == USART_LastBit_Disable) || \
                                   ((LASTBIT) == USART_LastBit_Enable))


//*****************************************************************************
//
// USART Interrupt Definitions
//
//*****************************************************************************
#define USART_IT_PE                          ((uint16_t)0x0028)  //!< Parity Error interrupt
#define USART_IT_TXE                         ((uint16_t)0x0727)  //!< Transmit Data Register Empty interrupt
#define USART_IT_TC                          ((uint16_t)0x0626)  //!< Transmission Complete interrupt
#define USART_IT_RXNE                        ((uint16_t)0x0525)  //!< Read Data Register Not Empty interrupt
#define USART_IT_ORE_RX                      ((uint16_t)0x0325)  //!< OverRun Error with RXNE interrupt
#define USART_IT_IDLE                        ((uint16_t)0x0424)  //!< Idle Line interrupt
#define USART_IT_LBD                         ((uint16_t)0x0846)  //!< LIN Break Detection interrupt
#define USART_IT_CTS                         ((uint16_t)0x096A)  //!< CTS interrupt
#define USART_IT_ERR                         ((uint16_t)0x0060)  //!< Error interrupt
#define USART_IT_ORE_ER                      ((uint16_t)0x0360)  //!< OverRun Error with Error interrupt
#define USART_IT_NE                          ((uint16_t)0x0260)  //!< Noise Error interrupt
#define USART_IT_FE                          ((uint16_t)0x0160)  //!< Framing Error interrupt

//*****************************************************************************
//
// USART Legacy Definitions
//
//*****************************************************************************
#define USART_IT_ORE                          USART_IT_ORE_ER  //!< Legacy OverRun Error interrupt


//*****************************************************************************
//
// USART Interrupt Configuration Checks
//
//*****************************************************************************
#define IS_USART_CONFIG_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
                               ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                               ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
                               ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ERR))

#define IS_USART_GET_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
                            ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                            ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
                            ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ORE) || \
                            ((IT) == USART_IT_ORE_RX) || ((IT) == USART_IT_ORE_ER) || \
                            ((IT) == USART_IT_NE) || ((IT) == USART_IT_FE))

#define IS_USART_CLEAR_IT(IT) (((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                               ((IT) == USART_IT_LBD) || ((IT) == USART_IT_CTS))


//*****************************************************************************
//
// USART DMA Requests Definitions
//
//*****************************************************************************
#define USART_DMAReq_Tx                      ((uint16_t)0x0080)  //!< TX DMA request
#define USART_DMAReq_Rx                      ((uint16_t)0x0040)  //!< RX DMA request

#define IS_USART_DMAREQ(DMAREQ) ((((DMAREQ) & (uint16_t)0xFF3F) == 0x00) && ((DMAREQ) != (uint16_t)0x00))


//*****************************************************************************
//
// USART WakeUp Methods Definitions
//
//*****************************************************************************
#define USART_WakeUp_IdleLine                ((uint16_t)0x0000)  //!< Wake up on idle line
#define USART_WakeUp_AddressMark             ((uint16_t)0x0800)  //!< Wake up on address mark

#define IS_USART_WAKEUP(WAKEUP) (((WAKEUP) == USART_WakeUp_IdleLine) || \
                                 ((WAKEUP) == USART_WakeUp_AddressMark))


//*****************************************************************************
//
// USART LIN Break Detection Length Definitions
//
//*****************************************************************************
#define USART_LINBreakDetectLength_10b      ((uint16_t)0x0000)  //!< 10-bit LIN break detection
#define USART_LINBreakDetectLength_11b      ((uint16_t)0x0020)  //!< 11-bit LIN break detection
#define IS_USART_LIN_BREAK_DETECT_LENGTH(LENGTH) \
                               (((LENGTH) == USART_LINBreakDetectLength_10b) || \
                                ((LENGTH) == USART_LINBreakDetectLength_11b))

//*****************************************************************************
//
// USART IrDA Mode Definitions
//
//*****************************************************************************
#define USART_IrDAMode_LowPower              ((uint16_t)0x0004)  //!< Low power IrDA mode
#define USART_IrDAMode_Normal                ((uint16_t)0x0000)  //!< Normal IrDA mode
#define IS_USART_IRDA_MODE(MODE) (((MODE) == USART_IrDAMode_LowPower) || \
                                  ((MODE) == USART_IrDAMode_Normal))

//*****************************************************************************
//
// USART SmartCard Mode Definitions
//
//*****************************************************************************
#define USART_SmartCard_Mode_Disable         ((uint16_t)0x0000)  //!< SmartCard mode disabled
#define USART_SmartCard_Mode_Enable          ((uint16_t)0x0400)  //!< SmartCard mode enabled
#define IS_USART_SMARTCARD_MODE(MODE) (((MODE) == USART_SmartCard_Mode_Disable) || \
                                      ((MODE) == USART_SmartCard_Mode_Enable))


//*****************************************************************************
//
// USART SmartCard NACK Definitions
//
//*****************************************************************************
#define USART_SmartCardNACK_Enable           ((uint16_t)0x0200)  //!< SmartCard NACK enabled
#define USART_SmartCardNACK_Disable          ((uint16_t)0x0000)  //!< SmartCard NACK disabled
#define IS_USART_SMARTCARD_NACK(NACK) (((NACK) == USART_SmartCardNACK_Enable) || \
                                      ((NACK) == USART_SmartCardNACK_Disable))


//*****************************************************************************
//
// USART Half Duplex Mode Definitions
//
//*****************************************************************************
#define USART_HalfDuplexMode_Disable         ((uint16_t)0x0000)  //!< Half duplex mode disabled
#define USART_HalfDuplexMode_Enable          ((uint16_t)0x0008)  //!< Half duplex mode enabled
#define IS_USART_HALF_DUPLEX_MODE(MODE) (((MODE) == USART_HalfDuplexMode_Disable) || \
                                        ((MODE) == USART_HalfDuplexMode_Enable))


//*****************************************************************************
//
// USART SIREN Definitions
//
//*****************************************************************************
#define USART_SIREN_Disable                  ((uint16_t)0x0000)  //!< SIREN disabled
#define USART_SIREN_Enable                   ((uint16_t)0x0004)  //!< SIREN enabled
#define IS_USART_SIREN(SIREN) (((SIREN) == USART_SIREN_Disable) || \
                               ((SIREN) == USART_SIREN_Enable))


//*****************************************************************************
//
// USART Flags Definitions
//
//*****************************************************************************
#define USART_FLAG_PE                        ((uint16_t)0x0001)  //!< Parity Error flag
#define USART_FLAG_FE                        ((uint16_t)0x0002)  //!< Framing Error flag
#define USART_FLAG_NE                        ((uint16_t)0x0004)  //!< Noise Error flag
#define USART_FLAG_ORE                       ((uint16_t)0x0008)  //!< OverRun Error flag
#define USART_FLAG_IDLE                      ((uint16_t)0x0010)  //!< Idle Line flag
#define USART_FLAG_RXNE                      ((uint16_t)0x0020)  //!< Read Data Register Not Empty flag
#define USART_FLAG_TC                        ((uint16_t)0x0040)  //!< Transmission Complete flag
#define USART_FLAG_TXE                       ((uint16_t)0x0080)  //!< Transmit Data Register Empty flag
#define USART_FLAG_LBD                       ((uint16_t)0x0100)  //!< LIN Break Detection flag
#define USART_FLAG_CTS                       ((uint16_t)0x0200)  //!< CTS Change flag

//*****************************************************************************
//
// USART Flag Check Macros
//
//*****************************************************************************
#define IS_USART_FLAG(FLAG) (((FLAG) == USART_FLAG_PE) || ((FLAG) == USART_FLAG_FE) || \
                             ((FLAG) == USART_FLAG_NE) || ((FLAG) == USART_FLAG_ORE) || \
                             ((FLAG) == USART_FLAG_IDLE) || ((FLAG) == USART_FLAG_RXNE) || \
                             ((FLAG) == USART_FLAG_TC) || ((FLAG) == USART_FLAG_TXE) || \
                             ((FLAG) == USART_FLAG_LBD) || ((FLAG) == USART_FLAG_CTS))  //!< Check if FLAG is valid USART flag

#define IS_USART_CLEAR_FLAG(FLAG) ((((FLAG) & (uint16_t)0xFC9F) == 0x00) && ((FLAG) != (uint16_t)0x00))  //!< Check if FLAG is valid clearable USART flag


#endif
