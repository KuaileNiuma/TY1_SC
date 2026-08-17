/** 
  *************************************************************************************
  * @file aci_se_const.h 
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

#ifndef _ACI_SE_CONST_H
#define _ACI_SE_CONST_H

//
// Included Files
//
#include "../aci_motor/parameter.h"
//#include "zhanlu_nice.h"

//
// Data structure for maintaining Speed estimator parameters
//
typedef struct 	{ 
	float  Rr;		  //!< Input: Rotor resistance (ohm) 
	float  Lr;		  //!< Input: Rotor inductance (H) 
	float  fb;        //!< Input: Base electrical frequency (Hz) 
	float  fc;        //!< Input: Cut-off frequency of lowpass filter (Hz) 
	float  Ts;		  //!< Input: Sampling period in sec  
	float  K1;		  //!< Output: constant using in rotor flux calculation  
	float  K2;		  //!< Output: constant using in rotor flux calculation  
	float  K3;		  //!< Output: constant using in rotor flux calculation  
	float  K4;		  //!< Output: constant using in stator current calculation
} ACISE_Const;

//
// Default initializer for the ACISE_CONST object
// These ACI parameters are based on WEG 1-hp induction motor
//
#define ACISE_CONST_DEFAULTS {RR_VALUE, LR_VALUE, \
                             BASE_FREQ, 200.0f, SAMPLING_PERIOD, \
 		          	         0,0,0,0, }

//
// Function prototypes
//
void ACISE_Const_calc(ACISE_Const *);

#endif //_ACI_SE_CONT_H

