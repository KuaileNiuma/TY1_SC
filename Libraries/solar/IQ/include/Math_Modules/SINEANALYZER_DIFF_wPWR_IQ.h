/** 
  *************************************************************************************
  * @file SINEANALYZER_DIFF_wPWR_IQ.h 
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

#ifndef SINEANALYZER_DIFF_wPWR_IQ_H
#define SINEANALYZER_DIFF_wPWR_IQ_H

//*********** Structure Definition ********//
typedef struct {
	int32  Vin;   				// Input: Sine Signal
	int32  SampleFreq;   		// Input: Signal Sampling Freq
	int32  Threshold;   		// Input: Voltage level corresponding to zero i/p
	int32  Vrms;   				// Output: RMS Value
	int32  Vavg;   				// Output: Average Value
	int32  Vema;				// Output: Exponential Moving Average Value
	int32  SigFreq;   			// Output: Signal Freq
	int32  Iin;   				// Input Current Signal
	int32  Irms;   				// Output: RMS Value of current
	int32  Prms;   				// Output: RMS Value of input power
	Uint16 ZCD;   				// Output: Zero Cross detected
	int32  sum_Vacc_avg;		// Internal : running sum for vacc_avg calculation over one sine cycle
	int32  sum_Vacc_rms;      	// Internal : running sum for vacc_rms calculation over one sine cycle
	int32  sum_Vacc_ema;		// Internal : running sum for vacc_ema calculation over one sine cycle
	int32  sum_Iacc_rms;      	// Internal : running sum for Iacc_rms calculation over one sine cycle
	int32  sum_Pacc_rms;      	// Internal : running sum for Pacc_rms calculation over one sine cycle
	int32  curr_vin_norm; 		// Internal: Normalized value of the input voltage
	int32  curr_iin_norm; 		// Internal: Normalized value of the input current
	Uint16 prev_sign;			// Internal: Flag to detect ZCD
	Uint16 curr_sign;         	// Internal: Flag to detect ZCD
	Uint32 nsamples;			// Internal: No of samples in one cycle of the sine wave
	Uint32 nsamplesMin;			// Internal: Lowerbound for no of samples in one sine wave cycle
	Uint32 nsamplesMax;			// Internal: Upperbound for no of samples in one sine wave cycle
	int32  inv_nsamples;		// Internal: 1/( No of samples in one cycle of the sine wave)
	int32  inv_sqrt_nsamples;	// Internal: sqrt(1/( No of samples in one cycle of the sine wave))
	Uint16 slew_power_update; 	// Internal: used to slew update of the power value
	int32  sum_Pacc_mul;		// Internal: used to sum Pac value over multiple sine cycles (100)
} SINEANALYZER_DIFF_wPWR_IQ;

typedef SINEANALYZER_DIFF_wPWR_IQ *SINEANALYZER_DIFF_wPWR_IQ_HANDLE;

//*********** Function Declarations *******//
void SINEANALYZER_DIFF_wPWR_IQ_init(SINEANALYZER_DIFF_wPWR_IQ *v);
void SINEANALYZER_DIFF_wPWR_IQ_FUNC(SINEANALYZER_DIFF_wPWR_IQ *v);

//*********** Macro Definition ***********//
#define SINEANALYZER_DIFF_wPWR_IQ_MACRO(v)															\
	if ( v.Vin > v.Threshold)																		\
	{																								\
		v.curr_vin_norm = v.Vin;																	\
		v.curr_iin_norm = v.Iin;																	\
		v.curr_sign = 1;																			\
	}																								\
	else																							\
	{																								\
		v.curr_vin_norm = _IQ15abs(v.Vin);															\
		v.curr_iin_norm = _IQ15abs(v.Iin);															\
		v.curr_sign = 0;																			\
	}																								\
	if((v.prev_sign != v.curr_sign) && (v.curr_sign == 1))											\
	{ 																								\
    	v.ZCD=1;																					\
    	v.inv_nsamples = _IQ15div(_IQ15(1.0), (v.nsamples<<15));									\
    	v.inv_sqrt_nsamples = _IQ15isqrt(v.nsamples<<15);											\
    	if(v.nsamplesMin < v.nsamples < v.nsamplesMax)												\
    	{																							\
			v.Vavg = _IQ15mpy(v.sum_Vacc_avg, v.inv_nsamples);										\
			v.Vrms = _IQ15mpy(_IQ15sqrt(v.sum_Vacc_rms),v.inv_sqrt_nsamples);						\
			v.Vema = v.sum_Vacc_ema;																\
			v.Irms = _IQ15rmpy(_IQ15sqrt(v.sum_Iacc_rms),v.inv_sqrt_nsamples);						\
			v.slew_power_update++ ;																	\
			if(v.slew_power_update >= 101)															\
			{																						\
				v.slew_power_update=0;																\
				v.Prms = _IQ15mpy(v.sum_Pacc_mul, _IQ15(0.01));										\
				v.sum_Pacc_mul = 0;																	\
			}																						\
			else																					\
			{																						\
				v.sum_Pacc_mul = v.sum_Pacc_mul + _IQ15rmpy(v.sum_Pacc_rms, v.inv_nsamples);		\
			}																						\
    	}																							\
    	else																						\
    	{																							\
    		v.Vavg = 0;																				\
			v.Vrms = 0;																				\
			v.Vema = 0;																				\
			v.Irms = 0;																				\
			v.Prms = 0;																				\
		}																							\
		v.SigFreq = (_IQ15mpy(v.SampleFreq, v.inv_nsamples)>>1); 									\
    	v.prev_sign = v.curr_sign;																	\
    	v.sum_Vacc_avg = 0;																			\
    	v.sum_Vacc_rms = 0;																			\
		v.sum_Vacc_ema = 0;																			\
    	v.sum_Iacc_rms = 0;																			\
    	v.sum_Pacc_rms = 0;																			\
    	v.nsamples=0;																				\
	}																								\
	else																							\
	{																								\
		v.nsamples++;																				\
		v.sum_Vacc_avg = v.sum_Vacc_avg+v.curr_vin_norm;											\
		v.sum_Vacc_rms = v.sum_Vacc_rms+_IQ15rsmpy(v.curr_vin_norm,v.curr_vin_norm);				\
		v.sum_Vacc_ema = v.sum_Vacc_ema+_IQ15rsmpy(_IQ15(0.01),(v.curr_vin_norm - v.sum_Vacc_ema));	\
		v.sum_Iacc_rms = v.sum_Iacc_rms+_IQ15rsmpy(v.curr_iin_norm,v.curr_iin_norm);				\
		v.sum_Pacc_rms = v.sum_Pacc_rms+_IQ15rsmpy(v.curr_iin_norm,v.curr_vin_norm);				\
		v.ZCD=0;																					\
		v.prev_sign = v.curr_sign;																	\
	}


#endif /*SINEANALYZER_DIFF_wPWR_IQ_H*/
