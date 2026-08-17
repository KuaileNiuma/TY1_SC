/**
 *************************************************************************************
 * @file clb_ex03_board.h
 * @brief This file contains the header file for example clb_ex03_board.
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

#ifndef BOARD_H
#define BOARD_H

#include "alb32r003x.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
//
// GPIO0 - GPIO Settings
//
#define myGPIO0_GPIO_PIN_CONFIG GPIO_0_GPIO0

//
// OUTPUTXBAR1 -> myOUTPUTXBAR1 Pinmux
//
//
// OUTPUTXBAR1 - GPIO Settings
//
#define GPIO_PIN_OUTPUTXBAR1 2
#define myOUTPUTXBAR1_OUTPUTXBAR_GPIO 2
#define myOUTPUTXBAR1_OUTPUTXBAR_PIN_CONFIG GPIO_2_OUTPUTXBAR1

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define myGPIO0 0
void myGPIO0_init();

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void myOUTPUTXBAR1_init();
#define myOUTPUTXBAR1 XBAR_OUTPUT1
#define myOUTPUTXBAR1_ENABLED_MUXES (XBAR_MUX01)

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void    Board_init();
void    GPIO_init();
void    OUTPUTXBAR_init();
void    PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
