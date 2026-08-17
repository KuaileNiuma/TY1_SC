/**
 *************************************************************************************
 * @file hw_int.h
 * @brief This file contains the definition of interrupt info.
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


#ifndef __ALB32R003X_INT_H
#define __ALB32R003X_INT_H

#ifdef __cplusplus
extern "C"{
#endif

 /* alb32r003x's External IRQn ID is from the hard-wired persperctive, 
    which has an offset mapped to the ECLIC IRQn.
    eg.: uart0's external interrupt id in alb32r003x is 32, while its ECLIC IRQn is 51 */
#define SOC_EXTERNAL_MAP_TO_ECLIC_IRQn_OFFSET      19
/* get alb32r003x's External IRQn from ECLIC external IRQn which indexs from 19 */
#define IRQn_MAP_TO_EXT_ID(IRQn)                   (IRQn - SOC_EXTERNAL_MAP_TO_ECLIC_IRQn_OFFSET)

/* ============================================================================================ */
/* ================                 Interrupt Number Definition                ================ */
/* ============================================================================================ */

/* ============================  Core Specific Interrupt Numbers  ============================= */
typedef enum IRQn { 
    Reserved0_IRQn  = 0, /*!<  Internal reserved */
    Reserved1_IRQn  = 1, /*!<  Internal reserved */
    Reserved2_IRQn  = 2, /*!<  Internal reserved */
    SysTimerSW_IRQn = 3, /*!<  System Timer SW interrupt for both M/S mode in ECLIC */
    Reserved3_IRQn  = 4, /*!<  Internal reserved */
    Reserved4_IRQn  = 5, /*!<  Internal reserved */
    Reserved5_IRQn  = 6, /*!<  Internal reserved */
    SysTimer_IRQn   = 7, /*!<  System Timer Interrupt for both M/S mode in ECLIC */
    Reserved6_IRQn  = 8, /*!<  Internal reserved */
    Reserved7_IRQn  = 9, /*!<  Internal reserved */
    Reserved8_IRQn  = 10, /*!<  Internal reserved */
    Reserved9_IRQn  = 11, /*!<  Internal reserved */
    Reserved10_IRQn = 12, /*!<  Internal reserved */
    Reserved11_IRQn = 13, /*!<  Internal reserved */
    Reserved12_IRQn = 14, /*!<  Internal reserved */
    Reserved13_IRQn = 15, /*!<  Internal reserved */
    InterCore_IRQn  = 16, /*!<  CIDU Inter Core Interrupt */
    Reserved15_IRQn = 17, /*!<  Internal reserved */
    Reserved16_IRQn = 18, /*!<  Internal reserved */

    /* ================  External Interrupt Numbers  ================ */
    SOC_INT19_IRQn = 19, /*!< Device Interrupt */
    SOC_INT20_IRQn = 20, /*!< Device Interrupt */
    SOC_INT21_IRQn = 21, /*!< Device Interrupt */
    SOC_INT22_IRQn = 22, /*!< Device Interrupt */
    SOC_INT23_IRQn = 23, /*!< Device Interrupt */
    SOC_INT24_IRQn = 24, /*!< Device Interrupt */
    SOC_INT25_IRQn = 25, /*!< Device Interrupt */
    SOC_INT26_IRQn = 26, /*!< Device Interrupt */
    SOC_INT27_IRQn = 27, /*!< Device Interrupt */
    SOC_INT28_IRQn = 28, /*!< Device Interrupt */
    SOC_INT29_IRQn = 29, /*!< Device Interrupt */
    SOC_INT30_IRQn = 30, /*!< Device Interrupt */
    SOC_INT31_IRQn = 31, /*!< Device Interrupt */
    SOC_INT32_IRQn = 32, /*!< Device Interrupt */
    SOC_INT33_IRQn = 33, /*!< Device Interrupt */
    SOC_INT34_IRQn = 34, /*!< Device Interrupt */
    SOC_INT35_IRQn = 35, /*!< Device Interrupt */
    SOC_INT36_IRQn = 36, /*!< Device Interrupt */
    SOC_INT37_IRQn = 37, /*!< Device Interrupt */
    SOC_INT38_IRQn = 38, /*!< Device Interrupt */
    SOC_INT39_IRQn = 39, /*!< Device Interrupt */
    SOC_INT40_IRQn = 40, /*!< Device Interrupt */
    SOC_INT41_IRQn = 41, /*!< Device Interrupt */
    SOC_INT42_IRQn = 42, /*!< Device Interrupt */
    SOC_INT43_IRQn = 43, /*!< Device Interrupt */
    SOC_INT44_IRQn = 44, /*!< Device Interrupt */
    SOC_INT45_IRQn = 45, /*!< Device Interrupt */
    SOC_INT46_IRQn = 46, /*!< Device Interrupt */
    SOC_INT47_IRQn = 47, /*!< Device Interrupt */
    SOC_INT48_IRQn = 48, /*!< Device Interrupt */
    SOC_INT49_IRQn = 49, /*!< Device Interrupt */
    SOC_INT50_IRQn = 50, /*!< Device Interrupt */
    SOC_INT51_IRQn = 51, /*!< Device Interrupt */
    SOC_INT52_IRQn = 52, /*!< Device Interrupt */
    SOC_INT53_IRQn = 53, /*!< Device Interrupt */
    SOC_INT54_IRQn = 54, /*!< Device Interrupt */
    SOC_INT55_IRQn = 55, /*!< Device Interrupt */
    SOC_INT56_IRQn = 56, /*!< Device Interrupt */
    SOC_INT57_IRQn = 57, /*!< Device Interrupt */
    SOC_INT58_IRQn = 58, /*!< Device Interrupt */
    SOC_INT59_IRQn = 59, /*!< Device Interrupt */
    SOC_INT60_IRQn = 60, /*!< Device Interrupt */
    SOC_INT61_IRQn = 61, /*!< Device Interrupt */
    SOC_INT62_IRQn = 62, /*!< Device Interrupt */
    SOC_INT63_IRQn = 63, /*!< Device Interrupt */
    SOC_INT64_IRQn = 64, /*!< Device Interrupt */
    SOC_INT65_IRQn = 65, /*!< Device Interrupt */
    SOC_INT66_IRQn = 66, /*!< Device Interrupt */
    SOC_INT67_IRQn = 67, /*!< Device Interrupt */
    SOC_INT68_IRQn = 68, /*!< Device Interrupt */
    SOC_INT69_IRQn = 69, /*!< Device Interrupt */
    SOC_INT70_IRQn = 70, /*!< Device Interrupt */
    SOC_INT71_IRQn = 71, /*!< Device Interrupt */
    SOC_INT72_IRQn = 72, /*!< Device Interrupt */
    SOC_INT73_IRQn = 73, /*!< Device Interrupt */
    SOC_INT74_IRQn = 74, /*!< Device Interrupt */
    SOC_INT75_IRQn = 75, /*!< Device Interrupt */
    SOC_INT76_IRQn = 76, /*!< Device Interrupt */
    SOC_INT77_IRQn = 77, /*!< Device Interrupt */
    SOC_INT78_IRQn = 78, /*!< Device Interrupt */
    SOC_INT79_IRQn = 79, /*!< Device Interrupt */
    SOC_INT80_IRQn = 80, /*!< Device Interrupt */
    SOC_INT81_IRQn = 81, /*!< Device Interrupt */
    SOC_INT82_IRQn = 82, /*!< Device Interrupt */
    SOC_INT83_IRQn = 83, /*!< Device Interrupt */
    SOC_INT84_IRQn = 84, /*!< Device Interrupt */
    SOC_INT85_IRQn = 85, /*!< Device Interrupt */
    SOC_INT86_IRQn = 86, /*!< Device Interrupt */
    SOC_INT87_IRQn = 87, /*!< Device Interrupt */
    SOC_INT88_IRQn = 88, /*!< Device Interrupt */
    SOC_INT89_IRQn = 89, /*!< Device Interrupt */
    SOC_INT90_IRQn = 90, /*!< Device Interrupt */
    SOC_INT91_IRQn = 91, /*!< Device Interrupt */
    SOC_INT92_IRQn = 92, /*!< Device Interrupt */
    SOC_INT93_IRQn = 93, /*!< Device Interrupt */
    SOC_INT94_IRQn = 94, /*!< Device Interrupt */
    SOC_INT95_IRQn = 95, /*!< Device Interrupt */
    SOC_INT96_IRQn = 96, /*!< Device Interrupt */
    SOC_INT97_IRQn = 97, /*!< Device Interrupt */
    SOC_INT98_IRQn = 98, /*!< Device Interrupt */
    SOC_INT99_IRQn = 99, /*!< Device Interrupt */
    SOC_INT100_IRQn = 100, /*!< Device Interrupt */
    SOC_INT101_IRQn = 101, /*!< Device Interrupt */
    SOC_INT102_IRQn = 102, /*!< Device Interrupt */
    SOC_INT103_IRQn = 103, /*!< Device Interrupt */
    SOC_INT104_IRQn = 104, /*!< Device Interrupt */
    SOC_INT105_IRQn = 105, /*!< Device Interrupt */
    SOC_INT106_IRQn = 106, /*!< Device Interrupt */
    SOC_INT107_IRQn = 107, /*!< Device Interrupt */
    SOC_INT108_IRQn = 108, /*!< Device Interrupt */
    SOC_INT109_IRQn = 109, /*!< Device Interrupt */
    SOC_INT110_IRQn = 110, /*!< Device Interrupt */
    SOC_INT111_IRQn = 111, /*!< Device Interrupt */
    SOC_INT112_IRQn = 112, /*!< Device Interrupt */
    SOC_INT113_IRQn = 113, /*!< Device Interrupt */
    SOC_INT114_IRQn = 114, /*!< Device Interrupt */
    SOC_INT115_IRQn = 115, /*!< Device Interrupt */
    SOC_INT116_IRQn = 116, /*!< Device Interrupt */
    SOC_INT117_IRQn = 117, /*!< Device Interrupt */
    SOC_INT118_IRQn = 118, /*!< Device Interrupt */
    SOC_INT119_IRQn = 119, /*!< Device Interrupt */
    SOC_INT120_IRQn = 120, /*!< Device Interrupt */
    SOC_INT121_IRQn = 121, /*!< Device Interrupt */
    SOC_INT122_IRQn = 122, /*!< Device Interrupt */
    SOC_INT123_IRQn = 123, /*!< Device Interrupt */
    SOC_INT124_IRQn = 124, /*!< Device Interrupt */
    SOC_INT125_IRQn = 125, /*!< Device Interrupt */
    SOC_INT126_IRQn = 126, /*!< Device Interrupt */
    SOC_INT127_IRQn = 127, /*!< Device Interrupt */
    SOC_INT128_IRQn = 128, /*!< Device Interrupt */
    SOC_INT129_IRQn = 129, /*!< Device Interrupt */
    SOC_INT130_IRQn = 130, /*!< Device Interrupt */
    SOC_INT131_IRQn = 131, /*!< Device Interrupt */
    SOC_INT132_IRQn = 132, /*!< Device Interrupt */
    SOC_INT133_IRQn = 133, /*!< Device Interrupt */
    SOC_INT134_IRQn = 134, /*!< Device Interrupt */
    SOC_INT135_IRQn = 135, /*!< Device Interrupt */
    SOC_INT136_IRQn = 136, /*!< Device Interrupt */
    SOC_INT137_IRQn = 137, /*!< Device Interrupt */
    SOC_INT138_IRQn = 138, /*!< Device Interrupt */
    SOC_INT139_IRQn = 139, /*!< Device Interrupt */
    SOC_INT140_IRQn = 140, /*!< Device Interrupt */
    SOC_INT141_IRQn = 141, /*!< Device Interrupt */
    SOC_INT142_IRQn = 142, /*!< Device Interrupt */
    SOC_INT143_IRQn = 143, /*!< Device Interrupt */
    SOC_INT144_IRQn = 144, /*!< Device Interrupt */
    SOC_INT145_IRQn = 145, /*!< Device Interrupt */
    SOC_INT146_IRQn = 146, /*!< Device Interrupt */
    SOC_INT147_IRQn = 147, /*!< Device Interrupt */
    SOC_INT148_IRQn = 148, /*!< Device Interrupt */
    SOC_INT149_IRQn = 149, /*!< Device Interrupt */
    SOC_INT150_IRQn = 150, /*!< Device Interrupt */
    SOC_INT151_IRQn = 151, /*!< Device Interrupt */
    SOC_INT152_IRQn = 152, /*!< Device Interrupt */
    SOC_INT153_IRQn = 153, /*!< Device Interrupt */
    SOC_INT154_IRQn = 154, /*!< Device Interrupt */
    SOC_INT155_IRQn = 155, /*!< Device Interrupt */
    SOC_INT156_IRQn = 156, /*!< Device Interrupt */
    SOC_INT157_IRQn = 157, /*!< Device Interrupt */
    SOC_INT158_IRQn = 158, /*!< Device Interrupt */
    SOC_INT159_IRQn = 159, /*!< Device Interrupt */
    SOC_INT160_IRQn = 160, /*!< Device Interrupt */
    SOC_INT161_IRQn = 161, /*!< Device Interrupt */
    SOC_INT162_IRQn = 162, /*!< Device Interrupt */
    SOC_INT163_IRQn = 163, /*!< Device Interrupt */
    SOC_INT164_IRQn = 164, /*!< Device Interrupt */
    SOC_INT165_IRQn = 165, /*!< Device Interrupt */
    SOC_INT166_IRQn = 166, /*!< Device Interrupt */
    SOC_INT167_IRQn = 167, /*!< Device Interrupt */
    SOC_INT168_IRQn = 168, /*!< Device Interrupt */
    SOC_INT169_IRQn = 169, /*!< Device Interrupt */
    SOC_INT170_IRQn = 170, /*!< Device Interrupt */
    SOC_INT171_IRQn = 171, /*!< Device Interrupt */
    SOC_INT172_IRQn = 172, /*!< Device Interrupt */
    SOC_INT173_IRQn = 173, /*!< Device Interrupt */
    SOC_INT174_IRQn = 174, /*!< Device Interrupt */
    SOC_INT175_IRQn = 175, /*!< Device Interrupt */
    SOC_INT176_IRQn = 176, /*!< Device Interrupt */
    SOC_INT177_IRQn = 177, /*!< Device Interrupt */
    SOC_INT178_IRQn = 178, /*!< Device Interrupt */
    SOC_INT179_IRQn = 179, /*!< Device Interrupt */
    SOC_INT180_IRQn = 180, /*!< Device Interrupt */
    SOC_INT181_IRQn = 181, /*!< Device Interrupt */
    SOC_INT182_IRQn = 182, /*!< Device Interrupt */
    SOC_INT183_IRQn = 183, /*!< Device Interrupt */
    SOC_INT184_IRQn = 184, /*!< Device Interrupt */
    SOC_INT185_IRQn = 185, /*!< Device Interrupt */
    SOC_INT186_IRQn = 186, /*!< Device Interrupt */
    SOC_INT187_IRQn = 187, /*!< Device Interrupt */
    SOC_INT188_IRQn = 188, /*!< Device Interrupt */
    SOC_INT189_IRQn = 189, /*!< Device Interrupt */
    SOC_INT190_IRQn = 190, /*!< Device Interrupt */
    SOC_INT191_IRQn = 191, /*!< Device Interrupt */
    SOC_INT192_IRQn = 192, /*!< Device Interrupt */
    SOC_INT193_IRQn = 193, /*!< Device Interrupt */
    SOC_INT194_IRQn = 194, /*!< Device Interrupt */
    SOC_INT195_IRQn = 195, /*!< Device Interrupt */
    SOC_INT196_IRQn = 196, /*!< Device Interrupt */
    SOC_INT197_IRQn = 197, /*!< Device Interrupt */
    SOC_INT198_IRQn = 198, /*!< Device Interrupt */
    SOC_INT199_IRQn = 199, /*!< Device Interrupt */
    SOC_INT200_IRQn = 200, /*!< Device Interrupt */
    SOC_INT201_IRQn = 201, /*!< Device Interrupt */
    SOC_INT202_IRQn = 202, /*!< Device Interrupt */
    SOC_INT203_IRQn = 203, /*!< Device Interrupt */
    SOC_INT204_IRQn = 204, /*!< Device Interrupt */
    SOC_INT205_IRQn = 205, /*!< Device Interrupt */
    SOC_INT206_IRQn = 206, /*!< Device Interrupt */
    SOC_INT207_IRQn = 207, /*!< Device Interrupt */
    SOC_INT208_IRQn = 208, /*!< Device Interrupt */
    SOC_INT209_IRQn = 209, /*!< Device Interrupt */
    SOC_INT210_IRQn = 210, /*!< Device Interrupt */
    SOC_INT211_IRQn = 211, /*!< Device Interrupt */
    SOC_INT212_IRQn = 212, /*!< Device Interrupt */
    SOC_INT213_IRQn = 213, /*!< Device Interrupt */
    SOC_INT214_IRQn = 214, /*!< Device Interrupt */
    SOC_INT215_IRQn = 215, /*!< Device Interrupt */
    SOC_INT216_IRQn = 216, /*!< Device Interrupt */
    SOC_INT217_IRQn = 217, /*!< Device Interrupt */
    SOC_INT218_IRQn = 218, /*!< Device Interrupt */
    SOC_INT219_IRQn = 219, /*!< Device Interrupt */
    SOC_INT220_IRQn = 220, /*!< Device Interrupt */
    SOC_INT221_IRQn = 221, /*!< Device Interrupt */
    SOC_INT222_IRQn = 222, /*!< Device Interrupt */
    SOC_INT223_IRQn = 223, /*!< Device Interrupt */
    SOC_INT224_IRQn = 224, /*!< Device Interrupt */
    SOC_INT225_IRQn = 225, /*!< Device Interrupt */
    SOC_INT226_IRQn = 226, /*!< Device Interrupt */
    SOC_INT227_IRQn = 227, /*!< Device Interrupt */
    SOC_INT228_IRQn = 228, /*!< Device Interrupt */
    SOC_INT229_IRQn = 229, /*!< Device Interrupt */
    SOC_INT230_IRQn = 230, /*!< Device Interrupt */
    SOC_INT231_IRQn = 231, /*!< Device Interrupt */
    SOC_INT232_IRQn = 232, /*!< Device Interrupt */
    SOC_INT233_IRQn = 233, /*!< Device Interrupt */
    SOC_INT234_IRQn = 234, /*!< Device Interrupt */
    SOC_INT235_IRQn = 235, /*!< Device Interrupt */
    SOC_INT236_IRQn = 236, /*!< Device Interrupt */
    SOC_INT237_IRQn = 237, /*!< Device Interrupt */
    SOC_INT238_IRQn = 238, /*!< Device Interrupt */
    SOC_INT239_IRQn = 239, /*!< Device Interrupt */
    SOC_INT240_IRQn = 240, /*!< Device Interrupt */
    SOC_INT241_IRQn = 241, /*!< Device Interrupt */
    SOC_INT242_IRQn = 242, /*!< Device Interrupt */
    SOC_INT243_IRQn = 243, /*!< Device Interrupt */
    SOC_INT244_IRQn = 244, /*!< Device Interrupt */
    SOC_INT245_IRQn = 245, /*!< Device Interrupt */
    SOC_INT246_IRQn = 246, /*!< Device Interrupt */
    SOC_INT247_IRQn = 247, /*!< Device Interrupt */
    SOC_INT248_IRQn = 248, /*!< Device Interrupt */
    SOC_INT249_IRQn = 249, /*!< Device Interrupt */
    SOC_INT250_IRQn = 250, /*!< Device Interrupt */
    SOC_INT251_IRQn = 251, /*!< Device Interrupt */
    SOC_INT252_IRQn = 252, /*!< Device Interrupt */
    SOC_INT253_IRQn = 253, /*!< Device Interrupt */
    SOC_INT254_IRQn = 254, /*!< Device Interrupt */
    SOC_INT255_IRQn = 255, /*!< Device Interrupt */
    SOC_INT256_IRQn = 256, /*!< Device Interrupt */
    SOC_INT257_IRQn = 257, /*!< Device Interrupt */
    SOC_INT258_IRQn = 258, /*!< Device Interrupt */
    SOC_INT259_IRQn = 259, /*!< Device Interrupt */
    SOC_INT260_IRQn = 260, /*!< Device Interrupt */
    SOC_INT261_IRQn = 261, /*!< Device Interrupt */
    SOC_INT262_IRQn = 262, /*!< Device Interrupt */
    SOC_INT263_IRQn = 263, /*!< Device Interrupt */
    SOC_INT264_IRQn = 264, /*!< Device Interrupt */
    SOC_INT265_IRQn = 265, /*!< Device Interrupt */
    SOC_INT266_IRQn = 266, /*!< Device Interrupt */
    SOC_INT267_IRQn = 267, /*!< Device Interrupt */
    SOC_INT268_IRQn = 268, /*!< Device Interrupt */
    SOC_INT269_IRQn = 269, /*!< Device Interrupt */
    SOC_INT270_IRQn = 270, /*!< Device Interrupt */
    SOC_INT271_IRQn = 271, /*!< Device Interrupt */
    SOC_INT272_IRQn = 272, /*!< Device Interrupt */
    SOC_INT273_IRQn = 273, /*!< Device Interrupt */
    SOC_INT274_IRQn = 274, /*!< Device Interrupt */
    SOC_INT275_IRQn = 275, /*!< Device Interrupt */
    SOC_INT276_IRQn = 276, /*!< Device Interrupt */

    #if defined(CFG_IRQ_NUM)
        SOC_INT_MAX = CFG_IRQ_NUM + SOC_EXTERNAL_MAP_TO_ECLIC_IRQn_OFFSET,
    #else
        SOC_INT_MAX,
    #endif
} IRQn_Type;

