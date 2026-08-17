/**
 *************************************************************************************
 * @file i2c_ex03_master_slave.h
 * @brief This file contains the header file for example i2c_ex03_master_slave.
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



#ifndef __I2C_EX03_MASTER_SLAVE_H__
#define __I2C_EX03_MASTER_SLAVE_H__

#include "i2c.h"
#include "device.h"
//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define myMasterI2C_BASE	  I2C1_BASE       //!< Master I2C base address selection
#define myMasterI2C_SDA_PIN	  GPIO_32_I2CA_SDA //!< Master I2C SDA pin definition
#define myMasterI2C_SCL_PIN	  GPIO_33_I2CA_SCL //!< Master I2C SCL pin definition
#define myMasterI2C_IRQn      I2C1_IRQn       //!< Master I2C interrupt vector


#define mySlaveI2C_BASE	      I2C2_BASE       //!< Slave I2C base address selection
#define mySlaveI2C_SDA_PIN	  GPIO_2_I2CB_SDA //!< Slave I2C SDA pin definition
#define mySlaveI2C_SCL_PIN	  GPIO_3_I2CB_SCL //!< Slave I2C SCL pin definition
#define mySlaveI2C_IRQn       I2C2_IRQn       //!< Slave I2C interrupt vector

#define myI2C1_GPIO_CLK_EN	SYSCTL_PERIPH_CLK_GPIOB
#define myI2C2_GPIO_CLK_EN	SYSCTL_PERIPH_CLK_GPIOA

//*****************************************************************************
//
// Enumerations
//
//*****************************************************************************
typedef enum
{
    I2C_NEXT_CONDITION_NONE          = 0x01, //!< No special condition
    I2C_NEXT_CONDITION_STOP          = 0x02, //!< Generate stop condition
    I2C_NEXT_CONDITION_RESTART       = 0x04, //!< Generate restart condition
} I2C_NEXT_CONDITION;                              //!< I2C next condition enumeration


//*****************************************************************************
//
// I2C Data Command Write Function
//
//*****************************************************************************
int32_t i2c_DataCmdWrite(uint32_t base, uint8_t *data_cmd, uint32_t data_cmd_len, I2C_NEXT_CONDITION next_cond)
{
    int32_t err = 0;
    uint32_t i = 0;
    //
    // Check if I2C is in master mode
    //
    if (I2C_getIcMode(base) == I2C_ICMODE_MASTER)
    {
        //
        // Loop through each data byte to be transmitted
        //
        for (i = 0; i < data_cmd_len; i++)
        {
            //
            // Wait until Tx FIFO is empty
            //
            I2C_pollTxEmpty(base);

            //
            // Handle special conditions based on next_cond flag
            //
            if ((next_cond & I2C_NEXT_CONDITION_RESTART) && (i == 0))
            {
                //
                // First byte with restart condition
                //
                I2C_putData(base, data_cmd[i]);
            }
            else if ((next_cond & I2C_NEXT_CONDITION_STOP) && (i == (data_cmd_len - 1)))
            {
                //
                // Last byte with stop condition
                //
                I2C_sendCmdWriteAndStop(base, data_cmd[i]);
            }
            else
            {
                //
                // Normal data transmission
                //
                I2C_putData(base, data_cmd[i]);
            }
        }
    }
    else
    {
        //
        // Assert if not in master mode
        //
        ASSERT(0);
    }
    return err;
}

//*****************************************************************************
//
// I2C Data Command Read Function
//
//*****************************************************************************
int32_t i2c_DataCmdRead(uint32_t base, uint8_t *data_cmd, uint32_t data_cmd_len, I2C_NEXT_CONDITION next_cond)
{
    int32_t err = 0;
    uint32_t retry_cnt = 0;

    //
    // Check if I2C is in master mode
    //
    if (I2C_getIcMode(base) == I2C_ICMODE_MASTER)
    {
        //
        // Loop through each data byte to be read
        //
        for (uint32_t i = 0; i < data_cmd_len; i++)
        {
            //
            // Wait until Tx FIFO is empty
            //
            I2C_pollTxEmpty(base);

            //
            // Handle special conditions based on next_cond flag
            //
            if ((next_cond & I2C_NEXT_CONDITION_RESTART) && (i == 0))
            {
                //
                // First byte with restart condition
                //
                I2C_sendCmdRestartAndRead(base);
            }
            else if ((next_cond & I2C_NEXT_CONDITION_STOP) && (i == (data_cmd_len - 1)))
            {
                //
                // Last byte with stop condition
                //
                I2C_sendCmdReadAndStop(base);
            }
            else
            {
                //
                // Normal read command
                //
                I2C_sendCmdRead(base);
            }

            //
            // Wait until Rx FIFO has data
            //
            I2C_pollRxFull(base);

            //
            // Read data from Rx FIFO
            //
            *data_cmd = I2C_getData(base);
            printf("r %d \r\n", *data_cmd);
            data_cmd++;
        }
    }
    else
    {
        //
        // Assert if not in master mode
        //
        ASSERT(0);
    }
    return 0;
}

//*****************************************************************************
//
// I2C Error Interrupt Check Function
//
//*****************************************************************************
void i2c_err_irq_check(uint32_t i2c_base, uint32_t i2c_port_num, uint32_t irq_status)
{
    //
    // Check for Tx abort interrupt
    //
    if (irq_status & I2C_INT_TX_ABRT)
    {
        printf("i2c%d tx abort irq 0x%x abort source 0x%x\r\n", i2c_port_num, irq_status, I2C_getIcTxAbrtSource(i2c_base));
        I2C_clearInterruptTxAbrt(i2c_base);
    }

    //
    // Check for Tx overrun interrupt
    //
    if (irq_status & I2C_INT_TX_OVER)
    {
        printf("i2c%d tx over irq 0x%x \r\n", i2c_port_num, irq_status);
        I2C_clearInterruptTxOver(i2c_base);
    }

    //
    // Check for Rx overrun interrupt
    //
    if (irq_status & I2C_INT_RX_OVER)
    {
        printf("i2c%d rx over irq 0x%x \r\n", i2c_port_num, irq_status);
        I2C_clearInterruptRxOver(i2c_base);
    }

    //
    // Check for Rx underrun interrupt
    //
    if (irq_status & I2C_INT_RX_UNDER)
    {
        printf("i2c%d rx under irq 0x%x \r\n", i2c_port_num, irq_status);
        I2C_clearInterruptRxUnder(i2c_base);
    }
}

//*****************************************************************************
//
//! @brief I2C Master-Slave Communication Test
//! 
//! This function performs a master-slave communication test using I2C interface.
//! It initializes both master and slave I2C peripherals, configures the pins,
//! sets up interrupt handlers, and performs data transfer between them.
//! 
//*****************************************************************************
void i2c_test03_master_slave(void);

#endif
