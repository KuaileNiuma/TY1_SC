/** 
  ************************************************************************************* 
  * @file spi.h 
  * @brief This file contains the definition of spi driver. 
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

#ifndef _SPI_H_
#define _SPI_H_

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

/* Includes ------------------------------------------------------------------*/

#include "hw_common.h"
#include "hw_spi.h"
#include "sysctl.h"

/**
  * @brief SPI (SPI)
  */
typedef struct {
    __IOM uint32_t CTRLR0;      /* Offset: 0x000 (R/W)  Control register 0 */
    __IOM uint32_t CTRLR1;      /* Offset: 0x004 (R/W)  Control register 1 */
    __IOM uint32_t SPIENR;      /* Offset: 0x008 (R/W)  SPI enable regiseter */
//          uint32_t RESERVED1;   /* Offset: 0x00C                             */
    __IOM uint32_t MWCR;        /* Offset: 0x00C (R/W)  Microwire control register*/
    __IOM uint32_t SER;         /* Offset: 0x010 (R/W)  Slave enable register */
    __IOM uint32_t BAUDR;       /* Offset: 0x014 (R/W)  Baud rate select */
    __IOM uint32_t TXFTLR;      /* Offset: 0x018 (R/W)  Transmit FIFO Threshold Level */
    __IOM uint32_t RXFTLR;      /* Offset: 0x01c (R/W)  Receive FIFO Threshold Level */
    __IOM uint32_t TXFLR;       /* Offset: 0x020 (R/W)  Transmit FIFO Level register */
    __IOM uint32_t RXFLR;       /* Offset: 0x024 (R/W)  Receive FIFO Level Register */
    __IOM uint32_t SR;          /* Offset: 0x028 (R/W)  status register */
    __IOM uint32_t IMR;         /* Offset: 0x02C (R/W)  Interrupt Mask Register */
    __IM  uint32_t ISR;         /* Offset: 0x030 (R/W)  interrupt status register */
    __IM  uint32_t RISR;        /* Offset: 0x034 (R/W)  Raw Interrupt Status Register */
    __IM  uint32_t TXOICR;      /* Offset: 0x038 (R/W)  Transmit FIFO Overflow Interrupt Clear Register */
    __IM  uint32_t RXOICR;      /* Offset: 0x03C (R/W)  Receive FIFO Overflow Interrupt Clear Register*/
    __IM  uint32_t RXUICR;      /* Offset: 0x040 (R/W)  Receive FIFO Underflow Interrupt Clear Register */
    __IM  uint32_t MSTICR;      /* Offset: 0x044 (R/W)  Multi-Master Interrupt Clear Register */
    __IM  uint32_t ICR;         /* Offset: 0x048 (R/W)  Interrupt Clear Register */
    __IOM uint32_t DMACR;       /* Offset: 0x04C (R/W)  DMA Control Register */
    __IOM uint32_t DMATDLR;     /* Offset: 0x050 (R/W)  DMA Transmoit Data Level */
    __IOM uint32_t DMARDLR;     /* Offset: 0x054 (R/W)  DMA Receive Data Level */
    __IM  uint32_t IDR;         /* Offset: 0x058 (R  )  identification register */
    __IM  uint32_t VERSION;     /* Offset: 0x05C (R  )  version register */
    __IOM uint32_t DR;          /* Offset: 0x060 (R/W)  Data Register */
    __IOM uint32_t DRx[35];     /*DR1-DR35*/
    __IOM uint32_t RX_SAMPLE_DLY; /* Offset: 0x0f0 (R/W)  RX Sample Delay Register */
//    __IM  uint32_t RSVD;        /* Offset: 0x0fc (R  )  */

//    __IOM uint32_t MSSEL;       /* Offset: 0x0A0 (R/W)  SPI is Master or Slave Select Register */
} SPI_TypeDef;

/*
 * @brief Interrput Flag
 * Values that can be passed to
 * SPI_enableInterrupt(),
 * SPI_disableInterrupt(),
 * and SPI_clearInterruptStatus()
 * as the intFlags parameter, and returned by
 * SPI_getInterruptStatus().
 */

/* ========================================================================== */
/* ================                   SPI                    ================ */
/* ========================================================================== */

#define SPI_FIFO_MAX_LV                      16

/* SPI register bit definitions */

/* ============================     CTRLR0     ============================== */
#define SPI_CTRLR0_SSTE_Pos                  (14UL)
#define SPI_CTRLR0_SSTE_Msk                  (0x1000000UL)

#define SPI_CTRLR0_DFS_32_Pos                (16UL)
#define SPI_CTRLR0_DFS_32_Msk                (0x1E0000UL)

#define SPI_CTRLR0_CFS_Pos                   (12UL)
#define SPI_CTRLR0_CFS_Msk                   (0xF000UL)

#define SPI_CTRLR0_SRL_Pos                   (11UL)
#define SPI_CTRLR0_SRL_Msk                   (0x800UL)

#define SPI_CTRLR0_SLVOE_Pos                 (10UL)
#define SPI_CTRLR0_SLVOE_Msk                 (0x400UL)

#define SPI_CTRLR0_TMOD_Pos                  (8UL)
#define SPI_CTRLR0_TMOD_Msk                  (0x300UL)

#define SPI_CTRLR0_SCPOL_Pos                 (7UL)
#define SPI_CTRLR0_SCPOL_Msk                 (0x80UL)

#define SPI_CTRLR0_SCPH_Pos                  (6UL)
#define SPI_CTRLR0_SCPH_Msk                  (0x40UL)

#define SPI_CTRLR0_FRF_Pos                   (4UL)
#define SPI_CTRLR0_FRF_Msk                   (0x30UL)

#define SPI_CTRLR0_DFS_Pos                   (0UL)
#define SPI_CTRLR0_DFS_Msk                   (0xFUL)

/* ============================     CTRLR1     ============================== */
#define SPI_CTRLR1_NDF_Pos                   (0UL)
#define SPI_CTRLR1_NDF_Msk                   (0xFFFFUL)

/* ============================     SSIENR     ============================== */
#define SPI_SSIENR_SSI_EN_Pos                (0UL)
#define SPI_SSIENR_SSI_EN_Msk                (0x1UL)
#define SPI_SSIENR_SSI_ENABLE                SPI_SSIENR_SSI_EN_Msk
#define SPI_SSIENR_SSI_DISABLE               (0UL)

/* ============================      MWCR      ============================== */
#define SPI_MWCR_MHS_Pos                     (2UL)
#define SPI_MWCR_MHS_Msk                     (0x4UL)

#define SPI_MWCR_MOD_Pos                     (1UL)
#define SPI_MWCR_MOD_Msk                     (0x2UL)

#define SPI_MWCR_MWMOD_Pos                   (0UL)
#define SPI_MWCR_MWMOD_Msk                   (0x1UL)
/* ============================      SER       ============================== */
#define SPI_SER_Pos                          (0UL)
#define SPI_SER_Msk                          (0x1UL)
/* ============================     BAUDR      ============================== */
#define SPI_BAUDR_SCKDIV_Pos                 (0UL)
#define SPI_BAUDR_SCKDIV_Msk                 (0xFFFFUL)
/* ============================     TXFTLR     ============================== */
#define SPI_TXFTLR_TXFTHR_Pos                (16UL)
#define SPI_TXFTLR_TXFTHR_Msk                (0x1F0000UL)

