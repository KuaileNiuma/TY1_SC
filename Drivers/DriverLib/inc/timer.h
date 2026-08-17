/** 
  ************************************************************************************* 
  * @file timer.h
  * @brief This file contains the definition of timer driver. 
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

#ifndef __TIMERER_H__
#define __TIMERER_H__

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
#include "hw_timer.h"


struct TIM_Channel_HW_TypeDef {
    __IO uint32_t LOADCNT;      /* TIM load count register */
    __IO uint32_t CCVR;         /* TIM current value register */
    __IO uint32_t CR;             /* TIM control register */
    __IO uint32_t EOI;          /* TIM end of interrupt register */
    __IO uint32_t INTSTAT;      /* TIM interrupt status register */
};

struct TIM_Common_HW_TypeDef
{
    __IO uint32_t  TIMS_INSTAT;
    __IO uint32_t  TIMS_EOI;
    __IO uint32_t  TIMS_RAWINSTAT;
    __IO uint32_t  COMP_VERSION;
    __IO uint32_t  LOAD_COUNT2[8];
    __IO uint32_t  N_PROT_LEVEL[8];
};

typedef struct {
    struct TIM_Channel_HW_TypeDef channel[8];
    struct TIM_Common_HW_TypeDef common;
}TIMER_TypeDef;

struct timer_cfg {
    /* Running mode of timer */
    uint8_t         mode;
#define TIMER_USER_DEFINED_MODE ((uint8_t)0x02U)
#define TIMER_FREE_RUNNING_MODE ((uint8_t)0x00U)
    /* Interrupt enable or not */
    uint8_t         irq_en;
#define TIMER_INT_ENABLE        ((uint8_t)0x00U)
#define TIMER_INT_DISABLE       ((uint8_t)0x04U)
    /* The load value of timer clock counter. The range of values
     * available is 0x0 to 0xFFFFFFFF */
    uint32_t        count;
    uint8_t         on100pwm_en;
#define TIMER_ON100PWM_ENABLE       ((uint8_t)0x10U)
#define TIMER_ON100PWM_DISABLE  ((uint8_t)0x00U)
    uint8_t         pwm_en;
#define TIMER_PWM_ENABLE        ((uint8_t)0x08U)
#define TIMER_PWM_DISABLE       ((uint8_t)0x00U)
    /* The load value of timer clock counter2. The range of values
     * available is 0x0 to 0xFFFFFFFF */
    uint32_t        count2;
};

typedef struct TIMER_InitTypeDef {
    int                 channel;
    struct timer_cfg    cfg;
} TIMER_InitTypeDef;



void TIMER_init(uint32_t base , TIMER_InitTypeDef *TIMER_InitStruct);
void TIMER_start(uint32_t base , int channel);
void TIMER_stop(uint32_t base , int channel);
uint32_t TIMER_setCurrentCnt(uint32_t base , int channel);
uint32_t TIMER_getCurrentCnt(uint32_t base , int channel);
void TIMER_clearInterruptPending(uint32_t base , int channel);
FlagStatus TIMER_getInterruptStatus(uint32_t base , int channel);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__TIMERER_H__

/**
  * @}
  */


