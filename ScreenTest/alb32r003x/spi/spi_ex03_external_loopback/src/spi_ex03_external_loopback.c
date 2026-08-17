/**
 *************************************************************************************
 * @file spi_ex03_external_loopback.c
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

#include "spi_ex03_external_loopback_board.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
	alb32r003x_evb_init();
	uint16_t i;              //!< Loop counter

    volatile uint16_t TxData_SPIA[] = {0xFF, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F}; //!< Data send from SPIA (peripheral)
    volatile uint16_t RxData_SPIA[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; //!< Data received by SPIA (peripheral)
    volatile uint16_t TxData_SPIB[] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F}; //!< Data send from SPIB (controller)
    volatile uint16_t RxData_SPIB[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; //!< Data received by SPIB (controller)



    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Initialize board hardware
    //
    Board_init();


    //
    // Loop through data buffers to perform SPI communication
    //
    for(i = 0; i < 16; i++)
    {
    	//
    	// Set the TX buffer of peripheral SPI (SPIA)
    	//
        SPI_writeDataNonBlocking(SPI1_BASE, TxData_SPIA[i]);

        //
        // Set the controller TX buffer (SPIB). This triggers the data transmission
        //
        SPI_writeDataNonBlocking(SPI2_BASE, TxData_SPIB[i]);
        
        //
        // Read the received data from both SPI modules
        //
        RxData_SPIA[i] = SPI_readDataBlockingFIFO(SPI1_BASE);
        RxData_SPIB[i] = SPI_readDataBlockingFIFO(SPI2_BASE);

        //
        // Check if received data matches expected data
        //
        if(RxData_SPIA[i] != TxData_SPIB[i])
        {
        	// Data mismatch detected - halt execution for debugging
        	printf("SPI1 communicate with SPI2 failed!\r\n");
        	__EBREAK();
        }
        if(RxData_SPIB[i] != TxData_SPIA[i])
        {
        	// Data mismatch detected - halt execution for debugging
        	printf("SPI1 communicate with SPI2 failed!\r\n");
        	__EBREAK();
        }
    }

    //
    // Loop forever once communication is complete
    printf("SPI1 communicate with SPI2 successfully!\r\n");
    //
    while(1);

    return 0;
}



