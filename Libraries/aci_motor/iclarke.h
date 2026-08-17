/** 
  *************************************************************************************
  * @file iclarke.h 
  * @author Albatross 
  * @brief This file contains the header file. 
  * @version 1.0.0 
  * @date 2025-07-30 
  *************************************************************************************
  * @copyright Copyright (c) 2025 Albatross  Semiconductor( Hangzhou ) Co ., Ltd . 
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

#ifndef _ICLARKE_H
#define _ICLARKE_H

#include "math.h"
#include "core_feature_vcu.h"
#include "core_feature_tmu.h"

//
// Clarke Transform Parameters for 3 phase stator current
//
typedef struct
{  
    float  Alpha;       //!< Input: stationary d-axis stator variable
    float  Beta;        //!< Input: stationary q-axis stator variable
    float  As;          //!< Output: phase-a stator variable
    float  Bs;          //!< Output: phase-b stator variable
    float  Cs;          //!< Output: phase-c stator variable
} ICLARKE;

//
//    Default initalizer for the CLARKE object.
//
#define ICLARKE_DEFAULTS {  0, \
                            0, \
                            0, \
                            0, \
                            0 }

//
// Constant
//
#define SQRT3 (1.732050808f)

//
// Inverse Clarke transformation calculation
//
static inline void IClarke_calc(ICLARKE* v)
{
    v->As = v->Alpha;
#ifdef ZHANLU
    v->Bs = __alb_div2f32(-v->Alpha);
    v->Bs += __alb_mpysqrt3div2f32(v->Beta);
    v->Cs = __alb_div2f32(-v->Alpha);
    v->Cs -= __alb_mpysqrt3div2f32(v->Beta);
#else
    v->Bs = ((-v->Alpha + (v->Beta)*(SQRT3)))*(0.5f);
    v->Cs = ((-v->Alpha - (v->Beta)*(SQRT3)))*(0.5f);
#endif

}

#endif // _ICLARKE_H

