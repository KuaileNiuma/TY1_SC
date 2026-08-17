/**
 *************************************************************************************
 * @file hw_mmap.h
 * @brief This file contains the definition of memory map.
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


#ifndef __ALB32R003X_MMAP_H
#define __ALB32R003X_MMAP_H

#ifdef __cplusplus
extern "C"{
#endif

#define ILM_BASE              (0x02000000U) /*!< ILM  base address */
#define ILM_END               (0x0201FFFFU) /*!< ILM  end  address */
#define DLM_BASE              (0x03000000U) /*!< DLM  base address */
#define DLM_END               (0x0301FFFFU) /*!< DLM  end  address */
#define SRAM_BASE             (0x18000000U) /*!< SRAM base address */
#define SRAM_END              (0x1806FFFFU) /*!< SRAM end  address */

#define EFLASHC_BASE          (0x23000000U)
#define EFLASH_BASE           (0x0FF70000U)
#define EFLASH_END            (0x0FFBFFFFU)

#define XFLASHC_BASE          (0x23008000U)
#define XFLASH_NOWAIT_BASE    (0x0FFF0000U)
#define XFLASH_NOWAIT_END     (0x0FFFFFFFU)
#define XFLASH_BASE           (0x0FFF0000U)
#define XFLASH_END            (0x10770000U)
#define XFLASH_OB_BASE        (0x1FFE0000U)
#define XFLASH_OB_END         (0x1FFFFFFFU)

#define QXIP_BASE             (0x30000000U)
#define QXIP_END              (0x5FFFFFFFU)

#define ROM1_BASE             (0x00000000U)
#define ROM1_END              (0x0001FFFFU)
#define ROM1D_BASE            (0x2F000000U)
#define ROM1D_END             (0x2F1FFFFFU)

#define OB_BASE               (0x1FFF7800U) /*!< Option byte Base address >*/
#define SRAM_BB_BASE          (4000000000U) /*!< SRAM base address in the bit-band region */

#define HAC_BASE              (0x60000000U) /*!< HAC Remap base address */

/* CPU TCIP base addr */
#define ROM_R_BASE            (0x001FF000U)
#define SPL_BASE              (0x0D000000U)

#define PERIPH_BASE           (0x20000000U) /*!< Peripheral base address in the alias region */
#define PERIPH_BB_BASE        (0x42000000U) /*!< Peripheral base address in the bit-band region */

#define QSPI_BASE             (0x20000000U)
#define CSPI_BASE             (0x20001000U)

#define ADCA_BASE              (0x20800100U)
#define ADCB_BASE              (0x20800300U)
#define ADCC_BASE              (0x20800500U)
#define ADCARESULT_BASE        (0x20800000U)
#define ADCBRESULT_BASE        (0x20800200U)
#define ADCCRESULT_BASE        (0x20800400U)

#define ECAP1_BASE            (0x21020000U)
#define ECAP2_BASE            (0x21020400U)
#define ECAP3_BASE            (0x21020800U)
#define ECAP3_HR_BASE         (0x21020840U)

#define CMPSS1_BASE           (0x21030000U)
#define CMPSS2_BASE           (0x21030400U)
#define CMPSS3_BASE           (0x21030800U)
#define CMPSS4_BASE           (0x21030C00U)

#define DACC1_BASE            (0x21040000U)
#define DACC2_BASE            (0x21040400U)

#define AES_BASE              (0x22000000U)
#define CANFD1_BASE           (0x22001000U)
#define CANFD2_BASE           (0x22002000U)
#define CLB_BASE              (0x22003000U)  // FIXME: TBD

// AHB1
#define EFLASHC_R_BASE        (0x23000000U)
#define DMAC1_BASE            (0x23002000U)
#define DMAC2_BASE            (0x23003000U)
#define DMASCH_BASE           (0x23004000U)
#define MBX1_BASE             (0x23005000U)
#define EPG_BASE              (0x23006000U)
#define MBX2_BASE             (0x23007000U)
#define XFLASHC_R_BASE        (0x23008000U)
#define SMCM_R_BASE           (0x23009000U)

