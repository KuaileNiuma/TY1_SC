/**
 *************************************************************************************
 * @file w25q64.c
 * @brief This file contains the source file.
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


#ifdef __cplusplus
extern "C"{
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


#include "w25q64.h"


#define FLASH_SECTOR_SIZE       (0x00001000)
#define FLASH_PAGE_SIZE         (0x00000100)


typedef struct
{
	uint8_t *send_cmd;
	uint32_t send_cmd_len;
	uint8_t *send_data;
	uint32_t send_data_len;
	uint8_t *rcv_data;
	uint32_t rcv_data_len;
} TRANSFER_INFO;


void w25q64_polling_transfer(uint32_t base, TRANSFER_INFO *transfer_info)
{
	uint32_t tx_data = 0;
    uint32_t tx_index = 0;
    uint32_t rx_index = 0;
    uint32_t tx_len = transfer_info->send_cmd_len + transfer_info->send_data_len;
    uint32_t rx_len = transfer_info->rcv_data_len;
    uint32_t total_len = tx_len + rx_len;

    //SPI_csEnable(base);
    // Send and receive complete?
    while((tx_index != total_len) || (rx_index != total_len))
    {
    	// Check transmit FIFO is not full
    	while(SPI_getStatus(base) & SPI_SR_TFNF)
        {
    		// Check whether enough data is being sent
            if(tx_index < tx_len)
            {
            	// send cmd
                if(tx_index <= transfer_info->send_cmd_len - 1)
                {
                    tx_data = transfer_info->send_cmd[tx_index];
                }
                // send data
                else
                {
                	tx_data = transfer_info->send_data[tx_index - transfer_info->send_cmd_len];
                }
            }
            // Send virtual data
            else if((tx_index >= tx_len) && (tx_index < total_len))
            {
            	tx_data = 0xff;
            }
            // sent enough data
            else
            {
                break;
            }

            SPI_writeDataNonBlocking32(base, tx_data);
            tx_index++;
            if(rx_index < tx_len)
            {
            	//read virtual data
            	SPI_readDataBlockingFIFO32(base);
                rx_index++;
            }
            else if((rx_index >= tx_len) && (rx_index < total_len))
            {
            	// read data
            	transfer_info->rcv_data[rx_index - tx_len] = SPI_readDataBlockingFIFO32(base);
            	rx_index++;
            }
        }
    }

    /* deselect device */
    //SPI_csDisable(base);
}

uint32_t w25q64_write_reg(uint32_t base, uint8_t reg, uint8_t *data, uint32_t len)
{
	TRANSFER_INFO transfer_info = {0};
    uint8_t send_cmd[1] = {0};

    send_cmd[0] = reg;
    transfer_info.send_cmd = send_cmd;
    transfer_info.send_cmd_len = sizeof(send_cmd);

    transfer_info.send_data = data;
    transfer_info.send_data_len = len;

    CS_LOW;
    w25q64_polling_transfer(base, &transfer_info);
    while((SPI_getStatus(base)&SPI_SR_TFE)== 0);
    while(SPI_isBusy(base));
    CS_HIGH;
    return 0;
}

uint32_t w25q64_read_reg(uint32_t base, uint8_t reg, uint8_t *data, uint32_t len)
{
	TRANSFER_INFO transfer_info = {0};
    uint8_t send_cmd[1] = {0};

    send_cmd[0] = reg;
    transfer_info.send_cmd = send_cmd;
    transfer_info.send_cmd_len = sizeof(send_cmd);

    transfer_info.rcv_data = data;
    transfer_info.rcv_data_len = len;
    CS_LOW;
    w25q64_polling_transfer(base, &transfer_info);
    while((SPI_getStatus(base)&SPI_SR_TFE)== 0);
    while(SPI_isBusy(base));
    CS_HIGH;
    return 0;
}

uint32_t w25q64_read_jedec_id(uint32_t base)
{
    uint8_t rcv_data[3] = {0};

    w25q64_read_reg(base, READ_JEDEC_ID, rcv_data, sizeof(rcv_data));

    return (rcv_data[0] << 16 | rcv_data[1] << 8 | rcv_data[2]) & 0x00ffffff;
}

uint32_t w25q64_read_device_id(uint32_t base)
{
	TRANSFER_INFO transfer_info = {0};
    uint8_t send_cmd[4] = {0x90, 0x90, 0x90, 0x90};
    uint8_t rcv_data[2] = {0};

    transfer_info.send_cmd = send_cmd;
    transfer_info.send_cmd_len = sizeof(send_cmd);

    transfer_info.rcv_data = rcv_data;
    transfer_info.rcv_data_len = sizeof(rcv_data);
    CS_LOW;
    w25q64_polling_transfer(base, &transfer_info);
    while((SPI_getStatus(base)&SPI_SR_TFE)== 0);
    while(SPI_isBusy(base));
    CS_HIGH;
    return (rcv_data[0] << 8 | rcv_data[1]) & 0x0000ffff;
}

int32_t w25q64_wait_ready(uint32_t base)
{
    uint32_t status = 0;
    uint8_t r_data = 0;

    do
    {
        w25q64_read_reg(base, READ_STATUS_REG1, &r_data, 1);
    } while (r_data & 0x01);// Status Register 1 Bit 0

    return 0;
}



int32_t w25q64_write_enable(uint32_t dev)
{
    uint32_t status = 0;
    uint8_t w_data[8] = {0};
	uint8_t r_data = 0;

    do
    {
        w25q64_write_reg(dev, WRITE_ENABLE, (uint8_t *)&w_data, 0);

        w25q64_read_reg(dev, READ_STATUS_REG1, &r_data, 1);

        // clear protection bits
        //  Write Protect. and Write Enable.
        if ((r_data & 0xfc) && (r_data & 0x02))
        {
            w_data[1] = 0;

            w25q64_write_reg(dev, WRITE_STATUS_REG, (uint8_t *)&w_data, 1);

            r_data = 0;
        }
    } while (r_data != 0x02);

    return 0;
}

