/** 
  *************************************************************************************
  * @file CNTL_3P3Z_IQ.c 
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
void CNTL_3P3Z_IQ_VARS_init(CNTL_3P3Z_IQ_VARS *k){
	// Initialize variables
	k->Ref = 0;
	k->Fdbk = 0;
	k->Errn = 0;
	k->Errn1 = 0;
	k->Errn2 = 0;
	k->Errn3 = 0;
	k->Out = 0;
	k->Out1 = 0;
	k->Out2 = 0;
	k->Out3 = 0;
}

void CNTL_3P3Z_IQ_COEFFS_init(CNTL_3P3Z_IQ_COEFFS *v){
	// Initialize coefficients
	v->Coeff_B3 = 0;
	v->Coeff_B2 = 0;
	v->Coeff_B1 = 0;
	v->Coeff_B0 = 0;
	v->Coeff_A3 = 0;
	v->Coeff_A2 = 0;
	v->Coeff_A1 = 0;
	// IMin cannot be lower than -0.9
	v->IMin = _IQ24(-0.9);
	v->Max = _IQ24(1.0);
	v->Min = (0);
}

//*********** Function Definition ********//

// Calculates a third order control law with IIR filter and programmable output saturation.
// @param CNTL_3P3Z_IQ_COEFFS structure with proper coefficient values.
// @param CNTL_3P3Z_IQ_VARS structure with internal & output values.
// @return CNTL_3P3Z_IQ_VARS Out parameter.

void CNTL_3P3Z_IQ_FUNC(CNTL_3P3Z_IQ_COEFFS *v, CNTL_3P3Z_IQ_VARS *k){
	/* Calculate error */
	k->Errn = k->Ref - k->Fdbk;
	k->Out = _IQ24mpy(v->Coeff_A3,k->Out3)+_IQ24mpy(v->Coeff_A2,k->Out2) + _IQ24mpy(v->Coeff_A1 , k->Out1)
	+ _IQ24mpy(v->Coeff_B3 ,k->Errn3)+_IQ24mpy(v->Coeff_B2 ,k->Errn2) + _IQ24mpy(v->Coeff_B1 , k->Errn1) + _IQ24mpy(v->Coeff_B0 , k->Errn);

	/* Update error values */
	k->Errn3 = k->Errn2;
	k->Errn2 = k->Errn1;
	k->Errn1 = k->Errn;

	/* Determine new output */
	k->Out = (k->Out < v->Max) ? k->Out : v->Max;
	k->Out = (k->Out > v->IMin) ? k->Out : v->IMin;

	/* Store outputs */
	k->Out3 = k->Out2;
	k->Out2 = k->Out1;
	k->Out1 = k->Out;
	/* Saturated output */
	k->Out = ((k->Out > v->Min) ? k->Out : v->Min);
}

