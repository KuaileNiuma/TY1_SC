/**
 *************************************************************************************
 * @file aes.c
 * @brief This file implements the function of AES encryption and decryption.
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


#include "aes.h"

#ifdef IS_ALB32R003X


//*****************************************************************************
//
// AES_Encode
//
//*****************************************************************************
void
AES_ModeSelect(int key_bits, const uint32_t key[8], AES_Runmode mode) {
    uint32_t aes_base = AES_BASE;
    uint32_t alg_sel;

    //
    // Select AES algorithm key length
    //
    switch (key_bits) {
        case 128: alg_sel = 0x20; break;
        case 192: alg_sel = 0x40; break;
        case 256: alg_sel = 0x60; break;
        default: alg_sel = 0x20; break;
    }

    //
    // Configure the algorithm selection in control register
    //
    HWREG(aes_base + AES_O_CR) = (HWREG(aes_base + AES_O_CR) & ~(AES_CR_AlgSell_S)) | alg_sel;
    HWREG(aes_base + AES_O_CR) = (HWREG(aes_base + AES_O_CR) & ~(AES_CR_EncDecSell)) | mode;

    //
    // Write key (from KEYR3 to KEYR0)
    //
    HWREG(aes_base + AES_O_KEYR0) = key[0];
    HWREG(aes_base + AES_O_KEYR1) = key[1];
    HWREG(aes_base + AES_O_KEYR2) = key[2];
    HWREG(aes_base + AES_O_KEYR3) = key[3];
    if (key_bits >= 192) {
        HWREG(aes_base + AES_O_KEYR4) = key[4];
        HWREG(aes_base + AES_O_KEYR5) = key[5];
    }
    if (key_bits == 256) {
        HWREG(aes_base + AES_O_KEYR6) = key[6];
        HWREG(aes_base + AES_O_KEYR7) = key[7];
    }


}


void AES_WriteDIN(const uint32_t din[4]) {
    uint32_t aes_base = AES_BASE;
    //
    // Write plaintext input (DINR3:0)
    //
    HWREG(aes_base + AES_O_DINR0) = din[0];
    HWREG(aes_base + AES_O_DINR1) = din[1];
    HWREG(aes_base + AES_O_DINR2) = din[2];
    HWREG(aes_base + AES_O_DINR3) = din[3];
}



void AES_Start(){
    uint32_t aes_base = AES_BASE;
    //
    // Start encryption
    //
    HWREG(aes_base + AES_O_CR) |= 1;
}


void AES_WaitforComplete(){
    uint32_t aes_base = AES_BASE;
    //
    // Wait for encryption to complete
    //
    while ((HWREG(aes_base + AES_O_ISR) & AES_ISR_DONE) == 0) {}
}




void AES_ReadDout(uint32_t dout[4]) {
    uint32_t aes_base = AES_BASE;
    //
    // Read ciphertext output (DOUTR3:0)
    //
    dout[0] = HWREG(aes_base + AES_O_DOUTR0);
    dout[1] = HWREG(aes_base + AES_O_DOUTR1);
    dout[2] = HWREG(aes_base + AES_O_DOUTR2);
    dout[3] = HWREG(aes_base + AES_O_DOUTR3);
}



//*****************************************************************************
//
// AES_Bigmode
//
//*****************************************************************************
void
AES_Bigmode() {
    uint32_t aes_base = AES_BASE;
    //
    // Configure AES for big-endian mode
    //
    HWREG(aes_base + AES_O_CR) = (HWREG(aes_base + AES_O_CR) & ~(AES_CR_Enddian)) | AES_CR_Enddian;
}


//*****************************************************************************
//
// AES_CBCmode
//
//*****************************************************************************
void
AES_CBCmode(){
    uint32_t aes_base = AES_BASE;
    //
    // Configure AES for CBC mode operation
    //
    HWREG(aes_base + AES_O_CR) = (HWREG(aes_base + AES_O_CR) & ~(AES_CR_WorkMode)) | AES_CR_WorkMode;
}

//*****************************************************************************
//
// AES_EnableInt
//
//*****************************************************************************
void
AES_EnableInt(){
    uint32_t aes_base = AES_BASE;
    //
    // Enable AES interrupt
    //
    HWREG(aes_base + AES_O_CR) = (HWREG(aes_base + AES_O_CR) & ~(AES_CR_IE)) | AES_CR_IE;
}



//*****************************************************************************
//
// AES_ClearCompleteFlag
//
//*****************************************************************************
void
AES_ClearCompleteFlag(){
    uint32_t aes_base = AES_BASE;
    //
    // Enable AES interrupt
    //
     HWREG(aes_base + AES_O_ISR) = 0;//AES_ISR_DONE;
}

#endif // IS_ALB32RP65

