/**
 *************************************************************************************
 * @file spi4_loopback_int_board.c
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

#include "spi4_loopback_int_board.h"

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
    SPIX_init();
    
    //
    // Initialize interrupts for SPI
    //
    INTERRUPT_init();
}

//*****************************************************************************
//
// Initializes GPIO Pin Muxing
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    // Configure SPI0 STE (Slave Transmit Enable) pin
    //
    GPIO_setPinConfig(mySPI0_SPISTE_PIN_CONFIG);
    
    //
    // Configure SPI0 CLK (Clock) pin
    //
    GPIO_setPinConfig(mySPI0_SPICLK_PIN_CONFIG);
    
    //
    // Configure SPI0 SIMO (Master Out Slave In) pin
    //
    GPIO_setPinConfig(mySPI0_SPISIMO_PIN_CONFIG);
    
    //
    // Configure SPI0 SOMI (Slave Out Master In) pin
    //
    GPIO_setPinConfig(mySPI0_SPISOMI_PIN_CONFIG);
}

//*****************************************************************************
//
// Initializes SPI Interrupts
//
//*****************************************************************************
extern void spiTxFIFOISR(void);
extern void spiRxFIFOISR(void);

void INTERRUPT_init(void)
{
    //
    // Register and configure SPI RX FIFO interrupt
    //
    Interrupt_register(SPI1RX_IRQn, spiRxFIFOISR);
    Interrupt_setPriority(SPI1RX_IRQn, 0, 0);
    Interrupt_enable(SPI1RX_IRQn);
    ECLIC_EnableIRQ(SPI1RX_IRQn);

    //
    // Register and configure SPI TX FIFO interrupt
    //
    Interrupt_register(SPI1TX_IRQn, spiTxFIFOISR);
    Interrupt_setPriority(SPI1TX_IRQn, 0, 0);
    Interrupt_enable(SPI1TX_IRQn);
    ECLIC_EnableIRQ(SPI1TX_IRQn);
}

//*****************************************************************************
//
// Initializes SPI Modules
//
//*****************************************************************************
void SPIX_init(void)
{
    //
    // Initialize SPI module
    //
    mySPI_init();
}

//*****************************************************************************
//
// Initializes SPI Module for Loopback Test with FIFO Interrupts
//
//*****************************************************************************
void mySPI_init(void)
{
    //
    // Disable the SPI module before configuration
    //
    SPI_disableModule(mySPI_BASE);

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
    // Disable all SPI interrupts before configuration
    //
    SPI_disableAllInterrupt(mySPI_BASE);

    //
    // Set FIFO interrupt levels
    // - TX interrupt when 2 or fewer words in FIFO
    // - RX interrupt when 2 or more words in FIFO
    //
    SPI_setFIFOInterruptLevel(mySPI_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);

    //
    // Clear all interrupt status flags
    //
    SPI_clearInterruptStatus(mySPI_BASE, SPI_INT_RXFF | SPI_INT_TXFF);

    //
    // Enable FIFO interrupts
    //
    SPI_enableInterrupt(mySPI_BASE, SPI_INT_RXFF | SPI_INT_TXFF);

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

