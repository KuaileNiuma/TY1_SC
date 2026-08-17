/** 
 *************************************************************************************
 * @file qFlash.h
 * @brief This file contains the definition of qFlash driver.
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

#ifndef __QFLASH_H
#define __QFLASH_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif


#include "hw_common.h"
#include "qspi.h"
#include "spi.h"

#define FLASH_WriteAddress        (0x000000)
#define FLASH_Security1Address    (0x001000)
#define FLASH_Security2Address    (0x002000)
#define FLASH_Security3Address    (0x003000)
#define FLASH_ReadAddress         FLASH_WriteAddress
#define FLASH_SectorToErase       FLASH_WriteAddress
#define qFLASH_CMD_ERSCUR         0x44  /*!< Erase Security Registers(PY25Q64) */
#define qFLASH_CMD_PRSCUR         0x42  /*!< Program Security Registers(PY25Q64) */
#define qFLASH_CMD_RDSCUR         0x48  /*!< Read Security Registers(PY25Q64) */
#define qFLASH_CMD_WRITE          0x02  /*!< Write to Memory instruction */
#define qFLASH_CMD_WRSR1          0x01  /*!< Write Status Register 1 instruction */
#define qFLASH_CMD_WRSR2          0x31  /*!< Write Status Register 2 instruction */
#define qFLASH_CMD_WREN           0x06  /*!< Write enable instruction */
#define qFLASH_CMD_READ           0x03  /*!< Read from Memory instruction */
#define qFLASH_CMD_ISDR           0xBB  /*!< Dual I/O Read instruction , INST Standard*/
#define qFLASH_CMD_IASDR          0x3B  /*!< Dual I/O Read instruction , INST and ADDR Standard*/
#define qFLASH_CMD_ISQR           0xEB  /*!< Quad I/O Read instruction , INST standard*/
#define qFLASH_CMD_IASQR          0x6B  /*!< Quad I/O Read instruction , INST and ADDR Standard*/
#define qFlash_CMD_QIOW           0x32  /*!< Quad I/O Page program instruction */
#define qFLASH_CMD_RDSR1          0x05  /*!< Read Status Register 1 instruction  */
#define qFLASH_CMD_RDSR2          0x35  /*!< Read Status Register 2 instruction  */
#define qFLASH_CMD_RDID           0x9F  /*!< Read identification */
#define qFLASH_CMD_SE             0x20  /*!< Sector Erase instruction */
#define qFLASH_CMD_BE             0xC7  /*!< Bulk Erase instruction */

#define qFLASH_WIP_FLAG           0x01  /*!< Write In Progress (WIP) flag */
#define qFlash_WREN_FLAG          0x02  /*!< Write Enable flag */

#define qFLASH_DUMMY_BYTE         0x00
#define qFLASH_SPI_PAGESIZE       256

#define qFLASH_W25Q32_ID          0xEF4016
#define sFLASH_GD25Q256_ID        0xC84019

