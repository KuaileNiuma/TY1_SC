/*
 * Copyright (c) 2026.02
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PMBUS_H
#define __PMBUS_H

#include "pmbus_def.h"
#include "device.h"

typedef struct {
    uint8_t command; /**< The PMBUS command type */
    uint32_t len;    /**< The length of the transferred data */
    bool read;       /**< Whether the operation is a read */
    bool pec_check;  /**< Whether PEC check is enabled */
    uint8_t *data;   /**< Pointer to the data buffer */
} pmbus_complete_cb_cfg_t;


typedef void (*pmbus_complete_cb_t)(uint32_t i2c_base, pmbus_complete_cb_cfg_t *cfg);

typedef enum {
    none            = 0,    /**< No operation */
    write_byte      = 1,    /**< Write a byte */
    read_byte       = 2,    /**< Read a byte */
    write_word      = 3,    /**< Write a word (two bytes) */
    read_word       = 4,    /**< Read a word (two bytes)  */
    write_block     = 5,    /**< Write a block */
    read_block      = 6,    /**< Read a block */
    send_byte       = 7,    /**< Send a byte */
    mfr_defined     = 8,    /**< Manufacturer-defined command */
    extended_command = 9,   /**< Extended command */
} pmbus_transaction_type;


typedef struct {
     /**< The command code, used to identify specific PMBus commands. */
    uint8_t command_code;
     /**< The write transaction type, indicating the type of write operation. */
    pmbus_transaction_type write_transaction_type;
    /**< The read transaction type, indicating the type of read operation. */
    pmbus_transaction_type read_transaction_type;
    /**< The data length, indicating the amount of data associated with the command. */
    uint32_t data_length;
} pmbus_cmd_param_t;


typedef struct {
    bool is_valid;        /**< A flag indicating whether the slave configuration is valid */
    uint8_t *wdata;       /**< Pointer to write data, used for writing data to the slave */
    uint8_t *rdata;       /**< Pointer to read data, used for reading data from the slave */
    uint32_t data_length; /**< Data length, representing the number of bytes to be written or read */
    pmbus_complete_cb_t callback; /**< Callback function pointer, called when data transfer completes */
} pmbus_slave_cfg_t;

/**
 * @brief PMBUS status
 */
enum {
    status_success = 0,
    status_fail,
    status_invalid_argument,
    status_timeout,
    status_pmbus_not_support_cmd ,
    status_pmbus_not_transaction_type,
};

#ifdef __cplusplus
extern "C"
{
#endif

void pmbus_isr_handler(uint32_t i2c_base);


uint32_t pmbus_slave_init(uint32_t i2c_base, uint8_t slave_addr);


uint32_t pmbus_master_read(uint32_t i2c_base, uint8_t slave_address, uint8_t command, uint8_t *data, uint32_t *len);

uint32_t pmbus_master_write(uint32_t i2c_base, uint8_t slave_address, uint8_t command, uint8_t *data, uint32_t len);


uint32_t pmbus_slave_command_transaction_install(uint32_t i2c_base, uint8_t command, uint8_t *wdata, uint8_t *rdata, uint32_t len, pmbus_complete_cb_t callback);

uint32_t pmbus_slave_command_transaction_uninstall(uint32_t i2c_base, uint8_t command);

#ifdef __cplusplus
}
#endif

#endif
