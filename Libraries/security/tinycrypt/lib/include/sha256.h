/** 
  *************************************************************************************
  * @file sha256.h 
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

#ifndef __TC_SHA256_H__
#define __TC_SHA256_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TC_SHA256_BLOCK_SIZE (64)
#define TC_SHA256_DIGEST_SIZE (32)
#define TC_SHA256_STATE_BLOCKS (TC_SHA256_DIGEST_SIZE/4)

struct tc_sha256_state_struct {
	unsigned int iv[TC_SHA256_STATE_BLOCKS];
	uint64_t bits_hashed;
	uint8_t leftover[TC_SHA256_BLOCK_SIZE];
	size_t leftover_offset;
};

typedef struct tc_sha256_state_struct *TCSha256State_t;

/**
 *  @brief SHA256 initialization procedure
 *  Initializes s
 *  @return returns TC_CRYPTO_SUCCESS (1)
 *          returns TC_CRYPTO_FAIL (0) if s == NULL
 *  @param s Sha256 state struct
 */
int tc_sha256_init(TCSha256State_t s);

/**
 *  @brief SHA256 update procedure
 *  Hashes data_length bytes addressed by data into state s
 *  @return returns TC_CRYPTO_SUCCESS (1)
 *          returns TC_CRYPTO_FAIL (0) if:
 *                s == NULL,
 *                s->iv == NULL,
 *                data == NULL
 *  @note Assumes s has been initialized by tc_sha256_init
 *  @warning The state buffer 'leftover' is left in memory after processing
 *           If your application intends to have sensitive data in this
 *           buffer, remind to erase it after the data has been processed
 *  @param s Sha256 state struct
 *  @param data message to hash
 *  @param datalen length of message to hash
 */
int tc_sha256_update (TCSha256State_t s, const uint8_t *data, size_t datalen);

/**
 *  @brief SHA256 final procedure
 *  Inserts the completed hash computation into digest
 *  @return returns TC_CRYPTO_SUCCESS (1)
 *          returns TC_CRYPTO_FAIL (0) if:
 *                s == NULL,
 *                s->iv == NULL,
 *                digest == NULL
 *  @note Assumes: s has been initialized by tc_sha256_init
 *        digest points to at least TC_SHA256_DIGEST_SIZE bytes
 *  @warning The state buffer 'leftover' is left in memory after processing
 *           If your application intends to have sensitive data in this
 *           buffer, remind to erase it after the data has been processed
 *  @param digest unsigned eight bit integer
 *  @param Sha256 state struct
 */
int tc_sha256_final(uint8_t *digest, TCSha256State_t s);

#ifdef __cplusplus
}
#endif

#endif /* __TC_SHA256_H__ */
