/** 
  ************************************************************************************* 
  * @file usart.h
  * @brief This file contains the definition of usart driver. 
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

#ifndef __XYZF4xx_USART_H
#define __XYZF4xx_USART_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include "hw_common.h"
#include "hw_usart.h"

//*****************************************************************************
//
//! Deinitializes the USART peripheral registers to their default reset values.
//! 
//! \param base is the base address of the USART peripheral.
//! 
//! This function deinitializes the USART peripheral registers to their default
//! reset values, including disabling the USART, clearing configuration settings,
//! and resetting all control registers.
//! 
//! \return None.
//
//*****************************************************************************
void USART_DeInit(uint32_t base);


//*****************************************************************************
//
//! Initializes the USART peripheral according to the specified parameters.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_InitStruct is a pointer to a USART_InitTypeDef structure that contains
//!        the configuration information for the specified USART peripheral.
//! 
//! This function initializes the USART peripheral with the specified configuration
//! parameters, including word length, stop bits, parity, baud rate, mode, and hardware
//! flow control settings.
//! 
//! \return None.
//
//*****************************************************************************
void USART_Init(uint32_t base, uint32_t apbclock, USART_InitTypeDef *USART_InitStruct);


//*****************************************************************************
//
//! Fills each USART_InitStruct member with its default value.
//! 
//! \param USART_InitStruct is a pointer to a USART_InitTypeDef structure that will
//!        be initialized with default values.
//! 
//! This function initializes the USART_InitTypeDef structure with default values:
//! - USART_BaudRate = 9600
//! - USART_WordLength = USART_WordLength_8b
//! - USART_StopBits = USART_StopBits_1
//! - USART_Parity = USART_Parity_No
//! - USART_Mode = USART_Mode_Rx | USART_Mode_Tx
//! - USART_HardwareFlowControl = USART_HardwareFlowControl_None
//! 
//! \return None.
//
//*****************************************************************************
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);


//*****************************************************************************
//
//! Configures the USART clock source according to the specified parameters.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_ClockInitStruct is a pointer to a USART_ClockInitTypeDef structure that contains
//!        the configuration information for the USART clock.
//! 
//! This function configures the USART clock with the specified settings, including
//! enabling/disabling the clock, setting the clock polarity (CPOL), clock phase (CPHA),
//! and the last bit clock pulse control.
//! 
//! \return None.
//
//*****************************************************************************
void USART_ClockInit(uint32_t base, USART_ClockInitTypeDef* USART_ClockInitStruct);


//*****************************************************************************
//
//! Fills each USART_ClockInitStruct member with its default value.
//! 
//! \param USART_ClockInitStruct is a pointer to a USART_ClockInitTypeDef structure that will
//!        be initialized with default values.
//! 
//! This function initializes the USART_ClockInitTypeDef structure with default values:
//! - USART_Clock = USART_Clock_Disable
//! - USART_CPOL = USART_CPOL_Low
//! - USART_CPHA = USART_CPHA_1Edge
//! - USART_LastBit = USART_LastBit_Disable
//! 
//! \return None.
//
//*****************************************************************************
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);


//*****************************************************************************
//
//! Enables or disables the USART peripheral.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the USART peripheral.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the USART peripheral
//!        - \b DISABLE: Disable the USART peripheral
//! 
//! This function enables or disables the USART peripheral by setting or clearing
//! the USART Enable bit in the Control Register 1 (CR1).
//! 
//! \return None.
//
//*****************************************************************************
void USART_Cmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Enables or disables the specified USART interrupts.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_IT specifies the USART interrupt sources to be enabled or disabled.
//!        This parameter can be any combination of the following values:
//!        - USART_IT_PE: Parity error interrupt
//!        - USART_IT_TXE: Transmit data register empty interrupt
//!        - USART_IT_TC: Transmission complete interrupt
//!        - USART_IT_RXNE: Receive data register not empty interrupt
//!        - USART_IT_IDLE: Idle line detection interrupt
//!        - USART_IT_LBD: LIN break detection interrupt
//!        - USART_IT_CTS: CTS change interrupt
//!        - USART_IT_ERR: Error interrupt
//! 
//! \param NewState is the new state of the specified USART interrupts.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the specified USART interrupts
//!        - \b DISABLE: Disable the specified USART interrupts
//! 
//! This function enables or disables the specified USART interrupts by setting or clearing
//! the corresponding interrupt enable bits in the USART control registers.
//! 
//! \return None.
//
//*****************************************************************************
void USART_ITConfig(uint32_t base, uint16_t USART_IT, FunctionalState NewState);


//*****************************************************************************
//
//! Enables or disables the USART DMA interface.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_DMAReq specifies the USART DMA request sources to be enabled or disabled.
//!        This parameter can be any combination of the following values:
//!        - USART_DMAReq_Tx: Transmit DMA request
//!        - USART_DMAReq_Rx: Receive DMA request
//! 
//! \param NewState is the new state of the specified USART DMA request sources.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the specified USART DMA request sources
//!        - \b DISABLE: Disable the specified USART DMA request sources
//! 
//! This function enables or disables the USART DMA interface by setting or clearing
//! the corresponding DMA enable bits in the USART Control Register 3 (CR3).
//! 
//! \return None.
//
//*****************************************************************************
void USART_DMACmd(uint32_t base, uint16_t USART_DMAReq, FunctionalState NewState);


//*****************************************************************************
//
//! Sets the USART node address for multi-node communication.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_Address is the USART node address.
//!        This parameter must be a number between 0 and 15.
//! 
//! This function sets the USART node address used in multi-processor communication mode.
//! The address is stored in the USART Control Register 2 (CR2).
//! 
//! \return None.
//
//*****************************************************************************
void USART_SetAddress(uint32_t base, uint8_t USART_Address);


//*****************************************************************************
//
//! Configures the USART wake-up method for multi-processor communication.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_WakeUp specifies the wake-up method.
//!        This parameter can be one of the following values:
//!        - USART_WakeUp_IdleLine: Idle line wake-up
//!        - USART_WakeUp_AddressMark: Address mark wake-up
//! 
//! This function configures the USART wake-up method used in multi-processor communication
//! mode to wake up the receiver from low-power modes.
//! 
//! \return None.
//
//*****************************************************************************
void USART_WakeUpConfig(uint32_t base, uint16_t USART_WakeUp);


//*****************************************************************************
//
//! Enables or disables the USART receiver wake-up function.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the receiver wake-up function.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the receiver wake-up function
//!        - \b DISABLE: Disable the receiver wake-up function
//! 
//! This function enables or disables the USART receiver wake-up function, which
//! allows the USART to wake up the system from low-power modes when receiving
//! data in multi-processor communication mode.
//! 
//! \return None.
//
//*****************************************************************************
void USART_ReceiverWakeUpCmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Configures the USART LIN break detection length.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_LINBreakDetectLength specifies the break detection length.
//!        This parameter can be one of the following values:
//!        - USART_LINBreakDetectLength_10b: 10-bit break detection length
//!        - USART_LINBreakDetectLength_11b: 11-bit break detection length
//! 
//! This function configures the length of the break character to be detected by
//! the USART in LIN (Local Interconnect Network) mode.
//! 
//! \return None.
//
//*****************************************************************************
void USART_LINBreakDetectLengthConfig(uint32_t base, uint16_t USART_LINBreakDetectLength);


//*****************************************************************************
//
//! Enables or disables the USART LIN (Local Interconnect Network) mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the LIN mode.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the LIN mode
//!        - \b DISABLE: Disable the LIN mode
//! 
//! This function enables or disables the USART LIN mode by setting or clearing
//! the LIN mode enable bit in the USART Control Register 2 (CR2).
//! 
//! \return None.
//
//*****************************************************************************
void USART_LINCmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Transmits a data through the USART peripheral.
//! 
//! \param base is the base address of the USART peripheral.
//! \param Data is the data to be transmitted.
//!        This parameter must be a number between 0 and 0x1FF.
//! 
//! This function transmits a single data byte or half-word through the USART peripheral.
//! The data is written to the USART Data Register (DR), which automatically triggers
//! the transmission process.
//! 
//! \return None.
//
//*****************************************************************************
void USART_SendData(uint32_t base, uint16_t Data);


//*****************************************************************************
//
//! Returns the most recent received data by the USART peripheral.
//! 
//! \param base is the base address of the USART peripheral.
//! 
//! This function returns the received data from the USART Data Register (DR).
//! The data value depends on the word length configuration (8-bit or 9-bit data).
//! 
//! \return The received data value. This value is between 0 and 0x1FF.
//
//*****************************************************************************
uint16_t USART_ReceiveData(uint32_t base);


//*****************************************************************************
//
//! Transmits break characters.
//! 
//! \param base is the base address of the USART peripheral.
//! 
//! This function sends a break character through the USART peripheral by setting
//! the Send Break bit in the USART Control Register 1 (CR1). A break character
//! is a sequence of low level bits longer than a normal character frame.
//! 
//! \return None.
//
//*****************************************************************************
void USART_SendBreak(uint32_t base);


//*****************************************************************************
//
//! Sets the USART guard time value for SmartCard mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_GuardTime is the guard time value in terms of bit periods.
//!        This parameter must be a number between 0 and 15.
//! 
//! This function sets the guard time value used in SmartCard mode, which is the
//! time between the end of the stop bit and the beginning of the next start bit.
//! The guard time is stored in the USART Guard Time Register (GTPR).
//! 
//! \return None.
//
//*****************************************************************************
void USART_SetGuardTime(uint32_t base, uint8_t USART_GuardTime);


//*****************************************************************************
//
//! Sets the USART prescaler value for IrDA mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_Prescaler is the prescaler value.
//!        This parameter must be a number between 1 and 15.
//! 
//! This function sets the prescaler value used in IrDA mode to divide the USART
//! clock. The prescaler is stored in the USART Guard Time Register (GTPR).
//! 
//! \return None.
//
//*****************************************************************************
void USART_SetPrescaler(uint32_t base, uint8_t USART_Prescaler);


//*****************************************************************************
//
//! Enables or disables the USART SmartCard mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the SmartCard mode.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the SmartCard mode
//!        - \b DISABLE: Disable the SmartCard mode
//! 
//! This function enables or disables the USART SmartCard mode by setting or clearing
//! the SmartCard mode enable bit in the USART Control Register 3 (CR3).
//! 
//! \return None.
//
//*****************************************************************************
void USART_SmartCardCmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Enables or disables the USART SmartCard NACK transmission.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the SmartCard NACK transmission.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the SmartCard NACK transmission
//!        - \b DISABLE: Disable the SmartCard NACK transmission
//! 
//! This function enables or disables the transmission of NACK (Not Acknowledged)
//! signals in SmartCard mode by setting or clearing the corresponding bit in the
//! USART Control Register 3 (CR3).
//! 
//! \return None.
//
//*****************************************************************************
void USART_SmartCardNACKCmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Enables or disables the USART half-duplex mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the half-duplex mode.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the half-duplex mode
//!        - \b DISABLE: Disable the half-duplex mode
//! 
//! This function enables or disables the USART half-duplex mode, which allows
//! communication over a single data line by automatically controlling the
//! direction of data flow.
//! 
//! \return None.
//
//*****************************************************************************
void USART_HalfDuplexCmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Enables or disables the USART 8x oversampling mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the 8x oversampling mode.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the 8x oversampling mode
//!        - \b DISABLE: Disable the 8x oversampling mode (use 16x oversampling)
//! 
//! This function enables or disables the USART 8x oversampling mode, which allows
//! for higher baud rates at the same clock frequency compared to the standard
//! 16x oversampling mode.
//! 
//! \return None.
//
//*****************************************************************************
void USART_OverSampling8Cmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Enables or disables the USART one-bit sampling method.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the one-bit sampling method.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the one-bit sampling method
//!        - \b DISABLE: Disable the one-bit sampling method (use three-sample majority vote)
//! 
//! This function enables or disables the USART one-bit sampling method, which
//! can improve noise immunity in certain communication scenarios.
//! 
//! \return None.
//
//*****************************************************************************
void USART_OneBitMethodCmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Configures the USART IrDA (Infrared Data Association) mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_IrDAMode specifies the IrDA mode.
//!        This parameter can be one of the following values:
//!        - USART_IrDAMode_LowPower: Low-power IrDA mode
//!        - USART_IrDAMode_Normal: Normal IrDA mode
//! 
//! This function configures the USART IrDA mode with the specified operating mode,
//! which is used for infrared communication according to the IrDA standard.
//! 
//! \return None.
//
//*****************************************************************************
void USART_IrDAConfig(uint32_t base, uint16_t USART_IrDAMode);


//*****************************************************************************
//
//! Enables or disables the USART IrDA (Infrared Data Association) mode.
//! 
//! \param base is the base address of the USART peripheral.
//! \param NewState is the new state of the IrDA mode.
//!        This parameter can be one of the following values:
//!        - \b ENABLE: Enable the IrDA mode
//!        - \b DISABLE: Disable the IrDA mode
//! 
//! This function enables or disables the USART IrDA mode by setting or clearing
//! the IrDA mode enable bit in the USART Control Register 3 (CR3).
//! 
//! \return None.
//
//*****************************************************************************
void USART_IrDACmd(uint32_t base, FunctionalState NewState);


//*****************************************************************************
//
//! Checks whether the specified USART flag is set or not.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_FLAG specifies the flag to check.
//!        This parameter can be one of the following values:
//!        - USART_FLAG_PE: Parity Error flag
//!        - USART_FLAG_TXE: Transmit data register empty flag
//!        - USART_FLAG_TC: Transmission complete flag
//!        - USART_FLAG_RXNE: Receive data register not empty flag
//!        - USART_FLAG_IDLE: Idle Line detected flag
//!        - USART_FLAG_LBD: LIN Break detection flag
//!        - USART_FLAG_CTS: CTS Change flag
//!        - USART_FLAG_ORE: OverRun Error flag
//!        - USART_FLAG_NE: Noise Error flag
//!        - USART_FLAG_FE: Framing Error flag
//! 
//! This function checks the specified USART flag status by reading the USART Status
//! Register (SR).
//! 
//! \return The new state of USART_FLAG (SET or RESET).
//
//*****************************************************************************
FlagStatus USART_GetFlagStatus(uint32_t base, uint16_t USART_FLAG);


//*****************************************************************************
//
//! Clears the specified USART flags.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_FLAG specifies the flag to clear.
//!        This parameter can be one of the following values:
//!        - USART_FLAG_TC: Transmission complete flag
//!        - USART_FLAG_RXNE: Receive data register not empty flag
//!        - USART_FLAG_LBD: LIN Break detection flag
//!        - USART_FLAG_CTS: CTS Change flag
//! 
//! This function clears the specified USART flags by performing the appropriate
//! operations according to the USART specification. Note that some flags require
//! specific operations to be cleared.
//! 
//! \return None.
//
//*****************************************************************************
void USART_ClearFlag(uint32_t base, uint16_t USART_FLAG);


//*****************************************************************************
//
//! Checks whether the specified USART interrupt has occurred or not.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_IT specifies the USART interrupt source to check.
//!        This parameter can be one of the following values:
//!        - USART_IT_PE: Parity Error interrupt
//!        - USART_IT_TXE: Transmit data register empty interrupt
//!        - USART_IT_TC: Transmission complete interrupt
//!        - USART_IT_RXNE: Receive data register not empty interrupt
//!        - USART_IT_IDLE: Idle Line detected interrupt
//!        - USART_IT_LBD: LIN Break detection interrupt
//!        - USART_IT_CTS: CTS Change interrupt
//!        - USART_IT_ORE: OverRun Error interrupt
//!        - USART_IT_NE: Noise Error interrupt
//!        - USART_IT_FE: Framing Error interrupt
//! 
//! This function checks whether the specified USART interrupt has occurred by
//! reading the corresponding interrupt flag in the USART Status Register (SR)
//! and verifying that the interrupt is enabled.
//! 
//! \return The new state of the USART_IT (SET or RESET).
//
//*****************************************************************************
ITStatus USART_GetITStatus(uint32_t base, uint16_t USART_IT);


//*****************************************************************************
//
//! Clears the USART's interrupt pending bits.
//! 
//! \param base is the base address of the USART peripheral.
//! \param USART_IT specifies the interrupt pending bit to clear.
//!        This parameter can be one of the following values:
//!        - USART_IT_PE: Parity Error interrupt
//!        - USART_IT_TC: Transmission complete interrupt
//!        - USART_IT_RXNE: Receive data register not empty interrupt
//!        - USART_IT_IDLE: Idle Line detected interrupt
//!        - USART_IT_LBD: LIN Break detection interrupt
//!        - USART_IT_CTS: CTS Change interrupt
//! 
//! This function clears the specified USART interrupt pending bit by performing
//! the appropriate operations according to the USART specification. Different
//! interrupt flags may require different clearing procedures.
//! 
//! \return None.
//
//*****************************************************************************
void USART_ClearITPendingBit(uint32_t base, uint16_t USART_IT);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // USART_H


