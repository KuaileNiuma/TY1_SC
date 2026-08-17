/** 
  ************************************************************************************* 
  * @file hw_xflashc.h 
  * @brief This file contains the definition of hw_xflashc driver. 
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

#ifndef HW_XFLASHC_H_
#define HW_XFLASHC_H_

//*************************************************************************************************
//
// The following are defines for the XFLASHC register offsets
//
//*************************************************************************************************
#define XFLASHC_O_FLASH_KEYR           0x004U    // FLASH_CR Unlock Register
#define XFLASHC_O_FLASH_OPTKEYR        0x008U    // FLASH_OPTCR0 Unlock Register
#define XFLASHC_O_FLASH_SR             0x00CU    // FLASH Status Register
#define XFLASHC_O_FLASH_CR             0x010U    // FLASH Control Register
#define XFLASHC_O_FLASH_OPTCR0         0x014U    // FLASH Operation Byte Control Register 0
#define XFLASHC_O_FLASH_OPTCR1         0x018U    // FLASH Operation Byte Control Register 1
#define XFLASHC_O_FLASH_PECFGR         0x020U    // FLASH PageErase Config Register
#define XFLASHC_O_FLASH_PEKEYR         0x024U    // FLASH PageErase Unlock Register
#define XFLASHC_O_FLASH_CRCCR          0x090U    // FLASH CRC Config Register
#define XFLASHC_O_FLASH_CRCSAR         0x094U    // FLASH CRC Start-Address Register
#define XFLASHC_O_FLASH_CRCEAR         0x098U    // FLASH CRC End-Address Register
#define XFLASHC_O_FLASH_CRCDR          0x09CU    // FLASH CRC Result Register
#if XFLASHC_HW_VER == 0x01
#define XFLASHC_O_FLASH_OPTCR0_MIR     0x100U    // FLASH Operation Byte Control Register Mirror 0
#define XFLASHC_O_FLASH_OPTCR1_MIR     0x104U    // FLASH Operation Byte Control Register Mirror 1
#define XFLASHC_O_FLASH_OPTCR2  	   0x108U    // FLASH Operation Byte Control Register 2
#define XFLASHC_O_FLASH_OPTCR3  	   0x10CU    // FLASH Operation Byte Control Register 3
#define XFLASHC_O_FLASH_OPTCR4  	   0x110U    // FLASH Operation Byte Control Register 3
#endif
#define XFLASHC_O_FLASH_CKDIVR         0x380U    // FLASH QSPI Clock-DIV Config Register
#define XFLASHC_O_FLASH_SAMPLE_DELAY   0x384U    // FLASH QSPI Sample-Delay Config Register
#define XFLASHC_O_FLASH_FSLOCK         0x3E0U    // FLASH Function Safety Lock Register
#define XFLASHC_O_FLASH_FSCTRL         0x3E4U    // FLASH Function Safety Control Register
#define XFLASHC_O_FLASH_FSDATA         0x3E8U    // FLASH Function Safety Data Access Register
#define XFLASHC_O_FLASH_FSINFO         0x3ECU    // FLASH Function Safety Error INFO Register
#define XFLASHC_O_FLASH_PARAM1         0x3F8U    // FLASH Parameters Register
#define XFLASHC_O_FLASH_REV            0x3FCU    // FLASH Reversion Register

/* ========================================================================== */
/* ================                 XFLASHC                  ================ */
/* ========================================================================== */

/* XFLASHC register bit definitions */

/* ============================     FLASH_SR     ============================== */
#define FLASH_SR_BSY_S                   (16UL)
#define FLASH_SR_BSY_M                   (0x10000UL)

#define FLASH_SR_RDERR_S                 (8UL)
#define FLASH_SR_RDERR_M                 (0x100UL)

#define FLASH_SR_PGSERR_S                (7UL)
#define FLASH_SR_PGSERR_M                (0x80UL)

#define FLASH_SR_PGPERR_S                (6UL)
#define FLASH_SR_PGPERR_M                (0x40UL)

#define FLASH_SR_PGAERR_S                (5UL)
#define FLASH_SR_PGAERR_M                (0x20UL)

#define FLASH_SR_WRPERR_S                (4UL)
#define FLASH_SR_WRPERR_M                (0x10UL)

#define FLASH_SR_OPERR_S                 (1UL)
#define FLASH_SR_OPERR_M                 (0x2UL)

#define FLASH_SR_EOP_S                   (0UL)
#define FLASH_SR_EOP_M                   (0x1UL)
/* ============================     FLASH_CR     ============================== */
#define FLASH_CR_LOCK_S                  (31UL)
#define FLASH_CR_LOCK_M                  (0x80000000UL)

#define FLASH_CR_ERRIE_S                 (25UL)
#define FLASH_CR_ERRIE_M                 (0x2000000UL)

#define FLASH_CR_EOPIE_S                 (24UL)
#define FLASH_CR_EOPIE_M                 (0x1000000UL)

