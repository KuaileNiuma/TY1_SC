/** 
  *************************************************************************************
  * @file ctr_mode.h 
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

#ifndef __TC_CTR_MODE_H__
#define __TC_CTR_MODE_H__

#include <aes.h>
#include <constants.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief CTR mode encryption/decryption procedure.
 *  CTR mode encrypts (or decrypts) inlen bytes from in buffer into out buffer
 *  @return returns TC_CRYPTO_SUCCESS (1)
 *          returns TC_CRYPTO_FAIL (0) if:
 *                out == NULL or
 *                in == NULL or
 *                ctr == NULL or
 *                sched == NULL or
 *                inlen == 0 or
 *                outlen == 0 or
 *                inlen != outlen
 *  @note Assumes:- The current value in ctr has NOT been used with sched
 *              - out points to inlen bytes
 *              - in points to inlen bytes
 *              - ctr is an integer counter in littleEndian format
 *              - sched was initialized by aes_set_encrypt_key
 * @param out OUT -- produced ciphertext (plaintext)
 * @param outlen IN -- length of ciphertext buffer in bytes
 * @param in IN -- data to encrypt (or decrypt)
 * @param inlen IN -- length of input data in bytes
 * @param ctr IN/OUT -- the current counter value
 * @param sched IN -- an initialized AES key schedule
 */
int tc_ctr_mode(uint8_t *out, unsigned int outlen, const uint8_t *in,
		unsigned int inlen, uint8_t *ctr, const TCAesKeySched_t sched);

#ifdef __cplusplus
}
#endif

#endif /* __TC_CTR_MODE_H__ */
