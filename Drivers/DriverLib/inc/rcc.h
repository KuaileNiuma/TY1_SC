/**
 *************************************************************************************
 * @file rcc.h
 * @brief This file impleted the function of gpio_test.
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

#ifndef __RCC_H
#define __RCC_H

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

#include "hw_common.h"
#include "hw_rcc.h"

#if RCC_HW_VER == 0

#define SYSCLK_FREQ_138MHz
#define SYSCLK_FREQ_120MHz
#define SYSCLK_FREQ_96MHz

/** @addtogroup 
 * @{
 */
typedef struct {
    uint32_t RCC_CR;
    uint32_t RCC_HSICR;
    uint32_t RCC_CFGR;
    uint32_t RCC_PERSELR;
    uint32_t RCC_PLLCFGR;
    uint32_t RCC_MCDCR;
    uint32_t RCC_CIR;
    uint32_t RCC_AHBRSTR1;
    uint32_t RCC_AHBRSTR2;
    uint32_t RCC_APBHRSTR;
    uint32_t RCC_APBLRSTR1;
    uint32_t RCC_APBLRSTR2;
    uint32_t RCC_AHBENR1;
    uint32_t RCC_AHBENR2;
    uint32_t RCC_APBHENR;
    uint32_t RCC_APBLENR1;
    uint32_t RCC_APBLENR2;
    uint32_t RCC_CSR;
} RCC_TypeDef;

#define RCC                 ((RCC_TypeDef *) RCC_BASE)

//RCC_CR reset
#define RCC_PLL_RDY_FLAG        (0x1 << 25)             //PLL clock ready flag

#define CR_PLL_ON           (0x1 << 24)             //ENABLE PLL clock
#define CR_PLL_OFF          ~(0x1 << 24)            //DISABLE PLL clock

#define CR_WWDG_RST_EN      (0x1 << 20)             //WWDG reset enable
#define CR_WWDG_RST_DIS     ~(0x1 << 20)            //WWDG reset disable

#define CR_HSE_BYP          (0x1 << 18)             //external 3-25MHz oscillator bypassed with external clock
#define CR_HSE_NBYP         ~(0x1 << 18)            //external 3-25MHz oscillator not bypassed

#define CR_HSE_RDY          (0x1 << 17)             //HSE oscillator is ready

#define CR_HSE_ON           (0x1 << 16)             //HSE oscillator ON
#define CR_HSE_OFF          ~(0x1 << 16)            //HSE oscillator OFF

typedef enum
{
    MCO_FB = 0x0,
    MCO_1_DIV = 0x1,
    MCO_2_DIV = 0x2,
    MCO_3_DIV = 0x3,
    MCO_4_DIV = 0x4,
    MCO_5_DIV = 0x5,
    MCO_6_DIV = 0x6,
    MCO_7_DIV = 0x7,
    MCO_8_DIV = 0x8,
    MCO_9_DIV = 0x9,
    MCO_10_DIV = 0xA,
    MCO_11_DIV = 0xB,
    MCO_12_DIV = 0xC,
    MCO_13_DIV = 0xD,
    MCO_14_DIV = 0xE,
    MCO_15_DIV = 0xF,
}RCC_MCO_DIV;

#define CR_CPU_RST_EN                  (0x1 << 1)

#define CR_SFTRST                     (0x1 << 0)
//RCC_HSICR
#define HSICR_HSI2_CTUNE             (0x3F << 25)
#define HSICR_HSI2_FTUNE             (0x3F << 18)
#define HSICR_HSI2_RDY               (0x1 << 17)
#define HSICR_HSI2_ON                (0x1 << 16)
#define HSICR_HSI2_OFF               ~(0x1 << 16)

#define HSICR_HSI1_CTUNE             (0x3F << 9)
#define HSICR_HSI1_FTUNE             (0x3F << 2)
#define HSICR_HSI1_RDY               (0x1 << 1)

#define HSICR_HSI1_ON                (0x1 << 0)
#define HSICR_HSI1_OFF               ~(0x1 << 0)
//RCC_CFGR
typedef enum
{
    DIV_CLK = 0x0,
    HSE_CLK = 0x1,
    AUX_CLK = 0x2,
}CANFD_CLK_SEL;

typedef enum
{
    HSIRC_HSI1 = 0x0,
    HSIRC_HSI2 = 0x1,
}HSI_SRC_SEL;

typedef enum OSC_SRC
{
    OSCSRC_HSI = 0x0,
    OSCSRC_HSE = 0x1,
}OSC_SRC_SEL;

typedef enum
{
    MCO_OSC = 0x0,
    MCO_PLL = 0x1,
    MCO_AHB,
    MCO_HSI1,
    MCO_HSI2,
    MCO_HSE,
    MCO_CPU,
    MCO_NO_CLK
}MCO_CLK_SEL;

typedef enum
{
    XFLASH_PRE1 = 0x0,
    XFLASH_PRE2 = 0x8,
    XFLASH_PRE4,
    XFLASH_PRE8,
    XFLASH_PRE16,
    XFLASH_PRE64,
    XFLASH_PRE128,
    XFLASH_PRE256,
    XFLASH_PRE512,
}XFLASH_PRE_DIV;

typedef enum
{
    CANFD_PRE1 = 0x0,
    CANFD_PRE2 = 0x8,
    CANFD_PRE4,
    CANFD_PRE8,
    CANFD_PRE16,
    CANFD_PRE64,
    CANFD_PRE128,
    CANFD_PRE256,
    CANFD_PRE512,
}CANFD_PRE_DIV;

typedef enum
{
    ADC_PRE2 = 0x0,
    ADC_PRE4,
    ADC_PRE6,
    ADC_PRE8,
}ADC_PRE_DIV;

typedef enum
{
    APBL_PRE1 = 0x0,
    APBL_PRE2 = 0x4,
    APBL_PRE4,
    APBL_PRE8,
    APBL_PRE16,
}APBL_PRE_DIV;

typedef enum
{
    APBH_PRE1 = 0x0,
    APBH_PRE2 = 0x4,
    APBH_PRE4,
    APBH_PRE8,
    APBH_PRE16,
}APBH_PRE_DIV;

