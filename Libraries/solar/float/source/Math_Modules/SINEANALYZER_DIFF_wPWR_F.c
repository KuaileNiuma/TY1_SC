/** 
  *************************************************************************************
  * @file SINEANALYZER_DIFF_wPWR_F.c 
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
void SINEANALYZER_DIFF_wPWR_F_init(SINEANALYZER_DIFF_wPWR_F *v)
{
	v->Vin=0;
	v->SampleFreq=0;
	v->Threshold=0;
	v->Vrms=0;
	v->Vavg=0;
	v->Vema=0;
	v->SigFreq=0;
	v->Iin=0;
	v->Irms=0;
	v->Prms=0;
	v->ZCD=0;
	v->sum_Vacc_avg=0;
	v->sum_Vacc_rms=0;
	v->sum_Vacc_ema=0;
	v->sum_Iacc_rms=0;
	v->sum_Pacc_rms=0;
	v->curr_vin_norm=0;
	v->curr_iin_norm=0;
	v->prev_sign=1;
	v->curr_sign=1;
	v->nsamples=0;
	v->nsamplesMin = 0;
	v->nsamplesMax = 0;
	v->inv_nsamples=0;
	v->inv_sqrt_nsamples=0;
	v->slew_power_update=0;
	v->sum_Pacc_mul=0;
}

//*********** Function Definition ********//
void SINEANALYZER_DIFF_wPWR_F_FUNC(SINEANALYZER_DIFF_wPWR_F *v)
{
	if ( v->Vin > v->Threshold)
	{
		v->curr_vin_norm = v->Vin;
		v->curr_iin_norm = v->Iin;
		v->curr_sign = 1;
	}
	else
	{
		v->curr_vin_norm = fabs(v->Vin);
		v->curr_iin_norm = fabs(v->Iin);
		v->curr_sign = 0;
	}
	if((v->prev_sign != v->curr_sign) && (v->curr_sign == 1))
	{
		v->ZCD=1;
		v->inv_nsamples = (1.0)*__einvf32(v->nsamples);
		v->inv_sqrt_nsamples = (1.0)*__eisqrtf32(v->nsamples);
		if(v->nsamplesMin < v->nsamples < v->nsamplesMax)
		{
			v->Vavg = (v->sum_Vacc_avg*v->inv_nsamples);
			v->Vrms = (sqrt(v->sum_Vacc_rms)*v->inv_sqrt_nsamples);
			v->Vema = v->sum_Vacc_ema;
			v->Irms = (sqrt(v->sum_Iacc_rms)*v->inv_sqrt_nsamples);
			v->slew_power_update++ ;
			if(v->slew_power_update >= 101)
			{
				v->slew_power_update=0;
				v->Prms = (v->sum_Pacc_mul*(0.01));
				v->sum_Pacc_mul = 0;
			}
			else
			{
				v->sum_Pacc_mul = v->sum_Pacc_mul + (v->sum_Pacc_rms*v->inv_nsamples);
			}
		}
		else
		{
    		v->Vavg = 0;
    		v->Vrms = 0;
    		v->Vema = 0;
    		v->Irms = 0;
    		v->Prms = 0;
		}
		v->SigFreq = (v->SampleFreq*v->inv_nsamples);
		v->prev_sign = v->curr_sign;
		v->sum_Vacc_avg = 0;
		v->sum_Vacc_rms = 0;
		v->sum_Vacc_ema = 0;
		v->sum_Iacc_rms = 0;
		v->sum_Pacc_rms = 0;
		v->nsamples=0;
	}
	else
	{
		v->nsamples++;
		v->sum_Vacc_avg = v->sum_Vacc_avg+v->curr_vin_norm;
		v->sum_Vacc_rms = v->sum_Vacc_rms+(v->curr_vin_norm*v->curr_vin_norm);
		v->sum_Vacc_ema = v->sum_Vacc_ema+(0.01*(v->curr_vin_norm - v->sum_Vacc_ema));
		v->sum_Iacc_rms = v->sum_Iacc_rms+(v->curr_iin_norm*v->curr_iin_norm);
		v->sum_Pacc_rms = v->sum_Pacc_rms+(v->curr_iin_norm*v->curr_vin_norm);
		v->ZCD=0;
		v->prev_sign = v->curr_sign;
	}
}
