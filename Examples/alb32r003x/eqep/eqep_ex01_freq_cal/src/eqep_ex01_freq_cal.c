/**
 *************************************************************************************
 * @file eqep_ex01_freq_cal.c
 * @brief This file contains the source file for example eqep_ex01_freq_cal.
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

#ifdef __cplusplus
extern "C"{
#endif

//*****************************************************************************
//
// Include Files
//
//*****************************************************************************
#include <stdio.h>
#include "eqep_ex01_calculation.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define TB_CLK    (SystemClock_Get_AHB())                                    //!< Time base clock frequency
#define PWM_CLK   5000                                          //!< PWM output frequency (5 kHz)
#define PRD_VAL   (TB_CLK / (PWM_CLK * 2))                      //!< PWM period value for up-down count mode


//
// Base/max frequency is 10 kHz
//
#define BASE_FREQ       10000                                  //!< Base/max frequency (10 kHz)

//
// See Equation 5 in eqep_ex01_calculation.c
//
#define FREQ_SCALER_PR  (((TB_CLK / 128) * 256) / (2 * BASE_FREQ)) //!< Capture counter frequency scaler

//
// See Equation 2 in eqep_ex01_calculation.c
//
#define FREQ_SCALER_FR  ((BASE_FREQ * 2) / 100)                //!< Position counter frequency scaler


//
// EQEP1 -> myEQEP Pinmux
//
//
// EQEP1_A - GPIO Settings
//
#define GPIO_PIN_EQEP1_A 10                                     //!< GPIO pin for EQEP1_A
#define myEQEP0_EQEPA_GPIO 10                                   //!< GPIO number for EQEP1_A
#define myEQEP0_EQEPA_PIN_CONFIG GPIO_10_EQEP1_A                //!< Pin configuration for EQEP1_A
//
// EQEP1_B - GPIO Settings
//
#define GPIO_PIN_EQEP1_B 11                                     //!< GPIO pin for EQEP1_B
#define myEQEP0_EQEPB_GPIO 11                                   //!< GPIO number for EQEP1_B
#define myEQEP0_EQEPB_PIN_CONFIG GPIO_11_EQEP1_B                //!< Pin configuration for EQEP1_B

//
// EQEP2 -> myEQEP Pinmux
//
//
// EQEP2_A - GPIO Settings
//
#define GPIO_PIN_EQEP2_A 14                                     //!< GPIO pin for EQEP2_A
#define myEQEP1_EQEPA_GPIO 14                                   //!< GPIO number for EQEP2_A
#define myEQEP1_EQEPA_PIN_CONFIG GPIO_14_EQEP2_A                //!< Pin configuration for EQEP2_A
//
// EQEP1_B - GPIO Settings
//
#define GPIO_PIN_EQEP2_B 15                                    //!< GPIO pin for EQEP2_B
#define myEQEP1_EQEPB_GPIO 15                                   //!< GPIO number for EQEP2_B
#define myEQEP1_EQEPB_PIN_CONFIG GPIO_15_EQEP2_B                //!< Pin configuration for EQEP2_B




//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
FreqCal_Object eqep_ex01_freq = {0};

uint32_t eqep_ex01_count = 0;       //!< Counter to check measurement gets saturated
uint32_t eqep_ex01_pass = 0;        //!< Test pass indicator
uint32_t eqep_ex01_fail = 0;        //!< Test fail indicator

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void eqep_ex01_myEQEP0_init();           		//!< Initialize eQEP module configuration
__INTERRUPT void EPWM1XINT_IRQHandler(void);        		//!< ePWM1 interrupt handler for frequency calculation
void eqep_ex01_initEPWM(uint32_t u32PwmBase); 	//!< Initialize ePWM module for test signal generation
void eqep_ex01_GPIO_Init();              		//!< Configure GPIO pins for eQEP and ePWM
int main(void);                         		//!< Main program entry point

//*****************************************************************************
//
// Main program
// Initialize hardware and start eQEP frequency measurement
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();

    eqep_ex01_freq.freqScalerPR = FREQ_SCALER_PR;  //!< Parameter: Scaler converting 1/N cycles to a GLOBAL_Q freq (Q0)
    eqep_ex01_freq.freqScalerFR = FREQ_SCALER_FR;  //!< Parameter: Scaler converting 1/N cycles to a GLOBAL_Q freq (Q0)
    eqep_ex01_freq.baseFreq     = BASE_FREQ;      //!< Parameter: Maximum frequency

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Step 1: Configure GPIO pins for eQEP and ePWM functionality
    //
	eqep_ex01_GPIO_Init();

    //
    // Step 2: Initialize eQEP module with frequency measurement configuration
    //
    eqep_ex01_myEQEP0_init();
    // EQEP_clearStatus(EQEP1_BASE, ( EQEP_STS_CAP_OVRFLW_ERROR));
    
    //
    // Step 3: Initialize ePWM1 to generate a 5 kHz test signal for eQEP input
    //
    eqep_ex01_initEPWM(EPWM1_BASE);
   // HWREG(EQEP1_BASE + EQEP_O_QEPSTS) = 0x88;

    //
    // Step 5: Configure and enable ePWM1 interrupt
    //
    Interrupt_register(EPWM1_IRQn, EPWM1XINT_IRQHandler);
    Interrupt_setPriority(EPWM1_IRQn, 0, 0);
    Interrupt_enable(EPWM1_IRQn);
    ECLIC_EnableIRQ(EPWM1_IRQn);
	CPU_enableIrq();

    //
    // Step 6: Infinite loop - all processing is done in interrupt handler
    //
    while(1)
    {
        ;
    }

}

//*****************************************************************************
//
// Configure GPIO pins for eQEP and ePWM functionality
// Sets up pin muxing for ePWM1A/B and eQEP1A/B signals
//
//*****************************************************************************
void eqep_ex01_GPIO_Init()
{
	//
	// Step 1: Configure GPIO pins for ePWM1 signals
	//
	GPIO_setPinConfig(GPIO_0_EPWM1_A);    // Configure pin for ePWM1A output
	GPIO_setPinConfig(GPIO_1_EPWM1_B);    // Configure pin for ePWM1B output

	//
	// Step 2: Configure GPIO pins for eQEP signals
	//
	GPIO_setPinConfig(myEQEP0_EQEPA_PIN_CONFIG);  // Configure pin for eQEP1A input
	GPIO_setPinConfig(myEQEP0_EQEPB_PIN_CONFIG);  // Configure pin for eQEP1B input

	GPIO_setPinConfig(myEQEP1_EQEPA_PIN_CONFIG);  // Configure pin for eQEP2A input
	GPIO_setPinConfig(myEQEP1_EQEPB_PIN_CONFIG);  // Configure pin for eQEP2B input
}


//*****************************************************************************
//
// Initialize eQEP module configuration
// Configures eQEP for frequency and position measurement with quadrature decoding
//
//*****************************************************************************
void eqep_ex01_myEQEP0_init()
{
	//
	// Step 1: Disable and clear all interrupts and flags
	//
	EQEP_disableInterrupt(myEQEP_BASE,
		(EQEP_INT_GLOBAL      			|		EQEP_INT_POS_CNT_ERROR		|		EQEP_INT_PHASE_ERROR     	|		EQEP_INT_DIR_CHANGE     	|		EQEP_INT_WATCHDOG           	|		EQEP_INT_UNDERFLOW          	|		EQEP_INT_OVERFLOW         	|		EQEP_INT_POS_COMP_READY     	|		EQEP_INT_POS_COMP_MATCH    	|		EQEP_INT_STROBE_EVNT_LATCH	|		EQEP_INT_INDEX_EVNT_LATCH  	|		EQEP_INT_UNIT_TIME_OUT    	|		EQEP_INT_QMA_ERROR));
	EQEP_clearInterruptStatus(myEQEP_BASE,
		(EQEP_INT_GLOBAL      			|		EQEP_INT_POS_CNT_ERROR		|		EQEP_INT_PHASE_ERROR     	|		EQEP_INT_DIR_CHANGE     	|		EQEP_INT_WATCHDOG           	|		EQEP_INT_UNDERFLOW          	|		EQEP_INT_OVERFLOW         	|		EQEP_INT_POS_COMP_READY     	|		EQEP_INT_POS_COMP_MATCH    	|		EQEP_INT_STROBE_EVNT_LATCH	|		EQEP_INT_INDEX_EVNT_LATCH  	|		EQEP_INT_UNIT_TIME_OUT    	|		EQEP_INT_QMA_ERROR));

	EQEP_enableInterrupt(myEQEP_BASE, EQEP_INT_UNIT_TIME_OUT);

	//
	// Set strobe input source to GPIO
	//
	EQEP_setStrobeSource(myEQEP_BASE, EQEP_STROBE_FROM_GPIO);
		
	//
	// Set input signal polarity (no inversion)
	//
	EQEP_setInputPolarity(myEQEP_BASE, false, false, false, false);
		
	//
	// Configure quadrature decoder with 2x resolution
	//
	EQEP_setDecoderConfig(myEQEP_BASE, (EQEP_CONFIG_UP_COUNT | EQEP_CONFIG_2X_RESOLUTION | EQEP_CONFIG_NO_SWAP | EQEP_CONFIG_IGATE_DISABLE));
	
	//
	// Step 3: Configure position counter and timing parameters
	//
	// Set emulation mode to stop immediately when debugging
	EQEP_setEmulationMode(myEQEP_BASE, EQEP_EMULATIONMODE_STOPIMMEDIATELY);
	
	//
	// Configure position counter to reset on first index pulse
	//
	EQEP_setPositionCounterConfig(myEQEP_BASE, EQEP_POSITION_RESET_1ST_IDX, 4294967295U);
	
	//
	// Initialize position counter to 0
	//
	EQEP_setPosition(myEQEP_BASE, 0U);
	
	//
	// Enable unit timer with 10ms period (TB_CLK/100)
	//
	EQEP_enableUnitTimer(myEQEP_BASE, TB_CLK/100);
	//
	// Step 4: Configure additional eQEP features
	//
	// Disable watchdog timer
	EQEP_disableWatchdog(myEQEP_BASE);
		
	//
	// Configure position latch modes
	//
	EQEP_setLatchMode(myEQEP_BASE, (EQEP_LATCH_UNIT_TIME_OUT|EQEP_LATCH_RISING_STROBE|EQEP_LATCH_RISING_INDEX));
		
	//
	// Bypass quadrature mode adapter
	//
	EQEP_setQMAModuleMode(myEQEP_BASE, EQEP_QMA_MODE_BYPASS);
		
	//
	// Disable direction change during index pulse
	//
	EQEP_disableDirectionChangeDuringIndex(myEQEP_BASE);
	//
	// Step 5: Configure position initialization and enable module
	//
	// Set position initialization mode
	EQEP_setPositionInitMode(myEQEP_BASE, (EQEP_INIT_DO_NOTHING));
	
	//
	// Enable software position initialization
	//
	EQEP_setSWPositionInit(myEQEP_BASE, true);
	
	//
	// Set initial position value
	//
	EQEP_setInitialPosition(myEQEP_BASE, 0U);
		
	//
	// Enable eQEP module
	//
	EQEP_enableModule(myEQEP_BASE);

	//
	// Step 6: Configure edge-capture unit for frequency measurement
	//
	//QCTME MAX TIME = 1 / SYSTICK * 128 * 65535 = 0.53333 * 65535 = 34.952ms
	//UPEVENT TIME = 1 / EPWM_FRE / 2 * 256 = 1 / 5000 / 2 * 256 = 25.6ms
	//
	EQEP_setCaptureConfig(myEQEP_BASE, EQEP_CAPTURE_CLK_DIV_128, EQEP_UNIT_POS_EVNT_DIV_256);
		
	//
	// Enable edge-capture unit
	//
	EQEP_enableCapture(myEQEP_BASE);
}

//*****************************************************************************
//
// Initialize ePWM module for test signal generation
// Configures ePWM to output square wave signals for eQEP frequency measurement
//
//*****************************************************************************
void eqep_ex01_initEPWM(uint32_t u32PwmBase)
{
    //
    // Step 1: Optional time base clock control (disabled in current configuration)
    //
		#if 1
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
		#endif

    //
    // Step 2: Initialize time base parameters
    //
    // Set phase shift to 0 degrees
	//
    EPWM_setPhaseShift(u32PwmBase, 0);

	//
    // Set period value for 50% duty cycle
	//
    EPWM_setTimeBasePeriod(u32PwmBase, PRD_VAL);
    
    // Clear time base counter
    EPWM_setTimeBaseCounter(u32PwmBase, 0);

    //
    // Step 3: Configure compare registers
    //
    // Disable shadow loading for immediate updates
	//
    EPWM_disableCounterCompareShadowLoadMode(u32PwmBase, EPWM_COUNTER_COMPARE_A);
    EPWM_disableCounterCompareShadowLoadMode(u32PwmBase, EPWM_COUNTER_COMPARE_B);

	//
    // Set compare A value for 50% duty cycle
	//
    EPWM_setCounterCompareValue(u32PwmBase, EPWM_COUNTER_COMPARE_A, PRD_VAL/2);
    EPWM_setCounterCompareValue(u32PwmBase, EPWM_COUNTER_COMPARE_B, 0);
    //
    // Step 4: Configure action qualifier for EPWM1A output
    //
    // Set EPWM1A high when counter matches CMPA while counting up
	//
    EPWM_setActionQualifierAction(u32PwmBase, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    
	//
	// Set EPWM1A low when counter matches CMPA while counting down
	//
    EPWM_setActionQualifierAction(u32PwmBase, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

	// Alternative configuration (commented out)
    //EPWM_setActionQualifierAction(u32PwmBase, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    //EPWM_setActionQualifierAction(u32PwmBase, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    //
    // Step 5: Configure dead band for complementary outputs
    //
    // Set dead band falling edge delay polarity
    EPWM_setDeadBandDelayPolarity(u32PwmBase, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);
    
	//
	// Enable falling edge dead band delay
	//
    EPWM_setDeadBandDelayMode(u32PwmBase, EPWM_DB_FED, true);
	
	//
    // Enable rising edge dead band delay
	//
    EPWM_setDeadBandDelayMode(u32PwmBase, EPWM_DB_RED, true);

    //
    // Step 6: Configure ePWM interrupt
    //
    // Set interrupt source to time base counter zero event
	//
    EPWM_setInterruptSource(u32PwmBase, EPWM_INT_TBCTR_ZERO);

	//
    // Enable ePWM interrupt
	//
    EPWM_enableInterrupt(u32PwmBase);

	//
    // Generate interrupt on every event
	//
    EPWM_setInterruptEventCount(u32PwmBase, 1);

    //
    // Step 7: Configure time base clock and counting mode
    //
    // Set clock prescaler to 1:1
	//
    EPWM_setClockPrescaler(u32PwmBase, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

	//
    // Set period load mode to direct load (no shadowing)
	//
    EPWM_setPeriodLoadMode(u32PwmBase, EPWM_PERIOD_DIRECT_LOAD);

	//
    // Set time base period value
	//
    EPWM_setTimeBasePeriod(u32PwmBase, PRD_VAL);

	//
    // Set counter mode to up-down counting
	//
    EPWM_setTimeBaseCounterMode(u32PwmBase, EPWM_COUNTER_MODE_UP_DOWN);

	//
    // Enable time base clock synchronization
	//
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

}


//*****************************************************************************
//
// ePWM1 ISR - interrupts once per ePWM period
// Performs frequency calculation and validation
//
//*****************************************************************************
__INTERRUPT void EPWM1XINT_IRQHandler(void)
{
    //
    // Step 1: Perform frequency calculation using eQEP measurements
    //
    eqep_ex01_FreqCal_calculate(&eqep_ex01_freq, &eqep_ex01_count);

    //
    // Step 2: Validate frequency measurement after saturation
    //
    // After 3 measurement cycles, eQEP measurement stabilizes
    // Check if measured frequency is within +/- 50 Hz of expected PWM frequency
    if (eqep_ex01_count >= 3) {
        if (((eqep_ex01_freq.freqHzFR - PWM_CLK) < 50) && ((eqep_ex01_freq.freqHzFR - PWM_CLK) > -50)) {
            eqep_ex01_pass = 1;  // Measurement within tolerance - pass
            eqep_ex01_fail = 0;
        } else {
            eqep_ex01_fail = 1;  // Measurement outside tolerance - fail
            eqep_ex01_pass = 0;
        }
    }

    //
    // Step 3: Clear ePWM interrupt flag
    //
    EPWM_clearEventTriggerInterruptFlag(EPWM1_BASE);

}




#ifdef __cplusplus
}
#endif

/*****END OF FILE****/
