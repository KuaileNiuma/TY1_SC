/**
 *************************************************************************************
 * @file sci_ex05_polling.c
 * @brief This file contains the source file for example sci_ex05_polling.
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
uint8_t data;                 //!< Data to be sent through UART\ nuint8_t rcv_data;                  //!< Data received from UART

//*****************************************************************************
//
// UART Initialization Function
//
//*****************************************************************************
void UART_init(uint32_t SCIBase, uint32_t clk, uint32_t baud)
{

    //
    //Turn on the UART2 peripheral clock
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_UART2);
    //
    // Set the baud rate for the SCI module
    //
    SCI_setBaud(SCIBase, clk, baud);
    // 
    // Configure SCI settings: no parity, 1 stop bit, 8-bit characters 
    //
    SCI_setInitConfig(SCIBase, SCI_CONFIG_PAR_NONE, SCI_STOP_1BIT, SCI_CHAR_8BITS);
    
    // 
    // Enable FIFO mode for SCI 
    //
    SCI_enableFIFO(SCIBase);
    // 
    // Set FIFO interrupt levels: TX at 0, RX at 1 
    //
    SCI_setFIFOInterruptLevel(SCIBase, SCI_FIFO_TX0, SCI_FIFO_RX1);
}
//*****************************************************************************
//
// SCI Polling Test Function
//
//*****************************************************************************
void sci_ex05_polling(void)
{
    // 
    // Print start message 
    //
    printf("SCI_ex05_polling start \r\n");
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
    // Print end message 
    //
    printf("SCI_ex05_polling end \r\n");
}

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();

    // 
    // Initialize interrupt as CLINT interrupt mode, see MTVEC register description 
    //
    sci_ex05_polling();

    // 
    // Infinite loop for polling-based UART communication 
    //
    while(1)
    {
        // 
        // Wait until receive data is available (polling method) 
        //
        while ((SCI_getRxStatus(SCI2_BASE) & (0x1)) == 0);
        // 
        // Read received data in non-FIFO mode 
        //
        data = SCI_readCharBlockingNonFIFO(SCI2_BASE);
        // 
        // Write data in non-FIFO mode 
        //
        SCI_writeCharBlockingNonFIFO(SCI2_BASE, data);
    }
}
