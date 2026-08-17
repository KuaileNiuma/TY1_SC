/**
 *************************************************************************************
 * @file interrupt.c
 * @brief This file implements the function of interrupt driver.
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
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_common.h"
#include "interrupt.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
typedef struct __DSP_IRQ_ATTR
{
    uint8_t shv;
    ECLIC_TRIGGER_Type trig_mode;
    uint8_t lvl;
    uint8_t priority;
} DSP_IRQ_ATTR;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Local Constants                                 */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Local Variables                                 */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Constants                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Local Function Prototypes                         */
/* ========================================================================== */
#if defined IS_ALB32R003X
const ECLIC_TRIGGER_Type dspIRQTriggleType[] = {
    [Reserved0_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved1_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved2_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [SysTimerSW_IRQn] = ECLIC_LEVEL_TRIGGER, /* System Timer SW interrupt */
    [Reserved3_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved4_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved5_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [SysTimer_IRQn]   = ECLIC_LEVEL_TRIGGER, /* System Timer Interrupt    */
    [Reserved6_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved7_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved8_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved9_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved10_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved11_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved12_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved13_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [InterCore_IRQn]  = ECLIC_LEVEL_TRIGGER, /* CIDU Inter Core Interrupt */
    [Reserved15_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved16_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */

    [TIMER4_C2_IRQn]    = ECLIC_LEVEL_TRIGGER,
    [TIMER3_C2_IRQn]    = ECLIC_LEVEL_TRIGGER,
    [TIMER2_C2_IRQn]    = ECLIC_LEVEL_TRIGGER,
    [TIMER1_C2_IRQn]    = ECLIC_LEVEL_TRIGGER,
    [XINT5_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT4_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT3_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER4_C1_IRQn]    = ECLIC_LEVEL_TRIGGER,
    [TIMER3_C1_IRQn]    = ECLIC_LEVEL_TRIGGER,
    [TIMER2_C1_IRQn]    = ECLIC_LEVEL_TRIGGER,
    [EFLASH_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [XFLASHC_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [QSPI_OR_MSPI_IRQn] = ECLIC_LEVEL_TRIGGER,
    [CSPI_IRQn]         = ECLIC_LEVEL_TRIGGER,
    [EPG_IRQn]          = ECLIC_LEVEL_TRIGGER,
    [SMC_IRQn]          = ECLIC_LEVEL_TRIGGER,
    [NPU_IRQn]          = ECLIC_LEVEL_TRIGGER,
    [GPIO5_IRQn]        = ECLIC_LEVEL_TRIGGER,
    [GPIO4_IRQn]        = ECLIC_LEVEL_TRIGGER,
    [GPIO3_IRQn]        = ECLIC_LEVEL_TRIGGER,
    [GPIO2_IRQn]        = ECLIC_LEVEL_TRIGGER,
    [GPIO1_IRQn]        = ECLIC_LEVEL_TRIGGER,
    [AES_IRQn]          = ECLIC_LEVEL_TRIGGER,
    [ECC_WARN_IRQn]     = ECLIC_LEVEL_TRIGGER,
    [ADCC4_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC3_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC2_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC_EVT_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB4_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB3_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB2_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB_EVT_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA4_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA3_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA2_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA_EVT_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DCC_IT_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [CANFD2_IRQn]       = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CANFD1_IRQn]       = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCI2_IRQn]         = ECLIC_LEVEL_TRIGGER,
    [SCI1_IRQn]         = ECLIC_LEVEL_TRIGGER,
    [RCC_IRQn]          = ECLIC_LEVEL_TRIGGER,
    [USART2_IRQn]       = ECLIC_LEVEL_TRIGGER,    //!< LIN2 Interrupt
    [USART1_IRQn]       = ECLIC_LEVEL_TRIGGER,    //!< LIN1 Interrupt
    [I2C3_IRQn]         = ECLIC_LEVEL_TRIGGER,
    [I2C1_IRQn]         = ECLIC_LEVEL_TRIGGER,
    [I2C2_IRQn]         = ECLIC_LEVEL_TRIGGER,
    [DMAC2_C4_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMAC1_C4_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMAC2_C3_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMAC1_C3_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMAC2_C2_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMAC1_C2_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMAC2_C1_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMAC1_C1_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMASCH_IRQn]       = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR4_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR3_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR2_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR1_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SPI4TX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SPI4RX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SPI3TX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SPI3RX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SPI2TX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SPI2RX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SPI1TX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SPI1RX_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [SDFM1DR4_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR3_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR2_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR1_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB4_IRQn]         = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB3_IRQn]         = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB2_IRQn]         = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB1_IRQn]         = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP2_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP1_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [HRCAP3_IRQn]       = ECLIC_POSTIVE_EDGE_TRIGGER,
    [HRCAP2_IRQn]       = ECLIC_POSTIVE_EDGE_TRIGGER,
    [HRCAP1_IRQn]       = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP3_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP2_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP1_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM8_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM7_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM6_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM5_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM4_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM3_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM2_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM1_IRQn]        = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM8TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM7TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM6TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM5TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM4TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM3TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM2TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM1TZ_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
	[PVDLP_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [WDT_IRQn]       = ECLIC_LEVEL_TRIGGER,
    [TIMER1_C1_IRQn] = ECLIC_LEVEL_TRIGGER,
    [XINT2_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT1_IRQn]     = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA_IRQn]      = ECLIC_POSTIVE_EDGE_TRIGGER,

};
#elif defined (IS_ALB32RP55)
const ECLIC_TRIGGER_Type dspIRQTriggleType[] = {
    [Reserved0_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved1_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved2_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [SysTimerSW_IRQn        ] =  ECLIC_LEVEL_TRIGGER, /* System Timer SW interrupt */
    [Reserved3_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved4_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved5_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [SysTimer_IRQn          ] =  ECLIC_LEVEL_TRIGGER, /* System Timer Interrupt    */
    [Reserved6_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved7_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved8_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved9_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved10_IRQn        ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved11_IRQn        ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved12_IRQn        ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved13_IRQn        ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [InterCore_IRQn         ] =  ECLIC_LEVEL_TRIGGER, /* CIDU Inter Core Interrupt */
    [Reserved15_IRQn        ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved16_IRQn        ] =  ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [EFUSE_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [NNIWWDT2_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [WWDT2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [xiaolian_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [RCC_IRQn               ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPG_IRQn               ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [FFT_IRQn               ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMASCH_IRQn            ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER6_C2_IRQn         ] =  ECLIC_LEVEL_TRIGGER,
    [TIMER5_C2_IRQn         ] =  ECLIC_LEVEL_TRIGGER,
    [TIMER4_C2_IRQn         ] =  ECLIC_LEVEL_TRIGGER,
    [TIMER3_C2_IRQn         ] =  ECLIC_LEVEL_TRIGGER,
    [TIMER2_C2_IRQn         ] =  ECLIC_LEVEL_TRIGGER,
    [TIMER1_C2_IRQn         ] =  ECLIC_LEVEL_TRIGGER,
    [SMCA_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [OTFSCA_IRQn            ] =  ECLIC_LEVEL_TRIGGER,
    [XFLASH1_IRQn           ] =  ECLIC_LEVEL_TRIGGER,
    [ZW_SMCA_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SMCM_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [NNIWWDT1_IRQn          ] =  ECLIC_LEVEL_TRIGGER,
    [WWDT1_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [XFLASH_OTFSCA0_IRQn    ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [XFLASH_OTFSCA1_IRQn    ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCA_IRQn               ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CRC2_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CRC1_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT5_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT4_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT3_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCE4_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCE3_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCE2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCE_EVT_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC4_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC3_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC_EVT_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB4_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB3_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB_EVT_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA4_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA3_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA_EVT_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [NPU_IRQn               ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [USB_IRQn               ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CANFD2_IRQn            ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CANFD1_IRQn            ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCI2_IRQn              ] =  ECLIC_LEVEL_TRIGGER,
    [SCI1_IRQn              ] =  ECLIC_LEVEL_TRIGGER,
    [SCI4_IRQn              ] =  ECLIC_LEVEL_TRIGGER,
    [LIN_IRQn               ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCI3_IRQn              ] =  ECLIC_LEVEL_TRIGGER,
    [I2C2_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [I2C1_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C8_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C7_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [PMBUS_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C6_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C5_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C4_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C3_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C2_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C1_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR4_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR3_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR2_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR1_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [BSPI3_TX_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [BSPI3_RX_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [DCC2_IRQn              ] =  ECLIC_LEVEL_TRIGGER,
    [DCC1_IRQn              ] =  ECLIC_LEVEL_TRIGGER,
    [BSPI2_TX_IRQn          ] =  ECLIC_LEVEL_TRIGGER,
    [BSPI2_RX_IRQn          ] =  ECLIC_LEVEL_TRIGGER,
    [BSPI1_TX_IRQn          ] =  ECLIC_LEVEL_TRIGGER,
    [BSPI1_RX_IRQn          ] =  ECLIC_LEVEL_TRIGGER,
    [SDFM1DR4_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR3_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR2_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR1_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2_ERR_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1_ERR_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB4_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB3_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB2_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB1_IRQn              ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP3_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER6_C1_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER5_C1_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER4_C1_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER3_C1_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER2_C1_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP3_HR_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP3_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM12_IRQn            ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM11_IRQn            ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM10_IRQn            ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM9_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM8_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM7_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM6_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM5_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM4_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM3_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM2_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM1_IRQn             ] =  ECLIC_LEVEL_TRIGGER,
    [EPWM12_TZ_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM11_TZ_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM10_TZ_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM9_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM8_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM7_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM6_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM5_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM4_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM3_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM2_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM1_TZ_IRQn          ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCE1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCD1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [CPU1_WAKE_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER1_C1_IRQn         ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [SYS_ERR_IRQn           ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT2_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA1_IRQn             ] =  ECLIC_POSTIVE_EDGE_TRIGGER,

};
#else

const ECLIC_TRIGGER_Type dspIRQTriggleType[] = {
    [Reserved0_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved1_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved2_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [SysTimerSW_IRQn] = ECLIC_LEVEL_TRIGGER, /* System Timer SW interrupt */
    [Reserved3_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved4_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved5_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [SysTimer_IRQn]   = ECLIC_LEVEL_TRIGGER, /* System Timer Interrupt    */
    [Reserved6_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved7_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved8_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved9_IRQn]  = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved10_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved11_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved12_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved13_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [InterCore_IRQn]  = ECLIC_LEVEL_TRIGGER, /* CIDU Inter Core Interrupt */
    [Reserved15_IRQn] = ECLIC_LEVEL_TRIGGER, /* Internal reserved         */
    [Reserved16_IRQn] = ECLIC_LEVEL_TRIGGER,
    [TIMER6_C2_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [TIMER5_C2_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [TIMER4_C2_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [TIMER3_C2_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [TIMER2_C2_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [TIMER1_C2_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [DMA_LCM_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CPU_LCM_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [RCC_IRQn              ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [UART6_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [UART5_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPG_IRQn              ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [FSMC_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [FFT_IRQn              ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMASCH_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C8_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C7_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C6_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C5_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C4_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C3_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C2_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA2_C1_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER3_C1_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [TIMER2_C1_IRQn        ] = ECLIC_LEVEL_TRIGGER,
    [NPU_IRQn              ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SMCA_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [OTFSCA_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XFLASHC_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SMCM2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SMCM1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CPU1_SPL_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [NMITWDT1_IRQn         ] = ECLIC_LEVEL_TRIGGER,
    [WWDT1_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [CRC1_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [HRCAP7_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [HRCAP6_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT5_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT4_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT3_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM4DR4_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM4DR3_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM4DR2_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM4DR1_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC4_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC3_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC_EVT_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB4_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB3_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB_EVT_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA4_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA3_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA_EVT_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [USB_IRQn              ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCA_IRQn              ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [PMBUS_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CANFD3_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM18_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM17_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CANFD2_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CANFD1_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCI2_IRQn             ] = ECLIC_LEVEL_TRIGGER,
    [SCI1_IRQn             ] = ECLIC_LEVEL_TRIGGER,
    [CLB6_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB5_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM4_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM3_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM18_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM17_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCI4_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SCI3_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [I2C2_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [I2C1_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM3DR4_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM3DR3_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM3DR2_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM3DR1_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C8_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C7_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP6_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP5_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C6_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C5_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C4_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C3_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C2_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [DMA1_C1_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR4_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR3_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR2_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2DR1_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [BSPI4_TX_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [BSPI4_RX_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [BSPI3_TX_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [BSPI3_RX_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [USART2_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [USART1_IRQn           ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [BSPI2_TX_IRQn         ] = ECLIC_LEVEL_TRIGGER,
    [BSPI2_RX_IRQn         ] = ECLIC_LEVEL_TRIGGER,
    [BSPI1_TX_IRQn         ] = ECLIC_LEVEL_TRIGGER,
    [BSPI1_RX_IRQn         ] = ECLIC_LEVEL_TRIGGER,
    [SDFM1DR4_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR3_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR2_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1DR1_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAT_SYNC1T_IRQn      ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAT_RST_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SDFM1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB4_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB3_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB2_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CLB1_IRQn             ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP4_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP3_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EQEP1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP7_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP6_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP5_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP4_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP3_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAP1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM16_IRQn           ] = ECLIC_LEVEL_TRIGGER,
    [EPWM15_IRQn           ] = ECLIC_LEVEL_TRIGGER,
    [EPWM14_IRQn           ] = ECLIC_LEVEL_TRIGGER,
    [EPWM13_IRQn           ] = ECLIC_LEVEL_TRIGGER,
    [EPWM12_IRQn           ] = ECLIC_LEVEL_TRIGGER,
    [EPWM11_IRQn           ] = ECLIC_LEVEL_TRIGGER,
    [EPWM10_IRQn           ] = ECLIC_LEVEL_TRIGGER,
    [EPWM9_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM8_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM7_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM6_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM5_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM4_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM3_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM2_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM1_IRQn            ] = ECLIC_LEVEL_TRIGGER,
    [EPWM16_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM15_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM14_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM13_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM12_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM11_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM10_TZ_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM9_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM8_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM7_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM6_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM5_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM4_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM3_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM2_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [EPWM1_TZ_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CPU2_IPC_IRQn         ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAT_INTn_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ECAT_SYNC0_IRQn       ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [SYS_ERR_IRQn          ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [CPU1_WAKE_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [TIMER1_C1_IRQn        ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT2_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [XINT1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCC1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCB1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
    [ADCA1_IRQn            ] = ECLIC_POSTIVE_EDGE_TRIGGER,
};

#endif
/* ========================================================================== */
/*                          Local Function Definitions                        */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Global Functions Definitions                       */
/* ========================================================================== */

/**
 * @brief   Enable Interrupt
 * @details Enables a device specific interrupt in the ECLIC interrupt controller.
 * @param   [in]      IRQn  Device specific interrupt number.
 * @note    IRQn must not be negative.
 */
void Interrupt_enable(IRQn_Type IRQn)
{
    ECLIC_EnableIRQ(IRQn);
}


/**
 * @brief   Disable Interrupt
 * @details Disables a device specific interrupt in the NVIC interrupt controller.
 * @param   [in]      IRQn  Device specific interrupt number.
 * @note    IRQn must not be negative.
 */
void Interrupt_disable(IRQn_Type IRQn)
{
    ECLIC_DisableIRQ(IRQn);
}

/**
 * @brief  Set the priority of an interrupt.
 * @param  [in] IRQn: External interrupt number.
 *         This parameter can be an enumerator of IRQn_Type enumeration
 * @param  [in] PreemptPriority: The pre-emption priority for the IRQn channel.
 *         This parameter can be a value between 0 and 7
 *         A big priority value indicates a higher priority
 * @param  [in] SubPriority: the subpriority level for the IRQ channel.
 *         This parameter is unused
 *         A big priority value indicates a higher priority.
 * @retval None
 */
void Interrupt_setPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{
    ECLIC_SetLevelIRQ(IRQn, PreemptPriority);
    ECLIC_SetPriorityIRQ(IRQn, SubPriority);
}

/**
 * @brief   Register an interrupt
 * @details register an ISR for an IRQ number
 * @param   [in] IRQn: External interrupt number.
 *          This parameter can be an enumerator of IRQn_Type enumeration
 * @param   [in] handler: interrupt service function
 * @return  none
 */

void Interrupt_register(IRQn_Type IRQn, IrqHandlerType handler)
{
    ECLIC_SetShvIRQ(IRQn, ECLIC_VECTOR_INTERRUPT);
    /* set interrupt trigger mode and polarity */
    ECLIC_SetTrigIRQ(IRQn, dspIRQTriggleType[IRQn]);

    if ( handler != NULL )
    {
        /* set interrupt handler entry to vector table */
        ECLIC_SetVector(IRQn, (rv_csr_t) handler);
    }
}

/**
 * @brief  Unregister an interrupt
 * @param  [in] IRQn: External interrupt number.
 *         This parameter can be an enumerator of IRQn_Type enumeration
 * @retval None
 */
void Interrupt_unregister(IRQn_Type IRQn)
{
    ECLIC_DisableIRQ(IRQn);
    ECLIC_SetVector(IRQn, (rv_csr_t) NULL);
}

#ifdef __cplusplus
}
#endif
