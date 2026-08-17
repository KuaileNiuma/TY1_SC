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
#include "alb32r003x_evb.h"
#include "device.h"


extern int main_coremark(void);
uint64_t instret;



long time(void)
{
#if defined(__SYSTIMER_PRESENT) && (__SYSTIMER_PRESENT == 1)
    return SysTimer_GetLoadValue() / (SystemClock_Get() / 4);
#else
#error "This example require CPU System Timer feature"
#endif
}

/**
 * @brief Enable clocks of all on-chip peripherals
 *
 * Test requirement: run CoreMark with every peripheral clocked so that
 * the benchmark reflects full-system power/performance. Enables the
 * defined peripherals on the AHB1/AHB2/APBL1/APBL2 buses.
 */
static void RCC_EnableAllPeripheralClocks(void)
{
    /* AHB1 bus */
    RCC_AHB1PeriphClockCmd(EPWM1_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EPWM2_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EPWM3_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EPWM4_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EPWM5_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EPWM6_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EPWM7_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EPWM8_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(CMPSS1_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(CMPSS2_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(CMPSS3_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(CMPSS4_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(SDFM1_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(SDFM2_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EQEP1_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EQEP2_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(EQEP3_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ECAP1_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ECAP2_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ECAP3_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ECAP4_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ADC1_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ADC2_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ADC3_CLK_EN, ENABLE);
    RCC_AHB1PeriphClockCmd(ERM_CLK_EN, ENABLE);

    /* AHB2 bus */
    RCC_AHB2PeriphClockCmd(LCM_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(EFLASHC_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(HAC_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(MBX2_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(MBX1_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(QSPI_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(CSPIL_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(CSPIF_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(HACL_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(HACF_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(AES_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(XFLASHC_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(SMCM_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(DMASCH_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(DMA1_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(DMA2_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(DACC1_CLK_EN, ENABLE);
    RCC_AHB2PeriphClockCmd(DACC2_CLK_EN, ENABLE);

    /* APB low bus 1 */
    RCC_APBL1PeriphClockCmd(XBAR_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(I2C1_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(I2C2_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(I2C3_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(I2C4_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(BSPI1_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(BSPI2_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(BSPI3_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(BSPI4_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(CANFD1_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(CANFD2_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(USART1_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(USART2_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(UART1_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(UART2_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(NPU_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(HACL_REG_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(SYSCTL_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(WWDT_CLK_EN, ENABLE);
    RCC_APBL1PeriphClockCmd(IWDT_CLK_EN, ENABLE);

    /* APB low bus 2 */
    RCC_APBL2PeriphClockCmd(CLB1_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(CLB2_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(CLB3_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(CLB4_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(CRC_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(GPIO1_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(GPIO2_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(GPIO3_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(GPIO4_CLK_EN, ENABLE);
    RCC_APBL2PeriphClockCmd(GPIO5_CLK_EN, ENABLE);
}

int main(void)
{
	uint8_t ram;
	alb32r003x_evb_init();
	/* Enable all peripheral clocks (test requirement) */
	RCC_EnableAllPeripheralClocks();
	printf("ALB32R003x CoreMark!\r\n");
	printf("Core running @ %d MHz\r\n", SystemClock_Get()/1000/1000);
	printf("Code: 0x%08X, Data: 0x%08X\r\n", (uint32_t)main_coremark, (uint32_t)&ram);

    /* Initialize interrupt as CLINT interrupt mode, see MTVEC register description */

	__enable_minstret_counter();
	instret = __get_rv_instret();
	main_coremark();
	instret = __get_rv_instret() - instret;
	printf("instret in main_coremark: %u\n\n", (uint32_t)instret);

	for(;;);

	return 0;
}
