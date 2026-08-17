/**
 *************************************************************************************
 * @file SYSCTL.h
 * @brief This file impleted the function of sysctl.
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

#ifndef __SYSCTL_H
#define __SYSCTL_H

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
//! \addtogroup aSYSCTL_api SYSCTL
//! @{
//
//*****************************************************************************
#include "hw_common.h"
#include "hw_sysctl.h"

#if SYSCTL_HW_VER == 0

typedef struct
{
    __IO uint32_t IO_REUSE0; /* offset 10 */
    __IO uint32_t IO_REUSE1; /* offset 14 */
    __IO uint32_t IO_REUSE2; /* offset 18 */
    __IO uint32_t IO_REUSE3; /* offset 1c */
    __IO uint32_t IO_REUSE4; /* offset 20 */
    __IO uint32_t IO_REUSE5; /* offset 24 */
    __IO uint32_t IO_REUSE6; /* offset 28 */
    __IO uint32_t IO_REUSE7; /* offset 2c */
    __IO uint32_t IO_REUSE8; /* offset 30 */
    __IO uint32_t IO_REUSE9; /* offset 34 */
    __IO uint32_t IO_REUSE10; /* offset 38 */
    __IO uint32_t IO_REUSE11; /* offset 3c */
    __IO uint32_t IO_REUSE12; /* offset 40 */
    __IO uint32_t IO_REUSE13; /* offset 44 */
    __IO uint32_t IO_REUSE14; /* offset 48 */
    __IO uint32_t IO_REUSE15; /* offset 4c */
    __IO uint32_t IO_REUSE16; /* offset 50 */
    __IO uint32_t IO_REUSE17; /* offset 54 */
    __IO uint32_t QSPI_XIP; /* offset 58 */
    __IO uint32_t ADC_TRIG_SEL; /* offset 5c */
} SYSCTL_TypeDef;

//
// OSCSTATUS value on completion
//
#define SYSCTL_EXTR_ENABLE_COMPLETE (0xE7U)

//*****************************************************************************
//
// Defines used for setting AnalogReference functions.
// SYSCTL_setAnalogReferenceInternal()
// SYSCTL_setAnalogReferenceExternal()
// SYSCTL_setAnalogReference2P5()
// SYSCTL_setAnalogReference1P65()
//
//*****************************************************************************
#define SYSCTL_VREFHI  0x1U //!< VREFHI

//*****************************************************************************
//
// Values used for function SYSCTL_enableCMPSSExternalDAC() and
// SYSCTL_disableCMPSSExternalDAC().  These values can be OR-ed together and
// passed these functions.
//
//*****************************************************************************
#define SYSCTL_CMPSS1_DACL 0x1U //!< CMPSS1.DACL

//*****************************************************************************
//
// Values used for function SYSCTL_selectCMPHNMux() and
// SYSCTL_selectCMPHNMuxValue().  These values can be OR-ed together and
// passed to SYSCTL_selectCMPHNMux().
//
//*****************************************************************************
#define SYSCTL_CMPHNMUX_SELECT_1 0x1U //!< CMPHNMUX select 1
#define SYSCTL_CMPHNMUX_SELECT_2 0x2U //!< CMPHNMUX select 2
#define SYSCTL_CMPHNMUX_SELECT_3 0x4U //!< CMPHNMUX select 3
#define SYSCTL_CMPHNMUX_SELECT_4 0x8U //!< CMPHNMUX select 4

//*****************************************************************************
//
// Values used for function SYSCTL_selectCMPLNMux() and
// SYSCTL_selectCMPLNMuxValue().  These values can be OR-ed together and
// passed to SYSCTL_selectCMPLNMux().
//
//*****************************************************************************
#define SYSCTL_CMPLNMUX_SELECT_1 0x1U //!< CMPLNMUX select 1
#define SYSCTL_CMPLNMUX_SELECT_2 0x2U //!< CMPLNMUX select 2
#define SYSCTL_CMPLNMUX_SELECT_3 0x4U //!< CMPLNMUX select 3
#define SYSCTL_CMPLNMUX_SELECT_4 0x8U //!< CMPLNMUX select 4

//*****************************************************************************
//
//! SYSCTL_CMPHPMuxSelect used for function SYSCTL_selectCMPHPMux().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CMPHPMUX_SELECT_1 = 0U, //!< CMPHPMUX select 1
    SYSCTL_CMPHPMUX_SELECT_2 = 3U, //!< CMPHPMUX select 2
    SYSCTL_CMPHPMUX_SELECT_3 = 6U, //!< CMPHPMUX select 3
    SYSCTL_CMPHPMUX_SELECT_4 = 9U  //!< CMPHPMUX select 4
} SYSCTL_CMPHPMuxSelect;

//*****************************************************************************
//
//! SYSCTL_CMPLPMuxSelect used for function SYSCTL_selectCMPLPMux().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CMPLPMUX_SELECT_1 = 0U, //!< CMPLPMUX select 1
    SYSCTL_CMPLPMUX_SELECT_2 = 3U, //!< CMPLPMUX select 2
    SYSCTL_CMPLPMUX_SELECT_3 = 6U, //!< CMPLPMUX select 3
    SYSCTL_CMPLPMUX_SELECT_4 = 9U  //!< CMPLPMUX select 4
} SYSCTL_CMPLPMuxSelect;

//*****************************************************************************
//
//! SYSCTL_TestSelect used for function SYSCTL_selectInternalTestNode().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_TEST_NODE_NO_CONN       = 0U,  //!< No Internal Connection
    SYSCTL_TEST_NODE_VDDCORE         = 1U,  //!< Core VDD (1.2V) voltage
    SYSCTL_TEST_NODE_VREFLO              = 2U,  //!< VREFLO pin voltage
    SYSCTL_TEST_NODE_CDAC1H              = 4U,  //!< CMPSS1 High DAC output
    SYSCTL_TEST_NODE_CDAC1L              = 5U,  //!< CMPSS1 Low DAC output
    SYSCTL_TEST_NODE_CDAC2H              = 6U,  //!< CMPSS2 High DAC output
    SYSCTL_TEST_NODE_CDAC2L              = 7U,  //!< CMPSS2 Low DAC output
    SYSCTL_TEST_NODE_CDAC3H              = 8U,  //!< CMPSS3 High DAC output
    SYSCTL_TEST_NODE_CDAC3L              = 9U,  //!< CMPSS3 Low DAC output
    SYSCTL_TEST_NODE_CDAC4H              = 10U, //!< CMPSS4 High DAC output
    SYSCTL_TEST_NODE_CDAC4L              = 11U, //!< CMPSS4 Low DAC output
    SYSCTL_TEST_NODE_VDDA                = 12U, //!< VDDA voltage
    SYSCTL_TEST_NODE_VSSA                = 13U, //!< VSSA - Analog ground pin
    SYSCTL_TEST_NODE_ENZ_CALIB_GAIN_3P3V = 19U //!< All ADCs are placed in gain
                                                //!< calibration mode
} SYSCTL_TestSelect;

//*****************************************************************************
//
//! Values that set the source of ECAP SYNCI
//! parameter.
//
//*****************************************************************************
typedef enum
{

    ECAP_DISABLESYNCI   = 0x0U,
    ECAP_EPWM1SYNCOUT   = 0x1U,
    ECAP_EPWM2SYNCOUT   = 0x2U,
    ECAP_EPWM3SYNCOUT   = 0x3U,
    ECAP_EPWM4SYNCOUT   = 0x4U,
    ECAP_EPWM5SYNCOUT   = 0x5U,
    ECAP_EPWM6SYNCOUT   = 0x6U,
    ECAP_EPWM7SYNCOUT   = 0x7U,
    ECAP_EPWM8SYNCOUT   = 0x8U,
    ECAP_ECAP1SYNCOUT   = 0x11,
    ECAP_ECAP2SYNCOUT   = 0x12,
    ECAP_ECAP3SYNCOUT   = 0x13,
    ECAP_INPUTXBAROUT5  = 0x18,
    ECAP_INPUTXBAROUT6  = 0x19,
    ECAP_FSI_RXA_RX_TRIG1 = 0x1F,
}ECAP_SYNCISource;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! Resets a peripheral
//!
//! \param peripheral is the peripheral to reset.
//!
//! This function uses the SOFTPRESx registers to reset a specified peripheral.
//! Module registers will be returned to their reset states.
//!
//! \note This includes registers containing trim values.The peripheral
//! software reset needed by CPU2 can be communicated to CPU1 via
//! IPC for all shared peripherals.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_resetPeripheral(SysCtl_PeripheralSOFTPRES peripheral)
{
    uint32_t regIndex;
    uint32_t bitIndex;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    HWREG(RCC_BASE + regIndex) |= (1U << bitIndex);
    HWREG(RCC_BASE + regIndex) &= ~(1U << bitIndex);
}

//*****************************************************************************
//
//! Enables a peripheral.
//!
//! \param peripheral is the peripheral to enable.
//!
//! Peripherals are enabled with this function.  At power-up, all peripherals
//! are disabled; they must be enabled in order to operate or respond to
//! register reads/writes.
//!
//! \note Note that there should be atleast 5 cycles delay between enabling the
//! peripheral clock and accessing the peripheral registers. The delay should be
//! added by the user if the peripheral is accessed immediately after this
//! function call.
//! Use asm(" RPT #5 || NOP"); to add 5 cycle delay post this function call.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_enablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint32_t IPIndex;
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t IP_BASE;
    IPIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_IP_M)
            >> SYSCTL_PERIPH_IP_S;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    if (IPIndex == 0)
    {
        IP_BASE = SYSCTL_BASE;
    }
    else
    {
        IP_BASE = RCC_BASE;
    }
    HWREG(IP_BASE + regIndex) |= (1U << bitIndex);
}

//*****************************************************************************
//
//! Disables a peripheral.
//!
//! \param peripheral is the peripheral to disable.
//!
//! Peripherals are disabled with this function.  Once disabled, they will not
//! operate or respond to register reads/writes.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_disablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint32_t IPIndex;
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t IP_BASE;
    IPIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_IP_M)
            >> SYSCTL_PERIPH_IP_S;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    if (IPIndex == 0)
    {
        IP_BASE = SYSCTL_BASE;
    }
    else
    {
        IP_BASE = RCC_BASE;
    }
    HWREG(IP_BASE + regIndex) &= ~(1U << bitIndex);
}

//*****************************************************************************
//
//! Resets the device.
//!
//! This function performs a software reset of the device.
//!
//! \return This function does not return.
//
//*****************************************************************************
static inline void
SysCtl_resetDevice(void)
{

}

//*****************************************************************************
//
//! Enable temperature sensor.
//!
//! This function enables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableTemperatureSensor(void)
{
    //
    // Set the temperature sensor enable bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_TSNS_CTL) |= SYSCTL_TSNSCTL_ENABLE;
}

