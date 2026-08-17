/**
  *************************************************************************************
  * @file xflashc.h
  * @brief This file contains the definition of xflashc driver.
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

#ifndef _XFLASHC_H_
#define _XFLASHC_H_

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

#include "hw_xflashc.h"
#include "qspi.h"
#include "sysctl.h"


//*****************************************************************************
//
// XFLASHC Register Map
//
//*****************************************************************************
#if XFLASHC_HW_VER == 0x00
typedef struct
{
    uint32_t RESERVED;                  //!< Reserved                             (offset = 0x000)
    __IOM uint32_t FLASH_KEYR;          //!< FLASH_CR Unlock Register             (offset = 0x004)
    __IOM uint32_t FLASH_OPTKEYR;       //!< FLASH_OPTCR0 Unlock Register         (offset = 0x008)
    __IOM uint32_t FLASH_SR;            //!< FLASH Status Register                (offset = 0x00C)
    __IOM uint32_t FLASH_CR;            //!< FLASH Control Register               (offset = 0x010)
    __IOM uint32_t FLASH_OPTCR0;        //!< FLASH Operation Byte Control Register 0 (offset = 0x014)
    __IOM uint32_t FLASH_OPTCR1;        //!< FLASH Operation Byte Control Register 1 (offset = 0x018)
    uint32_t RESERVED0;                 //!< Reserved                             (offset = 0x01C)
    __IOM uint32_t FLASH_PECFGR;        //!< FLASH PageErase Config Register      (offset = 0x020)
    __IOM uint32_t FLASH_PEKEYR;        //!< FLASH PageErase Unlock Register      (offset = 0x024)
    uint32_t RESERVED1[26];             //!< Reserved                             (offset = 0x028-0x08C)
    __IOM uint32_t FLASH_CRCCR;         //!< FLASH CRC Config Register            (offset = 0x090)
    __IOM uint32_t FLASH_CRCSAR;        //!< FLASH CRC Start-Address Register     (offset = 0x094)
    __IOM uint32_t FLASH_CRCEAR;        //!< FLASH CRC End-Address Register       (offset = 0x098)
    __IOM uint32_t FLASH_CRCDR;         //!< FLASH CRC Result Register            (offset = 0x09C)
    uint32_t RESERVED2[184];            //!< Reserved                             (offset = 0x0A0)
    __IOM uint32_t FLASH_CKDIVR;        //!< FLASH QSPI Clock-DIV Config Register (offset = 0x380)
    __IOM uint32_t FLASH_SAMPLE_DELAY;  //!< FLASH QSPI Sample-Delay Config Register (offset = 0x384)
    uint32_t RESERVED3[22];             //!< Reserved                             (offset = 0x388)
    __IOM uint32_t FLASH_FSLOCK;        //!< FLASH Function Safety Lock Register  (offset = 0x3E0)
    __IOM uint32_t FLASH_FSCTRL;        //!< FLASH Function Safety Control Register (offset = 0x3E4)
    __IOM uint32_t FLASH_FSDATA;        //!< FLASH Function Safety Data Access Register (offset = 0x3E8)
    __IOM uint32_t FLASH_FSINFO;        //!< FLASH Function Safety Error INFO Register (offset = 0x3EC)
    uint32_t RESERVED4[2];              //!< Reserved                             (offset = 0x3F0)
    __IOM uint32_t FLASH_PARAM1;        //!< FLASH Parameters Register            (offset = 0x3F8)
    __IOM uint32_t FLASH_REV;           //!< FLASH Revision Register              (offset = 0x3FC)

}XFLASHC_TypeDef;
#elif XFLASHC_HW_VER == 0x01
typedef struct
{
    uint32_t RESERVED;                  //!< Reserved                             (offset = 0x000)
    __IOM uint32_t FLASH_KEYR;          //!< FLASH_CR Unlock Register             (offset = 0x004)
    __IOM uint32_t FLASH_OPTKEYR;       //!< FLASH_OPTCR0 Unlock Register         (offset = 0x008)
    __IOM uint32_t FLASH_SR;            //!< FLASH Status Register                (offset = 0x00C)
    __IOM uint32_t FLASH_CR;            //!< FLASH Control Register               (offset = 0x010)
    __IOM uint32_t FLASH_OPTCR0;        //!< FLASH Operation Byte Control Register 0 (offset = 0x014)
    __IOM uint32_t FLASH_OPTCR1;        //!< FLASH Operation Byte Control Register 1 (offset = 0x018)
    uint32_t RESERVED0;                 //!< Reserved                             (offset = 0x01C)
    __IOM uint32_t FLASH_PECFGR;        //!< FLASH PageErase Config Register      (offset = 0x020)
    __IOM uint32_t FLASH_PEKEYR;        //!< FLASH PageErase Unlock Register      (offset = 0x024)
    uint32_t RESERVED1[26];             //!< Reserved                             (offset = 0x028-0x08C)
    __IOM uint32_t FLASH_CRCCR;         //!< FLASH CRC Config Register            (offset = 0x090)
    __IOM uint32_t FLASH_CRCSAR;        //!< FLASH CRC Start-Address Register     (offset = 0x094)
    __IOM uint32_t FLASH_CRCEAR;        //!< FLASH CRC End-Address Register       (offset = 0x098)
    __IOM uint32_t FLASH_CRCDR;         //!< FLASH CRC Result Register            (offset = 0x09C)
    uint32_t RESERVED2[24];             //!< Reserved                             (offset = 0x0A0-0xFC)
    __IOM uint32_t FLASH_OPTCR0_M;      //!< FLASH Operation Byte Control Mirror Register 0 (offset = 0x100)
    __IOM uint32_t FLASH_OPTCR1_M;      //!< FLASH Operation Byte Control Mirror Register 1 (offset = 0x104)
    __IOM uint32_t FLASH_OPTCR2;		//!< FLASH Operation Byte Control Register 2 (offset = 0x108)
    __IOM uint32_t FLASH_OPTCR3;		//!< FLASH Operation Byte Control Register 3 (offset = 0x10C)
    __IOM uint32_t FLASH_OPTCR4;		//!< FLASH Operation Byte Control Register 4 (offset = 0x110)
    uint32_t RESERVED3[10];             //!< Reserved                             (offset = 0x114-0x13C)
    __IOM uint32_t FLASH_USR_OPT[16];	//!< FLASH User Operation Byte Register 16~31 (offset = 0x140-0x17C)
    uint32_t RESERVED4[127];             //!< Reserved                             (offset = 0x180-0x37C)
    __IOM uint32_t FLASH_CKDIVR;        //!< FLASH QSPI Clock-DIV Config Register (offset = 0x380)
    __IOM uint32_t FLASH_SAMPLE_DELAY;  //!< FLASH QSPI Sample-Delay Config Register (offset = 0x384)
    uint32_t RESERVED5[22];             //!< Reserved                             (offset = 0x388)
    __IOM uint32_t FLASH_FSLOCK;        //!< FLASH Function Safety Lock Register  (offset = 0x3E0)
    __IOM uint32_t FLASH_FSCTRL;        //!< FLASH Function Safety Control Register (offset = 0x3E4)
    __IOM uint32_t FLASH_FSDATA;        //!< FLASH Function Safety Data Access Register (offset = 0x3E8)
    __IOM uint32_t FLASH_FSINFO;        //!< FLASH Function Safety Error INFO Register (offset = 0x3EC)
    uint32_t RESERVED6[2];              //!< Reserved                             (offset = 0x3F0)
    __IOM uint32_t FLASH_PARAM1;        //!< FLASH Parameters Register            (offset = 0x3F8)
    __IOM uint32_t FLASH_REV;           //!< FLASH Revision Register              (offset = 0x3FC)

}XFLASHC_TypeDef;
#endif


//*****************************************************************************
//
// XFLASH Size Definition
//
//*****************************************************************************
#define FLASH_SIZE      8192*1024  //!< 8MB Flash memory size in bytes
#define OTP_SIZE        513        //!< 513 bytes One-Time Programmable memory size
#define OPT_SIZE        1024       //!< 1KB Option bytes memory size
#define PAGE_SIZE       4096       //!< 4KB Flash page size in bytes

#if XFLASHC_HW_VER == 0x00
//*****************************************************************************
//
// XFLASHC Sector Address Definitions
//
//*****************************************************************************
#define SECTOR0_ADDR    ((uint32_t)0x0FFF0000)  //!< Sector 0 base address
#define SECTOR1_ADDR    ((uint32_t)0x0FFF4000)  //!< Sector 1 base address
#define SECTOR2_ADDR    ((uint32_t)0x0FFF8000)  //!< Sector 2 base address
#define SECTOR3_ADDR    ((uint32_t)0x0FFFC000)  //!< Sector 3 base address
#define SECTOR4_ADDR    ((uint32_t)0x10000000)  //!< Sector 4 base address
#define SECTOR5_ADDR    ((uint32_t)0x10010000)  //!< Sector 5 base address
#define SECTOR6_ADDR    ((uint32_t)0x10030000)  //!< Sector 6 base address
#define SECTOR7_ADDR    ((uint32_t)0x10050000)  //!< Sector 7 base address
#define SECTOR8_ADDR    ((uint32_t)0x10070000)  //!< Sector 8 base address
#define SECTOR9_ADDR    ((uint32_t)0x10090000)  //!< Sector 9 base address
#define SECTOR10_ADDR   ((uint32_t)0x100B0000)  //!< Sector 10 base address
#define SECTOR11_ADDR   ((uint32_t)0x100D0000)  //!< Sector 11 base address
#define SECTOR12_ADDR   ((uint32_t)0x100F0000)  //!< Sector 12 base address
#define SECTOR13_ADDR   ((uint32_t)0x10130000)  //!< Sector 13 base address
#define SECTOR14_ADDR   ((uint32_t)0x10170000)  //!< Sector 14 base address
#define SECTOR15_ADDR   ((uint32_t)0x101B0000)  //!< Sector 15 base address

#define SECTOR16_ADDR   ((uint32_t)0x101F0000)  //!< Sector 16 base address
#define SECTOR17_ADDR   ((uint32_t)0x10270000)  //!< Sector 17 base address
#define SECTOR18_ADDR   ((uint32_t)0x102F0000)  //!< Sector 18 base address
#define SECTOR19_ADDR   ((uint32_t)0x10370000)  //!< Sector 19 base address
#define SECTOR20_ADDR   ((uint32_t)0x103F0000)  //!< Sector 20 base address
#define SECTOR21_ADDR   ((uint32_t)0x10470000)  //!< Sector 21 base address
#define SECTOR22_ADDR   ((uint32_t)0x104F0000)  //!< Sector 22 base address

#define SECTOR23_ADDR   ((uint32_t)0x10570000)  //!< Sector 23 base address
#define SECTOR24_ADDR   ((uint32_t)0x105F0000)  //!< Sector 24 base address
#define SECTOR25_ADDR   ((uint32_t)0x10670000)  //!< Sector 25 base address
#define SECTOR26_ADDR   ((uint32_t)0x106F0000)  //!< Sector 26 base address
#define SECTOR27_ADDR   ((uint32_t)0x10770000)  //!< Sector 27 base address


//*****************************************************************************
//
// XFLASHC OTP and Option Bytes Address Definitions
//
//*****************************************************************************
#define OTP_DATA_ADDR_BASE  ((uint32_t)0x1FFF7800)  //!< OTP data area base address
#define OTP_DATA_ADDR_END   ((uint32_t)0x1FFF79FF)  //!< OTP data area end address
#define OTP_LOCK_ADDR       ((uint32_t)0x1FFF7A00)  //!< OTP lock register address

#define OPT_ADDR_BASE       ((uint32_t)0x1FFFC000)  //!< Option bytes area base address
#define OPT_ADDR_END        ((uint32_t)0x1FFFC3FF)  //!< Option bytes area end address
#elif XFLASHC_HW_VER == 0x01
//*****************************************************************************
//
// XFLASHC Sector Address Definitions
//
//*****************************************************************************
//Storage0(ZW)
#define SECTOR0_ADDR     ((uint32_t)XFLASHC_BASE)  //!< Sector 0 base address
#define SECTOR1_ADDR     ((uint32_t)SECTOR0_ADDR  + (32*1024))  //!< Sector 1 base address
#define SECTOR2_ADDR     ((uint32_t)SECTOR1_ADDR  + (32*1024))  //!< Sector 2 base address
#define SECTOR3_ADDR     ((uint32_t)SECTOR2_ADDR  + (32*1024))  //!< Sector 3 base address
#define SECTOR4_ADDR     ((uint32_t)SECTOR3_ADDR  + (64*1024))  //!< Sector 4 base address
#define SECTOR5_ADDR     ((uint32_t)SECTOR4_ADDR  + (64*1024))  //!< Sector 5 base address
//Storage1(ZW)
#define SECTOR6_ADDR     ((uint32_t)SECTOR5_ADDR  + (32*1024))  //!< Sector 6 base address
#define SECTOR7_ADDR     ((uint32_t)SECTOR6_ADDR  + (32*1024))  //!< Sector 7 base address
#define SECTOR8_ADDR     ((uint32_t)SECTOR7_ADDR  + (32*1024))  //!< Sector 8 base address
#define SECTOR9_ADDR     ((uint32_t)SECTOR8_ADDR  + (32*1024))  //!< Sector 9 base address
#define SECTOR10_ADDR    ((uint32_t)SECTOR9_ADDR  + (64*1024))  //!< Sector 10 base address
#define SECTOR11_ADDR    ((uint32_t)SECTOR10_ADDR + (64*1024))  //!< Sector 11 base address
//Storage0(Non-ZW)
#define SECTOR12_ADDR    ((uint32_t)SECTOR11_ADDR + (64*1024))  //!< Sector 12 base address
#define SECTOR13_ADDR    ((uint32_t)SECTOR12_ADDR + (64*1024))  //!< Sector 13 base address
#define SECTOR14_ADDR    ((uint32_t)SECTOR13_ADDR + (64*1024))  //!< Sector 14 base address
#define SECTOR15_ADDR    ((uint32_t)SECTOR14_ADDR + (64*1024))  //!< Sector 15 base address
#define SECTOR16_ADDR    ((uint32_t)SECTOR15_ADDR + (64*1024))  //!< Sector 16 base address
#define SECTOR17_ADDR    ((uint32_t)SECTOR16_ADDR + (64*1024))  //!< Sector 17 base address
#define SECTOR18_ADDR    ((uint32_t)SECTOR17_ADDR + (64*1024))  //!< Sector 18 base address
#define SECTOR19_ADDR    ((uint32_t)SECTOR18_ADDR + (64*1024))  //!< Sector 19 base address
#define SECTOR20_ADDR    ((uint32_t)SECTOR19_ADDR + (64*1024))  //!< Sector 20 base address
#define SECTOR21_ADDR    ((uint32_t)SECTOR20_ADDR + (64*1024))  //!< Sector 21 base address
#define SECTOR22_ADDR    ((uint32_t)SECTOR21_ADDR + (64*1024))  //!< Sector 22 base address
#define SECTOR23_ADDR    ((uint32_t)SECTOR22_ADDR + (64*1024))  //!< Sector 23 base address
#define SECTOR24_ADDR    ((uint32_t)SECTOR23_ADDR + (64*1024))  //!< Sector 24 base address
#define SECTOR25_ADDR    ((uint32_t)SECTOR24_ADDR + (64*1024))  //!< Sector 25 base address
#define SECTOR26_ADDR    ((uint32_t)SECTOR25_ADDR + (64*1024))  //!< Sector 26 base address
#define SECTOR27_ADDR    ((uint32_t)SECTOR26_ADDR + (64*1024))  //!< Sector 27 base address
#define SECTOR28_ADDR    ((uint32_t)SECTOR27_ADDR  + (64*1024)) //!< Sector 28 base address
#define SECTOR29_ADDR    ((uint32_t)SECTOR28_ADDR  + (64*1024)) //!< Sector 29 base address
#define SECTOR30_ADDR    ((uint32_t)SECTOR29_ADDR  + (64*1024)) //!< Sector 30 base address
#define SECTOR31_ADDR    ((uint32_t)SECTOR30_ADDR  + (64*1024)) //!< Sector 31 base address
#define SECTOR32_ADDR    ((uint32_t)SECTOR31_ADDR  + (64*1024)) //!< Sector 32 base address
#define SECTOR33_ADDR    ((uint32_t)SECTOR32_ADDR  + (64*1024)) //!< Sector 33 base address
#define SECTOR34_ADDR    ((uint32_t)SECTOR33_ADDR  + (64*1024)) //!< Sector 34 base address
#define SECTOR35_ADDR    ((uint32_t)SECTOR34_ADDR  + (64*1024)) //!< Sector 35 base address
#define SECTOR36_ADDR    ((uint32_t)SECTOR35_ADDR  + (64*1024)) //!< Sector 36 base address
#define SECTOR37_ADDR    ((uint32_t)SECTOR36_ADDR  + (64*1024)) //!< Sector 37 base address
#define SECTOR38_ADDR    ((uint32_t)SECTOR37_ADDR  + (64*1024)) //!< Sector 38 base address
#define SECTOR39_ADDR    ((uint32_t)SECTOR38_ADDR  + (64*1024)) //!< Sector 39 base address
#define SECTOR40_ADDR    ((uint32_t)SECTOR39_ADDR  + (64*1024)) //!< Sector 40 base address
#define SECTOR41_ADDR    ((uint32_t)SECTOR40_ADDR  + (64*1024)) //!< Sector 41 base address
#define SECTOR42_ADDR    ((uint32_t)SECTOR41_ADDR  + (64*1024)) //!< Sector 42 base address
#define SECTOR43_ADDR    ((uint32_t)SECTOR42_ADDR  + (64*1024)) //!< Sector 43 base address
#define SECTOR44_ADDR    ((uint32_t)SECTOR43_ADDR  + (64*1024)) //!< Sector 44 base address
#define SECTOR45_ADDR    ((uint32_t)SECTOR44_ADDR  + (64*1024)) //!< Sector 45 base address
#define SECTOR46_ADDR    ((uint32_t)SECTOR45_ADDR  + (64*1024)) //!< Sector 46 base address
#define SECTOR47_ADDR    ((uint32_t)SECTOR46_ADDR  + (64*1024)) //!< Sector 47 base address
#define SECTOR48_ADDR    ((uint32_t)SECTOR47_ADDR  + (64*1024)) //!< Sector 48 base address
#define SECTOR49_ADDR    ((uint32_t)SECTOR48_ADDR  + (64*1024)) //!< Sector 49 base address
#define SECTOR50_ADDR    ((uint32_t)SECTOR49_ADDR  + (64*1024)) //!< Sector 50 base address
#define SECTOR51_ADDR    ((uint32_t)SECTOR50_ADDR  + (64*1024)) //!< Sector 51 base address
#define SECTOR52_ADDR    ((uint32_t)SECTOR51_ADDR  + (64*1024)) //!< Sector 52 base address
#define SECTOR53_ADDR    ((uint32_t)SECTOR52_ADDR  + (64*1024)) //!< Sector 53 base address
#define SECTOR54_ADDR    ((uint32_t)SECTOR53_ADDR  + (64*1024)) //!< Sector 54 base address
#define SECTOR55_ADDR    ((uint32_t)SECTOR54_ADDR  + (64*1024)) //!< Sector 55 base address
#define SECTOR56_ADDR    ((uint32_t)SECTOR55_ADDR  + (64*1024)) //!< Sector 56 base address
#define SECTOR57_ADDR    ((uint32_t)SECTOR56_ADDR  + (64*1024)) //!< Sector 57 base address
#define SECTOR58_ADDR    ((uint32_t)SECTOR57_ADDR  + (64*1024)) //!< Sector 58 base address
#define SECTOR59_ADDR    ((uint32_t)SECTOR58_ADDR  + (64*1024)) //!< Sector 59 base address
#define SECTOR60_ADDR    ((uint32_t)SECTOR59_ADDR  + (64*1024)) //!< Sector 60 base address
#define SECTOR61_ADDR    ((uint32_t)SECTOR60_ADDR  + (64*1024)) //!< Sector 61 base address
#define SECTOR62_ADDR    ((uint32_t)SECTOR61_ADDR  + (64*1024)) //!< Sector 62 base address
#define SECTOR63_ADDR    ((uint32_t)SECTOR62_ADDR  + (64*1024)) //!< Sector 63 base address
#define SECTOR64_ADDR    ((uint32_t)SECTOR63_ADDR  + (64*1024)) //!< Sector 64 base address
#define SECTOR65_ADDR    ((uint32_t)SECTOR64_ADDR  + (64*1024)) //!< Sector 65 base address
#define SECTOR66_ADDR    ((uint32_t)SECTOR65_ADDR  + (64*1024)) //!< Sector 66 base address
#define SECTOR67_ADDR    ((uint32_t)SECTOR66_ADDR  + (64*1024)) //!< Sector 67 base address
#define SECTOR68_ADDR    ((uint32_t)SECTOR67_ADDR  + (64*1024)) //!< Sector 68 base address
#define SECTOR69_ADDR    ((uint32_t)SECTOR68_ADDR  + (64*1024)) //!< Sector 69 base address
#define SECTOR70_ADDR    ((uint32_t)SECTOR69_ADDR  + (64*1024)) //!< Sector 70 base address
#define SECTOR71_ADDR    ((uint32_t)SECTOR70_ADDR  + (64*1024)) //!< Sector 71 base address
//Storage1(Non-ZW)
#define SECTOR72_ADDR    ((uint32_t)SECTOR71_ADDR  + (64*1024)) //!< Sector 72 base address
#define SECTOR73_ADDR    ((uint32_t)SECTOR72_ADDR  + (64*1024)) //!< Sector 73 base address
#define SECTOR74_ADDR    ((uint32_t)SECTOR73_ADDR  + (64*1024)) //!< Sector 74 base address
#define SECTOR75_ADDR    ((uint32_t)SECTOR74_ADDR  + (64*1024)) //!< Sector 75 base address
#define SECTOR76_ADDR    ((uint32_t)SECTOR75_ADDR  + (64*1024)) //!< Sector 76 base address
#define SECTOR77_ADDR    ((uint32_t)SECTOR76_ADDR  + (64*1024)) //!< Sector 77 base address
#define SECTOR78_ADDR    ((uint32_t)SECTOR77_ADDR  + (64*1024)) //!< Sector 78 base address
#define SECTOR79_ADDR    ((uint32_t)SECTOR78_ADDR  + (64*1024)) //!< Sector 79 base address
#define SECTOR80_ADDR    ((uint32_t)SECTOR79_ADDR  + (64*1024)) //!< Sector 80 base address
#define SECTOR81_ADDR    ((uint32_t)SECTOR80_ADDR  + (64*1024)) //!< Sector 81 base address
#define SECTOR82_ADDR    ((uint32_t)SECTOR81_ADDR  + (64*1024)) //!< Sector 82 base address
#define SECTOR83_ADDR    ((uint32_t)SECTOR82_ADDR  + (64*1024)) //!< Sector 83 base address
#define SECTOR84_ADDR    ((uint32_t)SECTOR83_ADDR  + (64*1024)) //!< Sector 84 base address
#define SECTOR85_ADDR    ((uint32_t)SECTOR84_ADDR  + (64*1024)) //!< Sector 85 base address
#define SECTOR86_ADDR    ((uint32_t)SECTOR85_ADDR  + (64*1024)) //!< Sector 86 base address
#define SECTOR87_ADDR    ((uint32_t)SECTOR86_ADDR  + (64*1024)) //!< Sector 87 base address
#define SECTOR88_ADDR    ((uint32_t)SECTOR87_ADDR  + (64*1024)) //!< Sector 88 base address
#define SECTOR89_ADDR    ((uint32_t)SECTOR88_ADDR  + (64*1024)) //!< Sector 89 base address
#define SECTOR90_ADDR    ((uint32_t)SECTOR89_ADDR  + (64*1024)) //!< Sector 90 base address
#define SECTOR91_ADDR    ((uint32_t)SECTOR90_ADDR  + (64*1024)) //!< Sector 91 base address
#define SECTOR92_ADDR    ((uint32_t)SECTOR91_ADDR  + (64*1024)) //!< Sector 92 base address
#define SECTOR93_ADDR    ((uint32_t)SECTOR92_ADDR  + (64*1024)) //!< Sector 93 base address
#define SECTOR94_ADDR    ((uint32_t)SECTOR93_ADDR  + (64*1024)) //!< Sector 94 base address
#define SECTOR95_ADDR    ((uint32_t)SECTOR94_ADDR  + (64*1024)) //!< Sector 95 base address
#define SECTOR96_ADDR    ((uint32_t)SECTOR95_ADDR  + (64*1024)) //!< Sector 96 base address
#define SECTOR97_ADDR    ((uint32_t)SECTOR96_ADDR  + (64*1024)) //!< Sector 97 base address
#define SECTOR98_ADDR    ((uint32_t)SECTOR97_ADDR  + (64*1024)) //!< Sector 98 base address
#define SECTOR99_ADDR    ((uint32_t)SECTOR98_ADDR  + (64*1024)) //!< Sector 99 base address
#define SECTOR100_ADDR   ((uint32_t)SECTOR99_ADDR  + (64*1024)) //!< Sector 100 base address
#define SECTOR101_ADDR   ((uint32_t)SECTOR100_ADDR + (64*1024)) //!< Sector 101 base address
#define SECTOR102_ADDR   ((uint32_t)SECTOR101_ADDR + (64*1024)) //!< Sector 102 base address
#define SECTOR103_ADDR   ((uint32_t)SECTOR102_ADDR + (64*1024)) //!< Sector 103 base address
#define SECTOR104_ADDR   ((uint32_t)SECTOR103_ADDR + (64*1024)) //!< Sector 104 base address
#define SECTOR105_ADDR   ((uint32_t)SECTOR104_ADDR + (64*1024)) //!< Sector 105 base address
#define SECTOR106_ADDR   ((uint32_t)SECTOR105_ADDR + (64*1024)) //!< Sector 106 base address
#define SECTOR107_ADDR   ((uint32_t)SECTOR106_ADDR + (64*1024)) //!< Sector 107 base address
#define SECTOR108_ADDR   ((uint32_t)SECTOR107_ADDR + (64*1024)) //!< Sector 108 base address
#define SECTOR109_ADDR   ((uint32_t)SECTOR108_ADDR + (64*1024)) //!< Sector 109 base address
#define SECTOR110_ADDR   ((uint32_t)SECTOR109_ADDR + (64*1024)) //!< Sector 110 base address
#define SECTOR111_ADDR   ((uint32_t)SECTOR110_ADDR + (64*1024)) //!< Sector 111 base address
#define SECTOR112_ADDR   ((uint32_t)SECTOR111_ADDR + (64*1024)) //!< Sector 112 base address
#define SECTOR113_ADDR   ((uint32_t)SECTOR112_ADDR + (64*1024)) //!< Sector 113 base address
#define SECTOR114_ADDR   ((uint32_t)SECTOR113_ADDR + (64*1024)) //!< Sector 114 base address
#define SECTOR115_ADDR   ((uint32_t)SECTOR114_ADDR + (64*1024)) //!< Sector 115 base address
#define SECTOR116_ADDR   ((uint32_t)SECTOR115_ADDR + (64*1024)) //!< Sector 116 base address
#define SECTOR117_ADDR   ((uint32_t)SECTOR116_ADDR + (64*1024)) //!< Sector 117 base address
#define SECTOR118_ADDR   ((uint32_t)SECTOR117_ADDR + (64*1024)) //!< Sector 118 base address
#define SECTOR119_ADDR   ((uint32_t)SECTOR118_ADDR + (64*1024)) //!< Sector 119 base address
#define SECTOR120_ADDR   ((uint32_t)SECTOR119_ADDR + (64*1024)) //!< Sector 120 base address
#define SECTOR121_ADDR   ((uint32_t)SECTOR120_ADDR + (64*1024)) //!< Sector 121 base address
#define SECTOR122_ADDR   ((uint32_t)SECTOR121_ADDR + (64*1024)) //!< Sector 122 base address
#define SECTOR123_ADDR   ((uint32_t)SECTOR122_ADDR + (64*1024)) //!< Sector 123 base address
#define SECTOR124_ADDR   ((uint32_t)SECTOR123_ADDR + (64*1024)) //!< Sector 124 base address
#define SECTOR125_ADDR   ((uint32_t)SECTOR124_ADDR + (64*1024)) //!< Sector 125 base address
#define SECTOR126_ADDR   ((uint32_t)SECTOR125_ADDR + (64*1024)) //!< Sector 126 base address
#define SECTOR127_ADDR   ((uint32_t)SECTOR126_ADDR + (64*1024)) //!< Sector 127 base address
#define SECTOR128_ADDR   ((uint32_t)SECTOR127_ADDR + (64*1024)) //!< Sector 128 base address
#define SECTOR129_ADDR   ((uint32_t)SECTOR128_ADDR + (64*1024)) //!< Sector 129 base address
#define SECTOR130_ADDR   ((uint32_t)SECTOR129_ADDR + (64*1024)) //!< Sector 130 base address
#define SECTOR131_ADDR   ((uint32_t)SECTOR130_ADDR + (64*1024)) //!< Sector 131 base address

//*****************************************************************************
//
// XFLASHC OTP and Option Bytes Address Definitions
//
//*****************************************************************************
#define OTP_DATA_ADDR_BASE  ((uint32_t)0x1FFF7800)  //!< OTP data area base address
#define OTP_DATA_ADDR_END   ((uint32_t)0x1FFF7AFF)  //!< OTP data area end address
#define OTP_LOCK_ADDR       ((uint32_t)0x1FFF7B00)  //!< OTP lock register address

#define OPT_ADDR_BASE       ((uint32_t)0x1FFFC000)  //!< Option bytes area base address
#define OPT_ADDR_END        ((uint32_t)0x1FFFC3FF)  //!< Option bytes area end address
#endif



//*****************************************************************************
//
// FLASH_PROGRAM_SIZE
//
//*****************************************************************************
typedef enum
{
    PROGRAMSIZE8   = 0x00,  //!< 8-bit programming size
    PROGRAMSIZE16  = 0x01,  //!< 16-bit programming size
    PROGRAMSIZE32  = 0x02,  //!< 32-bit programming size
    PROGRAMSIZE64  = 0x03,  //!< 64-bit programming size
    PROGRAMSIZE128 = 0x04,  //!< 128-bit programming size
} FLASH_PROGRAM_SIZE;

#if XFLASHC_HW_VER == 0x00
//*****************************************************************************
//
// FLASH_SECTOR_A
//
//*****************************************************************************
typedef enum
{
    PSECTOR0  = (1 << 0),   //!< Sector 0 in group A
    PSECTOR1  = (1 << 1),   //!< Sector 1 in group A
    PSECTOR2  = (1 << 2),   //!< Sector 2 in group A
    PSECTOR3  = (1 << 3),   //!< Sector 3 in group A
    PSECTOR4  = (1 << 4),   //!< Sector 4 in group A
    PSECTOR5  = (1 << 5),   //!< Sector 5 in group A
    PSECTOR6  = (1 << 6),   //!< Sector 6 in group A
    PSECTOR7  = (1 << 7),   //!< Sector 7 in group A
    PSECTOR8  = (1 << 8),   //!< Sector 8 in group A
    PSECTOR9  = (1 << 9),   //!< Sector 9 in group A
    PSECTOR10 = (1 << 10),  //!< Sector 10 in group A
    PSECTOR11 = (1 << 11),  //!< Sector 11 in group A
    PSECTOR_A_ALL = 0xFFF,  //!< All sectors in group A
} FLASH_SECTOR_A;


//*****************************************************************************
//
// FLASH_SECTOR_B
//
//*****************************************************************************
typedef enum
{
    PSECTOR12 = (1 << 0),   //!< Sector 12 in group B
    PSECTOR13 = (1 << 1),   //!< Sector 13 in group B
    PSECTOR14 = (1 << 2),   //!< Sector 14 in group B
    PSECTOR15 = (1 << 3),   //!< Sector 15 in group B
    PSECTOR16 = (1 << 4),   //!< Sector 16 in group B
    PSECTOR17 = (1 << 5),   //!< Sector 17 in group B
    PSECTOR18 = (1 << 6),   //!< Sector 18 in group B
    PSECTOR19 = (1 << 7),   //!< Sector 19 in group B
    PSECTOR20 = (1 << 8),   //!< Sector 20 in group B
    PSECTOR21 = (1 << 9),   //!< Sector 21 in group B
    PSECTOR22 = (1 << 10),  //!< Sector 22 in group B
    PSECTOR23 = (1 << 11),  //!< Sector 23 in group B
    PSECTOR24 = (1 << 12),  //!< Sector 24 in group B
    PSECTOR25 = (1 << 13),  //!< Sector 25 in group B
    PSECTOR26 = (1 << 14),  //!< Sector 26 in group B
    PSECTOR27 = (1 << 15),  //!< Sector 27 in group B
    PSECTOR_B_ALL = 0xFFFF, //!< All sectors in group B

} FLASH_SECTOR_B;
#endif

//*****************************************************************************
//
// FLASH_SPRMOD
//
//*****************************************************************************
typedef enum
{
    WIRTEP  = 0x00,  //!< Write protection mode
    PCROP   = 0x01,  //!< Protected content readout protection mode
} FLASH_SPRMOD;


//*****************************************************************************
//
// FLASH_ERASE_SECTOR
//
//*****************************************************************************
typedef enum
{
    ESECTOR0  = 0x0,  //!< Sector 0 for erase operation
    ESECTOR1  = 0x1,   //!< Sector 1 for erase operation
    ESECTOR2  = 0x2,   //!< Sector 2 for erase operation
    ESECTOR3  = 0x3,   //!< Sector 3 for erase operation
    ESECTOR4  = 0x4,   //!< Sector 4 for erase operation
    ESECTOR5  = 0x5,   //!< Sector 5 for erase operation
    ESECTOR6  = 0x6,   //!< Sector 6 for erase operation
    ESECTOR7  = 0x7,   //!< Sector 7 for erase operation
    ESECTOR8  = 0x8,   //!< Sector 8 for erase operation
    ESECTOR9  = 0x9,   //!< Sector 9 for erase operation
    ESECTOR10 = 0xA,   //!< Sector 10 for erase operation
    ESECTOR11 = 0xB,   //!< Sector 11 for erase operation
    ESECTOR12 = 0xC,   //!< Sector 12 for erase operation
    ESECTOR13 = 0xD,   //!< Sector 13 for erase operation
    ESECTOR14 = 0xE,   //!< Sector 14 for erase operation
    ESECTOR15 = 0xF,   //!< Sector 15 for erase operation
    ESECTOR16 = 0x10,  //!< Sector 16 for erase operation
    ESECTOR17 = 0x11,  //!< Sector 17 for erase operation
    ESECTOR18 = 0x12,  //!< Sector 18 for erase operation
    ESECTOR19 = 0x13,  //!< Sector 19 for erase operation
    ESECTOR20 = 0x14,  //!< Sector 20 for erase operation
    ESECTOR21 = 0x15,  //!< Sector 21 for erase operation
    ESECTOR22 = 0x16,  //!< Sector 22 for erase operation
    ESECTOR23 = 0x17,  //!< Sector 23 for erase operation
    ESECTOR24 = 0x18,  //!< Sector 24 for erase operation
    ESECTOR25 = 0x19,  //!< Sector 25 for erase operation
    ESECTOR26 = 0x1A,  //!< Sector 26 for erase operation
    ESECTOR27 = 0x1B,  //!< Sector 27 for erase operation
#if XFLASHC_HW_VER == 0x01
	ESECTOR28,         //!< Sector 28 for erase operation
	ESECTOR29,         //!< Sector 29 for erase operation
	ESECTOR30,         //!< Sector 30 for erase operation
	ESECTOR31,         //!< Sector 31 for erase operation
	ESECTOR32  = (32  & 0x1F)||((32  & (~0x1F))<<3),         //!< Sector 32 for erase operation
	ESECTOR33  = (33  & 0x1F)||((33  & (~0x1F))<<3),         //!< Sector 33 for erase operation
	ESECTOR34  = (34  & 0x1F)||((34  & (~0x1F))<<3),         //!< Sector 34 for erase operation
	ESECTOR35  = (35  & 0x1F)||((35  & (~0x1F))<<3),         //!< Sector 35 for erase operation
	ESECTOR36  = (36  & 0x1F)||((36  & (~0x1F))<<3),         //!< Sector 36 for erase operation
	ESECTOR37  = (37  & 0x1F)||((37  & (~0x1F))<<3),         //!< Sector 37 for erase operation
	ESECTOR38  = (38  & 0x1F)||((38  & (~0x1F))<<3),         //!< Sector 38 for erase operation
	ESECTOR39  = (39  & 0x1F)||((39  & (~0x1F))<<3),         //!< Sector 39 for erase operation
	ESECTOR40  = (40  & 0x1F)||((40  & (~0x1F))<<3),         //!< Sector 40 for erase operation
	ESECTOR41  = (41  & 0x1F)||((41  & (~0x1F))<<3),         //!< Sector 41 for erase operation
	ESECTOR42  = (42  & 0x1F)||((42  & (~0x1F))<<3),         //!< Sector 42 for erase operation
	ESECTOR43  = (43  & 0x1F)||((43  & (~0x1F))<<3),         //!< Sector 43 for erase operation
	ESECTOR44  = (44  & 0x1F)||((44  & (~0x1F))<<3),         //!< Sector 44 for erase operation
	ESECTOR45  = (45  & 0x1F)||((45  & (~0x1F))<<3),         //!< Sector 45 for erase operation
	ESECTOR46  = (46  & 0x1F)||((46  & (~0x1F))<<3),         //!< Sector 46 for erase operation
	ESECTOR47  = (47  & 0x1F)||((47  & (~0x1F))<<3),         //!< Sector 47 for erase operation
	ESECTOR48  = (48  & 0x1F)||((48  & (~0x1F))<<3),         //!< Sector 48 for erase operation
	ESECTOR49  = (49  & 0x1F)||((49  & (~0x1F))<<3),         //!< Sector 49 for erase operation
	ESECTOR50  = (50  & 0x1F)||((50  & (~0x1F))<<3),         //!< Sector 50 for erase operation
	ESECTOR51  = (51  & 0x1F)||((51  & (~0x1F))<<3),         //!< Sector 51 for erase operation
	ESECTOR52  = (52  & 0x1F)||((52  & (~0x1F))<<3),         //!< Sector 52 for erase operation
	ESECTOR53  = (53  & 0x1F)||((53  & (~0x1F))<<3),         //!< Sector 53 for erase operation
	ESECTOR54  = (54  & 0x1F)||((54  & (~0x1F))<<3),         //!< Sector 54 for erase operation
	ESECTOR55  = (55  & 0x1F)||((55  & (~0x1F))<<3),         //!< Sector 55 for erase operation
	ESECTOR56  = (56  & 0x1F)||((56  & (~0x1F))<<3),         //!< Sector 56 for erase operation
	ESECTOR57  = (57  & 0x1F)||((57  & (~0x1F))<<3),         //!< Sector 57 for erase operation
	ESECTOR58  = (58  & 0x1F)||((58  & (~0x1F))<<3),         //!< Sector 58 for erase operation
	ESECTOR59  = (59  & 0x1F)||((59  & (~0x1F))<<3),         //!< Sector 59 for erase operation
	ESECTOR60  = (60  & 0x1F)||((60  & (~0x1F))<<3),         //!< Sector 60 for erase operation
	ESECTOR61  = (61  & 0x1F)||((61  & (~0x1F))<<3),         //!< Sector 61 for erase operation
	ESECTOR62  = (62  & 0x1F)||((62  & (~0x1F))<<3),         //!< Sector 62 for erase operation
	ESECTOR63  = (63  & 0x1F)||((63  & (~0x1F))<<3),         //!< Sector 63 for erase operation
	ESECTOR64  = (64  & 0x1F)||((64  & (~0x1F))<<3),         //!< Sector 64 for erase operation
	ESECTOR65  = (65  & 0x1F)||((65  & (~0x1F))<<3),         //!< Sector 65 for erase operation
	ESECTOR66  = (66  & 0x1F)||((66  & (~0x1F))<<3),         //!< Sector 66 for erase operation
	ESECTOR67  = (67  & 0x1F)||((67  & (~0x1F))<<3),         //!< Sector 67 for erase operation
	ESECTOR68  = (68  & 0x1F)||((68  & (~0x1F))<<3),         //!< Sector 68 for erase operation
	ESECTOR69  = (69  & 0x1F)||((69  & (~0x1F))<<3),         //!< Sector 69 for erase operation
	ESECTOR70  = (70  & 0x1F)||((70  & (~0x1F))<<3),         //!< Sector 70 for erase operation
	ESECTOR71  = (71  & 0x1F)||((71  & (~0x1F))<<3),         //!< Sector 71 for erase operation
	ESECTOR72  = (72  & 0x1F)||((72  & (~0x1F))<<3),         //!< Sector 72 for erase operation
	ESECTOR73  = (73  & 0x1F)||((73  & (~0x1F))<<3),         //!< Sector 73 for erase operation
	ESECTOR74  = (74  & 0x1F)||((74  & (~0x1F))<<3),         //!< Sector 74 for erase operation
	ESECTOR75  = (75  & 0x1F)||((75  & (~0x1F))<<3),         //!< Sector 75 for erase operation
	ESECTOR76  = (76  & 0x1F)||((76  & (~0x1F))<<3),         //!< Sector 76 for erase operation
	ESECTOR77  = (77  & 0x1F)||((77  & (~0x1F))<<3),         //!< Sector 77 for erase operation
	ESECTOR78  = (78  & 0x1F)||((78  & (~0x1F))<<3),         //!< Sector 78 for erase operation
	ESECTOR79  = (79  & 0x1F)||((79  & (~0x1F))<<3),         //!< Sector 79 for erase operation
	ESECTOR80  = (80  & 0x1F)||((80  & (~0x1F))<<3),         //!< Sector 80 for erase operation
	ESECTOR81  = (81  & 0x1F)||((81  & (~0x1F))<<3),         //!< Sector 81 for erase operation
	ESECTOR82  = (82  & 0x1F)||((82  & (~0x1F))<<3),         //!< Sector 82 for erase operation
	ESECTOR83  = (83  & 0x1F)||((83  & (~0x1F))<<3),         //!< Sector 83 for erase operation
	ESECTOR84  = (84  & 0x1F)||((84  & (~0x1F))<<3),         //!< Sector 84 for erase operation
	ESECTOR85  = (85  & 0x1F)||((85  & (~0x1F))<<3),         //!< Sector 85 for erase operation
	ESECTOR86  = (86  & 0x1F)||((86  & (~0x1F))<<3),         //!< Sector 86 for erase operation
	ESECTOR87  = (87  & 0x1F)||((87  & (~0x1F))<<3),         //!< Sector 87 for erase operation
	ESECTOR88  = (88  & 0x1F)||((88  & (~0x1F))<<3),         //!< Sector 88 for erase operation
	ESECTOR89  = (89  & 0x1F)||((89  & (~0x1F))<<3),         //!< Sector 89 for erase operation
	ESECTOR90  = (90  & 0x1F)||((90  & (~0x1F))<<3),         //!< Sector 90 for erase operation
	ESECTOR91  = (91  & 0x1F)||((91  & (~0x1F))<<3),         //!< Sector 91 for erase operation
	ESECTOR92  = (92  & 0x1F)||((92  & (~0x1F))<<3),         //!< Sector 92 for erase operation
	ESECTOR93  = (93  & 0x1F)||((93  & (~0x1F))<<3),         //!< Sector 93 for erase operation
	ESECTOR94  = (94  & 0x1F)||((94  & (~0x1F))<<3),         //!< Sector 94 for erase operation
	ESECTOR95  = (95  & 0x1F)||((95  & (~0x1F))<<3),         //!< Sector 95 for erase operation
	ESECTOR96  = (96  & 0x1F)||((96  & (~0x1F))<<3),         //!< Sector 96 for erase operation
	ESECTOR97  = (97  & 0x1F)||((97  & (~0x1F))<<3),         //!< Sector 97 for erase operation
	ESECTOR98  = (98  & 0x1F)||((98  & (~0x1F))<<3),         //!< Sector 98 for erase operation
	ESECTOR99  = (99  & 0x1F)||((99  & (~0x1F))<<3),         //!< Sector 99 for erase operation
	ESECTOR100 = (100 & 0x1F)||((100 & (~0x1F))<<3),         //!< Sector 100 for erase operation
	ESECTOR101 = (101 & 0x1F)||((101 & (~0x1F))<<3),         //!< Sector 101 for erase operation
	ESECTOR102 = (102 & 0x1F)||((102 & (~0x1F))<<3),         //!< Sector 102 for erase operation
	ESECTOR103 = (103 & 0x1F)||((103 & (~0x1F))<<3),         //!< Sector 103 for erase operation
	ESECTOR104 = (104 & 0x1F)||((104 & (~0x1F))<<3),         //!< Sector 104 for erase operation
	ESECTOR105 = (105 & 0x1F)||((105 & (~0x1F))<<3),         //!< Sector 105 for erase operation
	ESECTOR106 = (106 & 0x1F)||((106 & (~0x1F))<<3),         //!< Sector 106 for erase operation
	ESECTOR107 = (107 & 0x1F)||((107 & (~0x1F))<<3),         //!< Sector 107 for erase operation
	ESECTOR108 = (108 & 0x1F)||((108 & (~0x1F))<<3),         //!< Sector 108 for erase operation
	ESECTOR109 = (109 & 0x1F)||((109 & (~0x1F))<<3),         //!< Sector 109 for erase operation
	ESECTOR110 = (110 & 0x1F)||((110 & (~0x1F))<<3),         //!< Sector 110 for erase operation
	ESECTOR111 = (111 & 0x1F)||((111 & (~0x1F))<<3),         //!< Sector 111 for erase operation
	ESECTOR112 = (112 & 0x1F)||((112 & (~0x1F))<<3),         //!< Sector 112 for erase operation
	ESECTOR113 = (113 & 0x1F)||((113 & (~0x1F))<<3),         //!< Sector 113 for erase operation
	ESECTOR114 = (114 & 0x1F)||((114 & (~0x1F))<<3),         //!< Sector 114 for erase operation
	ESECTOR115 = (115 & 0x1F)||((115 & (~0x1F))<<3),         //!< Sector 115 for erase operation
	ESECTOR116 = (116 & 0x1F)||((116 & (~0x1F))<<3),         //!< Sector 116 for erase operation
	ESECTOR117 = (117 & 0x1F)||((117 & (~0x1F))<<3),         //!< Sector 117 for erase operation
	ESECTOR118 = (118 & 0x1F)||((118 & (~0x1F))<<3),         //!< Sector 118 for erase operation
	ESECTOR119 = (119 & 0x1F)||((119 & (~0x1F))<<3),         //!< Sector 119 for erase operation
	ESECTOR120 = (120 & 0x1F)||((120 & (~0x1F))<<3),         //!< Sector 120 for erase operation
	ESECTOR121 = (121 & 0x1F)||((121 & (~0x1F))<<3),         //!< Sector 121 for erase operation
	ESECTOR122 = (122 & 0x1F)||((122 & (~0x1F))<<3),         //!< Sector 122 for erase operation
	ESECTOR123 = (123 & 0x1F)||((123 & (~0x1F))<<3),         //!< Sector 123 for erase operation
	ESECTOR124 = (124 & 0x1F)||((124 & (~0x1F))<<3),         //!< Sector 124 for erase operation
	ESECTOR125 = (125 & 0x1F)||((125 & (~0x1F))<<3),         //!< Sector 125 for erase operation
	ESECTOR126 = (126 & 0x1F)||((126 & (~0x1F))<<3),         //!< Sector 126 for erase operation
	ESECTOR127 = (127 & 0x1F)||((127 & (~0x1F))<<3),         //!< Sector 127 for erase operation
	ESECTOR128 = (128 & 0x1F)||((128 & (~0x1F))<<3),         //!< Sector 128 for erase operation
	ESECTOR129 = (129 & 0x1F)||((129 & (~0x1F))<<3),         //!< Sector 129 for erase operation
	ESECTOR130 = (130 & 0x1F)||((130 & (~0x1F))<<3),         //!< Sector 130 for erase operation
	ESECTOR131 = (131 & 0x1F)||((131 & (~0x1F))<<3),         //!< Sector 131 for erase operation

#endif
} FLASH_ERASE_SECTOR;


//*****************************************************************************
//
// FLASH_CRC_SECTOR
//
//*****************************************************************************
typedef enum
{
    CSECTOR0  = 0x0,   //!< Sector 0 for CRC calculation
    CSECTOR1  = 0x1,   //!< Sector 1 for CRC calculation
    CSECTOR2  = 0x2,   //!< Sector 2 for CRC calculation
    CSECTOR3  = 0x3,   //!< Sector 3 for CRC calculation
    CSECTOR4  = 0x4,   //!< Sector 4 for CRC calculation
    CSECTOR5  = 0x5,   //!< Sector 5 for CRC calculation
    CSECTOR6  = 0x6,   //!< Sector 6 for CRC calculation
    CSECTOR7  = 0x7,   //!< Sector 7 for CRC calculation
    CSECTOR8  = 0x8,   //!< Sector 8 for CRC calculation
    CSECTOR9  = 0x9,   //!< Sector 9 for CRC calculation
    CSECTOR10 = 0xA,   //!< Sector 10 for CRC calculation
    CSECTOR11 = 0xB,   //!< Sector 11 for CRC calculation
    CSECTOR12 = 0xC,   //!< Sector 12 for CRC calculation
    CSECTOR13 = 0xD,   //!< Sector 13 for CRC calculation
    CSECTOR14 = 0xE,   //!< Sector 14 for CRC calculation
    CSECTOR15 = 0xF,   //!< Sector 15 for CRC calculation
    CSECTOR16 = 0x10,  //!< Sector 16 for CRC calculation
    CSECTOR17 = 0x11,  //!< Sector 17 for CRC calculation
    CSECTOR18 = 0x12,  //!< Sector 18 for CRC calculation
    CSECTOR19 = 0x13,  //!< Sector 19 for CRC calculation
    CSECTOR20 = 0x14,  //!< Sector 20 for CRC calculation
    CSECTOR21 = 0x15,  //!< Sector 21 for CRC calculation
    CSECTOR22 = 0x16,  //!< Sector 22 for CRC calculation
    CSECTOR23 = 0x17,  //!< Sector 23 for CRC calculation
    CSECTOR24 = 0x18,  //!< Sector 24 for CRC calculation
    CSECTOR25 = 0x19,  //!< Sector 25 for CRC calculation
    CSECTOR26 = 0x1A,  //!< Sector 26 for CRC calculation
    CSECTOR27 = 0x1B,  //!< Sector 27 for CRC calculation
} FLASH_CRC_SECTOR;


//*****************************************************************************
//
// FLASH_RDP_LEVEL
//
//*****************************************************************************
typedef enum
{
    LEVEL_0  = 0xAA,  //!< No read protection
    LEVEL_1  = 0xFF,  //!< Level 1 read protection
    LEVEL_2  = 0xCC,  //!< Level 2 read protection
} FLASH_RDP_LEVEL;


//*****************************************************************************
//
// FLASH_START_MODE
//
//*****************************************************************************
typedef enum
{
    STARTFORMFLASH  = 0x00,  //!< Start from flash memory
    STARTFORMOTHER  = 0x01,  //!< Start from other memory
} FLASH_START_MODE;


//*****************************************************************************
//
// FLASH_CRC_SECTORADD
//
//*****************************************************************************
typedef enum
{
    DISABLE_SADD    = 0x00,                 //!< Disable sector address mode
    ENABLE_SADD     = FLASH_CRCCR_ADD_SECT_M,  //!< Enable sector address mode
} FLASH_CRC_SECTORADD;


//*****************************************************************************
//
// ZeroWaitAreaSIZE
//
//*****************************************************************************
typedef enum
{
    SIZE4B      = 0x00,   //!< 4-byte zero wait area
    SIZE64KB    = 0x01,   //!< 64KB zero wait area
    SIZE128KB   = 0x02,   //!< 128KB zero wait area
    SIZE256KB   = 0x03,   //!< 256KB zero wait area
} ZeroWaitAreaSIZE;


//*****************************************************************************
//
//! Waits for Flash controller busy flag to clear
//!
//! This function waits until the Flash controller is no longer busy.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_waitBSY(uint32_t base)
{
    //
    // Read busy flag status and wait for it to clear
    //
    uint32_t BSYstatus ;
    do
    {
        BSYstatus = HWREG(base + XFLASHC_O_FLASH_SR) & FLASH_SR_BSY_M;
    }
    while(BSYstatus == FLASH_SR_BSY_M);
}


//*****************************************************************************
//
//! Unlocks the Flash control register
//!
//! This function unlocks the Flash control register to allow modification.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_unLockCR(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Check if locked, if so perform unlock sequence
    //
    if((HWREG(base + XFLASHC_O_FLASH_CR) & FLASH_CR_LOCK_M) == FLASH_CR_LOCK_M)
    {
        //
        // Write first unlock key
        //
        HWREG(base + XFLASHC_O_FLASH_KEYR) = 0x45670123;

        //
        // Write second unlock key
        //
        HWREG(base + XFLASHC_O_FLASH_KEYR) = 0xCDEF89AB;
    }
}


//*****************************************************************************
//
//! Locks the Flash control register
//!
//! This function locks the Flash control register to prevent unauthorized modification.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_lockCR(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the lock bit to protect the control register
    //
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_LOCK_M;
}


//*****************************************************************************
//
//! Unlocks the Flash option control register
//!
//! This function unlocks the Flash option control register to allow modification of option bytes.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_unLockOPTCR(uint32_t base)
{
    XFLASHC_waitBSY(base);

    if((HWREG(base + XFLASHC_O_FLASH_OPTCR0) & FLASH_OPTCR0_OPTLOCK_M) == FLASH_OPTCR0_OPTLOCK_M)
    {
        HWREG(base + XFLASHC_O_FLASH_OPTKEYR) = 0x08192A3B;
        HWREG(base + XFLASHC_O_FLASH_OPTKEYR) = 0x4C5D6E7F;
    }
}


//*****************************************************************************
//
//! Locks the Flash option control register
//!
//! This function locks the Flash option control register to prevent unauthorized
//! modification of option bytes.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_lockOPTCR(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the option lock bit to protect the option control register
    //
    HWREG(base + XFLASHC_O_FLASH_OPTCR0) |= FLASH_OPTCR0_OPTLOCK_M;
}


//*****************************************************************************
//
//! Unlocks the Flash Program Erase Control Register
//!
//! This function unlocks the Flash Program Erase Control Register to allow
//! program and erase operations.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_unLockPECR(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Write unlock key to Program Erase Key Register
    //
    HWREG(base + XFLASHC_O_FLASH_PEKEYR) = 0xA9B8C7D6;
}


//*****************************************************************************
//
//! Unlocks the Flash Function Safety Control Register
//!
//! This function unlocks the Flash Function Safety Control Register to allow
//! access to function safety features.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_unLockFSCR(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Write unlock key to Function Safety Lock Register
    //
    HWREG(base + XFLASHC_O_FLASH_FSLOCK) = 0x5A5A5A5A;
}


//*****************************************************************************
//
//! Gets the OTP (One-Time Programmable) memory lock status
//!
//! This function reads and returns the current lock status of the OTP memory.
//!
//! \param base is the base address of the XFLASHC module.
//! \return The lock status of the OTP memory. 0 indicates locked, non-zero indicates unlocked.
//
//*****************************************************************************
static inline int
XFLASHC_getOTPStatus(uint32_t base)
{
    //
    // Read the OTP lock status from the OTP lock address
    //
    return *((volatile uint8_t *)OTP_LOCK_ADDR);
}


//*****************************************************************************
//
//! Locks the OTP (One-Time Programmable) memory
//!
//! This function locks the OTP memory to prevent further modifications.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_lockOTP(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Write 0x00 to OTP lock address to lock the OTP memory
    //
    *((volatile uint8_t *)OTP_LOCK_ADDR) = 0x00;
}


//*****************************************************************************
//
//! Unlocks the OTP (One-Time Programmable) memory
//!
//! This function unlocks the OTP memory to allow modifications.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_unLockOTP(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Write 0xFF to OTP lock address to unlock the OTP memory
    //
    *((volatile uint8_t *)OTP_LOCK_ADDR) = 0xFF;
}


//*****************************************************************************
//
//! Starts a Flash erase operation
//!
//! This function starts the Flash erase operation after the erase mode has been configured.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_startErase(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the START bit to initiate the erase operation
    //
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_START_M;
}


//*****************************************************************************
//
//! Sets the Page Erase address
//!
//! This function sets the address for page erase operation in the Flash controller.
//!
//! \param base is the base address of the XFLASHC module.
//! \param addr is the address to be set for page erase operation.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setPEAddr(uint32_t base, uint32_t addr)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the page erase address in the Program Erase Config Register
    //
    HWREG(base + XFLASHC_O_FLASH_PECFGR) = (HWREG(base + XFLASHC_O_FLASH_PECFGR) & (~FLASH_PECFGR_PE_ADDR_M)) | addr;
}


//*****************************************************************************
//
//! Performs a page erase operation on the Flash memory
//!
//! This function erases a single page of Flash memory at the specified address.
//! The address is automatically aligned to a 4KB boundary.
//!
//! \param base is the base address of the XFLASHC module.
//! \param addr is the address of the page to be erased.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_pageErase(uint32_t base, uint32_t addr)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Enable Page Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_PECFGR) |= FLASH_PECFGR_PE_EN_M;

    //
    // Align address to 4KB boundary and set the page erase address
    //
    addr = addr & (~0xFFF); /*align 4K*/
    XFLASHC_setPEAddr(base, addr);

    //
    // Ensure sector number bits are cleared
    //
