/**
 *************************************************************************************
 * @file sdfm_ex01_filter_sync_cpuread.c
 * @brief This file contains the source file for example sdfm_ex01_filter_sync_cpuread.
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

#include <time.h>
#include <stdlib.h>
#include "alb32r003x_evb.h"

#include "sdfm_ex01_filter_sync_cpuread_board.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define MAX_SAMPLES               1024U    //!< Maximum number of samples to collect
#define SDFM_PIN_MUX_OPTION       SDFM1_BASE  //!< SDFM module base address for pin muxing

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
int16_t filter1Result[MAX_SAMPLES];   //!< Filter 1 result data buffer
int16_t filter2Result[MAX_SAMPLES];   //!< Filter 2 result data buffer
int16_t filter3Result[MAX_SAMPLES];   //!< Filter 3 result data buffer
int16_t filter4Result[MAX_SAMPLES];   //!< Filter 4 result data buffer
volatile uint32_t MF1cnt = 0;         //!< Filter 1 modulator failure counter
volatile uint32_t MF2cnt = 0;         //!< Filter 2 modulator failure counter
volatile uint32_t MF3cnt = 0;         //!< Filter 3 modulator failure counter
volatile uint32_t MF4cnt = 0;         //!< Filter 4 modulator failure counter

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void configureSDFM1Pins(void);       //!< Configures GPIO pins for SDFM operation
void configureSDFM2Pins(void);
__INTERRUPT void sdfm1ISR(void);                //!< SDFM1 interrupt service routine
__INTERRUPT void sdfm2ISR(void);                //!< SDFM2 interrupt service routine


//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void) {
	alb32r003x_evb_init();


	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SDFM2);

	uint32_t SDFMx_BASE;     //!< SDFM module base address
	uint16_t hlt, llt;       //!< High and low threshold values for comparators

	//
	// Get the SDFM module base address for configuration
	//
	SDFMx_BASE = SDFM_PIN_MUX_OPTION;

	//
	// Configure GPIO pins for SDFM operation
	//
	configureSDFM1Pins();
	configureSDFM2Pins();

	//
	// Input Control Unit
	//
	// Configure Input Control Unit: Modulator Clock rate = Modulator data rate
	//
	SDFM_setupModulatorClock(SDFMx_BASE, SDFM_FILTER_1,
			SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
	SDFM_setupModulatorClock(SDFMx_BASE, SDFM_FILTER_2,
			SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
	SDFM_setupModulatorClock(SDFMx_BASE, SDFM_FILTER_3,
			SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);
	SDFM_setupModulatorClock(SDFMx_BASE, SDFM_FILTER_4,
			SDFM_MODULATOR_CLK_EQUAL_DATA_RATE);



	//
	// Comparator Unit - over and under value threshold settings
	//
	hlt = 0x7FFF;
	llt = 0x0000;

	//
	// Configure Comparator Unit's comparator filter type and comparator's
	// OSR value, higher threshold, lower threshold
	//
	SDFM_configComparator(SDFMx_BASE,
			(SDFM_FILTER_1 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
			SDFM_THRESHOLD(hlt, llt), 0);
	SDFM_configComparator(SDFMx_BASE,
			(SDFM_FILTER_2 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
			SDFM_THRESHOLD(hlt, llt), 0);
	SDFM_configComparator(SDFMx_BASE,
			(SDFM_FILTER_3 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
			SDFM_THRESHOLD(hlt, llt), 0);
	SDFM_configComparator(SDFMx_BASE,
			(SDFM_FILTER_4 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
			SDFM_THRESHOLD(hlt, llt), 0);


	//
	// Data Filter Unit
	//
	// Configure Data Filter Unit - filter type, OSR value and
	// enable / disable data filter
	//
	SDFM_configDataFilter(SDFMx_BASE,
			(SDFM_FILTER_3 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(128)),
			(SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE
					| SDFM_SHIFT_VALUE(0x0007)));
	SDFM_configDataFilter(SDFMx_BASE,
			(SDFM_FILTER_4 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(128)),
			(SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE
					| SDFM_SHIFT_VALUE(0x0007)));
	SDFM_configDataFilter(SDFMx_BASE,
			(SDFM_FILTER_1 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(128)),
			(SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE
					| SDFM_SHIFT_VALUE(0x0007)));
	SDFM_configDataFilter(SDFMx_BASE,
			(SDFM_FILTER_2 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(128)),
			(SDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE
					| SDFM_SHIFT_VALUE(0x0007)));


	//
	// Enable Master filter bit: Unless this bit is set none of the filter modules
	// can be enabled. All the filter modules are synchronized when master filter
	// bit is enabled after individual filter modules are enabled.
	//
	SDFM_enableMainFilter(SDFMx_BASE);

	SDFM_disableExternalReset(SDFMx_BASE, SDFM_FILTER_1);
	SDFM_disableExternalReset(SDFMx_BASE, SDFM_FILTER_2);
	SDFM_disableExternalReset(SDFMx_BASE, SDFM_FILTER_3);
	SDFM_disableExternalReset(SDFMx_BASE, SDFM_FILTER_4);

	//
	// Enable interrupts
	//
	// Following SDFM interrupts can be enabled / disabled using this function.
	// Enable / disable comparator high threshold
	// Enable / disable comparator low threshold
	// Enable / disable modulator clock failure
	// Enable / disable data filter acknowledge
	//
	SDFM_enableInterrupt(SDFMx_BASE, SDFM_FILTER_1,
			(SDFM_MODULATOR_FAILURE_INTERRUPT
					| SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));
	SDFM_enableInterrupt(SDFMx_BASE, SDFM_FILTER_2,
			(SDFM_MODULATOR_FAILURE_INTERRUPT
					| SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));
	SDFM_enableInterrupt(SDFMx_BASE, SDFM_FILTER_3,
			(SDFM_MODULATOR_FAILURE_INTERRUPT
					| SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));
	SDFM_enableInterrupt(SDFMx_BASE, SDFM_FILTER_4,
			(SDFM_MODULATOR_FAILURE_INTERRUPT
					| SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_1,
			(SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT
					| SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_2,
			(SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT
					| SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_3,
			(SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT
					| SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_4,
			(SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT
					| SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_1,
			(SDFM_MODULATOR_FAILURE_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_2,
			(SDFM_MODULATOR_FAILURE_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_3,
			(SDFM_MODULATOR_FAILURE_INTERRUPT));
	SDFM_disableInterrupt(SDFMx_BASE, SDFM_FILTER_4,
			(SDFM_MODULATOR_FAILURE_INTERRUPT));
	//
	// Enable master interrupt so that any of the filter interrupts can trigger
	// by SDFM interrupt to CPU
	//
	SDFM_enableMainInterrupt(SDFMx_BASE);

    Interrupt_register(SDFM1DR1_IRQn, sdfm1ISR);
    Interrupt_setPriority(SDFM1DR1_IRQn, 0, 0);
    Interrupt_enable(SDFM1DR1_IRQn);
    ECLIC_EnableIRQ(SDFM1DR1_IRQn);

    Interrupt_register(SDFM2DR1_IRQn, sdfm2ISR);
    Interrupt_setPriority(SDFM2DR1_IRQn, 0, 0);
    Interrupt_enable(SDFM2DR1_IRQn);
    ECLIC_EnableIRQ(SDFM2DR1_IRQn);
	//
	// Enable Global Interrupt (INTM)
	//
	CPU_enableIrq();
	while (1) {

	}

	return 0;
}


//*****************************************************************************
//
// sdfm1ISR - SDFM1 Interrupt Service Routine
//
// This function handles SDFM1 interrupts, checking for modulator failures
// and incrementing the corresponding counter when a failure is detected.
//
//*****************************************************************************
__INTERRUPT void sdfm1ISR(void) {
	volatile uint32_t sdfmReadFlagRegister = 0;
	static uint16_t loopCounter1 = 0;

	SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_1,
			SDFM_DATA_FORMAT_16_BIT);
	SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_2,
			SDFM_DATA_FORMAT_16_BIT);
	SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_3,
			SDFM_DATA_FORMAT_16_BIT);
	SDFM_setOutputDataFormat(SDFM1_BASE, SDFM_FILTER_4,
			SDFM_DATA_FORMAT_16_BIT);

	//
	// Read SDFM flag register (SDIFLG)
	//
	sdfmReadFlagRegister = HWREG(SDFM1_BASE + SDFM_O_SDIFLG);

	if (loopCounter1 < MAX_SAMPLES) {
		//
		// Read each SDFM filter output and store it in respective filter
		// result array
		//
		printf("THE ITERATION: %d\r\n", loopCounter1);
		if (sdfmReadFlagRegister & SDFM_FILTER_1_NEW_DATA_FLAG)
			filter1Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM1_BASE, SDFM_FILTER_1) >> 16U);
			printf("filter1 value is %d\r\n", filter1Result[loopCounter1]);
		if (sdfmReadFlagRegister & SDFM_FILTER_2_NEW_DATA_FLAG)
			filter2Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM1_BASE, SDFM_FILTER_2) >> 16U);
			printf("filter2 value is %d\r\n", filter2Result[loopCounter1]);
		if (sdfmReadFlagRegister & SDFM_FILTER_3_NEW_DATA_FLAG)
			filter3Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM1_BASE, SDFM_FILTER_3) >> 16U);
			printf("filter3 value is %d\r\n", filter3Result[loopCounter1]);
		if (sdfmReadFlagRegister & SDFM_FILTER_4_NEW_DATA_FLAG)
			filter4Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM1_BASE, SDFM_FILTER_4) >> 16U);
			printf("filter4 value is %d\r\n", filter4Result[loopCounter1]);
		loopCounter1 ++;
		if (sdfmReadFlagRegister & SDFM_FILTER_1_MOD_FAILED_FLAG)
			MF1cnt++;
		if (sdfmReadFlagRegister & SDFM_FILTER_2_MOD_FAILED_FLAG)
			MF2cnt++;
		if (sdfmReadFlagRegister & SDFM_FILTER_3_MOD_FAILED_FLAG)
			MF3cnt++;
		if (sdfmReadFlagRegister & SDFM_FILTER_4_MOD_FAILED_FLAG)
			MF4cnt++;

		//
		// Clear SDFM flag register (SDIFLG)
		//
		SDFM_clearInterruptFlag(SDFM1_BASE, SDFM_MAIN_INTERRUPT_FLAG | 0xFFFFFFFF);

		//
		// For Test
		//
		sdfmReadFlagRegister = HWREG(SDFM1_BASE + SDFM_O_SDIFLG);
	} else {
//        ESTOP0;
//        done();
		asm volatile("NOP");
	}

}


//*****************************************************************************
//
// sdfm2ISR - SDFM2 Interrupt Service Routine
//
// This function handles SDFM2 interrupts, checking for modulator failures
// and incrementing the corresponding counter when a failure is detected.
//
//*****************************************************************************
__INTERRUPT void sdfm2ISR(void) {
	uint32_t sdfmReadFlagRegister = 0;
	static uint16_t loopCounter1 = 0;

	SDFM_setOutputDataFormat(SDFM2_BASE, SDFM_FILTER_1,
			SDFM_DATA_FORMAT_16_BIT);

	SDFM_setOutputDataFormat(SDFM2_BASE, SDFM_FILTER_2,
			SDFM_DATA_FORMAT_16_BIT);

	SDFM_setOutputDataFormat(SDFM2_BASE, SDFM_FILTER_3,
			SDFM_DATA_FORMAT_16_BIT);

	SDFM_setOutputDataFormat(SDFM2_BASE, SDFM_FILTER_4,
			SDFM_DATA_FORMAT_16_BIT);

	//
	// Read SDFM flag register (SDIFLG)
	//
	sdfmReadFlagRegister = HWREG(SDFM2_BASE + SDFM_O_SDIFLG);

	if (loopCounter1 < MAX_SAMPLES) {
		//
		// Read each SDFM filter output and store it in respective filter
		// result array
		//
		//
		// Read each SDFM filter output and store it in respective filter
		// result array
		//
		printf("THE ITERATION: %d\r\n", loopCounter1);
		if (sdfmReadFlagRegister & SDFM_FILTER_1_NEW_DATA_FLAG)
			filter1Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM2_BASE, SDFM_FILTER_1) >> 16U);
			printf("filter1 value is %d\r\n", filter1Result[loopCounter1]);
		if (sdfmReadFlagRegister & SDFM_FILTER_2_NEW_DATA_FLAG)
			filter2Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM2_BASE, SDFM_FILTER_2) >> 16U);
			printf("filter2 value is %d\r\n", filter2Result[loopCounter1]);
		if (sdfmReadFlagRegister & SDFM_FILTER_3_NEW_DATA_FLAG)
			filter3Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM2_BASE, SDFM_FILTER_3) >> 16U);
			printf("filter3 value is %d\r\n", filter3Result[loopCounter1]);
		if (sdfmReadFlagRegister & SDFM_FILTER_4_NEW_DATA_FLAG)
			filter4Result[loopCounter1] = (int16_t) (SDFM_getFilterData(
					SDFM2_BASE, SDFM_FILTER_4) >> 16U);
			printf("filter4 value is %d\r\n", filter4Result[loopCounter1]);
		loopCounter1 ++;
		if (sdfmReadFlagRegister & SDFM_FILTER_1_MOD_FAILED_FLAG)
			MF1cnt++;
		if (sdfmReadFlagRegister & SDFM_FILTER_2_MOD_FAILED_FLAG)
			MF2cnt++;
		if (sdfmReadFlagRegister & SDFM_FILTER_3_MOD_FAILED_FLAG)
			MF3cnt++;
		if (sdfmReadFlagRegister & SDFM_FILTER_4_MOD_FAILED_FLAG)
			MF4cnt++;
		//
		// Clear SDFM flag register
		//
		SDFM_clearInterruptFlag(SDFM2_BASE,
				(SDFM_MAIN_INTERRUPT_FLAG | 0xFFFF));

		sdfmReadFlagRegister = HWREG(SDFM2_BASE + SDFM_O_SDIFLG);

		if (sdfmReadFlagRegister != 0x0) {
//            ESTOP0;
			asm volatile("NOP");
		}
	} else {

//        ESTOP0;
//        done();
		asm volatile("NOP");
	}

}

//*****************************************************************************
//
// configureSDFMPins - Configures GPIO pins for SDFM operation
//
// This function initializes the GPIO pins required for SDFM module operation.
// It sets up the pins for clock and data signals according to the selected
// SDFM module configuration.
//
//*****************************************************************************
void configureSDFM2Pins(void) {
	//
	//SDFM2 SD1_C3 _GP53
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C3_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C3_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD1_D3 _GP52
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D3_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D3_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD1_C4 _GP55
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C4_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C4_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD1_D4 _GP22
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D4_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D4_GPIO, GPIO_DIR_MODE_IN);
	//
	// SDFM2 Pin Mux
	//SDFM2 SD1_C1 _GP17
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C1_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C1_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD1_D1 _GP16
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D1_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D1_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD1_C2 _GP19
	//
	GPIO_setPinConfig(mySDFM2_SDFM2C2_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2C2_GPIO, GPIO_DIR_MODE_IN);

	//
	//SDFM2 SD1_D2 _GP18
	//
	GPIO_setPinConfig(mySDFM2_SDFM2D2_PIN_CONFIG);
	GPIO_setDirectionMode(mySDFM2_SDFM2D2_GPIO, GPIO_DIR_MODE_IN);



}


void configureSDFM1Pins(void) {
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

}
