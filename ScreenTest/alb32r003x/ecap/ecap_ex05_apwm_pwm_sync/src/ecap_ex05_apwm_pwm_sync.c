/**
 *************************************************************************************
 * @file ecap_ex05_apwm_pwm_sync.c
 * @brief This file contains the source file for example ecap_ex05_apwm_pwm_sync.
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
#include "ecap_ex05_board.h"
#include "hw_types.h"
//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define PWM_FREQUENCY       10000U                      //!< PWM frequency in Hz (10 kHz)
#define PWM_DUTY            0.5f                        //!< PWM duty cycle (50%)
#define PWM_PRD_VAL         7000000U / PWM_FREQUENCY   //!< PWM period value
#define PWM_CMP_VAL         (uint32_t)(PWM_DUTY * PWM_PRD_VAL)  //!< PWM compare value


//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void initEPWM(void);

//*****************************************************************************
//
// initEPWM - Initialize EPWM module for synchronization
// 
//  This function configures the EPWM1 module in up-count mode with specified
//  period, compare values, and action qualifiers. It also enables sync
//  output pulses for synchronization with ECAP modules.
//
//*****************************************************************************
static void initEPWM(void)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Disable sync (Freeze clock to PWM as well)
    //
     SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Configure ePWM
    //       Counter runs in up-count mode.
    //       Action qualifier will output low on period match
    //       Action qualifier will output high on CTR=CMPA
    //
    EPWM_setClockPrescaler(EPWM1_BASE,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);
    EPWM_setTimeBasePeriod(EPWM1_BASE, PWM_PRD_VAL);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0U);
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(EPWM1_BASE);
    EPWM_setPhaseShift(EPWM1_BASE, 0U);
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, PWM_CMP_VAL);
    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_enableSyncOutPulseSource(EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(EPWM1_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM1_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

//
//     Another ePWM Configurations where ePWM shifts phase by 50% comparing to eCAP.
//           Counter runs in up-count mode.
//           Action qualifier will output low on period match
//           Action qualifier will output high on CTR=CMPB
//
     EPWM_setClockPrescaler(EPWM1_BASE,
                            EPWM_CLOCK_DIVIDER_1,
                            EPWM_HSCLOCK_DIVIDER_1);
     EPWM_setTimeBasePeriod(EPWM1_BASE, PWM_PRD_VAL);
     EPWM_setTimeBaseCounter(EPWM1_BASE, 0U);
     EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
     EPWM_disablePhaseShiftLoad(EPWM1_BASE);
     EPWM_setPhaseShift(EPWM1_BASE, 0U);
     EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, PWM_CMP_VAL);
     EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
     EPWM_enableSyncOutPulseSource(EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B);
     EPWM_setActionQualifierAction(EPWM1_BASE,
                                   EPWM_AQ_OUTPUT_A,
                                   EPWM_AQ_OUTPUT_LOW,
                                   EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
     EPWM_setActionQualifierAction(EPWM1_BASE,
                                   EPWM_AQ_OUTPUT_A,
                                   EPWM_AQ_OUTPUT_HIGH,
                                   EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

//*****************************************************************************
//
// main - Main function for ECAP APWM PWM synchronization example
// 
//  This function initializes the board components and EPWM module,
//  then enters an infinite loop. The example demonstrates synchronization
//  between EPWM and ECAP modules in APWM mode.
//
//*****************************************************************************
void main(void)
{
    ECAP_TypeDef *tmp;

    alb32r003x_evb_init();

    //
    // Board initialization
    // Select eCAP1OUT on MUX 0. Make GPIO4 as eCAP1OUT for PWM output
    // Select eCAP2OUT on MUX 2. Make GPIO15 as eCAP2OUT for PWM output
    // Configure eCAP1 in APWM mode with defined period and duty values
    // Polarity as low and configure SYNCOUT at CTR=PRD
    //
    Board_init();

    //
    // Configure ePWM
    //
    initEPWM();

    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
    while(1)
    {
        //
        // Main loop - Do nothing
        //
    }
}

#ifdef __cplusplus
}
#endif
