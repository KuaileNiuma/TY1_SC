/** 
  *************************************************************************************
  * @file sfo.h 
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

#ifndef _SFO_H
#define _SFO_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "stdint.h"
#include "../inc/hw_types.h"
#include "hw_hrpwm.h"
//
// Defines
//
#define PWM_CH_MAX 8  // Equals # of HRPWM modules in the device

//#define HRPWM_O_HRCNFG         (0x20U<<1)   // HRPWM Configuration Register
//#define HRPWM_O_HRPWR          (0x21U<<1)   // HRPWM Power Register
#define HRPWM_O_SFO_CFG          (0x22U<<1)
#define HRPWM_O_SFO_SYSCNT       (0x23U<<1)
#define HRPWM_O_SFO_HRCNT        (0x24U<<1)

#define HRPWM_HRCNFG_TESTSEL_S    14U
#define HRPWM_HRCNFG_TESTSEL_M    0xC000U   // ePWMxB Shadow Mode Select Bits

#define HRPWM_HRPWR_CALEN_S       2U
#define HRPWM_HRPWR_CALEN_M       0x4U
#define HRPWM_HRPWR_CNTMODE_S     3U
#define HRPWM_HRPWR_CNTMODE_M     0x8U
#define HRPWM_HRPWR_CALDONEn_S    4U
#define HRPWM_HRPWR_CALDONEn_M    0x1U
#define HRPWM_HRPWR_HRTYPE_S      5U
#define HRPWM_HRPWR_HRTYPE_M      0x20U
#define HRPWM_HRPWR_MEPOFF_S      6U
#define HRPWM_HRPWR_MEPOFF_M      0x7C0U

#define SFO_INCOMPLETE      0 //Not completed
#define SFO_COMPLETE        1 //Completed
#define SFO_ERROR           2 //Error

//
// This code drives the Micro Edge Positioner (MEP) calibration module to run the SFO diagnostic
// and determine the appropriate MEP scale factor (number of MEP steps per coarse EPWMCLK cycle)
// for the device at any given time.
//
// If EPWMCLK = TBCLK = 100 MHz and assuming an MEP step size of 150 ps,
// the typical scale factor value at 100 MHz is 66 MEP steps per TBCLK unit (10 ns).
//
// This function updates the MEP scale factor value:
// MEP_ScaleFactor = number of MEP steps per EPWMCLK.
//
// SFO() can be used with a minimum EPWMCLK = TBCLK = 50 MHz.
// The MEP diagnostic logic uses EPWMCLK instead of TBCLK, so the EPWMCLK limitation is critical.
// Below 50 MHz, due to process variations of the device, at low temperature and high core voltage,
// the MEP step size may shrink to a point where 255 MEP steps cannot span the entire EPWMCLK period.
//
// SFO() can be called at any time to run the SFO diagnostic on the MEP calibration module.
//
// Usage:
// • SFO() can be called in the background at any time while the ePWM channel is running in HRPWM mode.
//   The obtained scale factor result can be applied to all ePWM channels running in HRPWM mode,
//   because the function uses the diagnostic logic in the MEP calibration module,
//   which operates independently of ePWM channels.
//
// • When the calibration is complete and a new scale factor has been computed,
//   this routine returns 1; if the calibration is still in progress, it returns 0.
//   If an error occurs and the MEP_ScaleFactor exceeds the maximum 255 subdivision steps
//   per coarse EPWMCLK cycle, the routine returns 2.
//   In this case, the HRMSTEP register retains the last MEP scale factor value less than 256
//   for automatic conversion.
//
// • The SFO() function also updates the HRMSTEP register with the scale factor result.
//   If the HRCNFG[AUTOCONV] bit is set, the application software, while running SFO()
//   in the background, only needs to set
//   CMPAHR = fractional(PWMduty * PWMperiod) << 8
//   or CMPBHR = fractional(PWMduty * PWMperiod) << 8
//   or TBPRDHR = fractional(PWMperiod).
//   The MEP calibration module then automatically calculates the appropriate number of MEP steps
//   represented by the fractional duty cycle or period using the HRMSTEP and
//   CMPAHR/CMPBHR/TBPRDHR register values, and shifts the high-resolution ePWM signal edges accordingly.
//
// • If the HRCNFG[AUTOCONV] bit is cleared, the HRMSTEP register will be ignored.
//   The application software must manually perform the required calculations so that:
//   – CMPAHR = (fractional(PWMduty * PWMperiod) * MEP scale factor) << 8 + 0x080.
//   – TBPHSHR, CMPBHR, DBREDHR and DBFEDHR behave similarly.
//     When using TBPRDHR, automatic conversion must be enabled.
//
//    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = ((HWREGH(0x21000000U+ HRPWM_O_HRPWR))
//            | HRPWM_HRPWR_CALPWRON);
//    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = ((HWREGH(0x21000000U+ HRPWM_O_HRPWR))
//            & ~HRPWM_HRPWR_MEPOFF_M);
//    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = ((HWREGH(0x21000000U+ HRPWM_O_HRPWR))
//            | HRPWM_HRPWR_HRTYPE_M);
//    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = ((HWREGH(0x21000000U+ HRPWM_O_HRPWR))
//            | HRPWM_HRPWR_CNTMODE_M);
//    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = ((HWREGH(0x21000000U+ HRPWM_O_HRPWR))
//            | HRPWM_HRPWR_CALEN_M);

static inline int SFO(void) 
{
    uint16_t mep;
    uint16_t cfg1;
    uint16_t cfg2;
    uint16_t hrc1;
    uint16_t hrc2;
    int j;

    cfg1 = 150; //Value range: 0~255
    cfg2 = 200; //According to the calculation formula, cfg2 must be greater than cfg1

    //Not completed, should not occur?
    if ((HWREGH(0x21000000U+ HRPWM_O_HRPWR) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
        return SFO_INCOMPLETE;
    }

    //Calculate
    //Configure the SFO_CFG register and set the delay chain order to cfg1.
    HWREGH(0x21000000U+ HRPWM_O_SFO_CFG) = cfg1;
    //Wait for a while to stabilize the clock generated by the delay chain (simulate waiting for 5 system clocks).
    for (j = 0; j < 5; j++)
    {
    }
    //Configure the HRPWR register and start the first count
    HWREGH(0x21000000U+ HRPWM_O_HRPWR) =0x802c;
    //Poll HRPWR[CALDONEn], when CALDONEn is 0, the first count ends.
    while (((HWREGH(0x21000000U+ HRPWM_O_HRPWR)) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
    }
    //Wait for the counter to load
    for (j = 0; j < 40000; j++)
    {
    }
    //Read SFO_HRCNT, denote it as hrc1.
    hrc1 = (uint16_t)HWREGH(0x21000000U+ HRPWM_O_SFO_HRCNT);

    //Configure HRPWR register to 0, wait for a while (simulate waiting for 64 system clocks), hardware automatically clears SFO_HRCNT register.
    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = 0x00000000;
    for (j = 0; j < 64; j++)
    {
    }

    //Repeat the steps
    HWREGH(0x21000000U+ HRPWM_O_SFO_CFG) = cfg2;
    for (j = 0; j < 5; j++)
    {
    }
    HWREGH(0x21000000U+ HRPWM_O_HRPWR) =0x802c;
    while (((HWREGH(0x21000000U+ HRPWM_O_HRPWR)) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
    }
    for (j = 0; j < 40000; j++)
    {
    }
    hrc2 = (uint16_t)HWREGH(0x21000000U+ HRPWM_O_SFO_HRCNT);

    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = 0x00000000;
        for (j = 0; j < 64; j++)
        {
        }

    //Calculate mep and load
    float a=(1.0f / (float)hrc2);
    float b=(1.0f / (float)hrc1);
    mep = (2 * (cfg2 - cfg1)) / (65535U * (a - b));
    if (mep > 255)
    {
        HWREGH(0x21000000U+ HRPWM_O_HRMSTEP) = 255U;
        return SFO_ERROR;
    }
    else
    {
        HWREGH(0x21000000U+ HRPWM_O_HRMSTEP) = mep;
        return SFO_COMPLETE;
    }



}

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif // End: Multiple include Guard
//
// End of file
//
