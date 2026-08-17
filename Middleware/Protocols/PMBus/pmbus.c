/*
 * Copyright (c) 2026.02
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "pmbus.h"
#include "pmbus_private.h"
#include "smbus.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    uint32_t i2c_base;
    uint8_t slave_addr;
    bool cmd_found;
    uint8_t command_code;
    uint32_t data_length;
    pmbus_slave_cfg_t slave_conf[255];
} pmbus_cfg_t;

extern const pmbus_cmd_param_t pmbus_cmd_param_table[];

static pmbus_cfg_t pmbus_cfg_table[] =
{

{ .i2c_base = I2C1_BASE, .cmd_found = false, .data_length = 0, },

};

static pmbus_cfg_t* pmbus_get_cfg_obj(uint32_t i2c_base)
{
    pmbus_cfg_t *obj;
    uint8_t i = 0;
    for (i = 0; i < (sizeof(pmbus_cfg_table) / sizeof(pmbus_cfg_t)); i++)
    {
        obj = &pmbus_cfg_table[i];
        if (obj->i2c_base == i2c_base)
        {
            return obj;
        }
    }
    return NULL;
}

extern const uint8_t crc8_table[];
static uint8_t smbus_pec_crc8_in_command(uint8_t slave_addr, uint8_t command, uint8_t *data, uint32_t len, bool read,
        bool block)
{
    /* The PEC is a CRC-8 error-checking byte, calculated on all the message bytes (including addresses and read/write bits) */
    uint32_t i;
    uint8_t crc = 0x00;
    crc = crc8_table[crc ^ (slave_addr << 1)];
    crc = crc8_table[crc ^ command];

    if (read == true)
    {
        crc = crc8_table[crc ^ ((slave_addr << 1) + 1)];

        if (block == true)
        {
            crc = crc8_table[crc ^ len];
        }
    }
    while (len--)
    {
        crc = crc8_table[crc ^ *data++];
    }
    return crc;
}

