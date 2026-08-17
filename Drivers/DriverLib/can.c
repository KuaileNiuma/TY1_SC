/** 
  ************************************************************************************* 
  * @file can.c 
  * @brief This file implements the function of can driver. 
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
  
#include "can.h"
#include <string.h>

//static const uint32_t CAN_BaseAddressArray[] = CAN_BASE_ADDR_ARRAY;
static const uint8_t CAN_DataLengthArray[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

bool CAN_isInReset(uint32_t base)
{
	if(HWREG(base + CAN_O_CFG_STAT) & CAN_CFG_STAT_RESET_M)
		return true;
	else
		return false;
}

bool CAN_isFDOpEnable(uint32_t base)
{
	for (uint8_t i = 0; i < CAN_CTRL_NUMBER_OF_INSTANCES; i++)
	{
//		return SysCtl_getCanFdEnable(i); //is or not modfy
		return true;
	}

	return false;
}

bool CAN_setFDMode(uint32_t base, bool enable)
{
	for (uint8_t i = 0; i < CAN_CTRL_NUMBER_OF_INSTANCES; i++) {
			//	SysCtl_setCanFdEnable(i, enable);   //is or not modfy
			return true;
	}

	return false;
}

//*****************************************************************************
//
// CAN_setTDCValue
//
//*****************************************************************************
static void CAN_setTDCValue(uint32_t base, uint32_t TDCValue)
{
	HWREG(base + CAN_O_TDC) &= ~CAN_TDC_SSPOFF_M;

	HWREG(base + CAN_O_TDC) |= ((TDCValue << CAN_TDC_SSPOFF_S) & CAN_TDC_SSPOFF_M);
}

//*****************************************************************************
//
// CAN_enableTDC
//
//*****************************************************************************
static void CAN_enableTDC(uint32_t base, bool enable)
{
	if (enable)
		HWREG(base + CAN_O_TDC) |= CAN_TDC_TDCEN_M;
	else
		HWREG(base + CAN_O_TDC) &= ~CAN_TDC_TDCEN_M;
}

bool CAN_setFdTDC(uint32_t base, bool enable, uint32_t TDCValue)
{
//	if (!CAN_isBaseValid(base))
//		return false;

	CAN_enableTDC(base, enable);

	CAN_setTDCValue(base, TDCValue);

	return true;
}

//*****************************************************************************
//
// CAN_setListenOnlyMode
//
//*****************************************************************************
static void CAN_setListenOnlyMode(uint32_t base, bool enable)
{
	if (enable)
		HWREG(base + CAN_O_TCMD) |= CAN_TCMD_LOM_M;
	else
		HWREG(base + CAN_O_TCMD) &= ~CAN_TCMD_LOM_M;
}

//*****************************************************************************
//
// CAN_setAutoRetransmission
//
//*****************************************************************************
bool CAN_setAutoRetransmission(uint32_t base, bool enable)
{
//	if (!CAN_isBaseValid(base))
//		return false;

	if (enable) {
		HWREG(base + CAN_O_CFG_STAT) &= ~CAN_CFG_STAT_TPSS_M;
		HWREG(base + CAN_O_CFG_STAT) &= ~CAN_CFG_STAT_TSSS_M;
	} else {
		HWREG(base + CAN_O_CFG_STAT) |= CAN_CFG_STAT_TPSS_M;
		HWREG(base + CAN_O_CFG_STAT) |= CAN_CFG_STAT_TSSS_M;
	}

	return true;
}

//*****************************************************************************
//
// CAN_selectTxBufMode
//
//*****************************************************************************
static void CAN_setTransmitBufferMode(uint32_t base, CAN_TxBufferMode_t mode)
{
	if (mode == CAN_TS_MODE_FIFO)
		HWREG(base + CAN_O_TCTRL) &= ~CAN_TCTRL_TSMODE_M;
	else if (mode == CAN_TS_MODE_PRIORITY)
		HWREG(base + CAN_O_TCTRL) |= CAN_TCTRL_TSMODE_M;
}


//*****************************************************************************
//
// CAN_setTimeStampMode
//
//*****************************************************************************
static void CAN_setTimeStampMode(uint32_t base, CAN_TimeStampMode_t mode)
{
	if (mode == CAN_DIS_TIMESTAMP)
		HWREG(base + CAN_O_TIMECFG) &= ~CAN_TIMECFG_TIMEEN_M;
	else if (mode == CAN_TIMESTAMP_EOF) {
		HWREG(base + CAN_O_TIMECFG) |= CAN_TIMECFG_TIMEEN_M;
		HWREG(base + CAN_O_TIMECFG) |= CAN_TIMECFG_TIMEPOS_M;
	} else if (mode == CAN_TIMESTAMP_SOF) {
		HWREG(base + CAN_O_TIMECFG) |= CAN_TIMECFG_TIMEEN_M;
		HWREG(base + CAN_O_TIMECFG) &= ~CAN_TIMECFG_TIMEPOS_M;
	}
}

//*****************************************************************************
//
// CAN_setOpMode
//
//*****************************************************************************
bool
CAN_setOpMode(uint32_t base, CAN_OperationMode_t mode)
{
	/* Reset CAN-CTRL IP instance. */
	if(mode == CAN_OPERATION_MODE_SW_INIT)
		HWREG(base + CAN_O_CFG_STAT) |= CAN_CFG_STAT_RESET_M;
	else if(mode == CAN_OPERATION_MODE_NORMAL)
		HWREG(base + CAN_O_CFG_STAT) &= ~CAN_CFG_STAT_RESET_M;

	return true;
}

//*****************************************************************************
//
// CAN_initModule
//
//*****************************************************************************
bool
CAN_initModule(uint32_t base)
{

	HWREG(base + CAN_O_CFG_STAT) |= CAN_CFG_STAT_RESET_M;

	CAN_disableInterrupt(base, CAN_RTIE_ALL_M);

	return true;
}

