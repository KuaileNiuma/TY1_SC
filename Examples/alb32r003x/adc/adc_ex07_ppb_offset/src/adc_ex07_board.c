/**
 *************************************************************************************
 * @file adc_ex07_board.c
 * @brief This file contains the board initialization and configuration for example adc_ex07_board.
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

#ifdef __cplusplus
extern "C"{
#endif

//*****************************************************************************
//
// Include Files
//                                  
//*****************************************************************************
#include "adc_ex07_board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules.
// Call this function in your application if you wish to do all module
// initialization.
// If you wish to not use some of the initializations, instead of the
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	ANA_init();
    ADC_init();
    INTERRUPT_init();
}

//*****************************************************************************
//
// ANALOG Configurations
//
//*****************************************************************************
void ANA_init()
{
    ADC_setVREF(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init()
{
    //
    //Turn on the GPIO3 peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOC);
    //
    //Set PAD237 to analog mode
    //
    SysCtl_setGPIOCAMSEL(myANALOGPinMux0 , GPIOC_Analog_Mode);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init()
{
    Interrupt_register(myADC0_IRQn, adcA1ISR);
    Interrupt_setPriority(myADC0_IRQn, 0, 0);
    Interrupt_enable(myADC0_IRQn);
    ECLIC_EnableIRQ(myADC0_IRQn);
}

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void ADC_init()
{
    myADC0_init();
}

//*****************************************************************************
//
// myADC0_init
//
//*****************************************************************************
void myADC0_init()
{
    //
    //Turn on the ADC1 peripheral clock
    //
    SysCtl_enablePeripheral(myADC0_CLK_EN);
    //
    // Configures the analog-to-digital converter module prescaler.
    //
    ADC_setPrescaler(myADC0_BASE, ADC_CLK_DIV_4_0);
    //
    // Sets the timing of the end-of-conversion pulse
    //
    ADC_setInterruptPulseMode(myADC0_BASE, ADC_PULSE_END_OF_CONV);

    //
    // Delay for 50ms to allow ADC time to power up
    //
    delay_ms(50);
    //
    // SOC Configuration: Setup ADC EPWM channel and trigger settings
    //
    // Disables SOC burst mode.
    //
    ADC_disableBurstMode(myADC0_BASE);
    //
    // Sets the priority mode of the SOCs.
    //
    ADC_setSOCPriority(myADC0_BASE, ADC_PRI_ALL_ROUND_ROBIN);
    //
    // Start of Conversion 0 Configuration
    //
    //
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    // 	  	SOC number		: 0
    //	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
    //	  	Channel			: ADC_CH_ADCIN0
    //	 	Sample Window	: 50 SYSCLK cycles
    //		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
    //
    ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_SW_ONLY,
            ADC_CH_ADCIN11, 500);
    ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER0,
            ADC_INT_SOC_TRIGGER_NONE);
    //
    // ADC Interrupt 1 Configuration
    // 		SOC/EOC number	: 0
    // 		Interrupt Source: enabled
    // 		Continuous Mode	: disabled
    //
    ADC_setInterruptSource(myADC0_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
    ADC_enableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    ADC_disableContinuousMode(myADC0_BASE, ADC_INT_NUMBER1);

    //
    // Power Path Buffer (PPB) Configuration
    // Configures the power path buffer (PPB) for the ADC.
    //
    ADC_setupPPB(myADC0_BASE, ADC_PPB_NUMBER1, ADC_SOC_NUMBER0);
    ADC_setupPPB(myADC0_BASE, ADC_PPB_NUMBER2, ADC_SOC_NUMBER0);
    ADC_setupPPB(myADC0_BASE, ADC_PPB_NUMBER3, ADC_SOC_NUMBER0);
    ADC_setupPPB(myADC0_BASE, ADC_PPB_NUMBER4, ADC_SOC_NUMBER0);
    ADC_setPPBReferenceOffset(myADC0_BASE, ADC_PPB_NUMBER1, 128);
    ADC_setPPBReferenceOffset(myADC0_BASE, ADC_PPB_NUMBER2, 256);
    ADC_setPPBReferenceOffset(myADC0_BASE, ADC_PPB_NUMBER3, 512);
    ADC_setPPBReferenceOffset(myADC0_BASE, ADC_PPB_NUMBER4, 1024);
    //
    // Powers up the analog-to-digital converter core.
    //
    ADC_enableConverter(myADC0_BASE);
}

#ifdef __cplusplus

#endif

