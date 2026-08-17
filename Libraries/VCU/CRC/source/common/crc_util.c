/** 
  *************************************************************************************
  * @file crc_util.c 
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
uint32_t CRC_bitReflect(uint32_t valToReverse,int16_t bitWidth)
{
	int16_t i,j,p,t;
	uint32_t pattern, skip;
	//unsigned int a, b;
	uint32_t value = valToReverse;

	//Determine what power of 2 bitWidth is
	t = bitWidth; p = 0;
	while(t > 1){
		t = t >> 1;
		p++;
	}

	//Start the reversing process
	for(i = 0; i < p; i++){
		//Increment skip
		skip = CRC_pow2(i);

		//Initialize pattern
		pattern = 0xFFFFFFFF;
		//First generate the pattern for the switch
		for(j = 0; j < (bitWidth/skip)-1; j++){
			pattern ^= (pattern << skip);
		}

		//Make the switch
		//a = ((value & pattern) << skip);
		//b = ((value >> skip) & pattern);
		//value = a | b;
		value = (((value & pattern) << skip) | ((value >> skip) & pattern));
	}

	return value;

}


uint16_t CRC_pow2(uint16_t power)
{
	if (power == 0){
		return 1;
	}else{
		return(2 * CRC_pow2(--power));
	}
}
// End of file