//#define ATIM1_CC_IRQn                              SOC_INT46_IRQn
//#define ATIM1_BRK_IRQn                             SOC_INT44_IRQn
//#define ATIM1_UP_IRQn                              SOC_INT50_IRQn
//#define ATIM1_TRG_IRQn                             SOC_INT48_IRQn
//
//#define ATIM2_CC_IRQn                              SOC_INT45_IRQn
//#define ATIM2_BRK_IRQn                             SOC_INT43_IRQn
//#define ATIM2_UP_IRQn                              SOC_INT49_IRQn
//#define ATIM2_TRG_IRQn                             SOC_INT47_IRQn
#define TIMER4_C2_IRQn                             SOC_INT87_IRQn
#define TIMER3_C2_IRQn                             SOC_INT88_IRQn
#define TIMER2_C2_IRQn                             SOC_INT89_IRQn
#define TIMER1_C2_IRQn                             SOC_INT90_IRQn
#define XINT5_IRQn                                 SOC_INT91_IRQn
#define XINT4_IRQn                                 SOC_INT92_IRQn
#define XINT3_IRQn                                 SOC_INT93_IRQn

#define TIMER4_C1_IRQn                             SOC_INT96_IRQn
#define TIMER3_C1_IRQn                             SOC_INT97_IRQn
#define TIMER2_C1_IRQn                             SOC_INT98_IRQn
#define EFLASH_IRQn                                SOC_INT99_IRQn
#define XFLASHC_IRQn                               SOC_INT100_IRQn
#define QSPI_OR_MSPI_IRQn                          SOC_INT101_IRQn
#define CSPI_IRQn                                  SOC_INT102_IRQn

