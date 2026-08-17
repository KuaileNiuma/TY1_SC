/** 
  *************************************************************************************
  * @file fapi_alb32r003x.c 
  * @author Albatross 
  * @brief This file contains the source file. 
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

#include "FlashTech.h"
#include "device.h"
#include "alb32r003x_sector.h"
#include "hw_types.h"

#define SECTORNUM_SPLI 4
#define  FLASH_WRP_SECTORS  (0x0F<<8)
#define FLASH_SECTOR_SIZE (128*1024)


/* Flash State Machine commands */
ILM_FUNC_T Fapi_FlashStatusType Fapi_getFsmStatus(Fapi_FlashBankType iFlashBank)
{
	 Fapi_FlashStatusType ret = 0;
	 if (Fapi_FlashBank0 == iFlashBank)
	 {
		 ret = FLASH_busy();
	 }
	 else if (Fapi_FlashBank1 == iFlashBank)
	 {
		// ret =  HWREG(XFLASH_R_BASE + XFLASHC_O_FLASH_SR) & FLASH_SR_BSY_Msk;
	 }
	 else
	 {
		 ret = -1;;
	 }
	 return ret;
}

ILM_FUNC_T  Fapi_StatusType Fapi_checkFsmForReady(Fapi_FlashBankType iFlashBank)
{
	 Fapi_StatusType ret = Fapi_Status_FsmReady;
	 if (Fapi_FlashBank0 == iFlashBank)
	 {
		 if (FLASH_busy())
		 {
			 ret = Fapi_Status_FsmBusy;
		 }
	 }
	 else if (Fapi_FlashBank1 == iFlashBank)//TODO
	 {
		 //if (HWREG(XFLASH_R_BASE + XFLASHC_O_FLASH_SR) & FLASH_SR_BSY_Msk)
		 {
			 ret = Fapi_Status_FsmBusy;
		 }
	 }
	 else
	 {
		 ret = Fapi_Error_Fail;
	 }
	 return ret;
}

ILM_FUNC_T  Fapi_StatusType Fapi_setActiveFlashBank(Fapi_FlashBankType oNewFlashBank) /*flash from lower power*/
{
	return Fapi_Status_Success;
}

ILM_FUNC_T  Fapi_StatusType Fapi_issueFsmSuspendCommand(void)
{
	return Fapi_Status_Success;
}

ILM_FUNC_T  void Fapi_flushPipeline(void)
{

}

ILM_FUNC_T  Fapi_StatusType Fapi_setupBankSectorEnable(uint32 reg_address, uint32 value)
{
	return Fapi_Status_Success;
}
/* Device Family Dependent FSM commands */
ILM_FUNC_T  uint32 * Fapi_remapEccAddress(uint32 u32EccAddress)
{
    return 0;
}
ILM_FUNC_T boolean Fapi_isAddressEcc(uint32 u32Address)
{
    return 0;
}

/* Async Commands */
ILM_FUNC_T Fapi_StatusType Fapi_issueAsyncCommandWithAddress(
														Fapi_FlashBankType iFlashBank,
														Fapi_FlashStateCommandsType oCommand,
                                                        uint32 *pu32StartAddress
                                                        )
{
    Fapi_StatusType ret = Fapi_Status_Success;
    int sectorNum = 0;
    uint32_t sprmod;
    uint32_t wrp;

    switch (oCommand)
    {
    case Fapi_ProgramData:
        ret = Fapi_Error_Fail;
        break;
    case Fapi_EraseSector:
    	sectorNum = (((uint32) pu32StartAddress - EFLASH_BASE) / FLASH_SECTOR_SIZE) + EFLASH_Sector_8;
        if ((uint32) pu32StartAddress == (sectorNum - 8) * FLASH_SECTOR_SIZE + EFLASH_BASE)
        {

            FLASH_unlock();
            FLASH_OB_unlock();
            sprmod = FLASH_OB_getOPTCR() & EFLASH_OPTCR_SPRMOD;
            wrp = (FLASH_OB_getOPTCR() >> EFLASH_OPTCR_nWRP_S);
            if ((0 == sprmod && 0 == wrp)
                    || ((EFLASH_OPTCR_SPRMOD == sprmod) && ((1 << sectorNum) == wrp)))
            {
                ret = Fapi_Error_FlashRegsNotWritable;
            }
            else
            {
                FLASH_eraseSector(sectorNum);
            }
            FLASH_OB_lock();
            FLASH_lock();
        }
        //else if //xflash TODO
        else
        {
            ret = Fapi_Error_Fail;
        }

        break;
    case Fapi_EraseBank:
        if (Fapi_FlashBank0 == iFlashBank)
        {
            FLASH_unlock();
            FLASH_OB_unlock();
            sprmod = FLASH_OB_getOPTCR() & EFLASH_OPTCR_SPRMOD;
            wrp = (FLASH_OB_getOPTCR() >> EFLASH_OPTCR_nWRP_S) &
                    ((1<<EFLASH_Sector_8) | (1<<EFLASH_Sector_9) | (1<<EFLASH_Sector_10) | (1<<EFLASH_Sector_11));
            if ((0 == sprmod && 0 == wrp) || ((EFLASH_OPTCR_SPRMOD == sprmod) &&
                    (((1<<EFLASH_Sector_8) | (1<<EFLASH_Sector_9) | (1<<EFLASH_Sector_10) | (1<<EFLASH_Sector_11)) == wrp)))
            {
                ret = Fapi_Error_FlashRegsNotWritable;
            }
            else
            {
                FLASH_eraseBank0();
            }
            FLASH_OB_lock();
            FLASH_lock();

        }
        else if (Fapi_FlashBank1 == iFlashBank)
        {
            //XFLASHC_chipErase(XFLASH_R_BASE);
        }
        else
        {
            ret = Fapi_Error_Fail;
        }
        break;
    case Fapi_ClearStatus:
        if (Fapi_FlashBank0 == iFlashBank)
        {
            FLASH_clearFlag(0x1F3);
        }
        else if (Fapi_FlashBank0 == iFlashBank)
        {
            //HWREG(XFLASHC_R_BASE + XFLASH_O_FLASH_SR) = 0x1F3;
        }
        else
        {
            ret = Fapi_Error_Fail;
        }
        break;
    default:
        ret = Fapi_Error_Fail;
        break;
    }
    return ret;
}

