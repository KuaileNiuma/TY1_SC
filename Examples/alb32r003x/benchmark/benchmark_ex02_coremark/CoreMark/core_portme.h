/**
 *************************************************************************************
 * @file core_portme.h
 * @author Albatross
 * @brief This file contains the header file.
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
#ifndef CORE_PORTME_H
#define CORE_PORTME_H

#include "device.h"


#ifndef FLAGS_STR
#define FLAGS_STR "Please check your compiler options!"
#endif

#ifndef PERFORMANCE_RUN
#define PERFORMANCE_RUN 1
#endif

#ifndef ITERATIONS
#define ITERATIONS 10000
#endif

#ifndef FESDK_CORE_PORTME_H
#define FESDK_CORE_PORTME_H

#include <stdint.h>
#include <stddef.h>

#define HAS_FLOAT 1
#define HAS_TIME_H 1
#define USE_CLOCK 1
#define HAS_STDIO 1
#define HAS_PRINTF 1
#define SEED_METHOD SEED_VOLATILE
#define CORE_TICKS uint64_t
#define ee_u8 uint8_t
#define ee_u16 uint16_t
#if defined(__riscv_xlen) && (__riscv_xlen == 64)
// Trick used for RISC-V 64-bit coremark:
// Defining ee_u32 to be signed int instead of unsigned int,
// as 32-bit values on a 64-bit RISC-V must always be signed extended,
// so this avoids some useless sign extension shifts while still giving the correct result
// See https://forums.sifive.com/t/how-can-i-repeat-the-coremark-score/1947/3
#define ee_u32 int32_t
#else
#define ee_u32 uint32_t
#endif
#define ee_s16 int16_t
#define ee_s32 int32_t
#define ee_ptr_int uintptr_t
#define ee_size_t size_t
#define COMPILER_FLAGS FLAGS_STR

#define align_mem(x) (void *)(((ee_ptr_int)(x) + sizeof(ee_u32) - 1) & -sizeof(ee_u32))

#ifdef __GNUC__
# define COMPILER_VERSION "GCC"__VERSION__
#elif defined(__ICCRISCV__)
# define COMPILER_VERSION "IAR "__VERSION__
#else
# define COMPILER_VERSION "Unknown Compiler"
#endif

#define MEM_METHOD MEM_STACK
#define MEM_LOCATION "STACK"

#define MAIN_HAS_NOARGC 0
#define MAIN_HAS_NORETURN 0

#define MULTITHREAD 1
#define USE_PTHREAD 0
#define USE_FORK 0
#define USE_SOCKET 0

#define default_num_contexts MULTITHREAD

typedef int core_portable;
static void portable_init(core_portable* p, int* argc, char* argv[]) {}
static void portable_fini(core_portable* p) {}

#if !defined(PROFILE_RUN) && !defined(PERFORMANCE_RUN) && !defined(VALIDATION_RUN)
#if (TOTAL_DATA_SIZE==1200)
#define PROFILE_RUN 1
#elif (TOTAL_DATA_SIZE==2000)
#define PERFORMANCE_RUN 1
#else
#define VALIDATION_RUN 1
#endif
#endif

#endif

#endif
