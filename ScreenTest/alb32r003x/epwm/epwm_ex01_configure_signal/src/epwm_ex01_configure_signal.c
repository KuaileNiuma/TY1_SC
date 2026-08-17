/**
 *************************************************************************************
 * @file epwm_ex01_configure_signal.c
 * @brief This file contains the source file for example epwm_ex01_configure_signal.
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
 
#include <stdio.h>
#include "epwm_ex01_board.h"
#include "alb32r003x_evb.h"


//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
//
// Macros
//
#define DEVICE_SYSCLK_FREQ  200000000  //!< System clock frequency in Hz

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

EPWM_SignalParams pwmSignal =
{ 1000, 0.5f, 0.5f, true, DEVICE_SYSCLK_FREQ, EPWM_COUNTER_MODE_UP_DOWN,
        EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1 };  //!< PWM signal parameters

//*****************************************************************************
//
// Main
//
//*****************************************************************************
int main(void)
{
    uint32_t i;
    alb32r003x_evb_init();
    pwmSignal.sysClkInHz = SystemClock_Get_AHB();

    printf("EPWM EX01 Configure signal.\r\n");
    //
    // Disable sync(Freeze clock to PWM as well)
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    //
    // For this case just init GPIO pins for ePWM1, ePWM2, ePWM3
    //
    Board_init();
    //
    // Configure phase between PWM1, PWM2 & PWM3.
    // PWM1 is configured as master and ePWM2 & 3
    // are configured as slaves.
    //
    // ePWM1 SYNCO is generated on CTR=0
    //
    EPWM_enableSyncOutPulseSource(myEPWM1_BASE,
            EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);
    //
    // Configure phase shift for EPWM2 & 3
    //
    configurePhase(myEPWM2_BASE, myEPWM1_BASE, 120);
    configurePhase(myEPWM3_BASE, myEPWM1_BASE, 240);
    EPWM_setSyncInPulseSource(myEPWM2_BASE,
            EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1);
    EPWM_setSyncInPulseSource(myEPWM3_BASE,
            EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1);
    EPWM_enablePhaseShiftLoad(myEPWM2_BASE);
    EPWM_enablePhaseShiftLoad(myEPWM3_BASE);
    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    for (i = 0; i < 0xfffff; i++)
    {
    }

    //
    // force output low/high
    //
    EPWM_setActionQualifierContSWForceAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_SW_OUTPUT_LOW);
    EPWM_setActionQualifierContSWForceAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_SW_OUTPUT_LOW);

    for (;;);
}
