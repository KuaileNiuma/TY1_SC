/** 
  ************************************************************************************* 
  * @file can.h 
  * @brief This file contains the definition of can driver. 
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

#ifndef _CAN_H_
#define _CAN_H_

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
#include "hw_can.h"

#define CAN_CTRL_NUMBER_OF_INSTANCES	2U

//*****************************************************************************
//
// Controller Area Network TxMailBox
//
//*****************************************************************************

typedef struct
{
  __IO uint32_t TIR;
  __IO uint32_t TDTR;
  __IO uint32_t TDLR;
  __IO uint32_t TDHR;
} CAN_TxMailBox_TypeDef;

//*****************************************************************************
//
// Controller Area Network FIFOMailBox
//
//*****************************************************************************

typedef struct
{
  __IO uint32_t RIR;
  __IO uint32_t RDTR;
  __IO uint32_t RDLR;
  __IO uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;

//*****************************************************************************
//
// Controller Area Network FilterRegister
//
//*****************************************************************************

typedef struct
{
  __IO uint32_t FR1;
  __IO uint32_t FR2;
} CAN_FilterRegister_TypeDef;

//*****************************************************************************
//
// Controller Area Network
//
//*****************************************************************************
typedef struct
{
    __IO uint32_t RBUF[20];       // RBUF 0x00 - 0x4F  Tbuf only can be written with the format of uint32_t
    __IO uint32_t TBUF[18];       // TBUF 0x50 - 0x97  Rbuf only can be read with the format of uint32_t
    __IO uint32_t TTS[2];         // TTS 0x98 - 0x9F
    __IO uint8_t CFG_STAT;       // CFG_STAT 0xA0
    __IO uint8_t TCMD;           // TCMD 0xA1
    __IO uint8_t TCTRL;
    __IO uint8_t RCTRL;
    __IO uint8_t RTIE;
    __IO uint8_t RTIF;
    __IO uint8_t ERRINT;
    __IO uint8_t LIMIT;
    __IO uint8_t S_Seg_1;
    __IO uint8_t S_Seg_2;
    __IO uint8_t S_SJW;
    __IO uint8_t S_PRESC;

    __IO uint8_t F_Seg_1;
    __IO uint8_t F_Seg_2;
    __IO uint8_t F_SJW;
    __IO uint8_t F_PRESC;

    __IO uint8_t EALCAP;
    __IO uint8_t TDC;
    __IO uint8_t RECNT;
    __IO uint8_t TECNT;
    __IO uint8_t ACFCTRL;
    __IO uint8_t TIMECFG;

    __IO uint8_t ACF_EN_0;
    __IO uint8_t ACF_EN_1;
    __IO uint32_t ACF;

    __IO uint8_t VER_0;
    __IO uint8_t VER_1;

    __IO uint8_t TBSLOT;
    __IO uint8_t TTCFG;

    __IO uint8_t REF_MSG_0;
    __IO uint8_t REF_MSG_1;
    __IO uint8_t REF_MSG_2;
    __IO uint8_t REF_MSG_3;

    __IO uint8_t TRIG_CFG_0;
    __IO uint8_t TRIG_CFG_1;

    __IO uint8_t TT_TRIG_0;
    __IO uint8_t TT_TRIG_1;

    __IO uint8_t TT_WTRIG_0;
    __IO uint8_t TT_WTRIG_1;

}CAN_TypeDef;


//*****************************************************************************
//
// Check if the base address is valid or not.
//
//*****************************************************************************
#define CAN_CHECK_BASE_VALID					1U

#define CAN_TDC_TDCO_MAX						(0x7FU)
/* Maximum value of normal phase for segment 1 of CAN-CTRL instance in CAN/CANFD mode*/
#define CAN_NBTP_NTSEG1_MAX						(63U)
/* Maximum value of normal phase for segment 2 of CAN-CTRL instance in CAN mode*/
#define CAN_NBTP_NTSEG2_MAX_CAN_MODE			(7U)
/* Maximum value of normal phase for segment 2 of CAN-CTRL instance in CANFD mode*/
#define CAN_NBTP_NTSEG2_MAX_CANFD_MODE			(31U)
/* Maximum value of normal phase for sync jump width of CAN-CTRL instance in CAN/CANFD mode. */
#define CAN_NBTP_NSJW_MAX						(15U)
/* Maximum value of normal phase for prescaler of CAN-CTRL instance in CAN/CANFD mode. */
#define CAN_NBTP_NBRP_MAX						(0xFFU)

/* Maximum value of data phase for segment 1 of CAN-CTRL instance in CANFD mode*/
#define CAN_DBTP_DTSEG1_MAX						(15U)
/* Maximum value of data phase for segment 1 of CAN-CTRL instance in CANFD mode*/
#define CAN_DBTP_DTSEG2_MAX						(7U)
/* Maximum value of data phase for segment 1 of CAN-CTRL instance in CANFD mode*/
#define CAN_DBTP_DSJW_MAX						(7U)
/* Maximum value of data phase for segment 1 of CAN-CTRL instance in CANFD mode*/
#define CAN_DBTP_DBRP_MAX						(0xFFU)

/* Number of acceptance filter in CAN-CTRL */
#define NUMBER_OF_ACF							(16U)

#define CAN_ALL_INT_EN_MASK			(CAN_RTIE_RIE_M |	\
									CAN_RTIE_ROIE_M |	\
									CAN_RTIE_RFIE_M |	\
									CAN_RTIE_RAFIE_M |	\
									CAN_RTIE_TPIE_M |	\
									CAN_RTIE_TSIE_M |	\
									CAN_RTIE_EIE_M |	\
									CAN_ERRINT_BEIE_M |	\
									CAN_ERRINT_ALIE_M |	\
									CAN_ERRINT_EPIE_M	\
									)

