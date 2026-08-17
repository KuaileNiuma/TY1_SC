/** 
  *************************************************************************************
  * @file clarke.h 
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

#ifndef _CLARKE_H
#define _CLARKE_H

#include "math.h"
#include "core_feature_vcu.h"
#include "core_feature_tmu.h"


//
// Clarke Transform Parameters for 3 phase stator current
//
typedef struct
{  
    float  As;          //!< Input: phase-a stator variable
    float  Bs;          //!< Input: phase-b stator variable
    float  Cs;          //!< Input: phase-c stator variable
    float  Alpha;       //!< Output: stationary d-axis stator variable
    float  Beta;        //!< Output: stationary q-axis stator variable
} CLARKE;


//
// Default initalizer for the CLARKE object.
//
#define CLARKE_DEFAULTS { 0, \
                          0, \
                          0, \
                          0, \
                          0  }

//
// Constant
//

//
// 1/sqrt(3) = 0.57735026918963
//
#define INVSQRT3 (0.57735026918963f)


//
// Clarke transformation calculation
//
static inline void Clarke_calc(CLARKE* v)
{
    v->Alpha = v->As;
#ifdef ZHANLU
    v->Beta = __alb_mpy2divsqrt3f32(v->Bs);
	v->Beta	+= __alb_divsqrt3f32(v->As);
#else
    v->Beta = ((v->As +(v->Bs)*(2.0f)))*((INVSQRT3));
#endif



}

#endif // _CLARKE_H