#define SPI_TXFTLR_TFT_Pos                   (0UL)
#define SPI_TXFTLR_TFT_Msk                   (0x1FUL)
/* ============================     RXFTLR     ============================== */
#define SPI_RXFTLR_RFT_Pos                   (0UL)
#define SPI_RXFTLR_RFT_Msk                   (0x1FUL)
/* ============================     TXFLR      ============================== */
#define SPI_TXFTLR_TXTFL_Pos                 (0UL)
#define SPI_TXFTLR_TXTFL_Msk                 (0x3FUL)
/* ============================     RXFLR      ============================== */
#define SPI_RXFTLR_RXTFL_Pos                 (0UL)
#define SPI_RXFTLR_RXTFL_Msk                 (0x3FUL)
/* ============================       SR       ============================== */
#define SPI_SR_DCOL_Pos                      (6UL)
#define SPI_SR_DCOL_Msk                      (0x40UL)

#define SPI_SR_TXE_Pos                       (5UL)
#define SPI_SR_TXE_Msk                       (0x20UL)

#define SPI_SR_RFF_Pos                       (4UL)
#define SPI_SR_RFF_Msk                       (0x10UL)

#define SPI_SR_RFNE_Pos                      (3UL)
#define SPI_SR_RFNE_Msk                      (0x8UL)

#define SPI_SR_TFE_Pos                       (2UL)
#define SPI_SR_TFE_Msk                       (0x4UL)

#define SPI_SR_TFNF_Pos                      (1UL)
#define SPI_SR_TFNF_Msk                      (0x2UL)

#define SPI_SR_BUSY_Pos                      (0UL)
#define SPI_SR_BUSY_Msk                      (0x1UL)

/* ============================      IMR       ============================== */
#define SPI_IMR_MST_Pos                      (5UL)
#define SPI_IMR_MST_Msk                      (0x20UL)

#define SPI_IMR_RXF_Pos                      (4UL)
#define SPI_IMR_RXF_Msk                      (0x10UL)

#define SPI_IMR_RXO_Pos                      (3UL)
#define SPI_IMR_RXO_Msk                      (0x8UL)

#define SPI_IMR_RXU_Pos                      (2UL)
#define SPI_IMR_RXU_Msk                      (0x4UL)

#define SPI_IMR_TXO_Pos                      (1UL)
#define SPI_IMR_TXO_Msk                      (0x2UL)

#define SPI_IMR_TXE_Pos                      (0UL)
#define SPI_IMR_TXE_Msk                      (0x1UL)

/* ============================      ISR       ============================== */
#define SPI_ISR_MST_Pos                      (5UL)
#define SPI_ISR_MST_Msk                      (0x20UL)

#define SPI_ISR_RXF_Pos                      (4UL)
#define SPI_ISR_RXF_Msk                      (0x10UL)

#define SPI_ISR_RXO_Pos                      (3UL)
#define SPI_ISR_RXO_Msk                      (0x8UL)

#define SPI_ISR_RXU_Pos                      (2UL)
#define SPI_ISR_RXU_Msk                      (0x4UL)

#define SPI_ISR_TXO_Pos                      (1UL)
#define SPI_ISR_TXO_Msk                      (0x2UL)

#define SPI_ISR_TXE_Pos                      (0UL)
#define SPI_ISR_TXE_Msk                      (0x1UL)

/* ============================      RISR      ============================== */
#define SPI_RISR_MST_Pos                      (5UL)
#define SPI_RISR_MST_Msk                      (0x20UL)

#define SPI_RISR_RXF_Pos                      (4UL)
#define SPI_RISR_RXF_Msk                      (0x10UL)

#define SPI_RISR_RXO_Pos                      (3UL)
#define SPI_RISR_RXO_Msk                      (0x8UL)

#define SPI_RISR_RXU_Pos                      (2UL)
#define SPI_RISR_RXU_Msk                      (0x4UL)

#define SPI_RISR_TXO_Pos                      (1UL)
#define SPI_RISR_TXO_Msk                      (0x2UL)

#define SPI_RISR_TXE_Pos                      (0UL)
#define SPI_RISR_TXE_Msk                      (0x1UL)

/* ============================     TXOICR     ============================== */
/* ============================     RXOICR     ============================== */
/* ============================     RXUICR     ============================== */
/* ============================     MSTICR     ============================== */
/* ============================      ICR       ============================== */
/* ============================     DMACR      ============================== */
#define SPI_DMACR_TDMAE_Pos                   (1UL)
#define SPI_DMACR_TDMAE_Msk                   (0x2UL)

#define SPI_DMACR_RDMAE_Pos                   (0UL)
#define SPI_DMACR_RDMAE_Msk                   (0x1UL)
/* ============================    DMATDLR     ============================== */
#define SPI_DMATDLR_Pos                       (0UL)
#define SPI_DMATDLR_Msk                       (0xFUL)
/* ============================    DMARDLR     ============================== */
#define SPI_DMARDLR_Pos                       (0UL)
#define SPI_DMARDLR_Msk                       (0xFUL)
/* ============================      IDR       ============================== */
/* ============================    VERSION     ============================== */
/* ============================       DR       ============================== */
#define SPI_DR_Pos                            (0UL)
#define SPI_DR_Msk                            (0xFFFFUL)
/* ============================ RX_SAMPLE_DLY  ============================== */
#define SPI_RX_SAMPLE_DLY_RSD_Pos             (0UL)
#define SPI_RX_SAMPLE_DLY_RSD_Msk             (0xFFUL)
/* ============================     MSSEL      ============================== */
#define SPI_MSSEL_Pos                         (0UL)
#define SPI_MSSEL_Msk                         (0x1UL)

#define SPI_INT_RXFF                SPI_IMR_RXFIM //!< RX FIFO level interrupt
#define SPI_INT_TXFF                SPI_IMR_TXEIM //!< TX FIFO level interrupt
#define SPI_INT_RXFF_OVERFLOW       SPI_IMR_RXOIM //!< RX FIFO overflow

#define SPI_INT_TXFF_EMPTY          SPI_INT_TXFF
#define SPI_INT_TXFF_OF             SPI_IMR_TXOIM
#define SPI_INT_RXFF_UNDERFLOW      SPI_IMR_RXUIM
#define SPI_INT_RXFF_OF             SPI_INT_RXFF_OVERFLOW
#define SPI_INT_RXFF_FULL           SPI_INT_RXFF
#define SPI_INT_MST                 SPI_IMR_MSTIM

/*
 * @brief SPI mode bit register, master and slave mask
 * Values that can be passed to
 * SPI_setConfig().
 */
//#define SPI_CONFIG_REG              APB_COMM_PARA_BASE
#define SPI_MASTER_M                0x00000001U

/*
 * @brief SPI Master or Slave bit mask
 *
 * Values that can be passed to
 * SPI_setConfig().
 */
#define SPIA_CFG_MASTER_MASK        (0x01U)
#define SPIB_CFG_MASTER_MASK        (0x10U)
#define SPIC_CFG_MASTER_MASK        (0x100U)
#define SPID_CFG_MASTER_MASK        (0x1000U)
#define SPIE_CFG_MASTER_MASK        (0x1000U)

/*
 * @brief non-interrupt FIFO status flag
 *
 * Can be used to determine whether the SPI_getStatus() function returns to
 *
 * @param SPI_BUSY              SPI is communicating
 * @param SPI_TX_NOFULL         SPI TX FIFO contains one or more empty locations
 * @param SPI_TX_EMPTY          SPI TX FIFO is empty
 * @param SPI_RX_NOEMPTY        SPI RX FIFO contains one or more data
 * @param SPI_RX_FULL           SPI RX FIFO don't have more empty locations
 * @param SPI_TX_ERR            SPI TX FIFO is empty
 *                              when a transfer is satered in slave mode
 * @param SPI_DATA_COLLISION    CS is asserted by other master when as a master
 */
