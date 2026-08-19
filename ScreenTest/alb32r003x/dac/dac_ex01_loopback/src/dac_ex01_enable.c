/**
 *************************************************************************************
 * @file dac_ex01_enable.c
 * @brief This file contains the source file for example dac_ex01_enable.
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
#include "stdio.h"
#include "math.h"
#include "device.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define myDAC0_BASE         DACC1_BASE                   //!< DACA base address
#define myDAC1_BASE         DACC2_BASE                   //!< DACB base address
#define myADC0_BASE         ADCA_BASE                    //!< ADCA base address
#define myADC1_BASE         ADCB_BASE                    //!< ADCB base address

#define ADC_SAMPLE_TIME     40U                          //!< ADC sample time in SYSCLK cycles
#define VREFHI_VAL          1.65                         //!< Reference voltage value
#define SIN_SAMPLE          128                          //!< Number of sine wave samples
//*****************************************************************************
//
// Local Variables
//
//*****************************************************************************
uint16_t ADCA0_Result[128];                 //!< ADCA Channel 0 result buffer
uint16_t ADCA1_Result[128];                 //!< ADCA Channel 1 result buffer
uint16_t ADCB15_Result[128];                //!< ADCB Channel 15 result buffer
uint16_t ADCB7_Result[128];                 //!< ADCB Channel 7 result buffer
uint32_t AdcResultIdx;                      //!< ADC result index counter
uint16_t g_dac_sin_array[128] = {
	4064, 4059, 4045, 4038, 4010, 3967, 3940, 3890,
	3823, 3772, 3698, 3617, 3540, 3442, 3337, 3254, 3139, 3017,
	2908, 2779, 2657, 2538, 2407, 2277, 2151, 2019, 1885, 1770,
	1630, 1497, 1386, 1258, 1133, 1028, 906, 801, 708, 610,
	513, 436, 351, 281, 226, 156, 110, 78, 40, 14,
	6, 0, 0, 3, 19, 39, 84, 118, 167, 231,
	287, 357, 442, 520, 610, 718, 811, 917, 1034, 1154,
	1261, 1396, 1514, 1645, 1776, 1899, 2029, 2172, 2296, 2421,
	2558, 2675, 2793, 2918, 3035, 3136, 3255, 3347, 3449, 3542,
	3624, 3697, 3774, 3835, 3887, 3942, 3979, 4013, 4039, 4059,
	4061, 4070, 4056, 4040, 4020, 3971, 3933, 3892, 3832, 3768,
	3700, 3611, 3529, 3446, 3346, 3237, 3132, 3011, 2893, 2786,
	2655, 2532, 2410, 2275, 2145, 2023, 1890, 1752, 1632, 1483,
	};       //!< Sinusoidal waveform data array


//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint16_t DACA_Val = 0;                      //!< DACA output value
uint16_t DACB_Val = 4095;                   //!< DACB output value
DACC_TypeDef * test = (DACC_TypeDef *)0;

void ANA_init()
{
    // SysCtl_setAnalogReferenceExternal(SYSCTL_VREFHI);
    SysCtl_setAnalogReferenceInternal(SYSCTL_VREFHI);
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
    //Set DACA_OUT to analog mode
    //
    SysCtl_setGPIOCAMSEL(231 , GPIOC_Analog_Mode);
    //
    //Set DACA_OUT to analog mode
    //
    SysCtl_setGPIOCAMSEL(232 , GPIOC_Analog_Mode);
}

//*****************************************************************************
//
// Initializes DACA module
//
//*****************************************************************************

void myDAC0_init(void)
{
	EALLOW;
    //
    // Enable CMPSS clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DACC1);
    //
    // Set DAC reference voltage.
    //
    DAC_setReferenceVoltage(myDAC0_BASE, DAC_REF_ADC_VREFHI);
    //
    // Enable CMPSS clock
    //
	RCC_AHB2PeriphClockCmd(DACC1_CLK_EN,ENABLE);
    //
    // Set DAC load mode.
    //
    DAC_setLoadMode(myDAC0_BASE, DAC_LOAD_SYSCLK);
    //
    // configured with a gain mode of 1
    //
    DAC_setGainMode(myDAC0_BASE, DAC_GAIN_ONE);
    //
    // Enable the DAC output
    //
    DAC_enableOutput(myDAC0_BASE);
    //
    // Set the DAC shadow output
    //
    DAC_setShadowValue(myDAC0_BASE, 0U);
    //
    // Delay for buffered DAC to power up.
    //
    delay_ms(50);

    EDIS;
}

//*****************************************************************************
//
// Initializes DACB module
//
//*****************************************************************************
void myDAC1_init(void)
{
	EALLOW;
    //
    // Enable CMPSS clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DACC2);
    //
    // Set DAC reference voltage.
    //
    DAC_setReferenceVoltage(myDAC1_BASE, DAC_REF_ADC_VREFHI);
    //
    // Set DAC load mode.
    //
    DAC_setLoadMode(myDAC1_BASE, DAC_LOAD_SYSCLK);
    //
    // configured with a gain mode of 1
    //
    DAC_setGainMode(myDAC1_BASE, DAC_GAIN_ONE);
    //
    // Enable the DAC output
    //
    DAC_enableOutput(myDAC1_BASE);
    //
    // Set the DAC shadow output
    //
    DAC_setShadowValue(myDAC1_BASE, 0U);
    //
    // Delay for buffered DAC to power up.
    //
    delay_ms(50);

    EDIS;
}

//*****************************************************************************
//
// Initializes ADCA module for sampling DACA_OUT
//
//*****************************************************************************

void myADC0_init()
{
    //
    //Turn on the ADC1 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC1);
    //
    // Configures the analog-to-digital converter module prescaler
    //
    ADC_setPrescaler(myADC0_BASE, ADC_CLK_DIV_4_0);

    //
    // Sets the timing of the end-of-conversion pulse
    //
    ADC_setInterruptPulseMode(myADC0_BASE, ADC_PULSE_END_OF_CONV);

    //
    // Powers up the analog-to-digital converter core.
    //
    ADC_enableConverter(myADC0_BASE);

    //
    // Delay for 5ms to allow ADC time to power up
    //
    delay_ms(5);

    //
    // Start of Conversion 0 Configuration
    //
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //  	  	SOC number		: 0
    //  	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
    //  	  	Channel			: ADC_CH_ADCIN0
    //  	  	Sample Window	: 50 SYSCLK cycles
    //  	  	Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
    //
    ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_CPU1_TINT0,
            ADC_CH_ADCIN0, ADC_SAMPLE_TIME);
    ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER0,
            ADC_INT_SOC_TRIGGER_NONE);

    //
    // Start of Conversion 1 Configuration
    //
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //  	  	SOC number		: 1
    //  	  	Trigger			: ADC_TRIGGER_SW_ONLY
    //  	  	Channel			: ADC_CH_ADCIN1
    //  	  	Sample Window	: 50 SYSCLK cycles
    //  	  	Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
    //
    ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_SW_ONLY,
            ADC_CH_ADCIN1, ADC_SAMPLE_TIME);
    ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER1,
            ADC_INT_SOC_TRIGGER_NONE);

    //
    // ADC Interrupt 1 Configuration
    // 		SOC/EOC number	: 1
    // 		Interrupt Source: enabled
    // 		Continuous Mode	: disabled
    //
    ADC_setInterruptSource(myADC0_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
    ADC_enableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    ADC_disableContinuousMode(myADC0_BASE, ADC_INT_NUMBER1);
}

//*****************************************************************************
//
// Initializes ADCB module for sampling DAC outputs
//
//*****************************************************************************

void myADC1_init()
{
    //
    //Turn on the ADC2 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC2);
    //
    // Configures the analog-to-digital converter module prescaler
    //
    ADC_setPrescaler(myADC1_BASE, ADC_CLK_DIV_4_0);

    //
    // Sets the timing of the end-of-conversion pulse
    //
    ADC_setInterruptPulseMode(myADC1_BASE, ADC_PULSE_END_OF_CONV);

    //
    // Powers up the analog-to-digital converter core.
    //
    ADC_enableConverter(myADC1_BASE);

    //
    // Delay for 5ms to allow ADC time to power up
    //
    delay_ms(5);

    //
    // Start of Conversion 0 Configuration
    //
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //  	  	SOC number		: 0
    //  	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
    //  	  	Channel			: ADC_CH_ADCIN15
    //  	  	Sample Window	: 50 SYSCLK cycles
    //  	  	Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
    //
    ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_CPU1_TINT0,
            ADC_CH_ADCIN15, ADC_SAMPLE_TIME);
    ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER0,
            ADC_INT_SOC_TRIGGER_NONE);

    //
    // Start of Conversion 1 Configuration
    //
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //  	  	SOC number		: 1
    //  	  	Trigger			: ADC_TRIGGER_SW_ONLY
    //  	  	Channel			: ADC_CH_ADCIN7
    //  	  	Sample Window	: 50 SYSCLK cycles
    //  	  	Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
    //
    ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_SW_ONLY,
            ADC_CH_ADCIN7, ADC_SAMPLE_TIME);
    ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER1,
            ADC_INT_SOC_TRIGGER_NONE);

    //
    // ADC Interrupt 1 Configuration
    // 		SOC/EOC number	: 1
    // 		Interrupt Source: enabled
    // 		Continuous Mode	: disabled
    //
    ADC_setInterruptSource(myADC1_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
    ADC_enableInterrupt(myADC1_BASE, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(myADC1_BASE, ADC_INT_NUMBER1);
    ADC_disableContinuousMode(myADC1_BASE, ADC_INT_NUMBER1);
}

//*****************************************************************************
//
// main()
//
//*****************************************************************************

void main(void)
{
	alb32r003x_evb_init();
    //
    // Board initialization
    // Configure DAC - Setup the reference voltage and output value for the DAC
    //
	ANA_init();
	GPIO_init();

    myDAC0_init();
    myDAC1_init();

    myADC0_init();
    myADC1_init();
    uint16_t i = 0;

    //
    // Continuously set the DAC output value
    //
    while (1)
    {
        //
        // Set DAC1 output value - 0~4095 = 0V~VREFHI_VAL
        //
        DAC_setShadowValue(myDAC0_BASE, DACA_Val);
        DAC_setShadowValue(myDAC1_BASE, DACB_Val);
        delay_ms(10);
        //
        // Software trigger ADC conversion SOC0 and SOC1
        //
        ADC_forceMultipleSOC(myADC0_BASE, ADC_FORCE_SOC0 | ADC_FORCE_SOC1);
        //
        // wait till ADC result ready
        //
        while (ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == 0)
            ;
        //
        // read ADC_A0 result
        //
        ADCA0_Result[AdcResultIdx] = ADC_readResult(ADCARESULT_BASE,
                ADC_SOC_NUMBER0);
        //
        // read ADC_A1 result (it's for DACB_OUT test)
        //
        ADCA1_Result[AdcResultIdx] = ADC_readResult(ADCARESULT_BASE,
                ADC_SOC_NUMBER1);
        //
        // clear ADC int flag
        //
        ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);

        //
        // Software trigger ADC conversion SOC0 and SOC1
        //
        ADC_forceMultipleSOC(myADC1_BASE, ADC_FORCE_SOC0 | ADC_FORCE_SOC1);
        //
        // wait till ADC result ready
        //
        while (ADC_getInterruptStatus(myADC1_BASE, ADC_INT_NUMBER1) == 0)
            ;
        //
        // read ADC_B15 result
        //
        ADCB15_Result[AdcResultIdx] = ADC_readResult(ADCBRESULT_BASE,
                ADC_SOC_NUMBER0);
        //
        // read ADC_B7 result (it's for DACB_OUT test)
        //
        ADCB7_Result[AdcResultIdx] = ADC_readResult(ADCBRESULT_BASE,
                ADC_SOC_NUMBER1);
        //
        // clear ADC int flag
        //
        ADC_clearInterruptStatus(myADC1_BASE, ADC_INT_NUMBER1);
        AdcResultIdx++;
//        if(AdcResultIdx == 128)
//        {
//        	AdcResultIdx = 0;
//            printf("-----ADCA0 Sample Value: -----\r\n");
//            for(i = 0;i < 128;i++)
//            {
//                printf("ADCA0 = %d\r\n", ADCA0_Result[i]);
//            }
//            printf("-----ADCA1 Sample Value: -----\r\n");
//            for(i = 0;i < 128;i++)
//            {
//                printf("ADCA1 = %d\r\n", ADCA1_Result[i]);
//            }
//            printf("-----ADCB15 Sample Value: -----\r\n");
//            for(i = 0;i < 128;i++)
//            {
//                printf("ADCB15 = %d\r\n", ADCB15_Result[i]);
//            }
//            printf("-----ADCB7 Sample Value: -----\r\n");
//            for(i = 0;i < 128;i++)
//            {
//                printf("ADCB7 = %d\r\n", ADCB7_Result[i]);
//            }
//        }

        //
        // DAC_A output value
        //
        DACA_Val = g_dac_sin_array[i++];
        if (i >= SIN_SAMPLE)
        {
            i = 0;
        }

        //
        // decrement DAC_B output value
        //
        DACB_Val -= (4096 / 128);
        DACB_Val %= 4096;

    }
}

//
// End of File
//

#ifdef __cplusplus
}
#endif

