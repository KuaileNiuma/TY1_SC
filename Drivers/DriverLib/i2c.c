/**
 *************************************************************************************
 * @file i2c.c
 * @brief This file implements the function of I2C driver.
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

#include "i2c.h"


//*****************************************************************************
//
// I2C_setTargetAddress
//
//*****************************************************************************
void I2C_setTargetAddress(uint32_t base, uint16_t targetAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    ASSERT(targetAddr <= I2C_IC_TAR_IC_TAR);

    if (targetAddr == 0)
    {
        I2C_enableGeneralCall(base);
    }
    else
    {
        //HWREG(base + I2C_O_IC_TAR) = (HWREG(base + I2C_O_IC_TAR) & (~I2C_IC_TAR_IC_TAR)) | targetAddr;
        HWREG(base + I2C_O_IC_TAR) = targetAddr;  //7bit mode
    }
}

//*****************************************************************************
//
// I2C_setSlaveAddress,This is same as "I2C_setTargetAddress"
//
//*****************************************************************************
void I2C_setSlaveAddress(uint32_t base, uint16_t targetAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    ASSERT(targetAddr <= I2C_IC_TAR_IC_TAR);

    if (targetAddr == 0)
    {
        I2C_enableGeneralCall(base);
    }
    else
    {
        //HWREG(base + I2C_O_IC_TAR) = (HWREG(base + I2C_O_IC_TAR) & (~I2C_IC_TAR_IC_TAR)) | targetAddr;
        HWREG(base + I2C_O_IC_TAR) = targetAddr;  //7bit mode
    }
}

//*****************************************************************************
//
// I2C_initController
//
//*****************************************************************************
void
I2C_initController(uint32_t base, uint32_t sysclkHz, uint32_t bitRate,
                   I2C_DutyCycle dutyCycle)
{
    uint32_t divider;
    uint32_t spklen = HWREGH(base + I2C_O_IC_FS_SPKLEN);
    uint32_t clkh;
    uint32_t clkl;

    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    ASSERT(bitRate <= 400000U);

    //
    // Set the divider for the time low
    //
    divider = (sysclkHz / bitRate);

    if(dutyCycle == I2C_DUTYCYCLE_50)
    {
        clkh = divider / 2U;
    }
    else
    {
        clkh = divider / 3U;
    }

    clkl = divider - clkh;

    clkh -= (7 + spklen + (sysclkHz / (20 * 1000 * 1000)));
    clkl -= (1 + (sysclkHz / (20 * 1000 * 1000)));

    ASSERT(clkh > spklen + 5);
    ASSERT(clkl > spklen + 7);

    if (I2C_getSpeedMode(base) == I2C_FAST_SPEED_MODE)
    {
        HWREGH(base + I2C_O_IC_FS_SCL_HCNT) = clkh;
        HWREGH(base + I2C_O_IC_FS_SCL_LCNT) = clkl;
    }
    else
    {
        HWREGH(base + I2C_O_IC_SS_SCL_HCNT) = clkh;
        HWREGH(base + I2C_O_IC_SS_SCL_LCNT) = clkl;
    }
}

//*****************************************************************************
//
// I2C_setSDAHoldTime
//
//*****************************************************************************
void I2C_setSDAHoldTime(uint32_t base, uint8_t rxHoldTime, uint16_t txHoldTime)
{
    uint32_t sclHCNT;
    uint32_t sclLCNT;
    uint32_t spklen;

    ASSERT(I2C_isBaseValid(base));

    if (HWREG(base + I2C_O_IC_CON) & I2C_IC_CON_SPEEDL)
    {
        sclHCNT = HWREG(base + I2C_O_IC_SS_SCL_HCNT);
        sclLCNT = HWREG(base + I2C_O_IC_SS_SCL_LCNT);
    }
    else
    {
        sclHCNT = HWREG(base + I2C_O_IC_FS_SCL_HCNT);
        sclLCNT = HWREG(base + I2C_O_IC_FS_SCL_LCNT);
    }
    spklen = HWREG(base + I2C_O_IC_FS_SPKLEN);

    ASSERT((rxHoldTime >= 0) && (rxHoldTime < sclHCNT - spklen - 3));
    ASSERT((txHoldTime > 0) && (txHoldTime <= sclLCNT - 2));

    HWREG(base + I2C_O_IC_SDA_HOLD) = (HWREG(base + I2C_O_IC_SDA_HOLD) & (~I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD)) | txHoldTime;
    HWREG(base + I2C_O_IC_SDA_HOLD) = (HWREG(base + I2C_O_IC_SDA_HOLD) & (~I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD)) | rxHoldTime;
}

//*****************************************************************************
//
// I2C_clearInterruptStatus
//
//*****************************************************************************
void I2C_clearInterruptStatus(uint32_t base, uint32_t intFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    if ((intFlags & I2C_INT_ARB_LOST) || (intFlags & I2C_INT_NO_ACK))
        (void)HWREG(base + I2C_O_IC_CLR_TX_ABRT);
    if (intFlags & I2C_INT_STOP_CONDITION)
        (void)HWREG(base + I2C_O_IC_CLR_STOP_DET);
    if (intFlags & I2C_INT_ADDR_ZERO)
        (void)HWREG(base + I2C_O_IC_CLR_GEN_CALL);
//    if (intFlags & I2C_INT_ADDR_TARGET)
//        (void)HWREG(base + I2C_O_IC_CLR_SLV_ADDR_TAG);
    if (intFlags & I2C_INT_RD_REQ)
        (void)HWREG(base + I2C_O_IC_CLR_RD_REQ);
//    if (intFlags & I2C_INT_WR_REQ)
//        (void)HWREG(base + I2C_O_IC_CLR_WR_REQ);
    if (intFlags & I2C_INT_RESTART_DET)
        (void)HWREG(base + I2C_O_IC_CLR_RESTART_DET);
    if (intFlags & I2C_INT_START_DET)
        (void)HWREG(base + I2C_O_IC_CLR_START_DET);
    if (intFlags & I2C_INT_ACTIVITY)
        (void)HWREG(base + I2C_O_IC_CLR_ACTIVITY);
    if (intFlags & I2C_INT_RX_DONE)
        (void)HWREG(base + I2C_O_IC_CLR_RX_DONE);
    if (intFlags & I2C_INT_TX_OVER)
        (void)HWREG(base + I2C_O_IC_CLR_TX_OVER);
    if (intFlags & I2C_INT_RX_OVER)
        (void)HWREG(base + I2C_O_IC_CLR_RX_OVER);
    if (intFlags & I2C_INT_RX_UNDER)
        (void)HWREG(base + I2C_O_IC_CLR_RX_UNDER);
    if (intFlags & I2C_INT_TX_ABRT)
        (void)HWREG(base + I2C_O_IC_CLR_TX_ABRT);
}

//*****************************************************************************
//
// I2C_getInterruptSource
//
//*****************************************************************************
I2C_InterruptSource
I2C_getInterruptSource(uint32_t base)
{
    uint32_t flag = HWREG(base + I2C_O_IC_INTR_STAT);
    uint32_t txAbrtSrc = HWREG(base + I2C_O_IC_TX_ABRT_SOURCE);
    if ((flag & I2C_INT_TX_ABRT) && (txAbrtSrc & I2C_TXARB_LOST))
        return I2C_INTSRC_ARB_LOST;            //!< Arbitration-lost interrupt

    if ((flag & I2C_INT_TX_ABRT) && (txAbrtSrc & (I2C_TXABRT_7B_ADDR_NOACK | I2C_TXABRT_10ADDR1_NOACK | I2C_TXABRT_10ADDR2_NOACK | I2C_TXABRT_TXDATA_NOACK | I2C_TXABRT_GCALL_NOACK)))
        return I2C_INTSRC_NO_ACK;              //!< NACK interrupt
    if (flag & I2C_INT_RX_DATA_RDY)
        return I2C_INTSRC_RX_DATA_RDY;         //!< Receive-data-ready interrupt
    if (flag & I2C_INT_TX_DATA_RDY)
        return I2C_INTSRC_TX_DATA_RDY;         //!< Transmit-data-ready interrupt
    if (flag & I2C_INT_STOP_CONDITION)
        return I2C_INTSRC_STOP_CONDITION;      //!< Stop condition detected
    if (flag & I2C_INT_ADDR_TARGET)
        return I2C_INTSRC_ADDR_TARGET;         //!< Addressed as target interrupt

    return I2C_INTSRC_NONE;
}

//*****************************************************************************
//
// I2C_initConfig
//
//*****************************************************************************
void I2C_initConfig(uint32_t i2c_base, I2C_INIT_PARAM *init_param)
{
    uint32_t ic_con_params = 0;

    ASSERT(init_param->apbclk_freq);

    ic_con_params = init_param->master_mode | init_param->speed_mode | I2C_TX_EMPTY_CTRL | I2C_RESTART_EN|I2C_STOP_DET_IF_MASTER_ACTIVE;
    I2C_disableModule(i2c_base);
    I2C_disableInterrupt(i2c_base, 0xFFFFFFFF);
    I2C_clearAllInterruptStatus(i2c_base);
    I2C_setConfig(i2c_base, ic_con_params);
    I2C_setAddressMode(i2c_base, I2C_ADDR_MODE_7BITS);

    if (init_param->master_mode == I2C_MASTER_MODE)
    {
        I2C_setTargetAddress(i2c_base, init_param->slave_addr);
    }
    else
    {
        I2C_setOwnAddress(i2c_base, init_param->slave_addr);
    }

    I2C_enableFIFO(i2c_base);
    I2C_setFIFOInterruptLevel(i2c_base, I2C_FIFO_TX0, I2C_FIFO_RX1);
    I2C_initController(i2c_base, init_param->apbclk_freq, init_param->baudrate, I2C_DUTYCYCLE_50);
    I2C_enableModule(i2c_base);
}

//*****************************************************************************
//
// I2C_MasterStatusCheck
//
//*****************************************************************************
uint32_t I2C_MasterStatusCheck(uint32_t base)
{
    uint32_t retry_cnt = 0;

    while (I2C_getIcStatus(base) & I2C_ICSTS_MST_ACTIVITY)
    {
        if (retry_cnt++ == I2C_RETRY_LIMIT)
            return 1;
    }
    return 0;
}

/*
 * wait until Tx FIFO is empty
 * return 0 if TXFIFO empty
 * return 1 if TXFIFO not empty
 * */
