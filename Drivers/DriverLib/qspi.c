/**
 *************************************************************************************
 * @file qspi.c
 * @brief This file implements the function of qspi driver.
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

#include "qspi.h"
#include "sysctl.h"

//*****************************************************************************
//
// QSPI Mask Definitions
//
//*****************************************************************************
#define TXFTLR_TFT_M                       ((uint32_t)0x0000001F)  //!< QSPI TXFTLR mask
#define TXFTLR_TXFTHR_M                 ((uint32_t)0x001F0000)  //!< QSPI TXFTLR TXFTHR mask
#define RXFTLR_RFT_M                       ((uint32_t)0x0000001F)  //!< QSPI RXFTLR mask
#define CTRLR0_IS_MST_M                ((uint32_t)0x80000000)  //!< QSPI CTRLR0 IS MST mask
#define CTRLR0_DWS_EN_M                ((uint32_t)0x02000000)  //!< QSPI CTRLR0 DWS enable mask
#define CTRLR0_HYPERBUS_EN_M           ((uint32_t)0x01000000)  //!< QSPI CTRLR0 hyperbus enable mask
#define CTRLR0_FRF_M                   ((uint32_t)0x00C00000)  //!< QSPI CTRLR0 FRF mask
#define CTRLR0_CFS_M                   ((uint32_t)0x000F0000)  //!< QSPI CRTLR0 CFS mask
#define CTRLR0_SSTE_M                  ((uint32_t)0x00004000)  //!< QSPI CTRLR0 SSTE mask
#define CTRLR0_SRL_M                   ((uint32_t)0x00002000)  //!< QSPI CTRLR0 shift register Loop mask
#define CTRLR0_SLV_OE_M                ((uint32_t)0x00001000)  //!< QSPI CTRLR0 SLV_OE mask
#define CTRLR0_TMOD_M                               ((uint32_t)0x00000C00)  //!< QSPI CTRLR0 TMOD mask
#define CTRLR0_SCPOL_M                 ((uint32_t)0x00000200)  //!< QSPI CTRLR0 SCPOL mask
#define CTRLR0_SCPH_M                  ((uint32_t)0x00000100)  //!< QSPI CTRLR0 SCPH mask
#define CTRLR0_DFS_M                                    ((uint32_t)0x0000001F)  //!< QSPI CTRLR0 DFS mask

//*****************************************************************************
//
// QSPI SPI_CTRLR0 Mask Definitions
//
//*****************************************************************************
#define SPI_CTRLR0_XIP_PREFETCH_EN_M   ((uint32_t)0x20000000)  //!< QSPI SPI_CTRLR0 XIP prefetch enable mask
#define SPI_CTRLR0_Mode_Bits_M         ((uint32_t)0x0C000000)  //!< QSPI SPI_CTRL0 Mode Bits mask
#define SPI_CTRLR0_RXDS_SIG_EN_M       ((uint32_t)0x02000000)  //!< QSPI SPI_CTRLR0 RXDS SIG enable mask
#define SPI_CTRLR0_DM_EN_M             ((uint32_t)0x01000000)  //!< QSPI SPI_CTRL0 data mask enable mask
#define SPI_CTRLR0_XIP_CNTU_XFER_EN_M  ((uint32_t)0x00200000)  //!< QSPI SPI_CTRLR0 XIP continuous transfer enable mask
#define SPI_CTRLR0_XIP_INST_EN_M       ((uint32_t)0x00100000)  //!< QSPI SPI_CTRL0 INST EN mask
#define SPI_CTRLR0_XIP_DFS_FIX_M       ((uint32_t)0x00080000)  //!< QSPI SPI_CTRL0 DFS FIX mask
#define SPI_CTRLR0_RXDS_EN_M           ((uint32_t)0x00040000)  //!< QSPI SPI_CTRLR0 RXDS EN mask
#define SPI_CTRLR0_INST_DDR_EN_M       ((uint32_t)0x00020000)  //!< QSPI SPI_CTRLR0 INST DDR EN mask
#define SPI_CTRLR0_DDR_EN_M            ((uint32_t)0x00010000)  //!< QSPI SPI_CTRLR0 DDR EN mask
#define SPI_CTRLR0_WAIT_CYCLE_M        ((uint32_t)0x0000F800)  //!< QSPI SPI_CTRLR0 WAIT CYCLES mask
#define SPI_CTRLR0_INST_L_M                     ((uint32_t)0x00000300)  //!< QSPI SPI_CTRLR0 INST_L mask
#define SPI_CTRLR0_Mode_Bits_EN_M      ((uint32_t)0x00000080)  //!< QSPI SPI_CTRL0 Mode Bits EN mask
#define SPI_CTRLR0_ADDR_L_M                     ((uint32_t)0x0000003C)  //!< QSPI SPI_CTRLR0 ADDR_L mask
#define SPI_CTRLR0_INSTADDRTYPE_M      ((uint32_t)0x00000003)  //!< QSPI SPI_CTRLR0 INSTADDRTYPE mask

//*****************************************************************************
//
// QSPI Reset Value Definitions
//
//*****************************************************************************
#define QSPI_CTRL0_RESET_VALUE            ((uint32_t)0x0000)      //!< CTRL0 register reset value
#define QSPI_CTRL1_RESET_VALUE            ((uint32_t)0x00)        //!< CTRL1 register reset value
#define QSPI_SSIEN_RESET_VALUE            ((uint32_t)0x00)        //!< SSIEN register reset value
#define QSPI_SLAEN_RESET_VALUE            ((uint32_t)0x00)        //!< SLAEN register reset value
#define QSPI_BAUDR_RESET_VALUE            ((uint32_t)0x00)        //!< BR register reset value
#define QSPI_TXFTL_RESET_VALUE            ((uint32_t)0x00)        //!< TFTL register reset value
#define QSPI_RXFTL_RESET_VALUE            ((uint32_t)0x00)        //!< RFTL register reset value
#define QSPI_TXFLR_RESET_VALUE            ((uint32_t)0x00)        //!< TFL register reset value
#define QSPI_RXFLR_RESET_VALUE            ((uint32_t)0x00)        //!< RFL register reset value
#define QSPI_STATS_RESET_VALUE            ((uint32_t)0x06)        //!< STATUS register reset value
#define QSPI_INTEN_RESET_VALUE            ((uint32_t)0x00)        //!< INTEN register reset value
#define QSPI_RXSPD_RESET_VALUE            ((uint32_t)0x00)        //!< RSD register reset value
#define QSPI_CTRLR_RESET_VALUE            ((uint32_t)0x200)       //!< SPI_CTRLR0 register reset value
#define QSPI_IOSWT_RESET_VALUE            ((uint32_t)0x00)        //!< IOSW register reset value

//*****************************************************************************
//
// QSPI XIP and Enable Definitions
//
//*****************************************************************************
#define QSPI_XIP_INCR_INST_M           ((uint32_t)0x0000FFFF)  //!< QSPI XIP INCR INST mask
#define QSPI_XIP_WRAP_INST_M           ((uint32_t)0x0000FFFF)  //!< QSPI XIP WRAP INST mask
#define QSPI_XIP_Little_Endian_M       ((uint32_t)0x00000002)  //!< QSPI XIP Little Endian mask
#define SSIENR_SSI_ENABLE                 ((uint32_t)0x00000001)  //!< QSPI SSI Enable
#define QSPI_XIP_Little_Endian_ENABLE     ((uint32_t)0x00000002)  //!< QSPI XIP Little Endian enable
#define QSPI_SLAVE_SELECT_ENABLE          ((uint32_t)0x00000001)  //!< QSPI slave select enable


void QSPI_enableModule(uint32_t base)
{
    HWREG(base+QSPI_O_SSIENR) = QSPI_SSIENR_SSI_ENABLE;
}

void QSPI_disableModule(uint32_t base)
{
    HWREG(base+QSPI_O_SSIENR) = QSPI_SSIENR_SSI_DISABLE;
}

void QSPI_setMode(uint32_t base,uint32_t mode)
{
    HWREG(base+QSPI_O_CTRLR0) = (HWREG(base+QSPI_O_CTRLR0) & (~QSPI_CTRLR0_TMOD_Msk)) | mode;
}

void QSPI_clearIntFlag(uint32_t base)
{
    HWREG(base+QSPI_O_ICR);
}

FlagStatus QSPI_checkIntFlag(uint32_t base,uint32_t flag)
{
    return (HWREG(base+QSPI_O_ISR) & flag);
}
/**
  * @brief  Initialize the QSPI according to the specified parameters in the QSPI_InitStruct.
  * @param  QSPI_InitStruct: pointer to a QSPI_InitTypeDef structure that
  *         contains the configuration information for the QSPI peripheral.
  * @retval None
  */
