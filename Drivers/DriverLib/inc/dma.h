/** 
  ************************************************************************************* 
  * @file dma.h 
  * @brief This file contains the definition of dma driver. 
  * @version 1.0.0 
  ************************************************************************************* 
  * @copyright Copyright (c) 2025 Albatross Semiconductor(Hangzhou) Co.,Ltd. 
  * BSD-3-Clause License 
  * 
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted provided that the following conditions are met: 
  * 
  * 1. Redistributions of source code must retain the above copyright notice, this
  *    list of conditions and GPIODATA_BASEthe following disclaimer.
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

#ifndef _DMA_H_
#define _DMA_H_

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
#include "dmasch.h"
#include "hw_dma.h"

#define DMAC_NUMS              (2U)

#define DMAC_CHNLS              (8U)
#if DMAC_HW_VER == 0x01
#define DMA1_BASE                       DMA1R_BASE
#endif
#if DMAC_HW_VER == 0x00
#define DMA1_BASE                       DMAC1_BASE
#endif
#define DMA1_CH1_BASE                   (DMA1_BASE+0*0x58)
#define DMA1_CH2_BASE                   (DMA1_BASE+1*0x58)
#define DMA1_CH3_BASE                   (DMA1_BASE+2*0x58)
#define DMA1_CH4_BASE                   (DMA1_BASE+3*0x58)
#define DMA1_CH5_BASE                   (DMA1_BASE+4*0x58)
#define DMA1_CH6_BASE                   (DMA1_BASE+5*0x58)
#define DMA1_CH7_BASE                   (DMA1_BASE+6*0x58)
#define DMA1_CH8_BASE                   (DMA1_BASE+7*0x58)
#define DMA1_CHx_BASE(x)                (DMA1_BASE+(x-1)*0x58)


#if DMAC_HW_VER == 0x01
#define DMA2_BASE                       DMA2R_BASE
#endif
#if DMAC_HW_VER == 0x00
#define DMA2_BASE                       DMAC2_BASE
#endif
#define DMA2_CH1_BASE                   (DMA2_BASE+0*0x58)
#define DMA2_CH2_BASE                   (DMA2_BASE+1*0x58)
#define DMA2_CH3_BASE                   (DMA2_BASE+2*0x58)
#define DMA2_CH4_BASE                   (DMA2_BASE+3*0x58)
#define DMA2_CH5_BASE                   (DMA2_BASE+4*0x58)
#define DMA2_CH6_BASE                   (DMA2_BASE+5*0x58)
#define DMA2_CH7_BASE                   (DMA2_BASE+6*0x58)
#define DMA2_CH8_BASE                   (DMA2_BASE+7*0x58)
#define DMA2_CHx_BASE(x)                (DMA2_BASE+(x-1)*0x58)

#define DMA1 ((DMA_Type*)(DMA1_BASE))
#define DMA2 ((DMA_Type*)(DMA2_BASE))
//*****************************************************************************
//
// DMA Register Access Macros
//
//*****************************************************************************
#define DMAREGH(base, offset)      (HWREG(base + (offset) + 0x04))   //!< High word register access macro
#define DMAREGL(base, offset)      (HWREG(base + (offset)))         //!< Low word register access macro



//*****************************************************************************
//
// DMA Interrupt Flag Bit Definitions
//
//*****************************************************************************
#define DMA_INT_TFR         0x01U      //!< Transfer Complete Interrupt Flag
#define DMA_INT_BLOCK       0x02U      //!< Block Complete Interrupt Flag
#define DMA_INT_SRCTRAN     0x04U      //!< Source Transaction Interrupt Flag
#define DMA_INT_DSTTRAN     0x08U      //!< Destination Transaction Interrupt Flag
#define DMA_INT_ERR         0x10U      //!< Error Interrupt Flag

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
//*****************************************************************************
//
//! Values that can be passed to DMA_setInterruptMode() as the \e mode
//! parameter.
//
//*****************************************************************************
//typedef enum
//{
//    //! DMA interrupt is generated at the beginning of a transfer
//    DMA_INT_AT_BEGINNING,
//    //! DMA interrupt is generated at the end of a transfer
//    DMA_INT_AT_END
//} DMA_InterruptMode;

//*****************************************************************************
//
//! Values that can be passed to DMA_setEmulationMode() as the \e mode
//! parameter.
//
//*****************************************************************************
//typedef enum
//{
//    //! Transmission stops after current read-write access is completed
//    DMA_EMULATION_STOP,
//    //! Continue DMA operation regardless of emulation suspend
//    DMA_EMULATION_FREE_RUN
//} DMA_EmulationMode;

typedef enum
{
    DMA_AHB_MASTER_1 = 0,
    DMA_AHB_MASTER_2 = 1,
#if DMAC_HW_VER == 0x01
    DMA_AHB_MASTER_3 = 2,
#endif
} DMA_MasterInfSelect;

typedef enum
{
    DMA_TT_FC_0_M2M_DMAC = 0,
    DMA_TT_FC_1_M2P_DMAC = 1,
    DMA_TT_FC_2_P2M_DMAC = 2,
    DMA_TT_FC_3_P2P_DMAC = 3,
    DMA_TT_FC_4_P2M_P,
    DMA_TT_FC_5_P2P_SP,
    DMA_TT_FC_6_M2P_P,
    DMA_TT_FC_7_P2P_DP,
} DMA_TransTypeFlowCtrl;

typedef enum
{
    DMA_BTL_1 = 0,
    DMA_BTL_4,
    DMA_BTL_8,
    DMA_BTL_16,
    DMA_BTL_32,
} DMA_BurstTransLength;

typedef enum
{
    DMA_ADDR_INCRE = 0,
    DMA_ADDR_DECRE,
    DMA_ADDR_NO_CHANGE,
} DMA_AddressIncrement;

typedef enum
{
    DMA_TR_WIDTH_BYTE_1 = 0,
    DMA_TR_WIDTH_BYTE_2,
    DMA_TR_WIDTH_BYTE_4,
//    DMA_TR_WIDTH_BYTE_8,
//    DMA_TR_WIDTH_BYTE_16,
//    DMA_TR_WIDTH_BYTE_32,
//    DMA_TR_WIDTH_BYTE_64,
//    DMA_TR_WIDTH_BYTE_128,
} DMA_TransferWidth;

typedef enum
{
    DMA_HKS_HARDWARE = 0,
    DMA_HKS_SOFTWARE,
} DMA_HandshakingSelect;

typedef enum
{
    DMA_HKS_HARD_INF_0 = 0,
    DMA_HKS_HARD_INF_1,
    DMA_HKS_HARD_INF_2,
    DMA_HKS_HARD_INF_3,
    DMA_HKS_HARD_INF_4,
    DMA_HKS_HARD_INF_5,
    DMA_HKS_HARD_INF_6,
    DMA_HKS_HARD_INF_7,
    DMA_HKS_HARD_INF_8,
    DMA_HKS_HARD_INF_9,
    DMA_HKS_HARD_INF_10,
    DMA_HKS_HARD_INF_11,
    DMA_HKS_HARD_INF_12,
    DMA_HKS_HARD_INF_13,
    DMA_HKS_HARD_INF_14,
    DMA_HKS_HARD_INF_15,
} DMA_HK_HARDWARE_INF;

typedef enum
{
    DMA_CH_PRIORITY_0 = 0,     //lowest
    DMA_CH_PRIORITY_1,
    DMA_CH_PRIORITY_2,
    DMA_CH_PRIORITY_3,
#if DMAC_HW_VER == 0x01
    DMA_CH_PRIORITY_4,
    DMA_CH_PRIORITY_5,
    DMA_CH_PRIORITY_6,
    DMA_CH_PRIORITY_7,
#endif
} DMA_CHANNEL_PRIORITY;


#if DMAC_HW_VER == 0x01
typedef struct
{
    uint32_t lliSar;
    uint32_t lliDar;
    uint32_t lliLlp;
    uint32_t lliCtla;
    uint32_t lliCtlb;
}DMA_LLP_structure __attribute__((aligned(4)));

typedef DMA_LLP_structure* DMA_LLI;


//*****************************************************************************
//
//! Values that can be passed to DMA_configChannel() as the
//! configure parameter.
//
//*****************************************************************************
typedef struct
{
    bool              enableInterrupt; /* Enable/Disable interrupt mode */
    uint32_t             destAddr; /* destination address */
    uint32_t             srcAddr; /* source address */
    uint16_t blockTS; /* block transfer size */
    DMA_TransTypeFlowCtrl ttfc; /* transfer type and flow control */
    bool llpSrc;
    bool llpDst;
    DMA_BurstTransLength srcBtl; /* source burst transfer length */
    DMA_BurstTransLength destBtl; /* dest burst transfer length */
    DMA_AddressIncrement srcAddrDirect; /* source address Increment */
    DMA_AddressIncrement destAddrDirect; /* dest address Increment */
    DMA_TransferWidth    srcTrWidthBytes; /* src transfer width */
    DMA_TransferWidth    destTrWidthBytes; /* dest transfer width */
    bool reloadSrc; /* source address auto reload */
    bool reloadDst; /* dest address auto reload */
    DMAMUX_ReqId_Type dmaSrcReqId; /* source request trigger id */
    DMAMUX_ReqId_Type dmaDstReqId; /* dest request trigger id */
    DMA_CHANNEL_PRIORITY chPriority;    /*  A priority of 7 is the highest priority, and 0
                                            is the lowest. This field must be programmed within the
                                            range 0 to DMAH_NUM_CHANNELS-1. A programmed
                                            value outside this range will cause erroneous behavior.*/
    DMA_LLI lli0;

    DMAMUX_GEN_INF genNum;

} DMA_ConfigParams;
#endif

