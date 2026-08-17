/** 
  *************************************************************************************
  * @file vector_mpyRMbyRM.c 
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
DSP_FILENUM(39)

//*****************************************************************************
// VECTOR_mpyRMbyRM
//*****************************************************************************
void VECTOR_mpyRMbyRM(fsize_t *y, const fsize_t *w, 
                      const fsize_t *x, const uint16_t m, 
                      const uint16_t n, const uint16_t p)
{
    //Locals
    uint16_t i, j, k;
    
    // Row-Major Order (Matrices are stored row by row)
    //
    // for(i = 0U; i < m; i++)
    // {
    //     for(j = 0U; j < p; j++)
    //     {
    //         *(y + i*m + j) = (fsize_t)0.0;
    //         for(k = 0U; k < n; k++)
    //         {
    //             *(y + i*m + j) += *(w + i*n + k) * *(x + k*p + j);
    //         }
    //     #ifdef _DEBUG
    //         // Debugging message
    //         printf("y[%4d][%4d]=%10.7f\n", i, j, *(y + i*m + j));
    //     #endif
    //     }
    // }
    
    // Column-Major Order (Matrices are stored column by column)
    //
    for(i = 0U; i < m; i++)
    {
        for(j = 0U; j < p; j++)
        {
            *(y + i + j*p) = (fsize_t)0.0;
            for(k = 0U; k < n; k++)
            {
                *(y + i + j*p) += *(w + i + k*m) * *(x + j*n + k);
            }
        #ifdef _DEBUG
            // Debugging message
            printf("y[%4d][%4d]=%10.7f\n", i, j, *(y + i + j*p));
        #endif
        }
    }
}

// End of File