//*****************************************************************************
//
// CAN_startModule
//
//*****************************************************************************
bool
CAN_startModule(uint32_t base)
{

	HWREG(base + CAN_O_CFG_STAT) &= ~CAN_CFG_STAT_RESET_M;

	return true;
}

//*****************************************************************************
//
// CAN_initConfig
//
//*****************************************************************************
bool
CAN_initConfig(uint32_t base, const CAN_InitParams_t *initParams)
{

	if (initParams == NULL)
		return false;

	//
	// Is enable CANFD mode.
	//
	if (initParams->fdMode) {
		//
		// Enable CANFD mode.
		//
		CAN_setFDMode(base, true);

		//
		// Set CANFD frame mode.
		//
		if (initParams->fdFrame == CAN_FD_ISO_11898_1)
			HWREG(base + CAN_O_TCTRL) |= CAN_TCTRL_FD_ISO_M;
		else
			HWREG(base + CAN_O_TCTRL) &= ~CAN_TCTRL_FD_ISO_M;
	} else
		CAN_setFDMode(base, false);

	//
	// Is enable listen only mode.
	//
	CAN_setListenOnlyMode(base, initParams->listenOnlyEnable);

	//
	// Enable/Disable transmit buffer secondary operation mode.
	//
	CAN_setTransmitBufferMode(base, initParams->txbmode);

	//
	// Configuration timestamp mode.
	//
	CAN_setTimeStampMode(base, initParams->timestamp);

	//
	// Disable all interrupt.
	//
	CAN_disableInterrupt(base, CAN_ALL_INT_EN_MASK);

	return true;
}

//*****************************************************************************
//
// CAN_setBitTime
//
//*****************************************************************************
static inline bool CAN_setBitTime(uint32_t base, const CAN_BitTimingParams_t *configParams)
{
	if (CAN_isFDOpEnable(base)) {
		if ((configParams->nomRatePrescalar > CAN_NBTP_NBRP_MAX) ||
			(configParams->nomSynchJumpWidth > CAN_NBTP_NSJW_MAX) ||
			(configParams->nomTimeSeg1 > CAN_NBTP_NTSEG1_MAX) ||
			(configParams->nomTimeSeg2 > CAN_NBTP_NTSEG2_MAX_CANFD_MODE) ||

			(configParams->dataRatePrescalar > CAN_DBTP_DBRP_MAX) ||
			(configParams->dataSynchJumpWidth > CAN_DBTP_DSJW_MAX) ||
			(configParams->dataTimeSeg1 > CAN_DBTP_DTSEG1_MAX) ||
			(configParams->dataTimeSeg2 > CAN_DBTP_DTSEG2_MAX))

			return false;
	} else {
		if ((configParams->nomRatePrescalar > CAN_NBTP_NBRP_MAX) ||
			(configParams->nomSynchJumpWidth > CAN_NBTP_NSJW_MAX) ||
			(configParams->nomTimeSeg1 > CAN_NBTP_NTSEG1_MAX) ||
			(configParams->nomTimeSeg2 > CAN_NBTP_NTSEG2_MAX_CAN_MODE))
			return false;
	}

	//
	// Set Clock source prescalar in nominal phase.
	//
	HWREG(base + CAN_O_S_PRESC) &= ~CAN_S_PRESC_S_PRESC_M;
	HWREG(base + CAN_O_S_PRESC) |= (((uint32_t)configParams->nomRatePrescalar <<
									CAN_S_PRESC_S_PRESC_S) & CAN_S_PRESC_S_PRESC_M);

	//
	// Set Time Segment 1 in nominal phase.
	//
	HWREG(base + CAN_O_S_SEG_1) &= ~CAN_S_SEG_1_S_SEG_1_M;
	HWREG(base + CAN_O_S_SEG_1) |= (((uint32_t)configParams->nomTimeSeg1 <<
									CAN_S_SEG_1_S_SEG_1_S) & CAN_S_SEG_1_S_SEG_1_M);

	//
	// Set Time Segment 2 in nominal phase.
	//
	HWREG(base + CAN_O_S_SEG_2) &= ~CAN_S_SEG_2_S_SEG_2_M;
	HWREG(base + CAN_O_S_SEG_2) |= (((uint32_t)configParams->nomTimeSeg2 <<
									CAN_S_SEG_2_S_SEG_2_S) & CAN_S_SEG_2_S_SEG_2_M);

	//
	// Set Synch Jump Width in nominal phase.
	//
	HWREG(base + CAN_O_S_SJW) &= ~CAN_S_SJW_S_SJW_M;
	HWREG(base + CAN_O_S_SJW) |= (((uint32_t)configParams->nomSynchJumpWidth <<
									CAN_S_SJW_S_SJW_S) & CAN_S_SJW_S_SJW_M);

	/* 2. Configuration Data pahse Bit Time. */
	if (!CAN_isFDOpEnable(base))
		return true;

	//
	// Set Clock source prescalar in data phase.
	//
	HWREG(base + CAN_O_F_PRESC) &= ~CAN_F_PRESC_F_PRESC_M;
	HWREG(base + CAN_O_F_PRESC) |= (((uint32_t)configParams->dataRatePrescalar <<
									CAN_F_PRESC_F_PRESC_S) & CAN_F_PRESC_F_PRESC_M);

	//
	// Set Time Segment 1 in data phase.
	//
	HWREG(base + CAN_O_F_SEG_1) &= ~CAN_F_SEG_1_F_SEG_1_M;
	HWREG(base + CAN_O_F_SEG_1) |= (((uint32_t)configParams->dataTimeSeg1 <<
									CAN_F_SEG_1_F_SEG_1_S) & CAN_F_SEG_1_F_SEG_1_M);

	//
	// Set Time Segment 2 in data phase.
	//
	HWREG(base + CAN_O_F_SEG_2) &= ~CAN_F_SEG_2_F_SEG_2_M;
	HWREG(base + CAN_O_F_SEG_2) |= (((uint32_t)configParams->dataTimeSeg2 <<
									CAN_F_SEG_2_F_SEG_2_S) & CAN_F_SEG_2_F_SEG_2_M);

	//
	// Set Synch Jump Width in data phase.
	//
	HWREG(base + CAN_O_F_SJW) &= ~CAN_F_SJW_F_SJW_M;
	HWREG(base + CAN_O_F_SJW) |= (((uint32_t)configParams->dataSynchJumpWidth <<
									CAN_F_SJW_F_SJW_S) & CAN_F_SJW_F_SJW_M);

	return true;
}