static inline void QSPI_Std_TxRx(uint32_t qspi_base, uint8_t *pTxdata,
		uint8_t *pRxdata, uint32_t Size)
{

	uint8_t avalible, count;
	uint8_t Txsize = Size;
	uint8_t Rxsize = Size;

	if (Size > QSPI_FIFO_DEPTH || Size == 0)
		return;

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//Disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	HWREG(qspi_base+QSPI_O_CTRLR0) = (HWREG(qspi_base+QSPI_O_CTRLR0)
			& (~(QSPI_CTRLR0_MQSEL_Msk | QSPI_CTRLR0_DFS_Msk
					| QSPI_CTRLR0_SPI_FRF_Msk)))
			| (QSPI_CTRLR0_MQSEL_QSPI | QSPI_DataFrameSize_8b | QSPI_FRF_STD);

	HWREG(qspi_base+QSPI_O_CTRLR1) = (HWREG(qspi_base+QSPI_O_CTRLR1)
			& (~(QSPI_CTRLR1_NDF_Msk))) | (Rxsize);
	QSPI_setMode(qspi_base, QSPI_CTRLR0_TMOD_TX_AND_RX);

	HWREG(qspi_base+QSPI_O_CTRLR0) = (HWREG(qspi_base+QSPI_O_CTRLR0)
			& (~(QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk | QSPI_SPI_CTRLR0_INST_L_Msk
					| QSPI_SPI_CTRLR0_ADDR_L_Msk
					| QSPI_SPI_CTRLR0_TRANS_TYPE_Msk)))
			| (QSPI_WAIT_CYCLES_0 | QSPI_Inst_Length_NoInst
					| QSPI_Addr_Length_NoAddr | QSPI_INST_ADDR_TYPE_STANDARD);

	HWREG(qspi_base+QSPI_O_TXFTLR) = (HWREG(qspi_base+QSPI_O_TXFTLR)
			& (~(QSPI_TXFTLR_TXFTHR_Msk))) | (Size - 1);

	//Enable QSPI
	QSPI_enableModule(qspi_base);
	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	while (Txsize--)
	{
		QSPI_TxDataU8(qspi_base, pTxdata++);
	}

	while (Rxsize)
	{
		avalible = HWREG(qspi_base+QSPI_O_RXFLR);
		count = Rxsize > avalible ? avalible : Rxsize;
		Rxsize -= count;
		while (count--)
		{
			QSPI_RxDataU8(qspi_base, pRxdata++);
		}
	}

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;
}

static inline void QSPI_Std_Tx(uint32_t qspi_base, uint8_t *pTxdata,
		uint32_t Txsize)
{

	if (Txsize > QSPI_FIFO_DEPTH || Txsize == 0)
		return;

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//Disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	HWREG(qspi_base + QSPI_O_CTRLR0) = (HWREG(qspi_base + QSPI_O_CTRLR0)
			& ~(QSPI_CTRLR0_MQSEL_Msk | QSPI_CTRLR0_DFS_Msk
					| QSPI_CTRLR0_SPI_FRF_Msk | QSPI_CTRLR0_TMOD_Msk))
			| (QSPI_CTRLR0_MQSEL_QSPI | QSPI_DataFrameSize_8b | QSPI_FRF_STD
					| QSPI_CTRLR0_TMOD_TX_AND_RX);

	HWREG(qspi_base + QSPI_O_SPI_CTRLR0) =
			(HWREG(qspi_base + QSPI_O_SPI_CTRLR0)
					& ~(QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk
							| QSPI_SPI_CTRLR0_INST_L_Msk
							| QSPI_SPI_CTRLR0_ADDR_L_Msk
							| QSPI_SPI_CTRLR0_TRANS_TYPE_Msk))
					| (QSPI_WAIT_CYCLES_0 | QSPI_Inst_Length_NoInst
							| QSPI_Addr_Length_NoAddr
							| QSPI_INST_ADDR_TYPE_STANDARD);

	HWREG(qspi_base + QSPI_O_TXFTLR) = (HWREG(qspi_base + QSPI_O_TXFTLR)
			& ~(QSPI_TXFTLR_TXFTHR_Msk)) | (Txsize - 1);

	//Enable QSPI
	QSPI_enableModule(qspi_base);
	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	while (Txsize--)
	{
		QSPI_TxDataU8(qspi_base, pTxdata++);
	}

	while (QSPI_GetFlagStatus(qspi_base, QSPI_FLAG_TFE) == RESET)
	{
	}
	while (QSPI_GetFlagStatus(qspi_base, QSPI_FLAG_BUSY) == SET)
	{
	}

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

}

static inline uint8_t qFlsah_ReadSR2(uint32_t qspi_base)
{
	uint8_t cmdrdsr[2] =
	{ qFLASH_CMD_RDSR2, qFLASH_DUMMY_BYTE };
	uint8_t status[2] =
	{ 0, 0 };

	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	/*!< Loop as long as the memory is busy with a write cycle */
	QSPI_Std_TxRx(qspi_base, cmdrdsr, status, 2);

	/*!< Deselect the FLASH: Chip Select high */
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	return (status[1]);
}

