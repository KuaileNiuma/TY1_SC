/**
 *************************************************************************************
 * @file adc_ex07_ppb_offset.c
 * @brief This file contains the ADC example implementation for example adc_ex07_ppb_offset.
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

#include "adc_ex07_board.h"
#include <stdio.h>

//*****************************************************************************
//
// Global Variables 
//
//*****************************************************************************
int16_t myADC0Results[4];  //!< Buffer for results
volatile uint16_t bufferFull;                 //!< Flag to indicate buffer is full

//*****************************************************************************
//
// adc_A1_irq_handler - ADC A Interrupt 1 ISR
//
//*****************************************************************************
__INTERRUPT void adcA1ISR(void)
{
    //
    // Clear the interrupt flag
    //
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);

    //
    // Get the latest PPB Conversion results
    //
    myADC0Results[0] = ADC_readPPBResult(myADC0_RESULT_BASE, ADC_PPB_NUMBER1);
    myADC0Results[1] = ADC_readPPBResult(myADC0_RESULT_BASE, ADC_PPB_NUMBER2);
    myADC0Results[2] = ADC_readPPBResult(myADC0_RESULT_BASE, ADC_PPB_NUMBER3);
    myADC0Results[3] = ADC_readPPBResult(myADC0_RESULT_BASE, ADC_PPB_NUMBER4);

    bufferFull = 1;;

    //
    // Check if overflow has occurred
    //
    if (true == ADC_getInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    }
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
void main(void)
{
	alb32r003x_evb_init();

    printf("ADC EXT07 SOC PPB OFFSET.\r\n");
    //
    // Board Initialization
    // - Set up the ADC and initialize the SOC
    // - Enable ADC interrupt
    //
    Board_init();

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    CPU_enableIrq();

    // Loop indefinitely
    //
    while (1)
    {
        bufferFull = 0;
        while (ADC_isBusy(myADC0_BASE));
        ADC_forceMultipleSOC(myADC0_BASE, ADC_FORCE_SOC0);

        delay_ms(500);
        while(bufferFull == 0);
    	printf("ADCPPB1 = %d\r\n", myADC0Results[0]);
    	printf("ADCPPB2 = %d\r\n", myADC0Results[1]);
    	printf("ADCPPB3 = %d\r\n", myADC0Results[2]);
    	printf("ADCPPB4 = %d\r\n", myADC0Results[3]);
    	bufferFull = 0;

    }
}
