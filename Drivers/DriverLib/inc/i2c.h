/** 
  ************************************************************************************* 
  * @file i2c.h
  * @brief This file contains the definition of i2c driver. 
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

#ifndef _I2C_H_
#define _I2C_H_

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
#include "hw_i2c.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
  * @brief I2C (I2C)
  */
typedef struct {
    __IOM uint32_t IC_CON;                    /* Offset: 0x000 (R/W)  I2C Control */
    __IOM uint32_t IC_TAR;                    /* Offset: 0x004 (R/W)  I2C target address */
    __IOM uint32_t IC_SAR;                    /* Offset: 0x008 (R/W)  I2C slave address  */
    __IOM uint32_t IC_HS_MADDR;               /* Offset: 0x00c (R/W)  I2C HS Master Mode Code Address */
    __IOM uint32_t IC_DATA_CMD;               /* Offset: 0x010 (R/W)  I2C RX/TX Data Buffer and Command */
    __IOM uint32_t IC_SS_SCL_HCNT;            /* Offset: 0x014 (R/W)  Standard speed I2C Clock SCL High Count */
    __IOM uint32_t IC_SS_SCL_LCNT;            /* Offset: 0x018 (R/W)  Standard speed I2C Clock SCL Low Count */
    __IOM uint32_t IC_FS_SCL_HCNT;            /* Offset: 0x01c (R/W)  Fast speed I2C Clock SCL High Count */
    __IOM uint32_t IC_FS_SCL_LCNT;            /* Offset: 0x020 (R/W)  Fast speed I2C Clock SCL Low Count */
    __IOM uint32_t IC_HS_SCL_HCNT;            /* Offset: 0x024 (R/W)  High speed I2C Clock SCL High Count*/
    __IOM uint32_t IC_HS_SCL_LCNT;            /* Offset: 0x028 (R/W)  High speed I2C Clock SCL Low Count */
    __IM  uint32_t IC_INTR_STAT;              /* Offset: 0x02c (R)    I2C Interrupt Status */
    __IOM uint32_t IC_INTR_MASK;              /* Offset: 0x030 (R/W)  I2C Interrupt Mask */
    __IM  uint32_t IC_RAW_INTR_STAT;          /* Offset: 0x034 (R)    I2C Raw Interrupt Status */
    __IOM uint32_t IC_RX_TL;                  /* Offset: 0x038 (R/W)  I2C Receive FIFO Threshold */
    __IOM uint32_t IC_TX_TL;                  /* Offset: 0x03c (R/W)  I2C Transmit FIFO Threshold */
    __IM  uint32_t IC_CLR_INTR;               /* Offset: 0x040 (R)    Clear combined and individual interrupts*/
    __IM  uint32_t IC_CLR_RX_UNDER;           /* Offset: 0x044 (R)    I2C Clear RX_UNDER interrupt  */
    __IM  uint32_t IC_CLR_RX_OVER;            /* Offset: 0x048 (R)    I2C Clear RX_OVER interrupt  */
    __IM  uint32_t IC_CLR_TX_OVER;            /* Offset: 0x04c (R)    I2C Clear TX_OVER interrupt  */
    __IM  uint32_t IC_CLR_RD_REQ;             /* Offset: 0x050 (R)    I2C Clear RD_REQ interrupt  */
    __IM  uint32_t IC_CLR_TX_ABRT;            /* Offset: 0x054 (R)    I2C Clear TX_ABRT interrupt  */
    __IM  uint32_t IC_CLR_RX_DONE;            /* Offset: 0x058 (R)    I2C Clear RX_DONE interrupt  */
    __IM  uint32_t IC_CLR_ACTIVITY;           /* Offset: 0x05c (R)    I2C Clear ACTIVITY interrupt  */
    __IM  uint32_t IC_CLR_STOP_DET;           /* Offset: 0x060 (R)    I2C Clear STOP_DET interrupt  */
    __IM  uint32_t IC_CLR_START_DET;          /* Offset: 0x064 (R)    I2C Clear START_DET interrupt  */
    __IM  uint32_t IC_CLR_GEN_CALL;           /* Offset: 0x068 (R)    I2C Clear GEN_CAL interrupt  */
    __IOM uint32_t IC_ENABLE;                 /* Offset: 0x06c (R/W)  I2C enable */
    __IM  uint32_t IC_STATUS;                 /* Offset: 0x070 (R)    I2C status register */
    __IM  uint32_t IC_TXFLR;                  /* Offset: 0x074 (R)    Transmit FIFO Level register */
    __IM  uint32_t IC_RXFLR;                  /* Offset: 0x078 (R)    Receive FIFO Level Register */
          uint32_t RESERVED;                  /* Offset: 0x07c (R/ )   */
    __IOM uint32_t IC_TX_ABRT_SOURCE;         /* Offset: 0x080 (R/W)  I2C Transmit Abort Status Register */
    __IOM uint32_t IC_SLV_DATA_NACK_ONLY;     /* Offset: 0x084 (R/W)  I2C Slave Address1 */
    __IOM uint32_t IC_DMA_CR;                 /* Offset: 0x088 (R/W)  DMA Control Register for transmit and receive handshaking interface  */
    __IOM uint32_t IC_DMA_TDLR;               /* Offset: 0x08c (R/W)  DMA Transmit Data Level */
    __IOM uint32_t IC_DMA_RDLR;               /* Offset: 0x090 (R/W)  DMA Receive Data Level */
    __IOM uint32_t IC_SDA_SETUP;              /* Offset: 0x094 (R/W)  I2C Slave Address2 */
    __IOM uint32_t IC_ACK_GENERAL_CALL;       /* Offset: 0x098 (R/W)  I2C Slave Address3 */
    __IOM uint32_t IC_ENABLE_STATUS;          /* Offset: 0x09c (R/W)  I2C address number in slave mode */
    __IOM uint32_t IC_FS_SPKLEN;              /* Offset: 0x0a0 (R/W)  I2C general call mask register when I2C is in the slave mode */
    __IOM uint32_t IC_HS_SPKLEN;              /* Offset: 0x0a4 (R/W)  I2C FIFO flush register when I2C is in the slave transfer mode*/
    __IOM uint32_t IC_CLR_RESTART_DET;        /* Offset: 0x0a8 (R/W)  The value n indicate the data on SDA will delay for n cycle of pclk 0~100 */
    __IOM uint32_t IC_SCL_STUCK_AT_LOW_TIMEOUT;            /* Offset: 0x0ac (R/W)  force the I2C return to IDLE state and stop the transaction right now */
    __IOM uint32_t IC_SDA_STUCK_AT_LOW_TIMEOUT;     /*0xb0*/
    __IOM uint32_t IC_CLR_SCL_STUCK_DET;     /*0xb4*/
    __IOM uint32_t IC_DEVICE_ID;             /*0xb8*/
    __IOM uint32_t IC_SMBUS_CLK_LOW_SEXT;    /*0xbc*/
    __IOM uint32_t IC_SMBUS_CLK_LOW_MEXT;    /*0xc0*/
    __IOM uint32_t IC_SMBUS_THIGH_MAX_IDLE_COUNT;    /*0xc4*/
    __IOM uint32_t IC_SMBUS_INTR_STAT;       /*0xc8*/
    __IOM uint32_t IC_SMBUS_INTR_MASK;       /*0xcc*/
    __IOM uint32_t IC_SMBUS_RAW_INTR_MASK;   /*0xd0*/
    __IOM uint32_t IC_CLR_SMBUS_INTR;        /*0xd4*/
    __IOM uint32_t IC_OPTIONAL_SAR;          /*0xd8*/
    __IOM uint32_t IC_SMBUS_UDID_WORD0;      /*0xdc*/
    __IOM uint32_t IC_SMBUS_UDID_WORD1;      /*0xe0*/
    __IOM uint32_t IC_SMBUS_UDID_WORD2;      /*0xe4*/
    __IOM uint32_t IC_SMBUS_UDID_WORD3;      /*0xe8*/
    __IOM uint32_t reserved1;                /*0xec*/
    __IOM uint32_t REG_TIMEOUT_RST;          /*0xf0*/
    __IOM uint32_t IC_COMP_PARAM_1;          /*0xf4*/
    __IOM uint32_t IC_COMP_VERSION;          /*0xf8*/
    __IOM uint32_t IC_COMP_TYPE;             /*0xfc*/
} I2C_TypeDef;

#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define I2C3                ((I2C_TypeDef *) I2C3_BASE)
#define I2C_RETRY_LIMIT    40000

