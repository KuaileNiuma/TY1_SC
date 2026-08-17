/** 
  *************************************************************************************
  * @file DQ0_ABC_IQ.h 
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

#ifndef DQ0_ABC_IQ_H
#define DQ0_ABC_IQ_H

//*********** Structure Definition ********//
typedef struct{
	int32 a;
	int32 b;
	int32 c;
	int32 alpha;
	int32 beta;
	int32 sin;
	int32 cos;
	int32 d;
	int32 q;
	int32 z;
}DQ0_ABC_IQ;

//*********** Function Declarations *******//
void DQ0_ABC_IQ_init(DQ0_ABC_IQ *v);
void DQ0_ABC_IQ_FUNC(DQ0_ABC_IQ *v);

//*********** Macro Definition ***********//
#define DQ0_ABC_IQ_MACRO(v) 										\
	v.alpha = _IQmpy(v.d,v.cos) - _IQmpy(v.q,v.sin);				\
	v.beta  = _IQmpy(v.d,v.sin) + _IQmpy(v.q,v.cos);				\
	v.a = v.alpha;													\
	v.b = -_IQmpy(_IQ(0.5),v.alpha) + _IQmpy(_IQ(0.8660254),v.beta);\
	v.c = -_IQmpy(_IQ(0.5),v.alpha) - _IQmpy(_IQ(0.8660254),v.beta);


#endif /* DQ0_ABC_IQ_H_ */
