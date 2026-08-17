/**
 *************************************************************************************
 * @file adc_ex14_soc_software.c
 * @brief This file contains the definition of source file for example adc_ex14_soc_software.
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
#include "adc_ex14_board.h"

#define TIMER_BASE   TIMER1_BASE
#define TIMER_CH     TIMER_CHANNEL1

uint16_t myADC0Result;

static const struct timer_cfg t_cfg =
{
TIMER_USER_DEFINED_MODE,
TIMER_INT_ENABLE,
2000000,
TIMER_ON100PWM_DISABLE,
TIMER_PWM_DISABLE,
0xFFFF,
};

static TIMER_InitTypeDef timerInit =
{
    TIMER_CH,t_cfg,
};

__INTERRUPT static void timer1ISR(void)
{
    TIMER_clearInterruptPending(TIMER_BASE, TIMER_CH);
}

void timer_init()
{
    Interrupt_register(TIMER1_C1_IRQn, timer1ISR);
    Interrupt_setPriority(TIMER1_C1_IRQn, 0, 0);
    Interrupt_enable(TIMER1_C1_IRQn);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER1);
    TIMER_init(TIMER_BASE,&timerInit);
    TIMER_start(TIMER_BASE, TIMER_CH);
}

//*****************************************************************************
//
// adc_ex14_soc_software
//
//*****************************************************************************
void adc_ex14_soc_cput(void)
{
    //
    // Set up ADCs, initializing the SOCs to be triggered by software
    //
    Board_init();
    timer_init();
    while (1)
    {
        //
        // Wait for ADCA to complete, then acknowledge flag
        //
        while (ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false)
        {
        }
        ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
        //
        //store results
        //
        myADC0Result = ADC_readResult(myADC0_RESULT_BASE, ADC_SOC_NUMBER0);
        printf("ADC value:%d\r\n",myADC0Result);
    }
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
    printf("ADC EXT14 SOC CPUT.\r\n");
    //
    // Enable global interrupt
    //
    CPU_enableIrq();
    adc_ex14_soc_cput();

    while (1)
    {

    }
    return 0;
}

