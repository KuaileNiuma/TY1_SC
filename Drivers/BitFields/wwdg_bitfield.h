/** 
  ************************************************************************************* 
  * @file wwdg.h 
  * @author Albatross 
  * @brief This file contains the definition of wwdg driver. 
  * @version 1.0.0 
  * @date 2025-07-30 
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

#ifndef __ALB32R003X_WWDG_H
#define __ALB32R003X_WWDG_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup wwdg_api WWDG
//! @{
//
//*****************************************************************************

#include "alb32r003x.h"

//*****************************************************************************
//
// WWDG CR Register Bit Definitions
//
//*****************************************************************************
struct WWDG_CR_BITS {            // bits   description
    uint32_t    T:7;              // 6:0    7-Bit counter (MSB to LSB)
    uint32_t    WDGA:1;           // 7:7    Activation bit
    uint32_t    rsvd1:24;         // 31:8   reserved
};

union WWDG_CR_REG {
    uint32_t            all;
    struct WWDG_CR_BITS bit;
};

//*****************************************************************************
//
// WWDG CFR Register Bit Definitions
//
//*****************************************************************************
struct WWDG_CFR_BITS {           // bits   description
    uint32_t    W:7;              // 6:0    7-bit window value
    uint32_t    WDGTB:2;          // 8:7    Timer Base
    uint32_t    EWI:1;            // 9:9    Early Wakeup Interrupt
    uint32_t    rsvd1:22;         // 31:10  reserved
};

union WWDG_CFR_REG {
    uint32_t            all;
    struct WWDG_CFR_BITS bit;
};

//*****************************************************************************
//
// WWDG SR Register Bit Definitions
//
//*****************************************************************************
struct WWDG_SR_BITS {            // bits   description
    uint32_t    EWIF:1;           // 0:0    Early Wakeup Interrupt Flag
    uint32_t    rsvd1:31;         // 31:1   reserved
};

union WWDG_SR_REG {
    uint32_t            all;
    struct WWDG_SR_BITS bit;
};

//*****************************************************************************
//
// WWDG Module Register Structure
//
//*****************************************************************************
typedef struct {
    union WWDG_CR_REG   CR;       //!< Offset: 0x00  WWDG Control Register
    union WWDG_CFR_REG  CFR;      //!< Offset: 0x04  WWDG Configuration Register
    union WWDG_SR_REG   SR;       //!< Offset: 0x08  WWDG Status Register
} WWDG_REGS;

extern volatile struct WWDG_REGS wwdgRegs;

#endif