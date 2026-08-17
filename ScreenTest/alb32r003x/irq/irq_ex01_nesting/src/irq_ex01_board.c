/**
 *************************************************************************************
 * @file irq_ex01_board.c
 * @brief This file contains the source file for example irq_ex01_board.
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

#ifdef __cplusplus
extern "C"{
#endif

//*****************************************************************************
//
// Include Files   
//                                
//*****************************************************************************

#include "irq_ex01_board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
    USART_init();
    TIM_init();
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void USART_init()
{
	//
	// Configure USART structure for USART communication
	//
	USART_InitTypeDef USART_InitStruct = { 0 };
	//
	// Set communication parameters
	//
	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    //
    //Turn on the USART2 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_USART2);

	//
	// Initialize and enable USART interface
	//
	USART_Init(myUSART_BASE,SystemClock_Get_APBL(),&USART_InitStruct);
	USART_ITConfig(myUSART_BASE, USART_IT_IDLE, ENABLE);
	USART_Cmd(myUSART_BASE, ENABLE);
}
//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void TIM_init()
{
	TIMER_InitTypeDef TIMER_InitStruct;
	TIMER_InitStruct.cfg.mode = TIMER_USER_DEFINED_MODE;
	TIMER_InitStruct.cfg.irq_en = TIMER_INT_ENABLE;
	TIMER_InitStruct.cfg.count = 100000;
	TIMER_InitStruct.cfg.on100pwm_en = TIMER_ON100PWM_DISABLE;
	TIMER_InitStruct.cfg.pwm_en = TIMER_PWM_DISABLE;
	TIMER_InitStruct.cfg.count2 = 0;
	TIMER_InitStruct.channel = TIMER_CHANNEL1;

	TIMER_init(myTIMER_BASE , &TIMER_InitStruct);

	TIMER_start(myTIMER_BASE , TIMER_CHANNEL1);
}

#ifdef __cplusplus

#endif

