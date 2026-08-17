/** 
  *************************************************************************************
  * @file Solar_IQ.h 
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

#ifndef SOLAR_IQ_H
#define SOLAR_IQ_H

#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             	int16;
typedef long            	int32;
typedef long long			int64;
typedef unsigned int		Uint16;
typedef unsigned long		Uint32;
typedef unsigned long long	Uint64;
typedef float           	float32;
typedef long double     	float64;
#endif

#include "IQmathLib.h"

#include "ABC_DQ0_POS_IQ.h"
#include "ABC_DQ0_NEG_IQ.h"
#include "CLARKE_IQ.h"
#include "CNTL_2P2Z_IQ.h"
#include "CNTL_3P3Z_IQ.h"
#include "CNTL_PI_IQ.h"
#include "DLOG_1CH_IQ.h"
#include "DLOG_4CH_IQ.h"
#include "DQ0_ABC_IQ.h"
#include "iCLARKE_IQ.h"
#include "iPARK_IQ.h"
#include "MATH_EMAVG_IQ.h"
#include "MPPT_INCC_I_IQ.h"
#include "MPPT_INCC_IQ.h"
#include "MPPT_PNO_IQ.h"
#include "PARK_IQ.h"
#include "PID_GRANDO_IQ.h"
#include "RAMPGEN_IQ.h"
#include "SINEANALYZER_DIFF_IQ.h"
#include "SINEANALYZER_DIFF_wPWR_IQ.h"
#include "SPLL_1ph_IQ.h"
#include "SPLL_1ph_SOGI_IQ.h"
#include "SPLL_3PH_SRF_IQ.h"
#include "SPLL_3PH_DDSRF_IQ.h"
#include "NOTCH_FLTR_IQ.h"


#endif