//*****************************************************************************
//
// CAN_getBitTime
//
//*****************************************************************************
static inline void CAN_getBitTime(uint32_t base, CAN_BitTimingParams_t *configParams)
{
	configParams->nomRatePrescalar = (HWREG(base + CAN_O_S_PRESC) &
								CAN_S_PRESC_S_PRESC_M) >> CAN_S_PRESC_S_PRESC_S;
	configParams->nomTimeSeg1 = (HWREG(base + CAN_O_S_SEG_1) &
								CAN_S_SEG_1_S_SEG_1_M) >> CAN_S_SEG_1_S_SEG_1_S;
	configParams->nomTimeSeg2 = (HWREG(base + CAN_O_S_SEG_2) &
								CAN_S_SEG_2_S_SEG_2_M) >> CAN_S_SEG_2_S_SEG_2_S;
	configParams->nomSynchJumpWidth = (HWREG(base + CAN_O_S_SJW) &
								CAN_S_SJW_S_SJW_M) >> CAN_S_SJW_S_SJW_S;

	configParams->dataRatePrescalar = (HWREG(base + CAN_O_F_PRESC) &
								CAN_F_PRESC_F_PRESC_M) >> CAN_F_PRESC_F_PRESC_S;
	configParams->dataTimeSeg1 = (HWREG(base + CAN_O_F_SEG_1) &
								CAN_F_SEG_1_F_SEG_1_M) >> CAN_F_SEG_1_F_SEG_1_S;
	configParams->dataTimeSeg2 = (HWREG(base + CAN_O_F_SEG_2) &
								CAN_F_SEG_2_F_SEG_2_M) >> CAN_F_SEG_2_F_SEG_2_S;
	configParams->dataSynchJumpWidth = (HWREG(base + CAN_O_F_SJW) &
								CAN_F_SJW_F_SJW_M) >> CAN_F_SJW_F_SJW_S;
}

//*****************************************************************************
//
// CAN_setBitTiming
//
//*****************************************************************************
bool
CAN_setBitTiming(uint32_t base, uint16_t prescaler,
			uint16_t tSeg1, uint16_t tSeg2, uint16_t sjw)
{

	if (CAN_isFDOpEnable(base)) {
		if ((prescaler > CAN_NBTP_NBRP_MAX) ||
			(sjw > CAN_NBTP_NSJW_MAX) ||
			(tSeg1 > CAN_NBTP_NTSEG1_MAX) ||
			(tSeg2 > CAN_NBTP_NTSEG2_MAX_CANFD_MODE))
			return false;
	} else {
		if ((prescaler > CAN_NBTP_NBRP_MAX) ||
			(sjw > CAN_NBTP_NSJW_MAX) ||
			(tSeg1 > CAN_NBTP_NTSEG1_MAX) ||
			(tSeg2 > CAN_NBTP_NTSEG2_MAX_CAN_MODE))
			return false;
	}

	/* Set Clock source prescalar in nominal phase. */
	HWREG(base + CAN_O_S_PRESC) &= ~CAN_S_PRESC_S_PRESC_M;
	HWREG(base + CAN_O_S_PRESC) |= (((uint32_t)prescaler <<
									CAN_S_PRESC_S_PRESC_S) & CAN_S_PRESC_S_PRESC_M);

	/* Set Time Segment 1 in nominal phase. */
	HWREG(base + CAN_O_S_SEG_1) &= ~CAN_S_SEG_1_S_SEG_1_M;
	HWREG(base + CAN_O_S_SEG_1) |= (((uint32_t)tSeg1 <<
									CAN_S_SEG_1_S_SEG_1_S) & CAN_S_SEG_1_S_SEG_1_M);

	/* Set Time Segment 2 in nominal phase. */
	HWREG(base + CAN_O_S_SEG_2) &= ~CAN_S_SEG_2_S_SEG_2_M;
	HWREG(base + CAN_O_S_SEG_2) |= (((uint32_t)tSeg2 <<
									CAN_S_SEG_2_S_SEG_2_S) & CAN_S_SEG_2_S_SEG_2_M);

	/* Set Synch Jump Width in nominal phase. */
	HWREG(base + CAN_O_S_SJW) &= ~CAN_S_SJW_S_SJW_M;
	HWREG(base + CAN_O_S_SJW) |= (((uint32_t)sjw <<
									CAN_S_SJW_S_SJW_S) & CAN_S_SJW_S_SJW_M);

	return true;
}

