/**
 *************************************************************************************
 * @file ecap_ex01_board.c
 * @brief This file contains the source file for example ecap_ex01_board.
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
#include "ecap_ex01_board.h"

//*****************************************************************************
//
// Board_init - Initialize board components
// 
//  This function initializes all board components including pin muxing,
//  output XBAR configuration, and ECAP module setup.
//
//*****************************************************************************
void Board_init(void)
{
    PinMux_init();
    OUTPUTXBAR_init();
    ECAP_init();
}

//*****************************************************************************
//
// PinMux_init - Initialize GPIO pin multiplexing
// 
//  This function configures the GPIO pin multiplexing settings for modules
//  assigned to the CPU, specifically setting up GPIO_5 for OUTPUTXBAR3.
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    //Turn on the GPIO1 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    //
    // PinMux for modules assigned to CPU
    //
    GPIO_setPinConfig(GPIO_5_OUTPUTXBAR3);
}

//*****************************************************************************
//
// ECAP_init - Initialize ECAP modules
// 
//  This function initializes all ECAP modules used in the application,
//  currently calling myECAP0_init() to set up ECAP0.
//
//*****************************************************************************
void ECAP_init(void)
{
    myECAP0_init();
}

//*****************************************************************************
//
// myECAP0_init - Initialize ECAP0 in APWM mode
// 
//  This function configures ECAP0 in APWM mode, setting up the period,
//  compare value, polarity, phase shift, and other necessary parameters.
//  It also starts the time stamp counter after configuration.
//
//*****************************************************************************
void myECAP0_init(void)
{
    //
    //Turn on the ECAP1 peripheral clock
    //
    SysCtl_enablePeripheral(myECAP0_CLK_EN);
    //
    // Stops Time stamp counter.
    //
    ECAP_stopCounter(myECAP0_BASE);
    //
    // Sets eCAP in APWM mode.
    //
    ECAP_enableAPWMMode(myECAP0_BASE);
    //
    // Set eCAP APWM period.
    //
    ECAP_setAPWMPeriod(myECAP0_BASE,4000000U);
    //
    // Set eCAP APWM on or off time count.
    //
    ECAP_setAPWMCompare(myECAP0_BASE,1000000U);
    //
    // Set eCAP APWM polarity.
    //
    ECAP_setAPWMPolarity(myECAP0_BASE, ECAP_APWM_ACTIVE_HIGH);
    //
    // Sets a phase shift value count.
    //
    ECAP_setPhaseShiftCount(myECAP0_BASE, 0U);
    //
    // Disable counter loading with phase shift value.
    //
    ECAP_disableLoadCounter(myECAP0_BASE);
    //
    // Configures Sync out signal mode.
    //
    ECAP_setSyncOutMode(myECAP0_BASE, ECAP_SYNC_OUT_SYNCI);
    //
    // Configures emulation mode.
    //
    ECAP_setEmulationMode(myECAP0_BASE, ECAP_EMULATION_STOP);
    //
    // Set up the source for sync-in pulse..
    //
    ECAP_setSyncInPulseSource(myECAP0_BASE, ECAP_DISABLESYNCI);
    //
    // Starts Time stamp counter for myECAP0.
    //
    ECAP_startCounter(myECAP0_BASE);
}

//*****************************************************************************
//
// OUTPUTXBAR_init - Initialize OUTPUTXBAR modules
// 
//  This function initializes all OUTPUTXBAR modules used in the application,
//  currently calling myOUTPUTXBAR0_init() to set up OUTPUTXBAR0.
//
//*****************************************************************************
void OUTPUTXBAR_init(void)
{
    myOUTPUTXBAR0_init();
}

//*****************************************************************************
//
// myOUTPUTXBAR0_init - Initialize OUTPUTXBAR0 for ECAP1 output
// 
//  This function configures OUTPUTXBAR0 to route ECAP1 output signal to the
//  appropriate GPIO pin, setting up mux configuration, signal inversion,
//  and latch mode.
//
//*****************************************************************************
void myOUTPUTXBAR0_init(void)
{
    //
    //Turn on the ECAP1 peripheral clock
    //
    SysCtl_enablePeripheral(myOUTPUTXBAR0_CLK_EN);
    //
    // Mux configuration
    //
    XBAR_enableOutputMux(myOUTPUTXBAR0_BASE, myOUTPUTXBAR0, XBAR_MUX00);
    //
    // Set output mux config to route ECAP1 output
    //
    XBAR_setOutputMuxConfig(myOUTPUTXBAR0_BASE, myOUTPUTXBAR0,
            XBAR_OUT_MUX00_ECAP1_OUT);
    //
    // Disable signal inversion
    //
    XBAR_invertOutputSignal(myOUTPUTXBAR0_BASE, myOUTPUTXBAR0, false);
    //
    // Disable output latch mode
    //
    XBAR_setOutputLatchMode(myOUTPUTXBAR0_BASE, myOUTPUTXBAR0, false);
}