#if  XFLASHC_HW_VER == 0x00
    HWREG(base + XFLASHC_O_FLASH_CR) = HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_SNB_M);
#elif  XFLASHC_HW_VER == 0x01
    HWREG(base + XFLASHC_O_FLASH_CR) = HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_SNB0_M) & (~FLASH_CR_SNB1_M);
#endif
    //
    // Enable Sector Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_SER_M;

    //
    // Start the erase operation
    //
    XFLASHC_startErase(base);

    //
    // Wait for erase operation to complete
    //
    XFLASHC_waitBSY(base);

    //
    // Disable Sector Erase mode and Page Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) &= ~FLASH_CR_SER_M;
    HWREG(base + XFLASHC_O_FLASH_PECFGR) &= ~FLASH_PECFGR_PE_EN_M;
}


//*****************************************************************************
//
//! Performs a sector erase operation on the Flash memory
//!
//! This function erases a specific sector of Flash memory specified by the sector number.
//!
//! \param base is the base address of the XFLASHC module.
//! \param sectorNum is the sector number to be erased.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_sectorErase(uint32_t base, FLASH_ERASE_SECTOR sectorNum)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Enable Sector Erase mode and set the sector number
    //
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_SER_M;
#if  XFLASHC_HW_VER == 0x00
    HWREG(base + XFLASHC_O_FLASH_CR) = (HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_SNB_M))
    								 | (sectorNum<<3);
