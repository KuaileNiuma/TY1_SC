/**
 *************************************************************************************
 * @file core_feature_vcu.h
 * @brief This file contains the definition of device driver.
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

#ifndef __CORE_FEATURE_VCU__
#define __CORE_FEATURE_VCU__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

static inline float __satf32(float din1, float din2, float din3)
{
    __asm volatile("\n\tsatf32 %0, %1, %2"
  :"+f"(din1)
  :"f"(din2), "f"(din3)
  );
  return din1;
}

// zhanlu
#define __alb_mpy2pif32(a)                  \
  (__builtin_riscv_mpy2pif32((a)))
#define __alb_div2pif32(a)                  \
  (__builtin_riscv_div2pif32((a)))
#define __alb_nmpy2pif32(a)                 \
  (__builtin_riscv_nmpy2pif32((a)))
#define __alb_ndiv2pif32(a)                 \
  (__builtin_riscv_ndiv2pif32((a)))
#define __alb_mpy2f32(a)                    \
  (__builtin_riscv_mpy2f32((a)))
#define __alb_mpy2div3f32(a)                \
  (__builtin_riscv_mpy2div3f32((a)))
#define __alb_div2f32(a)                    \
  (__builtin_riscv_div2f32((a)))
#define __alb_div3f32(a)                    \
  (__builtin_riscv_div3f32((a)))
#define __alb_div4f32(a)                    \
  (__builtin_riscv_div4f32((a)))
#define __alb_mpysqrt3f32(a)                \
  (__builtin_riscv_mpysqrt3f32((a)))
#define __alb_mpysqrt3div2f32(a)            \
  (__builtin_riscv_mpysqrt3div2f32((a)))
#define __alb_mpysqrt3div6f32(a)            \
  (__builtin_riscv_mpysqrt3div6f32((a)))
#define __alb_divsqrt3f32(a)                \
  (__builtin_riscv_divsqrt3f32((a)))
#define __alb_mpy2divsqrt3f32(a)            \
  (__builtin_riscv_mpy2divsqrt3f32((a)))
#define __alb_mpylog2ef32(a)                \
  (__builtin_riscv_mpylog2ef32((a)))
#define __alb_nmpylog2ef32(a)               \
  (__builtin_riscv_nmpylog2ef32((a)))
#define __alb_add1f32(a)                    \
  (__builtin_riscv_add1f32((a)))
#define __alb_sub1f32(a)                    \
  (__builtin_riscv_sub1f32((a)))
#define __alb_nadd1f32(a)                   \
  (__builtin_riscv_nadd1f32((a)))
#define __alb_nsub1f32(a)                   \
  (__builtin_riscv_nsub1f32((a)))
#define __alb_addsqrt3f32(a)                \
  (__builtin_riscv_addsqrt3f32((a)))
#define __alb_subsqrt3f32(a)                \
  (__builtin_riscv_subsqrt3f32((a)))
#define __alb_naddsqrt3f32(a)               \
  (__builtin_riscv_naddsqrt3f32((a)))
#define __alb_nsubsqrt3f32(a)               \
  (__builtin_riscv_nsubsqrt3f32((a)))
#define __alb_addpid3f32(a)                 \
  (__builtin_riscv_addpid3f32((a)))
#define __alb_subpid3f32(a)                 \
  (__builtin_riscv_subpid3f32((a)))
#define __alb_naddpid3f32(a)                \
  (__builtin_riscv_naddpid3f32((a)))
#define __alb_nsubpid3f32(a)                \
  (__builtin_riscv_nsubpid3f32((a)))
#define __alb_truncf32(a)                   \
  (__builtin_riscv_truncf32((a)))
#define __alb_fractf32(a)                   \
  (__builtin_riscv_fractf32((a)))
#define __alb_naddcstf32(a,b)               \
  (__builtin_riscv_naddcstf32((a),(b)))
#define __alb_nsubcstf32(a,b)               \
  (__builtin_riscv_nsubcstf32((a),(b)))
#define __alb_satf32(a,b,c)                 \
  (__satf32((a),(b),(c)))
#define __alb_fcsr_r()                      \
  (__builtin_riscv_fcsr_r())
#define __alb_icsr_r()                      \
  (__builtin_riscv_icsr_r())
#define __alb_crccr_r()                     \
  (__builtin_riscv_crccr_r())
#define __alb_crcrr_r()                     \
  (__builtin_riscv_crcrr_r())
#define __alb_crcsr_r()                     \
  (__builtin_riscv_crcsr_r())
#define __alb_crcpr_r()                     \
  (__builtin_riscv_crcpr_r())
#define __alb_fcsr_w(a)                     \
  (__builtin_riscv_fcsr_w((a)))
#define __alb_icsr_w(a)                     \
  (__builtin_riscv_icsr_w((a)))
#define __alb_crccr_w(a)                    \
  (__builtin_riscv_crccr_w((a)))
#define __alb_crcrr_w(a)                    \
  (__builtin_riscv_crcrr_w((a)))
#define __alb_crcsr_w(a)                    \
  (__builtin_riscv_crcsr_w((a)))
#define __alb_crcpr_w(a)                    \
  (__builtin_riscv_crcpr_w((a)))
#define __alb_crc8p1_byte(a)                \
  (__builtin_riscv_crc8p1_byte((a)))
#define __alb_crc16p1_byte(a)               \
  (__builtin_riscv_crc16p1_byte((a)))
#define __alb_crc16p2_byte(a)               \
  (__builtin_riscv_crc16p2_byte((a)))
#define __alb_crc24p1_byte(a)               \
  (__builtin_riscv_crc24p1_byte((a)))
#define __alb_crc32p1_byte(a)               \
  (__builtin_riscv_crc32p1_byte((a)))
#define __alb_crc32p2_byte(a)               \
  (__builtin_riscv_crc32p2_byte((a)))
#define __alb_vcrc(a)                       \
  (__builtin_riscv_vcrc((a)))
#define __alb_vitmovin32(a)             \
  (__builtin_riscv_vitmovin32((a)))
#define __alb_vitbm2(a,b)                 \
  (__builtin_riscv_vitbm2((a),(b)))
#define __alb_vitbm3(a,b)                 \
  (__builtin_riscv_vitbm3((a),(b)))
#define __alb_vittrace(a,b)               \
  (__builtin_riscv_vittrace((a),(b)))
#define __alb_vitclear1(a,b)              \
  (__builtin_riscv_vitclear1((a),(b)))
#define __alb_vitclear2(a,b)              \
  (__builtin_riscv_vitclear2((a),(b)))
#define __alb_vitclear4(a)              \
  (__builtin_riscv_vitclear4((a)))
#define __alb_vitcfg(a)                 \
  (__builtin_riscv_vitcfg((a)))
#define __alb_vitacs2(a,b)                \
  (__builtin_riscv_vitacs2((a),(b)))
#define __alb_vitacs4(a,b)                \
  (__builtin_riscv_vitacs4((a),(b)))
#define __alb_vitacsn(a,b)                \
  (__builtin_riscv_vitacsn((a),(b)))
#define __alb_vitmovout32_t1(a,b)         \
  (__builtin_riscv_vitmovout32_t1((a),(b)))
#define __alb_vitmovout32_t2(a,b)         \
  (__builtin_riscv_vitmovout32_t2((a),(b)))
#define __alb_vitmovin64_pair(a)        \
  (__builtin_riscv_vitmovin64_pair((a)))
#define __alb_vitmovout64(a,b,c)            \
  (__builtin_riscv_vitmovout64((a),(b),(c)))


//=================================================================================================
// OPTIMIZED FUNCTIONS
//=================================================================================================
typedef struct {
  float result1;
  float result2;
  float result3;
} ThreeFloats_T;




#ifdef __cplusplus
}
#endif

#endif /* end of __CORE_FEATURE_VCU__ */
