/**
 *************************************************************************************
 * @file sci_ex03_irq_enablefifo.c
 * @brief This file contains the source file for example sci_ex03_irq_enablefifo.
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

#include "alb32r003x_evb.h"
#include <stdio.h>
#include "device.h"

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
static uint32_t g_SCI_base = SCI2_BASE; //!< SCI base address
uint8_t rcv_data;                        //!< Received data buffer
char test_msg[32] = {0};                 //!< Test message buffer

//*****************************************************************************
//
// UART Interrupt Handler
// 
//*****************************************************************************
__INTERRUPT static void uartISR(void)
{
    //
    // Variable to store interrupt status
    //
    uint32_t uart_intStat;
    
    //
    // Initialize interrupt status variable
    //
    uart_intStat = 0;
    
    //
    // Get current SCI interrupt status
    //
    uart_intStat = SCI_getInterruptStatus(g_SCI_base);
    
    //
    // Check if receive data is available
    //
    if((uart_intStat & SCI_RX_DATA_AVAILABLE) == SCI_RX_DATA_AVAILABLE)
    {
        //
        // Read received character in non-FIFO mode
        //
        rcv_data = SCI_readCharBlockingNonFIFO(g_SCI_base);
    }
}

//*****************************************************************************
//
// UART Initialization Function
// 
//*****************************************************************************
void UART_init(uint32_t SCIBase, uint32_t clk, uint32_t baud)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_UART2);
    //
    // Set SCI baud rate
    //
    SCI_setBaud(SCIBase, clk, baud);
    
    //
    // Configure SCI settings: no parity, 1 stop bit, 8-bit characters
    //
    SCI_setInitConfig(SCIBase, SCI_CONFIG_PAR_NONE, SCI_STOP_1BIT, SCI_CHAR_8BITS);
    
    //
    // Enable receive data available interrupt
    //
    SCI_enableInterrupt(SCIBase, SCI_RX_DATA_AVAILABLE_INT);
    
    //
    // Enable FIFO mode for this example
    //
    SCI_enableFIFO(SCIBase);
    
    //
    // Set FIFO interrupt levels: TX when empty, RX when 1 character received
    //
    SCI_setFIFOInterruptLevel(SCIBase, SCI_FIFO_TX0, SCI_FIFO_RX1);
}

//*****************************************************************************
//
// SCI Receive Interrupt with FIFO Test Function
// 
//*****************************************************************************
void sci_ex03_rx_interrupt(void)
{

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_UART2);
    //
    // Print test start message
    //
    printf("SCI_ex03_rx_irq start \r\n");
    
    //
    // Configure GPIO pins for SCI communication
    //
    GPIO_setPinConfig(GPIO_10_SCIB_TX);
    GPIO_setPinConfig(GPIO_11_SCIB_RX);
    
    //
    // Initialize UART with 20MHz clock and 115200 baud rate
    //
    UART_init(SCI2_BASE, SystemClock_Get_APBL(), 9600);

    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Register UART interrupt handler
    //
    Interrupt_register(SCI2_IRQn , uartISR);
    
    //
    // Set interrupt priority
    //
    Interrupt_setPriority(SCI2_IRQn , 0, 0);
    
    //
    // Enable UART interrupt
    //
    Interrupt_enable(SCI2_IRQn );
    
    //
    // Enable ECLIC for UART interrupt
    //
    ECLIC_EnableIRQ(SCI2_IRQn );
    
    //
    // Print test end message
    //
    printf("SCI_ex03_rx_irq end \r\n");
}

//*****************************************************************************
//
// Main function
// 
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();

    //
    // Initialize interrupt as CLINT interrupt mode, see MTVEC register description
    //
    sci_ex03_rx_interrupt();

    //
    // Infinite loop to wait for interrupts
    //
    while(1)
    {
    }
}