//*****************************************************************************
//
//! Disable temperature sensor.
//!
//! This function disables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableTemperatureSensor(void)
{
    //
    // Clear the temperature sensor enable bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_TSNS_CTL) &= ~(SYSCTL_TSNSCTL_ENABLE);
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to internal.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \note Internal reference mode is not available for packages lacking VREFHI
//! and VREFLO pins. Please see device datasheet for packages with VREFHI and
//! VREFLO pins available.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setAnalogReferenceInternal(uint16_t reference)
{
    //
    // Write selection to the Analog Internal Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) &= ~reference;
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to external.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setAnalogReferenceExternal(uint16_t reference)
{
    //
    // Write selection to the Analog External Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) |= reference;
}

//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 2.5V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setAnalogReference2P5(uint16_t reference)
{
    //
    // Write selection to the Analog Voltage Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) |= (reference << 8U);

    HWREG(ADCA_BASE + 0xF0) &= ~(0x1000);
    HWREG(ADCB_BASE + 0xF0) &= ~(0x1000);
    HWREG(ADCC_BASE + 0xF0) &= ~(0x1000);
}

//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 1.65V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setAnalogReference1P65(uint16_t reference)
{
    //
    // Write selection to the Analog Voltage Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) &= ~(reference << 8U);

    HWREG(ADCA_BASE + 0xF0) |= 0x1000;
    HWREG(ADCB_BASE + 0xF0) |= 0x1000;
    HWREG(ADCC_BASE + 0xF0) |= 0x1000;
}

//*****************************************************************************
//
//! Select internal test node for ADC.
//!
//! \param testSelect is internal node to come out on ADC.
//!
//! The \e testSelect is the desired internal test node. Valid values can be
//! refered from the enum \e SYSCTL_TestSelect.
//!
//! \return None.
//!
//*****************************************************************************
static inline void SysCtl_selectInternalTestNode(SYSCTL_TestSelect testSelect)
{
    //
    // Select internal test node for ADC
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_INTERNAL_TEST_CTL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_INTERNAL_TEST_CTL) &
        ~(SYSCTL_INTERNALTESTCTL_TESTSEL_M | SYSCTL_INTERNALTESTCTL_KEY_M)) |
        (0xA5A50000UL | testSelect);
}

//*****************************************************************************
//
//! Select the value for CMPHNMXSEL.
//!
//! \param select is a combination of CMPHNMXSEL values.
//!
//! The parameter \e select can be a bitwise OR of the below values:
//!
//! - \b SYSCTL_CMPHNMUX_SELECT_1
//! - \b SYSCTL_CMPHNMUX_SELECT_2
//! - \b SYSCTL_CMPHNMUX_SELECT_3
//! - \b SYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPHNMux(uint16_t select)
{
    //
    // Write a select to the mux select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) = select;
}

//*****************************************************************************
//
//! Select the value for individual CMPxHNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b SYSCTL_CMPHNMUX_SELECT_1
//! - \b SYSCTL_CMPHNMUX_SELECT_2
//! - \b SYSCTL_CMPHNMUX_SELECT_3
//! - \b SYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPHNMuxValue(uint16_t select, uint16_t value)
{
    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) |= select;
    }
    else
    {
        //Do nothing. Not a valid value
    }
}

//*****************************************************************************
//
//! Select the value for individual CMPxLNMXSEL.
//!
//! \param select is a combination of CMPLNMXSEL values.
//!
//! The parameter \e select can be the bitwise OR of the below values:
//!
//! - \b SYSCTL_CMPLNMUX_SELECT_1
//! - \b SYSCTL_CMPLNMUX_SELECT_2
//! - \b SYSCTL_CMPLNMUX_SELECT_3
//! - \b SYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPLNMux(uint16_t select)
{
    //
    // Write a select to the mux select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) = select;
}

//*****************************************************************************
//
//! Select the value for CMPLNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b SYSCTL_CMPLNMUX_SELECT_1
//! - \b SYSCTL_CMPLNMUX_SELECT_2
//! - \b SYSCTL_CMPLNMUX_SELECT_3
//! - \b SYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPLNMuxValue(uint16_t select, uint16_t value)
{
    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) |= select;
    }
    else
    {
        //Do nothing. Not a valid value
    }
}

//*****************************************************************************
//
//! Select the value for CMPHPMXSEL.
//!
//! \param select is of type SYSCTL_CMPHPMuxSelect.
//! \param value is 0, 1, 2, 3, 4 or 5.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b SYSCTL_CMPHPMUX_SELECT_1
//! - \b SYSCTL_CMPHPMUX_SELECT_2
//! - \b SYSCTL_CMPHPMUX_SELECT_3
//! - \b SYSCTL_CMPHPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectCMPHPMux(SYSCTL_CMPHPMuxSelect select, uint32_t value)
{
    //
    // Set the value for the appropriate Mux Select.
    //
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHPMX_SEL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_CMPHPMX_SEL) &
        ~((uint32_t)SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M << (uint32_t)select)) |
        (value << (uint32_t)select);
}

//*****************************************************************************
//
//! Select the value for CMPLPMXSEL.
//!
//! \param select is of type SYSCTL_CMPLPMuxSelect.
//! \param value is 0, 1, 2, 3, 4 or 5.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b SYSCTL_CMPLPMUX_SELECT_1
//! - \b SYSCTL_CMPLPMUX_SELECT_2
//! - \b SYSCTL_CMPLPMUX_SELECT_3
//! - \b SYSCTL_CMPLPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectCMPLPMux(SYSCTL_CMPLPMuxSelect select, uint32_t value)
{
    //
    // Set the value for the appropriate Mux Select.
    //
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLPMX_SEL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_CMPLPMX_SEL) &
        ~((uint32_t)SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M << (uint32_t)select)) |
        (value << (uint32_t)select);
}

//*****************************************************************************
//
//! Locks the temperature sensor control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockTemperatureSensor(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_TSNSCTL;
}

//*****************************************************************************
//
//! Locks the analog reference control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockANAREF(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_ANAREFCTL;
}

//*****************************************************************************
//
//! Locks the voltage monitor control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockVMON(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_VMONCTL;
}

//*****************************************************************************
//
//! Locks the CMPHPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPHPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPHPMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPLPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPLPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPLPMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPHNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPHNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPHNMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPLNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPLNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPLNMXSEL;
}

//*****************************************************************************
//
//! Locks the VREG control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockVREG(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_VREGCTL;
}

//*****************************************************************************
//
//! Locks the CMPSSCTL register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPSSCTL(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPSSCTL;
}


//*****************************************************************************
//
//! Enable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static inline void SysCtl_enableADCDACLoopback(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) | config) |
            (0xA5A5UL << SYSCTL_ADCDACLOOPBACK_KEY_S);
}

//*****************************************************************************
//
//! Disable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCB
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static inline void SysCtl_disableADCDACLoopback(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) & ~config) |
            (0xA5A5UL << SYSCTL_ADCDACLOOPBACK_KEY_S);
}

static inline void SysCtl_configXIP(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) = (HWREG(
            SYSCTL_BASE + SYSCTL_O_MSPI_CFG) & (~0xF)) | config;
}

static inline void SysCtl_enableEPWMGlobalSync(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) = (HWREG(
            SYSCTL_BASE + SYSCTL_O_CTRL_SUB) & (~SYSCTL_CTRLSUB_EPWMGBCLKSYNC))
            | SYSCTL_CTRLSUB_EPWMGBCLKSYNC;
}

static inline void SysCtl_disableEPWMGlobalSync(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) = (HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) & (~SYSCTL_CTRLSUB_EPWMGBCLKSYNC));
}

static inline void SysCtl_setSPIxMode(uint32_t modeControl)
{
    uint32_t regOffset;
    regOffset = (modeControl >> 8);
    HWREG(SYSCTL_BASE + regOffset) = (modeControl & 0x1);
}

static inline void SysCtl_setECAPxSyncInPulseSource(uint32_t ECAPx_base,ECAP_SYNCISource source)
{
    switch(ECAPx_base)
    {
        case ECAP1_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP1_SYNCSEL) = source;
            break;
        case ECAP2_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP2_SYNCSEL) = source;
            break;
        case ECAP3_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP3_SYNCSEL) = source;
            break;
        default:
            break;
    }
}

//*****************************************************************************
//
//! Set IO to QSPI
//
//*****************************************************************************
static inline void SysCtl_setQSPIIOEnable(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) |= SYSCTL_MSPI_IO_EN;
}

//*****************************************************************************
//
//! Set IO to XFlashc
//
//*****************************************************************************
static inline void SysCtl_setXFCIOEnable(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) &= ~SYSCTL_MSPI_IO_EN;
}

#if EPWM_HW_VER == 0
//*****************************************************************************
//
//! Configures the sync input source for the ePWM and eCAP signals.
//!
//! \param syncInput is the sync input being configured
//! \param syncSrc is sync input source selection.
//!
//! This function configures the sync input source for the ePWM and eCAP
//! modules. The \e syncInput parameter is the sync input being configured. It
//! should be passed a value of \b SYSCTL_SYNC_IN_XXXX, where XXXX is the ePWM
//! or eCAP instance the sync signal is entering.
//!
//! The \e syncSrc parameter is the sync signal selected as the source of the
//! sync input. It should be passed a value of \b SYSCTL_SYNC_IN_SRC_XXXX,
//! XXXX is a sync signal coming from an ePWM, eCAP or external sync output.
//! where For example, a \e syncInput value of \b SYSCTL_SYNC_IN_ECAP1 and a
//! \e syncSrc value of \b SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT will make the
//! EPWM1SYNCOUT signal drive eCAP1's SYNCIN signal.
//!
//! Note that some \e syncSrc values are only valid for certain values of
//! \e syncInput. See device technical reference manual for details on
//! time-base counter synchronization.
//!
//! \return None.
//
//*****************************************************************************
static inline void EPWM_setSyncInPulseSource(uint32_t base,
        EPWM_SyncInPulseSource source)
{
    //
    // Write the input sync source selection to the appropriate register.
    //
    uint32_t offset;

    switch (base)
    {
    case EPWM1_BASE:
        offset = SYSCTL_O_EPWM1_SYNCIN_SEL;
        break;
    case EPWM2_BASE:
        offset = SYSCTL_O_EPWM2_SYNCIN_SEL;
        break;
    case EPWM3_BASE:
        offset = SYSCTL_O_EPWM3_SYNCIN_SEL;
        break;
    case EPWM4_BASE:
        offset = SYSCTL_O_EPWM4_SYNCIN_SEL;
        break;
    case EPWM5_BASE:
        offset = SYSCTL_O_EPWM5_SYNCIN_SEL;
        break;
    case EPWM6_BASE:
        offset = SYSCTL_O_EPWM6_SYNCIN_SEL;
        break;
    case EPWM7_BASE:
        offset = SYSCTL_O_EPWM7_SYNCIN_SEL;
        break;
    case EPWM8_BASE:
        offset = SYSCTL_O_EPWM8_SYNCIN_SEL;
        break;

    }
    HWREG(SYSCTL_BASE+offset) = (HWREG(SYSCTL_BASE+offset)
            & ~SYSCTL_EPWMxSYNCINSEL_M)
            | ((uint32_t) source << SYSCTL_EPWMxSYNCINSEL_S);

}
#endif

//*****************************************************************************
//
//! Configures the sync output source.
//!
//! \param syncSrc is sync output source selection.
//!
//! This function configures the sync output source from the ePWM modules. The
//! \e syncSrc parameter is a value \b SYSCTL_SYNC_OUT_SRC_XXXX, where XXXX is
//! a sync signal coming from an ePWM such as SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setSyncOutputConfig(SysCtl_SyncOutputSource syncSrc)
{
    //
    // Write the sync output source selection to the appropriate register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_SYNC_SELECT) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_SYNC_SELECT)
                    & ~((uint32_t) SYSCTL_SYNCSELECT_SYNCOUT_M))
                    | ((uint32_t) syncSrc << SYSCTL_SYNCSELECT_SYNCOUT_S);

}

//*****************************************************************************
//
//! Enables ePWM SOC signals to drive an external (off-chip) ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be enabled
//!
//! This function configures which ePWM SOC signals are enabled as a source for
//! either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical OR
//! of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_enableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Set the bits that correspond to signal to be enabled.
    //
    uint32_t offset;
    uint32_t source;
    if (adcsocSrc > 0x1000)
    {
        offset = SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL;
        source = adcsocSrc >> 16;
    }
    else
    {
        offset = SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL;
        source = adcsocSrc;
    }
    HWREG(SYSCTL_BASE + offset) |= source;
}

//*****************************************************************************
//
//! Disables ePWM SOC signals from driving an external ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be disabled
//!
//! This function configures which ePWM SOC signals are disabled as a source
//! for either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical
//! OR of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_disableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Clear the bits that correspond to signal to be disabled.
    //
    uint32_t offset;
    uint32_t source;
    if (adcsocSrc > 0x1000)
    {
        offset = SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL;
        source = adcsocSrc >> 16;
    }
    else
    {
        offset = SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL;
        source = adcsocSrc;
    }
    HWREG(SYSCTL_BASE + offset) &= ~source;
}

//*****************************************************************************
//
//! Locks the SOC Select of the Trig X-BAR.
//!
//! This function locks the external ADC SOC select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockExtADCSOCSelect(void)
{
    HWREG(SYSCTL_BASE+ SYSCTL_O_SYNCSOC_LOCK) |= SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_M;
}

//*****************************************************************************
//
//! Locks the Sync Select of the Trig X-BAR.
//!
//! This function locks Sync Input and Output Select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockSyncSelect(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SYNCSOC_LOCK) |= SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_M;
}

//*****************************************************************************
//
//! Set the Option Bytes Source.
//!
//! This function sets the source of option byte.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setOBSource(SysCtl_OBSourece source)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_OB_SEL) = source;
}

//*****************************************************************************
//
//! Set wwdg stop or continue in the Debug mode.
//!
//! This function controls the wwdg in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgWwdgStop(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_WWDG_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_WWDG_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm sleep in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmSleep(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_SLEEP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_SLEEP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm stop in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmStop(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm standby in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmStandby(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set GPIOx debounce counting period.
//!
//! GPIOx debounce counting period, one set (32 GPIO ports) shares one value
//! GPIOx should be 0~5
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxDebounceVal(uint32_t GPIOx , uint32_t debounce_val)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_DEBOUNCE_VAL + GPIOx*4) = debounce_val;
}

//*****************************************************************************
//
//! Set GPIOx Qualification Period
//!
//! GPIO qualification period. Each GPIO port uses 8 bits. Only GPIO port 0 to 95 (the first three sets of GPIO) have this function.
//!
//! 0x0: Sampling window = 1 / PCLK
//! 0x1 ~ 0xFF: Sampling window = 2 * [qual_prd] * 1 / PCLK
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxQualPRDx(uint32_t gpio_pin , uint8_t debounce_val)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 4;
    shift = gpio_pin % 4;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_QUAL_PRDx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_QUAL_PRDx + offset*4)
                    & ~(0xFF << (shift * 8))) | debounce_val << (shift * 8);
}

//*****************************************************************************
//
//! Set GPIOx Qualification Mode
//!
//! GPIO qualification mode. Each GPIO port uses 2 bits. Only GPIO ports 0 to 95 (the first three GPIO groups) have this function.
//!
//! 0b00: Synchronous to PCLK
//! 0b01: Synchronous (3-sample window)
//! 0b10: Synchronous (6-sample window)
//! 0b11: Asynchronous
//!
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxQualMODEx(uint32_t gpio_pin , SysCtl_GPIOxQualificationMode mode)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 16;
    shift = gpio_pin % 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_QUAL_MODEx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_QUAL_MODEx + offset*4)
                    & ~(0x3 << (shift * 2))) | mode << (shift * 2);
}

//*****************************************************************************
//
//! Set GPIOx input inversion.
//!
//! GPIO input inversion enable. Only GPIO ports 0 to 95 (the first three GPIO groups) have this function.
//! 1: Inverted
//! 0: Not inverted
//!
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxInputINV(uint32_t gpio_pin , FunctionalState NewState)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState != ENABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4) |= (0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4) =
                ( HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4)
                        & ~(0x1 << shift));
    }
}

//*****************************************************************************
//
//! Set GPIOx Pull up/down ENABLE.
//!
//! PAD pull-up/pull-down resistor enable. Must be used in conjunction with PS to select pull-up or pull-down.
//! 1: Enabled
//! 0: Disabled
//!
//! gpio_pin = 0~128
//!
//! PAD28/32, PAD210~212 default to pull-up; PAD213 defaults to pull-down; all others default to no pull-up/pull-down.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxPullEnable(uint32_t gpio_pin , FunctionalState NewState)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PEx + offset*4) |= (0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PEx + offset*4) &= ~(0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx Pull up/down.
//!
//! PAD pull-up/pull-down resistor selection. Effective when PEx is set to 1.
//! 1: Pull-up
//! 0: Pull-down
//!
//! gpio_pin = 0~128
//!
//! PAD28/32, PAD210~212 default to pull-up; PAD213 defaults to pull-down; all others default to no pull-up/pull-down.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxPullSel(uint32_t gpio_pin , SysCtl_GPIOxUPorDOWN NewState)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState == GPIOx_PULL_DOWN)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PSx + offset*4) &= ~(0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PSx + offset*4) |= (0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx input mode.
//!
//! PAD input mode selection:
//!
//! 1: Buffer Input
//! 0: Schmitt Input
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxIuputMode(uint32_t gpio_pin , SysCtl_GPIOxInputMode mode)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(mode == GPIOx_INPUT_SCHMITT)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_ISx + offset*4) &= ~(0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_ISx + offset*4) |= (0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx input mode.
//!
//! PAD input mode selection:
//!
//! 1: Buffer Input
//! 0: Schmitt Input
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxDriverStrength(uint32_t gpio_pin , SysCtl_GPIOxDriveStrength strength)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 16;
    shift = gpio_pin % 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_DRx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_DRx + offset*4)
                    & ~(0x3 << (shift * 2))) | strength << (shift * 2);
}

//*****************************************************************************
//!
//! Set GPIOC Analog mode.
//!
//! PAD analog mode enable.
//! Only PAD64 to PAD95 have this function, with each PAD occupying 1 bit.
//! Analog mode is enabled by default.
//!
//! 1: Analog mode
//! 0: Digital mode
//! In analog mode, the PAD's IE, OE, and DOUT are fixed at 0.
//!
//! gpio_pin = 64~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOCAMSEL(uint32_t gpio_pin , SysCtl_GPIOCAMSEL amsel)
{
    uint32_t shift;
    shift = gpio_pin  - 160;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOC_AMSEL) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIOC_AMSEL)
                    & ~(0x1 << shift)) | (amsel << shift);
}

static inline void SysCtl_setExtiWakeUp(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_EXTI_WK_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_EXTI_WK_EN) &= ~(0x1);
    }
}

static inline void SysCtl_setEQEP1Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline void SysCtl_setEQEP2Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline void SysCtl_setEQEP3Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline uint32_t SysCtl_getTIMxStatus(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_TIMERx_STAT);
}

static inline void SysCtl_setCPUDebugMode(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WWDG_DBG_CFG) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WWDG_DBG_CFG) &= ~(0x1);
    }
}

static inline void SysCtl_setDccNMIIRQ(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) &= ~(0x1);
    }
}

static inline void SysCtl_setAGIOCTRLLOCK(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) &= ~(0x1);
    }
}

static inline void SysCtl_enableVMON(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_VMON_CTL) |= (0x1);
}

static inline void SysCtl_disableVMON(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_VMON_CTL) &= ~(0x1);
}

static inline void SysCtl_enableNMI(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CORE_NMI_WK_EN) = SYSCTL_CORE1_NMI_WK_EN;
}

static inline void SysCtl_disableNMI(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CORE_NMI_WK_EN) = SYSCTL_CORE1_NMI_WK_DIS;
}

static inline void SysCtl_setAGPIOCTRLA(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_AGPIO_CTRLA) = config;
}

static inline void SysCtl_setSMCMHWINT(uint8_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SMCM_HWINT) = config;
}

static inline void SysCtl_setTIMERxCHxPRESC(SysCtl_TIMERx gtimx, uint32_t presc)
{
    uint32_t offset;
    uint32_t shift;
    offset = (gtimx / 2) * 4;
    shift = (gtimx % 2) * 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_TIM1_PRESC + offset) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_TIM1_PRESC + offset)
                    & ~(0xFFFF << shift)) | ((presc - 1) << shift);
}

static inline void SysCtl_setWDTSpeedUp(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WDG_SPEED_UP) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WDG_SPEED_UP) &= ~(0x1);
    }
}

static inline uint32_t SysCtl_getSMCMECCError(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_SMCM_ECC_ERR);
}

static inline uint32_t SysCtl_getErrorStatus(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_STAT);
}

static inline void SysCtl_clearErrorStatus(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_STAT_CLR) |= 0x1;
}

static inline void SysCtl_forceErrorStatus(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SRROR_STAT_FRC) |= 0x1;
}

static inline void SysCtl_setErrorConfig(uint32_t conifg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_CTL) |= 0x1;
}

static inline void SysCtl_setErrorLock(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_LOCK) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_LOCK) &= ~(0x1);
    }
}

static inline void SysCtl_setCMPSSConfig(uint32_t cmpssConfig)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPSS_CFG) = cmpssConfig;
}

static inline void SysCtl_setDACCConfig(uint32_t dacConfig)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_DACC_CFG) = dacConfig;
}

static inline void SysCtl_setXFLASHCConfig(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_XFLASHC) = config & 0x7;
}

#elif SYSCTL_HW_VER == 1
/* RP55 */

typedef struct
{
    __IO uint32_t IO_REUSE0; /* offset 10 */
    __IO uint32_t IO_REUSE1; /* offset 14 */
    __IO uint32_t IO_REUSE2; /* offset 18 */
    __IO uint32_t IO_REUSE3; /* offset 1c */
    __IO uint32_t IO_REUSE4; /* offset 20 */
    __IO uint32_t IO_REUSE5; /* offset 24 */
    __IO uint32_t IO_REUSE6; /* offset 28 */
    __IO uint32_t IO_REUSE7; /* offset 2c */
    __IO uint32_t IO_REUSE8; /* offset 30 */
    __IO uint32_t IO_REUSE9; /* offset 34 */
    __IO uint32_t IO_REUSE10; /* offset 38 */
    __IO uint32_t IO_REUSE11; /* offset 3c */
    __IO uint32_t IO_REUSE12; /* offset 40 */
    __IO uint32_t IO_REUSE13; /* offset 44 */
    __IO uint32_t IO_REUSE14; /* offset 48 */
    __IO uint32_t IO_REUSE15; /* offset 4c */
    __IO uint32_t IO_REUSE16; /* offset 50 */
    __IO uint32_t IO_REUSE17; /* offset 54 */
    __IO uint32_t QSPI_XIP; /* offset 58 */
    __IO uint32_t ADC_TRIG_SEL; /* offset 5c */
} SYSCTL_TypeDef;

//
// OSCSTATUS value on completion
//
#define SYSCTL_EXTR_ENABLE_COMPLETE (0xE7U)

//*****************************************************************************
//
// Defines used for setting AnalogReference functions.
// SYSCTL_setAnalogReferenceInternal()
// SYSCTL_setAnalogReferenceExternal()
// SYSCTL_setAnalogReference2P5()
// SYSCTL_setAnalogReference1P65()
//
//*****************************************************************************
#define SYSCTL_VREFHI  0x1U //!< VREFHI

//*****************************************************************************
//
// Values used for function SYSCTL_enableCMPSSExternalDAC() and
// SYSCTL_disableCMPSSExternalDAC().  These values can be OR-ed together and
// passed these functions.
//
//*****************************************************************************
#define SYSCTL_CMPSS1_DACL 0x1U //!< CMPSS1.DACL

//*****************************************************************************
//
// Values used for function SYSCTL_selectCMPHNMux() and
// SYSCTL_selectCMPHNMuxValue().  These values can be OR-ed together and
// passed to SYSCTL_selectCMPHNMux().
//
//*****************************************************************************
#define SYSCTL_CMPHNMUX_SELECT_1 0x1U //!< CMPHNMUX select 1
#define SYSCTL_CMPHNMUX_SELECT_2 0x2U //!< CMPHNMUX select 2
#define SYSCTL_CMPHNMUX_SELECT_3 0x4U //!< CMPHNMUX select 3
#define SYSCTL_CMPHNMUX_SELECT_4 0x8U //!< CMPHNMUX select 4