#define EPG_IRQn                                   SOC_INT104_IRQn
#define SMC_IRQn                                   SOC_INT105_IRQn
#define NPU_IRQn                                   SOC_INT106_IRQn

#define GPIO5_IRQn                                 SOC_INT108_IRQn
#define GPIO4_IRQn                                 SOC_INT109_IRQn
#define GPIO3_IRQn                                 SOC_INT110_IRQn
#define GPIO2_IRQn                                 SOC_INT111_IRQn
#define GPIO1_IRQn                                 SOC_INT112_IRQn

#define AES_IRQn                                   SOC_INT114_IRQn
#define ECC_WARN_IRQn                              SOC_INT115_IRQn

#define ADCC4_IRQn                                 SOC_INT119_IRQn
#define ADCC3_IRQn                                 SOC_INT120_IRQn
#define ADCC2_IRQn                                 SOC_INT121_IRQn
#define ADCC_EVT_IRQn                              SOC_INT122_IRQn
#define ADCB4_IRQn                                 SOC_INT123_IRQn
#define ADCB3_IRQn                                 SOC_INT124_IRQn
#define ADCB2_IRQn                                 SOC_INT125_IRQn
#define ADCB_EVT_IRQn                              SOC_INT126_IRQn
#define ADCA4_IRQn                                 SOC_INT127_IRQn
#define ADCA3_IRQn                                 SOC_INT128_IRQn
#define ADCA2_IRQn                                 SOC_INT129_IRQn
#define ADCA_EVT_IRQn                              SOC_INT130_IRQn
#define DCC_IT_IRQn                                SOC_INT131_IRQn

