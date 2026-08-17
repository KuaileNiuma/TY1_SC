 /** 
  ************************************************************************************* 
  * @file hw_ecap.h 
  * @brief This file contains the definition of hw_ecap driver. 
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

#ifndef HW_EFLASHC_H
#define HW_EFLASHC_H

#define EFLASH_O_ACR            (0x00U)
#define EFLASH_O_KEYR           (0x04U)
#define EFLASH_O_OPTKEYR        (0x08U)
#define EFLASH_O_SR             (0x0CU)
#define EFLASH_O_CR             (0x10U)
#define EFLASH_O_OPTCR          (0x14U)
#define EFLASH_O_PARAM1         (0x94U)
#define EFLASH_O_PARAM0         (0x98U)
#define EFLASH_O_TESTKEYR       (0x100U)
#define EFLASH_O_CDCADDR        (0x104U)
#define EFLASH_O_CDCCR          (0x108U)
#define EFLASH_O_DIN0           (0x10CU)
#define EFLASH_O_DIN1           (0x110U)
#define EFLASH_O_DIN2           (0x114U)
#define EFLASH_O_DIN3           (0x118U)
#define EFLASH_O_DO0            (0x11CU)
#define EFLASH_O_DO1            (0x120U)
#define EFLASH_O_DO2            (0x124U)
#define EFLASH_O_DO3            (0x128U)
#define EFLASH_O_BISTENDADDR    (0x20CU)
#define EFLASH_O_BISTCR         (0x210U)
#define EFLASH_O_BISTSR         (0x214U)

 /* Flash Access Control Register bits */
 #define EFLASH_ACR_LATENCY_M               ((uint32_t)0x00000007)
 #define EFLASH_ACR_LATENCY_S           ((uint32_t)0x00000000)
 #define EFLASH_ACR_PRFTEN                  ((uint32_t)0x00000100)
 #define EFLASH_ACR_ICEN                    ((uint32_t)0x00000200)
 #define EFLASH_ACR_DCEN                    ((uint32_t)0x00000400)
 #define EFLASH_ACR_ICRST               ((uint32_t)0x00000800)
 #define EFLASH_ACR_DCRST               ((uint32_t)0x00001000)
 #define EFLASH_ACR_PRF_RULE                ((uint32_t)0x00010000)

 /* Flash Key Register*/
 #define EFLASH_KEY1                    (0x45670123U)
 #define EFLASH_KEY2                    (0xCDEF89ABU)

 /* Flash Key Register*/
 #define EFLASH_OPTKEY1                 (0x08192A3BU)
 #define EFLASH_OPTKEY2                 (0x4C5D6E7FU)

 /* Flash Status Register bits */
 #define EFLASH_SR_EOP                      ((uint32_t)0x00000001)   /*!< FLASH End of Operation flag               */
 #define EFLASH_SR_OPERR                    ((uint32_t)0x00000002)   /*!< FLASH operation Error flag                */
 #define EFLASH_SR_WRPERR               ((uint32_t)0x00000010)   /*!< FLASH Write protected error flag          */
 #define EFLASH_SR_PGAERR                   ((uint32_t)0x00000020)   /*!< FLASH Programming Alignment error flag    */
 #define EFLASH_SR_PGPERR                   ((uint32_t)0x00000040)   /*!< FLASH Programming Parallelism error flag  */
 #define EFLASH_SR_PGSERR                   ((uint32_t)0x00000080)   /*!< FLASH Programming Sequence error flag     */
 #define EFLASH_SR_RDERR                    ((uint32_t)0x00000100)   /*!< Read Protection error flag (PCROP)        */
 #define EFLASH_SR_BSY                   ((uint32_t)0x000010000)   /*!< FLASH Operation busy flag */


 #define IS_FLASH_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFE0C) == 0x00000000) && ((FLAG) != 0x00000000))
 #define IS_FLASH_GET_FLAG(FLAG)  (((FLAG) == EFLASH_SR_EOP)    || ((FLAG) == EFLASH_SR_OPERR)  || \
                                   ((FLAG) == EFLASH_SR_WRPERR) || ((FLAG) == EFLASH_SR_PGAERR) || \
                                   ((FLAG) == EFLASH_SR_PGPERR) || ((FLAG) == EFLASH_SR_PGSERR) || \
                                   ((FLAG) == EFLASH_SR_BSY)    || ((FLAG) == EFLASH_SR_RDERR))

 /* Flash Control Register bits */
 #define EFLASH_CR_PG                ((uint32_t)0x00000001)
 #define EFLASH_CR_SER               ((uint32_t)0x00000002)
 #define EFLASH_CR_MER               ((uint32_t)0x00000004)
 #define EFLASH_CR_SNB_M                ((uint32_t)(0x07<<3))
 #define EFLASH_CR_SNB_S                ((uint32_t)3)
 #define EFLASH_CR_PSIZE_M              ((uint32_t)(0x07<<8))
 #define EFLASH_CR_PSIZE_S              ((uint32_t)8)
 #define EFLASH_CR_START                ((uint32_t)(0x01<<16))
 #define EFLASH_CR_EOPIE             ((uint32_t)(0x01<<24)) /*!< End of FLASH Operation Interrupt source */
 #define EFLASH_CR_ERRIE             ((uint32_t)(0x01<<25)) /*!< Error Interrupt source */
 #define EFLASH_CR_LOCK                 ((uint32_t)(0x01<<31))

 #define IS_FLASH_IT(IT) ((((IT) & (uint32_t)(~(EFLASH_CR_EOPIE_EN|EFLASH_CR_ERRIE_EN))0xFCFFFFFF) == 0x00000000) && ((IT) != 0x00000000))

 /* Flash option Control Register bits */
 #define EFLASH_OPTCR_OPTLOCK           ((uint32_t)(0x01<<0))
 #define EFLASH_OPTCR_OPTSTART          ((uint32_t)(0x01<<1))
 #define EFLASH_OPTCR_BOR_LEV_M         ((uint32_t)(0x03<<2))
 #define EFLASH_OPTCR_BOR_LEV_S         ((uint32_t)2)
 #define EFLASH_OPTCR_WDG_SW            ((uint32_t)(0x01<<5))
 #define EFLASH_OPTCR_nSRT_STOP         ((uint32_t)(0x01<<6))
 #define EFLASH_OPTCR_nSRT_STDBY        ((uint32_t)(0x01<<7))
 #define EFLASH_OPTCR_RDP_M             ((uint32_t)(0xFF<<8))
 #define EFLASH_OPTCR_RDP_S             ((uint32_t)8)
 #define EFLASH_OPTCR_nWRP_M            ((uint32_t)(0xFFF<<16))
 #define EFLASH_OPTCR_nWRP_S            ((uint32_t)16)
 #define EFLASH_OPTCR_SPRMOD            ((uint32_t)(0x01<<31))


 /* Flash Key Register*/
 #define EFLASH_CDCKEY1                 (0x20240916U)
 #define EFLASH_CDCKEY2                 (0x55aaaa55U)

