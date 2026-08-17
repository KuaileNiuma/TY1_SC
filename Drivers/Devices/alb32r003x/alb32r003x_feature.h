#ifndef __ALB32R003X_FEATURE_H
#define __ALB32R003X_FEATURE_H




// NOTE: This header file is used to tell us the Nuclei CPU Feature
// Currently for the evalsoc's cpu feature, we manually create this header file
// but for our customer, you can use nuclei_gen tool to generate it, and just replace it
// If you want to create it on your own, please modify these files:
// cpufeature.h, cpufeature.mk, openocd_evalsoc.cfg and evalsoc.memory
// and the iar project linker script files *.icf

// TODO: You can replace this file using the generated one by nuclei_gen tool

// The CFG_IREGION_BASE_ADDR is only defined in generated cpufeature.h or if you know the
// cpu iregion baseaddr you can set it

//#define CFG_IREGION_BASE_ADDR       0x00000000    // FIXME

#define CFG_CPU_SERIES              0xFFFFFF
#define CFG_CPU_VER                 0xFFFFFF

// CPU Features
#ifndef UNDEF_CFG_TMR_PRIVATE
#define CFG_TMR_PRIVATE
#endif
#ifndef UNDEF_CFG_HAS_CLIC
#define CFG_HAS_CLIC
#endif
//#define CFG_HAS_PLIC

// External Interrupt Number
#define CFG_IRQ_NUM                 272

#ifndef UNDEF_CFG_HAS_SMP
#define CFG_HAS_SMP
#endif

#ifndef UNDEF_CFG_HAS_PMP
#define CFG_HAS_PMP
#endif

#define CFG_PMP_ENTRY_NUM           8

//#define CFG_HAS_HPM
#define CFG_HPM_VER                 1

//#define CFG_HAS_IDU
//#define CFG_HAS_TEE
//#define CFG_HAS_SMPU
//#define CFG_HAS_ISA_SSTC
#define CFG_HAS_PMA
#define CFG_HAS_PMA_MACRO
#define CFG_PMA_CSR_NUM             8
#define CFG_PMA_SEC_CSR_NUM         8
#define CFG_HAS_STACK_CHECK
#define CFG_HAS_NICE
#define CFG_HAS_VNICE

#define CFG_HAS_ICACHE
#define CFG_HAS_DCACHE

// When PLIC present or TEE present, S-Mode also present
#if defined(CFG_HAS_PLIC) || defined(CFG_HAS_TEE) || defined(CFG_HAS_ISA_SSTC)
#define CFG_HAS_SMODE
#endif

#ifndef __ASSEMBLER__
/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */
// NOTE: macros __NUCLEI_CORE_REV/__NUCLEI_N_REV/__NUCLEI_NX_REV are removed now
// NOTE: __FPU_PRESENT/__BITMANIP_PRESENT/__DSP_PRESENT/__VECTOR_PRESENT can be probed by compiler's -march= option
// See https://gcc.gnu.org/onlinedocs/gcc/RISC-V-Options.html
/*!< Set to 0, 1, or 2, 0 not present, 1 single floating point unit present, 2 double floating point unit present */
#if !defined(__riscv_flen)
#define __FPU_PRESENT             0
#elif __riscv_flen == 32
#define __FPU_PRESENT             1
#else
#define __FPU_PRESENT             2
#endif

#if defined(__riscv_bitmanip)
#define __BITMANIP_PRESENT        1                     /*!< Set to 1 if Bitmainpulation extension is present */
#else
#define __BITMANIP_PRESENT        0                     /*!< Set to 1 if Bitmainpulation extension is present */
#endif
#if defined(__riscv_dsp)
#define __DSP_PRESENT             1                     /*!< Set to 1 if Partial SIMD(DSP) extension is present */
#else
#define __DSP_PRESENT             0                     /*!< Set to 1 if Partial SIMD(DSP) extension is present */
#endif
#if defined(__riscv_vector)
#define __VECTOR_PRESENT          1                     /*!< Set to 1 if Vector extension is present */
#else
#define __VECTOR_PRESENT          0                     /*!< Set to 1 if Vector extension is present */
#endif

// CPU IREGION Private Peripherals Offset against IREGION base specified by mirgb_info CSR
// These offset information can be found in selected cpu series databook's IREGION section.
// mirgb_info CSR can be found in Nuclei RISC-V ISA Spec
// You can also probe the cpu information using the general application/baremetal/cpuinfo case
// You can find the offset macros(IREGION_*_OFS) in riscv_encoding.h via search IREGION Offsets

