/** 
  *************************************************************************************
  * @file DQ0_ABC_F.h 
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

#ifndef DQ0_ABC_F_H
#define DQ0_ABC_F_H

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
}DQ0_ABC_F;

//*********** Function Declarations *******//
void DQ0_ABC_F_init(DQ0_ABC_F *v);
void DQ0_ABC_F_FUNC(DQ0_ABC_F *v);

//*********** Macro Definition ***********//
#define DQ0_ABC_F_MACRO(v) 							\
	v.alpha = v.d*v.cos - v.q*v.sin;				\
	v.beta  = v.d*v.sin + v.q*v.cos;				\
	v.a = v.alpha + 0.5*v.z;						\
	v.b = -0.5*v.alpha + 0.8660254*v.beta + 0.5*v.z;\
	v.c = -0.5*v.alpha - 0.8660254*v.beta + 0.5*v.z;


#endif /* DQ0_ABC_F_H_ */
