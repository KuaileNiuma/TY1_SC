/** 
  *************************************************************************************
  * @file IQMathLib.c 
  * @author Albatross 
  * @brief This file contains the source file. 
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


#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "../inc/hw_types.h"
#include "IQMathLib.h"
#include "stdlib.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

//
// #define q15_ln2          0x58b9
// #define q13_pi           0x6488
// #define q14_pi           0xc910
// #define q14_halfPi       0x6488
// #define q14_quarterPi    0x3244
// #define q15_halfPi       0xc910
// #define q15_quarterPi    0x6488
// #define q15_invRoot2     0x5a82
// #define q15_tanSmall     0x0021
// #define q15_pointOne     0x0ccd
// #define q15_oneTenth     0x0ccd
#define iq28_twoPi 0x6487ed51
#define iq29_pi 0x6487ed51
#define iq29_halfPi 0x3243f6a8
#define iq30_pi 0xc90fdaa2
#define iq30_halfPi 0x6487ed51
#define iq30_quarterPi 0x3243f6a8
#define iq31_halfPi 0xc90fdaa2
#define iq31_quarterPi 0x6487ed51
#define iq31_invRoot2 0x5a82799a
#define iq31_tanSmall 0x0020c49b
#define iq31_ln2 0x58b90bfc
#define iq31_twoThird 0x55555555
#define iq31_pointOne 0x0ccccccd
#define iq31_oneTenth 0x0ccccccd
#define iq31_one 0x7fffffff

#define PI (3.1415926536) // The value of PI

#define TYPE_DEFAULT (0)  // Used to specify signed division on IQNdiv
#define TYPE_UNSIGNED (1) // Used to specify unsigned division on IQNdiv

// use TO SIN_SOC
#define TYPE_SIN (0) // Used to specify sine operation
#define TYPE_COS (1) // Used to specify cosine operation
#define TYPE_RAD (0) // Used to specify result in radians
#define TYPE_PU (1)  // Used to specify per-unit result

// use TO ATAN2
#define TYPEATAN2_PU (0)  // Used to specify per-unit result
#define TYPEATAN2_RAD (1) // Used to specify result in radians

// use TO SQRT
#define TYPE_ISQRT (0) // Specifies inverse square root operation type.
#define TYPE_SQRT (1)  // Specifies square root operation type.
#define TYPE_MAG (2)   // Specifies magnitude operation type.
#define TYPE_IMAG (3)  // Specifies inverse magnitude operation type.

// use TO exp/log
#define _IQ30exp_order 10
#define _IQ30log_order 14

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Local Constants                                 */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Local Variables                                 */
/* ========================================================================== */

/******************************** div **************************************/
const uint8_t _IQ6div_lookup[65] = {
    0x7F, 0x7D, 0x7B, 0x79, 0x78, 0x76, 0x74, 0x73,
    0x71, 0x6F, 0x6E, 0x6D, 0x6B, 0x6A, 0x68, 0x67,
    0x66, 0x65, 0x63, 0x62, 0x61, 0x60, 0x5F, 0x5E,
    0x5D, 0x5C, 0x5B, 0x5A, 0x59, 0x58, 0x57, 0x56,
    0x55, 0x54, 0x53, 0x52, 0x52, 0x51, 0x50, 0x4F,
    0x4E, 0x4E, 0x4D, 0x4C, 0x4C, 0x4B, 0x4A, 0x49,
    0x49, 0x48, 0x48, 0x47, 0x46, 0x46, 0x45, 0x45,
    0x44, 0x43, 0x43, 0x42, 0x42, 0x41, 0x41, 0x40, 0x40};

/******************************** cos **********************************/
const int32_t _IQ31CosLookup[52] = {
    2147483647, 2147221509, 2146435157, 2145124784,
    2143290709, 2140933381, 2138053374, 2134651392,
    2130728266, 2126284953, 2121322538, 2115842232,
    2109845374, 2103333428, 2096307983, 2088770754,
    2080723582, 2072168431, 2063107390, 2053542671,
    2043476608, 2032911661, 2021850407, 2010295547,
    1998249902, 1985716414, 1972698141, 1959198262,
    1945220073, 1930766987, 1915842531, 1900450350,
    1884594201, 1868277956, 1851505597, 1834281220,
    1816609030, 1798493340, 1779938574, 1760949261,
    1741530038, 1721685646, 1701420928, 1680740833,
    1659650409, 1638154806, 1616259270, 1593969148,
    1571289881, 1548227007, 1524786154, 1500973048};

/************************************* sin ************************************/
const int32_t _IQ31SinLookup[52] = {
    0, 33553067, 67097942, 100626436,
    134130364, 167601545, 201031810, 234412995,
    267736951, 300995544, 334180652, 367284176,
    400298032, 433214161, 466024527, 498721120,
    531295957, 563741086, 596048586, 628210568,
    660219183, 692066614, 723745087, 755246868,
    786564267, 817689637, 848615380, 879333946,
    909837834, 940119599, 970171848, 999987242,
    1029558505, 1058878415, 1087939815, 1116735610,
    1145258771, 1173502333, 1201459401, 1229123150,
    1256486826, 1283543749, 1310287313, 1336710990,
    1362808327, 1388572955, 1413998582, 1439079002,
    1463808091, 1488179813, 1512188216, 1535827441};

/*********************************** Asin *********************************/
const int32_t _IQ29Asin_coeffs[17][5] = {
    {3149732, 89392309, 962, 536870908, 0},
    {9526495, 88593699, 40416, 536870004, 8},
    {16138900, 86937495, 197996, 536863257, 118},
    {23156787, 84300941, 571586, 536839597, 683},
    {30770290, 80487362, 1290238, 536779215, 2591},
    {39200158, 75209531, 2531955, 536649108, 7714},
    {48710843, 68064494, 4547783, 536395980, 19650},
    {59627725, 58496679, 7695660, 535935197, 44970},
    {72359850, 45744506, 12489135, 535133733, 95261},
    {87431720, 28762778, 19668817, 533783769, 190507},
    {105527689, 6109335, 30308851, 531561517, 364646},
    {127555573, -24222672, 45978054, 527962405, 674787},
    {154739551, -65056242, 68987651, 522197749, 1216568},
    {188758701, -120414117, 102778528, 513027743, 2150044},
    {231956922, -196114786, 152538402, 498486871, 3743891},
    {287669673, -300718733, 226205346, 475423960, 6452123},
    {287669673, -300718733, 226205346, 475423960, 6452123} // repeat last set
};

/***************************** atan2 ****************************************/
const int32_t _IQ32atan_coeffs[132] = {
    -227484580, -9261, 683565333, 0,
    -224831707, -276221, 683574534, -108,
    -219602897, -1274081, 683638558, -1488,
    -211947885, -3443234, 683844263, -8015,
    -202081292, -7157693, 684311451, -27646,
    -190271590, -12705955, 685181594, -73201,
    -176827842, -20278271, 686604775, -162452,
    -162085247, -29960921, 688726164, -317494,
    -146390502, -41737384, 691673332, -563488,
    -130087951, -55495711, 695545487, -926914,
    -113507288, -71040919, 700405423, -1433559,
    -96953369 , -88110970, 706274644, -2106439,
    -80698479 , -106394779, 713131732, -2963878,
    -64977126 , -125550747, 720913749, -4017911,
    -49983270 , -145224548, 729520198, -5273132,
    -35869738 , -165065147, 738818936, -6726059,
    -22749467 , -184738347, 748653357, -8365003,
    -10698168 , -203937495, 758850169, -10170435,
    241989    , -222391214, 769227187, -12115749,
    10058068  , -239868310, 779600651, -14168336,
    18761768  , -256180110, 789791697, -16290870,
    26384816  , -271180628, 799631786, -18442695,
    32974556  , -284764983, 808966944, -20581230,
    38589896  , -296866517, 817660829, -22663305,
    43297701  , -307453021, 825596674, -24646386,
    47169678  , -316522417, 832678225, -26489630,
    50279770  , -324098234, 838829825, -28154764,
    52702039  , -330225080, 843995800, -29606769,
    54508999  , -334964326, 848139312, -30814380,
    55770360  , -338390095, 851240831, -31750408,
    56552116  , -340585675, 853296356, -32391901,
    56915945  , -341640355, 854315504, -32720182,
    56915945  , -341640355, 854315504, -32720182};

/**************************sqrt ********************************************/
const uint16_t _IQ14sqrt_lookup[96] = {
    0x7f02, 0x7d19, 0x7b46, 0x7986, 0x77d9, 0x763d, 0x74b2, 0x7335,
    0x71c7, 0x7066, 0x6f11, 0x6dc8, 0x6c8b, 0x6b58, 0x6a2f, 0x690f,
    0x67f8, 0x66ea, 0x65e4, 0x64e5, 0x63ee, 0x62fe, 0x6214, 0x6131,
    0x6054, 0x5f7d, 0x5eab, 0x5dde, 0x5d17, 0x5c54, 0x5b96, 0x5add,
    0x5a28, 0x5977, 0x58ca, 0x5821, 0x577c, 0x56da, 0x563c, 0x55a1,
    0x5509, 0x5475, 0x53e3, 0x5354, 0x52c9, 0x523f, 0x51b9, 0x5135,
    0x50b3, 0x5034, 0x4fb7, 0x4f3d, 0x4ec4, 0x4e4e, 0x4dda, 0x4d68,
    0x4cf7, 0x4c89, 0x4c1d, 0x4bb2, 0x4b49, 0x4ae1, 0x4a7c, 0x4a18,
    0x49b5, 0x4954, 0x48f4, 0x4896, 0x483a, 0x47de, 0x4784, 0x472c,
    0x46d4, 0x467e, 0x4629, 0x45d6, 0x4583, 0x4532, 0x44e1, 0x4492,
    0x4444, 0x43f7, 0x43aa, 0x435f, 0x4315, 0x42cc, 0x4284, 0x423c,
    0x41f6, 0x41b0, 0x416b, 0x4127, 0x40e4, 0x40a2, 0x4060, 0x4020};

/********************** exp table start**************************************/
const uint32_t _IQ30exp_coeffs[11] = {
    0x00000127, 0x00000B93, 0x00006806, 0x00034034,
    0x0016C16C, 0x00888888, 0x02AAAAAA, 0x0AAAAAAA,
    0x20000000, 0x40000000, 0x40000000};

const uint32_t _IQNexp_min[30] = {
    0xffffffff, 0xfffffffb, 0xfffffff0, 0xffffffd4, 0xffffff92, 0xfffffef6,
    0xfffffd93, 0xfffffa75, 0xfffff386, 0xffffe447, 0xffffc301, 0xffff7aeb,
    0xfffedfa7, 0xfffd92f1, 0xfffacd29, 0xfff4e8df, 0xffe86ed9, 0xffce17ea,
    0xff96a442, 0xff223163, 0xfe2e3482, 0xfc300c7d, 0xf8075fed, 0xef5d4dc1,
    0xdd57b752, 0xb7e9a644, 0x80000000, 0x80000000, 0x80000000, 0x80000000};

const uint32_t _IQNexp_max[30] = {
    0x00000029, 0x00000050, 0x0000009b, 0x0000012b, 0x00000240, 0x00000455,
    0x00000851, 0x00000ff1, 0x00001e7f, 0x00003a39, 0x00006ee7, 0x0000d2b7,
    0x00018f40, 0x0002f224, 0x00058b90, 0x000a65af, 0x0013687a, 0x00240b2c,
    0x00428ac8, 0x0079fe70, 0x00ddce9d, 0x018f40b5, 0x02c5c85f, 0x04da1ea7,
    0x0851591f, 0x0ddce9df, 0x162e42fe, 0x2145647e, 0x2c5c85fd, 0x2c5c85fd};
const uint16_t _IQNexp_offset[30] = {
    0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8,
    9, 9, 10, 11, 11, 12, 13, 13, 14,
    15, 15, 16, 17, 18, 18, 19, 20, 20};

const uint32_t _IQNexp_lookup1[22] = {
    0x00000004, 0x0000000A, 0x0000001D, 0x00000050, 0x000000DA, 0x00000251,
    0x0000064D, 0x00001122, 0x00002E93, 0x00007E9C, 0x00015829, 0x0003A788,
    0x0009EF0B, 0x001B00B5, 0x004966B1, 0x00C78665, 0x021E5D7A, 0x05C24D23,
    0x0FA79104, 0x2A8DB1F3, 0x73AC222D, 0x00000000};
const uint32_t _IQNexp_lookup2[22] = {
    0x00000002, 0x00000008, 0x00000015, 0x0000003B, 0x000000A0, 0x000001B4,
    0x000004A3, 0x00000C9B, 0x00002245, 0x00005D27, 0x0000FD38, 0x0002B053,
    0x00074F11, 0x0013DE16, 0x0036016B, 0x0092CD62, 0x018F0CCA, 0x043CBAF4,
    0x0B849A46, 0x1F4F2209, 0x551B63E7, 0xE758445B};
const uint32_t _IQNexp_lookup3[22] = {
    0x00000002, 0x00000005, 0x00000010, 0x0000002B, 0x00000076, 0x00000141,
    0x00000369, 0x00000946, 0x00001936, 0x0000448A, 0x0000BA4F, 0x0001FA71,
    0x000560A7, 0x000E9E22, 0x0027BC2C, 0x006C02D6, 0x01259AC4, 0x031E1995,
    0x087975E8, 0x1709348C, 0x3E9E4412, 0xAA36C7CF};
const uint32_t _IQNexp_lookup4[22] = {
    0x00000004, 0x0000000B, 0x00000020, 0x00000056, 0x000000EC, 0x00000282,
    0x000006D3, 0x0000128D, 0x0000326D, 0x00008914, 0x0001749E, 0x0003F4E2,
    0x000AC14E, 0x001D3C44, 0x004F7859, 0x00D805AC, 0x024B3589, 0x063C332B,
    0x10F2EBD0, 0x2E126918, 0x7D3C8824, 0x00000000};
const uint32_t _IQNexp_lookup5[22] = {
    0x00000003, 0x00000008, 0x00000017, 0x00000040, 0x000000AD, 0x000001D8,
    0x00000505, 0x00000DA6, 0x0000251A, 0x000064DB, 0x00011228, 0x0002E93D,
    0x0007E9C5, 0x0015829D, 0x003A7889, 0x009EF0B2, 0x01B00B59, 0x04966B12,
    0x0C786657, 0x21E5D7A1, 0x5C24D230, 0xFA791048};
const uint32_t _IQNexp_lookup6[22] = {
    0x00000002, 0x00000006, 0x00000011, 0x0000002F, 0x00000080, 0x0000015B,
    0x000003B1, 0x00000A0A, 0x00001B4C, 0x00004A34, 0x0000C9B6, 0x00022451,
    0x0005D27A, 0x000FD38A, 0x002B053B, 0x0074F112, 0x013DE165, 0x036016B2,
    0x092CD624, 0x18F0CCAF, 0x43CBAF42, 0xB849A460};
const uint32_t _IQNexp_lookup7[22] = {
    0x00000004, 0x0000000C, 0x00000022, 0x0000005E, 0x00000100, 0x000002B7,
    0x00000763, 0x00001415, 0x00003699, 0x00009469, 0x0001936D, 0x000448A2,
    0x000BA4F5, 0x001FA715, 0x00560A77, 0x00E9E224, 0x027BC2CA, 0x06C02D64,
    0x1259AC48, 0x31E1995F, 0x87975E85, 0x00000000};
const uint32_t _IQNexp_lookup8[22] = {
    0x00000003, 0x00000009, 0x00000019, 0x00000045, 0x000000BC, 0x00000200,
    0x0000056F, 0x00000EC7, 0x0000282B, 0x00006D32, 0x000128D3, 0x000326DB,
    0x00089144, 0x001749EA, 0x003F4E2A, 0x00AC14EE, 0x01D3C448, 0x04F78595,
    0x0D805AC8, 0x24B35891, 0x63C332BE, 0x00000000};
const uint32_t _IQNexp_lookup9[22] = {
    0x00000002, 0x00000006, 0x00000012, 0x00000032, 0x0000008A, 0x00000178,
    0x00000400, 0x00000ADF, 0x00001D8E, 0x00005057, 0x0000DA64, 0x000251A7,
    0x00064DB7, 0x00112288, 0x002E93D4, 0x007E9C55, 0x015829DC, 0x03A78891,
    0x09EF0B2A, 0x1B00B591, 0x4966B122, 0xC786657D};
const uint32_t _IQNexp_lookup10[22] = {
    0x00000005, 0x0000000D, 0x00000025, 0x00000065, 0x00000115, 0x000002F1,
    0x00000800, 0x000015BF, 0x00003B1C, 0x0000A0AF, 0x0001B4C9, 0x0004A34E,
    0x000C9B6E, 0x00224510, 0x005D27A9, 0x00FD38AB, 0x02B053B9, 0x074F1122,
    0x13DE1654, 0x36016B22, 0x92CD6245, 0x00000000};
const uint32_t _IQNexp_lookup11[22] = {
    0x00000003, 0x0000000A, 0x0000001B, 0x0000004B, 0x000000CB, 0x0000022A,
    0x000005E2, 0x00001000, 0x00002B7E, 0x00007639, 0x0001415E, 0x00036992,
    0x0009469C, 0x001936DC, 0x00448A21, 0x00BA4F53, 0x01FA7157, 0x0560A773,
    0x0E9E2244, 0x27BC2CA9, 0x6C02D645, 0x00000000};
const uint32_t _IQNexp_lookup12[22] = {
    0x00000002, 0x00000007, 0x00000014, 0x00000037, 0x00000096, 0x00000197,
    0x00000454, 0x00000BC5, 0x00002000, 0x000056FC, 0x0000EC73, 0x000282BC,
    0x0006D324, 0x00128D38, 0x00326DB8, 0x00891442, 0x01749EA7, 0x03F4E2AF,
    0x0AC14EE7, 0x1D3C4488, 0x4F785953, 0xD805AC8B};
const uint32_t _IQNexp_lookup13[22] = {
    0x00000002, 0x00000005, 0x0000000E, 0x00000028, 0x0000006E, 0x0000012C,
    0x0000032F, 0x000008A9, 0x0000178B, 0x00004000, 0x0000ADF8, 0x0001D8E6,
    0x00050579, 0x000DA648, 0x00251A71, 0x0064DB71, 0x01122885, 0x02E93D4F,
    0x07E9C55F, 0x15829DCF, 0x3A788911, 0x9EF0B2A6};
const uint32_t _IQNexp_lookup14[22] = {
    0x00000004, 0x0000000A, 0x0000001D, 0x00000051, 0x000000DC, 0x00000258,
    0x0000065F, 0x00001152, 0x00002F16, 0x00008000, 0x00015BF0, 0x0003B1CC,
    0x000A0AF2, 0x001B4C90, 0x004A34E2, 0x00C9B6E2, 0x0224510B, 0x05D27A9F,
    0x0FD38ABE, 0x2B053B9F, 0x74F11223, 0x00000000};
const uint32_t _IQNexp_lookup15[22] = {
    0x00000002, 0x00000008, 0x00000015, 0x0000003B, 0x000000A2, 0x000001B9,
    0x000004B0, 0x00000CBE, 0x000022A5, 0x00005E2D, 0x00010000, 0x0002B7E1,
    0x00076399, 0x001415E5, 0x00369920, 0x009469C4, 0x01936DC5, 0x0448A216,
    0x0BA4F53E, 0x1FA7157C, 0x560A773E, 0xE9E22447};
const uint32_t _IQNexp_lookup16[22] = {
    0x00000002, 0x00000005, 0x00000010, 0x0000002B, 0x00000077, 0x00000144,
    0x00000373, 0x00000960, 0x0000197D, 0x0000454A, 0x0000BC5A, 0x00020000,
    0x00056FC2, 0x000EC732, 0x00282BCB, 0x006D3240, 0x0128D389, 0x0326DB8A,
    0x0891442D, 0x1749EA7D, 0x3F4E2AF8, 0xAC14EE7C};
const uint32_t _IQNexp_lookup17[22] = {
    0x00000004, 0x0000000B, 0x00000020, 0x00000057, 0x000000EF, 0x00000289,
    0x000006E6, 0x000012C1, 0x000032FB, 0x00008A95, 0x000178B5, 0x00040000,
    0x000ADF85, 0x001D8E64, 0x00505796, 0x00DA6481, 0x0251A713, 0x064DB715,
    0x1122885A, 0x2E93D4FA, 0x7E9C55F1, 0x00000000};
const uint32_t _IQNexp_lookup18[22] = {
    0x00000003, 0x00000008, 0x00000017, 0x00000040, 0x000000AF, 0x000001DE,
    0x00000513, 0x00000DCC, 0x00002582, 0x000065F6, 0x0001152A, 0x0002F16A,
    0x00080000, 0x0015BF0A, 0x003B1CC9, 0x00A0AF2D, 0x01B4C902, 0x04A34E26,
    0x0C9B6E2B, 0x224510B5, 0x5D27A9F5, 0xFD38ABE2};
const uint32_t _IQNexp_lookup19[22] = {
    0x00000002, 0x00000006, 0x00000011, 0x0000002F, 0x00000081, 0x0000015F,
    0x000003BC, 0x00000A27, 0x00001B99, 0x00004B05, 0x0000CBED, 0x00022A55,
    0x0005E2D5, 0x00100000, 0x002B7E15, 0x00763992, 0x01415E5B, 0x03699205,
    0x09469C4C, 0x1936DC56, 0x448A216A, 0xBA4F53EA};
const uint32_t _IQNexp_lookup20[22] = {
    0x00000004, 0x0000000C, 0x00000023, 0x0000005F, 0x00000102, 0x000002BF,
    0x00000778, 0x0000144E, 0x00003732, 0x0000960A, 0x000197DB, 0x000454AA,
    0x000BC5AB, 0x00200000, 0x0056FC2A, 0x00EC7325, 0x0282BCB7, 0x06D3240B,
    0x128D3899, 0x326DB8AD, 0x891442D5, 0x00000000};
const uint32_t _IQNexp_lookup21[22] = {
    0x00000003, 0x00000009, 0x00000019, 0x00000046, 0x000000BE, 0x00000205,
    0x0000057F, 0x00000EF0, 0x0000289C, 0x00006E64, 0x00012C15, 0x00032FB6,
    0x0008A955, 0x00178B56, 0x00400000, 0x00ADF854, 0x01D8E64B, 0x0505796F,
    0x0DA64817, 0x251A7132, 0x64DB715A, 0x00000000};
const uint32_t _IQNexp_lookup22[22] = {
    0x00000002, 0x00000006, 0x00000012, 0x00000033, 0x0000008C, 0x0000017C,
    0x0000040B, 0x00000AFE, 0x00001DE1, 0x00005139, 0x0000DCC9, 0x0002582A,
    0x00065F6C, 0x001152AA, 0x002F16AC, 0x00800000, 0x015BF0A8, 0x03B1CC97,
    0x0A0AF2DF, 0x1B4C902E, 0x4A34E265, 0xC9B6E2B4};
const uint32_t _IQNexp_lookup23[22] = {
    0x00000005, 0x0000000D, 0x00000025, 0x00000067, 0x00000118, 0x000002F9,
    0x00000816, 0x000015FC, 0x00003BC2, 0x0000A272, 0x0001B993, 0x0004B055,
    0x000CBED8, 0x0022A555, 0x005E2D58, 0x01000000, 0x02B7E151, 0x0763992E,
    0x1415E5BF, 0x3699205C, 0x9469C4CB, 0x00000000};
const uint32_t _IQNexp_lookup24[22] = {
    0x00000003, 0x0000000A, 0x0000001B, 0x0000004B, 0x000000CE, 0x00000230,
    0x000005F3, 0x0000102C, 0x00002BF8, 0x00007785, 0x000144E5, 0x00037327,
    0x000960AA, 0x00197DB0, 0x00454AAA, 0x00BC5AB1, 0x02000000, 0x056FC2A2,
    0x0EC7325C, 0x282BCB7E, 0x6D3240B8, 0x00000000};
const uint32_t _IQNexp_lookup25[22] = {
    0x00000002, 0x00000007, 0x00000014, 0x00000037, 0x00000097, 0x0000019C,
    0x00000460, 0x00000BE6, 0x00002059, 0x000057F0, 0x0000EF0B, 0x000289CA,
    0x0006E64F, 0x0012C155, 0x0032FB61, 0x008A9555, 0x0178B563, 0x04000000,
    0x0ADF8545, 0x1D8E64B8, 0x505796FD, 0xDA648171};
const uint32_t _IQNexp_lookup26[22] = {
    0x00000002, 0x00000005, 0x0000000F, 0x00000029, 0x0000006F, 0x0000012F,
    0x00000338, 0x000008C1, 0x000017CD, 0x000040B3, 0x0000AFE1, 0x0001DE16,
    0x00051394, 0x000DCC9F, 0x002582AB, 0x0065F6C3, 0x01152AAA, 0x02F16AC6,
    0x08000000, 0x15BF0A8B, 0x3B1CC971, 0xA0AF2DFB};
const uint32_t _IQNexp_lookup27[22] = {
    0x00000004, 0x0000000B, 0x0000001E, 0x00000052, 0x000000DF, 0x0000025E,
    0x00000671, 0x00001183, 0x00002F9A, 0x00008167, 0x00015FC2, 0x0003BC2D,
    0x000A2728, 0x001B993F, 0x004B0556, 0x00CBED86, 0x022A5554, 0x05E2D58D,
    0x10000000, 0x2B7E1516, 0x763992E3, 0x00000000};
const uint32_t _IQNexp_lookup28[22] = {
    0x00000003, 0x00000008, 0x00000016, 0x0000003C, 0x000000A4, 0x000001BE,
    0x000004BD, 0x00000CE2, 0x00002306, 0x00005F35, 0x000102CF, 0x0002BF84,
    0x0007785A, 0x00144E51, 0x0037327F, 0x00960AAD, 0x0197DB0C, 0x0454AAA8,
    0x0BC5AB1B, 0x20000000, 0x56FC2A2C, 0xEC7325C6};
const uint32_t _IQNexp_lookup29[22] = {
    0x00000002, 0x00000006, 0x00000010, 0x0000002C, 0x00000078, 0x00000148,
    0x0000037C, 0x0000097B, 0x000019C5, 0x0000460D, 0x0000BE6B, 0x0002059E,
    0x00057F08, 0x000EF0B5, 0x00289CA3, 0x006E64FF, 0x012C155B, 0x032FB619,
    0x08A95551, 0x178B5636, 0x40000000, 0xADF85458};
const uint32_t _IQNexp_lookup30[22] = {
    0x00000004, 0x0000000C, 0x00000020, 0x00000058, 0x000000F1, 0x00000290,
    0x000006F9, 0x000012F6, 0x0000338A, 0x00008C1A, 0x00017CD7, 0x00040B3C,
    0x000AFE10, 0x001DE16B, 0x00513947, 0x00DCC9FF, 0x02582AB7, 0x065F6C33,
    0x1152AAA3, 0x2F16AC6C, 0x80000000, 0x00000000};
/**************************** exp table stop*******************************/
/********************************** log ***********************************/
const uint32_t _IQNlog_min[5] = {
    0x00000010, 0x00015FC3, 0x00960AAE, 0x08A95552, 0x2F16AC6D};

const uint32_t _IQ30log_coeffs[15] = {
    0xfb6db6db, 0x04ec4ec4, 0xfaaaaaab, 0x05d1745d, 0xf999999a,
    0x071c71c7, 0xf8000000, 0x09249249, 0xf5555556, 0x0ccccccc,
    0xf0000000, 0x15555555, 0xe0000000, 0x40000000, 0x00000000};
/* ========================================================================== */
/*                            Global Constants                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Local Function Prototypes                         */
/* ========================================================================== */
/***************atan2********/
int32_t _IQ31sqrt(int32_t a);

/* ========================================================================== */
/*                          Local Function Definitions                        */
/* ========================================================================== */

#if MATH_TYPE == IQ_MATH
//********************** Multiply functions  ************************//
/*   @name  __mpyx
 *   @brief  Multiply two values of long type.
 *
 *   @param iqNInput1       long type value input to be multiplied.
 *   @param iqNInput2       long type value input to be multiplied.
 *
 *   @return                long long type result of the multiplication.
 */
//  int64_t __mpyx(int32_t arg1, int32_t arg2) {			//fixme:: c++ compatible
//    return ((int64_t)arg1 * (int64_t)arg2);
//}

/*   @name  __mpyf_ul
 *   @brief  Multiply two values of unsigned long type.
 *
 *   @param iqNInput1       unsigned long type value input to be multiplied.
 *   @param iqNInput2       unsigned long type value input to be multiplied.
 *
 *   @return                unsigned long type result of the multiplication.
 */
  uint32_t __mpyf_ul(uint32_t arg1, uint32_t arg2) {
    return (uint32_t)(((uint64_t)arg1 * (uint64_t)arg2) >> 31);
}

/*   @name  __mpyf_ul_reuse_arg1
 *   @brief  Multiply two values of unsigned long type.
 *
 *   @param iqNInput1       unsigned long type value input to be multiplied.
 *   @param iqNInput2       unsigned long type value input to be multiplied.
 *
 *   @return                unsigned long type result of the multiplication.
 */
  int32_t __mpyf_ul_reuse_arg1(uint32_t arg1, uint32_t arg2) {
    /* This is identical to __mpyf_ul */
    return (uint32_t)(((uint64_t)arg1 * (uint64_t)arg2) >> 31);
}

/*   @name  __mpyf_l
 *   @brief  Multiply two values of  long type.
 *
 *   @param iqNInput1        long type value input to be multiplied.
 *   @param iqNInput2        long type value input to be multiplied.
 *
 *   @return                 long type result of the multiplication.
 */
  int32_t __mpyf_l(int32_t arg1, int32_t arg2) {
    return (int32_t)(((int64_t)arg1 * (int64_t)arg2) >> 31);
}

/*   @name  __mpy_l
 *   @brief  Multiply two values of  long type.
 *
 *   @param iqNInput1        long type value input to be multiplied.
 *   @param iqNInput2        long type value input to be multiplied.
 *
 *   @return                 long type result of the multiplication.
 */
  int32_t __mpy_l(int32_t arg1, int32_t arg2) {
    return (arg1 * arg2);
}

/*   @name  __mpyf_ul_reuse_arg1
 *   @brief  Multiply two values of unsigned long type.
 *
 *   @param iqNInput1       unsigned long type value input to be multiplied.
 *   @param iqNInput2       unsigned long type value input to be multiplied.
 *
 *   @return                unsigned long type result of the multiplication.
 */
  uint32_t __mpy_ul(uint32_t arg1, uint32_t arg2) {
    return (arg1 * arg2);
}

/*   @name  __mpyf_ul_reuse_arg1
 *   @brief  Multiply two values of unsigned int type.
 *
 *   @param iqNInput1       unsigned int type value input to be multiplied.
 *   @param iqNInput2       unsigned int type value input to be multiplied.
 *
 *   @return                unsigned int type result of the multiplication.
 */
  uint16_t __mpy_uw(uint16_t arg1, uint16_t arg2) {
    return (arg1 * arg2);
}

/*   @name  __mpyf_ul_reuse_arg1
 *   @brief  Multiply two values of unsigned long long  type.
 *
 *   @param iqNInput1       unsigned long long  type value input to be multiplied.
 *   @param iqNInput2       unsigned long long  type value input to be multiplied.
 *
 *   @return                unsigned long long  type result of the multiplication.
 */
 uint64_t __mpyx_u(uint32_t arg1, uint32_t arg2) {
    return ((uint64_t)arg1 * (uint64_t)arg2);
}

//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                   IQMath                                                 //
//                                                                          //
//                                                                         //
//////////////////////////////////////////////////////////////////////////////

/*******************************IQ TO float*****************************/

