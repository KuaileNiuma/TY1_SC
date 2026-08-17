/**
 *************************************************************************************
 * @file eeprom.c
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

#include "eeprom.h"
#include "stdio.h"
uint32_t eeprom_addr_len = 0;
uint32_t eeprom_status = 0;

uint16_t eeprom_DataAddrWrite(uint32_t base, uint32_t data_addr)
{
	uint8_t addr[2] = {0};

	if (eeprom_addr_len == 2)
	{
		addr[0] = (uint8_t)((data_addr >> 8) & 0xff);
		addr[1] = (uint8_t)(data_addr & 0xff);
	}
	else if (eeprom_addr_len == 1)
	{
		addr[0] = (uint8_t)(data_addr & 0xff);
	}
	else
	{
		printf("eeprom_addr_len error %d, please init eeprom \r\n", eeprom_addr_len);
		return -1;
	}

	for(uint32_t i = 0; i < eeprom_addr_len; i++)
	{
		I2C_pollTxEmpty(base);
		I2C_putData(base, addr[i]);
	}
	return 0;
}


uint16_t eeprom_WriteData(uint32_t base, uint32_t data_addr, uint8_t *data_cmd, uint32_t data_cmd_len, I2C_NEXT_CONDITION next_cond)
{
    int32_t err = 0;
    //send addr
	eeprom_DataAddrWrite(base,data_addr);


	//send data
	if (I2C_getIcMode(base) == I2C_ICMODE_MASTER)
	{
	   for (uint32_t i = 0; i < data_cmd_len; i++)
	   {
		   I2C_pollTxEmpty(base);

		   if ((next_cond & I2C_NEXT_CONDITION_RESTART) && (i == 0))
		   {
			   I2C_putData(base, data_cmd[i]);
		   }
		   else if ((next_cond & I2C_NEXT_CONDITION_STOP) && (i == (data_cmd_len - 1)))
		   {
			   I2C_sendCmdWriteAndStop(base, data_cmd[i]);
		   }
		   else
		   {
			   I2C_putData(base, data_cmd[i]);
		   }
	   }
	}
	else
	{
	   ASSERT(0);
	}
	return err;

}

uint16_t eeprom_ReadData(uint32_t base, uint32_t data_addr, uint8_t *data_cmd, uint32_t data_cmd_len, I2C_NEXT_CONDITION next_cond)
{
	int32_t err = 0;
	uint32_t retry_cnt = 0;
	//send addr
	eeprom_DataAddrWrite(base,data_addr);

	//recv data
	if (I2C_getIcMode(base) == I2C_ICMODE_MASTER)
	{
		for (uint32_t i = 0; i < data_cmd_len; i++)
		{
			I2C_pollTxEmpty(base);

			if ((next_cond & I2C_NEXT_CONDITION_RESTART) && (i == 0))
			{
				I2C_sendCmdRestartAndRead(base);
			}
			else if ((next_cond & I2C_NEXT_CONDITION_STOP) && (i == (data_cmd_len - 1)))
			{
				I2C_sendCmdReadAndStop(base);
			}
			else
			{
				I2C_sendCmdRead(base);
			}

			I2C_pollRxFull(base);

			*data_cmd = I2C_getData(base);
			data_cmd++;
		}
	}
	else
	{
		ASSERT(0);
	}
	return 0;

}


uint16_t checkBusStatus(uint32_t base)
{

    if(I2C_isBusBusy(base))
    {
        return ERROR_BUS_BUSY;
    }

    if(I2C_getStopConditionStatus(base))
    {
        return ERROR_STOP_NOT_READY;
    }

    return I2C_LINK_SUCCESS;
}


uint16_t handleNACK(uint32_t base)
{
    if(I2C_getInterruptRawStatus(base) & I2C_INT_NO_ACK)
    {
    	I2C_clearInterruptTxAbrt(base);

        return ERROR_NACK_RECEIVED;
    }

    return I2C_LINK_SUCCESS;
}


void eeprom_init(uint32_t addr_len)
{
	eeprom_addr_len = addr_len;
}

#ifdef __cplusplus
}
#endif




