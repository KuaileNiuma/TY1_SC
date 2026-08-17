/** 
  *************************************************************************************
  * @file vcu2_types.h 
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

#ifndef _VCU2_TYPES_H
#define _VCU2_TYPES_H

//*****************************************************************************
// includes
//*****************************************************************************
//#include <string.h>
#include <stdint.h>
//!
//! \defgroup VCU2_DEFINITIONS VCU2 Type Defintions


//!
//! \ingroup VCU2_DEFINITIONS
// @{

#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
// defines
//*****************************************************************************
#ifndef NULL
#define NULL				0
#endif
#define	TRUE				1
#define	FALSE				0

//*****************************************************************************
// typedefs
//*****************************************************************************

#ifndef VCU2_TYPES
#define VCU2_TYPES

//! \brief Boolean enumeration
//!
typedef enum{
	BOOL_FALSE=0,
	BOOL_TRUE
}Bool_e;

//! \brief Complex data (CPACK = 0)
//!
//! On reset the CPACK bit is 0, therefore, this is the
//! default complex structure
//
typedef struct{
	int16_t	real; 			//!< Real Part
	int16_t imag; 			//!< Imaginary Part
}complexShort_t;


typedef union{
//! \brief Complex data (CPACK = 1)
//!
	struct{
		int16_t imag; 			//!< Real Part
		int16_t	real; 			//!< Imaginary Part
	}cplx;
	uint32_t ui32;
}complexCPACKON_t;


typedef union{
//! \brief Complex data (CPACK = 0)
//!
	struct{
		int16_t	real; 			//!< Real Part
		int16_t imag; 			//!< Imaginary Part
	}cplx;
	uint32_t ui32;
}complexCPACKOFF_t;

#endif //VCU2_TYPES

#ifdef __cplusplus
}
#endif // extern "C"

// @} //ingroup

#endif //end of _VCU2_TYPES_H_ definition

// End of File
