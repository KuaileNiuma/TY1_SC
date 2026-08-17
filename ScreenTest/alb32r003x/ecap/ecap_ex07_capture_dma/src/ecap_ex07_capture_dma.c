/**
 *************************************************************************************
 * @file ecap_ex07_capture_dma.c
 * @brief This file contains the source file for example ecap_ex07_capture_dma.
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
#include "ecap_ex07_board.h"
#include "stdio.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************

#define PWM_FREQUENCY       10000U                    //!< PWM frequency in Hz (10 KHz)
#define PWM_DUTY            0.3f                      //!< PWM duty cycle (30%)
#define PWM_PRD_VAL         (SystemClock_Get_AHB() / PWM_FREQUENCY) //!< PWM period value
#define PWM_CMP_VAL         (uint32_t)(PWM_DUTY * PWM_PRD_VAL) //!< PWM compare value
#define ECAP_COUNT          16                        //!< Number of ECAP captures to perform


//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

volatile uint16_t cap3Count;               //!< Counter for ECAP event 3
volatile uint16_t cap4Count;               //!< Counter for ECAP event 4

uint32_t ecapData[ECAP_COUNT * 2] = { 0 }; //!< Array to store ECAP capture data
//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void initEPWM(uint32_t base);
static void initDMA(void);

//*****************************************************************************
//
// Function Definitions
//
//*****************************************************************************

//*****************************************************************************
//
// initEPWM - Configure ePWM module
// 
//  This function configures the ePWM module with the specified frequency,
//  duty cycle, and other parameters required for ECAP capture testing.
//
//*****************************************************************************
static void initEPWM(uint32_t base)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Disable peripheral clock sync before configuration
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Set emulation mode to stop after full cycle
    //
    EPWM_setEmulationMode(base, EPWM_EMULATION_STOP_AFTER_FULL_CYCLE);

    //
    // Set up time base clock
    //
    EPWM_setTimeBasePeriod(base, PWM_FREQUENCY);
    EPWM_setPhaseShift(base, 0U);
    EPWM_setTimeBaseCounter(base, 0U);

    //
    // Set up counter mode
    //
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(base);

    //
    // Configure clock prescaler and time base parameters
    //
    EPWM_setClockPrescaler(base, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    EPWM_setTimeBasePeriod(base, PWM_PRD_VAL);
    EPWM_setTimeBaseCounter(base, 0U);
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(base);
    EPWM_setPhaseShift(base, 0U);
    
    //
    // Configure compare value and shadow load mode
    //
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_A, PWM_CMP_VAL);
    EPWM_setCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_A,
            EPWM_COMP_LOAD_ON_CNTR_ZERO);
    
    //
    // Enable sync out pulse on counter zero
    //
    EPWM_enableSyncOutPulseSource(base, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);
    
    //
    // Configure action qualifier actions
    //
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
            EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
            EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

//*****************************************************************************
//
// initDMA - Configure DMA for ECAP data transfer
// 
//  This function configures the DMA controller to transfer data from ECAP
//  capture registers to memory when ECAP events occur.
//
//*****************************************************************************
static void initDMA(void)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
    //
    // Initialize DMA configuration structure
    //
    DMA_ConfigParams dmaCfg = { 0 };

    //
    // Initialize DMA controller
    //
    DMA_initController(DMA1_BASE);

    //
    // Stop DMA channel first to ensure it's in a known state
    //
    DMA_stopChannel(DMA1_CH1_BASE);
    
    //
    // Configure DMA channel parameters
    //
    dmaCfg.enableInterrupt = 1;
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_ECAP1;
    dmaCfg.srcAddr = (myECAP_BASE + ECAP_O_CAP3); // The ECAP capture 3 register address
    dmaCfg.destAddr = (uint32_t) ecapData;
    dmaCfg.blockTS = 2; // Transfer 2 data at a time (ECAP3 and ECAP4)
    dmaCfg.ttfc = DMA_TT_FC_2_P2M_DMAC;
    dmaCfg.srcBtl = DMA_BTL_8;
    dmaCfg.destBtl = DMA_BTL_8;
    dmaCfg.srcAddrDirect = DMA_ADDR_INCRE; // Increment source address to read ECAP3 and ECAP4
    dmaCfg.destAddrDirect = DMA_ADDR_INCRE; // Increment destination address to fill array
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_4;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_4;

    //
    // Apply DMA channel configuration
    //
    DMA_configChannel(DMA1_CH1_BASE, &dmaCfg);

    //
    // Clear any existing interrupt flags
    //
    DMA_clearInterrupt(DMA1_CH1_BASE, DMA_INT_TFR | DMA_INT_BLOCK | DMA_INT_ERR);
    
    //
    // Unmask required interrupts
    //
    DMA_unMaskInterrupt(DMA1_CH1_BASE, DMA_INT_TFR | DMA_INT_BLOCK | DMA_INT_ERR);

    //
    // Start DMA channel operation
    //
    DMA_startChannel(DMA1_CH1_BASE);
}

//*****************************************************************************
//
// main - Main application entry point
// 
//  This function initializes the system, configures the board, initializes ePWM
//  and DMA for ECAP capture, and then enters the main application loop.
//
//*****************************************************************************
void main(void)
{
    uint8_t status = 0;
    uint8_t reload_cnt = 0;
    uint32_t tmp32;

    alb32r003x_evb_init();

    //
    // Disable interrupts during initialization
    //
    CPU_disableIrq();

    //
    // Enable interrupts after critical initialization
    //
    CPU_enableIrq();

    //
    // Print debug information
    //
    printf("hello: %s \r\n", __FILE__);

    //
    // Board initialization
    // Configure GPIO pins, enable required modules and interrupts
    //
    Board_init();

    //
    // Initialize counters
    //
    cap3Count = 0U;
    cap4Count = 0U;

    //
    // Configure ePWM module
    //
    initEPWM(myEPWM_BASE);

    //
    // Configure DMA for ECAP data transfer
    //
    initDMA();

    //
    // Wait until all data has been transferred
    //
    while ((status & DMA_INT_TFR) == 0)
    {
        status = DMA_getInterruptStatus(DMA1_CH1_BASE);
        if (status & DMA_INT_BLOCK)
        {
            reload_cnt++;
            if (reload_cnt == ECAP_COUNT - 1)
            DMA_clearInterrupt(DMA1_CH1_BASE, DMA_INT_BLOCK);
        }
    }

    cap3Count = ECAP_getEventTimeStamp(myECAP_BASE, ECAP_EVENT_3);
    cap4Count = ECAP_getEventTimeStamp(myECAP_BASE, ECAP_EVENT_4);

    //
    // Main application loop - read ECAP events continuously
    //
    while (1)
    {
    }
}


#ifdef __cplusplus
}
#endif
