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

#ifndef _HW_SPI_H_
#define _HW_SPI_H_

/* registers definition */
#define SPI_O_CTRLR0        0x0  /* Control Register 0 */
#define SPI_O_CTRLR1        0x4  /* Control Register 1 */
#define SPI_O_SSIENR        0x8  /* Enable Register */
#define SPI_O_MWCR          0xC  /* Microwire Control Register */
#define SPI_O_SER           0x10 /* Slave Enable Register */
#define SPI_O_BAUDR         0x14 /* Baud Rate Select Register */
#define SPI_O_TXFTLR        0x18 /* Tx FIFO Threshold Level Register */
#define SPI_O_RXFTLR        0x1C /* Rx FIFO Threshold Level Register */
#define SPI_O_TXFLR         0x20 /* Transmit FIFO Level Register */
#define SPI_O_RXFLR         0x24 /* Receive  FIFO Level Register */
#define SPI_O_SR            0x28 /* Status   Register */
#define SPI_O_IMR           0x2C /* Interrupt Mask Register */
#define SPI_O_ISR           0x30 /* Interrupt Status Register */
#define SPI_O_RISR          0x34 /* Raw Interrupt Status Register */
#define SPI_O_TXOICR        0x38 /* Tx FIFO Overflow Interrupt Clear Register */
#define SPI_O_RXOICR        0x3C /* Rx FIFO Overflow Interrupt Clear Register */
#define SPI_O_RXUICR        0x40 /* Rx FIFO Underflow Interrupt Clear Register */
#define SPI_O_MSTICR        0x44 /* Multi-Master Interrupt Clear Register */
#define SPI_O_ICR           0x48 /* Interrupt Clear Register */
#define SPI_O_DMACR         0x4C /* DMA Control Register */
#define SPI_O_DMATDLR       0x50 /* DMA Transmit Data Level */
#define SPI_O_DMARDLR       0x54 /* DMA Receive Data Level */
#define SPI_O_IDR           0x58 /* Identification Register */
#define SPI_O_SPI_VER_ID    0x5C /* CoreKit ID Register(0x3332322A) */
#define SPI_O_DATAREG       0x60 /* DATA Register */
#define SPI_O_DRS           0x64 /* More DATA Register */

/**
 * @brief The following are defines for the bit fields in the CTRLR0 register
 *
 */

#define SPI_CTRLR0_SPI_SSTE_S   24U
#define SPI_CTRLR0_SPI_SSTE_M   0x01000000U     /* Slave Select Toggle Enable */

#define SPI_CTRLR0_DFS_32_S     16U
#define SPI_CTRLR0_DFS_32_M     0x001F0000U     /* Data Frame Size */

#define SPI_CTRLR0_CFS_S        12U
#define SPI_CTRLR0_CFS_M        0x0000F000U     /* Control Frame Size in
                                                Microwire Format */

#define SPI_CTRLR0_SRL_M        0x00000800U     /* Shift Register Loop */

#define SPI_CTRLR0_SLV_OE_M     0x00000400U     /* Slave Output Enable */

#define SPI_CTRLR0_TMOD_S       8U
#define SPI_CTRLR0_TMOD_M       0x00000300U     /* Transfer Mode */

#define SPI_CTRLR0_SCPOL_S      7U
#define SPI_CTRLR0_SCPOL_M      0x00000080U     /* Serial Clock Polarity */

#define SPI_CTRLR0_SCPH_S       6U
#define SPI_CTRLR0_SCPH_M       0x00000040U     /* Serial Clock Phase */

#define SPI_CTRLR0_FRF_S        4U
#define SPI_CTRLR0_FRF_M        0x00000030U     /* Frame Format */

/**
 * @brief The following are defines for the bit fields in the CTRLR1 register
 *
 */

#define SPI_CTRLR1_NDF_M        0X0000FFFFU     /* Number of Data Frames */s

/**
 * @brief The following are defines for the bit fields in the SSIENR register
 *
 *
 */

#define SPI_SSIENR_SSIC_EN      0X00000001U     /* SPI Enable */

/**
 * @brief The following are defines for the bit fields in the MWCR register
 *
 *
 */

#define SPI_MWCR_MHS            0X00000004U     /* Microwire Handshaking
                                                (only in master mode and
                                                National Microwire Frame
                                                Format) */

#define SPI_MWCR_MDD            0X00000002U     /* Microwire Control */

#define SPI_MWCR_MWMOD          0X00000001U     /* Microwire Transfer Mode */

/**
 * @brief The following are defines for the bit fields in the SER register
 *
 *
 */

#define SPI_SER_SER             0X00000001U     /* Chip Select Enable Flag */

/**
 * @brief The following are defines for the bit fields in the BAUDR register
 *
 *
 */

#define SPI_BAUDR_SCKDV_M       0X0000FFFFU     /* SSI Clock Divider */

/**
 * @brief The following are defines for the bit fields in the TXFTLR register
 *
 *
 */

#define SPI_TXFTLR_TFT_M        0X0000000FU     /* Transmit FIFO Threshold */

/**
 * @brief The following are defines for the bit fields in the RXFTLR register
 *
 *
 */

#define SPI_RXFTLR_RFT_M        0X0000000FU     /* Receive FIFO Threshold */

/**
 * @brief The following are defines for the bit fields in the TXFLR register
 *
 *
 */

#define SPI_TXFLR_TXTFL_M       0X0000001FU     /* Transmit FIFO Level */

/**
 * @brief The following are defines for the bit fields in the RXFLR register
 *
 *
 */

#define SPI_RXFLR_RXTFL_M       0X0000001FU     /* Receive FIFO Level */

/**
 * @brief The following are defines for the bit fields in the SR register
 *
 *
 */

#define SPI_SR_DCOL             0X00000040U     /* Data Collision Error */