typedef enum
{
    AHB_PRE1 = 0x0,
    AHB_PRE2 = 0x8,
    AHB_PRE4,
    AHB_PRE8,
    AHB_PRE16,
    AHB_PRE64,
    AHB_PRE128,
    AHB_PRE256,
    AHB_PRE512,
}AHB_PRE_DIV;

#define SWS_OSC               (0x0 << 2)
#define SWS_PLL               (0x1 << 2)

typedef enum
{
    SW_OSC = 0x0,
    SW_PLL,
}SYS_CLK_SRC;

//RCC_PERSELR


//RCC_PLLCFGR
typedef enum
{
    PLL_PRE_DIV1 = 0x1,
    PLL_PRE_DIV2,
    PLL_PRE_DIV3,
    PLL_PRE_DIV4,
    PLL_PRE_DIV5,
    PLL_PRE_DIV6,
    PLL_PRE_DIV7,
    PLL_PRE_DIV8,
    PLL_PRE_DIV9,
    PLL_PRE_DIV10,
    PLL_PRE_DIV11,
    PLL_PRE_DIV12,
    PLL_PRE_DIV13,
    PLL_PRE_DIV14,
    PLL_PRE_DIV15,
    PLL_PRE_DIV16,
    PLL_PRE_DIV17,
    PLL_PRE_DIV18,
    PLL_PRE_DIV19,
    PLL_PRE_DIV20,
    PLL_PRE_DIV21,
    PLL_PRE_DIV22,
    PLL_PRE_DIV23,
    PLL_PRE_DIV24,
    PLL_PRE_DIV25,
    PLL_PRE_DIV26,
    PLL_PRE_DIV27,
    PLL_PRE_DIV28,
    PLL_PRE_DIV29,
    PLL_PRE_DIV30,
    PLL_PRE_DIV31,
}PLL_PRE_DIV;

#define PLL_GLITCH_BYP                  (0x1 << 26)

typedef enum
{
    PLL_DELAY_TIME_1_25ns = 0x0,        //1.25ns
    PLL_DELAY_TIME_2_5ns,               //2.5ns
    PLL_DELAY_TIME_3_75ns,              //3.75ns
    PLL_DELAY_TIME_5_0ns,               //5.0ns
}PLL_DELAY_TIME;

typedef enum
{
    PLL_VCP_100 = 0x1,
    PLL_VCP_200,
    PLL_VCP_300,
    PLL_VCP_400,
}PLL_SW_VCO;

typedef enum
{
    PLL_LOCK_TIME64 = 0x0,
    PLL_LOCK_TIME128,
    PLL_LOCK_TIME256,
    PLL_LOCK_TIME512,
}PLL_LOCK_TIME;

typedef enum
{
    PLL_POST_DIV2 = 0x0,            //f(CLKOUT_LF)=f(CLKOUT_HF)/2
    PLL_POST_DIV4,                  //f(CLKOUT_LF)=f(CLKOUT_HF)/4
    PLL_POST_DIV8,                  //f(CLKOUT_LF)=f(CLKOUT_HF)/8
    PLL_POST_DIV16,                 //f(CLKOUT_LF)=f(CLKOUT_HF)/16
}PLL_SEL_POSTDIV;

typedef enum
{
    PLL_NOT_BYPASS_LOCK_DETECT = 0x0,
    PLL_BYPASS_LOCK_DETECT,
}PLL_FORCE_LOCK;

//*****************************************************************************
//
// RCC_MCDCR Register Bit Definitions
//
//*****************************************************************************
#define REF_LOST_MCD_EN       (0x1 << 6)    //!< Reference lost detector enable
#define REF_LOST_MCD_DIS          (0x0)         //!< Reference lost detector disable
#define REF_LOST_STS_CLR          (0x1 << 5)    //!< Reference lost status clear
#define REF_LOST_STS_FLAG         (0x1 << 4)    //!< Reference lost status flag
#define MCD_OSC_ON            ~(0x1 << 3)   //!< MCD oscillator on
#define MCD_OSC_OFF             (0x1 << 3)    //!< MCD oscillator off
#define MCLK_DETECT_ON          ~(0x1 << 2)   //!< Main clock detect on
#define MCLK_DETECT_OFF         (0x1 << 2)    //!< Main clock detect off
#define MCLK_STATUS_CLEAR       (0x1 << 1)    //!< Main clock status clear
#define MCLK_STATUS_MISS        (0x1 << 0)    //!< Main clock status miss
//*****************************************************************************
//
// RCC_CIR Register Bit Definitions
//
//*****************************************************************************
#define CIR_PLL_RDY_CLEAR           (0x1 << 20)   //!< PLL ready interrupt clear
#define CIR_HSE_RDY_CLEAR           (0x1 << 19)   //!< HSE ready interrupt clear
#define CIR_HSI2_RDY_CLEAR          (0x1 << 18)   //!< HSI2 ready interrupt clear
#define CIR_HSI1_RDY_CLEAR          (0x1 << 17)   //!< HSI1 ready interrupt clear

#define CIR_PLL_RDY_INT_EN          (0x1 << 12)   //!< PLL ready interrupt enable
#define CIR_HSE_RDY_INT_EN          (0x1 << 11)   //!< HSE ready interrupt enable
#define CIR_HSI2_RDY_INT_EN         (0x1 << 10)   //!< HSI2 ready interrupt enable
#define CIR_HSI1_RDY_INT_EN         (0x1 << 9)    //!< HSI1 ready interrupt enable

#define CIR_PLL_RDY_INT_FLAG            (0x1 << 4)
#define CIR_HSE_RDY_INT_FLAG            (0x1 << 3)
#define CIR_HSI2_RDY_INT_FLAG           (0x1 << 2)
#define CIR_HSI1_RDY_INT_FLAG           (0x1 << 1)
//RCC_AHBRSTR1
typedef enum
{
    EPWM8_RST = 4,
    EPWM7_RST,
    EPWM6_RST,
    EPWM5_RST,
    EPWM4_RST,
    EPWM3_RST,
    EPWM2_RST,
    EPWM1_RST,

    CMPSS7_RST,
    CMPSS6_RST,
    CMPSS5_RST,
    CMPSS4_RST,
    CMPSS3_RST,
    CMPSS2_RST,
    CMPSS1_RST,

    SDFM1_RST,
    SDFM2_RST,

    EQEP3_RST,
    EQEP2_RST,
    EQEP1_RST,

    ECAP4_RST,
    ECAP3_RST,
    ECAP2_RST,
    ECAP1_RST,

    ADC3_RST,
    ADC2_RST,
    ADC1_RST,
}AHB1_RST;

