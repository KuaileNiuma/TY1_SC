/**
 *************************************************************************************
 * @file xbat_ex04_inputInt.c
 * @brief This file contains the source file for example xbat_ex04_inputInt.
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
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
static volatile int gFlag;            //!< Interrupt flag

//*****************************************************************************
//
// Defines
//
//*****************************************************************************
#define TIMELIMIT          (0x0000FFFFUL)   //!< Time limit for operations
#define PASS 1                              //!< Test pass status
#define FAIL 0                              //!< Test fail status

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void INPUTXBAR_init(void);
__INTERRUPT void XINT1ISR(void);


//*****************************************************************************
//
// INPUTXBAR_init - Initializes the Input XBAR with specified parameters
//
//*****************************************************************************
void INPUTXBAR_init(void){
    //
    // Configure the Input XBAR input pin
    //
    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT4, 0);
}

//*****************************************************************************
//
// main - Main function for XBAR input interrupt test
//
//*****************************************************************************
void main(void)
{
    int ret;                    //!< Test result
    int index;                  //!< Loop index
    alb32r003x_evb_init();
    //
    // Initialize variables
    //
    gFlag = 0;
    ret = FAIL;
    
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_XBAR);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);

    //
    // Register XINT1 interrupt handler
    //
	CPU_enableIrq();

    //
    // Register interrupt handler using C function
    //
    Interrupt_register(XINT1_IRQn, XINT1ISR);

    //
    // Set interrupt priority and enable interrupt
    //
    Interrupt_setPriority(XINT1_IRQn, 0, 0);
    Interrupt_enable(XINT1_IRQn);
    //
    // Configure GPIO pin as output
    //
    GPIO_setDirectionMode(1, GPIO_DIR_MODE_OUT);
	//
	// Initialize Input XBAR with parameters for XINT1
	//
	INPUTXBAR_init();

	//
	// Generate test pulses
	//
	for (index = 0; index < 5; index++) {
		delay_ms(300);
		GPIO_writePin(1, SET);
		delay_ms(300);
		GPIO_writePin(1, RESET);
	}

	//
	// Wait for interrupt flag
	//
	while (!gFlag);
	gFlag = 0;

	ret = PASS;

	while(1);
}


//*****************************************************************************
//
// XINT1ISR - Interrupt handler for XINT1
//
//*****************************************************************************
__INTERRUPT void XINT1ISR(void)
{
    //
    // Set interrupt flag to indicate interrupt was received
    //
    gFlag = 1;
}

