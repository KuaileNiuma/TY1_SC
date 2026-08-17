/**
 *************************************************************************************
 * @file eflashc.h
 * @brief This file contains the definition of eflashc driver.
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

#ifndef __EFLASHC_H
#define __EFLASHC_H

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
#include "hw_eflashc.h"

typedef struct
{
    __IO uint32_t ACR;
    __O  uint32_t KEYR;
    __O  uint32_t OPTKEYR;
    __IO uint32_t SR;
    __IO uint32_t CR;
    __O  uint32_t OPTCR;
} FLASH_TypeDef;

typedef enum
{
  FLASH_PSIZE_BYTE = 0,
  FLASH_PSIZE_HARFWORD,
  FLASH_PSIZE_WORD,
  FLASH_PSIZE_TWOWORD,
  FLASH_PSIZE_FOURWORD
}FLASH_PSIZE;

#define FLASH_LETENCY_MAX    7
void Flash_matchLatency(uint32_t sys_clock);
void FLASH_setLatency(uint32_t FLASH_Latency);
void FLASH_setPrefetchEn(FunctionalState NewState);
void FLASH_setIcacheEn(FunctionalState NewState);
void FLASH_setDcacheEn(FunctionalState NewState);
void FLASH_resetIcahe(void);
void FLASH_resetDcahe(void);
void FLASH_setPrefetchMode(FunctionalState NewState);
void FLASH_unlock(void);
void FLASH_lock(void);
uint32_t FLASH_busy(void);
void FLASH_readUnlock(void);
void FLASH_eraseSector(uint16_t Sector_Num);
void FLASH_eraseBank0(void);
void FLASH_program(uint8_t *pdata, uint32_t offset, FLASH_PSIZE psize);
void FLASH_readBuff(uint8_t *buffer, uint32_t offset, uint32_t count);
void flash_writeBuff(uint8_t *buffer, uint32_t offset, uint32_t count);
void FLASH_itConfig(uint32_t FLASH_IT, FunctionalState NewState);
FlagStatus FLASH_getFlagStatus(uint32_t FLASH_FLAG);
void FLASH_clearFlag(uint32_t FLASH_FLAG);
uint32_t FLASH_getStatus(void);
void FLASH_OB_unlock(void);
void FLASH_OB_lock(void);
uint32_t FLASH_OB_getOPTCR(void);
void FLASH_OB_WRPconfig(uint32_t OB_WRP, FunctionalState NewState);
void FLASH_OB_PCROPenable(FunctionalState NewState);
void FLASH_OB_RDPconfig(uint32_t OB_RDP);
void FLASH_OB_userConfig(uint8_t OB_IWDG, uint8_t OB_STOP, uint8_t OB_STDBY);
void FLASH_OB_BORconfig(uint8_t OB_BOR);
uint8_t FLASH_OB_getUser(void);
FlagStatus FLASH_OB_getRDP(void);
uint8_t FLASH_OB_getBOR(void);
uint16_t FLASH_OB_getWRP(void);
uint16_t FLASH_OB_getPCROP(void);
void FLASH_OB_launch(void);
void FLASH_CDC_unlock(void);
void FLASH_CDC_erase (uint32_t arrdn, uint32_t nvr, uint16_t address);
void FLASH_OTP_CDCerase (void);
void FLASH_OTP_program (uint8_t *pdata, uint32_t address, FLASH_PSIZE psize);
void FLASH_CDC_program (uint32_t arrdn, uint32_t nvr, uint32_t address, uint32_t DIN0,
        uint32_t DIN1, uint32_t DIN2, uint32_t DIN3);
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __FLASH_H */