/**
 * @brief Converts IQN type to floating point.
 *
 * @param iqNInput        IQN type value input to be converted.
 * @param q_value         IQ format.
 *
 * @return                Conversion of iqNInput to floating point.
 */
  float __IQNtoF(int32_t iqNInput, int8_t q_value) {

    uint16_t ui16Exp;
    uint32_t uiq23Result;
    uint32_t uiq31Input;
    uint64_t uiq31Input1;

    /* Initialize exponent to the offset iq value. */
    ui16Exp = 0x3f80 + ((31 - q_value) * ((uint32_t)1 << (23 - 16)));

    /* Save the sign of the iqN input to the exponent construction. */
    if (iqNInput < 0) {
        ui16Exp |= 0x8000;
        uiq31Input = -iqNInput;
    } else if (iqNInput == 0) {
        return (0);
    } else {
        uiq31Input = iqNInput;
    }

    /* Scale the iqN input to uiq31 by keeping track of the exponent. */
    while ((uint16_t)(uiq31Input >> 16) < 0x8000) {
        uiq31Input <<= 1;
        ui16Exp -= 0x0080;
    }

    /* Round the uiq31 result and and shift to uiq23 */
    if (uiq31Input > 0xFFFFFF7F) {
        uiq31Input = 0xFFFFFF7F;
    }

    uiq23Result = (uiq31Input + 0x0080) >> 8;

    /* Remove the implied MSB bit of the mantissa. */
    uiq23Result &= ~0x00800000;

    /*
     * Add the constructed exponent and sign bit to the mantissa. We must use
     * an add in the case where rounding would cause the mantissa to overflow.
     * When this happens the mantissa result is two where the MSB is zero and
     * the LSB of the exp is set to 1 instead. Adding one to the exponent is the
     * correct handling for a mantissa of two. It is not required to scale the
     * mantissa since it will always be equal to zero in this scenario.
     */
    uiq23Result += (uint32_t)ui16Exp << 16;

    /* Return the mantissa + exp + sign result as a floating point type. */
    return *(float *)&uiq23Result;
}

/*******************************IQ*****************************/

/**
 * @brief Multiply two values of IQN type.
 *
 * @param iqNInput1       IQN type value input to be multiplied.
 * @param iqNInput2       IQN type value input to be multiplied.
 * @param q_value         IQ format.
 *
 * @return                IQN type result of the multiplication.
 */
// define ok
  int32_t __IQNmpy(int32_t iqNInput1, int32_t iqNInput2, const int32_t q_value) {
    int64_t iqNResult;

    iqNResult = (int64_t)iqNInput1 * (int64_t)iqNInput2;
    iqNResult = iqNResult >> q_value;

    return (int32_t)iqNResult;
}

/**
 * @brief Multiply two values of IQN type, with rounding.
 *
 * @param iqNInput1       IQN type value input to be multiplied.
 * @param iqNInput2       IQN type value input to be multiplied.
 * @param q_value         IQ format for result.
 *
 * @return                IQN type result of the multiplication.
 */
  int32_t __IQNrmpy(int32_t iqNInput1, int32_t iqNInput2, const int8_t q_value) {
    int64_t iqNResult;

    iqNResult = (int64_t)iqNInput1 * (int64_t)iqNInput2;
    iqNResult = iqNResult + ((uint32_t)1 << (q_value - 1));
    iqNResult = iqNResult >> q_value;

    return (int32_t)iqNResult;
}

/**
 * @brief Multiplies two IQN numbers, with rounding and saturation.
 *
 * @param iqNInput1       IQN type value input to be multiplied.
 * @param iqNInput2       IQN type value input to be multiplied.
 * @param q_value         IQ format for result.
 *
 * @return                IQN type result of the multiplication.
 */
  int32_t __IQNrsmpy(int32_t iqNInput1, int32_t iqNInput2, const int8_t q_value) {
    int64_t iqNResult;

    iqNResult = (int64_t)iqNInput1 * (int64_t)iqNInput2;
    iqNResult = iqNResult + ((uint32_t)1 << (q_value - 1));
    iqNResult = iqNResult >> q_value;

    if (iqNResult > INT32_MAX) {
        return INT32_MAX;
    } else if (iqNResult < INT32_MIN) {
        return INT32_MIN;
    } else {
        return (int32_t)iqNResult;
    }
}

/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in a third IQ format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 * @param q_value         IQ format for result.
 *
 * @return                IQN type result of the multiplication.
 */
  int32_t __IQNmpyIQX(int32_t a, int n1, int32_t b, int n2, int8_t q_value) {
    //    uint16_t ui16IntState;
    //    uint16_t ui16MPYState;
    int32_t i32Shift;
    int64_t i64Result;

    i64Result = ((int64_t)a * (int64_t)b); //__mpyx(a, b);

    i32Shift = (n1 + n2) - q_value;

    if (i32Shift > 0) {
        i64Result >>= i32Shift;
    } else {
        i64Result <<= -i32Shift;
    }

    return (int32_t)i64Result;
}
/**
 * @brief Divide two values of IQN type
 *
 * @param iqNInput1       IQN type value numerator to be divided.
 * @param iqNInput2       IQN type value denominator to divide by.
 * @param type            Specify operation is signed or unsigned.
 * @param q_value         IQ format.
 *
 * @return                IQN type result of the multiplication.
 */
  int32_t __IQNdiv(int32_t iqNInput1, int32_t iqNInput2, const uint8_t type, const int8_t q_value) {

    uint8_t ui8Index, ui8Sign = 0;
    uint32_t ui32Temp;
    uint32_t uiq30Guess;
    uint32_t uiqNInput1;
    uint32_t uiqNInput2;
    uint32_t uiqNResult;
    uint64_t uiiqNInput1;
    //    uint16_t ui16IntState;
    //    uint16_t ui16MPYState;

    if (type == TYPE_DEFAULT) {
        /* save sign of denominator */
        if (iqNInput2 <= 0) {
            /* check for divide by zero */
            if (iqNInput2 == 0) {
                return INT32_MAX;
            } else {
                ui8Sign = 1;
                iqNInput2 = -iqNInput2;
            }
        }

        /* save sign of numerator */
        if (iqNInput1 < 0) {
            ui8Sign ^= 1;
            iqNInput1 = -iqNInput1;
        }
    } else {
        /* Check for divide by zero */
        if (iqNInput2 == 0) {
            return INT32_MAX;
        }
    }

    /* Save input1 and input2 to unsigned IQN and IIQN (64-bit). */
    uiiqNInput1 = (uint64_t)iqNInput1;
    uiqNInput2 = (uint32_t)iqNInput2;

    /* Scale inputs so that 0.5 <= uiqNInput2 < 1.0. */
    while (uiqNInput2 < 0x40000000) { // 0x40000000 is 0100 0000 0000 0000 0000 0000 0000 0000
        uiqNInput2 <<= 1;
        uiiqNInput1 <<= 1;
    }

    /*
     * Shift input1 back from iq31 to iqN but scale by 2 since we multiply
     * by result in iq30 format.
     */
    if (q_value < 31) {
        uiiqNInput1 >>= (31 - q_value - 1);
    } else {
        uiiqNInput1 <<= 1;
    }

    /* Check for saturation. */
    if (uiiqNInput1 >> 32) {
        if (ui8Sign) {
            return INT32_MIN;
        } else {
            return INT32_MAX;
        }
    } else {
        uiqNInput1 = (uint32_t)uiiqNInput1;
    }

    /* use left most 7 bits as ui8Index into lookup table (range: 32-64) */
    ui8Index = uiqNInput2 >> 24;
    ui8Index -= 64;
    uiq30Guess = (uint32_t)_IQ6div_lookup[ui8Index] << 24;

    /* 1st iteration */
    ui32Temp = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)uiqNInput2) >> 31); //__mpyf_ul(uiq30Guess, uiqNInput2);
    ui32Temp = -((uint32_t)ui32Temp - 0x80000000);
    ui32Temp = ui32Temp << 1;
    uiq30Guess = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)ui32Temp) >> 31); //__mpyf_ul_reuse_arg1(uiq30Guess, ui32Temp);

    /* 2nd iteration */
    ui32Temp = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)uiqNInput2) >> 31); //__mpyf_ul(uiq30Guess, uiqNInput2);
    ui32Temp = -((uint32_t)ui32Temp - 0x80000000);
    ui32Temp = ui32Temp << 1;
    uiq30Guess = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)ui32Temp) >> 31); //__mpyf_ul_reuse_arg1(uiq30Guess, ui32Temp);

    /* 3rd iteration */
    ui32Temp = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)uiqNInput2) >> 31); //__mpyf_ul(uiq30Guess, uiqNInput2);
    ui32Temp = -((uint32_t)ui32Temp - 0x80000000);
    ui32Temp = ui32Temp << 1;
    uiq30Guess = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)ui32Temp) >> 31); //__mpyf_ul_reuse_arg1(uiq30Guess, ui32Temp);

    /* Multiply 1/uiqNInput2 and uiqNInput1. */
    uiqNResult = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)uiqNInput1) >> 31); //__mpyf_ul(uiq30Guess, uiqNInput1);

    /* Saturate, add the sign and return. */
    // if (type == TYPE_DEFAULT) {
    if (uiqNResult > INT32_MAX) {
        if (ui8Sign) {
            return INT32_MIN;
        } else {
            return INT32_MAX;
        }
    } else {
        if (ui8Sign) {
            return -(int32_t)uiqNResult;
        } else {
            return (int32_t)uiqNResult;
        }
    }
    //  }
    //  else {
    //      return uiqNResult;
    //  }
}

/************************3 functions(sin cos asin atan2)***************************/

/********************************************************************************************
 * @  the principle of sin calculation
 *
 * Perform the calculation where the input is only in the first quadrant
 * using one of the following two functions.
 *
 * This algorithm is derived from the following trig identities:
 *     sin(k + x) = sin(k)*cos(x) + cos(k)*sin(x)
 *     cos(k + x) = cos(k)*cos(x) - sin(k)*sin(x)
 *
 * First we calculate an index k and the remainder x according to the following
 * formulas:
 *
 *     k = 0x3F & int(Radian*64)
 *     x = fract(Radian*64)/64
 *
 * Two lookup tables store the values of sin(k) and cos(k) for all possible
 * indexes. The remainder, x, is calculated using second order Taylor series.
 *
 *     sin(x) = x - (x^3)/6     (~36.9 bits of accuracy)
 *     cos(x) = 1 - (x^2)/2     (~28.5 bits of accuracy)
 *
 * Combining the trig identities with the Taylor series approximiations gives
 * the following two functions:
 *
 *     cos(Radian) = C(k) + x*(-S(k) + 0.5*x*(-C(k) + 0.333*x*S(k)))
 *     sin(Radian) = S(k) + x*(C(k) + 0.5*x*(-S(k) - 0.333*x*C(k)))
 *
 *     where  S(k) = Sin table value at offset "k"
 *            C(k) = Cos table value at offset "k"
 *
 * Using a lookup table with a 64 bit index (52 indexes since the input range is
 * only 0 - 0.785398) and second order Taylor series gives 28 bits of accuracy.
 *******************************************************************************************************/

/**
 * @brief Computes the sine of an UIQ31 input.
 *
 * @param uiq31Input      UIQ31 type input.
 *
 * @return                UIQ31 type result of sine.
 */
  int32_t __IQNcalcSin(uint32_t uiq31Input) {
    uint16_t index;
    int32_t iq31X;
    int32_t iq31Sin;
    int32_t iq31Cos;
    int32_t iq31Res;

    /* Calculate index for sin and cos lookup using bits 31:26 */
    index = (uint16_t)(uiq31Input >> 25) & 0x003f; // index(0-64)

    /* Lookup S(k) and C(k) values. */
    iq31Sin = _IQ31SinLookup[index];
    iq31Cos = _IQ31CosLookup[index];

    /*
     * Calculated x (the remainder) by subtracting the index from the unsigned
     * iq31 input. This can be accomplished by masking out the bits used for
     * the index.
     */
    iq31X = uiq31Input & 0x01ffffff;

    /* 0.333*x*C(k) */
    iq31Res = (int32_t)(((int64_t)(int32_t)0x2aaaaaab * (int64_t)iq31X) >> 31); //__mpyf_l(0x2aaaaaab, iq31X);  // 0.333=0x2aaaaaab/7FFF FFFF
    iq31Res = (int32_t)(((int64_t)iq31Cos * (int64_t)iq31Res) >> 31);                //__mpyf_l(iq31Cos, iq31Res);

    /* -S(k) - 0.333*x*C(k) */
    iq31Res = -(iq31Sin + iq31Res);

    /* 0.5*x*(-S(k) - 0.333*x*C(k)) */
    iq31Res = iq31Res >> 1;
    iq31Res = (int32_t)(((int64_t)iq31X * (int64_t)iq31Res) >> 31); //__mpyf_l(iq31X, iq31Res);

    /* C(k) + 0.5*x*(-S(k) - 0.333*x*C(k)) */
    iq31Res = iq31Cos + iq31Res;

    /* x*(C(k) + 0.5*x*(-S(k) - 0.333*x*C(k))) */
    iq31Res = (int32_t)(((int64_t)iq31X * (int64_t)iq31Res) >> 31); //__mpyf_l(iq31X, iq31Res);

    /* sin(Radian) = S(k) + x*(C(k) + 0.5*x*(-S(k) - 0.333*x*C(k))) */
    iq31Res = iq31Sin + iq31Res;

    return iq31Res;
}

/**
 * @brief Computes the cosine of an UIQ31 input.
 *
 * @param uiq31Input      UIQ31 type input.
 *
 * @return                UIQ31 type result of cosine.
 */
  int32_t __IQNcalcCos(uint32_t uiq31Input) {
    uint16_t index;
    int32_t iq31X;
    int32_t iq31Sin;
    int32_t iq31Cos;
    int32_t iq31Res;

    /* Calculate index for sin and cos lookup using bits 31:26 */
    index = (uint16_t)(uiq31Input >> 25) & 0x003f;

    /* Lookup S(k) and C(k) values. */
    iq31Sin = _IQ31SinLookup[index];
    iq31Cos = _IQ31CosLookup[index];

    /*
     * Calculated x (the remainder) by subtracting the index from the unsigned
     * iq31 input. This can be accomplished by masking out the bits used for
     * the index.
     */
    iq31X = uiq31Input & 0x01ffffff;

    /* 0.333*x*S(k) */
    iq31Res = (int32_t)(((int64_t)(int32_t)0x2aaaaaab * (int64_t)iq31X) >> 31); //__mpyf_l(0x2aaaaaab, iq31X);
    iq31Res = (int32_t)(((int64_t)iq31Sin * (int64_t)iq31Res) >> 31);                //__mpyf_l(iq31Sin, iq31Res);

    /* -C(k) + 0.333*x*S(k) */
    iq31Res = iq31Res - iq31Cos;

    /* 0.5*x*(-C(k) + 0.333*x*S(k)) */
    iq31Res = iq31Res >> 1;
    iq31Res = (int32_t)(((int64_t)iq31X * (int64_t)iq31Res) >> 31); //__mpyf_l(iq31X, iq31Res);

    /* -S(k) + 0.5*x*(-C(k) + 0.333*x*S(k)) */
    iq31Res = iq31Res - iq31Sin;

    /* x*(-S(k) + 0.5*x*(-C(k) + 0.333*x*S(k))) */
    iq31Res = (int32_t)(((int64_t)iq31X * (int64_t)iq31Res) >> 31); //__mpyf_l(iq31X, iq31Res);

    /* cos(Radian) = C(k) + x*(-S(k) + 0.5*x*(-C(k) + 0.333*x*S(k))) */
    iq31Res = iq31Cos + iq31Res;

    return iq31Res;
}

  int32_t __IQNsin(int32_t iqNInput, const int8_t q_value) {
    uint8_t ui8Sign = 0;
    uint32_t uiq29Input;
    uint32_t uiq30Input;
    uint32_t uiq31Input;
    uint32_t uiq32Input;
    uint32_t uiq31Result;

    /* Remove sign from input */
    if (iqNInput < 0) {
        iqNInput = -iqNInput;
        /* Flip sign only for sin */
        ui8Sign = 1;
    }

    /* Radians API */

    /* Calculate the exponent difference from input format to iq29. */
    int16_t exp = 29 - q_value;

    /* Save input as unsigned iq29 format. */
    uiq29Input = (uint32_t)iqNInput;

    /* Reduce the input exponent to zero by scaling by 2*pi. */
    while (exp) {
        if (uiq29Input >= iq29_pi) {
            uiq29Input -= iq29_pi;
        }
        uiq29Input <<= 1;
        exp--;
    }

    /* Reduce the range to the first two quadrants. */
    if (uiq29Input >= iq29_pi) {
        uiq29Input -= iq29_pi;
        ui8Sign ^= 1;
    }

    /* Scale the unsigned iq29 input to unsigned iq30. */
    uiq30Input = uiq29Input << 1;

    /* Reduce the iq30 input range to the first quadrant. */
    if (uiq30Input >= iq30_halfPi) {
        uiq30Input = iq30_pi - uiq30Input;

        /* flip sign for cos calculations */
    }

    /* Convert the unsigned iq30 input to unsigned iq31 */
    uiq31Input = uiq30Input << 1;

    /* If input is greater than pi/4 use cos for calculations */
    if (uiq31Input > iq31_quarterPi) {
        uiq31Input = iq31_halfPi - uiq31Input;
        uiq31Result = __IQNcalcCos(uiq31Input);
    } else {
        uiq31Result = __IQNcalcSin(uiq31Input);
    }

    /* Shift to Q type */
    uiq31Result >>= (31 - q_value);

    /* set sign */
    if (ui8Sign) {
        uiq31Result = -uiq31Result;
    }

    return uiq31Result;
}

  int32_t __IQNsinPU(int32_t iqNInput, const int8_t q_value) {
    uint8_t ui8Sign = 0;
    uint32_t uiq29Input;
    uint32_t uiq30Input;
    uint32_t uiq31Input;
    uint32_t uiq32Input;
    uint32_t uiq31Result;

    /* Remove sign from input */
    if (iqNInput < 0) {
        iqNInput = -iqNInput;
        /* Flip sign only for sin */
        ui8Sign = 1;
    }

    /* Per unit API */
    /*
     * Scale input to unsigned iq32 to allow for maximum range. This removes
     * the integer component of the per unit input.
     */
    uiq32Input = (uint32_t)iqNInput << (32 - q_value);

    /* Reduce the input to the first two quadrants. */
    if (uiq32Input >= 0x80000000) {
        uiq32Input -= 0x80000000;
        ui8Sign ^= 1;
    }

    /*
     * Multiply unsigned iq32 input by 2*pi and scale to unsigned iq30:
     *     iq32 * iq30 = iq30 * 2
     */
    uiq30Input = (uint32_t)(((uint64_t)uiq32Input * (uint64_t)iq30_pi) >> 31); //__mpyf_ul(uiq32Input, iq30_pi);

    /* Reduce the iq30 input range to the first quadrant. */
    if (uiq30Input >= iq30_halfPi) {
        uiq30Input = iq30_pi - uiq30Input;

        /* flip sign for cos calculations */
    }

    /* Convert the unsigned iq30 input to unsigned iq31 */
    uiq31Input = uiq30Input << 1;

    /* If input is greater than pi/4 use cos for calculations */
    if (uiq31Input > iq31_quarterPi) {
        uiq31Input = iq31_halfPi - uiq31Input;
        uiq31Result = __IQNcalcCos(uiq31Input);
    } else {
        uiq31Result = __IQNcalcSin(uiq31Input);
    }

    /* Shift to Q type */
    uiq31Result >>= (31 - q_value);

    /* set sign */
    if (ui8Sign) {
        uiq31Result = -uiq31Result;
    }
    return uiq31Result;
}

  int32_t __IQNcos(int32_t iqNInput, const int8_t q_value) {
    uint8_t ui8Sign = 0;
    uint32_t uiq29Input;
    uint32_t uiq30Input;
    uint32_t uiq31Input;
    uint32_t uiq32Input;
    uint32_t uiq31Result;

    /* Remove sign from input */
    if (iqNInput < 0) {
        iqNInput = -iqNInput;
    }

    /* Radians API */

    /* Calculate the exponent difference from input format to iq29. */
    int16_t exp = 29 - q_value;

    /* Save input as unsigned iq29 format. */
    uiq29Input = (uint32_t)iqNInput;

    /* Reduce the input exponent to zero by scaling by 2*pi. */
    while (exp) {
        if (uiq29Input >= iq29_pi) {
            uiq29Input -= iq29_pi;
        }
        uiq29Input <<= 1;
        exp--;
    }

    /* Reduce the range to the first two quadrants. */
    if (uiq29Input >= iq29_pi) {
        uiq29Input -= iq29_pi;
        ui8Sign ^= 1;
    }

    /* Scale the unsigned iq29 input to unsigned iq30. */
    uiq30Input = uiq29Input << 1;

    /* Reduce the iq30 input range to the first quadrant. */
    if (uiq30Input >= iq30_halfPi) {
        uiq30Input = iq30_pi - uiq30Input;

        /* flip sign for cos calculations */
        ui8Sign ^= 1;
    }

    /* Convert the unsigned iq30 input to unsigned iq31 */
    uiq31Input = uiq30Input << 1;

    /* If input is greater than pi/4 use cos for calculations */
    if (uiq31Input > iq31_quarterPi) {
        uiq31Input = iq31_halfPi - uiq31Input;
        uiq31Result = __IQNcalcSin(uiq31Input);
    } else {
        uiq31Result = __IQNcalcCos(uiq31Input);
    }
    /* Shift to Q type */
    uiq31Result >>= (31 - q_value);

    /* set sign */
    if (ui8Sign) {
        uiq31Result = -uiq31Result;
    }
    return uiq31Result;
}

  int32_t __IQNcosPU(int32_t iqNInput, const int8_t q_value) {
    uint8_t ui8Sign = 0;
    uint32_t uiq29Input;
    uint32_t uiq30Input;
    uint32_t uiq31Input;
    uint32_t uiq32Input;
    uint32_t uiq31Result;

    /* Remove sign from input */
    if (iqNInput < 0) {
        iqNInput = -iqNInput;
    }

    /* Per unit API */
    /*
     * Scale input to unsigned iq32 to allow for maximum range. This removes
     * the integer component of the per unit input.
     */
    uiq32Input = (uint32_t)iqNInput << (32 - q_value);

    /* Reduce the input to the first two quadrants. */
    if (uiq32Input >= 0x80000000) {
        uiq32Input -= 0x80000000;
        ui8Sign ^= 1;
    }

    /*
     * Multiply unsigned iq32 input by 2*pi and scale to unsigned iq30:
     *     iq32 * iq30 = iq30 * 2
     */
    uiq30Input = (uint32_t)(((uint64_t)uiq32Input * (uint64_t)iq30_pi) >> 31); //__mpyf_ul(uiq32Input, iq30_pi);

    /* Reduce the iq30 input range to the first quadrant. */
    if (uiq30Input >= iq30_halfPi) {
        uiq30Input = iq30_pi - uiq30Input;

        /* flip sign for cos calculations */
        ui8Sign ^= 1;
    }

    /* Convert the unsigned iq30 input to unsigned iq31 */
    uiq31Input = uiq30Input << 1;

    /* If input is greater than pi/4 use cos for calculations */
    if (uiq31Input > iq31_quarterPi) {
        uiq31Input = iq31_halfPi - uiq31Input;
        uiq31Result = __IQNcalcSin(uiq31Input);
    } else {
        uiq31Result = __IQNcalcCos(uiq31Input);
    }

    /* Shift to Q type */
    uiq31Result >>= (31 - q_value);

    /* set sign */
    if (ui8Sign) {
        uiq31Result = -uiq31Result;
    }
    return uiq31Result;
}

/***********************************************************************************
 * @  the principle of asin calculation
 *
 * Calculate asin using a 4th order Taylor series for inputs in the range of
 * zero to 0.5. The coefficients are stored in a lookup table with 17 ranges
 * to give an accuracy of 26 bits.
 *
 * For inputs greater than 0.5 we apply the following transformation:
 *
 *     asin(x) = PI/2 - 2*asin(sqrt((1 - x)/2))
 *
 * This transformation is derived from the following trig identities:
 *
 *     (1) asin(x) = PI/2 - acos(x)
 *     (2) sin(t/2)^2 = (1 - cos(t))/2
 *     (3) cos(t) = x
 *     (4) t = acos(x)
 *
 * Identity (2) can be simplified to give equation (5):
 *
 *     (5) t = 2*asin(sqrt((1 - cos(t))/2))
 *
 * Substituing identities (3) and (4) into equation (5) gives equation (6):
 *
 *     (6) acos(x) = 2*asin(sqrt((1 - x)/2))
 *
 * The final step is substituting equation (6) into identity (1):
 *
 *     asin(x) = PI/2 - 2*asin(sqrt((1 - x)/2))
 *
 * Acos is implemented using asin and identity (1).
 **************************************************************************************/

/**
 * @brief Computes the inverse sine of the IQN input.
 *
 * @param iqNInput        IQN type input.
 * @param q_value         IQ format.
 *
 * @return                IQN type result of inverse sine.
 */
  int32_t __IQNasin(int32_t iqNInput, const int8_t q_value) {
    uint8_t ui8Status = 0;
    uint16_t index;
    int32_t iq29Result;
    const int32_t *piq29Coeffs;
    uint32_t uiq31Input;
    uint32_t uiq31InputTemp;

    /*
     * Extract the sign from the input and set the following status bits:
     *
     *      ui8Status = xxxxxxTS
     *      x = unused
     *      T = transform was applied
     *      S = sign bit needs to be set (-y)
     */
    if (iqNInput < 0) {
        ui8Status |= 1;
        iqNInput = -iqNInput;
    }

    /*
     * Check if input is within the valid input range:
     *
     *     0 <= iqNInput <= 1
     */
    if (iqNInput > ((uint32_t)1 << q_value)) {
        return 0;
    }

    /* Convert input to unsigned iq31. */
    uiq31Input = (uint32_t)iqNInput << (31 - q_value);

    /*
     * Apply the transformation from asin to acos if input is greater than 0.5.
     * The first step is to calculate the following:
     *
     *     (sqrt((1 - uiq31Input)/2))
     */
    uiq31InputTemp = 0x80000000 - uiq31Input;
    if (uiq31InputTemp < 0x40000000) {
        /* Halve the result. */
        uiq31Input = uiq31InputTemp >> 1;

        /* Calculate sqrt((1 - uiq31Input)/2) */
        uiq31Input = _IQ31sqrt(uiq31Input);

        /* Flag that the transformation was used. */
        ui8Status |= 2;
    }

    /* Calculate the index using the left 6 most bits of the input. */
    index = (int16_t)(uiq31Input >> 26) & 0x003f;

    /* Set the coefficient pointer. */
    piq29Coeffs = _IQ29Asin_coeffs[index];

    /*
     * Calculate asin(x) using the following Taylor series:
     *
     *     asin(x) = (((c4*x + c3)*x + c2)*x + c1)*x + c0
     */

    /* c4*x */
    iq29Result = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)(*piq29Coeffs++)) >> 31); //__mpyf_l(uiq31Input, *piq29Coeffs++);

    /* c4*x + c3 */
    iq29Result = iq29Result + *piq29Coeffs++;

    /* (c4*x + c3)*x */
    iq29Result = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)iq29Result) >> 31); //__mpyf_l(uiq31Input, iq29Result);

    /* (c4*x + c3)*x + c2 */
    iq29Result = iq29Result + *piq29Coeffs++;

    /* ((c4*x + c3)*x + c2)*x */
    iq29Result = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)iq29Result) >> 31); //__mpyf_l(uiq31Input, iq29Result);

    /* ((c4*x + c3)*x + c2)*x + c1 */
    iq29Result = iq29Result + *piq29Coeffs++;

    /* (((c4*x + c3)*x + c2)*x + c1)*x */
    iq29Result = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)iq29Result) >> 31); //__mpyf_l(uiq31Input, iq29Result);

    /* (((c4*x + c3)*x + c2)*x + c1)*x + c0 */
    iq29Result = iq29Result + *piq29Coeffs++;

    /* check if we switched to acos */
    if (ui8Status & 2) {
        /* asin(x) = pi/2 - 2*iq29Result */
        iq29Result = iq29Result << 1;
        iq29Result -= iq29_halfPi; // this is equivalent to the above
        iq29Result = -iq29Result;  // but avoids using temporary registers
    }

    /* Shift iq29 result to specified q_value. */
    iq29Result >>= 29 - q_value;

    /* Add sign to the result. */
    if (ui8Status & 1) {
        iq29Result = -iq29Result;
    }
    return iq29Result;

}

/*************************************************************************************
 * @the principle of atan2 calculation
 *
 * Calculate atan2 using a 3rd order Taylor series. The coefficients are stored
 * in a lookup table with 17 ranges to give an accuracy of XX bits.
 *
 * The input to the Taylor series is the ratio of the two inputs and must be
 * in the range of 0 <= input <= 1. If the y argument is larger than the x
 * argument we must apply the following transformation:
 * if y > x, then 0 <= ratio <= 1, and we must apply transformation:
 *     atan(y/x) = pi/2 - atan(x/y)
 ***************************************************************************************/

/**
 * @brief Divides two values of IQ31 format, without sign checks.
 *
 * @param a             IQ31 type value numerator to be divided.
 * @param b             IQ31 type value denominator to divide by.
 *
 * @return              IQ31 type result of the multiplication.
 *
 * @function Hidden unsigned uiq31 divide without sign checks, used for atan2
 */
uint32_t _UIQ31div(uint32_t a, uint32_t b) {
    return __IQNdiv(a, b, TYPE_UNSIGNED, 31);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQN input
 *        and return the result.
 *
 * @param iqNInputY       IQN type input y.
 * @param iqNInputX       IQN type input x.
 * @param type            Specifies radians or per-unit operation.
 * @param q_value         IQ format.
 *
 * @return                IQN type result of 4-quadrant arctangent.
 */
  int32_t __IQNatan2(int32_t iqNInputY, int32_t iqNInputX, const uint8_t type, const int8_t q_value) {
    uint8_t ui8Status = 0;
    uint8_t ui8Index;
    uint16_t ui16IntState;
    uint16_t ui16MPYState;
    uint32_t uiqNInputX;
    uint32_t uiqNInputY;
    uint32_t uiq32ResultPU;
    int32_t iqNResult;
    int32_t iq29Result;
    const int32_t *piq32Coeffs;
    uint32_t uiq31Input;

    /*
     * Extract the sign from the inputs and set the following status bits:
     *
     *      ui8Status = xxxxxTQS
     *      x = unused
     *      T = transform was applied
     *      Q = 2nd or 3rd quadrant (-x)
     *      S = sign bit needs to be set (-y)
     */
    if (iqNInputY < 0) {
        ui8Status |= 1;
        iqNInputY = -iqNInputY;
    }
    if (iqNInputX < 0) {
        ui8Status |= 2;
        iqNInputX = -iqNInputX;
    }

    /* Save inputs to unsigned iqN formats. */
    uiqNInputX = (uint32_t)iqNInputX;
    uiqNInputY = (uint32_t)iqNInputY;

    /*
     * Calcualte the ratio of the inputs in iq31. When using the iq31 div
     * fucntions with inputs of matching type the result will be iq31:
     *
     *     iq31 = _IQ31div(iqN, iqN);
     */
    if (uiqNInputX < uiqNInputY) {
        ui8Status |= 4;
        uiq31Input = __IQNdiv(uiqNInputX, uiqNInputY, TYPE_UNSIGNED, 31); //_UIQ31div(uiqNInputX, uiqNInputY);
    } else {
        uiq31Input = __IQNdiv(uiqNInputY, uiqNInputX, TYPE_UNSIGNED, 31); //_UIQ31div(uiqNInputY, uiqNInputX);
    }

    /* Calculate the index using the left 8 most bits of the input. */
    ui8Index = (uint16_t)(uiq31Input >> 24);
    ui8Index = ui8Index & 0x00fc;

    /* Set the coefficient pointer. */
    piq32Coeffs = &_IQ32atan_coeffs[ui8Index];

    /*
     * Calculate atan(x) using the following Taylor series:
     *
     *     atan(x) = ((c3*x + c2)*x + c1)*x + c0
     */

    /* c3*x */
    uiq32ResultPU = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)(int32_t)(*piq32Coeffs++)) >> 31); //__mpyf_l(uiq31Input, *piq32Coeffs++);//_

    /* c3*x + c2 */
    uiq32ResultPU = uiq32ResultPU + *piq32Coeffs++;

    /* (c3*x + c2)*x */
    uiq32ResultPU = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)(int32_t)uiq32ResultPU) >> 31); //__mpyf_l(uiq31Input, uiq32ResultPU);//

    /* (c3*x + c2)*x + c1 */
    uiq32ResultPU = uiq32ResultPU + *piq32Coeffs++;

    /* ((c3*x + c2)*x + c1)*x */
    uiq32ResultPU = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)(int32_t)uiq32ResultPU) >> 31); //__mpyf_l(uiq31Input, uiq32ResultPU);//

    /* ((c3*x + c2)*x + c1)*x + c0 */
    uiq32ResultPU = uiq32ResultPU + *piq32Coeffs++;

    /* Check if we applied the transformation. */
    if (ui8Status & 4) {
        /* atan(y/x) = pi/2 - uiq32ResultPU */
        uiq32ResultPU = (uint32_t)(0x40000000 - uiq32ResultPU); // 0x40000000- pi/2
    }

    /* Check if the result needs to be mirrored to the 2nd/3rd quadrants. */
    if (ui8Status & 2) {
        /* atan(y/x) = pi - uiq32ResultPU */
        uiq32ResultPU = (uint32_t)(0x80000000 - uiq32ResultPU); // 0x80000000 -pi
    }

    /* Round and convert result to correct format (radians/PU and iqN type). */
    if (type == TYPEATAN2_PU) {
        uiq32ResultPU += (uint32_t)1 << (31 - q_value);
        iqNResult = uiq32ResultPU >> (32 - q_value);
    } else {
        /*
         * Multiply the per-unit result by 2*pi:
         *
         *     iq31mpy(iq32, iq28) = iq29
         */
        iq29Result = (int32_t)(((int64_t)(int32_t)uiq32ResultPU * (int64_t)(int32_t)iq28_twoPi) >> 31); //__mpyf_l(uiq32ResultPU, iq28_twoPi); //2*pi*x

        /* Only round IQ formats < 29 */
        if (q_value < 29) {
            iq29Result += (uint32_t)1 << (28 - q_value);
        }
        iqNResult = iq29Result >> (29 - q_value);
    }

    /*
    /* Set the sign bit and result to correct quadrant. */
    if (ui8Status & 1) {
        return -iqNResult;
    } else {
        return iqNResult;
    }
}

