/*
 * Copyright (c) 2019 Nuclei Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/******************************************************************************
 * \file     timer_irq.S
 * \brief    NMSIS Interrupt and Exception Handling Template File
 *  for Nuclei Eval SoC which support Nuclei N/NX class cores
 * \version  V1.00
 * \date     17 Dec 2019
 *
 ******************************************************************************/

#include "riscv_encoding.h"

/* TODO: Require Nuclei SDK >= 0.6.0, which introduced this cpufeature.h */
#include "cpufeature.h"

#include "mytimer.h"


/**
 * \brief  Global interrupt disabled
 * \details
 *  This function disable global interrupt.
 * \remarks
 *  - All the interrupt requests will be ignored by CPU.
 */
.macro DISABLE_MIE
    csrc CSR_MSTATUS, MSTATUS_MIE
.endm

/**
 * \brief  Macro for context save
 * \details
 * This macro save ABI defined caller saved registers in the stack.
 * \remarks
 * - This Macro could use to save context when you enter to interrupt
 * or exception
*/
/* Save caller registers */
.macro SAVE_CONTEXT

#ifdef  USE_HARD_SP
     addi sp, sp, -20*REGBYTES
     npush ra          //.insn r 0xb, 0x0, 0x0, x0, x1, x1   //__ASM volatile(".insn r 0xb, 0x0, 0x0, x0, %0, x1")
     npush2p tp,t1     //.insn r 0xb, 0x1, 0x10, x0, x4, x6  //__ASM volatile(".insn r 0xb, 0x1, 0x10, x0, %0, %1")
     npush3p a0,a2,a4  //.insn r 0xb, 0x1, 0x50, x10, x12, x14//__ASM volatile(".insn r 0xb, 0x1, 0x50, %0, %1, %2")
     npush2	a6,a7      //.insn r 0xb, 0x1, 0x0, x0, x16, x17 // __ASM volatile(".insn r 0xb, 0x1, 0x0, x0, %0, %1")
     npush2p t3,t5     //.insn r 0xb, 0x1, 0x10, x0, x28, x30  //__ASM volatile(".insn r 0xb, 0x1, 0x10, x0, %0, %1")
#else
#ifndef __riscv_32e
    addi sp, sp, -20*REGBYTES
#else
    addi sp, sp, -14*REGBYTES
#endif /* __riscv_32e */
    STORE x1, 0*REGBYTES(sp)
    STORE x4, 1*REGBYTES(sp)
    STORE x5, 2*REGBYTES(sp)
    STORE x6, 3*REGBYTES(sp)
    STORE x7, 4*REGBYTES(sp)
    STORE x10, 5*REGBYTES(sp)
    STORE x11, 6*REGBYTES(sp)
    STORE x12, 7*REGBYTES(sp)
    STORE x13, 8*REGBYTES(sp)
    STORE x14, 9*REGBYTES(sp)
    STORE x15, 10*REGBYTES(sp)

#ifndef __riscv_32e
    STORE x16, 14*REGBYTES(sp)
    STORE x17, 15*REGBYTES(sp)
    STORE x28, 16*REGBYTES(sp)
    STORE x29, 17*REGBYTES(sp)
    STORE x30, 18*REGBYTES(sp)
    STORE x31, 19*REGBYTES(sp)

#endif /* __riscv_32e */
#endif /*USE_HARD_SP*/
.endm

/**
 * \brief  Macro for restore caller registers
 * \details
 * This macro restore ABI defined caller saved registers from stack.
 * \remarks
 * - You could use this macro to restore context before you want return
 * from interrupt or exeception
 */
/* Restore caller registers */
.macro RESTORE_CONTEXT
#ifdef  USE_HARD_SP
    npopp t5 //.insn r 0xb, 0x0, 0x10, x30, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npopp t3 //.insn r 0xb, 0x0, 0x10, x28, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npopp a6 //.insn r 0xb, 0x0, 0x10, x16, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npopp a4 //.insn r 0xb, 0x0, 0x10, x14, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npopp a2 //.insn r 0xb, 0x0, 0x10, x12, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npopp a0 //.insn r 0xb, 0x0, 0x10, x10, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npopp t1 //.insn r 0xb, 0x0, 0x10, x6, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npopp tp //.insn r 0xb, 0x0, 0x10, x4, x0, x0 //__ASM volatile(".insn r 0xb, 0x0, 0x10, %0, x0, x0"
    npop ra //.insn r 0xb, 0x0, 0x0, x1, x0, x0 // __ASM volatile(".insn r 0xb, 0x0, 0x0, %0, x0, x0"