#define CANFD2_IRQn                                SOC_INT139_IRQn
#define CANFD1_IRQn                                SOC_INT140_IRQn

#define SCI4_IRQn                                  SOC_INT143_IRQn
#define SCI3_IRQn                                  SOC_INT144_IRQn
#define SCI2_IRQn                                  SOC_INT145_IRQn
#define SCI1_IRQn                                  SOC_INT146_IRQn
#define RCC_IRQn                                   SOC_INT147_IRQn

#define I2C4_IRQn                                  SOC_INT154_IRQn

#define USART2_IRQn                                SOC_INT157_IRQn
#define USART1_IRQn                                SOC_INT158_IRQn

#define I2C2_IRQn                                  SOC_INT160_IRQn
#define I2C1_IRQn                                  SOC_INT161_IRQn
#define I2C3_IRQn                                  SOC_INT162_IRQn

#define FSI1_RXINT2_IRQn                           SOC_INT166_IRQn
#define FSI1_RXINT1_IRQn                           SOC_INT167_IRQn
#define FSI1_TXINT2_IRQn                           SOC_INT168_IRQn
#define FSI1_TXINT1_IRQn                           SOC_INT169_IRQn

#define DMAC2_C4_IRQn                              SOC_INT170_IRQn
#define DMAC1_C4_IRQn                              SOC_INT171_IRQn
#define DMAC2_C3_IRQn                              SOC_INT172_IRQn
#define DMAC1_C3_IRQn                              SOC_INT173_IRQn
#define DMAC2_C2_IRQn                              SOC_INT174_IRQn
#define DMAC1_C2_IRQn                              SOC_INT175_IRQn
#define DMAC2_C1_IRQn                              SOC_INT176_IRQn
#define DMAC1_C1_IRQn                              SOC_INT177_IRQn
#define DMASCH_IRQn                                SOC_INT178_IRQn
#define SDFM2DR4_IRQn                              SOC_INT179_IRQn
#define SDFM2DR3_IRQn                              SOC_INT180_IRQn
#define SDFM2DR2_IRQn                              SOC_INT181_IRQn
#define SDFM2DR1_IRQn                              SOC_INT182_IRQn