/******************************** 4 functions*****************************************/

/******************************************************************************************************************
 * @the principle of SQRT calculation
 *
 *
 * Calculate square root, inverse square root and the magnitude of two inputs
 * using a Newton-Raphson iterative method. This method takes an initial guess
 * and performs an error correction with each iteration. The equation is:
 * Newton-Raphson iterative method:
 *
 *     x1 = x0 - f(x0)/f'(x0)
 *
 * Where f' is the derivative (d/dx)of f. The approximation for inverse square root
 * is:
 *
 *     g' = g * (1.5 - (x/2) * g * g)
 *
 *     g' = new guess approximation
 *     g = best guess approximation
 *     x = input
 *
 * The inverse square root is multiplied by the initial input x to get the
 * square root result for square root and magnitude functions.
 *
 *     root(x) = x * 1/root(x)
 ******************************************************************************************************/

/**
 * @brief Calculate square root, inverse square root and the magnitude of two inputs.
 *
 * @param iqNInputX         IQN type input x.
 * @param iqNInputY         IQN type input y.
 * @param type              Operation type.
 * @param q_value           IQ format.
 *
 * @return                  IQN type result of the square root or magnitude operation.
 */
  int32_t __IQNsqrt(int32_t iqNInputX, int32_t iqNInputY, const int8_t q_value, const int8_t type) {
    uint8_t ui8Index;
    uint8_t ui8Loops;
    int16_t i16Exponent;
    uint16_t ui16IntState;
    uint16_t ui16MPYState;
    uint32_t uiq30Guess;
    uint32_t uiq30Result;
    uint32_t uiq31Result;
    uint32_t uiq32Input;

    /* If the type is (inverse) magnitude we need to calculate x^2 + y^2 first. */
    if (type == TYPE_MAG || type == TYPE_IMAG) {
        uint64_t ui64Sum;

        /* Calculate x^2 */
        ui64Sum = ((int64_t)iqNInputX * (int64_t)iqNInputX); //__mpyx(iqNInputX, iqNInputX);

        /* Calculate y^2 and add to x^2 */
        ui64Sum += ((int64_t)iqNInputY * (int64_t)iqNInputY); //__mpyx(iqNInputY, iqNInputY);

        //__mpy_stop(&ui16IntState, &ui16MPYState);

        /* Return if the magnitude is simply zero. */
        if (ui64Sum == 0) {
            return 0;
        }

        /*
         * Initialize the exponent to positive for magnitude, negative for
         * inverse magnitude.
         */
        if (type == TYPE_MAG) {
            i16Exponent = (32 - q_value);
        } else {
            i16Exponent = -(32 - q_value);
        }

        /* Shift to iq64 by keeping track of exponent. */
        while ((uint16_t)(ui64Sum >> 48) < 0x4000) {
            ui64Sum <<= 2;
            /* Decrement exponent for mag */
            if (type == TYPE_MAG) {
                i16Exponent--;
            }
            /* Increment exponent for imag */
            else {
                i16Exponent++;
            }
        }

        /* Shift ui64Sum to unsigned iq32 and set as uiq32Input */
        uiq32Input = (uint32_t)(ui64Sum >> 32);
    } else {
        /* check sign of input */
        if (iqNInputX <= 0) {
            return 0;
        }

        /* If the q_value gives an odd starting exponent make it even. */
        if ((32 - q_value) % 2 == 1) {
            iqNInputX <<= 1;
            /* Start with positive exponent for sqrt */
            if (type == TYPE_SQRT) {
                i16Exponent = ((32 - q_value) - 1) >> 1;
            }
            /* start with negative exponent for isqrt */
            else {
                i16Exponent = -(((32 - q_value) - 1) >> 1);
            }
        } else {
            /* start with positive exponent for sqrt */
            if (type == TYPE_SQRT) {
                i16Exponent = (32 - q_value) >> 1;
            }
            /* start with negative exponent for isqrt */
            else {
                i16Exponent = -((32 - q_value) >> 1);
            }
        }

        /* Save input as unsigned iq32. */
        uiq32Input = (uint32_t)iqNInputX;

        /* Shift to iq32 by keeping track of exponent */
        while ((uint16_t)(uiq32Input >> 16) < 0x4000) {
            uiq32Input <<= 2;
            /* Decrement exponent for sqrt and mag */
            if (type) {
                i16Exponent--;
            }
            /* Increment exponent for isqrt */
            else {
                i16Exponent++;
            }
        }
    }

    /* Use left most byte as index into lookup table (range: 32-128) */
    ui8Index = uiq32Input >> 25;
    ui8Index -= 32;
    uiq30Guess = (uint32_t)_IQ14sqrt_lookup[ui8Index] << 16;

    /*
     * Set the loop counter:
     *
     *     iq1 <= q_value < 24 - 2 loops
     *     iq22 <= q_value <= 31 - 3 loops
     */
    if (q_value < 24) {
        ui8Loops = 2;
    } else {
        ui8Loops = 3;
    }

    /* Iterate through Newton-Raphson algorithm. */
    while (ui8Loops--) {
        /* x*g */
        uiq31Result = (uint32_t)(((uint64_t)uiq32Input * (uint64_t)uiq30Guess) >> 31); //__mpyf_ul(uiq32Input, uiq30Guess);

        /* x*g*g */
        uiq30Result = (uint32_t)(((uint64_t)uiq31Result * (uint64_t)uiq30Guess) >> 31); //__mpyf_ul(uiq31Result, uiq30Guess);

        /* 3 - x*g*g */
        uiq30Result = -(uiq30Result - 0xC0000000); // 0xC0000000 is 3

        /*
         * g/2*(3 - x*g*g)
         * uiq30Guess = uiq31Guess/2
         */
        uiq30Guess = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)uiq30Result) >> 31); //__mpyf_ul(uiq30Guess, uiq30Result);
    }

    /* Calculate sqrt(x) for both sqrt and mag */
    if (type == TYPE_SQRT || type == TYPE_MAG) {
        /*
         * uiq30Guess contains the inverse square root approximation, multiply
         * by uiq32Input to get square root result.
         */
        uiq31Result = (uint32_t)(((uint64_t)uiq30Guess * (uint64_t)uiq32Input) >> 31); //__mpyf_ul(uiq30Guess, uiq32Input);

        /*
         * Shift the result right by 31 - q_value.
         */
        i16Exponent -= (31 - q_value);

        /* Saturate value for any shift larger than 1 (only need this for mag) */
        if (type == TYPE_MAG) {
            if (i16Exponent > 0) {
                return 0x7fffffff;
            }
        }

        /* Shift left by 1 check only needed for iq30 and iq31 mag/sqrt */
        if (q_value >= 30) {
            if (i16Exponent > 0) {
                uiq31Result <<= 1;
                return uiq31Result;
            }
        }
    }
    /* Separate handling for isqrt and imag. */
    else {
        /*
         * Shift the result right by 31 - q_value, add one since we use the uiq30
         * result without shifting.
         */
        i16Exponent = i16Exponent - (31 - q_value) + 1;
        uiq31Result = uiq30Guess;

        /* Saturate any positive non-zero exponent for isqrt. */
        if (i16Exponent > 0) {
            return 0x7fffffff;
        }
    }

    /* Shift uiq31Result right by -exponent */
    if (i16Exponent <= -32) {
        return 0;
    }
    if (i16Exponent <= -16) {
        uiq31Result >>= 16;
        i16Exponent += 16;
    }
    if (i16Exponent <= -8) {
        uiq31Result >>= 8;
        i16Exponent += 8;
    }
    while (i16Exponent < -1) {
        uiq31Result >>= 1;
        i16Exponent++;
    }
    if (i16Exponent) {
        uiq31Result++;
        uiq31Result >>= 1;
    }

    return uiq31Result;
}

/*********************************5 functions***************************************/

/**
 * @brief Computes the exponential of an IQN input.
 *
 * @param iqNInput          IQN type input.
 * @param iqNLookupTable    Integer result lookup table.
 * @param ui8IntegerOffset  Integer portion offset
 * @param iqN_MIN           Minimum parameter value.
 * @param iqN_MAX           Maximum parameter value.
 * @param q_value           IQ format.
 *
 *
 * @return                  IQN type result of exponential.
 */
  int32_t __IQNexp(int32_t iqNInput, const uint32_t *iqNLookupTable, uint8_t ui8IntegerOffset, const int32_t iqN_MIN, const int32_t iqN_MAX, const int8_t q_value) {
    uint8_t ui8Count;
    int16_t i16Integer;
    uint16_t ui16IntState;
    uint16_t ui16MPYState;
    int32_t iq31Fractional;
    uint32_t uiqNResult;
    uint32_t uiqNIntegerResult;
    uint32_t uiq30FractionalResult;
    uint32_t uiq31FractionalResult;
    const uint32_t *piq30Coeffs;

    /* Input is negative. */
    if (iqNInput < 0) {
        /* Check for the minimum value. */
        if (iqNInput < iqN_MIN) {
            return 0;
        }

        /* Extract the fractional portion in iq31 and set sign bit. */
        iq31Fractional = iqNInput;
        iq31Fractional <<= (31 - q_value);
        iq31Fractional |= 0x80000000;

        /* Extract the integer portion. */
        i16Integer = (int16_t)(iqNInput >> q_value) + 1;

        /* Offset the integer portion and lookup the integer result. */
        i16Integer += ui8IntegerOffset;
        uiqNIntegerResult = iqNLookupTable[i16Integer];

        /* Reduce the fractional portion to -ln(2) < iq31Fractional < 0 */
        if (iq31Fractional <= -iq31_ln2) {
            iq31Fractional += iq31_ln2;
            uiqNIntegerResult >>= 1;
        }
    }
    /* Input is positive. */
    else {
        /* Check for the maximum value. */
        if (iqNInput > iqN_MAX) {
            return INT32_MAX;
        }

        /* Extract the fractional portion in iq31 and clear sign bit. */
        iq31Fractional = iqNInput;
        iq31Fractional <<= (31 - q_value);
        iq31Fractional &= 0x7fffffff;

        /* Extract the integer portion. */
        i16Integer = (int16_t)(iqNInput >> q_value);

        /* Offset the integer portion and lookup the integer result. */
        i16Integer += ui8IntegerOffset;
        uiqNIntegerResult = iqNLookupTable[i16Integer];

        /* Reduce the fractional portion to 0 < iq31Fractional < ln(2) */
        if (iq31Fractional >= iq31_ln2) {
            iq31Fractional -= iq31_ln2;
            uiqNIntegerResult <<= 1;
        }
    }

    /*
     * Initialize the coefficient pointer to the Taylor Series iq30 coefficients
     * for the exponential functions. Set the iq30 result to the first
     * coefficient in the table.
     */
    piq30Coeffs = _IQ30exp_coeffs;
    uiq30FractionalResult = *piq30Coeffs++;

    /* Compute exp^(iq31Fractional). */
    for (ui8Count = _IQ30exp_order; ui8Count > 0; ui8Count--) {
        uiq30FractionalResult = (int32_t)(((int64_t)iq31Fractional * (int64_t)(int32_t)uiq30FractionalResult) >> 31); //__mpyf_l(iq31Fractional, uiq30FractionalResult);
        uiq30FractionalResult += *piq30Coeffs++;
    }

    /* Scale the iq30 fractional result by to iq31. */
    uiq31FractionalResult = uiq30FractionalResult << 1;

    /*
     * Multiply the integer result in iqN format and the fractional result in
     * iq31 format to obtain the result in iqN format.
     */
    uiqNResult = (uint32_t)(((uint64_t)uiqNIntegerResult * (uint64_t)uiq31FractionalResult) >> 31); //__mpyf_ul(uiqNIntegerResult, uiq31FractionalResult);

    /*
     * Mark the end of all multiplies. This restores MPY and interrupt states
     * (MSP430 only).
     */
    //__mpy_stop(&ui16IntState, &ui16MPYState);

    /* The result is scaled by 2, round the result and scale to iqN format. */
    uiqNResult++;
    uiqNResult >>= 1;

    return uiqNResult;
}

/**
 * @brief Computes the base-e logarithm of an IQN input.
 *
 * @param iqNInput          IQN type input.
 * @param iqNMin            Minimum parameter value.
 * @param q_value           IQ format.
 *
 * @return                  IQN type result of exponential.
 */
  int32_t __IQNlog(int32_t iqNInput, const int32_t iqNMin, const int8_t q_value) {
    uint8_t ui8Counter;
    int16_t i16Exp;
    uint16_t ui16IntState;
    uint16_t ui16MPYState;
    int32_t iqNResult;
    int32_t iq30Result;
    uint32_t uiq31Input;
    const uint32_t *piq30Coeffs;

    /*
     * Check the sign of the input and for negative saturation for q_values
     * larger than iq26.
     */
    if (q_value > 26) {
        if (iqNInput <= 0) {
            return 0;
        } else if (iqNInput <= iqNMin) {
            return INT32_MIN;
        }
    }
    /*
     * Only check the sign of the input and that it is not equal to zero for
     * q_values less than or equal to iq26.
     */
    else {
        if (iqNInput <= 0) {
            return 0;
        }
    }

    /* Initialize the exponent value. */
    i16Exp = (31 - q_value);

    /*
     * Scale the input so it is within the following range in iq31:
     *
     *     0.666666 < uiq31Input < 1.333333.
     */
    uiq31Input = (uint32_t)iqNInput;
    while (uiq31Input < iq31_twoThird) {
        uiq31Input <<= 1;
        i16Exp--;
    }

    /*
     * Initialize the coefficient pointer to the Taylor Series iq30 coefficients
     * for the logarithm functions. Set the iq30 result to the first
     * coefficient in the table. Subtract one from the iq31 input.
     */
    piq30Coeffs = _IQ30log_coeffs;
    iq30Result = *piq30Coeffs++;
    uiq31Input -= iq31_one;

    /* Calculate log(uiq31Input) using the iq30 Taylor Series coefficients. */
    for (ui8Counter = _IQ30log_order; ui8Counter > 0; ui8Counter--) {
        iq30Result = (int32_t)(((int64_t)(int32_t)uiq31Input * (int64_t)iq30Result) >> 31); //__mpyf_l(uiq31Input, iq30Result);//
        iq30Result += *piq30Coeffs++;
    }

    /* Scale the iq30 result to match the function iq type. */
    iqNResult = iq30Result >> (30 - q_value);

    /*
     * Add i16Exp * ln(2) to the iqN result. This will never saturate since we
     * check for the minimum value at the start of the function. Negative
     * exponents require seperate handling to allow for an extra bit with the
     * unsigned data type.
     */
    if (i16Exp > 0) {
        iqNResult += (uint32_t)(((uint64_t)iq31_ln2 * (uint64_t)((int32_t)i16Exp << q_value)) >> 31); //__mpyf_ul(iq31_ln2, ((int32_t)i16Exp << q_value));
    } else {
        iqNResult -= (uint32_t)(((uint64_t)iq31_ln2 * (uint64_t)(((uint32_t)-i16Exp) << q_value)) >> 31); //__mpyf_ul(iq31_ln2, (((uint32_t)-i16Exp) << q_value));
    }
    return iqNResult;
}

/**
 * @brief Return the fractional portion of an IQN input.
 *
 * @param iqNInput        IQN type input.
 * @param q_value         IQ format.
 *
 * @return                IQN type fractional portion of input.
 */
  int32_t __IQNfrac(int32_t iqNInput, int8_t q_value) {
    int32_t iqNInteger;

    iqNInteger = (uint32_t)iqNInput & ((uint32_t)0xffffffff << q_value);
    return (iqNInput - iqNInteger);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion..
 *
 * @param iqNInput        IQN type input.
 * @param q_value         IQ format.
 *
 * @return                IQ type integer portion of Multiplication.
 */
  int32_t __IQNmpyI32int(int32_t iqNInput1, int32_t iqNInput2, int8_t q_value) {
    int64_t reslut;
    int32_t iqNInteger;

    reslut = (int64_t)iqNInput1 * (int64_t)iqNInput2;
    iqNInteger = (int32_t)(reslut >> q_value);
    return iqNInteger;
}

  /**
   * @brief Multiplies an IQ number by an integer, and returns the fractional portion..
   *
   * @param iqNInput        IQN type input.
   * @param q_value         IQ format.
   *
   * @return                IQ type fractional portion of Multiplication.
   */
  int32_t __IQNmpyI32frac(int32_t iqNInput1, int32_t iqNInput2, int8_t q_value) {
    int32_t result;
    int64_t reslutmpy;
    uint8_t flag;

    reslutmpy = (int64_t)iqNInput1 * (int64_t)iqNInput2;
    result = __IQNfrac((int32_t)reslutmpy, q_value);
    return result;
}
/***************************************7 functions for IQ conversion*****************************************/
/**
 * @brief Converts string to an IQN number.
 *
 * @param string          Pointer to the string to be converted.
 * @param q_value         IQ format.
 *
 * @return                Conversion of string to IQN type.
 */
  int32_t __atoIQN(const char *string, int32_t q_value) {
    uint8_t sgn;
    uint16_t ui16IntState;
    uint16_t ui16MPYState;
    uint32_t iqNResult;
    uint32_t uiq0Integer = 0;
    uint32_t uiq31Fractional = 0;
    uint32_t max_int = 0x7fffffff >> q_value;

    /* Check for sign */
    if (*string == '-') {
        string++;
        sgn = 1;
    } else {
        sgn = 0;
    }

    /* Process integer portion of string starting from first character. */
    while ((*string != '.') && (*string != 0)) {
        /* Check for invalid character */
        if (*string < '0' || *string > '9') {
            return 0;
        }

        /* Check that multiplying by 10 won't cause overflow */
        if (uiq0Integer > iq31_pointOne) {
            if (sgn) {
                return 0x80000000;
            } else {
                return 0x7fffffff;
            }
        }

        /* Multiply by 10 */
        uiq0Integer = __mpy_l(uiq0Integer, 10);

        /* Add next integer to result */
        uiq0Integer += *string++ - '0';

        /* Check to see if integer portion has overflowed */
        if (uiq0Integer > max_int) {
            if (sgn) {
                return 0x80000000;
            } else {
                return 0x7fffffff;
            }
        }
    }

    /* Check if previous loop ended with null character and return. */
    if (*string == 0) {
        /* Shift integer portion up */
        iqNResult = uiq0Integer << q_value;

        /* Return the result. */
        return iqNResult;
    }

    /* Increment to the null terminating character and back up one character. */
    while (*++string)
        ;
    string--;

    /* Process fractional portion of string starting at the last character. */
    while (*string != '.') {
        /* Check for invalid character */
        if (*string < '0' || *string > '9') {
            return 0;
        }

        /* Multiply fractional piece by 0.1 to setup the next decimal place. */
        uiq31Fractional = __mpyf_ul(uiq31Fractional, iq31_pointOne);

        /*
         * Add the current decimal place converted to iq31 to the sum and
         * decrement pointer.
         */
        uiq31Fractional += __mpy_ul((*string - '0'), iq31_pointOne);
        string--;
    }

    /* Shift integer portion up */
    uiq0Integer <<= q_value;

    /* Shift fractional portion to match Q type with rounding. */
    if (q_value != 31) {
        uiq31Fractional += ((uint32_t)1 << (30 - q_value));
    }
    uiq31Fractional >>= (31 - q_value);

    /* Construct the iqN result. */
    iqNResult = uiq0Integer + uiq31Fractional;
    if (sgn) {
        iqNResult = -iqNResult;
    }

    /* Finished, return the result */
    return iqNResult;
}

/*
 * Convert IQN values to string.
 */
/**
 * @brief Convert an IQ number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQN type input.
 * @param q_value         IQ format.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
  int16_t __IQNtoa(char *string, const char *format, int32_t iqNInput, int16_t q_value) {
    char *pcBuf;                       // buffer pointer
    int16_t count;                // conversion character counter
    uint16_t ui16IntWidth;        // integer format width
    uint16_t ui16FracWidth;       // fractional format width
    uint16_t ui16IntState;        // save interrupt state
    uint16_t ui16MPYState;        // save multiplier state
    uint32_t uiqNInput;           // unsigned input
    uint32_t uiq32Fractional;     // working variable
    uint32_t ui32Integer;         // working variable
    uint32_t ui32IntTemp;         // temp variable
    uint32_t ui32IntegerTenth;    // uval scaled by 10
    uint64_t uiiq32FractionalTen; // fractional input scaled by 10

    /* Check that 1st character is a '%' character. */
    if (*format++ != '%') {
        /* Error: format not preceded with '%' character. */
        return (2);
    }

    /* Check that an integer is provided and extract the integer width. */
    if (*format < '0' || *format > '9') {
        /* Error: integer width is non integer. */
        return (2);
    }

    /* Initialize local variables and extract the integer width. */
    count = 0;
    ui16IntWidth = 0;
    while (*format >= '0' && *format <= '9') {
        ui16IntWidth = __mpy_uw(ui16IntWidth, 10);
        ui16IntWidth = ui16IntWidth + (*format++ - '0');

        /* If we don't find the '.' after 2 counts, something is wrong. */
        if (++count > 2) {
            /* Error: integer width field too many characters */
            return (2);
        }
    }

    /* Check integer width for errors. */
    if (ui16IntWidth > 11) {
        /* Error: integer width too large */
        return (2);
    }

    /* Check the next character for '.' and increment over. */
    if (*format++ != '.') {
        /* Error: format missing the '.' character. */
        return (2);
    }

    /* Re-initialize the local variables and extract the fractional width. */
    count = 0;
    ui16FracWidth = 0;
    while (*format >= '0' && *format <= '9') {
        ui16FracWidth = __mpy_uw(ui16FracWidth, 10);
        ui16FracWidth = ui16FracWidth + (*format++ - '0');

        /* If we don't exit after 2 counts, something is wrong. */
        if (++count > 2) {
            /* Error: fractional width field too many characters */
            return (2);
        }
    }

    /* Check the next character for 'f' or 'F'. */
    if (*format != 'f' && *format != 'F') {
        /* Error: format missing the format specifying character. */
        return (2);
    }

    /* Check that the next character is the NULL string terminator. */
    if (*++format != 0) {
        /* Error: missing null terminator. */
        return (2);
    }

    /*
     * Begin constructing the string.
     */
    pcBuf = string;

    /* Check for negative value. */
    if (iqNInput < 0) {
        iqNInput = -iqNInput;
        *pcBuf++ = '-';
    }
    uiqNInput = (uint32_t)iqNInput;

    /* Construct the integer string in reverse. */
    pcBuf += ui16IntWidth;
    ui32Integer = uiqNInput >> q_value;

    for (count = ui16IntWidth; count > 0; count--) {
        /* Integer position n = ui32Integer - floor(ui32Integer/(10^n))*(10^n) */
        ui32IntegerTenth = __mpyf_l(ui32Integer, iq31_oneTenth);
        ui32IntTemp = __mpy_ul(ui32IntegerTenth, 10);
        /* Handle any possible rounding. */
        if (ui32IntTemp > ui32Integer) {
            ui32IntTemp -= 10;
            ui32IntegerTenth -= 1;
        }
        ui32Integer -= ui32IntTemp;

        *--pcBuf = ui32Integer + '0';
        ui32Integer = ui32IntegerTenth;
    }

    /* Check if there is any remaining input. */
    if (ui32Integer) {
        /* Error: integer format too small. */
        return (1);
    }

    /* Construct the fractional string if specified using unsigned iq32. */
    pcBuf += ui16IntWidth;
    uiq32Fractional = uiqNInput << (32 - q_value);

    if (ui16FracWidth > 0) {
        *pcBuf++ = '.';

        while (ui16FracWidth--) {
            uiiq32FractionalTen = __mpyx_u(uiq32Fractional, 10);

            uiq32Fractional = (uint32_t)uiiq32FractionalTen;
            *pcBuf++ = (uint8_t)(uiiq32FractionalTen >> 32) + '0';
        }
    }

    /* Add null terminating character and return. */
    *pcBuf = 0;
    return (0);
}
/********************************** end ***************************************/
/* ========================================================================== */
/*                         Global Functions Definitions                       */
  /**
   * @brief IQNabs
   *
   * @param a       		IQN type value.
   *
   * @return                IQN type result.
   */
  uint32_t _IQNabs(int32_t a){
	return labs(a);
  }

  /**
   * @brief IQsat
   *
   * @param a       		IQN type value.
   *
   * @return                IQN type result.
   */
  int32_t __IQNsat(int32_t a, int32_t pos, int32_t neg){
	return (((a) > (pos)) ? (pos) : (((a) < (neg)) ? (neg) : (a)));
  }

/**
 * @brief Converts input to floating point using IQ30 format.
 *
 * @param a             IQ30 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ30toF(int32_t a) {
    return __IQNtoF(a, 30);
}

/**
 * @brief Converts input to floating point using IQ29 format.
 *
 * @param a             IQ29 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ29toF(int32_t a) {
    return __IQNtoF(a, 29);
}
/**
 * @brief Converts input to floating point using IQ28 format.
 *
 * @param a             IQ28 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ28toF(int32_t a) {
    return __IQNtoF(a, 28);
}
/**
 * @brief Converts input to floating point using IQ27 format.
 *
 * @param a             IQ27 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ27toF(int32_t a) {
    return __IQNtoF(a, 27);
}
/**
 * @brief Converts input to floating point using IQ26 format.
 *
 * @param a             IQ26 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ26toF(int32_t a) {
    return __IQNtoF(a, 26);
}
/**
 * @brief Converts input to floating point using IQ25 format.
 *
 * @param a             IQ25 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ25toF(int32_t a) {
    return __IQNtoF(a, 25);
}
/**
 * @brief Converts input to floating point using IQ24 format.
 *
 * @param a             IQ24 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ24toF(int32_t a) {
    return __IQNtoF(a, 24);
}
/**
 * @brief Converts input to floating point using IQ23 format.
 *
 * @param a             IQ23 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ23toF(int32_t a) {
    return __IQNtoF(a, 23);
}
/**
 * @brief Converts input to floating point using IQ22 format.
 *
 * @param a             IQ22 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ22toF(int32_t a) {
    return __IQNtoF(a, 22);
}
/**
 * @brief Converts input to floating point using IQ21 format.
 *
 * @param a             IQ21 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ21toF(int32_t a) {
    return __IQNtoF(a, 21);
}
/**
 * @brief Converts input to floating point using IQ20 format.
 *
 * @param a             IQ20 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ20toF(int32_t a) {
    return __IQNtoF(a, 20);
}
/**
 * @brief Converts input to floating point using IQ19 format.
 *
 * @param a             IQ19 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ19toF(int32_t a) {
    return __IQNtoF(a, 19);
}
/**
 * @brief Converts input to floating point using IQ18 format.
 *
 * @param a             IQ18 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ18toF(int32_t a) {
    return __IQNtoF(a, 18);
}
/**
 * @brief Converts input to floating point using IQ17 format.
 *
 * @param a             IQ17 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ17toF(int32_t a) {
	return __IQNtoF(a, 17);
}
/**
 * @brief Converts input to floating point using IQ16 format.
 *
 * @param a             IQ16 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ16toF(int32_t a) {
	return __IQNtoF(a, 16);
}
/**
 * @brief Converts input to floating point using IQ15 format.
 *
 * @param a             IQ15 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ15toF(int32_t a) {
	return __IQNtoF(a, 15);
}
/**
 * @brief Converts input to floating point using IQ14 format.
 *
 * @param a             IQ14 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ14toF(int32_t a) {
	return __IQNtoF(a, 14);
}
/**
 * @brief Converts input to floating point using IQ13 format.
 *
 * @param a             IQ13 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ13toF(int32_t a) {
	return __IQNtoF(a, 13);
}
/**
 * @brief Converts input to floating point using IQ12 format.
 *
 * @param a             IQ12 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ12toF(int32_t a) {
	return __IQNtoF(a, 12);
}
/**
 * @brief Converts input to floating point using IQ11 format.
 *
 * @param a             IQ11 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ11toF(int32_t a) {
	return __IQNtoF(a, 11);
}
/**
 * @brief Converts input to floating point using IQ10 format.
 *
 * @param a             IQ10 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ10toF(int32_t a) {
	return __IQNtoF(a, 10);
}
/**
 * @brief Converts input to floating point using IQ9 format.
 *
 * @param a             IQ9 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ9toF(int32_t a) {
	return __IQNtoF(a, 9);
}
/**
 * @brief Converts input to floating point using IQ8 format.
 *
 * @param a             IQ8 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ8toF(int32_t a) {
	return __IQNtoF(a, 8);
}
/**
 * @brief Converts input to floating point using IQ7 format.
 *
 * @param a             IQ7 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ7toF(int32_t a) {
	return __IQNtoF(a, 7);
}
/**
 * @brief Converts input to floating point using IQ6 format.
 *
 * @param a             IQ6 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ6toF(int32_t a) {
	return __IQNtoF(a, 6);
}
/**
 * @brief Converts input to floating point using IQ5 format.
 *
 * @param a             IQ5 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ5toF(int32_t a) {
	return __IQNtoF(a, 5);
}
/**
 * @brief Converts input to floating point using IQ4 format.
 *
 * @param a             IQ4 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ4toF(int32_t a) {
	return __IQNtoF(a, 4);
}
/**
 * @brief Converts input to floating point using IQ3 format.
 *
 * @param a             IQ3 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ3toF(int32_t a) {
	return __IQNtoF(a, 3);
}
/**
 * @brief Converts input to floating point using IQ2 format.
 *
 * @param a             IQ2 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ2toF(int32_t a) {
	return __IQNtoF(a, 2);
}
/**
 * @brief Converts input to floating point using IQ1 format.
 *
 * @param a             IQ1 type value to be converted.
 *
 * @return              Conversion of input to floating point.
 */
float _IQ1toF(int32_t a) {
	return __IQNtoF(a, 1);
}


//**********************************************************//

/**
 * @brief Multiplies two values of Global_Q format.
 *
 * @param a             IQ type value to be multiplied.
 * @param b             IQ type value to be multiplied.
 *
 * @return              IQ type result of the multiplication.
 */
//int32_t _IQmpy(int32_t a, int32_t b) {
//    return __IQNmpy(a, b, GLOBAL_Q);
//}

/**
 * @brief Multiplies two values of IQ30 format.
 *
 * @param a             IQ30 type value to be multiplied.
 * @param b             IQ30 type value to be multiplied.
 *
 * @return              IQ30 type result of the multiplication.
 */
