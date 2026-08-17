/** 
  *************************************************************************************
  * @file Solar_F.h 
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

#ifndef SOLAR_F_H
#define SOLAR_F_H

#ifndef F28_DATA_TYPES
#define F28_DATA_TYPES
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             	int16;
typedef long            	int32;
typedef long long			int64;
typedef unsigned long long	Uint64;
typedef float           	float32;
typedef long double     	float64;
#endif
#endif

#ifndef _TI_STD_TYPES
#define _TI_STD_TYPES
typedef int             Int;
typedef unsigned        Uns;
typedef char            Char;
typedef char            *String;
typedef void            *Ptr;
typedef unsigned short	Bool;

typedef unsigned long   Uint32;
typedef unsigned int    Uint16;
typedef unsigned char   Uint8;

typedef long            Int32;
typedef int             Int16;
typedef char            Int8;
#endif

#include "math.h"

#include "ABC_DQ0_POS_F.h"
#include "ABC_DQ0_NEG_F.h"
#include "CLARKE_F.h"
#include "CNTL_2P2Z_F.h"
#include "CNTL_3P3Z_F.h"
#include "CNTL_PI_F.h"
#include "DLOG_1CH_F.h"
#include "DLOG_4CH_F.h"
#include "DQ0_ABC_F.h"
#include "iCLARKE_F.h"
#include "iPARK_F.h"
#include "MATH_EMAVG_F.h"
#include "MPPT_INCC_F.h"
#include "MPPT_INCC_I_F.h"
#include "MPPT_PNO_F.h"
#include "NOTCH_FLTR_F.h"
#include "PARK_F.h"
#include "PID_GRANDO_F.h"
#include "RAMPGEN_F.h"
#include "SINEANALYZER_DIFF_F.h"
#include "SINEANALYZER_DIFF_wPWR_F.h"
#include "SPLL_1ph_F.h"
#include "SPLL_1ph_SOGI_F.h"
#include "SPLL_3PH_DDSRF_F.h"
#include "SPLL_3PH_SRF_F.h"


#endif