//*****************************************************************************
//
// Values used for function SYSCTL_selectCMPLNMux() and
// SYSCTL_selectCMPLNMuxValue().  These values can be OR-ed together and
// passed to SYSCTL_selectCMPLNMux().
//
//*****************************************************************************
#define SYSCTL_CMPLNMUX_SELECT_1 0x1U //!< CMPLNMUX select 1
#define SYSCTL_CMPLNMUX_SELECT_2 0x2U //!< CMPLNMUX select 2
#define SYSCTL_CMPLNMUX_SELECT_3 0x4U //!< CMPLNMUX select 3
#define SYSCTL_CMPLNMUX_SELECT_4 0x8U //!< CMPLNMUX select 4

//*****************************************************************************
//
//! SYSCTL_CMPHPMuxSelect used for function SYSCTL_selectCMPHPMux().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CMPHPMUX_SELECT_1 = 0U, //!< CMPHPMUX select 1
    SYSCTL_CMPHPMUX_SELECT_2 = 3U, //!< CMPHPMUX select 2
    SYSCTL_CMPHPMUX_SELECT_3 = 6U, //!< CMPHPMUX select 3
    SYSCTL_CMPHPMUX_SELECT_4 = 9U  //!< CMPHPMUX select 4
} SYSCTL_CMPHPMuxSelect;

//*****************************************************************************
//
//! SYSCTL_CMPLPMuxSelect used for function SYSCTL_selectCMPLPMux().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CMPLPMUX_SELECT_1 = 0U, //!< CMPLPMUX select 1
    SYSCTL_CMPLPMUX_SELECT_2 = 3U, //!< CMPLPMUX select 2
    SYSCTL_CMPLPMUX_SELECT_3 = 6U, //!< CMPLPMUX select 3
    SYSCTL_CMPLPMUX_SELECT_4 = 9U  //!< CMPLPMUX select 4
} SYSCTL_CMPLPMuxSelect;

//*****************************************************************************
//
//! SYSCTL_TestSelect used for function SYSCTL_selectInternalTestNode().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_TEST_NODE_NO_CONN       = 0U,  //!< No Internal Connection
    SYSCTL_TEST_NODE_VDDCORE         = 1U,  //!< Core VDD (1.2V) voltage
    SYSCTL_TEST_NODE_VREFLO              = 2U,  //!< VREFLO pin voltage
    SYSCTL_TEST_NODE_CDAC1H              = 4U,  //!< CMPSS1 High DAC output
    SYSCTL_TEST_NODE_CDAC1L              = 5U,  //!< CMPSS1 Low DAC output
    SYSCTL_TEST_NODE_CDAC2H              = 6U,  //!< CMPSS2 High DAC output
    SYSCTL_TEST_NODE_CDAC2L              = 7U,  //!< CMPSS2 Low DAC output
    SYSCTL_TEST_NODE_CDAC3H              = 8U,  //!< CMPSS3 High DAC output
    SYSCTL_TEST_NODE_CDAC3L              = 9U,  //!< CMPSS3 Low DAC output
    SYSCTL_TEST_NODE_CDAC4H              = 10U, //!< CMPSS4 High DAC output
    SYSCTL_TEST_NODE_CDAC4L              = 11U, //!< CMPSS4 Low DAC output
    SYSCTL_TEST_NODE_VDDA                = 12U, //!< VDDA voltage
    SYSCTL_TEST_NODE_VSSA                = 13U, //!< VSSA - Analog ground pin
    SYSCTL_TEST_NODE_ENZ_CALIB_GAIN_3P3V = 19U //!< All ADCs are placed in gain
                                                //!< calibration mode
} SYSCTL_TestSelect;

//*****************************************************************************
//
//! Values that set the source of ECAP SYNCI
//! parameter.
//
//*****************************************************************************
typedef enum
{

    ECAP_DISABLESYNCI   = 0x0U,
    ECAP_EPWM1SYNCOUT   = 0x1U,
    ECAP_EPWM2SYNCOUT   = 0x2U,
    ECAP_EPWM3SYNCOUT   = 0x3U,
    ECAP_EPWM4SYNCOUT   = 0x4U,
    ECAP_EPWM5SYNCOUT   = 0x5U,
    ECAP_EPWM6SYNCOUT   = 0x6U,
    ECAP_EPWM7SYNCOUT   = 0x7U,
    ECAP_EPWM8SYNCOUT   = 0x8U,
    ECAP_ECAP1SYNCOUT   = 0x11,
    ECAP_ECAP2SYNCOUT   = 0x12,
    ECAP_ECAP3SYNCOUT   = 0x13,
    ECAP_INPUTXBAROUT5  = 0x18,
    ECAP_INPUTXBAROUT6  = 0x19,
    ECAP_FSI_RXA_RX_TRIG1 = 0x1F,
}ECAP_SYNCISource;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! Resets a peripheral
//!
//! \param peripheral is the peripheral to reset.
//!
//! This function uses the SOFTPRESx registers to reset a specified peripheral.
//! Module registers will be returned to their reset states.
//!
//! \note This includes registers containing trim values.The peripheral
//! software reset needed by CPU2 can be communicated to CPU1 via
//! IPC for all shared peripherals.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_resetPeripheral(SysCtl_PeripheralSOFTPRES peripheral)
{
    uint32_t regIndex;
    uint32_t bitIndex;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    HWREG(RCC_BASE + regIndex) |= (1U << bitIndex);
    HWREG(RCC_BASE + regIndex) &= ~(1U << bitIndex);
}

//*****************************************************************************
//
//! Enables a peripheral.
//!
//! \param peripheral is the peripheral to enable.
//!
//! Peripherals are enabled with this function.  At power-up, all peripherals
//! are disabled; they must be enabled in order to operate or respond to
//! register reads/writes.
//!
//! \note Note that there should be atleast 5 cycles delay between enabling the
//! peripheral clock and accessing the peripheral registers. The delay should be
//! added by the user if the peripheral is accessed immediately after this
//! function call.
//! Use asm(" RPT #5 || NOP"); to add 5 cycle delay post this function call.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_enablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint32_t IPIndex;
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t IP_BASE;
    IPIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_IP_M)
            >> SYSCTL_PERIPH_IP_S;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    if (IPIndex == 0)
    {
        IP_BASE = SYSCTL_BASE;
    }
    else
    {
        IP_BASE = RCC_BASE;
    }
    HWREG(IP_BASE + regIndex) |= (1U << bitIndex);
}

//*****************************************************************************
//
//! Disables a peripheral.
//!
//! \param peripheral is the peripheral to disable.
//!
//! Peripherals are disabled with this function.  Once disabled, they will not
//! operate or respond to register reads/writes.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_disablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint32_t IPIndex;
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t IP_BASE;
    IPIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_IP_M)
            >> SYSCTL_PERIPH_IP_S;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    if (IPIndex == 0)
    {
        IP_BASE = SYSCTL_BASE;
    }
    else
    {
        IP_BASE = RCC_BASE;
    }
    HWREG(IP_BASE + regIndex) &= ~(1U << bitIndex);
}

//*****************************************************************************
//
//! Resets the device.
//!
//! This function performs a software reset of the device.
//!
//! \return This function does not return.
//
//*****************************************************************************
static inline void
SysCtl_resetDevice(void)
{

}

//*****************************************************************************
//
//! Enable temperature sensor.
//!
//! This function enables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableTemperatureSensor(void)
{
    //
    // Set the temperature sensor enable bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_TSNS_CTL) |= SYSCTL_TSNSCTL_ENABLE;
}

//*****************************************************************************
//
//! Disable temperature sensor.
//!
//! This function disables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableTemperatureSensor(void)
{
    //
    // Clear the temperature sensor enable bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_TSNS_CTL) &= ~(SYSCTL_TSNSCTL_ENABLE);
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to internal.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \note Internal reference mode is not available for packages lacking VREFHI
//! and VREFLO pins. Please see device datasheet for packages with VREFHI and
//! VREFLO pins available.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setAnalogReferenceInternal(uint16_t reference)
{
    //
    // Write selection to the Analog Internal Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) &= ~reference;
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to external.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setAnalogReferenceExternal(uint16_t reference)
{
    //
    // Write selection to the Analog External Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) |= reference;
}

//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 2.5V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setAnalogReference2P5(uint16_t reference)
{
    //
    // Write selection to the Analog Voltage Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) |= (reference << 8U);

    HWREG(ADCA_BASE + 0xF0) &= ~(0x1000);
    HWREG(ADCB_BASE + 0xF0) &= ~(0x1000);
    HWREG(ADCC_BASE + 0xF0) &= ~(0x1000);
}

//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 1.65V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setAnalogReference1P65(uint16_t reference)
{
    //
    // Write selection to the Analog Voltage Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) &= ~(reference << 8U);

    HWREG(ADCA_BASE + 0xF0) |= 0x1000;
    HWREG(ADCB_BASE + 0xF0) |= 0x1000;
    HWREG(ADCC_BASE + 0xF0) |= 0x1000;
}

//*****************************************************************************
//
//! Select internal test node for ADC.
//!
//! \param testSelect is internal node to come out on ADC.
//!
//! The \e testSelect is the desired internal test node. Valid values can be
//! refered from the enum \e SYSCTL_TestSelect.
//!
//! \return None.
//!
//*****************************************************************************
static inline void SysCtl_selectInternalTestNode(SYSCTL_TestSelect testSelect)
{
    //
    // Select internal test node for ADC
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_INTERNAL_TEST_CTL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_INTERNAL_TEST_CTL) &
        ~(SYSCTL_INTERNALTESTCTL_TESTSEL_M | SYSCTL_INTERNALTESTCTL_KEY_M)) |
        (0xA5A50000UL | testSelect);
}

//*****************************************************************************
//
//! Select the value for CMPHNMXSEL.
//!
//! \param select is a combination of CMPHNMXSEL values.
//!
//! The parameter \e select can be a bitwise OR of the below values:
//!
//! - \b SYSCTL_CMPHNMUX_SELECT_1
//! - \b SYSCTL_CMPHNMUX_SELECT_2
//! - \b SYSCTL_CMPHNMUX_SELECT_3
//! - \b SYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPHNMux(uint16_t select)
{
    //
    // Write a select to the mux select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) = select;
}

//*****************************************************************************
//
//! Select the value for individual CMPxHNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b SYSCTL_CMPHNMUX_SELECT_1
//! - \b SYSCTL_CMPHNMUX_SELECT_2
//! - \b SYSCTL_CMPHNMUX_SELECT_3
//! - \b SYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPHNMuxValue(uint16_t select, uint16_t value)
{
    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) |= select;
    }
    else
    {
        //Do nothing. Not a valid value
    }
}

//*****************************************************************************
//
//! Select the value for individual CMPxLNMXSEL.
//!
//! \param select is a combination of CMPLNMXSEL values.
//!
//! The parameter \e select can be the bitwise OR of the below values:
//!
//! - \b SYSCTL_CMPLNMUX_SELECT_1
//! - \b SYSCTL_CMPLNMUX_SELECT_2
//! - \b SYSCTL_CMPLNMUX_SELECT_3
//! - \b SYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPLNMux(uint16_t select)
{
    //
    // Write a select to the mux select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) = select;
}

//*****************************************************************************
//
//! Select the value for CMPLNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b SYSCTL_CMPLNMUX_SELECT_1
//! - \b SYSCTL_CMPLNMUX_SELECT_2
//! - \b SYSCTL_CMPLNMUX_SELECT_3
//! - \b SYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPLNMuxValue(uint16_t select, uint16_t value)
{
    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) |= select;
    }
    else
    {
        //Do nothing. Not a valid value
    }
}

