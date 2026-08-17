/** 
  ************************************************************************************* 
  * @file hw_can.h 
  * @brief This file contains the definition of hw_can driver. 
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

#ifndef _HW_CAN_H_
#define _HW_CAN_H_

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief The following is define of CAN CTRL IP register offset.
 *
 */
#define CAN_O_RBUF			0x0U  /*RBUF and RTS,   Tbuf only can be written with the format of uint32_t*/

#define CAN_O_TBUF			0x50U /*TBUF,buf only can be read with the format of uint32_t*/

#define CAN_O_TTS_L			0x98U
#define CAN_O_TTS_H			0x9CU

#define CAN_O_CFG_STAT		0xA0U		/* Configuration and Status Register. */
#define CAN_O_TCMD			0xA0U		/* Command Register. */
#define CAN_O_TCTRL			0xA0U		/* Transmit Control Register. */
#define CAN_O_RCTRL			0xA0U		/* Receive Control Register. */
#define CAN_O_RTIE			0xA4U		/* Receive and Transmit Interrupt Enable Register. */
#define CAN_O_RTIF			0xA4U		/* Receive and Transmit Interrupt Flag Register. */
#define CAN_O_ERRINT		0xA4U		/* Error Interrupt Enable and Flag Register. */
#define CAN_O_LIMIT			0xA4U		/* Warning Limits Register. */
#define CAN_O_S_SEG_1		0xA8U		/* Bit Timing in arbitration phase Register . */
#define CAN_O_S_SEG_2		0xA8U		/* Bit Timing in arbitration phase Register. */
#define CAN_O_S_SJW			0xA8U		/* Bit Timing in arbitration phase Register. */
#define CAN_O_S_PRESC		0xA8U		/* Prescaler in arbitration phase Register. */
#define CAN_O_F_SEG_1		0xACU		/* Bit Timing data phase in CANFD mode Register. */
#define CAN_O_F_SEG_2		0xACU		/* Bit Timing data phase in CANFD mode Register. */
#define CAN_O_F_SJW			0xACU		/* Bit Timing data phase in CANFD mode Register. */
#define CAN_O_F_PRESC		0xACU		/* Prescaler in data phase Register. */
#define CAN_O_EALCAP		0xB0U		/* Error and Arbitration Lost Capture Register. */
#define CAN_O_TDC			0xB0U		/* Transmitter Delay Compensation Register. */
#define CAN_O_RECNT			0xB0U		/* Error Counter Registers RECNT Register. */
#define CAN_O_TECNT			0xB0U		/* Error Counter Registers TECNT Register. */
#define CAN_O_ACFCTRL		0xB4U		/* Acceptance Filter Control Register. */
#define CAN_O_TIMECFG		0xB4U		/* CiA 603 Time-Stamping Register. */
#define CAN_O_ACF_EN_0		0xB4U		/* Acceptance Filter 0 Enable Register. */
#define CAN_O_ACF_EN_1		0xB4U		/* Acceptance Filter 1 Enable Register. */
#define CAN_O_ACF			0xB8U		/* Acceptance MASK 0 Register. */

#define CAN_O_VER_0			0xBCU		/* Version Information 0 Register. */
#define CAN_O_VER_1			0xBCU		/* Version Information 1 Register. */
#define CAN_O_TBSLOT		0xBCU		/* TTCAN: TB Slot Pointer Register. */
#define CAN_O_TTCFG			0xBCU		/* TTCAN: Time Trigger Configuration Register. */
#define CAN_O_REF_MSG_0		0xC0U		/* TTCAN: Reference Message 0 Register. */
#define CAN_O_REF_MSG_1		0xC0U		/* TTCAN: Reference Message 1 Register. */
#define CAN_O_REF_MSG_2		0xC0U		/* TTCAN: Reference Message 2 Register. */
#define CAN_O_REF_MSG_3		0xC0U		/* TTCAN: Reference Message 3 Register. */
#define CAN_O_TRIG_CFG_0	0xC4U		/* TTCAN: Trigger Configuration 0 Register. */
#define CAN_O_TRIG_CFG_1	0xC4U		/* TTCAN: Trigger Configuration 1 Register. */
#define CAN_O_TT_TRIG_0		0xC4U		/* TTCAN: Trigger Time 0 Register. */
#define CAN_O_TT_TRIG_1		0xC4U		/* TTCAN: Trigger Time 1 Register. */
#define CAN_O_TT_WTRIG_0	0xC8U		/* TTCAN: Watch Trigger Time 0 Register. */
#define CAN_O_TT_WTRIG_1	0xC8U		/* TTCAN: Watch Trigger Time 1 Register. */
#define CAN_O_MEM_PROT		0xC8U		/* Memory Protection Register. */
#define CAN_O_MEM_STAT		0xC8U		/* Memory Status Register. */
#define CAN_O_MEM_ES_0		0xCCU		/* Memory Error Stimulation 0 Register. */
#define CAN_O_MEM_ES_1		0xCCU		/* Memory Error Stimulation 1 Register. */
#define CAN_O_MEM_ES_2		0xCCU		/* Memory Error Stimulation 2 Register. */
#define CAN_O_MEM_ES_3		0xCCU		/* Memory Error Stimulation 3 Register. */
#define CAN_O_SCFG			0xD0U		/* Safety Configuration Register. */

