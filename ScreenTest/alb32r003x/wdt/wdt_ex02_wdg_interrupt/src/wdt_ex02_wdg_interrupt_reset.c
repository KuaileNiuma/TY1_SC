/**
 *************************************************************************************
 * @file wdt_ex02_wdg_interrupt_reset.c
 * @brief This file contains the source file for example wdt_ex02_wdg_interrupt_reset.
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
WDT_InitTypeDef myConfig = {0};           //!< WDT configuration structure
WDT_TypeDef* mywdt_intstance;             //!< WDT instance pointer

//
// WDT test time configuration
// If WDT clock is 20MHz, interrupt or reset occurs after (2^(16+11)/2000000) seconds
//
#define WDT_TEST_TIME        0x0C

uint32_t test_count = 0;                  //!< Test counter for WDT interrupts

//*****************************************************************************
//
// WDT Interrupt Service Routine
//
//*****************************************************************************
__INTERRUPT void wdtISR(void)
{
    
    //
    // Increment the interrupt counter
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
    // Busy-wait loop for delay
    //
    while(delay_ticks--);
}
//*****************************************************************************
//
// Initializes the interrupt system for WDT
//
//*****************************************************************************
void INTERRUPT_init(void)
{
    //
    // Register the WDT interrupt handler
    //
    Interrupt_register(WDT_IRQn, wdtISR);
    
    //
    // Set the WDT interrupt priority to highest
    //
    Interrupt_setPriority(WDT_IRQn, 0, 0);
    
    //
    // Enable the WDT interrupt
    //
    Interrupt_enable(WDT_IRQn);
    ECLIC_EnableIRQ(WDT_IRQn);
}
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
// Performs WDT interrupt and feed test
//
//*****************************************************************************
void wdt_feed_test(void)
{
    //
    // Initialize WDT
    //
    mywdt_init();
    
    //
    // Initialize interrupt system
    //
    INTERRUPT_init();
    
    //
    // Start WDT
    //
    WDT_start(WDT1_BASE);

    //
    // Main test loop - WDT is fed in the interrupt handler
    //
    while(1)
    {
        //
        // Small delay
        //
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
    // Print example information
    //
    printf("wdt EX02 wdg irq and feed dog.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Start WDT interrupt and feed test
    //
    wdt_feed_test();

    //
    // Infinite loop (should not be reached)
    //
    for(;;);
}
