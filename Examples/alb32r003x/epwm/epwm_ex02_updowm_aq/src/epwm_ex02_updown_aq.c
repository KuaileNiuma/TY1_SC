/**
 *************************************************************************************
 * @file epwm_ex02_updown_aq.c
 * @brief This file contains the source file for example epwm_ex02_updown_aq.
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
#include "epwm_ex02_board.h"
#include "alb32r003x_evb.h"



//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
//
// Macros
//
#define EPWM1_TIMER_TBPRD  2000U  //!< ePWM1 Timer period
#define EPWM1_MAX_CMPA     1950U  //!< ePWM1 Maximum CMPA value
#define EPWM1_MIN_CMPA       50U  //!< ePWM1 Minimum CMPA value
#define EPWM1_MAX_CMPB     1950U  //!< ePWM1 Maximum CMPB value
#define EPWM1_MIN_CMPB       50U  //!< ePWM1 Minimum CMPB value

#define EPWM2_TIMER_TBPRD  2000U  //!< ePWM2 Timer period
#define EPWM2_MAX_CMPA     1950U  //!< ePWM2 Maximum CMPA value
#define EPWM2_MIN_CMPA       50U  //!< ePWM2 Minimum CMPA value
#define EPWM2_MAX_CMPB     1950U  //!< ePWM2 Maximum CMPB value
#define EPWM2_MIN_CMPB       50U  //!< ePWM2 Minimum CMPB value

#define EPWM3_TIMER_TBPRD  2000U  //!< ePWM3 Timer period
#define EPWM3_MAX_CMPA      950U  //!< ePWM3 Maximum CMPA value
#define EPWM3_MIN_CMPA       50U  //!< ePWM3 Minimum CMPA value
#define EPWM3_MAX_CMPB     1950U  //!< ePWM3 Maximum CMPB value
#define EPWM3_MIN_CMPB     1050U  //!< ePWM3 Minimum CMPB value

#define EPWM_CMP_UP           1U  //!< Compare value increasing
#define EPWM_CMP_DOWN         0U  //!< Compare value decreasing

//
// Globals
//
typedef struct
{
    uint32_t epwmModule;         //!< ePWM module base address
    uint16_t epwmCompADirection; //!< CMPA direction (UP/DOWN)
    uint16_t epwmCompBDirection; //!< CMPB direction (UP/DOWN)
    uint16_t epwmTimerIntCount;  //!< Timer interrupt count
    uint16_t epwmMaxCompA;       //!< Maximum CMPA value
    uint16_t epwmMinCompA;       //!< Minimum CMPA value
    uint16_t epwmMaxCompB;       //!< Maximum CMPB value
    uint16_t epwmMinCompB;       //!< Minimum CMPB value

}epwmInformation;

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

//
// Globals to hold the ePWM information used in this example
//
epwmInformation epwm1Info;  //!< ePWM1 information structure
epwmInformation epwm2Info;  //!< ePWM2 information structure
epwmInformation epwm3Info;  //!< ePWM3 information structure

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void initEPWM1(void);                      //!< Initialize ePWM1
void initEPWM2(void);                      //!< Initialize ePWM2
void initEPWM3(void);                      //!< Initialize ePWM3
__INTERRUPT void epwm1ISR(void);           //!< ePWM1 ISR handler
__INTERRUPT void epwm2ISR(void);           //!< ePWM2 ISR handler
__INTERRUPT void epwm3ISR(void);           //!< ePWM3 ISR handler
void updateCompare(epwmInformation *epwmInfo);  //!< Update compare values




//*****************************************************************************
//
// Main
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();
	//
    // Assign the interrupt service routines to ePWM interrupts
    //
    Interrupt_register(EPWM1_IRQn, epwm1ISR);
    Interrupt_setPriority(EPWM1_IRQn, 0, 0);
    Interrupt_enable(EPWM1_IRQn);
    ECLIC_EnableIRQ(EPWM1_IRQn);

    Interrupt_register(EPWM2_IRQn, epwm2ISR);
    Interrupt_setPriority(EPWM2_IRQn, 0, 0);
    Interrupt_enable(EPWM2_IRQn);
    ECLIC_EnableIRQ(EPWM2_IRQn);

    Interrupt_register(EPWM3_IRQn, epwm3ISR);
    Interrupt_setPriority(EPWM3_IRQn, 0, 0);
    Interrupt_enable(EPWM3_IRQn);
    ECLIC_EnableIRQ(EPWM3_IRQn);


    //
    // Disable sync(Freeze clock to PWM as well)
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Configure GPIO0/1 , GPIO2/3 and GPIO4/5 as ePWM1A/1B, ePWM2A/2B and
    // ePWM3A/3B pins respectively
    // Configure EPWM Modules
    //
    Board_init();

    initEPWM1();
    initEPWM2();
    initEPWM3();

    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Enable ePWM interrupts
    //
    ECLIC_EnableIRQ(EPWM1_IRQn);
    ECLIC_EnableIRQ(EPWM2_IRQn);
    ECLIC_EnableIRQ(EPWM3_IRQn);

    //
    // Enable Global Interrupt
    //
    CPU_enableIrq();

    //
    // IDLE loop. Just sit and loop forever (optional):
    //
    for(;;)
    {
        NOP;
    }
}

//*****************************************************************************
//
// epwm1ISR - ePWM 1 ISR handler
//
//*****************************************************************************
__INTERRUPT void epwm1ISR(void)
{
    //
    // Update the CMPA and CMPB values
    //
    updateCompare(&epwm1Info);

    //
    // Clear INT flag for this timer
    //
    EPWM_clearEventTriggerInterruptFlag(myEPWM1_BASE);

}

//*****************************************************************************
//
// epwm2ISR - ePWM 2 ISR handler
//
//*****************************************************************************
__INTERRUPT void epwm2ISR(void)
{
    //
    // Update the CMPA and CMPB values
    //
    updateCompare(&epwm2Info);

    //
    // Clear INT flag for this timer
    //
    EPWM_clearEventTriggerInterruptFlag(myEPWM2_BASE);

}

//*****************************************************************************
//
// epwm3ISR - ePWM 3 ISR handler
//
//*****************************************************************************
__INTERRUPT void epwm3ISR(void)
{
    //
    // Update the CMPA and CMPB values
    //
    updateCompare(&epwm3Info);

    //
    // Clear INT flag for this timer
    //
    EPWM_clearEventTriggerInterruptFlag(myEPWM3_BASE);

}

//*****************************************************************************
//
// initEPWM1 - Initialize ePWM1 module
//
//*****************************************************************************
void initEPWM1(void)
{
    //
    // Information this example uses to keep track of the direction the
    // CMPA/CMPB values are moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm1Info.epwmCompADirection = EPWM_CMP_UP;
    epwm1Info.epwmCompBDirection = EPWM_CMP_DOWN;
    epwm1Info.epwmTimerIntCount = 0U;
    epwm1Info.epwmModule   = myEPWM1_BASE;
    epwm1Info.epwmMaxCompA = EPWM1_MAX_CMPA;
    epwm1Info.epwmMinCompA = EPWM1_MIN_CMPA;
    epwm1Info.epwmMaxCompB = EPWM1_MAX_CMPB;
    epwm1Info.epwmMinCompB = EPWM1_MIN_CMPB;
}

//*****************************************************************************
//
// initEPWM2 - Initialize ePWM2 module
//
//*****************************************************************************
void initEPWM2(void)
{
    //
    // Information this example uses to keep track of the direction the
    // CMPA/CMPB values are moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm2Info.epwmCompADirection = EPWM_CMP_UP;
    epwm2Info.epwmCompBDirection = EPWM_CMP_UP;
    epwm2Info.epwmTimerIntCount = 0U;
    epwm2Info.epwmModule   = myEPWM2_BASE;
    epwm2Info.epwmMaxCompA = EPWM2_MAX_CMPA;
    epwm2Info.epwmMinCompA = EPWM2_MIN_CMPA;
    epwm2Info.epwmMaxCompB = EPWM2_MAX_CMPB;
    epwm2Info.epwmMinCompB = EPWM2_MIN_CMPB;
}

//*****************************************************************************
//
// initEPWM3 - Initialize ePWM3 module
//
//*****************************************************************************
void initEPWM3(void)
{
    //
    // Information this example uses to keep track of the direction the
    // CMPA/CMPB values are moving, the min and max allowed values and
    // a pointer to the correct ePWM registers
    //
    epwm3Info.epwmCompADirection = EPWM_CMP_UP;
    epwm3Info.epwmCompBDirection = EPWM_CMP_DOWN;
    epwm3Info.epwmTimerIntCount = 0U;
    epwm3Info.epwmModule   = myEPWM3_BASE;
    epwm3Info.epwmMaxCompA = EPWM3_MAX_CMPA;
    epwm3Info.epwmMinCompA = EPWM3_MIN_CMPA;
    epwm3Info.epwmMaxCompB = EPWM3_MAX_CMPB;
    epwm3Info.epwmMinCompB = EPWM3_MIN_CMPB;
}

//*****************************************************************************
//
// updateCompare - Update ePWM compare values
//
//*****************************************************************************
void updateCompare(epwmInformation *epwmInfo)
{
    uint16_t compAValue;
    uint16_t compBValue;

    compAValue = EPWM_getCounterCompareValue(epwmInfo->epwmModule,
                                             EPWM_COUNTER_COMPARE_A);

    compBValue = EPWM_getCounterCompareValue(epwmInfo->epwmModule,
                                             EPWM_COUNTER_COMPARE_B);

    //
    //  Change the CMPA/CMPB values every 10th interrupt.
    //
    if(epwmInfo->epwmTimerIntCount == 10U)
    {
        epwmInfo->epwmTimerIntCount = 0U;

        //
        // If we were increasing CMPA, check to see if we reached the max
        // value. If not, increase CMPA else, change directions and decrease
        // CMPA
        //
        if(epwmInfo->epwmCompADirection == EPWM_CMP_UP)
        {
            if(compAValue < (epwmInfo->epwmMaxCompA))
            {
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_A,
                                            ++compAValue);
            }
            else
            {
                epwmInfo->epwmCompADirection = EPWM_CMP_DOWN;
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_A,
                                            --compAValue);
            }
        }
        //
        // If we were decreasing CMPA, check to see if we reached the min
        // value. If not, decrease CMPA else, change directions and increase
        // CMPA
        //
        else
        {
            if( compAValue == (epwmInfo->epwmMinCompA))
            {
                epwmInfo->epwmCompADirection = EPWM_CMP_UP;
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_A,
                                            ++compAValue);
            }
            else
            {
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_A,
                                            --compAValue);
            }
        }

        //
        // If we were increasing CMPB, check to see if we reached the max
        // value. If not, increase CMPB else, change directions and decrease
        // CMPB
        //
        if(epwmInfo->epwmCompBDirection == EPWM_CMP_UP)
        {
            if(compBValue < (epwmInfo->epwmMaxCompB))
            {
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_B,
                                            ++compBValue);
            }
            else
            {
                epwmInfo->epwmCompBDirection = EPWM_CMP_DOWN;
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_B,
                                            --compBValue);
            }
        }
        //
        // If we were decreasing CMPB, check to see if we reached the min
        // value. If not, decrease CMPB else, change directions and increase
        // CMPB
        //
        else
        {
            if(compBValue == (epwmInfo->epwmMinCompB))
            {
                epwmInfo->epwmCompBDirection = EPWM_CMP_UP;
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_B,
                                            ++compBValue);
            }
            else
            {
                EPWM_setCounterCompareValue(epwmInfo->epwmModule,
                                            EPWM_COUNTER_COMPARE_B,
                                            --compBValue);
            }
        }
    }
    else
    {
        epwmInfo->epwmTimerIntCount++;
    }
}
