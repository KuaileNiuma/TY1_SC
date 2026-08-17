/** 
  *************************************************************************************
  * @file type4_pwm_protection_source.c 
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

#include "type4_pwm_protection_source.h"

void initEPWM_aux_trip(uint32_t aux_pwm_base,
                       EPWM_DigitalCompareTripInput system_trip_source,
                       uint16_t trip_delay)
{

    EPWM_setTimeBasePeriod(aux_pwm_base, 2500);
    EPWM_setTimeBaseCounter(aux_pwm_base,0);
    EPWM_setPhaseShift(aux_pwm_base,0);
    EPWM_disablePhaseShiftLoad(aux_pwm_base);
    EPWM_setTimeBaseCounterMode(aux_pwm_base,EPWM_COUNTER_MODE_UP_DOWN);
    EPWM_setClockPrescaler(aux_pwm_base, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    // S1 = 1
    EPWM_setDeadBandDelayMode(aux_pwm_base,EPWM_DB_RED, true);
    // S2 = 0
    EPWM_setDeadBandDelayPolarity(aux_pwm_base, EPWM_DB_RED,
                                  EPWM_DB_POLARITY_ACTIVE_HIGH);

    // S4 = 0
    EPWM_setRisingEdgeDeadBandDelayInput(aux_pwm_base, EPWM_DB_INPUT_EPWMA);
    EPWM_setRisingEdgeDelayCount(aux_pwm_base, trip_delay);

    //
    // DCBH = TRIPIN4 = INPUT X-BAR 1 = EPWM8A in this example
    //
    EPWM_selectDigitalCompareTripInput(aux_pwm_base, system_trip_source,
                                       EPWM_DC_TYPE_DCBH);
    //
    //Trigger DCBEVT1 when system_trip_source signal goes low(fault occurs)
    //Trigger DCBEVT2 when system_trip_source signal goes high(recover from fault)
    //
    EPWM_setTripZoneDigitalCompareEventCondition(aux_pwm_base,
                                                 EPWM_TZ_DC_OUTPUT_B1,
                                                 EPWM_TZ_EVENT_DCXH_LOW);
    EPWM_setTripZoneDigitalCompareEventCondition(aux_pwm_base,
                                                 EPWM_TZ_DC_OUTPUT_B2,
                                                 EPWM_TZ_EVENT_DCXH_HIGH);
    //
    // DCBEVT1/2 event as AQ T1/2
    //
    // T1 = DCBEVT1
    EPWM_setActionQualifierT1TriggerSource(aux_pwm_base,
                                           EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_1);
    // T2 = DCBEVT2
    EPWM_setActionQualifierT2TriggerSource(aux_pwm_base,
                                           EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_2);

    //
    // EPWMA Trip on AQ T1/T2
    //
    EPWM_setActionQualifierAction(aux_pwm_base,
                                  EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);
    EPWM_setActionQualifierAction(aux_pwm_base,
                                  EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_T1_COUNT_DOWN);
    EPWM_setActionQualifierAction(aux_pwm_base,
                                  EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_T2_COUNT_UP);
    EPWM_setActionQualifierAction(aux_pwm_base,
                                  EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_T2_COUNT_DOWN);

    EPWM_setTripZoneAction(aux_pwm_base ,EPWM_TZ_ACTION_EVENT_DCAEVT1,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(aux_pwm_base, EPWM_TZ_ACTION_EVENT_DCAEVT2,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(aux_pwm_base, EPWM_TZ_ACTION_EVENT_DCBEVT1,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(aux_pwm_base, EPWM_TZ_ACTION_EVENT_DCBEVT2,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(aux_pwm_base, EPWM_TZ_ACTION_EVENT_TZA,
                           EPWM_TZ_ACTION_DISABLE);
    EPWM_setTripZoneAction(aux_pwm_base, EPWM_TZ_ACTION_EVENT_TZB,
                           EPWM_TZ_ACTION_DISABLE);
}

//! \brief   Configures the delay trip action for inner switches(PWMxB).
//! \param base1   PWM base register for inner switches
//! \param aux_trip_source  Trip input for the auxiliary PWM output
//!
void configEPWMDelayTrip(uint32_t base1,
                            EPWM_DigitalCompareTripInput aux_trip_source)
{
    //
    // Set force high actions for PWMxB during initialization
    //
    // Action When One-Time Software Force B is Invoked
    EPWM_setActionQualifierSWAction(base1, EPWM_AQ_OUTPUT_B,
                                    EPWM_AQ_OUTPUT_HIGH);
    // Initiates a single software forced event
    //
    EPWM_forceActionQualifierSWAction(base1,EPWM_AQ_OUTPUT_B);

    //
    // Configure EPWM DCBEVT1/2 as T1/2
    // DCBEVT1/2 generation based on aux PWM ouput set high and clear low
    //

    // DCBL = TRIPIN7 = INPUT X-BAR 3 = EPWM7A in this example
    EPWM_selectDigitalCompareTripInput(base1, aux_trip_source,
                                       EPWM_DC_TYPE_DCBL);

    //
    // DCBL = High, Trigger DCBEVT1 when auxiliary PWM goes high
    //
    EPWM_setTripZoneDigitalCompareEventCondition(base1, EPWM_TZ_DC_OUTPUT_B1,
                                                 EPWM_TZ_EVENT_DCXL_HIGH);

    //
    // DCBL = low, Trigger DCBEVT2 when auxiliary PWM goes low
    //
    EPWM_setTripZoneDigitalCompareEventCondition(base1, EPWM_TZ_DC_OUTPUT_B2,
                                                 EPWM_TZ_EVENT_DCXL_LOW);

    //
    // DCBEVT1/2 event as AQ T1/2
    // T1 = DCBEVT1
    // T2 = DCBEVT2
    //
    EPWM_setActionQualifierT1TriggerSource(base1,
                                           EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_1);
    EPWM_setActionQualifierT2TriggerSource(base1,
                                           EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_2);

    //
    // set T1/T2 action setting for EPWMxB
    //
    EPWM_setActionQualifierAction(base1, EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);
    EPWM_setActionQualifierAction(base1, EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_T1_COUNT_DOWN);
    EPWM_setActionQualifierAction(base1, EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_T2_COUNT_UP);
    EPWM_setActionQualifierAction(base1,EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_T2_COUNT_DOWN);
}




