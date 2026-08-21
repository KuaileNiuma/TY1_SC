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

#include "wdt_ex01_wdg_reset.h"
#include <stdio.h>
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"
#include "cpufeature.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
WDT_InitTypeDef myConfig = {0};   //!< WDT configuration structure


//*****************************************************************************
//
// Initializes the Watchdog Timer
// 
//*****************************************************************************
void mywdt_init(void)
{
    //
    // Configure WDT reset mode to interrupt and reset
    //
    myConfig.RMOD = WDT_RMODE_IRQRST;
    
    //
    // Set reset pulse length to 2 cycles
    //
    myConfig.RPL = WDT_RPL_2CYCLES;
    
    //
    // Set timeout period to 8,000,000 clock cycles
    //
    myConfig.TOP = WDT_TIMEOUTPERIOD_H8000000;

    //
    // Initialize WDT with the configuration
    //
    WDT_init(WDT1_BASE,&myConfig);
}


//*****************************************************************************
//
// Performs WDT system reset test
// 
//*****************************************************************************
void wdt_system_reset_test(void)
{
    //
    // Print test information
    //
    printf("Watchdog Timer System Reset Mode Test. . . \n");

    //
    // Initialize and start WDT
    //
    mywdt_init();
    WDT_start(WDT1_BASE);
    
    //
    // Indicate waiting for system reset
    //
    printf("                - - - Wait System Reset.\n");
}

//*****************************************************************************
//
// Main function
// 
//*****************************************************************************
int main(void)
{
    uint64_t start_cycle;
    uint32_t cur0;
    uint32_t cur1;

	alb32r003x_evb_init();
    //
    // Print example information
    //
    printf("wdt EX01 wdg reset.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Start WDT system reset test
    //
    wdt_system_reset_test();

    //
    // Verify the watchdog counter is running: read it twice with a short delay.
    // If it decreases, the watchdog is working and a system reset is imminent.
    //
    cur0 = WDT_get_curval(WDT1_BASE);
    start_cycle = __get_rv_cycle();
    while ((__get_rv_cycle() - start_cycle) < 20000000ULL)
    {
    }
    cur1 = WDT_get_curval(WDT1_BASE);

    if (cur1 < cur0)
    {
        printf("WDT system reset test OK: counter running, system will be reset soon.\r\n");
        return SC_PASS;
    }

    printf("WDT system reset test FAIL: watchdog counter is not running.\r\n");
    return SC_FAIL;
}
