/**
 *************************************************************************************
 * @file spi_ex03_external_loopback_board.c
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
}

//*****************************************************************************
//
// Initializes GPIO Pin Muxing
//
//*****************************************************************************
void PinMux_init(void)
{
    //
    // Configure SPIA peripheral pins
    //
    
    //
    // Configure SPIA SIMO (Slave In Master Out) pin
    //
    GPIO_setPinConfig(SPIA_peripheral_SPISIMO_PIN_CONFIG);
    
    //
    // Configure SPIA SOMI (Slave Out Master In) pin
    //
    GPIO_setPinConfig(SPIA_peripheral_SPISOMI_PIN_CONFIG);
    
    //
    // Configure SPIA CLK (Clock) pin
    //
    GPIO_setPinConfig(SPIA_peripheral_SPICLK_PIN_CONFIG);
    
    //
    // Configure SPIA STE (Slave Transmit Enable) pin
    //
    GPIO_setPinConfig(SPIA_peripheral_SPISTE_PIN_CONFIG);
    
    //
    // Configure SPIB controller pins
    //
    
    //
    // Configure SPIB SIMO (Master Out Slave In) pin
    //
    GPIO_setPinConfig(SPIB_controller_SPISIMO_PIN_CONFIG);
    
    //
    // Configure SPIB SOMI (Master In Slave Out) pin
    //
    GPIO_setPinConfig(SPIB_controller_SPISOMI_PIN_CONFIG);
    
    //
    // Configure SPIB CLK (Clock) pin
    //
    GPIO_setPinConfig(SPIB_controller_SPICLK_PIN_CONFIG);
    
    //
    // Configure SPIB STE (Slave Transmit Enable) pin
    //
    GPIO_setPinConfig(SPIB_controller_SPISTE_PIN_CONFIG);
}

//*****************************************************************************
//
// Initializes SPI modules
//
//*****************************************************************************
void SPIX_init(void)
{
    //
    // Initialize SPIA in peripheral mode
    //
    SPIA_peripheral_init();
    
    //
    // Initialize SPIB in controller mode
    //
    SPIB_controller_init();
}

//*****************************************************************************
//
// SPI Peripheral Configuration
//
//*****************************************************************************
void SPIA_peripheral_init(void)
{
    //
    // open SPI1 clk
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_BSPI1);

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
    SPI_setConfig(SPIA_peripheral_BASE, DEVICE_APBCLK_FREQ, SPI_PROT_POL0PHA0, \
                 SPI_MODE_PERIPHERAL, SPIA_peripheral_BITRATE, SPIA_peripheral_DATAWIDTH);

    //
    // Set FIFO interrupt levels
    // - TX interrupt when 8 or fewer words in FIFO
    // - RX interrupt when 8 or more words in FIFO
    //
    SPI_setFIFOInterruptLevel(SPIA_peripheral_BASE, SPI_FIFO_TX8, SPI_FIFO_RX8);

    //
    // Disable all SPI interrupts
    //
    SPI_disableAllInterrupt(SPIA_peripheral_BASE);

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
// SPI Controller Configuration
//
//*****************************************************************************
void SPIB_controller_init(void)
{
    //
    // open SPI2 clk
    //
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_BSPI2);

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
    SPI_setConfig(SPIB_controller_BASE, DEVICE_APBCLK_FREQ, SPI_PROT_POL0PHA0, \
                 SPI_MODE_CONTROLLER, SPIB_controller_BITRATE, SPIB_controller_DATAWIDTH);

    //
    // Set FIFO interrupt levels
    // - TX interrupt when 8 or fewer words in FIFO
    // - RX interrupt when 8 or more words in FIFO
    //
    SPI_setFIFOInterruptLevel(SPIB_controller_BASE, SPI_FIFO_TX8, SPI_FIFO_RX8);

    //
    // Disable all SPI interrupts
    //
    SPI_disableAllInterrupt(SPIB_controller_BASE);

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

