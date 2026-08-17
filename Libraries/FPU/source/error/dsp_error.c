/** 
  *************************************************************************************
  * @file dsp_error.c 
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
#include "dsp_error.h"
#include "dsp_assert.h"
//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(1)

//*****************************************************************************
// FastRTS_error
//*****************************************************************************
void DSP_error(errorHandle eh)
{

    
    // Locals
    uint16_t pass = 0U, fail = 0U;
    int16_t i, max_ep = 0U, min_ep =0U, size = error_getSize(eh);
    DSP_ASSERT(size > 0U);
    // Set the max, min errors (and their position), along with the average
    // and span to 0
    fsize_t avg_e = 0.0, isize = 1.0 / size, max_e = 0.0, span_e = 0.0;
#if USE_FPU64 == 1
    fsize_t min_e = DBL_MAX;
#else
    fsize_t min_e = FLT_MAX;
#endif
    fsize_t tol   = error_getTolerance(eh);
    fsize_t *err  = error_getErrPtr(eh);
    fsize_t *test = error_getTestPtr(eh);
    fsize_t *gold = error_getGoldPtr(eh);
    errorType et  = error_getErrType(eh);

    DSP_ASSERT((et == ERRORTYPE_ABSOLUTE) ||
               (et == ERRORTYPE_RELATIVE));

    for(i = 0U; i < size; i++)
    {
        if(et == ERRORTYPE_ABSOLUTE)
        {
            err[i] = fabs_t(test[i] - gold[i]);
        }
        else //et == ERRORTYPE_RELATIVE
        {
            err[i] =  fabs_t((test[i] - gold[i])/test[i]);
        }
        if(err[i] <= tol)
        {
            pass++;
        }
        else
        {
            fail++;
        }
        if(err[i] > max_e)
        {
            max_e = err[i];
            max_ep = i;
        }
        if(err[i] < min_e)
        {
            min_e = err[i];
            min_ep = i;
        }
        // Calculate the average
        avg_e += (err[i] * isize);
    }
    
    span_e = max_e - min_e;
    
    // Write to the object
    error_setMaxErr(eh, max_e);
    error_setMaxErrPos(eh, max_ep);
    error_setMinErr(eh, min_e);
    error_setMinErrPos(eh, min_ep);
    error_setAvgErr(eh, avg_e);
    error_setSpanErr(eh, span_e);
    error_setPass(eh, pass);
    error_setFail(eh, fail);
    
    // Print to the screen
    printf("Maximum Error =  %15.13e, at position %d\n", max_e, max_ep);
    printf("Maximum Error Data Point -> Test=%15.13e, Gold=%15.13e\n", 
           test[max_ep], gold[max_ep]);
    printf("Minimum Error =  %15.13e, at position %d\n", min_e, min_ep);
    printf("Average Error =  %15.13e\n",avg_e);
    printf("Error Span    =  %15.13e\n",span_e);
    printf("Data within error tolerance: %d\n", pass);
    printf("Data outside error tolerance: %d\n", fail);
}

// End of File
