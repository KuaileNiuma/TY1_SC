/** 
  ************************************************************************************* 
  * @file wdt.h 
  * @brief This file contains the definition of wdt driver. 
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

#ifndef __AC1005_HAL_WDT_H
#define __AC1005_HAL_WDT_H

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
//! \addtogroup wdt_api WDT
//! @{
//
//*****************************************************************************

#include "hw_common.h"
#include "hw_wdt.h"


//*****************************************************************************
//
//! Initializes the Watchdog Timer with the specified configuration.
//! 
//! \param Init is a pointer to a WDT_InitTypeDef structure that contains
//!        the configuration information for the Watchdog Timer.
//! 
//! This function configures the Watchdog Timer based on the parameters
//! provided in the Init structure. It sets up the timeout period, reset mode,
//! and other relevant settings for the Watchdog Timer operation.
//! 
//! \return None.
//
//*****************************************************************************
void WDT_init(uint32_t base,WDT_InitTypeDef* Init);


//*****************************************************************************
//
//! Restarts the Watchdog Timer counter.
//! 
//! This function restarts the Watchdog Timer counter by writing the specific
//! restart value (0x76) to the Counter Restart Register (CRR). As a safety
//! feature to prevent accidental restarts, only this specific value is accepted.
//! A restart also clears the WDT interrupt.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void WDT_feed(uint32_t base)
{
	//
	// This register is used to restart the WDT counter.
	// As a safety feature to prevent accidental restarts, the value 0x76 must be written.
	// A restart also clears the WDT interrupt.
	//
	HWREG(base + WDT_O_CRR) = WDT_CRR_RESTART;
}

//*****************************************************************************
//
//! Clears the Watchdog Timer interrupt flag.
//! 
//! This function clears the Watchdog Timer interrupt flag by accessing
//! the End Of Interrupt (EOI) register. This is typically done after
//! handling the interrupt to acknowledge that the interrupt has been processed.
//! 
//! \return None.
//
//*****************************************************************************
static inline void WDT_clearInterruptFlag(uint32_t base)
{
	uint32_t reg;
	reg = HWREG(base + WDT_O_EOI);
}

//*****************************************************************************
//
//  @fn       WDT_getInterruptFlag
//  @brief    Gets the interrupt flag status of the Watchdog Timer
//  @return   uint32_t: The interrupt flag status of the Watchdog Timer
//  @details  This function reads the status register of the Watchdog Timer and
//            returns its value, which indicates the interrupt flag status. A non-zero
//            return value typically indicates that an interrupt has been generated.
//
//*****************************************************************************
static inline uint32_t WDT_getInterruptFlag(uint32_t base)
{
	uint32_t flag = 0;
	flag = HWREG(base + WDT_O_STAT);
	return flag;
}


//*****************************************************************************
//
//! Gets the current value of the Watchdog Timer's internal counter.
//! 
//! This function reads the Current Counter Value Register (CCVR) and returns
//! the current value of the Watchdog Timer's internal counter. This can be
//! used to monitor the remaining time before a timeout occurs.
//! 
//! \return uint32_t: The current value of the Watchdog Timer's internal counter.
//
//*****************************************************************************
static inline uint32_t WDT_get_curval(uint32_t base)
{
	uint32_t curVal;
	// This register, when read, is the current value of the internal counter.
    curVal =HWREG(base + WDT_O_CCVR);
    return curVal ;
}


//*****************************************************************************
//
//! Disables the Watchdog Timer.
//! 
//! This function disables the Watchdog Timer by clearing the enable bit in
//! the Control Register (CR). Note that to prevent a software bug from
//! disabling the Watchdog Timer, once this bit has been enabled, it can be
//! cleared only by a system reset.
//! 
//! \return None.
//
//*****************************************************************************
static inline void WDT_disable(uint32_t base)
{

  //
	// To prevent a software bug from disabling the DW_apb_wdt, once this bit has been enabled, it can be cleared only by a system reset.
  //
	HWREG(base + WDT_O_CR) &= ~WDT_CR_ENABLE;
  
}


//*****************************************************************************
//
//! Enables the Watchdog Timer.
//! 
//! This function enables the Watchdog Timer by setting the enable bit in
//! the Control Register (CR). Once enabled, the Watchdog Timer will start
//! counting down from the configured timeout value.
//! 
//! \return None.
//
//*****************************************************************************
static inline void WDT_enable(uint32_t base)
{
	HWREG(base + WDT_O_CR) |= WDT_CR_ENABLE;
}


//*****************************************************************************
//
//! Initializes the Watchdog Timer with the specified configuration.
//! 
//! \param Init is a pointer to a WDT_InitTypeDef structure that contains
//!        the configuration information for the Watchdog Timer.
//! 
//! This function configures the Watchdog Timer based on the parameters
//! provided in the Init structure. It sets up the timeout period, reset mode,
//! and other relevant settings for the Watchdog Timer operation.
//! 
//! \return None.
//
//*****************************************************************************
extern void WDT_init(uint32_t base,WDT_InitTypeDef* Init);


//*****************************************************************************
//
//! Starts the Watchdog Timer counter.
//! 
//! This function starts the Watchdog Timer counter, beginning the countdown
//! based on the configured timeout period. Once started, the Watchdog Timer
//! will generate an interrupt or reset the system if not fed before the
//! timeout period expires.
//! 
//! \return None.
//
//*****************************************************************************
extern void WDT_start(uint32_t base);


//*****************************************************************************
//
//! Stops the Watchdog Timer counter.
//! 
//! This function stops the Watchdog Timer counter, preventing it from
//! generating an interrupt or resetting the system. This should be used
//! carefully as it disables the watchdog protection.
//! 
//! \return None.
//
//*****************************************************************************
extern void WDT_stop(uint32_t base);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // WDT_H