//*****************************************************************************
//
// RCC_AHBRSTR2 Register - AHB Bus Reset Register 2
//
//*****************************************************************************
typedef enum
{
    LCM_RST = 1,
    EFLASHC_RST,
    QSPI_RST = 17,
    CSPIL_RST,
    CSPIF_RST,
    AES_RST = 22,
    XFLASHC_RST,
    SPL_RST,
    SMCM_RST = 26,
    DMASCH_RST,
    DMA2_RST,
    DMA1_RST,
    DACC2_RST,
    DACC1_RST,
}AHB2_RST;

//*****************************************************************************
//
// RCC_APBHRSTR Register - APB High Bus Reset Register
//
//*****************************************************************************
typedef enum
{
    TIMER4_RST = 28,
    TIMER3_RST,
    TIMER2_RST,
    TIMER1_RST,
}APBHR_RST;
//*****************************************************************************
//
// RCC_APBLRSTR1 Register - APB Low Bus Reset Register 1
//
//*****************************************************************************
typedef enum
{
    XBAR_RST = 0,
    I2C4_RST = 5,
    BSPI3_RST,
    BSPI2_RST,
    BSPI1_RST,

    CANFD2_RST,
    CANFD1_RST,

    USART2_RST,
    USART1_RST,

    I2C1_RST,
    I2C2_RST,
    BSPI4_RST = 17,
    I2C3_RST,

    UART2_RST = 23,
    UART1_RST,
    SYSCTL_RST = 27,
    WWDT_RST = 29,
    IWDT_RST = 31,
}APBLR1_RST;
//*****************************************************************************
//
// RCC_APBLRSTR2 Register - APB Low Bus Reset Register 2
//
//*****************************************************************************
typedef enum
{
    CLB4_RST = 22,
    CLB3_RST,
    CLB2_RST,
    CRC_RST,
    CLB1_RST,
    GPIO5_RST,
    GPIO4_RST,
    GPIO3_RST,
    GPIO2_RST,
    GPIO1_RST,
}APBLR2_RST;
//*****************************************************************************
//
// RCC_AHBENR1 Register - AHB Bus Clock Enable Register 1
//
//*****************************************************************************
typedef enum
{
    EPWM8_CLK_EN = 4,
    EPWM7_CLK_EN,
    EPWM6_CLK_EN,
    EPWM5_CLK_EN,
    EPWM4_CLK_EN,
    EPWM3_CLK_EN,
    EPWM2_CLK_EN,
    EPWM1_CLK_EN,
    CMPSS4_CLK_EN = 15,
    CMPSS3_CLK_EN,
    CMPSS2_CLK_EN,
    CMPSS1_CLK_EN,
    SDFM2_CLK_EN,
    SDFM1_CLK_EN,
    EQEP3_CLK_EN,
    EQEP2_CLK_EN,
    EQEP1_CLK_EN,
    ECAP4_CLK_EN,
    ECAP3_CLK_EN,
    ECAP2_CLK_EN,
    ECAP1_CLK_EN,
    ADC3_CLK_EN,
    ADC2_CLK_EN,
    ADC1_CLK_EN,
    ERM_CLK_EN,
}AHB1_EN;
//*****************************************************************************
//
// RCC_AHBENR2 Register - AHB Bus Clock Enable Register 2
//
//*****************************************************************************
typedef enum
{
    LCM_CLK_EN = 0,
    EFLASHC_CLK_EN,
    HAC_CLK_EN = 14,
    MBX2_CLK_EN,
    MBX1_CLK_EN,
    QSPI_CLK_EN,
    CSPIL_CLK_EN,
    CSPIF_CLK_EN,
    HACL_CLK_EN,
    HACF_CLK_EN,
    AES_CLK_EN,
    XFLASHC_CLK_EN,
    SMCM_CLK_EN = 26,
    DMASCH_CLK_EN,
    DMA2_CLK_EN,
    DMA1_CLK_EN,
    DACC2_CLK_EN,
    DACC1_CLK_EN,
}AHB2_EN;
//*****************************************************************************
//
// RCC_APBHENR Register - APB High Bus Clock Enable Register
//
//*****************************************************************************

//*****************************************************************************
//
// RCC_APBLENR1 Register - APB Low Bus Clock Enable Register 1
//
//*****************************************************************************
typedef enum
{
    XBAR_CLK_EN = 0,
    I2C4_CLK_EN = 5,
    BSPI3_CLK_EN,
    BSPI2_CLK_EN,
    BSPI1_CLK_EN,
    CANFD2_CLK_EN,
    CANFD1_CLK_EN,
    USART2_CLK_EN,
    USART1_CLK_EN,
    I2C3_CLK_EN,
    I2C2_CLK_EN,
    BSPI4_CLK_EN = 17,
    I2C1_CLK_EN,
    UART2_CLK_EN = 23,
    UART1_CLK_EN,
    NPU_CLK_EN,
    HACL_REG_CLK_EN,
    SYSCTL_CLK_EN,
    WWDT_CLK_EN = 29,
    IWDT_CLK_EN = 31,
}APBL1_EN;

//*****************************************************************************
//
// RCC_APBLENR2 Register - APB Low Bus Clock Enable Register 2
//
//*****************************************************************************
typedef enum
{
    CLB4_CLK_EN = 22,
    CLB3_CLK_EN,
    CLB2_CLK_EN,
    CRC_CLK_EN,
    CLB1_CLK_EN,
    GPIO5_CLK_EN,
    GPIO4_CLK_EN,
    GPIO3_CLK_EN,
    GPIO2_CLK_EN,
    GPIO1_CLK_EN,
}APBL2_EN;

