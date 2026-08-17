/** 
  *************************************************************************************
  * @file CRC_configpoly_main.c 
  * @author Albatross 
  * @brief This file contains the source file. 
  * @version 1.0.0 
  * @date 2025-07-30 
  *************************************************************************************
  * @copyright Copyright (c) 2025 Albatross  Semiconductor( Hangzhou ) Co ., Ltd . 
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

//*****************************************************************************
// includes
//*****************************************************************************
#include <stdio.h>
#include "CRC_main.h"
#include "vcu2_types.h"
#include "vcu2_crc.h"
#include "vcrc_configpoly.h"
extern const unsigned short crc8Table[];
//extern const unsigned short crc8TableReflected[];
extern const unsigned short crc16P1Table[];
extern const unsigned short crc16P2Table[];
extern const unsigned short crc16P1TableReflected[];
extern const unsigned short crc16P2TableReflected[];
extern const unsigned long crc32P1Table[];
//extern const unsigned long crc32P2Table[];
extern const unsigned long crc32P1TableReflected[];
//extern const unsigned long crc32P2TableReflected[];

//*****************************************************************************
// defines
//*****************************************************************************
#define CRC_INIT_4 0x0
#define CRC_INIT_8 0x0
#define CRC_INIT_16 0x0
#define CRC_INIT_CRC16MODBUS  0xFFFF
#define CRC_INIT_CRC32 0xFFFFFFFF
#define POLYNOMIAL_4 0x0003
#define POLYNOMIAL_8 0x0007
#define POLYNOMIAL_17 0x1685B
#define POLYNOMIAL_16_P2 0x1021
#define POLYNOMIAL_16_P1 0x8005
#define POLYNOMIAL_32_P1 0x04C11DB7
#define POLYNOMIAL_32_P2 0x1EDC6F41
#define NO_OF_TESTS 22
#define NBYTES1	128
#define NWORDS1	NBYTES1/2

#define SIZE_32_BITS  31
#define SIZE_31_BITS  30
#define SIZE_30_BITS  29
#define SIZE_29_BITS  28
#define SIZE_28_BITS  27
#define SIZE_27_BITS  26
#define SIZE_26_BITS  25
#define SIZE_25_BITS  24
#define SIZE_24_BITS  23
#define SIZE_23_BITS  22
#define SIZE_22_BITS  21
#define SIZE_21_BITS  20
#define SIZE_20_BITS  19
#define SIZE_19_BITS  18
#define SIZE_18_BITS  17
#define SIZE_17_BITS  16
#define SIZE_16_BITS  15
#define SIZE_15_BITS  14
#define SIZE_14_BITS  13
#define SIZE_13_BITS  12
#define SIZE_12_BITS  11
#define SIZE_11_BITS  10
#define SIZE_10_BITS  9
#define SIZE_9_BITS   8
#define SIZE_8_BITS   7
#define SIZE_7_BITS   6
#define SIZE_6_BITS   5
#define SIZE_5_BITS   4
#define SIZE_4_BITS   3
#define SIZE_3_BITS   2
#define SIZE_2_BITS   1
#define SIZE_1_BITS   0


//*****************************************************************************
// globals
//*****************************************************************************

static uint32_t TestOutput[NO_OF_TESTS];
static uint32_t goldenOutput[NO_OF_TESTS];
static uint16_t pass,fail;

static CRC_Obj CRC;
static CRC_Handle handleCRC;

static uint16_t testInput[NWORDS1] = {
	0x4001, 0x8002, 0xC003, 0x0004, 0x4005, 0x8006, 0xC007, 0x0008,
	0x4009, 0x800A, 0xC00B, 0x000C, 0x400D, 0x800E, 0xC00F, 0x0010,
	0x4011, 0x8012, 0xC013, 0x0014, 0x4015, 0x8016, 0xC017, 0x0018,
	0x4019, 0x801A, 0xC01B, 0x001C, 0x401D, 0x801E, 0xC01F, 0x0020,
	0x4021, 0x8022, 0xC023, 0x0024, 0x4025, 0x8026, 0xC027, 0x0028,
	0x4029, 0x802A, 0xC02B, 0x002C, 0x402D, 0x802E, 0xC02F, 0x0030,
	0x4031, 0x8032, 0xC033, 0x0034, 0x4035, 0x8036, 0xC037, 0x0038,
	0x4039, 0x803A, 0xC03B, 0x003C, 0x403D, 0x803E, 0xC03F, 0x0040,
};


//! \brief C table-lookup 4-bit CRC calculation for ENDAT,message size in bytes
//! \param[in] hndCRC handle to the CRC object
void CRC_run4BitENDATTableLookupC(CRC_Handle hndCRC);

//! \brief C table-lookup 4-bit CRC calculation for ENDAT,message size in bits
//! \param[in] hndCRC handle to the CRC object
void CRC_run4BitENDATBitTableLookupC_Generic(CRC_Handle hndCRC);

//! \brief C table-lookup 17-bit CRC for CANFD,message size in bytes
//! \param[in] hndCRC handle to the CRC object
void CRC_run17BitCANFDTableLookupC(CRC_Handle hndCRC);

int CRCcongigpoly_main(void){
	// Locals
	int16_t index = 0;

	//******************************************************************************************************
	// Note -
	// Polynomial size - size of of 1 bit - indicated by programming a value of 0x0
	// Polynomial size - size of of 32bits - indicated by programming a value of 0x1F
	// Datasize refers to the integral unit on which the CRC is computed
	// Data size - size of 1 bit - indicated by programming a value of 0x0
	// Data size - size of 8 bits is indicated by programming a value of 0x7
	// These are to be set in the VCRCSIZE register - PSIZE and DSIZE fields and they are
	// set in the functions _CRC_runConfigPolyBytes and _CRC_runConfigPolyBits implemented in the asm file
	// vcrc_configpoly_asm.asm
	// Total size of the message on which the CRC to be computed is specified by 2 elements MsgBytes and MsgBits
	// If the size of the message is in bytes - then set the value of CRC.nMsgBytes to the size of the message
	// and call the function - CRC_runConfigPolyBytes
	// if the size of the message cannot be specified in bytes - then set the value of CRC.nMsgBits to the size
	// of the message in bits and call the function - _CRC_runConfigPolyBits

	//******************************************************************************************************
	//EXAMPLE 1 and 2 - Byte wise 4 bit CRC computation for different Msg Sizes -> 128, 7 bytes respectively

	// Step 1: Initialize CRC objects
	CRC.seedValue = CRC_INIT_4;       //enter the seed value for CRC computation
	CRC.nMsgBytes = 0; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = 0;                          //pointer to the message buffer
	CRC.polynomial = POLYNOMIAL_4;                      //user polynomial
	CRC.polySize = SIZE_4_BITS;                       //polynomial size
	CRC.dataSize = SIZE_8_BITS;                       //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run4BitENDATTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	//*****************************************************************************************
	// FIRST EXAMPLE: 128 bytes, Parity is low byte first and CRC computation in reflected mode
	//*****************************************************************************************
	CRC.nMsgBytes = 128;                     //enter the number of message bytes
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytes;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//*************************************************************************************************
	// SECOND EXAMPLE: 7 bytes(<8, odd), Parity is low byte first and CRC computation in reflected mode
	//*************************************************************************************************
	CRC.nMsgBytes = 7;                       //enter the number of message bytes
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer

	// Step 1: Calculate the golden value using the C routine
	CRC.run = (void (*)(void*)) CRC_run4BitENDATTableLookupC;
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytes;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//****************************************************************************************************
	//Example 3 and 4 - Bit wise 4 bit CRC computation for different Msg Sizes -> 13, 51 bits respectively

	//**************************************************************************************************
	// THIRD EXAMPLE: 13 bits, Parity is low byte first and CRC computation in reflected mode
	//**************************************************************************************************
	CRC.nMsgBits = 13;              //add the number of data bits to compute CRC
	CRC.nMsgBytes = 0; //we can keep MsgBytes = 0 for bit mode test as it is not required
	CRC.pMsgBuffer = testInput;                        //point to the test input

	// Step 1: Calculate the golden value using the C routine
	CRC.run = (void (*)(void*)) CRC_run4BitENDATBitTableLookupC_Generic;
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//*************************************************************************
	// FOURTH EXAMPLE: 51 bits, parity: low byte first
	//*************************************************************************
	CRC.nMsgBits = 51;              //add the number of data bits to compute CRC
	CRC.nMsgBytes = 0; //we can keep MsgBytes = 0 for bit mode test as it is not required
	CRC.pMsgBuffer = testInput;                        //point to the test input
	CRC.dataSize = SIZE_8_BITS; //initialize the initial data size to 8 bits as it gets overwritten by the remaining bits from the previous computation of CRC
	// Step 1: Calculate the golden value using the C routine
	CRC.run = (void (*)(void*)) CRC_run4BitENDATBitTableLookupC_Generic;
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//***************************************************************************************
	//Example 5 and 6 - Byte wise 16 bit CRC computation for Msg Sizes - 8, 128 bytes of data

	//***************************************************************************************
	// FIFTH EXAMPLE: 8 Bytes, Parity is low byte first and CRC computation in reflected mode
	//***************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 8; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P2Table; //proper form &crc16P2Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P2;                     //user polynomial
	CRC.polySize = SIZE_16_BITS;                         //polynomial size
	CRC.dataSize = SIZE_8_BITS;                          //data size
	CRC.nMsgBits = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.reflected = 0; //initialize the CRC routine by context save and context restore calls
	CRC.init = (void (*)(void*)) CRC_init16Bit; //point to the C routine or lookup table for CRC computation through software
	CRC.run = (void (*)(void*)) CRC_run16BitTableLookupC;
	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*))CRC_runConfigPolyBytes;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//*********************************************************************************************
	// SIXTH EXAMPLE: 128 bytes, Parity is low byte first and CRC computation in non-reflected mode
	//*********************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 128; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P1TableReflected; //proper form &crc16P1TableReflected[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P1;                      //user polynomial
	CRC.polySize = SIZE_16_BITS;                          //polynomial size
	CRC.dataSize = SIZE_8_BITS;                           //data size
	CRC.reflected = 1; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitReflectedTableLookupC; //point to the C routine or lookup table for CRC computation through software
	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytesReflected;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//******************************************************************************************
	// Example 7 and 8 - Bit wise 16 bit CRC computation for Msg Sizes - 48, 128 bits of data

	//******************************************************************************************************
	// SEVENTH EXAMPLE: 48 bits(i.e 6 bytes), Parity is low byte first and CRC computation in reflected mode
	//******************************************************************************************************

	// Step 1: Initialize CRC objects
	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 6; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 48;            //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P2Table; //proper form &crc16P2Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P2;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                              //polynomial size
	CRC.dataSize = SIZE_8_BITS;                               //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//********************************************************************************************
	// EIGHTH EXAMPLE: 128 bits, Parity is low byte first and CRC computation in non-reflected mode
	//********************************************************************************************
	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 16; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 128;           //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P1TableReflected; //proper form &crc16P1TableReflected[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P1;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                //data size
	CRC.reflected = 1; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitReflectedTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBitsReflected;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//***************************************************************************************************
	// Example 9 and 10 - Byte wise 16 bit CRC computation for different Msg Sizes - 10, 15 bytes of data
	//***************************************************************************************************
	// NINETH EXAMPLE: 10 bytes, Parity is high byte first and CRC computation in reflected mode
	//******************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 10; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_odd; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P1Table; //proper form &crc16P1Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P1;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytes;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//*********************************************************************************************
	// TENTH EXAMPLE: 15 bytes, Parity is high byte first and CRC computation in non-reflected mode
	//*********************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 15; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_odd; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P1TableReflected; //proper form &crc16P1TableReflected[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P1;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                 //data size
	CRC.reflected = 1; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitReflectedTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytesReflected;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//*************************************************************************************
	// Example 11 and 12 - Bit wise 16 bit CRC computation for Msg Sizes - 6 bytes of data

	//*******************************************************************************************
	// ELEVENTH EXAMPLE: 48 bits, Parity is high byte first and CRC computation in reflected mode
	//*******************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 6; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 48;            //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_odd; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P2Table; //proper form &crc16P2Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P2;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                   //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitTableLookupC; //point to the C routine or lookup table for CRC computation through software
	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//***********************************************************************************************
	// TWELVETH EXAMPLE: 48 bits, Parity is high byte first and CRC computation in non-reflected mode
	//***********************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 6; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 48;            //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_odd; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P2TableReflected; //proper form &crc16P2TableReflected[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P2;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                   //data size
	CRC.reflected = 1; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitReflectedTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBitsReflected;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//***************************************************************************************************************
	// Example 13 and 14 - Bit wise 16 bit CRC computation for MODBUS protocol with P2 polynomial for 48 bits of data

	//************************************************************************************************
	// THIRTEENTH EXAMPLE: 48 bits, Parity is low byte first and CRC computation in non-reflected mode
	//************************************************************************************************

	CRC.seedValue = CRC_INIT_CRC16MODBUS; //enter the seed value for CRC computation
	CRC.nMsgBytes = 6; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 48;            //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P2TableReflected; //proper form &crc16P2TableReflected[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P2;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                   //data size
	CRC.reflected = 1; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitReflectedTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code (generic instructions)
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBitsReflected;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//*********************************************************************************************
	// FOURTEENTH EXAMPLE : 48 bits, Parity is low byte first and CRC computation in reflected mode
	//*********************************************************************************************

	CRC.seedValue = CRC_INIT_CRC16MODBUS; //enter the seed value for CRC computation
	CRC.nMsgBytes = 6; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 48;            //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint16_t*) crc16P2Table; //proper form &crc16P2Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_16_P2;                         //user polynomial
	CRC.polySize = SIZE_16_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                   //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run16BitTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint16_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint16_t) CRC.crcResult;

	//***************************************************************************************************
	// Example 15 and 16 - Byte wise 32 bit CRC computation for P1 polynomial for Msg Sizes - 16, 6 bytes

	//************************************************************************************************
	// FIFTEENTH EXAMPLE: 16 bytes, Parity is low byte first and CRC computation in non reflected mode
	//************************************************************************************************

	CRC.seedValue = CRC_INIT_CRC32;   //enter the seed value for CRC computation
	CRC.nMsgBytes = 16; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc32P1TableReflected; //proper form &crc16P1TableReflected[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_32_P1;                         //user polynomial
	CRC.polySize = SIZE_32_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 1; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init32Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run32BitReflectedTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytesReflected;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	//*******************************************************************************************
	// SIXTEENTH EXAMPLE: 6 bytes, Parity is low byte first and CRC computation in reflected mode
	//*******************************************************************************************

	CRC.seedValue = CRC_INIT_CRC32;   //enter the seed value for CRC computation
	CRC.nMsgBytes = 6; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc32P1Table; //proper form &crc16P1Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_32_P1;                         //user polynomial
	CRC.polySize = SIZE_32_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init32Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run32BitTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytes;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	//***************************************************************************************************
	// Example 17 and 18 - Bit wise 32 bit CRC computation for P1 polynomial for Msg Sizes - 48, 128 bits

	//*************************************************************************************************
	// SEVENTEENTH EXAMPLE: 48 bits, Parity is low byte first and CRC computation in non reflected mode
	//*************************************************************************************************

	CRC.seedValue = CRC_INIT_CRC32;   //enter the seed value for CRC computation
	CRC.nMsgBytes = 6; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 48;            //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc32P1TableReflected; //proper form &crc16P1TableReflected[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_32_P1;                         //user polynomial
	CRC.polySize = SIZE_32_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 1; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init32Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run32BitReflectedTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBitsReflected;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	//*********************************************************************************************
	// EIGHTEENTH EXAMPLE: 128 bits, Parity is low byte first and CRC computation in reflected mode
	//*********************************************************************************************

	CRC.seedValue = CRC_INIT_CRC32;   //enter the seed value for CRC computation
	CRC.nMsgBytes = 16; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 128;           //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc32P1Table; //proper form &crc16P1Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_32_P1;                         //user polynomial
	CRC.polySize = SIZE_32_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init32Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run32BitTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	//*********************************************************************************************
	// Example 19 and 20 - Byte wise 17 bit CRC computation for Msg Size - 16 bytes
	//*********************************************************************************************
	// NINETEENTH EXAMPLE: 128 bits, Parity is low byte first and CRC computation in reflected mode
	//*********************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 16; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc16P2Table; //proper form &crc16P1Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_17;                            //user polynomial
	CRC.polySize = SIZE_17_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run17BitCANFDTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytes;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	//******************************************************************************************
	// Bit wise 17 bit CRC computation for Msg Size - 128 bits
	//*******************************************************************************************
	// TWENTYTH EXAMPLE: 128 bits, Parity is low byte first and CRC computation in reflected mode
	//*******************************************************************************************

	CRC.seedValue = CRC_INIT_16;      //enter the seed value for CRC computation
	CRC.nMsgBytes = 16; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 128;           //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc16P2Table; //proper form &crc16P1Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_17;                            //user polynomial
	CRC.polySize = SIZE_17_BITS;                               //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run17BitCANFDTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	//*************************************************************************
	// Example 21 and 2 - Bit wise 8 bit CRC computation for Msg Size - 32 bits
	//*************************************************************************

	// TWENTYONETH EXAMPLE: 32 bits, Parity is low byte first and CRC computation in reflected mode
	//*********************************************************************************************

	CRC.seedValue = CRC_INIT_8;       //enter the seed value for CRC computation
	CRC.nMsgBytes = 4; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 32;            //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_even; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc8Table; //proper form &crc16P1Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_8;                             //user polynomial
	CRC.polySize = SIZE_8_BITS;                                //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                      //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run8BitTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBits;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	//*****************************************************
	// Byte wise 8 bit CRC computation for Msg Size 56 bits

	//*********************************************************************************************
	// TWENTYTWOTH EXAMPLE: 32 bits, Parity is low byte first and CRC computation in reflected mode
	//*********************************************************************************************

	CRC.seedValue = CRC_INIT_8;       //enter the seed value for CRC computation
	CRC.nMsgBytes = 7; //enter the number of bytes on which the CRC is to be computated
	CRC.nMsgBits = 0;             //enter the number of bits for CRC computation
	CRC.parity = CRC_parity_odd; //choose to compute CRC for lower byte(8 bits) first or upper byte first based on the parity value
	CRC.crcResult = 0;              //CRC result would be stored in the location
	CRC.pMsgBuffer = testInput;                  //pointer to the message buffer
	CRC.pCrcTable = (uint32_t*) crc8Table; //proper form &crc16P1Table[0],  Not Required when we have a C code to compute CRC on the fly e.g. in case of 4 bit CRC
	CRC.polynomial = POLYNOMIAL_8;                             //user polynomial
	CRC.polySize = SIZE_8_BITS;                                //polynomial size
	CRC.dataSize = SIZE_8_BITS;                                    //data size
	CRC.reflected = 0; //Whether the computation is to be done from LSB or MSB, if CRC.reflected = 1 then the data bytes would be flipped before CRC computation
	CRC.init = (void (*)(void*)) CRC_init16Bit; //initialize the CRC routine by context save and context restore calls
	CRC.run = (void (*)(void*)) CRC_run8BitTableLookupC; //point to the C routine or lookup table for CRC computation through software

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 1: Calculate the golden value using the C routine
	CRC.run(handleCRC);
	goldenOutput[index] = (uint32_t) CRC.crcResult;

	// Step 2: run the CRC module with the VCRC assembly code
	CRC.run = (void (*)(void*)) CRC_runConfigPolyBytes;
	CRC.run(handleCRC);
	TestOutput[index++] = (uint32_t) CRC.crcResult;

	// self checking
	pass = 0;
	fail = 0;

	for (index = 0; index < NO_OF_TESTS; index++) {
		if (TestOutput[index] == goldenOutput[index]) {
			pass++;
		} else {
			fail++;
		}
	}
	//if the any of the example fails - code will loop forever in error function
	if (pass != NO_OF_TESTS) {
		return -1;
	}
	return 0;
}

void CRC_run4BitENDATTableLookupC(CRC_Handle hndCRC)
{
	int16_t  i,j;
	uint16_t data;
	uint16_t parity        = (uint16_t)hndCRC->parity;
	uint16_t accumulator   = hndCRC->seedValue;
	uint16_t *pInputVector = (uint16_t *)hndCRC->pMsgBuffer;
	uint16_t poly = 0x0003;
	uint16_t polySize = 4;

	// The assumption is the message bytes are packed into 16-bit words
	// and the calculation starts from either the high or low byte
	// The memory arrangement is as follows:
	// Address|_LB__|_HB__|
	// 0x0000 |_D0L_|_D0H_|
	// 0x0001 |_D1L_|_D1H_|
	// 0x0002 |_D2L_|_D2H_|
	// 0x0003 |_D3L_|_D3H_|
	// 0x0004 |_D4L_|_D4H_|
	// ...

	poly <<= (8 - polySize);

	for(i = 0; i < hndCRC->nMsgBytes; i++, parity++){
		// __byte selects either the low(0) or high(1) byte in a word
		// the initial selection provided by the enumeration parity
		// the table index is calculated from the high byte of the accumulator
		// XOR'd with the low and high bytes of each word in the input vector
		if(parity%2==0)
		{
			data = (uint16_t) (pInputVector[parity/2]&0xff);
		}
		else
		{
			data = (uint16_t) ((pInputVector[parity/2]>>8)&0xff);
		}

		accumulator ^= data;
		for (j = 0; j < 8; j++) {
			accumulator <<= 1;
			if (accumulator & 0x0100) {
				accumulator ^= poly;
			}
		}
		accumulator &= 0x00FF;
	}
	// Save the CRC result
	hndCRC->crcResult = (uint32_t)accumulator >> (8 - polySize);
}

void CRC_run4BitENDATBitTableLookupC_Generic(CRC_Handle hndCRC)
{
	int16_t  i;
	uint16_t data;

	uint16_t parity        = (uint16_t)hndCRC->parity;
	uint16_t accumulator   = hndCRC->seedValue;
	uint16_t *pInputVector = (uint16_t *)hndCRC->pMsgBuffer;

	uint16_t poly = 0x0003;
	uint32_t NumOfBits = hndCRC->nMsgBits;
	uint16_t bitPlace = 7;
	uint16_t newWordNext = 1;

	// The assumption is the message bytes are packed into 16-bit words
	// and the calculation starts from either the high or low byte
	// The memory arrangement is as follows:
	// Address|_LB__|_HB__|
	// 0x0000 |_D0L_|_D0H_|
	// 0x0001 |_D1L_|_D1H_|
	// 0x0002 |_D2L_|_D2H_|
	// 0x0003 |_D3L_|_D3H_|
	// 0x0004 |_D4L_|_D4H_|
	// ...

	for(i = 0; i < NumOfBits; i++){
		// __byte selects either the low(0) or high(1) byte in a word
		// the initial selection provided by the enumeration parity
		// the table index is calculated from the high byte of the accumulator
		// XOR'd with the low and high bytes of each word in the input vector
		if (newWordNext) {
			if(parity%2==0)
			{
				data = (uint16_t) (pInputVector[parity/2]&0xff);
			}
			else
			{
				data = (uint16_t) ((pInputVector[parity/2]>>8)&0xff);
			}
			parity++;
			newWordNext = 0;
			if ((NumOfBits - i) <= 8) {
				bitPlace = NumOfBits - i - 1;
			}
		}
		accumulator <<= 1;
		if (((accumulator & 0x0010)>>4) != (((data & (1<<bitPlace)))>>bitPlace)) {
			accumulator ^= poly;
		}
		accumulator &= 0x00F;
		if (!bitPlace) {
			newWordNext = 1;
			bitPlace = 7;
		} else {
			bitPlace--;
		}
	}
	// Save the CRC result
	hndCRC->crcResult = (uint32_t)accumulator;
}
void CRC_run17BitCANFDTableLookupC(CRC_Handle hndCRC)
{
    int16_t  i,j;
    uint16_t data;

    uint16_t parity        = (uint16_t)hndCRC->parity;
    uint32_t accumulator   = hndCRC->seedValue;
    uint16_t *pInputVector = (uint16_t *)hndCRC->pMsgBuffer;

    // The assumption is the message bytes are packed into 16-bit words
    // and the calculation starts from either the high or low byte
    // The memory arrangement is as follows:
    // Address|_LB__|_HB__|
    // 0x0000 |_D0L_|_D0H_|
    // 0x0001 |_D1L_|_D1H_|
    // 0x0002 |_D2L_|_D2H_|
    // 0x0003 |_D3L_|_D3H_|
    // 0x0004 |_D4L_|_D4H_|
    // ...

    for(i = 0; i < hndCRC->nMsgBytes; i++, parity++){
        // __byte selects either the low(0) or high(1) byte in a word
        // the initial selection provided by the enumeration parity
        // the table index is calculated from the high byte of the accumulator
        // XOR'd with the low and high bytes of each word in the input vector
		if(parity%2==0)
		{
			data = (uint16_t) (pInputVector[parity/2]&0xff);
		}
		else
		{
			data = (uint16_t) ((pInputVector[parity/2]>>8)&0xff);
		}
        accumulator ^= (uint32_t)data << 9;
        for (j = 0; j < 8; j++) {
            accumulator <<= 1;
            if (accumulator & 0x20000) {
                accumulator ^= 0x1685B;
            }
        }
        accumulator &= 0x1FFFF;
    }

    // Save the CRC result
    hndCRC->crcResult = (uint32_t)accumulator;
}

