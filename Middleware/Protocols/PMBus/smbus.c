/*
 * Copyright (c) 2026.02
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "smbus.h"
#include <string.h>
#define SMBUS_BUFF_SIZE_MAX   (256)

static uint8_t smbus_pec_crc8(uint8_t *data, uint32_t len);



uint32_t i2c_master_write(uint32_t i2c_base, const uint16_t device_address,
                            uint8_t *buf, const uint32_t size)
{
	uint32_t stat = 0;
	uint32_t i = 0;
	if (I2C_WaitForBusy(i2c_base))
	{
		return 1;
	}

	I2C_SetAddress(i2c_base, device_address);

	if (I2C_getIcMode(i2c_base) == I2C_ICMODE_MASTER)
	{
		for (i = 0; i < size; i++)
		{
			if (!I2C_pollTxEmpty(i2c_base))
			{
				stat = 3;
				break;
			}
			if (i == (size - 1))
		   {
			   I2C_sendCmdWriteAndStop(i2c_base, buf[i]);
		   }
		   else
		   {
			   I2C_putData(i2c_base, buf[i]);
		   }
		}
	}
	else
	{
		stat = 2;
	}
	return stat;
}







uint32_t i2c_master_read(uint32_t i2c_base, const uint16_t device_address,
                            uint8_t *buf, const uint32_t size)
{
	uint32_t stat = 0;
	if (I2C_WaitForBusy(i2c_base))
	{
		return 1;
	}

	I2C_SetAddress(i2c_base, device_address);

	if (I2C_getIcMode(i2c_base) == I2C_ICMODE_MASTER)
	{
		for (uint32_t i = 0; i < size; i++)
		{
			if (!I2C_pollTxEmpty(i2c_base))
			{
				stat = 3;
				break;
			}

			if (  i == (size - 1))
			{
				I2C_sendCmdReadAndStop(i2c_base);
			}
			else
			{
				I2C_sendCmdRead(i2c_base);
			}

			if (!I2C_pollRxFull(i2c_base))
			{
				stat = 4;
				break;
		    }

			buf[i] = I2C_getData(i2c_base);
		}
	}
	else
	{
		stat = 2;
	}
	return stat;
}

typedef enum
{
    I2C_NEXT_CONDITION_NONE          = 0x01,
    I2C_NEXT_CONDITION_STOP          = 0x02,
    I2C_NEXT_CONDITION_RESTART       = 0x04,
} I2C_NEXT_CONDITION;
uint32_t i2c_master_transfer(uint32_t i2c_base, const uint16_t device_address,
                            uint8_t *buf, const uint32_t size, I2C_NEXT_CONDITION next_cond)
{
	uint32_t stat = 0;

	if (I2C_getIcMode(i2c_base) == I2C_ICMODE_MASTER)
	{
		for (uint32_t i = 0; i < size; i++)
		{
			I2C_pollTxEmpty(i2c_base);
			if ((next_cond & I2C_NEXT_CONDITION_RESTART) && (i == 0))
			{
				I2C_sendCmdRestartAndWrite(i2c_base, buf[i]);
			}
			else if ((next_cond & I2C_NEXT_CONDITION_STOP) && (i == (size - 1)))
			{
			   I2C_sendCmdWriteAndStop(i2c_base, buf[i]);
			}
			else
			{
			   I2C_putData(i2c_base, buf[i]);
			}
		}
	}
	else
	{
		stat = 1;
	}


	return stat;
}



uint32_t i2c_master_receive(uint32_t i2c_base, const uint16_t device_address,
        uint8_t *buf, const uint32_t size, I2C_NEXT_CONDITION next_cond)
{
	uint32_t stat = 0;
	if (I2C_getIcMode(i2c_base) == I2C_ICMODE_MASTER)
	{
		for (uint32_t i = 0; i < size; i++)
		{
			I2C_pollTxEmpty(i2c_base);

			if ((next_cond & I2C_NEXT_CONDITION_RESTART) && (i == 0))
			{
				I2C_sendCmdRestartAndRead(i2c_base);
			}
			else if ((next_cond & I2C_NEXT_CONDITION_STOP) && (i == (size - 1)))
			{
				I2C_sendCmdReadAndStop(i2c_base);
			}
			else
			{
				I2C_sendCmdRead(i2c_base);
			}

			I2C_pollRxFull(i2c_base);
			buf[i] = I2C_getData(i2c_base);
		}
	}
	else
	{
		stat = 1;
	}


	return stat;
}


uint32_t smbus_master_write_byte(uint32_t i2c_base, uint8_t slave_address,
                                       uint8_t data)
{
	uint32_t stat;
    uint8_t buf[3];
    /* addr + rw bit*/
    buf[0] = (slave_address << 1);
    buf[1] = data;
    buf[2] = smbus_pec_crc8(buf, sizeof(buf) -1);
    stat = i2c_master_write(i2c_base, (const uint16_t)slave_address, &buf[1], sizeof(buf) - 1);
    return stat;
}


