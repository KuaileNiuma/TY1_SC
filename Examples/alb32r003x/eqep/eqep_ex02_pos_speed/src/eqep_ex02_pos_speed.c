/**
 *************************************************************************************
 * @file eqep_ex02_pos_speed.c
 * @brief This file contains the source file for example eqep_ex02_pos_speed.
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
#include "eqep_ex02_calculation.h"
#include "alb32r003x_evb.h"
//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************

#define sum 15                                 //!< Number of test samples

#define TB_CLK    (SystemClock_Get_AHB())                    //!< Time base clock frequency
#define PWM_CLK   5000                          //!< PWM output frequency (5 kHz = 300 rpm)
//#define PRD_VAL   (TB_CLK / (PWM_CLK * 2))      //!< Period value for up-down count mode
#define PRD_VAL   (TB_CLK / (PWM_CLK * 20))      //!< Period value for up-down count mode

// .9999 / 4000 converted to IQ26 fixed point format
#define MECH_SCALER     16776                   //!< Mechanical scaler for position calculation
// 2 pole pairs in this example
#define POLE_PAIRS      2                       //!< Number of pole pairs in the motor
// Angular offset between encoder and Phase A
#define CAL_ANGLE       0                       //!< Calibration angle offset
// See Equation 5 in eqep_ex02_calculation.c
#define SPEED_SCALER    ((((uint64_t)256 * TB_CLK / 128) * 60) / (24000000)) //!< Speed scaler for RPM calculation
// Base/max rpm is 6000rpm
#define BASE_RPM        6000                    //!< Base/maximum RPM value

//
// EQEP1 -> myEQEP0 Pinmux
//
//
// EQEP1_A - GPIO Settings
//
#define GPIO_PIN_EQEP1_A 10                     //!< GPIO pin number for EQEP1_A
#define myEQEP0_EQEPA_GPIO 10                   //!< GPIO pin for EQEP1_A
#define myEQEP0_EQEPA_PIN_CONFIG GPIO_10_EQEP1_A //!< GPIO configuration for EQEP1_A
//
// EQEP1_B - GPIO Settings
//
#define GPIO_PIN_EQEP1_B 11                     //!< GPIO pin number for EQEP1_B
#define myEQEP0_EQEPB_GPIO 11                   //!< GPIO pin for EQEP1_B
#define myEQEP0_EQEPB_PIN_CONFIG GPIO_11_EQEP1_B //!< GPIO configuration for EQEP1_B

//
// EQEP1_INDEX - GPIO Settings
//
#define GPIO_PIN_EQEP1_INDEX 23                 //!< GPIO pin number for EQEP1_INDEX
#define myEQEP0_EQEPINDEX_GPIO 23               //!< GPIO pin for EQEP1_INDEX
#define myEQEP0_EQEPINDEX_PIN_CONFIG GPIO_23_EQEP1_INDEX //!< GPIO configuration for EQEP1_INDEX

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


#define myEPWM0_BASE EPWM1_BASE                 //!< ePWM module base address
//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

PosSpeed_Object posSpeed = {0};

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
// (Already defined above)

uint16_t interruptCount = 0;
uint32_t eqep_ex02_count =0;  // counter to check measurement gets saturated
uint32_t eqep_ex02_pass=0, eqep_ex02_fail =0; // Pass or fail indicator

uint16_t eqep_ex02_ans[sum];
uint16_t eqep_ex02_cnt[sum];



volatile uint32_t EQEP_OK = 0;
volatile uint32_t eqep_flag=0;
//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************

void eqep_ex02_myEQEP_init(void);
void eqep_ex02_initEPWM(void);
__INTERRUPT void EPWM1XINTISR(void);
void eqep_ex02_GPIO_Init(void);

//*****************************************************************************
//
// Main function
//
//*****************************************************************************

/**
  * \brief  Main program
  * \param  None
  * \retval None
  */
