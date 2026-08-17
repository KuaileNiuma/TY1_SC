/**
 *************************************************************************************
 * @file my_float.h
 * @brief This file contains the header file.
 * @version 1.0.0
 *************************************************************************************
 * @copyright Copyright (c) 2025 Albatross Semiconductor(Hangzhou) Co.,Ltd.
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
//********************************************************************
// KEY:  FLT_     - APPLIES TO TYPE FLOAT                        
// DBL_     - APPLIES TO TYPE DOUBLE                       
// LDBL_    - APPLIES TO TYPE LONG DOUBLE                  
//********************************************************************
#ifndef _MY_FLOAT_H_
#define _MY_FLOAT_H_

#include "device.h"
#include <stdio.h>

#define FLT_RADIX                         2   //!< RADIX OF EXPONENT         
#define FLT_ROUNDS                        1   //!< ROUND TO NEAREST          
#define FLT_EVAL_METHOD                 (-1)  //!< INDETERMINABLE            

#define FLT_DIG                           6   //!< DECIMAL PRECISION         
#define FLT_DECIMAL_DIG                    9  //!< DECIMAL PRECISION         
#define FLT_MANT_DIG                     24   //!< BITS IN MANTISSA          
#define FLT_MIN_EXP                   (-125)  //!< SMALLEST EXPONENT         
#define FLT_MAX_EXP                     128   //!< LARGEST EXPONENT          
#define FLT_MIN_10_EXP                 (-37)  //!< MIN POWER OF 10           
#define FLT_MAX_10_EXP                   38   //!< MAX POWER OF 10           
#define FLT_EPSILON         1.192092896E-07F  //!< ULP SMALLEST X WHERE 1+X != 1 
#define FLT_MIN             1.175494351E-38F  //!< MIN NORMALIZED POS VALUE    
#define FLT_MAX             3.402823466E+38F  //!< MAX POSITIVE VALUE         
#define FLT_TOLERANCE       0.0000001F

typedef union
{
    unsigned int ui32;   //!< Unsigned long representation
    int i32;             //!< Signed long represntaion
    float f32;  //!< Single precision (32-bit) representation
} float32u_t;

#endif 
