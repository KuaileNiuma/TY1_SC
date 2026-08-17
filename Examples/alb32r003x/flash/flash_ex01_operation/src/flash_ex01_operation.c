/**
 *************************************************************************************
 * @file flash_ex01_operation.c
 * @brief This file contains the source file for example flash_ex01_operation.
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

#include <stdio.h>
#include "device.h"
#include "eflashc.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define ADDR_FLASH_SECTOE_8     (EFLASH_BASE+0x0U)      //!< Base address of Sector 8, 128k bytes
#define ADDR_FLASH_SECTOE_9     (EFLASH_BASE+0x20000U)  //!< Base address of Sector 9, 128k bytes
#define ADDR_FLASH_SECTOE_10    (EFLASH_BASE+0x40000U)  //!< Base address of Sector 10, 128k bytes
#define ADDR_FLASH_SECTOE_11    (EFLASH_BASE+0x60000U)  //!< Base address of Sector 11, 128k bytes

#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOE_8        //!< User flash start address
#define FLASH_OTP_START_ADDR    (0x1FFF7800U)              //!< User flash otp start address
#define FLASH_USER_SIZE         (0x20000U)                 //!< User flash size (4KB)
#define FLASH_OTP_PROGRAM_SIZE  (0x200U)                   //!<User OTP size for programming>

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint32_t test_data = 0x5a5aa5a5;                       //!< Test data pattern for flash operations
uint32_t address;
//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
static int getUserSector(uint32_t address);

//*****************************************************************************
//
// Get flash sector number from address
// Maps a given flash address to the corresponding sector number
//
//*****************************************************************************
static int getUserSector(uint32_t address)
{
	uint32_t sector_num = 0;
	if (address < ADDR_FLASH_SECTOE_9 && address >= ADDR_FLASH_SECTOE_8)
	{
		sector_num = EFLASH_Sector_8 + 0;
	}
	else if (address < ADDR_FLASH_SECTOE_10 && address >= ADDR_FLASH_SECTOE_9)
	{
		sector_num = EFLASH_Sector_8 + 1;
	}
	else if (address < ADDR_FLASH_SECTOE_11 && address >= ADDR_FLASH_SECTOE_10)
	{
		sector_num = EFLASH_Sector_8 + 2;
	}
	else if (address < ADDR_FLASH_SECTOE_11+128*1024 && address >= ADDR_FLASH_SECTOE_11)
	{
		sector_num = EFLASH_Sector_8 + 3;
	}
	else
	{
		return -1;
	}
	return sector_num;
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
	int error=0;

	alb32r003x_evb_init();
	//
    // Print test information
    //
    printf("FLASH EX01 Operation.\r\n");

    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Unlock FLASH and enable register access
    //
    FLASH_unlock();
    FLASH_readUnlock();
    //
    // Clear all flash status flags
    //
    FLASH_clearFlag(EFLASH_SR_EOP | EFLASH_SR_OPERR | EFLASH_SR_WRPERR |
                   EFLASH_SR_PGAERR | EFLASH_SR_PGPERR | EFLASH_SR_PGSERR);

    //
    // Erase user flash sectors
    //
    for(int size = 0; size < FLASH_USER_SIZE * 4; size += 128*1024)
    {
	   int sector_num = getUserSector(FLASH_USER_START_ADDR + size);
	   FLASH_eraseSector(sector_num);
    }

    //
    // Program flash with test data (word by word)
    //
    test_data = 0x5a5aa5a5;                       //!< Test data pattern for flash operations
    for (int i = 0; i < FLASH_USER_SIZE * 4; i += 4)
    {
       test_data += 4;
	   FLASH_program((uint8_t *)&test_data, FLASH_USER_START_ADDR + i, FLASH_PSIZE_WORD);
    }

    //
    // Verify programmed data
    //
    test_data = 0x5a5aa5a5;                       //!< Test data pattern for flash operations
    for (int i = 0; i < FLASH_USER_SIZE * 4; i += 4)
    {
	   uint32_t temp = *(__IO uint32_t *)(FLASH_USER_START_ADDR + i);
       test_data += 4;
	   if(test_data != temp)
	   {
		   printf("MAIN FLASH EX01 Operation fail.\r\n");
		   error++;
		   break;
	   }
    }

    //
    // Erase user flash sectors
    //
    for(int size = 0; size < FLASH_USER_SIZE * 4; size += 128*1024)
    {
	   int sector_num = getUserSector(FLASH_USER_START_ADDR + size);
	   FLASH_eraseSector(sector_num);
    }

    //
    // Verify programmed data
    //
    for (int i = 0; i < FLASH_USER_SIZE * 4; i += 4)
    {
	   uint32_t temp = *(__IO uint32_t *)(FLASH_USER_START_ADDR + i);
	   if(0xFFFFFFFF != temp)
	   {
		   printf("USER FLASH EX01 Operation fail.\r\n");
		   error++;
		   break;
	   }
    }

    //
    // Infinite loop
    //
    if(error ==0)
    {
    	printf("FLASH EX01 Operation success.\r\n");
    }
    for(;;);
}
