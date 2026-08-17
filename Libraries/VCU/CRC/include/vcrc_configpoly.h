/** 
  *************************************************************************************
  * @file vcrc_configpoly.h 
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

#ifndef _VCU_CONFIGPOLY_H
#define _VCU_CONFIGPOLY_H

#include "vcu2_crc.h"
//!
//! \defgroup VCRC_APIS VCRC Configurable Polynomial APIs

//!
//! \ingroup VCRC_APIS
// @{

//*****************************************************************************
// function prototypes
//*****************************************************************************

//! \brief Runs the CRC routine using provided polynomial
//!        with the input bits reversed, message size in bytes.
//!
//!  The polynomial to be used is set by the element \b polynomial in the \b CRC_Obj.
//!  The size of the polynomial is set by the element \b polySize in the \b CRC_Obj.
//!  For example - to use a 1 bit polynomial \b polySize must be set to 0x0 and
//!  to use a 32 bit polynomial \b polySize must be set to 0x1F. The size of the data is set
//!  by the element \b dataSize in \b the CRC_Obj. \b Datasize refers to the integral unit
//!  on which the CRC is computed. For example - to use data size of 1 bit \b dataSize must be set
//!  to 0x0 and data size of 8 bit is set by setting \b dataSize to a value of 0x7. These values
//!  finally translate to elements in the \b VCRCSIZE register - \b PSIZE and \b DSIZE fields and they are
//!  set in the functions \b _CRC_runConfigPolyBytes implemented in the asm file \b vcrc_configpoly_asm.asm.
//!  Total size of the message on which the CRC to be computed is specified by the element \b MsgBytes
//!  in the \b CRC_Obj.
//!
//! \param[in] hndCRC handle to the CRC object
//
void CRC_runConfigPolyBytesReflected(CRC_Handle hndCRC);

//! \brief Runs the CRC routine using provided polynomial
//!        with the input bits reversed, message size in bits.
//!
//!  The polynomial to be used is set by the element \b polynomial in the \b CRC_Obj.
//!  The size of the polynomial is set by the element \b polySize in the \b CRC_Obj.
//!  For example - to use a 1 bit polynomial \b polySize must be set to 0x0 and
//!  to use a 32 bit polynomial \b polySize must be set to 0x1F. The size of the data is set
//!  by the element \b dataSize in \b the CRC_Obj. \b Datasize refers to the integral unit
//!  on which the CRC is computed. For example - to use data size of 1 bit \b dataSize must be set
//!  to 0x0 and data size of 8 bit is set by setting \b dataSize to a value of 0x7. These values
//!  finally translate to elements in the \b VCRCSIZE register - \b PSIZE and \b DSIZE fields and they are
//!  set in the functions \b _CRC_runConfigPolyBytes implemented in the asm file \b vcrc_configpoly_asm.asm.
//!  Total size of the message on which the CRC to be computed is specified by the element \b MsgBytes
//!  in the \b CRC_Obj.
//!
//! \param[in] hndCRC handle to the CRC object
//
void CRC_runConfigPolyBitsReflected(CRC_Handle hndCRC);

//! \brief Runs the CRC routine using provided polynomial with message size in bytes.
//!
//!  The polynomial to be used is set by the element \b polynomial in the \b CRC_Obj.
//!  The size of the polynomial is set by the element \b polySize in the \b CRC_Obj.
//!  For example - to use a 1 bit polynomial \b polySize must be set to 0x0 and
//!  to use a 32 bit polynomial \b polySize must be set to 0x1F. The size of the data is set
//!  by the element \b dataSize in \b the CRC_Obj. \b Datasize refers to the integral unit
//!  on which the CRC is computed. For example - to use data size of 1 bit \b dataSize must be set
//!  to 0x0 and data size of 8 bit is set by setting \b dataSize to a value of 0x7. These values
//!  finally translate to elements in the \b VCRCSIZE register - \b PSIZE and \b DSIZE fields and they are
//!  set in the functions \b _CRC_runConfigPolyBytes implemented in the asm file \b vcrc_configpoly_asm.asm.
//!  Total size of the message on which the CRC to be computed is specified by the element \b MsgBytes
//!  in the \b CRC_Obj.
//!
//! \param[in] hndCRC handle to the CRC object
//
void CRC_runConfigPolyBytes(CRC_Handle hndCRC);

//! \brief Runs the CRC routine using provided polynomial with message size in bits.
//!
//!  The polynomial to be used is set by the element \b polynomial in the \b CRC_Obj.
//!  The size of the polynomial is set by the element \b polySize in the \b CRC_Obj.
//!  For example - to use a 1 bit polynomial \b polySize must be set to 0x0 and
//!  to use a 32 bit polynomial \b polySize must be set to 0x1F. The size of the data is set
//!  by the element \b dataSize in \b the CRC_Obj. \b Datasize refers to the integral unit
//!  on which the CRC is computed. For example - to use data size of 1 bit \b dataSize must be set
//!  to 0x0 and data size of 8 bit is set by setting \b dataSize to a value of 0x7. These values
//!  finally translate to elements in the \b VCRCSIZE register - \b PSIZE and \b DSIZE fields and they are
//!  set in the functions \b _CRC_runConfigPolyBytes implemented in the asm file \b vcrc_configpoly_asm.asm.
//!  Total size of the message on which the CRC to be computed is specified by the element \b MsgBytes
//!  in the \b CRC_Obj.
//!
//! \param[in] hndCRC handle to the CRC object
//
void CRC_runConfigPolyBits(CRC_Handle hndCRC);

// @} //ingroup

#endif
