/**
 *************************************************************************************
 * @file dma_ex04_adc_epwm_ch8.c
 * @brief This file contains the source file for example dma_ex04_adc_epwm_ch8.
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
#include "dma_ex04_adc_init.h"

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
    dmaCfg.enableInterrupt = 0;
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
// initEPWM
//
//*****************************************************************************
void initEPWM(void)
{
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Disable SOCA
    //
    EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    //
    // Configure the SOC to occur on the first up-count event
    //
    EPWM_setADCTriggerSource(EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_U_CMPA);
    EPWM_setADCTriggerEventPrescale(EPWM1_BASE, EPWM_SOC_A, 1);
    //
    // Set the compare A value to 1000 and the period to 1999
    // Assuming ePWM clock is 20MHz, this would give 10kHz sampling
    // 50MHz ePWM clock would give 25kHz sampling, etc.
    // The sample rate can also be modulated by changing the ePWM period
    // directly (ensure that the compare A value is less than the period).
    //
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 1000);
    EPWM_setTimeBasePeriod(EPWM1_BASE, 1999);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0);
    //
    // Set the local ePWM module clock divider to /1
    //
    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_1);
    //
    // Freeze the counter
    //
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);
}


//*****************************************************************************
//
// main - Application entry point
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();
    printf("DMA EXT04 ADC EPWM CH8.\r\n");
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
    // Set up the ePWM
    //
    initEPWM();
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
        // Start ePWM1, enabling SOCA and putting the counter in up-count mode
        //
        EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
        EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
        //
        // Wait while ePWM1 causes ADC conversions which then cause interrupts.
        // When the results buffer is filled, the bufferFull flag will be set.
        //
        while (bufferFull == 0);
        //
        // Clear the buffer full flag
        //
        bufferFull = 0;
        //
        // Stop ePWM1, disabling SOCA and freezing the counter
        //
        EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
        EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);

    }
}
