/**
 *************************************************************************************
 * @file epwm_ex11_configure_signal.c
 * @brief This file contains the source file for example epwm_ex11_configure_signal.
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

#include "epwm_ex11_board.h"
#include "alb32r003x_evb.h"
//
// Globals
//
uint32_t  epwm1TZIntCount;
uint32_t  epwm2TZIntCount;

//
// Function Prototypes
//
__INTERRUPT void epwm1TZISR(void);
__INTERRUPT void epwm2TZISR(void);


void main(void)
{
	alb32r003x_evb_init();
    //
    // Initialize global variables
    //
    epwm1TZIntCount = 0U;
    epwm2TZIntCount = 0U;

    //
    // Enable Global Interrupt
    //
    CPU_enableIrq();

    //
    // Disable sync(Freeze clock to PWM as well)
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Configure ePWM1, ePWM2, and TZ GPIOs/Modules
    //
    Board_init();

    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // IDLE loop. Just sit and loop forever (optional):
    //
    for(;;)
    {

        NOP;
    }
}


//
// epwm1TZISR - ePWM1 TZ ISR
//
__INTERRUPT void epwm1TZISR(void)
{
    epwm1TZIntCount++;

    //
    // To re-enable the OST Interrupt, uncomment the below code:
    //
    // EPWM_clearTripZoneFlag(EPWM1_BASE,(EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST));
}

//
// epwm2TZISR - ePWM2 TZ ISR
//
__INTERRUPT void epwm2TZISR(void)
{
    epwm2TZIntCount++;

    //
    // Clear the flags - we will continue to take this interrupt until the TZ
    // pin goes high.
    //
    EPWM_clearTripZoneFlag(myEPWM2_BASE, (EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_CBC));
}


