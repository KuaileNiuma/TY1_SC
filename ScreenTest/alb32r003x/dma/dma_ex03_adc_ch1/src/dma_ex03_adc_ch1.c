/**
 *************************************************************************************
 * @file dma_ex03_adc_ch1.c
 * @brief This file contains the source file for example dma_ex03_adc_ch1.
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
#include "dma_ex03_adc_init.h"
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint16_t myADC0Results[128];                 //!< Buffer for results
volatile uint16_t bufferFull;                //!< Flag to indicate buffer is full

//*****************************************************************************
//
// adc_A1_irq_handler - ADC A Interrupt 1 ISR
//
//*****************************************************************************
__INTERRUPT void adcA1ISR(void)
{
    //
    // Clear the interrupt flag
    //
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    bufferFull++;
    //
    // Check if overflow has occurred
    //
    if (true == ADC_getInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    }
}

//*****************************************************************************
//
// myDMAInit - Initialize DMA for ADC results transfer
//
//*****************************************************************************
void myDMAInit(void)
{
    DMA_ConfigParams dmaCfg;
    DMA_configParameter(&dmaCfg);
    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMASCH);
    //
    //Turn on the DMA1 & DMASCH peripheral clock
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
    dmaCfg.ttfc = DMA_TT_FC_2_P2M_DMAC;
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_ADC1_INT1;
    dmaCfg.srcAddr = ADCARESULT_BASE;
    dmaCfg.destAddr = (uint32_t) (myADC0Results);
    dmaCfg.srcBtl = DMA_BTL_1;
    dmaCfg.destBtl = DMA_BTL_1;
    dmaCfg.srcAddrDirect = DMA_ADDR_NO_CHANGE;
    dmaCfg.destAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_2;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_2;
    dmaCfg.chPriority=DMA_CH_PRIORITY_0;
    //
    // Apply DMA channel configuration and start
    //
    DMA_configChannel(DMA1_CH1_BASE, &dmaCfg);
	DMA_enableModule(DMA1_CH1_BASE);
    DMA_startChannel(DMA1_CH1_BASE);

}

//*****************************************************************************
//
// main - Application entry point
//
//*****************************************************************************
int main(void)
{
    alb32r003x_evb_init();
    printf("DMA EXT03 ADC CH1.\r\n");
    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    CPU_enableIrq();
    //
    // Board Initialization
    // - Set up the ADC and initialize the SOC
    // - Enable ADC interrupt
    //
    Board_init();
    //
    // DMA Initialization
    //
    myDMAInit();

    ADC_forceSOC(myADC0_BASE, ADC_SOC_NUMBER0);
    //
    // Loop indefinitely
    //
    return SC_PASS;
}