#elif  XFLASHC_HW_VER == 0x01
    HWREG(base + XFLASHC_O_FLASH_CR) = (HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_SNB0_M) & (~FLASH_CR_SNB1_M))
    								 | (sectorNum<<3);
#endif
    XFLASHC_waitBSY(base);
    //
    // Start the erase operation
    //
    XFLASHC_startErase(base);

    //
    // Wait for erase operation to complete
    //
    XFLASHC_waitBSY(base);

    //
    // Disable Sector Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) &= ~FLASH_CR_SER_M;
}


//*****************************************************************************
//
//! Performs a full chip erase operation on the Flash memory
//!
//! This function erases the entire Flash memory chip.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_chipErase(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Enable Mass Erase (Chip Erase) mode
    //
#if XFLASHC_HW_VER == 0x00
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_MER_M;
#elif XFLASHC_HW_VER == 0x01
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_MER0_M;
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_MER1_M;
#endif

    //
    // Start the erase operation
    //
    XFLASHC_startErase(base);
    //
    // Wait for erase operation to complete
    //
    XFLASHC_waitBSY(base);

    //
    // Disable Mass Erase mode
    //
#if XFLASHC_HW_VER == 0x00
    HWREG(base + XFLASHC_O_FLASH_CR) &= ~FLASH_CR_MER_M;
