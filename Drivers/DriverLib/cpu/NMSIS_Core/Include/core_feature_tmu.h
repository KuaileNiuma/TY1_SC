/**
 *************************************************************************************
 * @file core_feature_tmu.h
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

#ifndef __CORE_FEATURE_TMU__
#define __CORE_FEATURE_TMU__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>



// zhanlu
#define __alb_sqrtf32(a)                    \
  (__builtin_riscv_sqrtf32((a)))
#define __alb_sinpuf32(a)                   \
  (__builtin_riscv_sinpuf32((a)))
#define __alb_cospuf32(a)                   \
  (__builtin_riscv_cospuf32((a)))
#define __alb_atanpuf32(a)                  \
  (__builtin_riscv_atanpuf32((a)))
#define __alb_expf32(a)                     \
  (__builtin_riscv_expf32((a)))
#define __alb_aexpf32(a)                    \
  (__builtin_riscv_aexpf32((a)))
#define __alb_nexpf32(a)                    \
  (__builtin_riscv_nexpf32((a)))
#define __alb_iexpf32(a)                    \
  (__builtin_riscv_iexpf32((a)))
#define __alb_log2f32(a)                    \
  (__builtin_riscv_log2f32((a)))
#define __alb_divf32(a,b)                   \
  (__builtin_riscv_divf32((a),(b)))
#define __alb_atan2divf32(a,b)              \
  (__builtin_riscv_atan2divf32((a),(b)))
#define __alb_atan2quadf32(a,b)             \
  (__builtin_riscv_atan2quadf32((a),(b)))
#define __alb_sumsqf32(a,b)                 \
  (__builtin_riscv_sumsqf32((a),(b)))




#ifdef __cplusplus
}
#endif

#endif /* end of __CORE_FEATURE_TMU__ */