//*****************************************************************************
//
// I2C config for use with the config parameter of I2C_setConfig().
//
//*****************************************************************************
#define I2C_MASTER_MODE             (I2C_IC_CON_MASTER_MODE | I2C_IC_CON_IC_SLAVE_DISABLE) //!< master mode
#define I2C_MASTER_SEND_MODE        I2C_MASTER_MODE //!< Controller-transmitter mode
#define I2C_MASTER_RECEIVE_MODE     I2C_MASTER_MODE //!< Controller-receiver mode
#define I2C_SLAVE_MODE              0
//#define I2C_TARGET_SEND_MODE        I2C_SLAVE_MODE //!< Target-transmitter mode
//#define I2C_TARGET_RECEIVE_MODE     I2C_SLAVE_MODE //!< Target-receiver mode
#define I2C_FAST_SPEED_MODE         I2C_IC_CON_SPEEDH //!< fast speed mode
#define I2C_STANDARD_SPEED_MODE     I2C_IC_CON_SPEEDL //!< standard speed mode
#define I2C_STOP_DET_IFADDRESSED    I2C_IC_CON_STOP_DET_IFADDRESSED //!< STOP_DET interrrupt only when it is addressed
#define I2C_TX_EMPTY_CTRL           I2C_IC_CON_TX_EMPTY_CTRL //!< TX_EMPTY interrupt when tx empty and shift register transmission completed.
#define I2C_RX_FIFO_FULL_HLD_CTRL   I2C_IC_CON_RX_FIFO_FULL_HLD_CTRL //!< HOLD BUS when Rx FIFO full to BUFFER_DEPTH
#define I2C_STOP_DET_IF_MASTER_ACTIVE     I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE //!< STOP_DET interrupt only when master is active
#define I2C_RESTART_EN              I2C_IC_CON_IC_RESTART_EN //!< enable restart condition
#define I2C_10BIT_ADDRESS           (I2C_IC_CON_IC_10BITADDR_MASTER | I2C_IC_CON_IC_10BITADDR_SLAVE)

#define I2C_CONTROLLER_MODE         (I2C_MASTER_MODE | I2C_RESTART_EN)
#define I2C_CONTROLLER_SEND_MODE    I2C_CONTROLLER_MODE
#define I2C_CONTROLLER_RECEIVE_MODE I2C_CONTROLLER_MODE
#define I2C_TARGET_MODE             (I2C_SLAVE_MODE | I2C_RESTART_EN)
#define I2C_TARGET_SEND_MODE        I2C_TARGET_MODE
#define I2C_TARGET_RECEIVE_MODE     I2C_TARGET_MODE
#define I2C_REPEAT_MODE             0

//*****************************************************************************
//
// Input parameter intFlags for I2C_enableInterrupt();
//                              I2C_disableInterrupt();
// Returned value for I2C_getInterruptStatus();
//                    I2C_getInterruptRawStatus();
//                    I2C_getStatus();
//
//*****************************************************************************
#define I2C_INT_ARB_LOST        I2C_IC_INTR_STAT_TX_ABRT //!< Arbitration-lost interrupt
#define I2C_INT_NO_ACK          I2C_IC_INTR_STAT_TX_ABRT //!< NACK interrupt
#define I2C_INT_RX_DATA_RDY     I2C_IC_INTR_STAT_RX_FULL //!< Receive-data-ready interrupt
#define I2C_INT_TX_DATA_RDY     I2C_IC_INTR_STAT_TX_EMPTY //!< Transmit-data-ready interrupt
#define I2C_INT_STOP_CONDITION  I2C_IC_INTR_STAT_STOP_DET //!< Stop condition detected
#define I2C_INT_ADDR_ZERO       I2C_IC_INTR_STAT_GEN_CALL //!< Addressed GENERAL CALL interrupt
#define I2C_INT_ADDR_TARGET     I2C_IC_INTR_STAT_SLV_ADDR1_TAG //!< Addressed as target interrupt
#define I2C_INT_RD_REQ          I2C_IC_INTR_STAT_RD_REQ //!< interrupt of I2C master is attempting to read data from this i2c slave
#define I2C_INT_RXFF            I2C_IC_INTR_STAT_RX_FULL //!< RX FIFO level interrupt
#define I2C_INT_TXFF            I2C_IC_INTR_STAT_TX_EMPTY //!< TX FIFO level interrupt
#define I2C_INT_WR_REQ          I2C_IC_INTR_STAT_WR_REQ //!< interrupt of I2C master is attempting to write data from this i2c slave
#define I2C_INT_MASTER_ON_HOLD  I2C_IC_INTR_STAT_MASTER_ON_HOLD //!< I2C master is attempting to
#define I2C_INT_RESTART_DET     I2C_IC_INTR_STAT_RESTART_DET //!< ReStart condition detected
#define I2C_INT_START_DET       I2C_IC_INTR_STAT_START_DET //!< Start condition detected
#define I2C_INT_STOP_DET        I2C_IC_INTR_STAT_STOP_DET //!< Stop condition detected
#define I2C_INT_ACTIVITY        I2C_IC_INTR_STAT_ACTIVITY //!< bus activity interrupt
#define I2C_INT_RX_DONE         I2C_IC_INTR_STAT_RX_DONE //!< interrupt of when act as slave-transmitter, the master does not acknowledge a transmitted byte
#define I2C_INT_TX_OVER         I2C_IC_INTR_STAT_TX_OVER //!< interrupt of transmit buffer is filled to IC_TX_BUFFER_DEPTH
#define I2C_INT_RX_OVER         I2C_IC_INTR_STAT_RX_OVER //!< interrupt of receive buffer is completely filled to IC_RX_BUFFER_DEPTH
#define I2C_INT_RX_UNDER        I2C_IC_INTR_STAT_RX_UNDER //!< interrupt of no receive buffer to read
#define I2C_INT_TX_ABRT         I2C_IC_INTR_STAT_TX_ABRT //!< interrupt of unable to complete the intended actions on the contents of the transmit FIFO

#define I2C_INT_REG_ACCESS_RDY 0

/*
 * status flag
 */
#define I2C_STS_ARB_LOST        I2C_INT_ARB_LOST
#define I2C_STS_NO_ACK          I2C_INT_NO_ACK
#define I2C_STS_RX_DATA_RDY     I2C_INT_RX_DATA_RDY
#define I2C_STS_TX_DATA_RDY     I2C_INT_TX_DATA_RDY
#define I2C_STS_STOP_CONDITION  I2C_INT_STOP_CONDITION
#define I2C_STS_ADDR_ZERO       I2C_INT_ADDR_ZERO
#define I2C_STS_ADDR_TARGET     I2C_INT_ADDR_TARGET
#define I2C_STS_TX_EMPTY        I2C_INT_TXFF
#define I2C_STS_RX_FULL         I2C_INT_RXFF
#define I2C_STS_BUS_BUSY        I2C_ICSTS_ACTIVITY
#define I2C_STS_TARGET_DIR      I2C_INT_RD_REQ
#define I2C_STS_REG_ACCESS_RDY  I2C_INT_REG_ACCESS_RDY

//
// Helpful define to mask out the bits in the I2CSTR register that aren't
// associated with interrupts.
//
#define I2C_STR_INTMASK     ((uint16_t)I2C_INT_ARB_LOST |                      \
                             (uint16_t)I2C_INT_NO_ACK |                        \
                             (uint16_t)I2C_INT_RX_DATA_RDY |                   \
                             (uint16_t)I2C_INT_TX_DATA_RDY |                   \
                             (uint16_t)I2C_INT_STOP_CONDITION |                \
                             (uint16_t)I2C_INT_ADDR_TARGET)

#define I2C_ICMODE_MASTER 0x41U  //!< I2C MASTER MODE
#define I2C_ICMODE_SLAVE 0x00U  //!< I2C SLAVE MODE

//
//return value of function I2C_getIcStatus
//
#define I2C_ICSTS_ACTIVITY 0x01U  //!< I2C is not idle, the OR of MST_ACTIVITY and SLV_ACTIVITY
#define I2C_ICSTS_TFNF 0x02U  //!< I2C Transmit FIFO Not Full
#define I2C_ICSTS_TFE 0x04U  //!< I2C Transmit FIFO Completely Empty
#define I2C_ICSTS_RFNE 0x08U  //!< I2C Receive FIFO Not Empty.
#define I2C_ICSTS_RFF 0x10U  //!< I2C Receive FIFO Completely Full.
#define I2C_ICSTS_MST_ACTIVITY 0x20U  //!< the Master Finite State Machine (FSM) is not in the IDLE state
#define I2C_ICSTS_SLV_ACTIVITY 0x40U  //!< the Slave Finite State Machine (FSM) is not in the IDLE state

