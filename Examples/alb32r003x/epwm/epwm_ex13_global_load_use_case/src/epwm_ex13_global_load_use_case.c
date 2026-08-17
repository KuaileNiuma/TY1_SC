/**
 *************************************************************************************
 * @file epwm_ex13_global_load_use_case.c
 * @brief This file contains the source file for example epwm_ex13_global_load_use_case.
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
#include "epwm_ex13_board.h"
#include "alb32r003x_evb.h"

//
// Globals
//
volatile uint16_t  perform_one_shot_load = 0;
volatile uint32_t ISR_CNT = 0;

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void main(void)
{
	  alb32r003x_evb_init();
	  EPWM_TypeDef EPWM;
      //
      // Disable sync(Freeze clock to PWM as well)
      //
      SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

      //
      // Configure ePWM1, ePWM2, and TZ GPIOs
      //
      Board_init();


      //
      // Enable sync and clock to PWM
      //
      SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

      //
      // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
      //
      CPU_enableIrq();

      //
      // IDLE loop. Just sit and loop forever (optional):
      //
      for(;;)
      {

          if( 0 == perform_one_shot_load  )
          {
              //
              // EPWM1, EPWM2, EPWM3 are linked so only EPWM1 needs to be updated
              //
              EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 100);
              EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 100);

              //
              // Change the Action Qualifier Settings for EPWM1, EPWM2, and EPWM3
              //
              EPWM_setActionQualifierAction(myEPWM1_BASE,EPWM_AQ_OUTPUT_A,EPWM_AQ_OUTPUT_LOW,
                                            EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
              EPWM_setActionQualifierAction(myEPWM1_BASE,EPWM_AQ_OUTPUT_A,EPWM_AQ_OUTPUT_HIGH,
                                            EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
              EPWM_setActionQualifierAction(myEPWM2_BASE,EPWM_AQ_OUTPUT_A,EPWM_AQ_OUTPUT_LOW,
                                            EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
              EPWM_setActionQualifierAction(myEPWM2_BASE,EPWM_AQ_OUTPUT_A,EPWM_AQ_OUTPUT_HIGH,
                                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
              EPWM_setActionQualifierAction(myEPWM3_BASE,EPWM_AQ_OUTPUT_A,EPWM_AQ_OUTPUT_LOW,
                                            EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
              EPWM_setActionQualifierAction(myEPWM3_BASE,EPWM_AQ_OUTPUT_A,EPWM_AQ_OUTPUT_HIGH,
                                            EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

              // EPWM1, EPWM2, EPWM3 are linked
              EPWM_setGlobalLoadOneShotLatch(myEPWM1_BASE);


          }else if( 1 == perform_one_shot_load )
          {
              //
              // EPWM1, EPWM2, EPWM3 are linked so only EPWM1 needs to be updated
              //
              EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 69);
              EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 69);

              //
              // Change the Action Qualifier Settings for EPWM1, EPWM2, and EPWM3
              //
              EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
            		  	  	  	  	  	  	EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
              EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
            		  	  	  	  	  	  	EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
              EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
            		  	  	  	  	  	  	EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
              EPWM_setActionQualifierAction(myEPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
            		  	  	  	  	  	  	EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
              EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
            		  	  	  	  	  	  	EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
              EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
            		  	  	  	  	  	  	EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

              //                              
              // EPWM1, EPWM2, EPWM3 are linked
              //
              EPWM_setGlobalLoadOneShotLatch(myEPWM1_BASE);
          }
      }
}

//*****************************************************************************
//
// ePWM1 ISR
//
//*****************************************************************************
__INTERRUPT void INT_myEPWM1_ISR(void)
{
//	static uint32_t ISR_CNT = 0;

	if( ++ISR_CNT >= 300000)
	{
		ISR_CNT = 0;
		perform_one_shot_load = !perform_one_shot_load;
	}

	EPWM_clearEventTriggerInterruptFlag(myEPWM1_BASE);
}

//*****************************************************************************
//
// ePWM2 TZ ISR
//
//*****************************************************************************
__INTERRUPT void INT_myEPWM2_TZ_ISR(void)
{

     //
     // Clear the flags
     //
     EPWM_clearTripZoneFlag(myEPWM2_BASE, (EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_CBC));


}

//*****************************************************************************
//
// ePWM3 TZ ISR
//
//*****************************************************************************
__INTERRUPT void INT_myEPWM3_TZ_ISR(void)
{

    //
    // Re-enable the OST Interrupt
    //
	EPWM_clearOneShotTripZoneFlag(myEPWM3_BASE,EPWM_TZ_OST_FLAG_OST1);
    EPWM_clearTripZoneFlag(myEPWM3_BASE, (EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST));

}

