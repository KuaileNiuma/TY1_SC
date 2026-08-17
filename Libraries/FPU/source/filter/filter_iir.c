/** 
  *************************************************************************************
  * @file filter_iir.c 
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
#include "filter.h"
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(23)

//*****************************************************************************
// FILTER_runIIR()
// ALGORITHM:
//
// Difference Equation :
//
// The operations for each biquad, in order, is as follows 
// 1. yn  = xn*b(0) + q(3) 
// 2. q(2) = xn*b(1) + yn*a(1) + q(1)
// 3. q(3) = q(2)
// 4. q(0) = xn*b(2) + yn*a(2)
// 5. q(1) = q(0)
//      where
//              yn  =output sample of the filter at index n 
//              xn  =input sample of the filter at index n 
//			   q(n) =intermediate values stored in the delay buffer
//
// Transfer Function :
//   The difference equation is split up into multiple Second-Order Sections
//   (SOS). Each SOS represents a Biquad with the following transfer function                                 
//                                  -1        -2
//              Y(z)   b(0) + b(1) z  + b(2) z  
//			  ----- = ----------------------- 
//			   X(z)	               -1       -2
//					  a(0) + a(1) z  + a(2) z 
//
//   For a detailed treatment of Direct II Forms see
//   [1]Digital Signal Processing, Proakis, J. G. and Manolakis, D. G. - Ch 7
//   [2]Understanding Digital Signal Processing 3rd ed, Lyons, R. G.
//
//     Network Diagram  : 
//
// xn------>(x)--->(+)--------------->yn
//      |    ^      ^             |
//      |    |      |q(3)         |
//      |    b(0)  (z)            |
//      |           ^             |
//      |           |q(2)         |
//      |-->(x)--->(+)<-----(x)---|
//      |    ^      ^        ^    |
//      |    |      |q(1)    |    |
//      |    b(1)  (z)       a(1) |
//      |           ^             |
//      |           |q(0)         |
//      --->(x)--->(+)<-----(x)----
//           ^               ^
//           |               |
//           b(2)            a(2)
//*****************************************************************************
void FILTER_runIIR(IIRHandle hnd)
{
    // Locals
    uint16_t j;
    fsize_t *b = IIR_getCoefficientsPtr(hnd);
    fsize_t *a = b + 3UL;
    fsize_t *q = IIR_getDelayLinePtr(hnd);
    fsize_t *s = IIR_getScaleValPtr(hnd);
    fsize_t yn = (fsize_t)0.0;
    fsize_t xn = IIR_getInput(hnd);
    
    for(j = 0U; j < IIR_getnSOS(hnd); j++)
    {
        xn   = s[j] * xn; //Multiply the scaling factor for this stage
        yn   = xn*b[0] + q[3]; 
        q[2] = xn*b[1] - yn*a[1] + q[1];
        q[3] = q[2];
        q[0] = xn*b[2] - yn*a[2];
        q[1] = q[0];
        // Set input for the next biquad
        xn   = yn;
        // Set delay line for the next biquad
        q = q + 4UL;
        // Set coefficients for the next biquad
        a = a + 6UL;
        b = b + 6UL;
    }
    
    // write the final output to the structure object
    IIR_setOutput(hnd, yn);
#ifdef _DEBUG
    printf("output = %10.7f \n", IIR_getOutput(hnd));
#endif
}

// End of File
