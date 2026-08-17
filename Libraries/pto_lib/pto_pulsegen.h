/** 
  *************************************************************************************
  * @file pto_pulsegen.h 
  * @author Albatross 
  * @brief This file contains the header file. 
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

#ifndef PTO_PULSEGEN_H
#define PTO_PULSEGEN_H

//
// Library of functions
//
#include <stdint.h>

//
// Function Prototypes
//
extern void pto_pulsegen_setupPeriph(void);
extern uint16_t pto_pulsegen_runPulseGen(
        uint32_t pulseLo,
        uint32_t pulseHi,
        uint32_t ptoActivePeriod,
        uint32_t ptoFullPeriod,
        uint32_t ptoInterruptTime,
        uint16_t ptoDirection,
        uint16_t run);
extern void pto_pulsegen_startOperation(void);
extern void pto_pulsegen_initCLBXBAR(void);
extern void pto_pulsegen_resetCLB(void);
extern void pto_pulsegen_reset(void);
void initTILE1_pul(uint32_t base);

#endif // PTO_PULSEGEN_H

// HLC Instruction Register Field definitions
#define HLC_OPCODE_R0 0x0
#define HLC_OPCODE_R1 0x1
#define HLC_OPCODE_R2 0x2
#define HLC_OPCODE_R3 0x3
#define HLC_OPCODE_C0 0x4
#define HLC_OPCODE_C1 0x5
#define HLC_OPCODE_C2 0x6

#define HLC_OPCODE_MOV    0x00
#define HLC_OPCODE_MOV_T1 0x01
#define HLC_OPCODE_MOV_T2 0x02
#define HLC_OPCODE_PUSH   0x03
#define HLC_OPCODE_PULL   0x04
#define HLC_OPCODE_ADD    0x05
#define HLC_OPCODE_SUB    0x06
#define HLC_OPCODE_INTR   0x07

//---------------------------------------------------------------------------
// TILE1
//---------------------------------------------------------------------------
#define TILE1_CFG_OUTLUT_0 0x550004
#define TILE1_CFG_OUTLUT_1 0x550003
#define TILE1_CFG_OUTLUT_2 0x0
#define TILE1_CFG_OUTLUT_3 0x0
#define TILE1_CFG_OUTLUT_4 0x440304
#define TILE1_CFG_OUTLUT_5 0x550014
#define TILE1_CFG_OUTLUT_6 0x0
#define TILE1_CFG_OUTLUT_7 0x0

#define TILE1_CFG_LUT4_IN0   0x758
#define TILE1_CFG_LUT4_IN1   0x3319
#define TILE1_CFG_LUT4_IN2   0x2409
#define TILE1_CFG_LUT4_IN3   0x0
#define TILE1_CFG_LUT4_FN10  ((0x88880000) | 0xa8a8)
#define TILE1_CFG_LUT4_FN2   0xfefe

#define TILE1_CFG_FSM_EXT_IN0      0x7163
#define TILE1_CFG_FSM_EXT_IN1      0x1d21
#define TILE1_CFG_FSM_EXTRA_IN0    0x0
#define TILE1_CFG_FSM_EXTRA_IN1    0x0
#define TILE1_CFG_FSM_NEXT_STATE_0 ((0xcccc0000) | 0xfa)
#define TILE1_CFG_FSM_NEXT_STATE_1 ((0xaaaa0000) | 0xfa)
#define TILE1_CFG_FSM_NEXT_STATE_2 ((0xcccc0000) | 0xf0aa)
#define TILE1_CFG_FSM_LUT_FN10     ((0x00000) | 0x0)
#define TILE1_CFG_FSM_LUT_FN2      0x0
#define TILE1_FSM_MISC_CONTROL     0x0

#define TILE1_CFG_COUNTER_RESET   0x4537
#define TILE1_CFG_COUNTER_EVENT   0x0
#define TILE1_CFG_COUNTER_MODE_0  0x3def
#define TILE1_CFG_COUNTER_MODE_1  0x2108
#define TILE1_CFG_TAP_SEL          0x0
#define TILE1_CFG_MISC_CONTROL    (0x0 | TILE1_FSM_MISC_CONTROL)

#define TILE1_COUNTER_0_MATCH1_VAL  0
#define TILE1_COUNTER_0_MATCH2_VAL  0
#define TILE1_COUNTER_0_LOAD_VAL    0
#define TILE1_COUNTER_1_MATCH1_VAL  0
#define TILE1_COUNTER_1_MATCH2_VAL  0
#define TILE1_COUNTER_1_LOAD_VAL    0
#define TILE1_COUNTER_2_MATCH1_VAL  40
#define TILE1_COUNTER_2_MATCH2_VAL  0
#define TILE1_COUNTER_2_LOAD_VAL    0


#define TILE1_SPI_EN 0

#define TILE1_HLC_EVENT_SEL 0x7
#define TILE1_HLC_R0_INIT 19
#define TILE1_HLC_R1_INIT 39
#define TILE1_HLC_R2_INIT 199
#define TILE1_HLC_R3_INIT 199

#define TILE1_HLC_FIFO0_INIT 0
#define TILE1_HLC_FIFO1_INIT 0
#define TILE1_HLC_FIFO2_INIT 0
#define TILE1_HLC_FIFO3_INIT 0

#define TILE1_HLCINSTR_0	(0 << 11 | HLC_OPCODE_MOV_T1 << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_C0)
#define TILE1_HLCINSTR_1	(0 << 11 | HLC_OPCODE_MOV_T2 << 6 | HLC_OPCODE_R1<<3 | HLC_OPCODE_C0)
#define TILE1_HLCINSTR_2	(0 << 11 | HLC_OPCODE_MOV_T1 << 6 | HLC_OPCODE_R2<<3 | HLC_OPCODE_C1)
#define TILE1_HLCINSTR_3	(0 << 11 | HLC_OPCODE_MOV_T2 << 6 | HLC_OPCODE_R3<<3 | HLC_OPCODE_C1)
#define TILE1_HLCINSTR_4	(1 << 11 | HLC_OPCODE_MOV_T2 << 6 | HLC_OPCODE_R3<<3 | HLC_OPCODE_C2)
#define TILE1_HLCINSTR_5	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_6	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_7	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_8	(1 << 11 | HLC_OPCODE_INTR << 6 | 1)
#define TILE1_HLCINSTR_9	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_10	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_11	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_12	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_13	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_14	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_15	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_16	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_17	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_18	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_19	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_20	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_21	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_22	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_23	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_24	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_25	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_26	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_27	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_28	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_29	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_30	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_31	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)




#define TILE1_OUTPUT_COND_CTR_0 0x0
#define TILE1_OUTPUT_COND_CTR_1 0x0
#define TILE1_OUTPUT_COND_CTR_2 0x0
#define TILE1_OUTPUT_COND_CTR_3 0x0
#define TILE1_OUTPUT_COND_CTR_4 0x0
#define TILE1_OUTPUT_COND_CTR_5 0x0
#define TILE1_OUTPUT_COND_CTR_6 0x0
#define TILE1_OUTPUT_COND_CTR_7 0x0


//
// End of File
//
