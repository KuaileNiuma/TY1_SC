/**
 *************************************************************************************
 * @file epwm_ex13_board.c
 * @brief This file contains the source file for example epwm_ex13_board.
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
 
#include "epwm_ex13_board.h"

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
    CMPSS_init();
    EPWM_init();
    EPWMXBAR_init();
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
    //
    //Turn on the GPIOA peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    //
    //Turn on the GPIOc peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOC);
    //
    // CMPSS1 -> myCMPSS1 Pinmux
    //
	GPIO_setPinConfig(GPIO_224_GPIO224);
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

    // GPIO6 -> myGPIO6 Pinmux
    GPIO_setPinConfig(GPIO_6_GPIO6);

}

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
void CMPSS_init()
{
    myCMPSS1_init();
}

//*****************************************************************************
//
// CMPSS1 initialization function
//
//*****************************************************************************
void myCMPSS1_init()
{
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS1);
    //
    //Select the value for CMP1HPMXSEL
    //
	SysCtl_selectCMPHPMux(SYSCTL_CMPHPMUX_SELECT_1,0U);
    //
    //Select the value for CMP1LPMXSEL
    //
	SysCtl_selectCMPLPMux(SYSCTL_CMPLPMUX_SELECT_1,0U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSS_configHighComparator(myCMPSS1_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSS_configLowComparator(myCMPSS1_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSS_configDAC(myCMPSS1_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSS_setDACValueHigh(myCMPSS1_BASE,0U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSS_setDACValueLow(myCMPSS1_BASE,0U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSS_configFilterHigh(myCMPSS1_BASE, 0U, 1U, 1U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSS_configFilterLow(myCMPSS1_BASE, 0U, 1U, 1U);
    //
    // Sets the output signal configuration for the high comparator.
    //
    CMPSS_configOutputsHigh(myCMPSS1_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the output signal configuration for the low comparator.
    //
    CMPSS_configOutputsLow(myCMPSS1_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSS_setHysteresis(myCMPSS1_BASE,0U);
    //
    // Configures the comparator subsystem's ramp generator.
    //
    CMPSS_configRamp(myCMPSS1_BASE,0U,0U,0U,1U,true);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCHigh(myCMPSS1_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCLow(myCMPSS1_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSS_configBlanking(myCMPSS1_BASE,1U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSS_disableBlanking(myCMPSS1_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSS_configLatchOnPWMSYNC(myCMPSS1_BASE,false,false);
    //
    // Enables the CMPSS module.
    //
    CMPSS_enableModule(myCMPSS1_BASE);
    //
    // Delay for CMPSS DAC to power up.
    //
    delay_ms(500);

    CMPSS_setDACValueHigh(myCMPSS1_BASE,2500U);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init()
{
    myEPWM1_init();
    myEPWM2_init();
    myEPWM3_init();
}

//*****************************************************************************
//
// ePWM1 initialization function
//
//********************************************myEPWMXBAR4*********************************
void myEPWM1_init()
{
    //
    //	ePWM1 Configurations
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //  TB
    //	Enable Global shadow load mode
    //
    EPWM_enableGlobalLoad(myEPWM1_BASE);
    //
    //	Enable One shot global shadow to active load
    //
    EPWM_enableGlobalLoadOneShotMode(myEPWM1_BASE);
    EPWM_setGlobalLoadTrigger(myEPWM1_BASE,EPWM_GL_LOAD_PULSE_CNTR_ZERO);
    EPWM_setGlobalLoadEventPrescale(myEPWM1_BASE,1);
    //
    //	Set One shot global shadow to active load pulse
    //
    EPWM_setGlobalLoadOneShotLatch(myEPWM1_BASE);
    //
    //	Set 1(1*1) frequency division
    //
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    //
    //	Set TBPRD = 125
    //
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 125);
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
    //	A synchronization signal is sent when TBCTR = 0
    //
    EPWM_enableSyncOutPulseSource(myEPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);


    //
    //	Set CMPA = 69
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 69);
    //
    //	Enable CMPA_CMPAHR a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM1_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    //	Set CMPA = 69
    //
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 69);
    //
    //	Enable CMPB_CMPBHR a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM1_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);
    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);


    //
    //	Enable AQCTLA_AQCTLA2 a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM1_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);
    //
    //	TBCTR = UP_CMPA -> ePWM1A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    //	TBCTR = DOWN_CMPA -> ePWM1A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    //	Enable AQCTLB_AQCTLB2 a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM1_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);
    //
    //	TBCTR = UP_CMPB -> ePWM1B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    //	TBCTR = DOWN_CMPB -> ePWM1B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);


    //
    //	Set the input source for the dead zone to ePWM1A
    //
    EPWM_setRisingEdgeDeadBandDelayInput(myEPWM1_BASE,EPWM_DB_INPUT_EPWMA);
    //
    //	Set dead zone rising edge delay polarity reversal
    //
    EPWM_setDeadBandDelayPolarity(myEPWM1_BASE, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_LOW);
    //
    //	Enabling dead zone rising edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM1_BASE, EPWM_DB_RED, true);
    //
    //	Dead zone rising edge delay 20 TBCTR
    //
    EPWM_setRisingEdgeDelayCount(myEPWM1_BASE, 20);
    //
    //	Set the input source for the dead zone to ePWM1A
    //
    EPWM_setFallingEdgeDeadBandDelayInput(myEPWM1_BASE,EPWM_DB_INPUT_EPWMA);
    //
    //	Set dead zone falling edge delay polarity not reversed
    //
    EPWM_setDeadBandDelayPolarity(myEPWM1_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    //	Enable dead zone fall edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM1_BASE, EPWM_DB_FED, true);
    //
    //	Falling edge delay 20 TBCTR
    //
    EPWM_setFallingEdgeDelayCount(myEPWM1_BASE, 20);


    //
    //	Enable ePWM interrupt
    //
    EPWM_enableInterrupt(myEPWM1_BASE);
    //
    //	Sets the ePWM interrupt source to TBCTR = 0
    //
    EPWM_setInterruptSource(myEPWM1_BASE, EPWM_INT_TBCTR_ZERO);
    //
    //  Sets the ePWM interrupt event counts to 1
    //
    EPWM_setInterruptEventCount(myEPWM1_BASE,3);
}

//*****************************************************************************
//
// ePWM2 initialization function
//
//*****************************************************************************
void myEPWM2_init()
{
    //
    //	ePWM2 Configurations
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    //  TB
    //	Enable Global shadow load mode
    //
    EPWM_enableGlobalLoad(myEPWM2_BASE);
    //
    //	Enable One shot global shadow to active load
    //
    EPWM_enableGlobalLoadOneShotMode(myEPWM2_BASE);
    EPWM_setGlobalLoadTrigger(myEPWM2_BASE,EPWM_GL_LOAD_PULSE_CNTR_ZERO);
    EPWM_setGlobalLoadEventPrescale(myEPWM2_BASE,1);
    //
    //	Set One shot global shadow to active load pulse
    //
    EPWM_setGlobalLoadOneShotLatch(myEPWM2_BASE);
//    //
//    //	Force a software One shot global shadow to active load pulse
//    //
//    EPWM_forceGlobalLoadOneShotEvent(myEPWM2_BASE);
    //
    //	Link ePWM2's GLDCTL2 to ePWM1
    //
    EPWM_setupEPWMLinks(myEPWM2_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_GLDCTL2);
    //
    //	Set 1(1*1) frequency division
    //
    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    //
    //	Set TBPRD = 125
    //
    EPWM_setTimeBasePeriod(myEPWM2_BASE, 125);
    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0);
    //
    //	Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //
    //	Set up the source for sync-in pulse is ePWM1
    //
    EPWM_setSyncInPulseSource(myEPWM2_BASE, EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1);
    //
    //	Enable phase shift load
    //
    EPWM_enablePhaseShiftLoad(myEPWM2_BASE);
    //
    //	Set TBPHS = 83
    //
    EPWM_setPhaseShift(myEPWM2_BASE, 83);
    //
    //	Countmode after sync: UP
    //
    EPWM_setCountModeAfterSync(myEPWM2_BASE,EPWM_COUNT_MODE_UP_AFTER_SYNC);


    //
    //  CC
    //	Set CMPA = 69
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, 69);
    //
    //	Enable CMPA_CMPAHR a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM2_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    //	Link ePWM2's COMP_A to ePWM1
    //
    EPWM_setupEPWMLinks(myEPWM2_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_A);
    //
    //	Set CMPB = 69
    //
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, 69);
    //
    //	Enable CMPB_CMPBHR a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM2_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    //	Link ePWM2's COMP_B to ePWM1
    //
    EPWM_setupEPWMLinks(myEPWM2_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_B);


    //
    //  AQ
    //	Enable AQCTLA_AQCTLA2 a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM2_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);
    //
    //	TBCTR = UP_CMPA -> ePWM2A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    //	TBCTR = DOWN_CMPA -> ePWM2A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    //	Enable AQCTLB_AQCTLB2 a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM2_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);
    //
    //	TBCTR = UP_CMPB -> ePWM2B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    //	TBCTR = DOWN_CMPB -> ePWM2B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);


    //
    //  DB
    //	Set the input source for the dead zone to ePWM2A
    //
    EPWM_setRisingEdgeDeadBandDelayInput(myEPWM2_BASE,EPWM_DB_INPUT_EPWMA);
    //
    //	Set dead zone falling edge delay polarity reversal
    //
    EPWM_setDeadBandDelayPolarity(myEPWM2_BASE, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_LOW);
    //
    //	Enabling dead zone rising edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM2_BASE, EPWM_DB_RED, true);
    //
    //	Dead zone rising edge delay 20 TBCTR
    //
    EPWM_setRisingEdgeDelayCount(myEPWM2_BASE, 20);

    //
    //	Set the input source for the dead zone to ePWM2A
    //
    EPWM_setFallingEdgeDeadBandDelayInput(myEPWM2_BASE,EPWM_DB_INPUT_EPWMA);
    //
    //	Set dead zone falling edge delay polarity reversal
    //
    EPWM_setDeadBandDelayPolarity(myEPWM2_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    //	Enable dead zone fall edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM2_BASE, EPWM_DB_FED, true);
    //
    //	Falling edge delay 20 TBCTR
    //
    EPWM_setFallingEdgeDelayCount(myEPWM2_BASE, 20);


    //
    //  TZ
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM2A:LOW
    //
    EPWM_setTripZoneAction(myEPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);
    //
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM2B:LOW
    //
    EPWM_setTripZoneAction(myEPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);
    //
    //  DCAEVT2 CBC event trip zone signal  was enabled
    //
    EPWM_enableTripZoneSignals(myEPWM2_BASE, EPWM_TZ_SIGNAL_DCAEVT2);
    //
    //	CBC event trip zone signal Interrupt was enabled
    //
    EPWM_enableTripZoneInterrupt(myEPWM2_BASE, EPWM_TZ_INTERRUPT_CBC);


    //
    //  DC
    //	When a DCAH event occurs, a TRIPIN4 signal is emitted
    //
    EPWM_selectDigitalCompareTripInput(myEPWM2_BASE, EPWM_DC_TRIP_TRIPIN4, EPWM_DC_TYPE_DCAH);
    //
    //	When DCXH_HIGH event occurs, an A2 signal is emitted
    //
    EPWM_setTripZoneDigitalCompareEventCondition(myEPWM2_BASE, EPWM_TZ_DC_OUTPUT_A2, EPWM_TZ_EVENT_DCXH_HIGH);
}
//*****************************************************************************
//
// ePWM3 initialization function
//
//*****************************************************************************
void myEPWM3_init()
{
    //
    //	ePWM3 Configurations
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    //  TB
    //	Enable Global shadow load mode
    //
    EPWM_enableGlobalLoad(myEPWM3_BASE);
    //
    //	Enable One shot global shadow to active load
    //
    EPWM_enableGlobalLoadOneShotMode(myEPWM3_BASE);
    EPWM_setGlobalLoadTrigger(myEPWM3_BASE,EPWM_GL_LOAD_PULSE_CNTR_ZERO);
    EPWM_setGlobalLoadEventPrescale(myEPWM3_BASE,1);
    //
    //	Set One shot global shadow to active load pulse
    //
    EPWM_setGlobalLoadOneShotLatch(myEPWM3_BASE);
//    //
//    //	Force a software One shot global shadow to active load pulse
//    //
//    EPWM_forceGlobalLoadOneShotEvent(myEPWM3_BASE);
    //
    //	Link ePWM3's GLDCTL2 to ePWM1
    //
    EPWM_setupEPWMLinks(myEPWM3_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_GLDCTL2);
    //
    //	Set 1(1*1) frequency division
    //
    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    //
    //	Set TBPRD = 125
    //
    EPWM_setTimeBasePeriod(myEPWM3_BASE, 125);
    //
    //	Set TBCTR = 0
    //
    EPWM_setTimeBaseCounter(myEPWM3_BASE, 0);
    //
    //	Counting mode: UP_DOWN
    //
    EPWM_setTimeBaseCounterMode(myEPWM3_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //
    //	Set up the source for sync-in pulse is ePWM1
    //
    EPWM_setSyncInPulseSource(myEPWM3_BASE, EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1);
    //
    //	Enable phase shift load
    //
    EPWM_enablePhaseShiftLoad(myEPWM3_BASE);
    //
    //	Set TBPHS = 166
    //
    EPWM_setPhaseShift(myEPWM3_BASE, 83);
    //
    //	Countmode after sync: DOWN
    //
    EPWM_setCountModeAfterSync(myEPWM3_BASE,EPWM_COUNT_MODE_DOWN_AFTER_SYNC);


    //
    // CC
    // Set CMPA = 500
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, 69);
    //
    //	Enable CMPA_CMPAHR a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM3_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);
    //
    //	Load the new CMPA when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    //	Link ePWM3's COMP_A to ePWM1
    //
    EPWM_setupEPWMLinks(myEPWM3_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_A);
    //
    //	Set CMPB = 69
    //
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, 69);
    //
    //	Enable CMPB_CMPBHR a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM3_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);
    //
    //	Load the new CMPB when TBCTR = 0
    //
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    //	Link ePWM3's COMP_B to ePWM1
    //
    EPWM_setupEPWMLinks(myEPWM3_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_B);


    //
    // AQ
    // Enable AQCTLA_AQCTLA2 a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM3_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);
    //
    //	TBCTR = UP_CMPA -> ePWM3A:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    //	TBCTR = DOWN_CMPA -> ePWM3A:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    //
    //	Enable AQCTLB_AQCTLB2 a register to be loaded Globally
    //
    EPWM_enableGlobalLoadRegisters(myEPWM2_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);
    //
    //	TBCTR = UP_CMPB -> ePWM3B:HIGH
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //
    //	TBCTR = DOWN_CMPB -> ePWM3B:LOW
    //
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);


    //
    // DB
    // Set the input source for the dead zone to ePWM3A
    //
    EPWM_setRisingEdgeDeadBandDelayInput(myEPWM3_BASE,EPWM_DB_INPUT_EPWMA);
    //
    //	Set dead zone falling edge delay polarity reversal
    //
    EPWM_setDeadBandDelayPolarity(myEPWM3_BASE, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_LOW);
    //
    //	Enabling dead zone rising edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM3_BASE, EPWM_DB_RED, true);
    //
    // Dead zone rising edge delay 20 TBCTR
    //
    EPWM_setRisingEdgeDelayCount(myEPWM3_BASE, 20);
    //
    //	Set the input source for the dead zone to ePWM2A
    //
    EPWM_setFallingEdgeDeadBandDelayInput(myEPWM3_BASE,EPWM_DB_INPUT_EPWMA);
    //
    //	Set dead zone falling edge delay polarity reversal
    //
    EPWM_setDeadBandDelayPolarity(myEPWM3_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    //
    //	Enable dead zone fall edge delay
    //
    EPWM_setDeadBandDelayMode(myEPWM3_BASE, EPWM_DB_FED, true);
    //
    //	Falling edge delay 20 TBCTR
    //
    EPWM_setFallingEdgeDelayCount(myEPWM3_BASE, 20);

    //
    //TZ
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM3A:LOW
    //
    EPWM_setTripZoneAction(myEPWM3_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);
    //
    //	When TZ1-TZ6, DCAEVT2, DCAEVT1 occur -> ePWM3B:LOW
    //
    EPWM_setTripZoneAction(myEPWM3_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);
    //
    //  One-shot TZ1 event trip zone signal was enabled
    //
    EPWM_enableTripZoneSignals(myEPWM3_BASE, EPWM_TZ_SIGNAL_OSHT1);
    //
    //	OST event trip zone signal Interrupt was enabled
    //
    EPWM_enableTripZoneInterrupt(myEPWM3_BASE, EPWM_TZ_INTERRUPT_OST);
}

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void EPWMXBAR_init()
{
    myEPWMXBAR4_init();
}

//*****************************************************************************
//
// EPWMXBAR4 initialization function
//
//*****************************************************************************
void myEPWMXBAR4_init()
{
    XBAR_setEPWMMuxConfig(myEPWMXBAR4, XBAR_EPWM_MUX00_CMPSS1_CTRIPH);
    XBAR_enableEPWMMux(myEPWMXBAR4, XBAR_MUX00);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init()
{

    myGPIO6_init();
}

//*****************************************************************************
//
// GPIO6 initialization function
//
//*****************************************************************************
void myGPIO6_init()
{

    GPIO_setDirectionMode(myGPIO6, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init()
{
    //
    //Turn on the XBAR peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    myINPUTXBARINPUT0_init();
}

//*****************************************************************************
//
// INPUTXBARINPUT0 initialization function
//
//*****************************************************************************
void myINPUTXBARINPUT0_init()
{
    XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init()
{

    //
    // Interrupt Settings for INT_myEPWM1
    // ISR need to be defined for the registered interrupts
    //
    Interrupt_register(EPWM1_IRQn, INT_myEPWM1_ISR);
    Interrupt_setPriority(EPWM1_IRQn, 0, 0);
    Interrupt_enable(EPWM1_IRQn);
    ECLIC_EnableIRQ(EPWM1_IRQn);

    //
    // Interrupt Settings for INT_myEPWM2_TZ
    // ISR need to be defined for the registered interrupts
    //
    Interrupt_register(EPWM2TZ_IRQn, INT_myEPWM2_TZ_ISR);
    Interrupt_setPriority(EPWM2TZ_IRQn, 0, 0);
    Interrupt_enable(EPWM2TZ_IRQn);
    ECLIC_EnableIRQ(EPWM2TZ_IRQn);

    //
    // Interrupt Settings for INT_myEPWM3_TZ
    // ISR need to be defined for the registered interrupts
    //
    Interrupt_register(EPWM3TZ_IRQn, INT_myEPWM3_TZ_ISR);
    Interrupt_setPriority(EPWM3TZ_IRQn, 0, 0);
    Interrupt_enable(EPWM3TZ_IRQn);
    ECLIC_EnableIRQ(EPWM3TZ_IRQn);
}
#ifdef __cplusplus
#endif

