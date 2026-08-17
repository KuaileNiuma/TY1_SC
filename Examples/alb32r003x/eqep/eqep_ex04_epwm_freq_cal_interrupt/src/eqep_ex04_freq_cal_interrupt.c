/**
 *************************************************************************************
 * @file eqep_ex04_freq_cal_interrupt.c
 * @brief This file contains the source file for example eqep_ex04_freq_cal_interrupt.
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

#include "device.h"
#include "alb32r003x_evb.h"


//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************

#define TB_CLK    (SystemClock_Get_AHB())                        //!< Time base clock frequency (Hz)
#define PWM_CLK   5000                           //!< Desired PWM output frequency (5 kHz)
#define PRD_VAL   (TB_CLK / (PWM_CLK * 2))       //!< Period value for up-down count mode
#define UNIT_PERIOD  10000U                      //!< Specify the unit timeout period in microseconds
 //
// EQEP1 -> myEQEP0 Pinmux
//
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
#define myEQEP_BASE EQEP1_BASE                    //!< eQEP module base address


//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
#define  eqep_ex04_ans_size  5                      //!< Size of answer array

uint32_t eqep_ex04_oldcount = 0;  //!< Stores the previous position counter value
int32_t eqep_ex04_freq = 0;       //!< Measured frequency using eQEP
uint32_t eqep_ex04_count = 0;     //!< Counter to ensure measured frequency gets saturated
uint32_t eqep_ex04_pass = 0, eqep_ex04_fail = 0; //!< Test pass or fail indicator
uint32_t eqep_ex04_ans[eqep_ex04_ans_size];      //!< Answer array

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void eqep_ex04_myEQEP0_init();
void eqep_ex04_initEPWM(void);
__INTERRUPT void EQEP1ISR(void);
//*****************************************************************************
//
// Initialize GPIO pins for eQEP and ePWM
//
//*****************************************************************************
void eqep_ex04_GPIO_Init();

//*****************************************************************************
//
// Main
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    //
    // Disable pin locks and enable internal pullups.
    //
	eqep_ex04_GPIO_Init();


    //
    // Board Initialization
    // - Setup eQEP1, configuring the unit timer and quadrature capture units
    // - Initialize GPIOs for EQEP1A
    // - Interrupts that are used in this example are re-mapped to ISR functions
    //   found within this file.
    // - Enable interrupts required for this example
    //


    eqep_ex04_myEQEP0_init();



    //
    // Setup ePWM1 to generate a 5 kHz signal to be an input to the eQEP
    //
    eqep_ex04_initEPWM();

    Interrupt_register(EQEP1_IRQn, EQEP1ISR);
    Interrupt_setPriority(EQEP1_IRQn, 0, 0);
    Interrupt_enable(EQEP1_IRQn);
    ECLIC_EnableIRQ(EQEP1_IRQn);
    Interrupt_register(EQEP2_IRQn, EQEP1ISR);
    Interrupt_setPriority(EQEP2_IRQn, 0, 0);
    Interrupt_enable(EQEP2_IRQn);
    ECLIC_EnableIRQ(EQEP2_IRQn);
	CPU_enableIrq();




		#if 0
    EINT;
    ERTM;
		#endif

    //
    // Loop indefinitely
    //

    while(1)
    {
        ;
    }


}

//*****************************************************************************
//
// Initialize GPIO pins for eQEP and ePWM
//
//*****************************************************************************
void eqep_ex04_GPIO_Init()
{
	//
	// EPWM1 -> myEPWM1 Pinmux
	//
	GPIO_setPinConfig(GPIO_0_EPWM1_A);

    //
	//eqep1A
    //
	GPIO_setPinConfig(myEQEP0_EQEPA_PIN_CONFIG);

    //
    //eqep1B
    //
	GPIO_setPinConfig(myEQEP0_EQEPB_PIN_CONFIG);

    //
    //eqep1I
    //
	GPIO_setPinConfig(myEQEP0_EQEPINDEX_PIN_CONFIG);

    //
	//eqep2A
    //
	GPIO_setPinConfig(myEQEP1_EQEPA_PIN_CONFIG);

    //
    //eqep2B
    //
	GPIO_setPinConfig(myEQEP1_EQEPB_PIN_CONFIG);

    //
    //eqep2I
    //
	GPIO_setPinConfig(myEQEP1_EQEPINDEX_PIN_CONFIG);
}


//*****************************************************************************
//
// Configure eQEP1 module
//
//*****************************************************************************
void eqep_ex04_myEQEP0_init()
{
	//
	// Disable, clear all flags and interrupts
	//
	EQEP_disableInterrupt(myEQEP_BASE,
		(EQEP_INT_GLOBAL     		|
		EQEP_INT_POS_CNT_ERROR		|
		EQEP_INT_PHASE_ERROR    	|
		EQEP_INT_DIR_CHANGE    		|
		EQEP_INT_WATCHDOG          	|
		EQEP_INT_UNDERFLOW         	|
		EQEP_INT_OVERFLOW        	|
		EQEP_INT_POS_COMP_READY    	|
		EQEP_INT_POS_COMP_MATCH   	|
		EQEP_INT_STROBE_EVNT_LATCH	|
		EQEP_INT_INDEX_EVNT_LATCH 	|
		EQEP_INT_UNIT_TIME_OUT   	|
		EQEP_INT_QMA_ERROR));
	EQEP_clearInterruptStatus(myEQEP_BASE,
		(EQEP_INT_GLOBAL     		|
		EQEP_INT_POS_CNT_ERROR		|
		EQEP_INT_PHASE_ERROR    	|
		EQEP_INT_DIR_CHANGE    		|
		EQEP_INT_WATCHDOG          	|
		EQEP_INT_UNDERFLOW         	|
		EQEP_INT_OVERFLOW        	|
		EQEP_INT_POS_COMP_READY    	|
		EQEP_INT_POS_COMP_MATCH   	|
		EQEP_INT_STROBE_EVNT_LATCH	|
		EQEP_INT_INDEX_EVNT_LATCH 	|
		EQEP_INT_UNIT_TIME_OUT   	|
		EQEP_INT_QMA_ERROR));
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
	EQEP_setEmulationMode(myEQEP_BASE,EQEP_EMULATIONMODE_RUNFREE);
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
	// Enables individual eQEP module interrupt sources.
	//
	EQEP_enableInterrupt(myEQEP_BASE,(EQEP_INT_UNIT_TIME_OUT));
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
}

//*****************************************************************************
//
// Configure ePWM1 to generate a 5 kHz signal
//
//*****************************************************************************
void eqep_ex04_initEPWM(void)
{
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
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, 0);

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



    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

}


//*****************************************************************************
//
// eQEP1 interrupt service routine
// Interrupts once per eQEP period
//
//*****************************************************************************
__INTERRUPT void EQEP1ISR(void)
{

    uint32_t temp =0, newcount = 0 ;

    //
    // Increment count value so to wait for frequency saturation
    //
    eqep_ex04_count++;

    //
    // Get the latest position counter value
    //
    newcount = EQEP_getPositionLatch(myEQEP_BASE);
    temp = newcount;

    //
    // Calculates the number of position counts in unit time
    //
    if (newcount >= eqep_ex04_oldcount)
        newcount = newcount - eqep_ex04_oldcount;
    else
        newcount = (0xFFFFFFFF - eqep_ex04_oldcount) + newcount;

    //
    // Stores the current position count value to eqep_ex04_oldcount variable
    //
    eqep_ex04_oldcount = temp;

    //
    // Frequency calculation equation i.e
    // eqep_e0x4_freq = ((position counts) * 1000000 )/ (2 * Unit_time (in microseconds))
    //
    eqep_ex04_freq = (newcount * (uint32_t)1000000U)/(2 * (uint32_t)UNIT_PERIOD);

    //
    // Compares the measured frequency with input frequency
    //
    if (eqep_ex04_count >= 2){
        if (((eqep_ex04_freq - PWM_CLK) < 50) && ((eqep_ex04_freq - PWM_CLK) > -50)){
            eqep_ex04_pass = 1; eqep_ex04_fail = 0;
            printf("eqep_ex04 success.\r\n");
            printf("the value is %d\r\n", eqep_ex04_freq);
        }
        else {
            eqep_ex04_fail = 1; eqep_ex04_pass = 0;
            printf("eqep_ex04 fail.\r\n");
        }
    }

    //
    // Clears the interrupt flag
    //
    EQEP_clearInterruptStatus(myEQEP_BASE,EQEP_INT_UNIT_TIME_OUT|EQEP_INT_GLOBAL);

}

#ifdef __cplusplus
}
#endif

