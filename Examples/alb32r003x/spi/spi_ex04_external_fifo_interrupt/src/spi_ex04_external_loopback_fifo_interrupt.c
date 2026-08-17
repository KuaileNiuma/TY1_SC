/**
 *************************************************************************************
 * @file spi_ex04_external_loopback_fifo_interrupt.c
 * @brief This file contains the source file for example spi_ex04_external_loopback_fifo_interrupt.
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

#include "board.h"
#include "alb32r003x_evb.h"


SPI_TypeDef spi;
//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void spiARxFIFOISR(void);           //!< SPIA Receive FIFO Interrupt Service Routine
void spiBTxFIFOISR(void);           //!< SPIB Transmit FIFO Interrupt Service Routine

//
// Initialize the data buffers
//
volatile uint16_t sData[]={0xFF, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
volatile uint16_t rData[]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();
	uint16_t i;                  //!< Loop counter

    //
    // Initialize the data buffers
    //


    //
    // Disable interrupts before initialization
    //
    CPU_disableIrq();

    //
    // Initialize board hardware and SPI configuration
    //
    Board_init();

    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Main loop - execution continues in interrupt handlers
    //

    while(1)
    {

    }

    return 0;
}

//*****************************************************************************
//
// SPIA Receive FIFO Interrupt Service Routine
//
//*****************************************************************************
__INTERRUPT void spiARxFIFOISR(void)
{
    uint16_t i;              //!< Loop counter
    uint16_t status;         //!< SPI interrupt status
    
    //
    // Get SPI interrupt status
    //
    status = SPI_getInterruptStatus(SPI3_BASE);

    //
    // Read received data from SPI module
    //
    for(i = 0; i < 16; i++)
    {
        rData[i] = SPI_readDataNonBlocking(SPI3_BASE);
    }

    //
    // Verify received data matches expected pattern
    //
    for(i = 0; i < 16; i++)
    {
        if(rData[i] != sData[i])
        {
            // Data mismatch detected - halt execution for debugging
        	printf("SPI1 communicate with SPI2 by interrupt successfully!\r\n");
        	delay_ms(50);
        	__EBREAK();
        }
    }

    printf("SPI1 communicate with SPI2 by interrupt successfully!\r\n");
    delay_ms(50);
    Interrupt_disable(SPI3RX_IRQn);
    //
    // Update data position counter
    //

    //
    // RX FIFO Threshold Level interrupt is cleared by hardware
    //
}

//*****************************************************************************
//
// SPIB Transmit FIFO Interrupt Service Routine
//
//*****************************************************************************
__INTERRUPT void spiBTxFIFOISR(void)
{
    uint16_t i;              //!< Loop counter
    uint16_t status;         //!< SPI interrupt status
    
    //
    // Get SPI interrupt status
    //
    status = SPI_getInterruptStatus(SPI2_BASE);

    //
    // Send data to SPI module
    //
    for(i = 0; i < 16; i++)
    {
       SPI_writeDataNonBlocking(SPI2_BASE, sData[i]);
    }

    Interrupt_disable(SPI2TX_IRQn);

    //
    // TX FIFO Threshold Level interrupt is cleared by hardware
    // 
}

