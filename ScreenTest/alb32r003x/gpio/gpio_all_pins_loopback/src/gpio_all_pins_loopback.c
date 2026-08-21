/**
 *************************************************************************************
 * @file gpio_all_pins_loopback.c
 * @brief This file contains the source file for example gpio_all_pins_loopback.
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
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************

//
// GPIO pins under test. All of them are shorted together to a common node
// externally (one wire connecting every pin).
//
#define GPIO_TEST_PIN_NUM   45

static const uint16_t g_gpioTestPins[GPIO_TEST_PIN_NUM] =
{
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    12, 13, 14, 15, 16, 17, 20, 21,
    24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 37, 40, 41, 47, 48,
    51, 52, 53, 55, 56, 57, 58, 59, 60, 61
};

//*****************************************************************************
//
// Static Function Prototypes
//
//*****************************************************************************
static int gpio_test_drive_pin(uint16_t drivePin);
static void gpio_all_pins_init(void);

//*****************************************************************************
//
// gpio_all_pins_init - Configure all test pins as high-Z inputs.
//
//*****************************************************************************
static void gpio_all_pins_init(void)
{
    uint32_t i;

    //
    // Enable GPIOA / GPIOB peripheral clocks (pins 0-31 -> A, 32-63 -> B)
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOB);

    //
    // Configure every test pin as input (high-Z) first
    //
    for (i = 0; i < GPIO_TEST_PIN_NUM; i++)
    {
        uint16_t pin = g_gpioTestPins[i];

        switch (pin)
        {
            case 0:  GPIO_setPinConfig(GPIO_0_GPIO0);   break;
            case 1:  GPIO_setPinConfig(GPIO_1_GPIO1);   break;
            case 2:  GPIO_setPinConfig(GPIO_2_GPIO2);   break;
            case 3:  GPIO_setPinConfig(GPIO_3_GPIO3);   break;
            case 4:  GPIO_setPinConfig(GPIO_4_GPIO4);   break;
            case 5:  GPIO_setPinConfig(GPIO_5_GPIO5);   break;
            case 6:  GPIO_setPinConfig(GPIO_6_GPIO6);   break;
            case 7:  GPIO_setPinConfig(GPIO_7_GPIO7);   break;
            case 8:  GPIO_setPinConfig(GPIO_8_GPIO8);   break;
            case 9:  GPIO_setPinConfig(GPIO_9_GPIO9);   break;
            case 12: GPIO_setPinConfig(GPIO_12_GPIO12); break;
            case 13: GPIO_setPinConfig(GPIO_13_GPIO13); break;
            case 14: GPIO_setPinConfig(GPIO_14_GPIO14); break;
            case 15: GPIO_setPinConfig(GPIO_15_GPIO15); break;
            case 16: GPIO_setPinConfig(GPIO_16_GPIO16); break;
            case 17: GPIO_setPinConfig(GPIO_17_GPIO17); break;
            case 20: GPIO_setPinConfig(GPIO_20_GPIO20); break;
            case 21: GPIO_setPinConfig(GPIO_21_GPIO21); break;
            case 24: GPIO_setPinConfig(GPIO_24_GPIO24); break;
            case 25: GPIO_setPinConfig(GPIO_25_GPIO25); break;
            case 26: GPIO_setPinConfig(GPIO_26_GPIO26); break;
            case 27: GPIO_setPinConfig(GPIO_27_GPIO27); break;
            case 28: GPIO_setPinConfig(GPIO_28_GPIO28); break;
            case 29: GPIO_setPinConfig(GPIO_29_GPIO29); break;
            case 30: GPIO_setPinConfig(GPIO_30_GPIO30); break;
            case 31: GPIO_setPinConfig(GPIO_31_GPIO31); break;
            case 32: GPIO_setPinConfig(GPIO_32_GPIO32); break;
            case 33: GPIO_setPinConfig(GPIO_33_GPIO33); break;
            case 34: GPIO_setPinConfig(GPIO_34_GPIO34); break;
            case 35: GPIO_setPinConfig(GPIO_35_GPIO35); break;
            case 37: GPIO_setPinConfig(GPIO_37_GPIO37); break;
            case 40: GPIO_setPinConfig(GPIO_40_GPIO40); break;
            case 41: GPIO_setPinConfig(GPIO_41_GPIO41); break;
            case 47: GPIO_setPinConfig(GPIO_47_GPIO47); break;
            case 48: GPIO_setPinConfig(GPIO_48_GPIO48); break;
            case 51: GPIO_setPinConfig(GPIO_51_GPIO51); break;
            case 52: GPIO_setPinConfig(GPIO_52_GPIO52); break;
            case 53: GPIO_setPinConfig(GPIO_53_GPIO53); break;
            case 55: GPIO_setPinConfig(GPIO_55_GPIO55); break;
            case 56: GPIO_setPinConfig(GPIO_56_GPIO56); break;
            case 57: GPIO_setPinConfig(GPIO_57_GPIO57); break;
            case 58: GPIO_setPinConfig(GPIO_58_GPIO58); break;
            case 59: GPIO_setPinConfig(GPIO_59_GPIO59); break;
            case 60: GPIO_setPinConfig(GPIO_60_GPIO60); break;
            case 61: GPIO_setPinConfig(GPIO_61_GPIO61); break;
            default: break;
        }

        GPIO_setDirectionMode(pin, GPIO_DIR_MODE_IN);
    }
}

//*****************************************************************************
//
// gpio_test_drive_pin - Drive one pin as output and read back all others.
//
// Returns 0 on success, -1 on failure.
//
//*****************************************************************************
static int gpio_test_drive_pin(uint16_t drivePin)
{
    uint32_t i;
    int      result = 0;

    //
    // Configure the driven pin as output
    //
    GPIO_setDirectionMode(drivePin, GPIO_DIR_MODE_OUT);

    //
    // Drive high, then check all other pins read high
    //
    GPIO_writePin(drivePin, 1);
    delay_ms(1);
    for (i = 0; i < GPIO_TEST_PIN_NUM; i++)
    {
        if (g_gpioTestPins[i] == drivePin)
        {
            continue;
        }
        if (GPIO_readPin(g_gpioTestPins[i]) == 0)
        {
            printf("FAIL: drive %d high, pin %d reads low\r\n", drivePin, g_gpioTestPins[i]);
            result = -1;
        }
    }

    //
    // Drive low, then check all other pins read low
    //
    GPIO_writePin(drivePin, 0);
    delay_ms(1);
    for (i = 0; i < GPIO_TEST_PIN_NUM; i++)
    {
        if (g_gpioTestPins[i] == drivePin)
        {
            continue;
        }
        if (GPIO_readPin(g_gpioTestPins[i]) != 0)
        {
            printf("FAIL: drive %d low, pin %d reads high\r\n", drivePin, g_gpioTestPins[i]);
            result = -1;
        }
    }

    //
    // Restore the pin to input (high-Z)
    //
    GPIO_setDirectionMode(drivePin, GPIO_DIR_MODE_IN);

    return result;
}

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
    uint32_t i;
    int      testFail = 0;
    int      ret;

    alb32r003x_evb_init();

    printf("GPIO ALL PINS LOOPBACK TEST\r\n");
    printf("Connect all test pins to a common node before running.\r\n");

    //
    // Configure all test pins as inputs
    //
    gpio_all_pins_init();

    //
    // Drive each pin one at a time, read back all others
    //
    for (i = 0; i < GPIO_TEST_PIN_NUM; i++)
    {
        ret = gpio_test_drive_pin(g_gpioTestPins[i]);
        if (ret != 0)
        {
            testFail = 1;
        }
        else
        {
            printf("pin %d OK\r\n", g_gpioTestPins[i]);
        }
    }

    if (testFail == 0)
    {
        printf("GPIO ALL PINS LOOPBACK TEST OK\r\n");
        return SC_PASS;
    }

    printf("GPIO ALL PINS LOOPBACK TEST FAIL\r\n");
    return SC_FAIL;
}
