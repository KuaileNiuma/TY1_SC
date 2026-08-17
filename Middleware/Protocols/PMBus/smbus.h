/*
 * Copyright (c) 2026.02
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _SMBUS_H
#define _SMBUS_H

#include "device.h"

#ifdef __cplusplus
extern "C"
{
#endif



#ifndef I2C_DRV_DEFAULT_RETRY_COUNT
#define I2C_DRV_DEFAULT_RETRY_COUNT (5000U)
#endif


uint32_t smbus_master_write_byte(uint32_t i2c_base, uint8_t slave_address,
                                       uint8_t data);


uint32_t smbus_master_read_byte(uint32_t i2c_base, uint8_t slave_address,
                                      uint8_t *data);


uint32_t smbus_master_write_byte_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                  uint8_t command, uint8_t data);


uint32_t smbus_master_write_word_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                  uint8_t command,  uint16_t data);


uint32_t smbus_master_read_byte_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                 uint8_t command, uint8_t *data);


uint32_t smbus_master_read_word_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                 uint8_t command, uint16_t *data);


uint32_t smbus_master_write_block_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                   uint8_t command, uint8_t *data, uint32_t size);


uint32_t smbus_master_read_block_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                  uint8_t command, uint8_t *data, uint32_t size);


uint32_t smbus_master_write(uint32_t i2c_base, uint8_t slave_address,
                                  uint8_t *data, uint32_t size);


uint32_t smbus_master_read(uint32_t i2c_base, uint8_t slave_address,
                                 uint8_t *data, uint32_t size);


uint32_t smbus_slave_write(uint32_t i2c_base, uint8_t *data, uint32_t size);


uint32_t smbus_slave_read(uint32_t i2c_base, uint8_t *data, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif


