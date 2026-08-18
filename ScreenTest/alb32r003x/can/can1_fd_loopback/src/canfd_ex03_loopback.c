/**
 *************************************************************************************
 * @file canfd_ex03_loopback.c
 * @brief This file contains the source file for example canfd_ex03_loopback.
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

#include "canfd_ex03_loopback.h"
#include <string.h>
#include "alb32r003x_evb.h"

#define Delay_value  1000000
#define CAN_CLK		 HSE_CLOCK

CAN_RxMessage_t RxMsgBuf =
{ 0 };
CAN_TxMessage_t TxMsgBuf =
{ 0 };
CAN_TxMessage_t TxMsgBuf0 =
{ 0 };

//
// Loopback receive flag (set in ISR, cleared in main)
//
volatile uint32_t can_rx_ready = 0;


//*****************************************************************************
//
// canISR
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
        // Receive CAN message
        //
        CAN_receiveMsg(myCAN_BASE, &RxMsgBuf);
        can_rx_ready = 1;
    }
    //
    // Check if Rx buffer is empty before clearing interrupt
    // If the Rx buffer is not empty, do not clear the receive interrupt
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
    // Configure CAN FD mode parameters
    //
    initParams.fdMode = true;
    initParams.brsEnable = true;
    initParams.fdFrame = CAN_FD_ISO_11898_1;
    initParams.listenOnlyEnable = false;
    initParams.txbmode = CAN_TS_MODE_PRIORITY;
    initParams.timestamp = CAN_TIMESTAMP_EOF;
    //
    // Configure filter to accept all CAN ID frames
    //
    stdFiltelem.acode = 0xc0;
    stdFiltelem.amsk = 0x1fffffff;
    stdFiltelem.filerFrameType = CAN_IDTYPE_BOTH_STD_EXT;
    //
    // Initialize CAN module
    //
    if (!CAN_initModule(myCAN_BASE))
        while (1);
    //
    // Configure CAN basic functions
    //
    if (!CAN_initConfig(myCAN_BASE, &initParams))
        while (1);
    //
    // Set arbitration segment bit rate (1 Mbps, 80% sampling point)
    //
    if (!CAN_setBitRateSamplePoint(myCAN_BASE, CAN_CLK, 1U * 1000 * 1000, 0.8))
        while (1);
    //
    // Set data segment bit rate (4 Mbps, 80% sampling point)
    //
    if (!CAN_setDataBitRateSamplePoint(myCAN_BASE, CAN_CLK, 4U * 1000 * 1000,
            0.8))
        while (1);
    //
    // Configure CAN ID acceptance filter 0
    //
    if (!CAN_configMsgFilter(myCAN_BASE, 0, &stdFiltelem))
        while (1);
    //
    // Enable CAN ID acceptance filter 0
    //
    if (!CAN_configMsgFilterEnable(myCAN_BASE, 0))
        while (1);
    //
    // Start CAN module
    //
    if (!CAN_startModule(myCAN_BASE))
        while (1);
    //
    // Enable auto retransmission
    //
    if (!CAN_setAutoRetransmission(myCAN_BASE, true))
        while (1);
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
    printf("CANFD EX03 LOOPBACK.\r\n");
    //
    // Disable interrupts before initialization
    //
    CPU_disableIrq();
    //
    // Configure CAN GPIO pins
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_GPIOA);
    GPIO_setPinConfig(myCAN_RX_PIN);
    GPIO_setPinConfig(myCAN_TX_PIN);
    //
    // Initialize CAN controller
    //
    can_ctrl_init();
    //
    // Enable interrupts after initialization
    //
    CPU_enableIrq();
    //
    // Configure CAN FD message parameters
    //
    TxMsgBuf0.dlc = CAN_DATA_LENGTH_64;
    TxMsgBuf0.id = 0xc0;
    TxMsgBuf0.fdf = 1;
    TxMsgBuf0.brs = 1;
    //
    // Initialize message data with incremental values
    //
    for (i = 0; i < CAN_getMessageLength(TxMsgBuf0.dlc); i++)
    {
        TxMsgBuf0.data[i] = i;
    }
    printf("CANFD loopback test: send/verify 64 frames...\r\n");
    //
    // Run 64 loopback groups: send a CAN FD frame, then verify the received data
    //
    for (i = 0; i < 64; i++)
    {
        uint32_t j;
        uint32_t timeout = 0xFFFFFF;
        uint32_t len = CAN_getMessageLength(TxMsgBuf0.dlc);

        //
        // Transmit CAN FD message
        //
        CAN_transmitHighPriorityMsg(myCAN_BASE, &TxMsgBuf0);
        //
        // Wait for the loopback frame (with timeout)
        //
        while (!can_rx_ready && timeout--)
            ;
        if (!can_rx_ready)
        {
            printf("CANFD loopback FAIL: no response at frame %u\r\n", (unsigned int)i);
            return 1;
        }
        can_rx_ready = 0;
        //
        // Print sent and received data
        //
        printf("frame %u: sent=", (unsigned int)i);
        for (j = 0; j < len; j++)
            printf("%02X ", (unsigned int)TxMsgBuf0.data[j]);
        printf(" recv=");
        for (j = 0; j < len; j++)
            printf("%02X ", (unsigned int)RxMsgBuf.data[j]);
        printf("\r\n");
        //
        // Verify received values against transmitted values
        //
        if ((RxMsgBuf.id != TxMsgBuf0.id) ||
            (CAN_getMessageLength(RxMsgBuf.dlc) != CAN_getMessageLength(TxMsgBuf0.dlc)) ||
            (memcmp(RxMsgBuf.data, TxMsgBuf0.data, CAN_getMessageLength(TxMsgBuf0.dlc)) != 0))
        {
            printf("CANFD loopback FAIL: data mismatch at frame %u\r\n", (unsigned int)i);
            return 1;
        }
    }
    //
    // All 64 groups verified OK
    //
    printf("CANFD loopback PASS: 64 frames verified\r\n");
    return 0;   //!< Return 0 means the test passed
}

