/**
 *************************************************************************************
 * @file clb_ex02_config.h
 * @brief This file contains the header file for example clb_ex02_config.
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

#ifndef ti_clb_h
#define ti_clb_h

#include <stdint.h>

#ifdef __cplusplus
extern "C" {            
#endif

//*****************************************************************************
//
// HLC Instruction Register Field definitions
//
//*****************************************************************************
#define HLC_OPCODE_R0 0x0   //!< HLC Register 0
#define HLC_OPCODE_R1 0x1   //!< HLC Register 1
#define HLC_OPCODE_R2 0x2   //!< HLC Register 2
#define HLC_OPCODE_R3 0x3   //!< HLC Register 3
#define HLC_OPCODE_C0 0x4   //!< HLC Constant 0
#define HLC_OPCODE_C1 0x5   //!< HLC Constant 1
#define HLC_OPCODE_C2 0x6   //!< HLC Constant 2

#define HLC_OPCODE_MOV    0x00  //!< Move instruction
#define HLC_OPCODE_MOV_T1 0x01  //!< Move with T1 condition
#define HLC_OPCODE_MOV_T2 0x02  //!< Move with T2 condition
#define HLC_OPCODE_PUSH   0x03  //!< Push instruction
#define HLC_OPCODE_PULL   0x04  //!< Pull instruction
#define HLC_OPCODE_ADD    0x05  //!< Add instruction
#define HLC_OPCODE_SUB    0x06  //!< Subtract instruction
#define HLC_OPCODE_INTR   0x07  //!< Interrupt instruction

//*****************************************************************************
//
// TILE1
//
//*****************************************************************************
#define TILE1_PIPELINE_MODE 0     //!< Pipeline Mode Configuration
#define TILE1_CFG_OUTLUT_0 0x550004  //!< LUT0 Configuration
#define TILE1_CFG_OUTLUT_1 0x0     //!< LUT1 Configuration
#define TILE1_CFG_OUTLUT_2 0x0     //!< LUT2 Configuration
#define TILE1_CFG_OUTLUT_3 0x0     //!< LUT3 Configuration
#define TILE1_CFG_OUTLUT_4 0x0     //!< LUT4 Configuration
#define TILE1_CFG_OUTLUT_5 0x0     //!< LUT5 Configuration
#define TILE1_CFG_OUTLUT_6 0x0     //!< LUT6 Configuration
#define TILE1_CFG_OUTLUT_7 0x0     //!< LUT7 Configuration

#define TILE1_CFG_LUT4_IN0   0x18        //!< LUT4 Input 0 Configuration
#define TILE1_CFG_LUT4_IN1   0x0         //!< LUT4 Input 1 Configuration
#define TILE1_CFG_LUT4_IN2   0x0         //!< LUT4 Input 2 Configuration
#define TILE1_CFG_LUT4_IN3   0x0         //!< LUT4 Input 3 Configuration
#define TILE1_CFG_LUT4_FN10  ((0x00000) | 0x5555) //!< LUT4 Function 10 Configuration
#define TILE1_CFG_LUT4_FN2   0x0         //!< LUT4 Function 2 Configuration

#define TILE1_CFG_FSM_EXT_IN0      0x3           //!< FSM External Input 0 Configuration
#define TILE1_CFG_FSM_EXT_IN1      0xb           //!< FSM External Input 1 Configuration
#define TILE1_CFG_FSM_EXTRA_IN0    0x0           //!< FSM Extra Input 0 Configuration
#define TILE1_CFG_FSM_EXTRA_IN1    0x0           //!< FSM Extra Input 1 Configuration
#define TILE1_CFG_FSM_NEXT_STATE_0 ((0x00000) | 0x5f0a) //!< FSM Next State 0 Configuration
#define TILE1_CFG_FSM_NEXT_STATE_1 ((0x00000) | 0x0)  //!< FSM Next State 1 Configuration
#define TILE1_CFG_FSM_NEXT_STATE_2 ((0x00000) | 0x0)  //!< FSM Next State 2 Configuration
#define TILE1_CFG_FSM_LUT_FN10     ((0x00000) | 0x0)  //!< FSM LUT Function 10 Configuration
#define TILE1_CFG_FSM_LUT_FN2      0x0           //!< FSM LUT Function 2 Configuration
#define TILE1_FSM_MISC_CONTROL     0x0           //!< FSM Miscellaneous Control

#define TILE1_CFG_COUNTER_RESET   0x4cf8        //!< Counter Reset Configuration
#define TILE1_CFG_COUNTER_EVENT   0x0           //!< Counter Event Configuration
#define TILE1_CFG_COUNTER_MODE_0  0x2307        //!< Counter Mode 0 Configuration
#define TILE1_CFG_COUNTER_MODE_1  0x2108        //!< Counter Mode 1 Configuration
#define TILE1_CFG_TAP_SEL          0x0          //!< Tap Selection Configuration
#define TILE1_CFG_MISC_CONTROL    (0x0 | TILE1_FSM_MISC_CONTROL) //!< Miscellaneous Control Configuration

#define TILE1_COUNTER_0_MATCH1_VAL  8  //!< Counter 0 Match 1 Value
#define TILE1_COUNTER_0_MATCH2_VAL  0  //!< Counter 0 Match 2 Value
#define TILE1_COUNTER_0_LOAD_VAL    0  //!< Counter 0 Load Value
#define TILE1_COUNTER_1_MATCH1_VAL  8  //!< Counter 1 Match 1 Value
#define TILE1_COUNTER_1_MATCH2_VAL  0  //!< Counter 1 Match 2 Value
#define TILE1_COUNTER_1_LOAD_VAL    0  //!< Counter 1 Load Value
#define TILE1_COUNTER_2_MATCH1_VAL  0  //!< Counter 2 Match 1 Value
#define TILE1_COUNTER_2_MATCH2_VAL  0  //!< Counter 2 Match 2 Value
#define TILE1_COUNTER_2_LOAD_VAL    0  //!< Counter 2 Load Value


#define TILE1_HLC_EVENT_SEL 0x0       //!< HLC Event Selection
#define TILE1_HLC_R0_INIT 0           //!< HLC Register 0 Initial Value
#define TILE1_HLC_R1_INIT 0           //!< HLC Register 1 Initial Value
#define TILE1_HLC_R2_INIT 0           //!< HLC Register 2 Initial Value
#define TILE1_HLC_R3_INIT 0           //!< HLC Register 3 Initial Value

#define TILE1_HLCINSTR_0	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 0
#define TILE1_HLCINSTR_1	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 1
#define TILE1_HLCINSTR_2	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 2
#define TILE1_HLCINSTR_3	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 3
#define TILE1_HLCINSTR_4	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 4
#define TILE1_HLCINSTR_5	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 5
#define TILE1_HLCINSTR_6	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 6
#define TILE1_HLCINSTR_7	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 7
#define TILE1_HLCINSTR_8	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 8
#define TILE1_HLCINSTR_9	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)  //!< HLC Instruction 9
#define TILE1_HLCINSTR_10	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 10
#define TILE1_HLCINSTR_11	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 11
#define TILE1_HLCINSTR_12	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 12
#define TILE1_HLCINSTR_13	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 13
#define TILE1_HLCINSTR_14	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 14
#define TILE1_HLCINSTR_15	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 15
#define TILE1_HLCINSTR_16	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 16
#define TILE1_HLCINSTR_17	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 17
#define TILE1_HLCINSTR_18	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 18
#define TILE1_HLCINSTR_19	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 19
#define TILE1_HLCINSTR_20	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 20
#define TILE1_HLCINSTR_21	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 21
#define TILE1_HLCINSTR_22	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 22
#define TILE1_HLCINSTR_23	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 23
#define TILE1_HLCINSTR_24	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 24
#define TILE1_HLCINSTR_25	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 25
#define TILE1_HLCINSTR_26	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 26
#define TILE1_HLCINSTR_27	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 27
#define TILE1_HLCINSTR_28	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 28
#define TILE1_HLCINSTR_29	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 29
#define TILE1_HLCINSTR_30	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 30
#define TILE1_HLCINSTR_31	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0) //!< HLC Instruction 31




#define TILE1_OUTPUT_COND_CTR_0 0x0  //!< Output Condition Control 0
#define TILE1_OUTPUT_COND_CTR_1 0x0  //!< Output Condition Control 1
#define TILE1_OUTPUT_COND_CTR_2 0x0  //!< Output Condition Control 2
#define TILE1_OUTPUT_COND_CTR_3 0x0  //!< Output Condition Control 3
#define TILE1_OUTPUT_COND_CTR_4 0x0  //!< Output Condition Control 4
#define TILE1_OUTPUT_COND_CTR_5 0x0  //!< Output Condition Control 5
#define TILE1_OUTPUT_COND_CTR_6 0x0  //!< Output Condition Control 6
#define TILE1_OUTPUT_COND_CTR_7 0x0  //!< Output Condition Control 7

void initTILE1(uint32_t base);

#ifdef __cplusplus
}
#endif

#endif
