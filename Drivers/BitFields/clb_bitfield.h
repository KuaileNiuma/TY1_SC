//###########################################################################
//
// FILE:   clb.h
//
// TITLE:   Definitions for the CLB registers.
//
//###########################################################################
// 
//###########################################################################

#ifndef REGS_CLB_H
#define REGS_CLB_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CLB Individual Register Bit Definitions:

struct CLB_COUNT_RESET_BITS {           // bits description
    Uint16 SEL_0:5;                     // 4:0 Count Reset Select 0
    Uint16 SEL_1:5;                     // 9:5 Count Reset Select 1
    Uint16 SEL_2:5;                     // 14:10 Count Reset Select 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_COUNT_RESET_REG {
    Uint32  all;
    struct  CLB_COUNT_RESET_BITS  bit;
};

struct CLB_COUNT_MODE_1_BITS {          // bits description
    Uint16 SEL_0:5;                     // 4:0 Counter mode 1 select 0
    Uint16 SEL_1:5;                     // 9:5 Counter mode 1 select 1
    Uint16 SEL_2:5;                     // 14:10 Counter mode 1 select 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_COUNT_MODE_1_REG {
    Uint32  all;
    struct  CLB_COUNT_MODE_1_BITS  bit;
};

struct CLB_COUNT_MODE_0_BITS {          // bits description
    Uint16 SEL_0:5;                     // 4:0 Counter mode 0 select 0
    Uint16 SEL_1:5;                     // 9:5 Counter mode 0 select 1
    Uint16 SEL_2:5;                     // 14:10 Counter mode 0 select 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_COUNT_MODE_0_REG {
    Uint32  all;
    struct  CLB_COUNT_MODE_0_BITS  bit;
};

struct CLB_COUNT_EVENT_BITS {           // bits description
    Uint16 SEL_0:5;                     // 4:0 Counter event select 0
    Uint16 SEL_1:5;                     // 9:5 Counter event select 1
    Uint16 SEL_2:5;                     // 14:10 Counter event select 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_COUNT_EVENT_REG {
    Uint32  all;
    struct  CLB_COUNT_EVENT_BITS  bit;
};

struct CLB_FSM_EXTRA_IN0_BITS {         // bits description
    Uint16 SEL_0:5;                     // 4:0 FSM extra ext input select 0
    Uint16 SEL_1:5;                     // 9:5 FSM extra ext input select 1
    Uint16 SEL_2:5;                     // 14:10 FSM extra ext input select 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_FSM_EXTRA_IN0_REG {
    Uint32  all;
    struct  CLB_FSM_EXTRA_IN0_BITS  bit;
};

struct CLB_FSM_EXTERNAL_IN0_BITS {      // bits description
    Uint16 SEL_0:5;                     // 4:0 FSM EXT_IN0 select input for unit 0
    Uint16 SEL_1:5;                     // 9:5 FSM EXT_IN0 select input for unit 1
    Uint16 SEL_2:5;                     // 14:10 FSM EXT_IN0 select input for unit 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_FSM_EXTERNAL_IN0_REG {
    Uint32  all;
    struct  CLB_FSM_EXTERNAL_IN0_BITS  bit;
};

struct CLB_FSM_EXTERNAL_IN1_BITS {      // bits description
    Uint16 SEL_0:5;                     // 4:0 FSM EXT_IN1 select input for unit 0
    Uint16 SEL_1:5;                     // 9:5 FSM EXT_IN1 select input for unit 1
    Uint16 SEL_2:5;                     // 14:10 FSM EXT_IN1 select input for unit 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_FSM_EXTERNAL_IN1_REG {
    Uint32  all;
    struct  CLB_FSM_EXTERNAL_IN1_BITS  bit;
};

struct CLB_FSM_EXTRA_IN1_BITS {         // bits description
    Uint16 SEL_0:5;                     // 4:0 FSM extra ext input select 0
    Uint16 SEL_1:5;                     // 9:5 FSM extra ext input select 1
    Uint16 SEL_2:5;                     // 14:10 FSM extra ext input select 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_FSM_EXTRA_IN1_REG {
    Uint32  all;
    struct  CLB_FSM_EXTRA_IN1_BITS  bit;
};

struct CLB_LUT4_IN0_BITS {              // bits description
    Uint16 SEL_0:5;                     // 4:0 Select inputs for unit 0
    Uint16 SEL_1:5;                     // 9:5 Select inputs for unit 1
    Uint16 SEL_2:5;                     // 14:10 Select inputs for unit 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_LUT4_IN0_REG {
    Uint32  all;
    struct  CLB_LUT4_IN0_BITS  bit;
};

struct CLB_LUT4_IN1_BITS {              // bits description
    Uint16 SEL_0:5;                     // 4:0 Select inputs for unit 0
    Uint16 SEL_1:5;                     // 9:5 Select inputs for unit 1
    Uint16 SEL_2:5;                     // 14:10 Select inputs for unit 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_LUT4_IN1_REG {
    Uint32  all;
    struct  CLB_LUT4_IN1_BITS  bit;
};

struct CLB_LUT4_IN2_BITS {              // bits description
    Uint16 SEL_0:5;                     // 4:0 Select inputs for unit 0
    Uint16 SEL_1:5;                     // 9:5 Select inputs for unit 1
    Uint16 SEL_2:5;                     // 14:10 Select inputs for unit 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_LUT4_IN2_REG {
    Uint32  all;
    struct  CLB_LUT4_IN2_BITS  bit;
};

struct CLB_LUT4_IN3_BITS {              // bits description
    Uint16 SEL_0:5;                     // 4:0 Select inputs for unit 0
    Uint16 SEL_1:5;                     // 9:5 Select inputs for unit 1
    Uint16 SEL_2:5;                     // 14:10 Select inputs for unit 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_LUT4_IN3_REG {
    Uint32  all;
    struct  CLB_LUT4_IN3_BITS  bit;
};

struct CLB_FSM_LUT_FN1_0_BITS {         // bits description
    Uint16 FN0:16;                      // 15:0 FSM LUT output function for unit 0
    Uint16 FN1:16;                      // 31:16 FSM LUT output function for unit 1
};