//*****************************************************************************
//
// CAN_setDataBitTiming
//
//*****************************************************************************
bool
CAN_setDataBitTiming(uint32_t base, uint16_t prescaler,
			uint16_t tSeg1, uint16_t tSeg2, uint16_t sjw)
{

	if ((prescaler > CAN_DBTP_DBRP_MAX) ||
		(sjw > CAN_DBTP_DSJW_MAX) ||
		(tSeg1 > CAN_DBTP_DTSEG1_MAX) ||
		(tSeg2 > CAN_DBTP_DTSEG2_MAX))
		return false;

	/* Set Clock source prescalar in data phase. */
	HWREG(base + CAN_O_F_PRESC) &= ~CAN_F_PRESC_F_PRESC_M;
	HWREG(base + CAN_O_F_PRESC) |= (((uint32_t)prescaler <<
									CAN_F_PRESC_F_PRESC_S) & CAN_F_PRESC_F_PRESC_M);

	// 
	//Set Time Segment 1 in data phase 
	//
	HWREG(base + CAN_O_F_SEG_1) &= ~CAN_F_SEG_1_F_SEG_1_M;
	HWREG(base + CAN_O_F_SEG_1) |= (((uint32_t)tSeg1 <<
									CAN_F_SEG_1_F_SEG_1_S) & CAN_F_SEG_1_F_SEG_1_M);

	// 
	//Set Time Segment 2 in data phase 
	//
	HWREG(base + CAN_O_F_SEG_2) &= ~CAN_F_SEG_2_F_SEG_2_M;
	HWREG(base + CAN_O_F_SEG_2) |= (((uint32_t)tSeg2 <<
									CAN_F_SEG_2_F_SEG_2_S) & CAN_F_SEG_2_F_SEG_2_M);

	// 
	//Set Synch Jump Width in data phase 
	//
	HWREG(base + CAN_O_F_SJW) &= ~CAN_F_SJW_F_SJW_M;
	HWREG(base + CAN_O_F_SJW) |= (((uint32_t)sjw <<
									CAN_F_SJW_F_SJW_S) & CAN_F_SJW_F_SJW_M);

	return true;
}

//*****************************************************************************
//
// CAN_setBitRate
//
//*****************************************************************************
bool
CAN_setBitRate(uint32_t base, uint32_t clockFreq, uint32_t bitRate, uint16_t bitTime)
{
	uint32_t brp;
	uint32_t tSeg1;
	uint32_t tSeg2;
	uint32_t sjw;
	uint32_t prescaler;
	float ftseg2 = 0.0f;
	float sampRate = 0.0f;

//	if (!CAN_isBaseValid(base))
//		return false;

	if (bitRate > 1000000U || bitRate == 0U)
		return false;

	// 
	//Set the sampling rate based on the requested bit rate 
	//
	if (bitRate > 800000U)
		sampRate = 0.750f;
	else if (bitRate > 500000U)
		sampRate = 0.800f;
	else
		sampRate = 0.875f;

	//
	// Calculate bit timing values.
	//
	brp = clockFreq / (bitRate * bitTime);
	tSeg2 = (uint32_t)(bitTime * (1.0f - sampRate) + 0.5f);
	tSeg1 = bitTime - tSeg2;

	if(tSeg2 > 4U)
		sjw = 3U;
	else
		sjw = tSeg2;

	//
	// Adjust the timing values to fit the CAN register.
	//
	prescaler = brp - 1U;
	tSeg1 -= 2U;
	tSeg2 -= 1U;
	sjw -= 1U;

	/* Set the calculated timing parameters. */
	return CAN_setBitTiming(base, prescaler, tSeg1, tSeg2, sjw);
}

//*****************************************************************************
//
// CAN_setDataBitRate
//
//*****************************************************************************
bool
CAN_setDataBitRate(uint32_t base, uint32_t clockFreq, uint32_t bitRate, uint16_t bitTime)
{
	uint32_t brp;
	uint32_t tSeg1;
	uint32_t tSeg2;
	uint32_t sjw;
	uint32_t prescaler;
	float ftseg2 = 0.0f;
	float sampRate = 0.0f;

//	if (!CAN_isBaseValid(base))
//		return false;

	if (bitRate > 8000000U || bitRate == 0U)
		return false;

	//
	// Set the sampling rate based on the requested bit rate.
	//

	if (bitRate > 800000U)
		sampRate = 0.750f;
	else if (bitRate > 500000U)
		sampRate = 0.800f;
	else
		sampRate = 0.875f;

	// 
	//Calculate bit timing values 
	//
	brp = clockFreq / (bitRate * bitTime);
	tSeg2 = (uint32_t)(bitTime * (1.0f - sampRate) + 0.5f);
	tSeg1 = bitTime - tSeg2;

	if(tSeg2 > 4U)
		sjw = 3U;
	else
		sjw = tSeg2;

	// 
	//Adjust the timing values to fit the CAN register 
	//
	prescaler = brp - 1U;
	tSeg1 -= 2U;
	tSeg2 -= 1U;
	sjw -= 1U;

	//
	// Set the calculated timing parameters.
	//
	return CAN_setDataBitTiming(base, prescaler, tSeg1, tSeg2, sjw);
}

//*****************************************************************************
//
// CAN_setBitRateSamplePoint
//
//*****************************************************************************
bool
CAN_setBitRateSamplePoint(uint32_t base, uint32_t clockFreq,
				uint32_t bitrate, float32_t sample_point)
{
	uint32_t tmp_val;
	uint32_t bit_time;
	CAN_BitTimingParams_t configParams;

	//
	// CAN2.0 maximum of bitrate is 1Mbps.
	//
	if (bitrate > 1000000U || sample_point <= 0.0 ||
		clockFreq == 0U || bitrate == 0 || sample_point >= 1.0)
		return false;

	CAN_getBitTime(base, &configParams);

	//
	// tmp_val = bit time * prescaler.
	//
	if (CAN_isFDOpEnable(base))
		bit_time = CAN_NBTP_NTSEG1_MAX + CAN_NBTP_NTSEG2_MAX_CANFD_MODE + 3;
	else
		bit_time = CAN_NBTP_NTSEG1_MAX + CAN_NBTP_NTSEG2_MAX_CAN_MODE + 3;

	tmp_val = clockFreq / bitrate;
	configParams.nomRatePrescalar = 0;

	while (((tmp_val / (configParams.nomRatePrescalar + 1)) > bit_time) ||
		(((tmp_val / (configParams.nomRatePrescalar + 1)) * sample_point) >
		(CAN_NBTP_NTSEG1_MAX + 2U))) {
		configParams.nomRatePrescalar++;
	}

	tmp_val = tmp_val / (configParams.nomRatePrescalar + 1);

	configParams.nomTimeSeg1 = (uint8_t)(sample_point * tmp_val);
	configParams.nomTimeSeg2 = (uint8_t)(tmp_val - configParams.nomTimeSeg1);

	if (configParams.nomTimeSeg1 < configParams.nomTimeSeg2 + 2U)
		return false;

	configParams.nomTimeSeg1 -= 2U;
	configParams.nomTimeSeg2 -= 1U;

	if (configParams.nomTimeSeg2 > CAN_NBTP_NSJW_MAX)
		configParams.nomSynchJumpWidth = CAN_NBTP_NSJW_MAX;
	else
		configParams.nomSynchJumpWidth = configParams.nomTimeSeg2;

	if (configParams.nomSynchJumpWidth > 2)
		configParams.nomSynchJumpWidth = 2;

	return CAN_setBitTime(base, &configParams);
}

