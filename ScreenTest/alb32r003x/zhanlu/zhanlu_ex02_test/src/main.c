/**
 *************************************************************************************
 * @file main.c
 * @brief This file contains the source file.
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
#include <stdio.h>
#include "device.h"
#include <math.h>
#include "zhanlu_cycle_test.h"
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Define the interrupt handler name same as vector table in case download mode is flashxip.
//
//*****************************************************************************
#define systimer_irq_handler     core_mtip_handler     //!< System timer interrupt handler
#define systimer_sw_irq_handler  core_msip_handler     //!< System timer software interrupt handler

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
volatile static uint32_t int0_cnt = 0;                //!< mtip timer interrupt test counter
volatile static uint32_t int1_cnt = 0;                //!< msip timer interrupt test counter
unsigned int msip_trig_flag = 1;                      //!< sw trigger systimer sw interrupt flag

//*****************************************************************************
//
// System timer interrupt handler
//
//*****************************************************************************
void systimer_irq_handler(unsigned long cause, unsigned long sp)
{
    int0_cnt++;
    printf("SysTimer IRQ handler %d\n\r", int0_cnt);
    uint64_t now = SysTimer_GetLoadValue();
    SysTimer_SetCompareValue(now + SystemClock_Get() / 2);
}

//*****************************************************************************
//
// System timer software interrupt handler
//
//*****************************************************************************
void systimer_sw_irq_handler(unsigned long cause, unsigned long sp)
{
    SysTimer_ClearSWIRQ();
    int1_cnt++;
    printf("SysTimer SW IRQ handler %d\n\r", int1_cnt);
    msip_trig_flag = 1;
}

//*****************************************************************************
//
// Setup system timer
//
//*****************************************************************************
void setup_timer()
{
    printf("init timer and start\n\r");
    uint64_t now = SysTimer_GetLoadValue();
    uint64_t then = now + SystemClock_Get() / 2;
    SysTimer_SetCompareValue(then);
}

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#ifdef CFG_SIMULATION
#define LOOP_COUNT      2           //!< Loop count for simulation mode
#else
#define LOOP_COUNT      5           //!< Loop count for normal mode
#endif

//*****************************************************************************
//
// External Function Declarations
//
//*****************************************************************************
void zhanlu_cycle_test(void);       //!< External function for cycle testing

//*****************************************************************************
//
// Global Variables for Cycle Measurement
//
//*****************************************************************************
uint64_t star0_cycle = 0;           //!< Start cycle count for measurement
uint64_t end0_cycle = 0;            //!< End cycle count for measurement
uint64_t cycle0[2] =
{ 0 };           //!< Cycle count array for storage

//*****************************************************************************
//
// DLM_test - Tests DLM memory access performance
//
//*****************************************************************************
void DLM_test(void)
{
    uint32_t *p = (uint32_t*) 0x18060000;
    int i = 0;
    uint32_t val = 0;
    star0_cycle = __get_rv_cycle();
    for (i = 0; i < 1000; i++)
    {
        p[i] = 0x5a;
    }
    end0_cycle = __get_rv_cycle();
    cycle0[0] = end0_cycle - star0_cycle;
    HWREG(0x23009000+0x00) = 0xdeadbeef;
    HWREG(0x23009000+0x04) = 0x42333333;
    val = HWREG(0x23009000 + 0x18);
    HWREG(0x23009000+0x18) = val | 0x01;

    p = (uint32_t*) 0x03000000;
    star0_cycle = __get_rv_cycle();
    for (i = 0; i < 1000; i++)
    {
        p[i] = 0xa5;
    }
    end0_cycle = __get_rv_cycle();
    cycle0[1] = end0_cycle - star0_cycle;
}



//*****************************************************************************
//
// This demo will show cpu working in clint interrupt mode not eclic interrupt mode
// Mainly test timer interrupt and software interrupt
// If you want to see how systimer working in ECLIC interrupt mode,
// please check demo_timer or demo_eclic example
// TODO Currently it only can build for evalsoc
//
//*****************************************************************************
//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
    uint32_t returnCode;
    alb32r003x_evb_init();

    zhanlu_cycle_test();

    return SC_PASS;
}

