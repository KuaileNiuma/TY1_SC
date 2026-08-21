/**
 *************************************************************************************
 * @file viterbi_decoder_test.c
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
#include "viterbi_decoder.h"
#include "device.h"
#include <stdio.h>
#include "alb32r003x_screenTest.h"

//*****************************************************************************
//
// defines
//
//*****************************************************************************
//
// When DATA_PACK_LEN  too large(for example > 32), overflow may happen.
// Sliding windows and rescale are needed to avoid overflow.
// half-word number to be decode 
//
#define DATA_PACK_LEN         32
#define DATA_BITS_LEN         (DATA_PACK_LEN << 4)
#define CODE_RATE             2
#define NEG_STATEMETRIC_INIT  -8192

//
// Decode and encode paramter
// ACS_MODE=2,4,8
// when K=7, only acs8 will be used 
//
#define ACS_MODE 8
//
// SAT=0,1
//
#define SAT      1
//
// OPACK=0,1
//
#define OPACK    1
//
// SYM=0,1
//
#define SYM      0
//
// K=4,7
//
#define K        7
#define CONSTRAINT_LENGTH      K

//*****************************************************************************
//
// globals
//
//*****************************************************************************
uint16_t dataPack[64] =
{ 0x015A, 0x0302, 0x0504, 0x0706, 0x0908, 0x0B0A, 0x0D0C, 0x0F0E, 0x1110, 0x1312, 0x1514, 0x1716, 0x1918, 0x1B1A,
        0x1D1C, 0x1F1E, 0x2120, 0x2322, 0x2524, 0x2726, 0x2928, 0x2B2A, 0x2D2C, 0x2F2E, 0x3130, 0x3332, 0x3534, 0x3736,
        0x3938, 0x3B3A, 0x3D3C, 0x3F3E, 0x4140, 0x4342, 0x4544, 0x4746, 0x4948, 0x4B4A, 0x4D4C, 0x4F4E, 0x5150, 0x5352,
        0x5554, 0x5756, 0x5958, 0x5B5A, 0x5D5C, 0x5F5E, 0x6160, 0x6362, 0x6564, 0x6766, 0x6968, 0x6B6A, 0x6D6C, 0x6F6E,
        0x7170, 0x7372, 0x7574, 0x7776, 0x7978, 0x7B7A, 0x7D7C, 0x7011, };

uint16_t dataBits[DATA_BITS_LEN];
uint16_t dataOut[DATA_BITS_LEN];
int16_t dataReceived[DATA_BITS_LEN << 1];

#if(SYM)
const int32_t BMSELInit     = 0x5500;
unsigned int  bmsel_list[8] = {0x5050,0x5050,0x5050,0x5050,0x0505,0x0505,0x0505,0x0505};
#else
const int32_t BMSELInit = 0x55550000;
unsigned int bmsel_list[8] =
{ 0x55005500, 0x55005500, 0x55005500, 0x55005500, 0x550055, 0x550055, 0x550055, 0x550055 };
#endif

VITERBI_ENCODER_Obj VITERBI_ENCODER;
VITERBI_ENCODER_Handle handleVITERBIEncoder = &VITERBI_ENCODER;

uint16_t pass; //!< Test pass counter
uint16_t fail; //!< Test fail counter

//*****************************************************************************
//
// \brief Viterbi Decoder Test Function
// 
// This function tests the Viterbi decoder by:
// 1. Initializing the system
// 2. Encoding data using the Viterbi encoder
// 3. Decoding the encoded data
// 4. Verifying the decoded data against the original
//
// \return 1 on successful completion
//
//*****************************************************************************
int viterbi_test(void)
{
    //
    // System Initialization
    //
    int ret = 0;
    __RV_CSR_SET(CSR_MSTATUS, MSTATUS_XS);

    //
    // Data Encoding
    //
    // Local variables
    //
    int16_t i, k;
    uint16_t nBits, nBlks;

    VITERBI_ENCODER_blockUnpack2Bits(DATA_PACK_LEN, (uint16_t*) dataPack, (uint16_t*) dataBits);
    for (i = 1; i <= (CONSTRAINT_LENGTH - 1); i++)
    {
        dataBits[DATA_BITS_LEN - i] = 0;
    }

    //
    // Step 2: Initialize the Encoder structure and encode the bit stream followed by
    //
    // Step 2: Initialize the Encoder structure and encode the bit stream followed by
    // quantization of the encoded LLRs. This is the typical process at the transmission end
    //
    VITERBI_ENCODER.u_p = (uint16_t*) dataBits;
    VITERBI_ENCODER.c_p = (uint16_t*) dataReceived;
    VITERBI_ENCODER.cr = CODE_RATE;
    VITERBI_ENCODER.nBits = DATA_BITS_LEN;
    VITERBI_ENCODER.init = (void (*)(void*)) VITERBI_ENCODER_init;
    if (K == 4)
    {
        VITERBI_ENCODER.run = (void (*)(void*)) VITERBI_ENCODER_runK4CR12;
    }
    else
    {
        VITERBI_ENCODER.run = (void (*)(void*)) VITERBI_ENCODER_runK7CR12;

    }
    VITERBI_ENCODER.quantize = (void (*)(void*, int16_t)) VITERBI_ENCODER_quantizeBits;

    VITERBI_ENCODER.init(handleVITERBIEncoder);
    VITERBI_ENCODER.run(handleVITERBIEncoder);
    VITERBI_ENCODER.quantize(handleVITERBIEncoder, 5);

    //
    // Data Decoding
    //
    unsigned int tr1_list[DATA_BITS_LEN];
    unsigned int tr0_list[DATA_BITS_LEN];

    if (K == 4)
    {
        decode_viterbi_K4CR12(dataReceived, dataOut, tr1_list, tr0_list, BMSELInit, NEG_STATEMETRIC_INIT, K, SAT, OPACK,
                SYM, DATA_BITS_LEN, ACS_MODE);
    }
    else
    {
        decode_viterbi_K7CR12(dataReceived, dataOut, tr1_list, tr0_list, bmsel_list, NEG_STATEMETRIC_INIT, K, SAT,
                OPACK, SYM, DATA_BITS_LEN, ACS_MODE);

    }

    //
    // Results Verification
    //
    //
    // Verify the decoded data against the original data
    //
    uint16_t data_out_reserve;
    int e_flag = 0;
    for (k = 0; k < ((DATA_BITS_LEN >> 4) - 1); k++)
    {
        data_out_reserve = ((dataOut[k] >> 8) & 0xff) | ((dataOut[k] << 8) & 0xff00);
        if (dataPack[k] != data_out_reserve)
        {
            e_flag = 1;
            fail++;
        }
        else
        {
            pass++;
        }
    }
    if (e_flag)
    {
        printf("FAIL --decode_viterbi_K%dCR12\n", K);
    }
    else
    {
        printf("PASS --decode_viterbi_K%dCR12\n", K);
    }
    return e_flag ? SC_FAIL : SC_PASS;
}
