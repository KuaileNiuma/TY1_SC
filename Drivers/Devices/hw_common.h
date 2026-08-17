/** 
  ************************************************************************************* 
  * @file hw_common.h
  * @brief This file contains the definition of cpufeature driver. 
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

#ifndef __HW_COMMON_H
#define __HW_COMMON_H

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

#include "hw_types.h"
#include "hw_version.h"
#include "debug.h"

#if defined (IS_ALB32R003X)
    #include "alb32r003x.h"
    // #include "alb32r003x_feature.h"
    // #include "alb32r003x_int.h"
    // #include "alb32r003x_mmap.h"
    // #include "alb32r003x_pinmap.h"
#elif defined (IS_ALB32RP55)
    #include "alb32rp55.h"
   // #include "alb32rp55_feature.h"
   // #include "alb32rp55_int.h"
   // #include "alb32rp55_mmap.h"
   // #include "alb32rp55_pinmap.h"
#elif defined (IS_ALB32RP65)
    #include "alb32rp65.h"
    // #include "alb32rp65_feature.h"
    // #include "alb32rp65_int.h"
    // #include "alb32rp65_mmap.h"
    // #include "alb32rp65_pinmap.h"

#else
    #error "Error [Device must be defined]"
#endif

#include "nmsis_core.h"                     /*!< Nuclei N/NX class processor and core peripherals */
#include "system_cpu.h"                     /*!< alb32r003x System */

#ifndef __cregister
    #define __cregister
#endif

//
// Define to enable interrupts
//
#ifndef EINT
    #define EINT   __enable_irq()
#endif

//
// Define to disable interrupts
//
#ifndef DINT
    #define DINT   __disable_irq()
#endif

//
// Define to enable debug events
//
#ifndef ERTM
    #define ERTM   __asm(" clrc DBGM")
#endif

//
// Define to disable debug events
//
#ifndef DRTM
    #define DRTM   __asm(" setc DBGM")
#endif

#if defined IS_ALB32RP65 || (defined (IS_ALB32RP55) && COREID == 0)
    #define ipc0_wr(idx, val)  \
        __asm volatile(".insn r 0xb, 0x0, 0x5, x%c0, %1, x%c2"     \
        ::"K"(idx & 0x1f), "r"(val), "K"(((((idx & 0xff) >> 5) & 0x7) << 2) | (4 & 0x3)))
#endif

#ifndef EALLOW
    #ifdef IS_ALB32R003X
        #define EALLOW  (*((volatile unsigned int *) (0xe1000000)) |= (0x1))
    #elif defined IS_ALB32RP55
        #if COREID == 0
            #define EALLOW ipc0_wr(192,1)
        #else //cpu2
            #define EALLOW  (*((volatile unsigned int *) (0xe1000000)) |= (0x1))
        #endif
    #elif defined IS_ALB32RP65
        #define EALLOW ipc0_wr(192,1)
    #else
        #error "no device defined"
    #endif
#endif // EALLOW

// Define to disable writes to protected registers
#ifndef EDIS
    #ifdef IS_ALB32R003X
        #define EDIS  //(*((volatile unsigned int *) (0xe1000000)) &= ~(0x1))
    #elif defined IS_ALB32RP55
        #if COREID == 0
            #define EDIS   
        #else //cpu2
            #define EDIS  
        #endif
    #elif defined IS_ALB32RP65
        #define EDIS   //ipc0_wr(192,0)
    #else
        #error "no device defined"
  #endif
#endif // EDIS

//
// Define for emulation stop
//
#ifndef ESTOP0
    #define ESTOP0 __asm(" ESTOP0")
#endif

//
// Define for emulation stop
//
#ifndef ESTOP1
    #define ESTOP1 __asm(" ESTOP1")
#endif

//
// Define for no operation
//
#ifndef NOP
    #define NOP    __asm(" NOP")
#endif

//
// Define for putting processor into a low-power mode
//
#ifndef _DUAL_HEADERS
    #ifndef IDLE
        #define IDLE   __asm(" IDLE")
    #endif
#else
    #define IDLE_ASM __asm(" IDLE");
#endif

#ifdef __cplusplus
}
#endif


#ifndef UNUSED
#define UNUSED(x) (void)x
#endif

#endif

