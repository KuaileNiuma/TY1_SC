/**
 *************************************************************************************
 * @file epwm_ex06_valley_switching.c
 * @brief This file contains the source file for example epwm_ex06_valley_switching.
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
 
#include <stdio.h>
#include "epwm_ex06_board.h"
#include "alb32r003x_evb.h"



//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
__INTERRUPT void epwm1ISR(void);  //!< ePWM1 interrupt service routine


//*****************************************************************************
//
// Main
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();

    //
    // Disable sync and clock to PWM
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Configure ePWM1, and TZ GPIOs
    //
    Board_init();
    GPIO_writePin(myGPIO25, 1);

    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Enable interrupts required for this example
    //
    ECLIC_EnableIRQ(EPWM1_IRQn);

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    CPU_enableIrq();

    //
    // IDLE loop. Just sit and loop forever (optional):
    //
    for(;;)
    {
        //
        // PULL Trip GPIO LOW from CTR=4000 to 11000
        // PULL Trip GPIO HIGH at CTR=11000
        //
        while(HWREGH(myEPWM1_BASE + EPWM_O_TBCTR) < 4000);
        GPIO_writePin(myGPIO25, 0);
        while(HWREGH(myEPWM1_BASE + EPWM_O_TBCTR) < 11000);
        GPIO_writePin(myGPIO25, 1);
        while(HWREGH(myEPWM1_BASE + EPWM_O_TBCTR) > 3000);
        GPIO_writePin(myGPIO25, 1);
        NOP;
    }
}

//*****************************************************************************
//
// epwm1ISR - ePWM1 interrupt service routine
//
//*****************************************************************************
__INTERRUPT void epwm1ISR(void)
{
    EPWM_clearTripZoneFlag(myEPWM1_BASE, EPWM_TZ_FLAG_OST | EPWM_TZ_FLAG_DCAEVT1 | EPWM_TZ_FLAG_DCBEVT1 | EPWM_TZ_INTERRUPT);
    EPWM_clearOneShotTripZoneFlag(myEPWM1_BASE, EPWM_TZ_OST_FLAG_DCBEVT1);

    //
    // Clear INT flag for this timer
    //
    EPWM_clearEventTriggerInterruptFlag(myEPWM1_BASE);
}