void QSPI_Init(uint32_t base,QSPI_InitTypeDef* QSPI_InitStruct)
{
  uint32_t tmpreg, tmpreg1;

  HWREG(base+QSPI_O_SSIENR) = 0;
  HWREG(base+QSPI_O_ICR);
  HWREG(base+QSPI_O_CTRLR0) = QSPI_CTRL0_RESET_VALUE;
  HWREG(base+QSPI_O_CTRLR1) = QSPI_CTRL1_RESET_VALUE;
  HWREG(base+QSPI_O_SSIENR) = QSPI_SSIEN_RESET_VALUE;
  HWREG(base+QSPI_O_SER) = QSPI_SLAEN_RESET_VALUE;
  HWREG(base+QSPI_O_BAUDR) = QSPI_BAUDR_RESET_VALUE;
  HWREG(base+QSPI_O_TXFTLR) = QSPI_TXFTL_RESET_VALUE;
  HWREG(base+QSPI_O_RXFTLR) = QSPI_RXFTL_RESET_VALUE;
  HWREG(base+QSPI_O_IMR) = QSPI_INTEN_RESET_VALUE;
  HWREG(base+QSPI_O_RSD) = QSPI_RXSPD_RESET_VALUE;
  HWREG(base+QSPI_O_SPI_CTRLR0) = QSPI_CTRLR_RESET_VALUE;

  //Set IO to QSPI
  SysCtl_setQSPIIOEnable();

  tmpreg = HWREG(base+QSPI_O_CTRLR0);

    tmpreg &= ~(CTRLR0_DFS_M | CTRLR0_FRF_M | CTRLR0_SCPH_M | CTRLR0_SCPOL_M |
                CTRLR0_TMOD_M | CTRLR0_SLV_OE_M | CTRLR0_SRL_M | CTRLR0_SSTE_M |
                CTRLR0_CFS_M | CTRLR0_FRF_M | CTRLR0_HYPERBUS_EN_M | CTRLR0_DWS_EN_M |
                CTRLR0_IS_MST_M);

  tmpreg |= QSPI_InitStruct->QSPI_ClockPhase | QSPI_InitStruct->QSPI_ClockPolarity |
              QSPI_InitStruct->QSPI_DataFrameSize;

  tmpreg1 = HWREG(base+QSPI_O_CTRLR0);

  tmpreg1 &= ~(SPI_CTRLR0_Mode_Bits_EN_M | SPI_CTRLR0_DDR_EN_M |
               SPI_CTRLR0_INST_DDR_EN_M | SPI_CTRLR0_RXDS_EN_M | SPI_CTRLR0_XIP_DFS_FIX_M |
                 SPI_CTRLR0_XIP_INST_EN_M | SPI_CTRLR0_XIP_CNTU_XFER_EN_M | SPI_CTRLR0_DM_EN_M |
                             SPI_CTRLR0_RXDS_SIG_EN_M | SPI_CTRLR0_XIP_PREFETCH_EN_M);

  HWREG(base+QSPI_O_BAUDR) = QSPI_InitStruct->QSPI_Clk_Div;

  HWREG(base+QSPI_O_CTRLR0) = tmpreg;

  HWREG(base+QSPI_O_SPI_CTRLR0) = tmpreg1;
}