#define FLASH_CR_START_S                 (16UL)
#define FLASH_CR_START_M                 (0x10000UL)

#if XFLASHC_HW_VER == 0x01
#define FLASH_CR_SNB1_S                  (11UL)
#define FLASH_CR_SNB1_M                  (0x3800UL)
#endif

#define FLASH_CR_PSIZE_S                 (8UL)
#define FLASH_CR_PSIZE_M                 (0x700UL)

#if XFLASHC_HW_VER == 0x01
#define FLASH_CR_MER1_S                   (2UL)
#define FLASH_CR_MER1_M                   (0x4UL)
#endif

#if XFLASHC_HW_VER == 0x00
#define FLASH_CR_SNB_S                   (3UL)
#define FLASH_CR_SNB_M                   (0xF8UL)
#elif XFLASHC_HW_VER == 0x01
#define FLASH_CR_SNB0_S                  (3UL)
#define FLASH_CR_SNB0_M                  (0xF8UL)
#endif

#if XFLASHC_HW_VER == 0x00
#define FLASH_CR_MER_S                   (2UL)
#define FLASH_CR_MER_M                   (0x4UL)
#elif XFLASHC_HW_VER == 0x01
#define FLASH_CR_MER0_S                   (2UL)
#define FLASH_CR_MER0_M                   (0x4UL)
#endif

#define FLASH_CR_SER_S                   (1UL)
#define FLASH_CR_SER_M                   (0x2UL)

#define FLASH_CR_PG_S                    (0UL)
#define FLASH_CR_PG_M                    (0x1UL)
/* ============================     FLASH_OPTCR0     ============================== */
#define FLASH_OPTCR0_SPRMOD_S            (31UL)
#define FLASH_OPTCR0_SPRMOD_M            (0x80000000UL)

#define FLASH_OPTCR0_nWRP_S              (16UL)
#define FLASH_OPTCR0_nWRP_M              (0x3FFF0000UL)

#define FLASH_OPTCR0_RDP_S               (8UL)
#define FLASH_OPTCR0_RDP_M               (0xFF00UL)

#define FLASH_OPTCR0_nRST_STDBY_S        (7UL)
#define FLASH_OPTCR0_nRST_STDBY_M        (0x80UL)

#define FLASH_OPTCR0_nRST_STOP_S         (6UL)
#define FLASH_OPTCR0_nRST_STOP_M         (0x40UL)

#define FLASH_OPTCR0_WDG_SW_S            (5UL)
#define FLASH_OPTCR0_WDG_SW_M            (0x20UL)

#define FLASH_OPTCR0_BOR_LEV_S           (2UL)
#define FLASH_OPTCR0_BOR_LEV_M           (0xCUL)

#define FLASH_OPTCR0_OPTSTART_S          (1UL)
#define FLASH_OPTCR0_OPTSTART_M          (0x2UL)

#define FLASH_OPTCR0_OPTLOCK_S           (0UL)
#define FLASH_OPTCR0_OPTLOCK_M           (0x1UL)
/* ============================     FLASH_OPTCR1     ============================== */
#define FLASH_OPTCR1_nWRP_S              (0UL)
#define FLASH_OPTCR1_nWRP_M              (0xFFFFUL)
/* ============================     FLASH_PECFGR     ============================== */
#define FLASH_PECFGR_PE_EN_S             (31UL)
#define FLASH_PECFGR_PE_EN_M             (0x80000000UL)

#define FLASH_PECFGR_PE_ADDR_S           (0UL)
#define FLASH_PECFGR_PE_ADDR_M           (0x1FFFFFFFUL)
/* ============================      FLASH_CRCCR     ============================== */
#define FLASH_CRCCR_ALL_SECT_S           (22UL)
#define FLASH_CRCCR_ALL_SECT_M           (0x400000UL)

#define FLASH_CRCCR_CLEAN_CRC_S          (17UL)
#define FLASH_CRCCR_CLEAN_CRC_M          (0x20000UL)

#define FLASH_CRCCR_START_CRC_S          (16UL)
#define FLASH_CRCCR_START_CRC_M          (0x10000UL)

#define FLASH_CRCCR_ADD_SECT_S           (9UL)
#define FLASH_CRCCR_ADD_SECT_M           (0x200UL)

#define FLASH_CRCCR_CRC_BY_SECT_S        (8UL)
#define FLASH_CRCCR_CRC_BY_SECT_M        (0x100UL)

#define FLASH_CRCCR_SECT_S               (0UL)
#define FLASH_CRCCR_SECT_M               (0xFFUL)
/* ============================     FLASH_CRCSAR     ============================== */
#define FLASH_CRCSAR_CRC_START_ADDR_S    (2UL)
#define FLASH_CRCSAR_CRC_START_ADDR_M    (0x7FFFFFFCUL)
/* ============================     FLASH_CRCEAR     ============================== */
#define FLASH_CRCSAR_CRC_END_ADDR_S      (2UL)
#define FLASH_CRCSAR_CRC_END_ADDR_M      (0x7FFFFFFCUL)
/* ============================      FLASH_CRCDR     ============================== */
#define FLASH_CRCSAR_CRC_DATA_S          (0UL)
#define FLASH_CRCSAR_CRC_DATA_M          (0xFFFFFFFFUL)

