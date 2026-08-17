/** 
  *************************************************************************************
  * @file SINEANALYZER_DIFF_IQ.h 
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

#ifndef SINEANALYZER_DIFF_IQ_H_
#define SINEANALYZER_DIFF_IQ_H_

//*********** Structure Definition ********//
typedef struct {
	int32 Vin;   			// Input: Sine Signal
	int32 SampleFreq;   	// Input: Signal Sampling Freq
	int32 Threshold;   		// Input: Voltage level corresponding to zero i/p
	int32 Vrms;   			// Output: RMS Value
	int32 Vavg;   			// Output: Average Value
	int32 Vema;   			// Output: Exponential Moving Average Value
	int32 SigFreq;   		// Output: Signal Freq
	Uint16 ZCD;   			// Output: Zero Cross detected
	// internal variables
	int32 Vacc_avg ;
	int32 Vacc_rms ;
	int32 Vacc_ema;
	int32 curr_sample_norm; // normalized value of current sample
	Uint16 prev_sign ;
	Uint16 curr_sign ;
	Uint32 nsamples ;		// samples in half cycle input waveform
	Uint32 nsamplesMin;
	Uint32 nsamplesMax;
	int32 inv_nsamples;
	int32 inv_sqrt_nsamples;
} SINEANALYZER_DIFF_IQ;

//*********** Function Declarations *******//
void SINEANALYZER_DIFF_IQ_init(SINEANALYZER_DIFF_IQ *v);
void SINEANALYZER_DIFF_IQ_FUNC(SINEANALYZER_DIFF_IQ *v);

//*********** Macro Definition ***********//
#define SINEANALYZER_DIFF_IQ_MACRO(v)														\
	if ( v.Vin > v.Threshold)																\
	{																						\
		v.curr_sample_norm = v.Vin;															\
		v.curr_sign = 1;																	\
	}																						\
	else																					\
	{																						\
		v.curr_sample_norm = _IQ15abs(v.Vin);												\
		v.curr_sign = 0;																	\
	}																						\
	if((v.prev_sign != v.curr_sign) && (v.curr_sign == 1))									\
	{																						\
		v.ZCD=1;																			\
		v.inv_nsamples = _IQ15div(_IQ15(1.0), (v.nsamples<<15));							\
		v.inv_sqrt_nsamples = _IQ15isqrt(v.nsamples<<15);									\
		if(v.nsamplesMin < v.nsamples < v.nsamplesMax)										\
		{																					\
			v.Vavg = _IQ15mpy(v.Vacc_avg, v.inv_nsamples);									\
			v.Vrms = _IQ15mpy(_IQ15sqrt(v.Vacc_rms), _IQ15isqrt(v.nsamples<<15));			\
			v.Vema = v.Vacc_ema;															\
		}																					\
		else																				\
		{																					\
			v.Vavg = 0;																		\
			v.Vrms = 0;																		\
			v.Vema = 0;																		\
		}																					\
		v.SigFreq = (_IQ15mpy(v.SampleFreq, v.inv_nsamples));								\
		v.prev_sign = v.curr_sign;															\
		v.Vacc_avg = 0;																		\
		v.Vacc_rms = 0;																		\
		v.Vacc_ema = 0;																		\
		v.nsamples=0;																		\
	}																						\
	else																					\
	{																						\
		v.nsamples++;																		\
		v.Vacc_avg = v.Vacc_avg+v.curr_sample_norm;											\
		v.Vacc_rms = v.Vacc_rms+_IQ15mpy(v.curr_sample_norm,v.curr_sample_norm);			\
		v.Vacc_ema = v.Vacc_ema+_IQ15mpy(_IQ15(0.01), (v.curr_sample_norm - v.Vacc_ema));	\
		v.ZCD=0;																			\
		v.prev_sign = v.curr_sign;															\
	}																						\


#endif /*SINEANALYZER_DIFF_IQ_H_*/
