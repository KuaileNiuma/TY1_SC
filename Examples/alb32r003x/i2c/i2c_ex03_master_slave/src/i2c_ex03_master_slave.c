/**
 *************************************************************************************
 * @file i2c_ex03_master_slave.c
 * @brief This file contains the source file for example i2c_ex03_master_slave.
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

#include "i2c_ex03_master_slave.h"

#include <string.h>
#include <stdio.h>
#include "gpio.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define W_DATA_LEN         256        //!< Data length for I2C communication
#define I2C_SLAVE_ADDRESS  0x20       //!< I2C slave address

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint8_t wdata[W_DATA_LEN] = {0};                    //!< Write data buffer
uint8_t master_rdata[W_DATA_LEN] = {0};             //!< Master receive data buffer
uint8_t slave_rdata[W_DATA_LEN] = {0};              //!< Slave receive data buffer
uint32_t i2c_master_port = 0;                       //!< Master I2C port number
uint32_t i2c_slave_port = 1;                        //!< Slave I2C port number

volatile uint32_t i2c_slave_rcv_data_len = 0;       //!< Slave received data length
volatile uint32_t i2c_slave_send_data_len = 0;      //!< Slave sent data length


//*****************************************************************************
//
// I2C Master Interrupt Handler
// 
//*****************************************************************************
__INTERRUPT void MasterI2CISR(void)
{
    //
    // Get interrupt status
    //
    uint32_t irq_status = I2C_getInterruptStatus(myMasterI2C_BASE);

    //
    // Check and handle error interrupts
    //
    i2c_err_irq_check(myMasterI2C_BASE, i2c_master_port, irq_status);

    //
    // Clear all interrupt status bits
    //
    I2C_clearAllInterruptStatus(myMasterI2C_BASE);
}

//*****************************************************************************
//
// I2C Slave Interrupt Handler
// 
//*****************************************************************************
__INTERRUPT void SlaveI2CISR(void)
{
    uint16_t i = 0;
    //
    // Get interrupt status
    //
    uint32_t irq_status;
    irq_status = I2C_getInterruptStatus(mySlaveI2C_BASE);
    //
    // Check and handle error interrupts
    //
    i2c_err_irq_check(mySlaveI2C_BASE, i2c_slave_port, irq_status);

    //
    // Handle read request from master
    //
    if (irq_status & I2C_IC_INTR_STAT_RD_REQ)
    {
		//if ((I2C_getIcStatus(mySlaveI2C_BASE) & I2C_ICSTS_TFNF) == I2C_ICSTS_TFNF)
		{
			//
			// Send data to master
			//
			I2C_putData(mySlaveI2C_BASE, slave_rdata[i2c_slave_send_data_len++]);
		}

        //
        // Clear read request interrupt
        //
        I2C_clearInterruptRdReq(mySlaveI2C_BASE);
    }

    //
    // Handle receive full interrupt
    // Note: I2C_IC_INTR_STAT_WR_REQ may be triggered when there's no data in the FIFO
    //
    if (irq_status & I2C_IC_INTR_STAT_RX_FULL)
    {
        //
        // Check if Rx FIFO is not empty
        //
        if ((I2C_getIcStatus(mySlaveI2C_BASE) & I2C_ICSTS_RFNE) == I2C_ICSTS_RFNE)
        {
        	//
        	// Read data from Rx FIFO
        	//
        	slave_rdata[i2c_slave_rcv_data_len] = I2C_getData(mySlaveI2C_BASE);
        	i2c_slave_rcv_data_len++;
        }
        else
        {
        	printf("irq rx fifo is empty 0x%x\r\n", irq_status);
        }
    }

    //
    // Clear all interrupt status bits
    //
    I2C_clearAllInterruptStatus(mySlaveI2C_BASE);
}

//*****************************************************************************
//
// I2C Slave Verification Function
//
//*****************************************************************************
void i2c_slave_init(uint32_t i2c_base)
{
    uint32_t i = 0;

    //
    //Enable I2C Peripheral
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C2);

    //
    //I2C pins need pull up
    //
    SysCtl_enablePeripheral(myI2C2_GPIO_CLK_EN);
    SysCtl_setGPIOxPullEnable(2 ,ENABLE);
    SysCtl_setGPIOxPullSel(2, GPIOx_PULL_UP);
    SysCtl_setGPIOxPullEnable(3 ,ENABLE);
    SysCtl_setGPIOxPullSel(3, GPIOx_PULL_UP);

    //
    // Configure GPIO pins for Master I2C SDA and SCL
    //
    GPIO_setPinConfig(mySlaveI2C_SDA_PIN);
    GPIO_setPinConfig(mySlaveI2C_SCL_PIN);

    //
    // Initialize I2C in slave mode
	// Disable I2C module before configuration
	//
	I2C_disableModule(i2c_base);
	
	//
	// Disable all I2C interrupts
	//
	I2C_disableInterrupt(i2c_base, 0xFFFFFFF);
	
	//
	// Set target address for I2C communication
	//
	I2C_setOwnAddress(i2c_base, I2C_SLAVE_ADDRESS);
	
	//
	// Configure I2C in slave mode
	//
	I2C_setConfig(i2c_base, I2C_SLAVE_MODE);
	
	//
	// Initialize I2C controller with system clock, 400kHz bus frequency and 50% duty cycle
	//
	I2C_initController(i2c_base, SystemClock_Get_APBL(), 400000, I2C_DUTYCYCLE_50);
	
	//
	// Enable I2C module
	//
	I2C_enableModule(i2c_base);

    //
    // Configure I2C interrupts - error interrupts
    //
    I2C_enableInterrupt(i2c_base, I2C_INT_RX_OVER | I2C_INT_RX_UNDER | I2C_INT_TX_ABRT | I2C_INT_TX_OVER);

    //
    // Configure I2C interrupts - data transfer interrupts
    //
    I2C_enableInterrupt(i2c_base, I2C_INT_RXFF | I2C_INT_WR_REQ | I2C_INT_RD_REQ | I2C_INT_RX_DONE);
    
    //
    // Register and configure ECLIC interrupt
    //
    Interrupt_register(mySlaveI2C_IRQn, SlaveI2CISR);
    Interrupt_enable(mySlaveI2C_IRQn);
}

//*****************************************************************************
//
// I2C Master Verification Function
// 
//*****************************************************************************
void i2c_master_init(uint32_t i2c_base)
{
    //
    //Enable I2C Peripheral
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C1);

    //
    //I2C pins need pull up
    //
    SysCtl_enablePeripheral(myI2C1_GPIO_CLK_EN);
    SysCtl_setGPIOxPullEnable(33 ,ENABLE);
    SysCtl_setGPIOxPullSel(33, GPIOx_PULL_UP);
    SysCtl_setGPIOxPullEnable(32 ,ENABLE);
    SysCtl_setGPIOxPullSel(32, GPIOx_PULL_UP);

    //
    // Configure GPIO pins for Master I2C SDA and SCL
    //
    GPIO_setPinConfig(myMasterI2C_SDA_PIN);
    GPIO_setPinConfig(myMasterI2C_SCL_PIN);

    //
    // Initialize I2C in master mode
	// Disable I2C module before configuration
	//
	I2C_disableModule(i2c_base);

	//
	// Disable all I2C interrupts
	//
	I2C_disableInterrupt(i2c_base, 0xFFFFFFF);

	//
	// Set target address for I2C communication
	//
	I2C_setTargetAddress(i2c_base,I2C_SLAVE_ADDRESS);

	//
	// Configure I2C in master mode
	//
	I2C_setConfig(i2c_base, I2C_MASTER_MODE);

	//
	// Initialize I2C controller with system clock, 400kHz bus frequency and 50% duty cycle
	//
	I2C_initController(i2c_base, SystemClock_Get_APBL(), 400000, I2C_DUTYCYCLE_50);

	//
	// Enable I2C module
	//
	I2C_enableModule(i2c_base);

    //
    // Configure I2C error interrupts
    //
    I2C_enableInterrupt(i2c_base, I2C_INT_RX_OVER | I2C_INT_RX_UNDER | I2C_INT_TX_ABRT | I2C_INT_TX_OVER);
    
    //
    // Register and configure ECLIC interrupt
    //
    Interrupt_register(myMasterI2C_IRQn, MasterI2CISR);
    Interrupt_enable(myMasterI2C_IRQn);

}


//*****************************************************************************
//
// I2C Master-Slave Example Function
//
//*****************************************************************************
void i2c_ex03_master_slave(void)
{
    uint32_t i = 0;

    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Initialize write data buffer
    //
    for (i = 0; i < W_DATA_LEN; i++)
    {
        wdata[i] = i + 1;
    }

    //
    // Initialize and configure I2C in slave mode
    //
    i2c_slave_init(mySlaveI2C_BASE);
    i2c_slave_port = 1;

    //
    // Initialize and configure I2C in master mode
    //
    i2c_master_init(myMasterI2C_BASE);
    i2c_master_port = 0;

    //
    // Send data to slave
    //
    i2c_DataCmdWrite(myMasterI2C_BASE, wdata, W_DATA_LEN, I2C_NEXT_CONDITION_STOP);

    //
    // Delay to ensure slave has processed the data
    //
    delay_ms(20);

    //
    // Read data from slave in chunks of 16 bytes
    //
    for (i = 0; i < W_DATA_LEN / 16; i++)
    {
        i2c_DataCmdRead(myMasterI2C_BASE, master_rdata + i * 16, 16, I2C_NEXT_CONDITION_STOP);
    }

    //
    // Read any remaining data (if W_DATA_LEN is not a multiple of 16)
    //
    if (W_DATA_LEN % 16 != 0)
    {
        i2c_DataCmdRead(myMasterI2C_BASE, master_rdata + i * 16, W_DATA_LEN % 16, I2C_NEXT_CONDITION_STOP);
    }
    
    //
    // Reset slave send data length counter
    //
    i2c_slave_send_data_len = 0;

    //
    // Verify received data against transmitted data
    //
    for (i = 0; i < W_DATA_LEN; i++)
    {
        if (wdata[i] != master_rdata[i])
        {
            printf("master i2c%d slave i2c%d write read test fail wdata %d rdata %d \r\n", i2c_master_port, i2c_slave_port, wdata[i], master_rdata[i]);
            return;
        }
    }
    
    //
    // Print success message if all data matches
    //
    printf("master i2c%d slave i2c%d write read test OK \r\n", i2c_master_port, i2c_slave_port);


    //
    // Print end message
    //
    printf("i2c_test03_master_slave end \r\n");
}

//*****************************************************************************
//
// Main Function
// 
//*****************************************************************************
int main(void)
{
    alb32r003x_evb_init();

    //
    // Print start message
    //
    printf("i2c_ex03_master_slave start \r\n");

    //
    // Run I2C master-slave example
    //
    i2c_ex03_master_slave();

    //
    // Infinite loop
    //
    for(;;);
}