#define SPI_SR_TXE              0x00000020U     /* Transmission Error */

#define SPI_SR_RFF              0X00000010U     /* Receive FIFO Full */

#define SPI_SR_RFNE             0X00000008U     /* Receive FIFO Not Empty */

#define SPI_SR_TFE              0X00000004U     /* Transmit FIFO Empty */

#define SPI_SR_TFNF             0X00000002U     /* Transmit FIFO Not Full */

#define SPI_SR_BUSY             0X00000001U     /* SPI Busy Flag */

/**
 * @brief The following are defines for the bit fields in the IMR register
 *
 *
 */

#define SPI_IMR_MSTIM           0X00000020U     /* Multi-Controller
                                                Contention Interrupt Mask */

#define SPI_IMR_RXFIM           0X00000010U     /* Receive FIFO Full
                                                Interrupt Mask */

#define SPI_IMR_RXOIM           0X00000008U     /* Receive FIFO Overflow
                                                Interrupt Mask */

#define SPI_IMR_RXUIM           0X00000004U     /* Receive FIFO Overflow
                                                Interrupt Mask */

#define SPI_IMR_TXOIM           0X00000002U     /* Transmit FIFO Overflow
                                                Interrupt Mask */

#define SPI_IMR_TXEIM           0X00000001U     /* Transmit FIFO Empty
                                                Interrupt Mask */

/**
 * @brief The following are defines for the bit fields in the ISR register
 *
 *
 */

#define SPI_ISR_MSTIS           0X00000020U     /* Multi-Controller Contention
                                                Interrupt Status */

#define SPI_ISR_RXFIS           0X00000010U     /* Receive FIFO Full
                                                Interrupt Status */

#define SPI_ISR_RXOIS           0X00000008U     /* Receive FIFO Overflow
                                                Interrupt Status */

#define SPI_ISR_RXUIS           0X00000004U     /* Receive FIFO Underflow
                                                Interrupt Status */

#define SPI_ISR_TXOIS           0X00000002U     /* Transmit FIFO Overflow
                                                Interrupt Status */

#define SPI_ISR_TXEIS           0X00000001U     /* Transmit FIFO Empty
                                                Interrupt Status */

/**
 * @brief The following are defines for the bit fields in the RISR register
 *
 *
 */

#define SPI_RISR_MSTIR          0X00000020U     /* Multi-Controller Contention
                                                Interrupt Status */

#define SPI_RISR_RXFIR          0X00000010U     /* Receive FIFO Full
                                                Interrupt Status */

#define SPI_RISR_RXOIR          0X00000008U     /* Receive FIFO Overflow
                                                Interrupt Status */

#define SPI_RISR_RXUIR          0X00000004U     /* Receive FIFO Underflow
                                                Interrupt Status */

#define SPI_RISR_TXOIR          0X00000002U     /* Transmit FIFO Overflow
                                                Interrupt Status */

#define SPI_RISR_TXEIR          0X00000001U     /* Transmit FIFO Empty
                                                Interrupt Status */


/**
 * @brief The following are defines for the bit fields in the TXOICR register
 *
 *
 */

#define SPI_TXOICR_TXOICR       0X00000001U     /* Clear Transmit FIFO
                                                Overflow Interrupt */

/**
 * @brief The following are defines for the bit fields in the TXOICR register
 *
 *
 */

#define SPI_RXOICR_RXOICR       0X00000001U     /* Clear Receive FIFO
                                                Overflow Interrupt */

/**
 * @brief The following are defines for the bit fields in the RXUICR register
 *
 *
 */

#define SPI_RXUICR_RXUICR       0X00000001U     /* Clear Receive FIFO
                                                Underflow Interrupt */

/**
 * @brief The following are defines for the bit fields in the MSTICR register
 *
 *
 */

#define SPI_MSTICR_RXOICR       0X00000001U     /* Clear Multi-Controller
                                                Contention Interrupt */

/**
 * @brief The following are defines for the bit fields in the ICR register
 *
 *
 */

#define SPI_ICR_ICR             0X00000001U     /* Clear Interrupts
                                                (Clear txo,rxu,rxo,mst interrupts*/

/**
 * @brief The following are defines for the bit fields in the DMACR register
 *
 *
 */

#define SPI_DMACR_TDMAE         0X00000002U     /* Transmit DMA Enable */

#define SPI_DMACR_RDMAE         0X00000001U     /* Receive DMA Enable */

/**
 * @brief The following are defines for the bit fields in the DMATDLR register
 *
 *
 */

#define SPI_DMATDLR_DMATDL_S    0U
#define SPI_DMATDLR_DMATDL_M    0X0000000FU     /* Transmit Data Level */

/**
 * @brief The following are defines for the bit fields in the DMARDLR register
 *
 *
 */

#define SPI_DMARDLR_DMARDL_S    0U
#define SPI_DMARDLR_DMARDL_M    0X0000000FU     /* Receive Data Level */

/**
 * @brief The following are defines for the bit fields in the IDR register
 *
 *
 */

#define SPI_IDR_IDCODE_S        0U
#define SPI_IDR_IDCODE_M        0XFFFFFFFFU     /* Identification code */

/**
 * @brief The following are defines for the bit fields in the SSI_VERSION_ID register
 *
 *
 */

#define SPI_SSI_VERSION_ID_SSI_VERSION_ID_S     0U
#define SPI_SSI_VERSION_ID_SSI_VERSION_ID_M     0XFFFFFFFFU /* Contains the hex representation
                                                            of the Synopsys component version */

/**
 * @brief The following are defines for the bit fields in the DR0 register
 *
 *
 */

#define SPI_DR0_DR_S            0U
#define SPI_DR0_DR_M            0XFFFFFFFFU     /* Data Register */

#endif

