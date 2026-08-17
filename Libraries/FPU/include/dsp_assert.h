/** 
  *************************************************************************************
  * @file dsp_assert.h 
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

#ifndef _DSP_ASSERT_H_
#define _DSP_ASSERT_H_

//*****************************************************************************
// the includes
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
//!
//! \defgroup DSP_ASSERT Code Development with Assertion

//!
//! \ingroup DSP_ASSERT
//@{

#ifdef __cplusplus
extern "C" {
#endif
//*****************************************************************************
//defines
//*****************************************************************************
//! \brief Assign a "unique" number to each file, compiler error
//! on duplicates
//!
#define DSP_FILENUM(number) \
    enum{FILE_NUM = number};    \
    void _nullFunction##number(void){}

//! \brief The assert() for the PMBus communications stack
//!
#define DSP_ASSERT(expr) \
    if (expr)                \
    {}                       \
    else                     \
    DSP_assertionFailed(FILE_NUM, __LINE__)

//*****************************************************************************
// the function prototypes
//*****************************************************************************
//! \brief Handles failed assertions
//! \param[in] file File number where the assertion failed
//! \param[in] line Line number where the assertion failed
//!
static inline void DSP_assertionFailed(int16_t file, int16_t line)
{
#if defined(_DEBUG)
    // Do nothing
#else
    printf("Error in file %d on line %d\n",file,line );
#endif //defined(_DEBUG)
}

#ifdef __cplusplus
}
#endif // extern "C"
//@}  // ingroup

#endif // end of _DSP_ASSERT_H_ definition
