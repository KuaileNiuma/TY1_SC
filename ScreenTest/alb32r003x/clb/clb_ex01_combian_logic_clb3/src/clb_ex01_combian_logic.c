/**
 *************************************************************************************
 * @file clb_ex01_combian_logic.c
 * @brief This file contains the source file for example clb_ex01_combian_logic.
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
 
#include "xbar.h"
#include "device.h"
#include "hw_xbar.h"
#include "hw_clbxbar.h"
#include "hw_outputxbar.h"
#include "alb32r003x_evb.h"

#include "clb_ex01_board.h"
#include "clb_ex01_config.h"
#include "alb32r003x_screenTest.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define EDA_CSIM                  0             //set to 1 when make target for simulation

#if EDA_CSIM != 0
#define LOG_LEVEL                 LOG_ERROR
void _putchar(char character)
{
    //do nothing
}
#else
#define LOG_LEVEL                 LOG_INFO
#endif



int main(void) 
{
	uint32_t oldTicks;

	alb32r003x_evb_init();

	CPU_disableIrq();

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
	CPU_enableIrq();

	RCC_APBL2PeriphClockCmd(CLB3_CLK_EN,ENABLE);
	RCC_APBL2PeriphClockCmd(GPIO1_CLK_EN,ENABLE);
	RCC_APBL1PeriphClockCmd(XBAR_CLK_EN,ENABLE);
	RCC_AHB1PeriphClockCmd(EPWM1_CLK_EN,ENABLE);
	RCC_AHB1PeriphClockCmd(EPWM2_CLK_EN,ENABLE);

	CLB_init();
// OUTPUT TO IO

	XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT1,XBAR_OUT_MUX16_CLB3_OUT0);
	XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT1, XBAR_MUX16);
	XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT2,XBAR_OUT_MUX18_CLB3_OUT2);
	XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT2, XBAR_MUX18);

	delay_ms(5000);
	return SC_PASS;
}

