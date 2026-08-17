/**
 *************************************************************************************
 * @file wdt_ex03_wdg_feed.c
 * @brief This file contains the source file for example wdt_ex03_wdg_feed.
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
#include "alb32r003x_evb.h"
//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
WDT_InitTypeDef myConfig = {0};  //!< WDT configuration structure


//*****************************************************************************
//
// WDT initialization function
//
//*****************************************************************************
void mywdt_init(void)
{
    //
    // Configure WDT reset mode to generate interrupt and reset
    //
    myConfig.RMOD = WDT_RMODE_IRQRST;

    //
    // Set reset pulse length to 2 cycles
    //
    myConfig.RPL = WDT_RPL_2CYCLES;

    //
    // Set timeout period to 0x8000000
    //
    myConfig.TOP = WDT_TIMEOUTPERIOD_H800000;

    //
    // Initialize WDT with configuration parameters
    //
    WDT_init(WDT1_BASE,&myConfig);
}


//*****************************************************************************
//
// WDT system reset test function
//
//*****************************************************************************
void wdt_system_reset_test(void)
{
    //
    // Print test information
    //
    printf("Watchdog Timer System Reset Mode Test. . . \n");

    //
    // Initialize WDT with configuration
    //
    mywdt_init();
    
    //
    // Start WDT counter
    //
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

	alb32r003x_evb_init();
    //
    // Print test information
    //
    printf("wdt EX03 wdg feed.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Start WDT system reset test
    //
    wdt_system_reset_test();

    //
    // Infinite loop to feed the watchdog and prevent reset
    //
    while(1)
    {
        //
        // Feed the WDT to prevent reset
        //
        WDT_feed(WDT1_BASE);
    }
}
