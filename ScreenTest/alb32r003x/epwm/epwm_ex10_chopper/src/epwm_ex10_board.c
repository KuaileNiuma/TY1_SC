/**
 *************************************************************************************
 * @file epwm_ex10_board.c
 * @brief This file contains the source file for example epwm_ex10_board.
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

#include "epwm_ex10_board.h"
//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules.
// Call this function in your application if you wish to do all module
// initialization.
// If you wish to not use some of the initializations, instead of the
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
    //
    // Initialize required modules
    //
    PinMux_init();
    EPWM_init();
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
    //
    // PinMux for modules assigned to CPU1
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    //
    // EPWM1 -> myEPWM1 Pinmux
    //
    GPIO_setPinConfig(myEPWM1_EPWMA_PIN_CONFIG);

    GPIO_setPinConfig(myEPWM1_EPWMB_PIN_CONFIG);

    //
    // EPWM2 -> myEPWM2 Pinmux
    //
    GPIO_setPinConfig(myEPWM2_EPWMA_PIN_CONFIG);

    GPIO_setPinConfig(myEPWM2_EPWMB_PIN_CONFIG);

    //
    // EPWM3 -> myEPWM3 Pinmux
    //
    GPIO_setPinConfig(myEPWM3_EPWMA_PIN_CONFIG);

    GPIO_setPinConfig(myEPWM3_EPWMB_PIN_CONFIG);

    //
    // EPWM4 -> myEPWM4 Pinmux
    //
    GPIO_setPinConfig(myEPWM4_EPWMA_PIN_CONFIG);

    GPIO_setPinConfig(myEPWM4_EPWMB_PIN_CONFIG);


}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init()
{

    //
    // ePWM1 Configurations

    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    // TB
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 500
    //
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 500);
    //
    // Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM1_BASE, 0);
    //
    // Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //
    // Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM1_BASE);
    //
    // Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM1_BASE, 0);


    //
    // CC
    // Set CMPA = 125
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 125);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 0
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 0);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // AQ
    // TBCTR = UP_CMPA -> ePWM1A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM1A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPA -> ePWM1B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM1B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);




    //
    // ePWM2 Configurations
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    // TB
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 500
    //
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 500);
    //
    // Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0);
    //
    // Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //
    // Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM2_BASE);
    //
    // Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM2_BASE, 0);


    //
    // CC
    // Set CMPA = 125
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 125);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 0
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, 0);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // AQ
    // TBCTR = UP_CMPA -> ePWM2A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM2A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPA -> ePWM2B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM2B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);


    //
    // PC
    // Enable chopper mode
    //
    EPWM_enableChopper(myEPWM2_BASE);
    //
    // Set PC duty =  0 , Chopper duty cycle = (dutyCycleCount + 1)/ 8
    //
    EPWM_setChopperDutyCycle(myEPWM2_BASE,0);
    //
    // Set PCDiv = 3, chopper clock frequency = SYSCLKOUT / 8 / (1+freqDiv)
    //
    EPWM_setChopperFreq(myEPWM2_BASE, 3);
    //
    // Set OSHTWTH =  0, the first pulse width = (1 / TEPWMCLK) �� 8 �� OSHTWTH
    //
    EPWM_setChopperFirstPulseWidth(myEPWM2_BASE, 0);




    //
    // ePWM3 Configurations
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    // TB
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 500
    //
    EPWM_setTimeBasePeriod(myEPWM3_BASE, 500);
    //
    // Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM3_BASE, 0);
    //
    // Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM3_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //
    // Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM3_BASE);
    //
    // Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM3_BASE, 0);


    //
    // CC
    // Set CMPA = 125
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, 125);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 0
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, 0);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // AQ
    // TBCTR = UP_CMPA -> ePWM3A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM3A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPA -> ePWM3B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM3B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);


    //
    // PC
    // Enable chopper mode
    //
    EPWM_enableChopper(myEPWM3_BASE);
    //
    // Set PC duty =  5 , Chopper duty cycle = (dutyCycleCount + 1)/ 8
    //
    EPWM_setChopperDutyCycle(myEPWM3_BASE, 5);
    //
    // Set PCDiv = 3, chopper clock frequency = SYSCLKOUT / 8 / (1+freqDiv)
    //
    EPWM_setChopperFreq(myEPWM3_BASE, 3);
    //
    // Set OSHTWTH =  0, the first pulse width = (1 / TEPWMCLK) �� 8 �� OSHTWTH
    //
    EPWM_setChopperFirstPulseWidth(myEPWM3_BASE, 0);



    //
    // ePWM4 Configurations
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM4);
    // TB
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM4_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 500
    //
    EPWM_setTimeBasePeriod(myEPWM4_BASE, 500);
    //
    // Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM4_BASE, 0);
    //
    // Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM4_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //
    // Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM4_BASE);
    //
    // Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM4_BASE, 0);


    //
    // CC
    // Set CMPA = 125
    //
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, 125);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 0
    //
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, 0);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // AQ
    // TBCTR = UP_CMPA -> ePWM4A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM4A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPA -> ePWM4B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM4B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);


    //
    // PC
    // Enable chopper mode
    //
    EPWM_enableChopper(myEPWM4_BASE);
    //
    // Set PC duty =  3 , Chopper duty cycle = (dutyCycleCount + 1)/ 8
    //
    EPWM_setChopperDutyCycle(myEPWM4_BASE, 3);
    //
    // Set PCDiv = 3, chopper clock frequency = SYSCLKOUT / 8 / (1+freqDiv)
    //
    EPWM_setChopperFreq(myEPWM4_BASE, 3);
    //
    // Set OSHTWTH =  10, the first pulse width = (1 / TEPWMCLK) �� 8 �� OSHTWTH
    //
    EPWM_setChopperFirstPulseWidth(myEPWM4_BASE, 10);

}
#ifdef __cplusplus
}
#endif

//*****************************************************************************
//
// End of file
//
//*****************************************************************************

