/**
 *************************************************************************************
 * @file adc_ex05_soc_continuous.c
 * @brief This file contains the ADC example implementation for example adc_ex05_soc_continuous.
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

#include "adc_ex05_board.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint16_t myADC0Results[RESULTS_BUFFER_SIZE] = {0}; 		//!< Buffer for results
volatile uint16_t bufferFull;       					//!< Flag to indicate buffer is full
volatile uint16_t myindex;                              //!< Index into result buffer


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
	// Get the latest Conversion results
	//
    myADC0Results[myindex] = ADC_readResult(myADC0_RESULT_BASE, ADC_SOC_NUMBER0);
    myindex++;
    if(myindex == RESULTS_BUFFER_SIZE)
    {
    	bufferFull = 1;
    	ADC_disableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
    }

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
// main - Application entry point
//
//*****************************************************************************
void main(void)
{
	alb32r003x_evb_init();

	printf("ADC EXT05 SOC CONTINUOUS.\r\n");
	//
	// Board Initialization
	// Set up the ADC and initialize the SOC
	// Enable ADC interrupt
	//
	Board_init();

	bufferFull = 0;

	//
	// Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
	//
	CPU_enableIrq();

	ADC_forceMultipleSOC(myADC0_BASE, ADC_FORCE_SOC0);

	//
	// Loop indefinitely
	//
	while (1)
	{
        //
        // When the results buffer is filled, the bufferFull flag will be set.
        //
        while (bufferFull == 0);

        for (myindex = 0; myindex < RESULTS_BUFFER_SIZE; myindex++)
        {
            printf("sampleValue = %d\r\n", myADC0Results[myindex]);
        }

        //
        // Clear the buffer full flag
        //
        bufferFull = 0;
        myindex = 0;

        //
        //Wait 1s Start next ADC conversions
        //
        delay_ms(1000);
        ADC_enableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
        ADC_forceMultipleSOC(myADC0_BASE, ADC_FORCE_SOC0);
	}
}
