/** 
  ************************************************************************************* 
  * @file qspi.h 
  * @brief This file contains the definition of qspi driver. 
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

#ifndef __QSPI_H
#define __QSPI_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif


/* Includes ------------------------------------------------------------------*/

#include "hw_common.h"
#include "hw_qspi.h"

 typedef struct
 {
   uint32_t QSPI_ClockPhase;

   uint32_t QSPI_ClockPolarity;

 	uint32_t QSPI_DataFrameSize;

 	uint16_t QSPI_Clk_Div;
 }QSPI_InitTypeDef;

 /**
   * @brief  QSPI XIP Init structure definition
   */

 typedef struct
 {
 	uint32_t QSPI_XIP_FRF;

 	uint16_t QSPI_XIP_INCR_INST;

 	uint16_t QSPI_XIP_WRAP_INST;

 	uint32_t QSPI_XIP_Trans_Type;

 	uint32_t QSPI_XIP_Addr_Length;

 	uint32_t QSPI_XIP_Inst_Length;

 	uint32_t QSPI_XIP_Wait_Cycles;

 	uint32_t QSPI_XIP_Inst_EN;

 	uint32_t QSPI_XIP_Mode_Bits_EN;

 	uint32_t QSPI_XIP_Mode_Bits;

 	uint32_t QSPI_XIP_Mode_Bits_Length;
 }QSPI_XIP_InitTypeDef;



void QSPI_enableModule(uint32_t base);
void QSPI_disableModule(uint32_t base);
void QSPI_setMode(uint32_t base,uint32_t mode);
void QSPI_clearIntFlag(uint32_t base);
FlagStatus QSPI_checkIntFlag(uint32_t base,uint32_t flag);

void QSPI_Init(uint32_t base,QSPI_InitTypeDef* QSPI_InitStruct);

void QSPI_SSIEConfig(uint32_t base,FunctionalState NewState);
void QSPI_SSTEConfig(uint32_t base,FunctionalState NewState);
void QSPI_SetFrameNum(uint32_t base,uint16_t Num);
void QSPI_SetDataFrameSize(uint32_t base,uint32_t DataFrmSize);
void QSPI_SetFrameFormat(uint32_t base,uint32_t FrmFormat);
void QSPI_SetTransMode(uint32_t base,uint32_t TransMode);

uint8_t QSPI_ReadTxFIFOLevel(uint32_t base);
uint8_t QSPI_ReadRxFIFOLevel(uint32_t base);
void QSPI_SetRxFIFOFullThreshold(uint32_t base,uint32_t Threshold);
void QSPI_SetTxFIFOThreshold(uint32_t base,uint32_t Threshold);
void QSPI_SetTxFIFOEmptyThreshold(uint32_t base,uint8_t Threshold);

void QSPI_SetRxDMALevelFullThreshold(uint32_t base,uint8_t Threshold);
void QSPI_SetTxDMALevelEmptyThreshold(uint32_t base,uint8_t Threshold);

FlagStatus QSPI_GetFlagStatus(uint32_t base,uint32_t QSPI_FLAG);

void QSPI_SetRxSampleEdge(uint32_t base,uint32_t SampleEdge);
void QSPI_SetRxSampleDelay(uint32_t base,uint8_t Delay);

void QSPI_SetInstLen(uint32_t base,uint32_t Len);
void QSPI_SetAddrLen(uint32_t base,uint32_t Len);
void QSPI_SetInstAddrType(uint32_t base,uint32_t Type);
void QSPI_SetWaitCycle(uint32_t base,uint8_t Cycle);

void QSPI_RxDataU8(uint32_t base,uint8_t *Data);
void QSPI_TxDataU8(uint32_t base,uint8_t *Data);
void QSPI_RxDataU16(uint32_t base,uint16_t *Data);
void QSPI_TxDataU16(uint32_t base,uint16_t *Data);
void QSPI_RxDataU32(uint32_t base,uint32_t *Data);
void QSPI_TxDataU32(uint32_t base,uint32_t *Data);
void QSPI_TxInsAddr(uint32_t base,uint32_t InsOrAddr);
void QSPI_SlaveConfig(uint32_t base,FunctionalState NewState);
void QSPI_TxDMAConfig(uint32_t base,FunctionalState NewState);
void QSPI_RxDMAConfig(uint32_t base,FunctionalState NewState);

void QSPI_SRLConfig(uint32_t base,FunctionalState NewState);
void QSPI_XIP_Init(uint32_t base,QSPI_XIP_InitTypeDef* QSPI_XIP_InitStruct);
void QSPI_configXIP(uint32_t base,FunctionalState NewState);
void QSPI_enableInterrupt(uint32_t base,uint32_t intFlag);
void QSPI_disableInterrupt(uint32_t base,uint32_t intFlag);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /*__QSPI_H */


