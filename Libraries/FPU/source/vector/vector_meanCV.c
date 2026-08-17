/** 
  *************************************************************************************
  * @file vector_meanCV.c 
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
#include "vector.h"
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(8)

//*****************************************************************************
// VECTOR_meanCV
//*****************************************************************************
complex_t VECTOR_meanCV(const complex_t *x, const uint16_t n)
{
    // Locals
    uint16_t i;
    complex_t m = {(fsize_t)0.0, (fsize_t)0.0};
#ifdef ZHANLU
    fsize_t ONE_O_N = __builtin_riscv_divf32(1.0f,(fsize_t)n);
#else
    fsize_t ONE_O_N = 1/(fsize_t)n;
#endif

    
    for(i = 0U; i < n; i++)
    {
        m.r += x[i].r;
        m.i += x[i].i;
#ifdef _DEBUG
        // Debugging message
        printf("i=%4d, x=%10.7f+j%10.7f\n", i, x[i].r, x[i].i);
#endif    
    }
    m.r *= ONE_O_N;
    m.i *= ONE_O_N;
#ifdef _DEBUG
    // Debugging message
    printf("m=%10.7f+j%10.7f\n", m.r, m.i);
#endif  
    return(m);
}

// End of File
