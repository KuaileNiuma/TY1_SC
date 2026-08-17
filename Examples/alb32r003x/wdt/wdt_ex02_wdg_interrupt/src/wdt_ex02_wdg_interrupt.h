/**
 *************************************************************************************
 * @file wdt_ex02_wdg_interrupt.h
 * @brief This file contains the header file for example wdt_ex02_wdg_interrupt.
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

#ifndef WDT_EX02_WDG_IRQ_H
#define WDT_EX02_WDG_IRQ_H

#include "device.h"
#include "wdt.h"

//*****************************************************************************
//
// External Variables
//
//*****************************************************************************
extern WDT_InitTypeDef myConfig;      //!< WDT configuration structure
extern WDT_TypeDef* mywdt_intstance;  //!< WDT instance pointer
extern uint32_t test_count;           //!< Test counter for WDT interrupts


//*****************************************************************************
//
// WDT initialization function
//
//*****************************************************************************
void mywdt_init(void);

//*****************************************************************************
//
// WDT watchdog test function
//
//*****************************************************************************
void wdt_weed_test(void);

//*****************************************************************************
//
// CPU delay function
//
//*****************************************************************************
void cpu_delay(volatile unsigned int delay_ticks);

//*****************************************************************************
//
// Interrupt initialization function
//
//*****************************************************************************
void INTERRUPT_init(void);

#endif /* WDT_EX02_WDG_IRQ_H */