union CLB_FSM_LUT_FN1_0_REG {
    Uint32  all;
    struct  CLB_FSM_LUT_FN1_0_BITS  bit;
};

struct CLB_FSM_LUT_FN2_BITS {           // bits description
    Uint16 FN1:16;                      // 15:0 FSM LUT output function for unit 2
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union CLB_FSM_LUT_FN2_REG {
    Uint32  all;
    struct  CLB_FSM_LUT_FN2_BITS  bit;
};

struct CLB_LUT4_FN1_0_BITS {            // bits description
    Uint16 FN0:16;                      // 15:0 LUT4 output function for unit 0
    Uint16 FN1:16;                      // 31:16 LUT4 output function for unit 1
};

union CLB_LUT4_FN1_0_REG {
    Uint32  all;
    struct  CLB_LUT4_FN1_0_BITS  bit;
};

struct CLB_LUT4_FN2_BITS {              // bits description
    Uint16 FN1:16;                      // 15:0 LUT4 output function for unit 2
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union CLB_LUT4_FN2_REG {
    Uint32  all;
    struct  CLB_LUT4_FN2_BITS  bit;
};

struct CLB_FSM_NEXT_STATE_0_BITS {      // bits description
    Uint16 S0:16;                       // 15:0 FSM next state function for S0
    Uint16 S1:16;                       // 31:16 FSM next state function for S1
};

union CLB_FSM_NEXT_STATE_0_REG {
    Uint32  all;
    struct  CLB_FSM_NEXT_STATE_0_BITS  bit;
};

struct CLB_FSM_NEXT_STATE_1_BITS {      // bits description
    Uint16 S0:16;                       // 15:0 FSM next state function for S0
    Uint16 S1:16;                       // 31:16 FSM next state function for S1
};

union CLB_FSM_NEXT_STATE_1_REG {
    Uint32  all;
    struct  CLB_FSM_NEXT_STATE_1_BITS  bit;
};

struct CLB_FSM_NEXT_STATE_2_BITS {      // bits description
    Uint16 S0:16;                       // 15:0 FSM next state function for S0
    Uint16 S1:16;                       // 31:16 FSM next state function for S1
};

union CLB_FSM_NEXT_STATE_2_REG {
    Uint32  all;
    struct  CLB_FSM_NEXT_STATE_2_BITS  bit;
};

struct CLB_MISC_CONTROL_BITS {          // bits description
    Uint16 COUNT_ADD_SHIFT_0:1;         // 0 Add/Shift for counter 0
    Uint16 COUNT_DIR_0:1;               // 1 Direction for counter 0
    Uint16 COUNT_EVENT_CTRL_0:1;        // 2 Event control for counter 0
    Uint16 COUNT_ADD_SHIFT_1:1;         // 3 Add/Shift for counter 1
    Uint16 COUNT_DIR_1:1;               // 4 Direction for counter 1
    Uint16 COUNT_EVENT_CTRL_1:1;        // 5 Event control for counter 1
    Uint16 COUNT_ADD_SHIFT_2:1;         // 6 Add/Shift for counter 2
    Uint16 COUNT_DIR_2:1;               // 7 Direction for counter 2
    Uint16 COUNT_EVENT_CTRL_2:1;        // 8 Event control for counter 2
    Uint16 COUNT_SERIALIZER_0:1;        // 9 Serializer enable 0
    Uint16 COUNT_SERIALIZER_1:1;        // 10 Serializer enable 1
    Uint16 COUNT_SERIALIZER_2:1;        // 11 Serializer enable 2
    Uint16 FSM_EXTRA_SEL0_0:1;          // 12 FSM extra_sel0 for 0
    Uint16 FSM_EXTRA_SEL1_0:1;          // 13 FSM extra_sel1 for 0
    Uint16 FSM_EXTRA_SEL0_1:1;          // 14 FSM extra_sel0 for 1
    Uint16 FSM_EXTRA_SEL1_1:1;          // 15 FSM extra_sel1 for 1
    Uint16 FSM_EXTRA_SEL0_2:1;          // 16 FSM extra_sel0 for 2
    Uint16 FSM_EXTRA_SEL1_2:1;          // 17 FSM extra_sel1 for 2
    Uint16 COUNT0_MATCH1_TAP_EN:1;      // 18 Match1 Tap Enable for Counter 0
    Uint16 COUNT1_MATCH1_TAP_EN:1;      // 19 Match1 Tap Enable for Counter 1
    Uint16 COUNT2_MATCH1_TAP_EN:1;      // 20 Match1 Tap Enable for Counter 2
    Uint16 COUNT0_MATCH2_TAP_EN:1;      // 21 Match2 Tap Enable for Counter 0
    Uint16 COUNT1_MATCH2_TAP_EN:1;      // 22 Match2 Tap Enable for Counter 1
    Uint16 COUNT2_MATCH2_TAP_EN:1;      // 23 Match2 Tap Enable for Counter 2
    Uint16 COUNT0_LFSR_EN:1;            // 24 Enable LFSR mode for Counter 0
    Uint16 COUNT1_LFSR_EN:1;            // 25 Enable LFSR mode for Counter 1
    Uint16 COUNT2_LFSR_EN:1;            // 26 Enable LFSR mode for Counter 2
    Uint16 rsvd1:5;                     // 31:27 Reserved
};

union CLB_MISC_CONTROL_REG {
    Uint32  all;
    struct  CLB_MISC_CONTROL_BITS  bit;
};

struct CLB_OUTPUT_LUT_0_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_0_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_0_BITS  bit;
};

struct CLB_OUTPUT_LUT_1_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_1_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_1_BITS  bit;
};

struct CLB_OUTPUT_LUT_2_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_2_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_2_BITS  bit;
};

struct CLB_OUTPUT_LUT_3_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_3_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_3_BITS  bit;
};

struct CLB_OUTPUT_LUT_4_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_4_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_4_BITS  bit;
};

