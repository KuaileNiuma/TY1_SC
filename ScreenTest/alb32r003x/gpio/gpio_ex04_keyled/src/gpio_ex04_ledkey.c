/**
 *************************************************************************************
 * @file gpio_ex04_ledkey.c
 * @brief This file contains the source file for example gpio_ex04_ledkey.
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
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"


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
    printf("GPIO EX04 LED&KEY.\r\n");
    
    //
    // Initialize GPIO test configuration
    //
    evb_led_init(LED1);
    evb_led_init(LED2);

    evb_led_on(LED1);
    evb_led_on(LED2);

    delay_ms(500);

    evb_led_off(LED1);
    evb_led_off(LED2);
    delay_ms(333);

    evb_key_init(KEY1);
    evb_key_init(KEY2);

    //
    // Infinite loop
    //
    while(1)
    {
        evb_led_on(LED1);
        evb_led_off(LED2);
        if((evb_key_get_state(KEY1) == KEY_DOWN) || (evb_key_get_state(KEY2) == KEY_DOWN))
        {
            delay_ms(333);
        }
        else
        {
            delay_ms(666);
        }
        evb_led_off(LED1);
        evb_led_on(LED2);
        if((evb_key_get_state(KEY1) == KEY_DOWN) || (evb_key_get_state(KEY2) == KEY_DOWN))
        {
            delay_ms(333);
        }
        else
        {
            delay_ms(666);
        }
        printf("KEY1 %s, KEY2 %s\r\n",
                evb_key_get_state(KEY1) == KEY_DOWN ? "down" : "up",
                evb_key_get_state(KEY2) == KEY_DOWN ? "down" : "up"
                );
    }
}
