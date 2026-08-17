/**
 *************************************************************************************
 * @file gcc_alb32r003x_xflash.ld
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

/* ILM Memory Information */
ILM_MEMORY_PRESENT = 1;
ILM_MEMORY_BASE = 0x02000000;
ILM_MEMORY_SIZE = 0x20000;

/* DLM Memory Information */
DLM_MEMORY_PRESENT = 1;
DLM_MEMORY_BASE = 0x03000000;
DLM_MEMORY_SIZE = 0x10000;

/* xFlash Zero Wait Memory Information */
XFLASHZ_MEMORY_PRESENT = 1;
XFLASHZ_MEMORY_BASE = 0x0FFF0000;
XFLASHZ_MEMORY_SIZE = 0x10000;

/* xFlash Wait Memory Information */
XFLASH_MEMORY_PRESENT = 1;
XFLASH_MEMORY_BASE = 0x10000000;
XFLASH_MEMORY_SIZE = 8*1024*1024-0x10000;

/* SRAM Memory Information */
SRAM_MEMORY_PRESENT = 1;
SRAM_MEMORY_BASE = 0x18000000;
SRAM_MEMORY_SIZE = 0x10000;


MEMORY
{
  xflashz (rxa!w) : ORIGIN = XFLASHZ_MEMORY_BASE,     LENGTH = XFLASHZ_MEMORY_SIZE
  xflash (rxa!w) : ORIGIN = XFLASH_MEMORY_BASE,       LENGTH = XFLASH_MEMORY_SIZE
  ilm (rxa!w) : ORIGIN = ILM_MEMORY_BASE,             LENGTH = ILM_MEMORY_SIZE
  dlm (wxa!r) : ORIGIN = DLM_MEMORY_BASE,             LENGTH = DLM_MEMORY_SIZE
  sram (wxa!r) : ORIGIN = SRAM_MEMORY_BASE,           LENGTH = SRAM_MEMORY_SIZE
}

REGION_ALIAS("ROMZ", xflashz)
REGION_ALIAS("ROM" , xflash)
REGION_ALIAS("ILM", ilm)
REGION_ALIAS("DLM", dlm)
REGION_ALIAS("SRAM", sram)
/*REGION_ALIAS("RAM", ram)*/

SECTIONS
{
  /* To provide symbol __STACK_SIZE, __HEAP_SIZE and __SMP_CPU_CNT */
  PROVIDE(__STACK_SIZE = 2K);
  PROVIDE(__HEAP_SIZE = 2K);
  PROVIDE(__SMP_CPU_CNT = 1);
  __TOT_STACK_SIZE = __STACK_SIZE * __SMP_CPU_CNT;

  .init           :
  {
    *(.text.init)
    KEEP (*(SORT_NONE(.init)))
    . = ALIGN(4);
  } >ROMZ AT>ROMZ
  .text.ilm      :
  {
    /* vector table locate at ROM,run at RAM */
    *(.text.vtable)
    *(.text.vtable_s)
    /* xxx.o(.text .text.*) */
    *(.text.ilm) 
    . = ALIGN(8);
  } >ROM AT>ROM
  
  PROVIDE( _ilm_lma = LOADADDR(.text.ilm) );
  PROVIDE( _ilm = ADDR(.text.ilm) );
  PROVIDE( _eilm = . );

  .text           :
  {
    *(.text.unlikely .text.unlikely.*)
    *(.text.startup .text.startup.*)
    . = ALIGN(8);
    PROVIDE( __jvt_base$ = . );
    *(.text.tbljal .text.tbljal.*)
    *(.text .text.*)
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
  } >ROM AT>ROM

  PROVIDE( _text_lma = LOADADDR(.text) );
  PROVIDE( _text = ADDR(.text) );
  PROVIDE (_etext = .);
  PROVIDE (__etext = .);
  PROVIDE (etext = .);

  .data_sram   : ALIGN(8)
  {
    *(.data_sram .data_sram.*)
    . = ALIGN(4);
  } >SRAM AT>ROM
  
  PROVIDE( _data_sram_lma = LOADADDR(.data_sram) );
  PROVIDE( _data_sram = ADDR(.data_sram) );
  PROVIDE( _edata_sram = . );
  PROVIDE( eddata_sram = . );
  
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
    /* Fix undefined symbol: __eh_frame_start/__eh_frame_hdr_start/__eh_frame_end/__eh_frame_hdr_end */
    PROVIDE_HIDDEN (__eh_frame_hdr_start = .);
    *(.eh_frame_hdr)
    PROVIDE_HIDDEN (__eh_frame_hdr_end = .);
    PROVIDE_HIDDEN (__eh_frame_start = .);
    *(.eh_frame)
    PROVIDE_HIDDEN (__eh_frame_end = .);
    /* below sections are used for rt-thread */
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
  } >DLM AT>ROM

  
  .tdata           : ALIGN(8)
  {
    PROVIDE( __tls_base = . );
    *(.tdata .tdata.* .gnu.linkonce.td.*)
  } >DLM AT>ROM

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
  } >DLM AT>DLM


  .tbss_space (NOLOAD) : ALIGN(8)
  {
    . = . + SIZEOF(.tbss);
  } >DLM

  .bss (NOLOAD)   : ALIGN(8)
  {
    *(.sbss*)
    *(.gnu.linkonce.sb.*)
    *(.bss .bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)
    . = ALIGN(4);
  } >DLM


  
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
  } >DLM

  .stack  (NOLOAD) :
  {
    . = ALIGN(16);
    . = ORIGIN(DLM) + LENGTH(DLM) - __TOT_STACK_SIZE;
    PROVIDE( _heap_end = . );
    PROVIDE( __heap_end = . );
    PROVIDE( __StackLimit = . );
    PROVIDE( __StackBottom = . );
    . += __TOT_STACK_SIZE;
    . = ALIGN(16);
    PROVIDE( __StackTop = . );
    PROVIDE( _sp = . );
  } >DLM AT>DLM
}
