/**
 *************************************************************************************
 * @file sdfm_ex01_filter_sync_cpuread_board.h
 * @brief This file contains the header file for example sdfm_ex01_filter_sync_cpuread_board.
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
 
#ifndef SDFM_EX01_FILTER_SYNC_CPUREAD_BOARD_H_
#define SDFM_EX01_FILTER_SYNC_CPUREAD_BOARD_H_

#include "device.h"
#include  "alb32r003x.h"
//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
// SDFM1 SD1_C1 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C1 17                    //!< SDFM1 Channel 1 clock pin number
#define mySDFM1_SDFM1C1_GPIO 17                 //!< SDFM1 Channel 1 clock GPIO number
#define mySDFM1_SDFM1C1_PIN_CONFIG GPIO_17_SD1_C1 //!< SDFM1 Channel 1 clock pin configuration
//
// SDFM1 SD1_D1 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D1 16                    //!< SDFM1 Channel 1 data pin number
#define mySDFM1_SDFM1D1_GPIO 16                 //!< SDFM1 Channel 1 data GPIO number
#define mySDFM1_SDFM1D1_PIN_CONFIG GPIO_16_SD1_D1 //!< SDFM1 Channel 1 data pin configuration


// SDFM1 SD1_C2 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C2 33                    //!< SDFM1 Channel 2 clock pin number
#define mySDFM1_SDFM1C2_GPIO 33                 //!< SDFM1 Channel 2 clock GPIO number
#define mySDFM1_SDFM1C2_PIN_CONFIG GPIO_33_SD1_C2 //!< SDFM1 Channel 2 clock pin configuration
//
// SDFM1 SD1_D2 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D2 32                    //!< SDFM1 Channel 2 data pin number
#define mySDFM1_SDFM1D2_GPIO 32                 //!< SDFM1 Channel 2 data GPIO number
#define mySDFM1_SDFM1D2_PIN_CONFIG GPIO_32_SD1_D2 //!< SDFM1 Channel 2 data pin configuration


//
// SDFM1 SD1_C3 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C3 53                    //!< SDFM1 Channel 3 clock pin number
#define mySDFM1_SDFM1C3_GPIO 53                 //!< SDFM1 Channel 3 clock GPIO number
#define mySDFM1_SDFM1C3_PIN_CONFIG GPIO_53_SD1_C3 //!< SDFM1 Channel 3 clock pin configuration
//
// SDFM1 SD1_D3 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D3 52                    //!< SDFM1 Channel 3 data pin number
#define mySDFM1_SDFM1D3_GPIO 52                 //!< SDFM1 Channel 3 data GPIO number
#define mySDFM1_SDFM1D3_PIN_CONFIG GPIO_52_SD1_D3 //!< SDFM1 Channel 3 data pin configuration

//
// SDFM1 SD1_C4 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C4 23                    //!< SDFM1 Channel 4 clock pin number
#define mySDFM1_SDFM1C4_GPIO 23                 //!< SDFM1 Channel 4 clock GPIO number
#define mySDFM1_SDFM1C4_PIN_CONFIG GPIO_23_SD1_C4 //!< SDFM1 Channel 4 clock pin configuration

//
// SDFM1 SD1_D4 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D4 22                    //!< SDFM1 Channel 4 data pin number
#define mySDFM1_SDFM1D4_GPIO 22                 //!< SDFM1 Channel 4 data GPIO number
#define mySDFM1_SDFM1D4_PIN_CONFIG GPIO_22_SD1_D4 //!< SDFM1 Channel 4 data pin configuration

//
// SDFM2 SD2_C1 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C1 57                    //!< SDFM2 Channel 1 clock pin number
#define mySDFM2_SDFM2C1_GPIO 57                 //!< SDFM2 Channel 1 clock GPIO number
#define mySDFM2_SDFM2C1_PIN_CONFIG GPIO_57_SD2_C1 //!< SDFM2 Channel 1 clock pin configuration
//
// SDFM2 SD2_D1 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D1 56                    //!< SDFM2 Channel 1 data pin number
#define mySDFM2_SDFM2D1_GPIO 56                 //!< SDFM2 Channel 1 data GPIO number
#define mySDFM2_SDFM2D1_PIN_CONFIG GPIO_56_SD2_D1 //!< SDFM2 Channel 1 data pin configuration


// SDFM2 SD2_C2 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C2 58                    //!< SDFM2 Channel 2 clock pin number
#define mySDFM2_SDFM2C2_GPIO 58                 //!< SDFM2 Channel 2 clock GPIO number
#define mySDFM2_SDFM2C2_PIN_CONFIG GPIO_58_SD2_C2 //!< SDFM2 Channel 2 clock pin configuration
//
// SDFM2 SD2_D2 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D2 26                    //!< SDFM2 Channel 2 data pin number
#define mySDFM2_SDFM2D2_GPIO 26                 //!< SDFM2 Channel 2 data GPIO number
#define mySDFM2_SDFM2D2_PIN_CONFIG GPIO_26_SD2_D2 //!< SDFM2 Channel 2 data pin configuration

//
// SDFM2 SD2_C3 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C3 59                    //!< SDFM2 Channel 3 clock pin number
#define mySDFM2_SDFM2C3_GPIO 59                 //!< SDFM2 Channel 3 clock GPIO number
#define mySDFM2_SDFM2C3_PIN_CONFIG GPIO_59_SD2_C3 //!< SDFM2 Channel 3 clock pin configuration
//
// SDFM2 SD2_D3 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D3 51                    //!< SDFM2 Channel 3 data pin number
#define mySDFM2_SDFM2D3_GPIO 51                 //!< SDFM2 Channel 3 data GPIO number
#define mySDFM2_SDFM2D3_PIN_CONFIG GPIO_51_SD2_D3 //!< SDFM2 Channel 3 data pin configuration

//
// SDFM2 SD2_C4 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C4 60                    //!< SDFM2 Channel 4 clock pin number
#define mySDFM2_SDFM2C4_GPIO 60                 //!< SDFM2 Channel 4 clock GPIO number
#define mySDFM2_SDFM2C4_PIN_CONFIG GPIO_60_SD2_C4 //!< SDFM2 Channel 4 clock pin configuration

//
// SDFM2 SD2_D4 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D4 30                    //!< SDFM2 Channel 4 data pin number
#define mySDFM2_SDFM2D4_GPIO 30                 //!< SDFM2 Channel 4 data GPIO number
#define mySDFM2_SDFM2D4_PIN_CONFIG GPIO_30_SD2_D4 //!< SDFM2 Channel 4 data pin configuration


#endif 
