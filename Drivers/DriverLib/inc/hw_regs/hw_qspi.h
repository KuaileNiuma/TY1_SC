/**
  *************************************************************************************
  * @file hw_spi.h
  * @brief This file contains the definition of hw_spi driver.
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

#ifndef _HW_QSPI_H_
#define _HW_QSPI_H_

 /* ========================================================================== */
 /* ================                  QSPI                    ================ */
 /* ========================================================================== */


 /**
   * @brief QSPI host Interface
   */
 typedef struct
 {
   __IO uint32_t CTRLR0;            /*!< 0x000: Control Register 0 */
   __IO uint32_t CTRLR1;            /*!< 0x004: Control Register 1 */
   __IO uint32_t SSIENR;            /*!< 0x008: SSI Enable Register */
   __IO uint32_t MWCR;              /*!< 0x00C: Microwire Control Register */
   __IO uint32_t SER;               /*!< 0x010: Slave Enable Register */
   __IO uint32_t BAUDR;             /*!< 0x014: Baud Rate Select Register */
   __IO uint32_t TXFTLR;            /*!< 0x018: TX FIFO Threshold Level Register */
   __IO uint32_t RXFTLR;            /*!< 0x01C: RX FIFO Threshold Level Register */
   __IO uint32_t TXFLR;             /*!< 0x020: TX FIFO Level Register */
   __IO uint32_t RXFLR;             /*!< 0x024: RX FIFO Level Register */
   __IO uint32_t SR;                /*!< 0x028: Status Register */
   __IO uint32_t IMR;               /*!< 0x02C: Interrupt Mask Register */
   __IO uint32_t ISR;               /*!< 0x030: Interrupt Status Register */
   __IO uint32_t RISR;              /*!< 0x034: Raw Interrupt Status Register */
   __IO uint32_t TXOICR;            /*!< 0x038: TX FIFO Overflow Interrupt Clear Register */
   __IO uint32_t RXOICR;            /*!< 0x03C: RX FIFO Overflow Interrupt Clear Register */
   __IO uint32_t RXUICR;            /*!< 0x040: RX FIFO Underflow Interrupt Clear Register */
   __IO uint32_t MSTICR;            /*!< 0x044: Multi Master Interrupt Clear Register */
   __IO uint32_t ICR;               /*!< 0x048: Interrupt Clear Register */
   __IO uint32_t DMACR;             /*!< 0x04C: DMA Control Register */
   __IO uint32_t DMATDLR;           /*!< 0x050: TX DMA Threshold Level Register */
   __IO uint32_t DMARDLR;           /*!< 0x054: RX DMA Threshold Level Register */
   __IO uint32_t IDR;               /*!< 0x058: Identification Register */
   __IO uint32_t VIDR;              /*!< 0x05C: Version Identification Register */
   __IO uint32_t DR;                /*!< 0x060: Data Register */
   uint32_t RESERVED0[35];          /*!< 0x064 - 0x0EC: Reserved */
   __IO uint32_t RSD;               /*!< 0x0F0: Receive Sample Delay Register */
   __IO uint32_t SPI_CTRLR0;        /*!< 0x0F4: SPI Control Register 0 */
   __IO uint32_t DDR_DRIVE_EDGE;    /*!< 0x0F8: DDR Drive Edge Register */
   __IO uint32_t XIP_MODE_BITS;     /*!< 0x0FC: XIP Mode Bits Register */
   __IO uint32_t XIP_INCR_INST;     /*!< 0x100: XIP Increment Instruction Register */
   __IO uint32_t XIP_WRAP_INST;     /*!< 0x104: XIP Wrap Instruction Register */
   __IO uint32_t XIP_CTRL;          /*!< 0x108: XIP Control Register */
   __IO uint32_t XIP_SER;           /*!< 0x10C: XIP Slave Enable Register */
   __IO uint32_t XRXOICR;           /*!< 0x110: XIP RX Overflow Interrupt Clear Register */
   __IO uint32_t XIP_CNT_TIME_OUT;  /*!< 0x114: XIP Count Time Out Register */
 } QSPI_TypeDef;
// #define QSPI                ((QSPI_TypeDef *) QSPI_BASE)
 //TODO:wait for checking (JIN)
 #define QSPI_FIFO_MAX_LV                      32

#define QSPI_O_CTRLR0             (0x000U)
#define QSPI_O_CTRLR1             (0x004U)
#define QSPI_O_SSIENR             (0x008U)
#define QSPI_O_MWCR               (0x00CU)
#define QSPI_O_SER                (0x010U)
#define QSPI_O_BAUDR              (0x014U)
#define QSPI_O_TXFTLR             (0x018U)
#define QSPI_O_RXFTLR             (0x01CU)
#define QSPI_O_TXFLR              (0x020U)
#define QSPI_O_RXFLR              (0x024U)
#define QSPI_O_SR                 (0x028U)
#define QSPI_O_IMR                (0x02CU)
#define QSPI_O_ISR                (0x030U)
#define QSPI_O_RISR               (0x034U)
#define QSPI_O_TXOICR             (0x038U)
#define QSPI_O_RXOICR             (0x03CU)
#define QSPI_O_RXUICR             (0x040U)
#define QSPI_O_MSTICR             (0x044U)
#define QSPI_O_ICR                (0x048U)
#define QSPI_O_DMACR              (0x04CU)
#define QSPI_O_DMATDLR            (0x050U)
#define QSPI_O_DMARDLR            (0x054U)
#define QSPI_O_IDR                (0x058U)
#define QSPI_O_VIDR               (0x05CU)
#define QSPI_O_DR                 (0x060U)
#define QSPI_O_RSD                (0x0F0U)
#define QSPI_O_SPI_CTRLR0         (0x0F4U)
#define QSPI_O_DDR_DRIVE_EDGE     (0x0F8U)
#define QSPI_O_XIP_MODE_BITS      (0x0FCU)
#define QSPI_O_XIP_INCR_INST      (0x100U)
#define QSPI_O_XIP_WRAP_INST      (0x104U)
#define QSPI_O_XIP_CTRL           (0x108U)
#define QSPI_O_XIP_SER            (0x10CU)
#define QSPI_O_XRXOICR            (0x110U)
#define QSPI_O_XIP_CNT_TIME_OUT   (0x114U)



 /* QSPI register bit definitions */

/* ============================     CTRLR0     ============================== */
#define QSPI_CTRLR0_HYPERBUS_EN_Pos           (24UL)
#define QSPI_CTRLR0_HYPERBUS_EN_Msk           (0x1000000UL)

#define QSPI_CTRLR0_SPI_FRF_Pos               (22UL)
#define QSPI_CTRLR0_SPI_FRF_Msk               (0xC00000UL)

#define QSPI_CTRLR0_CFS_Pos                   (16UL)
#define QSPI_CTRLR0_CFS_Msk                   (0xF0000UL)

#define QSPI_CTRLR0_MQSEL_Pos                 (15UL)
#define QSPI_CTRLR0_MQSEL_Msk                 (0x8000UL)

#define QSPI_CTRLR0_SSTE_Pos                  (14UL)
#define QSPI_CTRLR0_SSTE_Msk                  (0x4000UL)