/**
  * @brief  Set the data frame format for transmitting/receiving the data.
  * @param  FrameFormat: data frame format.
  *     @arg QSPI_FRF_STD: Standard SPI Format.
  *     @arg QSPI_FRF_DUAL: Dual SPI Format.
  *     @arg QSPI_FRF_QUAD: Quad SPI Format.
  * @retval None
  */
void QSPI_SetFrameFormat(uint32_t base,uint32_t FrameFormat)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_CTRLR0);
  tmpreg &= ~CTRLR0_FRF_M;
  tmpreg |= FrameFormat & CTRLR0_FRF_M;

  HWREG(base+QSPI_O_CTRLR0) = tmpreg;
}

/**
  * @brief  Set the mode of transfer for serial communication.
  * @param  TransMode: transfer mode.
  *     @arg QSPI_CTRLR0_TMOD_TX_AND_RX: Transmit & Receive.
  *     @arg QSPI_CTRLR0_TMOD_TX_ONLY: Transmit only mode.
  *     @arg QSPI_CTRLR0_TMOD_RX_ONLY: Receive only mode.
  *     @arg QSPI_CTRLR0_TMOD_EEPROM_READ: EEPROM Read mode.
  * @retval None
  */
void QSPI_SetTransMode(uint32_t base,uint32_t TransMode)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_CTRLR0);
  tmpreg &= ~CTRLR0_TMOD_M;
  tmpreg |= TransMode & CTRLR0_TMOD_M;

  HWREG(base+QSPI_O_CTRLR0) = tmpreg;
}

