/**
 *************************************************************************************
 * @file lpm.c
 * @brief This file implements the function of lpm driver.
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


#ifndef __LPM_H
#define __LPM_H

#include "hw_common.h"
#include "hw_lpm.h"
#if LPM_HW_VER==0
static inline void LPM_enableWakeupPin(void)
{
    HWREG(LPM_BASE+LPM_O_CSR) |= (1<<LPM_CSR_EWUP_POS);  // Enable EWUP for WKUP pin
}




#elif LPM_HW_VER==1

#define CPUSYS_BASE                   LPM_BASE

#define SYSCTL_LPM_IDLE               (0x00U)
#define SYSCTL_LPM_STANDBY            (0x00U)
#define SYSCTL_LPM_HALT               (0x01U)

#define SYSCTL_O_LPMCR                (0x00 + (BOOT_HARTID<<2))   // LPM Control Register
#define SYSCTL_O_GPIOLPMSEL0          (0x10 + (BOOT_HARTID<<2))  // GPIO LPM Wakeup select registers
#define SYSCTL_O_GPIOLPMSEL1          (0x14 + (BOOT_HARTID<<2))  // GPIO LPM Wakeup select registers


//*************************************************************************************************
//
// The following are defines for the bit fields in the LPMCR register
//
//*************************************************************************************************
#define SYSCTL_LPMCR_LPM_S         0U
#define SYSCTL_LPMCR_LPM_M         0x3U      // Low Power Mode setting
#define SYSCTL_LPMCR_QUALSTDBY_S   2U
#define SYSCTL_LPMCR_QUALSTDBY_M   0xFCU     // STANDBY Wakeup Pin Qualification Setting
#define SYSCTL_LPMCR_WDINTE        0x8000U   // Enable for WDINT wakeup from STANDBY




//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL0 register
//
//*************************************************************************************************
#define SYSCTL_GPIOLPMSEL0_GPIO0    0x1U          // GPIO0 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO1    0x2U          // GPIO1 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO2    0x4U          // GPIO2 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO3    0x8U          // GPIO3 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO4    0x10U         // GPIO4 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO5    0x20U         // GPIO5 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO6    0x40U         // GPIO6 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO7    0x80U         // GPIO7 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO8    0x100U        // GPIO8 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO9    0x200U        // GPIO9 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO10   0x400U        // GPIO10 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO11   0x800U        // GPIO11 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO12   0x1000U       // GPIO12 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO13   0x2000U       // GPIO13 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO14   0x4000U       // GPIO14 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO15   0x8000U       // GPIO15 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO16   0x10000U      // GPIO16 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO17   0x20000U      // GPIO17 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO18   0x40000U      // GPIO18 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO19   0x80000U      // GPIO19 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO20   0x100000U     // GPIO20 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO21   0x200000U     // GPIO21 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO22   0x400000U     // GPIO22 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO23   0x800000U     // GPIO23 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO24   0x1000000U    // GPIO24 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO25   0x2000000U    // GPIO25 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO26   0x4000000U    // GPIO26 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO27   0x8000000U    // GPIO27 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO28   0x10000000U   // GPIO28 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO29   0x20000000U   // GPIO29 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO30   0x40000000U   // GPIO30 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO31   0x80000000U   // GPIO31 Enable for LPM Wakeup

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL1 register
//
//*************************************************************************************************
#define SYSCTL_GPIOLPMSEL1_GPIO32   0x1U          // GPIO32 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO33   0x2U          // GPIO33 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO34   0x4U          // GPIO34 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO35   0x8U          // GPIO35 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO36   0x10U         // GPIO36 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO37   0x20U         // GPIO37 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO38   0x40U         // GPIO38 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO39   0x80U         // GPIO39 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO40   0x100U        // GPIO40 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO41   0x200U        // GPIO41 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO42   0x400U        // GPIO42 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO43   0x800U        // GPIO43 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO44   0x1000U       // GPIO44 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO45   0x2000U       // GPIO45 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO46   0x4000U       // GPIO46 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO47   0x8000U       // GPIO47 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO48   0x10000U      // GPIO48 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO49   0x20000U      // GPIO49 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO50   0x40000U      // GPIO50 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO51   0x80000U      // GPIO51 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO52   0x100000U     // GPIO52 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO53   0x200000U     // GPIO53 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO54   0x400000U     // GPIO54 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO55   0x800000U     // GPIO55 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO56   0x1000000U    // GPIO56 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO57   0x2000000U    // GPIO57 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO58   0x4000000U    // GPIO58 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO59   0x8000000U    // GPIO59 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO60   0x10000000U   // GPIO60 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO61   0x20000000U   // GPIO61 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO62   0x40000000U   // GPIO62 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO63   0x80000000U   // GPIO63 Enable for LPM Wakeup



//*****************************************************************************
//
//! Enters IDLE mode.
//!
//! This function puts the device into IDLE mode. The CPU clock is gated while
//! all peripheral clocks are left running. Any enabled interrupt will wake the
//! CPU up from IDLE mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterIdleMode(void)
{
    EALLOW;

    //
    // Configure the device to go into IDLE mode when IDLE is executed.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
                (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) &
                 ~(uint32_t)SYSCTL_LPMCR_LPM_M) | SYSCTL_LPM_IDLE;

    EDIS;

    __set_wfi_sleepmode(WFI_SHALLOW_SLEEP);
    __WFI();
}

//*****************************************************************************
//
//! Enters STANDBY mode.
//!
//! This function puts the device into STANDBY mode. This will gate both the
//! CPU clock and any peripheral clocks derived from SYSCLK. The watchdog is
//! left active, and an NMI or an optional watchdog interrupt will wake the
//! CPU subsystem from STANDBY mode.
//!
//! GPIOs may be configured to wake the CPU subsystem. See
//! SysCtl_enableLPMWakeupPin().
//!
//! The CPU will receive an interrupt (WAKEINT) on wakeup.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterStandbyMode(void)
{
    EALLOW;

    //
    // Configure the device to go into STANDBY mode when IDLE is executed.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
                (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) &
                 ~(uint32_t)SYSCTL_LPMCR_LPM_M) | SYSCTL_LPM_STANDBY;

    EDIS;

    __set_wfi_sleepmode(WFI_DEEP_SLEEP);
    __WFI();
}

//*****************************************************************************
//
//! Enters HALT mode.
//!
//! This function puts the device into HALT mode. This will gate almost all
//! systems and clocks and allows for the power-down of oscillators and analog
//! blocks. The watchdog may be left clocked to produce a reset. See
//! SysCtl_enableWatchdogInHalt() to enable this. GPIOs should be
//! configured to wake the CPU subsystem. See SysCtl_enableLPMWakeupPin().
//!
//! Enter HALT mode (dual CPU). Puts CPU2 in IDLE mode first.
//!
//! The CPU will receive an interrupt (WAKEINT) on wakeup.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterHaltMode(void)
{
#if (BOOT_HARTID > 0)
    EALLOW;
    //
    // Configure the device to go into IDLE mode when IDLE is executed.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
            (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) &
             ~(uint32_t)SYSCTL_LPMCR_LPM_M) | SYSCTL_LPM_IDLE;

    EDIS;


#else
    EALLOW;

    //
    // Configure the device to go into HALT mode when IDLE is executed.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
                (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) &
                 ~(uint32_t)SYSCTL_LPMCR_LPM_M) | SYSCTL_LPM_HALT;

    EDIS;
#endif
    __set_wfi_sleepmode(WFI_SHALLOW_SLEEP);
    __WFI();
}

//*****************************************************************************
//! Enables a pin to wake up the device from the following mode(s):
//!  - STANDBY
//!  - HALT
//!
//! \param pin is the identifying number of the pin.
//!
//! This function connects a pin to the LPM circuit, allowing an event on the
//! pin to wake up the device when when it is in following mode(s):
//!  - STANDBY
//!  - HALT
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin. Only GPIOs 0 through 63 are capable of
//! being connected to the LPM circuit.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableLPMWakeupPin(uint32_t pin)
{
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(pin <= 63U);

    pinMask = 1UL << (pin % 32U);

    EALLOW;

    if(pin < 32U)
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL0) |= pinMask;
    }
    else
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL1) |= pinMask;
    }

    EDIS;
}

//*****************************************************************************
//! Disables a pin to wake up the device from the following mode(s):
//!  - STANDBY
//!  - HALT
//!
//! \param pin is the identifying number of the pin.
//!
//! This function disconnects a pin to the LPM circuit, disallowing an event on
//! the pin to wake up the device when when it is in following mode(s):
//!  - STANDBY
//!  - HALT
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin. Only GPIOs 0 through 63 are valid.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableLPMWakeupPin(uint32_t pin)
{
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(pin <= 63U);

    pinMask = 1UL << (pin % 32U);

    EALLOW;

    if(pin < 32U)
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL0) &= ~pinMask;
    }
    else
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL1) &= ~pinMask;
    }

    EDIS;
}



//*****************************************************************************
//
//! Sets the number of cycles to qualify an input on waking from STANDBY mode.
//!
//! \param cycles is the number of OSCCLK cycles.
//!
//! This function sets the number of OSCCLK clock cycles used to qualify the
//! selected inputs when waking from STANDBY mode. The \e cycles parameter
//! should be passed a cycle count between 2 and 65 cycles inclusive.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setStandbyQualificationPeriod(uint16_t cycles)
{
    //
    // Check the arguments.
    //
    ASSERT((cycles >= 2U) && (cycles <= 65U));

    EALLOW;

    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) =
                (HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) &
                 ~(uint16_t)SYSCTL_LPMCR_QUALSTDBY_M) |
                ((cycles - 2U) << SYSCTL_LPMCR_QUALSTDBY_S);

    EDIS;
}

//*****************************************************************************
//
//! Enable the device to wake from STANDBY mode upon a watchdog interrupt.
//!
//! \note In order to use this option, you must configure the watchdog to
//! generate an interrupt using SysCtl_setWatchdogMode().
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableWatchdogStandbyWakeup(void)
{
    EALLOW;

    //
    // Set the bit enables the watchdog to wake up the device from STANDBY.
    //
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) |= SYSCTL_LPMCR_WDINTE;

    EDIS;
}

//*****************************************************************************
//
//! Disable the device from waking from STANDBY mode upon a watchdog interrupt.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableWatchdogStandbyWakeup(void)
{
    EALLOW;

    //
    // Clear the bit enables the watchdog to wake up the device from STANDBY.
    //
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) &= ~SYSCTL_LPMCR_WDINTE;

    EDIS;
}




#endif
#endif /* __LPM_H */