#define CAN_INT_STATUS_MASK			(CAN_RTIF_RIF_M |	\
									CAN_RTIF_ROIF_M |	\
									CAN_RTIF_RFIF_M |	\
									CAN_RTIF_RAFIF_M |	\
									CAN_RTIF_TPIF_M |	\
									CAN_RTIF_TSIF_M |	\
									CAN_RTIF_EIF_M |	\
									CAN_RTIF_AIF_M |	\
									CAN_ERRINT_BEIF_M |	\
									CAN_ERRINT_ALIF_M |	\
									CAN_ERRINT_EPIF_M	\
									)

//*****************************************************************************
//
// Maximum payload supported by CAN-FD protocol in bytes.
//
//*****************************************************************************
#define CAN_MAX_PAYLOAD_BYTES					(64U)

//*****************************************************************************
//
// CAN loopback mode.
// CAN_LPBK_MODE_INTERNAL - CAN use internal loopback mode.
// CAN_LPBK_MODE_EXTERNAL - CAN use external loopback mode.
//
//*****************************************************************************
typedef enum {
	CAN_LPBK_MODE_INTERNAL		= 0U,
	CAN_LPBK_MODE_EXTERNAL		= 1U,
} CAN_LpbkMode_t;

//*****************************************************************************
//
// CAN-CTRL receive message ID filter types.
// CAN_IDTYPE_BOTH_STD_EXT - acceptance filter accepts both standard or extended frames.
// CAN_IDTYPE_ONLY_STD - acceptance filter accepts only standard frames.
// CAN_IDTYPE_ONLY_EXT - acceptance filter accepts only extended frames.
//
//*****************************************************************************
typedef enum {
	CAN_IDTYPE_BOTH_STD_EXT		= 0x00,
	CAN_IDTYPE_ONLY_STD			= 0x01,
	CAN_IDTYPE_ONLY_EXT			= 0x02,
} CAN_IDFilterType_t;

//*****************************************************************************
//
// Select Transmission buffer mode.
//
//*****************************************************************************
typedef enum {
	CAN_PTB_PRIORITY			= 0x00,		/* Transmission Primary buffer. */
	CAN_STB_SECONDARY			= 0x01		/* Transmission Secondary buffer. */
} CAN_TxBufMode_t;

//*****************************************************************************
//
// Select Transmission buffer mode in secondary buffer mode.
//
//*****************************************************************************
typedef enum {
	CAN_TX_MODE_SINGLE_MSG		= 0x01U,	/* Only transfer one message. */
	CAN_TX_MODE_ALL_MSG			= 0x02U,	/* Transfer all messages. */
} CAN_SendMsgMode_t;

//*****************************************************************************
//
// CAN-CTRL transmission buffer mode.
//
//*****************************************************************************
typedef enum {
	CAN_TS_MODE_FIFO			= 0x00, /* In FIFO mode frames are transmitted
										in the order in that they are written into the STB. */
	CAN_TS_MODE_PRIORITY		= 0x01,	/* In priority decision mode the fame with the highest
										priority in the STB is automatically transmitted first.
										The ID of a frame is used for the priority decision. */
} CAN_TxBufferMode_t;

//*****************************************************************************
//
// Configuration of CAN-CTRL timestamp mode.
// CAN_DIS_TIMESTAMP - Disable timestamp generation.
// CAN_TIMESTAMP_SOF - Timestamp generation at start of frame.
// CAN_TIMESTAMP_EOF - Timestamp generation at end of frame.
//
//*****************************************************************************
typedef enum {
	CAN_DIS_TIMESTAMP			= 0x00U,
	CAN_TIMESTAMP_SOF			= 0x01U,
	CAN_TIMESTAMP_EOF			= 0x02U,
} CAN_TimeStampMode_t;

//*****************************************************************************
//
// CAN-CTRL CAN bus error state.
//
//*****************************************************************************
typedef enum {
	CAN_STATUS_OK				= (0U << 0),
	CAN_STATUS_EWARN			= (1U << 1),	/* One of the error counters RECNT or TECNT
												is equal or bigger than EWL. */
	CAN_STATUS_EPASS			= (2U << 2),	/* Error Passive mode active. */
	CAN_STATUS_BUS_OFF			= (3U << 3),	/* Bus off state active. */
} CAN_BusErrState_t;

//*****************************************************************************
//
// CAN-CTRL Tx message buffer status.
//
//*****************************************************************************
typedef enum {
	CAN_TXBUFFER_EMPTY			= 0x00,			/* Message buffer is empty. */
	CAN_TXBUFFER_LESS_THAN_HALF	= 0x01,			/* Message buffer is less than or
												equal to half full. */
	CAN_TXBUFFER_MORE_THAN_HALF	= 0x02,			/* Message buffer is more than half full. */
	CAN_TXBUFFER_FULL			= 0x03,			/* Message buffer is full. */
	CAN_TXBUFFER_ERR			= 0x04,			/* Message buffer error. */
} CAN_TxMsgBufStatus_t;

//*****************************************************************************
//
// CAN-CTRL Rx message buffer status.
//
//*****************************************************************************
typedef enum {
	CAN_RXBUFFER_EMPTY					= 0x00,	/* Message buffer is empty. */
	CAN_RXBUFFER_LESS_THAN_ALMOST_FULL	= 0x01,	/* Message buffer is more than empty full and
												less than almost full. */
	CAN_RXBUFFER_MORE_THAN_ALMOST_FULL	= 0x02,	/* Message buffer is more than half full. */
	CAN_RXBUFFER_FULL					= 0x03,	/* Message buffer is full. */
	CAN_RXBUFFER_ERR					= 0x04,	/* Message buffer error. */
} CAN_RxMsgBufStatus_t;

