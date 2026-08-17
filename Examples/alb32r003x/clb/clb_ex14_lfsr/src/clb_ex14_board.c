/**
 *************************************************************************************
 * @file clb_ex14_board.c
 * @brief This file contains the source file for example clb_ex14_board.
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

#include "clb_ex14_board.h"

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
	CLB_configGlobalInputMux(myCLBForTILE1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM1A);
	CLB_configGPInputMux(myCLBForTILE1_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);
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
	CLB_configGlobalInputMux(myCLBForTILE1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1A);
	CLB_configGPInputMux(myCLBForTILE1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);
	CLB_enableSynchronization(myCLBForTILE1_BASE, CLB_IN1);
	CLB_selectInputFilter(myCLBForTILE1_BASE, CLB_IN1, CLB_FILTER_RISING_EDGE);
	CLB_disableInputPipelineMode(myCLBForTILE1_BASE, CLB_IN1);
	CLB_setGPREG(myCLBForTILE1_BASE,0);

	CLB_disableCLB(myCLBForTILE1_BASE);
}

