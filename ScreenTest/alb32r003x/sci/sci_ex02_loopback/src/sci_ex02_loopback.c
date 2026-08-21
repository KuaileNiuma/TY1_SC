/**
 *************************************************************************************
 * @file sci_ex02_loopback.c
 * @brief This file contains the source file for example sci_ex02_loopback.
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
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define SEND_DATA_LEN   10          //!< Length of data buffer for send/receive

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
static uint32_t g_SCI_base = SCI2_BASE;  //!< SCI base address
uint8_t send_data[SEND_DATA_LEN];         //!< Data buffer for transmission
uint8_t rcv_data[SEND_DATA_LEN];          //!< Data buffer for reception
#define myADC0_CLK_EN SYSCTL_PERIPH_CLK_UART2
//*****************************************************************************
//
// SCI Loopback Verification Function
// 
//*****************************************************************************
int SCI_pc_verify(uint32_t SCI_base)
{
    uint32_t i = 0;
    //
    // Update global SCI base address
    //
    g_SCI_base = SCI_base;
    //
    // Wait for the Transmitter Shift Register to be empty
    //
    while(SCI_isSpaceAvailableNonFIFO(SCI_base) == 0);
    //
    // Initialize send data buffer with incrementing values
    //
    for (i = 0; i < SEND_DATA_LEN; i++)
    {
        send_data[i] = i + 1;
    }
    //
    // Enable loopback mode for testing
    //
    SCI_enableLoopback(SCI_base);
    //
    // Transmit data through FIFO
    //
    for (i = 0; i < SEND_DATA_LEN; i++)
    {
        SCI_writeCharBlockingFIFO(SCI_base, send_data[i]);
    }
    //

    // Receive data through FIFO
    //
    for (i = 0; i < SEND_DATA_LEN; i++)
    {
        rcv_data[i] = SCI_readCharBlockingFIFO(SCI_base);
    }
    //
    // Disable loopback mode
    //
    SCI_disableLoopback(SCI_base);
    //
    // Compare transmitted and received data
    //
    for (i = 0; i < SEND_DATA_LEN; i++)
    {
        if (send_data[i] != rcv_data[i])
        {
            printf("SCIBASE=0x%08x loopback test fail send_data %d rcv_data %d \r\n", SCI_base, send_data[i], rcv_data[i]);
            return SC_FAIL;
        }
    }
    printf("SCIBASE=0x%08X loopback test OK \r\n", SCI_base);
    return SC_PASS;
}

//*****************************************************************************
//
// UART Initialization Function
// 
//*****************************************************************************
void UART_init(uint32_t SCIBase, uint32_t clk, uint32_t baud)
{

	SysCtl_enablePeripheral(myADC0_CLK_EN);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
	GPIO_setPinConfig(GPIO_10_SCIB_TX);
	GPIO_setPinConfig(GPIO_11_SCIB_RX);
    //
    // Set SCI baud rate
    //
    SCI_setBaud(SCIBase, clk, baud);
    //
    // Configure SCI settings: no parity, 1 stop bit, 8-bit characters
    //
    SCI_setInitConfig(SCIBase, SCI_CONFIG_PAR_NONE, SCI_STOP_1BIT, SCI_CHAR_8BITS);
    //
    // Enable FIFO for more efficient data handling
    //
    SCI_enableFIFO(SCIBase);
    //
    // Set FIFO interrupt levels
    //
    SCI_setFIFOInterruptLevel(SCIBase, SCI_FIFO_TX0, SCI_FIFO_RX1);
}


//*****************************************************************************
//
// Main function
//
//*****************************************************************************
int main(void)
{
	int ret=0;

    alb32r003x_evb_init();
    //
    // Initialize interrupt as CLINT interrupt mode, see MTVEC register description
    //
    //
    // Print test start message
    //
    printf("SCI_ex02_loopback start \r\n");
    
    //
    // Initialize UART with 20MHz clock and 115200 baud rate
    //
    UART_init(g_SCI_base, SystemClock_Get_APBL(), 115200);
    
    //
    // Perform loopback verification test
    //
    ret = SCI_pc_verify(g_SCI_base);

    //
    // Print test end message
    //
    printf("SCI_ex02_loopback end \r\n");

    return (ret == SC_PASS) ? SC_PASS : SC_FAIL;
}