struct CLB_OUTPUT_LUT_5_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_5_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_5_BITS  bit;
};

struct CLB_OUTPUT_LUT_6_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_6_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_6_BITS  bit;
};

struct CLB_OUTPUT_LUT_7_BITS {          // bits description
    Uint16 IN0:5;                       // 4:0 Select value for IN0 of output LUT
    Uint16 IN1:5;                       // 9:5 Select value for IN1 of output LUT
    Uint16 IN2:5;                       // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                        // 22:15 Output function for output LUT
    Uint16 rsvd1:9;                     // 31:23 Reserved
};

union CLB_OUTPUT_LUT_7_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_7_BITS  bit;
};

struct CLB_HLC_EVENT_SEL_BITS {         // bits description
    Uint16 EVENT0_SEL:5;                // 4:0 Event Select 0
    Uint16 EVENT1_SEL:5;                // 9:5 Event Select 1
    Uint16 EVENT2_SEL:5;                // 14:10 Event Select 2
    Uint32 EVENT3_SEL:5;                // 19:15 Event Select 3
    Uint16 ALT_EVENT0_SEL:1;            // 20 Event Select 3
    Uint16 ALT_EVENT1_SEL:1;            // 21 Event Select 3
    Uint16 ALT_EVENT2_SEL:1;            // 22 Event Select 3
    Uint16 ALT_EVENT3_SEL:1;            // 23 Event Select 3
    Uint16 rsvd1:8;                     // 31:24 Reserved
};

union CLB_HLC_EVENT_SEL_REG {
    Uint32  all;
    struct  CLB_HLC_EVENT_SEL_BITS  bit;
};


struct CLB_COUNT_MATCH_TAP_SEL_BITS {   // bits description
    Uint16 COUNT0_MATCH1:5;             // 4:0 Match1 tap select for Counter 0
    Uint16 COUNT1_MATCH1:5;             // 9:5 Match1 tap select for Counter 1
    Uint16 COUNT2_MATCH1:5;             // 14:10 Match1 tap select for Counter 2
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 COUNT0_MATCH2:5;             // 20:16 Match2 tap select for Counter 0
    Uint16 COUNT1_MATCH2:5;             // 25:21 Match2 tap select for Counter 1
    Uint16 COUNT2_MATCH2:5;             // 30:26 Match2 tap select for Counter 2
    Uint16 rsvd2:1;                     // 31 Reserved
};

