/**
 *************************************************************************************
 * @file sdfm_ex01_filter_sync_cpuread_board.c
 * @brief This file contains the source file for example sdfm_ex01_filter_sync_cpuread_board.
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

#include "sdfm_ex01_filter_sync_cpuread_board.h"

#include "sdfm.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint16_t  pinMuxOption;                     //!< Pin mux configuration option
uint16_t  hlt, llt;                         //!< High and low threshold values for SDFM comparator
uint32_t  sdfmInstance = SDFM1_BASE;
//*****************************************************************************
//
// Pin Mux Initialization
//
//*****************************************************************************
void PinMux_init()
{
    //
    // Configure SDFM1 filter 1 pins
    //
    // Configure SDFM1_SDFM1C1 (Clock for filter 1) - GP17
    GPIO_setPinConfig(mySDFM1_SDFM1C1_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1C1_GPIO, GPIO_DIR_MODE_IN);

    // Configure SDFM1_SDFM1D1 (Data for filter 1) - GP48
    GPIO_setPinConfig(mySDFM1_SDFM1D1_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1D1_GPIO, GPIO_DIR_MODE_IN);

    //
    // Configure SDFM1 filter 2 pins
    //
    // Configure SDFM1_SDFM1C2 (Clock for filter 2) - GP19
    GPIO_setPinConfig(mySDFM1_SDFM1C2_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1C2_GPIO, GPIO_DIR_MODE_IN);

    // Configure SDFM1_SDFM1D2 (Data for filter 2) - GP18
    GPIO_setPinConfig(mySDFM1_SDFM1D2_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1D2_GPIO, GPIO_DIR_MODE_IN);

    //
    // Configure SDFM1 filter 3 pins
    //
    // Configure SDFM1_SDFM1C3 (Clock for filter 3) - GP53
    GPIO_setPinConfig(mySDFM1_SDFM1C3_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1C3_GPIO, GPIO_DIR_MODE_IN);

    // Configure SDFM1_SDFM1D3 (Data for filter 3) - GP52
    GPIO_setPinConfig(mySDFM1_SDFM1D3_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1D3_GPIO, GPIO_DIR_MODE_IN);

    //
    // Configure SDFM1 filter 4 pins
    //
    // Configure SDFM1_SDFM1C4 (Clock for filter 4) - GP55
    GPIO_setPinConfig(mySDFM1_SDFM1C4_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1C4_GPIO, GPIO_DIR_MODE_IN);

    // Configure SDFM1_SDFM1D4 (Data for filter 4) - GP22
    GPIO_setPinConfig(mySDFM1_SDFM1D4_PIN_CONFIG);
    GPIO_setDirectionMode(mySDFM1_SDFM1D4_GPIO, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// SDFM Initialization
//
//*****************************************************************************
void sdfm_init(void)
{
    //
    // Local variables for threshold configuration
    //
    uint16_t hlt, llt;             //!< High and low threshold values

    //
    // Input Control Unit Configuration
    //
    // Configure Input Control Unit for all filters: Modulator Clock rate = Modulator data rate
    //
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_1, SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_2, SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_3, SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_4, SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    //
    // Comparator Unit Configuration
    //
    // Set threshold values for comparator
    //
    hlt = 0x7FFF;                  //!< Maximum positive value (16-bit)
    llt = 0x0000;                  //!< Zero value

    //
    // Configure Comparator Unit for all filters
    // - Filter type: SINC 3
    // - OSR (Oversampling Ratio): 32
    // - High threshold: 0x7FFF
    // - Low threshold: 0x0000
    //
    SDFM_configComparator(sdfmInstance,
        (SDFM_FILTER_1 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);
    SDFM_configComparator(sdfmInstance,
        (SDFM_FILTER_2 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);
    SDFM_configComparator(sdfmInstance,
        (SDFM_FILTER_3 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);
    SDFM_configComparator(sdfmInstance,
        (SDFM_FILTER_4 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);

    //
    // Data Filter Unit Configuration
    //
    // Configure Data Filter Unit for all filters
    // - Filter type: SINC 3
    // - OSR (Oversampling Ratio): 128
    // - Data format: 16-bit
    // - Filter enabled
    // - Shift value: 0x0007
    //
    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_1 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_2 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_3 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_4 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    //
    // Enable Master filter bit
    // This synchronizes all filter modules when enabled after individual filters
    //
    SDFM_enableMainFilter(sdfmInstance);

    //
    // Disable external reset for all filters
    //
    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_1);
    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_2);
    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_3);
    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_4);

    //
    // Interrupt Configuration
    //
    // Enable modulator failure and data filter acknowledge interrupts for all filters
    //
    SDFM_enableInterrupt(sdfmInstance, SDFM_FILTER_1,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    SDFM_enableInterrupt(sdfmInstance, SDFM_FILTER_2,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    SDFM_enableInterrupt(sdfmInstance, SDFM_FILTER_3,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    SDFM_enableInterrupt(sdfmInstance, SDFM_FILTER_4,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    //
    // Disable high and low threshold interrupts for all filters
    //
    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_1,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_2,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_3,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_4,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    //
    // Enable master interrupt so that any filter interrupt can trigger SDFM interrupt to CPU
    //
    SDFM_enableMainInterrupt(sdfmInstance);
}


//*****************************************************************************
//
// Board Initialization
//
//*****************************************************************************
void Board_init(void)
{
    //
    // Initialize GPIO pin muxing for SDFM pins
    //
	PinMux_init();
    
    //
    // Initialize SDFM modules and filters
    //
	sdfm_init();
}





