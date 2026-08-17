/** 
  *************************************************************************************
  * @file vector_qsortRV.c 
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
DSP_FILENUM(18)

//*****************************************************************************
// prototypes
//*****************************************************************************
static inline void swap_item(fsize_t *, fsize_t *);

//*****************************************************************************
// VECTOR_qsortRV
//*****************************************************************************
void VECTOR_qsortRV(void *base, const uint16_t nmemb)
{
	char *basep = base;              // POINTER TO ARRAY OF ELEMENTS
	uint16_t i = 0;                 // left scan index

	// right scan index
	uint16_t j = sizeof(fsize_t) * (nmemb - 1);
	// Want closest even value
	uint16_t pivot = (nmemb & 0xFFFE) * (sizeof(fsize_t) / 2);

	char *pivp = basep + pivot;
   
    if (nmemb <= 1) return;

    while( i < j )
    {
        while(*(fsize_t*)(basep + i) < *(fsize_t*)pivp) 
        {
            i=i+sizeof(fsize_t);
        }
        while(*(fsize_t*)(basep + j) > *(fsize_t*)pivp)
        {
            j=j-sizeof(fsize_t);
        }

        if( i < j )
        {
            swap_item((fsize_t*)(basep + i), (fsize_t*)(basep + j));
            if ( pivot == i ) 
            {
                pivot = j; 
                pivp = basep + pivot; 
            }
            else if( pivot == j ) 
            {
                pivot = i; 
                pivp = basep + pivot; 
            }
            i=i+sizeof(fsize_t); 
            j=j-sizeof(fsize_t);
        }
        else if ( i == j ) 
        {
            i=i+sizeof(fsize_t); 
            j=j-sizeof(fsize_t);  
            break; 
        }
    }

    if(j > 0)
    {
        VECTOR_qsortRV(basep, (j/sizeof(fsize_t) + 1U));
    }
    if((i/sizeof(fsize_t)) < (nmemb - 1))
    {
        VECTOR_qsortRV(basep + i, nmemb - (i/sizeof(fsize_t)));
    }


}

//*****************************************************************************
// swap_item
//*****************************************************************************
static inline void swap_item(fsize_t *src, fsize_t *dest)
{
    fsize_t temp;

    temp = *src;
    *src  = *dest;
    *dest = temp;

}

// End of File
