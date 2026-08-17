/**
 *************************************************************************************
 * @file hw_SYSCTL.h
 * @brief This file impleted the function of gpio_test.
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

#ifndef __HW_SYSCTL_H
#define __HW_SYSCTL_H

#if SYSCTL_HW_VER == 0

#define SYSCTL_PERIPH_IP_M                   0x10000000U
#define SYSCTL_PERIPH_IP_S                   28U
#define SYSCTL_PERIPH_REG_M                  0x000FFF00U
#define SYSCTL_PERIPH_REG_S                  8U
#define SYSCTL_PERIPH_BIT_M                  0x000000FFU
#define SYSCTL_PERIPH_BIT_S                  0U
/*
 * SYSCTL register offset
 */

#define SYSCTL_O_MSPI_CFG               (0x100)
#define SYSCTL_O_BSPI1_CFG              (0x140)
#define SYSCTL_O_BSPI2_CFG              (0x144)
#define SYSCTL_O_BSPI3_CFG              (0x148)
#define SYSCTL_O_BSPI4_CFG              (0x14C)
#define SYSCTL_O_CTRL_SUB               (0x180)
#define SYSCTL_O_SMCM                   (0x1C0)
#define SYSCTL_O_SMCM_HWINT             (0x1C4)
#define SYSCTL_O_SMCM_ECC_ERR           (0x1C8)

#define SYSCTL_O_CORE_NMI_WK_EN         (0x208)
#define SYSCTL_O_MATRIX4_REMAP          (0x240)
#define SYSCTL_O_EQEP1_CFG              (0x280)
#define SYSCTL_O_EQEP2_CFG              (0x284)
#define SYSCTL_O_EQEP3_CFG              (0x288)
#define SYSCTL_O_ECAP1_SYNCSEL          (0x2C0)
#define SYSCTL_O_ECAP2_SYNCSEL          (0x2C4)
#define SYSCTL_O_ECAP3_SYNCSEL          (0x2C8)
#define SYSCTL_O_ECAP4_SYNCSEL          (0x2CC)
#define SYSCTL_O_TIMERx_STAT            (0x300)

//SYSCTL timer
#define SYSCTL_O_TIM1_PRESC             (0x304)
#define SYSCTL_O_TIM2_PRESC             (0x308)
#define SYSCTL_O_TIM3_PRESC             (0x30C)
#define SYSCTL_O_TIM4_PRESC             (0x310)

#define SYSCTL_O_EPWM1_SYNCIN_SEL       (0x340)
#define SYSCTL_O_EPWM2_SYNCIN_SEL       (0x344)
#define SYSCTL_O_EPWM3_SYNCIN_SEL       (0x348)
#define SYSCTL_O_EPWM4_SYNCIN_SEL       (0x34C)
#define SYSCTL_O_EPWM5_SYNCIN_SEL       (0x350)
#define SYSCTL_O_EPWM6_SYNCIN_SEL       (0x354)
#define SYSCTL_O_EPWM7_SYNCIN_SEL       (0x358)
#define SYSCTL_O_EPWM8_SYNCIN_SEL       (0x35C)
#define SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL  (0x370)
#define SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL  (0x374)
#define SYSCTL_O_HRPWM_CLK_EN           (0x378)
#define SYSCTL_O_SYNC_SELECT            (0x37C)
#define SYSCTL_O_SYNCSOC_LOCK           (0x380)

//SYSCTL WWDG
#define SYSCTL_O_WWDG_DBG_CFG           (0x3C0)
//SYSCTL debug config
#define SYSCTL_O_DBG_CTRL               (0x3C4)

//
#define SYSCTL_O_EXTI_WK_EN             (0x400)//LPM
#define SYSCTL_O_DCC_NMI_IRQ_EN         (0x440)
//SYSCTL Analogsub
#define SYSCTL_O_INTERNAL_TEST_CTL      (0x480)
#define SYSCTL_O_CONFIG_LOCK            (0x484)
#define SYSCTL_O_TSNS_CTL               (0x488)//Tempsensor Enable
#define SYSCTL_O_ANAREF_CTL             (0x48C)//Analog reference voltage
#define SYSCTL_O_VMON_CTL               (0x490)
#define SYSCTL_O_CMPHPMX_SEL            (0x494)
#define SYSCTL_O_CMPLPMX_SEL            (0x498)
#define SYSCTL_O_CMPHNMX_SEL            (0x49C)
#define SYSCTL_O_CMPLNMX_SEL            (0x4A0)
#define SYSCTL_O_ADC_DAC_LOOP           (0x4A4)
#define SYSCTL_O_ANALOG_SUB_LOCK        (0x4A8)
#define SYSCTL_O_AGPIO_CTRLA            (0x4AC)

//SYSCTL Option Byte
#define SYSCTL_O_OB_SEL                 (0x4C0)
#define SYSCTL_O_OPTION_BYTE0           (0x4C4)
#define SYSCTL_O_OPTION_BYTE1           (0x4C8)
#define SYSCTL_O_OPTION_BYTE2           (0x4CC)
#define SYSCTL_O_OPTION_BYTE3           (0x4D0)
#define SYSCTL_O_OPTION_BYTE4           (0x4D4)
#define SYSCTL_O_OPTION_BYTE5           (0x4D8)
#define SYSCTL_O_OPTION_BYTE6           (0x4DC)
#define SYSCTL_O_OPTION_BYTE7           (0x4E0)
#define SYSCTL_O_OPTION_BYTE8           (0x4E4)
#define SYSCTL_O_OPTION_BYTE9           (0x4E8)
#define SYSCTL_O_OPTION_BYTE10          (0x4EC)
#define SYSCTL_O_OPTION_BYTE11          (0x4F0)
//SYSCTL wdg
#define SYSCTL_O_WDG_SPEED_UP           (0x500)

//SYSCTL ERR
#define SYSCTL_O_ERROR_STAT             (0x540)
#define SYSCTL_O_ERROR_STAT_CLR         (0x544)
#define SYSCTL_O_SRROR_STAT_FRC         (0x548)
#define SYSCTL_O_ERROR_CTL              (0x54C)
#define SYSCTL_O_ERROR_LOCK             (0x550)

//SYSCTL CMPSS
#define SYSCTL_O_CMPSS_CFG              (0x580)

//SYSCTL DACC
#define SYSCTL_O_DACC_CFG               (0x5C0)

//SYSCTL XFlashc
#define SYSCTL_O_XFLASHC                (0xC0)

//SYSCTL GPIO
#define SYSCTL_O_REUSEx                 (0x0)
#define SYSCTL_O_GPIOx_DEBOUNCE_VAL     (0x8C)
#define SYSCTL_O_GPIOx_QUAL_PRDx        (0x800)
#define SYSCTL_O_QUAL_MODEx             (0x860)
#define SYSCTL_O_INPUT_INVx             (0x878)

//SYSCTL PAD
#define SYSCTL_O_GPIO_PEx               (0x600)
#define SYSCTL_O_GPIO_PSx               (0x620)
#define SYSCTL_O_GPIO_ISx               (0x640)
#define SYSCTL_O_GPIO_DRx               (0x660)
#define SYSCTL_O_GPIOC_AMSEL            (0x884)

//SYSCTL HAC
#define SYSCTL_O_HAC_LP_EN              (0x900)
#define SYSCTL_O_HAC_SRCx               (0x904)
#define SYSCTL_O_HAC_I_DSTx             (0x910)

#define OB_VALID_KEY                (0xAA5555AAU)
#define OB_VALID_KEY_O              (0x300U)

#define OB_VREF_2P5_O               (0x000U)
#define OB_VREF_1P65_O              (0x004U)

#define OB_ADCA_2P5_OFFSET_O        (0x008U)
#define OB_ADCA_1P65_OFFSET_O       (0x00CU)
#define OB_ADCB_2P5_OFFSET_O        (0x010U)
#define OB_ADCB_1P65_OFFSET_O       (0x014U)
#define OB_ADCC_2P5_OFFSET_O        (0x018U)
#define OB_ADCC_1P65_OFFSET_O       (0x01CU)

#define OB_HSI1_O               (0x310U)
#define OB_HSI2_O               (0x314U)
#define OB_VREF_O               (0x31CU)

//#define SYSCTL_INIT(offset) (*((volatile int *)(SYSCTL_BASE + offset)))

//*************************************************************************************************
//
// The following are defines for the bit fields in the MSPI register
//
//*************************************************************************************************
#define SYSCTL_MSPI_XIP_EN                      (0x1U)
#define SYSCTL_MSPI_XIP_READ_LITTLE_ENDIAN      (0x2U)
#define SYSCTL_MSPI_NONXIP_READ_LITTLE_ENDIAN   (0x4U)
#define SYSCTL_MSPI_NONXIP_WIRTE_LITTLE_ENDIAN  (0x8U)
#define SYSCTL_MSPI_CFG_CLEAR                   (0x0U)
#define SYSCTL_MSPI_IO_EN                       0x80000000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the BSPIx register
//
//*************************************************************************************************
#define SYSCTL_BSPI1_MASTER_EN                      0x14001U
#define SYSCTL_BSPI1_SLAVE_EN                       0x14000U

#define SYSCTL_BSPI2_MASTER_EN                      0x14401U
#define SYSCTL_BSPI2_SLAVE_EN                       0x14400U

#define SYSCTL_BSPI3_MASTER_EN                      0x14801U
#define SYSCTL_BSPI3_SLAVE_EN                       0x14800U

#define SYSCTL_BSPI4_MASTER_EN                      0x14C01U
#define SYSCTL_BSPI4_SLAVE_EN                       0x14C00U

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRL_SUB register
//
//*************************************************************************************************
#define SYSCTL_CTRLSUB_EPWMGBCLKSYNC                0x10000U
#define SYSCTL_CTRLSUB_EPWMCPU1TBCLKSYNC            0x20000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the CORE_NMI_WK_EN register
//
//*************************************************************************************************
#define SYSCTL_CORE1_NMI_WK_EN                      0x1U
#define SYSCTL_CORE1_NMI_WK_DIS                     0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the MATRIX4_REMAP register
//
//*************************************************************************************************
#define SYSCTL_MATRIX4_REMAP_EFLASHC                0x0U
#define SYSCTL_MATRIX4_REMAP_XFLASHC                0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEPx_CFG register
//
//*************************************************************************************************
#define SYSCTL_EQEPxa_SEL_M                         0xFU
#define SYSCTL_EQEPxb_SEL_M                         0xF0U
#define SYSCTL_EQEPxi_SEL_M                         0xF00U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAPx_CFG register
//
//*************************************************************************************************
#define SYSCTL_ECAPx_SYNCIN_M                       0x3FU

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMERx_STAT register
//
//*************************************************************************************************
#define SYSCTL_TIM1_STAT_M                      0x3U
#define SYSCTL_TIM2_STAT_M                      0xCU
#define SYSCTL_TIM3_STAT_M                      0x30U
#define SYSCTL_TIM4_STAT_M                      0xC0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWMx_SYNCIN_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_SYNCIN_SEL_M               0x7FU

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_ADC_SOCA_OUT_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_ADC_SOCA_OUT_EN            0x1U
#define SYSCTL_EPWMx_ADC_SOCA_OUT_DIS           0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_ADC_SOCB_OUT_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_ADC_SOCB_OUT_EN            0x1U
#define SYSCTL_EPWMx_ADC_SOCB_OUT_DIS           0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR0 register
//
//*************************************************************************************************
#define SYSCTL_HRPWM_CLK_EN                     0x1U
#define SYSCTL_HRPWM_CLK_DIS                    0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNC_SEL register
//
//*************************************************************************************************
#define SYSCTL_SYNCOUT_SEL_M                    0x0F000000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG register
//
//*************************************************************************************************
#define SYSCTL_WWDG_DEBUG_MODE_EN               0x1U
#define SYSCTL_WWDG_DEBUG_MODE_DIS              0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPM register
//
//*************************************************************************************************
#define SYSCTL_EXTI_WK_EN                       0x1U
#define SYSCTL_EXTI_WK_DIS                      0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DCC register
//
//*************************************************************************************************
#define SYSCTL_DCC_NMI_IRQ_EN                   0x1U
#define SYSCTL_DCC_NMI_IRQ_DIS                  0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_CTRL register
//
//*************************************************************************************************
#define SYSCTL_WWDG_DBG_STOP_EN                 0x1U
#define SYSCTL_WWDG_DBG_STOP_DIS                0x0U
#define SYSCTL_LPM_DBG_SLEEP_M                  0x4U

//*************************************************************************************************
//
// The following are defines for the bit fields in the SMCM register
//
//*************************************************************************************************
#define SYSCTL_SMCM_HWINT_EN                    0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMERx_PRESC register
//
//*************************************************************************************************
#define SYSCTL_TIMERx_CH1_PRESC_M               0xFFFFU
#define SYSCTL_TIMERx_CH2_PRESC_M               0xFFFF0000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDT_SPEED_UP register
//
//*************************************************************************************************
#define SYSCTL_WDT_SPEED_UP_EN                  0x1U
#define SYSCTL_WDT_SPEED_UP_DIS                 0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_SYNCSOC_LOCK register
//
//*************************************************************************************************
#define SYSCTL_ADC_SOCOUTSEL_LOCK               0x2U
#define SYSCTL_ADC_SOCOUTSEL_UNLOCK             0x0U
#define SYSCTL_SYNC_SEL_LOCK                    0x1U
#define SYSCTL_SYNC_SEL_UNLOCK                  0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRORSTS register
//
//*************************************************************************************************
#define SYSCTL_ERRORSTS_ERROR_M                 0x1U
#define SYSCTL_ERRORSTS_PINSTS_M                0x2U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSCLR register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSCLR_ERROR_CLR              0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSFRC register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSFRC_ERROR_SET              0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSCTL register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSCTL_ERROR_0_ELSE_1         0x0U
#define SYSCTL_ERRSTSCTL_ERROR_1_ELSE_0         0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSLOCK register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSLOCK_ERRORCTL_LOCK         0x1U
#define SYSCTL_ERRSTSLOCK_ERRORCTL_UNLOCK       0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTERNALTESTCTL register
//
//*************************************************************************************************
#define SYSCTL_INTERNALTESTCTL_TESTSEL_S   0U
#define SYSCTL_INTERNALTESTCTL_TESTSEL_M   0x1FU         // Test Select
#define SYSCTL_INTERNALTESTCTL_KEY_S       16U
#define SYSCTL_INTERNALTESTCTL_KEY_M       0xFFFF0000U   // Key to Enable writes

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONFIGLOCK register
//
//*************************************************************************************************
#define SYSCTL_CONFIGLOCK_AGPIOCTRL   0x8U   // Locks all AGPIOCTRL Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the TSNSCTL register
//
//*************************************************************************************************
#define SYSCTL_TSNSCTL_ENABLE   0x1U   // Temperature Sensor Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ANAREFCTL register
//
//*************************************************************************************************
#define SYSCTL_ANAREFCTL_ANAREFSEL                0x1U      // Analog Reference Select
#define SYSCTL_ANAREFCTL_ANAREF2P5SEL             0x100U    // Analog Reference Select
#define SYSCTL_ANAREFCTL_ANAREFSEL_SUP_OVERRIDE   0x8000U   // Control for overriding the analog
// reference with VDDA/VSSA

