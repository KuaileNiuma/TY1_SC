/** 
  *************************************************************************************
  * @file vcu2_crc_16.c 
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
void CRC_init16Bit(CRC_Handle hndCRC) {
	__builtin_riscv_crccr_w(0x00000000);

}
void CRC_run16BitPoly1(CRC_Handle hndCRC) {
	uint16_t i;
	uint16_t tableIndex;
	uint16_t parity = (uint16_t) hndCRC->parity;
	uint16_t accumulator = hndCRC->seedValue;
	uint16_t *pInputVector = (uint16_t *)hndCRC->pMsgBuffer;
	uint8_t data;

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
	__builtin_riscv_crccr_w(0x00000000);
	__builtin_riscv_crcrr_w(accumulator);
	for (i = 0; i < hndCRC->nMsgBytes; i++, parity++) {
		// __byte selects either the low(0) or high(1) byte in a word
		// the initial selection provided by the enumeration parity
		// the table index is calculated from the high byte of the accumulator
		// XOR'd with the low and high bytes of each word in the input vector
		if(parity%2==0)
		{
			data=pInputVector[parity/2]&0xff;
		}
		else
		{
			data= (pInputVector[parity/2]>>8)&0xff;
		}
		__builtin_riscv_crc16p1_byte((data));
	}
	accumulator = __builtin_riscv_crcrr_r();

	// Save the CRC result
	hndCRC->crcResult = (uint32_t) accumulator;
}
void CRC_run16BitPoly2(CRC_Handle hndCRC) {
	uint16_t i;
	uint16_t tableIndex;
	uint16_t parity = (uint16_t) hndCRC->parity;
	uint16_t accumulator = hndCRC->seedValue;
	uint16_t *pInputVector = (uint16_t*) hndCRC->pMsgBuffer;
	uint8_t data;
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
	__builtin_riscv_crccr_w(0x00000000);

	__builtin_riscv_crcrr_w(accumulator);
	for (i = 0; i < hndCRC->nMsgBytes; i++, parity++) {
		// __byte selects either the low(0) or high(1) byte in a word
		// the initial selection provided by the enumeration parity
		// the table index is calculated from the high byte of the accumulator
		// XOR'd with the low and high bytes of each word in the input vector
		if(parity%2==0)
		{
			data=pInputVector[parity/2]&0xff;
		}
		else
		{
			data= (pInputVector[parity/2]>>8)&0xff;
		}
		__builtin_riscv_crc16p2_byte((data));
	}
	accumulator = __builtin_riscv_crcrr_r();


	// Save the CRC result
	hndCRC->crcResult = (uint32_t) accumulator;
}
void CRC_run16BitPoly1Reflected(CRC_Handle hndCRC) {
	uint16_t i;
	uint16_t tableIndex;
	uint16_t parity = (uint16_t) hndCRC->parity;
	uint16_t accumulator = hndCRC->seedValue;
	uint16_t *pInputVector = (uint16_t*) hndCRC->pMsgBuffer;
	uint8_t data;

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

	__builtin_riscv_crccr_w(0x80000000);
	__builtin_riscv_crcrr_w(accumulator);
	for (i = 0; i < hndCRC->nMsgBytes; i++, parity++) {
		// __byte selects either the low(0) or high(1) byte in a word
		// the initial selection provided by the enumeration parity
		// the table index is calculated from the high byte of the accumulator
		// XOR'd with the low and high bytes of each word in the input vector
		if(parity%2==0)
		{
			data=pInputVector[parity/2]&0xff;
		}
		else
		{
			data= (pInputVector[parity/2]>>8)&0xff;
		}
		__builtin_riscv_crc16p1_byte((data));
	}
	accumulator = __builtin_riscv_crcrr_r();


	__builtin_riscv_crccr_w(0x00000000);

	// Save the CRC result
	hndCRC->crcResult = (uint32_t) accumulator;
}
void CRC_run16BitPoly2Reflected(CRC_Handle hndCRC) {
	uint16_t i;
	uint16_t tableIndex;
	uint16_t parity = (uint16_t) hndCRC->parity;
	uint16_t accumulator = hndCRC->seedValue;
	uint16_t *pInputVector = (uint16_t*) hndCRC->pMsgBuffer;
	uint8_t data;

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

	__builtin_riscv_crccr_w(0x80000000);
	__builtin_riscv_crcrr_w(accumulator);
	for (i = 0; i < hndCRC->nMsgBytes; i++, parity++) {
		// __byte selects either the low(0) or high(1) byte in a word
		// the initial selection provided by the enumeration parity
		// the table index is calculated from the high byte of the accumulator
		// XOR'd with the low and high bytes of each word in the input vector
		if(parity%2==0)
		{
			data=pInputVector[parity/2]&0xff;
		}
		else
		{
			data= (pInputVector[parity/2]>>8)&0xff;
		}
		__builtin_riscv_crc16p2_byte((data));
	}
	accumulator = __builtin_riscv_crcrr_r();
	__builtin_riscv_crccr_w(0x00000000);

	// Save the CRC result
	hndCRC->crcResult = (uint32_t) accumulator;
}