ILM_FUNC_T  Fapi_StatusType Fapi_issueAsyncCommand(Fapi_FlashBankType iFlashBank,Fapi_FlashStateCommandsType oCommand)
{
 Fapi_StatusType ret = Fapi_Status_Success;
 int sectorNum = 0;
 uint32_t sprmod = 0;
 uint32_t wrp = 0;

 switch (oCommand)
    {
    case Fapi_ProgramData:
    case Fapi_EraseSector:
        ret = Fapi_Error_Fail;
        break;
    case Fapi_EraseBank:
        if (Fapi_FlashBank0 == iFlashBank)
        {
            FLASH_unlock();
            FLASH_OB_unlock();
            sprmod = FLASH_OB_getOPTCR() & EFLASH_OPTCR_SPRMOD;
            wrp = (FLASH_OB_getOPTCR() >> EFLASH_OPTCR_nWRP_S) &
                    ((1<<EFLASH_Sector_8) | (1<<EFLASH_Sector_9) | (1<<EFLASH_Sector_10) | (1<<EFLASH_Sector_11));
            if ((0 == sprmod && 0 == wrp) || ((EFLASH_OPTCR_SPRMOD == sprmod) &&
                    (((1<<EFLASH_Sector_8) | (1<<EFLASH_Sector_9) | (1<<EFLASH_Sector_10) | (1<<EFLASH_Sector_11)) == wrp)))
            {
                ret = Fapi_Error_FlashRegsNotWritable;
            }
            else
            {
                FLASH_eraseBank0();
            }
            FLASH_OB_lock();
            FLASH_lock();
        }
        else if (Fapi_FlashBank1 == iFlashBank) //TODO
        {
        }
        else
        {
            ret = Fapi_Error_Fail;
        }
        break;
    case Fapi_ClearStatus:
        if (Fapi_FlashBank0 == iFlashBank)
        {
            FLASH_unlock();
            FLASH_clearFlag(0x1F3);
            FLASH_lock();
        }
        else if (Fapi_FlashBank0 == iFlashBank)
        {
            //HWREG(XFLASHC_R_BASE + XFLASH_O_FLASH_SR) = 0x1F3;
        }
        else
        {
            ret = Fapi_Error_Fail;
        }
        break;
    default:
        ret = Fapi_Error_Fail;
        break;
    }
	 return ret;
}

