/** 
  *************************************************************************************
  * @file park.h 
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

#ifndef _PARK_H
#define _PARK_H

#include "math.h"
#include "core_feature_vcu.h"
#include "core_feature_tmu.h"

//
// Park Transformation Parameters
//
typedef struct
{
	float  ds;  		//!< Input: stationary d-axis stator variable */
	float  qs;		    //!< Input: stationary q-axis stator variable */
	float  ang;			//!< Input: rotating angle (pu) */
	float  de;			//!< Output: rotating d-axis stator variable */
	float  qe;			//!< Output: rotating q-axis stator variable */
} PARK;	

//
// Default initalizer for the PARK object.
//
#define PARK_DEFAULTS {   0, \
                          0, \
                          0, \
                          0, \
                          0, \
                      }

//
// Constants
//
#define TWO_PI_PARK    (6.28318530717959f)

//
// Park transform calculation
//

static inline void PARK_calc(PARK* v)
{
  float cos_ang, sin_ang;

  // Use zhanlu
#ifdef ZHANLU
  sin_ang = __alb_sinpuf32(v->ang);
  cos_ang = __alb_cospuf32(v->ang);
#else
  // Use Lib
  sin_ang = sinf(v->ang * TWO_PI_PARK);
  cos_ang = cosf(v->ang * TWO_PI_PARK);
#endif

  v->de = (v->ds)*(cos_ang) + (v->qs)*(sin_ang);
  v->qe = (v->qs)*(cos_ang) - (v->ds)*(sin_ang);
}

#endif //_PARK_H
