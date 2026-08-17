/**
 *************************************************************************************
 * @file ecap_ex04_sw_sync.c
 * @brief This file contains the source file for example ecap_ex04_sw_sync.
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
#include "ecap_ex04_board.h"
#include "device.h"
#include <stdio.h>


//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define PWM1_TIMER_MIN     50U    //!< Minimum PWM1 timer period
#define PWM1_TIMER_MAX     8000U    //!< Maximum PWM1 timer period
#define EPWM_TIMER_UP      1U       //!< ePWM timer up direction flag
#define EPWM_TIMER_DOWN    0U       //!< ePWM timer down direction flag

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
bool firstInterrupt;              //!< Flag to indicate first interrupt
uint32_t ecap3IntCount;           //!< eCAP3 interrupt counter
uint32_t ecapPassCount;           //!< Successful capture counter
uint32_t ecapErrorCount;          //!< Error capture counter
uint32_t epwm1TimerDirection;     //!< ePWM1 timer direction flag
volatile uint32_t epwm1PeriodCount; //!< ePWM1 period count value
volatile uint32_t ecap1Cap1Count;  //!< eCAP1 capture 1 count value
volatile uint32_t ecap1Cap2Count;  //!< eCAP1 capture 2 count value
volatile uint32_t ecap1Cap3Count;  //!< eCAP1 capture 3 count value
volatile uint32_t ecap1Cap4Count;  //!< eCAP1 capture 4 count value
volatile uint32_t ecap2Cap1Count;  //!< eCAP2 capture 1 count value
volatile uint32_t ecap2Cap2Count;  //!< eCAP2 capture 2 count value
volatile uint32_t ecap2Cap3Count;  //!< eCAP2 capture 3 count value
volatile uint32_t ecap2Cap4Count;  //!< eCAP2 capture 4 count value
volatile uint32_t ecap3Cap1Count;  //!< eCAP3 capture 1 count value
volatile uint32_t ecap3Cap2Count;  //!< eCAP3 capture 2 count value
volatile uint32_t ecap3Cap3Count;  //!< eCAP3 capture 3 count value
volatile uint32_t ecap3Cap4Count;  //!< eCAP3 capture 4 count value
//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void initEPWM(void);
static void error(void);
void main(void);
__INTERRUPT void Ecap3ISR(void);
void Unregister_ecap_ex04(void);

//*****************************************************************************
//
// initEPWM - Configure ePWM module
// 
//  This function configures the ePWM1 module in up-count mode with toggle
//  action on period match, and sets up the initial period and compare values.
//
//*****************************************************************************
static void initEPWM(void)
{
    //
    //Turn on the ECAP1 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Disable sync (Freeze clock to PWM as well)
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    //
    // Configure ePWM
    //   Counter runs in up-count mode.
    //   Action qualifier will toggle output on period match
    //
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_setTimeBasePeriod(EPWM1_BASE, PWM1_TIMER_MIN);
    EPWM_setPhaseShift(EPWM1_BASE, 0U);
    EPWM_setActionQualifierAction(EPWM1_BASE,
                                EPWM_AQ_OUTPUT_A,
                                EPWM_AQ_OUTPUT_TOGGLE,
                                EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setClockPrescaler(EPWM1_BASE,
                            EPWM_CLOCK_DIVIDER_1,
                            EPWM_HSCLOCK_DIVIDER_2);

    epwm1TimerDirection = EPWM_TIMER_UP;

    //
    // Enable sync and clock to PWM
    //
     SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

//*****************************************************************************
//
// error - Increment error counter
// 
//  This function increments the eCAP error counter when a synchronization
//  error is detected during the eCAP interrupt handling.
//
//*****************************************************************************
static void error(void)
{
    ecapErrorCount++;
}

//*****************************************************************************
//
// main - Main application function
// 
//  This function initializes the board components, configures ePWM, and enters
//  an infinite loop to allow for eCAP interrupt handling and PWM frequency
//  modulation.
//
//*****************************************************************************

void main(void)
{
	alb32r003x_evb_init();
    //
    // Board initialization
    // Configure GPIO 3 as eCAP input
    // Enable interrupts required for this example
    //
    Board_init();
    //
    // Configure ePWM
    //
    initEPWM();
    //
    // Initialize counters and values
    //
    firstInterrupt = true;
    ecap3IntCount = 0U;
    ecapPassCount = 0U;
    ecapErrorCount = 0U;
    epwm1PeriodCount = 0U;
    ecap1Cap1Count = 0U;
    ecap1Cap2Count = 0U;
    ecap1Cap3Count = 0U;
    ecap1Cap4Count = 0U;
    ecap2Cap1Count = 0U;
    ecap2Cap2Count = 0U;
    ecap2Cap3Count = 0U;
    ecap2Cap4Count = 0U;
    ecap3Cap1Count = 0U;
    ecap3Cap2Count = 0U;
    ecap3Cap3Count = 0U;
    ecap3Cap4Count = 0U;

    //
    // Loop forever. Suspend or place breakpoints to observe the buffers.
    //
    while(1)
    {
    }
}

//*****************************************************************************
//
// Ecap3ISR - eCAP3 interrupt handler
// 
//  This function handles eCAP3 interrupts, captures event timestamps from
//  multiple eCAP modules, validates synchronization between modules, and
//  adjusts the ePWM frequency in a sawtooth pattern.
//
//*****************************************************************************
__INTERRUPT void Ecap3ISR(void)
{
	EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
    //
    // Get the capture counts. Each capture should match for all the eCAPs.
    //
    ecap1Cap1Count = ECAP_getEventTimeStamp(myECAP1_BASE, ECAP_EVENT_1);
    ecap1Cap2Count = ECAP_getEventTimeStamp(myECAP1_BASE, ECAP_EVENT_2);
    ecap1Cap3Count = ECAP_getEventTimeStamp(myECAP1_BASE, ECAP_EVENT_3);
    ecap1Cap4Count = ECAP_getEventTimeStamp(myECAP1_BASE, ECAP_EVENT_4);
    ecap2Cap1Count = ECAP_getEventTimeStamp(myECAP2_BASE, ECAP_EVENT_1);
    ecap2Cap2Count = ECAP_getEventTimeStamp(myECAP2_BASE, ECAP_EVENT_2);
    ecap2Cap3Count = ECAP_getEventTimeStamp(myECAP2_BASE, ECAP_EVENT_3);
    ecap2Cap4Count = ECAP_getEventTimeStamp(myECAP2_BASE, ECAP_EVENT_4);
    ecap3Cap1Count = ECAP_getEventTimeStamp(myECAP3_BASE, ECAP_EVENT_1);
    ecap3Cap2Count = ECAP_getEventTimeStamp(myECAP3_BASE, ECAP_EVENT_2);
    ecap3Cap3Count = ECAP_getEventTimeStamp(myECAP3_BASE, ECAP_EVENT_3);
    ecap3Cap4Count = ECAP_getEventTimeStamp(myECAP3_BASE, ECAP_EVENT_4);
    //
    // Compare the period value with the captured count
    //
    epwm1PeriodCount = EPWM_getTimeBasePeriod(EPWM1_BASE);
    //
    // Validate synchronization.
    //
    if(firstInterrupt)
    {
        firstInterrupt = false;
    }
    else
    {
        if (!((ecap1Cap1Count == ecap2Cap1Count)&&(ecap2Cap1Count == ecap3Cap1Count)))
        {
            error();
        }
    }
    if (!((ecap1Cap2Count == ecap2Cap2Count)&&(ecap2Cap2Count == ecap3Cap2Count)))
    {
        error();
    }
    if (!((ecap1Cap3Count == ecap2Cap3Count)&&(ecap2Cap3Count == ecap3Cap3Count)))
    {
        error();
    }
    if (!((ecap1Cap4Count == ecap2Cap4Count)&&(ecap2Cap4Count == ecap3Cap4Count)))
    {
        error();
    }
    //
    // Increment interrupt counter
    //
    ecap3IntCount++;
    //
    // Keep track of the ePWM direction and adjust period accordingly to
    // generate a variable frequency PWM.
    //
    if(epwm1TimerDirection == EPWM_TIMER_UP)
    {
        if(epwm1PeriodCount < PWM1_TIMER_MAX)
        {
            EPWM_setTimeBasePeriod(EPWM1_BASE, ++epwm1PeriodCount);
        }
        else
        {
            epwm1TimerDirection = EPWM_TIMER_DOWN;
            EPWM_setTimeBasePeriod(EPWM1_BASE, ++epwm1PeriodCount);
        }
    }
    else
    {
        if(epwm1PeriodCount > PWM1_TIMER_MIN)
        {
            EPWM_setTimeBasePeriod(EPWM1_BASE, --epwm1PeriodCount);
        }
        else
        {
            epwm1TimerDirection = EPWM_TIMER_UP;
            EPWM_setTimeBasePeriod(EPWM1_BASE, ++epwm1PeriodCount);
        }
    }
    //
    // Count correct captures
    //
    ecapPassCount++;
    //
    // Clear interrupt flags for more interrupts.
    //
    ECAP_clearInterrupt(myECAP3_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(myECAP3_BASE);
    //
    // Start eCAP
    //
    ECAP_reArm(myECAP1_BASE);
    ECAP_reArm(myECAP2_BASE);
    ECAP_reArm(myECAP3_BASE);

    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);

}

//*****************************************************************************
//
// Unregister_ecap_ex04 - Interrupt unregistering function
// 
//  This function is used to unregister the eCAP3 interrupt handler when needed.
//
//*****************************************************************************
void Unregister_ecap_ex04(void)
{
    //
    // Interrupt unregistering implementation can be added here if needed
    //
}


#ifdef __cplusplus
}
#endif