#if DMAC_HW_VER == 0x00
//*****************************************************************************
//
//! Values that can be passed to DMA_configChannel() as the
//! configure parameter.
//
//*****************************************************************************
typedef struct
{
    bool              enableInterrupt; /* Enable/Disable interrupt mode */
    uint32_t             destAddr; /* destination address */
    uint32_t             srcAddr; /* source address */
    uint16_t blockTS; /* block transfer size */
    DMA_TransTypeFlowCtrl ttfc; /* transfer type and flow control */
    DMA_BurstTransLength srcBtl; /* source burst transfer length */
    DMA_BurstTransLength destBtl; /* dest burst transfer length */
    DMA_AddressIncrement srcAddrDirect; /* source address Increment */
    DMA_AddressIncrement destAddrDirect; /* dest address Increment */
    DMA_TransferWidth    srcTrWidthBytes; /* src transfer width */
    DMA_TransferWidth    destTrWidthBytes; /* dest transfer width */
    DMAMUX_ReqId_Type dmaSrcReqId; /* source request trigger id */
    DMAMUX_ReqId_Type dmaDstReqId; /* dest request trigger id */
    DMA_CHANNEL_PRIORITY chPriority;    /*  A priority of 7 is the highest priority, and 0
                                            is the lowest. This field must be programmed within the
                                            range 0 to DMAH_NUM_CHANNELS-1. A programmed
                                            value outside this range will cause erroneous behavior.*/

} DMA_ConfigParams;

#endif

//*****************************************************************************
//
//! Converts the channel base to the corresponding DMA module base.
//!
//! \param base is the channel base address of the DMA controller.
//!
//! \return Returns the module base of the input channel base.
//!
//! This function takes the channel base as input and returns the module base
//! where the given channel base address is located.
//!
//! \return Returns the corresponding DMA moudle base.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
DMA_convertChnBase2DmaBase(uint32_t base)
{
    uint32_t curDmacBase = 0U;
    curDmacBase = base & (~0xFFF);

    return curDmacBase;
}


//*****************************************************************************
//
//! Converts the channel base to the DMA channel number.
//!
//! \param base is the channel base address of the DMA controller.
//!
//! \return Returns the module base of the input channel base.
//!
//! This function takes the channel base as input and returns the module base
//! where the given channel base address is located.
//!
//! \return Returns the corresponding DMA channel Number.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
DMA_convertChnBase2ChnNum(uint32_t base)
{
    uint32_t channel = 0U;

    channel = (base & 0xFFF) / 0x58;

    return channel; ///(x-1)
}


__STATIC_INLINE uint32_t
DMA_convertChnBase2DmaNum(uint32_t base)
{
    uint32_t dma_num = 0U;

    switch(base)
    {
        case DMA1_CH1_BASE:
        case DMA1_CH2_BASE:
        case DMA1_CH3_BASE:
        case DMA1_CH4_BASE:
        case DMA1_CH5_BASE:
        case DMA1_CH6_BASE:
        case DMA1_CH7_BASE:
        case DMA1_CH8_BASE:
            dma_num = 1;
            break;

        case DMA2_CH1_BASE:
        case DMA2_CH2_BASE:
        case DMA2_CH3_BASE:
        case DMA2_CH4_BASE:
        case DMA2_CH5_BASE:
        case DMA2_CH6_BASE:
        case DMA2_CH7_BASE:
        case DMA2_CH8_BASE:
            dma_num = 2;
            break;

        default:
            dma_num = 2;
            break;
    }

    return dma_num;
}



//*****************************************************************************
//!
//! Initializes the DMA controller to a known state.
//!
//! \param base is the channel base address of the DMA controller.
//!
//! This function configures does a hard reset of the DMA controller in order
//! to put it into a known state. The function also sets the DMA to run free
//! during an emulation suspend (see the field DEBUGCTRL.FREE for more info).
//!
//! \return None.
//!
//*****************************************************************************
__STATIC_INLINE void
DMA_initController(uint32_t base)
{
    uint32_t dmacBase = 0U;
    uint32_t dmamuxBase = 0U;

    //
    // Covert the channel base to the Module base and the dmamux base address.
    //
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Dmac Disabled.
    //
    HWREG(dmacBase + DMA_O_DMACFGREG) &= (~DMA_DMACFGREG_DMA_EN);

    //
    // Check Dmac Disable success.
    //
    while (HWREG(dmacBase + DMA_O_DMACFGREG) & DMA_DMACFGREG_DMA_EN);

    //
    // Dmac Enabled.
    //
    HWREG(dmacBase + DMA_O_DMACFGREG) |= DMA_DMACFGREG_DMA_EN;

}

//*****************************************************************************
//!
//! Enable the DMA controller.
//!
//! \param base is the channel base address of the DMA controller.
//!
//! This function configures DMA module to eanbled status.
//!
//! \return None.
//!
//*****************************************************************************
__STATIC_INLINE void
DMA_enableModule(uint32_t base)
{
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to Module base.
    //
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Enabled Dma Controller.
    //
    HWREG(dmacBase + DMA_O_DMACFGREG) |= DMA_DMACFGREG_DMA_EN;
}

//*****************************************************************************
//!
//! Disable the DMA controller.
//!
//! \param base is the channel base address of the DMA controller.
//!
//! This function configures DMA module to disabled status.
//!
//! \return None.
//!
//*****************************************************************************
__STATIC_INLINE void
DMA_disableModule(uint32_t base)
{
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to Module base.
    //
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Disabled Dma Controller.
    //
    HWREG(dmacBase + DMA_O_DMACFGREG) &= ~(DMA_DMACFGREG_DMA_EN);
}

//*****************************************************************************
//
//! Trigger Soft Reset Channel
//!
//! \param base is the channel base address of the DMA controller.
//!
//! This function does a soft reset to place the channel into its default state
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_triggerSoftReset(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base base.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Disabled Dmac channel.
    //
    HWREG(dmacBase + DMA_O_CHENREG) = ((HWREG(dmacBase + DMA_O_CHENREG) | (1 << (8 + channel))) & (~(1 << channel)));

    //
    // Check Dmac Disable success.
    //
    while (HWREG(dmacBase + DMA_O_CHENREG) & (1 << channel));

    //
    // Enabled Dmac channel again.
    //
    HWREG(dmacBase + DMA_O_CHENREG) |= ((1 << (8 + channel)) | (1 << channel));
}


//*****************************************************************************
//
//! Starts a DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function starts the DMA running, typically after you have configured
//! it. It will wait for the first trigger event to start operation. To halt
//! the channel use DMA_stopChannel().
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_startChannel(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Enable the channel.
    //
    HWREG(dmacBase + DMA_O_CHENREG) = ((1 << (8 + channel)) | (1 << channel));
}

//*****************************************************************************
//
//! Halts a DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function halts the DMA at its current state and any current read-write
//! access is completed. To start the channel again use DMA_startChannel().
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_stopChannel(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Stop the channel.
    //
    HWREG(dmacBase + DMA_O_CHENREG) = ((HWREG(dmacBase + DMA_O_CHENREG) | (1 << (8 + channel))) & (~(1 << channel)));
}

//*****************************************************************************
//
//! Gets the status of a DMA channel's Run Status Flag.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function returns \b true if the Run Status Flag is set, which
//! means the DMA channel is enabled.
//! This flag is cleared when a transfer completes (TRANSFER_COUNT = 0) and
//! continuous mode is disabled, or when the HARDRESET, SOFTRESET, or HALT bit
//! is set.
//!
//! \return Returns \b true if the channel is enabled. Returns \b false
//! otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
DMA_getRunStatusFlag(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);


    //
    // Check the current channel is enabled or disabled and return.
    //
    return((HWREG(dmacBase + DMA_O_CHENREG) & (1 << channel)) != 0U);
}

//*****************************************************************************
//
//! Configures the source address for the DMA channel
//!
//! \param base is the base address of the DMA channel control registers.
//! \param *srcAddr is a source address.
//!
//! This function configures the source address of a DMA
//! channel.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_configSourceAddress(uint32_t base, uint32_t srcAddr)
{
    //
    // Set up SOURCE address.
    //
    HWREG(base + DMA_O_SAR) = (uint32_t)srcAddr;
}

//*****************************************************************************
//
//! Configures the destination address for the DMA channel
//!
//! \param base is the base address of the DMA channel control registers.
//! \param *destAddr is the destination address.
//!
//! This function configures the destinaton address of a DMA
//! channel.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_configDestAddress(uint32_t base, uint32_t destAddr)
{
    //
    // Set up DESTINATION address.
    //
    HWREG(base + DMA_O_DAR) = (uint32_t)destAddr;
}



/**
 * \brief   "config block transfer done"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   done       0: DONE bit is deasserted at the end of block transfer
 *                     1: SET the DONE bit at the end of block transfer
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configDone(uint32_t base, uint32_t done)
{
    ASSERT((done >= 0U) && (done <= 1U));

    DMAREGH(base, DMA_O_CTL) = ((DMAREGH(base, DMA_O_CTL) & (~(DMA_CTL_DONE >> 32))) | (done << 12));
}


/**
 * \brief   "config block transfer done"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   done       0: DONE bit is deasserted at the end of block transfer
 *                     1: SET the DONE bit at the end of block transfer
 *
 * \retval  None
 */
__STATIC_INLINE bool
DMA_readDone(uint32_t base, uint32_t done)
{
    ASSERT((done >= 0U) && (done <= 1U));

    return (((DMAREGH(base, DMA_O_CTL) & (DMA_CTL_DONE >> 32)))!=0);

}

