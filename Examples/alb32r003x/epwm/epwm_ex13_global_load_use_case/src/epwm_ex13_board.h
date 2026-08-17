/**
 *************************************************************************************
 * @file epwm_ex13_board.h
 * @brief This file contains the header file for example epwm_ex13_board.
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

#ifndef __EPWM_EX13_BOARD_H_
#define __EPWM_EX13_BOARD_H_

#ifdef __cplusplus
extern "C"{
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
//
// ANALOG -> myANALOGPinMux0 Pinmux
//

//
// EPWM1 -> myEPWM1 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define myEPWM1_EPWMA_GPIO 0
#define myEPWM1_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define myEPWM1_EPWMB_GPIO 1
#define myEPWM1_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B

//
// EPWM2 -> myEPWM2 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define myEPWM2_EPWMA_GPIO 2
#define myEPWM2_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define myEPWM2_EPWMB_GPIO 3
#define myEPWM2_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B

//
// EPWM3 -> myEPWM3 Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 4
#define myEPWM3_EPWMA_GPIO 4
#define myEPWM3_EPWMA_PIN_CONFIG GPIO_4_EPWM3_A
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 5
#define myEPWM3_EPWMB_GPIO 5
#define myEPWM3_EPWMB_PIN_CONFIG GPIO_5_EPWM3_B
//
// GPIO6 - GPIO Settings
//
#define myGPIO6_GPIO_PIN_CONFIG GPIO_6_GPIO6

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
#define myCMPSS1_BASE CMPSS1_BASE
#define myCMPSS1_HIGH_COMP_BASE CMPSS1_BASE
#define myCMPSS1_LOW_COMP_BASE CMPSS1_BASE
void myCMPSS1_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define myEPWM1_BASE EPWM1_BASE
void myEPWM1_init();
#define myEPWM2_BASE EPWM2_BASE
void myEPWM2_init();
#define myEPWM3_BASE EPWM3_BASE
void myEPWM3_init();

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void myEPWMXBAR4_init();
#define myEPWMXBAR4 XBAR_TRIP4
#define myEPWMXBAR4_ENABLED_MUXES (XBAR_MUX00)

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define myGPIO6 6
void myGPIO6_init();

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define myINPUTXBARINPUT0_SOURCE 6
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT1
void myINPUTXBARINPUT0_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

//
// Interrupt Settings for INT_myEPWM1
// ISR need to be defined for the registered interrupts
//
#define INT_myEPWM1 INT_EPWM1
__INTERRUPT void INT_myEPWM1_ISR(void);

//
// Interrupt Settings for INT_myEPWM2_TZ
// ISR need to be defined for the registered interrupts
//
#define INT_myEPWM2_TZ INT_EPWM2_TZ
__INTERRUPT void INT_myEPWM2_TZ_ISR(void);

//
// Interrupt Settings for INT_myEPWM3_TZ
// ISR need to be defined for the registered interrupts
//
#define INT_myEPWM3_TZ INT_EPWM3_TZ
__INTERRUPT void INT_myEPWM3_TZ_ISR(void);


//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void    Board_init();
void    CMPSS_init();
void    EPWM_init();
void    EPWMXBAR_init();
void    GPIO_init();
void    INPUTXBAR_init();
void    INTERRUPT_init();
void    PinMux_init();


#ifdef __cplusplus
}
#endif


#endif
