/** 
  *************************************************************************************
  * @file cmac_mode.h 
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

#ifndef __TC_CMAC_MODE_H__
#define __TC_CMAC_MODE_H__

#include <aes.h>

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* padding for last message block */
#define TC_CMAC_PADDING 0x80

/* struct tc_cmac_struct represents the state of a CMAC computation */
typedef struct tc_cmac_struct {
/* initialization vector */
	uint8_t iv[TC_AES_BLOCK_SIZE];
/* used if message length is a multiple of block_size bytes */
	uint8_t K1[TC_AES_BLOCK_SIZE];
/* used if message length isn't a multiple block_size bytes */
	uint8_t K2[TC_AES_BLOCK_SIZE];
/* where to put bytes that didn't fill a block */
	uint8_t leftover[TC_AES_BLOCK_SIZE];
/* identifies the encryption key */
	unsigned int keyid;
/* next available leftover location */
	unsigned int leftover_offset;
/* AES key schedule */
	TCAesKeySched_t sched;
/* calls to tc_cmac_update left before re-key */
	uint64_t countdown;
} *TCCmacState_t;

/**
 * @brief Configures the CMAC state to use the given AES key
 * @return returns TC_CRYPTO_SUCCESS (1) after having configured the CMAC state
 *         returns TC_CRYPTO_FAIL (0) if:
 *              s == NULL or
 *              key == NULL
 *
 * @param s IN/OUT -- the state to set up
 * @param key IN -- the key to use
 * @param sched IN -- AES key schedule
 */
int tc_cmac_setup(TCCmacState_t s, const uint8_t *key,
		      TCAesKeySched_t sched);

/**
 * @brief Erases the CMAC state
 * @return returns TC_CRYPTO_SUCCESS (1) after having configured the CMAC state
 *         returns TC_CRYPTO_FAIL (0) if:
 *              s == NULL
 *
 * @param s IN/OUT -- the state to erase
 */
int tc_cmac_erase(TCCmacState_t s);

/**
 * @brief Initializes a new CMAC computation
 * @return returns TC_CRYPTO_SUCCESS (1) after having initialized the CMAC state
 *         returns TC_CRYPTO_FAIL (0) if:
 *              s == NULL
 *
 * @param s IN/OUT -- the state to initialize
 */
int tc_cmac_init(TCCmacState_t s);

/**
 * @brief Incrementally computes CMAC over the next data segment
 * @return returns TC_CRYPTO_SUCCESS (1) after successfully updating the CMAC state
 *         returns TC_CRYPTO_FAIL (0) if:
 *              s == NULL or
 *              if data == NULL when dlen > 0
 *
 * @param s IN/OUT -- the CMAC state
 * @param data IN -- the next data segment to MAC
 * @param dlen IN -- the length of data in bytes
 */
int tc_cmac_update(TCCmacState_t s, const uint8_t *data, size_t dlen);

/**
 * @brief Generates the tag from the CMAC state
 * @return returns TC_CRYPTO_SUCCESS (1) after successfully generating the tag
 *         returns TC_CRYPTO_FAIL (0) if:
 *              tag == NULL or
 *              s == NULL
 *
 * @param tag OUT -- the CMAC tag
 * @param s IN -- CMAC state
 */
int tc_cmac_final(uint8_t *tag, TCCmacState_t s);

#ifdef __cplusplus
}
#endif

#endif /* __TC_CMAC_MODE_H__ */
