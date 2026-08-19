/**
 *************************************************************************************
 * @file board.h
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

#ifndef __BOARD_H_
#define __BOARD_H_

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


// SPIA -> SPIA_peripheral Pinmux
//
// SPIA_SIMO - GPIO Settings
//
#define GPIO_PIN_SPIA_SIMO 2                       //!< SPIA SIMO GPIO pin number
#define SPIA_peripheral_SPISIMO_GPIO 2             //!< SPIA SIMO GPIO number
#define SPIA_peripheral_SPISIMO_PIN_CONFIG GPIO_2_SPIA_SIMO //!< SPIA SIMO pin configuration
//
// SPIA_SOMI - GPIO Settings
//
#define GPIO_PIN_SPIA_SOMI 1                       //!< SPIA SOMI GPIO pin number
#define SPIA_peripheral_SPISOMI_GPIO 1             //!< SPIA SOMI GPIO number
#define SPIA_peripheral_SPISOMI_PIN_CONFIG GPIO_1_SPIA_SOMI //!< SPIA SOMI pin configuration
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIA_CLK 3                        //!< SPIA CLK GPIO pin number
#define SPIA_peripheral_SPICLK_GPIO 3              //!< SPIA CLK GPIO number
#define SPIA_peripheral_SPICLK_PIN_CONFIG GPIO_3_SPIA_CLK //!< SPIA CLK pin configuration
//
// SPIA_STE - GPIO Settings
//
#define GPIO_PIN_SPIA_STE 0                        //!< SPIA STE GPIO pin number
#define SPIA_peripheral_SPISTE_GPIO 0              //!< SPIA STE GPIO number
#define SPIA_peripheral_SPISTE_PIN_CONFIG GPIO_0_SPIA_STE //!< SPIA STE pin configuration

//
// SPIC -> SPIC_controller Pinmux
//
// SPIC_SIMO - GPIO Settings
//
#define GPIO_PIN_SPIC_SIMO 7                                 //!< SPIC SIMO pin number
#define SPIC_controller_SPISIMO_GPIO 7                       //!< SPIC SIMO GPIO number
#define SPIC_controller_SPISIMO_PIN_CONFIG GPIO_7_SPIC_SIMO   //!< SPIC SIMO pin configuration

//
// SPIC_SOMI - GPIO Settings
//
#define GPIO_PIN_SPIC_SOMI 6                                 //!< SPIC SOMI pin number
#define SPIC_controller_SPISOMI_GPIO 6                       //!< SPIC SOMI GPIO number
#define SPIC_controller_SPISOMI_PIN_CONFIG GPIO_6_SPIC_SOMI   //!< SPIC SOMI pin configuration

//
// SPIC_CLK - GPIO Settings
//
#define GPIO_PIN_SPIC_CLK 14                                //!< SPIC CLK pin number
#define SPIC_controller_SPICLK_GPIO 14                      //!< SPIC CLK GPIO number
#define SPIC_controller_SPICLK_PIN_CONFIG GPIO_14_SPIC_CLK  //!< SPIC CLK pin configuration

//
// SPIC_STE - GPIO Settings
//
#define GPIO_PIN_SPIC_STE 23                                //!< SPIC STE pin number
#define SPIC_controller_SPISTE_GPIO 23                      //!< SPIC STE GPIO number
#define SPIC_controller_SPISTE_PIN_CONFIG GPIO_15_SPIC_STE  //!< SPIC STE pin configuration



//*****************************************************************************
//
// Interrupt Configuration                                
//                                
//*****************************************************************************
extern void spiARxFIFOISR(void);  //!< SPIA RX FIFO interrupt service routine
extern void spiBTxFIFOISR(void);  //!< SPIC TX FIFO interrupt service routine

//*****************************************************************************
//
// SPI Configuration                                
//                                
//*****************************************************************************
#define SPIA_peripheral_BASE SPI1_BASE                    //!< SPIA peripheral base address
#define SPIA_peripheral_BITRATE 500000                    //!< SPIA peripheral bit rate (500 kHz)
#define SPIA_peripheral_DATAWIDTH 16                      //!< SPIA peripheral data width (16 bits)

//*****************************************************************************
//
// Initialize SPIA module as peripheral with FIFO interrupts
//
//*****************************************************************************
void SPIA_peripheral_init();

#define SPIC_controller_BASE SPI3_BASE                    //!< SPIC controller base address
#define SPIC_controller_BITRATE 500000                    //!< SPIC controller bit rate (500 kHz)
#define SPIC_controller_DATAWIDTH 16                      //!< SPIC controller data width (16 bits)

//*****************************************************************************
//
// Initialize SPIC module as controller with FIFO interrupts
//
//*****************************************************************************
void SPIC_controller_init();


//*****************************************************************************
//
// Initialize board hardware, including GPIO, SPI, and interrupts
//
//*****************************************************************************
void Board_init();

//*****************************************************************************
//
// Initialize interrupts for SPI communication
//
//*****************************************************************************
void INTERRUPT_init();

//*****************************************************************************
//
// Initialize SPI modules (SPIA and SPIC)
//
//*****************************************************************************
void SPIX_init();

//*****************************************************************************
//
// Initialize GPIO pin muxing for SPI communication
//
//*****************************************************************************
void PinMux_init();

#ifdef __cplusplus
}
#endif

#endif
