/**
 *************************************************************************************
 * @file epwm_ex02_board.c
 * @brief This file contains the source file for example epwm_ex02_board.
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

#include "epwm_ex02_board.h"
#include "epwm.h"
#include "gpio.h"

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
    //Turn on the GPIOA peripheral clock
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

}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init()  //!< EPWM configuration function
{

    //
    //	ePWM1 Configurations
    //  TB
    //	Set 1(1*1) frequency division
    //
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    
    //
    //	Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 2000);

    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM1_BASE, 0);

    //
    //	Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_UP_DOWN);
   
    //
    //	Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM1_BASE);

    //
    //	Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM1_BASE, 0);


    //
    //  CC
    //	Set CMPA = 50
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 50);
   
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //	Set CMPB = 1950
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 1950);
    
    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //  AQ
    //	TBCTR = UP_CMPA -> ePWM1A:HIGH
    //
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    
    //
    //	TBCTR = DOWN_CMPA -> ePWM1A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    
    //
    //	TBCTR = UP_CMPB -> ePWM1B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    
    //
    //	TBCTR = DOWN_CMPB -> ePWM1B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);


    //
    //  ET
    //  Enable ePWM1 interrupt
    //
    EPWM_enableInterrupt(myEPWM1_BASE);

    //
    //  ePWM1 interrupt Source is TBCTR = ZERO
    //
    EPWM_setInterruptSource(myEPWM1_BASE, EPWM_INT_TBCTR_ZERO);

    //
    //  Sets the ePWM1 interrupt event counts to 3
    //
    EPWM_setInterruptEventCount(myEPWM1_BASE, 3);



    //	ePWM2 Configurations
    //
    //Turn on the EPWM2 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    //
    //  TB
    //	Set 1(1*1) frequency division
    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    //	Set TBPRD = 2000
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 2000);
    //	Set TBCTR = 0
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0);
    //	Counting mode: UP_DOWN
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //	Disable phase shift load
    EPWM_disablePhaseShiftLoad(myEPWM2_BASE);
    //	Set TBPHS = 0
    EPWM_setPhaseShift(myEPWM2_BASE, 0);

    //
    //  CC
    //	Set CMPA = 50
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 50);
    
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //	Set CMPB = 50
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, 50);
    
    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //  AQ
    //	TBCTR = UP_CMPA -> ePWM2A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    
    //
    //	TBCTR = DOWN_CMPA -> ePWM2A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    
    //
    //	TBCTR = 0 -> ePWM2B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    
    //
    //	TBCTR = TBPRD -> ePWM2B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);

    //
    //ET
    //Enable ePWM2 interrupt
    //
    EPWM_enableInterrupt(myEPWM2_BASE);

    //
    //ePWM2 interrupt Source is TBCTR = ZERO
    //
    EPWM_setInterruptSource(myEPWM2_BASE, EPWM_INT_TBCTR_ZERO);

    //
    //Sets the ePWM2 interrupt event counts to 3
    //
    EPWM_setInterruptEventCount(myEPWM2_BASE, 3);


    //
    //	ePWM3 Configurations
    //  TB
    //	Set 1(1*1) frequency division
    //
    //
    //Turn on the EPWM3 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    //
    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    
    //
    //	Set TBPRD = 2000
    //
    EPWM_setTimeBasePeriod(myEPWM3_BASE, 2000);

    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM3_BASE, 0);

    //
    //	Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM3_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    
    //
    //	Disable phase shift load
    //
    EPWM_disablePhaseShiftLoad(myEPWM3_BASE);

    //
    //	Set TBPHS = 0
    //
    EPWM_setPhaseShift(myEPWM3_BASE, 0);


    //
    //  CC
    //	Set CMPA = 50
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, 50);
    
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //	Set CMPB = 1950
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, 1950);
    
    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //	AQ
    //	TBCTR = TBPRD -> ePWM3A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    
    //  
    //	TBCTR = DOWN_CMPB -> ePWM3A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    
    //
    //	TBCTR = TBPRD -> ePWM3B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    
    //
    //	TBCTR = UP_CMPA -> ePWM3B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    
    //
    //	ET
    //Enable ePWM3 interrupt
    //
    EPWM_enableInterrupt(myEPWM3_BASE);

    //
    //	ePWM3 interrupt Source is TBCTR = ZERO
    //
    EPWM_setInterruptSource(myEPWM3_BASE, EPWM_INT_TBCTR_ZERO);
    
    //
    //	Sets the ePWM3 interrupt event counts to 3
    //
    EPWM_setInterruptEventCount(myEPWM3_BASE, 3);

}

//
// configurePhase - Configure ePWMx Phase
//
void configurePhase(uint32_t base, uint32_t masterBase, uint16_t phaseVal)  //!< Configure ePWMx Phase
{
    uint32_t readPrdVal, phaseRegVal;

    //
    // Read Period value to calculate value for Phase Register
    //
    readPrdVal = EPWM_getTimeBasePeriod(masterBase);

    //
    // Caluclate phase register values based on Time Base counter mode
    //
    if ((HWREGH(base + EPWM_O_TBCTL) & 0x3U) == EPWM_COUNTER_MODE_UP_DOWN)
    {
        phaseRegVal = (2U * readPrdVal * phaseVal) / 360U;
        if (phaseVal > 180)
        {
            phaseRegVal = (2U * readPrdVal) - phaseRegVal;
        }
    }
    else if ((HWREGH(base + EPWM_O_TBCTL) & 0x3U) < EPWM_COUNTER_MODE_UP_DOWN)
    {
        phaseRegVal = (readPrdVal * phaseVal) / 360U;
    }

    EPWM_selectPeriodLoadEvent(base, EPWM_SHADOW_LOAD_MODE_SYNC);
    EPWM_setPhaseShift(base, phaseRegVal);
    EPWM_setTimeBaseCounter(base, phaseRegVal);
}

#ifdef __cplusplus

#endif

