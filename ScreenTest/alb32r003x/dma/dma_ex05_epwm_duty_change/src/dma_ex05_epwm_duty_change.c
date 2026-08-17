/**
 *************************************************************************************
 * @file dma_ex05_epwm_duty_change.c
 * @brief This file contains the source file for example dma_ex05_epwm_duty_change.
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

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define PRD_VALUE 199                           //!< ePWM period value

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
static uint16_t PRDTxBuffer[16];                      //!< Transmit buffer for PRD values
static uint16_t PRDRxBuffer[16];                      //!< Receive buffer for PRD values

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void EPWM_init(uint32_t epwm_base);
static void SYNC_init(uint32_t epwm_base);
static void Board_init(uint32_t epwm_base);
static void myDMAInit(void);
static void data_init(int num);

//*****************************************************************************
//
// Function Definitions
//
//*****************************************************************************
//
// EPWM_init - Configure ePWM module with specified base address
// 
//  This function initializes the ePWM module with the specified base address,
//  setting up the time base, clock prescaler, and action qualifiers.
//
//*****************************************************************************
static void EPWM_init(uint32_t epwm_base)
{
    //
    //Turn on the EPWM1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Set up clock prescaler
    //
    EPWM_setClockPrescaler(epwm_base, EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_2);
    EPWM_setTimeBasePeriod(epwm_base, PRD_VALUE);
    EPWM_setTimeBaseCounter(epwm_base, 0);
    EPWM_setTimeBaseCounterMode(epwm_base, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(epwm_base);
    EPWM_setPhaseShift(epwm_base, 0);
    EPWM_setCounterCompareValue(epwm_base, EPWM_COUNTER_COMPARE_A, 0);
    EPWM_setCounterCompareShadowLoadMode(epwm_base, EPWM_COUNTER_COMPARE_A,
            EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(epwm_base, EPWM_COUNTER_COMPARE_B, 0);
    EPWM_setCounterCompareShadowLoadMode(epwm_base, EPWM_COUNTER_COMPARE_B,
            EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(epwm_base,
            EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(epwm_base);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(epwm_base,
            EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(epwm_base);
    EPWM_enableADCTrigger(epwm_base, EPWM_SOC_A);
    EPWM_setADCTriggerEventPrescale(epwm_base, EPWM_SOC_A, 1);
    EPWM_enableADCTrigger(epwm_base, EPWM_SOC_B);
    EPWM_setADCTriggerEventPrescale(epwm_base, EPWM_SOC_B, 1);

}

//*****************************************************************************
//
// SYNC_init - Configure synchronization for ePWM modules
// 
//  This function sets up the synchronization configuration for ePWM modules,
//  configuring sync input sources and enabling ADC SOC sources.
//
//*****************************************************************************
static void SYNC_init(uint32_t epwm_base)
{
    //
    // Set sync output configuration
    //
    SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
    EPWM_setSyncInPulseSource(EPWM1_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM2_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM3_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM4_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM5_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM6_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM7_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM8_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    //
    // SOCA
    //
    SysCtl_enableExtADCSOCSource(0);
    //
    // SOCB
    //
    SysCtl_enableExtADCSOCSource(0);
}

//*****************************************************************************
//
// Board_init - Initialize the board and all required ePWM modules
// 
//  This function initializes the ePWM module and sets up synchronization
//  for the specified ePWM base address.
//
//*****************************************************************************
static void Board_init(uint32_t epwm_base)
{
    //
    // Initialize ePWM and sync configurations
    //
    EPWM_init(epwm_base);
    SYNC_init(epwm_base);
}

//*****************************************************************************
//
// myDMAInit - Initialize the DMA controller for data transfer
// 
//  This function configures the DMA channel for transferring data between
//  PRDTxBuffer and PRDRxBuffer using ePWM1 SOCA as trigger.
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
    dmaCfg.blockTS = 1;
    dmaCfg.ttfc = DMA_TT_FC_2_P2M_DMAC;
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_EPWM1_SOCA;
    dmaCfg.srcAddr = (uint32_t) PRDTxBuffer;
    dmaCfg.destAddr = (uint32_t) (EPWM1_BASE + EPWM_O_CMPA);
    dmaCfg.srcBtl = DMA_BTL_16;
    dmaCfg.destBtl = DMA_BTL_16;
    dmaCfg.srcAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.destAddrDirect = DMA_ADDR_NO_CHANGE;
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
// data_init - Initialize the data buffers
// 
//  This function initializes the PRDTxBuffer with incrementing values based
//  on the input multiplier and clears the PRDRxBuffer.
//
//*****************************************************************************
static void data_init(int num)
{
    int i;
    //
    // Initialize buffers with appropriate values
    //
    for (i = 0; i < 16; i++)
    {
        PRDRxBuffer[i] = 0;
        PRDTxBuffer[i] = i * num + 1;
    }
}

//*****************************************************************************
//
// main - Main application entry point
// 
//  This function initializes the DMA controller, configures ePWM modules,
//  and enters an infinite loop.
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();
    printf("DMA EXT05 EPWM DUTY CHANGE.\r\n");
    //
    // Initialize DMA controller
    //
    myDMAInit();
    //
    // Disable time base clock sync before configuring ePWM
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    //
    // Configure and initialize ePWM parameters, then start counting
    //
    Board_init(EPWM1_BASE);
    //
    // Enable time base clock sync to start all ePWM modules simultaneously
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    //
    // Force an ADC trigger on ePWM1 SOCA
    //
    EPWM_forceADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    while((DMA_getRawInterruptStatus(DMA1_CH1_BASE) & DMA_INT_TFR) == 0);
    //
    // Infinite loop
    //
    while (1)
    {
    }
}