//*****************************************************************************
//
// RCC_CSR Register Bit Definitions
//
//*****************************************************************************
#define LPWR_RST_FLAG           (0x1 << 31)   //!< Low power reset flag
#define WWDG_RST_FLAG           (0x1 << 29)   //!< Window watchdog reset flag
#define IWDG_RST_FLAG           (0x1 << 27)   //!< Independent watchdog reset flag
#define SFT_RST_FLAG            (0x1 << 26)   //!< Software reset flag
#define POR_RST_FLAG            (0x1 << 25)   //!< Power-on reset flag
#define PIN_RST_FLAG            (0x1 << 24)   //!< Pin reset flag
#define CPU_RST_FLAG            (0x1 << 23)   //!< CPU reset flag
#define REMOVE_RST_FLAG         (0x1 << 16)  //!< Remove reset flag



static inline uint32_t RCC_getPLLReadyStatus(void)
{
    //
    // Check if PLL is ready
    //
    return (HWREG(RCC_BASE + RCC_O_CR) & RCC_CR_PLLRDY);
}

static inline void RCC_enbalePLL(void)
{
    //
    // Enable PLL
    //
    HWREG(RCC_BASE + RCC_O_CR) |= RCC_CR_PLLON;
}

static inline void RCC_disbalePLL(void)
{
    //
    // Disable PLL
    //
    HWREG(RCC_BASE + RCC_O_CR) &= ~RCC_CR_PLLON;
}

static inline void RCC_enableWWDGReset()
{
    HWREG(RCC_BASE + RCC_O_CR) |= RCC_CR_WWDG1RSTEN;
}

static inline void RCC_disableWWDGReset()
{
    HWREG(RCC_BASE + RCC_O_CR) &= ~RCC_CR_WWDG1RSTEN;
}

static inline void RCC_setHSEBypass()
{
    HWREG(RCC_BASE + RCC_O_CR) |= RCC_CR_HSEBYP;
}

static inline void RCC_setHSENotBypass()
{
    HWREG(RCC_BASE + RCC_O_CR) &= ~RCC_CR_HSEBYP;
}

static inline uint32_t RCC_getHSEReadyStatus(void)
{
    return (HWREG(RCC_BASE + RCC_O_CR) & RCC_CR_HSERDY);
}

static inline void RCC_enableHSE(void)
{
    HWREG(RCC_BASE + RCC_O_CR) |= RCC_CR_HSEON;
}

static inline void RCC_disableHSE(void)
{
    HWREG(RCC_BASE + RCC_O_CR) &= ~RCC_CR_HSEON;
}

static inline void RCC_HSEConfig(uint32_t config)
{

    //
    // Clear HSE configuration bits
    //
    HWREG(RCC_BASE + RCC_O_CR) &= ~RCC_CR_HSECFG_M;

    //
    // Set new HSE configuration
    //
    HWREG(RCC_BASE + RCC_O_CR) |= config;
}

static inline void RCC_setMCODivider(RCC_MCO_DIV div)
{
    HWREG(RCC_BASE + RCC_O_CR) &= ~RCC_CR_MCODIV_M;
    HWREG(RCC_BASE + RCC_O_CR) |= (div << 4);
}

static inline void RCC_CPUReset()
{
    HWREG(RCC_BASE + RCC_O_CR) &= ~0xF0;
    HWREG(RCC_BASE + RCC_O_CR) |= RCC_CR_CPURST;
}

static inline void RCC_softwareReset()
{
    HWREG(RCC_BASE + RCC_O_CR) |= RCC_CR_SFTRST;
}

static inline uint32_t RCC_getHSI2CoaresTrimming()
{
    return (HWREG(RCC_BASE + RCC_O_HSICR) & RCC_CR_HSI2CTUNE_M);
}

static inline uint32_t RCC_getHSI2HSI2FineTrimming()
{
    return (HWREG(RCC_BASE + RCC_O_HSICR) & RCC_CR_HSI2FTUNE_M);
}

static inline void RCC_setHSI2FineTrimming(uint32_t trim)
{
    //
    // Check if parameter is valid
    //
    if((trim & (~HSICR_HSI2_FTUNE))!=0)
    {
        return;
    }
    //
    // Set HSI2 fine trimming value
    //
    HWREG(RCC_BASE + RCC_O_HSICR) &= ~RCC_CR_HSI2FTUNE_M;
    HWREG(RCC_BASE + RCC_O_HSICR) |= ((trim << 2) & RCC_CR_HSI2FTUNE_M);
}

static inline uint32_t RCC_getHSI2ReadyStatus(void)
{
    return (HWREG(RCC_BASE + RCC_O_HSICR) & RCC_CR_HSI2RDY);
}

static inline void RCC_enableHSI2(void)
{
    HWREG(RCC_BASE + RCC_O_HSICR) |= RCC_CR_HSI2ON;
}

static inline void RCC_disableHSI2(void)
{
    HWREG(RCC_BASE + RCC_O_HSICR) &= ~RCC_CR_HSI2ON;
}

static inline uint32_t RCC_getHSI1CoaresTrimmingStatus()
{
    return (HWREG(RCC_BASE + RCC_O_HSICR) & RCC_CR_HSI1CTUNE_M);
}

static inline void RCC_setHSI1FineTrimming(uint32_t trim)
{

    if((trim & (~HSICR_HSI1_FTUNE))!=0)
    {
        return;
    }
    //
    // Set HSI1 fine trimming value
    //
    HWREG(RCC_BASE + RCC_O_HSICR) &= ~RCC_CR_HSI1FTUNE_M;
    HWREG(RCC_BASE + RCC_O_HSICR) |= ((trim << 2) & RCC_CR_HSI1FTUNE_M);
}

static inline uint32_t RCC_getHSI1ReadyStatus(void)
{
    return (HWREG(RCC_BASE + RCC_O_HSICR) & RCC_CR_HSI1RDY);
}

static inline void RCC_enableHSI1(void)
{
    HWREG(RCC_BASE + RCC_O_HSICR) |= RCC_CR_HSI1ON;
}

