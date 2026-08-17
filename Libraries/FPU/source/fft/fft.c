/** 
  *************************************************************************************
  * @file fft.c 
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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dsp.h"
#include "dsp_assert.h"
#include "dsp_error.h"
#include "vector.h"
#include "filter.h"
#include "fft.h"
//*****************************************************************************
// defines
//*****************************************************************************

//*****************************************************************************
// globals
//*****************************************************************************

// Objects and their handler

FFT cfft2, cfft4;
FFTHandle hndCFFT2 = &cfft2;
FFTHandle hndCFFT4 = &cfft4;

FFT icfft2, icfft4;
FFTHandle hndICFFT2 = &icfft2;
FFTHandle hndICFFT4 = &icfft4;

FFT rfft2, rfft4;
FFTHandle hndRFFT2 = &rfft2;
FFTHandle hndRFFT4 = &rfft4;

FFT irfft2, irfft4;
FFTHandle hndIRFFT2 = &irfft2;
FFTHandle hndIRFFT4 = &irfft4;

FFT wcfft2, wcfft4;
FFTHandle hndWCFFT2 = &wcfft2;
FFTHandle hndWCFFT4 = &wcfft4;

FFT wrfft2, wrfft4;
FFTHandle hndWRFFT2 = &wrfft2;
FFTHandle hndWRFFT4 = &wrfft4;

//*****************************************************************************

void CFFT2_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndCFFT2, COMPLEX_RADIX_2);
       // Set the FFT size
       FFT_setSize(hndCFFT2, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndCFFT2, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndCFFT2, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndCFFT2, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndCFFT2, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndCFFT2, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndCFFT2->bitrev(hndCFFT2);
       // Set the run function
       FFT_setRunFunction(hndCFFT2, (v_pfn_v)FFT_runCFFT2);
       // Run the FFT
       hndCFFT2->run(hndCFFT2);
       // Copy the IO buffer to the output vector (IOBuffer2)
       memcpy((fsize_t *)output, (fsize_t *)input, 
               size * sizeof(complex_t));
      // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndCFFT2, &output[2U*size]);
       // Set the mag function
       FFT_setMagnitudeFunction(hndCFFT2, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndCFFT2->magnitude(hndCFFT2);
      // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndCFFT2, &output[3U*size]);
       // Set the phase function
       FFT_setPhaseFunction(hndCFFT2, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndCFFT2->phase(hndCFFT2);
}

void CFFT4_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndCFFT4, COMPLEX_RADIX_4);
       // Set the FFT size
       FFT_setSize(hndCFFT4, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndCFFT4, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndCFFT4, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndCFFT4, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndCFFT4, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndCFFT4, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndCFFT4->bitrev(hndCFFT4);
       // Set the run function
       FFT_setRunFunction(hndCFFT4, (v_pfn_v)FFT_runCFFT4);
       // Run the FFT
       hndCFFT4->run(hndCFFT4);
       // Copy the IO buffer to the output vector (IOBuffer2)
       memcpy((fsize_t *)output, (fsize_t *)input, 
               size * sizeof(complex_t));
      // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndCFFT4, &output[2U*size]);
       // Set the mag function
       FFT_setMagnitudeFunction(hndCFFT4, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndCFFT4->magnitude(hndCFFT4);
      // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndCFFT4, &output[3U*size]);
       // Set the phase function
       FFT_setPhaseFunction(hndCFFT4, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndCFFT4->phase(hndCFFT4);
}

void ICFFT2_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndICFFT2, COMPLEX_RADIX_2);
       // Set the FFT size
       FFT_setSize(hndICFFT2, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndICFFT2, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndICFFT2, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndICFFT2, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndICFFT2, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndICFFT2, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndICFFT2->bitrev(hndICFFT2);
       // Set the run function
       FFT_setRunFunction(hndICFFT2, (v_pfn_v)FFT_runICFFT2);
       // Run the FFT
       hndICFFT2->run(hndICFFT2);
       // Copy the IO buffer to the output vector (IOBuffer2)
       memcpy((fsize_t *)output, (fsize_t *)input, 
               size * sizeof(complex_t));
}

void ICFFT4_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndICFFT4, COMPLEX_RADIX_4);
       // Set the FFT size
       FFT_setSize(hndICFFT4, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndICFFT4, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndICFFT4, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndICFFT4, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndICFFT4, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndICFFT4, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndICFFT4->bitrev(hndICFFT4);
       // Set the run function
       FFT_setRunFunction(hndICFFT4, (v_pfn_v)FFT_runICFFT4);
       // Run the FFT
       hndICFFT4->run(hndICFFT4);
       // Copy the IO buffer to the output vector (IOBuffer2)
       memcpy((fsize_t *)output, (fsize_t *)input, 
               size * sizeof(complex_t));
}

void IRFFT2_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndIRFFT2, REAL_RADIX_2);
       // Set the FFT size
       FFT_setSize(hndIRFFT2, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndIRFFT2, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndIRFFT2, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndIRFFT2, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndIRFFT2, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndIRFFT2, (v_pfn_v)FFT_bitReverseInput);
       // Set the run function
       FFT_setRunFunction(hndIRFFT2, (v_pfn_v)FFT_runIRFFT);
       // Run the FFT
       hndIRFFT2->run(hndIRFFT2);

}

void IRFFT4_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndIRFFT4, REAL_RADIX_4);
       // Set the FFT size
       FFT_setSize(hndIRFFT4, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndIRFFT4, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndIRFFT4, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndIRFFT4, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndIRFFT4, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndIRFFT4, (v_pfn_v)FFT_bitReverseInput);
       // Set the run function
       FFT_setRunFunction(hndIRFFT4, (v_pfn_v)FFT_runIRFFT);
       // Run the FFT
       hndIRFFT4->run(hndIRFFT4);

}

void RFFT2_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT size
       FFT_setSize(hndRFFT2, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndRFFT2, TWIDDLE_TABLE_SIZE);

#if USE_ALT_RFFT2 == 1U
       // Set the FFT Type
       FFT_setType(hndRFFT2, ALT_REAL_RADIX_2);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndRFFT2, DSP_rfftTwiddleFactorTbl);
       // Set the run function
       FFT_setRunFunction(hndRFFT2, (v_pfn_v)FFT_runRFFT2);
       // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndRFFT2, &output[size]);
         // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndRFFT2, &output[3U*size/2 + 1]);
#else 
       // Set the FFT Type
       FFT_setType(hndRFFT2, REAL_RADIX_2);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndRFFT2, DSP_twiddleFactorTbl);
       // Set the run function
       FFT_setRunFunction(hndRFFT2, (v_pfn_v)FFT_runRFFT);
       // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndRFFT2, &test_output[2U*size]);
             // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndRFFT2, &test_output[3U*size + 1]);
#endif //USE_ALT_RFFT2 == 1
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndRFFT2, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndRFFT2, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndRFFT2, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndRFFT2->bitrev(hndRFFT2);

       
       // Run the FFT
       hndRFFT2->run(hndRFFT2);

       // Set the mag function
       FFT_setMagnitudeFunction(hndRFFT2, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndRFFT2->magnitude(hndRFFT2);
       // Set the phase function
       FFT_setPhaseFunction(hndRFFT2, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndRFFT2->phase(hndRFFT2);
}

void RFFT4_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndRFFT4, REAL_RADIX_4);
       // Set the FFT size
       FFT_setSize(hndRFFT4, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndRFFT4, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndRFFT4, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndRFFT4, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndRFFT4, output);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndRFFT4, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndRFFT4->bitrev(hndRFFT4);
       // Set the run function
       FFT_setRunFunction(hndRFFT4, (v_pfn_v)FFT_runRFFT);
       
       // Run the FFT
       hndRFFT4->run(hndRFFT4);
       // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndRFFT4, &output[2U*size]);
       // Set the mag function
       FFT_setMagnitudeFunction(hndRFFT4, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndRFFT4->magnitude(hndRFFT4);
      // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndRFFT4, &output[3U*size]);
       // Set the phase function
       FFT_setPhaseFunction(hndRFFT4, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndRFFT4->phase(hndRFFT4);
}

void WCFFT2_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndWCFFT2, COMPLEX_RADIX_2);
       // Set the FFT size
       FFT_setSize(hndWCFFT2, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndWCFFT2, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndWCFFT2, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndWCFFT2, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndWCFFT2, output);
       // Set the window for this test. The MATLAB routine 
       // FPU_DSP_runWindowedFFT.m will generate a window of the user's 
       // choosing and write the table values to an array DSP_window. The same
       // script will also generate header files for the different windows
       // and the user can then use the definitions in the header file to
       // define the required window
       FFT_setWindowTblPtr(hndWCFFT2, DSP_window);
       // Set the windowing function
       FFT_setWindowFunction(hndWCFFT2, (v_pfn_v)FFT_applyWindow);
       // Apply the window
       hndWCFFT2->window(hndWCFFT2);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndWCFFT2, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndWCFFT2->bitrev(hndWCFFT2);
       // Set the run function
       FFT_setRunFunction(hndWCFFT2, (v_pfn_v)FFT_runCFFT2);
       // Run the FFT
       hndWCFFT2->run(hndWCFFT2);
       // Copy the IO buffer to the output vector (IOBuffer2)
       memcpy((fsize_t *)output, (fsize_t *)input, 
               size * sizeof(complex_t));
      // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndWCFFT2, &output[2U*size]);
       // Set the mag function
       FFT_setMagnitudeFunction(hndWCFFT2, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndWCFFT2->magnitude(hndWCFFT2);
      // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndWCFFT2, &output[3U*size]);
       // Set the phase function
       FFT_setPhaseFunction(hndWCFFT2, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndWCFFT2->phase(hndWCFFT2);
}

void WCFFT4_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndWCFFT4, COMPLEX_RADIX_4);
       // Set the FFT size
       FFT_setSize(hndWCFFT4, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndWCFFT4, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndWCFFT4, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndWCFFT4, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndWCFFT4, output);
       // Set the window for this test. The MATLAB routine 
       // FPU_DSP_runWindowedFFT.m will generate a window of the user's 
       // choosing and write the table values to an array DSP_window. The same
       // script will also generate header files for the different windows
       // and the user can then use the definitions in the header file to
       // define the required window
       FFT_setWindowTblPtr(hndWCFFT4, DSP_window);
       // Set the windowing function
       FFT_setWindowFunction(hndWCFFT4, (v_pfn_v)FFT_applyWindow);
       // Apply the window
       hndWCFFT4->window(hndWCFFT4);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndWCFFT4, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndWCFFT4->bitrev(hndWCFFT4);
       // Set the run function
       FFT_setRunFunction(hndWCFFT4, (v_pfn_v)FFT_runCFFT4);
       // Run the FFT
       hndWCFFT4->run(hndWCFFT4);
       // Copy the IO buffer to the output vector (IOBuffer2)
       memcpy((fsize_t *)output, (fsize_t *)input, 
               size * sizeof(complex_t));
      // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndWCFFT4, &output[2U*size]);
       // Set the mag function
       FFT_setMagnitudeFunction(hndWCFFT4, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndWCFFT4->magnitude(hndWCFFT4);
      // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndWCFFT4, &output[3U*size]);
       // Set the phase function
       FFT_setPhaseFunction(hndWCFFT4, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndWCFFT4->phase(hndWCFFT4);
}

void WRFFT2_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndWRFFT2, REAL_RADIX_2);
       // Set the FFT size
       FFT_setSize(hndWRFFT2, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndWRFFT2, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndWRFFT2, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndWRFFT2, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndWRFFT2, output);
       // Set the window for this test. The MATLAB routine 
       // FPU_DSP_runWindowedFFT.m will generate a window of the user's 
       // choosing and write the table values to an array DSP_window. The same
       // script will also generate header files for the different windows
       // and the user can then use the definitions in the header file to
       // define the required window
       FFT_setWindowTblPtr(hndWRFFT2, DSP_window);
       // Set the windowing function
       FFT_setWindowFunction(hndWRFFT2, (v_pfn_v)FFT_applyWindow);
       // Apply the window
       hndWRFFT2->window(hndWRFFT2);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndWRFFT2, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndWRFFT2->bitrev(hndWRFFT2);
       // Set the run function
       FFT_setRunFunction(hndWRFFT2, (v_pfn_v)FFT_runRFFT);
       
       // Run the FFT
       hndWRFFT2->run(hndWRFFT2);
       // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndWRFFT2, &output[2U*size]);
       // Set the mag function
       FFT_setMagnitudeFunction(hndWRFFT2, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndWRFFT2->magnitude(hndWRFFT2);
      // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndWRFFT2, &output[3U*size]);
       // Set the phase function
       FFT_setPhaseFunction(hndWRFFT2, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndWRFFT2->phase(hndWRFFT2);
}

void WRFFT4_run(int16_t size, fsize_t *input, fsize_t *output)
{
       // Set the FFT Type
       FFT_setType(hndWRFFT4, REAL_RADIX_4);
       // Set the FFT size
       FFT_setSize(hndWRFFT4, size);
       // Set the Twiddle Factor Table size
       FFT_setTfTblSize(hndWRFFT4, TWIDDLE_TABLE_SIZE);
       // Set the Twiddle Factor Table Pointer
       FFT_setTwiddlePtr(hndWRFFT4, DSP_twiddleFactorTbl);
       // Set the Input/Output Buffer Pointer
       FFT_setIOBufferPtr(hndWRFFT4, input);
       // Set the Input/Output Buffer2 Pointer
       FFT_setIOBuffer2Ptr(hndWRFFT4, output);
       // Set the window for this test. The MATLAB routine 
       // FPU_DSP_runWindowedFFT.m will generate a window of the user's 
       // choosing and write the table values to an array DSP_window. The same
       // script will also generate header files for the different windows
       // and the user can then use the definitions in the header file to
       // define the required window
       FFT_setWindowTblPtr(hndWRFFT4, DSP_window);
       // Set the windowing function
       FFT_setWindowFunction(hndWRFFT4, (v_pfn_v)FFT_applyWindow);
       // Apply the window
       hndWRFFT4->window(hndWRFFT4);
       // Set the bit reversal function
       FFT_setBitrevFunction(hndWRFFT4, (v_pfn_v)FFT_bitReverseInput);
       // Bit-reverse the input
       hndWRFFT4->bitrev(hndWRFFT4);
       // Set the run function
       FFT_setRunFunction(hndWRFFT4, (v_pfn_v)FFT_runRFFT);
       
       // Run the FFT
       hndWRFFT4->run(hndWRFFT4);
       // Set the Magnitude Buffer Pointer
       FFT_setMagBufferPtr(hndWRFFT4, &output[2U*size]);
       // Set the mag function
       FFT_setMagnitudeFunction(hndWRFFT4, (v_pfn_v)FFT_getMagnitude);
       // Run the Magntiude function
       hndWRFFT4->magnitude(hndWRFFT4);
      // Set the Phase Buffer Pointer
       FFT_setPhaseBufferPtr(hndWRFFT4, &output[3U*size]);
       // Set the phase function
       FFT_setPhaseFunction(hndWRFFT4, (v_pfn_v)FFT_getPhase);
       // Run the Phase function
       hndWRFFT4->phase(hndWRFFT4);
}
