/** 
  *************************************************************************************
  * @file pid_reg3.h 
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

#ifndef _PID_REG3_H
#define _PID_REG3_H

#include "math.h"
#include "core_feature_vcu.h"


//
// PID Controller Parameters
//
typedef struct
{  
	float  pid_ref_reg3;   	//!< Input: Reference input 
	float  pid_fdb_reg3;   	//!< Input: Feedback input 
	float  e_reg3;			//!< Variable: Error   
	float  Kp_reg3;			//!< Parameter: Proportional gain 
	float  up_reg3;			//!< Variable: Proportional output 
	float  ui_reg3;			//!< Variable: Integral output   
	float  ud_reg3;			//!< Variable: Derivative output   	
	float  uprsat_reg3; 	    //!< Variable: Pre-saturated output 
	float  pid_out_max;		//!< Parameter: Maximum output   
	float  pid_out_min;		//!< Parameter: Minimum output   
	float  pid_out_reg3;   	//!< Output: PID output   
	float  saterr_reg3;		//!< Variable: Saturated difference
	float  Ki_reg3;			//!< Parameter: Integral gain  
	float  Kc_reg3;			//!< Parameter: Integral correction gain 
	float  Kd_reg3; 		    //!< Parameter: Derivative gain  
	float  up1_reg3;		    //!< History: Previous proportional output
} PIDREG3;

//
// Default initializer for the PIDREG3 object.
//
#define PIDREG3_DEFAULTS { 0, \
                           0, \
                           0, \
                           (1.3f), \
                           0, \
                           0, \
                           0, \
                           0, \
                           (1.0f), \
                           (-1.0f), \
                           0, \
                           0, \
                           (0.02f), \
                           (0.5f), \
                           (1.05f), \
                           0, \
              			 }

//
// PID Controller calculations
//
static inline void PIDREG3_calc(PIDREG3 *v)
{	
    float temp_out;

    v->e_reg3 = v->pid_ref_reg3 - v->pid_fdb_reg3;
    
    v->up_reg3 = (v->Kp_reg3)*(v->e_reg3);
    
    v->uprsat_reg3 = v->up_reg3 + v->ui_reg3 + v->ud_reg3;
    
    temp_out = v->uprsat_reg3;
#if ZHANLU
    temp_out = __alb_satf32(temp_out, v->pid_out_max, v->pid_out_min);
#else
   // Use Lib
   temp_out = (temp_out > v->pid_out_max)? v->pid_out_max:temp_out;
   temp_out = (temp_out < v->pid_out_min)? v->pid_out_min:temp_out;
#endif
//    temp_out = (temp_out > v->pid_out_max)? v->pid_out_max:temp_out;
//    temp_out = (temp_out < v->pid_out_min)? v->pid_out_min:temp_out;
    v->pid_out_reg3 = temp_out;
      
    v->saterr_reg3 = temp_out - v->uprsat_reg3;
    
    v->ui_reg3 = v->ui_reg3 + (v->Ki_reg3)*(v->up_reg3) + 
                (v->Kc_reg3)*(v->saterr_reg3);
    
    v->ud_reg3 = (v->Kd_reg3)*((v->up_reg3 - v->up1_reg3));
     
    v->up1_reg3 = v->up_reg3;
}

#endif //_PID_REG3_H
