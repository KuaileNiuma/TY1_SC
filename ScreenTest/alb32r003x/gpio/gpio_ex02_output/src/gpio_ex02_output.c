/**
 *************************************************************************************
 * @file gpio_ex02_output.c
 * @brief This file contains the source file for example gpio_ex02_output.
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
#include "gpio.h"
#include "debug.h"
#include "interrupt.h"
#include "xbar.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"


void gpio_led_init(void)
{
    //
    // Enable GPIOB CLK
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOB);

	//
	// Set GPIO44 to output mode and output low
	//
	GPIO_setPinConfig(GPIO_44_GPIO44);
	GPIO_setDirectionMode(44,GPIO_DIR_MODE_OUT);
	GPIO_writePin(44,0);

	//
	// Set GPIO49 to output mode and output low
	//
	GPIO_setPinConfig(GPIO_49_GPIO49);
	GPIO_setDirectionMode(49,GPIO_DIR_MODE_OUT);
	GPIO_writePin(49,0);


}

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();

	//
    // Print test information
    //
    printf("GPIO EX02 OUTPUT.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Initialize GPIO test configuration
    //
    gpio_led_init();
    
    //
    // Infinite loop
    //
    while(1)
    {
    	GPIO_writePin(44,1);
    	GPIO_writePin(49,0);
    	delay_ms(333);
    	GPIO_writePin(44,0);
    	GPIO_writePin(49,1);
    	delay_ms(333);
    }
}