/******************  Bit definition for FLASH_CDC_CR register  ******************/
#define  EFLASH_CDCCR_porb              ((uint32_t)(0x01<<0))
#define  EFLASH_CDCCR_web               ((uint32_t)(0x01<<1))
#define  EFLASH_CDCCR_ceb               ((uint32_t)(0x01<<2))
#define  EFLASH_CDCCR_tmen              ((uint32_t)(0x01<<3))
#define  EFLASH_CDCCR_vread0            ((uint32_t)(0x01<<4))
#define  EFLASH_CDCCR_vread1            ((uint32_t)(0x01<<5))
#define  EFLASH_CDCCR_recall            ((uint32_t)(0x01<<6))
#define  EFLASH_CDCCR_confen            ((uint32_t)(0x01<<7))
#define  EFLASH_CDCCR_chip              ((uint32_t)(0x01<<8))
#define  EFLASH_CDCCR_blok              ((uint32_t)(0x01<<9))
#define  EFLASH_CDCCR_erase             ((uint32_t)(0x01<<10))
#define  EFLASH_CDCCR_prog              ((uint32_t)(0x01<<11))
#define  EFLASH_CDCCR_prepg             ((uint32_t)(0x01<<12))
#define  EFLASH_CDCCR_prog2             ((uint32_t)(0x01<<13))
#define  EFLASH_CDCCR_epen              ((uint32_t)(0x01<<14))
#define  EFLASH_CDCCR_dpd               ((uint32_t)(0x01<<15))
#define  EFLASH_CDCCR_nvr_M             ((uint32_t)(0x0F<<16))
#define  EFLASH_CDCCR_arrdn             ((uint32_t)(0x01<<20))
#define  EFLASH_CDCCR_flash2mode        ((uint32_t)(0x01<<22))

/******************  Bit definition for FLASH_BIST_CR register  ******************/
#define  EFLASH_BISTCR_mode             ((uint32_t)(0x01<<0))
#define  EFLASH_BISTCR_direction        ((uint32_t)(0x01<<1))
#define  EFLASH_BISTCR_area_M           ((uint32_t)(0x03<<2))
#define  EFLASH_BISTCR_pattern_M        ((uint32_t)(0x03<<4))
#define  EFLASH_BISTCR_start            ((uint32_t)(0x01<<7))

