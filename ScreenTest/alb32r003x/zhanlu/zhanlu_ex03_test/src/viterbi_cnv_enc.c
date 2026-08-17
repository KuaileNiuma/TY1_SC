/**
 *************************************************************************************
 * @file viterbi_cnv_enc.c
 * @brief This file contains the source file.
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

//*****************************************************************************
//
// includes
//
//*****************************************************************************
#include "viterbi_encoder.h"

//*****************************************************************************
//
// \brief Initialize the encoder structure by zeroing out the delay line
// \param hndVITEncoder Handle to the Viterbi Encoder Structure
//
//*****************************************************************************
void VITERBI_ENCODER_init(VITERBI_ENCODER_Handle hndVITEncoder)
{
    int16_t i;
    for (i = 0; i < MAX_CNV_ENC_DELAY_LEN; i++)
    {
        hndVITEncoder->delay[0] = 0;
    }
}

//*****************************************************************************
//
// \brief This function performs convolution encoding in prime. It uses
// constraint length of K=7, and code rate 1/2.
// 
// The polynomials are:
// G0 = 1 + D2 + D3
// G1 = 1 + D  + D2 + D3
//                                                       
// It calculates:
// c(2k  )=u(k)+u(k-2)+u(k-3)
// c(2k+1)=u(k)+u(k-1)+u(k-2)+u(k-3)
//
// \param hndVITEncoder handle to the Viterbi encoder object whose elements are
//        nBits - number of input bits for decode                         
//        u_p   - pointer to input uncoded bits                                    
//        c_p   - pointer to output coded bits 
//                (It produces 2xnBit bits)                           
//*****************************************************************************
void VITERBI_ENCODER_runK4CR12(VITERBI_ENCODER_Handle hndVITEncoder)
{
    uint16_t *c_p, *u_p, *d_p, *uu_p, tmp;
    int16_t i;

    u_p = hndVITEncoder->u_p;
    c_p = hndVITEncoder->c_p;
    d_p = &hndVITEncoder->delay[0];

    c_p[0] = (u_p[0] ^ d_p[1] ^ d_p[0]);
    c_p[1] = (u_p[0] ^ d_p[2] ^ d_p[1] ^ d_p[0]);
    c_p[2] = (u_p[1] ^ d_p[1] ^ d_p[0]);
    c_p[3] = (u_p[1] ^ u_p[0] ^ d_p[1] ^ d_p[0]);
    c_p[4] = (u_p[2] ^ u_p[0] ^ d_p[0]);
    c_p[5] = (u_p[2] ^ u_p[1] ^ u_p[0] ^ d_p[0]);

    c_p = &c_p[6];

    uu_p = u_p;
    for (i = 3; i < hndVITEncoder->nBits; i++)
    {
        tmp = uu_p[3] ^ uu_p[1] ^ uu_p[0];
        *c_p++ = tmp;
        *c_p++ = tmp ^ uu_p[2];
        uu_p++;
    }
    //
    // Update delays 
    //
    u_p += (hndVITEncoder->nBits - K7_CNV_ENC_DELAY_LEN);
    for (i = 0; i < K7_CNV_ENC_DELAY_LEN; i++)
        *d_p++ = *u_p++;

}

//*****************************************************************************
//
// \brief This function performs convolution encoding in prime. It uses
// constraint length of K=7, and code rate 1/2.
// 
// The polynomials are:
// G0 = 1 + D + D2 +D3 + D6                                            
// G1 = 1 + D2 + D3 + D5 + D6  
//                                                       
// It calculates:
// c(2k  )=u(k)+u(k-1)+u(k-2)+u(k-3)+u(k-6)                  
// c(2k+1)=u(k)+u(k-2)+u(k-3)+u(k-5)+u(k-6)
//
// \param hndVITEncoder handle to the Viterbi encoder object whose elements are
//        nBits - number of input bits for decode                         
//        u_p   - pointer to input uncoded bits                                    
//        c_p   - pointer to output coded bits 
//                (It produces 2xnBit bits)    
//                       
//*****************************************************************************
void VITERBI_ENCODER_runK7CR12(VITERBI_ENCODER_Handle hndVITEncoder)
{
    uint16_t *c_p, *u_p, *d_p, *uu_p, tmp;
    int16_t i;

    u_p = hndVITEncoder->u_p;
    c_p = hndVITEncoder->c_p;
    d_p = &hndVITEncoder->delay[0];

    c_p[0] = (u_p[0] ^ d_p[5] ^ d_p[4] ^ d_p[3] ^ d_p[0]);
    c_p[1] = (u_p[0] ^ d_p[4] ^ d_p[3] ^ d_p[1] ^ d_p[0]);
    c_p[2] = (u_p[1] ^ u_p[0] ^ d_p[5] ^ d_p[4] ^ d_p[1]);
    c_p[3] = (u_p[1] ^ d_p[5] ^ d_p[4] ^ d_p[2] ^ d_p[1]);
    c_p[4] = (u_p[2] ^ u_p[1] ^ u_p[0] ^ d_p[5] ^ d_p[2]);
    c_p[5] = (u_p[2] ^ u_p[0] ^ d_p[5] ^ d_p[3] ^ d_p[2]);
    c_p[6] = (u_p[3] ^ u_p[2] ^ u_p[1] ^ u_p[0] ^ d_p[3]);
    c_p[7] = (u_p[3] ^ u_p[1] ^ u_p[0] ^ d_p[4] ^ d_p[3]);
    c_p[8] = (u_p[4] ^ u_p[3] ^ u_p[2] ^ u_p[1] ^ d_p[4]);
    c_p[9] = (u_p[4] ^ u_p[2] ^ u_p[1] ^ d_p[5] ^ d_p[4]);
    c_p[10] = (u_p[5] ^ u_p[4] ^ u_p[3] ^ u_p[2] ^ d_p[5]);
    c_p[11] = (u_p[5] ^ u_p[3] ^ u_p[2] ^ u_p[0] ^ d_p[5]);

    c_p = &c_p[12];

    uu_p = u_p;
    for (i = 6; i < hndVITEncoder->nBits; i++)
    {
        tmp = uu_p[6] ^ uu_p[4] ^ uu_p[3] ^ uu_p[0];
        *c_p++ = tmp ^ uu_p[5];
        *c_p++ = tmp ^ uu_p[1];
        uu_p++;
    }

    //
    // Update delays 
    //
    u_p += (hndVITEncoder->nBits - K4_CNV_ENC_DELAY_LEN);
    for (i = 0; i < K4_CNV_ENC_DELAY_LEN; i++)
        *d_p++ = *u_p++;

}

//*****************************************************************************
//
// \brief Quantization of Encoder Bits
// \param hndVITEncoder handle to the Viterbi encoder object whose elements are
//        nBits - number of input bits to be quantized                         
//        c_p   - pointer to output coded bits 
// \param format power of 2, the bits will be quantized to +-(2^format)
//
//*****************************************************************************
void VITERBI_ENCODER_quantizeBits(VITERBI_ENCODER_Handle hndVITEncoder, int16_t format)
{
    int16_t i;
    int16_t value;

    value = 1 << format;

    //
    // Quantize the bits
    //
    for (i = 0; i < (hndVITEncoder->nBits * hndVITEncoder->cr); i++)
    {
        if (hndVITEncoder->c_p[i] == 0)
            hndVITEncoder->c_p[i] = value;
        else
            hndVITEncoder->c_p[i] = -value;
    }
}

//*****************************************************************************
//
// \breif Word Unpacking to Bits
// \param[in]  nSize number of 16-bits words 
// \param[in]  in_p  pointer to input data in 16-bit words
// \param[out] out_p pointer to output data in bits 
//
//*****************************************************************************
#include <stdio.h>
void VITERBI_ENCODER_blockUnpack2Bits(uint16_t nSize, uint16_t *in_p, uint16_t *out_p)
{
    int16_t i;
    uint16_t data;
    for (i = 0; i < (nSize << 1); i++)
    {
        data = *((uint8_t*) in_p + i);
        //data = __byte((int *)in_p,i);
        //printf("%d\n",data);
        *out_p++ = (data >> 7) & 0x1;
        *out_p++ = (data >> 6) & 0x1;
        *out_p++ = (data >> 5) & 0x1;
        *out_p++ = (data >> 4) & 0x1;
        *out_p++ = (data >> 3) & 0x1;
        *out_p++ = (data >> 2) & 0x1;
        *out_p++ = (data >> 1) & 0x1;
        *out_p++ = (data) & 0x1;
    }
}