//*************************************************************************************************
//
// The following are defines for the bit fields in the VMONCTL register
//
//*************************************************************************************************
#define SYSCTL_VMONCTL_BORLVMONDIS   0x100U   // Disable BORL(ow) feature on VDDIO

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHPMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_S   0U
#define SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M   0x7U     // CMP1HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP2HPMXSEL_S   3U
#define SYSCTL_CMPHPMXSEL_CMP2HPMXSEL_M   0x38U    // CMP2HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP3HPMXSEL_S   6U
#define SYSCTL_CMPHPMXSEL_CMP3HPMXSEL_M   0x1C0U   // CMP3HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP4HPMXSEL_S   9U
#define SYSCTL_CMPHPMXSEL_CMP4HPMXSEL_M   0xE00U   // CMP4HPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLPMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_S   0U
#define SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M   0x7U     // CMP1LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP2LPMXSEL_S   3U
#define SYSCTL_CMPLPMXSEL_CMP2LPMXSEL_M   0x38U    // CMP2LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP3LPMXSEL_S   6U
#define SYSCTL_CMPLPMXSEL_CMP3LPMXSEL_M   0x1C0U   // CMP3LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP4LPMXSEL_S   9U
#define SYSCTL_CMPLPMXSEL_CMP4LPMXSEL_M   0xE00U   // CMP4LPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHNMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPHNMXSEL_CMP1HNMXSEL   0x1U   // CMP1HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP2HNMXSEL   0x2U   // CMP2HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP3HNMXSEL   0x4U   // CMP3HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP4HNMXSEL   0x8U   // CMP4HNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLNMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPLNMXSEL_CMP1LNMXSEL   0x1U   // CMP1LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP2LNMXSEL   0x2U   // CMP2LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP3LNMXSEL   0x4U   // CMP3LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP4LNMXSEL   0x8U   // CMP4LNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCDACLOOPBACK register
//
//*************************************************************************************************
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCA   0x1U          // Enable DACA loopback to ADCA
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCB   0x2U          // Enable DACA loopback to ADCA
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCC   0x4U          // Enable DACA loopback to ADCC
#define SYSCTL_ADCDACLOOPBACK_KEY_S       16U
#define SYSCTL_ADCDACLOOPBACK_KEY_M       0xFFFF0000U   // Key to enable writes

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSSCTL register
//
//*************************************************************************************************
#define SYSCTL_CMPSSCTL_CMP1LDACOUTEN   0x1U      // Enable general purpose DAC functionality for
// CMPSS1.COMPDACL
#define SYSCTL_CMPSSCTL_CMPSSCTLEN      0x8000U   // Enable the CMPSSCTL Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the LOCK register
//
//*************************************************************************************************
#define SYSCTL_LOCK_TSNSCTL      0x1U     // TSNSCTL Register lock bit
#define SYSCTL_LOCK_ANAREFCTL    0x2U     // ANAREFCTL Register lock bit
#define SYSCTL_LOCK_VMONCTL      0x4U     // VMONCTL Register lock bit
#define SYSCTL_LOCK_CMPHPMXSEL   0x20U    // CMPHPMXSEL Register lock bit
#define SYSCTL_LOCK_CMPLPMXSEL   0x40U    // CMPLPMXSEL Register lock bit
#define SYSCTL_LOCK_CMPHNMXSEL   0x80U    // CMPHNMXSEL Register lock bit
#define SYSCTL_LOCK_CMPLNMXSEL   0x100U   // CMPLNMXSEL Register lock bit
#define SYSCTL_LOCK_VREGCTL      0x200U   // VREGCTL Register lock bit
#define SYSCTL_LOCK_CMPSSCTL     0x400U   // CMPSSCTL Register lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOCTRLA register
//
//*************************************************************************************************
#define SYSCTL_AGPIOCTRLA_GPIO12   0x1000U       // AGPIOCTRL for GPIO12
#define SYSCTL_AGPIOCTRLA_GPIO13   0x2000U       // AGPIOCTRL for GPIO13
#define SYSCTL_AGPIOCTRLA_GPIO20   0x100000U     // AGPIOCTRL for GPIO20
#define SYSCTL_AGPIOCTRLA_GPIO21   0x200000U     // AGPIOCTRL for GPIO21
#define SYSCTL_AGPIOCTRLA_GPIO28   0x10000000U   // AGPIOCTRL for GPIO28

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOCTRLH register
//
//*************************************************************************************************
#define SYSCTL_AGPIOCTRLH_GPIO224   0x1U       // AGPIOCTRL for GPIO224
#define SYSCTL_AGPIOCTRLH_GPIO226   0x4U       // AGPIOCTRL for GPIO226
#define SYSCTL_AGPIOCTRLH_GPIO227   0x8U       // AGPIOCTRL for GPIO227
#define SYSCTL_AGPIOCTRLH_GPIO228   0x10U      // AGPIOCTRL for GPIO228
#define SYSCTL_AGPIOCTRLH_GPIO230   0x40U      // AGPIOCTRL for GPIO230
#define SYSCTL_AGPIOCTRLH_GPIO242   0x40000U   // AGPIOCTRL for GPIO242

#define CTRLSUB_BASE  0x29001180U
#define SYNC_BASE     0x29001340U

#define SYSCTL_CTRLSUB_GBCLKSYNC_S       16U
#define SYSCTL_CTRLSUB_GBCLKSYNC_M       0x10000U
#define SYSCTL_CTRLSUB_CPU1TBCLKSYNC_S   17U
#define SYSCTL_CTRLSUB_CPU1TBCLKSYNC_M   0x20000U
#define SYSCTL_CTRLSUB_CPU2TBCLKSYNC_S   18U
#define SYSCTL_CTRLSUB_CPU2TBCLKSYNC_M   0x40000U

#define SYSCTL_EPWMxSYNCINSEL_S          0U
#define SYSCTL_EPWMxSYNCINSEL_M          0x7FU

#define SYSCTL_ADCSOCxOUTSELECCT_S       0U
#define SYSCTL_ADCSOCxOUTSELECCT_M       0x7FFFFFFFU

#define SYSCTL_PCLKCR0_HRPWM_S           0U
#define SYSCTL_PCLKCR0_HRPWM_M           0x1U

#define SYSCTL_SYNCSELECT_SYNCOUT_S       24U
#define SYSCTL_SYNCSELECT_SYNCOUT_M       0x1F000000U   // Select Syncout Source

#define SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_S  0U
#define SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_M  0x1U
#define SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_S  1U
#define SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_M  0x2U
//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSELECT register
//
//*************************************************************************************************
#define SYSCTL_ADCSOC_SRC_PWM1SOCA   0x1U //!<ePWM1 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM2SOCA   0x2U //!<ePWM2 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM3SOCA   0x4U //!<ePWM3 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM4SOCA   0x8U //!<ePWM4 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM5SOCA   0x10U //!<ePWM5 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM6SOCA   0x20U //!<ePWM6 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM7SOCA   0x40U //!<ePWM7 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM8SOCA   0x80U //!<ePWM8 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM1SOCB   0x10000U //!<ePWM1 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM2SOCB   0x20000U //!<ePWM2 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM3SOCB   0x40000U //!<ePWM3 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM4SOCB   0x80000U //!<ePWM4 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM5SOCB   0x100000U //!<ePWM5 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM6SOCB   0x200000U //!<ePWM6 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM7SOCB   0x400000U //!<ePWM7 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM8SOCB   0x800000U //!<ePWM8 SOCB for ADCSOCBO

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCSOCLOCK register
//
//*************************************************************************************************
#define SYSCTL_SYNCSOCLOCK_SYNCSELECT        0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT   0x2U   // ADCSOCOUTSELECT Register Lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBGCTRL register
//
//*************************************************************************************************
#define SYSCTL_DBGCTRL_WWDG_STOP_EN             0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_SLEEP_EN             0x4U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_STOP_EN              0x8U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_STANDBY_EN           0x10U   // SYNCSEL Register Lock bit

#if EPWM_HW_VER == 0
//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncInputConfig(). Note that some of these are only valid for
//! certain values of \e syncInput. See device technical reference manual for
//! info on time-base counter synchronization for details.
//
//*****************************************************************************
typedef enum
{
    //! Disable Sync-in
    EPWM_SYNC_IN_PULSE_SRC_DISABLE = 0x0,
    //! Sync-in source is EPWM1 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1 = 0x1,
    //! Sync-in source is EPWM2 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2 = 0x2,
    //! Sync-in source is EPWM3 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3 = 0x3,
    //! Sync-in source is EPWM4 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4 = 0x4,
    //! Sync-in source is EPWM5 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5 = 0x5,
    //! Sync-in source is EPWM6 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6 = 0x6,
    //! Sync-in source is EPWM7 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7 = 0x7,
    //! Sync-in source is EPWM8 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8 = 0x8,
    //! Sync-in source is ECAP1 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1 = 0x11,
    //! Sync-in source is ECAP2 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2 = 0x12,
    //! Sync-in source is ECAP3 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3 = 0x13,
    //! Sync-in source is Input XBAR out5 signal
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5 = 0x18,
    //! Sync-in source is Input XBAR out6 signal
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6 = 0x19,
    //! Sync-in source is FSI RX trigger1 signal
    EPWM_SYNC_IN_PULSE_SRC_FSIRX_TRIG1 = 0x1F,
} EPWM_SyncInPulseSource;
#endif

