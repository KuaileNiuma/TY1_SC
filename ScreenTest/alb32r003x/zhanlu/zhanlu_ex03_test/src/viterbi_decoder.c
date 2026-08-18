/**
 *************************************************************************************
 * @file viterbi_decoder.c
 * @brief This file contains the source file.
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
//*****************************************************************************
//
// includes
//
//*****************************************************************************
#include "viterbi_decoder.h"
#include <stdio.h>
 /* Include core tmu feature header file */
 #include "core_feature_tmu.h"
 /* Include core vcu feature header file */
 #include "core_feature_vcu.h"
//*****************************************************************************
//
// function definitions
//
//*****************************************************************************

//*****************************************************************************
//
// \brief Initialize the state metric in VR and configure decoding parameters
//
//*****************************************************************************
void initK4CR12(int init_value, int k, int sat, int opack, int sym)
{
    int cfg_data = k | (sat << 3) | (opack << 4) | (sym << 5);
    int init1 = (init_value << 16);
    int init2 = (init_value & 0xFFFF) | init1;
#ifdef ZHANLU
  vitcfg(cfg_data);
  vitmovout32_t1(0,init1);
  vitmovout32_t1(2,init2);
  vitmovout32_t2(4,init2);
#else
    __alb_vitcfg(cfg_data);
    __alb_vitmovout32_t1(0, init1);
    __alb_vitmovout32_t1(2, init2);
    __alb_vitmovout32_t2(4, init2);
#endif
}

//*****************************************************************************
//
// \brief Compute one stage use acs2 instruction
//
//*****************************************************************************
void decode_1stage_acs2_K4CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[])
{
#ifdef ZHANLU
	vitclear4(28); //clear TR0,TR1
	vitmovout32_t1(20,din);
	vitbm2(20,20);
	vitacs2(0,bm_sel[0]);
	vitacs2(2,bm_sel[1]);
	vitacs2(4,bm_sel[2]);
	vitacs2(6,bm_sel[3]);
#else
    __alb_vitclear4(28); //clear TR0,TR1
    __alb_vitmovout32_t1(20, din);
    __alb_vitbm2(20, 20);
    __alb_vitacs2(0, bm_sel[0]);
    __alb_vitacs2(2, bm_sel[1]);
    __alb_vitacs2(4, bm_sel[2]);
    __alb_vitacs2(6, bm_sel[3]);
#endif
    uint16_t tmp_list[8];
#ifdef ZHANLU
  unsigned long tmp = vitmovin32(0);
  tmp_list[0] = tmp;
  tmp_list[4] = tmp >> 16;
  tmp = vitmovin32(2);
  tmp_list[1] = tmp;
  tmp_list[5] = tmp >> 16;
  tmp = vitmovin32(4);
  tmp_list[2] = tmp;
  tmp_list[6] = tmp >> 16;
  tmp = vitmovin32(6);
  tmp_list[3] = tmp;
  tmp_list[7] = tmp >> 16;
  
  tmp = (tmp_list[1] << 16) | tmp_list[0];
  vitmovout32_t1(0,tmp);
  tmp = (tmp_list[3] << 16) | tmp_list[2];
  vitmovout32_t1(2,tmp);
  tmp = (tmp_list[5] << 16) | tmp_list[4];
  vitmovout32_t1(4,tmp);
  tmp = (tmp_list[7] << 16) | tmp_list[6];
  vitmovout32_t1(6,tmp);
  unsigned long long tr = vitmovin64_pair(28);
  tr0[0] = tr & 0xFFFFFFFF;
  tr1[0] = tr >> 32;
#else
    unsigned long tmp = __alb_vitmovin32(0);
    tmp_list[0] = tmp;
    tmp_list[4] = tmp >> 16;
    tmp = __alb_vitmovin32(2);
    tmp_list[1] = tmp;
    tmp_list[5] = tmp >> 16;
    tmp = __alb_vitmovin32(4);
    tmp_list[2] = tmp;
    tmp_list[6] = tmp >> 16;
    tmp = __alb_vitmovin32(6);
    tmp_list[3] = tmp;
    tmp_list[7] = tmp >> 16;

    tmp = (tmp_list[1] << 16) | tmp_list[0];
    __alb_vitmovout32_t1(0, tmp);
    tmp = (tmp_list[3] << 16) | tmp_list[2];
    __alb_vitmovout32_t1(2, tmp);
    tmp = (tmp_list[5] << 16) | tmp_list[4];
    __alb_vitmovout32_t1(4, tmp);
    tmp = (tmp_list[7] << 16) | tmp_list[6];
    __alb_vitmovout32_t1(6, tmp);
    unsigned long long tr = __alb_vitmovin64_pair(28);
    tr0[0] = tr & 0xFFFFFFFF;
    tr1[0] = tr >> 32;
#endif
}

