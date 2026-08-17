/**
 *************************************************************************************
 * @file epwm_ex08_board.c
 * @brief This file contains the source file for example epwm_ex08_board.
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

#include "epwm_ex08_board.h"
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

    //
    // EPWM5 -> myEPWM5 Pinmux
    //
    GPIO_setPinConfig(myEPWM5_EPWMA_PIN_CONFIG);

    GPIO_setPinConfig(myEPWM5_EPWMB_PIN_CONFIG);


    //
    // EPWM6 -> myEPWM6 Pinmux
    //
    GPIO_setPinConfig(myEPWM6_EPWMA_PIN_CONFIG);

    GPIO_setPinConfig(myEPWM6_EPWMB_PIN_CONFIG);


}

//*****************************************************************************
//
//*****************************************************************************
void EPWM_init()
{
    //ePWM1 Configurations

    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 2000);
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
    // Set CMPA = 500
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 500);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 1500
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 1500);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // TBCTR = UP_CMPA -> ePWM1A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM1A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPB -> ePWM1B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    // TBCTR = DOWN_CMPB -> ePWM1B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);


    //
    // Set the RED (Rising Edge Delay) shadow load mode
    //
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM1_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);
    //
    // Disable the RED (Rising Edge Delay) shadow load mode
    //
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM1_BASE);
    //
    // Set the FED (Falling Edge Delay) shadow load mode
    //
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM1_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);
    //
    // Disables the FED (Falling Edge Delay) shadow load mode
    //
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM1_BASE);




    //ePWM2 Configurations
    //
    //Turn on the EPWM2 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    //
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 2000);
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
    // Set CMPA = 500
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 500);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 1500
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, 1500);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // TBCTR = UP_CMPA -> ePWM2A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM2A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPB -> ePWM2B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    // TBCTR = DOWN_CMPB -> ePWM2B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);


    //
    // Set the input source for the dead zone to ePWM2A
    //
    EPWM_setRisingEdgeDeadBandDelayInput(myEPWM2_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone rising edge delay polarity not reversed
    //
    EPWM_setDeadBandDelayPolarity(myEPWM2_BASE, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    // Enabling dead zone rising edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM2_BASE, EPWM_DB_RED, true);
    //
    // Dead zone rising edge delay 400 TBCTR
    //
    EPWM_setRisingEdgeDelayCount(myEPWM2_BASE, 400);
    //
    // Set the input source for the dead zone to ePWM2A
    //
    EPWM_setFallingEdgeDeadBandDelayInput(myEPWM2_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone falling edge delay polarity not to reverse
    //
    EPWM_setDeadBandDelayPolarity(myEPWM2_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    // Enable dead zone fall edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM2_BASE, EPWM_DB_FED, true);
    //
    // Falling edge delay 200 TBCTR
    //
    EPWM_setFallingEdgeDelayCount(myEPWM2_BASE, 200);





    //	ePWM3 Configurations
    //
    //Turn on the EPWM3 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    //
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM3_BASE, 2000);
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
    // Set CMPA = 500
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, 500);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 1500
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, 1500);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


	//
    // TBCTR = UP_CMPA -> ePWM3A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM3A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPB -> ePWM3B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    // TBCTR = DOWN_CMPB -> ePWM3B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    //
    // Set the input source for the dead zone to ePWM3A
    //
    EPWM_setRisingEdgeDeadBandDelayInput(myEPWM3_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone rising edge delay polarity not reversed
    //
    EPWM_setDeadBandDelayPolarity(myEPWM3_BASE, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    // Enabling dead zone rising edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM3_BASE, EPWM_DB_RED, true);
    //
    // Dead zone rising edge delay 400 TBCTR
    //
    EPWM_setRisingEdgeDelayCount(myEPWM3_BASE, 400);
    //
    // Set the input source for the dead zone to ePWM3A
    //
    EPWM_setFallingEdgeDeadBandDelayInput(myEPWM3_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone falling edge delay polarity not reversed
    //
    EPWM_setDeadBandDelayPolarity(myEPWM3_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    // Enable dead zone fall edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM3_BASE, EPWM_DB_FED, true);
    //
    // Falling edge delay 200 TBCTR
    //
    EPWM_setFallingEdgeDelayCount(myEPWM3_BASE, 200);
    //
    // Enables ePWM3A dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM3_BASE, EPWM_DB_OUTPUT_A, true);
    //
    // Enables ePWM3B dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM3_BASE, EPWM_DB_OUTPUT_B, true);


    //	ePWM4 Configurations
    //
    //Turn on the EPWM4 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM4);
    //
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM4_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM4_BASE, 2000);
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
    // Set CMPA = 500
    //
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, 500);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 1500
    //
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, 1500);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // TBCTR = UP_CMPA -> ePWM4A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM4A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPB -> ePWM4B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    // TBCTR = DOWN_CMPB -> ePWM4B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    //
    // Set the input source for the dead zone to ePWM4A
    //
    EPWM_setRisingEdgeDeadBandDelayInput(myEPWM4_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone rising edge delay polarity not reversed
    //
    EPWM_setDeadBandDelayPolarity(myEPWM4_BASE, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    // Enabling dead zone rising edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM4_BASE, EPWM_DB_RED, true);
    //
    // Dead zone rising edge delay 400 TBCTR
    //
    EPWM_setRisingEdgeDelayCount(myEPWM4_BASE, 400);
    //
    // Set the input source for the dead zone to ePWM4A
    //
    EPWM_setFallingEdgeDeadBandDelayInput(myEPWM4_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone falling edge delay polarity reversal
    //
    EPWM_setDeadBandDelayPolarity(myEPWM4_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);
    //
    // Enable dead zone fall edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM4_BASE, EPWM_DB_FED, true);
    //
    // Falling edge delay 200 TBCTR
    //
    EPWM_setFallingEdgeDelayCount(myEPWM4_BASE, 200);
    //
    // Disables ePWM4A dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM4_BASE, EPWM_DB_OUTPUT_A, false);
    //
    // Disables ePWM4B dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM4_BASE, EPWM_DB_OUTPUT_B, false);


    //	ePWM5 Configurations
    //
    //Turn on the EPWM5 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM5);
    //
    // Set 16(4*4) frequency division
    //
    EPWM_setClockPrescaler(myEPWM5_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //
    // Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM5_BASE, 2000);
    //
    // Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM5_BASE, 0);
    //
    // Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM5_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //
    // Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM5_BASE);
    //
    // Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM5_BASE, 0);


    //
    // Set CMPA = 500
    //
    EPWM_setCounterCompareValue(myEPWM5_BASE, EPWM_COUNTER_COMPARE_A, 500);
    //
    // Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM5_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set CMPB = 1500
    //
    EPWM_setCounterCompareValue(myEPWM5_BASE, EPWM_COUNTER_COMPARE_B, 1500);
    //
    // Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM5_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    // TBCTR = UP_CMPA -> ePWM5A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // TBCTR = DOWN_CMPA -> ePWM5A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    // TBCTR = UP_CMPB -> ePWM5B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    // TBCTR = DOWN_CMPB -> ePWM5B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    //
    // Set the input source for the dead zone to ePWM5A
    //
    EPWM_setRisingEdgeDeadBandDelayInput(myEPWM5_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone rising edge delay polarity reversal
    //
    EPWM_setDeadBandDelayPolarity(myEPWM5_BASE, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_LOW);
    //
    // Enabling dead zone rising edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM5_BASE, EPWM_DB_RED, true);
    //
    // Dead zone rising edge delay 400 TBCTR
    //
    EPWM_setRisingEdgeDelayCount(myEPWM5_BASE, 400);
    //
    // Set the input source for the dead zone to ePWM5A
    //
    EPWM_setFallingEdgeDeadBandDelayInput(myEPWM5_BASE,EPWM_DB_INPUT_EPWMA);
    //
    // Set dead zone falling edge delay polarity not to reverse
    //
    EPWM_setDeadBandDelayPolarity(myEPWM5_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    // Enable dead zone fall edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM5_BASE, EPWM_DB_FED, true);
    //
    // Falling edge delay 200 TBCTR
    //
    EPWM_setFallingEdgeDelayCount(myEPWM5_BASE, 200);
    //
    // Enables ePWM5A dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM5_BASE, EPWM_DB_OUTPUT_A, true);
    //
    // Enables ePWM5B dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM5_BASE, EPWM_DB_OUTPUT_B, true);



    //	ePWM6 Configurations
    //
    //Turn on the EPWM6 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM6);
    //TB
    //	Set 16(4*4) frequency division
    EPWM_setClockPrescaler(myEPWM6_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //	Set TBPRD = 2000
    EPWM_setTimeBasePeriod(myEPWM6_BASE, 2000);
    //	Set TBCTR = 0
    EPWM_setTimeBaseCounter(myEPWM6_BASE, 0);
    //	Counting mode: UP_DOWN
    EPWM_setTimeBaseCounterMode(myEPWM6_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //	Disable phase shift load
    EPWM_disablePhaseShiftLoad(myEPWM6_BASE);
    //	Set TBPHS = 0
    EPWM_setPhaseShift(myEPWM6_BASE, 0);


    //CC
    //	Set CMPA = 500
    EPWM_setCounterCompareValue(myEPWM6_BASE, EPWM_COUNTER_COMPARE_A, 500);
    //	Load the new CMPA when TBCTR = 0
    EPWM_setCounterCompareShadowLoadMode(myEPWM6_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //	Set CMPB = 1500
    EPWM_setCounterCompareValue(myEPWM6_BASE, EPWM_COUNTER_COMPARE_B, 1500);
    //	Load the new CMPB when TBCTR = 0
    EPWM_setCounterCompareShadowLoadMode(myEPWM6_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //AQ
    //	TBCTR = UP_CMPA -> ePWM6A:HIGH
    EPWM_setActionQualifierAction(myEPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //	TBCTR = DOWN_CMPA -> ePWM6A:LOW
    EPWM_setActionQualifierAction(myEPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //	TBCTR = UP_CMPB -> ePWM6B:HIGH
    EPWM_setActionQualifierAction(myEPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //	TBCTR = DOWN_CMPB -> ePWM6B:LOW
    EPWM_setActionQualifierAction(myEPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);


    //
    // Set the RED (Rising Edge Delay) shadow load mode
    //
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM6_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);
    //
    // Disable the RED (Rising Edge Delay) shadow load mode
    //
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM6_BASE);
    //
    // Set the FED (Falling Edge Delay) shadow load mode
    //
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM6_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);
    //
    // Disables the FED (Falling Edge Delay) shadow load mode
    //
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM6_BASE);
    //
    // Enable ePWM6A dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM6_BASE, EPWM_DB_OUTPUT_A, true);
    //
    // Enable ePWM6B dead zone switching mode
    //
    EPWM_setDeadBandOutputSwapMode(myEPWM6_BASE, EPWM_DB_OUTPUT_B, true);


}
#ifdef __cplusplus

#endif

