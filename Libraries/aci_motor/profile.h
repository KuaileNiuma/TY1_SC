/** 
  *************************************************************************************
  * @file profile.h 
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

#ifndef _PROFILE_H
#define _PROFILE_H

//
// Include files
//
#include    "stdint.h"

#include "../aci_motor/device_profile.h"

//
// Instances of application benchmarking datastructures
//
#define BMRK_INSTANCES 15

//
// Benchmarking datastructure declarations
//
extern volatile uint32_t Bmrk_Start;
extern volatile uint32_t Bmrk_End;
extern volatile uint32_t Bmrk_Cyc[BMRK_INSTANCES];
extern volatile uint32_t Bmrk_Sum[BMRK_INSTANCES];
extern volatile uint32_t Bmrk_Max[BMRK_INSTANCES];
extern volatile uint32_t Bmrk_Min[BMRK_INSTANCES];
extern volatile uint32_t Bmrk_Count[BMRK_INSTANCES];
extern volatile uint32_t Bmrk_Adjust;

extern volatile uint32_t IOBmrk_End;
extern volatile uint32_t IOBmrk_Cyc;
extern volatile uint32_t IOBmrk_Sum;
extern volatile uint32_t IOBmrk_Max;
extern volatile uint32_t IOBmrk_Min;
extern volatile uint32_t IOBmrk_Count;

extern volatile uint32_t Bmrk_TotalAvg;
extern volatile uint32_t Bmrk_TotalMin;
extern volatile uint32_t Bmrk_TotalMax;

//
// Function definitions
// These device specific implementations
//
extern void Bmrk_start(void);
extern void Bmrk_end(void);
extern void Bmrk_calibrate(void);
extern void Bmrk_init(void);
extern void IOBmrk_end(void);
extern void IOBmrk_init(void);

//
// Defines for printing benchmark results
//
#define BMRK_READ_ADC_CONV_FLOAT 1
#define BMRK_CLARKE_TRANSFORM 2
#define BMRK_PID_TRANSFORM 3
#define BMRK_IPARK_TRANSFORM 4
#define BMRK_ACI_MODEL 5
#define BMRK_FE_TRANSFORM 6
#define BMRK_SE_TRANSFORM 7
#define BMRK_PARK_TRANSFORM 8
#define BMRK_SVGEN 9
#define BMRK_PWM_WRITE 10

#endif  // _PROFILE_H