//*****************************************************************************
//
// Compute one stage use acs4 instruction
//
//*****************************************************************************
void decode_1stage_acs4_K4CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[])
{
#ifdef ZHANLU
	vitclear4(28); //clear TR0,TR1
  vitmovout32_t1(20,din);
  vitbm2(20,20);
  vitacs4(0,bm_sel[0]);
  vitacs4(4,bm_sel[1]);
  unsigned long tmp1 = vitmovin32(2);
  unsigned long tmp2 = vitmovin32(4);
  vitmovout32_t1(4,tmp1);
  vitmovout32_t1(2,tmp2);
  unsigned long long tr = vitmovin64_pair(28);
  tr0[0] = tr & 0xFFFFFFFF;
  tr1[0] = tr >> 32;
#else
    __alb_vitclear4(28); //clear TR0,TR1
    __alb_vitmovout32_t1(20, din);
    __alb_vitbm2(20, 20);
    __alb_vitacs4(0, bm_sel[0]);
    __alb_vitacs4(4, bm_sel[1]);
    unsigned long tmp1 = __alb_vitmovin32(2);
    unsigned long tmp2 = __alb_vitmovin32(4);
    __alb_vitmovout32_t1(4, tmp1);
    __alb_vitmovout32_t1(2, tmp2);
    unsigned long long tr = __alb_vitmovin64_pair(28);
    tr0[0] = tr & 0xFFFFFFFF;
    tr1[0] = tr >> 32;
#endif
}
//*****************************************************************************
//
// \brief Compute one stage use acs8 instruction
//
//*****************************************************************************
void decode_1stage_acs8_K4CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[])
{
#ifdef ZHANLU
	vitclear4(28); //clear TR0,TR1
  vitmovout32_t1(20,din);
  vitbm2(20,20);
  vitacsn(0,bm_sel[0]);
  unsigned long long tr = vitmovin64_pair(28);
  tr0[0] = tr & 0xFFFFFFFF;
  tr1[0] = tr >> 32;
#else
    __alb_vitclear4(28); //clear TR0,TR1
    __alb_vitmovout32_t1(20, din);
    __alb_vitbm2(20, 20);
    __alb_vitacsn(0, bm_sel[0]);
    unsigned long long tr = __alb_vitmovin64_pair(28);
    tr0[0] = tr & 0xFFFFFFFF;
    tr1[0] = tr >> 32;
#endif
}
//*****************************************************************************
//
// \brief Initialize the state metric in MEM and configure decoding parameters
//
//*****************************************************************************
void initK7CR12(int init_value, int k, int sat, int opack, int sym, uint32_t old_sm[])
{
    int cfg_data = k | (sat << 3) | (opack << 4) | (sym << 5);
    int init1 = (init_value << 16);
    int init2 = (init_value & 0xFFFF) | init1;
#ifdef ZHANLU
  vitcfg(cfg_data);
#else
    __alb_vitcfg(cfg_data);
#endif
    old_sm[0] = init1;
    for (int i = 1; i < 32; i++)
    {
        old_sm[i] = init2;
    }
}

