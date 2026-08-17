/** 
  *************************************************************************************
  * @file SPLL_1ph_SOGI_IQ.h 
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

#ifndef SPLL_1ph_SOGI_IQ_H_
#define SPLL_1ph_SOGI_IQ_H_

#define SPLL_SOGI_Q _IQ23
#define SPLL_SOGI_Qmpy _IQ23mpy
#define SPLL_SOGI_SINE _IQ23sin
#define SPLL_SOGI_COS  _IQ23cos

//*********** Structure Definition ********//
typedef struct{
	int32	osg_k;
	int32	osg_x;
	int32	osg_y;
	int32	osg_b0;
	int32	osg_b2;
	int32	osg_a1;
	int32	osg_a2;
	int32	osg_qb0;
	int32	osg_qb1;
	int32	osg_qb2;
}SPLL_1ph_SOGI_IQ_OSG_COEFF;

typedef struct{
	int32	B1_lf;
	int32	B0_lf;
	int32	A1_lf;
}SPLL_1ph_SOGI_IQ_LPF_COEFF;

typedef struct{
	int32	u[3];  // Ac Input
	int32   osg_u[3]; 
	int32   osg_qu[3];
	int32   u_Q[2];
	int32   u_D[2];
	int32   ylf[2];
	int32   fo; // output frequency of PLL
	int32   fn; //nominal frequency
	int32	theta[2];
	int32	cos;
	int32	sin;
	int32   delta_T;
	SPLL_1ph_SOGI_IQ_OSG_COEFF osg_coeff;
	SPLL_1ph_SOGI_IQ_LPF_COEFF lpf_coeff;
}SPLL_1ph_SOGI_IQ;

//*********** Function Declarations *******//
void SPLL_1ph_SOGI_IQ_init(int Grid_freq, long DELTA_T, SPLL_1ph_SOGI_IQ *spll);
void SPLL_1ph_SOGI_IQ_coeff_update(float delta_T, float wn, SPLL_1ph_SOGI_IQ *spll);
void SPLL_1ph_SOGI_IQ_FUNC(SPLL_1ph_SOGI_IQ *spll1);

//*********** Macro Definition ***********//
#define SPLL_1ph_SOGI_IQ_MACRO(v) 																																																				\
	v.osg_u[0]=SPLL_SOGI_Qmpy(v.osg_coeff.osg_b0,(v.u[0]-v.u[2]))+SPLL_SOGI_Qmpy(v.osg_coeff.osg_a1,v.osg_u[1])+SPLL_SOGI_Qmpy(v.osg_coeff.osg_a2,v.osg_u[2]); 																					\
	v.osg_u[2]=v.osg_u[1];																																																						\
	v.osg_u[1]=v.osg_u[0];																																																						\
	v.osg_qu[0]=SPLL_SOGI_Qmpy(v.osg_coeff.osg_qb0,v.u[0])+SPLL_SOGI_Qmpy(v.osg_coeff.osg_qb1,v.u[1])+SPLL_SOGI_Qmpy(v.osg_coeff.osg_qb2,v.u[2])+SPLL_SOGI_Qmpy(v.osg_coeff.osg_a1,v.osg_qu[1])+SPLL_SOGI_Qmpy(v.osg_coeff.osg_a2,v.osg_qu[2]); \
	v.osg_qu[2]=v.osg_qu[1];																																																					\
	v.osg_qu[1]=v.osg_qu[0];																																																					\
	v.u[2]=v.u[1];																																																								\
	v.u[1]=v.u[0];																																																								\
	v.u_Q[0]=SPLL_SOGI_Qmpy(v.cos,v.osg_u[0])+SPLL_SOGI_Qmpy(v.sin,v.osg_qu[0]);																																								\
	v.u_D[0]=SPLL_SOGI_Qmpy(v.cos,v.osg_qu[0])-SPLL_SOGI_Qmpy(v.sin,v.osg_u[0]);																																								\
	v.ylf[0]=v.ylf[1]+SPLL_SOGI_Qmpy(v.lpf_coeff.B0_lf,v.u_Q[0])+SPLL_SOGI_Qmpy(v.lpf_coeff.B1_lf,v.u_Q[1]);																																	\
	v.ylf[1]=v.ylf[0];																																																							\
	v.u_Q[1]=v.u_Q[0];																																																							\
	v.fo=v.fn+v.ylf[0]; 																																																						\
	v.theta[0]=v.theta[1]+SPLL_SOGI_Qmpy(SPLL_SOGI_Qmpy(v.fo,v.delta_T),SPLL_SOGI_Qmpy(SPLL_SOGI_Q(2.0),SPLL_SOGI_Q(3.1415926))); 																																				\
	if(v.theta[0]>SPLL_SOGI_Qmpy(SPLL_SOGI_Q(2.0),SPLL_SOGI_Q(3.1415926))) 																																																	\
		v.theta[0]=SPLL_SOGI_Q(0.0); 																																																			\
	v.theta[1]=v.theta[0]; 																																																						\
	v.sin=SPLL_SOGI_SINE(v.theta[0]); 																																																			\
	v.cos=SPLL_SOGI_COS(v.theta[0]);


#endif /* SPLL_1ph_SOGI_IQ_H_ */
