/**
 *************************************************************************************
 * @file timer_ex01_irq.c
 * @brief This file contains the source file for example timer_ex01_irq.
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
    // Toggle the test GPIO pin
    //
    GPIO_togglePin(TEST_GPIO_PIN);
    
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
    // Configure GPIO pin for output
    //
    GPIO_setPinConfig(GPIO_0_GPIO0);
    GPIO_setDirectionMode(TEST_GPIO_PIN, GPIO_DIR_MODE_OUT);
    
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
	alb32r003x_evb_init();
    //
    // Print example information
    //
    printf("TIMER EX01 IRQ.\r\n");

    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Initialize board hardware
    //
    Board_init();

    //
    // Wait for test completion
    //
    while(Timer_ex1_TestDone == 0);
    
    //
    // Infinite loop
    //
    for(;;);
}