//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncOutputConfig().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT = 0,   //!< EPWM1SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM2SYNCOUT = 1,
    SYSCTL_SYNC_OUT_SRC_EPWM3SYNCOUT = 2,
    SYSCTL_SYNC_OUT_SRC_EPWM4SYNCOUT = 3,
    SYSCTL_SYNC_OUT_SRC_EPWM5SYNCOUT = 4,
    SYSCTL_SYNC_OUT_SRC_EPWM6SYNCOUT = 5,
    SYSCTL_SYNC_OUT_SRC_EPWM7SYNCOUT = 6,
    SYSCTL_SYNC_OUT_SRC_EPWM8SYNCOUT = 7,
    SYSCTL_SYNC_OUT_SRC_ECAP1SYNCOUT = 24,
    SYSCTL_SYNC_OUT_SRC_ECAP2SYNCOUT = 25,
    SYSCTL_SYNC_OUT_SRC_ECAP3SYNCOUT = 26,

} SysCtl_SyncOutputSource;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_enablePeripheral()
//! and SysCtl_disablePeripheral() as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_PERIPH_CLK_HRPWM = 0x00037800,
    SYSCTL_PERIPH_CLK_TBCLKSYNC = 0x00018010,
    SYSCTL_PERIPH_CLK_CPU1TBCLKSYNC = 0x00018011,
    //AHB1
    SYSCTL_PERIPH_CLK_ERM = 0x1000301F,
    SYSCTL_PERIPH_CLK_ADC1 = 0x1000301E,
    SYSCTL_PERIPH_CLK_ADC2 = 0x1000301D,
    SYSCTL_PERIPH_CLK_ADC3 = 0x1000301C,
    SYSCTL_PERIPH_CLK_ECAP1 = 0x1000301B,
    SYSCTL_PERIPH_CLK_ECAP2 = 0x1000301A,
    SYSCTL_PERIPH_CLK_ECAP3 = 0x10003019,
    SYSCTL_PERIPH_CLK_ECAP4 = 0x10003018,
    SYSCTL_PERIPH_CLK_EQEP1 = 0x10003017,
    SYSCTL_PERIPH_CLK_EQEP2 = 0x10003016,
    SYSCTL_PERIPH_CLK_EQEP3 = 0x10003015,
    SYSCTL_PERIPH_CLK_SDFM1 = 0x10003014,
    SYSCTL_PERIPH_CLK_SDFM2 = 0x10003013,
    SYSCTL_PERIPH_CLK_CMPSS1 = 0x10003012,
    SYSCTL_PERIPH_CLK_CMPSS2 = 0x10003011,
    SYSCTL_PERIPH_CLK_CMPSS3 = 0x10003010,
    SYSCTL_PERIPH_CLK_CMPSS4 = 0x1000300F,
    SYSCTL_PERIPH_CLK_CMPSS5 = 0x1000300E,
    SYSCTL_PERIPH_CLK_CMPSS6 = 0x1000300D,
    SYSCTL_PERIPH_CLK_CMPSS7 = 0x1000300C,
    SYSCTL_PERIPH_CLK_EPWM1 = 0x1000300B,
    SYSCTL_PERIPH_CLK_EPWM2 = 0x1000300A,
    SYSCTL_PERIPH_CLK_EPWM3 = 0x10003009,
    SYSCTL_PERIPH_CLK_EPWM4 = 0x10003008,
    SYSCTL_PERIPH_CLK_EPWM5 = 0x10003007,
    SYSCTL_PERIPH_CLK_EPWM6 = 0x10003006,
    SYSCTL_PERIPH_CLK_EPWM7 = 0x10003005,
    SYSCTL_PERIPH_CLK_EPWM8 = 0x10003004,
    //AHB2
    SYSCTL_PERIPH_CLK_DACC1 = 0x1000341F,
    SYSCTL_PERIPH_CLK_DACC2 = 0x1000341E,
    SYSCTL_PERIPH_CLK_DMA1 = 0x1000341D,
    SYSCTL_PERIPH_CLK_DMA2 = 0x1000341C,
    SYSCTL_PERIPH_CLK_DMASCH = 0x1000341B,
    SYSCTL_PERIPH_CLK_SMCM = 0x1000341A,
    SYSCTL_PERIPH_CLK_XFLASHC = 0x10003417,
    SYSCTL_PERIPH_CLK_AES = 0x10003416,
    SYSCTL_PERIPH_CLK_CSPIF = 0x10003413,
    SYSCTL_PERIPH_CLK_CSPIL = 0x10003412,
    SYSCTL_PERIPH_CLK_QSPI = 0x10003411,
    SYSCTL_PERIPH_CLK_EFLASHC = 0x10003401,
    SYSCTL_PERIPH_CLK_LCM = 0x10003400,
    //APBH
    SYSCTL_PERIPH_CLK_TIMER1 = 0x1000381F,
    SYSCTL_PERIPH_CLK_TIMER2 = 0x1000381E,
    SYSCTL_PERIPH_CLK_TIMER3 = 0x1000381D,
    SYSCTL_PERIPH_CLK_TIMER4 = 0x1000381C,
    //APBL1
    SYSCTL_PERIPH_CLK_IWDT = 0x10003C1F,
    SYSCTL_PERIPH_CLK_WWDT = 0x10003C1D,
    SYSCTL_PERIPH_CLK_SYSCTL = 0x10003C1B,
    SYSCTL_PERIPH_CLK_UART1 = 0x10003C18,
    SYSCTL_PERIPH_CLK_UART2 = 0x10003C17,
    SYSCTL_PERIPH_CLK_TIMER5 = 0x10003C16,
    SYSCTL_PERIPH_CLK_TIMER6 = 0x10003C15,
    SYSCTL_PERIPH_CLK_I2C1 = 0x10003C12,
    SYSCTL_PERIPH_CLK_BSPI4 = 0x10003C11,
    SYSCTL_PERIPH_CLK_I2C2 = 0x10003C0E,
    SYSCTL_PERIPH_CLK_I2C3 = 0x10003C0D,
    SYSCTL_PERIPH_CLK_USART1 = 0x10003C0C,
    SYSCTL_PERIPH_CLK_USART2 = 0x10003C0B,
    SYSCTL_PERIPH_CLK_CANFD1 = 0x10003C0A,
    SYSCTL_PERIPH_CLK_CANFD2 = 0x10003C09,
    SYSCTL_PERIPH_CLK_BSPI1 = 0x10003C08,
    SYSCTL_PERIPH_CLK_BSPI2 = 0x10003C07,
    SYSCTL_PERIPH_CLK_BSPI3 = 0x10003C06,
    SYSCTL_PERIPH_CLK_I2C4 = 0x10003C05,
    SYSCTL_PERIPH_CLK_XBAR = 0x10003C00,
    //APBL2
    SYSCTL_PERIPH_CLK_GPIOA = 0x1000401F,
    SYSCTL_PERIPH_CLK_GPIOB = 0x1000401E,
    SYSCTL_PERIPH_CLK_GPIOC = 0x1000401D,
    SYSCTL_PERIPH_CLK_GPIOD = 0x1000401C,
    SYSCTL_PERIPH_CLK_GPIOE = 0x1000401B,
    SYSCTL_PERIPH_CLK_CLB1 = 0x1000401A,
    SYSCTL_PERIPH_CLK_CRC = 0x10004019,
    SYSCTL_PERIPH_CLK_CLB2 = 0x10004018,
    SYSCTL_PERIPH_CLK_CLB3 = 0x10004017,
    SYSCTL_PERIPH_CLK_CLB4 = 0x10004016,
} SysCtl_PeripheralPCLOCKCR;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_resetPeripheral() as
//! the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    //AHB1
    SYSCTL_PERIPH_RES_ERM = 0x10001C1F,
    SYSCTL_PERIPH_RES_ADC1 = 0x10001C1E,
    SYSCTL_PERIPH_RES_ADC2 = 0x10001C1D,
    SYSCTL_PERIPH_RES_ADC3 = 0x10001C1C,
    SYSCTL_PERIPH_RES_ECAP1 = 0x10001C1B,
    SYSCTL_PERIPH_RES_ECAP2 = 0x10001C1A,
    SYSCTL_PERIPH_RES_ECAP3 = 0x10001C19,
    SYSCTL_PERIPH_RES_ECAP4 = 0x10001C18,
    SYSCTL_PERIPH_RES_EQEP1 = 0x10001C17,
    SYSCTL_PERIPH_RES_EQEP2 = 0x10001C16,
    SYSCTL_PERIPH_RES_EQEP3 = 0x10001C15,
    SYSCTL_PERIPH_RES_SDFM1 = 0x10001C14,
    SYSCTL_PERIPH_RES_SDFM2 = 0x10001C13,
    SYSCTL_PERIPH_RES_CMPSS1 = 0x10001C12,
    SYSCTL_PERIPH_RES_CMPSS2 = 0x10001C11,
    SYSCTL_PERIPH_RES_CMPSS3 = 0x10001C10,
    SYSCTL_PERIPH_RES_CMPSS4 = 0x10001C0F,
    SYSCTL_PERIPH_RES_CMPSS5 = 0x10001C0E,
    SYSCTL_PERIPH_RES_CMPSS6 = 0x10001C0D,
    SYSCTL_PERIPH_RES_CMPSS7 = 0x10001C0C,
    SYSCTL_PERIPH_RES_EPWM1 = 0x10001C0B,
    SYSCTL_PERIPH_RES_EPWM2 = 0x10001C0A,
    SYSCTL_PERIPH_RES_EPWM3 = 0x10001C09,
    SYSCTL_PERIPH_RES_EPWM4 = 0x10001C08,
    SYSCTL_PERIPH_RES_EPWM5 = 0x10001C07,
    SYSCTL_PERIPH_RES_EPWM6 = 0x10001C06,
    SYSCTL_PERIPH_RES_EPWM7 = 0x10001C05,
    SYSCTL_PERIPH_RES_EPWM8 = 0x10001C04,
    //AHB2
    SYSCTL_PERIPH_RES_DACC1 = 0x1000201F,
    SYSCTL_PERIPH_RES_DACC2 = 0x1000201E,
    SYSCTL_PERIPH_RES_DMA1 = 0x1000201D,
    SYSCTL_PERIPH_RES_DMA2 = 0x1000201C,
    SYSCTL_PERIPH_RES_DMASCH = 0x1000201B,
    SYSCTL_PERIPH_RES_SMCM = 0x1000201A,
    SYSCTL_PERIPH_RES_XFLASHC = 0x10002017,
    SYSCTL_PERIPH_RES_AES = 0x10002016,
    SYSCTL_PERIPH_RES_CSPIF = 0x10002013,
    SYSCTL_PERIPH_RES_CSPIL = 0x10002012,
    SYSCTL_PERIPH_RES_QSPI = 0x10002011,
    SYSCTL_PERIPH_RES_EFLASHC = 0x10002001,
    SYSCTL_PERIPH_RES_LCM = 0x10002000,
    //APBH
    SYSCTL_PERIPH_RES_TIMER1 = 0x1000241F,
    SYSCTL_PERIPH_RES_TIMER2 = 0x1000241E,
    SYSCTL_PERIPH_RES_TIMER3 = 0x1000241D,
    SYSCTL_PERIPH_RES_TIMER4 = 0x1000241C,
    //APBL1
    SYSCTL_PERIPH_RES_IWDT = 0x1000281F,
    SYSCTL_PERIPH_RES_WWDT = 0x1000281D,
    SYSCTL_PERIPH_RES_SYSCTL = 0x1000281B,
    SYSCTL_PERIPH_RES_UART1 = 0x10002818,
    SYSCTL_PERIPH_RES_UART2 = 0x10002817,
    SYSCTL_PERIPH_RES_TIMER5 = 0x10002816,
    SYSCTL_PERIPH_RES_TIMER6 = 0x10002815,
    SYSCTL_PERIPH_RES_I2C3 = 0x10002812,
    SYSCTL_PERIPH_RES_BSPI4 = 0x10002811,
    SYSCTL_PERIPH_RES_I2C1 = 0x1000280E,
    SYSCTL_PERIPH_RES_I2C2 = 0x1000280D,
    SYSCTL_PERIPH_RES_USART1 = 0x1000280C,
    SYSCTL_PERIPH_RES_USART2 = 0x1000280B,
    SYSCTL_PERIPH_RES_CANFD1 = 0x1000280A,
    SYSCTL_PERIPH_RES_CANFD2 = 0x10002809,
    SYSCTL_PERIPH_RES_BSPI1 = 0x10002808,
    SYSCTL_PERIPH_RES_BSPI2 = 0x10002807,
    SYSCTL_PERIPH_RES_BSPI3 = 0x10002806,
    SYSCTL_PERIPH_RES_I2C4 = 0x10002805,
    SYSCTL_PERIPH_RES_XBAR = 0x10002800,
    //APBL2
    SYSCTL_PERIPH_RES_GPIO1 = 0x10002C1F,
    SYSCTL_PERIPH_RES_GPIO2 = 0x10002C1E,
    SYSCTL_PERIPH_RES_GPIO3 = 0x10002C1D,
    SYSCTL_PERIPH_RES_GPIO4 = 0x10002C1C,
    SYSCTL_PERIPH_RES_GPIO5 = 0x10002C1B,
    SYSCTL_PERIPH_RES_CLB1 = 0x10002C1A,
    SYSCTL_PERIPH_RES_CRC = 0x10002C19,
    SYSCTL_PERIPH_RES_CLB2 = 0x10002C18,
    SYSCTL_PERIPH_RES_CLB3 = 0x10002C17,
    SYSCTL_PERIPH_RES_CLB4 = 0x10002C16,
} SysCtl_PeripheralSOFTPRES;

//*****************************************************************************
//
// Option bytes Source
//
//*****************************************************************************
typedef enum
{
    EXFLASHC_OB = 0x00,   //!< Option bytes from SYSCTL
    SYSCTCL_OB = 0x01,   //!< Option bytes from external flash controller
} SysCtl_OBSourece;

//*****************************************************************************
//
// GPIO qualification mode
//
//*****************************************************************************
typedef enum
{
    GPIO_SYNC_PCLK = 0x0,  // Synchronous to PCLK
    GPIO_SYNC_3_SAMPLE = 0x1,  // Synchronous (3-sample window)
    GPIO_SYNC_6_SAMPLE = 0x2,  // Synchronous (6-sample window)
    GPIO_ASYNC = 0x3   // Asynchronous
} SysCtl_GPIOxQualificationMode;

//*****************************************************************************
//
// GPIO Pull up/down
//
//*****************************************************************************
typedef enum
{
    GPIOx_PULL_DOWN = 0x0, 
    GPIOx_PULL_UP = 0x1,
} SysCtl_GPIOxUPorDOWN;

//*****************************************************************************
//
// GPIO Input Mode
//
//*****************************************************************************
typedef enum
{
    GPIOx_INPUT_SCHMITT = 0x0, 
    GPIOx_INPUT_BUFFER = 0x1,
} SysCtl_GPIOxInputMode;

//*****************************************************************************
//
// GPIO GPIOx Drive Strength
//
//*****************************************************************************
typedef enum
{
    GPIOx_DR_5mA = 0x0,
    GPIOx_DR_15mA = 0x1,
    GPIOx_DR_20mA = 0x2,
    GPIOx_DR_41mA = 0x3,
} SysCtl_GPIOxDriveStrength;

//*****************************************************************************
//
// GPIO3 Analog Mode Select
//
//*****************************************************************************
typedef enum
{
    GPIOC_Digital_Mode = 0x0, 
    GPIOC_Analog_Mode = 0x1,
} SysCtl_GPIOCAMSEL;

typedef enum
{
    TIMER1CH1 = 0x0,
    TIMER1CH2,
    TIMER2CH1,
    TIMER2CH2,
    TIMER3CH1,
    TIMER3CH2,
    TIMER4CH1,
    TIMER4CH2
} SysCtl_TIMERx;

#elif SYSCTL_HW_VER == 1

#define SYSCTL_PERIPH_IP_M                   0x10000000U
#define SYSCTL_PERIPH_IP_S                   28U
#define SYSCTL_PERIPH_REG_M                  0x000FFF00U
#define SYSCTL_PERIPH_REG_S                  8U
#define SYSCTL_PERIPH_BIT_M                  0x000000FFU
#define SYSCTL_PERIPH_BIT_S                  0U
/*
 * SYSCTL register offset
 */

#define SYSCTL_O_MSPI_CFG               (0x100)
#define SYSCTL_O_BSPI1_CFG              (0x140)
#define SYSCTL_O_BSPI2_CFG              (0x144)
#define SYSCTL_O_BSPI3_CFG              (0x148)
#define SYSCTL_O_BSPI4_CFG              (0x14C)
#define SYSCTL_O_CTRL_SUB               (0x180)
#define SYSCTL_O_SMCM                   (0x1C0)
#define SYSCTL_O_SMCM_HWINT             (0x1C4)
#define SYSCTL_O_SMCM_ECC_ERR           (0x1C8)

#define SYSCTL_O_CORE_NMI_WK_EN         (0x208)
#define SYSCTL_O_MATRIX4_REMAP          (0x240)
#define SYSCTL_O_EQEP1_CFG              (0x280)
#define SYSCTL_O_EQEP2_CFG              (0x284)
#define SYSCTL_O_EQEP3_CFG              (0x288)
#define SYSCTL_O_ECAP1_SYNCSEL          (0x2C0)
#define SYSCTL_O_ECAP2_SYNCSEL          (0x2C4)
#define SYSCTL_O_ECAP3_SYNCSEL          (0x2C8)
#define SYSCTL_O_ECAP4_SYNCSEL          (0x2CC)
#define SYSCTL_O_TIMERx_STAT            (0x300)

//SYSCTL timer
#define SYSCTL_O_TIM1_PRESC             (0x304)
#define SYSCTL_O_TIM2_PRESC             (0x308)
#define SYSCTL_O_TIM3_PRESC             (0x30C)
#define SYSCTL_O_TIM4_PRESC             (0x310)

#define SYSCTL_O_EPWM1_SYNCIN_SEL       (0x340)
#define SYSCTL_O_EPWM2_SYNCIN_SEL       (0x344)
#define SYSCTL_O_EPWM3_SYNCIN_SEL       (0x348)
#define SYSCTL_O_EPWM4_SYNCIN_SEL       (0x34C)
#define SYSCTL_O_EPWM5_SYNCIN_SEL       (0x350)
#define SYSCTL_O_EPWM6_SYNCIN_SEL       (0x354)
#define SYSCTL_O_EPWM7_SYNCIN_SEL       (0x358)
#define SYSCTL_O_EPWM8_SYNCIN_SEL       (0x35C)
#define SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL  (0x370)
#define SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL  (0x374)
#define SYSCTL_O_HRPWM_CLK_EN           (0x378)
#define SYSCTL_O_SYNC_SELECT            (0x37C)
#define SYSCTL_O_SYNCSOC_LOCK           (0x380)

//SYSCTL WWDG
#define SYSCTL_O_WWDG_DBG_CFG           (0x3C0)
//SYSCTL debug config
#define SYSCTL_O_DBG_CTRL               (0x3C4)

//
#define SYSCTL_O_EXTI_WK_EN             (0x400)//LPM
#define SYSCTL_O_DCC_NMI_IRQ_EN         (0x440)
//SYSCTL Analogsub
#define SYSCTL_O_INTERNAL_TEST_CTL      (0x480)
#define SYSCTL_O_CONFIG_LOCK            (0x484)
#define SYSCTL_O_TSNS_CTL               (0x488)//Tempsensor Enable
#define SYSCTL_O_ANAREF_CTL             (0x48C)//Analog reference voltage
#define SYSCTL_O_VMON_CTL               (0x490)
#define SYSCTL_O_CMPHPMX_SEL            (0x494)
#define SYSCTL_O_CMPLPMX_SEL            (0x498)
#define SYSCTL_O_CMPHNMX_SEL            (0x49C)
#define SYSCTL_O_CMPLNMX_SEL            (0x4A0)
#define SYSCTL_O_ADC_DAC_LOOP           (0x4A4)
#define SYSCTL_O_ANALOG_SUB_LOCK        (0x4A8)
#define SYSCTL_O_AGPIO_CTRLA            (0x4AC)

//SYSCTL Option Byte
#define SYSCTL_O_OB_SEL                 (0x4C0)
#define SYSCTL_O_OPTION_BYTE0           (0x4C4)
#define SYSCTL_O_OPTION_BYTE1           (0x4C8)
#define SYSCTL_O_OPTION_BYTE2           (0x4CC)
#define SYSCTL_O_OPTION_BYTE3           (0x4D0)
#define SYSCTL_O_OPTION_BYTE4           (0x4D4)
#define SYSCTL_O_OPTION_BYTE5           (0x4D8)
#define SYSCTL_O_OPTION_BYTE6           (0x4DC)
#define SYSCTL_O_OPTION_BYTE7           (0x4E0)
#define SYSCTL_O_OPTION_BYTE8           (0x4E4)
#define SYSCTL_O_OPTION_BYTE9           (0x4E8)
#define SYSCTL_O_OPTION_BYTE10          (0x4EC)
#define SYSCTL_O_OPTION_BYTE11          (0x4F0)
//SYSCTL wdg
#define SYSCTL_O_WDG_SPEED_UP           (0x500)

