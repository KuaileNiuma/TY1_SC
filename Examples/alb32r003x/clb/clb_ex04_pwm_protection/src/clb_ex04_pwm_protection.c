/**
 *************************************************************************************
 * @file clb_ex04_pwm_protection.c
 * @brief This file contains the source file for example clb_ex04_pwm_protection.
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
#include "clb.h"
#include "alb32r003x_evb.h"

#include "clb_ex04_board.h"
#include "clb_ex04_config.h"

#define EPWM1_TIMER_TBPRD   2000U
#define EPWM1_CMPA           933U
#define EPWM1_CMPB           933U

#define EPWM2_TIMER_TBPRD   2000U
#define EPWM2_CMPA           933U
#define EPWM2_CMPB           933U

#define EPWM3_TIMER_TBPRD   2000U
#define EPWM3_CMPA           933U
#define EPWM3_CMPB           933U

#define EPWM4_TIMER_TBPRD   2000U
#define EPWM4_CMPA           933U
#define EPWM4_CMPB           933U


void initEPWM1(void);
void initEPWM2(void);
void initEPWM3(void);
void initEPWM4(void);
__INTERRUPT void epwm1ISR(void);

uint32_t mode = 0;


void main(void)
{

	alb32r003x_evb_init();

	CPU_enableIrq();

    Interrupt_register(EPWM1_IRQn, &epwm1ISR);
    //
    // Set interrupt priority and enable interrupt
    //
    Interrupt_setPriority(EPWM1_IRQn, 0, 0);

    Interrupt_enable(EPWM1_IRQn);

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB2);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB3);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB4);

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM4);

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);

    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    Board_init();
    initTILE1(myTILE1_BASE);
    initTILE2(myTILE2_BASE);
    initTILE3(myTILE3_BASE);
    initTILE4(myTILE4_BASE);

    initEPWM1();
    initEPWM2();
    initEPWM3();
    initEPWM4();

    // start PWMs
    EPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_setTimeBaseCounterMode(myEPWM2_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_setTimeBaseCounterMode(myEPWM3_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_setTimeBaseCounterMode(myEPWM4_BASE, EPWM_COUNTER_MODE_UP);

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);


    while(1)
    {
        asm(" NOP");
    }
}


void initEPWM1()
{
    EPWM_setTimeBasePeriod(myEPWM1_BASE, EPWM1_TIMER_TBPRD);
    EPWM_setPhaseShift(myEPWM1_BASE, 0U);
    EPWM_setTimeBaseCounter(myEPWM1_BASE, 0U);

    EPWM_enableSyncOutPulseSource(myEPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);

    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM1_CMPA);
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM1_CMPB);

    EPWM_disablePhaseShiftLoad(myEPWM1_BASE);
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    EPWM_setInterruptSource(myEPWM1_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(myEPWM1_BASE);
    EPWM_setInterruptEventCount(myEPWM1_BASE, 3U);
}


void initEPWM2()
{
    EPWM_setTimeBasePeriod(myEPWM2_BASE, EPWM2_TIMER_TBPRD);
    EPWM_setTimeBaseCounter(myEPWM2_BASE, 0U);

    EPWM_enablePhaseShiftLoad(myEPWM2_BASE);
    EPWM_setPhaseShift(myEPWM2_BASE, 0U);

    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM2_CMPA);
    EPWM_setCounterCompareValue(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM2_CMPB);

    EPWM_setClockPrescaler(myEPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(myEPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
}


void initEPWM3()
{
    EPWM_setTimeBasePeriod(myEPWM3_BASE, EPWM3_TIMER_TBPRD);
    EPWM_setTimeBaseCounter(myEPWM3_BASE, 0U);

    EPWM_enablePhaseShiftLoad(myEPWM3_BASE);
    EPWM_setPhaseShift(myEPWM3_BASE, 0U);

    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM3_CMPA);
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM3_CMPB);

    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
}


void initEPWM4()
{
    EPWM_setTimeBasePeriod(myEPWM4_BASE, EPWM4_TIMER_TBPRD);;
    EPWM_setTimeBaseCounter(myEPWM4_BASE, 0U);

    EPWM_enablePhaseShiftLoad(myEPWM4_BASE);
    EPWM_setPhaseShift(myEPWM4_BASE, 0U);

    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM4_CMPA);
    EPWM_setCounterCompareValue(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM4_CMPB);

    EPWM_setClockPrescaler(myEPWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(myEPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(myEPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
}


__INTERRUPT void epwm1ISR(void)
{
    EPWM_clearEventTriggerInterruptFlag(myEPWM1_BASE);

    if (mode == 0)
    {
        CLB_setOutputMask(myTILE1_BASE, 0x5, false);
        CLB_setOutputMask(myTILE2_BASE, 0x5, false);
        CLB_setOutputMask(myTILE3_BASE, 0x5, false);
        CLB_setOutputMask(myTILE4_BASE, 0x5, false);
    }
    else
    {
        CLB_setOutputMask(myTILE1_BASE, 0x5, true);
        CLB_setOutputMask(myTILE2_BASE, 0x5, true);
        CLB_setOutputMask(myTILE3_BASE, 0x5, true);
        CLB_setOutputMask(myTILE4_BASE, 0x5, true);
    }
    asm(" NOP");
}

/* end of file */