/**
 * @brief The following are defines for the bit fields in the RBUF0 register.
 *
 */
#define CAN_RBUF0_STD_ID_M			0x000007FFU		/* Standard ID Mask. */
#define CAN_RBUF0_STD_ID_S			0U
#define CAN_RBUF0_EXT_ID_M			0x1FFFFFFFU		/* Extended ID Mask */
#define CAN_RBUF0_EXT_ID_S			0U

/**
 * @brief The following are defines for the bit fields in the RBUF3 register.
 *
 */
#define CAN_RBUF3_ESI_M				0x80000000U		/* The protocol machine automatically
													embeds the correct value of ESI into
													transmitted frames.esi. */
#define CAN_RBUF3_ESI_S				31U
#define CAN_RBUF3_ID_M				0x1F000000U		/* ID Message */
#define CAN_RBUF3_ID_S				24U

/**
 * @brief The following are defines for the bit fields in the RBUF4 register.
 *
 */
#define CAN_RBUF4_IDE_M				0x80U			/* IDentifier Extension. */
#define CAN_RBUF4_IDE_S				7U
#define CAN_RBUF4_RTR_M				0x40U			/* Remote Transmission Request. */
#define CAN_RBUF4_RTR_S				6U
#define CAN_RBUF4_FDF_M				0x20U			/* CAN FD frame. */
#define CAN_RBUF4_FDF_S				5U
#define CAN_RBUF4_BRS_M				0x10U			/* Bit Rate Switch. */
#define CAN_RBUF4_BRS_S				4U
#define CAN_RBUF4_DLC_M				0xFU			/* DLC Frame Type Payload in Bytes. */
#define CAN_RBUF4_DLC_S				0U

/**
 * @brief The following are defines for the bit fields in the RBUF5 register.
 *
 */
#define CAN_RBUF5_KOER_M			0xE000U			/* KOER in RBUF has the same meaning as the
													bits KOER in register EALCAP. KOER in RBUF
													becomes meaningful if RBALL=1 . */
#define CAN_RBUF5_KOER_S			13U
#define CAN_RBUF5_TX_M				0x1000U			/* Status bit TX in RBUF is set to 1 if the
													loop back mode is activated and the core has
													received its own transmitted frame. This can be
													useful if LBME=1 and other nodes in the network
													do also transmissions. */
#define CAN_RBUF5_TX_S				12U

/**
 * @brief The following are defines for the bit fields in the RBUF6 register.
 *
 */
#define CAN_RBUF6_CYCLE_TIME_M		0xFF0000U		/* The time-stamp CYCLE_TIME will be stored in
													RBUF only in TTCAN mode. */
#define CAN_RBUF6_CYCLE_TIME_S		16U

/**
 * @brief The following are defines for the bit fields in the RBUF7 register.
 *
 */
#define CAN_RBUF7_CYCLE_TIME_M		0xFF000000U		/* The time-stamp CYCLE_TIME will be
													stored in RBUF only in TTCAN mode. */
#define CAN_RBUF7_CYCLE_TIME_S		24U

/**
 * @brief The following are defines for the bit fields in the TBUF0 register.
 *
 */
#define CAN_TBUF0_ID_M				0xFFU			/* ID value. */
#define CAN_TBUF0_ID_S				0U

/**
 * @brief The following are defines for the bit fields in the TBUF1 register.
 *
 */
#define CAN_TBUF1_ID_M				0xFF00U			/* ID value. */
#define CAN_TBUF1_ID_S				8U

/**
 * @brief The following are defines for the bit fields in the TBUF2 register.
 *
 */
#define CAN_TBUF2_ID_M				0xFF0000U		/* ID value. */
#define CAN_TBUF2_ID_S				16U

/**
 * @brief The following are defines for the bit fields in the TBUF3 register.
 *
 */
#define CAN_TBUF3_TTSEN_M			0x80000000U		/* Transmit Time-Stamp Enable. */
#define CAN_TBUF3_TTSEN_S			31U
#define CAN_TBUF3_ID_M				0x1F000000U		/* ID value. */
#define CAN_TBUF3_ID_S				24U

/**
 * @brief The following are defines for the bit fields in the TBUF4 register.
 *
 */