//SYSCTL ERR
#define SYSCTL_O_ERROR_STAT             (0x540)
#define SYSCTL_O_ERROR_STAT_CLR         (0x544)
#define SYSCTL_O_SRROR_STAT_FRC         (0x548)
#define SYSCTL_O_ERROR_CTL              (0x54C)
#define SYSCTL_O_ERROR_LOCK             (0x550)

//SYSCTL CMPSS
#define SYSCTL_O_CMPSS_CFG              (0x580)

//SYSCTL DACC
#define SYSCTL_O_DACC_CFG               (0x5C0)

//SYSCTL XFlashc
#define SYSCTL_O_XFLASHC                (0xC0)

//SYSCTL GPIO
#define SYSCTL_O_REUSEx                 (0x0)
#define SYSCTL_O_GPIOx_DEBOUNCE_VAL     (0x8C)
#define SYSCTL_O_GPIOx_QUAL_PRDx        (0x800)
#define SYSCTL_O_QUAL_MODEx             (0x860)
#define SYSCTL_O_INPUT_INVx             (0x878)

//SYSCTL PAD
#define SYSCTL_O_GPIO_PEx               (0x600)
#define SYSCTL_O_GPIO_PSx               (0x620)
#define SYSCTL_O_GPIO_ISx               (0x640)
#define SYSCTL_O_GPIO_DRx               (0x660)
#define SYSCTL_O_GPIOC_AMSEL            (0x884)

//SYSCTL HAC
#define SYSCTL_O_HAC_LP_EN              (0x900)
#define SYSCTL_O_HAC_SRCx               (0x904)
#define SYSCTL_O_HAC_I_DSTx             (0x910)

#define OB_VALID_KEY                (0xAA5555AAU)
#define OB_VALID_KEY_O              (0x300U)

#define OB_VREF_2P5_O               (0x000U)
#define OB_VREF_1P65_O              (0x004U)

#define OB_ADCA_2P5_OFFSET_O        (0x008U)
#define OB_ADCA_1P65_OFFSET_O       (0x00CU)
#define OB_ADCB_2P5_OFFSET_O        (0x010U)
#define OB_ADCB_1P65_OFFSET_O       (0x014U)
#define OB_ADCC_2P5_OFFSET_O        (0x018U)
#define OB_ADCC_1P65_OFFSET_O       (0x01CU)

#define OB_HSI1_O               (0x310U)
#define OB_HSI2_O               (0x314U)
#define OB_VREF_O               (0x31CU)

//#define SYSCTL_INIT(offset) (*((volatile int *)(SYSCTL_BASE + offset)))

//*************************************************************************************************
//
// The following are defines for the bit fields in the MSPI register
//
//*************************************************************************************************
#define SYSCTL_MSPI_XIP_EN                      (0x1U)
#define SYSCTL_MSPI_XIP_READ_LITTLE_ENDIAN      (0x2U)
#define SYSCTL_MSPI_NONXIP_READ_LITTLE_ENDIAN   (0x4U)
#define SYSCTL_MSPI_NONXIP_WIRTE_LITTLE_ENDIAN  (0x8U)
#define SYSCTL_MSPI_CFG_CLEAR                   (0x0U)
#define SYSCTL_MSPI_IO_EN                       0x80000000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the BSPIx register
//
//*************************************************************************************************
#define SYSCTL_BSPI1_MASTER_EN                      0x14001U
#define SYSCTL_BSPI1_SLAVE_EN                       0x14000U

#define SYSCTL_BSPI2_MASTER_EN                      0x14401U
#define SYSCTL_BSPI2_SLAVE_EN                       0x14400U

#define SYSCTL_BSPI3_MASTER_EN                      0x14801U
#define SYSCTL_BSPI3_SLAVE_EN                       0x14800U

#define SYSCTL_BSPI4_MASTER_EN                      0x14C01U
#define SYSCTL_BSPI4_SLAVE_EN                       0x14C00U

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRL_SUB register
//
//*************************************************************************************************
#define SYSCTL_CTRLSUB_EPWMGBCLKSYNC                0x10000U
#define SYSCTL_CTRLSUB_EPWMCPU1TBCLKSYNC            0x20000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the CORE_NMI_WK_EN register
//
//*************************************************************************************************
#define SYSCTL_CORE1_NMI_WK_EN                      0x1U
#define SYSCTL_CORE1_NMI_WK_DIS                     0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the MATRIX4_REMAP register
//
//*************************************************************************************************
#define SYSCTL_MATRIX4_REMAP_EFLASHC                0x0U
#define SYSCTL_MATRIX4_REMAP_XFLASHC                0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEPx_CFG register
//
//*************************************************************************************************
#define SYSCTL_EQEPxa_SEL_M                         0xFU
#define SYSCTL_EQEPxb_SEL_M                         0xF0U
#define SYSCTL_EQEPxi_SEL_M                         0xF00U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAPx_CFG register
//
//*************************************************************************************************
#define SYSCTL_ECAPx_SYNCIN_M                       0x3FU

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMERx_STAT register
//
//*************************************************************************************************
#define SYSCTL_TIM1_STAT_M                      0x3U
#define SYSCTL_TIM2_STAT_M                      0xCU
#define SYSCTL_TIM3_STAT_M                      0x30U
#define SYSCTL_TIM4_STAT_M                      0xC0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWMx_SYNCIN_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_SYNCIN_SEL_M               0x7FU

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_ADC_SOCA_OUT_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_ADC_SOCA_OUT_EN            0x1U
#define SYSCTL_EPWMx_ADC_SOCA_OUT_DIS           0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_ADC_SOCB_OUT_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_ADC_SOCB_OUT_EN            0x1U
#define SYSCTL_EPWMx_ADC_SOCB_OUT_DIS           0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR0 register
//
//*************************************************************************************************
#define SYSCTL_HRPWM_CLK_EN                     0x1U
#define SYSCTL_HRPWM_CLK_DIS                    0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNC_SEL register
//
//*************************************************************************************************
#define SYSCTL_SYNCOUT_SEL_M                    0x0F000000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG register
//
//*************************************************************************************************
#define SYSCTL_WWDG_DEBUG_MODE_EN               0x1U
#define SYSCTL_WWDG_DEBUG_MODE_DIS              0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPM register
//
//*************************************************************************************************
#define SYSCTL_EXTI_WK_EN                       0x1U
#define SYSCTL_EXTI_WK_DIS                      0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DCC register
//
//*************************************************************************************************
#define SYSCTL_DCC_NMI_IRQ_EN                   0x1U
#define SYSCTL_DCC_NMI_IRQ_DIS                  0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_CTRL register
//
//*************************************************************************************************
#define SYSCTL_WWDG_DBG_STOP_EN                 0x1U
#define SYSCTL_WWDG_DBG_STOP_DIS                0x0U
#define SYSCTL_LPM_DBG_SLEEP_M                  0x4U

//*************************************************************************************************
//
// The following are defines for the bit fields in the SMCM register
//
//*************************************************************************************************
#define SYSCTL_SMCM_HWINT_EN                    0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMERx_PRESC register
//
//*************************************************************************************************
#define SYSCTL_TIMERx_CH1_PRESC_M                0xFFFFU
#define SYSCTL_TIMERx_CH2_PRESC_M                0xFFFF0000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDT_SPEED_UP register
//
//*************************************************************************************************
#define SYSCTL_WDT_SPEED_UP_EN                  0x1U
#define SYSCTL_WDT_SPEED_UP_DIS                 0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_SYNCSOC_LOCK register
//
//*************************************************************************************************
#define SYSCTL_ADC_SOCOUTSEL_LOCK               0x2U
#define SYSCTL_ADC_SOCOUTSEL_UNLOCK             0x0U
#define SYSCTL_SYNC_SEL_LOCK                    0x1U
#define SYSCTL_SYNC_SEL_UNLOCK                  0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRORSTS register
//
//*************************************************************************************************
#define SYSCTL_ERRORSTS_ERROR_M                 0x1U
#define SYSCTL_ERRORSTS_PINSTS_M                0x2U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSCLR register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSCLR_ERROR_CLR              0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSFRC register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSFRC_ERROR_SET              0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSCTL register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSCTL_ERROR_0_ELSE_1         0x0U
#define SYSCTL_ERRSTSCTL_ERROR_1_ELSE_0         0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSLOCK register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSLOCK_ERRORCTL_LOCK         0x1U
#define SYSCTL_ERRSTSLOCK_ERRORCTL_UNLOCK       0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTERNALTESTCTL register
//
//*************************************************************************************************
#define SYSCTL_INTERNALTESTCTL_TESTSEL_S   0U
#define SYSCTL_INTERNALTESTCTL_TESTSEL_M   0x1FU         // Test Select
#define SYSCTL_INTERNALTESTCTL_KEY_S       16U
#define SYSCTL_INTERNALTESTCTL_KEY_M       0xFFFF0000U   // Key to Enable writes

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONFIGLOCK register
//
//*************************************************************************************************
#define SYSCTL_CONFIGLOCK_AGPIOCTRL   0x8U   // Locks all AGPIOCTRL Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the TSNSCTL register
//
//*************************************************************************************************
#define SYSCTL_TSNSCTL_ENABLE   0x1U   // Temperature Sensor Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ANAREFCTL register
//
//*************************************************************************************************
#define SYSCTL_ANAREFCTL_ANAREFSEL                0x1U      // Analog Reference Select
#define SYSCTL_ANAREFCTL_ANAREF2P5SEL             0x100U    // Analog Reference Select
#define SYSCTL_ANAREFCTL_ANAREFSEL_SUP_OVERRIDE   0x8000U   // Control for overriding the analog
// reference with VDDA/VSSA

//*************************************************************************************************
//
// The following are defines for the bit fields in the VMONCTL register
//
//*************************************************************************************************
#define SYSCTL_VMONCTL_BORLVMONDIS   0x100U   // Disable BORL(ow) feature on VDDIO

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHPMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_S   0U
#define SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M   0x7U     // CMP1HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP2HPMXSEL_S   3U
#define SYSCTL_CMPHPMXSEL_CMP2HPMXSEL_M   0x38U    // CMP2HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP3HPMXSEL_S   6U
#define SYSCTL_CMPHPMXSEL_CMP3HPMXSEL_M   0x1C0U   // CMP3HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP4HPMXSEL_S   9U
#define SYSCTL_CMPHPMXSEL_CMP4HPMXSEL_M   0xE00U   // CMP4HPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLPMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_S   0U
#define SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M   0x7U     // CMP1LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP2LPMXSEL_S   3U
#define SYSCTL_CMPLPMXSEL_CMP2LPMXSEL_M   0x38U    // CMP2LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP3LPMXSEL_S   6U
#define SYSCTL_CMPLPMXSEL_CMP3LPMXSEL_M   0x1C0U   // CMP3LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP4LPMXSEL_S   9U
#define SYSCTL_CMPLPMXSEL_CMP4LPMXSEL_M   0xE00U   // CMP4LPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHNMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPHNMXSEL_CMP1HNMXSEL   0x1U   // CMP1HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP2HNMXSEL   0x2U   // CMP2HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP3HNMXSEL   0x4U   // CMP3HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP4HNMXSEL   0x8U   // CMP4HNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLNMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPLNMXSEL_CMP1LNMXSEL   0x1U   // CMP1LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP2LNMXSEL   0x2U   // CMP2LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP3LNMXSEL   0x4U   // CMP3LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP4LNMXSEL   0x8U   // CMP4LNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCDACLOOPBACK register
//
//*************************************************************************************************
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCA   0x1U          // Enable DACA loopback to ADCA
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCB   0x2U          // Enable DACA loopback to ADCA
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCC   0x4U          // Enable DACA loopback to ADCC
#define SYSCTL_ADCDACLOOPBACK_KEY_S       16U
#define SYSCTL_ADCDACLOOPBACK_KEY_M       0xFFFF0000U   // Key to enable writes

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSSCTL register
//
//*************************************************************************************************
#define SYSCTL_CMPSSCTL_CMP1LDACOUTEN   0x1U      // Enable general purpose DAC functionality for
// CMPSS1.COMPDACL
#define SYSCTL_CMPSSCTL_CMPSSCTLEN      0x8000U   // Enable the CMPSSCTL Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the LOCK register
//
//*************************************************************************************************
#define SYSCTL_LOCK_TSNSCTL      0x1U     // TSNSCTL Register lock bit
#define SYSCTL_LOCK_ANAREFCTL    0x2U     // ANAREFCTL Register lock bit
#define SYSCTL_LOCK_VMONCTL      0x4U     // VMONCTL Register lock bit
#define SYSCTL_LOCK_CMPHPMXSEL   0x20U    // CMPHPMXSEL Register lock bit
#define SYSCTL_LOCK_CMPLPMXSEL   0x40U    // CMPLPMXSEL Register lock bit
#define SYSCTL_LOCK_CMPHNMXSEL   0x80U    // CMPHNMXSEL Register lock bit
#define SYSCTL_LOCK_CMPLNMXSEL   0x100U   // CMPLNMXSEL Register lock bit
#define SYSCTL_LOCK_VREGCTL      0x200U   // VREGCTL Register lock bit
#define SYSCTL_LOCK_CMPSSCTL     0x400U   // CMPSSCTL Register lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOCTRLA register
//
//*************************************************************************************************
#define SYSCTL_AGPIOCTRLA_GPIO12   0x1000U       // AGPIOCTRL for GPIO12
#define SYSCTL_AGPIOCTRLA_GPIO13   0x2000U       // AGPIOCTRL for GPIO13
#define SYSCTL_AGPIOCTRLA_GPIO20   0x100000U     // AGPIOCTRL for GPIO20
#define SYSCTL_AGPIOCTRLA_GPIO21   0x200000U     // AGPIOCTRL for GPIO21
#define SYSCTL_AGPIOCTRLA_GPIO28   0x10000000U   // AGPIOCTRL for GPIO28

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOCTRLH register
//
//*************************************************************************************************
#define SYSCTL_AGPIOCTRLH_GPIO224   0x1U       // AGPIOCTRL for GPIO224
#define SYSCTL_AGPIOCTRLH_GPIO226   0x4U       // AGPIOCTRL for GPIO226
#define SYSCTL_AGPIOCTRLH_GPIO227   0x8U       // AGPIOCTRL for GPIO227
#define SYSCTL_AGPIOCTRLH_GPIO228   0x10U      // AGPIOCTRL for GPIO228
#define SYSCTL_AGPIOCTRLH_GPIO230   0x40U      // AGPIOCTRL for GPIO230
#define SYSCTL_AGPIOCTRLH_GPIO242   0x40000U   // AGPIOCTRL for GPIO242

#define CTRLSUB_BASE  0x29001180U
#define SYNC_BASE     0x29001340U