//*****************************************************************************
//
//! Select the value for CMPHPMXSEL.
//!
//! \param select is of type SYSCTL_CMPHPMuxSelect.
//! \param value is 0, 1, 2, 3, 4 or 5.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b SYSCTL_CMPHPMUX_SELECT_1
//! - \b SYSCTL_CMPHPMUX_SELECT_2
//! - \b SYSCTL_CMPHPMUX_SELECT_3
//! - \b SYSCTL_CMPHPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectCMPHPMux(SYSCTL_CMPHPMuxSelect select, uint32_t value)
{
    //
    // Set the value for the appropriate Mux Select.
    //
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHPMX_SEL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_CMPHPMX_SEL) &
        ~((uint32_t)SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M << (uint32_t)select)) |
        (value << (uint32_t)select);
}

//*****************************************************************************
//
//! Select the value for CMPLPMXSEL.
//!
//! \param select is of type SYSCTL_CMPLPMuxSelect.
//! \param value is 0, 1, 2, 3, 4 or 5.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b SYSCTL_CMPLPMUX_SELECT_1
//! - \b SYSCTL_CMPLPMUX_SELECT_2
//! - \b SYSCTL_CMPLPMUX_SELECT_3
//! - \b SYSCTL_CMPLPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectCMPLPMux(SYSCTL_CMPLPMuxSelect select, uint32_t value)
{
    //
    // Set the value for the appropriate Mux Select.
    //
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLPMX_SEL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_CMPLPMX_SEL) &
        ~((uint32_t)SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M << (uint32_t)select)) |
        (value << (uint32_t)select);
}

//*****************************************************************************
//
//! Locks the temperature sensor control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockTemperatureSensor(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_TSNSCTL;
}

//*****************************************************************************
//
//! Locks the analog reference control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockANAREF(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_ANAREFCTL;
}

//*****************************************************************************
//
//! Locks the voltage monitor control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockVMON(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_VMONCTL;
}

//*****************************************************************************
//
//! Locks the CMPHPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPHPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPHPMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPLPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPLPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPLPMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPHNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPHNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPHNMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPLNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPLNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPLNMXSEL;
}

//*****************************************************************************
//
//! Locks the VREG control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockVREG(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_VREGCTL;
}

//*****************************************************************************
//
//! Locks the CMPSSCTL register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPSSCTL(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPSSCTL;
}


//*****************************************************************************
//
//! Enable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static inline void SysCtl_enableADCDACLoopback(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) | config) |
            (0xA5A5UL << SYSCTL_ADCDACLOOPBACK_KEY_S);
}

//*****************************************************************************
//
//! Disable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCB
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static inline void SysCtl_disableADCDACLoopback(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) & ~config) |
            (0xA5A5UL << SYSCTL_ADCDACLOOPBACK_KEY_S);
}

static inline void SysCtl_configXIP(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) = (HWREG(
            SYSCTL_BASE + SYSCTL_O_MSPI_CFG) & (~0xF)) | config;
}

static inline void SysCtl_enableEPWMGlobalSync(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) = (HWREG(
            SYSCTL_BASE + SYSCTL_O_CTRL_SUB) & (~SYSCTL_CTRLSUB_EPWMGBCLKSYNC))
            | SYSCTL_CTRLSUB_EPWMGBCLKSYNC;
}

static inline void SysCtl_disableEPWMGlobalSync(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) = (HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) & (~SYSCTL_CTRLSUB_EPWMGBCLKSYNC));
}

static inline void SysCtl_setSPIxMode(uint32_t modeControl)
{
    uint32_t regOffset;
    regOffset = (modeControl >> 8);
    HWREG(SYSCTL_BASE + regOffset) = (modeControl & 0x1);
}

static inline void SysCtl_setECAPxSyncInPulseSource(uint32_t ECAPx_base,ECAP_SYNCISource source)
{
    switch(ECAPx_base)
    {
        case ECAP1_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP1_SYNCSEL) = source;
            break;
        case ECAP2_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP2_SYNCSEL) = source;
            break;
        case ECAP3_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP3_SYNCSEL) = source;
            break;
        default:
            break;
    }
}

//*****************************************************************************
//
//! Set IO to QSPI
//
//*****************************************************************************
static inline void SysCtl_setQSPIIOEnable(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) |= SYSCTL_MSPI_IO_EN;
}

//*****************************************************************************
//
//! Set IO to XFlashc
//
//*****************************************************************************
static inline void SysCtl_setXFCIOEnable(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) &= ~SYSCTL_MSPI_IO_EN;
}

//*****************************************************************************
//
//! Configures the sync output source.
//!
//! \param syncSrc is sync output source selection.
//!
//! This function configures the sync output source from the ePWM modules. The
//! \e syncSrc parameter is a value \b SYSCTL_SYNC_OUT_SRC_XXXX, where XXXX is
//! a sync signal coming from an ePWM such as SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setSyncOutputConfig(SysCtl_SyncOutputSource syncSrc)
{
    //
    // Write the sync output source selection to the appropriate register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_SYNC_SELECT) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_SYNC_SELECT)
                    & ~((uint32_t) SYSCTL_SYNCSELECT_SYNCOUT_M))
                    | ((uint32_t) syncSrc << SYSCTL_SYNCSELECT_SYNCOUT_S);

}

//*****************************************************************************
//
//! Enables ePWM SOC signals to drive an external (off-chip) ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be enabled
//!
//! This function configures which ePWM SOC signals are enabled as a source for
//! either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical OR
//! of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_enableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Set the bits that correspond to signal to be enabled.
    //
    uint32_t offset;
    uint32_t source;
    if (adcsocSrc > 0x1000)
    {
        offset = SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL;
        source = adcsocSrc >> 16;
    }
    else
    {
        offset = SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL;
        source = adcsocSrc;
    }
    HWREG(SYSCTL_BASE + offset) |= source;
}

//*****************************************************************************
//
//! Disables ePWM SOC signals from driving an external ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be disabled
//!
//! This function configures which ePWM SOC signals are disabled as a source
//! for either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical
//! OR of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_disableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Clear the bits that correspond to signal to be disabled.
    //
    uint32_t offset;
    uint32_t source;
    if (adcsocSrc > 0x1000)
    {
        offset = SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL;
        source = adcsocSrc >> 16;
    }
    else
    {
        offset = SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL;
        source = adcsocSrc;
    }
    HWREG(SYSCTL_BASE + offset) &= ~source;
}

//*****************************************************************************
//
//! Locks the SOC Select of the Trig X-BAR.
//!
//! This function locks the external ADC SOC select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockExtADCSOCSelect(void)
{
    HWREG(SYSCTL_BASE+ SYSCTL_O_SYNCSOC_LOCK) |= SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_M;
}

//*****************************************************************************
//
//! Locks the Sync Select of the Trig X-BAR.
//!
//! This function locks Sync Input and Output Select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockSyncSelect(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SYNCSOC_LOCK) |= SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_M;
}

//*****************************************************************************
//
//! Set the Option Bytes Source.
//!
//! This function sets the source of option byte.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setOBSource(SysCtl_OBSourece source)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_OB_SEL) = source;
}

//*****************************************************************************
//
//! Set wwdg stop or continue in the Debug mode.
//!
//! This function controls the wwdg in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgWwdgStop(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_WWDG_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_WWDG_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm sleep in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmSleep(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_SLEEP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_SLEEP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm stop in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmStop(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm standby in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmStandby(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set GPIOx debounce counting period.
//!
//! GPIOx debounce counting period, one set (32 GPIO ports) shares one value
//! GPIOx should be 0~5
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxDebounceVal(uint32_t GPIOx , uint32_t debounce_val)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_DEBOUNCE_VAL + GPIOx*4) = debounce_val;
}

//*****************************************************************************
//
//! Set GPIOx Qualification Period
//!
//! GPIO qualification period. Each GPIO port uses 8 bits. Only GPIO port 0 to 95 (the first three sets of GPIO) have this function.
//!
//! 0x0: Sampling window = 1 / PCLK
//! 0x1 ~ 0xFF: Sampling window = 2 * [qual_prd] * 1 / PCLK
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxQualPRDx(uint32_t gpio_pin , uint8_t debounce_val)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 4;
    shift = gpio_pin % 4;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_QUAL_PRDx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_QUAL_PRDx + offset*4)
                    & ~(0xFF << (shift * 8))) | debounce_val << (shift * 8);
}

//*****************************************************************************
//
//! Set GPIOx Qualification Mode
//!
//! GPIO qualification mode. Each GPIO port uses 2 bits. Only GPIO ports 0 to 95 (the first three GPIO groups) have this function.
//!
//! 0b00: Synchronous to PCLK
//! 0b01: Synchronous (3-sample window)
//! 0b10: Synchronous (6-sample window)
//! 0b11: Asynchronous
//!
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxQualMODEx(uint32_t gpio_pin , SysCtl_GPIOxQualificationMode mode)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 16;
    shift = gpio_pin % 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_QUAL_MODEx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_QUAL_MODEx + offset*4)
                    & ~(0x3 << (shift * 2))) | mode << (shift * 2);
}

//*****************************************************************************
//
//! Set GPIOx input inversion.
//!
//! GPIO input inversion enable. Only GPIO ports 0 to 95 (the first three GPIO groups) have this function.
//! 1: Inverted
//! 0: Not inverted
//!
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxInputINV(uint32_t gpio_pin , FunctionalState NewState)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState != ENABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4) |= (0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4) =
                ( HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4)
                        & ~(0x1 << shift));
    }
}

//*****************************************************************************
//
//! Set GPIOx Pull up/down ENABLE.
//!
//! PAD pull-up/pull-down resistor enable. Must be used in conjunction with PS to select pull-up or pull-down.
//! 1: Enabled
//! 0: Disabled
//!
//! gpio_pin = 0~128
//!
//! PAD28/32, PAD210~212 default to pull-up; PAD213 defaults to pull-down; all others default to no pull-up/pull-down.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxPullEnable(uint32_t gpio_pin , FunctionalState NewState)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PEx + offset*4) |= (0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PEx + offset*4) &= ~(0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx Pull up/down.
//!
//! PAD pull-up/pull-down resistor selection. Effective when PEx is set to 1.
//! 1: Pull-up
//! 0: Pull-down
//!
//! gpio_pin = 0~128
//!
//! PAD28/32, PAD210~212 default to pull-up; PAD213 defaults to pull-down; all others default to no pull-up/pull-down.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxPullSel(uint32_t gpio_pin , SysCtl_GPIOxUPorDOWN NewState)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState == GPIOx_PULL_DOWN)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PSx + offset*4) &= ~(0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PSx + offset*4) |= (0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx input mode.
//!
//! PAD input mode selection:
//!
//! 1: Buffer Input
//! 0: Schmitt Input
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxIuputMode(uint32_t gpio_pin , SysCtl_GPIOxInputMode mode)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(mode == GPIOx_INPUT_SCHMITT)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_ISx + offset*4) &= ~(0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_ISx + offset*4) |= (0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx input mode.
//!
//! PAD input mode selection:
//!
//! 1: Buffer Input
//! 0: Schmitt Input
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxDriverStrength(uint32_t gpio_pin , SysCtl_GPIOxDriveStrength strength)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 16;
    shift = gpio_pin % 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_DRx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_DRx + offset*4)
                    & ~(0x3 << (shift * 2))) | strength << (shift * 2);
}

//*****************************************************************************
//!
//! Set GPIOC Analog mode.
//!
//! PAD analog mode enable.
//! Only PAD64 to PAD95 have this function, with each PAD occupying 1 bit.
//! Analog mode is enabled by default.
//!
//! 1: Analog mode
//! 0: Digital mode
//! In analog mode, the PAD's IE, OE, and DOUT are fixed at 0.
//!
//! gpio_pin = 64~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOCAMSEL(uint32_t gpio_pin , SysCtl_GPIOCAMSEL amsel)
{
    uint32_t shift;
    shift = gpio_pin  - 160;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOC_AMSEL) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIOC_AMSEL)
                    & ~(0x1 << shift)) | (amsel << shift);
}