// NORMAL CPU Configuration: From Nuclei SDK 0.6.0, we recommend you to update the CPU configuration macros defined in cpufeature.h
// Please don't modify the macros below directly

// NOTE: We use macros defined in cpufeature.h
// WARNING: Please dont modify macros directly below, you can change in cpufeature.h

// CPU Series and Version Configuration
// To set CPU REV and SERIES, just define CFG_CPU_VER/CFG_CPU_SERIES macros in cpufeature.h
#define __NUCLEI_CPU_REV            CFG_CPU_VER           /*!< Nuclei CPU Core Revision, version X.Y.Z, this is for the CPU Core Version, you get from Nuclei, eg. N300 v3.10.1, it should be 0x030A01 */
#define __NUCLEI_CPU_SERIES         CFG_CPU_SERIES        /*!< Nuclei CPU Series, such as 200/300/600/900, eg. 900 will be 0x0900 */

// CPU IREGION Base Address
// To set IREGION base, just define macro CFG_IREGION_BASE_ADDR in cpufeature.h
#ifndef CFG_IREGION_BASE_ADDR
// it is defined in system_cpu.c, you should not use this variable CpuIRegionBase
// SystemIRegionInfo variable in previous release is removed, you should avoid to use it
// you should use macro __IREGION_BASEADDR defined in alb32r003x.h
extern volatile unsigned long CpuIRegionBase;
#define CPU_IREGION_BASE            CpuIRegionBase
#else
#define CPU_IREGION_BASE            CFG_IREGION_BASE_ADDR
#endif
#define __IREGION_BASEADDR          (CPU_IREGION_BASE)

// ECLIC Configuration
// To enable ECLIC, just define macro CFG_HAS_CLIC/CFG_CLICINTCTLBITS/CFG_IRQ_NUM in cpufeature.h
#ifdef CFG_HAS_CLIC
#define __ECLIC_PRESENT             1
#ifdef CFG_CLICINTCTLBITS
#define __ECLIC_INTCTLBITS          CFG_CLICINTCTLBITS
#endif
#define __ECLIC_INTNUM              (CFG_IRQ_NUM + SOC_EXTERNAL_MAP_TO_ECLIC_IRQn_OFFSET)
#else
#define __ECLIC_PRESENT             0
#endif
#define __ECLIC_BASEADDR            (__IREGION_BASEADDR + IREGION_ECLIC_OFS)

// PLIC Configuration
// To enable PLIC, just define macro CFG_HAS_PLIC/CFG_IRQ_NUM in cpufeature.h
#ifdef CFG_HAS_PLIC
#define __PLIC_PRESENT              1
#define __PLIC_INTNUM               (CFG_IRQ_NUM + 1)
#else
#define __PLIC_PRESENT              0
#endif
#define __PLIC_BASEADDR             (__IREGION_BASEADDR + IREGION_PLIC_OFS)

// CPU System Timer Configuration
// To enable CPU System Timer, just define macro CFG_TMR_PRIVATE in cpufeature.h
#if defined(CFG_TMR_PRIVATE) || defined(CFG_TMR_BASE_ADDR)
#define __SYSTIMER_PRESENT          1
#else
#define __SYSTIMER_PRESENT          0
#endif
#ifdef CFG_TMR_BASE_ADDR    // Maybe using timer out of cpu for alb32r003x
#define __SYSTIMER_BASEADDR         (CFG_TMR_BASE_ADDR)
#else
#define __SYSTIMER_BASEADDR         (__IREGION_BASEADDR + IREGION_TIMER_OFS)
#endif
#define __CLINT_TIMER_BASEADDR      (__SYSTIMER_BASEADDR + 0x1000)

// CIDU Configuration
// To enable CIDU, just define macro CFG_HAS_IDU in cpufeature.h
#ifdef CFG_HAS_IDU
#define __CIDU_PRESENT              1
#else
#define __CIDU_PRESENT              0
#endif

#define __CIDU_BASEADDR             (__IREGION_BASEADDR + IREGION_IDU_OFS)

// SMP & CC Configuration
// To enable SMP & CC, just define macro CFG_HAS_SMP in cpufeature.h
#ifdef CFG_HAS_SMP
#define __SMPCC_PRESENT             1
#else
#define __SMPCC_PRESENT             0
#endif

