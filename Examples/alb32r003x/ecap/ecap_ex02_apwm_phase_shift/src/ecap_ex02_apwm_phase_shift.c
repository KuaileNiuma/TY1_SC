/**
 *************************************************************************************
 * @file ecap_ex02_apwm_phase_shift.c
 * @brief This file contains the source file for example ecap_ex02_apwm_phase_shift.
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
#include "ecap_ex02_board.h"

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
//  This function initializes the board, configures eCAP modules in APWM mode
//  with phase shift, and enters an infinite loop.
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();
    //
    // Board initialization - Select eCAP1OUT on MUX 0. Make GPIO5 as eCAP1OUT for PWM output
    // Select eCAP2OUT on MUX 2. Make GPIO6 as eCAP2OUT for PWM output
    // Configure eCAP1 in APWM mode with defined period and duty values
    // Polarity as low and configure SYNCOUT at CTR=PRD
    //
    Board_init();
    //
    // Infinite loop
    //
    while (1)
    {
    }
}
