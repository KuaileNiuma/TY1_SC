/** 
  *************************************************************************************
  * @file SPLL_1ph_SOGI_IQ.c 
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

#include "Solar_IQ.h"

//*********** Structure Init Function ****//
void SPLL_1ph_SOGI_IQ_init(int Grid_freq, long DELTA_T, SPLL_1ph_SOGI_IQ *spll_obj)
{
	spll_obj->u[0]=SPLL_SOGI_Q(0.0);
	spll_obj->u[1]=SPLL_SOGI_Q(0.0);
	spll_obj->u[2]=SPLL_SOGI_Q(0.0);
	
	spll_obj->osg_u[0]=SPLL_SOGI_Q(0.0);
	spll_obj->osg_u[1]=SPLL_SOGI_Q(0.0);
	spll_obj->osg_u[2]=SPLL_SOGI_Q(0.0);
	
	spll_obj->osg_qu[0]=SPLL_SOGI_Q(0.0);
	spll_obj->osg_qu[1]=SPLL_SOGI_Q(0.0);
	spll_obj->osg_qu[2]=SPLL_SOGI_Q(0.0);
	
	spll_obj->u_Q[0]=SPLL_SOGI_Q(0.0);
	spll_obj->u_Q[1]=SPLL_SOGI_Q(0.0);
	
	spll_obj->u_D[0]=SPLL_SOGI_Q(0.0);
	spll_obj->u_D[1]=SPLL_SOGI_Q(0.0);
	
	spll_obj->ylf[0]=SPLL_SOGI_Q(0.0);
	spll_obj->ylf[1]=SPLL_SOGI_Q(0.0);
	
	spll_obj->fo=SPLL_SOGI_Q(0.0);
	spll_obj->fn=SPLL_SOGI_Q(Grid_freq);
	
	spll_obj->theta[0]=SPLL_SOGI_Q(0.0);
	spll_obj->theta[1]=SPLL_SOGI_Q(0.0);
	
	spll_obj->sin=SPLL_SOGI_Q(0.0);
	spll_obj->cos=SPLL_SOGI_Q(0.0);

	// loop filter coefficients for 20kHz
	spll_obj->lpf_coeff.B0_lf=SPLL_SOGI_Q(166.9743);
	spll_obj->lpf_coeff.B1_lf=SPLL_SOGI_Q(-166.266);
	spll_obj->lpf_coeff.A1_lf=SPLL_SOGI_Q(-1.0);
	
	spll_obj->delta_T=DELTA_T;
}

//*********** Structure Coeff Update *****//
void SPLL_1ph_SOGI_IQ_coeff_update(float delta_T, float wn, SPLL_1ph_SOGI_IQ *spll)
{
	float osgx,osgy,temp;
	spll->osg_coeff.osg_k=SPLL_SOGI_Q(0.5);
	osgx=(float)(2.0*0.5*wn*delta_T);
	spll->osg_coeff.osg_x=SPLL_SOGI_Q(osgx);
	osgy=(float)(wn*delta_T*wn*delta_T);
	spll->osg_coeff.osg_y=SPLL_SOGI_Q(osgy);
	temp=(float)1.0/(osgx+osgy+4.0);
	spll->osg_coeff.osg_b0=SPLL_SOGI_Q((float)osgx*temp);
	spll->osg_coeff.osg_b2=SPLL_SOGI_Qmpy(SPLL_SOGI_Q(-1.0),spll->osg_coeff.osg_b0);
	spll->osg_coeff.osg_a1=SPLL_SOGI_Q((float)(2.0*(4.0-osgy))*temp);
	spll->osg_coeff.osg_a2=SPLL_SOGI_Q((float)(osgx-osgy-4)*temp);
	spll->osg_coeff.osg_qb0=SPLL_SOGI_Q((float)(0.5*osgy)*temp);
	spll->osg_coeff.osg_qb1=SPLL_SOGI_Qmpy(spll->osg_coeff.osg_qb0,SPLL_SOGI_Q(2.0));
	spll->osg_coeff.osg_qb2=spll->osg_coeff.osg_qb0;
}

