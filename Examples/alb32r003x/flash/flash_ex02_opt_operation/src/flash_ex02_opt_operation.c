/**
 *************************************************************************************
 * @file flash_ex02_opt_operation.c
 * @brief This file contains the source file for example flash_ex02_opt_operation.
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
#include "debug.h"
#include "interrupt.h"
#include "eflashc.h"
#include "alb32r003x_evb.h"

//*****************************************************************************
//
// Macro Definitions
//
//*****************************************************************************
#define FLASH_DEBUG_ON         0                         //!< Debug mode enable flag

#define FLASH_INFO(fmt,arg...)           printf("<<-FLASH-INFO->> "fmt"\n",##arg)       //!< Flash information printf macro
#define FLASH_ERROR(fmt,arg...)          printf("<<-FLASH-ERROR->> "fmt"\n",##arg)     //!< Flash error printf macro
#define FLASH_DEBUG(fmt,arg...)          do{\
                                          if(FLASH_DEBUG_ON)\
                                          printf("<<-FLASH-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)     //!< Flash debug printf macro

#define FLASH_WRP_SECTORS   (EFLASH_OB_WRP_Sector_8|EFLASH_OB_WRP_Sector_9) //!< Write protection sectors

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
__IO uint32_t SectorsWRPStatus = 0xFFF;                 //!< Write protection status of sectors

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
void InternalFlash_Reset(void);
void WriteProtect_Test(void);
void OptionByte_Info(void);

//*****************************************************************************
//
// Reset internal flash to default configuration
// Restores flash option bytes to factory defaults
//
//*****************************************************************************
void InternalFlash_Reset(void)
{
    //
    // Unlock flash option bytes
    //
    FLASH_OB_unlock();
    
    //
    // Clear all flash status flags
    //
    FLASH_clearFlag(EFLASH_SR_EOP | EFLASH_SR_OPERR | EFLASH_SR_WRPERR |
                    EFLASH_SR_PGAERR | EFLASH_SR_PGPERR | EFLASH_SR_PGSERR);

    //
    // Set RDP to LEVEL1
    //
    FLASH_INFO("\r\n");
    FLASH_INFO("Set RDP LEVEL1.....\r\n");
    FLASH_OB_RDPconfig(EFLASH_OB_RDP_Level_1);
    FLASH_OB_launch();

    //
    // Set RDP to LEVEL0
    //
    FLASH_INFO("\r\n");
    FLASH_INFO("Set RDP LEVEL0.....\r\n");
    FLASH_OB_RDPconfig(EFLASH_OB_RDP_Level_0);
    FLASH_OB_launch();

    //
    // Set OPTCR to default value
    //
    (*(__IO uint32_t *)(OPTCR_BYTE0_ADDRESS)) = 0x0FFFFFED;
    FLASH_OB_launch();
    
    //
    // Lock flash option bytes
    //
    FLASH_OB_lock();
}

//*****************************************************************************
//
// Test flash write protection features
// Enables or disables write protection for specified sectors
//
//*****************************************************************************
void WriteProtect_Test(void)
{
    //
    // Get current write protection status
    //
    SectorsWRPStatus = FLASH_OB_getWRP() & FLASH_WRP_SECTORS;

    //
    // Check if sectors are protected and toggle protection state
    //
    if (SectorsWRPStatus == 0x00)
    {
        //
        // Remove write protection
        //
        FLASH_OB_unlock();
        FLASH_OB_WRPconfig(FLASH_WRP_SECTORS, DISABLE);
        FLASH_OB_launch();
        FLASH_OB_lock();

        //
        // Verify protection removal
        //
        SectorsWRPStatus = FLASH_OB_getWRP() & FLASH_WRP_SECTORS;
        if (SectorsWRPStatus == FLASH_WRP_SECTORS)
        {
            FLASH_INFO("WRP deprotect success.......");
        }
        else
        {
            FLASH_ERROR("WRP deprotect fail.......");
        }
    }
    else
    {
        //
        // Enable write protection
        //
        FLASH_OB_unlock();
        FLASH_OB_WRPconfig(FLASH_WRP_SECTORS, ENABLE);
        FLASH_OB_launch();
        FLASH_OB_lock();
        //
        // Verify protection enabled
        //
        SectorsWRPStatus = FLASH_OB_getWRP() & FLASH_WRP_SECTORS;
        if (SectorsWRPStatus == 0x00)
        {
            FLASH_INFO("WRP protect success.......");
        }
        else
        {
            FLASH_ERROR("WRP protect fail.......");
        }
    }
}


//*****************************************************************************
//
// printf flash option byte information
// Displays current configuration of RDP, WRP, user options, and BOR levels
//
//*****************************************************************************
void OptionByte_Info(void)
{
    //
    // Read and display OPTCR register value
    //
    uint32_t temp_optcr = *(uint32_t *)OPTCR_BYTE0_ADDRESS;
    uint16_t temp = 0;

    FLASH_INFO("\r\n");
    FLASH_INFO("REG:OPTCR=%08X", temp_optcr);
    //
    // Display Read Protection Level
    //
    FLASH_INFO("\r\n");
    FLASH_INFO("-------------RDP LEVEL-------------");
    if(FLASH_OB_getRDP() == RESET)
    {
        FLASH_INFO("FLASH RDP is LEVEL0");
    }
    else
    {
        FLASH_INFO("FLASH RDP is LEVEL1");
    }

    //
    // Display Write Protection Status
    //
    FLASH_INFO("\r\n");
    FLASH_INFO("-------------WRP sector-------------");
    temp = FLASH_OB_getWRP();
    FLASH_INFO("WRP=0x%x", temp);
    //
    // Display User Options
    //
    FLASH_DEBUG("\r\n");
    FLASH_DEBUG("-------------OPTIONG USER------------");
    temp = FLASH_OB_getUser();

    FLASH_INFO("\r\n");
    if(temp & 0x01)
    {
    	FLASH_INFO("default: soft wdg\n");
//        FLASH_DEBUG("default: soft wdg");
    }
    else
    {
    	FLASH_INFO("hard wdg\r\n");
//        FLASH_DEBUG("hard wdg");
    }

    if(temp & (0x01 << 1))
    {
    	FLASH_INFO("default: cpu not reset when suspend mode\n");
//        FLASH_DEBUG("default: cpu not reset when suspend mode");
    }
    else
    {
    	FLASH_INFO("cpu reset when suspend mode\n");
//        FLASH_DEBUG("cpu reset when suspend mode");
    }
    FLASH_INFO("\r\n");
    if(temp & (0x01 << 2))
    {
    	FLASH_INFO("default: cpu not reset when standby mode\n");
//        FLASH_DEBUG("default: cpu not reset when standby mode");
    }
    else
    {
    	FLASH_INFO("cpu reset when standby mode\n");
//        FLASH_DEBUG("cpu reset when standby mode");
    }

    //
    // Display Brown-Out Reset Level
    //
    FLASH_DEBUG("\r\n");
    FLASH_DEBUG("-------------BOR_LEV------------");
    temp = FLASH_OB_getBOR();
    switch(temp)
    {
        case OB_BOR_LEVEL3:
        	FLASH_INFO("BOR Voltage is from 2.70 to  3.60 V\n");
//            FLASH_DEBUG("BOR Voltage is from 2.70 to  3.60 V");
            break;

        case OB_BOR_LEVEL2:
        	FLASH_INFO("BOR Voltage is from 2.40 to  3.70 V\n");
//            FLASH_DEBUG("BOR Voltage is from 2.40 to  3.70 V");
            break;

        case OB_BOR_LEVEL1:
        	FLASH_INFO("BOR Voltage is from 2.10 to  2.40 V\n");
//            FLASH_DEBUG("BOR Voltage is from 2.10 to  2.40 V");
            break;

        case OB_BOR_OFF:
        	FLASH_INFO("BOR Voltage is from 2.10 to  2.40 V\n");
//            FLASH_DEBUG("BOR Voltage is from 1.80 to  2.10V");
            break;
    }
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
    alb32r003x_evb_init();
    //
    // printf test information
    //
    printf("FLASH EX02 option operation.\r\n");
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Test write protection functionality
    //
#if 1
    WriteProtect_Test(); // Project debug, modify flash WRP
#endif
    
    FLASH_OB_unlock();

    (*(__IO uint32_t *)(OPTCR_BYTE0_ADDRESS)) = 0x0FFFAA02;

    FLASH_OB_lock();
    //
    // Display current option byte information
    //
    OptionByte_Info();
    //
    // Reset flash to default configuration
    //
    InternalFlash_Reset();
    //
    // Display option byte information after reset
    //
    OptionByte_Info();
    //
    // Infinite loop
    //
    for(;;);
}