//*****************************************************************************
//
// Data Length Code.
// 0-8= CAN + CAN FD: transmit frame has 0-8 data bytes.
// 9-15= CAN: transmit frame has 8 data bytes.
// 9-15=CAN FD: transmit frame has 12/16/20/24/32/48/64 data bytes.
//
//*****************************************************************************
typedef enum {
	CAN_DATA_LENGTH_0		= 0U,
	CAN_DATA_LENGTH_1		= 1U,
	CAN_DATA_LENGTH_2		= 2U,
	CAN_DATA_LENGTH_3		= 3U,
	CAN_DATA_LENGTH_4		= 4U,
	CAN_DATA_LENGTH_5		= 5U,
	CAN_DATA_LENGTH_6		= 6U,
	CAN_DATA_LENGTH_7		= 7U,
	CAN_DATA_LENGTH_8		= 8U,
	CAN_DATA_LENGTH_12		= 9U,
	CAN_DATA_LENGTH_16		= 10U,
	CAN_DATA_LENGTH_20		= 11U,
	CAN_DATA_LENGTH_24		= 12U,
	CAN_DATA_LENGTH_32		= 13U,
	CAN_DATA_LENGTH_48		= 14U,
	CAN_DATA_LENGTH_64		= 15U,
} CAN_MsgDataLength_t;

//*****************************************************************************
//
// CAN-CTRL Operation Mode.
// CAN_OPERATION_MODE_NORMAL - The CAN-CTRL instance is not resetting.
// CAN_OPERATION_MODE_SW_INIT - Reset CAN-CTRL instance.
//
//*****************************************************************************
typedef enum {
	CAN_OPERATION_MODE_NORMAL	= 0U,
	CAN_OPERATION_MODE_SW_INIT	= 1U
} CAN_OperationMode_t;

//*****************************************************************************
//
// CANFD frame format mode.
//
//*****************************************************************************
typedef enum {
	CAN_FD_ISO_11898_1			= 0U,			/* CANFD mode use ISO11898.1 frame format. */
	CAN_FD_BOSCH_STANDARD		= 1U,			/* CANFD mode use BOSCH CANFD frame format. */
} CAN_FDISOMode_t;

//*****************************************************************************
//
// Structure for MCAN initialization parameters.
//
//*****************************************************************************
typedef struct {
	bool fdMode;
	bool brsEnable;
	bool listenOnlyEnable;
	CAN_FDISOMode_t fdFrame;
	CAN_TxBufferMode_t txbmode;
	CAN_TimeStampMode_t timestamp;
} CAN_InitParams_t;

//*****************************************************************************
//
// CAN-CTRL Bit Rate Parameters.
//
//*****************************************************************************
typedef struct {
	volatile uint8_t nomRatePrescalar;
	volatile uint8_t nomTimeSeg1;
	volatile uint8_t nomTimeSeg2;
	volatile uint8_t nomSynchJumpWidth;
	volatile uint8_t dataRatePrescalar;
	volatile uint8_t dataTimeSeg1;
	volatile uint8_t dataTimeSeg2;
	volatile uint8_t dataSynchJumpWidth;
} CAN_BitTimingParams_t;

//*****************************************************************************
//
// CAN-CTRL IP instance ID filter configuration paramters.
//
//*****************************************************************************
typedef struct {
	uint32_t acode;
	uint32_t amsk;
	CAN_IDFilterType_t filerFrameType;
} CAN_FilterElement_t;

//*****************************************************************************
//
// CAN-CTRL instance receives message buffer structure.
//
//*****************************************************************************
//! CAN message identifier(Standard frame ID is 11 bit(10:0),
//! Extended frame ID is 29 bit(28:0)).
//! Error State Indicator.
//! This is a read-only status bit for RBUF and is not available in TBUF.
//! The protocol machine automatically embeds the correct value of ESI into transmitted frames.
//! ESI is only included in CAN FD frames and does not exist in CAN 2.0 frames.
//! 0 - CAN node is error active
//! 1 - CAN node is error passive
//! ESI in RBUF is always low for CAN 2.0 frames.
//! The error state for transmission is shown with bit EPASS in register ERRINT.
//! Data length code(0-64, @CAN_MsgDataLength_t).
//! Bit Rate Switch.
//! 0 - nominal / slow bit rate for the complete frame.
//! 1 - switch to data / fast bit rate for the data payload and the CRC.
//! Only CAN FD frames can switch the bitrate. Therefore BRS is forced to 0 if FDF =0.
//! CAN FD frame.
//! 0 - CAN 2.0 frame (up to 8 bytes payload).
//! 1 - CAN FD frame (up to 64 bytes payload).
//! Remote Transmission Request.
//! 0 - data frame.
//! 1 - remote frame.
//! Only CAN 2.0 frames can be remote frames. There is no remote frame for CAN FD.
//! Therefore RTR is forced to 0 if FDF =1 in TBUF and RBUF.
//! If a CAN FD frame is received with bit RRS=1, then this is ignored,
//! a data payload is expected for reception instead and RTR in RBUF is overridden
//! but the CRC of the frame is calculated with RRS=1.
//! Extended Frame Format.
//! 0 - Standard Format: ID(10:0)
//! 1 - Extended Format: ID(28:0)
//! Status bit TX in RBUF is set to 1 if the loop back mode (Chapter 3.9.10.4) is
//! activated and the core has received its own transmitted frame. This can be useful if LBME=1 and
//! other nodes in the network do also transmissions.
//! KOER in RBUF has the same meaning as the bits KOER in register EALCAP.
//! KOER in RBUF becomes meaningful if RBALL=1.
//! The time-stamp CYCLE_TIME will be stored in RBUF only in TTCAN mode.
//! This is the cycle time at the SOF of this frame.
//! The cycle time of a reference message is always 0.
//! CAN message data buffer.
//! CAN message timestamp.
//! The Reception Time Stamps (RTS) for CiA 603 time-stamping are stored for each received
//! message at the end of the RBUF address range. Therefore in contrast to TTS, RTS is related
//! to the actual selected RBUF slot.
typedef struct CAN_RxMessage {
	uint32_t id			: 29;
	uint32_t resved_0	: 2;
	uint32_t esi		: 1;
	uint32_t dlc		: 4;
	uint32_t brs		: 1;
	uint32_t fdf		: 1;
	uint32_t rtr		: 1;
	uint32_t ide		: 1;
	uint32_t resved_1	: 4;
	uint32_t tx			: 1;
	uint32_t koer		: 3;
	uint32_t cycletime	: 16;
	uint8_t data[CAN_MAX_PAYLOAD_BYTES];
	uint64_t timestamp;
} CAN_RxMessage_t;

