/**
 *************************************************************************************
 * @file zhanlu_cycle_test.c
 * @brief This file contains the source file for example zhanlu_cycle_test.
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
#include <stdio.h>
#include "device.h"

uint64_t cycle_no, cycle_add, cycle;

#define  SINGLE_RUN   0
#define  CNT  (100)

#if SINGLE_RUN
#define IMPL_TEST_FUNC_2op(insn)    \
    void test##insn()          \
    {                                                                       \
        int i;                                                              \
        uint64_t star_cycle = 0;                                            \
        uint64_t end_cycle = 0;                                             \
                                                                            \
        __set_rv_cycle(0);                                                  \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++)                                           \
            ;                                                               \
        end_cycle = __get_rv_cycle();                                       \
        cycle_no = end_cycle - star_cycle;                                  \
                                                                            \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++){                                          \
            __asm volatile ("\n\t .rept 100"                                 \
                            "\n\t "#insn" fa1, fa0"                         \
                            "\n\t .endr" );                                 \
        }                                                                   \
	    end_cycle = __get_rv_cycle();                                       \
	    cycle_add = end_cycle - star_cycle;                                 \
                                                                            \
	    cycle = cycle_add - cycle_no;                                       \
        printf(""#insn" %d times cost: %d cycle\r\n", 100 * CNT, cycle);    \
    }

#define IMPL_TEST_FUNC_3op(insn)    \
    void test##insn()          \
    {                                                                       \
        int i;                                                              \
        uint64_t star_cycle = 0;                                            \
        uint64_t end_cycle = 0;                                             \
                                                                            \
        __set_rv_cycle(0);                                                  \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++)                                           \
            ;                                                               \
        end_cycle = __get_rv_cycle();                                       \
        cycle_no = end_cycle - star_cycle;                                  \
                                                                            \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++){                                          \
            __asm volatile ("\n\t .rept 100"                                \
                            "\n\t "#insn" fa2, fa0, fa1"                    \
                            "\n\t .endr" );                                 \
        }                                                                   \
	    end_cycle = __get_rv_cycle();                                       \
	    cycle_add = end_cycle - star_cycle;                                 \
                                                                            \
	    cycle = cycle_add - cycle_no;                                       \
        printf(""#insn" %d times cost: %d cycle\r\n", 100 * CNT, cycle);    \
    }

#define IMPL_TEST_FUNC_3op_imm(insn)    \
    void test##insn()          \
    {                                                                       \
        int i;                                                              \
        uint64_t star_cycle = 0;                                            \
        uint64_t end_cycle = 0;                                             \
                                                                            \
        __set_rv_cycle(0);                                                  \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++)                                           \
            ;                                                               \
        end_cycle = __get_rv_cycle();                                       \
        cycle_no = end_cycle - star_cycle;                                  \
                                                                            \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++){                                          \
            __asm volatile ("\n\t .rept 100"                                 \
                            "\n\t "#insn" fa1, fa0, 1"                      \
                            "\n\t .endr" );                                 \
        }                                                                   \
	    end_cycle = __get_rv_cycle();                                       \
	    cycle_add = end_cycle - star_cycle;                                 \
                                                                            \
	    cycle = cycle_add - cycle_no;                                       \
        printf(""#insn" %d times cost: %d cycle\r\n", 100 * CNT, cycle);    \
    }
#else
#define IMPL_TEST_FUNC_2op(insn)    \
    void test##insn()          \
    {                                                                       \
        int i;                                                              \
        uint64_t star_cycle = 0;                                            \
        uint64_t end_cycle = 0;                                             \
                                                                            \
        __set_rv_cycle(0);                                                  \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++)                                           \
            ;                                                               \
        end_cycle = __get_rv_cycle();                                       \
        cycle_no = end_cycle - star_cycle;                                  \
                                                                            \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++){                                          \
            __asm volatile ("\n\t .rept 20"                                 \
                            "\n\t "#insn" fa1, fa0"                         \
                            "\n\t "#insn" fa2, fa0"                         \
                            "\n\t "#insn" fa3, fa0"                         \
                            "\n\t "#insn" fa4, fa0"                         \
                            "\n\t "#insn" fa5, fa0"                         \
                            "\n\t .endr" );                                 \
        }                                                                   \
	    end_cycle = __get_rv_cycle();                                       \
	    cycle_add = end_cycle - star_cycle;                                 \
                                                                            \
	    cycle = cycle_add - cycle_no;                                       \
        printf(""#insn" %d times cost: %d cycle\r\n", 100 * CNT, cycle);    \
    }

#define IMPL_TEST_FUNC_3op(insn)    \
    void test##insn()          \
    {                                                                       \
        int i;                                                              \
        uint64_t star_cycle = 0;                                            \
        uint64_t end_cycle = 0;                                             \
                                                                            \
        __set_rv_cycle(0);                                                  \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++)                                           \
            ;                                                               \
        end_cycle = __get_rv_cycle();                                       \
        cycle_no = end_cycle - star_cycle;                                  \
                                                                            \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++){                                          \
            __asm volatile ("\n\t .rept 20"                                 \
                            "\n\t "#insn" fa2, fa0, fa1"                    \
                            "\n\t "#insn" fa3, fa0, fa1"                    \
                            "\n\t "#insn" fa4, fa0, fa1"                    \
                            "\n\t "#insn" fa5, fa0, fa1"                    \
                            "\n\t "#insn" fa6, fa0, fa1"                    \
                            "\n\t .endr" );                                 \
        }                                                                   \
	    end_cycle = __get_rv_cycle();                                       \
	    cycle_add = end_cycle - star_cycle;                                 \
                                                                            \
	    cycle = cycle_add - cycle_no;                                       \
        printf(""#insn" %d times cost: %d cycle\r\n", 100 * CNT, cycle);    \
    }

#define IMPL_TEST_FUNC_3op_imm(insn)    \
    void test##insn()          \
    {                                                                       \
        int i;                                                              \
        uint64_t star_cycle = 0;                                            \
        uint64_t end_cycle = 0;                                             \
                                                                            \
        __set_rv_cycle(0);                                                  \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++)                                           \
            ;                                                               \
        end_cycle = __get_rv_cycle();                                       \
        cycle_no = end_cycle - star_cycle;                                  \
                                                                            \
        star_cycle = __get_rv_cycle();                                      \
        for (i = 0; i < CNT; i++){                                          \
            __asm volatile ("\n\t .rept 20"                                 \
                            "\n\t "#insn" fa1, fa0, 1"                      \
                            "\n\t "#insn" fa2, fa0, 1"                      \
                            "\n\t "#insn" fa3, fa0, 1"                      \
                            "\n\t "#insn" fa4, fa0, 1"                      \
                            "\n\t "#insn" fa5, fa0, 1"                      \
                            "\n\t .endr" );                                 \
        }                                                                   \
	    end_cycle = __get_rv_cycle();                                       \
	    cycle_add = end_cycle - star_cycle;                                 \
                                                                            \
	    cycle = cycle_add - cycle_no;                                       \
        printf(""#insn" %d times cost: %d cycle\r\n", 100 * CNT, cycle);    \
    }
#endif

#define TEST_FUNC(insn)   test##insn()

IMPL_TEST_FUNC_2op(sqrtf32)
IMPL_TEST_FUNC_2op(sinpuf32)
IMPL_TEST_FUNC_2op(cospuf32)
IMPL_TEST_FUNC_2op(atanpuf32)
IMPL_TEST_FUNC_2op(expf32)
IMPL_TEST_FUNC_2op(aexpf32)
IMPL_TEST_FUNC_2op(nexpf32)
IMPL_TEST_FUNC_2op(iexpf32)
IMPL_TEST_FUNC_2op(log2f32)
IMPL_TEST_FUNC_3op(divf32)
IMPL_TEST_FUNC_3op(sumsqf32)
IMPL_TEST_FUNC_3op(atan2divf32)
IMPL_TEST_FUNC_3op(atan2quadf32)
IMPL_TEST_FUNC_2op(mpy2pif32)
IMPL_TEST_FUNC_2op(div2pif32)
IMPL_TEST_FUNC_2op(nmpy2pif32)
IMPL_TEST_FUNC_2op(ndiv2pif32)
IMPL_TEST_FUNC_2op(mpy2f32)
IMPL_TEST_FUNC_2op(mpy2div3f32)
IMPL_TEST_FUNC_2op(div2f32)
IMPL_TEST_FUNC_2op(div3f32)
IMPL_TEST_FUNC_2op(div4f32)
IMPL_TEST_FUNC_2op(mpysqrt3f32)
IMPL_TEST_FUNC_2op(mpysqrt3div2f32)
IMPL_TEST_FUNC_2op(mpysqrt3div6f32)
IMPL_TEST_FUNC_2op(divsqrt3f32)
IMPL_TEST_FUNC_2op(mpy2divsqrt3f32)
IMPL_TEST_FUNC_2op(mpylog2ef32)
IMPL_TEST_FUNC_2op(add1f32)
IMPL_TEST_FUNC_2op(sub1f32)
IMPL_TEST_FUNC_2op(nadd1f32)
IMPL_TEST_FUNC_2op(nsub1f32)
IMPL_TEST_FUNC_2op(addsqrt3f32)
IMPL_TEST_FUNC_2op(subsqrt3f32)
IMPL_TEST_FUNC_2op(naddsqrt3f32)
IMPL_TEST_FUNC_2op(nsubsqrt3f32)
IMPL_TEST_FUNC_2op(addpid3f32)
IMPL_TEST_FUNC_2op(subpid3f32)
IMPL_TEST_FUNC_2op(naddpid3f32)
IMPL_TEST_FUNC_2op(nsubpid3f32)
IMPL_TEST_FUNC_2op(truncf32)
IMPL_TEST_FUNC_2op(fractf32)
IMPL_TEST_FUNC_3op_imm(naddcstf32)
IMPL_TEST_FUNC_3op_imm(nsubcstf32)
IMPL_TEST_FUNC_3op(satf32)


//*****************************************************************************
//
// zhanlu_cycle_test
//
//*****************************************************************************
void zhanlu_cycle_test(void)
{
	TEST_FUNC(sqrtf32);
	TEST_FUNC(sinpuf32);
	TEST_FUNC(cospuf32);
	TEST_FUNC(atanpuf32);
	TEST_FUNC(expf32);
	TEST_FUNC(aexpf32);
	TEST_FUNC(nexpf32);
	TEST_FUNC(iexpf32);
	TEST_FUNC(log2f32);
	TEST_FUNC(divf32);
	TEST_FUNC(sumsqf32);
	TEST_FUNC(atan2divf32);
	TEST_FUNC(atan2quadf32);
	TEST_FUNC(mpy2pif32);
	TEST_FUNC(div2pif32);
	TEST_FUNC(nmpy2pif32);
	TEST_FUNC(ndiv2pif32);
	TEST_FUNC(mpy2f32);
	TEST_FUNC(mpy2div3f32);
	TEST_FUNC(div2f32);
	TEST_FUNC(div3f32);
	TEST_FUNC(div4f32);
	TEST_FUNC(mpysqrt3f32);
	TEST_FUNC(mpysqrt3div2f32);
	TEST_FUNC(mpysqrt3div6f32);
	TEST_FUNC(divsqrt3f32);
	TEST_FUNC(mpy2divsqrt3f32);
	TEST_FUNC(mpylog2ef32);
	TEST_FUNC(add1f32);
	TEST_FUNC(sub1f32);
	TEST_FUNC(nadd1f32);
	TEST_FUNC(nsub1f32);
	TEST_FUNC(addsqrt3f32);
	TEST_FUNC(subsqrt3f32);
	TEST_FUNC(naddsqrt3f32);
	TEST_FUNC(nsubsqrt3f32);
	TEST_FUNC(addpid3f32);
	TEST_FUNC(subpid3f32);
	TEST_FUNC(naddpid3f32);
	TEST_FUNC(nsubpid3f32);
	TEST_FUNC(truncf32);
	TEST_FUNC(fractf32);
	TEST_FUNC(naddcstf32);
	TEST_FUNC(nsubcstf32);
	TEST_FUNC(satf32);
}
