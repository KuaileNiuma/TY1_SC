/** 
  *************************************************************************************
  * @file device_profile.h 
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

#ifndef _DEVICE_PROFILE_H
#define _DEVICE_PROFILE_H

//
// Application benchmark calculation
//
#define Bmrk_calc(n)            Bmrk_Cyc[n-1] = ((Bmrk_End - Bmrk_Start) - Bmrk_Adjust);        \
                                Bmrk_Sum[n-1] += Bmrk_Cyc[n-1];                                     \
                                Bmrk_Max[n-1] = (Bmrk_Cyc[n-1] > Bmrk_Max[n-1])? Bmrk_Cyc[n-1]:Bmrk_Max[n-1];   \
                                Bmrk_Min[n-1] = (Bmrk_Cyc[n-1] < Bmrk_Min[n-1])? Bmrk_Cyc[n-1]:Bmrk_Min[n-1];   \
                                Bmrk_Count[n-1]++;

//
// IO response time calculation (interrupt trigger to ISR entry)

//
// Note: The IO response is inferred from the PWM counter value.
// The PWM triggers ADC read when the PWM counter reaches max count.
// Hence the the number of cycles taken from ADC trigger
// to ISR entry can be inferred from the change in PWM count
// from the max count.
//

//
// Constants
//

// Adjust the IO count for the number of cycles elapsed between the IOBmrk end
// function being called and the PWM register being read. This was determined from
// the assembly code generated and counting the cycles.
//
#define IOBMRK_ADJUST 5

//
// PWM max value used as reference for start of ADC interrupt
//
extern uint32_t PWM_PERIOD_MAX;

//
// Calculate the cycles for IO response
//
#define IOBmrk_calc()           IOBmrk_Cyc = PWM_PERIOD_MAX - IOBmrk_End - IOBMRK_ADJUST;    \
                                IOBmrk_Sum += IOBmrk_Cyc;                                        \
                                IOBmrk_Max = (IOBmrk_Cyc > IOBmrk_Max)? IOBmrk_Cyc:IOBmrk_Max;   \
                                IOBmrk_Min = (IOBmrk_Cyc < IOBmrk_Min)? IOBmrk_Cyc:IOBmrk_Min;   \
                                IOBmrk_Count++;



#endif //_DEVICE_PROFILE_H
