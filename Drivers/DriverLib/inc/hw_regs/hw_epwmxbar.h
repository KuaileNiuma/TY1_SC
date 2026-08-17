/** 
  ************************************************************************************* 
  * @file hw_epwmxbar.h 
  * @brief This file contains the definition of hw_epwmxbar driver. 
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
  
#ifndef HW_EPWMXBAR_H
#define HW_EPWMXBAR_H

#if XBAR_HW_VER == 0x00
//*************************************************************************************************
//
// The following are defines for the XBAR register offsets
//
//*************************************************************************************************
#define XBAR_O_TRIP4MUX0TO15CFG     0x200U    // ePWM XBAR Mux Configuration for TRIP4
#define XBAR_O_TRIP4MUX16TO31CFG    0x204U    // ePWM XBAR Mux Configuration for TRIP4
#define XBAR_O_TRIP5MUX0TO15CFG     0x208U    // ePWM XBAR Mux Configuration for TRIP5
#define XBAR_O_TRIP5MUX16TO31CFG    0x20CU    // ePWM XBAR Mux Configuration for TRIP5
#define XBAR_O_TRIP7MUX0TO15CFG     0x210U   // ePWM XBAR Mux Configuration for TRIP7
#define XBAR_O_TRIP7MUX16TO31CFG    0x214U   // ePWM XBAR Mux Configuration for TRIP7
#define XBAR_O_TRIP8MUX0TO15CFG     0x218U   // ePWM XBAR Mux Configuration for TRIP8
#define XBAR_O_TRIP8MUX16TO31CFG    0x21CU   // ePWM XBAR Mux Configuration for TRIP8
#define XBAR_O_TRIP9MUX0TO15CFG     0x220U   // ePWM XBAR Mux Configuration for TRIP9
#define XBAR_O_TRIP9MUX16TO31CFG    0x224U   // ePWM XBAR Mux Configuration for TRIP9
#define XBAR_O_TRIP10MUX0TO15CFG    0x228U   // ePWM XBAR Mux Configuration for TRIP10
#define XBAR_O_TRIP10MUX16TO31CFG   0x22CU   // ePWM XBAR Mux Configuration for TRIP10
#define XBAR_O_TRIP11MUX0TO15CFG    0x230U   // ePWM XBAR Mux Configuration for TRIP11
#define XBAR_O_TRIP11MUX16TO31CFG   0x234U   // ePWM XBAR Mux Configuration for TRIP11
#define XBAR_O_TRIP12MUX0TO15CFG    0x238U   // ePWM XBAR Mux Configuration for TRIP12
#define XBAR_O_TRIP12MUX16TO31CFG   0x23CU   // ePWM XBAR Mux Configuration for TRIP12
#define XBAR_O_TRIP4MUXENABLE       0x240U   // ePWM XBAR Mux Enable for TRIP4
#define XBAR_O_TRIP5MUXENABLE       0x244U   // ePWM XBAR Mux Enable for TRIP5
#define XBAR_O_TRIP7MUXENABLE       0x248U   // ePWM XBAR Mux Enable for TRIP7
#define XBAR_O_TRIP8MUXENABLE       0x24CU   // ePWM XBAR Mux Enable for TRIP8
#define XBAR_O_TRIP9MUXENABLE       0x250U   // ePWM XBAR Mux Enable for TRIP9
#define XBAR_O_TRIP10MUXENABLE      0x254U   // ePWM XBAR Mux Enable for TRIP10
#define XBAR_O_TRIP11MUXENABLE      0x258U   // ePWM XBAR Mux Enable for TRIP11
#define XBAR_O_TRIP12MUXENABLE      0x25CU   // ePWM XBAR Mux Enable for TRIP12
#define XBAR_O_TRIPOUTINV           0x270U   // ePWM XBAR Output Inversion Register
#define XBAR_O_TRIPLOCK             0x27CU   // ePWM XBAR Configuration Lock register


//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP4MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP4MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP4MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP4MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP4MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP4MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP4MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP4MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP4MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP4MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP4MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP4MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP4MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP4MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP4MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP4MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP4MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP4MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP4MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP4MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP4MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP4MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP4MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP4MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP4MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP4MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP4MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP4MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP4MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP4MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP4MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP4MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP4MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP4MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP4MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP4 of
                                                       // EPWM-XBAR
#define XBAR_TRIP4MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP4MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP4 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP5MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP5MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP5MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP5MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP5MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP5MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP5MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP5MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP5MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP5MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP5MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP5MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP5MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP5MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP5MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP5MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP5MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP5MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP5 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP5MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP5MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP5MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP5MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP5MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP5MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP5MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP5MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP5MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP5MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP5MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP5MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP5MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP5MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP5MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP5MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP5MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP5 of
                                                       // EPWM-XBAR
#define XBAR_TRIP5MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP5MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP5 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP7MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP7MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP7MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP7MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP7MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP7MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP7MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP7MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP7MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP7MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP7MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP7MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP7MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP7MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP7MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP7MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP7MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP7MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP7MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP7MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP7MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP7MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP7MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP7MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP7MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP7MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP7MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP7MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP7MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP7MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP7MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP7MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP7MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP7MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP7MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP7 of
                                                       // EPWM-XBAR
#define XBAR_TRIP7MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP7MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP7 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP8MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP8MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP8MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP8MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP8MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP8MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP8MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP8MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP8MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP8MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP8MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP8MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP8MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP8MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP8MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP8MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP8MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP8MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP8 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP8MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP8MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP8MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP8MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP8MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP8MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP8MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP8MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP8MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP8MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP8MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP8MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP8MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP8MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP8MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP8MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP8MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP8 of
                                                       // EPWM-XBAR
#define XBAR_TRIP8MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP8MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP8 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP9MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP9MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP9MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP9MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP9MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP9MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP9MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP9MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP9MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP9MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP9MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP9MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP9MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP9MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP9MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP9MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP9MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP9MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP9 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP9MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP9MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP9MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP9MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP9MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP9MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP9MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP9MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP9MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP9MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP9MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP9MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP9MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP9MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP9MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP9MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP9MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP9 of
                                                       // EPWM-XBAR
#define XBAR_TRIP9MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP9MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP9 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP10MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP10MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP10MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP10MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP10MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP10MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP10MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP10MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP10MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP10MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP10MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP10MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP10MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP10MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP10MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP10MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP10MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP10 of
                                                       // EPWM-XBAR
#define XBAR_TRIP10MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP10MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP10 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP10MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP10MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP10MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP10MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP10MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP10MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP10MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP10MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP10MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP10MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP10MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP10MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP10MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP10MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP10MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP10MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP10MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP10 of
                                                        // EPWM-XBAR
#define XBAR_TRIP10MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP10MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP10 of
                                                        // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP11MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP11MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP11MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP11MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP11MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP11MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP11MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP11MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP11MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP11MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP11MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP11MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP11MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP11MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP11MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP11MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP11MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP11 of
                                                       // EPWM-XBAR
#define XBAR_TRIP11MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP11MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP11 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP11MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP11MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP11MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP11MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP11MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP11MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP11MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP11MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP11MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP11MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP11MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP11MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP11MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP11MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP11MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP11MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP11MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP11 of
                                                        // EPWM-XBAR
#define XBAR_TRIP11MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP11MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP11 of
                                                        // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP12MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_TRIP12MUX0TO15CFG_MUX0_S    0U
#define XBAR_TRIP12MUX0TO15CFG_MUX0_M    0x3U          // Mux0 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX1_S    2U
#define XBAR_TRIP12MUX0TO15CFG_MUX1_M    0xCU          // Mux1 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX2_S    4U
#define XBAR_TRIP12MUX0TO15CFG_MUX2_M    0x30U         // Mux2 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX3_S    6U
#define XBAR_TRIP12MUX0TO15CFG_MUX3_M    0xC0U         // Mux3 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX4_S    8U
#define XBAR_TRIP12MUX0TO15CFG_MUX4_M    0x300U        // Mux4 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX5_S    10U
#define XBAR_TRIP12MUX0TO15CFG_MUX5_M    0xC00U        // Mux5 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX6_S    12U
#define XBAR_TRIP12MUX0TO15CFG_MUX6_M    0x3000U       // Mux6 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX7_S    14U
#define XBAR_TRIP12MUX0TO15CFG_MUX7_M    0xC000U       // Mux7 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX8_S    16U
#define XBAR_TRIP12MUX0TO15CFG_MUX8_M    0x30000U      // Mux8 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX9_S    18U
#define XBAR_TRIP12MUX0TO15CFG_MUX9_M    0xC0000U      // Mux9 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX10_S   20U
#define XBAR_TRIP12MUX0TO15CFG_MUX10_M   0x300000U     // Mux10 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX11_S   22U
#define XBAR_TRIP12MUX0TO15CFG_MUX11_M   0xC00000U     // Mux11 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX12_S   24U
#define XBAR_TRIP12MUX0TO15CFG_MUX12_M   0x3000000U    // Mux12 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX13_S   26U
#define XBAR_TRIP12MUX0TO15CFG_MUX13_M   0xC000000U    // Mux13 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX14_S   28U
#define XBAR_TRIP12MUX0TO15CFG_MUX14_M   0x30000000U   // Mux14 Configuration for TRIP12 of
                                                       // EPWM-XBAR
#define XBAR_TRIP12MUX0TO15CFG_MUX15_S   30U
#define XBAR_TRIP12MUX0TO15CFG_MUX15_M   0xC0000000U   // Mux15 Configuration for TRIP12 of
                                                       // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP12MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_TRIP12MUX16TO31CFG_MUX16_S   0U
#define XBAR_TRIP12MUX16TO31CFG_MUX16_M   0x3U          // Mux16 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX17_S   2U
#define XBAR_TRIP12MUX16TO31CFG_MUX17_M   0xCU          // Mux17 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX18_S   4U
#define XBAR_TRIP12MUX16TO31CFG_MUX18_M   0x30U         // Mux18 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX19_S   6U
#define XBAR_TRIP12MUX16TO31CFG_MUX19_M   0xC0U         // Mux19 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX20_S   8U
#define XBAR_TRIP12MUX16TO31CFG_MUX20_M   0x300U        // Mux20 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX21_S   10U
#define XBAR_TRIP12MUX16TO31CFG_MUX21_M   0xC00U        // Mux21 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX22_S   12U
#define XBAR_TRIP12MUX16TO31CFG_MUX22_M   0x3000U       // Mux22 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX23_S   14U
#define XBAR_TRIP12MUX16TO31CFG_MUX23_M   0xC000U       // Mux23 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX24_S   16U
#define XBAR_TRIP12MUX16TO31CFG_MUX24_M   0x30000U      // Mux24 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX25_S   18U
#define XBAR_TRIP12MUX16TO31CFG_MUX25_M   0xC0000U      // Mux25 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX26_S   20U
#define XBAR_TRIP12MUX16TO31CFG_MUX26_M   0x300000U     // Mux26 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX27_S   22U
#define XBAR_TRIP12MUX16TO31CFG_MUX27_M   0xC00000U     // Mux27 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX28_S   24U
#define XBAR_TRIP12MUX16TO31CFG_MUX28_M   0x3000000U    // Mux28 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX29_S   26U
#define XBAR_TRIP12MUX16TO31CFG_MUX29_M   0xC000000U    // Mux29 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX30_S   28U
#define XBAR_TRIP12MUX16TO31CFG_MUX30_M   0x30000000U   // Mux30 Configuration for TRIP12 of
                                                        // EPWM-XBAR
#define XBAR_TRIP12MUX16TO31CFG_MUX31_S   30U
#define XBAR_TRIP12MUX16TO31CFG_MUX31_M   0xC0000000U   // Mux31 Configuration for TRIP12 of
                                                        // EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP4MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP4MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP4 of EPWM-XBAR
#define XBAR_TRIP4MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP5MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP5MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP5 of EPWM-XBAR
#define XBAR_TRIP5MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP5 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP7MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP7MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP7 of EPWM-XBAR
#define XBAR_TRIP7MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP8MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP8MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP8 of EPWM-XBAR
#define XBAR_TRIP8MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP8 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP9MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP9MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP9 of EPWM-XBAR
#define XBAR_TRIP9MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP9 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP10MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP10MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP10 of EPWM-XBAR
#define XBAR_TRIP10MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP10 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP11MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP11MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP11 of EPWM-XBAR
#define XBAR_TRIP11MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP11 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIP12MUXENABLE register
//
//*************************************************************************************************
#define XBAR_TRIP12MUXENABLE_MUX0    0x1U          // mux0 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX1    0x2U          // Mux1 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX2    0x4U          // Mux2 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX3    0x8U          // Mux3 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX4    0x10U         // Mux4 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX5    0x20U         // Mux5 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX6    0x40U         // Mux6 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX7    0x80U         // Mux7 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX8    0x100U        // Mux8 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX9    0x200U        // Mux9 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX10   0x400U        // Mux10 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX11   0x800U        // Mux11 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX12   0x1000U       // Mux12 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX13   0x2000U       // Mux13 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX14   0x4000U       // Mux14 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX15   0x8000U       // Mux15 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX16   0x10000U      // Mux16 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX17   0x20000U      // Mux17 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX18   0x40000U      // Mux18 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX19   0x80000U      // Mux19 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX20   0x100000U     // Mux20 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX21   0x200000U     // Mux21 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX22   0x400000U     // Mux22 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX23   0x800000U     // Mux23 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX24   0x1000000U    // Mux24 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX25   0x2000000U    // Mux25 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX26   0x4000000U    // Mux26 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX27   0x8000000U    // Mux27 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX28   0x10000000U   // Mux28 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX29   0x20000000U   // Mux29 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX30   0x40000000U   // Mux30 to drive TRIP12 of EPWM-XBAR
#define XBAR_TRIP12MUXENABLE_MUX31   0x80000000U   // Mux31 to drive TRIP12 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIPOUTINV register
//
//*************************************************************************************************
#define XBAR_TRIPOUTINV_TRIP4    0x1U    // Selects polarity for TRIP4 of EPWM-XBAR
#define XBAR_TRIPOUTINV_TRIP5    0x2U    // Selects polarity for TRIP5 of EPWM-XBAR
#define XBAR_TRIPOUTINV_TRIP7    0x4U    // Selects polarity for TRIP7 of EPWM-XBAR
#define XBAR_TRIPOUTINV_TRIP8    0x8U    // Selects polarity for TRIP8 of EPWM-XBAR
#define XBAR_TRIPOUTINV_TRIP9    0x10U   // Selects polarity for TRIP9 of EPWM-XBAR
#define XBAR_TRIPOUTINV_TRIP10   0x20U   // Selects polarity for TRIP10 of EPWM-XBAR
#define XBAR_TRIPOUTINV_TRIP11   0x40U   // Selects polarity for TRIP11 of EPWM-XBAR
#define XBAR_TRIPOUTINV_TRIP12   0x80U   // Selects polarity for TRIP12 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIPLOCK register
//
//*************************************************************************************************
#define XBAR_TRIPLOCK_LOCK    0x1U          // Locks the configuration for EPWM-XBAR
#define XBAR_TRIPLOCK_KEY_S   16U
#define XBAR_TRIPLOCK_KEY_M   0xFFFF0000U   // Write protection KEY

#elif XBAR_HW_VER == 0x01


//*************************************************************************************************
//
// The following are defines for the XBAR register offsets
//
//*************************************************************************************************

#ifndef XBAR_REGS_H
#define XBAR_REGS_H

//###########################################################################
// XBAR Output MUX Configuration Registers (OUT1 ~ OUT16)
// Base Start Address: 0x200
// Each OUT group size: 0x10 (16 bytes)
//###########################################################################

#define XBAR_O_OUT1MUX0TO15CFG        0x200U     // Output 1 Mux Config (0-15)
#define XBAR_O_OUT1MUX16TO31CFG       0x204U     // Output 1 Mux Config (16-31)
#define XBAR_O_OUT1MUX32TO47CFG       0x208U     // Output 1 Mux Config (32-47)
#define XBAR_O_OUT1MUX48TO63CFG       0x20CU     // Output 1 Mux Config (48-63)

#define XBAR_O_OUT2MUX0TO15CFG        0x210U     // Output 2 Mux Config (0-15)
#define XBAR_O_OUT2MUX16TO31CFG       0x214U     // Output 2 Mux Config (16-31)
#define XBAR_O_OUT2MUX32TO47CFG       0x218U     // Output 2 Mux Config (32-47)
#define XBAR_O_OUT2MUX48TO63CFG       0x21CU     // Output 2 Mux Config (48-63)

#define XBAR_O_OUT3MUX0TO15CFG        0x220U     // Output 3 Mux Config (0-15)
#define XBAR_O_OUT3MUX16TO31CFG       0x224U     // Output 3 Mux Config (16-31)
#define XBAR_O_OUT3MUX32TO47CFG       0x228U     // Output 3 Mux Config (32-47)
#define XBAR_O_OUT3MUX48TO63CFG       0x22CU     // Output 3 Mux Config (48-63)

#define XBAR_O_OUT4MUX0TO15CFG        0x230U     // Output 4 Mux Config (0-15)
#define XBAR_O_OUT4MUX16TO31CFG       0x234U     // Output 4 Mux Config (16-31)
#define XBAR_O_OUT4MUX32TO47CFG       0x238U     // Output 4 Mux Config (32-47)
#define XBAR_O_OUT4MUX48TO63CFG       0x23CU     // Output 4 Mux Config (48-63)

#define XBAR_O_OUT5MUX0TO15CFG        0x240U     // Output 5 Mux Config (0-15)
#define XBAR_O_OUT5MUX16TO31CFG       0x244U     // Output 5 Mux Config (16-31)
#define XBAR_O_OUT5MUX32TO47CFG       0x248U     // Output 5 Mux Config (32-47)
#define XBAR_O_OUT5MUX48TO63CFG       0x24CU     // Output 5 Mux Config (48-63)

#define XBAR_O_OUT6MUX0TO15CFG        0x250U     // Output 6 Mux Config (0-15)
#define XBAR_O_OUT6MUX16TO31CFG       0x254U     // Output 6 Mux Config (16-31)
#define XBAR_O_OUT6MUX32TO47CFG       0x258U     // Output 6 Mux Config (32-47)
#define XBAR_O_OUT6MUX48TO63CFG       0x25CU     // Output 6 Mux Config (48-63)

#define XBAR_O_OUT7MUX0TO15CFG        0x260U     // Output 7 Mux Config (0-15)
#define XBAR_O_OUT7MUX16TO31CFG       0x264U     // Output 7 Mux Config (16-31)
#define XBAR_O_OUT7MUX32TO47CFG       0x268U     // Output 7 Mux Config (32-47)
#define XBAR_O_OUT7MUX48TO63CFG       0x26CU     // Output 7 Mux Config (48-63)

#define XBAR_O_OUT8MUX0TO15CFG        0x270U     // Output 8 Mux Config (0-15)
#define XBAR_O_OUT8MUX16TO31CFG       0x274U     // Output 8 Mux Config (16-31)
#define XBAR_O_OUT8MUX32TO47CFG       0x278U     // Output 8 Mux Config (32-47)
#define XBAR_O_OUT8MUX48TO63CFG       0x27CU     // Output 8 Mux Config (48-63)

#define XBAR_O_OUT9MUX0TO15CFG        0x280U     // Output 9 Mux Config (0-15)
#define XBAR_O_OUT9MUX16TO31CFG       0x284U     // Output 9 Mux Config (16-31)
#define XBAR_O_OUT9MUX32TO47CFG       0x288U     // Output 9 Mux Config (32-47)
#define XBAR_O_OUT9MUX48TO63CFG       0x28CU     // Output 9 Mux Config (48-63)

#define XBAR_O_OUT10MUX0TO15CFG       0x290U     // Output 10 Mux Config (0-15)
#define XBAR_O_OUT10MUX16TO31CFG      0x294U     // Output 10 Mux Config (16-31)
#define XBAR_O_OUT10MUX32TO47CFG      0x298U     // Output 10 Mux Config (32-47)
#define XBAR_O_OUT10MUX48TO63CFG      0x29CU     // Output 10 Mux Config (48-63)

#define XBAR_O_OUT11MUX0TO15CFG       0x2A0U     // Output 11 Mux Config (0-15)
#define XBAR_O_OUT11MUX16TO31CFG      0x2A4U     // Output 11 Mux Config (16-31)
#define XBAR_O_OUT11MUX32TO47CFG      0x2A8U     // Output 11 Mux Config (32-47)
#define XBAR_O_OUT11MUX48TO63CFG      0x2ACU     // Output 11 Mux Config (48-63)

#define XBAR_O_OUT12MUX0TO15CFG       0x2B0U     // Output 12 Mux Config (0-15)
#define XBAR_O_OUT12MUX16TO31CFG      0x2B4U     // Output 12 Mux Config (16-31)
#define XBAR_O_OUT12MUX32TO47CFG      0x2B8U     // Output 12 Mux Config (32-47)
#define XBAR_O_OUT12MUX48TO63CFG      0x2BCU     // Output 12 Mux Config (48-63)

#define XBAR_O_OUT13MUX0TO15CFG       0x2C0U     // Output 13 Mux Config (0-15)
#define XBAR_O_OUT13MUX16TO31CFG      0x2C4U     // Output 13 Mux Config (16-31)
#define XBAR_O_OUT13MUX32TO47CFG      0x2C8U     // Output 13 Mux Config (32-47)
#define XBAR_O_OUT13MUX48TO63CFG      0x2CCU     // Output 13 Mux Config (48-63)

#define XBAR_O_OUT14MUX0TO15CFG       0x2D0U     // Output 14 Mux Config (0-15)
#define XBAR_O_OUT14MUX16TO31CFG      0x2D4U     // Output 14 Mux Config (16-31)
#define XBAR_O_OUT14MUX32TO47CFG      0x2D8U     // Output 14 Mux Config (32-47)
#define XBAR_O_OUT14MUX48TO63CFG      0x2DCU     // Output 14 Mux Config (48-63)

#define XBAR_O_OUT15MUX0TO15CFG       0x2E0U     // Output 15 Mux Config (0-15)
#define XBAR_O_OUT15MUX16TO31CFG      0x2E4U     // Output 15 Mux Config (16-31)
#define XBAR_O_OUT15MUX32TO47CFG      0x2E8U     // Output 15 Mux Config (32-47)
#define XBAR_O_OUT15MUX48TO63CFG      0x2ECU     // Output 15 Mux Config (48-63)

#define XBAR_O_OUT16MUX0TO15CFG       0x2F0U     // Output 16 Mux Config (0-15)
#define XBAR_O_OUT16MUX16TO31CFG      0x2F4U     // Output 16 Mux Config (16-31)
#define XBAR_O_OUT16MUX32TO47CFG      0x2F8U     // Output 16 Mux Config (32-47)
#define XBAR_O_OUT16MUX48TO63CFG      0x2FCU     // Output 16 Mux Config (48-63)


//###########################################################################
// XBAR Output MUX Enable Registers (OUT1 ~ OUT16)
// Base Start Address: 0x300
// Each OUT group size: 0x08 (8 bytes)
//###########################################################################

#define XBAR_O_OUT1MUXENABLE          0x300U     // Output 1 Mux Enable (0-31)
#define XBAR_O_OUT1MUXENABLE32TO64    0x304U     // Output 1 Mux Enable (32-64)

#define XBAR_O_OUT2MUXENABLE          0x308U
#define XBAR_O_OUT2MUXENABLE32TO64    0x30CU

#define XBAR_O_OUT3MUXENABLE          0x310U
#define XBAR_O_OUT3MUXENABLE32TO64    0x314U

#define XBAR_O_OUT4MUXENABLE          0x318U
#define XBAR_O_OUT4MUXENABLE32TO64    0x31CU

#define XBAR_O_OUT5MUXENABLE          0x320U
#define XBAR_O_OUT5MUXENABLE32TO64    0x324U

#define XBAR_O_OUT6MUXENABLE          0x328U
#define XBAR_O_OUT6MUXENABLE32TO64    0x32CU

#define XBAR_O_OUT7MUXENABLE          0x330U
#define XBAR_O_OUT7MUXENABLE32TO64    0x334U

#define XBAR_O_OUT8MUXENABLE          0x338U
#define XBAR_O_OUT8MUXENABLE32TO64    0x33CU

#define XBAR_O_OUT9MUXENABLE          0x340U
#define XBAR_O_OUT9MUXENABLE32TO64    0x344U

#define XBAR_O_OUT10MUXENABLE         0x348U
#define XBAR_O_OUT10MUXENABLE32TO64   0x34CU

#define XBAR_O_OUT11MUXENABLE         0x350U
#define XBAR_O_OUT11MUXENABLE32TO64   0x354U

#define XBAR_O_OUT12MUXENABLE         0x358U
#define XBAR_O_OUT12MUXENABLE32TO64   0x35CU

#define XBAR_O_OUT13MUXENABLE         0x360U
#define XBAR_O_OUT13MUXENABLE32TO64   0x364U

#define XBAR_O_OUT14MUXENABLE         0x368U
#define XBAR_O_OUT14MUXENABLE32TO64   0x36CU

#define XBAR_O_OUT15MUXENABLE         0x370U
#define XBAR_O_OUT15MUXENABLE32TO64   0x374U

#define XBAR_O_OUT16MUXENABLE         0x378U
#define XBAR_O_OUT16MUXENABLE32TO64   0x37CU


//###########################################################################
// TRIP Registers & LOCK Registers
//###########################################################################

#define XBAR_O_TRIPOUTINV             0x390U     // Trip Output Inversion
#define XBAR_O_TRIPLOCK               0x39CU     // Trip Configuration Lock

#endif  // XBAR_REGS_H




//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT1MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT1MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT1MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT1MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT1MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT1MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT1MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT1MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT1MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT1MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT1MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT1MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT1MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT1MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT1MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT1MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT1MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT1MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT1 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT1MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT1MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT1MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT1MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT1MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT1MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT1MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT1MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT1MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT1MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT1MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT1MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT1MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT1MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT1MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT1MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT1MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT1MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT1 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT1MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT1MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT1MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT1MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT1MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT1MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT1MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT1MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT1MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT1MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT1MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT1MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT1MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT1MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT1MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT1MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT1MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT1MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT1MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT1MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT1MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT1MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT1MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT1MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT1MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT1MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT1MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT1MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT1MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT1MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT1MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT1MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT1MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT1MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT1MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT1MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT1 of EPWM-XBAR
#define XBAR_OUT1MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT1MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT1 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT2MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT2MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT2MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT2MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT2MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT2MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT2MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT2MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT2MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT2MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT2MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT2MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT2MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT2MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT2MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT2MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT2MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT2MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT2 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT2MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT2MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT2MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT2MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT2MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT2MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT2MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT2MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT2MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT2MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT2MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT2MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT2MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT2MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT2MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT2MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT2MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT2MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT2 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT2MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT2MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT2MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT2MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT2MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT2MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT2MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT2MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT2MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT2MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT2MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT2MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT2MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT2MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT2MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT2MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT2MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT2MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT2MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT2MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT2MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT2MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT2MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT2MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT2MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT2MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT2MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT2MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT2MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT2MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT2MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT2MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT2MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT2MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT2MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT2MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT2 of EPWM-XBAR
#define XBAR_OUT2MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT2MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT2 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT3MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT3MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT3MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT3MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT3MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT3MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT3MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT3MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT3MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT3MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT3MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT3MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT3MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT3MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT3MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT3MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT3MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT3MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT3 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT3MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT3MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT3MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT3MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT3MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT3MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT3MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT3MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT3MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT3MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT3MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT3MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT3MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT3MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT3MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT3MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT3MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT3MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT3 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT3MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT3MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT3MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT3MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT3MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT3MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT3MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT3MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT3MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT3MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT3MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT3MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT3MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT3MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT3MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT3MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT3MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT3MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT3MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT3MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT3MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT3MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT3MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT3MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT3MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT3MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT3MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT3MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT3MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT3MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT3MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT3MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT3MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT3MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT3MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT3MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT3 of EPWM-XBAR
#define XBAR_OUT3MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT3MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT3 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT4MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT4MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT4MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT4MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT4MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT4MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT4MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT4MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT4MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT4MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT4MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT4MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT4MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT4MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT4MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT4MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT4MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT4MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT4MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT4MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT4MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT4MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT4MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT4MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT4MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT4MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT4MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT4MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT4MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT4MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT4MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT4MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT4MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT4MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT4MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT4MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT4MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT4MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT4MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT4MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT4MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT4MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT4MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT4MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT4MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT4MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT4MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT4MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT4MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT4MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT4MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT4MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT4MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT4MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT4MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT4MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT4MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT4MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT4MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT4MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT4MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT4MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT4MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT4MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT4MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT4MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT4MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT4MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT4MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT4MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT4MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT4MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT4 of EPWM-XBAR
#define XBAR_OUT4MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT4MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT5MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT5MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT5MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT5MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT5MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT5MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT5MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT5MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT5MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT5MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT5MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT5MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT5MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT5MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT5MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT5MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT5MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT5MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT5 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT5MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT5MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT5MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT5MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT5MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT5MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT5MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT5MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT5MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT5MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT5MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT5MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT5MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT5MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT5MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT5MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT5MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT5MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT5 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT5MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT5MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT5MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT5MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT5MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT5MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT5MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT5MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT5MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT5MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT5MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT5MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT5MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT5MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT5MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT5MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT5MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT5MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT5MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT5MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT5MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT5MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT5MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT5MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT5MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT5MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT5MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT5MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT5MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT5MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT5MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT5MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT5MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT5MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT5MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT5MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT5 of EPWM-XBAR
#define XBAR_OUT5MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT5MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT5 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT6MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT6MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT6MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT6MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT6MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT6MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT6MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT6MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT6MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT6MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT6MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT6MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT6MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT6MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT6MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT6MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT6MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT6MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT6 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT6MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT6MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT6MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT6MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT6MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT6MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT6MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT6MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT6MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT6MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT6MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT6MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT6MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT6MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT6MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT6MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT6MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT6MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT6 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT6MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT6MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT6MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT6MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT6MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT6MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT6MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT6MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT6MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT6MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT6MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT6MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT6MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT6MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT6MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT6MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT6MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT6MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT6MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT6MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT6MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT6MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT6MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT6MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT6MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT6MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT6MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT6MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT6MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT6MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT6MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT6MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT6MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT6MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT6MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT6MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT6 of EPWM-XBAR
#define XBAR_OUT6MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT6MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT6 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT7MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT7MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT7MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT7MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT7MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT7MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT7MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT7MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT7MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT7MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT7MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT7MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT7MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT7MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT7MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT7MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT7MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT7MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT7MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT7MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT7MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT7MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT7MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT7MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT7MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT7MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT7MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT7MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT7MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT7MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT7MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT7MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT7MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT7MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT7MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT7MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT7MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT7MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT7MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT7MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT7MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT7MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT7MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT7MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT7MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT7MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT7MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT7MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT7MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT7MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT7MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT7MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT7MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT7MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT7MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT7MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT7MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT7MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT7MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT7MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT7MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT7MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT7MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT7MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT7MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT7MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT7MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT7MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT7MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT7MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT7MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT7MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT7 of EPWM-XBAR
#define XBAR_OUT7MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT7MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT8MUX0TO15CFG register
//
//*************************************************************************************************
#define XBAR_OUT8MUX0TO15CFG_MUX0_S    0U
#define XBAR_OUT8MUX0TO15CFG_MUX0_M    0x3U          // MUX0 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX1_S    2U
#define XBAR_OUT8MUX0TO15CFG_MUX1_M    0xCU          // MUX1 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX2_S    4U
#define XBAR_OUT8MUX0TO15CFG_MUX2_M    0x30U         // MUX2 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX3_S    6U
#define XBAR_OUT8MUX0TO15CFG_MUX3_M    0xC0U         // MUX3 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX4_S    8U
#define XBAR_OUT8MUX0TO15CFG_MUX4_M    0x300U        // MUX4 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX5_S    10U
#define XBAR_OUT8MUX0TO15CFG_MUX5_M    0xC00U        // MUX5 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX6_S    12U
#define XBAR_OUT8MUX0TO15CFG_MUX6_M    0x3000U       // MUX6 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX7_S    14U
#define XBAR_OUT8MUX0TO15CFG_MUX7_M    0xC000U       // MUX7 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX8_S    16U
#define XBAR_OUT8MUX0TO15CFG_MUX8_M    0x30000U      // MUX8 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX9_S    18U
#define XBAR_OUT8MUX0TO15CFG_MUX9_M    0xC0000U      // MUX9 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX10_S   20U
#define XBAR_OUT8MUX0TO15CFG_MUX10_M   0x300000U     // MUX10 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX11_S   22U
#define XBAR_OUT8MUX0TO15CFG_MUX11_M   0xC00000U     // MUX11 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX12_S   24U
#define XBAR_OUT8MUX0TO15CFG_MUX12_M   0x3000000U    // MUX12 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX13_S   26U
#define XBAR_OUT8MUX0TO15CFG_MUX13_M   0xC000000U    // MUX13 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX14_S   28U
#define XBAR_OUT8MUX0TO15CFG_MUX14_M   0x30000000U   // MUX14 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX0TO15CFG_MUX15_S   30U
#define XBAR_OUT8MUX0TO15CFG_MUX15_M   0xC0000000U   // MUX15 Configuration for OUT8 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT8MUX16TO31CFG register
//
//*************************************************************************************************
#define XBAR_OUT8MUX16TO31CFG_MUX16_S   0U
#define XBAR_OUT8MUX16TO31CFG_MUX16_M   0x3U          // MUX16 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX17_S   2U
#define XBAR_OUT8MUX16TO31CFG_MUX17_M   0xCU          // MUX17 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX18_S   4U
#define XBAR_OUT8MUX16TO31CFG_MUX18_M   0x30U         // MUX18 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX19_S   6U
#define XBAR_OUT8MUX16TO31CFG_MUX19_M   0xC0U         // MUX19 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX20_S   8U
#define XBAR_OUT8MUX16TO31CFG_MUX20_M   0x300U        // MUX20 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX21_S   10U
#define XBAR_OUT8MUX16TO31CFG_MUX21_M   0xC00U        // MUX21 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX22_S   12U
#define XBAR_OUT8MUX16TO31CFG_MUX22_M   0x3000U       // MUX22 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX23_S   14U
#define XBAR_OUT8MUX16TO31CFG_MUX23_M   0xC000U       // MUX23 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX24_S   16U
#define XBAR_OUT8MUX16TO31CFG_MUX24_M   0x30000U      // MUX24 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX25_S   18U
#define XBAR_OUT8MUX16TO31CFG_MUX25_M   0xC0000U      // MUX25 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX26_S   20U
#define XBAR_OUT8MUX16TO31CFG_MUX26_M   0x300000U     // MUX26 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX27_S   22U
#define XBAR_OUT8MUX16TO31CFG_MUX27_M   0xC00000U     // MUX27 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX28_S   24U
#define XBAR_OUT8MUX16TO31CFG_MUX28_M   0x3000000U    // MUX28 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX29_S   26U
#define XBAR_OUT8MUX16TO31CFG_MUX29_M   0xC000000U    // MUX29 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX30_S   28U
#define XBAR_OUT8MUX16TO31CFG_MUX30_M   0x30000000U   // MUX30 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX16TO31CFG_MUX31_S   30U
#define XBAR_OUT8MUX16TO31CFG_MUX31_M   0xC0000000U   // MUX31 Configuration for OUT8 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT8MUX32TO47CFG register
//
//*************************************************************************************************
#define XBAR_OUT8MUX32TO47CFG_MUX32_S   0U
#define XBAR_OUT8MUX32TO47CFG_MUX32_M   0x3U          // MUX32 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX33_S   2U
#define XBAR_OUT8MUX32TO47CFG_MUX33_M   0xCU          // MUX33 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX34_S   4U
#define XBAR_OUT8MUX32TO47CFG_MUX34_M   0x30U         // MUX34 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX35_S   6U
#define XBAR_OUT8MUX32TO47CFG_MUX35_M   0xC0U         // MUX35 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX36_S   8U
#define XBAR_OUT8MUX32TO47CFG_MUX36_M   0x300U        // MUX36 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX37_S   10U
#define XBAR_OUT8MUX32TO47CFG_MUX37_M   0xC00U        // MUX37 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX38_S   12U
#define XBAR_OUT8MUX32TO47CFG_MUX38_M   0x3000U       // MUX38 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX39_S   14U
#define XBAR_OUT8MUX32TO47CFG_MUX39_M   0xC000U       // MUX39 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX40_S   16U
#define XBAR_OUT8MUX32TO47CFG_MUX40_M   0x30000U      // MUX40 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX41_S   18U
#define XBAR_OUT8MUX32TO47CFG_MUX41_M   0xC0000U      // MUX41 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX42_S   20U
#define XBAR_OUT8MUX32TO47CFG_MUX42_M   0x300000U     // MUX42 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX43_S   22U
#define XBAR_OUT8MUX32TO47CFG_MUX43_M   0xC00000U     // MUX43 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX44_S   24U
#define XBAR_OUT8MUX32TO47CFG_MUX44_M   0x3000000U    // MUX44 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX45_S   26U
#define XBAR_OUT8MUX32TO47CFG_MUX45_M   0xC000000U    // MUX45 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX46_S   28U
#define XBAR_OUT8MUX32TO47CFG_MUX46_M   0x30000000U   // MUX46 Configuration for TRIP4 of EPWM-XBAR
#define XBAR_OUT8MUX32TO47CFG_MUX47_S   30U
#define XBAR_OUT8MUX32TO47CFG_MUX47_M   0xC0000000U   // MUX47 Configuration for TRIP4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT8MUX48TO63CFG register
//
//*************************************************************************************************
#define XBAR_OUT8MUX48TO63CFG_MUX48_S   0U
#define XBAR_OUT8MUX48TO63CFG_MUX48_M   0x3U          // MUX48 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX49_S   2U
#define XBAR_OUT8MUX48TO63CFG_MUX49_M   0xCU          // MUX49 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX50_S   4U
#define XBAR_OUT8MUX48TO63CFG_MUX50_M   0x30U         // MUX50 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX51_S   6U
#define XBAR_OUT8MUX48TO63CFG_MUX51_M   0xC0U         // MUX51 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX52_S   8U
#define XBAR_OUT8MUX48TO63CFG_MUX52_M   0x300U        // MUX52 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX53_S   10U
#define XBAR_OUT8MUX48TO63CFG_MUX53_M   0xC00U        // MUX53 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX54_S   12U
#define XBAR_OUT8MUX48TO63CFG_MUX54_M   0x3000U       // MUX54 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX55_S   14U
#define XBAR_OUT8MUX48TO63CFG_MUX55_M   0xC000U       // MUX55 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX56_S   16U
#define XBAR_OUT8MUX48TO63CFG_MUX56_M   0x30000U      // MUX56 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX57_S   18U
#define XBAR_OUT8MUX48TO63CFG_MUX57_M   0xC0000U      // MUX57 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX58_S   20U
#define XBAR_OUT8MUX48TO63CFG_MUX58_M   0x300000U     // MUX58 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX59_S   22U
#define XBAR_OUT8MUX48TO63CFG_MUX59_M   0xC00000U     // MUX59 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX60_S   24U
#define XBAR_OUT8MUX48TO63CFG_MUX60_M   0x3000000U    // MUX60 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX61_S   26U
#define XBAR_OUT8MUX48TO63CFG_MUX61_M   0xC000000U    // MUX61 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX62_S   28U
#define XBAR_OUT8MUX48TO63CFG_MUX62_M   0x30000000U   // MUX62 Configuration for OUT8 of EPWM-XBAR
#define XBAR_OUT8MUX48TO63CFG_MUX63_S   30U
#define XBAR_OUT8MUX48TO63CFG_MUX63_M   0xC0000000U   // MUX63 Configuration for OUT8 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT1MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT1MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT1 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT1MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT1MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT1 of EPWM-XBAR
#define XBAR_OUT1MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT1 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT2MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT2MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT2 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT2MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT2MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT2 of EPWM-XBAR
#define XBAR_OUT2MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT2 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT3MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT3MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT3 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT3MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT3MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT3 of EPWM-XBAR
#define XBAR_OUT3MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT3 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT4MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT4MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT4MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT4MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT4 of EPWM-XBAR
#define XBAR_OUT4MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT4 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT5MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT5MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT5 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT5MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT5MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT5 of EPWM-XBAR
#define XBAR_OUT5MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT5 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT6MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT6MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT6 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT6MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT6MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT6 of EPWM-XBAR
#define XBAR_OUT6MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT6 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT7MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT7MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT7MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT7MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT7 of EPWM-XBAR
#define XBAR_OUT7MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT8MUXENABLE register
//
//*************************************************************************************************
#define XBAR_OUT8MUXENABLE_MUX0    0x1U          // MUX0 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX1    0x2U          // MUX1 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX2    0x4U          // MUX2 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX3    0x8U          // MUX3 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX4    0x10U         // MUX4 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX5    0x20U         // MUX5 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX6    0x40U         // MUX6 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX7    0x80U         // MUX7 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX8    0x100U        // MUX8 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX9    0x200U        // MUX9 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX10   0x400U        // MUX10 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX11   0x800U        // MUX11 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX12   0x1000U       // MUX12 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX13   0x2000U       // MUX13 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX14   0x4000U       // MUX14 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX15   0x8000U       // MUX15 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX16   0x10000U      // MUX16 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX17   0x20000U      // MUX17 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX18   0x40000U      // MUX18 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX19   0x80000U      // MUX19 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX20   0x100000U     // MUX20 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX21   0x200000U     // MUX21 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX22   0x400000U     // MUX22 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX23   0x800000U     // MUX23 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX24   0x1000000U    // MUX24 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX25   0x2000000U    // MUX25 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX26   0x4000000U    // MUX26 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX27   0x8000000U    // MUX27 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX28   0x10000000U   // MUX28 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX29   0x20000000U   // MUX29 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX30   0x40000000U   // MUX30 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE_MUX31   0x80000000U   // MUX31 to drive OUT8 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUT8MUXENABLE32TO64 register
//
//*************************************************************************************************
#define XBAR_OUT8MUXENABLE32TO64_MUX32   0x1U          // MUX32 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX33   0x2U          // MUX33 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX34   0x4U          // MUX34 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX35   0x8U          // MUX35 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX36   0x10U         // MUX36 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX37   0x20U         // MUX37 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX38   0x40U         // MUX38 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX39   0x80U         // MUX39 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX40   0x100U        // MUX40 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX41   0x200U        // MUX41 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX42   0x400U        // MUX42 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX43   0x800U        // MUX43 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX44   0x1000U       // MUX44 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX45   0x2000U       // MUX45 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX46   0x4000U       // MUX46 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX47   0x8000U       // MUX47 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX48   0x10000U      // MUX48 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX49   0x20000U      // MUX49 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX50   0x40000U      // MUX50 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX51   0x80000U      // MUX51 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX52   0x100000U     // MUX52 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX53   0x200000U     // MUX53 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX54   0x400000U     // MUX54 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX55   0x800000U     // MUX55 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX56   0x1000000U    // MUX56 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX57   0x2000000U    // MUX57 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX58   0x4000000U    // MUX58 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX59   0x8000000U    // MUX59 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX60   0x10000000U   // MUX60 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX61   0x20000000U   // MUX61 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX62   0x40000000U   // MUX62 to drive OUT8 of EPWM-XBAR
#define XBAR_OUT8MUXENABLE32TO64_MUX63   0x80000000U   // MUX63 to drive OUT8 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIPOUTINV register
//
//*************************************************************************************************
#define XBAR_TRIPOUTINV_OUT0   0x1U    // Selects polarity for OUT0 of EPWM-XBAR
#define XBAR_TRIPOUTINV_OUT1   0x2U    // Selects polarity for OUT1 of EPWM-XBAR
#define XBAR_TRIPOUTINV_OUT2   0x4U    // Selects polarity for OUT2 of EPWM-XBAR
#define XBAR_TRIPOUTINV_OUT3   0x8U    // Selects polarity for OUT3 of EPWM-XBAR
#define XBAR_TRIPOUTINV_OUT4   0x10U   // Selects polarity for OUT4 of EPWM-XBAR
#define XBAR_TRIPOUTINV_OUT5   0x20U   // Selects polarity for OUT5 of EPWM-XBAR
#define XBAR_TRIPOUTINV_OUT6   0x40U   // Selects polarity for OUT6 of EPWM-XBAR
#define XBAR_TRIPOUTINV_OUT7   0x80U   // Selects polarity for OUT7 of EPWM-XBAR

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIPLOCK register
//
//*************************************************************************************************
#define XBAR_TRIPLOCK_LOCK    0x1U          // Locks the configuration for EPWM-XBAR
#define XBAR_TRIPLOCK_KEY_S   16U
#define XBAR_TRIPLOCK_KEY_M   0xFFFF0000U   // Write protection KEY


#endif
#endif
