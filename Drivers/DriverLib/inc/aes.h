/** 
 *************************************************************************************
 * @file aes.h 
 * @brief This file contains the function declarations and definitions for AES.
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

#ifndef __AES_H
#define __AES_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif


#include "hw_common.h"
#include "hw_aes.h"


typedef enum
{

    AES_Encode            = 0x0000,
	AES_Decode            = 0x0010

} AES_Runmode;

//*****************************************************************************
//
//! AES encryption function.
//! 
//! \param key_bits  Length of the key in bits (128, 192, or 256).
//! \param key       Pointer to the key array.
//! \param din       Pointer to the input data array.
//! \param dout      Pointer to the output data array.
//! 
//! This function performs AES encryption with the specified key length.
//! 
//! \return None
//
//*****************************************************************************
void AES_ModeSelect(int key_bits, const uint32_t key[8], AES_Runmode mode);




void AES_WriteDIN(const uint32_t din[4]);



void AES_Start();



void AES_WaitforComplete();



void AES_ReadDout(uint32_t dout[4]);
//*****************************************************************************
//
//! Sets AES to big-endian mode.
//! 
//! This function configures the AES module to use big-endian byte order.
//! 
//! \return None
//
//*****************************************************************************
void AES_Bigmode();

//*****************************************************************************
//
//! Sets AES to CBC mode.
//! 
//! This function configures the AES module to use Cipher Block Chaining (CBC) mode.
//! 
//! \return None
//
//*****************************************************************************
void AES_CBCmode();

//*****************************************************************************
//
//! Enables AES interrupts.
//! 
//! This function enables interrupts for the AES module.
//! 
//! \return None
//
//*****************************************************************************
void AES_EnableInt();

//*****************************************************************************
//
//! Clear AES interrupts flag.
//!
//! This function clears interrupts flag for the AES module.
//!
//! \return None
//
//*****************************************************************************
void AES_ClearCompleteFlag();


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
