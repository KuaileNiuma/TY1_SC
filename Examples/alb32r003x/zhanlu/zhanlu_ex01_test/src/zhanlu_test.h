/**
 *************************************************************************************
 * @file zhanlu_test.h
 * @brief This file contains the header file for example zhanlu_test.
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

#ifndef  __ZHANLU_TEST_H_
#define  __ZHANLU_TEST_H_

int test_crc(void);
int test_sqrtf32(void);
int test_sinpuf32(void);
int test_cospuf32(void);
int test_atanpuf32(void);
int test_expf32(void);
int test_aexpf32(void);
int test_nexpf32(void);
int test_iexpf32(void);
int test_log2f32(void);
int test_divf32(void);

int test_quadf32(void);
int test_sumsqf32(void);

int test_mpy2pif32(void);
int test_div2pif32(void);
int test_nmpy2pif32(void);
int test_ndiv2pif32(void);
int test_mpy2f32(void);
int test_mpy2div3f32(void);
int test_div2f32(void);
int test_div3f32(void);
int test_div4f32(void);
int test_mpysqrt3f32(void);
int test_mpysqrt3div2f32(void);
int test_mpysqrt3div6f32(void);
int test_divsqrt3f32(void);
int test_mpy2divsqrt3f32(void);
int test_mpylog2ef32(void);
int test_nmpylog2ef32(void);
int test_add1f32(void);
int test_sub1f32(void);
int test_nadd1f32(void);
int test_nsub1f32(void);
int test_addsqrt3f32(void);
int test_subsqrt3f32(void);
int test_naddsqrt3f32(void);
int test_nsubsqrt3f32(void);
int test_addpid3f32(void);
int test_subpid3f32(void);
int test_naddpid3f32(void);
int test_nsubpid3f32(void);
int test_truncf32(void);
int test_fractf32(void);
int test_naddcstf32(void);
int test_nsubcstf32(void);
int test_satf32(void);

void zhanlu_test(void);
#endif

