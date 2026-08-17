/**
 *************************************************************************************
 * @file eqep_ex02_calculation.h
 * @brief This file contains the header file for example eqep_ex02_calculation.
 * @version 1.0.0
 *************************************************************************************
 * @copyright Copyright (c) 2025 Albatross Semiconductor(Hangzhou) Co.,Ltd.
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

#ifndef DEVICE_EQEP_EX02_CALCULATION_H_
#define DEVICE_EQEP_EX02_CALCULATION_H_

//#include "IQmathLib.h"
#include "device.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************

typedef   long    _iq;                  //!< IQ math type definition

typedef struct {
    int16_t thetaElec;      //!< Output: Motor electrical angle (Q15)
    int16_t thetaMech;      //!< Output: Motor mechanical angle (Q15)
    int16_t directionQEP;   //!< Output: Motor rotation direction (Q0)
    int16_t thetaRaw;       //!< Variable: Raw angle from timer 2 (Q0)
    int16_t mechScaler;     //!< Parameter: 0.9999 / total count, total count = 4000 (Q26)
    int16_t polePairs;      //!< Parameter: Number of pole pairs (Q0)
    int16_t calAngle;       //!< Parameter: Raw angular offset between encoder and Phase A (Q0)

    uint32_t speedScaler;   //!< Parameter: Scaler converting 1/N cycles to a GLOBAL_Q speed (Q0)
    _iq speedPR;            //!< Output: Speed in per-unit (capture method)
    uint32_t baseRPM;       //!< Parameter: Scaler converting GLOBAL_Q speed to rpm (Q0) speed
    int16_t speedRPMPR;     //!< Output: Speed in rpm (Q0) - capture method

    _iq oldPos;             //!< Variable: Previous position value for speed calculation
    _iq speedFR;            //!< Output: Speed in per-unit (frequency method)
    int16_t speedRPMFR;     //!< Output: Speed in rpm (Q0) - frequency method
	_iq newPos;             //!< Variable: New position value for speed calculation
} PosSpeed_Object;

typedef PosSpeed_Object *PosSpeed_Handle;     //!< PosSpeed object handle type


#define myEQEP_BASE EQEP1_BASE                 //!< eQEP module base address

void eqep_ex02_PosSpeed_calculate(PosSpeed_Handle handle, uint32_t *timer, uint32_t myEQEP0_BASE);



#ifdef __cplusplus
}
#endif


#endif 