static inline void qFlash_WriteSR2(uint32_t qspi_base, uint8_t sr)
{
	uint8_t cmdwsr[2] =
	{ qFLASH_CMD_WRSR2, sr };

	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	/*!< Loop as long as the memory is busy with a write cycle */
	QSPI_Std_Tx(qspi_base, &cmdwsr[0], 2);

	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;
}

static inline void qFLASH_WaitForWriteEnd(uint32_t qspi_base)
{
	uint8_t cmdrdsr[2] =
	{ qFLASH_CMD_RDSR1, qFLASH_DUMMY_BYTE };
	uint8_t status[2] =
	{ 0, 0 };
	uint8_t flashstatus = 0;

	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	/*!< Loop as long as the memory is busy with a write cycle */
	do
	{
		QSPI_Std_TxRx(qspi_base, cmdrdsr, status, 2);
		flashstatus = status[1];
	} while (flashstatus & qFLASH_WIP_FLAG); /* Write in progress */

	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

}

static inline void qFLASH_WriteEnable(uint32_t qspi_base)
{
	uint8_t cmdwen = qFLASH_CMD_WREN;
	uint8_t cmdrdsr[2] =
	{ qFLASH_CMD_RDSR1, qFLASH_DUMMY_BYTE };
	uint8_t status[2] =
	{ 0, 0 };
	uint8_t flashstatus;

	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	QSPI_Std_Tx(qspi_base, &cmdwen, 1);
#if simulationTest == 0

	do
	{
		QSPI_Std_TxRx(qspi_base, cmdrdsr, status, 2);
		flashstatus = status[1];
	} while (!(flashstatus & qFlash_WREN_FLAG));

#endif
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;
}

static inline void qFLASH_EraseSector(uint32_t qspi_base, uint32_t SectorAddr)
{
	uint8_t cmdse[4] =
	{ qFLASH_CMD_SE, 0, 0, 0 };

	cmdse[1] = (SectorAddr & 0xFF0000) >> 16;
	cmdse[2] = (SectorAddr & 0xFF00) >> 8;
	cmdse[3] = (SectorAddr & 0xFF);

	/*!< Send write enable instruction */
	qFLASH_WriteEnable(qspi_base);
	qFLASH_WaitForWriteEnd(qspi_base);

	/*!< Sector Erase */
	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	QSPI_Std_Tx(qspi_base, cmdse, 4);

	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	/*!< Wait the end of Flash writing */
	qFLASH_WaitForWriteEnd(qspi_base);
}

static inline void qFlash_QuadMode(uint32_t qspi_base, FunctionalState NewState)
{
	volatile uint8_t sr;

	sr = qFlsah_ReadSR2(qspi_base);
	if (NewState != DISABLE)
	{
		sr |= (1 << 1);  // quad enable, bit6 in sr
	}
	else
	{
		sr &= ~(1 << 1);  // quad disable, bit6 in sr
	}
	qFLASH_WriteEnable(qspi_base);
#if simulationTest == 0
	qFLASH_WaitForWriteEnd(qspi_base);
#endif
	qFlash_WriteSR2(qspi_base, sr);
#if simulationTest == 0
	qFLASH_WaitForWriteEnd(qspi_base);
#endif
	sr = qFlsah_ReadSR2(qspi_base);
}