#define SPI_BUSY                    SPI_SR_BUSY
#define SPI_TX_NOFULL               SPI_SR_TFNF
#define SPI_TX_EMPTY                SPI_SR_TFE
#define SPI_RX_NOEMPTY              SPI_SR_RFNE
#define SPI_RX_FULL                 SPI_SR_RFF
#define SPI_TX_ERR                  SPI_SR_TXE
#define SPI_DATA_COLLISION          SPI_SR_TXE




/*
 * @brief This macro definition is used to transmit a byte of data
 */
#define SPI_transmitByte(base, txData)                                         \
                                SPI_pollingNonFIFOTransaction(base, 8U,  txData)

/*
 * @brief This macro definition is used to transmit a 16-bit word of data
 */
#define SPI_transmit16Bits(base, txData)                                       \
                                SPI_pollingNonFIFOTransaction(base, 16U, txData)

/*
 * @brief This macro definition can be used to transmit 'N' bytes of data
 */
#define SPI_transmitNBytes(base, txBuffer, numOfWords, txDelay)                \
      SPI_pollingFIFOTransaction(base, 8U,  txBuffer, NULL, numOfWords, txDelay)

/*
 * @brief This macro definition can be used to transmit 'N' 16-bit words of data
 */
#define SPI_transmitN16BitWord(base, txBuffer, numOfWords, txDelay)            \
      SPI_pollingFIFOTransaction(base, 16U, txBuffer, NULL, numOfWords, txDelay)

/*
 * @brief This macro definition can be used to transmit 'N' with configurable
 * SPI character length
 */
#define SPI_transmitNWordsWithCharLength(base, charLength, txBuffer,           \
                                         numOfWords, txDelay)                  \
              SPI_pollingFIFOTransaction(base, charLength, txBuffer, NULL,     \
                                         numOfWords, txDelay)

/*
 * @brief This macro definition is used to receive a byte of data
 */
#define SPI_receiveByte(base, dummyData)                                       \
                            SPI_pollingNonFIFOTransaction(base, 8U, dummyData)

/*
 * @brief This macro is used to receive 'N' bytes of data
 */
#define SPI_receiveNBytes(base, rxBuffer, numOfWords, txDelay)                 \
      SPI_pollingFIFOTransaction(base, 8U,  NULL, rxBuffer, numOfWords, txDelay)

/*
 * @brief This macro is used to receive 'N' 16-bits words of data
 */
#define SPI_receiveN16BitWord(base, rxBuffer, numOfWords, txDelay)             \
      SPI_pollingFIFOTransaction(base, 16U, NULL, rxBuffer, numOfWords, txDelay)

/*
 * @brief This macro is used to receive 'N' words with specified character length
 */
#define SPI_receiveNWordsWithcharLength(base, charLength, rxBuffer,            \
                                        numOfWords, txDelay)                   \
            SPI_pollingFIFOTransaction(base, charLength, NULL, rxBuffer,       \
                                       numOfWords, txDelay)

/*
 * @brief Enumeration value used for SPI function
 */

/*
 * @brief SPI clock  Polarity and Phase.
 *
 * Values that can be passed to SPI_setConfig() as the protocol parameter.
 *
 * @param SPI_PROT_POL0PHA0  Inactive state of serial clock is low,
 *                           Data is collected at the rising edge
 * @param SPI_PROT_POL0PHA1  Inactive state of serial clock is low,
 *                           Data is collected at the falling edge
 * @param SPI_PROT_POL1PHA0  Inactive state of serial clock is high,
 *                           Data is collected at the rising edge
 * @param SPI_PROT_POL1PHA1  Inactive state of serial clock is high,
 *                           Data is collected at the falling edge
 *
 */
typedef enum
{
    //! Mode 0. Polarity 0, phase 0. Rising edge with delay.
    SPI_PROT_POL0PHA0   = 0x00000000U,
    //! Mode 1. Polarity 0, phase 1. Rising edge without delay.
    SPI_PROT_POL0PHA1   = 0x00000040U,
    //! Mode 2. Polarity 1, phase 0. Falling edge with delay.
    SPI_PROT_POL1PHA0   = 0x00000080U,
    //! Mode 3. Polarity 1, phase 1. Falling edge without delay.
    SPI_PROT_POL1PHA1   = 0x000000C0U
} SPI_TransferProtocol;

/*
 * @brief SPI mode and transmitting power
 *
 * Values that can be passed to SPI_setConfig() as the mode parameter.
 *
 * @param SPI_MODE_PERIPHERAL       SPI as slave,Transmit & Receive
 * @param SPI_MODE_CONTROLLER       SPI as master,Transmit & Receive
 * @param SPI_MODE_PERIPHERAL_OD    SPI as slave,only Receive
 * @param SPI_MODE_PERIPHERAL_OD    SPI as master,only Receive
 * @param SPI_MODE_PERIPHERAL_OD    SPI as slave,only Transmit
 * @param SPI_MODE_PERIPHERAL_OD    SPI as master,only Transmit
 * @param SPI_MODE_PERIPHERAL_OD    SPI as slave,eeprom mode
 */
typedef enum
{
    SPI_MODE_PERIPHERAL         = 0x00000000U,
    SPI_MODE_CONTROLLER         = 0x00000001U,
    SPI_MODE_PERIPHERAL_ID      = 0x00000100U,  /* Input disable  */
    SPI_MODE_CONTROLLER_ID      = 0x00000101U,  /* Input disable  */
    SPI_MODE_PERIPHERAL_OD      = 0x00000200U,  /* Output disable */
    SPI_MODE_CONTROLLER_OD      = 0x00000201U,  /* Output disable */
    SPI_MODE_CONTROLLER_EEPROM  = 0x00000301U   /* EEPROM mode  */
} SPI_Mode;

/*
 * @brief Tx FIFO level
 *
 * Values that can be passed to SPI_setFIFOInterruptLevel() as the txLevel
 * Values that can be passed to SPI_setFIFOInterruptLevel() as the txLevel
 * parameter, and returned by SPI_getTxFIFOStatus().
 *
 * @param SPI_FIFO_TXEMPTY  TX FIFO is empty or
 *                          TX FIFO threshold level = 0.
 * @param SPI_FIFO_TX0      0 word in the TX FIFO or
 *                          TX FIFO threshold level = 0.
 * @param SPI_FIFO_TX1      1 word in the TX FIFO or
 *                          TX FIFO threshold level = 1.
 * @param SPI_FIFO_TX2      2 word in the TX FIFO or
 *                          TX FIFO threshold level = 2.
 * @param SPI_FIFO_TX3      3 word in the TX FIFO or
 *                          TX FIFO threshold level = 3.
 * @param SPI_FIFO_TX4      4 word in the TX FIFO or
 *                          TX FIFO threshold level = 4.
 * @param SPI_FIFO_TX5      5 word in the TX FIFO or
 *                          TX FIFO threshold level = 5.
 * @param SPI_FIFO_TX6      6 word in the TX FIFO or
 *                          TX FIFO threshold level = 6.
 * @param SPI_FIFO_TX7      7 word in the TX FIFO or
 *                          TX FIFO threshold level = 7.
 * @param SPI_FIFO_TX8      8 word in the TX FIFO or
 *                          TX FIFO threshold level = 8.
 * @param SPI_FIFO_TX9      9 word in the TX FIFO or
 *                          TX FIFO threshold level = 9.
 * @param SPI_FIFO_TX10     10 word in the TX FIFO or
 *                          TX FIFO threshold level = 10.
 * @param SPI_FIFO_TX11     11 word in the TX FIFO or
 *                          TX FIFO threshold level = 11.
 * @param SPI_FIFO_TX12     12 word in the TX FIFO or
 *                          TX FIFO threshold level = 12.
 * @param SPI_FIFO_TX13     13 word in the TX FIFO or
 *                          TX FIFO threshold level = 13.
 * @param SPI_FIFO_TX14     14 word in the TX FIFO or
 *                          TX FIFO threshold level = 14.
 * @param SPI_FIFO_TX15     15 word in the TX FIFO or
 *                          TX FIFO threshold level = 15.
 * @param SPI_FIFO_TX16     16 word in the TX FIFO or
 *                          TX FIFO threshold level = 16.
 * @param SPI_FIFO_TXFULL   TX FIFO is full or
 *                          TX FIFO threshold level = 16.
 *
 */