#define SPI4TX_IRQn                                SOC_INT187_IRQn
#define SPI4RX_IRQn                                SOC_INT188_IRQn
#define SPI3TX_IRQn                                SOC_INT189_IRQn
#define SPI3RX_IRQn                                SOC_INT190_IRQn
#define SPI2TX_IRQn                                SOC_INT191_IRQn
#define SPI2RX_IRQn                                SOC_INT192_IRQn
#define SPI1TX_IRQn                                SOC_INT193_IRQn
#define SPI1RX_IRQn                                SOC_INT194_IRQn
#define SDFM1DR4_IRQn                              SOC_INT195_IRQn
#define SDFM1DR3_IRQn                              SOC_INT196_IRQn
#define SDFM1DR2_IRQn                              SOC_INT197_IRQn
#define SDFM1DR1_IRQn                              SOC_INT198_IRQn

#define SDFM2_IRQn                                 SOC_INT201_IRQn
#define SDFM1_IRQn                                 SOC_INT202_IRQn
#define CLB4_IRQn                                  SOC_INT203_IRQn
#define CLB3_IRQn                                  SOC_INT204_IRQn
#define CLB2_IRQn                                  SOC_INT205_IRQn
#define CLB1_IRQn                                  SOC_INT206_IRQn

#define EQEP3_IRQn                                 SOC_INT208_IRQn
#define EQEP2_IRQn                                 SOC_INT209_IRQn
#define EQEP1_IRQn                                 SOC_INT210_IRQn