//*****************************************************************************
//
// CAN_setDataBitRateSamplePoint
//
//*****************************************************************************
bool
CAN_setDataBitRateSamplePoint(uint32_t base, uint32_t clockFreq,
				uint32_t bitrate, float32_t sample_point)
{
	uint32_t tmp_val;
	uint32_t bit_time;
	uint32_t bit_time_tmp;
	CAN_BitTimingParams_t configParams;


	//
	// CANFD maximum of bitrate is 4Mbps.
	//
	if (bitrate > 5000000U || sample_point <= 0.0 ||
		clockFreq == 0U || bitrate == 0 || sample_point >= 1.0)
		return false;

	CAN_getBitTime(base, &configParams);

	//
	// tmp_val = bit time * prescaler.
	//
	bit_time = CAN_DBTP_DTSEG1_MAX + CAN_DBTP_DTSEG2_MAX + 3;

	tmp_val = clockFreq / bitrate;
	configParams.dataRatePrescalar = 0;

	while (((tmp_val / (configParams.dataRatePrescalar + 1)) > bit_time) ||
		(((tmp_val / (configParams.dataRatePrescalar + 1)) * sample_point) >
		(CAN_DBTP_DTSEG1_MAX + 2U))) {
		configParams.dataRatePrescalar++;
	}

	tmp_val = tmp_val / (configParams.dataRatePrescalar + 1);
	configParams.dataTimeSeg1 = (uint8_t)(sample_point * tmp_val);
	configParams.dataTimeSeg2 = (uint8_t)(tmp_val - configParams.dataTimeSeg1);

	if (configParams.dataTimeSeg1 < configParams.dataTimeSeg2 + 2U)
		return false;

	configParams.dataTimeSeg1 -= 2U;
	configParams.dataTimeSeg2 -= 1U;

	if (configParams.dataTimeSeg2 > CAN_DBTP_DSJW_MAX)
		configParams.dataSynchJumpWidth = CAN_DBTP_DSJW_MAX;
	else
		configParams.dataSynchJumpWidth = configParams.dataTimeSeg2;

	if (configParams.dataSynchJumpWidth > 2)
		configParams.dataSynchJumpWidth = 2;

	tmp_val = (configParams.dataTimeSeg1 + 2U);

	//
	// Enable TDC mode and set TDC value.
	//
	CAN_setTDCValue(base, tmp_val);
	CAN_enableTDC(base, true);

	return CAN_setBitTime(base, &configParams);
}

//*****************************************************************************
//
// CAN_configMsgFilter
//
//*****************************************************************************
bool
CAN_configMsgFilter(uint32_t base, uint32_t filtNum, const CAN_FilterElement_t *elem)
{
	uint32_t reg_val = 0;


	if (elem == NULL || filtNum >= NUMBER_OF_ACF)
		return false;

	//
	// Select ID filter.
	//
	reg_val |= ((filtNum & (CAN_ACFCTRL_ACFADR_M >> CAN_ACFCTRL_ACFADR_S)) << CAN_ACFCTRL_ACFADR_S);

	//
	// Choose to set CAN ID filter.
	//
	reg_val &= ~CAN_ACFCTRL_SELMASK_M;
	reg_val |= (HWREG(base + CAN_O_ACFCTRL) & 0xFFFFFF00);
	HWREG(base + CAN_O_ACFCTRL) = reg_val;

	//
	// Set the CAN ID filter.
	//
	HWREG(base + CAN_O_ACF) =(elem->acode & CAN_ACF_ACODE_X_AMASK_X_M);

	//
	// Choose to set CAN ID mask filter.
	//
	reg_val |= CAN_ACFCTRL_SELMASK_M;
	HWREG(base + CAN_O_ACFCTRL) = reg_val;

	//
	// Set the CAN ID mask filter.
	//
	reg_val = (elem->amsk & CAN_ACF_ACODE_X_AMASK_X_M);

	//
	// Set the CAN ID filter frame type.
	// By default, all standard frames and extended frames are accepted.
	//
	reg_val &= ~(CAN_ACF_3_AIDEE_M | CAN_ACF_3_AIDE_M);

	//
	// Only accept standard frames.
	//
	if (elem->filerFrameType == CAN_IDTYPE_ONLY_STD)
		reg_val |= CAN_ACF_3_AIDEE_M;
	//
	// Only accept extended frames.
	//
	else if (elem->filerFrameType == CAN_IDTYPE_ONLY_EXT) {
		reg_val |= CAN_ACF_3_AIDEE_M;
		reg_val |= CAN_ACF_3_AIDE_M;
	}

	HWREG(base + CAN_O_ACF) = reg_val;

	return true;
}

