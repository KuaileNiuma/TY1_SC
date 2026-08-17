/** 
  *************************************************************************************
  * @file device_profile.c 
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
// Include files
//
#include "../aci_motor/profile.h"
//#include "driverlib.h"
#include "device.h"
#include "epwm.h"

//
// Timer 0 registers used for benchmarking application
//
//#define CPU_TIMER0_TIM_REG      (CPUTIMER0_BASE + CPUTIMER_O_TIM)
//#define CPU_TIMER0_PRD_REG      (CPUTIMER0_BASE + CPUTIMER_O_PRD)
//#define CPU_TIMER0_TCR_REG      (CPUTIMER0_BASE + CPUTIMER_O_TCR)
//#define CPU_TIMER0_TPR_REG      (CPUTIMER0_BASE + CPUTIMER_O_TPR)
//#define CPU_TIMER0_TPRH_REG     (CPUTIMER0_BASE + CPUTIMER_O_TPRH)

//
// For consistent results, force the application benchmark
// functions to never be inlined
//

//
// Calibrate application benchmark to determine offset
//
#pragma FUNC_CANNOT_INLINE (Bmrk_calibrate)
void Bmrk_calibrate(void)
{
	__set_rv_cycle(0);
    Bmrk_start();
    Bmrk_end();
    Bmrk_Adjust = (Bmrk_End - Bmrk_Start);
}

//
// Save application benchmark start count
//
#pragma FUNC_CANNOT_INLINE (Bmrk_start)
void Bmrk_start(void)
{
    Bmrk_Start = __get_rv_cycle();
}

//
// Save application benchmark end count
//
#pragma FUNC_CANNOT_INLINE (Bmrk_end)
void Bmrk_end(void)
{
    Bmrk_End = __get_rv_cycle();
}

//
// Save benchmark count for marking the end
//
void IOBmrk_end(void)
{
    // Read PWM Counter
//    uint16_t  *counter = (uint16_t *) (uintptr_t)(EPWM1_BASE + EPWM_O_TBCTR);
//    IOBmrk_End = *counter;
	IOBmrk_End = EPWM_getTimeBaseCounterValue(EPWM1_BASE);
}
