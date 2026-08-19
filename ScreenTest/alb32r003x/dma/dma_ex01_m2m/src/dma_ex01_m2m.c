/**
 *************************************************************************************
 * @file dma_ex01_m2m.c
 * @brief This file contains the source file for example dma_ex01_m2m.
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
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t my_srcData[128];                //!< Source data buffer for DMA transfer
uint32_t my_destData[128];               //!< Destination data buffer for DMA transfer

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void myDMAInit(void);
static void srcData_init(void);

//*****************************************************************************
//
// Initialize and configure DMA channel for memory-to-memory transfer
//
//*****************************************************************************
static void myDMAInit(void)
{
    DMA_ConfigParams dmaCfg;
    DMA_configParameter(&dmaCfg);

    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMASCH);
    //
    // Stop and initialize DMA channel
    //
    DMA_disableModule(DMA1_CH1_BASE);
    DMA_stopChannel(DMA1_CH1_BASE);
    DMA_DeConfChannel(DMA1_CH1_BASE);
    DMA_disableInterrupt(DMA1_CH1_BASE);

    //
    // Set up DMA transfer parameters
    //
    dmaCfg.enableInterrupt = false;
    dmaCfg.blockTS = 128;
    dmaCfg.ttfc = DMA_TT_FC_0_M2M_DMAC;
    dmaCfg.srcAddr = (uint32_t) (my_srcData);
    dmaCfg.destAddr = (uint32_t) (my_destData);
    dmaCfg.srcBtl = DMA_BTL_1;
    dmaCfg.destBtl = DMA_BTL_1;
    dmaCfg.srcAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.destAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_4;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_4;
    dmaCfg.chPriority=DMA_CH_PRIORITY_0;
    //
    // Apply DMA channel configuration
    //
    DMA_configChannel(DMA1_CH1_BASE, &dmaCfg);
	DMA_enableModule(DMA1_CH1_BASE);
}

//*****************************************************************************
//
// Initialize source data buffer with sequential values
//
//*****************************************************************************
static void srcData_init(void)
{
    int i;
    i = 0;
    //
    // Fill source buffer with sequential values from 1 to 128
    //
    for (i = 0; i < 128; i++)
    {
        my_srcData[i] = i + 1;
    }
}

//*****************************************************************************
//
// Main function
//
//*****************************************************************************
int main(void)
{
    alb32r003x_evb_init();
    printf("DMA EXT01 M2M.\r\n");
    //
    // Initialize source data buffer
    //
    srcData_init();
    //
    // Initialize DMA channel
    //
    myDMAInit();
    //
    // Start DMA transfer
    //
    DMA_startChannel(DMA1_CH1_BASE);
    //
    // Loop indefinitely
    //
    return SC_PASS;
}

#ifdef __cplusplus
}
#endif
