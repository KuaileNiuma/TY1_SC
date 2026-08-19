/**
 *************************************************************************************
 * @file dma_ex02_ecap_pwm.c
 * @brief This file contains the source file for example dma_ex02_ecap_pwm.
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
uint32_t timeStamp[4];                               //!< Timestamp capture buffer

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void myEcap_init(void);
static void myDMAInit(void);
static void ECAP_generateSignal(void);

//*****************************************************************************
//
// Function Definitions
//
//*****************************************************************************
//
//! Configures the ECAP module for timestamp capture functionality.
//! 
//! This function initializes the ECAP1 module in capture mode, configures event
//! polarities, and sets up DMA source for transferring captured timestamps.
//
//*****************************************************************************
static void myEcap_init(void)
{
    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP1);
    //
    // Disable all ECAP interrupts
    //
    ECAP_disableInterrupt(ECAP1_BASE, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
    ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
    ECAP_ISR_SOURCE_COUNTER_PERIOD |
    ECAP_ISR_SOURCE_COUNTER_COMPARE));
    //
    // Clear all ECAP interrupt flags
    //
    ECAP_clearInterrupt(ECAP1_BASE, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
    ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
    ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
    ECAP_ISR_SOURCE_COUNTER_PERIOD |
    ECAP_ISR_SOURCE_COUNTER_COMPARE));
    //
    // Re-arm the ECAP module
    //
    ECAP_reArm(ECAP1_BASE);
    //
    // Enable capture mode
    //
    ECAP_enableCaptureMode(ECAP1_BASE);
    //
    // Enable timestamp capture
    //
    ECAP_enableTimeStampCapture(ECAP1_BASE);
    //
    // Configure counter reset settings (relative mode)
    //
    ECAP_disableCounterResetOnEvent(ECAP1_BASE, ECAP_EVENT_1);
    ECAP_disableCounterResetOnEvent(ECAP1_BASE, ECAP_EVENT_2);
    ECAP_disableCounterResetOnEvent(ECAP1_BASE, ECAP_EVENT_3);
    ECAP_disableCounterResetOnEvent(ECAP1_BASE, ECAP_EVENT_4);
    //
    // Set event polarities to falling edge
    //
    ECAP_setEventPolarity(ECAP1_BASE, ECAP_EVENT_1, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(ECAP1_BASE, ECAP_EVENT_2, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(ECAP1_BASE, ECAP_EVENT_3, ECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(ECAP1_BASE, ECAP_EVENT_4, ECAP_EVNT_FALLING_EDGE);
    //
    // Set to continuous capture mode starting from Event 1
    //
    ECAP_setCaptureMode(ECAP1_BASE, ECAP_CONTINUOUS_CAPTURE_MODE, ECAP_EVENT_1);
    //
    // Set phase shift count
    //
    ECAP_setPhaseShiftCount(ECAP1_BASE, 0);
    //
    // Set event prescaler
    //
    ECAP_setEventPrescaler(ECAP1_BASE, 0);
    //
    // Set DMA source to Event 1
    //
    ECAP_setDMASource(ECAP1_BASE, ECAP_EVENT_1);
}

//*****************************************************************************
//
//! Initializes the DMA controller for ECAP data transfer.
//! 
//! This function configures the DMA channel, DMAMUX settings, and sets up the
//! data transfer parameters for moving captured timestamps from ECAP to memory.
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
    // Configure DMA parameters
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
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_ECAP1;
    dmaCfg.srcAddr = (uint32_t) (ECAP1_BASE+ECAP_O_CAP1);
    dmaCfg.destAddr = (uint32_t) timeStamp;
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
//! Generates test signals for ECAP capture.
//! 
//! This function starts the ECAP counter and generates a square wave signal
//! on GPIO pin 0 to test the capture functionality.
//
//*****************************************************************************
static void ECAP_generateSignal(void)
{
    uint32_t indexB;
    //
    // Start and load the ECAP counter
    //
    ECAP_startCounter(ECAP1_BASE);
    ECAP_loadCounter(ECAP1_BASE);
    //
    // Generate test square wave signals
    //
    for (indexB = 0; indexB < 16; indexB++)
    {
        delay_ms(30);
        GPIO_writePin(0, 1);
        delay_ms(30);
        GPIO_writePin(0, 0);
    }
    //
    // Stop the ECAP counter after signal generation
    //
    ECAP_stopCounter(ECAP1_BASE);

}

//*****************************************************************************
//
//! Main application entry point.
//! 
//! This function initializes the ECAP and DMA modules, generates test signals,
//! and enters an infinite loop.
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();
    printf("DMA EXT02 ECAP PWM.\r\n");
    //
    // Initialize ECAP module
    //
    myEcap_init();
    //
    // Initialize DMA controller
    //
    myDMAInit();
    //
    // Generate test signals for ECAP capture
    //
    ECAP_generateSignal();
    //
    // Infinite loop
    //
    while (1)
    {
        //
        // Main loop does nothing
        //
    }
}

#ifdef __cplusplus
}
#endif