int32_t _IQ30mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 30);
}
/**
 * @brief Multiplies two values of IQ29 format.
 *
 * @param a             IQ29 type value to be multiplied.
 * @param b             IQ29 type value to be multiplied.
 *
 * @return              IQ29 type result of the multiplication.
 */
int32_t _IQ29mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 29);
}
/**
 * @brief Multiplies two values of IQ28 format.
 *
 * @param a             IQ28 type value to be multiplied.
 * @param b             IQ28 type value to be multiplied.
 *
 * @return              IQ28 type result of the multiplication.
 */
int32_t _IQ28mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 28);
}
/**
 * @brief Multiplies two values of IQ27 format.
 *
 * @param a             IQ27 type value to be multiplied.
 * @param b             IQ27 type value to be multiplied.
 *
 * @return              IQ27 type result of the multiplication.
 */
int32_t _IQ27mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 27);
}
/**
 * @brief Multiplies two values of IQ26 format.
 *
 * @param a             IQ26 type value to be multiplied.
 * @param b             IQ26 type value to be multiplied.
 *
 * @return              IQ26 type result of the multiplication.
 */
int32_t _IQ26mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 26);
}
/**
 * @brief Multiplies two values of IQ25 format.
 *
 * @param a             IQ25 type value to be multiplied.
 * @param b             IQ25 type value to be multiplied.
 *
 * @return              IQ25 type result of the multiplication.
 */
int32_t _IQ25mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 25);
}
/**
 * @brief Multiplies two values of IQ24 format.
 *
 * @param a             IQ24 type value to be multiplied.
 * @param b             IQ24 type value to be multiplied.
 *
 * @return              IQ24 type result of the multiplication.
 */
int32_t _IQ24mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 24);
}
/**
 * @brief Multiplies two values of IQ23 format.
 *
 * @param a             IQ23 type value to be multiplied.
 * @param b             IQ23 type value to be multiplied.
 *
 * @return              IQ23 type result of the multiplication.
 */
int32_t _IQ23mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 23);
}
/**
 * @brief Multiplies two values of IQ22 format.
 *
 * @param a             IQ22 type value to be multiplied.
 * @param b             IQ22 type value to be multiplied.
 *
 * @return              IQ22 type result of the multiplication.
 */
int32_t _IQ22mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 22);
}
/**
 * @brief Multiplies two values of IQ21 format.
 *
 * @param a             IQ21 type value to be multiplied.
 * @param b             IQ21 type value to be multiplied.
 *
 * @return              IQ21 type result of the multiplication.
 */
int32_t _IQ21mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 21);
}
/**
 * @brief Multiplies two values of IQ20 format.
 *
 * @param a             IQ20 type value to be multiplied.
 * @param b             IQ20 type value to be multiplied.
 *
 * @return              IQ20 type result of the multiplication.
 */
int32_t _IQ20mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 20);
}
/**
 * @brief Multiplies two values of IQ19 format.
 *
 * @param a             IQ19 type value to be multiplied.
 * @param b             IQ19 type value to be multiplied.
 *
 * @return              IQ19 type result of the multiplication.
 */
int32_t _IQ19mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 19);
}
/**
 * @brief Multiplies two values of IQ18 format.
 *
 * @param a             IQ18 type value to be multiplied.
 * @param b             IQ18 type value to be multiplied.
 *
 * @return              IQ18 type result of the multiplication.
 */
int32_t _IQ18mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 18);
}
/**
 * @brief Multiplies two values of IQ17 format.
 *
 * @param a             IQ17 type value to be multiplied.
 * @param b             IQ17 type value to be multiplied.
 *
 * @return              IQ17 type result of the multiplication.
 */
int32_t _IQ17mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 17);
}
/**
 * @brief Multiplies two values of IQ16 format.
 *
 * @param a             IQ16 type value to be multiplied.
 * @param b             IQ16 type value to be multiplied.
 *
 * @return              IQ16 type result of the multiplication.
 */
int32_t _IQ16mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 16);
}
/**
 * @brief Multiplies two values of IQ15 format.
 *
 * @param a             IQ15 type value to be multiplied.
 * @param b             IQ15 type value to be multiplied.
 *
 * @return              IQ15 type result of the multiplication.
 */
int32_t _IQ15mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 15);
}
/**
 * @brief Multiplies two values of IQ14 format.
 *
 * @param a             IQ14 type value to be multiplied.
 * @param b             IQ14 type value to be multiplied.
 *
 * @return              IQ14 type result of the multiplication.
 */
int32_t _IQ14mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 14);
}
/**
 * @brief Multiplies two values of IQ13 format.
 *
 * @param a             IQ13 type value to be multiplied.
 * @param b             IQ13 type value to be multiplied.
 *
 * @return              IQ13 type result of the multiplication.
 */
int32_t _IQ13mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 13);
}
/**
 * @brief Multiplies two values of IQ12 format.
 *
 * @param a             IQ12 type value to be multiplied.
 * @param b             IQ12 type value to be multiplied.
 *
 * @return              IQ12 type result of the multiplication.
 */
int32_t _IQ12mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 12);
}
/**
 * @brief Multiplies two values of IQ11 format.
 *
 * @param a             IQ11 type value to be multiplied.
 * @param b             IQ11 type value to be multiplied.
 *
 * @return              IQ11 type result of the multiplication.
 */
int32_t _IQ11mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 11);
}
/**
 * @brief Multiplies two values of IQ10 format.
 *
 * @param a             IQ10 type value to be multiplied.
 * @param b             IQ10 type value to be multiplied.
 *
 * @return              IQ10 type result of the multiplication.
 */
int32_t _IQ10mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 10);
}
/**
 * @brief Multiplies two values of IQ9 format.
 *
 * @param a             IQ9 type value to be multiplied.
 * @param b             IQ9 type value to be multiplied.
 *
 * @return              IQ9 type result of the multiplication.
 */
int32_t _IQ9mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 9);
}
/**
 * @brief Multiplies two values of IQ8 format.
 *
 * @param a             IQ8 type value to be multiplied.
 * @param b             IQ8 type value to be multiplied.
 *
 * @return              IQ8 type result of the multiplication.
 */
int32_t _IQ8mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 8);
}
/**
 * @brief Multiplies two values of IQ7 format.
 *
 * @param a             IQ7 type value to be multiplied.
 * @param b             IQ7 type value to be multiplied.
 *
 * @return              IQ7 type result of the multiplication.
 */
int32_t _IQ7mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 7);
}
/**
 * @brief Multiplies two values of IQ6 format.
 *
 * @param a             IQ6 type value to be multiplied.
 * @param b             IQ6 type value to be multiplied.
 *
 * @return              IQ6 type result of the multiplication.
 */
int32_t _IQ6mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 6);
}
/**
 * @brief Multiplies two values of IQ5 format.
 *
 * @param a             IQ5 type value to be multiplied.
 * @param b             IQ5 type value to be multiplied.
 *
 * @return              IQ5 type result of the multiplication.
 */
int32_t _IQ5mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 5);
}
/**
 * @brief Multiplies two values of IQ4 format.
 *
 * @param a             IQ4 type value to be multiplied.
 * @param b             IQ4 type value to be multiplied.
 *
 * @return              IQ4 type result of the multiplication.
 */
int32_t _IQ4mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 4);
}
/**
 * @brief Multiplies two values of IQ3 format.
 *
 * @param a             IQ3 type value to be multiplied.
 * @param b             IQ3 type value to be multiplied.
 *
 * @return              IQ3 type result of the multiplication.
 */
int32_t _IQ3mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 3);
}
/**
 * @brief Multiplies two values of IQ2 format.
 *
 * @param a             IQ2 type value to be multiplied.
 * @param b             IQ2 type value to be multiplied.
 *
 * @return              IQ2 type result of the multiplication.
 */
int32_t _IQ2mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 2);
}
/**
 * @brief Multiplies two values of IQ1 format.
 *
 * @param a             IQ1 type value to be multiplied.
 * @param b             IQ1 type value to be multiplied.
 *
 * @return              IQ1 type result of the multiplication.
 */
int32_t _IQ1mpy(int32_t a, int32_t b)
{
    return __IQNmpy(a, b, 1);
}

/**
 * @brief Multiply two values of IQ31 type, with rounding.
 *
 * @param a               IQ31 type value input to be multiplied.
 * @param b               IQ31 type value input to be multiplied.
 *
 * @return                IQ31 type result of the multiplication.
 */
int32_t _IQ31rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 31);
}
/**
 * @brief Multiply two values of IQ30 type, with rounding.
 *
 * @param a               IQ30 type value input to be multiplied.
 * @param b               IQ30 type value input to be multiplied.
 *
 * @return                IQ30 type result of the multiplication.
 */
int32_t _IQ30rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 30);
}
/**
 * @brief Multiply two values of IQ29 type, with rounding.
 *
 * @param a               IQ29 type value input to be multiplied.
 * @param b               IQ29 type value input to be multiplied.
 *
 * @return                IQ29 type result of the multiplication.
 */
int32_t _IQ29rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 29);
}
/**
 * @brief Multiply two values of IQ28 type, with rounding.
 *
 * @param a               IQ28 type value input to be multiplied.
 * @param b               IQ28 type value input to be multiplied.
 *
 * @return                IQ28 type result of the multiplication.
 */
int32_t _IQ28rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 28);
}
/**
 * @brief Multiply two values of IQ27 type, with rounding.
 *
 * @param a               IQ27 type value input to be multiplied.
 * @param b               IQ27 type value input to be multiplied.
 *
 * @return                IQ27 type result of the multiplication.
 */
int32_t _IQ27rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 27);
}
/**
 * @brief Multiply two values of IQ26 type, with rounding.
 *
 * @param a               IQ26 type value input to be multiplied.
 * @param b               IQ26 type value input to be multiplied.
 *
 * @return                IQ26 type result of the multiplication.
 */
int32_t _IQ26rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 26);
}
/**
 * @brief Multiply two values of IQ25 type, with rounding.
 *
 * @param a               IQ25 type value input to be multiplied.
 * @param b               IQ25 type value input to be multiplied.
 *
 * @return                IQ25 type result of the multiplication.
 */
int32_t _IQ25rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 25);
}
/**
 * @brief Multiply two values of IQ24 type, with rounding.
 *
 * @param a               IQ24 type value input to be multiplied.
 * @param b               IQ24 type value input to be multiplied.
 *
 * @return                IQ24 type result of the multiplication.
 */
int32_t _IQ24rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 24);
}
/**
 * @brief Multiply two values of IQ23 type, with rounding.
 *
 * @param a               IQ23 type value input to be multiplied.
 * @param b               IQ23 type value input to be multiplied.
 *
 * @return                IQ23 type result of the multiplication.
 */
int32_t _IQ23rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 23);
}
/**
 * @brief Multiply two values of IQ22 type, with rounding.
 *
 * @param a               IQ22 type value input to be multiplied.
 * @param b               IQ22 type value input to be multiplied.
 *
 * @return                IQ22 type result of the multiplication.
 */
int32_t _IQ22rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 22);
}
/**
 * @brief Multiply two values of IQ21 type, with rounding.
 *
 * @param a               IQ21 type value input to be multiplied.
 * @param b               IQ21 type value input to be multiplied.
 *
 * @return                IQ21 type result of the multiplication.
 */
int32_t _IQ21rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 21);
}
/**
 * @brief Multiply two values of IQ20 type, with rounding.
 *
 * @param a               IQ20 type value input to be multiplied.
 * @param b               IQ20 type value input to be multiplied.
 *
 * @return                IQ20 type result of the multiplication.
 */
int32_t _IQ20rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 20);
}
/**
 * @brief Multiply two values of IQ19 type, with rounding.
 *
 * @param a               IQ19 type value input to be multiplied.
 * @param b               IQ19 type value input to be multiplied.
 *
 * @return                IQ19 type result of the multiplication.
 */
int32_t _IQ19rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 19);
}
/**
 * @brief Multiply two values of IQ18 type, with rounding.
 *
 * @param a               IQ18 type value input to be multiplied.
 * @param b               IQ18 type value input to be multiplied.
 *
 * @return                IQ18 type result of the multiplication.
 */
int32_t _IQ18rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 18);
}
/**
 * @brief Multiply two values of IQ17 type, with rounding.
 *
 * @param a               IQ17 type value input to be multiplied.
 * @param b               IQ17 type value input to be multiplied.
 *
 * @return                IQ17 type result of the multiplication.
 */
int32_t _IQ17rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 17);
}
/**
 * @brief Multiply two values of IQ16 type, with rounding.
 *
 * @param a               IQ16 type value input to be multiplied.
 * @param b               IQ16 type value input to be multiplied.
 *
 * @return                IQ16 type result of the multiplication.
 */
int32_t _IQ16rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 16);
}
/**
 * @brief Multiply two values of IQ15 type, with rounding.
 *
 * @param a               IQ15 type value input to be multiplied.
 * @param b               IQ15 type value input to be multiplied.
 *
 * @return                IQ15 type result of the multiplication.
 */
int32_t _IQ15rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 15);
}
/**
 * @brief Multiply two values of IQ14 type, with rounding.
 *
 * @param a               IQ14 type value input to be multiplied.
 * @param b               IQ14 type value input to be multiplied.
 *
 * @return                IQ14 type result of the multiplication.
 */
int32_t _IQ14rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 14);
}
/**
 * @brief Multiply two values of IQ13 type, with rounding.
 *
 * @param a               IQ13 type value input to be multiplied.
 * @param b               IQ13 type value input to be multiplied.
 *
 * @return                IQ13 type result of the multiplication.
 */
int32_t _IQ13rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 13);
}
/**
 * @brief Multiply two values of IQ12 type, with rounding.
 *
 * @param a               IQ12 type value input to be multiplied.
 * @param b               IQ12 type value input to be multiplied.
 *
 * @return                IQ12 type result of the multiplication.
 */
int32_t _IQ12rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 12);
}
/**
 * @brief Multiply two values of IQ11 type, with rounding.
 *
 * @param a               IQ11 type value input to be multiplied.
 * @param b               IQ11 type value input to be multiplied.
 *
 * @return                IQ11 type result of the multiplication.
 */
int32_t _IQ11rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 11);
}
/**
 * @brief Multiply two values of IQ10 type, with rounding.
 *
 * @param a               IQ10 type value input to be multiplied.
 * @param b               IQ10 type value input to be multiplied.
 *
 * @return                IQ10 type result of the multiplication.
 */
int32_t _IQ10rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 10);
}
/**
 * @brief Multiply two values of IQ9 type, with rounding.
 *
 * @param a               IQ9 type value input to be multiplied.
 * @param b               IQ9 type value input to be multiplied.
 *
 * @return                IQ9 type result of the multiplication.
 */
int32_t _IQ9rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 9);
}
/**
 * @brief Multiply two values of IQ8 type, with rounding.
 *
 * @param a               IQ8 type value input to be multiplied.
 * @param b               IQ8 type value input to be multiplied.
 *
 * @return                IQ8 type result of the multiplication.
 */
int32_t _IQ8rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 8);
}
/**
 * @brief Multiply two values of IQ7 type, with rounding.
 *
 * @param a               IQ7 type value input to be multiplied.
 * @param b               IQ7 type value input to be multiplied.
 *
 * @return                IQ7 type result of the multiplication.
 */
int32_t _IQ7rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 7);
}
/**
 * @brief Multiply two values of IQ6 type, with rounding.
 *
 * @param a               IQ6 type value input to be multiplied.
 * @param b               IQ6 type value input to be multiplied.
 *
 * @return                IQ6 type result of the multiplication.
 */
int32_t _IQ6rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 6);
}
/**
 * @brief Multiply two values of IQ5 type, with rounding.
 *
 * @param a               IQ5 type value input to be multiplied.
 * @param b               IQ5 type value input to be multiplied.
 *
 * @return                IQ5 type result of the multiplication.
 */
int32_t _IQ5rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 5);
}
/**
 * @brief Multiply two values of IQ4 type, with rounding.
 *
 * @param a               IQ4 type value input to be multiplied.
 * @param b               IQ4 type value input to be multiplied.
 *
 * @return                IQ4 type result of the multiplication.
 */
int32_t _IQ4rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 4);
}
/**
 * @brief Multiply two values of IQ3 type, with rounding.
 *
 * @param a               IQ3 type value input to be multiplied.
 * @param b               IQ3 type value input to be multiplied.
 *
 * @return                IQ3 type result of the multiplication.
 */
int32_t _IQ3rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 3);
}
/**
 * @brief Multiply two values of IQ2 type, with rounding.
 *
 * @param a               IQ2 type value input to be multiplied.
 * @param b               IQ2 type value input to be multiplied.
 *
 * @return                IQ2 type result of the multiplication.
 */
int32_t _IQ2rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 2);
}
/**
 * @brief Multiply two values of IQ1 type, with rounding.
 *
 * @param a               IQ1 type value input to be multiplied.
 * @param b               IQ1 type value input to be multiplied.
 *
 * @return                IQ1 type result of the multiplication.
 */
int32_t _IQ1rmpy(int32_t a, int32_t b) {
    return __IQNrmpy(a, b, 1);
}

/**
 * @brief Multiplies two IQ31 numbers, with rounding and saturation.
 *
 * @param a               IQ31 type value input to be multiplied.
 * @param b               IQ31 type value input to be multiplied.
 *
 * @return                IQ31 type result of the multiplication.
 */
int32_t _IQ31rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 31);
}
/**
 * @brief Multiplies two IQ30 numbers, with rounding and saturation.
 *
 * @param a               IQ30 type value input to be multiplied.
 * @param b               IQ30 type value input to be multiplied.
 *
 * @return                IQ30 type result of the multiplication.
 */
int32_t _IQ30rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 30);
}
/**
 * @brief Multiplies two IQ29 numbers, with rounding and saturation.
 *
 * @param a               IQ29 type value input to be multiplied.
 * @param b               IQ29 type value input to be multiplied.
 *
 * @return                IQ29 type result of the multiplication.
 */
int32_t _IQ29rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 29);
}
/**
 * @brief Multiplies two IQ28 numbers, with rounding and saturation.
 *
 * @param a               IQ28 type value input to be multiplied.
 * @param b               IQ28 type value input to be multiplied.
 *
 * @return                IQ28 type result of the multiplication.
 */
int32_t _IQ28rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 28);
}
/**
 * @brief Multiplies two IQ27 numbers, with rounding and saturation.
 *
 * @param a               IQ27 type value input to be multiplied.
 * @param b               IQ27 type value input to be multiplied.
 *
 * @return                IQ27 type result of the multiplication.
 */
int32_t _IQ27rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 27);
}
/**
 * @brief Multiplies two IQ26 numbers, with rounding and saturation.
 *
 * @param a               IQ26 type value input to be multiplied.
 * @param b               IQ26 type value input to be multiplied.
 *
 * @return                IQ26 type result of the multiplication.
 */
int32_t _IQ26rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 26);
}
/**
 * @brief Multiplies two IQ25 numbers, with rounding and saturation.
 *
 * @param a               IQ25 type value input to be multiplied.
 * @param b               IQ25 type value input to be multiplied.
 *
 * @return                IQ25 type result of the multiplication.
 */
int32_t _IQ25rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 25);
}
/**
 * @brief Multiplies two IQ24 numbers, with rounding and saturation.
 *
 * @param a               IQ24 type value input to be multiplied.
 * @param b               IQ24 type value input to be multiplied.
 *
 * @return                IQ24 type result of the multiplication.
 */
int32_t _IQ24rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 24);
}
/**
 * @brief Multiplies two IQ23 numbers, with rounding and saturation.
 *
 * @param a               IQ23 type value input to be multiplied.
 * @param b               IQ23 type value input to be multiplied.
 *
 * @return                IQ23 type result of the multiplication.
 */
int32_t _IQ23rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 23);
}
/**
 * @brief Multiplies two IQ22 numbers, with rounding and saturation.
 *
 * @param a               IQ22 type value input to be multiplied.
 * @param b               IQ22 type value input to be multiplied.
 *
 * @return                IQ22 type result of the multiplication.
 */
int32_t _IQ22rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 22);
}
/**
 * @brief Multiplies two IQ21 numbers, with rounding and saturation.
 *
 * @param a               IQ21 type value input to be multiplied.
 * @param b               IQ21 type value input to be multiplied.
 *
 * @return                IQ21 type result of the multiplication.
 */
int32_t _IQ21rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 21);
}
/**
 * @brief Multiplies two IQ20 numbers, with rounding and saturation.
 *
 * @param a               IQ20 type value input to be multiplied.
 * @param b               IQ20 type value input to be multiplied.
 *
 * @return                IQ20 type result of the multiplication.
 */
int32_t _IQ20rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 20);
}
/**
 * @brief Multiplies two IQ19 numbers, with rounding and saturation.
 *
 * @param a               IQ19 type value input to be multiplied.
 * @param b               IQ19 type value input to be multiplied.
 *
 * @return                IQ19 type result of the multiplication.
 */
int32_t _IQ19rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 19);
}
/**
 * @brief Multiplies two IQ18 numbers, with rounding and saturation.
 *
 * @param a               IQ18 type value input to be multiplied.
 * @param b               IQ18 type value input to be multiplied.
 *
 * @return                IQ18 type result of the multiplication.
 */
int32_t _IQ18rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 18);
}
/**
 * @brief Multiplies two IQ17 numbers, with rounding and saturation.
 *
 * @param a               IQ17 type value input to be multiplied.
 * @param b               IQ17 type value input to be multiplied.
 *
 * @return                IQ17 type result of the multiplication.
 */
int32_t _IQ17rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 17);
}
/**
 * @brief Multiplies two IQ16 numbers, with rounding and saturation.
 *
 * @param a               IQ16 type value input to be multiplied.
 * @param b               IQ16 type value input to be multiplied.
 *
 * @return                IQ16 type result of the multiplication.
 */
int32_t _IQ16rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 16);
}
/**
 * @brief Multiplies two IQ15 numbers, with rounding and saturation.
 *
 * @param a               IQ15 type value input to be multiplied.
 * @param b               IQ15 type value input to be multiplied.
 *
 * @return                IQ15 type result of the multiplication.
 */
int32_t _IQ15rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 15);
}
/**
 * @brief Multiplies two IQ14 numbers, with rounding and saturation.
 *
 * @param a               IQ14 type value input to be multiplied.
 * @param b               IQ14 type value input to be multiplied.
 *
 * @return                IQ14 type result of the multiplication.
 */
int32_t _IQ14rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 14);
}
/**
 * @brief Multiplies two IQ13 numbers, with rounding and saturation.
 *
 * @param a               IQ13 type value input to be multiplied.
 * @param b               IQ13 type value input to be multiplied.
 *
 * @return                IQ13 type result of the multiplication.
 */
int32_t _IQ13rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 13);
}
/**
 * @brief Multiplies two IQ12 numbers, with rounding and saturation.
 *
 * @param a               IQ12 type value input to be multiplied.
 * @param b               IQ12 type value input to be multiplied.
 *
 * @return                IQ12 type result of the multiplication.
 */
int32_t _IQ12rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 12);
}
/**
 * @brief Multiplies two IQ11 numbers, with rounding and saturation.
 *
 * @param a               IQ11 type value input to be multiplied.
 * @param b               IQ11 type value input to be multiplied.
 *
 * @return                IQ11 type result of the multiplication.
 */
int32_t _IQ11rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 11);
}
/**
 * @brief Multiplies two IQ10 numbers, with rounding and saturation.
 *
 * @param a               IQ10 type value input to be multiplied.
 * @param b               IQ10 type value input to be multiplied.
 *
 * @return                IQ10 type result of the multiplication.
 */
int32_t _IQ10rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 10);
}
/**
 * @brief Multiplies two IQ9 numbers, with rounding and saturation.
 *
 * @param a               IQ9 type value input to be multiplied.
 * @param b               IQ9 type value input to be multiplied.
 *
 * @return                IQ9 type result of the multiplication.
 */
int32_t _IQ9rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 9);
}
/**
 * @brief Multiplies two IQ8 numbers, with rounding and saturation.
 *
 * @param a               IQ8 type value input to be multiplied.
 * @param b               IQ8 type value input to be multiplied.
 *
 * @return                IQ8 type result of the multiplication.
 */
int32_t _IQ8rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 8);
}
/**
 * @brief Multiplies two IQ7 numbers, with rounding and saturation.
 *
 * @param a               IQ7 type value input to be multiplied.
 * @param b               IQ7 type value input to be multiplied.
 *
 * @return                IQ7 type result of the multiplication.
 */
int32_t _IQ7rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 7);
}
/**
 * @brief Multiplies two IQ6 numbers, with rounding and saturation.
 *
 * @param a               IQ6 type value input to be multiplied.
 * @param b               IQ6 type value input to be multiplied.
 *
 * @return                IQ6 type result of the multiplication.
 */
int32_t _IQ6rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 6);
}
/**
 * @brief Multiplies two IQ5 numbers, with rounding and saturation.
 *
 * @param a               IQ5 type value input to be multiplied.
 * @param b               IQ5 type value input to be multiplied.
 *
 * @return                IQ5 type result of the multiplication.
 */
int32_t _IQ5rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 5);
}
/**
 * @brief Multiplies two IQ4 numbers, with rounding and saturation.
 *
 * @param a               IQ4 type value input to be multiplied.
 * @param b               IQ4 type value input to be multiplied.
 *
 * @return                IQ4 type result of the multiplication.
 */
int32_t _IQ4rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 4);
}
/**
 * @brief Multiplies two IQ3 numbers, with rounding and saturation.
 *
 * @param a               IQ3 type value input to be multiplied.
 * @param b               IQ3 type value input to be multiplied.
 *
 * @return                IQ3 type result of the multiplication.
 */
int32_t _IQ3rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 3);
}
/**
 * @brief Multiplies two IQ2 numbers, with rounding and saturation.
 *
 * @param a               IQ2 type value input to be multiplied.
 * @param b               IQ2 type value input to be multiplied.
 *
 * @return                IQ2 type result of the multiplication.
 */
int32_t _IQ2rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 2);
}
/**
 * @brief Multiplies two IQ1 numbers, with rounding and saturation.
 *
 * @param a               IQ1 type value input to be multiplied.
 * @param b               IQ1 type value input to be multiplied.
 *
 * @return                IQ1 type result of the multiplication.
 */
int32_t _IQ1rsmpy(int32_t a, int32_t b) {
    return __IQNrsmpy(a, b, 1);
}

/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ30 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ GLOBAL_Q type result of the multiplication.
 */
int32_t _IQmpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, GLOBAL_Q);
}

/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ30 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ30 type result of the multiplication.
 */
int32_t _IQ30mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 30);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ29 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ29 type result of the multiplication.
 */
int32_t _IQ29mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 29);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ28 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ28 type result of the multiplication.
 */
int32_t _IQ28mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 28);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ27 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ27 type result of the multiplication.
 */
int32_t _IQ27mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 27);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ26 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ26 type result of the multiplication.
 */
int32_t _IQ26mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 26);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ25 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ25 type result of the multiplication.
 */
int32_t _IQ25mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 25);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ24 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ24 type result of the multiplication.
 */
int32_t _IQ24mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 24);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ23 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ23 type result of the multiplication.
 */
int32_t _IQ23mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 23);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ22 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ22 type result of the multiplication.
 */
int32_t _IQ22mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 22);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ21 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ21 type result of the multiplication.
 */
int32_t _IQ21mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 21);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ20 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ20 type result of the multiplication.
 */
int32_t _IQ20mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 20);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ19 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ19 type result of the multiplication.
 */
int32_t _IQ19mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 19);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ18 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ18 type result of the multiplication.
 */
int32_t _IQ18mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 18);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ17 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ17 type result of the multiplication.
 */
int32_t _IQ17mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 17);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ16 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ16 type result of the multiplication.
 */
int32_t _IQ16mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 16);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ15 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ15 type result of the multiplication.
 */
int32_t _IQ15mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 15);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ14 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ14 type result of the multiplication.
 */
int32_t _IQ14mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 14);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ13 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ13 type result of the multiplication.
 */
int32_t _IQ13mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 13);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ12 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ12 type result of the multiplication.
 */
int32_t _IQ12mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 12);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ11 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ11 type result of the multiplication.
 */
int32_t _IQ11mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 11);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ10 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ10 type result of the multiplication.
 */
int32_t _IQ10mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 10);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ9 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ9 type result of the multiplication.
 */
int32_t _IQ9mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 9);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ8 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ8 type result of the multiplication.
 */
int32_t _IQ8mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 8);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ7 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ7 type result of the multiplication.
 */
int32_t _IQ7mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 7);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ6 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ6 type result of the multiplication.
 */
int32_t _IQ6mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 6);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ5 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ5 type result of the multiplication.
 */
int32_t _IQ5mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 5);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ4 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ4 type result of the multiplication.
 */
int32_t _IQ4mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 4);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ3 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ3 type result of the multiplication.
 */
int32_t _IQ3mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 3);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ2 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ2 type result of the multiplication.
 */
int32_t _IQ2mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 2);
}
/**
 * @brief Multiply two IQ numbers in different IQ formats,
 * returning the product in  IQ1 format.
 *
 * @param a               IQN1 type value input to be multiplied.
 * @param n1              IQ format for first value.
 * @param b               IQN2 type value input to be multiplied.
 * @param n2              IQ format for second value.
 *
 * @return                IQ1 type result of the multiplication.
 */
int32_t _IQ1mpyIQX(int32_t a, int n1, int32_t b, int n2) {
    return __IQNmpyIQX(a, n1, b, n2, 1);
}

/**
 * @brief Divides two values of IQ31 format.
 *
 * @param a             IQ31 type value numerator to be divided.
 * @param b             IQ31 type value denominator to divide by.
 *
 * @return              IQ31 type result of the multiplication.
 */
int32_t _IQ31div(int32_t a, int32_t b) {
    return __IQNdiv(a, b, TYPE_DEFAULT, 31);
}
/**
 * @brief Divides two values of IQ30 format.
 *
 * @param a             IQ30 type value numerator to be divided.
 * @param b             IQ30 type value denominator to divide by.
 *
 * @return              IQ30 type result of the multiplication.
 */
int32_t _IQ30div(int32_t a, int32_t b) {
    return __IQNdiv(a, b, TYPE_DEFAULT, 30);
}
/**
 * @brief Divides two values of IQ29 format.
 *
 * @param a             IQ29 type value numerator to be divided.
 * @param b             IQ29 type value denominator to divide by.
 *
 * @return              IQ29 type result of the multiplication.
 */
int32_t _IQ29div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 29);
}
/**
 * @brief Divides two values of IQ28 format.
 *
 * @param a             IQ28 type value numerator to be divided.
 * @param b             IQ28 type value denominator to divide by.
 *
 * @return              IQ28 type result of the multiplication.
 */
int32_t _IQ28div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 28);
}
/**
 * @brief Divides two values of IQ27 format.
 *
 * @param a             IQ27 type value numerator to be divided.
 * @param b             IQ27 type value denominator to divide by.
 *
 * @return              IQ27 type result of the multiplication.
 */
int32_t _IQ27div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 27);
}
/**
 * @brief Divides two values of IQ26 format.
 *
 * @param a             IQ26 type value numerator to be divided.
 * @param b             IQ26 type value denominator to divide by.
 *
 * @return              IQ26 type result of the multiplication.
 */
int32_t _IQ26div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 26);
}
/**
 * @brief Divides two values of IQ25 format.
 *
 * @param a             IQ25 type value numerator to be divided.
 * @param b             IQ25 type value denominator to divide by.
 *
 * @return              IQ25 type result of the multiplication.
 */
int32_t _IQ25div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 25);
}
/**
 * @brief Divides two values of IQ24 format.
 *
 * @param a             IQ24 type value numerator to be divided.
 * @param b             IQ24 type value denominator to divide by.
 *
 * @return              IQ24 type result of the multiplication.
 */
int32_t _IQ24div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 24);
}
/**
 * @brief Divides two values of IQ23 format.
 *
 * @param a             IQ23 type value numerator to be divided.
 * @param b             IQ23 type value denominator to divide by.
 *
 * @return              IQ23 type result of the multiplication.
 */
int32_t _IQ23div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 23);
}
/**
 * @brief Divides two values of IQ22 format.
 *
 * @param a             IQ22 type value numerator to be divided.
 * @param b             IQ22 type value denominator to divide by.
 *
 * @return              IQ22 type result of the multiplication.
 */
int32_t _IQ22div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 22);
}
/**
 * @brief Divides two values of IQ21 format.
 *
 * @param a             IQ21 type value numerator to be divided.
 * @param b             IQ21 type value denominator to divide by.
 *
 * @return              IQ21 type result of the multiplication.
 */
