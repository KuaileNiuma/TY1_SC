/**
 *************************************************************************************
 * @file spi_ex01_loopback.c
 * @brief This file contains the source file for example spi_ex01_loopback.
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

#include "spi3_loopback_dma_board.h"
#include <string.h>
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"


//*****************************************************************************
//
// Macros & Typedefs
//
//*****************************************************************************
#define TEST_DATA_COUNT		64                          //!< Data length for UART transmission

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint8_t readBuffer[TEST_DATA_COUNT] = {0};    //!< Buffer to store data read from FLASH
uint8_t writeBuffer[TEST_DATA_COUNT] = {0};   //!< Buffer to store data to write to FLASH


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
static void spi_send_data_init(void)
{
    int i;
    for (i = 0; i < TEST_DATA_COUNT; i++)
    {
    	writeBuffer[i] = i + 1;
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
static void spi_tx_dma_init(void)
{
    DMA_ConfigParams dmaCfg;
    DMA_configParameter(&dmaCfg);
    //
    // Channel-level reset (module enable done once in main)
    //
    DMA_stopChannel(DMA1_CH1_BASE);
    DMA_DeConfChannel(DMA1_CH1_BASE);
    DMA_disableInterrupt(DMA1_CH1_BASE);
    //
    // Set up DMA transfer parameters
    //
    dmaCfg.enableInterrupt = 0;
    dmaCfg.blockTS = 16;
    dmaCfg.ttfc = DMA_TT_FC_1_M2P_DMAC;
    dmaCfg.dmaDstReqId = DMAMUX_ReqId_dma_SPI3_TX;
    dmaCfg.srcAddr = (uint32_t) writeBuffer;
    dmaCfg.destAddr = (uint32_t)(mySPI_BASE + SPI_O_DATAREG);
    dmaCfg.srcBtl = DMA_BTL_8;
    dmaCfg.destBtl = DMA_BTL_8;
    dmaCfg.srcAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.destAddrDirect = DMA_ADDR_NO_CHANGE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_4;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_4;
    dmaCfg.chPriority=DMA_CH_PRIORITY_0;
    //
    // Apply DMA channel configuration and start
    //
    DMA_configChannel(DMA1_CH1_BASE, &dmaCfg);
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
static void spi_rx_dma_init(void)
{
    DMA_ConfigParams dmaCfg;
    DMA_configParameter(&dmaCfg);
    //
    // Channel-level reset (module enable done once in main)
    //
    DMA_stopChannel(DMA1_CH2_BASE);
    DMA_DeConfChannel(DMA1_CH2_BASE);
    DMA_disableInterrupt(DMA1_CH2_BASE);
    //
    // Set up DMA transfer parameters
    //
    dmaCfg.enableInterrupt = 0;
    dmaCfg.blockTS = 16;
    dmaCfg.ttfc = DMA_TT_FC_2_P2M_DMAC;
    dmaCfg.dmaSrcReqId = DMAMUX_ReqId_dma_SPI3_RX;
    dmaCfg.srcAddr = (uint32_t)(mySPI_BASE + SPI_O_DATAREG);
    dmaCfg.destAddr = (uint32_t)readBuffer;
    dmaCfg.srcBtl = DMA_BTL_8;
    dmaCfg.destBtl = DMA_BTL_8;
    dmaCfg.srcAddrDirect = DMA_ADDR_NO_CHANGE;
    dmaCfg.destAddrDirect = DMA_ADDR_INCRE;
    dmaCfg.srcTrWidthBytes = DMA_TR_WIDTH_BYTE_4;
    dmaCfg.destTrWidthBytes = DMA_TR_WIDTH_BYTE_4;
    dmaCfg.chPriority=DMA_CH_PRIORITY_1;
    //
    // Apply DMA channel configuration and start
    //
    DMA_configChannel(DMA1_CH2_BASE, &dmaCfg);
    DMA_startChannel(DMA1_CH2_BASE);
}



//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
	DMAC_CH_TypeDef  *tmp1;
	SPI_TypeDef  *tmp2;
	uint32_t dma_timeout;
	int i;
	alb32r003x_evb_init();
	spi_send_data_init();

	//
	// Initialize board hardware and SPI configuration
	//
    Board_init();

    //
    // Disable interrupts before initialization
    //
    CPU_disableIrq();


	 //
	 // Configure DMA for UART transmission and reception
	 //

	 // Enable DMA1 controller once (avoid module-level disable in
	 // spi_tx/rx_dma_init overwriting each other)
	 SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA1);
	 SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMASCH);
	 DMA_enableModule(DMA1_CH1_BASE);

	 spi_tx_dma_init();
	 dma_timeout = 0xFFFFFF;
	 while(((DMA_getRawInterruptStatus(DMA1_CH1_BASE) & DMA_INT_TFR) == 0) && dma_timeout--);
	 if (dma_timeout == 0) { printf("SPI3 DMA loopback FAIL: tx timeout\r\n"); return SC_FAIL; }
	 dma_timeout = 0xFFFFFF;
	 spi_rx_dma_init();
	 while(((DMA_getRawInterruptStatus(DMA1_CH2_BASE) & DMA_INT_TFR) == 0) && dma_timeout--);
	 if (dma_timeout == 0) { printf("SPI3 DMA loopback FAIL: rx timeout\r\n"); return SC_FAIL; }



     //
     // Print sent and received data (64 groups)
     //
     printf("SPI3 DMA loopback: sent=");
     for (i = 0; i < TEST_DATA_COUNT; i++) printf("%02X ", (unsigned int)writeBuffer[i]);
     printf(" recv=");
     for (i = 0; i < TEST_DATA_COUNT; i++) printf("%02X ", (unsigned int)readBuffer[i]);
     printf("\r\n");
     //
     // Verify received data
     //
     if (memcmp(readBuffer, writeBuffer, TEST_DATA_COUNT) != 0)
     {
         printf("SPI3 DMA loopback FAIL: data mismatch\r\n");
         return SC_FAIL;
     }
     printf("SPI3 DMA loopback PASS: 64 groups verified\r\n");
     return SC_PASS;
}

