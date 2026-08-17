/** 
  *************************************************************************************
  * @file SPLL_1ph_IQ.c 
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
void SPLL_1ph_IQ_init(int Grid_freq, long DELTA_T, SPLL_1ph_IQ *spll_obj)
{
	spll_obj->Upd[0]=SPLL_Q(0.0);
	spll_obj->Upd[1]=SPLL_Q(0.0);
	spll_obj->Upd[2]=SPLL_Q(0.0);
	
	spll_obj->ynotch[0]=SPLL_Q(0.0);
	spll_obj->ynotch[1]=SPLL_Q(0.0);
	spll_obj->ynotch[2]=SPLL_Q(0.0);
	
	spll_obj->ylf[0]=SPLL_Q(0.0);
	spll_obj->ylf[1]=SPLL_Q(0.0);
	
	spll_obj->sin[0]=SPLL_Q(0.0);
	spll_obj->sin[1]=SPLL_Q(0.0);
	
	spll_obj->cos[0]=SPLL_Q(0.999);
	spll_obj->cos[1]=SPLL_Q(0.999);
	
	spll_obj->theta[0]=SPLL_Q(0.0);
	spll_obj->theta[1]=SPLL_Q(0.0);
	
	spll_obj->wn=SPLL_Q(2*3.14*Grid_freq);

	// loop filter coefficients for 20kHz
	spll_obj->lpf_coeff.B0_lf=SPLL_Q(166.9743);
	spll_obj->lpf_coeff.B1_lf=SPLL_Q(-166.266);
	spll_obj->lpf_coeff.A1_lf=SPLL_Q(-1.0);
	
	spll_obj->delta_t=DELTA_T;  
}

//*********** Structure Coeff Update *****//
void SPLL_1ph_IQ_notch_coeff_update(float delta_T, float wn,float c2, float c1, SPLL_1ph_IQ *spll_obj)
{
	// Note c2<<c1 for the notch to work
	float x,y,z;
	x=(float)(2.0*c2*wn*delta_T);
	y=(float)(2.0*c1*wn*delta_T);
	z=(float)(wn*delta_T*wn*delta_T);

	spll_obj->notch_coeff.A1_notch=SPLL_Q(y-2);
	spll_obj->notch_coeff.A2_notch=SPLL_Q(z-y+1);
	spll_obj->notch_coeff.B0_notch=SPLL_Q(1.0);
	spll_obj->notch_coeff.B1_notch=SPLL_Q(x-2);
	spll_obj->notch_coeff.B2_notch=SPLL_Q(z-x+1);
}
	
//*********** Function Definition ********//
void SPLL_1ph_IQ_FUNC(SPLL_1ph_IQ *spll_obj)
{
	//-------------------//
	// Phase Detect 	 //
	//-------------------//
	
	spll_obj->Upd[0]=SPLL_Qmpy(spll_obj->AC_input,spll_obj->cos[1]);
	
	//-------------------//
	//Notch filter structure//
	//-------------------//
	
	spll_obj->ynotch[0]=-SPLL_Qmpy(spll_obj->notch_coeff.A1_notch,spll_obj->ynotch[1])-SPLL_Qmpy(spll_obj->notch_coeff.A2_notch,spll_obj->ynotch[2])+SPLL_Qmpy(spll_obj->notch_coeff.B0_notch,spll_obj->Upd[0])+SPLL_Qmpy(spll_obj->notch_coeff.B1_notch,spll_obj->Upd[1])+SPLL_Qmpy(spll_obj->notch_coeff.B2_notch,spll_obj->Upd[2]);
	
	// update the Upd array for future
	spll_obj->Upd[2]=spll_obj->Upd[1];
	spll_obj->Upd[1]=spll_obj->Upd[0];
	
	//---------------------------//
	// PI loop filter 			 //
	//---------------------------//
	
	spll_obj->ylf[0]=-SPLL_Qmpy(spll_obj->lpf_coeff.A1_lf,spll_obj->ylf[1])+SPLL_Qmpy(spll_obj->lpf_coeff.B0_lf,spll_obj->ynotch[0])+SPLL_Qmpy(spll_obj->lpf_coeff.B1_lf,spll_obj->ynotch[1]);
	
	//update array for future use
	spll_obj->ynotch[2]=spll_obj->ynotch[1];
	spll_obj->ynotch[1]=spll_obj->ynotch[0];
	
	spll_obj->ylf[1]=spll_obj->ylf[0];
	
	//------------------//
	// VCO              //
	//------------------//
	
	spll_obj->wo=spll_obj->wn+spll_obj->ylf[0];
	
	//integration process
	spll_obj->sin[0]=spll_obj->sin[1]+SPLL_Qmpy((SPLL_Qmpy(spll_obj->delta_t,spll_obj->wo)),spll_obj->cos[1]);
	spll_obj->cos[0]=spll_obj->cos[1]-SPLL_Qmpy((SPLL_Qmpy(spll_obj->delta_t,spll_obj->wo)),spll_obj->sin[1]);

	if(spll_obj->sin[0]>SPLL_Q(0.99))
		spll_obj->sin[0]=SPLL_Q(0.99);
	else if(spll_obj->sin[0]<SPLL_Q(-0.99))
		spll_obj->sin[0]=SPLL_Q(-0.99);
	
	if(spll_obj->cos[0]>SPLL_Q(0.99))
		spll_obj->cos[0]=SPLL_Q(0.99);
	else if(spll_obj->cos[0]<SPLL_Q(-0.99))
		spll_obj->cos[0]=SPLL_Q(-0.99);
	
	spll_obj->theta[0]=spll_obj->theta[1]+SPLL_Qmpy(SPLL_Qmpy(spll_obj->wo,SPLL_Q(0.159154943)),spll_obj->delta_t);
	
	if(spll_obj->sin[0]>SPLL_Q(0.0) && spll_obj->sin[1]<=SPLL_Q(0.0))
	{
		spll_obj->theta[0]=SPLL_Q(0.0);
	} 
	
	spll_obj->theta[1]=spll_obj->theta[0];
	
	spll_obj->sin[1]=spll_obj->sin[0];
	spll_obj->cos[1]=spll_obj->cos[0];
}

