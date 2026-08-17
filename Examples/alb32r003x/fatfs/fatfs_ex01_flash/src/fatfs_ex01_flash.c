/**
 *************************************************************************************
 * @file fatfs_ex01_flash.c
 * @brief This file contains the source file for example fatfs_ex01_flash.
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

#include <fatfs_ex01_board.h>
#include <fatfs_ex01_w25q64.h>
#include <stdio.h>
#include <string.h>
#include "device.h"
#include "alb32r003x_evb.h"
#include "spi.h"
#include "diskio.h"
#include "ff.h"
#include "ffconf.h"
#include "integer.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define TEST_DATA_COUNT		512          //!< Number of data bytes to transfer

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
uint8_t readBuffer[TEST_DATA_COUNT] = {0};    //!< Buffer to store data read from FLASH
uint8_t writeBuffer[TEST_DATA_COUNT] = {0};   //!< Buffer to store data to write to FLASH
uint8_t res = 0;
//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void spiRxFIFOISR(void);                      //!< SPI receive FIFO interrupt service routine



/* test4: FATFS TEST */
void test_full_fatfs(void);
//*****************************************************************************
//
// Main Function
//
//*****************************************************************************
int main(void)
{
	uint32_t i;               //!< Loop counter
	uint32_t jedec_id = 0;    //!< FLASH JEDEC ID

    //
    // Disable global interrupts
    //
    CPU_disableIrq();
    alb32r003x_evb_init();
    //
    // Initialize board hardware
    //
    Board_init();

    //
    // Set the CS to inactive (when GPIO08 as CS)
    //
    CS_HIGH;

    //
    // Initialize the send data buffers with sequential values
    //
    for (i = 0; i < 256; i++)
    {
    	writeBuffer[i] = i;
    }

    for (i = 256; i < 512; i++)
    {
    	writeBuffer[i] = 511 - i;
    }


    //
    // Enable global interrupts
    //
    CPU_enableIrq();

    //
    // Read the flash JEDEC ID to confirm connection
    //
	jedec_id = w25q64_read_jedec_id(mySPI_BASE);

	//
	// Erase 64KB sector
	//
//	w25q64_erase(mySPI_BASE, 0, 0x10000);

	//
	// Write 256 bytes to FLASH
	//
    flash_write(mySPI_BASE, 0, TEST_DATA_COUNT, writeBuffer);

    //
    // Read a page of data from FLASH
    //
    w25q64_read(mySPI_BASE, 0, TEST_DATA_COUNT, readBuffer);

    //
    // Verify received data matches transmitted data
    //
    for (i = 0; i < TEST_DATA_COUNT; i++)
    {
        if (readBuffer[i] != writeBuffer[i])
        {
            // Data mismatch detected - halt execution for debugging
        	__EBREAK();
        }
    }


    //fates
    /* 测试4: 完整FATFS功能测试 */

    test_full_fatfs();


	//
	// Infinite loop after successful operation
	//
	while(1);

    return 0;

}

//*****************************************************************************
//
// SPI Receive FIFO Interrupt Service Routine
//
//*****************************************************************************
void spiRxFIFOISR(void)
{
    uint32_t status;         //!< SPI interrupt status register

    //
    // Get SPI interrupt status flags
    //
    status = SPI_getInterruptStatus(mySPI_BASE);
    
    //
    // Check for FIFO error conditions
    //
    if((status & SPI_ISR_TXOIS) ||
       (status & SPI_ISR_RXUIS) ||
       (status & SPI_ISR_RXOIS))
    {
        //
        // Disable the error interrupts and halt for debugging
        //
    	SPI_disableInterrupt(mySPI_BASE, status);
    	__EBREAK();
    }

    //
    // Clear all interrupt status flags
    //
    SPI_clearAllInterruptStatus(mySPI_BASE);

}


/* test4: FATFS TEST */

void test_full_fatfs(void)
{
    FATFS fs;
    FIL fil;
    FRESULT fr;
    UINT bw, br;
    char buffer[64];


    // 1. Start
    fr = f_mount(NULL, "0:", 0);

    // 2. Try
    fr = f_mount(&fs, "0:", 1);
    printf("1. f_mount return: %d (0=FR_OK)\n", fr);

    if(fr == FR_NO_FILESYSTEM) {
        printf("2. No file system detected,start formatting...\n");

    	//w25q64_erase(mySPI_BASE, 0, 0x1000);
    	// format FAT32/FAT16/FAT12
        fr = f_mkfs("0:", 1,4096);
        printf("   f_mkfs return: %d\n", fr);


        if(fr != FR_OK) {
//            printf("FAILED！Check disk_ioctl(GET_SECTOR_COUNT)return value\n");
            return;
        }

        // reformat
        fr = f_mount(NULL, "0:", 0);
        fr = f_mount(&fs, "0:", 1);
        printf("3. reformat return: %d\n", fr);
    }

    if(fr == FR_OK)
    {
        printf("4. create/write test document ...\n");
        fr = f_open(&fil, "0:/test.txt", FA_CREATE_ALWAYS | FA_WRITE);
        printf("   f_open(write) return: %d\n", fr);

        if(fr == FR_OK) {
            fr = f_write(&fil, "Hello from MSP432!", 19, &bw);
            printf("   f_write return: %d, write byte size: %d\n", fr, bw);
            fr = f_close(&fil);
        }

        printf("5. read and check ...\n");
        fr = f_open(&fil, "0:/test.txt", FA_READ);
        if(fr == FR_OK) {
            fr = f_read(&fil, buffer, sizeof(buffer), &br);
            printf("   f_read return: %d,read byte size: %d\n", fr, br);
            buffer[br] = '\0';
            printf("   file content: %s\n", buffer);
            f_close(&fil);
        }

        printf("6.1 create new file ...\n");
        fr = f_open(&fil, "0:/data1.dat", FA_CREATE_ALWAYS | FA_WRITE);
        if(fr == FR_OK) {
            for(int i=0; i<100; i++) {
                f_write(&fil, &i, sizeof(i), &bw);
            }
            f_close(&fil);
            printf("Successfully created 100 integer files\n");
        }
        printf("6.2 read and check ...\n");
        fr = f_open(&fil, "0:/data1.dat", FA_READ);
        if(fr == FR_OK) {
        	int data[100];
            fr = f_read(&fil, data, sizeof(data), &br);
            printf("   f_read return: %d,read byte size: %d\n", fr, br);
            printf("The first 10\n");
            for(int i = 0;i < 10; i++)
            {
            	printf("%d\n", data[i]);
            }
            printf("The document has %d\n", (int)(br/ sizeof(int)));
            f_close(&fil);
        }

        // 测试文件信息获取
        FILINFO fno;
        fr = f_stat("0:/test.txt", &fno);
        printf("7. f_stat return: %d,document size: %ld byte\n", fr, fno.fsize);

        // 列出根目录文件
        printf("8. Root directory list:\n");
        DIR dir;
        fr = f_opendir(&dir, "0:/");
        if(fr == FR_OK) {
            while(f_readdir(&dir, &fno) == FR_OK && fno.fname[0]) {
                printf("   %s (%ld byte)\n", fno.fname, fno.fsize);
            }
            f_closedir(&dir);
        }
    }
    else
    	while(1);
}
