/**
 *************************************************************************************
 * @file usart.c
 * @brief This file implements the function of usart driver.
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

#include "usart.h"
#include "rcc.h"

//*****************************************************************************
//
// USART Control Register 1 (CR1) Masks
//
//*****************************************************************************
#define CR1_UE_Set                ((uint16_t)0x2000)  //!< USART Enable Mask
#define CR1_UE_Reset              ((uint16_t)0xDFFF)  //!< USART Disable Mask
#define CR1_WAKE_Mask             ((uint16_t)0xF7FF)  //!< USART WakeUp Method Mask
#define CR1_RWU_Set               ((uint16_t)0x0002)  //!< USART mute mode Enable Mask
#define CR1_RWU_Reset             ((uint16_t)0xFFFD)  //!< USART mute mode Enable Mask
#define CR1_SBK_Set               ((uint16_t)0x0001)  //!< USART Break Character send Mask
#define CR1_CLEAR_Mask            ((uint16_t)0xE9F3)  //!< USART CR1 Mask

//*****************************************************************************
//
// USART Control Register 2 (CR2) Masks
//
//*****************************************************************************
#define CR2_Address_Mask          ((uint16_t)0xFFF0)  //!< USART address Mask
#define CR2_LINEN_Set             ((uint16_t)0x4000)  //!< USART LIN Enable Mask
#define CR2_LINEN_Reset           ((uint16_t)0xBFFF)  //!< USART LIN Disable Mask
#define CR2_LBDL_Mask             ((uint16_t)0xFFDF)  //!< USART LIN Break detection Mask
#define CR2_STOP_CLEAR_Mask       ((uint16_t)0xCFFF)  //!< USART CR2 STOP Bits Mask
#define CR2_CLOCK_CLEAR_Mask      ((uint16_t)0xF0FF)  //!< USART CR2 Clock Mask

//*****************************************************************************
//
// USART Control Register 3 (CR3) Masks
//
//*****************************************************************************
#define CR3_SCEN_Set              ((uint16_t)0x0020)  //!< USART SC Enable Mask
#define CR3_SCEN_Reset            ((uint16_t)0xFFDF)  //!< USART SC Disable Mask
#define CR3_NACK_Set              ((uint16_t)0x0010)  //!< USART SC NACK Enable Mask
#define CR3_NACK_Reset            ((uint16_t)0xFFEF)  //!< USART SC NACK Disable Mask
#define CR3_HDSEL_Set             ((uint16_t)0x0008)  //!< USART Half-Duplex Enable Mask
#define CR3_HDSEL_Reset           ((uint16_t)0xFFF7)  //!< USART Half-Duplex Disable Mask
#define CR3_IRLP_Mask             ((uint16_t)0xFFFB)  //!< USART IrDA LowPower mode Mask
#define CR3_CLEAR_Mask            ((uint16_t)0xFCFF)  //!< USART CR3 Mask
#define CR3_IREN_Set              ((uint16_t)0x0002)  //!< USART IrDA Enable Mask
#define CR3_IREN_Reset            ((uint16_t)0xFFFD)  //!< USART IrDA Disable Mask

//*****************************************************************************
//
// USART Guard Time and Prescaler Register (GTPR) Masks
//
//*****************************************************************************
#define GTPR_LSB_Mask             ((uint16_t)0x00FF)  //!< Guard Time Register LSB Mask */
#define GTPR_MSB_Mask             ((uint16_t)0xFF00)  //!< Guard Time Register MSB Mask */

//*****************************************************************************
//
// USART Interrupt and Special Mode Masks
//
//*****************************************************************************
#define IT_Mask                   ((uint16_t)0x001F)  //!< USART Interrupt Mask

//*****************************************************************************
//
// USART OverSampling-8 Masks
//
//*****************************************************************************
#define CR1_OVER8_Set             ((uint16_t)0x8000)  //!< USART OVER8 mode Enable Mask
#define CR1_OVER8_Reset           ((uint16_t)0x7FFF)  //!< USART OVER8 mode Disable Mask

//*****************************************************************************
//
// USART One Bit Sampling Masks
//
//*****************************************************************************
#define CR3_ONEBITE_Set           ((uint16_t)0x0800)  //!< USART ONEBITE mode Enable Mask
#define CR3_ONEBITE_Reset         ((uint16_t)0xF7FF)  //!< USART ONEBITE mode Disable Mask