/**
 * \brief   "config Block Transfer Size"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   block_ts   Block Transfer Size, 0-4095.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configBlockTs(uint32_t base, uint32_t block_ts)
{
    DMAREGH(base, DMA_O_CTL) = (DMAREGH(base, DMA_O_CTL) & (~(DMA_CTL_BLOCK_TS >> 32))) | (block_ts & 0x00000fff);
}


/**
 * \brief   "config Transfer Type and Flow Control"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   tt_fc      Transfer Type and Flow Control.
 *          0x0 (TT_FC_0): Transfer type is Memory to Memory and
 *          Flow Controller is DW_ahb_dmac
 *          0x1 (TT_FC_1): Transfer type is Memory to Peripheral
 *          and Flow Controller is DW_ahb_dmac
 *          0x2 (TT_FC_2): Transfer type is Peripheral to Memory
 *          and Flow Controller is DW_ahb_dmac
 *          0x3 (TT_FC_3): Transfer type is Peripheral to Peripheral
 *          and Flow Controller is DW_ahb_dmac
 *          0x4 (TT_FC_4): Transfer type is Peripheral to Memory
 *          and Flow Controller is Peripheral
 *          0x5 (TT_FC_5): Transfer type is Peripheral to Peripheral
 *          and Flow Controller is Source Peripheral
 *          0x6 (TT_FC_6): Transfer type is Memory to Peripheral
 *          and Flow Controller is Peripheral
 *          0x7 (TT_FC_7): Transfer type is Peripheral to Peripheral
 *          and Flow Controller is Destination Peripheral
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configTtFc(uint32_t base, uint32_t tt_fc)
{
    HWREG(base + DMA_O_CTL) = (HWREG(base + DMA_O_CTL) & (~DMA_CTL_TT_FC)) | (tt_fc << 20);
}

/**
 * \brief   "config Burst Transaction Length"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   src_msize  source Burst Transaction Length.
 * \param   dst_msize  dest Burst Transaction Length.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configMSize(uint32_t base, uint32_t src_msize, uint32_t dst_msize)
{
    HWREG(base + DMA_O_CTL) = (HWREG(base + DMA_O_CTL) & (~(DMA_CTL_SRC_MSIZE | DMA_CTL_DST_MSIZE))) | ((src_msize << 14) | (dst_msize << 11));
}

/**
 * \brief   "config Address Increment"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   sinc       source Address Increment.
 *          0x0 (SINC_0): Increments the source address
 *          0x1 (SINC_1): Decrements the source address
 *          0x2 (SINC_2): No change in the source address
 *          0x3 (SINC_3): No change in the source address
 * \param   dinc       dest Address Increment.
 *          0x0 (DINC_0): Increments the destination address
 *          0x1 (DINC_1): Decrements the destination address
 *          0x2 (DINC_2): No change in the destination address
 *          0x3 (DINC_3): No change in the destination address
 * \retval  None
 */
__STATIC_INLINE void
DMA_configAddrInc(uint32_t base, uint32_t sinc, uint32_t dinc)
{
    HWREG(base + DMA_O_CTL) = (HWREG(base + DMA_O_CTL) & (~(DMA_CTL_SINC | DMA_CTL_DINC))) | ((sinc << 9) | (dinc << 7));
}

/**
 * \brief   config Transfer Width
 *
 * \param   base          the base address of the DMA channel control registers.
 * \param   src_tr_width  source Transfer Width.
 *          0x0 (SRC_TR_WIDTH_0): Source transfer width is 8 bits
 *          0x1 (SRC_TR_WIDTH_1): Source transfer width is 16 bits
 *          0x2 (SRC_TR_WIDTH_2): Source transfer width is 32 bits
 *          0x3 (SRC_TR_WIDTH_3): Source transfer width is 64 bits
 *          0x4 (SRC_TR_WIDTH_4): Source transfer width is 128 bits
 *          0x5 (SRC_TR_WIDTH_5): Source transfer width is 256 bits
 *          0x6 (SRC_TR_WIDTH_6): Source transfer width is 256 bits
 *          0x7 (SRC_TR_WIDTH_7): Source transfer width is 256 bits
 * \param   dst_tr_width  dest Transfer Width.
 *          0x0 (DST_TR_WIDTH_0): Destination transfer width is 8 bits
 *          0x1 (DST_TR_WIDTH_1): Destination transfer width is 16 bits
 *          0x2 (DST_TR_WIDTH_2): Destination transfer width is 32 bits
 *          0x3 (DST_TR_WIDTH_3): Destination transfer width is 64 bits
 *          0x4 (DST_TR_WIDTH_4): Destination transfer width is 128 bits
 *          0x5 (DST_TR_WIDTH_5): Destination transfer width is 256 bits
 *          0x6 (DST_TR_WIDTH_6): Destination transfer width is 256 bits
 *          0x7 (DST_TR_WIDTH_7): Destination transfer width is 256 bits
 * \retval  None
 */
__STATIC_INLINE void
DMA_configTrWidth(uint32_t base, uint32_t src_tr_width, uint32_t dst_tr_width)
{
    HWREG(base + DMA_O_CTL) = (HWREG(base + DMA_O_CTL) & (~(DMA_CTL_SRC_TR_WIDTH | DMA_CTL_DST_TR_WIDTH))) | ((src_tr_width << 4) | (dst_tr_width << 1));
}


//*****************************************************************************
//
//! Enables a DMA channel interrupt source.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function enables the indicated DMA channel interrupt source.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_enableInterrupt(uint32_t base)
{
    //
    // Enable Current Channel interrupt.
    //
    HWREG(base + DMA_O_CTL) |= DMA_CTL_INT_EN;
}

//*****************************************************************************
//
//! Disables a DMA channel interrupt source.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function disables the indicated DMA channel interrupt source.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_disableInterrupt(uint32_t base)
{
    //
    // Disable Current Channel interrupt.
    //
    HWREG(base + DMA_O_CTL) &= (~DMA_CTL_INT_EN);
}

/**
 * \brief   "Assigns a hardware handshaking interface (0 : 15)"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   dest_per   Dest Hardware Interface
 * \param   src_per    Source Hardware Interface
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configHardwareInterface(uint32_t base, uint32_t dest_per, uint32_t src_per)
{
    ASSERT((dest_per >= 0U) && (dest_per <= 15U));
    ASSERT((src_per >= 0U) && (src_per <= 15U));

    DMAREGH(base, DMA_O_CFG) = ((DMAREGH(base, DMA_O_CFG) & (~((DMA_CFG_DEST_PER | DMA_CFG_SRC_PER) >> 32))) | (dest_per << 11) | (src_per << 7));
}

/**
 * \brief   "config protection control"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   protctl    Protection Control bits, 3 bits total for HPROT.
 *          CFGx.PROTCTL[1] to HPROT[1] privileged
 *          CFGx.PROTCTL[2] to HPROT[2] non-buffered
 *          CFGx.PROTCTL[3] to HPROT[3] non-cached
 *          ps: HPROT[0] is tied high
 * \retval  None
 */
__STATIC_INLINE void
DMA_configProtctl(uint32_t base, uint32_t protctl)
{
    ASSERT((protctl >= 0U) && (protctl <= 7U));

    DMAREGH(base, DMA_O_CFG) = ((DMAREGH(base, DMA_O_CFG) & (~(DMA_CFG_PROTCTL >> 32))) | (protctl << 2));
}

/**
 * \brief   "FIFO Mode Select"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   fifo_mode  fifo mode as bellow:
 *          0x0 (FIFO_MODE_0): Space/data available for single
 *          AHB transfer of the specified transfer width
 *          0x1 (FIFO_MODE_1): Data available is greater than or
 *          equal to half the FIFO depth for destination transfers and
 *          space available is greater than half the fifo depth for
 *          source transfers. The exceptions are at the end of a burst
 *          transaction request or at the end of a block transfer
 * \retval  None
 */
__STATIC_INLINE void
DMA_configFifoMode(uint32_t base, uint32_t fifo_mode)
{
    ASSERT((fifo_mode >= 0U) && (fifo_mode <= 1U));

    DMAREGH(base, DMA_O_CFG) = ((DMAREGH(base, DMA_O_CFG) & (~(DMA_CFG_FIFOMODE >> 32))) | (fifo_mode << 1));
}

/**
 * \brief   "Flow Control Mode"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   fc_mode  fc mode as bellow:
 *          0x0 (FCMODE_0): Source transaction requests are
 *          serviced when they occur. Data pre-fetching is enabled
 *          0x1 (FCMODE_1): Source transaction requests are not
 *          serviced until a destination transaction request occurs. In
 *           this mode, the amount of data transferred from the source
 *           is limited so that it is guaranteed to be transferred to the
 *           destination prior to block termination by the destination.
 *           Data pre-fetching is disabled.
 * \retval  None
 */
__STATIC_INLINE void
DMA_configFcMode(uint32_t base, uint32_t fc_mode)
{
    ASSERT((fc_mode >= 0U) && (fc_mode <= 1U));

    DMAREGH(base, DMA_O_CFG) = ((DMAREGH(base, DMA_O_CFG) & (~(DMA_CFG_FCMODE >> 32))) | fc_mode);
}

#if DMAC_HW_VER == 0x01
/**
 * \brief   "enable Automatic Reload"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_enableReload(uint32_t base)
{
    HWREG(base + DMA_O_CFG) |= (DMA_CFG_RELOAD_SRC | DMA_CFG_RELOAD_DST);
}

/**
 * \brief   "disable Automatic Reload"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_disableReload(uint32_t base)
{
    HWREG(base + DMA_O_CFG) &= (~(DMA_CFG_RELOAD_SRC | DMA_CFG_RELOAD_DST));
}

/**
 * \brief   "enable Automatic Reload"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_enableReloadDst(uint32_t base)
{
    HWREG(base + DMA_O_CFG) |= DMA_CFG_RELOAD_DST;
}

/**
 * \brief   "enable Automatic Reload"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_disableReloadDst(uint32_t base)
{
    HWREG(base + DMA_O_CFG) &= DMA_CFG_RELOAD_DST;
}

/**
 * \brief   "enable Automatic Reload"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_enableReloadSrc(uint32_t base)
{
    HWREG(base + DMA_O_CFG) |= DMA_CFG_RELOAD_SRC;
}

/**
 * \brief   "enable Automatic Reload"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_disableReloadSrc(uint32_t base)
{
    HWREG(base + DMA_O_CFG) &= DMA_CFG_RELOAD_SRC;
}
#endif

/**
 * \brief   "config Handshaking Interface Polarity"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   src_hs_pol   Source Handshaking Interface Polarity ,0 is Active high, 1 is Active low.
 * \param   dst_hs_pol   Dest Handshaking Interface Polarity ,0 is Active high, 1 is Active low.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configHandshakingInterfacePolarity(uint32_t base, uint32_t src_hs_pol, uint32_t dst_hs_pol)
{
    ASSERT((src_hs_pol >= 0U) && (src_hs_pol <= 1U));
    ASSERT((dst_hs_pol >= 0U) && (dst_hs_pol <= 1U));

    HWREG(base + DMA_O_CFG) = ((HWREG(base + DMA_O_CFG) & (~(DMA_CFG_SRC_HS_POL | DMA_CFG_DST_HS_POL))) | ((src_hs_pol << 19) | (dst_hs_pol << 18)));
}

/**
 * \brief   "Select Software or Hardware Handshaking"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   hs_sel_src   Source Handshaking Interface select, 0 is hardware, 1 is software.
 * \param   hs_sel_dst   Dest Handshaking Interface select, 0 is hardware, 1 is software.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configHandshakingInterface(uint32_t base, uint32_t hs_sel_src, uint32_t hs_sel_dst)
{
    ASSERT((hs_sel_src >= 0U) && (hs_sel_src <= 1U));
    ASSERT((hs_sel_dst >= 0U) && (hs_sel_dst <= 1U));

    HWREG(base + DMA_O_CFG) = ((HWREG(base + DMA_O_CFG) & (~(DMA_CFG_HS_SEL_SRC | DMA_CFG_HS_SEL_DST))) | ((hs_sel_src << 11) | (hs_sel_dst << 10)));
}

/**
 * \brief   "get Channel FIFO status"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  0 is not empty, 1 is empty
 */
__STATIC_INLINE bool
DMA_isFifoEmpty(uint32_t base)
{
    return ((HWREG(base + DMA_O_CFG) & DMA_CFG_FIFO_EMPTY) != 0);
}

/**
 * \brief   "channel suspend"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_suspendChannel(uint32_t base)
{
    HWREG(base + DMA_O_CFG) |= DMA_CFG_CH_SUSP;
}

/**
 * \brief   "channel resume"
 *
 * \param   base       the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_resumeChannel(uint32_t base)
{
    HWREG(base + DMA_O_CFG) &= (~DMA_CFG_CH_SUSP);
}


/**
 * \brief   "set channel priority"
 *
 * \param   base       the base address of the DMA channel control registers.
 * \param   prior      the channel priority to set .
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_setChannelPriority(uint32_t base, DMA_CHANNEL_PRIORITY prior)
{
    HWREG(base + DMA_O_CFG) = (HWREG(base + DMA_O_CFG) & (~DMA_CFG_CH_PRIOR)) | (prior << 5);
}


/**
 * \brief   "config channel ctrl"
 *
 * \param   base          the base address of the DMA channel control registers.
 * \param   ctl
 *          DONE             bit    44           Done bit.
 *          BLOCK_TS         bit    43:32        Block Transfer Size.
 *          TT_FC            bit    22:20        Transfer Type and Flow Control.
 *          DST_SCATTER_EN   bit    18           Destination scatter enable.
 *          SRC_GATHER_EN    bit    17           Source gather enable.
 *          SRC_MSIZE        bit    16:14        Source Burst Transaction Length.
 *          DEST_MSIZE       bit    13:11        Destination Burst Transaction Length.
 *          SINC             bit    10:9         Source Address Increment.
 *          DINC             bit    8:7          Destination Address Increment.
 *          SRC_TR_WIDTH     bit    6:4          Source Transfer Width.
 *          DST_TR_WIDTH     bit    3:1          Destination Transfer Width.
 *          INT_EN           bit    0            Interrupt Enable Bit.
 * \retval  None
 */
__STATIC_INLINE void
DMA_configChannelCTL(uint32_t base, uint64_t ctl)
{
    DMAREGH(base, DMA_O_CTL) = ((ctl >> 32) & 0xffffffff);
    DMAREGL(base, DMA_O_CTL) = (ctl & 0xffffffff);
}



/**
 * \brief   "config channel cfg"
 *
 * \param   base          the base address of the DMA channel control registers.
 * \param   cfg
 *          DEST_PER           bit    46:43        Assigns a Destination hardware interface.
 *          SRC_PER            bit    42:39        Assigns a Source Hardware Interface.
 *          PROTCTL            bit    36:34        Protection Control bits used to drive the AHB HPROT[3:1] bus.
 *          FIFO_MODE          bit    33           FIFO Mode Select.
 *          FCMODE             bit    32           Flow Control Mode.
 *          RELOAD_DST         bit    31           Automatic Destination Reload.
 *          RELOAD_SRC         bit    30           Automatic Source Reload.
 *          SRC_HS_POL         bit    19           Source Handshaking Interface Polarity
 *          DST_HS_POL         bit    18           Destination Handshaking Interface Polarity.
 *          HS_SEL_SRC         bit    11           Source Software or Hardware Handshaking Select.
 *          HS_SEL_DST         bit    10           Destination Software or Hardware Handshaking Select.
 *          CH_SUSP            bit    8            Channel Suspend.
 *          CH_PRIOR           bit    7:5          Channel Priority.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_configChannelCFG(uint32_t base, uint64_t cfg)
{
    DMAREGH(base, DMA_O_CFG) = ((cfg >> 32) & 0xffffffff);
    DMAREGL(base, DMA_O_CFG) = (cfg & 0xffffffff);
}

/**
 * \brief   "get channel ctrl"
 *
 * \param   base          the base address of the DMA channel control registers.
 * \retval  ctl value
 *          DONE             bit    44           Done bit.
 *          BLOCK_TS         bit    43:32        Block Transfer Size.
 *          TT_FC            bit    22:20        Transfer Type and Flow Control.
 *          DST_SCATTER_EN   bit    18           Destination scatter enable.
 *          SRC_GATHER_EN    bit    17           Source gather enable.
 *          SRC_MSIZE        bit    16:14        Source Burst Transaction Length.
 *          DEST_MSIZE       bit    13:11        Destination Burst Transaction Length.
 *          SINC             bit    10:9         Source Address Increment.
 *          DINC             bit    8:7          Destination Address Increment.
 *          SRC_TR_WIDTH     bit    6:4          Source Transfer Width.
 *          DST_TR_WIDTH     bit    3:1          Destination Transfer Width.
 *          INT_EN           bit    0            Interrupt Enable Bit.
 */
__STATIC_INLINE uint64_t
DMA_getChannelCTL(uint32_t base)
{
    return ((uint64_t)DMAREGH(base, DMA_O_CTL) << 32) + (uint64_t)DMAREGL(base, DMA_O_CTL);
}


/**
 * \brief   "get channel cfg"
 *
 * \param   base          the base address of the DMA channel control registers.
 * \retval  cfg value
 *          DEST_PER           bit    46:43        Assigns a Destination hardware interface.
 *          SRC_PER            bit    42:39        Assigns a Source Hardware Interface.
 *          PROTCTL            bit    36:34        Protection Control bits used to drive the AHB HPROT[3:1] bus.
 *          FIFO_MODE          bit    33           FIFO Mode Select.
 *          FCMODE             bit    32           Flow Control Mode.
 *          RELOAD_DST         bit    31           Automatic Destination Reload.
 *          RELOAD_SRC         bit    30           Automatic Source Reload.
 *          SRC_HS_POL         bit    19           Source Handshaking Interface Polarity
 *          DST_HS_POL         bit    18           Destination Handshaking Interface Polarity.
 *          HS_SEL_SRC         bit    11           Source Software or Hardware Handshaking Select.
 *          HS_SEL_DST         bit    10           Destination Software or Hardware Handshaking Select.
 *          FIFO_EMPTY         bit    9            Channel FIFO status.
 *          CH_SUSP            bit    8            Channel Suspend.
 *          CH_PRIOR           bit    7:5          Channel Priority.
 *
 */
__STATIC_INLINE uint64_t
DMA_getChannelCFG(uint32_t base)
{
    return ((uint64_t)DMAREGH(base, DMA_O_CFG) << 32) + (uint64_t)DMAREGL(base, DMA_O_CFG);
}


/**
 * \brief   "get Raw Interrupt Status"
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  status like bellow
            DMA_INT_TFR
            DMA_INT_BLOCK
            DMA_INT_SRCTRAN
            DMA_INT_DSTTRAN
            DMA_INT_ERR
 */
__STATIC_INLINE uint8_t
DMA_getRawInterruptStatus(uint32_t base)
{
    uint8_t status = 0U;
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);


    //
    //  Check raw Tfr interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_RAWTFR) & (1 << channel)) != 0)
        status |= DMA_INT_TFR;
    //
    //  Check raw Block interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_RAWBLOCK) & (1 << channel)) != 0)
        status |= DMA_INT_BLOCK;
    //
    //  Check raw SrcTran interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_RAWSRCTRAN) & (1 << channel)) != 0)
        status |= DMA_INT_SRCTRAN;
    //
    //  Check raw DstTran interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_RAWDSTTRAN) & (1 << channel)) != 0)
        status |= DMA_INT_DSTTRAN;
    //
    //  Check raw Err interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_RAWERR) & (1 << channel)) != 0)
        status |= DMA_INT_ERR;

    return status;
}

/**
 * \brief   "get Interrupt Status"
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  status like bellow
 *          DMA_INT_TFR
 *          DMA_INT_BLOCK
 *          DMA_INT_SRCTRAN
 *          DMA_INT_DSTTRAN
 *          DMA_INT_ERR
 *          DMA_INT_FDI
 */
__STATIC_INLINE uint8_t
DMA_getInterruptStatus(uint32_t base)
{
    uint8_t status = 0U;
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;
    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Check Tfr interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_STATUSTFR) & (1 << channel)) != 0)
        status |= DMA_INT_TFR;
    //
    //  Check Block interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_STATUSBLOCK) & (1 << channel)) != 0)
        status |= DMA_INT_BLOCK;
    //
    //  Check SrcTran interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_STATUSSRCTRAN) & (1 << channel)) != 0)
        status |= DMA_INT_SRCTRAN;
    //
    //  Check DstTran interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_STATUSDSTTRAN) & (1 << channel)) != 0)
        status |= DMA_INT_DSTTRAN;
    //
    //  Check Err interrupt status
    //
    if ((HWREG(dmacBase + DMA_O_STATUSERR) & (1 << channel)) != 0)
        status |= DMA_INT_ERR;

    return status;

}


//*****************************************************************************
//
//! Gets the block interrupt Status of the current DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//!
//! \return Returns \b true if the channel is enabled. Returns \b false
//! otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
DMA_getBlockInterruptStatus(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;
    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);


    //
    // Get the block interrupt status of current DMA channel.
    //
    if (HWREG(dmacBase + DMA_O_STATUSBLOCK) & (1 << channel))
        return true;
    else
        return false;
}

//*****************************************************************************
//
//! Gets the block interrupt Status of the current DMA channel.
//!
//! \param dmacBase is the base address of the DMA controler base.
//! \param nChannel is the current dma channel number.
//!
//!I
//! \return Returns \b true if the channel is block. Returns \b false
//! otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
DMA_getBlockInterruptStatusbyChns(uint32_t dmacBase, uint32_t nChannel)
{
    ASSERT(nChannel <= 7U);

    //
    // Get the block interrupt status of current DMA channel.
    //
    if (HWREG(dmacBase + DMA_O_STATUSBLOCK) & (1 << nChannel))
        return true;
    else
        return false;
}

//*****************************************************************************
//
//! Gets the block interrupt Status of the current DMA channel.
//!
//! \param dmacBase is the base address of the DMA controler base.
//! \param nChannel is the current dma channel number.
//!
//!
//! \return Returns \b true if the channel is enabled. Returns \b false
//! otherwise.
//
//*****************************************************************************
__STATIC_INLINE bool
DMA_getBlockInterruptStatusbyChnMsk(uint32_t dmacBase, uint32_t nChannelMask)
{
    ASSERT(nChannelMask <= 0xFFU);

    //
    // Get the block interrupt status of current DMA channel.
    //
    if (HWREG(dmacBase + DMA_O_STATUSBLOCK) & nChannelMask)
        return true;
    else
        return false;
}


//*****************************************************************************
//
//! clears the block interrupt Status of the current DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//!
//! \return none
//
//*****************************************************************************
__STATIC_INLINE void
DMA_clearBlockInterruptStatus(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Clear the block interrupt status of current DMA channel.
    //
    HWREG(dmacBase + DMA_O_CLEARBLOCK) = (1 << channel);
}

//*****************************************************************************
//
//! clears the block interrupt Status of the current DMA channel.
//!
//! \param dmacBase is the base address of the DMA controler base.
//! \param nChannel is the current dma channel number.
//!
//!
//! \return none
//
//*****************************************************************************
__STATIC_INLINE void
DMA_clearBlockInterruptStatusbyChns(uint32_t dmacBase, uint32_t nChannel)
{
    ASSERT(nChannel <= 7U);

    //
    // Clear the block interrupt status of current DMA channel.
    //
    HWREG(dmacBase + DMA_O_CLEARBLOCK) = (1 << nChannel);
}


