/**
 *************************************************************************************
 * @file timer.c
 * @brief This file implements the function of timer driver.
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


#include "timer.h"


//*****************************************************************************
//
// TIMER_clearInterruptPending
//
//*****************************************************************************
void TIMER_clearInterruptPending(uint32_t base, int channel)
{
    uint32_t reg;
    reg = HWREG(base + TIMERx_O_EOI(channel));
}

//*****************************************************************************
//
// TIMER_getInterruptStatus
//
//*****************************************************************************
FlagStatus TIMER_getInterruptStatus(uint32_t base , int channel)
{
    ITStatus bitstatus = RESET;

    if (HWREG(base + TIMERS_O_ISR) & (0x1 << (channel)))
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
// TIMER_init
//
//*****************************************************************************
void TIMER_init(uint32_t base , TIMER_InitTypeDef *TIMER_InitStruct)
{
    uint32_t temp;
    //
    // Disable TIMER
    //
    HWREG(base + TIMERx_O_CR(TIMER_InitStruct->channel)) &=~TIMER_CR_ENABLE;
    //
    // Clear TIMER interrupt
    //
    temp = HWREG(base + TIMERx_O_EOI(TIMER_InitStruct->channel));

    //
    // Configure running mode and interrupt mask
    //
    temp = HWREG(base + TIMERx_O_CR(TIMER_InitStruct->channel));
    temp &= ~(0x1fUL);
    temp |= (TIMER_InitStruct->cfg.mode & TIMER_CR_MODE);
    temp |= (TIMER_InitStruct->cfg.irq_en & TIMER_CR_INT_MASK);
    temp |= (TIMER_InitStruct->cfg.on100pwm_en & TIMER_ON100PWM_MODE);
    temp |= (TIMER_InitStruct->cfg.pwm_en & TIMER_PWM_MODE);
    HWREG(base + TIMERx_O_CR(TIMER_InitStruct->channel)) = temp;

    //
    // Configure load count
    //
    if (TIMER_InitStruct->cfg.mode == TIMER_USER_DEFINED_MODE)
        HWREG(base + TIMERx_O_LCR(TIMER_InitStruct->channel)) = TIMER_InitStruct->cfg.count;

    HWREG(base + TIMERx_O_LCR2(TIMER_InitStruct->channel)) = TIMER_InitStruct->cfg.count2;
}

//*****************************************************************************
//
// TIMER_start
//
//*****************************************************************************
void TIMER_start(uint32_t base , int channel)
{
    HWREG(base + TIMERx_O_CR(channel)) |= TIMER_CR_ENABLE;
}

//*****************************************************************************
//
// TIMER_stop
//
//*****************************************************************************
void TIMER_stop(uint32_t base , int channel)
{
    HWREG(base + TIMERx_O_CR(channel)) &= ~(TIMER_CR_ENABLE);
}

//*****************************************************************************
//
// TIMER_getCurrentCnt
//
//*****************************************************************************
uint32_t TIMER_getCurrentCnt(uint32_t base , int channel)
{
    return HWREG(base + TIMERx_O_CVR(channel));
}






