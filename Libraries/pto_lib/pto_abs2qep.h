/** 
  *************************************************************************************
  * @file pto_abs2qep.h 
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

#ifndef PTO_ABS2QEP_H
#define PTO_ABS2QEP_H

//
// Library functions
//
#include <stdint.h>
#include "math.h"

//
// This is the GPIO used for Test Pin 1.
// This GPIO toggles in the system ISR and
// stays low if the direction is reverse
// stays high if the direction is forward
// It is to aid in visualization of waveforms
// only
//
#if defined(_F2837x) || defined(_F2838x)
#define PTO_ABSQEP_TEST_PIN_1 32
#else
#define PTO_ABSQEP_TEST_PIN_1 13
#endif

//
// Configurable defines
//
// CLB clock in seconds
// Position sampling period in seconds
// Maximum motor revolutions per minute
//
#define PTO_ABS2QEP_CLB_CLK            10.0e-9f
#define PTO_ABS2QEP_ABS_SAMPLE_PERIOD  100.0e-6f
#define PTO_ABS2QEP_MAX_RPM            30000.0f

//
// Absolute encoder resolution
//
#if defined(_TFORMAT_TS5700N8501)
#define PTO_ABS2QEP_ABS_ENCODER_RESOLUTION 17u        // Q17
#else
#define PTO_ABS2QEP_ABS_ENCODER_RESOLUTION 20u        // Q20
#endif

//
// Incremental encoder resolution
//
#define PTO_ABS2QEP_LINES_PER_REV   1024u    // Lines per revolution
#define PTO_ABS2QEP_QCLKS_PER_LINE  2.0f     // QCLKs (QEP edges) per line

//
// Calculated Defines
//
// Used in translating the absolute encoder position change
// an equivalent incremental position change.
//
// PTO_ABS2QEP_SAMPLE_ADJUST takes into account time required to
// load the next PTO sample.  If this adjustment is not used then
// the PTO will be slightly longer than the sampling period.  This
// time will accumulate over samples if no adjustment is made.
//
#define PTO_ABS2QEP_ABS_MAX_POSITION                                           \
            (1UL << PTO_ABS2QEP_ABS_ENCODER_RESOLUTION)

#define PTO_ABS2QEP_QCLK_PER_REV                                               \
            (PTO_ABS2QEP_LINES_PER_REV * PTO_ABS2QEP_QCLKS_PER_LINE)

#define PTO_ABS2QEP_ABS_TO_INCR                                                \
            ((float32_t)(PTO_ABS2QEP_QCLK_PER_REV)                             \
           / (float32_t)(PTO_ABS2QEP_ABS_MAX_POSITION))

#define PTO_ABS2QEP_SAMPLE_ADJUST        1.0e-6

#define PTO_ABS2QEP_SAMPLING_RATIO                                             \
             ((PTO_ABS2QEP_ABS_SAMPLE_PERIOD - PTO_ABS2QEP_SAMPLE_ADJUST)      \
            / PTO_ABS2QEP_CLB_CLK)

//
// Revolution / sample is the maximum distance the motor can move within
// one sampling period. For example: .05 of a revolution
// This value is used to detect a zero crossing as described in the
// user's guide.
//
#define PTO_ABS2QEP_MAX_REV_PER_SECOND    (PTO_ABS2QEP_MAX_RPM / 60.0f)
#define PTO_ABS2QEP_MAX_REV_PER_SAMPLE    (PTO_ABS2QEP_MAX_REV_PER_SECOND      \
                                         * PTO_ABS2QEP_ABS_SAMPLE_PERIOD)

#define PTO_ABS2QEP_ABS_MAX_DELTA_PER_SAMPLE (PTO_ABS2QEP_ABS_MAX_POSITION     \
                                        * PTO_ABS2QEP_MAX_REV_PER_SAMPLE)

//
// GP Register Bit Definitions
//
#define PTO_ABS2QEP_GPREG_LOAD_PTO_S     0x0u  // in0
#define PTO_ABS2QEP_GPREG_DIRECTION_S    0x1u  // in1

#define PTO_ABS2QEP_SET_LOAD             (0x1u << PTO_ABS2QEP_GPREG_LOAD_PTO_S)
#define PTO_ABS2QEP_SET_CLOCKWISE        (0x1u << PTO_ABS2QEP_GPREG_DIRECTION_S)
#define PTO_ABS2QEP_SET_COUNTERCLOCKWISE (0x0u << PTO_ABS2QEP_GPREG_DIRECTION_S)

//
// Status values
//
#define PTO_ABS2QEP_CLOCKWISE_PTO         0x1u
#define PTO_ABS2QEP_COUNTERCLOCKWISE_PTO  0x2u

#define PTO_ABS2QEP_PTO_WAIT_TAG          0x0u  // HLC no tag set
#define PTO_ABS2QEP_PTO_LOAD_TAG          0x1u  // HLC INTR tag
#define PTO_ABS2QEP_PTO_DONE_TAG          0x2u  // HLC INTR tag



//
// Globals
//
extern volatile uint16_t pto_direction;

//
// Function Prototypes
//
extern void pto_abs2qep_setupPeriph(void);
extern void pto_abs2qep_initCLBXBAR(void);
extern void pto_abs2qep_runPulseGen(uint16_t direction);
extern uint16_t pto_abs2qep_translatePosition(uint32_t current_position);
extern uint32_t pto_generateTestAbsPosition(uint32_t currentPosition);
extern void pto_initAbs2QEP(void);
extern void pto_configEPWM(void);



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

#define TILE1_CFG_OUTLUT_0 0x55000e
#define TILE1_CFG_OUTLUT_1 0x0
#define TILE1_CFG_OUTLUT_2 0x550014
#define TILE1_CFG_OUTLUT_3 0x550003
#define TILE1_CFG_OUTLUT_4 0x550004
#define TILE1_CFG_OUTLUT_5 0x550005
#define TILE1_CFG_OUTLUT_6 0x0
#define TILE1_CFG_OUTLUT_7 0x0

#define TILE1_CFG_LUT4_IN0   0x0
#define TILE1_CFG_LUT4_IN1   0x0
#define TILE1_CFG_LUT4_IN2   0x0
#define TILE1_CFG_LUT4_IN3   0x0
#define TILE1_CFG_LUT4_FN10  ((0x00000) | 0x0)
#define TILE1_CFG_LUT4_FN2   0x0

#define TILE1_CFG_FSM_EXT_IN0      0x4d39
#define TILE1_CFG_FSM_EXT_IN1      0x4703
#define TILE1_CFG_FSM_EXTRA_IN0    0x0
#define TILE1_CFG_FSM_EXTRA_IN1    0x0
#define TILE1_CFG_FSM_NEXT_STATE_0 ((0xa5cc0000) | 0x3caa)
#define TILE1_CFG_FSM_NEXT_STATE_1 ((0x00000) | 0xfa)
#define TILE1_CFG_FSM_NEXT_STATE_2 ((0x00000) | 0xfa)
#define TILE1_CFG_FSM_LUT_FN10     ((0x550000|0X0))
#define TILE1_CFG_FSM_LUT_FN2      0x0
#define TILE1_FSM_MISC_CONTROL     0x0

#define TILE1_CFG_COUNTER_RESET   0x2521
#define TILE1_CFG_COUNTER_EVENT   0xc60
#define TILE1_CFG_COUNTER_MODE_0  0xe
#define TILE1_CFG_COUNTER_MODE_1  0x8
#define TILE1_CFG_TAP_SEL         0x0
#define TILE1_CFG_MISC_CONTROL    (0x1f8 | TILE1_FSM_MISC_CONTROL)

#define TILE1_COUNTER_0_MATCH1_VAL  0x2
#define TILE1_COUNTER_0_MATCH2_VAL  0xFFFFFFFF
#define TILE1_COUNTER_0_LOAD_VAL    0
#define TILE1_COUNTER_1_MATCH1_VAL  0xFFFFFFFF
#define TILE1_COUNTER_1_MATCH2_VAL  1
#define TILE1_COUNTER_1_LOAD_VAL    1
#define TILE1_COUNTER_2_MATCH1_VAL  0xFFFFFFFF
#define TILE1_COUNTER_2_MATCH2_VAL  0xFFFFFFFF
#define TILE1_COUNTER_2_LOAD_VAL    1


#define TILE1_SPI_EN 0

#define TILE1_HLC_EVENT_SEL 0x2718
#define TILE1_HLC_R0_INIT 0
#define TILE1_HLC_R1_INIT 0
#define TILE1_HLC_R2_INIT 0
#define TILE1_HLC_R3_INIT 0xFFFFFFF

#define TILE1_HLC_FIFO0_INIT 11
#define TILE1_HLC_FIFO1_INIT 10
#define TILE1_HLC_FIFO2_INIT 20
#define TILE1_HLC_FIFO3_INIT 30


#define TILE1_HLCINSTR_0	(0 << 11 | HLC_OPCODE_MOV_T1 << 6 | HLC_OPCODE_R2<<3 | HLC_OPCODE_C1)
#define TILE1_HLCINSTR_1	(0 << 11 | HLC_OPCODE_MOV_T2 << 6 | HLC_OPCODE_R3<<3 | HLC_OPCODE_C1)
#define TILE1_HLCINSTR_2	(0 << 11 | HLC_OPCODE_PULL << 6 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_3	(0 << 11 | HLC_OPCODE_MOV_T2 << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_C1)
#define TILE1_HLCINSTR_4	(0 << 11 | HLC_OPCODE_PULL << 6 | HLC_OPCODE_R1)
#define TILE1_HLCINSTR_5	(0 << 11 | HLC_OPCODE_MOV_T2 << 6 | HLC_OPCODE_R1<<3 | HLC_OPCODE_C0)
#define TILE1_HLCINSTR_6	(0 << 11 | HLC_OPCODE_PULL << 6 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_7	(1 << 11 | HLC_OPCODE_MOV_T1 << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_C2)
#define TILE1_HLCINSTR_8	(0 << 11 | HLC_OPCODE_PULL << 6 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_9	(0 << 11 | HLC_OPCODE_MOV_T2 << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_C2)
#define TILE1_HLCINSTR_10	(0 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R1<<3 | HLC_OPCODE_C0)
#define TILE1_HLCINSTR_11	(0 << 11 | HLC_OPCODE_INTR << 6 | 1)
#define TILE1_HLCINSTR_12	(1 << 11 | HLC_OPCODE_MOV_T1 << 6 | HLC_OPCODE_R3<<3 | HLC_OPCODE_C1)
#define TILE1_HLCINSTR_13	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_14	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_15	(1 << 11 | HLC_OPCODE_MOV << 6 | HLC_OPCODE_R0<<3 | HLC_OPCODE_R0)
#define TILE1_HLCINSTR_16	(1 << 11 | HLC_OPCODE_INTR << 6 | 2)
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

void initTILE1(uint32_t base);

#endif // PTO_ABS2QEP_H
//
// End of File
//
