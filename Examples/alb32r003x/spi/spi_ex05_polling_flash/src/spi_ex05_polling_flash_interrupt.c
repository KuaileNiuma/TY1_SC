/**
 *************************************************************************************
 * @file spi_ex05_polling_flash_interrupt.c
 * @brief This file contains the source file for example spi_ex05_polling_flash_interrupt.
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
#include "spi.h"
#include "board.h"
#include "w25q64.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define TEST_DATA_COUNT		256          //!< Number of data bytes to transfer

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint8_t readBuffer[TEST_DATA_COUNT] = {0};    //!< Buffer to store data read from FLASH
uint8_t writeBuffer[TEST_DATA_COUNT] = {0};   //!< Buffer to store data to write to FLASH

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void spiRxFIFOISR(void);                      //!< SPI receive FIFO interrupt service routine

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();

	uint32_t i;               //!< Loop counter
	uint32_t jedec_id = 0;    //!< FLASH JEDEC ID

    //
    // Disable global interrupts
    //
    CPU_disableIrq();

    //
    // Initialize board hardware
    //
    Board_init();

    //
    // Set the CS to inactive (when GPIO08 as CS)
    //
    CS_HIGH;

    //
    // Initialize the send data buffers with sequential values
    //
    for (i = 0; i < TEST_DATA_COUNT; i++)
    {
    	writeBuffer[i] = i;
    }

    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Read the flash JEDEC ID to confirm connection
    //
	jedec_id = w25q64_read_jedec_id(mySPI_BASE);

	//
	// Erase 64KB sector
	//
	w25q64_erase(mySPI_BASE, 0, 0x10000);

	//
	// Write 256 bytes to FLASH
	//
    w25q64_write(mySPI_BASE, 0, TEST_DATA_COUNT, writeBuffer);

    //
    // Read a page of data from FLASH
    //
    w25q64_read(mySPI_BASE, 0, TEST_DATA_COUNT, readBuffer);

    //
    // Verify received data matches transmitted data
    //
    for (i = 0; i < TEST_DATA_COUNT; i++)
    {
        if (readBuffer[i] != writeBuffer[i])
        {
            // Data mismatch detected - halt execution for debugging
        	printf("FLASH communicate with SPI failed!\r\n");
        	__EBREAK();
        }
    }

	//
	// Infinite loop after successful operation
	//

    printf("FLASH communicate with SPI successfully!\r\n");
	for(;;);

    return 0;

}

//*****************************************************************************
//
// SPI Receive FIFO Interrupt Service Routine
//
//*****************************************************************************
void spiRxFIFOISR(void)
{
    uint32_t status;         //!< SPI interrupt status register

    //
    // Get SPI interrupt status flags
    //
    status = SPI_getInterruptStatus(mySPI_BASE);
    
    //
    // Check for FIFO error conditions
    //
    if((status & SPI_ISR_TXOIS) ||
       (status & SPI_ISR_RXUIS) ||
       (status & SPI_ISR_RXOIS))
    {
        //
        // Disable the error interrupts and halt for debugging
        //
    	SPI_disableInterrupt(mySPI_BASE, status);
    	__EBREAK();
    }

    //
    // Clear all interrupt status flags
    //
    SPI_clearAllInterruptStatus(mySPI_BASE);

}

