/** 
  *************************************************************************************
  * @file pto_pulsegen.c 
  * @author Albatross 
  * @brief This file contains the source file. 
  * @version 1.0.0 
  * @date 2025-07-30 
  *************************************************************************************
  * @copyright Copyright (c) 2025 Albatross  Semiconductor( Hangzhou ) Co ., Ltd . 
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

#include "stdint.h"
#include "pto_pulsegen.h"
#include "device.h"
#include "clb.h"

//*****************************************************************************
//
//! Setup CLB tiles
//!
//! \param None
//!
//! Setup the CLB and other interconnect XBARs used in this application.
//! This is called during the CLB initialization. This function needs to be
//! called after every system reset.
//!
//! \return None
//
//*****************************************************************************
void
pto_pulsegen_setupPeriph(void)
{
    pto_pulsegen_resetCLB();
    initTILE1_pul(CLB1_BASE);


    //
    // SW-controlled input select (GP_REG)
    //
    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_EXTERNAL);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_EXTERNAL);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_EXTERNAL);

    //
    // Input Filtering (Edge detects, or passthru)
    //
    CLB_selectInputFilter(CLB1_BASE, CLB_IN0, CLB_FILTER_NONE);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN1, CLB_FILTER_RISING_EDGE);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN2, CLB_FILTER_NONE);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN3, CLB_FILTER_NONE);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN4, CLB_FILTER_NONE);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN5, CLB_FILTER_NONE);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN6, CLB_FILTER_NONE);
    CLB_selectInputFilter(CLB1_BASE, CLB_IN7, CLB_FILTER_NONE);

    pto_pulsegen_initCLBXBAR();   // Initialize the CLB XBAR
}

//*****************************************************************************
//
//! Reset pulsegen
//!
//! \param None
//!
//! This function resets the pulsegen parameters set by earlier
//! configuration and start a fresh setup. The reset is done by calling the
//! reset CLB function.
//!
//! \return None
//
//*****************************************************************************
void
pto_pulsegen_reset(void)
{
    pto_pulsegen_resetCLB();
    CLB_setGPREG(CLB1_BASE, 0);
}

//*****************************************************************************
//
//! Run pulse generator by loading PTO options (pulses, period, duration
//! into HLC registers
//!
//! \param None
//! \param pulseLo is low pulse width
//! \param pulseHi is high pulse width
//! \param ptoActivePeriod is the period the pulses are sent out
//!        less than ptoFullPeriod
//! \param ptoFullPeriod is full PTO period
//! \param ptoInterruptTime is the time when the interrupt is generated to
//!        the CPU
//! \param ptoDirection is the output direction output. The output direction is
//!        latched at the beginning of new period
//! \param run is the run status. 1 indicates run and 0 is stop.
//!        This value is sampled at the beginning of the new period to determine
//!         to continue or halt the pulse generation
//!
//! This function is a runtime function to be called periodically
//! for dynamically configuring and changing the pulse generation requirements
//! as needed by the application
//!
//! \return ptoFullPeriod return the value, if the function is
//! executed successfully
//
//*****************************************************************************
uint16_t
pto_pulsegen_runPulseGen(uint32_t pulseLo, uint32_t pulseHi,
                            uint32_t ptoActivePeriod, uint32_t ptoFullPeriod,
                            uint32_t ptoInterruptTime, uint16_t ptoDirection,
                            uint16_t run)
{
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_HLC_R0, pulseLo - 1);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_HLC_R1, pulseLo + pulseHi - 1);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_HLC_R2, ptoActivePeriod - 1);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_HLC_R3, ptoFullPeriod - 1);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_2_MATCH1,
                       ptoInterruptTime - 1);
    CLB_setGPREG(CLB1_BASE,(run*6) + (ptoDirection*16) +1);
    return(ptoFullPeriod);
}

//*****************************************************************************
//
//! This function initiates the pulse generation.
//!
//! \param None
//!
//! This function must be called after pto_pulsegen_setupPeriph.
//! Hence, the pto_pulsegen_startOperation kick starts the pulse generation that
//! was set up earlier.
//!
//! \return None.
//
//*****************************************************************************
void
pto_pulsegen_startOperation(void)
{
	  CLB_enableCLB(CLB1_BASE);


    CLB_setGPREG(CLB1_BASE, 0x15);

}

//*****************************************************************************
//
//! Reset the CLB
//!
//! \param None
//!
//! This function configures Output-XBars to route CLB outputs to GPIO pins
//!
//! \return None
//
//*****************************************************************************
void
pto_pulsegen_resetCLB(void)
{
    //
    // Turn OFF the CLB functionality
    //
    CLB_setGPREG(CLB1_BASE, 0);

    CLB_disableCLB(CLB1_BASE);
    //
    // Clear Counters - this will clear counter REGs.
    // Add_shift_on_even_en should be Zero for this to take effect.
    //
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_0_LOAD, 0x0);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_1_LOAD, 0x0);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_2_LOAD, 0x0);

    //
    // Clear and reload the HLC registers
    //
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_HLC_R0, 0x9);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_HLC_R1, 0x0);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_1_MATCH1, 0x2);

}

//*****************************************************************************
//
//! Initialize the CLB XBAR-connect
//!
//! \param None
//!
//! This function configures Output-XBars to route CLB outputs to GPIO pins
//!
//! \return None
//
//*****************************************************************************
void
pto_pulsegen_initCLBXBAR(void) // see configuration for controlCARD
{
    //
    // Configure CLB1 o/p 4 and 5 to OUTPUT XBAR to OUTPUT3 and OUTPUT4
    // respectively
    //
    XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT1,XBAR_OUT_MUX05_CLB1_OUT5);
    XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT1, XBAR_MUX05);
    XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT2,XBAR_OUT_MUX06_CLB1_OUT6);
    XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT2, XBAR_MUX06);
}



uint16_t TILE1HLCInstr_pul[CLB_NUM_HLC_INSTR + 1] =
{
    TILE1_HLCINSTR_0,
    TILE1_HLCINSTR_1,
    TILE1_HLCINSTR_2,
    TILE1_HLCINSTR_3,
    TILE1_HLCINSTR_4,
    TILE1_HLCINSTR_5,
    TILE1_HLCINSTR_6,
    TILE1_HLCINSTR_7,
    TILE1_HLCINSTR_8,
    TILE1_HLCINSTR_9,
    TILE1_HLCINSTR_10,
    TILE1_HLCINSTR_11,
    TILE1_HLCINSTR_12,
    TILE1_HLCINSTR_13,
    TILE1_HLCINSTR_14,
    TILE1_HLCINSTR_15,
    TILE1_HLCINSTR_16,
    TILE1_HLCINSTR_17,
    TILE1_HLCINSTR_18,
    TILE1_HLCINSTR_19,
    TILE1_HLCINSTR_20,
    TILE1_HLCINSTR_21,
    TILE1_HLCINSTR_22,
    TILE1_HLCINSTR_23,
    TILE1_HLCINSTR_24,
    TILE1_HLCINSTR_25,
    TILE1_HLCINSTR_26,
    TILE1_HLCINSTR_27,
    TILE1_HLCINSTR_28,
    TILE1_HLCINSTR_29,
    TILE1_HLCINSTR_30,
    TILE1_HLCINSTR_31
};



void initTILE1_pul(uint32_t base)
{
    uint16_t i;
    // Output LUT
    CLB_configOutputLUT(base, CLB_OUT0, TILE1_CFG_OUTLUT_0);
    CLB_configOutputLUT(base, CLB_OUT1, TILE1_CFG_OUTLUT_1);
    CLB_configOutputLUT(base, CLB_OUT2, TILE1_CFG_OUTLUT_2);
    CLB_configOutputLUT(base, CLB_OUT3, TILE1_CFG_OUTLUT_3);
    CLB_configOutputLUT(base, CLB_OUT4, TILE1_CFG_OUTLUT_4);
    CLB_configOutputLUT(base, CLB_OUT5, TILE1_CFG_OUTLUT_5);
    CLB_configOutputLUT(base, CLB_OUT6, TILE1_CFG_OUTLUT_6);
    CLB_configOutputLUT(base, CLB_OUT7, TILE1_CFG_OUTLUT_7);
    // AOC
    CLB_configAOC(base, CLB_AOC0, TILE1_OUTPUT_COND_CTR_0);
    CLB_configAOC(base, CLB_AOC1, TILE1_OUTPUT_COND_CTR_1);
    CLB_configAOC(base, CLB_AOC2, TILE1_OUTPUT_COND_CTR_2);
    CLB_configAOC(base, CLB_AOC3, TILE1_OUTPUT_COND_CTR_3);
    CLB_configAOC(base, CLB_AOC4, TILE1_OUTPUT_COND_CTR_4);
    CLB_configAOC(base, CLB_AOC5, TILE1_OUTPUT_COND_CTR_5);
    CLB_configAOC(base, CLB_AOC6, TILE1_OUTPUT_COND_CTR_6);
    CLB_configAOC(base, CLB_AOC7, TILE1_OUTPUT_COND_CTR_7);

    // LUT4
    CLB_selectLUT4Inputs(base, TILE1_CFG_LUT4_IN0, TILE1_CFG_LUT4_IN1, TILE1_CFG_LUT4_IN2, TILE1_CFG_LUT4_IN3);
    CLB_configLUT4Function(base, TILE1_CFG_LUT4_FN10, TILE1_CFG_LUT4_FN2);

    // FSM
    CLB_selectFSMInputs(base, TILE1_CFG_FSM_EXT_IN0, TILE1_CFG_FSM_EXT_IN1, TILE1_CFG_FSM_EXTRA_IN0, TILE1_CFG_FSM_EXTRA_IN1);
    CLB_configFSMNextState(base, TILE1_CFG_FSM_NEXT_STATE_0, TILE1_CFG_FSM_NEXT_STATE_1, TILE1_CFG_FSM_NEXT_STATE_2);
    CLB_configFSMLUTFunction(base, TILE1_CFG_FSM_LUT_FN10, TILE1_CFG_FSM_LUT_FN2);

    // Counters
    CLB_selectCounterInputs(base, TILE1_CFG_COUNTER_RESET, TILE1_CFG_COUNTER_EVENT, TILE1_CFG_COUNTER_MODE_0, TILE1_CFG_COUNTER_MODE_1);
    CLB_configMiscCtrlModes(base, TILE1_CFG_MISC_CONTROL);
    CLB_configCounterLoadMatch(base, CLB_CTR0, TILE1_COUNTER_0_LOAD_VAL, TILE1_COUNTER_0_MATCH1_VAL, TILE1_COUNTER_0_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR1, TILE1_COUNTER_1_LOAD_VAL, TILE1_COUNTER_1_MATCH1_VAL, TILE1_COUNTER_1_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR2, TILE1_COUNTER_2_LOAD_VAL, TILE1_COUNTER_2_MATCH1_VAL, TILE1_COUNTER_2_MATCH2_VAL);
    CLB_configCounterTapSelects(base, TILE1_CFG_TAP_SEL);

    // HLC

    CLB_configHLCEventSelect(base,TILE1_HLC_EVENT_SEL);
    CLB_setHLCRegisters(base,TILE1_HLC_R0_INIT,TILE1_HLC_R1_INIT,TILE1_HLC_R2_INIT,TILE1_HLC_R3_INIT);

    for(i = 0;i <= CLB_NUM_HLC_INSTR;i++)
    {
    	CLB_programHLCInstruction(base,i,TILE1HLCInstr_pul[i]);
    }
}
//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//
// End of File
//