//*****************************************************************************
//
// USART_Init
//
//*****************************************************************************
void USART_Init(uint32_t base, uint32_t apbclock, USART_InitTypeDef *USART_InitStruct)
{
    uint32_t tmpreg = 0x00;
    uint64_t integerdivider = 0x00;
    uint32_t fractionaldivider = 0x00;
    //
    // USART CR2 Configuration
    //
    tmpreg = HWREG(base + USART_O_CR2);
    //
    // Clear STOP[13:12] bits
    //
    tmpreg &= CR2_STOP_CLEAR_Mask;
    //
    // Configure the USART Stop Bits, Clock, CPOL, CPHA and LastBit
    // Set STOP[13:12] bits according to USART_StopBits value
    //
    tmpreg |= (uint32_t) USART_InitStruct->USART_StopBits;
    //
    // Write to USART CR2
    //
    HWREG(base + USART_O_CR2) = (uint16_t) tmpreg;
    //
    // USART CR1 Configuration
    //
    tmpreg =HWREG(base + USART_O_CR1);;
    //
    // Clear M, PCE, PS, TE and RE bits
    //
    tmpreg &= CR1_CLEAR_Mask;
    //
    // Configure the USART Word Length, Parity and mode
    // Set the M bits according to USART_WordLength value
    // Set PCE and PS bits according to USART_Parity value
    // Set TE and RE bits according to USART_Mode value
    //
    tmpreg |= (uint32_t) USART_InitStruct->USART_WordLength
            | USART_InitStruct->USART_Parity | USART_InitStruct->USART_Mode;
    //
    // Write to USART CR1
    //
    HWREG(base + USART_O_CR1) = (uint16_t) tmpreg;
    //
    // USART CR3 Configuration
    //
    tmpreg = HWREG(base + USART_O_CR3);
    //
    // Clear CTSE and RTSE bits
    //
    tmpreg &= CR3_CLEAR_Mask;
    //
    // Configure the USART HFC
    // Set CTSE and RTSE bits according to USART_HardwareFlowControl value
    //
    tmpreg |= USART_InitStruct->USART_HardwareFlowControl;
    //
    // Write to USART CR3
    //
    HWREG(base + USART_O_CR3) = (uint16_t) tmpreg;
    //
    // Determine the integer part
    //
    integerdivider = apbclock / (16 *USART_InitStruct->USART_BaudRate);
    tmpreg = integerdivider << 4;
    //
    // Determine the fractional part
    //
    fractionaldivider = (apbclock / USART_InitStruct->USART_BaudRate) - (integerdivider * 16);
    tmpreg |= fractionaldivider;
    //
    // Write to USART BRR
    //
    HWREG(base + USART_O_BRR) = (uint16_t) tmpreg;
}

//*****************************************************************************
//
// USART_StructInit
//
//*****************************************************************************
void USART_StructInit(USART_InitTypeDef *USART_InitStruct)
{
	//
	// USART_InitStruct members default value
	//
	USART_InitStruct->USART_BaudRate = 9600;
	USART_InitStruct->USART_WordLength = USART_WordLength_8b;
	USART_InitStruct->USART_StopBits = USART_StopBits_1;
	USART_InitStruct->USART_Parity = USART_Parity_No;
	USART_InitStruct->USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct->USART_HardwareFlowControl =
			USART_HardwareFlowControl_None;
}

//*****************************************************************************
//
// USART_ClockInit
//
//*****************************************************************************
void USART_ClockInit(uint32_t base,
		USART_ClockInitTypeDef *USART_ClockInitStruct)
{
	uint32_t tmpreg = 0x00;

	//
	// USART CR2 Configuration
	//
	tmpreg = HWREG(base + USART_O_CR2);
	//
	// Clear CLKEN, CPOL, CPHA and LBCL bits
	//
	tmpreg &= CR2_CLOCK_CLEAR_Mask;
	//
	// Configure the USART Clock, CPOL, CPHA and LastBit
	// Set CLKEN bit according to USART_Clock value
	// Set CPOL bit according to USART_CPOL value
	// Set CPHA bit according to USART_CPHA value
	// Set LBCL bit according to USART_LastBit value
	//
	tmpreg |= (uint32_t) USART_ClockInitStruct->USART_Clock
			| USART_ClockInitStruct->USART_CPOL
			| USART_ClockInitStruct->USART_CPHA
			| USART_ClockInitStruct->USART_LastBit;
	//
	// Write to USART CR2
	//
	HWREG(base + USART_O_CR2) = (uint16_t) tmpreg;
}