//*****************************************************************************
//
// CAN-CTRL instance transmission message buffer structure.
//
//*****************************************************************************
//! CAN message identifier(Standard frame ID is 11 bit(10:0),
//! Extended frame ID is 29 bit(28:0)).
//! Transmit Time-Stamp Enable.
//! In contrast to RTS, which is stored for every received frame, TTS is stored only for
//! the last transmitted frame if TTSEN=1. TTS is not related to the actual selected TBUF slot.
//! Data length code(0-64, @CAN_MsgDataLength_t).
//! Bit Rate Switch.
//! 0 - nominal / slow bit rate for the complete frame.
//! 1 - switch to data / fast bit rate for the data payload and the CRC.
//! Only CAN FD frames can switch the bitrate. Therefore BRS is forced to 0 if FDF =0.
//! CAN FD frame.
//! 0 - CAN 2.0 frame (up to 8 bytes payload).
//! 1 - CAN FD frame (up to 64 bytes payload).
//! Remote Transmission Request.
//! 0 - data frame.
//! 1 - remote frame.
//! Only CAN 2.0 frames can be remote frames. There is no remote frame for CAN FD.
//! Therefore RTR is forced to 0 if FDF =1 in TBUF and RBUF.
//! If a CAN FD frame is received with bit RRS=1, then this is ignored,
//! a data payload is expected for reception instead and RTR in RBUF is overridden
//! but the CRC of the frame is calculated with RRS=1.
//! Extended Frame Format.
//! 0 - Standard Format: ID(10:0)
//! 1 - Extended Format: ID(28:0)
//! CAN message data buffer.
typedef struct CAN_TxMessage {
	uint32_t id			: 29;
	uint32_t resved_0	: 2;
	uint32_t ttsen		: 1;
	uint32_t dlc		: 4;
	uint32_t brs		: 1;
	uint32_t fdf		: 1;
	uint32_t rtr		: 1;
	uint32_t ide		: 1;
	uint32_t resved_1	: 24;
	uint8_t data[CAN_MAX_PAYLOAD_BYTES];
} CAN_TxMessage_t;

//*****************************************************************************
//
//! Set CAN-CTRL operation mode.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param mode is the operation mode of CAN-CTRL(@CAN_OperationMode_t:Reset/Normal).
//! 
//! This function sets the operation mode of the CAN-CTRL instance.
//! 
//! \return true if CAN-CTRL is initialized successfully.
//! \return false if CAN-CTRL is failed to initialize.
//
//*****************************************************************************
bool CAN_setOpMode(uint32_t base, CAN_OperationMode_t mode);

//*****************************************************************************
//
//! CAN-CTRL instance start running.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function starts the CAN-CTRL instance operation.
//! 
//! \return true if CAN-CTRL is started successfully.
//! \return false if CAN-CTRL is failed to start.
//
//*****************************************************************************
bool CAN_startModule(uint32_t base);

//*****************************************************************************
//
//! CAN-CTRL instance reset to initialization state.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function resets the CAN-CTRL instance to its initialization state.
//! 
//! \return true if CAN-CTRL is reset successfully.
//! \return false if CAN-CTRL is failed to reset.
//
//*****************************************************************************
bool CAN_initModule(uint32_t base);

//*****************************************************************************
//
//! Check if the CAN_CTRL is in resetting.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function checks whether the CAN-CTRL controller is currently in reset state.
//! 
//! \return true if the CAN-CTRL Controller is resetting.
//! \return false if the CAN-CTRL Controller is not resetting.
//
//*****************************************************************************
bool CAN_isInReset(uint32_t base);

//*****************************************************************************
//
//! Enable/Disable CAN-CTRL IP CANFD mode.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param enable true to enable CAN-FD mode, false to disable CAN-FD mode.
//! 
//! This function enables or disables the CAN-FD mode for the CAN-CTRL instance.
//! 
//! \return true if CAN-FD mode is successfully enabled/disabled.
//! \return false if enabling/disabling CAN-FD mode failed.
//
//*****************************************************************************
bool CAN_setFDMode(uint32_t base, bool enable);

//*****************************************************************************
//
//! Enable/Disable CAN-CTRL IP FD TDC.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param enable true to enable FD TDC, false to disable FD TDC.
//! \param TDCValue is the TDC value(Range:[0x0-0xFF]).
//! Suggest setting the value of TDC equal to t_seg1 + 2.
//! 
//! This function enables or disables the CAN-CTRL IP FD TDC.
//! 
//! \return true if CAN-CTRL IP FD TDC is enabled successfully.
//! \return false if CAN-CTRL IP FD TDC is disabled.
//
//*****************************************************************************
bool CAN_setFdTDC(uint32_t base, bool enable, uint32_t TDCValue);