#define HRCAP4_IRQn                                SOC_INT215_IRQn
#define HRCAP3_IRQn                                SOC_INT216_IRQn
#define HRCAP2_IRQn                                SOC_INT217_IRQn
#define HRCAP1_IRQn                                SOC_INT218_IRQn

#define ECAP4_IRQn                                 SOC_INT223_IRQn
#define ECAP3_IRQn                                 SOC_INT224_IRQn
#define ECAP2_IRQn                                 SOC_INT225_IRQn
#define ECAP1_IRQn                                 SOC_INT226_IRQn

#define MBX_IRQn                                   SOC_INT228_IRQn

#define EPWM12_IRQn                                SOC_INT231_IRQn
#define EPWM11_IRQn                                SOC_INT232_IRQn
#define EPWM10_IRQn                                SOC_INT233_IRQn
#define EPWM9_IRQn                                 SOC_INT234_IRQn
#define EPWM8_IRQn                                 SOC_INT235_IRQn
#define EPWM7_IRQn                                 SOC_INT236_IRQn
#define EPWM6_IRQn                                 SOC_INT237_IRQn
#define EPWM5_IRQn                                 SOC_INT238_IRQn
#define EPWM4_IRQn                                 SOC_INT239_IRQn
#define EPWM3_IRQn                                 SOC_INT240_IRQn
#define EPWM2_IRQn                                 SOC_INT241_IRQn
#define EPWM1_IRQn                                 SOC_INT242_IRQn