//*****************************************************************************
//
// \brief Compute one stage use acs8 instruction
//
//*****************************************************************************
void decode_1stage_acs8_K7CR12(unsigned int din, unsigned int bm_sel[], unsigned int tr1[], unsigned int tr0[],
        uint32_t old_sm[], int32_t new_sm[])
{
#ifdef ZHANLU
	vitclear4(28); //clear TR0,TR1
  vitmovout32_t1(20,din);
  vitbm2(20,20);
  vitacsn(0,bm_sel[0]);
  for(int i = 0; i < 8; i++){
	  vitmovout32_t1(0,old_sm[4*i]);
	  vitmovout32_t1(2,old_sm[4*i+1]);
	  vitmovout32_t1(4,old_sm[4*i+2]);
	  vitmovout32_t1(6,old_sm[4*i+3]);
	  vitacsn(0,bm_sel[i]);
    //printf("%x\n",bm_sel[i]);
    new_sm[2*i    ]  = vitmovin32(0);
    new_sm[2*i + 1]  = vitmovin32(2);
    new_sm[2*i + 16] = vitmovin32(4);
    new_sm[2*i + 17] = vitmovin32(6);
  }
  unsigned long long tr = vitmovin64_pair(28);
  tr0[0] = tr & 0xFFFFFFFF;
  tr1[0] = tr >> 32;
#else
    __alb_vitclear4(28); //clear TR0,TR1
    __alb_vitmovout32_t1(20, din);
    __alb_vitbm2(20, 20);
    __alb_vitacsn(0, bm_sel[0]);
    for (int i = 0; i < 8; i++)
    {
        __alb_vitmovout32_t1(0, old_sm[4 * i]);
        __alb_vitmovout32_t1(2, old_sm[4 * i + 1]);
        __alb_vitmovout32_t1(4, old_sm[4 * i + 2]);
        __alb_vitmovout32_t1(6, old_sm[4 * i + 3]);
        __alb_vitacsn(0, bm_sel[i]);
        //printf("%x\n",bm_sel[i]);
        new_sm[2 * i] = __alb_vitmovin32(0);
        new_sm[2 * i + 1] = __alb_vitmovin32(2);
        new_sm[2 * i + 16] = __alb_vitmovin32(4);
        new_sm[2 * i + 17] = __alb_vitmovin32(6);
    }
    unsigned long long tr = __alb_vitmovin64_pair(28);
    tr0[0] = tr & 0xFFFFFFFF;
    tr1[0] = tr >> 32;
#endif
}

//*****************************************************************************
//
// \brief vitervi decode 
//
//*****************************************************************************
void decode_viterbi_K4CR12(int16_t data_bits_in[], uint16_t data_pack_out[], unsigned int tr1_list[],
        unsigned int tr0_list[], unsigned int bm_sel, int init_value, int k, int sat, int opack, int sym,
        int data_bits_len, int acs_mode)
{
    initK4CR12(init_value, k, sat, opack, sym);
    unsigned int din, tr1, tr0, dout;
    unsigned int *pdin;
    int i;
    pdin = (unsigned int*) data_bits_in;

    // acs mode select
    unsigned int bm_sel_list[4];
    int shift_num;
    STAGE_DECODE stage_decode_func;
    if (acs_mode == 2)
    {
        shift_num = sym ? 4 : 8;
        bm_sel_list[0] = bm_sel;
        bm_sel_list[1] = bm_sel >> shift_num;
        bm_sel_list[2] = bm_sel >> 2 * shift_num;
        bm_sel_list[3] = bm_sel >> 3 * shift_num;
        stage_decode_func = &decode_1stage_acs2_K4CR12;
    }
    else if (acs_mode == 4)
    {
        shift_num = sym ? 8 : 16;
        bm_sel_list[0] = bm_sel;
        bm_sel_list[1] = bm_sel >> shift_num;
        stage_decode_func = &decode_1stage_acs4_K4CR12;
    }
    else
    {
        bm_sel_list[0] = bm_sel;
        stage_decode_func = &decode_1stage_acs8_K4CR12;
    }
    printf("decode use acs%d\n", acs_mode);
    printf("K = %d, SAT = %d, OPACK = %d, SYM = %d\n", k, sat, opack, sym);

    //
    // stage compute 
    //
    for (i = 0; i < data_bits_len; i += 1)
    {
        din = pdin[i];
        stage_decode_func(din, bm_sel_list, tr1_list + i, tr0_list + i);
    }

    //
    // trace and get raw data 
    //
    //clear clear VR0,VR1,VR2,VR3
    //
#ifdef ZHANLU
  vitclear4(0); //clear clear VR0,VR1,VR2,VR3
  for (i=0; i < data_bits_len ;i+=1){
    tr1 = tr1_list[data_bits_len - i - 1];
    tr0 = tr0_list[data_bits_len - i - 1];
    vitmovout64(28,tr0,tr1);
    vittrace(2,0);
    if((i+1)%32 == 0){
      dout = vitmovin32(2);
      data_pack_out[data_bits_len/16 - (i/16)   ]   = dout;
      data_pack_out[data_bits_len/16 - (i/16) -1]   = dout >> 16;
    }
  }
#else
    __alb_vitclear4(0); //clear clear VR0,VR1,VR2,VR3
    for (i = 0; i < data_bits_len; i += 1)
    {
        tr1 = tr1_list[data_bits_len - i - 1];
        tr0 = tr0_list[data_bits_len - i - 1];
        __alb_vitmovout64(28, tr0, tr1);
        __alb_vittrace(2, 0);
        if ((i + 1) % 32 == 0)
        {
            dout = __alb_vitmovin32(2);
            data_pack_out[data_bits_len / 16 - (i / 16)] = dout;
            data_pack_out[data_bits_len / 16 - (i / 16) - 1] = dout >> 16;
        }
    }
#endif
}

//*****************************************************************************
//
// \brief vitervi decode 
//
//*****************************************************************************
void decode_viterbi_K7CR12(int16_t data_bits_in[], uint16_t data_pack_out[], unsigned int tr1_list[],
        unsigned int tr0_list[], unsigned int bm_sel_list[], int init_value, int k, int sat, int opack, int sym,
        int data_bits_len, int acs_mode)
{
    uint32_t old_sm[32];
    uint32_t new_sm[32];
    uint32_t *sm_ptmp;
    uint32_t *sm_pold = old_sm;
    uint32_t *sm_pnew = new_sm;
    initK7CR12(init_value, k, sat, opack, sym, old_sm);
    unsigned int din, tr1, tr0, dout;
    unsigned int *pdin;
    int i;
    pdin = (unsigned int*) data_bits_in;

    printf("decode use acs%d\n", acs_mode);
    printf("K = %d, SAT = %d, OPACK = %d, SYM = %d\n", k, sat, opack, sym);

    //
    // stage compute 
    //
    for (i = 0; i < data_bits_len; i += 1)
    {
        din = pdin[i];
        //printf("din = %x",din);
        decode_1stage_acs8_K7CR12(din, bm_sel_list, tr1_list + i, tr0_list + i, sm_pold, sm_pnew);
        sm_ptmp = sm_pold;
        sm_pold = sm_pnew;
        sm_pnew = sm_ptmp;
    }

    //
    // trace and get raw data 
    //
    //clear clear VR0,VR1,VR2,VR3
    //
#ifdef ZHANLU
  vitclear4(0); //clear clear VR0,VR1,VR2,VR3
  for (i=0; i < data_bits_len ;i+=1){
    tr1 = tr1_list[data_bits_len - i - 1];
    tr0 = tr0_list[data_bits_len - i - 1];
    vitmovout64(28,tr0,tr1);
    vittrace(2,0);
    if((i+1)%32 == 0){
      dout = vitmovin32(2);
      data_pack_out[data_bits_len/16 - (i/16)   ]   = dout;
      data_pack_out[data_bits_len/16 - (i/16) -1]   = dout >> 16;
    }
  }
#else
    __alb_vitclear4(0); //clear clear VR0,VR1,VR2,VR3
    for (i = 0; i < data_bits_len; i += 1)
    {
        tr1 = tr1_list[data_bits_len - i - 1];
        tr0 = tr0_list[data_bits_len - i - 1];
        __alb_vitmovout64(28, tr0, tr1);
        __alb_vittrace(2, 0);
        if ((i + 1) % 32 == 0)
        {
            dout = __alb_vitmovin32(2);
            data_pack_out[data_bits_len / 16 - (i / 16)] = dout;
            data_pack_out[data_bits_len / 16 - (i / 16) - 1] = dout >> 16;
        }
    }
#endif
}