/**
  * @brief  Set the data frame size.
  *         Data frame size must be a multiple of 2 if data frame format is QSPI_FRF_DUAL.
  *         Data frame size must be a multiple of 4 if data frame format is QSPI_FRF_QUAD.
  * @param  DataFrmSize: data frame size.
  *     @arg QSPI_DataFrameSize_4b: 04-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_5b: 05-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_6b: 06-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_7b: 07-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_8b: 08-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_9b: 09-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_10b: 10-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_11b: 11-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_12b: 12-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_13b: 13-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_14b: 14-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_15b: 15-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_16b: 16-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_17b: 17-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_18b: 18-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_19b: 19-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_20b: 20-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_21b: 21-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_22b: 22-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_23b: 23-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_24b: 24-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_25b: 25-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_26b: 26-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_27b: 27-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_28b: 28-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_29b: 29-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_30b: 30-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_31b: 31-bit serial data transfer.
  *     @arg QSPI_DataFrameSize_32b: 32-bit serial data transfer.
  * @retval None
  */
void QSPI_SetDataFrameSize(uint32_t base,uint32_t DataFrmSize)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_CTRLR0);
  tmpreg &= ~CTRLR0_DFS_M;
  tmpreg |= DataFrmSize & CTRLR0_DFS_M;

  HWREG(base+QSPI_O_CTRLR0) = tmpreg;
}

/**
  * @brief  Set the number of data frame to be transfered.
  * @param  Num: number of data frame.
  * @retval None
  */
void QSPI_SetFrameNum(uint32_t base,uint16_t Num)
{
  HWREG(base+QSPI_O_CTRLR1) = Num - 1;
}

/**
  * @brief  Enable or disable all QSPI operations.
  * @param  NewState: new state of the QSPI.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_SSIEConfig(uint32_t base,FunctionalState NewState)
{
  if(NewState != DISABLE)
  {
    HWREG(base+QSPI_O_SSIENR) |= SSIENR_SSI_ENABLE;
  }
  else
  {
    HWREG(base+QSPI_O_SSIENR) &= ~SSIENR_SSI_ENABLE;
  }
    __DSB();
    __NOP();
}

/**
  * @brief  Enable or disable QSPI LoopBack Mode.
  * @param  NewState: new state of the QSPI.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_SRLConfig(uint32_t base,FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
      HWREG(base+QSPI_O_CTRLR0) |= QSPI_CTRLR0_SRL_TESTING;
    }
    else
    {
      HWREG(base+QSPI_O_CTRLR0) &= ~QSPI_CTRLR0_SRL_TESTING;
    }
      __DSB();
      __NOP();
};

/**
  * @brief  Enable or disable QSPI Slave select toggle between DataFrames.
  * @param  NewState: new state of the QSPI.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_SSTEConfig(uint32_t base,FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(base+QSPI_O_CTRLR0) |= QSPI_CTRLR0_SSTE_Msk;
    }
    else
    {
        HWREG(base+QSPI_O_CTRLR0) &= ~QSPI_CTRLR0_SSTE_Msk;
    }
      __DSB();
      __NOP();
};

/**
  * @brief  Get the number of valid data entries in the transmit FIFO.
  * @param  None
  * @retval The number of entries in transmit FIFO.
  */
uint8_t QSPI_ReadTxFIFOLevel(uint32_t base)
{
  return (uint8_t)HWREG(base+QSPI_O_TXFLR);
}