#ifndef __riscv_32e
    addi sp, sp, 20*REGBYTES
#else
    addi sp, sp, 14*REGBYTES
#endif
#else

    LOAD x1, 0*REGBYTES(sp)
    LOAD x4, 1*REGBYTES(sp)
    LOAD x5, 2*REGBYTES(sp)
    LOAD x6, 3*REGBYTES(sp)
    LOAD x7, 4*REGBYTES(sp)
    LOAD x10, 5*REGBYTES(sp)
    LOAD x11, 6*REGBYTES(sp)
    LOAD x12, 7*REGBYTES(sp)
    LOAD x13, 8*REGBYTES(sp)
    LOAD x14, 9*REGBYTES(sp)
    LOAD x15, 10*REGBYTES(sp)
#ifndef __riscv_32e
    LOAD x16, 14*REGBYTES(sp)
    LOAD x17, 15*REGBYTES(sp)
    LOAD x28, 16*REGBYTES(sp)
    LOAD x29, 17*REGBYTES(sp)
    LOAD x30, 18*REGBYTES(sp)
    LOAD x31, 19*REGBYTES(sp)
    /* De-allocate the stack space */
    addi sp, sp, 20*REGBYTES
#else
    /* De-allocate the stack space */
    addi sp, sp, 14*REGBYTES
#endif /* __riscv_32e */
#endif /*USE_HARD_SP*/

.endm

/**
 * \brief  Macro for save necessary CSRs to stack
 * \details
 * This macro store MCAUSE, MEPC, MSUBM to stack.
 */
.macro SAVE_CSR_CONTEXT
#ifdef CFG_HAS_CLIC
    /* Store CSR mcause to stack using pushmcause */
    csrrwi  x0, CSR_PUSHMCAUSE, 11
    /* Store CSR mepc to stack using pushmepc */
    csrrwi  x0, CSR_PUSHMEPC, 12
    /* Store CSR msub to stack using pushmsub */
    csrrwi  x0, CSR_PUSHMSUBM, 13
#else
    csrr x5, CSR_MEPC
    STORE x5,  12*REGBYTES(sp)
    csrr x5, CSR_MCAUSE
    STORE x5,  11*REGBYTES(sp)
#endif
.endm

/**
 * \brief  Macro for restore necessary CSRs from stack
 * \details
 * This macro restore MSUBM, MEPC, MCAUSE from stack.
 */
.macro RESTORE_CSR_CONTEXT
#ifdef CFG_HAS_CLIC
    LOAD x5,  13*REGBYTES(sp)
    csrw CSR_MSUBM, x5
#endif
    LOAD x5,  12*REGBYTES(sp)
    csrw CSR_MEPC, x5
    LOAD x5,  11*REGBYTES(sp)
    csrw CSR_MCAUSE, x5
.endm


/**
 * \brief  Non-Vector Interrupt Entry
 * \details
 * This function provide common entry functions for handling
 * non-vector interrupts
 * \remarks
 * This function provide a default non-vector interrupt entry.
 * ABI defined caller save register and some CSR registers need
 * to be saved before enter interrupt handler and be restored before return.
 */
.section      .text.irq
/* In CLIC mode, the interrupt entry must be 4bytes aligned */
.align 2
# gnu let .weak override .globl, but llvm will show warning
# see https://reviews.llvm.org/D90108
.global timer_irq_entry
.type timer_irq_entry, @function
/* This label will be set to MTVT2 register */
timer_irq_entry:
    /* Save the caller saving registers (context) */
    SAVE_CONTEXT
    /* Save the necessary CSR registers */
    //SAVE_CSR_CONTEXT

    /*
     * TODO: Call the exception handler function
     * By default, the function template is provided in
     * system_Device.c, you can adjust it as you want
     */
    call mytimerCHISR

    /* Restore the necessary CSR registers */
    // RESTORE_CSR_CONTEXT
    /* Restore the caller saving registers (context) */
    RESTORE_CONTEXT

    /* Return to regular code */
    mret

    .size timer_irq_entry, . - timer_irq_entry