//*****************************************************************************
//
// USART_ClockStructInit
//
//*****************************************************************************
void USART_ClockStructInit(USART_ClockInitTypeDef *USART_ClockInitStruct)
{
	//
	// USART_ClockInitStruct members default value
	//
	USART_ClockInitStruct->USART_Clock = USART_Clock_Disable;
	USART_ClockInitStruct->USART_CPOL = USART_CPOL_Low;
	USART_ClockInitStruct->USART_CPHA = USART_CPHA_1Edge;
	USART_ClockInitStruct->USART_LastBit = USART_LastBit_Disable;
}

//*****************************************************************************
//
// USART_Cmd
//
//*****************************************************************************
void USART_Cmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the selected USART by setting the UE bit in the CR1 register
		//
		HWREG(base + USART_O_CR1) |= CR1_UE_Set;
	}
	else
	{
		//
		// Disable the selected USART by clearing the UE bit in the CR1 register
		//
		HWREG(base + USART_O_CR1) &= CR1_UE_Reset;
	}
}

//*****************************************************************************
//
// USART_ITConfig
//
//*****************************************************************************
void USART_ITConfig(uint32_t base, uint16_t USART_IT, FunctionalState NewState)
{
	uint32_t usartreg = 0x00, itpos = 0x00, itmask = 0x00;

	//
	// Get the USART register index
	//
	usartreg = (((uint8_t) USART_IT) >> 0x05);

	//
	// Get the interrupt position
	//
	itpos = USART_IT & IT_Mask;
	itmask = (((uint32_t) 0x01) << itpos);

	if (usartreg == 0x01)
	{
		base += 0x0C;
	}
	else if (usartreg == 0x02)
	{
		base += 0x10;
	}
	else  // The IT is in CR3 register
	{
		base += 0x14;
	}
	if (NewState != DISABLE)
	{
		*(__IO uint32_t*) base |= itmask;
	}
	else
	{
		*(__IO uint32_t*) base &= ~itmask;
	}
}

//*****************************************************************************
//
// USART_DMACmd
//
//*****************************************************************************
void USART_DMACmd(uint32_t base, uint16_t USART_DMAReq,
		FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the DMA transfer for selected requests by setting the DMAT and/or
		// DMAR bits in the USART CR3 register
		//
		HWREG(base + USART_O_CR3) |= USART_DMAReq;
	}
	else
	{
		//
		// Disable the DMA transfer for selected requests by clearing the DMAT and/or
		// DMAR bits in the USART CR3 register
		//
		HWREG(base + USART_O_CR3) &= (uint16_t) ~USART_DMAReq;
	}
}

/**
 * @brief  Sets the address of the USART node.
 * @param  USARTx: Select the USART or the UART peripheral.
 *   This parameter can be one of the following values:
 *   USART1, USART2, USART3, UART4 or UART5.
 * @param  USART_Address: Indicates the address of the USART node.
 * @retval None
 */
void USART_SetAddress(uint32_t base, uint8_t USART_Address)
{
	/* Clear the USART address */
	HWREG(base + USART_O_CR2) &= CR2_Address_Mask;
	/* Set the USART address node */
	HWREG(base + USART_O_CR2) |= USART_Address;
}

/**
 * @brief  Selects the USART WakeUp method.
 * @param  USARTx: Select the USART or the UART peripheral.
 *   This parameter can be one of the following values:
 *   USART1, USART2, USART3, UART4 or UART5.
 * @param  USART_WakeUp: specifies the USART wakeup method.
 *   This parameter can be one of the following values:
 *     @arg USART_WakeUp_IdleLine: WakeUp by an idle line detection
 *     @arg USART_WakeUp_AddressMark: WakeUp by an address mark
 * @retval None
 */
//*****************************************************************************
//
// USART_WakeUpConfig
//
//*****************************************************************************
void USART_WakeUpConfig(uint32_t base, uint16_t USART_WakeUp)
{
	HWREG(base + USART_O_CR1) &= CR1_WAKE_Mask;
	HWREG(base + USART_O_CR1)|= USART_WakeUp;
}