static inline void qFLASH_WritePage(uint32_t qspi_base, uint8_t *pBuffer,
		uint32_t WriteAddr, uint16_t NumByteToWrite)
{

	uint8_t avalible;
	uint8_t count;

	/*!< Enable the write access to the FLASH */
	qFLASH_WriteEnable(qspi_base);
#if simulationTest == 0
	qFLASH_WaitForWriteEnd(qspi_base);
#endif

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//Disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	HWREG(qspi_base + QSPI_O_CTRLR0) = (HWREG(qspi_base + QSPI_O_CTRLR0)
			& ~(QSPI_CTRLR0_MQSEL_Msk | QSPI_CTRLR0_DFS_Msk
					| QSPI_CTRLR0_SPI_FRF_Msk))
			| (QSPI_CTRLR0_MQSEL_QSPI | QSPI_DataFrameSize_8b | QSPI_FRF_QUAD);

	HWREG(qspi_base + QSPI_O_CTRLR1) = (HWREG(qspi_base + QSPI_O_CTRLR1)
			& ~(QSPI_CTRLR1_NDF_Msk)) | (NumByteToWrite);

	QSPI_setMode(qspi_base, QSPI_CTRLR0_TMOD_TX_ONLY);

	HWREG(qspi_base + QSPI_O_SPI_CTRLR0) =
			(HWREG(qspi_base + QSPI_O_SPI_CTRLR0)
					& ~(QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk
							| QSPI_SPI_CTRLR0_INST_L_Msk
							| QSPI_SPI_CTRLR0_ADDR_L_Msk
							| QSPI_SPI_CTRLR0_TRANS_TYPE_Msk))
					| (QSPI_WAIT_CYCLES_0 | QSPI_Inst_Length_8b
							| QSPI_Addr_Length_24b
							| QSPI_INST_ADDR_TYPE_STANDARD);

	HWREG(qspi_base + QSPI_O_TXFTLR) = (HWREG(qspi_base + QSPI_O_TXFTLR)
			& ~(QSPI_TXFTLR_TXFTHR_Msk)) | (0);

	//Enable QSPI
	QSPI_enableModule(qspi_base);
	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	//Send instruction and address
	HWREG(qspi_base+QSPI_O_DR) = qFlash_CMD_QIOW;
	HWREG(qspi_base+QSPI_O_DR) = WriteAddr;

	while (NumByteToWrite)
	{
		avalible = QSPI_FIFO_DEPTH - QSPI_ReadTxFIFOLevel(qspi_base);
		count = NumByteToWrite > avalible ? avalible : NumByteToWrite;
		NumByteToWrite -= count;
		while (count--)
		{
			HWREG(qspi_base+QSPI_O_DR) = *(pBuffer++);
		}
	}

	while (QSPI_checkIntFlag(qspi_base,QSPI_FLAG_BUSY) == SET)
	{
	}

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	/*!< Wait the end of Flash writing */
	qFLASH_WaitForWriteEnd(qspi_base);
}

