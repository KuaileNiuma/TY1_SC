/**
 *************************************************************************************
 * @file ecap_ex04_board.c
 * @brief This file contains the source file for example ecap_ex04_board.
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

#include "ecap_ex04_board.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

#define CounterResetOnEvent 1                  //!< Counter reset on event flag
#define ECAP_ECCTL2_SYNCI_EN_BIT 1             //!< Sync-in enable bit mask

//*****************************************************************************
//
// Board_init - Initialize board components
// 
//  This function initializes all board components including pin muxing,
//  INPUTXBAR setup, ECAP module configuration, GPIO setup, and interrupts.
//
//*****************************************************************************
void Board_init(void)
{
    PinMux_init();
    INPUTXBAR_init();
    ECAP_init();
    GPIO_init();
    INTERRUPT_init();
}

//*****************************************************************************
//
// PinMux_init - Initialize pin muxing for the board
// 
//  This function configures the GPIO pins for the required functionality,
//  including setting up pins for ECAP modules.
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    // EPWM1 -> myEPWM1 Pinmux
    //
    GPIO_setPinConfig(myEPWM1_EPWMA_PIN_CONFIG);
}

//*****************************************************************************
//
// ECAP_init - Initialize all ECAP modules
// 
//  This function initializes all ECAP modules (ECAP1, ECAP2, ECAP3) with the
//  required configuration for software synchronization functionality.
//
//*****************************************************************************
void ECAP_init(void)
{
    myECAP1_init();
    myECAP2_init();
    myECAP3_init();

    //
    // Output Sync Signal by SW.
    //
    ECAP_loadCounter(myECAP1_BASE);
}

//*****************************************************************************
//
// myECAP1_init - Initialize ECAP1 module in capture mode
// 
//  This function configures ECAP1 in capture mode with specified event
//  polarities, counter reset settings, and synchronization configuration
//  for software synchronization functionality.
//
//*****************************************************************************
void myECAP1_init(void)
{
    //
    //Turn on the ECAP1 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP1);
    //
    // Disables time stamp capture.
    //
    ECAP_disableTimeStampCapture(myECAP1_BASE);
    //
    // Stops Time stamp counter.
    //
    ECAP_stopCounter(myECAP1_BASE);
    //
    // Sets eCAP in Capture mode.
    //
    ECAP_enableCaptureMode(myECAP1_BASE);
    //
    // Sets the capture mode.
    //
    ECAP_setCaptureMode(myECAP1_BASE, ECAP_ONE_SHOT_CAPTURE_MODE, ECAP_EVENT_4);
    //
    // Sets the Capture event prescaler.
    //
    ECAP_setEventPrescaler(myECAP1_BASE, 0U);
    //
    // Sets the Capture event polarity.
    //
    ECAP_setEventPolarity(myECAP1_BASE, ECAP_EVENT_1, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP1_BASE, ECAP_EVENT_2, ECAP_EVNT_RISING_EDGE);
    ECAP_setEventPolarity(myECAP1_BASE, ECAP_EVENT_3, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP1_BASE, ECAP_EVENT_4, ECAP_EVNT_RISING_EDGE);
    //
    // Configure counter reset on events
    //
    ECAP_disableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_1);
    ECAP_disableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_2);
    ECAP_disableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_3);
    ECAP_disableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_4);
    //
    // Select eCAP input.
    //
    ECAP_selectECAPInput(myECAP1_BASE, ECAP_INPUT_INPUTXBAR7);
    //
    // Sets a phase shift value count.
    //
    ECAP_setPhaseShiftCount(myECAP1_BASE, 0U);
    //
    // Enable counter loading with phase shift value.
    //
    ECAP_enableLoadCounter(myECAP1_BASE);
    //
    // Load time stamp counter.
    //
    ECAP_loadCounter(myECAP1_BASE);
    //
    // Configures Sync out signal mode.
    //
    ECAP_setSyncOutMode(myECAP1_BASE, ECAP_SYNC_OUT_SYNCI);
    //
    // Configures emulation mode.
    //
    ECAP_setEmulationMode(myECAP1_BASE, ECAP_EMULATION_STOP);
    //
    // Set up the source for sync-in pulse.
    //
    //SysCtl_setECAPSyncInPulseSource(myECAP1_SYNC_IN_OFFSET, ECAP_SYNC_IN_PULSE_SRC_SYNCIN_EXT1);
    ECAP_setSyncInPulseSource(myECAP1_BASE, ECAP_ECAP1SYNCOUT);
    //
    // Starts Time stamp counter for myECAP1.
    //
    ECAP_startCounter(myECAP1_BASE);
    //
    // Enables time stamp capture for myECAP1.
    //
    ECAP_enableTimeStampCapture(myECAP1_BASE);
    //
    // Re-arms the eCAP module for myECAP1.
    //
    ECAP_reArm(myECAP1_BASE);
}

//*****************************************************************************
//
// myECAP2_init - Initialize ECAP2 module in capture mode
// 
//  This function configures ECAP2 in capture mode with specified event
//  polarities, counter reset settings, and synchronization configuration
//  for software synchronization functionality.
//
//*****************************************************************************
void myECAP2_init(void)
{
    //
    //Turn on the ECAP2 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP2);
    //
    // Disables time stamp capture.
    //
    ECAP_disableTimeStampCapture(myECAP2_BASE);
    //
    // Stops Time stamp counter.
    //
    ECAP_stopCounter(myECAP2_BASE);
    //
    // Sets eCAP in Capture mode.
    //
    ECAP_enableCaptureMode(myECAP2_BASE);
    //
    // Sets the capture mode.
    //
    ECAP_setCaptureMode(myECAP2_BASE, ECAP_ONE_SHOT_CAPTURE_MODE, ECAP_EVENT_4);
    //
    // Sets the Capture event prescaler.
    //
    ECAP_setEventPrescaler(myECAP2_BASE, 0U);
    //
    // Sets the Capture event polarity.
    //
    ECAP_setEventPolarity(myECAP2_BASE, ECAP_EVENT_1, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP2_BASE, ECAP_EVENT_2, ECAP_EVNT_RISING_EDGE);
    ECAP_setEventPolarity(myECAP2_BASE, ECAP_EVENT_3, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP2_BASE, ECAP_EVENT_4, ECAP_EVNT_RISING_EDGE);
    //
    // Configure counter reset on events
    //
    ECAP_disableCounterResetOnEvent(myECAP2_BASE, ECAP_EVENT_1);
    ECAP_disableCounterResetOnEvent(myECAP2_BASE, ECAP_EVENT_2);
    ECAP_disableCounterResetOnEvent(myECAP2_BASE, ECAP_EVENT_3);
    ECAP_disableCounterResetOnEvent(myECAP2_BASE, ECAP_EVENT_4);
    //
    // Select eCAP input.
    //
    ECAP_selectECAPInput(myECAP2_BASE, ECAP_INPUT_INPUTXBAR7);
    //
    // Sets a phase shift value count.
    //
    ECAP_setPhaseShiftCount(myECAP2_BASE, 0U);
    //
    // Enable counter loading with phase shift value.
    //
    ECAP_enableLoadCounter(myECAP2_BASE);
    //
    // Configures Sync out signal mode.
    //
    ECAP_setSyncOutMode(myECAP2_BASE, ECAP_SYNC_OUT_DISABLED);
    //
    // Configures emulation mode.
    //
    ECAP_setEmulationMode(myECAP2_BASE, ECAP_EMULATION_STOP);
    //
    // Set up the source for sync-in pulse.
    //
    //SysCtl_setECAPSyncInPulseSource(myECAP2_SYNC_IN_OFFSET, ECAP_SYNC_IN_PULSE_SRC_SYNCIN_EXT1);
    ECAP_setSyncInPulseSource(myECAP2_BASE, ECAP_ECAP1SYNCOUT);
    //
    // Starts Time stamp counter for myECAP2.
    //
    ECAP_startCounter(myECAP2_BASE);
    //
    // Enables time stamp capture for myECAP2.
    //
    ECAP_enableTimeStampCapture(myECAP2_BASE);
    //
    // Re-arms the eCAP module for myECAP2.
    //
    ECAP_reArm(myECAP2_BASE);
}

//*****************************************************************************
//
// myECAP3_init - Initialize ECAP3 module in capture mode
// 
//  This function configures ECAP3 in capture mode with specified event
//  polarities, counter reset settings, interrupt configuration, and
//  synchronization settings for software synchronization functionality.
//
//*****************************************************************************
void myECAP3_init(void)
{
    //
    //Turn on the ECAP3 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP3);
    //
    // Disable and clear all capture flags and interrupts
    //
    ECAP_disableInterrupt(myECAP3_BASE,
        (ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
        ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
        ECAP_ISR_SOURCE_COUNTER_PERIOD   |
        ECAP_ISR_SOURCE_COUNTER_COMPARE));
    ECAP_clearInterrupt(myECAP3_BASE,
        (ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
        ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
        ECAP_ISR_SOURCE_COUNTER_PERIOD   |
        ECAP_ISR_SOURCE_COUNTER_COMPARE));
    //
    // Disables time stamp capture.
    //
    ECAP_disableTimeStampCapture(myECAP3_BASE);
    //
    // Stops Time stamp counter.
    //
    ECAP_stopCounter(myECAP3_BASE);
    //
    // Sets eCAP in Capture mode.
    //
    ECAP_enableCaptureMode(myECAP3_BASE);
    //
    // Sets the capture mode.
    //
    ECAP_setCaptureMode(myECAP3_BASE, ECAP_ONE_SHOT_CAPTURE_MODE, ECAP_EVENT_4);
    //
    // Sets the Capture event prescaler.
    //
    ECAP_setEventPrescaler(myECAP3_BASE, 0U);
    //
    // Sets the Capture event polarity.
    //
    ECAP_setEventPolarity(myECAP3_BASE, ECAP_EVENT_1, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP3_BASE, ECAP_EVENT_2, ECAP_EVNT_RISING_EDGE);
    ECAP_setEventPolarity(myECAP3_BASE, ECAP_EVENT_3, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP3_BASE, ECAP_EVENT_4, ECAP_EVNT_RISING_EDGE);
    //
    // Configure counter reset on events
    //
    ECAP_disableCounterResetOnEvent(myECAP3_BASE, ECAP_EVENT_1);
    ECAP_disableCounterResetOnEvent(myECAP3_BASE, ECAP_EVENT_2);
    ECAP_disableCounterResetOnEvent(myECAP3_BASE, ECAP_EVENT_3);
    ECAP_disableCounterResetOnEvent(myECAP3_BASE, ECAP_EVENT_4);
    //
    // Select eCAP input.
    //
    ECAP_selectECAPInput(myECAP3_BASE, ECAP_INPUT_INPUTXBAR7);
    //
    // Sets a phase shift value count.
    //
    ECAP_setPhaseShiftCount(myECAP3_BASE, 0U);
    //
    // Enable counter loading with phase shift value.
    //
    ECAP_enableLoadCounter(myECAP3_BASE);
    //
    // Configures Sync out signal mode.
    //
    ECAP_setSyncOutMode(myECAP3_BASE, ECAP_SYNC_OUT_DISABLED);
    //
    // Configures emulation mode.
    //
    ECAP_setEmulationMode(myECAP3_BASE, ECAP_EMULATION_STOP);
    //
    // Set up the source for sync-in pulse.
    //
    //SysCtl_setECAPSyncInPulseSource(myECAP3_SYNC_IN_OFFSET, ECAP_SYNC_IN_PULSE_SRC_SYNCIN_EXT1);
    ECAP_setSyncInPulseSource(myECAP3_BASE, ECAP_ECAP1SYNCOUT);
    //
    // Starts Time stamp counter for myECAP3.
    //
    ECAP_startCounter(myECAP3_BASE);
    //
    // Enables time stamp capture for myECAP3.
    //
    ECAP_enableTimeStampCapture(myECAP3_BASE);
    //
    // Re-arms the eCAP module for myECAP3.
    //
    ECAP_reArm(myECAP3_BASE);
    //
    // Enables interrupt source for myECAP3.
    //
    ECAP_enableInterrupt(myECAP3_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    //
    // Clear interrupt flags for more interrupts.
    //
    ECAP_clearInterrupt(myECAP3_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(myECAP3_BASE);

}

//*****************************************************************************
//
// GPIO_init - Initialize GPIO modules
// 
//  This function initializes the GPIO modules required for the application.
//
//*****************************************************************************
void GPIO_init(void)
{
    myGPIO0_init();
}

//*****************************************************************************
//
// myGPIO0_init - Initialize GPIO for ECAP modules
// 
//  This function configures the GPIO pins associated with ECAP modules.
//
//*****************************************************************************
void myGPIO0_init(void)
{
    //
    // Set GPIO3 connect inputxbar7 for ecap input.
    //
	GPIO_setPinConfig(GPIO_3_GPIO3);
    GPIO_setDirectionMode(3, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// INPUTXBAR_init - Initialize INPUTXBAR modules
// 
//  This function initializes the INPUTXBAR modules required for signal routing.
//
//*****************************************************************************
void INPUTXBAR_init(void)
{
    myINPUTXBARINPUT0_init();
}

//*****************************************************************************
//
// myINPUTXBARINPUT0_init - Initialize INPUTXBAR for ECAP input
// 
//  This function configures the INPUTXBAR for routing signals to the ECAP modules.
//
//*****************************************************************************
void myINPUTXBARINPUT0_init(void)
{
    //
    // Configure XBAR routing
    //
    XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT_init - Initialize interrupts for ECAP module
// 
//  This function configures and enables the interrupts required for
//  ECAP module operation, including registering the interrupt handler.
//
//*****************************************************************************
void INTERRUPT_init(void)
{
    //
    // Register and configure ECAP3 interrupt
    //
    Interrupt_register(INT_myECAP3, Ecap3ISR);
    Interrupt_setPriority(INT_myECAP3, 0, 0);
    Interrupt_enable(INT_myECAP3);
    CPU_enableIrq();
}

#ifdef __cplusplus
}
#endif