//*****************************************************************************
//
//! Check if CAN-FD operation mode is enabled.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function checks whether the CAN-FD operation mode is enabled.
//! 
//! \return true if the CAN-FD operation mode is enabled.
//! \return false if the CAN-FD operation mode is disabled.
//
//*****************************************************************************
bool CAN_isFDOpEnable(uint32_t base);

//*****************************************************************************
//
//! CAN-Ctrl instance initialize.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param initParams is the initialization CAN-CTRL instance parameters.
//! 
//! This function initializes the CAN-CTRL instance.
//! 
//! \return true if CAN-CTRL is initialized successfully.
//! \return false if CAN-CTRL is failed to initialize.
//
//*****************************************************************************
bool CAN_initConfig(uint32_t base, const CAN_InitParams_t *initParams);

//*****************************************************************************
//
//! Set the CAN-CTRL CAN arbitration phase bit rate.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param prescaler is the Nominal Baud Rate Pre-scaler(Range:[0x0-0xFF]).
//! The value of parameter \prescaler should be equal to the actual value minus 1.
//! \param tSeg1 is the Nominal Time segment before sample point(Range:[0x0-0xFF]).
//! The value of parameter \tSeg1 should be equal to the actual value minus 2.
//! \param tSeg2 is the Nominal Time segment after sample point(Range:[0x0-0x7F]).
//! The value of parameter \tSeg2 should be equal to the actual value minus 1.
//! \param sjw is the Nominal (Re)Synchronization Jump Width(Range:[0x0-0x7F]).
//! The value of parameter \sjw should be equal to the actual value minus 1.
//! 
//! This function sets the CAN-CTRL CAN arbitration phase bit rate.
//! 
//! \return true if the bit rate is successfully set.
//! \return false if the bit rate setting failed.
//
//*****************************************************************************
bool CAN_setBitTiming(uint32_t base, uint16_t prescaler,
					uint16_t tSeg1, uint16_t tSeg2, uint16_t sjw);

//*****************************************************************************
//
//! Set the CAN-CTRL CAN data phase bit rate.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param prescaler is the Data Baud Rate Pre-scaler(Range:[0x0-0xFF]).
//! The value of parameter \prescaler should be equal to the actual value minus 1.
//! \param tSeg1 is the Data Time segment before sample point(Range:[0x0-0xFF]).
//! The value of parameter \tSeg1 should be equal to the actual value minus 2.
//! \param tSeg2 is the Data Time segment after sample point(Range:[0x0-0x7F]).
//! The value of parameter \tSeg2 should be equal to the actual value minus 1.
//! \param sjw is the Data (Re)Synchronization Jump Width(Range:[0x0-0x7F]).
//! The value of parameter \sjw should be equal to the actual value minus 1.
//! 
//! This function sets the CAN-CTRL CAN data phase bit rate.
//! 
//! \return true if the data bit rate is successfully set.
//! \return false if the data bit rate setting failed.
//
//*****************************************************************************
bool CAN_setDataBitTiming(uint32_t base, uint16_t prescaler,
						uint16_t tSeg1, uint16_t tSeg2, uint16_t sjw);

//*****************************************************************************
//
//! Set the CAN-CTRL CAN bit rate in arbitration phase.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param clockFreq is the CAN-CTRL instance main clock frequency(Hz).
//! \param bitRate is the targets bit rate(bps).
//! \param bitTime is the targets bit time(bittime = frequency/(prescalar * (tSeg1 + tSeg2))).
//! 
//! This function sets the CAN-CTRL CAN bit rate in arbitration phase.
//! 
//! \return true if the bit rate is successfully set.
//! \return false if the bit rate setting failed.
//
//*****************************************************************************
bool CAN_setBitRate(uint32_t base, uint32_t clockFreq, uint32_t bitRate, uint16_t bitTime);

//*****************************************************************************
//
//! Set the CAN-CTRL CAN bit rate in data phase.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param clockFreq is the CAN-CTRL instance main clock frequency(Hz).
//! \param bitRate is the targets bit rate(bps).
//! \param bitTime is the targets bit time(bittime = frequency/(prescalar * (tSeg1 + tSeg2))).
//! 
//! This function sets the CAN-CTRL CAN bit rate in data phase.
//! 
//! \return true if the bit rate is successfully set.
//! \return false if the bit rate setting failed.
//
//*****************************************************************************
bool CAN_setDataBitRate(uint32_t base, uint32_t clockFreq, uint32_t bitRate, uint16_t bitTime);

//*****************************************************************************
//
//! Configuration the CAN-CTRL bit rate in arbitration phase.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param clockFreq is the CAN-CTRL instance main clock frequency(Hz).
//! \param bitRate is the targets bit rate(bps).
//! \param sample_point is the CAN2.0 sample point(S_seg1 / (S_seg1 + S_seg2)).
//! 
//! This function configures the CAN-CTRL bit rate in arbitration phase.
//! 
//! \return true if the bit rate is successfully configured.
//! \return false if the bit rate configuration failed.
//
//*****************************************************************************
bool CAN_setBitRateSamplePoint(uint32_t base, uint32_t clockFreq,
							uint32_t bitrate, float32_t sample_point);

