/**
 *************************************************************************************
 * @file cmpss_ex02_digital_filter.c
 * @brief This file contains the source file for example cmpss_ex02_digital_filter.
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
#include "cmpss_ex02_board.h"
#include <stdio.h>
#include "alb32r003x_screenTest.h"

//
// Main
//
int main(void)
{
	alb32r003x_evb_init();

	CPU_enableIrq();
    //
    // Board initialization
    // - Configure GPIO14 to output CTRIPOUT1H (routed through XBAROUTPUT3)
    // - Setup the Output X-BAR to output CTRIPOUTH on OUTPUTXBAR3
    // - Configure the high comparator of CMPSS1
    // - Enable CMPSS and configure the negative input signal to come from
    //   the DAC
    // - Use VDDA as the reference for the DAC and set DAC value to midpoint for
    //   arbitrary reference.
    // - Configure digital filter. For this example, the maxiumum values will be
    //   used for the clock prescale, sample window size, and threshold.
    // - Initialize the filter logic and start filtering
    // - Configure the output signals. Both CTRIPH and CTRIPOUTH will be fed by
    //   the filter output.
    //
    Board_init();


    //
    // Loop indefinitely
    //
    return SC_PASS;
}
