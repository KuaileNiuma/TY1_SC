/**
 *************************************************************************************
 * @file i2c_ex02_loopback_irq.h
 * @brief This file contains the header file for example i2c_ex02_loopback_irq.
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

#ifndef __I2C_EX02_LOOPBACK_IRQ_H__
#define __I2C_EX02_LOOPBACK_IRQ_H__

#include "i2c.h"
#include "device.h"
//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define myI2C_BASE	I2C2_BASE  //!< I2C base address selection

//*****************************************************************************
//
// I2C1 pin definitions
//
//*****************************************************************************
#if (myI2C_BASE == I2C1_BASE)
#define myI2C_GPIO_CLK_EN	SYSCTL_PERIPH_CLK_GPIOA
#define myI2C_SDA_PIN	GPIO_32_I2CA_SDA   //!< I2C1 SDA pin definition
#define myI2C_SCL_PIN	GPIO_33_I2CA_SCL   //!< I2C1 SCL pin definition
#define myI2C_IRQn      I2C1_IRQn        //!< I2C1 interrupt vector

//*****************************************************************************
//
// I2C2 pin definitions
//
//*****************************************************************************
#elif	(myI2C_BASE == I2C2_BASE)
#define myI2C_GPIO_CLK_EN	SYSCTL_PERIPH_CLK_GPIOA
#define myI2C_SDA_PIN	GPIO_2_I2CB_SDA     //!< I2C2 SDA pin definition
#define myI2C_SCL_PIN	GPIO_3_I2CB_SCL     //!< I2C2 SCL pin definition
#define myI2C_IRQn      I2C2_IRQn           //!< I2C2 interrupt vector

//*****************************************************************************
//
// I2C3 pin definitions
//
//*****************************************************************************
#elif	(myI2C_BASE == I2C3_BASE)
#define myI2C_GPIO_CLK_EN	SYSCTL_PERIPH_CLK_GPIOA
#define myI2C_SDA_PIN	GPIO_62_I2CC_SDA    //!< I2C3 SDA pin definition
#define myI2C_SCL_PIN	GPIO_230_I2CC_SCL   //!< I2C3 SCL pin definition
#define myI2C_IRQn      I2C3_IRQn           //!< I2C3 interrupt vector

#endif



//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
//*****************************************************************************
//
// I2C Loopback Interrupt Test Function
//
// This function configures GPIO pins for I2C, initializes the I2C module in
// loopback mode, and runs the interrupt-based test to verify communication.
//
//*****************************************************************************
void i2c_test02_loopback_irq(void);

#endif