//
//return value of function I2C_getIcTxAbrtSource
//
#define I2C_TXABRT_7B_ADDR_NOACK 0x01U  //!< NOACK for 7-bit address
#define I2C_TXABRT_10ADDR1_NOACK 0x02U  //!< Byte 1 of 10Bit Address not ACKed by any slave
#define I2C_TXABRT_10ADDR2_NOACK 0x04U  //!< Byte 2 of 10Bit Address not ACKed by any slave
#define I2C_TXABRT_TXDATA_NOACK 0x08U  //!< Transmitted data not ACKed by addressed slave
#define I2C_TXABRT_GCALL_NOACK 0x10U  //!< GCALL not ACKed by any slave
#define I2C_TXABRT_GCALL_READ 0x20U  //!< GCALL is followed by read from bus
#define I2C_TXABRT_SBYTE_ACKDET 0x80U  //!< ACK detected for START byte
#define I2C_TXABRT_MASTER_DIS 0x800U  //!< User initiating master operation when MASTER disabled
#define I2C_TXARB_LOST 0x1000U  //!< Master or Slave-Transmitter lost arbitration
#define I2C_TXABRT_SLVFLUSH_TXFIFO 0x2000U  //!< Slave flushes existing data in TX-FIFO upon getting read command
#define I2C_TXABRT_SLV_ARBLOST 0x4000U  //!< Slave lost arbitration to remote master
#define I2C_TXABRT_SLVRD_INTX 0x8000U  //!< Slave trying to transmit to remote master in read mode
#define I2C_TXABRT_USER_ABRT 0x10000U  //!< Transfer abort detected by master
#define I2C_TXABRT_NOACK 0x1FU


#define I2C_ICENSTS_IC_EN 0x01U                   //!< I2C Enable Status.
#define I2C_ICENSTS_SLV_DISABLED_WHILE_BUSY 0x02U //!< Slave Disabled While Busy (Transmit, Receive).
#define I2C_ICENSTS_SLV_RX_DATA_LOST 0X04U        //!< Slave Received Data Lost.

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

//*****************************************************************************
//
//! I2C interrupts to be returned by I2C_getInterruptSource().
//
//*****************************************************************************
typedef enum
{
    I2C_INTSRC_NONE,                //!< No interrupt pending
    I2C_INTSRC_ARB_LOST,            //!< Arbitration-lost interrupt
    I2C_INTSRC_NO_ACK,              //!< NACK interrupt
    I2C_INTSRC_REG_ACCESS_RDY,      //!< Register-access-ready interrupt
    I2C_INTSRC_RX_DATA_RDY,         //!< Receive-data-ready interrupt
    I2C_INTSRC_RX_FULL = I2C_INTSRC_RX_DATA_RDY,         //!< Rx fifo full interrupt
    I2C_INTSRC_TX_DATA_RDY,         //!< Transmit-data-ready interrupt
    I2C_INTSRC_TX_EMPTY = I2C_INTSRC_TX_DATA_RDY,         //!< Tx fifo empty interrupt
    I2C_INTSRC_STOP_CONDITION,      //!< Stop condition detected
    I2C_INTSRC_ADDR_TARGET,           //!< Addressed as target interrupt
    I2C_INTSRC_ADDR_ZERO,           //!< Addressed general call interrupt
    I2C_INTSRC_RD_REQ,           //!< Addressed as slave transmitter interrupt
    I2C_INTSRC_WR_REQ,           //!< Addressed as slave reciever interrupt
    I2C_INTSRC_RESTART_DET,           //!< Restart condition detected
    I2C_INTSRC_START_DET,           //!< Start condition detected
    I2C_INTSRC_ACTIVITY,           //!< i2c bus active interrupt
    I2C_INTSRC_RX_DONE,           //!< transmission done interrupt when act as slave-transmitter
    I2C_INTSRC_TX_OVER,           //!< tx fifo filled to BUFFER_DEPTH interrupt
    I2C_INTSRC_RX_OVER,           //!< rx fifo filled to BUFFER_DEPTH interrupt
    I2C_INTSRC_RX_UNDER,           //!< no receive buffer, rx fifo empty interrupt
    I2C_INTSRC_TX_ABRT           //!< transmit abort interrupt
} I2C_InterruptSource;

//*****************************************************************************
//
//! Values that can be passed to I2C_setFIFOInterruptLevel() as the \e txLevel
//! parameter, returned by I2C_getFIFOInterruptLevel() in the \e txLevel
//! parameter, and returned by I2C_getTxFIFOStatus().
//
//*****************************************************************************
typedef enum
{
    I2C_FIFO_TXEMPTY    = 0x0000U,      //!< Transmit FIFO empty
    I2C_FIFO_TX0        = 0x0000U,      //!< Transmit FIFO empty
    I2C_FIFO_TX1        = 0x0001U,      //!< Transmit FIFO 1/16 full
    I2C_FIFO_TX2        = 0x0002U,      //!< Transmit FIFO 2/16 full
    I2C_FIFO_TX3        = 0x0003U,      //!< Transmit FIFO 3/16 full
    I2C_FIFO_TX4        = 0x0004U,      //!< Transmit FIFO 4/16 full
    I2C_FIFO_TX5        = 0x0005U,      //!< Transmit FIFO 5/16 full
    I2C_FIFO_TX6        = 0x0006U,      //!< Transmit FIFO 6/16 full
    I2C_FIFO_TX7        = 0x0007U,      //!< Transmit FIFO 7/16 full
    I2C_FIFO_TX8        = 0x0008U,      //!< Transmit FIFO 8/16 full
    I2C_FIFO_TX9        = 0x0009U,      //!< Transmit FIFO 9/16 full
    I2C_FIFO_TX10       = 0x000AU,      //!< Transmit FIFO 10/16 full
    I2C_FIFO_TX11       = 0x000BU,      //!< Transmit FIFO 11/16 full
    I2C_FIFO_TX12       = 0x000CU,      //!< Transmit FIFO 12/16 full
    I2C_FIFO_TX13       = 0x000DU,      //!< Transmit FIFO 13/16 full
    I2C_FIFO_TX14       = 0x000EU,      //!< Transmit FIFO 14/16 full
    I2C_FIFO_TX15       = 0x000FU,      //!< Transmit FIFO 15/16 full
    I2C_FIFO_TX16       = 0x0010U,      //!< Transmit FIFO full
    I2C_FIFO_TXFULL     = 0x0010U       //!< Transmit FIFO full
} I2C_TxFIFOLevel;

//*****************************************************************************
//
//! Values that can be passed to I2C_setFIFOInterruptLevel() as the \e rxLevel
//! parameter, returned by I2C_getFIFOInterruptLevel() in the \e rxLevel
//! parameter, and returned by I2C_getRxFIFOStatus().
//
//*****************************************************************************
typedef enum
{
    I2C_FIFO_RXEMPTY    = 0x0000U,      //!< Receive FIFO empty
    I2C_FIFO_RX1        = 0x0001U,      //!< Receive FIFO 1/16 full
    I2C_FIFO_RX2        = 0x0002U,      //!< Receive FIFO 2/16 full
    I2C_FIFO_RX3        = 0x0003U,      //!< Receive FIFO 3/16 full
    I2C_FIFO_RX4        = 0x0004U,      //!< Receive FIFO 4/16 full
    I2C_FIFO_RX5        = 0x0005U,      //!< Receive FIFO 5/16 full
    I2C_FIFO_RX6        = 0x0006U,      //!< Receive FIFO 6/16 full
    I2C_FIFO_RX7        = 0x0007U,      //!< Receive FIFO 7/16 full
    I2C_FIFO_RX8        = 0x0008U,      //!< Receive FIFO 8/16 full
    I2C_FIFO_RX9        = 0x0009U,      //!< Receive FIFO 9/16 full
    I2C_FIFO_RX10       = 0x000AU,      //!< Receive FIFO 10/16 full
    I2C_FIFO_RX11       = 0x000BU,      //!< Receive FIFO 11/16 full
    I2C_FIFO_RX12       = 0x000CU,      //!< Receive FIFO 12/16 full
    I2C_FIFO_RX13       = 0x000DU,      //!< Receive FIFO 13/16 full
    I2C_FIFO_RX14       = 0x000EU,      //!< Receive FIFO 14/16 full
    I2C_FIFO_RX15       = 0x000FU,      //!< Receive FIFO 15/16 full
    I2C_FIFO_RX16       = 0x0010U,      //!< Receive FIFO full
    I2C_FIFO_RXFULL     = 0x0010U       //!< Receive FIFO full
} I2C_RxFIFOLevel;

//*****************************************************************************
//
//! Values that can be passed to I2C_setBitCount() as the \e size parameter.
//
//*****************************************************************************
typedef enum
{
    I2C_BITCOUNT_1  = 1U,   //!< 1 bit per data byte
    I2C_BITCOUNT_2  = 2U,   //!< 2 bits per data byte
    I2C_BITCOUNT_3  = 3U,   //!< 3 bits per data byte
    I2C_BITCOUNT_4  = 4U,   //!< 4 bits per data byte
    I2C_BITCOUNT_5  = 5U,   //!< 5 bits per data byte
    I2C_BITCOUNT_6  = 6U,   //!< 6 bits per data byte
    I2C_BITCOUNT_7  = 7U,   //!< 7 bits per data byte
    I2C_BITCOUNT_8  = 0U    //!< 8 bits per data byte
} I2C_BitCount;

//*****************************************************************************
//
//! Values that can be passed to I2C_setAddressMode() as the \e mode parameter.
//
//*****************************************************************************
typedef enum
{
    I2C_ADDR_MODE_7BITS        = 0x0000U,   //!< 7-bit address
    I2C_ADDR_MODE_10BITS       = 0x0018U    //!< 10-bit address
} I2C_AddressMode;

//*****************************************************************************
//
//! Values that can be passed to I2C_setExtendedMode() as the \e mode parameter.
//
//*****************************************************************************
typedef enum
{
    I2C_EADDR_MODE_BC  = 1U,   //!<  Backward compatibility
    I2C_EADDR_MODE_FWD = 2U    //!<  Forward compatibility
} I2C_ExtendedMode;

//*****************************************************************************
//
//! Values that can be passed to I2C_setEmulationMode() as the \e mode
//! parameter.
//
//*****************************************************************************
typedef enum
{
    //! If SCL is low, keep it low. If high, stop when it goes low again.
    I2C_EMULATION_STOP_SCL_LOW = 0x0000U,
    //! Continue I2C operation regardless
    I2C_EMULATION_FREE_RUN     = 0x4000U
} I2C_EmulationMode;

//*****************************************************************************
//
//! Values that can be passed to I2C_initController() as the \e dutyCycle
//! parameter.
//
//*****************************************************************************
typedef enum
{
    I2C_DUTYCYCLE_33,       //!< Clock duty cycle is 33%
    I2C_DUTYCYCLE_50        //!< Clock duty cycle is 55%
} I2C_DutyCycle;

typedef struct
{
    uint32_t master_mode;
    uint32_t slave_addr;
    uint32_t speed_mode;
    uint32_t baudrate;
    uint32_t apbclk_freq;
} I2C_INIT_PARAM;


/* ========================================================================== */
/*                            Global Constants                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Global Functions Declarations                      */
/* ========================================================================== */

//*****************************************************************************
//
//! \internal
//! Checks an I2C base address.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function determines if a I2C module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
__STATIC_INLINE boolean I2C_isBaseValid(uint32_t base)
{
    return(
           (base == I2C1_BASE) ||
           (base == I2C2_BASE)
          );
}
#endif



//*****************************************************************************
//
//! Enables the I2C module.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function enables operation of the I2C module.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_enableModule(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    HWREG(base + I2C_O_IC_ENABLE) |= I2C_IC_ENABLE_ENABLE;
}

//*****************************************************************************
//
//! Disables the I2C module.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function disables operation of the I2C module.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_disableModule(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    HWREG(base + I2C_O_IC_ENABLE) &= ~(I2C_IC_ENABLE_ENABLE);
}

__STATIC_INLINE void
I2C_enableTxCmdBlock(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    HWREG(base + I2C_O_IC_ENABLE) |= I2C_IC_ENABLE_TX_CMD_BLOCK;
}

__STATIC_INLINE void
I2C_disableTxCmdBlock(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    HWREG(base + I2C_O_IC_ENABLE) &= ~(I2C_IC_ENABLE_TX_CMD_BLOCK);
}


//*****************************************************************************
//
//! Enables the transmit and receive FIFOs.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This functions enables the transmit and receive FIFOs in the I2C.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_enableFIFO(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    //config FIFO Threshold Level to default
    HWREG(base + I2C_O_IC_TX_TL) = (HWREG(base + I2C_O_IC_TX_TL) &
                                 (~I2C_IC_TX_TL_TX_TL)) | I2C_FIFO_TXEMPTY;
    HWREG(base + I2C_O_IC_RX_TL) = (HWREG(base + I2C_O_IC_RX_TL) &
                                 (~I2C_IC_RX_TL_RX_TL)) | I2C_FIFO_RXEMPTY;
}

//*****************************************************************************
//
//! Disables the transmit and receive FIFOs.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This functions disables the transmit and receive FIFOs in the I2C.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_disableFIFO(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    //config FIFO Threshold Level to 1 to disableFIFO
    HWREG(base + I2C_O_IC_TX_TL) = (HWREG(base + I2C_O_IC_TX_TL) &
                                 (~I2C_IC_TX_TL_TX_TL)) | I2C_FIFO_TX1;
    HWREG(base + I2C_O_IC_RX_TL) = (HWREG(base + I2C_O_IC_RX_TL) &
                                 (~I2C_IC_RX_TL_RX_TL)) | I2C_FIFO_RX1;
}

//*****************************************************************************
//
//! Sets the FIFO level at which interrupts are generated.
//!
//! \param base is the base address of the I2C instance used.
//! \param txLevel is the transmit FIFO interrupt level, specified as
//! \b I2C_FIFO_TX0, \b I2C_FIFO_TX1, \b I2C_FIFO_TX2, . . . or
//! \b I2C_FIFO_TX16.
//! \param rxLevel is the receive FIFO interrupt level, specified as
//! \b I2C_FIFO_RX0, \b I2C_FIFO_RX1, \b I2C_FIFO_RX2, . . . or
//! \b I2C_FIFO_RX16.
//!
//! This function sets the FIFO level at which transmit and receive interrupts
//! are generated.  The transmit FIFO interrupt flag will be set when the FIFO
//! reaches a value less than or equal to \e txLevel.  The receive FIFO
//! flag will be set when the FIFO reaches a value greater than or equal to
//! \e rxLevel.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_setFIFOInterruptLevel(uint32_t base, I2C_TxFIFOLevel txLevel,
                          I2C_RxFIFOLevel rxLevel)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    if(rxLevel > I2C_FIFO_RXEMPTY)
        rxLevel = (I2C_RxFIFOLevel)((uint32_t)rxLevel - 1);

    //
    // Set the FIFO interrupt levels.
    //
    HWREG(base + I2C_O_IC_TX_TL) = (HWREG(base + I2C_O_IC_TX_TL) &
                                 (~I2C_IC_TX_TL_TX_TL)) | (uint32_t)txLevel;
    HWREG(base + I2C_O_IC_RX_TL) = (HWREG(base + I2C_O_IC_RX_TL) &
                                 (~I2C_IC_RX_TL_RX_TL)) | (uint32_t)rxLevel;
//    HWREG(base + I2C_O_IC_TX_TL) = txLevel;
//    HWREG(base + I2C_O_IC_RX_TL) = rxLevel;
}


__STATIC_INLINE void I2C_setReceiveFIFOLevel(uint32_t base,
		I2C_RxFIFOLevel rxLevel) {
	//
	// Check the arguments.
	//
	ASSERT(I2C_isBaseValid(base));

	if (rxLevel > I2C_FIFO_RXEMPTY)
		rxLevel = (I2C_RxFIFOLevel) ((uint32_t) rxLevel - 1);

	//
	// Set the FIFO interrupt levels.
	//
	HWREG(base + I2C_O_IC_RX_TL) = (HWREG(base + I2C_O_IC_RX_TL)
			& (~I2C_IC_RX_TL_RX_TL)) | (uint32_t) rxLevel;
}

__STATIC_INLINE uint32_t
I2C_getReceiveFIFOLevel(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    return HWREG(base + I2C_O_IC_RXFLR);
}

//*****************************************************************************
//
//! Gets the FIFO level at which interrupts are generated.
//!
//! \param base is the base address of the I2C instance used.
//! \param txLevel is a pointer to storage for the transmit FIFO level,
//! returned as one of \b I2C_FIFO_TX0, \b I2C_FIFO_TX1,
//! \b I2C_FIFO_TX2, . . . or \b I2C_FIFO_TX16.
//! \param rxLevel is a pointer to storage for the receive FIFO level,
//! returned as one of \b I2C_FIFO_RX0, \b I2C_FIFO_RX1,
//! \b I2C_FIFO_RX2, . . . or \b I2C_FIFO_RX16.
//!
//! This function gets the FIFO level at which transmit and receive interrupts
//! are generated.  The transmit FIFO interrupt flag will be set when the FIFO
//! reaches a value less than or equal to \e txLevel.  The receive FIFO
//! flag will be set when the FIFO reaches a value greater than or equal to
//! \e rxLevel.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_getFIFOInterruptLevel(uint32_t base, I2C_TxFIFOLevel *txLevel,
                          I2C_RxFIFOLevel *rxLevel)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Extract the transmit and receive FIFO levels.
    //
    *txLevel = (I2C_TxFIFOLevel)HWREG(base + I2C_O_IC_TX_TL);
    *rxLevel = (I2C_RxFIFOLevel)HWREG(base + I2C_O_IC_RX_TL);
}

