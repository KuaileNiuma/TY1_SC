/** 
  *************************************************************************************
  * @file flash_api.h 
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
 
#ifndef _FLASH_API_H_
#define _FLASH_API_H_

#include "Registers.h"
#include "Types.h"


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



/* Flash C API functions*/

/* Flash State Machine commands */
extern Fapi_FlashStatusType Fapi_getFsmStatus(Fapi_FlashBankType iFlashBank);

extern Fapi_StatusType Fapi_checkFsmForReady(Fapi_FlashBankType iFlashBank);

extern Fapi_StatusType Fapi_setActiveFlashBank(Fapi_FlashBankType oNewFlashBank);

extern Fapi_StatusType Fapi_issueFsmSuspendCommand(void);

extern void Fapi_flushPipeline(void);

extern Fapi_StatusType Fapi_setupBankSectorEnable(uint32 reg_address, uint32 value);

/* Device Family Dependent FSM commands */
extern uint32 * Fapi_remapEccAddress(uint32 u32EccAddress);

extern boolean Fapi_isAddressEcc(uint32 u32Address);

/* Async Commands */
extern Fapi_StatusType Fapi_issueAsyncCommandWithAddress(
		                                                Fapi_FlashBankType iFlashBank,
                                                        Fapi_FlashStateCommandsType oCommand,
                                                        uint32 *pu32StartAddress
                                                        );

extern Fapi_StatusType Fapi_issueAsyncCommand(Fapi_FlashBankType iFlashBank,Fapi_FlashStateCommandsType oCommand);

extern Fapi_StatusType Fapi_issueBankEraseCommand(uint32 *pu32StartAddress);

/* Info Commands */
extern Fapi_LibraryInfoType Fapi_getLibraryInfo(void);

/* Init */
extern  Fapi_StatusType Fapi_initializeAPI(
											Fapi_FlashBankType iFlashBank,
											Fapi_FmcRegistersType *poFlashControlRegister,
											uint32 u32HclkFrequency);

/* Read commands */
extern Fapi_StatusType Fapi_doBlankCheck(
		                                Fapi_FlashBankType iFlashBank,
                                        uint32 *pu32StartAddress,
                                        uint32 u32Length,
                                        Fapi_FlashStatusWordType *poFlashStatusWord
                                        );

extern Fapi_StatusType Fapi_doVerify(
                                    uint32 *pu32StartAddress,
                                    uint32 u32Length,
                                    uint32 *pu32CheckValueBuffer,
                                    Fapi_FlashStatusWordType *poFlashStatusWord
                                    );

extern Fapi_StatusType Fapi_doVerifyBy16bits(
                             uint16 *pu16StartAddress,
                             uint32 u16Length,
                             uint16 *pu16CheckValueBuffer,
                             Fapi_FlashStatusWordType *poFlashStatusWord
                             );


/* Programming Commands */
extern Fapi_StatusType Fapi_issueProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32DataBuffer,
                                            uint32  u32DataBufferSizeInWords,
                                            uint32 *pu32EccBuffer,
                                            uint32  u32EccBufferSizeInBytes,
                                            Fapi_FlashProgrammingCommandsType oMode
                                            );

extern Fapi_StatusType Fapi_issueDataOnly512ProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32DataBuffer,
                                            uint32  u32DataBufferSizeInWords
                                            );
											
extern Fapi_StatusType Fapi_issueAutoEcc512ProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32DataBuffer,
                                            uint32  u32DataBufferSizeInWords
                                            );											

extern Fapi_StatusType Fapi_issueDataAndEcc512ProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32DataBuffer,
                                            uint32  u32DataBufferSizeInWords,
                                            uint32 *pu32EccBuffer,
                                            uint32  u32EccBufferSizeInBytes
                                            );

extern Fapi_StatusType Fapi_issueEccOnly64ProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32EccBuffer,
                                            uint32  u32EccBufferSizeInBytes
                                            );

extern Fapi_StatusType Fapi_issueProgrammingCommandForEccAddresses(
                                                           uint32 *pu32StartAddress,
                                                           uint32 *pu16EccBuffer,
                                                           uint32 u16EccBufferSizeInBytes
                                                           );


/* Utility Commands */
extern uint32 Fapi_calculateFletcherChecksum(
                                            uint32 const * pu32Data,
                                            uint32 u32Length
                                            );

extern uint8 Fapi_calculateEcc(
                               uint32 u32Address,
                               uint64 u64Data
                               );

extern Fapi_StatusType Fapi_configureFMAC(uint32 u32Address);

extern void Write_32bp(uint32 reg_offset, uint32 mask, uint32 shift, uint32 value);

extern void Write_32(uint32 ctrlBase, uint32 reg_offset, uint32 mask, uint32 shift, uint32 value);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif 
