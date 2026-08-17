/**
 *************************************************************************************
 * @file w25q64.h
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



#ifndef _W25Q64_H_
#define _W25Q64_H_

#ifdef __cplusplus
extern "C"{
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <spi.h>
#include "board.h"


#define READ_JEDEC_ID    0x9F            /*!<read chip ID */
#define READ_STATUS_REG1   0x05            /*!< read status register-1 */
#define WRITE_STATUS_REG   0x01            /*!< write status registe-1 */
#define READ_STATUS_REG2   0x35            /*!< read status register-2 */
#define WRITE_ENABLE    0x06            /*!< write enablewaitDeviceReady */
#define WRITE_DISABLE    0x04            /*!< write disable */
#define READ_DATA    0x03            /*!< read data bytes */
#define SECTOR_ERASE              0x20    /*!< sector erase */
#define PAGE_PROGRAM              0x02    /*!< page program */



int32_t w25q64_init(uint32_t spi_base);
int32_t w25q64_write_enable(uint32_t dev);
int32_t w25q64_write_disable(uint32_t dev);
int32_t w25q64_erase(uint32_t dev, uint32_t address, uint32_t size);
int32_t w25q64_write(uint32_t dev, uint32_t address, uint32_t size, const void *data);
extern int32_t w25q64_read(uint32_t dev, uint32_t address, uint32_t size, void *data);
extern uint32_t w25q64_read_jedec_id(uint32_t base);
extern uint32_t w25q64_read_device_id(uint32_t base);
int32_t w25q64_wait_ready(uint32_t base);
#ifdef __cplusplus
}
#endif


#endif /* _W25Q64_H_ */
