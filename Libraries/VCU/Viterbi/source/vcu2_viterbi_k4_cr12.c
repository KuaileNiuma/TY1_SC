/** 
  *************************************************************************************
  * @file vcu2_viterbi_k4_cr12.c 
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

//
// \brief Initialize the state metric in VR and configure decoding parameters
//
void VITERBI_DECODER_initK4CR12(VITERBI_DECODER_Handle hndVITDecoder)
{
	  int cfg_data = hndVITDecoder->constraintLength | (1 << 3) | (1 << 4) | (0 << 5);//sat-1 opack-1 sym=0
	  int init1 = (hndVITDecoder->stateMetricInit << 16);
	  int init2 = (hndVITDecoder->stateMetricInit & 0xFFFF) | init1;
	  __builtin_riscv_vitcfg(cfg_data);
	  __builtin_riscv_vitmovout32_t1(0,init1);
	  __builtin_riscv_vitmovout32_t1(2,init2);
	  __builtin_riscv_vitmovout32_t2(4,init2);

}

static void decode_1stage_acs8_K4CR12(unsigned int din,unsigned int bm_sel[],unsigned int tr1[],unsigned int tr0[]){
  __builtin_riscv_vitclear4(28); //clear TR0,TR1
  __builtin_riscv_vitmovout32_t1(20,din);
  __builtin_riscv_vitbm2(20,20);
  __builtin_riscv_vitacsn(0,bm_sel[0]);
  unsigned long long tr = __builtin_riscv_vitmovin64_pair(28);
  tr0[0] = tr & 0xFFFFFFFF;
  tr1[0] = tr >> 32;
}


void VITERBI_DECODER_runK4CR12(VITERBI_DECODER_Handle hndVITDecoder)
{
	unsigned int din, tr1, tr0, dout;
	unsigned int codebit;
	unsigned int traceblk;
	unsigned int tracebit;
	unsigned int statemask;
	unsigned int bm_sel[1];
	unsigned int *pdin;
	uint16_t *data_pack_out;
	uint16_t *TR;
	int i;
	int j;

	pdin = (unsigned int*) hndVITDecoder->pInBuffer;
	data_pack_out = hndVITDecoder->pOutBuffer;
	TR = hndVITDecoder->pTransitionHistory;
	bm_sel[0]=hndVITDecoder->pBMSELInit[0];
	codebit = (hndVITDecoder->nBits / hndVITDecoder->codeRate);
	statemask=2<<(hndVITDecoder->nStates/2)-1;

	unsigned int TR1[codebit], TR0[codebit];

	// stage compute
	for (i = 0; i < codebit; i += 1) {
		din = pdin[i];
		decode_1stage_acs8_K4CR12(din,bm_sel, &TR1[i],&TR0[i]);
		if (((i + 1)% 128) == 0) {
			VITERBI_DECODER_rescaleK4CR12(hndVITDecoder);
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
		data_pack_out[traceblk * 2 +1] = dout;
		data_pack_out[traceblk * 2 ] = dout >> 16;
	}

	for (i = tracebit,j=0; i < codebit; i += 1,j+=1) {
		tr1 = TR1[codebit - i - 1];
		tr0 = TR0[codebit - i - 1];
		__builtin_riscv_vitmovout64(28, tr0, tr1);
		__builtin_riscv_vittrace(2, 0);
		if (((j + 1) % 32) == 0) {
			dout = __builtin_riscv_vitmovin32(2);
			data_pack_out[traceblk * 2-(j/32)*2-1] = dout;
			data_pack_out[traceblk * 2-(j/32)*2-2] = dout >> 16;
		}
	}

//	for (i = 0; i < codebit; i += 1) {
//		data_pack_out[i] = ((data_pack_out[i] >> 8) & 0xff) | ((data_pack_out[i] << 8) &0xff00);
//
//	}

	for (i = 0; i < codebit; i += 1){
		TR[i]=((TR0[i]&statemask)<<4)|(TR1[i]&statemask);
	}

}
void VITERBI_DECODER_rescaleK4CR12(VITERBI_DECODER_Handle hndVITDecoder)
{
	unsigned int state;
	unsigned int state0;
	unsigned int tmpstate[8];
	int i;

	state = __builtin_riscv_vitmovin32(0);
	tmpstate[0] = state & 0xffff;
	tmpstate[1] = (state >> 16) & 0xffff;
	state = __builtin_riscv_vitmovin32(2);
	tmpstate[2] = state & 0xffff;
	tmpstate[3] = (state >> 16) & 0xffff;
	state = __builtin_riscv_vitmovin32(4);
	tmpstate[4] = state & 0xffff;
	tmpstate[5] = (state >> 16) & 0xffff;
	state = __builtin_riscv_vitmovin32(6);
	tmpstate[6] = state & 0xffff;
	tmpstate[7] = (state >> 16) & 0xffff;

	state = tmpstate[0];
	for (i = 1; i < 8; i++)
	{
		if(tmpstate[i]<=state)
		{
			state=tmpstate[i];
		}
	}

	for(i=0;i<8;i++)
	{
		tmpstate[i]-=state;
	}

	for(i=0;i<2;i++)
	{
		state=(tmpstate[4*i]&0xffff)|((tmpstate[4*i+1]&0xffff)<<16);
		state0=(tmpstate[4*i+2]&0xffff)|((tmpstate[4*i+3]&0xffff)<<16);
	//	vitmovout64((unsigned long const )(4*i),state,state0);
		if(0 == i)
		{
			__builtin_riscv_vitmovout64(0,state,state0);
		}
		else
		{
			__builtin_riscv_vitmovout64(4,state,state0);
		}
	}
}
