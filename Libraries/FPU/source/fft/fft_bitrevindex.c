/** 
  *************************************************************************************
  * @file fft_bitrevindex.c 
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
// the includes
//*****************************************************************************
#include "fft.h"
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(30)

//*****************************************************************************
// FFT_bitReverseIndex()
//*****************************************************************************
uint32_t FFT_bitReverseIndex(uint32_t idx, uint16_t nbits)
{    
    // Locals
    // exchange every adjacent bit
    idx = ((idx & 0xAAAAAAAA) >> 1)  | ((idx & 0x55555555) << 1);
    // exchange every bit pair       
    idx = ((idx & 0xCCCCCCCC) >> 2)  | ((idx & 0x33333333) << 2);
    // exchange every nibble         
    idx = ((idx & 0xF0F0F0F0) >> 4)  | ((idx & 0x0F0F0F0F) << 4);
    // exchange every byte           
    idx = ((idx & 0xFF00FF00) >> 8)  | ((idx & 0x00FF00FF) << 8);
    // exchange every word
    idx = ((idx & 0xFFFF0000) >> 16) | ((idx & 0x0000FFFF) << 16);
    // Shift right to get only nbits
    idx >>= (32 - nbits);
    
    return(idx);    
}

// End of File
