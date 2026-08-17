/**
 *************************************************************************************
 * @file clb_ex09_interrupt_tag.c
 * @brief This file contains the source file for example clb_ex09_interrupt_tag.
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



#include "device.h"
#include "clb.h"
#include "alb32r003x_evb.h"

#include "clb_ex09_board.h"
#include "clb_ex09_config.h"

__INTERRUPT void clb1ISR(void);

#define COUNTER0_TIMER_ENABLE     0x1


#define COUNTER0_INT_TAG    11
#define COUNTER1_INT_TAG    12


void main(void)
{
	alb32r003x_evb_init();

	CPU_enableIrq();

    Interrupt_register(CLB1_IRQn, &clb1ISR);
    Interrupt_enable(CLB1_IRQn);

    //
    // Enabling CLB1
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);

    Board_init();

    initTILE1(myTILE1_BASE);

    CLB_setGPREG(myTILE1_BASE, COUNTER0_TIMER_ENABLE);

    CLB_clearInterruptTag(myTILE1_BASE);


    while(1)
    {
        asm(" NOP");
    }
}


__INTERRUPT void clb1ISR(void)
{
    uint16_t tag = CLB_getInterruptTag(myTILE1_BASE);
    if (tag == COUNTER0_INT_TAG)
    {
        GPIO_togglePin(myGPIO0);
    }
    if (tag == COUNTER1_INT_TAG)
    {
        GPIO_togglePin(myGPIO1);
    }

    CLB_clearInterruptTag(myTILE1_BASE);
}