/**
 * \brief   "mask Interrupt"
 *
 * \param   base   the base address of the DMA channel control registers.
 * \param   mask   interrupt to mask, as bellow
 *          DMA_INT_TFR
 *          DMA_INT_BLOCK
 *          DMA_INT_SRCTRAN
 *          DMA_INT_DSTTRAN
 *          DMA_INT_ERR
 *          DMA_INT_FDI
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_maskInterrupt(uint32_t base, uint8_t mask)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Check Tfr interrupt mask, if mask contain Tfr, set mask and enable
    //
    if (mask & DMA_INT_TFR)
        HWREG(dmacBase + DMA_O_MASKTFR) = (HWREG(dmacBase + DMA_O_MASKTFR) | (1 << (8 + channel))) & (~(1 << channel));
    //
    //  Check Block interrupt mask, if mask contain Block, set mask and enable
    //
    if (mask & DMA_INT_BLOCK)
        HWREG(dmacBase + DMA_O_MASKBLOCK) = (HWREG(dmacBase + DMA_O_MASKBLOCK) | (1 << (8 + channel))) & (~(1 << channel));
    //
    //  Check SrcTran interrupt mask, if mask contain SrcTran, set mask and enable
    //
    if (mask & DMA_INT_SRCTRAN)
        HWREG(dmacBase + DMA_O_MASKSRCTRAN) = (HWREG(dmacBase + DMA_O_MASKSRCTRAN) | (1 << (8 + channel))) & (~(1 << channel));
    //
    //  Check DstTran interrupt mask, if mask contain DstTran, set mask and enable
    //
    if (mask & DMA_INT_DSTTRAN)
        HWREG(dmacBase + DMA_O_MASKDSTTRAN) = (HWREG(dmacBase + DMA_O_MASKDSTTRAN) | (1 << (8 + channel))) & (~(1 << channel));
    //
    //  Check Err interrupt mask, if mask contain Err, set mask and enable
    //
    if (mask & DMA_INT_ERR)
        HWREG(dmacBase + DMA_O_MASKERR) = (HWREG(dmacBase + DMA_O_MASKERR) | (1 << (8 + channel))) & (~(1 << channel));


}


/**
 * \brief   "unmask Interrupt"
 *
 * \param   base   the base address of the DMA channel control registers.
 * \param   mask   interrupt to unmask, as bellow
 *          DMA_INT_TFR
 *          DMA_INT_BLOCK
 *          DMA_INT_SRCTRAN
 *          DMA_INT_DSTTRAN
 *          DMA_INT_ERR
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_unMaskInterrupt(uint32_t base, uint8_t mask)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Check Tfr interrupt mask, if mask contain Tfr, set un-mask and enable
    //
    if (mask & DMA_INT_TFR)
        HWREG(dmacBase + DMA_O_MASKTFR) |= ((1 << (8 + channel)) | (1 << channel));
    //
    //  Check Block interrupt mask, if mask contain Block, set un-mask and enable
    //
    if (mask & DMA_INT_BLOCK)
        HWREG(dmacBase + DMA_O_MASKBLOCK) |= ((1 << (8 + channel)) | (1 << channel));
    //
    //  Check SrcTran interrupt mask, if mask contain SrcTran, set un-mask and enable
    //
    if (mask & DMA_INT_SRCTRAN)
        HWREG(dmacBase + DMA_O_MASKSRCTRAN) |= ((1 << (8 + channel)) | (1 << channel));
    //
    //  Check DstTran interrupt mask, if mask contain DstTran, set un-mask and enable
    //
    if (mask & DMA_INT_DSTTRAN)
        HWREG(dmacBase + DMA_O_MASKDSTTRAN) |= ((1 << (8 + channel)) | (1 << channel));
    //
    //  Check Err interrupt mask, if mask contain Err, set un-mask and enable
    //
    if (mask & DMA_INT_ERR)
        HWREG(dmacBase + DMA_O_MASKERR) |= ((1 << (8 + channel)) | (1 << channel));

}



/**
 * \brief   clear Interrupt
 *
 * \param   base   the base address of the DMA channel control registers.
 * \param   mask   interrupt to clear, as bellow
 *          DMA_INT_TFR
 *          DMA_INT_BLOCK
 *          DMA_INT_SRCTRAN
 *          DMA_INT_DSTTRAN
 *          DMA_INT_ERR
 *          DMA_INT_FDI
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_clearInterrupt(uint32_t base, uint8_t clear)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Check Tfr interrupt clear mask, if the clear mask contain Tfr, clear all TFR interrupt status.
    //
    if (clear & DMA_INT_TFR)
        HWREG(dmacBase + DMA_O_CLEARTFR) = (1 << channel);
    //
    //  Check Block interrupt clear mask, if the clear mask contain Block, clear all Block interrupt status.
    //
    if (clear & DMA_INT_BLOCK)
        HWREG(dmacBase + DMA_O_CLEARBLOCK) = (1 << channel);
    //
    //  Check SrcTran interrupt clear mask, if the clear mask contain SrcTran, clear all SrcTran interrupt status.
    //
    if (clear & DMA_INT_SRCTRAN)
        HWREG(dmacBase + DMA_O_CLEARSRCTRAN) = (1 << channel);
    //
    //  Check DstTran interrupt clear mask, if the clear mask contain DstTran, clear all DstTran status.
    //
    if (clear & DMA_INT_DSTTRAN)
        HWREG(dmacBase + DMA_O_CLEARDSTTRAN) = (1 << channel);

    if (clear & DMA_INT_ERR)
        HWREG(dmacBase + DMA_O_CLEARERR) = (1 << channel);

}

//*****************************************************************************
//
//! Clears the DMA channel error flags.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function clears both the DMA channel's sync error flag and its
//! overrun error flag.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_clearErrorFlag(uint32_t base)
{
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to dmac base address.
    //
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // clear the whole dmac of the current channel 's Err interrupts.
    //
    HWREG(dmacBase + DMA_O_CLEARERR) |= DMA_CLEARERR_CLEAR;
}

__STATIC_INLINE uint8_t
DMA_getDMAInterruptStatus(uint32_t dmacbase, uint8_t type)
{

    uint8_t status;
    //
    //  Check Tfr interrupt status
    //
    if (type & DMA_INT_TFR)
    {
        if ((HWREG(dmacbase + DMA_O_STATUSINT) & (DMA_INT_TFR)) != 0)
                status |= DMA_INT_TFR;

    }

    //
    //  Check Block interrupt status
    //
    if (type & DMA_INT_BLOCK)
    {
        if ((HWREG(dmacbase + DMA_O_STATUSINT) & (DMA_INT_BLOCK)) != 0)
                status |= DMA_INT_BLOCK;
    }
    //
    //  Check SrcTran interrupt status
    //
    if (type & DMA_INT_SRCTRAN)
    {
        if ((HWREG(dmacbase + DMA_O_STATUSINT) & (DMA_INT_SRCTRAN)) != 0)
               status |= DMA_INT_SRCTRAN;
    }
    //
    //  Check DstTran interrupt status
    //
    if (type & DMA_INT_DSTTRAN)
    {
        if ((HWREG(dmacbase + DMA_O_STATUSINT) & (DMA_INT_DSTTRAN)) != 0)
               status |= DMA_INT_DSTTRAN;
    }
    //
    //  Check raw Err interrupt status
    //
    if (type & DMA_INT_ERR)
    {
        if ((HWREG(dmacbase + DMA_O_STATUSINT) & (DMA_INT_ERR)) != 0)
               status |= DMA_INT_ERR;
    }

    return status;
}

//*****************************************************************************
//
//! Force a peripheral trigger to a DMA channel.
//!
//! \param base is the base address of the DMA channel control registers.
//!
//! This function sets the peripheral trigger flag and if triggering a DMA
//! burst is enabled (see DMA_enableTrigger()), a DMA burst transfer will be
//! forced.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
DMA_forceTrigger(uint32_t base)  //?
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    // Config the channel to Softeware handshaking, Both for Ssource and Destination.
    //
    HWREG(base + DMA_O_CFG) |= (DMA_CFG_HS_SEL_SRC | DMA_CFG_HS_SEL_DST);

    //
    // Enable and Active source software transaction request for the DMA controller
    //
    HWREG(dmacBase + DMA_O_REQSRCREG) |= ((1 << channel) | (1 << (8 + channel)));

    //
    // Enable and Active destination software transaction request for the DMA controller
    //
    HWREG(dmacBase + DMA_O_REQDSTREG) |= ((1 << channel) | (1 << (8 + channel)));

    //
    // Enable and Active source Single transaction request for the DMA controller
    //
    HWREG(dmacBase + DMA_O_SGLRQSRCREG) |= ((1 << channel) | (1 << (8 + channel)));

    //
    // Enable and Active destination single transaction request for the DMA controller
    //
    HWREG(dmacBase + DMA_O_SGLRQDSTREG) |= ((1 << channel) | (1 << (8 + channel)));
}


/**
 * \brief   Source Software Transaction Request
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_ReqSrcSoftwareTransaction(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);


    //
    //  Set source software transaction request enable and active
    //
    HWREG(dmacBase + DMA_O_REQSRCREG) |= ((1 << channel) | (1 << (8 + channel)));
}




/**
 * \brief   Destination Software Transaction Request
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_ReqDstSoftwareTransaction(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Set Destination software transactionrequest enable and active
    //
    HWREG(dmacBase + DMA_O_REQDSTREG)|= ((1 << channel) | (1 << (8 + channel)));
}

/**
 * \brief   Source Software Sigle Transaction Request
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_ReqSglSrcSoftwareTransaction(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Set Source single transaction request enable and active
    //
    HWREG(dmacBase + DMA_O_SGLRQSRCREG) |= ((1 << channel) | (1 << (8 + channel)));
}

/**
 * \brief   Destination Software Sigle Transaction Request
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_ReqSglDstSoftwareTransaction(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Set Destination single transaction request enable and active
    //
    HWREG(dmacBase + DMA_O_SGLRQDSTREG) |= ((1 << channel) | (1 << (8 + channel)));
}

/**
 * \brief   Last Source Software Transaction Request
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_ReqlstSrcSoftwareTransaction(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Set Source Last transaction request enable and active
    //
    HWREG(dmacBase + DMA_O_LSTSRCREG) |= ((1 << channel) | (1 << (8 + channel)));
}


/**
 * \brief   Last Destination Software Transaction Request
 *
 * \param   base   the base address of the DMA channel control registers.
 *
 * \retval  None
 */
__STATIC_INLINE void
DMA_ReqlstDstSoftwareTransaction(uint32_t base)
{
    uint32_t channel = 0U;
    uint32_t dmacBase = 0U;

    //
    // Covert the channel base to channel number and dmac base address.
    //
    channel = DMA_convertChnBase2ChnNum(base);
    dmacBase = DMA_convertChnBase2DmaBase(base);

    //
    //  Set Destination Last transaction request enable and active
    //
    HWREG(dmacBase + DMA_O_LSTDSTREG) |= ((1 << channel) | (1 << (8 + channel)));
}


extern void
DMA_configParameter(DMA_ConfigParams *Params);
//*****************************************************************************
//
//! Setup DMA to transfer data on the specified channel.
//!
//! \param base is Base address of the DMA channel control register
//! \param *transfParams configuration parameter
//!                      Refer struct #DMA_ConfigParams
//!
//! This function configures the DMA transfer on the specified channel.
//!
//! \return None.
//
//*****************************************************************************
extern void
DMA_configChannel(uint32_t base, const DMA_ConfigParams *transfParams);
//*****************************************************************************
//
//! Clear DMA setting from previous transfer data on the specified channel.
//!
//! \param base is Base address of the DMA channel control register
//! \param *transfParams configuration parameter
//!                      Refer struct #DMA_ConfigParams
//!
//! This function configures the DMA transfer on the specified channel.
//!
//! \return None.
//
//*****************************************************************************
extern void
DMA_DeConfChannel(uint32_t base);

/**
 * \brief   config channel parameters
 *
 * \param   base          the base address of the DMA channel control registers.
 * \retval  chParams      the parameters of channel config inclue:
 *                        channel ctl, channel cfg,dmamux ccr and dmamux rgcr
 *
 */


//*****************************************************************************
//
//! Configures the DMA channel
//!
//! \param base is the base address of the DMA channel control registers.
//! \param *destAddr is the destination address.
//! \param *srcAddr is a source address.
//!
//! This function configures the source and destination addresses of a DMA
//! channel. The parameters are pointers to the data to be transferred.
//!
//! \return None.
//
//*****************************************************************************
extern void
DMA_configAddresses(uint32_t base, uint32_t destAddr, uint32_t srcAddr);

//*****************************************************************************
//
//! Configures the DMA channel's burst settings.
//!
//! \param base is the base address of the DMA channel control registers.
//! \param size is the number of words transferred per burst.
//! \param srcStep is the amount to increment or decrement the source address
//! after each word of a burst.
//! \param destStep is the amount to increment or decrement the destination
//! address after each word of a burst.
//!
//! This function configures the size of each burst and the address step size.
//!
//! The \e size parameter is the number of words that will be transferred
//! during a single burst. Possible amounts range from 1 word to 32 words.
//!
//! The \e srcStep and \e destStep parameters is not support
//!
//! \note Note that regardless of what data size (configured by
//! DMA_configMode()) is used, parameters are in terms of 16-bits words.
//!       Note that DMA_configBurst must be called before DMA_configTransfer
//! \return None.
//
//*****************************************************************************
extern void
DMA_configBurst(uint32_t base, uint16_t size, int16_t srcStep,
                            int16_t destStep);

#if DMAC_HW_VER == 0x01
extern void
DMA_configLLP(uint32_t base, DMA_LLI loc, DMA_MasterInfSelect lms );
#endif

extern void
DMA_configTransfer(uint32_t base, uint32_t transferSize, int16_t srcStep,
                        int16_t destStep);



#if DMAC_HW_VER == 0x00

//driver 2 ***********************************

/** @defgroup DMAC_Exported_Constants DMAC Exported Constants
  * @{
  */

#define HAL_DMAC_INT_DISABLE          (0x0UL)
#define HAL_DMAC_INT_ENABLE           (0x1UL)

/**
  * @defgroup HAL_DMAC_TRANSWIDTHTypeDef DMAC Transaction Data Width definition
  */
#define HAL_DMAC_TRANSWIDTHT_32BITS   (2UL)
#define HAL_DMAC_TRANSWIDTHT_16BITS   (1UL)
#define HAL_DMAC_TRANSWIDTHT_8BITS    (0UL)

