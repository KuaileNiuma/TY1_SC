/**
 *************************************************************************************
 * @file wwdg.c
 * @brief This file implements the function of wwdg driver.
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
 
#include "wwdg.h"

//*****************************************************************************
//
// WWDG registers bit mask
//
//*****************************************************************************
#define CR_WDGA_Set       ((uint32_t)0x00000080)     //!< WWDG Activation Bit Mask
#define CFR_WDGTB_Mask    ((uint32_t)0xFFFFFE7F)     //!< WWDG Timer Base Mask
#define CFR_W_Mask        ((uint32_t)0xFFFFFF80)     //!< WWDG Window Value Mask
#define BIT_Mask          ((uint8_t)0x7F)            //!< Bit Mask


//*****************************************************************************
//
// WWDG_DeInit
//
//*****************************************************************************
void WWDG_DeInit(void)
{
//  RCC_APB1PeriphResetCmd(RCC_APB1Periph_WWDG, ENABLE);
//  RCC_APB1PeriphResetCmd(RCC_APB1Periph_WWDG, DISABLE);
}

//*****************************************************************************
//
// WWDG_SetPrescaler
//
//*****************************************************************************
void WWDG_SetPrescaler(uint32_t base,uint32_t WWDG_Prescaler)
{
  uint32_t tmpreg = 0;
  //
  // Clear WDGTB[1:0] bits
  //
  tmpreg = HWREG(base+WWDG_O_CFR) & CFR_WDGTB_Mask;
  //
  // Set WDGTB[1:0] bits according to WWDG_Prescaler value
  //
  tmpreg |= WWDG_Prescaler;
  //
  // Store the new value
  //
  HWREG(base+WWDG_O_CFR) = tmpreg;
}

//*****************************************************************************
//
// WWDG_SetWindowValue
//
//*****************************************************************************
void WWDG_SetWindowValue(uint32_t base,uint8_t WindowValue)
{
  __IO uint32_t tmpreg = 0;
  //
  // Clear W[6:0] bits
  //
  tmpreg = HWREG(base+WWDG_O_CFR) & CFR_W_Mask;

  //
  // Set W[6:0] bits according to WindowValue value
  //
  tmpreg |= WindowValue & (uint32_t) BIT_Mask;

  //
  // Store the new value
  //
  HWREG(base+WWDG_O_CFR) = tmpreg;
}

//*****************************************************************************
//
// WWDG_EnableIT
//
//*****************************************************************************
void WWDG_EnableIT(uint32_t base)
{
	HWREG(base+WWDG_O_CFR) |= WWDG_CFR_EWI;
}

//*****************************************************************************
//
// WWDG_SetCounter
//
//*****************************************************************************
void WWDG_SetCounter(uint32_t base,uint8_t Counter)
{
  //
  // Write to T[6:0] bits to configure the counter value, no need to do
  // a read-modify-write; writing a 0 to WDGA bit does nothing
  //
	HWREG(base+WWDG_O_CR) = Counter & BIT_Mask;
}

//*****************************************************************************
//
// WWDG_Enable
//
//*****************************************************************************
void WWDG_Enable(uint32_t base,uint8_t Counter)
{
	HWREG(base+WWDG_O_CR) = CR_WDGA_Set | Counter;
}

//*****************************************************************************
//
// WWDG_GetFlagStatus
//
//*****************************************************************************
FlagStatus WWDG_GetFlagStatus(uint32_t base)
{
  return (FlagStatus)HWREG(base+WWDG_O_SR);
}

//*****************************************************************************
//
// WWDG_ClearFlag
//
//*****************************************************************************
void WWDG_ClearFlag(uint32_t base)
{
	HWREG(base+WWDG_O_SR) = (uint32_t)RESET;
}

