/** 
  ************************************************************************************* 
  * @file dmasch.h 
  * @brief This file contains the definition of dmasch driver. 
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

#ifndef __DMACSH_H__
#define __DMACSH_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif


#include "hw_common.h"
#include "hw_dmasch.h"

typedef enum
{
	DMAMUX_GEN_0 = 0,
	DMAMUX_GEN_1,
	DMAMUX_GEN_2,
	DMAMUX_GEN_3,
	DMAMUX_GEN_4,
	DMAMUX_GEN_5,
	DMAMUX_GEN_6,
	DMAMUX_GEN_7,
} DMAMUX_GEN_INF;

#if DMAC_HW_VER == 0x01
typedef enum
{
    DMAMUX_ReqId_dma_GEN0 = 0,
	DMAMUX_ReqId_dma_GEN1 = 1,
    DMAMUX_ReqId_dma_GEN2 = 2,
	DMAMUX_ReqId_dma_GEN3 = 3,
    DMAMUX_ReqId_dma_GEN4 = 4,
	DMAMUX_ReqId_dma_GEN5 = 5,
    DMAMUX_ReqId_dma_GEN6 = 6,
	DMAMUX_ReqId_dma_GEN7 = 7,

	DMAMUX_ReqId_dma_ADC1_INT1 = 11,
	DMAMUX_ReqId_dma_ADC1_INT2 = 12,
	DMAMUX_ReqId_dma_ADC1_INT3 = 13,
	DMAMUX_ReqId_dma_ADC1_INT4 = 14,
	DMAMUX_ReqId_dma_ADC1_EVT  = 15,
	DMAMUX_ReqId_dma_ADC2_INT1 = 16,
	DMAMUX_ReqId_dma_ADC2_INT2 = 17,
	DMAMUX_ReqId_dma_ADC2_INT3 = 18,
	DMAMUX_ReqId_dma_ADC2_INT4 = 19,
	DMAMUX_ReqId_dma_ADC2_EVT  = 20,
	DMAMUX_ReqId_dma_ADC3_INT1 = 21,
	DMAMUX_ReqId_dma_ADC3_INT2 = 22,
	DMAMUX_ReqId_dma_ADC3_INT3 = 23,
	DMAMUX_ReqId_dma_ADC3_INT4 = 24,
	DMAMUX_ReqId_dma_ADC3_EVT  = 25,

	DMAMUX_ReqId_dma_XINT1     = 39,
	DMAMUX_ReqId_dma_XINT2     = 40,
	DMAMUX_ReqId_dma_XINT3     = 41,
	DMAMUX_ReqId_dma_XINT4     = 42,
	DMAMUX_ReqId_dma_XINT5     = 43,

	DMAMUX_ReqId_dma_FFT_W     = 93,
	DMAMUX_ReqId_dma_FFT_R     = 94,
	DMAMUX_ReqId_dma_W         = 95,  //?
	DMAMUX_ReqId_dma_R         = 96,  //?

	DMAMUX_ReqId_dma_LIN1_TX   = 109,
	DMAMUX_ReqId_dma_LIN1_RX   = 110,
	DMAMUX_ReqId_dma_LIN2_TX   = 111,
	DMAMUX_ReqId_dma_LIN2_RX   = 112,

	DMAMUX_ReqId_dma_SYNC_TRIG = 113,

	DMAMUX_ReqId_dma_BSPI1_TX   = 119,
	DMAMUX_ReqId_dma_BSPI1_RX   = 120,
	DMAMUX_ReqId_dma_BSPI2_TX   = 121,
	DMAMUX_ReqId_dma_BSPI2_RX   = 122,
	DMAMUX_ReqId_dma_BSPI3_TX   = 123,
	DMAMUX_ReqId_dma_BSPI3_RX   = 124,
	DMAMUX_ReqId_dma_BSPI4_TX   = 125,
	DMAMUX_ReqId_dma_BSPI4_RX   = 126,

	DMAMUX_ReqId_dma_USB_EPX_RX1= 141,
	DMAMUX_ReqId_dma_USB_EPX_TX1= 142,
	DMAMUX_ReqId_dma_USB_EPX_RX2= 143,
	DMAMUX_ReqId_dma_USB_EPX_TX2= 144,
	DMAMUX_ReqId_dma_USB_EPX_RX3= 145,
	DMAMUX_ReqId_dma_USB_EPX_TX3= 146,

	DMAMUX_ReqId_dma_UART3_TX   = 168,
	DMAMUX_ReqId_dma_UART3_RX   = 169,
	DMAMUX_ReqId_dma_UART4_TX   = 170,
	DMAMUX_ReqId_dma_UART4_RX   = 171,

	DMAMUX_ReqId_dma_SCA_IN     = 190,
	DMAMUX_ReqId_dma_SCA_OUT    = 191,

	DMAMUX_ReqId_dma_EPG1_INT   = 194,

	DMAMUX_ReqId_dma_IIC1_TX    = 216,
	DMAMUX_ReqId_dma_IIC1_RX    = 217,
	DMAMUX_ReqId_dma_IIC2_TX    = 218,
	DMAMUX_ReqId_dma_IIC2_RX    = 219,
	DMAMUX_ReqId_dma_UART1_TX   = 220,
	DMAMUX_ReqId_dma_UART1_RX   = 221,
	DMAMUX_ReqId_dma_UART2_TX   = 222,
	DMAMUX_ReqId_dma_UART2_RX   = 223,
	DMAMUX_ReqId_dma_UART5_TX   = 224,
	DMAMUX_ReqId_dma_UART5_RX   = 225,
	DMAMUX_ReqId_dma_UART6_TX   = 226,
	DMAMUX_ReqId_dma_UART6_RX   = 227,
	DMAMUX_ReqId_dma_UART7_TX   = 228,
	DMAMUX_ReqId_dma_UART7_RX   = 229,
	DMAMUX_ReqId_dma_UART8_TX   = 230,
	DMAMUX_ReqId_dma_UART8_RX   = 231,
	DMAMUX_ReqId_dma_PMBUS_TX   = 232,
	DMAMUX_ReqId_dma_PMBUS_RX   = 233,

	DMAMUX_ReqId_max = 256,

	DMAMUX_ReqId_dma_EPWM1_SOCA = 46+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM1_SOCB = 47+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM2_SOCA = 48+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM2_SOCB = 49+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM3_SOCA = 50+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM3_SOCB = 51+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM4_SOCA = 52+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM4_SOCB = 53+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM5_SOCA = 54+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM5_SOCB = 55+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM6_SOCA = 56+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM6_SOCB = 57+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM7_SOCA = 58+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM7_SOCB = 59+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM8_SOCA = 60+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM8_SOCB = 61+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM9_SOCA = 62+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM9_SOCB = 63+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM10_SOCA= 64+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM10_SOCB= 65+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM11_SOCA= 66+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM11_SOCB= 67+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM12_SOCA= 68+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM12_SOCB= 69+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM13_SOCA= 70+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM13_SOCB= 71+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM14_SOCA= 72+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM14_SOCB= 73+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM15_SOCA= 74+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM15_SOCB= 75+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM16_SOCA= 76+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM16_SOCB= 77+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_CPU1_TINT0 = 78+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_CPU1_TINT1 = 79+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_CPU1_TINT2 = 80+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM17_SOCA= 81+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM17_SOCB= 82+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM18_SOCA= 83+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_EPWM18_SOCB= 84+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_ECAP1_DMA  = 85+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_ECAP2_DMA  = 86+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_ECAP3_DMA  = 87+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_ECAP4_DMA  = 88+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_ECAP5_DMA  = 89+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_ECAP6_DMA  = 80+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_ECAP7_DMA  = 91+DMAMUX_ReqId_max,

	DMAMUX_ReqId_dma_CLB5_INT   = 127+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_CLB6_INT   = 128+DMAMUX_ReqId_max,

	DMAMUX_ReqId_dma_CLB1_INT   = 137+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_CLB2_INT   = 138+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_CLB3_INT   = 139+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_CLB4_INT   = 140+DMAMUX_ReqId_max,

	DMAMUX_ReqId_dma_SDFM1_FLT1_DRINT   = 200+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM1_FLT2_DRINT   = 201+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM1_FLT3_DRINT   = 202+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM1_FLT4_DRINT   = 203+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM2_FLT1_DRINT   = 204+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM2_FLT2_DRINT   = 205+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM2_FLT3_DRINT   = 206+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM2_FLT4_DRINT   = 207+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM3_FLT1_DRINT   = 208+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM3_FLT2_DRINT   = 209+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM3_FLT3_DRINT   = 210+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM3_FLT4_DRINT   = 211+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM4_FLT1_DRINT   = 212+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM4_FLT2_DRINT   = 213+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM4_FLT3_DRINT   = 214+DMAMUX_ReqId_max,
	DMAMUX_ReqId_dma_SDFM4_FLT4_DRINT   = 215+DMAMUX_ReqId_max,

} DMAMUX_ReqId_Type;
#endif
#if DMAC_HW_VER == 0x00
typedef enum
{
    DMAMUX_ReqId_dma_GEN0 = 0,
	DMAMUX_ReqId_dma_GEN1 = 1,
    DMAMUX_ReqId_dma_GEN2 = 2,
	DMAMUX_ReqId_dma_GEN3 = 3,
    DMAMUX_ReqId_dma_GEN4 = 4,
	DMAMUX_ReqId_dma_GEN5 = 5,
    DMAMUX_ReqId_dma_GEN6 = 6,
	DMAMUX_ReqId_dma_GEN7 = 7,

	DMAMUX_ReqId_dma_MSPI_TX = 107,
	DMAMUX_ReqId_dma_MSPI_RX = 108,

	DMAMUX_ReqId_dma_SPI1_TX = 109,
	DMAMUX_ReqId_dma_SPI1_RX = 110,
	DMAMUX_ReqId_dma_SPI2_TX = 111,
	DMAMUX_ReqId_dma_SPI2_RX = 112,
	DMAMUX_ReqId_dma_SPI3_TX = 113,
	DMAMUX_ReqId_dma_SPI3_RX = 114,

	DMAMUX_ReqId_dma_USART1_TX = 117,
	DMAMUX_ReqId_dma_USART1_RX = 118,
	DMAMUX_ReqId_dma_USART2_TX = 119,
	DMAMUX_ReqId_dma_USART2_RX = 120,

	DMAMUX_ReqId_dma_SMBUS_TX = 192,
	DMAMUX_ReqId_dma_SMBUS_RX = 193,

	DMAMUX_ReqId_dma_I2C1_TX = 194,
	DMAMUX_ReqId_dma_I2C1_RX = 195,
	DMAMUX_ReqId_dma_I2C2_TX = 196,
	DMAMUX_ReqId_dma_I2C2_RX = 197,

	DMAMUX_ReqId_dma_UART1_TX = 200,
	DMAMUX_ReqId_dma_UART1_RX = 201,
	DMAMUX_ReqId_dma_UART2_TX = 202,
	DMAMUX_ReqId_dma_UART2_RX = 203,

	DMAMUX_ReqId_max = 256,

	DMAMUX_ReqId_dma_ADC1_INT1 = DMAMUX_ReqId_max+1,
	DMAMUX_ReqId_dma_ADC1_INT2 = DMAMUX_ReqId_max+2,
	DMAMUX_ReqId_dma_ADC1_INT3 = DMAMUX_ReqId_max+3,
	DMAMUX_ReqId_dma_ADC1_INT4 = DMAMUX_ReqId_max+4,
	DMAMUX_ReqId_dma_ADC1_EVT  = DMAMUX_ReqId_max+5,
	DMAMUX_ReqId_dma_ADC2_INT1 = DMAMUX_ReqId_max+6,
	DMAMUX_ReqId_dma_ADC2_INT2 = DMAMUX_ReqId_max+7,
	DMAMUX_ReqId_dma_ADC2_INT3 = DMAMUX_ReqId_max+8,
	DMAMUX_ReqId_dma_ADC2_INT4 = DMAMUX_ReqId_max+9,
	DMAMUX_ReqId_dma_ADC2_EVT  = DMAMUX_ReqId_max+10,
	DMAMUX_ReqId_dma_ADC3_INT1 = DMAMUX_ReqId_max+11,
	DMAMUX_ReqId_dma_ADC3_INT2 = DMAMUX_ReqId_max+12,
	DMAMUX_ReqId_dma_ADC3_INT3 = DMAMUX_ReqId_max+13,
	DMAMUX_ReqId_dma_ADC3_INT4 = DMAMUX_ReqId_max+14,
	DMAMUX_ReqId_dma_ADC3_EVT  = DMAMUX_ReqId_max+15,

	DMAMUX_ReqId_dma_XINT1     = DMAMUX_ReqId_max+29,
	DMAMUX_ReqId_dma_XINT2     = DMAMUX_ReqId_max+30,
	DMAMUX_ReqId_dma_XINT3     = DMAMUX_ReqId_max+31,
	DMAMUX_ReqId_dma_XINT4     = DMAMUX_ReqId_max+32,
	DMAMUX_ReqId_dma_XINT5     = DMAMUX_ReqId_max+33,

	DMAMUX_ReqId_dma_EPWM1_SOCA = DMAMUX_ReqId_max+36,
	DMAMUX_ReqId_dma_EPWM1_SOCB = DMAMUX_ReqId_max+37,
	DMAMUX_ReqId_dma_EPWM2_SOCA = DMAMUX_ReqId_max+38,
	DMAMUX_ReqId_dma_EPWM2_SOCB = DMAMUX_ReqId_max+39,
	DMAMUX_ReqId_dma_EPWM3_SOCA = DMAMUX_ReqId_max+40,
	DMAMUX_ReqId_dma_EPWM3_SOCB = DMAMUX_ReqId_max+41,
	DMAMUX_ReqId_dma_EPWM4_SOCA = DMAMUX_ReqId_max+42,
	DMAMUX_ReqId_dma_EPWM4_SOCB = DMAMUX_ReqId_max+43,
	DMAMUX_ReqId_dma_EPWM5_SOCA = DMAMUX_ReqId_max+44,
	DMAMUX_ReqId_dma_EPWM5_SOCB = DMAMUX_ReqId_max+45,
	DMAMUX_ReqId_dma_EPWM6_SOCA = DMAMUX_ReqId_max+46,
	DMAMUX_ReqId_dma_EPWM6_SOCB = DMAMUX_ReqId_max+47,
	DMAMUX_ReqId_dma_EPWM7_SOCA = DMAMUX_ReqId_max+48,
	DMAMUX_ReqId_dma_EPWM7_SOCB = DMAMUX_ReqId_max+49,
	DMAMUX_ReqId_dma_EPWM8_SOCA = DMAMUX_ReqId_max+50,
	DMAMUX_ReqId_dma_EPWM8_SOCB = DMAMUX_ReqId_max+51,

	DMAMUX_ReqId_dma_ECAP1       = DMAMUX_ReqId_max+75,
	DMAMUX_ReqId_dma_ECAP2       = DMAMUX_ReqId_max+76,
	DMAMUX_ReqId_dma_ECAP3       = DMAMUX_ReqId_max+77,

	DMAMUX_ReqId_dma_SDFM1_FLT1_DPINT = DMAMUX_ReqId_max+96,
	DMAMUX_ReqId_dma_SDFM1_FLT2_DPINT = DMAMUX_ReqId_max+97,
	DMAMUX_ReqId_dma_SDFM1_FLT3_DPINT = DMAMUX_ReqId_max+98,
	DMAMUX_ReqId_dma_SDFM1_FLT4_DPINT = DMAMUX_ReqId_max+99,

	DMAMUX_ReqId_dma_SDFM2_FLT1_DPINT = DMAMUX_ReqId_max+101,
	DMAMUX_ReqId_dma_SDFM2_FLT2_DPINT = DMAMUX_ReqId_max+102,
	DMAMUX_ReqId_dma_SDFM2_FLT3_DPINT = DMAMUX_ReqId_max+103,
	DMAMUX_ReqId_dma_SDFM2_FLT4_DPINT = DMAMUX_ReqId_max+104,

	DMAMUX_ReqId_dma_CLB1_INT      = DMAMUX_ReqId_max+127,
	DMAMUX_ReqId_dma_CLB2_INT      = DMAMUX_ReqId_max+128,
	DMAMUX_ReqId_dma_CLB3_INT      = DMAMUX_ReqId_max+129,
	DMAMUX_ReqId_dma_CLB4_INT      = DMAMUX_ReqId_max+130,

} DMAMUX_ReqId_Type;

#endif

static inline void DMASCH_selectTRGSource(DMASCH_TypeDef *instance, int ch,
        uint32_t source)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_TRG_M);
    value |= source;
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_TRGOverFlowIntEnable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_TOIE_M);
    value |= DMASCH_GCR_TOIE_ENABLE;
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_TRGOverFlowIntDisable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_TOIE_M);
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_singleEnable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_SINGLEE_M);
    value |= DMASCH_GCR_SINGLEE_ENABLE;
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_singleDisable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_SINGLEE_M);
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_setTRGPolarity(DMASCH_TypeDef *instance, int ch,
        uint32_t polarity)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_TPOL_M);
    value |= polarity;
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_setTRGMode(DMASCH_TypeDef *instance, int ch, uint32_t mode)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_TMOD_M);
    value |= mode;
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_GENChannelEnable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_GENE_M);
    value |= DMASCH_GCR_GENE_ENABLE;
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_GENChannelDisable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_GENE_M);
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_setGENRequestNum(DMASCH_TypeDef *instance, int ch,
        uint32_t num)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_GREQLOW_M);
    value |= (num << DMASCH_GCR_GREQLOW_S);
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_setGENSingleNum(DMASCH_TypeDef *instance, int ch,
        uint32_t num)
{
    uint32_t value;
    value = instance->GenCfg[ch].GCR;
    value &= ~(DMASCH_GCR_GREQHIGH_M);
    value |= (num << DMASCH_GCR_GREQHIGH_S);
    instance->GenCfg[ch].GCR = value;
}

static inline Status DMASCH_readGENChannelOverFlowInt(DMASCH_TypeDef *instance, int ch)
{
    return (((instance->GISR) && (1 << ch)) != 0);
}

static inline Status DMASCH_readGENOverFlowInt(DMASCH_TypeDef *instance)
{
    return ((instance->GISR) != 0);
}

static inline void DMASCH_clearGENChannelOverFlowInt(DMASCH_TypeDef *instance, int ch)
{
    instance->GICR = (1 << ch);
}

static inline void DMASCH_clearGENOverFlowInt(DMASCH_TypeDef *instance)
{
    instance->GICR = 0xFFFFFFFF;
}

static inline void DMASCH_GENChannelSoftwareTrigger(DMASCH_TypeDef *instance, int ch)
{
    instance->GSTR = (1 << ch);
}

static inline void DMASCH_selectDMASource(DMASCH_TypeDef *instance, int ch,
        uint32_t source)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_REQ_M);
    value |= source;
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_SYNCOverFlowIntEnable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_SOIE_M);
    value |= DMASCH_MCR_SOIE_ENABLE;
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_SYNCOverFlowIntDisable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_SOIE_M);
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_eventEnable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_EVTE_M);
    value |= DMASCH_MCR_EVTE_ENABLE;
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_eventDisable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_EVTE_M);
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_setSYNCPolarity(DMASCH_TypeDef *instance, int ch,
        uint32_t polarity)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_SPOL_M);
    value |= polarity;
    instance->GenCfg[ch].GCR = value;
}

static inline void DMASCH_SYNCEnable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_SE_M);
    value |= DMASCH_MCR_SE_ENABLE;
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_SYNCDisable(DMASCH_TypeDef *instance, int ch)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_SE_M);
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_setRequestOutMode(DMASCH_TypeDef *instance, int ch,
        uint32_t mode)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_O_MODE_M);
    value |= mode;
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_setRequestOutPolarity(DMASCH_TypeDef *instance, int ch,
        uint32_t polarity)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_O_POL_M);
    value |= polarity;
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_setMUXRequestNum(DMASCH_TypeDef *instance, int ch,
        uint32_t num)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_MREQ_M);
    value |= (num << DMASCH_MCR_MREQ_S);
    instance->MuxCfg[ch].MCR = value;
}

static inline void DMASCH_slectSYNCSource(DMASCH_TypeDef *instance, int ch,
        uint32_t num)
{
    uint32_t value;
    value = instance->MuxCfg[ch].MCR;
    value &= ~(DMASCH_MCR_SYNC_M);
    value |= (num << DMASCH_MCR_SYNC_S);
    instance->MuxCfg[ch].MCR = value;
}

static inline Status DMASCH_readMUXChannelOverFlowInt(DMASCH_TypeDef *instance, int ch)
{
    return (((instance->MISR) && (1 << ch)) != 0);
}

static inline Status DMASCH_readMUXOverFlowInt(DMASCH_TypeDef *instance)
{
    return ((instance->MISR) != 0);
}

static inline void DMASCH_clearMUXChannelOverFlowInt(DMASCH_TypeDef *instance, int ch)
{
    instance->MICR = (1 << ch);
}

static inline void DMASCH_clearMUXOverFlowInt(DMASCH_TypeDef *instance)
{
    instance->MICR = 0xFFFFFFFF;
}

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __DMACSH_H__ */
