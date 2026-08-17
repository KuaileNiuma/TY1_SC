/**
 *************************************************************************************
 * @file clb_board.c
 * @brief This file contains the source file.
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
#include "clb_board.h"

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
void Board_134_init()
{
    CLB_134_init();
}

//*****************************************************************************
//
// CLB Configurations
//
//*****************************************************************************
void CLB_134_init(){
    myCLB0_134_init();
}

void myCLB0_134_init(){
    CLB_enableNMI(myCLB0_BASE);
    CLB_setOutputMask(myCLB0_BASE,
                (0UL << 0UL), true);
    //
    // myCLB0 CLB_IN0 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN0, CLB_FILTER_NONE);
    //
    // myCLB0 CLB_IN1 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN1, CLB_FILTER_NONE);
    //
    // myCLB0 CLB_IN2 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN2, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN2, CLB_FILTER_NONE);
    //
    // myCLB0 CLB_IN3 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN3, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN3, CLB_FILTER_NONE);
    //
    // myCLB0 CLB_IN4 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN4, CLB_FILTER_NONE);
    //
    // myCLB0 CLB_IN5 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN5, CLB_FILTER_NONE);
    //
    // myCLB0 CLB_IN6 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN6, CLB_FILTER_NONE);
    //
    // myCLB0 CLB_IN7 initialization
    //
    // The following functions configure the CLB input mux and whether the inputs
    // have synchronization or pipeline enabled; check the device manual for more
    // information on when a signal needs to be synchronized or go through a
    // pipeline filter
    //
    CLB_configLocalInputMux(myCLB0_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(myCLB0_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGPInputMux(myCLB0_BASE, CLB_IN7, CLB_GP_IN_MUX_GP_REG);
    CLB_selectInputFilter(myCLB0_BASE, CLB_IN7, CLB_FILTER_NONE);
    CLB_setGPREG(myCLB0_BASE,63);

    CLB_disableCLB(myCLB0_BASE);
}

