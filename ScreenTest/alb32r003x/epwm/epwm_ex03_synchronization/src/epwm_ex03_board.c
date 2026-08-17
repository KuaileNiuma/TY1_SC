/**
 *************************************************************************************
 * @file epwm_ex03_board.c
 * @brief This file contains the source file for example epwm_ex03_board.
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

#include "epwm_ex03_board.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define   EPWM_MODE_SEL    EPWM_MODE_SPWM_0  //!< EPWM mode selection


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
void Board_init()  //!< Board initialization function
{

    PinMux_init();
    EPWM_init();

}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()  //!< PINMUX configuration function
{
    //
    // PinMux for modules assigned to CPU1
    //
    //
    //Turn on the GPIO peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
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
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init()  //!< EPWM configuration function
{

    //	ePWM1 Configurations
    //
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    //	ePWM1 Configurations
    //  TB
    //	Set 8(8*1) frequency division
    
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_8, EPWM_HSCLOCK_DIVIDER_1);

    //
    //	Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 2000);

    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM1_BASE, 0);

    //
    //	Counting mode: UP
    //
    EPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_UP);
    
    //
    //	Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM1_BASE);

    //
    //	Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM1_BASE, 0);

    //
    //	The synchronization signal SYNC is generated when TBCTR = 0
    //
    EPWM_enableSyncOutPulseSource(myEPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);

    //
    //  CC
    //	Set CMPA = 1000
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 1000);

    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    //	Set CMPB = 500
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 500);

    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    //  AQ
    //	TBCTR = 0 -> ePWM1A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    //	TBCTR = UP_CMPA -> ePWM1A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    //
    //	TBCTR = 0 -> ePWM1B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    //	TBCTR = UP_CMPB -> ePWM1B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);



    //
    //  ePWM2 Configurations
    //
    //Turn on the EPWM2 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    //
    //  TB
    //	Set 8(8*1) frequency division
    //
    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_8, EPWM_HSCLOCK_DIVIDER_1);
    
    //
    //	Load a new TBPRD when SYNC is received
    //
    EPWM_selectPeriodLoadEvent(myEPWM2_BASE, EPWM_SHADOW_LOAD_MODE_SYNC);
    
    //
    //	Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 2000);

    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0);

    //
    //	Counting mode: UP
    //
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_UP);
    
    //
    //	Enable phase shift load
    //
    EPWM_enablePhaseShiftLoad(myEPWM2_BASE);

    //
    //	Set TBPHS = 300
    //
    EPWM_setPhaseShift(myEPWM2_BASE, 300);

    //
    //  CC
    //	Set CMPA = 1000
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 1000);
    
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //	Set CMPB = 500
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, 500);
    
    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    //  AQ
    //	TBCTR = 0 -> ePWM2A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    
    //
    //	TBCTR = UP_CMPA -> ePWM2A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    
    //
    //	TBCTR = 0 -> ePWM2B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    
    //
    //	TBCTR = UP_CMPB -> ePWM2B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    //
    //  ePWM3 Configurations
    //
    //Turn on the EPWM3 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    //
    //  TB
    //	Set 8(8*1) frequency division
    //
    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_8, EPWM_HSCLOCK_DIVIDER_1);

    //
    //	Load a new TBPRD when SYNC is received
    //
    EPWM_selectPeriodLoadEvent(myEPWM3_BASE, EPWM_SHADOW_LOAD_MODE_SYNC);

    //
    //	Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM3_BASE, 2000);

    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM3_BASE, 0);

    //
    //	Counting mode: UP
    //
    EPWM_setTimeBaseCounterMode(myEPWM3_BASE, EPWM_COUNTER_MODE_UP);

    //
    //	Enable phase shift load
    //
    EPWM_enablePhaseShiftLoad(myEPWM3_BASE);

    //
    //	Set TBPHS = 600
    //
    EPWM_setPhaseShift(myEPWM3_BASE, 600);


    //
    //  CC
    //	Set CMPA = 1000
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, 1000);

    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    //	Set CMPB = 500
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, 500);

    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    //  AQ
    //	TBCTR = 0 -> ePWM3A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    //	TBCTR = UP_CMPA -> ePWM3A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    //
    //	TBCTR = 0 -> ePWM3B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    //	TBCTR = UP_CMPB -> ePWM3B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);


    //
    //  ePWM4 Configurations
    //
    //Turn on the EPWM4 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM4);
    //
    //  TB
    //	Set 8(8*1) frequency division
    //
    EPWM_setClockPrescaler(myEPWM4_BASE, EPWM_CLOCK_DIVIDER_8, EPWM_HSCLOCK_DIVIDER_1);

    //
    //	Load a new TBPRD when SYNC is received
    //
    EPWM_selectPeriodLoadEvent(myEPWM4_BASE, EPWM_SHADOW_LOAD_MODE_SYNC);

    //
    //	Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM4_BASE, 2000);

    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM4_BASE, 0);

    //
    //	Counting mode: UP
    //
    EPWM_setTimeBaseCounterMode(myEPWM4_BASE, EPWM_COUNTER_MODE_UP);

    //
    //	Enable phase shift load
    //
    EPWM_enablePhaseShiftLoad(myEPWM4_BASE);

    //
    //	Set TBPHS = 900
    //
    EPWM_setPhaseShift(myEPWM4_BASE, 900);


    //
    //  CC
    //	Set CMPA = 1000
    //
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, 1000);

    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    //	Set CMPB = 500
    //
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, 500);

    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    //  AQ
    //	TBCTR = 0 -> ePWM4A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    //	TBCTR = UP_CMPA -> ePWM4A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    //
    //	TBCTR = 0 -> ePWM4B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    //	TBCTR = UP_CMPB -> ePWM4B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);


}


#ifdef __cplusplus

#endif

