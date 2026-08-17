/**
 *************************************************************************************
 * @file sdfm_ex04_type1_filter_fifo_cpuread.c
 * @brief This file contains the source file for example sdfm_ex04_type1_filter_fifo_cpuread.
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
#include <time.h>
#include <stdlib.h>
#include "alb32r003x_evb.h"

#include "sdfm_ex04_filter_sync_cpuread_board.h"

#define MAX_SAMPLES               1024

volatile int16_t  filter1Result[MAX_SAMPLES+50];
__INTERRUPT void SDFM1ISR(void);
__INTERRUPT void SDFM2ISR(void);
__INTERRUPT void sdfmFIFO1ISR(void);
__INTERRUPT void sdfmFIFO2ISR(void);

volatile static uint16_t loopCounter1 = 0;


int main(void)
{
	alb32r003x_evb_init();

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM2);

    uint32_t oldTicks;
    uint32_t tickCnt;

    Board_init();

    Interrupt_enable(SDFM1DR1_IRQn);
    Interrupt_enable(SDFM2DR1_IRQn);
    Interrupt_register(SDFM1DR1_IRQn, sdfmFIFO1ISR);
    Interrupt_register(SDFM2DR1_IRQn, sdfmFIFO2ISR);

    //
    // Enable Global Interrupt (INTM)
    //
    CPU_enableIrq();


    while (1) {
        if(loopCounter1 == MAX_SAMPLES)
        {
			for (int i = 0; i < 1024; i ++) {
				printf("THE ITERATION: %d\r\n", i);
				printf("filter1 value is %d\r\n", filter1Result[i]);
			}
			loopCounter1 ++;
        }
    }

    return 0;
}


#define FIFO_INT_NUM              16U
//
// sdfmFIFO1ISR - SDFM FIFO1 ISR
//
__INTERRUPT void sdfmFIFO1ISR(void)
{
    uint16_t i;

    SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_1,
                             SDFM_DATA_FORMAT_16_BIT);

    //
    // Read SDFM flag register (SDIFLG)
    //
    if(loopCounter1 >= MAX_SAMPLES)
    {
        asm ("NOP");
    }
    else if(SDFM_getFIFOISRStatus(SDFM1_BASE, SDFM_FILTER_1) == 0x1U)
    {
        for(i = 0; i < FIFO_INT_NUM; i++)
        {
            filter1Result[loopCounter1] =
                         (int16_t)(SDFM_getFIFOData(SDFM1_BASE,
                                                    SDFM_FILTER_1) >> 16U);
            loopCounter1 ++;
        }

    }
    else if(SDFM_getNewFilterDataStatus(SDFM1_BASE, SDFM_FILTER_1) == 0x1U)
    {
        filter1Result[loopCounter1++] =
               (int16_t)(SDFM_getFilterData(SDFM1_BASE, SDFM_FILTER_1) >> 16U);
    }

    //
    // Clear SDFM flag register (SDIFLG)
    //
    SDFM_clearInterruptFlag(SDFM1_BASE, SDFM_MAIN_INTERRUPT_FLAG |
                            SDFM_FILTER_1_FIFO_INTERRUPT_FLAG      |
                            SDFM_FILTER_1_NEW_DATA_FLAG            |
                            SDFM_FILTER_1_FIFO_OVERFLOW_FLAG);

}



//
// sdfmFIFO2ISR - SDFM FIFO2 ISR
//
__INTERRUPT void sdfmFIFO2ISR(void)
{
    uint16_t i;
    static uint16_t loopCounter2 = 0;

   SDFM_setOutputDataFormat(SDFM2_BASE, SDFM_FILTER_1,
                             SDFM_DATA_FORMAT_16_BIT);

    //
    // Read SDFM flag register (SDIFLG)
    //
    if(loopCounter2 >= MAX_SAMPLES)
    {
        asm ("NOP");
    }
    else if(SDFM_getFIFOISRStatus(SDFM2_BASE, SDFM_FILTER_1) == 0x1U)
    {
        for(i = 0; i < FIFO_INT_NUM; i++)
        {
            filter1Result[loopCounter2] =
                         (int16_t)(SDFM_getFIFOData(SDFM2_BASE,
                                                    SDFM_FILTER_1) >> 16U);
            loopCounter2 ++;
        }

    }
    else if(SDFM_getNewFilterDataStatus(SDFM2_BASE, SDFM_FILTER_1) == 0x1U)
    {
        filter1Result[loopCounter2++] =
               (int16_t)(SDFM_getFilterData(SDFM2_BASE, SDFM_FILTER_1) >> 16U);
    }

    //
    // Clear SDFM flag register (SDIFLG)
    //
    SDFM_clearInterruptFlag(SDFM2_BASE, SDFM_MAIN_INTERRUPT_FLAG |
                            SDFM_FILTER_1_FIFO_INTERRUPT_FLAG      |
                            SDFM_FILTER_1_NEW_DATA_FLAG            |
                            SDFM_FILTER_1_FIFO_OVERFLOW_FLAG);

}
