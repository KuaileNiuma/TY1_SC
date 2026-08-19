/**
 *************************************************************************************
 * @file i2c1_eeprom_polling.c
 * @brief This file contains the source file for example i2c1_eeprom_polling.
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

#include <string.h>
#include <stdio.h>
#include "gpio.h"
#include "eeprom.h"
#include "device.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"
//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define EEPROM_SLAVE_ADDRESS   0x50         //!< EEPROM slave address
#define EEPROM_PAGE_LEN        16           //!< EEPROM page length in bytes
#define W_DATA_LEN             EEPROM_PAGE_LEN*16 //!< Total data length for EEPROM operations
#define W_ADDR                 0x00         //!< Starting address for writing to EEPROM
#define EEPROM_DATA_ADDRESS_LEN 2           //!< EEPROM address length in bytes

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t g_i2c_base = myMasterI2C_BASE;     //!< I2C base address
uint8_t wdata[W_DATA_LEN] = {0};            //!< Write data buffer
uint8_t rdata[W_DATA_LEN] = {0};            //!< Read data buffer
uint32_t i2c_port_num = 1;                  //!< I2C port number

//*****************************************************************************
//
// I2C Error Interrupt Check Function
//
//*****************************************************************************
void i2c_err_irq_check(uint32_t irq_status)
{
    //
    // Check for Tx abort interrupt
    //
    if (irq_status & I2C_INT_TX_ABRT)
    {
        printf("tx abort irq 0x%x tx_flush_cnt[31:23] 0x%x\r\n", irq_status, I2C_getIcTxAbrtSource(g_i2c_base));
        I2C_clearInterruptTxAbrt(g_i2c_base);
    }

    //
    // Check for Tx overrun interrupt
    //
    if (irq_status & I2C_INT_TX_OVER)
    {
        printf("tx over irq 0x%x \r\n", irq_status);
        I2C_clearInterruptTxOver(g_i2c_base);
    }

    //
    // Check for Rx overrun interrupt
    //
    if (irq_status & I2C_INT_RX_OVER)
    {
        printf("rx over irq 0x%x \r\n", irq_status);
        I2C_clearInterruptRxOver(g_i2c_base);
    }

    //
    // Check for Rx underrun interrupt
    //
    if (irq_status & I2C_INT_RX_UNDER)
    {
        printf("rx under irq 0x%x \r\n", irq_status);
        I2C_clearInterruptRxUnder(g_i2c_base);
    }
}

//*****************************************************************************
//
// I2C Interrupt Handler
//
//*****************************************************************************
void I2CX_INTR_IRQHandler(void)
{
    //
    // Get interrupt status
    //
    uint32_t irq_status = I2C_getInterruptStatus(g_i2c_base);

    //
    // Check and handle error interrupts
    //
    i2c_err_irq_check(irq_status);

    //
    // Clear all interrupt status bits
    //
    I2C_clearAllInterruptStatus(g_i2c_base);
}

//*****************************************************************************
//
// I2C GPIO Initialization Function
//
//*****************************************************************************
void I2C_GPIO_init(void)
{
    //
    // Configure GPIO pins for I2C SDA and SCL
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOB);
	SysCtl_setGPIOxPullEnable(32 ,ENABLE);
	SysCtl_setGPIOxPullSel(32, GPIOx_PULL_UP);
	SysCtl_setGPIOxPullEnable(33 ,ENABLE);
	SysCtl_setGPIOxPullSel(33, GPIOx_PULL_UP);

    GPIO_setPinConfig(myMasterI2C_SDA_PIN);
    GPIO_setPinConfig(myMasterI2C_SCL_PIN);
}

//*****************************************************************************
//
// I2C Initialization Function
//
//*****************************************************************************
void I2Cinit(uint32_t i2c_base)
{
    //
    // Store I2C base address
    //
    g_i2c_base = i2c_base;

    //Enable I2C1 Peripheral
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C1);

    //
    // Determine I2C port number based on base address
    //
    if (i2c_base == I2C1_BASE)
    {
        i2c_port_num = 0;
    }
    else if (i2c_base == I2C2_BASE)
    {
        i2c_port_num = 1;
    }
    else
    {
        printf("i2c base error 0x%x \r\n", i2c_base);
        return;
    }

    //
    // Disable I2C module before configuration
    //
    I2C_disableModule(i2c_base);
    
    //
    // Disable all I2C interrupts
    //
    I2C_disableInterrupt(i2c_base, 0xFFFFFFF);
    
    //
    // Set target address to EEPROM slave address
    //
    I2C_setTargetAddress(i2c_base, EEPROM_SLAVE_ADDRESS);
    
    //
    // Configure I2C in master mode with Tx empty control and restart enabled
    //
    I2C_setConfig(i2c_base, I2C_MASTER_MODE | I2C_TX_EMPTY_CTRL | I2C_RESTART_EN);
    
    //
    // Initialize I2C controller with system clock, 400kHz bus frequency and 50% duty cycle
    //
    I2C_initController(i2c_base, SystemClock_Get_APBL(), 400000, I2C_DUTYCYCLE_50);
    
    //
    // Enable I2C module
    //
    I2C_enableModule(i2c_base);

    //
    // Enable error interrupts
    //
    I2C_enableInterrupt(i2c_base, I2C_INT_RX_OVER | I2C_INT_RX_UNDER | I2C_INT_TX_ABRT | I2C_INT_TX_OVER);
    
    //
    // Register and configure ECLIC interrupt handler
    //
    Interrupt_register(myMasterI2C_IRQn, I2CX_INTR_IRQHandler);
    Interrupt_setPriority(myMasterI2C_IRQn, 0, 0);
    Interrupt_enable(myMasterI2C_IRQn);
}

//*****************************************************************************
//
// I2C EEPROM Operation Function
//
//*****************************************************************************
void i2c_eeprom_operate(uint32_t i2c_base)
{
    uint32_t i = 0;

    //
    // Initialize write data buffer with sequential values
    //
    for (i = 0; i < W_DATA_LEN; i++)
    {
        wdata[i] = i + 1;
    }

    //
    // Write data to EEPROM in pages
    // Only one page of EEPROM_PAGE_LEN byte data can be written at a time
    //
    for (i = 0; i < W_DATA_LEN / EEPROM_PAGE_LEN; i++)
    {
        eeprom_WriteData(i2c_base, W_ADDR + EEPROM_PAGE_LEN * i, wdata + EEPROM_PAGE_LEN * i, EEPROM_PAGE_LEN, I2C_NEXT_CONDITION_STOP);
        delay_ms(5);
    }

    //
    // Write any remaining data if W_DATA_LEN is not a multiple of EEPROM_PAGE_LEN
    //
    if (W_DATA_LEN % EEPROM_PAGE_LEN != 0)
    {
        uint32_t remain_data_len = W_DATA_LEN % EEPROM_PAGE_LEN;
        eeprom_WriteData(i2c_base, W_ADDR + EEPROM_PAGE_LEN * (W_DATA_LEN / EEPROM_PAGE_LEN), 
                         wdata + EEPROM_PAGE_LEN * (W_DATA_LEN / EEPROM_PAGE_LEN), remain_data_len, I2C_NEXT_CONDITION_STOP);
        delay_ms(5);
    }

    //
    // Read data back from EEPROM
    //
    eeprom_ReadData(i2c_base, W_ADDR, rdata, W_DATA_LEN, I2C_NEXT_CONDITION_RESTART | I2C_NEXT_CONDITION_STOP);
}

//*****************************************************************************
//
// EEPROM Read Verification Function
//
//*****************************************************************************
int verifyEEPROMRead(uint32_t i2c_base)
{
    uint16_t i;

    //
    // Compare written data with read data
    //
    for (i = 0; i < W_DATA_LEN; i++)
    {
        if (wdata[i] != rdata[i])
        {
            printf("I2C%d_BASE eeprom write read test fail wdata %d rdata %d \r\n", i2c_port_num, wdata[i], rdata[i]);
            return -1;
        }
    }
    
    //
    // Print success message if all data matches
    //
    printf("I2C%d_BASE eeprom write read test OK \r\n", i2c_port_num);
    return 0;
}

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
	int ret;

	alb32r003x_evb_init();

	//
	// Enable global interrupts
	//
	CPU_enableIrq();

    //
    // Print start message
    //
    printf("i2c1_eeprom_polling start\r\n");

    //
    // Initialize I2C GPIO pins
    //
    I2C_GPIO_init();

    //
    // Initialize I2C module
    //
    I2Cinit(g_i2c_base);

    //
    // Initialize EEPROM interface
    //
    eeprom_init(EEPROM_DATA_ADDRESS_LEN);

    //
    // Perform EEPROM write and read operations
    //
    i2c_eeprom_operate(g_i2c_base);

    //
    // Verify the data read from EEPROM
    //
    ret = verifyEEPROMRead(g_i2c_base);

    //
    // Print end message
    //
    printf("i2c_test04_eeprom_polling end\r\n");


    return (ret == 0) ? SC_PASS : SC_FAIL;
}
