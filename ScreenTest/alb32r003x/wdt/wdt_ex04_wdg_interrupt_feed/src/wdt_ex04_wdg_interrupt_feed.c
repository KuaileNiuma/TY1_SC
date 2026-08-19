/**
 *************************************************************************************
 * @file wdt_ex04_wdg_interrupt_feed.c
 * @brief This file contains the source file for example wdt_ex04_wdg_interrupt_feed.
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
#include "alb32r003x_screenTest.h"
//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
WDT_InitTypeDef myConfig = {0};    //!< WDT configuration structure
WDT_TypeDef* mywdt_intstance;      //!< WDT instance pointer

#define WDT_TEST_TIME        0x0C  //!< WDT test time value (if WDT clock is 20M, interrupt or reset after (2^(16+11)/2000000))
uint32_t test_count = 0;           //!< Test counter for WDT interrupts

//*****************************************************************************
//
// WDT Interrupt Service Routine
//
//*****************************************************************************
__INTERRUPT void wdtISR(void)
{
    //
    // Clear the WDT interrupt flag
    //
    WDT_clearInterruptFlag(WDT1_BASE);
    
    //
    // Feed the WDT to prevent reset
    //
    WDT_feed(WDT1_BASE);
    
    //
    // Increment test counter
    //
    test_count++;
}

//*****************************************************************************
//
// CPU delay function
//
//*****************************************************************************
void cpu_delay(volatile unsigned int delay_ticks)
{
    //
    // Delay loop
    //
    while(delay_ticks--);
}
//*****************************************************************************
//
// Interrupt initialization function
//
//*****************************************************************************
void INTERRUPT_init()
{
    //
    // Register WDT interrupt handler
    //
    Interrupt_register(WDT_IRQn, wdtISR);
    
    //
    // Set WDT interrupt priority
    //
    Interrupt_setPriority(WDT_IRQn, 0, 0);
    
    //
    // Enable WDT interrupt
    //
    Interrupt_enable(WDT_IRQn);
    
    //
    // Enable ECLIC for WDT interrupt
    //
    ECLIC_EnableIRQ(WDT_IRQn);
}
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
    myConfig.TOP = WDT_TIMEOUTPERIOD_H8000000;

    //
    // Initialize WDT with configuration parameters
    //
    WDT_init(WDT1_BASE,&myConfig);
}

//*****************************************************************************
//
// WDT watchdog test function
//
//*****************************************************************************
void wdt_feed_test(void)
{
    //
    // Initialize WDT with configuration
    //
    mywdt_init();
    
    //
    // Initialize interrupts
    //
    INTERRUPT_init();
    
    //
    // Start WDT counter
    //
    WDT_start(WDT1_BASE);

    //
    // Infinite loop with small delays
    //
    while(1)
    {
        cpu_delay(100);
    }
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
    printf("wdt EX04 wdg irq and feed dog.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Start WDT watchdog test
    //
    wdt_feed_test();

    //
    // Infinite loop (will not be reached)
    //
    return SC_PASS;
}
