/**
 *************************************************************************************
 * @file clb_ex05_board.c
 * @brief This file contains the source file for example clb_ex05_board.
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

#include "clb_ex05_board.h"

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
	CLB_init();
	CLBXBAR_init();

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


}

//*****************************************************************************
//
// CLB Configurations
//
//*****************************************************************************
void CLB_init(){
	myTILE1_init();
	myTILE2_init();
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
	CLB_setGPREG(myTILE1_BASE,0);

	CLB_enableCLB(myTILE1_BASE);
}
void myTILE2_init(){
	CLB_setOutputMask(myTILE2_BASE,
				(0UL << 0UL), true);
	CLB_enableOutputMaskUpdates(myTILE2_BASE);
	//
	// myTILE2 SPI Buffer Configuration
	//
	CLB_disableSPIBufferAccess(myTILE2_BASE);
	CLB_configSPIBufferLoadSignal(myTILE2_BASE, 0);
	CLB_configSPIBufferShift(myTILE2_BASE, 0);
	//
	// myTILE2 CLB_IN0 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE2_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE2_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);
	CLB_configGPInputMux(myTILE2_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE2_BASE, CLB_IN0);
	CLB_selectInputFilter(myTILE2_BASE, CLB_IN0, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE2_BASE, CLB_IN0);
	//
	// myTILE2 CLB_IN1 initialization
	//
	// The following functions configure the CLB input mux and whether the inputs
	// have synchronization or pipeline enabled; check the device manual for more
	// information on when a signal needs to be synchronized or go through a
	// pipeline filter
	//
	CLB_configLocalInputMux(myTILE2_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
	CLB_configGlobalInputMux(myTILE2_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_CLB_AUXSIG1);
	CLB_configGPInputMux(myTILE2_BASE, CLB_IN1, CLB_GP_IN_MUX_EXTERNAL);
	CLB_enableSynchronization(myTILE2_BASE, CLB_IN1);
	CLB_selectInputFilter(myTILE2_BASE, CLB_IN1, CLB_FILTER_NONE);
	CLB_disableInputPipelineMode(myTILE2_BASE, CLB_IN1);
	CLB_setGPREG(myTILE2_BASE,0);

	CLB_enableCLB(myTILE2_BASE);
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

	XBAR_setCLBMuxConfig(myCLBXBAR0, XBAR_CLB_MUX09_CLB3_OUT4);
	XBAR_enableCLBMux(myCLBXBAR0, myCLBXBAR0_ENABLED_MUXES);
}
void myCLBXBAR1_init(){

	XBAR_setCLBMuxConfig(myCLBXBAR1, XBAR_CLB_MUX11_CLB3_OUT5);
	XBAR_enableCLBMux(myCLBXBAR1, myCLBXBAR1_ENABLED_MUXES);
}

