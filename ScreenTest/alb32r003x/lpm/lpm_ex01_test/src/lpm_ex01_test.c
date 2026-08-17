/**
 *************************************************************************************
 * @file lpm_ex01_test.c
 * @brief This file contains the source file for example lpm_ex01_test.
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
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define TEST_GPIO_PIN     (3)                           //!< GPIO pin used for testing
#define TIMER_PERIOD      (SystemClock_Get_APBH()*3)    //!< Timer period value
#define MY_TIMER_BASE     TIMER1_BASE                   //!< Timer base used
#define MY_TIMER_CHANNEL  TIMER_CHANNEL1                //!< Timer channel used
#define MY_TIMER_IRQ      TIMER1_C1_IRQn                //!< Timer IRQ used

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
TIMER_InitTypeDef TIMER1_InitStruct = {0};   //!< Timer1 initialization structure
volatile uint32_t Timer_ex1_IntCnt = 0;      //!< Timer interrupt counter
volatile uint32_t Timer_ex1_TestDone = 0;    //!< Test completion flag



//*****************************************************************************
//
// Timer Channel Interrupt Service Routine
// 
//*****************************************************************************
__INTERRUPT void mytimerCHISR(void)
{
	//
	// Clear timer interrupt flag
	//
	TIMER_clearInterruptPending(MY_TIMER_BASE, MY_TIMER_CHANNEL);
	
	//
	// Log interrupt occurrence
	//
	log_printf("timer irq....\r\n");
	
	//
	// Increment interrupt counter
	//
	Timer_ex1_IntCnt++;
	
}	
	 


//*****************************************************************************
//
// GPIO Interrupt Service Routine
// 
//*****************************************************************************
__INTERRUPT void mygpioISR(void)
{
	//
	// Check if the interrupt is from the test GPIO pin
	//
	if (GPIO_getPinInterruptStatus(TEST_GPIO_PIN))
	{
		//
		// Log GPIO interrupt occurrence
		//
		log_printf("gpio_%d irq....\r\n", TEST_GPIO_PIN);
		
		//
		// Clear GPIO interrupt flag
		//
		GPIO_clearPinInterruptStatus(TEST_GPIO_PIN);
	}
}


//*****************************************************************************
//
// Timer Initialization Function
// 
//*****************************************************************************
void timer_init(void)
{
	//
	// Configure timer channel and instance
	//
	TIMER1_InitStruct.channel = MY_TIMER_CHANNEL;

	//
	// Configure timer count, interrupt, and mode
	//
	TIMER1_InitStruct.cfg.count = TIMER_PERIOD;
	TIMER1_InitStruct.cfg.irq_en = TIMER_INT_ENABLE;
	TIMER1_InitStruct.cfg.mode = TIMER_USER_DEFINED_MODE;

	//
	// Configure PWM settings (disabled for this example)
	//
	TIMER1_InitStruct.cfg.count2 = 0;
	TIMER1_InitStruct.cfg.on100pwm_en = TIMER_ON100PWM_DISABLE;
	TIMER1_InitStruct.cfg.pwm_en = TIMER_PWM_DISABLE;

	//
	// Initialize the timer with the configuration
	//
	TIMER_init(MY_TIMER_BASE, &TIMER1_InitStruct);

    Interrupt_register(MY_TIMER_IRQ, mytimerCHISR);

    //
    // Set interrupt priority and enable interrupt
    //
    Interrupt_setPriority(MY_TIMER_IRQ, 0, 0);
    Interrupt_enable(MY_TIMER_IRQ);

    //
    // Start the timer
    //
    TIMER_start(MY_TIMER_BASE, MY_TIMER_CHANNEL);

}

//*****************************************************************************
//
// Board Initialization Function
// 
//*****************************************************************************
void Board_init()
{
	//
	// Configure GPIO pin and interrupt
	//
	SysCtl_enableNMI();
	GPIO_setPinConfig(GPIO_3_GPIO3);
    GPIO_setInterruptType(TEST_GPIO_PIN, GPIO_EXTI_INT_HIGH_LEVEL);
    GPIO_enableInterrupt(TEST_GPIO_PIN);

	//
	// Initialize timer and interrupts
	//
    timer_init();

}


//*****************************************************************************
//
// XINT1 Interrupt Handler
// 
//*****************************************************************************
__INTERRUPT void XINT1ISR(void)
{
    SystemClock_Set200MHz( OSCSRC_HSI);
    /* configure USART */
    evb_com_init(EVB_COM_UART);
	//
	// Log interrupt handler execution
	//
	log_printf("%s:%d.....\r\n", __func__, __LINE__);
}
//*****************************************************************************
//
// Main Function
// 
//*****************************************************************************
int main(void)
{
	uint32_t cnt = 0;  //!< Counter for wake-up cycles

	alb32r003x_evb_init();;
	//
	// Print test start message
	//
	log_printf("TIMER EX02 IRQ.\r\n");
	//
	// Enable global interrupts
	//
	CPU_enableIrq();
	
	//
	// Initialize board hardware
	//
	Board_init();
	//
	// Configure wake-up and external interrupt settings
	//
	SysCtl_enableNMI();
	SysCtl_setExtiWakeUp(ENABLE);   // Enable external interrupt wake-up
	LPM_enableWakeupPin();  // Enable EWUP for WKUP pin
	XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT4, 3);
	//
	// Register XINT1 interrupt handler
	//
    Interrupt_register(XINT1_IRQn, XINT1ISR);
    Interrupt_enable(XINT1_IRQn);
	//
	// Main loop - enters sleep mode and waits for interrupts
	//
	while(1)
	{
		//
		// Log before entering sleep
		//
		log_printf("cpu suspends  cnt = %d before wfi....\r\n", cnt);
		
		//
		// Choose sleep mode based on count
		//
		if (cnt >= 3)
		{
			log_printf("go to deepsleep\r\n");
			__set_wfi_sleepmode(WFI_DEEP_SLEEP);
		}
		else
		{
			log_printf("go to sleep\r\n");
			__set_wfi_sleepmode(WFI_SHALLOW_SLEEP);
		}
		
		//
		// Enter wait-for-interrupt state
		//
		__WFI();
		
		//
		// Increment counter and log after wake-up
		//
		cnt++;
		log_printf("cpu suspends  cnt = %d after wfi....\r\n", cnt);
	}

}
