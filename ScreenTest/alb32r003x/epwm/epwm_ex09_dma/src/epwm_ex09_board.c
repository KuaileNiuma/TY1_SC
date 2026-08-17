/**
 *************************************************************************************
 * @file epwm_ex09_board.c
 * @brief This file contains the source file for example epwm_ex09_board.
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

#include "epwm_ex09_board.h"
uint16_t PRDTxBuffer[8]={100,200,400,1000,2000,5000,10000,20000};

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
    //
    // PinMux for modules assigned to CPU1
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    //
    // EPWM1 -> myEPWM1 Pinmux
    //
    GPIO_setPinConfig(myEPWM1_EPWMA_PIN_CONFIG);

    GPIO_setPinConfig(myEPWM1_EPWMB_PIN_CONFIG);
}
//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(uint32_t epwm_base)
{
    //
    // Set clock prescaler
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    EPWM_setClockPrescaler(epwm_base, EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_2);
    EPWM_setTimeBasePeriod(epwm_base, 100);
    EPWM_setTimeBaseCounter(epwm_base, 0);
    EPWM_setTimeBaseCounterMode(epwm_base, EPWM_COUNTER_MODE_UP_DOWN);
    EPWM_setPeriodLoadMode(epwm_base,EPWM_PERIOD_SHADOW_LOAD);
    EPWM_selectPeriodLoadEvent(epwm_base,EPWM_SHADOW_LOAD_MODE_COUNTER_ZERO);
    EPWM_disablePhaseShiftLoad(epwm_base);
    EPWM_setPhaseShift(epwm_base, 0);
    EPWM_setCounterCompareValue(epwm_base, EPWM_COUNTER_COMPARE_A, 50);
    EPWM_setCounterCompareShadowLoadMode(epwm_base, EPWM_COUNTER_COMPARE_A,
            EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(epwm_base, EPWM_COUNTER_COMPARE_B, 50);
    EPWM_setCounterCompareShadowLoadMode(epwm_base, EPWM_COUNTER_COMPARE_B,
            EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
    		EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
    		EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
    		EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
    		EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
    		EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
    		EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
    		EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
    		EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
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

}

//*****************************************************************************
//
// SYNC Configurations
//
//*****************************************************************************
void SYNC_init(uint32_t epwm_base)
{
    //
    // Set sync output configuration
    //
    SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
    
    //
    //Set the input source of all EPWMs to the output of the incoming EPWM
    //
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
// DMA Configurations
//
//*****************************************************************************
void DMA_init(void)
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
    dmaCfg.enableInterrupt = false;
    dmaCfg.blockTS = 8;
    dmaCfg.ttfc = DMA_TT_FC_1_M2P_DMAC;
    dmaCfg.dmaSrcReqId = 0;
    dmaCfg.dmaDstReqId = DMAMUX_ReqId_dma_EPWM1_SOCA;
    dmaCfg.srcAddr = (uint32_t)(PRDTxBuffer);
    dmaCfg.destAddr = (uint32_t)(EPWM1_BASE+EPWM_O_TBPRD) ;
    dmaCfg.srcBtl = DMA_BTL_1;
    dmaCfg.destBtl = DMA_BTL_1;
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
// Board Configurations
// Initializes the rest of the modules.
// Call this function in your application if you wish to do all module
// initialization.
// If you wish to not use some of the initializations, instead of the
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init(uint32_t epwm_base)
{
    //
    // Initialize all required modules
    //
	PinMux_init();
    EPWM_init(epwm_base);
    SYNC_init(epwm_base);
    DMA_init();

}



#ifdef __cplusplus
}
#endif