static inline void SysCtl_setExtiWakeUp(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_EXTI_WK_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_EXTI_WK_EN) &= ~(0x1);
    }
}

static inline void SysCtl_setEQEP1Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline void SysCtl_setEQEP2Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline void SysCtl_setEQEP3Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline uint32_t SysCtl_getTIMxStatus(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_TIMERx_STAT);
}

static inline void SysCtl_setCPUDebugMode(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WWDG_DBG_CFG) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WWDG_DBG_CFG) &= ~(0x1);
    }
}

static inline void SysCtl_setDccNMIIRQ(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) &= ~(0x1);
    }
}

static inline void SysCtl_setAGIOCTRLLOCK(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) &= ~(0x1);
    }
}

static inline void SysCtl_enableVMON(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_VMON_CTL) |= (0x1);
}

static inline void SysCtl_disableVMON(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_VMON_CTL) &= ~(0x1);
}

static inline void SysCtl_enableNMI(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CORE_NMI_WK_EN) = SYSCTL_CORE1_NMI_WK_EN;
}

static inline void SysCtl_disableNMI(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CORE_NMI_WK_EN) = SYSCTL_CORE1_NMI_WK_DIS;
}

static inline void SysCtl_setAGPIOCTRLA(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_AGPIO_CTRLA) = config;
}

static inline void SysCtl_setSMCMHWINT(uint8_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SMCM_HWINT) = config;
}

static inline void SysCtl_setTIMERxCHxPRESC(SysCtl_TIMERx gtimx, uint32_t presc)
{
    uint32_t offset;
    uint32_t shift;
    offset = gtimx / 2;
    shift = (gtimx % 2) * 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_TIM1_PRESC + offset) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_TIM1_PRESC + offset)
                    & (0xFFFF << shift)) | (presc << shift);
}

static inline void SysCtl_setWDTSpeedUp(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WDG_SPEED_UP) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WDG_SPEED_UP) &= ~(0x1);
    }
}

static inline uint32_t SysCtl_getSMCMECCError(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_SMCM_ECC_ERR);
}

static inline uint32_t SysCtl_getErrorStatus(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_STAT);
}

static inline void SysCtl_clearErrorStatus(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_STAT_CLR) |= 0x1;
}

static inline void SysCtl_forceErrorStatus(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SRROR_STAT_FRC) |= 0x1;
}

static inline void SysCtl_setErrorConfig(uint32_t conifg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_CTL) |= 0x1;
}

static inline void SysCtl_setErrorLock(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_LOCK) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_LOCK) &= ~(0x1);
    }
}

static inline void SysCtl_setCMPSSConfig(uint32_t cmpssConfig)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPSS_CFG) = cmpssConfig;
}

static inline void SysCtl_setDACCConfig(uint32_t dacConfig)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_DACC_CFG) = dacConfig;
}

static inline void SysCtl_setXFLASHCConfig(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_XFLASHC) = config & 0x7;
}


#elif SYSCTL_HW_VER == 2
/* RP65 */


typedef struct
{
    __IO uint32_t IO_REUSE0; /* offset 10 */
    __IO uint32_t IO_REUSE1; /* offset 14 */
    __IO uint32_t IO_REUSE2; /* offset 18 */
    __IO uint32_t IO_REUSE3; /* offset 1c */
    __IO uint32_t IO_REUSE4; /* offset 20 */
    __IO uint32_t IO_REUSE5; /* offset 24 */
    __IO uint32_t IO_REUSE6; /* offset 28 */
    __IO uint32_t IO_REUSE7; /* offset 2c */
    __IO uint32_t IO_REUSE8; /* offset 30 */
    __IO uint32_t IO_REUSE9; /* offset 34 */
    __IO uint32_t IO_REUSE10; /* offset 38 */
    __IO uint32_t IO_REUSE11; /* offset 3c */
    __IO uint32_t IO_REUSE12; /* offset 40 */
    __IO uint32_t IO_REUSE13; /* offset 44 */
    __IO uint32_t IO_REUSE14; /* offset 48 */
    __IO uint32_t IO_REUSE15; /* offset 4c */
    __IO uint32_t IO_REUSE16; /* offset 50 */
    __IO uint32_t IO_REUSE17; /* offset 54 */
    __IO uint32_t QSPI_XIP; /* offset 58 */
    __IO uint32_t ADC_TRIG_SEL; /* offset 5c */
} SYSCTL_TypeDef;

//
// OSCSTATUS value on completion
//
#define SYSCTL_EXTR_ENABLE_COMPLETE (0xE7U)

//*****************************************************************************
//
// Defines used for setting AnalogReference functions.
// SYSCTL_setAnalogReferenceInternal()
// SYSCTL_setAnalogReferenceExternal()
// SYSCTL_setAnalogReference2P5()
// SYSCTL_setAnalogReference1P65()
//
//*****************************************************************************
#define SYSCTL_VREFHI  0x1U //!< VREFHI

//*****************************************************************************
//
// Values used for function SYSCTL_enableCMPSSExternalDAC() and
// SYSCTL_disableCMPSSExternalDAC().  These values can be OR-ed together and
// passed these functions.
//
//*****************************************************************************
#define SYSCTL_CMPSS1_DACL 0x1U //!< CMPSS1.DACL

//*****************************************************************************
//
// Values used for function SYSCTL_selectCMPHNMux() and
// SYSCTL_selectCMPHNMuxValue().  These values can be OR-ed together and
// passed to SYSCTL_selectCMPHNMux().
//
//*****************************************************************************
#define SYSCTL_CMPHNMUX_SELECT_1 0x1U //!< CMPHNMUX select 1
#define SYSCTL_CMPHNMUX_SELECT_2 0x2U //!< CMPHNMUX select 2
#define SYSCTL_CMPHNMUX_SELECT_3 0x4U //!< CMPHNMUX select 3
#define SYSCTL_CMPHNMUX_SELECT_4 0x8U //!< CMPHNMUX select 4

//*****************************************************************************
//
// Values used for function SYSCTL_selectCMPLNMux() and
// SYSCTL_selectCMPLNMuxValue().  These values can be OR-ed together and
// passed to SYSCTL_selectCMPLNMux().
//
//*****************************************************************************
#define SYSCTL_CMPLNMUX_SELECT_1 0x1U //!< CMPLNMUX select 1
#define SYSCTL_CMPLNMUX_SELECT_2 0x2U //!< CMPLNMUX select 2
#define SYSCTL_CMPLNMUX_SELECT_3 0x4U //!< CMPLNMUX select 3
#define SYSCTL_CMPLNMUX_SELECT_4 0x8U //!< CMPLNMUX select 4

//*****************************************************************************
//
//! SYSCTL_CMPHPMuxSelect used for function SYSCTL_selectCMPHPMux().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CMPHPMUX_SELECT_1 = 0U, //!< CMPHPMUX select 1
    SYSCTL_CMPHPMUX_SELECT_2 = 3U, //!< CMPHPMUX select 2
    SYSCTL_CMPHPMUX_SELECT_3 = 6U, //!< CMPHPMUX select 3
    SYSCTL_CMPHPMUX_SELECT_4 = 9U  //!< CMPHPMUX select 4
} SYSCTL_CMPHPMuxSelect;

//*****************************************************************************
//
//! SYSCTL_CMPLPMuxSelect used for function SYSCTL_selectCMPLPMux().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CMPLPMUX_SELECT_1 = 0U, //!< CMPLPMUX select 1
    SYSCTL_CMPLPMUX_SELECT_2 = 3U, //!< CMPLPMUX select 2
    SYSCTL_CMPLPMUX_SELECT_3 = 6U, //!< CMPLPMUX select 3
    SYSCTL_CMPLPMUX_SELECT_4 = 9U  //!< CMPLPMUX select 4
} SYSCTL_CMPLPMuxSelect;

//*****************************************************************************
//
//! SYSCTL_TestSelect used for function SYSCTL_selectInternalTestNode().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_TEST_NODE_NO_CONN       = 0U,  //!< No Internal Connection
    SYSCTL_TEST_NODE_VDDCORE         = 1U,  //!< Core VDD (1.2V) voltage
    SYSCTL_TEST_NODE_VREFLO              = 2U,  //!< VREFLO pin voltage
    SYSCTL_TEST_NODE_CDAC1H              = 4U,  //!< CMPSS1 High DAC output
    SYSCTL_TEST_NODE_CDAC1L              = 5U,  //!< CMPSS1 Low DAC output
    SYSCTL_TEST_NODE_CDAC2H              = 6U,  //!< CMPSS2 High DAC output
    SYSCTL_TEST_NODE_CDAC2L              = 7U,  //!< CMPSS2 Low DAC output
    SYSCTL_TEST_NODE_CDAC3H              = 8U,  //!< CMPSS3 High DAC output
    SYSCTL_TEST_NODE_CDAC3L              = 9U,  //!< CMPSS3 Low DAC output
    SYSCTL_TEST_NODE_CDAC4H              = 10U, //!< CMPSS4 High DAC output
    SYSCTL_TEST_NODE_CDAC4L              = 11U, //!< CMPSS4 Low DAC output
    SYSCTL_TEST_NODE_VDDA                = 12U, //!< VDDA voltage
    SYSCTL_TEST_NODE_VSSA                = 13U, //!< VSSA - Analog ground pin
    SYSCTL_TEST_NODE_ENZ_CALIB_GAIN_3P3V = 19U //!< All ADCs are placed in gain
                                                //!< calibration mode
} SYSCTL_TestSelect;

//*****************************************************************************
//
//! Values that set the source of ECAP SYNCI
//! parameter.
//
//*****************************************************************************
typedef enum
{

    ECAP_DISABLESYNCI   = 0x0U,
    ECAP_EPWM1SYNCOUT   = 0x1U,
    ECAP_EPWM2SYNCOUT   = 0x2U,
    ECAP_EPWM3SYNCOUT   = 0x3U,
    ECAP_EPWM4SYNCOUT   = 0x4U,
    ECAP_EPWM5SYNCOUT   = 0x5U,
    ECAP_EPWM6SYNCOUT   = 0x6U,
    ECAP_EPWM7SYNCOUT   = 0x7U,
    ECAP_EPWM8SYNCOUT   = 0x8U,
    ECAP_ECAP1SYNCOUT   = 0x11,
    ECAP_ECAP2SYNCOUT   = 0x12,
    ECAP_ECAP3SYNCOUT   = 0x13,
    ECAP_INPUTXBAROUT5  = 0x18,
    ECAP_INPUTXBAROUT6  = 0x19,
    ECAP_FSI_RXA_RX_TRIG1 = 0x1F,
}ECAP_SYNCISource;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! Resets a peripheral
//!
//! \param peripheral is the peripheral to reset.
//!
//! This function uses the SOFTPRESx registers to reset a specified peripheral.
//! Module registers will be returned to their reset states.
//!
//! \note This includes registers containing trim values.The peripheral
//! software reset needed by CPU2 can be communicated to CPU1 via
//! IPC for all shared peripherals.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_resetPeripheral(SysCtl_PeripheralSOFTPRES peripheral)
{
    uint32_t regIndex;
    uint32_t bitIndex;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    HWREG(RCC_BASE + regIndex) |= (1U << bitIndex);
    HWREG(RCC_BASE + regIndex) &= ~(1U << bitIndex);
}

