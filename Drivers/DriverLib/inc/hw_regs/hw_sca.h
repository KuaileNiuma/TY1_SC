/**
 *************************************************************************************
 * @file hw_sca.c
 * @brief This file implements the function of hw_sca driver.
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

#ifndef REG_SCA_H
#define REG_SCA_H

//*************************************************************************************************
//
// The following are defines for the SCA register offsets
//
//*************************************************************************************************
#define SCA_CTRL              0x0U
#define SCA_DMA               0x4U
#define SCA_STAT              0x8U
#define SCA_INTRAW            0x10U
#define SCA_INTRAWCLR         0x14U
#define SCA_INTEN             0x18U
#define SCA_INTSTAT           0x1CU
#define SCA_DIN0              0x20U
#define SCA_DIN1              0x24U
#define SCA_DIN2              0x28U
#define SCA_DIN3              0x2CU
#define SCA_DIN4              0x30U
#define SCA_DIN5              0x34U
#define SCA_DIN6              0x38U
#define SCA_DIN7              0x3CU
#define SCA_DOUT0             0x40U
#define SCA_DOUT1             0x44U
#define SCA_DOUT2             0x48U
#define SCA_DOUT3             0x4CU
#define SCA_DOUT4             0x50U
#define SCA_DOUT5             0x54U
#define SCA_DOUT6             0x58U
#define SCA_DOUT7             0x5CU
#define SCA_KEY               0x60U
#define SCA_IVR               0x64U
#define SCA_RDNSED            0x68U
#define SCA_FSLOCKREG         0x70U
#define SCA_FSCTRLREG         0x74U
#define SCA_FSDATAREG         0x78U
#define SCA_FSINFOREG         0x7CU

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRL register
//
//*************************************************************************************************
#define SCA_CTRL_EN           0x1U
#define SCA_CTRL_ALGOMODE_S   1U
#define SCA_CTRL_ALGOMODE_M   0xEU
#define SCA_CTRL_ALGODIR_S    4U
#define SCA_CTRL_ALGODIR_M    0x30U
#define SCA_CTRL_FBMODE_S     6U
#define SCA_CTRL_FBMODE_M     0x1C0U
#define SCA_CTRL_DATATYPE_S   9U
#define SCA_CTRL_DATATYPE_M   0x600U
#define SCA_CTRL_XCMPHASE_S   11U
#define SCA_CTRL_XCMPHASE_M   0x1800U


//*************************************************************************************************
//
// The following are defines for the bit fields in the DMA register
//
//*************************************************************************************************
#define SCA_DMA_INEN              0x1U
#define SCA_DMA_OUTEN             0x2U


//*************************************************************************************************
//
// The following are defines for the bit fields in the STAT register
//
//*************************************************************************************************
#define SCA_STAT_BUSYF            0x1U
#define SCA_STAT_INFIFOEMPTY      0x2U
#define SCA_STAT_INFIFOFULL       0x4U
#define SCA_STAT_OUTFIFOEMPTY     0x8U
#define SCA_STAT_OUTFIFOFULL      0x10U

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_RAW register
//
//*************************************************************************************************
#define SCA_INTRAW_CCF            0x1U
#define SCA_INTRAW_ERR            0x2U

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_RAW_CLR register
//
//*************************************************************************************************
#define SCA_INTRAWCLR_CCF         0x1U
#define SCA_INTRAWCLR_ERR         0x2U


//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_EN register
//
//*************************************************************************************************
#define SCA_INTEN_CCF         0x1U
#define SCA_INTEN_ERR         0x2U

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_STAT register
//
//*************************************************************************************************
#define SCA_INTSTAT_CCF         0x1U
#define SCA_INTSTAT_ERR         0x2U


//*************************************************************************************************
//
// The following are defines for the bit fields in the FSCTRL_REG register
//
//*************************************************************************************************
#define SCA_FSCTRLREG_TARGET_S  8U
#define SCA_FSCTRLREG_TARGET_M  0xFF00U
#define SCA_FSCTRLREG_ID_S  16U
#define SCA_FSCTRLREG_ID_M  0xFFFF0000U




#endif
