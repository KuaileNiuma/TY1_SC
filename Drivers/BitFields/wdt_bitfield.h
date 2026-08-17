/** 
  ************************************************************************************* 
  * @file wdt.h 
  * @author Albatross 
  * @brief This file contains the definition of wdt driver. 
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

#ifndef REGS_CRC_H
#define REGS_CRC_H

#ifdef __cplusplus
extern "C" {
#endif



//*****************************************************************************
//
// CR (Control Register) Bit Fields
//
//*****************************************************************************
struct WDT_CR_BITS {
    uint32_t    ENABLE:1;          // 0:0    Watchdog Timer Enable
    uint32_t    RMOD:1;            // 1:1    Reset Mode
    uint32_t    RPL:3;             // 4:2    Reset Pull Level
    uint32_t    rsvd1:1;         // 5:5    Reserved
    uint32_t    rsvd2:26;          // 31:6   reserved
};

union WDT_CR_REG {
    uint32_t            all;
    struct WDT_CR_BITS  bit;
};

//*****************************************************************************
//
// TORR (Timeout Range Register) Bit Fields
//
//*****************************************************************************
struct WDT_TORR_BITS {
    uint32_t    TOP:4;             // 3:0    Timeout Period
    uint32_t    rsvd1:28;          // 31:4   reserved
};

union WDT_TORR_REG {
    uint32_t            all;
    struct WDT_TORR_BITS bit;
};

//*****************************************************************************
//
// CCVR (Current Counter Value Register) Bit Fields
//
//*****************************************************************************
struct WDT_CCVR_BITS {
    uint32_t    CURRENT:32;        // 31:0   Current Counter Value
};

union WDT_CCVR_REG {
    uint32_t            all;
    struct WDT_CCVR_BITS bit;
};

//*****************************************************************************
//
// CRR (Counter Restart Register) Bit Fields
//
//*****************************************************************************
struct WDT_CRR_BITS {
    uint32_t    RESTART:8;         // 7:0    Restart Key
    uint32_t    rsvd1:24;          // 31:8   reserved
};

union WDT_CRR_REG {
    uint32_t            all;
    struct WDT_CRR_BITS bit;
};

//*****************************************************************************
//
// STAT (Status Register) Bit Fields
//
//*****************************************************************************
struct WDT_STAT_BITS {
    uint32_t    IS:1;              // 0:0    Interrupt Status
    uint32_t    rsvd1:31;          // 31:1   reserved
};

union WDT_STAT_REG {
    uint32_t            all;
    struct WDT_STAT_BITS bit;
};

//*****************************************************************************
//
// EOI (End of Interrupt Register) Bit Fields
//
//*****************************************************************************
struct WDT_EOI_BITS {
    uint32_t    EOI:1;             // 0:0    End of Interrupt
    uint32_t    rsvd1:31;          // 31:1   reserved
};

union WDT_EOI_REG {
    uint32_t            all;
    struct WDT_EOI_BITS bit;
};

struct WDT_REGS {
    union WDT_CR_REG     WDT_CR;         // Offset: 0x000 (R/W)  Control Register */
    union WDT_TORR_REG 	 WDT_TORR;       // Offset: 0x004 (R/W)  Timeout Range Register */
    union WDT_CCVR_REG   WDT_CCVR;       // Offset: 0x008 (R/ )  Current Counter Value Register */
    union WDT_CRR_REG    WDT_CRR;        // Offset: 0x00C ( /W)  Counter Restart Register */
    union WDT_STAT_REG   WDT_STAT;       // Offset: 0x010 (R/ )  Status Register */
    union WDT_EOI_REG    WDT_EOI;        // Offset: 0x014 (R/ )  End of Interrupt Register */
}




extern volatile struct WDT_REGS wdtRegs;



#endif  // end of REGS_CRC_H definition