//*****************************************************************************
//
//! Configuration the CAN-CTRL bit rate in data phase.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param clockFreq is the CAN-CTRL instance main clock frequency(Hz).
//! \param bitrate is the targets bit rate(bps).
//! \param sample_point is the CANFD sample point(F_seg1 / (F_seg1 + F_seg2)).
//! 
//! This function configures the CAN-CTRL bit rate in data phase.
//! 
//! \return true if the bit rate is successfully configured.
//! \return false if the bit rate configuration failed.
//
//*****************************************************************************
bool CAN_setDataBitRateSamplePoint(uint32_t base, uint32_t clockFreq,
								uint32_t bitrate, float32_t sample_point);

//*****************************************************************************
//
//! Configuration the CAN-CTRL receive message filter.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param filtNum is the filter number.
//! \param elem is the filter element(@CAN_FilterElement_t).
//! 
//! This function configures the CAN-CTRL receive message filter.
//! 
//! \return true if the filter is successfully configured.
//! \return false if the filter configuration failed.
//
//*****************************************************************************
bool CAN_configMsgFilter(uint32_t base, uint32_t filtNum, const CAN_FilterElement_t *elem);

//*****************************************************************************
//
//! Enable the CAN ID filter.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param filtNum is the filter number.
//! 
//! This function enables the specified CAN ID filter.
//! 
//! \return true if the filter is successfully enabled.
//! \return false if enabling the filter failed.
//
//*****************************************************************************
bool CAN_configMsgFilterEnable(uint32_t base, uint32_t filtNum);

//*****************************************************************************
//
//! Disable the CAN ID filter.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param filtNum is the filter number.
//! 
//! This function disables the specified CAN ID filter.
//! 
//! \return true if the filter is successfully disabled.
//! \return false if disabling the filter failed.
//
//*****************************************************************************
bool CAN_configMsgFilterDisable(uint32_t base, uint32_t filtNum);

//*****************************************************************************
//
//! Add a CAN ID filter.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param acode is the filter acceptance code.
//! \param mask is the filter acceptance mask.
//! \param type is the filter type(standard or extended, @CAN_IDFilterType_t).
//! 
//! This function adds a CAN ID filter.
//! 
//! \return true if the filter is successfully added.
//! \return false if adding the filter failed.
//
//*****************************************************************************
bool CAN_addMsgFilter(uint32_t base, uint32_t acode, uint32_t mask, CAN_IDFilterType_t type);

//*****************************************************************************
//
//! Enable/Disable the loopback mode.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param lpbkMode choose between internal or external loop modes(@CAN_LpbkMode_t).
//! \param enable true to enable, false to disable.
//! 
//! This function enables or disables the loopback mode.
//! 
//! \return true if the loopback mode is successfully enabled/disabled.
//! \return false if enabling/disabling the loopback mode failed.
//
//*****************************************************************************
bool CAN_lpbkModeEnable(uint32_t base, CAN_LpbkMode_t lpbkMode, bool enable);

//*****************************************************************************
//
//! Enable/Disable the CAN-CTRL auto retransmission.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param enable true to enable auto retransmission, false to disable auto retransmission.
//! 
//! This function enables or disables the CAN-CTRL auto retransmission.
//
//*****************************************************************************
bool CAN_setAutoRetransmission(uint32_t base, bool enable);

//*****************************************************************************
//
//! Get the number of errors during reception and transmission for the CAN-CTRL.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param rxCount is the pointer to the receive error counter.
//! \param txCount is the pointer to the transmit error counter.
//! 
//! This function retrieves the number of errors during reception and transmission for the CAN-CTRL.
//! 
//! \return true if the error counters are successfully retrieved.
//! \return false if retrieving the error counters failed.
//
//*****************************************************************************
bool CAN_getErrorCount(uint32_t base, uint32_t *rxCount, uint32_t *txCount);

//*****************************************************************************
//
//! Get the CAN bus error status.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function retrieves the CAN bus error status.
//! 
//! \return The CAN bus error status(@CAN_IDFilterType_t).
//! If return value is 0, the CAN bus is in normal state,
//! otherwise the CAN bus is in error state or input parameter is invalid.
//
//*****************************************************************************
int CAN_getStatus(uint32_t base);

//*****************************************************************************
//
//! Get the status of the receive buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function retrieves the status of the receive buffer.
//! 
//! \return CAN-CTRL receive buffer status(@CAN_TxBufMode_t).
//
//*****************************************************************************
CAN_RxMsgBufStatus_t CAN_getRxBufState(uint32_t base);

//*****************************************************************************
//
//! Get the status of the secondary buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function retrieves the status of the secondary buffer.
//! 
//! \return CAN-CTRL secondary buffer status(@CAN_TxMsgBufStatus_t).
//
//*****************************************************************************
CAN_TxMsgBufStatus_t CAN_getTxSecondaryBufState(uint32_t base);

//*****************************************************************************
//
//! Get the status of the primary buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function retrieves the status of the primary buffer.
//! 
//! \return If the return value is non-zero, the Primary buffer is full.
//! If the return value is 0, the Primary buffer is empty.
//! If the return value is 1, the Primary buffer is full.
//
//*****************************************************************************
int CAN_getTxPrimaryBufState(uint32_t base);

//*****************************************************************************
//
//! Write a CAN message to the secondary buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param pTxFrame is the pointer to the CAN message.
//! 
//! This function writes a CAN message to the secondary buffer.
//! 
//! \return true if writing is successful.
//! \return false if writing failed.
//
//*****************************************************************************
bool CAN_writeTxMsgToSTB(uint32_t base, CAN_TxMessage_t *pTxFrame);

