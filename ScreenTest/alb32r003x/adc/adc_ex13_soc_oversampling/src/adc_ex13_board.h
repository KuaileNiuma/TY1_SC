/**
 *************************************************************************************
 * @file adc_ex13_board.h
 * @brief This file contains the definition of header file for example adc_ex13_board.
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

#ifndef ADC_EX13_BOARD_H_
#define ADC_EX13_BOARD_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
//
// ANALOG -> myANALOGPinMux0 Pinmux
//
//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************

#define RESULTS_BUFFER_SIZE 5             		//!< Results buffer size

#define myADC0_BASE 		ADCA_BASE				//!< ADC0 module base address
#define myADC0_CH			11

#if myADC0_BASE == ADCA_BASE
#define myADC0_CLK_EN       SYSCTL_PERIPH_CLK_ADC1	//!< Peripheral clock
#define myADC0_RESULT_BASE 	ADCARESULT_BASE 		//!< ADC0 result register base address
#define myADC0_DMAIRQn		DMAMUX_ReqId_dma_ADC1_INT1

#if (myADC0_CH == 0)
//A0
#define myANALOGPinMux0     231
#elif myADC0_CH == 1
//A1
#define myANALOGPinMux0     232
#elif myADC0_CH == 2
//A2
#define myANALOGPinMux0     224
#elif myADC0_CH == 3
//A3
#define myANALOGPinMux0     229
#elif myADC0_CH == 4
//A4
#define myANALOGPinMux0     225
#elif myADC0_CH == 5
//A5
#define myANALOGPinMux0     249
#elif myADC0_CH == 6
//A6
#define myANALOGPinMux0     228
#elif myADC0_CH == 7
//A7
#define myANALOGPinMux0     240
#elif myADC0_CH == 8
//A8
#define myANALOGPinMux0     241
#elif myADC0_CH == 9
//A9
#define myANALOGPinMux0     227
#elif myADC0_CH == 10
//A10
#define myANALOGPinMux0     230
#elif myADC0_CH == 11
//A11
#define myANALOGPinMux0     237
#elif myADC0_CH == 12
//A12
#define myANALOGPinMux0     238
#elif myADC0_CH == 13
#error "Not support A13"
#elif myADC0_CH == 14
//A14
#define myANALOGPinMux0     239
#elif myADC0_CH == 15
//A15
#define myANALOGPinMux0     233
#endif
#define myADC0_IRQn			ADCA1_IRQn				//!< ADC0 Irq num
#elif myADC0_BASE == ADCB_BASE
#define myADC0_CLK_EN       SYSCTL_PERIPH_CLK_ADC1	//!< Peripheral clock
#define myADC0_RESULT_BASE 	ADCBRESULT_BASE 		//!< ADC0 result register base address
#define myADC0_IRQn			ADCB1_IRQn				//!< ADC0 Irq num
#define myADC0_DMAIRQn		DMAMUX_ReqId_dma_ADC2_INT1

#if (myADC0_CH == 0)
//B0
#define myANALOGPinMux0     235
#elif myADC0_CH == 1
//A10
#define myANALOGPinMux0     230
#elif myADC0_CH == 2
//B2
#define myANALOGPinMux0     226
#elif myADC0_CH == 3
//B3
#define myANALOGPinMux0     229
#elif myADC0_CH == 4
//B4
#define myANALOGPinMux0     236
#elif myADC0_CH == 5
//B5
#define myANALOGPinMux0     252
#elif myADC0_CH == 6
//A2
#define myANALOGPinMux0     224
#elif myADC0_CH == 7
//A1
#define myANALOGPinMux0     232
#elif myADC0_CH == 8
//A4
#define myANALOGPinMux0     225
#elif myADC0_CH == 9
//A3
#define myANALOGPinMux0     229
#elif myADC0_CH == 10
//A11
#define myANALOGPinMux0     237
#elif myADC0_CH == 11
//B11
#define myANALOGPinMux0     251
#elif myADC0_CH == 12
//B12
#define myANALOGPinMux0     244
#elif myADC0_CH == 13
#error "Not support B13"
#elif myADC0_CH == 14
//A14
#define myANALOGPinMux0     239
#elif myADC0_CH == 15
//A0
#define myANALOGPinMux0     231
#endif
#elif myADC0_BASE == ADCC_BASE
#define myADC0_CLK_EN       SYSCTL_PERIPH_CLK_ADC1	//!< Peripheral clock
#define myADC0_RESULT_BASE 	ADCCRESULT_BASE 		//!< ADC0 result register base address
#define myADC0_IRQn			ADCC1_IRQn				//!< ADC0 Irq num
#define myADC0_DMAIRQn		DMAMUX_ReqId_dma_ADC3_INT1

#if (myADC0_CH == 0)
//A11
#define myANALOGPinMux0     237
#elif myADC0_CH == 1
//C1
#define myANALOGPinMux0     248
#elif myADC0_CH == 2
//B12
#define myANALOGPinMux0     244
#elif myADC0_CH == 3
//A7
#define myANALOGPinMux0     245
#elif myADC0_CH == 4
//A14
#define myANALOGPinMux0     239
#elif myADC0_CH == 5
//A12
#define myANALOGPinMux0     238
#elif myADC0_CH == 6
//B2
#define myANALOGPinMux0     226
#elif myADC0_CH == 7
//A3
#define myANALOGPinMux0     229
#elif myADC0_CH == 8
//B4
#define myANALOGPinMux0     236
#elif myADC0_CH == 9
//A2
#define myANALOGPinMux0     224
#elif myADC0_CH == 10
//A10
#define myANALOGPinMux0     230
#elif myADC0_CH == 11
//B0
#define myANALOGPinMux0     235
#elif myADC0_CH == 12
#error "Not support C12"
#elif myADC0_CH == 13
#error "Not support C13"
#elif myADC0_CH == 14
//C14
#define myANALOGPinMux0     247
#elif myADC0_CH == 15
//A0
#define myANALOGPinMux0     231
#endif
#endif

#define myEPWM_CLK			SystemClock_Get_AHB()
#define myEPWM_Freq			50000
#define myEPWM_Prd			myEPWM_CLK/myEPWM_Freq
#define myEPWM_Cmp			myEPWM_Prd/2

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
extern void adcA1ISR(void);

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void myADC0_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void Board_init();
void ANA_init();
void RCC_init();
void ADC_init();
void INTERRUPT_init();
void GPIO_init();

#ifdef __cplusplus
}
#endif

#endif