#define QSPI_CTRLR0_SRL_Pos                   (13UL)
#define QSPI_CTRLR0_SRL_Msk                   (0x2000UL)

#define QSPI_CTRLR0_SLVOE_Pos                 (12UL)
#define QSPI_CTRLR0_SLVOE_Msk                 (0x1000UL)

#define QSPI_CTRLR0_TMOD_Pos                  (10UL)
#define QSPI_CTRLR0_TMOD_Msk                  (0xC00UL)

#define QSPI_CTRLR0_SCPOL_Pos                 (9UL)
#define QSPI_CTRLR0_SCPOL_Msk                 (0x200UL)

#define QSPI_CTRLR0_SCPH_Pos                  (8UL)
#define QSPI_CTRLR0_SCPH_Msk                  (0x100UL)

#define QSPI_CTRLR0_FRF_Pos                   (6UL)
#define QSPI_CTRLR0_FRF_Msk                   (0xC0UL)

#define QSPI_CTRLR0_DFS_Pos                   (0UL)
#define QSPI_CTRLR0_DFS_Msk                   (0x1FUL)
/* ============================     CTRLR1     ============================== */
#define QSPI_CTRLR1_NDF_Pos                   (0UL)
#define QSPI_CTRLR1_NDF_Msk                   (0xFFFFUL)
/* ============================     SSIENR     ============================== */
#define QSPI_SSIENR_SSI_EN_Pos                (0UL)
#define QSPI_SSIENR_SSI_EN_Msk                (0x1UL)
/* ============================      MWCR      ============================== */
#define QSPI_MWCR_MHS_Pos                     (2UL)
#define QSPI_MWCR_MHS_Msk                     (0x4UL)

#define QSPI_MWCR_MOD_Pos                     (1UL)
#define QSPI_MWCR_MOD_Msk                     (0x2UL)

#define QSPI_MWCR_MWMOD_Pos                   (0UL)
#define QSPI_MWCR_MWMOD_Msk                   (0x1UL)
/* ============================      SER       ============================== */
#define QSPI_SER_Pos                          (0UL)
#define QSPI_SER_Msk                          (0x1UL)
/* ============================     BAUDR      ============================== */
#define QSPI_BAUDR_SCKDIV_Pos                 (0UL)
#define QSPI_BAUDR_SCKDIV_Msk                 (0xFFFFUL)
/* ============================     TXFTLR     ============================== */
#define QSPI_TXFTLR_TFT_Pos                   (0UL)
#define QSPI_TXFTLR_TFT_Msk                   (0x1FUL)
/* ============================     RXFTLR     ============================== */
#define QSPI_RXFTLR_RFT_Pos                   (0UL)
#define QSPI_RXFTLR_RFT_Msk                   (0x1FUL)
/* ============================     TXFLR      ============================== */
#define QSPI_TXFTLR_TXTFL_Pos                 (0UL)
#define QSPI_TXFTLR_TXTFL_Msk                 (0x3FUL)
/* ============================     RXFLR      ============================== */
#define QSPI_RXFTLR_RXTFL_Pos                 (0UL)
#define QSPI_RXFTLR_RXTFL_Msk                 (0x3FUL)
/* ============================       SR       ============================== */
#define QSPI_SR_DCOL_Pos                      (6UL)
#define QSPI_SR_DCOL_Msk                      (0x40UL)

#define QSPI_SR_TXE_Pos                       (5UL)
#define QSPI_SR_TXE_Msk                       (0x20UL)

#define QSPI_SR_RFF_Pos                       (4UL)
#define QSPI_SR_RFF_Msk                       (0x10UL)

#define QSPI_SR_RFNE_Pos                      (3UL)
#define QSPI_SR_RFNE_Msk                      (0x8UL)

#define QSPI_SR_TFE_Pos                       (2UL)
#define QSPI_SR_TFE_Msk                       (0x4UL)

#define QSPI_SR_TFNF_Pos                      (1UL)
#define QSPI_SR_TFNF_Msk                      (0x2UL)

#define QSPI_SR_BUSY_Pos                      (0UL)
#define QSPI_SR_BUSY_Msk                      (0x1UL)
/* ============================      IMR       ============================== */
#define QSPI_IMR_XRXOIM_Pos                   (6UL)
#define QSPI_IMR_XRXOIM_Msk                   (0x40UL)

#define QSPI_IMR_MSTIM_Pos                    (5UL)
#define QSPI_IMR_MSTIM_Msk                    (0x20UL)

#define QSPI_IMR_RXFIM_Pos                    (4UL)
#define QSPI_IMR_RXFIM_Msk                    (0x10UL)

#define QSPI_IMR_RXOIM_Pos                    (3UL)
#define QSPI_IMR_RXOIM_Msk                    (0x8UL)

#define QSPI_IMR_RXUIM_Pos                    (2UL)
#define QSPI_IMR_RXUIM_Msk                    (0x4UL)

#define QSPI_IMR_TXOIM_Pos                    (1UL)
#define QSPI_IMR_TXOIM_Msk                    (0x2UL)

#define QSPI_IMR_TXEIM_Pos                    (0UL)
#define QSPI_IMR_TXEIM_Msk                    (0x1UL)
/* ============================      ISR       ============================== */
#define QSPI_IMR_XRXOIS_Pos                   (6UL)
#define QSPI_IMR_XRXOIS_Msk                   (0x40UL)

#define QSPI_ISR_MSTIS_Pos                    (5UL)
#define QSPI_ISR_MSTIS_Msk                    (0x20UL)

#define QSPI_ISR_RXFIS_Pos                    (4UL)
#define QSPI_ISR_RXFIS_Msk                    (0x10UL)

#define QSPI_ISR_RXOIS_Pos                    (3UL)
#define QSPI_ISR_RXOIS_Msk                    (0x8UL)

#define QSPI_ISR_RXUIS_Pos                    (2UL)
#define QSPI_ISR_RXUIS_Msk                    (0x4UL)

#define QSPI_ISR_TXOIS_Pos                    (1UL)
#define QSPI_ISR_TXOIS_Msk                    (0x2UL)

#define QSPI_ISR_TXEIS_Pos                    (0UL)
#define QSPI_ISR_TXEIS_Msk                    (0x1UL)
/* ============================      RISR      ============================== */
#define QSPI_IMR_XRXOIR_Pos                   (6UL)
#define QSPI_IMR_XRXOIR_Msk                   (0x40UL)

#define QSPI_RISR_MSTIR_Pos                   (5UL)
#define QSPI_RISR_MSTIR_Msk                   (0x20UL)

#define QSPI_RISR_RXFIR_Pos                   (4UL)
#define QSPI_RISR_RXFIR_Msk                   (0x10UL)

#define QSPI_RISR_RXOIR_Pos                   (3UL)
#define QSPI_RISR_RXOIR_Msk                   (0x8UL)

#define QSPI_RISR_RXUIR_Pos                   (2UL)
#define QSPI_RISR_RXUIR_Msk                   (0x4UL)

#define QSPI_RISR_TXOIR_Pos                   (1UL)
#define QSPI_RISR_TXOIR_Msk                   (0x2UL)

#define QSPI_RISR_TXEIR_Pos                   (0UL)
#define QSPI_RISR_TXEIR_Msk                   (0x1UL)
 /* ============================      SER       ============================== */
 #define QSPI_SER_Pos                          (0UL)
 #define QSPI_SER_Msk                          (0x1UL)
 /* ============================     BAUDR      ============================== */
 #define QSPI_BAUDR_SCKDIV_Pos                 (0UL)
 #define QSPI_BAUDR_SCKDIV_Msk                 (0xFFFFUL)
 /* ============================     TXFTLR     ============================== */
 #define QSPI_TXFTLR_TXFTHR_Pos                (16UL)
 #define QSPI_TXFTLR_TXFTHR_Msk                (0x1F0000UL)

 #define QSPI_TXFTLR_TFT_Pos                   (0UL)
 #define QSPI_TXFTLR_TFT_Msk                   (0x1FUL)
 /* ============================     RXFTLR     ============================== */
 #define QSPI_RXFTLR_RFT_Pos                   (0UL)
 #define QSPI_RXFTLR_RFT_Msk                   (0x1FUL)
 /* ============================     TXFLR      ============================== */
 #define QSPI_TXFTLR_TXTFL_Pos                 (0UL)
 #define QSPI_TXFTLR_TXTFL_Msk                 (0x3FUL)
 /* ============================     RXFLR      ============================== */
 #define QSPI_RXFTLR_RXTFL_Pos                 (0UL)
 #define QSPI_RXFTLR_RXTFL_Msk                 (0x3FUL)
/* ============================     DMACR      ============================== */
#define QSPI_DMACR_TDMAE_Pos                   (1UL)
#define QSPI_DMACR_TDMAE_Msk                   (0x2UL)

#define QSPI_DMACR_RDMAE_Pos                   (0UL)
#define QSPI_DMACR_RDMAE_Msk                   (0x1UL)
/* ============================    DMATDLR     ============================== */
#define QSPI_DMATDLR_Pos                       (0UL)
#define QSPI_DMATDLR_Msk                       (0x1FUL)
/* ============================    DMARDLR     ============================== */
#define QSPI_DMARDLR_Pos                       (0UL)
#define QSPI_DMARDLR_Msk                       (0x1FUL)
/* ============================      IDR       ============================== */
/* ============================    VERSION     ============================== */
/* ============================       DR       ============================== */
#define QSPI_DR_Pos                            (0UL)
#define QSPI_DR_Msk                            (0xFFFFFFFFUL)
/* ============================  RX_SAM_DELAY  ============================== */
#define QSPI_RX_SAMPLE_DELAY_SE_Pos            (16UL)
#define QSPI_RX_SAMPLE_DELAY_SE_Msk            (10000UL)

#define QSPI_RX_SAMPLE_DELAY_RSD_Pos           (0UL)
#define QSPI_RX_SAMPLE_DELAY_RSD_Msk           (FFUL)
/* ============================   SPI_CTRLR0   ============================== */
#define QSPI_SPI_CTRLR0_CLK_STRETCH_EN_Pos     (30UL)
#define QSPI_SPI_CTRLR0_CLK_STRETCH_EN_Msk     (40000000UL)

#define QSPI_SPI_CTRLR0_XIP_PREFETCH_EN_Pos    (29UL)
#define QSPI_SPI_CTRLR0_XIP_PREFETCH_EN_Msk    (20000000UL)

#define QSPI_SPI_CTRLR0_XIP_MBL_Pos            (26UL)
#define QSPI_SPI_CTRLR0_XIP_MBL_Msk            (C000000UL)

#define QSPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Pos    (25UL)
#define QSPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Msk    (2000000UL)

#define QSPI_SPI_CTRLR0_SPI_DM_EN_Pos          (24UL)
#define QSPI_SPI_CTRLR0_SPI_DM_EN_Msk          (1000000UL)

#define QSPI_SPI_CTRLR0_SSIC_XIP_CONT_XFER_EN_Pos    (21UL)
#define QSPI_SPI_CTRLR0_SSIC_XIP_CONT_XFER_EN_Msk    (200000UL)

#define QSPI_SPI_CTRLR0_XIP_INST_EN_Pos        (20UL)
#define QSPI_SPI_CTRLR0_XIP_INST_EN_Msk        (100000UL)

#define QSPI_SPI_CTRLR0_XIP_DFS_EN_Pos         (19UL)
#define QSPI_SPI_CTRLR0_XIP_DFS_EN_Msk         (80000UL)

#define QSPI_SPI_CTRLR0_XIP_RXDS_EN_Pos        (18UL)
#define QSPI_SPI_CTRLR0_XIP_RXDS_EN_Msk        (40000UL)

#define QSPI_SPI_CTRLR0_INST_DDR_EN_Pos        (17UL)
#define QSPI_SPI_CTRLR0_INST_DDR_EN_Msk        (20000UL)

#define QSPI_SPI_CTRLR0_SPI_DDR_EN_Pos         (16UL)
#define QSPI_SPI_CTRLR0_SPI_DDR_EN_Msk         (10000UL)

#define QSPI_SPI_CTRLR0_WAIT_CYCLES_Pos        (11UL)
#define QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk        (0xF800UL)

#define QSPI_SPI_CTRLR0_INST_L_Pos             (8UL)
#define QSPI_SPI_CTRLR0_INST_L_Msk             (300UL)

#define QSPI_SPI_CTRLR0_XIP_MD_BIT_EN_Pos      (7UL)
#define QSPI_SPI_CTRLR0_XIP_MD_BIT_EN_Msk      (80UL)

#define QSPI_SPI_CTRLR0_ADDR_L_Pos             (2UL)
#define QSPI_SPI_CTRLR0_ADDR_L_Msk             (0x3CUL)