#define __SMPCC_BASEADDR            (__IREGION_BASEADDR + IREGION_SMP_OFS)

// PMP Configuration
// To enable PMP, just define macro CFG_HAS_PMP/__PMP_ENTRY_NUM in cpufeature.h
#ifdef CFG_HAS_PMP
#define __PMP_PRESENT               1
#define __PMP_ENTRY_NUM             CFG_PMP_ENTRY_NUM
#else
#define __PMP_PRESENT               0
#define __PMP_ENTRY_NUM             0
#endif

// TEE/sPMP Configuration
// To enable TEE, just define macro CFG_HAS_TEE in cpufeature.h
// TEE required PMP, please also make sure CFG_HAS_PMP defined
#ifdef CFG_HAS_TEE
#define __TEE_PRESENT               1
#define __SPMP_PRESENT              1
#define __SPMP_ENTRY_NUM            CFG_PMP_ENTRY_NUM
#ifdef CFG_HAS_SMPU
#define __SMPU_PRESENT              1
#define __SMPU_ENTRY_NUM            __SPMP_ENTRY_NUM
#endif
#else
#define __TEE_PRESENT               0
#define __SPMP_PRESENT              0
#define __SMPU_PRESENT              0
#define __SPMP_ENTRY_NUM            0
#endif

// ICache Configuration
// To enable ICACHE, just define macro CFG_HAS_ICACHE in cpufeature.h
#ifdef CFG_HAS_ICACHE
#define __ICACHE_PRESENT            1
#else
#define __ICACHE_PRESENT            0
#endif

// DCache Configuration
// To enable DCACHE, just define macro CFG_HAS_DCACHE in cpufeature.h
#ifdef CFG_HAS_DCACHE
#define __DCACHE_PRESENT            1
#else
#define __DCACHE_PRESENT            0
#endif

// CCM Configuration
// To enable CCM, just define macro CFG_HAS_IOCC in cpufeature.h
#ifdef CFG_HAS_IOCC
#define __CCM_PRESENT               1
#else
#define __CCM_PRESENT               0
#endif

// NICE Configuration
// To enable NICE, just define macro CFG_HAS_NICE in cpufeature.h
#ifdef CFG_HAS_NICE
#define __NICE_PRESENT              1
#else
#define __NICE_PRESENT              0
#endif

// VNICE Configuration
// To enable Vector NICE, just define macro CFG_HAS_VNICE in cpufeature.h
#ifdef CFG_HAS_VNICE
#define __VNICE_PRESENT             1
#else
#define __VNICE_PRESENT             0
#endif

#ifndef __INC_INTRINSIC_API
#define __INC_INTRINSIC_API         0                     /*!< Set to 1 if intrinsic api header files need to be included */
#endif

#define __Vendor_SysTickConfig      0                     /*!< Set to 1 if different SysTick Config is used */
#define __Vendor_EXCEPTION          0                     /*!< Set to 1 if vendor exception hander is present */

/*!< Set this timer hartid if you have only 1 hart in your cpu, and you know the timer hartid, just set it */
//#define __SYSTIMER_HARTID           0
#ifndef __HARTID_OFFSET
/**
 * If your hart index is different to your hartid, you must define this __HARTID_OFFSET macro.
 * For example, if your cpu has 4 harts, and hartid start from 3, so the __HARTID_OFFSET should set to 3.
 * Which means hartid 3-6 means hart index 0-3, this is useful for the timer software interrupt and timer interrupt trigger register location
 */
#define __HARTID_OFFSET             0
#endif

/* Define boot hart id */
#ifndef BOOT_HARTID
/**
 * Choosen boot hart id in current cluster when in soc system, need to align with the value defined in startup_<Device>.S,
 * should start from 0, taken the mhartid bit 0-7 value
 */
#define BOOT_HARTID                 0
#endif

/** @} *//* End of group Configuration_of_NMSIS */


/* ========================================  Start of section using anonymous unions  ======================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/****************************************************************************
 * Platform definitions
 *****************************************************************************/

// Interrupt Handler Definitions
#define SOC_MTIMER_HANDLER          eclic_mtip_handler
#define SOC_SOFTINT_HANDLER         eclic_msip_handler

/* =========================================  End of section using anonymous unions  ========================================= */
#endif //__ASSEMBLER__

#endif