/**
  * @brief  Get the number of valid data entries in the receive FIFO.
  * @param  None
  * @retval The number of entries in receive FIFO.
  */
uint8_t QSPI_ReadRxFIFOLevel(uint32_t base)
{
  return (uint8_t)HWREG(base+QSPI_O_RXFLR);
}

/**
  * @brief  Set the level of entries at which the receive FIFO controller trigger an interrupt.
  * @param  Threshold: The level of entries in receive FIFO, should be 1 ~ QSPI_FIFO_DEPTH.
  * @retval None
  */
void QSPI_SetRxFIFOFullThreshold(uint32_t base,uint32_t Threshold)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_RXFTLR);
  tmpreg &= ~RXFTLR_RFT_M;
  tmpreg |= Threshold & RXFTLR_RFT_M;

  HWREG(base+QSPI_O_RXFTLR) = tmpreg;
}

/**
  * @brief  Set the level of entries above which the transfer will start on serial line.
  * @param  Threshold: The level of entries in transmit FIFO, should be 0 ~ (QSPI_FIFO_DEPTH - 1).
  * @retval None
  */
void QSPI_SetTxFIFOThreshold(uint32_t base,uint32_t Threshold)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_TXFTLR);
  tmpreg &= ~TXFTLR_TXFTHR_M;
  tmpreg |= (Threshold << 16) & TXFTLR_TXFTHR_M;

  HWREG(base+QSPI_O_TXFTLR) = tmpreg;
}

/**
  * @brief  Set the level of entries at which the transmit FIFO controller trigger an interrupt.
  * @param  Threshold: The level of entries in transmit FIFO, should be 0 ~ (QSPI_FIFO_DEPTH - 1).
  * @retval None
  */
void QSPI_SetTxFIFOEmptyThreshold(uint32_t base,uint8_t Threshold)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_TXFTLR);
  tmpreg &= ~TXFTLR_TFT_M;
  tmpreg |= Threshold & TXFTLR_TFT_M;

  HWREG(base+QSPI_O_TXFTLR) = tmpreg;
}

/**
  * @brief  Set the level of entries at which the receive FIFO controller generate a DMA request.
  * @param  Threshold: The level of entries in receive FIFO, should be 1 ~ QSPI_FIFO_DEPTH.
  * @retval None
  */
void QSPI_SetRxDMALevelFullThreshold(uint32_t base,uint8_t Threshold)
{
  HWREG(base+QSPI_O_DMARDLR) = Threshold;
}

/**
  * @brief  Set the level of entries at which the transmit FIFO controller generate a DMA request.
  * @param  Threshold: The level of entries in transmit FIFO, should be 0 ~ (QSPI_FIFO_DEPTH - 1).
  * @retval None
  */
void QSPI_SetTxDMALevelEmptyThreshold(uint32_t base,uint8_t Threshold)
{
  HWREG(base+QSPI_O_DMATDLR) = Threshold;
}

/**
  * @brief  Check whether the specified QSPI flag is set or not.
  * @param  QSPI_FLAG: specifies the flag to check.
  *   This parameter can be one of the following values:
  *     @arg QSPI_FLAG_BUSY: QSPI Busy Flag.
  *     @arg QSPI_FLAG_TFNF: Transmit FIFO not Full Flag.
  *     @arg QSPI_FLAG_TFE: Transmit FIFO Empty Flag.
  *     @arg QSPI_FLAG_RFNE: Receive FIFO not Empty Flag.
  *     @arg QSPI_FLAG_RFF: Receive FIFO Full Flag.
  *     @arg QSPI_FLAG_TXE: Transmission Error Flag.
  *     @arg QSPI_FLAG_DCE: Data Collision Error Flag.
  * @retval The new state of QSPI_FLAG (SET or RESET).
  */
FlagStatus QSPI_GetFlagStatus(uint32_t base,uint32_t QSPI_FLAG)
{
  FlagStatus tmpreg = RESET;

  tmpreg = HWREG(base+QSPI_O_SR) & QSPI_FLAG ? SET : RESET;

  return tmpreg;
}

/**
  * @brief  Set receive data sampling edge.
  * @param  SampleEdge: receive data sampling edge.
  *     @arg QSPI_RX_Sample_Edge_LOW: Negative edge of ssi_clk will be used to sample the incoming data.
  *     @arg QSPI_RX_Sample_Edge_HIGH: Positive edge of ssi_clk will be used to sample the incoming data.
  * @retval None
  */
