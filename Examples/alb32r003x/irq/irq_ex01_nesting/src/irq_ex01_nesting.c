/**
 *************************************************************************************
 * @file irq_ex01_nesting.c
 * @brief This file contains the definition of source file  for example irq_ex01_nesting.
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
#include "irq_ex01_board.h"

volatile uint8_t tim_IrqnFlag;

__INTERRUPT void usartISR(void)
{
	//
	//Interrupts with low preemption priority need to save the context
    //
	SAVE_IRQ_CSR_CONTEXT();
    USART_GetITStatus(myUSART_BASE,USART_IT_IDLE);
    while(tim_IrqnFlag < 5);
    tim_IrqnFlag = 0;
    //
    //Restore the context
    //
    RESTORE_IRQ_CSR_CONTEXT();
}

__INTERRUPT void timISR(void)
{
	tim_IrqnFlag++;
	TIMER_clearInterruptPending(myTIMER_BASE , TIMER_CHANNEL1);
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
    uint32_t returnCode;

    alb32r003x_evb_init();
    //
    // Enable global interrupt
    //
    CPU_enableIrq(); 

    Interrupt_register(myUSART_IRQn, usartISR);
    Interrupt_setPriority(myUSART_IRQn, 1, 0);
    Interrupt_enable(myUSART_IRQn);

    Interrupt_register(TIMER1_C1_IRQn, timISR);
    Interrupt_setPriority(TIMER1_C1_IRQn, 5, 0);
    Interrupt_enable(TIMER1_C1_IRQn);

    Board_init();

    while (1)
    {

    }
    return 0;
}

