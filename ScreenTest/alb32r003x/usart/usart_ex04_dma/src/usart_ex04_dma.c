/**
 *************************************************************************************
 * @file lin_ex05_tx_dma.c
 * @brief This file contains the source file for example lin_ex05_tx_dma.
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
#include "alb32r003x_screenTest.h"
//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define my_usartBase         	USART1_BASE
#define USART_TX_PIN			GPIO_22_USARTA_TX
#define USART_RX_PIN			GPIO_23_USARTA_RX
#define my_USART_CLK_EN       	SYSCTL_PERIPH_CLK_USART1
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
// usart_send_data_init - Initialize the USART transmit buffer
//
//  This function initializes the send_data buffer with incrementing values
//  from 1 to SEND_DATA_LEN.
//
//*****************************************************************************
static void usart_send_data_init(void)
{
    int i;
    for (i = 0; i < SEND_DATA_LEN; i++)
    {
        send_data[i] = i + 1;
    }
}

//*****************************************************************************
//
// usart_tx_dma_init - Initialize DMA for USART transmission
// 
//  This function configures the DMA channel for transferring data from
//  send_data buffer to USART2 TX register using USART2_TX as trigger.
//
//*****************************************************************************
static void usart_tx_dma_init(void)
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
    dmaCfg.dmaDstReqId = DMAMUX_ReqId_dma_USART1_TX;
    dmaCfg.srcAddr = (uint32_t) send_data;
    dmaCfg.destAddr = (uint32_t)(USART1_BASE + USART_O_DR);
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
// usart_rx_dma_init - Initialize DMA for USART reception
//
//  This function configures the DMA channel for transferring data from
//  USART2 RX register to send_data buffer using USART2_RX as trigger.
//
//*****************************************************************************
static void usart_rx_dma_init(void)
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
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_USART1_RX;
    dmaCfg.srcAddr = (uint32_t)(USART1_BASE + USART_O_DR);
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
// USART Initialization Function
// 
//*****************************************************************************
void usart_init(uint32_t Base, uint32_t baud)
{
	//
	// Configure USART structure for USART communication
	//
	USART_InitTypeDef USART_InitStruct = {0};
	//
	// Set communication parameters
	//
	USART_InitStruct.USART_BaudRate = baud;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;

	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    //
    //Turn on the USART1 peripheral clock	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    //
    SysCtl_enablePeripheral(my_USART_CLK_EN);
	//
	// Initialize and enable USART interface
	//
	USART_Init(Base,SystemClock_Get_APBL(), &USART_InitStruct);
	USART_DMACmd(Base, USART_DMAReq_Tx | USART_DMAReq_Rx,ENABLE);
	USART_Cmd(Base, ENABLE);
}

//*****************************************************************************
//
// USART TX DMA Example Initialization Function
// 
//*****************************************************************************
void usart_ex04_dma(void)
{
    //
    // Configure GPIO pins for USART communication
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    GPIO_setPinConfig(USART_TX_PIN);
    GPIO_setPinConfig(USART_RX_PIN);
    //
    // Initialize USART interface with 9600 baud rate
    //
    usart_init(my_usartBase, 9600);
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
}

//*****************************************************************************
//
// Main Function
// 
//*****************************************************************************
int main(void)
{
    uint32_t returnCode;  //!< Return code variable

    alb32r003x_evb_init();

    usart_send_data_init();

    //
    // Initialize USART TX DMA example
    //
    usart_ex04_dma();

    usart_tx_dma_init();
    while((DMA_getRawInterruptStatus(DMA1_CH1_BASE) & DMA_INT_TFR) == 0);
    usart_rx_dma_init();
    while((DMA_getRawInterruptStatus(DMA1_CH2_BASE) & DMA_INT_TFR) == 0);
    //
    // Main loop - application remains here
    //
    while(1)
    {
        //
        // Application can add additional tasks here
        //
    }
}
