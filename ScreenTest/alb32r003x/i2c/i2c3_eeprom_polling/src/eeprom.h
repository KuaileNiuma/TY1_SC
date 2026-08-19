/**
 *************************************************************************************
 * @file eeprom.h
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

#ifndef __EEPROM_H__
#define __EEPROM_H__

#include "i2c.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define myMasterI2C_BASE	  I2C3_BASE       //!< Master I2C base address selection
#define myMasterI2C_SDA_PIN	  GPIO_14_PMBUSA_SDA //!< Master I2C SDA pin definition
#define myMasterI2C_SCL_PIN	  GPIO_15_PMBUSA_SCL //!< Master I2C SCL pin definition
#define myMasterI2C_IRQn      I2C3_IRQn       //!< Master I2C interrupt vector

//*****************************************************************************
//
// Enumerations
//
//*****************************************************************************
typedef enum
{
    I2C_NEXT_CONDITION_NONE          = 0x01,  //!< No specific condition after transfer
    I2C_NEXT_CONDITION_STOP          = 0x02,  //!< Generate STOP condition after transfer
    I2C_NEXT_CONDITION_RESTART       = 0x04,  //!< Generate RESTART condition after transfer
} I2C_NEXT_CONDITION;

//*****************************************************************************
//
// Error messages for read and write functions
//
//*****************************************************************************
#define ERROR_BUS_BUSY             0x1000  //!< I2C bus is busy
#define ERROR_NACK_RECEIVED        0x2000  //!< NACK received during communication
#define ERROR_ARBITRATION_LOST     0x3000  //!< Arbitration lost on the bus
#define ERROR_ADDRESS_ERROR        0x4000  //!< Address error occurred
#define ERROR_STOP_NOT_READY       0x5555  //!< STOP condition not ready
#define I2C_LINK_SUCCESS           0x0000  //!< I2C communication successful

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//Write EEPROM Data Address
//
//*****************************************************************************
uint16_t eeprom_DataAddrWrite(uint32_t base, uint32_t data_addr);

//*****************************************************************************
//
// Write Data to EEPROM
//
//*****************************************************************************
uint16_t eeprom_WriteData(uint32_t base, uint32_t data_addr, uint8_t *data_cmd, uint32_t data_cmd_len, I2C_NEXT_CONDITION next_cond);

//*****************************************************************************
//
// Read Data from EEPROM
//
//*****************************************************************************
uint16_t eeprom_ReadData(uint32_t base, uint32_t data_addr, uint8_t *data_cmd, uint32_t data_cmd_len, I2C_NEXT_CONDITION next_cond);

//*****************************************************************************
//
// Check I2C Bus Status
//
//*****************************************************************************
uint16_t checkBusStatus(uint32_t base);

//*****************************************************************************
//
// Handle NACK Condition
//
//*****************************************************************************
uint16_t handleNACK(uint32_t base);

//*****************************************************************************
//
// Initialize EEPROM Interface
//
//*****************************************************************************
void eeprom_init(uint32_t addr_len);

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
extern uint16_t status;  //!< Global status variable


#endif 
