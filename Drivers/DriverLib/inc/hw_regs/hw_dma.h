/** 
  ************************************************************************************* 
  * @file hw_dma.h 
  * @brief This file contains the definition of hw_dma driver. 
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
#ifndef _HW_DMA_H_
#define _HW_DMA_H_



/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define DMA_O_SAR                     0x0
#define DMA_O_DAR                     0x8
#define DMA_O_LLP                     0x10 //QUZE YUZHEN
#define DMA_O_CTL                     0x18
#define DMA_O_SSTAT                   0x20 //all no
#define DMA_O_DSTAT                   0x28 //all no
#define DMA_O_SSTATAR                 0x30 //all no
#define DMA_O_DSTATAR                 0x38 //all no
#define DMA_O_CFG                     0x40 //all no
#define DMA_O_SGR                     0x48 //QUZE
#define DMA_O_DSR                     0x50 //QUZE
#define DMA_O_RAWTFR                  0x2C0
#define DMA_O_RAWBLOCK                0x2C8
#define DMA_O_RAWSRCTRAN              0x2D0
#define DMA_O_RAWDSTTRAN              0x2D8
#define DMA_O_RAWERR                  0x2E0
#define DMA_O_STATUSTFR               0x2E8
#define DMA_O_STATUSBLOCK             0x2F0
#define DMA_O_STATUSSRCTRAN           0x2F8
#define DMA_O_STATUSDSTTRAN           0x300
#define DMA_O_STATUSERR               0x308
#define DMA_O_MASKTFR                 0x310
#define DMA_O_MASKBLOCK               0x318
#define DMA_O_MASKSRCTRAN             0x320
#define DMA_O_MASKDSTTRAN             0x328
#define DMA_O_MASKERR                 0x330
#define DMA_O_CLEARTFR                0x338
#define DMA_O_CLEARBLOCK              0x340
#define DMA_O_CLEARSRCTRAN            0x348
#define DMA_O_CLEARDSTTRAN            0x350
#define DMA_O_CLEARERR                0x358
#define DMA_O_STATUSINT               0x360
#define DMA_O_REQSRCREG               0x368
#define DMA_O_REQDSTREG               0x370
#define DMA_O_SGLRQSRCREG             0x378
#define DMA_O_SGLRQDSTREG             0x380
#define DMA_O_LSTSRCREG               0x388
#define DMA_O_LSTDSTREG               0x390
#define DMA_O_DMACFGREG               0x398
#define DMA_O_CHENREG                 0x3A0
#define DMA_O_DMAIDREG                0x3A8
#define DMA_O_DMATESTREG              0x3B0
#define DMA_O_DMALPTIMEOUTREG         0x3B8 //YUZHEN NO
#define DMA_O_DMACOMPPARAMS_6         0x3C8
#define DMA_O_DMACOMPPARAMS_5         0x3D0
#define DMA_O_DMACOMPPARAMS_4         0x3D8
#define DMA_O_DMACOMPPARAMS_3         0x3E0
#define DMA_O_DMACOMPPARAMS_2         0x3E8
#define DMA_O_DMACOMPPARAMS_1         0x3F0
#define DMA_O_DMACOMPSID              0x3F8


#define DMA_CTL_INT_EN                0x00000001U
#define DMA_CTL_DST_TR_WIDTH          0x0000000EU
#define DMA_CTL_SRC_TR_WIDTH          0x00000070U
#define DMA_CTL_DINC                  0x00000180U
#define DMA_CTL_SINC                  0x00000600U
#define DMA_CTL_DST_MSIZE             0x00003800U
#define DMA_CTL_SRC_MSIZE             0x0001C000U
#define DMA_CTL_SRC_GATHER_EN         0x00020000U //QUZE
#define DMA_CTL_DST_SCATTER_EN        0x00040000U //QUZE
#define DMA_CTL_TT_FC                 0x00700000U
#define DMA_CTL_DMS                   0x01800000U
#define DMA_CTL_SMS                   0x06000000U
#define DMA_CTL_LLP_DST_EN            0x08000000U //QUZE YUZHEN
#define DMA_CTL_LLP_SRC_EN            0x10000000U //QUZE YUZHEN
#define DMA_CTL_BLOCK_TS              0x00000FFF00000000U
#define DMA_CTL_DONE                  0x0000100000000000U

#define DMA_CFG_CH_PRIOR              0x000000E0U
#define DMA_CFG_CH_SUSP               0x00000100U
#define DMA_CFG_FIFO_EMPTY            0x00000200U
#define DMA_CFG_HS_SEL_DST            0x00000400U
#define DMA_CFG_HS_SEL_SRC            0x00000800U
#define DMA_CFG_DST_HS_POL            0x00040000U
#define DMA_CFG_SRC_HS_POL            0x00080000U
#define DMA_CFG_MAX_ABRST             0x3FF00000U
#define DMA_CFG_RELOAD_SRC            0x40000000U  //QUZE YUZHEN
#define DMA_CFG_RELOAD_DST            0x80000000U  //QUZE YUZHEN
#define DMA_CFG_FCMODE                0x0000000100000000U
#define DMA_CFG_FIFOMODE              0x0000000200000000U
#define DMA_CFG_PROTCTL               0x0000001C00000000U
#define DMA_CFG_SRC_PER               0x0000078000000000U
#define DMA_CFG_DEST_PER              0x0000780000000000U

#define DMA_SGR_SGI_M              (0x000FFFFFU) //QUZE
#define DMA_SGR_SGC_M              (0xFFF00000U)  //QUZE
#define DMA_DSR_DSI_M              (0x000FFFFFU)  //QUZE
#define DMA_DSR_DSC_M              (0xFFF00000U)  //QUZE

#define DMA_CLEARERR_CLEAR            0x0FFU

#define DMA_STATUSINT_TFR             0x01U
#define DMA_STATUSINT_BLOCK           0x02U
#define DMA_STATUSINT_SRC             0x03U
#define DMA_STATUSINT_DST             0x08U
#define DMA_STATUSINT_ERR             0x10U


#define DMA_DMACFGREG_DMA_EN          0x01U

#define DMA_CHENREG_CH_EN             0x01U
#define DMA_CHENREG_CH_EN_WE          0x100U

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/*****************************************************************
 *    New definitions for DMA
 *****************************************************************/

/* DMA channel registers - 22 registers, size 0x58 */
typedef struct  {
    __IO uint32_t SAR;
    __IO uint32_t Reserved_0;
    __IO uint32_t DAR;
    __IO uint32_t Reserved_1;
    __IO uint32_t LLP;
    __IO uint32_t Reserved_2;
    __IO uint32_t CTRL_L;
    __IO uint32_t CTRL_H;
    __IO uint32_t SSTAT;
    __IO uint32_t Reserved_3;
    __IO uint32_t DSTAT;
    __IO uint32_t Reserved_4;
    __IO uint32_t SSTATAR;
    __IO uint32_t Reserved_5;
    __IO uint32_t DSTATAR;
    __IO uint32_t Reserved_6;
    __IO uint32_t CFG_L;
    __IO uint32_t CFG_H;
    __IO uint32_t SGR_L;
    __IO uint32_t SGR_H;
    __IO uint32_t DSR_L;
    __IO uint32_t DSR_H;
} DMA_ChannelType;

/* Interrupt registers */
typedef struct {
    __IO uint32_t RawTfr_L;
    __IO uint32_t RawTfr_H;
    __IO uint32_t RawBlock_L;
    __IO uint32_t RawBlock_H;
    __IO uint32_t RawSrcTran_L;
    __IO uint32_t RawSrcTran_H;
    __IO uint32_t RawDstTran_L;
    __IO uint32_t RawDstTran_H;
    __IO uint32_t RawErr_L;
    __IO uint32_t RawErr_H;
    __IO uint32_t StatusTfr_L;
    __IO uint32_t StatusTfr_H;
    __IO uint32_t StatusBlock_L;
    __IO uint32_t StatusBlock_H;
    __IO uint32_t StatusSrcTran_L;
    __IO uint32_t StatusSrcTran_H;
    __IO uint32_t StatusDstTran_L;
    __IO uint32_t StatusDstTran_H;
    __IO uint32_t StatusErr_L;
    __IO uint32_t StatusErr_H;
    __IO uint32_t MaskTfr_L;
    __IO uint32_t MaskTfr_H;
    __IO uint32_t MaskBlock_L;
    __IO uint32_t MaskBlock_H;
    __IO uint32_t MaskSrcTran_L;
    __IO uint32_t MaskSrcTran_H;
    __IO uint32_t MaskDstTran_L;
    __IO uint32_t MaskDstTran_H;
    __IO uint32_t MaskErr_L;
    __IO uint32_t MaskErr_H;
    __IO uint32_t ClearTfr_L;
    __IO uint32_t ClearTfr_H;
    __IO uint32_t ClearBlock_L;
    __IO uint32_t ClearBlock_H;
    __IO uint32_t ClearSrcTran_L;
    __IO uint32_t ClearSrcTran_H;
    __IO uint32_t ClearDstTran_L;
    __IO uint32_t ClearDstTran_H;
    __IO uint32_t ClearErr_L;
    __IO uint32_t ClearErr_H;
    __IO uint32_t StatusInt_L;
    __IO uint32_t StatusInt_H;
} DMA_IntCtrlType;

