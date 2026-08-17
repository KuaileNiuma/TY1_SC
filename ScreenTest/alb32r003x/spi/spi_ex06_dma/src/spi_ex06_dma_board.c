/**
 *************************************************************************************
 * @file spi_ex01_loopback_board.c
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

#include "spi_ex06_dma_board.h"

//*****************************************************************************
//
// Board Configuration
//
//*****************************************************************************
void Board_init()
{
    //
    // Initialize GPIO pin muxing for SPI
    //
    PinMux_init();
    
    //
    // Initialize SPI module
    //
    SPI_init();
}

//*****************************************************************************
//
// Initializes GPIO Pin Muxing for SPI
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    // Configure SPI0 STE pin
    //
    GPIO_setPinConfig(mySPI0_SPISTE_PIN_CONFIG);
    
    //
    // Configure SPI0 CLK pin
    //
    GPIO_setPinConfig(mySPI0_SPICLK_PIN_CONFIG);
    
    //
    // Configure SPI0 SIMO pin
    //
    GPIO_setPinConfig(mySPI0_SPISIMO_PIN_CONFIG);
    
    //
    // Configure SPI0 SOMI pin
    //
    GPIO_setPinConfig(mySPI0_SPISOMI_PIN_CONFIG);
}

//*****************************************************************************
//
// Initializes SPI Modules
//
//*****************************************************************************
void SPI_init(void)
{
    //
    // Initialize SPI0 module
    //
    mySPI0_init();
}
//*****************************************************************************
//
// Initializes SPI0 Module for Loopback Test
//
//*****************************************************************************


void mySPI0_init()
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_BSPI1);

	//
    // Disable the SPI module before configuration
    //
    SPI_disableModule(SPI1_BASE);

    //
    // Configure SPI with specified parameters
    // - Clock frequency: DEVICE_APBCLK_FREQ
    // - Protocol: SPI_PROT_POL0PHA0 (Clock idle low, data captured on rising edge)
    // - Mode: Controller mode
    // - Bit rate: mySPI_BITRATE
    // - Data width: mySPI_DATAWIDTH
    //
    SPI_setConfig(mySPI_BASE, DEVICE_APBCLK_FREQ, SPI_PROT_POL0PHA0, \
                 SPI_MODE_CONTROLLER, mySPI_BITRATE, mySPI_DATAWIDTH);

    //
    // Disable all SPI interrupts
    //
    SPI_disableAllInterrupt(mySPI_BASE);

	SPI_setDmaTxDataLevel(mySPI_BASE, SPI_FIFO_TX8);
	SPI_setDmaRxDataLevel(mySPI_BASE, SPI_FIFO_RX8);
	SPI_enableTransmitDMA(mySPI_BASE);
	SPI_enableReceiveDMA(mySPI_BASE);

    //
    // Enable loopback mode for testing
    //
    SPI_enableLoopback(mySPI_BASE);

    //
    // Enable the SPI module after configuration
    //
    SPI_enableModule(mySPI_BASE);
}


#ifdef __cplusplus
}
#endif

