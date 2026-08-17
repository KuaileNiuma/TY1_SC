/**
 *************************************************************************************
 * @file epwm_ex01_board.h
 * @brief This file contains the header file for example epwm_ex01_board.
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

#ifndef __EPWM_EX01_BOARD_H_
#define __EPWM_EX01_BOARD_H_

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
#define GPIO_PIN_EPWM1_A 0  //!< EPWM1 A channel GPIO pin number
#define myEPWM1_EPWMA_GPIO 0  //!< EPWM1 A channel GPIO number
#define myEPWM1_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A  //!< EPWM1 A channel pin configuration
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1  //!< EPWM1 B channel GPIO pin number
#define myEPWM1_EPWMB_GPIO 1  //!< EPWM1 B channel GPIO number
#define myEPWM1_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B  //!< EPWM1 B channel pin configuration

//
// EPWM2 -> myEPWM2 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2  //!< EPWM2 A channel GPIO pin number
#define myEPWM2_EPWMA_GPIO 2  //!< EPWM2 A channel GPIO number
#define myEPWM2_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A  //!< EPWM2 A channel pin configuration
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3  //!< EPWM2 B channel GPIO pin number
#define myEPWM2_EPWMB_GPIO 3  //!< EPWM2 B channel GPIO number
#define myEPWM2_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B  //!< EPWM2 B channel pin configuration

//
// EPWM3 -> myEPWM3 Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 4  //!< EPWM3 A channel GPIO pin number
#define myEPWM3_EPWMA_GPIO 4  //!< EPWM3 A channel GPIO number
#define myEPWM3_EPWMA_PIN_CONFIG GPIO_4_EPWM3_A  //!< EPWM3 A channel pin configuration
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 5  //!< EPWM3 B channel GPIO pin number
#define myEPWM3_EPWMB_GPIO 5  //!< EPWM3 B channel GPIO number
#define myEPWM3_EPWMB_PIN_CONFIG GPIO_5_EPWM3_B  //!< EPWM3 B channel pin configuration

// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 6  //!< EPWM4 A channel GPIO pin number
#define myEPWM4_EPWMA_GPIO 6  //!< EPWM4 A channel GPIO number
#define myEPWM4_EPWMA_PIN_CONFIG GPIO_6_EPWM4_A  //!< EPWM4 A channel pin configuration
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 7  //!< EPWM4 B channel GPIO pin number
#define myEPWM4_EPWMB_GPIO 7  //!< EPWM4 B channel GPIO number
#define myEPWM4_EPWMB_PIN_CONFIG GPIO_7_EPWM4_B  //!< EPWM4 B channel pin configuration

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define myEPWM1_BASE EPWM1_BASE  //!< EPWM1 base address
#define myEPWM1_TBPRD 0  //!< EPWM1 time base period
#define myEPWM1_COUNTER_MODE EPWM_COUNTER_MODE_STOP_FREEZE  //!< EPWM1 counter mode
#define myEPWM1_TBPHS 0  //!< EPWM1 time base phase shift
#define myEPWM1_CMPA 0  //!< EPWM1 compare A value
#define myEPWM1_CMPB 0  //!< EPWM1 compare B value
#define myEPWM1_CMPC 0  //!< EPWM1 compare C value
#define myEPWM1_CMPD 0  //!< EPWM1 compare D value
#define myEPWM1_DBRED 0  //!< EPWM1 dead-band rising edge delay
#define myEPWM1_DBFED 0  //!< EPWM1 dead-band falling edge delay
#define myEPWM1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z  //!< EPWM1 trip zone A action
#define myEPWM1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z  //!< EPWM1 trip zone B action
#define myEPWM1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED  //!< EPWM1 interrupt source
#define myEPWM2_BASE EPWM2_BASE  //!< EPWM2 base address
#define myEPWM2_TBPRD 0  //!< EPWM2 time base period
#define myEPWM2_COUNTER_MODE EPWM_COUNTER_MODE_STOP_FREEZE  //!< EPWM2 counter mode
#define myEPWM2_TBPHS 0  //!< EPWM2 time base phase shift
#define myEPWM2_CMPA 0  //!< EPWM2 compare A value
#define myEPWM2_CMPB 0  //!< EPWM2 compare B value
#define myEPWM2_CMPC 0  //!< EPWM2 compare C value
#define myEPWM2_CMPD 0  //!< EPWM2 compare D value
#define myEPWM2_DBRED 0  //!< EPWM2 dead-band rising edge delay
#define myEPWM2_DBFED 0  //!< EPWM2 dead-band falling edge delay
#define myEPWM2_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z  //!< EPWM2 trip zone A action
#define myEPWM2_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z  //!< EPWM2 trip zone B action
#define myEPWM2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED  //!< EPWM2 interrupt source
#define myEPWM3_BASE EPWM3_BASE  //!< EPWM3 base address
#define myEPWM3_TBPRD 0  //!< EPWM3 time base period
#define myEPWM3_COUNTER_MODE EPWM_COUNTER_MODE_STOP_FREEZE  //!< EPWM3 counter mode
#define myEPWM3_TBPHS 0  //!< EPWM3 time base phase shift
#define myEPWM3_CMPA 0  //!< EPWM3 compare A value
#define myEPWM3_CMPB 0  //!< EPWM3 compare B value
#define myEPWM3_CMPC 0  //!< EPWM3 compare C value
#define myEPWM3_CMPD 0  //!< EPWM3 compare D value
#define myEPWM3_DBRED 0  //!< EPWM3 dead-band rising edge delay
#define myEPWM3_DBFED 0  //!< EPWM3 dead-band falling edge delay
#define myEPWM3_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z  //!< EPWM3 trip zone A action
#define myEPWM3_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z  //!< EPWM3 trip zone B action
#define myEPWM3_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED  //!< EPWM3 interrupt source

#define myEPWM4_BASE EPWM4_BASE  //!< EPWM4 base address

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void Board_init();  //!< Initialize board and all modules
void EPWM_init();  //!< Initialize EPWM modules
void SYNC_init();  //!< Initialize synchronization
void PinMux_init();  //!< Initialize pin muxing
void PREPWM_init();  //!< Pre-initialize EPWM modules
void configurePhase(uint32_t base, uint32_t masterBase, uint16_t phaseVal);  //!< Configure EPWM phase


#ifdef __cplusplus
}
#endif


#endif