//*****************************************************************************
//
// USART_ReceiverWakeUpCmd
//
//*****************************************************************************
void USART_ReceiverWakeUpCmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the USART mute mode  by setting the RWU bit in the CR1 register
		//
		HWREG(base + USART_O_CR1) |= CR1_RWU_Set;
	}
	else
	{
		/* Disable the USART mute mode by clearing the RWU bit in the CR1 register */
		HWREG(base + USART_O_CR1) &= CR1_RWU_Reset;
	}
}

//*****************************************************************************
//
// USART_LINBreakDetectLengthConfig
//
//*****************************************************************************
void USART_LINBreakDetectLengthConfig(uint32_t base,
		uint16_t USART_LINBreakDetectLength)
{
	HWREG(base + USART_O_CR2) &= CR2_LBDL_Mask;
	HWREG(base + USART_O_CR2) |= USART_LINBreakDetectLength;
}

//*****************************************************************************
//
// USART_LINCmd
//
//*****************************************************************************
void USART_LINCmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the LIN mode by setting the LINEN bit in the CR2 register
		//
		HWREG(base + USART_O_CR2) |= CR2_LINEN_Set;
	}
	else
	{
		//
		// Disable the LIN mode by clearing the LINEN bit in the CR2 register
		//
		HWREG(base + USART_O_CR2) &= CR2_LINEN_Reset;
	}
}

//*****************************************************************************
//
// USART_SendData
//
//*****************************************************************************
void USART_SendData(uint32_t base, uint16_t Data)
{
	//
	// Transmit Data
	//
	HWREG(base + USART_O_DR) = (Data & (uint16_t) 0x01FF);
}

//*****************************************************************************
//
// USART_ReceiveData
//
//*****************************************************************************
uint16_t USART_ReceiveData(uint32_t base)
{
	//
	// Receive Data
	//
	return (uint16_t) (HWREG(base + USART_O_DR) & (uint16_t) 0x01FF);
}

//*****************************************************************************
//
// USART_SendBreak
//
//*****************************************************************************
void USART_SendBreak(uint32_t base)
{
	//
	// Send break characters
	//
	HWREG(base + USART_O_CR1) |= CR1_SBK_Set;
}

//*****************************************************************************
//
// USART_SetGuardTime
//
//*****************************************************************************
void USART_SetGuardTime(uint32_t base, uint8_t USART_GuardTime)
{
	//
	// Clear the USART Guard time
	//
	HWREG(base + USART_O_GTPR) &= GTPR_LSB_Mask;
	//
	// Set the USART guard time
	//
	HWREG(base + USART_O_GTPR) |= (uint16_t) ((uint16_t) USART_GuardTime << 0x08);
}

//*****************************************************************************
//
// USART_SetPrescaler
//
//*****************************************************************************
void USART_SetPrescaler(uint32_t base, uint8_t USART_Prescaler)
{
	//
	// Clear the USART prescaler
	//
	HWREG(base + USART_O_GTPR) &= GTPR_MSB_Mask;
	//
	// Set the USART prescaler
	//
	HWREG(base + USART_O_GTPR) |= USART_Prescaler;
}

//*****************************************************************************
//
// USART_SmartCardCmd
//
//*****************************************************************************
void USART_SmartCardCmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the SC mode by setting the SCEN bit in the CR3 register
		//
		HWREG(base + USART_O_CR3)|= CR3_SCEN_Set;
	}
	else
	{
		//
		// Disable the SC mode by clearing the SCEN bit in the CR3 register
		//
		HWREG(base + USART_O_CR3) &= CR3_SCEN_Reset;
	}
}

//*****************************************************************************
//
// USART_SmartCardNACKCmd
//
//*****************************************************************************
void USART_SmartCardNACKCmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the NACK transmission by setting the NACK bit in the CR3 register
		//
		HWREG(base + USART_O_CR3) |= CR3_NACK_Set;
	}
	else
	{
		//
		// Disable the NACK transmission by clearing the NACK bit in the CR3 register
		//
		HWREG(base + USART_O_CR3) &= CR3_NACK_Reset;
	}
}

//*****************************************************************************
//
// USART_HalfDuplexCmd
//
//*****************************************************************************
void USART_HalfDuplexCmd(uint32_t base, FunctionalState NewState)
{
	USART_TypeDef *USARTx = (USART_TypeDef*) base;

	if (NewState != DISABLE)
	{
		/* Enable the Half-Duplex mode by setting the HDSEL bit in the CR3 register */
		USARTx->CR3 |= CR3_HDSEL_Set;
	}
	else
	{
		//
		// Disable the Half-Duplex mode by clearing the HDSEL bit in the CR3 register
		//
		USARTx->CR3 &= CR3_HDSEL_Reset;
	}
}