static inline void RCC_disableHSI1(void)
{
    HWREG(RCC_BASE + RCC_O_HSICR) &= ~RCC_CR_HSI1ON;
}

static inline void RCC_selCANFDClock(CANFD_CLK_SEL clk)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(0x3 << 29);
    HWREG(RCC_BASE + RCC_O_CFGR) |= clk << 29;
}

static inline void RCC_selHSISource(HSI_SRC_SEL HSIx)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(0x1 << 28);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (HSIx << 28);
}

static inline void RCC_selOSCSource(OSC_SRC_SEL clk)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(0x1 << 27);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (clk << 27);
}

static inline void RCC_selMCO(MCO_CLK_SEL clk)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(0x1 << 24);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (clk << 24);
}

static inline void RCC_setXFLASHPrescaler(XFLASH_PRE_DIV div)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(RCC_CFGR_XFLASH_PREDIV_M);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (div << 20);
}

static inline uint32_t RCC_getXFLASHPrescaler()
{
    return (HWREG(RCC_BASE + RCC_O_CFGR) & RCC_CFGR_XFLASH_PREDIV_M);
}

static inline void RCC_setCANFDPrescaler(CANFD_PRE_DIV div)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(RCC_CFGR_CANFD_PREDIV_M);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (div << 16);
}

static inline uint32_t RCC_getCANFDPrescaler()
{
    return ((HWREG(RCC_BASE + RCC_O_CFGR) & RCC_CFGR_CANFD_PREDIV_M) >> 16);
}

static inline void RCC_setADCPrescaler(ADC_PRE_DIV div)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(RCC_CFGR_ADC_PREDIV_M);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (div << 14);
}

static inline uint32_t RCC_getADCPrescaler()
{
    return (HWREG(RCC_BASE + RCC_O_CFGR) & RCC_CFGR_ADC_PREDIV_M);
}

static inline void RCC_setAPBLPrescaler(APBL_PRE_DIV div)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(RCC_CFGR_APBL_PREDIV_M);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (div << 11);
}

static inline uint32_t RCC_getAPBLPrescaler(void)
{
    uint32_t div;
    APBL_PRE_DIV div_e = (HWREG(RCC_BASE + RCC_O_CFGR) & RCC_CFGR_APBL_PREDIV_M) >> 11;
    switch (div_e) {
    case APBL_PRE2:
        div = 2;
        break;
    case APBL_PRE4:
        div = 4;
        break;
    case APBL_PRE8:
        div = 8;
        break;
    case APBL_PRE16:
        div = 16;
        break;
    default:
        div = 1; // FIXME
        break;
    }
    return div;
}

static inline void RCC_setAPBHPrescaler(APBH_PRE_DIV div)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(RCC_CFGR_APBH_PREDIV_M);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (div << 8);
}

static inline uint32_t RCC_getAPBHPrescaler(void)
{
    uint32_t div;
    APBH_PRE_DIV div_e = (HWREG(RCC_BASE + RCC_O_CFGR) & RCC_CFGR_APBH_PREDIV_M) >> 8;
    switch (div_e) {
    case APBH_PRE2:
        div = 2;
        break;
    case APBH_PRE4:
        div = 4;
        break;
    case APBH_PRE8:
        div = 8;
        break;
    case APBH_PRE16:
        div = 16;
        break;
    default:
        div = 1;
        break;
    }
    return div;
}

static inline void RCC_setAHBPrescaler(AHB_PRE_DIV div)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(RCC_CFGR_AHB_PREDIV_M);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (div << 4);
}

static inline uint32_t RCC_getAHBPrescaler(void)
{
    uint32_t div;
    AHB_PRE_DIV div_e = (HWREG(RCC_BASE + RCC_O_CFGR) & RCC_CFGR_AHB_PREDIV_M) >> 4;
    switch (div_e) {
    case AHB_PRE2:
        div = 2;
        break;
    case AHB_PRE4:
        div = 4;
        break;
    case AHB_PRE8:
        div = 8;
        break;
    case AHB_PRE16:
        div = 16;
        break;
    case AHB_PRE64:
        div = 64;
        break;
    case AHB_PRE128:
        div = 128;
        break;
    case AHB_PRE256:
        div = 256;
        break;
    case AHB_PRE512:
        div = 512;
        break;
    default:
        div = 1; // FIXME
        break;
    }
    return div;
}

static inline uint32_t RCC_getSyetemClockSwitchStatus(void)
{
    return (HWREG(RCC_BASE + RCC_O_CFGR) & RCC_CFGR_SCLK_SWITCH_STATUS_M);
}

static inline void RCC_setSystemClockSrc(SYS_CLK_SRC clk)
{
    HWREG(RCC_BASE + RCC_O_CFGR) &= ~(RCC_CFGR_SCLK_SWITCH_M);
    HWREG(RCC_BASE + RCC_O_CFGR) |= (clk << 0);
}

static inline void RCC_setPLLPrescaler(PLL_PRE_DIV pll_pre)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~RCC_PLLCFGR_PLL_PREDIV_M;
    HWREG(RCC_BASE + RCC_O_PLLCFGR) |= (pll_pre << 27);
}

static inline void RCC_setPLLGlitchBypass(FunctionalState state)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~(RCC_PLLCFGR_GLITCH_BYP_M);
    if(state != DISABLE)
    {
        HWREG(RCC_BASE + RCC_O_PLLCFGR) |= RCC_PLLCFGR_GLITCH_BYP_M;
    }
}

static inline void RCC_setPLLLockDetectionDelayTime(PLL_DELAY_TIME pll_delay)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~RCC_PLLCFGR_DELAY_M;
    HWREG(RCC_BASE + RCC_O_PLLCFGR) |= (pll_delay << 24);
}

static inline void RCC_setPLLMultipler(uint8_t loop)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~RCC_PLLCFGR_PLL_LOOP_M;
    HWREG(RCC_BASE + RCC_O_PLLCFGR) |= (loop << 16);
}

static inline void RCC_setPLLVCOOscillatingFreq(PLL_SW_VCO vco)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~(0x7 << 5);
    HWREG(RCC_BASE + RCC_O_PLLCFGR) |= (vco << 5);
}

