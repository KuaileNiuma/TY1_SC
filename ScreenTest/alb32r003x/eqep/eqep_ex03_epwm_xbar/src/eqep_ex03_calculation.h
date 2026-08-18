/**
 *************************************************************************************
 * @file eqep_ex03_calculation.h
 * @brief This file contains the header file for example eqep_ex03_calculation.
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

#ifndef DEVICE_EQEP_EX03_CALCULATION_H_
#define DEVICE_EQEP_EX03_CALCULATION_H_

//#include "IQmathLib.h"
#include "device.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************

typedef   long    _iq;                  //!< IQ math type definition

typedef struct
{
    uint32_t freqScalerPR;  //!< Parameter: Scaler converting 1/N cycles to a GLOBAL_Q freq (Q0)
    uint32_t freqScalerFR;  //!< Parameter: Scaler converting 1/N cycles to a GLOBAL_Q freq (Q0)
    uint32_t baseFreq;      //!< Parameter: Maximum frequency

    _iq freqPR;             //!< Output: Frequency in per-unit using capture unit
    int32_t freqHzPR;       //!< Output: Frequency in Hz, measured using capture method
    uint32_t oldPos;        //!< Variable: Previous position value

    _iq freqFR;             //!< Output: Frequency in per-unit using position counter
    int32_t freqHzFR;       //!< Output: Frequency in Hz, measured using frequency method
} FreqCal_Object;

typedef FreqCal_Object *FreqCal_Handle; //!< FreqCal object handle type
#define myEQEP_BASE EQEP1_BASE                    //!< eQEP module base address

//*****************************************************************************
//
// Frequency calculation function using eQEP module
//
//*****************************************************************************
void eqep_ex03_FreqCal_calculate(FreqCal_Handle handle, uint32_t *count);


#ifdef __cplusplus
}
#endif


#endif 

