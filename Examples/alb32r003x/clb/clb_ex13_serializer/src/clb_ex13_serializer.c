/**
 *************************************************************************************
 * @file clb_ex13_serializer.c
 * @brief This file contains the source file for example clb_ex13_serializer.
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

//
// Included Files
//
#include "device.h"
#include "alb32r003x_evb.h"

#include "clb_ex13_board.h"
#include "clb_ex13_config.h"

static volatile uint8_t match1Flag;
static volatile uint8_t match2Flag;

__INTERRUPT void clb1ISR(void);

//
// Shift register GP REG bits
//
#define GPREG_0_EVENT_DATA_SHIFT  0U
#define GPREG_1_MODE0_EN_SHIFT    1U

//
// Main
//
void main(void)
{
    uint32_t counterValue = 0;
    int ret;
    ret = 0;

    alb32r003x_evb_init();

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);

	CPU_enableIrq();

    Interrupt_register(CLB1_IRQn, &clb1ISR);
    Interrupt_enable(CLB1_IRQn);


    Board_init();

    //
    // Serializer mode
    // Match1 EQUAL will generate interrupt at 0b110101
    // Match2 TAP Select bit enable
    // Match 2 Generate interrupt on the rising edge of BIT6
    // MODE0 and EVENT controlled through GPREG
    //
    initTILE1(myCLBForTILE1_BASE);

    CLB_enableCLB(myCLBForTILE1_BASE);

    counterValue = CLB_getRegister(myCLBForTILE1_BASE, CLB_REG_CTR_C0);
    if (counterValue != 0)
    {
        //
        // Error
        //
    }

    //
    // Now we will shift in new values
    //

    //
    // Write 1 to DATA
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (0U << GPREG_1_MODE0_EN_SHIFT));
    //
    // Write 1 to EN
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (1U << GPREG_1_MODE0_EN_SHIFT));

    //
    // The value is now 0b1
    //

    //
    // Write 1 to DATA
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (0U << GPREG_1_MODE0_EN_SHIFT));
    //
    // Write 1 to EN
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (1U << GPREG_1_MODE0_EN_SHIFT));

    //
    // The value is now 0b11
    //

    //
    // Write 0 to DATA
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (0U << GPREG_0_EVENT_DATA_SHIFT) | (0U << GPREG_1_MODE0_EN_SHIFT));
    //
    // Write 1 to EN
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (0U << GPREG_0_EVENT_DATA_SHIFT) | (1U << GPREG_1_MODE0_EN_SHIFT));

    //
    // The value is now 0b110
    //

    //
    // Write 1 to DATA
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (0U << GPREG_1_MODE0_EN_SHIFT));
    //
    // Write 1 to EN
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (1U << GPREG_1_MODE0_EN_SHIFT));

    //
    // The value is now 0b1101
    //

    //
    // Write 0 to DATA
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (0U << GPREG_0_EVENT_DATA_SHIFT) | (0U << GPREG_1_MODE0_EN_SHIFT));
    //
    // Write 1 to EN
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (0U << GPREG_0_EVENT_DATA_SHIFT) | (1U << GPREG_1_MODE0_EN_SHIFT));

    //
    // The value is now 0b11010
    //

    counterValue = CLB_getRegister(myCLBForTILE1_BASE, CLB_REG_CTR_C0);
    if (counterValue != 0b11010)
    {
        //
        // Error
        //
    }

    //
    // Shift successful!
    // The value is
    //

    //
    // Match 1 is set to 0b110101, should get an interrupt
    //

    //
    // Write 1 to DATA
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (0U << GPREG_1_MODE0_EN_SHIFT));
    //
    // Write 1 to EN
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (1U << GPREG_1_MODE0_EN_SHIFT));

    delay_ms(1);

    //
    // Match 2 TAP SELECT for bit 6, 0b"1"101011 should get an interrupt
    //

    //
    // Write 1 to DATA
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (0U << GPREG_1_MODE0_EN_SHIFT));
    //
    // Write 1 to EN
    //
    CLB_setGPREG(myCLBForTILE1_BASE, (1U << GPREG_0_EVENT_DATA_SHIFT) | (1U << GPREG_1_MODE0_EN_SHIFT));

    delay_ms(1);

    while(!(match1Flag&match2Flag));
    ret = 1;
    while(1);
}


__INTERRUPT void clb1ISR(void)
{
    uint32_t intTag = CLB_getInterruptTag(myCLBForTILE1_BASE);

    if (intTag == 1)
    {
        //
        // Match 1 value EQUAL
        //
        match1Flag = 1;
    }
    else if (intTag == 2)
    {
        //
        // Match 2 TAP Select Bit Set
        //
        match2Flag = 1;
    }

    CLB_clearInterruptTag(CLB1_BASE);
}


//
// End of File
//
