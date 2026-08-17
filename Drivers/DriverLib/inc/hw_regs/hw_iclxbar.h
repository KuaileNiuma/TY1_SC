/**
 *************************************************************************************
 * @file hw_iclxbar.h
 * @brief This file implements the function of hw_iclxbar driver.
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

#ifndef HW_ICLXBAR_H
#define HW_ICLXBAR_H

//*************************************************************************************************
//
// The following are defines for the XBAR register offsets
//
//*************************************************************************************************
#define XBAR_O_ICL1SELECT        0x0U    // ICL1SELECT Input Select Register
#define XBAR_O_ICL2SELECT        0x2U    // ICL2SELECT Input Select Register
#define XBAR_O_ICL3SELECT        0x4U    // ICL3SELECT Input Select Register
#define XBAR_O_ICL4SELECT        0x6U    // ICL4SELECT Input Select Register
#define XBAR_O_ICL5SELECT        0x8U    // ICL5SELECT Input Select Register
#define XBAR_O_ICL6SELECT        0xAU    // ICL6SELECT Input Select Register
#define XBAR_O_ICL7SELECT        0xCU    // ICL7SELECT Input Select Register
#define XBAR_O_ICL8SELECT        0xEU    // ICL8SELECT Input Select Register
#define XBAR_O_ICL9SELECT        0x10U   // ICL9SELECT Input Select Register
#define XBAR_O_ICL10SELECT       0x12U   // ICL10SELECT Input Select Register
#define XBAR_O_ICL11SELECT       0x14U   // ICL11SELECT Input Select Register
#define XBAR_O_ICL12SELECT       0x16U   // ICL12SELECT Input Select Register
#define XBAR_O_ICL13SELECT       0x18U   // ICL13SELECT Input Select Register
#define XBAR_O_ICL14SELECT       0x1AU   // ICL14SELECT Input Select Register
#define XBAR_O_ICL15SELECT       0x1CU   // ICL15SELECT Input Select Register
#define XBAR_O_ICL16SELECT       0x1EU   // ICL16SELECT Input Select Register
#define XBAR_O_INPUTSELECTLOCK   0x3CU   // Input Select Lock Register



//*************************************************************************************************
//
// The following are defines for the bit fields in the INPUTSELECTLOCK register
//
//*************************************************************************************************
#define XBAR_INPUTSELECTLOCK_ICL1SELECT    0x1U      // Lock bit for ICL1SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL2SELECT    0x2U      // Lock bit for ICL2SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL3SELECT    0x4U      // Lock bit for ICL3SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL4SELECT    0x8U      // Lock bit for ICL4SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL5SELECT    0x10U     // Lock bit for ICL5SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL6SELECT    0x20U     // Lock bit for ICL6SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL7SELECT    0x40U     // Lock bit for ICL7SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL8SELECT    0x80U     // Lock bit for ICL8SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL9SELECT    0x100U    // Lock bit for ICL9SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL10SELECT   0x200U    // Lock bit for ICL10SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL11SELECT   0x400U    // Lock bit for ICL11SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL12SELECT   0x800U    // Lock bit for ICL12SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL13SELECT   0x1000U   // Lock bit for ICL13SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL14SELECT   0x2000U   // Lock bit for ICL14SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL15SELECT   0x4000U   // Lock bit for ICL15SELECT Register
#define XBAR_INPUTSELECTLOCK_ICL16SELECT   0x8000U   // Lock bit for ICL16SELECT Register



#endif
