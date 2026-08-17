/** 
  *************************************************************************************
  * @file crc_8.c 
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
#include "vcu2_crc.h"
//*****************************************************************************
// defines
//*****************************************************************************

//*****************************************************************************
// globals
//*****************************************************************************


//*****************************************************************************
// function definitions
//*****************************************************************************

void CRC_run8BitTableLookupC(CRC_Handle hndCRC)
{
	uint32_t i;
	uint16_t tableIndex;
	uint16_t accumulator   = hndCRC->seedValue;
	uint16_t parity        = (uint16_t)hndCRC->parity;
	uint16_t *pInputVector = (uint16_t *)hndCRC->pMsgBuffer;
	uint16_t *pCrcTable    = (uint16_t *)hndCRC->pCrcTable;
	uint8_t data;

	// The assumption is the message bytes are packed into 16-bit words
	// and the calculation starts from from either the high or low byte
	// The memory arrangement is as follows
	// Address|__LB__|__HB__|
	// 0x0000 |__D0__|__D1__|
	// 0x0001 |__D2__|__D3__|
	// 0x0002 |__D4__|__D5__|
	// 0x0003 |__D6__|__D7__|
	// 0x0004 |__D8__|__D9__|
    // ...

	for(i = 0; i < hndCRC->nMsgBytes; i++, parity++){
		// __byte selects either the low(0) or high(1) byte in a word
		// the initial selection provided by the enumeration parity
		if(parity%2==0)
		{
			data=pInputVector[parity/2]&0xff;
		}
		else
		{
			data= (pInputVector[parity/2]>>8)&0xff;
		}
		tableIndex = accumulator ^ (data);
		accumulator = pCrcTable[tableIndex];
	}

	// Save the CRC result
	hndCRC->crcResult = (uint32_t)(accumulator & 0x00FF);
}

// End of file