#define QSPI_SPI_CTRLR0_TRANS_TYPE_Pos         (0UL)
#define QSPI_SPI_CTRLR0_TRANS_TYPE_Msk         (0x3UL)
 /* ============================   XIP_MODE_BITS   ============================== */
 #define QSPI_XIP_MODE_BITS_Pos                 (0UL)
 #define QSPI_XIP_MODE_BITS_Msk                 (0xFFFFUL)
 /* ============================   XIP_INCR_INST   ============================== */
 #define QSPI_XIP_INCR_INST_Pos                 (0UL)
 #define QSPI_XIP_INCR_INST_Msk                 (0xFFFFUL)
 /* ============================   XIP_WRAP_INST   ============================== */
 #define QSPI_XIP_WRAP_INST_Pos                 (0UL)
 #define QSPI_XIP_WRAP_INST_Msk                 (0xFFFFUL)
 /* ============================   XIP_CTRLR   ============================== */
 #define QSPI_XIP_CTRLR_XIP_PREFETCH_EN_Pos                 (29UL)
 #define QSPI_XIP_CTRLR_XIP_PREFETCH_EN_Msk                 (0x20000000L)

 #define QSPI_XIP_CTRLR_XIP_MBL_Pos                         (26UL)
 #define QSPI_XIP_CTRLR_XIP_MBL_Msk                         (0xC000000UL)

 #define QSPI_XIP_CTRLR_RXDS_SIG_EN_Pos                     (25UL)
 #define QSPI_XIP_CTRLR_RXDS_SIG_EN_Msk                     (0x2000000UL)

 #define QSPI_XIP_CTRLR_XIP_HYPERBUS_EN_Pos                 (24UL)
 #define QSPI_XIP_CTRLR_XIP_HYPERBUS_EN_Msk                 (0x1000000UL)

 #define QSPI_XIP_CTRLR_CONT_XFER_EN_Pos                    (23UL)
 #define QSPI_XIP_CTRLR_CONT_XFER_EN_Msk                    (0x800000UL)

 #define QSPI_XIP_CTRLR_INST_EN_Pos                         (22UL)
 #define QSPI_XIP_CTRLR_INST_EN_Msk                         (0x400000UL)

 #define QSPI_XIP_CTRLR_RXDS_EN_Pos                         (21UL)
 #define QSPI_XIP_CTRLR_RXDS_EN_Msk                         (0x200000UL)

 #define QSPI_XIP_CTRLR_INST_DDR_EN_Pos                     (20UL)
 #define QSPI_XIP_CTRLR_INST_DDR_EN_Msk                     (0x100000UL)

 #define QSPI_XIP_CTRLR_DDR_EN_Pos                          (19UL)
 #define QSPI_XIP_CTRLR_DDR_EN_Msk                          (0x80000UL)

 #define QSPI_XIP_CTRLR_DFS_HC_Pos                          (18UL)
 #define QSPI_XIP_CTRLR_DFS_HC_Msk                          (0x40000UL)

 #define QSPI_XIP_CTRLR_WAIT_CYCLES_Pos                     (13UL)
 #define QSPI_XIP_CTRLR_WAIT_CYCLES_Msk                     (0x3E000UL)

 #define QSPI_XIP_CTRLR_MD_BITS_EN_Pos                      (12UL)
 #define QSPI_XIP_CTRLR_MD_BITS_EN_Msk                      (0x1000UL)

 #define QSPI_XIP_CTRLR_INST_L_Pos                          (9UL)
 #define QSPI_XIP_CTRLR_INST_L_Msk                          (0x600UL)

 #define QSPI_XIP_CTRLR_ADDR_L_Pos                          (4UL)
 #define QSPI_XIP_CTRLR_ADDR_L_Msk                          (0xF0UL)

 #define QSPI_XIP_CTRLR_TRANS_TYPE_Pos                      (2UL)
 #define QSPI_XIP_CTRLR_TRANS_TYPE_Msk                      (0xCUL)

 #define QSPI_XIP_CTRLR_FRF_Pos                             (0UL)
 #define QSPI_XIP_CTRLR_FRF_Msk                             (0x3UL)
 /* ============================   XIP_SER   ============================== */
 #define QSPI_XIP_SER_Pos                       (0UL)
 #define QSPI_XIP_SER_Msk                       (0x1UL)
 /* ============================   XRXOICR   ============================== */
 #define QSPI_XRXOICR_Pos                       (0UL)
 #define QSPI_XRXOICR_Msk                       (0x1UL)
 /* ============================   XIP_CNT_TIME_OUT   ============================== */
 #define QSPI_XIP_CNT_TIME_OUT_XTOC_Pos         (0UL)
 #define QSPI_XIP_CNT_TIME_OUT_XTOC_Msk         (0xFFUL)
/** @addtogroup 
  * @{
  */

/** @addtogroup QSPI
  * @{
  */

/** @defgroup QSPI_Exported_Types
  * @{
  */


#define QSPI_FIFO_DEPTH 32



#define QSPI_XIP_BASE               ((uint32_t)0x60000000)

/**
  * @}
  */

/** @defgroup QSPI_ClockPolarity
  * @{
  */

#define QSPI_CLKPOL_LOW				      ((uint32_t)0x00000000)
#define QSPI_CLKPOL_HIGH					  ((uint32_t)0x00000200)

/**
  * @}
  */

/** @defgroup QSPI_ClockPhase
  * @{
  */
#define QSPI_CLKPHA_1EDGE           ((uint32_t)0x00000100) //toggles at start of first edge
#define QSPI_CLKPHA_2EDGE           ((uint32_t)0x00000000) //toggles at start of sencond edge
/**
  * @}
  */

/** @defgroup QSPI_DataFrameSize
  * @{
  */
#define QSPI_DataFrameSize_4b            ((uint32_t)0x00000003)
#define QSPI_DataFrameSize_5b            ((uint32_t)0x00000004)
#define QSPI_DataFrameSize_6b            ((uint32_t)0x00000005)
#define QSPI_DataFrameSize_7b            ((uint32_t)0x00000006)
#define QSPI_DataFrameSize_8b            ((uint32_t)0x00000007)
#define QSPI_DataFrameSize_9b            ((uint32_t)0x00000008)
#define QSPI_DataFrameSize_10b           ((uint32_t)0x00000009)
#define QSPI_DataFrameSize_11b           ((uint32_t)0x0000000A)
#define QSPI_DataFrameSize_12b           ((uint32_t)0x0000000B)
#define QSPI_DataFrameSize_13b           ((uint32_t)0x0000000C)
#define QSPI_DataFrameSize_14b           ((uint32_t)0x0000000D)
#define QSPI_DataFrameSize_15b           ((uint32_t)0x0000000E)
#define QSPI_DataFrameSize_16b           ((uint32_t)0x0000000F)
#define QSPI_DataFrameSize_17b           ((uint32_t)0x00000010)
#define QSPI_DataFrameSize_18b           ((uint32_t)0x00000011)
#define QSPI_DataFrameSize_19b           ((uint32_t)0x00000012)
#define QSPI_DataFrameSize_20b           ((uint32_t)0x00000013)
#define QSPI_DataFrameSize_21b           ((uint32_t)0x00000014)
#define QSPI_DataFrameSize_22b           ((uint32_t)0x00000015)
#define QSPI_DataFrameSize_23b           ((uint32_t)0x00000016)
#define QSPI_DataFrameSize_24b           ((uint32_t)0x00000017)
#define QSPI_DataFrameSize_25b           ((uint32_t)0x00000018)
#define QSPI_DataFrameSize_26b           ((uint32_t)0x00000019)
#define QSPI_DataFrameSize_27b           ((uint32_t)0x0000001A)
#define QSPI_DataFrameSize_28b           ((uint32_t)0x0000001B)
#define QSPI_DataFrameSize_29b           ((uint32_t)0x0000001C)
#define QSPI_DataFrameSize_30b           ((uint32_t)0x0000001D)
#define QSPI_DataFrameSize_31b           ((uint32_t)0x0000001E)
#define QSPI_DataFrameSize_32b           ((uint32_t)0x0000001F)
/**
  * @}
  */

/** @defgroup SPI_CFS SPI Data Frame Size
  * @{
  */
