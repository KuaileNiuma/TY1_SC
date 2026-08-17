/**
 *************************************************************************************
 * @file cmpss_ex01_board.c
 * @brief This file contains the source file for example cmpss_ex01_board.
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


#include "cmpss_ex01_board.h"

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
	EALLOW;

	PinMux_init();
	CMPSS_init();
	OUTPUTXBAR_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//

	//
	// ANALOG -> myANALOGPinMux0 Pinmux
	//
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOC);
	// Analog PinMux for A0/B15/C15/DACA_OUT
	GPIO_setPinConfig(GPIO_231_GPIO231);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(231 , GPIOC_Analog_Mode);
	// Analog PinMux for A1/B7/DACB_OUT
	GPIO_setPinConfig(GPIO_232_GPIO232);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(232 , GPIOC_Analog_Mode);
	// Analog PinMux for A10/B1/C10
	GPIO_setPinConfig(GPIO_230_GPIO230);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(230 , GPIOC_Analog_Mode);
	// Analog PinMux for A11/B10/C0
	GPIO_setPinConfig(GPIO_237_GPIO237);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(237 , GPIOC_Analog_Mode);
	// Analog PinMux for A12, C5
	GPIO_setPinConfig(GPIO_238_GPIO238);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(238 , GPIOC_Analog_Mode);
	// Analog PinMux for A14/B14/C4
	GPIO_setPinConfig(GPIO_239_GPIO239);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(239 , GPIOC_Analog_Mode);
	// Analog PinMux for A2/B6/C9
	GPIO_setPinConfig(GPIO_224_GPIO224);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(224 , GPIOC_Analog_Mode);
	// Analog PinMux for A3, C7/B9
	GPIO_setPinConfig(GPIO_229_GPIO229);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(229 , GPIOC_Analog_Mode);
	// Analog PinMux for A4/B8
	GPIO_setPinConfig(GPIO_225_GPIO225);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(225 , GPIOC_Analog_Mode);
	// Analog PinMux for A5
	GPIO_setPinConfig(GPIO_249_GPIO249);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(249 , GPIOC_Analog_Mode);
	// Analog PinMux for A6
	GPIO_setPinConfig(GPIO_228_GPIO228);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(228 , GPIOC_Analog_Mode);
	// Analog PinMux for A8
	GPIO_setPinConfig(GPIO_240_GPIO240);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(240 , GPIOC_Analog_Mode);
	// Analog PinMux for A9
	GPIO_setPinConfig(GPIO_227_GPIO227);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(227 , GPIOC_Analog_Mode);
	// Analog PinMux for B0/C11
	GPIO_setPinConfig(GPIO_253_GPIO253);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(253 , GPIOC_Analog_Mode);
	// Analog PinMux for B11
	GPIO_setPinConfig(GPIO_251_GPIO251);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(251 , GPIOC_Analog_Mode);
	// Analog PinMux for B2/C6
	GPIO_setPinConfig(GPIO_226_GPIO226);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(226 , GPIOC_Analog_Mode);
	// Analog PinMux for B3/VDAC
	GPIO_setPinConfig(GPIO_242_GPIO242);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(242 , GPIOC_Analog_Mode);
	// Analog PinMux for B4/C8
	GPIO_setPinConfig(GPIO_236_GPIO236);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(236 , GPIOC_Analog_Mode);
	// Analog PinMux for B5
	GPIO_setPinConfig(GPIO_252_GPIO252);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(252 , GPIOC_Analog_Mode);
	// Analog PinMux for C1
	GPIO_setPinConfig(GPIO_248_GPIO248);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(248 , GPIOC_Analog_Mode);
	// Analog PinMux for C14
	GPIO_setPinConfig(GPIO_247_GPIO247);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(247 , GPIOC_Analog_Mode);
	// Analog PinMux for C2/B12
	GPIO_setPinConfig(GPIO_244_GPIO244);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(244 , GPIOC_Analog_Mode);
	// Analog PinMux for C3/A7
	GPIO_setPinConfig(GPIO_245_GPIO245);
	// AIO -> Analog mode selected
	SysCtl_setGPIOCAMSEL(245 , GPIOC_Analog_Mode);
	//
	// OUTPUTXBAR3 -> myOUTPUTXBAR0 Pinmux
	//
	GPIO_setPinConfig(myOUTPUTXBAR0_OUTPUTXBAR_PIN_CONFIG);

}

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
void CMPSS_init(){
	myCMPSS0_init();
}

void myCMPSS0_init(){

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS1);
    //
    // Select the value for CMP1HPMXSEL.
    //
    SysCtl_selectCMPHPMux(SYSCTL_CMPHPMUX_SELECT_1,0U);
    //
    // Select the value for CMP1LPMXSEL.
    //
    SysCtl_selectCMPLPMux(SYSCTL_CMPLPMUX_SELECT_1,0U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSS_configHighComparator(myCMPSS0_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSS_configLowComparator(myCMPSS0_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSS_configDAC(myCMPSS0_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSS_setDACValueHigh(myCMPSS0_BASE,0U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSS_setDACValueLow(myCMPSS0_BASE,0U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSS_configFilterHigh(myCMPSS0_BASE, 0U, 1U, 1U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSS_configFilterLow(myCMPSS0_BASE, 0U, 1U, 1U);
    //
    // Sets the output signal configuration for the high comparator.
    //
    CMPSS_configOutputsHigh(myCMPSS0_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the output signal configuration for the low comparator.
    //
    CMPSS_configOutputsLow(myCMPSS0_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSS_setHysteresis(myCMPSS0_BASE,0U);
    //
    // Configures the comparator subsystem's ramp generator.
    //
    CMPSS_configRamp(myCMPSS0_BASE,0U,0U,0U,1U,true);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCHigh(myCMPSS0_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCLow(myCMPSS0_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSS_configBlanking(myCMPSS0_BASE,1U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSS_disableBlanking(myCMPSS0_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSS_configLatchOnPWMSYNC(myCMPSS0_BASE,false,false);
    //
    // Enables the CMPSS module.
    //
    CMPSS_enableModule(myCMPSS0_BASE);
    //
    // Delay for CMPSS DAC to power up.
    //
    delay_ms(500);
}

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void OUTPUTXBAR_init(){
	myOUTPUTXBAR0_init();
}

void myOUTPUTXBAR0_init(){
	XBAR_setOutputLatchMode(OUTPUTXBAR_BASE, myOUTPUTXBAR0, false);
	XBAR_invertOutputSignal(OUTPUTXBAR_BASE, myOUTPUTXBAR0, false);

	//
	//Mux configuration
	//
	XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, myOUTPUTXBAR0, XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH);
	XBAR_enableOutputMux(OUTPUTXBAR_BASE, myOUTPUTXBAR0, XBAR_MUX00);
}

