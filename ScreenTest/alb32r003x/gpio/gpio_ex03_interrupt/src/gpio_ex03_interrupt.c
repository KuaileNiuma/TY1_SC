/**
 *************************************************************************************
 * @file gpio_ex03_interrupt.c
 * @brief This file contains the source file for example gpio_ex03_interrupt.
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
#include "device.h"
#include "gpio.h"
#include "timer.h"
#include "interrupt.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define TIMER_PERIOD   (SystemClock_Get_AHB()/4)      //!< Timer period for LED blinking
#define MY_TIMER_BASE  TIMER1_BASE
#define MY_TIMER_CHANNEL    TIMER_CHANNEL1
#define MY_TIMER_IRQ   TIMER1_C1_IRQn
//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t gpio_IQR=0;                   		//!< GPIO interrupt status variable
TIMER_InitTypeDef TIMER_InitStruct = {0};   //!< Timer initialization structure
volatile uint32_t timerTicks = 0;       	//!< Timer tick counter

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
__INTERRUPT void mytimerCHISR(void);
__INTERRUPT void gpio_portaISR(void);
void timer_init( void );
void gpio_test03_init(void);

//*****************************************************************************
//
// Timer interrupt service routine
// Toggles different GPIO pins based on timer tick count
//
//*****************************************************************************
__INTERRUPT void mytimerCHISR(void)
{
	TIMER_clearInterruptPending(MY_TIMER_BASE, MY_TIMER_CHANNEL);
	if (timerTicks % 4 == 0)
	{
		GPIO_togglePin(8);
	}
	else if (timerTicks % 4 == 1)
	{
		GPIO_togglePin(9);
	}
	else if (timerTicks % 4 == 2)
	{
		GPIO_togglePin(10);
	}
	else
	{
		GPIO_togglePin(11);
	}
	timerTicks++;
	__DSB();
}


//*****************************************************************************
//
// Initialize timer interrupt
// Configures interrupt vector, priority and enables the interrupt
//
//*****************************************************************************
void Timer_irq_init(uint8_t timerid, uint8_t channel)
{
	IRQn_Type timer_IRQn = TIMER1_C1_IRQn;
	if (1 == channel)
	{
		timer_IRQn = TIMER1_C2_IRQn-timerid;
	}
	else if (channel==0 && timerid>0)
	{
		timer_IRQn = TIMER2_C1_IRQn-timerid;
	}
    Interrupt_register(timer_IRQn, mytimerCHISR);
    Interrupt_setPriority(timer_IRQn,0,0);
    Interrupt_enable(timer_IRQn);
}

//*****************************************************************************
//
// Initialize timer module
// Configures timer mode, period and interrupt settings
//
//*****************************************************************************
void timer_init( void )
{
	TIMER_InitStruct.channel = MY_TIMER_CHANNEL;
	TIMER_InitStruct.cfg.count = TIMER_PERIOD;
	TIMER_InitStruct.cfg.irq_en = TIMER_INT_ENABLE;
	TIMER_InitStruct.cfg.mode = TIMER_USER_DEFINED_MODE;

	TIMER_init(MY_TIMER_BASE, &TIMER_InitStruct);

    Interrupt_register(MY_TIMER_IRQ, mytimerCHISR);
    Interrupt_setPriority(MY_TIMER_IRQ,0,0);
    Interrupt_enable(MY_TIMER_IRQ);

	TIMER_start(MY_TIMER_BASE, MY_TIMER_CHANNEL);
}

//*****************************************************************************
//
// GPIO port A interrupt service routine
// Handles interrupts from GPIO pins 0-3 and toggles corresponding output pins
//
//*****************************************************************************
__INTERRUPT void gpio_portaISR(void)
{
	//
	// Get port interrupt status
	//
	gpio_IQR = GPIO_getPortInterruptStatus(GPIO_PORT_A);
	
	//
	// Handle GPIO0 interrupt (rising edge)
	//
	if(GPIO_getPinInterruptStatus(0))
	{
		GPIO_togglePin(4);
		GPIO_clearPinInterruptStatus(0);
	}
	
	//
	// Handle GPIO1 interrupt (rising edge)
	//
	if(GPIO_getPinInterruptStatus(1))
	{
		GPIO_togglePin(5);
		GPIO_clearPinInterruptStatus(1);
	}
	
	//
	// Handle GPIO2 interrupt (falling edge)
	//
	if(GPIO_getPinInterruptStatus(2))
	{
		GPIO_togglePin(6);
		GPIO_clearPinInterruptStatus(2);
	}
	
	//
	// Handle GPIO3 interrupt (falling edge)
	//
	if(GPIO_getPinInterruptStatus(3))
	{
		GPIO_togglePin(7);
		GPIO_clearPinInterruptStatus(3);
	}
	
	//
	// Make sure the interrupt flag clear is completed
	//
	__DSB();
}
//*****************************************************************************
//
// Initialize GPIO test for interrupt example
// Configures GPIO pins for interrupts and output mode
//
//*****************************************************************************
void gpio_test03_init()
{
	//
	// Configure GPIO interrupt handler
	//
    Interrupt_register(GPIO1_IRQn, gpio_portaISR);
    Interrupt_enable(GPIO1_IRQn);

	//
	// Set GPIO0 and GPIO1 to rising edge interrupt
	//
	GPIO_setInterruptType(0,GPIO_INT_TYPE_RISING_EDGE);
	GPIO_setInterruptType(1,GPIO_INT_TYPE_RISING_EDGE);
	
	//
	// Set GPIO2 and GPIO3 to falling edge interrupt
	//
	GPIO_setInterruptType(2,GPIO_INT_TYPE_FALLING_EDGE);
	GPIO_setInterruptType(3,GPIO_INT_TYPE_FALLING_EDGE);

	//
	// Enable GPIO0,1,2,3 interrupts
	//
	GPIO_enableInterrupt(0);
	GPIO_enableInterrupt(1);
	GPIO_enableInterrupt(2);
	GPIO_enableInterrupt(3);

	//
	// Set GPIO4-11 to output mode for LED indicators
	//
	GPIO_setDirectionMode(4,GPIO_DIR_MODE_OUT);
	GPIO_setDirectionMode(5,GPIO_DIR_MODE_OUT);
	GPIO_setDirectionMode(6,GPIO_DIR_MODE_OUT);
	GPIO_setDirectionMode(7,GPIO_DIR_MODE_OUT);
	GPIO_setDirectionMode(8,GPIO_DIR_MODE_OUT);
	GPIO_setDirectionMode(9,GPIO_DIR_MODE_OUT);
	GPIO_setDirectionMode(10,GPIO_DIR_MODE_OUT);
	GPIO_setDirectionMode(11,GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
    alb32r003x_evb_init();
    //
    // Print test information
    //
    printf("GPIO EX03 INTERRUPT.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Initialize GPIO interrupt configuration
    //
    gpio_test03_init();
    
    //
    // Initialize timer for LED blinking
    //
    timer_init();
    
    //
    // Infinite loop
    //
    return SC_PASS;
}
