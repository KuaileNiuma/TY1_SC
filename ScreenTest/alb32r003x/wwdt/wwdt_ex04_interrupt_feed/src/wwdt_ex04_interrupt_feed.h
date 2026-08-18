/**
 *************************************************************************************
 * @file wwdt_ex04_interrupt_feed.h
 * @brief This file contains the header file for example wwdt_ex04_interrupt_feed.
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

#ifndef WWDT_EX04_IRQ_FEED_H_
#define WWDT_EX04_IRQ_FEED_H_

#include "device.h"
#include "wwdg.h"

//*****************************************************************************
//
// Structure Definitions
//
//*****************************************************************************

//*****************************************************************************
//
// WWDT configuration parameters structure
//
//*****************************************************************************
typedef struct {
    uint32_t WWDG_Prescaler;   //!< WWDT prescaler value
    uint8_t timeVal;           //!< WWDT counter value
    uint8_t windowVal;         //!< WWDT window value
} wwdg_param_t;

//*****************************************************************************
//
// External Variables
//
//*****************************************************************************
extern uint32_t wwdgIrqCount;   //!< WWDT interrupt counter

//*****************************************************************************
//
// Initializes the Window Watchdog Timer
// 
//*****************************************************************************
void my_wwdt_init(wwdg_param_t wwdg_params);

//*****************************************************************************
//
// Performs WWDT system reset test
// 
//*****************************************************************************
void wwdt_system_reset_test(void);

#endif /* WWDT_EX04_IRQ_FEED_H_ */
