/** 
  *************************************************************************************
  * @file dsp.h 
  * @author Albatross 
  * @brief This file contains the header file. 
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

#ifndef _DSP_H_
#define _DSP_H_


#define CONCAT(x,y)          x##y
#define XCONCAT(x,y)         CONCAT(x,y)
#define STRINGIZE(s)         #s
#define XSTRINGIZE(s)        STRINGIZE(s)

//*****************************************************************************
// the includes
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#define USE_FPU64  0
//!
//! \defgroup C_REF_MOD C Reference Module

//! 
//! \ingroup C_REF_MOD
//@{
    
#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
// defines
//*****************************************************************************
#if USE_FPU64 == 1
typedef double        fsize_t; //!< Use double precision
#define PI            (3.141592653589793)
#define TWOPI         (6.283185307179586)
#define PI_O_2        (1.570796326794897)
#define INVTWOPI      (0.159154943091895)
#else //USE_FPU32 == 1
typedef float         fsize_t; //!< Use single precision
#define PI            (3.141592653589793F)
#define TWOPI         (6.283185307179586F)
#define PI_O_2        (1.570796326794897F)
#define INVTWOPI      (0.159154943091895F)
#endif //USE_FPU64 == 1

//! The Twiddle Factor Table size 
//! \note The user must change this value to match the size argument of
//! the MATLAB function FPU_DSP_genTwiddleFactorTable()
//! 
#define TWIDDLEFACTOR_TBLSIZE    (1024U) 

//*****************************************************************************
// typedefs
//*****************************************************************************
//! \brief The error type enumeration
//!
typedef enum{
    ERRORTYPE_ABSOLUTE = 0, //!< Absolute error
    ERRORTYPE_RELATIVE = 1, //!< Relative error
}errorType;

//! \brief Pointer to a function that takes an argument of fsize_t and 
//! returns a value of type fsize_t
typedef fsize_t (*PFF)(fsize_t);

//! \brief Primitive for the sincos type
//!
typedef struct{
    fsize_t c;   //!< The Cosine 
    fsize_t s;   //!< The Sine
}sincos_t;

//! \brief Primitive for the complex type
//!
typedef struct{
    fsize_t r;   //!< The Real Part 
    fsize_t i;   //!< The Imaginary Part
}complex_t;

//*****************************************************************************
//globals
//*****************************************************************************
//! \brief The Twiddle Factors Table
//!
extern const fsize_t FFT_twiddleFactors[];

#if USE_FPU64 == 1
static PFF fabs_t  = fabs;
#else //USE_FPU32 == 1
static PFF fabs_t  = fabsf;
#endif //USE_FPU64 == 1


//*****************************************************************************
// 'extern' function prototypes
//*****************************************************************************

#ifdef __cplusplus
}
#endif //extern "C"

//@} //ingroup

#endif // end of _DSP_H_ definition