#define QSPI_ControlFrameSize_1b               (0x00000U)
#define QSPI_ControlFrameSize_2b               (0x10000U)
#define QSPI_ControlFrameSize_3b               (0x20000U)
#define QSPI_ControlFrameSize_4b               (0x30000U)
#define QSPI_ControlFrameSize_5b               (0x40000U)
#define QSPI_ControlFrameSize_6b               (0x50000U)
#define QSPI_ControlFrameSize_7b               (0x60000U)
#define QSPI_ControlFrameSize_8b               (0x70000U)
#define QSPI_ControlFrameSize_9b               (0x80000U)
#define QSPI_ControlFrameSize_10b              (0x90000U)
#define QSPI_ControlFrameSize_11b              (0xA0000U)
#define QSPI_ControlFrameSize_12b              (0xB0000U)
#define QSPI_ControlFrameSize_13b              (0xC0000U)
#define QSPI_ControlFrameSize_14b              (0xD0000U)
#define QSPI_ControlFrameSize_15b              (0xE0000U)
#define QSPI_ControlFrameSize_16b              (0xF0000U)
/**
  * @}
  */


/** @defgroup QSPI FrmFormat
  * @{
  */
#define QSPI_FRF_STD                      ((uint32_t)0x00000000)     //!< Standard SPI
#define QSPI_FRF_DUAL                     ((uint32_t)0x00400000)     //!< Dual SPI
#define QSPI_FRF_QUAD                     ((uint32_t)0x00800000)     //!< QUAD SPI
#define QSPI_FRF_OCTAL                    ((uint32_t)0x00C00000)     //!< OCTAL SPI
/**
  * @}
  */

/** @defgroup Slave Select Toggle Enable
  * @{
  */
#define QSPI_CTRLR0_SSTE_ENABLE            QSPI_CTRLR0_SSTE_Msk
#define QSPI_CTRLR0_SSTE_DISABLE           0x000U
/**
  * @}
  */

/** @defgroup QSPI TransMode
  * @{
  */
#define QSPI_CTRLR0_TMOD_TX_AND_RX				((uint32_t)0x00000000)
#define QSPI_CTRLR0_TMOD_TX_ONLY			    ((uint32_t)0x00000400)
#define QSPI_CTRLR0_TMOD_RX_ONLY				((uint32_t)0x00000800)
#define QSPI_CTRLR0_TMOD_EEPROM_READ		    ((uint32_t)0x00000C00)
/**
  * @}
  */

/** @defgroup transmit FrameFormat
  * @{
  */
#define QSPI_CTRLR0_FRF_SPI              0x00000000U
#define QSPI_CTRLR0_FRF_SSP              0x00000040U
#define QSPI_CTRLR0_FRF_Microwire        0x000000C0U
/**
  * @}
  */

/** @defgroup CTRLR0.SRL
  * @{
  */
#define QSPI_CTRLR0_SRL_NORMAL             0x00000000U
#define QSPI_CTRLR0_SRL_TESTING            QSPI_CTRLR0_SRL_Msk
/**
  * @}
  */

/** @defgroup QSPI Select mspi or qspi
  * @{
  */
#define QSPI_CTRLR0_MQSEL_QSPI              0x00000000U
#define QSPI_CTRLR0_MQSEL_MSPI              QSPI_CTRLR0_MQSEL_Msk
/**
  * @}
  */

/** @defgroup QSPI SSIENR
  * @{
  */
#define QSPI_SSIENR_SSI_ENABLE               QSPI_SSIENR_SSI_EN_Msk
#define QSPI_SSIENR_SSI_DISABLE              ((uint32_t)0x00000000)
/**
  * @}
  */

/** @defgroup QSPI_NSS_management QSPI NSS set
 *   * @{
 *     */
#define HAL_QSPI_NSS_CS_ENABLE          (0x1U)
#define HAL_QSPI_NSS_CS_DISABLE         (0x0U)
/**
  * @}
  */

/** @defgroup Microwire Control
  * @{
  */
#define QSPI_MWCR_MHS_DISABLE              QSPI_MWCR_MHS_Msk
#define QSPI_MWCR_MHS_ENABLE               0x00000000U
#define QSPI_MWCR_MOD_TRANSMIT             QSPI_MWCR_MOD_Msk
#define QSPI_MWCR_MOD_RECEIVE              0x00000000U
#define QSPI_MWCR_MWMOD_SEQUENTIAL         QSPI_MWCR_MWMOD_Msk
#define QSPI_MWCR_MWMOD_NON_SEQUENTIAL     0x00000000U
/**
  * @}
  */

/** @defgroup  Transmit FIFO Threshold
  * @{
  */
#define QSPI_RXFIFO_THRESHOLD1       0x0U
#define QSPI_RXFIFO_THRESHOLD2       0x1U
#define QSPI_RXFIFO_THRESHOLD3       0x2U
#define QSPI_RXFIFO_THRESHOLD4       0x3U
#define QSPI_RXFIFO_THRESHOLD5       0x4U
#define QSPI_RXFIFO_THRESHOLD6       0x5U
#define QSPI_RXFIFO_THRESHOLD7       0x6U
#define QSPI_RXFIFO_THRESHOLD8       0x7U
#define QSPI_RXFIFO_THRESHOLD9       0x8U
#define QSPI_RXFIFO_THRESHOLD10      0x9U
#define QSPI_RXFIFO_THRESHOLD11      0xAU
#define QSPI_RXFIFO_THRESHOLD12      0xBU
#define QSPI_RXFIFO_THRESHOLD13      0xCU
#define QSPI_RXFIFO_THRESHOLD14      0xDU
#define QSPI_RXFIFO_THRESHOLD15      0xEU
#define QSPI_RXFIFO_THRESHOLD16      0xFU
#define QSPI_RXFIFO_THRESHOLD17      0x10U
#define QSPI_RXFIFO_THRESHOLD18      0x11U
#define QSPI_RXFIFO_THRESHOLD19      0x12U
#define QSPI_RXFIFO_THRESHOLD20      0x13U
#define QSPI_RXFIFO_THRESHOLD21      0x14U
#define QSPI_RXFIFO_THRESHOLD22      0x15U
#define QSPI_RXFIFO_THRESHOLD23      0x16U
#define QSPI_RXFIFO_THRESHOLD24      0x17U
#define QSPI_RXFIFO_THRESHOLD25      0x18U
#define QSPI_RXFIFO_THRESHOLD26      0x19U
#define QSPI_RXFIFO_THRESHOLD27      0x1AU
#define QSPI_RXFIFO_THRESHOLD28      0x1BU
#define QSPI_RXFIFO_THRESHOLD29      0x1CU
#define QSPI_RXFIFO_THRESHOLD30      0x1DU
#define QSPI_RXFIFO_THRESHOLD31      0x1EU
#define QSPI_RXFIFO_THRESHOLD32      0x1FU
/**
  * @}
  */

/** @defgroup  Receive FIFO Threshold
  * @{
  */