static inline void RCC_setPLLLockTime(PLL_LOCK_TIME lock_time)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~(0x3 << 3);
    HWREG(RCC_BASE + RCC_O_PLLCFGR) |= (lock_time << 3);
}

//*****************************************************************************
//
// Set_PLL_Sel_PostDIV
//
//*****************************************************************************
static inline void RCC_setPLLSelPostDIV(PLL_SEL_POSTDIV postdiv)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~(0x3 << 1);
    HWREG(RCC_BASE + RCC_O_PLLCFGR) |= (postdiv << 1);
}

//*****************************************************************************
//
// Set_PLL_Force_Lock
//
//*****************************************************************************
static inline void RCC_setPLLForceLock(PLL_FORCE_LOCK forceLock)
{
    HWREG(RCC_BASE + RCC_O_PLLCFGR) &= ~(0x1 << 0);
    HWREG(RCC_BASE + RCC_O_PLLCFGR) |= (forceLock << 0);
}

//*****************************************************************************
//
// RCC_setMCDEnable
//
//*****************************************************************************
static inline void RCC_setMCDEnable(void)
{
    HWREG(RCC_BASE + RCC_O_MCDCR) |= REF_LOST_MCD_EN;
}

//*****************************************************************************
//
// RCC_setMCDDisable
//
//*****************************************************************************
static inline void RCC_setMCDDisable(void)
{
    HWREG(RCC_BASE + RCC_O_MCDCR) |= REF_LOST_MCD_EN;
}

//*****************************************************************************
//
// RCC_getMCDStatus
//
//*****************************************************************************
static inline uint32_t RCC_getMCDStatus()
{

    return  (HWREG(RCC_BASE + RCC_O_MCDCR) &REF_LOST_STS_FLAG);

}

//*****************************************************************************
//
// RCC_getCPUresetFlag
//
//*****************************************************************************
static inline uint32_t RCC_getCPUresetFlag()
{
    return  (HWREG(RCC_BASE + RCC_O_CSR) &RCC_CSR_CPURSTF);
}

//*****************************************************************************
//
// RCC_getPINresetFlag
//
//*****************************************************************************
static inline uint32_t RCC_getPINresetFlag()
{
    return  (HWREG(RCC_BASE + RCC_O_CSR) &RCC_CSR_PINRSTF);
}

//*****************************************************************************
//
// RCC_getPORresetFlag
//
//*****************************************************************************
static inline uint32_t RCC_getPORresetFlag()
{
    return  (HWREG(RCC_BASE + RCC_O_CSR) &RCC_CSR_PORRSTF);
}

//*****************************************************************************
//
// RCC_getSFTresetFlag
//
//*****************************************************************************
static inline uint32_t RCC_getSFTresetFlag()
{
    return  (HWREG(RCC_BASE + RCC_O_CSR) &RCC_CSR_SFTRSTF);
}

//*****************************************************************************
//
// RCC_getIWDGresetFlag
//
//*****************************************************************************
static inline uint32_t RCC_getIWDGresetFlag()
{
    return  (HWREG(RCC_BASE + RCC_O_CSR) &RCC_CSR_IWDGRSTF);
}

//*****************************************************************************
//
// RCC_getWWDGresetFlag
//
//*****************************************************************************
static inline uint32_t RCC_getWWDGresetFlag()
{
    return  (HWREG(RCC_BASE + RCC_O_CSR) &RCC_CSR_WWDGRSTF);
}

//*****************************************************************************
//
// RCC_getLPWresetFlag
//
//*****************************************************************************
static inline uint32_t RCC_getLPWresetFlag()
{
    return  (HWREG(RCC_BASE + RCC_O_CSR) &RCC_CSR_LPWRRSTF);
}

//*****************************************************************************
//
// RCC_AHBRSTR1_ResetCmd
//
//*****************************************************************************
static inline void RCC_AHBRSTR1_ResetCmd(AHB1_RST cmd)
{
    //
    // Delay counter
    //
    uint32_t delay_num = 1000;

    //
    // Set reset bit
    //
    HWREG(RCC_BASE + RCC_O_AHBRSTR1) |= (0x1 << cmd);

    //
    // Delay to wait for reset completion
    //
    while (delay_num--);

    //
    // Clear reset bit
    //
    HWREG(RCC_BASE + RCC_O_AHBRSTR1) &= ~(0x1 << cmd);
}

//*****************************************************************************
//
// RCC_AHBRSTR2_ResetCmd
//
//*****************************************************************************
static inline void RCC_AHBRSTR2_ResetCmd(AHB2_RST cmd)
{
    //
    // Delay counter
    //
    uint32_t delay_num = 1000;

    //
    // Set reset bit
    //
    HWREG(RCC_BASE + RCC_O_AHBRSTR2) |= (0x1 << cmd);

    //
    // Delay to wait for reset completion
    //
    while (delay_num--);

    //
    // Clear reset bit
    //
    HWREG(RCC_BASE + RCC_O_AHBRSTR2) &= ~(0x1 << cmd);
}

//*****************************************************************************
//
// RCC_APBHRSTR_ResetCmd
//
//*****************************************************************************
static inline void RCC_APBHRSTR_ResetCmd(APBHR_RST cmd)
{
    //
    // Delay counter
    //
    uint32_t delay_num = 1000;

    //
    // Set reset bit
    //
    HWREG(RCC_BASE + RCC_O_APBHRSTR) |= (0x1 << cmd);

    //
    // Delay to wait for reset completion
    //
    while (delay_num--);

    //
    // Clear reset bit
    //
    HWREG(RCC_BASE + RCC_O_APBHRSTR) &= ~(0x1 << cmd);
}

//*****************************************************************************
//
// RCC_APBLRSTR1_ResetCmd
//
//*****************************************************************************
static inline void RCC_APBLRSTR1_ResetCmd(APBLR1_RST cmd)
{
    //
    // Delay counter
    //
    uint32_t delay_num = 1000;

    //
    // Set reset bit
    //
    HWREG(RCC_BASE + RCC_O_APBLRSTR1) |= (0x1 << cmd);

    //
    // Delay to wait for reset completion
    //
    while (delay_num--);

    //
    // Clear reset bit
    //
    HWREG(RCC_BASE + RCC_O_APBLRSTR1) &= ~(0x1 << cmd);
}