typedef enum
{
    SPI_FIFO_TXEMPTY    = 0x0000U,      //!< Transmit FIFO empty
    SPI_FIFO_TX0        = 0x0000U,      //!< Transmit FIFO empty
    SPI_FIFO_TX1        = 0x0001U,      //!< Transmit FIFO 1/16 full
    SPI_FIFO_TX2        = 0x0002U,      //!< Transmit FIFO 2/16 full
    SPI_FIFO_TX3        = 0x0003U,      //!< Transmit FIFO 3/16 full
    SPI_FIFO_TX4        = 0x0004U,      //!< Transmit FIFO 4/16 full
    SPI_FIFO_TX5        = 0x0005U,      //!< Transmit FIFO 5/16 full
    SPI_FIFO_TX6        = 0x0006U,      //!< Transmit FIFO 6/16 full
    SPI_FIFO_TX7        = 0x0007U,      //!< Transmit FIFO 7/16 full
    SPI_FIFO_TX8        = 0x0008U,      //!< Transmit FIFO 8/16 full
    SPI_FIFO_TX9        = 0x0009U,      //!< Transmit FIFO 9/16 full
    SPI_FIFO_TX10       = 0x000AU,      //!< Transmit FIFO 10/16 full
    SPI_FIFO_TX11       = 0x000BU,      //!< Transmit FIFO 11/16 full
    SPI_FIFO_TX12       = 0x000CU,      //!< Transmit FIFO 12/16 full
    SPI_FIFO_TX13       = 0x000DU,      //!< Transmit FIFO 13/16 full
    SPI_FIFO_TX14       = 0x000EU,      //!< Transmit FIFO 14/16 full
    SPI_FIFO_TX15       = 0x000FU,      //!< Transmit FIFO 15/16 full
    SPI_FIFO_TX16       = 0x0010U,      //!< Transmit FIFO full
    SPI_FIFO_TXFULL     = 0x0010U       //!< Transmit FIFO full
} SPI_TxFIFOLevel;

/*
 * @brief Rx FIFO level
 *
 * Values that can be passed to SPI_setFIFOInterruptLevel() as the rxLevel
 * parameter, returned by SPI_getFIFOInterruptLevel() in the rxLevel
 * parameter, and returned by SPI_getRxFIFOStatus().
 *
 * @param SPI_FIFO_RXEMPTY  RX FIFO is empty or
 *                          RX FIFO threshold level = 0.
 * @param SPI_FIFO_RX0      0 word in the RX FIFO or
 *                          RX FIFO threshold level = 0.
 * @param SPI_FIFO_RX1      1 word in the RX FIFO or
 *                          RX FIFO threshold level = 1.
 * @param SPI_FIFO_RX2      2 word in the RX FIFO or
 *                          RX FIFO threshold level = 2.
 * @param SPI_FIFO_RX3      3 word in the RX FIFO or
 *                          RX FIFO threshold level = 3.
 * @param SPI_FIFO_RX4      4 word in the RX FIFO or
 *                          RX FIFO threshold level = 4.
 * @param SPI_FIFO_RX5      5 word in the RX FIFO or
 *                          RX FIFO threshold level = 5.
 * @param SPI_FIFO_RX6      6 word in the RX FIFO or
 *                          RX FIFO threshold level = 6.
 * @param SPI_FIFO_RX7      7 word in the RX FIFO or
 *                          RX FIFO threshold level = 7.
 * @param SPI_FIFO_RX8      8 word in the RX FIFO or
 *                          RX FIFO threshold level = 8.
 * @param SPI_FIFO_RX9      9 word in the RX FIFO or
 *                          RX FIFO threshold level = 9.
 * @param SPI_FIFO_RX10     10 word in the RX FIFO or
 *                          RX FIFO threshold level = 10.
 * @param SPI_FIFO_RX11     11 word in the RX FIFO or
 *                          RX FIFO threshold level = 11.
 * @param SPI_FIFO_RX12     12 word in the RX FIFO or
 *                          RX FIFO threshold level = 12.
 * @param SPI_FIFO_RX13     13 word in the RX FIFO or
 *                          RX FIFO threshold level = 13.
 * @param SPI_FIFO_RX14     14 word in the RX FIFO or
 *                          RX FIFO threshold level = 14.
 * @param SPI_FIFO_RX15     15 word in the RX FIFO or
 *                          RX FIFO threshold level = 15.
 * @param SPI_FIFO_RX16     16 word in the RX FIFO or
 *                          RX FIFO threshold level = 16.
 * @param SPI_FIFO_RXFULL   RX FIFO is full or
 *                          RX FIFO threshold level = 16.
 */
typedef enum
{
    SPI_FIFO_RXEMPTY    = 0x0000U,      //!< Receive FIFO empty
    SPI_FIFO_RX0        = 0x0000U,      //!< Receive FIFO empty
    SPI_FIFO_RX1        = 0x0001U,      //!< Receive FIFO 1/16 full
    SPI_FIFO_RX2        = 0x0002U,      //!< Receive FIFO 2/16 full
    SPI_FIFO_RX3        = 0x0003U,      //!< Receive FIFO 3/16 full
    SPI_FIFO_RX4        = 0x0004U,      //!< Receive FIFO 4/16 full
    SPI_FIFO_RX5        = 0x0005U,      //!< Receive FIFO 5/16 full
    SPI_FIFO_RX6        = 0x0006U,      //!< Receive FIFO 6/16 full
    SPI_FIFO_RX7        = 0x0007U,      //!< Receive FIFO 7/16 full
    SPI_FIFO_RX8        = 0x0008U,      //!< Receive FIFO 8/16 full
    SPI_FIFO_RX9        = 0x0009U,      //!< Receive FIFO 9/16 full
    SPI_FIFO_RX10       = 0x000AU,      //!< Receive FIFO 10/16 full
    SPI_FIFO_RX11       = 0x000BU,      //!< Receive FIFO 11/16 full
    SPI_FIFO_RX12       = 0x000CU,      //!< Receive FIFO 12/16 full
    SPI_FIFO_RX13       = 0x000DU,      //!< Receive FIFO 13/16 full
    SPI_FIFO_RX14       = 0x000EU,      //!< Receive FIFO 14/16 full
    SPI_FIFO_RX15       = 0x000FU,      //!< Receive FIFO 15/16 full
    SPI_FIFO_RX16       = 0x0010U,      //!< Receive FIFO full
    SPI_FIFO_RXFULL     = 0x0010U,      //!< Receive FIFO full
    SPI_FIFO_RXDEFAULT  = 0x001FU       //!< To prevent interrupt at reset
} SPI_RxFIFOLevel;

/*
 * @brief Endian
 *
 * Values that can be passed to
 * SPI_receive16Bits(),
 * SPI_receive24Bits(),
 * SPI_receive32Bits()
 *
 * @param SPI_DATA_LITTLE_ENDIAN    LITTLE ENDIAN
 * @param SPI_DATA_BIG_ENDIAN       BIG ENDIAN
 */
typedef enum
{
    SPI_DATA_LITTLE_ENDIAN   = 0U,
    SPI_DATA_BIG_ENDIAN   = 1U,
} SPI_endianess;

