/** 
  *************************************************************************************
  * @file fft_magnitude.c 
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
DSP_FILENUM(27)

//*****************************************************************************
// FFT_getMagnitude()
//*****************************************************************************
void FFT_getMagnitude(FFTHandle hnd)
{
    // Locals
    uint16_t i,j,k;
    uint16_t N = FFT_getSize(hnd);
    fsize_t *mag = FFT_getMagBufferPtr(hnd);
    fsize_t *io = FFT_getIOBuffer2Ptr(hnd);

    if(FFT_getType(hnd) == ALT_REAL_RADIX_2)
    {
        i = 0U, j = i;
        mag[0] = fabs_t(io[0]);
#ifdef _DEBUG
        printf("i=%4d, io[i]=%10.7f, mag[i]=%10.7f\n",
            i, io[i], mag[i]);
#endif
      
        for(i = 1U, j = N - 1U; i < (N >> 1U); i++, j--)
        {
#ifdef ZHANLU
            mag[i] = __builtin_riscv_sqrtf32(io[i]*io[i] + io[j]*io[j]);
#else
            mag[i] = sqrt(io[i]*io[i] + io[j]*io[j]);
#endif
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f, mag[i]=%10.7f\n",
                i, io[i], io[j], mag[i]);
#endif
        }
        i = N >> 1U, j = i;
        mag[(N >> 1U)] = fabs_t(io[(N >> 1U)]);
#ifdef _DEBUG
        printf("i=%4d, io[i]=%10.7f, mag[i]=%10.7f\n",
            i, io[i], mag[i]);
#endif
    }
    else
    {
        for(i = 0U, j = 0U, k = 1U; i < N; i++, j += 2, k += 2)
        {
#ifdef ZHANLU
            mag[i] = __builtin_riscv_sqrtf32(io[j]*io[j] + io[k]*io[k]);
#else
            mag[i] = sqrt(io[j]*io[j] + io[k]*io[k]);
#endif
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f, mag[i]=%10.7f\n",
                i, io[j], io[k], mag[i]);
#endif
        }
    }
}

// End of File