// Local APB
#define TIMER1_BASE            (0x24000000U)
#define TIMER2_BASE            (0x24001000U)
#define TIMER3_BASE            (0x24002000U)
#define TIMER4_BASE            (0x24003000U)
#define RCC_BASE               (0x24004000U)

// AHB XBar
#define XBAR_BASE             (0x25000000U)  // FIXME: TBD
#define INPUTXBAR_BASE        (0x25010000U)
#define CLBINPUTXBAR_BASE     (0x25011000U)
#define EPWMXBAR_BASE         (0x25012000U)
#define CLBXBAR_BASE          (0x25013000U)
#define OUTPUTXBAR_BASE       (0x25014000U)

// APB XBar
#define GPIO1_BASE            (0x25000000U)
#define GPIO2_BASE            (0x25001000U)
#define GPIO3_BASE            (0x25007000U)
#define GPIO4_BASE            (0x25008000U)
#define GPIO5_BASE            (0x25009000U)

// APB1
#define SPI1_BASE             (0x26000000U)
#define SPI2_BASE             (0x26001000U)
#define SPI3_BASE             (0x26002000U)
#define I2C3_BASE             (0x26003000U)
#define FSITX_BASE            (0x26004000U)
#define FSIRX_BASE            (0x26005000U)

// APB2
#define USART1_BASE           (0x27000000U)
#define USART2_BASE           (0x27001000U)

// APB3
#define SCI1_BASE             (0x28000000U)
#define SCI2_BASE             (0x28001000U)
#define I2C1_BASE             (0x28002000U)
#define I2C2_BASE             (0x28003000U)

// APB4
#define LPM_BASE              (0x29000000U)
#define SYSCTL_BASE           (0x29001000U)
#define WDT1_BASE             (0x29002000U)
#define WWDG1_BASE            (0x29003000U)

#define HAC_R_BASE            (0x29005000U)
#define FLASH_R_BASE          (0x29006000U)
#define CRC_BASE              (0x29007000U)

#define NPU_BASE              (0x29009000U)

#define ATIM1_BASE            (0x2900C000U)
#define ATIM2_BASE            (0x2900D000U)
#define I2C4_BASE             (0x2900E000U)
#define SPI4_BASE             (0x2900F000U)
#define UART3_BASE            (0x26010000U)
#define UART4_BASE            (0x26011000U)

// Ctrl subsystem
#define CLB1_BASE                 0x2A000000U
#define CLB1_LOGICCFG_BASE        0x2A000000U
#define CLB1_LOGICCTRL_BASE       0x2A000200U
#define CLB1_DATAEXCH_BASE        0x2A000400U
#define CLB2_BASE                 0x2A000800U
#define CLB2_LOGICCFG_BASE        0x2A000800U
#define CLB2_LOGICCTRL_BASE       0x2A000A00U
#define CLB2_DATAEXCH_BASE        0x2A000C00U
#define CLB3_BASE                 0x2A001000U
#define CLB3_LOGICCFG_BASE        0x2A001000U
#define CLB3_LOGICCTRL_BASE       0x2A001200U
#define CLB3_DATAEXCH_BASE        0x2A001400U
#define CLB4_BASE                 0x2A001800U
#define CLB4_LOGICCFG_BASE        0x2A001800U
#define CLB4_LOGICCTRL_BASE       0x2A001A00U
#define CLB4_DATAEXCH_BASE        0x2A001C00U

#define EPWM1_BASE                0x21000000U
#define EPWM2_BASE                0x21000400U
#define EPWM3_BASE                0x21000800U
#define EPWM4_BASE                0x21000C00U
#define EPWM5_BASE                0x21001000U
#define EPWM6_BASE                0x21001400U
#define EPWM7_BASE                0x21001800U
#define EPWM8_BASE                0x21001C00U
#define EQEP1_BASE                0x21010000U
#define EQEP2_BASE                0x21010400U

#define SDFM1_BASE                0x21050000U
#define SDFM2_BASE                0x21050400U

#define APBXBAR_BASE              0x25000000U

#define CLBOUTPUTXBAR_BASE        0x25015000U

#define SYNC_BASE     0x29001340U

#ifdef __cplusplus
}
#endif


#endif // __ALB32R003X_MMAP_H
