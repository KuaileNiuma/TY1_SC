/** 
  *************************************************************************************
  * @file vector_medianNoreorderRV.c 
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
#include <string.h>
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(9)
#define        K    256         // WARNING: K must be at least as large as N.

//*****************************************************************************
// VECTOR_medianNoreorderRV
// Median of a real valued array of floats. Input array is preserved.
// Notes:
// 1) This function simply makes a local copy of the input array, and then
//    calls VECTOR_medianRV() using the copy.
// 2) The length of the copy of the input array is allocated at compile time
//    by the constant 'K' defined in the code.  If the passed parameter N
//    is greater than K, memory corruption will result.  A better way to do
//    this is to dynamically allocate the copy array at run time using
//    malloc().  This is work for the future. 
//
//*****************************************************************************
fsize_t VECTOR_medianNoreorderRV(const fsize_t *x, uint16_t n)
{
    fsize_t x_copy[K], m;

    // Make a copy of the input array
    memcpy(x_copy, x, n*sizeof(fsize_t));     
    // Call VECTOR_medianRV()
    m = VECTOR_medianRV(x_copy, n);   
    return(m);
}

// End of File
