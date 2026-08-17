/** 
  *************************************************************************************
  * @file SPLL_1ph_F.c 
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

#include "Solar_F.h"

//*********** Structure Init Function ****//
void SPLL_1ph_F_init(int Grid_freq, float32 DELTA_T, SPLL_1ph_F *spll_obj)
{
	spll_obj->Upd[0]=(float32)(0.0);
	spll_obj->Upd[1]=(float32)(0.0);
	spll_obj->Upd[2]=(float32)(0.0);
	
	spll_obj->ynotch[0]=(float32)(0.0);
	spll_obj->ynotch[1]=(float32)(0.0);
	spll_obj->ynotch[2]=(float32)(0.0);
	
	spll_obj->ylf[0]=(float32)(0.0);
	spll_obj->ylf[1]=(float32)(0.0);
	
	spll_obj->sin[0]=(float32)(0.0);
	spll_obj->sin[1]=(float32)(0.0);
	
	spll_obj->cos[0]=(float32)(0.999);
	spll_obj->cos[1]=(float32)(0.999);
	
	spll_obj->theta[0]=(float32)(0.0);
	spll_obj->theta[1]=(float32)(0.0);
	
	spll_obj->wn=(float32)(2*3.14*Grid_freq);

	// loop filter coefficients for 20kHz
	spll_obj->lpf_coeff.B0_lf=(float32)(166.9743);
	spll_obj->lpf_coeff.B1_lf=(float32)(-166.266);
	spll_obj->lpf_coeff.A1_lf=(float32)(-1.0);
	
	spll_obj->delta_t=DELTA_T;  
}

//*********** Structure Coeff Update *****//
void SPLL_1ph_F_notch_coeff_update(float32 delta_T, float32 wn,float32 c2, float32 c1, SPLL_1ph_F *spll_obj)
{
	// Note c2<<c1 for the notch to work
	float32 x,y,z;
	x=(float32)(2.0*c2*wn*delta_T);
	y=(float32)(2.0*c1*wn*delta_T);
	z=(float32)(wn*delta_T*wn*delta_T);

	spll_obj->notch_coeff.A1_notch=(float32)(y-2);
	spll_obj->notch_coeff.A2_notch=(float32)(z-y+1);
	spll_obj->notch_coeff.B0_notch=(float32)(1.0);
	spll_obj->notch_coeff.B1_notch=(float32)(x-2);
	spll_obj->notch_coeff.B2_notch=(float32)(z-x+1);
}

//*********** Function Definition ********//
void SPLL_1ph_F_FUNC(SPLL_1ph_F *spll_obj)
{
	//-------------------//
	// Phase Detect 	 //
	//-------------------//
	
	spll_obj->Upd[0]=(spll_obj->AC_input*spll_obj->cos[1]);
	
	//-------------------//
	//Notch filter structure//
	//-------------------//
	
	spll_obj->ynotch[0]=-(spll_obj->notch_coeff.A1_notch*spll_obj->ynotch[1])-(spll_obj->notch_coeff.A2_notch*spll_obj->ynotch[2])+(spll_obj->notch_coeff.B0_notch*spll_obj->Upd[0])+(spll_obj->notch_coeff.B1_notch*spll_obj->Upd[1])+(spll_obj->notch_coeff.B2_notch*spll_obj->Upd[2]);
	
	// update the Upd array for future
	spll_obj->Upd[2]=spll_obj->Upd[1];
	spll_obj->Upd[1]=spll_obj->Upd[0];
	
	//---------------------------//
	// PI loop filter 			 //
	//---------------------------//
	
	spll_obj->ylf[0]=-(spll_obj->lpf_coeff.A1_lf*spll_obj->ylf[1])+(spll_obj->lpf_coeff.B0_lf*spll_obj->ynotch[0])+(spll_obj->lpf_coeff.B1_lf*spll_obj->ynotch[1]);
	
	//update array for future use
	spll_obj->ynotch[2]=spll_obj->ynotch[1];
	spll_obj->ynotch[1]=spll_obj->ynotch[0];
	
	spll_obj->ylf[1]=spll_obj->ylf[0];
	
	//------------------//
	// VCO              //
	//------------------//
	
	spll_obj->wo=spll_obj->wn+spll_obj->ylf[0];
	
	//integration process
	spll_obj->sin[0]=spll_obj->sin[1]+(((spll_obj->delta_t*spll_obj->wo))*spll_obj->cos[1]);
	spll_obj->cos[0]=spll_obj->cos[1]-(((spll_obj->delta_t*spll_obj->wo))*spll_obj->sin[1]);

	if(spll_obj->sin[0]>(float32)(0.99))
		spll_obj->sin[0]=(float32)(0.99);
	else if(spll_obj->sin[0]<(float32)(-0.99))
		spll_obj->sin[0]=(float32)(-0.99);
	
	if(spll_obj->cos[0]>(float32)(0.99))
		spll_obj->cos[0]=(float32)(0.99);
	else if(spll_obj->cos[0]<(float32)(-0.99))
		spll_obj->cos[0]=(float32)(-0.99);
	
	spll_obj->theta[0]=spll_obj->theta[1]+((spll_obj->wo*(float32)(0.159154943))*spll_obj->delta_t);
	
	if(spll_obj->sin[0]>(float32)(0.0) && spll_obj->sin[1]<=(float32)(0.0))
	{
		spll_obj->theta[0]=(float32)(0.0);
	} 
	
	spll_obj->theta[1]=spll_obj->theta[0];
	
	spll_obj->sin[1]=spll_obj->sin[0];
	spll_obj->cos[1]=spll_obj->cos[0];
}

