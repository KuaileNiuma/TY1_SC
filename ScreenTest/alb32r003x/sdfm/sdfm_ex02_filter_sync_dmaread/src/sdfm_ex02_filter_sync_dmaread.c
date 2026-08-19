/**
 *************************************************************************************
 * @file sdfm_ex02_filter_sync_dmaread.c
 * @brief This file contains the source file for example sdfm_ex02_filter_sync_dmaread.
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

#include "sdfm_ex02_filter_sync_dmaread_board.h"
#include "alb32r003x_screenTest.h"

#define MAX_SAMPLES               1024  //!< Maximum number of samples to collect


//*****************************************************************************
//
// Interrupt Handlers
//
__INTERRUPT void DMA_CH0ISR(void); //!< Interrupt handler for SDFM1 Filter 1 DMA channel. Clears the transfer complete interrupt.
__INTERRUPT void DMA_CH1ISR(void); //!< Interrupt handler for SDFM1 Filter 2 DMA channel. Clears the transfer complete interrupt.
__INTERRUPT void DMA_CH2ISR(void); //!< Interrupt handler for SDFM1 Filter 3 DMA channel. Clears the transfer complete interrupt.
__INTERRUPT void DMA_CH3ISR(void); //!< Interrupt handler for SDFM1 Filter 4 DMA channel. Clears the transfer complete interrupt.

//*****************************************************************************
// 
// Main Function
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM2);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA2);
    Board_init();

    Interrupt_register(DMAC1_C1_IRQn, DMA_CH0ISR);
    Interrupt_setPriority(DMAC1_C1_IRQn, 0, 0);
    Interrupt_enable(DMAC1_C1_IRQn);
    ECLIC_EnableIRQ(DMAC1_C1_IRQn);

    Interrupt_register(DMAC1_C2_IRQn, DMA_CH1ISR);
    Interrupt_setPriority(DMAC1_C2_IRQn, 0, 0);
    Interrupt_enable(DMAC1_C2_IRQn);
    ECLIC_EnableIRQ(DMAC1_C2_IRQn);

    Interrupt_register(DMAC1_C3_IRQn, DMA_CH2ISR);
    Interrupt_setPriority(DMAC1_C3_IRQn, 0, 0);
    Interrupt_enable(DMAC1_C3_IRQn);
    ECLIC_EnableIRQ(DMAC1_C3_IRQn);

    Interrupt_register(DMAC1_C4_IRQn, DMA_CH3ISR);
    Interrupt_setPriority(DMAC1_C4_IRQn, 0, 0);
    Interrupt_enable(DMAC1_C4_IRQn);
    ECLIC_EnableIRQ(DMAC1_C4_IRQn);


    //
    // Enable Global Interrupt (INTM)
    //
    CPU_enableIrq();


    return SC_PASS;
}

//*****************************************************************************
// 
// DMA_CH0ISR
// 
// This function handles DMA channel 0 interrupts, which are triggered when the
// SDFM1 Filter 1 data transfer is complete.
//
//*****************************************************************************
__INTERRUPT void DMA_CH0ISR()
{
    DMA_clearInterrupt(DMA1_CH1_BASE,DMA_INT_TFR);
}


//*****************************************************************************
// 
// DMA_CH1ISR
// 
// This function handles DMA channel 1 interrupts, which are triggered when the
// SDFM1 Filter 2 data transfer is complete.
//
//*****************************************************************************
__INTERRUPT void DMA_CH1ISR()
{
    DMA_clearInterrupt(DMA1_CH2_BASE,DMA_INT_TFR);
}

//*****************************************************************************
// 
// DMA_CH2ISR
// 
// This function handles DMA channel 2 interrupts, which are triggered when the
// SDFM1 Filter 3 data transfer is complete.
//
//*****************************************************************************
__INTERRUPT void DMA_CH2ISR()
{
    DMA_clearInterrupt(DMA1_CH3_BASE,DMA_INT_TFR);
}

//*****************************************************************************
// 
// DMA_CH3ISR
// 
// This function handles DMA channel 3 interrupts, which are triggered when the
// SDFM1 Filter 4 data transfer is complete.
//
//*****************************************************************************
__INTERRUPT void DMA_CH3ISR()
{
    DMA_clearInterrupt(DMA1_CH4_BASE,DMA_INT_TFR);
}


