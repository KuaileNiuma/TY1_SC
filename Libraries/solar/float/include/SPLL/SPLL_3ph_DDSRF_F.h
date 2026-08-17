/** 
  *************************************************************************************
  * @file SPLL_3ph_DDSRF_F.h 
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

#ifndef SPLL_3ph_DDSRF_F_H_
#define SPLL_3ph_DDSRF_F_H_

//*********** Structure Definition ********//
typedef struct{
	float32	B1_lf;
	float32	B0_lf;
	float32	A1_lf;
}SPLL_3ph_DDSRF_F_LPF_COEFF;

typedef struct{
	float32 d_p;
	float32 d_n;
	float32 q_p;
	float32 q_n;

	float32 d_p_decoupl;
	float32 d_n_decoupl;
	float32 q_p_decoupl;
	float32 q_n_decoupl;

	float32 cos_2theta;
	float32 sin_2theta;

	float32 y[2];
	float32 x[2];
	float32 w[2];
	float32 z[2];
	float32 k1;
	float32 k2;
	float32 d_p_decoupl_lpf;
	float32 d_n_decoupl_lpf;
	float32 q_p_decoupl_lpf;
	float32 q_n_decoupl_lpf;

	float32 v_q[2];
	float32 theta[2];
	float32 ylf[2];
	float32 fo;
	float32 fn;
	float32 delta_T;
	SPLL_3ph_DDSRF_F_LPF_COEFF lpf_coeff;
}SPLL_3ph_DDSRF_F;

//*********** Function Declarations *******//
void SPLL_3ph_DDSRF_F_init(int Grid_freq, float32 DELTA_T, float32 k1, float32 k2, SPLL_3ph_DDSRF_F *spll);
void SPLL_3ph_DDSRF_F_FUNC(SPLL_3ph_DDSRF_F *spll_obj);

//*********** Macro Definition ***********//
#define SPLL_3ph_DDSRF_F_MACRO(spll_obj)																								\
	spll_obj.d_p_decoupl=spll_obj.d_p - (spll_obj.d_n_decoupl_lpf*spll_obj.cos_2theta) - (spll_obj.q_n_decoupl*spll_obj.sin_2theta);	\
	spll_obj.q_p_decoupl=spll_obj.q_p + (spll_obj.d_n_decoupl_lpf*spll_obj.sin_2theta) - (spll_obj.q_n_decoupl*spll_obj.cos_2theta);	\
	spll_obj.d_n_decoupl=spll_obj.d_n - (spll_obj.d_p_decoupl_lpf*spll_obj.cos_2theta) + (spll_obj.q_p_decoupl*spll_obj.sin_2theta);	\
	spll_obj.q_n_decoupl=spll_obj.q_n - (spll_obj.d_p_decoupl_lpf*spll_obj.sin_2theta) - (spll_obj.q_p_decoupl*spll_obj.cos_2theta);	\
	spll_obj.y[1]=(spll_obj.d_p_decoupl*spll_obj.k1) - (spll_obj.y[0]*spll_obj.k2);														\
	spll_obj.d_p_decoupl_lpf=spll_obj.y[1] + spll_obj.y[0];																				\
	spll_obj.y[0]=spll_obj.y[1];																										\
	spll_obj.x[1]=(spll_obj.q_p_decoupl*spll_obj.k1) - (spll_obj.x[0]*spll_obj.k2);														\
	spll_obj.q_p_decoupl_lpf=spll_obj.x[1] + spll_obj.x[0];																				\
	spll_obj.x[0]=spll_obj.x[1];																										\
	spll_obj.w[1]=(spll_obj.d_n_decoupl*spll_obj.k1) - (spll_obj.w[0]*spll_obj.k2);														\
	spll_obj.d_n_decoupl_lpf=spll_obj.w[1] + spll_obj.w[0];																				\
	spll_obj.w[0]=spll_obj.w[1];																										\
	spll_obj.z[1]=(spll_obj.q_n_decoupl*spll_obj.k1) - (spll_obj.z[0]*spll_obj.k2);														\
	spll_obj.q_n_decoupl_lpf=spll_obj.z[1] + spll_obj.z[0];																				\
	spll_obj.z[0]=spll_obj.z[1];																										\
	spll_obj.v_q[0]=spll_obj.q_p_decoupl;																								\
	spll_obj.ylf[0]=spll_obj.ylf[1] + (spll_obj.lpf_coeff.B0_lf*spll_obj.v_q[0]) + (spll_obj.lpf_coeff.B1_lf*spll_obj.v_q[1]);			\
	spll_obj.ylf[1]=spll_obj.ylf[0];																									\
	spll_obj.v_q[1]=spll_obj.v_q[0];																									\
	spll_obj.fo=spll_obj.fn+spll_obj.ylf[0];																							\
	spll_obj.theta[0]=spll_obj.theta[1] + ((spll_obj.fo*spll_obj.delta_T)*(float32)(2*3.1415926));										\
	if(spll_obj.theta[0]>(float32)(2*3.1415926))																							\
		spll_obj.theta[0]=spll_obj.theta[0] - (float32)(2*3.1415926);																		\
	spll_obj.theta[1]=spll_obj.theta[0];																								\


#endif /* SPLL_3ph_DDSRF_F_H_ */
