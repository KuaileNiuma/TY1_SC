/** 
  ************************************************************************************* 
  * @file sfo.h 
  * @brief This file contains the definition of sfo driver. 
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

#ifndef _SFO_H
#define _SFO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
#include "hw_types.h"
#include "hw_common.h"
#include "hw_hrpwm.h"




#if HRPWM_HW_VER == 0x0

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

#define SFO_INCOMPLETE      0
#define SFO_COMPLETE        1
#define SFO_ERROR           2

static inline int SFO(void)
{
    uint16_t mep;
    uint16_t cfg1;
    uint16_t cfg2;
    uint16_t hrc1;
    uint16_t hrc2;
    int j;

    cfg1 = 150;
    cfg2 = 200;

    if ((HWREGH(0x21000000U+ HRPWM_O_HRPWR) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
        return SFO_INCOMPLETE;
    }

    HWREGH(0x21000000U+ HRPWM_O_SFO_CFG) = cfg1;
    for (j = 0; j < 100; j++)
    {
    }
    HWREGH(0x21000000+ HRPWM_O_HRPWR) = ((0x802c)&(~0x4)); // 0x802c-HRCAL 0x842c-other
    for (j = 0; j < 100; j++)
       {
       }
    HWREGH(0x21000000+HRPWM_O_HRPWR)|=0x4;
    while (((HWREGH(0x21000000U+ HRPWM_O_HRPWR)) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
    }
    for (j = 0; j < 40000; j++)
    {
    }
    hrc1 = (uint16_t)HWREGH(0x21000000U+ HRPWM_O_SFO_HRCNT);

    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = 0x00000000;
    for (j = 0; j < 10000; j++)
    {
    }

    HWREGH(0x21000000U+ HRPWM_O_SFO_CFG) = cfg2;
    for (j = 0; j < 100; j++)
    {
    }
    HWREGH(0x21000000+ HRPWM_O_HRPWR) = ((0x802c) & (~0x4));
    for (j = 0; j < 100; j++)
    {
    }
    HWREGH(0x21000000+HRPWM_O_HRPWR) |= 0x4;
    while (((HWREGH(0x21000000U+ HRPWM_O_HRPWR)) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
    }
    for (j = 0; j < 40000; j++)
    {
    }
    hrc2 = (uint16_t)HWREGH(0x21000000U+ HRPWM_O_SFO_HRCNT);

    HWREGH(0x21000000U+ HRPWM_O_HRPWR) = 0x00000000;
    for (j = 0; j < 1000; j++)
    {
    }

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
#endif

#if HRPWM_HW_VER == 0x1

//
// Defines
//
#define PWM_CH_MAX 8  // Equals # of HRPWM modules in the device

//#define HRPWM_O_HRCNFG         (0x20U<<1)   // HRPWM Configuration Register
//#define HRPWM_O_HRPWR          (0x21U<<1)   // HRPWM Power Register
#define HRPWM_O_SFO_CFG          (0x22U<<1)
#define HRPWM_O_SFO_SYSCNT       (0x24U<<1)
#define HRPWM_O_SFO_HRCNT        (0x25U<<1)

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
#define HRPWM_HRPWR_MEPOFF_M      0xFC0U

#define SFO_INCOMPLETE      0
#define SFO_COMPLETE        1
#define SFO_ERROR           2

static int SFO(void) //
{
    uint16_t mep;
    uint16_t cfg1;
    uint16_t cfg2;
    uint16_t hrc1;
    uint16_t hrc2;
    int j;

    cfg1 = 150;
    cfg2 = 200;
    if ((HWREGH((0xF2700000U)+ HRPWM_O_HRPWR) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
        return SFO_INCOMPLETE;
    }

    //ground 1
    HWREGH((0xF2700000U)+ HRPWM_O_SFO_CFG) = cfg1;
    //at least wait for 16 sysclk
    for (j = 0; j < 100; j++)
    {
        __NOP();
    }
    HWREGH((0xF2700000U)+ HRPWM_O_HRPWR) =((0x802c)&(~0x4)); //CALPWRON-1 MEPOFF-000000 HRTYPE-1 CNTMODE-1 CALEN-1
    for (j = 0; j < 100; j++)
    {
    }
    HWREGH((0xF2700000U)+ HRPWM_O_HRPWR) |=0x4;
    while (((HWREGH((0xF2700000U)+ HRPWM_O_HRPWR)) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
    }
    for (j = 0; j < 40000; j++)
    {
    }
    hrc1 = (uint16_t)HWREGH((0xF2700000U)+ HRPWM_O_SFO_HRCNT);
    HWREGH((0xF2700000U)+ HRPWM_O_HRPWR) = 0x00000000;
    for (j = 0; j < 10000; j++)
    {
        __NOP();
    }

    //ground 2
    HWREGH((0xF2700000U)+ HRPWM_O_SFO_CFG) = cfg2;
    //at least wait for 16 sysclk
    for (j = 0; j < 100; j++)
    {
        __NOP();
    }
    HWREGH((0xF2700000U)+ HRPWM_O_HRPWR) =((0x802c)&(~0x4)); //CALPWRON-1 MEPOFF-000000 HRTYPE-1 CNTMODE-1 CALEN-1
    for (j = 0; j < 100; j++)
    {
    }
    HWREGH((0xF2700000U)+ HRPWM_O_HRPWR) |=0x4;
    while (((HWREGH((0xF2700000U)+ HRPWM_O_HRPWR)) & HRPWM_HRPWR_CALDONEn_M)
            == HRPWM_HRPWR_CALDONEn_M)
    {
    }
    for (j = 0; j < 40000; j++)
    {
    }
    hrc2 = (uint16_t)HWREGH((0xF2700000U)+ HRPWM_O_SFO_HRCNT);
    HWREGH((0xF2700000U)+ HRPWM_O_HRPWR) = 0x00000000;
    for (j = 0; j < 1000; j++)
    {
        __NOP();
    }

    float a=(1.0f / (float)hrc2);
    float b=(1.0f / (float)hrc1);
    mep = (2 * (cfg2 - cfg1)) / (65535U * (a - b));
    if (mep > 255)
    {
        HWREGH((0xF2700000U)+ HRPWM_O_HRMSTEP) = 255U;
        return SFO_ERROR;
    }
    else
    {
        HWREGH((0xF2700000U)+ HRPWM_O_HRMSTEP) = mep;
        return SFO_COMPLETE;
    }



}
#endif

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif // End: Multiple include Guard
//
// End of file
//