uint8_t g_buf[256] = { 0 };
int g_cnt = 0;
#ifdef  PMBUS_DEBUG
uint8_t g_txbuf[256] = { 0 };
int g_txcnt = 0;
#endif
void pmbus_isr_handler(uint32_t i2c_base)
{
    volatile uint32_t status, irq;
    uint8_t pec = 0;
    uint8_t size;
    uint32_t send_size;
    uint8_t cmd_code;
    pmbus_complete_cb_cfg_t cfg;
    static uint8_t isreq = 0;
    static uint8_t is_send_read_block_len = 0;
    irq = I2C_getInterruptStatus(i2c_base);
    pmbus_cfg_t *obj = pmbus_get_cfg_obj(i2c_base);

    if (irq & I2C_IC_INTR_STAT_START_DET) //start
    {
        I2C_clearInterruptStartDet(i2c_base);
        obj->data_length = 0;
        isreq = 0;
        is_send_read_block_len = 0;
        g_cnt = 0;
    }
    if (irq & I2C_IC_INTR_STAT_RD_REQ)  //master initiate  read
    {
        isreq = 1;
        I2C_enableInterrupt(i2c_base, I2C_IC_INTR_MASK_M_TX_EMPTY);
        I2C_clearInterruptRdReq(i2c_base);
    }

    if (irq & I2C_IC_INTR_STAT_RX_FULL)
    {
        if (obj->cmd_found == false)
        {
            if (0 == obj->data_length) //receive fisrt
            {
                if (g_cnt == 0)
                {
                    cmd_code = I2C_getData(i2c_base);
                    g_buf[g_cnt++/sizeof(g_buf)] = cmd_code; //beause of noack,consider invalid cmd
                }
                else
                {
                    g_buf[g_cnt++/sizeof(g_buf)] = I2C_getData(i2c_base);//beause of noack,consider invalid cmd
                }
            }
            /* check if the command is valid */
            if (obj->slave_conf[cmd_code].is_valid == true)
            {
                /* Mark that the command has been found, set the current command code */
                obj->command_code = cmd_code;
                obj->cmd_found = true;
            }
            else /* Send a NACK response, indicating an invalid command */
            {

            }
        }
        else
        {
            /* If the command has been found and the data length is within the expected range */
            if ((obj->cmd_found == true) && (obj->data_length < pmbus_cmd_param_table[obj->command_code].data_length))
            {
                if (obj->slave_conf[obj->command_code].rdata)
                {
                    obj->slave_conf[obj->command_code].rdata[obj->data_length++] = I2C_getData(i2c_base);
                    /* Send an ACK response, indicating successful data reception */
                }
                else
                {
                    /* Send a NACK response, indicating a failure in storing data */
                    obj->data_length = 0;
                }
#ifdef  PMBUS_DEBUG
                g_buf[g_cnt++/sizeof(g_buf)] = obj->slave_conf[obj->command_code].rdata[obj->data_length - 1];  //for debug
#endif
            }
            else
            {
                /* has pec byte*/
                if (obj->data_length >= pmbus_cmd_param_table[obj->command_code].data_length)
                {
                    obj->slave_conf[obj->command_code].rdata[obj->data_length++] = I2C_getData(i2c_base);
#ifdef  PMBUS_DEBUG
                    g_buf[g_cnt++/siezof(g_buf)] = obj->slave_conf[obj->command_code].rdata[obj->data_length - 1];  //for debug
#endif
                    /* Send an ACK response, indicating successful data reception */
                }
                else
                {
                    /* Send a NACK response, indicating a failure in storing data */
                    obj->data_length = 0;
                }
            }
        }
    }

    /* transmit */
    if (irq & I2C_IC_INTR_STAT_TX_EMPTY)
    {
        if ((obj->data_length > pmbus_cmd_param_table[obj->command_code].data_length) || (obj->cmd_found == false))
        {
            I2C_disableInterrupt(i2c_base, I2C_IC_INTR_MASK_M_TX_EMPTY);
        }
        else
        {
            while ((I2C_getIcStatus(i2c_base) & I2C_IC_STATUS_TFNF))
            {
                if ((is_send_read_block_len == 0)
                        && (pmbus_cmd_param_table[obj->command_code].read_transaction_type == read_block))
                {
                    is_send_read_block_len = 1;
                    I2C_putData(i2c_base, obj->slave_conf[obj->command_code].data_length);
#ifdef  PMBUS_DEBUG
                    g_txbuf[g_txcnt++/sizeof(g_txbuf)] = obj->slave_conf[obj->command_code].data_length;
#endif
                    continue;
                }
                if (pmbus_cmd_param_table[obj->command_code].read_transaction_type == read_block)
                {
                    send_size = obj->slave_conf[obj->command_code].data_length;
                }
                else
                {
                    send_size = pmbus_cmd_param_table[obj->command_code].data_length;
                }
                if (obj->data_length < send_size)
                {
                    I2C_putData(i2c_base, obj->slave_conf[obj->command_code].wdata[obj->data_length++]);
#ifdef  PMBUS_DEBUG
                    g_txbuf[g_txcnt++/sizeof(g_txbuf)] = obj->slave_conf[obj->command_code].wdata[obj->data_length - 1];
#endif
                }
                else
                {
                    if (obj->data_length == send_size)
                    {
                        if (pmbus_cmd_param_table[obj->command_code].read_transaction_type == read_block)
                        {
                            /* For read block, pec check must contain length */
                            pec = smbus_pec_crc8_in_command(obj->slave_addr, obj->command_code,
                                    &obj->slave_conf[obj->command_code].wdata[0], obj->data_length, true, true);
                        }
                        else
                        {
                            pec = smbus_pec_crc8_in_command(obj->slave_addr, obj->command_code,
                                    &obj->slave_conf[obj->command_code].wdata[0], obj->data_length, true, false);
                        }
                        I2C_putData(i2c_base, pec);
                        obj->data_length++;
#ifdef  PMBUS_DEBUG
                        g_txbuf[g_txcnt++/sizeof(g_txbuf)] = pec;
#endif

                    }
                    else
                    {
                        I2C_disableInterrupt(i2c_base, I2C_IC_INTR_MASK_M_TX_EMPTY);
                        break;
                    }
                }
            }
        }
    }
    /* complete */
    if (irq & I2C_IC_INTR_STAT_STOP_DET)
    {
        I2C_disableInterrupt(i2c_base, I2C_IC_INTR_MASK_M_TX_EMPTY);
        I2C_clearInterruptStopDet(i2c_base);
        /* For the slave mode, write-related commands are read operations */
        if (0 == isreq)
        {
            if (!obj->data_length)
            {
                return;
            }
            if (pmbus_cmd_param_table[obj->command_code].write_transaction_type == write_block)
            {
                /* need read length for write_block */
                size = obj->slave_conf[obj->command_code].rdata[0];
                if (obj->data_length == (uint32_t) (size + 2))
                {
                    pec = smbus_pec_crc8_in_command(obj->slave_addr, obj->command_code,
                            &obj->slave_conf[obj->command_code].rdata[0], size + 1, false, true);
                    memcpy(&obj->slave_conf[obj->command_code].rdata[0], &obj->slave_conf[obj->command_code].rdata[1],
                            size);
                    if (pec != obj->slave_conf[obj->command_code].rdata[size + 1])
                    {
                        cfg.pec_check = false;
                    }
                    else
                    {
                        cfg.pec_check = true;
                    }
                    cfg.len = size;
                }
            }
            else
            {
                switch (pmbus_cmd_param_table[obj->command_code].write_transaction_type)
                {
                case write_word:
                    cfg.len = 2;
                    break;
                case write_byte:
                    cfg.len = 1;
                    break;
                default:
                    cfg.len = 0;
                    break;
                }
                pec = smbus_pec_crc8_in_command(obj->slave_addr, obj->command_code,
                        &obj->slave_conf[obj->command_code].rdata[0], cfg.len, false, false);
                if (pec != obj->slave_conf[obj->command_code].rdata[obj->data_length - 1])
                {
                    cfg.pec_check = false;
                }
                else
                {
                    cfg.pec_check = true;
                }
            }
            cfg.data = obj->slave_conf[obj->command_code].rdata;
            cfg.read = true;
        }
        else
        {
            if (!obj->data_length)
            {
                return;
            }
            if (pmbus_cmd_param_table[obj->command_code].read_transaction_type == read_block)
            {
                cfg.len = obj->slave_conf[obj->command_code].data_length;
            }
            else
            {
                cfg.len = pmbus_cmd_param_table[obj->command_code].data_length;
            }
            cfg.data = obj->slave_conf[obj->command_code].wdata;
            cfg.read = false;
            cfg.pec_check = true;
        }
        cfg.command = obj->command_code;
        if (obj->slave_conf[obj->command_code].callback != NULL)
        {
            obj->slave_conf[obj->command_code].callback(i2c_base, &cfg);
        }
        obj->cmd_found = false;
    }
}


