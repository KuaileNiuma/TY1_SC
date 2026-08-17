/** 
  *************************************************************************************
  * @file aci_fe.h 
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

#ifndef _ACI_FE_H
#define _ACI_FE_H

#include "math.h"
#include "core_feature_vcu.h"
#include "core_feature_tmu.h"

//
// Parameters needed for Flux Estimator calculations
//
typedef struct
{  
    float  theta_r_fe; //!< Output: Rotor flux angle 
    float  i_qs_fe;	 //!< Input: Stationary q-axis stator current  
    float  i_ds_fe;    //!< Input: Stationary d-axis stator current  
    float  K1_fe;      //!< Parameter: Constant using in current model 
    float  flx_dr_e;   //!< Variable: Rotating d-axis rotor flux (current model)  
    float  K2_fe;      //!< Parameter: Constant using in current model  
    float  flx_qr_s;   //!< Variable: Stationary q-axis rotor flux (current model)  
    float  flx_dr_s;   //!< Variable: Stationary d-axis rotor flux (current model)  
    float  K3_fe;      //!< Parameter: Constant using in stator flux computation  
    float  K4_fe;      //!< Parameter: Constant using in stator flux computation 
    float  flx_ds_s;   //!< Variable: Stationary d-axis stator flux (current model)  
    float  flx_qs_s;   //!< Variable: Stationary q-axis stator flux (current model)  
    float  psi_ds_fe;  //!< Variable: Stationary d-axis stator flux (voltage model)  
    float  Kp_fe;      //!< Parameter: PI proportionnal gain  
    float  ui_ds;      //!< Variable: Stationary d-axis _iqegral term  
    float  ucomp_ds;   //!< Variable: Stationary d-axis compensated voltage  
    float  Ki_fe;      //!< Parameter: PI _iqegral gain  
    float  psi_qs_fe;  //!< Variable: Stationary q-axis stator flux (voltage model)  
    float  ui_qs;      //!< Variable: Stationary q-axis _iqegral term  
    float  ucomp_qs;   //!< Variable: Stationary q-axis compensated voltage  
    float  emf_ds;     //!< Variable: Stationary d-axis back emf  
    float  u_ds_fe;    //!< Input: Stationary d-axis stator voltage  
    float  K5_fe;      //!< Parameter: Constant using in back emf computation  
    float  K6_fe;      //!< Parameter: Constant using in back emf computation  
    float  emf_qs;     //!< Variable: Stationary q-axis back emf  
    float  u_qs_fe;    //!< Input: Stationary q-axis stator voltage  
    float  K8_fe;      //!< Parameter: Constant using in rotor flux computation  
    float  K7_fe;      //!< Parameter: Constant using in rotor flux computation  
    float  psi_dr_fe;	 //!< Output: Stationary d-axis estimated rotor flux 
    float  psi_qr_fe;	 //!< Output: Stationary q-axis estimated rotor flux
} ACIFE;

//
// Default initalizer for the ACIFE object.
//
#define ACIFE_DEFAULTS {  0,    /*  theta_r_fe  */  \
                          0,    /*  i_qs_fe  */     \
                          0,    /*  i_ds_fe  */     \
                          0,    /*  K1_fe */       \
                          0,    /*  flx_dr_e  */    \
                          0,    /*  K2_fe  */       \
                          0,    /*  flx_dr_s  */    \
                          0,    /*  flx_qr_s  */    \
                          0,    /*  K3_fe  */       \
                          0,    /*  K4_fe  */       \
                          0,    /*  flx_ds_s  */    \
                          0,    /*  flx_qs_s  */    \
                          0,    /*  psi_ds_fe  */   \
                          0,    /*  Kp_fe  */       \
                          0,    /*  ui_ds  */    \
                          0,    /*  ucomp_ds  */    \
                          0,    /*  Ki_fe  */ \
                          0,    /*  psi_qs_fe  */   \
                          0,    /*  ui_qs  */    \
                          0,    /*  ucomp_qs  */    \
                          0,    /*  emf_ds  */      \
                          0,    /*  u_ds_fe  */     \
                          0,    /*  K5_fe  */       \
                          0,    /*  K6_fe  */       \
                          0,    /*  emf_qs  */      \
                          0,    /*  u_qs_fe  */     \
                          0,    /*  K8_fe  */       \
                          0,    /*  K7_fe  */       \
                          0,    /*  psi_dr_fe  */   \
                          0,	/*  psi_qr_fe  */   }

//
// Constants
//
#define TWO_PI_FE    6.28318530717959f
#define INV_2PI   0.15915494309190f


