/**
 *************************************************************************************
 * @file ecap_ex07_board.c
 * @brief This file contains the source file for example ecap_ex07_board.
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

#include "ecap_ex07_board.h"

//*****************************************************************************
//
// Function Definitions
//
//*****************************************************************************

//*****************************************************************************
//
// Board_init - Initialize board components
// 
//  This function initializes all board components including pin muxing,
//  INPUTXBAR setup, ECAP module configuration, and GPIO initialization.
//
//*****************************************************************************
void Board_init(void)
{
    PinMux_init();
    INPUTXBAR_init();
    ECAP_init();
    GPIO_init();
}

//*****************************************************************************
//
// PinMux_init - Initialize pin muxing for the board
// 
//  This function configures the GPIO pins for the required functionality,
//  including setting up pins for ECAP and PWM modules.
//
//*****************************************************************************
void PinMux_init(void)
{
	GPIO_setPinConfig(GPIO_1_GPIO1);
    GPIO_setDirectionMode(1, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// ECAP_init - Initialize ECAP modules
// 
//  This function initializes the ECAP module required for capture DMA functionality.
//
//*****************************************************************************
void ECAP_init(void)
{
    myECAP0_init();
}

//*****************************************************************************
//
// myECAP0_init - Initialize ECAP0 module in capture mode with DMA support
// 
//  This function configures ECAP0 in capture mode with specified event polarities,
//  capture modes, and DMA source configuration for transferring capture data
//  to memory automatically.
//
//*****************************************************************************
void myECAP0_init(void)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP1);
    //
    // Disable and clear all capture flags and interrupts
    //
    ECAP_disableInterrupt(myECAP_BASE, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
    ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
    ECAP_ISR_SOURCE_COUNTER_PERIOD |
    ECAP_ISR_SOURCE_COUNTER_COMPARE));
    
    ECAP_clearInterrupt(myECAP_BASE, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
    ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
    ECAP_ISR_SOURCE_COUNTER_PERIOD |
    ECAP_ISR_SOURCE_COUNTER_COMPARE));

    //
    // Disable time stamp capture temporarily during configuration
    //
    ECAP_disableTimeStampCapture(myECAP_BASE);

    //
    // Stop time stamp counter during configuration
    //
    ECAP_stopCounter(myECAP_BASE);

    //
    // Enable HR feature (commented out)
    //
    //HWREG(myECAP_BASE + 0x100) = 0x3;

    //
    // Set ECAP in capture mode
    //
    ECAP_enableCaptureMode(myECAP_BASE);

    //
    // Set continuous capture mode with event 4 as trigger
    //
    ECAP_setCaptureMode(myECAP_BASE, ECAP_ONE_SHOT_CAPTURE_MODE,
            ECAP_EVENT_4);

    //
    // Set capture event prescaler
    //
    ECAP_setEventPrescaler(myECAP_BASE, 0U);

    //
    // Set capture event polarities for rising and falling edges
    //
    ECAP_setEventPolarity(myECAP_BASE, ECAP_EVENT_1, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP_BASE, ECAP_EVENT_2, ECAP_EVNT_RISING_EDGE);
    ECAP_setEventPolarity(myECAP_BASE, ECAP_EVENT_3, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(myECAP_BASE, ECAP_EVENT_4, ECAP_EVNT_RISING_EDGE);

    //
    // Configure counter reset on events
    //
    ECAP_enableCounterResetOnEvent(myECAP_BASE, ECAP_EVENT_1);
    ECAP_enableCounterResetOnEvent(myECAP_BASE, ECAP_EVENT_2);
    ECAP_enableCounterResetOnEvent(myECAP_BASE, ECAP_EVENT_3);
    ECAP_enableCounterResetOnEvent(myECAP_BASE, ECAP_EVENT_4);

    //
    // Select ECAP input from INPUTXBAR3
    //
    ECAP_selectECAPInput(myECAP_BASE, ECAP_INPUT_INPUTXBAR3);

    //
    // Set phase shift value
    //
    ECAP_setPhaseShiftCount(myECAP_BASE, 0U);

    //
    // Disable counter loading with phase shift value
    //
    ECAP_disableLoadCounter(myECAP_BASE);

    //
    // Disable sync out signal mode
    //
    ECAP_setSyncOutMode(myECAP_BASE, ECAP_SYNC_OUT_DISABLED);

    //
    // Configure emulation mode to stop
    //
    ECAP_setEmulationMode(myECAP_BASE, ECAP_EMULATION_STOP);

    //
    // Start time stamp counter
    //
    ECAP_startCounter(myECAP_BASE);

    //
    // Enable time stamp capture
    //
    ECAP_enableTimeStampCapture(myECAP_BASE);

    //
    // Configure DMA source to event 4
    //
    ECAP_setDMASource(myECAP_BASE, ECAP_EVENT_4);

    //
    // Re-arm the ECAP module
    //
    ECAP_reArm(myECAP_BASE);
}

//*****************************************************************************
//
// GPIO_init - Initialize GPIO modules
// 
//  This function initializes the GPIO modules required for the application,
//  configuring pins for PWM and other functionality.
//
//*****************************************************************************
void GPIO_init(void)
{
    myGPIO0_init();
}

//*****************************************************************************
//
// myGPIO0_init - Initialize GPIO for EPWM1
// 
//  This function configures the GPIO pin for EPWM1 output, setting up the
//  pin mux for proper signal routing.
//
//*****************************************************************************
void myGPIO0_init(void)
{
    //
    // Configure GPIO0 as EPWM1_A output
    //
    GPIO_setPinConfig(GPIO_0_EPWM1_A);
}

//*****************************************************************************
//
// INPUTXBAR_init - Initialize INPUTXBAR modules
// 
//  This function initializes the INPUTXBAR modules required for routing
//  external signals to ECAP modules.
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
//  This function configures the INPUTXBAR input channel to route external
//  signals to the ECAP module for capture operations.
//
//*****************************************************************************
void myINPUTXBARINPUT0_init(void)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    //
    // Configure XBAR_INPUT3 with pin 1
    //
    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT3, 1);
}



#ifdef __cplusplus
}
#endif
