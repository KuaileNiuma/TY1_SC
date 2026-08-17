/**
 *************************************************************************************
 * @file pmbus_ex02_slave.c
 * @brief This file contains the source file for example pmbus_ex02_slave.
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
#include "alb32r003x_evb.h"
#include "debug.h"
#include "interrupt.h"
#include "pmbus.h"

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
uint8_t tx_data_buff[TEST_TRANSFER_DATA_IN_BYTE];
uint8_t rx_data_buff[TEST_TRANSFER_DATA_IN_BYTE];

__INTERRUPT void i2c_isr(void) {
	pmbus_isr_handler(myI2C_BASE);
}
void pmbus_callback(uint32_t i2c_base, pmbus_complete_cb_cfg_t *cfg) {
	(void) i2c_base;
	printf("cb:cmd: 0x%02x, read:%s, pec_check:%s, len:%d, data_addr:0x%08x\n",
			cfg->command, cfg->read ? "true" : "false",
			cfg->pec_check ? "true" : "false", cfg->len, cfg->data);
}
int main(void) {
	uint32_t stat;
	uint32_t read_len;

	CPU_enableIrq();
	alb32r003x_evb_init();

	/*I2C GPIO config*/
	GPIO_setPinConfig(myI2C_SDA_PIN);
	GPIO_setPinConfig(myI2C_SCL_PIN);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2C1);
    SysCtl_setGPIOxPullEnable(0, ENABLE);
    SysCtl_setGPIOxPullSel(0,  GPIOx_PULL_UP);
    SysCtl_setGPIOxPullEnable(1, ENABLE);
    SysCtl_setGPIOxPullSel(1, GPIOx_PULL_UP);
	/*i2c slave init*/
	pmbus_slave_init(myI2C_BASE, TEST_SMBUS_SLAVE_ADDRESS);

	/*enable i2c1 intr*/
    Interrupt_register(I2C1_IRQn, i2c_isr);
    Interrupt_enable(I2C1_IRQn);

	printf("PMbus slave test\n");
	if (pmbus_slave_command_transaction_install(myI2C_BASE,
			PMBUS_CODE_PAGE_PLUS_WRITE, NULL, rx_data_buff, TEST_TRANSFER_DATA_IN_BYTE, pmbus_callback)
			== status_success) {
		printf("pmbus(cmd:0x%02x) slave command transaction install success\n",
				PMBUS_CODE_PAGE_PLUS_WRITE);
	} else {
		printf("pmbus(cmd:0x%02x) slave command transaction install fail\n",
				PMBUS_CODE_PAGE_PLUS_WRITE);
		while (1) {
		};
	}

	tx_data_buff[0] =0x5A;
	tx_data_buff[1] =0x5B;
	tx_data_buff[2] =0x5C;
	tx_data_buff[3] =0x5D;
	tx_data_buff[4] =0x5E;
	tx_data_buff[5] =0x5F;

	if (pmbus_slave_command_transaction_install(myI2C_BASE,
			PMBUS_CODE_PAGE, tx_data_buff, rx_data_buff, 1, pmbus_callback)
			== status_success) {
		printf("pmbus(cmd:0x%02x) slave command transaction install success\n",
				PMBUS_CODE_PAGE);
	} else {
		printf("pmbus(cmd:0x%02x) slave command transaction install fail\n",
				PMBUS_CODE_PAGE);
		while (1) {
		};
	}
	if (pmbus_slave_command_transaction_install(myI2C_BASE,
			PMBUS_CODE_PAGE_PLUS_READ, tx_data_buff, NULL, TEST_TRANSFER_DATA_IN_BYTE, pmbus_callback)
			== status_success) {
		printf("pmbus(cmd:0x%02x) slave command transaction install success\n",
				PMBUS_CODE_PAGE_PLUS_READ);
	} else {
		printf("pmbus(cmd:0x%02x) slave command transaction install fail\n",
				PMBUS_CODE_PAGE_PLUS_READ);
		while (1) {
		};
	}


	if (pmbus_slave_command_transaction_install(myI2C_BASE,
			PMBUS_CODE_CLEAR_FAULTS, NULL, rx_data_buff, 0, pmbus_callback)
			== status_success) {
		printf("pmbus(cmd:0x%02x) slave command transaction install success\n",
				PMBUS_CODE_CLEAR_FAULTS);
	} else {
		printf("pmbus(cmd:0x%02x) slave command transaction install fail\n",
				PMBUS_CODE_CLEAR_FAULTS);
		while (1) {
		};
	}

	if (pmbus_slave_command_transaction_install(myI2C_BASE,
			PMBUS_CODE_VOUT_TRIM, tx_data_buff, rx_data_buff, 2,
			pmbus_callback) == status_success) {
		printf("pmbus(cmd:0x%02x) slave command transaction install success\n",
				PMBUS_CODE_VOUT_TRIM);
	} else {
		printf("pmbus(cmd:0x%02x) slave command transaction install fail\n",
				PMBUS_CODE_VOUT_TRIM);
		while (1) {
		};
	}
	while (1) {
	}
	return 0;

}