void QSPI_SetRxSampleEdge(uint32_t base,uint32_t SampleEdge)
{
  HWREG(base+QSPI_O_RSD) |= SampleEdge;
}

/**
  * @brief  Set the receive data sampling delay.
  * @param  Delay: receive data sampling delay.
  * @retval None
  */
void QSPI_SetRxSampleDelay(uint32_t base,uint8_t Delay)
{
  HWREG(base+QSPI_O_RSD) |= Delay;
}

/**
  * @brief  Set the instruction length in bits.
  * @param  DataFrmSize: data frame size.
  *     @arg QSPI_Inst_Length_NoInst: No instruction.
  *     @arg QSPI_Inst_Length_4b: 4 bit instruction length.
  *     @arg QSPI_Inst_Length_8b: 8 bit instruction length.
  *     @arg QSPI_Inst_Length_16b: 16 bit instruction length.
  * @retval None
  */
void QSPI_SetInstLen(uint32_t base,uint32_t Len)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_SPI_CTRLR0);
  tmpreg &= ~SPI_CTRLR0_INST_L_M;
  tmpreg |= Len  & SPI_CTRLR0_INST_L_M;

  HWREG(base+QSPI_O_SPI_CTRLR0) = tmpreg;
}

/**
  * @brief  Set the length of address to be transmitted.
  * @param  DataFrmSize: data frame size.
  *     @arg QSPI_Addr_Length_NoAddr: No address.
  *     @arg QSPI_Addr_Length_4b: 4 bit address length.
  *     @arg QSPI_Addr_Length_8b: 8 bit address length.
  *     @arg QSPI_Addr_Length_12b: 16 bit address length.
  *     @arg QSPI_Addr_Length_16b: 16 bit address length.
  *     @arg QSPI_Addr_Length_20b: 20 bit address length.
  *     @arg QSPI_Addr_Length_24b: 24 bit address length.
  *     @arg QSPI_Addr_Length_28b: 28 bit address length.
  *     @arg QSPI_Addr_Length_32b: 32 bit address length.
  *     @arg QSPI_Addr_Length_36b: 36 bit address length.
  *     @arg QSPI_Addr_Length_40b: 40 bit address length.
  *     @arg QSPI_Addr_Length_44b: 44 bit address length.
  *     @arg QSPI_Addr_Length_48b: 48 bit address length.
  *     @arg QSPI_Addr_Length_52b: 52 bit address length.
  *     @arg QSPI_Addr_Length_56b: 56 bit address length.
  *     @arg QSPI_Addr_Length_60b: 60 bit address length.
  * @retval None
  */
void QSPI_SetAddrLen(uint32_t base,uint32_t Len)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_SPI_CTRLR0);
  tmpreg &= ~SPI_CTRLR0_ADDR_L_M;
  tmpreg |= Len & SPI_CTRLR0_ADDR_L_M;

  HWREG(base+QSPI_O_SPI_CTRLR0) = tmpreg;
}

/**
  * @brief  Set the address and instruction transfer format.
  * @param  Type: Type of the address and instruction transfer format.
  *     @arg QSPI_INST_ADDR_TYPE_STANDARD: Instruction and address will be sent in standard SPI mode.
  *     @arg QSPI_INST_TYPE_STANDARD: Instruction will be sent in standard SPI mode and address will
  *                                   be sent in the mode specified by QSPI_SetFrameFormat().
  *     @arg QSPI_INST_ADDR_TYPE_FRF: Both Instruction and address will be sent in the mode specified
  *                                   by QSPI_SetFrameFormat().
  * @retval None
  */
void QSPI_SetInstAddrType(uint32_t base,uint32_t Type)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_SPI_CTRLR0);
  tmpreg &= ~SPI_CTRLR0_INSTADDRTYPE_M;
  tmpreg |= Type & SPI_CTRLR0_INSTADDRTYPE_M;

  HWREG(base+QSPI_O_SPI_CTRLR0) = tmpreg;
}

/**
  * @brief  Set the wait cycles between control frames transmit and data reception.
  * @param  Cycle: Number of SPI clock cycles.
  * @retval None
  */
