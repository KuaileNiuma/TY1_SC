/**
 *************************************************************************************
 * @file pmbus_ex01_master.c
 * @brief This file contains the source file for example pmbus_ex01_master.
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

#include <stdio.h>
#include "device.h"
#include "timer.h"
#include "debug.h"
#include "interrupt.h"
#include "alb32r003x_evb.h"
#include "pmbus.h"
#include "alb32r003x_screenTest.h"


#define myI2C_BASE	I2C1_BASE

#if (myI2C_BASE == I2C1_BASE)

#define myI2C_SDA_PIN	GPIO_0_I2CA_SDA
#define myI2C_SCL_PIN	GPIO_1_I2CA_SCL
#define myI2C_IRQn      I2C1_IRQn

#elif	(myI2C_BASE == I2C2_BASE)

#define myI2C_SDA_PIN	GPIO_2_I2CB_SDA
#define myI2C_SCL_PIN	GPIO_3_I2CB_SCL
#define myI2C_IRQn      I2C2_IRQn

#elif	(myI2C_BASE == I2C3_BASE)

#define myI2C_SDA_PIN	GPIO_62_I2CC_SDA
#define myI2C_SCL_PIN	GPIO_230_I2CC_SCL
#define myI2C_IRQn      I2C3_IRQn

#endif



#define TEST_SMBUS_SLAVE_ADDRESS  (0x50U)

#define TEST_TRANSFER_DATA_IN_BYTE  (128U)
uint8_t rx_buff[TEST_TRANSFER_DATA_IN_BYTE];
uint8_t tx_buff[TEST_TRANSFER_DATA_IN_BYTE];

void mydelay(uint32_t tick)
{
    for(int i=0;i<1000;i++);
}


void I2C_master_init(uint32_t i2c_base)
{
    uint32_t sysclkHz = SystemClock_Get();
	I2C_disableModule(i2c_base);
	I2C_disableInterrupt(i2c_base, 0xFFFFFFF);
	I2C_setTargetAddress(i2c_base,TEST_SMBUS_SLAVE_ADDRESS);
	I2C_setConfig(i2c_base, I2C_MASTER_MODE | I2C_IC_CON_SPEEDL |I2C_RESTART_EN);
	I2C_initController(i2c_base, sysclkHz, sysclkHz, I2C_DUTYCYCLE_50);
	I2C_enableModule(i2c_base);
}
int main(void)
{
	uint32_t stat;
	uint32_t read_len;

	alb32r003x_evb_init();
	/*I2C GPIO config*/
	GPIO_setPinConfig(myI2C_SDA_PIN);
	GPIO_setPinConfig(myI2C_SCL_PIN);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C1);
    SysCtl_setGPIOxPullEnable(0, ENABLE);
    SysCtl_setGPIOxPullSel(0,  GPIOx_PULL_UP);
    SysCtl_setGPIOxPullEnable(1, ENABLE);
    SysCtl_setGPIOxPullSel(1, GPIOx_PULL_UP);

    /*i2c master init*/
	I2C_master_init(myI2C_BASE);

	for (int i = 0; i<TEST_TRANSFER_DATA_IN_BYTE; i++)
	{
		tx_buff[i] = 0x10+i;
	}
    printf("PMbus master test\n");
    while (1) {
        printf("pmbus master write test begin...\n");
        stat = pmbus_master_write(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS, PMBUS_CODE_PAGE_PLUS_WRITE, tx_buff, TEST_TRANSFER_DATA_IN_BYTE);
        if (stat != status_success) {
            printf("pmbus(cmd:0x%02x) master write failed, err_code:%d\r\n", PMBUS_CODE_PAGE_PLUS_WRITE, stat);
        }
        mydelay(100);
        stat = pmbus_master_write(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS, PMBUS_CODE_PAGE, tx_buff, TEST_TRANSFER_DATA_IN_BYTE);
        if (stat != status_success) {
            printf("pmbus(cmd:0x%02x) master write failed, err_code:%d\r\n", PMBUS_CODE_PAGE, stat);
        }
        mydelay(100);
        stat = pmbus_master_write(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS, PMBUS_CODE_CLEAR_FAULTS, tx_buff, TEST_TRANSFER_DATA_IN_BYTE);
        if (stat != status_success) {
            printf("pmbus(cmd:0x%02x) master write failed, err_code:%d\r\n", PMBUS_CODE_CLEAR_FAULTS, stat);
        }
        mydelay(100);
        stat = pmbus_master_write(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS, PMBUS_CODE_VOUT_TRIM, tx_buff, TEST_TRANSFER_DATA_IN_BYTE);
        if (stat != status_success) {
            printf("pmbus(cmd:0x%02x) master write failed, err_code:%d\r\n", PMBUS_CODE_VOUT_TRIM, stat);
        }
        printf("pmbus master write test end...\n\n");

        printf("pmbus master read test begin...\n");
        mydelay(100);
        read_len = TEST_TRANSFER_DATA_IN_BYTE;
        stat = pmbus_master_read(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS, PMBUS_CODE_PAGE, rx_buff, &read_len);
        if (stat != status_success) {
            printf("pmbus(cmd:0x%02x) master read failed, err_code:%d\r\n", PMBUS_CODE_PAGE, stat);
        } else {
            printf("pmbus(cmd:0x%02x) master read len:%d\n", PMBUS_CODE_PAGE, read_len);
        }
        mydelay(100);
        read_len = TEST_TRANSFER_DATA_IN_BYTE;
        stat = pmbus_master_read(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS, PMBUS_CODE_PAGE_PLUS_READ, rx_buff, &read_len);
        if (stat != status_success) {
            printf("pmbus(cmd:0x%02x) master read failed, err_code:%d\r\n", PMBUS_CODE_PAGE_PLUS_READ, stat);
        } else {
            printf("pmbus(cmd:0x%02x) master read len:%d\n", PMBUS_CODE_PAGE_PLUS_READ, read_len);
        }
        mydelay(100);
        read_len = TEST_TRANSFER_DATA_IN_BYTE;
        stat = pmbus_master_read(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS, PMBUS_CODE_VOUT_TRIM, rx_buff, &read_len);
        if (stat != status_success) {
            printf("pmbus(cmd:0x%02x) master read failed, err_code:%d\r\n", PMBUS_CODE_VOUT_TRIM, stat);
        } else {
            printf("pmbus(cmd:0x%02x) master read len:%d\n", PMBUS_CODE_VOUT_TRIM, read_len);
        }
        mydelay(100);

        printf("pmbus master read test end...\n\n");
    }
    return SC_PASS;
}
