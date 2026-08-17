/**
 *************************************************************************************
 * @file clb_ex04_board.c
 * @brief This file contains the source file for example clb_ex04_board.
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

#include "clb_ex04_board.h"

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
	SYNC_init();
	CLB_init();
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
// CLB Configurations
//
//*****************************************************************************
void CLB_init(){
	myTILE1_init();
	myTILE2_init();
	myTILE3_init();
	myTILE4_init();
}

void myTILE1_init(){
	CLB_setOutputMask(myTILE1_BASE,
				(0UL << 0UL), true);
	CLB_enableOutputMaskUpdates(myTILE1_BASE);
	//
	// myTILE1 SPI Buffer Configuration
	//
	CLB_disableSPIBufferAccess(myTILE1_BASE);
	CLB_configSPIBufferLoadSignal(myTILE1_BASE, 0);
	CLB_configSPIBufferShift(myTILE1_BASE, 0);
	//
	// myTILE1 CLB_IN0 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM1A);
	CLB_configGPInputMux(myTILE1_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE1_BASE, CLB_IN0);
	CLB_selectInputFilter(myTILE1_BASE, CLB_IN0, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE1_BASE, CLB_IN0);
	//
	// myTILE1 CLB_IN1 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1A);
	CLB_configGPInputMux(myTILE1_BASE, CLB_IN1, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE1_BASE, CLB_IN1);
	CLB_selectInputFilter(myTILE1_BASE, CLB_IN1, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE1_BASE, CLB_IN1);
	//
	// myTILE1 CLB_IN2 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1B);
	CLB_configGPInputMux(myTILE1_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE1_BASE, CLB_IN2);
	CLB_selectInputFilter(myTILE1_BASE, CLB_IN2, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE1_BASE, CLB_IN2);
	//
	// myTILE1 CLB_IN3 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE1_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1B);
	CLB_configGPInputMux(myTILE1_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE1_BASE, CLB_IN3);
	CLB_selectInputFilter(myTILE1_BASE, CLB_IN3, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE1_BASE, CLB_IN3);
	CLB_setGPREG(myTILE1_BASE,0);

	CLB_enableCLB(myTILE1_BASE);
}
void myTILE2_init(){
	CLB_setOutputMask(myTILE2_BASE,
				(0UL << 0UL), true);
	CLB_enableOutputMaskUpdates(myTILE2_BASE);
	//
	// myTILE2 SPI Buffer Configuration
	//
	CLB_disableSPIBufferAccess(myTILE2_BASE);
	CLB_configSPIBufferLoadSignal(myTILE2_BASE, 0);
	CLB_configSPIBufferShift(myTILE2_BASE, 0);
	//
	// myTILE2 CLB_IN0 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE2_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE2_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM2A);
	CLB_configGPInputMux(myTILE2_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE2_BASE, CLB_IN0);
	CLB_selectInputFilter(myTILE2_BASE, CLB_IN0, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE2_BASE, CLB_IN0);
	//
	// myTILE2 CLB_IN1 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE2_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE2_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM2A);
	CLB_configGPInputMux(myTILE2_BASE, CLB_IN1, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE2_BASE, CLB_IN1);
	CLB_selectInputFilter(myTILE2_BASE, CLB_IN1, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE2_BASE, CLB_IN1);
	//
	// myTILE2 CLB_IN2 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE2_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE2_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM2B);
	CLB_configGPInputMux(myTILE2_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE2_BASE, CLB_IN2);
	CLB_selectInputFilter(myTILE2_BASE, CLB_IN2, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE2_BASE, CLB_IN2);
	//
	// myTILE2 CLB_IN3 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE2_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE2_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM2B);
	CLB_configGPInputMux(myTILE2_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE2_BASE, CLB_IN3);
	CLB_selectInputFilter(myTILE2_BASE, CLB_IN3, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE2_BASE, CLB_IN3);
	CLB_setGPREG(myTILE2_BASE,0);

	CLB_enableCLB(myTILE2_BASE);
}
void myTILE3_init(){
	CLB_setOutputMask(myTILE3_BASE,
				(0UL << 0UL), true);
	CLB_enableOutputMaskUpdates(myTILE3_BASE);
	//
	// myTILE3 SPI Buffer Configuration
	//
	CLB_disableSPIBufferAccess(myTILE3_BASE);
	CLB_configSPIBufferLoadSignal(myTILE3_BASE, 0);
	CLB_configSPIBufferShift(myTILE3_BASE, 0);
	//
	// myTILE3 CLB_IN0 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE3_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE3_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM3A);
	CLB_configGPInputMux(myTILE3_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE3_BASE, CLB_IN0);
	CLB_selectInputFilter(myTILE3_BASE, CLB_IN0, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE3_BASE, CLB_IN0);
	//
	// myTILE3 CLB_IN1 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE3_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE3_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM3A);
	CLB_configGPInputMux(myTILE3_BASE, CLB_IN1, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE3_BASE, CLB_IN1);
	CLB_selectInputFilter(myTILE3_BASE, CLB_IN1, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE3_BASE, CLB_IN1);
	//
	// myTILE3 CLB_IN2 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE3_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE3_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM3B);
	CLB_configGPInputMux(myTILE3_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE3_BASE, CLB_IN2);
	CLB_selectInputFilter(myTILE3_BASE, CLB_IN2, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE3_BASE, CLB_IN2);
	//
	// myTILE3 CLB_IN3 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE3_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE3_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM3B);
	CLB_configGPInputMux(myTILE3_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE3_BASE, CLB_IN3);
	CLB_selectInputFilter(myTILE3_BASE, CLB_IN3, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE3_BASE, CLB_IN3);
	CLB_setGPREG(myTILE3_BASE,0);

	CLB_enableCLB(myTILE3_BASE);
}
void myTILE4_init(){
	CLB_setOutputMask(myTILE4_BASE,
				(0UL << 0UL), true);
	CLB_enableOutputMaskUpdates(myTILE4_BASE);
	//
	// myTILE4 SPI Buffer Configuration
	//
	CLB_disableSPIBufferAccess(myTILE4_BASE);
	CLB_configSPIBufferLoadSignal(myTILE4_BASE, 0);
	CLB_configSPIBufferShift(myTILE4_BASE, 0);
	//
	// myTILE4 CLB_IN0 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE4_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE4_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM4A);
	CLB_configGPInputMux(myTILE4_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE4_BASE, CLB_IN0);
	CLB_selectInputFilter(myTILE4_BASE, CLB_IN0, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE4_BASE, CLB_IN0);
	//
	// myTILE4 CLB_IN1 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE4_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE4_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM4A);
	CLB_configGPInputMux(myTILE4_BASE, CLB_IN1, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE4_BASE, CLB_IN1);
	CLB_selectInputFilter(myTILE4_BASE, CLB_IN1, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE4_BASE, CLB_IN1);
	//
	// myTILE4 CLB_IN2 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE4_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE4_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM4B);
	CLB_configGPInputMux(myTILE4_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE4_BASE, CLB_IN2);
	CLB_selectInputFilter(myTILE4_BASE, CLB_IN2, CLB_FILTER_FALLING_EDGE);
	CLB_disableInputPipelineMode(myTILE4_BASE, CLB_IN2);
	//
	// myTILE4 CLB_IN3 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE4_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE4_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM4B);
	CLB_configGPInputMux(myTILE4_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE4_BASE, CLB_IN3);
	CLB_selectInputFilter(myTILE4_BASE, CLB_IN3, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE4_BASE, CLB_IN3);
	CLB_setGPREG(myTILE4_BASE,0);

	CLB_enableCLB(myTILE4_BASE);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_2);
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 0);
    EPWM_setTimeBaseCounter(myEPWM1_BASE, 0);
    EPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
    EPWM_disablePhaseShiftLoad(myEPWM1_BASE);
    EPWM_setPhaseShift(myEPWM1_BASE, 0);
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM1_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM1_BASE);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM1_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM1_BASE);

    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_2);
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 0);
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0);
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
    EPWM_disablePhaseShiftLoad(myEPWM2_BASE);
    EPWM_setPhaseShift(myEPWM2_BASE, 0);
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM2_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM2_BASE);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM2_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM2_BASE);

    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_2);
    EPWM_setTimeBasePeriod(myEPWM3_BASE, 0);
    EPWM_setTimeBaseCounter(myEPWM3_BASE, 0);
    EPWM_setTimeBaseCounterMode(myEPWM3_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
    EPWM_disablePhaseShiftLoad(myEPWM3_BASE);
    EPWM_setPhaseShift(myEPWM3_BASE, 0);
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM3_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM3_BASE);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM3_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM3_BASE);

    EPWM_setClockPrescaler(myEPWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_2);
    EPWM_setTimeBasePeriod(myEPWM4_BASE, 0);
    EPWM_setTimeBaseCounter(myEPWM4_BASE, 0);
    EPWM_setTimeBaseCounterMode(myEPWM4_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
    EPWM_disablePhaseShiftLoad(myEPWM4_BASE);
    EPWM_setPhaseShift(myEPWM4_BASE, 0);
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, 0);
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM4_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM4_BASE);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM4_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM4_BASE);
}

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