void QSPI_SetWaitCycle(uint32_t base,uint8_t Cycle)
{
  uint32_t tmpreg;

  tmpreg = HWREG(base+QSPI_O_SPI_CTRLR0);
  tmpreg &= ~SPI_CTRLR0_WAIT_CYCLE_M;
  tmpreg |= (Cycle << 11) & SPI_CTRLR0_WAIT_CYCLE_M;

  HWREG(base+QSPI_O_SPI_CTRLR0) = tmpreg;
}

/**
  * @brief  Read one byte from receive FIFO.
  * @param  None
  * @retval Pointer of data read from receive FIFO.
  */
void QSPI_RxDataU8(uint32_t base,uint8_t *Data)
{
  *Data = HWREG(base+QSPI_O_DR);
}

/**
  * @brief  Read one halfword from receive FIFO.
  * @param  None
  * @retval Pointer of data read from receive FIFO.
  */
void QSPI_RxDataU16(uint32_t base,uint16_t *Data)
{
  *Data = HWREG(base+QSPI_O_DR);
}

/**
  * @brief  Read one word from receive FIFO.
  * @param  None
  * @retval Pointer of data read from receive FIFO.
  */
void QSPI_RxDataU32(uint32_t base,uint32_t *Data)
{
  *Data = HWREG(base+QSPI_O_DR);
}

/**
  * @brief  Write one byte into transmit FIFO.
  * @param  Data: Pointer of data to be sent.
  * @retval None
  */
void QSPI_TxDataU8(uint32_t base,uint8_t *Data)
{
  HWREG(base+QSPI_O_DR) = *Data;
}

/**
  * @brief  Write one halfword into transmit FIFO.
  * @param  Data: Pointer of data to be sent.
  * @retval None
  */
void QSPI_TxDataU16(uint32_t base,uint16_t *Data)
{
  HWREG(base+QSPI_O_DR) = *Data;
}

/**
  * @brief  Write one word into transmit FIFO.
  * @param  Data: Pointer of data to be sent.
  * @retval None
  */
void QSPI_TxDataU32(uint32_t base,uint32_t *Data)
{
  HWREG(base+QSPI_O_DR) = *Data;
}

/**
  * @brief  Write instruction or address into transmit FIFO.
  * @param  InsOrAddr: Instruction or address to be sent.
  * @retval None
  */
void QSPI_TxInsAddr(uint32_t base,uint32_t InsOrAddr)
{
  HWREG(base+QSPI_O_DR) = InsOrAddr;
}

/**
  * @brief  Enable or disable the slave select line.
  * @param  NewState: new state of slave select line.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_SlaveConfig(uint32_t base,FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    HWREG(base+QSPI_O_SER) |= QSPI_SLAVE_SELECT_ENABLE;
  }
  else
  {
    HWREG(base+QSPI_O_SER) &= ~QSPI_SLAVE_SELECT_ENABLE;
  }
    __DSB();
    __NOP();
}

/**
  * @brief  Enable or disable the transmit FIFO DMA channel.
  * @param  NewState: new state of the transmit FIFO DMA channel.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_TxDMAConfig(uint32_t base,FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
    HWREG(base+QSPI_O_DMACR) |= QSPI_DMA_TDMAEN;
    }
    else
    {
    HWREG(base+QSPI_O_DMACR) &= ~QSPI_DMA_TDMAEN;
    }
    __DSB();
    __NOP();
}

/**
  * @brief  Enable or disable the receive FIFO DMA channel.
  * @param  NewState: new state of the receive FIFO DMA channel.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_RxDMAConfig(uint32_t base,FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
    HWREG(base+QSPI_O_DMACR) |= QSPI_DMA_RDMAEN;
    }
    else
    {
    HWREG(base+QSPI_O_DMACR) &= ~QSPI_DMA_RDMAEN;
    }
    __DSB();
    __NOP();
}


/**
  * @brief  Initialize the QSPI_XIP according to the specified parameters in the QSPI_XIP_InitTypeDef.
  * @param  QSPI_XIP_InitTypeDef: pointer to a QSPI_XIP_InitTypeDef structure that
  *         contains the configuration information for the QSPI XIP.
  * @retval None
  */
