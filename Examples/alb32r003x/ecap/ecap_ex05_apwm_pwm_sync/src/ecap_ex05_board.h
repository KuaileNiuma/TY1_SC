/**
 *************************************************************************************
 * @file ecap_ex05_board.h
 * @brief This file contains the header file for example ecap_ex05_board.
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

#ifndef ECAP_EX05_BOARD_H_
#define ECAP_EX05_BOARD_H_

#include "device.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define myECAP0_BASE                ECAP1_BASE                 //!< eCAP0 base address
#define myECAP1_BASE                ECAP2_BASE                 //!< eCAP1 base address

#define myECAP0_SYNC_IN_OFFSET      SYSCTL_SYNCSEL_ECAP1_SYNCIN //!< eCAP0 sync input offset
#define myECAP1_SYNC_IN_OFFSET      SYSCTL_SYNCSEL_ECAP2_SYNCIN //!< eCAP1 sync input offset

#define myOUTPUTXBAR0               XBAR_OUTPUT3               //!< OUTPUTXBAR0 output
#define myOUTPUTXBAR0_ENABLED_MUXES (XBAR_MUX00)              //!< OUTPUTXBAR0 enabled muxes

#define myOUTPUTXBAR1               XBAR_OUTPUT4               //!< OUTPUTXBAR1 output
#define myOUTPUTXBAR1_ENABLED_MUXES (XBAR_MUX02)              //!< OUTPUTXBAR1 enabled muxes

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void Board_init(void);
void myECAP0_init(void);
void myECAP1_init(void);
void ECAP_init(void);
void myOUTPUTXBAR0_init(void);
void myOUTPUTXBAR1_init(void);
void OUTPUTXBAR_init(void);
void PinMux_init(void);

#ifdef __cplusplus
}
#endif

#endif
