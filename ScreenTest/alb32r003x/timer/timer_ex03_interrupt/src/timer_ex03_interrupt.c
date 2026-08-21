/**
 *************************************************************************************
 * @file timer_EX03_irq.c
 * @brief This file contains the source file for example timer_EX03_irq.
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
#include "timer.h"
#include "debug.h"
#include "interrupt.h"
#include "alb32r003x_evb.h"
#include "cpufeature.h"

#include "mytimer.h"
#include "alb32r003x_screenTest.h"


//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
TIMER_InitTypeDef TIMER1_InitStruct = {0};  //!< Timer1 initialization structure

#ifdef ILM_DLM_ENABLE
SRAM_BSS_T volatile uint32_t Timer_ex1_IntCnt = 0;    //!< Timer interrupt counter
SRAM_BSS_T volatile uint32_t Timer_ex1_TestDone = 0;  //!< Test completion flag
//ILM_FUNC_T void mytimerCHISR(void);
#else
volatile uint32_t Timer_ex1_IntCnt = 0;    //!< Timer interrupt counter
volatile uint32_t Timer_ex1_TestDone = 0;  //!< Test completion flag
void mytimerCHISR(void);
#endif

//*****************************************************************************
//
// Timer Interrupt Service Routine
//
//*****************************************************************************
#ifdef USE_HARD_SP
void timer_irq_entry(void);
void mytimerCHISR(void)
#else
__INTERRUPT void mytimerCHISR(void)
#endif
{
    //
    // Clear the timer interrupt pending flag
    //
    TIMER_clearInterruptPending(MY_TIMER_BASE, MY_TIMER_CHANNEL);
    
    //
    // Increment the interrupt counter
    //
    Timer_ex1_IntCnt++;
    
    //
    // Stop timer after 16 interrupts and set test done flag
    //
    if(Timer_ex1_IntCnt >= 16)
    {
        TIMER_stop(MY_TIMER_BASE, MY_TIMER_CHANNEL);
        Timer_ex1_TestDone = 1;
    }
}

//*****************************************************************************
//
// Initializes Timer Module
//
//*****************************************************************************
void timer_init( void )
{
    //
    // Enable the timer peripheral clock
    //
    SysCtl_enablePeripheral(MY_TIMER_CLK_EN);

    //
    // Configure timer channel and instance
    //
    TIMER1_InitStruct.channel = MY_TIMER_CHANNEL;
    //
    // Set timer period and enable interrupt
    //
    TIMER1_InitStruct.cfg.count = TIMER_PERIOD;
    TIMER1_InitStruct.cfg.irq_en = TIMER_INT_ENABLE;
    TIMER1_InitStruct.cfg.mode = TIMER_USER_DEFINED_MODE;

    //
    // Disable PWM functionality
    //
    TIMER1_InitStruct.cfg.count2 = 0;
    TIMER1_InitStruct.cfg.on100pwm_en = TIMER_ON100PWM_DISABLE;
    TIMER1_InitStruct.cfg.pwm_en = TIMER_PWM_DISABLE;

    //
    // Initialize the timer with configured parameters
    //
    TIMER_init(MY_TIMER_BASE, &TIMER1_InitStruct);

    //
    // Initialize the timer interrupt IRQ
    //
#ifdef USE_HARD_SP
    //
    // Register interrupt handler using hard SP
    //
    Interrupt_register(MY_TIMER_IRQ, timer_irq_entry); // implement in timer_irq.S
#else
    //
    // Register interrupt handler using C function
    //
    Interrupt_register(MY_TIMER_IRQ, mytimerCHISR);
#endif

    //
    // Set interrupt priority and enable interrupt
    //
    Interrupt_setPriority(MY_TIMER_IRQ, 0, 0);
    Interrupt_enable(MY_TIMER_IRQ);

    //
    // Start the timer
    //
    TIMER_start(MY_TIMER_BASE, MY_TIMER_CHANNEL);
}

//*****************************************************************************
//
// Initializes Board Hardware
//
//*****************************************************************************
void Board_init()
{
    //
    // Initialize timer and interrupts
    //
    timer_init();
    
}

//*****************************************************************************
//
// Main function
//
//*****************************************************************************
int main(void)
{
    uint32_t sys_clk;
    uint32_t apbl_clk;
    uint32_t clk_div;
    uint64_t start_cycle;
    uint64_t timeout_cycle;

	alb32r003x_evb_init();
    //
    // Print example information
    //
    printf("TIMER EX03 IRQ.\r\n");

    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Initialize board hardware
    //
    Board_init();

    //
    // Compute a frequency-scaled timeout in CPU cycles.
    // 16 interrupts need 16 * TIMER_PERIOD timer clocks; the timer clock is
    // at most the APBL clock, so scale by SystemClock/APBL and keep 10x margin.
    // The cycle count is independent of CPU frequency and memory location.
    //
    sys_clk = SystemClock_Get();
    apbl_clk = SystemClock_Get_APBL();
    clk_div = (apbl_clk == 0) ? 1U : (sys_clk / apbl_clk);
    start_cycle = __get_rv_cycle();
    timeout_cycle = 16ULL * TIMER_PERIOD * clk_div * 10U;

    //
    // Wait for test completion
    //
    while(Timer_ex1_TestDone == 0)
    {
        if((__get_rv_cycle() - start_cycle) > timeout_cycle)
        {
            printf("TIMER EX03 IRQ FAIL: timeout.\r\n");
            return SC_FAIL;
        }
    }

    if(Timer_ex1_IntCnt >= 16)
    {
        printf("TIMER EX03 IRQ PASS.\r\n");
        return SC_PASS;
    }

    printf("TIMER EX03 IRQ FAIL: count=%d\r\n", (int)Timer_ex1_IntCnt);
    return SC_FAIL;
}
