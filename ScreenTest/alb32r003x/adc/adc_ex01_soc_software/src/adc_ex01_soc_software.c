/**
 *************************************************************************************
 * @file adc_ex01_soc_software.c
 * @brief This file contains the definition of source file for example adc_ex01_soc_software.
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
#include "adc_ex01_board.h"
#include "alb32r003x_evb.h"

uint16_t myADC0Result0[128] = {0};
uint16_t myADC0Result1[128] = {0};
uint16_t myADC1Result0[128] = {0};
uint16_t myADC1Result1[128] = {0};

//*****************************************************************************
//
// adc_ex1_soc_software
//
//*****************************************************************************
void adc_ex1_soc_software(void)
{
    uint32_t i;

    //
    // Set up ADCs, initializing the SOCs to be triggered by software
    //
    Board_init();

    while (1)
    {
        for(i = 0;i < 128;i++)
        {
            //
            // Convert, wait for completion, and store results
            //
            ADC_forceMultipleSOC(myADC0_BASE, ADC_FORCE_SOC0 | ADC_FORCE_SOC1);
            //
            // Wait for ADCA to complete, then acknowledge flag
            //
            while (ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false)
            {
            }
            ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
            //
            // Convert, wait for completion, and store results
            //
            ADC_forceMultipleSOC(myADC1_BASE, ADC_FORCE_SOC0 | ADC_FORCE_SOC1);
            //
            // Wait for ADCA to complete, then acknowledge flag
            //
            while (ADC_getInterruptStatus(myADC1_BASE, ADC_INT_NUMBER1) == false)
            {
            }
            ADC_clearInterruptStatus(myADC1_BASE, ADC_INT_NUMBER1);
            //
            //store results
            //
            myADC0Result0[i] = ADC_readResult(myADC0_RESULT_BASE, ADC_SOC_NUMBER0);
            myADC0Result1[i] = ADC_readResult(myADC0_RESULT_BASE, ADC_SOC_NUMBER1);
            myADC1Result0[i] = ADC_readResult(myADC1_RESULT_BASE, ADC_SOC_NUMBER0);
            myADC1Result1[i] = ADC_readResult(myADC1_RESULT_BASE, ADC_SOC_NUMBER1);
        }
        printf("-----ADCA Sample Value: -----\r\n");
        for(i = 0;i < 8;i++)
        {
            printf("sampleValue = %d\r\n", myADC0Result0[i]);
        }
        printf("-----ADCB Sample Value: -----\r\n");
        for(i = 0;i < 8;i++)
        {
            printf("%d\r\n", myADC1Result0[i]);
        }
        printf("-----------\r\n");
        delay_ms(100);
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

    //
    // Enable global interrupt
    //
    CPU_enableIrq(); 

    adc_ex1_soc_software();

    while (1)
    {

    }
    return 0;
}