#define QSPI_TXFIFO_THRESHOLD0       0x0U
#define QSPI_TXFIFO_THRESHOLD1       0x1U
#define QSPI_TXFIFO_THRESHOLD2       0x2U
#define QSPI_TXFIFO_THRESHOLD3       0x3U
#define QSPI_TXFIFO_THRESHOLD4       0x4U
#define QSPI_TXFIFO_THRESHOLD5       0x5U
#define QSPI_TXFIFO_THRESHOLD6       0x6U
#define QSPI_TXFIFO_THRESHOLD7       0x7U
#define QSPI_TXFIFO_THRESHOLD8       0x8U
#define QSPI_TXFIFO_THRESHOLD9       0x9U
#define QSPI_TXFIFO_THRESHOLD10      0xAU
#define QSPI_TXFIFO_THRESHOLD11      0xBU
#define QSPI_TXFIFO_THRESHOLD12      0xCU
#define QSPI_TXFIFO_THRESHOLD13      0xDU
#define QSPI_TXFIFO_THRESHOLD14      0xEU
#define QSPI_TXFIFO_THRESHOLD15      0xFU
#define QSPI_TXFIFO_THRESHOLD16      0x10U
#define QSPI_TXFIFO_THRESHOLD17      0x11U
#define QSPI_TXFIFO_THRESHOLD18      0x12U
#define QSPI_TXFIFO_THRESHOLD19      0x13U
#define QSPI_TXFIFO_THRESHOLD20      0x14U
#define QSPI_TXFIFO_THRESHOLD21      0x15U
#define QSPI_TXFIFO_THRESHOLD22      0x16U
#define QSPI_TXFIFO_THRESHOLD23      0x17U
#define QSPI_TXFIFO_THRESHOLD24      0x18U
#define QSPI_TXFIFO_THRESHOLD25      0x19U
#define QSPI_TXFIFO_THRESHOLD26      0x1AU
#define QSPI_TXFIFO_THRESHOLD27      0x1BU
#define QSPI_TXFIFO_THRESHOLD28      0x1CU
#define QSPI_TXFIFO_THRESHOLD29      0x1DU
#define QSPI_TXFIFO_THRESHOLD30      0x1EU
#define QSPI_TXFIFO_THRESHOLD31      0x1FU
/**
  * @}
  */

/** @defgroup QSPI_Flags_definition QSPI Flags Definition
  * @{
  */
#define QSPI_INTFLAG_TXE             QSPI_ISR_TXEIS_Msk
#define QSPI_INTFLAG_TXO             QSPI_ISR_TXOIS_Msk
#define QSPI_INTFLAG_RXU             QSPI_ISR_RXUIS_Msk
#define QSPI_INTFLAG_RXO             QSPI_ISR_RXOIS_Msk
#define QSPI_INTFLAG_RXF             QSPI_ISR_RXFIS_Msk
#define QSPI_INTFLAG_MST             QSPI_ISR_MSTIS_Msk
/**
  * @}
  */

/** @defgroup QSPI_INTMask_definition
  * @{
  */
#define QSPI_TXEIM_ENABLE              QSPI_IMR_TXEIM_Msk
#define QSPI_TXOIM_ENABLE              QSPI_IMR_TXOIM_Msk
#define QSPI_RXUIM_ENABLE              QSPI_IMR_RXUIM_Msk
#define QSPI_RXOIM_ENABLE              QSPI_IMR_RXOIM_Msk
#define QSPI_RXFIM_ENABLE              QSPI_IMR_RXFIM_Msk
#define QSPI_MSTIM_ENABLE              QSPI_IMR_MSTIM_Msk
#define QSPI_XRXOIM_ENABLE             QSPI_IMR_XRXOIM_Msk

#define QSPI_TXEIM_DISABLE             (0UL)
#define QSPI_TXOIM_DISABLE             (0UL)
#define QSPI_RXUIM_DISABLE             (0UL)
#define QSPI_RXOIM_DISABLE             (0UL)
#define QSPI_RXFIM_DISABLE             (0UL)
#define QSPI_MSTIM_DISABLE             (0UL)
#define QSPI_XRXOIM_DISABLE            (0UL)
/**
  * @}
  */

/** @defgroup QSPI_FLAG
  * @{
  */

#define QSPI_FLAG_BUSY     ((uint32_t)0x00000001)
#define QSPI_FLAG_TFNF     ((uint32_t)0x00000002)
#define QSPI_FLAG_TFE      ((uint32_t)0x00000004)
#define QSPI_FLAG_RFNE     ((uint32_t)0x00000008)
#define QSPI_FLAG_RFF      ((uint32_t)0x00000010)
#define QSPI_FLAG_TXE      ((uint32_t)0x00000020)
#define QSPI_FLAG_DCE      ((uint32_t)0x00000040)

/**
  * @}
  */

/** @defgroup QSPI DMA Receive and Transmit Enable
  * @{
  */
#define QSPI_DMA_RDMAEN               ((uint32_t)0x00000001)
#define QSPI_DMA_RDMADIS              ((uint32_t)0x00000000)
#define QSPI_DMA_TDMAEN               ((uint32_t)0x00000002)
#define QSPI_DMA_TDMADIS              ((uint32_t)0x00000000)
/**
  * @}
  */

/** @defgroup TX Request Threshold of DMA
  * @{
  */
#define QSPI_DMATDLR_0                (0x0U)
#define QSPI_DMATDLR_1                (0x1U)
#define QSPI_DMATDLR_2                (0x2U)
#define QSPI_DMATDLR_3                (0x3U)
#define QSPI_DMATDLR_4                (0x4U)
#define QSPI_DMATDLR_5                (0x5U)
#define QSPI_DMATDLR_6                (0x6U)
#define QSPI_DMATDLR_7                (0x7U)
#define QSPI_DMATDLR_8                (0x8U)
#define QSPI_DMATDLR_9                (0x9U)
#define QSPI_DMATDLR_10               (0xAU)
#define QSPI_DMATDLR_11               (0xBU)
#define QSPI_DMATDLR_12               (0xCU)
#define QSPI_DMATDLR_13               (0xDU)
#define QSPI_DMATDLR_14               (0xEU)
#define QSPI_DMATDLR_15               (0xFU)
#define QSPI_DMATDLR_16               (0x10U)
#define QSPI_DMATDLR_17               (0x11U)
#define QSPI_DMATDLR_18               (0x12U)
#define QSPI_DMATDLR_19               (0x13U)
#define QSPI_DMATDLR_20               (0x14U)
#define QSPI_DMATDLR_21               (0x15U)
#define QSPI_DMATDLR_22               (0x16U)
#define QSPI_DMATDLR_23               (0x17U)
#define QSPI_DMATDLR_24               (0x18U)
#define QSPI_DMATDLR_25               (0x19U)
#define QSPI_DMATDLR_26               (0x1AU)
#define QSPI_DMATDLR_27               (0x1BU)
#define QSPI_DMATDLR_28               (0x1CU)
#define QSPI_DMATDLR_29               (0x1DU)
#define QSPI_DMATDLR_30               (0x1EU)
#define QSPI_DMATDLR_31               (0x1FU)
/**
  * @}
  */

/** @defgroup RX Request Threshold of DMA
  * @{
  */
