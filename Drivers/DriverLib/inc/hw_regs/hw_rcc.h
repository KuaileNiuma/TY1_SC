/** 
  ************************************************************************************* 
  * @file hw_rcc.h 
  * @brief This file contains the definition of hw_rcc driver. 
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

#ifndef HW_RCC_H
#define HW_RCC_H

#if RCC_HW_VER == 0

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
#define RCC_O_CR            0x00U
#define RCC_O_HSICR         0x04U
#define RCC_O_CFGR          0x08U
#define RCC_O_PERSELR       0x0CU
#define RCC_O_PLLCFGR       0x10U
#define RCC_O_MCDCR         0x14U
#define RCC_O_CIR           0x18U
#define RCC_O_AHBRSTR1      0x1CU
#define RCC_O_AHBRSTR2      0x20U
#define RCC_O_APBHRSTR      0x24U
#define RCC_O_APBLRSTR1     0x28U
#define RCC_O_APBLRSTR2     0x2CU
#define RCC_O_AHBENR1       0x30U
#define RCC_O_AHBENR2       0x34U
#define RCC_O_APBHENR       0x38U
#define RCC_O_APBLENR1      0x3CU
#define RCC_O_APBLENR2      0x40U
#define RCC_O_CSR           0x44U

/********************  Bit definition for RCC_CR register  ********************/
#define  RCC_CR_SFTRST                       ((uint32_t)0x00000001)        /*!< Internal High Speed clock enable */
#define  RCC_CR_CPURST                       ((uint32_t)0x00000002)        /*!< Internal High Speed clock ready flag */
#define  RCC_CR_MCODIV_M                     ((uint32_t)0x000000F0)        /*!< Internal High Speed clock trimming */
#define  RCC_CR_HSECFG_M                     ((uint32_t)0x0000FF00)        /*!< Internal High Speed clock Calibration */
#define  RCC_CR_HSEON                        ((uint32_t)0x00010000)        /*!< External High Speed clock enable */
#define  RCC_CR_HSERDY                       ((uint32_t)0x00020000)        /*!< External High Speed clock ready flag */
#define  RCC_CR_HSEBYP                       ((uint32_t)0x00040000)        /*!< External High Speed clock Bypass */
#define  RCC_CR_WWDG1RSTEN                   ((uint32_t)0x00100000)        /*!< Clock Security System enable */
#define  RCC_CR_PLLON                        ((uint32_t)0x01000000)        /*!< PLL enable */
#define  RCC_CR_PLLRDY                       ((uint32_t)0x02000000)        /*!< PLL clock ready flag */

/********************  Bit definition for RCC_HSICR register  ********************/
#define  RCC_CR_HSI1ON                       ((uint32_t)0x00000001)        /*!< Internal High Speed clock1 enable */
#define  RCC_CR_HSI1RDY                      ((uint32_t)0x00000002)        /*!< Internal High Speed clock1 ready flag */
#define  RCC_CR_HSI1FTUNE_M                  ((uint32_t)0x000000FC)        /*!< Internal High Speed clock1 fine trimming */
#define  RCC_CR_HSI1CTUNE_M                  ((uint32_t)0x00007E00)        /*!< Internal High Speed clock1 coarse trimming */
#define  RCC_CR_HSI2ON                       ((uint32_t)0x00010000)        /*!< Internal High Speed clock2 enable */
#define  RCC_CR_HSI2RDY                      ((uint32_t)0x00020000)        /*!< Internal High Speed clock2 ready flag */
#define  RCC_CR_HSI2FTUNE_M                  ((uint32_t)0x00FC0000)        /*!< Internal High Speed clock2 fine trimming */
#define  RCC_CR_HSI2CTUNE_M                  ((uint32_t)0x7E000000)        /*!< Internal High Speed clock2 coarse trimming */


/*******************  Bit definition for RCC_CFGR register  *******************/
/*!< SW configuration */
#define RCC_CFGR_SCLK_SWITCH_M               ((uint32_t)0x00000003)        /*!< Mask for system clock switch */
#define RCC_CFGR_SCLK_SWITCH_STATUS_M        ((uint32_t)0x0000000C)        /*!< Mask for system clock switch status flag */
#define RCC_CFGR_AHB_PREDIV_M                ((uint32_t)0x000000F0)        /*!< Mask for AHB prescaler */
#define RCC_CFGR_APBH_PREDIV_M               ((uint32_t)0x00000700)        /*!< Mask for APBL prescaler */
#define RCC_CFGR_APBL_PREDIV_M               ((uint32_t)0x00003800)        /*!< Mask for APBL prescaler */
#define RCC_CFGR_ADC_PREDIV_M                ((uint32_t)0x0000C000)        /*!< Mask for ADC prescaler */
#define RCC_CFGR_CANFD_PREDIV_M              ((uint32_t)0x000F0000)        /*!< Mask for CANFD prescaler */
#define RCC_CFGR_XFLASH_PREDIV_M             ((uint32_t)0x00F00000)        /*!< Mask for XFLASH prescaler */

/*******************  Bit definition for RCC_PLLCFGR register  *******************/
/*!< SW configuration */
#define RCC_PLLCFGR_PLL_LOOP_M               ((uint32_t)0x00FF0000)        /*!< Mask for the loop divider of PLL */
#define RCC_PLLCFGR_DELAY_M                  ((uint32_t)0x03000000)        /*!< Mask for the signal of lock detection delay time */
#define RCC_PLLCFGR_GLITCH_BYP_M             ((uint32_t)0x04000000)        /*!< Mask for bypass signal of anti-glitch function */
#define RCC_PLLCFGR_PLL_PREDIV_M             ((uint32_t)0xF8000000)        /*!< Mask for PLL prescaler */

/*******************  Bit definition for RCC_CSR register  ********************/
#define  RCC_CSR_RMVF                        ((uint32_t)0x00010000)        /*!< Remove reset flag */
#define  RCC_CSR_CPURSTF                     ((uint32_t)0x00800000)        /*!< PIN reset flag */
#define  RCC_CSR_PINRSTF                     ((uint32_t)0x01000000)        /*!< PIN reset flag */
#define  RCC_CSR_PORRSTF                     ((uint32_t)0x02000000)        /*!< POR/PDR reset flag */
#define  RCC_CSR_SFTRSTF                     ((uint32_t)0x04000000)        /*!< Software Reset flag */
#define  RCC_CSR_IWDGRSTF                    ((uint32_t)0x08000000)        /*!< Independent Watchdog reset flag */
#define  RCC_CSR_WWDGRSTF                    ((uint32_t)0x20000000)        /*!< Window watchdog reset flag */
#define  RCC_CSR_LPWRRSTF                    ((uint32_t)0x80000000)        /*!< Low-Power reset flag */

#elif RCC_HW_VER == 1

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/

#define RCC_O_RST_EN     0x68U
#define RCC_O_RST1       0x6CU
#define RCC_O_RST2       0x70U
#define RCC_O_RST3       0x74U
#define RCC_O_RST4       0x78U
#define RCC_O_RST5       0x7CU

#else

#endif

#endif

