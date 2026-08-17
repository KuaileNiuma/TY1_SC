/** 
  *************************************************************************************
  * @file ABC_DQ0_POS_IQ.h 
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

#ifndef ABC_DQ0_POS_IQ_H
#define ABC_DQ0_POS_IQ_H

/

/
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
}ABC_DQ0_POS_IQ;

//
void ABC_DQ0_POS_IQ_init(ABC_DQ0_POS_IQ *v);
void ABC_DQ0_POS_IQ_FUNC(ABC_DQ0_POS_IQ *v);

//
#define ABC_DQ0_POS_IQ_MACRO(v) 										\
	v.alpha=_IQmpy(_IQ(0.6666666667),(v.a-_IQmpy(_IQ(0.5),(v.b+v.c))));	\
	v.beta=_IQmpy(_IQ(0.57735026913),(v.b-v.c));						\
	v.z=_IQmpy(_IQ(0.33333333333),(v.a+v.b+v.c));						\
	v.d=_IQmpy(v.alpha,v.cos)+_IQmpy(v.beta,v.sin);						\
	v.q=-_IQmpy(v.alpha,v.sin)+_IQmpy(v.beta,v.cos);

#endif /* ABC_DQ0_POS_IQ_H_ */





