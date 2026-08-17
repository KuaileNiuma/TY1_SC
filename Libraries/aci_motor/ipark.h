/** 
  *************************************************************************************
  * @file ipark.h 
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

#ifndef _IPARK_H
#define _IPARK_H

#include "math.h"

//
// Inverse Park Transformation Parameters
//
typedef struct
{  
	float  ds; 	 	 //!<Output: stationary d-axis stator variable
	float  qs;		 //!<Output: stationary q-axis stator variable
	float  ang;		 //!<Input: rotating angle (pu)
	float  de;		 //!<Input: rotating d-axis stator variable
	float  qe;		 //!<Input: rotating q-axis stator variable
} IPARK;

//
// Default initalizer for the IPARK object.
//
#define IPARK_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          0, \
					   }

//
// Constants
//
#define TWO_PI (6.28318530717959f)

//
// Inverse Park transform calculation
//

static inline void IPARK_calc(IPARK *v)
{	
    float cos_ang, sin_ang;

#ifdef ZHANLU
    sin_ang = __alb_sinpuf32(v->ang);
    cos_ang = __alb_cospuf32(v->ang);
#else
    sin_ang = sinf(v->ang * TWO_PI);
    cos_ang = cosf(v->ang * TWO_PI);
#endif
    v->ds = (v->de)*(cos_ang) - (v->qe)*(sin_ang);
    v->qs = (v->qe)*(cos_ang) + (v->de)*(sin_ang);
}

#endif //_IPARK_H
