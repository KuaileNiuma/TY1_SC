/**
 *************************************************************************************
 * @file cmpss_ex02_board.h
 * @brief This file contains the header file for example cmpss_ex02_board.
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

#ifndef CMPSS_EX02_BOARD_H_
#define CMPSS_EX02_BOARD_H_

#ifdef __cplusplus
extern "C"
{
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
// ANALOG -> myANALOGPinMux0 Pinmux
//

//
// OUTPUTXBAR3 -> myOUTPUTXBAR0 Pinmux
//
//
// OUTPUTXBAR3 - GPIO Settings
//
#define GPIO_PIN_OUTPUTXBAR3 14
#define myOUTPUTXBAR0_OUTPUTXBAR_GPIO 14
#define myOUTPUTXBAR0_OUTPUTXBAR_PIN_CONFIG GPIO_14_OUTPUTXBAR3

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
#define myCMPSS0_BASE CMPSS1_BASE
#define myCMPSS0_HIGH_COMP_BASE CMPSS1_BASE
#define myCMPSS0_LOW_COMP_BASE CMPSS1_BASE
void myCMPSS0_init();

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void myOUTPUTXBAR0_init();
#define myOUTPUTXBAR0 XBAR_OUTPUT3
#define myOUTPUTXBAR0_ENABLED_MUXES (XBAR_MUX00)

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	CMPSS_init();
void	OUTPUTXBAR_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