/* Software_Handshake Registers */
typedef struct {
    __IO uint32_t ReqSrcReg;
    __IO uint32_t Reserved_0;
    __IO uint32_t ReqDstReg;
    __IO uint32_t Reserved_1;
    __IO uint32_t SglRqSrcReg;
    __IO uint32_t Reserved_2;
    __IO uint32_t SglRqDstcReg;
    __IO uint32_t Reserved_3;
    __IO uint32_t LstSrcReg;
    __IO uint32_t Reserved_4;
    __IO uint32_t LstDstReg;
    __IO uint32_t Reserved_5;
} DMA_SoftHandshakeType;

/* DMAC Miscellaneous Registers */
typedef struct {
    __IO uint32_t DmaCfgReg;
    __IO uint32_t Reserved_0;
    __IO uint32_t ChEnReg;
    __IO uint32_t Reserved_1;
    __IO uint32_t DmaIdReg;
    __IO uint32_t Reserved_2;
    __IO uint32_t DmaTestReg;
    __IO uint32_t Reserved_3;
    __IO uint32_t DmaLpTimeoutReg;
    __IO uint32_t Reserved_4;
    __IO uint32_t Reserved_5;
    __IO uint32_t Reserved_6;
    __IO uint32_t DmaCompParams[12];
    __IO uint32_t DmaCompsID_L;
    __IO uint32_t DmaCompsID_H;
} DMA_MiscCfgType;

typedef struct {
    DMA_ChannelType Dma_Channels[8];    //offset is n*0x58=6*0x58= 0x210, max 8 channel
    DMA_IntCtrlType Dma_Interrupt;        //offset 0x02C0
    DMA_SoftHandshakeType Dma_SoftHandshake;    //offset 0x0368
    DMA_MiscCfgType    Dma_Misc;            //offset 0x0398
} DMA_Type;


#if DMAC_HW_VER == 0x00

//DIVER 2*********************************************************

#define DMAC_CHANNEL_NUM 8

//*****************************************************************************
//
// DMAC Channel Register Structure
//
//*****************************************************************************
typedef struct {
    __IOM uint32_t   SAR;             //!< Channel Source Address Register     (offset = 0x00)
    __IM  uint32_t   reserved1[1];    //!< Reserved                           (offset = 0x04)
    __IOM uint32_t   DAR;             //!< Channel Destination Address Register (offset = 0x08)
    __IM  uint32_t   reserved2[1];    //!< Reserved                           (offset = 0x0C)
    __IOM uint32_t   LLP;
    __IM  uint32_t   reserved3[1];
    __IOM uint32_t   CTRLa;           //!< Channel Control Register A         (offset = 0x18)
    __IOM uint32_t   CTRLb;           //!< Channel Control Register B         (offset = 0x1C)
    __IOM uint32_t   SSTAT;
    __IM  uint32_t   reserved4[1];
    __IOM uint32_t   DSTAT;
    __IM  uint32_t   reserved5[1];
    __IOM uint32_t   SSTATAR;
    __IM  uint32_t   reserved6[1];
    __IOM uint32_t   DSTATAR;
    __IM  uint32_t   reserved7[1];
    __IOM uint32_t   CFGa;            //!< Channel Configuration Register A   (offset = 0x40)
    __IOM uint32_t   CFGb;            //!< Channel Configuration Register B   (offset = 0x44)
    __IOM uint32_t   SGRa;
    __IOM uint32_t   SGRb;
    __IOM uint32_t   DSRa;
    __IOM uint32_t   DSRb;
}DMAC_CH_TypeDef;