int32_t _IQ21div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 21);
}
/**
 * @brief Divides two values of IQ20 format.
 *
 * @param a             IQ20 type value numerator to be divided.
 * @param b             IQ20 type value denominator to divide by.
 *
 * @return              IQ20 type result of the multiplication.
 */
int32_t _IQ20div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 20);
}
/**
 * @brief Divides two values of IQ19 format.
 *
 * @param a             IQ19 type value numerator to be divided.
 * @param b             IQ19 type value denominator to divide by.
 *
 * @return              IQ19 type result of the multiplication.
 */
int32_t _IQ19div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 19);
}
/**
 * @brief Divides two values of IQ18 format.
 *
 * @param a             IQ18 type value numerator to be divided.
 * @param b             IQ18 type value denominator to divide by.
 *
 * @return              IQ18 type result of the multiplication.
 */
int32_t _IQ18div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 18);
}
/**
 * @brief Divides two values of IQ17 format.
 *
 * @param a             IQ17 type value numerator to be divided.
 * @param b             IQ17 type value denominator to divide by.
 *
 * @return              IQ17 type result of the multiplication.
 */
int32_t _IQ17div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 17);
}
/**
 * @brief Divides two values of IQ16 format.
 *
 * @param a             IQ16 type value numerator to be divided.
 * @param b             IQ16 type value denominator to divide by.
 *
 * @return              IQ16 type result of the multiplication.
 */
int32_t _IQ16div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 16);
}
/**
 * @brief Divides two values of IQ15 format.
 *
 * @param a             IQ15 type value numerator to be divided.
 * @param b             IQ15 type value denominator to divide by.
 *
 * @return              IQ15 type result of the multiplication.
 */
int32_t _IQ15div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 15);
}
/**
 * @brief Divides two values of IQ14 format.
 *
 * @param a             IQ14 type value numerator to be divided.
 * @param b             IQ14 type value denominator to divide by.
 *
 * @return              IQ14 type result of the multiplication.
 */
int32_t _IQ14div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 14);
}
/**
 * @brief Divides two values of IQ13 format.
 *
 * @param a             IQ13 type value numerator to be divided.
 * @param b             IQ13 type value denominator to divide by.
 *
 * @return              IQ13 type result of the multiplication.
 */
int32_t _IQ13div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 13);
}
/**
 * @brief Divides two values of IQ12 format.
 *
 * @param a             IQ12 type value numerator to be divided.
 * @param b             IQ12 type value denominator to divide by.
 *
 * @return              IQ12 type result of the multiplication.
 */
int32_t _IQ12div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 12);
}
/**
 * @brief Divides two values of IQ11 format.
 *
 * @param a             IQ11 type value numerator to be divided.
 * @param b             IQ11 type value denominator to divide by.
 *
 * @return              IQ11 type result of the multiplication.
 */
int32_t _IQ11div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 11);
}
/**
 * @brief Divides two values of IQ10 format.
 *
 * @param a             IQ10 type value numerator to be divided.
 * @param b             IQ10 type value denominator to divide by.
 *
 * @return              IQ10 type result of the multiplication.
 */
int32_t _IQ10div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 10);
}
/**
 * @brief Divides two values of IQ9 format.
 *
 * @param a             IQ9 type value numerator to be divided.
 * @param b             IQ9 type value denominator to divide by.
 *
 * @return              IQ9 type result of the multiplication.
 */
int32_t _IQ9div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 9);
}
/**
 * @brief Divides two values of IQ8 format.
 *
 * @param a             IQ8 type value numerator to be divided.
 * @param b             IQ8 type value denominator to divide by.
 *
 * @return              IQ8 type result of the multiplication.
 */
int32_t _IQ8div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 8);
}
/**
 * @brief Divides two values of IQ7 format.
 *
 * @param a             IQ7 type value numerator to be divided.
 * @param b             IQ7 type value denominator to divide by.
 *
 * @return              IQ7 type result of the multiplication.
 */
int32_t _IQ7div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 7);
}
/**
 * @brief Divides two values of IQ6 format.
 *
 * @param a             IQ6 type value numerator to be divided.
 * @param b             IQ6 type value denominator to divide by.
 *
 * @return              IQ6 type result of the multiplication.
 */
int32_t _IQ6div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 6);
}
/**
 * @brief Divides two values of IQ5 format.
 *
 * @param a             IQ5 type value numerator to be divided.
 * @param b             IQ5 type value denominator to divide by.
 *
 * @return              IQ5 type result of the multiplication.
 */
int32_t _IQ5div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 5);
}
/**
 * @brief Divides two values of IQ4 format.
 *
 * @param a             IQ4 type value numerator to be divided.
 * @param b             IQ4 type value denominator to divide by.
 *
 * @return              IQ4 type result of the multiplication.
 */
int32_t _IQ4div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 4);
}
/**
 * @brief Divides two values of IQ3 format.
 *
 * @param a             IQ3 type value numerator to be divided.
 * @param b             IQ3 type value denominator to divide by.
 *
 * @return              IQ3 type result of the multiplication.
 */
int32_t _IQ3div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 3);
}
/**
 * @brief Divides two values of IQ2 format.
 *
 * @param a             IQ2 type value numerator to be divided.
 * @param b             IQ2 type value denominator to divide by.
 *
 * @return              IQ2 type result of the multiplication.
 */
int32_t _IQ2div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 2);
}
/**
 * @brief Divides two values of IQ1 format.
 *
 * @param a             IQ1 type value numerator to be divided.
 * @param b             IQ1 type value denominator to divide by.
 *
 * @return              IQ1 type result of the multiplication.
 */
int32_t _IQ1div(int32_t a, int32_t b) {
	return __IQNdiv(a, b, TYPE_DEFAULT, 1);
}

//***********************************************************//

//***********************************************************//
/* IQ sin functions */

/**
 * @brief Computes the cosine of an IQ31 input.
 *
 * @param a               IQ31 type input.
 *
 * @return                IQ31 type result of cosine operation, in radians.
 */
int32_t _IQ31sin(int32_t a) {
    return __IQNsin(a, 31); //, TYPE_SIN, TYPE_RAD
}

/**
 * @brief Computes the cosine of an IQ30 input.
 *
 * @param a               IQ30 type input.
 *
 * @return                IQ30 type result of cosine operation, in radians.
 */
int32_t _IQ30sin(int32_t a) {
    return __IQNsin(a, 30); //, TYPE_SIN, TYPE_RAD
}

/**
 * @brief Computes the cosine of an IQ29 input.
 *
 * @param a               IQ29 type input.
 *
 * @return                IQ29 type result of cosine operation, in radians.
 */
int32_t _IQ29sin(int32_t a) {
    return __IQNsin(a, 29); //, TYPE_SIN, TYPE_RAD
}
/**
 * @brief Computes the sine of an IQ28 input.
 *
 * @param a               IQ28 type input.
 *
 * @return                IQ28 type result of sine operation, in radians.
 */
