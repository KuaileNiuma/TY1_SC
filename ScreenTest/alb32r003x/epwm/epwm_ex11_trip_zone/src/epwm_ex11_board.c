/**
 *************************************************************************************
 * @file epwm_ex11_board.c
 * @brief This file contains the source file for example epwm_ex11_board.
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
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "epwm_ex11_board.h"
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
    EALLOW;

    PinMux_init();
    INPUTXBAR_init();
    GPIO_init();
    EPWM_init();
    INTERRUPT_init();

    EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    //
    // EPWM1 -> myEPWM1 Pinmux
    //
    GPIO_setPinConfig(myEPWM1_EPWMA_PIN_CONFIG);

    // EPWM2 -> myEPWM2 Pinmux
    GPIO_setPinConfig(myEPWM2_EPWMA_PIN_CONFIG);

    // GPIO12 -> myGPIO12 Pinmux
    GPIO_setPinConfig(GPIO_12_GPIO12);

}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){

    //	ePWM1 Configurations
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //TB
    //	Set 16(4*4) frequency division
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //	Set TBPRD = 12000
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 12000);
    //	Set TBCTR = 0
    EPWM_setTimeBaseCounter(myEPWM1_BASE, 0);
    //	Counting mode: UP_DOWN
    EPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //	Disable phase shift load
    EPWM_disablePhaseShiftLoad(myEPWM1_BASE);
    //	Set TBPHS = 0
    EPWM_setPhaseShift(myEPWM1_BASE, 0);


    //CC
    //	Set CMPA = 6000
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 6000);
    //	Load the new CMPA when TBCTR = 0
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //AQ
    //	TBCTR = UP_CMPA -> ePWM1A:HIGH
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //	TBCTR = DOWN_CMPA -> ePWM1A:LOW
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);


    //TZ
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM1A:HIGH
    EPWM_setTripZoneAction(myEPWM1_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_HIGH);
    //	TZ1 event trip zone signal OSHT was enabled
    EPWM_enableTripZoneSignals(myEPWM1_BASE, EPWM_TZ_SIGNAL_OSHT1);
    //	TZ1 event trip zone signal OSHT Interrupt was enabled
    EPWM_enableTripZoneInterrupt(myEPWM1_BASE, EPWM_TZ_INTERRUPT_OST);



    //	ePWM2 Configurations
    //Turn on the EPWM2 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    //TB
    //	Set 16(4*4) frequency division
    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    //	Set TBPRD = 6000
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 6000);
    //	Set TBCTR = 0
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0);
    //	Counting mode: UP_DOWN
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //	Disable phase shift load
    EPWM_disablePhaseShiftLoad(myEPWM2_BASE);
    //	Set TBPHS = 0;
    EPWM_setPhaseShift(myEPWM2_BASE, 0);


    //CC
    //	Set CMPA = 3000
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 3000);
    //	Load the new CMPA when TBCTR = 0
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //AQ
    //	TBCTR = UP_CMPA -> ePWM2A:HIGH
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //	TBCTR = DOWN_CMPA -> ePWM2A:LOW
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);


    //TZ
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM1A:HIGH
    EPWM_setTripZoneAction(myEPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_HIGH);
    //	TZ1 event trip zone signal CBC was enabled
    EPWM_enableTripZoneSignals(myEPWM2_BASE, EPWM_TZ_SIGNAL_CBC1);
    //	TZ1 event trip zone signal CBC Interrupt was enabled
    EPWM_enableTripZoneInterrupt(myEPWM2_BASE, EPWM_TZ_INTERRUPT_CBC);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init()
{
    myGPIO12_init();
}

void myGPIO12_init()
{
    GPIO_setDirectionMode(myGPIO12, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
    //Turn on the XBAR peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);

	//Set GPIO12 to XBAR_INPUT1
    XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}


//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){

    // Interrupt Settings for INT_myEPWM1_TZ
    // ISR need to be defined for the registered interrupts
    Interrupt_register(INT_myEPWM1_TZ, &epwm1TZISR);
    Interrupt_enable(INT_myEPWM1_TZ);

    // Interrupt Settings for INT_myEPWM2_TZ
    // ISR need to be defined for the registered interrupts
    Interrupt_register(INT_myEPWM2_TZ, &epwm2TZISR);
    Interrupt_enable(INT_myEPWM2_TZ);
}


#ifdef __cplusplus
}
#endif

//*****************************************************************************
//
// End of File
//
//*****************************************************************************