/******************  Bit definition for FLASH_BIST_SR register  ******************/
#define  EFLASH_BISTSR_doneaddr_M       ((uint32_t)(0x7FFF<<0))
#define  EFLASH_BISTSR_fail             ((uint32_t)(0x01<<30))
#define  EFLASH_BISTSR_done             ((uint32_t)(0x01<<31))
 /** @defgroup Option_Bytes_Write_Protection
   * @{
   */
 #define EFLASH_OB_WRP_Sector_8         ((uint32_t)(1<<8)) /*!< Write protection of Sector8     */
 #define EFLASH_OB_WRP_Sector_9         ((uint32_t)(1<<9)) /*!< Write protection of Sector9     */
 #define EFLASH_OB_WRP_Sector_10        ((uint32_t)(1<<10)) /*!< Write protection of Sector10    */
 #define EFLASH_OB_WRP_Sector_11        ((uint32_t)(1<<11)) /*!< Write protection of Sector11    */

 #define IS_FLASH_OB_WRP(SECTOR)((((SECTOR) & (uint32_t)0xFFFFF0FF) == 0x00000000) && ((SECTOR) != 0x00000000))


 /** @defgroup FLASH_Option_Bytes_Read_Protection
   * @{
   */
 #define EFLASH_OB_RDP_Level_0   ((uint8_t)0xAA)
 #define EFLASH_OB_RDP_Level_1   ((uint8_t)0x55)
 #define EFLASH_OB_RDP_Level_2   ((uint8_t)0xCC) /*!< Warning: When enabling read protection level 2it's no more possible to go back to level 1 or 0 */
 
 #define IS_FLASH_OB_RDP(LEVEL) (((LEVEL) == EFLASH_OB_RDP_Level_0)||\
                           ((LEVEL) == EFLASH_OB_RDP_Level_1))||\
                           ((LEVEL) == EFLASH_OB_RDP_Level_2))


 /** @defgroup FLASH_Option_Bytes_IWatchdog
   * @{
   */
 #define OB_IWDG_SW                     ((uint8_t)0x20)  /*!< Software IWDG selected */
 #define OB_IWDG_HW                     ((uint8_t)0x00)  /*!< Hardware IWDG selected */
 #define IS_OB_IWDG_SOURCE(SOURCE) (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))
 /**
   * @}
   */

 /** @defgroup FLASH_Option_Bytes_nRST_STOP
   * @{
   */
 #define OB_STOP_NoRST                  ((uint8_t)0x40) /*!< No reset generated when entering in STOP */
 #define OB_STOP_RST                    ((uint8_t)0x00) /*!< Reset generated when entering in STOP */
 #define IS_OB_STOP_SOURCE(SOURCE) (((SOURCE) == OB_STOP_NoRST) || ((SOURCE) == OB_STOP_RST))
 /**
   * @}
   */


 /** @defgroup FLASH_Option_Bytes_nRST_STDBY
   * @{
   */
 #define OB_STDBY_NoRST                 ((uint8_t)0x80) /*!< No reset generated when entering in STANDBY */
 #define OB_STDBY_RST                   ((uint8_t)0x00) /*!< Reset generated when entering in STANDBY */
 #define IS_OB_STDBY_SOURCE(SOURCE) (((SOURCE) == OB_STDBY_NoRST) || ((SOURCE) == OB_STDBY_RST))


#define OB_BOR_LEVEL3 (0x00)
#define OB_BOR_LEVEL2 (0x04)
#define OB_BOR_LEVEL1 (0x08)
#define OB_BOR_OFF    (0x0C)
#define IS_OB_BOR(LEVEL)  (((LEVEL)==OB_BOR_LEVEL1) || ((LEVEL)==OB_BOR_LEVEL2) || \
                          ((LEVEL)==OB_BOR_LEVEL3) || ((LEVEL)==OB_BOR_OFF))

 /** @defgroup FLASH_Sectors
   * @{
   */
 #define EFLASH_Sector_8     ((uint16_t)8) /*!< Sector Number 8   */
 #define EFLASH_Sector_9     ((uint16_t)9) /*!< Sector Number 9   */
 #define EFLASH_Sector_10    ((uint16_t)10) /*!< Sector Number 10  */
 #define EFLASH_Sector_11    ((uint16_t)11) /*!< Sector Number 11  */


 #define IS_FLASH_SECTOR(SECTOR) (((SECTOR) == EFLASH_Sector_8)   || ((SECTOR) == EFLASH_Sector_9)   ||\
                                  ((SECTOR) == EFLASH_Sector_10)  || ((SECTOR) == EFLASH_Sector_11)  )

 /**
   * @brief   ACR register byte 0 (Bits[7:0]) base address
   */
 #define ACR_BYTE0_ADDRESS           ((uint32_t)(EFLASHC_R_BASE+00))
 /**
   * @brief   OPTCR register byte 0 (Bits[7:0]) base address
   */
 #define OPTCR_BYTE0_ADDRESS         ((uint32_t)(EFLASHC_R_BASE+0x14))
 /**
   * @brief   OPTCR register byte 1 (Bits[15:8]) base address
   */
 #define OPTCR_BYTE1_ADDRESS         ((uint32_t)(EFLASHC_R_BASE+0x15))
 /**
   * @brief   OPTCR register byte 2 (Bits[23:16]) base address
   */
 #define OPTCR_BYTE2_ADDRESS         ((uint32_t)(EFLASHC_R_BASE+0x16))
 /**
   * @brief   OPTCR register byte 3 (Bits[31:24]) base address
   */
 #define OPTCR_BYTE3_ADDRESS         ((uint32_t)(EFLASHC_R_BASE+0x17))

#endif

