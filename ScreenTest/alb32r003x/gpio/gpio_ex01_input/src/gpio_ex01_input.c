/**
 *************************************************************************************
 * @file gpio_ex01_input.c
 * @brief This file contains the source file for example gpio_ex01_input.
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
#include "gpio.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************

#define GPIO_TEST1_PIN     (50)               //!< GPIO test pin number
#define GPIO_TEST1_PIN_CFG (GPIO_50_GPIO50)

#define GPIO_TEST2_PIN     (54)               //!< GPIO test pin number
#define GPIO_TEST2_PIN_CFG (GPIO_54_GPIO54)
//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t g_gpio_readPin1 = 0;            //!< Store GPIO50 pin read value
uint32_t g_gpio_readPin2 = 0;            //!< Store GPIO54 pin read value


int main(void)
{
    int idx;
    alb32r003x_evb_init();

    //
    // Print test information 
    //
    printf("GPIO EX01 INPUT.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Enable GPIOB CLK
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOB);


    //
    // Configure GPIO pin muxing
    //
    GPIO_setPinConfig(GPIO_TEST1_PIN_CFG);
    GPIO_setPinConfig(GPIO_TEST2_PIN_CFG);

    //
    // Set GPIO pin direction to input
    //
    SysCtl_setGPIOCAMSEL(GPIO_TEST1_PIN , 0);
    GPIO_setDirectionMode(GPIO_TEST1_PIN, GPIO_DIR_MODE_IN);
    SysCtl_setGPIOCAMSEL(GPIO_TEST2_PIN , 0);
    GPIO_setDirectionMode(GPIO_TEST2_PIN, GPIO_DIR_MODE_IN);

	// Read individual pin state
	//
	g_gpio_readPin1 = GPIO_readPin(GPIO_TEST1_PIN);
	g_gpio_readPin2 = GPIO_readPin(GPIO_TEST2_PIN);


	while(1)
	{

		delay_ms(1000);
		if(GPIO_readPin(GPIO_TEST1_PIN) == 0)
		{
			delay_ms(10);
			if(GPIO_readPin(GPIO_TEST1_PIN) == 0)
			{
				printf("KEY1 DOWN,GPIO50 SET LOW\r\n");
			}
			else
				printf("KEY1 UP,GPIO50 SET HIGH\r\n");
		}
		else
				printf("KEY1 UP,GPIO50 SET HIGH\r\n");

		if(GPIO_readPin(GPIO_TEST2_PIN) == 0)
		{
			delay_ms(10);
			if(GPIO_readPin(GPIO_TEST2_PIN) == 0)
			{
				printf("KEY2 DOWN,GPIO54 SET LOW\r\n");
			}
			else
				printf("KEY2 UP,GPIO54 SET HIGH\r\n");
		}
		else
				printf("KEY2 UP,GPIO54 SET HIGH\r\n");
	}
}

