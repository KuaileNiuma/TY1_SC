/** 
  *************************************************************************************
  * @file CNTL_2P2Z_F.h 
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

#ifndef CNTL_2P2Z_F_H_
#define CNTL_2P2Z_F_H_

//*********** Structure Definition ********//

// Second order control law using an IIR filter structure with programmable output saturation.
// This macro uses CNTL_2P2Z_F structures to store coefficients & internal values.
// The structures should be initialized with the supplied CNTL_2P2Z_F_INIT macro.
// Within the structure the Max & Min parameters are the output bounds where as the IMin parameter
// is used for saturating the lower bound while keeping an internal history.  The IMin parameter
// should not be lower than -0.9.

typedef struct {
	// Coefficients
	float32 Coeff_B2;
	float32 Coeff_B1;
	float32 Coeff_B0;
	float32 Coeff_A2;
	float32 Coeff_A1;

	// Output saturation limits
	float32 Max;
	float32 IMin;
	float32 Min;
} CNTL_2P2Z_F_COEFFS;

typedef struct {
	float32 Out1;
	float32 Out2;
	// Internal values
	float32 Errn;
	float32 Errn1;
	float32 Errn2;
	// Inputs
	float32 Ref;
	float32 Fdbk;
	// Output values
	float32 Out;
} CNTL_2P2Z_F_VARS;

//*********** Function Declarations *******//
void CNTL_2P2Z_F_COEFFS_init(CNTL_2P2Z_F_COEFFS *v);
void CNTL_2P2Z_F_VARS_init(CNTL_2P2Z_F_VARS *k);
void CNTL_2P2Z_F_FUNC(CNTL_2P2Z_F_COEFFS *v, CNTL_2P2Z_F_VARS *k);
void CNTL_2P2Z_F_ASM(CNTL_2P2Z_F_COEFFS *v, CNTL_2P2Z_F_VARS *k);

//*********** Macro Definition ***********//
#define CNTL_2P2Z_F_MACRO(v, k)																\
	/* Calculate error */																	\
	k.Errn = k.Ref - k.Fdbk;																\
	k.Out = (v.Coeff_A2*k.Out2) + (v.Coeff_A1 *k.Out1) + (v.Coeff_B2 *k.Errn2)				\
					+ (v.Coeff_B1 * k.Errn1) + (v.Coeff_B0 * k.Errn);						\
	/* Update error values */																\
	k.Errn2 = k.Errn1;																		\
	k.Errn1 = k.Errn;																		\
	/* Determine new output */																\
	k.Out = (k.Out < v.Max) ? k.Out : v.Max;												\
	k.Out = (k.Out > v.IMin) ? k.Out : v.IMin;												\
	/* Store outputs */																		\
	k.Out2 = k.Out1;																		\
	k.Out1 = k.Out;																			\
	/* Saturated output */																	\
	k.Out = ((k.Out > v.Min) ? k.Out : v.Min);


#endif /* CNTL_2P2Z_F_H_ */
