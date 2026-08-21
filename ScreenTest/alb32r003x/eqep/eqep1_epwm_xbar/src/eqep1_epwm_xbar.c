/**
 *************************************************************************************
 * @file eqep1_epwm_xbar.c
 * @brief This file contains the source file for example eqep1_epwm_xbar.
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
 
#include <stdio.h>
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"

#include "eqep_ex03_calculation.h"
//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define eqep_ex03_ans_size  5                      //!< Size of answer array
#define TB_CLK    (SystemClock_Get_AHB())         //!< Time base clock frequency (Hz)

#define PWM_CLK   5000                            //!< Desired PWM output frequency (5 kHz)
#define PRD_VAL   (TB_CLK / (PWM_CLK * 2))        //!< Period value for up-down count mode
#define BASE_FREQ       10000                     //!< Base/max frequency reference (10 kHz)
#define FREQ_SCALER_PR  (((TB_CLK / 128) * 256) / (2 * BASE_FREQ))  //!< Period measurement scaler
#define FREQ_SCALER_FR  ((BASE_FREQ * 2) / 100)   //!< Frequency measurement scaler


//
// EQEP1 -> myEQEP0 Pinmux
//
//
// EQEP1_A - GPIO Settings
//
// EQEP1_A - GPIO Settings
//
#define GPIO_PIN_EQEP1_A 10                       //!< GPIO pin number for EQEP1_A
#define myEQEP0_EQEPA_GPIO 10                      //!< GPIO pin for EQEP1_A
#define myEQEP0_EQEPA_PIN_CONFIG GPIO_10_EQEP1_A   //!< GPIO configuration for EQEP1_A

//
// EQEP1_B - GPIO Settings
//
#define GPIO_PIN_EQEP1_B 11                        //!< GPIO pin number for EQEP1_B
#define myEQEP0_EQEPB_GPIO 11                      //!< GPIO pin for EQEP1_B
#define myEQEP0_EQEPB_PIN_CONFIG GPIO_11_EQEP1_B   //!< GPIO configuration for EQEP1_B

//
// EQEP1_INDEX - GPIO Settings
//
#define GPIO_PIN_EQEP1_INDEX 23                           //!< GPIO pin number for EQEP1_INDEX
#define myEQEP0_EQEPINDEX_GPIO 23                         //!< GPIO pin for EQEP1_INDEX
#define myEQEP0_EQEPINDEX_PIN_CONFIG GPIO_23_EQEP1_INDEX  //!< GPIO configuration for EQEP1_INDEX


//
// EQEP2_A - GPIO Settings
//
#define GPIO_PIN_EQEP2_A 14                                     //!< GPIO pin for EQEP2_A
#define myEQEP1_EQEPA_GPIO 14                                   //!< GPIO number for EQEP2_A
#define myEQEP1_EQEPA_PIN_CONFIG GPIO_14_EQEP2_A                //!< Pin configuration for EQEP2_A
//
// EQEP2_B - GPIO Settings
//
#define GPIO_PIN_EQEP2_B 15                                    //!< GPIO pin for EQEP2_B
#define myEQEP1_EQEPB_GPIO 15                                   //!< GPIO number for EQEP2_B
#define myEQEP1_EQEPB_PIN_CONFIG GPIO_15_EQEP2_B                //!< Pin configuration for EQEP2_B

//
// EQEP2_INDEX - GPIO Settings
//
#define GPIO_PIN_EQEP2_INDEX 26                 //!< GPIO pin number for EQEP1_INDEX
#define myEQEP1_EQEPINDEX_GPIO 26               //!< GPIO pin for EQEP1_INDEX
#define myEQEP1_EQEPINDEX_PIN_CONFIG GPIO_26_EQEP2_INDEX //!< GPIO configuration for EQEP1_INDEX
//
// EQEP1 -> myEQEP0 Pinmux Configuration
//


//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
FreqCal_Object eqep_ex03_freq = {0};

uint32_t eqep_ex03_count =0;                   //!< counter to check measurement gets saturated
uint32_t eqep_ex03_pass=0, eqep_ex03_fail =0;   //!< Pass or fail indicator

//
//Temprory
//
int eqep_ex03_ans[eqep_ex03_ans_size];
int eqep_ex03_fre[200]={0};

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void eqep_ex03_myEQEP0_init();


//*****************************************************************************
//
// Initializes the EPWM module to generate a 5 kHz signal
//
//***************************************************************************** 
void eqep_ex03_initEPWM(void);

//***************************************************************************** 
//
// EPWM1 interrupt handler that processes frequency measurement
//
//***************************************************************************** 
__INTERRUPT void EPWM1XINTISR(void);



//***************************************************************************** 
//
// Main program entry point
//
//***************************************************************************** 
int main(void)
{
	alb32r003x_evb_init();

    eqep_ex03_freq.freqScalerPR = FREQ_SCALER_PR;  //!< Parameter: Scaler converting 1/N cycles to a GLOBAL_Q freq (Q0)
    eqep_ex03_freq.freqScalerFR = FREQ_SCALER_FR;  //!< Parameter: Scaler converting 1/N cycles to a GLOBAL_Q freq (Q0)
    eqep_ex03_freq.baseFreq     = BASE_FREQ;      //!< Parameter: Maximum frequency


	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    //
    // Reset eQEP / EPWM / XBAR modules before test to clear any stale state
    //
    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_EQEP1);
    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_EPWM1);
    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_XBAR);
    //
    // Disable pin locks and enable internal pullups.
    //
    GPIO_setDirectionMode(15, GPIO_DIR_MODE_IN);
    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT1, 15);
    //
    // Route Input XBAR INPUT1 to ePWM XBAR MUX01 -> PWMXBAR1,
    // which is selected as eQEP1A input source via EQEP1_CFG (SEL=9).
    //
    XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX01);
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX01_INPUTXBAR1);

	GPIO_setPinConfig(GPIO_0_EPWM1_A);    // Configure pin for ePWM1A output
//	GPIO_setPinConfig(GPIO_1_EPWM1_B);    // Configure pin for ePWM1B output
    //
    // Board Initialization
    // Setup eQEP1, configuring the unit timer and quadrature capture units
    //
    eqep_ex03_myEQEP0_init();


    //
    // Setup ePWM1 to generate a 5 kHz signal to be an input to the eQEP
    //

    eqep_ex03_initEPWM();

    //
    //epeq1a
    //

    Interrupt_register(EPWM1_IRQn, EPWM1XINTISR);
    Interrupt_setPriority(EPWM1_IRQn, 0, 0);
    Interrupt_enable(EPWM1_IRQn);
    ECLIC_EnableIRQ(EPWM1_IRQn);
	CPU_enableIrq();

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
		#if 0
    EINT;
    ERTM;
		#endif

    //
    // Setup eQEP1, configuring the unit timer and quadrature capture units
    //

    //
    // Wait for the frequency measurement to complete (ISR sets pass/fail
    // after eqep_ex03_count reaches 3), then return the test result.
    // Add a timeout in case the eQEP never receives a signal.
    //
    {
        uint32_t waitCnt = 0;

        while (eqep_ex03_count < 3)
        {
            if (++waitCnt > 50000000U)
            {
                printf("EQEP measurement timeout\r\n");
                return SC_FAIL;
            }
        }
    }

    if (eqep_ex03_pass == 1)
    {
        printf("EQEP frequency measurement OK: %d Hz\r\n", eqep_ex03_freq.freqHzFR);
        return SC_PASS;
    }

    printf("EQEP frequency measurement fail: %d Hz\r\n", eqep_ex03_freq.freqHzFR);
    return SC_FAIL;
}



void eqep_ex03_myEQEP0_init()
{
	HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) |=  0x009;
	HWREG(SYSCTL_BASE + SYSCTL_O_EQEP2_CFG) |=  0x009;

	//
	// Set the strobe input source of the eQEP module.
	//
	EQEP_setStrobeSource(myEQEP_BASE,EQEP_STROBE_FROM_GPIO);
	//
	// Sets the polarity of the eQEP module's input signals.
	//
	EQEP_setInputPolarity(myEQEP_BASE,false,false,false,false);
	//
	// Configures eQEP module's quadrature decoder unit.
	//
	EQEP_setDecoderConfig(myEQEP_BASE, (EQEP_CONFIG_UP_COUNT | EQEP_CONFIG_2X_RESOLUTION | EQEP_CONFIG_NO_SWAP | EQEP_CONFIG_IGATE_DISABLE));
	//
	// Set the emulation mode of the eQEP module.
	//
	EQEP_setEmulationMode(myEQEP_BASE,EQEP_EMULATIONMODE_STOPIMMEDIATELY);
	//
	// Configures eQEP module position counter unit.
	//
	EQEP_setPositionCounterConfig(myEQEP_BASE,EQEP_POSITION_RESET_IDX,4294967295U);
	//
	// Sets the current encoder position.
	//
	EQEP_setPosition(myEQEP_BASE,0U);
	//
	// Enables the eQEP module unit timer.
	//
	EQEP_enableUnitTimer(myEQEP_BASE,TB_CLK/100);
	//
	// Disables the eQEP module watchdog timer.
	//
	EQEP_disableWatchdog(myEQEP_BASE);
	//
	// Configures the quadrature modes in which the position count can be latched.
	//
	EQEP_setLatchMode(myEQEP_BASE,(EQEP_LATCH_UNIT_TIME_OUT|EQEP_LATCH_RISING_STROBE|EQEP_LATCH_RISING_INDEX));
	//
	// Set the quadrature mode adapter (QMA) module mode.
	//
	EQEP_setQMAModuleMode(myEQEP_BASE,EQEP_QMA_MODE_BYPASS);
	//
	// Disable Direction Change During Index
	//
	EQEP_disableDirectionChangeDuringIndex(myEQEP_BASE);
	//
	// Configures the mode in which the position counter is initialized.
	//
	EQEP_setPositionInitMode(myEQEP_BASE,(EQEP_INIT_DO_NOTHING));
	//
	// Sets the software initialization of the encoder position counter.
	//
	EQEP_setSWPositionInit(myEQEP_BASE,true);
	//
	// Sets the init value for the encoder position counter.
	//
	EQEP_setInitialPosition(myEQEP_BASE,0U);
	//
	// Enables the eQEP module.
	//
	EQEP_enableModule(myEQEP_BASE);
	//
	// Configures eQEP module edge-capture unit.
	//
	EQEP_setCaptureConfig(myEQEP_BASE,EQEP_CAPTURE_CLK_DIV_128,EQEP_UNIT_POS_EVNT_DIV_256);
	//
	// Enables the eQEP module edge-capture unit.
	//
	EQEP_enableCapture(myEQEP_BASE);
}

void eqep_ex03_initEPWM(void)
{

	SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
	EPWM_TypeDef* EP;
    //
    // Set phase shift to 0 and clear the time base counter
    //
    EPWM_setPhaseShift(EPWM1_BASE, 0);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0);

    //
    // Disable the shadow load; the load will be immediate instead
    //
    EPWM_disableCounterCompareShadowLoadMode(EPWM1_BASE,
                                             EPWM_COUNTER_COMPARE_A);
    EPWM_disableCounterCompareShadowLoadMode(EPWM1_BASE,
                                             EPWM_COUNTER_COMPARE_B);

    //
    // Set the compare A value to half the period value, compare B to 0
    //
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, PRD_VAL/2);
  //  EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, 0);

    //
    // Set action qualifier behavior on compare A events
    // - EPWM1A --> 1 when CTR = CMPA and increasing
    // - EPWM1A --> 0 when CTR = CMPA and decreasing
    //
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

    //
    // Configure EPWM1B to be complementary to EPWM1A
    //
    EPWM_setDeadBandDelayPolarity(EPWM1_BASE, EPWM_DB_FED,
                                  EPWM_DB_POLARITY_ACTIVE_LOW);
    EPWM_setDeadBandDelayMode(EPWM1_BASE, EPWM_DB_FED, true);
    EPWM_setDeadBandDelayMode(EPWM1_BASE, EPWM_DB_RED, true);

    //
    // Enable interrupt when the counter is equal to 0
    //
    EPWM_setInterruptSource(EPWM1_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(EPWM1_BASE);

    //
    // Interrupt on first event
    //
    EPWM_setInterruptEventCount(EPWM1_BASE, 1);

    //
    // Set the time base clock prescaler to /1
    //
    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    //
    // Set the period value; don't shadow the register
    //
    EPWM_setPeriodLoadMode(EPWM1_BASE, EPWM_PERIOD_DIRECT_LOAD);
    EPWM_setTimeBasePeriod(EPWM1_BASE, PRD_VAL);

    //
    // Put the time base counter into up-down count mode
    //
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP_DOWN);

    //
    // Sync the ePWM time base clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

}


//*****************************************************************************
//
// Function Definitions
//
//*****************************************************************************
__INTERRUPT void EPWM1XINTISR(void)
{
	uint32_t i=0;
    //
    // Checks for events and calculates frequency.
    //
    eqep_ex03_FreqCal_calculate(&eqep_ex03_freq, &eqep_ex03_count);

    //
    // Comparing the eQEP measured frequency with the ePWM frequency
    // After count becomes 3 , eQEP measurement gets saturated and
    // classifying eqep_ex03_pass = 1 if measured frequency is 50 more or
    // less than input
    //
    if (eqep_ex03_count >= 3){

        if (((eqep_ex03_freq.freqHzFR - PWM_CLK) < 60) && ((eqep_ex03_freq.freqHzFR - PWM_CLK) > -60)){
            eqep_ex03_pass = 1; eqep_ex03_fail = 0;
          }
        else {
            eqep_ex03_fail = 1; eqep_ex03_pass = 0;
          }
    }

    //
    // Clear interrupt flag and issue ACK
    //
    EPWM_clearEventTriggerInterruptFlag(EPWM1_BASE);
}


#ifdef __cplusplus
}
#endif