/**
  * @defgroup HAL_DMAC_ADDROPRTypeDef DMAC Address Operator definition
  */
#define HAL_DMAC_ADDR_INC             0
#define HAL_DMAC_ADDR_DEC             1
#define HAL_DMAC_ADDR_CONSTANT        2

/**
  * @defgroup HAL_DMAC_BURSTSIZETypeDef DMAC Burst Size definition
  */
#define HAL_DMAC_BURSTSIZE_1          (0UL)
#define HAL_DMAC_BURSTSIZE_4          (1UL)
#define HAL_DMAC_BURSTSIZE_8          (2UL)
#define HAL_DMAC_BURSTSIZE_16         (3UL)
#define HAL_DMAC_BURSTSIZE_32         (4UL)
/**
  * @defgroup HAL_DMAC_TRANSTYPETypeDef DMAC Transfer Type definition
  */
#define HAL_DMAC_TRANSTYPE_MEM2MEM    DMAC_CTRLA_TRANSTYPE_MEM2MEM
#define HAL_DMAC_TRANSTYPE_MEM2PERI   DMAC_CTRLA_TRANSTYPE_MEM2PERI
#define HAL_DMAC_TRANSTYPE_PERI2MEM   DMAC_CTRLA_TRANSTYPE_PERI2MEM
#define HAL_DMAC_TRANSTYPE_PERI2PERI  DMAC_CTRLA_TRANSTYPE_PERI2PERI


#define HAL_DMAC_MASTER_1             (0UL)
#define HAL_DMAC_MASTER_2             (1UL)

#define HAL_DMAC_DONE_Set             DMAC_CTRLB_DONE_Msk
#define HAL_DMAC_DONE_ReSet           (0UL)

#define HAL_DMAC_PRIOR_0              (0x00UL)
#define HAL_DMAC_PRIOR_1              (0x20UL)
#define HAL_DMAC_PRIOR_2              (0x40UL)
#define HAL_DMAC_PRIOR_3              (0x60UL)
#define HAL_DMAC_PRIOR_4              (0x80UL)
#define HAL_DMAC_PRIOR_5              (0xA0UL)
#define HAL_DMAC_PRIOR_6              (0xC0UL)
#define HAL_DMAC_PRIOR_7              (0xE0UL)

#define HAL_DMAC_SUSP_DISABLE            (0x000UL)
#define HAL_DMAC_SUSP_ENABLE             (0x100UL)

#define HAL_DMAC_HSSEL_HW             (0UL)
#define HAL_DMAC_HSSEL_SW             (1UL)

#define HAL_DMAC_POL_HIGH             (0UL)
#define HAL_DMAC_POL_LOW              (1UL)


/**
  * @defgroup HAL_DMAC_HSTypeDef DMAC Handshaking Interface definition
 */
#define HAL_DMAC_HS_PERI_0      (0)
#define HAL_DMAC_HS_PERI_1      (1)
#define HAL_DMAC_HS_PERI_2      (2)
#define HAL_DMAC_HS_PERI_3      (3)
#define HAL_DMAC_HS_PERI_4      (4)
#define HAL_DMAC_HS_PERI_5      (5)
#define HAL_DMAC_HS_PERI_6      (6)
#define HAL_DMAC_HS_PERI_7      (7)
#define HAL_DMAC_HS_PERI_8      (8)
#define HAL_DMAC_HS_PERI_9      (9)
#define HAL_DMAC_HS_PERI_10     (10)
#define HAL_DMAC_HS_PERI_11     (11)
#define HAL_DMAC_HS_PERI_12     (12)
#define HAL_DMAC_HS_PERI_13     (13)
#define HAL_DMAC_HS_PERI_14     (14)
#define HAL_DMAC_HS_PERI_15     (15)

#define HAL_DMAC_FIFO_MODE_0          (0x0UL)
#define HAL_DMAC_FIFO_MODE_1          (0x2UL)

#define HAL_DMAC_TESTMODE_OFF         (0UL)
#define HAL_DMAC_TESTMODE_ON          (1UL)

#define HAL_DMAC_INT_MASK (0UL)
#define HAL_DMAC_INT_UNMASK (1UL)

#define HAL_DMAC_CHANNEL1   (0U)
#define HAL_DMAC_CHANNEL2   (1U)
#define HAL_DMAC_CHANNEL3   (2U)
#define HAL_DMAC_CHANNEL4   (3U)


/* Init function      ********************************/

//*****************************************************************************
// This function sets the interrupt control for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set interrupt for
//! \param status is the interrupt status to be set
//*****************************************************************************
void DMAC_Set_INT(uint32_t base, int ch, uint32_t status);

//*****************************************************************************
// This function sets the data width for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set data width for
//! \param trWidth is the data width to be set (e.g., 8-bit, 16-bit, 32-bit)
//*****************************************************************************
void DMAC_Set_DATAWIDTH(uint32_t base, int ch, uint32_t trWidth);

//*****************************************************************************
// This function sets the address increment mode for source and destination of a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set address increment for
//! \param srcInc is the source address increment mode
//! \param dstInc is the destination address increment mode
//*****************************************************************************
void DMAC_Set_ADDRINC(uint32_t base, int ch, uint32_t srcInc,
        uint32_t dstInc);
        
//*****************************************************************************
// This function sets the burst length for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set burst length for
//! \param burstLength is the burst length to be set
//*****************************************************************************
void DMAC_Set_BurstLength(uint32_t base, int ch, uint32_t burstLength);

//*****************************************************************************
// This function sets the transfer type for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set transfer type for
//! \param trType is the transfer type to be set
//*****************************************************************************
void DMAC_Set_TransType(uint32_t base, int ch, uint32_t trType);

//*****************************************************************************
// This function sets the master for source and destination of a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set channel master for
//! \param srcMaster is the source master configuration
//! \param dstMaster is the destination master configuration
//*****************************************************************************
void DMAC_Set_Channelmaster(uint32_t base, int ch, uint32_t srcMaster,
        uint32_t dstMaster);

//*****************************************************************************
// This function sets the block number for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set block number for
//! \param totalNum is the total number of blocks to be set
//*****************************************************************************
void DMAC_Set_BlockNum(uint32_t base, int ch, uint32_t totalNum);

//*****************************************************************************
// This function reads the block count for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to read block count from
//! \return int32_t value representing the current block count
//*****************************************************************************
int32_t DMAC_Read_Block(uint32_t base, int ch);

//*****************************************************************************
// This function reads the done status for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to read done status from
//! \return Status indicating completion status (1 for completed, 0 for not completed)
//*****************************************************************************
Status DMAC_Read_Done(uint32_t base, int ch);

//*****************************************************************************
// This function resets the done flag for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to reset done flag for
//*****************************************************************************
void DMAC_Reset_Done(uint32_t base, int ch);

//*****************************************************************************
// This function sets the done flag for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set done flag for
//*****************************************************************************
void DMAC_Set_Done(uint32_t base, int ch);

//*****************************************************************************
// This function sets the source and destination addresses for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set addresses for
//! \param srcAddr is the source address to be set
//! \param dstAddr is the destination address to be set
//*****************************************************************************
void DMAC_Set_ADDR(uint32_t base, int ch, uint32_t srcAddr,
        uint32_t dstAddr);

//*****************************************************************************
//! This function sets the priority level for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to set priority for.
//! \param prior is the priority level to be set.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_Prior(uint32_t base, int ch, uint32_t prior);

//*****************************************************************************
//! This function stops a specific DMA channel from operation.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to stop.
//! 
//! \return None
//*****************************************************************************
void DMAC_Stop_Channel(uint32_t base, int ch);

//*****************************************************************************
//! This function restarts a previously stopped DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to restart.
//! 
//! \return None
//*****************************************************************************
void DMAC_ReStart_Channel(uint32_t base, int ch);

//*****************************************************************************
//! This function reads the FIFO empty status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating FIFO state: Set (1) indicates the FIFO is empty;
//!         Reset (0) indicates the FIFO is not empty.
//*****************************************************************************
Status DMAC_Read_FIFOEMPTY(uint32_t base, int ch);

//*****************************************************************************
//! This function sets the handshaking mode for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to configure.
//! \param srcHandShaking specifies the source handshaking mode (software or hardware).
//! \param dstHandShaking specifies the destination handshaking mode (software or hardware).
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_Handshaking(uint32_t base, int ch,
        uint32_t srcHandShaking, uint32_t dstHandShaking);

//*****************************************************************************
//! This function sets the handshaking polarity for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to configure.
//! \param srcPOL specifies the source handshaking polarity.
//! \param dstPOL specifies the destination handshaking polarity.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_HS_POL(uint32_t base, int ch,
        uint32_t srcPOL, uint32_t dstPOL);

//*****************************************************************************
//! This function sets the FIFO mode for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to configure.
//! \param mode specifies the FIFO mode to be set.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_FIFOMODE(uint32_t base, int ch, uint32_t mode);
//*****************************************************************************
//! This function assigns hardware handshaking interfaces to a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to configure.
//! \param srcDevice specifies the source hardware interface to be assigned.
//! \param dstDevice specifies the destination hardware interface to be assigned.
//! 
//! \return None
//*****************************************************************************
void DMAC_Assign_Hdhs_Interface(uint32_t base, int ch,
        uint32_t srcDevice, uint32_t dstDevice);

//*****************************************************************************
//! This function sets a source software transaction request for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to set the request for.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_SrcReq(uint32_t base, int ch);

//*****************************************************************************
//! This function sets a destination software transaction request for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to set the request for.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_DstReq(uint32_t base, int ch);

//*****************************************************************************
//! This function sets a single source transaction request for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to set the request for.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_SglSrcReq(uint32_t base, int ch);

