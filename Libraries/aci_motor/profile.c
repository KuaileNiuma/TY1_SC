/** 
  *************************************************************************************
  * @file profile.c 
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

//
// Include Files
//
#include "../aci_motor/profile.h"

//
// Application execution benchmark datastructures
//
volatile uint32_t Bmrk_Start;
volatile uint32_t Bmrk_End;
volatile uint32_t Bmrk_Cyc[BMRK_INSTANCES];
volatile uint32_t Bmrk_Sum[BMRK_INSTANCES];
volatile uint32_t Bmrk_Max[BMRK_INSTANCES];
volatile uint32_t Bmrk_Min[BMRK_INSTANCES];
volatile uint32_t Bmrk_Count[BMRK_INSTANCES];
volatile uint32_t Bmrk_Adjust;

//
// IO Response benchmark datastructures
//
volatile uint32_t IOBmrk_End;
volatile uint32_t IOBmrk_Cyc;
volatile uint32_t IOBmrk_Sum;
volatile uint32_t IOBmrk_Max;
volatile uint32_t IOBmrk_Min;
volatile uint32_t IOBmrk_Count;

//
// Total cycle count
//
volatile uint32_t Bmrk_TotalAvg = 0;
volatile uint32_t Bmrk_TotalMin = 0;
volatile uint32_t Bmrk_TotalMax = 0;
