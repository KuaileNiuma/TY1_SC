/** 
  *************************************************************************************
  * @file ABC_DQ0_NEG_F.h 
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

#ifndef ABC_DQ0_NEG_F_H
#define ABC_DQ0_NEG_F_H

//*********** Structure Definition ********//
typedef struct{
	float32 a;
	float32 b;
	float32 c;
	float32 alpha;
	float32 beta;
	float32 sin;
	float32 cos;
	float32 d;
	float32 q;
	float32 z;
}ABC_DQ0_NEG_F;

//*********** Function Declarations *******//
void ABC_DQ0_NEG_F_init(ABC_DQ0_NEG_F *v);
void ABC_DQ0_NEG_F_FUNC(ABC_DQ0_NEG_F *v);

//*********** Macro Definition ***********//
#define ABC_DQ0_NEG_F_MACRO(v) 						\
	v.alpha=(0.6666666667)*(v.a - 0.5*(v.b + v.c));	\
	v.beta=(0.57735026913)*(v.b - v.c);				\
	v.z =0.57735026913*(v.a + v.b + v.c);			\
	v.d=v.alpha*v.cos - v.beta*v.sin;				\
	v.q=v.alpha*v.sin + v.beta*v.cos;


#endif /* ABC_DQ0_NEG_F_H_ */
