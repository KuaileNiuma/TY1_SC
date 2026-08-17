/**
 *************************************************************************************
 * @file hw_i2c.h
 * @brief This file contains the definition of hw_i2c driver.
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

#ifndef __HW_TIMER_H
#define __HW_TIMER_H

#define TIMER_CHANNEL_NUM           (2)
#define TIMER_CHANNEL1              (0x00U)
#define TIMER_CHANNEL2              (0x01U)

#define TIMERx_O_LCR(N)             (0x00 + N*0x14)
#define TIMERx_O_CVR(N)             (0x04 + N*0x14)
#define TIMERx_O_CR(N)              (0x08 + N*0x14)
#define TIMERx_O_EOI(N)             (0x0C + N*0x14)
#define TIMERx_O_ISR(N)             (0x10 + N*0x14)
#define TIMERS_O_ISR                (0xA0)
#define TIMERS_O_EOI                (0xA4)
#define TIMERS_O_RISR               (0xA8)
#define TIMERS_O_VER                (0xAC)
#define TIMERx_O_LCR2(N)            (0xB0 + N*0x14)
#define TIMERx_O_PLR(N)             (0xD0 + N*0x14)


#define IS_TIMER_ALL_PERIPH(PERIPH) (((PERIPH) == TIMER1) || \
                                     ((PERIPH) == TIMER2) || \
                                     ((PERIPH) == TIMER3) || \
                                     ((PERIPH) == TIMER4))

#define TIMER_CR_ENABLE             ((uint32_t)0x01U)
#define TIMER_CR_MODE               ((uint32_t)0x02U)
#define TIMER_CR_INT_MASK           ((uint32_t)0x04U)
#define TIMER_ON100PWM_MODE         ((uint32_t)0x10U)
#define TIMER_PWM_MODE              ((uint32_t)0x08U)

#endif
