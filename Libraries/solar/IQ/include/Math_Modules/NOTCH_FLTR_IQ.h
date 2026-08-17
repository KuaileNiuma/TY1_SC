/** 
  *************************************************************************************
  * @file NOTCH_FLTR_IQ.h 
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

#ifndef NOTCH_FLTR_IQ_H_
#define NOTCH_FLTR_IQ_H_

/*********** Structure Definitions ***********/
typedef struct{
	_iq24	B2_notch;
	_iq24	B1_notch;
	_iq24	B0_notch;
	_iq24	A2_notch;
	_iq24	A1_notch;
}NOTCH_COEFF_IQ;

typedef struct{
	_iq24	Out1;
	_iq24	Out2;
	_iq24	In;
	_iq24	In1;
	_iq24 	In2;
	_iq24	Out;
}NOTCH_VARS_IQ;

//*********** Function Declarations *******//
void NOTCH_FLTR_IQ_VARS_init(NOTCH_VARS_IQ *v);
void NOTCH_FLTR_IQ_run(NOTCH_VARS_IQ *v,NOTCH_COEFF_IQ *w);
void NOTCH_FLTR_IQ_ASM(NOTCH_VARS_IQ *v,NOTCH_COEFF_IQ *w);
void NOTCH_FLTR_IQ_COEFF_Update(float32 delta_T, float32 wn,float32 c2, float32 c1, NOTCH_COEFF_IQ *notch_obj);

//*********** Macro Definition ***********//
#define NOTCH_FLTR_IQ_MACRO(v, w)		\
	v.Out=_IQ24mpy(w.A1_notch,v.Out1)+_IQ24mpy(w.A2_notch,v.Out2)+_IQ24mpy(w.B0_notch,v.In)+_IQ24mpy(w.B1_notch,v.In1)+_IQ24mpy(w.B2_notch,v.In2); \
	v.Out2=v.Out1;	\
	v.Out1=v.Out;	\
	v.In2=v.In1;	\
	v.In1=v.In;

#endif