uint32_t smbus_master_read_byte(uint32_t i2c_base, uint8_t slave_address,
                                      uint8_t *data)
{
    uint8_t buf[3];
    uint32_t stat;
    uint8_t pec;
    /* addr + rw bit*/
    buf[0] = (slave_address << 1) | 1;
    stat = i2c_master_read(i2c_base, (const uint16_t)slave_address, &buf[1], sizeof(buf) - 1);
    if (stat == 0)
    {
        pec = smbus_pec_crc8(buf, sizeof(buf) - 1);
        if (pec == buf[2])
        {
            *data = buf[1];
        } else
        {
            stat = 	1;
        }
    }
    return stat;
}
uint32_t smbus_master_write_byte_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                  uint8_t command, uint8_t data)
{
	uint32_t stat;
	uint8_t buf[4];
	/* addr + rw bit*/
	buf[0] = (slave_address << 1);
	buf[1] = command;
	buf[2] = data;
	buf[3] = smbus_pec_crc8(buf, sizeof(buf) - 1);
	stat = i2c_master_write(i2c_base, (const uint16_t)slave_address, &buf[1], sizeof(buf) - 1);
	return stat;

}

uint32_t smbus_master_write_word_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                  uint8_t command,  uint16_t data)
{
	uint32_t stat;
	uint8_t buf[5];
	/* addr + rw bit*/
	buf[0] = (slave_address << 1);
	buf[1] = command;
	*(uint16_t *)(&buf[2]) = data;
	buf[4] = smbus_pec_crc8(buf, sizeof(buf) - 1);
	stat = i2c_master_write(i2c_base, (const uint16_t)slave_address, &buf[1], sizeof(buf) - 1);
	return stat;
	return 0;
}

uint32_t smbus_master_read_byte_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                 uint8_t command, uint8_t *data)
{
	uint32_t stat;
    uint8_t pec;
    uint8_t buf[5];
    /* addr + rw bit*/
    buf[0] = (slave_address << 1);
    buf[1] = command;

	if (I2C_WaitForBusy(i2c_base))
	{
		return 1;
	}

	/*Set Slave Address*/
	I2C_SetAddress(i2c_base, slave_address);

    /* write command code in smbus spec*/
    stat =  i2c_master_transfer(i2c_base, (const uint16_t)slave_address, &command, sizeof(uint8_t), I2C_NEXT_CONDITION_NONE);

    if (stat == 0)
    {
        /* read */
        buf[2] = (slave_address << 1) | 0x01;
        /* now change dir,restart, read the byte */
    	stat = i2c_master_receive(i2c_base, (const uint16_t)slave_address, &buf[3], 2, I2C_NEXT_CONDITION_RESTART|I2C_NEXT_CONDITION_STOP);
    	if (stat == 0)
    	{
    		 pec = smbus_pec_crc8(buf, sizeof(buf) - 1);
			if (pec == buf[4])
			{
				*data = buf[3];
			} else
			{
				stat = 2;
			}
    	}
    }
    return stat;
}

uint32_t smbus_master_read_word_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                 uint8_t command, uint16_t *data)
{
	uint32_t stat;
    uint8_t pec;
    uint8_t buf[6];
    /* addr + rw bit*/
    buf[0] = (slave_address << 1);
    buf[1] = command;

	if (I2C_WaitForBusy(i2c_base))
	{
		return 1;
	}

	/*Set Slave Address*/
	I2C_SetAddress(i2c_base, slave_address);

    /* write command code in smbus spec*/
    stat =  i2c_master_transfer(i2c_base, (const uint16_t)slave_address, &command, sizeof(uint8_t), I2C_NEXT_CONDITION_NONE);

    if (stat == 0)
    {
        /* read */
        buf[2] = (slave_address << 1) | 0x01;
        /* now change dir,restart, read the byte */
    	stat = i2c_master_receive(i2c_base, (const uint16_t)slave_address, &buf[3], 3, I2C_NEXT_CONDITION_RESTART|I2C_NEXT_CONDITION_STOP);
    	if (stat == 0)
    	{
    		 pec = smbus_pec_crc8(buf, sizeof(buf) - 1);
			if (pec == buf[5])
			{
				*data = *(uint16_t *)&buf[3];
			} else
			{
				stat = 2;
			}
    	}
    }
    return stat;
}