#define SYSCTL_CTRLSUB_GBCLKSYNC_S       16U
#define SYSCTL_CTRLSUB_GBCLKSYNC_M       0x10000U
#define SYSCTL_CTRLSUB_CPU1TBCLKSYNC_S   17U
#define SYSCTL_CTRLSUB_CPU1TBCLKSYNC_M   0x20000U
#define SYSCTL_CTRLSUB_CPU2TBCLKSYNC_S   18U
#define SYSCTL_CTRLSUB_CPU2TBCLKSYNC_M   0x40000U

#define SYSCTL_EPWMxSYNCINSEL_S          0U
#define SYSCTL_EPWMxSYNCINSEL_M          0x7FU

#define SYSCTL_ADCSOCxOUTSELECCT_S       0U
#define SYSCTL_ADCSOCxOUTSELECCT_M       0x7FFFFFFFU

#define SYSCTL_PCLKCR0_HRPWM_S           0U
#define SYSCTL_PCLKCR0_HRPWM_M           0x1U

#define SYSCTL_SYNCSELECT_SYNCOUT_S       24U
#define SYSCTL_SYNCSELECT_SYNCOUT_M       0x1F000000U   // Select Syncout Source

#define SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_S  0U
#define SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_M  0x1U
#define SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_S  1U
#define SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_M  0x2U
//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSELECT register
//
//*************************************************************************************************
#define SYSCTL_ADCSOC_SRC_PWM1SOCA   0x1U //!<ePWM1 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM2SOCA   0x2U //!<ePWM2 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM3SOCA   0x4U //!<ePWM3 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM4SOCA   0x8U //!<ePWM4 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM5SOCA   0x10U //!<ePWM5 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM6SOCA   0x20U //!<ePWM6 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM7SOCA   0x40U //!<ePWM7 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM8SOCA   0x80U //!<ePWM8 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM1SOCB   0x10000U //!<ePWM1 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM2SOCB   0x20000U //!<ePWM2 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM3SOCB   0x40000U //!<ePWM3 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM4SOCB   0x80000U //!<ePWM4 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM5SOCB   0x100000U //!<ePWM5 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM6SOCB   0x200000U //!<ePWM6 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM7SOCB   0x400000U //!<ePWM7 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM8SOCB   0x800000U //!<ePWM8 SOCB for ADCSOCBO

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCSOCLOCK register
//
//*************************************************************************************************
#define SYSCTL_SYNCSOCLOCK_SYNCSELECT        0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT   0x2U   // ADCSOCOUTSELECT Register Lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBGCTRL register
//
//*************************************************************************************************
#define SYSCTL_DBGCTRL_WWDG_STOP_EN             0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_SLEEP_EN             0x4U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_STOP_EN              0x8U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_STANDBY_EN           0x10U   // SYNCSEL Register Lock bit

#if EPWM_HW_VER == 0
//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncInputConfig(). Note that some of these are only valid for
//! certain values of \e syncInput. See device technical reference manual for
//! info on time-base counter synchronization for details.
//
//*****************************************************************************
typedef enum
{
    //! Disable Sync-in
    EPWM_SYNC_IN_PULSE_SRC_DISABLE = 0x0,
    //! Sync-in source is EPWM1 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1 = 0x1,
    //! Sync-in source is EPWM2 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2 = 0x2,
    //! Sync-in source is EPWM3 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3 = 0x3,
    //! Sync-in source is EPWM4 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4 = 0x4,
    //! Sync-in source is EPWM5 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5 = 0x5,
    //! Sync-in source is EPWM6 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6 = 0x6,
    //! Sync-in source is EPWM7 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7 = 0x7,
    //! Sync-in source is EPWM8 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8 = 0x8,
    //! Sync-in source is ECAP1 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1 = 0x11,
    //! Sync-in source is ECAP2 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2 = 0x12,
    //! Sync-in source is ECAP3 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3 = 0x13,
    //! Sync-in source is Input XBAR out5 signal
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5 = 0x18,
    //! Sync-in source is Input XBAR out6 signal
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6 = 0x19,
    //! Sync-in source is FSI RX trigger1 signal
    EPWM_SYNC_IN_PULSE_SRC_FSIRX_TRIG1 = 0x1F,
} EPWM_SyncInPulseSource;
#endif

//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncOutputConfig().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT = 0,   //!< EPWM1SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM2SYNCOUT = 1,
    SYSCTL_SYNC_OUT_SRC_EPWM3SYNCOUT = 2,
    SYSCTL_SYNC_OUT_SRC_EPWM4SYNCOUT = 3,
    SYSCTL_SYNC_OUT_SRC_EPWM5SYNCOUT = 4,
    SYSCTL_SYNC_OUT_SRC_EPWM6SYNCOUT = 5,
    SYSCTL_SYNC_OUT_SRC_EPWM7SYNCOUT = 6,
    SYSCTL_SYNC_OUT_SRC_EPWM8SYNCOUT = 7,
    SYSCTL_SYNC_OUT_SRC_ECAP1SYNCOUT = 24,
    SYSCTL_SYNC_OUT_SRC_ECAP2SYNCOUT = 25,
    SYSCTL_SYNC_OUT_SRC_ECAP3SYNCOUT = 26,

} SysCtl_SyncOutputSource;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_enablePeripheral()
//! and SysCtl_disablePeripheral() as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_PERIPH_CLK_HRPWM = 0x00037800,
    SYSCTL_PERIPH_CLK_TBCLKSYNC = 0x00018010,
    SYSCTL_PERIPH_CLK_CPU1TBCLKSYNC = 0x00018011,
    //AHB1
    SYSCTL_PERIPH_CLK_ERM = 0x1000301F,
    SYSCTL_PERIPH_CLK_ADC1 = 0x1000301E,
    SYSCTL_PERIPH_CLK_ADC2 = 0x1000301D,
    SYSCTL_PERIPH_CLK_ADC3 = 0x1000301C,
    SYSCTL_PERIPH_CLK_ECAP1 = 0x1000301B,
    SYSCTL_PERIPH_CLK_ECAP2 = 0x1000301A,
    SYSCTL_PERIPH_CLK_ECAP3 = 0x10003019,
    SYSCTL_PERIPH_CLK_ECAP4 = 0x10003018,
    SYSCTL_PERIPH_CLK_EQEP1 = 0x10003017,
    SYSCTL_PERIPH_CLK_EQEP2 = 0x10003016,
    SYSCTL_PERIPH_CLK_EQEP3 = 0x10003015,
    SYSCTL_PERIPH_CLK_SDFM1 = 0x10003014,
    SYSCTL_PERIPH_CLK_SDFM2 = 0x10003013,
    SYSCTL_PERIPH_CLK_CMPSS1 = 0x10003012,
    SYSCTL_PERIPH_CLK_CMPSS2 = 0x10003011,
    SYSCTL_PERIPH_CLK_CMPSS3 = 0x10003010,
    SYSCTL_PERIPH_CLK_CMPSS4 = 0x1000300F,
    SYSCTL_PERIPH_CLK_CMPSS5 = 0x1000300E,
    SYSCTL_PERIPH_CLK_CMPSS6 = 0x1000300D,
    SYSCTL_PERIPH_CLK_CMPSS7 = 0x1000300C,
    SYSCTL_PERIPH_CLK_EPWM1 = 0x1000300B,
    SYSCTL_PERIPH_CLK_EPWM2 = 0x1000300A,
    SYSCTL_PERIPH_CLK_EPWM3 = 0x10003009,
    SYSCTL_PERIPH_CLK_EPWM4 = 0x10003008,
    SYSCTL_PERIPH_CLK_EPWM5 = 0x10003007,
    SYSCTL_PERIPH_CLK_EPWM6 = 0x10003006,
    SYSCTL_PERIPH_CLK_EPWM7 = 0x10003005,
    SYSCTL_PERIPH_CLK_EPWM8 = 0x10003004,
    //AHB2
    SYSCTL_PERIPH_CLK_DACC1 = 0x1000341F,
    SYSCTL_PERIPH_CLK_DACC2 = 0x1000341E,
    SYSCTL_PERIPH_CLK_DMA1 = 0x1000341D,
    SYSCTL_PERIPH_CLK_DMA2 = 0x1000341C,
    SYSCTL_PERIPH_CLK_DMASCH = 0x1000341B,
    SYSCTL_PERIPH_CLK_SMCM = 0x1000341A,
    SYSCTL_PERIPH_CLK_XFLASHC = 0x10003417,
    SYSCTL_PERIPH_CLK_AES = 0x10003416,
    SYSCTL_PERIPH_CLK_CSPIF = 0x10003413,
    SYSCTL_PERIPH_CLK_CSPIL = 0x10003412,
    SYSCTL_PERIPH_CLK_QSPI = 0x10003411,
    SYSCTL_PERIPH_CLK_EFLASHC = 0x10003401,
    SYSCTL_PERIPH_CLK_LCM = 0x10003400,
    //APBH
    SYSCTL_PERIPH_CLK_TIMER1 = 0x1000381F,
    SYSCTL_PERIPH_CLK_TIMER2 = 0x1000381E,
    SYSCTL_PERIPH_CLK_TIMER3 = 0x1000381D,
    SYSCTL_PERIPH_CLK_TIMER4 = 0x1000381C,
    //APBL1
    SYSCTL_PERIPH_CLK_IWDT = 0x10003C1F,
    SYSCTL_PERIPH_CLK_WWDT = 0x10003C1D,
    SYSCTL_PERIPH_CLK_SYSCTL = 0x10003C1B,
    SYSCTL_PERIPH_CLK_UART1 = 0x10003C18,
    SYSCTL_PERIPH_CLK_UART2 = 0x10003C17,
    SYSCTL_PERIPH_CLK_TIMER5 = 0x10003C16,
    SYSCTL_PERIPH_CLK_TIMER6 = 0x10003C15,
    SYSCTL_PERIPH_CLK_I2C1 = 0x10003C12,
    SYSCTL_PERIPH_CLK_BSPI4 = 0x10003C11,
    SYSCTL_PERIPH_CLK_I2C2 = 0x10003C0E,
    SYSCTL_PERIPH_CLK_I2C3 = 0x10003C0D,
    SYSCTL_PERIPH_CLK_USART1 = 0x10003C0C,
    SYSCTL_PERIPH_CLK_USART2 = 0x10003C0B,
    SYSCTL_PERIPH_CLK_CANFD1 = 0x10003C0A,
    SYSCTL_PERIPH_CLK_CANFD2 = 0x10003C09,
    SYSCTL_PERIPH_CLK_BSPI1 = 0x10003C08,
    SYSCTL_PERIPH_CLK_BSPI2 = 0x10003C07,
    SYSCTL_PERIPH_CLK_BSPI3 = 0x10003C06,
    SYSCTL_PERIPH_CLK_I2C4 = 0x10003C05,
    SYSCTL_PERIPH_CLK_XBAR = 0x10003C00,
    //APBL2
    SYSCTL_PERIPH_CLK_GPIOA = 0x1000401F,
    SYSCTL_PERIPH_CLK_GPIOB = 0x1000401E,
    SYSCTL_PERIPH_CLK_GPIOC = 0x1000401D,
    SYSCTL_PERIPH_CLK_GPIOD = 0x1000401C,
    SYSCTL_PERIPH_CLK_GPIOE = 0x1000401B,
    SYSCTL_PERIPH_CLK_CLB1 = 0x1000401A,
    SYSCTL_PERIPH_CLK_CRC = 0x10004019,
    SYSCTL_PERIPH_CLK_CLB2 = 0x10004018,
    SYSCTL_PERIPH_CLK_CLB3 = 0x10004017,
    SYSCTL_PERIPH_CLK_CLB4 = 0x10004016,
} SysCtl_PeripheralPCLOCKCR;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_resetPeripheral() as
//! the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    //AHB1
    SYSCTL_PERIPH_RES_ERM = 0x10001C1F,
    SYSCTL_PERIPH_RES_ADC1 = 0x10001C1E,
    SYSCTL_PERIPH_RES_ADC2 = 0x10001C1D,
    SYSCTL_PERIPH_RES_ADC3 = 0x10001C1C,
    SYSCTL_PERIPH_RES_ECAP1 = 0x10001C1B,
    SYSCTL_PERIPH_RES_ECAP2 = 0x10001C1A,
    SYSCTL_PERIPH_RES_ECAP3 = 0x10001C19,
    SYSCTL_PERIPH_RES_ECAP4 = 0x10001C18,
    SYSCTL_PERIPH_RES_EQEP1 = 0x10001C17,
    SYSCTL_PERIPH_RES_EQEP2 = 0x10001C16,
    SYSCTL_PERIPH_RES_EQEP3 = 0x10001C15,
    SYSCTL_PERIPH_RES_SDFM1 = 0x10001C14,
    SYSCTL_PERIPH_RES_SDFM2 = 0x10001C13,
    SYSCTL_PERIPH_RES_CMPSS1 = 0x10001C12,
    SYSCTL_PERIPH_RES_CMPSS2 = 0x10001C11,
    SYSCTL_PERIPH_RES_CMPSS3 = 0x10001C10,
    SYSCTL_PERIPH_RES_CMPSS4 = 0x10001C0F,
    SYSCTL_PERIPH_RES_CMPSS5 = 0x10001C0E,
    SYSCTL_PERIPH_RES_CMPSS6 = 0x10001C0D,
    SYSCTL_PERIPH_RES_CMPSS7 = 0x10001C0C,
    SYSCTL_PERIPH_RES_EPWM1 = 0x10001C0B,
    SYSCTL_PERIPH_RES_EPWM2 = 0x10001C0A,
    SYSCTL_PERIPH_RES_EPWM3 = 0x10001C09,
    SYSCTL_PERIPH_RES_EPWM4 = 0x10001C08,
    SYSCTL_PERIPH_RES_EPWM5 = 0x10001C07,
    SYSCTL_PERIPH_RES_EPWM6 = 0x10001C06,
    SYSCTL_PERIPH_RES_EPWM7 = 0x10001C05,
    SYSCTL_PERIPH_RES_EPWM8 = 0x10001C04,
    //AHB2
    SYSCTL_PERIPH_RES_DACC1 = 0x1000201F,
    SYSCTL_PERIPH_RES_DACC2 = 0x1000201E,
    SYSCTL_PERIPH_RES_DMA1 = 0x1000201D,
    SYSCTL_PERIPH_RES_DMA2 = 0x1000201C,
    SYSCTL_PERIPH_RES_DMASCH = 0x1000201B,
    SYSCTL_PERIPH_RES_SMCM = 0x1000201A,
    SYSCTL_PERIPH_RES_XFLASHC = 0x10002017,
    SYSCTL_PERIPH_RES_AES = 0x10002016,
    SYSCTL_PERIPH_RES_CSPIF = 0x10002013,
    SYSCTL_PERIPH_RES_CSPIL = 0x10002012,
    SYSCTL_PERIPH_RES_QSPI = 0x10002011,
    SYSCTL_PERIPH_RES_EFLASHC = 0x10002001,
    SYSCTL_PERIPH_RES_LCM = 0x10002000,
    //APBH
    SYSCTL_PERIPH_RES_TIMER1 = 0x1000241F,
    SYSCTL_PERIPH_RES_TIMER2 = 0x1000241E,
    SYSCTL_PERIPH_RES_TIMER3 = 0x1000241D,
    SYSCTL_PERIPH_RES_TIMER4 = 0x1000241C,
    //APBL1
    SYSCTL_PERIPH_RES_IWDT = 0x1000281F,
    SYSCTL_PERIPH_RES_WWDT = 0x1000281D,
    SYSCTL_PERIPH_RES_SYSCTL = 0x1000281B,
    SYSCTL_PERIPH_RES_UART1 = 0x10002818,
    SYSCTL_PERIPH_RES_UART2 = 0x10002817,
    SYSCTL_PERIPH_RES_TIMER5 = 0x10002816,
    SYSCTL_PERIPH_RES_TIMER6 = 0x10002815,
    SYSCTL_PERIPH_RES_I2C3 = 0x10002812,
    SYSCTL_PERIPH_RES_BSPI4 = 0x10002811,
    SYSCTL_PERIPH_RES_I2C1 = 0x1000280E,
    SYSCTL_PERIPH_RES_I2C2 = 0x1000280D,
    SYSCTL_PERIPH_RES_USART1 = 0x1000280C,
    SYSCTL_PERIPH_RES_USART2 = 0x1000280B,
    SYSCTL_PERIPH_RES_CANFD1 = 0x1000280A,
    SYSCTL_PERIPH_RES_CANFD2 = 0x10002809,
    SYSCTL_PERIPH_RES_BSPI1 = 0x10002808,
    SYSCTL_PERIPH_RES_BSPI2 = 0x10002807,
    SYSCTL_PERIPH_RES_BSPI3 = 0x10002806,
    SYSCTL_PERIPH_RES_I2C4 = 0x10002805,
    SYSCTL_PERIPH_RES_XBAR = 0x10002800,
    //APBL2
    SYSCTL_PERIPH_RES_GPIO1 = 0x10002C1F,
    SYSCTL_PERIPH_RES_GPIO2 = 0x10002C1E,
    SYSCTL_PERIPH_RES_GPIO3 = 0x10002C1D,
    SYSCTL_PERIPH_RES_GPIO4 = 0x10002C1C,
    SYSCTL_PERIPH_RES_GPIO5 = 0x10002C1B,
    SYSCTL_PERIPH_RES_CLB1 = 0x10002C1A,
    SYSCTL_PERIPH_RES_CRC = 0x10002C19,
    SYSCTL_PERIPH_RES_CLB2 = 0x10002C18,
    SYSCTL_PERIPH_RES_CLB3 = 0x10002C17,
    SYSCTL_PERIPH_RES_CLB4 = 0x10002C16,
} SysCtl_PeripheralSOFTPRES;