int32_t _IQ28sin(int32_t a) {
    return __IQNsin(a, 28); //__IQNsin_cos(a, 28, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ27 input.
 *
 * @param a               IQ27 type input.
 *
 * @return                IQ27 type result of sine operation, in radians.
 */
int32_t _IQ27sin(int32_t a) {
    return __IQNsin(a, 27); //__IQNsin_cos(a, 27, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ26 input.
 *
 * @param a               IQ26 type input.
 *
 * @return                IQ26 type result of sine operation, in radians.
 */
int32_t _IQ26sin(int32_t a) {
    return __IQNsin(a, 26); //__IQNsin_cos(a, 26, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ25 input.
 *
 * @param a               IQ25 type input.
 *
 * @return                IQ25 type result of sine operation, in radians.
 */
int32_t _IQ25sin(int32_t a) {
    return __IQNsin(a, 25); //__IQNsin_cos(a, 25, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ24 input.
 *
 * @param a               IQ24 type input.
 *
 * @return                IQ24 type result of sine operation, in radians.
 */
int32_t _IQ24sin(int32_t a) {
    return __IQNsin(a, 24); //__IQNsin_cos(a, 24, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ23 input.
 *
 * @param a               IQ23 type input.
 *
 * @return                IQ23 type result of sine operation, in radians.
 */
int32_t _IQ23sin(int32_t a) {
    return __IQNsin(a, 23); //__IQNsin_cos(a, 23, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ22 input.
 *
 * @param a               IQ22 type input.
 *
 * @return                IQ22 type result of sine operation, in radians.
 */
int32_t _IQ22sin(int32_t a) {
    return __IQNsin(a, 22); //__IQNsin_cos(a, 22, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ21 input.
 *
 * @param a               IQ21 type input.
 *
 * @return                IQ21 type result of sine operation, in radians.
 */
int32_t _IQ21sin(int32_t a) {
    return __IQNsin(a, 21); //__IQNsin_cos(a, 21, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ20 input.
 *
 * @param a               IQ20 type input.
 *
 * @return                IQ20 type result of sine operation, in radians.
 */
int32_t _IQ20sin(int32_t a) {
    return __IQNsin(a, 20); //__IQNsin_cos(a, 20, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ19 input.
 *
 * @param a               IQ19 type input.
 *
 * @return                IQ19 type result of sine operation, in radians.
 */
int32_t _IQ19sin(int32_t a) {
    return __IQNsin(a, 19); //__IQNsin_cos(a, 19, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ18 input.
 *
 * @param a               IQ18 type input.
 *
 * @return                IQ18 type result of sine operation, in radians.
 */
int32_t _IQ18sin(int32_t a) {
    return __IQNsin(a, 18); //__IQNsin_cos(a, 18, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ17 input.
 *
 * @param a               IQ17 type input.
 *
 * @return                IQ17 type result of sine operation, in radians.
 */
int32_t _IQ17sin(int32_t a) {
    return __IQNsin(a, 17); //__IQNsin_cos(a, 17, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ16 input.
 *
 * @param a               IQ16 type input.
 *
 * @return                IQ16 type result of sine operation, in radians.
 */
int32_t _IQ16sin(int32_t a) {
    return __IQNsin(a, 16); //__IQNsin_cos(a, 16, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ15 input.
 *
 * @param a               IQ15 type input.
 *
 * @return                IQ15 type result of sine operation, in radians.
 */
int32_t _IQ15sin(int32_t a) {
    return __IQNsin(a, 15); //__IQNsin_cos(a, 15, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ14 input.
 *
 * @param a               IQ14 type input.
 *
 * @return                IQ14 type result of sine operation, in radians.
 */
int32_t _IQ14sin(int32_t a) {
    return __IQNsin(a, 14); //__IQNsin_cos(a, 14, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ13 input.
 *
 * @param a               IQ13 type input.
 *
 * @return                IQ13 type result of sine operation, in radians.
 */
int32_t _IQ13sin(int32_t a) {
    return __IQNsin(a, 13); //__IQNsin_cos(a, 13, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ12 input.
 *
 * @param a               IQ12 type input.
 *
 * @return                IQ12 type result of sine operation, in radians.
 */
int32_t _IQ12sin(int32_t a) {
    return __IQNsin(a, 12); //__IQNsin_cos(a, 12, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ11 input.
 *
 * @param a               IQ11 type input.
 *
 * @return                IQ11 type result of sine operation, in radians.
 */
int32_t _IQ11sin(int32_t a) {
    return __IQNsin(a, 11); //__IQNsin_cos(a, 11, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ10 input.
 *
 * @param a               IQ10 type input.
 *
 * @return                IQ10 type result of sine operation, in radians.
 */
int32_t _IQ10sin(int32_t a) {
    return __IQNsin(a, 10); //__IQNsin_cos(a, 10, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ9 input.
 *
 * @param a               IQ9 type input.
 *
 * @return                IQ9 type result of sine operation, in radians.
 */
int32_t _IQ9sin(int32_t a) {
    return __IQNsin(a, 9); //__IQNsin_cos(a, 9, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ8 input.
 *
 * @param a               IQ8 type input.
 *
 * @return                IQ8 type result of sine operation, in radians.
 */
int32_t _IQ8sin(int32_t a) {
    return __IQNsin(a, 8); //__IQNsin_cos(a, 8, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ7 input.
 *
 * @param a               IQ7 type input.
 *
 * @return                IQ7 type result of sine operation, in radians.
 */
int32_t _IQ7sin(int32_t a) {
    return __IQNsin(a, 7); //__IQNsin_cos(a, 7, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ6 input.
 *
 * @param a               IQ6 type input.
 *
 * @return                IQ6 type result of sine operation, in radians.
 */
int32_t _IQ6sin(int32_t a) {
    return __IQNsin(a, 6); //__IQNsin_cos(a, 6, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ5 input.
 *
 * @param a               IQ5 type input.
 *
 * @return                IQ5 type result of sine operation, in radians.
 */
int32_t _IQ5sin(int32_t a) {
    return __IQNsin(a, 5); //__IQNsin_cos(a, 5, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ4 input.
 *
 * @param a               IQ4 type input.
 *
 * @return                IQ4 type result of sine operation, in radians.
 */
int32_t _IQ4sin(int32_t a) {
    return __IQNsin(a, 4); //__IQNsin_cos(a, 4, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ3 input.
 *
 * @param a               IQ3 type input.
 *
 * @return                IQ3 type result of sine operation, in radians.
 */
int32_t _IQ3sin(int32_t a) {
    return __IQNsin(a, 3); //__IQNsin_cos(a, 3, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ2 input.
 *
 * @param a               IQ2 type input.
 *
 * @return                IQ2 type result of sine operation, in radians.
 */
int32_t _IQ2sin(int32_t a) {
    return __IQNsin(a, 2); //__IQNsin_cos(a, 2, TYPE_SIN, TYPE_RAD);
}
/**
 * @brief Computes the sine of an IQ1 input.
 *
 * @param a               IQ1 type input.
 *
 * @return                IQ1 type result of sine operation, in radians.
 */
int32_t _IQ1sin(int32_t a) {
    return __IQNsin(a, 1); //__IQNsin_cos(a, 1, TYPE_SIN, TYPE_RAD);
}

/* IQ cos functions */
/**
 * @brief Computes the cosine of an IQ31 input.
 *
 * @param a               IQ31 type input.
 *
 * @return                IQ31 type result of cosine operation, in radians.
 */
int32_t _IQ31cos(int32_t a) {
    return __IQNcos(a, 31); //__IQNsin_cos(a, 29, TYPE_COS, TYPE_RAD);
}

/* IQ cos functions */
/**
 * @brief Computes the cosine of an IQ30 input.
 *
 * @param a               IQ30 type input.
 *
 * @return                IQ30 type result of cosine operation, in radians.
 */
int32_t _IQ30cos(int32_t a) {
    return __IQNcos(a, 30); //__IQNsin_cos(a, 29, TYPE_COS, TYPE_RAD);
}

/**
 * @brief Computes the cosine of an IQ29 input.
 *
 * @param a               IQ29 type input.
 *
 * @return                IQ29 type result of cosine operation, in radians.
 */
int32_t _IQ29cos(int32_t a) {
    return __IQNcos(a, 29); //__IQNsin_cos(a, 29, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ28 input.
 *
 * @param a               IQ28 type input.
 *
 * @return                IQ28 type result of cosine operation, in radians.
 */
int32_t _IQ28cos(int32_t a) {
    return __IQNcos(a, 28); //__IQNsin_cos(a, 28, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ27 input.
 *
 * @param a               IQ27 type input.
 *
 * @return                IQ27 type result of cosine operation, in radians.
 */
int32_t _IQ27cos(int32_t a) {
    return __IQNcos(a, 27); //__IQNsin_cos(a, 27, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ26 input.
 *
 * @param a               IQ26 type input.
 *
 * @return                IQ26 type result of cosine operation, in radians.
 */
int32_t _IQ26cos(int32_t a) {
    return __IQNcos(a, 26); //__IQNsin_cos(a, 26, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ25 input.
 *
 * @param a               IQ25 type input.
 *
 * @return                IQ25 type result of cosine operation, in radians.
 */
int32_t _IQ25cos(int32_t a) {
    return __IQNcos(a, 25); //__IQNsin_cos(a, 25, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ24 input.
 *
 * @param a               IQ24 type input.
 *
 * @return                IQ24 type result of cosine operation, in radians.
 */
int32_t _IQ24cos(int32_t a) {
    return __IQNcos(a, 24); //__IQNsin_cos(a, 24, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ23 input.
 *
 * @param a               IQ23 type input.
 *
 * @return                IQ23 type result of cosine operation, in radians.
 */
int32_t _IQ23cos(int32_t a) {
    return __IQNcos(a, 23); //__IQNsin_cos(a, 23, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ22 input.
 *
 * @param a               IQ22 type input.
 *
 * @return                IQ22 type result of cosine operation, in radians.
 */
int32_t _IQ22cos(int32_t a) {
    return __IQNcos(a, 22); //__IQNsin_cos(a, 22, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ21 input.
 *
 * @param a               IQ21 type input.
 *
 * @return                IQ21 type result of cosine operation, in radians.
 */
int32_t _IQ21cos(int32_t a) {
    return __IQNcos(a, 21); //__IQNsin_cos(a, 21, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ20 input.
 *
 * @param a               IQ20 type input.
 *
 * @return                IQ20 type result of cosine operation, in radians.
 */
int32_t _IQ20cos(int32_t a) {
    return __IQNcos(a, 20); //__IQNsin_cos(a, 20, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ19 input.
 *
 * @param a               IQ19 type input.
 *
 * @return                IQ19 type result of cosine operation, in radians.
 */
int32_t _IQ19cos(int32_t a) {
    return __IQNcos(a, 19); //__IQNsin_cos(a, 19, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ18 input.
 *
 * @param a               IQ18 type input.
 *
 * @return                IQ18 type result of cosine operation, in radians.
 */
int32_t _IQ18cos(int32_t a) {
    return __IQNcos(a, 18); //__IQNsin_cos(a, 18, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ17 input.
 *
 * @param a               IQ17 type input.
 *
 * @return                IQ17 type result of cosine operation, in radians.
 */
int32_t _IQ17cos(int32_t a) {
    return __IQNcos(a, 17); //__IQNsin_cos(a, 17, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ16 input.
 *
 * @param a               IQ16 type input.
 *
 * @return                IQ16 type result of cosine operation, in radians.
 */
int32_t _IQ16cos(int32_t a) {
    return __IQNcos(a, 16); //__IQNsin_cos(a, 16, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ15 input.
 *
 * @param a               IQ15 type input.
 *
 * @return                IQ15 type result of cosine operation, in radians.
 */
int32_t _IQ15cos(int32_t a) {
    return __IQNcos(a, 15); //__IQNsin_cos(a, 15, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ14 input.
 *
 * @param a               IQ14 type input.
 *
 * @return                IQ14 type result of cosine operation, in radians.
 */
int32_t _IQ14cos(int32_t a) {
    return __IQNcos(a, 14); //__IQNsin_cos(a, 14, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ13 input.
 *
 * @param a               IQ13 type input.
 *
 * @return                IQ13 type result of cosine operation, in radians.
 */
int32_t _IQ13cos(int32_t a) {
    return __IQNcos(a, 13); //__IQNsin_cos(a, 13, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ12 input.
 *
 * @param a               IQ12 type input.
 *
 * @return                IQ12 type result of cosine operation, in radians.
 */
int32_t _IQ12cos(int32_t a) {
    return __IQNcos(a, 12); //__IQNsin_cos(a, 12, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ11 input.
 *
 * @param a               IQ11 type input.
 *
 * @return                IQ11 type result of cosine operation, in radians.
 */
int32_t _IQ11cos(int32_t a) {
    return __IQNcos(a, 11); //__IQNsin_cos(a, 11, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ10 input.
 *
 * @param a               IQ10 type input.
 *
 * @return                IQ10 type result of cosine operation, in radians.
 */
int32_t _IQ10cos(int32_t a) {
    return __IQNcos(a, 10); //__IQNsin_cos(a, 10, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ9 input.
 *
 * @param a               IQ9 type input.
 *
 * @return                IQ9 type result of cosine operation, in radians.
 */
int32_t _IQ9cos(int32_t a) {
    return __IQNcos(a, 9); //__IQNsin_cos(a, 9, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ8 input.
 *
 * @param a               IQ8 type input.
 *
 * @return                IQ8 type result of cosine operation, in radians.
 */
int32_t _IQ8cos(int32_t a) {
    return __IQNcos(a, 8); //__IQNsin_cos(a, 8, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ7 input.
 *
 * @param a               IQ7 type input.
 *
 * @return                IQ7 type result of cosine operation, in radians.
 */
int32_t _IQ7cos(int32_t a) {
    return __IQNcos(a, 7); //__IQNsin_cos(a, 7, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ6 input.
 *
 * @param a               IQ6 type input.
 *
 * @return                IQ6 type result of cosine operation, in radians.
 */
int32_t _IQ6cos(int32_t a) {
    return __IQNcos(a, 6); //__IQNsin_cos(a, 6, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ5 input.
 *
 * @param a               IQ5 type input.
 *
 * @return                IQ5 type result of cosine operation, in radians.
 */
int32_t _IQ5cos(int32_t a) {
    return __IQNcos(a, 5); //__IQNsin_cos(a, 5, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ4 input.
 *
 * @param a               IQ4 type input.
 *
 * @return                IQ4 type result of cosine operation, in radians.
 */
int32_t _IQ4cos(int32_t a) {
    return __IQNcos(a, 4); //__IQNsin_cos(a, 4, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ3 input.
 *
 * @param a               IQ3 type input.
 *
 * @return                IQ3 type result of cosine operation, in radians.
 */
int32_t _IQ3cos(int32_t a) {
    return __IQNcos(a, 3); //__IQNsin_cos(a, 3, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ2 input.
 *
 * @param a               IQ2 type input.
 *
 * @return                IQ2 type result of cosine operation, in radians.
 */
int32_t _IQ2cos(int32_t a) {
    return __IQNcos(a, 2); //__IQNsin_cos(a, 2, TYPE_COS, TYPE_RAD);
}
/**
 * @brief Computes the cosine of an IQ1 input.
 *
 * @param a               IQ1 type input.
 *
 * @return                IQ1 type result of cosine operation, in radians.
 */
int32_t _IQ1cos(int32_t a) {
    return __IQNcos(a, 1); //__IQNsin_cos(a, 1, TYPE_COS, TYPE_RAD);
}

/* IQ sinPU functions */
/**
 * @brief Computes the sine of an IQ31 input.
 *
 * @param a               IQ31 type input.
 *
 * @return                IQ31 type per-unit result of sine operation.
 */
int32_t _IQ31sinPU(int32_t a) {
    return __IQNsinPU(a, 31); //__IQNsin_cos(a, 31, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ30 input.
 *
 * @param a               IQ30 type input.
 *
 * @return                IQ30 type per-unit result of sine operation.
 */
int32_t _IQ30sinPU(int32_t a) {
    return __IQNsinPU(a, 30); //__IQNsin_cos(a, 30, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ29 input.
 *
 * @param a               IQ29 type input.
 *
 * @return                IQ29 type per-unit result of sine operation.
 */
int32_t _IQ29sinPU(int32_t a) {
    return __IQNsinPU(a, 29); //__IQNsin_cos(a, 29, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ28 input.
 *
 * @param a               IQ28 type input.
 *
 * @return                IQ28 type per-unit result of sine operation.
 */
int32_t _IQ28sinPU(int32_t a) {
    return __IQNsinPU(a, 28); //__IQNsin_cos(a, 28, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ27 input.
 *
 * @param a               IQ27 type input.
 *
 * @return                IQ27 type per-unit result of sine operation.
 */
int32_t _IQ27sinPU(int32_t a) {
    return __IQNsinPU(a, 27); //__IQNsin_cos(a, 27, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ26 input.
 *
 * @param a               IQ26 type input.
 *
 * @return                IQ26 type per-unit result of sine operation.
 */
int32_t _IQ26sinPU(int32_t a) {
    return __IQNsinPU(a, 26); //__IQNsin_cos(a, 26, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ25 input.
 *
 * @param a               IQ25 type input.
 *
 * @return                IQ25 type per-unit result of sine operation.
 */
int32_t _IQ25sinPU(int32_t a) {
    return __IQNsinPU(a, 25); //__IQNsin_cos(a, 25, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ24 input.
 *
 * @param a               IQ24 type input.
 *
 * @return                IQ24 type per-unit result of sine operation.
 */
int32_t _IQ24sinPU(int32_t a) {
    return __IQNsinPU(a, 24); //__IQNsin_cos(a, 24, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ23 input.
 *
 * @param a               IQ23 type input.
 *
 * @return                IQ23 type per-unit result of sine operation.
 */
int32_t _IQ23sinPU(int32_t a) {
    return __IQNsinPU(a, 23); //__IQNsin_cos(a, 23, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ22 input.
 *
 * @param a               IQ22 type input.
 *
 * @return                IQ22 type per-unit result of sine operation.
 */
int32_t _IQ22sinPU(int32_t a) {
    return __IQNsinPU(a, 22); //__IQNsin_cos(a, 22, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ21 input.
 *
 * @param a               IQ21 type input.
 *
 * @return                IQ21 type per-unit result of sine operation.
 */
int32_t _IQ21sinPU(int32_t a) {
    return __IQNsinPU(a, 21); //__IQNsin_cos(a, 21, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ20 input.
 *
 * @param a               IQ20 type input.
 *
 * @return                IQ20 type per-unit result of sine operation.
 */
int32_t _IQ20sinPU(int32_t a) {
    return __IQNsinPU(a, 20); //__IQNsin_cos(a, 20, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ19 input.
 *
 * @param a               IQ19 type input.
 *
 * @return                IQ19 type per-unit result of sine operation.
 */
int32_t _IQ19sinPU(int32_t a) {
    return __IQNsinPU(a, 19); //__IQNsin_cos(a, 19, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ18 input.
 *
 * @param a               IQ18 type input.
 *
 * @return                IQ18 type per-unit result of sine operation.
 */
int32_t _IQ18sinPU(int32_t a) {
    return __IQNsinPU(a, 18); //__IQNsin_cos(a, 18, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ17 input.
 *
 * @param a               IQ17 type input.
 *
 * @return                IQ17 type per-unit result of sine operation.
 */
int32_t _IQ17sinPU(int32_t a) {
    return __IQNsinPU(a, 17); //__IQNsin_cos(a, 17, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ16 input.
 *
 * @param a               IQ16 type input.
 *
 * @return                IQ16 type per-unit result of sine operation.
 */
int32_t _IQ16sinPU(int32_t a) {
    return __IQNsinPU(a, 16); //__IQNsin_cos(a, 16, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ15 input.
 *
 * @param a               IQ15 type input.
 *
 * @return                IQ15 type per-unit result of sine operation.
 */
int32_t _IQ15sinPU(int32_t a) {
    return __IQNsinPU(a, 15); //__IQNsin_cos(a, 15, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ14 input.
 *
 * @param a               IQ14 type input.
 *
 * @return                IQ14 type per-unit result of sine operation.
 */
int32_t _IQ14sinPU(int32_t a) {
    return __IQNsinPU(a, 14); //__IQNsin_cos(a, 14, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ13 input.
 *
 * @param a               IQ13 type input.
 *
 * @return                IQ13 type per-unit result of sine operation.
 */
int32_t _IQ13sinPU(int32_t a) {
    return __IQNsinPU(a, 13); //__IQNsin_cos(a, 13, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ12 input.
 *
 * @param a               IQ12 type input.
 *
 * @return                IQ12 type per-unit result of sine operation.
 */
int32_t _IQ12sinPU(int32_t a) {
    return __IQNsinPU(a, 12); //__IQNsin_cos(a, 12, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ11 input.
 *
 * @param a               IQ11 type input.
 *
 * @return                IQ11 type per-unit result of sine operation.
 */
int32_t _IQ11sinPU(int32_t a) {
    return __IQNsinPU(a, 11); //__IQNsin_cos(a, 11, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ10 input.
 *
 * @param a               IQ10 type input.
 *
 * @return                IQ10 type per-unit result of sine operation.
 */
int32_t _IQ10sinPU(int32_t a) {
    return __IQNsinPU(a, 10); //__IQNsin_cos(a, 10, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ9 input.
 *
 * @param a               IQ9 type input.
 *
 * @return                IQ9 type per-unit result of sine operation.
 */
int32_t _IQ9sinPU(int32_t a) {
    return __IQNsinPU(a, 9); //__IQNsin_cos(a, 9, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ8 input.
 *
 * @param a               IQ8 type input.
 *
 * @return                IQ8 type per-unit result of sine operation.
 */
int32_t _IQ8sinPU(int32_t a) {
    return __IQNsinPU(a, 8); //__IQNsin_cos(a, 8, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ7 input.
 *
 * @param a               IQ7 type input.
 *
 * @return                IQ7 type per-unit result of sine operation.
 */
int32_t _IQ7sinPU(int32_t a) {
    return __IQNsinPU(a, 7); //__IQNsin_cos(a, 7, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ6 input.
 *
 * @param a               IQ6 type input.
 *
 * @return                IQ6 type per-unit result of sine operation.
 */
int32_t _IQ6sinPU(int32_t a) {
    return __IQNsinPU(a, 6); //__IQNsin_cos(a, 6, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ5 input.
 *
 * @param a               IQ5 type input.
 *
 * @return                IQ5 type per-unit result of sine operation.
 */
int32_t _IQ5sinPU(int32_t a) {
    return __IQNsinPU(a, 5); //__IQNsin_cos(a, 5, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ4 input.
 *
 * @param a               IQ4 type input.
 *
 * @return                IQ4 type per-unit result of sine operation.
 */
int32_t _IQ4sinPU(int32_t a) {
    return __IQNsinPU(a, 4); //__IQNsin_cos(a, 4, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ3 input.
 *
 * @param a               IQ3 type input.
 *
 * @return                IQ3 type per-unit result of sine operation.
 */
int32_t _IQ3sinPU(int32_t a) {
    return __IQNsinPU(a, 3); //__IQNsin_cos(a, 3, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ2 input.
 *
 * @param a               IQ2 type input.
 *
 * @return                IQ2 type per-unit result of sine operation.
 */
int32_t _IQ2sinPU(int32_t a) {
    return __IQNsinPU(a, 2); //__IQNsin_cos(a, 2, TYPE_SIN, TYPE_PU);
}
/**
 * @brief Computes the sine of an IQ1 input.
 *
 * @param a               IQ1 type input.
 *
 * @return                IQ1 type per-unit result of sine operation.
 */
int32_t _IQ1sinPU(int32_t a) {
    return __IQNsinPU(a, 1); //__IQNsin_cos(a, 1, TYPE_SIN, TYPE_PU);
}

/* IQ cosPU functions */
/**
 * @brief Computes the cosine of an IQ31 input.
 *
 * @param a               IQ31 type input.
 *
 * @return                IQ31 type per-unit result of cosine operation.
 */
int32_t _IQ31cosPU(int32_t a) {
    return __IQNcosPU(a, 31); //__IQNsin_cos(a, 31, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ30 input.
 *
 * @param a               IQ30 type input.
 *
 * @return                IQ30 type per-unit result of cosine operation.
 */
int32_t _IQ30cosPU(int32_t a) {
    return __IQNcosPU(a, 30); //__IQNsin_cos(a, 30, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ29 input.
 *
 * @param a               IQ29 type input.
 *
 * @return                IQ29 type per-unit result of cosine operation.
 */
int32_t _IQ29cosPU(int32_t a) {
    return __IQNcosPU(a, 29); //__IQNsin_cos(a, 29, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ28 input.
 *
 * @param a               IQ28 type input.
 *
 * @return                IQ28 type per-unit result of cosine operation.
 */
int32_t _IQ28cosPU(int32_t a) {
    return __IQNcosPU(a, 28); //__IQNsin_cos(a, 28, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ27 input.
 *
 * @param a               IQ27 type input.
 *
 * @return                IQ27 type per-unit result of cosine operation.
 */
int32_t _IQ27cosPU(int32_t a) {
    return __IQNcosPU(a, 27); //__IQNsin_cos(a, 27, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ26 input.
 *
 * @param a               IQ26 type input.
 *
 * @return                IQ26 type per-unit result of cosine operation.
 */
int32_t _IQ26cosPU(int32_t a) {
    return __IQNcosPU(a, 26); //__IQNsin_cos(a, 26, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ25 input.
 *
 * @param a               IQ25 type input.
 *
 * @return                IQ25 type per-unit result of cosine operation.
 */
int32_t _IQ25cosPU(int32_t a) {
    return __IQNcosPU(a, 25); //__IQNsin_cos(a, 25, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ24 input.
 *
 * @param a               IQ24 type input.
 *
 * @return                IQ24 type per-unit result of cosine operation.
 */
int32_t _IQ24cosPU(int32_t a) {
    return __IQNcosPU(a, 24); //__IQNsin_cos(a, 24, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ23 input.
 *
 * @param a               IQ23 type input.
 *
 * @return                IQ23 type per-unit result of cosine operation.
 */
int32_t _IQ23cosPU(int32_t a) {
    return __IQNcosPU(a, 23); //__IQNsin_cos(a, 23, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ22 input.
 *
 * @param a               IQ22 type input.
 *
 * @return                IQ22 type per-unit result of cosine operation.
 */
int32_t _IQ22cosPU(int32_t a) {
    return __IQNcosPU(a, 22); //__IQNsin_cos(a, 22, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ21 input.
 *
 * @param a               IQ21 type input.
 *
 * @return                IQ21 type per-unit result of cosine operation.
 */
int32_t _IQ21cosPU(int32_t a) {
    return __IQNcosPU(a, 21); //__IQNsin_cos(a, 21, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ20 input.
 *
 * @param a               IQ20 type input.
 *
 * @return                IQ20 type per-unit result of cosine operation.
 */
int32_t _IQ20cosPU(int32_t a) {
    return __IQNcosPU(a, 20); //__IQNsin_cos(a, 20, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ19 input.
 *
 * @param a               IQ19 type input.
 *
 * @return                IQ19 type per-unit result of cosine operation.
 */
int32_t _IQ19cosPU(int32_t a) {
    return __IQNcosPU(a, 19); //__IQNsin_cos(a, 19, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ18 input.
 *
 * @param a               IQ18 type input.
 *
 * @return                IQ18 type per-unit result of cosine operation.
 */
int32_t _IQ18cosPU(int32_t a) {
    return __IQNcosPU(a, 18); //__IQNsin_cos(a, 18, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ17 input.
 *
 * @param a               IQ17 type input.
 *
 * @return                IQ17 type per-unit result of cosine operation.
 */
int32_t _IQ17cosPU(int32_t a) {
    return __IQNcosPU(a, 17); //__IQNsin_cos(a, 17, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ16 input.
 *
 * @param a               IQ16 type input.
 *
 * @return                IQ16 type per-unit result of cosine operation.
 */
int32_t _IQ16cosPU(int32_t a) {
    return __IQNcosPU(a, 16); //__IQNsin_cos(a, 16, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ15 input.
 *
 * @param a               IQ15 type input.
 *
 * @return                IQ15 type per-unit result of cosine operation.
 */
int32_t _IQ15cosPU(int32_t a) {
    return __IQNcosPU(a, 15); //__IQNsin_cos(a, 15, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ14 input.
 *
 * @param a               IQ14 type input.
 *
 * @return                IQ14 type per-unit result of cosine operation.
 */
int32_t _IQ14cosPU(int32_t a) {
    return __IQNcosPU(a, 14); //__IQNsin_cos(a, 14, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ13 input.
 *
 * @param a               IQ13 type input.
 *
 * @return                IQ13 type per-unit result of cosine operation.
 */
int32_t _IQ13cosPU(int32_t a) {
    return __IQNcosPU(a, 13); //__IQNsin_cos(a, 13, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ12 input.
 *
 * @param a               IQ12 type input.
 *
 * @return                IQ12 type per-unit result of cosine operation.
 */
int32_t _IQ12cosPU(int32_t a) {
    return __IQNcosPU(a, 12); //__IQNsin_cos(a, 12, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ11 input.
 *
 * @param a               IQ11 type input.
 *
 * @return                IQ11 type per-unit result of cosine operation.
 */
int32_t _IQ11cosPU(int32_t a) {
    return __IQNcosPU(a, 11); //__IQNsin_cos(a, 11, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ10 input.
 *
 * @param a               IQ10 type input.
 *
 * @return                IQ10 type per-unit result of cosine operation.
 */
int32_t _IQ10cosPU(int32_t a) {
    return __IQNcosPU(a, 10); //__IQNsin_cos(a, 10, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ9 input.
 *
 * @param a               IQ9 type input.
 *
 * @return                IQ9 type per-unit result of cosine operation.
 */
int32_t _IQ9cosPU(int32_t a) {
    return __IQNcosPU(a, 9); //__IQNsin_cos(a, 9, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ8 input.
 *
 * @param a               IQ8 type input.
 *
 * @return                IQ8 type per-unit result of cosine operation.
 */
int32_t _IQ8cosPU(int32_t a) {
    return __IQNcosPU(a, 8); //__IQNsin_cos(a, 8, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ7 input.
 *
 * @param a               IQ7 type input.
 *
 * @return                IQ7 type per-unit result of cosine operation.
 */
int32_t _IQ7cosPU(int32_t a) {
    return __IQNcosPU(a, 7); //__IQNsin_cos(a, 7, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ6 input.
 *
 * @param a               IQ6 type input.
 *
 * @return                IQ6 type per-unit result of cosine operation.
 */
int32_t _IQ6cosPU(int32_t a) {
    return __IQNcosPU(a, 6); //__IQNsin_cos(a, 6, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ5 input.
 *
 * @param a               IQ5 type input.
 *
 * @return                IQ5 type per-unit result of cosine operation.
 */
int32_t _IQ5cosPU(int32_t a) {
    return __IQNcosPU(a, 5); //__IQNsin_cos(a, 5, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ4 input.
 *
 * @param a               IQ4 type input.
 *
 * @return                IQ4 type per-unit result of cosine operation.
 */
int32_t _IQ4cosPU(int32_t a) {
    return __IQNcosPU(a, 4); //__IQNsin_cos(a, 4, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ3 input.
 *
 * @param a               IQ3 type input.
 *
 * @return                IQ3 type per-unit result of cosine operation.
 */
int32_t _IQ3cosPU(int32_t a) {
    return __IQNcosPU(a, 3); //__IQNsin_cos(a, 3, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ2 input.
 *
 * @param a               IQ2 type input.
 *
 * @return                IQ2 type per-unit result of cosine operation.
 */
int32_t _IQ2cosPU(int32_t a) {
    return __IQNcosPU(a, 2); //__IQNsin_cos(a, 2, TYPE_COS, TYPE_PU);
}
/**
 * @brief Computes the cosine of an IQ1 input.
 *
 * @param a               IQ1 type input.
 *
 * @return                IQ1 type per-unit result of cosine operation.
 */
int32_t _IQ1cosPU(int32_t a) {
    return __IQNcosPU(a, 1); //__IQNsin_cos(a, 1, TYPE_COS, TYPE_PU);
}

/* ASIN */
/**
 * @brief Computes the inverse sine of the IQ29 input.
 *
 * @param a               IQ29 type input.
 *
 * @return                IQ29 type result of inverse sine.
 */
int32_t _IQ29asin(int32_t a) {
//
//	register float32_t float29Result;
//
//	float29Result = __iqn2float(a, 29); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float29Result, __sqrt(1-float29Result*float29Result))), 29); //convert float value to iqn
//	#else
    return __IQNasin(a, 29);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ28 input.
 *
 * @param a               IQ28 type input.
 *
 * @return                IQ28 type result of inverse sine.
 */
int32_t _IQ28asin(int32_t a) {
//
//	register float32_t float28Result;
//
//	float28Result = __iqn2float(a, 28); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float28Result, __sqrt(1-float28Result*float28Result))), 28); //convert float value to iqn
//	#else
    return __IQNasin(a, 28);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ27 input.
 *
 * @param a               IQ27 type input.
 *
 * @return                IQ27 type result of inverse sine.
 */
int32_t _IQ27asin(int32_t a) {
//
//	register float32_t float27Result;
//
//	float27Result = __iqn2float(a, 27); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float27Result, __sqrt(1-float27Result*float27Result))), 27); //convert float value to iqn
//	#else
    return __IQNasin(a, 27);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ26 input.
 *
 * @param a               IQ26 type input.
 *
 * @return                IQ26 type result of inverse sine.
 */
int32_t _IQ26asin(int32_t a) {
//
//	register float32_t float26Result;
//
//	float26Result = __iqn2float(a, 26); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float26Result, __sqrt(1-float26Result*float26Result))), 26); //convert float value to iqn
//	#else
    return __IQNasin(a, 26);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ25 input.
 *
 * @param a               IQ25 type input.
 *
 * @return                IQ25 type result of inverse sine.
 */
int32_t _IQ25asin(int32_t a) {
//
//	register float32_t float25Result;
//
//	float25Result = __iqn2float(a, 25); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float25Result, __sqrt(1-float25Result*float25Result))), 25); //convert float value to iqn
//	#else
    return __IQNasin(a, 25);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ24 input.
 *
 * @param a               IQ24 type input.
 *
 * @return                IQ24 type result of inverse sine.
 */
int32_t _IQ24asin(int32_t a) {
//
//	register float32_t float24Result;
//
//	float24Result = __iqn2float(a, 24); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float24Result, __sqrt(1-float24Result*float24Result))), 24); //convert float value to iqn
//	#else
    return __IQNasin(a, 24);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ23 input.
 *
 * @param a               IQ23 type input.
 *
 * @return                IQ23 type result of inverse sine.
 */
int32_t _IQ23asin(int32_t a) {
//
//	register float32_t float23Result;
//
//	float23Result = __iqn2float(a, 23); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float23Result, __sqrt(1-float23Result*float23Result))), 23); //convert float value to iqn
//	#else
    return __IQNasin(a, 23);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ22 input.
 *
 * @param a               IQ22 type input.
 *
 * @return                IQ22 type result of inverse sine.
 */
int32_t _IQ22asin(int32_t a) {
//
//	register float32_t float22Result;
//
//	float22Result = __iqn2float(a, 22); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float22Result, __sqrt(1-float22Result*float22Result))), 22); //convert float value to iqn
//	#else
    return __IQNasin(a, 22);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ21 input.
 *
 * @param a               IQ21 type input.
 *
 * @return                IQ21 type result of inverse sine.
 */
int32_t _IQ21asin(int32_t a) {
//
//	register float32_t float21Result;
//
//	float21Result = __iqn2float(a, 21); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float21Result, __sqrt(1-float21Result*float21Result))), 21); //convert float value to iqn
//	#else
    return __IQNasin(a, 21);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ20 input.
 *
 * @param a               IQ20 type input.
 *
 * @return                IQ20 type result of inverse sine.
 */
int32_t _IQ20asin(int32_t a) {
//
//	register float32_t float20Result;
//
//	float20Result = __iqn2float(a, 20); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float20Result, __sqrt(1-float20Result*float20Result))), 20); //convert float value to iqn
//	#else
    return __IQNasin(a, 20);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ19 input.
 *
 * @param a               IQ19 type input.
 *
 * @return                IQ19 type result of inverse sine.
 */
int32_t _IQ19asin(int32_t a) {
//
//	register float32_t float19Result;
//
//	float19Result = __iqn2float(a, 19); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float19Result, __sqrt(1-float19Result*float19Result))), 19); //convert float value to iqn
//	#else
    return __IQNasin(a, 19);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ18 input.
 *
 * @param a               IQ18 type input.
 *
 * @return                IQ18 type result of inverse sine.
 */
int32_t _IQ18asin(int32_t a) {
//
//	register float32_t float18Result;
//
//	float18Result = __iqn2float(a, 18); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float18Result, __sqrt(1-float18Result*float18Result))), 18); //convert float value to iqn
//	#else
    return __IQNasin(a, 18);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ17 input.
 *
 * @param a               IQ17 type input.
 *
 * @return                IQ17 type result of inverse sine.
 */
int32_t _IQ17asin(int32_t a) {
//
//	register float32_t float17Result;
//
//	float17Result = __iqn2float(a, 17); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float17Result, __sqrt(1-float17Result*float17Result))), 17); //convert float value to iqn
//	#else
    return __IQNasin(a, 17);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ16 input.
 *
 * @param a               IQ16 type input.
 *
 * @return                IQ16 type result of inverse sine.
 */
int32_t _IQ16asin(int32_t a) {
//
//	register float32_t float16Result;
//
//	float16Result = __iqn2float(a, 16); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float16Result, __sqrt(1-float16Result*float16Result))), 16); //convert float value to iqn
//	#else
    return __IQNasin(a, 16);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ15 input.
 *
 * @param a               IQ15 type input.
 *
 * @return                IQ15 type result of inverse sine.
 */
int32_t _IQ15asin(int32_t a) {
//
//	register float32_t float15Result;
//
//	float15Result = __iqn2float(a, 15); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float15Result, __sqrt(1-float15Result*float15Result))), 15); //convert float value to iqn
//	#else
    return __IQNasin(a, 15);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ14 input.
 *
 * @param a               IQ14 type input.
 *
 * @return                IQ14 type result of inverse sine.
 */
int32_t _IQ14asin(int32_t a) {
//
//	register float32_t float14Result;
//
//	float14Result = __iqn2float(a, 14); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float14Result, __sqrt(1-float14Result*float14Result))), 14); //convert float value to iqn
//	#else
    return __IQNasin(a, 14);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ13 input.
 *
 * @param a               IQ13 type input.
 *
 * @return                IQ13 type result of inverse sine.
 */
int32_t _IQ13asin(int32_t a) {
//
//	register float32_t float13Result;
//
//	float13Result = __iqn2float(a, 13); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float13Result, __sqrt(1-float13Result*float13Result))), 13); //convert float value to iqn
//	#else
    return __IQNasin(a, 13);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ12 input.
 *
 * @param a               IQ12 type input.
 *
 * @return                IQ12 type result of inverse sine.
 */
int32_t _IQ12asin(int32_t a) {
//
//	register float32_t float12Result;
//
//	float12Result = __iqn2float(a, 12); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float12Result, __sqrt(1-float12Result*float12Result))), 12); //convert float value to iqn
//	#else
    return __IQNasin(a, 12);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ11 input.
 *
 * @param a               IQ11 type input.
 *
 * @return                IQ11 type result of inverse sine.
 */
int32_t _IQ11asin(int32_t a) {
//
//	register float32_t float11Result;
//
//	float11Result = __iqn2float(a, 11); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float11Result, __sqrt(1-float11Result*float11Result))), 11); //convert float value to iqn
//	#else
    return __IQNasin(a, 11);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ10 input.
 *
 * @param a               IQ10 type input.
 *
 * @return                IQ10 type result of inverse sine.
 */
int32_t _IQ10asin(int32_t a) {
//
//	register float32_t float10Result;
//
//	float10Result = __iqn2float(a, 10); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float10Result, __sqrt(1-float10Result*float10Result))), 10); //convert float value to iqn
//	#else
    return __IQNasin(a, 10);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ9 input.
 *
 * @param a               IQ9 type input.
 *
 * @return                IQ9 type result of inverse sine.
 */
int32_t _IQ9asin(int32_t a) {
//
//	register float32_t float9Result;
//
//	float9Result = __iqn2float(a, 9); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float9Result, __sqrt(1-float9Result*float9Result))), 9); //convert float value to iqn
//	#else
    return __IQNasin(a, 9);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ8 input.
 *
 * @param a               IQ8 type input.
 *
 * @return                IQ8 type result of inverse sine.
 */
int32_t _IQ8asin(int32_t a) {
//
//	register float32_t float8Result;
//
//	float8Result = __iqn2float(a, 8); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float8Result, __sqrt(1-float8Result*float8Result))), 8); //convert float value to iqn
//	#else
    return __IQNasin(a, 8);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ7 input.
 *
 * @param a               IQ7 type input.
 *
 * @return                IQ7 type result of inverse sine.
 */
int32_t _IQ7asin(int32_t a) {
//
//	register float32_t float7Result;
//
//	float7Result = __iqn2float(a, 7); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float7Result, __sqrt(1-float7Result*float7Result))), 7); //convert float value to iqn
//	#else
    return __IQNasin(a, 7);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ6 input.
 *
 * @param a               IQ6 type input.
 *
 * @return                IQ6 type result of inverse sine.
 */
int32_t _IQ6asin(int32_t a) {
//
//	register float32_t float6Result;
//
//	float6Result = __iqn2float(a, 6); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float6Result, __sqrt(1-float6Result*float6Result))), 6); //convert float value to iqn
//	#else
    return __IQNasin(a, 6);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ5 input.
 *
 * @param a               IQ5 type input.
 *
 * @return                IQ5 type result of inverse sine.
 */
int32_t _IQ5asin(int32_t a) {
//
//	register float32_t float5Result;
//
//	float5Result = __iqn2float(a, 5); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float5Result, __sqrt(1-float5Result*float5Result))), 5); //convert float value to iqn
//	#else
    return __IQNasin(a, 5);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ4 input.
 *
 * @param a               IQ4 type input.
 *
 * @return                IQ4 type result of inverse sine.
 */
int32_t _IQ4asin(int32_t a) {
//
//	register float32_t float4Result;
//
//	float4Result = __iqn2float(a, 4); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float4Result, __sqrt(1-float4Result*float4Result))), 4); //convert float value to iqn
//	#else
    return __IQNasin(a, 4);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ3 input.
 *
 * @param a               IQ3 type input.
 *
 * @return                IQ3 type result of inverse sine.
 */
int32_t _IQ3asin(int32_t a) {
//
//	register float32_t float3Result;
//
//	float3Result = __iqn2float(a, 3); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float3Result, __sqrt(1-float3Result*float3Result))), 3); //convert float value to iqn
//	#else
    return __IQNasin(a, 3);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ2 input.
 *
 * @param a               IQ2 type input.
 *
 * @return                IQ2 type result of inverse sine.
 */
int32_t _IQ2asin(int32_t a) {
//
//	register float32_t float2Result;
//
//	float2Result = __iqn2float(a, 2); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float2Result, __sqrt(1-float2Result*float2Result))), 2); //convert float value to iqn
//	#else
    return __IQNasin(a, 2);
//	#endif
}
/**
 * @brief Computes the inverse sine of the IQ1 input.
 *
 * @param a               IQ1 type input.
 *
 * @return                IQ1 type result of inverse sine.
 */
int32_t _IQ1asin(int32_t a) {
//
//	register float32_t float1Result;
//
//	float1Result = __iqn2float(a, 1); //convert iqn value to float
//	return __float2iqn(__atan(__divf32(float1Result, __sqrt(1-float1Result*float1Result))), 1); //convert float value to iqn
//	#else
    return __IQNasin(a, 1);
//	#endif
}

/* ATAN2 */
/**
 * @brief Compute the 4-quadrant arctangent of the IQ30 input
 *        and return the result, in radians.
 *
 * @param y               IQ30 type input y.
 * @param x               IQ30 type input x.
 *
 * @return                IQ30 type result of 4-quadrant arctangent.
 */
int32_t _IQ30atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 30);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ29 input
 *        and return the result, in radians.
 *
 * @param y               IQ29 type input y.
 * @param x               IQ29 type input x.
 *
 * @return                IQ29 type result of 4-quadrant arctangent.
 */
int32_t _IQ29atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 29);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ28 input
 *        and return the result, in radians.
 *
 * @param y               IQ28 type input y.
 * @param x               IQ28 type input x.
 *
 * @return                IQ28 type result of 4-quadrant arctangent.
 */
int32_t _IQ28atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 28);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ27 input
 *        and return the result, in radians.
 *
 * @param y               IQ27 type input y.
 * @param x               IQ27 type input x.
 *
 * @return                IQ27 type result of 4-quadrant arctangent.
 */
int32_t _IQ27atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 27);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ26 input
 *        and return the result, in radians.
 *
 * @param y               IQ26 type input y.
 * @param x               IQ26 type input x.
 *
 * @return                IQ26 type result of 4-quadrant arctangent.
 */
int32_t _IQ26atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 26);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ25 input
 *        and return the result, in radians.
 *
 * @param y               IQ25 type input y.
 * @param x               IQ25 type input x.
 *
 * @return                IQ25 type result of 4-quadrant arctangent.
 */
int32_t _IQ25atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 25);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ24 input
 *        and return the result, in radians.
 *
 * @param y               IQ24 type input y.
 * @param x               IQ24 type input x.
 *
 * @return                IQ24 type result of 4-quadrant arctangent.
 */
int32_t _IQ24atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 24);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ23 input
 *        and return the result, in radians.
 *
 * @param y               IQ23 type input y.
 * @param x               IQ23 type input x.
 *
 * @return                IQ23 type result of 4-quadrant arctangent.
 */
int32_t _IQ23atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 23);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ22 input
 *        and return the result, in radians.
 *
 * @param y               IQ22 type input y.
 * @param x               IQ22 type input x.
 *
 * @return                IQ22 type result of 4-quadrant arctangent.
 */
int32_t _IQ22atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 22);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ21 input
 *        and return the result, in radians.
 *
 * @param y               IQ21 type input y.
 * @param x               IQ21 type input x.
 *
 * @return                IQ21 type result of 4-quadrant arctangent.
 */
int32_t _IQ21atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 21);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ20 input
 *        and return the result, in radians.
 *
 * @param y               IQ20 type input y.
 * @param x               IQ20 type input x.
 *
 * @return                IQ20 type result of 4-quadrant arctangent.
 */
int32_t _IQ20atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 20);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ19 input
 *        and return the result, in radians.
 *
 * @param y               IQ19 type input y.
 * @param x               IQ19 type input x.
 *
 * @return                IQ19 type result of 4-quadrant arctangent.
 */
int32_t _IQ19atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 19);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ18 input
 *        and return the result, in radians.
 *
 * @param y               IQ18 type input y.
 * @param x               IQ18 type input x.
 *
 * @return                IQ18 type result of 4-quadrant arctangent.
 */
int32_t _IQ18atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 18);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ17 input
 *        and return the result, in radians.
 *
 * @param y               IQ17 type input y.
 * @param x               IQ17 type input x.
 *
 * @return                IQ17 type result of 4-quadrant arctangent.
 */
int32_t _IQ17atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 17);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ16 input
 *        and return the result, in radians.
 *
 * @param y               IQ16 type input y.
 * @param x               IQ16 type input x.
 *
 * @return                IQ16 type result of 4-quadrant arctangent.
 */
int32_t _IQ16atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 16);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ15 input
 *        and return the result, in radians.
 *
 * @param y               IQ15 type input y.
 * @param x               IQ15 type input x.
 *
 * @return                IQ15 type result of 4-quadrant arctangent.
 */
int32_t _IQ15atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 15);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ14 input
 *        and return the result, in radians.
 *
 * @param y               IQ14 type input y.
 * @param x               IQ14 type input x.
 *
 * @return                IQ14 type result of 4-quadrant arctangent.
 */
int32_t _IQ14atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 14);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ13 input
 *        and return the result, in radians.
 *
 * @param y               IQ13 type input y.
 * @param x               IQ13 type input x.
 *
 * @return                IQ13 type result of 4-quadrant arctangent.
 */
int32_t _IQ13atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 13);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ12 input
 *        and return the result, in radians.
 *
 * @param y               IQ12 type input y.
 * @param x               IQ12 type input x.
 *
 * @return                IQ12 type result of 4-quadrant arctangent.
 */
int32_t _IQ12atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 12);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ11 input
 *        and return the result, in radians.
 *
 * @param y               IQ11 type input y.
 * @param x               IQ11 type input x.
 *
 * @return                IQ11 type result of 4-quadrant arctangent.
 */
int32_t _IQ11atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 11);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ10 input
 *        and return the result, in radians.
 *
 * @param y               IQ10 type input y.
 * @param x               IQ10 type input x.
 *
 * @return                IQ10 type result of 4-quadrant arctangent.
 */
int32_t _IQ10atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 10);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ9 input
 *        and return the result, in radians.
 *
 * @param y               IQ9 type input y.
 * @param x               IQ9 type input x.
 *
 * @return                IQ9 type result of 4-quadrant arctangent.
 */
int32_t _IQ9atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 9);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ8 input
 *        and return the result, in radians.
 *
 * @param y               IQ8 type input y.
 * @param x               IQ8 type input x.
 *
 * @return                IQ8 type result of 4-quadrant arctangent.
 */
int32_t _IQ8atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 8);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ7 input
 *        and return the result, in radians.
 *
 * @param y               IQ7 type input y.
 * @param x               IQ7 type input x.
 *
 * @return                IQ7 type result of 4-quadrant arctangent.
 */
int32_t _IQ7atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 7);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ6 input
 *        and return the result, in radians.
 *
 * @param y               IQ6 type input y.
 * @param x               IQ6 type input x.
 *
 * @return                IQ6 type result of 4-quadrant arctangent.
 */
int32_t _IQ6atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 6);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ5 input
 *        and return the result, in radians.
 *
 * @param y               IQ5 type input y.
 * @param x               IQ5 type input x.
 *
 * @return                IQ5 type result of 4-quadrant arctangent.
 */
int32_t _IQ5atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 5);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ4 input
 *        and return the result, in radians.
 *
 * @param y               IQ4 type input y.
 * @param x               IQ4 type input x.
 *
 * @return                IQ4 type result of 4-quadrant arctangent.
 */
int32_t _IQ4atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 4);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ3 input
 *        and return the result, in radians.
 *
 * @param y               IQ3 type input y.
 * @param x               IQ3 type input x.
 *
 * @return                IQ3 type result of 4-quadrant arctangent.
 */
int32_t _IQ3atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 3);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ2 input
 *        and return the result, in radians.
 *
 * @param y               IQ2 type input y.
 * @param x               IQ2 type input x.
 *
 * @return                IQ2 type result of 4-quadrant arctangent.
 */
int32_t _IQ2atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 2);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ1 input
 *        and return the result, in radians.
 *
 * @param y               IQ1 type input y.
 * @param x               IQ1 type input x.
 *
 * @return                IQ1 type result of 4-quadrant arctangent.
 */
int32_t _IQ1atan2(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_RAD, 1);
}

/* ATAN2PU */
/**
 * @brief Compute the 4-quadrant arctangent of the IQ31 input
 *        and return the result.
 *
 * @param y               IQ31 type input y.
 * @param x               IQ31 type input x.
 *
 * @return                IQ31 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ31atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 31);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ30 input
 *        and return the result.
 *
 * @param y               IQ30 type input y.
 * @param x               IQ30 type input x.
 *
 * @return                IQ30 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ30atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 30);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ29 input
 *        and return the result.
 *
 * @param y               IQ29 type input y.
 * @param x               IQ29 type input x.
 *
 * @return                IQ29 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ29atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 29);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ28 input
 *        and return the result.
 *
 * @param y               IQ28 type input y.
 * @param x               IQ28 type input x.
 *
 * @return                IQ28 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ28atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 28);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ27 input
 *        and return the result.
 *
 * @param y               IQ27 type input y.
 * @param x               IQ27 type input x.
 *
 * @return                IQ27 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ27atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 27);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ26 input
 *        and return the result.
 *
 * @param y               IQ26 type input y.
 * @param x               IQ26 type input x.
 *
 * @return                IQ26 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ26atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 26);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ25 input
 *        and return the result.
 *
 * @param y               IQ25 type input y.
 * @param x               IQ25 type input x.
 *
 * @return                IQ25 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ25atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 25);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ24 input
 *        and return the result.
 *
 * @param y               IQ24 type input y.
 * @param x               IQ24 type input x.
 *
 * @return                IQ24 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ24atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 24);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ23 input
 *        and return the result.
 *
 * @param y               IQ23 type input y.
 * @param x               IQ23 type input x.
 *
 * @return                IQ23 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ23atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 23);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ22 input
 *        and return the result.
 *
 * @param y               IQ22 type input y.
 * @param x               IQ22 type input x.
 *
 * @return                IQ22 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ22atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 22);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ21 input
 *        and return the result.
 *
 * @param y               IQ21 type input y.
 * @param x               IQ21 type input x.
 *
 * @return                IQ21 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ21atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 21);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ20 input
 *        and return the result.
 *
 * @param y               IQ20 type input y.
 * @param x               IQ20 type input x.
 *
 * @return                IQ20 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ20atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 20);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ19 input
 *        and return the result.
 *
 * @param y               IQ19 type input y.
 * @param x               IQ19 type input x.
 *
 * @return                IQ19 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ19atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 19);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ18 input
 *        and return the result.
 *
 * @param y               IQ18 type input y.
 * @param x               IQ18 type input x.
 *
 * @return                IQ18 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ18atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 18);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ17 input
 *        and return the result.
 *
 * @param y               IQ17 type input y.
 * @param x               IQ17 type input x.
 *
 * @return                IQ17 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ17atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 17);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ16 input
 *        and return the result.
 *
 * @param y               IQ16 type input y.
 * @param x               IQ16 type input x.
 *
 * @return                IQ16 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ16atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 16);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ15 input
 *        and return the result.
 *
 * @param y               IQ15 type input y.
 * @param x               IQ15 type input x.
 *
 * @return                IQ15 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ15atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 15);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ14 input
 *        and return the result.
 *
 * @param y               IQ14 type input y.
 * @param x               IQ14 type input x.
 *
 * @return                IQ14 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ14atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 14);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ13 input
 *        and return the result.
 *
 * @param y               IQ13 type input y.
 * @param x               IQ13 type input x.
 *
 * @return                IQ13 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ13atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 13);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ12 input
 *        and return the result.
 *
 * @param y               IQ12 type input y.
 * @param x               IQ12 type input x.
 *
 * @return                IQ12 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ12atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 12);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ11 input
 *        and return the result.
 *
 * @param y               IQ11 type input y.
 * @param x               IQ11 type input x.
 *
 * @return                IQ11 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ11atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 11);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ10 input
 *        and return the result.
 *
 * @param y               IQ10 type input y.
 * @param x               IQ10 type input x.
 *
 * @return                IQ10 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ10atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 10);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ9 input
 *        and return the result.
 *
 * @param y               IQ9 type input y.
 * @param x               IQ9 type input x.
 *
 * @return                IQ9 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ9atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 9);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ8 input
 *        and return the result.
 *
 * @param y               IQ8 type input y.
 * @param x               IQ8 type input x.
 *
 * @return                IQ8 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ8atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 8);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ7 input
 *        and return the result.
 *
 * @param y               IQ7 type input y.
 * @param x               IQ7 type input x.
 *
 * @return                IQ7 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ7atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 7);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ6 input
 *        and return the result.
 *
 * @param y               IQ6 type input y.
 * @param x               IQ6 type input x.
 *
 * @return                IQ6 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ6atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 6);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ5 input
 *        and return the result.
 *
 * @param y               IQ5 type input y.
 * @param x               IQ5 type input x.
 *
 * @return                IQ5 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ5atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 5);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ4 input
 *        and return the result.
 *
 * @param y               IQ4 type input y.
 * @param x               IQ4 type input x.
 *
 * @return                IQ4 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ4atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 4);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ3 input
 *        and return the result.
 *
 * @param y               IQ3 type input y.
 * @param x               IQ3 type input x.
 *
 * @return                IQ3 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ3atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 3);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ2 input
 *        and return the result.
 *
 * @param y               IQ2 type input y.
 * @param x               IQ2 type input x.
 *
 * @return                IQ2 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ2atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 2);
}
/**
 * @brief Compute the 4-quadrant arctangent of the IQ1 input
 *        and return the result.
 *
 * @param y               IQ1 type input y.
 * @param x               IQ1 type input x.
 *
 * @return                IQ1 type per-unit result of 4-quadrant arctangent.
 */
int32_t _IQ1atan2PU(int32_t y, int32_t x) {
    return __IQNatan2(y, x, TYPEATAN2_PU, 1);
}

//***********************************************************//

//***********************************************************//
/* RTS SQRT */
/**
 * @brief Calculate square root of an IQ31 input.
 *
 * @param a                 IQ31 type input.
 *
 * @return                  IQ31 type result of the square root operation.
 */

int32_t _IQ31sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 31, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ30 input.
 *
 * @param a                 IQ30 type input.
 *
 * @return                  IQ30 type result of the square root operation.
 */
int32_t _IQ30sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 30, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ29 input.
 *
 * @param a                 IQ29 type input.
 *
 * @return                  IQ29 type result of the square root operation.
 */
int32_t _IQ29sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 29, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ28 input.
 *
 * @param a                 IQ28 type input.
 *
 * @return                  IQ28 type result of the square root operation.
 */
int32_t _IQ28sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 28, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ27 input.
 *
 * @param a                 IQ27 type input.
 *
 * @return                  IQ27 type result of the square root operation.
 */
int32_t _IQ27sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 27, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ26 input.
 *
 * @param a                 IQ26 type input.
 *
 * @return                  IQ26 type result of the square root operation.
 */
int32_t _IQ26sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 26, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ25 input.
 *
 * @param a                 IQ25 type input.
 *
 * @return                  IQ25 type result of the square root operation.
 */
int32_t _IQ25sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 25, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ24 input.
 *
 * @param a                 IQ24 type input.
 *
 * @return                  IQ24 type result of the square root operation.
 */
int32_t _IQ24sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 24, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ23 input.
 *
 * @param a                 IQ23 type input.
 *
 * @return                  IQ23 type result of the square root operation.
 */
int32_t _IQ23sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 23, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ22 input.
 *
 * @param a                 IQ22 type input.
 *
 * @return                  IQ22 type result of the square root operation.
 */
int32_t _IQ22sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 22, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ21 input.
 *
 * @param a                 IQ21 type input.
 *
 * @return                  IQ21 type result of the square root operation.
 */
int32_t _IQ21sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 21, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ20 input.
 *
 * @param a                 IQ20 type input.
 *
 * @return                  IQ20 type result of the square root operation.
 */
int32_t _IQ20sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 20, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ19 input.
 *
 * @param a                 IQ19 type input.
 *
 * @return                  IQ19 type result of the square root operation.
 */
int32_t _IQ19sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 19, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ18 input.
 *
 * @param a                 IQ18 type input.
 *
 * @return                  IQ18 type result of the square root operation.
 */
int32_t _IQ18sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 18, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ17 input.
 *
 * @param a                 IQ17 type input.
 *
 * @return                  IQ17 type result of the square root operation.
 */
int32_t _IQ17sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 17, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ16 input.
 *
 * @param a                 IQ16 type input.
 *
 * @return                  IQ16 type result of the square root operation.
 */
int32_t _IQ16sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 16, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ15 input.
 *
 * @param a                 IQ15 type input.
 *
 * @return                  IQ15 type result of the square root operation.
 */
int32_t _IQ15sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 15, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ14 input.
 *
 * @param a                 IQ14 type input.
 *
 * @return                  IQ14 type result of the square root operation.
 */
int32_t _IQ14sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 14, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ13 input.
 *
 * @param a                 IQ13 type input.
 *
 * @return                  IQ13 type result of the square root operation.
 */
int32_t _IQ13sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 13, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ12 input.
 *
 * @param a                 IQ12 type input.
 *
 * @return                  IQ12 type result of the square root operation.
 */
int32_t _IQ12sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 12, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ11 input.
 *
 * @param a                 IQ11 type input.
 *
 * @return                  IQ11 type result of the square root operation.
 */
int32_t _IQ11sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 11, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ10 input.
 *
 * @param a                 IQ10 type input.
 *
 * @return                  IQ10 type result of the square root operation.
 */
int32_t _IQ10sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 10, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ9 input.
 *
 * @param a                 IQ9 type input.
 *
 * @return                  IQ9 type result of the square root operation.
 */
int32_t _IQ9sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 9, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ8 input.
 *
 * @param a                 IQ8 type input.
 *
 * @return                  IQ8 type result of the square root operation.
 */
int32_t _IQ8sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 8, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ7 input.
 *
 * @param a                 IQ7 type input.
 *
 * @return                  IQ7 type result of the square root operation.
 */
int32_t _IQ7sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 7, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ6 input.
 *
 * @param a                 IQ6 type input.
 *
 * @return                  IQ6 type result of the square root operation.
 */
int32_t _IQ6sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 6, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ5 input.
 *
 * @param a                 IQ5 type input.
 *
 * @return                  IQ5 type result of the square root operation.
 */
int32_t _IQ5sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 5, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ4 input.
 *
 * @param a                 IQ4 type input.
 *
 * @return                  IQ4 type result of the square root operation.
 */
int32_t _IQ4sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 4, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ3 input.
 *
 * @param a                 IQ3 type input.
 *
 * @return                  IQ3 type result of the square root operation.
 */
int32_t _IQ3sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 3, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ2 input.
 *
 * @param a                 IQ2 type input.
 *
 * @return                  IQ2 type result of the square root operation.
 */
int32_t _IQ2sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 2, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ1 input.
 *
 * @param a                 IQ1 type input.
 *
 * @return                  IQ1 type result of the square root operation.
 */
int32_t _IQ1sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 1, TYPE_SQRT);
}
/**
 * @brief Calculate square root of an IQ0 input.
 *
 * @param a                 IQ0 type input.
 *
 * @return                  IQ0 type result of the square root operation.
 */
int32_t _IQ0sqrt(int32_t a) {
    return __IQNsqrt(a, 0, 0, TYPE_SQRT);
}
/**
 * @brief Calculate magnitude of an IQ30 input.
 *
 * @param a                 IQ30 type input.
 *
 * @return                  IQ30 type result of the magnitude operation.
 */
int32_t _IQ30mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 30, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ29 input.
 *
 * @param a                 IQ29 type input.
 *
 * @return                  IQ29 type result of magnitude operation.
 */
int32_t _IQ29mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 29, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ28 input.
 *
 * @param a                 IQ28 type input.
 *
 * @return                  IQ28 type result of the magnitude operation.
 */
int32_t _IQ28mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 28, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ27 input.
 *
 * @param a                 IQ27 type input.
 *
 * @return                  IQ27 type result of the magnitude operation.
 */
int32_t _IQ27mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 27, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ26 input.
 *
 * @param a                 IQ26 type input.
 *
 * @return                  IQ26 type result of the magnitude operation.
 */
int32_t _IQ26mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 26, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ25 input.
 *
 * @param a                 IQ25 type input.
 *
 * @return                  IQ25 type result of the magnitude operation.
 */
int32_t _IQ25mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 25, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ24 input.
 *
 * @param a                 IQ24 type input.
 *
 * @return                  IQ24 type result of the magnitude operation.
 */
int32_t _IQ24mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 24, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ23 input.
 *
 * @param a                 IQ23 type input.
 *
 * @return                  IQ23 type result of the magnitude operation.
 */
int32_t _IQ23mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 23, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ22 input.
 *
 * @param a                 IQ22 type input.
 *
 * @return                  IQ22 type result of the magnitude operation.
 */
int32_t _IQ22mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 22, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ21 input.
 *
 * @param a                 IQ21 type input.
 *
 * @return                  IQ21 type result of the magnitude operation.
 */
int32_t _IQ21mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 21, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ20 input.
 *
 * @param a                 IQ20 type input.
 *
 * @return                  IQ20 type result of the magnitude operation.
 */
int32_t _IQ20mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 20, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ19 input.
 *
 * @param a                 IQ19 type input.
 *
 * @return                  IQ19 type result of the magnitude operation.
 */
int32_t _IQ19mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 19, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ18 input.
 *
 * @param a                 IQ18 type input.
 *
 * @return                  IQ18 type result of the magnitude operation.
 */
int32_t _IQ18mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 18, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ17 input.
 *
 * @param a                 IQ17 type input.
 *
 * @return                  IQ17 type result of the magnitude operation.
 */
int32_t _IQ17mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 17, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ16 input.
 *
 * @param a                 IQ16 type input.
 *
 * @return                  IQ16 type result of the magnitude operation.
 */
int32_t _IQ16mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 16, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ15 input.
 *
 * @param a                 IQ15 type input.
 *
 * @return                  IQ15 type result of the magnitude operation.
 */
int32_t _IQ15mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 15, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ14 input.
 *
 * @param a                 IQ14 type input.
 *
 * @return                  IQ14 type result of the magnitude operation.
 */
int32_t _IQ14mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 14, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ13 input.
 *
 * @param a                 IQ13 type input.
 *
 * @return                  IQ13 type result of the magnitude operation.
 */
int32_t _IQ13mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 13, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ12 input.
 *
 * @param a                 IQ12 type input.
 *
 * @return                  IQ12 type result of the magnitude operation.
 */
int32_t _IQ12mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 12, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ11 input.
 *
 * @param a                 IQ11 type input.
 *
 * @return                  IQ11 type result of the magnitude operation.
 */
int32_t _IQ11mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 11, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ10 input.
 *
 * @param a                 IQ10 type input.
 *
 * @return                  IQ10 type result of the magnitude operation.
 */
int32_t _IQ10mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 10, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ9 input.
 *
 * @param a                 IQ9 type input.
 *
 * @return                  IQ9 type result of the magnitude operation.
 */
int32_t _IQ9mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 9, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ8 input.
 *
 * @param a                 IQ8 type input.
 *
 * @return                  IQ8 type result of the magnitude operation.
 */
int32_t _IQ8mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 8, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ7 input.
 *
 * @param a                 IQ7 type input.
 *
 * @return                  IQ7 type result of the magnitude operation.
 */
int32_t _IQ7mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 7, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ6 input.
 *
 * @param a                 IQ6 type input.
 *
 * @return                  IQ6 type result of the magnitude operation.
 */
int32_t _IQ6mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 6, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ5 input.
 *
 * @param a                 IQ5 type input.
 *
 * @return                  IQ5 type result of the magnitude operation.
 */
int32_t _IQ5mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 5, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ4 input.
 *
 * @param a                 IQ4 type input.
 *
 * @return                  IQ4 type result of the magnitude operation.
 */
int32_t _IQ4mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 4, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ3 input.
 *
 * @param a                 IQ3 type input.
 *
 * @return                  IQ3 type result of the magnitude operation.
 */
int32_t _IQ3mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 3, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ2 input.
 *
 * @param a                 IQ2 type input.
 *
 * @return                  IQ2 type result of the magnitude operation.
 */
int32_t _IQ2mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 2, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ1 input.
 *
 * @param a                 IQ1 type input.
 *
 * @return                  IQ1 type result of the magnitude operation.
 */
int32_t _IQ1mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 1, TYPE_MAG);
}
/**
 * @brief Calculate magnitude of an IQ0 input.
 *
 * @param a                 IQ0 type input.
 *
 * @return                  IQ0 type result of the magnitude operation.
 */
int32_t _IQ0mag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 0, TYPE_MAG);
}
/* INVERSE SQRT */
/**
 * @brief Calculate inverse square root of an IQ30 input.
 *
 * @param a                 IQ30 type input.
 *
 * @return                  IQ30 type result of the inverse square root operation.
 */
int32_t _IQ30isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 30, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ29 input.
 *
 * @param a                 IQ29 type input.
 *
 * @return                  IQ29 type result of the inverse square root operation.
 */
int32_t _IQ29isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 29, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ28 input.
 *
 * @param a                 IQ28 type input.
 *
 * @return                  IQ28 type result of the inverse square root operation.
 */
int32_t _IQ28isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 28, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ27 input.
 *
 * @param a                 IQ27 type input.
 *
 * @return                  IQ27 type result of the inverse square root operation.
 */
int32_t _IQ27isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 27, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ26 input.
 *
 * @param a                 IQ26 type input.
 *
 * @return                  IQ26 type result of the inverse square root operation.
 */
int32_t _IQ26isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 26, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ25 input.
 *
 * @param a                 IQ25 type input.
 *
 * @return                  IQ25 type result of the inverse square root operation.
 */
int32_t _IQ25isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 25, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ24 input.
 *
 * @param a                 IQ24 type input.
 *
 * @return                  IQ24 type result of the inverse square root operation.
 */
int32_t _IQ24isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 24, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ23 input.
 *
 * @param a                 IQ23 type input.
 *
 * @return                  IQ23 type result of the inverse square root operation.
 */
int32_t _IQ23isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 23, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ22 input.
 *
 * @param a                 IQ22 type input.
 *
 * @return                  IQ22 type result of the inverse square root operation.
 */
int32_t _IQ22isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 22, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ21 input.
 *
 * @param a                 IQ21 type input.
 *
 * @return                  IQ21 type result of the inverse square root operation.
 */
int32_t _IQ21isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 21, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ20 input.
 *
 * @param a                 IQ20 type input.
 *
 * @return                  IQ20 type result of the inverse square root operation.
 */
int32_t _IQ20isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 20, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ19 input.
 *
 * @param a                 IQ19 type input.
 *
 * @return                  IQ19 type result of the inverse square root operation.
 */
int32_t _IQ19isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 19, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ18 input.
 *
 * @param a                 IQ18 type input.
 *
 * @return                  IQ18 type result of the inverse square root operation.
 */
int32_t _IQ18isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 18, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ17 input.
 *
 * @param a                 IQ17 type input.
 *
 * @return                  IQ17 type result of the inverse square root operation.
 */
int32_t _IQ17isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 17, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ16 input.
 *
 * @param a                 IQ16 type input.
 *
 * @return                  IQ16 type result of the inverse square root operation.
 */
int32_t _IQ16isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 16, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ15 input.
 *
 * @param a                 IQ15 type input.
 *
 * @return                  IQ15 type result of the inverse square root operation.
 */
int32_t _IQ15isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 15, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ14 input.
 *
 * @param a                 IQ14 type input.
 *
 * @return                  IQ14 type result of the inverse square root operation.
 */
int32_t _IQ14isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 14, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ13 input.
 *
 * @param a                 IQ13 type input.
 *
 * @return                  IQ13 type result of the inverse square root operation.
 */
int32_t _IQ13isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 13, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ12 input.
 *
 * @param a                 IQ12 type input.
 *
 * @return                  IQ12 type result of the inverse square root operation.
 */
int32_t _IQ12isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 12, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ11 input.
 *
 * @param a                 IQ11 type input.
 *
 * @return                  IQ11 type result of the inverse square root operation.
 */
int32_t _IQ11isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 11, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ10 input.
 *
 * @param a                 IQ10 type input.
 *
 * @return                  IQ10 type result of the inverse square root operation.
 */
int32_t _IQ10isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 10, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ9 input.
 *
 * @param a                 IQ9 type input.
 *
 * @return                  IQ9 type result of the inverse square root operation.
 */
int32_t _IQ9isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 9, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ8 input.
 *
 * @param a                 IQ8 type input.
 *
 * @return                  IQ8 type result of the inverse square root operation.
 */
int32_t _IQ8isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 8, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ7 input.
 *
 * @param a                 IQ7 type input.
 *
 * @return                  IQ7 type result of the inverse square root operation.
 */
int32_t _IQ7isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 7, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ6 input.
 *
 * @param a                 IQ6 type input.
 *
 * @return                  IQ6 type result of the inverse square root operation.
 */
int32_t _IQ6isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 6, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ5 input.
 *
 * @param a                 IQ5 type input.
 *
 * @return                  IQ5 type result of the inverse square root operation.
 */
int32_t _IQ5isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 5, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ4 input.
 *
 * @param a                 IQ4 type input.
 *
 * @return                  IQ4 type result of the inverse square root operation.
 */
int32_t _IQ4isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 4, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ3 input.
 *
 * @param a                 IQ3 type input.
 *
 * @return                  IQ3 type result of the inverse square root operation.
 */
int32_t _IQ3isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 3, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ2 input.
 *
 * @param a                 IQ2 type input.
 *
 * @return                  IQ2 type result of the inverse square root operation.
 */
int32_t _IQ2isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 2, TYPE_ISQRT);
}
/**
 * @brief Calculate inverse square root of an IQ1 input.
 *
 * @param a                 IQ1 type input.
 *
 * @return                  IQ1 type result of the inverse square root operation.
 */
int32_t _IQ1isqrt(int32_t a) {
    return __IQNsqrt(a, 0, 1, TYPE_ISQRT);
}

/* MAGNITUDE */
/* INVERSE MAGNITUDE */
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ30 type input.
 * @param b                 IQ30 type input.
 *
 * @return                  IQ30 type result of the inverse magnitude operation.
 */
int32_t _IQ30imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 30, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ29 type input.
 * @param b                 IQ29 type input.
 *
 * @return                  IQ29 type result of the inverse magnitude operation.
 */
int32_t _IQ29imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 29, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ28 type input.
 * @param b                 IQ28 type input.
 *
 * @return                  IQ28 type result of the inverse magnitude operation.
 */
int32_t _IQ28imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 28, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ27 type input.
 * @param b                 IQ27 type input.
 *
 * @return                  IQ27 type result of the inverse magnitude operation.
 */
int32_t _IQ27imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 27, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ26 type input.
 * @param b                 IQ26 type input.
 *
 * @return                  IQ26 type result of the inverse magnitude operation.
 */
int32_t _IQ26imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 26, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ25 type input.
 * @param b                 IQ25 type input.
 *
 * @return                  IQ25 type result of the inverse magnitude operation.
 */
int32_t _IQ25imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 25, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ24 type input.
 * @param b                 IQ24 type input.
 *
 * @return                  IQ24 type result of the inverse magnitude operation.
 */
int32_t _IQ24imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 24, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ23 type input.
 * @param b                 IQ23 type input.
 *
 * @return                  IQ23 type result of the inverse magnitude operation.
 */
int32_t _IQ23imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 23, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ22 type input.
 * @param b                 IQ22 type input.
 *
 * @return                  IQ22 type result of the inverse magnitude operation.
 */
int32_t _IQ22imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 22, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ21 type input.
 * @param b                 IQ21 type input.
 *
 * @return                  IQ21 type result of the inverse magnitude operation.
 */
int32_t _IQ21imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 21, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ20 type input.
 * @param b                 IQ20 type input.
 *
 * @return                  IQ20 type result of the inverse magnitude operation.
 */
int32_t _IQ20imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 20, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ19 type input.
 * @param b                 IQ19 type input.
 *
 * @return                  IQ19 type result of the inverse magnitude operation.
 */
int32_t _IQ19imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 19, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ18 type input.
 * @param b                 IQ18 type input.
 *
 * @return                  IQ18 type result of the inverse magnitude operation.
 */
int32_t _IQ18imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 18, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ17 type input.
 * @param b                 IQ17 type input.
 *
 * @return                  IQ17 type result of the inverse magnitude operation.
 */
int32_t _IQ17imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 17, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ16 type input.
 * @param b                 IQ16 type input.
 *
 * @return                  IQ16 type result of the inverse magnitude operation.
 */
int32_t _IQ16imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 16, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ15 type input.
 * @param b                 IQ15 type input.
 *
 * @return                  IQ15 type result of the inverse magnitude operation.
 */
int32_t _IQ15imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 15, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ14 type input.
 * @param b                 IQ14 type input.
 *
 * @return                  IQ14 type result of the inverse magnitude operation.
 */
int32_t _IQ14imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 14, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ13 type input.
 * @param b                 IQ13 type input.
 *
 * @return                  IQ13 type result of the inverse magnitude operation.
 */
int32_t _IQ13imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 13, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ12 type input.
 * @param b                 IQ12 type input.
 *
 * @return                  IQ12 type result of the inverse magnitude operation.
 */
int32_t _IQ12imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 12, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ11 type input.
 * @param b                 IQ11 type input.
 *
 * @return                  IQ11 type result of the inverse magnitude operation.
 */
int32_t _IQ11imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 11, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ10 type input.
 * @param b                 IQ10 type input.
 *
 * @return                  IQ10 type result of the inverse magnitude operation.
 */
int32_t _IQ10imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 10, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ9 type input.
 * @param b                 IQ9 type input.
 *
 * @return                  IQ9 type result of the inverse magnitude operation.
 */
int32_t _IQ9imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 9, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ8 type input.
 * @param b                 IQ8 type input.
 *
 * @return                  IQ8 type result of the inverse magnitude operation.
 */
int32_t _IQ8imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 8, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ7 type input.
 * @param b                 IQ7 type input.
 *
 * @return                  IQ7 type result of the inverse magnitude operation.
 */
int32_t _IQ7imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 7, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ6 type input.
 * @param b                 IQ6 type input.
 *
 * @return                  IQ6 type result of the inverse magnitude operation.
 */
int32_t _IQ6imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 6, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ5 type input.
 * @param b                 IQ5 type input.
 *
 * @return                  IQ5 type result of the inverse magnitude operation.
 */
int32_t _IQ5imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 5, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ4 type input.
 * @param b                 IQ4 type input.
 *
 * @return                  IQ4 type result of the inverse magnitude operation.
 */
int32_t _IQ4imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 4, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ3 type input.
 * @param b                 IQ3 type input.
 *
 * @return                  IQ3 type result of the inverse magnitude operation.
 */
int32_t _IQ3imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 3, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ2 type input.
 * @param b                 IQ2 type input.
 *
 * @return                  IQ2 type result of the inverse magnitude operation.
 */
int32_t _IQ2imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 2, TYPE_IMAG);
}
/**
 * @brief Calculate inverse magnitude of two inputs.
 *
 * @param a                 IQ1 type input.
 * @param b                 IQ1 type input.
 *
 * @return                  IQ1 type result of the inverse magnitude operation.
 */
int32_t _IQ1imag(int32_t a, int32_t b) {
    return __IQNsqrt(a, b, 1, TYPE_IMAG);
}
//***********************************************************//

//***********************************************************//
/**
 * @brief Computes the exponential of an IQ30 input.
 *
 * @param a               IQ30 type input.
 *
 * @return                IQ30 type result of exponential.
 */
int32_t _IQ30exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup30, _IQNexp_offset[30 - 1], _IQNexp_min[30 - 1], _IQNexp_max[30 - 1], 30);
}
/**
 * @brief Computes the exponential of an IQ29 input.
 *
 * @param a               IQ29 type input.
 *
 * @return                IQ29 type result of exponential.
 */
int32_t _IQ29exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup29, _IQNexp_offset[29 - 1], _IQNexp_min[29 - 1], _IQNexp_max[29 - 1], 29);
}
/**
 * @brief Computes the exponential of an IQ28 input.
 *
 * @param a               IQ28 type input.
 *
 * @return                IQ28 type result of exponential.
 */
int32_t _IQ28exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup28, _IQNexp_offset[28 - 1], _IQNexp_min[28 - 1], _IQNexp_max[28 - 1], 28);
}
/**
 * @brief Computes the exponential of an IQ27 input.
 *
 * @param a               IQ27 type input.
 *
 * @return                IQ27 type result of exponential.
 */
int32_t _IQ27exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup27, _IQNexp_offset[27 - 1], _IQNexp_min[27 - 1], _IQNexp_max[27 - 1], 27);
}
/**
 * @brief Computes the exponential of an IQ26 input.
 *
 * @param a               IQ26 type input.
 *
 * @return                IQ26 type result of exponential.
 */
int32_t _IQ26exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup26, _IQNexp_offset[26 - 1], _IQNexp_min[26 - 1], _IQNexp_max[26 - 1], 26);
}
/**
 * @brief Computes the exponential of an IQ25 input.
 *
 * @param a               IQ25 type input.
 *
 * @return                IQ25 type result of exponential.
 */
int32_t _IQ25exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup25, _IQNexp_offset[25 - 1], _IQNexp_min[25 - 1], _IQNexp_max[25 - 1], 25);
}
/**
 * @brief Computes the exponential of an IQ24 input.
 *
 * @param a               IQ24 type input.
 *
 * @return                IQ24 type result of exponential.
 */
int32_t _IQ24exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup24, _IQNexp_offset[24 - 1], _IQNexp_min[24 - 1], _IQNexp_max[24 - 1], 24);
}
/**
 * @brief Computes the exponential of an IQ23 input.
 *
 * @param a               IQ23 type input.
 *
 * @return                IQ23 type result of exponential.
 */
int32_t _IQ23exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup23, _IQNexp_offset[23 - 1], _IQNexp_min[23 - 1], _IQNexp_max[23 - 1], 23);
}
/**
 * @brief Computes the exponential of an IQ22 input.
 *
 * @param a               IQ22 type input.
 *
 * @return                IQ22 type result of exponential.
 */
int32_t _IQ22exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup22, _IQNexp_offset[22 - 1], _IQNexp_min[22 - 1], _IQNexp_max[22 - 1], 22);
}
/**
 * @brief Computes the exponential of an IQ21 input.
 *
 * @param a               IQ21 type input.
 *
 * @return                IQ21 type result of exponential.
 */
int32_t _IQ21exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup21, _IQNexp_offset[21 - 1], _IQNexp_min[21 - 1], _IQNexp_max[21 - 1], 21);
}
/**
 * @brief Computes the exponential of an IQ20 input.
 *
 * @param a               IQ20 type input.
 *
 * @return                IQ20 type result of exponential.
 */
int32_t _IQ20exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup20, _IQNexp_offset[20 - 1], _IQNexp_min[20 - 1], _IQNexp_max[20 - 1], 20);
}
/**
 * @brief Computes the exponential of an IQ19 input.
 *
 * @param a               IQ19 type input.
 *
 * @return                IQ19 type result of exponential.
 */
int32_t _IQ19exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup19, _IQNexp_offset[19 - 1], _IQNexp_min[19 - 1], _IQNexp_max[19 - 1], 19);
}
/**
 * @brief Computes the exponential of an IQ18 input.
 *
 * @param a               IQ18 type input.
 *
 * @return                IQ18 type result of exponential.
 */
int32_t _IQ18exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup18, _IQNexp_offset[18 - 1], _IQNexp_min[18 - 1], _IQNexp_max[18 - 1], 18);
}
/**
 * @brief Computes the exponential of an IQ17 input.
 *
 * @param a               IQ17 type input.
 *
 * @return                IQ17 type result of exponential.
 */
int32_t _IQ17exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup17, _IQNexp_offset[17 - 1], _IQNexp_min[17 - 1], _IQNexp_max[17 - 1], 17);
}
/**
 * @brief Computes the exponential of an IQ16 input.
 *
 * @param a               IQ16 type input.
 *
 * @return                IQ16 type result of exponential.
 */
int32_t _IQ16exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup16, _IQNexp_offset[16 - 1], _IQNexp_min[16 - 1], _IQNexp_max[16 - 1], 16);
}
/**
 * @brief Computes the exponential of an IQ15 input.
 *
 * @param a               IQ15 type input.
 *
 * @return                IQ15 type result of exponential.
 */
int32_t _IQ15exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup15, _IQNexp_offset[15 - 1], _IQNexp_min[15 - 1], _IQNexp_max[15 - 1], 15);
}
/**
 * @brief Computes the exponential of an IQ14 input.
 *
 * @param a               IQ14 type input.
 *
 * @return                IQ14 type result of exponential.
 */
int32_t _IQ14exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup14, _IQNexp_offset[14 - 1], _IQNexp_min[14 - 1], _IQNexp_max[14 - 1], 14);
}
/**
 * @brief Computes the exponential of an IQ13 input.
 *
 * @param a               IQ13 type input.
 *
 * @return                IQ13 type result of exponential.
 */
int32_t _IQ13exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup13, _IQNexp_offset[13 - 1], _IQNexp_min[13 - 1], _IQNexp_max[13 - 1], 13);
}
/**
 * @brief Computes the exponential of an IQ12 input.
 *
 * @param a               IQ12 type input.
 *
 * @return                IQ12 type result of exponential.
 */
int32_t _IQ12exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup12, _IQNexp_offset[12 - 1], _IQNexp_min[12 - 1], _IQNexp_max[12 - 1], 12);
}
/**
 * @brief Computes the exponential of an IQ11 input.
 *
 * @param a               IQ11 type input.
 *
 * @return                IQ11 type result of exponential.
 */
int32_t _IQ11exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup11, _IQNexp_offset[11 - 1], _IQNexp_min[11 - 1], _IQNexp_max[11 - 1], 11);
}
/**
 * @brief Computes the exponential of an IQ10 input.
 *
 * @param a               IQ10 type input.
 *
 * @return                IQ10 type result of exponential.
 */
int32_t _IQ10exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup10, _IQNexp_offset[10 - 1], _IQNexp_min[10 - 1], _IQNexp_max[10 - 1], 10);
}
/**
 * @brief Computes the exponential of an IQ9 input.
 *
 * @param a               IQ9 type input.
 *
 * @return                IQ9 type result of exponential.
 */
int32_t _IQ9exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup9, _IQNexp_offset[9 - 1], _IQNexp_min[9 - 1], _IQNexp_max[9 - 1], 9);
}
/**
 * @brief Computes the exponential of an IQ8 input.
 *
 * @param a               IQ8 type input.
 *
 * @return                IQ8 type result of exponential.
 */
int32_t _IQ8exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup8, _IQNexp_offset[8 - 1], _IQNexp_min[8 - 1], _IQNexp_max[8 - 1], 8);
}
/**
 * @brief Computes the exponential of an IQ7 input.
 *
 * @param a               IQ7 type input.
 *
 * @return                IQ7 type result of exponential.
 */
int32_t _IQ7exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup7, _IQNexp_offset[7 - 1], _IQNexp_min[7 - 1], _IQNexp_max[7 - 1], 7);
}
/**
 * @brief Computes the exponential of an IQ6 input.
 *
 * @param a               IQ6 type input.
 *
 * @return                IQ6 type result of exponential.
 */
int32_t _IQ6exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup6, _IQNexp_offset[6 - 1], _IQNexp_min[6 - 1], _IQNexp_max[6 - 1], 6);
}
/**
 * @brief Computes the exponential of an IQ5 input.
 *
 * @param a               IQ5 type input.
 *
 * @return                IQ5 type result of exponential.
 */
int32_t _IQ5exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup5, _IQNexp_offset[5 - 1], _IQNexp_min[5 - 1], _IQNexp_max[5 - 1], 5);
}
/**
 * @brief Computes the exponential of an IQ4 input.
 *
 * @param a               IQ4 type input.
 *
 * @return                IQ4 type result of exponential.
 */
int32_t _IQ4exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup4, _IQNexp_offset[4 - 1], _IQNexp_min[4 - 1], _IQNexp_max[4 - 1], 4);
}
/**
 * @brief Computes the exponential of an IQ3 input.
 *
 * @param a               IQ3 type input.
 *
 * @return                IQ3 type result of exponential.
 */
int32_t _IQ3exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup3, _IQNexp_offset[3 - 1], _IQNexp_min[3 - 1], _IQNexp_max[3 - 1], 3);
}
/**
 * @brief Computes the exponential of an IQ2 input.
 *
 * @param a               IQ2 type input.
 *
 * @return                IQ2 type result of exponential.
 */
int32_t _IQ2exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup2, _IQNexp_offset[2 - 1], _IQNexp_min[2 - 1], _IQNexp_max[2 - 1], 2);
}
/**
 * @brief Computes the exponential of an IQ1 input.
 *
 * @param a               IQ1 type input.
 *
 * @return                IQ1 type result of exponential.
 */
int32_t _IQ1exp(int32_t a) {
    return __IQNexp(a, _IQNexp_lookup1, _IQNexp_offset[1 - 1], _IQNexp_min[1 - 1], _IQNexp_max[1 - 1], 1);
}

/**
 * @brief Computes the base-e logarithm of an IQ30 input.
 *
 * @param a                 IQ30 type input.
 *
 * @return                  IQ30 type result of exponential.
 */
int32_t _IQ30log(int32_t a) {
    return __IQNlog(a, _IQNlog_min[30 - 27], 30);
}
/**
 * @brief Computes the base-e logarithm of an IQ29 input.
 *
 * @param a                 IQ29 type input.
 *
 * @return                  IQ29 type result of exponential.
 */
int32_t _IQ29log(int32_t a) {
    return __IQNlog(a, _IQNlog_min[29 - 27], 29);
}
/**
 * @brief Computes the base-e logarithm of an IQ28 input.
 *
 * @param a                 IQ28 type input.
 *
 * @return                  IQ28 type result of exponential.
 */
int32_t _IQ28log(int32_t a) {
    return __IQNlog(a, _IQNlog_min[28 - 27], 28);
}
/**
 * @brief Computes the base-e logarithm of an IQ27 input.
 *
 * @param a                 IQ27 type input.
 *
 * @return                  IQ27 type result of exponential.
 */
int32_t _IQ27log(int32_t a) {
    return __IQNlog(a, _IQNlog_min[27 - 27], 27);
}
/**
 * @brief Computes the base-e logarithm of an IQ26 input.
 *
 * @param a                 IQ26 type input.
 *
 * @return                  IQ26 type result of exponential.
 */
int32_t _IQ26log(int32_t a) {
    return __IQNlog(a, 1, 26);
}
/**
 * @brief Computes the base-e logarithm of an IQ25 input.
 *
 * @param a                 IQ25 type input.
 *
 * @return                  IQ25 type result of exponential.
 */
int32_t _IQ25log(int32_t a) {
    return __IQNlog(a, 1, 25);
}
/**
 * @brief Computes the base-e logarithm of an IQ24 input.
 *
 * @param a                 IQ24 type input.
 *
 * @return                  IQ24 type result of exponential.
 */
int32_t _IQ24log(int32_t a) {
    return __IQNlog(a, 1, 24);
}
/**
 * @brief Computes the base-e logarithm of an IQ23 input.
 *
 * @param a                 IQ23 type input.
 *
 * @return                  IQ23 type result of exponential.
 */
int32_t _IQ23log(int32_t a) {
    return __IQNlog(a, 1, 23);
}
/**
 * @brief Computes the base-e logarithm of an IQ22 input.
 *
 * @param a                 IQ22 type input.
 *
 * @return                  IQ22 type result of exponential.
 */
int32_t _IQ22log(int32_t a) {
    return __IQNlog(a, 1, 22);
}
/**
 * @brief Computes the base-e logarithm of an IQ21 input.
 *
 * @param a                 IQ21 type input.
 *
 * @return                  IQ21 type result of exponential.
 */
int32_t _IQ21log(int32_t a) {
    return __IQNlog(a, 1, 21);
}
/**
 * @brief Computes the base-e logarithm of an IQ20 input.
 *
 * @param a                 IQ20 type input.
 *
 * @return                  IQ20 type result of exponential.
 */
int32_t _IQ20log(int32_t a) {
    return __IQNlog(a, 1, 20);
}
/**
 * @brief Computes the base-e logarithm of an IQ19 input.
 *
 * @param a                 IQ19 type input.
 *
 * @return                  IQ19 type result of exponential.
 */
int32_t _IQ19log(int32_t a) {
    return __IQNlog(a, 1, 19);
}
/**
 * @brief Computes the base-e logarithm of an IQ18 input.
 *
 * @param a                 IQ18 type input.
 *
 * @return                  IQ18 type result of exponential.
 */
int32_t _IQ18log(int32_t a) {
    return __IQNlog(a, 1, 18);
}
/**
 * @brief Computes the base-e logarithm of an IQ17 input.
 *
 * @param a                 IQ17 type input.
 *
 * @return                  IQ17 type result of exponential.
 */
int32_t _IQ17log(int32_t a) {
    return __IQNlog(a, 1, 17);
}
/**
 * @brief Computes the base-e logarithm of an IQ16 input.
 *
 * @param a                 IQ16 type input.
 *
 * @return                  IQ16 type result of exponential.
 */
int32_t _IQ16log(int32_t a) {
    return __IQNlog(a, 1, 16);
}
/**
 * @brief Computes the base-e logarithm of an IQ15 input.
 *
 * @param a                 IQ15 type input.
 *
 * @return                  IQ15 type result of exponential.
 */
int32_t _IQ15log(int32_t a) {
    return __IQNlog(a, 1, 15);
}
/**
 * @brief Computes the base-e logarithm of an IQ14 input.
 *
 * @param a                 IQ14 type input.
 *
 * @return                  IQ14 type result of exponential.
 */
int32_t _IQ14log(int32_t a) {
    return __IQNlog(a, 1, 14);
}
/**
 * @brief Computes the base-e logarithm of an IQ13 input.
 *
 * @param a                 IQ13 type input.
 *
 * @return                  IQ13 type result of exponential.
 */
int32_t _IQ13log(int32_t a) {
    return __IQNlog(a, 1, 13);
}
/**
 * @brief Computes the base-e logarithm of an IQ12 input.
 *
 * @param a                 IQ12 type input.
 *
 * @return                  IQ12 type result of exponential.
 */
int32_t _IQ12log(int32_t a) {
    return __IQNlog(a, 1, 12);
}
/**
 * @brief Computes the base-e logarithm of an IQ11 input.
 *
 * @param a                 IQ11 type input.
 *
 * @return                  IQ11 type result of exponential.
 */
int32_t _IQ11log(int32_t a) {
    return __IQNlog(a, 1, 11);
}
/**
 * @brief Computes the base-e logarithm of an IQ10 input.
 *
 * @param a                 IQ10 type input.
 *
 * @return                  IQ10 type result of exponential.
 */
int32_t _IQ10log(int32_t a) {
    return __IQNlog(a, 1, 10);
}
/**
 * @brief Computes the base-e logarithm of an IQ9 input.
 *
 * @param a                 IQ9 type input.
 *
 * @return                  IQ9 type result of exponential.
 */
int32_t _IQ9log(int32_t a) {
    return __IQNlog(a, 1, 9);
}
/**
 * @brief Computes the base-e logarithm of an IQ8 input.
 *
 * @param a                 IQ8 type input.
 *
 * @return                  IQ8 type result of exponential.
 */
int32_t _IQ8log(int32_t a) {
    return __IQNlog(a, 1, 8);
}
/**
 * @brief Computes the base-e logarithm of an IQ7 input.
 *
 * @param a                 IQ7 type input.
 *
 * @return                  IQ7 type result of exponential.
 */
int32_t _IQ7log(int32_t a) {
    return __IQNlog(a, 1, 7);
}
/**
 * @brief Computes the base-e logarithm of an IQ6 input.
 *
 * @param a                 IQ6 type input.
 *
 * @return                  IQ6 type result of exponential.
 */
int32_t _IQ6log(int32_t a) {
    return __IQNlog(a, 1, 6);
}
/**
 * @brief Computes the base-e logarithm of an IQ5 input.
 *
 * @param a                 IQ5 type input.
 *
 * @return                  IQ5 type result of exponential.
 */
int32_t _IQ5log(int32_t a) {
    return __IQNlog(a, 1, 5);
}
/**
 * @brief Computes the base-e logarithm of an IQ4 input.
 *
 * @param a                 IQ4 type input.
 *
 * @return                  IQ4 type result of exponential.
 */
int32_t _IQ4log(int32_t a) {
    return __IQNlog(a, 1, 4);
}
/**
 * @brief Computes the base-e logarithm of an IQ3 input.
 *
 * @param a                 IQ3 type input.
 *
 * @return                  IQ3 type result of exponential.
 */
int32_t _IQ3log(int32_t a) {
    return __IQNlog(a, 1, 3);
}
/**
 * @brief Computes the base-e logarithm of an IQ2 input.
 *
 * @param a                 IQ2 type input.
 *
 * @return                  IQ2 type result of exponential.
 */
int32_t _IQ2log(int32_t a) {
    return __IQNlog(a, 1, 2);
}
/**
 * @brief Computes the base-e logarithm of an IQ1 input.
 *
 * @param a                 IQ1 type input.
 *
 * @return                  IQ1 type result of exponential.
 */
int32_t _IQ1log(int32_t a) {
    return __IQNlog(a, 1, 1);
}
//***********************************************************//

//***********************************************************//
/**
 * @brief Return the fractional portion of an IQ30 input.
 *
 * @param a               IQ30 type input.
 *
 * @return                IQ30 type fractional portion of input.
 */
int32_t _IQ30frac(int32_t a) {
    return __IQNfrac(a, 30);
}
/**
 * @brief Return the fractional portion of an IQ29 input.
 *
 * @param a               IQ29 type input.
 *
 * @return                IQ29 type fractional portion of input.
 */
int32_t _IQ29frac(int32_t a) {
    return __IQNfrac(a, 29);
}
/**
 * @brief Return the fractional portion of an IQ28 input.
 *
 * @param a               IQ28 type input.
 *
 * @return                IQ28 type fractional portion of input.
 */
int32_t _IQ28frac(int32_t a) {
    return __IQNfrac(a, 28);
}
/**
 * @brief Return the fractional portion of an IQ27 input.
 *
 * @param a               IQ27 type input.
 *
 * @return                IQ27 type fractional portion of input.
 */
int32_t _IQ27frac(int32_t a) {
    return __IQNfrac(a, 27);
}
/**
 * @brief Return the fractional portion of an IQ26 input.
 *
 * @param a               IQ26 type input.
 *
 * @return                IQ26 type fractional portion of input.
 */
int32_t _IQ26frac(int32_t a) {
    return __IQNfrac(a, 26);
}
/**
 * @brief Return the fractional portion of an IQ25 input.
 *
 * @param a               IQ25 type input.
 *
 * @return                IQ25 type fractional portion of input.
 */
int32_t _IQ25frac(int32_t a) {
    return __IQNfrac(a, 25);
}
/**
 * @brief Return the fractional portion of an IQ24 input.
 *
 * @param a               IQ24 type input.
 *
 * @return                IQ24 type fractional portion of input.
 */
int32_t _IQ24frac(int32_t a) {
    return __IQNfrac(a, 24);
}
/**
 * @brief Return the fractional portion of an IQ23 input.
 *
 * @param a               IQ23 type input.
 *
 * @return                IQ23 type fractional portion of input.
 */
int32_t _IQ23frac(int32_t a) {
    return __IQNfrac(a, 23);
}
/**
 * @brief Return the fractional portion of an IQ22 input.
 *
 * @param a               IQ22 type input.
 *
 * @return                IQ22 type fractional portion of input.
 */
int32_t _IQ22frac(int32_t a) {
    return __IQNfrac(a, 22);
}
/**
 * @brief Return the fractional portion of an IQ21 input.
 *
 * @param a               IQ21 type input.
 *
 * @return                IQ21 type fractional portion of input.
 */
int32_t _IQ21frac(int32_t a) {
    return __IQNfrac(a, 21);
}
/**
 * @brief Return the fractional portion of an IQ20 input.
 *
 * @param a               IQ20 type input.
 *
 * @return                IQ20 type fractional portion of input.
 */
int32_t _IQ20frac(int32_t a) {
    return __IQNfrac(a, 20);
}
/**
 * @brief Return the fractional portion of an IQ19 input.
 *
 * @param a               IQ19 type input.
 *
 * @return                IQ19 type fractional portion of input.
 */
int32_t _IQ19frac(int32_t a) {
    return __IQNfrac(a, 19);
}
/**
 * @brief Return the fractional portion of an IQ18 input.
 *
 * @param a               IQ18 type input.
 *
 * @return                IQ18 type fractional portion of input.
 */
int32_t _IQ18frac(int32_t a) {
    return __IQNfrac(a, 18);
}
/**
 * @brief Return the fractional portion of an IQ17 input.
 *
 * @param a               IQ17 type input.
 *
 * @return                IQ17 type fractional portion of input.
 */
int32_t _IQ17frac(int32_t a) {
    return __IQNfrac(a, 17);
}
/**
 * @brief Return the fractional portion of an IQ16 input.
 *
 * @param a               IQ16 type input.
 *
 * @return                IQ16 type fractional portion of input.
 */
int32_t _IQ16frac(int32_t a) {
    return __IQNfrac(a, 16);
}
/**
 * @brief Return the fractional portion of an IQ15 input.
 *
 * @param a               IQ15 type input.
 *
 * @return                IQ15 type fractional portion of input.
 */
int32_t _IQ15frac(int32_t a) {
    return __IQNfrac(a, 15);
}
/**
 * @brief Return the fractional portion of an IQ14 input.
 *
 * @param a               IQ14 type input.
 *
 * @return                IQ14 type fractional portion of input.
 */
int32_t _IQ14frac(int32_t a) {
    return __IQNfrac(a, 14);
}
/**
 * @brief Return the fractional portion of an IQ13 input.
 *
 * @param a               IQ13 type input.
 *
 * @return                IQ13 type fractional portion of input.
 */
int32_t _IQ13frac(int32_t a) {
    return __IQNfrac(a, 13);
}
/**
 * @brief Return the fractional portion of an IQ12 input.
 *
 * @param a               IQ12 type input.
 *
 * @return                IQ12 type fractional portion of input.
 */
int32_t _IQ12frac(int32_t a) {
    return __IQNfrac(a, 12);
}
/**
 * @brief Return the fractional portion of an IQ11 input.
 *
 * @param a               IQ11 type input.
 *
 * @return                IQ11 type fractional portion of input.
 */
int32_t _IQ11frac(int32_t a) {
    return __IQNfrac(a, 11);
}
/**
 * @brief Return the fractional portion of an IQ10 input.
 *
 * @param a               IQ10 type input.
 *
 * @return                IQ10 type fractional portion of input.
 */
int32_t _IQ10frac(int32_t a) {
    return __IQNfrac(a, 10);
}
/**
 * @brief Return the fractional portion of an IQ9 input.
 *
 * @param a               IQ9 type input.
 *
 * @return                IQ9 type fractional portion of input.
 */
int32_t _IQ9frac(int32_t a) {
    return __IQNfrac(a, 9);
}
/**
 * @brief Return the fractional portion of an IQ8 input.
 *
 * @param a               IQ8 type input.
 *
 * @return                IQ8 type fractional portion of input.
 */
int32_t _IQ8frac(int32_t a) {
    return __IQNfrac(a, 8);
}
/**
 * @brief Return the fractional portion of an IQ7 input.
 *
 * @param a               IQ7 type input.
 *
 * @return                IQ7 type fractional portion of input.
 */
int32_t _IQ7frac(int32_t a) {
    return __IQNfrac(a, 7);
}
/**
 * @brief Return the fractional portion of an IQ6 input.
 *
 * @param a               IQ6 type input.
 *
 * @return                IQ6 type fractional portion of input.
 */
int32_t _IQ6frac(int32_t a) {
    return __IQNfrac(a, 6);
}
/**
 * @brief Return the fractional portion of an IQ5 input.
 *
 * @param a               IQ5 type input.
 *
 * @return                IQ5 type fractional portion of input.
 */
int32_t _IQ5frac(int32_t a) {
    return __IQNfrac(a, 5);
}
/**
 * @brief Return the fractional portion of an IQ4 input.
 *
 * @param a               IQ4 type input.
 *
 * @return                IQ4 type fractional portion of input.
 */
int32_t _IQ4frac(int32_t a) {
    return __IQNfrac(a, 4);
}
/**
 * @brief Return the fractional portion of an IQ3 input.
 *
 * @param a               IQ3 type input.
 *
 * @return                IQ3 type fractional portion of input.
 */
int32_t _IQ3frac(int32_t a) {
    return __IQNfrac(a, 3);
}
/**
 * @brief Return the fractional portion of an IQ2 input.
 *
 * @param a               IQ2 type input.
 *
 * @return                IQ2 type fractional portion of input.
 */
int32_t _IQ2frac(int32_t a) {
    return __IQNfrac(a, 2);
}
/**
 * @brief Return the fractional portion of an IQ1 input.
 *
 * @param a               IQ1 type input.
 *
 * @return                IQ1 type fractional portion of input.
 */
int32_t _IQ1frac(int32_t a) {
    return __IQNfrac(a, 1);
}

//***********************************************************//

//***********************************************************//
/**
 * @brief Converts string to IQ31 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ31 type.
 */
int32_t _atoIQ31(const char *string) {
    return __atoIQN(string, 31);
}
/**
 * @brief Converts string to IQ30 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ30 type.
 */
int32_t _atoIQ30(const char *string) {
    return __atoIQN(string, 30);
}
/**
 * @brief Converts string to IQ29 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ29 type.
 */
int32_t _atoIQ29(const char *string) {
    return __atoIQN(string, 29);
}
/**
 * @brief Converts string to IQ28 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ28 type.
 */
int32_t _atoIQ28(const char *string) {
    return __atoIQN(string, 28);
}
/**
 * @brief Converts string to IQ27 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ27 type.
 */
int32_t _atoIQ27(const char *string) {
    return __atoIQN(string, 27);
}
/**
 * @brief Converts string to IQ26 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ26 type.
 */
int32_t _atoIQ26(const char *string) {
    return __atoIQN(string, 26);
}
/**
 * @brief Converts string to IQ25 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ25 type.
 */
int32_t _atoIQ25(const char *string) {
    return __atoIQN(string, 25);
}
/**
 * @brief Converts string to IQ24 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ24 type.
 */
int32_t _atoIQ24(const char *string) {
    return __atoIQN(string, 24);
}
/**
 * @brief Converts string to IQ23 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ23 type.
 */
int32_t _atoIQ23(const char *string) {
    return __atoIQN(string, 23);
}
/**
 * @brief Converts string to IQ22 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ22 type.
 */
int32_t _atoIQ22(const char *string) {
    return __atoIQN(string, 22);
}
/**
 * @brief Converts string to IQ21 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ21 type.
 */
int32_t _atoIQ21(const char *string) {
    return __atoIQN(string, 21);
}
/**
 * @brief Converts string to IQ20 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ20 type.
 */
int32_t _atoIQ20(const char *string) {
    return __atoIQN(string, 20);
}
/**
 * @brief Converts string to IQ19 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ19 type.
 */
int32_t _atoIQ19(const char *string) {
    return __atoIQN(string, 19);
}
/**
 * @brief Converts string to IQ18 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ18 type.
 */
int32_t _atoIQ18(const char *string) {
    return __atoIQN(string, 18);
}
/**
 * @brief Converts string to IQ17 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ17 type.
 */
int32_t _atoIQ17(const char *string) {
    return __atoIQN(string, 17);
}
/**
 * @brief Converts string to IQ16 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ16 type.
 */
int32_t _atoIQ16(const char *string) {
    return __atoIQN(string, 16);
}
/**
 * @brief Converts string to IQ15 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ15 type.
 */
int32_t _atoIQ15(const char *string) {
    return __atoIQN(string, 15);
}
/**
 * @brief Converts string to IQ14 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ14 type.
 */
int32_t _atoIQ14(const char *string) {
    return __atoIQN(string, 14);
}
/**
 * @brief Converts string to IQ13 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ13 type.
 */
int32_t _atoIQ13(const char *string) {
    return __atoIQN(string, 13);
}
/**
 * @brief Converts string to IQ12 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ12 type.
 */
int32_t _atoIQ12(const char *string) {
    return __atoIQN(string, 12);
}
/**
 * @brief Converts string to IQ11 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ11 type.
 */
int32_t _atoIQ11(const char *string) {
    return __atoIQN(string, 11);
}
/**
 * @brief Converts string to IQ10 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ10 type.
 */
int32_t _atoIQ10(const char *string) {
    return __atoIQN(string, 10);
}
/**
 * @brief Converts string to IQ9 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ9 type.
 */
int32_t _atoIQ9(const char *string) {
    return __atoIQN(string, 9);
}
/**
 * @brief Converts string to IQ8 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ8 type.
 */
int32_t _atoIQ8(const char *string) {
    return __atoIQN(string, 8);
}
/**
 * @brief Converts string to IQ7 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ7 type.
 */
int32_t _atoIQ7(const char *string) {
    return __atoIQN(string, 7);
}
/**
 * @brief Converts string to IQ6 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ6 type.
 */
int32_t _atoIQ6(const char *string) {
    return __atoIQN(string, 6);
}
/**
 * @brief Converts string to IQ5 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ5 type.
 */
int32_t _atoIQ5(const char *string) {
    return __atoIQN(string, 5);
}
/**
 * @brief Converts string to IQ4 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ4 type.
 */
int32_t _atoIQ4(const char *string) {
    return __atoIQN(string, 4);
}
/**
 * @brief Converts string to IQ3 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ3 type.
 */
int32_t _atoIQ3(const char *string) {
    return __atoIQN(string, 3);
}
/**
 * @brief Converts string to IQ2 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ2 type.
 */
int32_t _atoIQ2(const char *string) {
    return __atoIQN(string, 2);
}
/**
 * @brief Converts string to IQ1 number.
 *
 * @param string        Pointer to the string to be converted.
 *
 * @return              Conversion of string to IQ1 type.
 */
int32_t _atoIQ1(const char *string) {
    return __atoIQN(string, 1);
}

/**
 * @brief Convert an IQ31 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ31 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
int16_t _IQ31toa(char *string, const char *format, int32_t iqNInput) {
    return __IQNtoa(string, format, iqNInput, 31);
}
/**
 * @brief Convert an IQ30 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ30 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ30toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 30);
 }
/**
 * @brief Convert an IQ29 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ29 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ29toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 29);
 }
/**
 * @brief Convert an IQ28 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ28 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ28toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 28);
 }
/**
 * @brief Convert an IQ27 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ27 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ27toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 27);
 }
/**
 * @brief Convert an IQ26 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ26 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ26toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 26);
 }
/**
 * @brief Convert an IQ25 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ25 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ25toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 25);
 }
/**
 * @brief Convert an IQ24 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ24 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ24toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 24);
 }
/**
 * @brief Convert an IQ23 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ23 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ23toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 23);
 }
/**
 * @brief Convert an IQ22 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ22 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ22toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 22);
 }
/**
 * @brief Convert an IQ21 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ21 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ21toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 21);
 }
/**
 * @brief Convert an IQ20 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ20 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ20toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 20);
 }
/**
 * @brief Convert an IQ19 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ19 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ19toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 19);
 }
/**
 * @brief Convert an IQ18 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ18 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ18toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 18);
 }
/**
 * @brief Convert an IQ17 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ17 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ17toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 17);
 }
/**
 * @brief Convert an IQ16 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ16 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ16toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 16);
 }
/**
 * @brief Convert an IQ15 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ15 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ15toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 15);
 }
/**
 * @brief Convert an IQ14 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ14 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ14toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 14);
 }
/**
 * @brief Convert an IQ13 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ13 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ13toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 13);
 }
/**
 * @brief Convert an IQ12 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ12 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ12toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 12);
 }
/**
 * @brief Convert an IQ11 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ11 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ11toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 11);
 }
/**
 * @brief Convert an IQ10 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ10 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ10toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 10);
 }
/**
 * @brief Convert an IQ9 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ9 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ9toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 9);
 }
/**
 * @brief Convert an IQ8 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ8 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ8toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 8);
 }
/**
 * @brief Convert an IQ7 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ7 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ7toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 7);
 }
/**
 * @brief Convert an IQ6 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ6 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ6toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 6);
 }
/**
 * @brief Convert an IQ5 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ5 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ5toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 5);
 }
/**
 * @brief Convert an IQ4 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ4 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ4toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 4);
 }
/**
 * @brief Convert an IQ3 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ3 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ3toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 3);
 }
/**
 * @brief Convert an IQ2 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ2 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ2toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 2);
 }
/**
 * @brief Convert an IQ1 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ1 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
 int16_t _IQ1toa(char *string, const char *format, int32_t iqNInput)
{
     return __IQNtoa(string, format, iqNInput, 1);
 }
/**
 * @brief Convert an IQ0 number to a string.
 *
 * @param string          Pointer to the buffer to store the converted IQ number.
 * @param format          The format string specifying how to convert the IQ number.
 * @param iqNInput        IQ0 type input.
 *
 * @return                Returns 0 if there is no error, 1 if the width is too small to hold the integer
 *                        characters, and 2 if an illegal format was specified.
 */
int16_t _IQ0toa(char *string, const char *format, int32_t iqNInput) {
    return __IQNtoa(string, format, iqNInput, 0);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ30 type input.
 * @param b          	  long type input.
 *
 * @return                IQ30 type integer portion of a*b.
 */
int32_t _IQ30mpyI32int(int32_t a, int32_t b) {
//
//	return  (__ftrunc(__iqn2float(a, 30)*b));
//#else
    return __IQNmpyI32int(a, b, 30);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ29 type input.
 * @param b          	  long type input.
 *
 * @return                IQ29 type integer portion of a*b.
 */
int32_t _IQ29mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 29)*b));
//#else
    return __IQNmpyI32int(a, b, 29);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ28 type input.
 * @param b          	  long type input.
 *
 * @return                IQ28 type integer portion of a*b.
 */
int32_t _IQ28mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 28)*b));
//#else
    return __IQNmpyI32int(a, b, 28);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ27 type input.
 * @param b          	  long type input.
 *
 * @return                IQ27 type integer portion of a*b.
 */
int32_t _IQ27mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 27)*b));
//#else
    return __IQNmpyI32int(a, b, 27);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ26 type input.
 * @param b          	  long type input.
 *
 * @return                IQ26 type integer portion of a*b.
 */
int32_t _IQ26mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 26)*b));
//#else
    return __IQNmpyI32int(a, b, 26);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ25 type input.
 * @param b          	  long type input.
 *
 * @return                IQ25 type integer portion of a*b.
 */
int32_t _IQ25mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 25)*b));
//#else
    return __IQNmpyI32int(a, b, 25);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ24 type input.
 * @param b          	  long type input.
 *
 * @return                IQ24 type integer portion of a*b.
 */
int32_t _IQ24mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 24)*b));
//#else
    return __IQNmpyI32int(a, b, 24);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ23 type input.
 * @param b          	  long type input.
 *
 * @return                IQ23 type integer portion of a*b.
 */
int32_t _IQ23mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 23)*b));
//#else
    return __IQNmpyI32int(a, b, 23);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ22 type input.
 * @param b          	  long type input.
 *
 * @return                IQ22 type integer portion of a*b.
 */
int32_t _IQ22mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 22)*b));
//#else
    return __IQNmpyI32int(a, b, 22);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ21 type input.
 * @param b          	  long type input.
 *
 * @return                IQ21 type integer portion of a*b.
 */
int32_t _IQ21mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 21)*b));
//#else
    return __IQNmpyI32int(a, b, 21);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ20 type input.
 * @param b          	  long type input.
 *
 * @return                IQ20 type integer portion of a*b.
 */
int32_t _IQ20mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 20)*b));
//#else
    return __IQNmpyI32int(a, b, 20);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ19 type input.
 * @param b          	  long type input.
 *
 * @return                IQ19 type integer portion of a*b.
 */
int32_t _IQ19mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 19)*b));
//#else
    return __IQNmpyI32int(a, b, 19);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ18 type input.
 * @param b          	  long type input.
 *
 * @return                IQ18 type integer portion of a*b.
 */
int32_t _IQ18mpyI32int(int32_t a, int32_t b) {
//
//	return (__ftrunc(__iqn2float(a, 18)*b));
//#else
    return __IQNmpyI32int(a, b, 18);
//#endif
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ17 type input.
 * @param b          	  long type input.
 *
 * @return                IQ17 type integer portion of a*b.
 */
int32_t _IQ17mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 17);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ16 type input.
 * @param b          	  long type input.
 *
 * @return                IQ16 type integer portion of a*b.
 */
int32_t _IQ16mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 16);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ15 type input.
 * @param b          	  long type input.
 *
 * @return                IQ15 type integer portion of a*b.
 */
int32_t _IQ15mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 15);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ14 type input.
 * @param b          	  long type input.
 *
 * @return                IQ14 type integer portion of a*b.
 */
int32_t _IQ14mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 14);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ13 type input.
 * @param b          	  long type input.
 *
 * @return                IQ13 type integer portion of a*b.
 */
int32_t _IQ13mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 13);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ12 type input.
 * @param b          	  long type input.
 *
 * @return                IQ12 type integer portion of a*b.
 */
int32_t _IQ12mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 12);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ11 type input.
 * @param b          	  long type input.
 *
 * @return                IQ11 type integer portion of a*b.
 */
int32_t _IQ11mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 11);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ10 type input.
 * @param b          	  long type input.
 *
 * @return                IQ10 type integer portion of a*b.
 */
int32_t _IQ10mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 10);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ9 type input.
 * @param b          	  long type input.
 *
 * @return                IQ9 type integer portion of a*b.
 */
int32_t _IQ9mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 9);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ8 type input.
 * @param b          	  long type input.
 *
 * @return                IQ8 type integer portion of a*b.
 */
int32_t _IQ8mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 8);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ7 type input.
 * @param b          	  long type input.
 *
 * @return                IQ7 type integer portion of a*b.
 */
