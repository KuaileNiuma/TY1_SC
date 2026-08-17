/**
 *************************************************************************************
 * @file epwm_ex05_board.h
 * @brief This file contains the header file for example epwm_ex05_board.
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

#ifndef __EPWM_EX05_BOARD_H_
#define __EPWM_EX05_BOARD_H_

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
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> myEPWM1 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0                          //!< GPIO pin for EPWM1_A
#define myEPWM1_EPWMA_GPIO 0                        //!< GPIO number for EPWM1_A
#define myEPWM1_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A     //!< Pin configuration for EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1                          //!< GPIO pin for EPWM1_B
#define myEPWM1_EPWMB_GPIO 1                        //!< GPIO number for EPWM1_B
#define myEPWM1_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B     //!< Pin configuration for EPWM1_B
//
// GPIO25 - GPIO Settings
//
#define myGPIO25_GPIO_PIN_CONFIG GPIO_25_GPIO25     //!< Pin configuration for GPIO25

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define myEPWM1_BASE EPWM1_BASE                     //!< EPWM1 base address 

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define myGPIO25 25                                 //!< GPIO25 pin number
void myGPIO25_init();                               //!< GPIO25 initialization function

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define myINPUTXBARINPUT0_SOURCE 25             //!< INPUTXBAR input 0 source
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT1     //!< INPUTXBAR input 0
void myINPUTXBARINPUT0_init();                  //!< INPUTXBAR input 0 initialization function

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

#define INT_myEPWM1_TZ SOC_INT274_IRQn              //!< EPWM1 trip zone interrupt
#define INT_myEPWM1_TZ_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP2 //!< Interrupt acknowledge group
extern  __INTERRUPT void epwm1TZISR(void);         //!< EPWM1 trip zone ISR

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void    Board_init();                               //!< Board initialization function
void    EPWM_init();                                //!< EPWM configuration function
void    GPIO_init();                                //!< GPIO configuration function
void    INPUTXBAR_init();                           //!< INPUTXBAR configuration function
void 	INTERRUPT_init();                           //!< INTERRUPT configuration function
void    PinMux_init();                              //!< PINMUX configuration function


#ifdef __cplusplus
}
#endif


#endif