static inline void qFLASH_WritePageStandard(uint32_t qspi_base,
		uint8_t *pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{

	uint8_t avalible;
	uint8_t count;

	/*!< Enable the write access to the FLASH */
	qFLASH_WriteEnable(qspi_base);
	qFLASH_WaitForWriteEnd(qspi_base);

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	HWREG(qspi_base + QSPI_O_CTRLR0) = (HWREG(qspi_base + QSPI_O_CTRLR0)
			& ~(QSPI_CTRLR0_MQSEL_Msk | QSPI_CTRLR0_DFS_Msk
					| QSPI_CTRLR0_SPI_FRF_Msk))
			| (QSPI_CTRLR0_MQSEL_QSPI | QSPI_DataFrameSize_8b | QSPI_FRF_STD);
	HWREG(qspi_base + QSPI_O_CTRLR1) = (HWREG(qspi_base + QSPI_O_CTRLR1)
			& ~(QSPI_CTRLR1_NDF_Msk)) | (NumByteToWrite);
	QSPI_setMode(qspi_base, QSPI_CTRLR0_TMOD_TX_ONLY);
	HWREG(qspi_base + QSPI_O_SPI_CTRLR0) =
			(HWREG(qspi_base + QSPI_O_SPI_CTRLR0)
					& ~(QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk
							| QSPI_SPI_CTRLR0_INST_L_Msk
							| QSPI_SPI_CTRLR0_ADDR_L_Msk
							| QSPI_SPI_CTRLR0_TRANS_TYPE_Msk))
					| (QSPI_WAIT_CYCLES_4 | QSPI_Inst_Length_8b
							| QSPI_Addr_Length_24b
							| QSPI_INST_ADDR_TYPE_STANDARD);
	HWREG(qspi_base + QSPI_O_TXFTLR) = (HWREG(qspi_base + QSPI_O_TXFTLR)
			& ~(QSPI_TXFTLR_TXFTHR_Msk)) | (0);

	//Enable QSPI
	QSPI_enableModule(qspi_base);
	//enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_ENABLE;

	//Send instruction and address
	HWREG(qspi_base+QSPI_O_DR) = 0x02;
	HWREG(qspi_base+QSPI_O_DR) = WriteAddr >> 16;
	HWREG(qspi_base+QSPI_O_DR) = WriteAddr >> 8;
	HWREG(qspi_base+QSPI_O_DR) = WriteAddr;

	while (NumByteToWrite)
	{
		avalible = QSPI_FIFO_DEPTH - QSPI_ReadTxFIFOLevel(qspi_base);
		count = NumByteToWrite > avalible ? avalible : NumByteToWrite;
		NumByteToWrite -= count;
		while (count--)
		{
			HWREG(qspi_base+QSPI_O_DR) = *(pBuffer++);
		}
	}

	while (QSPI_checkIntFlag(qspi_base,QSPI_FLAG_BUSY) == SET)
	{
	}

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	/*!< Wait the end of Flash writing */
	qFLASH_WaitForWriteEnd(qspi_base);
}

static inline void qFLASH_WriteBuffer(uint32_t qspi_base,uint8_t *pBuffer, uint32_t WriteAddr,
		uint16_t NumByteToWrite)
{
	uint8_t NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;

	Addr = WriteAddr % qFLASH_SPI_PAGESIZE;
	count = qFLASH_SPI_PAGESIZE - Addr;
	NumOfPage = NumByteToWrite / qFLASH_SPI_PAGESIZE;
	NumOfSingle = NumByteToWrite % qFLASH_SPI_PAGESIZE;

	if (Addr == 0) /*!< WriteAddr is sFLASH_PAGESIZE aligned  */
	{
		if (NumOfPage == 0) /*!< NumByteToWrite < sFLASH_PAGESIZE */
		{
			qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, NumByteToWrite);
		}
		else /*!< NumByteToWrite > sFLASH_PAGESIZE */
		{
			while (NumOfPage--)
			{
				qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, qFLASH_SPI_PAGESIZE);
				WriteAddr += qFLASH_SPI_PAGESIZE;
				pBuffer += qFLASH_SPI_PAGESIZE;
			}
			qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, NumOfSingle);
		}
	}
	else /*!< WriteAddr is not sFLASH_PAGESIZE aligned  */
	{
		if (NumOfPage == 0) /*!< NumByteToWrite < sFLASH_PAGESIZE */
		{
			if (NumOfSingle > count) /*!< (NumByteToWrite + WriteAddr) > sFLASH_PAGESIZE */
			{
				temp = NumOfSingle - count;

				qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, count);
				WriteAddr += count;
				pBuffer += count;

				qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, temp);
			}
			else
			{
				qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, NumByteToWrite);
			}
		}
		else /*!< NumByteToWrite > sFLASH_PAGESIZE */
		{
			NumByteToWrite -= count;
			NumOfPage = NumByteToWrite / qFLASH_SPI_PAGESIZE;
			NumOfSingle = NumByteToWrite % qFLASH_SPI_PAGESIZE;

			qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, count);
			WriteAddr += count;
			pBuffer += count;

			while (NumOfPage--)
			{
				qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, qFLASH_SPI_PAGESIZE);
				WriteAddr += qFLASH_SPI_PAGESIZE;
				pBuffer += qFLASH_SPI_PAGESIZE;
			}

			if (NumOfSingle != 0)
			{
				qFLASH_WritePage(qspi_base,pBuffer, WriteAddr, NumOfSingle);
			}
		}
	}
}

