/** 
  *************************************************************************************
  * @file MPPT_PNO_F.c 
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

#include "Solar_F.h"

//*********** Structure Init Function ****//
void MPPT_PNO_F_init(MPPT_PNO_F *v)
{
	v->Ipv=0;
	v->Vpv=0;
	v->DeltaPmin=(0.00001);
	v->MaxVolt=(0.9);
	v->MinVolt=0;
	v->Stepsize=(0.002);
	v->VmppOut=0;
	v->DeltaP=0;
	v->PanelPower=0;
	v->PanelPower_Prev=0;
	v->mppt_enable=1;
	v->mppt_first=1;
}

//*********** Function Definition ********//
void MPPT_PNO_F_FUNC(MPPT_PNO_F *v)
{
	if (v->mppt_enable==1)
		{
			if (v->mppt_first == 1)
			{
				v->VmppOut= v->Vpv - (0.02);
				v->mppt_first=0;
				v->PanelPower_Prev=v->PanelPower;
			}
			else
			{
				v->PanelPower=(v->Vpv*v->Ipv);
				v->DeltaP=v->PanelPower-v->PanelPower_Prev;
				if (v->DeltaP > v->DeltaPmin)
				{
					v->VmppOut=v->Vpv+v->Stepsize;
				}
				else
				{
					if (v->DeltaP < -v->DeltaPmin)
					{
						v->Stepsize=-v->Stepsize;
						v->VmppOut=v->Vpv+v->Stepsize;
					}
				}
				v->PanelPower_Prev = v->PanelPower;
			}
			if(v->VmppOut < v->MinVolt) v->VmppOut = v->MinVolt;
			if(v->VmppOut > v->MaxVolt) v->VmppOut = v->MaxVolt;
		}
}
