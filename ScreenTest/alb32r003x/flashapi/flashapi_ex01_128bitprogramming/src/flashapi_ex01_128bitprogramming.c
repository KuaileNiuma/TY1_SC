/**
 *************************************************************************************
 * @file flashapi_ex01_128bitprogramming.c
 * @brief This file contains the source file for example flashapi_ex01_128bitprogramming.
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



//
// Include Flash API include file
//

//
// Include Flash API include file
//
#include "FlashTech.h"

// Include Flash API example header file
//
#include "alb32r003x_sector.h"

//
// Defines
//

//
// Globals
//

//
// Length (in 32-bit words) of data buffer used for program
// Actually a page of data
//
#define  WORDS_IN_FLASH_BUFFER    ( ( 0x100 ) )
#define  FLASH_TEST_START_ADDR    (Bzero_Sector2_start)
#define  FLASH_TEST_START_SIZE    (0x1000)
#define  FLASH_LINE_SIZE          (512)
/* 系统时钟 20M */
#define DEVICE_SYSCLK_FREQ              (200*1000*1000U)
//
// Data Buffers used for program operation using the flash API program function
//
uint32 Buffer[WORDS_IN_FLASH_BUFFER];
uint32   *Buffer32 = (uint32 *)Buffer;


//
// Prototype of the functions used in this example
//
Fapi_StatusType Example_EraseSector(void);
Fapi_StatusType Example_CallFlashAPI(void);
Fapi_StatusType Example_ProgramUsingAutoECC(void);

int main(void)
{
	Fapi_StatusType returnCheck = Fapi_Status_Success;

	//
	// Initialize device clock and peripherals
	//
	//Device_init();

	//
	// Initialize module
	//
	//Interrupt_initModule();

	//
	// Initialize vector table
	//
	//Interrupt_initVectorTable();

    //
    // Flash API functions should not be executed from the same bank on which
    // erase/program operations are in progress.
    // Also, note that there should not be any access to the Flash bank on
    // which erase/program operations are in progress.  Hence below function
    // is mapped to RAM for execution.
    //

	returnCheck = Example_CallFlashAPI();

    //
    // Example is done here
    //
	for(;;);
	return 0;
}

//*****************************************************************************
//  Example_CallFlashAPI
//
//  This function will interface to the flash API.
//  Flash API functions used in this function are executed from RAM in this
//  example.
//*****************************************************************************
ILM_FUNC_T Fapi_StatusType Example_CallFlashAPI(void)
{
    uint32 u32BuffIndex = 0;
    Fapi_StatusType  oReturnCheck;

	//	Initialize the Flash API by providing the Flash register base address
	//	and operating frequency(in MHz).
	//	This function is required to initialize the Flash API based on System
	//	frequency before any other Flash API operation can be performed.
	//	This function must also be called whenever System frequency or RWAIT is
	//	changed.

    oReturnCheck = Fapi_initializeAPI(Fapi_FlashBank0, (Fapi_FmcRegistersType *)0,DEVICE_SYSCLK_FREQ);
    if(oReturnCheck != Fapi_Status_Success)
    {
        //
        // Check Flash API documentation for possible errors
        //
        return oReturnCheck;
    }

    //
    // Initialize the Flash banks and FMC for erase and program operations.
    // Fapi_setActiveFlashBank() function sets the Flash banks and FMC for
    // further Flash operations to be performed on the banks.
    //
    oReturnCheck = Fapi_setActiveFlashBank(Fapi_FlashBank0);

	//
	// Wait until Flash Control is enable done with other operation
	//
    while (Fapi_checkFsmForReady(Fapi_FlashBank0) != Fapi_Status_FsmReady){}

    if(oReturnCheck != Fapi_Status_Success)
	{
		//
		// Check Flash API documentation for possible errors
		//
		return oReturnCheck;
	}

    //
    // Erase the sector before programming
    //
    oReturnCheck = Example_EraseSector();
    if(oReturnCheck != Fapi_Status_Success)
	{
	   //
	   // Check Flash API documentation for possible errors
	   //
	   return oReturnCheck;
	}

	//
	// Fill a buffer with data to program into the flash.
	//
	for(u32BuffIndex=0; u32BuffIndex < WORDS_IN_FLASH_BUFFER; u32BuffIndex++)
	{
		Buffer[u32BuffIndex] = u32BuffIndex;
	}

    //
    // Program the sector using AutoECC option
    //
	oReturnCheck = Example_ProgramUsingAutoECC();
    if(oReturnCheck != Fapi_Status_Success)
	{
	   //
	   // Check Flash API documentation for possible errors
	   //
	   return oReturnCheck;
	}

    return oReturnCheck;
}

