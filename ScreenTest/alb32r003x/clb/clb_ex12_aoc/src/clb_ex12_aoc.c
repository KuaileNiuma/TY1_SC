/**
 *************************************************************************************
 * @file clb_ex12_aoc.c
 * @brief This file contains the source file for example clb_ex12_aoc.
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

//
// Included Files
//
#include "device.h"
#include "alb32r003x_evb.h"

#include "clb_ex12_board.h"
#include "clb_ex12_config.h"
//
// Main
//
void main(void)
{
	alb32r003x_evb_init();

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);

    Board_init();

    //
    // Implement AND Gate between GPIO0 and GPIO1
    // Implement AOC Invert functionality turning the GATE to a NAND
    // Implement AOC Gate Control as an AND GATE on top of the logic
    // AOC Gate Control will use SW GATE register
    //
    initTILE1(myCLBForTILE1_BASE);

    CLB_enableCLB(myCLBForTILE1_BASE);

    //
    // Gate the NAND implemented
    // Switch the value of the GATE control to 'false' and the logic will
    // be gated.
    //
    CLB_writeSWGateControl(myCLBForTILE1_BASE, CLB_SW_GATE_CTRL4, true);

    while(1)
    {

        asm(" NOP");
    }
}

//
// End of File
//
