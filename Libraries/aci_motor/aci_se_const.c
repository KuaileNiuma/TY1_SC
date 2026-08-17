/** 
  *************************************************************************************
  * @file aci_se_const.c 
  * @author Albatross 
  * @brief This file contains the source file. 
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

//
// Included Files
//
#include "../aci_motor/aci_se_const.h"

#include "math.h"
#include "core_feature_vcu.h"
#include "core_feature_tmu.h"

#define PI 3.14159265358979f

//
// Calculate Speed Estimator(FE) output constants
//
void ACISE_Const_calc(ACISE_Const *v) {
	float Wb, Tr, tc;

#ifdef ZHANLU
	//
	// Rotor time constant (sec)
	//
	Tr = __alb_divf32(v->Lr, v->Rr);

	//
	// Lowpass filter time constant (sec)
	//
	tc = __alb_divf32(1.0f, __alb_mpy2pif32(v->fc));
	Wb = __alb_mpy2pif32(v->fb);

	v->K1 = __alb_divf32(1.0f, (Wb * Tr));
	v->K2 = __alb_divf32(1.0f, (v->fb * v->Ts));
	v->K3 = __alb_divf32(tc, (tc + v->Ts));
	v->K4 = __alb_divf32(v->Ts, (tc + v->Ts));
#else
	//
	// Rotor time constant (sec)
	//
	Tr = v->Lr / v->Rr;

	//
	// Lowpass filter time constant (sec)
	//
	tc = 1.0f / (2.0f * PI * v->fc);
	Wb = 2.0f * PI * v->fb;

	v->K1 = 1.0f / (Wb * Tr);
	v->K2 = 1.0f / (v->fb * v->Ts);
	v->K3 = tc / (tc + v->Ts);
	v->K4 = v->Ts / (tc + v->Ts);
#endif
}
