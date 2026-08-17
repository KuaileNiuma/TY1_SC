/** 
  *************************************************************************************
  * @file MPPT_PNO_IQ.h 
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

#ifndef MPPT_PNO_IQ_H_
#define MPPT_PNO_IQ_H_

//*********** Structure Definition ********//
typedef struct {
	int32  Ipv;
	int32  Vpv;
	int32  DeltaPmin;
	int32  MaxVolt;
	int32  MinVolt;
	int32  Stepsize;
	int32  VmppOut;
	int32  DeltaP;
	int32  PanelPower;
	int32  PanelPower_Prev;
	int16 mppt_enable;
	int16 mppt_first;
} MPPT_PNO_IQ;

typedef MPPT_PNO_IQ *MPPT_PNO_handle;

//*********** Function Declarations *******//
void MPPT_PNO_IQ_init(MPPT_PNO_IQ *v);
void MPPT_PNO_IQ_FUNC(MPPT_PNO_IQ *v);

//*********** Macro Definition ***********//
#define MPPT_PNO_IQ_MACRO(v)						\
if (v.mppt_enable==1)								\
{													\
	if (v.mppt_first == 1)							\
	{												\
		v.VmppOut= v.Vpv - _IQ(0.02);				\
		v.mppt_first=0;								\
		v.PanelPower_Prev=v.PanelPower;				\
	}												\
	else											\
	{												\
		v.PanelPower= _IQmpy(v.Vpv,v.Ipv);			\
		v.DeltaP=v.PanelPower-v.PanelPower_Prev;	\
		if (v.DeltaP > v.DeltaPmin)					\
		{											\
			v.VmppOut=v.Vpv+v.Stepsize;				\
		}											\
		else										\
		{											\
			if (v.DeltaP < -v.DeltaPmin)			\
			{										\
				v.Stepsize=-v.Stepsize;				\
				v.VmppOut=v.Vpv+v.Stepsize;			\
			}										\
		}											\
		v.PanelPower_Prev = v.PanelPower;			\
	}												\
	if(v.VmppOut< v.MinVolt) v.VmppOut = v.MinVolt;	\
	if(v.VmppOut> v.MaxVolt) v.VmppOut= v.MaxVolt;	\
}	


#endif /*MPPT_PNO_IQ_H_*/
