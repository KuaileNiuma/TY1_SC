/**
 *************************************************************************************
 * @file rcc.c
 * @brief This file implements the function of rcc driver.
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

#include "rcc.h"

#if RCC_HW_VER == 0

void RCC_ClkConfig(SYS_CLK_SRC sys_clk_src, OSC_SRC_SEL osc_src,
        uint8_t pll_loop, PLL_PRE_DIV pll_div_pre, AHB_PRE_DIV AHB_div,
        APBH_PRE_DIV APBH_div, APBL_PRE_DIV APBL_div)
{
    //
    //  Switch System Clock Source to OSC, make sure CPU is running
    //
    RCC_setSystemClockSrc(SW_OSC);
    //
    //  Select OSC Source (HSE or HSI)
    //
    switch(osc_src)
    {
    case OSCSRC_HSE:
        RCC_enableHSE();
        RCC_selOSCSource(OSCSRC_HSE);
        break;
    default:
        RCC_enableHSI1();
        RCC_selHSISource(HSIRC_HSI1);
        RCC_selOSCSource(OSCSRC_HSI);
        RCC_disableHSE();
        break;
    }
    //
    //  Select System Clock Source  (PLL or OSC)
    //
    switch(sys_clk_src)
    {
    case SW_PLL:
        RCC_disbalePLL();
        RCC_setPLLPrescaler(pll_div_pre);
        RCC_setPLLMultipler(pll_loop);
        RCC_enbalePLL();
        RCC_setSystemClockSrc(SW_PLL);
        break;
    default:
        break;
    }
    //
    //
    //
    RCC_setAHBPrescaler(AHB_div);
    //
    //
    //
    RCC_setAPBHPrescaler(APBH_div);
    //
    //
    //
    RCC_setAPBLPrescaler(APBL_div);
}

/*
 * Freq = HSI_CLOCK * mult / div MHz
 */
void RCC_SetFreqHSI( uint32_t mult, PLL_PRE_DIV div );
/*
 * Freq = HSE_CLOCK * mult / div MHz
 */
void RCC_SetFreqHSE( uint32_t mult, PLL_PRE_DIV div );

#elif RCC_HW_VER == 1

void RCC_ResetPeripheral(RCC_ResetSrc src)
{
    uint32_t bit = (1 << (src & 0x1FU)); // (src & 0x1FU) = (src % 32);
    uint32_t reg_addr = RCC_BASE + RCC_O_RST1 + ((src >> 3U) & 0x1CU); // src/32*4
    uint32_t reg_val = 0U;
    uint32_t reg_tmp = 0U;
    uint32_t i = 0U;

    EALLOW;
    reg_val = HWREG(reg_addr);

    // hold reset
    HWREG(reg_addr) = reg_val & (~bit);
    for (i = 0; i < 200U; i++)
    {
        reg_tmp = HWREG(reg_addr);
        if(reg_tmp == (reg_val & (~bit)))
        {
            break;
        }
        __NOP();
    }
    // release reset
    HWREG(reg_addr) = reg_val | bit;
    reg_tmp = HWREG(reg_addr);
    for (i = 0; i < 200U; i++)
    {
        reg_tmp = HWREG(reg_addr);
        if(reg_tmp == (reg_val | bit))
        {
            break;
        }
        __NOP();
    }
    EDIS;
}

void RCC_holdResetPeripheral(RCC_ResetSrc src)
{
    uint32_t bit = (1 << (src & 0x1FU)); // (src & 0x1FU) = (src % 32);
    uint32_t reg = src / 32U;
    uint32_t reg_addr = RCC_BASE + RCC_O_RST1 + reg * 4U;
    uint32_t i = 0U;

    EALLOW;
    HWREG(reg_addr) &= (~bit);
    for (i = 0U; i < 200U; i++)
    {
        __NOP();
    }
    EDIS;
}

void RCC_releaseResetPeripheral(RCC_ResetSrc src)
{
    uint32_t bit = (1 << (src & 0x1FU)); // (src & 0x1FU) = (src % 32);
    uint32_t reg = src / 32U;
    uint32_t reg_addr = RCC_BASE + RCC_O_RST1 + reg * 4U;
    uint32_t i = 0U;

    EALLOW;
    HWREG(reg_addr) |= bit;
    for (i = 0U; i < 200U; i++)
    {
        __NOP();
    }
    EDIS;
}


#else

#endif
