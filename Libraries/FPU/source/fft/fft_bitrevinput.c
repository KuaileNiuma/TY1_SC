/** 
  *************************************************************************************
  * @file fft_bitrevinput.c 
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
DSP_FILENUM(31)

//*****************************************************************************
// FFT_bitReverseInput()
//*****************************************************************************
void FFT_bitReverseInput(FFTHandle hnd)
{    
   // Locals
    uint16_t i, bri, j, brj, k, brk;
    uint16_t N     = FFT_getSize(hnd);
    uint16_t nbits;
    fsize_t t_r, t_i;
    fsize_t *io    = FFT_getIOBufferPtr(hnd);
    
#ifdef _DEBUG
    printf("Bit Reversal of array of %d values\n", N);
#endif    
    if((FFT_getType(hnd) == COMPLEX_RADIX_2) ||
       (FFT_getType(hnd) == COMPLEX_RADIX_4) ||
       (FFT_getType(hnd) == ALT_REAL_RADIX_2))
    {
        // Do nothing
    }
    else if ((FFT_getType(hnd) == REAL_RADIX_2) ||
             (FFT_getType(hnd) == REAL_RADIX_4))
    {
        N = N >> 1; // must treat real input as N/2 complex and then bit-rev
    }
    else 
    {
        DSP_ASSERT(0U); //Type is invalid
    }   
    nbits = log2(N);
#ifdef _DEBUG
    printf("Each %d-bit index is reversed \n", nbits);
#endif  

    if(FFT_getType(hnd) == ALT_REAL_RADIX_2)
    {
        for(i = 0U; i < N; i++)
        {
            bri = FFT_bitReverseIndex(i, nbits);
            
            if(i < bri)
            {
                // Exhcange
                t_i       = io[i];
                io[i]     = io[bri];
                io[bri]   = t_i;
#ifdef _DEBUG
            printf("    Reversing i=%4d, br_i=%4d\n", i, bri);
#endif
            }
            else
            {
#ifdef _DEBUG
            printf("Not Reversing i=%4d, br_i=%4d\n", i, bri);
#endif            
            }
        }
    }
    else
    {
        for(i = 0U, j = i, k =j+1; i < N; i++, j += 2U, k += 2U)
        {
            bri = FFT_bitReverseIndex(i, nbits);
            brj = bri << 1; // accounts for the complex size
            brk = brj + 1;        
            
            if(i < bri)
            {
                // Exhcange
                t_r       = io[j];
                t_i       = io[k];
                io[j]     = io[brj];
                io[k]     = io[brk];
                io[brj]   = t_r;
                io[brk]   = t_i;
#ifdef _DEBUG
            printf("    Reversing i=%4d, br_i=%4d\n", j, brj);
#endif
            }
            else
            {
#ifdef _DEBUG
            printf("Not Reversing i=%4d, br_i=%4d\n", j, brj);
#endif            
            }
        }
    }
}

// End of File