/*
 * @brief Frame Format
 * Values that can be passed to
 * SPI_setFrameFormat()
 *
 * @param MOTOROLA_SPI  Motorola SPI Frame Format
 * @param TEXAS_SSP     Texas Instruments SSP Frame Format
 * @param NS_MICROWIRE  National Microwire Frame Format
 */
typedef enum
{
    MOTOROLA_SPI = 0,
    TEXAS_SSP = 1,
    NS_MICROWIRE = 2
}SPI_FRAME_FORMAT;

typedef enum {
    BSPI1_MASTER = SYSCTL_BSPI1_MASTER_EN,
    BSPI2_MASTER = SYSCTL_BSPI2_MASTER_EN,
    BSPI3_MASTER = SYSCTL_BSPI3_MASTER_EN,
    BSPI4_MASTER = SYSCTL_BSPI4_MASTER_EN,
    BSPI1_SLAVE  = SYSCTL_BSPI1_SLAVE_EN,
    BSPI2_SLAVE  = SYSCTL_BSPI2_SLAVE_EN,
    BSPI3_SLAVE  = SYSCTL_BSPI3_SLAVE_EN,
    BSPI4_SLAVE  = SYSCTL_BSPI4_SLAVE_EN,
}eBSPI_t;

__STATIC_INLINE bool SPI_isBaseValid(uint32_t base)
{
    return(
           (base == SPI1_BASE) ||
           (base == SPI2_BASE) ||
           (base == SPI3_BASE)
          );
}

/*
 * @brief set the SPI control mode
 *
 * This function set the SPI control mode: master or slave.
 *
 * @param base  specifies the SPI module base address.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_setModeControl(eBSPI_t modeControl)
{
	SysCtl_setSPIxMode(modeControl);
}
/*
 * @brief Enables the SPI module.
 *
 * This function enables operation of the SPI module.
 * The SPI module must be configured before it is enabled.
 *
 * @param base  specifies the SPI module base address.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_enableModule(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_SSIENR) |= SPI_SSIENR_SSIC_EN;
}

/*
 * @brief Disables the SPI module.
 *
 * This function disables operation of the SPI module.
 * Call this function before doing any configuration.
 *
 * @param base  specifies the SPI module base address.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_disableModule(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_SSIENR) &= (~SPI_SSIENR_SSIC_EN);
}

/*
 * @brief Sets the character length of SPI transaction
 *
 * This function configures the character length of SPI transaction.\
 * SPI character length can be from anywhere between 4-bit word to 32 bit word
 * of character length.
 *
 * @param base  specifies the SPI module base address.
 * @param charLength specifies the character length of SPI transaction.
 *
 * @retuen None.
 */
__STATIC_INLINE void
SPI_setcharLength(uint32_t base, uint16_t charLength)
{
    ASSERT((charLength >= 4U) && (charLength <= 32U));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) = (HWREG(base+SPI_O_CTRLR0) & ~SPI_CTRLR0_DFS_32_M) |
                               ((charLength - 1) << SPI_CTRLR0_DFS_32_S);
    SPI_enableModule(base);
}

/*
 * @brief Resets the transmit FIFO.
 *
 * This function to clear TX FIFO buffer.
 *
 * @param base  specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_resetTxFIFO(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    SPI_enableModule(base);
}

/*
 * @brief Resets the receive FIFO.
 *
 * This function to clear RX FIFO buffer.
 *
 * @param base  specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_resetRxFIFO(uint32_t base)
{

    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    SPI_enableModule(base);
}

/*
 * @brief Sets the FIFO level at which interrupts are generated.
 *
 * This function sets the FIFO level at which transmit and receive interrupts
 * are generated.
 *
 * @param base  specifies the SPI module base address.
 * @param txLevel   is the transmit FIFO interrupt level, specified as
 * SPI_FIFO_TX0,SPI_FIFO_TX1,SPI_FIFO_TX2, . . . or SPI_FIFO_TX16.
 * @param rxLevel   is the receive FIFO interrupt level, specified as
 * SPI_FIFO_RX0,SPI_FIFO_RX1,SPI_FIFO_RX2, . . . or SPI_FIFO_RX16.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_setFIFOInterruptLevel(uint32_t base, SPI_TxFIFOLevel txLevel,
                          SPI_RxFIFOLevel rxLevel)
{

    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));


    /*Set the FIFO interrupt levels.*/
    if(txLevel == 16)
    {
        HWREG(base+SPI_O_TXFTLR) = (HWREG(base+SPI_O_TXFTLR) & (~SPI_TXFTLR_TFT_M)) \
                            | (uint16_t)(txLevel-1);
    }
    else
    {
        HWREG(base+SPI_O_TXFTLR) = (HWREG(base+SPI_O_TXFTLR) & (~SPI_TXFTLR_TFT_M)) \
                                    | (uint16_t)txLevel;
    }
    if(rxLevel)
    {
        HWREG(base+SPI_O_RXFTLR) = (HWREG(base+SPI_O_RXFTLR) & (~SPI_RXFTLR_RFT_M)) \
                            | (uint16_t)(rxLevel-1);
    }
    else
    {
        HWREG(base+SPI_O_RXFTLR) = (HWREG(base+SPI_O_RXFTLR) & (~SPI_RXFTLR_RFT_M)) \
                            | (uint16_t)rxLevel;
    }

}

/*
 * @brief  Gets the FIFO level at which interrupts are generated.
 *
 * This function gets the FIFO level at which transmit and receive interrupts
 * are generated.
 *
 * @param base specifies the SPI module base address.
 * @param txLevel is a pointer to storage for the transmit FIFO level,
 * returned as one of SPI_FIFO_TX0,SPI_FIFO_TX1, . . . or SPI_FIFO_TX16.
 * @param rxLevel is a pointer to storage for the receive FIFO level,
 * returned as one of SPI_FIFO_RX0,SPI_FIFO_RX1, . . . or SPI_FIFO_RX16.
 */
__STATIC_INLINE void
SPI_getFIFOInterruptLevel(uint32_t base, SPI_TxFIFOLevel *txLevel,
                          SPI_RxFIFOLevel *rxLevel)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    *txLevel = (SPI_TxFIFOLevel)((uint16_t)(HWREG(base+SPI_O_TXFTLR) &
                                SPI_TXFTLR_TFT_M));
    *rxLevel = (SPI_RxFIFOLevel)((uint16_t)(HWREG(base+SPI_O_RXFTLR) &
                                SPI_RXFTLR_RFT_M));
}

/*
 * @brief Get the transmit FIFO status
 *
 * This function gets the current number of words in the transmit FIFO.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Returns the current number of words in the transmit FIFO specified
 * as one of the following:
 * SPI_FIFO_TX0,SPI_FIFO_TX1,SPI_FIFO_TX2,..., or SPI_FIFO_TX16
 *
 */
__STATIC_INLINE SPI_TxFIFOLevel
SPI_getTxFIFOStatus(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    return (SPI_TxFIFOLevel)((uint16_t)(HWREG(base+SPI_O_TXFLR) & SPI_TXFLR_TXTFL_M));
}

/*
 * @brief Get the receive FIFO status
 *
 * This function gets the current number of words in the receive FIFO.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Returns the current number of words in the receive FIFO specified
 * as one of the following:
 * SPI_FIFO_RX0,SPI_FIFO_RX1,SPI_FIFO_RX2,..., or SPI_FIFO_RX16
 *
 */
__STATIC_INLINE SPI_RxFIFOLevel
SPI_getRxFIFOStatus(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    return (SPI_RxFIFOLevel)((uint16_t)(HWREG(base+SPI_O_RXFLR) & SPI_RXFLR_RXTFL_M));
}