//*****************************************************************************
//! This function sets a single destination transaction request for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to set the request for.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_SglDstReq(uint32_t base, int ch);

//*****************************************************************************
//! This function sets a last source transaction request for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to set the request for.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_LstSrcReq(uint32_t base, int ch);

//*****************************************************************************
//! This function sets a last destination transaction request for a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to set the request for.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_LstDstReq(uint32_t base, int ch);

//*****************************************************************************
//! This function enables the DMA controller.
//! 
//! \param base is the base address of the DMA controller.
//! 
//! \return None
//*****************************************************************************
void DMAC_ENABLE(uint32_t base);

//*****************************************************************************
//! This function disables the DMA controller.
//! 
//! \param base is the base address of the DMA controller.
//! 
//! \return None
//*****************************************************************************
void DMAC_DISABLE(uint32_t base);

//*****************************************************************************
//! This function enables a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to enable.
//! 
//! \return None
//*****************************************************************************
void DMAC_CHANNEL_ENABLE(uint32_t base, int ch);

//*****************************************************************************
//! This function disables a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to disable.
//! 
//! \return None
//*****************************************************************************
void DMAC_CHANNEL_DISABLE(uint32_t base, int ch);

//*****************************************************************************
//! This function reads the enable status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating whether the channel is enabled (1) or disabled (0).
//*****************************************************************************
Status DMAC_READ_CHANNELEN(uint32_t base, int ch);

//*****************************************************************************
//! This function sets the test mode for the DMA controller.
//! 
//! \param base is the base address of the DMA controller.
//! \param status specifies the test mode status to be set.
//! 
//! \return None
//*****************************************************************************
void DMAC_Set_TestMode(uint32_t base, uint32_t status);

//*****************************************************************************
//! This function reads the raw transfer interrupt status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating the raw transfer interrupt status.
//*****************************************************************************
Status DMAC_ReadCH_RawTfr(uint32_t base, int ch);

//*****************************************************************************
//! This function reads the raw block transfer interrupt status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating the raw block transfer interrupt status.
//*****************************************************************************
Status DMAC_ReadCH_RawBlock(uint32_t base, int ch);

//*****************************************************************************
//! This function reads the raw source transaction interrupt status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating the raw source transaction interrupt status.
//*****************************************************************************
Status DMAC_ReadCH_RawSrcTran(uint32_t base, int ch);

//*****************************************************************************
//! This function reads the raw destination transaction interrupt status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating the raw destination transaction interrupt status.
//*****************************************************************************
Status DMAC_ReadCH_RawDstTran(uint32_t base, int ch);

//*****************************************************************************
//! This function reads the raw error interrupt status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating the raw error interrupt status.
//*****************************************************************************
Status DMAC_ReadCH_RawErr(uint32_t base, int ch);

//*****************************************************************************
//! This function reads the raw transfer interrupt status for all DMA channels.
//! 
//! \param base is the base address of the DMA controller.
//! 
//! \return uint32_t value representing the raw transfer interrupt status for all channels.
//*****************************************************************************
uint32_t DMAC_Read_RawTfr(uint32_t base);

//*****************************************************************************
//! This function reads the raw block transfer interrupt status for all DMA channels.
//! 
//! \param base is the base address of the DMA controller.
//! 
//! \return uint32_t value representing the raw block transfer interrupt status for all channels.
//*****************************************************************************
uint32_t DMAC_Read_RawBlock(uint32_t base);

//*****************************************************************************
//! This function reads the raw source transaction interrupt status for all DMA channels.
//! 
//! \param base is the base address of the DMA controller.
//! 
//! \return uint32_t value representing the raw source transaction interrupt status for all channels.
//*****************************************************************************
uint32_t DMAC_Read_RawSrcTran(uint32_t base);

//*****************************************************************************
//! This function reads the raw destination transaction interrupt status for all DMA channels.
//! 
//! \param base is the base address of the DMA controller.
//! 
//! \return uint32_t value representing the raw destination transaction interrupt status for all channels.
//*****************************************************************************
uint32_t DMAC_Read_RawDstTran(uint32_t base);

//*****************************************************************************
//! This function reads the raw error interrupt status for all DMA channels.
//! 
//! \param base is the base address of the DMA controller.
//! 
//! \return uint32_t value representing the raw error interrupt status for all channels.
//*****************************************************************************
uint32_t DMAC_Read_RawErr(uint32_t base);

//*****************************************************************************
//! This function reads the masked transfer interrupt status of a specific DMA channel.
//! 
//! \param base is the base address of the DMA controller.
//! \param ch is the channel number to check.
//! 
//! \return Status indicating the masked transfer interrupt status.
//*****************************************************************************
Status DMAC_ReadCH_StatusTfr(uint32_t base, int ch);

//*****************************************************************************
// This function reads the masked block transfer interrupt status for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return Status indicating the masked block transfer interrupt status
Status DMAC_ReadCH_StatusBlock(uint32_t base, int ch);

//*****************************************************************************
// This function reads the masked source transaction interrupt status for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return Status indicating the masked source transaction interrupt status
Status DMAC_ReadCH_StatusSrcTran(uint32_t base, int ch);

//*****************************************************************************
// This function reads the masked destination transaction interrupt status for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return Status indicating the masked destination transaction interrupt status
Status DMAC_ReadCH_StatusDstTran(uint32_t base, int ch);

//*****************************************************************************
// This function reads the masked error interrupt status for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return Status indicating the masked error interrupt status
Status DMAC_ReadCH_StatusErr(uint32_t base, int ch);

//*****************************************************************************
// This function reads the masked transfer interrupt status for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return uint32_t value representing the masked transfer interrupt status for all channels
uint32_t DMAC_Read_StatusTfr(uint32_t base);

//*****************************************************************************
// This function reads the masked block transfer interrupt status for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return uint32_t value representing the masked block transfer interrupt status for all channels
uint32_t DMAC_Read_StatusBlock(uint32_t base);

//*****************************************************************************
// This function reads the masked source transaction interrupt status for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return uint32_t value representing the masked source transaction interrupt status for all channels
uint32_t DMAC_Read_StatusSrcTran(uint32_t base);

//*****************************************************************************
// This function reads the masked destination transaction interrupt status for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return uint32_t value representing the masked destination transaction interrupt status for all channels
uint32_t DMAC_Read_StatusDstTran(uint32_t base);

//*****************************************************************************
// This function reads the masked error interrupt status for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return uint32_t value representing the masked error interrupt status for all channels
uint32_t DMAC_Read_StatusErr(uint32_t base);

//*****************************************************************************
// This function sets the mask for transfer interrupts on a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set the mask for
//! \param status is the mask status (0 to disable mask, non-zero to enable mask)
void DMAC_Set_MaskTfr(uint32_t base, int ch, uint32_t status);

//*****************************************************************************
// This function sets the mask for block transfer interrupts on a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set the mask for
//! \param status is the mask status (0 to disable mask, non-zero to enable mask)
void DMAC_Set_MaskBlock(uint32_t base, int ch, uint32_t status);

//*****************************************************************************
// This function sets the mask for source transaction interrupts on a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set the mask for
//! \param status is the mask status (0 to disable mask, non-zero to enable mask)
void DMAC_Set_MaskSrcTran(uint32_t base, int ch, uint32_t status);

//*****************************************************************************
// This function sets the mask for destination transaction interrupts on a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set the mask for
//! \param status is the mask status (0 to disable mask, non-zero to enable mask)
void DMAC_Set_MaskDstTran(uint32_t base, int ch, uint32_t status);

//*****************************************************************************
// This function sets the mask for error interrupts on a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to set the mask for
//! \param status is the mask status (0 to disable mask, non-zero to enable mask)
void DMAC_Set_MaskErr(uint32_t base, int ch, uint32_t status);

//*****************************************************************************
// This function clears the transfer interrupt flag for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to clear the interrupt flag for
void DMAC_ClearCH_Tfr(uint32_t base, int ch);

//*****************************************************************************
// This function clears the block transfer interrupt flag for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to clear the interrupt flag for
void DMAC_ClearCH_Block(uint32_t base, int ch);

//*****************************************************************************
// This function clears the source transaction interrupt flag for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to clear the interrupt flag for
void DMAC_ClearCH_SrcTran(uint32_t base, int ch);

//*****************************************************************************
// This function clears the destination transaction interrupt flag for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to clear the interrupt flag for
void DMAC_ClearCH_DstTran(uint32_t base, int ch);

//*****************************************************************************
// This function clears the error interrupt flag for a specific DMA channel.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \param ch is the channel number to clear the interrupt flag for
void DMAC_ClearCH_Err(uint32_t base, int ch);

//*****************************************************************************
// This function clears the transfer interrupt flags for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
void DMAC_Clear_Tfr(uint32_t base);

//*****************************************************************************
// This function clears the block transfer interrupt flags for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
void DMAC_Clear_Block(uint32_t base);

//*****************************************************************************
// This function clears the source transaction interrupt flags for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
void DMAC_Clear_SrcTran(uint32_t base);

//*****************************************************************************
// This function clears the destination transaction interrupt flags for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
void DMAC_Clear_DstTran(uint32_t base);

//*****************************************************************************
// This function clears the error interrupt flags for all DMA channels.
//*****************************************************************************
//! \param base is the base address of the DMA controller
void DMAC_Clear_Err(uint32_t base);

//*****************************************************************************
// This function reads the status interrupt for the DMA controller.
//*****************************************************************************
//! \param base is the base address of the DMA controller
//! \return uint32_t value representing the status interrupt
uint32_t DMAC_Read_StausInt(uint32_t base);

#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif 