//*****************************************************************************
//
//! Get the transmit FIFO status
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function gets the current number of words in the transmit FIFO.
//!
//! \return Returns the current number of words in the transmit FIFO specified
//! as one of the following:
//! \b I2C_FIFO_TX0, \b I2C_FIFO_TX1, \b I2C_FIFO_TX2, \b I2C_FIFO_TX3,
//! ..., or \b I2C_FIFO_TX16
//
//*****************************************************************************
__STATIC_INLINE I2C_TxFIFOLevel
I2C_getTxFIFOStatus(uint32_t base)
{
    uint16_t level;

    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Get the current FIFO status
    //
    level = (uint16_t)HWREG(base + I2C_O_IC_TXFLR);

    return((I2C_TxFIFOLevel)level);
}

//*****************************************************************************
//
//! Get the receive FIFO status
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function gets the current number of words in the receive FIFO.
//!
//! \return Returns the current number of words in the receive FIFO specified
//! as one of the following:
//! \b I2C_FIFO_RX0, \b I2C_FIFO_RX1, \b I2C_FIFO_RX2, \b I2C_FIFO_RX3,
//! ..., or \b I2C_FIFO_RX16
//
//*****************************************************************************
__STATIC_INLINE I2C_RxFIFOLevel
I2C_getRxFIFOStatus(uint32_t base)
{
    uint16_t level;

    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Get the current FIFO status
    //
    level = (uint16_t)HWREG(base + I2C_O_IC_RXFLR);

    return((I2C_RxFIFOLevel)level);
}

//*****************************************************************************
//
//! Reads I2C Module clock prescaler value.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function reads the I2C prescaler value which configures the I2C module
//! clock by dividing down the SYSCLK. I2C_MODULE_CLK = SYSCLK / (I2CPSC + )
//!
//! \return Returns the I2C prescaler(I2CPSC) cast as an uint16_t.
//
//*****************************************************************************
__STATIC_INLINE uint16_t
I2C_getPreScaler(uint32_t base)
{
    ASSERT(FALSE);

    return 0;
}


//*****************************************************************************
//
//! Sets the own address for this I2C module.
//!
//! \param base is the base address of the I2C Target module.
//! \param Addr is the 7-bit or 10-bit address
//!
//! This function writes the specified address.
//!
//! The parameter \e Addr is the value that is compared against the
//! target address sent by an I2C controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_setOwnAddress(uint32_t base, uint16_t Addr)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    ASSERT(Addr <= I2C_IC_SAR_IC_SAR);
    HWREG(base + I2C_O_IC_SAR) = (HWREG(base + I2C_O_IC_SAR) & (~I2C_IC_SAR_IC_SAR)) | (uint32_t)Addr;
}

__STATIC_INLINE uint16_t 
I2C_getOwnAddress(uint32_t base) 
{
	//
	// Check the arguments.
	//
	ASSERT(I2C_isBaseValid(base));
	return (HWREG(base + I2C_O_IC_SAR)) & I2C_IC_SAR_IC_SAR;

}
//*****************************************************************************
//
//! Indicates whether or not the I2C bus is busy.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function returns an indication of whether or not the I2C bus is busy.
//! This function can be used in a multi-controller environment to determine if the
//! bus is free for another data transfer.
//!
//! \return Returns \b true if the I2C bus is busy; otherwise, returns
//! \b false.
//
//*****************************************************************************
__STATIC_INLINE bool
I2C_isBusBusy(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    return (HWREG(base + I2C_O_IC_STATUS) & I2C_IC_STATUS_ACTIVITY != 0);
}

//*****************************************************************************
//
//! Indicates whether or not the I2C master is busy.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function returns an indication of whether or not the I2C master is busy.
//!
//! \return Returns \b true if the I2C bus is busy; otherwise, returns
//! \b false.
//
//*****************************************************************************
__STATIC_INLINE bool
I2C_isMasterBusy(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    return (HWREG(base + I2C_O_IC_STATUS) & I2C_IC_STATUS_MST_ACTIVITY != 0);
}


//*****************************************************************************
//
//! Issues an read/write command with START/STOP/RESTART CONDITION.
//!
//! \param base is the base address of the I2C instance used.
//! \param ic_data_cmd is the data and command like data | write/read | stop/restart
//!
//! This function issues a read/write command and causes the I2C module to generate a START/RESTART/STOP condition.
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendIcDataCmd(uint32_t base, uint32_t ic_data_cmd)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Set the CMD bit. Issues a read/write command and causes an START/RESTART/STOP condition.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) = ic_data_cmd;
}

//*****************************************************************************
//
//! Issues an write command.
//!
//! \param base is the base address of the I2C instance used.
//! \param data is the data and command like data
//!
//! This function issues a write command and data .
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendCmdWrite(uint32_t base,uint8_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    //
    // Set the CMD bit. Issues a write command.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) = (data&0x00FFU);

}

//*****************************************************************************
//
//! Issues an write command with STOP CONDITION.
//!
//! \param base is the base address of the I2C instance used.
//! \param ic_data_cmd is the data and command like data | stop
//!
//! This function issues a write command data and causes the I2C module to generate a STOP condition.
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendCmdWriteAndStop(uint32_t base,uint8_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    //
    // Set the CMD bit. Issues a write command and causes an STOP condition.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) = ((data&0x00FFU)|I2C_IC_DATA_CMD_STOP);

}

//*****************************************************************************
//
//! Issues an write command with RESTART CONDITION.
//!
//! \param base is the base address of the I2C instance used.
//! \param ic_data_cmd is the data and command like data | restart
//!
//! This function issues a write command data and causes the I2C module to generate a RESTART condition.
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendCmdRestartAndWrite(uint32_t base,uint8_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    //
    // Set the CMD bit. Causes a RESTART condition and issues a write command.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) =((data&0x00FFU)|I2C_IC_DATA_CMD_RESTART);
}

//*****************************************************************************
//
//! Issues an read command with RESTART CONDITION.
//!
//! \param base is the base address of the I2C instance used.
//! \param ic_data_cmd is the data and command like data | restart
//!
//! This function issues a read command and causes the I2C module to generate a RESTART condition.
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendCmdRestartAndRead(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    //
    // Set the CMD bit. Causes a RESTART condition and issues a read command.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) =I2C_IC_DATA_CMD_CMD | I2C_IC_DATA_CMD_RESTART;
}


//*****************************************************************************
//
//! Issues an read command with STOP CONDITION.
//!
//! \param base is the base address of the I2C instance used.
//! \param ic_data_cmd is the data and command like data | stop
//!
//! This function issues a read command and causes the I2C module to generate a STOP condition.
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendCmdReadAndStop(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    //
    // Set the CMD bit. Issues a read command and causes an STOP condition.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) = I2C_IC_DATA_CMD_CMD | I2C_IC_DATA_CMD_STOP;
}

//*****************************************************************************
//
//! Issues an read command with STOP/RESTART CONDITION.
//!
//! \param base is the base address of the I2C instance used.
//! \param ic_data_cmd is the data and command like data | stop | restart
//!
//! This function issues a read command and causes the I2C module to generate a STOP condition.
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendCmdRestartAndReadAndStop(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    //
    // Set the CMD bit. Causes a RESTART condition and issues a read command and generate STOP.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) =I2C_IC_DATA_CMD_CMD | I2C_IC_DATA_CMD_RESTART | I2C_IC_DATA_CMD_STOP;
}

//*****************************************************************************
//
//! Issues an read command .
//!
//! \param base is the base address of the I2C instance used.
//! \param ic_data_cmd is the data and command like data
//!
//! This function issues a read command and causes the I2C module to generate a STOP condition.
//! This function is only valid when the I2C module specified by the \b base
//! parameter is a controller.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_sendCmdRead(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    //
    // Set the CMD bit. Issues a read command.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) =I2C_IC_DATA_CMD_READ;
}

