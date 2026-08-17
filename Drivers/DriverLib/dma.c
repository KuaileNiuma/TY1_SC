/**
 *************************************************************************************
 * @file dma.c
 * @brief This file implements the function of dma driver.
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

#include "dma.h"


//*****************************************************************************
//
// DMA_configAddresses
//
//*****************************************************************************
#if DMAC_HW_VER == 0x01
const DMA_MasterInfSelect dmaMasterInterface[] = { //MASTER1=MASTER2
	    [DMAMUX_ReqId_dma_GEN0] = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_GEN1] = DMA_AHB_MASTER_1,
	    [DMAMUX_ReqId_dma_GEN2] = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_GEN3] = DMA_AHB_MASTER_1,
	    [DMAMUX_ReqId_dma_GEN4] = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_GEN5] = DMA_AHB_MASTER_1,
	    [DMAMUX_ReqId_dma_GEN6] = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_GEN7] = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_ADC1_INT1] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC1_INT2] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC1_INT3] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC1_INT4] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC1_EVT ] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC2_INT1] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC2_INT2] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC2_INT3] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC2_INT4] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC2_EVT ] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC3_INT1] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC3_INT2] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC3_INT3] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC3_INT4] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ADC3_EVT ] = DMA_AHB_MASTER_3,

		[DMAMUX_ReqId_dma_XINT1]     = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_XINT2]     = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_XINT3]     = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_XINT4]     = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_XINT5]     = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_FFT_W]     = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_FFT_R]     = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_W    ]     = DMA_AHB_MASTER_3,  
		[DMAMUX_ReqId_dma_R    ]     = DMA_AHB_MASTER_3,  

		[DMAMUX_ReqId_dma_LIN1_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_LIN1_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_LIN2_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_LIN2_RX]   = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_SYNC_TRIG] = DMA_AHB_MASTER_1, 

		[DMAMUX_ReqId_dma_BSPI1_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_BSPI1_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_BSPI2_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_BSPI2_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_BSPI3_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_BSPI3_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_BSPI4_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_BSPI4_RX]   = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_USB_EPX_RX1]= DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_USB_EPX_RX1]= DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_USB_EPX_RX2]= DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_USB_EPX_RX2]= DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_USB_EPX_RX3]= DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_USB_EPX_RX3]= DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_UART3_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART3_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART4_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART4_RX]   = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_SCA_IN ]    = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_SCA_OUT]    = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_EPG1_INT]   = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_IIC1_TX]    = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_IIC1_RX]    = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_IIC2_TX]    = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_IIC2_RX]    = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART1_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART1_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART2_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART2_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART5_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART5_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART6_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART6_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART7_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART7_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART8_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_UART8_RX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_PMBUS_TX]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_PMBUS_RX]   = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_EPWM1_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM1_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM2_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM2_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM3_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM3_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM4_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM4_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM5_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM5_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM6_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM6_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM7_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM7_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM8_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM8_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM9_SOCA] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM9_SOCB] = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM10_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM10_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM11_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM11_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM12_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM12_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM13_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM13_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM14_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM14_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM15_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM15_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM16_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM16_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_CPU1_TINT0] = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_CPU1_TINT1] = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_CPU1_TINT2] = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_EPWM17_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM17_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM18_SOCA]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_EPWM18_SOCB]= DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ECAP1_DMA]  = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ECAP2_DMA]  = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ECAP3_DMA]  = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ECAP4_DMA]  = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ECAP5_DMA]  = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ECAP6_DMA]  = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_ECAP7_DMA]  = DMA_AHB_MASTER_3,

		[DMAMUX_ReqId_dma_CLB5_INT]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_CLB6_INT]   = DMA_AHB_MASTER_1,

		[DMAMUX_ReqId_dma_CLB1_INT]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_CLB2_INT]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_CLB3_INT]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_CLB4_INT]   = DMA_AHB_MASTER_1,
		[DMAMUX_ReqId_dma_SDFM1_FLT1_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM1_FLT2_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM1_FLT3_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM1_FLT4_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM2_FLT1_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM2_FLT2_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM2_FLT3_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM2_FLT4_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM3_FLT1_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM3_FLT2_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM3_FLT3_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM3_FLT4_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM4_FLT1_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM4_FLT2_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM4_FLT3_DRINT]   = DMA_AHB_MASTER_3,
		[DMAMUX_ReqId_dma_SDFM4_FLT4_DRINT]   = DMA_AHB_MASTER_3,

};
#endif
#if DMAC_HW_VER == 0x00
const DMA_MasterInfSelect dmaMasterInterface[] = {
		    [DMAMUX_ReqId_dma_GEN0] = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_GEN1] = DMA_AHB_MASTER_1,
		    [DMAMUX_ReqId_dma_GEN2] = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_GEN3] = DMA_AHB_MASTER_1,
		    [DMAMUX_ReqId_dma_GEN4] = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_GEN5] = DMA_AHB_MASTER_1,
		    [DMAMUX_ReqId_dma_GEN6] = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_GEN7] = DMA_AHB_MASTER_1,

			//
			//DMA2_1 can only access memory addresses corresponding to MSPI. DMA2_2 can only access MSPI registers. DMA1 can access all.
			//
			[DMAMUX_ReqId_dma_MSPI_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_MSPI_RX] = DMA_AHB_MASTER_2,

			//
			//DMA2_1 cannot access
			//
			[DMAMUX_ReqId_dma_SPI1_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SPI1_RX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SPI2_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SPI2_RX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SPI3_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SPI3_RX] = DMA_AHB_MASTER_2,

			//
			//DMA2_1 cannot access
			//
			[DMAMUX_ReqId_dma_USART1_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_USART1_RX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_USART2_RX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_USART2_RX] = DMA_AHB_MASTER_2,

			//
			//DMA2_1 cannot access
			//
			[DMAMUX_ReqId_dma_SMBUS_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SMBUS_RX] = DMA_AHB_MASTER_2,

			//
			//DMA2_1 cannot access
			//
			[DMAMUX_ReqId_dma_I2C1_TX ]= DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_I2C1_RX ]= DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_I2C2_TX ]= DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_I2C2_RX ]= DMA_AHB_MASTER_2,

			//
			//DMA2_1 cannot access
			//
			[DMAMUX_ReqId_dma_UART1_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_UART1_RX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_UART2_TX] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_UART2_RX] = DMA_AHB_MASTER_2,

			[DMAMUX_ReqId_max] = 256,

			[DMAMUX_ReqId_dma_ADC1_INT1] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC1_INT2] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC1_INT3] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC1_INT4] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC1_EVT ] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC2_INT1] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC2_INT2] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC2_INT3] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC2_INT4] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC2_EVT ] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC3_INT1] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC3_INT2] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC3_INT3] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC3_INT4] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ADC3_EVT ] = DMA_AHB_MASTER_2,

			[DMAMUX_ReqId_dma_XINT1]     = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_XINT2]     = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_XINT3]     = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_XINT4]     = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_XINT5]     = DMA_AHB_MASTER_1,

			[DMAMUX_ReqId_dma_EPWM1_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM1_SOCB] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM2_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM2_SOCB] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM3_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM3_SOCB] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM4_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM4_SOCB] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM5_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM5_SOCB] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM6_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM6_SOCB] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM7_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM7_SOCB] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM8_SOCA] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_EPWM8_SOCB] = DMA_AHB_MASTER_2,


			[DMAMUX_ReqId_dma_ECAP1]       = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ECAP2]       = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_ECAP3]       = DMA_AHB_MASTER_2,

			[DMAMUX_ReqId_dma_SDFM1_FLT1_DPINT] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SDFM1_FLT2_DPINT] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SDFM1_FLT3_DPINT] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SDFM1_FLT4_DPINT] = DMA_AHB_MASTER_2,

			[DMAMUX_ReqId_dma_SDFM2_FLT1_DPINT] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SDFM2_FLT2_DPINT] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SDFM2_FLT3_DPINT] = DMA_AHB_MASTER_2,
			[DMAMUX_ReqId_dma_SDFM2_FLT4_DPINT] = DMA_AHB_MASTER_2,

			[DMAMUX_ReqId_dma_CLB1_INT]      = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_CLB2_INT]      = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_CLB3_INT]      = DMA_AHB_MASTER_1,
			[DMAMUX_ReqId_dma_CLB4_INT]      = DMA_AHB_MASTER_1,


};

#endif

void DMA_configAddresses(uint32_t base, uint32_t destAddr, uint32_t srcAddr)
{

    //
    // Set up SOURCE address.
    //
    HWREG(base + DMA_O_SAR) = (uint32_t)srcAddr;

    //
    // Set up DESTINATION address.
    //
    HWREG(base + DMA_O_DAR) = (uint32_t)destAddr;
}


//*****************************************************************************
//
// DMA_configBurst
//
//*****************************************************************************
void DMA_configBurst(uint32_t base, uint16_t size, int16_t srcStep,
                     int16_t destStep)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));
    ASSERT((size >= 1U) && (size <= 32U));

    //
    // Set up BURST registers.
    //
    HWREG(base + DMA_O_CTL) = ((HWREG(base + DMA_O_CTL) & (~(DMA_CTL_DST_MSIZE | DMA_CTL_SRC_MSIZE))) | ((size << 11) | (size << 14)));
}
#if DMAC_HW_VER == 0x01
void DMA_configLLP(uint32_t base, DMA_LLI loc, DMA_MasterInfSelect lms )
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Set up SOURCE address.
    //
    HWREG(base + DMA_O_LLP) = (uint32_t)((((uint32_t)loc) & 0xfffffffc) | (((uint32_t)lms) & 0x00000003));

}
#endif
//*****************************************************************************
//
// DMA_configTransfer
//
//*****************************************************************************
void DMA_configTransfer(uint32_t base, uint32_t transferSize, int16_t srcStep,
                        int16_t destStep)
{
//    uint32_t burst_size;
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));

    //
    // Set up TRANSFER registers.
    //

    DMAREGH(base, DMA_O_CTL) = ((DMAREGH(base, DMA_O_CTL) & (~(DMA_CTL_BLOCK_TS >> 32))) | (transferSize));
}

//*****************************************************************************
//
// DMA_configParameter
//
//*****************************************************************************
void DMA_configParameter(DMA_ConfigParams *Params)
{
	Params->blockTS=2;
	Params->chPriority=0;
	Params->destAddr=0;
	Params->destAddrDirect=DMA_ADDR_INCRE;
	Params->destBtl=DMA_BTL_4;
	Params->destTrWidthBytes=DMA_TR_WIDTH_BYTE_1;
	Params->dmaDstReqId=0;
	Params->dmaSrcReqId=0;
	Params->enableInterrupt=true;
	Params->srcAddr=0;
	Params->srcAddrDirect=DMA_ADDR_INCRE;
	Params->srcBtl=DMA_BTL_4;
	Params->srcTrWidthBytes=DMA_TR_WIDTH_BYTE_1;
	Params->ttfc=DMA_TT_FC_0_M2M_DMAC;
#if DMAC_HW_VER == 0x01
	Params->genNum=0;
	Params->lli0=0;
	Params->llpDst=false;
	Params->llpSrc=false;
	Params->reloadDst=0;
	Params->reloadSrc=0;
#endif
}

#if DMAC_HW_VER == 0x01
//*****************************************************************************
//
// DMA_configChannel
//
//*****************************************************************************
void DMA_configChannel(uint32_t base, const DMA_ConfigParams *transfParams)
{
    uint32_t high = 0;
    uint32_t low = 0;

    //
    // uint32_t dmamuxBase = 0U;
    //
    uint32_t channel = 0U;
    uint32_t dma_num = 0U;
    DMA_HandshakingSelect srcHkSelect;
    DMA_HandshakingSelect destHkSelect;
    DMA_MasterInfSelect srcMISelect;
    DMA_MasterInfSelect destMISelect;
    DMA_HK_HARDWARE_INF   srcHardInf;
    DMA_HK_HARDWARE_INF   destHardInf;
    DMA_HK_HARDWARE_INF   srcMuxNum;
    DMA_HK_HARDWARE_INF   destMuxNum;

    ASSERT(DMA_isBaseValid(base));
#if !(DMAMUX_RGCR_P2P_SUPPORT)
    //
    // Not support DMAMUX P2P trigger case,
    //
    ASSERT((transfParams->dmaSrcReqId < DMAMUX_ReqId_max) ||
            (transfParams->ttfc == DMA_TT_FC_2_P2M_DMAC) ||
            (transfParams->ttfc == DMA_TT_FC_4_P2M_P) ||
            (transfParams->ttfc == DMA_TT_FC_1_M2P_DMAC) ||
            (transfParams->ttfc == DMA_TT_FC_5_P2P_SP));
#endif

    //
    // Covert the channel base to the channel number and the dmamux base address..
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dma_num = DMA_convertChnBase2DmaNum(base);

    //
    // Forced distribution of the handshake signals by channel.
    //
    switch (transfParams->ttfc)
    {
        case DMA_TT_FC_2_P2M_DMAC:
        case DMA_TT_FC_4_P2M_P:
            srcHkSelect  = DMA_HKS_HARDWARE;
            destHkSelect = DMA_HKS_SOFTWARE;
            srcMISelect=dmaMasterInterface[transfParams->dmaSrcReqId];
            destMISelect=DMA_AHB_MASTER_1;
            break;

        case DMA_TT_FC_1_M2P_DMAC:
        case DMA_TT_FC_6_M2P_P:
            srcHkSelect  = DMA_HKS_SOFTWARE;
            destHkSelect = DMA_HKS_HARDWARE;
            srcMISelect=DMA_AHB_MASTER_1;
            destMISelect=dmaMasterInterface[transfParams->dmaDstReqId];
            break;

        case DMA_TT_FC_3_P2P_DMAC:
        case DMA_TT_FC_5_P2P_SP:
        case DMA_TT_FC_7_P2P_DP:
            srcHkSelect  = DMA_HKS_HARDWARE;
            destHkSelect = DMA_HKS_HARDWARE;
            srcMISelect=dmaMasterInterface[transfParams->dmaSrcReqId];
            destMISelect=dmaMasterInterface[transfParams->dmaDstReqId];
            break;

        default:
            srcHkSelect  = DMA_HKS_SOFTWARE;
            destHkSelect = DMA_HKS_SOFTWARE;
            srcMISelect=DMA_AHB_MASTER_1;
            destMISelect=DMA_AHB_MASTER_1;
            break;
    }

    //
    // DMA_HKS_HARD_INF_0 used as source handshaking signal of channel0
    // DMA_HKS_HARD_INF_1 used as dest handshaking signal of channel0
    // DMA_HKS_HARD_INF_2 used as source handshaking signal of channel1
    // DMA_HKS_HARD_INF_3 used as dest handshaking signal of channel1
    // DMA_HKS_HARD_INF_14 used as source handshaking signal of channel7
    // DMA_HKS_HARD_INF_15 used as dest handshaking signal of channel7
    //
    srcHardInf   = 2* channel;
    destHardInf  = 2* channel + 1U;

    //
    // Configure DMA Channel
    //
    DMA_configAddresses(base, transfParams->destAddr, transfParams->srcAddr);
    DMA_configLLP(base,transfParams->lli0 ,DMA_AHB_MASTER_1);//TODO:default to be master1


    low+=(transfParams->llpSrc<<28);
    low+=(transfParams->llpDst<<27);
    // 
    // Src Master
    //
    low += (srcMISelect<<25);

    // 
    // Dst master
    //
    low += (destMISelect<<23);

    // 
    // TransType 0=m2m, 1=m2p, 2=p2m, 3=p2p, 4=p2m_fc_p, 5=p2p_fc_sp, ......
    //
    low += (transfParams->ttfc<<20);

    // 
    // Src Burst Size, 1/4/8/.../256cnt
    //
    low += (transfParams->srcBtl<<14);

    // 
    // Dst Burst Size, 1/4/8/.../256cnt
    //
    low += (transfParams->destBtl<<11);

    // 
    // SrcInc, 0=increment src addr
    //
    low += (transfParams->srcAddrDirect<<9);

    // 
    // DstInc, 2=unchanged dst addr
    //
    low += (transfParams->destAddrDirect<<7);

    // 
    // Src_Tr_Width, 8/16/32/.../256bit, 2=32bit
    //
    low += (transfParams->srcTrWidthBytes<<4);

    // 
    // Dst_Tr_Width, 8/16/32/.../256bit, 2=32bit
    //
    low += (transfParams->destTrWidthBytes<<1);

    // 
    // Interrupt enable, it's used to mask all interrupts related to this channel
    //
    low += (transfParams->enableInterrupt<<0);



    // 
    // bit44, DONE
    //
    high = (1<<12);

    // 
    // Bit32~x, Block_Ts max is 4095
    //
    high += (transfParams->blockTS & 0x00000fff);

    DMA_configChannelCTL(base, (uint64_t)high << 32 | low);



    low = (transfParams->chPriority<<5);

    // 
    // Bit_11, HS_SEL_DST select handshaking source
    //
    low += (srcHkSelect<<11);

    // 
    // Bit_10, HS_SEL_SRC select handshaking source
    //
    low += (destHkSelect<<10);

    // 
    // Bit_30, RELOAD_SRC Automatic Source Reload
    //
    low += (transfParams->reloadSrc<<30);

    // 
    // Bit_31, RELOAD_DST Automatic Destination Reload
    //
    low += (transfParams->reloadDst<<31);

    // 
    // Bit_39, SRC_PER select handshaking source //MUX channel number, source end
    //
    high = (srcHardInf<<7);

    // 
    // Bit_43, DST_PER select handshaking source //MUX channel number, destination end
    //
    high += (destHardInf<<11);  

    DMA_configChannelCFG(base, (uint64_t)high << 32 | low);

    if(dma_num==1)
    {
    	srcMuxNum=srcHardInf;
    	destMuxNum=destHardInf;

    }else
    {
    	srcMuxNum=srcHardInf+16;
    	destMuxNum=destHardInf+16;
    }


    if (transfParams->ttfc == DMA_TT_FC_2_P2M_DMAC || transfParams->ttfc == DMA_TT_FC_3_P2P_DMAC ||
        transfParams->ttfc == DMA_TT_FC_4_P2M_P || transfParams->ttfc == DMA_TT_FC_5_P2P_SP || transfParams->ttfc == DMA_TT_FC_7_P2P_DP)
    {
    	if(transfParams->dmaSrcReqId>=DMAMUX_ReqId_max)
    	{
    		DMASCH_GENChannelDisable(DMASCH,transfParams->genNum);
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,0);

    		DMASCH_selectTRGSource(DMASCH,transfParams->genNum,(transfParams->dmaSrcReqId-DMAMUX_ReqId_max));
    		DMASCH_setTRGPolarity(DMASCH,transfParams->genNum,DMASCH_GCR_TPOL_RISE);
    		DMASCH_setGENRequestNum(DMASCH,transfParams->genNum,1);
    		DMASCH_GENChannelEnable(DMASCH,transfParams->genNum);
    		DMASCH_selectDMASource(DMASCH,srcMuxNum,transfParams->genNum);
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,1);
    	}
    	else
    	{
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,0);

    		DMASCH_selectDMASource(DMASCH,srcMuxNum,transfParams->dmaSrcReqId);
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,1);
    	}

    }
    if (transfParams->ttfc == DMA_TT_FC_1_M2P_DMAC || transfParams->ttfc == DMA_TT_FC_3_P2P_DMAC ||
        transfParams->ttfc == DMA_TT_FC_5_P2P_SP || transfParams->ttfc == DMA_TT_FC_6_M2P_P || transfParams->ttfc == DMA_TT_FC_7_P2P_DP)
       
        // 
       // DMAMUX_configDmaMux(dmamuxBase, destHardInf, transfParams->dmaDstReqId);
       //
    {
    	if(transfParams->dmaDstReqId>=DMAMUX_ReqId_max)
    	{
    		DMASCH_GENChannelDisable(DMASCH,transfParams->genNum);
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,0);

    		DMASCH_selectTRGSource(DMASCH,transfParams->genNum,(transfParams->dmaDstReqId-DMAMUX_ReqId_max));
    		DMASCH_setTRGPolarity(DMASCH,transfParams->genNum,DMASCH_GCR_TPOL_RISE);
    		DMASCH_setGENRequestNum(DMASCH,transfParams->genNum,1);
    		DMASCH_GENChannelEnable(DMASCH,transfParams->genNum);
    		DMASCH_selectDMASource(DMASCH,destMuxNum,transfParams->genNum);
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,1);
    	}
    	else
    	{
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,0);

    		DMASCH_selectDMASource(DMASCH,destMuxNum,transfParams->dmaDstReqId);
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,1);
    	}
    }

}
#endif

#if DMAC_HW_VER == 0x00

//*****************************************************************************
//
// DMA_configChannel
//
//*****************************************************************************
void DMA_configChannel(uint32_t base, const DMA_ConfigParams *transfParams)
{
    uint32_t high = 0;
    uint32_t low = 0;

    //
    // uint32_t dmamuxBase = 0U;
    //
    uint32_t channel = 0U;
    uint32_t dma_num = 0U;
    DMA_HandshakingSelect srcHkSelect;
    DMA_HandshakingSelect destHkSelect;
    DMA_MasterInfSelect srcMISelect;
    DMA_MasterInfSelect destMISelect;
    DMA_HK_HARDWARE_INF   srcHardInf;
    DMA_HK_HARDWARE_INF   destHardInf;
    DMA_HK_HARDWARE_INF   srcMuxNum;
    DMA_HK_HARDWARE_INF   destMuxNum;
    DMAMUX_GEN_INF GenNum;

#if !(DMAMUX_RGCR_P2P_SUPPORT)
    //
    // Not support DMAMUX P2P trigger case,
    //
    ASSERT((transfParams->dmaSrcReqId < DMAMUX_ReqId_max) ||
            (transfParams->ttfc == DMA_TT_FC_2_P2M_DMAC) ||
            (transfParams->ttfc == DMA_TT_FC_4_P2M_P) ||
            (transfParams->ttfc == DMA_TT_FC_1_M2P_DMAC) ||
            (transfParams->ttfc == DMA_TT_FC_5_P2P_SP));
#endif

    //
    // Covert the channel base to the channel number and the dmamux base address..
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dma_num = DMA_convertChnBase2DmaNum(base);
    uint32_t status;
    status=*((volatile uint8_t *)(0x29001100))&(0x01);//TODO:

    //
    // Forced distribution of the handshake signals by channel.
    //
    switch (transfParams->ttfc)
    {
        case DMA_TT_FC_2_P2M_DMAC:
        case DMA_TT_FC_4_P2M_P:
            srcHkSelect  = DMA_HKS_HARDWARE;
            destHkSelect = DMA_HKS_SOFTWARE;
            srcMISelect=dmaMasterInterface[transfParams->dmaSrcReqId];
            destMISelect=DMA_AHB_MASTER_1;
            if((transfParams->dmaSrcReqId==DMAMUX_ReqId_dma_MSPI_TX)||(transfParams->dmaSrcReqId==DMAMUX_ReqId_dma_MSPI_RX))
            {
                if(status!=0){
                    srcMISelect = DMA_AHB_MASTER_1;
                }
                else{
                    srcMISelect = DMA_AHB_MASTER_2;
                }
            }
            break;

        case DMA_TT_FC_1_M2P_DMAC:
        case DMA_TT_FC_6_M2P_P:
            srcHkSelect  = DMA_HKS_SOFTWARE;
            destHkSelect = DMA_HKS_HARDWARE;
            srcMISelect=DMA_AHB_MASTER_1;
            destMISelect=dmaMasterInterface[transfParams->dmaDstReqId];
            if((transfParams->dmaDstReqId==DMAMUX_ReqId_dma_MSPI_TX)||(transfParams->dmaDstReqId==DMAMUX_ReqId_dma_MSPI_RX))
            {
                if(status!=0){
                    destMISelect = DMA_AHB_MASTER_1;
                }
                else{
                    destMISelect = DMA_AHB_MASTER_2;
                }
            }
            break;

        case DMA_TT_FC_3_P2P_DMAC:
        case DMA_TT_FC_5_P2P_SP:
        case DMA_TT_FC_7_P2P_DP:
            srcHkSelect  = DMA_HKS_HARDWARE;
            destHkSelect = DMA_HKS_HARDWARE;
            srcMISelect=dmaMasterInterface[transfParams->dmaSrcReqId];
            destMISelect=dmaMasterInterface[transfParams->dmaDstReqId];
            if((transfParams->dmaSrcReqId==DMAMUX_ReqId_dma_MSPI_TX)||(transfParams->dmaSrcReqId==DMAMUX_ReqId_dma_MSPI_RX))
            {
                if(status!=0){
                    srcMISelect = DMA_AHB_MASTER_1;
                }
                else{
                    srcMISelect = DMA_AHB_MASTER_2;
                }
            }
            if((transfParams->dmaDstReqId==DMAMUX_ReqId_dma_MSPI_TX)||(transfParams->dmaDstReqId==DMAMUX_ReqId_dma_MSPI_RX))
            {
                if(status!=0){
                    destMISelect = DMA_AHB_MASTER_1;
                }
                else{
                    destMISelect = DMA_AHB_MASTER_2;
                }
            }
            break;

        default:
            srcHkSelect  = DMA_HKS_SOFTWARE;
            destHkSelect = DMA_HKS_SOFTWARE;
            srcMISelect=DMA_AHB_MASTER_1;
            destMISelect=DMA_AHB_MASTER_1;
            break;
    }

    //
    // DMA_HKS_HARD_INF_0 used as source handshaking signal of channel0
    // DMA_HKS_HARD_INF_1 used as dest handshaking signal of channel0
    // DMA_HKS_HARD_INF_2 used as source handshaking signal of channel1
    // DMA_HKS_HARD_INF_3 used as dest handshaking signal of channel1
    // DMA_HKS_HARD_INF_14 used as source handshaking signal of channel7
    // DMA_HKS_HARD_INF_15 used as dest handshaking signal of channel7
    //
    srcHardInf   = 2* channel;
    destHardInf  = 2* channel + 1U;

    //
    // Configure DMA Channel
    //
    DMA_configAddresses(base, transfParams->destAddr, transfParams->srcAddr);

    //
    // Src Master //TODO
    //
    low += (srcMISelect<<25);

    //
    // Dest master //TODO
    //
    low += (destMISelect<<23);

    //
    // TransType 0=m2m, 1=m2p, 2=p2m, 3=p2p, 4=p2m_fc_p, 5=p2p_fc_sp, ......
    //
    low += (transfParams->ttfc<<20);

    //
    // Src Burst Size, 1/4/8/.../256cnt
    //
    low += (transfParams->srcBtl<<14);

    //
    // Dst Burst Size, 1/4/8/.../256cnt
    //
    low += (transfParams->destBtl<<11);

    //
    // SrcInc, 0=increment src addr
    //
    low += (transfParams->srcAddrDirect<<9);

    //
    // DstInc, 2=unchanged dst addr
    //
    low += (transfParams->destAddrDirect<<7);

    //
    // Src_Tr_Width, 8/16/32/.../256bit, 2=32bit
    //
    low += (transfParams->srcTrWidthBytes<<4);

    //
    // Dst_Tr_Width, 8/16/32/.../256bit, 2=32bit
    //
    low += (transfParams->destTrWidthBytes<<1);

    //
    // Interrupt enable, it's used to mask all interrupts related to this channel
    //
    low += (transfParams->enableInterrupt<<0);

    //
    // bit44, DONE
    //
    high = (1<<12);

    //
    // Bit32~x, Block_Ts max is 4095
    //
    high += (transfParams->blockTS & 0x00000fff);

    DMA_configChannelCTL(base, (uint64_t)high << 32 | low);

    low = (transfParams->chPriority<<5);

    //
    // Bit_11, HS_SEL_DST select handshaking source
    //
    low += (srcHkSelect<<11);

    //
    // Bit_10, HS_SEL_SRC select handshaking source
    //
    low += (destHkSelect<<10);

    //
    // Bit_39, SRC_PER select handshaking source //MUX channel number, source end
    //
    high = (srcHardInf<<7);

    //
    // Bit_43, DST_PER select handshaking source //MUX channel number, destination end
    //
    high += (destHardInf<<11);

    DMA_configChannelCFG(base, (uint64_t)high << 32 | low);

    if(dma_num==1)
    {
    	srcMuxNum=srcHardInf;
    	destMuxNum=destHardInf;
    	GenNum=channel;

    }else
    {
    	srcMuxNum=srcHardInf+16;
    	destMuxNum=destHardInf+16;
    	GenNum=channel+4;
    }


    if (transfParams->ttfc == DMA_TT_FC_2_P2M_DMAC || transfParams->ttfc == DMA_TT_FC_3_P2P_DMAC ||
        transfParams->ttfc == DMA_TT_FC_4_P2M_P || transfParams->ttfc == DMA_TT_FC_5_P2P_SP || transfParams->ttfc == DMA_TT_FC_7_P2P_DP)
    {
    	if(transfParams->dmaSrcReqId>=DMAMUX_ReqId_max)
    	{
    		DMASCH_GENChannelDisable(DMASCH,GenNum);
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,0);

    		DMASCH_selectTRGSource(DMASCH,GenNum,(transfParams->dmaSrcReqId-DMAMUX_ReqId_max));
    		DMASCH_setTRGPolarity(DMASCH,GenNum,DMASCH_GCR_TPOL_RISE);
    		DMASCH_setGENRequestNum(DMASCH,GenNum,1);
    		DMASCH_GENChannelEnable(DMASCH,GenNum);
    		DMASCH_selectDMASource(DMASCH,srcMuxNum,GenNum);
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,1);
    	}
    	else
    	{
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,0);

    		DMASCH_selectDMASource(DMASCH,srcMuxNum,transfParams->dmaSrcReqId);
    		DMASCH_setMUXRequestNum(DMASCH,srcMuxNum,1);
    	}

    }
    if (transfParams->ttfc == DMA_TT_FC_1_M2P_DMAC || transfParams->ttfc == DMA_TT_FC_3_P2P_DMAC ||
        transfParams->ttfc == DMA_TT_FC_5_P2P_SP || transfParams->ttfc == DMA_TT_FC_6_M2P_P || transfParams->ttfc == DMA_TT_FC_7_P2P_DP)
    {
    	if(transfParams->dmaDstReqId>=DMAMUX_ReqId_max)
    	{
    		DMASCH_GENChannelDisable(DMASCH,GenNum);
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,0);

    		DMASCH_selectTRGSource(DMASCH,GenNum,(transfParams->dmaDstReqId-DMAMUX_ReqId_max));
    		DMASCH_setTRGPolarity(DMASCH,GenNum,DMASCH_GCR_TPOL_RISE);
    		DMASCH_setGENRequestNum(DMASCH,GenNum,1);
    		DMASCH_GENChannelEnable(DMASCH,GenNum);
    		DMASCH_selectDMASource(DMASCH,destMuxNum,GenNum);
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,1);
    	}
    	else
    	{
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,0);

    		DMASCH_selectDMASource(DMASCH,destMuxNum,transfParams->dmaDstReqId);
    		DMASCH_setMUXRequestNum(DMASCH,destMuxNum,1);
    	}
    }

}

#endif


void DMA_DeConfChannel(uint32_t base)
{
    uint32_t high = 0;
    uint32_t low = 0;

    //
    // uint32_t dmamuxBase = 0U;
    //
    uint32_t channel = 0U;
    uint32_t dma_num = 0U;

    ASSERT(DMA_isBaseValid(base));

    //
    // Covert the channel base to the channel number and the dmamux base address..
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dma_num = DMA_convertChnBase2DmaNum(base);
    DMA_configAddresses(base, 0, 0);
    #if DMAC_HW_VER == 0x01
    DMA_configLLP(base,0 ,DMA_AHB_MASTER_1);//TODO:default to be master1
    #endif
    DMA_configChannelCTL(base, (uint64_t)0x00000002<< 32 | 0x00304801);
    DMA_configChannelCFG(base, (uint64_t)0x00000004<< 32|0x00000E00|(uint32_t)dma_num<<5);

}

#if DMAC_HW_VER == 0x00

///driver2****************************************************************


void DMAC_Set_INT(uint32_t base, int ch, uint32_t status)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLa;
    value &= ~(DMAC_CTRLA_INTEN_Msk);
    value |= status;
    instance->ChannelCfg[ch].CTRLa = value;
}

void DMAC_Set_DATAWIDTH(uint32_t base, int ch, uint32_t trWidth)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLa;
    value &= ~(DMAC_CTRLA_SRC_TR_WIDTH_Msk | DMAC_CTRLA_DST_TR_WIDTH_Msk);
    value |= (trWidth << DMAC_CTRLA_SRC_TR_WIDTH_Pos)
            | (trWidth << DMAC_CTRLA_DST_TR_WIDTH_Pos);
    instance->ChannelCfg[ch].CTRLa = value;
}

void DMAC_Set_ADDRINC(uint32_t base, int ch, uint32_t srcInc,
        uint32_t dstInc)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLa;
    value &= ~(DMAC_CTRLA_SRCADDR_OPR_Msk | DMAC_CTRLA_DSTADDR_OPR_Msk);
    value |= (srcInc << DMAC_CTRLA_SRCADDR_OPR_Pos)
            | (dstInc << DMAC_CTRLA_DSTADDR_OPR_Pos);
    instance->ChannelCfg[ch].CTRLa = value;
}

//*****************************************************************************
//
// DMAC_Set_BurstLength
//
//*****************************************************************************
void DMAC_Set_BurstLength(uint32_t base, int ch, uint32_t burstLength)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLa;
    value &= ~(DMAC_CTRLA_SRC_MSIZE_Msk | DMAC_CTRLA_DST_MSIZE_Msk);
    value |= (burstLength << DMAC_CTRLA_SRC_MSIZE_Pos)
            | (burstLength << DMAC_CTRLA_DST_MSIZE_Pos);
    instance->ChannelCfg[ch].CTRLa = value;
}

//*****************************************************************************
//
// DMAC_Set_TransType
//
//*****************************************************************************
void DMAC_Set_TransType(uint32_t base, int ch, uint32_t trType)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLa;
    value &= ~(DMAC_CTRLA_TRANSTYPE_Msk);
    value |= trType;
    instance->ChannelCfg[ch].CTRLa = value;
}

//*****************************************************************************
//
// DMAC_Set_Channelmaster
//
//*****************************************************************************
void DMAC_Set_Channelmaster(uint32_t base, int ch, uint32_t srcMaster,
        uint32_t dstMaster)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLa;
    value &= ~(DMAC_CTRLA_SMS_Msk | DMAC_CTRLA_DMS_Msk);
    value |= (srcMaster << DMAC_CTRLA_SMS_Pos)
            | (dstMaster << DMAC_CTRLA_DMS_Pos);
    instance->ChannelCfg[ch].CTRLa = value;
}

//*****************************************************************************
//
// DMAC_Set_BlockNum
//
//*****************************************************************************
void DMAC_Set_BlockNum(uint32_t base, int ch, uint32_t totalNum)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLb;
    value &= ~(DMAC_CTRLB_BLOCK_Msk); //mask code
    value |= totalNum;
    instance->ChannelCfg[ch].CTRLb = value;
}

//*****************************************************************************
//
// DMAC_Read_Block
//
//*****************************************************************************
int32_t DMAC_Read_Block(uint32_t base, int ch)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLb;
    return (value & DMAC_CTRLB_BLOCK_Msk);

}

//*****************************************************************************
//
// DMAC_Read_Done
//
//*****************************************************************************
Status DMAC_Read_Done(uint32_t base, int ch)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLb;
    return ((value & DMAC_CTRLB_DONE_Msk) != 0);
}

//*****************************************************************************
//
// DMAC_Reset_Done
//
//*****************************************************************************
void DMAC_Reset_Done(uint32_t base, int ch)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLb;
    value &= ~(DMAC_CTRLB_DONE_Msk);
    value |= HAL_DMAC_DONE_ReSet;
    instance->ChannelCfg[ch].CTRLb = value;
}

//*****************************************************************************
//
// DMAC_Set_Done
//
//*****************************************************************************
void DMAC_Set_Done(uint32_t base, int ch)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CTRLb;
    value &= ~(DMAC_CTRLB_DONE_Msk);
    value |= HAL_DMAC_DONE_Set;
    instance->ChannelCfg[ch].CTRLb = value;
}

//*****************************************************************************
//
// DMAC_Set_ADDR
//
//*****************************************************************************
void DMAC_Set_ADDR(uint32_t base, int ch, uint32_t srcAddr,
        uint32_t dstAddr)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->ChannelCfg[ch].SAR = srcAddr;
    instance->ChannelCfg[ch].DAR = dstAddr;
}

//*****************************************************************************
//
// DMAC_Set_Prior
//
//*****************************************************************************
void DMAC_Set_Prior(uint32_t base, int ch, uint32_t prior)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGa;
    value &= ~(DMAC_CFGA_PRIOR_Msk);
    value |= prior<<DMAC_CFGA_PRIOR_Pos;
    instance->ChannelCfg[ch].CFGa = value;
}

//*****************************************************************************
//
// DMAC_Stop_Channel
//
//*****************************************************************************
void DMAC_Stop_Channel(uint32_t base, int ch)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGa;
//    value &= ~(DMAC_CFGA_SUSP_Msk);
    value |= HAL_DMAC_SUSP_ENABLE;
    instance->ChannelCfg[ch].CFGa = value;
}

//*****************************************************************************
//
// DMAC_ReStart_Channel
//
//*****************************************************************************
void DMAC_ReStart_Channel(uint32_t base, int ch)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGa;
    value &= ~(DMAC_CFGA_SUSP_Msk);
    value |= HAL_DMAC_SUSP_DISABLE;
    instance->ChannelCfg[ch].CFGa = value;
}

//*****************************************************************************
//
// DMAC_Read_FIFOEMPTY
//
//*****************************************************************************
Status DMAC_Read_FIFOEMPTY(uint32_t base, int ch) //Set indicates the FIFO is empty; Reset indicates it is not empty.
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGa;
    return ((value & DMAC_CFGA_FIFO_EMPTY_Msk) != 0);

}

//*****************************************************************************
//
// DMAC_Set_Handshaking
//
//*****************************************************************************

//
// Set software and hardware handshaking, ignore for memory-to-memory (m-m) transfers
//
void DMAC_Set_Handshaking(uint32_t base, int ch,
        uint32_t srcHandShaking, uint32_t dstHandShaking)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGa;
    value &= ~(DMAC_CFGA_HSSEL_SRC_Msk | DMAC_CFGA_HSSEL_DST_Msk);
    value |= srcHandShaking << DMAC_CFGA_HSSEL_SRC_Pos
            | dstHandShaking << DMAC_CFGA_HSSEL_DST_Pos;
    instance->ChannelCfg[ch].CFGa = value;
}

//*****************************************************************************
//
// DMAC_Set_HS_POL
//
//*****************************************************************************
void DMAC_Set_HS_POL(uint32_t base, int ch, uint32_t srcPOL,
        uint32_t dstPOL)
{
    uint32_t value;
    uint32_t tmp;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGa;
    value &= ~(DMAC_CFGA_POL_DST_Msk | DMAC_CFGA_POL_SRC_Msk);
    value |= (srcPOL << DMAC_CFGA_POL_SRC_Pos
            | dstPOL << DMAC_CFGA_POL_DST_Pos);
    instance->ChannelCfg[ch].CFGa = value;

}
//*****************************************************************************
//
// DMAC_Set_FIFOMODE
//
//*****************************************************************************
void DMAC_Set_FIFOMODE(uint32_t base, int ch, uint32_t mode)
{
    //FIFO mode
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGb;
    value &= ~(DMAC_CFGB_FIFOMODE_Msk);
    value |= (mode);
    instance->ChannelCfg[ch].CFGb = value;
}

//*****************************************************************************
//
// DMAC_Assign_Hdhs_Interface
//
//*****************************************************************************

//
// Peripheral selection
//
void DMAC_Assign_Hdhs_Interface(uint32_t base, int ch,
        uint32_t srcDevice, uint32_t dstDevice)
{
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    value = instance->ChannelCfg[ch].CFGb;
    value &= ~(DMAC_CFGB_HS_SRCPERI_Msk | DMAC_CFGB_HS_DSTPERI_Msk);
    value |= (srcDevice << DMAC_CFGB_HS_SRCPERI_Pos)
            | (dstDevice << DMAC_CFGB_HS_DSTPERI_Pos);
    instance->ChannelCfg[ch].CFGb = value;
}

//*****************************************************************************
//
// DMAC_Set_SrcReq
//
//*****************************************************************************
void DMAC_Set_SrcReq(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->ReqSrc |= ((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_Set_DstReq
//
//*****************************************************************************
void DMAC_Set_DstReq(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->ReqDst |= ((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_Set_SglSrcReq
//
//*****************************************************************************
void DMAC_Set_SglSrcReq(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->SglReqSrc |= ((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_Set_SglDstReq
//
//*****************************************************************************
void DMAC_Set_SglDstReq(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->SglReqDst |= ((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_Set_LstSrcReq
//
//*****************************************************************************
void DMAC_Set_LstSrcReq(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->LstReqSrc |= ((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_Set_LstDstReq
//
//*****************************************************************************
void DMAC_Set_LstDstReq(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->LstReqDst |= ((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_ENABLE
//
//*****************************************************************************
void DMAC_ENABLE(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->DmaCfg = DMAC_CFG_ENABLE;
}

//*****************************************************************************
//
// DMAC_DISABLE
//
//*****************************************************************************
void DMAC_DISABLE(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->DmaCfg = DMAC_CFG_DISABLE;
}

//*****************************************************************************
//
// DMAC_CHANNEL_ENABLE
//
//*****************************************************************************
void DMAC_CHANNEL_ENABLE(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->DmaChEn |= ((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_CHANNEL_DISABLE
//
//*****************************************************************************
void DMAC_CHANNEL_DISABLE(uint32_t base, int ch)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->DmaChEn &= ~((1 << (8 + ch)) | (1 << ch));
}

//*****************************************************************************
//
// DMAC_READ_CHANNELEN
//
//*****************************************************************************
Status DMAC_READ_CHANNELEN(uint32_t base, int ch)
{
    uint32_t mask;
    uint32_t value;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    mask = ((1 << ch));
    value = instance->DmaChEn;
    return ((value & mask) != 0);
}

//*****************************************************************************
//
// DMAC_Set_TestMode
//
//*****************************************************************************
void DMAC_Set_TestMode(uint32_t base, uint32_t status)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->DmaTest = status;
}

//*****************************************************************************
//
// DMAC_ReadCH_RawTfr
//
//*****************************************************************************
Status DMAC_ReadCH_RawTfr(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;

    value = instance->RawTfr;
    return ((value & channel_msk) != 0);

}

//*****************************************************************************
//
// DMAC_ReadCH_RawBlock
//
//*****************************************************************************
Status DMAC_ReadCH_RawBlock(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->RawBlock;
    return ((value & channel_msk) != 0);

}

//*****************************************************************************
//
// DMAC_ReadCH_RawSrcTran
//
//*****************************************************************************
Status DMAC_ReadCH_RawSrcTran(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->RawSrcTran;
    return ((value & channel_msk) != 0);

}

//*****************************************************************************
//
// DMAC_ReadCH_RawDstTran
//
//*****************************************************************************
Status DMAC_ReadCH_RawDstTran(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->RawDstTran;
    return ((value & channel_msk) != 0);

}

//*****************************************************************************
//
// DMAC_ReadCH_RawErr
//
//*****************************************************************************
Status DMAC_ReadCH_RawErr(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->RawErr;
    return ((value & channel_msk) != 0);
}

//*****************************************************************************
//
// DMAC_Read_RawTfr
//
//*****************************************************************************
uint32_t DMAC_Read_RawTfr(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->RawTfr;
}

//*****************************************************************************
//
// DMAC_Read_RawBlock
//
//*****************************************************************************
uint32_t DMAC_Read_RawBlock(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->RawBlock;
}

//*****************************************************************************
//
// DMAC_Read_RawSrcTran
//
//*****************************************************************************
uint32_t DMAC_Read_RawSrcTran(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->RawSrcTran;
}

//*****************************************************************************
//
// DMAC_Read_RawDstTran
//
//*****************************************************************************
uint32_t DMAC_Read_RawDstTran(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->RawDstTran;
}

//*****************************************************************************
//
// DMAC_Read_RawErr
//
//*****************************************************************************
uint32_t DMAC_Read_RawErr(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->RawErr;
}

//*****************************************************************************
//
// DMAC_ReadCH_StatusTfr
//
//*****************************************************************************
Status DMAC_ReadCH_StatusTfr(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->StatusTfr;
    return ((value & channel_msk) != 0);
}
//*****************************************************************************
//
// DMAC_ReadCH_StatusBlock
//
//*****************************************************************************
Status DMAC_ReadCH_StatusBlock(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->StatusBlock;
    return ((value & channel_msk) != 0);
}
//*****************************************************************************
//
// DMAC_ReadCH_StatusSrcTran
//
//*****************************************************************************
Status DMAC_ReadCH_StatusSrcTran(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->StatusSrcTran;
    return ((value & channel_msk) != 0);
}
//*****************************************************************************
//
// DMAC_ReadCH_StatusDstTran
//
//*****************************************************************************
Status DMAC_ReadCH_StatusDstTran(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->StatusDstTran;
    return ((value & channel_msk) != 0);
}
//*****************************************************************************
//
// DMAC_ReadCH_StatusErr
//
//*****************************************************************************
Status DMAC_ReadCH_StatusErr(uint32_t base, int ch)
{
    uint32_t value;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    value = instance->StatusErr;
    return ((value & channel_msk) != 0);
}

//*****************************************************************************
//
// DMAC_Read_StatusTfr
//
//*****************************************************************************
uint32_t DMAC_Read_StatusTfr(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->StatusTfr;
}

//*****************************************************************************
//
// DMAC_Read_StatusBlock
//
//*****************************************************************************
uint32_t DMAC_Read_StatusBlock(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->StatusBlock;
}

//*****************************************************************************
//
// DMAC_Read_StatusSrcTran
//
//*****************************************************************************
uint32_t DMAC_Read_StatusSrcTran(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->StatusSrcTran;
}

//*****************************************************************************
//
// DMAC_Read_StatusDstTran
//
//*****************************************************************************
uint32_t DMAC_Read_StatusDstTran(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->StatusDstTran;
}

//*****************************************************************************
//
// DMAC_Read_StatusErr
//
//*****************************************************************************
uint32_t DMAC_Read_StatusErr(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->StatusErr;
}
//*****************************************************************************
//
// DMAC_Set_MaskTfr
//
//*****************************************************************************
void DMAC_Set_MaskTfr(uint32_t base, int ch, uint32_t status)
{
    uint32_t value;
    uint32_t channel_unmsk;
    uint32_t channel_msken;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_unmsk = ((1 << (8 + ch)) | (1 << ch));
    channel_msken = (1 << 8 + ch);
    channel_msk = (1 << ch);
    value = instance->MaskTfr;
    if (status == HAL_DMAC_INT_MASK)
    {
        value |= channel_msken;
        value &= ~channel_msk;
    }
    else if (status == HAL_DMAC_INT_UNMASK)
    {
        value |= channel_unmsk;
    }
    instance->MaskTfr = value;
}

//*****************************************************************************
//
// DMAC_Set_MaskBlock
//
//*****************************************************************************
void DMAC_Set_MaskBlock(uint32_t base, int ch, uint32_t status)
{
    uint32_t value;
    uint32_t channel_unmsk;
    uint32_t channel_msken;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_unmsk = ((1 << (8 + ch)) | (1 << ch));
    channel_msken = (1 << 8 + ch);
    channel_msk = (1 << ch);
    value = instance->MaskBlock;
    if (status == HAL_DMAC_INT_MASK)
    {
        value |= channel_msken;
        value &= ~channel_msk;
    }
    else if (status == HAL_DMAC_INT_UNMASK)
    {
        value |= channel_unmsk;
    }
    instance->MaskBlock = value;
}

//*****************************************************************************
//
// DMAC_Set_MaskSrcTran
//
//*****************************************************************************
void DMAC_Set_MaskSrcTran(uint32_t base, int ch, uint32_t status)
{
    uint32_t value;
    uint32_t channel_unmsk;
    uint32_t channel_msken;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_unmsk = ((1 << (8 + ch)) | (1 << ch));
    channel_msken = (1 << 8 + ch);
    channel_msk = (1 << ch);
    value = instance->MaskSrcTran;
    if (status == HAL_DMAC_INT_MASK)
    {
        value |= channel_msken;
        value &= ~channel_msk;
    }
    else if (status == HAL_DMAC_INT_UNMASK)
    {
        value |= channel_unmsk;
    }
    instance->MaskSrcTran = value;
}

//*****************************************************************************
//
// DMAC_Set_MaskDstTran
//
//*****************************************************************************
void DMAC_Set_MaskDstTran(uint32_t base, int ch, uint32_t status)
{
    uint32_t value;
    uint32_t channel_unmsk;
    uint32_t channel_msken;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_unmsk = ((1 << (8 + ch)) | (1 << ch));
    channel_msken = (1 << 8 + ch);
    channel_msk = (1 << ch);
    value = instance->MaskDstTran;
    if (status == HAL_DMAC_INT_MASK)
    {
        value |= channel_msken;
        value &= ~channel_msk;
    }
    else if (status == HAL_DMAC_INT_UNMASK)
    {
        value |= channel_unmsk;
    }
    instance->MaskDstTran = value;
}

//*****************************************************************************
//
// DMAC_Set_MaskErr
//
//*****************************************************************************
void DMAC_Set_MaskErr(uint32_t base, int ch, uint32_t status)
{
    uint32_t value;
    uint32_t channel_unmsk;
    uint32_t channel_msken;
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_unmsk = ((1 << (8 + ch)) | (1 << ch));
    channel_msken = (1 << 8 + ch);
    channel_msk = (1 << ch);
    value = instance->MaskErr;
    if (status == HAL_DMAC_INT_MASK)
    {
        value |= channel_msken;
        value &= ~channel_msk;
    }
    else if (status == HAL_DMAC_INT_UNMASK)
    {
        value |= channel_unmsk;
    }
    instance->MaskErr = value;
}

//*****************************************************************************
//
// DMAC_ClearCH_Tfr
//
//*****************************************************************************
void DMAC_ClearCH_Tfr(uint32_t base, int ch)
{
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    instance->ClearTfr = channel_msk;
}

//*****************************************************************************
//
// DMAC_ClearCH_Block
//
//*****************************************************************************
void DMAC_ClearCH_Block(uint32_t base, int ch)
{
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    instance->ClearBlock = channel_msk;
}

//*****************************************************************************
//
// DMAC_ClearCH_SrcTran
//
//*****************************************************************************
void DMAC_ClearCH_SrcTran(uint32_t base, int ch)
{
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    instance->ClearSrcTran = channel_msk;
}

//*****************************************************************************
//
// DMAC_ClearCH_DstTran
//
//*****************************************************************************
void DMAC_ClearCH_DstTran(uint32_t base, int ch)
{
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    instance->ClearDstTran = channel_msk;
}

//*****************************************************************************
//
// DMAC_ClearCH_Err
//
//*****************************************************************************
void DMAC_ClearCH_Err(uint32_t base, int ch)
{
    uint32_t channel_msk;
    DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    channel_msk = 1 << ch;
    instance->ClearErr = channel_msk;
}

//*****************************************************************************
//
// DMAC_Clear_Tfr
//
//*****************************************************************************
void DMAC_Clear_Tfr(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->ClearTfr = 0xff;
}

//*****************************************************************************
//
// DMAC_Clear_Block
//
//*****************************************************************************
void DMAC_Clear_Block(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
	instance->ClearBlock = 0xff;
}

//*****************************************************************************
//
// DMAC_Clear_SrcTran
//
//*****************************************************************************
void DMAC_Clear_SrcTran(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->ClearSrcTran = 0xff;
}

//*****************************************************************************
//
// DMAC_Clear_DstTran
//
//*****************************************************************************
void DMAC_Clear_DstTran(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->ClearDstTran = 0xff;
}

//*****************************************************************************
//
// DMAC_Clear_Err
//
//*****************************************************************************
void DMAC_Clear_Err(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    instance->ClearErr = 0xff;
}

//*****************************************************************************
//
// DMAC_Read_StausInt
//
//*****************************************************************************
uint32_t DMAC_Read_StausInt(uint32_t base)
{
	DMAC_TypeDef *instance = (DMAC_TypeDef *)base;
    return instance->StatusInt;
}
#endif
