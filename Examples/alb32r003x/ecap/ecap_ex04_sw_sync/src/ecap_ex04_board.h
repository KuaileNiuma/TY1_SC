/**
 *************************************************************************************
 * @file ecap_ex04_board.h
 * @brief This file contains the header file for example ecap_ex04_board.
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
#ifndef __ECAP_EX04_BOARD_H
#define __ECAP_EX04_BOARD_H

#include "device.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************

#define myECAP1_BASE                ECAP1_BASE                 //!< eCAP1 base address
#define myECAP2_BASE                ECAP2_BASE                 //!< eCAP2 base address
#define myECAP3_BASE                ECAP3_BASE                 //!< eCAP3 base address
#define myECAP1_SYNC_IN_OFFSET      SYSCTL_SYNCSEL_ECAP1_SYNCIN //!< eCAP1 sync input offset
#define myECAP2_SYNC_IN_OFFSET      SYSCTL_SYNCSEL_ECAP2_SYNCIN //!< eCAP2 sync input offset
#define myECAP3_SYNC_IN_OFFSET      SYSCTL_SYNCSEL_ECAP3_SYNCIN //!< eCAP3 sync input offset

#define myGPIO0_GPIO_PIN_CONFIG     GPIO_16_GPIO16             //!< GPIO0 pin configuration

#define myINPUTXBARINPUT0_SOURCE    3                          //!< INPUTXBAR input0 source
#define myINPUTXBARINPUT0_INPUT     XBAR_INPUT7                //!< INPUTXBAR input0 channel

#define INT_myECAP3                 ECAP3_IRQn                 //!< eCAP3 interrupt number
//*****************************************************************************
//
// EPWM1_A - GPIO Settings
//
//*****************************************************************************
#define GPIO_PIN_EPWM1_A            0                          //!< GPIO pin for EPWM1_A
#define myEPWM1_EPWMA_GPIO          0                          //!< GPIO number for EPWM1_A
#define myEPWM1_EPWMA_PIN_CONFIG    GPIO_0_EPWM1_A             //!< Pin configuration for EPWM1_A

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void Board_init(void);
void myECAP1_init(void);
void myECAP2_init(void);
void myECAP3_init(void);
void ECAP_init(void);
void myGPIO0_init(void);
void GPIO_init(void);
void myINPUTXBARINPUT0_init(void);
void INPUTXBAR_init(void);
void INTERRUPT_init(void);
void PinMux_init(void);
extern void Ecap3ISR(void);
extern void Unregister_ecap_ex04(void);


#ifdef __cplusplus
}
#endif


#endif
