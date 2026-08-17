/**
 *************************************************************************************
 * @file hw_wwdg.h
 * @brief This file contains the definition of hw_uart driver.
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

#ifndef _HW_WWDG_H
#define _HW_WWDG_H

//*****************************************************************************
//
// WWDG Module Register Structure
//
//*****************************************************************************
typedef struct
 {
    __IO uint32_t CR;            //!< WWDG Control Register               (offset = 0x00)
    __IO uint32_t CFR;           //!< WWDG Configuration Register         (offset = 0x04)
    __IO uint32_t SR;            //!< WWDG Status Register                (offset = 0x08)
 } WWDG_TypeDef;

//*****************************************************************************
//
// WWDG Register Offsets
//
//*****************************************************************************
#define WWDG_O_CR           (0x00U)  //!< WWDG Control Register
#define WWDG_O_CFR          (0x04U)  //!< WWDG Configuration Register
#define WWDG_O_SR           (0x08U)  //!< WWDG Status Register

//*****************************************************************************
//
// WWDG_CR Register Bit Definitions
//
//*****************************************************************************
#define WWDG_CR_T                      ((uint8_t)0x7F)          //!< T[6:0] bits (7-Bit counter (MSB to LSB))
#define WWDG_CR_T0                     ((uint8_t)0x01)          //!< Bit 0
#define WWDG_CR_T1                     ((uint8_t)0x02)          //!< Bit 1
#define WWDG_CR_T2                     ((uint8_t)0x04)          //!< Bit 2
#define WWDG_CR_T3                     ((uint8_t)0x08)          //!< Bit 3
#define WWDG_CR_T4                     ((uint8_t)0x10)          //!< Bit 4
#define WWDG_CR_T5                     ((uint8_t)0x20)          //!< Bit 5
#define WWDG_CR_T6                     ((uint8_t)0x40)          //!< Bit 6

#define WWDG_CR_WDGA                   ((uint8_t)0x80)          //!< Activation bit


//*****************************************************************************
//
// WWDG_CFR Register Bit Definitions
//
//*****************************************************************************
#define WWDG_CFR_W                     ((uint16_t)0x007F)       //!< W[6:0] bits (7-bit window value)
#define WWDG_CFR_W0                    ((uint16_t)0x0001)       //!< Bit 0
#define WWDG_CFR_W1                    ((uint16_t)0x0002)       //!< Bit 1
#define WWDG_CFR_W2                    ((uint16_t)0x0004)       //!< Bit 2
#define WWDG_CFR_W3                    ((uint16_t)0x0008)       //!< Bit 3
#define WWDG_CFR_W4                    ((uint16_t)0x0010)       //!< Bit 4
#define WWDG_CFR_W5                    ((uint16_t)0x0020)       //!< Bit 5
#define WWDG_CFR_W6                    ((uint16_t)0x0040)       //!< Bit 6

#define WWDG_CFR_WDGTB                 ((uint16_t)0x0180)       //!< WDGTB[1:0] bits (Timer Base)
#define WWDG_CFR_WDGTB0                ((uint16_t)0x0080)       //!< Bit 0
#define WWDG_CFR_WDGTB1                ((uint16_t)0x0100)       //!< Bit 1

#define WWDG_CFR_EWI                   ((uint16_t)0x0200)       //!< Early Wakeup Interrupt


//*****************************************************************************
//
// WWDG_SR Register Bit Definitions
//
//*****************************************************************************
#define WWDG_SR_EWIF                    ((uint8_t)0x01)          //!< Early Wakeup Interrupt Flag


//*****************************************************************************
//
// WWDG Prescaler Definitions
//
//*****************************************************************************
#define WWDG_Prescaler_1    ((uint32_t)0x00000000)  //!< WWDG counter clock = (PCLK1 / 4096)/1
#define WWDG_Prescaler_2    ((uint32_t)0x00000080)  //!< WWDG counter clock = (PCLK1 / 4096)/2
#define WWDG_Prescaler_4    ((uint32_t)0x00000100)  //!< WWDG counter clock = (PCLK1 / 4096)/4
#define WWDG_Prescaler_8    ((uint32_t)0x00000180)  //!< WWDG counter clock = (PCLK1 / 4096)/8


#endif