//*****************************************************************************
//
// CAN_configMsgFilterEnable
//
//*****************************************************************************
bool
CAN_configMsgFilterEnable(uint32_t base, uint32_t filtNum)
{
	if (filtNum >= NUMBER_OF_ACF)
		return false;

	HWREG(base + CAN_O_ACF_EN_0) |= ((1U << filtNum) << CAN_ACF_EN_0_AE_0_S);

	return true;
}

//*****************************************************************************
//
// CAN_addMsgFilter
//
//*****************************************************************************
bool
CAN_addMsgFilter(uint32_t base, uint32_t acode, uint32_t mask, CAN_IDFilterType_t type)
{
	uint32_t reg_val;
	uint8_t i;
	uint8_t filter_number = 0xff;

	CAN_FilterElement_t elem;


	reg_val = HWREG(base + CAN_O_ACF_EN_0) & 0xFFFF0000U;

	reg_val >>= CAN_ACF_EN_0_AE_0_S;

	for (i = 0; i < NUMBER_OF_ACF; i++) {
		if (!((reg_val >> i) & 1U)) {
			filter_number = i;
			break;
		}
	}

	//
	// Check if all filter are used.
	//
	if (filter_number == 0xff)
		return false;

	elem.acode = acode;
	elem.amsk = mask;
	elem.filerFrameType = type;

	CAN_configMsgFilter(base, filter_number, &elem);

	return CAN_configMsgFilterEnable(base, filter_number);
}

//*****************************************************************************
//
// CAN_configMsgFilterDisable
//
//*****************************************************************************
bool
CAN_configMsgFilterDisable(uint32_t base, uint32_t filtNum)
{

	if (filtNum >= NUMBER_OF_ACF)
		return false;

	HWREG(base + CAN_O_ACF_EN_0) &= ~((1U << filtNum) << CAN_ACF_EN_0_AE_0_S);

	return true;
}

//*****************************************************************************
//
// setSelfACKnowledge
//
//*****************************************************************************
static inline void
setSelfACKnowledge(uint32_t base, bool enable)
{
	if (enable)
		HWREG(base + CAN_O_RCTRL) |= CAN_RCTRL_SACK_M;
	else
		HWREG(base + CAN_O_RCTRL) &= ~CAN_RCTRL_SACK_M;
}

//*****************************************************************************
//
// CAN_lpbkModeEnable
//
//*****************************************************************************
bool
CAN_lpbkModeEnable(uint32_t base, CAN_LpbkMode_t lpbkMode, bool enable)
{
	uint32_t reg_val;

	//
	// Disable loopback mode only in reset mode.
	//
	if (!enable) {
		if (CAN_isInReset(base))
			return false;
	}

	if (lpbkMode == CAN_LPBK_MODE_EXTERNAL && enable)
		//
		// Enable Self-ACKnowledge.
		//
		setSelfACKnowledge(base, true);
	else
		setSelfACKnowledge(base, false);

	reg_val = HWREG(base + CAN_O_CFG_STAT);

	if (lpbkMode == CAN_LPBK_MODE_INTERNAL) {
		if(enable) {
			reg_val &= ~CAN_CFG_STAT_LBME_M;
			reg_val |= CAN_CFG_STAT_LBMI_M;
		} else
			reg_val &= ~CAN_CFG_STAT_LBMI_M;
	} else if (lpbkMode == CAN_LPBK_MODE_EXTERNAL) {
		if(enable) {
			reg_val &= ~CAN_CFG_STAT_LBMI_M;
			reg_val |= CAN_CFG_STAT_LBME_M;
		} else
			reg_val &= ~CAN_CFG_STAT_LBME_M;
	} else
		return false;

	HWREG(base + CAN_O_CFG_STAT) = reg_val;

	return true;
}

//*****************************************************************************
//
// CAN_getErrorCount
//
//*****************************************************************************
bool
CAN_getErrorCount(uint32_t base, uint32_t *rxCount, uint32_t *txCount)
{

	if (rxCount == NULL || txCount == NULL)
		return false;

	*txCount = (HWREG(base + CAN_O_TECNT) & CAN_TECNT_TECNT_M) >>
								CAN_TECNT_TECNT_S;

	*rxCount = (HWREG(base + CAN_O_RECNT) & CAN_RECNT_RECNT_M) >>
								CAN_RECNT_RECNT_S;

	return true;
}

//*****************************************************************************
//
// CAN_getStatus
//
//*****************************************************************************
int
CAN_getStatus(uint32_t base)
{
	uint32_t reg_val;
	uint32_t status = CAN_STATUS_OK;

	//
	// Get bus error status.
	//
	reg_val = HWREG(base + CAN_O_ERRINT);

	if (reg_val & CAN_ERRINT_EWARN_M)
		status |= CAN_STATUS_EWARN;

	if (reg_val & CAN_ERRINT_EPASS_M)
		status |= CAN_STATUS_EPASS;

	if (HWREG(base + CAN_O_CFG_STAT) & CAN_CFG_STAT_BUSOFF_M)
		status |= CAN_STATUS_BUS_OFF;

	return status;
}

//*****************************************************************************
//
// CAN_getRxBufState
//
//*****************************************************************************
CAN_RxMsgBufStatus_t
CAN_getRxBufState(uint32_t base)
{

	return ((HWREG(base + CAN_O_RCTRL) & CAN_RCTRL_RSTAT_M) >> CAN_RCTRL_RSTAT_S);
}

//*****************************************************************************
//
// CAN_getTxSecondaryBufState
//
//*****************************************************************************
CAN_TxMsgBufStatus_t
CAN_getTxSecondaryBufState(uint32_t base)
{
	return ((HWREG(base + CAN_O_TCTRL) & CAN_TCTRL_TSSTAT_M) >> CAN_TCTRL_TSSTAT_S);
}

//*****************************************************************************
//
// CAN_getTxPrimaryBufState
//
//*****************************************************************************
int
CAN_getTxPrimaryBufState(uint32_t base)
{
	return !!(HWREG(base + CAN_O_TCMD) & CAN_TCMD_TPE_M);
}

