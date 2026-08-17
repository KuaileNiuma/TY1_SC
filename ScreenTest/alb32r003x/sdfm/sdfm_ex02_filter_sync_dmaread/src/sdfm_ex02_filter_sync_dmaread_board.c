/**
 *************************************************************************************
 * @file sdfm_ex02_filter_sync_dmaread_board.c
 * @brief This file contains the source file for example sdfm_ex02_filter_sync_dmaread_board.
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

#include "sdfm_ex02_filter_sync_dmaread_board.h"

#include "sdfm.h"

//
// SDFM1 SD1_C1 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C1 17              //!< SDFM1 Filter 1 Clock pin
#define mySDFM1_SDFM1C1_GPIO 17           //!< SDFM1 Filter 1 Clock GPIO number
#define mySDFM1_SDFM1C1_PIN_CONFIG GPIO_17_SD1_C1  //!< SDFM1 Filter 1 Clock pin configuration

//
// SDFM1 SD1_D1 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D1 16              //!< SDFM1 Filter 1 Data pin
#define mySDFM1_SDFM1D1_GPIO 16           //!< SDFM1 Filter 1 Data GPIO number
#define mySDFM1_SDFM1D1_PIN_CONFIG GPIO_16_SD1_D1  //!< SDFM1 Filter 1 Data pin configuration


// SDFM1 SD1_C2 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C2 33              //!< SDFM1 Filter 2 Clock pin
#define mySDFM1_SDFM1C2_GPIO 33           //!< SDFM1 Filter 2 Clock GPIO number
#define mySDFM1_SDFM1C2_PIN_CONFIG GPIO_33_SD1_C2  //!< SDFM1 Filter 2 Clock pin configuration

//
// SDFM1 SD1_D2 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D2 32              //!< SDFM1 Filter 2 Data pin
#define mySDFM1_SDFM1D2_GPIO 32           //!< SDFM1 Filter 2 Data GPIO number
#define mySDFM1_SDFM1D2_PIN_CONFIG GPIO_32_SD1_D2  //!< SDFM1 Filter 2 Data pin configuration


//
// SDFM1 SD1_C3 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C3 53              //!< SDFM1 Filter 3 Clock pin
#define mySDFM1_SDFM1C3_GPIO 53           //!< SDFM1 Filter 3 Clock GPIO number
#define mySDFM1_SDFM1C3_PIN_CONFIG GPIO_53_SD1_C3  //!< SDFM1 Filter 3 Clock pin configuration

//
// SDFM1 SD1_D3 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D3 52              //!< SDFM1 Filter 3 Data pin
#define mySDFM1_SDFM1D3_GPIO 52           //!< SDFM1 Filter 3 Data GPIO number
#define mySDFM1_SDFM1D3_PIN_CONFIG GPIO_52_SD1_D3  //!< SDFM1 Filter 3 Data pin configuration

//
// SDFM1 SD1_C4 - GPIO Settings
//
#define GPIO_PIN_SDFM1_C4 23              //!< SDFM1 Filter 4 Clock pin
#define mySDFM1_SDFM1C4_GPIO 23           //!< SDFM1 Filter 4 Clock GPIO number
#define mySDFM1_SDFM1C4_PIN_CONFIG GPIO_23_SD1_C4  //!< SDFM1 Filter 4 Clock pin configuration

//
// SDFM1 SD1_D4 - GPIO Settings
//
#define GPIO_PIN_SDFM1_D4 22              //!< SDFM1 Filter 4 Data pin
#define mySDFM1_SDFM1D4_GPIO 22           //!< SDFM1 Filter 4 Data GPIO number
#define mySDFM1_SDFM1D4_PIN_CONFIG GPIO_22_SD1_D4  //!< SDFM1 Filter 4 Data pin configuration


//
// SDFM2 SD2_C1 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C1 57                    //!< SDFM2 Channel 1 clock pin number
#define mySDFM2_SDFM2C1_GPIO 57                 //!< SDFM2 Channel 1 clock GPIO number
#define mySDFM2_SDFM2C1_PIN_CONFIG GPIO_57_SD2_C1 //!< SDFM2 Channel 1 clock pin configuration
//
// SDFM2 SD2_D1 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D1 56                    //!< SDFM2 Channel 1 data pin number
#define mySDFM2_SDFM2D1_GPIO 56                 //!< SDFM2 Channel 1 data GPIO number
#define mySDFM2_SDFM2D1_PIN_CONFIG GPIO_56_SD2_D1 //!< SDFM2 Channel 1 data pin configuration


// SDFM2 SD2_C2 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C2 58                    //!< SDFM2 Channel 2 clock pin number
#define mySDFM2_SDFM2C2_GPIO 58                 //!< SDFM2 Channel 2 clock GPIO number
#define mySDFM2_SDFM2C2_PIN_CONFIG GPIO_58_SD2_C2 //!< SDFM2 Channel 2 clock pin configuration
//
// SDFM2 SD2_D2 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D2 26                    //!< SDFM2 Channel 2 data pin number
#define mySDFM2_SDFM2D2_GPIO 26                 //!< SDFM2 Channel 2 data GPIO number
#define mySDFM2_SDFM2D2_PIN_CONFIG GPIO_26_SD2_D2 //!< SDFM2 Channel 2 data pin configuration

//
// SDFM2 SD2_C3 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C3 59                    //!< SDFM2 Channel 3 clock pin number
#define mySDFM2_SDFM2C3_GPIO 59                 //!< SDFM2 Channel 3 clock GPIO number
#define mySDFM2_SDFM2C3_PIN_CONFIG GPIO_59_SD2_C3 //!< SDFM2 Channel 3 clock pin configuration
//
// SDFM2 SD2_D3 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D3 51                    //!< SDFM2 Channel 3 data pin number
#define mySDFM2_SDFM2D3_GPIO 51                 //!< SDFM2 Channel 3 data GPIO number
#define mySDFM2_SDFM2D3_PIN_CONFIG GPIO_51_SD2_D3 //!< SDFM2 Channel 3 data pin configuration

//
// SDFM2 SD2_C4 - GPIO Settings
//
#define GPIO_PIN_SDFM2_C4 60                    //!< SDFM2 Channel 4 clock pin number
#define mySDFM2_SDFM2C4_GPIO 60                 //!< SDFM2 Channel 4 clock GPIO number
#define mySDFM2_SDFM2C4_PIN_CONFIG GPIO_60_SD2_C4 //!< SDFM2 Channel 4 clock pin configuration

//
// SDFM2 SD2_D4 - GPIO Settings
//
#define GPIO_PIN_SDFM2_D4 30                    //!< SDFM2 Channel 4 data pin number
#define mySDFM2_SDFM2D4_GPIO 30                 //!< SDFM2 Channel 4 data GPIO number
#define mySDFM2_SDFM2D4_PIN_CONFIG GPIO_30_SD2_D4 //!< SDFM2 Channel 4 data pin configuration


#define RESULTS_BUFFER_SIZE     (512)  //!< Size of the data buffer for storing SDFM results
#define CHECK_SIZE              (32)     //!< Size of data chunk to check for validation

uint16_t mySDFilter1DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];
uint16_t mySDFilter2DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];
uint16_t mySDFilter3DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];
uint16_t mySDFilter4DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];


uint32_t sdfmInstance = SDFM1_BASE;




//*****************************************************************************
// 
// Board_init
// 
// This function initializes the board by calling all necessary initialization
// functions for the SDFM example.
//
//*****************************************************************************
void Board_init(void)
{
	PinMux_init();
	DMA_init();
	sdfm_init();

}
//*****************************************************************************
// 
// PinMux_init
// 
// This function initializes the GPIO pins for SDFM1 module, configuring them for
// clock and data signals used by the modulators.
//
//*****************************************************************************
void PinMux_init()
{
	//
	// SDFM1 Pin Mux
	//SDFM1 SD1_C1 _GP17
	//
	GPIO_setPinConfig(mySDFM1_SDFM1C1_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1C1_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM1 SD1_D1 _GP16
	//
	GPIO_setPinConfig(mySDFM1_SDFM1D1_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1D1_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM1 SD1_C2 _GP19
	//
	GPIO_setPinConfig(mySDFM1_SDFM1C2_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1C2_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM1 SD1_D2 _GP18
	//
	GPIO_setPinConfig(mySDFM1_SDFM1D2_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1D2_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM1 SD1_C3 _GP53
	//
	GPIO_setPinConfig(mySDFM1_SDFM1C3_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1C3_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM1 SD1_D3 _GP52
	//
	GPIO_setPinConfig(mySDFM1_SDFM1D3_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1D3_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM1 SD1_C4 _GP55
	//
	GPIO_setPinConfig(mySDFM1_SDFM1C4_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1C4_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM1 SD1_D4 _GP22
	//
	GPIO_setPinConfig(mySDFM1_SDFM1D4_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM1_SDFM1D4_GPIO, GPIO_DIR_MODE_IN);
	//
	// SDFM2 Pin Mux
	//SDFM2 SD2_C1
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C1_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C1_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD2_D1
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D1_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D1_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 S2_C2
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C2_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C2_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD2_D2
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D2_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D2_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD2_C3
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C3_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C3_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD2_D3
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D3_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D3_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD2_C4
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C4_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C4_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD2_D4
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D4_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D4_GPIO, GPIO_DIR_MODE_IN);

}

//*****************************************************************************
// 
// sdfm_init
// 
// This function initializes the SDFM1 module, configuring modulator clock,
// comparator thresholds, filter parameters, and enabling interrupts for all
// four filters.
//
//*****************************************************************************
void sdfm_init(void){

    uint16_t  hlt, llt;
    //
    // Input Control Unit
    //
    // Configure Input Control Unit: Modulator Clock rate = Modulator data rate
    //
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_1,SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_2,SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_3,SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
    SDFM_setupModulatorClock(sdfmInstance, SDFM_FILTER_4,SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    //
    // Comparator Unit - over and under value threshold settings
    //
    hlt = 0x7FFF;
    llt = 0x0000;

    //
    // Configure Comparator Unit's comparator filter type and comparator's
    // OSR value, higher threshold, lower threshold
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
    // Data filter Module
    //
    // Configure Data filter modules filter type, OSR value and
    // enable / disable data filter
    //

    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_1 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(7)));

    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_2 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(7)));

    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_3 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(7)));

    SDFM_configDataFilter(sdfmInstance, (SDFM_FILTER_4 | SDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(7)));

    //
    // Enable Master filter bit: Unless this bit is set none of the filter modules
    // can be enabled. All the filter modules are synchronized when master filter
    // bit is enabled after individual filter modules are enabled.
    //
    SDFM_enableMainFilter(sdfmInstance);

    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_1);
    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_2);
    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_3);
    SDFM_disableExternalReset(sdfmInstance, SDFM_FILTER_4);


    //
    // Enable interrupts
    //
    // Following SDFM interrupts can be enabled / disabled using this function.
    // Enable / disable comparator high threshold
    // Enable / disable comparator low threshold
    // Enable / disable modulator clock failure
    // Enable / disable data filter acknowledge
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

    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_1,SDFM_MODULATOR_FAILURE_INTERRUPT);
    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_2,SDFM_MODULATOR_FAILURE_INTERRUPT);
    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_3,SDFM_MODULATOR_FAILURE_INTERRUPT);
    SDFM_disableInterrupt(sdfmInstance, SDFM_FILTER_4,SDFM_MODULATOR_FAILURE_INTERRUPT);

    //
    // Enable master interrupt so that any of the filter interrupts can trigger
    // by SDFM interrupt to CPU
    //
    SDFM_enableMainInterrupt(sdfmInstance);
}
//*****************************************************************************
// 
// DMA_init
// 
// This function initializes the DMA controller, configuring channels for SDFM1
// filter data transfers and setting up interrupt generation for each channel.
//
//*****************************************************************************
void DMA_init()
{
    //
    // Perform a hard reset on DMA
    //
    DMA_initController(DMA1_BASE);



    DMA_ConfigParams dmaCfg = {0};
    dmaCfg.enableInterrupt = 1;

    //
    //enable DMA Trigger by DMA MUX
    //
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM1_FLT1_DPINT;
//    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM2_FLT1_DPINT;
    dmaCfg.srcAddr = (uint32_t)(sdfmInstance  + SDFM_O_SDDATA1 + 0x2);// read high 16bit
    dmaCfg.destAddr = (uint32_t)mySDFilter1DataBuffer;
    dmaCfg.blockTS = 512;
    dmaCfg.ttfc    = DMA_TT_FC_2_P2M_DMAC;
    dmaCfg.srcBtl  = DMA_BTL_1;
//    dmaCfg.reloadSrc = false;
    dmaCfg.destBtl = DMA_BTL_1;
    dmaCfg.srcAddrDirect = DMA_ADDR_NO_CHANGE;
    dmaCfg.destAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_2;
    dmaCfg.destTrWidthBytes= DMA_TR_WIDTH_BYTE_2;

    DMA_configChannel(DMA1_CH1_BASE, &dmaCfg);
    DMA_clearInterrupt(DMA1_CH1_BASE, DMA_INT_TFR);
    DMA_unMaskInterrupt(DMA1_CH1_BASE, DMA_INT_TFR);


    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM1_FLT2_DPINT;
//    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM2_FLT2_DPINT;
    dmaCfg.srcAddr = (uint32_t)(sdfmInstance  + SDFM_O_SDDATA2 + 0x2);// read high 16bit
    dmaCfg.destAddr = (uint32_t)mySDFilter2DataBuffer;
    DMA_configChannel(DMA1_CH2_BASE, &dmaCfg);
    DMA_clearInterrupt(DMA1_CH2_BASE, DMA_INT_TFR);
    DMA_unMaskInterrupt(DMA1_CH2_BASE, DMA_INT_TFR);


    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM1_FLT3_DPINT;
//    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM2_FLT3_DPINT;
    dmaCfg.srcAddr = (uint32_t)(sdfmInstance  + SDFM_O_SDDATA3 + 0x2);
    dmaCfg.destAddr = (uint32_t)mySDFilter3DataBuffer;
    DMA_configChannel(DMA1_CH3_BASE, &dmaCfg);
    DMA_clearInterrupt(DMA1_CH3_BASE, DMA_INT_TFR);
    DMA_unMaskInterrupt(DMA1_CH3_BASE, DMA_INT_TFR);



    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM1_FLT4_DPINT;
//    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SDFM2_FLT4_DPINT;
    dmaCfg.srcAddr = (uint32_t)(sdfmInstance  + SDFM_O_SDDATA4 + 0x2);
    dmaCfg.destAddr = (uint32_t)mySDFilter4DataBuffer;
    DMA_configChannel(DMA1_CH4_BASE, &dmaCfg);
    DMA_clearInterrupt(DMA1_CH4_BASE, DMA_INT_TFR);
    DMA_unMaskInterrupt(DMA1_CH4_BASE, DMA_INT_TFR);


    DMA_startChannel(DMA1_CH1_BASE);
    DMA_startChannel(DMA1_CH2_BASE);
    DMA_startChannel(DMA1_CH3_BASE);
    DMA_startChannel(DMA1_CH4_BASE);
}