#elif XFLASHC_HW_VER == 0x01
    HWREG(base + XFLASHC_O_FLASH_CR) &= ~FLASH_CR_MER0_M;
    HWREG(base + XFLASHC_O_FLASH_CR) &= ~FLASH_CR_MER1_M;
#endif
}

#if XFLASHC_HW_VER == 0x01
//*****************************************************************************
//
//! Performs Bank0 erase operation on the Flash memory
//!
//! This function erases the Flash Bank0 memory.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_Bank0Erase(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Enable Bank0 Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_MER0_M;

    //
    // Start the erase operation
    //
    XFLASHC_startErase(base);
    //
    // Wait for erase operation to complete
    //
    XFLASHC_waitBSY(base);

    //
    // Disable Bank0 Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) &= ~FLASH_CR_MER0_M;
}

//*****************************************************************************
//
//! Performs Bank1 erase operation on the Flash memory
//!
//! This function erases the Flash Bank1 memory.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_Bank1Erase(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Enable Bank1 Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_MER1_M;

    //
    // Start the erase operation
    //
    XFLASHC_startErase(base);
    //
    // Wait for erase operation to complete
    //
    XFLASHC_waitBSY(base);

    //
    // Disable Bank1 Erase mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) &= ~FLASH_CR_MER1_M;
}