static inline void qFLASH_ReadBufferQuad(uint32_t qspi_base,uint8_t *pBuffer, uint32_t ReadAddr,
		uint16_t NumByteToRead)
{

	uint8_t avalible;
	uint8_t count;

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;


	HWREG(qspi_base + QSPI_O_CTRLR0) = (HWREG(qspi_base + QSPI_O_CTRLR0) & ~(QSPI_CTRLR0_MQSEL_Msk|QSPI_CTRLR0_DFS_Msk|QSPI_CTRLR0_SPI_FRF_Msk)) | (QSPI_CTRLR0_MQSEL_QSPI|QSPI_DataFrameSize_8b|QSPI_FRF_QUAD);
	HWREG(qspi_base + QSPI_O_CTRLR1) = (HWREG(qspi_base + QSPI_O_CTRLR1) & ~(QSPI_CTRLR1_NDF_Msk)) | (NumByteToRead);

	QSPI_setMode(qspi_base, QSPI_CTRLR0_TMOD_EEPROM_READ);

	HWREG(qspi_base + QSPI_O_SPI_CTRLR0) = (HWREG(qspi_base + QSPI_O_SPI_CTRLR0) & ~(QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk|QSPI_SPI_CTRLR0_INST_L_Msk |QSPI_SPI_CTRLR0_ADDR_L_Msk|QSPI_SPI_CTRLR0_TRANS_TYPE_Msk)) | (QSPI_WAIT_CYCLES_6|QSPI_Inst_Length_8b|QSPI_Addr_Length_24b |QSPI_INST_TYPE_STANDARD);

	//Enable QSPI
	QSPI_enableModule(qspi_base);

	HWREG(qspi_base + QSPI_O_DR) = qFLASH_CMD_ISQR;
	HWREG(qspi_base + QSPI_O_DR) = ReadAddr;

	//Enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	while (NumByteToRead)
	{
		avalible = QSPI_ReadRxFIFOLevel(qspi_base);
		count = NumByteToRead > avalible ? avalible : NumByteToRead;
		NumByteToRead -= count;
		if (QSPI_checkIntFlag(qspi_base,SPI_RISR_RXO_Msk) == 1)
		{
			HWREG(qspi_base + QSPI_O_DR) = ReadAddr;
		}
		while (avalible--)
		{
			*(pBuffer++) = HWREG(qspi_base + QSPI_O_DR);
		}
	}

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

}

static inline void qFLASH_ReadBufferDual(uint32_t qspi_base,uint8_t *pBuffer, uint32_t ReadAddr,
		uint16_t NumByteToRead)
{

	uint8_t avalible;
	uint8_t count;

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	HWREG(qspi_base + QSPI_O_CTRLR0) = (HWREG(qspi_base + QSPI_O_CTRLR0) & ~(QSPI_CTRLR0_MQSEL_Msk|QSPI_CTRLR0_DFS_Msk|QSPI_CTRLR0_SPI_FRF_Msk)) | (QSPI_CTRLR0_MQSEL_QSPI|QSPI_DataFrameSize_8b|QSPI_FRF_DUAL);
	HWREG(qspi_base + QSPI_O_CTRLR1) = (HWREG(qspi_base + QSPI_O_CTRLR1) & ~(QSPI_CTRLR1_NDF_Msk)) | (NumByteToRead);

	QSPI_setMode(qspi_base, QSPI_CTRLR0_TMOD_RX_ONLY);

	HWREG(qspi_base + QSPI_O_SPI_CTRLR0) = (HWREG(qspi_base + QSPI_O_SPI_CTRLR0) & ~(QSPI_SPI_CTRLR0_WAIT_CYCLES_Msk|QSPI_SPI_CTRLR0_INST_L_Msk |QSPI_SPI_CTRLR0_ADDR_L_Msk|QSPI_SPI_CTRLR0_TRANS_TYPE_Msk)) | (QSPI_WAIT_CYCLES_8|QSPI_Inst_Length_8b|QSPI_Addr_Length_24b |QSPI_INST_ADDR_TYPE_STANDARD);

	//Enable QSPI
	QSPI_enableModule(qspi_base);

	HWREG(qspi_base + QSPI_O_DR) = qFLASH_CMD_IASDR;
	HWREG(qspi_base + QSPI_O_DR) = ReadAddr;

	//Enable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

	while (NumByteToRead)
	{
		avalible = QSPI_ReadRxFIFOLevel(qspi_base);
		count = NumByteToRead > avalible ? avalible : NumByteToRead;
		NumByteToRead -= count;
		while (avalible--)
		{
			*(pBuffer++) = HWREG(qspi_base + QSPI_O_DR);
		}
	}

	//Disable QSPI
	QSPI_disableModule(qspi_base);
	//disable slave
	HWREG(qspi_base+QSPI_O_SER) = HAL_QSPI_NSS_CS_DISABLE;

}

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /*__QFLASH_H */

