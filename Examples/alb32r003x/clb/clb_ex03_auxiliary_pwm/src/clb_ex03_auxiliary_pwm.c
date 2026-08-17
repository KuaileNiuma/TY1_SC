/**
 *************************************************************************************
 * @file clb_ex03_auxiliary_pwm.c
 * @brief This file contains the source file for example clb_ex03_auxiliary_pwm.
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

#include "clb_ex03_board.h"
#include "clb_ex03_config.h"

#define EDA_CSIM                  0             //!< set to 1 when make target for simulation

#if EDA_CSIM != 0
#define LOG_LEVEL                 LOG_ERROR
void _putchar(char character)
{
    //
    // Do nothing
    //
}
#else
#define LOG_LEVEL                 LOG_INFO
#endif

#define LED_STA_PIN     GPIO_PIN_LED2

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
static volatile uint16_t dutyValue = 200;

__INTERRUPT void clb1ISR(void);
//*****************************************************************************
//
// Global Functions Definitions
//
//*****************************************************************************

int main(void) {

	alb32r003x_evb_init();

	CPU_enableIrq();

    //
    // Register interrupt handler using C function
    //
    Interrupt_register(CLB1_IRQn, clb1ISR);

    //
    // Set interrupt priority and enable interrupt
    //
    Interrupt_setPriority(CLB1_IRQn, 0, 0);
    Interrupt_enable(CLB1_IRQn);
    Board_init();

    initTILE1(CLB1_BASE);

    CLB_enableCLB(CLB1_BASE);

	while (1) {

	}

	return 0;
}

__INTERRUPT void clb1ISR(void)
{
    //
    // Change duty cycle of PWM signal at the end of a period
    //
    if (dutyValue == 150)
    {
        dutyValue = 100U;
    }
    else
    {
        dutyValue = 150U;
    }

    //
    // Load new duty cycle value in HLC Registers
    //
    CLB_setHLCRegisters(CLB1_BASE, dutyValue, 0, 0, 0);

    CLB_clearInterruptTag(CLB1_BASE);
}
