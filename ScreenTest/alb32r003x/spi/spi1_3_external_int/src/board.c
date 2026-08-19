/**
 *************************************************************************************
 * @file board.c
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

#include "board.h"

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
    // Initialize SPI modules
    //
	SPIX_init();
    
    //
    // Initialize interrupts for SPI
    //
	INTERRUPT_init();
}

//*****************************************************************************
//
// Initializes GPIO Pin Muxing for SPI
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    // SPIA_peripheral Pinmux configuration
    //
    // SPIA SIMO (Master Out Slave In) pin configuration
	GPIO_setPinConfig(SPIA_peripheral_SPISIMO_PIN_CONFIG);

    // SPIA SOMI (Slave Out Master In) pin configuration
	GPIO_setPinConfig(SPIA_peripheral_SPISOMI_PIN_CONFIG);

    // SPIA CLK (Clock) pin configuration
	GPIO_setPinConfig(SPIA_peripheral_SPICLK_PIN_CONFIG);

    // SPIA STE (Slave Transmit Enable) pin configuration
	GPIO_setPinConfig(SPIA_peripheral_SPISTE_PIN_CONFIG);

    //
    // SPIB_controller Pinmux configuration
    //
    // SPIB SIMO (Master Out Slave In) pin configuration
	GPIO_setPinConfig(SPIB_controller_SPISIMO_PIN_CONFIG);

    // SPIB SOMI (Slave Out Master In) pin configuration
	GPIO_setPinConfig(SPIB_controller_SPISOMI_PIN_CONFIG);

    // SPIB CLK (Clock) pin configuration
	GPIO_setPinConfig(SPIB_controller_SPICLK_PIN_CONFIG);

    // SPIB STE (Slave Transmit Enable) pin configuration
	GPIO_setPinConfig(SPIB_controller_SPISTE_PIN_CONFIG);
}

//*****************************************************************************
//
// Initializes SPI Interrupts
//
//*****************************************************************************
void INTERRUPT_init(void)
{
    //
    // Register and configure SPIB TX FIFO interrupt
    //
    Interrupt_register(SPI3TX_IRQn, spiBTxFIFOISR);
    Interrupt_setPriority(SPI3TX_IRQn, 0, 0);
    Interrupt_enable(SPI3TX_IRQn);
    ECLIC_EnableIRQ(SPI3TX_IRQn);

    //
    // Register and configure SPIA RX FIFO interrupt
    //
    Interrupt_register(SPI4RX_IRQn, spiARxFIFOISR);
    Interrupt_setPriority(SPI4RX_IRQn, 0, 0);
    Interrupt_enable(SPI4RX_IRQn);
    ECLIC_EnableIRQ(SPI4RX_IRQn);
}

//*****************************************************************************
//
// Initializes SPI Modules
//
//*****************************************************************************
void SPIX_init(void)
{
    //
    // Initialize SPIA as peripheral
    //
	SPIA_peripheral_init();
    
    //
    // Initialize SPIB as controller
    //
	SPIB_controller_init();
}


//*****************************************************************************
//
// Initializes SPIA Module as Peripheral with FIFO Interrupts
//
//*****************************************************************************
void SPIA_peripheral_init(void)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_BSPI4);

    //
    // Disable the SPI module before configuration
    //
	SPI_disableModule(SPIA_peripheral_BASE);

    //
    // Configure SPI with specified parameters
    // - Clock frequency: DEVICE_APBCLK_FREQ
    // - Protocol: SPI_PROT_POL0PHA0 (Clock idle low, data captured on rising edge)
    // - Mode: Peripheral mode
    // - Bit rate: SPIA_peripheral_BITRATE
    // - Data width: SPIA_peripheral_DATAWIDTH
    //
	SPI_setConfig(SPIA_peripheral_BASE,DEVICE_APBCLK_FREQ,SPI_PROT_POL0PHA0,
			SPI_MODE_PERIPHERAL,SPIA_peripheral_BITRATE,SPIA_peripheral_DATAWIDTH);

    //
    // Set FIFO interrupt levels
    // - TX interrupt when 2 or fewer words in FIFO
    // - RX interrupt when 2 or more words in FIFO
    //
    SPI_setFIFOInterruptLevel(SPIA_peripheral_BASE, SPI_FIFO_TX16, SPI_FIFO_TX16);

    //
    // Disable all SPI interrupts before configuration
    //
    SPI_disableAllInterrupt(SPIA_peripheral_BASE);

    //
    // Clear all interrupt status flags
    //
    SPI_clearAllInterruptStatus(SPIA_peripheral_BASE);

    //
    // Enable RX FIFO interrupt
    //
	SPI_enableInterrupt(SPIA_peripheral_BASE, SPI_INT_RXFF);

    //
    // Disable loopback mode for external communication
    //
	SPI_disableLoopback(SPIA_peripheral_BASE);

    //
    // Enable the SPI module after configuration
    //
    SPI_enableModule(SPIA_peripheral_BASE);
}

//*****************************************************************************
//
// Initializes SPIB Module as Controller with FIFO Interrupts
//
//*****************************************************************************
void SPIB_controller_init(void)
{
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_BSPI3);

    //
    // Disable the SPI module before configuration
    //
	SPI_disableModule(SPIB_controller_BASE);

    //
    // Configure SPI with specified parameters
    // - Clock frequency: DEVICE_APBCLK_FREQ
    // - Protocol: SPI_PROT_POL0PHA0 (Clock idle low, data captured on rising edge)
    // - Mode: Controller mode
    // - Bit rate: SPIB_controller_BITRATE
    // - Data width: SPIB_controller_DATAWIDTH
    //
	SPI_setConfig(SPIB_controller_BASE,DEVICE_APBCLK_FREQ,SPI_PROT_POL0PHA0,
			SPI_MODE_CONTROLLER,SPIB_controller_BITRATE,SPIB_controller_DATAWIDTH);

    //
    // Set FIFO interrupt levels
    // - TX interrupt when 2 or fewer words in FIFO
    // - RX interrupt when 2 or more words in FIFO
    //
    SPI_setFIFOInterruptLevel(SPIB_controller_BASE, SPI_FIFO_TX16, SPI_FIFO_TX16);

    //
    // Disable all SPI interrupts before configuration
    //
    SPI_disableAllInterrupt(SPIB_controller_BASE);

    //
    // Clear all interrupt status flags
    //
    SPI_clearAllInterruptStatus(SPIB_controller_BASE);

    //
    // Enable TX FIFO interrupt
    //
	SPI_enableInterrupt(SPIB_controller_BASE, SPI_INT_TXFF);

    //
    // Disable loopback mode for external communication
    //
	SPI_disableLoopback(SPIB_controller_BASE);

    //
    // Enable the SPI module after configuration
    //
    SPI_enableModule(SPIB_controller_BASE);
}


#ifdef __cplusplus
}
#endif