//*****************************************************************************
//
//! Receives a byte that has been sent to the I2C.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function reads a byte of data from the I2C Data Receive Register.
//!
//! \return Returns the byte received from by the I2C cast as an uint8_t.
//
//*****************************************************************************
__STATIC_INLINE uint8_t
I2C_getData(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //must make sure Rx FIFO is not empty before reading RxFIFO
    if(I2C_FIFO_RXEMPTY != (0xFF & I2C_getReceiveFIFOLevel(base)))
    {
        // Return the contents of the receive register.
        return(HWREG(base + I2C_O_IC_DATA_CMD) & I2C_IC_DATA_CMD_DAT);
    }
    else
    {
        return 0;  //return 0 means invalid data, Rx FIFO is empty
    }

}

//*****************************************************************************
//
//! Transmits a byte from the I2C.
//!
//! \param base is the base address of the I2C instance used.
//! \param data is the data to be transmitted from the I2C Controller.
//!
//! This function places the supplied data into I2C Data Transmit Register.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_putData(uint32_t base, uint32_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Place the data into the transmit register.
    //
    HWREG(base + I2C_O_IC_DATA_CMD) = (data & 0xFF);
}


//*****************************************************************************
//
//! Get stop condition status.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function reads and returns the stop condition bit status.
//!
//! \return Returns \b true if the STP bit has been set by the device to
//! generate a stop condition when the internal data counter of the I2C module
//! has reached 0. Returns \b false when the STP bit is zero. This bit is
//! automatically cleared after the stop condition has been generated.
//
//*****************************************************************************
__STATIC_INLINE bool
I2C_getStopConditionStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Check the stop condition bit and return appropriately.
    //
    return((HWREG(base + I2C_O_IC_RAW_INTR_STAT) & I2C_IC_INTR_STAT_STOP_DET) != 0U);
}

//*****************************************************************************
//
//! Sets the addressing mode to either 7-bit or 10-bit.
//!
//! \param base is the base address of the I2C instance used.
//! \param mode is the address mode, 7-bit or 10-bit.
//!
//! This function configures the I2C module for either a 7-bit address
//! (default) or a 10-bit address. The \e mode parameter configures the address
//! length to 10 bits when its value is \b I2C_ADDR_MODE_10BITS and 7 bits when
//! \b I2C_ADDR_MODE_7BITS.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_setAddressMode(uint32_t base, I2C_AddressMode mode)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Write the appropriate value to the address expansion bit.
    //
    HWREG(base + I2C_O_IC_CON) = (HWREG(base + I2C_O_IC_CON) &
                               ~(I2C_IC_CON_IC_10BITADDR_MASTER | I2C_IC_CON_IC_10BITADDR_SLAVE)) |
                               (uint16_t)mode;
}

//*****************************************************************************
//
//! Enables I2C loopback mode.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function enables loopback mode. This mode is only valid during controller
//! mode and is helpful during device testing as it causes data transmitted out
//! of the data transmit register to be received in data receive register.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_enableLoopback(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    // loopback exists when tar == sar
    ASSERT((HWREG(base + I2C_O_IC_TAR) & I2C_IC_TAR_IC_TAR) == (HWREG(base + I2C_O_IC_SAR) & I2C_IC_SAR_IC_SAR));

    I2C_disableModule(base);
    HWREG(base + I2C_O_IC_CON) |= I2C_IC_CON_MASTER_MODE;
    HWREG(base + I2C_O_IC_CON) &= (~I2C_IC_CON_IC_SLAVE_DISABLE);
    I2C_enableModule(base);
}

//*****************************************************************************
//
//! Disables I2C loopback mode.
//!
//! \param base is the base address of the I2C instance used.
//!
//! This function disables loopback mode. Loopback mode is disabled by default
//! after reset.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
I2C_disableLoopback(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    HWREG(base + I2C_O_IC_CON) |= I2C_IC_CON_MASTER_MODE;
    HWREG(base + I2C_O_IC_CON) |= I2C_IC_CON_IC_SLAVE_DISABLE;
}

/**
 * \brief   i2c config.
 *
 * \param   base   the base address of the I2C instance used.
 * \param   config the I2C_IC_CON register value,
 *          it should be the combination of the following macro:
 *          I2C_MASTER_MODE, or I2C_SLAVE_MODE, (must include one of them)
 *          I2C_FAST_SPEED_MODE, or I2C_STANDARD_SPEED_MODE, (must include one of them)
 *          I2C_STOP_DET_IFADDRESSED,
 *          I2C_TX_EMPTY_CTRL, (must include this bit)
 *          I2C_RX_FIFO_FULL_HLD_CTRL,
 *          I2C_STOP_DET_IF_MASTER_ACTIVE,
 *          I2C_RESTART_EN,
 *          I2C_10BIT_ADDRESS,
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_setConfig(uint32_t base, uint32_t config)
{
    HWREG(base + I2C_O_IC_CON) = config;
}

/**
 * \brief   enable general call.
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_enableGeneralCall(uint32_t base)
{
    HWREG(base + I2C_O_IC_TAR) = (HWREG(base + I2C_O_IC_TAR) | I2C_IC_TAR_SPECIAL) & (~I2C_IC_TAR_GC_OR_START);
}

/**
 * \brief   enable start byte.
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_enableStartByte(uint32_t base)
{
    HWREG(base + I2C_O_IC_CON) |= (I2C_IC_TAR_SPECIAL | I2C_IC_TAR_GC_OR_START);
}


/**
 * \brief   abort the I2C transfer in master mode
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_transmitAbort(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    HWREG(base + I2C_O_IC_ENABLE) |= I2C_IC_ENABLE_ABORT;
}

/**
 * \brief   get I2C ic mode
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  i2c ic mode, refer:
 *          I2C_ICMODE_MASTER
 *          I2C_ICMODE_SLAVE
 */
__STATIC_INLINE uint32_t
I2C_getIcMode(uint32_t base)
{
//    ASSERT(I2C_isBaseValid(base));
    return HWREG(base + I2C_O_IC_CON) & (I2C_IC_CON_MASTER_MODE | I2C_IC_CON_IC_SLAVE_DISABLE);
}


/**
 * \brief   get I2C speed
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  i2c speed value
 *
 *
 */
__STATIC_INLINE uint32_t
I2C_getSpeedMode(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    return HWREG(base + I2C_O_IC_CON) & (0x03 << 1);
}


/**
 * \brief    Enables I2C interrupt sources.
 *
 * \param   base       the base address of the I2C instance used.
 * \param  intFlags is the bit mask of the interrupt sources to be enabled.
 *!  This function enables the indicated I2C Controller interrupt sources.   Only the
 *!  sources that are enabled can be reflected to the processor interrupt.
 *!  Disabled sources have no effect on the processor.
 *!  The \e intFlags parameter is the logical OR of any of the following:
 * #define I2C_IC_INTR_STAT_RX_UNDER    0x01U
 * #define I2C_IC_INTR_STAT_RX_OVER 0x02U
 * #define I2C_IC_INTR_STAT_RX_FULL 0x04U
 * #define I2C_IC_INTR_STAT_TX_OVER 0x08U
 * #define I2C_IC_INTR_STAT_TX_EMPTY    0x10U
 * #define I2C_IC_INTR_STAT_RD_REQ  0x20U
 * #define I2C_IC_INTR_STAT_TX_ABRT 0x40U
 * #define I2C_IC_INTR_STAT_RX_DONE 0x80U
 * #define I2C_IC_INTR_STAT_ACTIVITY    0x100U
 * #define I2C_IC_INTR_STAT_STOP_DET    0x200U
 * #define I2C_IC_INTR_STAT_START_DET   0x400U
 * #define I2C_IC_INTR_STAT_GEN_CALL    0x800U
 * #define I2C_IC_INTR_STAT_RESTART_DET 0x1000U
 * #define I2C_IC_INTR_STAT_MASTER_ON_HOLD 0x2000U
 * #define I2C_IC_INTR_STAT_WR_REQ  0x8000U
 * #define I2C_IC_INTR_STAT_SLV_ADDR1_TAG   0x10000U
 * \retval  None
 */
__STATIC_INLINE void
I2C_enableInterrupt(uint32_t base, uint32_t intFlags)
{
    HWREG(base + I2C_O_IC_INTR_MASK) |= intFlags;
}