//*****************************************************************************
//
// RCC_APBLRSTR2_ResetCmd
//
//*****************************************************************************
static inline void RCC_APBLRSTR2_ResetCmd(APBLR2_RST cmd)
{
    //
    // Delay counter
    //
    uint32_t delay_num = 1000;

    //
    // Set reset bit
    //
    HWREG(RCC_BASE + RCC_O_APBLRSTR2) |= (0x1 << cmd);

    //
    // Delay to wait for reset completion
    //
    while (delay_num--);

    //
    // Clear reset bit
    //
    HWREG(RCC_BASE + RCC_O_APBLRSTR2) &= ~(0x1 << cmd);
}

//*****************************************************************************
//
// RCC_AHB1PeriphClockCmd
//
//*****************************************************************************
static inline void RCC_AHB1PeriphClockCmd(AHB1_EN RCC_AHB1Periph,FunctionalState state)
{
    //
    // Clear corresponding clock bit first
    //
    HWREG(RCC_BASE + RCC_O_AHBENR1) &= ~(0x1 << RCC_AHB1Periph);

    //
    // Enable or keep disabled based on state
    //
    if(state != DISABLE)
    {
        HWREG(RCC_BASE + RCC_O_AHBENR1) |= (0x1 << RCC_AHB1Periph);
    }
}

//*****************************************************************************
//
// RCC_AHB2PeriphClockCmd
//
//*****************************************************************************
static inline void RCC_AHB2PeriphClockCmd(AHB2_EN RCC_AHB2Periph,FunctionalState state)
{
    //
    // Clear corresponding clock bit first
    //
    HWREG(RCC_BASE + RCC_O_AHBENR2) &= ~(0x1 << RCC_AHB2Periph);

    //
    // Enable or keep disabled based on state
    //
    if(state != DISABLE)
    {
        HWREG(RCC_BASE + RCC_O_AHBENR2) |= (0x1 << RCC_AHB2Periph);
    }
}

//*****************************************************************************
//
// RCC_APBL1PeriphClockCmd
//
//*****************************************************************************
static inline void RCC_APBL1PeriphClockCmd(APBL1_EN RCC_APBL1Periph,FunctionalState state)
{
    //
    // Clear corresponding clock bit first
    //
    HWREG(RCC_BASE + RCC_O_APBLENR1) &= ~(0x1 << RCC_APBL1Periph);

    //
    // Enable or keep disabled based on state
    //
    if(state != DISABLE)
    {
        HWREG(RCC_BASE + RCC_O_APBLENR1) |= (0x1 << RCC_APBL1Periph);
    }
}

//*****************************************************************************
//
// RCC_APBL2PeriphClockCmd
//
//*****************************************************************************
static inline void RCC_APBL2PeriphClockCmd(APBL2_EN RCC_APBL2Periph,FunctionalState state)
{
    //
    // Clear corresponding clock bit first
    //
    HWREG(RCC_BASE + RCC_O_APBLENR2) &= ~(0x1 << RCC_APBL2Periph);

    //
    // Enable or keep disabled based on state
    //
    if(state != DISABLE)
    {
        HWREG(RCC_BASE + RCC_O_APBLENR2) |= (0x1 << RCC_APBL2Periph);
    }
}

void RCC_ClkConfig(SYS_CLK_SRC sys_clk_src, OSC_SRC_SEL osc_src,
        uint8_t pll_loop, PLL_PRE_DIV pll_div_pre, AHB_PRE_DIV AHB_div,
        APBH_PRE_DIV APBH_div, APBL_PRE_DIV APBL_div);

#elif RCC_HW_VER == 1

