/** 
  *************************************************************************************
  * @file vcu2_viterbi_k8_cr12.c 
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

//*****************************************************************************
// includes
//*****************************************************************************
#include "vcu2_viterbi_decoder.h"
#include <stdio.h>

//*****************************************************************************
// function definitions
//*****************************************************************************

uint32_t old_sm[32];
uint32_t new_sm[32];

void VITERBI_DECODER_initK7CR12(VITERBI_DECODER_Handle hndVITDecoder)
{
	  int cfg_data =hndVITDecoder->constraintLength| (1 << 3) | (1 << 4) | (0 << 5); //sat=1;opack=1;sym=0
	  int init1 = (hndVITDecoder->stateMetricInit<< 16);
	  int init2 = (hndVITDecoder->stateMetricInit & 0xFFFF) | init1;
	  __builtin_riscv_vitcfg(cfg_data);
	  old_sm[0] = init1;
	  for(int i = 1; i < 32; i++){
	  old_sm[i] = init2;
	  }
}

static void decode_1stage_acs8_K7CR12(unsigned int din,unsigned int bm_sel[],unsigned int tr1[],unsigned int tr0[],uint32_t old_sm[],int32_t new_sm[]){
  __builtin_riscv_vitclear4(28); //clear TR0,TR1
  __builtin_riscv_vitmovout32_t1(20,din);
  __builtin_riscv_vitbm2(20,20);
  for(int i = 0; i < 8; i++){
    __builtin_riscv_vitmovout32_t1(0,old_sm[4*i]);
    __builtin_riscv_vitmovout32_t1(2,old_sm[4*i+1]);
    __builtin_riscv_vitmovout32_t1(4,old_sm[4*i+2]);
    __builtin_riscv_vitmovout32_t1(6,old_sm[4*i+3]);
    __builtin_riscv_vitacsn(0,bm_sel[i]);
    //printf("%x\n",bm_sel[i]);
    new_sm[2*i    ]  = __builtin_riscv_vitmovin32(0);
    new_sm[2*i + 1]  = __builtin_riscv_vitmovin32(2);
    new_sm[2*i + 16] = __builtin_riscv_vitmovin32(4);
    new_sm[2*i + 17] = __builtin_riscv_vitmovin32(6);
  }
  unsigned long long tr = __builtin_riscv_vitmovin64_pair(28);
  tr0[0] = tr & 0xFFFFFFFF;
  tr1[0] = tr >> 32;
}

void VITERBI_DECODER_runK7CR12(VITERBI_DECODER_Handle hndVITDecoder)
{
	uint32_t *sm_ptmp;
	uint32_t *sm_pold = old_sm;
	uint32_t *sm_pnew = new_sm;
	unsigned int din, tr1, tr0, dout;
	unsigned int codebit;
	unsigned int traceblk;
	unsigned int tracebit;
	unsigned int statemask;
	unsigned int bm_sel[8];
	unsigned int *pdin;
	uint16_t *data_pack_out;
	uint16_t *TR;
	int i;
	int j;


	pdin = (unsigned int*)(hndVITDecoder->pInBuffer);
	data_pack_out = hndVITDecoder->pOutBuffer;
	TR = hndVITDecoder->pTransitionHistory;
	bm_sel[0]=hndVITDecoder->pBMSELInit[0];
	bm_sel[1]=hndVITDecoder->pBMSELInit[1];
	bm_sel[2]=hndVITDecoder->pBMSELInit[2];
	bm_sel[3]=hndVITDecoder->pBMSELInit[3];
	bm_sel[4]=hndVITDecoder->pBMSELInit[4];
	bm_sel[5]=hndVITDecoder->pBMSELInit[5];
	bm_sel[6]=hndVITDecoder->pBMSELInit[6];
	bm_sel[7]=hndVITDecoder->pBMSELInit[7];
	codebit = (hndVITDecoder->nBits / hndVITDecoder->codeRate);
	statemask=2<<(hndVITDecoder->nStates/2)-1;

	unsigned int TR1[codebit], TR0[codebit];

	// stage compute
	for (i = 0; i < codebit; i += 1) {
		din = pdin[i];
		//printf("din = %x",din);
		decode_1stage_acs8_K7CR12(din, bm_sel, &TR1[i], &TR0[i], sm_pold,
				sm_pnew);
		sm_ptmp = sm_pold;
		sm_pold = sm_pnew;
		sm_pnew = sm_ptmp;
		if (((i + 1) % 128) == 0) {
			VITERBI_DECODER_rescaleK7CR12(hndVITDecoder);
		}
	}

	// trace and get raw data
	__builtin_riscv_vitclear4(0); //clear clear VR0,VR1,VR2,VR3
	traceblk = codebit / 32;
	tracebit = codebit % 32;
	if (tracebit != 0) {
		for (i = 0; i < tracebit; i += 1) {
			tr1 = TR1[codebit - i - 1];
			tr0 = TR0[codebit - i - 1];
			__builtin_riscv_vitmovout64(28, tr0, tr1);
			__builtin_riscv_vittrace(2, 0);
		}
		dout = __builtin_riscv_vitmovin32(2);
		data_pack_out[traceblk * 2 + 1] = dout;
		data_pack_out[traceblk * 2] = dout >> 16;
	}
	int a;
	int b;
	for (i = tracebit,j=0; i < codebit; i += 1,j+=1) {
		tr1 = TR1[codebit - i - 1];
		tr0 = TR0[codebit - i - 1];
		__builtin_riscv_vitmovout64(28, tr0, tr1);
		__builtin_riscv_vittrace(2, 0);
		if (((j + 1) % 32) == 0) {
			dout = __builtin_riscv_vitmovin32(2);
			a=traceblk * 2-(j/32)*2-1;  //TODO:
			b=traceblk * 2-(j/32)*2-2;
			data_pack_out[a] = dout;
			data_pack_out[b] = dout >> 16;
		}
	}
	for (i = 0; i < codebit; i += 1){
		TR[4*i]=(uint16_t)((TR0[i]>>16)&0xffff);
		TR[4*i+1]=(uint16_t)(TR0[i]&0xffff);
		TR[4*i+2]=(uint16_t)((TR1[i]>>16)&0xffff);
		TR[4*i+3]=(uint16_t)(TR1[i]&0xffff);
	}
}

void VITERBI_DECODER_rescaleK7CR12(VITERBI_DECODER_Handle hndVITDecoder)
{
	//i-jishu  jisuandedaodezhizai old shuzu
	unsigned state;
	unsigned int tmpstate[64];
	int i;
	for(i=0;i<32;i++)
	{
		tmpstate[2*i]=old_sm[i]&0xffff;
		tmpstate[2*i+1]=(old_sm[i]>>16)&0xffff;
	}

	state=tmpstate[0];
	for(i=1;i<64;i++)
	{
		if(tmpstate[i]<=state){
			state=tmpstate[i];
		}

	}

	for(i=0;i<64;i++){
		tmpstate[i]-=state;
	}

	for(i=0;i<32;i++)
	{
		old_sm[i]=(tmpstate[2*i]&0xffff)|((tmpstate[2*i+1]&0xffff)<<16);
	}
}