//
// ACI motor flux estimator calculation
//

static inline void ACIFE_calc(ACIFE *v)
{
   float i_ds_e, error, emf_old;
   
   //
   // Park transformation on the measured stator current
   //
   // Use Zhanlu
#ifdef ZHANLU
   i_ds_e  = v->i_qs_fe * __alb_sinpuf32(v->theta_r_fe);
   i_ds_e += v->i_ds_fe * __alb_cospuf32(v->theta_r_fe);
#else
   // Use Lib
   i_ds_e  = v->i_qs_fe * sinf((v->theta_r_fe)*TWO_PI_FE);
   i_ds_e += v->i_ds_fe * cosf((v->theta_r_fe)*TWO_PI_FE);
#endif
   
   //
   // The current model section (Classical Rotor Flux Vector Control Equation)
   //
   v->flx_dr_e = (v->K1_fe)*(v->flx_dr_e) - (v->K2_fe)*(i_ds_e);

   //
   // Inverse park transformation on the rotor flux from the current model
   //
#ifdef ZHANLU
   // Use TMU
   v->flx_dr_s = v->flx_dr_e * __alb_cospuf32(v->theta_r_fe);
   v->flx_qr_s = v->flx_dr_e * __alb_sinpuf32(v->theta_r_fe);
#else
   // Use Lib
   v->flx_dr_s = v->flx_dr_e * sinf((v->theta_r_fe)*TWO_PI_FE);
   v->flx_qr_s = v->flx_dr_e * cosf((v->theta_r_fe)*TWO_PI_FE);
#endif
   
   //
   // Compute the stator flux based on the rotor flux from current model
   //
   v->flx_ds_s = (v->K3_fe)*(v->flx_dr_s) + (v->K4_fe)*(v->i_ds_fe);	
   v->flx_qs_s = (v->K3_fe)*(v->flx_qr_s) + (v->K4_fe)*(v->i_qs_fe);
   
   //
   // Conventional PI controller section
   //
   error =  v->psi_ds_fe - v->flx_ds_s;
   v->ucomp_ds = (v->Kp_fe*error) + v->ui_ds;
   v->ui_ds = (v->Kp_fe)*((v->Ki_fe)*(error)) + v->ui_ds;
   
   error =  v->psi_qs_fe - v->flx_qs_s;
   v->ucomp_qs = (v->Kp_fe)*(error) + v->ui_qs;
   v->ui_qs = (v->Kp_fe)*((v->Ki_fe)*(error)) + v->ui_qs;
   
   //
   // Compute the estimated stator flux based on the integral of back emf
   //
   emf_old = v->emf_ds;
   v->emf_ds = v->u_ds_fe - v->ucomp_ds - (v->K5_fe)*(v->i_ds_fe);
   v->psi_ds_fe = v->psi_ds_fe +
                  ((float)(0.5f))*((v->K6_fe)*((v->emf_ds + emf_old))); 

   emf_old = v->emf_qs;
   v->emf_qs = v->u_qs_fe - v->ucomp_qs - (v->K5_fe)*(v->i_qs_fe);
   v->psi_qs_fe = v->psi_qs_fe +
                  ((float)(0.5f))*((v->K6_fe)*((v->emf_qs + emf_old)));
   //
   // Compute the estimated rotor flux based on the stator flux
   // from the integral of back emf
   //
   v->psi_dr_fe = (v->K7_fe)*(v->psi_ds_fe) - (v->K8_fe)*(v->i_ds_fe);  
   v->psi_qr_fe = (v->K7_fe)*(v->psi_qs_fe) - (v->K8_fe)*(v->i_qs_fe);
   
   //
   // Compute the rotor flux angle
   //
#ifdef ZHANLU
   v->theta_r_fe =  __alb_atanpuf32(__alb_atan2divf32(v->psi_qr_fe,v->psi_dr_fe)) + __alb_atan2quadf32(v->psi_qr_fe,v->psi_dr_fe);
#else
   v->theta_r_fe = (atan2f(v->psi_qr_fe,v->psi_dr_fe))*(INV_2PI);
#endif

   //
   // (PI,-PI)/(2*PI) -> (0, 2*PI)/(2*PI)
   //
#ifdef ZHANLU
   if (v->theta_r_fe < 0)
     v->theta_r_fe = __alb_add1f32(v->theta_r_fe);
#else
   if (v->theta_r_fe < 0)
     v->theta_r_fe = 1.0f + v->theta_r_fe;
#endif
}
#endif
