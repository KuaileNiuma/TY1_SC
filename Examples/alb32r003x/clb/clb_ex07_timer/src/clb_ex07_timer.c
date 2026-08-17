/**
 *************************************************************************************
 * @file clb_ex07_timer.c
 * @brief This file contains the source file for example clb_ex07_timer.
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

#include "clb_ex07_board.h"
#include "clb_ex07_config.h"

__INTERRUPT void clb1ISR(void);

#define RESET_TIMER     1
#define ENABLE_TIMER    2
#define COUNTUP_MODE    4

void main(void)
{

	alb32r003x_evb_init();

	CPU_enableIrq();

    Interrupt_register(CLB1_IRQn, &clb1ISR);
    Interrupt_enable(CLB1_IRQn);

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);

    initTILE1(myTILE1_BASE);
    Board_init();

    CLB_setGPREG(myTILE1_BASE, ENABLE_TIMER | COUNTUP_MODE);

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //

    CLB_clearInterruptTag(myTILE1_BASE);


    while(1)
    {
        delay_ms(2000);
        // Change Timer Value to 2000
        CLB_configCounterLoadMatch(myTILE1_BASE, CLB_CTR0, 0, 2000, 0);
        delay_ms(2000);
        // Change Timer Value to 1000
        CLB_configCounterLoadMatch(myTILE1_BASE, CLB_CTR0, 0, 1000, 0);
        asm(" NOP");
    }
}


__INTERRUPT void clb1ISR(void)
{
    GPIO_togglePin(myGPIO0);
    CLB_clearInterruptTag(myTILE1_BASE);
}

