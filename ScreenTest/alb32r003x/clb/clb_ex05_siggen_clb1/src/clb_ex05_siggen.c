/**
 *************************************************************************************
 * @file clb_ex05_siggen.c
 * @brief This file contains the source file for example clb_ex05_siggen.
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
#include "clb.h"
#include "cpufeature.h"
#include "alb32r003x_evb.h"

#include "clb_ex05_board.h"
#include "clb_ex05_config.h"
#include "alb32r003x_screenTest.h"

volatile int ErrorFlag;

__INTERRUPT void clb2ISR(void);

// GPREG settings:
// bit 2 = enable
// bit 1 = ISR end flag
// bit 0 not used
uint32_t gpreg1 = 1;


bool error_low = false;
bool error_hi  = false;


int main(void)
{
	uint64_t start_cycle;
	uint64_t timeout_cycle;

	ErrorFlag = 0;

	alb32r003x_evb_init();

	CPU_enableIrq();

    Interrupt_register(CLB2_IRQn, &clb2ISR);

    //
    // initialize CLB tiles
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB2);

    Board_init();

    initTILE1(myTILE1_BASE);
    initTILE2(myTILE2_BASE);

    //
    // enable interrupts
    //
    Interrupt_enable(CLB2_IRQn);

    //
    // enable CLB counters
    //
    HWREG(0x3100) = 0x6;
    HWREG(0x3500) = 0x6;
    CLB_setGPREG(myTILE1_BASE, gpreg1);

    printf("CLB EX05 siggen test: CLB1 square wave, CLB2 checks duty/period limits...\r\n");

    //
    // Wait for several CLB check windows. With default limits the CLB1 square
    // wave is within spec so no CLB2 error interrupt is expected -> PASS.
    // If the limits are tightened (e.g. TILE2_COUNTER_1_MATCH1_VAL=400) the
    // CLB2 error interrupt fires, ErrorFlag is set -> FAIL.
    //
    timeout_cycle = 180000000ULL / 5ULL;   // ~200ms at 180MHz
    start_cycle = __get_rv_cycle();
    while (ErrorFlag == 0)
    {
        if ((__get_rv_cycle() - start_cycle) > timeout_cycle)
        {
            break;
        }
    }

    if (ErrorFlag != 0)
    {
        printf("CLB siggen FAIL: CLB2 error interrupt triggered (ErrorFlag=%d)\r\n",
                (int)ErrorFlag);
        return SC_FAIL;
    }

    printf("CLB siggen PASS: CLB1 square wave within CLB2 duty/period limits\r\n");
    return SC_PASS;
}

__INTERRUPT void clb2ISR(void)
{
	ErrorFlag = 1;
}

//
// end of file //
//
