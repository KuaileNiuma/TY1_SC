/**
 *************************************************************************************
 * @file ecap_ex01_apwm.c
 * @brief This file contains the source file for example ecap_ex01_apwm.
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

#include "alb32r003x_evb.h"
#include "ecap_ex01_board.h"
#include "stdio.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define PWM_CLK   5UL                           //!< PWM frequency as 5Hz
#define Period_VAL  (SystemClock_Get_AHB() / PWM_CLK)       //!< Calculate period value
#define DECREASE_FREQUENCY  0                   //!< Direction flag for decreasing frequency
#define INCREASE_FREQUENCY  1                   //!< Direction flag for increasing frequency

//*****************************************************************************
//
// Local Variables
//
//*****************************************************************************
uint16_t direction;                          //!< Direction flag for frequency adjustment
uint32_t cap1Count;                          //!< Capture count value

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void Board_init(void);

//*****************************************************************************
//
// main - Main application entry point
// 
//  This function initializes the board, configures the eCAP module in APWM mode,
//  and enters a loop to dynamically adjust the PWM frequency.
//
//*****************************************************************************
void main(void)
{
	alb32r003x_evb_init();
    //
    // Print status message
    //
    printf("ECAP EX01 APWM.\r\n");
    //
    // Board initialization - Select eCAP1OUT on MUX 0. Make GPIO5 eCAP1OUT for PWM output
    // Configure eCAP in APWM mode
    //
    Board_init();
    //
    // Infinite loop to adjust PWM frequency
    //
    for (;;)
    {
        //
        // Set the duty cycle to 50%
        //
        ECAP_setAPWMShadowCompare(myECAP0_BASE,
                (ECAP_getEventTimeStamp(myECAP0_BASE, ECAP_EVENT_1) >> 1U));
        cap1Count = ECAP_getEventTimeStamp(myECAP0_BASE, ECAP_EVENT_1);
        //
        // Vary frequency based on current period value
        //
        if (cap1Count >= Period_VAL)
        {
            direction = INCREASE_FREQUENCY;
        }
        else if (cap1Count <= Period_VAL / 2)
        {
            direction = DECREASE_FREQUENCY;
        }
        //
        // Adjust period value based on direction
        //
        if (direction == INCREASE_FREQUENCY)
        {
            ECAP_setAPWMShadowPeriod(myECAP0_BASE, (cap1Count - 50000U));
        }
        else
        {
            ECAP_setAPWMShadowPeriod(myECAP0_BASE, (cap1Count + 50000U));
        }
    }
}