/**
 * \brief   disable interrupt.
 *
 * \param   base       the base address of the I2C instance used.
 * \param   intFlags   the interrupt to disable.
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_disableInterrupt(uint32_t base, uint32_t intFlags)
{
    HWREG(base + I2C_O_IC_INTR_MASK) &= (~intFlags);
}

/**
 * \brief  Gets the current I2C interrupt status.
 *
 * \param   base       the base address of the I2C instance used.
 * This function returns the interrupt status for the I2C module.
 * return The current interrupt status, Macro definition:
 * #define I2C_IC_INTR_STAT_RX_UNDER    0x01U
 * #define I2C_IC_INTR_STAT_RX_OVER 0x02U
 * #define I2C_IC_INTR_STAT_RX_FULL 0x04U
 * #define I2C_IC_INTR_STAT_TX_OVER 0x08U
 * #define I2C_IC_INTR_STAT_TX_EMPTY    0x10U
 * #define I2C_IC_INTR_STAT_RD_REQ  0x20U
 * #define I2C_IC_INTR_STAT_TX_ABRT 0x40U
 * #define I2C_IC_INTR_STAT_RX_DONE 0x80U
 * #define I2C_IC_INTR_STAT_ACTIVITY    0x100U
 * #define I2C_IC_INTR_STAT_STOP_DET    0x200U
 * #define I2C_IC_INTR_STAT_START_DET   0x400U
 * #define I2C_IC_INTR_STAT_GEN_CALL    0x800U
 * #define I2C_IC_INTR_STAT_RESTART_DET 0x1000U
 * #define I2C_IC_INTR_STAT_MASTER_ON_HOLD 0x2000U
 * #define I2C_IC_INTR_STAT_WR_REQ  0x8000U
 * #define I2C_IC_INTR_STAT_SLV_ADDR1_TAG   0x10000U
 * !note This function will only return the status flags associated with
 * !The corresponding interrupt source can be set only after it is enabled
 * \retval  the status of interrupt
 */
__STATIC_INLINE uint32_t I2C_getInterruptStatus(uint32_t base)
{
    return HWREG(base + I2C_O_IC_INTR_STAT);
}

#define I2C_getStatus I2C_getInterruptStatus

/**
 * \brief   get raw interrupt status.
 *
 * \param   base       the base address of the I2C instance used.
 * This function returns the status of raw interrupt
 * return The current interrupt status, Macro definition:
 * #define I2C_IC_INTR_STAT_RX_UNDER    0x01U
 * #define I2C_IC_INTR_STAT_RX_OVER 0x02U
 * #define I2C_IC_INTR_STAT_RX_FULL 0x04U
 * #define I2C_IC_INTR_STAT_TX_OVER 0x08U
 * #define I2C_IC_INTR_STAT_TX_EMPTY    0x10U
 * #define I2C_IC_INTR_STAT_RD_REQ  0x20U
 * #define I2C_IC_INTR_STAT_TX_ABRT 0x40U
 * #define I2C_IC_INTR_STAT_RX_DONE 0x80U
 * #define I2C_IC_INTR_STAT_ACTIVITY    0x100U
 * #define I2C_IC_INTR_STAT_STOP_DET    0x200U
 * #define I2C_IC_INTR_STAT_START_DET   0x400U
 * #define I2C_IC_INTR_STAT_GEN_CALL    0x800U
 * #define I2C_IC_INTR_STAT_RESTART_DET 0x1000U
 * #define I2C_IC_INTR_STAT_MASTER_ON_HOLD 0x2000U
 * #define I2C_IC_INTR_STAT_WR_REQ  0x8000U
 * #define I2C_IC_INTR_STAT_SLV_ADDR1_TAG   0x10000U
 * !note This function will only return the status flags associated with
 * !The corresponding interrupt source can be set only after it is enabled
 * \retval  the status of raw interrupt
 */
__STATIC_INLINE uint32_t I2C_getInterruptRawStatus(uint32_t base)
{
    return HWREG(base + I2C_O_IC_RAW_INTR_STAT);
}

/**
 * \brief   clear all interrupt status.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 * \details I2C Interrupt Status Register IC_INTR_STAT is cleared by reading IC_CLR_INTR register
 */
__STATIC_INLINE void I2C_clearAllInterruptStatus(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_INTR);
}

/**
 * \brief   clear rx under.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptRxUnder(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_RX_UNDER);
}

/**
 * \brief   clear rx over.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptRxOver(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_RX_OVER);
}

/**
 * \brief   clear tx over.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptTxOver(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_TX_OVER);
}

/**
 * \brief   clear rd req.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptRdReq(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_RD_REQ);
}

/**
 * \brief   clear tx abrt.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptTxAbrt(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_TX_ABRT);
}

/**
 * \brief   clear rx done.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */\
__STATIC_INLINE void I2C_clearInterruptRxDone(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_RX_DONE);
}

/**
 * \brief   clear activity.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptActivity(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_ACTIVITY);
}

/**
 * \brief   clear stop detect.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptStopDet(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));


    (void)HWREG(base + I2C_O_IC_CLR_STOP_DET);
}

/**
 * \brief   clear start detect.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptStartDet(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_START_DET);
}

/**
 * \brief   clear general call.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptGenCall(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_GEN_CALL);
}

/**
 * \brief   clear restart detect.
 *
 * \param   base       the base address of the I2C instance used.
 *
 * \retval  none
 */
__STATIC_INLINE void I2C_clearInterruptRestartDet(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    (void)HWREG(base + I2C_O_IC_CLR_RESTART_DET);
}



/**
 * \brief   get the current transfer status and FIFO status
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  ic status, refer:
 *          I2C_TXABRT_7B_ADDR_NOACK
 *          I2C_TXABRT_10ADDR1_NOACK
 *          I2C_TXABRT_10ADDR2_NOACK
 *          I2C_TXABRT_TXDATA_NOACK
 *          I2C_TXABRT_GCALL_NOACK
 *          I2C_TXABRT_GCALL_READ
 *          I2C_TXABRT_SBYTE_ACKDET
 *          I2C_TXABRT_MASTER_DIS
 *          I2C_TXARB_LOST
 *          I2C_TXABRT_SLVFLUSH_TXFIFO
 *          I2C_TXABRT_SLV_ARBLOST
 *          I2C_TXABRT_SLVRD_INTX
 *          I2C_TXABRT_USER_ABRT
 */
__STATIC_INLINE uint32_t
I2C_getIcTxAbrtSource(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    return HWREG(base + I2C_O_IC_TX_ABRT_SOURCE);
}

/**
 * \brief   get the current transfer status and FIFO status
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  ic status, refer:
 *          I2C_ICSTS_ACTIVITY,        bus is busy
 *          I2C_ICSTS_TFNF,            TX FIFO is not full
 *          I2C_ICSTS_TFE,             TX FIFO empty
 *          I2C_ICSTS_RFNE,            RX FIFO not empty
 *          I2C_ICSTS_RFF,             RX FIFO is full
 *          I2C_ICSTS_MST_ACTIVITY,    Master is in TX/RX activity
 *          I2C_ICSTS_SLV_ACTIVITY,    Slave is in TX/RX activity
 */
__STATIC_INLINE uint32_t
I2C_getIcStatus(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    return HWREG(base + I2C_O_IC_STATUS);
}

/**
 * \brief   poll the I2C tx status for nRetryCnt times
 *
 * \param   base, the base address of the I2C instance used.
 *          nRetryCnt, max re-try count of reading the status register before return.
 *              assuming 240MHz sysclk, nRetryCnt=30 is around 1uS
 *
 * \retval  true, the Tx shift register is empty
 *          false, Tx shift register is not empty
 */
__STATIC_INLINE bool
I2C_pollTxStatus(uint32_t base, uint32_t nRetryCnt)
{
    uint32_t retry_cnt = 0;
    ASSERT(I2C_isBaseValid(base));

    // wait if tx shift register is not empty
    while (!(I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_TX_EMPTY))
    {
        if (retry_cnt == nRetryCnt)
            return false;
        retry_cnt++;
    }
    return true;
}

/**
 * \brief   poll the I2C rx status for nRetryCnt times
 *
 * \param   base, the base address of the I2C instance used.
 *          nRetryCnt, max re-try count of reading the status register before return.
 *              assuming 240MHz sysclk, nRetryCnt=30 is around 1uS
 *
 * \retval  true, there is data received in rx buffer.
 *          false, rx buffer is empty, no data received.
 */
__STATIC_INLINE bool
I2C_pollRxStatus(uint32_t base, uint32_t nRetryCnt)
{
    uint32_t retry_cnt = 0;
    ASSERT(I2C_isBaseValid(base));

    /* wait if Rx FIFO is empty */
    while (!(I2C_getIcStatus(base) & I2C_ICSTS_RFNE))
    {
        if (retry_cnt == nRetryCnt)
            return false;
        retry_cnt++;
    }
    return true;
}

/**
 * \brief   poll the I2C master status for nRetryCnt times
 *
 * \param   base, the base address of the I2C instance used.
 *          nRetryCnt, max re-try count of reading the status register before return.
 *                assuming 240MHz sysclk, nRetryCnt=30 is around 1uS
 *
 * \retval  true, master status is inactive, master has completed read/write operation.
 *          false, master is active, master has not yet completed read/write operation.
 */
