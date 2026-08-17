/**
 *************************************************************************************
 * @file clb_ex07_board.c
 * @brief This file contains the source file for example clb_ex07_board.
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

#include "clb_ex07_board.h"

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

	PinMux_init();
	CLB_init();
	GPIO_init();
	OUTPUTXBAR_init();

}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//

	// GPIO0 -> myGPIO0 Pinmux
	GPIO_setPinConfig(GPIO_0_GPIO0);
	//
	// OUTPUTXBAR1 -> myOUTPUTXBAR1 Pinmux
	//
	GPIO_setPinConfig(myOUTPUTXBAR1_OUTPUTXBAR_PIN_CONFIG);

}

//*****************************************************************************
//
// CLB Configurations
//
//*****************************************************************************
void CLB_init(){
	myTILE1_init();
}

void myTILE1_init(){
	CLB_setOutputMask(myTILE1_BASE,
				(0UL << 0UL), true);
	CLB_enableOutputMaskUpdates(myTILE1_BASE);
	//
	// myTILE1 SPI Buffer Configuration
	//
	CLB_disableSPIBufferAccess(myTILE1_BASE);
	CLB_configSPIBufferLoadSignal(myTILE1_BASE, 0);
	CLB_configSPIBufferShift(myTILE1_BASE, 0);
	//
	// myTILE1 CLB_IN0 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM1A);
	CLB_configGPInputMux(myTILE1_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);
	CLB_selectInputFilter(myTILE1_BASE, CLB_IN0, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE1_BASE, CLB_IN0);
	//
	// myTILE1 CLB_IN1 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1A);
	CLB_configGPInputMux(myTILE1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);
	CLB_selectInputFilter(myTILE1_BASE, CLB_IN1, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE1_BASE, CLB_IN1);
	//
	// myTILE1 CLB_IN2 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
	CLB_configGPInputMux(myTILE1_BASE, CLB_IN2, CLB_GP_IN_MUX_GP_REG);
	CLB_selectInputFilter(myTILE1_BASE, CLB_IN2, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE1_BASE, CLB_IN2);
	CLB_setGPREG(myTILE1_BASE,0);

	CLB_enableCLB(myTILE1_BASE);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	myGPIO0_init();
}

void myGPIO0_init(){
	GPIO_setDirectionMode(myGPIO0, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void OUTPUTXBAR_init(){
	myOUTPUTXBAR1_init();
}

void myOUTPUTXBAR1_init(){
	XBAR_setOutputLatchMode(OUTPUTXBAR_BASE, myOUTPUTXBAR1, false);
	XBAR_invertOutputSignal(OUTPUTXBAR_BASE, myOUTPUTXBAR1, false);

	//
	//Mux configuration
	//
	XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, myOUTPUTXBAR1, XBAR_OUT_MUX01_CLB1_OUT4);
	XBAR_enableOutputMux(OUTPUTXBAR_BASE, myOUTPUTXBAR1, XBAR_MUX01);
}

