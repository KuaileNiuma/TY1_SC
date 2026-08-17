/** 
  *************************************************************************************
  * @file SPLL_3ph_DDSRF_F.c 
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
void SPLL_3ph_DDSRF_F_init(int Grid_freq, float32 DELTA_T, float32 k1, float32 k2, SPLL_3ph_DDSRF_F *spll_obj)
{
	spll_obj->d_p=(float32)(0.0);
	spll_obj->d_n=(float32)(0.0);

	spll_obj->q_p=(float32)(0.0);
	spll_obj->q_n=(float32)(0.0);

	spll_obj->d_p_decoupl=(float32)(0.0);
	spll_obj->d_n_decoupl=(float32)(0.0);

	spll_obj->q_p_decoupl=(float32)(0.0);
	spll_obj->q_n_decoupl=(float32)(0.0);

	spll_obj->d_p_decoupl_lpf=(float32)(0.0);
	spll_obj->d_n_decoupl_lpf=(float32)(0.0);

	spll_obj->q_p_decoupl_lpf=(float32)(0.0);
	spll_obj->q_n_decoupl_lpf=(float32)(0.0);

	spll_obj->y[0]=(float32)(0.0);
	spll_obj->y[1]=(float32)(0.0);

	spll_obj->x[0]=(float32)(0.0);
	spll_obj->x[1]=(float32)(0.0);

	spll_obj->w[0]=(float32)(0.0);
	spll_obj->w[1]=(float32)(0.0);

	spll_obj->z[0]=(float32)(0.0);
	spll_obj->z[1]=(float32)(0.0);

	spll_obj->k1=k1;
	spll_obj->k2=k2;

	spll_obj->v_q[0]=(float32)(0.0);
	spll_obj->v_q[1]=(float32)(0.0);

	spll_obj->ylf[0]=(float32)(0.0);
	spll_obj->ylf[1]=(float32)(0.0);

	spll_obj->fo=(float32)(0.0);
	spll_obj->fn=(float32)(Grid_freq);

	spll_obj->theta[0]=(float32)(0.0);
	spll_obj->theta[1]=(float32)(0.0);

	// loop filter coefficients for 20kHz
	spll_obj->lpf_coeff.B0_lf=(float32)(166.9743);
	spll_obj->lpf_coeff.B1_lf=(float32)(-166.266);
	spll_obj->lpf_coeff.A1_lf=(float32)(-1.0);


	spll_obj->delta_T=DELTA_T;
}

//*********** Function Definition ********//
void SPLL_3ph_DDSRF_F_FUNC(SPLL_3ph_DDSRF_F *spll_obj)
{
	// before calling this routine run the ABC_DQ0_Pos_Neg and update the values for d_p,d_n,q_p,q_n
	// and update the cos_2theta and sin_2theta values with the prev angle

	//-------------------------//
	// Decoupling Network      //
	//-------------------------//
	spll_obj->d_p_decoupl=spll_obj->d_p - (spll_obj->d_n_decoupl_lpf*spll_obj->cos_2theta) - (spll_obj->q_n_decoupl*spll_obj->sin_2theta);
	spll_obj->q_p_decoupl=spll_obj->q_p + (spll_obj->d_n_decoupl_lpf*spll_obj->sin_2theta) - (spll_obj->q_n_decoupl*spll_obj->cos_2theta);

	spll_obj->d_n_decoupl=spll_obj->d_n - (spll_obj->d_p_decoupl_lpf*spll_obj->cos_2theta) + (spll_obj->q_p_decoupl*spll_obj->sin_2theta);
	spll_obj->q_n_decoupl=spll_obj->q_n - (spll_obj->d_p_decoupl_lpf*spll_obj->sin_2theta) - (spll_obj->q_p_decoupl*spll_obj->cos_2theta);

	//-------------------------//
	// Low pass filter         //
	//-------------------------//

	spll_obj->y[1]=(spll_obj->d_p_decoupl*spll_obj->k1) - (spll_obj->y[0]*spll_obj->k2);
	spll_obj->d_p_decoupl_lpf=spll_obj->y[1] + spll_obj->y[0];
	spll_obj->y[0]=spll_obj->y[1];

	spll_obj->x[1]=(spll_obj->q_p_decoupl*spll_obj->k1) - (spll_obj->x[0]*spll_obj->k2);
	spll_obj->q_p_decoupl_lpf=spll_obj->x[1] + spll_obj->x[0];
	spll_obj->x[0]=spll_obj->x[1];

	spll_obj->w[1]=(spll_obj->d_n_decoupl*spll_obj->k1) - (spll_obj->w[0]*spll_obj->k2);
	spll_obj->d_n_decoupl_lpf=spll_obj->w[1] + spll_obj->w[0];
	spll_obj->w[0]=spll_obj->w[1];

	spll_obj->z[1]=(spll_obj->q_n_decoupl*spll_obj->k1) - (spll_obj->z[0]*spll_obj->k2);
	spll_obj->q_n_decoupl_lpf=spll_obj->z[1] + spll_obj->z[0];
	spll_obj->z[0]=spll_obj->z[1];

	spll_obj->v_q[0]=spll_obj->q_p_decoupl;

	//---------------------------------//
	// Loop Filter                     //
	//---------------------------------//
	spll_obj->ylf[0]=spll_obj->ylf[1] + (spll_obj->lpf_coeff.B0_lf*spll_obj->v_q[0]) + (spll_obj->lpf_coeff.B1_lf*spll_obj->v_q[1]);
	spll_obj->ylf[1]=spll_obj->ylf[0];
	spll_obj->v_q[1]=spll_obj->v_q[0];

	//---------------------------------//
	// VCO                             //
	//---------------------------------//
	spll_obj->fo=spll_obj->fn+spll_obj->ylf[0];

	spll_obj->theta[0]=spll_obj->theta[1] + ((spll_obj->fo*spll_obj->delta_T)*(float32)(2*3.1415926));
	if(spll_obj->theta[0]>(float32)(2*3.1415926))
		spll_obj->theta[0]=spll_obj->theta[0] - (float32)(2*3.1415926);

	spll_obj->theta[1]=spll_obj->theta[0];
}

