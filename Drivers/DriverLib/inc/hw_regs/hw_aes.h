/** 
 *************************************************************************************
 * @file hw_aes.h 
 * @brief This file contains the register definitions and bit definitions for hardware AES.
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

#ifndef HW_AES_H
#define HW_AES_H

/**
 * @brief AES Registers
 *
 * This section contains the register definitions for the AES module.
 */
#define  AES_O_AES                           0x0    /*!< AES base register */
#define  AES_O_CR                            0x4    /*!< Control register */
#define  AES_O_ISR                           0x8    /*!< Interrupt status register */
#define  AES_O_DINR0                         0x10   /*!< Data input register 0 */
#define  AES_O_DINR1                         0x14   /*!< Data input register 1 */
#define  AES_O_DINR2                         0x18   /*!< Data input register 2 */
#define  AES_O_DINR3                         0x1C   /*!< Data input register 3 */
#define  AES_O_DOUTR0                        0x20   /*!< Data output register 0 */
#define  AES_O_DOUTR1                        0x24   /*!< Data output register 1 */
#define  AES_O_DOUTR2                        0x28   /*!< Data output register 2 */
#define  AES_O_DOUTR3                        0x2C   /*!< Data output register 3 */
#define  AES_O_KEYR0                         0x30   /*!< Key register 0 */
#define  AES_O_KEYR1                         0x34   /*!< Key register 1 */
#define  AES_O_KEYR2                         0x38   /*!< Key register 2 */
#define  AES_O_KEYR3                         0x3C   /*!< Key register 3 */
#define  AES_O_KEYR4                         0x40   /*!< Key register 4 */
#define  AES_O_KEYR5                         0x44   /*!< Key register 5 */
#define  AES_O_KEYR6                         0x48   /*!< Key register 6 */
#define  AES_O_KEYR7                         0x4C   /*!< Key register 7 */
#define  AES_O_IVR0                          0x50   /*!< Initialization vector register 0 */
#define  AES_O_IVR1                          0x54   /*!< Initialization vector register 1 */
#define  AES_O_IVR2                          0x58   /*!< Initialization vector register 2 */
#define  AES_O_IVR3                          0x5C   /*!< Initialization vector register 3 */


/**
 * @brief Bit definition for AES_VR register
 */
#define  AES_VR_REVISION                     0x1     /*!< Revision number */
#define  AES_VR_SVERSION                     0x100   /*!< Sub-version number */
#define  AES_VR_PVERSION                     0x10000 /*!< Major version number */

/**
 * @brief Bit definition for AES_CR register
 */
#define  AES_CR_START                        0x1     /*!< Start bit */
#define  AES_CR_IE                           0x2     /*!< Interrupt enable */
#define  AES_CR_WorkMode                     0x8     /*!< Work mode */
#define  AES_CR_EncDecSell                   0x10    /*!< Encryption/decryption select */
#define  AES_CR_AlgSell_S                    0x60    /*!< Algorithm select */
#define  AES_CR_Enddian                      0x100   /*!< Endian mode */

/**
 * @brief Bit definition for AES_ISR register
 */
#define  AES_ISR_DONE                        0x1     /*!< Done flag */
#define  AES_ISR_KEYDONE                     0x2     /*!< Key done flag */
#define  AES_ISR_EDONE                       0x4     /*!< Encryption/decryption done flag */


#endif
