/** 
  ************************************************************************************* 
  * @file hw_dmasch.h 
  * @brief This file contains the definition of hw_dmasch driver. 
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

#ifndef _HW_DMASCH_H_
#define _HW_DMASCH_H_

/* ========================================================================== */
/* ================                   DMASCH                 ================ */
/* ========================================================================== */

#define DMASCH_GEN_NUM 8  //TODO
#define DMASCH_MUX_NUM 32 //TODO
typedef struct
{
    __IOM uint32_t   GCR;             /* offset: 0x000 (R/W) GEN configuration register of channel x */
} DMASCH_GEN_TypeDef;

typedef struct
{
    __IOM uint32_t   MCR;             /* offset: 0x080 (R/W) MUX configuration register of channel x */
} DMASCH_MUX_TypeDef;

typedef struct
{
    DMASCH_GEN_TypeDef GenCfg[DMASCH_GEN_NUM];               /* Generator Configuration              */
          uint32_t reserved1[8];                /* offset: 0x020-0x03C           Reserved Registers  */
    __IOM uint32_t GISR;               /* offset: 0x040 (R/W) GEN interrupt status register          */
    __IOM uint32_t GICR;               /* offset: 0x044 (R/W) GEN interrupt clear register           */
    __IOM uint32_t GSTR;               /* offset: 0x048 (R/W) GEN software trigger register          */
          uint32_t reserved2[13];               /* offset: 0x04C-0x07C         Reserved Registers    */
    DMASCH_MUX_TypeDef  MuxCfg[DMASCH_MUX_NUM];            /* Multiplexer Configuration              */
    __IOM uint32_t MISR;               /* offset: 0x100 (R/W) MUX interrupt status register          */
    __IOM uint32_t MICR;               /* offset: 0x104 (R/W) MUX interrupt clear register           */
} DMASCH_TypeDef;

#define DMASCH              ((DMASCH_TypeDef*) DMASCH_BASE)

/* DMASCH register bit definitions */
/* ==========================         GCR         ============================ */
#define DMASCH_GCR_TRG_S            (0UL)
#define DMASCH_GCR_TRG_M            (0xFFUL)

#define DMASCH_GCR_TOIE_S           (8UL)
#define DMASCH_GCR_TOIE_M           (0x100UL)
#define DMASCH_GCR_TOIE_ENABLE        (0x100UL)
#define DMASCH_GCR_TOIE_DISABLE       (0x000UL)

#define DMASCH_GCR_SINGLEE_S           (9UL)
#define DMASCH_GCR_SINGLEE_M           (0x200UL)
#define DMASCH_GCR_SINGLEE_ENABLE        (0x200UL)
#define DMASCH_GCR_SINGLEE_DISABLE       (0x000UL)

#define DMASCH_GCR_TPOL_S           (10UL)
#define DMASCH_GCR_TPOL_M           (0xC00UL)
#define DMASCH_GCR_TPOL_NONE          (0x000UL)
#define DMASCH_GCR_TPOL_RISE          (0x400UL)
#define DMASCH_GCR_TPOL_FALL          (0x800UL)
#define DMASCH_GCR_TPOL_BOTH          (0xC00UL)

#define DMASCH_GCR_TMOD_S           (12UL)
#define DMASCH_GCR_TMOD_M           (0x1000UL)
#define DMASCH_GCR_TMOD_SWHW          (0x0000UL)
#define DMASCH_GCR_TMOD_AUTO          (0x1000UL)

#define DMASCH_GCR_GENE_S           (13UL)
#define DMASCH_GCR_GENE_M           (0x2000UL)
#define DMASCH_GCR_GENE_ENABLE        (0x2000UL)
#define DMASCH_GCR_GENE_DISABLE       (0x0000UL)

#define DMASCH_GCR_GREQLOW_S        (16UL)
#define DMASCH_GCR_GREQLOW_M        (0x1F0000UL)

#define DMASCH_GCR_GREQHIGH_S       (21UL)
#define DMASCH_GCR_GREQHIGH_M       (0x3E00000UL)

/* ==========================         MCR        ============================ */
#define DMASCH_MCR_REQ_S            (0UL)
#define DMASCH_MCR_REQ_M            (0xFFUL)

#define DMASCH_MCR_SOIE_S           (8UL)
#define DMASCH_MCR_SOIE_M           (0x100UL)
#define DMASCH_MCR_SOIE_ENABLE        (0x100UL)
#define DMASCH_MCR_SOIE_DISABLE       (0x000UL)

#define DMASCH_MCR_EVTE_S           (9UL)
#define DMASCH_MCR_EVTE_M           (0x200UL)
#define DMASCH_MCR_EVTE_ENABLE        (0x200UL)
#define DMASCH_MCR_EVTE_DISABLE       (0x000UL)

#define DMASCH_MCR_SPOL_S           (10UL)
#define DMASCH_MCR_SPOL_M           (0xC00UL)
#define DMASCH_MCR_SPOL_NONE          (0x000UL)
#define DMASCH_MCR_SPOL_RISE          (0x400UL)
#define DMASCH_MCR_SPOL_FALL          (0x800UL)
#define DMASCH_MCR_SPOL_BOTH          (0xC00UL)

#define DMASCH_MCR_SE_S             (12UL)
#define DMASCH_MCR_SE_M             (0x1000UL)
#define DMASCH_MCR_SE_ENABLE          (0x1000UL)
#define DMASCH_MCR_SE_DISABLE         (0x0000UL)

#define DMASCH_MCR_O_MODE_S         (13UL)
#define DMASCH_MCR_O_MODE_M         (0x2000UL)
#define DMASCH_MCR_O_MODE_PULSE       (0x2000UL)
#define DMASCH_MCR_O_MODE_LEVEL       (0x0000UL)

#define DMASCH_MCR_O_POL_S          (14UL)
#define DMASCH_MCR_O_POL_M          (0x4000UL)
#define DMASCH_MCR_O_POL_LOW          (0x4000UL)
#define DMASCH_MCR_O_POL_HIGH         (0x0000UL)

#define DMASCH_MCR_MREQ_S           (16UL)
#define DMASCH_MCR_MREQ_M           (0x7FF0000UL)

#define DMASCH_MCR_SYNC_S           (26UL)
#define DMASCH_MCR_SYNC_M           (0xF8000000UL)

#define HAL_TPOL_NONE DMASCH_GCR_TPOL_NONE
#define HAL_TPOL_RISE DMASCH_GCR_TPOL_RISE
#define HAL_TPOL_FALL DMASCH_GCR_TPOL_FALL
#define HAL_TPOL_BOTH DMASCH_GCR_TPOL_BOTH

#define HAL_TMOD_SWHW DMASCH_GCR_TMOD_SWHW
#define HAL_TMOD_AUTO DMASCH_GCR_TMOD_AUTO

#define HAL_SPOL_NONE DMASCH_MCR_SPOL_NONE
#define HAL_SPOL_RISE DMASCH_MCR_SPOL_RISE
#define HAL_SPOL_FALL DMASCH_MCR_SPOL_FALL
#define HAL_SPOL_BOTH DMASCH_MCR_SPOL_BOTH

#define HAL_O_MODE_PULSE DMASCH_MCR_O_MODE_PULSE
#define HAL_O_MODE_LEVEL DMASCH_MCR_O_MODE_LEVEL

#define HAL_O_POL_LOW  DMASCH_MCR_O_POL_LOW
#define HAL_O_POL_HIGH DMASCH_MCR_O_POL_HIGH

#endif
