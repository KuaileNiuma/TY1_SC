/** 
  ************************************************************************************* 
  * @file alb32r003x_evb.h 
  * @author Albatross 
  * @brief This file contains the definition of alb32r003x_evb driver. 
  * @version 1.0.0 
  * @date 2025-07-30 
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


#ifndef ALB32R003X_EVB_H
#define ALB32R003X_EVB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "device.h"

#define EVB_HSE_CLK  (12000000U)
#define EVB_COM

#ifdef EVB_COM
#define EVB_COM_UART       (SCI1_BASE)
#define EVB_COM_UART_BAUD  (115200)
#define EVB_COM_UART_TX    GPIO_29_SCIA_TX
#define EVB_COM_UART_RX    GPIO_28_SCIA_RX
#define EVB_COM_UART_CLK   SystemClock_Get_APBL()
#endif

#define ALB_SDK_BANNER     1

/* exported types */
typedef enum {
    LED1 = 0,
    LED2 = 1,
} led_typedef_enum;

#define GPIO_LED1_PIN     (44)               //!< GPIO test pin number
#define GPIO_LED1_PIN_CFG (GPIO_44_GPIO44)

#define GPIO_LED2_PIN     (49)               //!< GPIO test pin number
#define GPIO_LED2_PIN_CFG (GPIO_49_GPIO49)

#define LED_ON   0
#define LED_OFF  1

typedef enum {
    KEY1 = 0,
    KEY2 = 1,
    LEDn = KEY2
} key_typedef_enum;

#define KEY_DOWN     0
#define KEY_UP       1

#define GPIO_KEY1_PIN     (50)               //!< GPIO test pin number
#define GPIO_KEY1_PIN_CFG (GPIO_50_GPIO50)

#define GPIO_KEY2_PIN     (54)               //!< GPIO test pin number
#define GPIO_KEY2_PIN_CFG (GPIO_54_GPIO54)

/* function declarations */
/* configure led GPIO */
void evb_led_init(led_typedef_enum lednum);
/* turn on selected led */
void evb_led_on(led_typedef_enum lednum);
/* turn off selected led */
void evb_led_off(led_typedef_enum lednum);
/* toggle the selected led */
void evb_led_toggle(led_typedef_enum lednum);
/* configure key */
void evb_key_init(key_typedef_enum keynum);
/* return the selected key state */
uint8_t evb_key_get_state(key_typedef_enum keynum);
/* configure COM port */
void evb_com_init(uint32_t uart_base);

void alb32r003x_evb_init();


void SystemClock_Set240MHz ( OSC_SRC_SEL src );
void SystemClock_Set200MHz ( OSC_SRC_SEL src );
void SystemClock_Set138MHz ( OSC_SRC_SEL src );
void SystemClock_Set120MHz ( OSC_SRC_SEL src );
void SystemClock_Set96MHz  ( OSC_SRC_SEL src );


#ifdef __cplusplus
}
#endif

#endif /* ALB32R003X_EVB_H */
