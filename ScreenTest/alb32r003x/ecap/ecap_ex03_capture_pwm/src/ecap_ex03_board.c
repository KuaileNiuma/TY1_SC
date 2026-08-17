/**
 *************************************************************************************
 * @file ecap_ex03_board.c
 * @brief This file contains the source file for example ecap_ex03_board.
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
#include "ecap_ex03_board.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define CAP_CH            5                  //!< Capture channel number

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
//  including setting up pins for ECAP, EPWM, and OUTPUTXBAR signals.
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    // EPWM1 -> myEPWM1 Pinmux
    //
    GPIO_setPinConfig(myEPWM1_EPWMA_PIN_CONFIG);
    GPIO_setPinConfig(myEPWM1_EPWMB_PIN_CONFIG);
}

//*****************************************************************************
//
// ECAP_init - Initialize all ECAP modules
// 
//  This function initializes the ECAP module with the required configuration
//  for PWM capture functionality.
//
//*****************************************************************************
void ECAP_init(void)
{
    myECAP0_init();
}

//*****************************************************************************
//
// myECAP0_init - Initialize ECAP1 module in capture mode
// 
//  This function configures ECAP1 in capture mode with specified event
//  polarities, counter reset settings, and interrupt configuration
//  for PWM signal capture.
//
//*****************************************************************************
void myECAP0_init(void)
{
    //
    //Turn on the ECAP1 peripheral clock
    //
    SysCtl_enablePeripheral(myECAP1_CLK_EN);
    //
    // Disable and clear all capture flags and interrupts
    //
    ECAP_disableInterrupt(myECAP1_BASE, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
    ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
    ECAP_ISR_SOURCE_COUNTER_PERIOD |
    ECAP_ISR_SOURCE_COUNTER_COMPARE));
    ECAP_clearInterrupt(myECAP1_BASE, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
    ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
    ECAP_ISR_SOURCE_COUNTER_PERIOD |
    ECAP_ISR_SOURCE_COUNTER_COMPARE));
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
    ECAP_enableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_1);
    ECAP_enableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_2);
    ECAP_enableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_3);
    ECAP_enableCounterResetOnEvent(myECAP1_BASE, ECAP_EVENT_4);
    //
    // Select eCAP input.
    //
    ECAP_selectECAPInput(myECAP1_BASE, ECAP_INPUT_INPUTXBAR7);
    //
    // Sets a phase shift value count.
    //
    ECAP_setPhaseShiftCount(myECAP1_BASE, 0U);
    //
    // Disable counter loading with phase shift value.
    //
    ECAP_disableLoadCounter(myECAP1_BASE);
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
    ECAP_setSyncInPulseSource(myECAP1_BASE, ECAP_ECAP1SYNCOUT);
    //
    // Starts Time stamp counter for myECAP0.
    //
    ECAP_startCounter(myECAP1_BASE);
    //
    // Enables time stamp capture for myECAP0.
    //
    ECAP_enableTimeStampCapture(myECAP1_BASE);
    //
    // Re-arms the eCAP module for myECAP0.
    //
    ECAP_reArm(myECAP1_BASE);
    //
    // Enables interrupt source for myECAP0.
    //
    ECAP_enableInterrupt(myECAP1_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
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
// myGPIO0_init - Initialize GPIO for ECAP1
// 
//  This function configures the GPIO pins associated with ECAP1 module.
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
    //
    //Turn on the XBAR peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);

    myINPUTXBARINPUT0_init();
}

//*****************************************************************************
//
// myINPUTXBARINPUT0_init - Initialize INPUTXBAR for ECAP1 input
// 
//  This function configures the INPUTXBAR and OUTPUTXBAR for routing signals
//  to the ECAP1 module.
//
//*****************************************************************************
void myINPUTXBARINPUT0_init(void)
{
//    //
//    // Configure CLB output LUT and enable CLB
//    //
//    CLB_configOutputLUT(CLB1_BASE, CLB_OUT0, 0X550018);
//    CLB_enableCLB(CLB1_BASE);
    //
    // Configure XBAR routing
    //
    XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT,
            myINPUTXBARINPUT0_SOURCE);
//    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT1,
//            XBAR_OUT_MUX01_CLB1_OUT1);
//    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT1, XBAR_MUX01);
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
    // Register and configure ECAP1 interrupt
    //
    Interrupt_register(ECAP1_IRQn, Ecap1ISR);
    Interrupt_setPriority(ECAP1_IRQn, 0, 0);
    Interrupt_enable(ECAP1_IRQn);
    CPU_enableIrq();
}

#ifdef __cplusplus
}
#endif
