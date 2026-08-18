/**
 *************************************************************************************
 * @file xbat_ex08_pwmProtection.c
 * @brief This file contains the source file for example xbat_ex08_pwmProtection.
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

#define GPIO_TO_EPWM_NUM 33

EPWM_TypeDef EPWM;

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
int nowLine;

#if GPIO_TO_EPWM_NUM == 16

uint32_t TZInputPin = 16;
uint32_t TZFlipPin = 1;
uint32_t TZInputPinConfig = GPIO_16_GPIO16;
uint32_t TZFlipPinConfig = GPIO_1_GPIO1;
uint32_t TZInputPinNum = 16;
uint32_t TZXBAR = XBAR_INPUT1;

uint32_t TripSourcePara = EPWM_DC_TRIP_TRIPIN1;

#elif GPIO_TO_EPWM_NUM == 17

uint32_t TZInputPin = 17;
uint32_t TZFlipPin = 1;
uint32_t TZInputPinConfig = GPIO_17_GPIO17;
uint32_t TZFlipPinConfig = GPIO_1_GPIO1;
uint32_t TZInputPinNum = 17;
uint32_t TZXBAR = XBAR_INPUT2;

uint32_t TripSourcePara = EPWM_DC_TRIP_TRIPIN2;

#elif GPIO_TO_EPWM_NUM == 22

uint32_t TZInputPin = 22;
uint32_t TZFlipPin = 1;
uint32_t TZInputPinConfig = GPIO_22_GPIO22;
uint32_t TZFlipPinConfig = GPIO_1_GPIO1;
uint32_t TZInputPinNum = 22;
uint32_t TZXBAR = XBAR_INPUT3;

uint32_t TripSourcePara = EPWM_DC_TRIP_TRIPIN3;

#elif GPIO_TO_EPWM_NUM == 23

uint32_t TZInputPin = 23;
uint32_t TZFlipPin = 1;
uint32_t TZInputPinConfig = GPIO_23_GPIO23;
uint32_t TZFlipPinConfig = GPIO_1_GPIO1;
uint32_t TZInputPinNum = 23;
uint32_t TZXBAR = XBAR_INPUT4;
uint32_t TZEPWMXBAR = XBAR_TRIP4;

XBAR_EPWMMuxConfig EPWMXBAR_Source = XBAR_EPWM_MUX07_INPUTXBAR4;
uint32_t XBAR_MUX = XBAR_MUX07;

uint32_t TripSourcePara = EPWM_DC_TRIP_TRIPIN4;

#elif GPIO_TO_EPWM_NUM == 33

uint32_t TZInputPin = 33;
uint32_t TZFlipPin = 1;
uint32_t TZInputPinConfig = GPIO_33_GPIO33;
uint32_t TZFlipPinConfig = GPIO_1_GPIO1;
uint32_t TZInputPinNum = 33;
uint32_t TZXBAR = XBAR_INPUT5;
uint32_t TZEPWMXBAR = XBAR_TRIP5;

XBAR_EPWMMuxConfig EPWMXBAR_Source = XBAR_EPWM_MUX09_INPUTXBAR5;
uint32_t XBAR_MUX = XBAR_MUX09;

uint32_t TripSourcePara = EPWM_DC_TRIP_TRIPIN5;

#endif


//*****************************************************************************
//
// Defines
//
//*****************************************************************************

#define EPWM_TZ_FLAG_ALL (EPWM_TZ_FLAG_CBC|EPWM_TZ_FLAG_OST|EPWM_TZ_FLAG_DCAEVT1|EPWM_TZ_FLAG_DCAEVT2|EPWM_TZ_FLAG_DCBEVT1|EPWM_TZ_FLAG_DCBEVT2)

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void PinMux_init();
void GPIO_init();
void INPUTXBAR_init(void);
void EPWM_init(uint32_t epwm_base);
void SYNC_init(void);

static void Board_init(uint32_t epwm_base);


//*****************************************************************************
//
// main - Main function for XBAR input interrupt test
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();
    //
    // Initialize variables
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOB);

    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    Board_init(EPWM1_BASE);

    do
    {
        EPWM_clearTripZoneFlag(EPWM1_BASE, EPWM_TZ_FLAG_ALL);
    } while (EPWM_getTripZoneFlagStatus(EPWM1_BASE) != 0);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    GPIO_writePin(TZFlipPin,RESET);
    if ((EPWM_getTripZoneFlagStatus(EPWM1_BASE) & EPWM_TZ_FLAG_DCAEVT1)
            != EPWM_TZ_FLAG_DCAEVT1)
    {
        printf("INPUTXBAR TO EPWM Error!");
    }
    GPIO_writePin(TZFlipPin,SET);
    do
    {
        EPWM_clearTripZoneFlag(EPWM1_BASE, EPWM_TZ_FLAG_ALL);
    } while (EPWM_getTripZoneFlagStatus(EPWM1_BASE) != 0);

    printf("INPUTXBAR PWM Protection Done!");
}

void PinMux_init()
{
    GPIO_setPinConfig(TZInputPinConfig); //TZINPUT
    GPIO_setPinConfig(TZFlipPinConfig); //TZFLIP
}
void GPIO_init()
{
    GPIO_setDirectionMode(TZInputPin,GPIO_DIR_MODE_IN );
    GPIO_setDirectionMode(TZFlipPin,GPIO_DIR_MODE_OUT );
    GPIO_writePin(TZFlipPin,SET);
}

void INPUTXBAR_init(void)
{
    XBAR_setInputPin(INPUTXBAR_BASE, TZXBAR, TZInputPinNum);
}

void EPWMXBAR_init()
{

    XBAR_setEPWMMuxConfig(TZEPWMXBAR, EPWMXBAR_Source);
    XBAR_enableEPWMMux(TZEPWMXBAR, XBAR_MUX);
}

void EPWM_init(uint32_t epwm_base)
{
    EPWM_setClockPrescaler(epwm_base, EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_1);
    EPWM_setTimeBasePeriod(epwm_base, 1999);
    EPWM_setTimeBaseCounter(epwm_base, 0);
    EPWM_setTimeBaseCounterMode(epwm_base, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(epwm_base);
    EPWM_setPhaseShift(epwm_base, 0);
    EPWM_setCounterCompareValue(epwm_base, EPWM_COUNTER_COMPARE_A, 0);
    EPWM_setCounterCompareShadowLoadMode(epwm_base, EPWM_COUNTER_COMPARE_A,
            EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareValue(epwm_base, EPWM_COUNTER_COMPARE_B, 0);
    EPWM_setCounterCompareShadowLoadMode(epwm_base, EPWM_COUNTER_COMPARE_B,
            EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(epwm_base, EPWM_AQ_OUTPUT_B,
            EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(epwm_base,
            EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(epwm_base);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(epwm_base,
            EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(epwm_base);
    EPWM_selectDigitalCompareTripInput(epwm_base, TripSourcePara,
            EPWM_DC_TYPE_DCAH);
    EPWM_setTripZoneDigitalCompareEventCondition(epwm_base,
            EPWM_TZ_DC_OUTPUT_A1, EPWM_TZ_EVENT_DCXH_LOW);
}

void SYNC_init(void)
{
    SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
    //
    // For EPWM1, the sync input is: SYSCTL_SYNC_IN_SRC_EXTSYNCIN1
    //
    EPWM_setSyncInPulseSource(EPWM1_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM2_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM3_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM4_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM5_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM6_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM7_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);
    EPWM_setSyncInPulseSource(EPWM8_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);

    //
    // SOCA
    //
    SysCtl_enableExtADCSOCSource(0);
    //
    // SOCB
    //
    SysCtl_enableExtADCSOCSource(0);
}

void Board_init(uint32_t epwm_base)
{
    PinMux_init();
    GPIO_init();
    INPUTXBAR_init();
    EPWMXBAR_init();
    EPWM_init(epwm_base);
    SYNC_init();
}