typedef struct {
    DMAC_CH_TypeDef  ChannelCfg[8];   //!< Channel Configuration                       (offset = 0x000)

    __IM  uint32_t   RawTfr;          //!< Raw Status for IntTfr Interrupt            (offset = 0x2C0)
          uint32_t   reserved1[1];    //!< Reserved                                   (offset = 0x2C4)
    __IM  uint32_t   RawBlock;        //!< Raw Status for IntBlock Interrupt          (offset = 0x2C8)
          uint32_t   reserved2[1];    //!< Reserved                                   (offset = 0x2CC)
    __IM  uint32_t   RawSrcTran;      //!< Raw Status for IntSrcTran Interrupt        (offset = 0x2D0)
          uint32_t   reserved3[1];    //!< Reserved                                   (offset = 0x2D4)
    __IM  uint32_t   RawDstTran;      //!< Raw Status for IntDstTran Interrupt        (offset = 0x2D8)
          uint32_t   reserved4[1];    //!< Reserved                                   (offset = 0x2DC)
    __IM  uint32_t   RawErr;          //!< Raw Status for IntErr Interrupt            (offset = 0x2E0)
          uint32_t   reserved5[1];    //!< Reserved                                   (offset = 0x2E4)
    __IM  uint32_t   StatusTfr;       //!< Status for IntTfr Interrupt                (offset = 0x2E8)
          uint32_t   reserved6[1];   //!< Reserved                                   (offset = 0x2EC)
    __IM  uint32_t   StatusBlock;     //!< Status for IntBlock Interrupt              (offset = 0x2F0)
          uint32_t   reserved7[1];   //!< Reserved                                   (offset = 0x2F4)
    __IM  uint32_t   StatusSrcTran;   //!< Status for IntSrcTran Interrupt            (offset = 0x2F8)
          uint32_t   reserved8[1];   //!< Reserved                                   (offset = 0x2FC)
    __IM  uint32_t   StatusDstTran;   //!< Status for IntDstTran Interrupt            (offset = 0x300)
          uint32_t   reserved9[1];   //!< Reserved                                   (offset = 0x304)
    __IM  uint32_t   StatusErr;       //!< Status for IntErr Interrupt                (offset = 0x308)

          uint32_t   reserved10[1];   //!< Reserved                                   (offset = 0x30C)
    __IOM uint32_t   MaskTfr;         //!< Mask for IntTfr Interrupt                  (offset = 0x310)
          uint32_t   reserved11[1];   //!< Reserved                                   (offset = 0x314)
    __IOM uint32_t   MaskBlock;       //!< Mask for IntBlock Interrupt                (offset = 0x318)
          uint32_t   reserved12[1];   //!< Reserved                                   (offset = 0x31C)
    __IOM uint32_t   MaskSrcTran;     //!< Mask for IntSrcTran Interrupt              (offset = 0x320)
          uint32_t   reserved13[1];   //!< Reserved                                   (offset = 0x324)
    __IOM uint32_t   MaskDstTran;     //!< Mask for IntDstTran Interrupt              (offset = 0x328)
          uint32_t   reserved14[1];   //!< Reserved                                   (offset = 0x32C)
    __IOM uint32_t   MaskErr;         //!< Mask for IntErr Interrupt                  (offset = 0x330)

          uint32_t   reserved15[1];   //!< Reserved                                   (offset = 0x334)
    __OM  uint32_t   ClearTfr;        //!< Clear for IntTfr Interrupt                 (offset = 0x338)
          uint32_t   reserved16[1];   //!< Reserved                                   (offset = 0x33C)
    __OM  uint32_t   ClearBlock;      //!< Clear for IntBlock Interrupt               (offset = 0x340)
          uint32_t   reserved17[1];   //!< Reserved                                   (offset = 0x344)
    __OM  uint32_t   ClearSrcTran;    //!< Clear for IntSrcTran Interrupt             (offset = 0x348)
          uint32_t   reserved18[1];   //!< Reserved                                   (offset = 0x34C)
    __OM  uint32_t   ClearDstTran;    //!< Clear for IntDstTran Interrupt             (offset = 0x350)
          uint32_t   reserved19[1];   //!< Reserved                                   (offset = 0x354)
    __OM  uint32_t   ClearErr;        //!< Clear for IntErr Interrupt                 (offset = 0x358)
          uint32_t   reserved20[1];   //!< Reserved                                   (offset = 0x36C)
    __IM  uint32_t   StatusInt;       //!< Status for each interrupt type             (offset = 0x360)
          uint32_t   reserved21[1];   //!< Reserved                                   (offset = 0x364)

    __IOM uint32_t   ReqSrc;          //!< Source Software Transaction Request        (offset = 0x368)
          uint32_t   reserved22[1];   //!< Reserved                                   (offset = 0x36C)
    __IOM  uint32_t  ReqDst;          //!< Destination Software Transaction Request   (offset = 0x370)
          uint32_t   reserved23[1];   //!< Reserved                                   (offset = 0x374)
    __IOM uint32_t   SglReqSrc;       //!< Single Source Transaction Request          (offset = 0x378)
          uint32_t   reserved24[1];   //!< Reserved                                   (offset = 0x37C)
    __IOM uint32_t   SglReqDst;       //!< Single Destination Transaction Request     (offset = 0x380)
          uint32_t   reserved25[1];   //!< Reserved                                   (offset = 0x384)
    __IOM uint32_t   LstReqSrc;       //!< Last Source Transaction Request            (offset = 0x388)
          uint32_t   reserved36[1];   //!< Reserved                                   (offset = 0x38C)
    __IOM uint32_t   LstReqDst;       //!< Last Destination Transaction Request       (offset = 0x390)
          uint32_t   reserved37[1];   //!< Reserved                                   (offset = 0x394)

    __IOM uint32_t   DmaCfg;          //!< DMA configuration Register                 (offset = 0x398)
          uint32_t   reserved38[1];   //!< Reserved                                   (offset = 0x39C)
    __IOM uint32_t   DmaChEn;         //!< DMA channel Enable Register                (offset = 0x3A0)
          uint32_t   reserved39[1];   //!< Reserved                                   (offset = 0x3A4)
    __IM  uint32_t   DmaId;           //!< DMA ID Register                            (offset = 0x3A8)
          uint32_t   reserved40[1];   //!< Reserved                                   (offset = 0x3AC)
    __IOM uint32_t   DmaTest;         //!< DMA Test RSCHegister                          (offset = 0x3B0)
          uint32_t   reserved41[1];   //!< Reserved
    __IOM uint32_t   DmaLpTimeoutReg;
          uint32_t   reserved42[3];

          uint32_t   reserved43[1];      //!< Reserved                                   (offset = 0x3C8)
    __IM  uint32_t   Params_6;        //!< DMA Component Parameters Register 6        (offset = 0x3CC)
    __IM  uint32_t   Params_5a;       //!< DMA Component Parameters Register 5 A      (offset = 0x3D0)
    __IM  uint32_t   Params_5b;       //!< DMA Component Parameters Register 5 B      (offset = 0x3D4)
    __IM  uint32_t   Params_4a;       //!< DMA Component Parameters Register 4 A      (offset = 0x3D8)
    __IM  uint32_t   Params_4b;       //!< DMA Component Parameters Register 4 B      (offset = 0x3DC)
    __IM  uint32_t   Params_3a;       //!< DMA Component Parameters Register 3 A      (offset = 0x3E0)
    __IM  uint32_t   Params_3b;       //!< DMA Component Parameters Register 3 B      (offset = 0x3E4)
    __IM  uint32_t   Params_2a;       //!< DMA Component Parameters Register 2 A      (offset = 0x3E8)
    __IM  uint32_t   Params_2b;       //!< DMA Component Parameters Register 2 B      (offset = 0x3EC)
    __IM  uint32_t   Params_1a;       //!< DMA Component Parameters Register 1 A      (offset = 0x3F0)
    __IM  uint32_t   Params_1b;       //!< DMA Component Parameters Register 1 B      (offset = 0x3F4)
    __IM  uint32_t   COMP_TYPE;       //!< DMA Component ID Register low              (offset = 0x3F8)
    __IM  uint32_t   COMP_VERSION;    //!< DMA Component ID Register high             (offset = 0x3FC)
} DMAC_TypeDef;

//*****************************************************************************
//
// DMAC Register Bit Definitions
//
//*****************************************************************************

// CTRLa Register Bit Definitions
#define DMAC_CTRLA_INTEN_Pos          (0UL)   //!< Interrupt Enable bit position
#define DMAC_CTRLA_INTEN_Msk          (0x1UL)   //!< Interrupt Enable bit mask
#define DMAC_CTRLA_INT_ENABLE         DMAC_CTRLA_INTEN_Msk   //!< Enable interrupt
#define DMAC_CTRLA_INT_DISABLE        (0x0UL)   //!< Disable interrupt

#define DMAC_CTRLA_DST_TR_WIDTH_Pos   (1UL)   //!< Destination Transfer Width bit position
#define DMAC_CTRLA_DST_TR_WIDTH_Msk   (0x7UL)   //!< Destination Transfer Width bit mask(0xEUL)
#define DMAC_CTRLA_DST_TR_WIDTH_8     (0x0UL)   //!< 8-bit destination transfer width
#define DMAC_CTRLA_DST_TR_WIDTH_16    (0x2UL)   //!< 16-bit destination transfer width
#define DMAC_CTRLA_DST_TR_WIDTH_32    (0x4UL)   //!< 32-bit destination transfer width

#define DMAC_CTRLA_SRC_TR_WIDTH_Pos   (4UL)   //!< Source Transfer Width bit position
#define DMAC_CTRLA_SRC_TR_WIDTH_Msk   (0x70UL)   //!< Source Transfer Width bit mask
#define DMAC_CTRLA_SRC_TR_WIDTH_8     (0x00UL)   //!< 8-bit source transfer width
#define DMAC_CTRLA_SRC_TR_WIDTH_16    (0x10UL)   //!< 16-bit source transfer width
#define DMAC_CTRLA_SRC_TR_WIDTH_32    (0x20UL)   //!< 32-bit source transfer width