//*****************************************************************************
//  Example_EraseSector
//
//  Example function to Erase data of a sector in Flash.
//  Flash API functions used in this function are executed from RAM in this
//  example.
//*****************************************************************************
ILM_FUNC_T Fapi_StatusType Example_EraseSector(void)
{
    Fapi_StatusType  oReturnCheck = Fapi_Status_Success;
    Fapi_FlashStatusType  oFlashStatus = Fapi_Status_Success;
    Fapi_FlashStatusWordType  oFlashStatusWord = {0};

    //
    // Issue ClearMore command
    //
    oReturnCheck = Fapi_issueAsyncCommand(Fapi_FlashBank0, Fapi_ClearStatus);

    if(oReturnCheck != Fapi_Status_Success)
	{
		//
		// Check Flash API documentation for possible errors
		//
		return oReturnCheck;
	}

    //
    // Erase the sector that is programmed in the above example
    // Erase Sector0 flash main block
    //
    oReturnCheck = Fapi_issueAsyncCommandWithAddress(Fapi_FlashBank0, Fapi_EraseSector, (uint32 *)FLASH_TEST_START_ADDR );

    //
	// Wait until Flash Control is enable done with other operation
	//
	while (Fapi_checkFsmForReady(Fapi_FlashBank0) != Fapi_Status_FsmReady){}

	if(oReturnCheck != Fapi_Status_Success)
	{
		//
		// Check Flash API documentation for possible errors
		//
		return oReturnCheck;
	}

    //
    // Read flash control status register contents to know the status of flash control after
    // erase command to see if there are any erase operation related errors
    //
	oFlashStatus = Fapi_getFsmStatus(Fapi_FlashBank0);
	if ( 0 != oFlashStatus  )
	{
		oReturnCheck = 0xff;
		return oReturnCheck;
	}

    // Do blank check
    // Verify that flash block
    // The Erase command itself does a verify as it goes.
    // Hence erase verify by CPU reads (Fapi_doBlankCheck()) is optional.

	oReturnCheck = Fapi_doBlankCheck(Fapi_FlashBank0, (uint32 *)FLASH_TEST_START_ADDR, FLASH_TEST_START_SIZE, &oFlashStatusWord);
	if ( oReturnCheck != Fapi_Status_Success )
	{
		 return oReturnCheck;
	}

    return oReturnCheck;
}

//*****************************************************************************
//  Example_ProgramUsingAutoECC
//
//  Example function to Program data in Flash using "AutoEccGeneration" option.
//  Flash API functions used in this function are executed from RAM in this
//  example.
//*****************************************************************************
ILM_FUNC_T Fapi_StatusType Example_ProgramUsingAutoECC(void)
{
	uint32 u32Index = 0;
	uint32 i = 0;
	Fapi_StatusType  oReturnCheck = Fapi_Status_Success;
	Fapi_FlashStatusType  oFlashStatus;
	Fapi_FlashStatusWordType  oFlashStatusWord;

	uint32 FlashLineNumber = 0;
	uint32 BufferSizeInWords = 4;//program
	uint32 FlashStartAddr = FLASH_TEST_START_ADDR;

	for(i=0, u32Index = FlashStartAddr;
	   (u32Index < (FlashStartAddr + WORDS_IN_FLASH_BUFFER*sizeof(uint32)));
	   i += BufferSizeInWords, u32Index += BufferSizeInWords*sizeof(uint32))
	{

		oReturnCheck = Fapi_issueProgrammingCommand((uint32 *)u32Index, (uint32 *)(Buffer+i), BufferSizeInWords, 0, 0, Fapi_AutoEccGeneration);

		//
		// Wait until the Flash program operation is over
		//
		while(Fapi_checkFsmForReady(Fapi_FlashBank0) == Fapi_Status_FsmBusy);

		if(oReturnCheck != Fapi_Status_Success)
		{
			//
			// Check Flash API documentation for possible errors
			//
			return oReturnCheck;
		}

		//
		// Read flash control register contents to know the status of flash control after
		// program command to see if there are any program operation related
		// errors
		//
		oFlashStatus = Fapi_getFsmStatus(Fapi_FlashBank0);
		if( (oFlashStatus != 0))
		{
			//
			//Check flash control and debug accordingly
			//
			oReturnCheck = 0xff;
			return oReturnCheck;
		}

		//
		// Verify the programmed values.
		//

		oReturnCheck = Fapi_doVerify((uint32 *)u32Index,
								BufferSizeInWords,
								(uint32 *)(Buffer+i),
								&oFlashStatusWord);

		if(oReturnCheck != Fapi_Status_Success)
		{
			//
			// Check Flash API documentation for possible errors
			//
			return oReturnCheck;
		}
	}



    return oReturnCheck;
}