int32_t _IQ7mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 7);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ6 type input.
 * @param b          	  long type input.
 *
 * @return                IQ6 type integer portion of a*b.
 */
int32_t _IQ6mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 6);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ5 type input.
 * @param b          	  long type input.
 *
 * @return                IQ5 type integer portion of a*b.
 */
int32_t _IQ5mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 5);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ4 type input.
 * @param b          	  long type input.
 *
 * @return                IQ4 type integer portion of a*b.
 */
int32_t _IQ4mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 4);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ3 type input.
 * @param b          	  long type input.
 *
 * @return                IQ3 type integer portion of a*b.
 */
int32_t _IQ3mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 3);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ2 type input.
 * @param b          	  long type input.
 *
 * @return                IQ2 type integer portion of a*b.
 */
int32_t _IQ2mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 2);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the integer portion.
 *
 * @param a				  IQ1 type input.
 * @param b          	  long type input.
 *
 * @return                IQ1 type integer portion of a*b.
 */
int32_t _IQ1mpyI32int(int32_t a, int32_t b) {
    return __IQNmpyI32int(a, b, 1);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ30 type input.
 * @param b          	  long type input.
 *
 * @return                IQ30 type fractional portion of a*b.
 */
int32_t _IQ30mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 30);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ29 type input.
 * @param b          	  long type input.
 *
 * @return                IQ29 type fractional portion of a*b.
 */
