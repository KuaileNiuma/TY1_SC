/** 
  *************************************************************************************
  * @file parameter.h 
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

#ifndef _PARAMETER_H
#define _PARAMETER_H

/**
 * @brief Define the samping period for simulation (sec) 
 * 
 */
#define SAMPLING_PERIOD 0.0005f

/**
 * @brief Define the Induction motor parameters 
 * 
 */
#define RS_VALUE 	  1.723f               //!< Stator resistance (ohm)
#define RR_VALUE   	2.011f               //!< Rotor resistance (ohm)
#define LS_VALUE   	0.166619f     		//!< Stator inductance (H)
#define LR_VALUE   	0.168964f			//!< Rotor inductance (H)
#define LM_VALUE   	0.159232f			//!< Rotor inductance (H)
#define P_VALUE    	4.0f					//!< Number of poles

/**
 * @brief Define the mechanical parameters 
 * 
 */
#define BB_VALUE	0.0001f     			//!< Damping coefficient (N.m.sec/rad)
#define JJ_VALUE	0.001f				//!< Moment of inertia of rotor mass (kg.m^2)
#define TL_VALUE  0    				//!< Load torque (N.m)

/**
 * @brief Define the base quantites 
 * 
 */
#define BASE_VOLTAGE    184.752f       //!< Base peak phase voltage (volt)
#define BASE_CURRENT    5.0f             //!< Base peak phase current (amp)
#define BASE_TORQUE     7.35105194f    //!< Base torque (N.m)
#define BASE_FLUX       0.79616f       //!< Base flux linkage (volt.sec/rad)
#define BASE_FREQ      	60.0f            //!< Base electrical frequency (Hz)

void aci_ctrlLoop(void);

#endif  // _PARAMETER.H