int main(void)
{
	alb32r003x_evb_init();

	posSpeed.mechScaler = MECH_SCALER;
	posSpeed.polePairs  = POLE_PAIRS;
	posSpeed.calAngle   = CAL_ANGLE;
	posSpeed.speedScaler= SPEED_SCALER;
	posSpeed.baseRPM    = BASE_RPM;

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
//    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    //
    // Disable pin locks and enable internal pullups.
    //
	eqep_ex02_GPIO_Init();




//    printf("eQEP test begin!\r\n");


    //
    // Board Initialization
    // Setup eQEP1, configuring the unit timer and quadrature capture units
    // Initialize GPIOs for use as EQEP1A, EQEP1B, and EQEP1I
    //
    eqep_ex02_myEQEP_init();
    //
    // Setup ePWM1 to generate a 5 kHz signal to be an input to the eQEP
    //
    eqep_ex02_initEPWM();



    Interrupt_register(EPWM1_IRQn, EPWM1XINTISR);
    Interrupt_setPriority(EPWM1_IRQn, 0, 0);
    Interrupt_enable(EPWM1_IRQn);
    ECLIC_EnableIRQ(EPWM1_IRQn);


	CPU_enableIrq();

	delay_ms(500);



    //
    // Loop indefinitely
    //

    while(1)
    {
        if(EQEP_OK == 1)
        {
        	uint32_t i=0;
        	for(i=0;i<sum;i++)
        	{
        		if(eqep_ex02_ans[i] == 1 && eqep_ex02_cnt[i] <= 4000)
        		{
        			eqep_flag++;
        		}
        	}

        	if (eqep_flag == sum)
        	{
        		printf("eqep_test ok!\r\n");
        	}
        	else
        	{
        		printf("eqep_test error!\r\n");
        	}
        	EQEP_OK = 2;
        }
    }

}

void eqep_ex02_GPIO_Init()
{
	//
	// EPWM1 -> myEPWM1 Pinmux
	//
	GPIO_setPinConfig(GPIO_0_EPWM1_A);    // Configure pin for ePWM1A output
	GPIO_setPinConfig(GPIO_1_EPWM1_B);    // Configure pin for ePWM1B output
	GPIO_setDirectionMode(30, GPIO_DIR_MODE_OUT);

	//eqep1A
	GPIO_setPinConfig(myEQEP0_EQEPA_PIN_CONFIG);
    //eqep1B
	GPIO_setPinConfig(myEQEP0_EQEPB_PIN_CONFIG);
	//eqep1I
	GPIO_setPinConfig(myEQEP0_EQEPINDEX_PIN_CONFIG);

	//eqep2A
	GPIO_setPinConfig(myEQEP1_EQEPA_PIN_CONFIG);
    //eqep2B
	GPIO_setPinConfig(myEQEP1_EQEPB_PIN_CONFIG);
	//eqep2I
	GPIO_setPinConfig(myEQEP1_EQEPINDEX_PIN_CONFIG);

}

void eqep_ex02_myEQEP_init()

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
	EQEP_setDecoderConfig(myEQEP_BASE, (EQEP_CONFIG_QUADRATURE | EQEP_CONFIG_1X_RESOLUTION | EQEP_CONFIG_NO_SWAP | EQEP_CONFIG_IGATE_DISABLE));
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
	//EQEP_enableUnitTimer(myEQEP_BASE,1200000U);
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
	//QCTME MAX TIME = 1 / SYSTICK * 128 * 65535 = 0.53333 * 65535 = 34.952ms
	//UPEVENT TIME = 1 / EPWM_FRE / 4 * 256 = 1 / 5000 / 4 * 256 = 12.8ms
	EQEP_setCaptureConfig(myEQEP_BASE,EQEP_CAPTURE_CLK_DIV_128,EQEP_UNIT_POS_EVNT_DIV_256);
	//
	// Enables the eQEP module edge-capture unit.
	//
	EQEP_enableCapture(myEQEP_BASE);
}

