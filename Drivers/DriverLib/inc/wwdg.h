/** 
  ************************************************************************************* 
  * @file wwdg.h
  * @brief This file contains the definition of wwdg driver. 
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

#ifndef __WWDG_H
#define __WWDG_H

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

//*****************************************************************************
//
//! \addtogroup wwdg_api WWDG
//! @{
//
//*****************************************************************************

#include "hw_common.h"
#include "hw_wwdg.h"

//*****************************************************************************
//
//! Deinitializes the WWDG peripheral registers to their default reset values.
//! 
//! This function resets all WWDG control registers to their default states.
//! 
//! \return None.
//
//*****************************************************************************
void WWDG_DeInit(void);


//*****************************************************************************
//
//! Sets the prescaler value for the WWDG counter clock.
//! 
//! \param WWDG_Prescaler specifies the prescaler value. 
//! This parameter can be one of the following values:
//! - \b WWDG_Prescaler_1: WWDG counter clock = (PCLK1 / 4096)/1
//! - \b WWDG_Prescaler_2: WWDG counter clock = (PCLK1 / 4096)/2
//! - \b WWDG_Prescaler_4: WWDG counter clock = (PCLK1 / 4096)/4
//! - \b WWDG_Prescaler_8: WWDG counter clock = (PCLK1 / 4096)/8
//! 
//! This function configures the prescaler of the window watchdog timer.
//! The prescaler divides the input clock to determine the WWDG counter clock frequency.
//! 
//! \return None.
//
//*****************************************************************************
void WWDG_SetPrescaler(uint32_t base,uint32_t WWDG_Prescaler);


//*****************************************************************************
//
//! Sets the window value of the WWDG.
//! 
//! \param WindowValue specifies the window value to be compared to the counter.
//! This parameter must be a value between 0x40 and 0x7F.
//! 
//! This function configures the upper window value for the watchdog timer.
//! The counter must be reloaded only when the counter value is below the window
//! value and greater than the reset value (0x40).
//! 
//! \return None.
//
//*****************************************************************************
void WWDG_SetWindowValue(uint32_t base,uint8_t WindowValue);


//*****************************************************************************
//
//! Enables the WWDG Early Wakeup interrupt(EWI).
//! 
//! This function enables the Early Wakeup interrupt which is generated when the
//! counter reaches the value 0x40. This interrupt can be used to reload the counter
//! before it reaches the reset value (0x3F).
//! 
//! \return None.
//
//*****************************************************************************
void WWDG_EnableIT(uint32_t base);


//*****************************************************************************
//
//! Sets the WWDG counter value.
//! 
//! \param Counter specifies the watchdog counter value.
//! This parameter must be a value between 0x40 and 0x7F.
//! 
//! This function reloads the WWDG counter with the specified value.
//! The counter value must be between 0x40 and 0x7F to avoid immediate reset.
//! 
//! \return None.
//
//*****************************************************************************
void WWDG_SetCounter(uint32_t base,uint8_t Counter);


//*****************************************************************************
//
//! Enables the WWDG peripheral.
//! 
//! \param Counter specifies the initial watchdog counter value.
//! This parameter must be a value between 0x40 and 0x7F.
//! 
//! This function enables the window watchdog timer and loads the counter with
//! the specified value. Once enabled, the WWDG cannot be disabled except by a
//! system reset.
//! 
//! \return None.
//
//*****************************************************************************
void WWDG_Enable(uint32_t base,uint8_t Counter);


//*****************************************************************************
//
//! Checks whether the Early Wakeup interrupt flag is set or not.
//! 
//! This function checks the status of the Early Wakeup interrupt flag which is
//! set when the counter reaches the value 0x40.
//! 
//! \return The new state of the Early Wakeup interrupt flag (SET or RESET).
//
//*****************************************************************************
FlagStatus WWDG_GetFlagStatus(uint32_t base);


//*****************************************************************************
//
//! Clears the Early Wakeup interrupt flag.
//! 
//! This function clears the Early Wakeup interrupt flag by writing 0 to the EWIF bit.
//! 
//! \return None.
//
//*****************************************************************************
void WWDG_ClearFlag(uint32_t base);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // WWDG_H



