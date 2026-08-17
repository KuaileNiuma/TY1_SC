/**
 *************************************************************************************
 * @file fatfs_ex01_board.c
 * @brief This file contains the source file for example fatfs_ex01_board.
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
 
#include "fatfs_ex01_board.h"

//*****************************************************************************
//
// Board Initialization
//
//*****************************************************************************
void Board_init(void)
{
	//
	// Initialize GPIO pins
	//
	Gpio_init();
	//
	// Configure GPIO pin muxing
	//
	PinMux_init();
	//
	// Initialize SPI modules
	//
	SPI_init();
	//
	// Configure and enable interrupts
	//
	INTERRUPT_init();

}

//*****************************************************************************
//
// GPIO Initialization
//
//*****************************************************************************
void Gpio_init(void)
{
    //
    // Configure GPIO0 as chip select (CS)
    //
	GPIO_setDirectionMode(mySPI0_SPISTE_GPIO, GPIO_DIR_MODE_OUT);
    //
    // Set CS pin high (inactive) initially
    //
	GPIO_writePin(mySPI0_SPISTE_GPIO, 1);
}
//*****************************************************************************
//
// Pin Mux Configuration
//
//*****************************************************************************
void PinMux_init(void)
{
	//
	// Configure SPIA pin muxing
	//

	//
	// Configure SPIA_STE (GPIO0) pin function
	//
	GPIO_setPinConfig(mySPI0_SPISTE_GPIO);     

	//
	// Configure SPIA_CLK (GPIO3) pin function
	//
	GPIO_setPinConfig(mySPI0_SPICLK_PIN_CONFIG);

	//
	// Configure SPIA_SIMO (GPIO2) pin function
	//
	GPIO_setPinConfig(mySPI0_SPISIMO_PIN_CONFIG);

	//
	// Configure SPIA_SOMI (GPIO1) pin function
	//
	GPIO_setPinConfig(mySPI0_SPISOMI_PIN_CONFIG);
}

//*****************************************************************************
//
// Interrupt Configuration
//
//*****************************************************************************
extern void spiRxFIFOISR(void);      //!< SPI receive FIFO interrupt service routine

void INTERRUPT_init(void)
{
    //
    // Register SPI RX FIFO interrupt handler
    //
	Interrupt_register(SPI1RX_IRQn, spiRxFIFOISR);
    //
    // Set SPI RX FIFO interrupt priority
    //
	Interrupt_setPriority(SPI1RX_IRQn, 0, 0);
    //
    // Enable SPI RX FIFO interrupt
    //
	Interrupt_enable(SPI1RX_IRQn);
    //
    // Enable external interrupt controller for SPI RX interrupt
    //
	ECLIC_EnableIRQ(SPI1RX_IRQn);
}

//*****************************************************************************
//
// SPI Module Initialization
//
//*****************************************************************************
void SPI_init(void)
{
	//
	// Initialize SPI module with flash-specific settings
	//
	mySPI_init();
}

//*****************************************************************************
//
// SPI Module Configuration for Flash Communication
//
//*****************************************************************************
void mySPI_init(void)
{
    //
    // Disable the SPI module before configuration
    //
	SPI_disableModule(mySPI_BASE);

	//
	// Configure SPI module with controller mode, specific protocol and timing
	//
	SPI_setConfig(mySPI_BASE,DEVICE_APBCLK_FREQ,SPI_PROT_POL0PHA0,
			SPI_MODE_CONTROLLER,mySPI_BITRATE,mySPI_DATAWIDTH);

    //
    // Configure FIFO interrupt levels for efficient data transfer
    //
    SPI_setFIFOInterruptLevel(mySPI_BASE, SPI_FIFO_TX16, SPI_FIFO_RX16);

	//
	// Disable all SPI interrupts before configuring
	//
	SPI_disableAllInterrupt(mySPI_BASE);

	//
	// Clear any pending interrupt flags
	//
	SPI_clearAllInterruptStatus(mySPI_BASE);

    //
    // Enable specific SPI interrupts for error handling
    //
	SPI_enableInterrupt(mySPI_BASE,SPI_INT_RXFF_OVERFLOW | SPI_INT_RXFF_UNDERFLOW | SPI_INT_TXFF_OF);

	//
	// Disable loopback mode (use normal external communication)
	//
	SPI_disableLoopback(mySPI_BASE);

    //
    // Enable the SPI module after configuration
    //
    SPI_enableModule(mySPI_BASE);

    //
    // Note: CS pin handled manually via GPIO
    //
    // SPI_csEnable(mySPI_BASE);
}





#ifdef __cplusplus
}
#endif

