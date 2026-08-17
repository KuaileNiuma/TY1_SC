/**
 *************************************************************************************
 * @file xbar_ex07_outputInv.c
 * @brief This file contains the source file for example xbar_ex07_outputInv.
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
// main
//
//*****************************************************************************
void main(void)
{
	int i;

    alb32r003x_evb_init();

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);

	GPIO_setPinConfig(GPIO_1_GPIO1);
	GPIO_setPinConfig(GPIO_0_GPIO0);

	GPIO_setPinConfig(GPIO_2_OUTPUTXBAR1);
	GPIO_setPinConfig(GPIO_3_OUTPUTXBAR2);

	GPIO_setDirectionMode(0,GPIO_DIR_MODE_OUT);

	XBAR_setInputPin(INPUTXBAR_BASE,XBAR_INPUT1,1);

	XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE,XBAR_OUTPUT1,XBAR_OUT_MUX01_INPUTXBAR1);
	XBAR_enableOutputMux(OUTPUTXBAR_BASE,XBAR_OUTPUT1,XBAR_MUX01);
	XBAR_invertOutputSignal(OUTPUTXBAR_BASE,XBAR_OUTPUT1,1);

	XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE,XBAR_OUTPUT2,XBAR_OUT_MUX01_INPUTXBAR1);
	XBAR_enableOutputMux(OUTPUTXBAR_BASE,XBAR_OUTPUT2,XBAR_MUX01);

	while(1)
	{
		GPIO_writePin(0,1);
		for(i=0;i<5000;i++);
		GPIO_writePin(0,0);
		for(i=0;i<5000;i++);
	}
}


