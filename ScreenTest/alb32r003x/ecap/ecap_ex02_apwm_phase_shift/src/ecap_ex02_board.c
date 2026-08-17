/**
 *************************************************************************************
 * @file ecap_ex02_board.c
 * @brief This file contains the source file for example ecap_ex02_board.
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

#include "ecap_ex02_board.h"

//*****************************************************************************
//
// Board_init - Initialize board components
// 
//  This function initializes all board components including pin muxing,
//  ECAP module setup, and OUTPUTXBAR configuration.
//
//*****************************************************************************
void Board_init(void)
{
    PinMux_init();
    ECAP_init();
    OUTPUTXBAR_init();
}

//*****************************************************************************
//
// PinMux_init - Initialize pin muxing for the board
// 
//  This function configures the GPIO pins for the required functionality,
//  including setting up pins for OUTPUTXBAR signals.
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    //Turn on the GPIO1 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    GPIO_setPinConfig(GPIO_5_OUTPUTXBAR3);
    GPIO_setPinConfig(GPIO_6_OUTPUTXBAR4);
}

//*****************************************************************************
//
// myECAP0_init - Initialize ECAP1 module in APWM mode
// 
//  This function configures ECAP1 in APWM mode with specified period,
//  compare value, and phase shift settings.
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
    ECAP_setAPWMPeriod(myECAP0_BASE, PWM_PRD_VAL);
    //
    // Set eCAP APWM on or off time count.
    //
    ECAP_setAPWMCompare(myECAP0_BASE, PWM_CMP_VAL);
    //
    // Set eCAP APWM polarity.
    //
    ECAP_setAPWMPolarity(myECAP0_BASE, ECAP_APWM_ACTIVE_LOW);
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
    ECAP_setSyncOutMode(myECAP0_BASE, ECAP_SYNC_OUT_COUNTER_PRD);
    //
    // Configures emulation mode.
    //
    ECAP_setEmulationMode(myECAP0_BASE, ECAP_EMULATION_STOP);
    //
    // Starts Time stamp counter for myECAP0.
    //
    ECAP_startCounter(myECAP0_BASE);
}

//*****************************************************************************
//
// myECAP1_init - Initialize ECAP2 module in APWM mode with phase shift
// 
//  This function configures ECAP2 in APWM mode with specified period,
//  compare value, phase shift settings, and sync-in configuration.
//
//*****************************************************************************
void myECAP1_init(void)
{
    //
    //Turn on the ECAP2 peripheral clock
    //
    SysCtl_enablePeripheral(myECAP1_CLK_EN);
    //
    // Stops Time stamp counter.
    //
    ECAP_stopCounter(myECAP1_BASE);
    //
    // Sets eCAP in APWM mode.
    //
    ECAP_enableAPWMMode(myECAP1_BASE);
    //
    // Set eCAP APWM period.
    //
    ECAP_setAPWMPeriod(myECAP1_BASE, PWM_PRD_VAL);
    //
    // Set eCAP APWM on or off time count.
    //
    ECAP_setAPWMCompare(myECAP1_BASE, PWM_CMP_VAL);
    //
    // Set eCAP APWM polarity.
    //
    ECAP_setAPWMPolarity(myECAP1_BASE, ECAP_APWM_ACTIVE_LOW);
    //
    // Sets a phase shift value count.
    //
    ECAP_setPhaseShiftCount(myECAP1_BASE, PWM_PHASE_VAL);
    //
    // Enable counter loading with phase shift value.
    //
    ECAP_enableLoadCounter(myECAP1_BASE);
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
    // Starts Time stamp counter for myECAP1.
    //
    ECAP_startCounter(myECAP1_BASE);
}

//*****************************************************************************
//
// ECAP_init - Initialize all ECAP modules
// 
//  This function initializes both ECAP modules (ECAP1 and ECAP2) with their
//  respective configurations.
//
//*****************************************************************************
void ECAP_init(void)
{
    myECAP0_init();
    myECAP1_init();
}

//*****************************************************************************
//
// myOUTPUTXBAR0_init - Initialize OUTPUTXBAR0 for ECAP1
// 
//  This function configures OUTPUTXBAR0 to output the ECAP1 signal to the
//  appropriate GPIO pin.
//
//*****************************************************************************
void myOUTPUTXBAR0_init(void)
{
    XBAR_setOutputLatchMode(OUTPUTXBAR_BASE, myOUTPUTXBAR0, false);
    XBAR_invertOutputSignal(OUTPUTXBAR_BASE, myOUTPUTXBAR0, false);

    //
    // Mux configuration
    //
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, myOUTPUTXBAR0,
            XBAR_OUT_MUX00_ECAP1_OUT);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, myOUTPUTXBAR0,
            myOUTPUTXBAR0_ENABLED_MUXES);
}

//*****************************************************************************
//
// myOUTPUTXBAR1_init - Initialize OUTPUTXBAR1 for ECAP2
// 
//  This function configures OUTPUTXBAR1 to output the ECAP2 signal to the
//  appropriate GPIO pin.
//
//*****************************************************************************
void myOUTPUTXBAR1_init(void)
{
    XBAR_setOutputLatchMode(OUTPUTXBAR_BASE, myOUTPUTXBAR1, false);
    XBAR_invertOutputSignal(OUTPUTXBAR_BASE, myOUTPUTXBAR1, false);

    //
    // Mux configuration
    //
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, myOUTPUTXBAR1,
            XBAR_OUT_MUX02_ECAP2_OUT);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, myOUTPUTXBAR1,
            myOUTPUTXBAR1_ENABLED_MUXES);
}

//*****************************************************************************
//
// OUTPUTXBAR_init - Initialize all OUTPUTXBAR channels
// 
//  This function initializes both OUTPUTXBAR channels (OUTPUTXBAR0 and
//  OUTPUTXBAR1) with their respective configurations.
//
//*****************************************************************************
void OUTPUTXBAR_init(void)
{
    //
    //Turn on the ECAP1 peripheral clock
    //
    SysCtl_enablePeripheral(myOUTPUTXBAR_CLK_EN);
    myOUTPUTXBAR0_init();
    myOUTPUTXBAR1_init();
}

#ifdef __cplusplus
}
#endif