#define CAN_TBUF4_IDE_M				0x80U			/* IDentifier Extension. */
#define CAN_TBUF4_IDE_S				7U
#define CAN_TBUF4_RTR_M				0x40U			/* Remote Transmission Request. */
#define CAN_TBUF4_RTR_S				6U
#define CAN_TBUF4_FDF_M				0x20U			/* CAN FD frame. */
#define CAN_TBUF4_FDF_S				5U
#define CAN_TBUF4_BRS_M				0x10U			/* Bit Rate Switch. */
#define CAN_TBUF4_BRS_S				4U
#define CAN_TBUF4_DLC_M				0xFU			/* The Data Length Code (DLC) in RBUF and TBUF
													defines the length of the payload. */
#define CAN_TBUF4_DLC_S				0U

/**
 * @brief The following are defines for the bit fields in the TTS_L register.
 *
 */
#define CAN_TTS_L_TRANSMISSION_TIME_STAMP_L_M	0xFFFFFFFFU		/* Transmission Time Stamp. */
#define CAN_TTS_L_TRANSMISSION_TIME_STAMP_L_S	0U

/**
 * @brief The following are defines for the bit fields in the TTS_H register.
 *
 */
#define CAN_TTS_H_TRANSMISSION_TIME_STAMP_H_M	0xFFFFFFFFU		/* Transmission Time Stamp. */
#define CAN_TTS_H_TRANSMISSION_TIME_STAMP_H_S	0U

/**
 * @brief The following are defines for the bit fields in the CFG_STAT register.
 *
 */
#define CAN_CFG_STAT_RESET_M		0x80U			/* RESET request bit. */
#define CAN_CFG_STAT_RESET_S		7U
#define CAN_CFG_STAT_LBME_M			0x40U			/* Loop Back Mode, External. */
#define CAN_CFG_STAT_LBME_S			6U
#define CAN_CFG_STAT_LBMI_M			0x20U			/* Loop Back Mode, Internal. */
#define CAN_CFG_STAT_LBMI_S			5U
#define CAN_CFG_STAT_TPSS_M			0x10U			/* Transmission Primary Single
													Shot mode for PTB. */
#define CAN_CFG_STAT_TPSS_S			4U
#define CAN_CFG_STAT_TSSS_M			0x8U			/* Transmission Secondary Single
													Shot mode for STB. */
#define CAN_CFG_STAT_TSSS_S			3U
#define CAN_CFG_STAT_RACTIVE_M		0x4U			/* Reception ACTIVE (Receive Status bit). */
#define CAN_CFG_STAT_RACTIVE_S		2U
#define CAN_CFG_STAT_TACTIVE_M		0x2U			/* Transmission ACTIVE (Transmit Status bit). */
#define CAN_CFG_STAT_TACTIVE_S		1U
#define CAN_CFG_STAT_BUSOFF_M		0x1U			/* Bus Off. */
#define CAN_CFG_STAT_BUSOFF_S		0U

/**
 * @brief The following are defines for the bit fields in the TCMD register.
 *
 */
#define CAN_TCMD_TBSEL_M			0x8000U			/* Transmit Buffer Select. */
#define CAN_TCMD_TBSEL_S			15U
#define CAN_TCMD_LOM_M				0x4000U			/* Listen Only Mode. */
#define CAN_TCMD_LOM_S				14U
#define CAN_TCMD_STBY_M				0x2000U			/* Transceiver Standby Mode. */
#define CAN_TCMD_STBY_S				13U
#define CAN_TCMD_TPE_M				0x1000U			/* Transmit Primary Enable. */
#define CAN_TCMD_TPE_S				12U
#define CAN_TCMD_TPA_M				0x800U			/* Transmit Primary Abort. */
#define CAN_TCMD_TPA_S				11U
#define CAN_TCMD_TSONE_M			0x400U			/* Transmit Secondary ONE frame. */
#define CAN_TCMD_TSONE_S			10U
#define CAN_TCMD_TSALL_M			0x200U			/* Transmit Secondary ALL frames. */
#define CAN_TCMD_TSALL_S			9U
#define CAN_TCMD_TSA_M				0x100U			/* Transmit Secondary Abort. */
#define CAN_TCMD_TSA_S				8U

/**
 * @brief The following are defines for the bit fields in the TCTRL register.
 *
 */
#define CAN_TCTRL_FD_ISO_M			0x800000U		/* CAN FD ISO mode. */
#define CAN_TCTRL_FD_ISO_S			23U
#define CAN_TCTRL_TSNEXT_M			0x400000U		/* Transmit buffer Secondary NEXT. */
#define CAN_TCTRL_TSNEXT_S			22U
#define CAN_TCTRL_TSMODE_M			0x200000U		/* Transmit buffer Secondary operation MODE. */
#define CAN_TCTRL_TSMODE_S			21U
#define CAN_TCTRL_TTTBM_M			0x100000U		/* TTCAN Transmit Buffer Mode. */
#define CAN_TCTRL_TTTBM_S			20U
#define CAN_TCTRL_TSSTAT_M			0x030000U		/* Transmission Secondary STATus bits. */
#define CAN_TCTRL_TSSTAT_S			16U