ILM_FUNC_T  Fapi_StatusType Fapi_issueBankEraseCommand(uint32 *pu32StartAddress)
{
	 Fapi_StatusType ret = Fapi_Status_Success;
	 uint32_t sprmod;
	 uint32_t wrp;
	 if ((uint32_t)pu32StartAddress == EFLASH_BASE)
	 {
	     FLASH_unlock();
         FLASH_OB_unlock();
         sprmod = FLASH_OB_getOPTCR() & EFLASH_OPTCR_SPRMOD;
         wrp = (FLASH_OB_getOPTCR() >> EFLASH_OPTCR_nWRP_S) &
                 ((1<<EFLASH_Sector_8) | (1<<EFLASH_Sector_9) | (1<<EFLASH_Sector_10) | (1<<EFLASH_Sector_11));
         if ((0 == sprmod && 0 == wrp) || ((EFLASH_OPTCR_SPRMOD == sprmod) &&
                 (((1<<EFLASH_Sector_8) | (1<<EFLASH_Sector_9) | (1<<EFLASH_Sector_10) | (1<<EFLASH_Sector_11)) == wrp)))
         {
             ret = Fapi_Error_FlashRegsNotWritable;
         }
		 else
        {
		     FLASH_eraseBank0();
        }
		 FLASH_OB_lock();
		 FLASH_lock();
	 }
	 else if ((uint32_t)pu32StartAddress == XFLASH_BASE)
	 {
		 //XFLASHC_chipErase(XFLASHC_R_BASE);
	 }
	 else
	 {
		 ret = Fapi_Error_Fail;
	 }
	 return ret;
}

/* Info Commands */
ILM_FUNC_T  Fapi_LibraryInfoType Fapi_getLibraryInfo(void)
{
	 Fapi_LibraryInfoType ret = {0};
	 return ret;
}

/* Init */
#define  FLASH_PHY_PARA   (24*1000*1000U)
ILM_FUNC_T  Fapi_StatusType Fapi_initializeAPI(
		                                 Fapi_FlashBankType iFlashBank,
		                                 Fapi_FmcRegistersType *poFlashControlRegister,
                                         uint32 u32HclkFrequency
                                         )
 {
	 uint32_t latency = 0;
	 Fapi_StatusType ret = Fapi_Status_Success;
	 if (Fapi_FlashBank0 == iFlashBank)
	 {
		 latency = (u32HclkFrequency / FLASH_PHY_PARA) & 0xFF;
		 latency = (latency > 7) ? 7 : latency;
		 FLASH_setLatency(latency);
	 }
	 else if (Fapi_FlashBank1 == iFlashBank)
	 {

	 }
	 else
	 {
		 ret = Fapi_Error_Fail;
	 }
	 return ret;
 }

/* Read commands */
ILM_FUNC_T  Fapi_StatusType Fapi_doBlankCheck(
		 	 	 	 	 	 	 	 	Fapi_FlashBankType iFlashBank,
                                        uint32 *pu32StartAddress,
                                        uint32 u32Length,
                                        Fapi_FlashStatusWordType *poFlashStatusWord
                                        )
 {
	 poFlashStatusWord->au32StatusWord[0] = 0;
	 poFlashStatusWord->au32StatusWord[1] = 0;
	 poFlashStatusWord->au32StatusWord[2] = 0;
	 poFlashStatusWord->au32StatusWord[3] = 0;
	 for(uint32 i = 0; i < u32Length; i=i+4)
	 {
		 if(pu32StartAddress[i] != 0xFFFFFFFF)
		 {
             return Fapi_Error_Fail;
		 }
	 }
	 return Fapi_Status_Success;
 }

ILM_FUNC_T  Fapi_StatusType Fapi_doVerify(
                                    uint32 *pu32StartAddress,
                                    uint32 u32Length,
                                    uint32 *pu32CheckValueBuffer,
                                    Fapi_FlashStatusWordType *poFlashStatusWord
                                    )
 {

	 poFlashStatusWord->au32StatusWord[0] = 0;
	 poFlashStatusWord->au32StatusWord[1] = 0;
	 poFlashStatusWord->au32StatusWord[2] = 0;
	 poFlashStatusWord->au32StatusWord[3] = 0;
	 for(uint32 i = 0; i < u32Length; i=i+4)
	 {
		 if(pu32StartAddress[i] != pu32CheckValueBuffer[i])
		 {
             return Fapi_Error_Fail;
		 }
	 }
	 return Fapi_Status_Success;
 }

ILM_FUNC_T  Fapi_StatusType Fapi_doVerifyBy16bits(
                             uint16 *pu16StartAddress,
                             uint32 u16Length,
                             uint16 *pu16CheckValueBuffer,
                             Fapi_FlashStatusWordType *poFlashStatusWord
                             )
 {
	 poFlashStatusWord->au32StatusWord[0] = 0;
	 poFlashStatusWord->au32StatusWord[1] = 0;
	 poFlashStatusWord->au32StatusWord[2] = 0;
	 poFlashStatusWord->au32StatusWord[3] = 0;
	 for(uint32 i = 0; i < u16Length; i=i+2)
	 {
		 if(pu16StartAddress[i] != pu16CheckValueBuffer[i])
		 {
             return Fapi_Error_Fail;
		 }
	 }
	 return Fapi_Status_Success;
 }


