/**
 *************************************************************************************
 * @file i2c_ex02_loopback_irq.c
 * @brief This file contains the source file for example i2c_ex02_loopback_irq.
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

#include "i2c1_loopback_interrupt.h"

#include <string.h>
#include <stdio.h>
#include "gpio.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"


//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define SLAVE_ADDRESS      0x55       //!< I2C slave address
#define I2C_TEST_COUNT     16         //!< I2C test data count

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t g_i2c_base = myI2C_BASE;        //!< I2C base address
uint32_t i2c_port_num = 0;               //!< I2C port number
volatile uint32_t i2c_test_finish = 0;   //!< Test completion flag
volatile int i2c_test_result = 0;       //!< 1=pass, -1=fail

//*****************************************************************************
//
// I2C Interrupt Handler
//
// This function handles I2C interrupts, processing both receive and transmit
// interrupts in loopback mode.
//
//*****************************************************************************
__INTERRUPT void I2CISR(void)
{
    uint8_t i = 0;                //!< Loop counter
    uint8_t rx_buff[I2C_TEST_COUNT] = {0}; //!< Receive buffer
    uint32_t irq_status = I2C_getInterruptStatus(g_i2c_base); //!< Interrupt status

    //
    // Handle receive full interrupt
    //
    if (irq_status & I2C_IC_INTR_STAT_RX_FULL)
    {
        //
        // Read and verify received data
        //
        for (i = 0; i < I2C_TEST_COUNT; i++)
        {
            //
            // Wait until receive FIFO is not empty
            //
            while ((I2C_getIcStatus(g_i2c_base) & I2C_ICSTS_RFNE) != I2C_ICSTS_RFNE);

            //
            // Read data from receive FIFO
            //
            rx_buff[i] = I2C_getData(g_i2c_base);

            //
            // Verify received data matches expected value
            //
            if (rx_buff[i] != i)
            {
                printf("i2c%d loopback test fail i %d rx_buff %d\r\n", i2c_port_num, i, rx_buff[i]);
                i2c_test_result = -1;
                break;
            }
        }

        //
        // Print success message if all data was verified
        //
        if (i == I2C_TEST_COUNT)
        {
        	printf("i2c%d loopback test ok \r\n", i2c_port_num);
            i2c_test_result = 1;
        }

        //
        // Mark test as finished and disable interrupts
        //
        i2c_test_finish = 1;
        I2C_disableInterrupt(g_i2c_base, I2C_IC_INTR_MASK_M_RX_FULL);
        I2C_clearAllInterruptStatus(g_i2c_base);
        I2C_disableModule(g_i2c_base);
    }
    //
    // Handle transmit empty interrupt
    //
    else if (irq_status & I2C_IC_INTR_STAT_TX_EMPTY)
    {
        //
        // Transmit test data
        //
        for (i = 0; i < I2C_TEST_COUNT; i++)
        {
            //
            // Wait until transmit FIFO is not full
            //
            while ((I2C_getIcStatus(g_i2c_base) & I2C_ICSTS_TFNF) != I2C_ICSTS_TFNF);
            
            //
            // For last byte, send with stop condition
            //
            if(i == I2C_TEST_COUNT-1){
				I2C_sendCmdWriteAndStop(g_i2c_base, i);
			} else {
				//
				// Send data into transmit FIFO
				//
				I2C_putData(g_i2c_base, i);
			}
        }
        
        //
        // Disable transmit empty interrupt
        //
        I2C_disableInterrupt(g_i2c_base, I2C_IC_INTR_MASK_M_TX_EMPTY);
    }
    //
    // Handle unexpected interrupts
    //
    else
    {
    	//printf("i2c%d irq error 0x%x \r\n", i2c_port_num, irq_status);
    	I2C_clearAllInterruptStatus(g_i2c_base);
    }
}

//*****************************************************************************
//
// I2C Loopback Verification Function
//
// This function configures and verifies I2C communication in loopback mode
// using interrupts.
//
//*****************************************************************************
void i2c_loopback_verify(uint32_t i2c_base)
{
	I2C_INIT_PARAM init_param = {0}; //!< I2C initialization parameters

    //
    // Store I2C base address
    //
    g_i2c_base = i2c_base;

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
    // Enable global interrupts
    //
    CPU_enableIrq();

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
    // Configure I2C in master mode with transmit empty control and restart enabled
    //
	I2C_setConfig(i2c_base, I2C_MASTER_MODE | I2C_TX_EMPTY_CTRL | I2C_RESTART_EN);
    
    //
    // Initialize I2C controller with 400kHz bus frequency and 50% duty cycle
    //
	I2C_initController(i2c_base, SystemClock_Get_APBL(), 400000, I2C_DUTYCYCLE_50);
    
    //
    // Enable I2C module
    //
	I2C_enableModule(i2c_base);

    //
    // Set own address and enable loopback mode
    //
	I2C_setOwnAddress(i2c_base, SLAVE_ADDRESS);
	I2C_enableLoopback(i2c_base);

    //
    // Enable receive full and transmit empty interrupts
    //
	I2C_enableInterrupt(i2c_base, I2C_IC_INTR_MASK_M_RX_FULL | I2C_IC_INTR_MASK_M_TX_EMPTY);
    
    //
    // Register and enable I2C interrupt handler
    //
    Interrupt_register(myI2C_IRQn, I2CISR);
    Interrupt_setPriority(myI2C_IRQn, 0, 0);
    Interrupt_enable(myI2C_IRQn);

    //
    // Wait for test completion
    //
    while(i2c_test_finish == 0);
    i2c_test_finish = 0;
}


//*****************************************************************************
//
// I2C Loopback Interrupt Test Function
//
// This function configures GPIO pins for I2C and runs the loopback test.
//
//*****************************************************************************
void i2c_test02_loopback_irq(void)
{
    //
    // Configure GPIO pins as I2C_SDA and I2C_CLK
    //
    SysCtl_enablePeripheral(myI2C_GPIO_CLK_EN);

    //
    // Configure GPIO pins for I2C SDA and SCL
    //
	GPIO_setPinConfig(myI2C_SDA_PIN);
	GPIO_setPinConfig(myI2C_SCL_PIN);

    //
    // Run I2C loopback verification
    //
    i2c_loopback_verify(myI2C_BASE);

    //
    // Print test end message
    //
    printf("i2c_test02_loopback_interrupt end \r\n");
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
    // Print test start message
    //
    printf("i2c1_loopback_interrupt start \r\n");

    //
    // Run I2C loopback interrupt test
    //
    i2c_test02_loopback_irq();

    //
    // Return test result
    //
    return (i2c_test_result > 0) ? SC_PASS : SC_FAIL;
}
