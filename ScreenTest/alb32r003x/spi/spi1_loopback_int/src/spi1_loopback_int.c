/**
 *************************************************************************************
 * @file spi1_loopback_int.c
 * @brief This file contains the source file.
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
//#############################################################################
//
// FILE:   spi_ex2_loopback_fifo_interrupt.c
//
// TITLE:  SPI Digital Loopback with FIFO Interrupts
//
//! \addtogroup driver_example_list
//! <h1>SPI Digital Loopback with FIFO Interrupts</h1>
//!
//! This program uses the internal loopback test mode of the SPI module. Both
//! the SPI FIFOs and their interrupts are used.
//!
//! A stream of data is sent and then compared to the received stream.
//! The sent data looks like this: \n
//!  0000 0001 \n
//!  0001 0002 \n
//!  0002 0003 \n
//!  .... \n
//!  FFFE FFFF \n
//!  FFFF 0000 \n
//!  etc.. \n
//! This pattern is repeated forever.
//!
//! \b External \b Connections \n
//!  - None
//!
//! \b Watch \b Variables \n
//!  - \b sData - Data to send
//!  - \b rData - Received data
//!  - \b rDataPoint - Used to keep track of the last position in the receive
//!    stream for error checking
//!
//

#include "spi1_loopback_int_board.h"
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"
//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint16_t sData[2];                  //!< Data buffer to send over SPI
uint16_t rData[2];                  //!< Buffer to store received SPI data
uint16_t rDataPoint = 0;            //!< Tracks position in data stream for error checking
volatile int spi_test_result = 0;   //!< 1=pass, -1=fail



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
    // Disable interrupts before initialization
    //
    CPU_disableIrq();

    //
    // Initialize board hardware and SPI configuration
    //
    Board_init();

    //
    // Initialize the data buffers
    //
    for(i = 0; i < 2; i++)
    {
        sData[i] = i;          // Initialize send buffer with incrementing values
        rData[i] = 0;          // Clear receive buffer
    }

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
// SPI TX FIFO Interrupt Service Routine
//
//*****************************************************************************
__INTERRUPT void spiTxFIFOISR(void)
{
    uint16_t i;              //!< Loop counter
    uint16_t status;         //!< SPI interrupt status
    
    //
    // Get SPI interrupt status
    //
    status = SPI_getInterruptStatus(mySPI_BASE);
    
    //
    // Check if TX FIFO interrupt occurred
    //
    if((status & SPI_INT_TXFF))
    {
        //
        // Send data to SPI module
        //
        for(i = 0; i < 2; i++)
        {
           SPI_writeDataNonBlocking(SPI1_BASE, sData[i]);
        }

        //
        // Increment data values for next transmission cycle
        //
        for(i = 0; i < 2; i++)
        {
           sData[i] = sData[i] + 1;
        }

        //
        // Clear TX FIFO interrupt flag
        //
        SPI_clearInterruptStatus(SPI1_BASE, SPI_INT_TXFF);
    }
}

//*****************************************************************************
//
// SPI RX FIFO Interrupt Service Routine
//
//*****************************************************************************
__INTERRUPT void spiRxFIFOISR(void)
{
    uint16_t i;              //!< Loop counter
    uint16_t status;         //!< SPI interrupt status
    
    //
    // Get SPI interrupt status
    //
    status = SPI_getInterruptStatus(mySPI_BASE);
    
    //
    // Check if RX FIFO interrupt occurred
    //
    if ((status & SPI_INT_RXFF))
    {
        //
        // Read received data from SPI module
        //
        for(i = 0; i < 2; i++)
        {
            rData[i] = SPI_readDataNonBlocking(SPI1_BASE);
        }

        //
        // Verify received data matches expected pattern
        //
        for(i = 0; i < 2; i++)
        {
            if(rData[i] != (uint16_t)(rDataPoint + i))
            {
                spi_test_result = -1;
                break;
            }
            spi_test_result = 1;
        }
        if (spi_test_result == 1)
        {
            printf("SPI transmit and receive successfully!\r\n");
        }
        else
        {
            printf("SPI loopback FAIL: data mismatch\r\n");
        }

        //
        // Update data position counter
        //
        rDataPoint++;

        //
        // Clear RX FIFO interrupt flag
        //
        SPI_clearInterruptStatus(SPI1_BASE, SPI_INT_RXFF);
    }
}
