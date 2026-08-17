/**
 *************************************************************************************
 * @file hw_lpm.h
 * @brief This file implements the function of hw_lpm driver.
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

#ifndef _HW_LPM_H
#define _HW_LPM_H
#if LPM_HW_VER==0
/******************************************************************************/
/*                                                                            */
/*                                 LPM Registers                              */
/*                                                                            */
/******************************************************************************/

#define LPM_O_CR                             0x0U
#define LPM_O_CSR                            0x4U


/*******************  Bit definition for LPM_CR register  ******************/
#define LPM_CR_CWUF_POS                                 (2)
#define LPM_CR_LVDE_POS                                (11)
#define LPM_CR_BOREN_POS                               (20)
#define LPM_CR_VTMP_BUF_EN_POS                         (23)
#define LPM_CR_VBG_BUF_EN_POS                          (24)

/*******************  Bit definition for LPM_CSR register  ******************/
#define LPM_CSR_WUF_POS                                 (0)
#define LPM_CSR_SBF_POS                                 (1)
#define LPM_CSR_LVDO_POS                                (2)
#define LPM_CSR_EWUP_POS                                (8)
#elif LPM_HW_VER==1

#endif
#endif