uint32_t smbus_master_write_block_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                   uint8_t command, uint8_t *data, uint32_t size)
{
	uint32_t stat;
	uint8_t buf[SMBUS_BUFF_SIZE_MAX+4];
	/* frame included addr, command, data, and pec */
	assert(size > 0 && size <= (SMBUS_BUFF_SIZE_MAX));
	/* addr + rw bit*/
	buf[0] = slave_address << 1;
	buf[1] = command;
	buf[2] = size;
	memcpy(&buf[3], data, size);
	buf[size + 3] = smbus_pec_crc8(buf, size + 3);

    stat = i2c_master_write(i2c_base, (const uint16_t)slave_address, &buf[1], size + 3);
	return stat;
}

uint32_t smbus_master_read_block_in_command(uint32_t i2c_base, uint8_t slave_address,
                                                  uint8_t command, uint8_t *data, uint32_t size)
{
	uint32_t stat;
    uint8_t pec;
    uint8_t _size;
    uint16_t buf_size;
    uint8_t buf[SMBUS_BUFF_SIZE_MAX+4];
    /* frame included addr, command, data, and pec */
    assert(size > 0 && size <= (SMBUS_BUFF_SIZE_MAX));
    /* addr + rw bit*/
    buf[0] = (slave_address << 1);
    buf[1] = command;
    /* write command code in smbus spec*/
    if (I2C_WaitForBusy(i2c_base))
	{
		return 1;
	}

	/*Set Slave Address*/
	I2C_SetAddress(i2c_base, slave_address);

	/* write command code in smbus spec*/
	stat =  i2c_master_transfer(i2c_base, (const uint16_t)slave_address, &command, sizeof(uint8_t), I2C_NEXT_CONDITION_NONE);

    if (stat == 0)
    {
        /* read */
        buf[2] = (slave_address << 1) | 0x01;
        /* now change dir,restart, read the byte */
    	stat = i2c_master_receive(i2c_base, (const uint16_t)slave_address, &buf[3], 1, I2C_NEXT_CONDITION_RESTART|I2C_NEXT_CONDITION_NONE);
    	if (stat == 0)
    	{
    		_size = buf[3];
    		/* read data and pec*/
    		stat = i2c_master_receive(i2c_base, (const uint16_t)slave_address, &buf[4], _size+1, I2C_NEXT_CONDITION_STOP);
    		pec = smbus_pec_crc8(buf, _size + 4);
			if (pec == buf[_size+4])
			{
				 memcpy(data, &buf[4], size);
			} else
			{
				stat = 2;
			}
    	}
    }
	return 0;
}

uint32_t smbus_master_write(uint32_t i2c_base, uint8_t slave_address,
                                  uint8_t *data, uint32_t size)
{
	uint32_t stat;
	uint8_t buf[SMBUS_BUFF_SIZE_MAX+4];
	/* frame included addr, command, data, and pec */
	assert(size > 0 && size <= (SMBUS_BUFF_SIZE_MAX));
	/* addr + rw bit*/
	buf[0] = slave_address << 1;
	memcpy(&buf[1], data, size);
	buf[size + 1] = smbus_pec_crc8(buf, size + 1);

    stat = i2c_master_write(i2c_base, (const uint16_t)slave_address, &buf[1], size + 1);
	return 0;
}
uint32_t smbus_master_read(uint32_t i2c_base, uint8_t slave_address,
                                 uint8_t *data, uint32_t size)
{
	uint32_t stat = 0;
	uint8_t pec;
	uint8_t buf[SMBUS_BUFF_SIZE_MAX+4];
	/* frame included addr, command, data, and pec */
	assert(size > 0 && size <= (SMBUS_BUFF_SIZE_MAX));
	/* addr + rw bit*/
	buf[0] = (slave_address << 1) | 1;
	stat = i2c_master_read(i2c_base, (const uint16_t)slave_address, &buf[1], size + 1);
	if (stat == 0)
	{
		pec = smbus_pec_crc8(buf, size + 1);
		if (pec == buf[size + 1]) {
			memcpy(data, &buf[1], size);
		} else {
			stat = 1;
		}
	}
	return stat;

}