#define QSPI_DMARDLR_1                (0x0U)
#define QSPI_DMARDLR_2                (0x1U)
#define QSPI_DMARDLR_3                (0x2U)
#define QSPI_DMARDLR_4                (0x3U)
#define QSPI_DMARDLR_5                (0x4U)
#define QSPI_DMARDLR_6                (0x5U)
#define QSPI_DMARDLR_7                (0x6U)
#define QSPI_DMARDLR_8                (0x7U)
#define QSPI_DMARDLR_9                (0x8U)
#define QSPI_DMARDLR_10               (0x9U)
#define QSPI_DMARDLR_11               (0xAU)
#define QSPI_DMARDLR_12               (0xBU)
#define QSPI_DMARDLR_13               (0xCU)
#define QSPI_DMARDLR_14               (0xDU)
#define QSPI_DMARDLR_15               (0xEU)
#define QSPI_DMARDLR_16               (0xFU)
#define QSPI_DMARDLR_17               (0x10U)
#define QSPI_DMARDLR_18               (0x11U)
#define QSPI_DMARDLR_19               (0x12U)
#define QSPI_DMARDLR_20               (0x13U)
#define QSPI_DMARDLR_21               (0x14U)
#define QSPI_DMARDLR_22               (0x15U)
#define QSPI_DMARDLR_23               (0x16U)
#define QSPI_DMARDLR_24               (0x17U)
#define QSPI_DMARDLR_25               (0x18U)
#define QSPI_DMARDLR_26               (0x19U)
#define QSPI_DMARDLR_27               (0x1AU)
#define QSPI_DMARDLR_28               (0x1BU)
#define QSPI_DMARDLR_29               (0x1CU)
#define QSPI_DMARDLR_30               (0x1DU)
#define QSPI_DMARDLR_31               (0x1EU)
#define QSPI_DMARDLR_32               (0x1FU)

/**
  * @}
  */


/** @defgroup QSPI RX SampleEdge
  * @{
  */

#define QSPI_RX_Sample_Edge_LOW               ((uint32_t)0x00010000)
#define QSPI_RX_Sample_Edge_HIGH              ((uint32_t)0x00000000)

/**
  * @}
  */

/** @defgroup SPI_CTRLR0.TRANSTYPE
  * @{
  */
#define QSPI_SPI_CTRLR0_TRANSTYPE_TT0             0x00000000U
#define QSPI_SPI_CTRLR0_TRANSTYPE_TT1             0x00000001U
#define QSPI_SPI_CTRLR0_TRANSTYPE_TT2             0x00000002U
#define QSPI_SPI_CTRLR0_TRANSTYPE_TT3             0x00000003U
/**
  * @}
  */

/** @defgroup QSPI InsAddr Type
  * @{
  */
#define QSPI_INST_ADDR_TYPE_STANDARD	            ((uint32_t)0x00000000)
#define QSPI_INST_TYPE_STANDARD	                  ((uint32_t)0x00000001)
#define QSPI_INST_ADDR_TYPE_FRF	                  ((uint32_t)0x00000002)
/**
  * @}
  */

/** @defgroup QSPI_Addr_Length
  * @{
  */
#define QSPI_Addr_Length_NoAddr 				((uint32_t)0x00000000)
#define QSPI_Addr_Length_4b 					  ((uint32_t)0x00000004)
#define QSPI_Addr_Length_8b 					  ((uint32_t)0x00000008)
#define QSPI_Addr_Length_12b 					  ((uint32_t)0x0000000C)
#define QSPI_Addr_Length_16b 					  ((uint32_t)0x00000010)
#define QSPI_Addr_Length_20b 					  ((uint32_t)0x00000014)
#define QSPI_Addr_Length_24b 					  ((uint32_t)0x00000018)
#define QSPI_Addr_Length_28b 				  	((uint32_t)0x0000001C)
#define QSPI_Addr_Length_32b 				  	((uint32_t)0x00000020)
#define QSPI_Addr_Length_36b 				  	((uint32_t)0x00000024)
#define QSPI_Addr_Length_40b 				  	((uint32_t)0x00000028)
#define QSPI_Addr_Length_44b 			  		((uint32_t)0x0000002C)
#define QSPI_Addr_Length_48b 			  		((uint32_t)0x00000030)
#define QSPI_Addr_Length_52b 			  		((uint32_t)0x00000034)
#define QSPI_Addr_Length_56b 			  		((uint32_t)0x00000038)
#define QSPI_Addr_Length_60b 			  		((uint32_t)0x0000003C)
/**
  * @}
  */

/** @defgroup QSPI_Inst_Length
  * @{
  */
#define QSPI_Inst_Length_NoInst						((uint32_t)0x00000000)
#define QSPI_Inst_Length_4b						    ((uint32_t)0x00000100)
#define QSPI_Inst_Length_8b						  	((uint32_t)0x00000200)
#define QSPI_Inst_Length_16b					  	((uint32_t)0x00000300)
/**
  * @}
  */

/** @defgroup QSPI_Wait_Cycles
  * @{
  */
#define QSPI_WAIT_CYCLES_0                         ((uint32_t)0x00000000)
#define QSPI_WAIT_CYCLES_1                         ((uint32_t)0x00000800)
#define QSPI_WAIT_CYCLES_2                         ((uint32_t)0x00001000)
#define QSPI_WAIT_CYCLES_3                         ((uint32_t)0x00001800)
#define QSPI_WAIT_CYCLES_4                         ((uint32_t)0x00002000)
#define QSPI_WAIT_CYCLES_5                         ((uint32_t)0x00002800)
#define QSPI_WAIT_CYCLES_6                         ((uint32_t)0x00003000)
#define QSPI_WAIT_CYCLES_7                         ((uint32_t)0x00003800)
#define QSPI_WAIT_CYCLES_8                         ((uint32_t)0x00004000)
#define QSPI_WAIT_CYCLES_9                         ((uint32_t)0x00004800)
#define QSPI_WAIT_CYCLES_10                        ((uint32_t)0x00005000)
#define QSPI_WAIT_CYCLES_11                        ((uint32_t)0x00005800)
#define QSPI_WAIT_CYCLES_12                        ((uint32_t)0x00006000)
#define QSPI_WAIT_CYCLES_13                        ((uint32_t)0x00006800)
#define QSPI_WAIT_CYCLES_14                        ((uint32_t)0x00007000)
#define QSPI_WAIT_CYCLES_15                        ((uint32_t)0x00007800)
#define QSPI_WAIT_CYCLES_16                        ((uint32_t)0x00008000)
#define QSPI_WAIT_CYCLES_17                        ((uint32_t)0x00008800)
#define QSPI_WAIT_CYCLES_18                        ((uint32_t)0x00009000)
#define QSPI_WAIT_CYCLES_19                        ((uint32_t)0x00009800)
#define QSPI_WAIT_CYCLES_20                        ((uint32_t)0x0000A000)
#define QSPI_WAIT_CYCLES_21                        ((uint32_t)0x0000A800)
#define QSPI_WAIT_CYCLES_22                        ((uint32_t)0x0000B000)
#define QSPI_WAIT_CYCLES_23                        ((uint32_t)0x0000B800)
#define QSPI_WAIT_CYCLES_24                        ((uint32_t)0x0000C000)
#define QSPI_WAIT_CYCLES_25                        ((uint32_t)0x0000C800)
#define QSPI_WAIT_CYCLES_26                        ((uint32_t)0x0000D000)
#define QSPI_WAIT_CYCLES_27                        ((uint32_t)0x0000D800)
#define QSPI_WAIT_CYCLES_28                        ((uint32_t)0x0000E000)
#define QSPI_WAIT_CYCLES_29                        ((uint32_t)0x0000E800)
#define QSPI_WAIT_CYCLES_30                        ((uint32_t)0x0000F000)
#define QSPI_WAIT_CYCLES_31                        ((uint32_t)0x0000F800)
/**
  * @}
  */

