/** 
  *************************************************************************************
  * @file aci.h 
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

#ifndef _ACI_H
#define _ACI_H

#include "math.h"
#include "core_feature_vcu.h"
#include "core_feature_tmu.h"

//
// ACI Model parameters
//

typedef struct
{ 
	float  ualfa; 		//!< Input: alfa-axis phase voltage at k  
	float  ubeta;			//!< Input: beta-axis phase voltage at k  
	float  load_torque;	//!< Input: load torque  	  			      
	float  ialfa;			//!< Output: alfa-axis phase current at k  			
	float  ibeta;			//!< Output: beta-axis phase current at k  
	float  psi_r_alfa; 	//!< Output: alfa-axis rotor flux at k  		
	float  psi_r_beta;	//!< Output: beta-axis rotor flux at k  					  
	float  torque; 		//!< Output: electromagnetic torque at k  		
	float  wr;			//!< Output: electrically angular velocity of motor  
	long   wr_rpm; 		//!< Output: motor speed in rpm  (Q0) - \
									 independently with global Q 
	float  K1;			//!< Parameter: constant using in rotor flux calculation  
	float  K2;			//!< Parameter: constant using in rotor flux calculation  
	float  K3;			//!< Parameter: constant using in rotor flux calculation  
	float  K4;			//!< Parameter: constant using in stator current \
										calculation  
	float  K5;			//!< Parameter: constant using in stator current \
										calculation  
	float  K6;			//!< Parameter: constant using in stator current \
										calculation  
	float  K7;			//!< Parameter: constant using in stator current \
										calculation  
	float  K8;			//!< Parameter: constant using in torque calculation  
	float  K9;			//!< Parameter: constant using in rotor speed calculation  
	float  K10;			//!< Parameter: constant using in rotor speed calculation  			      
	long   base_rpm;		//!< Parameter: base motor speed in rpm (Q0) - \
										independently with global Q 	  			      
	float  alpha;			//!< Parameter: trapezoidal integration parameter
} ACI;

//
// Default initalizer for the ACI object.
//
#define ACI_DEFAULTS { 0,0,0, \
                       0,0,0,0,0,0,0, \
 		          	   (0.000595097f),(0.037699112f),(0.000994357f),(0.003227603f),(0.204467f), \
 		          	   (0.010596f),(0.093444628f),(1.094054741f),(0.005f),(0.00816532f), \
 		          	   3600.0f, (0.01f) }


//
// ACI motor modelling calculations
//

static inline void ACI_calc(ACI *v)
{	
  float psi_r_alfa_p, psi_r_beta_p, ialfa_p, ibeta_p;
	float dpsi_r_alfa_p, dpsi_r_beta_p, dialfa_p, dibeta_p;
	float dpsi_r_alfa, dpsi_r_beta, dialfa, dibeta;
	float wr_p, dwr_p, dwr;

    //
    // Rotor flux/Stator current calculation
    //

	//
    // Predictor
	//
    psi_r_beta_p = v->psi_r_beta - (v->K1)*(v->psi_r_beta) + ((v->K2)*(v->wr))*(v->psi_r_alfa) + (v->K3)*(v->ibeta);
    psi_r_alfa_p = v->psi_r_alfa - (v->K1)*(v->psi_r_alfa) - ((v->K2)*(v->wr))*(v->psi_r_beta) + (v->K3)*(v->ialfa);
    ibeta_p = v->ibeta + (v->K4)*(v->psi_r_beta) - ((v->K5)*(v->wr))*(v->psi_r_alfa) - (v->K6)*(v->ibeta) + (v->K7)*(v->ubeta);
    ialfa_p = v->ialfa + (v->K4)*(v->psi_r_alfa) + ((v->K5)*(v->wr))*(v->psi_r_beta) - (v->K6)*(v->ialfa) + (v->K7)*(v->ualfa);

    //
    // Corrector
    //
    dpsi_r_beta_p = - (v->K1)*(psi_r_beta_p) + ((v->K2)*(v->wr))*(psi_r_alfa_p) + (v->K3)*(ibeta_p);
    dpsi_r_alfa_p = - (v->K1)*(psi_r_alfa_p) - ((v->K2)*(v->wr))*(psi_r_beta_p) + (v->K3)*(ialfa_p);
    dibeta_p = (v->K4)*(psi_r_beta_p) - ((v->K5)*(v->wr))*(psi_r_alfa_p) - (v->K6)*(ibeta_p) + (v->K7)*(v->ubeta);
    dialfa_p = (v->K4)*(psi_r_alfa_p) + ((v->K5)*(v->wr))*(psi_r_beta_p) - (v->K6)*(ialfa_p) + (v->K7)*(v->ualfa);
  
    dpsi_r_beta = psi_r_beta_p - v->psi_r_beta;
    dpsi_r_alfa = psi_r_alfa_p - v->psi_r_alfa;
    dibeta = ibeta_p - v->ibeta;
    dialfa = ialfa_p - v->ialfa;

#ifdef ZHANLU
    v->psi_r_beta = v->psi_r_beta + ((0.5f))*((((__alb_add1f32(v->alpha)))*(dpsi_r_beta_p) + ((__alb_nadd1f32(v->alpha)))*(dpsi_r_beta)));
    v->psi_r_alfa = v->psi_r_alfa + ((0.5f))*((((__alb_add1f32(v->alpha)))*(dpsi_r_alfa_p) + ((__alb_nadd1f32(v->alpha)))*(dpsi_r_alfa)));

    v->ibeta = v->ibeta + ((0.5f))*((((__alb_add1f32(v->alpha)))*(dibeta_p) + ((__alb_nadd1f32(v->alpha)))*(dibeta)));
    v->ialfa = v->ialfa + ((0.5f))*((((__alb_add1f32(v->alpha)))*(dialfa_p) + ((__alb_nadd1f32(v->alpha)))*(dialfa)));
#else
    v->psi_r_beta = v->psi_r_beta + ((0.5f))*(((((1)+v->alpha))*(dpsi_r_beta_p) + (((1)-v->alpha))*(dpsi_r_beta)));
    v->psi_r_alfa = v->psi_r_alfa + ((0.5f))*(((((1)+v->alpha))*(dpsi_r_alfa_p) + (((1)-v->alpha))*(dpsi_r_alfa)));

    v->ibeta = v->ibeta + ((0.5f))*(((((1.0f)+v->alpha))*(dibeta_p) + (((1.0f)-v->alpha))*(dibeta)));
     v->ialfa = v->ialfa + ((0.5f))*(((((1.0f)+v->alpha))*(dialfa_p) + (((1.0f)-v->alpha))*(dialfa)));
#endif
    //
    // Electromagnetic torque calculation
    //
    v->torque = (v->K8)*(((v->psi_r_alfa)*(v->ibeta) - (v->psi_r_beta)*(v->ialfa)));

    //
    // Rotor speed calculation
    //
    wr_p = v->wr - (v->K9)*(v->wr) + (v->K10)*((v->torque - v->load_torque));

    dwr_p = - (v->K9)*(wr_p) + (v->K10)*((v->torque - v->load_torque));

    dwr = wr_p - v->wr;
#ifdef ZHANLU
    v->wr = v->wr + ((0.5f))*((((__alb_add1f32(v->alpha)))*(dwr_p) + ((__alb_nadd1f32(v->alpha)))*(dwr)));
#else
    v->wr = v->wr + ((0.5f))*(((((1.0f)+v->alpha))*(dwr_p) + (((1)-v->alpha))*(dwr)));
#endif

    v->wr_rpm = ((long)v->wr)*((float)v->base_rpm);    // This operation performs long = iq * long
}

#endif //_ACI_H