#endif

//*****************************************************************************
//
//! Sets the Flash programming size
//!
//! This function configures the programming size for Flash write operations.
//!
//! \param base is the base address of the XFLASHC module.
//! \param psize is the programming size to be set.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setPgSize(uint32_t base, FLASH_PROGRAM_SIZE psize)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the programming size in the Flash Control Register
    //
    HWREG(base + XFLASHC_O_FLASH_CR) = (HWREG(base + XFLASHC_O_FLASH_CR) & ~FLASH_CR_PSIZE_M)
                                       | (psize << FLASH_CR_PSIZE_S);
}


//*****************************************************************************
//
//! Enables Flash programming mode
//!
//! This function enables the Flash programming mode to allow write operations to the Flash memory.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_enableProgram(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the PG bit to enable programming mode
    //
    HWREG(base + XFLASHC_O_FLASH_CR) |= FLASH_CR_PG_M;
}


//*****************************************************************************
//
//! Starts the Flash option bytes programming operation
//!
//! This function starts the option bytes programming operation after the option bytes have been configured.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_startOPT(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the OPTSTART bit to initiate the option bytes programming
    //
    HWREG(base + XFLASHC_O_FLASH_OPTCR0) |= FLASH_OPTCR0_OPTSTART_M;

    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);
}