/** @defgroup QSPI_XIP_FRF
  * @{
  */
#define QSPI_XIP_FRF_STD                  ((uint32_t)0x0)     //!< Standard SPI
#define QSPI_XIP_FRF_DUAL                 ((uint32_t)0x1)     //!< Dual SPI
#define QSPI_XIP_FRF_QUAD                 ((uint32_t)0x2)     //!< QUAD SPI

/**
  * @}
  */

/** @defgroup QSPI_XIP_Inst_EN
  * @{
  */

#define QSPI_XIP_INST_ENABLE              ((uint32_t)0x00400000)
#define QSPI_XIP_INST_DISABLE             ((uint32_t)0x00000000)

/**
  * @}
  */

/** @defgroup QSPI_XIP_Trans_Type
  * @{
  */
#define QSPI_XIP_INST_ADDR_TYPE_STANDARD          ((uint32_t)0x00000000)
#define QSPI_XIP_INST_TYPE_STANDARD               ((uint32_t)0x00000004)
#define QSPI_XIP_INST_ADDR_TYPE_FRF               ((uint32_t)0x00000008)
/**
  * @}
  */

/** @defgroup QSPI_XIP_Addr_Length
  * @{
  */
#define QSPI_XIP_Addr_Length_NoAddr                 ((uint32_t)0x00000000)
#define QSPI_XIP_Addr_Length_4b                     ((uint32_t)0x00000010)
#define QSPI_XIP_Addr_Length_8b                     ((uint32_t)0x00000020)
#define QSPI_XIP_Addr_Length_12b                    ((uint32_t)0x00000030)
#define QSPI_XIP_Addr_Length_16b                    ((uint32_t)0x00000040)
#define QSPI_XIP_Addr_Length_20b                    ((uint32_t)0x00000050)
#define QSPI_XIP_Addr_Length_24b                    ((uint32_t)0x00000060)
#define QSPI_XIP_Addr_Length_28b                    ((uint32_t)0x00000070)
#define QSPI_XIP_Addr_Length_32b                    ((uint32_t)0x00000080)
#define QSPI_XIP_Addr_Length_36b                    ((uint32_t)0x00000090)
#define QSPI_XIP_Addr_Length_40b                    ((uint32_t)0x000000A0)
#define QSPI_XIP_Addr_Length_44b                    ((uint32_t)0x000000B0)
#define QSPI_XIP_Addr_Length_48b                    ((uint32_t)0x000000C0)
#define QSPI_XIP_Addr_Length_52b                    ((uint32_t)0x000000D0)
#define QSPI_XIP_Addr_Length_56b                    ((uint32_t)0x000000E0)
#define QSPI_XIP_Addr_Length_60b                    ((uint32_t)0x000000F0)
/**
  * @}
  */

/** @defgroup QSPI_XIP_Inst_Length
  * @{
  */
#define QSPI_XIP_Inst_Length_NoInst                     ((uint32_t)0x00000000)
#define QSPI_XIP_Inst_Length_4b                         ((uint32_t)0x00000200)
#define QSPI_XIP_Inst_Length_8b                         ((uint32_t)0x00000400)
#define QSPI_XIP_Inst_Length_16b                        ((uint32_t)0x00000600)

/**
  * @}
  */

/** @defgroup QSPI_XIP_Mode_Bits_EN
  * @{
  */
#define QSPI_SPICTRL0_XIP_Mode_Bits_ENABLE             ((uint32_t)0x00000080)
#define QSPI_SPICTRL0_XIP_Mode_Bits_DISABLE            ((uint32_t)0x00000000)
#define QSPI_XIPCTRL_XIP_Mode_Bits_ENABLE             ((uint32_t)0x00001000)
#define QSPI_XIPCTRL_XIP_Mode_Bits_DISABLE            ((uint32_t)0x00000000)
/**
  * @}
  */

/** @defgroup QSPI_Mode_Bits_Length
  * @{
  */

#define QSPI_XIP_Mode_Bits_Length_2						((uint32_t)0x00000000)
#define QSPI_XIP_Mode_Bits_Length_4						((uint32_t)0x04000000)
#define QSPI_XIP_Mode_Bits_Length_8						((uint32_t)0x08000000)
#define QSPI_XIP_Mode_Bits_Length_16					((uint32_t)0x0C000000)
/**
  * @}
  */

/** @defgroup QSPI_XIP_CTRL_WAIT_CYCLES
  * @{
  */
#define QSPI_XIP_CTRL_WAIT_CYCLES_0             ((uint32_t)0x0000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_1             ((uint32_t)0x2000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_2             ((uint32_t)0x4000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_3             ((uint32_t)0x6000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_4             ((uint32_t)0x8000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_5             ((uint32_t)0xA000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_6             ((uint32_t)0xC000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_7             ((uint32_t)0xE000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_8             ((uint32_t)0x10000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_9             ((uint32_t)0x12000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_10            ((uint32_t)0x14000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_11            ((uint32_t)0x16000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_12            ((uint32_t)0x18000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_13            ((uint32_t)0x1A000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_14            ((uint32_t)0x1C000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_15            ((uint32_t)0x1E000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_16            ((uint32_t)0x20000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_17            ((uint32_t)0x22000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_18            ((uint32_t)0x24000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_19            ((uint32_t)0x26000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_20            ((uint32_t)0x28000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_21            ((uint32_t)0x2A000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_22            ((uint32_t)0x2C000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_23            ((uint32_t)0x2E000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_24            ((uint32_t)0x30000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_25            ((uint32_t)0x32000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_26            ((uint32_t)0x34000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_27            ((uint32_t)0x36000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_28            ((uint32_t)0x38000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_29            ((uint32_t)0x3A000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_30            ((uint32_t)0x3C000)
#define QSPI_XIP_CTRL_WAIT_CYCLES_31            ((uint32_t)0x3E000)

 /** @defgroup QSPI_XIP_DFS_HC
   * @{
   */
 #define QSPI_XIP_DFS_HC_ENABLE                 ((uint32_t)0x40000)
 #define QSPI_XIP_DFS_HC_DISABLE                ((uint32_t)0x00000)
 /**
   * @}
   */

 /** @defgroup QSPI_XIP_PREFETCH
   * @{
   */
 #define QSPI_XIP_PREFETCH_ENABLE                 ((uint32_t)0x20000000)
 #define QSPI_XIP_PREFETCH_DISABLE                ((uint32_t)0x00000000)
 /**
   * @}
   */

 /** @defgroup QSPI_XIP_PREFETCH
   * @{
   */
 #define QSPI_XIP_CONTINUOUSTX_ENABLE             ((uint32_t)0x800000)
 #define QSPI_XIP_CONTINUOUSTX_DISABLE            ((uint32_t)0x000000)
 /**
   * @}
   */


#endif 