__STATIC_INLINE bool
I2C_pollMasterStatus(uint32_t base, uint32_t nRetryCnt)
{
    uint32_t retry_cnt = 0;
    ASSERT(I2C_isBaseValid(base));

    /* wait if master status is active */
    while (I2C_getIcStatus(base) & I2C_ICSTS_MST_ACTIVITY)
    {
        if (retry_cnt == nRetryCnt)
            return false;
        retry_cnt++;
    }
    return true;
}

/**
 * \brief   poll the I2C bus busy status for nRetryCnt times
 *
 * \param   base, the base address of the I2C instance used.
 *          nRetryCnt, max re-try count of reading the status register before return.
 *                assuming 240MHz sysclk, nRetryCnt=30 is around 1uS
 *
 * \retval  true, bus is idle.
 *          false, bus is busy.
 */
__STATIC_INLINE bool
I2C_pollBusyStatus(uint32_t base, uint32_t nRetryCnt)
{
    uint32_t retry_cnt = 0;
    ASSERT(I2C_isBaseValid(base));

    /* wait if master status is active */
    while (I2C_getIcStatus(base) & I2C_IC_STATUS_ACTIVITY)
    {
        if (retry_cnt == nRetryCnt)
            return false;
        retry_cnt++;
    }
    return true;
}

/**
 * \brief   report the i2c hardware status
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  ic enable status, refer:
 *          I2C_ICENSTS_IC_EN
 *          I2C_ICENSTS_SLV_DISABLED_WHILE_BUSY
 *          I2C_ICENSTS_SLV_RX_DATA_LOST
 */
__STATIC_INLINE uint32_t
I2C_getIcEnableStatus(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    return HWREG(base + I2C_O_IC_ENABLE_STATUS);
}

/**
 * \brief   controls the amount of time delay (in terms of number of ic_clk clock periods)
 *          introduced in the rising edge of SCL - relative to SDA changing
 *          when i2c services a read request in a slave-transmitter operation.
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \param   setupTime   SDA setup time (tSU:DAT).
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_setSDASetupTime(uint32_t base, uint32_t setupTime)
{
    ASSERT(I2C_isBaseValid(base));
    ASSERT(setupTime > 0);
    HWREG(base + I2C_O_IC_SDA_SETUP) = setupTime;
}

/**
 * \brief   store the duration, measured in ic_clk cycles,
 *          of the longest spike that is filtered out by the spike suppression logic.
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \param   spklen   the duration, measured in ic_clk cycles, of the longest spike.
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_setSpkLen(uint32_t base, uint32_t spklen)
{
    ASSERT(I2C_isBaseValid(base));
    HWREG(base + I2C_O_IC_SDA_SETUP) = spklen;
}

/**
 * \brief   poll Tx Empty flag for I2C_RETRY_TIMES
 * \param   base   the base address of the I2C instance used.
 * \retval  TRUE if TxBuf is empty
 *          FALSE if TxBuf is not empty
 * \note    I2C need be initialized with EMPTY_CTRL=1
 */
__STATIC_INLINE uint32_t I2C_pollTxEmpty(uint32_t base)
{
    uint32_t retry_cnt = 0;

    while (!(I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_TX_EMPTY))
    {
        if (retry_cnt++ == I2C_RETRY_LIMIT)
            return FALSE;
    }
    return TRUE;
}

__STATIC_INLINE void I2C_waitTxEmpty(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    while((I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_TX_EMPTY) == 0);
}

__STATIC_INLINE uint32_t I2C_isTxEmpty(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    if(I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_TX_EMPTY)
        return 1;
    else
        return 0;
}

__STATIC_INLINE uint32_t I2C_isTxNOACK(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    if((I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_TX_ABRT) && (I2C_getIcTxAbrtSource(base) & (I2C_TXABRT_NOACK)))
        return 1;
    else
        return 0;
}

/**
 * \brief   poll Tx Empty flag for I2C_RETRY_TIMES
 * \param   base   the base address of the I2C instance used.
 * \retval  TRUE if RxBuf is full
 *          FALSE if RxBuf is not full
 * \note    I2C need be initialized with EMPTY_CTRL=1
 */
__STATIC_INLINE uint32_t I2C_pollRxFull(uint32_t base)
{
    uint32_t retry_cnt = 0;

    /* wait if Rx FIFO is empty */
    while (!(I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_RX_FULL))
    {
        if (retry_cnt++ == I2C_RETRY_LIMIT)
            return FALSE;
    }
    return TRUE;
}

__STATIC_INLINE void I2C_waitRxFull(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    while((I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_RX_FULL) == 0);
}

__STATIC_INLINE uint32_t I2C_isRxFull(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));
    if(I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_RX_FULL)
        return 1;
    else
        return 0;
}


/**
 * \brief   controls whether i2c responds with a ACK or NACK when it receives an I2C General Call address.
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \param   flag   respond or not respond GENERAL CALL
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_setAckGeneralCall(uint32_t base, bool flag)
{
    ASSERT(I2C_isBaseValid(base));
    if (flag)
        HWREG(base + I2C_O_IC_ACK_GENERAL_CALL) |= I2C_IC_ACK_GENERAL_CALL;
    else
        HWREG(base + I2C_O_IC_ACK_GENERAL_CALL) &= (~I2C_IC_ACK_GENERAL_CALL);
}

/**
 * \brief   enable i2c dma.
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_enableDma(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    HWREG(base + I2C_O_IC_DMA_CR) |= (I2C_IC_DMA_CR_RDMAE | I2C_IC_DMA_CR_TDMAE);
}

/**
 * \brief   disable i2c dma.
 *
 * \param   base   the base address of the I2C instance used.
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_disableDma(uint32_t base)
{
    ASSERT(I2C_isBaseValid(base));

    HWREG(base + I2C_O_IC_DMA_CR) &= (~(I2C_IC_DMA_CR_RDMAE | I2C_IC_DMA_CR_TDMAE));
}

/**
 * \brief   set i2c DMA Transmit Data Level.
 *
 * \param   base   the base address of the I2C instance used.
 * \param   dmatdl   Transmit Data Level.range:0-7
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_setDmaTdLr(uint32_t base, uint8_t dmatdl)
{
    ASSERT(I2C_isBaseValid(base));
    ASSERT(dmatdl >> 0 && dmatdl << 7);

    HWREG(base + I2C_O_IC_DMA_TDLR) = ((HWREG(base + I2C_O_IC_DMA_TDLR) & (~I2C_IC_DMA_TDLR_DMATDL)) | dmatdl);
}

/**
 * \brief   set i2c DMA Receive Data Level.
 *
 * \param   base   the base address of the I2C instance used.
 * \param   dmardl   Receive Data Level.range:0-7
 *
 * \retval  None
 */
__STATIC_INLINE void
I2C_setDmaRdLr(uint32_t base, uint8_t dmardl)
{
    ASSERT(I2C_isBaseValid(base));

    ASSERT(dmardl >> 0 && dmardl << 7);

    HWREG(base + I2C_O_IC_DMA_RDLR) = ((HWREG(base + I2C_O_IC_DMA_RDLR) & (~I2C_IC_DMA_RDLR_DMARDL)) | dmardl);
}

__STATIC_INLINE void
I2C_setFsSpklen(uint32_t base, uint32_t spike_len)
{
    HWREGH(base + I2C_O_IC_FS_SPKLEN) = spike_len;
}

extern void
I2C_setTargetAddress(uint32_t base, uint16_t targetAddr);

extern void
I2C_setSlaveAddress(uint32_t base, uint16_t targetAddr);

extern void
I2C_initController(uint32_t base, uint32_t sysclkHz, uint32_t bitRate,
               I2C_DutyCycle dutyCycle);

extern void
I2C_setSDAHoldTime(uint32_t base, uint8_t rxHoldTime, uint16_t txHoldTime);

extern void
I2C_clearInterruptStatus(uint32_t base, uint32_t intFlags);

#define I2C_clearStatus I2C_clearInterruptStatus

extern I2C_InterruptSource
I2C_getInterruptSource(uint32_t base);

void I2C_initConfig(uint32_t i2c_base, I2C_INIT_PARAM *init_param);

extern uint32_t I2C_MasterStatusCheck(uint32_t base);
extern uint32_t I2C_SendStatusCheck(uint32_t base);
uint32_t I2C_ReceiveStatusCheck(uint32_t base);
void I2C_SetAddress(uint32_t base, uint16_t device_addr);
void I2C_FlushRxfifo(uint32_t base);
uint32_t I2C_WaitForBusy(uint32_t base);
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* _I2C_H_ */