//*****************************************************************************
//
// CAN_selectTxBufMode
//
//*****************************************************************************
static void
CAN_selectTxBufMode(uint32_t base, CAN_TxBufMode_t mode)
{
	if (mode == CAN_PTB_PRIORITY)
		HWREG(base + CAN_O_TCMD) &= ~CAN_TCMD_TBSEL_M;
	else
		HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TBSEL_M;
}

//*****************************************************************************
//
// CAN_selectNextSecondaryBuf
//
//*****************************************************************************
static void
CAN_selectNextSecondaryBuf(uint32_t base)
{
	HWREG(base + CAN_O_TCTRL) |= CAN_TCTRL_TSNEXT_M;
}

//*****************************************************************************
//
// CAN_writeTxMsgToSTB
//
//*****************************************************************************
bool
CAN_writeTxMsgToSTB(uint32_t base, CAN_TxMessage_t *pTxFrame)
{
	uint32_t can_id = 0;
	uint32_t can_ctrl = 0;
	int i = 0;

	if (pTxFrame == NULL)
		return false;

	//
	// Obtain the status of the secondary buffer.
	//
	if (CAN_getTxSecondaryBufState(base) == CAN_TXBUFFER_FULL)
		return false;

	//
	// Switch to STB mode.
	//
	CAN_selectTxBufMode(base, CAN_STB_SECONDARY);

#if 0
	can_id = *((uint32_t *)pTxFrame);
	can_ctrl = *((uint32_t *)pTxFrame+1);


	//
		// Copy data to the TBUF register.
		//
		HWREG(base + CAN_O_TBUF) = can_id;
	HWREG(base + CAN_O_TBUF + 4)  = can_ctrl;
	for(i = 0; i < CAN_getMessageLength(pTxFrame->dlc); i = i+4 )
	{
		HWREG(base + CAN_O_TBUF + 8 + i) = *(uint32_t*)(&(pTxFrame->data[i]));
	}

#else
	memcpy((void *)(base + CAN_O_TBUF), (void *)pTxFrame, sizeof(CAN_TxMessage_t));
#endif
	//
	// Update the secondary buffer head pointer.
	//
	CAN_selectNextSecondaryBuf(base);

	return true;
}

//*****************************************************************************
//
// CAN_writeSTB
//
//*****************************************************************************
static inline bool
CAN_writeSTB(uint32_t base, CAN_TxMessage_t *pTxFrame)
{
	uint32_t can_id = 0;
	uint32_t can_ctrl = 0;
	uint32_t i = 0;
	//
	// Obtain the status of the secondary buffer.
	//
//	if (CAN_getTxSecondaryBufState(base) == CAN_TXBUFFER_FULL)
//		return false;

	//
	// Switch to STB mode.
	//
	CAN_selectTxBufMode(base, CAN_STB_SECONDARY);

#if 0
	can_id = *((uint32_t *)pTxFrame);
	can_ctrl = *((uint32_t *)pTxFrame+1);


	//
	// Copy data to the TBUF register.
	//
	HWREG(base + CAN_O_TBUF) =  can_id;
	HWREG(base + CAN_O_TBUF+4) = can_ctrl;
	for(i = 0; i < CAN_getMessageLength(pTxFrame->dlc); i = i+4 )
	{
		HWREG(base + CAN_O_TBUF + 8 + i) = *(uint32_t*)(&(pTxFrame->data[i]));
	}
#else

	memcpy((void *)(base + CAN_O_TBUF), (void *)pTxFrame, sizeof(CAN_TxMessage_t));
#endif

	//
	// Update the secondary buffer head pointer.
	//
	CAN_selectNextSecondaryBuf(base);

	return true;
}


//*****************************************************************************
//
// CAN_writePrimaryBuf
//
//*****************************************************************************
static inline bool
CAN_writePrimaryBuf(uint32_t base, CAN_TxMessage_t *pTxFrame)
{
	uint32_t can_id = 0;
	uint32_t can_ctrl = 0;
	uint32_t i = 0;
	//
	// Switch to PBT mode.
	//
	CAN_selectTxBufMode(base, CAN_PTB_PRIORITY);

	//
	// Obtain the status of the primary buffer.
	// Check if the primary buffer is empty.
	//
	if (CAN_getTxPrimaryBufState(base) != 0)
		return false;

#if 0
	can_id = *(uint32_t*)pTxFrame;
	can_ctrl = *((uint32_t*)pTxFrame+1);

		//
		// Copy data to the TBUF register.
		//
		HWREG(base + CAN_O_TBUF) = can_id;
	HWREG(base + CAN_O_TBUF+4 ) = can_ctrl;
	for(i = 0; i < CAN_getMessageLength(pTxFrame->dlc); i = i+4 )
	{
		HWREG(base + CAN_O_TBUF + 8 + i) = *(uint32_t*)(&(pTxFrame->data[i]));
	}
#else
	memcpy((void *)(base + CAN_O_TBUF), (void *)pTxFrame, sizeof(CAN_TxMessage_t));
#endif
	return true;
}

//*****************************************************************************
//
// CAN_startTransmissionOnce
//
//*****************************************************************************
bool
CAN_startTransmissionOnce(uint32_t base)
{

	HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TSONE_M;

	return true;
}


//*****************************************************************************
//
// CAN_startTransmissionAll
//
//*****************************************************************************
bool
CAN_startTransmissionAll(uint32_t base)
{

	HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TSALL_M;

	return true;
}

//*****************************************************************************
//
// CAN_startTransmissionHighPrimaryMsg
//
//*****************************************************************************
bool
CAN_startTransmissionHighPrimaryMsg(uint32_t base)
{

	HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TSALL_M;

	return true;
}

