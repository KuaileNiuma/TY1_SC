/**
 *************************************************************************************
 * @file spi_ex01_loopback.c
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

#include "spi_ex01_loopback_board.h"
#include "alb32r003x_evb.h"
//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();

	volatile uint16_t sData = 0;                  //!< Data to send over SPI
    volatile uint16_t rData = 0;                  //!< Received data to verify

    //
    // Disable interrupts before initialization
    //
    CPU_disableIrq();

    //
    // Initialize board hardware and SPI configuration
    //
    Board_init();

    //
    // Main Loop
    //
    while(sData<16)
    {
        //
        // Write data to SPI module in non-blocking mode
        //
        SPI_writeDataNonBlocking(mySPI_BASE, sData);

        //
        // Wait for data to be received (blocking call)
        //
        rData = SPI_readDataBlockingFIFO(mySPI_BASE);

        //
        // Verify received data matches transmitted data
        //
        if(rData != sData)
        {
            //
            // Data mismatch detected - halt execution for debugging
            //

        	printf("SPI_Loopback test failed!\r\n");
        	__EBREAK();

        }

        //
        // Increment data for next transmission
        //
        sData++;
    }

    printf("SPI_Loopback test successful!\r\n");

    return 0;
}

