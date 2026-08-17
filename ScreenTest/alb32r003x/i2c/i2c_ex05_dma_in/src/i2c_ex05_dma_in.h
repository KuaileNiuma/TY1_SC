/**
 *************************************************************************************
 * @file i2c_ex05_dma_in.h
 * @brief This file contains the header file for example i2c_ex05_dma_in.
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

#ifndef __I2C_EX05_DMA_IN_H__
#define __I2C_EX05_DMA_IN_H__

#include "i2c.h"
#include "dma.h"
#include "dmasch.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define myMasterI2C_BASE	  I2C1_BASE       //!< Master I2C base address selection
#define myMasterI2C_SDA_PIN	  GPIO_32_I2CA_SDA //!< Master I2C SDA pin definition
#define myMasterI2C_SCL_PIN	  GPIO_33_I2CA_SCL //!< Master I2C SCL pin definition
#define myMasterI2C_IRQn      I2C1_IRQn       //!< Master I2C interrupt vector


//*****************************************************************************
//
// I2C Write-Read Polling Function
//
//*****************************************************************************
void i2c_write_read_polling(void);

#endif
