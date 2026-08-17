/**
 *************************************************************************************
 * @file xbat_ex02_ecapIN.c
 * @brief This file contains the source file for example xbat_ex02_ecapIN.
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
#include <stdlib.h>

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

uint32_t timeStamp1;


//*****************************************************************************
//
// Defines
//
//*****************************************************************************

#define PASS 1
#define FAIL 0

#define EXPECT_VAL 1000
#define ErrorRange 30

#define GPIO_34  34

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************

void ECAP_initIO(void);
int  ECAP_CaptureEventPolarity_poll(void);
void ECAP_init(uint32_t ecapBase);
void ECAP_getTestTimeStamp(uint32_t ecapBase);
int  ECAP_checkTestTimeStamp(uint32_t ecapBase);
int  ECAP_CaptureEventPolarity_poll(void);

//*****************************************************************************
//
// main - Main function for XBAR input interrupt test
//
//*****************************************************************************
void main(void)
{
    int ret;                    //!< Test result

    alb32r003x_evb_init();
    //
    // Initialize variables
    //

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP1);

    ECAP_reArm(ECAP1_BASE);

    ECAP_enableLoadCounter(ECAP1_BASE);
    ECAP_startCounter(ECAP1_BASE);
    ECAP_loadCounter(ECAP1_BASE);
    ECAP_stopCounter(ECAP1_BASE);

    ECAP_initIO();

    ret = ECAP_CaptureEventPolarity_poll();

    if (ret == FAIL)
    {
        printf("INPUTXBAR TO ECAP FAIL!");
    }

    printf("INPUTXBAR TO ECAP PASS!");
}

void ECAP_initIO(void)
{
    //Set INPUTXBAR1 to ECAP_Input
    ECAP_selectECAPInput(ECAP1_BASE,ECAP_INPUT_INPUTXBAR6);
    //Set GPIO1 to INPUTXBAR1
    XBAR_setInputPin(INPUTXBAR_BASE,XBAR_INPUT6, GPIO_34);

    //Set GPIO0 to output
    GPIO_setDirectionMode(0,GPIO_DIR_MODE_OUT );
    //GPIO output signal to Capture,defualt reset
    GPIO_writePin(0,RESET);
}

void ECAP_init(uint32_t ecapBase)
{
    ECAP_disableInterrupt(ecapBase,
        (ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
        ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
        ECAP_ISR_SOURCE_COUNTER_PERIOD   |
        ECAP_ISR_SOURCE_COUNTER_COMPARE));
    ECAP_clearInterrupt(ecapBase,
        (ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
        ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
        ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
        ECAP_ISR_SOURCE_COUNTER_PERIOD   |
        ECAP_ISR_SOURCE_COUNTER_COMPARE));

    //Turn to CAPTURE Mode
    ECAP_enableCaptureMode(ecapBase);

    //Enable event load to CAPx
    ECAP_enableTimeStampCapture(ecapBase);

    //Set CTRRST(relative mode)
    ECAP_enableCounterResetOnEvent(ecapBase,ECAP_EVENT_1);
    //Set Event Polarity
    ECAP_setEventPolarity(ecapBase,ECAP_EVENT_1,ECAP_EVNT_RISING_EDGE);

    //Set to one Capture Mode and stop until Event4
    ECAP_setCaptureMode(ecapBase,ECAP_CONTINUOUS_CAPTURE_MODE,ECAP_EVENT_1);

    //Set value of loading TSCTR(SYNC)
    ECAP_setPhaseShiftCount(ecapBase,0);

    ECAP_enableLoadCounter(ecapBase);
    ECAP_resetCounters(ecapBase);
    ECAP_disableLoadCounter(ecapBase);

    ECAP_reArm(ecapBase);
}

void ECAP_getTestTimeStamp(uint32_t ecapBase)
{
    uint32_t indexB;

    //Set defualt low
    GPIO_writePin(0,RESET);

    ECAP_startCounter(ecapBase);

    for(indexB = 0;indexB < 16;indexB++)
    {
        delay_us(500);
        GPIO_writePin(0,SET);
        delay_us(500);
        GPIO_writePin(0,RESET);
    }

    ECAP_stopCounter(ecapBase);
    ECAP_disableTimeStampCapture(ecapBase);

    timeStamp1 = ECAP_getEventTimeStamp(ecapBase,ECAP_EVENT_1);
}

int ECAP_checkTestTimeStamp(uint32_t ecapBase)
{
	uint32_t ret;
	uint32_t Sysclk;
    uint32_t CapVal;

    ret = PASS;

    Sysclk = SystemClock_Get();

    CapVal = timeStamp1 / (Sysclk / 1000000);

    if(abs(CapVal-EXPECT_VAL) > ErrorRange)
    	ret = FAIL;

    return ret;
}

int ECAP_CaptureEventPolarity_poll(void)
{
    uint32_t indexA;
    uint32_t ret;

    ret = FAIL;
    timeStamp1 = 0;

    ECAP_init(ECAP1_BASE);

    //start Capture
    ECAP_getTestTimeStamp(ECAP1_BASE);

    ret = ECAP_checkTestTimeStamp(ECAP1_BASE);

    return ret;
}