//*****************************************************************************
//
//! Sets the special protection mode for Flash option bytes
//!
//! This function configures the special protection mode for the Flash option bytes,
//! either write protection or PCROP (Proprietary Code Readout Protection).
//!
//! \param base is the base address of the XFLASHC module.
//! \param mode is the special protection mode to be set (WIRTEP or PCROP).
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setSPRMOD(uint32_t base, FLASH_SPRMOD mode)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the special protection mode based on the input parameter
    //
    if(mode == WIRTEP)
    {
        HWREG(base + XFLASHC_O_FLASH_OPTCR0) = (HWREG(base + XFLASHC_O_FLASH_OPTCR0) & (~FLASH_OPTCR0_SPRMOD_M))
                                             | (0);
    }
    else if(mode == PCROP)
    {
        //
        // Set PCROP (Proprietary Code Readout Protection) mode
        //
        HWREG(base + XFLASHC_O_FLASH_OPTCR0) = (HWREG(base + XFLASHC_O_FLASH_OPTCR0) & (~FLASH_OPTCR0_SPRMOD_M))
                                             | (FLASH_OPTCR0_SPRMOD_M);
    }
}

#if XFLASHC_HW_VER == 0x00
//*****************************************************************************
//
//! Configures the Write Protection (WRP) for Flash sectors
//!
//! This function configures write protection for specified sectors in Flash memory.
//! It supports both write protection mode and PCROP (Proprietary Code Readout Protection)
//! mode depending on the SPRMOD bit setting.
//!
//! \param base is the base address of the XFLASHC module.
//! \param sectorAID is the sector mask for group A sectors (0-11).
//! \param sectorBID is the sector mask for group B sectors (12-27).
//! \param status is the protection status (ENABLE or DISABLE).
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setWRP
(uint32_t base, FLASH_SECTOR_A sectorAID, FLASH_SECTOR_B sectorBID, FunctionalState status)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Check if PCROP mode is active
    //
    if((HWREG(base + XFLASHC_O_FLASH_OPTCR0) & FLASH_OPTCR0_SPRMOD_M) == FLASH_OPTCR0_SPRMOD_M)
    {
        //
        // Configure PCROP (Protected Content Readout Protection)
        //
        if(status == ENABLE)
        {
            //
            // Enable PCROP for the specified sectors
            //
            HWREG(base + XFLASHC_O_FLASH_OPTCR0) = (HWREG(base + XFLASHC_O_FLASH_OPTCR0) & ~FLASH_OPTCR0_nWRP_M)
                                                       | (sectorAID << FLASH_OPTCR0_nWRP_S);
            HWREG(base + XFLASHC_O_FLASH_OPTCR1) = (HWREG(base + XFLASHC_O_FLASH_OPTCR1) & ~FLASH_OPTCR1_nWRP_M)
                                                       | (sectorBID << FLASH_OPTCR1_nWRP_S);
        }else if(status == DISABLE)
        {
            //
            // Disable PCROP for the specified sectors
            //
            HWREG(base + XFLASHC_O_FLASH_OPTCR0) = (HWREG(base + XFLASHC_O_FLASH_OPTCR0) & ~FLASH_OPTCR0_nWRP_M)
                                                       | ((~sectorAID & 0xFFF) << FLASH_OPTCR0_nWRP_S);
            HWREG(base + XFLASHC_O_FLASH_OPTCR1) = (HWREG(base + XFLASHC_O_FLASH_OPTCR1) & ~FLASH_OPTCR1_nWRP_M)
                                                       | ((~sectorBID & 0xFFF) << FLASH_OPTCR1_nWRP_S);
        }
    }
    else
    {
        //
        // Write PROTECT
        //
        if(status == DISABLE)
        {
            //
            // Disable write protection for the specified sectors
            //
            HWREG(base + XFLASHC_O_FLASH_OPTCR0) = (HWREG(base + XFLASHC_O_FLASH_OPTCR0) & (~FLASH_OPTCR0_nWRP_M))
                                                       | (sectorAID << FLASH_OPTCR0_nWRP_S);
            HWREG(base + XFLASHC_O_FLASH_OPTCR1) = (HWREG(base + XFLASHC_O_FLASH_OPTCR1) & (~FLASH_OPTCR1_nWRP_M))
                                                       | (sectorBID << FLASH_OPTCR1_nWRP_S);
        }else if(status == ENABLE)
        {
            //
            // Enable write protection for the specified sectors
            //
            HWREG(base + XFLASHC_O_FLASH_OPTCR0) = (HWREG(base + XFLASHC_O_FLASH_OPTCR0) & (~FLASH_OPTCR0_nWRP_M))
                                                       | ((~sectorAID & 0xFFF) << FLASH_OPTCR0_nWRP_S);
            HWREG(base + XFLASHC_O_FLASH_OPTCR1) = (HWREG(base + XFLASHC_O_FLASH_OPTCR1) & (~FLASH_OPTCR1_nWRP_M))
                                                       | ((~sectorBID & 0xFFF) << FLASH_OPTCR1_nWRP_S);
        }
    }
}
#elif XFLASHC_HW_VER == 0x01
//*****************************************************************************
//
//! Configures the Write Protection (WRP) for Flash sectors
//!
//! This function configures write protection for specified sectors in Flash memory.
//! It supports both write protection mode and PCROP (Proprietary Code Readout Protection)
//! mode depending on the SPRMOD bit setting.
//!
//! \param base is the base address of the XFLASHC module.
//! \param sectorID is a array about sectors   (0-131).
//! \param sectorNum is the number of sectorID (0-131).
//! \param status is the protection status (ENABLE or DISABLE).
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setWRP
(uint32_t base, uint32_t *sectorID, uint32_t sectorNum, FunctionalState status)
{
	uint32_t i;
	uint32_t reg;
	uint32_t regMsk;
	uint32_t regPos;
	uint32_t regVal;

    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

	for(i=0;i++;i<sectorNum)
	{
		if(sectorID[i] <= 11)
		{
			reg = XFLASHC_O_FLASH_OPTCR0_MIR;
			regMsk = FLASH_OPTCR0_MIR_nWRP_M;
			regPos = FLASH_OPTCR0_MIR_nWRP_S;
			regVal = sectorID[i];
		}else if(sectorID[i] <= 43)
		{
			reg = XFLASHC_O_FLASH_OPTCR1_MIR;
			regMsk = FLASH_OPTCR1_MIR_nWRP_S;
			regPos = FLASH_OPTCR1_MIR_nWRP_S;
			regVal = sectorID[i] - 12;
		}else if(sectorID[i] <= 75)
		{
			reg = XFLASHC_O_FLASH_OPTCR2;
			regMsk = FLASH_OPTCR2_nWRP_M;
			regPos = FLASH_OPTCR2_nWRP_S;
			regVal = sectorID[i] - 44;
		}else if(sectorID[i] <= 108)
		{
			reg = XFLASHC_O_FLASH_OPTCR3;
			regMsk = FLASH_OPTCR3_nWRP_M;
			regPos = FLASH_OPTCR3_nWRP_S;
			regVal = sectorID[i] - 76;
		}else if(sectorID[i] <= 131)
		{
			reg = XFLASHC_O_FLASH_OPTCR4;
			regMsk = FLASH_OPTCR4_nWRP_M;
			regPos = FLASH_OPTCR4_nWRP_S;
			regVal = sectorID[i] - 109;
		}
		//
		// Check if PCROP mode is active
		//
		if((HWREG(base + XFLASHC_O_FLASH_OPTCR0) & FLASH_OPTCR0_SPRMOD_M) == FLASH_OPTCR0_SPRMOD_M)
		{
			//
			// Configure PCROP (Protected Content Readout Protection)
			//
			if(status == ENABLE)
			{
				//
				// Enable PCROP for the specified sectors
				//
				HWREG(base + reg) = (HWREG(base + reg) & ~regMsk) | (regVal << regPos);
			}else if(status == DISABLE)
			{
				//
				// Disable PCROP for the specified sectors
				//
				HWREG(base + reg) = (HWREG(base + reg) & ~regMsk) | ((~regVal) << regPos);
			}
		}
		else
		{
			//
			// Write PROTECT
			//
			if(status == DISABLE)
			{
				//
				// Disable write protection for the specified sectors
				//
				HWREG(base + reg) = (HWREG(base + reg) & ~regMsk) | (regVal << regPos);
			}else if(status == ENABLE)
			{
				//
				// Enable write protection for the specified sectors
				//
				HWREG(base + reg) = (HWREG(base + reg) & ~regMsk) | ((~regVal) << regPos);
			}
		}
	}
}
#endif

