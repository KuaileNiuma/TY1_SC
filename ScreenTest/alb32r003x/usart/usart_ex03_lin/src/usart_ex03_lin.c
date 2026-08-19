/**
 *************************************************************************************
 * @file lin_ex03_master_irq.c
 * @brief This file contains the source file for example lin_ex03_master_irq.
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
#include <stdio.h>
#include "device.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"
//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define my_usartBase         	USART1_BASE
#define USART_TX_PIN			GPIO_22_USARTA_TX
#define USART_RX_PIN			GPIO_23_USARTA_RX
#define my_USART_CLK_EN       	SYSCTL_PERIPH_CLK_USART1

//*****************************************************************************
//
// USART Initialization Function
// 
//*****************************************************************************
void usart_init(uint32_t Base, uint32_t baud)
{
	//
	// Configure USART structure for LIN communication
	//
	USART_InitTypeDef USART_InitStruct = {0};
	//
	// Set communication parameters
	//
	USART_InitStruct.USART_BaudRate = baud;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    //
    //Turn on the USART1 peripheral clock
    //
    SysCtl_enablePeripheral(my_USART_CLK_EN);
	//
	// Initialize USART and enable LIN mode
	//
	USART_Init(my_usartBase,SystemClock_Get_APBL(), &USART_InitStruct);
	USART_LINCmd(my_usartBase, ENABLE);
	//
	// Enable USART module
	//
	USART_Cmd(Base, ENABLE);
}

//*****************************************************************************
//
// USART Master Mode Initialization Function
// 
//*****************************************************************************
void usart_ex03_lin(void)
{
    //
    // Configure GPIO pins for USART communication
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    GPIO_setPinConfig(USART_TX_PIN);
    GPIO_setPinConfig(USART_RX_PIN);
    //
    // Initialize USART interface in master mode with 9600 baud rate
    //
    usart_init(my_usartBase, 9600);

    //
    // Enable global interrupts
    //
    CPU_enableIrq();
}

//*****************************************************************************
//
// Main Function
// 
//*****************************************************************************
int main(void)
{
    uint32_t returnCode;  //!< Return code variable
    
    alb32r003x_evb_init();
    //
    // Initialize LIN in master mode
    //
    usart_ex03_lin();
    
    //
    // Send LIN break signal to start communication
    //
    USART_SendBreak(my_usartBase);
    
    //
    // Main loop - implements LIN master echo functionality
    //
    return SC_PASS;
}