typedef enum {
    RCC_SMCM1_RST           = 0x00,
    RCC_SMCM2_RST           = 0x01,
    RCC_ROM1_RST            = 0x02,
    RCC_ROM2_RST            = 0x03,
    RCC_ROM3_RST            = 0x04,
    RCC_ROM4_RST            = 0x05,
    RCC_XFLASHC1_RST        = 0x06,
    RCC_XFLASHC2_RST        = 0x07,
    RCC_CPU_LCM_RST         = 0x08,
    RCC_DMA1_RST            = 0x09,
    RCC_DMA2_RST            = 0x0A,
    RCC_DMA_LCM_RST         = 0x0B,
    RCC_SMCA_RST            = 0x0C,
    RCC_FFT_RST             = 0x0D,
    RCC_UCIE_RST            = 0x0E,
    RCC_HACL_RST            = 0x0F,
    RCC_USB_RST             = 0x10,
    RCC_NPU_RST             = 0x11,
    RCC_ECAP1_RST           = 0x12,
    RCC_ECAP2_RST           = 0x13,
    RCC_ECAP3_RST           = 0x14,
    RCC_ECAP4_RST           = 0x15,
    RCC_ECAP5_RST           = 0x16,
    RCC_ECAP6_RST           = 0x17,
    RCC_ECAP7_RST           = 0x18,
    RCC_EQEP1_RST           = 0x19,
    RCC_EQEP2_RST           = 0x1A,
    RCC_EQEP3_RST           = 0x1B,
    RCC_EQEP4_RST           = 0x1C,
    RCC_EQEP5_RST           = 0x1D,
    RCC_EQEP6_RST           = 0x1E,
    RCC_SDFM1_RST           = 0x1F,
    RCC_SDFM2_RST           = 0x20,
    RCC_SDFM3_RST           = 0x21,
    RCC_SDFM4_RST           = 0x22,
    RCC_CMPSS1_RST          = 0x23,
    RCC_CMPSS2_RST          = 0x24,
    RCC_CMPSS3_RST          = 0x25,
    RCC_CMPSS4_RST          = 0x26,
    RCC_CMPSS5_RST          = 0x27,
    RCC_CMPSS6_RST          = 0x28,
    RCC_CMPSS7_RST          = 0x29,
    RCC_CMPSS8_RST          = 0x2A,
    RCC_CMPSS9_RST          = 0x2B,
    RCC_CMPSS10_RST         = 0x2C,
    RCC_CMPSS11_RST         = 0x2D,
    RCC_EPWM1_RST           = 0x2E,
    RCC_EPWM2_RST           = 0x2F,
    RCC_EPWM3_RST           = 0x30,
    RCC_EPWM4_RST           = 0x31,
    RCC_EPWM5_RST           = 0x32,
    RCC_EPWM6_RST           = 0x33,
    RCC_EPWM7_RST           = 0x34,
    RCC_EPWM8_RST           = 0x35,
    RCC_EPWM9_RST           = 0x36,
    RCC_EPWM10_RST          = 0x37,
    RCC_EPWM11_RST          = 0x38,
    RCC_EPWM12_RST          = 0x39,
    RCC_EPWM13_RST          = 0x3A,
    RCC_EPWM14_RST          = 0x3B,
    RCC_EPWM15_RST          = 0x3C,
    RCC_EPWM16_RST          = 0x3D,
    RCC_EPWM17_RST          = 0x3E,
    RCC_EPWM18_RST          = 0x3F,
    RCC_DAC1_RST            = 0x40,
    RCC_DAC2_RST            = 0x41,
    RCC_SPL_RST             = 0x42,
    RCC_RSVD0_RST           = 0x43,
    RCC_ADC_RST             = 0x44,
    RCC_FSMC_RST            = 0x45,
    RCC_EPG_RST             = 0x46,
    RCC_CLB_SUB_RST         = 0x47,
    RCC_INPUT_XBAR_RST      = 0x48,
    RCC_OUTPUT_XBAR_RST     = 0x49,
    RCC_EPWM_XBAR_RST       = 0x4A,
    RCC_CLB_XBAR_RST        = 0x4B,
    RCC_CLB_INPUT_XBAR_RST  = 0x4C,
    RCC_CLB_OUTPUT_XBAR_RST = 0x4D,
    RCC_MIN_DB_XBAR_RST     = 0x4E,
    RCC_ICL_XBAR_RST        = 0x4F,
    RCC_SCA_RST             = 0x50,
    RCC_ETHERCAT_RST        = 0x51,
    RCC_DMA_SCH_RST         = 0x52,
    RCC_CTRL_SUB_RST        = 0x53,
    RCC_ADC1_RST            = 0x54,
    RCC_ADC2_RST            = 0x55,
    RCC_CRC1_RST            = 0x56,
    RCC_CRC2_RST            = 0x57,
    RCC_RSVD1_RST           = 0x58,
    RCC_CAN1_RST            = 0x59,
    RCC_CAN2_RST            = 0x5A,
    RCC_CAN3_RST            = 0x5B,
    RCC_XIAOLIAN_RST        = 0x5C,
    RCC_ADC3_RST            = 0x5D,
    RCC_RSVD2_RST           = 0x5E,
    RCC_RSVD3_RST           = 0x5F,
    RCC_BSPI1_RST           = 0x60,
    RCC_BSPI2_RST           = 0x61,
    RCC_BSPI3_RST           = 0x62,
    RCC_BSPI4_RST           = 0x63,
    RCC_PMBUS_RST           = 0x64,
    RCC_LIN1_RST            = 0x65,
    RCC_LIN2_RST            = 0x66,
    RCC_RSVD4_RST           = 0x67,
    RCC_RSVD5_RST           = 0x68,
    RCC_UART1_RST           = 0x69,
    RCC_UART2_RST           = 0x6A,
    RCC_RSVD6_RST           = 0x6B,
    RCC_UART3_RST           = 0x6C,
    RCC_UART4_RST           = 0x6D,
    RCC_UART5_RST           = 0x6E,
    RCC_UART6_RST           = 0x6F,
    RCC_UART7_RST           = 0x70,
    RCC_UART8_RST           = 0x71,
    RCC_DCC1_RST            = 0x72,
    RCC_TIM1_RST            = 0x73,
    RCC_TIM2_RST            = 0x74,
    RCC_TIM3_RST            = 0x75,
    RCC_TIM4_RST            = 0x76,
    RCC_TIM5_RST            = 0x77,
    RCC_TIM6_RST            = 0x78,
    RCC_DCC2_RST            = 0x79,
    RCC_WWDT1_RST           = 0x7A,
    RCC_WWDT2_RST           = 0x7B,
    RCC_WWDT3_RST           = 0x7C,
    RCC_WWDT4_RST           = 0x7D,
    RCC_IWDT1_RST           = 0x7E,
    RCC_IWDT2_RST           = 0x7F,
    RCC_IWDT3_RST           = 0x80,
    RCC_IWDT4_RST           = 0x81,
    RCC_CLB1_RST            = 0x82,
    RCC_CLB2_RST            = 0x83,
    RCC_CLB3_RST            = 0x84,
    RCC_CLB4_RST            = 0x85,
    RCC_CLB5_RST            = 0x86,
    RCC_CLB6_RST            = 0x87,
    RCC_I2C1_RST            = 0x88,
    RCC_I2C2_RST            = 0x89,
    RCC_SYSTEM_CTRL_RST     = 0x8A,
    RCC_GPIO_RST            = 0x8B,
    RCC_LPM_RST             = 0x8C,
    RCC_SPI5_RST            = 0x8D,
    RCC_SPI6_RST            = 0x8E,
    RCC_HMS0_RST            = 0x8F,
    RCC_HMS1_RST            = 0x90,
    RCC_HMS2_RST            = 0x91,
    RCC_HMS3_RST            = 0x92,
    RCC_TAC_RST             = 0x93,
}RCC_ResetSrc;

void RCC_ResetPeripheral(RCC_ResetSrc src);
void RCC_holdResetPeripheral(RCC_ResetSrc src);
void RCC_releaseResetPeripheral(RCC_ResetSrc src);
static inline uint32_t RCC_getAHBPrescaler(void)
{
    return 1;
}
static inline uint32_t RCC_getAPBHPrescaler(void)
{
    return 1;
}
static inline uint32_t RCC_getAPBLPrescaler(void)
{
    return 1;
}

#else

#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __RCC_H */