//*****************************************************************************
//
//! Start transmission once message in Tx buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function starts transmission of a single message in the Tx buffer.
//! Only used in secondary buffer mode.
//! 
//! \return true if starting transmission is successful.
//! \return false if starting transmission failed.
//
//*****************************************************************************
bool CAN_startTransmissionOnce(uint32_t base);

//*****************************************************************************
//
//! Start transmission all message in Tx buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function starts transmission of all messages in the Tx buffer.
//! Only used in secondary buffer mode.
//! 
//! \return true if starting transmission is successful.
//! \return false if starting transmission failed.
//
//*****************************************************************************
bool CAN_startTransmissionAll(uint32_t base);

//*****************************************************************************
//
//! Start high-priority transmission of message in Tx primary buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function starts high-priority transmission of message in the Tx primary buffer.
//! 
//! \return true if starting transmission is successful.
//! \return false if starting transmission failed.
//
//*****************************************************************************
bool CAN_startTransmissionHighPrimaryMsg(uint32_t base);

//*****************************************************************************
//
//! Get the data length of the message.
//! 
//! \param size is the data length of the message.
//! 
//! This function retrieves the data length of a message.
//! 
//! \return If the return value is less than zero, the length retrieval fails;
//! otherwise, the length is returned.
//
//*****************************************************************************
int CAN_getMessageLength(CAN_MsgDataLength_t size);

//*****************************************************************************
//
//! Transmit a CAN message.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param pTxFrame is the pointer to the CAN message.
//! 
//! This function transmits a CAN message.
//! 
//! \return true if the CAN message is successfully transmitted.
//! \return false if transmission of the CAN message failed.
//
//*****************************************************************************
bool CAN_transmitMsg(uint32_t base, CAN_TxMessage_t *pTxFrame);

//*****************************************************************************
//
//! Transmit a CAN message in primary buffer.
//! 
//! The Primary buff is used to transmit a CAN message with the highest priority.
//! This message priority is different from the arbitration priority defined in the CAN protocol.
//! It is an absolute priority, and the messages stored in this buffer must be sent out with the
//! highest priority.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param pTxFrame is the pointer to the CAN message.
//! 
//! This function transmits a high-priority CAN message using the primary buffer.
//! 
//! \return true if the CAN message is successfully transmitted.
//! \return false if transmission of the CAN message failed.
//
//*****************************************************************************
bool CAN_transmitHighPriorityMsg(uint32_t base, CAN_TxMessage_t *pTxFrame);

//*****************************************************************************
//
//! Aborts a transmission from STB which has been requested but not started yet.
//! 
//! For a TSONE transmission, only one frame is aborted while for a TSALL
//! Transmission, all frames are aborted.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function aborts a pending transmission from the secondary buffer.
//! 
//! \return true if the abort is successful.
//! \return false if the abort failed.
//
//*****************************************************************************
bool CAN_transmitSecondaryAbort(uint32_t base);

//*****************************************************************************
//
//! Aborts a transmission from Primary buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function aborts a pending transmission from the primary buffer.
//! 
//! \return true if the abort is successful.
//! \return false if the abort failed.
//
//*****************************************************************************
bool CAN_transmitPrimaryAbort(uint32_t base);

//*****************************************************************************
//
//! Release current Rx buffer.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function releases the current receive buffer.
//! 
//! \return true if the release is successful.
//! \return false if the release failed.
//
//*****************************************************************************
bool CAN_releaseRxBuf(uint32_t base);

//*****************************************************************************
//
//! Receive a CAN message.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param pRxFrame is the pointer to the CAN message.
//! 
//! This function receives a CAN message.
//! 
//! \return true if the CAN message is received successfully.
//! \return false if receiving the CAN message failed.
//
//*****************************************************************************
bool CAN_receiveMsg(uint32_t base, CAN_RxMessage_t *pRxFrame);

//*****************************************************************************
//
//! Set error warning level.
//! 
//! Programmable Error Warning Limit = (EWL+1)*8. Possible Limit values: 8, 16, 64, 128.
//! The value of EWL controls EIF.EWL needs to be transferred using CDC from host
//! to CAN clock domain. During transfer EWL register bits are write-locked for
//! the host for a few clocks until CDC is complete.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param level is the error warning level (the level valid range is 0~15).
//! 
//! This function sets the error warning level for the CAN controller.
//! 
//! \return true if setting the error level is successful.
//! \return false if setting the error level failed.
//
//*****************************************************************************
bool CAN_setErrWarnLevel(uint32_t base, uint8_t level);

//*****************************************************************************
//
//! Obtain the error warning level.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function retrieves the current error warning level from the CAN controller.
//! 
//! \return The error warning level. If the return value is less than 0, it indicates an error.
//
//*****************************************************************************
int CAN_getErrWarnLevel(uint32_t base);

//*****************************************************************************
//
//! Set the Rx buffer almost full level.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param level is the almost full level (the level valid range is 0~15).
//! 
//! This function sets the receive buffer almost full threshold level.
//! 
//! \return true if setting the almost full level is successful.
//! \return false if setting the almost full level failed.
//
//*****************************************************************************
bool CAN_setRxBufAlmostFullLevel(uint32_t base, uint8_t level);

//*****************************************************************************
//
//! Obtain the Rx buffer almost full level.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function retrieves the current receive buffer almost full threshold level.
//! 
//! \return The almost full level. If the return value is less than 0, it indicates an error.
//
//*****************************************************************************
int CAN_getRxBufAlmostFullLevel(uint32_t base);

