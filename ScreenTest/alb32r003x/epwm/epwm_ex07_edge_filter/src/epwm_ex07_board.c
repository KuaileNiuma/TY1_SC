/**
 *************************************************************************************
 * @file epwm_ex07_board.c
 * @brief This file contains the source file for example epwm_ex07_board.
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
 
#include "epwm_ex07_board.h"

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
    EPWM_init();
    GPIO_init();
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
    GPIO_setPinConfig(myEPWM1_EPWMB_PIN_CONFIG);

    //
    // GPIO25 -> myGPIO25 Pinmux
    //
    GPIO_setPinConfig(GPIO_25_GPIO25);


}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init()
{
    //	ePWM1 Configurations
	//
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //  TB
    //	Set 16(4*4) frequency division
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_4, EPWM_HSCLOCK_DIVIDER_4);
    
    //
    //	Set TBPRD = 12000
    //
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 12000);

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
    //	Set CMPA = 2000
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 2000);
    
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //	Set CMPB = 0
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 0);
    
    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    //	AQ
    //	TBCTR = UP_CMPA -> ePWM1A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    //	TBCTR = DOWN_CMPA -> ePWM1A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    //	AQ
    //	TBCTR = UP_CMPA -> ePWM1B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    //	TBCTR = DOWN_CMPA -> ePWM1B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

    //
    //	TZ
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM1A:Disable action
    //
    //
    EPWM_setTripZoneAction(myEPWM1_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
    
    //
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM1B:LOW
    //
    EPWM_setTripZoneAction(myEPWM1_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);
    
    //
    //	Enables Trip Zone signal is DCBEVT2
    //
    EPWM_enableTripZoneSignals(myEPWM1_BASE, EPWM_TZ_SIGNAL_DCBEVT2);
    
    //
    //	Set the digital comparator generating event that causes the trip zone event to DCBEVT2 (B2),
    //  and the event firing source to DCXH = LOW
    //
    EPWM_setTripZoneDigitalCompareEventCondition(myEPWM1_BASE, EPWM_TZ_DC_OUTPUT_B2, EPWM_TZ_EVENT_DCXH_LOW);
    
    //
    //	DC
    //	Set the synchronous input mode of digital comparator B to DC input signal out of sync with TBCLK,
    //  and the digital comparison event number is 2 (CBC event, number 1 is One-shot event).
    //
    EPWM_selectDigitalCompareTripInput(myEPWM1_BASE,EPWM_DC_TRIP_TRIPIN1,EPWM_DC_TYPE_DCBH);
    EPWM_setDigitalCompareEventSyncMode(myEPWM1_BASE, EPWM_DC_MODULE_B, EPWM_DC_EVENT_2, EPWM_DC_EVENT_INPUT_NOT_SYNCED);
    
    
    //
    //	Event 2 of Digital Comparator B uses the filtered signal as the source signal
    //
    EPWM_setDigitalCompareEventSource(myEPWM1_BASE, EPWM_DC_MODULE_B, EPWM_DC_EVENT_2, EPWM_DC_EVENT_SOURCE_FILT_SIGNAL);

    //
    //	Set the digital filter signal source to DCBEVT2
    //
    EPWM_setDigitalCompareFilterInput(myEPWM1_BASE, EPWM_DC_WINDOW_SOURCE_DCBEVT2);
    //
    //	Enable Digital Compare Edge Filter
    //
    EPWM_enableDigitalCompareEdgeFilter(myEPWM1_BASE);
    //
    //	Set the edge count value of the digital comparison edge filter to 4
    //
    EPWM_setDigitalCompareEdgeFilterEdgeCount(myEPWM1_BASE, EPWM_DC_EDGEFILT_EDGECNT_4);

    //
    //  ET
    //	Enable ePWM1 interrupt
    //
    EPWM_enableInterrupt(myEPWM1_BASE);
    //
    //	Set the interrupt source for ePWM1 to TBCTR = 0
    //
    EPWM_setInterruptSource(myEPWM1_BASE, EPWM_INT_TBCTR_ZERO);
    //
    //	Set the interrupt event count value for ePWM1 to 3
    //
    EPWM_setInterruptEventCount(myEPWM1_BASE, 3);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init()
{
    myGPIO25_init();
}

void myGPIO25_init()
{
    GPIO_setDirectionMode(myGPIO25, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init()
{
    myINPUTXBARINPUT0_init();
}

void myINPUTXBARINPUT0_init()
{
    XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init()
{

    //
    // Interrupt Settings for INT_myEPWM1_ISR
    // ISR need to be defined for the registered interrupts
    //
    Interrupt_register(INT_myEPWM1, epwm1ISR);
    Interrupt_setPriority(INT_myEPWM1, 0, 0);
    Interrupt_enable(INT_myEPWM1);
    ECLIC_EnableIRQ(INT_myEPWM1);
}
#ifdef __cplusplus

#endif