uint32_t i2c_slave_write(uint32_t i2c_base, uint8_t *buf, const uint32_t size)
{
	uint32_t stat = 0;
	uint32_t retry =0;

	if (size == 0 || (size>SMBUS_BUFF_SIZE_MAX))
	{
		return 1;
	}
    /* wait for address hit */
    retry = 0;
    while (retry < I2C_RETRY_LIMIT)
    {
    	if(I2C_getInterruptRawStatus(i2c_base) & I2C_IC_INTR_STAT_RD_REQ)
    	{
    		I2C_clearInterruptRdReq(i2c_base);
    		break;
    	}
        retry++;
    }
    if (retry > I2C_RETRY_LIMIT-1)
    {
            return 2;
    }

	for (int i = 0; i < size; i++)
	{
		I2C_pollTxEmpty(i2c_base);
        I2C_putData(i2c_base, buf[i++]);
	}
	return stat;
}

uint32_t i2c_slave_read(uint32_t i2c_base, uint8_t *buf, const uint32_t size)
{
	uint32_t stat = 0;
	uint32_t retry =0;
	int i = 0;
	if (size == 0 || (size>SMBUS_BUFF_SIZE_MAX))
	{
		return 1;
	}
	while(retry < I2C_RETRY_LIMIT)
	{
		 if ((I2C_getIcStatus(i2c_base) & I2C_ICSTS_RFNE) == I2C_ICSTS_RFNE)
		 {
			 buf[i++] = I2C_getData(i2c_base);
		 }
		 retry++;
	}
    if (retry > I2C_RETRY_LIMIT-1)
    {
            return 2;
    }
	return stat;
}
uint32_t smbus_slave_write(uint32_t i2c_base, uint8_t *data, uint32_t size)
{
	uint32_t stat;
    uint8_t buf[SMBUS_BUFF_SIZE_MAX+4];
    uint16_t buf_size;
    uint8_t slave_address;
    /* frame included addr, data, and pec */
    assert(size > 0 && size <= (SMBUS_BUFF_SIZE_MAX + 3));
    slave_address = I2C_getOwnAddress(i2c_base);
    /* addr + rw bit*/
    buf[0] = (slave_address << 1) | 1;
    memcpy(&buf[1], data, size);
    buf[size + 1] = smbus_pec_crc8(buf, size + 1);
    buf_size = size + 1;
    stat = i2c_slave_write(i2c_base, &buf[1], buf_size);
    return stat;
}

uint32_t smbus_slave_read(uint32_t i2c_base, uint8_t *data, uint32_t size)
{
	uint32_t stat;
	uint8_t pec;
    uint8_t buf[SMBUS_BUFF_SIZE_MAX+4];
    uint16_t buf_size;
    uint8_t slave_address;
    /* frame included addr, data, and pec */
    assert(size > 0 && size <= (SMBUS_BUFF_SIZE_MAX + 3));
    slave_address = I2C_getOwnAddress(i2c_base);
    /* addr + rw bit*/
    buf[0] = (slave_address << 1);
    stat = i2c_slave_read(i2c_base, &buf[1], size + 1);
    if (stat == 0)
    {
        pec = smbus_pec_crc8(buf, size + 1);
        if (pec == buf[size + 1])
        {
            memcpy(data, &buf[1], size);
        }
        else
        {
            stat = 1;
        }
    }
    return stat;
	return 0;
}
const uint8_t crc8_table[256] = {
    0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15,
    0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D,
    0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65,
    0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
    0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5,
    0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
    0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85,
    0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
    0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2,
    0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
    0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2,
    0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
    0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32,
    0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
    0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42,
    0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
    0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C,
    0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
    0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC,
    0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
    0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C,
    0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
    0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C,
    0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
    0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B,
    0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
    0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B,
    0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
    0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB,
    0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
    0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB,
    0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3
};
static uint8_t smbus_pec_crc8(uint8_t *data, uint32_t len)
{
    /* The PEC is a CRC-8 error-checking byte, calculated on all the message bytes (including addresses and read/write bits) */
    uint32_t i;
    uint8_t crc = 0x00;
    while (len--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; i++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ 0x07;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