/*
 * @brief Determines whether the SPI transmitter is busy or not.
 *
 * This function to get the BUSY flag in the SR register.
 * Determine whether the SPI is busy.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Return true indicates that SPI is transmitting
 *                false indicates that SPI transfer is complete
 *
 * @note Before polling the BUSY status, you should first poll
 * the TFE status (waiting for 1).
 */
__STATIC_INLINE bool
SPI_isBusy(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    return((HWREG(base+SPI_O_SR) & SPI_SR_BUSY));
}

/*
 * @brief Puts a data element into the SPI transmit buffer.
 *
 * This function places the supplied data into the transmit buffer of the
 * specified SPI module.
 *
 * @param base specifies the SPI module base address.
 * @param data is the right-justified data to be transmitted over SPI.
 *
 * @return None.
 *
 * @ note This function only transmit 4-16bit data.
 */
__STATIC_INLINE void
SPI_writeDataNonBlocking(uint32_t base, uint16_t data)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREGH(base+SPI_O_DATAREG) = data;
}

/*
 * @brief Gets a data element from the SPI receive buffer.
 *
 * This function gets received data from the receive buffer of the specified
 * SPI module and returns it.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Returns the word of data read from the SPI receive buffer.
 *
 * @ note This function only receive 4-16bit data.
 */
__STATIC_INLINE uint16_t
SPI_readDataNonBlocking(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    return(HWREGH(base+SPI_O_DATAREG));
}

/*
 * @brief Waits for space in the FIFO and then puts data
 * into the transmit buffer.
 *
 * This function places the supplied data into the transmit buffer of the
 * specified SPI module once space is available in the transmit FIFO.
 *
 * @param base specifies the SPI module base address.
 * @param data is the right-justified data to be transmitted over SPI.
 *
 * @retuen None.
 *
 * @ note This function only transmit 4-16bit data.
 */
__STATIC_INLINE void
SPI_writeDataBlockingFIFO(uint32_t base, uint16_t data)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));


    /*
     * Wait until space is available in the receive FIFO.
     */

    while(SPI_getTxFIFOStatus(base) == SPI_FIFO_TXFULL)
    {
    }

    HWREGH(base+SPI_O_DATAREG) = data;
}

/*
 * @brief Waits for data in the FIFO and then reads it
 * from the receive buffer.
 *
 * This function waits until there is data in the receive FIFO
 * and then reads received data from the receive buffer.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Returns the word of data read from the SPI receive buffer.
 *
 * @ note This function only receive 4-16bit data.
 */
__STATIC_INLINE uint16_t
SPI_readDataBlockingFIFO(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    /*
     * Wait until data is available in the receive FIFO.
     */
    while(SPI_getRxFIFOStatus(base) == SPI_FIFO_RXEMPTY)
    {
    }

    //
    // Check for data to read.
    //
    return(HWREGH(base+SPI_O_DATAREG));
}

/*
 * @brief Puts a data element into the SPI transmit buffer.
 *
 * This function places the supplied data into the transmit buffer of the
 * specified SPI module.
 *
 * @param base specifies the SPI module base address.
 * @param data is the right-justified data to be transmitted over SPI.
 *
 * @return None.
 *
 * @ note This function only transmit 4-32bit data.
 *        Uses this function When data >= 16bit.
 */
__STATIC_INLINE void
SPI_writeDataNonBlocking32(uint32_t base, uint32_t data)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREGH(base+SPI_O_DATAREG) = data;
}

/*
 * @brief Gets a data element from the SPI receive buffer.
 *
 * This function gets received data from the receive buffer of the specified
 * SPI module and returns it.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Returns the word of data read from the SPI receive buffer.
 *
 * @ note This function can receive 4-32bit data.
 */
__STATIC_INLINE uint32_t
SPI_readDataNonBlocking32(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    return(HWREG(base+SPI_O_DATAREG));
}

/*
 * @brief Waits for space in the FIFO and then puts data
 * into the transmit buffer.
 *
 * This function places the supplied data into the transmit buffer of the
 * specified SPI module once space is available in the transmit FIFO.
 *
 * @param base specifies the SPI module base address.
 * @param data is the right-justified data to be transmitted over SPI.
 *
 * @retuen None.
 *
 * @note This function can transmit 4-32bit data.
 */
__STATIC_INLINE void
SPI_writeDataBlockingFIFO32(uint32_t base, uint32_t data)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));


    /*
     * Wait until space is available in the receive FIFO.
     */

    while(SPI_getTxFIFOStatus(base) == SPI_FIFO_TXFULL)
    {
    }

    HWREG(base+SPI_O_DATAREG) = data;
}


/*
 * @brief Waits for data in the FIFO and then reads it
 * from the receive buffer.
 *
 * This function waits until there is data in the receive FIFO
 * and then reads received data from the receive buffer.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Returns the word of data read from the SPI receive buffer.
 *
 * @ note This function can receive 4-32bit data.
 *        Uses this function When data >= 16bit.
 */
__STATIC_INLINE uint32_t
SPI_readDataBlockingFIFO32(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    /*
     * Wait until data is available in the receive FIFO.
     */
    while(SPI_getRxFIFOStatus(base) == SPI_FIFO_RXEMPTY)
    {
    }

    //
    // Check for data to read.
    //
    return(HWREG(base+SPI_O_DATAREG));
}

/*
 * @brief Enables SPI loopback mode.
 *
 * This function enables loopback mode.
 * Used for  testing purposes only
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableLoopback(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_CTRLR0) |= SPI_CTRLR0_SRL_M;

}

/*
 * @brief Disables SPI loopback mode.
 *
 * This function disables loopback mode.
 * Loopback mode is disabled by default after reset.
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableLoopback(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_CTRLR0) &= ~SPI_CTRLR0_SRL_M;

}

/*
 * @brief  Enable CS to select slave
 *
 * This function to enable CS ,the corresponding slave select line from
 * the master is activated when a serial transfer begins.
 *
 * @param base is the base address of the SPI port.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableCS(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_SER) |= SPI_SER_SER;
}

/*
 * @brief  Disable CS to select slave
 *
 * This function to disable CS ,the corresponding slave select line from
 * the master is disactivated when a serial transfer begins.
 *
 * @param base is the base address of the SPI port.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableCS(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_SER) &= ~SPI_SER_SER;
}

/*
 * @brief Slave select toggle enable.
 *
 * This function allow CS will toggle between consecutive data frames
 *
 * @param base is the base address of the SPI port.
 */
__STATIC_INLINE void
SPI_enableCSToggle(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) |= SPI_CTRLR0_SPI_SSTE_M;
    SPI_enableModule(base);
}

/*
 * @brief Slave select toggle disable.
 *
 * This function disallow CS will toggle between consecutive data frames
 *
 * @param base is the base address of the SPI port.
 */
__STATIC_INLINE void
SPI_disableCSToggle(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) &= ~SPI_CTRLR0_SPI_SSTE_M;
    SPI_enableModule(base);
}

