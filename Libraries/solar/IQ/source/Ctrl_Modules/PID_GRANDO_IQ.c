/** 
  *************************************************************************************
  * @file PID_GRANDO_IQ.c 
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
void PID_GRANDO_IQ_init(PID_GRANDO_IQ_CONTROLLER *v)
{
	v->term.Ref=0;
	v->term.Fbk=0;
	v->term.Out=0;
	v->term.c1=0;
	v->term.c2=0;

	v->param.Kr = _IQ(1.0);
	v->param.Kp = _IQ(1.0);
	v->param.Ki = _IQ(0.0);
	v->param.Kd = _IQ(0.0);
	v->param.Km = _IQ(1.0);
	v->param.Umax = _IQ(1.0);
	v->param.Umin = _IQ(-1.0);

	v->data.up = _IQ(0.0);
	v->data.ui = _IQ(0.0);
	v->data.ud = _IQ(0.0);
	v->data.v1 = _IQ(0.0);
	v->data.i1 = _IQ(0.0);
	v->data.d1 = _IQ(0.0);
	v->data.d2 = _IQ(0.0);
	v->data.w1 = _IQ(1.0);
}

//*********** Function Definition ********//
void PID_GRANDO_IQ_FUNC(PID_GRANDO_IQ_CONTROLLER *v)
{
	/* proportional term */
	v->data.up = _IQmpy(v->param.Kr, v->term.Ref) - v->term.Fbk;

	/* integral term */
	v->data.ui = _IQmpy(v->param.Ki, _IQmpy(v->data.w1, (v->term.Ref - v->term.Fbk))) + v->data.i1;
	v->data.i1 = v->data.ui;

	/* derivative term */
	v->data.d2 = _IQmpy(v->param.Kd, _IQmpy(v->term.c1, (_IQmpy(v->term.Ref, v->param.Km) - v->term.Fbk))) - v->data.d2;
	v->data.ud = v->data.d2 + v->data.d1;
	v->data.d1 = _IQmpy(v->data.ud, v->term.c2);

	/* control output */
	v->data.v1 = _IQmpy(v->param.Kp, (v->data.up + v->data.ui + v->data.ud));
	v->term.Out= _IQsat(v->data.v1, v->param.Umax, v->param.Umin);
	v->data.w1 = (v->term.Out == v->data.v1) ? _IQ(1.0) : _IQ(0.0);
}

