/**
 *************************************************************************************
 * @file main.c
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

#include <stdio.h>
#include "device.h"
#include "device_init.h"
#include "alb32r003x_evb.h"
#include "aci_main.h"
#include "debug.h"

uint64_t instret;

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
	uint8_t ram;
	alb32r003x_evb_init();

	printf("\r\nALB32R003x ACI Motor Benchmark!\r\n");
	printf("Core running @ %d MHz\r\n", SystemClock_Get()/1000000);
	printf("Code: 0x%08X, Data: 0x%08X\r\n", (uint32_t)ACI_main, (uint32_t)&ram);

	//
    // Initialize interrupt as CLINT interrupt mode, see MTVEC register description
    //
#ifdef ZHANLU
	printf("ZHANLU enable....\r\n");
#endif

	__RV_CSR_SET(CSR_MSTATUS, MSTATUS_XS);

	RCC_AHB1PeriphClockCmd(ADC1_CLK_EN, ENABLE);
	RCC_AHB1PeriphClockCmd(EPWM1_CLK_EN, ENABLE);
	RCC_AHB1PeriphClockCmd(EPWM2_CLK_EN, ENABLE);
	RCC_AHB1PeriphClockCmd(EPWM3_CLK_EN, ENABLE);

	ACI_main();

	for(;;);

	return 0;
}