//*****************************************************************************
//
// USART_OverSampling8Cmd
//
//*****************************************************************************
void USART_OverSampling8Cmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the 8x Oversampling mode by setting the OVER8 bit in the CR1 register
		//
		HWREG(base + USART_O_CR1) |= CR1_OVER8_Set;
	}
	else
	{
		//
		// Disable the 8x Oversampling mode by clearing the OVER8 bit in the CR1 register
		//
		HWREG(base + USART_O_CR1) &= CR1_OVER8_Reset;
	}
}

//*****************************************************************************
//
// USART_OneBitMethodCmd
//
//*****************************************************************************
void USART_OneBitMethodCmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the one bit method by setting the ONEBITE bit in the CR3 register
		//
		HWREG(base + USART_O_CR3)|= CR3_ONEBITE_Set;
	}
	else
	{
		//
		// Disable the one bit method by clearing the ONEBITE bit in the CR3 register
		//
		HWREG(base + USART_O_CR3) &= CR3_ONEBITE_Reset;
	}
}

//*****************************************************************************
//
// USART_IrDAConfig
//
//*****************************************************************************
void USART_IrDAConfig(uint32_t base, uint16_t USART_IrDAMode)
{
	HWREG(base + USART_O_CR3) &= CR3_IRLP_Mask;
	HWREG(base + USART_O_CR3) |= USART_IrDAMode;
}

//*****************************************************************************
//
// USART_IrDACmd
//
//*****************************************************************************
void USART_IrDACmd(uint32_t base, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		//
		// Enable the IrDA mode by setting the IREN bit in the CR3 register
		//
		HWREG(base + USART_O_CR3) |= CR3_IREN_Set;
	}
	else
	{
		//
		// Disable the IrDA mode by clearing the IREN bit in the CR3 register
		//
		HWREG(base + USART_O_CR3) &= CR3_IREN_Reset;
	}
}

//*****************************************************************************
//
// USART_GetFlagStatus
//
//*****************************************************************************
FlagStatus USART_GetFlagStatus(uint32_t base, uint16_t USART_FLAG)
{
	FlagStatus bitstatus = RESET;

	if ((HWREG(base + USART_O_SR) & USART_FLAG) != (uint16_t) RESET)
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}
	return bitstatus;
}

//*****************************************************************************
//
// USART_ClearFlag
//
//*****************************************************************************
void USART_ClearFlag(uint32_t base, uint16_t USART_FLAG)
{

	HWREG(base + USART_O_SR) = (uint16_t) ~USART_FLAG;
}

//*****************************************************************************
//
// USART_GetITStatus
//
//*****************************************************************************
ITStatus USART_GetITStatus(uint32_t base, uint16_t USART_IT)
{
	uint32_t bitpos = 0x00, itmask = 0x00, usartreg = 0x00;
	ITStatus bitstatus = RESET;

	//
	// Get the USART register index
	//
	usartreg = (((uint8_t) USART_IT) >> 0x05);
	//
	// Get the interrupt position
	//
	itmask = USART_IT & IT_Mask;
	itmask = (uint32_t) 0x01 << itmask;

	//
	// The IT is in CR1 register
	//
	if (usartreg == 0x01)
	{
		itmask &= HWREG(base + USART_O_CR1);
	}
	//
	// The IT is in CR2 register
	//
	else if (usartreg == 0x02)
	{
		itmask &= HWREG(base + USART_O_CR2);
	}
	//
	// The IT is in CR3 register
	//
	else
	{
		itmask &= HWREG(base + USART_O_CR3);
	}

	bitpos = USART_IT >> 0x08;
	bitpos = (uint32_t) 0x01 << bitpos;
	bitpos &= HWREG(base + USART_O_SR);
	if ((itmask != (uint16_t) RESET) && (bitpos != (uint16_t) RESET))
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}

	return bitstatus;
}

//*****************************************************************************
//
// USART_ClearITPendingBit
//
//*****************************************************************************
void USART_ClearITPendingBit(uint32_t base, uint16_t USART_IT)
{
	uint16_t bitpos = 0x00, itmask = 0x00;

	bitpos = USART_IT >> 0x08;
	itmask = ((uint16_t) 0x01 << (uint16_t) bitpos);
	HWREG(base + USART_O_SR) = (uint16_t) ~itmask;
}

