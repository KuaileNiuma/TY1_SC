/** 
  *************************************************************************************
  * @file MPPT_INCC_I_F.c 
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
void MPPT_INCC_I_F_init(MPPT_INCC_I_F *v)
{
	v->Ipv=0;
	v->Vpv=0;
	v->IpvH=(1.65);
	v->IpvL=0;
	v->VpvH=0;
	v->VpvL=0;
	v->MaxI=0;
	v->MinI=0;
	v->Stepsize=0;
	v->ImppOut=0;
	v->Cond=0;
	v->IncCond=0;
	v->DeltaV=0;
	v->DeltaI=0;
	v->VpvOld=0;
	v->IpvOld=0;
	v->StepFirst=(0.02);
	v->mppt_enable=1;
	v->mppt_first=1;
}

//*********** Function Definition ********//
void MPPT_INCC_I_F_FUNC(MPPT_INCC_I_F *v)
{
	if (v->mppt_enable==1)
	{	/*MPPT mode enable*/
		if (v->mppt_first == 1)
		{
			v->ImppOut= v->Ipv + v->StepFirst;
	    	v->VpvOld=v->Vpv;
	    	v->IpvOld=v->Ipv;
			v->mppt_first=0;
		}
		else
		{
			v->DeltaV = v->Vpv-v->VpvOld ; 				/* PV voltage change */
	    	v->DeltaI = v->Ipv-v->IpvOld ; 				/* PV current change */
//	   		if(v->DeltaV <v->VpvH && v->DeltaV >-v->VpvL )  /* Tolerence limits PV Voaltge Variation */
//	    	v->DeltaV= 0;
//	   		if(v->DeltaI <v->IpvH && v->DeltaI >-v->IpvL )  /* Tolerence limits PV current Variation */
//	    	v->DeltaI = 0;
	    	if(v->DeltaV >= 0)    						/* DeltaV=0 */
			{
				if(v->DeltaI !=0 )    					/* dI=0 operating at MPP */
				{
					if ( v->DeltaI > 0 )  				/* climbing towards MPP */
					{v->ImppOut=v->Ipv-v->Stepsize;}		/* Increment Vref */
					else
					{v->ImppOut=v->Ipv+v->Stepsize;} 		/* Decrement Vref */
				}
			}
	    	else
			{
	    	 	v->Cond = v->Ipv*__einvf32(v->Vpv);				/*Cond =-(v->Ipv<<10)/v->Vpv;*/
	    	 	v->IncCond = v->DeltaI*__einvf32(v->DeltaV);	/*IncCond =(DeltaI<<10)/DeltaV;*/
	       		if (v->IncCond != v->Cond)			/* Operating at MPP */
				{
					if (v->IncCond > (-v->Cond))		/* left of MPP */
					{
					v->ImppOut=v->Ipv-v->Stepsize;		/* change Vref */
					}
					else							/* Right of MPP */
					{
					v->ImppOut=v->Ipv+v->Stepsize;		/* change Vref */
					}
	        	}
			}
		    v->ImppOut=(v->ImppOut<v->MinI)?v->MinI: v->ImppOut;	 /*Min. MPP Current */
			v->ImppOut=(v->ImppOut>v->MaxI)?v->MaxI: v->ImppOut;  /*Max. MPP Current	*/
			v->VpvOld = v->Vpv;
			v->IpvOld = v->Ipv;
		}
	}
}