/**
 * @brief The following are defines for the bit fields in the RCTRL register.
 *
 */
#define CAN_RCTRL_SACK_M			0x80000000U		/* Self-ACKnowledge. */
#define CAN_RCTRL_SACK_S			31U
#define CAN_RCTRL_ROM_M				0x40000000U		/* Receive buffer Overflow Mode. */
#define CAN_RCTRL_ROM_S				30U
#define CAN_RCTRL_ROV_M				0x20000000U		/* Receive buffer OVerflow. */
#define CAN_RCTRL_ROV_S				29U
#define CAN_RCTRL_RREL_M			0x10000000U		/* Receive buffer RELease. */
#define CAN_RCTRL_RREL_S			28U
#define CAN_RCTRL_RBALL_M			0x08000000U		/* Receive Buffer stores ALL data frames. */
#define CAN_RCTRL_RBALL_S			27U
#define CAN_RCTRL_RSTAT_M			0x03000000U		/* Receive buffer STATus. */
#define CAN_RCTRL_RSTAT_S			24U

/**
 * @brief The following are defines for the bit fields in the RTIE register.
 *
 */
#define CAN_RTIE_RIE_M				0x80U			/* Receive Interrupt Enable. */
#define CAN_RTIE_RIE_S				7U
#define CAN_RTIE_ROIE_M				0x40U			/* RB Overrun Interrupt Enable. */
#define CAN_RTIE_ROIE_S				6U
#define CAN_RTIE_RFIE_M				0x20U			/* RB Full Interrupt Enable. */
#define CAN_RTIE_RFIE_S				5U
#define CAN_RTIE_RAFIE_M			0x10U			/* RB Almost Full Interrupt Enable. */
#define CAN_RTIE_RAFIE_S			4U
#define CAN_RTIE_TPIE_M				0x8U			/* Transmission Primary Interrupt Enable. */
#define CAN_RTIE_TPIE_S				3U
#define CAN_RTIE_TSIE_M				0x4U			/* Transmission Secondary Interrupt Enable. */
#define CAN_RTIE_TSIE_S				2U
#define CAN_RTIE_EIE_M				0x2U			/* Error Interrupt Enable. */
#define CAN_RTIE_EIE_S				1U
#define CAN_RTIE_TSFF_M				0x1U			/* If TTEN=0 or TTTBM=0: Transmit
													Secondary buffer Full Flag. */
#define CAN_RTIE_TSFF_S				0U
#define CAN_RTIE_ALL_M				0xFFU			/* All Interrupt Enable or Disable. */

/**
 * @brief The following are defines for the bit fields in the RTIF register.
 *
 */
#define CAN_RTIF_RIF_M				0x8000U			/* Receive Interrupt Flag. */
#define CAN_RTIF_RIF_S				15U
#define CAN_RTIF_ROIF_M				0x4000U			/* RB Overrun Interrupt Flag. */
#define CAN_RTIF_ROIF_S				14U
#define CAN_RTIF_RFIF_M				0x2000U			/* RB Full Interrupt Flag. */
#define CAN_RTIF_RFIF_S				13U
#define CAN_RTIF_RAFIF_M			0x1000U			/* RB Almost Full Interrupt Flag. */
#define CAN_RTIF_RAFIF_S			12U
#define CAN_RTIF_TPIF_M				0x800U			/* Transmission Primary Interrupt Flag. */
#define CAN_RTIF_TPIF_S				11U
#define CAN_RTIF_TSIF_M				0x400U			/* Transmission Secondary Interrupt Flag. */
#define CAN_RTIF_TSIF_S				10U
#define CAN_RTIF_EIF_M				0x200U			/* Error Interrupt Flag. */
#define CAN_RTIF_EIF_S				9U
#define CAN_RTIF_AIF_M				0x100U			/* Abort Interrupt Flag. */
#define CAN_RTIF_AIF_S				8U
#define CAN_RTIF_ALL_M				0xFF00U			/* RTIF all Flag. */

/**
 * @brief The following are defines for the bit fields in the ERRINT register.
 *
 */
#define CAN_ERRINT_EWARN_M			0x800000U		/* Error WARNing limit reached. */
#define CAN_ERRINT_EWARN_S			23U
#define CAN_ERRINT_EPASS_M			0x400000U		/* Error Passive mode active. */
#define CAN_ERRINT_EPASS_S			22U
#define CAN_ERRINT_EPIE_M			0x200000U		/* Error Passive Interrupt Enable. */
#define CAN_ERRINT_EPIE_S			21U
#define CAN_ERRINT_EPIF_M			0x100000U		/* Error Passive Interrupt Flag.
													EPIF will be activated if the error status
													changes from error. */