#define EPWM12TZ_IRQn                              SOC_INT247_IRQn
#define EPWM11TZ_IRQn                              SOC_INT248_IRQn
#define EPWM10TZ_IRQn                              SOC_INT249_IRQn
#define EPWM9TZ_IRQn                               SOC_INT250_IRQn
#define EPWM8TZ_IRQn                               SOC_INT251_IRQn
#define EPWM7TZ_IRQn                               SOC_INT252_IRQn
#define EPWM6TZ_IRQn                               SOC_INT253_IRQn
#define EPWM5TZ_IRQn                               SOC_INT254_IRQn
#define EPWM4TZ_IRQn                               SOC_INT255_IRQn
#define EPWM3TZ_IRQn                               SOC_INT256_IRQn
#define EPWM2TZ_IRQn                               SOC_INT257_IRQn
#define EPWM1TZ_IRQn                               SOC_INT258_IRQn

#define PVDLP_IRQn                                 SOC_INT265_IRQn
#define WWDT_IRQn                                  SOC_INT266_IRQn
#define WDT_IRQn                                   SOC_INT267_IRQn
#define TIMER1_C1_IRQn                             SOC_INT268_IRQn

#define XINT2_IRQn                                 SOC_INT270_IRQn
#define XINT1_IRQn                                 SOC_INT271_IRQn

#define ADCC1_IRQn                                 SOC_INT272_IRQn
#define ADCB1_IRQn                                 SOC_INT273_IRQn
#define ADCA1_IRQn                                 SOC_INT274_IRQn
#define ADCC_IRQn                                  SOC_INT272_IRQn
#define ADCB_IRQn                                  SOC_INT273_IRQn
#define ADCA_IRQn                                  SOC_INT274_IRQn

#ifdef __cplusplus
}
#endif

#endif
