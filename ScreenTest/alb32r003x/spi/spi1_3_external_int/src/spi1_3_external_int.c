/**
 *************************************************************************************
 * @file spi1_3_external_int.c
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
#include "alb32r003x_screenTest.h"


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
volatile int spi_test_result = 0;   //!< 1=pass, -1=fail
volatile uint32_t spi_group_count = 0; //!< received group counter

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

    while (spi_test_result == 0)
    {
    }

    return (spi_test_result > 0) ? SC_PASS : SC_FAIL;
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
    status = SPI_getInterruptStatus(SPI1_BASE);

    //
    // Read received data from SPI module
    //
    for(i = 0; i < 16; i++)
    {
        rData[i] = SPI_readDataNonBlocking(SPI1_BASE);
    }

    spi_group_count++;
    if (spi_test_result == 0)
    {
        //
        // Print sent and received data for this group
        //
        printf("SPI1 communicate with SPI3 group %u: sent=", (unsigned int)spi_group_count);
        for (i = 0; i < 16; i++) printf("%02X ", (unsigned int)sData[i]);
        printf(" recv=");
        for (i = 0; i < 16; i++) printf("%02X ", (unsigned int)rData[i]);
        printf("\r\n");
        //
        // Verify received data matches expected pattern
        //
        for (i = 0; i < 16; i++)
        {
            if (rData[i] != sData[i])
            {
                spi_test_result = -1;
                break;
            }
        }
        if (spi_test_result == -1)
        {
            printf("SPI1 communicate with SPI3 FAIL: data mismatch at group %u\r\n", (unsigned int)spi_group_count);
            Interrupt_disable(SPI1RX_IRQn);
        }
        else if (spi_group_count >= 64)
        {
            spi_test_result = 1;
            printf("SPI1 communicate with SPI3 PASS: 64 groups verified\r\n");
            Interrupt_disable(SPI1RX_IRQn);
        }
        else
        {
            // Trigger the next transaction
            Interrupt_enable(SPI3TX_IRQn);
        }
    }
    delay_ms(50);
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
    status = SPI_getInterruptStatus(SPI3_BASE);

    //
    // Send data to SPI module
    //
    for(i = 0; i < 16; i++)
    {
       SPI_writeDataNonBlocking(SPI3_BASE, sData[i]);
    }

    Interrupt_disable(SPI3TX_IRQn);

    //
    // TX FIFO Threshold Level interrupt is cleared by hardware
    // 
}