#if XFLASHC_HW_VER == 0x01
/* ============================     FLASH_OPTCR0 Mirror    ============================== */
#define FLASH_OPTCR0_MIR_SPRMOD_S            (31UL)
#define FLASH_OPTCR0_MIR_SPRMOD_M            (0x80000000UL)

#define FLASH_OPTCR0_MIR_nWRP_S              (16UL)
#define FLASH_OPTCR0_MIR_nWRP_M              (0x3FFF0000UL)

#define FLASH_OPTCR0_MIR_RDP_S               (8UL)
#define FLASH_OPTCR0_MIR_RDP_M               (0xFF00UL)

#define FLASH_OPTCR0_MIR_nRST_STDBY_S        (7UL)
#define FLASH_OPTCR0_MIR_nRST_STDBY_M        (0x80UL)

#define FLASH_OPTCR0_MIR_nRST_STOP_S         (6UL)
#define FLASH_OPTCR0_MIR_nRST_STOP_M         (0x40UL)

#define FLASH_OPTCR0_MIR_WDG_SW_S            (5UL)
#define FLASH_OPTCR0_MIR_WDG_SW_M            (0x20UL)

#define FLASH_OPTCR0_MIR_BOR_LEV_S           (2UL)
#define FLASH_OPTCR0_MIR_BOR_LEV_M           (0xCUL)

#define FLASH_OPTCR0_MIR_OPTSTART_S          (1UL)
#define FLASH_OPTCR0_MIR_OPTSTART_M          (0x2UL)

#define FLASH_OPTCR0_MIR_OPTLOCK_S           (0UL)
#define FLASH_OPTCR0_MIR_OPTLOCK_M           (0x1UL)
/* ============================     FLASH_OPTCR1 Mirror    ============================== */
#define FLASH_OPTCR1_MIR_nWRP_S              (0UL)
#define FLASH_OPTCR1_MIR_nWRP_M              (0xFFFFUL)
/* ============================     FLASH_OPTCR2     ============================== */
#define FLASH_OPTCR2_nWRP_S              (0UL)
#define FLASH_OPTCR2_nWRP_M              (0xFFFFUL)
/* ============================     FLASH_OPTCR3     ============================== */
#define FLASH_OPTCR3_nWRP_S              (0UL)
#define FLASH_OPTCR3_nWRP_M              (0xFFFFUL)
/* ============================     FLASH_OPTCR4     ============================== */
#define FLASH_OPTCR4_nWRP_S              (0UL)
#define FLASH_OPTCR4_nWRP_M              (0xFFFFUL)
#endif

/* ============================     FLASH_CKDIVR     ============================== */
#define FLASH_CKDIVR_DIV_S               (1UL)
#define FLASH_CKDIVR_DIV_M               (0xFFFEUL)
/* ============================     FLASH_SAMPLE_DELAY     ============================== */
#define FLASH_SAMPLE_DELAY_SE_S          (16UL)
#define FLASH_SAMPLE_DELAY_SE_M          (0x10000UL)

#define FLASH_SAMPLE_DELAY_RSD_S         (0UL)
#define FLASH_SAMPLE_DELAY_RSD_M         (0xFFUL)
/* ============================     FLASH_FSCTRL     ============================== */
#define FLASH_FSCTRL_ID_S                (16UL)
#define FLASH_FSCTRL_ID_M                (0xFFFF0000UL)

#define FLASH_FSCTRL_TARGET_S            (8UL)
#define FLASH_FSCTRL_TARGET_M            (0xFF00UL)

#define FLASH_FSCTRL_ECC_OFF_S           (0UL)
#define FLASH_FSCTRL_ECC_OFF_M           (0x1UL)
/* ============================     FLASH_PARAM     ============================== */
#define FLASH_PARAM_SSIC_IO_MAP_EN_S     (16UL)
#define FLASH_PARAM_SSIC_IO_MAP_EN_M     (0x10000UL)

#define FLASH_PARAM_HAS_ECC_S            (8UL)
#define FLASH_PARAM_HAS_ECC_M            (0x100UL)

#define FLASH_PARAM_HAS_PARITY_S         (0UL)
#define FLASH_PARAM_HAS_PARITY_M         (0x1UL)
/* ============================     FLASH_REV     ============================== */
#define FLASH_REV_MAJ_S                  (16UL)
#define FLASH_REV_MAJ_M                  (0xFF0000UL)

#define FLASH_REV_MID_S                  (8UL)
#define FLASH_REV_MID_M                  (0xFF00UL)

#define FLASH_REV_MIN_S                  (0UL)
#define FLASH_REV_MIN_M                  (0xFFUL)

#endif /* _REG_XFLASHC_H_ */

