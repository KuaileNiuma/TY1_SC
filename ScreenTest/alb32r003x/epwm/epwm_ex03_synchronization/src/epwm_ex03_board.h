/**
 *************************************************************************************
 * @file epwm_ex03_board.h
 * @brief This file contains the header file for example epwm_ex03_board.
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

#ifndef __EPWM_EX03_BOARD_H_
#define __EPWM_EX03_BOARD_H_

#ifdef __cplusplus
extern "C"{
#endif

//*****************************************************************************
//
// Include Files
//
//*****************************************************************************
#include "device.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************

#define EPWM_MODE_SPWM_0 0  //!< SPWM mode 0
#define   EPWM_MODE_SEL    EPWM_MODE_SPWM_0  //!< EPWM mode selection

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> myEPWM1 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0                    //!< GPIO pin for EPWM1_A
#define myEPWM1_EPWMA_GPIO 0                  //!< GPIO number for EPWM1_A
#define myEPWM1_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A  //!< Pin configuration for EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1                    //!< GPIO pin for EPWM1_B
#define myEPWM1_EPWMB_GPIO 1                  //!< GPIO number for EPWM1_B
#define myEPWM1_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B  //!< Pin configuration for EPWM1_B

//
// EPWM2 -> myEPWM2 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2                    //!< GPIO pin for EPWM2_A
#define myEPWM2_EPWMA_GPIO 2                  //!< GPIO number for EPWM2_A
#define myEPWM2_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A  //!< Pin configuration for EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3                    //!< GPIO pin for EPWM2_B
#define myEPWM2_EPWMB_GPIO 3                  //!< GPIO number for EPWM2_B
#define myEPWM2_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B  //!< Pin configuration for EPWM2_B

//
// EPWM3 -> myEPWM3 Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 4                    //!< GPIO pin for EPWM3_A
#define myEPWM3_EPWMA_GPIO 4                  //!< GPIO number for EPWM3_A
#define myEPWM3_EPWMA_PIN_CONFIG GPIO_4_EPWM3_A  //!< Pin configuration for EPWM3_A
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 5                    //!< GPIO pin for EPWM3_B
#define myEPWM3_EPWMB_GPIO 5                  //!< GPIO number for EPWM3_B
#define myEPWM3_EPWMB_PIN_CONFIG GPIO_5_EPWM3_B  //!< Pin configuration for EPWM3_B

//
// EPWM4 -> myEPWM4 Pinmux
//
//
// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 6                    //!< GPIO pin for EPWM4_A
#define myEPWM4_EPWMA_GPIO 6                  //!< GPIO number for EPWM4_A
#define myEPWM4_EPWMA_PIN_CONFIG GPIO_6_EPWM4_A  //!< Pin configuration for EPWM4_A
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 7                    //!< GPIO pin for EPWM4_B
#define myEPWM4_EPWMB_GPIO 7                  //!< GPIO number for EPWM4_B
#define myEPWM4_EPWMB_PIN_CONFIG GPIO_7_EPWM4_B  //!< Pin configuration for EPWM4_B

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define myEPWM1_BASE EPWM1_BASE  //!< EPWM1 base address
#define myEPWM2_BASE EPWM2_BASE  //!< EPWM2 base address
#define myEPWM3_BASE EPWM3_BASE  //!< EPWM3 base address
#define myEPWM4_BASE EPWM4_BASE  //!< EPWM4 base address


//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void    Board_init();  //!< Board initialization function
void    EPWM_init();   //!< EPWM configuration function
void    INPUTXBAR_init(); //!< INPUTXBAR initialization function
void    PinMux_init(); //!< PINMUX configuration function

#ifdef __cplusplus
}
#endif


#endif
