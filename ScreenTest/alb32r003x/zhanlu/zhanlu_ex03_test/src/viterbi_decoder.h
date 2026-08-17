/**
 *************************************************************************************
 * @file viterbi_decoder.h
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
#ifndef _VITERBI_DECODER_H_
#define _VITERBI_DECODER_H_
//*****************************************************************************
//
// includes
//
//*****************************************************************************
#include <stdint.h>

//*****************************************************************************
//
// typedefs
//
//*****************************************************************************
typedef void (*STAGE_DECODE)(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[]);

//*****************************************************************************
//
// Initialize the state metric in VR and configure decoding parameters
//
//*****************************************************************************
void initK4CR12(int init_value, int k, int sat, int opack, int sym);

//*****************************************************************************
//
// Initialize the state metric in MEM and configure decoding parameters
//
//*****************************************************************************
void initK7CR12(int init_value, int k, int sat, int opack, int sym, uint32_t old_sm[]);

//*****************************************************************************
//
// Compute one stage use acs2 instruction
//
//*****************************************************************************
void decode_1stage_acs2_K4CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[]);

//*****************************************************************************
//
// Compute one stage use acs4 instruction
//
//*****************************************************************************
void decode_1stage_acs4_K4CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[]);

//*****************************************************************************
//
// Compute one stage use acs8 instruction
//
//*****************************************************************************
void decode_1stage_acs8_K4CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[]);

//*****************************************************************************
//
// Compute one stage use acs8 instruction
//
//*****************************************************************************
void decode_1stage_acs8_K7CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[],
        uint32_t old_sm[], int32_t new_sm[]);

//*****************************************************************************
//
// vitervi decode 
//
//*****************************************************************************
void decode_viterbi_K4CR12(int16_t data_bits_in[], uint16_t data_pack_out[], unsigned int tr1_list[],
        unsigned int tr0_list[], unsigned int bm_sel, int init_value, int k, int sat, int opack, int sym,
        int data_bits_len, int acs_mode);

//
// \brief vitervi decode 
//
void decode_viterbi_K7CR12(int16_t data_bits_in[], uint16_t data_pack_out[], unsigned int tr1_list[],
        unsigned int tr0_list[], unsigned int bm_sel_list[], int init_value, int k, int sat, int opack, int sym,
        int data_bits_len, int acs_mode);

#endif //end of _VITERBI_DECODER_H_ definition

// End of File
