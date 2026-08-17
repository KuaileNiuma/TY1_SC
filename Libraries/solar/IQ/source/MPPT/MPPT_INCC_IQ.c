/** 
  *************************************************************************************
  * @file MPPT_INCC_IQ.c 
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
void MPPT_INCC_IQ_init(MPPT_INCC_IQ *v)
{
	v->Ipv=_IQ(0.0);
	v->Vpv=_IQ(0.0);
	v->IpvH=_IQ(1.65);
	v->IpvL=_IQ(0.0);
	v->VpvH=_IQ(0.0);
	v->VpvL=_IQ(0.0);
	v->MaxVolt=_IQ(0.0);
	v->MinVolt=_IQ(0.0);
	v->Stepsize=_IQ(0.0);
	v->VmppOut=_IQ(0.0);
	v->Cond=_IQ(0.0);
	v->IncCond=_IQ(0.0);
	v->DeltaV=_IQ(0.0);
	v->DeltaI=_IQ(0.0);
	v->VpvOld=_IQ(0.0);
	v->IpvOld=_IQ(0.0);
	v->StepFirst=_IQ(0.02);
	v->mppt_enable=1;
	v->mppt_first=1;
}

//*********** Function Definition ********//
void MPPT_INCC_IQ_FUNC(MPPT_INCC_IQ *v)
{
	if (v->mppt_enable==1)
	{	/*MPPT mode enable*/
		if (v->mppt_first == 1)
		{
			v->VmppOut= v->Vpv - v->StepFirst;
	    	v->VpvOld=v->Vpv;
	    	v->IpvOld=v->Ipv;
			v->mppt_first=0;
		}
		else
		{
			v->DeltaV = v->Vpv-v->VpvOld ; 				/* PV voltage change */
	    	v->DeltaI = v->Ipv-v->IpvOld ; 				/* PV current change */
//	   		if(v->DeltaV < v->VpvH && v->DeltaV > -v->VpvL )  /* Tolerence limits PV Voaltge Variation */
//	    	v->DeltaV= 0;
//	   		if(v->DeltaI < v->IpvH && v->DeltaI > -v->IpvL )  /* Tolerence limits PV current Variation */
//	    	v->DeltaI = 0;
	    	if(v->DeltaV == 0)    						/* DeltaV=0 */
			{
				if(v->DeltaI !=0 )    					/* dI=0 operating at MPP */
				{
					if ( v->DeltaI > 0 )  				/* climbing towards MPP */
					{v->VmppOut=v->Vpv+v->Stepsize;}		/* Increment Vref */
					else
					{v->VmppOut=v->Vpv-v->Stepsize;} 	 	/* Decrement Vref */
				}
			}
	    	else
			{
	    	 	v->Cond = _IQdiv(v->Ipv, v->Vpv);			/*Cond =-(v->Ipv<<10)/v->Vpv;*/
	    	 	v->IncCond = _IQdiv(v->DeltaI, v->DeltaV);	/*IncCond =(DeltaI<<10)/DeltaV;*/
	       		if (v->IncCond != v->Cond)			/* Operating at MPP */
				{
					if (v->IncCond > (-v->Cond))		/* left of MPP */
					{
					v->VmppOut=v->Vpv+v->Stepsize;		/* change Vref */
					}
					else							/* Right of MPP */
					{
					v->VmppOut=v->Vpv-v->Stepsize;		/* change Vref */
					}
	        	}
			}
		/*	if (v->VmppOut<v->MinVolt) v->VmppOut=v->MinVolt;	 Min. MPP Voltage	*/
		/*	if (v->VmppOut>v->MaxVolt) v->VmppOut=v->MaxVolt; 	 Max. MPP Voltage	*/
			v->VpvOld = v->Vpv;
			v->IpvOld = v->Ipv;
		}
	}
}

