/** 
  *************************************************************************************
  * @file pto_qepdiv.c 
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
#include "pto_qepdiv.h"
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
pto_qepdiv_setupPeriph(void)
{

    initTILE1_qepdiv(CLB1_BASE);
    initTILE2_qepdiv(CLB2_BASE);

    //
    // Set the various counter loads and match values.
    //
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_0_LOAD,
                       TILE1_COUNTER_0_LOAD_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_1_LOAD,
                       TILE1_COUNTER_1_LOAD_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_2_LOAD,
                       TILE1_COUNTER_2_LOAD_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_0_MATCH1,
                       TILE1_COUNTER_0_MATCH1_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_0_MATCH2,
                       TILE1_COUNTER_0_MATCH2_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_1_MATCH1,
                       TILE1_COUNTER_1_MATCH1_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_1_MATCH2,
                       TILE1_COUNTER_1_MATCH2_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_2_MATCH1,
                       TILE1_COUNTER_2_MATCH1_VAL);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_2_MATCH2,
                       TILE1_COUNTER_2_MATCH2_VAL);

    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_0_LOAD,
                       TILE2_COUNTER_0_LOAD_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_1_LOAD,
                       TILE2_COUNTER_1_LOAD_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_2_LOAD,
                       TILE2_COUNTER_2_LOAD_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_0_MATCH1,
                       TILE2_COUNTER_0_MATCH1_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_0_MATCH2,
                       TILE2_COUNTER_0_MATCH2_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_1_MATCH1,
                       TILE2_COUNTER_1_MATCH1_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_1_MATCH2,
                       TILE2_COUNTER_1_MATCH2_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_2_MATCH1,
                       TILE2_COUNTER_2_MATCH1_VAL);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_2_MATCH2,
                       TILE2_COUNTER_2_MATCH2_VAL);

//    pto_qepdiv_initCLBXBAR();   // Initialize the CLB XBAR
}

//*****************************************************************************
//
//! Configure the divider
//!
//! \param divider is value of the divider
//! \param indexWidth is the number of cycles for which the index pulse output
//!        is kept on
//!
//! This function configures the divider. The divider value cannot be changed
//! dynamically. Users must reset the module using pto_qepdiv_reset before
//! reconfiguring the functionality.
//!
//! \return divider ptoFullPeriod is the return value, if the function is
//! executed successfully
//
//*****************************************************************************

uint16_t
pto_qepdiv_config(uint16_t divider, uint16_t indexWidth)
{
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_0_MATCH2, divider * 4);
    CLB_writeInterface(CLB2_BASE, CLB_ADDR_COUNTER_0_MATCH1, divider * 2);
    CLB_writeInterface(CLB1_BASE, CLB_ADDR_COUNTER_2_MATCH1, indexWidth - 1);
    return(divider);
}

//*****************************************************************************
//
//! This function initiates the pulse generation.
//!
//! \param run parameters to be passed to start(1) or stop(0) the function
//!
//! This function initiates the pulse generation. This function must only be called after
//! pto_qepdiv_setupPeriph. Hence, the pto_qepdiv_startOperation function kick starts the pulse generation
//! that was set up earlier.
//!
//! \return None.
//
//*****************************************************************************
void
pto_qepdiv_startOperation(uint16_t run)
{
    EALLOW;
    CLB_enableCLB(CLB1_BASE);
    CLB_enableCLB(CLB2_BASE);


    CLB_setGPREG(CLB2_BASE, run);
    CLB_setGPREG(CLB1_BASE, run);
}

//*****************************************************************************
//
//! Reset the qepdiv parameters
//!
//! \param None
//!
//! This function resets the qepdiv parameters set by earlier configurations
//! and to begin a fresh setup. This function must be called in case the pulse
//! generation must be reset and started again at a later stage.
//!
//! \return None
//
//*****************************************************************************
void
pto_qepdiv_reset(void)
{
    pto_qepdiv_resetCLB();
    CLB_setGPREG(CLB1_BASE, 0);
    CLB_setGPREG(CLB2_BASE, 0);
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
pto_qepdiv_initCLBXBAR(void) // see configuration for controlCARD
{
	   XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT1,XBAR_OUT_MUX09_CLB2_OUT1);
	   XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT1, 9);

	   XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE, XBAR_OUTPUT2,XBAR_OUT_MUX11_CLB2_OUT3);
	   XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT2, 11);

	   XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT3,XBAR_OUT_MUX06_CLB1_OUT6);
	   XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT3, 6);

	   XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT4, XBAR_OUT_MUX05_CLB1_OUT5);
	   XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT4, 5);

	   XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT4, 40);
	   XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT5, 41);
	   XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT6, 31);
}


const uint32_t TILE1_HLC_initFIFOData_qepdiv[4] = {TILE1_HLC_FIFO0_INIT, TILE1_HLC_FIFO1_INIT, TILE1_HLC_FIFO2_INIT, TILE1_HLC_FIFO3_INIT};

uint16_t TILE1HLCInstr_qepdiv[CLB_NUM_HLC_INSTR + 1] =
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


const uint32_t TILE2_HLC_initFIFOData_qepdiv[4] = {TILE2_HLC_FIFO0_INIT, TILE2_HLC_FIFO1_INIT, TILE2_HLC_FIFO2_INIT, TILE2_HLC_FIFO3_INIT};

uint16_t TILE2HLCInstr_qepdiv[CLB_NUM_HLC_INSTR + 1] =
{
    TILE2_HLCINSTR_0,
    TILE2_HLCINSTR_1,
    TILE2_HLCINSTR_2,
    TILE2_HLCINSTR_3,
    TILE2_HLCINSTR_4,
    TILE2_HLCINSTR_5,
    TILE2_HLCINSTR_6,
    TILE2_HLCINSTR_7,
    TILE2_HLCINSTR_8,
    TILE2_HLCINSTR_9,
    TILE2_HLCINSTR_10,
    TILE2_HLCINSTR_11,
    TILE2_HLCINSTR_12,
    TILE2_HLCINSTR_13,
    TILE2_HLCINSTR_14,
    TILE2_HLCINSTR_15,
    TILE2_HLCINSTR_16,
    TILE2_HLCINSTR_17,
    TILE2_HLCINSTR_18,
    TILE2_HLCINSTR_19,
    TILE2_HLCINSTR_20,
    TILE2_HLCINSTR_21,
    TILE2_HLCINSTR_22,
    TILE2_HLCINSTR_23,
    TILE2_HLCINSTR_24,
    TILE2_HLCINSTR_25,
    TILE2_HLCINSTR_26,
    TILE2_HLCINSTR_27,
    TILE2_HLCINSTR_28,
    TILE2_HLCINSTR_29,
    TILE2_HLCINSTR_30,
    TILE2_HLCINSTR_31
};



void initTILE1_qepdiv(uint32_t base)
{
    uint16_t i;
    //
    //  Output LUT
    //
    CLB_configOutputLUT(base, CLB_OUT0, TILE1_CFG_OUTLUT_0);

    CLB_configOutputLUT(base, CLB_OUT1, TILE1_CFG_OUTLUT_1);

    CLB_configOutputLUT(base, CLB_OUT2, TILE1_CFG_OUTLUT_2);

    //
    //  Equation for Output Look-Up Table Block 3 for TILE1: 0
    //
    CLB_configOutputLUT(base, CLB_OUT3, TILE1_CFG_OUTLUT_3);

    //
    //  Equation for Output Look-Up Table Block 4 for TILE1: i0 & i1
    //
    CLB_configOutputLUT(base, CLB_OUT4, TILE1_CFG_OUTLUT_4);

    //
    //  Equation for Output Look-Up Table Block 5 for TILE1: i0
    //
    CLB_configOutputLUT(base, CLB_OUT5, TILE1_CFG_OUTLUT_5);
    
    CLB_configOutputLUT(base, CLB_OUT6, TILE1_CFG_OUTLUT_6);

    CLB_configOutputLUT(base, CLB_OUT7, TILE1_CFG_OUTLUT_7);

    //
    //  AOC
    //
    CLB_configAOC(base, CLB_AOC0, TILE1_OUTPUT_COND_CTR_0);
    CLB_configAOC(base, CLB_AOC1, TILE1_OUTPUT_COND_CTR_1);
    CLB_configAOC(base, CLB_AOC2, TILE1_OUTPUT_COND_CTR_2);
    CLB_configAOC(base, CLB_AOC3, TILE1_OUTPUT_COND_CTR_3);
    CLB_configAOC(base, CLB_AOC4, TILE1_OUTPUT_COND_CTR_4);
    CLB_configAOC(base, CLB_AOC5, TILE1_OUTPUT_COND_CTR_5);
    CLB_configAOC(base, CLB_AOC6, TILE1_OUTPUT_COND_CTR_6);
    CLB_configAOC(base, CLB_AOC7, TILE1_OUTPUT_COND_CTR_7);

    //
    // LUT 0 - 2 are configured as macros in clb_config.h; these macros are used in
    // CLB_selectLUT4Inputs and CLB_configLUT4Function
    //
    //
    //  Equation for Look-Up Table Block 1 for TILE1: (((~i0) & (~i1)) & i3) | (((~i0) & i1) & i2) | ((i0 & (~i1)) & i2) | ((i0 & i1) & i3) 
    //
    //  Equation for Look-Up Table Block 2 for TILE1: 0

    //
    //  LUT Configuration
    //
    CLB_selectLUT4Inputs(base, TILE1_CFG_LUT4_IN0, TILE1_CFG_LUT4_IN1, TILE1_CFG_LUT4_IN2, TILE1_CFG_LUT4_IN3);
    CLB_configLUT4Function(base, TILE1_CFG_LUT4_FN10, TILE1_CFG_LUT4_FN2);

    //
    // FSM 0 - 2 are configured in <file>
    //
    //
    //  Output equation for Finite State Machine 0 for TILE1: s0 | s1
    //  State 0 output equation for Finite State Machine 0 for TILE1: e0
    //  State 1 output equation for Finite State Machine 0 for TILE1: e1
    //
    //
    //  Output equation for Finite State Machine 1 for TILE1: s0 & s1
    //  State 0 output equation for Finite State Machine 1 for TILE1: ((~s0) & e0 & e1) | (s0 & (~e1) | e0) 
    //  State 1 output equation for Finite State Machine 1 for TILE1: s1
    //
    //
    //  Output equation for Finite State Machine 2 for TILE1: ~s0
    //  State 0 output equation for Finite State Machine 2 for TILE1: ((~s0) & e0) | (s0 & (~e1))
    //  State 1 output equation for Finite State Machine 2 for TILE1: s1
    //

    //
    //  FSM
    //
    CLB_selectFSMInputs(base, TILE1_CFG_FSM_EXT_IN0, TILE1_CFG_FSM_EXT_IN1, TILE1_CFG_FSM_EXTRA_IN0, TILE1_CFG_FSM_EXTRA_IN1);
    CLB_configFSMNextState(base, TILE1_CFG_FSM_NEXT_STATE_0, TILE1_CFG_FSM_NEXT_STATE_1, TILE1_CFG_FSM_NEXT_STATE_2);
    CLB_configFSMLUTFunction(base, TILE1_CFG_FSM_LUT_FN10, TILE1_CFG_FSM_LUT_FN2);

    //
    // Counter 0 - 2 are configured in <file>
    //

    //
    //  Counters
    //
    CLB_selectCounterInputs(base, TILE1_CFG_COUNTER_RESET, TILE1_CFG_COUNTER_EVENT, TILE1_CFG_COUNTER_MODE_0, TILE1_CFG_COUNTER_MODE_1);
    CLB_configMiscCtrlModes(base, TILE1_CFG_MISC_CONTROL);
    CLB_configCounterLoadMatch(base, CLB_CTR0, TILE1_COUNTER_0_LOAD_VAL, TILE1_COUNTER_0_MATCH1_VAL, TILE1_COUNTER_0_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR1, TILE1_COUNTER_1_LOAD_VAL, TILE1_COUNTER_1_MATCH1_VAL, TILE1_COUNTER_1_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR2, TILE1_COUNTER_2_LOAD_VAL, TILE1_COUNTER_2_MATCH1_VAL, TILE1_COUNTER_2_MATCH2_VAL);
    CLB_configCounterTapSelects(base, TILE1_CFG_TAP_SEL);

    //
    // HLC is configured in <file>
    //
    //  User Description for the High Level Controller for TILE1
    /*
        
    */
}


