/** 
  *************************************************************************************
  * @file device_profile_init.c 
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


//
// Timer 0 registers used for benchmarking application
//
//#define CPU_TIMER0_TIM_REG      (CPUTIMER0_BASE + CPUTIMER_O_TIM)
//#define CPU_TIMER0_PRD_REG      (CPUTIMER0_BASE + CPUTIMER_O_PRD)
//#define CPU_TIMER0_TCR_REG      (CPUTIMER0_BASE + CPUTIMER_O_TCR)
//#define CPU_TIMER0_TPR_REG      (CPUTIMER0_BASE + CPUTIMER_O_TPR)
//#define CPU_TIMER0_TPRH_REG     (CPUTIMER0_BASE + CPUTIMER_O_TPRH)

//
// Initialize the resources for application benchmarking
//
void Bmrk_init(void)
{
//    //
//    // CPU Timer 0
//    //
//    unsigned long  *period  = (unsigned long *) CPU_TIMER0_PRD_REG;
//    unsigned long  *tpr     = (unsigned long *) CPU_TIMER0_TPR_REG;
//    unsigned long  *tprh    = (unsigned long *) CPU_TIMER0_TPRH_REG;
//    unsigned long  *tcr     = (unsigned long *) CPU_TIMER0_TCR_REG;
//
//    //
//    // Initialize timer period to maximum
//    //
//    *period = 0xFFFFFFFF;
//    //
//    // Initialize pre-scale counter to divide by 1 (SYSCLKOUT)
//    //
//    *tpr = 0;
//    *tprh = 0;
//    //
//    // Make sure timer is stopped (TSS bit 4 = 1)
//    //
//    *tcr |= 0x0010;
//    //
//    // Reload all counter register with period value (TRB bit 5 = 1)
//    //
//    *tcr |= 0x0020;
//    //
//    // Start timer (TSS bit 4 = 0)
//    //
//    *tcr &= 0xFFEF;

    //
    // Initialize the data structures
    //
    unsigned int i=0;
    for (i=0; i<BMRK_INSTANCES; i++)
    {
        Bmrk_Sum[i] = 0;
        Bmrk_Max[i] = 0;
        Bmrk_Min[i] = 0xFFFFFFFF;
        Bmrk_Count[i] = 0;
    }
}


//
// Initialize resources for IO response benchmarking
//
void IOBmrk_init(void)
{
    //
    // Initialize the data structures
    //

    IOBmrk_End = 0;
    IOBmrk_Cyc = 0;
    IOBmrk_Sum = 0;
    IOBmrk_Max = 0;
    IOBmrk_Min = 0xFFFFFFFF;
    IOBmrk_Count = 0;
}
