/** 
  *************************************************************************************
  * @file aci_const.c 
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
#include "../aci_motor/aci_const.h"

#include "math.h"
#include "core_feature_vcu.h"
#include "core_feature_tmu.h"

//
// Calculate the ACI motor output constants
//
void ACI_Const_calc(ACI_Const *v) {
	float sigma, gamma, alpha, beta;

#ifdef ZHANLU
	sigma = __alb_nadd1f32(__alb_divf32((v->Lm*v->Lm),(v->Ls*v->Lr)));
	gamma = __alb_divf32((v->Lm*v->Lm*v->Rr + v->Lr*v->Lr*v->Rs),(sigma*v->Ls*v->Lr*v->Lr));
	alpha = __alb_divf32(v->Rr,v->Lr);
	beta = __alb_divf32(v->Lm,(sigma*v->Ls*v->Lr));

	v->K1 = v->Ts * alpha;
	v->K2 = v->Ts * v->Wb;
	v->K3 = v->Ts * alpha * v->Lm * __alb_divf32(v->Ib,v->Lb);
	v->K4 = v->Ts * alpha * beta * __alb_divf32(v->Lb , v->Ib);
	v->K5 = v->Ts * beta * (v->Lb * __alb_divf32(v->Wb , v->Ib));
	v->K6 = v->Ts * gamma;
	v->K7 = v->Ts * __alb_divf32(1.0f,(sigma * v->Ls)) * __alb_divf32(v->Vb, v->Ib);
	v->K8 = 1.5f * __alb_divf32(v->p , 2.0f) * __alb_divf32(v->Lm , v->Lr) * __alb_divf32((v->Lb * v->Ib), v->Tb);
	v->K9 = v->Ts * __alb_divf32(v->B , v->J);
	v->K10 = v->Ts * __alb_divf32(v->p , 2.0f) * __alb_divf32(1.0f , v->J) * __alb_divf32(v->Tb , v->Wb);

#else
	sigma = 1.0f - (v->Lm * v->Lm) / (v->Ls * v->Lr);
	gamma = (v->Lm * v->Lm * v->Rr + v->Lr * v->Lr * v->Rs)
			/ (sigma * v->Ls * v->Lr * v->Lr);
	alpha = v->Rr / v->Lr;
	beta = v->Lm / (sigma * v->Ls * v->Lr);
	
	v->K1 = v->Ts * alpha;
	v->K2 = v->Ts * v->Wb;
	v->K3 = v->Ts * alpha * v->Lm * (v->Ib / v->Lb);
	v->K4 = v->Ts * alpha * beta * (v->Lb / v->Ib);
	v->K5 = v->Ts * beta * (v->Lb * v->Wb / v->Ib);
	v->K6 = v->Ts * gamma;
	v->K7 = v->Ts * (1 / (sigma * v->Ls)) * (v->Vb / v->Ib);
	v->K8 = 1.5f * (v->p / 2.0f) * (v->Lm / v->Lr) * (v->Lb * v->Ib / v->Tb);
	v->K9 = v->Ts * (v->B / v->J);
	v->K10 = v->Ts * (v->p / 2.0f) * (1.0f / v->J) * (v->Tb / v->Wb);
	
#endif
}

//
// End of File
//
