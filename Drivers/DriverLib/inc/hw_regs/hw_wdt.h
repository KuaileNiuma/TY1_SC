/**
 *************************************************************************************
 * @file hw_wdt.h
 * @brief This file contains the definition of hw_uart driver.
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

#ifndef _HW_WDT_H
#define _HW_WDT_H

//*****************************************************************************
//
// WDT Register Structure
//
//*****************************************************************************
typedef struct {
    __IOM uint32_t     CR;          //!< WDT Control Register (R/W, Offset: 0x000)
    __IOM uint32_t     TORR;        //!< WDT Timeout Range Register (R/W, Offset: 0x004)
    __IM  uint32_t     CCVR;        //!< WDT Current Counter Value Register (R, Offset: 0x008)
    __OM  uint32_t     CRR;         //!< WDT Count Restart Register (W, Offset: 0x00C)
    __IM  uint32_t     STAT;        //!< WDT Interrupt Status Register (R, Offset: 0x010)
    __IM  uint32_t     EOI;         //!< WDT Interrupt Clear Register (R, Offset: 0x014)
}WDT_TypeDef;

#define WDT_O_CR		(0x00U)
#define WDT_O_TORR		(0x04U)
#define WDT_O_CCVR		(0x08U)
#define WDT_O_CRR		(0x0CU)
#define WDT_O_STAT		(0x10U)
#define WDT_O_EOI		(0x14U)



//*****************************************************************************
//
// WDT_CR Register Bit Definitions
//
//*****************************************************************************
#define WDT_CR_EN_S                   (0UL)           //!< Enable Position
#define WDT_CR_EN_M                   (0x1UL)         //!< Enable Mask
#define WDT_CR_ENABLE                 WDT_CR_EN_M   //!< Enable
#define WDT_CR_DISABLE                (0x0UL)         //!< Disable

#define WDT_CR_RMOD_S                 (1UL)           //!< Reset Mode Position
#define WDT_CR_RMOD_M                 (0x2UL)         //!< Reset Mode Mask
#define WDT_CR_RST                    (0x0UL)         //!< Reset Only
#define WDT_CR_IRQRST                 WDT_CR_RMOD_M //!< Interrupt and Reset

#define WDT_CR_RPL_S                (2UL)           //!< Reset Pulse Length Position
#define WDT_CR_RPL_M                (0x1CUL)        //!< Reset Pulse Length Mask
#define WDT_CR_RPL_2CYCLES            (0x00UL)        //!< 2 Clock Cycles
#define WDT_CR_RPL_4CYCLES            (0x04UL)        //!< 4 Clock Cycles
#define WDT_CR_RPL_8CYCLES            (0x08UL)        //!< 8 Clock Cycles
#define WDT_CR_RPL_16CYCLES           (0x0CUL)        //!< 16 Clock Cycles
#define WDT_CR_RPL_32CYCLES           (0x10UL)        //!< 32 Clock Cycles
#define WDT_CR_RPL_64CYCLES           (0x14UL)        //!< 64 Clock Cycles
#define WDT_CR_RPL_128CYCLES          (0x18UL)        //!< 128 Clock Cycles
#define WDT_CR_RPL_256CYCLES          (0x1CUL)        //!< 256 Clock Cycles


//*****************************************************************************
//
// WDT_TORR Register Bit Definitions
//
//*****************************************************************************
#define WDT_TORR_TOP_S             	  (0UL)           //!< Timeout Period Position
#define WDT_TORR_TOP_M	              (0xFUL)         //!< Timeout Period Mask
#define WDT_TORR_TOP_H10000           (0x0UL)         //!< 10000 Clock Cycles
#define WDT_TORR_TOP_H20000           (0x1UL)         //!< 20000 Clock Cycles
#define WDT_TORR_TOP_H40000           (0x2UL)         //!< 40000 Clock Cycles
#define WDT_TORR_TOP_H80000           (0x3UL)         //!< 80000 Clock Cycles
#define WDT_TORR_TOP_H100000          (0x4UL)         //!< 100000 Clock Cycles
#define WDT_TORR_TOP_H200000          (0x5UL)         //!< 200000 Clock Cycles
#define WDT_TORR_TOP_H400000          (0x6UL)         //!< 400000 Clock Cycles
#define WDT_TORR_TOP_H800000          (0x7UL)         //!< 800000 Clock Cycles
#define WDT_TORR_TOP_H1000000         (0x8UL)         //!< 1000000 Clock Cycles
#define WDT_TORR_TOP_H2000000         (0x9UL)         //!< 2000000 Clock Cycles
#define WDT_TORR_TOP_H4000000         (0xAUL)         //!< 4000000 Clock Cycles
#define WDT_TORR_TOP_H8000000         (0xBUL)         //!< 8000000 Clock Cycles
#define WDT_TORR_TOP_H10000000        (0xCUL)         //!< 10000000 Clock Cycles
#define WDT_TORR_TOP_H20000000        (0xDUL)         //!< 20000000 Clock Cycles
#define WDT_TORR_TOP_H40000000        (0xEUL)         //!< 40000000 Clock Cycles
#define WDT_TORR_TOP_H80000000        (0xFUL)         //!< 80000000 Clock Cycles


//*****************************************************************************
//
// WDT_CRR Register Bit Definitions
//
//*****************************************************************************
#define WDT_CRR_RESTART_S           (0UL)           //!< Restart Position
#define WDT_CRR_RESTART_M           (0xFFUL)        //!< Restart Mask
#define WDT_CRR_RESTART               (0x76UL)        //!< Restart Key


//*****************************************************************************
//
// WDT_STAT Register Bit Definitions
//
//*****************************************************************************
#define WDT_STAT_IS_S               (0UL)           //!< Interrupt Status Position
#define WDT_STAT_IS_M               (0x1UL)         //!< Interrupt Status Mask


//*****************************************************************************
//
// WDT_EOI Register Bit Definitions
//
//*****************************************************************************
#define WDT_EOI_IC_S                (0UL)           //!< Interrupt Clear Position
#define WDT_EOI_IC_M                (0x1UL)         //!< Interrupt Clear Mask


//*****************************************************************************
//
// WDT Initialization Structure
//
//*****************************************************************************
typedef struct
{
  uint32_t        TOP;       //!< WDT Timeout Period, See WDT_TIMEOUTPERIOD_* definitions
  uint32_t        RMOD;      //!< WDT Run Mode, See WDT_RMODE_* definitions
  uint32_t        RPL;       //!< WDT Reset Pulse Length, See WDT_RPL_* definitions
}WDT_InitTypeDef;



//*****************************************************************************
//
// WDT Time Out Period Cycle Number definition
//
//*****************************************************************************
#define WDT_TIMEOUTPERIOD_H10000           WDT_TORR_TOP_H10000         //!< 10000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H20000           WDT_TORR_TOP_H20000         //!< 20000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H40000           WDT_TORR_TOP_H40000         //!< 40000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H80000           WDT_TORR_TOP_H80000         //!< 80000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H100000          WDT_TORR_TOP_H100000        //!< 100000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H200000          WDT_TORR_TOP_H200000        //!< 200000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H400000          WDT_TORR_TOP_H400000        //!< 400000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H800000          WDT_TORR_TOP_H800000        //!< 800000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H1000000         WDT_TORR_TOP_H1000000       //!< 1000000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H2000000         WDT_TORR_TOP_H2000000       //!< 2000000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H4000000         WDT_TORR_TOP_H4000000       //!< 4000000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H8000000         WDT_TORR_TOP_H8000000       //!< 8000000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H10000000        WDT_TORR_TOP_H10000000      //!< 10000000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H20000000        WDT_TORR_TOP_H20000000      //!< 20000000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H40000000        WDT_TORR_TOP_H40000000      //!< 40000000 Clock Cycles
#define WDT_TIMEOUTPERIOD_H80000000        WDT_TORR_TOP_H80000000      //!< 80000000 Clock Cycles

//*****************************************************************************
//
// WDT Run Mode definition
//
//*****************************************************************************
#define WDT_RMODE_RST              WDT_CR_RST            //!< Reset Only Mode
#define WDT_RMODE_IRQRST           WDT_CR_IRQRST         //!< Interrupt and Reset Mode

//*****************************************************************************
//
// WDT Reset Pull Level Cycle Number definition
//
//*****************************************************************************
#define WDT_RPL_2CYCLES                    WDT_CR_RPL_2CYCLES          //!< 2 Clock Cycles
#define WDT_RPL_4CYCLES                    WDT_CR_RPL_4CYCLES          //!< 4 Clock Cycles
#define WDT_RPL_8CYCLES                    WDT_CR_RPL_8CYCLES          //!< 8 Clock Cycles
#define WDT_RPL_16CYCLES                   WDT_CR_RPL_16CYCLES         //!< 16 Clock Cycles
#define WDT_RPL_32CYCLES                   WDT_CR_RPL_32CYCLES         //!< 32 Clock Cycles
#define WDT_RPL_64CYCLES                   WDT_CR_RPL_64CYCLES         //!< 64 Clock Cycles
#define WDT_RPL_128CYCLES                  WDT_CR_RPL_128CYCLES        //!< 128 Clock Cycles
#define WDT_RPL_256CYCLES                  WDT_CR_RPL_256CYCLES        //!< 256 Clock Cycles


#endif
