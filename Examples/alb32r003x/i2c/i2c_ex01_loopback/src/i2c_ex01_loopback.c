/**
 *************************************************************************************
 * @file i2c_ex01_loopback.c
 * @brief This file contains the source file for example i2c_ex01_loopback.
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

#include "i2c_ex01_loopback.h"
#include <string.h>
#include <stdio.h>
#include "alb32r003x_evb.h"


//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define I2C_TEST_COUNT   16          //!< I2C test data count
#define SLAVE_ADDRESS    0x55        //!< I2C slave address

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t g_i2c_base = myI2C_BASE;   //!< I2C base address
uint32_t i2c_port_num = 0;          //!< I2C port number
uint32_t rx_buff[I2C_TEST_COUNT] = {0}; //!< I2C receive buffer


//*****************************************************************************
//
// I2C Initialization Function
//
//*****************************************************************************
void myi2c_init(uint32_t i2c_base)
{
	//
	// Determine I2C port number based on base address
	//
	if (i2c_base == I2C1_BASE)
	{
		i2c_port_num = 0;
		SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C1);
		SysCtl_setGPIOxPullEnable(32 ,ENABLE);
		SysCtl_setGPIOxPullSel(32, GPIOx_PULL_UP);
		SysCtl_setGPIOxPullEnable(33 ,ENABLE);
		SysCtl_setGPIOxPullSel(33, GPIOx_PULL_UP);

	    SysCtl_enablePeripheral(myI2C_GPIO_CLK_EN);
	    GPIO_setPinConfig(myI2C_SDA_PIN);
	    GPIO_setPinConfig(myI2C_SCL_PIN);
	}
	else if (i2c_base == I2C2_BASE)
	{
		i2c_port_num = 1;
		SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C2);
		SysCtl_setGPIOxPullEnable(2 ,ENABLE);
		SysCtl_setGPIOxPullSel(2, GPIOx_PULL_UP);
		SysCtl_setGPIOxPullEnable(3 ,ENABLE);
		SysCtl_setGPIOxPullSel(3, GPIOx_PULL_UP);

	    SysCtl_enablePeripheral(myI2C_GPIO_CLK_EN);
	    GPIO_setPinConfig(myI2C_SDA_PIN);
	    GPIO_setPinConfig(myI2C_SCL_PIN);
	}
	else if (i2c_base == I2C3_BASE)
	{
		i2c_port_num = 2;
		SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C3);
		SysCtl_setGPIOxPullEnable(62 ,ENABLE);
		SysCtl_setGPIOxPullSel(62, GPIOx_PULL_UP);
		SysCtl_setGPIOxPullEnable(230 ,ENABLE);
		SysCtl_setGPIOxPullSel(230, GPIOx_PULL_UP);

	    SysCtl_enablePeripheral(myI2C_GPIO_CLK_EN);
	    GPIO_setPinConfig(myI2C_SDA_PIN);
	    GPIO_setPinConfig(myI2C_SCL_PIN);
	}
	else
	{
		printf("i2c base error 0x%x \r\n", i2c_base);
		return;
	}

	//
	// Store I2C base address
	//
	g_i2c_base = i2c_base;
	//
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
	I2C_setTargetAddress(i2c_base, SLAVE_ADDRESS);
	//
	// Configure I2C in master mode
	//
	I2C_setConfig(i2c_base, I2C_MASTER_MODE);
	//
	// Initialize I2C controller with system clock, 100kHz bus frequency and 50% duty cycle
	//
	I2C_initController(i2c_base, SystemClock_Get_APBL(), 100000, I2C_DUTYCYCLE_50);
	//
	// Enable I2C module
	//
	I2C_enableModule(i2c_base);
}


//*****************************************************************************
//
// I2C Polling Read/Write Function
//
//*****************************************************************************
void i2c_write_read_polling(void)
{
	//
	// Transmit and receive test data
	//
	for (uint32_t i = 0; i < I2C_TEST_COUNT; i++)
    {
		//
		// Wait until Tx Buff is empty
		//
		I2C_pollTxEmpty(g_i2c_base);

		//
		// For the last data byte, send with stop condition
		// For other bytes, send data normally
		//
		if(i == I2C_TEST_COUNT-1)
		{
			I2C_sendCmdWriteAndStop(g_i2c_base, i);
		}
		else
		{
			//
			// Send I2C data into TxFIFO
			//
			I2C_putData(g_i2c_base, i);
		}

		//
		// Check if I2C Rx FIFO is not empty
		//
		I2C_pollRxFull(g_i2c_base);

		//
		// Read I2C data from RxFIFO
		//
		rx_buff[i] = I2C_getData(g_i2c_base);

    }

	//
	// Verify received data against transmitted data
	//
	for (uint32_t i = 0; i < I2C_TEST_COUNT; i++)
	{
		//
		// Compare the Rx data with Tx data
		//
		if (rx_buff[i] != i)
		{
			printf("i2c%d loopback test fail  i %d  rx_buff %d\r\n", i2c_port_num, i, rx_buff[i]);
			return;
		}
	}
	//
	// Print success message if all data matches
	//
	printf("i2c%d loopback test OK \r\n", i2c_port_num);
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
    // Enable global interrupts
    //
	CPU_enableIrq();

    //
    // Configure GPIO pins as I2C_SDA and I2C_CLK
    //



    //
    // Initialize I2C interface
    //
    myi2c_init(g_i2c_base);

    //
    // Configure I2C loopback mode, must set own address as slave address
    //
    I2C_setOwnAddress(g_i2c_base, SLAVE_ADDRESS);
    I2C_enableLoopback(g_i2c_base);

    //
    // Print start message
    //
    printf("i2c_ex01_loopback start \r\n");
    //
    // Run I2C read/write polling test
    //
    i2c_write_read_polling();
    //
    // Print end message
    //
    printf("i2c_ex01_loopback end \r\n");
    //
    // Infinite loop
    //
    for(;;);
}