//*********** Function Definition ********//
void SPLL_1ph_SOGI_IQ_FUNC(SPLL_1ph_SOGI_IQ *spll_obj)
{
	// Update the spll_obj->u[0] with the grid value before calling this routine

	//-------------------------------//
	// Orthogonal Signal Generator 	 //
	//-------------------------------//
	spll_obj->osg_u[0]=SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_b0,(spll_obj->u[0]-spll_obj->u[2]))+SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_a1,spll_obj->osg_u[1])+SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_a2,spll_obj->osg_u[2]);

	spll_obj->osg_u[2]=spll_obj->osg_u[1];
	spll_obj->osg_u[1]=spll_obj->osg_u[0];

	spll_obj->osg_qu[0]=SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_qb0,spll_obj->u[0])+SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_qb1,spll_obj->u[1])+SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_qb2,spll_obj->u[2])+SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_a1,spll_obj->osg_qu[1])+SPLL_SOGI_Qmpy(spll_obj->osg_coeff.osg_a2,spll_obj->osg_qu[2]);

	spll_obj->osg_qu[2]=spll_obj->osg_qu[1];
	spll_obj->osg_qu[1]=spll_obj->osg_qu[0];

	spll_obj->u[2]=spll_obj->u[1];
	spll_obj->u[1]=spll_obj->u[0];
	
	//-------------------------------------------------------//
	// Park Transform from alpha beta to d-q axis 			 //
	//-------------------------------------------------------//
	spll_obj->u_Q[0]=SPLL_SOGI_Qmpy(spll_obj->cos,spll_obj->osg_u[0])+SPLL_SOGI_Qmpy(spll_obj->sin,spll_obj->osg_qu[0]);
	spll_obj->u_D[0]=SPLL_SOGI_Qmpy(spll_obj->cos,spll_obj->osg_qu[0])-SPLL_SOGI_Qmpy(spll_obj->sin,spll_obj->osg_u[0]);

	//---------------------------------//
	// Loop Filter                     //
	//---------------------------------//
	spll_obj->ylf[0]=spll_obj->ylf[1]+SPLL_SOGI_Qmpy(spll_obj->lpf_coeff.B0_lf,spll_obj->u_Q[0])+SPLL_SOGI_Qmpy(spll_obj->lpf_coeff.B1_lf,spll_obj->u_Q[1]);
	//spll_obj->ylf[0]=(spll_obj->ylf[0]>SPLL_SOGI_Q(20.0))?SPLL_SOGI_Q(20.0):spll_obj->ylf[0];
	//spll_obj->ylf[0]=(spll_obj->ylf[0]<SPLL_SOGI_Q(-20.0))?SPLL_SOGI_Q(-20.0):spll_obj->ylf[0];
	spll_obj->ylf[1]=spll_obj->ylf[0];

	spll_obj->u_Q[1]=spll_obj->u_Q[0];
	//spll_obj->u_D[1]=spll_obj->u_D[0];

	//---------------------------------//
	// VCO                             //
	//---------------------------------//
	spll_obj->fo=spll_obj->fn+spll_obj->ylf[0];
	
	spll_obj->theta[0]=spll_obj->theta[1]+SPLL_SOGI_Qmpy(SPLL_SOGI_Qmpy(spll_obj->fo,spll_obj->delta_T),SPLL_SOGI_Qmpy(SPLL_SOGI_Q(2.0),SPLL_SOGI_Q(3.1415926)));
	if(spll_obj->theta[0]>SPLL_SOGI_Q(2*3.1415926))
		spll_obj->theta[0]=SPLL_SOGI_Q(0.0);
	
	spll_obj->theta[1]=spll_obj->theta[0];
	
	spll_obj->sin=SPLL_SOGI_SINE(spll_obj->theta[0]);
	spll_obj->cos=SPLL_SOGI_COS(spll_obj->theta[0]);
}