//*****************************************************************************
//
//! Sets the Read Protection (RDP) level for Flash memory
//!
//! This function configures the Read Protection level for the Flash memory, which
//! controls the ability to read the Flash memory content via debug interfaces.
//!
//! \param base is the base address of the XFLASHC module.
//! \param level is the read protection level to be set.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setRDP(uint32_t base, FLASH_RDP_LEVEL level)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the Read Protection level in the OPTCR0 register
    //
    HWREG(base + XFLASHC_O_FLASH_OPTCR0) = (HWREG(base + XFLASHC_O_FLASH_OPTCR0) & (~FLASH_OPTCR0_RDP_M))
                                                               | (level << FLASH_OPTCR0_RDP_S);
}

//*****************************************************************************
//
//! Programs data into Flash memory
//!
//! This function programs data into the Flash memory at the specified offset
//! using the provided programming size (8-bit, 16-bit, or 32-bit).
//!
//! \param base is the base address of the XFLASHC module.
//! \param psize is the programming size (PROGRAMSIZE8, PROGRAMSIZE16, or PROGRAMSIZE32).
//! \param offset is the offset from XFLASHC_BASE where programming starts.
//! \param txBuffer is the pointer to the data buffer to be programmed.
//! \param bufferSize is the size of the data buffer in bytes.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_program(uint32_t base, FLASH_PROGRAM_SIZE psize, uint32_t offset, uint8_t *txBuffer, uint32_t bufferSize)
{
    uint32_t i = 0;
    uint32_t address = XFLASHC_BASE + offset;

    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);
    //
    // Enable program Flash
    //
    XFLASHC_enableProgram(base);

    //
    // Set the programming size for Flash operations
    //
    XFLASHC_setPgSize(base, psize);

    //
    // Program data based on the selected programming size
    //
    switch(psize)
    {
    case PROGRAMSIZE8:
        //
        // 8-bit programming mode
        // Program each byte individually
        //
        for(i = 0; i < bufferSize; i++)
        {
            XFLASHC_waitBSY(base);
            *((volatile uint8_t *)(address + i)) = *(uint8_t *)(txBuffer + i);
        }
        break;
    case PROGRAMSIZE16:
        //
        // 16-bit programming mode，Program data in 16-bit chunks
        //
        for(i = 0; i < bufferSize; i += 2)
        {
            XFLASHC_waitBSY(base);
            *((volatile uint16_t *)(address + i)) = *(uint16_t *)(txBuffer + i);
        }
        break;
    case PROGRAMSIZE32:
        //
        // 32-bit programming mode，Program data in 32-bit chunks
        //
        for(i = 0; i < bufferSize; i += 4)
        {
            XFLASHC_waitBSY(base);
            *((volatile uint32_t *)(address + i)) = *(uint32_t*)(txBuffer + i);
        }
        break;
    case PROGRAMSIZE64:
        for(i = 0;i < bufferSize;i += 8)
        {
            *(volatile uint32_t *)(address + i)      = *(uint32_t*)(txBuffer + i);
            *(volatile uint32_t *)(address + i + 4)      = *(uint32_t*)(txBuffer + i + 4);
            XFLASHC_waitBSY(base);
        }
        break;
    case PROGRAMSIZE128:
        for(i = 0;i < bufferSize;i += 16)
        {
            XFLASHC_waitBSY(base);
            *(volatile uint32_t *)(address + i)      = *(uint32_t*)(txBuffer + i);
            *(volatile uint32_t *)(address + i + 4)  = *(uint32_t*)(txBuffer + i + 4);
            *(volatile uint32_t *)(address + i + 8)  = *(uint32_t*)(txBuffer + i + 8);
            *(volatile uint32_t *)(address + i + 12) = *(uint32_t*)(txBuffer + i + 12);
        }
        break;
    default:
        break;
    }
    XFLASHC_waitBSY(base);
}

//*****************************************************************************
//
//! Reads data from Flash memory in 8-bit mode
//!
//! This function reads data from Flash memory at the specified offset into the
//! provided buffer in 8-bit chunks.
//!
//! \param base is the base address of the XFLASHC module.
//! \param offset is the offset from XFLASHC_BASE where reading starts.
//! \param rxBuffer is the pointer to the buffer to store read data.
//! \param dataSize is the size of data to read in bytes.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_read8Bits(uint32_t base, uint32_t offset, uint8_t* rxBuffer, uint32_t dataSize)
{
    uint32_t i = 0;
    uint32_t address = XFLASHC_BASE + offset;

    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Read data byte by byte from Flash memory
    //
    for(i = 0; i < dataSize; i++)
    {
        *(rxBuffer + i) = *((volatile uint8_t *)(address + i));
    }
}

//*****************************************************************************
//
//! Gets the Flash start mode
//!
//! This function retrieves the Flash start mode, which indicates how the device
//! was started (e.g., from Flash, bootloader, etc.).
//!
//! \param base is the base address of the XFLASHC module.
//! \return The Flash start mode.
//
//*****************************************************************************
static inline FLASH_START_MODE
XFLASHC_getStartMode(uint32_t base)
{
    FLASH_START_MODE mode;

    return mode;
}

//*****************************************************************************
//
//! Inserts an error into Flash function safety module
//!
//! This function inserts an error into the Flash function safety module for
//! testing purposes. It allows testing of error detection mechanisms.
//!
//! \param base is the base address of the XFLASHC module.
//! \param regID is the register ID where the error should be inserted.
//! \param invBit is the invalid bit pattern to be inserted.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_errorInsert(uint32_t base, uint32_t regID, uint32_t invBit)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Clear the TARGET bit in the function safety control register
    //
    HWREG(base + XFLASHC_O_FLASH_FSCTRL) = HWREG(base + XFLASHC_O_FLASH_FSCTRL) & (~FLASH_FSCTRL_TARGET_M);

    //
    // Set the register ID for error insertion
    //
    HWREG(base + XFLASHC_O_FLASH_FSCTRL) = (HWREG(base + XFLASHC_O_FLASH_FSCTRL) & (~FLASH_FSCTRL_ID_M))
                                         | (regID << FLASH_FSCTRL_ID_S);

    //
    // Unlock the function safety control register
    //
    XFLASHC_unLockFSCR(base);

    //
    // Write the invalid bit pattern to trigger the error
    //
    HWREG(base + XFLASHC_O_FLASH_FSDATA) = invBit;
}

//*****************************************************************************
//
//! Gets the parity check result from Flash function safety module
//!
//! This function retrieves the parity check result from the Flash function safety module,
//! which indicates whether any parity errors have been detected.
//!
//! \param base is the base address of the XFLASHC module.
//! \return The parity check result value.
//
//*****************************************************************************
static inline int
XFLASHC_getParityCheckResult(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Clear the TARGET bit to access parity check results
    //
    HWREG(base + XFLASHC_O_FLASH_FSCTRL) = HWREG(base + XFLASHC_O_FLASH_FSCTRL) & (~FLASH_FSCTRL_TARGET_M);

    //
    // Return the parity check result from the function safety info register
    //
    return (HWREG(base + XFLASHC_O_FLASH_FSINFO));
}

//*****************************************************************************
//
//! Gets detailed parity check information from Flash function safety module
//!
//! This function retrieves detailed information about parity check errors
//! from the Flash function safety module, including error locations.
//!
//! \param base is the base address of the XFLASHC module.
//! \return The detailed parity check information value.
//
//*****************************************************************************
static inline int
XFLASHC_getParityCheckINFO(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the TARGET bit to access detailed parity check information
    //
    HWREG(base + XFLASHC_O_FLASH_FSCTRL) = (HWREG(base + XFLASHC_O_FLASH_FSCTRL) & (~FLASH_FSCTRL_TARGET_M))
                                         | FLASH_FSCTRL_TARGET_M;

    //
    // Return the detailed parity check information from the function safety info register
    //
    return (HWREG(base + XFLASHC_O_FLASH_FSINFO));
}

//*****************************************************************************
//
//! Clears the Flash CRC result register
//!
//! This function clears the CRC result register to prepare for a new CRC calculation.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_clearCRC(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the CLEAN_CRC bit to clear the CRC result register
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) = (HWREG(base + XFLASHC_O_FLASH_CRCCR) & (~FLASH_CRCCR_CLEAN_CRC_M))
                                                | (FLASH_CRCCR_CLEAN_CRC_M);;
}

//*****************************************************************************
//
//! Calculates CRC for a specified address range in Flash memory
//!
//! This function performs a CRC calculation over a specified address range
//! in Flash memory and stores the result in the CRC result register.
//!
//! \param base is the base address of the XFLASHC module.
//! \param startAddr is the starting address for CRC calculation.
//! \param endAddr is the ending address for CRC calculation.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_addrCRC(uint32_t base, uint32_t startAddr, uint32_t endAddr)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Clear previous CRC result
    //
    XFLASHC_clearCRC(base);

    //
    // Enable address CRC mode (disable sector mode)
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) = (HWREG(base + XFLASHC_O_FLASH_CRCCR) & (~FLASH_CRCCR_CRC_BY_SECT_M))
                                        | (0);

    //
    // Set start and end address for CRC calculation
    //
    HWREG(base + XFLASHC_O_FLASH_CRCSAR) = (startAddr);
    HWREG(base + XFLASHC_O_FLASH_CRCEAR) = (endAddr);

    //
    // Start the CRC calculation
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) |= FLASH_CRCCR_START_CRC_M;

    //
    // Wait for CRC calculation to complete
    //
    XFLASHC_waitBSY(base);
}

