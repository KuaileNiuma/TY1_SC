/**
 *************************************************************************************
 * @file spi_ex01_lookback_board.h
 * @brief This file contains the header file.
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

#ifndef __SPI_EX01_LOOPBACK_BOARD_H_
#define __SPI_EX01_LOOPBACK_BOARD_H_

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Include Files
//
//*****************************************************************************
#include <stdio.h>
#include "device.h"
#include "spi.h"

//*****************************************************************************
//
// Get SPI Clock
//
//*****************************************************************************
#define DEVICE_APBCLK_FREQ SystemClock_Get_APBL()  //!< APB clock frequency

//*****************************************************************************
//
// Pin Mux Configuration
//
//*****************************************************************************
//
// SPI0 Pin Mux Configuration
//

//
// SPI0 SIMO (Master Out Slave In) GPIO Configuration
//
#define GPIO_PIN_SPIA_SIMO 2                     //!< SPI0 SIMO GPIO pin number
#define mySPI0_SPISIMO_GPIO 2                    //!< SPI0 SIMO GPIO number
#define mySPI0_SPISIMO_PIN_CONFIG GPIO_2_SPIA_SIMO  //!< SPI0 SIMO pin configuration

//
// SPI0 SOMI (Slave Out Master In) GPIO Configuration
//
#define GPIO_PIN_SPIA_SOMI 1                     //!< SPI0 SOMI GPIO pin number
#define mySPI0_SPISOMI_GPIO 1                    //!< SPI0 SOMI GPIO number
#define mySPI0_SPISOMI_PIN_CONFIG GPIO_1_SPIA_SOMI  //!< SPI0 SOMI pin configuration

//
// SPI0 CLK (Clock) GPIO Configuration
//
#define GPIO_PIN_SPIA_CLK 3                      //!< SPI0 CLK GPIO pin number
#define mySPI0_SPICLK_GPIO 3                     //!< SPI0 CLK GPIO number
#define mySPI0_SPICLK_PIN_CONFIG GPIO_3_SPIA_CLK  //!< SPI0 CLK pin configuration

//
// SPI0 STE (Slave Transmit Enable) GPIO Configuration
//
#define GPIO_PIN_SPIA_STE 0                      //!< SPI0 STE GPIO pin number
#define mySPI0_SPISTE_GPIO 0                     //!< SPI0 STE GPIO number
#define mySPI0_SPISTE_PIN_CONFIG GPIO_0_SPIA_STE  //!< SPI0 STE pin configuration

//*****************************************************************************
//
// SPI Configuration
//
//*****************************************************************************
#define mySPI_BASE SPI1_BASE           //!< SPI base address
#define mySPI_BITRATE 1000000          //!< SPI bit rate (1 MHz)
#define mySPI_DATAWIDTH 32             //!< SPI data width (16 bits)



//
// Function Prototypes
//
//*****************************************************************************
void mySPI0_init();                   //!< Initializes SPI0 module

//*****************************************************************************
//
// Board Functions
//
//*****************************************************************************
void Board_init();    //!< Initializes board hardware
void SPI_init();      //!< Initializes SPI modules
void PinMux_init();   //!< Configures GPIO pin muxing

#ifdef __cplusplus
}
#endif

#endif 
