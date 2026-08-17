/**
 *************************************************************************************
 * @file adc_ex04_soc_software_sync.c
 * @brief This file contains the ADC example implementation for example adc_ex04_soc_software_sync.
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
#include "adc_ex04_board.h"
#include "stdio.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define RESULTS_BUFFER_SIZE 15             //!< Results buffer size
#define myADC0_BASE ADCA_BASE               //!< ADC0 module base address
#define myADC0_RESULT_BASE ADCARESULT_BASE  //!< ADC0 result register base address

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint16_t myADC0Results[RESULTS_BUFFER_SIZE];    //!< Buffer for results
uint16_t myADC1Results[RESULTS_BUFFER_SIZE];    //!< Buffer for results
uint16_t myindex1;                               //!< Index into result buffer
uint16_t myindex2;                               //!< Index into result buffer
volatile uint16_t bufferFull;                   //!< Flag to indicate buffer is full

void initEPWM(void);

//*****************************************************************************
//
// adc_A1_irq_handler - ADC A Interrupt 1 ISR
//
//*****************************************************************************
__INTERRUPT void adcA1ISR(void)
{
    //
    // Add the latest result to the buffer
    //
    myADC0Results[myindex1++] = ADC_readResult(myADC0_RESULT_BASE,
            ADC_SOC_NUMBER0);
    myADC0Results[myindex1++] = ADC_readResult(myADC0_RESULT_BASE,
            ADC_SOC_NUMBER1);
    myADC0Results[myindex1++] = ADC_readResult(myADC0_RESULT_BASE,
            ADC_SOC_NUMBER2);

    myADC1Results[myindex2++] = ADC_readResult(myADC1_RESULT_BASE,
            ADC_SOC_NUMBER0);
    myADC1Results[myindex2++] = ADC_readResult(myADC1_RESULT_BASE,
            ADC_SOC_NUMBER1);
    myADC1Results[myindex2++] = ADC_readResult(myADC1_RESULT_BASE,
            ADC_SOC_NUMBER2);

    if(myindex1 == RESULTS_BUFFER_SIZE && myindex2 == RESULTS_BUFFER_SIZE)
    {
    	bufferFull = 1;
    	ADC_disableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
    }

    //
    // Clear the interrupt flag
    //
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);

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
// Function to configure ePWM1 to generate the SOC.
//
//*****************************************************************************
void initEPWM(void)
{
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Disable SOCA
    //
    EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    //
    // Configure the SOC to occur on the first up-count event
    //
    EPWM_setADCTriggerSource(EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_U_CMPA);
    EPWM_setADCTriggerEventPrescale(EPWM1_BASE, EPWM_SOC_A, 1);
    //
    // Set the compare A value to 1000 and the period to 1999
    // Assuming ePWM clock is 20MHz, this would give 10kHz sampling
    // 50MHz ePWM clock would give 25kHz sampling, etc.
    // The sample rate can also be modulated by changing the ePWM period
    // directly (ensure that the compare A value is less than the period).
    //
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 1000);
    EPWM_setTimeBasePeriod(EPWM1_BASE, 1999);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0);
    //
    // Set the local ePWM module clock divider to /1
    //
    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_1);
    //
    // Freeze the counter
    //
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
void main(void)
{
	alb32r003x_evb_init();

    printf("ADC EXT04 SOC EPWM.\r\n");
    //
    // Board Initialization
    // - Set up the ADC and initialize the SOC
    // - Enable ADC interrupt
    //
    Board_init();

    //
    // Initialize results buffer
    //
    for (myindex1 = 0; myindex1 < RESULTS_BUFFER_SIZE; myindex1++)
    {
        myADC0Results[myindex1] = 0;
    }
    myindex1 = 0;
    for (myindex2 = 0; myindex2 < RESULTS_BUFFER_SIZE; myindex2++)
    {
        myADC0Results[myindex2] = 0;
    }
    myindex2 = 0;
    bufferFull = 0;

    // Set up the ePWM
    initEPWM();

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    CPU_enableIrq();

    //
    // Start ePWM1, enabling SOCA and putting the counter in up-count mode
    //
    EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Loop indefinitely
    //
    while (1)
    {
        //
        // Wait while ePWM1 causes ADC conversions which then cause interrupts.
        // When the results buffer is filled, the bufferFull flag will be set.
        //
        while (bufferFull == 0);

        //
        // Stop ePWM1, disabling SOCA and freezing the counter
        //
        EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
        EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);

        for (myindex1 = 0; myindex1 < RESULTS_BUFFER_SIZE; myindex1++)
        {
            printf("ADCA11 = %d\r\n", myADC0Results[myindex1]);
        }
        for (myindex2 = 0; myindex2 < RESULTS_BUFFER_SIZE; myindex2++)
        {
            printf("ADCB10 = %d\r\n", myADC0Results[myindex2]);
        }

        //
        // Clear the buffer full flag
        //
        bufferFull = 0;
        myindex1 = 0;
        myindex2 = 0;

        //
        //Wait 1s Start next ADC conversions
        //
        delay_ms(1000);
        ADC_enableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
        EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
        EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);

    }
}
