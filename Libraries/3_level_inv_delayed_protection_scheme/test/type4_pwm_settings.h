/** 
  *************************************************************************************
  * @file type4_pwm_settings.h 
  * @author Albatross 
  * @brief This file contains the header file. 
  * @version 1.0.0 
  * @date 2025-07-30 
  *************************************************************************************
  * @copyright Copyright (c) 2025 Albatross  Semiconductor( Hangzhou ) Co ., Ltd . 
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

#ifndef TYPE4_PWM_SETTINGS_H
#define TYPE4_PWM_SETTINGS_H

#ifdef __cplusplus

extern "C" {
#endif

//
// Delay time settings
//
#define DELAY_1us       100         // 1us delay @ 100MHz TBCLK
#define DELAY_2us       200         // 2us delay @ 100MHz TBCLK

//TBPRD = TBCLK/(FPWM*2) = 100MHz/(20kHz*2) = 2500
#define PERIOD_TICKS   (uint32_t)2500
#define Falling_edge_delay   (uint16_t)50
#define Rising_edge_delay   (uint16_t)50


#define S1_S3_PWM_BASE EPWM1_BASE
#define S2_S4_PWM_BASE EPWM2_BASE

#define AUX_PWM_BASE EPWM7_BASE

#define simulate_trip_PWM_BASE EPWM8_BASE

#define S1_PWM_GPIO 0
#define S1_PWM_GPIO_PIN_CONFIG GPIO_0_EPWM1_A

#define S3_PWM_GPIO 1
#define S3_PWM_GPIO_PIN_CONFIG GPIO_1_EPWM1_B

#define S4_PWM_GPIO 2
#define S4_PWM_GPIO_PIN_CONFIG GPIO_2_EPWM2_A

#define S2_PWM_GPIO 3
#define S2_PWM_GPIO_PIN_CONFIG GPIO_3_EPWM2_B


#define AUX_PWM_GPIO 12
#define AUX_PWM_INPUT_GPIO 11
#define AUX_PWM_GPIO_PIN_CONFIG GPIO_12_EPWM7_A
#define AUX_PWM_GPIO_INPUT_CONFIG GPIO_11_GPIO11

#define ISR1_PWM_TRIGGER INT_EPWM1

#define simulate_PWM_GPIO 14
#define simulate_PWM_INPUT_GPIO 13
#define simulate_PWM_GPIO_PIN_CONFIG GPIO_14_EPWM8_A
#define simulate_PWM_GPIO_INPUT_CONFIG GPIO_13_GPIO13

#define XBAR_INPUT_system  XBAR_INPUT1
#define XBAR_INPUT_auxiliary  XBAR_INPUT3

#define XBAR_TRIP_system XBAR_TRIP4
#define XBAR_TRIP_auxiliary XBAR_TRIP7


#define DC_TRIP_system EPWM_DC_TRIP_TRIPIN4
#define DC_TRIP_auxiliary EPWM_DC_TRIP_TRIPIN7


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif
