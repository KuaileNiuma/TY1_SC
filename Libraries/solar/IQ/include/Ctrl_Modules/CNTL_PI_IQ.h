/** 
  *************************************************************************************
  * @file CNTL_PI_IQ.h 
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

#ifndef CNTL_PI_IQ_H_
#define CNTL_PI_IQ_H_

//*********** Structure Definition ********//

// PI control law with programmable output saturation.
// This macro uses CNTL_PI_IQ structures to store coefficients & internal values.
// The structures should be initialized with the supplied CNTL_PI_IQ_INIT macro.
// Within the structure the Max & Min parameters are the output bounds

typedef struct {
	int32 Ref;   			// Input: reference set-point
	int32 Fbk;   			// Input: feedback
	int32 Out;   			// Output: controller output
	int32 Kp;				// Parameter: proportional loop gain
	int32 Ki;			    // Parameter: integral gain
	int32 Umax;				// Parameter: upper saturation limit
	int32 Umin;				// Parameter: lower saturation limit
	int32 up;				// Data: proportional term
	int32 ui;				// Data: integral term
	int32 v1;				// Data: pre-saturated controller output
	int32 i1;				// Data: integrator storage: ui(k-1)
	int32 w1;				// Data: saturation record: [u(k-1) - v(k-1)]
} CNTL_PI_IQ;

//*********** Function Declarations *******//
void CNTL_PI_IQ_init(CNTL_PI_IQ *k);
void CNTL_PI_IQ_FUNC(CNTL_PI_IQ *v);

//*********** Macro Definition ***********//
#define CNTL_PI_IQ_MACRO(v)										\
	/* proportional term */ 									\
	v.up = _IQmpy((v.Ref - v.Fbk),v.Kp);						\
																\
	/* integral term */ 										\
	v.ui = (v.Out == v.v1)?(_IQmpy(v.Ki, v.up)+ v.i1) : v.i1;	\
	v.i1 = v.ui;												\
																\
	/* control output */ 										\
	v.v1 = (v.up + v.ui);										\
	v.Out= _IQsat(v.v1, v.Umax, v.Umin);						\
	/*v.w1 = (v.Out == v.v1) ? _IQ(1.0) : _IQ(0.0);*/			\
	

#endif /* CNTL_PI_H_ */
