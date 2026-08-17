/**
  *************************************************************************************
  * @file startup.S
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
/* Please check the TODO items */

#include "riscv_encoding.h"

/* TODO: Require Nuclei SDK >= 0.6.0, which introduced this cpufeature.h */
#include "cpufeature.h"

/* If BOOT_HARTID is not defined, default value is 0 */
#ifndef BOOT_HARTID
    .equ BOOT_HARTID,    0
#endif

.macro DECLARE_INT_HANDLER  INT_HDL_NAME
#if defined(__riscv_xlen) && (__riscv_xlen == 32)
    .word \INT_HDL_NAME
#else
    .dword \INT_HDL_NAME
#endif
.endm

#ifdef CFG_HAS_CLIC
    .section .text.vtable

    .weak eclic_msip_handler
    .weak eclic_mtip_handler
    .weak eclic_uart0_int_handler
    .weak eclic_inter_core_int_handler
    .globl vector_base
    .type vector_base, @object
    .option push
    .option norelax
vector_base:
#if defined (RUN_ON_EFLASH) || defined (RUN_ON_XFLASH)
	DECLARE_INT_HANDLER     default_intexc_handler
#else
    j     _start                          /* 0: Reserved, default handler for vector table remapped cases */
    .align LOG_REGBYTES
#endif
    DECLARE_INT_HANDLER     default_intexc_handler          /* 1: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 2: Reserved */
    DECLARE_INT_HANDLER     eclic_msip_handler              /* 3: Machine software interrupt */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 4: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 5: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 6: Reserved */
    DECLARE_INT_HANDLER     eclic_mtip_handler              /* 7: Machine timer interrupt */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 8: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 9: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 10: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 11: Reserved */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 12: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 13: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 14: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 15: Reserved */

    DECLARE_INT_HANDLER     eclic_inter_core_int_handler    /* 16: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 17: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 18: Reserved */
    /* TODO Below are external interrupt handlers, please define them as your requirements, you need to increase or decrease it, and define correct interrupt handler name */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 19: Interrupt 19 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 20: Interrupt 20 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 21: Interrupt 21 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 22: Interrupt 22 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 23: Interrupt 23 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 24: Interrupt 24 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 25: Interrupt 25 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 26: Interrupt 26 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 27: Interrupt 27 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 28: Interrupt 28 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 29: Interrupt 29 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 30: Interrupt 30 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 31: Interrupt 31 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 32: Interrupt 32 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 33: Interrupt 33 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 34: Interrupt 34 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 35: Interrupt 35 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 36: Interrupt 36 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 37: Interrupt 37 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 38: Interrupt 38 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 39: Interrupt 39 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 40: Interrupt 40 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 41: Interrupt 41 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 42: Interrupt 42 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 43: Interrupt 43 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 44: Interrupt 44 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 45: Interrupt 45 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 46: Interrupt 46 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 47: Interrupt 47 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 48: Interrupt 48 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 49: Interrupt 49 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 50: Interrupt 50 */
    DECLARE_INT_HANDLER     default_intexc_handler         /* 51: Interrupt 51 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 52: Interrupt 52 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 53: Interrupt 53 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 54: Interrupt 54 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 55: Interrupt 55 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 56: Interrupt 56 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 57: Interrupt 57 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 58: Interrupt 58 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 59: Interrupt 59 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 60: Interrupt 60 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 61: Interrupt 61 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 62: Interrupt 62 */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 63: Interrupt 63 */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 64	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 65	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 66	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 67	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 68	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 69	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 70	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 71	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 72	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 73	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 74	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 75	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 76	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 77	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 78	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 79	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 80	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 81	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 82	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 83	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 84	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 85	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 86	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 87	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 88	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 89	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 90	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 91	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 92	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 93	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 94	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 95	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 96	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 97	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 98	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 99	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 100	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 101	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 102	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 103	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 104	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 105	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 106	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 107	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 108	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 109	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 110	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 111	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 112	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 113	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 114	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 115	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 116	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 117	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 118	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 119	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 120	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 121	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 122	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 123	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 124	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 125	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 126	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 127	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 128	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 129	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 130	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 131	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 132	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 133	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 134	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 135	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 136	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 137	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 138	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 139	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 140	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 141	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 142	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 143	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 144	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 145	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 146	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 147	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 148	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 149	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 150	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 151	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 152	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 153	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 154	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 155	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 156	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 157	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 158	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 159	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 160	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 161	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 162	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 163	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 164	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 165	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 166	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 167	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 168	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 169	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 170	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 171	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 172	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 173	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 174	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 175	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 176	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 177	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 178	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 179	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 180	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 181	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 182	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 183	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 184	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 185	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 186	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 187	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 188	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 189	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 190	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 191	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 192	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 193	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 194	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 195	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 196	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 197	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 198	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 199	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 200	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 201	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 202	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 203	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 204	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 205	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 206	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 207	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 208	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 209	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 210	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 211	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 212	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 213	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 214	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 215	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 216	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 217	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 218	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 219	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 220	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 221	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 222	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 223	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 224	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 225	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 226	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 227	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 228	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 229	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 230	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 231	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 232	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 233	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 234	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 235	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 236	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 237	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 238	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 239	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 240	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 241	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 242	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 243	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 244	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 245	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 246	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 247	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 248	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 249	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 250	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 251	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 252	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 253	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 254	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 255	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 256	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 257	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 258	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 259	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 260	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 261	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 262	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 263	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 264	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 265	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 266	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 267	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 268	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 269	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 270	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 271	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 272	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 273	: Interrupt  */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 274	: Interrupt  */

    .option pop

    .size vector_base, . - vector_base