union CLB_COUNT_MATCH_TAP_SEL_REG {
    Uint32  all;
    struct  CLB_COUNT_MATCH_TAP_SEL_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_0_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_0_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_0_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_1_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_1_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_1_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_2_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_2_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_2_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_3_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_3_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_3_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_4_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_4_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_4_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_5_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_5_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_5_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_6_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_6_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_6_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_7_BITS {    // bits description
    Uint16 LEVEL_1_SEL:1;               // 0 Level 1 Mux Select
    Uint16 LEVEL_2_SEL:2;               // 2:1 Level 2 Mux Select
    Uint16 LEVEL_3_SEL:2;               // 4:3 Level 3 Mux Select
    Uint16 SEL_GATING_CTRL:3;           // 7:5 Gating control mux select
    Uint16 SEL_RELEASE_CTRL:3;          // 10:8 Releast control mux select
    Uint16 HW_GATING_CTRL_SEL:1;        // 11 Select HW for gating control
    Uint16 HW_RLS_CTRL_SEL:1;           // 12 Select HW for release control
    Uint16 SEL_RAW_IN:1;                // 13 Select input mode for the CLB AOC
    Uint16 ASYNC_COND_EN:1;             // 14 Enable for conditioning
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_7_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_7_BITS  bit;
};

struct CLB_MISC_ACCESS_CTRL_BITS {      // bits description
    Uint16 SPIEN:1;                     // 0 Enable CLB SPI Buffer feature
    Uint16 BLKEN:1;                     // 1 Block Register write
    Uint16 rsvd1:14;                    // 15:2 Reserved
};

union CLB_MISC_ACCESS_CTRL_REG {
    Uint16  all;
    struct  CLB_MISC_ACCESS_CTRL_BITS  bit;
};

struct CLB_SPI_DATA_CTRL_HI_BITS {      // bits description
    Uint16 STRB:5;                      // 4:0 Select value for strobe
    Uint16 rsvd1:3;                     // 7:5 Reserved
    Uint16 SHIFT:5;                     // 12:8 Shift value select
    Uint16 rsvd2:3;                     // 15:13 Reserved
};

union CLB_SPI_DATA_CTRL_HI_REG {
    Uint16  all;
    struct  CLB_SPI_DATA_CTRL_HI_BITS  bit;
};

struct CLB_LOGIC_CONFIG_REGS {
    Uint32                                   rsvd1[1];                     // Reserved
    union   CLB_COUNT_RESET_REG              CLB_COUNT_RESET;              // Counter Block RESET
    union   CLB_COUNT_MODE_1_REG             CLB_COUNT_MODE_1;             // Counter Block MODE_1
    union   CLB_COUNT_MODE_0_REG             CLB_COUNT_MODE_0;             // Counter Block MODE_0
    union   CLB_COUNT_EVENT_REG              CLB_COUNT_EVENT;              // Counter Block EVENT
    union   CLB_FSM_EXTRA_IN0_REG            CLB_FSM_EXTRA_IN0;            // FSM Extra EXT_IN0
    union   CLB_FSM_EXTERNAL_IN0_REG         CLB_FSM_EXTERNAL_IN0;         // FSM EXT_IN0
    union   CLB_FSM_EXTERNAL_IN1_REG         CLB_FSM_EXTERNAL_IN1;         // FSM_EXT_IN1
    union   CLB_FSM_EXTRA_IN1_REG            CLB_FSM_EXTRA_IN1;            // FSM Extra_EXT_IN1
    union   CLB_LUT4_IN0_REG                 CLB_LUT4_IN0;                 // LUT4_0/1/2 IN0 input source
    union   CLB_LUT4_IN1_REG                 CLB_LUT4_IN1;                 // LUT4_0/1/2 IN1 input source
    union   CLB_LUT4_IN2_REG                 CLB_LUT4_IN2;                 // LUT4_0/1/2 IN2 input source
    union   CLB_LUT4_IN3_REG                 CLB_LUT4_IN3;                 // LUT4_0/1/2 IN3 input source
    Uint32                                   rsvd2[1];                     // Reserved
    union   CLB_FSM_LUT_FN1_0_REG            CLB_FSM_LUT_FN1_0;            // LUT function for FSM Unit 1 and Unit 0
    union   CLB_FSM_LUT_FN2_REG              CLB_FSM_LUT_FN2;              // LUT function for FSM Unit 2
    union   CLB_LUT4_FN1_0_REG               CLB_LUT4_FN1_0;               // LUT function for LUT4 block of Unit 1 and 0
    union   CLB_LUT4_FN2_REG                 CLB_LUT4_FN2;                 // LUT function for LUT4 block of Unit 2
    union   CLB_FSM_NEXT_STATE_0_REG         CLB_FSM_NEXT_STATE_0;         // FSM Next state equations for Unit 0
    union   CLB_FSM_NEXT_STATE_1_REG         CLB_FSM_NEXT_STATE_1;         // FSM Next state equations for Unit 1
    union   CLB_FSM_NEXT_STATE_2_REG         CLB_FSM_NEXT_STATE_2;         // FSM Next state equations for Unit 2
    union   CLB_MISC_CONTROL_REG             CLB_MISC_CONTROL;             // Static controls for Ctr,FSM
    union   CLB_OUTPUT_LUT_0_REG             CLB_OUTPUT_LUT_0;             // Inp Sel, LUT fns for Out0
    union   CLB_OUTPUT_LUT_1_REG             CLB_OUTPUT_LUT_1;             // Inp Sel, LUT fns for Out1
    union   CLB_OUTPUT_LUT_2_REG             CLB_OUTPUT_LUT_2;             // Inp Sel, LUT fns for Out2
    union   CLB_OUTPUT_LUT_3_REG             CLB_OUTPUT_LUT_3;             // Inp Sel, LUT fns for Out3
    union   CLB_OUTPUT_LUT_4_REG             CLB_OUTPUT_LUT_4;             // Inp Sel, LUT fns for Out4
    union   CLB_OUTPUT_LUT_5_REG             CLB_OUTPUT_LUT_5;             // Inp Sel, LUT fns for Out5
    union   CLB_OUTPUT_LUT_6_REG             CLB_OUTPUT_LUT_6;             // Inp Sel, LUT fns for Out6
    union   CLB_OUTPUT_LUT_7_REG             CLB_OUTPUT_LUT_7;             // Inp Sel, LUT fns for Out7
    union   CLB_HLC_EVENT_SEL_REG            CLB_HLC_EVENT_SEL;            // Event Selector register for the High Level controller
    union   CLB_COUNT_MATCH_TAP_SEL_REG      CLB_COUNT_MATCH_TAP_SEL;      // Counter tap values for match1 and match2 outputs
    union   CLB_OUTPUT_COND_CTRL_0_REG       CLB_OUTPUT_COND_CTRL_0;       // Output conditioning control for output 0
    union   CLB_OUTPUT_COND_CTRL_1_REG       CLB_OUTPUT_COND_CTRL_1;       // Output conditioning control for output 1
    union   CLB_OUTPUT_COND_CTRL_2_REG       CLB_OUTPUT_COND_CTRL_2;       // Output conditioning control for output 2
    union   CLB_OUTPUT_COND_CTRL_3_REG       CLB_OUTPUT_COND_CTRL_3;       // Output conditioning control for output 3
    union   CLB_OUTPUT_COND_CTRL_4_REG       CLB_OUTPUT_COND_CTRL_4;       // Output conditioning control for output 4
    union   CLB_OUTPUT_COND_CTRL_5_REG       CLB_OUTPUT_COND_CTRL_5;       // Output conditioning control for output 5
    union   CLB_OUTPUT_COND_CTRL_6_REG       CLB_OUTPUT_COND_CTRL_6;       // Output conditioning control for output 6
    union   CLB_OUTPUT_COND_CTRL_7_REG       CLB_OUTPUT_COND_CTRL_7;       // Output conditioning control for output 7
    union   CLB_MISC_ACCESS_CTRL_REG         CLB_MISC_ACCESS_CTRL;         // Miscellaneous Access and enable control
    union   CLB_SPI_DATA_CTRL_HI_REG         CLB_SPI_DATA_CTRL_HI;         // CLB to SPI buffer control High
};

struct PLU_IN_0SEL_BITS {    // bits description
    Uint16 PLU_IN_0SEL:9;               // 8:0 PLU INPUT0 select
    Uint16 PLU_IN_1SEL:9;               // 17:9 PLU INPUT1 select
    Uint16 PLU_IN_2SEL:9;               // 26:18 PLU INPUT2 select
    Uint16 rsvd2:5;                     // 31:27 Reserved
 };

union PLU_IN_0SEL_REG {
    Uint32  all;
    struct  PLU_IN_0SEL_BITS  bit;
};

struct PLU_IN_1SEL_BITS {    // bits description
    Uint16 PLU_IN_3SEL:9;               // 8:0 PLU INPUT3 select
    Uint16 PLU_IN_4SEL:9;               // 17:9 PLU INPUT4 select
    Uint16 PLU_IN_5SEL:9;               // 26:18 PLU INPUT5 select
    Uint16 rsvd2:5;                     // 31:27 Reserved
 };

union PLU_IN_1SEL_REG {
    Uint32  all;
    struct  PLU_IN_1SEL_BITS  bit;
};

struct PLU_IN_2SEL_BITS {    // bits description
    Uint16 PLU_IN_6SEL:9;               // 8:0 PLU INPUT6 select
    Uint16 PLU_IN_7SEL:9;               // 17:9 PLU INPUT7 select
    Uint16 rsvd2:14;                     // 31:18 Reserved
 };

union PLU_IN_2SEL_REG {
    Uint32  all;
    struct  PLU_IN_2SEL_BITS  bit;
};

struct RISING_DELAY_0_BITS {               // bits description
    Uint32 RISING_DELAY_0:24;                   // 23:0 Input0 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_0_REG {
    Uint16  all;
    struct  RISING_DELAY_0_BITS  bit;
};

struct FALLING_DELAY_0_BITS {               // bits description
    Uint32 FALLING_DELAY_0:24;                   // 23:0 Input0 falling delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union FALLING_DELAY_0_REG {
    Uint16  all;
    struct  FALLING_DELAY_0_BITS  bit;
};

struct RISING_DELAY_1_BITS {               // bits description
    Uint32 RISING_DELAY_1:24;                   // 23:0 Input1 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_1_REG {
    Uint16  all;
    struct  RISING_DELAY_1_BITS  bit;
};

struct FALLING_DELAY_1_BITS {               // bits description
    Uint32 FALLING_DELAY_1:24;                   // 23:0 Input1 falling delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union FALLING_DELAY_1_REG {
    Uint16  all;
    struct  FALLING_DELAY_1_BITS  bit;
};

struct RISING_DELAY_2_BITS {               // bits description
    Uint32 RISING_DELAY_2:24;                   // 23:0 Input2 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_2_REG {
    Uint16  all;
    struct  RISING_DELAY_2_BITS  bit;
};

struct FALLING_DELAY_2_BITS {               // bits description
    Uint32 FALLING_DELAY_2:24;                   // 23:0 Input2 falling delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union FALLING_DELAY_2_REG {
    Uint16  all;
    struct  FALLING_DELAY_2_BITS  bit;
};

struct RISING_DELAY_3_BITS {               // bits description
    Uint32 RISING_DELAY_3:24;                   // 23:0 Input3 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_3_REG {
    Uint16  all;
    struct  RISING_DELAY_3_BITS  bit;
};

struct FALLING_DELAY_3_BITS {               // bits description
    Uint32 FALLING_DELAY_3:24;                   // 23:0 Input3 falling delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union FALLING_DELAY_3_REG {
    Uint16  all;
    struct  FALLING_DELAY_3_BITS  bit;
};

struct RISING_DELAY_4_BITS {               // bits description
    Uint32 RISING_DELAY_4:24;                   // 23:0 Input4 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_4_REG {
    Uint16  all;
    struct  RISING_DELAY_4_BITS  bit;
};

struct FALLING_DELAY_4_BITS {               // bits description
    Uint32 FALLING_DELAY_4:24;                   // 23:0 Input4 falling delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union FALLING_DELAY_4_REG {
    Uint16  all;
    struct  FALLING_DELAY_4_BITS  bit;
};

struct RISING_DELAY_5_BITS {               // bits description
    Uint32 RISING_DELAY_5:24;                   // 23:0 Input5 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_5_REG {
    Uint16  all;
    struct  RISING_DELAY_5_BITS  bit;
};

struct FALLING_DELAY_5_BITS {               // bits description
    Uint32 FALLING_DELAY_5:24;                   // 23:0 Input5 falling delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union FALLING_DELAY_5_REG {
    Uint16  all;
    struct  FALLING_DELAY_5_BITS  bit;
};

struct RISING_DELAY_6_BITS {               // bits description
    Uint32 RISING_DELAY_6:24;                   // 23:0 Input6 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_6_REG {
    Uint16  all;
    struct  RISING_DELAY_6_BITS  bit;
};

struct FALLING_DELAY_6_BITS {               // bits description
    Uint32 FALLING_DELAY_6:24;                   // 23:0 Input6 falling delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union FALLING_DELAY_6_REG {
    Uint16  all;
    struct  FALLING_DELAY_6_BITS  bit;
};

struct RISING_DELAY_7_BITS {               // bits description
    Uint32 RISING_DELAY_7:24;                   // 23:0 Input7 rising delay
    Uint16 rsvd1:8;                             // 31:24 Reserved
};

union RISING_DELAY_7_REG {
    Uint16  all;
    struct  RISING_DELAY_7_BITS  bit;
};

struct FALLING_DELAY_7_BITS {               // bits description
    Uint32 FALLING_DELAY_7:24;                   // 23:0 Input7 falling delay
    Uint16 rsvd1:8;                              // 31:24 Reserved
};

union FALLING_DELAY_7_REG {
    Uint16  all;
    struct  FALLING_DELAY_7_BITS  bit;
};

struct LEVEL_23_ORDER_BITS {                // bits description
    Uint16 level_23_order_0:1;                // 0 CLB OUTLUT0 AOE level2 With the level3 processing order
    Uint16 level_23_order_1:1;                // 1 CLB OUTLUT1 AOE level2 With the level3 processing order
    Uint16 level_23_order_2:1;                // 2 CLB OUTLUT2 AOE level2 With the level3 processing order
    Uint16 level_23_order_3:1;                // 3 CLB OUTLUT3 AOE level2 With the level3 processing order
    Uint16 level_23_order_4:1;                // 4 CLB OUTLUT4 AOE level2 With the level3 processing order
    Uint16 level_23_order_5:1;                // 5 CLB OUTLUT5 AOE level2 With the level3 processing order
    Uint16 level_23_order_6:1;                // 6 CLB OUTLUT6 AOE level2 With the level3 processing order
    Uint16 level_23_order_7:1;                // 7 CLB OUTLUT7 AOE level2 With the level3 processing order
    Uint16 rsvd1:8;                           // 15:8 Reserved
    Uint16 rsvd1:16;                          // 31:16 Reserved
 };
union LEVEL_23_ORDER_REG {
    Uint32  all;
    struct  LEVEL_23_ORDER_BITS  bit;
};

struct RLS_TZ_SEL_BITS {                // bits description
    Uint16 RLS_TZ_SEL_0:1;                // 0 CLB OUTLUT0 level3 release Signal source selection
    Uint16 RLS_TZ_SEL_1:1;                // 1 CLB OUTLUT1 level3 release Signal source selection
    Uint16 RLS_TZ_SEL_2:1;                // 2 CLB OUTLUT2 level3 release Signal source selection
    Uint16 RLS_TZ_SEL_3:1;                // 3 CLB OUTLUT3 level3 release Signal source selection
    Uint16 RLS_TZ_SEL_4:1;                // 4 CLB OUTLUT4 level3 release Signal source selection
    Uint16 RLS_TZ_SEL_5:1;                // 5 CLB OUTLUT5 level3 release Signal source selection
    Uint16 RLS_TZ_SEL_6:1;                // 6 CLB OUTLUT6 level3 release Signal source selection
    Uint16 RLS_TZ_SEL_7:1;                // 7 CLB OUTLUT7 level3 release Signal source selection
    Uint16 rsvd1:8;                       // 15:8 Reserved
    Uint16 rsvd1:16;                      // 31:16 Reserved
 };
union RLS_TZ_SEL_REG {
    Uint32  all;
    struct  RLS_TZ_SEL_BITS  bit;
};

struct RLS_TZ_TYPE_BITS {                // bits description
    Uint16 RLS_TZ_TYPE_0:3;                // 2:0 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 3 Reserved
    Uint16 RLS_TZ_TYPE_1:3;                // 6:4 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 7 Reserved
    Uint16 RLS_TZ_TYPE_2:3;                // 10:8 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 11 Reserved
    Uint16 RLS_TZ_TYPE_3:3;                // 14:12 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 13 Reserved
    Uint16 RLS_TZ_TYPE_4:3;                // 18:16 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 19 Reserved
    Uint16 RLS_TZ_TYPE_5:3;                // 22:20 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 23 Reserved
    Uint16 RLS_TZ_TYPE_6:3;                // 26:24 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 27 Reserved
    Uint16 RLS_TZ_TYPE_7:3;                // 30:28 The TZ unsealing type 
    Uint16 rsvd1:1;                        // 31 Reserved
 };
union RLS_TZ_TYPE_REG {
    Uint32  all;
    struct  RLS_TZ_TYPE_BITS  bit;
};

struct RLS_TZ_CPU1_BITS {               // bits description
    Uint16 RLS_TZ_CPU1_0:1;                      // 0 CPU1 OUTLUT0 Unseal the configuration register
    Uint16 RLS_TZ_CPU1_1:1;                      // 1 CPU1 OUTLUT1 Unseal the configuration register
    Uint16 RLS_TZ_CPU1_2:1;                      // 2 CPU1 OUTLUT2 Unseal the configuration register
    Uint16 RLS_TZ_CPU1_3:1;                      // 3 CPU1 OUTLUT3 Unseal the configuration register
    Uint16 RLS_TZ_CPU1_4:1;                      // 4 CPU1 OUTLUT4 Unseal the configuration register
    Uint16 RLS_TZ_CPU1_5:1;                      // 5 CPU1 OUTLUT5 Unseal the configuration register
    Uint16 RLS_TZ_CPU1_6:1;                      // 6 CPU1 OUTLUT6 Unseal the configuration register
    Uint16 RLS_TZ_CPU1_7:1;                      // 7 CPU1 OUTLUT7 Unseal the configuration register
    Uint16 rsvd1:8;                              // 15:8 Reserved
    Uint16 rsvd1:16;                             // 31:16 Reserved
};

union RLS_TZ_CPU1_REG {
    Uint16  all;
    struct  RLS_TZ_CPU1_BITS  bit;
};

struct RLS_TZ_CPU2_BITS {               // bits description
    Uint16 RLS_TZ_CPU2_0:1;                      // 0 CPU2 OUTLUT0 Unseal the configuration register
    Uint16 RLS_TZ_CPU2_1:1;                      // 1 CPU2 OUTLUT1 Unseal the configuration register
    Uint16 RLS_TZ_CPU2_2:1;                      // 2 CPU2 OUTLUT2 Unseal the configuration register
    Uint16 RLS_TZ_CPU2_3:1;                      // 3 CPU2 OUTLUT3 Unseal the configuration register
    Uint16 RLS_TZ_CPU2_4:1;                      // 4 CPU2 OUTLUT4 Unseal the configuration register
    Uint16 RLS_TZ_CPU2_5:1;                      // 5 CPU2 OUTLUT5 Unseal the configuration register
    Uint16 RLS_TZ_CPU2_6:1;                      // 6 CPU2 OUTLUT6 Unseal the configuration register
    Uint16 RLS_TZ_CPU2_7:1;                      // 7 CPU2 OUTLUT7 Unseal the configuration register
    Uint16 rsvd1:8;                              // 15:8 Reserved
    Uint16 rsvd1:16;                             // 31:16 Reserved
};

union RLS_TZ_CPU2_REG {
    Uint16  all;
    struct  RLS_TZ_CPU2_BITS  bit;
};

struct CLB_LOGIC_CONTROL_REGS {
    union  PLU_IN_0SEL_REG                   PLU_IN_0SEL;                  // plu input0 1 2
    union  PLU_IN_1SEL_REG                   PLU_IN_1SEL;                   // plu input3 4 5
    union  PLU_IN_2SEL_REG                   PLU_IN_2SEL;                   // plu input6 7
    Uint32                                   rsvd1[17];                      // Reserved
    union  RISING_DELAY_0_REG                RISING_DELAY_0;                // RISING_DELAY of input0
    union  FALLING_DELAY_0_REG               FALLING_DELAY_0;               // FALLING_DELAY of input0
    union  RISING_DELAY_1_REG                RISING_DELAY_1;                // RISING_DELAY of input1
    union  FALLING_DELAY_1_REG               FALLING_DELAY_1;               // FALLING_DELAY of input1
    union  RISING_DELAY_2_REG                RISING_DELAY_2;                // RISING_DELAY of input2
    union  FALLING_DELAY_2_REG               FALLING_DELAY_2;               // FALLING_DELAY of input2
    union  RISING_DELAY_3_REG                RISING_DELAY_3;                // RISING_DELAY of input3
    union  FALLING_DELAY_3_REG               FALLING_DELAY_3;               // FALLING_DELAY of input3
    union  RISING_DELAY_4_REG                RISING_DELAY_4;                // RISING_DELAY of input4
    union  FALLING_DELAY_4_REG               FALLING_DELAY_4;               // FALLING_DELAY of input4
    union  RISING_DELAY_5_REG                RISING_DELAY_5;                // RISING_DELAY of input5
    union  FALLING_DELAY_5_REG               FALLING_DELAY_5;               // FALLING_DELAY of input5
    union  RISING_DELAY_6_REG                RISING_DELAY_6;                // RISING_DELAY of input6
    union  FALLING_DELAY_6_REG               FALLING_DELAY_6;               // FALLING_DELAY of input6
    union  RISING_DELAY_7_REG                RISING_DELAY_7;                // RISING_DELAY of input7
    union  FALLING_DELAY_7_REG               FALLING_DELAY_7;               // FALLING_DELAY of input7
    union  LEVEL_23_ORDER_REG                LEVEL_23_ORDER;                // OUTLUT AOE level2 With the level3 processing order
    union  RLS_TZ_SEL_REG                    RLS_TZ_SEL;                    // OUTLUT level3 release Signal source selection
    union  RLS_TZ_TYPE_REG                   RLS_TZ_TYPE;                   // The TZ unsealing type
    union  RLS_TZ_CPU1_REG                   RLS_TZ_CPU1;                  // CPU1 OUTLUT0 Unseal the configuration register
    union  RLS_TZ_CPU2_REG                   RLS_TZ_CPU2;                  // CPU2 OUTLUT0 Unseal the configuration register

};

struct CLB_LOAD_EN_BITS {               // bits description
    Uint16 LOAD_EN:1;                   // 0 Load Enable
    Uint16 GLOBAL_EN:1;                 // 1 Global Enable
    Uint16 STOP:1;                      // 2 Debug stop control
    Uint16 NMI_EN:1;                    // 3 NMI output enable
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union CLB_LOAD_EN_REG {
    Uint16  all;
    struct  CLB_LOAD_EN_BITS  bit;
};

struct CLB_LOAD_ADDR_BITS {             // bits description
    Uint16 ADDR:6;                      // 5:0 Indirect Address
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_LOAD_ADDR_REG {
    Uint32  all;
    struct  CLB_LOAD_ADDR_BITS  bit;
};

struct CLB_INPUT_FILTER_BITS {          // bits description
    Uint16 FILTER_IN_0:2;                      // 1:0 Input filter control 0
    Uint16 FILTER_IN_1:2;                      // 3:2 Input filter control 1
    Uint16 FILTER_IN_2:2;                      // 5:4 Input filter control 2
    Uint16 FILTER_IN_3:2;                      // 7:6 Input filter control 3
    Uint16 FILTER_IN_4:2;                      // 9:8 Input filter control 4
    Uint16 FILTER_IN_5:2;                      // 11:10 Input filter control 5
    Uint16 FILTER_IN_6:2;                      // 13:12 Input filter control 6
    Uint16 FILTER_IN_7:2;                      // 15:14 Input filter control 7
    Uint16 rsvd1:16;                     // 31:16 Reserved
};

union CLB_INPUT_FILTER_REG {
    Uint32  all;
    struct  CLB_INPUT_FILTER_BITS  bit;
};

struct CLB_IN_MUX_SEL_0_BITS {          // bits description
    Uint16 SEL_GP_IN_0:1;               // 0 Select GP register 0
    Uint16 SEL_GP_IN_1:1;               // 1 Select GP register 1
    Uint16 SEL_GP_IN_2:1;               // 2 Select GP register 2
    Uint16 SEL_GP_IN_3:1;               // 3 Select GP register 3
    Uint16 SEL_GP_IN_4:1;               // 4 Select GP register 4
    Uint16 SEL_GP_IN_5:1;               // 5 Select GP register 5
    Uint16 SEL_GP_IN_6:1;               // 6 Select GP register 6
    Uint16 SEL_GP_IN_7:1;               // 7 Select GP register 7
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLB_IN_MUX_SEL_0_REG {
    Uint32  all;
    struct  CLB_IN_MUX_SEL_0_BITS  bit;
};

struct CLB_BUF_PTR_BITS {               // bits description
    Uint16 PULL:8;                      // 7:0 Data pointer for pull
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 PUSH:8;                      // 23:16 Data pointer for pull
    Uint16 rsvd2:8;                     // 31:24 Reserved
};

union CLB_BUF_PTR_REG {
    Uint32  all;
    struct  CLB_BUF_PTR_BITS  bit;
};

//the following bit-field is modified to avoid byte access instruction
struct CLB_GP_REG_BITS {          // bits description
    Uint16 REG_GP_IN:8;                 // 0 Select GP register 0
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 SW_Gating_CTRL_0:1;               // 16 Software gating control for output 0 of the asynchronous output conditioning block
    Uint16 SW_Gating_CTRL_1:1;               // 17 Software gating control for output 1 of the asynchronous output conditioning block
    Uint16 SW_Gating_CTRL_2:1;               // 18 Software gating control for output 2 of the asynchronous output conditioning block
    Uint16 SW_Gating_CTRL_3:1;               // 19 Software gating control for output 3 of the asynchronous output conditioning block
    Uint16 SW_Gating_CTRL_4:1;               // 20 Software gating control for output 4 of the asynchronous output conditioning block
    Uint16 SW_Gating_CTRL_5:1;               // 21 Software gating control for output 5 of the asynchronous output conditioning block
    Uint16 SW_Gating_CTRL_6:1;               // 22 Software gating control for output 6 of the asynchronous output conditioning block
    Uint16 SW_Gating_CTRL_7:1;               // 23 Software gating control for output 7 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_0:1;                  // 24 Software release control for output 0 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_1:1;                  // 25 Software release control for output 1 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_2:1;                  // 26 Software release control for output 2 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_3:1;                  // 27 Software release control for output 3 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_4:1;                  // 28 Software release control for output 4 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_5:1;                  // 29 Software release control for output 5 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_6:1;                  // 30 Software release control for output 6 of the asynchronous output conditioning block
    Uint16 SW_rls_CTRL_7:1;                  // 31 Software release control for output 7 of the asynchronous output conditioning block
};

union CLB_GP_REG_REG {
    Uint32  all;
    struct  CLB_GP_REG_BITS  bit;
};

struct CLB_PRESCALE_CTRL_BITS {         // bits description
    Uint16 CLKEN:1;                     // 0 Enable the prescale clock generator
    Uint16 STRB:1;                      // 1 Enable the Strobe mode of operation
    Uint16 TAP:4;                       // 5:2 TAP Select value
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 PRESCALE:16;                 // 31:16 Value of prescale register
};

union CLB_PRESCALE_CTRL_REG {
    Uint32  all;
    struct  CLB_PRESCALE_CTRL_BITS  bit;
};

struct CLB_INTR_TAG_REG_BITS {          // bits description
    Uint16 TAG:6;                       // 5:0 Interrupt tag
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union CLB_INTR_TAG_REG_REG {
    Uint32  all;
    struct  CLB_INTR_TAG_REG_BITS  bit;
};

struct CLB_HLC_INSTR_READ_PTR_BITS {    // bits description
    Uint16 READ_PTR:5;                  // 4:0 HLC instruction read pointer
    Uint16 rsvd1:11;                    // 15:5 Reserved
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union CLB_HLC_INSTR_READ_PTR_REG {
    Uint32  all;
    struct  CLB_HLC_INSTR_READ_PTR_BITS  bit;
};

struct CLB_HLC_INSTR_VALUE_BITS {       // bits description
    Uint16 INSTR:12;                    // 11:0 HLC instruction value
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 rsvd1:16;                     // 31:16 Reserved
};

union CLB_HLC_INSTR_VALUE_REG {
    Uint32  all;
    struct  CLB_HLC_INSTR_VALUE_BITS  bit;
};

struct CLB_DBG_OUT_2_BITS {             // bits description
    Uint16 OUT:8;                       // 7:0 Outputs of CLB Async block
    Uint16 IN:16;                        // 23:8 CLB CELL Inputs
    Uint16 rsvd1:8;                    // 31:24 Reserved
};

union CLB_DBG_OUT_2_REG {
    Uint32  all;
    struct  CLB_DBG_OUT_2_BITS  bit;
};


struct CLB_DATA_EXCHANGE_REGS {
    union  CLB_LOAD_EN_REG                   CLB_LOAD_EN;                  // CLB enable
    Uint16                                   rsvd1[1];                     // Reserved
    union  CLB_LOAD_ADDR_BITS                CLB_LOAD_ADDR_BITS;           // Indirect address
    Uint32                                   CLB_LOAD_DATA;                // Indirect address  CLB_LOAD_DATA
    union   CLB_INPUT_FILTER_REG             CLB_INPUT_FILTER;             // Input filter selection for both edge detection and synchronizers
    union   CLB_IN_MUX_SEL_0_REG             CLB_IN_MUX_SEL_0;             // Input selection to decide between Signals and GP register
    Uint32                                   rsvd2[2];                           // Reserved
    union   CLB_BUF_PTR_REG                  CLB_BUF_PTR;                  // PUSH and PULL pointers
    union   CLB_GP_REG_REG                   CLB_GP_REG;                   // General purpose register for CELL inputs
    Uint32                                   CLB_OUT_EN;                   // CELL output enable register
    Uint32                                   rsvd3[2];                           // Reserved
    union   CLB_PRESCALE_CTRL_REG            CLB_PRESCALE_CTRL;            // Prescaler register control
    Uint32                                   rsvd4[3];                     // Reserved
    union   CLB_INTR_TAG_REG_REG             CLB_INTR_TAG_REG;             // Interrupt Tag register
    Uint32             					     CLB_LOCK;                     // Lock control register
    union   CLB_HLC_INSTR_READ_PTR_REG       CLB_HLC_INSTR_READ_PTR;       // HLC instruction read pointer
    union   CLB_HLC_INSTR_VALUE_REG          CLB_HLC_INSTR_VALUE;          // HLC instruction read value
    Uint32                                   rsvd5[3];                     // Reserved
    union   CLB_DBG_OUT_2_REG                CLB_DBG_OUT_2;                // Visibility for CLB inputs and final  asynchronous outputs
    Uint32                                   CLB_DBG_R0;                   // HLC R0 Register
    Uint32                                   CLB_DBG_R1;                   // HLC R1 Register
    Uint32                                   CLB_DBG_R2;                   // HLC R2 Register
    Uint32                                   CLB_DBG_R3;                   // HLC R3 Register
    Uint32                                   CLB_DBG_C0;                   // counter0 out Register
    Uint32                                   CLB_DBG_C1;                   // counter1 out Register
    Uint32                                   CLB_DBG_C2;                   // counter2 out Register
    union   CLB_DBG_OUT_REG                  CLB_DBG_OUT;                  //

  };

struct CLB_DATA_EXCHANGE_REGS {
    Uint32                                   CLB_PUSH[4];                  // CLB_PUSH FIFO Registers (from HLC)
    Uint16                                   rsvd1[15];                    // Reserved
    Uint32                                   CLB_PULL[4];                  // CLB_PULL FIFO Registers (TO HLC)
};

//---------------------------------------------------------------------------
// CLB External References & Function Declarations:
//
extern volatile struct CLB_LOGIC_CONFIG_REGS Clb1LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS Clb1LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS Clb1DataExchRegs;
extern volatile struct CLB_LOGIC_CONFIG_REGS Clb2LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS Clb2LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS Clb2DataExchRegs;
extern volatile struct CLB_LOGIC_CONFIG_REGS Clb3LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS Clb3LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS Clb3DataExchRegs;
extern volatile struct CLB_LOGIC_CONFIG_REGS Clb4LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS Clb4LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS Clb4DataExchRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
