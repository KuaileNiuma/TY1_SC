/** 
  *************************************************************************************
  * @file alb32r003x_sector.h 
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

#ifndef __ALB32R003X_SECTOR_H
#define __ALB32R003X_SECTOR_H
#include "device.h"


//flash bank number,flash control number
#define FlashBankNumber			2U

//base addr
#define Bzero_MainBaseAddr		EFLASH_BASE
#define Bzero_MainEndAddr		EFLASH_END
#define Bzero_MainSize			(Bzero_MainEndAddr - Bzero_MainBaseAddr + 1)
#define Bzero_InfoBaseAddr		0x1FFF7800U
#define Bzero_InfoEndAddr		0x1FFFC3FFU
#define Bone_MainBaseAddr		XFLASH_BASE
#define Bone_MainEndAddr		XFLASH_END



// Bank0 Sector start addresses
#define     Bzero_Sector0_start         (EFLASH_BASE+0x0000U)
#define     Bzero_Sector1_start         (EFLASH_BASE+0x20000U)
#define     Bzero_Sector2_start         (EFLASH_BASE+0x40000U)
#define     Bzero_Sector3_start         (EFLASH_BASE+0x60000U)

// Bank1 Sector start addresses
#define     Bone_Sector0_start         ((uint32_t)XFLASH_BASE + 0x0000)     /*offset 0x00, size 0x4000*/
#define     Bone_Sector1_start         ((uint32_t)XFLASH_BASE + 0x4000)     /*offset 0x4000,16K*/
#define     Bone_Sector2_start         ((uint32_t)XFLASH_BASE + 0x8000)     /*offset 0x8000,16K*/
#define     Bone_Sector3_start         ((uint32_t)XFLASH_BASE + 0xC000)     /*offset 0xc000,16K*/
#define     Bone_Sector4_start         ((uint32_t)XFLASH_BASE + 0x10000)    /*size 0x10000,64K*/
#define     Bone_Sector5_start         ((uint32_t)XFLASH_BASE + 0x20000)    /*offset 0x20000,128K*/
#define     Bone_Sector6_start         ((uint32_t)XFLASH_BASE + 0x40000)    /*offset 0x40000,128K*/
#define     Bone_Sector7_start         ((uint32_t)XFLASH_BASE + 0x60000)    /*offset 0x60000,128K*/
#define     Bone_Sector8_start         ((uint32_t)XFLASH_BASE + 0x80000)    /*offset 0x80000,128K*/
#define     Bone_Sector9_start         ((uint32_t)XFLASH_BASE + 0xA0000)    /*offset 0xA0000,128K*/
#define     Bone_Sector10_start        ((uint32_t)XFLASH_BASE + 0xC0000)    /*offset 0xC0000,128K*/
#define     Bone_Sector11_start        ((uint32_t)XFLASH_BASE + 0xE0000)    /*offset 0xE0000,128K*/
#define     Bone_Sector12_start        ((uint32_t)XFLASH_BASE + 0x100000)    /*offset 0x100000,256K*/
#define     Bone_Sector13_start        ((uint32_t)XFLASH_BASE + 0x140000)    /*offset 0x140000,256K*/
#define     Bone_Sector14_start        ((uint32_t)XFLASH_BASE + 0x180000)    /*offset 0x180000,256K*/
#define     Bone_Sector15_start        ((uint32_t)XFLASH_BASE + 0x1C0000)    /*offset 0x1C0000,256K*/
#define     Bone_Sector16_start        ((uint32_t)XFLASH_BASE + 0x200000)    /*offset 0x200000,512K*/
#define     Bone_Sector17_start        ((uint32_t)XFLASH_BASE + 0x280000)    /*offset 0x280000,512K*/
#define     Bone_Sector18_start        ((uint32_t)XFLASH_BASE + 0x300000)    /*offset 0x300000,512K*/
#define     Bone_Sector19_start        ((uint32_t)XFLASH_BASE + 0x380000)    /*offset 0x380000,512K*/
#define     Bone_Sector20_start        ((uint32_t)XFLASH_BASE + 0x400000)    /*offset 0x400000,512K*/
#define     Bone_Sector21_start        ((uint32_t)XFLASH_BASE + 0x480000)    /*offset 0x480000,512K*/
#define     Bone_Sector22_start        ((uint32_t)XFLASH_BASE + 0x500000)    /*offset 0x500000,512K*/
#define     Bone_Sector23_start        ((uint32_t)XFLASH_BASE + 0x580000)    /*offset 0x580000,512K*/
#define     Bone_Sector24_start        ((uint32_t)XFLASH_BASE + 0x600000)    /*offset 0x600000,512K*/
#define     Bone_Sector25_start        ((uint32_t)XFLASH_BASE + 0x680000)    /*offset 0x680000,512K*/
#define     Bone_Sector26_start        ((uint32_t)XFLASH_BASE + 0x700000)    /*offset 0x700000,512K*/
#define     Bone_Sector27_start        ((uint32_t)XFLASH_BASE + 0x780000)    /*offset 0x780000,512K*/


#endif
