/** 
  *************************************************************************************
  * @file SPLL_1ph_SOGI_F.h 
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

#ifndef SPLL_1ph_SOGI_F_H
#define SPLL_1ph_SOGI_F_H

//*********** Structure Definition ********//
typedef struct{
	float32	osg_k;
	float32	osg_x;
	float32	osg_y;
	float32	osg_b0;
	float32	osg_b2;
	float32	osg_a1;
	float32	osg_a2;
	float32	osg_qb0;
	float32	osg_qb1;
	float32	osg_qb2;
}SPLL_1ph_SOGI_F_OSG_COEFF;

typedef struct{
	float32	B1_lf;
	float32	B0_lf;
	float32	A1_lf;
}SPLL_1ph_SOGI_F_LPF_COEFF;

typedef struct{
	float32	u[3];  // Ac Input
	float32   osg_u[3];
	float32   osg_qu[3];
	float32   u_Q[2];
	float32   u_D[2];
	float32   ylf[2];
	float32   fo; // output frequency of PLL
	float32   fn; //nominal frequency
	float32	theta[2];
	float32	cos;
	float32	sin;
	float32   delta_T;
	SPLL_1ph_SOGI_F_OSG_COEFF osg_coeff;
	SPLL_1ph_SOGI_F_LPF_COEFF lpf_coeff;
}SPLL_1ph_SOGI_F;

//*********** Function Declarations *******//
void SPLL_1ph_SOGI_F_init(int Grid_freq, float32 DELTA_T, SPLL_1ph_SOGI_F *spll);
void SPLL_1ph_SOGI_F_coeff_update(float32 delta_T, float32 wn, SPLL_1ph_SOGI_F *spll);
void SPLL_1ph_SOGI_F_FUNC(SPLL_1ph_SOGI_F *spll1);

//*********** Macro Definition ***********//
#define SPLL_1ph_SOGI_F_MACRO(v) 																																					\
	v.osg_u[0]=(v.osg_coeff.osg_b0*(v.u[0]-v.u[2])) + (v.osg_coeff.osg_a1*v.osg_u[1]) + (v.osg_coeff.osg_a2*v.osg_u[2]); 															\
	v.osg_u[2]=v.osg_u[1];																																							\
	v.osg_u[1]=v.osg_u[0];																																							\
	v.osg_qu[0]=(v.osg_coeff.osg_qb0*v.u[0]) + (v.osg_coeff.osg_qb1*v.u[1]) + (v.osg_coeff.osg_qb2*v.u[2]) + (v.osg_coeff.osg_a1*v.osg_qu[1]) + (v.osg_coeff.osg_a2*v.osg_qu[2]); 	\
	v.osg_qu[2]=v.osg_qu[1];																																						\
	v.osg_qu[1]=v.osg_qu[0];																																						\
	v.u[2]=v.u[1];																																									\
	v.u[1]=v.u[0];																																									\
	v.u_Q[0]=(v.cos*v.osg_u[0]) + (v.sin*v.osg_qu[0]);																																\
	v.u_D[0]=(v.cos*v.osg_qu[0]) - (v.sin*v.osg_u[0]);																																\
	v.ylf[0]=v.ylf[1] + (v.lpf_coeff.B0_lf*v.u_Q[0]) + (v.lpf_coeff.B1_lf*v.u_Q[1]);																								\
	v.ylf[1]=v.ylf[0];																																								\
	v.u_Q[1]=v.u_Q[0];																																								\
	v.fo=v.fn + v.ylf[0]; 																																							\
	v.theta[0]=v.theta[1] + ((v.fo*v.delta_T)*(float32)(2.0*3.1415926)); 																												\
	if(v.theta[0]>(float32)(2.0*3.1415926)) 																																			\
		v.theta[0]=(float32)(0.0); 																																					\
	v.theta[1]=v.theta[0]; 																																							\
	v.sin=(float32)(sin(v.theta[0])); 																																				\
	v.cos=(float32)(cos(v.theta[0]));


#endif /* SPLL_1ph_SOGI_F_H_ */
