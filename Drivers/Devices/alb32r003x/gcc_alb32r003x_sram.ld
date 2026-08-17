/**
 *************************************************************************************
 * @file gcc_alb32r003x_sram.ld
 * @author Albatross
 * @brief
 * @version 1.0.0
 * @date 2025-07-30
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
 
OUTPUT_ARCH( "riscv" )

ENTRY( _start )

/* SRAM Memory Information */
SRAM_MEMORY_PRESENT = 1;
SRAM_MEMORY_BASE = 0x18010000;
SRAM_MEMORY_SIZE = 0x40000;
/* SRAM_MEMORY_ROM_SIZE must be smaller than SRAM_MEMORY_SIZE */
SRAM_MEMORY_ROM_SIZE = 0x30000;

MEMORY
{
  /* For alb32r003x using 200/300 core, it has a 128K sram started from 0xA0000000 */
  /* For alb32r003x using 600/900 core, it has a DDR ram started from 0xA0000000 */
  /* The sram ld script file use just 128K to make it works on all types of core */
  rom (rxa!w) : ORIGIN = SRAM_MEMORY_BASE,                           LENGTH = SRAM_MEMORY_ROM_SIZE
  ram (wxa!r) : ORIGIN = SRAM_MEMORY_BASE + SRAM_MEMORY_ROM_SIZE,    LENGTH = SRAM_MEMORY_SIZE - SRAM_MEMORY_ROM_SIZE
}

REGION_ALIAS("ROM", rom)
REGION_ALIAS("RAM", ram)
REGION_ALIAS("DATA_LMA", ram)

SECTIONS
{
  /* To provide symbol __STACK_SIZE, __HEAP_SIZE and __SMP_CPU_CNT */
  PROVIDE(__STACK_SIZE = 2K);
  PROVIDE(__HEAP_SIZE = 2K);
  PROVIDE(__SMP_CPU_CNT = 1);
  __TOT_STACK_SIZE = __STACK_SIZE * __SMP_CPU_CNT;

  .init           :
  {
    *(.text.vtable)
    *(.text.vtable_s)
    *(.text.init)
    KEEP (*(SORT_NONE(.init)))
    . = ALIGN(4);
  } >ROM AT>ROM

  .text           :
  {
    *(.text.unlikely .text.unlikely.*)
    *(.text.startup .text.startup.*)
    . = ALIGN(8);
    PROVIDE( __jvt_base$ = . );
    *(.text.tbljal .text.tbljal.*)
    *(.text .text.*)
    *(.ztf_ctx.0)
    *(EXCLUDE_FILE (*ztf.o) .ztf_ctx.*)
    *(.ztf_ctx.9)
    *(.gnu.linkonce.t.*)
    /* .fini */
    . = ALIGN(8);
    KEEP (*(SORT_NONE(.fini)))
    /* .preinit_array */
    . = ALIGN(8);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    /* .init_array */
    . = ALIGN(8);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .ctors))
    PROVIDE_HIDDEN (__init_array_end = .);
    /* .fini_array */
    . = ALIGN(8);
    PROVIDE_HIDDEN (__fini_array_start = .);
    PROVIDE_HIDDEN (__libc_fini = _fini);
    KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
    KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
    PROVIDE_HIDDEN (__fini_array_end = .);
    /* .ctors */
    . = ALIGN(8);
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    /* .dtors */
    . = ALIGN(8);
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
    KEEP (*(.ztf_ctx.*))
  } >ROM AT>ROM

  PROVIDE( _ilm_lma = LOADADDR(.text) );
  PROVIDE( _ilm = ADDR(.text) );
  PROVIDE( _eilm = . );
  PROVIDE( _text_lma = LOADADDR(.text) );
  PROVIDE( _text = ADDR(.text) );
  PROVIDE (_etext = .);
  PROVIDE (__etext = .);
  PROVIDE (etext = .);

  .data            : ALIGN(8)
  {
    KEEP(*(.data.ctest*))
    *(.data .data.*)
    *(.gnu.linkonce.d.*)
    . = ALIGN(8);
    PROVIDE( __global_pointer$ = . + 0x800 );
    *(.sdata .sdata.* .sdata*)
    *(.gnu.linkonce.s.*)
    /* readonly data placed in RAM for access speed */
    . = ALIGN(8);
    *(.srodata.cst16)
    *(.srodata.cst8)
    *(.srodata.cst4)
    *(.srodata.cst2)
    *(.srodata .srodata.*)
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)
    /* below sections are used for rt-thread */
    /* Fix undefined symbol: __eh_frame_start/__eh_frame_hdr_start/__eh_frame_end/__eh_frame_hdr_end */
    PROVIDE_HIDDEN (__eh_frame_hdr_start = .);
    *(.eh_frame_hdr)
    PROVIDE_HIDDEN (__eh_frame_hdr_end = .);
    PROVIDE_HIDDEN (__eh_frame_start = .);
    *(.eh_frame)
    PROVIDE_HIDDEN (__eh_frame_end = .);
    . = ALIGN(8);
    __rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(8);
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);
  } >RAM AT>ROM

  .tdata           : ALIGN(8)
  {
    PROVIDE( __tls_base = . );
    *(.tdata .tdata.* .gnu.linkonce.td.*)
  } >RAM AT>ROM

  PROVIDE( _data_lma = LOADADDR(.data) );
  PROVIDE( _data = ADDR(.data) );
  PROVIDE( _edata = . );
  PROVIDE( edata = . );

  PROVIDE( _fbss = . );
  PROVIDE( __bss_start = . );

  .tbss (NOLOAD)   : ALIGN(8)
  {
    *(.tbss .tbss.* .gnu.linkonce.tb.*)
    *(.tcommon)
    PROVIDE( __tls_end = . );
  } >RAM

  .tbss_space (NOLOAD) : ALIGN(8)
  {
    . = . + SIZEOF(.tbss);
  } >RAM

  .bss (NOLOAD)   : ALIGN(8)
  {
    *(.sbss*)
    *(.gnu.linkonce.sb.*)
    *(.bss .bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)
    . = ALIGN(4);
  } >RAM

  PROVIDE( _end = . );
  PROVIDE( end = . );

  /* Nuclei C Runtime Library requirements:
   * 1. heap need to be align at 16 bytes
   * 2. __heap_start and __heap_end symbol need to be defined
   * 3. reserved at least __HEAP_SIZE space for heap
   */
  .heap (NOLOAD)   : ALIGN(16)
  {
    . = ALIGN(16);
    PROVIDE( __heap_start = . );
    . += __HEAP_SIZE;
    . = ALIGN(16);
    PROVIDE( __heap_limit = . );
  } >RAM

  .stack  (NOLOAD) :
  {
    . = ALIGN(16);
    . = ORIGIN(RAM) + LENGTH(RAM) - __TOT_STACK_SIZE;
    PROVIDE( _heap_end = . );
    PROVIDE( __heap_end = . );
    PROVIDE( __StackLimit = . );
    PROVIDE( __StackBottom = . );
    . += __TOT_STACK_SIZE;
    . = ALIGN(16);
    PROVIDE( __StackTop = . );
    PROVIDE( _sp = . );
  } >RAM
}