uint32_t pmbus_slave_init(uint32_t i2c_base, uint8_t slave_addr)
{
    uint32_t sta = status_success;
    uint32_t ic_con_params = 0;
    pmbus_cfg_t *obj = pmbus_get_cfg_obj(i2c_base);
    uint32_t sysclkHz = SystemClock_Get();
    if (obj == NULL)
    {
        return status_invalid_argument;
    }
    memset(obj->slave_conf, 0, sizeof(obj->slave_conf));
    obj->slave_addr = slave_addr;
    I2C_disableModule(i2c_base);
    I2C_disableInterrupt(i2c_base, 0xFFFFFFF);

    ic_con_params = I2C_SLAVE_MODE | I2C_TX_EMPTY_CTRL | I2C_RESTART_EN | I2C_STOP_DET_IF_MASTER_ACTIVE;
    I2C_setConfig(i2c_base, ic_con_params);
    I2C_setOwnAddress(i2c_base, slave_addr);
    I2C_initController(i2c_base, sysclkHz, 400000, I2C_DUTYCYCLE_50);
    I2C_setReceiveFIFOLevel(i2c_base, I2C_FIFO_RX1);
    I2C_enableInterrupt(i2c_base,
            I2C_IC_INTR_MASK_M_START_DET | I2C_IC_INTR_MASK_M_RD_REQ | I2C_IC_INTR_MASK_M_RX_FULL
                    | I2C_IC_INTR_MASK_M_STOP_DET);
    I2C_enableModule(i2c_base);
    return sta;

}