//*****************************************************************************
//
// Option bytes Source
//
//*****************************************************************************
typedef enum
{
    EXFLASHC_OB = 0x00,   //!< Option bytes from SYSCTL
    SYSCTCL_OB = 0x01,   //!< Option bytes from external flash controller
} SysCtl_OBSourece;

//*****************************************************************************
//
// GPIO qualification mode
//
//*****************************************************************************
typedef enum
{
    GPIO_SYNC_PCLK = 0x0,  // Synchronous to PCLK
    GPIO_SYNC_3_SAMPLE = 0x1,  // Synchronous (3-sample window)
    GPIO_SYNC_6_SAMPLE = 0x2,  // Synchronous (6-sample window)
    GPIO_ASYNC = 0x3   // Asynchronous
} SysCtl_GPIOxQualificationMode;

//*****************************************************************************
//
// GPIO Pull up/down
//
//*****************************************************************************
typedef enum
{
    GPIOx_PULL_DOWN = 0x0, GPIOx_PULL_UP = 0x1,
} SysCtl_GPIOxUPorDOWN;

//*****************************************************************************
//
// GPIO Input Mode
//
//*****************************************************************************
typedef enum
{
    GPIOx_INPUT_SCHMITT = 0x0, GPIOx_INPUT_BUFFER = 0x1,
} SysCtl_GPIOxInputMode;

//*****************************************************************************
//
// GPIO GPIOx Drive Strength
//
//*****************************************************************************
typedef enum
{
    GPIOx_DR_5mA = 0x0,
    GPIOx_DR_15mA = 0x1,
    GPIOx_DR_20mA = 0x2,
    GPIOx_DR_41mA = 0x3,
} SysCtl_GPIOxDriveStrength;

//*****************************************************************************
//
// GPIO3 Analog Mode Select
//
//*****************************************************************************
typedef enum
{
    GPIOC_Digital_Mode = 0x0, GPIOC_Analog_Mode = 0x1,
} SysCtl_GPIOCAMSEL;

typedef enum
{
    TIMER1CH1 = 0x0,
    TIMER1CH2,
    TIMER2CH1,
    TIMER2CH2,
    TIMER3CH1,
    TIMER3CH2,
    TIMER4CH1,
    TIMER4CH2
} SysCtl_TIMERx;

#elif SYSCTL_HW_VER == 2

#define SYSCTL_PERIPH_IP_M                   0x10000000U
#define SYSCTL_PERIPH_IP_S                   28U
#define SYSCTL_PERIPH_REG_M                  0x000FFF00U
#define SYSCTL_PERIPH_REG_S                  8U
#define SYSCTL_PERIPH_BIT_M                  0x000000FFU
#define SYSCTL_PERIPH_BIT_S                  0U
/*
 * SYSCTL register offset
 */

#define SYSCTL_O_MSPI_CFG               (0x100)
#define SYSCTL_O_BSPI1_CFG              (0x140)
#define SYSCTL_O_BSPI2_CFG              (0x144)
#define SYSCTL_O_BSPI3_CFG              (0x148)
#define SYSCTL_O_BSPI4_CFG              (0x14C)
#define SYSCTL_O_CTRL_SUB               (0x180)
#define SYSCTL_O_SMCM                   (0x1C0)
#define SYSCTL_O_SMCM_HWINT             (0x1C4)
#define SYSCTL_O_SMCM_ECC_ERR           (0x1C8)

#define SYSCTL_O_CORE_NMI_WK_EN         (0x208)
#define SYSCTL_O_MATRIX4_REMAP          (0x240)
#define SYSCTL_O_EQEP1_CFG              (0x280)
#define SYSCTL_O_EQEP2_CFG              (0x284)
#define SYSCTL_O_EQEP3_CFG              (0x288)
#define SYSCTL_O_ECAP1_SYNCSEL          (0x2C0)
#define SYSCTL_O_ECAP2_SYNCSEL          (0x2C4)
#define SYSCTL_O_ECAP3_SYNCSEL          (0x2C8)
#define SYSCTL_O_ECAP4_SYNCSEL          (0x2CC)
#define SYSCTL_O_TIMERx_STAT            (0x300)

//SYSCTL timer
#define SYSCTL_O_TIM1_PRESC             (0x304)
#define SYSCTL_O_TIM2_PRESC             (0x308)
#define SYSCTL_O_TIM3_PRESC             (0x30C)
#define SYSCTL_O_TIM4_PRESC             (0x310)

#define SYSCTL_O_EPWM1_SYNCIN_SEL       (0x340)
#define SYSCTL_O_EPWM2_SYNCIN_SEL       (0x344)
#define SYSCTL_O_EPWM3_SYNCIN_SEL       (0x348)
#define SYSCTL_O_EPWM4_SYNCIN_SEL       (0x34C)
#define SYSCTL_O_EPWM5_SYNCIN_SEL       (0x350)
#define SYSCTL_O_EPWM6_SYNCIN_SEL       (0x354)
#define SYSCTL_O_EPWM7_SYNCIN_SEL       (0x358)
#define SYSCTL_O_EPWM8_SYNCIN_SEL       (0x35C)
#define SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL  (0x370)
#define SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL  (0x374)
#define SYSCTL_O_HRPWM_CLK_EN           (0x378)
#define SYSCTL_O_SYNC_SELECT            (0x37C)
#define SYSCTL_O_SYNCSOC_LOCK           (0x380)

//SYSCTL WWDG
#define SYSCTL_O_WWDG_DBG_CFG           (0x3C0)
//SYSCTL debug config
#define SYSCTL_O_DBG_CTRL               (0x3C4)

//
#define SYSCTL_O_EXTI_WK_EN             (0x400)//LPM
#define SYSCTL_O_DCC_NMI_IRQ_EN         (0x440)
//SYSCTL Analogsub
#define SYSCTL_O_INTERNAL_TEST_CTL      (0x480)
#define SYSCTL_O_CONFIG_LOCK            (0x484)
#define SYSCTL_O_TSNS_CTL               (0x488)//Tempsensor Enable
#define SYSCTL_O_ANAREF_CTL             (0x48C)//Analog reference voltage
#define SYSCTL_O_VMON_CTL               (0x490)
#define SYSCTL_O_CMPHPMX_SEL            (0x494)
#define SYSCTL_O_CMPLPMX_SEL            (0x498)
#define SYSCTL_O_CMPHNMX_SEL            (0x49C)
#define SYSCTL_O_CMPLNMX_SEL            (0x4A0)
#define SYSCTL_O_ADC_DAC_LOOP           (0x4A4)
#define SYSCTL_O_ANALOG_SUB_LOCK        (0x4A8)
#define SYSCTL_O_AGPIO_CTRLA            (0x4AC)

//SYSCTL Option Byte
#define SYSCTL_O_OB_SEL                 (0x4C0)
#define SYSCTL_O_OPTION_BYTE0           (0x4C4)
#define SYSCTL_O_OPTION_BYTE1           (0x4C8)
#define SYSCTL_O_OPTION_BYTE2           (0x4CC)
#define SYSCTL_O_OPTION_BYTE3           (0x4D0)
#define SYSCTL_O_OPTION_BYTE4           (0x4D4)
#define SYSCTL_O_OPTION_BYTE5           (0x4D8)
#define SYSCTL_O_OPTION_BYTE6           (0x4DC)
#define SYSCTL_O_OPTION_BYTE7           (0x4E0)
#define SYSCTL_O_OPTION_BYTE8           (0x4E4)
#define SYSCTL_O_OPTION_BYTE9           (0x4E8)
#define SYSCTL_O_OPTION_BYTE10          (0x4EC)
#define SYSCTL_O_OPTION_BYTE11          (0x4F0)
//SYSCTL wdg
#define SYSCTL_O_WDG_SPEED_UP           (0x500)

//SYSCTL ERR
#define SYSCTL_O_ERROR_STAT             (0x540)
#define SYSCTL_O_ERROR_STAT_CLR         (0x544)
#define SYSCTL_O_SRROR_STAT_FRC         (0x548)
#define SYSCTL_O_ERROR_CTL              (0x54C)
#define SYSCTL_O_ERROR_LOCK             (0x550)

//SYSCTL CMPSS
#define SYSCTL_O_CMPSS_CFG              (0x580)

//SYSCTL DACC
#define SYSCTL_O_DACC_CFG               (0x5C0)

//SYSCTL XFlashc
#define SYSCTL_O_XFLASHC                (0xC0)

//SYSCTL GPIO
#define SYSCTL_O_REUSEx                 (0x0)
#define SYSCTL_O_GPIOx_DEBOUNCE_VAL     (0x8C)
#define SYSCTL_O_GPIOx_QUAL_PRDx        (0x800)
#define SYSCTL_O_QUAL_MODEx             (0x860)
#define SYSCTL_O_INPUT_INVx             (0x878)

//SYSCTL PAD
#define SYSCTL_O_GPIO_PEx               (0x600)
#define SYSCTL_O_GPIO_PSx               (0x620)
#define SYSCTL_O_GPIO_ISx               (0x640)
#define SYSCTL_O_GPIO_DRx               (0x660)
#define SYSCTL_O_GPIOC_AMSEL            (0x884)

//SYSCTL HAC
#define SYSCTL_O_HAC_LP_EN              (0x900)
#define SYSCTL_O_HAC_SRCx               (0x904)
#define SYSCTL_O_HAC_I_DSTx             (0x910)

#define OB_VALID_KEY                (0xAA5555AAU)
#define OB_VALID_KEY_O              (0x300U)

#define OB_VREF_2P5_O               (0x000U)
#define OB_VREF_1P65_O              (0x004U)

#define OB_ADCA_2P5_OFFSET_O        (0x008U)
#define OB_ADCA_1P65_OFFSET_O       (0x00CU)
#define OB_ADCB_2P5_OFFSET_O        (0x010U)
#define OB_ADCB_1P65_OFFSET_O       (0x014U)
#define OB_ADCC_2P5_OFFSET_O        (0x018U)
#define OB_ADCC_1P65_OFFSET_O       (0x01CU)

#define OB_HSI1_O               (0x310U)
#define OB_HSI2_O               (0x314U)
#define OB_VREF_O               (0x31CU)

//#define SYSCTL_INIT(offset) (*((volatile int *)(SYSCTL_BASE + offset)))

//*************************************************************************************************
//
// The following are defines for the bit fields in the MSPI register
//
//*************************************************************************************************
#define SYSCTL_MSPI_XIP_EN                      (0x1U)
#define SYSCTL_MSPI_XIP_READ_LITTLE_ENDIAN      (0x2U)
#define SYSCTL_MSPI_NONXIP_READ_LITTLE_ENDIAN   (0x4U)
#define SYSCTL_MSPI_NONXIP_WIRTE_LITTLE_ENDIAN  (0x8U)
#define SYSCTL_MSPI_CFG_CLEAR                   (0x0U)
#define SYSCTL_MSPI_IO_EN                       0x80000000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the BSPIx register
//
//*************************************************************************************************
#define SYSCTL_BSPI1_MASTER_EN                      0x14001U
#define SYSCTL_BSPI1_SLAVE_EN                       0x14000U

#define SYSCTL_BSPI2_MASTER_EN                      0x14401U
#define SYSCTL_BSPI2_SLAVE_EN                       0x14400U

#define SYSCTL_BSPI3_MASTER_EN                      0x14801U
#define SYSCTL_BSPI3_SLAVE_EN                       0x14800U

#define SYSCTL_BSPI4_MASTER_EN                      0x14C01U
#define SYSCTL_BSPI4_SLAVE_EN                       0x14C00U

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRL_SUB register
//
//*************************************************************************************************
#define SYSCTL_CTRLSUB_EPWMGBCLKSYNC                0x10000U
#define SYSCTL_CTRLSUB_EPWMCPU1TBCLKSYNC            0x20000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the CORE_NMI_WK_EN register
//
//*************************************************************************************************
#define SYSCTL_CORE1_NMI_WK_EN                      0x1U
#define SYSCTL_CORE1_NMI_WK_DIS                     0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the MATRIX4_REMAP register
//
//*************************************************************************************************
#define SYSCTL_MATRIX4_REMAP_EFLASHC                0x0U
#define SYSCTL_MATRIX4_REMAP_XFLASHC                0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEPx_CFG register
//
//*************************************************************************************************
#define SYSCTL_EQEPxa_SEL_M                         0xFU
#define SYSCTL_EQEPxb_SEL_M                         0xF0U
#define SYSCTL_EQEPxi_SEL_M                         0xF00U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAPx_CFG register
//
//*************************************************************************************************
#define SYSCTL_ECAPx_SYNCIN_M                       0x3FU

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMERx_STAT register
//
//*************************************************************************************************
#define SYSCTL_TIM1_STAT_M                      0x3U
#define SYSCTL_TIM2_STAT_M                      0xCU
#define SYSCTL_TIM3_STAT_M                      0x30U
#define SYSCTL_TIM4_STAT_M                      0xC0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWMx_SYNCIN_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_SYNCIN_SEL_M               0x7FU

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_ADC_SOCA_OUT_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_ADC_SOCA_OUT_EN            0x1U
#define SYSCTL_EPWMx_ADC_SOCA_OUT_DIS           0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_ADC_SOCB_OUT_SEL register
//
//*************************************************************************************************
#define SYSCTL_EPWMx_ADC_SOCB_OUT_EN            0x1U
#define SYSCTL_EPWMx_ADC_SOCB_OUT_DIS           0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR0 register
//
//*************************************************************************************************
#define SYSCTL_HRPWM_CLK_EN                     0x1U
#define SYSCTL_HRPWM_CLK_DIS                    0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNC_SEL register
//
//*************************************************************************************************
#define SYSCTL_SYNCOUT_SEL_M                    0x0F000000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG register
//
//*************************************************************************************************
#define SYSCTL_WWDG_DEBUG_MODE_EN               0x1U
#define SYSCTL_WWDG_DEBUG_MODE_DIS              0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPM register
//
//*************************************************************************************************
#define SYSCTL_EXTI_WK_EN                       0x1U
#define SYSCTL_EXTI_WK_DIS                      0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DCC register
//
//*************************************************************************************************
#define SYSCTL_DCC_NMI_IRQ_EN                   0x1U
#define SYSCTL_DCC_NMI_IRQ_DIS                  0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_CTRL register
//
//*************************************************************************************************
#define SYSCTL_WWDG_DBG_STOP_EN                 0x1U
#define SYSCTL_WWDG_DBG_STOP_DIS                0x0U
#define SYSCTL_LPM_DBG_SLEEP_M                  0x4U

//*************************************************************************************************
//
// The following are defines for the bit fields in the SMCM register
//
//*************************************************************************************************
#define SYSCTL_SMCM_HWINT_EN                    0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMERx_PRESC register
//
//*************************************************************************************************
#define SYSCTL_TIMERx_CH1_PRESC_M               0xFFFFU
#define SYSCTL_TIMERx_CH2_PRESC_M               0xFFFF0000U

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDT_SPEED_UP register
//
//*************************************************************************************************
#define SYSCTL_WDT_SPEED_UP_EN                  0x1U
#define SYSCTL_WDT_SPEED_UP_DIS                 0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM_SYNCSOC_LOCK register
//
//*************************************************************************************************
#define SYSCTL_ADC_SOCOUTSEL_LOCK               0x2U
#define SYSCTL_ADC_SOCOUTSEL_UNLOCK             0x0U
#define SYSCTL_SYNC_SEL_LOCK                    0x1U
#define SYSCTL_SYNC_SEL_UNLOCK                  0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRORSTS register
//
//*************************************************************************************************
#define SYSCTL_ERRORSTS_ERROR_M                 0x1U
#define SYSCTL_ERRORSTS_PINSTS_M                0x2U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSCLR register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSCLR_ERROR_CLR              0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSFRC register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSFRC_ERROR_SET              0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSCTL register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSCTL_ERROR_0_ELSE_1         0x0U
#define SYSCTL_ERRSTSCTL_ERROR_1_ELSE_0         0x1U

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRSTSLOCK register
//
//*************************************************************************************************
#define SYSCTL_ERRSTSLOCK_ERRORCTL_LOCK         0x1U
#define SYSCTL_ERRSTSLOCK_ERRORCTL_UNLOCK       0x0U

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTERNALTESTCTL register
//
//*************************************************************************************************
#define SYSCTL_INTERNALTESTCTL_TESTSEL_S   0U
#define SYSCTL_INTERNALTESTCTL_TESTSEL_M   0x1FU         // Test Select
#define SYSCTL_INTERNALTESTCTL_KEY_S       16U
#define SYSCTL_INTERNALTESTCTL_KEY_M       0xFFFF0000U   // Key to Enable writes

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONFIGLOCK register
//
//*************************************************************************************************
#define SYSCTL_CONFIGLOCK_AGPIOCTRL   0x8U   // Locks all AGPIOCTRL Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the TSNSCTL register
//
//*************************************************************************************************
#define SYSCTL_TSNSCTL_ENABLE   0x1U   // Temperature Sensor Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ANAREFCTL register
//
//*************************************************************************************************
#define SYSCTL_ANAREFCTL_ANAREFSEL                0x1U      // Analog Reference Select
#define SYSCTL_ANAREFCTL_ANAREF2P5SEL             0x100U    // Analog Reference Select
#define SYSCTL_ANAREFCTL_ANAREFSEL_SUP_OVERRIDE   0x8000U   // Control for overriding the analog
// reference with VDDA/VSSA

//*************************************************************************************************
//
// The following are defines for the bit fields in the VMONCTL register
//
//*************************************************************************************************
#define SYSCTL_VMONCTL_BORLVMONDIS   0x100U   // Disable BORL(ow) feature on VDDIO

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHPMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_S   0U
#define SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M   0x7U     // CMP1HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP2HPMXSEL_S   3U
#define SYSCTL_CMPHPMXSEL_CMP2HPMXSEL_M   0x38U    // CMP2HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP3HPMXSEL_S   6U
#define SYSCTL_CMPHPMXSEL_CMP3HPMXSEL_M   0x1C0U   // CMP3HPMXSEL bits
#define SYSCTL_CMPHPMXSEL_CMP4HPMXSEL_S   9U
#define SYSCTL_CMPHPMXSEL_CMP4HPMXSEL_M   0xE00U   // CMP4HPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLPMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_S   0U
#define SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M   0x7U     // CMP1LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP2LPMXSEL_S   3U
#define SYSCTL_CMPLPMXSEL_CMP2LPMXSEL_M   0x38U    // CMP2LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP3LPMXSEL_S   6U
#define SYSCTL_CMPLPMXSEL_CMP3LPMXSEL_M   0x1C0U   // CMP3LPMXSEL bits
#define SYSCTL_CMPLPMXSEL_CMP4LPMXSEL_S   9U
#define SYSCTL_CMPLPMXSEL_CMP4LPMXSEL_M   0xE00U   // CMP4LPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHNMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPHNMXSEL_CMP1HNMXSEL   0x1U   // CMP1HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP2HNMXSEL   0x2U   // CMP2HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP3HNMXSEL   0x4U   // CMP3HNMXSEL bits
#define SYSCTL_CMPHNMXSEL_CMP4HNMXSEL   0x8U   // CMP4HNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLNMXSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPLNMXSEL_CMP1LNMXSEL   0x1U   // CMP1LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP2LNMXSEL   0x2U   // CMP2LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP3LNMXSEL   0x4U   // CMP3LNMXSEL bits
#define SYSCTL_CMPLNMXSEL_CMP4LNMXSEL   0x8U   // CMP4LNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCDACLOOPBACK register
//
//*************************************************************************************************
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCA   0x1U          // Enable DACA loopback to ADCA
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCB   0x2U          // Enable DACA loopback to ADCA
#define SYSCTL_ADCDACLOOPBACK_ENLB2ADCC   0x4U          // Enable DACA loopback to ADCC
#define SYSCTL_ADCDACLOOPBACK_KEY_S       16U
#define SYSCTL_ADCDACLOOPBACK_KEY_M       0xFFFF0000U   // Key to enable writes

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSSCTL register
//
//*************************************************************************************************
#define SYSCTL_CMPSSCTL_CMP1LDACOUTEN   0x1U      // Enable general purpose DAC functionality for
// CMPSS1.COMPDACL
#define SYSCTL_CMPSSCTL_CMPSSCTLEN      0x8000U   // Enable the CMPSSCTL Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the LOCK register
//
//*************************************************************************************************
#define SYSCTL_LOCK_TSNSCTL      0x1U     // TSNSCTL Register lock bit
#define SYSCTL_LOCK_ANAREFCTL    0x2U     // ANAREFCTL Register lock bit
#define SYSCTL_LOCK_VMONCTL      0x4U     // VMONCTL Register lock bit
#define SYSCTL_LOCK_CMPHPMXSEL   0x20U    // CMPHPMXSEL Register lock bit
#define SYSCTL_LOCK_CMPLPMXSEL   0x40U    // CMPLPMXSEL Register lock bit
#define SYSCTL_LOCK_CMPHNMXSEL   0x80U    // CMPHNMXSEL Register lock bit
#define SYSCTL_LOCK_CMPLNMXSEL   0x100U   // CMPLNMXSEL Register lock bit
#define SYSCTL_LOCK_VREGCTL      0x200U   // VREGCTL Register lock bit
#define SYSCTL_LOCK_CMPSSCTL     0x400U   // CMPSSCTL Register lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOCTRLA register
//
//*************************************************************************************************
#define SYSCTL_AGPIOCTRLA_GPIO12   0x1000U       // AGPIOCTRL for GPIO12
#define SYSCTL_AGPIOCTRLA_GPIO13   0x2000U       // AGPIOCTRL for GPIO13
#define SYSCTL_AGPIOCTRLA_GPIO20   0x100000U     // AGPIOCTRL for GPIO20
#define SYSCTL_AGPIOCTRLA_GPIO21   0x200000U     // AGPIOCTRL for GPIO21
#define SYSCTL_AGPIOCTRLA_GPIO28   0x10000000U   // AGPIOCTRL for GPIO28

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOCTRLH register
//
//*************************************************************************************************
#define SYSCTL_AGPIOCTRLH_GPIO224   0x1U       // AGPIOCTRL for GPIO224
#define SYSCTL_AGPIOCTRLH_GPIO226   0x4U       // AGPIOCTRL for GPIO226
#define SYSCTL_AGPIOCTRLH_GPIO227   0x8U       // AGPIOCTRL for GPIO227
#define SYSCTL_AGPIOCTRLH_GPIO228   0x10U      // AGPIOCTRL for GPIO228
#define SYSCTL_AGPIOCTRLH_GPIO230   0x40U      // AGPIOCTRL for GPIO230
#define SYSCTL_AGPIOCTRLH_GPIO242   0x40000U   // AGPIOCTRL for GPIO242

#define CTRLSUB_BASE  0x29001180U
#define SYNC_BASE     0x29001340U

#define SYSCTL_CTRLSUB_GBCLKSYNC_S       16U
#define SYSCTL_CTRLSUB_GBCLKSYNC_M       0x10000U
#define SYSCTL_CTRLSUB_CPU1TBCLKSYNC_S   17U
#define SYSCTL_CTRLSUB_CPU1TBCLKSYNC_M   0x20000U
#define SYSCTL_CTRLSUB_CPU2TBCLKSYNC_S   18U
#define SYSCTL_CTRLSUB_CPU2TBCLKSYNC_M   0x40000U

#define SYSCTL_EPWMxSYNCINSEL_S          0U
#define SYSCTL_EPWMxSYNCINSEL_M          0x7FU

#define SYSCTL_ADCSOCxOUTSELECCT_S       0U
#define SYSCTL_ADCSOCxOUTSELECCT_M       0x7FFFFFFFU

#define SYSCTL_PCLKCR0_HRPWM_S           0U
#define SYSCTL_PCLKCR0_HRPWM_M           0x1U

#define SYSCTL_SYNCSELECT_SYNCOUT_S       24U
#define SYSCTL_SYNCSELECT_SYNCOUT_M       0x1F000000U   // Select Syncout Source

#define SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_S  0U
#define SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_M  0x1U
#define SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_S  1U
#define SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_M  0x2U
//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSELECT register
//
//*************************************************************************************************
#define SYSCTL_ADCSOC_SRC_PWM1SOCA   0x1U //!<ePWM1 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM2SOCA   0x2U //!<ePWM2 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM3SOCA   0x4U //!<ePWM3 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM4SOCA   0x8U //!<ePWM4 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM5SOCA   0x10U //!<ePWM5 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM6SOCA   0x20U //!<ePWM6 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM7SOCA   0x40U //!<ePWM7 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM8SOCA   0x80U //!<ePWM8 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM1SOCB   0x10000U //!<ePWM1 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM2SOCB   0x20000U //!<ePWM2 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM3SOCB   0x40000U //!<ePWM3 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM4SOCB   0x80000U //!<ePWM4 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM5SOCB   0x100000U //!<ePWM5 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM6SOCB   0x200000U //!<ePWM6 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM7SOCB   0x400000U //!<ePWM7 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM8SOCB   0x800000U //!<ePWM8 SOCB for ADCSOCBO

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCSOCLOCK register
//
//*************************************************************************************************
#define SYSCTL_SYNCSOCLOCK_SYNCSELECT        0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT   0x2U   // ADCSOCOUTSELECT Register Lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBGCTRL register
//
//*************************************************************************************************
#define SYSCTL_DBGCTRL_WWDG_STOP_EN             0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_SLEEP_EN             0x4U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_STOP_EN              0x8U   // SYNCSEL Register Lock bit
#define SYSCTL_DBGCTRL_LPM_STANDBY_EN           0x10U   // SYNCSEL Register Lock bit

#if EPWM_HW_VER == 0
//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncInputConfig(). Note that some of these are only valid for
//! certain values of \e syncInput. See device technical reference manual for
//! info on time-base counter synchronization for details.
//
//*****************************************************************************
typedef enum
{
    //! Disable Sync-in
    EPWM_SYNC_IN_PULSE_SRC_DISABLE = 0x0,
    //! Sync-in source is EPWM1 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1 = 0x1,
    //! Sync-in source is EPWM2 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2 = 0x2,
    //! Sync-in source is EPWM3 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3 = 0x3,
    //! Sync-in source is EPWM4 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4 = 0x4,
    //! Sync-in source is EPWM5 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5 = 0x5,
    //! Sync-in source is EPWM6 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6 = 0x6,
    //! Sync-in source is EPWM7 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7 = 0x7,
    //! Sync-in source is EPWM8 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8 = 0x8,
    //! Sync-in source is ECAP1 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1 = 0x11,
    //! Sync-in source is ECAP2 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2 = 0x12,
    //! Sync-in source is ECAP3 sync-out signal
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3 = 0x13,
    //! Sync-in source is Input XBAR out5 signal
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5 = 0x18,
    //! Sync-in source is Input XBAR out6 signal
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6 = 0x19,
    //! Sync-in source is FSI RX trigger1 signal
    EPWM_SYNC_IN_PULSE_SRC_FSIRX_TRIG1 = 0x1F,
} EPWM_SyncInPulseSource;
#endif

