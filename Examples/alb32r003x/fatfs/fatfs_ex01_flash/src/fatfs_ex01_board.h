/**
 *************************************************************************************
 * @file fatfs_ex01_board.h
 * @brief This file contains the header file for example fatfs_ex01_board.
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

#include "device.h"

//*****************************************************************************
//
// Get SPI Clock
//
//*****************************************************************************

#define DEVICE_APBCLK_FREQ SystemClock_Get_APBL()  //!< APB clock frequency (20 MHz)

//*****************************************************************************
//
// GPIO Configuration
//
//*****************************************************************************
#define GPIO_SPIA_CS GPIO_0_GPIO0               //!< SPI chip select GPIO pin
#define CS_HIGH		    GPIO_writePin(GPIO_SPIA_CS,1);  //!< Set CS pin high
#define CS_LOW		    GPIO_writePin(GPIO_SPIA_CS,0);   //!< Set CS pin low

//*****************************************************************************
//
// Pin Mux Configuration
//
//*****************************************************************************
//
// SPIA -> mySPI0 Pinmux
//
//
// SPIA_SIMO - GPIO Settings
//
#define GPIO_PIN_SPIX_SIMO 2                      //!< SPI SIMO GPIO pin number
#define mySPI0_SPISIMO_GPIO 2                     //!< SPI SIMO GPIO number
#define mySPI0_SPISIMO_PIN_CONFIG GPIO_2_SPIA_SIMO  //!< SPI SIMO pin configuration
//
// SPIA_SOMI - GPIO Settings
//
#define GPIO_PIN_SPIX_SOMI 1                      //!< SPI SOMI GPIO pin number
#define mySPI0_SPISOMI_GPIO 1                     //!< SPI SOMI GPIO number
#define mySPI0_SPISOMI_PIN_CONFIG GPIO_1_SPIA_SOMI  //!< SPI SOMI pin configuration
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIX_CLK 3                       //!< SPI CLK GPIO pin number
#define mySPI0_SPICLK_GPIO 3                      //!< SPI CLK GPIO number
#define mySPI0_SPICLK_PIN_CONFIG GPIO_3_SPIA_CLK   //!< SPI CLK pin configuration
//
// SPIA_STE - GPIO Settings
//
#define GPIO_PIN_SPIX_STE 0                       //!< SPI STE GPIO pin number
#define mySPI0_SPISTE_GPIO 0                      //!< SPI STE GPIO number
#define mySPI0_SPISTE_PIN_CONFIG GPIO_0_SPIA_STE   //!< SPI STE pin configuration



//*****************************************************************************
//
// Interrupt Function Prototypes
//
extern void spiFIFOISR(void);                   //!< SPI FIFO interrupt service routine

//*****************************************************************************
//
// SPI Configuration
//
//*****************************************************************************
#define mySPI_BASE SPI1_BASE                     //!< SPI base address
#define mySPI_BITRATE 1000000                    //!< SPI bit rate (1 MHz)
#define mySPI_DATAWIDTH 8                        //!< SPI data width (8 bits)

//
// Function Prototypes
//
void mySPI_init(void);                          //!< Initializes SPI module for flash communication

//*****************************************************************************
//
// Board Functions
//
//*****************************************************************************
void	Board_init();        //!< Initializes board hardware
void	Gpio_init();         //!< Configures GPIO pins
void	INTERRUPT_init();    //!< Configures and enables interrupts
void	SPI_init();          //!< Initializes SPI modules
void	PinMux_init();       //!< Configures GPIO pin muxing

#ifdef __cplusplus
}
#endif


