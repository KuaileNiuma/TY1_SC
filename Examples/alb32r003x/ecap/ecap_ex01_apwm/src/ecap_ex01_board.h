/**
 *************************************************************************************
 * @file ecap_ex01_board.h
 * @brief This file contains the header file for example ecap_ex01_board.
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

#ifndef ECAP_EX01_BOARD_H_
#define ECAP_EX01_BOARD_H_

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
#define myECAP0_BASE                ECAP1_BASE                 //!< eCAP0 base address
#define myECAP0_CLK_EN				SYSCTL_PERIPH_CLK_ECAP1
#define myECAP0_SYNC_IN_OFFSET      SYSCTL_SYNCSEL_ECAP1_SYNCIN //!< eCAP0 sync input offset

#define myOUTPUTXBAR0_BASE		    OUTPUTXBAR_BASE           //!< Output XBAR0 base address
#define myOUTPUTXBAR0_CLK_EN		SYSCTL_PERIPH_CLK_XBAR
#define myOUTPUTXBAR0               XBAR_OUTPUT3              //!< Output XBAR0 channel
#define myOUTPUTXBAR0_ENABLED_MUXES (XBAR_MUX00)             //!< Enabled XBAR muxes

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void Board_init(void);

//*****************************************************************************
//
// ECAP Configurations for the module ECAP1
//
//*****************************************************************************
void myECAP0_init(void);

//*****************************************************************************
//
// ECAP Configurations
//
//*****************************************************************************
void ECAP_init(void);

//*****************************************************************************
//
// OUTPUTXBAR Configurations for ECAP1 output
//
//*****************************************************************************
void myOUTPUTXBAR0_init(void);

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void OUTPUTXBAR_init(void);

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
void PinMux_init(void);

#ifdef __cplusplus
}
#endif

#endif
