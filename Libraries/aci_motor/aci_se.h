/** 
  *************************************************************************************
  * @file aci_se.h 
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

#ifndef _ACI_SE_H
#define _ACI_SE_H

//
// Included Files
//
#include "math.h"
#include "nmsis_gcc.h"
#include "nmsis_core.h"

//#include "core_feature_vcu.h"
//#include "core_feature_tmu.h"

__STATIC_FORCEINLINE float __zl_satf32(float din1, float din2, float din3)
{
  __ASM volatile("\n\tsatf32 %0, %1, %2"
  :"+f"(din1)
  :"f"(din2), "f"(din3)
  );
  return din1;
}


//
// Parameters for calculating Speed Estimator
//
typedef struct
{
	float  i_qs_se;  		 //!< Input: Stationary q-axis stator current  
	float  psi_dr_se;  	 //!< Input: Stationary d-axis rotor flux  
	float  i_ds_se;		 //!< Input: Stationary d-axis stator current  
	float  psi_qr_se;		 //!< Input: Stationary q-axis rotor flux  		
	float  K1_se;			 //!< Parameter: Constant using in speed computation  
	float  psi_r_2;     	 //!< Variable: Squared rotor flux    
	float  theta_r_se;  	 //!< Input: Rotor flux angle      		  
	float  K2_se;			 //!< Parameter: Constant using in differentiator  
	float  theta_r_old; 	 //!< Variable: Previous rotor flux angle      		  
	float  K3_se;			 //!< Parameter: Constant using in low-pass filter   
	float  wr_psi_r;		 //!< Variable: Synchronous rotor flux speed in per-unit  
	float  K4_se;			 //!< Parameter: Constant using in low-pass filter  
	float  wr_hat_se;		 //!< Output: Estimated speed in per unit  
	long  base_rpm_se; 	 //!< Parameter: Base rpm speed (Q0) - \
						                 independently with global Q 		 	 	  
	long  wr_hat_rpm_se; //!< Output: Estimated speed in rpm (Q0) - \
						              independently with global Q
} ACISE;

//
// Default initalizer for the ACISE object.
//
#define ACISE_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          (0.1f), \
                          0, \
                          0, \
                          (0.1f), \
                          0, \
                          (0.1f), \
                          0, \
                          (0.1f), \
                          0, \
                          3600.0f, \
                          0 }
						  

//
// Constants
//
#define DIFF_MAX_LIMIT  	0.97f
#define DIFF_MIN_LIMIT  	0.03f

//
// ACI rotor speed estimation calculation
//
static inline void ACISE_calc(ACISE *v)
{	
   float w_slip, w_syn;
					
   //
   // Slip computation
   //
#ifdef ZHANLU
   v->psi_r_2 = __alb_sumsqf32(v->psi_dr_se, v->psi_qr_se);
#else
   v->psi_r_2 = (v->psi_dr_se)*(v->psi_dr_se) + 
      				(v->psi_qr_se)*(v->psi_qr_se);
#endif

   w_slip = (v->K1_se)*(((v->psi_dr_se)*(v->i_qs_se) - 
   							 (v->psi_qr_se)*(v->i_ds_se)));
#ifdef ZHANLU
   w_slip = __alb_divf32(w_slip, v->psi_r_2);
#else
   w_slip = (w_slip)/(v->psi_r_2);
#endif



   //
   // Synchronous speed computation
   //
   if ((v->theta_r_se < DIFF_MAX_LIMIT)&(v->theta_r_se > DIFF_MIN_LIMIT))
   		w_syn = (v->K2_se)*((v->theta_r_se - v->theta_r_old));
   else  w_syn = v->wr_psi_r;
   
   //
   // low-pass filter
   //
   v->wr_psi_r = (v->K3_se)*(v->wr_psi_r) + (v->K4_se)*(w_syn);
    
   v->theta_r_old = v->theta_r_se;
   v->wr_hat_se = w_syn - w_slip;
 
   //
   // Saturate
   //
#ifdef ZHANLU
   v->wr_hat_se = __zl_satf32(v->wr_hat_se, 1.0f, -1.0f);
   //w_slip = divf32(w_slip, v->psi_r_2);
#else
   v->wr_hat_se = (v->wr_hat_se > ( 1.0f))? ( 1.0f):v->wr_hat_se;
   v->wr_hat_se = (v->wr_hat_se < (-1.0f))? (-1.0f):v->wr_hat_se;
#endif
   
   //
   // This operation performs long = iq * long
   //
   v->wr_hat_rpm_se = ((long)v->wr_hat_se)*((float)v->base_rpm_se);
}

#endif //_ACI_SE_H