#endif

    .section .text.init
    .globl _start
    .type _start, @function

/**
 * Reset Handler called on controller reset
 */
_start:
    /* ===== Startup Stage 1 ===== */
    /* Disable Global Interrupt */
    csrc CSR_MSTATUS, MSTATUS_MIE

#if defined (RUN_ON_EFLASH) || defined (RUN_ON_XFLASH)
    la a0, 0x23009000
    la a1, 0xdeadbeef
#if defined(RUN_ON_XFLASH)
/*0x0FFF0000-0x0FFFFFFF config xflash zero wait memrory;
  0x02000000-0x0201FFFF config ILM;
  0x03000000-0x0300FFFF config DLM;
  0x18000000-0x1800FFFF config SRAM;*/
     la a2, 0x00041123
#else
/*0x02000000-0x0201FFFF config ILM;
  0x03000000-0x0301FFFF config DLM;
  0x18000000-0x1800FFFF config SRAM;*/
    la a2, 0x00011223
#endif
    lw a3, 24(a0)
    ori	a3, a3, 1
    sw a1, 0(a0)
    sw a2, 4(a0)
    sw a3, 24(a0)
#endif


    /* If SMP_CPU_CNT is not defined,
     * assume that only 1 core is allowed to run,
     * the core hartid is defined via BOOT_HARTID.
     * other harts if run to here, just do wfi in __amp_wait
     */
#ifndef SMP_CPU_CNT
    /* take bit 0-7 for hart id in a local cluster */
    csrr a0, CSR_MHARTID
    andi a0, a0, 0xFF
    /* BOOT_HARTID is configurable in Makefile via BOOT_HARTID variable */
    li a1, BOOT_HARTID
    bne a0, a1, __amp_wait
#endif

    /* Initialize GP and TP and jump table base when zcmt enabled */
    .option push
    .option norelax
    la gp, __global_pointer$
    la tp, __tls_base
#if defined(__riscv_zcmt)
    la t0, __jvt_base$
    csrw CSR_JVT, t0
#endif
    .option pop

/* TODO if don't have SMP, you can remove the SMP_CPU_CNT related code */
#if defined(SMP_CPU_CNT) && (SMP_CPU_CNT > 1)
    /* Set correct sp for each cpu
     * each stack size is __STACK_SIZE
     * defined in linker script */
    lui t0, %hi(__STACK_SIZE)
    addi t0, t0, %lo(__STACK_SIZE)
    la sp, _sp
    csrr a0, CSR_MHARTID
    andi a0, a0, 0xFF
    li a1, 0
1:
    beq a0, a1, 2f
    sub sp, sp, t0
    addi a1, a1, 1
    j 1b
2:
#else
    /* Set correct sp for current cpu */
    la sp, _sp
#endif

    /*
     * Set the the NMI base mnvec to share
     * with mtvec by setting CSR_MMISC_CTL
     * bit 9 NMI_CAUSE_FFF to 1
     */
    li t0, MMISC_CTL_NMI_CAUSE_FFF
    csrs CSR_MMISC_CTL, t0

    /*
     * Enable Zc feature when compiled zcmp & zcmt
     */
    li t0, MMISC_CTL_ZC
#if defined(__riscv_zcmp) || defined(__riscv_zcmt)
    csrs CSR_MMISC_CTL, t0
#else
    csrc CSR_MMISC_CTL, t0
#endif

    /*
     * Set Exception Entry MTVEC to early_exc_entry
     * Due to settings above, Exception and NMI
     * will share common entry.
     * This early_exc_entry is only used during early
     * boot stage before main
     * Set default interrupt mode to CLINT interrupt mode
     */
    la t0, early_exc_entry
    csrw CSR_MTVEC, t0

    /* ===== Startup Stage 2 ===== */

    /* Enable FPU and Vector Unit if f/d/v exist in march */
#if defined(__riscv_flen) && __riscv_flen > 0
    /* Enable FPU, and set state to initial */
    li t0, MSTATUS_FS
    csrc mstatus, t0
    li t0, MSTATUS_FS_INITIAL
    csrs mstatus, t0
#endif

#if defined(__riscv_vector)
    /* Enable Vector, and set state to initial */
    li t0, MSTATUS_VS
    csrc mstatus, t0
    li t0, MSTATUS_VS_INITIAL
    csrs mstatus, t0