void eqep_ex02_initEPWM(void)
{
    //
    // Disable the ePWM time base clock before configuring the module
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Set phase shift to 0 and clear the time base counter
    //
    EPWM_setPhaseShift(myEPWM0_BASE, 0);
    EPWM_setTimeBaseCounter(myEPWM0_BASE, 0);

    //
    // Disable the shadow load; the load will be immediate instead
    //
    EPWM_disableCounterCompareShadowLoadMode(myEPWM0_BASE,
                                             EPWM_COUNTER_COMPARE_A);
    EPWM_disableCounterCompareShadowLoadMode(myEPWM0_BASE,
                                             EPWM_COUNTER_COMPARE_B);

    //
    // Set the compare A value to half the period value, compare B to 0
    //
    EPWM_setCounterCompareValue(myEPWM0_BASE, EPWM_COUNTER_COMPARE_A, PRD_VAL/2);
    EPWM_setCounterCompareValue(myEPWM0_BASE, EPWM_COUNTER_COMPARE_B, 0);

    //
    // Set action qualifier behavior on compare A events
    // - EPWM1A --> 1 when CTR = CMPA and increasing
    // - EPWM1A --> 0 when CTR = CMPA and decreasing
    //
    EPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

    //
    // Set action qualifier behavior on compare B events
    // - EPWM1B --> 1 when CTR = PRD and increasing
    // - EPWM1B --> 0 when CTR = 0 and decreasing
    //
    EPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    // Enable interrupt when the counter is equal to PRD
    //
    EPWM_setInterruptSource(myEPWM0_BASE, EPWM_INT_TBCTR_PERIOD);
    EPWM_enableInterrupt(myEPWM0_BASE);

    //
    // Interrupt on first event
    //
    EPWM_setInterruptEventCount(myEPWM0_BASE, 1);

    //
    // Set the time base clock prescaler to /1
    //
    EPWM_setClockPrescaler(myEPWM0_BASE, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_10);

    //
    // Set the period value; don't shadow the register
    //
    EPWM_setPeriodLoadMode(myEPWM0_BASE, EPWM_PERIOD_DIRECT_LOAD);
    EPWM_setTimeBasePeriod(myEPWM0_BASE, PRD_VAL);

    //
    // Put the time base counter into up-down count mode
    //
    EPWM_setTimeBaseCounterMode(myEPWM0_BASE, EPWM_COUNTER_MODE_UP_DOWN);

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);



}



//*****************************************************************************
//
// ePWM interrupt handler - processes eQEP position and speed data
//
//*****************************************************************************
__INTERRUPT void EPWM1XINTISR(void)
{
	uint16_t i;
    //
    // Position speed and measurement
    //
    eqep_ex02_PosSpeed_calculate(&posSpeed, &eqep_ex02_count,myEQEP_BASE);

    //
    // Comparing the eQEP measured frequency with the ePWM frequency
    // After count becomes 3 , eQEP measurement gets saturated and if
    // measure speed is 5 more or less than input speed then eqep_ex02_pass = 1
    //
    if ((eqep_ex02_count >= 2)&&(EQEP_OK == 0))
    {

		if (((posSpeed.speedRPMFR - 300) < 20) &&
			 ((posSpeed.speedRPMFR - 300) > -20))
		{
			eqep_ex02_pass = 1; eqep_ex02_fail = 0;
		}
		else
		{
			eqep_ex02_fail = 1; eqep_ex02_pass = 0;
		}
		eqep_ex02_ans[eqep_ex02_count-2] = eqep_ex02_pass;
		eqep_ex02_cnt[eqep_ex02_count-2] = EQEP_getPosition(myEQEP_BASE);

		if(eqep_ex02_count - 2 == sum -1 )
		{
			EQEP_OK = 1;
			Interrupt_disable(EPWM1_IRQn);
		}


   }
    //
    // Control loop for position control and speed control
    //
    interruptCount++;
    if(interruptCount % 1000 == 0 )
    {
        //
        // Pulse index signal (1 pulse/rev)
        //
        GPIO_writePin(30, 1);
        for(i = 0; i < 700; i++)
        {
            ;
        }
        GPIO_writePin(30, 0);

    }


    //
    // Clear interrupt flag and issue ACK
    //
    EPWM_clearEventTriggerInterruptFlag(myEPWM0_BASE);

}


#ifdef __cplusplus
}
#endif