//*****************************************************************************
//
//! Enable CAN transfer interrupt. This API enables interrupts during transmission.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param intFlag is the interrupt flag.
//! \param CAN_RTIE_RIE_M Receive Interrupt Enable.
//! \param CAN_RTIE_ROIE_M RB Overrun Interrupt Enable.
//! \param CAN_RTIE_RFIE_M RB Full Interrupt Enable.
//! \param CAN_RTIE_RAFIE_M RB Almost Full Interrupt Enable.
//! \param CAN_RTIE_TPIE_M Transmission Primary Interrupt Enable.
//! \param CAN_RTIE_TSIE_M Transmission Secondary Interrupt Enable
//! \param CAN_RTIE_EIE_M Error Interrupt Enable.
//! \param CAN_ERRINT_ALIE_M Arbitration Lost Interrupt Enable.
//! \param CAN_ERRINT_BEIE_M Bus Error Interrupt Enable.
//! \param CAN_ERRINT_EPIE_M Error Passive Interrupt Enable.
//! 
//! This function enables CAN transfer interrupts during transmission.
//! 
//! \return true if enabling the interrupt is successful.
//! \return false if enabling the interrupt failed.
//
//*****************************************************************************
bool CAN_enableInterrupt(uint32_t base, uint32_t intFlag);

//*****************************************************************************
//
//! Disable CAN transfer interrupt.
//! 
//! \param baseAddr is the base address of CAN-CTRL IP.
//! \param intFlag is the interrupt flag.
//! \param CAN_RTIE_RIE_M Receive Interrupt Disable.
//! \param CAN_RTIE_ROIE_M RB Overrun Interrupt Disable.
//! \param CAN_RTIE_RFIE_M RB Full Interrupt Disable.
//! \param CAN_RTIE_RAFIE_M RB Almost Full Interrupt Disable.
//! \param CAN_RTIE_TPIE_M Transmission Primary Interrupt Disable.
//! \param CAN_RTIE_TSIE_M Transmission Secondary Interrupt Disable
//! \param CAN_RTIE_EIE_M Error Interrupt Disable.
//! \param CAN_ERRINT_ALIE_M Arbitration Lost Interrupt Disable.
//! \param CAN_ERRINT_BEIE_M Bus Error Interrupt Disable.
//! \param CAN_ERRINT_EPIE_M Error Passive Interrupt Disable.
//! 
//! This function disables CAN transfer interrupts.
//! 
//! \return true if disabling the interrupt is successful.
//! \return false if disabling the interrupt failed.
//
//*****************************************************************************
bool CAN_disableInterrupt(uint32_t base, uint32_t intFlag);

//*****************************************************************************
//
//! Get the interrupt status.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! 
//! This function retrieves the current interrupt status of the CAN controller.
//! 
//! \return The interrupt status.
//! \param CAN_RTIF_RIF_M Data or a remote frame has been received and is available in the receive buffer.
//! \param CAN_RTIF_ROIF_M At least one received message has been overwritten in the RB.
//! \param CAN_RTIF_RFIF_M All RBs are full. If no RB will be released until the next valid message
//! is received,the oldest message will be lost.
//! \param CAN_RTIF_RAFIF_M RB Almost Full Interrupt Flag.
//! \param CAN_RTIF_TPIF_M The requested transmission of the PTB has been successfully completed.
//! \param CAN_RTIF_TSIF_M The requested transmission of the STB has been successfully completed.
//! \param CAN_RTIF_EIF_M The border of the error warning limit has been crossed in either direction,
//! or the BUSOFF bit has been changed in either direction.
//! 
//! \param CAN_RTIF_AIF_M After setting TPA or TSA the appropriated message(s) have been aborted.
//! It is recommended to not set both TPA and TSA simultaneously because both source AIF.
//! 
//! \param CAN_ERRINT_BEIF_M EPIF will be activated if the error status changes from error
//! active to error passive or vice versa and if this interrupt is enabled.
//! \param CAN_ERRINT_ALIF_M Arbitration Lost Interrupt Flag.
//! \param CAN_ERRINT_EPIF_M Bus Error Interrupt Flag.
//
//*****************************************************************************
uint32_t CAN_getIntrStatus(uint32_t base);

//*****************************************************************************
//
//! Clear the interrupt status.
//! 
//! \param base is the base address of CAN-CTRL IP.
//! \param intFlag is the interrupt flag to clear.
//! 
//! This function clears the specified interrupt status flags in the CAN controller.
//! 
//! \return The interrupt status after clearing.
//! \param CAN_RTIF_RIF_M Data or a remote frame has been received and is available in the receive buffer.
//! \param CAN_RTIF_ROIF_M At least one received message has been overwritten in the RB.
//! \param CAN_RTIF_RFIF_M All RBs are full. If no RB will be released until the next valid message
//! is received,the oldest message will be lost.
//! \param CAN_RTIF_RAFIF_M RB Almost Full Interrupt Flag.
//! \param CAN_RTIF_TPIF_M The requested transmission of the PTB has been successfully completed.
//! \param CAN_RTIF_TSIF_M The requested transmission of the STB has been successfully completed.
//! \param CAN_RTIF_EIF_M The border of the error warning limit has been crossed in either direction,
//! or the BUSOFF bit has been changed in either direction.
//! 
//! \param CAN_RTIF_AIF_M After setting TPA or TSA the appropriated message(s) have been aborted.
//! It is recommended to not set both TPA and TSA simultaneously because both source AIF.
//! 
//! \param CAN_ERRINT_BEIF_M EPIF will be activated if the error status changes from error
//! active to error passive or vice versa and if this interrupt is enabled.
//! \param CAN_ERRINT_ALIF_M Arbitration Lost Interrupt Flag.
//! \param CAN_ERRINT_EPIF_M Bus Error Interrupt Flag.
//
//*****************************************************************************
uint32_t CAN_clearIntrStatus(uint32_t base, uint32_t intFlag);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif


#endif

