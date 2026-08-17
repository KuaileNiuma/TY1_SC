/** 
  *************************************************************************************
  * @file fft_window.c 
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
DSP_FILENUM(29)

//*****************************************************************************
// FFT_applyWindow()
//*****************************************************************************
void FFT_applyWindow(FFTHandle hnd)
{    
    // Locals
    uint16_t i, j, k;
    uint16_t N   = FFT_getSize(hnd);
    fsize_t *win = FFT_getWindowTblPtr(hnd);
    fsize_t *io  = FFT_getIOBufferPtr(hnd);
    fsize_t t_r, t_i, w;
    
    if((FFT_getType(hnd) == COMPLEX_RADIX_2) ||
       (FFT_getType(hnd) == COMPLEX_RADIX_4))
    {
        for(i = 0U, j = i, k =j+1; i < (N >> 1); i++, j += 2U, k += 2U)
        {
            t_r   = io[j];
            t_i   = io[k];
            w     = *win;
            io[j] = io[j] * (*win);
            io[k] = io[k] * (*win++);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f," 
                   " win=%10.7f, out=(%10.7f+j%10.7f)\n",
                    i, t_r, t_i, w, io[j], io[k]);
#endif
        }
        for(i = (N >> 1), j = N, k =j+1; i < N; i++, j += 2U, k += 2U)
        {
            t_r   = io[j];
            t_i   = io[k];
            io[j] = io[j] * (*--win);
            io[k] = io[k] * (*win);
            w     = *win;
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f,"
                   " win=%10.7f, out=(%10.7f+j%10.7f)\n",
                    i, t_r, t_i, w, io[j], io[k]);
#endif
        }
    }
    else if ((FFT_getType(hnd) == REAL_RADIX_2) ||
             (FFT_getType(hnd) == REAL_RADIX_4))
    {
        for(i = 0U; i < (N >> 1); i++)
        {
            t_r   = io[i];
            w     = *win;
            io[i] = io[i] * (*win++);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f, win*io[i]=%10.7f*(%10.7f)\n",
                    i, t_r, w, io[i]);
#endif
        }
        for(i = (N >> 1); i < N; i++)
        {
            t_r   = io[i];
            w     = *win;
            io[i] = io[i] * (*--win);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f, win*io[i]=%10.7f*(%10.7f)\n",
                    i, t_r, w, io[i]);
#endif
        }
    }
    else
    {
        DSP_ASSERT(0U); //Type is invalid
    }
}

// End of File