/*
 * @brief Enable trasnmit
 *
 * This function sets the TALK bit enabling the data trasnmission.
 * Used in the slave mode only.
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableTalk(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) &= ~SPI_CTRLR0_TMOD_M;
    SPI_enableModule(base);
}

/*
 * @brief Disable trasnmit
 *
 * This function clears the TALK bit disabling the data trasnmission.
 * Used in the slave mode only.
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableTalk(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) = (HWREG(base+SPI_O_CTRLR0) & (~SPI_CTRLR0_TMOD_M))|\
                               (0x00000020U);
    SPI_enableModule(base);
}

/*
 * @brief Enable slave output
 *
 * This function to enable output when SPI in the slave mode
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableSlaveOutput(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) &= ~SPI_CTRLR0_SLV_OE_M;
    SPI_enableModule(base);
}

/*
 * @brief Disable slave output
 *
 * This function to disable output when SPI in the slave mode
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableSlaveOutput(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) |= SPI_CTRLR0_SLV_OE_M;
    SPI_enableModule(base);
}

/*
 * @brief Clear SPI transmit and receive FIFO buffers
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_reset(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    SPI_enableModule(base);
}

/*
 * @brief Enables individual SPI interrupt sources.
 *
 * This function enables the indicated SPI interrupt sources.
 * Only the sources that are enabled can be reflected
 * to the processor interrupt;disabled sources have no effect
 * on the processor.
 * The intFlags parameter can be any of the following values:
 * - SPI_IMR_TXEIM
 * - SPI_IMR_TXOIM
 * - SPI_IMR_RXUIM
 * - SPI_IMR_RXOIM
 * - SPI_IMR_RXFIM
 * - SPI_IMR_MSTIM
 * The following macro definitions are used to be compatible
 * with the above macro definitions:
 * - SPI_INT_RXFF
 * - SPI_INT_TXFF
 * - SPI_INT_RXFF_OVERFLOW
 * - SPI_INT_TXFF_EMPTY
 * - SPI_INT_TXFF_OF
 * - SPI_INT_RXFF_UNDERFLOW
 * - SPI_INT_RXFF_OF
 * - SPI_INT_RXFF_FULL
 * - SPI_INT_MST
 *
 *
 * @param base specifies the SPI module base address.
 * @param intFlags is a bit mask of the interrupt sources to be enabled.
 *
 * @note All interrupts are unmasked after reset
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableInterrupt(uint32_t base, uint32_t intFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // enable corresponding interrupt
    //
    HWREG(base+SPI_O_IMR) |= intFlags;
}

/*
 * @brief Disables individual SPI interrupt sources.
 *
 * This function disables the indicated SPI interrupt sources.
 * Only the sources that are enabled can be reflected
 * to the processor interrupt;disabled sources have no effect
 * on the processor.
 * The intFlags parameter can be any of the following values:
 * - SPI_IMR_TXEIM
 * - SPI_IMR_TXOIM
 * - SPI_IMR_RXUIM
 * - SPI_IMR_RXOIM
 * - SPI_IMR_RXFIM
 * - SPI_IMR_MSTIM
 * The following macro definitions are used to be compatible
 * with the above macro definitions:
 * - SPI_INT_RXFF
 * - SPI_INT_TXFF
 * - SPI_INT_RXFF_OVERFLOW
 * - SPI_INT_TXFF_EMPTY
 * - SPI_INT_TXFF_OF
 * - SPI_INT_RXFF_UNDERFLOW
 * - SPI_INT_RXFF_OF
 * - SPI_INT_RXFF_FULL
 * - SPI_INT_MST
 *
 *
 * @param base specifies the SPI module base address.
 * @param intFlags is a bit mask of the interrupt sources to be enabled.
 *
 * @note All interrupts are unmasked after reset
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableInterrupt(uint32_t base, uint32_t intFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // enable corresponding interrupt
    //
    HWREG(base+SPI_O_IMR) &= (~intFlags);
}

/*
 * @brief Disables all SPI interrupt sources
 *
 * This function to disables all SPI interrupt sources
 * At initialization.
 *
 * @param base specifies the SPI module base address.
 *
 * @note All interrupts are enabled after a reset,
 * so you need to use the SPI_disableAllInterrupt function to
 * disable all interrupts and then use the SPI_enableInterrupt
 * function to enable the required interrupts.
 */
__STATIC_INLINE void
SPI_disableAllInterrupt(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // Clear SR register
    //
    HWREG(base+SPI_O_IMR) = 0;
}

/*
 * @brief get the interrupts that are enabled
 */
__STATIC_INLINE uint32_t
SPI_getInterruptEnable(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // Clear SR register
    //
    return HWREG(base+SPI_O_IMR);
}

/*
 * @brief Gets the current interrupt status.
 *
 * This function returns the interrupt status for the SPI module.
 *
 * @param base specifies the SPI module base address.
 *
 * @return The current interrupt status, enumerated as a bit field of the
 * Interrupt Mask Register values.
 */
__STATIC_INLINE uint32_t
SPI_getInterruptStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // Get interrupt status
    //
    return (HWREG(base+SPI_O_ISR));
}

/*
 * @brief Clears SPI interrupt sources.
 *
 * This function clears the specified SPI interrupt sources so that they no
 * longer assert.
 * This function claer interrupts if any of the interrupts below are active.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Return  ICR register
 */
__STATIC_INLINE void
SPI_clearAllInterruptStatus(uint32_t base)
{
    /*
     *Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    (void)(HWREG(base+SPI_O_ICR));
}

/*
 * @brief Gets the raw interrupt status.
 *
 * This function returns the interrupt status for the SPI module.
 *
 * @param base specifies the SPI module base address.
 *
 * @return The current interrupt status, enumerated as a bit field of the
 * Raw Interrupt Mask Register values.
 */
__STATIC_INLINE uint32_t
SPI_getRawInterruptStatus(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    return (HWREG(base+SPI_O_RISR));
}

/*
 * @brief Gets the FIFO status that non-interrupt
 *
 * This function to get  status register.
 * The value indicate the current transfer status, FIFO status,
 * and any transmission/reception errors that may have occurred.
 * None of the bits in this register request an interrupt.
 *
 * @param base specifies the SPI module base address.
 *
 * @return Return The intFlags parameter can be any of the following values:
 * - SPI_BUSY
 * - SPI_TX_NOFULL
 * - SPI_TX_EMPTY
 * - SPI_RX_NOEMPTY
 * - SPI_RX_FULL
 * - SPI_TX_ERR
 * - SPI_DATA_COLLISION
 */
__STATIC_INLINE uint32_t
SPI_getStatus(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    return HWREG(base+SPI_O_SR);
}

/*
 * @brief Receive "N" words data
 *
 * This function to set the receive int the Receive only mode or EEPROM mode
 *
 * @param base specifies the SPI module base address.
 * @param ndf number of data frames.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_setRecievNumofDataFrame(uint32_t base,uint16_t num)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR1) = num;
    SPI_enableModule(base);
}



/* @brief Microwire frame format related operations */

/*
 * @brief Set control frame size
 *
 * This function to selects the length of the control word
 * for the Microwire frame format.
 *
 *
 */
__STATIC_INLINE void
SPI_setControlFrameSize(uint32_t base,uint16_t size)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));
    ASSERT((size>=1)&&(size<=16));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) = (HWREG(base+SPI_O_CTRLR0) & (~SPI_CTRLR0_CFS_M))|\
            ((uint32_t)size<<SPI_CTRLR0_CFS_S);
    SPI_enableModule(base);
}

/*
 * @brief Set Frame Format
 *
 * This function is set the frame format.
 *
 * @param base specifies the SPI module base address.
 * @param format specifies the frame format.
 *
 * @return None;
 *
 */
__STATIC_INLINE void
SPI_setFrameFormat(uint32_t base,SPI_FRAME_FORMAT format)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_CTRLR0) = (HWREG(base+SPI_O_CTRLR0) & (~SPI_CTRLR0_FRF_M))|\
            ((uint32_t)format<<SPI_CTRLR0_FRF_S);
    SPI_enableModule(base);
}