int32_t w25q64_write_disable(uint32_t dev)
{
    uint32_t status = 0;
    uint8_t w_data[8], r_data = 0;

    do
    {
        w25q64_write_reg(dev, WRITE_DISABLE, (uint8_t *)&w_data, 0);

        w25q64_read_reg(dev, READ_STATUS_REG1, &r_data, 1);

    } while (r_data & 0x02);// Status Register 1 Bit 1

    return 0;

}

int32_t w25q64_erase(uint32_t spi_base, uint32_t address, uint32_t size)
{
    uint32_t last_address;
    uint32_t earse_sector_counts = 0;
    uint8_t cmd[4] = {0};
	TRANSFER_INFO transfer_info = {0};


    // start address of last sector
    last_address = (address + size) & (~(FLASH_SECTOR_SIZE - 1));

    // start address of first sector
    address &= ~(FLASH_SECTOR_SIZE - 1);

    do 
    {
        if (w25q64_write_enable(spi_base) != 0)
        {
            return -1;
        }

        if (w25q64_wait_ready(spi_base) != 0)
        {
            return -1;
        }

        cmd[0] = SECTOR_ERASE;
        cmd[1] = (address >> 16) & 0xff;
        cmd[2] = (address >> 8) & 0xff;
        cmd[3] =  address & 0xff;

        transfer_info.send_cmd = cmd;
        transfer_info.send_cmd_len = sizeof(cmd);
        CS_LOW;
        w25q64_polling_transfer(spi_base, &transfer_info);
        while((SPI_getStatus(spi_base)&SPI_SR_TFE)== 0);
        while(SPI_isBusy(spi_base));
        CS_HIGH;
        address += FLASH_SECTOR_SIZE;
        earse_sector_counts++;
    } while (address <= last_address);

    if (w25q64_wait_ready(spi_base) != 0)
    {
        return -1;
    }

    if (w25q64_write_disable(spi_base) != 0)
    {
        return -1;
    }

    return earse_sector_counts;
}

int32_t w25q64_write(uint32_t dev, uint32_t address, uint32_t size, const void *data)
{
    uint8_t cmd[4] = {0};
    uint32_t next_write_data_len = 0;
    TRANSFER_INFO transfer_info = {0};

    if (w25q64_wait_ready(dev) != 0)
    {
        return -1;
    }

    next_write_data_len = FLASH_PAGE_SIZE - (address & (FLASH_PAGE_SIZE - 1));

    do
    {
        // send write enable command to flash
        if (w25q64_write_enable(dev) != 0)
        {
            return -1;
        }
        if (w25q64_wait_ready(dev) != 0)
        {
            return -1;
        }

        next_write_data_len = next_write_data_len < size ? next_write_data_len : size;

        cmd[0] = PAGE_PROGRAM;
        cmd[1] = (address >> 16) & 0xff;
        cmd[2] = (address >> 8) & 0xff;
        cmd[3] = address  & 0xff;

        transfer_info.send_cmd = cmd;
        transfer_info.send_cmd_len = sizeof(cmd);

        transfer_info.send_data = (uint8_t *)data;
        transfer_info.send_data_len = next_write_data_len;
        CS_LOW;
        w25q64_polling_transfer(dev, &transfer_info);
        while(!(SPI_getStatus(dev)&SPI_SR_TFE));
        while(SPI_isBusy(dev));
        CS_HIGH;
        size -= next_write_data_len;
        address += next_write_data_len;
        data += next_write_data_len;
        next_write_data_len = FLASH_PAGE_SIZE;

    } while (size);

    if (w25q64_wait_ready(dev) != 0)
    {
        return -1;
    }

    if (w25q64_write_disable(dev) != 0)
    {
        return -1;
    }

    return 0;
}

int32_t w25q64_read(uint32_t dev, uint32_t address, uint32_t size, void *data)
{
    TRANSFER_INFO stSend = {0};
    TRANSFER_INFO stCmd = {0};
    TRANSFER_INFO stRecv = {0};
    uint8_t cmd[4] = {0};

    uint32_t next_read_len = 0;
    uint32_t size_orig = size;
    TRANSFER_INFO transfer_info = {0};

    next_read_len = FLASH_PAGE_SIZE - (address & (FLASH_PAGE_SIZE - 1));

    do
    {
        if (w25q64_wait_ready(dev) != 0)
        {
            return -1;
        }

        next_read_len = next_read_len < size ? next_read_len : size;

        cmd[0] = READ_DATA;
        cmd[1] = (address >> 16) & 0xff;
        cmd[2] = (address >> 8) & 0xff;
        cmd[3] = address  & 0xff;

        transfer_info.send_cmd = cmd;
        transfer_info.send_cmd_len = sizeof(cmd);

        transfer_info.rcv_data = (uint8_t *)data;
        transfer_info.rcv_data_len = next_read_len;
        CS_LOW;
        w25q64_polling_transfer(dev, &transfer_info);
        while((SPI_getStatus(dev)&SPI_SR_TFE)== 0);
        while(SPI_isBusy(dev));
        CS_HIGH;
        size -= next_read_len;
        address += next_read_len;
        data += next_read_len;
        next_read_len = FLASH_PAGE_SIZE;

    } while (size);

    return 0;
}
#ifdef __cplusplus
}
#endif

