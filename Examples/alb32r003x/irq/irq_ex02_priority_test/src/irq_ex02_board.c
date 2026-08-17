/**
 *************************************************************************************
 * @file irq_ex02_board.c
 * @brief This file contains the source file for example irq_ex02_board.
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

#include "irq_ex02_board.h"


//*****************************************************************************
// Board unified initialization entry
//*****************************************************************************
void Board_PriorityTest_Init(void)
{
    DbgUSART_Init();
    Timer_LowPriority_Init();
    Timer_HighPriority_Init();
}

//*****************************************************************************
// Debug USART 115200
//*****************************************************************************
void DbgUSART_Init(void)
{
    USART_InitTypeDef USART_InitStruct = { 0 };

    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;

    // Enable peripheral clock
    SysCtl_enablePeripheral(DBG_USART_CLK_EN);

    USART_Init(DBG_USART_BASE, SystemClock_Get_APBL(), &USART_InitStruct);
    USART_Cmd(DBG_USART_BASE, ENABLE);
}

//*****************************************************************************
// Low priority timer: TIM1 CH1, 100ms interrupt, simulate long-time calculation
//*****************************************************************************
void Timer_LowPriority_Init(void)
{
    TIMER_InitTypeDef TIMER_InitStruct;

    TIMER_InitStruct.cfg.mode = TIMER_USER_DEFINED_MODE;
    TIMER_InitStruct.cfg.irq_en = TIMER_INT_ENABLE;
    TIMER_InitStruct.cfg.count = 100000;
    TIMER_InitStruct.cfg.on100pwm_en = TIMER_ON100PWM_DISABLE;
    TIMER_InitStruct.cfg.pwm_en = TIMER_PWM_DISABLE;
    TIMER_InitStruct.cfg.count2 = 0;
    TIMER_InitStruct.channel = TIMER_CHANNEL1;

    SysCtl_enablePeripheral(TIM_LOW_CLK_EN);
    TIMER_init(TIM_LOW_BASE, &TIMER_InitStruct);
    TIMER_start(TIM_LOW_BASE, TIMER_CHANNEL1);
}

//*****************************************************************************
// High priority timer: TIM2 CH1, 20ms urgent real-time task
//*****************************************************************************
void Timer_HighPriority_Init(void)
{
    TIMER_InitTypeDef TIMER_InitStruct;

    TIMER_InitStruct.cfg.mode = TIMER_USER_DEFINED_MODE;
    TIMER_InitStruct.cfg.irq_en = TIMER_INT_ENABLE;
    TIMER_InitStruct.cfg.count = 20000;
    TIMER_InitStruct.cfg.on100pwm_en = TIMER_ON100PWM_DISABLE;
    TIMER_InitStruct.cfg.pwm_en = TIMER_PWM_DISABLE;
    TIMER_InitStruct.cfg.count2 = 0;
    TIMER_InitStruct.channel = TIMER_CHANNEL1;

    SysCtl_enablePeripheral(TIM_HIGH_CLK_EN);
    TIMER_init(TIM_HIGH_BASE, &TIMER_InitStruct);
    TIMER_start(TIM_HIGH_BASE, TIMER_CHANNEL1);
}

#ifdef __cplusplus
}
#endif