#define CAN_ERRINT_EPIF_S			20U
#define CAN_ERRINT_ALIE_M			0x80000U		/* Arbitration Lost Interrupt Enable. */
#define CAN_ERRINT_ALIE_S			19U
#define CAN_ERRINT_ALIF_M			0x40000U		/* Arbitration Lost Interrupt Flag. */
#define CAN_ERRINT_ALIF_S			18U
#define CAN_ERRINT_BEIE_M			0x20000U		/* Bus Error Interrupt Enable. */
#define CAN_ERRINT_BEIE_S			17U
#define CAN_ERRINT_BEIF_M			0x10000U		/* Bus Error Interrupt Flag. */
#define CAN_ERRINT_BEIF_S			16U

/**
 * @brief The following are defines for the bit fields in the LIMIT register.
 *
 */
#define CAN_LIMIT_AFWL_M			0xF0000000U		/* receive buffer Almost Full Warning Limit. */
#define CAN_LIMIT_AFWL_S			28U
#define CAN_LIMIT_EWL_M				0x0F000000U		/* Programmable Error Warning Limit =
													(EWL+1) * 8. Possible Limit values:
													8, 16, ...128. */
#define CAN_LIMIT_EWL_S				24U

/**
 * @brief The following are defines for the bit fields in the S_SEG_1 register.
 *
 */
#define CAN_S_SEG_1_S_SEG_1_M		0xFFU			/* Bit Timing Segment 1 (slow speed). */
#define CAN_S_SEG_1_S_SEG_1_S		0U

/**
 * @brief The following are defines for the bit fields in the S_SEG_2 register.
 *
 */
#define CAN_S_SEG_2_S_SEG_2_M		0x7F00U			/* Bit Timing Segment 2 (slow speed). */
#define CAN_S_SEG_2_S_SEG_2_S		8U

/**
 * @brief The following are defines for the bit fields in the S_SJW register.
 *
 */
#define CAN_S_SJW_S_SJW_M			0x7F0000U		/* Synchronization Jump Width (slow speed). */
#define CAN_S_SJW_S_SJW_S			16U

/**
 * @brief The following are defines for the bit fields in the S_PRESC register.
 *
 */
#define CAN_S_PRESC_S_PRESC_M		0xFF000000U		/* Prescaler (slow speed). */
#define CAN_S_PRESC_S_PRESC_S		24U

/**
 * @brief The following are defines for the bit fields in the F_SEG_1 register.
 *
 */
#define CAN_F_SEG_1_F_SEG_1_M		0x1FU			/* Bit Timing Segment 1 (fast speed). */
#define CAN_F_SEG_1_F_SEG_1_S		0U

/**
 * @brief The following are defines for the bit fields in the F_SEG_2 register.
 *
 */
#define CAN_F_SEG_2_F_SEG_2_M		0xF00U			/* Bit Timing Segment 2 (fast speed). */
#define CAN_F_SEG_2_F_SEG_2_S		8U

/**
 * @brief The following are defines for the bit fields in the F_SJW register.
 *
 */
#define CAN_F_SJW_F_SJW_M			0xF0000U		/* Synchronization Jump Width (fast speed). */
#define CAN_F_SJW_F_SJW_S			16U

/**
 * @brief The following are defines for the bit fields in the F_PRESC register.
 *
 */
#define CAN_F_PRESC_F_PRESC_M		0xFF000000U		/* Prescaler (fast speed). */
#define CAN_F_PRESC_F_PRESC_S		24U

/**
 * @brief The following are defines for the bit fields in the EALCAP register.
 *
 */
