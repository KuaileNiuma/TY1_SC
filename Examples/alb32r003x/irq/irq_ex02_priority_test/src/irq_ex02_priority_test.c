/**
 *************************************************************************************
 * @file irq_ex02_priority_test.c
 * @brief This file contains the definition of source file  for example irq_ex02_priority_test.
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
#include "alb32r003x_evb.h"

#include "irq_ex02_board.h"

// Global test flag
volatile uint32_t lowIrqBusyFlag = 0;
volatile uint32_t highIrqPreemptCnt = 0;

/**
 * @brief Low priority timer ISR(Prio=5), simulate long computation
 */
__INTERRUPT void Timer_Low_ISR(void)
{
    SAVE_IRQ_CSR_CONTEXT();

    lowIrqBusyFlag = 1;
    printf("[LOW_IRQ] Enter low priority long task, waiting possible preempt...\r\n");

    // Simulate long-time loop calculation (easily be preempted)
    for(uint32_t i = 0; i < 80000; i++)
    {
        // If high priority interrupt triggered, count record
        if(highIrqPreemptCnt > 0)
        {
            printf("[LOW_IRQ] Detected high priority preempt during my execution!\r\n");
            highIrqPreemptCnt = 0;
        }
    }

    printf("[LOW_IRQ] Low priority task finished\r\n");
    lowIrqBusyFlag = 0;

    // Clear timer pending bit
    TIMER_clearInterruptPending(TIM_LOW_BASE, TIMER_CHANNEL1);
    RESTORE_IRQ_CSR_CONTEXT();
}

/**
 * @brief High priority timer ISR(Prio=1), real-time urgent task
 * Can preempt low priority interrupt
 */
__INTERRUPT void Timer_High_ISR(void)
{
    SAVE_IRQ_CSR_CONTEXT();

    highIrqPreemptCnt++;
    printf("[HIGH_IRQ] Real-time urgent task execute, preempt flag ++\r\n");

    // Short real-time business logic
    for(uint32_t i = 0; i < 1000; i++);

    TIMER_clearInterruptPending(TIM_HIGH_BASE, TIMER_CHANNEL1);
    RESTORE_IRQ_CSR_CONTEXT();
}

//*****************************************************************************
// Main entry
//*****************************************************************************
int main(void)
{
    alb32r003x_evb_init();

    // Enable global interrupt switch
    CPU_enableIrq();

    // 1. Register & Config Low Priority Timer Interrupt (Preemption Priority = 5)
    Interrupt_register(TIM_LOW_IRQn, Timer_Low_ISR);
    Interrupt_setPriority(TIM_LOW_IRQn, 5, 0);
    Interrupt_enable(TIM_LOW_IRQn);

    // 2. Register & Config High Priority Timer Interrupt (Preemption Priority = 1)
    // Smaller number = Higher priority, can preempt priority 5 interrupt
    Interrupt_register(TIM_HIGH_IRQn, Timer_High_ISR);
    Interrupt_setPriority(TIM_HIGH_IRQn, 1, 0);
    Interrupt_enable(TIM_HIGH_IRQn);

    // Init USART & Timer hardware
    Board_PriorityTest_Init();

    printf("========== Interrupt Priority & Real-Time Response Test Start ==========\r\n");
    printf("Rule: TIM1(Prio5 Low) long task, TIM2(Prio1 High) real-time task\r\n");
    printf("High priority IRQ will preempt low priority IRQ when low task running\r\n\r\n");

    while (1)
    {
        // Main loop idle, all test logic run in interrupt
    }
    return 0;
}

