/** 
 *************************************************************************************
 * @file hw_i2c.h
 * @brief This file contains the definition of hw_i2c driver.
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

#ifndef _HW_I2C_H_
#define _HW_I2C_H_
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
//register offset
#define I2C_O_IC_CON    0x0
#define I2C_O_IC_TAR    0x4
#define I2C_O_IC_SAR    0x8
#define I2C_O_IC_DATA_CMD   0x10
#define I2C_O_IC_SS_SCL_HCNT    0x14
#define I2C_O_IC_SS_SCL_LCNT    0x18
#define I2C_O_IC_FS_SCL_HCNT    0x1c
#define I2C_O_IC_FS_SCL_LCNT    0x20
#define I2C_O_IC_INTR_STAT  0x2c
#define I2C_O_IC_INTR_MASK  0x30
#define I2C_O_IC_RAW_INTR_STAT  0x34
#define I2C_O_IC_RX_TL  0x38
#define I2C_O_IC_TX_TL  0x3c
#define I2C_O_IC_CLR_INTR   0x40
#define I2C_O_IC_CLR_RX_UNDER   0x44
#define I2C_O_IC_CLR_RX_OVER    0x48
#define I2C_O_IC_CLR_TX_OVER    0x4c
#define I2C_O_IC_CLR_RD_REQ 0x50
#define I2C_O_IC_CLR_TX_ABRT    0x54
#define I2C_O_IC_CLR_RX_DONE    0x58
#define I2C_O_IC_CLR_ACTIVITY   0x5c
#define I2C_O_IC_CLR_STOP_DET   0x60
#define I2C_O_IC_CLR_START_DET  0x64
#define I2C_O_IC_CLR_GEN_CALL   0x68
#define I2C_O_IC_ENABLE 0x6c
#define I2C_O_IC_STATUS 0x70
#define I2C_O_IC_TXFLR  0x74
#define I2C_O_IC_RXFLR  0x78
#define I2C_O_IC_SDA_HOLD   0x7c
#define I2C_O_IC_TX_ABRT_SOURCE 0x80
#define I2C_O_IC_DMA_CR 0x88
#define I2C_O_IC_DMA_TDLR   0x8c
#define I2C_O_IC_DMA_RDLR   0x90
#define I2C_O_IC_SDA_SETUP  0x94
#define I2C_O_IC_ACK_GENERAL_CALL   0x98
#define I2C_O_IC_ENABLE_STATUS  0x9c
#define I2C_O_IC_FS_SPKLEN  0xa0
#define I2C_O_IC_CLR_RESTART_DET    0xa8
#define I2C_O_IC_SCL_STUCK_AT_LOW_TIMEOUT   0xac

//register bit set
#define I2C_IC_ENABLE_ENABLE    0x01U
#define I2C_IC_ENABLE_ABORT 0x02U
#define I2C_IC_ENABLE_TX_CMD_BLOCK 0x04U
#define I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE 0x08U
#define I2C_IC_ENABLE_SMBUS_CLK_RESET   0x10000U
#define I2C_IC_ENABLE_SMBUS_SUSPEND_EN  0x20000U
#define I2C_IC_ENABLE_SMBUS_ALERT_EN    0x40000U
#define I2C_IC_ENABLE_IC_SAR2_EN    0x100000U

#define I2C_IC_TX_TL_TX_TL  0xFFU

#define I2C_IC_RX_TL_RX_TL  0xFFU

#define I2C_IC_TAR_IC_TAR   0x3FFU
#define I2C_IC_TAR_GC_OR_START  0x400U
#define I2C_IC_TAR_SPECIAL  0x800U
#define I2C_IC_TAR_SMBUS_QUICK_CMD  0x10000U

#define I2C_IC_SAR_IC_SAR   0x3FFU

#define I2C_IC_STATUS_ACTIVITY  0x01U
#define I2C_IC_STATUS_TFNF  0x02U
#define I2C_IC_STATUS_TFE   0x04U
#define I2C_IC_STATUS_RFNE  0x08U
#define I2C_IC_STATUS_RFF   0x10U
#define I2C_IC_STATUS_MST_ACTIVITY  0x20U
#define I2C_IC_STATUS_SLV_ACTIVITY  0x40U

#define I2C_IC_DATA_CMD_DAT     0xFFU
#define I2C_IC_DATA_CMD_CMD     0x100U
#define I2C_IC_DATA_CMD_STOP    0x200U
#define I2C_IC_DATA_CMD_RESTART 0x400U
#define I2C_IC_DATA_CMD_READ    I2C_IC_DATA_CMD_CMD

#define I2C_IC_CON_MASTER_MODE  0x01U
#define I2C_IC_CON_SPEEDL   0x02U
#define I2C_IC_CON_SPEEDH   0x04U
#define I2C_IC_CON_SPEED    0x06U
#define I2C_IC_CON_IC_10BITADDR_SLAVE   0x08U
#define I2C_IC_CON_IC_10BITADDR_MASTER  0x10U
#define I2C_IC_CON_IC_RESTART_EN    0x20U
#define I2C_IC_CON_IC_SLAVE_DISABLE 0x40U
#define I2C_IC_CON_STOP_DET_IFADDRESSED 0x80U
#define I2C_IC_CON_TX_EMPTY_CTRL    0x100U
#define I2C_IC_CON_RX_FIFO_FULL_HLD_CTRL    0x200U
#define I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE    0x400U
#define I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL   0x800U
#define I2C_IC_CON_SMBUS_SLAVE_QUICK_EN 0x2000U
#define I2C_IC_CON_SMBUS_ARP_EN 0x4000U
#define I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN 0x8000U
#define I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR2_EN    0x10000U
#define I2C_IC_CON_IC_SAR2_SMBUS_ARP_EN 0x800000U

//
//return value of I2C_getStatus, I2C_getInterruptStatus, I2C_getInterruptRawStatus
//
#define I2C_IC_INTR_STAT_RX_UNDER   0x01U
#define I2C_IC_INTR_STAT_RX_OVER    0x02U
#define I2C_IC_INTR_STAT_RX_FULL    0x04U
#define I2C_IC_INTR_STAT_TX_OVER    0x08U
#define I2C_IC_INTR_STAT_TX_EMPTY   0x10U
#define I2C_IC_INTR_STAT_RD_REQ 0x20U
#define I2C_IC_INTR_STAT_TX_ABRT    0x40U
#define I2C_IC_INTR_STAT_RX_DONE    0x80U
#define I2C_IC_INTR_STAT_ACTIVITY   0x100U
#define I2C_IC_INTR_STAT_STOP_DET   0x200U
#define I2C_IC_INTR_STAT_START_DET  0x400U
#define I2C_IC_INTR_STAT_GEN_CALL   0x800U
#define I2C_IC_INTR_STAT_RESTART_DET    0x1000U
#define I2C_IC_INTR_STAT_MASTER_ON_HOLD 0x2000U
#define I2C_IC_INTR_STAT_WR_REQ 0x8000U
#define I2C_IC_INTR_STAT_SLV_ADDR1_TAG  0x10000U

#define I2C_IC_TX_ABRT_SOURCE_NACK  0x1FU
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST  0x1000U

#define I2C_IC_INTR_MASK_M_RX_UNDER 0x01U
#define I2C_IC_INTR_MASK_M_RX_OVER  0x02U
#define I2C_IC_INTR_MASK_M_RX_FULL  0x04U
#define I2C_IC_INTR_MASK_M_TX_OVER  0x08U
#define I2C_IC_INTR_MASK_M_TX_EMPTY 0x10U
#define I2C_IC_INTR_MASK_M_RD_REQ   0x20U
#define I2C_IC_INTR_MASK_M_TX_ABRT  0x40U
#define I2C_IC_INTR_MASK_M_RX_DONE  0x80U
#define I2C_IC_INTR_MASK_M_ACTIVITY 0x100U
#define I2C_IC_INTR_MASK_M_STOP_DET 0x200U
#define I2C_IC_INTR_MASK_M_START_DET    0x400U
#define I2C_IC_INTR_MASK_M_GEN_CALL 0x800U
#define I2C_IC_INTR_MASK_M_RESTART_DET  0x1000U
#define I2C_IC_INTR_MASK_M_WR_REQ   0x8000U
#define I2C_IC_INTR_MASK_M_SLV_ADDR1_TAG    0x10000U

#define I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD  0xFFFFU
#define I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD  0xFF0000U

#define I2C_IC_SDA_SETUP_SDA_SETUP  0xFFU

#define I2C_IC_ACK_GENERAL_CALL 0x01U

#define I2C_IC_DMA_CR_RDMAE 0x01U
#define I2C_IC_DMA_CR_TDMAE 0x02U

#define I2C_IC_DMA_TDLR_DMATDL 0x07U
#define I2C_IC_DMA_RDLR_DMARDL 0x07U

#define I2C_IC_ENABLE_STATUS_IC_EN  0x01U
#define I2C_IC_ENABLE_STATUS_SLV_DISABLE_WHILE_BUSY  0x02U
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST  0x04U

#endif 
