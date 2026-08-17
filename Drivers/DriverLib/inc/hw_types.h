/**
 *************************************************************************************
 * @file hw_types.h
 * @brief This file contains the definition of hw_types driver.
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

#ifndef HW_TYPES_H
#define HW_TYPES_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "nmsis_compiler.h"

// use for print
#define DEBUG_PRINT

#ifdef DEBUG_PRINT
    #define error_print    printf
    #define log_printf     printf
    #define debug_print    printf
#else
    #define error_print(fmt, ...)
    #define log_printf(fmt, ...)
    #define debug_print(fmt, ...)
#endif
//end of print

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))


typedef enum
{
    RESET = 0,
    SET   = 1
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE  = !DISABLE
} FunctionalState;

typedef enum
{
    ReSet = 0,
    Set   = 1
} Status;

//*****************************************************************************
//
// Macros for hardware access
//
//*****************************************************************************
#define HWREG(x)    (*((volatile uint32_t *) (x)))
#define HWREGH(x)   (*((volatile uint16_t *) (x)))
#define HWREGB(x)   (*((volatile uint8_t *) (x)))

#define HWREG_BP(x) __byte_peripheral_32((uint32_t *) (x))


/* Macros for memory access operations */
#define _REG8P(p, i)                        ((volatile uint8_t *) ((uintptr_t)((p) + (i))))
#define _REG16P(p, i)                       ((volatile uint16_t *) ((uintptr_t)((p) + (i))))
#define _REG32P(p, i)                       ((volatile uint32_t *) ((uintptr_t)((p) + (i))))
#define _REG64P(p, i)                       ((volatile uint64_t *) ((uintptr_t)((p) + (i))))
#define _REG8(p, i)                         (*(_REG8P(p, i)))
#define _REG16(p, i)                        (*(_REG16P(p, i)))
#define _REG32(p, i)                        (*(_REG32P(p, i)))
#define _REG64(p, i)                        (*(_REG64P(p, i)))
#define REG8(addr)                          _REG8((addr), 0)
#define REG16(addr)                         _REG16((addr), 0)
#define REG32(addr)                         _REG32((addr), 0)
#define REG64(addr)                         _REG64((addr), 0)

/* Macros for address type convert and access operations */
#define ADDR16(addr)                        ((uint16_t)(uintptr_t)(addr))
#define ADDR32(addr)                        ((uint32_t)(uintptr_t)(addr))
#define ADDR64(addr)                        ((uint64_t)(uintptr_t)(addr))
#define ADDR8P(addr)                        ((uint8_t *)(uintptr_t)(addr))
#define ADDR16P(addr)                       ((uint16_t *)(uintptr_t)(addr))
#define ADDR32P(addr)                       ((uint32_t *)(uintptr_t)(addr))
#define ADDR64P(addr)                       ((uint64_t *)(uintptr_t)(addr))

#define BITMASK_MAX                         0xFFFFFFFFUL
#define BITOFS_MAX                          31

//
// BIT/BITS only support bit mask for __riscv_xlen
// For RISC-V 32 bit, it support mask 32 bit wide
// For RISC-V 64 bit, it support mask 64 bit wide
#define BIT(ofs)                            ((ofs) < 32 ? (0x1UL << (ofs)) : 0)
#define BITS(start, end)                    ((BITMASK_MAX) << (start) & (BITMASK_MAX) >> (BITOFS_MAX - (end)))
#define GET_BIT(regval, bitofs)             (((regval) >> (bitofs)) & 0x1)
#define SET_BIT(regval, bitofs)             ((regval) |= BIT(bitofs))
#define CLR_BIT(regval, bitofs)             ((regval) &= (~BIT(bitofs)))
#define FLIP_BIT(regval, bitofs)            ((regval) ^= BIT(bitofs))
#define WRITE_BIT(regval, bitofs, val)      CLR_BIT(regval, bitofs); ((regval) |= ((val) << bitofs) & BIT(bitofs))
#define CHECK_BIT(regval, bitofs)           (!!((regval) & (0x1UL<<(bitofs))))
#define GET_BITS(regval, start, end)        (((regval) & BITS((start), (end))) >> (start))
#define SET_BITS(regval, start, end)        ((regval) |= BITS((start), (end)))
#define CLR_BITS(regval, start, end)        ((regval) &= (~BITS((start), (end))))
#define FLIP_BITS(regval, start, end)       ((regval) ^= BITS((start), (end)))
#define WRITE_BITS(regval, start, end, val) CLR_BITS(regval, start, end); ((regval) |= ((val) << start) & BITS((start), (end)))
#define CHECK_BITS_ALL(regval, start, end)  (!((~(regval)) & BITS((start), (end))))
#define CHECK_BITS_ANY(regval, start, end)  ((regval) & BITS((start), (end)))

#define BITMASK_SET(regval, mask)           ((regval) |= (mask))
#define BITMASK_CLR(regval, mask)           ((regval) &= (~(mask)))
#define BITMASK_FLIP(regval, mask)          ((regval) ^= (mask))
#define BITMASK_CHECK_ALL(regval, mask)     (!((~(regval)) & (mask)))
#define BITMASK_CHECK_ANY(regval, mask)     ((regval) & (mask))

#define CLEAR_BIT(REG, BIT)                 ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)                  ((REG) & (BIT))
#define CLEAR_REG(REG)                      ((REG) = (0x0))
#define WRITE_REG(REG, VAL)                 ((REG) = (VAL))
#define READ_REG(REG)                       ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_S_SUCCESS (0)
#define STATUS_E_FAILURE (-1)

//****************************************************************************
//
// For checking NULL pointers
//
//****************************************************************************
#ifndef NULL
    #define NULL ((void *) 0x0)
#endif

//*****************************************************************************
//
// 32-bit and 64-bit float type
//
//*****************************************************************************

typedef float float32_t;
typedef double float64_t;

//*****************************************************************************
//
// Extern compiler intrinsic prototypes. See compiler User's Guide for details.
// These are provided to satisfy static analysis tools. The #ifndef is required
// because the '&' is for a C++-style reference, and although it is the correct
// prototype, it will not build in C code.
//
//*****************************************************************************
extern int16_t *__byte(int16_t *array, uint16_t byte_index);
extern uint32_t *__byte_peripheral_32(uint32_t *x);

//*****************************************************************************
//
// Prototype for the function that is called when an invalid argument is passed
// to an API.  This is only used when doing a DEBUG build. It is the
// application's responsibility to define the __error__ function.
//
//*****************************************************************************
extern void __error__(const char *filename, uint32_t line);

//
// C++ Bool Compatibility
//
#if defined(__cplusplus)
typedef bool _Bool;
#endif

/* To fix Misra-C errors */
#ifndef TRUE
    #define TRUE ((bool) 1)
#endif
#ifndef FALSE
    #define FALSE ((bool) 0)
#endif

#ifndef ERTM
    #define ERTM
#endif

#if defined (RUN_ON_EFLASH) || defined (RUN_ON_XFLASH)
    #define ILM_FUNC_T __attribute__((section(".text.ilm ")))
    #define SRAM_BSS_T __attribute__((section(".data_sram")))
#else
    #define ILM_FUNC_T
    #define SRAM_BSS_T
#endif

#endif    // HW_TYPES_H
