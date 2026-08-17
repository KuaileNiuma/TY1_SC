/**
 *************************************************************************************
 * @file rcc_ex01_mco.c
 * @brief This file contains the definition of source file for example rcc_ex01_mco.
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

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    GPIO_setPinConfig(GPIO_16_XCLKOUT);
    //
    //Configure the PLL clock;
    //PLL = HSE * PLL_MULT / PLL_PRE_DIV1;
    //AHB = PLL / AHB_PRE1;
    //APBH = PLL / APBH_PRE2;
    //APBL = PLL / APBL_PRE4;
    //
    RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 10, PLL_PRE_DIV1, AHB_PRE1, APBH_PRE2,
            APBL_PRE4);

    //
    //Configure MCO, output the PLL clock
    //
    RCC_selMCO(MCO_PLL);
    RCC_setMCODivider(MCO_1_DIV);

    //
    //Wait 10s, then change the PLL clock
    //
    delay_ms(10000);

    //
    //Configure the PLL clock;
    //PLL = HSE * PLL_MULT / PLL_PRE_DIV2;
    //AHB = PLL / AHB_PRE1;
    //APBH = PLL / APBH_PRE2;
    //APBL = PLL / APBL_PRE4;
    //
    RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 10, PLL_PRE_DIV1, AHB_PRE1, APBH_PRE2,
            APBL_PRE4);

    //
    //Wait 10s, then change the PLL clock
    //
    delay_ms(10000);

    //
    //Configure the PLL clock;
    //PLL = HSE * PLL_MULT / PLL_PRE_DIV1;
    //AHB = PLL / AHB_PRE1;
    //APBH = PLL / APBH_PRE2;
    //APBL = PLL / APBL_PRE4;
    //
    RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 7, PLL_PRE_DIV1, AHB_PRE1, APBH_PRE2,
            APBL_PRE4);

    //
    //Wait 10s, then change the PLL clock
    //
    delay_ms(10000);

    //
    //Configure the PLL clock;
    //PLL = HSE * PLL_MULT / PLL_PRE_DIV1;
    //AHB = PLL / AHB_PRE1;
    //APBH = PLL / APBH_PRE2;
    //APBL = PLL / APBL_PRE4;
    //
    RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 8, PLL_PRE_DIV1, AHB_PRE1, APBH_PRE2,
            APBL_PRE4);

    //
    //Wait 10s, then change the PLL clock
    //
    delay_ms(10000);

    while (1)
    {

    }
    return 0;
}

