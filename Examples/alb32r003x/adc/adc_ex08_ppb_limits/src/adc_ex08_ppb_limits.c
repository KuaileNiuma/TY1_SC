/**
 *************************************************************************************
 * @file adc_ex08_ppb_limits.c
 * @brief This file contains the ADC example implementation for example adc_ex08_ppb_limits.
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
#include "adc_ex08_board.h"
#include "stdio.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint16_t myADC0Results[RESULTS_BUFFER_SIZE];  //!< Buffer for results
volatile uint16_t evtFlag;                 //!< Flag to indicate buffer is full

//*****************************************************************************
//
// adcA1ISR - ADC A PPB EVENT ISR
//
//*****************************************************************************
__INTERRUPT void adcAEvtISR(void)
{
    //
    // Clear the interrupt flag
    //
	ADC_clearPPBEventStatus(myADC0_BASE, ADC_PPB_NUMBER1,ADC_EVT_TRIPHI);

    //
    // Get the latest Conversion results
    //
    myADC0Results[0] = ADC_readResult(myADC0_RESULT_BASE, ADC_SOC_NUMBER0);

    //
    //ADC conversion value reaches the set threshold
    //
    evtFlag = 1;
    ADC_disablePPBEventInterrupt(myADC0_BASE, ADC_PPB_NUMBER1, ADC_EVT_TRIPHI);

}

//*****************************************************************************
//
// main
//
//*****************************************************************************
void main(void)
{
	alb32r003x_evb_init();

    printf("ADC EXT08 PPB LIMITS.\r\n");
    //
    // Board Initialization
    // - Set up the ADC and initialize the SOC
    // - Enable ADC interrupt
    //
    Board_init();
    evtFlag = 0;

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    CPU_enableIrq();

    //
    // Loop indefinitely
    //
    while (1)
    {
        while (ADC_isBusy(myADC0_BASE))
            ;
        ADC_forceMultipleSOC(myADC0_BASE, ADC_FORCE_SOC0);
        if(evtFlag == 1)
        {
        	printf("ADC conversion value reaches the set threshold!\r\n");
        	printf("ADC has stopped conversion!\r\n");
        	evtFlag = 0;
        }
    }
}
