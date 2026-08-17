/**
 *************************************************************************************
 * @file ecap_ex06_intr_phase_shift.c
 * @brief This file contains the source file for example ecap_ex06_intr_phase_shift.
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
#include "ecap_ex06_board.h"
#include "device.h"
#include <stdio.h>



uint32_t shiftPhase;     //!< Variable to track the current phase shift value


//__INTERRUPT static void EcapISR(void);


//*****************************************************************************
//
// main - Main function for ECAP interrupt phase shift example
// 
//  This function initializes the board components and sets up the initial phase
//  shift value, then enters an infinite loop. The ECAP interrupt handler will
//  dynamically adjust the phase shift during runtime.
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();
    //
    // Board initialization
    // Select eCAP1OUT on MUX 0. Make GPIO5 as eCAP1OUT for PWM output
    // Select eCAP2OUT on MUX 2. Make GPIO6 as eCAP2OUT for PWM output
    // Configure eCAP1 in APWM mode with defined period and duty values
    // Polarity as low and configure SYNCOUT at CTR=PRD
    //
    Board_init();

    //
    // Initialize shifting phase
    //
    shiftPhase = 0U;

    while(1)
    {
        //
        // Main loop - Do nothing
        //
    }
}

//*****************************************************************************
//
// EcapISR - ECAP interrupt handler for phase shifting
// 
//  This interrupt handler is triggered when an ECAP interrupt occurs. It
//  increments the phase shift value, updates the ECAP APWM period and compare
//  values, sets the new phase shift, and clears the interrupt flags.
//
//*****************************************************************************
__INTERRUPT void EcapISR(void)
{
    //
    // Add phase value
    //
    shiftPhase += 1U;
    if(shiftPhase > 4000)shiftPhase = 0;

    //
    // Set eCAP APWM period
    //
    if(shiftPhase %10 == 0)
    {

		ECAP_setAPWMShadowPeriod (myECAP1_BASE, PWM_PRD_VAL);  //shiftPhase + 2000U

		//
		// Set eCAP APWM on or off time count
		//
		ECAP_setAPWMShadowCompare(myECAP1_BASE, PWM_CMP_VAL);  //shiftPhase + 1000U

		//
		// Sets a phase shift value count
		//
		ECAP_setPhaseShiftCount(myECAP1_BASE, shiftPhase);
		ECAP_loadCounter(myECAP1_BASE);
    }
    //
    // Clear interrupt flags for more interrupts
    //
    ECAP_clearInterrupt(myECAP1_BASE, ECAP_ISR_SOURCE_COUNTER_PERIOD);
    ECAP_clearGlobalInterrupt(myECAP1_BASE);

    //
    // Reset the counter
    //
}
#ifdef __cplusplus
}
#endif