#define CAN_EALCAP_KOER_M			0xE0U			/* Kind Of ERror (Error code). */
#define CAN_EALCAP_KOER_S			5U
#define CAN_EALCAP_ALC_M			0x1FU			/* Arbitration Lost Capture
													(bit position in the frame. */
#define CAN_EALCAP_ALC_S			0U

/**
 * @brief The following are defines for the bit fields in the TDC register.
 *
 */
#define CAN_TDC_TDCEN_M				0x8000U			/* Transmitter Delay Compensation ENable. */
#define CAN_TDC_TDCEN_S				15U
#define CAN_TDC_SSPOFF_M			0x7F00U			/* Secondary Sample Point OFFset. */
#define CAN_TDC_SSPOFF_S			8U

/**
 * @brief The following are defines for the bit fields in the RECNT register.
 *
 */
#define CAN_RECNT_RECNT_M			0xFF0000U		/* Receive Error CouNT.
													(number of errors during reception) */
#define CAN_RECNT_RECNT_S			16U

/**
 * @brief The following are defines for the bit fields in the TECNT register.
 *
 */
#define CAN_TECNT_TECNT_M			0xFF000000U		/* Transmit Error CouNT
													(number of errors during transmission) TECNT is
													incremented and decremented as defined. */
#define CAN_TECNT_TECNT_S			24U

/**
 * @brief The following are defines for the bit fields in the ACFCTRL register.
 *
 */
#define CAN_ACFCTRL_SELMASK_M		0x20U			/* SELect acceptance MASK. */
#define CAN_ACFCTRL_SELMASK_S		5U
#define CAN_ACFCTRL_ACFADR_M		0xFU			/* acceptance filter address. */
#define CAN_ACFCTRL_ACFADR_S		0U

/**
 * @brief The following are defines for the bit fields in the TIMECFG register.
 *
 */
#define CAN_TIMECFG_TIMEPOS_M		0x200U			/* Time stamp position. */
#define CAN_TIMECFG_TIMEPOS_S		9U
#define CAN_TIMECFG_TIMEEN_M		0x100U			/* time stamp enable. */
#define CAN_TIMECFG_TIMEEN_S		8U

/**
 * @brief The following are defines for the bit fields in the ACF_EN_0 register.
 *
 */
#define CAN_ACF_EN_0_AE_7_M			0x800000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_7_S			23U
#define CAN_ACF_EN_0_AE_6_M			0x400000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_6_S			22U
#define CAN_ACF_EN_0_AE_5_M			0x200000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_5_S			21U
#define CAN_ACF_EN_0_AE_4_M			0x100000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_4_S			20U
#define CAN_ACF_EN_0_AE_3_M			0x80000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_3_S			19U
#define CAN_ACF_EN_0_AE_2_M			0x40000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_2_S			18U
#define CAN_ACF_EN_0_AE_1_M			0x20000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_1_S			17U
#define CAN_ACF_EN_0_AE_0_M			0x10000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_0_AE_0_S			16U

/**
 * @brief The following are defines for the bit fields in the ACF_EN_1 register.
 *
 */
#define CAN_ACF_EN_1_AE_15_M		0x80000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_15_S		31U
#define CAN_ACF_EN_1_AE_14_M		0x40000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_14_S		30U
#define CAN_ACF_EN_1_AE_13_M		0x20000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_13_S		29U
#define CAN_ACF_EN_1_AE_12_M		0x10000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_12_S		28U
#define CAN_ACF_EN_1_AE_11_M		0x8000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_11_S		27U
#define CAN_ACF_EN_1_AE_10_M		0x4000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_10_S		26U
#define CAN_ACF_EN_1_AE_9_M			0x2000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_9_S			25U
#define CAN_ACF_EN_1_AE_8_M			0x1000000U		/* Acceptance filter Enable. */
#define CAN_ACF_EN_1_AE_8_S			24U

/**
 * @brief The following are defines for the bit fields in the ACF_0 register.
 *
 */
#define CAN_ACF_0_ACODE_X_AMASK_X_M	0xFFU			/* Acceptance MASK 0. */
#define CAN_ACF_0_ACODE_X_AMASK_X_S	0U

/**
 * @brief The following are defines for the bit fields in the ACF_1 register.
 *
 */
#define CAN_ACF_1_ACODE_X_AMASK_X_M	0xFF00U			/* Acceptance MASK 1. */
#define CAN_ACF_1_ACODE_X_AMASK_X_S	8U

/**
 * @brief The following are defines for the bit fields in the ACF_2 register.
 *
 */
#define CAN_ACF_2_ACODE_X_AMASK_X_M	0xFF0000U		/* Acceptance MASK. */
#define CAN_ACF_2_ACODE_X_AMASK_X_S	16U

/**
 * @brief The following are defines for the bit fields in the ACF_3 register.
 *
 */
#define CAN_ACF_3_AIDEE_M			0x40000000U		/* Acceptance mask IDE bit check enable. */
#define CAN_ACF_3_AIDEE_S			30U
#define CAN_ACF_3_AIDE_M			0x20000000U		/* Acceptance mask IDE bit value. */
#define CAN_ACF_3_AIDE_S			29U
#define CAN_ACF_3_ACODE_X_AMASK_X_M	0x1FFFFFFFU		/* Acceptance MASK. */
#define CAN_ACF_3_ACODE_X_AMASK_X_S	0U

#define CAN_ACF_ACODE_X_AMASK_X_M	0x1FFFFFFFU		/* Acceptance MASK. */
#define CAN_ACF_ACODE_X_AMASK_X_S	0U

/**
 * @brief The following are defines for the bit fields in the VER_0 register.
 *
 */
#define CAN_VER_0_VERSION_M			0xFFU			/* Version of CAN-CTRL, given as decimal value.
													VER_1 holds the major version and VER_0 the
													minor version.*/
#define CAN_VER_0_VERSION_S			0U

/**
 * @brief The following are defines for the bit fields in the VER_1 register.
 *
 */
#define CAN_VER_1_VERSION_M			0xFF00U			/* Version of CAN-CTRL, given as decimal value.
													VER_1 holds the major version and VER_0 the
													minor version.*/
#define CAN_VER_1_VERSION_S			8U

/**
 * @brief The following are defines for the bit fields in the TBSLOT register.
 *
 */
#define CAN_TBSLOT_TBE_M			0x800000U		/* set TB slot to "Empty". */
#define CAN_TBSLOT_TBE_S			23U
#define CAN_TBSLOT_TBF_M			0x400000U		/* set TB slot to "Filled". */
#define CAN_TBSLOT_TBF_S			22U
#define CAN_TBSLOT_TBPTR_M			0x3F0000U		/* Pointer to a TB message slot. */
#define CAN_TBSLOT_TBPTR_S			16U

/**
 * @brief The following are defines for the bit fields in the TTCFG register.
 *
 */
#define CAN_TTCFG_WTIE_M			0x80000000U		/* Watch Trigger Interrupt Enable. */
#define CAN_TTCFG_WTIE_S			31U
#define CAN_TTCFG_WTIF_M			0x40000000U		/* Watch Trigger Interrupt Flag. */
#define CAN_TTCFG_WTIF_S			30U
#define CAN_TTCFG_TEIF_M			0x20000000U		/* Trigger Error Interrupt Flag. */
#define CAN_TTCFG_TEIF_S			29U
#define CAN_TTCFG_TTIE_M			0x1000000U		/* Time Trigger Interrupt Enable. */
#define CAN_TTCFG_TTIE_S			28U
#define CAN_TTCFG_TTIF_M			0x8000000U		/* Time Trigger Interrupt Flag. */
#define CAN_TTCFG_TTIF_S			27U
#define CAN_TTCFG_T_PRESC_M			0x6000000U		/* TTCAN Timer PRESCaler. */
#define CAN_TTCFG_T_PRESC_S			25U
#define CAN_TTCFG_TTEN_M			0x1000000U		/* Time Trigger Enable. */
#define CAN_TTCFG_TTEN_S			24U

/**
 * @brief The following are defines for the bit fields in the REF_MSG_0 register.
 *
 */
#define CAN_REF_MSG_0_REF_ID_M		0xFFU			/* REFerence message IDentifier. */
#define CAN_REF_MSG_0_REF_ID_S		0U

/**
 * @brief The following are defines for the bit fields in the REF_MSG_1 register.
 *
 */
#define CAN_REF_MSG_1_REF_ID_M		0xFF00U			/* REFerence message IDentifier. */
#define CAN_REF_MSG_1_REF_ID_S		8U

/**
 * @brief The following are defines for the bit fields in the REF_MSG_2 register.
 *
 */
#define CAN_REF_MSG_2_REF_ID_M		0xFF0000U		/* REFerence message IDentifier. */
#define CAN_REF_MSG_2_REF_ID_S		16U

/**
 * @brief The following are defines for the bit fields in the REF_MSG_3 register.
 *
 */
#define CAN_REF_MSG_3_REF_IDE_M		0x80000000U		/* REFerence message IDE bit. */
#define CAN_REF_MSG_3_REF_IDE_S		31U
#define CAN_REF_MSG_3_REF_ID_M		0x1F000000U		/* REFerence message IDentifier. */
#define CAN_REF_MSG_3_REF_ID_S		24U

/**
 * @brief The following are defines for the bit fields in the TRIG_CFG_0 register.
 *
 */
#define CAN_TRIG_CFG_0_TTPTR_M		0x3FU			/* Transmit Trigger TB slot Pointer. */
#define CAN_TRIG_CFG_0_TTPTR_S		0U

/**
 * @brief The following are defines for the bit fields in the TRIG_CFG_1 register.
 *
 */
#define CAN_TRIG_CFG_1_TEW_M		0xF000U			/* Transmit Enable Window. */
#define CAN_TRIG_CFG_1_TEW_S		12U
#define CAN_TRIG_CFG_1_TTYPE_M		0x700U			/* Trigger Type. */
#define CAN_TRIG_CFG_1_TTYPE_S		8U

/**
 * @brief The following are defines for the bit fields in the TT_TRIG_0 register.
 *
 */
#define CAN_TT_TRIG_0_TT_TRIG_M		0xFF0000U		/* Trigger Time. */
#define CAN_TT_TRIG_0_TT_TRIG_S		16U

/**
 * @brief The following are defines for the bit fields in the TT_TRIG_1 register.
 *
 */
#define CAN_TT_TRIG_1_TT_TRIG_M		0xFF000000U		/* Trigger Time. */
#define CAN_TT_TRIG_1_TT_TRIG_S		24U

/**
 * @brief The following are defines for the bit fields in the TT_WTRIG_0 register.
 *
 */
#define CAN_TT_WTRIG_0_TT_WTRIG_M	0xFFU			/* Watch Trigger Time. */
#define CAN_TT_WTRIG_0_TT_WTRIG_S	0U

/**
 * @brief The following are defines for the bit fields in the TT_WTRIG_1 register.
 *
 */
#define CAN_TT_WTRIG_1_TT_WTRIG_M	0xFF00U			/* Watch Trigger Time. */
#define CAN_TT_WTRIG_1_TT_WTRIG_S	8U

/**
 * @brief The following are defines for the bit fields in the MEM_PROT register.
 *
 */
#define CAN_MEM_PROT_MAEIF_M		0x100000U		/* Memory: Address Error Interrupt Flag. */
#define CAN_MEM_PROT_MAEIF_S		20U
#define CAN_MEM_PROT_MDEIF_M		0x80000U		/* Memory: Data Error Interrupt Flag. */
#define CAN_MEM_PROT_MDEIF_S		19U
#define CAN_MEM_PROT_MDWIF_M		0x40000U		/* Memory: Data Warning Interrupt Flag. */
#define CAN_MEM_PROT_MDWIF_S		18U
#define CAN_MEM_PROT_MDWIE_M		0x20000U		/* Memory: Data Warning Interrupt Enable. */
#define CAN_MEM_PROT_MDWIE_S		17U
#define CAN_MEM_PROT_MPEN_M			0x10000U		/* Memory Protection Enable. */
#define CAN_MEM_PROT_MPEN_S			16U

/**
 * @brief The following are defines for the bit fields in the MEM_STAT register.
 *
 */
#define CAN_MEM_STAT_HELOC_M		0x18000000U		/* Host side memory error location. */
#define CAN_MEM_STAT_HELOC_S		27U
#define CAN_MEM_STAT_TXB_M			0x4000000U		/* Transmission Block. */
#define CAN_MEM_STAT_TXB_S			26U
#define CAN_MEM_STAT_TXS_M			0x2000000U		/* Transmission Stop. */
#define CAN_MEM_STAT_TXS_S			25U
#define CAN_MEM_STAT_ACFA_M			0x1000000U		/* Acceptance Filter Accept. */
#define CAN_MEM_STAT_ACFA_S			24U

/**
 * @brief The following are defines for the bit fields in the MEM_ES_0 register.
 *
 */
#define CAN_MEM_ES_0_MEAEE_M		0x80U			/* Memory Error: Address Error Enable. */
#define CAN_MEM_ES_0_MEAEE_S		7U
#define CAN_MEM_ES_0_ME1EE_M		0x40U			/* Memory Error: 1st Error Enable. */
#define CAN_MEM_ES_0_ME1EE_S		6U
#define CAN_MEM_ES_0_MEBP1_M		0x3FU			/* Memory Error: Bit Position 1. */
#define CAN_MEM_ES_0_MEBP1_S		0U

/**
 * @brief The following are defines for the bit fields in the MEM_ES_1 register.
 *
 */
#define CAN_MEM_ES_1_ME2EE_M		0x4000U			/* Memory Error: 2nd Error Enable. */
#define CAN_MEM_ES_1_ME2EE_S		14U
#define CAN_MEM_ES_1_MEBP2_M		0x3F00U			/* Memory Error: Bit Position 2. */
#define CAN_MEM_ES_1_MEBP2_S		8U

/**
 * @brief The following are defines for the bit fields in the MEM_ES_2 register.
 *
 */
#define CAN_MEM_ES_2_MENEC_M		0xF00000U		/* Memory Error: No Error Counter. */
#define CAN_MEM_ES_2_MENEC_S		20U
#define CAN_MEM_ES_2_MEEEC_M		0xF0000U		/* Memory Error: Error Enable Counter. */
#define CAN_MEM_ES_2_MEEEC_S		16U

/**
 * @brief The following are defines for the bit fields in the MEM_ES_3 register.
 *
 */
#define CAN_MEM_ES_3_MES_M			0x4000000U		/* Memory Error Side. */
#define CAN_MEM_ES_3_MES_S			26U
#define CAN_MEM_ES_3_MEL_M			0x3000000U		/* Memory Error Location. */
#define CAN_MEM_ES_3_MEL_S			24U

/**
 * @brief The following are defines for the bit fields in the SCFG register.
 *
 */
#define CAN_SCFG_FSTIM_M			0x70U			/* Fault Stimulation. */
#define CAN_SCFG_FSTIM_S			4U
#define CAN_SCFG_SWIF_M				0x8U			/* DMR/TMR: Safety warning interrupt flag. */
#define CAN_SCFG_SWIF_S				3U
#define CAN_SCFG_SWIE_M				0x4U			/* DMR/TMR: Safety Warning Interrupt Enable. */
#define CAN_SCFG_SWIE_S				2U
#define CAN_SCFG_SEIF_M				0x2U			/* DMR/TMR: Safety Error Interrupt Flag. */
#define CAN_SCFG_SEIF_S				1U
#define CAN_SCFG_XMREN_M			0x1U			/* DMR/TMR enable. */
#define CAN_SCFG_XMREN_S			0U

#ifdef __cplusplus
}
#endif		/* extern "C" */

#endif

