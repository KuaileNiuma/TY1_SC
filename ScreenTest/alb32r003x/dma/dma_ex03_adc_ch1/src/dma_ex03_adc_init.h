/**
 *************************************************************************************
 * @file dma_ex03_adc_init.h
 * @brief This file contains the source file for example dma_ex03_adc_init.
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

#ifndef __DMA_EX03_ADC_CH1_H
#define __DMA_EX03_ADC_CH1_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Include Files
//
//*****************************************************************************
#include <stdio.h>
#include "device.h"


//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myANALOGPinMux0     237                     //!< Analog PAD

#define myADC0_CLK_EN       SYSCTL_PERIPH_CLK_ADC1  //!< Peripheral clock
#define RESULTS_BUFFER_SIZE 256                     //!< Results buffer size
#define myADC0_BASE         ADCA_BASE               //!< ADC0 module base address
#define myADC0_RESULT_BASE  ADCARESULT_BASE         //!< ADC0 result register base address
#define myADC0_IRQn         ADCA1_IRQn              //!< ADC0 Irq num

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
extern void adcA1ISR(void);


//*****************************************************************************
//
// Global Functions Declarations
//
//*****************************************************************************
void myADC0_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void Board_init();
void ADC_init();
void INTERRUPT_init();
void GPIO_init();

#ifdef __cplusplus
}
#endif

#endif
