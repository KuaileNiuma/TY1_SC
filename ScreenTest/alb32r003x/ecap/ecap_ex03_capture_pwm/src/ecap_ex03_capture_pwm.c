/**
 *************************************************************************************
 * @file ecap_ex03_capture_pwm.c
 * @brief This file contains the source file for example ecap_ex03_capture_pwm.
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
#include "ecap_ex03_board.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define PWM1_TIMER_MIN     500U    //!< Minimum PWM1 timer period
#define PWM1_TIMER_MAX     8000U    //!< Maximum PWM1 timer period
#define EPWM_TIMER_UP      1U       //!< ePWM timer up direction flag
#define EPWM_TIMER_DOWN    0U       //!< ePWM timer down direction flag

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t ecap1IntCount;         //!< eCAP interrupt counter
uint32_t ecap1PassCount;        //!< Successful capture counter
uint32_t ecap1ErrorCount;       //!< Error capture counter
uint32_t epwm1TimerDirection;   //!< ePWM1 timer direction flag
uint16_t cap2Count;             //!< eCAP capture 2 count value
uint16_t cap3Count;             //!< eCAP capture 3 count value
uint16_t cap4Count;             //!< eCAP capture 4 count value
uint16_t epwm1PeriodCount;      //!< ePWM1 period count value
uint16_t PeriodFine = 0;        //!< Fine period adjustment value

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void initEPWM(void);
static void error(void);
void main(void);
extern __INTERRUPT void Ecap1ISR(void);

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
    //Turn on the EPWM1 peripheral clock
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
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_2);
    //
    // Set initial timer direction
    //
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
//  This function increments the eCAP error counter when a capture error
//  is detected during the eCAP interrupt handling.
//
//*****************************************************************************
static void error(void)
{
    ecap1ErrorCount++;
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
    // Initialize counters
    //
    cap2Count = 0U;
    cap3Count = 0U;
    cap4Count = 0U;
    ecap1IntCount = 0U;
    ecap1PassCount = 0U;
    ecap1ErrorCount = 0U;
    epwm1PeriodCount = 0U;
    //
    // Loop forever. Suspend or place breakpoints to observe the buffers.
    //
    while (1)
    {
    }
}

//*****************************************************************************
//
// Ecap1ISR - eCAP1 interrupt handler
// 
//  This function handles eCAP1 interrupts, captures event timestamps,
//  validates capture values against expected periods, and adjusts the
//  ePWM frequency in a sawtooth pattern.
//
//*****************************************************************************
__INTERRUPT void Ecap1ISR(void)
{
    //
    // Get the capture counts. Each capture should be 2x the ePWM count
    // because of the ePWM clock divider.
    //
    cap2Count = ECAP_getEventTimeStamp(myECAP1_BASE, ECAP_EVENT_2);
    cap3Count = ECAP_getEventTimeStamp(myECAP1_BASE, ECAP_EVENT_3);
    cap4Count = ECAP_getEventTimeStamp(myECAP1_BASE, ECAP_EVENT_4);
    //
    // Compare the period value with the captured count
    //
    epwm1PeriodCount = EPWM_getTimeBasePeriod(EPWM1_BASE);
    //
    // Validate capture 2 count against expected value
    //
    if (cap2Count > ((epwm1PeriodCount * 2) + 2U)
            || cap2Count < ((epwm1PeriodCount * 2) - 2U))
    {
        error();
    }
    //
    // Validate capture 3 count against expected value
    //
    if (cap3Count > ((epwm1PeriodCount * 2) + 2U)
            || cap3Count < ((epwm1PeriodCount * 2) - 2U))
    {
        error();
    }
    //
    // Validate capture 4 count against expected value
    //
    if (cap4Count > ((epwm1PeriodCount * 2) + 2U)
            || cap4Count < ((epwm1PeriodCount * 2) - 2U))
    {
        error();
    }
    //
    // Increment interrupt counter
    //
    ecap1IntCount++;
    //
    // Keep track of the ePWM direction and adjust period accordingly to
    // generate a variable frequency PWM.
    //
    if (epwm1TimerDirection == EPWM_TIMER_UP)
    {
        if (epwm1PeriodCount < PWM1_TIMER_MAX)
        {
            EPWM_setTimeBasePeriod(EPWM1_BASE, ++epwm1PeriodCount);
        }
        else
        {
            epwm1TimerDirection = EPWM_TIMER_DOWN;
            EPWM_setTimeBasePeriod(EPWM1_BASE, --epwm1PeriodCount);
        }
    }
    else
    {
        if (epwm1PeriodCount > PWM1_TIMER_MIN)
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
    ecap1PassCount++;
    //
    // Clear interrupt flags for more interrupts.
    //
    ECAP_clearInterrupt(myECAP1_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(myECAP1_BASE);
    //
    // Start eCAP
    //
    ECAP_reArm(myECAP1_BASE);
}

#ifdef __cplusplus
}
#endif
