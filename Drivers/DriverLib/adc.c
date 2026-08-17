/** 
 *************************************************************************************
 * @file adc.c
 * @brief This file implements the function of ADC driver.
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

#include "adc.h"
#include "sysctl.h"

//*****************************************************************************
//
// ADC_setVREF
//
//*****************************************************************************
void ADC_setVREF(ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage)
{
    uint32_t option_byte1;
    uint32_t vref;

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC3);

    EALLOW;

#if ADC_HW_VER == 0

    //
    // Configure the reference mode (internal or external).
    //
    if (refMode == ADC_REFERENCE_INTERNAL)
    {
        SysCtl_setAnalogReferenceInternal(SYSCTL_VREFHI);
        //
        // Configure the reference voltage (3.3V or 2.5V).
        //
        if (refVoltage == ADC_REFERENCE_3_3V)
        {
            SysCtl_setAnalogReference1P65(SYSCTL_VREFHI);
            vref = HWREG(OB_BASE + OB_VREF_1P65_O) & 0xFFFF;
        }
        else
        {
            SysCtl_setAnalogReference2P5(SYSCTL_VREFHI);
            vref = HWREG(OB_BASE + OB_VREF_2P5_O) & 0xFFFF;
        }
        option_byte1 = HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1);
        HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) = (option_byte1 & 0xFFFF)
                | (vref << 16);
    }
    else
    {
        SysCtl_setAnalogReferenceExternal(SYSCTL_VREFHI);
    }

    //
    // Set ADC offset trim for the all the ADC instances
    //
    ADC_setOffsetTrimAll(refVoltage);

#endif

    EDIS;
}

//*****************************************************************************
//
// ADC_setINLTrim
//
//*****************************************************************************
void ADC_setINLTrim(uint32_t base, ADC_ReferenceVoltage refVoltage)
{
    uint16_t i;
    int temp;
    int offsetValue;
    signed int offsetTrim1;
    signed int offsetTrim2;
    signed int compareValue;
    uint16_t value;
    (*((volatile unsigned int*) (0xe1000000)) |= (0x1));
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC1);
    HWREG(base + 0xF0) |= (0x1 << 10);
    HWREG(base + 0xF0) |= (0x1 << 6);

    temp = 0;
    value = 0;
    compareValue = 31;
    //
    // Configures the analog-to-digital converter module prescaler.
    //
    ADC_setPrescaler(base, ADC_CLK_DIV_4_0);
    //
    // Sets the timing of the end-of-conversion pulse
    //
    ADC_setInterruptPulseMode(base, ADC_PULSE_END_OF_CONV);
    //
    // Delay for 50ms to allow ADC time to power up
    //
    delay_ms(50);
    //
    // SOC Configuration: Setup ADC EPWM channel and trigger settings
    //
    // Disables SOC burst mode.
    //
    ADC_disableBurstMode(base);
    //
    // Sets the priority mode of the SOCs.
    //
    ADC_setSOCPriority(base, ADC_PRI_ALL_ROUND_ROBIN);
    //
    // Start of Conversion 0 Configuration
    //
    //
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 0
    //      Trigger         : ADC_TRIGGER_EPWM1_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 50 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
    //
    ADC_setupSOC(base, ADC_SOC_NUMBER0, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 16);
    ADC_setInterruptSOCTrigger(base, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
    //
    // ADC Interrupt 1 Configuration
    //      SOC/EOC number  : 0
    //      Interrupt Source: enabled
    //      Continuous Mode : disabled
    //
    ADC_setInterruptSource(base, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
    ADC_enableInterrupt(base, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(base, ADC_INT_NUMBER1);
    ADC_enableContinuousMode(base, ADC_INT_NUMBER1);
    //
    // Powers up the analog-to-digital converter core.
    //
    ADC_enableConverter(base);
    for (i = 0; i < 100; i++)
    {
        ADC_forceMultipleSOC(base, ADC_FORCE_SOC0);
        //
        // Wait for ADCA to complete, then acknowledge flag
        //
        while (ADC_getInterruptStatus(base, ADC_INT_NUMBER1) == false)
        {
        }
        ADC_clearInterruptStatus(base, ADC_INT_NUMBER1);
        temp += ADC_readResult((base - 0x100), ADC_SOC_NUMBER0);
    }
    offsetValue = temp / 100;

    //set offsetValue into ADCx
    offsetTrim1 = 2048 - offsetValue;
    offsetTrim2 = offsetValue - 2048;
    if ((offsetTrim1 > 31) || (offsetTrim2 > 31))
    {
        HWREG(base + 0xF0) &= ~(0x1 << 10);
        HWREG(base + 0xF0) &= ~(0x1 << 6);
        return;
    }
    HWREG(base + 0xF0) &= ~(0x3F);
    if (offsetTrim1 > 0)
    {
        value = 64 - offsetTrim1;
    }
    else
    {
        value = offsetTrim1;
    }
    switch (base)
    {
    case ADCA_BASE:
        SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_ADC1);
        break;
    case ADCB_BASE:
        SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_ADC2);
        break;
    case ADCC_BASE:
        SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_ADC3);
        break;
    }
    HWREG(base + 0xF0) &= ~(0x3F);
    if (offsetTrim1 > 0)
    {
        HWREG(base + 0xF0) |= value;
    }
    else
    {
        HWREG(base + 0xF0) |= value;
    }
    return;
}

//*****************************************************************************
//
// ADC_setOffsetTrim
//
//*****************************************************************************
void ADC_setOffsetTrim(uint32_t base, ADC_ReferenceVoltage refVoltage)
{
    uint32_t offsetVlaue;
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADC3);

#if ADC_HW_VER == 0

    switch (base)
    {
    case ADCA_BASE:
        if (refVoltage == ADC_REFERENCE_3_3V)
        {
            offsetVlaue = HWREG(OB_BASE + OB_ADCA_1P65_OFFSET_O);
        }
        else if(refVoltage == ADC_REFERENCE_2_5V)
        {
            offsetVlaue = HWREG(OB_BASE + OB_ADCA_2P5_OFFSET_O);
        }
        break;
    case ADCB_BASE:
        if (refVoltage == ADC_REFERENCE_3_3V)
          {
              offsetVlaue = HWREG(OB_BASE + OB_ADCB_1P65_OFFSET_O);
          }
          else if(refVoltage == ADC_REFERENCE_2_5V)
          {
              offsetVlaue = HWREG(OB_BASE + OB_ADCB_2P5_OFFSET_O);
          }
          break;
    case ADCC_BASE:
        if (refVoltage == ADC_REFERENCE_3_3V)
          {
              offsetVlaue = HWREG(OB_BASE + OB_ADCC_1P65_OFFSET_O);
          }
          else if(refVoltage == ADC_REFERENCE_2_5V)
          {
              offsetVlaue = HWREG(OB_BASE + OB_ADCC_2P5_OFFSET_O);

          }
          break;
    }
    if (offsetVlaue > 63)
    {
        return;
    }
    HWREG(base + 0xF0) &= ~(0x3F);
    HWREG(base + 0xF0) |= offsetVlaue;
#endif
}

//*****************************************************************************
//
// ADC_setOffsetTrimAll
//
//*****************************************************************************
void ADC_setOffsetTrimAll(ADC_ReferenceVoltage refVoltage)
{
    ADC_setOffsetTrim(ADCA_BASE,refVoltage);
    ADC_setOffsetTrim(ADCB_BASE,refVoltage);
    ADC_setOffsetTrim(ADCC_BASE,refVoltage);
}

//*****************************************************************************
//
// ADC_setPPBTripLimits
//
//*****************************************************************************
void ADC_setPPBTripLimits(uint32_t base, ADC_PPBNumber ppbNumber,
        int32_t tripHiLimit, int32_t tripLoLimit)
{
    uint32_t ppbHiOffset;
    uint32_t ppbLoOffset;

    //
    // Get the offset to the appropriate trip limit registers.
    //
    ppbHiOffset = (ADC_PPBxTRIPHI_STEP * (uint32_t) ppbNumber) +
    ADC_O_PPB1TRIPHI;
    ppbLoOffset = (ADC_PPBxTRIPLO_STEP * (uint32_t) ppbNumber) +
    ADC_O_PPB1TRIPLO;

    EALLOW;

    //
    // Set the trip high limit.
    //
    HWREG(base + ppbHiOffset) =
            (HWREG(base + ppbHiOffset) & ~ADC_PPBTRIP_MASK)
                    | ((uint32_t) tripHiLimit & ADC_PPBTRIP_MASK);

    //
    // Set the trip low limit.
    //
    HWREG(base + ppbLoOffset) =
            (HWREG(base + ppbLoOffset) & ~ADC_PPBTRIP_MASK)
                    | ((uint32_t) tripLoLimit & ADC_PPBTRIP_MASK);

    EDIS;
}
