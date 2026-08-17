/**
 *************************************************************************************
 * @file clb_ex12_board.c
 * @brief This file contains the source file for example clb_ex12_board.
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

#include "clb_ex12_board.h"

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
	CLB_init();
	CLBXBAR_init();
	GPIO_init();
	OUTPUTXBAR_init();

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
	// PinMux for modules assigned to CPU1
	//

	// GPIO1 -> myGPIO1Input Pinmux
	GPIO_setPinConfig(GPIO_1_GPIO1);
	// GPIO0 -> myGPIO0Input Pinmux
	GPIO_setPinConfig(GPIO_0_GPIO0);
	//
	// OUTPUTXBAR1 -> myOUTPUTXBAR0 Pinmux
	//
	GPIO_setPinConfig(myOUTPUTXBAR0_OUTPUTXBAR_PIN_CONFIG);

}

//*****************************************************************************
//
// CLB Configurations
//
//*****************************************************************************
void CLB_init(){
	myCLBForTILE1_init();
}

void myCLBForTILE1_init(){
	CLB_setOutputMask(myCLBForTILE1_BASE,
				(0UL << 0UL), true);
	CLB_enableOutputMaskUpdates(myCLBForTILE1_BASE);
	//
	// myCLBForTILE1 SPI Buffer Configuration
	//
	CLB_disableSPIBufferAccess(myCLBForTILE1_BASE);
	CLB_configSPIBufferLoadSignal(myCLBForTILE1_BASE, 0);
	CLB_configSPIBufferShift(myCLBForTILE1_BASE, 0);
	//
	// myCLBForTILE1 CLB_IN0 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myCLBForTILE1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myCLBForTILE1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);
	CLB_configGPInputMux(myCLBForTILE1_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myCLBForTILE1_BASE, CLB_IN0);
	CLB_selectInputFilter(myCLBForTILE1_BASE, CLB_IN0, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myCLBForTILE1_BASE, CLB_IN0);
	//
	// myCLBForTILE1 CLB_IN1 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myCLBForTILE1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myCLBForTILE1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_CLB_AUXSIG1);
	CLB_configGPInputMux(myCLBForTILE1_BASE, CLB_IN1, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myCLBForTILE1_BASE, CLB_IN1);
	CLB_selectInputFilter(myCLBForTILE1_BASE, CLB_IN1, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myCLBForTILE1_BASE, CLB_IN1);
	CLB_setGPREG(myCLBForTILE1_BASE,0);

	CLB_disableCLB(myCLBForTILE1_BASE);
}

//*****************************************************************************
//
// CLBXBAR Configurations
//
//*****************************************************************************
void CLBXBAR_init(){
	myCLBXBAR0_init();
	myCLBXBAR1_init();
}

void myCLBXBAR0_init(){

	XBAR_setCLBMuxConfig(myCLBXBAR0, XBAR_CLB_MUX01_INPUTXBAR1);
	XBAR_enableCLBMux(myCLBXBAR0, myCLBXBAR0_ENABLED_MUXES);
}
void myCLBXBAR1_init(){

	XBAR_setCLBMuxConfig(myCLBXBAR1, XBAR_CLB_MUX03_INPUTXBAR2);
	XBAR_enableCLBMux(myCLBXBAR1, myCLBXBAR1_ENABLED_MUXES);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	myGPIO1Input_init();
	myGPIO0Input_init();
}

void myGPIO1Input_init(){
	GPIO_setDirectionMode(myGPIO1Input, GPIO_DIR_MODE_IN);
}
void myGPIO0Input_init(){
	GPIO_setDirectionMode(myGPIO0Input, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
	myINPUTXBARINPUT0_init();
	myINPUTXBARINPUT1_init();
}

void myINPUTXBARINPUT0_init(){
	XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}
void myINPUTXBARINPUT1_init(){
	XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT1_INPUT, myINPUTXBARINPUT1_SOURCE);
}

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void OUTPUTXBAR_init(){
	myOUTPUTXBAR0_init();
}

void myOUTPUTXBAR0_init(){
	XBAR_setOutputLatchMode(OUTPUTXBAR_BASE, myOUTPUTXBAR0, false);
	XBAR_invertOutputSignal(OUTPUTXBAR_BASE, myOUTPUTXBAR0, false);

	//
	//Mux configuration
	//
	XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, myOUTPUTXBAR0, XBAR_OUT_MUX01_CLB1_OUT4);
	XBAR_enableOutputMux(OUTPUTXBAR_BASE, myOUTPUTXBAR0, XBAR_MUX01);
}