/*
 * @brief Enable microwire Handshaking
 *
 * This function to enable microwire handshaking.
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableMHandshaking(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_MWCR) |=  SPI_MWCR_MHS;
    SPI_enableModule(base);
}

/*
 * @brief Disable microwire Handshaking
 *
 * This function to disable microwire handshaking.
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableMHandshaking(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_MWCR) &=  (~SPI_MWCR_MHS);
    SPI_enableModule(base);
}

/*
 * @brief SPI transfer data
 *
 * This function to set SPI transer mode in the microwire mode.
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_setTransferData(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_MWCR) |=  SPI_MWCR_MDD;
    SPI_enableModule(base);
}

/*
 * @brief SPI receives data
 *
 * This function to set SPI receives mode in the microwire mode.
 *
 * @param base specifies the SPI module base address.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_setReceiveData(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_MWCR) &=  (~SPI_MWCR_MDD);
    SPI_enableModule(base);
}

/*
 * @brief Set sequential transfer mode
 *
 * This function to set spi sequential transfer mode in the microwire mode
 *
 * @param  base specifies the SPI module base address.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_enableSequentialMode(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_MWCR) |= SPI_O_MWCR;
    SPI_enableModule(base);
}

/*
 * @brief Set non-sequential transfer mode
 *
 * This function to set spi non-sequential transfer mode in the microwire mode
 *
 * @param  base specifies the SPI module base address.
 *
 * @return None.
 *
 */
__STATIC_INLINE void
SPI_disableSequentialMode(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    SPI_disableModule(base);
    HWREG(base+SPI_O_MWCR) &= (~SPI_O_MWCR);
    SPI_enableModule(base);
}

/*
 * @brief SPI use DMA to Transfer and Recieve.
 *
 */

/*
 * @brief enable transmit DMA .
 *
 * @param base is the base address of the SPI port.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableTransmitDMA(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_DMACR) |= SPI_DMACR_TDMAE;
}

/*
 * @brief disable transmit DMA .
 *
 * @param base is the base address of the SPI port.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableTransmitDMA(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_DMACR) &= ~SPI_DMACR_TDMAE;
}

/*
 * @brief enable receive DMA .
 *
 * @param base is the base address of the SPI port.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_enableReceiveDMA(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_DMACR) |= SPI_DMACR_RDMAE;
}

/*
 * @brief disable transmit DMA .
 *
 * @param base is the base address of the SPI port.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_disableReceiveDMA(uint32_t base)
{
    /*
     * Check the arguments.
     */
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_DMACR) &= ~SPI_DMACR_RDMAE;
}

/*
 * @brief Sets the TxFIFO level at which DMA transmit interrupts are generated.
 *
 * This function sets the FIFO level at which DMA transmit interrupts
 * are generated.
 *
 * @param base is the base address of the SPI port.
 * @param  level is the transmit FIFO interrupt level, specified as
 * SPI_FIFO_TX0,SPI_FIFO_TX1,SPI_FIFO_TX2,...SPI_FIFO_TX16.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_setDmaTxDataLevel(uint32_t base, SPI_TxFIFOLevel level)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_DMATDLR) = level;
}

/*
 * @brief Sets the RxFIFO level at which DMA receive interrupts are generated.
 *
 * This function sets the FIFO level at which DMA receive interrupts
 * are generated.
 *
 * @param base is the base address of the SPI port.
 * @param  level is the receive FIFO interrupt level, specified as
 * SPI_FIFO_RX0,SPI_FIFO_RX1,SPI_FIFO_RX2,...SPI_FIFO_RX16.
 *
 * @return None.
 */
__STATIC_INLINE void
SPI_setDmaRxDataLevel(uint32_t base, SPI_TxFIFOLevel level)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    HWREG(base+SPI_O_DMARDLR) = level-1;
}

/*
 * @brief Configures the serial peripheral interface.
 *
 * This function configures the serial peripheral interface.
 * It sets the SPI protocol, mode of operation, bit rate, and data width.
 *
 * @param base specifies the SPI module base address.
 * @param lspclkHz is the rate of the clock supplied to the SPI module
 * (APBCLK) in HZ.
 * @param protocol specifies the data transfer protocol.
 * @param mode specifies the mode of operation.
 * @param bitRate specifies the clock rate in Hz.
 * @param dataWidth specifies number of bits transferred per frame.
 *
 * The protocol parameter defines the data frame format.
 * The protocol parameter can be one of the following values:
 * SPI_PROT_POL0PHA0,SPI_PROT_POL0PHA1,SPI_PROT_POL1PHA0,SPI_PROT_POL1PHA1
 *
 * These frame formats encode the following polarity and phase configurations:
 * Polarity Phase       Mode
 *    0       0   SPI_PROT_POL0PHA0
 *    0       1   SPI_PROT_POL0PHA1
 *    1       0   SPI_PROT_POL1PHA0
 *    1       1   SPI_PROT_POL1PHA1
 *
 * The mode parameter defines the operating mode of the SPI module.
 * SPI module can operate as a controller or peripheral;
 * the SPI can also be configured to disable output on its serial
 * output line in the Slave mode.
 * The mode parameter can be one of the following values:
 * SPI_MODE_CONTROLLER,SPI_MODE_PERIPHERAL,SPI_MODE_PERIPHERAL_OD
 *
 * The \e bitRate parameter defines the bit rate for the SPI.
 * This bit rate must satisfy the following clock ratio criteria:
 *
 * - bitRate can be no greater than lspclkHz divided by 2
 *   in the Master mode.
 * - lspclkHz / bitRate cannot be greater than 65534.
 *
 * The dataWidth parameter defines the width of the data transfers and
 * can be a value between 4 and 32, inclusive.
 *
 * @note SPI operation should be disabled via SPI_disableModule() before any
 * changes to its configuration.
 *
 * @return
 */
extern void
SPI_setConfig(uint32_t base, uint32_t lspclkHz, SPI_TransferProtocol protocol,
              SPI_Mode mode, uint32_t bitRate, uint16_t dataWidth);

/*
 * @brief Configures the baud rate of the serial peripheral interface.
 *
 * This function configures the SPI baud rate.
 *
 * @param base specifies the SPI module base address.
 * @param lspclkHz is the rate of the clock supplied to the SPI module
 * (APBCLK) in HZ.
 * @param bitRate specifies the clock rate in Hz.
 *
 * This bit rate must satisfy the following clock ratio criteria:
 * - bitRate can be no greater than lspclkHz divided by 2
 *   in the Master mode.
 * - lspclkHz / bitRate cannot be greater than 65534.
 *
 * @return
 */
extern void
SPI_setBaudRate(uint32_t base, uint32_t lspclkHz, uint32_t bitRate);

/*
 * @brief Clears SPI interrupt sources.
 *
 * This function clears the specified SPI interrupt sources so that they no
 * longer assert.
 * This function must be called in the interrupt handler to
 * keep the interrupts from being triggered again immediately upon exit.
 * The intFlags parameter can consist of a bit field of the following values:
 * - SPI_INT_TXFF_OF
 * - SPI_INT_RXFF_UNDERFLOW
 * - SPI_INT_RXFF_OF
 * - SPI_INT_MST
 *
 * @param base specifies the SPI module base address.
 * @param intFlags is a bit mask of the interrupt sources to be cleared.
 *
 *
 * @return
 */
extern void
SPI_clearInterruptStatus(uint32_t base, uint32_t intFlags);

/*
 * @brief This function is used to initiate SPI transaction of
 * specified character length and 'N' words of transaction
 *
 * @param base specifies the SPI module base address.
 * @param charLength specifies the SPI character length of SPI transaction
 * @param pTxBuffer specifies the pointer to transmit buffer
 * @param pRxBuffer specifies the pointer to receive buffer
 * @param numOfWords specified the number of data to be transmitted / received
 *
 * @return
 */
extern void
SPI_pollingFIFOTransaction(uint32_t base, uint16_t charLength,
                           uint16_t *pTxBuffer, uint16_t *pRxBuffer,
                           uint16_t numOfWords);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __AC1005_HAL_SPI_H */