//*****************************************************************************
//
//! Calculates CRC for a specified Flash sector
//!
//! This function performs a CRC calculation on a specific Flash sector or
//! sector address range based on the configuration.
//!
//! \param base is the base address of the XFLASHC module.
//! \param sectorNum is the sector number for CRC calculation.
//! \param addStatus indicates whether to enable sector address mode.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_sectorCRC(uint32_t base, FLASH_CRC_SECTOR sectorNum, FLASH_CRC_SECTORADD addStatus)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Clear previous CRC result
    //
    XFLASHC_clearCRC(base);

    //
    // Enable sector CRC mode
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) = (HWREG(base + XFLASHC_O_FLASH_CRCCR) & (~FLASH_CRCCR_CRC_BY_SECT_M))
                                        | (FLASH_CRCCR_CRC_BY_SECT_M);

    //
    // Configure sector address status
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) = (HWREG(base + XFLASHC_O_FLASH_CRCCR) & (~FLASH_CRCCR_ADD_SECT_M))
                                        | (addStatus);

    //
    // If sector address mode is disabled, set the specific sector number
    //
    if(addStatus == DISABLE_SADD)
    {
        //
        // Set the sector number for CRC calculation
        //
        HWREG(base + XFLASHC_O_FLASH_CRCCR) = (HWREG(base + XFLASHC_O_FLASH_CRCCR) & (~FLASH_CRCCR_SECT_M))
                                            | (sectorNum);
    }

    //
    // Start the CRC calculation
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) |= FLASH_CRCCR_START_CRC_M;

    //
    // Wait for CRC calculation to complete
    //
    XFLASHC_waitBSY(base);
}

//*****************************************************************************
//
//! Calculates CRC for all Flash sectors
//!
//! This function performs a CRC calculation on all Flash sectors to verify
//! the integrity of the entire Flash memory.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_allCRC(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Clear previous CRC result
    //
    XFLASHC_clearCRC(base);

    //
    // Enable sector CRC mode
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) = (HWREG(base + XFLASHC_O_FLASH_CRCCR) & (~FLASH_CRCCR_CRC_BY_SECT_M))
                                        | (FLASH_CRCCR_CRC_BY_SECT_M);

    //
    // Enable all sectors for CRC calculation
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) = (HWREG(base + XFLASHC_O_FLASH_CRCCR) & (~FLASH_CRCCR_ALL_SECT_M))
                                        | (FLASH_CRCCR_ALL_SECT_M);

    //
    // Start the CRC calculation
    //
    HWREG(base + XFLASHC_O_FLASH_CRCCR) |= FLASH_CRCCR_START_CRC_M;

    //
    // Wait for CRC calculation to complete
    //
    XFLASHC_waitBSY(base);
}

//*****************************************************************************
//
//! Retrieves the CRC calculation result
//!
//! This function reads and returns the result of the most recent CRC calculation
//! from the CRC data register.
//!
//! \param base is the base address of the XFLASHC module.
//! \return The CRC calculation result as a 32-bit value.
//
//*****************************************************************************
static inline uint32_t
XFLASHC_getCRC(uint32_t base)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Return the CRC result from the CRC data register
    //
    return HWREG(base + XFLASHC_O_FLASH_CRCDR);
}

//*****************************************************************************
//
//! Configures the End of Operation (EOP) interrupt
//!
//! This function enables or disables the End of Operation interrupt, which is
//! triggered when a Flash operation (programming or erasing) is completed.
//!
//! \param base is the base address of the XFLASHC module.
//! \param status is the interrupt status (ENABLE or DISABLE).
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setEOPINT(uint32_t base, FunctionalState status)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Configure the EOP interrupt based on the status parameter
    //
    if(status == ENABLE)
    {
        //
        // Enable the EOP interrupt
        //
        HWREG(base + XFLASHC_O_FLASH_CR) = (HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_EOPIE_M))
                                         | (FLASH_CR_EOPIE_M);
    }
    else
    {
        //
        // Disable the EOP interrupt
        //
        HWREG(base + XFLASHC_O_FLASH_CR) = (HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_EOPIE_M))
                                         | (0);
    }
}

//*****************************************************************************
//
//! Configures the Error interrupt
//!
//! This function enables or disables the Error interrupt, which is triggered
//! when a Flash operation encounters an error during programming or erasing.
//!
//! \param base is the base address of the XFLASHC module.
//! \param status is the interrupt status (ENABLE or DISABLE).
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setERRINT(uint32_t base, FunctionalState status)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Configure the Error interrupt based on the status parameter
    //
    if(status == ENABLE)
    {
        //
        // Enable the Error interrupt
        //
        HWREG(base + XFLASHC_O_FLASH_CR) = (HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_ERRIE_M))
                                         | (FLASH_CR_ERRIE_M);
    }
    else
    {
        //
        // Disable the Error interrupt
        //
        HWREG(base + XFLASHC_O_FLASH_CR) = (HWREG(base + XFLASHC_O_FLASH_CR) & (~FLASH_CR_ERRIE_M))
                                         | (0);
    }

}

//*****************************************************************************
//
//! Clear WRPERR Interrupt flag of FLASH
//!
//! This function will clear WRPERR Interrupt flag of FLASH.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_clearWRPERR(uint32_t base)
{
    HWREG(base + XFLASHC_O_FLASH_SR) = HWREG(base + XFLASHC_O_FLASH_SR) | FLASH_SR_OPERR_M;
    HWREG(base + XFLASHC_O_FLASH_SR) = HWREG(base + XFLASHC_O_FLASH_SR) | FLASH_SR_WRPERR_M;
}

//*****************************************************************************
//
//! Clear RDERR Interrupt flag of FLASH
//!
//! This function will clear RDERR Interrupt flag of FLASH.
//!
//! \param base is the base address of the XFLASHC module.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_clearRDERR(uint32_t base)
{
    HWREG(base + XFLASHC_O_FLASH_SR) = HWREG(base + XFLASHC_O_FLASH_SR) | FLASH_SR_OPERR_M;
    HWREG(base + XFLASHC_O_FLASH_SR) = HWREG(base + XFLASHC_O_FLASH_SR) | FLASH_SR_RDERR_M;
}
//*****************************************************************************
//
//! Configures the Flash controller clock divider
//!
//! This function sets the clock divider for the Flash controller to control
//! the access speed to the Flash memory.
//!
//! \param base is the base address of the XFLASHC module.
//! \param div is the clock divider value to be set.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setCLK(uint32_t base, uint32_t div)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the clock divider value in the Flash clock divider register
    //
    HWREG(base + XFLASHC_O_FLASH_CKDIVR) = div;
}

//*****************************************************************************
//
//! Configures the Flash read sample delay and edge
//!
//! This function sets the read sample edge (polarity) and read sample delay (RSD)
//! for Flash memory access to optimize reading operations at different clock speeds.
//!
//! \param base is the base address of the XFLASHC module.
//! \param polarity is the read sample edge (polarity) value.
//! \param RSD is the read sample delay value to be set.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setSampleDelay(uint32_t base, uint32_t polarity, uint32_t RSD)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Set the read sample edge (polarity) in the Flash sample delay register
    //
    HWREG(base + XFLASHC_O_FLASH_SAMPLE_DELAY) = (HWREG(base + XFLASHC_O_FLASH_SAMPLE_DELAY) & (~FLASH_SAMPLE_DELAY_SE_M))
                                               | (polarity);

    //
    // Set the read sample delay (RSD) in the Flash sample delay register
    //
    HWREG(base + XFLASHC_O_FLASH_SAMPLE_DELAY) = (HWREG(base + XFLASHC_O_FLASH_SAMPLE_DELAY) & (~FLASH_SAMPLE_DELAY_RSD_M))
                                               | (RSD);
}

//*****************************************************************************
//
//! Configures the Option Byte source
//!
//! This function selects the source for the option bytes between the system
//! control module (SYSCTL) and the Flash controller.
//!
//! \param base is the base address of the XFLASHC module.
//! \param source is the option byte source to be selected (SYSCTCL_OB or EXFLASHC_OB).
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setOBSourece(uint32_t base, SysCtl_OBSourece source)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Select the option byte source based on the input parameter
    //
    SysCtl_setOBSource(source);
}

//*****************************************************************************
//
//! Configures the Zero Wait State area
//!
//! This function enables or disables the Zero Wait State area and sets its size
//! to improve Flash memory access performance for critical code sections.
//!
//! \param base is the base address of the XFLASHC module.
//! \param status is the Zero Wait State area status (ENABLE or DISABLE).
//! \param size is the size of the Zero Wait State area to be configured.
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_setZeroWaitArea(uint32_t base, FunctionalState status, ZeroWaitAreaSIZE size)
{
    //
    // Wait for Flash controller to be not busy
    //
    XFLASHC_waitBSY(base);

    //
    // Configure Zero Wait State area based on the status parameter
    //
    if(status == ENABLE)
    {
        //
        // Enable Zero Wait State area
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) &= (~0x0800);
        //
        // Enable Zero Wait State area loading
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) |= 0x1000;
    }
    else
    {
        //
        // Disable Zero Wait State area
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) |= 0x0800;
        //
        // Disable Zero Wait State area loading
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) &= (~0x1000);
    }

    //
    // Set the size of the Zero Wait State area
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) &= (~0xE000);
    switch(size)
    {
    case(SIZE4B):
        //
        // Set Zero Wait State area size to 4KB
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) |= 0x0000;
        break;
    case(SIZE64KB):
        //
        // Set Zero Wait State area size to 64KB
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) |= 0x2000;
        break;
    case(SIZE128KB):
        //
        // Set Zero Wait State area size to 128KB
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) |= 0x4000;
        break;
    case(SIZE256KB):
        //
        // Set Zero Wait State area size to 256KB
        //
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) |= 0x8000;
        break;
    default:
        //
        // Default case: No change to Zero Wait State area size
        //
        break;
    }

}

//*****************************************************************************
//
//! Waits for Zero Wait State area to be ready
//!
//! This function waits until the Zero Wait State area is ready for operation
//! by polling the ready status bit in the system register.
//!
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_waitZWReady(void)
{
    uint32_t buffer;

    //
    // Wait until Zero Wait State area is ready
    //
    while(1)
    {
        //
        // Read the Zero Wait State ready bit from the system register
        //
        buffer = HWREG(0xe1000008) & (0x1);

        //
        // Check if Zero Wait State area is ready (bit set to 1)
        //
        if(buffer == 1)break;
    }

}

//*****************************************************************************
//
//! Configures the Secure Memory Controller Module (SMCM)
//!
//! This function configures the Secure Memory Controller Module and allocates
//! zero-wait state RAM space for secure memory operations.
//!
//! \return None.
//
//*****************************************************************************
static inline void
XFLASHC_smcmConfig(void)
{
    //
    // Write magic number to SMCM configuration register
    //
    HWREG(0x23009000) = 0xdeadbeef;

    //
    // Configure the zero-wait state RAM space size (16KB) while preserving lower bits
    //
    HWREG(0x23009004) = 0x00043333;

    //
    // Enable the SMCM configuration by setting the enable bit
    //
    HWREG(0x23009018) |= 0x00000001;
}

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // XFLASHC_H

