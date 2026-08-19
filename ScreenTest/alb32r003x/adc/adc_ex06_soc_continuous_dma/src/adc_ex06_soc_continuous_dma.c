/**
 *************************************************************************************
 * @file adc_ex06_soc_continuous_dma.c
 * @brief This file contains the ADC example implementation for example adc_ex06_soc_continuous_dma.
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
#include "adc_ex06_board.h"
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
__attribute__((section(".data_sram"))) uint16_t myADC0Results[RESULTS_BUFFER_SIZE] ;      //!< Buffer for results
volatile uint16_t bufferFull;                           //!< Flag to indicate buffer is full
volatile uint16_t myindex;                              //!< Index into result buffer


//*****************************************************************************
//
// myDMAInit - Initialize DMA for ADC results transfer
//
//*****************************************************************************
void myDMAInit(void)
{
    DMA_ConfigParams dmaCfg =
    { 0 };
    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMASCH);
    //
    // Stop and initialize DMA channel
    //
    DMA_stopChannel(DMA1_CH1_BASE);
    DMA_initController(DMA1_CH1_BASE);
    DMA_enableModule(DMA1_CH1_BASE);
    //
    // Set up DMA transfer parameters
    //
    dmaCfg.enableInterrupt = 0;
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_ADC1_INT1;
    dmaCfg.srcAddr = ADCARESULT_BASE;
    dmaCfg.destAddr = (uint32_t) (&myADC0Results[0]);
    dmaCfg.blockTS = RESULTS_BUFFER_SIZE;
    dmaCfg.ttfc = DMA_TT_FC_2_P2M_DMAC;
    dmaCfg.srcBtl = DMA_BTL_1;
    dmaCfg.destBtl = DMA_BTL_1;
    dmaCfg.srcAddrDirect = DMA_ADDR_NO_CHANGE;
    dmaCfg.destAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_2;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_2;
    //
    // Apply DMA channel configuration
    //
    DMA_configChannel(DMA1_CH1_BASE, &dmaCfg);
    DMA_startChannel(DMA1_CH1_BASE);

}

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

    //
    // Get the latest Conversion results
    //
    myindex++;
    if(myindex == RESULTS_BUFFER_SIZE)
    {
        bufferFull = 1;
        ADC_disableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
    }

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
// main - Application entry point
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();

    printf("ADC EXT06 SOC CONTINUOUS DMA.\r\n");
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
    while (1)
    {
        //
        // When the results buffer is filled, the bufferFull flag will be set.
        //
        while (bufferFull == 0);

        for (myindex = 0; myindex < RESULTS_BUFFER_SIZE; myindex++)
        {
            printf("sampleValue = %d\r\n", myADC0Results[myindex]);
        }

        //
        // Clear the buffer full flag
        //
        bufferFull = 0;

        //
        //Wait 1s Start next ADC conversions
        //
        delay_ms(1000);
        myDMAInit();
        ADC_enableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
        ADC_forceMultipleSOC(myADC0_BASE, ADC_FORCE_SOC0);
    }
}