void initTILE2_qepdiv(uint32_t base)
{
    uint16_t i;
    //
    //  Output LUT
    //
    //
    //  Equation for Output Look-Up Table Block 0 for TILE2: i0
    //
    CLB_configOutputLUT(base, CLB_OUT0, TILE2_CFG_OUTLUT_0);

    //
    //  Equation for Output Look-Up Table Block 1 for TILE2: 1
    //
    CLB_configOutputLUT(base, CLB_OUT1, TILE2_CFG_OUTLUT_1);

    //
    //  Equation for Output Look-Up Table Block 2 for TILE2: i0
    //
    CLB_configOutputLUT(base, CLB_OUT2, TILE2_CFG_OUTLUT_2);

    //
    //  Equation for Output Look-Up Table Block 3 for TILE2: 1
    //
    CLB_configOutputLUT(base, CLB_OUT3, TILE2_CFG_OUTLUT_3);

    //
    //  Equation for Output Look-Up Table Block 4 for TILE2: i0
    //
    CLB_configOutputLUT(base, CLB_OUT4, TILE2_CFG_OUTLUT_4);

    //
    //  Equation for Output Look-Up Table Block 5 for TILE2: 0
    //
    CLB_configOutputLUT(base, CLB_OUT5, TILE2_CFG_OUTLUT_5);
    
    CLB_configOutputLUT(base, CLB_OUT6, TILE2_CFG_OUTLUT_6);

    CLB_configOutputLUT(base, CLB_OUT7, TILE2_CFG_OUTLUT_7);

    //
    //  AOC
    //
    CLB_configAOC(base, CLB_AOC0, TILE2_OUTPUT_COND_CTR_0);
    CLB_configAOC(base, CLB_AOC1, TILE2_OUTPUT_COND_CTR_1);
    CLB_configAOC(base, CLB_AOC2, TILE2_OUTPUT_COND_CTR_2);
    CLB_configAOC(base, CLB_AOC3, TILE2_OUTPUT_COND_CTR_3);
    CLB_configAOC(base, CLB_AOC4, TILE2_OUTPUT_COND_CTR_4);
    CLB_configAOC(base, CLB_AOC5, TILE2_OUTPUT_COND_CTR_5);
    CLB_configAOC(base, CLB_AOC6, TILE2_OUTPUT_COND_CTR_6);
    CLB_configAOC(base, CLB_AOC7, TILE2_OUTPUT_COND_CTR_7);

    //
    // LUT 0 - 2 are configured as macros in clb_config.h; these macros are used in
    // CLB_selectLUT4Inputs and CLB_configLUT4Function
    //
    //
    //  Equation for Look-Up Table Block 0 for TILE2: i0 & (i1 | i2)
    //
    //  Equation for Look-Up Table Block 1 for TILE2: (i2 & i1) | ((~i2) & i0)
    //
    //  Equation for Look-Up Table Block 2 for TILE2: (i2 & i0) | ((~i2) & i1)

    //
    //  LUT Configuration
    //
    CLB_selectLUT4Inputs(base, TILE2_CFG_LUT4_IN0, TILE2_CFG_LUT4_IN1, TILE2_CFG_LUT4_IN2, TILE2_CFG_LUT4_IN3);
    CLB_configLUT4Function(base, TILE2_CFG_LUT4_FN10, TILE2_CFG_LUT4_FN2);

    //
    // FSM 0 - 2 are configured in <file>
    //
    //
    //  Output equation for Finite State Machine 0 for TILE2: (~s0) & e0
    //  State 0 output equation for Finite State Machine 0 for TILE2: e0
    //  State 1 output equation for Finite State Machine 0 for TILE2: s1
    //
    //
    //  Output equation for Finite State Machine 1 for TILE2: s0 | s1
    //  State 0 output equation for Finite State Machine 1 for TILE2: ((~s0) & (e0)) | (s0 & (~e0))
    //  State 1 output equation for Finite State Machine 1 for TILE2: s0
    //
    //
    //  Output equation for Finite State Machine 2 for TILE2: s0
    //  State 0 output equation for Finite State Machine 2 for TILE2: ((~s0) & (e0)) | (s0 & (~e0))
    //  State 1 output equation for Finite State Machine 2 for TILE2: s1
    //

    //
    //  FSM
    //
    CLB_selectFSMInputs(base, TILE2_CFG_FSM_EXT_IN0, TILE2_CFG_FSM_EXT_IN1, TILE2_CFG_FSM_EXTRA_IN0, TILE2_CFG_FSM_EXTRA_IN1);
    CLB_configFSMNextState(base, TILE2_CFG_FSM_NEXT_STATE_0, TILE2_CFG_FSM_NEXT_STATE_1, TILE2_CFG_FSM_NEXT_STATE_2);
    CLB_configFSMLUTFunction(base, TILE2_CFG_FSM_LUT_FN10, TILE2_CFG_FSM_LUT_FN2);

    //
    // Counter 0 - 2 are configured in <file>
    //

    //
    //  Counters
    //
    CLB_selectCounterInputs(base, TILE2_CFG_COUNTER_RESET, TILE2_CFG_COUNTER_EVENT, TILE2_CFG_COUNTER_MODE_0, TILE2_CFG_COUNTER_MODE_1);
    CLB_configMiscCtrlModes(base, TILE2_CFG_MISC_CONTROL);
    CLB_configCounterLoadMatch(base, CLB_CTR0, TILE2_COUNTER_0_LOAD_VAL, TILE2_COUNTER_0_MATCH1_VAL, TILE2_COUNTER_0_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR1, TILE2_COUNTER_1_LOAD_VAL, TILE2_COUNTER_1_MATCH1_VAL, TILE2_COUNTER_1_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR2, TILE2_COUNTER_2_LOAD_VAL, TILE2_COUNTER_2_MATCH1_VAL, TILE2_COUNTER_2_MATCH2_VAL);
    CLB_configCounterTapSelects(base, TILE2_CFG_TAP_SEL);

    //
    // HLC is configured in <file>
    //
    //  User Description for the High Level Controller for TILE2
    /*
        
    */

    //
    // HLC
    //
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
