/** 
  *************************************************************************************
  * @file SPLL_3ph_DDSRF_IQ.h 
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

#ifndef SPLL_3ph_DDSRF_IQ_H_
#define SPLL_3ph_DDSRF_IQ_H_

#define SPLL_DDSRF_Q _IQ22
#define SPLL_DDSRF_Qmpy _IQ22mpy

//*********** Structure Definition ********//
typedef struct{
	int32	B1_lf;
	int32	B0_lf;
	int32	A1_lf;
}SPLL_3ph_DDSRF_IQ_LPF_COEFF;

typedef struct{
	int32 d_p;
	int32 d_n;
	int32 q_p;
	int32 q_n;

	int32 d_p_decoupl;
	int32 d_n_decoupl;
	int32 q_p_decoupl;
	int32 q_n_decoupl;

	int32 cos_2theta;
	int32 sin_2theta;

	int32 y[2];
	int32 x[2];
	int32 w[2];
	int32 z[2];
	int32 k1;
	int32 k2;
	int32 d_p_decoupl_lpf;
	int32 d_n_decoupl_lpf;
	int32 q_p_decoupl_lpf;
	int32 q_n_decoupl_lpf;

	int32 v_q[2];
	int32 theta[2];
	int32 ylf[2];
	int32 fo;
	int32 fn;
	int32 delta_T;
	SPLL_3ph_DDSRF_IQ_LPF_COEFF lpf_coeff;
}SPLL_3ph_DDSRF_IQ;

//*********** Function Declarations *******//
void SPLL_3ph_DDSRF_IQ_init(int Grid_freq, long DELTA_T, long k1, long k2, SPLL_3ph_DDSRF_IQ *spll);
void SPLL_3ph_DDSRF_IQ_FUNC(SPLL_3ph_DDSRF_IQ *spll_obj);

//*********** Macro Definition ***********//
#define SPLL_3ph_DDSRF_IQ_MACRO(spll_obj)																															\
	spll_obj.d_p_decoupl=spll_obj.d_p - SPLL_DDSRF_Qmpy(spll_obj.d_n_decoupl_lpf,spll_obj.cos_2theta) - SPLL_DDSRF_Qmpy(spll_obj.q_n_decoupl,spll_obj.sin_2theta);	\
	spll_obj.q_p_decoupl=spll_obj.q_p + SPLL_DDSRF_Qmpy(spll_obj.d_n_decoupl_lpf,spll_obj.sin_2theta) - SPLL_DDSRF_Qmpy(spll_obj.q_n_decoupl,spll_obj.cos_2theta);	\
	spll_obj.d_n_decoupl=spll_obj.d_n - SPLL_DDSRF_Qmpy(spll_obj.d_p_decoupl_lpf,spll_obj.cos_2theta) + SPLL_DDSRF_Qmpy(spll_obj.q_p_decoupl,spll_obj.sin_2theta);	\
	spll_obj.q_n_decoupl=spll_obj.q_n - SPLL_DDSRF_Qmpy(spll_obj.d_p_decoupl_lpf,spll_obj.sin_2theta) - SPLL_DDSRF_Qmpy(spll_obj.q_p_decoupl,spll_obj.cos_2theta);	\
	spll_obj.y[1]=SPLL_DDSRF_Qmpy(spll_obj.d_p_decoupl,spll_obj.k1)-SPLL_DDSRF_Qmpy(spll_obj.y[0],spll_obj.k2);														\
	spll_obj.d_p_decoupl_lpf=spll_obj.y[1]+spll_obj.y[0];																											\
	spll_obj.y[0]=spll_obj.y[1];																																	\
	spll_obj.x[1]=SPLL_DDSRF_Qmpy(spll_obj.q_p_decoupl,spll_obj.k1)-SPLL_DDSRF_Qmpy(spll_obj.x[0],spll_obj.k2);														\
	spll_obj.q_p_decoupl_lpf=spll_obj.x[1]+spll_obj.x[0];																											\
	spll_obj.x[0]=spll_obj.x[1];																																	\
	spll_obj.w[1]=SPLL_DDSRF_Qmpy(spll_obj.d_n_decoupl,spll_obj.k1)-SPLL_DDSRF_Qmpy(spll_obj.w[0],spll_obj.k2);														\
	spll_obj.d_n_decoupl_lpf=spll_obj.w[1]+spll_obj.w[0];																											\
	spll_obj.w[0]=spll_obj.w[1];																																	\
	spll_obj.z[1]=SPLL_DDSRF_Qmpy(spll_obj.q_n_decoupl,spll_obj.k1)-SPLL_DDSRF_Qmpy(spll_obj.z[0],spll_obj.k2);														\
	spll_obj.q_n_decoupl_lpf=spll_obj.z[1]+spll_obj.z[0];																											\
	spll_obj.z[0]=spll_obj.z[1];																																	\
	spll_obj.v_q[0]=spll_obj.q_p_decoupl;																															\
	spll_obj.ylf[0]=spll_obj.ylf[1]+SPLL_DDSRF_Qmpy(spll_obj.lpf_coeff.B0_lf,spll_obj.v_q[0])+SPLL_DDSRF_Qmpy(spll_obj.lpf_coeff.B1_lf,spll_obj.v_q[1]);			\
	spll_obj.ylf[1]=spll_obj.ylf[0];																																\
	spll_obj.v_q[1]=spll_obj.v_q[0];																																\
	spll_obj.fo=spll_obj.fn+spll_obj.ylf[0];																														\
	spll_obj.theta[0]=spll_obj.theta[1]+SPLL_DDSRF_Qmpy(SPLL_DDSRF_Qmpy(spll_obj.fo,spll_obj.delta_T),SPLL_DDSRF_Q(2*3.1415926));									\
	if(spll_obj.theta[0]>SPLL_DDSRF_Q(2*3.1415926))																													\
		spll_obj.theta[0]=spll_obj.theta[0]-SPLL_DDSRF_Q(2*3.1415926);																								\
	spll_obj.theta[1]=spll_obj.theta[0];																															\


#endif /* SPLL_3ph_DDSRF_IQ_H_ */
