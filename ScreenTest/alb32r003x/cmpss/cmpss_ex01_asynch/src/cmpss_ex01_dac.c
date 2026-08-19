/**
 *************************************************************************************
 * @file cmpss_ex01_dac.c
 * @brief This file contains the source file for example cmpss_ex01_dac.
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

#ifdef __cplusplus
extern "C"{
#endif

#include "stdio.h"
#include "device.h"
#include "cmpss_ex01_board.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"

//
// Function Prototypes
//
void initEPWM(void);
//
// Main
//

void main(void)
{
    alb32r003x_evb_init();

    //
    // Set up ePWM7 to take CTRIPH as TRIP4 for its DC trip input
    //
    initEPWM();

    //
    // Board Initialization
    // - Configure GPIO14 to output CTRIPOUT1H (routed through XBAROUTPUT3)
    // - Setup the Output X-BAR to output CTRIPOUTH on OUTPUTXBAR3
    // - Configure the high comparator of CMPSS1
    // - Enable CMPSS and configure the negative input signal to come from
    //   the DAC
    // - Use VDDA as the reference for the DAC and set DAC value to midpoint for
    //   arbitrary reference.
    // - Configure the output signals. Both CTRIPH and CTRIPOUTH will be fed by
    //   the asynchronous comparator output.
    //
    Board_init();


    //
    // Configure GPIO13 to output CTRIPH (routed through ePWM TRIP4 and ePWM7)
    //
    GPIO_setPinConfig(GPIO_13_EPWM7_B);

    //
    // Set DAC output 1.25V to CMPSS_HN
    //
    CMPSS_setDACValueHigh(myCMPSS0_BASE,1551U);

    //
    // Loop indefinitely
    //
    while(1)
    {

        //
        // Trip flag is set when CTRIP signal is asserted
        //
        if((EPWM_getTripZoneFlagStatus(EPWM7_BASE) &
            EPWM_TZ_FLAG_OST) != 0U)
        {
            //
            // Wait for comparator CTRIP to de-assert
            //
            while((CMPSS_getStatus(CMPSS1_BASE) & CMPSS_STS_HI_FILTOUT) != 0U)
            {
                ;
            }

            //
            // Clear trip flags
            //
            EPWM_clearTripZoneFlag(EPWM7_BASE, EPWM_TZ_INTERRUPT |
                                   EPWM_TZ_FLAG_OST);
        }
    }
}

//
// initEPWM - Function to configure ePWM7 and the ePWM X-BAR to take CTRIPH as
//            the DC trip input
//
void initEPWM(void)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM7);

    //
    // Disable the ePWM time base clock before configuring the module
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Set the time base clock prescalers to /1
    //
    EPWM_setClockPrescaler(EPWM7_BASE, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    //
    // Initializing dummy values for ePWM counter and period
    //
    EPWM_setTimeBaseCounter(EPWM7_BASE, 0);
    EPWM_setTimeBasePeriod(EPWM7_BASE, 0xFFFF);

    //
    // Put the time base counter into up-count mode
    //
    EPWM_setTimeBaseCounterMode(EPWM7_BASE, EPWM_COUNTER_MODE_UP);

    //
    // Set-up compare
    //
    EPWM_setCounterCompareValue(EPWM7_BASE, EPWM_COUNTER_COMPARE_B, 0x8000);

    //
    // Set actions
    //
    EPWM_setActionQualifierAction(EPWM7_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    EPWM_setActionQualifierAction(EPWM7_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    // Configure ePWM7B to output high on TZB TRIP

    //
    EPWM_setTripZoneAction(EPWM7_BASE, EPWM_TZ_ACTION_EVENT_TZB,
                           EPWM_TZ_ACTION_HIGH);
    EPWM_setTripZoneAction(EPWM7_BASE, EPWM_TZ_ACTION_EVENT_DCBEVT1,
    		EPWM_TZ_ACTION_DISABLE);

    //
    // Configure DCBH to use TRIP4 as an input
    //
    EPWM_selectDigitalCompareTripInput(EPWM7_BASE,EPWM_DC_TRIP_TRIPIN4,EPWM_DC_TYPE_DCBH);

    //
    // Trigger event when DCBH is high
    //
    EPWM_setTripZoneDigitalCompareEventCondition(EPWM7_BASE,
                                                 EPWM_TZ_DC_OUTPUT_B1,
												 EPWM_TZ_EVENT_DCXH_HIGH);

    //
    // Enable DCB as OST
    //
    EPWM_enableTripZoneSignals(EPWM7_BASE, EPWM_TZ_SIGNAL_DCBEVT1);

    //
    // Configure TRIP4 to be CTRIP1H using the ePWM X-BAR
    //
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX00_CMPSS1_CTRIPH);
    XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX00);

    //
    // Clear trip flags
    //
    EPWM_clearTripZoneFlag(EPWM7_BASE, EPWM_TZ_INTERRUPT |
                           EPWM_TZ_FLAG_OST);

    //
    // Sync the ePWM time base clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

}