#define DMAC_CTRLA_DSTADDR_OPR_Pos    (7UL)   //!< Destination Address Operation bit position
#define DMAC_CTRLA_DSTADDR_OPR_Msk    (0x180UL)   //!< Destination Address Operation bit mask
#define DMAC_CTRLA_DSTADDR_INC        (0x000UL)   //!< Increment destination address
#define DMAC_CTRLA_DSTADDR_DEC        (0x080UL)   //!< Decrement destination address
#define DMAC_CTRLA_DSTADDR_CONSTANT   (0x100UL)   //!< Constant destination address

#define DMAC_CTRLA_SRCADDR_OPR_Pos    (9UL)   //!< Source Address Operation bit position
#define DMAC_CTRLA_SRCADDR_OPR_Msk    (0x600UL)   //!< Source Address Operation bit mask
#define DMAC_CTRLA_SRCADDR_INC        (0x000UL)   //!< Increment source address
#define DMAC_CTRLA_SRCADDR_DEC        (0x200UL)   //!< Decrement source address
#define DMAC_CTRLA_SRCADDR_CONSTANT   (0x400UL)   //!< Constant source address


#define DMAC_CTRLA_DST_MSIZE_Pos      (11UL)   //!< Destination Burst Size bit position
#define DMAC_CTRLA_DST_MSIZE_Msk      (0x3800UL)   //!< Destination Burst Size bit mask
#define DMAC_CTRLA_DST_MSIZE_1BYTE    (0x0000UL)   //!< 1-byte destination burst size
#define DMAC_CTRLA_DST_MSIZE_4BYTE    (0x0800UL)   //!< 4-byte destination burst size
#define DMAC_CTRLA_DST_MSIZE_8BYTE    (0x1000UL)   //!< 8-byte destination burst size
#define DMAC_CTRLA_DST_MSIZE_16BYTE   (0x1800UL)   //!< 16-byte destination burst size
#define DMAC_CTRLA_DST_MSIZE_32BYTE   (0x2000UL)   //!< 32-byte destination burst size
#define DMAC_CTRLA_DST_MSIZE_64BYTE   (0x2800UL)   //!< 64-byte destination burst size
#define DMAC_CTRLA_DST_MSIZE_128BYTE  (0x3000UL)   //!< 128-byte destination burst size
#define DMAC_CTRLA_DST_MSIZE_256BYTE  (0x3800UL)   //!< 256-byte destination burst size

#define DMAC_CTRLA_SRC_MSIZE_Pos      (14UL)   //!< Source Burst Size bit position
#define DMAC_CTRLA_SRC_MSIZE_Msk      (0x1C000UL)   //!< Source Burst Size bit mask
#define DMAC_CTRLA_SRC_MSIZE_1BYTE    (0x00000UL)   //!< 1-byte source burst size
#define DMAC_CTRLA_SRC_MSIZE_4BYTE    (0x04000UL)   //!< 4-byte source burst size
#define DMAC_CTRLA_SRC_MSIZE_8BYTE    (0x08000UL)   //!< 8-byte source burst size
#define DMAC_CTRLA_SRC_MSIZE_16BYTE   (0x0C000UL)   //!< 16-byte source burst size
#define DMAC_CTRLA_SRC_MSIZE_32BYTE   (0x10000UL)   //!< 32-byte source burst size
#define DMAC_CTRLA_SRC_MSIZE_64BYTE   (0x14000UL)   //!< 64-byte source burst size
#define DMAC_CTRLA_SRC_MSIZE_128BYTE  (0x18000UL)   //!< 128-byte source burst size
#define DMAC_CTRLA_SRC_MSIZE_256BYTE  (0x1C000UL)   //!< 256-byte source burst size

