/**
 *************************************************************************************
 * @file wdt_ex01_wdg_reset.c
 * @brief This file contains the source file for example wdt_ex01_wdg_reset.
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
#include "wdt.h"
#include "clb_board.h"
#include "clb_config.h"

uint32_t nmi_flag;


void NMI()
{
	nmi_flag = 0x10;
}

//*****************************************************************************
//
// Main function
// 
//*****************************************************************************
int main(void)
{

	alb32r003x_evb_init();
    //
    // Print initialization message
    //
    printf("wdt EX05 wdg reset.\r\n");
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_IWDT);

    SysCtl_enableNMI();

    Exception_Register_EXC(NMI_EXCn,(unsigned long)NMI);
    __DSB();
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Initialize board hardware
    //
    Board_134_init();
    
    //
    // Feed the Watchdog Timer to prevent early reset
    //
    WDT_feed(WDT1_BASE);
    
    //
    // Initialize CLB module with TILE1 configuration
    //
    initTILE1_134(myCLB0_BASE);
    
    //
    // Enable CLB module
    //
    CLB_enableCLB(myCLB0_BASE);

    //
    // Infinite loop - WDT will reset the system if not fed periodically
    //
    for(;;);
}
