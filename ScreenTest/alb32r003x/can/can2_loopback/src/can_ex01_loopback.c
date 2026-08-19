/**
 *************************************************************************************
 * @file can_ex01_loopback.c
 * @brief This file contains the source file for example can_ex01_loopback.
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

#include "can_ex01_loopback.h"
#include <string.h>
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"

#define Delay_value  100000
#define CAN_CLK		 HSE_CLOCK

CAN_TxMessage_t TxMsgBuf =
{ 0 };
CAN_RxMessage_t RxMsgBuf =
{ 0 };

//
// Loopback receive flag (set in ISR, cleared in main)
//
volatile uint32_t can_rx_ready = 0;

//*****************************************************************************
//
// can_irq_handler
//
//*****************************************************************************
__INTERRUPT void canISR(void)
{
	uint32_t status;
	//
	// Get CAN interrupt status
	//
	status = CAN_getIntrStatus(myCAN_BASE);
	//
	// Check if receive interrupt is set
	//
	if (status & CAN_RTIF_RIF_M)
	{
		//
		// Receive CAN message (data is kept for verification in main loop)
		//
		CAN_receiveMsg(myCAN_BASE, &RxMsgBuf);
		can_rx_ready = 1;
	}
	//
	// Check if Rx buffer is empty before clearing interrupt
	//
	if (CAN_getRxBufState(myCAN_BASE) == CAN_RXBUFFER_EMPTY)
		CAN_clearIntrStatus(myCAN_BASE, CAN_RTIF_RIF_M);
}

//*****************************************************************************
//
// can_config
//
//*****************************************************************************
void can_config(void)
{
	CAN_InitParams_t initParams =
	{ 0 };
	CAN_FilterElement_t stdFiltelem =
	{ 0 };
	//
	// Configure CAN parameters for standard mode
	//
	initParams.fdMode = false;
	initParams.txbmode = CAN_TS_MODE_PRIORITY;
	initParams.timestamp = CAN_TIMESTAMP_EOF;
	//
	// Configure filter to accept specific CAN ID frames
	//
	stdFiltelem.acode = 0xc0;
	stdFiltelem.amsk = 0x1fffffff;
	stdFiltelem.filerFrameType = CAN_IDTYPE_BOTH_STD_EXT;
	//
	// Initialize CAN module
	//
	if (!CAN_initModule(myCAN_BASE))
		while (1)
			;
	//
	// Configure CAN basic functions
	//
	if (!CAN_initConfig(myCAN_BASE, &initParams))
		while (1)
			;
	//
	// Set arbitration segment bit rate (1 Mbps, 80% sampling point)
	//
	if (!CAN_setBitRateSamplePoint(myCAN_BASE, CAN_CLK, 1U * 1000 * 1000, 0.8))
		while (1)
			;
	//
	// Configure CAN ID acceptance filter 0
	//
	if (!CAN_configMsgFilter(myCAN_BASE, 0, &stdFiltelem))
		while (1)
			;
	//
	// Enable CAN ID acceptance filter 0
	//
	if (!CAN_configMsgFilterEnable(myCAN_BASE, 0))
		while (1)
			;
	//
	// Start CAN module
	//
	if (!CAN_startModule(myCAN_BASE))
		while (1)
			;
	//
	// Enable CAN loopback mode
	//
	if (!CAN_lpbkModeEnable(myCAN_BASE, CAN_LPBK_MODE_INTERNAL, true))
		while (1)
			;
}

//*****************************************************************************
//
// can_ctrl_init
//
//*****************************************************************************
void can_ctrl_init(void)
{
	//
	// Enable CAN clock
	//
	RCC_selCANFDClock(HSE_CLK);
	SysCtl_enablePeripheral(myCAN_CLK_EN);
	//
	// Configure CAN parameters
	//
	can_config();
	//
	// Register and configure interrupt handler
	//
	Interrupt_register(myCAN_IRQn, canISR);
	Interrupt_setPriority(myCAN_IRQn, 0, 0);
	Interrupt_enable(myCAN_IRQn);
	//
	// Enable CAN receive interrupt
	//
	CAN_enableInterrupt(myCAN_BASE, CAN_RTIE_RIE_M);
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
	uint32_t i;
	alb32r003x_evb_init();
    printf("CAN EX01 LOOPBACK.\r\n");
	//
	// Disable interrupts before initialization
	//
	CPU_disableIrq();
	//
	// Initialize CAN controller
	//
	can_ctrl_init();
	//
	// Enable interrupts after initialization
	//
	CPU_enableIrq();

	//
	// Configure CAN transmit message buffer
	//
	TxMsgBuf.dlc = CAN_DATA_LENGTH_8;
	TxMsgBuf.id = 0xc0;
	//
	// Initialize message data
	//
	for (i = 0; i < CAN_getMessageLength(TxMsgBuf.dlc); i++)
	{
		TxMsgBuf.data[i] = i;
	}
	printf("CAN loopback test: send/verify 64 frames...\r\n");
	//
	// Run 64 loopback groups: send a frame, then verify the received data
	//
	for (i = 0; i < 64; i++)
	{
		uint32_t j;
		uint32_t timeout = 0xFFFFFF;
		uint32_t len = CAN_getMessageLength(TxMsgBuf.dlc);

		//
		// Transmit CAN message
		//
		CAN_transmitHighPriorityMsg(myCAN_BASE, &TxMsgBuf);
		//
		// Wait for the loopback frame (with timeout)
		//
		while (!can_rx_ready && timeout--)
			;
		if (!can_rx_ready)
		{
			printf("CAN loopback FAIL: no response at frame %u\r\n", (unsigned int)i);
			return SC_FAIL;
		}
		can_rx_ready = 0;
		//
		// Print sent and received data
		//
		printf("frame %u: sent=", (unsigned int)i);
		for (j = 0; j < len; j++)
			printf("%02X ", (unsigned int)TxMsgBuf.data[j]);
		printf(" recv=");
		for (j = 0; j < len; j++)
			printf("%02X ", (unsigned int)RxMsgBuf.data[j]);
		printf("\r\n");
		//
		// Verify received values against transmitted values
		//
		if ((RxMsgBuf.id != TxMsgBuf.id) ||
			(CAN_getMessageLength(RxMsgBuf.dlc) != CAN_getMessageLength(TxMsgBuf.dlc)) ||
			(memcmp(RxMsgBuf.data, TxMsgBuf.data, CAN_getMessageLength(TxMsgBuf.dlc)) != 0))
		{
			printf("CAN loopback FAIL: data mismatch at frame %u\r\n", (unsigned int)i);
			return SC_FAIL;
		}
	}
	//
	// All 64 groups verified OK
	//
	printf("CAN loopback PASS: 64 frames verified\r\n");
	return SC_PASS;   //!< Test passed
}