#define DMAC_CTRLA_TRANSTYPE_Pos       (20UL)   //!< Transfer Type bit position
#define DMAC_CTRLA_TRANSTYPE_Msk       (0x700000UL)   //!< Transfer Type bit mask
#define DMAC_CTRLA_TRANSTYPE_MEM2MEM   (0x000000UL)   //!< Memory to Memory transfer type
#define DMAC_CTRLA_TRANSTYPE_MEM2PERI  (0x100000UL)   //!< Memory to Peripheral transfer type
#define DMAC_CTRLA_TRANSTYPE_PERI2MEM  (0x200000UL)   //!< Peripheral to Memory transfer type
#define DMAC_CTRLA_TRANSTYPE_PERI2PERI (0x300000UL)   //!< Peripheral to Peripheral transfer type

#define DMAC_CTRLA_DMS_Pos (23UL)
#define DMAC_CTRLA_DMS_Msk (0x01800000UL)
#define DMAC_CTRLA_SMS_Pos (25UL)
#define DMAC_CTRLA_SMS_Msk (0x06000000UL)


//*****************************************************************************
//
// DMAC CFGb Register Bit Definitions
//
//*****************************************************************************

#define DMAC_CTRLB_DONE_Msk  (0x00001000UL)
#define DMAC_CTRLB_BLOCK_Msk (0x00000FFFUL)

//*****************************************************************************
//
// DMAC CFGa Register Bit Definitions
//
//*****************************************************************************
#define DMAC_CFGA_PRIOR_Pos  (5UL)
#define DMAC_CFGA_PRIOR_Msk  (0x000000E0UL)
#define DMAC_CFGA_SUSP_Msk   (0x00000100UL)
#define DMAC_CFGA_FIFO_EMPTY_Msk   (0x00000200UL)

#define DMAC_CFGA_HSSEL_DST_Pos      (10UL)
#define DMAC_CFGA_HSSEL_DST_Msk      (0x400UL)
#define DMAC_CFGA_HSSEL_DST_HW       (0x000UL)
#define DMAC_CFGA_HSSEL_DST_SW       DMAC_CFGA_HSSEL_DST_Msk

#define DMAC_CFGA_POL_DST_Pos 18UL
#define DMAC_CFGA_POL_DST_Msk (0x40000UL)
#define DMAC_CFGA_POL_SRC_Pos 19UL
#define DMAC_CFGA_POL_SRC_Msk (0x80000UL)

#define DMAC_CFGA_HSSEL_SRC_Pos      (11UL)
#define DMAC_CFGA_HSSEL_SRC_Msk      (0x800UL)
#define DMAC_CFGA_HSSEL_SRC_HW       (0x000UL)
#define DMAC_CFGA_HSSEL_SRC_SW       DMAC_CFGA_HSSEL_SRC_Msk

//*****************************************************************************
//
// DMAC CFGb Register Bit Definitions
//
//*****************************************************************************
#define DMAC_CFGB_FIFOMODE_Pos       (1UL)
#define DMAC_CFGB_FIFOMODE_Msk       (0x2UL)

#define DMAC_CFGB_HS_SRCPERI_Pos     (7UL)
#define DMAC_CFGB_HS_SRCPERI_Msk     (0x780UL)

#define DMAC_CFGB_HS_DSTPERI_Pos     (11UL)
#define DMAC_CFGB_HS_DSTPERI_Msk     (0x7800UL)

//*****************************************************************************
//
// DMAC DmaCfg Register Bit Definitions
//
//*****************************************************************************
#define DMAC_CFG_EN_Pos              (0UL)
#define DMAC_CFG_EN_Msk              (0x1UL)
#define DMAC_CFG_ENABLE              DMAC_CFG_EN_Msk
#define DMAC_CFG_DISABLE             (0x0UL)
#endif


#endif 

