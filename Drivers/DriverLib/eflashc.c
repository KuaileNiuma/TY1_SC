/**
 *************************************************************************************
 * @file eflashc.c
 * @brief This file implements the function of eflashc driver.
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

#include "eflashc.h"

#ifdef IS_ALB32R003X
////*****************************************************************************
////
//// FLASH Access Control Register bits
////
////*****************************************************************************
//#define DMASCH_MCR_SYNC_M         ((uint32_t)0x00000007)   //!< FLASH Latency Mask
//#define FLASH_ACR_LATENCY_S         ((uint32_t)0x00000000)  //!< FLASH Latency Shift
//#define FLASH_ACR_PRF_RULE        ((uint32_t)0x00010000)        //!< FLASH Prefetch Rule
//
//
////*****************************************************************************
////
//// FLASH Flag Check Macros
////
////*****************************************************************************
//#define IS_FLASH_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFE0C) == 0x00000000) && ((FLAG) != 0x00000000))  //!< Check if FLASH flag can be cleared
//#define IS_FLASH_GET_FLAG(FLAG)  (((FLAG) == FLASH_SR_EOP)    || ((FLAG) == FLASH_SR_OPERR)  || \
//                                  ((FLAG) == FLASH_SR_WRPERR) || ((FLAG) == FLASH_SR_PGAERR) || \
//                                  ((FLAG) == FLASH_SR_PGPERR) || ((FLAG) == FLASH_SR_PGSERR) || \
//                                  ((FLAG) == FLASH_SR_BSY)    || ((FLAG) == FLASH_SR_RDERR))                  //!< Check if FLASH flag is valid
//
////*****************************************************************************
////
//// FLASH Control Register bits
////
////*****************************************************************************
//#define FLASH_CR_PG_EN        ((uint32_t)0x00000001)      //!< FLASH Programming Enable
//#define FLASH_CR_SER_EN       ((uint32_t)0x00000002)      //!< FLASH Sector Erase Enable
//#define FLASH_CR_MER_EN       ((uint32_t)0x00000004)      //!< FLASH Mass Erase Enable
//#define FLASH_CR_SNB_M     ((uint32_t)(0x07<<3))       //!< FLASH Sector Number Mask
//#define FLASH_CR_SNB_S     ((uint32_t)3)              //!< FLASH Sector Number Shift
//#define FLASH_CR_PSIZE_M    ((uint32_t)(0x07<<8))      //!< FLASH Program Size Mask
//#define FLASH_CR_PSIZE_S    ((uint32_t)8)             //!< FLASH Program Size Shift
//#define FLASH_CR_EOPIE_EN        ((uint32_t)(0x01<<24))   //!< End of FLASH Operation Interrupt source
//#define FLASH_CR_ERRIE_EN        ((uint32_t)(0x01<<25))   //!< Error Interrupt source
//
////*****************************************************************************
////
//// FLASH Interrupt Check Macro
////
////*****************************************************************************
//#define IS_FLASH_IT(IT) ((((IT) & (uint32_t)(~(EFLASH_CR_EOPIE_EN | EFLASH_CR_ERRIE_EN))0xFCFFFFFF) == 0x00000000) && ((IT) != 0x00000000))  //!< Check if FLASH interrupt is valid
//
////*****************************************************************************
////
//// FLASH Option Control Register bits
////
////*****************************************************************************
//#define FLASH_OPTCR_OPTSTART            ((uint32_t)(0x01<<1))       //!< FLASH Option Start
//#define FLASH_OPTCR_BOR_LEV_M        ((uint32_t)(0x03<<2))       //!< FLASH BOR Level Mask
//#define FLASH_OPTCR_BOR_LEV_S        ((uint32_t)2)              //!< FLASH BOR Level Shift
//#define FLASH_OPTCR_WDG_SW              ((uint32_t)(0x01<<5))       //!< FLASH Watchdog Software
//#define FLASH_OPTCR_nSRT_STOP           ((uint32_t)(0x01<<6))       //!< FLASH No Reset Stop Mode
//#define FLASH_OPTCR_nSRT_STDBY          ((uint32_t)(0x01<<7))       //!< FLASH No Reset Standby Mode
//#define FLASH_OPTCR_RDP_M            ((uint32_t)(0xFF<<8))       //!< FLASH Read Protection Mask
//#define FLASH_OPTCR_RDP_S            ((uint32_t)8)              //!< FLASH Read Protection Shift
//#define FLASH_OPTCR_nWRP_M           ((uint32_t)(0xFFF<<16))     //!< FLASH No Write Protection Mask
//#define FLASH_OPTCR_nWRP_S          ((uint32_t)16)              //!< FLASH No Write Protection Shift
//
////*****************************************************************************
////
//// Option Byte Configuration Macros
////
////*****************************************************************************
//#define FLASH_OB_WRP_Sector_8       ((uint32_t)(1<<8))  //!< Write protection of Sector8
//#define FLASH_OB_WRP_Sector_9       ((uint32_t)(1<<9))  //!< Write protection of Sector9
//#define FLASH_OB_WRP_Sector_10      ((uint32_t)(1<<10))  //!< Write protection of Sector10
//#define FLASH_OB_WRP_Sector_11      ((uint32_t)(1<<11))  //!< Write protection of Sector11
//
//#define IS_FLASH_OB_WRP(SECTOR)((((SECTOR) & (uint32_t)0xFFFFF0FF) == 0x00000000) && ((SECTOR) != 0x00000000))  //!< Check if FLASH option bytes write protection is valid
//
////*****************************************************************************
////
//// FLASH_Option_Bytes_Read_Protection
////
////*****************************************************************************
//#define FLASH_OB_RDP_Level_0   ((uint8_t)0xAA)  //!< FLASH Read Protection Level 0
//#define FLASH_OB_RDP_Level_1   ((uint8_t)0x55)  //!< FLASH Read Protection Level 1
//#define FLASH_OB_RDP_Level_2   ((uint8_t)0xCC)  //!< FLASH Read Protection Level 2 (Warning: When enabling read protection level 2, it's no more possible to go back to level 1 or 0)
//
////*****************************************************************************
////
//// FLASH_Option_Bytes_IWatchdog
////
////*****************************************************************************
//#define OB_IWDG_SW                     ((uint8_t)0x20)  //!< Software IWDG selected
//#define OB_IWDG_HW                     ((uint8_t)0x00)  //!< Hardware IWDG selected
//#define IS_OB_IWDG_SOURCE(SOURCE) (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))  //!< Check if IWDG source is valid
//
////*****************************************************************************
////
//// FLASH_Option_Bytes_nRST_STOP
////
////*****************************************************************************
//#define OB_STOP_NoRST                  ((uint8_t)0x40)  //!< No reset generated when entering in STOP
//#define OB_STOP_RST                    ((uint8_t)0x00)  //!< Reset generated when entering in STOP
//#define IS_OB_STOP_SOURCE(SOURCE) (((SOURCE) == OB_STOP_NoRST) || ((SOURCE) == OB_STOP_RST))  //!< Check if STOP source is valid


//*****************************************************************************
//
// FLASH_setLatency
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_setLatency(uint32_t FLASH_Latency)
{
    HWREG((uint32_t)(EFLASHC_R_BASE + EFLASH_O_ACR)) =
            (HWREG((uint32_t)(EFLASHC_R_BASE + EFLASH_O_ACR)) & ~(0xFF))
                    | (FLASH_Latency & 0xFF);
}

#define FREQ_24M          24000000

ILM_FUNC_T void
Flash_matchLatency(uint32_t sys_clock)
{
    // Flash read latency configuration
    if(sys_clock < FREQ_24M)
    {
        FLASH_setLatency(0);
    }
    else if(sys_clock < (FREQ_24M * 2))
    {
        FLASH_setLatency(1);
    }
    else if(sys_clock < (FREQ_24M * 3))
    {
        FLASH_setLatency(2);
    }
    else if(sys_clock < (FREQ_24M * 4))
    {
        FLASH_setLatency(3);
    }
    else if(sys_clock < (FREQ_24M * 5))
    {
        FLASH_setLatency(4);
    }
    else if(sys_clock < (FREQ_24M * 6))
    {
        FLASH_setLatency(5);
    }
    else if(sys_clock < (FREQ_24M * 7))
    {
        FLASH_setLatency(6);
    }
    else
    {
        FLASH_setLatency(7);  // max is 7
    }
}

//*****************************************************************************
//
// FLASH_setPrefetchEn
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_setPrefetchEn(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        //
        // Enable Prefetch
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) |= EFLASH_ACR_PRFTEN;
    }
    else
    {
        //
        // Disable Prefetch
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) &= ~EFLASH_ACR_PRFTEN;
    }
}

//*****************************************************************************
//
// FLASH_setIcacheEn
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_setIcacheEn(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        //
        // Enable icache
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) |= EFLASH_ACR_ICEN;
    }
    else
    {
        //
        // Disable icache
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) &= ~EFLASH_ACR_ICEN;
    }
}

//*****************************************************************************
//
// FLASH_setDcacheEn
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_setDcacheEn(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        //
        // Enable dcache
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) |= EFLASH_ACR_DCEN;
    }
    else
    {
        //
        // Disable dcache
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) &= ~EFLASH_ACR_DCEN;
    }
}


//*****************************************************************************
//
// FLASH_resetIcahe
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_resetIcahe(void)
{
    if((HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) & EFLASH_ACR_ICEN) == 0)
    {
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) |= EFLASH_ACR_ICRST;
    }
}

//*****************************************************************************
//
// FLASH_resetDcahe
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_resetDcahe(void)
{
    if((HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) & EFLASH_ACR_DCEN) == 0)
    {
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) |= EFLASH_ACR_DCRST;
    }
}

//*****************************************************************************
//
// FLASH_setPrefetchMode
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_setPrefetchMode(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        //
        // Enable Prefetch Rule
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) |= EFLASH_ACR_PRF_RULE;
    }
    else
    {
        //
        // Disable Prefetch Rule
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_ACR) &= ~EFLASH_ACR_PRF_RULE;
    }
}
//*****************************************************************************
//
// FLASH_unlock
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_unlock(void)
{
    if((HWREG(EFLASHC_R_BASE + EFLASH_O_CR) & EFLASH_CR_LOCK) != RESET)
    {
        HWREG(EFLASHC_R_BASE + EFLASH_O_KEYR) = EFLASH_KEY1;
        HWREG(EFLASHC_R_BASE + EFLASH_O_KEYR) = EFLASH_KEY2;
    }
}

//*****************************************************************************
//
// FLASH_lock
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_lock(void)
{
    //
    // Set the Lock Bit to lock the FPEC and the CR of Bank1
    //
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= EFLASH_CR_LOCK;
}

//*****************************************************************************
//
// FLASH_readUnlock
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_readUnlock(void)
{
    HWREG(EFLASHC_R_BASE + EFLASH_O_OPTCR) = 0x0FFFAAEC;
    HWREG(EFLASHC_R_BASE + EFLASH_O_OPTCR) = 0x0FFFAAEE;
}

//*****************************************************************************
//
// FLASH_busy
//
//*****************************************************************************
ILM_FUNC_T uint32_t
FLASH_busy(void)
{
    return (HWREG(EFLASHC_R_BASE + EFLASH_O_SR) & EFLASH_SR_BSY);
}

//*****************************************************************************
//
// FLASH_eraseSector
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_eraseSector(uint16_t Sector_Num)
{
    uint16_t FLASH_Sector = Sector_Num;
    ASSERT(IS_FLASH_SECTOR(FLASH_Sector));
    while(FLASH_busy());
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) &= ~EFLASH_CR_SNB_M;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= ((Sector_Num << EFLASH_CR_SNB_S) | EFLASH_CR_SER);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= EFLASH_CR_START;
    while(FLASH_busy());
    return;
}

//*****************************************************************************
//
// FLASH_mainSector
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_eraseBank0(void)
{
    while(FLASH_busy());
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= EFLASH_CR_MER;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= EFLASH_CR_START;
    while(FLASH_busy());
    return;
}



//*****************************************************************************
//
// FLASH_program
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_program(uint8_t *pdata, uint32_t address, FLASH_PSIZE psize)
{
    while(FLASH_busy());
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= EFLASH_CR_PG;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) &= ~EFLASH_CR_PSIZE_M;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= (psize << EFLASH_CR_PSIZE_S);
    if (FLASH_PSIZE_BYTE == psize)
    {
      *(uint8_t *)(address) = *pdata;
    }
    if (FLASH_PSIZE_HARFWORD == psize)
    {
      *(uint16_t *)(address) = *(uint16_t *)pdata;
    }
    if (FLASH_PSIZE_WORD == psize)
    {
      *(uint32_t *)(address) = *(uint32_t *)pdata;
    }
    if (FLASH_PSIZE_TWOWORD == psize)
    {
      *(uint32_t *)(address) = *(uint32_t *)pdata;
      *(uint32_t *)(address+4) = *(uint32_t *)(pdata+4);
    }
    if (FLASH_PSIZE_FOURWORD == psize)
    {
      *(uint32_t *)(address) = *(uint32_t *)pdata;
      *(uint32_t *)(address + 4) = *(uint32_t *)(pdata + 4);
      *(uint32_t *)(address + 8) = *(uint32_t *)(pdata + 8);
      *(uint32_t *)(address + 12) = *(uint32_t *)(pdata + 12);
    }
    while(FLASH_busy());
    return;
}

//*****************************************************************************
//
// FLASH_readBuff
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_readBuff(uint8_t *buffer, uint32_t address, uint32_t count)
{
    for(int i=0; i<count/4; i++)
    {
      *(uint32_t *)(buffer+i*4) = *(volatile uint32_t*)(address+i*4);
    }

    if(count%4)
    {
        for(int i=0; i<count%4; i++)
        {
          *(uint8_t *)(buffer+count/4*4+i) = *(volatile uint8_t*)(address+count/4*4+i) ;
        }
    }
    return;
}
//*****************************************************************************
//
// flash_writeBuff
//
//*****************************************************************************
ILM_FUNC_T void
flash_writeBuff(uint8_t* buffer, uint32_t address, uint32_t count)
{
    while(FLASH_busy());
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= EFLASH_CR_PG;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) &= ~EFLASH_CR_PSIZE_M;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= (FLASH_PSIZE_WORD << EFLASH_CR_PSIZE_S);
    for(int i=0; i<count/4; i++)
    {
      *(volatile uint32_t*)(address+i*4) = *(uint32_t *)(buffer+i*4);
        while(FLASH_busy());
    }

    if(count%4)
    {
        HWREG(EFLASHC_R_BASE + EFLASH_O_CR) &= ~EFLASH_CR_PSIZE_M;
        HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= (FLASH_PSIZE_BYTE << EFLASH_CR_PSIZE_S);
        for(int i=0; i<count%4; i++)
        {
          *(volatile uint8_t*)(address+count/4*4+i) = *(uint8_t *)(buffer+count/4*4+i);
            while(FLASH_busy());
        }
    }
    return;
}

//*****************************************************************************
//
// FLASH_itConfig
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_itConfig(uint32_t FLASH_IT, FunctionalState NewState)
{
    //
    // Check the parameters
    //
    ASSERT(IS_FLASH_IT(FLASH_IT));


    if(NewState != DISABLE)
    {
        //
        // Enable the interrupt sources
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= FLASH_IT;
    }
    else
    {
        //
        // Disable the interrupt sources
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_CR) &= ~(uint32_t)FLASH_IT;
    }
}

//*****************************************************************************
//
// FLASH_getFlagStatus
//
//*****************************************************************************
ILM_FUNC_T FlagStatus
FLASH_getFlagStatus(uint32_t FLASH_FLAG)
{
    FlagStatus bitstatus = RESET;
    //
    // Check the parameters
    //
    ASSERT(IS_FLASH_GET_FLAG(FLASH_FLAG));

    if((HWREG(EFLASHC_R_BASE + EFLASH_O_SR) & FLASH_FLAG) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    //
    // Return the new state of FLASH_FLAG (SET or RESET)
    //
    return bitstatus;
}


//*****************************************************************************
//
// FLASH_clearFlag
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_clearFlag(uint32_t FLASH_FLAG)
{
    //
    // Check the parameters
    //
    ASSERT(IS_FLASH_CLEAR_FLAG(FLASH_FLAG));

    //
    // Clear the flags
    //
    HWREG(EFLASHC_R_BASE + EFLASH_O_SR) = FLASH_FLAG;
}

//*****************************************************************************
//
// FLASH_getStatus
//
//*****************************************************************************
ILM_FUNC_T uint32_t
FLASH_getStatus(void)
{
    return HWREG(EFLASHC_R_BASE + EFLASH_O_SR);
}

//*****************************************************************************
//
// FLASH_OB_unlock
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_unlock(void)
{
    if((HWREG(EFLASHC_R_BASE + EFLASH_O_OPTCR) & EFLASH_OPTCR_OPTLOCK) != RESET)
    {
        //
        // Authorizes the Option Byte register programming
        //
        HWREG(EFLASHC_R_BASE + EFLASH_O_OPTKEYR) = EFLASH_OPTKEY1;
        HWREG(EFLASHC_R_BASE + EFLASH_O_OPTKEYR) = EFLASH_OPTKEY2;
    }
}

//*****************************************************************************
//
// FLASH_OB_lock
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_lock(void)
{
    //
    // Set the OPTLOCK Bit to lock the FLASH Option Byte Registers access
    //
    HWREG(EFLASHC_R_BASE + EFLASH_O_OPTCR) |= EFLASH_OPTCR_OPTLOCK;
}


//*****************************************************************************
//
// FLASH_OB_WRPconfig
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_WRPconfig(uint32_t OB_WRP, FunctionalState NewState)
{

    //
    // Check the parameters
    //
    ASSERT(IS_FLASH_OB_WRP(OB_WRP));
    ASSERT(IS_FUNCTIONAL_STATE(NewState));

    while(FLASH_busy());

    if(NewState != DISABLE)
    {
      *(__IO uint16_t*)OPTCR_BYTE2_ADDRESS &= (~OB_WRP);
    }
    else
    {
      *(__IO uint16_t*)OPTCR_BYTE2_ADDRESS |= (uint16_t)OB_WRP;
    }

}


//*****************************************************************************
//
// FLASH_OB_PCROPenable
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_PCROPenable(FunctionalState NewState)
{
    while(FLASH_busy());
    if(NewState != DISABLE)
    {
        HWREG(EFLASHC_R_BASE + EFLASH_O_OPTCR) &= (~EFLASH_OPTCR_SPRMOD);
    }
    else
    {
        HWREG(EFLASHC_R_BASE + EFLASH_O_OPTCR) |= EFLASH_OPTCR_SPRMOD;
    }
}

//*****************************************************************************
//
// FLASH_OB_RDPconfig
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_RDPconfig(uint32_t OB_RDP)
{
    //
    // Check the parameters
    //
    ASSERT(IS_FLASH_OB_RDP(OB_WRP));
    while(FLASH_busy());
    *(__IO uint8_t*)OPTCR_BYTE1_ADDRESS = OB_RDP;
}

//*****************************************************************************
//
// FLASH_OB_userConfig
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_userConfig(uint8_t OB_IWDG, uint8_t OB_STOP, uint8_t OB_STDBY)
{
    uint8_t optiontmp = 0xFF;

    //
    // Check the parameters
    //
    ASSERT(IS_OB_IWDG_SOURCE(OB_IWDG));
    ASSERT(IS_OB_STOP_SOURCE(OB_STOP));
    ASSERT(IS_OB_STDBY_SOURCE(OB_STDBY));

    while(FLASH_busy());

    optiontmp = (uint8_t)((*(__IO uint8_t *)OPTCR_BYTE0_ADDRESS) & (uint8_t)0x0F);

    //
    // Update User Option Byte
    //
    *(__IO uint8_t *)OPTCR_BYTE0_ADDRESS = OB_IWDG | OB_STDBY | OB_STOP | optiontmp;
}

//*****************************************************************************
//
// FLASH_OB_BORconfig
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_BORconfig(uint8_t OB_BOR)
{

    //
    // Check the parameters
    //
    ASSERT(IS_OB_BOR(OB_BOR));
    while(FLASH_busy());

    //
    // Set the BOR Level
    //
    *(__IO uint8_t *)OPTCR_BYTE0_ADDRESS &= (~EFLASH_OPTCR_BOR_LEV_M);
    *(__IO uint8_t *)OPTCR_BYTE0_ADDRESS |= OB_BOR;
}

//*****************************************************************************
//
// FLASH_OB_getUser
//
//*****************************************************************************
ILM_FUNC_T uint8_t
FLASH_OB_getUser(void)
{
    //
    // Return the User Option Byte
    //
    return (uint8_t)(HWREG(EFLASHC_R_BASE + EFLASH_O_OPTCR) >> 5);
}

//*****************************************************************************
//
// FLASH_OB_getRDP
//
//*****************************************************************************
ILM_FUNC_T FlagStatus
FLASH_OB_getRDP(void)
{
    FlagStatus readstatus = RESET;
    if(*(__IO uint8_t *)(OPTCR_BYTE1_ADDRESS) != (uint8_t) EFLASH_OB_RDP_Level_0)
    {
        readstatus = SET;
    }
    return readstatus;
}
//*****************************************************************************
//
// FLASH_OB_getWRP
//
//*****************************************************************************
ILM_FUNC_T uint16_t
FLASH_OB_getWRP(void)
{
    //
    // Return the FLASH write protection Register value
    //
    return (*(__IO uint16_t *)(OPTCR_BYTE2_ADDRESS));
}

//*****************************************************************************
//
// FLASH_OB_getBOR
//
//*****************************************************************************
ILM_FUNC_T uint8_t
FLASH_OB_getBOR(void)
{
    //
    // Return the Flash BOR level
    //
    return (*(__IO uint16_t *)(OPTCR_BYTE0_ADDRESS)) & 0x0C;
}

//*****************************************************************************
//
// FLASH_OB_getOPTCR
//
//*****************************************************************************
ILM_FUNC_T uint32_t
FLASH_OB_getOPTCR(void)
{
    //
    // Return the FLASH PC Read/write protection Register value
    //
    return (*(__IO uint32_t *)(EFLASHC_R_BASE + EFLASH_O_OPTCR));
}
//*****************************************************************************
//
// FLASH_OB_getPCROP
//
//*****************************************************************************
uint16_t
FLASH_OB_getPCROP(void)
{
    //
    // Return the FLASH PC Read/write protection Register value
    //
    return (*(__IO uint16_t *)(OPTCR_BYTE2_ADDRESS));
}

//*****************************************************************************
//
// FLASH_OB_launch
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_OB_launch(void)
{
    //
    // Set the OPTSTRT bit in OPTCR register
    //
    *(__IO uint8_t *)OPTCR_BYTE0_ADDRESS |= EFLASH_OPTCR_OPTSTART;

    while(FLASH_busy());
}

//*****************************************************************************
//
// FLASH_CDC_unlock
//
//*****************************************************************************
ILM_FUNC_T void
FLASH_CDC_unlock(void)
{
    //
    // Authorizes the CDC register programming
    //
    HWREG(EFLASHC_R_BASE + EFLASH_O_TESTKEYR) = EFLASH_CDCKEY1;
    HWREG(EFLASHC_R_BASE + EFLASH_O_TESTKEYR) = EFLASH_CDCKEY2;

}

ILM_FUNC_T void
FLASH_CDC_erase (uint32_t arrdn, uint32_t nvr, uint16_t address){
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = 0x400003;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_nvr_M )) | nvr;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_arrdn )) | arrdn;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCADDR) = address;

    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_epen)) | EFLASH_CDCCR_epen;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_erase)) | EFLASH_CDCCR_erase;
    delay_ms(1);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_web));
    delay_ms(4);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_web)) | EFLASH_CDCCR_web;
    delay_ms(1);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_epen));
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_erase));
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_ceb)) | EFLASH_CDCCR_ceb;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = 0x3;
}

ILM_FUNC_T void
FLASH_OTP_CDCerase (void){
    uint32_t address = 0x6000;
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 32; i++) {
            FLASH_CDC_erase(0, 0x80000, address);
            address++;
        }
    }
}


ILM_FUNC_T void
FLASH_OTP_program (uint8_t *pdata, uint32_t address, FLASH_PSIZE psize){
    while(FLASH_busy());
    if ((address < 0x1fff7800) || (address >= 0x1fff7a00)) return;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= EFLASH_CR_PG;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) &= ~EFLASH_CR_PSIZE_M;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CR) |= (psize << EFLASH_CR_PSIZE_S);
    if (FLASH_PSIZE_BYTE == psize)
    {
      *(uint8_t *)(address) = *pdata;
    }
    if (FLASH_PSIZE_HARFWORD == psize)
    {
      *(uint16_t *)(address) = *(uint16_t *)pdata;
    }
    if (FLASH_PSIZE_WORD == psize)
    {
      *(uint32_t *)(address) = *(uint32_t *)pdata;
    }
    if (FLASH_PSIZE_TWOWORD == psize)
    {
      *(uint32_t *)(address) = *(uint32_t *)pdata;
      *(uint32_t *)(address+4) = *(uint32_t *)(pdata+4);
    }
    if (FLASH_PSIZE_FOURWORD == psize)
    {
      *(uint32_t *)(address) = *(uint32_t *)pdata;
      *(uint32_t *)(address + 4) = *(uint32_t *)(pdata + 4);
      *(uint32_t *)(address + 8) = *(uint32_t *)(pdata + 8);
      *(uint32_t *)(address + 12) = *(uint32_t *)(pdata + 12);
    }
    while(FLASH_busy());
}


ILM_FUNC_T void
FLASH_CDC_program (uint32_t arrdn, uint32_t nvr, uint32_t address, uint32_t DIN0,
        uint32_t DIN1, uint32_t DIN2, uint32_t DIN3){
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = 0x400003;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_nvr_M )) | nvr;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_arrdn )) | arrdn;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCADDR) = address;

    HWREG(EFLASHC_R_BASE + EFLASH_O_DIN0) = DIN0;
    HWREG(EFLASHC_R_BASE + EFLASH_O_DIN1) = DIN1;
    HWREG(EFLASHC_R_BASE + EFLASH_O_DIN2) = DIN2;
    HWREG(EFLASHC_R_BASE + EFLASH_O_DIN3) = DIN3;

    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_epen)) | EFLASH_CDCCR_epen;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_prepg)) | EFLASH_CDCCR_prepg;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_prog)) | EFLASH_CDCCR_prog;
    delay_ms(1);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_web));
    delay_ms(4);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_prog2)) | EFLASH_CDCCR_prog2;
    delay_ms(1);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_prog2);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_prepg);
    delay_ms(3);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_prog2)) | EFLASH_CDCCR_prog2;
    delay_ms(3);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_prog2);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = (HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) & ~(EFLASH_CDCCR_web)) | EFLASH_CDCCR_web;
    delay_ms(3);
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = 0x400003 | nvr;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = 0x400007 | nvr;
    HWREG(EFLASHC_R_BASE + EFLASH_O_CDCCR) = 0x3;
}

#endif // IS_ALB32R003X

