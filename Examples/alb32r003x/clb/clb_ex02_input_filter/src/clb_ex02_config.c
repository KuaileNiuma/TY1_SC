/**
 *************************************************************************************
 * @file clb_ex02_config.c
 * @brief This file contains the source file for example clb_ex02_config.
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

#include "clb.h"
#include "clb_ex02_config.h"

//*****************************************************************************
//
// TILE1HLCInstr - TILE1 HLC Instruction Array
//
//*****************************************************************************
uint16_t TILE1HLCInstr[CLB_NUM_HLC_INSTR + 1] =
{
    TILE1_HLCINSTR_0,   //!< HLC Instruction 0
    TILE1_HLCINSTR_1,   //!< HLC Instruction 1
    TILE1_HLCINSTR_2,   //!< HLC Instruction 2
    TILE1_HLCINSTR_3,   //!< HLC Instruction 3
    TILE1_HLCINSTR_4,   //!< HLC Instruction 4
    TILE1_HLCINSTR_5,   //!< HLC Instruction 5
    TILE1_HLCINSTR_6,   //!< HLC Instruction 6
    TILE1_HLCINSTR_7,   //!< HLC Instruction 7
    TILE1_HLCINSTR_8,   //!< HLC Instruction 8
    TILE1_HLCINSTR_9,   //!< HLC Instruction 9
    TILE1_HLCINSTR_10,  //!< HLC Instruction 10
    TILE1_HLCINSTR_11,  //!< HLC Instruction 11
    TILE1_HLCINSTR_12,  //!< HLC Instruction 12
    TILE1_HLCINSTR_13,  //!< HLC Instruction 13
    TILE1_HLCINSTR_14,  //!< HLC Instruction 14
    TILE1_HLCINSTR_15,  //!< HLC Instruction 15
    TILE1_HLCINSTR_16,  //!< HLC Instruction 16
    TILE1_HLCINSTR_17,  //!< HLC Instruction 17
    TILE1_HLCINSTR_18,  //!< HLC Instruction 18
    TILE1_HLCINSTR_19,  //!< HLC Instruction 19
    TILE1_HLCINSTR_20,  //!< HLC Instruction 20
    TILE1_HLCINSTR_21,  //!< HLC Instruction 21
    TILE1_HLCINSTR_22,  //!< HLC Instruction 22
    TILE1_HLCINSTR_23,  //!< HLC Instruction 23
    TILE1_HLCINSTR_24,  //!< HLC Instruction 24
    TILE1_HLCINSTR_25,  //!< HLC Instruction 25
    TILE1_HLCINSTR_26,  //!< HLC Instruction 26
    TILE1_HLCINSTR_27,  //!< HLC Instruction 27
    TILE1_HLCINSTR_28,  //!< HLC Instruction 28
    TILE1_HLCINSTR_29,  //!< HLC Instruction 29
    TILE1_HLCINSTR_30,  //!< HLC Instruction 30
    TILE1_HLCINSTR_31   //!< HLC Instruction 31
};

//*****************************************************************************
//
// initTILE1 - TILE1 Initialization
//
//*****************************************************************************
void initTILE1(uint32_t base)
{
    uint16_t i;
    
    //
    // Output LUT
    //
    CLB_configOutputLUT(base, CLB_OUT0, TILE1_CFG_OUTLUT_0);
    CLB_configOutputLUT(base, CLB_OUT1, TILE1_CFG_OUTLUT_1);
    CLB_configOutputLUT(base, CLB_OUT2, TILE1_CFG_OUTLUT_2);
    CLB_configOutputLUT(base, CLB_OUT3, TILE1_CFG_OUTLUT_3);
    CLB_configOutputLUT(base, CLB_OUT4, TILE1_CFG_OUTLUT_4);
    CLB_configOutputLUT(base, CLB_OUT5, TILE1_CFG_OUTLUT_5);
    CLB_configOutputLUT(base, CLB_OUT6, TILE1_CFG_OUTLUT_6);
    CLB_configOutputLUT(base, CLB_OUT7, TILE1_CFG_OUTLUT_7);

    //
    // AOC
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
    // LUT4
    //
    CLB_selectLUT4Inputs(base, TILE1_CFG_LUT4_IN0, TILE1_CFG_LUT4_IN1, TILE1_CFG_LUT4_IN2, TILE1_CFG_LUT4_IN3);
    CLB_configLUT4Function(base, TILE1_CFG_LUT4_FN10, TILE1_CFG_LUT4_FN2);

    //
    // FSM
    //
    CLB_selectFSMInputs(base, TILE1_CFG_FSM_EXT_IN0, TILE1_CFG_FSM_EXT_IN1, TILE1_CFG_FSM_EXTRA_IN0, TILE1_CFG_FSM_EXTRA_IN1);
    CLB_configFSMNextState(base, TILE1_CFG_FSM_NEXT_STATE_0, TILE1_CFG_FSM_NEXT_STATE_1, TILE1_CFG_FSM_NEXT_STATE_2);
    CLB_configFSMLUTFunction(base, TILE1_CFG_FSM_LUT_FN10, TILE1_CFG_FSM_LUT_FN2);

    //
    // Counters
    //
    CLB_selectCounterInputs(base, TILE1_CFG_COUNTER_RESET, TILE1_CFG_COUNTER_EVENT, TILE1_CFG_COUNTER_MODE_0, TILE1_CFG_COUNTER_MODE_1);
    CLB_configMiscCtrlModes(base, TILE1_CFG_MISC_CONTROL);
    CLB_configCounterLoadMatch(base, CLB_CTR0, TILE1_COUNTER_0_LOAD_VAL, TILE1_COUNTER_0_MATCH1_VAL, TILE1_COUNTER_0_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR1, TILE1_COUNTER_1_LOAD_VAL, TILE1_COUNTER_1_MATCH1_VAL, TILE1_COUNTER_1_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR2, TILE1_COUNTER_2_LOAD_VAL, TILE1_COUNTER_2_MATCH1_VAL, TILE1_COUNTER_2_MATCH2_VAL);
    CLB_configCounterTapSelects(base, TILE1_CFG_TAP_SEL);

}