uint32_t I2C_SendStatusCheck(uint32_t base)
{
    uint32_t retry_cnt = 0;

    while (!(I2C_getInterruptRawStatus(base) & I2C_IC_INTR_STAT_TX_EMPTY))
        {
             if (retry_cnt++ == I2C_RETRY_LIMIT)
             return 1;
        }
//    while (!(I2C_getIcStatus(base) & I2C_ICSTS_TFE))
//    {
//        if (retry_cnt++ == I2C_RETRY_LIMIT)
//            return 1;
//    }
    return 0;
}

/*
 * wait until Rx FIFO is not empty
 * return 0 if RXFIFO not empty
 * return 1 if RXFIFO empty
 * */
uint32_t I2C_ReceiveStatusCheck(uint32_t base)
{
    uint32_t retry_cnt = 0;

    /* wait if Rx FIFO is empty */
    while (!(I2C_getIcStatus(base) & I2C_ICSTS_RFNE))
    {
        if (retry_cnt++ == I2C_RETRY_LIMIT)
            return 1;
    }
    return 0;
}


void I2C_SetAddress(uint32_t base, uint16_t device_addr)
{
    /* Disable i2c */
    HWREG(base + I2C_O_IC_ENABLE) &= ~I2C_IC_ENABLE_ENABLE;

    /*
	wait until IC_EN goes to 0 in IC_ENABLE_STATUS
    which means it has completely been disabled
	*/
    while ( (HWREG(base +I2C_O_IC_ENABLE_STATUS) & I2C_IC_ENABLE_STATUS_IC_EN) != 0);

    I2C_setTargetAddress(base, device_addr);

    /* Enable i2c */
    HWREG(base + I2C_O_IC_ENABLE) |= I2C_IC_ENABLE_ENABLE;
}



void I2C_FlushRxfifo(uint32_t base)
{
	uint32_t tmp32 = 0;
	/*Read the rxfifo uintil rxfifo is empty*/
    while (!(I2C_getIcStatus(base) & I2C_ICSTS_RFNE))
	{
        tmp32 =  HWREG(base + I2C_O_IC_DATA_CMD);
    }
}


uint32_t I2C_WaitForBusy(uint32_t base)
{
    uint32_t timeout = 0 ;
    while (((I2C_getIcStatus(base) & I2C_ICSTS_MST_ACTIVITY) != 0) ||
           ((I2C_getIcStatus(base) & I2C_ICSTS_TFE) == 0))
	{
        /* Evaluate timeout */
        if (timeout++ > I2C_RETRY_LIMIT)
		{
            return 1;  /*i2c is busy*/
        }
    }

    return 0; /*i2c is idle*/
}