int32_t _IQ29mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 29);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ28 type input.
 * @param b          	  long type input.
 *
 * @return                IQ28 type fractional portion of a*b.
 */
int32_t _IQ28mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 28);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ27 type input.
 * @param b          	  long type input.
 *
 * @return                IQ27 type fractional portion of a*b.
 */
int32_t _IQ27mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 27);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ26 type input.
 * @param b          	  long type input.
 *
 * @return                IQ26 type fractional portion of a*b.
 */
int32_t _IQ26mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 26);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ25 type input.
 * @param b          	  long type input.
 *
 * @return                IQ25 type fractional portion of a*b.
 */
int32_t _IQ25mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 25);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ24 type input.
 * @param b          	  long type input.
 *
 * @return                IQ24 type fractional portion of a*b.
 */
int32_t _IQ24mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 24);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ23 type input.
 * @param b          	  long type input.
 *
 * @return                IQ23 type fractional portion of a*b.
 */
int32_t _IQ23mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 23);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ22 type input.
 * @param b          	  long type input.
 *
 * @return                IQ22 type fractional portion of a*b.
 */
int32_t _IQ22mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 22);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ21 type input.
 * @param b          	  long type input.
 *
 * @return                IQ21 type fractional portion of a*b.
 */
int32_t _IQ21mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 21);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ20 type input.
 * @param b          	  long type input.
 *
 * @return                IQ20 type fractional portion of a*b.
 */
int32_t _IQ20mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 20);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ19 type input.
 * @param b          	  long type input.
 *
 * @return                IQ19 type fractional portion of a*b.
 */
int32_t _IQ19mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 19);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ18 type input.
 * @param b          	  long type input.
 *
 * @return                IQ18 type fractional portion of a*b.
 */
int32_t _IQ18mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 18);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ17 type input.
 * @param b          	  long type input.
 *
 * @return                IQ17 type fractional portion of a*b.
 */
int32_t _IQ17mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 17);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ16 type input.
 * @param b          	  long type input.
 *
 * @return                IQ16 type fractional portion of a*b.
 */
int32_t _IQ16mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 16);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ15 type input.
 * @param b          	  long type input.
 *
 * @return                IQ15 type fractional portion of a*b.
 */
int32_t _IQ15mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 15);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ14 type input.
 * @param b          	  long type input.
 *
 * @return                IQ14 type fractional portion of a*b.
 */
int32_t _IQ14mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 14);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ13 type input.
 * @param b          	  long type input.
 *
 * @return                IQ13 type fractional portion of a*b.
 */
int32_t _IQ13mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 13);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ12 type input.
 * @param b          	  long type input.
 *
 * @return                IQ12 type fractional portion of a*b.
 */
int32_t _IQ12mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 12);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ11 type input.
 * @param b          	  long type input.
 *
 * @return                IQ11 type fractional portion of a*b.
 */
int32_t _IQ11mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 11);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ10 type input.
 * @param b          	  long type input.
 *
 * @return                IQ10 type fractional portion of a*b.
 */
int32_t _IQ10mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 10);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ9 type input.
 * @param b          	  long type input.
 *
 * @return                IQ9 type fractional portion of a*b.
 */
int32_t _IQ9mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 9);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ8 type input.
 * @param b          	  long type input.
 *
 * @return                IQ8 type fractional portion of a*b.
 */
int32_t _IQ8mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 8);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ7 type input.
 * @param b          	  long type input.
 *
 * @return                IQ7 type fractional portion of a*b.
 */
int32_t _IQ7mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 7);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ6 type input.
 * @param b          	  long type input.
 *
 * @return                IQ6 type fractional portion of a*b.
 */
int32_t _IQ6mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 6);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ5 type input.
 * @param b          	  long type input.
 *
 * @return                IQ5 type fractional portion of a*b.
 */
int32_t _IQ5mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 5);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ4 type input.
 * @param b          	  long type input.
 *
 * @return                IQ4 type fractional portion of a*b.
 */
int32_t _IQ4mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 4);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ3 type input.
 * @param b          	  long type input.
 *
 * @return                IQ3 type fractional portion of a*b.
 */
int32_t _IQ3mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 3);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ2 type input.
 * @param b          	  long type input.
 *
 * @return                IQ2 type fractional portion of a*b.
 */
int32_t _IQ2mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 2);
}

/**
 * @brief Multiplies an IQ number by an integer, and returns the fractional portion.
 *
 * @param a				  IQ1 type input.
 * @param b          	  long type input.
 *
 * @return                IQ1 type fractional portion of a*b.
 */
int32_t _IQ1mpyI32frac(int32_t a, int32_t b) {
    return __IQNmpyI32frac(a, b, 1);
}

#endif /* ENABLE_IQMATH_FUNC_DECLARE */

#ifdef __cplusplus
}
#endif
