/** 
  *************************************************************************************
  * @file fft_inversereal.c 
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
DSP_FILENUM(34)

//*****************************************************************************
// FFT_runIRFFT()
//*****************************************************************************
void FFT_runIRFFT(FFTHandle hnd)
{    
    // Locals
    uint16_t  N;
    fsize_t *temp;
    
    // Run the pack function
    FFT_pack(hnd);
    
    // The output of the pack is in the io2 buffer, the inverse complex FFTHandle
    // expects its input in the io buffer, we exchange the pointers
    temp = FFT_getIOBufferPtr(hnd);
    FFT_setIOBufferPtr(hnd, FFT_getIOBuffer2Ptr(hnd));
    FFT_setIOBuffer2Ptr(hnd, temp);

    // bit reverse the input - you do not need to set the size to N/2 
    // for the bitreverse operation, it will query the FFT type and do
    // the right thing
    hnd->bitrev(hnd);
    // run an N/2 point inverse complex FFT on the packed 
    // data
    N = FFT_getSize(hnd);
    FFT_setSize(hnd, N/2);
    if(FFT_getType(hnd) == REAL_RADIX_2)
    {
        FFT_runICFFT2(hnd);
    }
    else if (FFT_getType(hnd) == REAL_RADIX_4)
    {
        FFT_runICFFT4(hnd);
    }
    else
    {
        DSP_ASSERT(0U); // FFT Type is undefined
    }

    // Set the size back to its original
    FFT_setSize(hnd, N);

}

// End of File