#endif

    /* TODO: Enable I/D Cache if present determined by cpufeature.h */
    /* This should be only used by nuclei_gen which generate a correct cpufeature.h */
    /* We use CPU_ISA macro to determine whether this cpufeature.h is generated or hand written */
    /* This is used to speedup data loading */
#ifdef CPU_ISA
#ifdef CFG_HAS_ICACHE
    csrsi CSR_MCACHE_CTL, MCACHE_CTL_IC_EN
#endif
#ifdef CFG_HAS_DCACHE
    li t0, MCACHE_CTL_DC_EN
    csrs CSR_MCACHE_CTL, t0
#endif
#endif

    /* Enable mcycle and minstret counter */
    csrci CSR_MCOUNTINHIBIT, 0x5

#if defined(SMP_CPU_CNT) && (SMP_CPU_CNT > 1)
    csrr a0, CSR_MHARTID
    li a1, BOOT_HARTID
    bne a0, a1, __skip_init
#endif

    .size _start, . - _start

.type __init_common, @function
__init_common:
    /* ===== Startup Stage 3 ===== */
    /*
     * Load text section from CODE ROM to CODE RAM
     * when text LMA is different with VMA
     */
    la a0, _ilm_lma
    la a1, _ilm
   /* If text LMA and VMA are equal
     * then no need to copy text section */
    beq a0, a1, 2f
    la a2, _eilm
    bgeu a1, a2, 2f

1:
    /* Load code section if necessary */
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, 1b

#if defined(ILM_DLM_ENABLE)
2:
    /* Load sram_data section */
    la a0, _data_sram_lma
    la a1, _data_sram
    /* If data vma=lma, no need to copy */
    beq a0, a1, 2f
    la a2, _edata_sram
    bgeu a1, a2, 2f

1:
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, 1b
#endif
2:
    /* Load data section */
    la a0, _data_lma
    la a1, _data
    /* If data vma=lma, no need to copy */
    beq a0, a1, 2f
    la a2, _edata
    bgeu a1, a2, 2f

1:
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, 1b
2:
    /* Clear bss section */
    la a0, __bss_start
    la a1, _end
    bgeu a0, a1, 2f
1:
    sw zero, (a0)
    addi a0, a0, 4
    bltu a0, a1, 1b
2:

    .size __init_common, . - __init_common

.globl _start_premain
.type _start_premain, @function
_start_premain:
    /*
     * Call vendor defined SystemInit to
     * initialize the micro-controller system
     * SystemInit will just be called by boot cpu
     */
    call SystemInit

    /*
     * Call C/C++ constructor start up code,
     * __libc_fini is defined in linker script,
     * so register_fini function will be called
     * and will run atexit (__libc_fini_array)
     * to do previous call atexit function
     */
    call __libc_init_array

    .size _start_premain, . - _start_premain

.type __skip_init, @function
__skip_init:
    /* Sync all harts at this function */
    call __sync_harts

    /* do pre-init steps before main */
    /* _premain_init will be called by each cpu
     * please make sure the implementation of __premain_int
     * considered this
     * it will update mtvec according to eclic present or not
     * mtvec will set to exc_entry
     */
    call _premain_init

    /* BPU cold bringup need time, so enable BPU before enter to main */
    li t0, MMISC_CTL_BPU
    csrs CSR_MMISC_CTL, t0

    // Interrupt is still disabled here
    /* ===== Call SMP Main Function  ===== */
    /* argc = argv = 0 */
    li a0, 0
    li a1, 0
#if defined(SMP_CPU_CNT) && (SMP_CPU_CNT > 1)
    /* The weak implementation of smp_main is in this file */
    call smp_main
#else
#ifdef RTOS_RTTHREAD
    // Call entry function when using RT-Thread
    call entry
#else
    call main
#endif
#endif
    /* do post-main steps after main
     * this function will be called by each cpu */
    call _postmain_fini

    .size __skip_init, . - __skip_init

.type __amp_wait, @function
__amp_wait:
1:
    wfi
    j 1b

    .size __amp_wait, . - __amp_wait

#if defined(SMP_CPU_CNT) && (SMP_CPU_CNT > 1)
/*
 * You can re-implement smp_main function in your code
 * to do smp boot process and handle multi harts
 */
.weak smp_main
.type smp_main, @function
smp_main:
    addi sp, sp, -2*REGBYTES
    STORE ra, 0*REGBYTES(sp)
    /* only boot hart goto main, other harts do wfi */
    csrr t0, CSR_MHARTID
    li t1, BOOT_HARTID
    beq t0, t1, 2f
1:
    wfi
    j 1b
2:
#ifdef RTOS_RTTHREAD
    // Call entry function when using RT-Thread
    call entry
#else
    call main
#endif
    LOAD ra, 0*REGBYTES(sp)
    addi sp, sp, 2*REGBYTES
    ret

    .size smp_main, . - smp_main
#endif

/* Early boot exception entry before main */
.align 6
.global early_exc_entry
.type early_exc_entry, @function
early_exc_entry:
    wfi
    j early_exc_entry

    .size early_exc_entry, . - early_exc_entry