uint32_t pmbus_master_read(uint32_t i2c_base, uint8_t slave_address, uint8_t command, uint8_t *data, uint32_t *len)
{
    pmbus_cmd_param_t para;
    uint32_t sta = status_success;
    para = pmbus_cmd_param_table[command];
    switch (para.read_transaction_type)
    {
    case read_byte:
        sta = smbus_master_read_byte_in_command(i2c_base, slave_address, command, data);
        *len = 1;
        break;
    case read_word:
        sta = smbus_master_read_word_in_command(i2c_base, slave_address, command, (uint16_t*) data);
        *len = 2;
        break;
    case read_block:
        if (para.data_length != 0xFFFFFFFF)
        {
            sta = smbus_master_read_block_in_command(i2c_base, slave_address, command, data, para.data_length);
            *len = para.data_length;
        }
        else
        {
            sta = smbus_master_read_block_in_command(i2c_base, slave_address, command, data, *len);
        }
        break;
    case mfr_defined:
    case extended_command:
        sta = status_pmbus_not_support_cmd;
        break;
    default:
        sta = status_pmbus_not_transaction_type;
        break;
    }
    return sta;
}

uint32_t pmbus_master_write(uint32_t i2c_base, uint8_t slave_address, uint8_t command, uint8_t *data, uint32_t len)
{
    pmbus_cmd_param_t para;
    uint32_t sta = status_success;
    para = pmbus_cmd_param_table[command];
    switch (para.write_transaction_type)
    {
    case send_byte:
        sta = smbus_master_write_byte(i2c_base, slave_address, command);
        break;
    case write_byte:
        sta = smbus_master_write_byte_in_command(i2c_base, slave_address, command, *data);
        break;
    case write_word:
        sta = smbus_master_write_word_in_command(i2c_base, slave_address, command, *(uint16_t*) data);
        break;
    case write_block:
        if (para.data_length != 0xFFFFFFFF)
        {
            sta = smbus_master_write_block_in_command(i2c_base, slave_address, command, data, para.data_length);
        }
        else
        {
            sta = smbus_master_write_block_in_command(i2c_base, slave_address, command, data, len);
        }
        break;
    case mfr_defined:
    case extended_command:
        sta = status_pmbus_not_support_cmd;
        break;
    default:
        sta = status_pmbus_not_transaction_type;
        break;
    }
    return sta;
}

uint32_t pmbus_slave_command_transaction_install(uint32_t i2c_base, uint8_t command, uint8_t *wdata, uint8_t *rdata,
        uint32_t len, pmbus_complete_cb_t callback)
{
    uint32_t stat = status_success;
    pmbus_cfg_t *obj = pmbus_get_cfg_obj(i2c_base);
    if ((obj == NULL)
            || (((pmbus_cmd_param_table[command].write_transaction_type != none) && (rdata == NULL))
                    && ((pmbus_cmd_param_table[command].read_transaction_type != none) && (wdata == NULL)))
            || ((pmbus_cmd_param_table[command].data_length != 0xFFFFFFFF)
                    && (len != (pmbus_cmd_param_table[command].data_length))))
    {
        /* included pec byte, So the length needs to be increased by 1 */
        return status_invalid_argument;
    }
    if ((pmbus_cmd_param_table[command].write_transaction_type == mfr_defined)
            || (pmbus_cmd_param_table[command].read_transaction_type == mfr_defined)
            || (pmbus_cmd_param_table[command].write_transaction_type == extended_command)
            || (pmbus_cmd_param_table[command].read_transaction_type == extended_command))
    {
        return status_pmbus_not_support_cmd;
    }
    obj->slave_conf[command].is_valid = true;
    obj->slave_conf[command].wdata = wdata;
    obj->slave_conf[command].rdata = rdata;
    obj->slave_conf[command].data_length = len;
    obj->slave_conf[command].callback = callback;
    return stat;
}

uint32_t pmbus_slave_command_transaction_uninstall(uint32_t i2c_base, uint8_t command)
{
    uint32_t stat = status_success;
    pmbus_cfg_t *obj = pmbus_get_cfg_obj(i2c_base);
    if (obj == NULL)
    {
        return status_invalid_argument;
    }
    obj->slave_conf[command].is_valid = false;
    return stat;
}
