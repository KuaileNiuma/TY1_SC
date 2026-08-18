/**
 *************************************************************************************
 * @file xbat_ex01_clbxbar.c
 * @brief This file contains the source file for example xbat_ex01_clbxbar.
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

#include "xbar_ex01_clb_config.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

volatile uint32_t gClbFlag;


//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void PinMux_init(void);
void CLBXBAR_init(void);
void CLB_init(void);
void INPUTXBAR_init(void);

__INTERRUPT void CLB1ISR(void);
//*****************************************************************************
//
// INPUTXBAR_init - Initializes the Input XBAR with specified parameters
//
//*****************************************************************************


//*****************************************************************************
//
// main - Main function for XBAR input interrupt test
//
//*****************************************************************************
void main(void)
{
	uint32_t count;

    alb32r003x_evb_init();
    //
    // Initialize variables
    //
    gClbFlag = 0;
    
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);

    //
    // Register XINT1 interrupt handler
    //
	CPU_enableIrq();

    //
    // Register interrupt handler using C function
    //
    Interrupt_register(CLB1_IRQn, CLB1ISR);

    //
    // Set interrupt priority and enable interrupt
    //
    Interrupt_setPriority(CLB1_IRQn, 0, 0);
    Interrupt_enable(CLB1_IRQn);

    CLB_init();
    INPUTXBAR_init();
    CLBXBAR_init();
    initTILE0(CLB1_BASE);

    CLB_enableCLB(CLB1_BASE);

    while (!gClbFlag);
    gClbFlag = 0;
    count = HWREG(CLB1_BASE + CLB_LOGICCTL + CLB_O_DBG_C0);

    if (count == 0)
    {
    	printf("CLBXBAR Test FAIL!");
    }
    printf("CLBXBAR Test PASS!");
}

//*****************************************************************************
//
// PIN Configurations
//
//*****************************************************************************
void PinMux_init(void)
{
    GPIO_setDirectionMode(1,GPIO_DIR_MODE_OUT);
    GPIO_writePin(1,SET);
}


//*****************************************************************************
//
// CLB Configurations
//
//*****************************************************************************
void CLB_init(void)
{
    CLB_setOutputMask(CLB1_BASE,
                (0UL << 0UL), true);
    CLB_enableOutputMaskUpdates(CLB1_BASE);
    //
    // myCLB0 SPI Buffer Configuration
    //
    CLB_disableSPIBufferAccess(CLB1_BASE);
    CLB_configSPIBufferLoadSignal(CLB1_BASE, 0);
    CLB_configSPIBufferShift(CLB1_BASE, 0);
    //
    // myCLB0 CLB_IN0 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);
    CLB_enableSynchronization(CLB1_BASE, CLB_IN0);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN0, CLB_FILTER_NONE);
    CLB_disableInputPipelineMode(CLB1_BASE, CLB_IN0);
    CLB_setGPREG(CLB1_BASE,0);

    CLB_disableCLB(CLB1_BASE);
}

//*****************************************************************************
//
// CLBXBAR Configurations
//
//*****************************************************************************
void CLBXBAR_init(void)
{
    XBAR_invertCLBSignal(XBAR_AUXSIG0,false);

    XBAR_setCLBMuxConfig(XBAR_AUXSIG0, XBAR_CLB_MUX01_INPUTXBAR1);
    XBAR_enableCLBMux(XBAR_AUXSIG0, XBAR_MUX01);
}
//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(void)
{
    XBAR_setInputPin(INPUTXBAR_BASE,XBAR_INPUT1, 0);
}

//*****************************************************************************
//
// CLB1ISR - Interrupt handler for CLB
//
//*****************************************************************************
__INTERRUPT void CLB1ISR(void)
{
    uint32_t intTag = CLB_getInterruptTag(CLB1_BASE);
    CLB_configHLCEventSelect(CLB1_BASE, 0);
    if (intTag == 1)
    {
        gClbFlag = 1;
    }
    CLB_clearInterruptTag(CLB1_BASE);
}

