/**
 *************************************************************************************
 * @file clb_ex03_board.c
 * @brief This file contains the source file for example clb_ex03_board.
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

 #include "clb_ex03_board.h"


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
	RCC_APBL2PeriphClockCmd(CLB1_CLK_EN,ENABLE);
	RCC_APBL2PeriphClockCmd(GPIO1_CLK_EN,ENABLE);
	RCC_APBL1PeriphClockCmd(XBAR_CLK_EN,ENABLE);

    PinMux_init();
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
    GPIO_setPinConfig(myOUTPUTXBAR1_OUTPUTXBAR_PIN_CONFIG);

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
    XBAR_setOutputLatchMode(OUTPUTXBAR_BASE,myOUTPUTXBAR1, false);
    XBAR_invertOutputSignal(OUTPUTXBAR_BASE,myOUTPUTXBAR1, false);

    //
    //Mux configuration
    //
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, myOUTPUTXBAR1, XBAR_OUT_MUX01_CLB1_OUT4);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, myOUTPUTXBAR1, XBAR_MUX01);

}
