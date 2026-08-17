/**
 *************************************************************************************
 * @file sci_ex06_dma.c
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
// Macros & Typedefs
//
//*****************************************************************************
#define SEND_DATA_LEN   128                           //!< Data length for UART transmission

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint8_t send_data[SEND_DATA_LEN];                      //!< Transmit buffer for UART data
uint8_t rcv_data[SEND_DATA_LEN];                       //!< Receive buffer for UART data

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static void uart_send_data_init(void);
static void uart_tx_dma_init(void);
static void uart_rx_dma_init(void);
static void UART_init(uint32_t SCIBase, uint32_t clk, uint32_t baud);
static void sci_ex06_dma(void);

//*****************************************************************************
//
// Function Definitions
//
//*****************************************************************************
//
// uart_send_data_init - Initialize the UART transmit buffer
//
//  This function initializes the send_data buffer with incrementing values
//  from 1 to SEND_DATA_LEN.
//
//*****************************************************************************
static void uart_send_data_init(void)
{
    int i;
    for (i = 0; i < SEND_DATA_LEN; i++)
    {
        send_data[i] = i + 1;
    }
}

//*****************************************************************************
//
// uart_tx_dma_init - Initialize DMA for UART transmission
//
//  This function configures the DMA channel for transferring data from
//  send_data buffer to UART2 TX register using UART2_TX as trigger.
//
//*****************************************************************************
static void uart_tx_dma_init(void)
{
    DMA_ConfigParams dmaCfg;
    DMA_configParameter(&dmaCfg);
    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMASCH);
    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    DMA_disableModule(DMA1_CH1_BASE);
    DMA_stopChannel(DMA1_CH1_BASE);
    DMA_DeConfChannel(DMA1_CH1_BASE);
    DMA_disableInterrupt(DMA1_CH1_BASE);
    //
    // Set up DMA transfer parameters
    //
    dmaCfg.enableInterrupt = 0;
    dmaCfg.blockTS = 128;
    dmaCfg.ttfc = DMA_TT_FC_1_M2P_DMAC;
    dmaCfg.dmaDstReqId = DMAMUX_ReqId_dma_UART2_TX;
    dmaCfg.srcAddr = (uint32_t) send_data;
    dmaCfg.destAddr = (uint32_t)(SCI2_BASE + SCI_O_RBR_THR_DLL);
    dmaCfg.srcBtl = DMA_BTL_1;
    dmaCfg.destBtl = DMA_BTL_1;
    dmaCfg.srcAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.destAddrDirect = DMA_ADDR_NO_CHANGE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_1;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_1;
    dmaCfg.chPriority=DMA_CH_PRIORITY_0;
    //
    // Apply DMA channel configuration and start
    //
    DMA_configChannel(DMA1_CH1_BASE, &dmaCfg);
	DMA_enableModule(DMA1_CH1_BASE);
    DMA_startChannel(DMA1_CH1_BASE);
}

//*****************************************************************************
//
// uart_rx_dma_init - Initialize DMA for UART reception
//
//  This function configures the DMA channel for transferring data from
//  UART2 RX register to send_data buffer using UART2_RX as trigger.
//
//*****************************************************************************
static void uart_rx_dma_init(void)
{
    DMA_ConfigParams dmaCfg;
    DMA_configParameter(&dmaCfg);
    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMASCH);
    //
    //Turn on the DMA1 & DMASCH peripheral clock
    //
    DMA_disableModule(DMA1_CH2_BASE);
    DMA_stopChannel(DMA1_CH2_BASE);
    DMA_DeConfChannel(DMA1_CH2_BASE);
    DMA_disableInterrupt(DMA1_CH2_BASE);
    //
    // Set up DMA transfer parameters
    //
    dmaCfg.enableInterrupt = 0;
    dmaCfg.blockTS = 128;
    dmaCfg.ttfc = DMA_TT_FC_2_P2M_DMAC;
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_UART2_RX;
    dmaCfg.srcAddr = (uint32_t)(SCI2_BASE + SCI_O_RBR_THR_DLL);
    dmaCfg.destAddr = (uint32_t)rcv_data;
    dmaCfg.srcBtl = DMA_BTL_1;
    dmaCfg.destBtl = DMA_BTL_1;
    dmaCfg.srcAddrDirect = DMA_ADDR_NO_CHANGE;
    dmaCfg.destAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_1;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_1;
    dmaCfg.chPriority=DMA_CH_PRIORITY_1;
    //
    // Apply DMA channel configuration and start
    //
    DMA_configChannel(DMA1_CH2_BASE, &dmaCfg);
	DMA_enableModule(DMA1_CH2_BASE);
    DMA_startChannel(DMA1_CH2_BASE);
}

//*****************************************************************************
//
// UART_init - Initialize UART module with specified parameters
//
//  This function configures the UART module with specified base address,
//  clock frequency, and baud rate, along with FIFO settings.
//
//*****************************************************************************
static void UART_init(uint32_t SCIBase, uint32_t clk, uint32_t baud)
{

	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_UART2);

    SCI_setBaud(SCIBase, clk, baud);
    SCI_setInitConfig(SCIBase, SCI_CONFIG_PAR_NONE, SCI_STOP_1BIT,
            SCI_CHAR_8BITS);
    SCI_setDmaMode(SCIBase, DMAM_1);
    SCI_enableFIFO(SCIBase);
    SCI_setFIFOInterruptLevel(SCIBase, SCI_FIFO_TX0, SCI_FIFO_RX1);
}

//*****************************************************************************
//
// sci_ex06_dma - Initialize SCI for DMA example
//
//  This function sets up the GPIO pins for UART communication,
//  initializes the UART module, and enables interrupts.
//
//*****************************************************************************
static void sci_ex06_dma(void)
{
    printf("sci_ex06_dma start \r\n");
    GPIO_setPinConfig(GPIO_10_SCIB_TX);
    GPIO_setPinConfig(GPIO_11_SCIB_RX);
    UART_init(SCI2_BASE, SystemClock_Get_APBL(), 9600);

    CPU_enableIrq();

    printf("sci_ex06_dma end \r\n");
}

//*****************************************************************************
//
// main - Main application entry point
//
//  This function initializes the UART data buffer, configures the UART module
//  with DMA for both transmission and reception, and enters an infinite loop.
//
//*****************************************************************************
void main(void)
{
    alb32r003x_evb_init();
    //
    // Initialize UART data buffer with test data
    //
    uart_send_data_init();
    //
    // Initialize interrupt as CLINT interrupt mode, see MTVEC register description
    //
    sci_ex06_dma();
    //
    // Configure DMA for UART transmission and reception
    //
    uart_tx_dma_init();
    while((DMA_getRawInterruptStatus(DMA1_CH1_BASE) & DMA_INT_TFR) == 0);
    uart_rx_dma_init();
    while((DMA_getRawInterruptStatus(DMA1_CH2_BASE) & DMA_INT_TFR) == 0);
    //
    // Infinite loop
    //
    while (1)
    {
    }
}