//*****************************************************************************
//
//! Enables a peripheral.
//!
//! \param peripheral is the peripheral to enable.
//!
//! Peripherals are enabled with this function.  At power-up, all peripherals
//! are disabled; they must be enabled in order to operate or respond to
//! register reads/writes.
//!
//! \note Note that there should be atleast 5 cycles delay between enabling the
//! peripheral clock and accessing the peripheral registers. The delay should be
//! added by the user if the peripheral is accessed immediately after this
//! function call.
//! Use asm(" RPT #5 || NOP"); to add 5 cycle delay post this function call.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_enablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint32_t IPIndex;
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t IP_BASE;
    IPIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_IP_M)
            >> SYSCTL_PERIPH_IP_S;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    if (IPIndex == 0)
    {
        IP_BASE = SYSCTL_BASE;
    }
    else
    {
        IP_BASE = RCC_BASE;
    }
    HWREG(IP_BASE + regIndex) |= (1U << bitIndex);
}

//*****************************************************************************
//
//! Disables a peripheral.
//!
//! \param peripheral is the peripheral to disable.
//!
//! Peripherals are disabled with this function.  Once disabled, they will not
//! operate or respond to register reads/writes.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_disablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint32_t IPIndex;
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t IP_BASE;
    IPIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_IP_M)
            >> SYSCTL_PERIPH_IP_S;
    regIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_REG_M)
            >> SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t) peripheral & (uint32_t) SYSCTL_PERIPH_BIT_M)
            >> SYSCTL_PERIPH_BIT_S;
    if (IPIndex == 0)
    {
        IP_BASE = SYSCTL_BASE;
    }
    else
    {
        IP_BASE = RCC_BASE;
    }
    HWREG(IP_BASE + regIndex) &= ~(1U << bitIndex);
}

//*****************************************************************************
//
//! Resets the device.
//!
//! This function performs a software reset of the device.
//!
//! \return This function does not return.
//
//*****************************************************************************
static inline void
SysCtl_resetDevice(void)
{

}

//*****************************************************************************
//
//! Enable temperature sensor.
//!
//! This function enables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableTemperatureSensor(void)
{
    //
    // Set the temperature sensor enable bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_TSNS_CTL) |= SYSCTL_TSNSCTL_ENABLE;
}

//*****************************************************************************
//
//! Disable temperature sensor.
//!
//! This function disables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableTemperatureSensor(void)
{
    //
    // Clear the temperature sensor enable bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_TSNS_CTL) &= ~(SYSCTL_TSNSCTL_ENABLE);
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to internal.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \note Internal reference mode is not available for packages lacking VREFHI
//! and VREFLO pins. Please see device datasheet for packages with VREFHI and
//! VREFLO pins available.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setAnalogReferenceInternal(uint16_t reference)
{
    //
    // Write selection to the Analog Internal Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) &= ~reference;
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to external.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setAnalogReferenceExternal(uint16_t reference)
{
    //
    // Write selection to the Analog External Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) |= reference;
}

//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 2.5V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setAnalogReference2P5(uint16_t reference)
{
    //
    // Write selection to the Analog Voltage Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) |= (reference << 8U);

    HWREG(ADCA_BASE + 0xF0) &= ~(0x1000);
    HWREG(ADCB_BASE + 0xF0) &= ~(0x1000);
    HWREG(ADCC_BASE + 0xF0) &= ~(0x1000);
}

//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 1.65V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b SYSCTL_VREFHI
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setAnalogReference1P65(uint16_t reference)
{
    //
    // Write selection to the Analog Voltage Reference Select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANAREF_CTL) &= ~(reference << 8U);

    HWREG(ADCA_BASE + 0xF0) |= 0x1000;
    HWREG(ADCB_BASE + 0xF0) |= 0x1000;
    HWREG(ADCC_BASE + 0xF0) |= 0x1000;
}

//*****************************************************************************
//
//! Select internal test node for ADC.
//!
//! \param testSelect is internal node to come out on ADC.
//!
//! The \e testSelect is the desired internal test node. Valid values can be
//! refered from the enum \e SYSCTL_TestSelect.
//!
//! \return None.
//!
//*****************************************************************************
static inline void SysCtl_selectInternalTestNode(SYSCTL_TestSelect testSelect)
{
    //
    // Select internal test node for ADC
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_INTERNAL_TEST_CTL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_INTERNAL_TEST_CTL) &
        ~(SYSCTL_INTERNALTESTCTL_TESTSEL_M | SYSCTL_INTERNALTESTCTL_KEY_M)) |
        (0xA5A50000UL | testSelect);
}

//*****************************************************************************
//
//! Select the value for CMPHNMXSEL.
//!
//! \param select is a combination of CMPHNMXSEL values.
//!
//! The parameter \e select can be a bitwise OR of the below values:
//!
//! - \b SYSCTL_CMPHNMUX_SELECT_1
//! - \b SYSCTL_CMPHNMUX_SELECT_2
//! - \b SYSCTL_CMPHNMUX_SELECT_3
//! - \b SYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPHNMux(uint16_t select)
{
    //
    // Write a select to the mux select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) = select;
}

//*****************************************************************************
//
//! Select the value for individual CMPxHNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b SYSCTL_CMPHNMUX_SELECT_1
//! - \b SYSCTL_CMPHNMUX_SELECT_2
//! - \b SYSCTL_CMPHNMUX_SELECT_3
//! - \b SYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPHNMuxValue(uint16_t select, uint16_t value)
{
    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHNMX_SEL) |= select;
    }
    else
    {
        //Do nothing. Not a valid value
    }
}

//*****************************************************************************
//
//! Select the value for individual CMPxLNMXSEL.
//!
//! \param select is a combination of CMPLNMXSEL values.
//!
//! The parameter \e select can be the bitwise OR of the below values:
//!
//! - \b SYSCTL_CMPLNMUX_SELECT_1
//! - \b SYSCTL_CMPLNMUX_SELECT_2
//! - \b SYSCTL_CMPLNMUX_SELECT_3
//! - \b SYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPLNMux(uint16_t select)
{
    //
    // Write a select to the mux select bit.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) = select;
}

//*****************************************************************************
//
//! Select the value for CMPLNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b SYSCTL_CMPLNMUX_SELECT_1
//! - \b SYSCTL_CMPLNMUX_SELECT_2
//! - \b SYSCTL_CMPLNMUX_SELECT_3
//! - \b SYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_selectCMPLNMuxValue(uint16_t select, uint16_t value)
{
    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLNMX_SEL) |= select;
    }
    else
    {
        //Do nothing. Not a valid value
    }
}

//*****************************************************************************
//
//! Select the value for CMPHPMXSEL.
//!
//! \param select is of type SYSCTL_CMPHPMuxSelect.
//! \param value is 0, 1, 2, 3, 4 or 5.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b SYSCTL_CMPHPMUX_SELECT_1
//! - \b SYSCTL_CMPHPMUX_SELECT_2
//! - \b SYSCTL_CMPHPMUX_SELECT_3
//! - \b SYSCTL_CMPHPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectCMPHPMux(SYSCTL_CMPHPMuxSelect select, uint32_t value)
{
    //
    // Set the value for the appropriate Mux Select.
    //
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPHPMX_SEL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_CMPHPMX_SEL) &
        ~((uint32_t)SYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M << (uint32_t)select)) |
        (value << (uint32_t)select);
}

//*****************************************************************************
//
//! Select the value for CMPLPMXSEL.
//!
//! \param select is of type SYSCTL_CMPLPMuxSelect.
//! \param value is 0, 1, 2, 3, 4 or 5.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b SYSCTL_CMPLPMUX_SELECT_1
//! - \b SYSCTL_CMPLPMUX_SELECT_2
//! - \b SYSCTL_CMPLPMUX_SELECT_3
//! - \b SYSCTL_CMPLPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectCMPLPMux(SYSCTL_CMPLPMuxSelect select, uint32_t value)
{
    //
    // Set the value for the appropriate Mux Select.
    //
        HWREG(SYSCTL_BASE + SYSCTL_O_CMPLPMX_SEL) =
        (HWREG(SYSCTL_BASE + SYSCTL_O_CMPLPMX_SEL) &
        ~((uint32_t)SYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M << (uint32_t)select)) |
        (value << (uint32_t)select);
}

//*****************************************************************************
//
//! Locks the temperature sensor control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockTemperatureSensor(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_TSNSCTL;
}

//*****************************************************************************
//
//! Locks the analog reference control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockANAREF(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_ANAREFCTL;
}

//*****************************************************************************
//
//! Locks the voltage monitor control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockVMON(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_VMONCTL;
}

//*****************************************************************************
//
//! Locks the CMPHPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPHPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPHPMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPLPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPLPMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPLPMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPHNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPHNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPHNMXSEL;
}

//*****************************************************************************
//
//! Locks the CMPLNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPLNMux(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPLNMXSEL;
}

//*****************************************************************************
//
//! Locks the VREG control register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockVREG(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_VREGCTL;
}

//*****************************************************************************
//
//! Locks the CMPSSCTL register.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockCMPSSCTL(void)
{
    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_ANALOG_SUB_LOCK) |= SYSCTL_LOCK_CMPSSCTL;
}


//*****************************************************************************
//
//! Enable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static inline void SysCtl_enableADCDACLoopback(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) | config) |
            (0xA5A5UL << SYSCTL_ADCDACLOOPBACK_KEY_S);
}

//*****************************************************************************
//
//! Disable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCB
//! - SYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static inline void SysCtl_disableADCDACLoopback(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_ADC_DAC_LOOP) & ~config) |
            (0xA5A5UL << SYSCTL_ADCDACLOOPBACK_KEY_S);
}

static inline void SysCtl_configXIP(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) = (HWREG(
            SYSCTL_BASE + SYSCTL_O_MSPI_CFG) & (~0xF)) | config;
}

static inline void SysCtl_enableEPWMGlobalSync(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) = (HWREG(
            SYSCTL_BASE + SYSCTL_O_CTRL_SUB) & (~SYSCTL_CTRLSUB_EPWMGBCLKSYNC))
            | SYSCTL_CTRLSUB_EPWMGBCLKSYNC;
}

static inline void SysCtl_disableEPWMGlobalSync(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) = (HWREG(SYSCTL_BASE + SYSCTL_O_CTRL_SUB) & (~SYSCTL_CTRLSUB_EPWMGBCLKSYNC));
}

static inline void SysCtl_setSPIxMode(uint32_t modeControl)
{
    uint32_t regOffset;
    regOffset = (modeControl >> 8);
    HWREG(SYSCTL_BASE + regOffset) = (modeControl & 0x1);
}

static inline void SysCtl_setECAPxSyncInPulseSource(uint32_t ECAPx_base,ECAP_SYNCISource source)
{
    switch(ECAPx_base)
    {
        case ECAP1_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP1_SYNCSEL) = source;
            break;
        case ECAP2_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP2_SYNCSEL) = source;
            break;
        case ECAP3_BASE:
            HWREG(SYSCTL_BASE + SYSCTL_O_ECAP3_SYNCSEL) = source;
            break;
        default:
            break;
    }
}

//*****************************************************************************
//
//! Set IO to QSPI
//
//*****************************************************************************
static inline void SysCtl_setQSPIIOEnable(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) |= SYSCTL_MSPI_IO_EN;
}

//*****************************************************************************
//
//! Set IO to XFlashc
//
//*****************************************************************************
static inline void SysCtl_setXFCIOEnable(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_MSPI_CFG) &= ~SYSCTL_MSPI_IO_EN;
}

//*****************************************************************************
//
//! Configures the sync output source.
//!
//! \param syncSrc is sync output source selection.
//!
//! This function configures the sync output source from the ePWM modules. The
//! \e syncSrc parameter is a value \b SYSCTL_SYNC_OUT_SRC_XXXX, where XXXX is
//! a sync signal coming from an ePWM such as SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setSyncOutputConfig(SysCtl_SyncOutputSource syncSrc)
{
    //
    // Write the sync output source selection to the appropriate register.
    //
    HWREG(SYSCTL_BASE + SYSCTL_O_SYNC_SELECT) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_SYNC_SELECT)
                    & ~((uint32_t) SYSCTL_SYNCSELECT_SYNCOUT_M))
                    | ((uint32_t) syncSrc << SYSCTL_SYNCSELECT_SYNCOUT_S);

}

