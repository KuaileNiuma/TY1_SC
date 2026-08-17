/** 
  *************************************************************************************
  * @file CNTL_PI_F.h 
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

#ifndef CNTL_PI_F_H_
#define CNTL_PI_F_H_

//*********** Structure Definition ********//

// PI control law with programmable output saturation.
// This macro uses CNTL_PI_F structures to store coefficients & internal values.
// The structures should be initialized with the supplied CNTL_PI_F_INIT macro.
// Within the structure the Max & Min parameters are the output bounds

typedef struct {
	float32  Ref;   			// Input: reference set-point
	float32  Fbk;   			// Input: feedback
	float32  Out;   			// Output: controller output
	float32  Kp;				// Parameter: proportional loop gain
	float32  Ki;			    // Parameter: integral gain
	float32  Umax;				// Parameter: upper saturation limit
	float32  Umin;				// Parameter: lower saturation limit
	float32  up;				// Data: proportional term
	float32  ui;				// Data: integral term
	float32  v1;				// Data: pre-saturated controller output
	float32  i1;				// Data: integrator storage: ui(k-1)
	float32  w1;				// Data: saturation record: [u(k-1) - v(k-1)]
} CNTL_PI_F;

//*********** Function Declarations *******//
void CNTL_PI_F_init(CNTL_PI_F *k);
void CNTL_PI_F_FUNC(CNTL_PI_F *v);

//*********** Macro Definition ***********//
#define CNTL_PI_F_MACRO(v)								\
	/* proportional term */ 							\
	v.up = ((v.Ref - v.Fbk)*v.Kp);						\
														\
	/* integral term */ 								\
	v.ui = (v.Out == v.v1)?((v.Ki* v.up)+ v.i1) : v.i1;	\
	v.i1 = v.ui;										\
														\
	/* control output */ 								\
	v.v1 = (v.up + v.ui);								\
	v.Out= (v.v1> v.Umax)?v.Umax:v.v1;					\
	v.Out= (v.Out< v.Umin)?v.Umin:v.Out;				\
	

#endif /* CNTL_PI_F_H_ */
