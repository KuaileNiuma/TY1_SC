/**
 *************************************************************************************
 * @file xbat_ex03_ecapOUT.c
 * @brief This file contains the source file for example xbat_ex03_ecapOUT.
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
#include "device.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************

void OUTPUTXBAR_init(void);
void ECAP_init(uint32_t ecapBase);

//*****************************************************************************
//
// main - Main function for XBAR input interrupt test
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);

    OUTPUTXBAR_init();
    GPIO_setPinConfig(GPIO_14_OUTPUTXBAR3);

    ECAP_reArm(ECAP3_BASE);

    ECAP_enableLoadCounter(ECAP3_BASE);
    ECAP_startCounter(ECAP3_BASE);
    ECAP_loadCounter(ECAP3_BASE);
    ECAP_stopCounter(ECAP3_BASE);

    ECAP_init(ECAP3_BASE);

    ECAP_startCounter(ECAP3_BASE);

    while(1);
}

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void OUTPUTXBAR_init(void)
{
    XBAR_setOutputLatchMode(OUTPUTXBAR_BASE, XBAR_OUTPUT3, false);
    XBAR_invertOutputSignal(OUTPUTXBAR_BASE, XBAR_OUTPUT3, false);

    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT3,XBAR_OUT_MUX04_ECAP3_OUT);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT3, XBAR_MUX04);
}

//*****************************************************************************
//
// ECAP Configurations
//
//*****************************************************************************
void ECAP_init(uint32_t ecapBase)
{
    //Turn to APWM Mode
    ECAP_enableAPWMMode(ecapBase);
    //Set Frequence , Duty , active Polarity and Shift Phase
    ECAP_setAPWMPeriod(ecapBase,0x0001FFFF);
    ECAP_setAPWMCompare(ecapBase,0x000FFFF);
    ECAP_setAPWMPolarity(ecapBase,ECAP_APWM_ACTIVE_LOW);
    ECAP_setEmulationMode(ecapBase,ECAP_EMULATION_FREE_RUN);

    ECAP_enableLoadCounter(ecapBase);
    ECAP_resetCounters(ecapBase);

    ECAP_clearInterrupt(ecapBase,ECAP_ISR_SOURCE_COUNTER_PERIOD);
    ECAP_clearInterrupt(ecapBase,ECAP_ISR_SOURCE_COUNTER_COMPARE);
}
