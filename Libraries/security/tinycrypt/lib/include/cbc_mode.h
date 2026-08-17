/** 
  *************************************************************************************
  * @file cbc_mode.h 
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

#ifndef __TC_CBC_MODE_H__
#define __TC_CBC_MODE_H__

#include <aes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief CBC encryption procedure
 *  CBC encrypts inlen bytes of the in buffer into the out buffer
 *  using the encryption key schedule provided, prepends iv to out
 *  @return returns TC_CRYPTO_SUCCESS (1)
 *          returns TC_CRYPTO_FAIL (0) if:
 *                out == NULL or
 *                in == NULL or
 *                ctr == NULL or
 *                sched == NULL or
 *                inlen == 0 or
 *                (inlen % TC_AES_BLOCK_SIZE) != 0 or
 *                (outlen % TC_AES_BLOCK_SIZE) != 0 or
 *                outlen != inlen + TC_AES_BLOCK_SIZE
 *  @note Assumes: - sched has been configured by aes_set_encrypt_key
 *              - iv contains a 16 byte random string
 *              - out buffer is large enough to hold the ciphertext + iv
 *              - out buffer is a contiguous buffer
 *              - in holds the plaintext and is a contiguous buffer
 *              - inlen gives the number of bytes in the in buffer
 *  @param out IN/OUT -- buffer to receive the ciphertext
 *  @param outlen IN -- length of ciphertext buffer in bytes
 *  @param in IN -- plaintext to encrypt
 *  @param inlen IN -- length of plaintext buffer in bytes
 *  @param iv IN -- the IV for the this encrypt/decrypt
 *  @param sched IN --  AES key schedule for this encrypt
 */
int tc_cbc_mode_encrypt(uint8_t *out, unsigned int outlen, const uint8_t *in,
			unsigned int inlen, const uint8_t *iv,
			const TCAesKeySched_t sched);

/**
 * @brief CBC decryption procedure
 * CBC decrypts inlen bytes of the in buffer into the out buffer
 * using the provided encryption key schedule
 * @return returns TC_CRYPTO_SUCCESS (1)
 *         returns TC_CRYPTO_FAIL (0) if:
 *                out == NULL or
 *                in == NULL or
 *                sched == NULL or
 *                inlen == 0 or
 *                outlen == 0 or
 *                (inlen % TC_AES_BLOCK_SIZE) != 0 or
 *                (outlen % TC_AES_BLOCK_SIZE) != 0 or
 *                outlen != inlen + TC_AES_BLOCK_SIZE
 * @note Assumes:- in == iv + ciphertext, i.e. the iv and the ciphertext are
 *                contiguous. This allows for a very efficient decryption
 *                algorithm that would not otherwise be possible
 *              - sched was configured by aes_set_decrypt_key
 *              - out buffer is large enough to hold the decrypted plaintext
 *              and is a contiguous buffer
 *              - inlen gives the number of bytes in the in buffer
 * @param out IN/OUT -- buffer to receive decrypted data
 * @param outlen IN -- length of plaintext buffer in bytes
 * @param in IN -- ciphertext to decrypt, including IV
 * @param inlen IN -- length of ciphertext buffer in bytes
 * @param iv IN -- the IV for the this encrypt/decrypt
 * @param sched IN --  AES key schedule for this decrypt
 *
 */
int tc_cbc_mode_decrypt(uint8_t *out, unsigned int outlen, const uint8_t *in,
			unsigned int inlen, const uint8_t *iv,
			const TCAesKeySched_t sched);

#ifdef __cplusplus
}
#endif

#endif /* __TC_CBC_MODE_H__ */
