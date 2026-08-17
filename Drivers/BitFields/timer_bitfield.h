/** 
  ************************************************************************************* 
  * @file timer.h 
  * @author Albatross 
  * @brief This file contains the definition of timer driver. 
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

#ifndef REGS_TIMER_H
#define REGS_TIMER_H
  
#ifdef __cplusplus
 extern "C" {
#endif

#include "alb32r003x.h"

struct TIMER_LOADCNT_BITS {            // bits   description
    uint32_t    LOADCNT:32;             // 31:0   Load count value
};

union TIMER_LOADCNT_REG {
    uint32_t            all;
    struct TIMER_LOADCNT_BITS    bit;
};

struct TIMER_CCVR_BITS {               // bits   description
    uint32_t    CCVR:32;                // 31:0   Current counter value
};

union TIMER_CCVR_REG {
    uint32_t            all;
    struct TIMER_CCVR_BITS       bit;
};

struct TIMER_CR_BITS {                 // bits   description
    uint32_t    ENABLE:1;               // 0:0    Timer enable bit
    uint32_t    MODE:1;                 // 1:1    Timer mode bit
    uint32_t    INT_MASK:1;             // 2:2    Interrupt mask bit
    uint32_t    PWM_MODE:1;             // 3:3   PWM mode enable
    uint32_t    ON100PWM_MODE:1;        // 4:4    100% PWM mode enable
    uint32_t    rsvd2:27;               // 31:5   Reserved
};

union TIMER_CR_REG {
    uint32_t            all;
    struct TIMER_CR_BITS         bit;
};

struct TIMER_EOI_BITS {                // bits   description
    uint32_t    TimerNEOI:1;            // 0:0    End of interrupt
    uint32_t    rsvd1:31;               // 31:1   Reserved
};

union TIMER_EOI_REG {
    uint32_t            all;
    struct TIMER_EOI_BITS        bit;
};

struct TIMER_INTSTAT_BITS {            // bits   description
    uint32_t    INTSTAT:1;              // 0:0    Interrupt status
    uint32_t    rsvd1:31;               // 31:1   Reserved
};

union TIMER_INTSTAT_REG {
    uint32_t            all;
    struct TIMER_INTSTAT_BITS    bit;
};

struct TIMER_TIMS_INSTAT_BITS {        // bits   description
    uint32_t    INSTAT:8;               // 7:0    Interrupt status for each channel
    uint32_t    rsvd1:24;               // 31:8   Reserved
};

union TIMER_TIMS_INSTAT_REG {
    uint32_t                all;
    struct TIMER_TIMS_INSTAT_BITS    bit;
};

struct TIMER_TIMS_EOI_BITS {           // bits   description
    uint32_t    TIMERSEOI:8;            // 7:0    End of interrupt for each channel
    uint32_t    rsvd1:24;               // 31:8   Reserved
};

union TIMER_TIMS_EOI_REG {
    uint32_t                all;
    struct TIMER_TIMS_EOI_BITS       bit;
};

struct TIMER_TIMS_RAWINSTAT_BITS {     // bits   description
    uint32_t    RAWINSTAT:8;            // 7:0    Raw interrupt status for each channel
    uint32_t    rsvd1:24;               // 31:8   Reserved
};

union TIMER_TIMS_RAWINSTAT_REG {
    uint32_t                    all;
    struct TIMER_TIMS_RAWINSTAT_BITS    bit;
};

struct TIMER_COMP_VERSION_BITS {       // bits   description
    uint32_t    TIMERSCOMPVERSION:32;   // 31:0   Component version
};

union TIMER_COMP_VERSION_REG {
    uint32_t                    all;
    struct TIMER_COMP_VERSION_BITS    bit;
};

struct TIMER_LOAD_COUNT2_BITS {        // bits   description
    uint32_t    LOAD_COUNT2:32;         // 31:0   Load count2 value
};

union TIMER_LOAD_COUNT2_REG {
    uint32_t                    all;
    struct TIMER_LOAD_COUNT2_BITS    bit;
};

struct TIMER_N_PROT_LEVEL_BITS {       // bits   description
    uint32_t    Timer_N_ProtLevelField:3;  // 2:0    Protection level
    uint32_t    rsvd1:29;               // 31:3   Reserved
};

union TIMER_N_PROT_LEVEL_REG {
    uint32_t                    all;
    struct TIMER_N_PROT_LEVEL_BITS    bit;
};



struct TIMER_REGS {
        union TIMER_LOADCNT_REG        LOADCNT;        // Timer N Load Count Register (0x00 + (N-1)*0x14)
        union TIMER_CCVR_REG           CCVR;           // Timer N Current Value Register (0x04 + (N-1)*0x14)
        union TIMER_CR_REG             CR;             // Timer N Control Register (0x08 + (N-1)*0x14)
        union TIMER_EOI_REG            EOI;            // Timer N End-of-Interrupt (0x0C + (N-1)*0x14)
        union TIMER_INTSTAT_REG        INTSTAT;        // Timer N Interrupt Status (0x10 + (N-1)*0x14)
        uint32_t                       rsvd1[3];       // Reserved (0x14-0x1C + (N-1)*0x14)
        union TIMER_N_PROT_LEVEL_REG       PROT_LEVEL[NUM_TIMERS];
        uint32_t                           rsvd2[0x18];    // Reserved (gap to 0xA0)
    
        // Global Timer Registers
        union TIMER_TIMS_INSTAT_REG        TIMS_INSTAT;    // Timers Interrupt Status (0xA0)
        union TIMER_TIMS_EOI_REG           TIMS_EOI;       // Timers End-of-Interrupt (0xA4)
        union TIMER_TIMS_RAWINSTAT_REG     TIMS_RAWINSTAT; // Timers Raw Interrupt Status (0xA8)
        union TIMER_COMP_VERSION_REG       COMP_VERSION;   // Timers Component Version (0xAC)
    
        // Load Count2 Registers (PWM mode) (0xB0 + (N-1)*0x04)
        union TIMER_LOAD_COUNT2_REG        LOADCNT2[NUM_TIMERS];

}

extern volatile struct TIMERTIMER_REGS timerRegs;

#endif

