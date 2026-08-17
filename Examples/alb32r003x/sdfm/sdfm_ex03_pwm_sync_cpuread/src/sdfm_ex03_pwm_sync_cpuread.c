/**
 *************************************************************************************
 * @file sdfm_ex03_pwm_sync_cpuread.c
 * @brief This file contains the source file for example sdfm_ex03_pwm_sync_cpuread.
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

#include "sdfm_ex03_filter_sync_cpuread_board.h"

#define MAX_SAMPLES               1024    //!< Maximum number of samples to store

//
// Macro to read the SDFM filter data in 16-bit format
//
#define READ_16BIT_FILTER_DATA(base, offset)                                  \
                                   (*((volatile int16_t *)(base + offset) + 1)) //!< Macro to read SDFM filter data in 16-bit format

#define READ_32BIT_FILTER_DATA(base, offset)                                  \
                                   (*((volatile int32_t *)(base + offset)))     //!< Macro to read SDFM filter data in 32-bit format



int16_t  filter1Result[MAX_SAMPLES];
int16_t  filter2Result[MAX_SAMPLES];
int16_t  filter3Result[MAX_SAMPLES];
int16_t  filter4Result[MAX_SAMPLES];
__INTERRUPT void sdfm1ISR(void);
__INTERRUPT void sdfm2ISR(void);
volatile static uint16_t loopCounter1 = 0;
//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();
	HWREG(0xe1000000) |= 0x1;
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM2);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);

    Board_init();

    //
    // Enable SDFM1 amd SDFM2 interrupts
    //
    Interrupt_register(SDFM1DR1_IRQn, sdfm1ISR);
    Interrupt_register(SDFM1DR2_IRQn, sdfm1ISR);
    Interrupt_register(SDFM2DR1_IRQn, sdfm2ISR);
    Interrupt_register(SDFM2DR2_IRQn, sdfm2ISR);

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
				printf("filter2 value is %d\r\n", filter2Result[i]);
				printf("filter3 value is %d\r\n", filter3Result[i]);
				printf("filter4 value is %d\r\n", filter4Result[i]);
			}
			loopCounter1 ++;
		}
    }

    return 0;
}

#define SDFM_INT_MASK             0x8000F000U //!< SDFM interrupt mask for filter status flags
volatile uint32_t MF1cnt = 0;

//*****************************************************************************
//
// sdfm1ISR - SDFM 1 ISR
//
//*****************************************************************************
__INTERRUPT void sdfm1ISR(void)
{

    volatile uint32_t sdfmReadFlagRegister = 0;


    SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_1,
                             SDFM_DATA_FORMAT_16_BIT);

    SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_2,
                             SDFM_DATA_FORMAT_16_BIT);

    SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_3,
                             SDFM_DATA_FORMAT_16_BIT);

    SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_4,
                             SDFM_DATA_FORMAT_16_BIT);



    //
    // Read SDFM flag register (SDIFLG)
    //
    sdfmReadFlagRegister = HWREG(SDFM1_BASE + SDFM_O_SDIFLG);

    if((sdfmReadFlagRegister & SDFM_FILTER_1_MOD_FAILED_FLAG))
    {
    	MF1cnt++;
    }


    if(loopCounter1 < MAX_SAMPLES && (sdfmReadFlagRegister & SDFM_FILTER_1_NEW_DATA_FLAG))
    {
        //
        // Read each SDFM filter output and store it in respective filter
        // result array
        //
        filter1Result[loopCounter1] =
              (int16_t)((SDFM_getFilterData(SDFM1_BASE, SDFM_FILTER_1) >> 16U));
        filter2Result[loopCounter1] =
        		(int16_t)((SDFM_getFilterData(SDFM1_BASE, SDFM_FILTER_2) >> 16U));
        filter3Result[loopCounter1] =
        		(int16_t)((SDFM_getFilterData(SDFM1_BASE, SDFM_FILTER_3) >> 16U));
        filter4Result[loopCounter1] =
        		(int16_t)((SDFM_getFilterData(SDFM1_BASE, SDFM_FILTER_4) >> 16U));
        loopCounter1 ++;
        //
        // Clear SDFM flag register (SDIFLG)
        //
        SDFM_clearInterruptFlag(SDFM1_BASE, SDFM_MAIN_INTERRUPT_FLAG |
                                            0xFFFF);

    }
}


//*****************************************************************************
//
// sdfm2ISR - SDFM 2 ISR
//
//*****************************************************************************
__INTERRUPT void sdfm2ISR(void)
{
    static uint16_t loopCounter2 = 0;

    //
    // Wait for result from all the filters (SDIFLG)
    //
    while(HWREG(SDFM2_BASE + SDFM_O_SDIFLG) & SDFM_INT_MASK != SDFM_INT_MASK);

    //
    // Reset the loop counter
    //

    if(loopCounter2 == MAX_SAMPLES)
    {
        for (int i = 0; i < 1024; i ++) {
        	printf("THE ITERATION: %d\r\n", i);
        	printf("filter1 value is %d\r\n", filter1Result[i]);
        	printf("filter2 value is %d\r\n", filter2Result[i]);
        	printf("filter3 value is %d\r\n", filter3Result[i]);
        	printf("filter4 value is %d\r\n", filter4Result[i]);
        }
        loopCounter2 ++;
    }
    //
    // Read each SDFM filter output and store it in respective filter
    // result array
    //
    filter1Result[loopCounter2]   =
                        READ_16BIT_FILTER_DATA(SDFM2_BASE, SDFM_O_SDDATA1);
    filter2Result[loopCounter2]   =
                        READ_16BIT_FILTER_DATA(SDFM2_BASE, SDFM_O_SDDATA2);
    filter3Result[loopCounter2]   =
                        READ_16BIT_FILTER_DATA(SDFM2_BASE, SDFM_O_SDDATA3);
    filter4Result[loopCounter2] =
                        READ_16BIT_FILTER_DATA(SDFM2_BASE, SDFM_O_SDDATA4);
    loopCounter2 ++;
    //
    // Clear SDFM flag register
    //
    SDFM_clearInterruptFlag(SDFM2_BASE, SDFM_INT_MASK);

}
