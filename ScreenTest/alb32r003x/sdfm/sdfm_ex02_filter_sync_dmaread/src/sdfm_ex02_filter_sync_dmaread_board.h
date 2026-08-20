/**
 *************************************************************************************
 * @file sdfm_ex02_filter_sync_dmaread_board.h
 * @brief This file contains the header file for example sdfm_ex02_filter_sync_dmaread_board.
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
#ifndef SDFM_EX02_FILTER_SYNC_DMAREAD_BOARD_H_
#define SDFM_EX02_FILTER_SYNC_DMAREAD_BOARD_H_

#include "device.h"
#include "alb32r003x.h"

//*****************************************************************************
//
// Macros
//
//*****************************************************************************
#define RESULTS_BUFFER_SIZE     (512)  //!< Size of the data buffer for storing SDFM results
#define CHECK_SIZE              (32)     //!< Size of data chunk to check for validation

//*****************************************************************************
//
// Global Variables (DMA target buffers)
//
//*****************************************************************************
extern uint16_t mySDFilter1DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];
extern uint16_t mySDFilter2DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];
extern uint16_t mySDFilter3DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];
extern uint16_t mySDFilter4DataBuffer[RESULTS_BUFFER_SIZE + CHECK_SIZE];

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void Board_init(void);       //!< Initializes all board components for the SDFM example
void PinMux_init(void);      //!< Configures GPIO pins for SDFM1 module
void sdfm_init(void);        //!< Initializes and configures the SDFM1 module
void DMA_init(void);         //!< Initializes the DMA controller for SDFM data transfers

#endif


