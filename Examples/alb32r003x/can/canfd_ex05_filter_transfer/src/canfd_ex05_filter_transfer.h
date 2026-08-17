/**
 *************************************************************************************
 * @file canfd_ex05_filter_transfer.h
 * @brief This file contains the header file for example canfd_ex05_filter_transfer.
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

#ifndef __CAN_EX05_FILTER_TRANSFER_H
#define __CAN_EX05_FILTER_TRANSFER_H

#include "device.h"

#define myCAN_BASE	CANFD1_BASE

#if (myCAN_BASE == CANFD1_BASE)
#define myCAN_RX_PIN	GPIO_5_CANA_RX
#define myCAN_TX_PIN	GPIO_4_CANA_TX
#define myCAN_CLK_EN	SYSCTL_PERIPH_CLK_CANFD1
#define myCAN_IRQn      CANFD1_IRQn

#elif	(myCAN_BASE == CANFD2_BASE)
#define myCAN_RX_PIN	GPIO_5_CANB_RX
#define myCAN_TX_PIN	GPIO_4_CANB_TX
#define myCAN_CLK_EN	SYSCTL_PERIPH_CLK_CANFD2
#define myCAN_IRQn      CANFD2_IRQn


#endif

void can_ctrl_init(void);

#endif