/* Programming Commands */
ILM_FUNC_T  Fapi_StatusType Fapi_issueProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32DataBuffer,
                                            uint32  u32DataBufferSizeInWords,
                                            uint32 *pu32EccBuffer,
                                            uint32  u32EccBufferSizeInBytes,
                                            Fapi_FlashProgrammingCommandsType oMode
                                            )
 {
	 Fapi_StatusType ret = Fapi_Status_Success;
	 uint8_t sectorNum;
	 uint32_t sprmod;
	 uint32_t wrp;

	 if (oMode == Fapi_AutoEccGeneration)
    {
        if (((uint32) pu32StartAddress >= EFLASH_BASE) && ((uint32) pu32StartAddress <= EFLASH_END))
        {
            sectorNum = (((uint32) pu32StartAddress - EFLASH_BASE) / FLASH_SECTOR_SIZE) + EFLASH_Sector_8;
            FLASH_unlock(); // FIXME
            FLASH_OB_unlock(); // FIXME
            sprmod = FLASH_OB_getOPTCR() & EFLASH_OPTCR_SPRMOD;
            wrp = (FLASH_OB_getOPTCR() >> EFLASH_OPTCR_nWRP_S) & (1 << (sectorNum));

            if ((0 == sprmod && 0 == wrp) || ((EFLASH_OPTCR_SPRMOD == sprmod) && ((1 << sectorNum) == wrp)))
            {
                ret = Fapi_Error_FlashRegsNotWritable;
            }
            else
            {
                if (u32DataBufferSizeInWords == 4)
                {
                    FLASH_program((uint8_t*) pu32DataBuffer, (uint32) pu32StartAddress, FLASH_PSIZE_WORD);
                }
                else if (u32DataBufferSizeInWords == 8)
                {
                    FLASH_program((uint8_t*) pu32DataBuffer, (uint32) pu32StartAddress, FLASH_PSIZE_TWOWORD);
                }
                else if (u32DataBufferSizeInWords == 16)
                {
                    FLASH_program((uint8_t*) pu32DataBuffer, (uint32) pu32StartAddress, FLASH_PSIZE_FOURWORD);
                }
                else
                {
                    ret = Fapi_Error_FlashRegsNotWritable;
                }
            }

            FLASH_OB_lock();
            FLASH_lock();
        }
        if (((uint32) pu32StartAddress >= XFLASH_BASE) && ((uint32) pu32StartAddress <= XFLASH_END)) //TODO
        {

        }
    }
	 else
	 {
		ret =  Fapi_Error_Fail;
	 }

	 return ret;
 }

ILM_FUNC_T Fapi_StatusType Fapi_issueDataOnly512ProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu16DataBuffer,
                                            uint32  u16DataBufferSizeInWords
                                            )
{
	return Fapi_Status_Success;
}

ILM_FUNC_T  Fapi_StatusType Fapi_issueAutoEcc512ProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32DataBuffer,
                                            uint32  u32DataBufferSizeInWords
                                            )
{
	return Fapi_Error_Fail;
}

ILM_FUNC_T  Fapi_StatusType Fapi_issueDataAndEcc512ProgrammingCommand(
                                            uint32 *pu32StartAddress,
                                            uint32 *pu32DataBuffer,
                                            uint32  u32DataBufferSizeInWords,
                                            uint32 *pu32EccBuffer,
                                            uint32  u32EccBufferSizeInBytes
                                            )
{
	return Fapi_Error_Fail;
}


ILM_FUNC_T  Fapi_StatusType Fapi_issueEccOnly64ProgrammingCommand(
                                             uint32 *pu32StartAddress,
                                             uint32 *pu32EccBuffer,
                                             uint32  u32EccBufferSizeInBytes
                                             )
{
	return Fapi_Error_Fail;
}

ILM_FUNC_T  Fapi_StatusType Fapi_issueProgrammingCommandForEccAddresses(
                                                           uint32 *pu32StartAddress,
                                                           uint32 *pu32EccBuffer,
                                                           uint32 u32EccBufferSizeInBytes
                                                           )
{
	return Fapi_Error_Fail;
}


/* Utility Commands */
ILM_FUNC_T  uint32 Fapi_calculateFletcherChecksum(
                                            uint32 const * pu16Data,
                                            uint32 u32Length
                                            )
{
	return Fapi_Error_Fail;
}

ILM_FUNC_T  uint8 Fapi_calculateEcc(
                               uint32 u32Address,
                               uint64 u64Data
                               )
{
	return Fapi_Error_Fail;
}

ILM_FUNC_T  Fapi_StatusType Fapi_configureFMAC(uint32 u32Address)
{
	return Fapi_Error_Fail;
}

ILM_FUNC_T  void Write_32bp(uint32 reg_offset, uint32 mask, uint32 shift, uint32 value)
{

}

ILM_FUNC_T  void Write_32(uint32 ctrlBase, uint32 reg_offset, uint32 mask, uint32 shift, uint32 value)
{

}