//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncOutputConfig().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT = 0,   //!< EPWM1SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM2SYNCOUT = 1,
    SYSCTL_SYNC_OUT_SRC_EPWM3SYNCOUT = 2,
    SYSCTL_SYNC_OUT_SRC_EPWM4SYNCOUT = 3,
    SYSCTL_SYNC_OUT_SRC_EPWM5SYNCOUT = 4,
    SYSCTL_SYNC_OUT_SRC_EPWM6SYNCOUT = 5,
    SYSCTL_SYNC_OUT_SRC_EPWM7SYNCOUT = 6,
    SYSCTL_SYNC_OUT_SRC_EPWM8SYNCOUT = 7,
    SYSCTL_SYNC_OUT_SRC_ECAP1SYNCOUT = 24,
    SYSCTL_SYNC_OUT_SRC_ECAP2SYNCOUT = 25,
    SYSCTL_SYNC_OUT_SRC_ECAP3SYNCOUT = 26,

} SysCtl_SyncOutputSource;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_enablePeripheral()
//! and SysCtl_disablePeripheral() as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_PERIPH_CLK_HRPWM = 0x00037800,
    SYSCTL_PERIPH_CLK_TBCLKSYNC = 0x00018010,
    SYSCTL_PERIPH_CLK_CPU1TBCLKSYNC = 0x00018011,
    //AHB1
    SYSCTL_PERIPH_CLK_ERM = 0x1000301F,
    SYSCTL_PERIPH_CLK_ADC1 = 0x1000301E,
    SYSCTL_PERIPH_CLK_ADC2 = 0x1000301D,
    SYSCTL_PERIPH_CLK_ADC3 = 0x1000301C,
    SYSCTL_PERIPH_CLK_ECAP1 = 0x1000301B,
    SYSCTL_PERIPH_CLK_ECAP2 = 0x1000301A,
    SYSCTL_PERIPH_CLK_ECAP3 = 0x10003019,
    SYSCTL_PERIPH_CLK_ECAP4 = 0x10003018,
    SYSCTL_PERIPH_CLK_EQEP1 = 0x10003017,
    SYSCTL_PERIPH_CLK_EQEP2 = 0x10003016,
    SYSCTL_PERIPH_CLK_EQEP3 = 0x10003015,
    SYSCTL_PERIPH_CLK_SDFM1 = 0x10003014,
    SYSCTL_PERIPH_CLK_SDFM2 = 0x10003013,
    SYSCTL_PERIPH_CLK_CMPSS1 = 0x10003012,
    SYSCTL_PERIPH_CLK_CMPSS2 = 0x10003011,
    SYSCTL_PERIPH_CLK_CMPSS3 = 0x10003010,
    SYSCTL_PERIPH_CLK_CMPSS4 = 0x1000300F,
    SYSCTL_PERIPH_CLK_CMPSS5 = 0x1000300E,
    SYSCTL_PERIPH_CLK_CMPSS6 = 0x1000300D,
    SYSCTL_PERIPH_CLK_CMPSS7 = 0x1000300C,
    SYSCTL_PERIPH_CLK_EPWM1 = 0x1000300B,
    SYSCTL_PERIPH_CLK_EPWM2 = 0x1000300A,
    SYSCTL_PERIPH_CLK_EPWM3 = 0x10003009,
    SYSCTL_PERIPH_CLK_EPWM4 = 0x10003008,
    SYSCTL_PERIPH_CLK_EPWM5 = 0x10003007,
    SYSCTL_PERIPH_CLK_EPWM6 = 0x10003006,
    SYSCTL_PERIPH_CLK_EPWM7 = 0x10003005,
    SYSCTL_PERIPH_CLK_EPWM8 = 0x10003004,
    //AHB2
    SYSCTL_PERIPH_CLK_DACC1 = 0x1000341F,
    SYSCTL_PERIPH_CLK_DACC2 = 0x1000341E,
    SYSCTL_PERIPH_CLK_DMA1 = 0x1000341D,
    SYSCTL_PERIPH_CLK_DMA2 = 0x1000341C,
    SYSCTL_PERIPH_CLK_DMASCH = 0x1000341B,
    SYSCTL_PERIPH_CLK_SMCM = 0x1000341A,
    SYSCTL_PERIPH_CLK_XFLASHC = 0x10003417,
    SYSCTL_PERIPH_CLK_AES = 0x10003416,
    SYSCTL_PERIPH_CLK_CSPIF = 0x10003413,
    SYSCTL_PERIPH_CLK_CSPIL = 0x10003412,
    SYSCTL_PERIPH_CLK_QSPI = 0x10003411,
    SYSCTL_PERIPH_CLK_EFLASHC = 0x10003401,
    SYSCTL_PERIPH_CLK_LCM = 0x10003400,
    //APBH
    SYSCTL_PERIPH_CLK_TIMER1 = 0x1000381F,
    SYSCTL_PERIPH_CLK_TIMER2 = 0x1000381E,
    SYSCTL_PERIPH_CLK_TIMER3 = 0x1000381D,
    SYSCTL_PERIPH_CLK_TIMER4 = 0x1000381C,
    //APBL1
    SYSCTL_PERIPH_CLK_IWDT = 0x10003C1F,
    SYSCTL_PERIPH_CLK_WWDT = 0x10003C1D,
    SYSCTL_PERIPH_CLK_SYSCTL = 0x10003C1B,
    SYSCTL_PERIPH_CLK_UART1 = 0x10003C18,
    SYSCTL_PERIPH_CLK_UART2 = 0x10003C17,
    SYSCTL_PERIPH_CLK_TIMER5 = 0x10003C16,
    SYSCTL_PERIPH_CLK_TIMER6 = 0x10003C15,
    SYSCTL_PERIPH_CLK_I2C1 = 0x10003C12,
    SYSCTL_PERIPH_CLK_BSPI4 = 0x10003C11,
    SYSCTL_PERIPH_CLK_I2C2 = 0x10003C0E,
    SYSCTL_PERIPH_CLK_I2C3 = 0x10003C0D,
    SYSCTL_PERIPH_CLK_USART1 = 0x10003C0C,
    SYSCTL_PERIPH_CLK_USART2 = 0x10003C0B,
    SYSCTL_PERIPH_CLK_CANFD1 = 0x10003C0A,
    SYSCTL_PERIPH_CLK_CANFD2 = 0x10003C09,
    SYSCTL_PERIPH_CLK_BSPI1 = 0x10003C08,
    SYSCTL_PERIPH_CLK_BSPI2 = 0x10003C07,
    SYSCTL_PERIPH_CLK_BSPI3 = 0x10003C06,
    SYSCTL_PERIPH_CLK_I2C4 = 0x10003C05,
    SYSCTL_PERIPH_CLK_XBAR = 0x10003C00,
    //APBL2
    SYSCTL_PERIPH_CLK_GPIOA = 0x1000401F,
    SYSCTL_PERIPH_CLK_GPIOB = 0x1000401E,
    SYSCTL_PERIPH_CLK_GPIOC = 0x1000401D,
    SYSCTL_PERIPH_CLK_GPIOD = 0x1000401C,
    SYSCTL_PERIPH_CLK_GPIOE = 0x1000401B,
    SYSCTL_PERIPH_CLK_CLB1 = 0x1000401A,
    SYSCTL_PERIPH_CLK_CRC = 0x10004019,
    SYSCTL_PERIPH_CLK_CLB2 = 0x10004018,
    SYSCTL_PERIPH_CLK_CLB3 = 0x10004017,
    SYSCTL_PERIPH_CLK_CLB4 = 0x10004016,
} SysCtl_PeripheralPCLOCKCR;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_resetPeripheral() as
//! the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    //AHB1
    SYSCTL_PERIPH_RES_ERM = 0x10001C1F,
    SYSCTL_PERIPH_RES_ADC1 = 0x10001C1E,
    SYSCTL_PERIPH_RES_ADC2 = 0x10001C1D,
    SYSCTL_PERIPH_RES_ADC3 = 0x10001C1C,
    SYSCTL_PERIPH_RES_ECAP1 = 0x10001C1B,
    SYSCTL_PERIPH_RES_ECAP2 = 0x10001C1A,
    SYSCTL_PERIPH_RES_ECAP3 = 0x10001C19,
    SYSCTL_PERIPH_RES_ECAP4 = 0x10001C18,
    SYSCTL_PERIPH_RES_EQEP1 = 0x10001C17,
    SYSCTL_PERIPH_RES_EQEP2 = 0x10001C16,
    SYSCTL_PERIPH_RES_EQEP3 = 0x10001C15,
    SYSCTL_PERIPH_RES_SDFM1 = 0x10001C14,
    SYSCTL_PERIPH_RES_SDFM2 = 0x10001C13,
    SYSCTL_PERIPH_RES_CMPSS1 = 0x10001C12,
    SYSCTL_PERIPH_RES_CMPSS2 = 0x10001C11,
    SYSCTL_PERIPH_RES_CMPSS3 = 0x10001C10,
    SYSCTL_PERIPH_RES_CMPSS4 = 0x10001C0F,
    SYSCTL_PERIPH_RES_CMPSS5 = 0x10001C0E,
    SYSCTL_PERIPH_RES_CMPSS6 = 0x10001C0D,
    SYSCTL_PERIPH_RES_CMPSS7 = 0x10001C0C,
    SYSCTL_PERIPH_RES_EPWM1 = 0x10001C0B,
    SYSCTL_PERIPH_RES_EPWM2 = 0x10001C0A,
    SYSCTL_PERIPH_RES_EPWM3 = 0x10001C09,
    SYSCTL_PERIPH_RES_EPWM4 = 0x10001C08,
    SYSCTL_PERIPH_RES_EPWM5 = 0x10001C07,
    SYSCTL_PERIPH_RES_EPWM6 = 0x10001C06,
    SYSCTL_PERIPH_RES_EPWM7 = 0x10001C05,
    SYSCTL_PERIPH_RES_EPWM8 = 0x10001C04,
    //AHB2
    SYSCTL_PERIPH_RES_DACC1 = 0x1000201F,
    SYSCTL_PERIPH_RES_DACC2 = 0x1000201E,
    SYSCTL_PERIPH_RES_DMA1 = 0x1000201D,
    SYSCTL_PERIPH_RES_DMA2 = 0x1000201C,
    SYSCTL_PERIPH_RES_DMASCH = 0x1000201B,
    SYSCTL_PERIPH_RES_SMCM = 0x1000201A,
    SYSCTL_PERIPH_RES_XFLASHC = 0x10002017,
    SYSCTL_PERIPH_RES_AES = 0x10002016,
    SYSCTL_PERIPH_RES_CSPIF = 0x10002013,
    SYSCTL_PERIPH_RES_CSPIL = 0x10002012,
    SYSCTL_PERIPH_RES_QSPI = 0x10002011,
    SYSCTL_PERIPH_RES_EFLASHC = 0x10002001,
    SYSCTL_PERIPH_RES_LCM = 0x10002000,
    //APBH
    SYSCTL_PERIPH_RES_TIMER1 = 0x1000241F,
    SYSCTL_PERIPH_RES_TIMER2 = 0x1000241E,
    SYSCTL_PERIPH_RES_TIMER3 = 0x1000241D,
    SYSCTL_PERIPH_RES_TIMER4 = 0x1000241C,
    //APBL1
    SYSCTL_PERIPH_RES_IWDT = 0x1000281F,
    SYSCTL_PERIPH_RES_WWDT = 0x1000281D,
    SYSCTL_PERIPH_RES_SYSCTL = 0x1000281B,
    SYSCTL_PERIPH_RES_UART1 = 0x10002818,
    SYSCTL_PERIPH_RES_UART2 = 0x10002817,
    SYSCTL_PERIPH_RES_TIMER5 = 0x10002816,
    SYSCTL_PERIPH_RES_TIMER6 = 0x10002815,
    SYSCTL_PERIPH_RES_I2C3 = 0x10002812,
    SYSCTL_PERIPH_RES_BSPI4 = 0x10002811,
    SYSCTL_PERIPH_RES_I2C1 = 0x1000280E,
    SYSCTL_PERIPH_RES_I2C2 = 0x1000280D,
    SYSCTL_PERIPH_RES_USART1 = 0x1000280C,
    SYSCTL_PERIPH_RES_USART2 = 0x1000280B,
    SYSCTL_PERIPH_RES_CANFD1 = 0x1000280A,
    SYSCTL_PERIPH_RES_CANFD2 = 0x10002809,
    SYSCTL_PERIPH_RES_BSPI1 = 0x10002808,
    SYSCTL_PERIPH_RES_BSPI2 = 0x10002807,
    SYSCTL_PERIPH_RES_BSPI3 = 0x10002806,
    SYSCTL_PERIPH_RES_I2C4 = 0x10002805,
    SYSCTL_PERIPH_RES_XBAR = 0x10002800,
    //APBL2
    SYSCTL_PERIPH_RES_GPIO1 = 0x10002C1F,
    SYSCTL_PERIPH_RES_GPIO2 = 0x10002C1E,
    SYSCTL_PERIPH_RES_GPIO3 = 0x10002C1D,
    SYSCTL_PERIPH_RES_GPIO4 = 0x10002C1C,
    SYSCTL_PERIPH_RES_GPIO5 = 0x10002C1B,
    SYSCTL_PERIPH_RES_CLB1 = 0x10002C1A,
    SYSCTL_PERIPH_RES_CRC = 0x10002C19,
    SYSCTL_PERIPH_RES_CLB2 = 0x10002C18,
    SYSCTL_PERIPH_RES_CLB3 = 0x10002C17,
    SYSCTL_PERIPH_RES_CLB4 = 0x10002C16,
} SysCtl_PeripheralSOFTPRES;

//*****************************************************************************
//
// Option bytes Source
//
//*****************************************************************************
typedef enum
{
    EXFLASHC_OB = 0x00,   //!< Option bytes from SYSCTL
    SYSCTCL_OB = 0x01,   //!< Option bytes from external flash controller
} SysCtl_OBSourece;

//*****************************************************************************
//
// GPIO qualification mode
//
//*****************************************************************************
typedef enum
{
    GPIO_SYNC_PCLK = 0x0,  // Synchronous to PCLK
    GPIO_SYNC_3_SAMPLE = 0x1,  // Synchronous (3-sample window)
    GPIO_SYNC_6_SAMPLE = 0x2,  // Synchronous (6-sample window)
    GPIO_ASYNC = 0x3   // Asynchronous
} SysCtl_GPIOxQualificationMode;

//*****************************************************************************
//
// GPIO Pull up/down
//
//*****************************************************************************
typedef enum
{
    GPIOx_PULL_DOWN = 0x0, GPIOx_PULL_UP = 0x1,
} SysCtl_GPIOxUPorDOWN;

//*****************************************************************************
//
// GPIO Input Mode
//
//*****************************************************************************
typedef enum
{
    GPIOx_INPUT_SCHMITT = 0x0, GPIOx_INPUT_BUFFER = 0x1,
} SysCtl_GPIOxInputMode;

//*****************************************************************************
//
// GPIO GPIOx Drive Strength
//
//*****************************************************************************
typedef enum
{
    GPIOx_DR_5mA = 0x0,
    GPIOx_DR_15mA = 0x1,
    GPIOx_DR_20mA = 0x2,
    GPIOx_DR_41mA = 0x3,
} SysCtl_GPIOxDriveStrength;

//*****************************************************************************
//
// GPIO3 Analog Mode Select
//
//*****************************************************************************
typedef enum
{
    GPIOC_Digital_Mode = 0x0, GPIOC_Analog_Mode = 0x1,
} SysCtl_GPIOCAMSEL;

typedef enum
{
    TIMER1CH1 = 0x0,
    TIMER1CH2,
    TIMER2CH1,
    TIMER2CH2,
    TIMER3CH1,
    TIMER3CH2,
    TIMER4CH1,
    TIMER4CH2
} SysCtl_TIMERx;

#endif

#endif /* __HW_SYSCTL_H_ */
