/**
 *************************************************************************************
 * @file usart_ex01_polling.c
 * @brief This file contains the source file for example usart_ex01_polling.
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
// Global Variables
//
//*****************************************************************************
uint8_t volatile data;           //!< Data buffer for USART communication

//*****************************************************************************
//
// USART Initialization Function
// 
//*****************************************************************************
void usart_init(uint32_t Base, uint32_t baud)
{

	//
	// Configure USART structure for USART communication
	//
	USART_InitTypeDef USART_InitStruct = { 0 };
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
	// Initialize and enable USART interface
	//
	USART_Init(Base,SystemClock_Get_APBL(),&USART_InitStruct);
	USART_Cmd(Base, ENABLE);
}

//*****************************************************************************
//
// USART Example Initialization Function
// 
//*****************************************************************************
void usart_ex01_polling(void)
{
    //
    // Configure GPIO pins for USART communication
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    GPIO_setPinConfig(USART_TX_PIN);
    GPIO_setPinConfig(USART_RX_PIN);
    //
    // Initialize USART interface with 9600 baud rate
    //
    usart_init(my_usartBase, 115200);
}

//*****************************************************************************
//
// Main Function
// 
//*****************************************************************************
int main(void)
{
    alb32r003x_evb_init();
    //
    // Initialize USART example
    //

	  usart_ex01_polling();
    //
    // Main loop - implements echo functionality
    //
    while(1)
    {
    	//
    	// Wait for data reception
    	//
    	while (USART_GetFlagStatus(my_usartBase, USART_FLAG_RXNE) == 0);
		//
		// Read received data
		//
		data = USART_ReceiveData(my_usartBase);
		//
		// Wait for transmit complete
		//
		while (USART_GetFlagStatus(my_usartBase, USART_FLAG_TC) == 0);
		//
		// Echo back the received data
		//
		USART_SendData(my_usartBase, data);
    }
}