void QSPI_XIP_Init(uint32_t base,QSPI_XIP_InitTypeDef* QSPI_XIP_InitStruct)
{
    QSPI_SSIEConfig(base,DISABLE);
    QSPI_SlaveConfig(base,DISABLE);

    HWREG(base + QSPI_O_XIP_CTRL) = (HWREG(base + QSPI_O_XIP_CTRL) & ~(QSPI_XIP_CTRLR_INST_EN_Msk|QSPI_XIP_CTRLR_WAIT_CYCLES_Msk
            |QSPI_XIP_CTRLR_MD_BITS_EN_Msk|QSPI_XIP_CTRLR_INST_L_Msk|QSPI_XIP_CTRLR_ADDR_L_Msk
            |QSPI_XIP_CTRLR_XIP_MBL_Msk|QSPI_XIP_CTRLR_TRANS_TYPE_Msk|QSPI_XIP_CTRLR_FRF_Msk)) |
            (QSPI_XIP_InitStruct->QSPI_XIP_Inst_EN|QSPI_XIP_InitStruct->QSPI_XIP_Wait_Cycles
            |QSPI_XIP_InitStruct->QSPI_XIP_Mode_Bits_EN|QSPI_XIP_InitStruct->QSPI_XIP_Inst_Length
            |QSPI_XIP_InitStruct->QSPI_XIP_Addr_Length|QSPI_XIP_InitStruct->QSPI_XIP_Mode_Bits_Length
            |QSPI_XIP_InitStruct->QSPI_XIP_Trans_Type|QSPI_XIP_InitStruct->QSPI_XIP_FRF);

    HWREG(base + QSPI_O_XIP_INCR_INST) = (HWREG(base + QSPI_O_XIP_INCR_INST) & ~(QSPI_XIP_INCR_INST_Msk)) |
            (QSPI_XIP_InitStruct->QSPI_XIP_INCR_INST);

    HWREG(base + QSPI_O_XIP_WRAP_INST) = (HWREG(base + QSPI_O_XIP_WRAP_INST) & ~(QSPI_XIP_WRAP_INST_Msk)) |
            (QSPI_XIP_InitStruct->QSPI_XIP_WRAP_INST);

    HWREG(base + QSPI_O_XIP_MODE_BITS) = (HWREG(base + QSPI_O_XIP_MODE_BITS) & ~(QSPI_XIP_MODE_BITS_Msk)) |
            (QSPI_XIP_InitStruct->QSPI_XIP_Mode_Bits);

    HWREG(base + QSPI_O_XIP_SER) = (HWREG(base + QSPI_O_XIP_SER) & ~(QSPI_XIP_SER_Msk)) | (1);

    QSPI_SSIEConfig(base,ENABLE);
    QSPI_SlaveConfig(base,ENABLE);
    QSPI_configXIP(base,ENABLE);
}

/**
  * @brief  Enable or disable the QSPI XIP Mode.
  * @param  NewState: new state of the receive FIFO DMA channel.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_configXIP(uint32_t base,FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
      SysCtl_configXIP(SYSCTL_MSPI_XIP_EN);
    }
    else
    {
      SysCtl_configXIP(SYSCTL_MSPI_CFG_CLEAR);
    }
}

/**
  * @brief  Enable or disable the QSPI Interrupt.
  * @param  NewState: new state of the receive FIFO DMA channel.
  *   This parameter can be: ENABLE or DISABLE.
  * @param  intFlag: flag of Interrupt.
  *   This parameter can be:
  *    QSPI_IMR_RXFIM_Msk
  *    QSPI_IMR_TXEIM_Msk
  *    QSPI_IMR_TXOIM_Msk
  *    QSPI_IMR_RXUIM_Msk
  *    QSPI_IMR_RXOIM_Msk
  *    QSPI_IMR_MSTIM_Msk
  *    QSPI_IMR_XRXOIM_Msk
  * @retval None
  */
void QSPI_enableInterrupt(uint32_t base,uint32_t intFlag)
{
    HWREG(base+QSPI_O_IMR) = ((HWREG(base+QSPI_O_IMR)) & (~intFlag)) | intFlag;
}
void QSPI_disableInterrupt(uint32_t base,uint32_t intFlag)
{
    HWREG(base+QSPI_O_IMR) = ((HWREG(base+QSPI_O_IMR)) & (~intFlag));
}
/**
  * @}
  */

/**
  * @}
  */