//*****************************************************************************
//
//! Enables ePWM SOC signals to drive an external (off-chip) ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be enabled
//!
//! This function configures which ePWM SOC signals are enabled as a source for
//! either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical OR
//! of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_enableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Set the bits that correspond to signal to be enabled.
    //
    uint32_t offset;
    uint32_t source;
    if (adcsocSrc > 0x1000)
    {
        offset = SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL;
        source = adcsocSrc >> 16;
    }
    else
    {
        offset = SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL;
        source = adcsocSrc;
    }
    HWREG(SYSCTL_BASE + offset) |= source;
}

//*****************************************************************************
//
//! Disables ePWM SOC signals from driving an external ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be disabled
//!
//! This function configures which ePWM SOC signals are disabled as a source
//! for either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical
//! OR of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_disableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Clear the bits that correspond to signal to be disabled.
    //
    uint32_t offset;
    uint32_t source;
    if (adcsocSrc > 0x1000)
    {
        offset = SYSCTL_O_EPWM_ADC_SOCB_OUT_SEL;
        source = adcsocSrc >> 16;
    }
    else
    {
        offset = SYSCTL_O_EPWM_ADC_SOCA_OUT_SEL;
        source = adcsocSrc;
    }
    HWREG(SYSCTL_BASE + offset) &= ~source;
}

//*****************************************************************************
//
//! Locks the SOC Select of the Trig X-BAR.
//!
//! This function locks the external ADC SOC select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockExtADCSOCSelect(void)
{
    HWREG(SYSCTL_BASE+ SYSCTL_O_SYNCSOC_LOCK) |= SYSCTL_O_SYNCSOCLOCK_ADCSOCOUTSELECT_M;
}

//*****************************************************************************
//
//! Locks the Sync Select of the Trig X-BAR.
//!
//! This function locks Sync Input and Output Select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_lockSyncSelect(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SYNCSOC_LOCK) |= SYSCTL_O_SYNCSOCLOCK_SYNCSELECT_M;
}

//*****************************************************************************
//
//! Set the Option Bytes Source.
//!
//! This function sets the source of option byte.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setOBSource(SysCtl_OBSourece source)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_OB_SEL) = source;
}

//*****************************************************************************
//
//! Set wwdg stop or continue in the Debug mode.
//!
//! This function controls the wwdg in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgWwdgStop(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_WWDG_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_WWDG_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm sleep in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmSleep(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_SLEEP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_SLEEP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm stop in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmStop(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set lpm standby in the Debug mode.
//!
//! This function controls the lpm in the Debug mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setDbgLpmStandby(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) |= SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DBG_CTRL) &= ~SYSCTL_DBGCTRL_LPM_STOP_EN;
    }
}

//*****************************************************************************
//
//! Set GPIOx debounce counting period.
//!
//! GPIOx debounce counting period, one set (32 GPIO ports) shares one value
//! GPIOx should be 0~5
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxDebounceVal(uint32_t GPIOx , uint32_t debounce_val)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_DEBOUNCE_VAL + GPIOx*4) = debounce_val;
}

//*****************************************************************************
//
//! Set GPIOx Qualification Period
//!
//! GPIO qualification period. Each GPIO port uses 8 bits. Only GPIO port 0 to 95 (the first three sets of GPIO) have this function.
//!
//! 0x0: Sampling window = 1 / PCLK
//! 0x1 ~ 0xFF: Sampling window = 2 * [qual_prd] * 1 / PCLK
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxQualPRDx(uint32_t gpio_pin , uint8_t debounce_val)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 4;
    shift = gpio_pin % 4;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_QUAL_PRDx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIOx_QUAL_PRDx + offset*4)
                    & ~(0xFF << (shift * 8))) | debounce_val << (shift * 8);
}

//*****************************************************************************
//
//! Set GPIOx Qualification Mode
//!
//! GPIO qualification mode. Each GPIO port uses 2 bits. Only GPIO ports 0 to 95 (the first three GPIO groups) have this function.
//!
//! 0b00: Synchronous to PCLK
//! 0b01: Synchronous (3-sample window)
//! 0b10: Synchronous (6-sample window)
//! 0b11: Asynchronous
//!
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxQualMODEx(uint32_t gpio_pin , SysCtl_GPIOxQualificationMode mode)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 16;
    shift = gpio_pin % 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_QUAL_MODEx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_QUAL_MODEx + offset*4)
                    & ~(0x3 << (shift * 2))) | mode << (shift * 2);
}

//*****************************************************************************
//
//! Set GPIOx input inversion.
//!
//! GPIO input inversion enable. Only GPIO ports 0 to 95 (the first three GPIO groups) have this function.
//! 1: Inverted
//! 0: Not inverted
//!
//! gpio_pin = 0~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxInputINV(uint32_t gpio_pin , FunctionalState NewState)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState != ENABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4) |= (0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4) =
                ( HWREG(SYSCTL_BASE + SYSCTL_O_INPUT_INVx + offset*4)
                        & ~(0x1 << shift));
    }
}

//*****************************************************************************
//
//! Set GPIOx Pull up/down ENABLE.
//!
//! PAD pull-up/pull-down resistor enable. Must be used in conjunction with PS to select pull-up or pull-down.
//! 1: Enabled
//! 0: Disabled
//!
//! gpio_pin = 0~128
//!
//! PAD28/32, PAD210~212 default to pull-up; PAD213 defaults to pull-down; all others default to no pull-up/pull-down.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxPullEnable(uint32_t gpio_pin , FunctionalState NewState)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PEx + offset*4) |= (0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PEx + offset*4) &= ~(0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx Pull up/down.
//!
//! PAD pull-up/pull-down resistor selection. Effective when PEx is set to 1.
//! 1: Pull-up
//! 0: Pull-down
//!
//! gpio_pin = 0~128
//!
//! PAD28/32, PAD210~212 default to pull-up; PAD213 defaults to pull-down; all others default to no pull-up/pull-down.
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxPullSel(uint32_t gpio_pin , SysCtl_GPIOxUPorDOWN NewState)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(NewState == GPIOx_PULL_DOWN)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PSx + offset*4) &= ~(0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_PSx + offset*4) |= (0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx input mode.
//!
//! PAD input mode selection:
//!
//! 1: Buffer Input
//! 0: Schmitt Input
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxIuputMode(uint32_t gpio_pin , SysCtl_GPIOxInputMode mode)
{
    uint32_t offset,shift;

    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }

    offset = gpio_pin / 32;
    shift = gpio_pin % 32;
    if(mode == GPIOx_INPUT_SCHMITT)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_ISx + offset*4) &= ~(0x1 << shift);
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_ISx + offset*4) |= (0x1 << shift);
    }
}

//*****************************************************************************
//
//! Set GPIOx input mode.
//!
//! PAD input mode selection:
//!
//! 1: Buffer Input
//! 0: Schmitt Input
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOxDriverStrength(uint32_t gpio_pin , SysCtl_GPIOxDriveStrength strength)
{
    uint32_t offset,shift;
    if(gpio_pin > 63)
    {
        gpio_pin = gpio_pin - 160;
    }
    offset = gpio_pin / 16;
    shift = gpio_pin % 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_DRx + offset*4) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIO_DRx + offset*4)
                    & ~(0x3 << (shift * 2))) | strength << (shift * 2);
}

//*****************************************************************************
//!
//! Set GPIOC Analog mode.
//!
//! PAD analog mode enable.
//! Only PAD64 to PAD95 have this function, with each PAD occupying 1 bit.
//! Analog mode is enabled by default.
//!
//! 1: Analog mode
//! 0: Digital mode
//! In analog mode, the PAD's IE, OE, and DOUT are fixed at 0.
//!
//! gpio_pin = 64~95
//!
//! \return None.
//
//*****************************************************************************
static inline void SysCtl_setGPIOCAMSEL(uint32_t gpio_pin , SysCtl_GPIOCAMSEL amsel)
{
    uint32_t shift;
    shift = gpio_pin  - 160;
    HWREG(SYSCTL_BASE + SYSCTL_O_GPIOC_AMSEL) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_GPIOC_AMSEL)
                    & ~(0x1 << shift)) | (amsel << shift);
}

static inline void SysCtl_setExtiWakeUp(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_EXTI_WK_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_EXTI_WK_EN) &= ~(0x1);
    }
}

static inline void SysCtl_setEQEP1Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline void SysCtl_setEQEP2Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline void SysCtl_setEQEP3Config(uint32_t cfg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_EQEP1_CFG) = cfg;
}

static inline uint32_t SysCtl_getTIMxStatus(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_TIMERx_STAT);
}

static inline void SysCtl_setCPUDebugMode(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WWDG_DBG_CFG) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WWDG_DBG_CFG) &= ~(0x1);
    }
}

static inline void SysCtl_setDccNMIIRQ(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) &= ~(0x1);
    }
}

static inline void SysCtl_setAGIOCTRLLOCK(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_DCC_NMI_IRQ_EN) &= ~(0x1);
    }
}

static inline void SysCtl_enableVMON(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_VMON_CTL) |= (0x1);
}

static inline void SysCtl_disableVMON(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_VMON_CTL) &= ~(0x1);
}

static inline void SysCtl_enableNMI(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CORE_NMI_WK_EN) = SYSCTL_CORE1_NMI_WK_EN;
}

static inline void SysCtl_disableNMI(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CORE_NMI_WK_EN) = SYSCTL_CORE1_NMI_WK_DIS;
}

static inline void SysCtl_setAGPIOCTRLA(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_AGPIO_CTRLA) = config;
}

static inline void SysCtl_setSMCMHWINT(uint8_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SMCM_HWINT) = config;
}

static inline void SysCtl_setTIMERxCHxPRESC(SysCtl_TIMERx gtimx, uint32_t presc)
{
    uint32_t offset;
    uint32_t shift;
    offset = gtimx / 2;
    shift = (gtimx % 2) * 16;
    HWREG(SYSCTL_BASE + SYSCTL_O_TIM1_PRESC + offset) =
            (HWREG(SYSCTL_BASE + SYSCTL_O_TIM1_PRESC + offset)
                    & (0xFFFF << shift)) | (presc << shift);
}

static inline void SysCtl_setWDTSpeedUp(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WDG_SPEED_UP) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_WDG_SPEED_UP) &= ~(0x1);
    }
}

static inline uint32_t SysCtl_getSMCMECCError(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_SMCM_ECC_ERR);
}

static inline uint32_t SysCtl_getErrorStatus(void)
{
    return HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_STAT);
}

static inline void SysCtl_clearErrorStatus(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_STAT_CLR) |= 0x1;
}

static inline void SysCtl_forceErrorStatus(void)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_SRROR_STAT_FRC) |= 0x1;
}

static inline void SysCtl_setErrorConfig(uint32_t conifg)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_CTL) |= 0x1;
}

static inline void SysCtl_setErrorLock(FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_LOCK) |= 0x1;
    }
    else
    {
        HWREG(SYSCTL_BASE + SYSCTL_O_ERROR_LOCK) &= ~(0x1);
    }
}

static inline void SysCtl_setCMPSSConfig(uint32_t cmpssConfig)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_CMPSS_CFG) = cmpssConfig;
}

static inline void SysCtl_setDACCConfig(uint32_t dacConfig)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_DACC_CFG) = dacConfig;
}

static inline void SysCtl_setXFLASHCConfig(uint32_t config)
{
    HWREG(SYSCTL_BASE + SYSCTL_O_XFLASHC) = config & 0x7;
}

#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // SYS _H