//*****************************************************************************
//
// CAN_startTransmission
//
//*****************************************************************************
static inline void
CAN_startTransmission(uint32_t base, CAN_SendMsgMode_t mode)
{
	if (mode == CAN_TX_MODE_ALL_MSG)
		HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TSALL_M;
	else
		HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TSONE_M;
}

//*****************************************************************************
//
// CAN_startTransmissionPrimaryMsg
//
//*****************************************************************************
static inline void
CAN_startTransmissionPrimaryMsg(uint32_t base)
{
	HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TPE_M;
}

int CAN_getMessageLength(CAN_MsgDataLength_t size)
{
	if (size > CAN_DATA_LENGTH_64)
		return -1;

	return CAN_DataLengthArray[size];
}

bool CAN_transmitMsg(uint32_t base, CAN_TxMessage_t *pTxFrame)
{
	if (pTxFrame == NULL)
		return false;

	//
	// Check if the Tx buffer is full.
	//
	if (!CAN_writeSTB(base, pTxFrame))
		return false;

	//
	// Start transmission.
	//
	CAN_startTransmission(base, CAN_TX_MODE_ALL_MSG);

	return true;
}

bool CAN_transmitHighPriorityMsg(uint32_t base, CAN_TxMessage_t *pTxFrame)
{

	if (pTxFrame == NULL)
		return false;

	//
	// Fill Tx message to primary buffer.
	//
	if (!CAN_writePrimaryBuf(base, pTxFrame))
		return false;

	//
	// Start transmission message.
	//
	CAN_startTransmissionPrimaryMsg(base);

	return true;
}

bool CAN_transmitSecondaryAbort(uint32_t base)
{

	HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TSA_M;

	return true;
}

bool CAN_transmitPrimaryAbort(uint32_t base)
{

	HWREG(base + CAN_O_TCMD) |= CAN_TCMD_TPA_M;

	return true;
}

bool CAN_releaseRxBuf(uint32_t base)
{

	HWREG(base + CAN_O_RCTRL) |= CAN_RCTRL_RREL_M;

	return true;
}

bool CAN_receiveMsg(uint32_t base, CAN_RxMessage_t *pRxFrame)
{
	uint32_t can_id = 0;
	uint32_t can_ctrl = 0;
	uint32_t i = 0;
//	if (!CAN_isBaseValid(base))
//		return false;

	if (pRxFrame == NULL)
		return false;

	//
	// Check if the Rx buffer is empty.
	//
	if (CAN_getRxBufState(base) == CAN_RXBUFFER_EMPTY)
		return false;

	//
	// Copy data from the RBUF register.
	//
#if 0
	can_id = HWREG(base + CAN_O_RBUF);
	can_ctrl = HWREG(base + CAN_O_RBUF + 4);
	*((uint32_t *)pRxFrame) = can_id;
	*(((uint32_t *)pRxFrame)+1) = can_ctrl;
	for(i = 0; i < CAN_getMessageLength(pRxFrame->dlc); i = i+4 )
	{
		*(uint32_t*)(&(pRxFrame->data[i])) = HWREG(base + CAN_O_RBUF + 8 + i);
	}
	pRxFrame->timestamp = HWREG(base + CAN_O_RBUF + 72) + ((uint64_t)HWREG(base + CAN_O_RBUF + 76)<<32);
#else
	memcpy((void *)pRxFrame, (void *)(base + CAN_O_RBUF), sizeof(CAN_RxMessage_t));
#endif
	CAN_releaseRxBuf(base);

	return true;
}

bool CAN_setErrWarnLevel(uint32_t base, uint8_t level)
{
//	if (!CAN_isBaseValid(base))
//		return false;

	if (level > 15)
		return false;

	HWREG(base + CAN_O_LIMIT) |= ((level & (CAN_LIMIT_EWL_M >> CAN_LIMIT_EWL_S)) >>
									CAN_LIMIT_EWL_S);

	return true;
}

int CAN_getErrWarnLevel(uint32_t base)
{
//	if (!CAN_isBaseValid(base))
//		return -1;

	return ((HWREG(base + CAN_O_LIMIT) & CAN_LIMIT_EWL_M) >> CAN_LIMIT_EWL_S);
}

bool CAN_setRxBufAlmostFullLevel(uint32_t base, uint8_t level)
{
//	if (!CAN_isBaseValid(base))
//		return false;

	if (level > 15)
		return false;

	HWREG(base + CAN_O_LIMIT) |= ((level & (CAN_LIMIT_AFWL_M >> CAN_LIMIT_AFWL_S)) >>
									CAN_LIMIT_AFWL_S);

	return true;
}

int CAN_getRxBufAlmostFullLevel(uint32_t base)
{
//	if (!CAN_isBaseValid(base))
//		return -1;

	return ((HWREG(base + CAN_O_LIMIT) & CAN_LIMIT_AFWL_M) >> CAN_LIMIT_AFWL_S);
}

bool CAN_enableInterrupt(uint32_t base, uint32_t intFlag)
{
//	if (!CAN_isBaseValid(base))
//		return false;

	HWREG(base + CAN_O_RTIE) |= (intFlag & CAN_ALL_INT_EN_MASK);

	return true;
}

bool CAN_disableInterrupt(uint32_t base, uint32_t intFlag)
{
//	if (!CAN_isBaseValid(base))
//		return false;

	HWREG(base + CAN_O_RTIE) &= ~(intFlag & CAN_ALL_INT_EN_MASK);

	return true;
}

uint32_t CAN_getIntrStatus(uint32_t base)
{
//	if (!CAN_isBaseValid(base))
//		return 0;

	return (HWREG(base + CAN_O_RTIF) & CAN_INT_STATUS_MASK);
}

uint32_t CAN_clearIntrStatus(uint32_t base, uint32_t intFlag)
{
//	if (!CAN_isBaseValid(base))
//		return 0;

	HWREG(base + CAN_O_RTIF) |= (intFlag & CAN_INT_STATUS_MASK);

	return true;
}































