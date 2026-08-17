/** 
  *************************************************************************************
  * @file CRC32_main.c 
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
#include "CRC_main.h"
#include "vcu2_types.h"
#include "vcu2_crc.h"
extern const unsigned long crc32P1Table[];
extern const unsigned long crc32P1TableReflected[];
extern const unsigned long crc32P2Table[];
extern const unsigned long crc32P2TableReflected[];

//*****************************************************************************
// defines
//*****************************************************************************
#define     NBYTES        (128)
#define     NWORDS        (NBYTES/2)

// \brief object of the structure CRC_Obj
//
static CRC_Obj CRC;
// \brief handle(pointer) to the CRC object
//
static CRC_Handle handleCRC;

static uint16_t pass = 0;
static uint16_t fail = 0;
//\brief test input
//
// This vector is declared as a static const in order for the linker to
// be able to run the CRC algorithm on it. It needn't be either static
// or const for the C and VCU routines
//
static const uint16_t testInput[NWORDS] = {
    0x4001, 0x8002, 0xC003, 0x0004, 0x4005, 0x8006, 0xC007, 0x0008,
    0x4009, 0x800A, 0xC00B, 0x000C, 0x400D, 0x800E, 0xC00F, 0x0010,
    0x4011, 0x8012, 0xC013, 0x0014, 0x4015, 0x8016, 0xC017, 0x0018,
    0x4019, 0x801A, 0xC01B, 0x001C, 0x401D, 0x801E, 0xC01F, 0x0020,
    0x4021, 0x8022, 0xC023, 0x0024, 0x4025, 0x8026, 0xC027, 0x0028,
    0x4029, 0x802A, 0xC02B, 0x002C, 0x402D, 0x802E, 0xC02F, 0x0030,
    0x4031, 0x8032, 0xC033, 0x0034, 0x4035, 0x8036, 0xC037, 0x0038,
    0x4039, 0x803A, 0xC03B, 0x003C, 0x403D, 0x803E, 0xC03F, 0x0040,
};



int CRC32_main(void){
	// Locals
	int16_t i;
	uint32_t crcResultC_1, crcResultC_2;
	uint32_t crcResultVcu_1, crcResultVcu_2;

	//*************************************************************************
	// Example #1: 128 bytes(x8, even), parity: low byte first
	//*************************************************************************
	//! \b Example \b #1, \b Part \b 1
	//! In this section we run a table lookup CRC on the vector testInput. The
	//! table is specified in the header files "CrcTable0x04C11DB7.h" and
	//! "CrcTable0x1EDC6F41.h"respectively and the entries were generated from the
	//! polynomials \f$ x^{32}+x^{26}+x^{23}+x^{22}+x^{16}+x^{12}+x^{11}+x^{10}+x^{8}+x^{7}+x^{5}+x^{4}+x^{2}+x^{1}+1 \f$(CCITT-32, 0x04C11DB7) and
	//! \f$ x^{32}+x^{28}+x^{27}+x^{26}+x^{25}+x^{23}+x^{22}+x^{20}+x^{19}+x^{18}+x^{14}+x^{13}+x^{11}+x^{10}+x^{9}+x^{8}+x^{6}+1 \f$(0x1EDC6F41) respectively.
	//! The parity chosen was CRC_parity_even indicating that the CRC will start
	//! from the low byte of the first word.
	//! \code
	//*************************************************************************
	// Step 1: Initialize the CRC object
	CRC.seedValue = INIT_CRC32;
	CRC.nMsgBytes = NBYTES;
	CRC.parity = CRC_parity_even;
	CRC.crcResult = 0;
	CRC.pMsgBuffer = (uint16_t*) &testInput[0];
	CRC.pCrcTable = (uint16_t*) &crc32P1Table[0];
	CRC.init = (void (*)(void*)) CRC_init32Bit;
	CRC.run = (void (*)(void*)) CRC_run32BitTableLookupC;

	// Step 2: Initialize the handle
	handleCRC = &CRC;

	// Step 3: Run the 32-bit table look-up CRC routine and save the first result
	CRC.init(handleCRC);
	CRC.run(handleCRC);
	crcResultC_1 = CRC.crcResult;

	// Step 4: Load the second lookup table and run the C routine
	CRC.pCrcTable = (uint16_t*) &crc32P2Table[0];
	CRC.crcResult = 0;
	CRC.run(handleCRC);
	crcResultC_2 = CRC.crcResult;

	//*************************************************************************
	//! \endcode
	//!
	//! \b Example \b #1, \b Part \b 2
	//! Now we run the VCU routine on the vector testInput. The two
	//! polynomials employed by the VCU are  fixed i.e.
	//! \f$ x^{32}+x^{26}+x^{23}+x^{22}+x^{16}+x^{12}+x^{11}+x^{10}+x^{8}+x^{7}+x^{5}+x^{4}+x^{2}+x^{1}+1 \f$(CCITT-32, 0x04C11DB7) and
	//! \f$ x^{32}+x^{28}+x^{27}+x^{26}+x^{25}+x^{23}+x^{22}+x^{20}+x^{19}+x^{18}+x^{14}+x^{13}+x^{11}+x^{10}+x^{9}+x^{8}+x^{6}+1 \f$(0x1EDC6F41) respectively
	//! The parity chosen was CRC_parity_even indicating that the CRC will start
	//! from the low byte of the first word.
	//!
	//! Most of the object elements remain unchanged from the initial setup
	//!
	//! \note The VCU routine does not require a lookup table; pCrcTable can be
	//! reset to NULL or left as-is
	//! \code
	//*************************************************************************
	// Step 1: Reset a few elements of the CRC object
	CRC.crcResult = 0;
	CRC.run = (void (*)(void*)) CRC_run32BitPoly1;

	// Step 2: Run the VCU 32-bit CRC routine and save the result
	CRC.run(handleCRC);
	crcResultVcu_1 = CRC.crcResult;

	// Step 3: Now for the other polynomial
	CRC.crcResult = 0;
	CRC.run = (void (*)(void*)) CRC_run32BitPoly2;

	// Step 4: Run the VCU 32-bit CRC routine and save the result
	CRC.run(handleCRC);
	crcResultVcu_2 = CRC.crcResult;

	// Step 5: Compare the results
	(crcResultC_1 == crcResultVcu_1) ? pass++ : fail++;
	(crcResultC_2 == crcResultVcu_2) ? pass++ : fail++;

	//*************************************************************************
	//! \endcode
	//!
	//! \b Example \b #2
	//! We now run the reflected algorithm using both a table lookup method and
	//! compare it against its equivalent VCU routine. The reflected CRC
	//! table is specified in the header files "CrcTable0x04C11DB7Reflected.h" and
	//! "CrcTable0x1EDC6F41Reflected.h"; the entries were generated from the table
	//! indices 0,1,...255 by shifting out the LSB of the index and XOR'ing the
	//! remainder with the polynomial if the LSB was a 1
	//! The parity chosen was CRC_parity_even indicating that the CRC will start
	//! from the low byte of the first word.
	//! \code
	//*************************************************************************
	// Step 1: For the C routine, assign the correct look-up table and function
	// to the object and reset the CRC result
	CRC.crcResult = 0;
	CRC.pCrcTable = (uint16_t*) &crc32P1TableReflected[0];
	CRC.run = (void (*)(void*)) CRC_run32BitReflectedTableLookupC;

	// Step 2: Run the C routine, reflect and save the result
	CRC.run(handleCRC);
	crcResultC_1 = (uint32_t) (CRC_bitReflect((uint32_t) CRC.crcResult, 32));

	// Step 3: Replace the lookup table with that of the second polynomial
	CRC.crcResult = 0;
	CRC.pCrcTable = (uint16_t*) &crc32P2TableReflected[0];
	CRC.run(handleCRC);
	crcResultC_2 = (uint32_t) (CRC_bitReflect((uint32_t) CRC.crcResult, 32));

	// Step 4: Assign the VCU routine to the object and run it
	CRC.crcResult = 0;
	CRC.run = (void (*)(void*)) CRC_run32BitPoly1Reflected;
	CRC.run(handleCRC);
	crcResultVcu_1 = CRC.crcResult;

	// Step 5: Assign the VCU routine(2nd polynomial) to the object and run it
	CRC.crcResult = 0;
	CRC.run = (void (*)(void*)) CRC_run32BitPoly2Reflected;
	CRC.run(handleCRC);
	crcResultVcu_2 = CRC.crcResult;

	// Step 6: Compare the results of steps 2/3 with 4/5
	(crcResultC_1 == crcResultVcu_1) ? pass++ : fail++;
	(crcResultC_2 == crcResultVcu_2) ? pass++ : fail++;

	//if the any of the example fails - code will loop forever in error function
	if (fail > 0) {
		return -1;
	}
	return 0;

}
