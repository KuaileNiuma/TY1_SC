/**
  *************************************************************************************
  * @file system_cpu.h
  * @brief This file implements the function of cpu driver.
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
#ifndef __SYSTEM_H__   /* ToDo: replace '<Device>' with your device name */
#define __SYSTEM_H__

// NOTE: Should never directly include this header, you should include alb32r003x.h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* =========================================================================================================================== */
/* ================                                  Exception Code Definition                                ================ */
/* =========================================================================================================================== */

typedef enum EXCn {
    /* =======================================  Nuclei N/NX Specific Exception Code  ======================================== */
    InsUnalign_EXCn          =   0,              /*!<  Instruction address misaligned */
    InsAccFault_EXCn         =   1,              /*!<  Instruction access fault */
    IlleIns_EXCn             =   2,              /*!<  Illegal instruction */
    Break_EXCn               =   3,              /*!<  Beakpoint */
    LdAddrUnalign_EXCn       =   4,              /*!<  Load address misaligned */
    LdFault_EXCn             =   5,              /*!<  Load access fault */
    StAddrUnalign_EXCn       =   6,              /*!<  Store or AMO address misaligned */
    StAccessFault_EXCn       =   7,              /*!<  Store or AMO access fault */
    UmodeEcall_EXCn          =   8,              /*!<  Environment call from User mode */
    SmodeEcall_EXCn          =   9,              /*!<  Environment call from S-mode */
    MmodeEcall_EXCn          =  11,              /*!<  Environment call from Machine mode */
    InsPageFault_EXCn        =  12,              /*!<  Instruction page fault */
    LdPageFault_EXCn         =  13,              /*!<  Load page fault */
    StPageFault_EXCn         =  15,              /*!<  Store or AMO page fault */
    StackOverflow_EXCn       =  24,              /*!<  Stack overflow fault */
    StackUnderflow_EXCn      =  25,              /*!<  Stack underflow fault */
    NMI_EXCn                 =  0xfff,           /*!<  NMI interrupt */
} EXCn_Type;

typedef struct EXC_Frame {
    unsigned long ra;                /* ra: x1, return address for jump */
    unsigned long tp;                /* tp: x4, thread pointer */
    unsigned long t0;                /* t0: x5, temporary register 0 */
    unsigned long t1;                /* t1: x6, temporary register 1 */
    unsigned long t2;                /* t2: x7, temporary register 2 */
    unsigned long a0;                /* a0: x10, return value or function argument 0 */
    unsigned long a1;                /* a1: x11, return value or function argument 1 */
    unsigned long a2;                /* a2: x12, function argument 2 */
    unsigned long a3;                /* a3: x13, function argument 3 */
    unsigned long a4;                /* a4: x14, function argument 4 */
    unsigned long a5;                /* a5: x15, function argument 5 */
    unsigned long cause;             /* cause: machine/supervisor mode cause csr register */
    unsigned long epc;               /* epc: machine/ supervisor mode exception program counter csr register */
    unsigned long msubm;             /* msubm: machine sub-mode csr register, nuclei customized, exclusive to machine mode */
#ifndef __riscv_32e
    unsigned long a6;                /* a6: x16, function argument 6 */
    unsigned long a7;                /* a7: x17, function argument 7 */
    unsigned long t3;                /* t3: x28, temporary register 3 */
    unsigned long t4;                /* t4: x29, temporary register 4 */
    unsigned long t5;                /* t5: x30, temporary register 5 */
    unsigned long t6;                /* t6: x31, temporary register 6 */
#endif
} EXC_Frame_Type;

/**
 * \brief Setup the microcontroller system.
 * \details
 * Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit(void);

/**
 * \brief  Update SystemCoreClock variable.
 * \details
 * Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate(void);

/**
 * \brief Dump Exception Frame
 */
void Exception_DumpFrame(unsigned long sp, uint8_t mode);

/**
 * \brief Register an exception handler for exception code EXCn
 */
extern void Exception_Register_EXC(uint32_t EXCn, unsigned long exc_handler);

/**
 * \brief Get current exception handler for exception code EXCn
 */
extern unsigned long Exception_Get_EXC(uint32_t EXCn);

/**
 * \brief Initialize Interrupt as Clint interrupt mode
 */
extern void CLINT_Interrupt_Init(void);

/**
 * \brief Initialize Interrupt
 */
extern void Interrupt_Init(void);

#if defined(__ECLIC_PRESENT) && (__ECLIC_PRESENT == 1)
/**
 * \brief Do ECLIC Interrupt configuration
 */
extern void ECLIC_Interrupt_Init(void);

/**
 * \brief  Initialize a specific IRQ and register the handler
 * \details
 * This function set vector mode, trigger mode and polarity, interrupt level and priority,
 * assign handler for specific IRQn.
 */
extern int32_t ECLIC_Register_IRQ(IRQn_Type IRQn, uint8_t shv, ECLIC_TRIGGER_Type trig_mode, uint8_t lvl, uint8_t priority, void* handler);
#endif

/**
 * \brief Register an core interrupt handler for clint/plic interrupt mode
 */
extern void Interrupt_Register_CoreIRQ(uint32_t irqn, unsigned long int_handler);

/**
 * \brief Register an plic external interrupt handler for clint/plic interrupt mode
 */
extern void Interrupt_Register_ExtIRQ(uint32_t irqn, unsigned long int_handler);

/**
 * \brief Register a riscv core interrupt and register the handler for clint/plic interrupt mode
 */
extern int32_t Core_Register_IRQ(uint32_t irqn, void *handler);

/**
 * \brief UnRegister a riscv core interrupt for clint/plic interrupt mode
 */
extern int32_t Core_UnRegister_IRQ(uint32_t irqn);

#if defined(__PLIC_PRESENT) && (__PLIC_PRESENT == 1)
/**
 * \brief  Do plic interrupt configuration for clint/plic interrupt mode
 */
extern void PLIC_Interrupt_Init(void);
/**
 * \brief  Register a specific plic interrupt and register the handler
 */
extern int32_t PLIC_Register_IRQ(uint32_t source, uint8_t priority, void *handler);
#endif

#if defined(__TEE_PRESENT) && (__TEE_PRESENT == 1)
/**
 * \brief Register an exception handler for exception code EXCn of supervisor mode
 */
extern void Exception_Register_EXC_S(uint32_t EXCn, unsigned long exc_handler);

/**
 * \brief Get current exception handler for exception code EXCn of supervisor mode
 */
extern unsigned long Exception_Get_EXC_S(uint32_t EXCn);

#if defined(__ECLIC_PRESENT) && (__ECLIC_PRESENT == 1)
/**
 * \brief  Initialize a specific IRQ and register the handler of supervisor mode
 * \details
 * This function set vector mode, trigger mode and polarity, interrupt level and priority,
 * assign handler for specific IRQn.
 */
extern int32_t ECLIC_Register_IRQ_S(IRQn_Type IRQn, uint8_t shv, ECLIC_TRIGGER_Type trig_mode, uint8_t lvl, uint8_t priority, void* handler);
#endif

#endif




void SystemClock_Update(uint32_t sys_clock);
uint32_t SystemClock_Get( void );
uint32_t SystemClock_Get_AHB ( void );
uint32_t SystemClock_Get_APBH( void );
uint32_t SystemClock_Get_APBL( void );

extern uint32_t get_cpu_freq(void);
extern void delay_ms(uint32_t count);
extern void delay_us(uint32_t count);
extern void nopDelay(uint32_t delay);


#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_H__ */
