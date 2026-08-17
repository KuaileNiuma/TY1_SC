/**
 *************************************************************************************
 * @file xbat_ex05_ixbar_to_oxbar.c
 * @brief This file contains the source file for example xbat_ex05_ixbar_to_oxbar.
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

void INPUTXBAR_init(void);
void OUTPUTXBAR_init(void);

//*****************************************************************************
//
// main - Main function for XBAR input interrupt test
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);

    GPIO_setPinConfig(GPIO_2_OUTPUTXBAR1);

    GPIO_setDirectionMode(1,GPIO_DIR_MODE_OUT );
    GPIO_setDirectionMode(3,GPIO_DIR_MODE_IN );

    GPIO_writePin(1,RESET);

    INPUTXBAR_init();
    OUTPUTXBAR_init();

    GPIO_writePin(1,SET);

    while(!(GPIO_readPin(3)));

    printf("INPUTXBAR TO OUTPUTXBAR PASS!");
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(void)
{
    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT1, 0);
}
//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void OUTPUTXBAR_init(void)
{
    XBAR_setOutputLatchMode(OUTPUTXBAR_BASE, XBAR_OUTPUT1, false);
    XBAR_invertOutputSignal(OUTPUTXBAR_BASE, XBAR_OUTPUT1, false);

    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT1,XBAR_OUT_MUX01_INPUTXBAR1);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT1, XBAR_MUX01);
}

