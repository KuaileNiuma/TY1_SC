/** 
  *************************************************************************************
  * @file level_main.c 
  * @author Albatross 
  * @brief This file contains the source file. 
  * @version 1.0.0 
  * @date 2025-07-30 
  *************************************************************************************
  * @copyright Copyright (c) 2025 Albatross  Semiconductor( Hangzhou ) Co ., Ltd . 
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

//
// Included Files
//

#include "level_main.h"

// EPWM duty cycle for the 4 switches
//
volatile uint16_t Test_Cmpa = 1250; // (PERIOD_TICKS/2)

// Note: change simulate_EPWM_Cmpa value to simulate different length of the
// trip signal. 2500 refers to normally high for the trip signal, reduce this
// value to generate the system trip signal.
volatile uint16_t simulate_EPWM_Cmpa = 2200;
//
// Globals
// positive_cycle change to 0 to simulate negative cycle operation
// positive_cycle change to 1 to simulate positive cycle operation
volatile int16_t  positive_cycle = 1;

uint16_t negative_flag = 1;
uint16_t positive_flag = 1;

// keep the simulated PWM period same as the main PWM
#define simulate_EPWM_TBPRD  PERIOD_TICKS
#define EPWM1 ((EPWM_TypeDef*) EPWM1_BASE);
//
// Function Prototypes
//
void init_simluate_trip_EPWM(uint32_t base);
__INTERRUPT void ISR1(void);

//
// Note that the watchdog is disabled in codestartbranch.asm
// for this project. This is to prevent it from expiring while
// c_init routine initializes the global variables before
// reaching the main()                                2500);

//
void epwm_main(void)
{

	EPWM1;
    //
    // This routine sets up the basic device configuration such as
    // initializing PLL, copying code from FLASH to RAM
    //
    InitEPwmGpio();

    //
    // Assign the interrupt service routines to ePWM interrupts
    //
    ECLIC_Register_IRQ(EPWM1_IRQn,ECLIC_VECTOR_INTERRUPT,ECLIC_POSTIVE_EDGE_TRIGGER,0,0,ISR1);
    CPU_enableIrq();

    //
    // Disable sync(Freeze clock to PWM as well)
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_HRPWM);
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    InitINPUTXBAR();
    InitEPWMXBAR();
    setupEPWM(S1_S3_PWM_BASE);
    setupEPWM(S2_S4_PWM_BASE);
    configEPWM_CBC(S1_S3_PWM_BASE,S2_S4_PWM_BASE);

    //
    // EPWM X-BAR TRIP 4 source from INPUT X-BAR 1 = GPIO14 = EPWM8A
    //
    initEPWM_aux_trip(AUX_PWM_BASE, DC_TRIP_system, DELAY_2us);

    //
    // EPWM X-BAR TRIP 7 source from INPUT X-BAR 3 = GPIO12 = EPWM7A
    //
    configEPWMDelayTrip(S1_S3_PWM_BASE, DC_TRIP_auxiliary);
    configEPWMDelayTrip(S2_S4_PWM_BASE, DC_TRIP_auxiliary);

    //The system trip signal is simulated and generated with EPWM8A
    init_simluate_trip_EPWM(simulate_trip_PWM_BASE);

    EPWM_setInterruptSource(S1_S3_PWM_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(S1_S3_PWM_BASE);
    EPWM_setInterruptEventCount(S1_S3_PWM_BASE, 1U);

    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    for(;;);

}

//
// ISR1
// Example to swap EPWM settings during the zero cross point between positive
// and negative cycle
__INTERRUPT void ISR1(void)
{

    if(positive_cycle)
    {
        EPWM_setCounterCompareValue(S1_S3_PWM_BASE, EPWM_COUNTER_COMPARE_A,
                                    Test_Cmpa);
        if(negative_flag)
        {
            EPWM_setCounterCompareValue(S2_S4_PWM_BASE, EPWM_COUNTER_COMPARE_A,
                                        PERIOD_TICKS);
            EPWM_setDeadBandDelayMode(S1_S3_PWM_BASE, EPWM_DB_FED, true);
            EPWM_setDeadBandDelayMode(S2_S4_PWM_BASE, EPWM_DB_FED, false);

            EPWM_setTripZoneAction(S1_S3_PWM_BASE, EPWM_TZ_ACTION_EVENT_TZB,
                                 EPWM_TZ_ACTION_LOW);
            EPWM_setTripZoneAction(S2_S4_PWM_BASE, EPWM_TZ_ACTION_EVENT_TZB,
                                 EPWM_TZ_ACTION_DISABLE);

            negative_flag=0;
            positive_flag=1;
        }
    }

    else
    {
        EPWM_setCounterCompareValue(S2_S4_PWM_BASE, EPWM_COUNTER_COMPARE_A,
                                    Test_Cmpa);
        if(positive_flag)
        {
            EPWM_setCounterCompareValue(S1_S3_PWM_BASE, EPWM_COUNTER_COMPARE_A,
                                        PERIOD_TICKS);
            EPWM_setDeadBandDelayMode(S1_S3_PWM_BASE, EPWM_DB_FED, false);
            EPWM_setDeadBandDelayMode(S2_S4_PWM_BASE, EPWM_DB_FED, true);

            EPWM_setTripZoneAction(S1_S3_PWM_BASE, EPWM_TZ_ACTION_EVENT_TZB,
                                   EPWM_TZ_ACTION_DISABLE );
            EPWM_setTripZoneAction(S2_S4_PWM_BASE, EPWM_TZ_ACTION_EVENT_TZB,
                                   EPWM_TZ_ACTION_LOW);

            positive_flag =0;
            negative_flag = 1;
        }
    }

    EPWM_setCounterCompareValue(simulate_trip_PWM_BASE, EPWM_COUNTER_COMPARE_A,
    		simulate_EPWM_Cmpa);

    //
    // Clear INT flag for this timer
    //
    EPWM_clearEventTriggerInterruptFlag(S1_S3_PWM_BASE);

    //
    // Acknowledge interrupt group
    //
}

// In order to validate the scheme, the system trip signal is simulated and
// generated with an EPWM output, which serves as the trip signal with actively
// low. It can be replaced by any other PWMs or external signals.
// EPWM8A is used in this example
void init_simluate_trip_EPWM(uint32_t base)
{
    EPWM_setTimeBasePeriod(base, simulate_EPWM_TBPRD);
    EPWM_setTimeBaseCounter(base, 0);
    EPWM_setPhaseShift(base, 0);
    EPWM_disablePhaseShiftLoad(base);
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP_DOWN);
    EPWM_setClockPrescaler(base, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    EPWM_disableCounterCompareShadowLoadMode(base,
                                             EPWM_COUNTER_COMPARE_A);
    EPWM_disableCounterCompareShadowLoadMode(base,
                                             EPWM_COUNTER_COMPARE_B);

    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_A,
                                simulate_EPWM_Cmpa);

    //
    // Set actions
    //
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);


}

//
// InitEPwmGpio -
//
void InitEPwmGpio(void)
{

	GPIO_setPinConfig(S1_PWM_GPIO_PIN_CONFIG);
    GPIO_setPinConfig(S3_PWM_GPIO_PIN_CONFIG);
    GPIO_setDirectionMode(S1_PWM_GPIO,GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(S3_PWM_GPIO,GPIO_DIR_MODE_OUT);

    GPIO_setPinConfig(S4_PWM_GPIO_PIN_CONFIG);
    GPIO_setPinConfig(S2_PWM_GPIO_PIN_CONFIG);
    GPIO_setDirectionMode(S4_PWM_GPIO,GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(S2_PWM_GPIO,GPIO_DIR_MODE_OUT);

    GPIO_setPinConfig(AUX_PWM_GPIO_PIN_CONFIG);
    GPIO_setPinConfig(AUX_PWM_GPIO_INPUT_CONFIG);
    GPIO_setDirectionMode(AUX_PWM_GPIO,GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(AUX_PWM_INPUT_GPIO,GPIO_DIR_MODE_IN);

    GPIO_setPinConfig(simulate_PWM_GPIO_PIN_CONFIG);
    GPIO_setPinConfig(simulate_PWM_GPIO_INPUT_CONFIG);
    GPIO_setDirectionMode(simulate_PWM_GPIO,GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(simulate_PWM_INPUT_GPIO,GPIO_DIR_MODE_IN);

}
// InitINPUTXBAR -
//static inline
void InitINPUTXBAR(void)
{
    // INPUT X-BAR 1->GPIO14->EPWM8A
    XBAR_setInputPin(INPUTXBAR_BASE,XBAR_INPUT_system, simulate_PWM_INPUT_GPIO);
    // INPUT X-BAR 3->GPIO12->EPWM7A
    XBAR_setInputPin(INPUTXBAR_BASE,XBAR_INPUT_auxiliary, AUX_PWM_INPUT_GPIO);
}
//
// InitEPWMXBAR
// Select the trip input sources for the the system trip event and auxiliary
// trip event through ePWM X-BAR.
void InitEPWMXBAR(void)
{
    //
    // Configure INPUT X-BAR 1 and 3 as the source for EPWM X-BAR TRIP 4 and TRIP 7
    //
    XBAR_setEPWMMuxConfig(XBAR_TRIP_system, XBAR_EPWM_MUX01_INPUTXBAR1);
    XBAR_enableEPWMMux(XBAR_TRIP_system, XBAR_MUX01);

    XBAR_setEPWMMuxConfig(XBAR_TRIP_auxiliary, XBAR_EPWM_MUX05_INPUTXBAR3);
    XBAR_enableEPWMMux(XBAR_TRIP_auxiliary, XBAR_MUX05);
}

//
// setupEPWM -
//
void setupEPWM(uint32_t base)
{
    //
    // Set-up TBCLK
    //
    EPWM_setTimeBasePeriod(base, PERIOD_TICKS);
    EPWM_setPhaseShift(base, 0U);
    EPWM_setTimeBaseCounter(base, 0U);
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP_DOWN);
    EPWM_disablePhaseShiftLoad(base);
    EPWM_setClockPrescaler(base, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setDeadBandControlShadowLoadMode(base, EPWM_DB_LOAD_ON_CNTR_ZERO);

    //
    // Use EPWMA as the input for both RED and FED
    //
    EPWM_setRisingEdgeDeadBandDelayInput(base, EPWM_DB_INPUT_EPWMA);
    EPWM_setFallingEdgeDeadBandDelayInput(base, EPWM_DB_INPUT_EPWMA);

    //
    // Set the RED and FED values, 500ns in this example
    //
    EPWM_setFallingEdgeDelayCount(base, Falling_edge_delay);
    EPWM_setRisingEdgeDelayCount(base, Rising_edge_delay);

    //
    // Invert only the Falling Edge delayed output (AHC)
    //
    EPWM_setDeadBandDelayPolarity(base, EPWM_DB_RED,
                                  EPWM_DB_POLARITY_ACTIVE_HIGH);
    EPWM_setDeadBandDelayPolarity(base, EPWM_DB_FED,
                                  EPWM_DB_POLARITY_ACTIVE_LOW);
    //TEST_MAIN_H
    //  Use the delayed signals instead of the original signals
    //
    EPWM_setDeadBandDelayMode(base, EPWM_DB_RED, true);

    //
    // DO NOT Switch Output A with Output B
    //
    EPWM_setDeadBandOutputSwapMode(base, EPWM_DB_OUTPUT_A, false);
    EPWM_setDeadBandOutputSwapMode(base, EPWM_DB_OUTPUT_B, false);

    // Set actions for PWM1A

    // Clear PWM1A on ZRO
    //
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //
    // Set PWM1A on CMPA Up
    //
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //
    // Set PWM1A on Period
    //
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);

    //
    // Clear PWM1A on CMPA Down
    //
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

    EPWM_setTripZoneAction(base, EPWM_TZ_ACTION_EVENT_DCAEVT1,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(base, EPWM_TZ_ACTION_EVENT_DCAEVT2,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(base, EPWM_TZ_ACTION_EVENT_DCBEVT1,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(base, EPWM_TZ_ACTION_EVENT_DCBEVT2,
                           EPWM_TZ_ACTION_DISABLE);

}


//
// configEPWM_CBC -
// Enable force low action with CBC for EPWM1A and EPWM2A during initialization
void configEPWM_CBC(uint32_t base1, uint32_t base2)
{
    //EPWM1 CBC

    //
    // DCAH = TRIPIN4 = INPUT X-BAR 1 = EPWM8A
    //
    EPWM_selectDigitalCompareTripInput(base1, DC_TRIP_system,
                                       EPWM_DC_TYPE_DCAH);

    //
    // DCAH = Low and DCAL = Don't care,Trigger DCAEVT2 when EPWM8A goes low
    //
    EPWM_setTripZoneDigitalCompareEventCondition(base1, EPWM_TZ_DC_OUTPUT_A2,
                                                 EPWM_TZ_EVENT_DCXH_LOW);

    EPWM_setTripZoneAction(base1, EPWM_TZ_ACTION_EVENT_TZA,
                           EPWM_TZ_ACTION_LOW);
    EPWM_setTripZoneAction(base1, EPWM_TZ_ACTION_EVENT_TZB,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_enableTripZoneSignals(base1, EPWM_TZ_SIGNAL_DCAEVT2);

    //EPWM2 CBC

    //
    // DCAH = TRIPIN4 = INPUT X-BAR 1 = EPWM8A in this example
    //
    EPWM_selectDigitalCompareTripInput(base2, DC_TRIP_system,
                                       EPWM_DC_TYPE_DCAH);

    //
    // DCAH = Low and DCAL = Don't care,Trigger DCAEVT2 when EPWM8A goes low
    //
    EPWM_setTripZoneDigitalCompareEventCondition(base2, EPWM_TZ_DC_OUTPUT_A2,
                                                 EPWM_TZ_EVENT_DCXH_LOW);

    EPWM_setTripZoneAction(base2, EPWM_TZ_ACTION_EVENT_TZA,
                           EPWM_TZ_ACTION_LOW);
    EPWM_setTripZoneAction(base2, EPWM_TZ_ACTION_EVENT_TZB,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_enableTripZoneSignals(base2,EPWM_TZ_SIGNAL_DCAEVT2);

    //
    // Clear any spurious trip
    //
    EPWM_clearTripZoneFlag(base1,(EPWM_TZ_FLAG_CBC|EPWM_TZ_FLAG_DCAEVT2));
    EPWM_clearTripZoneFlag(base2,(EPWM_TZ_FLAG_CBC|EPWM_TZ_FLAG_DCAEVT2));
}

//
// End of File
//
