/**
  *************************************************************************************
  * @file hw_gpio.h
  * @brief This file contains the definition of hw_gpio driver.
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

#ifndef HW_GPIO_H
#define HW_GPIO_H

#if GPIO_HW_VER==0x00

#define GPIO_SWPORT_DR             (0x00)     /* Port A Data Register. */
#define GPIO_SWPORT_DDR            (0x04)     /* Port A Data Direction Register. */
#define GPIO_SWPORT_CTL            (0x08)     /* Port A Data Source, not use.*/


#define GPIO_INTEN                  (0x30)     /* Interrupt enable. Can only be a PORTA */
#define GPIO_INTMASK                (0x34)     /* Interrupt mask.Can only be a PORTA*/
#define GPIO_INTTYPE_LEVEL          (0x38)     /* Interrupt level.Can only be a PORTA*/
#define GPIO_INT_POLARITY           (0x3c)     /* Interrupt polarity.Can only be a PORTA*/
#define GPIO_INTSTATUS              (0x40)     /* Interrupt status.Can only be a PORTA*/
#define GPIO_RAW_INTSTATUS          (0x44)     /* Raw interrupt status.Can only be a PORTA*/
#define GPIO_PORT_DEBOUNCE          (0x48)     /* Debounce enable.Can only be a PORTA*/
#define GPIO_PORT_EOI               (0x4c)     /* Clear interrupt.Can only be a PORTA*/
#define GPIO_EXT_PORT              (0x50)      /* External Port A, use read gpio-pin value.*/

#define GPIO_LS_SYNC                (0x60)     /*not use*/
/*GPIO info. General GPIO operation is not used*/
#define GPIO_ID_CODE                (0x64)     /* GPIO ID code*/
#define GPIO_INT_BOTHEDGE           (0x68)     /* Interrupt both edge type*/
#define GPIO_VER_ID_CODE            (0x6c)     /* GPIO Component Version*/
#define GPIO_CONFIG_REG2            (0x70)     /* GPIO Configuration Register 2*/
#define GPIO_CONFIG_REG1            (0x74)     /* GPIO Configuration Register 1*/

#define GPIO_BITBAND_WR             (0x100)   /*bitband写第GPIO的第n bit，效果和写GPIO_SWPORTA_DR[n]相同。此寄存器有更高的写优先级。n = 0 to 31*/
#define GPIO_BITBAND_RD             (0x180)  /*bitband读GPIO的第n bit，读取值为GPIO_EXT_PORTA[n]展宽到32bit。n = 0 to 31*/

#endif
#if GPIO_HW_VER==0x01
typedef struct  {
    __IO uint32_t GPXCTL;
    __IO uint32_t GPXQAEL1;
    __IO uint32_t GPXQSEL2;
    __IO uint32_t GPXMUX1;
    __IO uint32_t GPXMUX2;
    __IO uint32_t GPXDIR;
    __IO uint32_t GPXPUD;
    __IO uint32_t reserved1[1];

    __IO uint32_t GPXINV;
    __IO uint32_t GPXODR;
    __IO uint32_t GPXAMSEL;
    __IO uint32_t reserved2[5];

    __IO uint32_t GPXGMUX1;
    __IO uint32_t GPXGMUX2;
    __IO uint32_t reserved3[2];
    __IO uint32_t GPXCSEL1;
    __IO uint32_t GPXCSEL2;
    __IO uint32_t GPXCSEL3;
    __IO uint32_t GPXCSEL4;

    __IO uint32_t reserved4[6];
    __IO uint32_t GPXLOCK;
    __IO uint32_t GPXCR;
} GPIO_PortCtrlType;
typedef struct{
	GPIO_PortCtrlType Port[8];
}GPIO_CtrlType;

typedef struct  {
    __IO uint32_t GPXDAT;
    __IO uint32_t GPXSET;
    __IO uint32_t GPXCLEAR;
    __IO uint32_t GPXTOGGLE;
} GPIO_PortDataType;
typedef struct{
	GPIO_PortDataType Port[8];
}GPIO_DataType;

typedef struct{
    __IO uint32_t GPADAT_R;
    __IO uint32_t GPBDAT_R;
    __IO uint32_t GPCDAT_R;
    __IO uint32_t GPDDAT_R;
    __IO uint32_t GPEDAT_R;
    __IO uint32_t GPFDAT_R;
    __IO uint32_t GPGDAT_R;
    __IO uint32_t GPHDAT_R;
}GPIO_DataRType;
#define GPIO_Ctrl ((GPIO_CtrlType*)GPIOCTRL_BASE)
#define GPIO_Data ((GPIO_DataType*)GPIODATA_BASE)
#define GPIO_DataR ((GPIO_DataRType*)GPIODATA_BASE)
//*************************************************************************************************
//
// The following are defines for the GPIO register offsets
//
//*************************************************************************************************
#define GPIO_O_GPACTRL    (0x0U<<1)     // GPIO A Qualification Sampling Period Control (GPIO0 to 31)
#define GPIO_O_GPAQSEL1   (0x2U<<1)     // GPIO A Qualifier Select 1 Register (GPIO0 to 15)
#define GPIO_O_GPAQSEL2   (0x4U<<1)     // GPIO A Qualifier Select 2 Register (GPIO16 to 31)
#define GPIO_O_GPAMUX1    (0x6U<<1)     // GPIO A Mux 1 Register (GPIO0 to 15)
#define GPIO_O_GPAMUX2    (0x8U<<1)     // GPIO A Mux 2 Register (GPIO16 to 31)
#define GPIO_O_GPADIR     (0xAU<<1)     // GPIO A Direction Register (GPIO0 to 31)
#define GPIO_O_GPAPUD     (0xCU<<1)     // GPIO A Pull Up Disable Register (GPIO0 to 31)
#define GPIO_O_GPAINV     (0x10U<<1)    // GPIO A Input Polarity Invert Registers (GPIO0 to 31)
#define GPIO_O_GPAODR     (0x12U<<1)    // GPIO A Open Drain Output Register (GPIO0 to GPIO31)
#define GPIO_O_GPAPUDEN   (0x1CU<<1)
#define GPIO_O_GPAGMUX1   (0x20U<<1)    // GPIO A Peripheral Group Mux (GPIO0 to 15)
#define GPIO_O_GPAGMUX2   (0x22U<<1)    // GPIO A Peripheral Group Mux (GPIO16 to 31)
#define GPIO_O_GPACSEL1   (0x28U<<1)    // GPIO A Core Select Register (GPIO0 to 7)
#define GPIO_O_GPACSEL2   (0x2AU<<1)    // GPIO A Core Select Register (GPIO8 to 15)
#define GPIO_O_GPACSEL3   (0x2CU<<1)    // GPIO A Core Select Register (GPIO16 to 23)
#define GPIO_O_GPACSEL4   (0x2EU<<1)    // GPIO A Core Select Register (GPIO24 to 31)
#define GPIO_O_GPALOCK    (0x3CU<<1)    // GPIO A Lock Configuration Register (GPIO0 to 31)
#define GPIO_O_GPACR      (0x3EU<<1)    // GPIO A Lock Commit Register (GPIO0 to 31)
#define GPIO_O_GPBCTRL    (0x40U<<1)    // GPIO B Qualification Sampling Period Control (GPIO32 to 63)
#define GPIO_O_GPBQSEL1   (0x42U<<1)    // GPIO B Qualifier Select 1 Register (GPIO32 to 47)
#define GPIO_O_GPBQSEL2   (0x44U<<1)    // GPIO B Qualifier Select 2 Register (GPIO48 to 63)
#define GPIO_O_GPBMUX1    (0x46U<<1)    // GPIO B Mux 1 Register (GPIO32 to 47)
#define GPIO_O_GPBMUX2    (0x48U<<1)    // GPIO B Mux 2 Register (GPIO48 to 63)
#define GPIO_O_GPBDIR     (0x4AU<<1)    // GPIO B Direction Register (GPIO32 to 63)
#define GPIO_O_GPBPUD     (0x4CU<<1)    // GPIO B Pull Up Disable Register (GPIO32 to 63)
#define GPIO_O_GPBINV     (0x50U<<1)    // GPIO B Input Polarity Invert Registers (GPIO32 to 63)
#define GPIO_O_GPBODR     (0x52U<<1)    // GPIO B Open Drain Output Register (GPIO32 to GPIO63)
#define GPIO_O_GPBAMSEL   (0x54U<<1)    // GPIO B Analog Mode Select register (GPIO32 to GPIO63)
#define GPIO_O_GPBGMUX1   (0x60U<<1)    // GPIO B Peripheral Group Mux (GPIO32 to 47)
#define GPIO_O_GPBGMUX2   (0x62U<<1)    // GPIO B Peripheral Group Mux (GPIO48 to 63)
#define GPIO_O_GPBCSEL1   (0x68U<<1)    // GPIO B Core Select Register (GPIO32 to 39)
#define GPIO_O_GPBCSEL2   (0x6AU<<1)    // GPIO B Core Select Register (GPIO40 to 47)
#define GPIO_O_GPBCSEL3   (0x6CU<<1)    // GPIO B Core Select Register (GPIO48 to 55)
#define GPIO_O_GPBCSEL4   (0x6EU<<1)    // GPIO B Core Select Register (GPIO56 to 63)
#define GPIO_O_GPBLOCK    (0x7CU<<1)    // GPIO B Lock Configuration Register (GPIO32 to 63)
#define GPIO_O_GPBCR      (0x7EU<<1)    // GPIO B Lock Commit Register (GPIO32 to 63)
#define GPIO_O_GPCCTRL    (0x80U<<1)    // GPIO C Qualification Sampling Period Control (GPIO64 to 95)
#define GPIO_O_GPCQSEL1   (0x82U<<1)    // GPIO C Qualifier Select 1 Register (GPIO64 to 79)
#define GPIO_O_GPCQSEL2   (0x84U<<1)    // GPIO C Qualifier Select 2 Register (GPIO80  to 95)
#define GPIO_O_GPCMUX1    (0x86U<<1)    // GPIO C Mux 1 Register (GPIO64 to 79)
#define GPIO_O_GPCMUX2    (0x88U<<1)    // GPIO C Mux 2 Register (GPIO80  to 95)
#define GPIO_O_GPCDIR     (0x8AU<<1)    // GPIO C Direction Register (GPIO64 to 95)
#define GPIO_O_GPCPUD     (0x8CU<<1)    // GPIO C Pull Up Disable Register (GPIO64 to 95)
#define GPIO_O_GPCINV     (0x90U<<1)    // GPIO C Input Polarity Invert Registers (GPIO64 to 95)
#define GPIO_O_GPCODR     (0x92U<<1)    // GPIO C Open Drain Output Register (GPIO64 to GPIO95)
#define GPIO_O_GPCGMUX1   (0xA0U<<1)    // GPIO C Peripheral Group Mux (GPIO64 to 79)
#define GPIO_O_GPCGMUX2   (0xA2U<<1)    // GPIO C Peripheral Group Mux (GPIO80  to 95)
#define GPIO_O_GPCCSEL1   (0xA8U<<1)    // GPIO C Core Select Register (GPIO64 to 71)
#define GPIO_O_GPCCSEL2   (0xAAU<<1)    // GPIO C Core Select Register (GPIO72 to 79)
#define GPIO_O_GPCCSEL3   (0xACU<<1)    // GPIO C Core Select Register (GPIO80  to 87)
#define GPIO_O_GPCCSEL4   (0xAEU<<1)    // GPIO C Core Select Register (GPIO88 to 95)
#define GPIO_O_GPCLOCK    (0xBCU<<1)    // GPIO C Lock Configuration Register (GPIO64 to 95)
#define GPIO_O_GPCCR      (0xBEU<<1)    // GPIO C Lock Commit Register (GPIO64 to 95)
#define GPIO_O_GPDCTRL    (0xC0U<<1)    // GPIO D Qualification Sampling Period Control (GPIO96 to 127)
#define GPIO_O_GPDQSEL1   (0xC2U<<1)    // GPIO D Qualifier Select 1 Register (GPIO96 to 111)
#define GPIO_O_GPDQSEL2   (0xC4U<<1)    // GPIO D Qualifier Select 2 Register (GPIO112 to 127)
#define GPIO_O_GPDMUX1    (0xC6U<<1)    // GPIO D Mux 1 Register (GPIO96 to 111)
#define GPIO_O_GPDMUX2    (0xC8U<<1)    // GPIO D Mux 2 Register (GPIO112 to 127)
#define GPIO_O_GPDDIR     (0xCAU<<1)    // GPIO D Direction Register (GPIO96 to 127)
#define GPIO_O_GPDPUD     (0xCCU<<1)    // GPIO D Pull Up Disable Register (GPIO96 to 127)
#define GPIO_O_GPDINV     (0xD0U<<1)    // GPIO D Input Polarity Invert Registers (GPIO96 to 127)
#define GPIO_O_GPDODR     (0xD2U<<1)    // GPIO D Open Drain Output Register (GPIO96 to GPIO127)
#define GPIO_O_GPDGMUX1   (0xE0U<<1)    // GPIO D Peripheral Group Mux (GPIO96 to 111)
#define GPIO_O_GPDGMUX2   (0xE2U<<1)    // GPIO D Peripheral Group Mux (GPIO112 to 127)
#define GPIO_O_GPDCSEL1   (0xE8U<<1)    // GPIO D Core Select Register (GPIO96 to 103)
#define GPIO_O_GPDCSEL2   (0xEAU<<1)    // GPIO D Core Select Register (GPIO104 to 111)
#define GPIO_O_GPDCSEL3   (0xECU<<1)    // GPIO D Core Select Register (GPIO112 to 119)
#define GPIO_O_GPDCSEL4   (0xEEU<<1)    // GPIO D Core Select Register (GPIO120 to 127)
#define GPIO_O_GPDLOCK    (0xFCU<<1)    // GPIO D Lock Configuration Register (GPIO96 to 127)
#define GPIO_O_GPDCR      (0xFEU<<1)    // GPIO D Lock Commit Register (GPIO96 to 127)
#define GPIO_O_GPECTRL    (0x100U<<1)   // GPIO E Qualification Sampling Period Control (GPIO128 to 159)
#define GPIO_O_GPEQSEL1   (0x102U<<1)   // GPIO E Qualifier Select 1 Register (GPIO128 to 143)
#define GPIO_O_GPEQSEL2   (0x104U<<1)   // GPIO E Qualifier Select 2 Register (GPIO144  to 159)
#define GPIO_O_GPEMUX1    (0x106U<<1)   // GPIO E Mux 1 Register (GPIO128 to 143)
#define GPIO_O_GPEMUX2    (0x108U<<1)   // GPIO E Mux 2 Register (GPIO144  to 159)
#define GPIO_O_GPEDIR     (0x10AU<<1)   // GPIO E Direction Register (GPIO128 to 159)
#define GPIO_O_GPEPUD     (0x10CU<<1)   // GPIO E Pull Up Disable Register (GPIO128 to 159)
#define GPIO_O_GPEINV     (0x110U<<1)   // GPIO E Input Polarity Invert Registers (GPIO128 to 159)
#define GPIO_O_GPEODR     (0x112U<<1)   // GPIO E Open Drain Output Register (GPIO128 to GPIO159)
#define GPIO_O_GPEGMUX1   (0x120U<<1)   // GPIO E Peripheral Group Mux (GPIO128 to 143)
#define GPIO_O_GPEGMUX2   (0x122U<<1)   // GPIO E Peripheral Group Mux (GPIO144  to 159)
#define GPIO_O_GPECSEL1   (0x128U<<1)   // GPIO E Core Select Register (GPIO128 to 135)
#define GPIO_O_GPECSEL2   (0x12AU<<1)   // GPIO E Core Select Register (GPIO136 to 143)
#define GPIO_O_GPECSEL3   (0x12CU<<1)   // GPIO E Core Select Register (GPIO144  to 151)
#define GPIO_O_GPECSEL4   (0x12EU<<1)   // GPIO E Core Select Register (GPIO152 to 159)
#define GPIO_O_GPELOCK    (0x13CU<<1)   // GPIO E Lock Configuration Register (GPIO128 to 159)
#define GPIO_O_GPECR      (0x13EU<<1)   // GPIO E Lock Commit Register (GPIO128 to 159)
#define GPIO_O_GPFCTRL    (0x140U<<1)   // GPIO F Qualification Sampling Period Control (GPIO160 to 191)
#define GPIO_O_GPFQSEL1   (0x142U<<1)   // GPIO F Qualifier Select 1 Register (GPIO160 to 175)
#define GPIO_O_GPFQSEL2   (0x144U<<1)   // GPIO F Qualifier Select 1 Register (GPIO176 to 181) //add
#define GPIO_O_GPFMUX1    (0x146U<<1)   // GPIO F Mux 1 Register (GPIO160 to 175)
#define GPIO_O_GPFMUX2    (0x148U<<1)   // GPIO F Mux 2 Register (GPIO176 to 181) //add
#define GPIO_O_GPFDIR     (0x14AU<<1)   // GPIO F Direction Register (GPIO160 to 191)
#define GPIO_O_GPFPUD     (0x14CU<<1)   // GPIO F Pull Up Disable Register (GPIO160 to 191)
#define GPIO_O_GPFINV     (0x150U<<1)   // GPIO F Input Polarity Invert Registers (GPIO160 to 191)
#define GPIO_O_GPFODR     (0x152U<<1)   // GPIO F Open Drain Output Register (GPIO160 to GPIO191)
#define GPIO_O_GPFGMUX1   (0x160U<<1)   // GPIO F Peripheral Group Mux (GPIO160 to 175)
#define GPIO_O_GPFGMUX2   (0x162U<<1)   // GPIO F Peripheral Group Mux (GPIO176 to 181) //add
#define GPIO_O_GPFCSEL1   (0x168U<<1)   // GPIO F Core Select Register (GPIO160 to 167)
#define GPIO_O_GPFCSEL2   (0x16AU<<1)   // GPIO F Core Select Register (GPIO168 to 175)
#define GPIO_O_GPFCSEL3   (0x16CU<<1)   // GPIO F Core Select Register (GPIO176 to 181)
#define GPIO_O_GPFCSEL4   (0x16EU<<1)   // GPIO F Core Select Register (GPIO176 to 181)
#define GPIO_O_GPFLOCK    (0x17CU<<1)   // GPIO F Lock Configuration Register (GPIO160 to 191)
#define GPIO_O_GPFCR      (0x17EU<<1)   // GPIO F Lock Commit Register (GPIO160 to 191)



#define GPIO_O_GPADAT      (0x0U<<1)    // GPIO A Data Register (GPIO0 to 31)
#define GPIO_O_GPASET      (0x2U<<1)    // GPIO A Data Set Register (GPIO0 to 31)
#define GPIO_O_GPACLEAR    (0x4U<<1)    // GPIO A Data Clear Register (GPIO0 to 31)
#define GPIO_O_GPATOGGLE   (0x6U<<1)    // GPIO A Data Toggle Register (GPIO0 to 31)
#define GPIO_O_GPBDAT      (0x8U<<1)    // GPIO B Data Register (GPIO32 to 63)
#define GPIO_O_GPBSET      (0xAU<<1)    // GPIO B Data Set Register (GPIO32 to 63)
#define GPIO_O_GPBCLEAR    (0xCU<<1)    // GPIO B Data Clear Register (GPIO32 to 63)
#define GPIO_O_GPBTOGGLE   (0xEU<<1)    // GPIO B Data Toggle Register (GPIO32 to 63)
#define GPIO_O_GPCDAT      (0x10U<<1)   // GPIO C Data Register (GPIO64 to 95)
#define GPIO_O_GPCSET      (0x12U<<1)   // GPIO C Data Set Register (GPIO64 to 95)
#define GPIO_O_GPCCLEAR    (0x14U<<1)   // GPIO C Data Clear Register (GPIO64 to 95)
#define GPIO_O_GPCTOGGLE   (0x16U<<1)   // GPIO C Data Toggle Register (GPIO64 to 95)
#define GPIO_O_GPDDAT      (0x18U<<1)   // GPIO D Data Register (GPIO96 to 127)
#define GPIO_O_GPDSET      (0x1AU<<1)   // GPIO D Data Set Register (GPIO96 to 127)
#define GPIO_O_GPDCLEAR    (0x1CU<<1)   // GPIO D Data Clear Register (GPIO96 to 127)
#define GPIO_O_GPDTOGGLE   (0x1EU<<1)   // GPIO D Data Toggle Register (GPIO96 to 127)
#define GPIO_O_GPEDAT      (0x20U<<1)   // GPIO E Data Register (GPIO128 to 159)
#define GPIO_O_GPESET      (0x22U<<1)   // GPIO E Data Set Register (GPIO128 to 159)
#define GPIO_O_GPECLEAR    (0x24U<<1)   // GPIO E Data Clear Register (GPIO128 to 159)
#define GPIO_O_GPETOGGLE   (0x26U<<1)   // GPIO E Data Toggle Register (GPIO128 to 159)
#define GPIO_O_GPFDAT      (0x28U<<1)   // GPIO F Data Register (GPIO160 to 191)~181
#define GPIO_O_GPFSET      (0x2AU<<1)   // GPIO F Data Set Register (GPIO160 to 191)~181
#define GPIO_O_GPFCLEAR    (0x2CU<<1)   // GPIO F Data Clear Register (GPIO160 to 191)~181
#define GPIO_O_GPFTOGGLE   (0x2EU<<1)   // GPIO F Data Toggle Register (GPIO160 to 191)~181

#define GPIO_O_GPADAT_R   (0x0U<<1)   // GPIO A Data Read Register
#define GPIO_O_GPBDAT_R   (0x2U<<1)   // GPIO B Data Read Register
#define GPIO_O_GPCDAT_R   (0x4U<<1)   // GPIO C Data Read Register
#define GPIO_O_GPDDAT_R   (0x6U<<1)   // GPIO D Data Read Register
#define GPIO_O_GPEDAT_R   (0x8U<<1)   // GPIO E Data Read Register
#define GPIO_O_GPFDAT_R   (0xAU<<1)   // GPIO F Data Read Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPACTRL register
//
//*************************************************************************************************
#define GPIO_GPACTRL_QUALPRD0_S   0U
#define GPIO_GPACTRL_QUALPRD0_M   0xFFU         // Qualification sampling period for GPIO0 to GPIO7
#define GPIO_GPACTRL_QUALPRD1_S   8U
#define GPIO_GPACTRL_QUALPRD1_M   0xFF00U       // Qualification sampling period for GPIO8 to
                                                // GPIO15
#define GPIO_GPACTRL_QUALPRD2_S   16U
#define GPIO_GPACTRL_QUALPRD2_M   0xFF0000U     // Qualification sampling period for GPIO16 to
                                                // GPIO23
#define GPIO_GPACTRL_QUALPRD3_S   24U
#define GPIO_GPACTRL_QUALPRD3_M   0xFF000000U   // Qualification sampling period for GPIO24 to
                                                // GPIO31

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAQSEL1 register
//
//*************************************************************************************************
#define GPIO_GPAQSEL1_GPIO0_S    0U
#define GPIO_GPAQSEL1_GPIO0_M    0x3U          // Select input qualification type for GPIO0
#define GPIO_GPAQSEL1_GPIO1_S    2U
#define GPIO_GPAQSEL1_GPIO1_M    0xCU          // Select input qualification type for GPIO1
#define GPIO_GPAQSEL1_GPIO2_S    4U
#define GPIO_GPAQSEL1_GPIO2_M    0x30U         // Select input qualification type for GPIO2
#define GPIO_GPAQSEL1_GPIO3_S    6U
#define GPIO_GPAQSEL1_GPIO3_M    0xC0U         // Select input qualification type for GPIO3
#define GPIO_GPAQSEL1_GPIO4_S    8U
#define GPIO_GPAQSEL1_GPIO4_M    0x300U        // Select input qualification type for GPIO4
#define GPIO_GPAQSEL1_GPIO5_S    10U
#define GPIO_GPAQSEL1_GPIO5_M    0xC00U        // Select input qualification type for GPIO5
#define GPIO_GPAQSEL1_GPIO6_S    12U
#define GPIO_GPAQSEL1_GPIO6_M    0x3000U       // Select input qualification type for GPIO6
#define GPIO_GPAQSEL1_GPIO7_S    14U
#define GPIO_GPAQSEL1_GPIO7_M    0xC000U       // Select input qualification type for GPIO7
#define GPIO_GPAQSEL1_GPIO8_S    16U
#define GPIO_GPAQSEL1_GPIO8_M    0x30000U      // Select input qualification type for GPIO8
#define GPIO_GPAQSEL1_GPIO9_S    18U
#define GPIO_GPAQSEL1_GPIO9_M    0xC0000U      // Select input qualification type for GPIO9
#define GPIO_GPAQSEL1_GPIO10_S   20U
#define GPIO_GPAQSEL1_GPIO10_M   0x300000U     // Select input qualification type for GPIO10
#define GPIO_GPAQSEL1_GPIO11_S   22U
#define GPIO_GPAQSEL1_GPIO11_M   0xC00000U     // Select input qualification type for GPIO11
#define GPIO_GPAQSEL1_GPIO12_S   24U
#define GPIO_GPAQSEL1_GPIO12_M   0x3000000U    // Select input qualification type for GPIO12
#define GPIO_GPAQSEL1_GPIO13_S   26U
#define GPIO_GPAQSEL1_GPIO13_M   0xC000000U    // Select input qualification type for GPIO13
#define GPIO_GPAQSEL1_GPIO14_S   28U
#define GPIO_GPAQSEL1_GPIO14_M   0x30000000U   // Select input qualification type for GPIO14
#define GPIO_GPAQSEL1_GPIO15_S   30U
#define GPIO_GPAQSEL1_GPIO15_M   0xC0000000U   // Select input qualification type for GPIO15

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAQSEL2 register
//
//*************************************************************************************************
#define GPIO_GPAQSEL2_GPIO16_S   0U
#define GPIO_GPAQSEL2_GPIO16_M   0x3U          // Select input qualification type for GPIO16
#define GPIO_GPAQSEL2_GPIO17_S   2U
#define GPIO_GPAQSEL2_GPIO17_M   0xCU          // Select input qualification type for GPIO17
#define GPIO_GPAQSEL2_GPIO18_S   4U
#define GPIO_GPAQSEL2_GPIO18_M   0x30U         // Select input qualification type for GPIO18
#define GPIO_GPAQSEL2_GPIO19_S   6U
#define GPIO_GPAQSEL2_GPIO19_M   0xC0U         // Select input qualification type for GPIO19
#define GPIO_GPAQSEL2_GPIO20_S   8U
#define GPIO_GPAQSEL2_GPIO20_M   0x300U        // Select input qualification type for GPIO20
#define GPIO_GPAQSEL2_GPIO21_S   10U
#define GPIO_GPAQSEL2_GPIO21_M   0xC00U        // Select input qualification type for GPIO21
#define GPIO_GPAQSEL2_GPIO22_S   12U
#define GPIO_GPAQSEL2_GPIO22_M   0x3000U       // Select input qualification type for GPIO22
#define GPIO_GPAQSEL2_GPIO23_S   14U
#define GPIO_GPAQSEL2_GPIO23_M   0xC000U       // Select input qualification type for GPIO23
#define GPIO_GPAQSEL2_GPIO24_S   16U
#define GPIO_GPAQSEL2_GPIO24_M   0x30000U      // Select input qualification type for GPIO24
#define GPIO_GPAQSEL2_GPIO25_S   18U
#define GPIO_GPAQSEL2_GPIO25_M   0xC0000U      // Select input qualification type for GPIO25
#define GPIO_GPAQSEL2_GPIO26_S   20U
#define GPIO_GPAQSEL2_GPIO26_M   0x300000U     // Select input qualification type for GPIO26
#define GPIO_GPAQSEL2_GPIO27_S   22U
#define GPIO_GPAQSEL2_GPIO27_M   0xC00000U     // Select input qualification type for GPIO27
#define GPIO_GPAQSEL2_GPIO28_S   24U
#define GPIO_GPAQSEL2_GPIO28_M   0x3000000U    // Select input qualification type for GPIO28
#define GPIO_GPAQSEL2_GPIO29_S   26U
#define GPIO_GPAQSEL2_GPIO29_M   0xC000000U    // Select input qualification type for GPIO29
#define GPIO_GPAQSEL2_GPIO30_S   28U
#define GPIO_GPAQSEL2_GPIO30_M   0x30000000U   // Select input qualification type for GPIO30
#define GPIO_GPAQSEL2_GPIO31_S   30U
#define GPIO_GPAQSEL2_GPIO31_M   0xC0000000U   // Select input qualification type for GPIO31

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAMUX1 register
//
//*************************************************************************************************
#define GPIO_GPAMUX1_GPIO0_S    0U
#define GPIO_GPAMUX1_GPIO0_M    0x3U          // Defines pin-muxing selection for GPIO0
#define GPIO_GPAMUX1_GPIO1_S    2U
#define GPIO_GPAMUX1_GPIO1_M    0xCU          // Defines pin-muxing selection for GPIO1
#define GPIO_GPAMUX1_GPIO2_S    4U
#define GPIO_GPAMUX1_GPIO2_M    0x30U         // Defines pin-muxing selection for GPIO2
#define GPIO_GPAMUX1_GPIO3_S    6U
#define GPIO_GPAMUX1_GPIO3_M    0xC0U         // Defines pin-muxing selection for GPIO3
#define GPIO_GPAMUX1_GPIO4_S    8U
#define GPIO_GPAMUX1_GPIO4_M    0x300U        // Defines pin-muxing selection for GPIO4
#define GPIO_GPAMUX1_GPIO5_S    10U
#define GPIO_GPAMUX1_GPIO5_M    0xC00U        // Defines pin-muxing selection for GPIO5
#define GPIO_GPAMUX1_GPIO6_S    12U
#define GPIO_GPAMUX1_GPIO6_M    0x3000U       // Defines pin-muxing selection for GPIO6
#define GPIO_GPAMUX1_GPIO7_S    14U
#define GPIO_GPAMUX1_GPIO7_M    0xC000U       // Defines pin-muxing selection for GPIO7
#define GPIO_GPAMUX1_GPIO8_S    16U
#define GPIO_GPAMUX1_GPIO8_M    0x30000U      // Defines pin-muxing selection for GPIO8
#define GPIO_GPAMUX1_GPIO9_S    18U
#define GPIO_GPAMUX1_GPIO9_M    0xC0000U      // Defines pin-muxing selection for GPIO9
#define GPIO_GPAMUX1_GPIO10_S   20U
#define GPIO_GPAMUX1_GPIO10_M   0x300000U     // Defines pin-muxing selection for GPIO10
#define GPIO_GPAMUX1_GPIO11_S   22U
#define GPIO_GPAMUX1_GPIO11_M   0xC00000U     // Defines pin-muxing selection for GPIO11
#define GPIO_GPAMUX1_GPIO12_S   24U
#define GPIO_GPAMUX1_GPIO12_M   0x3000000U    // Defines pin-muxing selection for GPIO12
#define GPIO_GPAMUX1_GPIO13_S   26U
#define GPIO_GPAMUX1_GPIO13_M   0xC000000U    // Defines pin-muxing selection for GPIO13
#define GPIO_GPAMUX1_GPIO14_S   28U
#define GPIO_GPAMUX1_GPIO14_M   0x30000000U   // Defines pin-muxing selection for GPIO14
#define GPIO_GPAMUX1_GPIO15_S   30U
#define GPIO_GPAMUX1_GPIO15_M   0xC0000000U   // Defines pin-muxing selection for GPIO15

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAMUX2 register
//
//*************************************************************************************************
#define GPIO_GPAMUX2_GPIO16_S   0U
#define GPIO_GPAMUX2_GPIO16_M   0x3U          // Defines pin-muxing selection for GPIO16
#define GPIO_GPAMUX2_GPIO17_S   2U
#define GPIO_GPAMUX2_GPIO17_M   0xCU          // Defines pin-muxing selection for GPIO17
#define GPIO_GPAMUX2_GPIO18_S   4U
#define GPIO_GPAMUX2_GPIO18_M   0x30U         // Defines pin-muxing selection for GPIO18
#define GPIO_GPAMUX2_GPIO19_S   6U
#define GPIO_GPAMUX2_GPIO19_M   0xC0U         // Defines pin-muxing selection for GPIO19
#define GPIO_GPAMUX2_GPIO20_S   8U
#define GPIO_GPAMUX2_GPIO20_M   0x300U        // Defines pin-muxing selection for GPIO20
#define GPIO_GPAMUX2_GPIO21_S   10U
#define GPIO_GPAMUX2_GPIO21_M   0xC00U        // Defines pin-muxing selection for GPIO21
#define GPIO_GPAMUX2_GPIO22_S   12U
#define GPIO_GPAMUX2_GPIO22_M   0x3000U       // Defines pin-muxing selection for GPIO22
#define GPIO_GPAMUX2_GPIO23_S   14U
#define GPIO_GPAMUX2_GPIO23_M   0xC000U       // Defines pin-muxing selection for GPIO23
#define GPIO_GPAMUX2_GPIO24_S   16U
#define GPIO_GPAMUX2_GPIO24_M   0x30000U      // Defines pin-muxing selection for GPIO24
#define GPIO_GPAMUX2_GPIO25_S   18U
#define GPIO_GPAMUX2_GPIO25_M   0xC0000U      // Defines pin-muxing selection for GPIO25
#define GPIO_GPAMUX2_GPIO26_S   20U
#define GPIO_GPAMUX2_GPIO26_M   0x300000U     // Defines pin-muxing selection for GPIO26
#define GPIO_GPAMUX2_GPIO27_S   22U
#define GPIO_GPAMUX2_GPIO27_M   0xC00000U     // Defines pin-muxing selection for GPIO27
#define GPIO_GPAMUX2_GPIO28_S   24U
#define GPIO_GPAMUX2_GPIO28_M   0x3000000U    // Defines pin-muxing selection for GPIO28
#define GPIO_GPAMUX2_GPIO29_S   26U
#define GPIO_GPAMUX2_GPIO29_M   0xC000000U    // Defines pin-muxing selection for GPIO29
#define GPIO_GPAMUX2_GPIO30_S   28U
#define GPIO_GPAMUX2_GPIO30_M   0x30000000U   // Defines pin-muxing selection for GPIO30
#define GPIO_GPAMUX2_GPIO31_S   30U
#define GPIO_GPAMUX2_GPIO31_M   0xC0000000U   // Defines pin-muxing selection for GPIO31

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPADIR register
//
//*************************************************************************************************
#define GPIO_GPADIR_GPIO0    0x1U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO1    0x2U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO2    0x4U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO3    0x8U          // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO4    0x10U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO5    0x20U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO6    0x40U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO7    0x80U         // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO8    0x100U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO9    0x200U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO10   0x400U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO11   0x800U        // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO12   0x1000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO13   0x2000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO14   0x4000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO15   0x8000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO16   0x10000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO17   0x20000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO18   0x40000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO19   0x80000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO20   0x100000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO21   0x200000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO22   0x400000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO23   0x800000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO24   0x1000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO25   0x2000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO26   0x4000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO27   0x8000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO28   0x10000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO29   0x20000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO30   0x40000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPADIR_GPIO31   0x80000000U   // Defines direction for this pin in GPIO mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAPUD register
//
//*************************************************************************************************
#define GPIO_GPAPUD_GPIO0    0x1U          // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO1    0x2U          // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO2    0x4U          // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO3    0x8U          // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO4    0x10U         // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO5    0x20U         // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO6    0x40U         // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO7    0x80U         // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO8    0x100U        // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO9    0x200U        // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO10   0x400U        // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO11   0x800U        // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO12   0x1000U       // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO13   0x2000U       // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO14   0x4000U       // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO15   0x8000U       // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO16   0x10000U      // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO17   0x20000U      // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO18   0x40000U      // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO19   0x80000U      // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO20   0x100000U     // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO21   0x200000U     // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO22   0x400000U     // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO23   0x800000U     // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO24   0x1000000U    // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO25   0x2000000U    // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO26   0x4000000U    // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO27   0x8000000U    // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO28   0x10000000U   // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO29   0x20000000U   // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO30   0x40000000U   // Pull-Up Disable control for this pin
#define GPIO_GPAPUD_GPIO31   0x80000000U   // Pull-Up Disable control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAINV register
//
//*************************************************************************************************
#define GPIO_GPAINV_GPIO0    0x1U          // Input inversion control for this pin
#define GPIO_GPAINV_GPIO1    0x2U          // Input inversion control for this pin
#define GPIO_GPAINV_GPIO2    0x4U          // Input inversion control for this pin
#define GPIO_GPAINV_GPIO3    0x8U          // Input inversion control for this pin
#define GPIO_GPAINV_GPIO4    0x10U         // Input inversion control for this pin
#define GPIO_GPAINV_GPIO5    0x20U         // Input inversion control for this pin
#define GPIO_GPAINV_GPIO6    0x40U         // Input inversion control for this pin
#define GPIO_GPAINV_GPIO7    0x80U         // Input inversion control for this pin
#define GPIO_GPAINV_GPIO8    0x100U        // Input inversion control for this pin
#define GPIO_GPAINV_GPIO9    0x200U        // Input inversion control for this pin
#define GPIO_GPAINV_GPIO10   0x400U        // Input inversion control for this pin
#define GPIO_GPAINV_GPIO11   0x800U        // Input inversion control for this pin
#define GPIO_GPAINV_GPIO12   0x1000U       // Input inversion control for this pin
#define GPIO_GPAINV_GPIO13   0x2000U       // Input inversion control for this pin
#define GPIO_GPAINV_GPIO14   0x4000U       // Input inversion control for this pin
#define GPIO_GPAINV_GPIO15   0x8000U       // Input inversion control for this pin
#define GPIO_GPAINV_GPIO16   0x10000U      // Input inversion control for this pin
#define GPIO_GPAINV_GPIO17   0x20000U      // Input inversion control for this pin
#define GPIO_GPAINV_GPIO18   0x40000U      // Input inversion control for this pin
#define GPIO_GPAINV_GPIO19   0x80000U      // Input inversion control for this pin
#define GPIO_GPAINV_GPIO20   0x100000U     // Input inversion control for this pin
#define GPIO_GPAINV_GPIO21   0x200000U     // Input inversion control for this pin
#define GPIO_GPAINV_GPIO22   0x400000U     // Input inversion control for this pin
#define GPIO_GPAINV_GPIO23   0x800000U     // Input inversion control for this pin
#define GPIO_GPAINV_GPIO24   0x1000000U    // Input inversion control for this pin
#define GPIO_GPAINV_GPIO25   0x2000000U    // Input inversion control for this pin
#define GPIO_GPAINV_GPIO26   0x4000000U    // Input inversion control for this pin
#define GPIO_GPAINV_GPIO27   0x8000000U    // Input inversion control for this pin
#define GPIO_GPAINV_GPIO28   0x10000000U   // Input inversion control for this pin
#define GPIO_GPAINV_GPIO29   0x20000000U   // Input inversion control for this pin
#define GPIO_GPAINV_GPIO30   0x40000000U   // Input inversion control for this pin
#define GPIO_GPAINV_GPIO31   0x80000000U   // Input inversion control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAODR register
//
//*************************************************************************************************
#define GPIO_GPAODR_GPIO0    0x1U          // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO1    0x2U          // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO2    0x4U          // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO3    0x8U          // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO4    0x10U         // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO5    0x20U         // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO6    0x40U         // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO7    0x80U         // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO8    0x100U        // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO9    0x200U        // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO10   0x400U        // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO11   0x800U        // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO12   0x1000U       // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO13   0x2000U       // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO14   0x4000U       // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO15   0x8000U       // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO16   0x10000U      // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO17   0x20000U      // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO18   0x40000U      // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO19   0x80000U      // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO20   0x100000U     // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO21   0x200000U     // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO22   0x400000U     // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO23   0x800000U     // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO24   0x1000000U    // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO25   0x2000000U    // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO26   0x4000000U    // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO27   0x8000000U    // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO28   0x10000000U   // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO29   0x20000000U   // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO30   0x40000000U   // Output Open-Drain control for this pin
#define GPIO_GPAODR_GPIO31   0x80000000U   // Output Open-Drain control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAGMUX1 register
//
//*************************************************************************************************
#define GPIO_GPAGMUX1_GPIO0_S    0U
#define GPIO_GPAGMUX1_GPIO0_M    0x3U          // Defines pin-muxing selection for GPIO0
#define GPIO_GPAGMUX1_GPIO1_S    2U
#define GPIO_GPAGMUX1_GPIO1_M    0xCU          // Defines pin-muxing selection for GPIO1
#define GPIO_GPAGMUX1_GPIO2_S    4U
#define GPIO_GPAGMUX1_GPIO2_M    0x30U         // Defines pin-muxing selection for GPIO2
#define GPIO_GPAGMUX1_GPIO3_S    6U
#define GPIO_GPAGMUX1_GPIO3_M    0xC0U         // Defines pin-muxing selection for GPIO3
#define GPIO_GPAGMUX1_GPIO4_S    8U
#define GPIO_GPAGMUX1_GPIO4_M    0x300U        // Defines pin-muxing selection for GPIO4
#define GPIO_GPAGMUX1_GPIO5_S    10U
#define GPIO_GPAGMUX1_GPIO5_M    0xC00U        // Defines pin-muxing selection for GPIO5
#define GPIO_GPAGMUX1_GPIO6_S    12U
#define GPIO_GPAGMUX1_GPIO6_M    0x3000U       // Defines pin-muxing selection for GPIO6
#define GPIO_GPAGMUX1_GPIO7_S    14U
#define GPIO_GPAGMUX1_GPIO7_M    0xC000U       // Defines pin-muxing selection for GPIO7
#define GPIO_GPAGMUX1_GPIO8_S    16U
#define GPIO_GPAGMUX1_GPIO8_M    0x30000U      // Defines pin-muxing selection for GPIO8
#define GPIO_GPAGMUX1_GPIO9_S    18U
#define GPIO_GPAGMUX1_GPIO9_M    0xC0000U      // Defines pin-muxing selection for GPIO9
#define GPIO_GPAGMUX1_GPIO10_S   20U
#define GPIO_GPAGMUX1_GPIO10_M   0x300000U     // Defines pin-muxing selection for GPIO10
#define GPIO_GPAGMUX1_GPIO11_S   22U
#define GPIO_GPAGMUX1_GPIO11_M   0xC00000U     // Defines pin-muxing selection for GPIO11
#define GPIO_GPAGMUX1_GPIO12_S   24U
#define GPIO_GPAGMUX1_GPIO12_M   0x3000000U    // Defines pin-muxing selection for GPIO12
#define GPIO_GPAGMUX1_GPIO13_S   26U
#define GPIO_GPAGMUX1_GPIO13_M   0xC000000U    // Defines pin-muxing selection for GPIO13
#define GPIO_GPAGMUX1_GPIO14_S   28U
#define GPIO_GPAGMUX1_GPIO14_M   0x30000000U   // Defines pin-muxing selection for GPIO14
#define GPIO_GPAGMUX1_GPIO15_S   30U
#define GPIO_GPAGMUX1_GPIO15_M   0xC0000000U   // Defines pin-muxing selection for GPIO15

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPAGMUX2 register
//
//*************************************************************************************************
#define GPIO_GPAGMUX2_GPIO16_S   0U
#define GPIO_GPAGMUX2_GPIO16_M   0x3U          // Defines pin-muxing selection for GPIO16
#define GPIO_GPAGMUX2_GPIO17_S   2U
#define GPIO_GPAGMUX2_GPIO17_M   0xCU          // Defines pin-muxing selection for GPIO17
#define GPIO_GPAGMUX2_GPIO18_S   4U
#define GPIO_GPAGMUX2_GPIO18_M   0x30U         // Defines pin-muxing selection for GPIO18
#define GPIO_GPAGMUX2_GPIO19_S   6U
#define GPIO_GPAGMUX2_GPIO19_M   0xC0U         // Defines pin-muxing selection for GPIO19
#define GPIO_GPAGMUX2_GPIO20_S   8U
#define GPIO_GPAGMUX2_GPIO20_M   0x300U        // Defines pin-muxing selection for GPIO20
#define GPIO_GPAGMUX2_GPIO21_S   10U
#define GPIO_GPAGMUX2_GPIO21_M   0xC00U        // Defines pin-muxing selection for GPIO21
#define GPIO_GPAGMUX2_GPIO22_S   12U
#define GPIO_GPAGMUX2_GPIO22_M   0x3000U       // Defines pin-muxing selection for GPIO22
#define GPIO_GPAGMUX2_GPIO23_S   14U
#define GPIO_GPAGMUX2_GPIO23_M   0xC000U       // Defines pin-muxing selection for GPIO23
#define GPIO_GPAGMUX2_GPIO24_S   16U
#define GPIO_GPAGMUX2_GPIO24_M   0x30000U      // Defines pin-muxing selection for GPIO24
#define GPIO_GPAGMUX2_GPIO25_S   18U
#define GPIO_GPAGMUX2_GPIO25_M   0xC0000U      // Defines pin-muxing selection for GPIO25
#define GPIO_GPAGMUX2_GPIO26_S   20U
#define GPIO_GPAGMUX2_GPIO26_M   0x300000U     // Defines pin-muxing selection for GPIO26
#define GPIO_GPAGMUX2_GPIO27_S   22U
#define GPIO_GPAGMUX2_GPIO27_M   0xC00000U     // Defines pin-muxing selection for GPIO27
#define GPIO_GPAGMUX2_GPIO28_S   24U
#define GPIO_GPAGMUX2_GPIO28_M   0x3000000U    // Defines pin-muxing selection for GPIO28
#define GPIO_GPAGMUX2_GPIO29_S   26U
#define GPIO_GPAGMUX2_GPIO29_M   0xC000000U    // Defines pin-muxing selection for GPIO29
#define GPIO_GPAGMUX2_GPIO30_S   28U
#define GPIO_GPAGMUX2_GPIO30_M   0x30000000U   // Defines pin-muxing selection for GPIO30
#define GPIO_GPAGMUX2_GPIO31_S   30U
#define GPIO_GPAGMUX2_GPIO31_M   0xC0000000U   // Defines pin-muxing selection for GPIO31

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPACSEL1 register
//
//*************************************************************************************************
#define GPIO_GPACSEL1_GPIO0_S   0U
#define GPIO_GPACSEL1_GPIO0_M   0xFU          // GPIO0 Controller CPU Select
#define GPIO_GPACSEL1_GPIO1_S   4U
#define GPIO_GPACSEL1_GPIO1_M   0xF0U         // GPIO1 Controller CPU Select
#define GPIO_GPACSEL1_GPIO2_S   8U
#define GPIO_GPACSEL1_GPIO2_M   0xF00U        // GPIO2 Controller CPU Select
#define GPIO_GPACSEL1_GPIO3_S   12U
#define GPIO_GPACSEL1_GPIO3_M   0xF000U       // GPIO3 Controller CPU Select
#define GPIO_GPACSEL1_GPIO4_S   16U
#define GPIO_GPACSEL1_GPIO4_M   0xF0000U      // GPIO4 Controller CPU Select
#define GPIO_GPACSEL1_GPIO5_S   20U
#define GPIO_GPACSEL1_GPIO5_M   0xF00000U     // GPIO5 Controller CPU Select
#define GPIO_GPACSEL1_GPIO6_S   24U
#define GPIO_GPACSEL1_GPIO6_M   0xF000000U    // GPIO6 Controller CPU Select
#define GPIO_GPACSEL1_GPIO7_S   28U
#define GPIO_GPACSEL1_GPIO7_M   0xF0000000U   // GPIO7 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPACSEL2 register
//
//*************************************************************************************************
#define GPIO_GPACSEL2_GPIO8_S    0U
#define GPIO_GPACSEL2_GPIO8_M    0xFU          // GPIO8 Controller CPU Select
#define GPIO_GPACSEL2_GPIO9_S    4U
#define GPIO_GPACSEL2_GPIO9_M    0xF0U         // GPIO9 Controller CPU Select
#define GPIO_GPACSEL2_GPIO10_S   8U
#define GPIO_GPACSEL2_GPIO10_M   0xF00U        // GPIO10 Controller CPU Select
#define GPIO_GPACSEL2_GPIO11_S   12U
#define GPIO_GPACSEL2_GPIO11_M   0xF000U       // GPIO11 Controller CPU Select
#define GPIO_GPACSEL2_GPIO12_S   16U
#define GPIO_GPACSEL2_GPIO12_M   0xF0000U      // GPIO12 Controller CPU Select
#define GPIO_GPACSEL2_GPIO13_S   20U
#define GPIO_GPACSEL2_GPIO13_M   0xF00000U     // GPIO13 Controller CPU Select
#define GPIO_GPACSEL2_GPIO14_S   24U
#define GPIO_GPACSEL2_GPIO14_M   0xF000000U    // GPIO14 Controller CPU Select
#define GPIO_GPACSEL2_GPIO15_S   28U
#define GPIO_GPACSEL2_GPIO15_M   0xF0000000U   // GPIO15 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPACSEL3 register
//
//*************************************************************************************************
#define GPIO_GPACSEL3_GPIO16_S   0U
#define GPIO_GPACSEL3_GPIO16_M   0xFU          // GPIO16 Controller CPU Select
#define GPIO_GPACSEL3_GPIO17_S   4U
#define GPIO_GPACSEL3_GPIO17_M   0xF0U         // GPIO17 Controller CPU Select
#define GPIO_GPACSEL3_GPIO18_S   8U
#define GPIO_GPACSEL3_GPIO18_M   0xF00U        // GPIO18 Controller CPU Select
#define GPIO_GPACSEL3_GPIO19_S   12U
#define GPIO_GPACSEL3_GPIO19_M   0xF000U       // GPIO19 Controller CPU Select
#define GPIO_GPACSEL3_GPIO20_S   16U
#define GPIO_GPACSEL3_GPIO20_M   0xF0000U      // GPIO20 Controller CPU Select
#define GPIO_GPACSEL3_GPIO21_S   20U
#define GPIO_GPACSEL3_GPIO21_M   0xF00000U     // GPIO21 Controller CPU Select
#define GPIO_GPACSEL3_GPIO22_S   24U
#define GPIO_GPACSEL3_GPIO22_M   0xF000000U    // GPIO22 Controller CPU Select
#define GPIO_GPACSEL3_GPIO23_S   28U
#define GPIO_GPACSEL3_GPIO23_M   0xF0000000U   // GPIO23 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPACSEL4 register
//
//*************************************************************************************************
#define GPIO_GPACSEL4_GPIO24_S   0U
#define GPIO_GPACSEL4_GPIO24_M   0xFU          // GPIO24 Controller CPU Select
#define GPIO_GPACSEL4_GPIO25_S   4U
#define GPIO_GPACSEL4_GPIO25_M   0xF0U         // GPIO25 Controller CPU Select
#define GPIO_GPACSEL4_GPIO26_S   8U
#define GPIO_GPACSEL4_GPIO26_M   0xF00U        // GPIO26 Controller CPU Select
#define GPIO_GPACSEL4_GPIO27_S   12U
#define GPIO_GPACSEL4_GPIO27_M   0xF000U       // GPIO27 Controller CPU Select
#define GPIO_GPACSEL4_GPIO28_S   16U
#define GPIO_GPACSEL4_GPIO28_M   0xF0000U      // GPIO28 Controller CPU Select
#define GPIO_GPACSEL4_GPIO29_S   20U
#define GPIO_GPACSEL4_GPIO29_M   0xF00000U     // GPIO29 Controller CPU Select
#define GPIO_GPACSEL4_GPIO30_S   24U
#define GPIO_GPACSEL4_GPIO30_M   0xF000000U    // GPIO30 Controller CPU Select
#define GPIO_GPACSEL4_GPIO31_S   28U
#define GPIO_GPACSEL4_GPIO31_M   0xF0000000U   // GPIO31 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPALOCK register
//
//*************************************************************************************************
#define GPIO_GPALOCK_GPIO0    0x1U          // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO1    0x2U          // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO2    0x4U          // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO3    0x8U          // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO4    0x10U         // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO5    0x20U         // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO6    0x40U         // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO7    0x80U         // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO8    0x100U        // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO9    0x200U        // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO10   0x400U        // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO11   0x800U        // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO12   0x1000U       // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO13   0x2000U       // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO14   0x4000U       // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO15   0x8000U       // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO16   0x10000U      // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO17   0x20000U      // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO18   0x40000U      // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO19   0x80000U      // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO20   0x100000U     // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO21   0x200000U     // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO22   0x400000U     // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO23   0x800000U     // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO24   0x1000000U    // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO25   0x2000000U    // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO26   0x4000000U    // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO27   0x8000000U    // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO28   0x10000000U   // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO29   0x20000000U   // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO30   0x40000000U   // Configuration Lock bit for this pin
#define GPIO_GPALOCK_GPIO31   0x80000000U   // Configuration Lock bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPACR register
//
//*************************************************************************************************
#define GPIO_GPACR_GPIO0    0x1U          // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO1    0x2U          // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO2    0x4U          // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO3    0x8U          // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO4    0x10U         // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO5    0x20U         // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO6    0x40U         // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO7    0x80U         // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO8    0x100U        // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO9    0x200U        // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO10   0x400U        // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO11   0x800U        // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO12   0x1000U       // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO13   0x2000U       // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO14   0x4000U       // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO15   0x8000U       // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO16   0x10000U      // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO17   0x20000U      // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO18   0x40000U      // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO19   0x80000U      // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO20   0x100000U     // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO21   0x200000U     // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO22   0x400000U     // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO23   0x800000U     // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO24   0x1000000U    // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO25   0x2000000U    // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO26   0x4000000U    // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO27   0x8000000U    // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO28   0x10000000U   // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO29   0x20000000U   // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO30   0x40000000U   // Configuration lock commit bit for this pin
#define GPIO_GPACR_GPIO31   0x80000000U   // Configuration lock commit bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBCTRL register
//
//*************************************************************************************************
#define GPIO_GPBCTRL_QUALPRD0_S   0U
#define GPIO_GPBCTRL_QUALPRD0_M   0xFFU         // Qualification sampling period for GPIO32 to
                                                // GPIO39
#define GPIO_GPBCTRL_QUALPRD1_S   8U
#define GPIO_GPBCTRL_QUALPRD1_M   0xFF00U       // Qualification sampling period for GPIO40 to
                                                // GPIO47
#define GPIO_GPBCTRL_QUALPRD2_S   16U
#define GPIO_GPBCTRL_QUALPRD2_M   0xFF0000U     // Qualification sampling period for GPIO48 to
                                                // GPIO55
#define GPIO_GPBCTRL_QUALPRD3_S   24U
#define GPIO_GPBCTRL_QUALPRD3_M   0xFF000000U   // Qualification sampling period for GPIO56 to
                                                // GPIO63

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBQSEL1 register
//
//*************************************************************************************************
#define GPIO_GPBQSEL1_GPIO32_S   0U
#define GPIO_GPBQSEL1_GPIO32_M   0x3U          // Select input qualification type for GPIO32
#define GPIO_GPBQSEL1_GPIO33_S   2U
#define GPIO_GPBQSEL1_GPIO33_M   0xCU          // Select input qualification type for GPIO33
#define GPIO_GPBQSEL1_GPIO34_S   4U
#define GPIO_GPBQSEL1_GPIO34_M   0x30U         // Select input qualification type for GPIO34
#define GPIO_GPBQSEL1_GPIO35_S   6U
#define GPIO_GPBQSEL1_GPIO35_M   0xC0U         // Select input qualification type for GPIO35
#define GPIO_GPBQSEL1_GPIO36_S   8U
#define GPIO_GPBQSEL1_GPIO36_M   0x300U        // Select input qualification type for GPIO36
#define GPIO_GPBQSEL1_GPIO37_S   10U
#define GPIO_GPBQSEL1_GPIO37_M   0xC00U        // Select input qualification type for GPIO37
#define GPIO_GPBQSEL1_GPIO38_S   12U
#define GPIO_GPBQSEL1_GPIO38_M   0x3000U       // Select input qualification type for GPIO38
#define GPIO_GPBQSEL1_GPIO39_S   14U
#define GPIO_GPBQSEL1_GPIO39_M   0xC000U       // Select input qualification type for GPIO39
#define GPIO_GPBQSEL1_GPIO40_S   16U
#define GPIO_GPBQSEL1_GPIO40_M   0x30000U      // Select input qualification type for GPIO40
#define GPIO_GPBQSEL1_GPIO41_S   18U
#define GPIO_GPBQSEL1_GPIO41_M   0xC0000U      // Select input qualification type for GPIO41
#define GPIO_GPBQSEL1_GPIO42_S   20U
#define GPIO_GPBQSEL1_GPIO42_M   0x300000U     // Select input qualification type for GPIO42
#define GPIO_GPBQSEL1_GPIO43_S   22U
#define GPIO_GPBQSEL1_GPIO43_M   0xC00000U     // Select input qualification type for GPIO43
#define GPIO_GPBQSEL1_GPIO44_S   24U
#define GPIO_GPBQSEL1_GPIO44_M   0x3000000U    // Select input qualification type for GPIO44
#define GPIO_GPBQSEL1_GPIO45_S   26U
#define GPIO_GPBQSEL1_GPIO45_M   0xC000000U    // Select input qualification type for GPIO45
#define GPIO_GPBQSEL1_GPIO46_S   28U
#define GPIO_GPBQSEL1_GPIO46_M   0x30000000U   // Select input qualification type for GPIO46
#define GPIO_GPBQSEL1_GPIO47_S   30U
#define GPIO_GPBQSEL1_GPIO47_M   0xC0000000U   // Select input qualification type for GPIO47

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBQSEL2 register
//
//*************************************************************************************************
#define GPIO_GPBQSEL2_GPIO48_S   0U
#define GPIO_GPBQSEL2_GPIO48_M   0x3U          // Select input qualification type for GPIO48
#define GPIO_GPBQSEL2_GPIO49_S   2U
#define GPIO_GPBQSEL2_GPIO49_M   0xCU          // Select input qualification type for GPIO49
#define GPIO_GPBQSEL2_GPIO50_S   4U
#define GPIO_GPBQSEL2_GPIO50_M   0x30U         // Select input qualification type for GPIO50
#define GPIO_GPBQSEL2_GPIO51_S   6U
#define GPIO_GPBQSEL2_GPIO51_M   0xC0U         // Select input qualification type for GPIO51
#define GPIO_GPBQSEL2_GPIO52_S   8U
#define GPIO_GPBQSEL2_GPIO52_M   0x300U        // Select input qualification type for GPIO52
#define GPIO_GPBQSEL2_GPIO53_S   10U
#define GPIO_GPBQSEL2_GPIO53_M   0xC00U        // Select input qualification type for GPIO53
#define GPIO_GPBQSEL2_GPIO54_S   12U
#define GPIO_GPBQSEL2_GPIO54_M   0x3000U       // Select input qualification type for GPIO54
#define GPIO_GPBQSEL2_GPIO55_S   14U
#define GPIO_GPBQSEL2_GPIO55_M   0xC000U       // Select input qualification type for GPIO55
#define GPIO_GPBQSEL2_GPIO56_S   16U
#define GPIO_GPBQSEL2_GPIO56_M   0x30000U      // Select input qualification type for GPIO56
#define GPIO_GPBQSEL2_GPIO57_S   18U
#define GPIO_GPBQSEL2_GPIO57_M   0xC0000U      // Select input qualification type for GPIO57
#define GPIO_GPBQSEL2_GPIO58_S   20U
#define GPIO_GPBQSEL2_GPIO58_M   0x300000U     // Select input qualification type for GPIO58
#define GPIO_GPBQSEL2_GPIO59_S   22U
#define GPIO_GPBQSEL2_GPIO59_M   0xC00000U     // Select input qualification type for GPIO59
#define GPIO_GPBQSEL2_GPIO60_S   24U
#define GPIO_GPBQSEL2_GPIO60_M   0x3000000U    // Select input qualification type for GPIO60
#define GPIO_GPBQSEL2_GPIO61_S   26U
#define GPIO_GPBQSEL2_GPIO61_M   0xC000000U    // Select input qualification type for GPIO61
#define GPIO_GPBQSEL2_GPIO62_S   28U
#define GPIO_GPBQSEL2_GPIO62_M   0x30000000U   // Select input qualification type for GPIO62
#define GPIO_GPBQSEL2_GPIO63_S   30U
#define GPIO_GPBQSEL2_GPIO63_M   0xC0000000U   // Select input qualification type for GPIO63

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBMUX1 register
//
//*************************************************************************************************
#define GPIO_GPBMUX1_GPIO32_S   0U
#define GPIO_GPBMUX1_GPIO32_M   0x3U          // Defines pin-muxing selection for GPIO32
#define GPIO_GPBMUX1_GPIO33_S   2U
#define GPIO_GPBMUX1_GPIO33_M   0xCU          // Defines pin-muxing selection for GPIO33
#define GPIO_GPBMUX1_GPIO34_S   4U
#define GPIO_GPBMUX1_GPIO34_M   0x30U         // Defines pin-muxing selection for GPIO34
#define GPIO_GPBMUX1_GPIO35_S   6U
#define GPIO_GPBMUX1_GPIO35_M   0xC0U         // Defines pin-muxing selection for GPIO35
#define GPIO_GPBMUX1_GPIO36_S   8U
#define GPIO_GPBMUX1_GPIO36_M   0x300U        // Defines pin-muxing selection for GPIO36
#define GPIO_GPBMUX1_GPIO37_S   10U
#define GPIO_GPBMUX1_GPIO37_M   0xC00U        // Defines pin-muxing selection for GPIO37
#define GPIO_GPBMUX1_GPIO38_S   12U
#define GPIO_GPBMUX1_GPIO38_M   0x3000U       // Defines pin-muxing selection for GPIO38
#define GPIO_GPBMUX1_GPIO39_S   14U
#define GPIO_GPBMUX1_GPIO39_M   0xC000U       // Defines pin-muxing selection for GPIO39
#define GPIO_GPBMUX1_GPIO40_S   16U
#define GPIO_GPBMUX1_GPIO40_M   0x30000U      // Defines pin-muxing selection for GPIO40
#define GPIO_GPBMUX1_GPIO41_S   18U
#define GPIO_GPBMUX1_GPIO41_M   0xC0000U      // Defines pin-muxing selection for GPIO41
#define GPIO_GPBMUX1_GPIO42_S   20U
#define GPIO_GPBMUX1_GPIO42_M   0x300000U     // Defines pin-muxing selection for GPIO42
#define GPIO_GPBMUX1_GPIO43_S   22U
#define GPIO_GPBMUX1_GPIO43_M   0xC00000U     // Defines pin-muxing selection for GPIO43
#define GPIO_GPBMUX1_GPIO44_S   24U
#define GPIO_GPBMUX1_GPIO44_M   0x3000000U    // Defines pin-muxing selection for GPIO44
#define GPIO_GPBMUX1_GPIO45_S   26U
#define GPIO_GPBMUX1_GPIO45_M   0xC000000U    // Defines pin-muxing selection for GPIO45
#define GPIO_GPBMUX1_GPIO46_S   28U
#define GPIO_GPBMUX1_GPIO46_M   0x30000000U   // Defines pin-muxing selection for GPIO46
#define GPIO_GPBMUX1_GPIO47_S   30U
#define GPIO_GPBMUX1_GPIO47_M   0xC0000000U   // Defines pin-muxing selection for GPIO47

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBMUX2 register
//
//*************************************************************************************************
#define GPIO_GPBMUX2_GPIO48_S   0U
#define GPIO_GPBMUX2_GPIO48_M   0x3U          // Defines pin-muxing selection for GPIO48
#define GPIO_GPBMUX2_GPIO49_S   2U
#define GPIO_GPBMUX2_GPIO49_M   0xCU          // Defines pin-muxing selection for GPIO49
#define GPIO_GPBMUX2_GPIO50_S   4U
#define GPIO_GPBMUX2_GPIO50_M   0x30U         // Defines pin-muxing selection for GPIO50
#define GPIO_GPBMUX2_GPIO51_S   6U
#define GPIO_GPBMUX2_GPIO51_M   0xC0U         // Defines pin-muxing selection for GPIO51
#define GPIO_GPBMUX2_GPIO52_S   8U
#define GPIO_GPBMUX2_GPIO52_M   0x300U        // Defines pin-muxing selection for GPIO52
#define GPIO_GPBMUX2_GPIO53_S   10U
#define GPIO_GPBMUX2_GPIO53_M   0xC00U        // Defines pin-muxing selection for GPIO53
#define GPIO_GPBMUX2_GPIO54_S   12U
#define GPIO_GPBMUX2_GPIO54_M   0x3000U       // Defines pin-muxing selection for GPIO54
#define GPIO_GPBMUX2_GPIO55_S   14U
#define GPIO_GPBMUX2_GPIO55_M   0xC000U       // Defines pin-muxing selection for GPIO55
#define GPIO_GPBMUX2_GPIO56_S   16U
#define GPIO_GPBMUX2_GPIO56_M   0x30000U      // Defines pin-muxing selection for GPIO56
#define GPIO_GPBMUX2_GPIO57_S   18U
#define GPIO_GPBMUX2_GPIO57_M   0xC0000U      // Defines pin-muxing selection for GPIO57
#define GPIO_GPBMUX2_GPIO58_S   20U
#define GPIO_GPBMUX2_GPIO58_M   0x300000U     // Defines pin-muxing selection for GPIO58
#define GPIO_GPBMUX2_GPIO59_S   22U
#define GPIO_GPBMUX2_GPIO59_M   0xC00000U     // Defines pin-muxing selection for GPIO59
#define GPIO_GPBMUX2_GPIO60_S   24U
#define GPIO_GPBMUX2_GPIO60_M   0x3000000U    // Defines pin-muxing selection for GPIO60
#define GPIO_GPBMUX2_GPIO61_S   26U
#define GPIO_GPBMUX2_GPIO61_M   0xC000000U    // Defines pin-muxing selection for GPIO61
#define GPIO_GPBMUX2_GPIO62_S   28U
#define GPIO_GPBMUX2_GPIO62_M   0x30000000U   // Defines pin-muxing selection for GPIO62
#define GPIO_GPBMUX2_GPIO63_S   30U
#define GPIO_GPBMUX2_GPIO63_M   0xC0000000U   // Defines pin-muxing selection for GPIO63

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBDIR register
//
//*************************************************************************************************
#define GPIO_GPBDIR_GPIO32   0x1U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO33   0x2U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO34   0x4U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO35   0x8U          // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO36   0x10U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO37   0x20U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO38   0x40U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO39   0x80U         // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO40   0x100U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO41   0x200U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO42   0x400U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO43   0x800U        // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO44   0x1000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO45   0x2000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO46   0x4000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO47   0x8000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO48   0x10000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO49   0x20000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO50   0x40000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO51   0x80000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO52   0x100000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO53   0x200000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO54   0x400000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO55   0x800000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO56   0x1000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO57   0x2000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO58   0x4000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO59   0x8000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO60   0x10000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO61   0x20000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO62   0x40000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPBDIR_GPIO63   0x80000000U   // Defines direction for this pin in GPIO mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBPUD register
//
//*************************************************************************************************
#define GPIO_GPBPUD_GPIO32   0x1U          // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO33   0x2U          // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO34   0x4U          // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO35   0x8U          // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO36   0x10U         // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO37   0x20U         // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO38   0x40U         // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO39   0x80U         // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO40   0x100U        // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO41   0x200U        // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO42   0x400U        // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO43   0x800U        // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO44   0x1000U       // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO45   0x2000U       // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO46   0x4000U       // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO47   0x8000U       // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO48   0x10000U      // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO49   0x20000U      // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO50   0x40000U      // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO51   0x80000U      // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO52   0x100000U     // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO53   0x200000U     // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO54   0x400000U     // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO55   0x800000U     // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO56   0x1000000U    // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO57   0x2000000U    // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO58   0x4000000U    // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO59   0x8000000U    // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO60   0x10000000U   // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO61   0x20000000U   // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO62   0x40000000U   // Pull-Up Disable control for this pin
#define GPIO_GPBPUD_GPIO63   0x80000000U   // Pull-Up Disable control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBINV register
//
//*************************************************************************************************
#define GPIO_GPBINV_GPIO32   0x1U          // Input inversion control for this pin
#define GPIO_GPBINV_GPIO33   0x2U          // Input inversion control for this pin
#define GPIO_GPBINV_GPIO34   0x4U          // Input inversion control for this pin
#define GPIO_GPBINV_GPIO35   0x8U          // Input inversion control for this pin
#define GPIO_GPBINV_GPIO36   0x10U         // Input inversion control for this pin
#define GPIO_GPBINV_GPIO37   0x20U         // Input inversion control for this pin
#define GPIO_GPBINV_GPIO38   0x40U         // Input inversion control for this pin
#define GPIO_GPBINV_GPIO39   0x80U         // Input inversion control for this pin
#define GPIO_GPBINV_GPIO40   0x100U        // Input inversion control for this pin
#define GPIO_GPBINV_GPIO41   0x200U        // Input inversion control for this pin
#define GPIO_GPBINV_GPIO42   0x400U        // Input inversion control for this pin
#define GPIO_GPBINV_GPIO43   0x800U        // Input inversion control for this pin
#define GPIO_GPBINV_GPIO44   0x1000U       // Input inversion control for this pin
#define GPIO_GPBINV_GPIO45   0x2000U       // Input inversion control for this pin
#define GPIO_GPBINV_GPIO46   0x4000U       // Input inversion control for this pin
#define GPIO_GPBINV_GPIO47   0x8000U       // Input inversion control for this pin
#define GPIO_GPBINV_GPIO48   0x10000U      // Input inversion control for this pin
#define GPIO_GPBINV_GPIO49   0x20000U      // Input inversion control for this pin
#define GPIO_GPBINV_GPIO50   0x40000U      // Input inversion control for this pin
#define GPIO_GPBINV_GPIO51   0x80000U      // Input inversion control for this pin
#define GPIO_GPBINV_GPIO52   0x100000U     // Input inversion control for this pin
#define GPIO_GPBINV_GPIO53   0x200000U     // Input inversion control for this pin
#define GPIO_GPBINV_GPIO54   0x400000U     // Input inversion control for this pin
#define GPIO_GPBINV_GPIO55   0x800000U     // Input inversion control for this pin
#define GPIO_GPBINV_GPIO56   0x1000000U    // Input inversion control for this pin
#define GPIO_GPBINV_GPIO57   0x2000000U    // Input inversion control for this pin
#define GPIO_GPBINV_GPIO58   0x4000000U    // Input inversion control for this pin
#define GPIO_GPBINV_GPIO59   0x8000000U    // Input inversion control for this pin
#define GPIO_GPBINV_GPIO60   0x10000000U   // Input inversion control for this pin
#define GPIO_GPBINV_GPIO61   0x20000000U   // Input inversion control for this pin
#define GPIO_GPBINV_GPIO62   0x40000000U   // Input inversion control for this pin
#define GPIO_GPBINV_GPIO63   0x80000000U   // Input inversion control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBODR register
//
//*************************************************************************************************
#define GPIO_GPBODR_GPIO32   0x1U          // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO33   0x2U          // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO34   0x4U          // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO35   0x8U          // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO36   0x10U         // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO37   0x20U         // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO38   0x40U         // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO39   0x80U         // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO40   0x100U        // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO41   0x200U        // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO42   0x400U        // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO43   0x800U        // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO44   0x1000U       // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO45   0x2000U       // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO46   0x4000U       // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO47   0x8000U       // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO48   0x10000U      // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO49   0x20000U      // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO50   0x40000U      // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO51   0x80000U      // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO52   0x100000U     // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO53   0x200000U     // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO54   0x400000U     // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO55   0x800000U     // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO56   0x1000000U    // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO57   0x2000000U    // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO58   0x4000000U    // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO59   0x8000000U    // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO60   0x10000000U   // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO61   0x20000000U   // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO62   0x40000000U   // Output Open-Drain control for this pin
#define GPIO_GPBODR_GPIO63   0x80000000U   // Output Open-Drain control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBAMSEL register
//
//*************************************************************************************************
#define GPIO_GPBAMSEL_GPIO42   0x400U   // Analog Mode select for this pin
#define GPIO_GPBAMSEL_GPIO43   0x800U   // Analog Mode select for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBGMUX1 register
//
//*************************************************************************************************
#define GPIO_GPBGMUX1_GPIO32_S   0U
#define GPIO_GPBGMUX1_GPIO32_M   0x3U          // Defines pin-muxing selection for GPIO32
#define GPIO_GPBGMUX1_GPIO33_S   2U
#define GPIO_GPBGMUX1_GPIO33_M   0xCU          // Defines pin-muxing selection for GPIO33
#define GPIO_GPBGMUX1_GPIO34_S   4U
#define GPIO_GPBGMUX1_GPIO34_M   0x30U         // Defines pin-muxing selection for GPIO34
#define GPIO_GPBGMUX1_GPIO35_S   6U
#define GPIO_GPBGMUX1_GPIO35_M   0xC0U         // Defines pin-muxing selection for GPIO35
#define GPIO_GPBGMUX1_GPIO36_S   8U
#define GPIO_GPBGMUX1_GPIO36_M   0x300U        // Defines pin-muxing selection for GPIO36
#define GPIO_GPBGMUX1_GPIO37_S   10U
#define GPIO_GPBGMUX1_GPIO37_M   0xC00U        // Defines pin-muxing selection for GPIO37
#define GPIO_GPBGMUX1_GPIO38_S   12U
#define GPIO_GPBGMUX1_GPIO38_M   0x3000U       // Defines pin-muxing selection for GPIO38
#define GPIO_GPBGMUX1_GPIO39_S   14U
#define GPIO_GPBGMUX1_GPIO39_M   0xC000U       // Defines pin-muxing selection for GPIO39
#define GPIO_GPBGMUX1_GPIO40_S   16U
#define GPIO_GPBGMUX1_GPIO40_M   0x30000U      // Defines pin-muxing selection for GPIO40
#define GPIO_GPBGMUX1_GPIO41_S   18U
#define GPIO_GPBGMUX1_GPIO41_M   0xC0000U      // Defines pin-muxing selection for GPIO41
#define GPIO_GPBGMUX1_GPIO42_S   20U
#define GPIO_GPBGMUX1_GPIO42_M   0x300000U     // Defines pin-muxing selection for GPIO42
#define GPIO_GPBGMUX1_GPIO43_S   22U
#define GPIO_GPBGMUX1_GPIO43_M   0xC00000U     // Defines pin-muxing selection for GPIO43
#define GPIO_GPBGMUX1_GPIO44_S   24U
#define GPIO_GPBGMUX1_GPIO44_M   0x3000000U    // Defines pin-muxing selection for GPIO44
#define GPIO_GPBGMUX1_GPIO45_S   26U
#define GPIO_GPBGMUX1_GPIO45_M   0xC000000U    // Defines pin-muxing selection for GPIO45
#define GPIO_GPBGMUX1_GPIO46_S   28U
#define GPIO_GPBGMUX1_GPIO46_M   0x30000000U   // Defines pin-muxing selection for GPIO46
#define GPIO_GPBGMUX1_GPIO47_S   30U
#define GPIO_GPBGMUX1_GPIO47_M   0xC0000000U   // Defines pin-muxing selection for GPIO47

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBGMUX2 register
//
//*************************************************************************************************
#define GPIO_GPBGMUX2_GPIO48_S   0U
#define GPIO_GPBGMUX2_GPIO48_M   0x3U          // Defines pin-muxing selection for GPIO48
#define GPIO_GPBGMUX2_GPIO49_S   2U
#define GPIO_GPBGMUX2_GPIO49_M   0xCU          // Defines pin-muxing selection for GPIO49
#define GPIO_GPBGMUX2_GPIO50_S   4U
#define GPIO_GPBGMUX2_GPIO50_M   0x30U         // Defines pin-muxing selection for GPIO50
#define GPIO_GPBGMUX2_GPIO51_S   6U
#define GPIO_GPBGMUX2_GPIO51_M   0xC0U         // Defines pin-muxing selection for GPIO51
#define GPIO_GPBGMUX2_GPIO52_S   8U
#define GPIO_GPBGMUX2_GPIO52_M   0x300U        // Defines pin-muxing selection for GPIO52
#define GPIO_GPBGMUX2_GPIO53_S   10U
#define GPIO_GPBGMUX2_GPIO53_M   0xC00U        // Defines pin-muxing selection for GPIO53
#define GPIO_GPBGMUX2_GPIO54_S   12U
#define GPIO_GPBGMUX2_GPIO54_M   0x3000U       // Defines pin-muxing selection for GPIO54
#define GPIO_GPBGMUX2_GPIO55_S   14U
#define GPIO_GPBGMUX2_GPIO55_M   0xC000U       // Defines pin-muxing selection for GPIO55
#define GPIO_GPBGMUX2_GPIO56_S   16U
#define GPIO_GPBGMUX2_GPIO56_M   0x30000U      // Defines pin-muxing selection for GPIO56
#define GPIO_GPBGMUX2_GPIO57_S   18U
#define GPIO_GPBGMUX2_GPIO57_M   0xC0000U      // Defines pin-muxing selection for GPIO57
#define GPIO_GPBGMUX2_GPIO58_S   20U
#define GPIO_GPBGMUX2_GPIO58_M   0x300000U     // Defines pin-muxing selection for GPIO58
#define GPIO_GPBGMUX2_GPIO59_S   22U
#define GPIO_GPBGMUX2_GPIO59_M   0xC00000U     // Defines pin-muxing selection for GPIO59
#define GPIO_GPBGMUX2_GPIO60_S   24U
#define GPIO_GPBGMUX2_GPIO60_M   0x3000000U    // Defines pin-muxing selection for GPIO60
#define GPIO_GPBGMUX2_GPIO61_S   26U
#define GPIO_GPBGMUX2_GPIO61_M   0xC000000U    // Defines pin-muxing selection for GPIO61
#define GPIO_GPBGMUX2_GPIO62_S   28U
#define GPIO_GPBGMUX2_GPIO62_M   0x30000000U   // Defines pin-muxing selection for GPIO62
#define GPIO_GPBGMUX2_GPIO63_S   30U
#define GPIO_GPBGMUX2_GPIO63_M   0xC0000000U   // Defines pin-muxing selection for GPIO63

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBCSEL1 register
//
//*************************************************************************************************
#define GPIO_GPBCSEL1_GPIO32_S   0U
#define GPIO_GPBCSEL1_GPIO32_M   0xFU          // GPIO32 Controller CPU Select
#define GPIO_GPBCSEL1_GPIO33_S   4U
#define GPIO_GPBCSEL1_GPIO33_M   0xF0U         // GPIO33 Controller CPU Select
#define GPIO_GPBCSEL1_GPIO34_S   8U
#define GPIO_GPBCSEL1_GPIO34_M   0xF00U        // GPIO34 Controller CPU Select
#define GPIO_GPBCSEL1_GPIO35_S   12U
#define GPIO_GPBCSEL1_GPIO35_M   0xF000U       // GPIO35 Controller CPU Select
#define GPIO_GPBCSEL1_GPIO36_S   16U
#define GPIO_GPBCSEL1_GPIO36_M   0xF0000U      // GPIO36 Controller CPU Select
#define GPIO_GPBCSEL1_GPIO37_S   20U
#define GPIO_GPBCSEL1_GPIO37_M   0xF00000U     // GPIO37 Controller CPU Select
#define GPIO_GPBCSEL1_GPIO38_S   24U
#define GPIO_GPBCSEL1_GPIO38_M   0xF000000U    // GPIO38 Controller CPU Select
#define GPIO_GPBCSEL1_GPIO39_S   28U
#define GPIO_GPBCSEL1_GPIO39_M   0xF0000000U   // GPIO39 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBCSEL2 register
//
//*************************************************************************************************
#define GPIO_GPBCSEL2_GPIO40_S   0U
#define GPIO_GPBCSEL2_GPIO40_M   0xFU          // GPIO40 Controller CPU Select
#define GPIO_GPBCSEL2_GPIO41_S   4U
#define GPIO_GPBCSEL2_GPIO41_M   0xF0U         // GPIO41 Controller CPU Select
#define GPIO_GPBCSEL2_GPIO42_S   8U
#define GPIO_GPBCSEL2_GPIO42_M   0xF00U        // GPIO42 Controller CPU Select
#define GPIO_GPBCSEL2_GPIO43_S   12U
#define GPIO_GPBCSEL2_GPIO43_M   0xF000U       // GPIO43 Controller CPU Select
#define GPIO_GPBCSEL2_GPIO44_S   16U
#define GPIO_GPBCSEL2_GPIO44_M   0xF0000U      // GPIO44 Controller CPU Select
#define GPIO_GPBCSEL2_GPIO45_S   20U
#define GPIO_GPBCSEL2_GPIO45_M   0xF00000U     // GPIO45 Controller CPU Select
#define GPIO_GPBCSEL2_GPIO46_S   24U
#define GPIO_GPBCSEL2_GPIO46_M   0xF000000U    // GPIO46 Controller CPU Select
#define GPIO_GPBCSEL2_GPIO47_S   28U
#define GPIO_GPBCSEL2_GPIO47_M   0xF0000000U   // GPIO47 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBCSEL3 register
//
//*************************************************************************************************
#define GPIO_GPBCSEL3_GPIO48_S   0U
#define GPIO_GPBCSEL3_GPIO48_M   0xFU          // GPIO48 Controller CPU Select
#define GPIO_GPBCSEL3_GPIO49_S   4U
#define GPIO_GPBCSEL3_GPIO49_M   0xF0U         // GPIO49 Controller CPU Select
#define GPIO_GPBCSEL3_GPIO50_S   8U
#define GPIO_GPBCSEL3_GPIO50_M   0xF00U        // GPIO50 Controller CPU Select
#define GPIO_GPBCSEL3_GPIO51_S   12U
#define GPIO_GPBCSEL3_GPIO51_M   0xF000U       // GPIO51 Controller CPU Select
#define GPIO_GPBCSEL3_GPIO52_S   16U
#define GPIO_GPBCSEL3_GPIO52_M   0xF0000U      // GPIO52 Controller CPU Select
#define GPIO_GPBCSEL3_GPIO53_S   20U
#define GPIO_GPBCSEL3_GPIO53_M   0xF00000U     // GPIO53 Controller CPU Select
#define GPIO_GPBCSEL3_GPIO54_S   24U
#define GPIO_GPBCSEL3_GPIO54_M   0xF000000U    // GPIO54 Controller CPU Select
#define GPIO_GPBCSEL3_GPIO55_S   28U
#define GPIO_GPBCSEL3_GPIO55_M   0xF0000000U   // GPIO55 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBCSEL4 register
//
//*************************************************************************************************
#define GPIO_GPBCSEL4_GPIO56_S   0U
#define GPIO_GPBCSEL4_GPIO56_M   0xFU          // GPIO56 Controller CPU Select
#define GPIO_GPBCSEL4_GPIO57_S   4U
#define GPIO_GPBCSEL4_GPIO57_M   0xF0U         // GPIO57 Controller CPU Select
#define GPIO_GPBCSEL4_GPIO58_S   8U
#define GPIO_GPBCSEL4_GPIO58_M   0xF00U        // GPIO58 Controller CPU Select
#define GPIO_GPBCSEL4_GPIO59_S   12U
#define GPIO_GPBCSEL4_GPIO59_M   0xF000U       // GPIO59 Controller CPU Select
#define GPIO_GPBCSEL4_GPIO60_S   16U
#define GPIO_GPBCSEL4_GPIO60_M   0xF0000U      // GPIO60 Controller CPU Select
#define GPIO_GPBCSEL4_GPIO61_S   20U
#define GPIO_GPBCSEL4_GPIO61_M   0xF00000U     // GPIO61 Controller CPU Select
#define GPIO_GPBCSEL4_GPIO62_S   24U
#define GPIO_GPBCSEL4_GPIO62_M   0xF000000U    // GPIO62 Controller CPU Select
#define GPIO_GPBCSEL4_GPIO63_S   28U
#define GPIO_GPBCSEL4_GPIO63_M   0xF0000000U   // GPIO63 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBLOCK register
//
//*************************************************************************************************
#define GPIO_GPBLOCK_GPIO32   0x1U          // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO33   0x2U          // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO34   0x4U          // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO35   0x8U          // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO36   0x10U         // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO37   0x20U         // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO38   0x40U         // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO39   0x80U         // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO40   0x100U        // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO41   0x200U        // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO42   0x400U        // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO43   0x800U        // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO44   0x1000U       // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO45   0x2000U       // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO46   0x4000U       // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO47   0x8000U       // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO48   0x10000U      // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO49   0x20000U      // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO50   0x40000U      // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO51   0x80000U      // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO52   0x100000U     // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO53   0x200000U     // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO54   0x400000U     // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO55   0x800000U     // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO56   0x1000000U    // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO57   0x2000000U    // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO58   0x4000000U    // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO59   0x8000000U    // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO60   0x10000000U   // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO61   0x20000000U   // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO62   0x40000000U   // Configuration Lock bit for this pin
#define GPIO_GPBLOCK_GPIO63   0x80000000U   // Configuration Lock bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBCR register
//
//*************************************************************************************************
#define GPIO_GPBCR_GPIO32   0x1U          // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO33   0x2U          // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO34   0x4U          // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO35   0x8U          // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO36   0x10U         // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO37   0x20U         // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO38   0x40U         // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO39   0x80U         // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO40   0x100U        // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO41   0x200U        // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO42   0x400U        // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO43   0x800U        // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO44   0x1000U       // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO45   0x2000U       // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO46   0x4000U       // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO47   0x8000U       // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO48   0x10000U      // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO49   0x20000U      // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO50   0x40000U      // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO51   0x80000U      // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO52   0x100000U     // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO53   0x200000U     // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO54   0x400000U     // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO55   0x8DMA_Type00000U     // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO56   0x1000000U    // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO57   0x2000000U    // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO58   0x4000000U    // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO59   0x8000000U    // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO60   0x10000000U   // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO61   0x20000000U   // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO62   0x40000000U   // Configuration lock commit bit for this pin
#define GPIO_GPBCR_GPIO63   0x80000000U   // Configuration lock commit bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCCTRL register
//
//*************************************************************************************************
#define GPIO_GPCCTRL_QUALPRD0_S   0U
#define GPIO_GPCCTRL_QUALPRD0_M   0xFFU         // Qualification sampling period for GPIO64 to
                                                // GPIO71
#define GPIO_GPCCTRL_QUALPRD1_S   8U
#define GPIO_GPCCTRL_QUALPRD1_M   0xFF00U       // Qualification sampling period for GPIO72 to
                                                // GPIO79
#define GPIO_GPCCTRL_QUALPRD2_S   16U
#define GPIO_GPCCTRL_QUALPRD2_M   0xFF0000U     // Qualification sampling period for GPIO80 to
                                                // GPIO87
#define GPIO_GPCCTRL_QUALPRD3_S   24U
#define GPIO_GPCCTRL_QUALPRD3_M   0xFF000000U   // Qualification sampling period for GPIO88 to
                                                // GPIO95

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCQSEL1 register
//
//*************************************************************************************************
#define GPIO_GPCQSEL1_GPIO64_S   0U
#define GPIO_GPCQSEL1_GPIO64_M   0x3U          // Select input qualification type for GPIO64
#define GPIO_GPCQSEL1_GPIO65_S   2U
#define GPIO_GPCQSEL1_GPIO65_M   0xCU          // Select input qualification type for GPIO65
#define GPIO_GPCQSEL1_GPIO66_S   4U
#define GPIO_GPCQSEL1_GPIO66_M   0x30U         // Select input qualification type for GPIO66
#define GPIO_GPCQSEL1_GPIO67_S   6U
#define GPIO_GPCQSEL1_GPIO67_M   0xC0U         // Select input qualification type for GPIO67
#define GPIO_GPCQSEL1_GPIO68_S   8U
#define GPIO_GPCQSEL1_GPIO68_M   0x300U        // Select input qualification type for GPIO68
#define GPIO_GPCQSEL1_GPIO69_S   10U
#define GPIO_GPCQSEL1_GPIO69_M   0xC00U        // Select input qualification type for GPIO69
#define GPIO_GPCQSEL1_GPIO70_S   12U
#define GPIO_GPCQSEL1_GPIO70_M   0x3000U       // Select input qualification type for GPIO70
#define GPIO_GPCQSEL1_GPIO71_S   14U
#define GPIO_GPCQSEL1_GPIO71_M   0xC000U       // Select input qualification type for GPIO71
#define GPIO_GPCQSEL1_GPIO72_S   16U
#define GPIO_GPCQSEL1_GPIO72_M   0x30000U      // Select input qualification type for GPIO72
#define GPIO_GPCQSEL1_GPIO73_S   18U
#define GPIO_GPCQSEL1_GPIO73_M   0xC0000U      // Select input qualification type for GPIO73
#define GPIO_GPCQSEL1_GPIO74_S   20U
#define GPIO_GPCQSEL1_GPIO74_M   0x300000U     // Select input qualification type for GPIO74
#define GPIO_GPCQSEL1_GPIO75_S   22U
#define GPIO_GPCQSEL1_GPIO75_M   0xC00000U     // Select input qualification type for GPIO75
#define GPIO_GPCQSEL1_GPIO76_S   24U
#define GPIO_GPCQSEL1_GPIO76_M   0x3000000U    // Select input qualification type for GPIO76
#define GPIO_GPCQSEL1_GPIO77_S   26U
#define GPIO_GPCQSEL1_GPIO77_M   0xC000000U    // Select input qualification type for GPIO77
#define GPIO_GPCQSEL1_GPIO78_S   28U
#define GPIO_GPCQSEL1_GPIO78_M   0x30000000U   // Select input qualification type for GPIO78
#define GPIO_GPCQSEL1_GPIO79_S   30U
#define GPIO_GPCQSEL1_GPIO79_M   0xC0000000U   // Select input qualification type for GPIO79

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCQSEL2 register
//
//*************************************************************************************************
#define GPIO_GPCQSEL2_GPIO80_S   0U
#define GPIO_GPCQSEL2_GPIO80_M   0x3U          // Select input qualification type for GPIO80
#define GPIO_GPCQSEL2_GPIO81_S   2U
#define GPIO_GPCQSEL2_GPIO81_M   0xCU          // Select input qualification type for GPIO81
#define GPIO_GPCQSEL2_GPIO82_S   4U
#define GPIO_GPCQSEL2_GPIO82_M   0x30U         // Select input qualification type for GPIO82
#define GPIO_GPCQSEL2_GPIO83_S   6U
#define GPIO_GPCQSEL2_GPIO83_M   0xC0U         // Select input qualification type for GPIO83
#define GPIO_GPCQSEL2_GPIO84_S   8U
#define GPIO_GPCQSEL2_GPIO84_M   0x300U        // Select input qualification type for GPIO84
#define GPIO_GPCQSEL2_GPIO85_S   10U
#define GPIO_GPCQSEL2_GPIO85_M   0xC00U        // Select input qualification type for GPIO85
#define GPIO_GPCQSEL2_GPIO86_S   12U
#define GPIO_GPCQSEL2_GPIO86_M   0x3000U       // Select input qualification type for GPIO86
#define GPIO_GPCQSEL2_GPIO87_S   14U
#define GPIO_GPCQSEL2_GPIO87_M   0xC000U       // Select input qualification type for GPIO87
#define GPIO_GPCQSEL2_GPIO88_S   16U
#define GPIO_GPCQSEL2_GPIO88_M   0x30000U      // Select input qualification type for GPIO88
#define GPIO_GPCQSEL2_GPIO89_S   18U
#define GPIO_GPCQSEL2_GPIO89_M   0xC0000U      // Select input qualification type for GPIO89
#define GPIO_GPCQSEL2_GPIO90_S   20U
#define GPIO_GPCQSEL2_GPIO90_M   0x300000U     // Select input qualification type for GPIO90
#define GPIO_GPCQSEL2_GPIO91_S   22U
#define GPIO_GPCQSEL2_GPIO91_M   0xC00000U     // Select input qualification type for GPIO91
#define GPIO_GPCQSEL2_GPIO92_S   24U
#define GPIO_GPCQSEL2_GPIO92_M   0x3000000U    // Select input qualification type for GPIO92
#define GPIO_GPCQSEL2_GPIO93_S   26U
#define GPIO_GPCQSEL2_GPIO93_M   0xC000000U    // Select input qualification type for GPIO93
#define GPIO_GPCQSEL2_GPIO94_S   28U
#define GPIO_GPCQSEL2_GPIO94_M   0x30000000U   // Select input qualification type for GPIO94
#define GPIO_GPCQSEL2_GPIO95_S   30U
#define GPIO_GPCQSEL2_GPIO95_M   0xC0000000U   // Select input qualification type for GPIO95

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCMUX1 register
//
//*************************************************************************************************
#define GPIO_GPCMUX1_GPIO64_S   0U
#define GPIO_GPCMUX1_GPIO64_M   0x3U          // Defines pin-muxing selection for GPIO64
#define GPIO_GPCMUX1_GPIO65_S   2U
#define GPIO_GPCMUX1_GPIO65_M   0xCU          // Defines pin-muxing selection for GPIO65
#define GPIO_GPCMUX1_GPIO66_S   4U
#define GPIO_GPCMUX1_GPIO66_M   0x30U         // Defines pin-muxing selection for GPIO66
#define GPIO_GPCMUX1_GPIO67_S   6U
#define GPIO_GPCMUX1_GPIO67_M   0xC0U         // Defines pin-muxing selection for GPIO67
#define GPIO_GPCMUX1_GPIO68_S   8U
#define GPIO_GPCMUX1_GPIO68_M   0x300U        // Defines pin-muxing selection for GPIO68
#define GPIO_GPCMUX1_GPIO69_S   10U
#define GPIO_GPCMUX1_GPIO69_M   0xC00U        // Defines pin-muxing selection for GPIO69
#define GPIO_GPCMUX1_GPIO70_S   12U
#define GPIO_GPCMUX1_GPIO70_M   0x3000U       // Defines pin-muxing selection for GPIO70
#define GPIO_GPCMUX1_GPIO71_S   14U
#define GPIO_GPCMUX1_GPIO71_M   0xC000U       // Defines pin-muxing selection for GPIO71
#define GPIO_GPCMUX1_GPIO72_S   16U
#define GPIO_GPCMUX1_GPIO72_M   0x30000U      // Defines pin-muxing selection for GPIO72
#define GPIO_GPCMUX1_GPIO73_S   18U
#define GPIO_GPCMUX1_GPIO73_M   0xC0000U      // Defines pin-muxing selection for GPIO73
#define GPIO_GPCMUX1_GPIO74_S   20U
#define GPIO_GPCMUX1_GPIO74_M   0x300000U     // Defines pin-muxing selection for GPIO74
#define GPIO_GPCMUX1_GPIO75_S   22U
#define GPIO_GPCMUX1_GPIO75_M   0xC00000U     // Defines pin-muxing selection for GPIO75
#define GPIO_GPCMUX1_GPIO76_S   24U
#define GPIO_GPCMUX1_GPIO76_M   0x3000000U    // Defines pin-muxing selection for GPIO76
#define GPIO_GPCMUX1_GPIO77_S   26U
#define GPIO_GPCMUX1_GPIO77_M   0xC000000U    // Defines pin-muxing selection for GPIO77
#define GPIO_GPCMUX1_GPIO78_S   28U
#define GPIO_GPCMUX1_GPIO78_M   0x30000000U   // Defines pin-muxing selection for GPIO78
#define GPIO_GPCMUX1_GPIO79_S   30U
#define GPIO_GPCMUX1_GPIO79_M   0xC0000000U   // Defines pin-muxing selection for GPIO79

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCMUX2 register
//
//*************************************************************************************************
#define GPIO_GPCMUX2_GPIO80_S   0U
#define GPIO_GPCMUX2_GPIO80_M   0x3U          // Defines pin-muxing selection for GPIO80
#define GPIO_GPCMUX2_GPIO81_S   2U
#define GPIO_GPCMUX2_GPIO81_M   0xCU          // Defines pin-muxing selection for GPIO81
#define GPIO_GPCMUX2_GPIO82_S   4U
#define GPIO_GPCMUX2_GPIO82_M   0x30U         // Defines pin-muxing selection for GPIO82
#define GPIO_GPCMUX2_GPIO83_S   6U
#define GPIO_GPCMUX2_GPIO83_M   0xC0U         // Defines pin-muxing selection for GPIO83
#define GPIO_GPCMUX2_GPIO84_S  DMA_Type 8U
#define GPIO_GPCMUX2_GPIO84_M   0x300U        // Defines pin-muxing selection for GPIO84
#define GPIO_GPCMUX2_GPIO85_S   10U
#define GPIO_GPCMUX2_GPIO85_M   0xC00U        // Defines pin-muxing selection for GPIO85
#define GPIO_GPCMUX2_GPIO86_S   12U
#define GPIO_GPCMUX2_GPIO86_M   0x3000U       // Defines pin-muxing selection for GPIO86
#define GPIO_GPCMUX2_GPIO87_S   14U
#define GPIO_GPCMUX2_GPIO87_M   0xC000U       // Defines pin-muxing selection for GPIO87
#define GPIO_GPCMUX2_GPIO88_S   16U
#define GPIO_GPCMUX2_GPIO88_M   0x30000U      // Defines pin-muxing selection for GPIO88
#define GPIO_GPCMUX2_GPIO89_S   18U
#define GPIO_GPCMUX2_GPIO89_M   0xC0000U      // Defines pin-muxing selection for GPIO89
#define GPIO_GPCMUX2_GPIO90_S   20U
#define GPIO_GPCMUX2_GPIO90_M   0x300000U     // Defines pin-muxing selection for GPIO90
#define GPIO_GPCMUX2_GPIO91_S   22U
#define GPIO_GPCMUX2_GPIO91_M   0xC00000U     // Defines pin-muxing selection for GPIO91
#define GPIO_GPCMUX2_GPIO92_S   24U
#define GPIO_GPCMUX2_GPIO92_M   0x3000000U    // Defines pin-muxing selection for GPIO92
#define GPIO_GPCMUX2_GPIO93_S   26U
#define GPIO_GPCMUX2_GPIO93_M   0xC000000U    // Defines pin-muxing selection for GPIO93
#define GPIO_GPCMUX2_GPIO94_S   28U
#define GPIO_GPCMUX2_GPIO94_M   0x30000000U   // Defines pin-muxing selection for GPIO94
#define GPIO_GPCMUX2_GPIO95_S   30U
#define GPIO_GPCMUX2_GPIO95_M   0xC0000000U   // Defines pin-muxing selection for GPIO95

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCDIR register
//
//*************************************************************************************************
#define GPIO_GPCDIR_GPIO64   0x1U          // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO65   0x2U          // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO66   0x4U          // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO67   0x8U          // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO68   0x10U         // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO69   0x20U         // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO70   0x40U         // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO71   0x80U         // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO72   0x100U        // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO73   0x200U        // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO74   0x400U        // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO75   0x800U        // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO76   0x1000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO77   0x2000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO78   0x4000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO79   0x8000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO80   0x10000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO81   0x20000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO82   0x40000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO83   0x80000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO84   0x100000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO85   0x200000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO86   0x400000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO87   0x800000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO88   0x1000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO89   0x2000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO90   0x4000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO91   0x8000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO92   0x10000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO93   0x20000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO94   0x40000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPCDIR_GPIO95   0x80000000U   // Defines direction for this pin in GPIO mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCPUD register
//
//*************************************************************************************************
#define GPIO_GPCPUD_GPIO64   0x1U          // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO65   0x2U          // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO66   0x4U          // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO67   0x8U          // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO68   0x10U         // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO69   0x20U         // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO70   0x40U         // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO71   0x80U         // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO72   0x100U        // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO73   0x200U        // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO74   0x400U        // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO75   0x800U        // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO76   0x1000U       // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO77   0x2000U       // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO78   0x4000U       // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO79   0x8000U       // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO80   0x10000U      // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO81   0x20000U      // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO82   0x40000U      // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO83   0x80000U      // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO84   0x100000U     // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO85   0x200000U     // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO86   0x400000U     // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO87   0x800000U     // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO88   0x1000000U    // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO89   0x2000000U    // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO90   0x4000000U    // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO91   0x8000000U    // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO92   0x10000000U   // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO93   0x20000000U   // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO94   0x40000000U   // Pull-Up Disable control for this pin
#define GPIO_GPCPUD_GPIO95   0x80000000U   // Pull-Up Disable control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCINV register
//
//*************************************************************************************************
#define GPIO_GPCINV_GPIO64   0x1U          // Input inversion control for this pin
#define GPIO_GPCINV_GPIO65   0x2U          // Input inversion control for this pin
#define GPIO_GPCINV_GPIO66   0x4U          // Input inversion control for this pin
#define GPIO_GPCINV_GPIO67   0x8U          // Input inversion control for this pin
#define GPIO_GPCINV_GPIO68   0x10U         // Input inversion control for this pin
#define GPIO_GPCINV_GPIO69   0x20U         // Input inversion control for this pin
#define GPIO_GPCINV_GPIO70   0x40U         // Input inversion control for this pin
#define GPIO_GPCINV_GPIO71   0x80U         // Input inversion control for this pin
#define GPIO_GPCINV_GPIO72   0x100U        // Input inversion control for this pin
#define GPIO_GPCINV_GPIO73   0x200U        // Input inversion control for this pin
#define GPIO_GPCINV_GPIO74   0x400U        // Input inversion control for this pin
#define GPIO_GPCINV_GPIO75   0x800U        // Input inversion control for this pin
#define GPIO_GPCINV_GPIO76   0x1000U       // Input inversion control for this pin
#define GPIO_GPCINV_GPIO77   0x2000U       // Input inversion control for this pin
#define GPIO_GPCINV_GPIO78   0x4000U       // Input inversion control for this pin
#define GPIO_GPCINV_GPIO79   0x8000U       // Input inversion control for this pin
#define GPIO_GPCINV_GPIO80   0x10000U      // Input inversion control for this pin
#define GPIO_GPCINV_GPIO81   0x20000U      // Input inversion control for this pin
#define GPIO_GPCINV_GPIO82   0x40000U      // Input inversion control for this pin
#define GPIO_GPCINV_GPIO83   0x80000U      // Input inversion control for this pin
#define GPIO_GPCINV_GPIO84   0x100000U     // Input inversion control for this pin
#define GPIO_GPCINV_GPIO85   0x200000U     // Input inversion control for this pin
#define GPIO_GPCINV_GPIO86   0x400000U     // Input inversion control for this pin
#define GPIO_GPCINV_GPIO87   0x800000U     // Input inversion control for this pin
#define GPIO_GPCINV_GPIO88   0x1000000U    // Input inversion control for this pin
#define GPIO_GPCINV_GPIO89   0x2000000U    // Input inversion control for this pin
#define GPIO_GPCINV_GPIO90   0x4000000U    // Input inversion control for this pin
#define GPIO_GPCINV_GPIO91   0x8000000U    // Input inversion control for this pin
#define GPIO_GPCINV_GPIO92   0x10000000U   // Input inversion control for this pin
#define GPIO_GPCINV_GPIO93   0x20000000U   // Input inversion control for this pin
#define GPIO_GPCINV_GPIO94   0x40000000U   // Input inversion control for this pin
#define GPIO_GPCINV_GPIO95   0x80000000U   // Input inversion control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCODR register
//
//*************************************************************************************************
#define GPIO_GPCODR_GPIO64   0x1U          // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO65   0x2U          // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO66   0x4U          // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO67   0x8U          // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO68   0x10U         // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO69   0x20U         // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO70   0x40U         // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO71   0x80U         // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO72   0x100U        // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO73   0x200U        // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO74   0x400U        // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO75   0x800U        // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO76   0x1000U       // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO77   0x2000U       // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO78   0x4000U       // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO79   0x8000U       // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO80   0x10000U      // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO81   0x20000U      // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO82   0x40000U      // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO83   0x80000U      // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO84   0x100000U     // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO85   0x200000U     // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO86   0x400000U     // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO87   0x800000U     // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO88   0x1000000U    // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO89   0x2000000U    // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO90   0x4000000U    // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO91   0x8000000U    // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO92   0x10000000U   // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO93   0x20000000U   // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO94   0x40000000U   // Output Open-Drain control for this pin
#define GPIO_GPCODR_GPIO95   0x80000000U   // Output Open-Drain control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCGMUX1 register
//
//*************************************************************************************************
#define GPIO_GPCGMUX1_GPIO64_S   0U
#define GPIO_GPCGMUX1_GPIO64_M   0x3U          // Defines pin-muxing selection for GPIO64
#define GPIO_GPCGMUX1_GPIO65_S   2U
#define GPIO_GPCGMUX1_GPIO65_M   0xCU          // Defines pin-muxing selection for GPIO65
#define GPIO_GPCGMUX1_GPIO66_S   4U
#define GPIO_GPCGMUX1_GPIO66_M   0x30U         // Defines pin-muxing selection for GPIO66
#define GPIO_GPCGMUX1_GPIO67_S   6U
#define GPIO_GPCGMUX1_GPIO67_M   0xC0U         // Defines pin-muxing selection for GPIO67
#define GPIO_GPCGMUX1_GPIO68_S   8U
#define GPIO_GPCGMUX1_GPIO68_M   0x300U        // Defines pin-muxing selection for GPIO68
#define GPIO_GPCGMUX1_GPIO69_S   10U
#define GPIO_GPCGMUX1_GPIO69_M   0xC00U        // Defines pin-muxing selection for GPIO69
#define GPIO_GPCGMUX1_GPIO70_S   12U
#define GPIO_GPCGMUX1_GPIO70_M   0x3000U       // Defines pin-muxing selection for GPIO70
#define GPIO_GPCGMUX1_GPIO71_S   14U
#define GPIO_GPCGMUX1_GPIO71_M   0xC000U       // Defines pin-muxing selection for GPIO71
#define GPIO_GPCGMUX1_GPIO72_S   16U
#define GPIO_GPCGMUX1_GPIO72_M   0x30000U      // Defines pin-muxing selection for GPIO72
#define GPIO_GPCGMUX1_GPIO73_S   18U
#define GPIO_GPCGMUX1_GPIO73_M   0xC0000U      // Defines pin-muxing selection for GPIO73
#define GPIO_GPCGMUX1_GPIO74_S   20U
#define GPIO_GPCGMUX1_GPIO74_M   0x300000U     // Defines pin-muxing selection for GPIO74
#define GPIO_GPCGMUX1_GPIO75_S   22U
#define GPIO_GPCGMUX1_GPIO75_M   0xC00000U     // Defines pin-muxing selection for GPIO75
#define GPIO_GPCGMUX1_GPIO76_S   24U
#define GPIO_GPCGMUX1_GPIO76_M   0x3000000U    // Defines pin-muxing selection for GPIO76
#define GPIO_GPCGMUX1_GPIO77_S   26U
#define GPIO_GPCGMUX1_GPIO77_M   0xC000000U    // Defines pin-muxing selection for GPIO77
#define GPIO_GPCGMUX1_GPIO78_S   28U
#define GPIO_GPCGMUX1_GPIO78_M   0x30000000U   // Defines pin-muxing selection for GPIO78
#define GPIO_GPCGMUX1_GPIO79_S   30U
#define GPIO_GPCGMUX1_GPIO79_M   0xC0000000U   // Defines pin-muxing selection for GPIO79

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCGMUX2 register
//
//*************************************************************************************************
#define GPIO_GPCGMUX2_GPIO80_S   0U
#define GPIO_GPCGMUX2_GPIO80_M   0x3U          // Defines pin-muxing selection for GPIO80
#define GPIO_GPCGMUX2_GPIO81_S   2U
#define GPIO_GPCGMUX2_GPIO81_M   0xCU          // Defines pin-muxing selection for GPIO81
#define GPIO_GPCGMUX2_GPIO82_S   4U
#define GPIO_GPCGMUX2_GPIO82_M   0x30U         // Defines pin-muxing selection for GPIO82
#define GPIO_GPCGMUX2_GPIO83_S   6U
#define GPIO_GPCGMUX2_GPIO83_M   0xC0U         // Defines pin-muxing selection for GPIO83
#define GPIO_GPCGMUX2_GPIO84_S   8U
#define GPIO_GPCGMUX2_GPIO84_M   0x300U        // Defines pin-muxing selection for GPIO84
#define GPIO_GPCGMUX2_GPIO85_S   10U
#define GPIO_GPCGMUX2_GPIO85_M   0xC00U        // Defines pin-muxing selection for GPIO85
#define GPIO_GPCGMUX2_GPIO86_S   12U
#define GPIO_GPCGMUX2_GPIO86_M   0x3000U       // Defines pin-muxing selection for GPIO86
#define GPIO_GPCGMUX2_GPIO87_S   14U
#define GPIO_GPCGMUX2_GPIO87_M   0xC000U       // Defines pin-muxing selection for GPIO87
#define GPIO_GPCGMUX2_GPIO88_S   16U
#define GPIO_GPCGMUX2_GPIO88_M   0x30000U      // Defines pin-muxing selection for GPIO88
#define GPIO_GPCGMUX2_GPIO89_S   18U
#define GPIO_GPCGMUX2_GPIO89_M   0xC0000U      // Defines pin-muxing selection for GPIO89
#define GPIO_GPCGMUX2_GPIO90_S   20U
#define GPIO_GPCGMUX2_GPIO90_M   0x300000U     // Defines pin-muxing selection for GPIO90
#define GPIO_GPCGMUX2_GPIO91_S   22U
#define GPIO_GPCGMUX2_GPIO91_M   0xC00000U     // Defines pin-muxing selection for GPIO91
#define GPIO_GPCGMUX2_GPIO92_S   24U
#define GPIO_GPCGMUX2_GPIO92_M   0x3000000U    // Defines pin-muxing selection for GPIO92
#define GPIO_GPCGMUX2_GPIO93_S   26U
#define GPIO_GPCGMUX2_GPIO93_M   0xC000000U    // Defines pin-muxing selection for GPIO93
#define GPIO_GPCGMUX2_GPIO94_S   28U
#define GPIO_GPCGMUX2_GPIO94_M   0x30000000U   // Defines pin-muxing selection for GPIO94
#define GPIO_GPCGMUX2_GPIO95_S   30U
#define GPIO_GPCGMUX2_GPIO95_M   0xC0000000U   // Defines pin-muxing selection for GPIO95

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCCSEL1 register
//
//*************************************************************************************************
#define GPIO_GPCCSEL1_GPIO64_S   0U
#define GPIO_GPCCSEL1_GPIO64_M   0xFU          // GPIO64 Controller CPU Select
#define GPIO_GPCCSEL1_GPIO65_S   4U
#define GPIO_GPCCSEL1_GPIO65_M   0xF0U         // GPIO65 Controller CPU Select
#define GPIO_GPCCSEL1_GPIO66_S   8U
#define GPIO_GPCCSEL1_GPIO66_M   0xF00U        // GPIO66 Controller CPU Select
#define GPIO_GPCCSEL1_GPIO67_S   12U
#define GPIO_GPCCSEL1_GPIO67_M   0xF000U       // GPIO67 Controller CPU Select
#define GPIO_GPCCSEL1_GPIO68_S   16U
#define GPIO_GPCCSEL1_GPIO68_M   0xF0000U      // GPIO68 Controller CPU Select
#define GPIO_GPCCSEL1_GPIO69_S   20U
#define GPIO_GPCCSEL1_GPIO69_M   0xF00000U     // GPIO69 Controller CPU Select
#define GPIO_GPCCSEL1_GPIO70_S   24U
#define GPIO_GPCCSEL1_GPIO70_M   0xF000000U    // GPIO70 Controller CPU Select
#define GPIO_GPCCSEL1_GPIO71_S   28U
#define GPIO_GPCCSEL1_GPIO71_M   0xF0000000U   // GPIO71 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCCSEL2 register
//
//*************************************************************************************************
#define GPIO_GPCCSEL2_GPIO72_S   0U
#define GPIO_GPCCSEL2_GPIO72_M   0xFU          // GPIO72 Controller CPU Select
#define GPIO_GPCCSEL2_GPIO73_S   4U
#define GPIO_GPCCSEL2_GPIO73_M   0xF0U         // GPIO73 Controller CPU Select
#define GPIO_GPCCSEL2_GPIO74_S   8U
#define GPIO_GPCCSEL2_GPIO74_M   0xF00U        // GPIO74 Controller CPU Select
#define GPIO_GPCCSEL2_GPIO75_S   12U
#define GPIO_GPCCSEL2_GPIO75_M   0xF000U       // GPIO75 Controller CPU Select
#define GPIO_GPCCSEL2_GPIO76_S   16U
#define GPIO_GPCCSEL2_GPIO76_M   0xF0000U      // GPIO76 Controller CPU Select
#define GPIO_GPCCSEL2_GPIO77_S   20U
#define GPIO_GPCCSEL2_GPIO77_M   0xF00000U     // GPIO77 Controller CPU Select
#define GPIO_GPCCSEL2_GPIO78_S   24U
#define GPIO_GPCCSEL2_GPIO78_M   0xF000000U    // GPIO78 Controller CPU Select
#define GPIO_GPCCSEL2_GPIO79_S   28U
#define GPIO_GPCCSEL2_GPIO79_M   0xF0000000U   // GPIO79 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCCSEL3 register
//
//*************************************************************************************************
#define GPIO_GPCCSEL3_GPIO80_S   0U
#define GPIO_GPCCSEL3_GPIO80_M   0xFU          // GPIO80 Controller CPU Select
#define GPIO_GPCCSEL3_GPIO81_S   4U
#define GPIO_GPCCSEL3_GPIO81_M   0xF0U         // GPIO81 Controller CPU Select
#define GPIO_GPCCSEL3_GPIO82_S   8U
#define GPIO_GPCCSEL3_GPIO82_M   0xF00U        // GPIO82 Controller CPU Select
#define GPIO_GPCCSEL3_GPIO83_S   12U
#define GPIO_GPCCSEL3_GPIO83_M   0xF000U       // GPIO83 Controller CPU Select
#define GPIO_GPCCSEL3_GPIO84_S   16U
#define GPIO_GPCCSEL3_GPIO84_M   0xF0000U      // GPIO84 Controller CPU Select
#define GPIO_GPCCSEL3_GPIO85_S   20U
#define GPIO_GPCCSEL3_GPIO85_M   0xF00000U     // GPIO85 Controller CPU Select
#define GPIO_GPCCSEL3_GPIO86_S   24U
#define GPIO_GPCCSEL3_GPIO86_M   0xF000000U    // GPIO86 Controller CPU Select
#define GPIO_GPCCSEL3_GPIO87_S   28U
#define GPIO_GPCCSEL3_GPIO87_M   0xF0000000U   // GPIO87 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCCSEL4 register
//
//*************************************************************************************************
#define GPIO_GPCCSEL4_GPIO88_S   0U
#define GPIO_GPCCSEL4_GPIO88_M   0xFU          // GPIO88 Controller CPU Select
#define GPIO_GPCCSEL4_GPIO89_S   4U
#define GPIO_GPCCSEL4_GPIO89_M   0xF0U         // GPIO89 Controller CPU Select
#define GPIO_GPCCSEL4_GPIO90_S   8U
#define GPIO_GPCCSEL4_GPIO90_M   0xF00U        // GPIO90 Controller CPU Select
#define GPIO_GPCCSEL4_GPIO91_S   12U
#define GPIO_GPCCSEL4_GPIO91_M   0xF000U       // GPIO91 Controller CPU Select
#define GPIO_GPCCSEL4_GPIO92_S   16U
#define GPIO_GPCCSEL4_GPIO92_M   0xF0000U      // GPIO92 Controller CPU Select
#define GPIO_GPCCSEL4_GPIO93_S   20U
#define GPIO_GPCCSEL4_GPIO93_M   0xF00000U     // GPIO93 Controller CPU Select
#define GPIO_GPCCSEL4_GPIO94_S   24U
#define GPIO_GPCCSEL4_GPIO94_M   0xF000000U    // GPIO94 Controller CPU Select
#define GPIO_GPCCSEL4_GPIO95_S   28U
#define GPIO_GPCCSEL4_GPIO95_M   0xF0000000U   // GPIO95 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCLOCK register
//
//*************************************************************************************************
#define GPIO_GPCLOCK_GPIO64   0x1U          // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO65   0x2U          // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO66   0x4U          // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO67   0x8U          // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO68   0x10U         // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO69   0x20U         // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO70   0x40U         // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO71   0x80U         // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO72   0x100U        // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO73   0x200U        // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO74   0x400U        // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO75   0x800U        // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO76   0x1000U       // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO77   0x2000U       // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO78   0x4000U       // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO79   0x8000U       // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO80   0x10000U      // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO81   0x20000U      // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO82   0x40000U      // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO83   0x80000U      // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO84   0x100000U     // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO85   0x200000U     // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO86   0x400000U     // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO87   0x800000U     // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO88   0x1000000U    // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO89   0x2000000U    // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO90   0x4000000U    // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO91   0x8000000U    // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO92   0x10000000U   // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO93   0x20000000U   // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO94   0x40000000U   // Configuration Lock bit for this pin
#define GPIO_GPCLOCK_GPIO95   0x80000000U   // Configuration Lock bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCCR register
//
//*************************************************************************************************
#define GPIO_GPCCR_GPIO64   0x1U          // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO65   0x2U          // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO66   0x4U          // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO67   0x8U          // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO68   0x10U         // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO69   0x20U         // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO70   0x40U         // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO71   0x80U         // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO72   0x100U        // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO73   0x200U        // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO74   0x400U        // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO75   0x800U        // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO76   0x1000U       // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO77   0x2000U       // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO78   0x4000U       // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO79   0x8000U       // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO80   0x10000U      // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO81   0x20000U      // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO82   0x40000U      // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO83   0x80000U      // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO84   0x100000U     // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO85   0x200000U     // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO86   0x400000U     // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO87   0x800000U     // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO88   0x1000000U    // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO89   0x2000000U    // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO90   0x4000000U    // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO91   0x8000000U    // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO92   0x10000000U   // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO93   0x20000000U   // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO94   0x40000000U   // Configuration lock commit bit for this pin
#define GPIO_GPCCR_GPIO95   0x80000000U   // Configuration lock commit bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDCTRL register
//
//*************************************************************************************************
#define GPIO_GPDCTRL_QUALPRD0_S   0U
#define GPIO_GPDCTRL_QUALPRD0_M   0xFFU         // Qualification sampling period for GPIO96 to
                                                // GPIO103
#define GPIO_GPDCTRL_QUALPRD1_S   8U
#define GPIO_GPDCTRL_QUALPRD1_M   0xFF00U       // Qualification sampling period for GPIO104 to
                                                // GPIO111
#define GPIO_GPDCTRL_QUALPRD2_S   16U
#define GPIO_GPDCTRL_QUALPRD2_M   0xFF0000U     // Qualification sampling period for GPIO112 to
                                                // GPIO119
#define GPIO_GPDCTRL_QUALPRD3_S   24U
#define GPIO_GPDCTRL_QUALPRD3_M   0xFF000000U   // Qualification sampling period for GPIO120 to
                                                // GPIO127

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDQSEL1 register
//
//*************************************************************************************************
#define GPIO_GPDQSEL1_GPIO96_S    0U
#define GPIO_GPDQSEL1_GPIO96_M    0x3U          // Select input qualification type for GPIO96
#define GPIO_GPDQSEL1_GPIO97_S    2U
#define GPIO_GPDQSEL1_GPIO97_M    0xCU          // Select input qualification type for GPIO97
#define GPIO_GPDQSEL1_GPIO98_S    4U
#define GPIO_GPDQSEL1_GPIO98_M    0x30U         // Select input qualification type for GPIO98
#define GPIO_GPDQSEL1_GPIO99_S    6U
#define GPIO_GPDQSEL1_GPIO99_M    0xC0U         // Select input qualification type for GPIO99
#define GPIO_GPDQSEL1_GPIO100_S   8U
#define GPIO_GPDQSEL1_GPIO100_M   0x300U        // Select input qualification type for GPIO100
#define GPIO_GPDQSEL1_GPIO101_S   10U
#define GPIO_GPDQSEL1_GPIO101_M   0xC00U        // Select input qualification type for GPIO101
#define GPIO_GPDQSEL1_GPIO102_S   12U
#define GPIO_GPDQSEL1_GPIO102_M   0x3000U       // Select input qualification type for GPIO102
#define GPIO_GPDQSEL1_GPIO103_S   14U
#define GPIO_GPDQSEL1_GPIO103_M   0xC000U       // Select input qualification type for GPIO103
#define GPIO_GPDQSEL1_GPIO104_S   16U
#define GPIO_GPDQSEL1_GPIO104_M   0x30000U      // Select input qualification type for GPIO104
#define GPIO_GPDQSEL1_GPIO105_S   18U
#define GPIO_GPDQSEL1_GPIO105_M   0xC0000U      // Select input qualification type for GPIO105
#define GPIO_GPDQSEL1_GPIO106_S   20U
#define GPIO_GPDQSEL1_GPIO106_M   0x300000U     // Select input qualification type for GPIO106
#define GPIO_GPDQSEL1_GPIO107_S   22U
#define GPIO_GPDQSEL1_GPIO107_M   0xC00000U     // Select input qualification type for GPIO107
#define GPIO_GPDQSEL1_GPIO108_S   24U
#define GPIO_GPDQSEL1_GPIO108_M   0x3000000U    // Select input qualification type for GPIO108
#define GPIO_GPDQSEL1_GPIO109_S   26U
#define GPIO_GPDQSEL1_GPIO109_M   0xC000000U    // Select input qualification type for GPIO109
#define GPIO_GPDQSEL1_GPIO110_S   28U
#define GPIO_GPDQSEL1_GPIO110_M   0x30000000U   // Select input qualification type for GPIO110
#define GPIO_GPDQSEL1_GPIO111_S   30U
#define GPIO_GPDQSEL1_GPIO111_M   0xC0000000U   // Select input qualification type for GPIO111

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDQSEL2 register
//
//*************************************************************************************************
#define GPIO_GPDQSEL2_GPIO112_S   0U
#define GPIO_GPDQSEL2_GPIO112_M   0x3U          // Select input qualification type for GPIO112
#define GPIO_GPDQSEL2_GPIO113_S   2U
#define GPIO_GPDQSEL2_GPIO113_M   0xCU          // Select input qualification type for GPIO113
#define GPIO_GPDQSEL2_GPIO114_S   4U
#define GPIO_GPDQSEL2_GPIO114_M   0x30U         // Select input qualification type for GPIO114
#define GPIO_GPDQSEL2_GPIO115_S   6U
#define GPIO_GPDQSEL2_GPIO115_M   0xC0U         // Select input qualification type for GPIO115
#define GPIO_GPDQSEL2_GPIO116_S   8U
#define GPIO_GPDQSEL2_GPIO116_M   0x300U        // Select input qualification type for GPIO116
#define GPIO_GPDQSEL2_GPIO117_S   10U
#define GPIO_GPDQSEL2_GPIO117_M   0xC00U        // Select input qualification type for GPIO117 //add
#define GPIO_GPDQSEL2_GPIO118_S   12U
#define GPIO_GPDQSEL2_GPIO118_M   0x3000U       // Select input qualification type for GPIO118 //add
#define GPIO_GPDQSEL2_GPIO119_S   14U
#define GPIO_GPDQSEL2_GPIO119_M   0xC000U       // Select input qualification type for GPIO119
#define GPIO_GPDQSEL2_GPIO120_S   16U
#define GPIO_GPDQSEL2_GPIO120_M   0x30000U      // Select input qualification type for GPIO120
#define GPIO_GPDQSEL2_GPIO121_S   18U
#define GPIO_GPDQSEL2_GPIO121_M   0xC0000U      // Select input qualification type for GPIO121 //add
#define GPIO_GPDQSEL2_GPIO122_S   20U
#define GPIO_GPDQSEL2_GPIO122_M   0x300000U     // Select input qualification type for GPIO122
#define GPIO_GPDQSEL2_GPIO123_S   22U
#define GPIO_GPDQSEL2_GPIO123_M   0xC00000U     // Select input qualification type for GPIO123
#define GPIO_GPDQSEL2_GPIO124_S   24U
#define GPIO_GPDQSEL2_GPIO124_M   0x3000000U    // Select input qualification type for GPIO124
#define GPIO_GPDQSEL2_GPIO125_S   26U
#define GPIO_GPDQSEL2_GPIO125_M   0xC000000U    // Select input qualification type for GPIO125
#define GPIO_GPDQSEL2_GPIO126_S   28U
#define GPIO_GPDQSEL2_GPIO126_M   0x30000000U   // Select input qualification type for GPIO126
#define GPIO_GPDQSEL2_GPIO127_S   30U
#define GPIO_GPDQSEL2_GPIO127_M   0xC0000000U   // Select input qualification type for GPIO127

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDMUX1 register
//
//*************************************************************************************************
#define GPIO_GPDMUX1_GPIO96_S    0U
#define GPIO_GPDMUX1_GPIO96_M    0x3U          // Defines pin-muxing selection for GPIO96
#define GPIO_GPDMUX1_GPIO97_S    2U
#define GPIO_GPDMUX1_GPIO97_M    0xCU          // Defines pin-muxing selection for GPIO97
#define GPIO_GPDMUX1_GPIO98_S    4U
#define GPIO_GPDMUX1_GPIO98_M    0x30U         // Defines pin-muxing selection for GPIO98
#define GPIO_GPDMUX1_GPIO99_S    6U
#define GPIO_GPDMUX1_GPIO99_M    0xC0U         // Defines pin-muxing selection for GPIO99
#define GPIO_GPDMUX1_GPIO100_S   8U
#define GPIO_GPDMUX1_GPIO100_M   0x300U        // Defines pin-muxing selection for GPIO100
#define GPIO_GPDMUX1_GPIO101_S   10U
#define GPIO_GPDMUX1_GPIO101_M   0xC00U        // Defines pin-muxing selection for GPIO101
#define GPIO_GPDMUX1_GPIO102_S   12U
#define GPIO_GPDMUX1_GPIO102_M   0x3000U       // Defines pin-muxing selection for GPIO102
#define GPIO_GPDMUX1_GPIO103_S   14U
#define GPIO_GPDMUX1_GPIO103_M   0xC000U       // Defines pin-muxing selection for GPIO103
#define GPIO_GPDMUX1_GPIO104_S   16U
#define GPIO_GPDMUX1_GPIO104_M   0x30000U      // Defines pin-muxing selection for GPIO104
#define GPIO_GPDMUX1_GPIO105_S   18U
#define GPIO_GPDMUX1_GPIO105_M   0xC0000U      // Defines pin-muxing selection for GPIO105
#define GPIO_GPDMUX1_GPIO106_S   20U
#define GPIO_GPDMUX1_GPIO106_M   0x300000U     // Defines pin-muxing selection for GPIO106
#define GPIO_GPDMUX1_GPIO107_S   22U
#define GPIO_GPDMUX1_GPIO107_M   0xC00000U     // Defines pin-muxing selection for GPIO107
#define GPIO_GPDMUX1_GPIO108_S   24U
#define GPIO_GPDMUX1_GPIO108_M   0x3000000U    // Defines pin-muxing selection for GPIO108
#define GPIO_GPDMUX1_GPIO109_S   26U
#define GPIO_GPDMUX1_GPIO109_M   0xC000000U    // Defines pin-muxing selection for GPIO109
#define GPIO_GPDMUX1_GPIO110_S   28U
#define GPIO_GPDMUX1_GPIO110_M   0x30000000U   // Defines pin-muxing selection for GPIO110
#define GPIO_GPDMUX1_GPIO111_S   30U
#define GPIO_GPDMUX1_GPIO111_M   0xC0000000U   // Defines pin-muxing selection for GPIO111

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDMUX2 register
//
//*************************************************************************************************
#define GPIO_GPDMUX2_GPIO112_S   0U
#define GPIO_GPDMUX2_GPIO112_M   0x3U          // Defines pin-muxing selection for GPIO112
#define GPIO_GPDMUX2_GPIO113_S   2U
#define GPIO_GPDMUX2_GPIO113_M   0xCU          // Defines pin-muxing selection for GPIO113
#define GPIO_GPDMUX2_GPIO114_S   4U
#define GPIO_GPDMUX2_GPIO114_M   0x30U         // Defines pin-muxing selection for GPIO114
#define GPIO_GPDMUX2_GPIO115_S   6U
#define GPIO_GPDMUX2_GPIO115_M   0xC0U         // Defines pin-muxing selection for GPIO115
#define GPIO_GPDMUX2_GPIO116_S   8U
#define GPIO_GPDMUX2_GPIO116_M   0x300U        // Defines pin-muxing selection for GPIO116
#define GPIO_GPDMUX2_GPIO117_S   10U
#define GPIO_GPDMUX2_GPIO117_M   0xC00U        // Defines pin-muxing selection for GPIO117//add
#define GPIO_GPDMUX2_GPIO118_S   12U
#define GPIO_GPDMUX2_GPIO118_M   0x3000U        // Defines pin-muxing selection for GPIO118 //add
#define GPIO_GPDMUX2_GPIO119_S   14U
#define GPIO_GPDMUX2_GPIO119_M   0xC000U       // Defines pin-muxing selection for GPIO119
#define GPIO_GPDMUX2_GPIO120_S   16U
#define GPIO_GPDMUX2_GPIO120_M   0x30000U      // Defines pin-muxing selection for GPIO120
#define GPIO_GPDMUX2_GPIO121_S   18U
#define GPIO_GPDMUX2_GPIO121_M   0xC0000U      // Defines pin-muxing selection for GPIO121 //add
#define GPIO_GPDMUX2_GPIO122_S   20U
#define GPIO_GPDMUX2_GPIO122_M   0x300000U     // Defines pin-muxing selection for GPIO122
#define GPIO_GPDMUX2_GPIO123_S   22U
#define GPIO_GPDMUX2_GPIO123_M   0xC00000U     // Defines pin-muxing selection for GPIO123
#define GPIO_GPDMUX2_GPIO124_S   24U
#define GPIO_GPDMUX2_GPIO124_M   0x3000000U    // Defines pin-muxing selection for GPIO124
#define GPIO_GPDMUX2_GPIO125_S   26U
#define GPIO_GPDMUX2_GPIO125_M   0xC000000U    // Defines pin-muxing selection for GPIO125
#define GPIO_GPDMUX2_GPIO126_S   28U
#define GPIO_GPDMUX2_GPIO126_M   0x30000000U   // Defines pin-muxing selection for GPIO126
#define GPIO_GPDMUX2_GPIO127_S   30U
#define GPIO_GPDMUX2_GPIO127_M   0xC0000000U   // Defines pin-muxing selection for GPIO127

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDDIR register
//
//*************************************************************************************************
#define GPIO_GPDDIR_GPIO96    0x1U          // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO97    0x2U          // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO98    0x4U          // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO99    0x8U          // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO100   0x10U         // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO101   0x20U         // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO102   0x40U         // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO103   0x80U         // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO104   0x100U        // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO105   0x200U        // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO106   0x400U        // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO107   0x800U        // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO108   0x1000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO109   0x2000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO110   0x4000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO111   0x8000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO112   0x10000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO113   0x20000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO114   0x40000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO115   0x80000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO116   0x100000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO117   0x200000U     // Defines direction for this pin in GPIO mode//add
#define GPIO_GPDDIR_GPIO118   0x400000U     // Defines direction for this pin in GPIO mode//add
#define GPIO_GPDDIR_GPIO119   0x800000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO120   0x1000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO121   0x2000000U    // Defines direction for this pin in GPIO mode//add
#define GPIO_GPDDIR_GPIO122   0x4000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO123   0x8000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO124   0x10000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO125   0x20000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO126   0x40000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPDDIR_GPIO127   0x80000000U   // Defines direction for this pin in GPIO mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDPUD register
//
//*************************************************************************************************
#define GPIO_GPDPUD_GPIO96    0x1U          // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO97    0x2U          // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO98    0x4U          // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO99    0x8U          // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO100   0x10U         // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO101   0x20U         // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO102   0x40U         // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO103   0x80U         // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO104   0x100U        // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO105   0x200U        // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO106   0x400U        // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO107   0x800U        // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO108   0x1000U       // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO109   0x2000U       // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO110   0x4000U       // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO111   0x8000U       // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO112   0x10000U      // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO113   0x20000U      // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO114   0x40000U      // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO115   0x80000U      // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO116   0x100000U     // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO117   0x200000U     // Pull-Up Disable control for this pin //add
#define GPIO_GPDPUD_GPIO118   0x400000U     // Pull-Up Disable control for this pin //add
#define GPIO_GPDPUD_GPIO119   0x800000U     // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO120   0x1000000U    // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO121   0x2000000U    // Pull-Up Disable control for this pin //add
#define GPIO_GPDPUD_GPIO122   0x4000000U    // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO123   0x8000000U    // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO124   0x10000000U   // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO125   0x20000000U   // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO126   0x40000000U   // Pull-Up Disable control for this pin
#define GPIO_GPDPUD_GPIO127   0x80000000U   // Pull-Up Disable control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDINV register
//
//*************************************************************************************************
#define GPIO_GPDINV_GPIO96    0x1U          // Input inversion control for this pin
#define GPIO_GPDINV_GPIO97    0x2U          // Input inversion control for this pin
#define GPIO_GPDINV_GPIO98    0x4U          // Input inversion control for this pin
#define GPIO_GPDINV_GPIO99    0x8U          // Input inversion control for this pin
#define GPIO_GPDINV_GPIO100   0x10U         // Input inversion control for this pin
#define GPIO_GPDINV_GPIO101   0x20U         // Input inversion control for this pin
#define GPIO_GPDINV_GPIO102   0x40U         // Input inversion control for this pin
#define GPIO_GPDINV_GPIO103   0x80U         // Input inversion control for this pin
#define GPIO_GPDINV_GPIO104   0x100U        // Input inversion control for this pin
#define GPIO_GPDINV_GPIO105   0x200U        // Input inversion control for this pin
#define GPIO_GPDINV_GPIO106   0x400U        // Input inversion control for this pin
#define GPIO_GPDINV_GPIO107   0x800U        // Input inversion control for this pin
#define GPIO_GPDINV_GPIO108   0x1000U       // Input inversion control for this pin
#define GPIO_GPDINV_GPIO109   0x2000U       // Input inversion control for this pin
#define GPIO_GPDINV_GPIO110   0x4000U       // Input inversion control for this pin
#define GPIO_GPDINV_GPIO111   0x8000U       // Input inversion control for this pin
#define GPIO_GPDINV_GPIO112   0x10000U      // Input inversion control for this pin
#define GPIO_GPDINV_GPIO113   0x20000U      // Input inversion control for this pin
#define GPIO_GPDINV_GPIO114   0x40000U      // Input inversion control for this pin
#define GPIO_GPDINV_GPIO115   0x80000U      // Input inversion control for this pin
#define GPIO_GPDINV_GPIO116   0x100000U     // Input inversion control for this pin
#define GPIO_GPDINV_GPIO117   0x200000U     // Input inversion control for this pin //add
#define GPIO_GPDINV_GPIO118   0x400000U     // Input inversion control for this pin //add
#define GPIO_GPDINV_GPIO119   0x800000U     // Input inversion control for this pin
#define GPIO_GPDINV_GPIO120   0x1000000U    // Input inversion control for this pin
#define GPIO_GPDINV_GPIO121   0x2000000U    // Input inversion control for this pin //add
#define GPIO_GPDINV_GPIO122   0x4000000U    // Input inversion control for this pin
#define GPIO_GPDINV_GPIO123   0x8000000U    // Input inversion control for this pin
#define GPIO_GPDINV_GPIO124   0x10000000U   // Input inversion control for this pin
#define GPIO_GPDINV_GPIO125   0x20000000U   // Input inversion control for this pin
#define GPIO_GPDINV_GPIO126   0x40000000U   // Input inversion control for this pin
#define GPIO_GPDINV_GPIO127   0x80000000U   // Input inversion control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDODR register
//
//*************************************************************************************************
#define GPIO_GPDODR_GPIO96    0x1U          // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO97    0x2U          // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO98    0x4U          // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO99    0x8U          // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO100   0x10U         // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO101   0x20U         // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO102   0x40U         // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO103   0x80U         // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO104   0x100U        // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO105   0x200U        // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO106   0x400U        // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO107   0x800U        // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO108   0x1000U       // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO109   0x2000U       // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO110   0x4000U       // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO111   0x8000U       // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO112   0x10000U      // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO113   0x20000U      // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO114   0x40000U      // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO115   0x80000U      // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO116   0x100000U     // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO117   0x200000U     // Output Open-Drain control for this pin //add
#define GPIO_GPDODR_GPIO118   0x400000U     // Output Open-Drain control for this pin //add
#define GPIO_GPDODR_GPIO119   0x800000U     // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO120   0x1000000U    // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO121   0x2000000U    // Output Open-Drain control for this pin//add
#define GPIO_GPDODR_GPIO122   0x4000000U    // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO123   0x8000000U    // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO124   0x10000000U   // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO125   0x20000000U   // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO126   0x40000000U   // Output Open-Drain control for this pin
#define GPIO_GPDODR_GPIO127   0x80000000U   // Output Open-Drain control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDGMUX1 register
//
//*************************************************************************************************
#define GPIO_GPDGMUX1_GPIO96_S    0U
#define GPIO_GPDGMUX1_GPIO96_M    0x3U          // Defines pin-muxing selection for GPIO96
#define GPIO_GPDGMUX1_GPIO97_S    2U
#define GPIO_GPDGMUX1_GPIO97_M    0xCU          // Defines pin-muxing selection for GPIO97
#define GPIO_GPDGMUX1_GPIO98_S    4U
#define GPIO_GPDGMUX1_GPIO98_M    0x30U         // Defines pin-muxing selection for GPIO98
#define GPIO_GPDGMUX1_GPIO99_S    6U
#define GPIO_GPDGMUX1_GPIO99_M    0xC0U         // Defines pin-muxing selection for GPIO99
#define GPIO_GPDGMUX1_GPIO100_S   8U
#define GPIO_GPDGMUX1_GPIO100_M   0x300U        // Defines pin-muxing selection for GPIO100
#define GPIO_GPDGMUX1_GPIO101_S   10U
#define GPIO_GPDGMUX1_GPIO101_M   0xC00U        // Defines pin-muxing selection for GPIO101
#define GPIO_GPDGMUX1_GPIO102_S   12U
#define GPIO_GPDGMUX1_GPIO102_M   0x3000U       // Defines pin-muxing selection for GPIO102
#define GPIO_GPDGMUX1_GPIO103_S   14U
#define GPIO_GPDGMUX1_GPIO103_M   0xC000U       // Defines pin-muxing selection for GPIO103
#define GPIO_GPDGMUX1_GPIO104_S   16U
#define GPIO_GPDGMUX1_GPIO104_M   0x30000U      // Defines pin-muxing selection for GPIO104
#define GPIO_GPDGMUX1_GPIO105_S   18U
#define GPIO_GPDGMUX1_GPIO105_M   0xC0000U      // Defines pin-muxing selection for GPIO105
#define GPIO_GPDGMUX1_GPIO106_S   20U
#define GPIO_GPDGMUX1_GPIO106_M   0x300000U     // Defines pin-muxing selection for GPIO106
#define GPIO_GPDGMUX1_GPIO107_S   22U
#define GPIO_GPDGMUX1_GPIO107_M   0xC00000U     // Defines pin-muxing selection for GPIO107
#define GPIO_GPDGMUX1_GPIO108_S   24U
#define GPIO_GPDGMUX1_GPIO108_M   0x3000000U    // Defines pin-muxing selection for GPIO108
#define GPIO_GPDGMUX1_GPIO109_S   26U
#define GPIO_GPDGMUX1_GPIO109_M   0xC000000U    // Defines pin-muxing selection for GPIO109
#define GPIO_GPDGMUX1_GPIO110_S   28U
#define GPIO_GPDGMUX1_GPIO110_M   0x30000000U   // Defines pin-muxing selection for GPIO110
#define GPIO_GPDGMUX1_GPIO111_S   30U
#define GPIO_GPDGMUX1_GPIO111_M   0xC0000000U   // Defines pin-muxing selection for GPIO111

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDGMUX2 register
//
//*************************************************************************************************
#define GPIO_GPDGMUX2_GPIO112_S   0U
#define GPIO_GPDGMUX2_GPIO112_M   0x3U          // Defines pin-muxing selection for GPIO112
#define GPIO_GPDGMUX2_GPIO113_S   2U
#define GPIO_GPDGMUX2_GPIO113_M   0xCU          // Defines pin-muxing selection for GPIO113
#define GPIO_GPDGMUX2_GPIO114_S   4U
#define GPIO_GPDGMUX2_GPIO114_M   0x30U         // Defines pin-muxing selection for GPIO114
#define GPIO_GPDGMUX2_GPIO115_S   6U
#define GPIO_GPDGMUX2_GPIO115_M   0xC0U         // Defines pin-muxing selection for GPIO115
#define GPIO_GPDGMUX2_GPIO116_S   8U
#define GPIO_GPDGMUX2_GPIO116_M   0x300U        // Defines pin-muxing selection for GPIO116
#define GPIO_GPDGMUX2_GPIO117_S   10U
#define GPIO_GPDGMUX2_GPIO117_M   0xC00U        // Defines pin-muxing selection for GPIO117  //add
#define GPIO_GPDGMUX2_GPIO118_S   12U
#define GPIO_GPDGMUX2_GPIO118_M   0x3000U       // Defines pin-muxing selection for GPIO118  //add
#define GPIO_GPDGMUX2_GPIO119_S   14U
#define GPIO_GPDGMUX2_GPIO119_M   0xC000U       // Defines pin-muxing selection for GPIO119
#define GPIO_GPDGMUX2_GPIO120_S   16U
#define GPIO_GPDGMUX2_GPIO120_M   0x30000U      // Defines pin-muxing selection for GPIO120
#define GPIO_GPDGMUX2_GPIO121_S   18U
#define GPIO_GPDGMUX2_GPIO121_M   0xC0000U      // Defines pin-muxing selection for GPIO121
#define GPIO_GPDGMUX2_GPIO122_S   20U
#define GPIO_GPDGMUX2_GPIO122_M   0x300000U     // Defines pin-muxing selection for GPIO122
#define GPIO_GPDGMUX2_GPIO123_S   22U
#define GPIO_GPDGMUX2_GPIO123_M   0xC00000U     // Defines pin-muxing selection for GPIO123
#define GPIO_GPDGMUX2_GPIO124_S   24U
#define GPIO_GPDGMUX2_GPIO124_M   0x3000000U    // Defines pin-muxing selection for GPIO124
#define GPIO_GPDGMUX2_GPIO125_S   26U
#define GPIO_GPDGMUX2_GPIO125_M   0xC000000U    // Defines pin-muxing selection for GPIO125
#define GPIO_GPDGMUX2_GPIO126_S   28U
#define GPIO_GPDGMUX2_GPIO126_M   0x30000000U   // Defines pin-muxing selection for GPIO126
#define GPIO_GPDGMUX2_GPIO127_S   30U
#define GPIO_GPDGMUX2_GPIO127_M   0xC0000000U   // Defines pin-muxing selection for GPIO127

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDCSEL1 register
//
//*************************************************************************************************
#define GPIO_GPDCSEL1_GPIO96_S    0U
#define GPIO_GPDCSEL1_GPIO96_M    0xFU          // GPIO96 Controller CPU Select
#define GPIO_GPDCSEL1_GPIO97_S    4U
#define GPIO_GPDCSEL1_GPIO97_M    0xF0U         // GPIO97 Controller CPU Select
#define GPIO_GPDCSEL1_GPIO98_S    8U
#define GPIO_GPDCSEL1_GPIO98_M    0xF00U        // GPIO98 Controller CPU Select
#define GPIO_GPDCSEL1_GPIO99_S    12U
#define GPIO_GPDCSEL1_GPIO99_M    0xF000U       // GPIO99 Controller CPU Select
#define GPIO_GPDCSEL1_GPIO100_S   16U
#define GPIO_GPDCSEL1_GPIO100_M   0xF0000U      // GPIO100 Controller CPU Select
#define GPIO_GPDCSEL1_GPIO101_S   20U
#define GPIO_GPDCSEL1_GPIO101_M   0xF00000U     // GPIO101 Controller CPU Select
#define GPIO_GPDCSEL1_GPIO102_S   24U
#define GPIO_GPDCSEL1_GPIO102_M   0xF000000U    // GPIO102 Controller CPU Select
#define GPIO_GPDCSEL1_GPIO103_S   28U
#define GPIO_GPDCSEL1_GPIO103_M   0xF0000000U   // GPIO103 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDCSEL2 register
//
//*************************************************************************************************
#define GPIO_GPDCSEL2_GPIO104_S   0U
#define GPIO_GPDCSEL2_GPIO104_M   0xFU          // GPIO104 Controller CPU Select
#define GPIO_GPDCSEL2_GPIO105_S   4U
#define GPIO_GPDCSEL2_GPIO105_M   0xF0U         // GPIO105 Controller CPU Select
#define GPIO_GPDCSEL2_GPIO106_S   8U
#define GPIO_GPDCSEL2_GPIO106_M   0xF00U        // GPIO106 Controller CPU Select
#define GPIO_GPDCSEL2_GPIO107_S   12U
#define GPIO_GPDCSEL2_GPIO107_M   0xF000U       // GPIO107 Controller CPU Select
#define GPIO_GPDCSEL2_GPIO108_S   16U
#define GPIO_GPDCSEL2_GPIO108_M   0xF0000U      // GPIO108 Controller CPU Select
#define GPIO_GPDCSEL2_GPIO109_S   20U
#define GPIO_GPDCSEL2_GPIO109_M   0xF00000U     // GPIO109 Controller CPU Select
#define GPIO_GPDCSEL2_GPIO110_S   24U
#define GPIO_GPDCSEL2_GPIO110_M   0xF000000U    // GPIO110 Controller CPU Select
#define GPIO_GPDCSEL2_GPIO111_S   28U
#define GPIO_GPDCSEL2_GPIO111_M   0xF0000000U   // GPIO111 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDCSEL3 register
//
//*************************************************************************************************
#define GPIO_GPDCSEL3_GPIO112_S   0U
#define GPIO_GPDCSEL3_GPIO112_M   0xFU          // GPIO112 Controller CPU Select
#define GPIO_GPDCSEL3_GPIO113_S   4U
#define GPIO_GPDCSEL3_GPIO113_M   0xF0U         // GPIO113 Controller CPU Select
#define GPIO_GPDCSEL3_GPIO114_S   8U
#define GPIO_GPDCSEL3_GPIO114_M   0xF00U        // GPIO114 Controller CPU Select
#define GPIO_GPDCSEL3_GPIO115_S   12U
#define GPIO_GPDCSEL3_GPIO115_M   0xF000U       // GPIO115 Controller CPU Select
#define GPIO_GPDCSEL3_GPIO116_S   16U
#define GPIO_GPDCSEL3_GPIO116_M   0xF0000U      // GPIO116 Controller CPU Select
#define GPIO_GPDCSEL3_GPIO117_S   20U
#define GPIO_GPDCSEL3_GPIO117_M   0xF00000U      // GPIO117 Controller CPU Select //add
#define GPIO_GPDCSEL3_GPIO118_S   24U
#define GPIO_GPDCSEL3_GPIO118_M   0xF000000U      // GPIO118 Controller CPU Select //add
#define GPIO_GPDCSEL3_GPIO119_S   28U
#define GPIO_GPDCSEL3_GPIO119_M   0xF0000000U   // GPIO119 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDCSEL4 register
//
//*************************************************************************************************
#define GPIO_GPDCSEL4_GPIO120_S   0U
#define GPIO_GPDCSEL4_GPIO120_M   0xFU          // GPIO120 Controller CPU Select
#define GPIO_GPDCSEL4_GPIO121_S   4U
#define GPIO_GPDCSEL4_GPIO121_M   0xF0U         // GPIO121 Controller CPU Select //add
#define GPIO_GPDCSEL4_GPIO122_S   8U
#define GPIO_GPDCSEL4_GPIO122_M   0xF00U        // GPIO122 Controller CPU Select
#define GPIO_GPDCSEL4_GPIO123_S   12U
#define GPIO_GPDCSEL4_GPIO123_M   0xF000U       // GPIO123 Controller CPU Select
#define GPIO_GPDCSEL4_GPIO124_S   16U
#define GPIO_GPDCSEL4_GPIO124_M   0xF0000U      // GPIO124 Controller CPU Select
#define GPIO_GPDCSEL4_GPIO125_S   20U
#define GPIO_GPDCSEL4_GPIO125_M   0xF00000U     // GPIO125 Controller CPU Select
#define GPIO_GPDCSEL4_GPIO126_S   24U
#define GPIO_GPDCSEL4_GPIO126_M   0xF000000U    // GPIO126 Controller CPU Select
#define GPIO_GPDCSEL4_GPIO127_S   28U
#define GPIO_GPDCSEL4_GPIO127_M   0xF0000000U   // GPIO127 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDLOCK register
//
//*************************************************************************************************
#define GPIO_GPDLOCK_GPIO96    0x1U          // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO97    0x2U          // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO98    0x4U          // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO99    0x8U          // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO100   0x10U         // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO101   0x20U         // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO102   0x40U         // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO103   0x80U         // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO104   0x100U        // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO105   0x200U        // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO106   0x400U        // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO107   0x800U        // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO108   0x1000U       // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO109   0x2000U       // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO110   0x4000U       // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO111   0x8000U       // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO112   0x10000U      // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO113   0x20000U      // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO114   0x40000U      // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO115   0x80000U      // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO116   0x100000U     // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO117   0x200000U     // Configuration Lock bit for this pin //add
#define GPIO_GPDLOCK_GPIO118   0x400000U     // Configuration Lock bit for this pin //add
#define GPIO_GPDLOCK_GPIO119   0x800000U     // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO120   0x1000000U    // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO121   0x2000000U    // Configuration Lock bit for this pin //add
#define GPIO_GPDLOCK_GPIO122   0x4000000U    // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO123   0x8000000U    // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO124   0x10000000U   // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO125   0x20000000U   // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO126   0x40000000U   // Configuration Lock bit for this pin
#define GPIO_GPDLOCK_GPIO127   0x80000000U   // Configuration Lock bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDCR register
//
//*************************************************************************************************
#define GPIO_GPDCR_GPIO96    0x1U          // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO97    0x2U          // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO98    0x4U          // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO99    0x8U          // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO100   0x10U         // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO101   0x20U         // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO102   0x40U         // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO103   0x80U         // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO104   0x100U        // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO105   0x200U        // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO106   0x400U        // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO107   0x800U        // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO108   0x1000U       // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO109   0x2000U       // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO110   0x4000U       // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO111   0x8000U       // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO112   0x10000U      // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO113   0x20000U      // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO114   0x40000U      // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO115   0x80000U      // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO116   0x100000U     // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO117   0x200000U     // Configuration lock commit bit for this pin //add
#define GPIO_GPDCR_GPIO118   0x400000U     // Configuration lock commit bit for this pin //add
#define GPIO_GPDCR_GPIO119   0x800000U     // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO120   0x1000000U    // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO121   0x2000000U    // Configuration lock commit bit for this pin //add
#define GPIO_GPDCR_GPIO122   0x4000000U    // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO123   0x8000000U    // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO124   0x10000000U   // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO125   0x20000000U   // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO126   0x40000000U   // Configuration lock commit bit for this pin
#define GPIO_GPDCR_GPIO127   0x80000000U   // Configuration lock commit bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPECTRL register
//
//*************************************************************************************************
#define GPIO_GPECTRL_QUALPRD0_S   0U
#define GPIO_GPECTRL_QUALPRD0_M   0xFFU         // Qualification sampling period for GPIO128 to
                                                // GPIO135
#define GPIO_GPECTRL_QUALPRD1_S   8U
#define GPIO_GPECTRL_QUALPRD1_M   0xFF00U       // Qualification sampling period for GPIO136 to
                                                // GPIO143
#define GPIO_GPECTRL_QUALPRD2_S   16U
#define GPIO_GPECTRL_QUALPRD2_M   0xFF0000U     // Qualification sampling period for GPIO144 to
                                                // GPIO151
#define GPIO_GPECTRL_QUALPRD3_S   24U
#define GPIO_GPECTRL_QUALPRD3_M   0xFF000000U   // Qualification sampling period for GPIO152 to
                                                // GPIO159

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEQSEL1 register
//
//*************************************************************************************************
#define GPIO_GPEQSEL1_GPIO128_S   0U
#define GPIO_GPEQSEL1_GPIO128_M   0x3U          // Select input qualification type for GPIO128
#define GPIO_GPEQSEL1_GPIO129_S   2U
#define GPIO_GPEQSEL1_GPIO129_M   0xCU          // Select input qualification type for GPIO129
#define GPIO_GPEQSEL1_GPIO130_S   4U
#define GPIO_GPEQSEL1_GPIO130_M   0x30U         // Select input qualification type for GPIO130
#define GPIO_GPEQSEL1_GPIO131_S   6U
#define GPIO_GPEQSEL1_GPIO131_M   0xC0U         // Select input qualification type for GPIO131
#define GPIO_GPEQSEL1_GPIO132_S   8U
#define GPIO_GPEQSEL1_GPIO132_M   0x300U        // Select input qualification type for GPIO132
#define GPIO_GPEQSEL1_GPIO133_S   10U
#define GPIO_GPEQSEL1_GPIO133_M   0xC00U        // Select input qualification type for GPIO133
#define GPIO_GPEQSEL1_GPIO134_S   12U
#define GPIO_GPEQSEL1_GPIO134_M   0x3000U       // Select input qualification type for GPIO134
#define GPIO_GPEQSEL1_GPIO135_S   14U
#define GPIO_GPEQSEL1_GPIO135_M   0xC000U       // Select input qualification type for GPIO135 //add
#define GPIO_GPEQSEL1_GPIO136_S   16U
#define GPIO_GPEQSEL1_GPIO136_M   0x30000U      // Select input qualification type for GPIO136 //add
#define GPIO_GPEQSEL1_GPIO137_S   18U
#define GPIO_GPEQSEL1_GPIO137_M   0xC0000U      // Select input qualification type for GPIO137 //add
#define GPIO_GPEQSEL1_GPIO138_S   20U
#define GPIO_GPEQSEL1_GPIO138_M   0x300000U     // Select input qualification type for GPIO138 //add
#define GPIO_GPEQSEL1_GPIO139_S   22U
#define GPIO_GPEQSEL1_GPIO139_M   0xC00000U     // Select input qualification type for GPIO139 //add
#define GPIO_GPEQSEL1_GPIO140_S   24U
#define GPIO_GPEQSEL1_GPIO140_M   0x3000000U    // Select input qualification type for GPIO140 //add
#define GPIO_GPEQSEL1_GPIO141_S   26U
#define GPIO_GPEQSEL1_GPIO141_M   0xC000000U    // Select input qualification type for GPIO141
#define GPIO_GPEQSEL1_GPIO142_S   28U
#define GPIO_GPEQSEL1_GPIO142_M   0x30000000U   // Select input qualification type for GPIO142
#define GPIO_GPEQSEL1_GPIO143_S   30U
#define GPIO_GPEQSEL1_GPIO143_M   0xC0000000U    // Select input qualification type for GPIO143 //add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEQSEL2 register
//
//*************************************************************************************************
#define GPIO_GPEQSEL2_GPIO144_S   0U
#define GPIO_GPEQSEL2_GPIO144_M   0x3U          // Select input qualification type for GPIO144 //add
#define GPIO_GPEQSEL2_GPIO145_S   2U
#define GPIO_GPEQSEL2_GPIO145_M   0xCU          // Select input qualification type for GPIO145
#define GPIO_GPEQSEL2_GPIO146_S   4U
#define GPIO_GPEQSEL2_GPIO146_M   0x30U         // Select input qualification type for GPIO146
#define GPIO_GPEQSEL2_GPIO147_S   6U
#define GPIO_GPEQSEL2_GPIO147_M   0xC0U         // Select input qualification type for GPIO147
#define GPIO_GPEQSEL2_GPIO148_S   8U
#define GPIO_GPEQSEL2_GPIO148_M   0x300U        // Select input qualification type for GPIO148
#define GPIO_GPEQSEL2_GPIO149_S   10U
#define GPIO_GPEQSEL2_GPIO149_M   0xC00U        // Select input qualification type for GPIO149
#define GPIO_GPEQSEL2_GPIO150_S   12U
#define GPIO_GPEQSEL2_GPIO150_M   0x3000U       // Select input qualification type for GPIO150
#define GPIO_GPEQSEL2_GPIO151_S   14U
#define GPIO_GPEQSEL2_GPIO151_M   0xC000U       // Select input qualification type for GPIO151
#define GPIO_GPEQSEL2_GPIO152_S   16U
#define GPIO_GPEQSEL2_GPIO152_M   0x30000U      // Select input qualification type for GPIO152
#define GPIO_GPEQSEL2_GPIO153_S   18U
#define GPIO_GPEQSEL2_GPIO153_M   0xC0000U      // Select input qualification type for GPIO153
#define GPIO_GPEQSEL2_GPIO154_S   20U
#define GPIO_GPEQSEL2_GPIO154_M   0x300000U     // Select input qualification type for GPIO154
#define GPIO_GPEQSEL2_GPIO155_S   22U
#define GPIO_GPEQSEL2_GPIO155_M   0xC00000U     // Select input qualification type for GPIO155
#define GPIO_GPEQSEL2_GPIO156_S   24U
#define GPIO_GPEQSEL2_GPIO156_M   0x3000000U    // Select input qualification type for GPIO156
#define GPIO_GPEQSEL2_GPIO157_S   26U
#define GPIO_GPEQSEL2_GPIO157_M   0xC000000U    // Select input qualification type for GPIO157
#define GPIO_GPEQSEL2_GPIO158_S   28U
#define GPIO_GPEQSEL2_GPIO158_M   0x30000000U   // Select input qualification type for GPIO158
#define GPIO_GPEQSEL2_GPIO159_S   30U
#define GPIO_GPEQSEL2_GPIO159_M   0xC0000000U   // Select input qualification type for GPIO159

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEMUX1 register
//
//*************************************************************************************************
#define GPIO_GPEMUX1_GPIO128_S   0U
#define GPIO_GPEMUX1_GPIO128_M   0x3U          // Defines pin-muxing selection for GPIO128
#define GPIO_GPEMUX1_GPIO129_S   2U
#define GPIO_GPEMUX1_GPIO129_M   0xCU          // Defines pin-muxing selection for GPIO129
#define GPIO_GPEMUX1_GPIO130_S   4U
#define GPIO_GPEMUX1_GPIO130_M   0x30U         // Defines pin-muxing selection for GPIO130
#define GPIO_GPEMUX1_GPIO131_S   6U
#define GPIO_GPEMUX1_GPIO131_M   0xC0U         // Defines pin-muxing selection for GPIO131
#define GPIO_GPEMUX1_GPIO132_S   8U
#define GPIO_GPEMUX1_GPIO132_M   0x300U        // Defines pin-muxing selection for GPIO132
#define GPIO_GPEMUX1_GPIO133_S   10U
#define GPIO_GPEMUX1_GPIO133_M   0xC00U        // Defines pin-muxing selection for GPIO133
#define GPIO_GPEMUX1_GPIO134_S   12U
#define GPIO_GPEMUX1_GPIO134_M   0x3000U       // Defines pin-muxing selection for GPIO134
#define GPIO_GPEMUX1_GPIO135_S   14U
#define GPIO_GPEMUX1_GPIO135_M   0xC000U       // Defines pin-muxing selection for GPIO135 //add
#define GPIO_GPEMUX1_GPIO136_S   16U
#define GPIO_GPEMUX1_GPIO136_M   0x30000U       // Defines pin-muxing selection for GPIO136 //add
#define GPIO_GPEMUX1_GPIO137_S   18U
#define GPIO_GPEMUX1_GPIO137_M   0xC0000U       // Defines pin-muxing selection for GPIO137 //add
#define GPIO_GPEMUX1_GPIO138_S   20U
#define GPIO_GPEMUX1_GPIO138_M   0x300000U     // Defines pin-muxing selection for GPIO138 //add
#define GPIO_GPEMUX1_GPIO139_S   22U
#define GPIO_GPEMUX1_GPIO139_M   0xC00000U       // Defines pin-muxing selection for GPIO139 //add
#define GPIO_GPEMUX1_GPIO140_S   24U
#define GPIO_GPEMUX1_GPIO140_M   0x3000000U    // Defines pin-muxing selection for GPIO140 //add
#define GPIO_GPEMUX1_GPIO141_S   26U
#define GPIO_GPEMUX1_GPIO141_M   0xC000000U    // Defines pin-muxing selection for GPIO141
#define GPIO_GPEMUX1_GPIO142_S   28U
#define GPIO_GPEMUX1_GPIO142_M   0x30000000U   // Defines pin-muxing selection for GPIO142
#define GPIO_GPEMUX1_GPIO143_S   30U
#define GPIO_GPEMUX1_GPIO143_M   0xC0000000U   // Defines pin-muxing selection for GPIO143 //add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEMUX2 register
//
//*************************************************************************************************
#define GPIO_GPEMUX2_GPIO144_S   0U
#define GPIO_GPEMUX2_GPIO144_M   0x3U          // Defines pin-muxing selection for GPIO144 //add
#define GPIO_GPEMUX2_GPIO145_S   2U
#define GPIO_GPEMUX2_GPIO145_M   0xCU          // Defines pin-muxing selection for GPIO145
#define GPIO_GPEMUX2_GPIO146_S   4U
#define GPIO_GPEMUX2_GPIO146_M   0x30U         // Defines pin-muxing selection for GPIO146
#define GPIO_GPEMUX2_GPIO147_S   6U
#define GPIO_GPEMUX2_GPIO147_M   0xC0U         // Defines pin-muxing selection for GPIO147
#define GPIO_GPEMUX2_GPIO148_S   8U
#define GPIO_GPEMUX2_GPIO148_M   0x300U        // Defines pin-muxing selection for GPIO148
#define GPIO_GPEMUX2_GPIO149_S   10U
#define GPIO_GPEMUX2_GPIO149_M   0xC00U        // Defines pin-muxing selection for GPIO149
#define GPIO_GPEMUX2_GPIO150_S   12U
#define GPIO_GPEMUX2_GPIO150_M   0x3000U       // Defines pin-muxing selection for GPIO150
#define GPIO_GPEMUX2_GPIO151_S   14U
#define GPIO_GPEMUX2_GPIO151_M   0xC000U       // Defines pin-muxing selection for GPIO151
#define GPIO_GPEMUX2_GPIO152_S   16U
#define GPIO_GPEMUX2_GPIO152_M   0x30000U      // Defines pin-muxing selection for GPIO152
#define GPIO_GPEMUX2_GPIO153_S   18U
#define GPIO_GPEMUX2_GPIO153_M   0xC0000U      // Defines pin-muxing selection for GPIO153
#define GPIO_GPEMUX2_GPIO154_S   20U
#define GPIO_GPEMUX2_GPIO154_M   0x300000U     // Defines pin-muxing selection for GPIO154
#define GPIO_GPEMUX2_GPIO155_S   22U
#define GPIO_GPEMUX2_GPIO155_M   0xC00000U     // Defines pin-muxing selection for GPIO155
#define GPIO_GPEMUX2_GPIO156_S   24U
#define GPIO_GPEMUX2_GPIO156_M   0x3000000U    // Defines pin-muxing selection for GPIO156
#define GPIO_GPEMUX2_GPIO157_S   26U
#define GPIO_GPEMUX2_GPIO157_M   0xC000000U    // Defines pin-muxing selection for GPIO157
#define GPIO_GPEMUX2_GPIO158_S   28U
#define GPIO_GPEMUX2_GPIO158_M   0x30000000U   // Defines pin-muxing selection for GPIO158
#define GPIO_GPEMUX2_GPIO159_S   30U
#define GPIO_GPEMUX2_GPIO159_M   0xC0000000U   // Defines pin-muxing selection for GPIO159

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEDIR register
//
//*************************************************************************************************
#define GPIO_GPEDIR_GPIO128   0x1U          // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO129   0x2U          // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO130   0x4U          // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO131   0x8U          // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO132   0x10U         // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO133   0x20U         // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO134   0x40U         // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO135   0x80U         // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO136   0x100U        // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO137   0x200U        // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO138   0x400U        // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO139   0x800U        // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO140   0x1000U       // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO141   0x2000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO142   0x4000U       // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO143   0x8000U       // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO144   0x10000U      // Defines direction for this pin in GPIO mode//add
#define GPIO_GPEDIR_GPIO145   0x20000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO146   0x40000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO147   0x80000U      // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO148   0x100000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO149   0x200000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO150   0x400000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO151   0x800000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO152   0x1000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO153   0x2000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO154   0x4000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO155   0x8000000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO156   0x10000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO157   0x20000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO158   0x40000000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPEDIR_GPIO159   0x80000000U   // Defines direction for this pin in GPIO mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEPUD register
//
//*************************************************************************************************
#define GPIO_GPEPUD_GPIO128   0x1U          // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO129   0x2U          // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO130   0x4U          // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO131   0x8U          // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO132   0x10U         // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO133   0x20U         // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO134   0x40U         // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO135   0x80U         // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO136   0x100U        // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO137   0x200U        // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO138   0x400U        // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO139   0x800U        // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO140   0x1000U       // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO141   0x2000U       // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO142   0x4000U       // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO143   0x8000U       // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO144   0x10000U      // Pull-Up Disable control for this pin //add
#define GPIO_GPEPUD_GPIO145   0x20000U      // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO146   0x40000U      // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO147   0x80000U      // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO148   0x100000U     // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO149   0x200000U     // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO150   0x400000U     // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO151   0x800000U     // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO152   0x1000000U    // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO153   0x2000000U    // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO154   0x4000000U    // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO155   0x8000000U    // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO156   0x10000000U   // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO157   0x20000000U   // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO158   0x40000000U   // Pull-Up Disable control for this pin
#define GPIO_GPEPUD_GPIO159   0x80000000U   // Pull-Up Disable control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEINV register
//
//*************************************************************************************************
#define GPIO_GPEINV_GPIO128   0x1U          // Input inversion control for this pin
#define GPIO_GPEINV_GPIO129   0x2U          // Input inversion control for this pin
#define GPIO_GPEINV_GPIO130   0x4U          // Input inversion control for this pin
#define GPIO_GPEINV_GPIO131   0x8U          // Input inversion control for this pin
#define GPIO_GPEINV_GPIO132   0x10U         // Input inversion control for this pin
#define GPIO_GPEINV_GPIO133   0x20U         // Input inversion control for this pin
#define GPIO_GPEINV_GPIO135   0x40U         // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO136   0x80U         // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO137   0x100U        // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO138   0x400U        // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO139   0x800U        // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO140   0x1000U       // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO141   0x2000U       // Input inversion control for this pin
#define GPIO_GPEINV_GPIO142   0x4000U       // Input inversion control for this pin
#define GPIO_GPEINV_GPIO143   0x8000U       // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO144   0x10000U       // Input inversion control for this pin //add
#define GPIO_GPEINV_GPIO145   0x20000U      // Input inversion control for this pin
#define GPIO_GPEINV_GPIO146   0x40000U      // Input inversion control for this pin
#define GPIO_GPEINV_GPIO147   0x80000U      // Input inversion control for this pin
#define GPIO_GPEINV_GPIO148   0x100000U     // Input inversion control for this pin
#define GPIO_GPEINV_GPIO149   0x200000U     // Input inversion control for this pin
#define GPIO_GPEINV_GPIO150   0x400000U     // Input inversion control for this pin
#define GPIO_GPEINV_GPIO151   0x800000U     // Input inversion control for this pin
#define GPIO_GPEINV_GPIO152   0x1000000U    // Input inversion control for this pin
#define GPIO_GPEINV_GPIO153   0x2000000U    // Input inversion control for this pin
#define GPIO_GPEINV_GPIO154   0x4000000U    // Input inversion control for this pin
#define GPIO_GPEINV_GPIO155   0x8000000U    // Input inversion control for this pin
#define GPIO_GPEINV_GPIO156   0x10000000U   // Input inversion control for this pin
#define GPIO_GPEINV_GPIO157   0x20000000U   // Input inversion control for this pin
#define GPIO_GPEINV_GPIO158   0x40000000U   // Input inversion control for this pin
#define GPIO_GPEINV_GPIO159   0x80000000U   // Input inversion control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEODR register
//
//*************************************************************************************************
#define GPIO_GPEODR_GPIO128   0x1U          // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO129   0x2U          // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO130   0x4U          // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO131   0x8U          // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO132   0x10U         // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO133   0x20U         // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO134   0x40U         // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO135   0x80U         // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO136   0x100U        // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO137   0x200U        // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO138   0x400U        // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO139   0x800U        // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO140   0x1000U       // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO141   0x2000U       // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO142   0x4000U       // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO143   0x8000U       // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO144   0x10000U      // Output Open-Drain control for this pin//add
#define GPIO_GPEODR_GPIO145   0x20000U      // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO146   0x40000U      // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO147   0x80000U      // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO148   0x100000U     // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO149   0x200000U     // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO150   0x400000U     // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO151   0x800000U     // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO152   0x1000000U    // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO153   0x2000000U    // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO154   0x4000000U    // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO155   0x8000000U    // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO156   0x10000000U   // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO157   0x20000000U   // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO158   0x40000000U   // Output Open-Drain control for this pin
#define GPIO_GPEODR_GPIO159   0x80000000U   // Output Open-Drain control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEGMUX1 register
//
//*************************************************************************************************
#define GPIO_GPEGMUX1_GPIO128_S   0U
#define GPIO_GPEGMUX1_GPIO128_M   0x3U          // Defines pin-muxing selection for GPIO128
#define GPIO_GPEGMUX1_GPIO129_S   2U
#define GPIO_GPEGMUX1_GPIO129_M   0xCU          // Defines pin-muxing selection for GPIO129
#define GPIO_GPEGMUX1_GPIO130_S   4U
#define GPIO_GPEGMUX1_GPIO130_M   0x30U         // Defines pin-muxing selection for GPIO130
#define GPIO_GPEGMUX1_GPIO131_S   6U
#define GPIO_GPEGMUX1_GPIO131_M   0xC0U         // Defines pin-muxing selection for GPIO131
#define GPIO_GPEGMUX1_GPIO132_S   8U
#define GPIO_GPEGMUX1_GPIO132_M   0x300U        // Defines pin-muxing selection for GPIO132
#define GPIO_GPEGMUX1_GPIO133_S   10U
#define GPIO_GPEGMUX1_GPIO133_M   0xC00U        // Defines pin-muxing selection for GPIO133
#define GPIO_GPEGMUX1_GPIO134_S   12U
#define GPIO_GPEGMUX1_GPIO134_M   0x3000U       // Defines pin-muxing selection for GPIO134
#define GPIO_GPEGMUX1_GPIO135_S   14U
#define GPIO_GPEGMUX1_GPIO135_M   0xC000U       // Defines pin-muxing selection for GPIO135 //add
#define GPIO_GPEGMUX1_GPIO136_S   16U
#define GPIO_GPEGMUX1_GPIO136_M   0x30000U      // Defines pin-muxing selection for GPIO136//add
#define GPIO_GPEGMUX1_GPIO137_S   18U
#define GPIO_GPEGMUX1_GPIO137_M   0xC0000U      // Defines pin-muxing selection for GPIO137//add
#define GPIO_GPEGMUX1_GPIO138_S   20U
#define GPIO_GPEGMUX1_GPIO138_M   0x300000U     // Defines pin-muxing selection for GPIO138//add
#define GPIO_GPEGMUX1_GPIO139_S   22U
#define GPIO_GPEGMUX1_GPIO139_M   0xC00000U     // Defines pin-muxing selection for GPIO139//add
#define GPIO_GPEGMUX1_GPIO140_S   24U
#define GPIO_GPEGMUX1_GPIO140_M   0x3000000U    // Defines pin-muxing selection for GPIO140//add
#define GPIO_GPEGMUX1_GPIO141_S   26U
#define GPIO_GPEGMUX1_GPIO141_M   0xC000000U    // Defines pin-muxing selection for GPIO141
#define GPIO_GPEGMUX1_GPIO142_S   28U
#define GPIO_GPEGMUX1_GPIO142_M   0x30000000U   // Defines pin-muxing selection for GPIO142
#define GPIO_GPEGMUX1_GPIO143_S   30U
#define GPIO_GPEGMUX1_GPIO143_M   0xC0000000U   // Defines pin-muxing selection for GPIO143 //add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEGMUX2 register
//
//*************************************************************************************************
#define GPIO_GPEGMUX2_GPIO144_S   0U
#define GPIO_GPEGMUX2_GPIO144_M   0x3U          // Defines pin-muxing selection for GPIO144//add
#define GPIO_GPEGMUX2_GPIO145_S   2U
#define GPIO_GPEGMUX2_GPIO145_M   0xCU          // Defines pin-muxing selection for GPIO145
#define GPIO_GPEGMUX2_GPIO146_S   4U
#define GPIO_GPEGMUX2_GPIO146_M   0x30U         // Defines pin-muxing selection for GPIO146
#define GPIO_GPEGMUX2_GPIO147_S   6U
#define GPIO_GPEGMUX2_GPIO147_M   0xC0U         // Defines pin-muxing selection for GPIO147
#define GPIO_GPEGMUX2_GPIO148_S   8U
#define GPIO_GPEGMUX2_GPIO148_M   0x300U        // Defines pin-muxing selection for GPIO148
#define GPIO_GPEGMUX2_GPIO149_S   10U
#define GPIO_GPEGMUX2_GPIO149_M   0xC00U        // Defines pin-muxing selection for GPIO149
#define GPIO_GPEGMUX2_GPIO150_S   12U
#define GPIO_GPEGMUX2_GPIO150_M   0x3000U       // Defines pin-muxing selection for GPIO150
#define GPIO_GPEGMUX2_GPIO151_S   14U
#define GPIO_GPEGMUX2_GPIO151_M   0xC000U       // Defines pin-muxing selection for GPIO151
#define GPIO_GPEGMUX2_GPIO152_S   16U
#define GPIO_GPEGMUX2_GPIO152_M   0x30000U      // Defines pin-muxing selection for GPIO152
#define GPIO_GPEGMUX2_GPIO153_S   18U
#define GPIO_GPEGMUX2_GPIO153_M   0xC0000U      // Defines pin-muxing selection for GPIO153
#define GPIO_GPEGMUX2_GPIO154_S   20U
#define GPIO_GPEGMUX2_GPIO154_M   0x300000U     // Defines pin-muxing selection for GPIO154
#define GPIO_GPEGMUX2_GPIO155_S   22U
#define GPIO_GPEGMUX2_GPIO155_M   0xC00000U     // Defines pin-muxing selection for GPIO155
#define GPIO_GPEGMUX2_GPIO156_S   24U
#define GPIO_GPEGMUX2_GPIO156_M   0x3000000U    // Defines pin-muxing selection for GPIO156
#define GPIO_GPEGMUX2_GPIO157_S   26U
#define GPIO_GPEGMUX2_GPIO157_M   0xC000000U    // Defines pin-muxing selection for GPIO157
#define GPIO_GPEGMUX2_GPIO158_S   28U
#define GPIO_GPEGMUX2_GPIO158_M   0x30000000U   // Defines pin-muxing selection for GPIO158
#define GPIO_GPEGMUX2_GPIO159_S   30U
#define GPIO_GPEGMUX2_GPIO159_M   0xC0000000U   // Defines pin-muxing selection for GPIO159

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPECSEL1 register
//
//*************************************************************************************************
#define GPIO_GPECSEL1_GPIO128_S   0U
#define GPIO_GPECSEL1_GPIO128_M   0xFU         // GPIO128 Controller CPU Select
#define GPIO_GPECSEL1_GPIO129_S   4U
#define GPIO_GPECSEL1_GPIO129_M   0xF0U        // GPIO129 Controller CPU Select
#define GPIO_GPECSEL1_GPIO130_S   8U
#define GPIO_GPECSEL1_GPIO130_M   0xF00U       // GPIO130 Controller CPU Select
#define GPIO_GPECSEL1_GPIO131_S   12U
#define GPIO_GPECSEL1_GPIO131_M   0xF000U      // GPIO131 Controller CPU Select
#define GPIO_GPECSEL1_GPIO132_S   16U
#define GPIO_GPECSEL1_GPIO132_M   0xF0000U     // GPIO132 Controller CPU Select
#define GPIO_GPECSEL1_GPIO133_S   20U
#define GPIO_GPECSEL1_GPIO133_M   0xF00000U    // GPIO133 Controller CPU Select
#define GPIO_GPECSEL1_GPIO134_S   24U
#define GPIO_GPECSEL1_GPIO134_M   0xF000000U   // GPIO134 Controller CPU Select
#define GPIO_GPECSEL1_GPIO135_S   28U
#define GPIO_GPECSEL1_GPIO135_M   0xF0000000U  // GPIO135 Controller CPU Select //add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPECSEL2 register
//
//*************************************************************************************************
#define GPIO_GPECSEL2_GPIO136_S   0U
#define GPIO_GPECSEL2_GPIO136_M   0xFU        // GPIO136 Controller CPU Select//add
#define GPIO_GPECSEL2_GPIO137_S   4U
#define GPIO_GPECSEL2_GPIO137_M   0xF0U       // GPIO137 Controller CPU Select//add
#define GPIO_GPECSEL2_GPIO138_S   8U
#define GPIO_GPECSEL2_GPIO138_M   0xF00U       // GPIO138 Controller CPU Select//add
#define GPIO_GPECSEL2_GPIO139_S   12U
#define GPIO_GPECSEL2_GPIO139_M   0xF000U      // GPIO139 Controller CPU Select//add
#define GPIO_GPECSEL2_GPIO140_S   16U
#define GPIO_GPECSEL2_GPIO140_M   0xF0000U      // GPIO140 Controller CPU Select//add
#define GPIO_GPECSEL2_GPIO141_S   20U
#define GPIO_GPECSEL2_GPIO141_M   0xF00000U     // GPIO141 Controller CPU Select
#define GPIO_GPECSEL2_GPIO142_S   24U
#define GPIO_GPECSEL2_GPIO142_M   0xF000000U    // GPIO142 Controller CPU Select
#define GPIO_GPECSEL2_GPIO143_S   28U
#define GPIO_GPECSEL2_GPIO143_M   0xF0000000U   // GPIO143 Controller CPU Select//add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPECSEL3 register
//
//*************************************************************************************************
#define GPIO_GPECSEL3_GPIO144_S   0U
#define GPIO_GPECSEL3_GPIO144_M   0xF0U         // GPIO145 Controller CPU Select //add
#define GPIO_GPECSEL3_GPIO145_S   4U
#define GPIO_GPECSEL3_GPIO145_M   0xF0U         // GPIO145 Controller CPU Select
#define GPIO_GPECSEL3_GPIO146_S   8U
#define GPIO_GPECSEL3_GPIO146_M   0xF00U        // GPIO146 Controller CPU Select
#define GPIO_GPECSEL3_GPIO147_S   12U
#define GPIO_GPECSEL3_GPIO147_M   0xF000U       // GPIO147 Controller CPU Select
#define GPIO_GPECSEL3_GPIO148_S   16U
#define GPIO_GPECSEL3_GPIO148_M   0xF0000U      // GPIO148 Controller CPU Select
#define GPIO_GPECSEL3_GPIO149_S   20U
#define GPIO_GPECSEL3_GPIO149_M   0xF00000U     // GPIO149 Controller CPU Select
#define GPIO_GPECSEL3_GPIO150_S   24U
#define GPIO_GPECSEL3_GPIO150_M   0xF000000U    // GPIO150 Controller CPU Select
#define GPIO_GPECSEL3_GPIO151_S   28U
#define GPIO_GPECSEL3_GPIO151_M   0xF0000000U   // GPIO151 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPECSEL4 register
//
//*************************************************************************************************
#define GPIO_GPECSEL4_GPIO152_S   0U
#define GPIO_GPECSEL4_GPIO152_M   0xFU          // GPIO152 Controller CPU Select
#define GPIO_GPECSEL4_GPIO153_S   4U
#define GPIO_GPECSEL4_GPIO153_M   0xF0U         // GPIO153 Controller CPU Select
#define GPIO_GPECSEL4_GPIO154_S   8U
#define GPIO_GPECSEL4_GPIO154_M   0xF00U        // GPIO154 Controller CPU Select
#define GPIO_GPECSEL4_GPIO155_S   12U
#define GPIO_GPECSEL4_GPIO155_M   0xF000U       // GPIO155 Controller CPU Select
#define GPIO_GPECSEL4_GPIO156_S   16U
#define GPIO_GPECSEL4_GPIO156_M   0xF0000U      // GPIO156 Controller CPU Select
#define GPIO_GPECSEL4_GPIO157_S   20U
#define GPIO_GPECSEL4_GPIO157_M   0xF00000U     // GPIO157 Controller CPU Select
#define GPIO_GPECSEL4_GPIO158_S   24U
#define GPIO_GPECSEL4_GPIO158_M   0xF000000U    // GPIO158 Controller CPU Select
#define GPIO_GPECSEL4_GPIO159_S   28U
#define GPIO_GPECSEL4_GPIO159_M   0xF0000000U   // GPIO159 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPELOCK register
//
//*************************************************************************************************
#define GPIO_GPELOCK_GPIO128   0x1U          // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO129   0x2U          // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO130   0x4U          // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO131   0x8U          // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO132   0x10U         // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO133   0x20U         // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO134   0x40U         // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO135   0x80U         // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO136   0x100U        // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO137   0x200U        // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO138   0x400U        // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO139   0x800U        // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO140   0x1000U       // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO141   0x2000U       // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO142   0x4000U       // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO143   0x8000U       // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO144   0x10000U       // Configuration Lock bit for this pin//add
#define GPIO_GPELOCK_GPIO145   0x20000U      // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO146   0x40000U      // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO147   0x80000U      // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO148   0x100000U     // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO149   0x200000U     // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO150   0x400000U     // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO151   0x800000U     // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO152   0x1000000U    // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO153   0x2000000U    // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO154   0x4000000U    // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO155   0x8000000U    // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO156   0x10000000U   // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO157   0x20000000U   // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO158   0x40000000U   // Configuration Lock bit for this pin
#define GPIO_GPELOCK_GPIO159   0x80000000U   // Configuration Lock bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPECR register
//
//*************************************************************************************************
#define GPIO_GPECR_GPIO128   0x1U          // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO129   0x2U          // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO130   0x4U          // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO131   0x8U          // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO132   0x10U         // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO133   0x20U         // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO134   0x40U         // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO135   0x80U         // Configuration lock commit bit for this pin //add
#define GPIO_GPECR_GPIO136   0x100U        // Configuration lock commit bit for this pin //add
#define GPIO_GPECR_GPIO137   0x200U        // Configuration lock commit bit for this pin //add
#define GPIO_GPECR_GPIO138   0x400U        // Configuration lock commit bit for this pin //add
#define GPIO_GPECR_GPIO139   0x800U        // Configuration lock commit bit for this pin //add
#define GPIO_GPECR_GPIO140   0x1000U       // Configuration lock commit bit for this pin //add
#define GPIO_GPECR_GPIO141   0x2000U       // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO142   0x4000U       // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO143   0x8000U       // Configuration lock commit bit for this pin//add
#define GPIO_GPECR_GPIO144   0x10000U      // Configuration lock commit bit for this pin//add
#define GPIO_GPECR_GPIO145   0x20000U      // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO146   0x40000U      // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO147   0x80000U      // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO148   0x100000U     // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO149   0x200000U     // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO150   0x400000U     // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO151   0x800000U     // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO152   0x1000000U    // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO153   0x2000000U    // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO154   0x4000000U    // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO155   0x8000000U    // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO156   0x10000000U   // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO157   0x20000000U   // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO158   0x40000000U   // Configuration lock commit bit for this pin
#define GPIO_GPECR_GPIO159   0x80000000U   // Configuration lock commit bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFCTRL register
//
//*************************************************************************************************
#define GPIO_GPFCTRL_QUALPRD0_S   0U
#define GPIO_GPFCTRL_QUALPRD0_M   0xFFU     // Qualification sampling period for GPIO160 to GPIO167
#define GPIO_GPFCTRL_QUALPRD1_S   8U
#define GPIO_GPFCTRL_QUALPRD1_M   0xFF00U   // Qualification sampling period for GPIO168 to GPIO175
#define GPIO_GPFCTRL_QUALPRD2_S   16U
#define GPIO_GPFCTRL_QUALPRD2_M   0xFF0000U   // Qualification sampling period for GPIO176 to GPIO181 //add

// add GPIO169~181
//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFQSEL1 register
//
//*************************************************************************************************
#define GPIO_GPFQSEL1_GPIO160_S   0U
#define GPIO_GPFQSEL1_GPIO160_M   0x3U       // Select input qualification type for GPIO160
#define GPIO_GPFQSEL1_GPIO161_S   2U
#define GPIO_GPFQSEL1_GPIO161_M   0xCU       // Select input qualification type for GPIO161
#define GPIO_GPFQSEL1_GPIO162_S   4U
#define GPIO_GPFQSEL1_GPIO162_M   0x30U      // Select input qualification type for GPIO162
#define GPIO_GPFQSEL1_GPIO163_S   6U
#define GPIO_GPFQSEL1_GPIO163_M   0xC0U      // Select input qualification type for GPIO163
#define GPIO_GPFQSEL1_GPIO164_S   8U
#define GPIO_GPFQSEL1_GPIO164_M   0x300U     // Select input qualification type for GPIO164
#define GPIO_GPFQSEL1_GPIO165_S   10U
#define GPIO_GPFQSEL1_GPIO165_M   0xC00U     // Select input qualification type for GPIO165
#define GPIO_GPFQSEL1_GPIO166_S   12U
#define GPIO_GPFQSEL1_GPIO166_M   0x3000U    // Select input qualification type for GPIO166
#define GPIO_GPFQSEL1_GPIO167_S   14U
#define GPIO_GPFQSEL1_GPIO167_M   0xC000U    // Select input qualification type for GPIO167
#define GPIO_GPFQSEL1_GPIO168_S   16U
#define GPIO_GPFQSEL1_GPIO168_M   0x30000U   // Select input qualification type for GPIO168
#define GPIO_GPFQSEL1_GPIO169_S   18U
#define GPIO_GPFQSEL1_GPIO169_M   0xC0000U   // Select input qualification type for GPIO169
#define GPIO_GPFQSEL1_GPIO170_S   20U
#define GPIO_GPFQSEL1_GPIO170_M   0x300000U   // Select input qualification type for GPIO170
#define GPIO_GPFQSEL1_GPIO171_S   22U
#define GPIO_GPFQSEL1_GPIO171_M   0xC00000U   // Select input qualification type for GPIO171
#define GPIO_GPFQSEL1_GPIO172_S   24U
#define GPIO_GPFQSEL1_GPIO172_M   0x3000000U   // Select input qualification type for GPIO172
#define GPIO_GPFQSEL1_GPIO173_S   26U
#define GPIO_GPFQSEL1_GPIO173_M   0xC000000U   // Select input qualification type for GPIO173
#define GPIO_GPFQSEL1_GPIO174_S   28U
#define GPIO_GPFQSEL1_GPIO174_M   0x30000000U   // Select input qualification type for GPIO174
#define GPIO_GPFQSEL1_GPIO175_S   30U
#define GPIO_GPFQSEL1_GPIO175_M   0xC0000000U   // Select input qualification type for GPIO175

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFQSEL2 register
//
//*************************************************************************************************
#define GPIO_GPFQSEL2_GPIO176_S   0U
#define GPIO_GPFQSEL2_GPIO176_M   0x3U       // Select input qualification type for GPIO176
#define GPIO_GPFQSEL2_GPIO177_S   2U
#define GPIO_GPFQSEL2_GPIO177_M   0xCU       // Select input qualification type for GPIO177
#define GPIO_GPFQSEL2_GPIO178_S   4U
#define GPIO_GPFQSEL2_GPIO178_M   0x30U      // Select input qualification type for GPIO178
#define GPIO_GPFQSEL2_GPIO179_S   6U
#define GPIO_GPFQSEL2_GPIO179_M   0xC0U      // Select input qualification type for GPIO179
#define GPIO_GPFQSEL2_GPIO180_S   8U
#define GPIO_GPFQSEL2_GPIO180_M   0x300U     // Select input qualification type for GPIO180
#define GPIO_GPFQSEL2_GPIO181_S   10U
#define GPIO_GPFQSEL2_GPIO181_M   0xC00U     // Select input qualification type for GPIO181

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFMUX1 register
//
//*************************************************************************************************
#define GPIO_GPFMUX1_GPIO160_S   0U
#define GPIO_GPFMUX1_GPIO160_M   0x3U       // Defines pin-muxing selection for GPIO160
#define GPIO_GPFMUX1_GPIO161_S   2U
#define GPIO_GPFMUX1_GPIO161_M   0xCU       // Defines pin-muxing selection for GPIO161
#define GPIO_GPFMUX1_GPIO162_S   4U
#define GPIO_GPFMUX1_GPIO162_M   0x30U      // Defines pin-muxing selection for GPIO162
#define GPIO_GPFMUX1_GPIO163_S   6U
#define GPIO_GPFMUX1_GPIO163_M   0xC0U      // Defines pin-muxing selection for GPIO163
#define GPIO_GPFMUX1_GPIO164_S   8U
#define GPIO_GPFMUX1_GPIO164_M   0x300U     // Defines pin-muxing selection for GPIO164
#define GPIO_GPFMUX1_GPIO165_S   10U
#define GPIO_GPFMUX1_GPIO165_M   0xC00U     // Defines pin-muxing selection for GPIO165
#define GPIO_GPFMUX1_GPIO166_S   12U
#define GPIO_GPFMUX1_GPIO166_M   0x3000U    // Defines pin-muxing selection for GPIO166
#define GPIO_GPFMUX1_GPIO167_S   14U
#define GPIO_GPFMUX1_GPIO167_M   0xC000U    // Defines pin-muxing selection for GPIO167
#define GPIO_GPFMUX1_GPIO168_S   16U
#define GPIO_GPFMUX1_GPIO168_M   0x30000U   // Defines pin-muxing selection for GPIO168
#define GPIO_GPFMUX1_GPIO169_S   18U
#define GPIO_GPFMUX1_GPIO169_M   0xC0000U       // Defines pin-muxing selection for GPIO169
#define GPIO_GPFMUX1_GPIO170_S   20U
#define GPIO_GPFMUX1_GPIO170_M   0x300000U       // Defines pin-muxing selection for GPIO170
#define GPIO_GPFMUX1_GPIO171_S   22U
#define GPIO_GPFMUX1_GPIO171_M   0xC00000U      // Defines pin-muxing selection for GPIO171
#define GPIO_GPFMUX1_GPIO172_S   24U
#define GPIO_GPFMUX1_GPIO172_M   0x3000000U      // Defines pin-muxing selection for GPIO172
#define GPIO_GPFMUX1_GPIO173_S   26U
#define GPIO_GPFMUX1_GPIO173_M   0xC000000U     // Defines pin-muxing selection for GPIO173
#define GPIO_GPFMUX1_GPIO174_S   28U
#define GPIO_GPFMUX1_GPIO174_M   0x30000000U     // Defines pin-muxing selection for GPIO174
#define GPIO_GPFMUX1_GPIO175_S   30U
#define GPIO_GPFMUX1_GPIO175_M   0xC0000000U    // Defines pin-muxing selection for GPIO175

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFMUX2 register
//
//*************************************************************************************************
#define GPIO_GPFMUX2_GPIO176_S   0U
#define GPIO_GPFMUX2_GPIO176_M   0x3U       // Defines pin-muxing selection for GPIO176
#define GPIO_GPFMUX2_GPIO177_S   2U
#define GPIO_GPFMUX2_GPIO177_M   0xCU       // Defines pin-muxing selection for GPIO177
#define GPIO_GPFMUX2_GPIO178_S   4U
#define GPIO_GPFMUX2_GPIO178_M   0x30U      // Defines pin-muxing selection for GPIO178
#define GPIO_GPFMUX2_GPIO179_S   6U
#define GPIO_GPFMUX2_GPIO179_M   0xC0U      // Defines pin-muxing selection for GPIO179
#define GPIO_GPFMUX2_GPIO180_S   8U
#define GPIO_GPFMUX2_GPIO180_M   0x300U     // Defines pin-muxing selection for GPIO180
#define GPIO_GPFMUX2_GPIO181_S   10U
#define GPIO_GPFMUX2_GPIO181_M   0xC00U     // Defines pin-muxing selection for GPIO181

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFDIR register
//
//*************************************************************************************************
#define GPIO_GPFDIR_GPIO160   0x1U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO161   0x2U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO162   0x4U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO163   0x8U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO164   0x10U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO165   0x20U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO166   0x40U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO167   0x80U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO168   0x100U   // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO169   0x200U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO170   0x400U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO171   0x800U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO172   0x1000U     // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO173   0x2000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO174   0x4000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO175   0x8000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO176   0x10000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO177   0x20000U   // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO178   0x40000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO179   0x80000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO180   0x100000U    // Defines direction for this pin in GPIO mode
#define GPIO_GPFDIR_GPIO181   0x200000U   // Defines direction for this pin in GPIO mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFPUD register
//
//*************************************************************************************************
#define GPIO_GPFPUD_GPIO160   0x1U     // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO161   0x2U     // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO162   0x4U     // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO163   0x8U     // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO164   0x10U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO165   0x20U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO166   0x40U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO167   0x80U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO168   0x100U   // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO169   0x200U     // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO170   0x400U     // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO171   0x800U     // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO172   0x1000U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO173   0x2000U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO174   0x4000U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO175   0x8000U    // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO176   0x10000U   // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO177   0x20000U   // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO178   0x40000U   // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO179   0x80000U   // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO180   0x100000U  // Pull-Up Disable control for this pin
#define GPIO_GPFPUD_GPIO181   0x200000U  // Pull-Up Disable control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFINV register
//
//*************************************************************************************************
#define GPIO_GPFINV_GPIO160   0x1U     // Input inversion control for this pin
#define GPIO_GPFINV_GPIO161   0x2U     // Input inversion control for this pin
#define GPIO_GPFINV_GPIO162   0x4U     // Input inversion control for this pin
#define GPIO_GPFINV_GPIO163   0x8U     // Input inversion control for this pin
#define GPIO_GPFINV_GPIO164   0x10U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO165   0x20U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO166   0x40U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO167   0x80U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO168   0x100U   // Input inversion control for this pin
#define GPIO_GPFINV_GPIO169   0x200U     // Input inversion control for this pin
#define GPIO_GPFINV_GPIO170   0x400U     // Input inversion control for this pin
#define GPIO_GPFINV_GPIO171   0x800U     // Input inversion control for this pin
#define GPIO_GPFINV_GPIO172   0x1000U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO173   0x2000U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO174   0x4000U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO175   0x8000U    // Input inversion control for this pin
#define GPIO_GPFINV_GPIO176   0x10000U   // Input inversion control for this pin
#define GPIO_GPFINV_GPIO177   0x20000U   // Input inversion control for this pin
#define GPIO_GPFINV_GPIO178   0x40000U   // Input inversion control for this pin
#define GPIO_GPFINV_GPIO179   0x80000U   // Input inversion control for this pin
#define GPIO_GPFINV_GPIO180   0x100000U  // Input inversion control for this pin
#define GPIO_GPFINV_GPIO181   0x200000U  // Input inversion control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFODR register
//
//*************************************************************************************************
#define GPIO_GPFODR_GPIO160   0x1U     // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO161   0x2U     // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO162   0x4U     // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO163   0x8U     // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO164   0x10U    // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO165   0x20U    // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO166   0x40U    // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO167   0x80U    // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO168   0x100U   // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO169   0x200U    // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO170   0x400U    // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO171   0x800U    // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO172   0x1000U   // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO173   0x2000U   // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO174   0x4000U   // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO175   0x8000U   // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO176   0x10000U  // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO177   0x20000U  // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO178   0x40000U  // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO179   0x80000U  // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO180   0x100000U // Output Open-Drain control for this pin
#define GPIO_GPFODR_GPIO181   0x200000U // Output Open-Drain control for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFGMUX1 register
//
//*************************************************************************************************
#define GPIO_GPFGMUX1_GPIO160_S   0U
#define GPIO_GPFGMUX1_GPIO160_M   0x3U       // Defines pin-muxing selection for GPIO160
#define GPIO_GPFGMUX1_GPIO161_S   2U
#define GPIO_GPFGMUX1_GPIO161_M   0xCU       // Defines pin-muxing selection for GPIO161
#define GPIO_GPFGMUX1_GPIO162_S   4U
#define GPIO_GPFGMUX1_GPIO162_M   0x30U      // Defines pin-muxing selection for GPIO162
#define GPIO_GPFGMUX1_GPIO163_S   6U
#define GPIO_GPFGMUX1_GPIO163_M   0xC0U      // Defines pin-muxing selection for GPIO163
#define GPIO_GPFGMUX1_GPIO164_S   8U
#define GPIO_GPFGMUX1_GPIO164_M   0x300U     // Defines pin-muxing selection for GPIO164
#define GPIO_GPFGMUX1_GPIO165_S   10U
#define GPIO_GPFGMUX1_GPIO165_M   0xC00U     // Defines pin-muxing selection for GPIO165
#define GPIO_GPFGMUX1_GPIO166_S   12U
#define GPIO_GPFGMUX1_GPIO166_M   0x3000U    // Defines pin-muxing selection for GPIO166
#define GPIO_GPFGMUX1_GPIO167_S   14U
#define GPIO_GPFGMUX1_GPIO167_M   0xC000U    // Defines pin-muxing selection for GPIO167
#define GPIO_GPFGMUX1_GPIO168_S   16U
#define GPIO_GPFGMUX1_GPIO168_M   0x30000U   // Defines pin-muxing selection for GPIO168
#define GPIO_GPFGMUX1_GPIO169_S   18U
#define GPIO_GPFGMUX1_GPIO169_M   0xC0000U       // Defines pin-muxing selection for GPIO169
#define GPIO_GPFGMUX1_GPIO170_S   20U
#define GPIO_GPFGMUX1_GPIO170_M   0x300000U       // Defines pin-muxing selection for GPIO170
#define GPIO_GPFGMUX1_GPIO171_S   22U
#define GPIO_GPFGMUX1_GPIO171_M   0xC00000U      // Defines pin-muxing selection for GPIO171
#define GPIO_GPFGMUX1_GPIO172_S   24U
#define GPIO_GPFGMUX1_GPIO172_M   0x3000000U      // Defines pin-muxing selection for GPIO172
#define GPIO_GPFGMUX1_GPIO173_S   26U
#define GPIO_GPFGMUX1_GPIO173_M   0xC000000U     // Defines pin-muxing selection for GPIO173
#define GPIO_GPFGMUX1_GPIO174_S   28U
#define GPIO_GPFGMUX1_GPIO174_M   0x30000000U     // Defines pin-muxing selection for GPIO174
#define GPIO_GPFGMUX1_GPIO175_S   30U
#define GPIO_GPFGMUX1_GPIO175_M   0xC0000000U    // Defines pin-muxing selection for GPIO175

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFGMUX2 register
//
//*************************************************************************************************
#define GPIO_GPFGMUX2_GPIO176_S   0U
#define GPIO_GPFGMUX2_GPIO176_M   0x3U       // Defines pin-muxing selection for GPIO176
#define GPIO_GPFGMUX2_GPIO177_S   2U
#define GPIO_GPFGMUX2_GPIO177_M   0xCU       // Defines pin-muxing selection for GPIO177
#define GPIO_GPFGMUX2_GPIO178_S   4U
#define GPIO_GPFGMUX2_GPIO178_M   0x30U      // Defines pin-muxing selection for GPIO178
#define GPIO_GPFGMUX2_GPIO179_S   6U
#define GPIO_GPFGMUX2_GPIO179_M   0xC0U      // Defines pin-muxing selection for GPIO179
#define GPIO_GPFGMUX2_GPIO180_S   8U
#define GPIO_GPFGMUX2_GPIO180_M   0x300U     // Defines pin-muxing selection for GPIO180
#define GPIO_GPFGMUX2_GPIO181_S   10U
#define GPIO_GPFGMUX2_GPIO181_M   0xC00U     // Defines pin-muxing selection for GPIO181

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFCSEL1 register
//
//*************************************************************************************************
#define GPIO_GPFCSEL1_GPIO160_S   0U
#define GPIO_GPFCSEL1_GPIO160_M   0xFU          // GPIO160 Controller CPU Select
#define GPIO_GPFCSEL1_GPIO161_S   4U
#define GPIO_GPFCSEL1_GPIO161_M   0xF0U         // GPIO161 Controller CPU Select
#define GPIO_GPFCSEL1_GPIO162_S   8U
#define GPIO_GPFCSEL1_GPIO162_M   0xF00U        // GPIO162 Controller CPU Select
#define GPIO_GPFCSEL1_GPIO163_S   12U
#define GPIO_GPFCSEL1_GPIO163_M   0xF000U       // GPIO163 Controller CPU Select
#define GPIO_GPFCSEL1_GPIO164_S   16U
#define GPIO_GPFCSEL1_GPIO164_M   0xF0000U      // GPIO164 Controller CPU Select
#define GPIO_GPFCSEL1_GPIO165_S   20U
#define GPIO_GPFCSEL1_GPIO165_M   0xF00000U     // GPIO165 Controller CPU Select
#define GPIO_GPFCSEL1_GPIO166_S   24U
#define GPIO_GPFCSEL1_GPIO166_M   0xF000000U    // GPIO166 Controller CPU Select
#define GPIO_GPFCSEL1_GPIO167_S   28U
#define GPIO_GPFCSEL1_GPIO167_M   0xF0000000U   // GPIO167 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFCSEL2 register
//
//*************************************************************************************************
#define GPIO_GPFCSEL2_GPIO168_S   0U
#define GPIO_GPFCSEL2_GPIO168_M   0xFU        // GPIO168 Controller CPU Select
#define GPIO_GPFCSEL2_GPIO169_S   4U
#define GPIO_GPFCSEL2_GPIO169_M   0xF0U       // GPIO169 Controller CPU Select
#define GPIO_GPFCSEL2_GPIO170_S   8U
#define GPIO_GPFCSEL2_GPIO170_M   0xF00U      // GPIO170 Controller CPU Select
#define GPIO_GPFCSEL2_GPIO171_S   12U
#define GPIO_GPFCSEL2_GPIO171_M   0xF000U     // GPIO171 Controller CPU Select
#define GPIO_GPFCSEL2_GPIO172_S   16U
#define GPIO_GPFCSEL2_GPIO172_M   0xF0000U    // GPIO172 Controller CPU Select
#define GPIO_GPFCSEL2_GPIO173_S   20U
#define GPIO_GPFCSEL2_GPIO173_M   0xF00000U   // GPIO173 Controller CPU Select
#define GPIO_GPFCSEL2_GPIO174_S   24U
#define GPIO_GPFCSEL2_GPIO174_M   0xF000000U  // GPIO174 Controller CPU Select
#define GPIO_GPFCSEL2_GPIO175_S   28U
#define GPIO_GPFCSEL2_GPIO175_M   0xF0000000U // GPIO175 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFCSEL3 register
//
//*************************************************************************************************
#define GPIO_GPFCSEL3_GPIO176_S   0U
#define GPIO_GPFCSEL3_GPIO176_M   0xFU        // GPIO176 Controller CPU Select
#define GPIO_GPFCSEL3_GPIO177_S   4U
#define GPIO_GPFCSEL3_GPIO177_M   0xF0U       // GPIO177 Controller CPU Select
#define GPIO_GPFCSEL3_GPIO178_S   8U
#define GPIO_GPFCSEL3_GPIO178_M   0xF00U      // GPIO178 Controller CPU Select
#define GPIO_GPFCSEL3_GPIO179_S   12U
#define GPIO_GPFCSEL3_GPIO179_M   0xF000U     // GPIO179 Controller CPU Select
#define GPIO_GPFCSEL3_GPIO180_S   16U
#define GPIO_GPFCSEL3_GPIO180_M   0xF0000U    // GPIO180 Controller CPU Select
#define GPIO_GPFCSEL3_GPIO181_S   20U
#define GPIO_GPFCSEL3_GPIO181_M   0xF00000U   // GPIO181 Controller CPU Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFLOCK register
//
//*************************************************************************************************
#define GPIO_GPFLOCK_GPIO160   0x1U     // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO161   0x2U     // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO162   0x4U     // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO163   0x8U     // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO164   0x10U    // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO165   0x20U    // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO166   0x40U    // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO167   0x80U    // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO168   0x100U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO169   0x200U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO170   0x400U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO171   0x800U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO172   0x1000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO173   0x2000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO174   0x4000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO175   0x8000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO176   0x10000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO177   0x20000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO178   0x40000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO179   0x80000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO180   0x100000U   // Configuration Lock bit for this pin
#define GPIO_GPFLOCK_GPIO181   0x200000U   // Configuration Lock bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFCR register
//
//*************************************************************************************************
#define GPIO_GPFCR_GPIO160   0x1U     // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO161   0x2U     // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO162   0x4U     // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO163   0x8U     // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO164   0x10U    // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO165   0x20U    // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO166   0x40U    // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO167   0x80U    // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO168   0x100U   // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO169   0x200U    // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO170   0x400U    // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO171   0x800U    // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO172   0x1000U   // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO173   0x2000U   // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO174   0x4000U   // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO175   0x8000U   // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO176   0x10000U  // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO177   0x20000U  // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO178   0x40000U  // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO179   0x80000U  // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO180   0x100000U // Configuration lock commit bit for this pin
#define GPIO_GPFCR_GPIO181   0x200000U // Configuration lock commit bit for this pin


//*************************************************************************************************
//
// The following are defines for the bit fields in the GPADAT register
//
//*************************************************************************************************
#define GPIO_GPADAT_GPIO0    0x1U          // Data Register for this pin
#define GPIO_GPADAT_GPIO1    0x2U          // Data Register for this pin
#define GPIO_GPADAT_GPIO2    0x4U          // Data Register for this pin
#define GPIO_GPADAT_GPIO3    0x8U          // Data Register for this pin
#define GPIO_GPADAT_GPIO4    0x10U         // Data Register for this pin
#define GPIO_GPADAT_GPIO5    0x20U         // Data Register for this pin
#define GPIO_GPADAT_GPIO6    0x40U         // Data Register for this pin
#define GPIO_GPADAT_GPIO7    0x80U         // Data Register for this pin
#define GPIO_GPADAT_GPIO8    0x100U        // Data Register for this pin
#define GPIO_GPADAT_GPIO9    0x200U        // Data Register for this pin
#define GPIO_GPADAT_GPIO10   0x400U        // Data Register for this pin
#define GPIO_GPADAT_GPIO11   0x800U        // Data Register for this pin
#define GPIO_GPADAT_GPIO12   0x1000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO13   0x2000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO14   0x4000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO15   0x8000U       // Data Register for this pin
#define GPIO_GPADAT_GPIO16   0x10000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO17   0x20000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO18   0x40000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO19   0x80000U      // Data Register for this pin
#define GPIO_GPADAT_GPIO20   0x100000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO21   0x200000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO22   0x400000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO23   0x800000U     // Data Register for this pin
#define GPIO_GPADAT_GPIO24   0x1000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO25   0x2000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO26   0x4000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO27   0x8000000U    // Data Register for this pin
#define GPIO_GPADAT_GPIO28   0x10000000U   // Data Register for this pin
#define GPIO_GPADAT_GPIO29   0x20000000U   // Data Register for this pin
#define GPIO_GPADAT_GPIO30   0x40000000U   // Data Register for this pin
#define GPIO_GPADAT_GPIO31   0x80000000U   // Data Register for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPASET register
//
//*************************************************************************************************
#define GPIO_GPASET_GPIO0    0x1U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO1    0x2U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO2    0x4U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO3    0x8U          // Output Set bit for this pin
#define GPIO_GPASET_GPIO4    0x10U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO5    0x20U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO6    0x40U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO7    0x80U         // Output Set bit for this pin
#define GPIO_GPASET_GPIO8    0x100U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO9    0x200U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO10   0x400U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO11   0x800U        // Output Set bit for this pin
#define GPIO_GPASET_GPIO12   0x1000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO13   0x2000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO14   0x4000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO15   0x8000U       // Output Set bit for this pin
#define GPIO_GPASET_GPIO16   0x10000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO17   0x20000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO18   0x40000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO19   0x80000U      // Output Set bit for this pin
#define GPIO_GPASET_GPIO20   0x100000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO21   0x200000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO22   0x400000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO23   0x800000U     // Output Set bit for this pin
#define GPIO_GPASET_GPIO24   0x1000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO25   0x2000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO26   0x4000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO27   0x8000000U    // Output Set bit for this pin
#define GPIO_GPASET_GPIO28   0x10000000U   // Output Set bit for this pin
#define GPIO_GPASET_GPIO29   0x20000000U   // Output Set bit for this pin
#define GPIO_GPASET_GPIO30   0x40000000U   // Output Set bit for this pin
#define GPIO_GPASET_GPIO31   0x80000000U   // Output Set bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPACLEAR register
//
//*************************************************************************************************
#define GPIO_GPACLEAR_GPIO0    0x1U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO1    0x2U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO2    0x4U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO3    0x8U          // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO4    0x10U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO5    0x20U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO6    0x40U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO7    0x80U         // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO8    0x100U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO9    0x200U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO10   0x400U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO11   0x800U        // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO12   0x1000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO13   0x2000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO14   0x4000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO15   0x8000U       // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO16   0x10000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO17   0x20000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO18   0x40000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO19   0x80000U      // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO20   0x100000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO21   0x200000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO22   0x400000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO23   0x800000U     // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO24   0x1000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO25   0x2000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO26   0x4000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO27   0x8000000U    // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO28   0x10000000U   // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO29   0x20000000U   // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO30   0x40000000U   // Output Clear bit for this pin
#define GPIO_GPACLEAR_GPIO31   0x80000000U   // Output Clear bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPATOGGLE register
//
//*************************************************************************************************
#define GPIO_GPATOGGLE_GPIO0    0x1U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO1    0x2U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO2    0x4U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO3    0x8U          // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO4    0x10U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO5    0x20U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO6    0x40U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO7    0x80U         // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO8    0x100U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO9    0x200U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO10   0x400U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO11   0x800U        // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO12   0x1000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO13   0x2000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO14   0x4000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO15   0x8000U       // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO16   0x10000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO17   0x20000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO18   0x40000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO19   0x80000U      // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO20   0x100000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO21   0x200000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO22   0x400000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO23   0x800000U     // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO24   0x1000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO25   0x2000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO26   0x4000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO27   0x8000000U    // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO28   0x10000000U   // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO29   0x20000000U   // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO30   0x40000000U   // Output Toggle bit for this pin
#define GPIO_GPATOGGLE_GPIO31   0x80000000U   // Output Toggle bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBDAT register
//
//*************************************************************************************************
#define GPIO_GPBDAT_GPIO32   0x1U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO33   0x2U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO34   0x4U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO35   0x8U          // Data Register for this pin
#define GPIO_GPBDAT_GPIO36   0x10U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO37   0x20U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO38   0x40U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO39   0x80U         // Data Register for this pin
#define GPIO_GPBDAT_GPIO40   0x100U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO41   0x200U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO42   0x400U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO43   0x800U        // Data Register for this pin
#define GPIO_GPBDAT_GPIO44   0x1000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO45   0x2000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO46   0x4000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO47   0x8000U       // Data Register for this pin
#define GPIO_GPBDAT_GPIO48   0x10000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO49   0x20000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO50   0x40000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO51   0x80000U      // Data Register for this pin
#define GPIO_GPBDAT_GPIO52   0x100000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO53   0x200000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO54   0x400000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO55   0x800000U     // Data Register for this pin
#define GPIO_GPBDAT_GPIO56   0x1000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO57   0x2000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO58   0x4000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO59   0x8000000U    // Data Register for this pin
#define GPIO_GPBDAT_GPIO60   0x10000000U   // Data Register for this pin
#define GPIO_GPBDAT_GPIO61   0x20000000U   // Data Register for this pin
#define GPIO_GPBDAT_GPIO62   0x40000000U   // Data Register for this pin
#define GPIO_GPBDAT_GPIO63   0x80000000U   // Data Register for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBSET register
//
//*************************************************************************************************
#define GPIO_GPBSET_GPIO32   0x1U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO33   0x2U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO34   0x4U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO35   0x8U          // Output Set bit for this pin
#define GPIO_GPBSET_GPIO36   0x10U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO37   0x20U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO38   0x40U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO39   0x80U         // Output Set bit for this pin
#define GPIO_GPBSET_GPIO40   0x100U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO41   0x200U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO42   0x400U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO43   0x800U        // Output Set bit for this pin
#define GPIO_GPBSET_GPIO44   0x1000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO45   0x2000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO46   0x4000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO47   0x8000U       // Output Set bit for this pin
#define GPIO_GPBSET_GPIO48   0x10000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO49   0x20000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO50   0x40000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO51   0x80000U      // Output Set bit for this pin
#define GPIO_GPBSET_GPIO52   0x100000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO53   0x200000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO54   0x400000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO55   0x800000U     // Output Set bit for this pin
#define GPIO_GPBSET_GPIO56   0x1000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO57   0x2000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO58   0x4000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO59   0x8000000U    // Output Set bit for this pin
#define GPIO_GPBSET_GPIO60   0x10000000U   // Output Set bit for this pin
#define GPIO_GPBSET_GPIO61   0x20000000U   // Output Set bit for this pin
#define GPIO_GPBSET_GPIO62   0x40000000U   // Output Set bit for this pin
#define GPIO_GPBSET_GPIO63   0x80000000U   // Output Set bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBCLEAR register
//
//*************************************************************************************************
#define GPIO_GPBCLEAR_GPIO32   0x1U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO33   0x2U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO34   0x4U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO35   0x8U          // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO36   0x10U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO37   0x20U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO38   0x40U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO39   0x80U         // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO40   0x100U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO41   0x200U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO42   0x400U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO43   0x800U        // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO44   0x1000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO45   0x2000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO46   0x4000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO47   0x8000U       // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO48   0x10000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO49   0x20000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO50   0x40000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO51   0x80000U      // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO52   0x100000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO53   0x200000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO54   0x400000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO55   0x800000U     // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO56   0x1000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO57   0x2000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO58   0x4000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO59   0x8000000U    // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO60   0x10000000U   // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO61   0x20000000U   // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO62   0x40000000U   // Output Clear bit for this pin
#define GPIO_GPBCLEAR_GPIO63   0x80000000U   // Output Clear bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPBTOGGLE register
//
//*************************************************************************************************
#define GPIO_GPBTOGGLE_GPIO32   0x1U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO33   0x2U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO34   0x4U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO35   0x8U          // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO36   0x10U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO37   0x20U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO38   0x40U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO39   0x80U         // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO40   0x100U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO41   0x200U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO42   0x400U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO43   0x800U        // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO44   0x1000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO45   0x2000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO46   0x4000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO47   0x8000U       // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO48   0x10000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO49   0x20000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO50   0x40000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO51   0x80000U      // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO52   0x100000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO53   0x200000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO54   0x400000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO55   0x800000U     // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO56   0x1000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO57   0x2000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO58   0x4000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO59   0x8000000U    // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO60   0x10000000U   // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO61   0x20000000U   // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO62   0x40000000U   // Output Toggle bit for this pin
#define GPIO_GPBTOGGLE_GPIO63   0x80000000U   // Output Toggle bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCDAT register
//
//*************************************************************************************************
#define GPIO_GPCDAT_GPIO64   0x1U          // Data Register for this pin
#define GPIO_GPCDAT_GPIO65   0x2U          // Data Register for this pin
#define GPIO_GPCDAT_GPIO66   0x4U          // Data Register for this pin
#define GPIO_GPCDAT_GPIO67   0x8U          // Data Register for this pin
#define GPIO_GPCDAT_GPIO68   0x10U         // Data Register for this pin
#define GPIO_GPCDAT_GPIO69   0x20U         // Data Register for this pin
#define GPIO_GPCDAT_GPIO70   0x40U         // Data Register for this pin
#define GPIO_GPCDAT_GPIO71   0x80U         // Data Register for this pin
#define GPIO_GPCDAT_GPIO72   0x100U        // Data Register for this pin
#define GPIO_GPCDAT_GPIO73   0x200U        // Data Register for this pin
#define GPIO_GPCDAT_GPIO74   0x400U        // Data Register for this pin
#define GPIO_GPCDAT_GPIO75   0x800U        // Data Register for this pin
#define GPIO_GPCDAT_GPIO76   0x1000U       // Data Register for this pin
#define GPIO_GPCDAT_GPIO77   0x2000U       // Data Register for this pin
#define GPIO_GPCDAT_GPIO78   0x4000U       // Data Register for this pin
#define GPIO_GPCDAT_GPIO79   0x8000U       // Data Register for this pin
#define GPIO_GPCDAT_GPIO80   0x10000U      // Data Register for this pin
#define GPIO_GPCDAT_GPIO81   0x20000U      // Data Register for this pin
#define GPIO_GPCDAT_GPIO82   0x40000U      // Data Register for this pin
#define GPIO_GPCDAT_GPIO83   0x80000U      // Data Register for this pin
#define GPIO_GPCDAT_GPIO84   0x100000U     // Data Register for this pin
#define GPIO_GPCDAT_GPIO85   0x200000U     // Data Register for this pin
#define GPIO_GPCDAT_GPIO86   0x400000U     // Data Register for this pin
#define GPIO_GPCDAT_GPIO87   0x800000U     // Data Register for this pin
#define GPIO_GPCDAT_GPIO88   0x1000000U    // Data Register for this pin
#define GPIO_GPCDAT_GPIO89   0x2000000U    // Data Register for this pin
#define GPIO_GPCDAT_GPIO90   0x4000000U    // Data Register for this pin
#define GPIO_GPCDAT_GPIO91   0x8000000U    // Data Register for this pin
#define GPIO_GPCDAT_GPIO92   0x10000000U   // Data Register for this pin
#define GPIO_GPCDAT_GPIO93   0x20000000U   // Data Register for this pin
#define GPIO_GPCDAT_GPIO94   0x40000000U   // Data Register for this pin
#define GPIO_GPCDAT_GPIO95   0x80000000U   // Data Register for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCSET register
//
//*************************************************************************************************
#define GPIO_GPCSET_GPIO64   0x1U          // Output Set bit for this pin
#define GPIO_GPCSET_GPIO65   0x2U          // Output Set bit for this pin
#define GPIO_GPCSET_GPIO66   0x4U          // Output Set bit for this pin
#define GPIO_GPCSET_GPIO67   0x8U          // Output Set bit for this pin
#define GPIO_GPCSET_GPIO68   0x10U         // Output Set bit for this pin
#define GPIO_GPCSET_GPIO69   0x20U         // Output Set bit for this pin
#define GPIO_GPCSET_GPIO70   0x40U         // Output Set bit for this pin
#define GPIO_GPCSET_GPIO71   0x80U         // Output Set bit for this pin
#define GPIO_GPCSET_GPIO72   0x100U        // Output Set bit for this pin
#define GPIO_GPCSET_GPIO73   0x200U        // Output Set bit for this pin
#define GPIO_GPCSET_GPIO74   0x400U        // Output Set bit for this pin
#define GPIO_GPCSET_GPIO75   0x800U        // Output Set bit for this pin
#define GPIO_GPCSET_GPIO76   0x1000U       // Output Set bit for this pin
#define GPIO_GPCSET_GPIO77   0x2000U       // Output Set bit for this pin
#define GPIO_GPCSET_GPIO78   0x4000U       // Output Set bit for this pin
#define GPIO_GPCSET_GPIO79   0x8000U       // Output Set bit for this pin
#define GPIO_GPCSET_GPIO80   0x10000U      // Output Set bit for this pin
#define GPIO_GPCSET_GPIO81   0x20000U      // Output Set bit for this pin
#define GPIO_GPCSET_GPIO82   0x40000U      // Output Set bit for this pin
#define GPIO_GPCSET_GPIO83   0x80000U      // Output Set bit for this pin
#define GPIO_GPCSET_GPIO84   0x100000U     // Output Set bit for this pin
#define GPIO_GPCSET_GPIO85   0x200000U     // Output Set bit for this pin
#define GPIO_GPCSET_GPIO86   0x400000U     // Output Set bit for this pin
#define GPIO_GPCSET_GPIO87   0x800000U     // Output Set bit for this pin
#define GPIO_GPCSET_GPIO88   0x1000000U    // Output Set bit for this pin
#define GPIO_GPCSET_GPIO89   0x2000000U    // Output Set bit for this pin
#define GPIO_GPCSET_GPIO90   0x4000000U    // Output Set bit for this pin
#define GPIO_GPCSET_GPIO91   0x8000000U    // Output Set bit for this pin
#define GPIO_GPCSET_GPIO92   0x10000000U   // Output Set bit for this pin
#define GPIO_GPCSET_GPIO93   0x20000000U   // Output Set bit for this pin
#define GPIO_GPCSET_GPIO94   0x40000000U   // Output Set bit for this pin
#define GPIO_GPCSET_GPIO95   0x80000000U   // Output Set bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCCLEAR register
//
//*************************************************************************************************
#define GPIO_GPCCLEAR_GPIO64   0x1U          // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO65   0x2U          // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO66   0x4U          // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO67   0x8U          // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO68   0x10U         // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO69   0x20U         // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO70   0x40U         // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO71   0x80U         // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO72   0x100U        // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO73   0x200U        // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO74   0x400U        // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO75   0x800U        // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO76   0x1000U       // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO77   0x2000U       // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO78   0x4000U       // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO79   0x8000U       // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO80   0x10000U      // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO81   0x20000U      // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO82   0x40000U      // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO83   0x80000U      // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO84   0x100000U     // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO85   0x200000U     // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO86   0x400000U     // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO87   0x800000U     // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO88   0x1000000U    // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO89   0x2000000U    // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO90   0x4000000U    // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO91   0x8000000U    // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO92   0x10000000U   // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO93   0x20000000U   // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO94   0x40000000U   // Output Clear bit for this pin
#define GPIO_GPCCLEAR_GPIO95   0x80000000U   // Output Clear bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPCTOGGLE register
//
//*************************************************************************************************
#define GPIO_GPCTOGGLE_GPIO64   0x1U          // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO65   0x2U          // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO66   0x4U          // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO67   0x8U          // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO68   0x10U         // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO69   0x20U         // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO70   0x40U         // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO71   0x80U         // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO72   0x100U        // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO73   0x200U        // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO74   0x400U        // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO75   0x800U        // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO76   0x1000U       // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO77   0x2000U       // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO78   0x4000U       // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO79   0x8000U       // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO80   0x10000U      // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO81   0x20000U      // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO82   0x40000U      // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO83   0x80000U      // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO84   0x100000U     // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO85   0x200000U     // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO86   0x400000U     // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO87   0x800000U     // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO88   0x1000000U    // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO89   0x2000000U    // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO90   0x4000000U    // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO91   0x8000000U    // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO92   0x10000000U   // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO93   0x20000000U   // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO94   0x40000000U   // Output Toggle bit for this pin
#define GPIO_GPCTOGGLE_GPIO95   0x80000000U   // Output Toggle bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDDAT register
//
//*************************************************************************************************
#define GPIO_GPDDAT_GPIO96    0x1U          // Data Register for this pin
#define GPIO_GPDDAT_GPIO97    0x2U          // Data Register for this pin
#define GPIO_GPDDAT_GPIO98    0x4U          // Data Register for this pin
#define GPIO_GPDDAT_GPIO99    0x8U          // Data Register for this pin
#define GPIO_GPDDAT_GPIO100   0x10U         // Data Register for this pin
#define GPIO_GPDDAT_GPIO101   0x20U         // Data Register for this pin
#define GPIO_GPDDAT_GPIO102   0x40U         // Data Register for this pin
#define GPIO_GPDDAT_GPIO103   0x80U         // Data Register for this pin
#define GPIO_GPDDAT_GPIO104   0x100U        // Data Register for this pin
#define GPIO_GPDDAT_GPIO105   0x200U        // Data Register for this pin
#define GPIO_GPDDAT_GPIO106   0x400U        // Data Register for this pin
#define GPIO_GPDDAT_GPIO107   0x800U        // Data Register for this pin
#define GPIO_GPDDAT_GPIO108   0x1000U       // Data Register for this pin
#define GPIO_GPDDAT_GPIO109   0x2000U       // Data Register for this pin
#define GPIO_GPDDAT_GPIO110   0x4000U       // Data Register for this pin
#define GPIO_GPDDAT_GPIO111   0x8000U       // Data Register for this pin
#define GPIO_GPDDAT_GPIO112   0x10000U      // Data Register for this pin
#define GPIO_GPDDAT_GPIO113   0x20000U      // Data Register for this pin
#define GPIO_GPDDAT_GPIO114   0x40000U      // Data Register for this pin
#define GPIO_GPDDAT_GPIO115   0x80000U      // Data Register for this pin
#define GPIO_GPDDAT_GPIO116   0x100000U     // Data Register for this pin
#define GPIO_GPDDAT_GPIO117   0x200000U     // Data Register for this pin //add
#define GPIO_GPDDAT_GPIO118   0x400000U     // Data Register for this pin //add
#define GPIO_GPDDAT_GPIO119   0x800000U     // Data Register for this pin
#define GPIO_GPDDAT_GPIO120   0x1000000U    // Data Register for this pin
#define GPIO_GPDDAT_GPIO121   0x2000000U    // Data Register for this pin //add
#define GPIO_GPDDAT_GPIO122   0x4000000U    // Data Register for this pin
#define GPIO_GPDDAT_GPIO123   0x8000000U    // Data Register for this pin
#define GPIO_GPDDAT_GPIO124   0x10000000U   // Data Register for this pin
#define GPIO_GPDDAT_GPIO125   0x20000000U   // Data Register for this pin
#define GPIO_GPDDAT_GPIO126   0x40000000U   // Data Register for this pin
#define GPIO_GPDDAT_GPIO127   0x80000000U   // Data Register for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDSET register
//
//*************************************************************************************************
#define GPIO_GPDSET_GPIO96    0x1U          // Output Set bit for this pin
#define GPIO_GPDSET_GPIO97    0x2U          // Output Set bit for this pin
#define GPIO_GPDSET_GPIO98    0x4U          // Output Set bit for this pin
#define GPIO_GPDSET_GPIO99    0x8U          // Output Set bit for this pin
#define GPIO_GPDSET_GPIO100   0x10U         // Output Set bit for this pin
#define GPIO_GPDSET_GPIO101   0x20U         // Output Set bit for this pin
#define GPIO_GPDSET_GPIO102   0x40U         // Output Set bit for this pin
#define GPIO_GPDSET_GPIO103   0x80U         // Output Set bit for this pin
#define GPIO_GPDSET_GPIO104   0x100U        // Output Set bit for this pin
#define GPIO_GPDSET_GPIO105   0x200U        // Output Set bit for this pin
#define GPIO_GPDSET_GPIO106   0x400U        // Output Set bit for this pin
#define GPIO_GPDSET_GPIO107   0x800U        // Output Set bit for this pin
#define GPIO_GPDSET_GPIO108   0x1000U       // Output Set bit for this pin
#define GPIO_GPDSET_GPIO109   0x2000U       // Output Set bit for this pin
#define GPIO_GPDSET_GPIO110   0x4000U       // Output Set bit for this pin
#define GPIO_GPDSET_GPIO111   0x8000U       // Output Set bit for this pin
#define GPIO_GPDSET_GPIO112   0x10000U      // Output Set bit for this pin
#define GPIO_GPDSET_GPIO113   0x20000U      // Output Set bit for this pin
#define GPIO_GPDSET_GPIO114   0x40000U      // Output Set bit for this pin
#define GPIO_GPDSET_GPIO115   0x80000U      // Output Set bit for this pin
#define GPIO_GPDSET_GPIO116   0x100000U     // Output Set bit for this pin
#define GPIO_GPDSET_GPIO117   0x200000U     // Output Set bit for this pin //add
#define GPIO_GPDSET_GPIO118   0x400000U     // Output Set bit for this pin //add
#define GPIO_GPDSET_GPIO119   0x800000U     // Output Set bit for this pin
#define GPIO_GPDSET_GPIO120   0x1000000U    // Output Set bit for this pin
#define GPIO_GPDSET_GPIO121   0x2000000U    // Output Set bit for this pin //add
#define GPIO_GPDSET_GPIO122   0x4000000U    // Output Set bit for this pin
#define GPIO_GPDSET_GPIO123   0x8000000U    // Output Set bit for this pin
#define GPIO_GPDSET_GPIO124   0x10000000U   // Output Set bit for this pin
#define GPIO_GPDSET_GPIO125   0x20000000U   // Output Set bit for this pin
#define GPIO_GPDSET_GPIO126   0x40000000U   // Output Set bit for this pin
#define GPIO_GPDSET_GPIO127   0x80000000U   // Output Set bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDCLEAR register
//
//*************************************************************************************************
#define GPIO_GPDCLEAR_GPIO96    0x1U          // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO97    0x2U          // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO98    0x4U          // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO99    0x8U          // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO100   0x10U         // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO101   0x20U         // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO102   0x40U         // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO103   0x80U         // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO104   0x100U        // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO105   0x200U        // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO106   0x400U        // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO107   0x800U        // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO108   0x1000U       // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO109   0x2000U       // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO110   0x4000U       // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO111   0x8000U       // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO112   0x10000U      // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO113   0x20000U      // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO114   0x40000U      // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO115   0x80000U      // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO116   0x100000U     // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO117   0x200000U     // Output Clear bit for this pin //add
#define GPIO_GPDCLEAR_GPIO118   0x400000U     // Output Clear bit for this pin //add
#define GPIO_GPDCLEAR_GPIO119   0x800000U     // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO120   0x1000000U    // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO121   0x2000000U    // Output Clear bit for this pin //add
#define GPIO_GPDCLEAR_GPIO122   0x4000000U    // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO123   0x8000000U    // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO124   0x10000000U   // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO125   0x20000000U   // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO126   0x40000000U   // Output Clear bit for this pin
#define GPIO_GPDCLEAR_GPIO127   0x80000000U   // Output Clear bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPDTOGGLE register
//
//*************************************************************************************************
#define GPIO_GPDTOGGLE_GPIO96    0x1U          // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO97    0x2U          // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO98    0x4U          // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO99    0x8U          // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO100   0x10U         // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO101   0x20U         // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO102   0x40U         // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO103   0x80U         // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO104   0x100U        // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO105   0x200U        // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO106   0x400U        // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO107   0x800U        // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO108   0x1000U       // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO109   0x2000U       // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO110   0x4000U       // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO111   0x8000U       // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO112   0x10000U      // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO113   0x20000U      // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO114   0x40000U      // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO115   0x80000U      // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO116   0x100000U     // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO117   0x200000U     // Output Toggle bit for this pin //add
#define GPIO_GPDTOGGLE_GPIO118   0x400000U     // Output Toggle bit for this pin //add
#define GPIO_GPDTOGGLE_GPIO119   0x800000U     // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO120   0x1000000U    // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO121   0x2000000U    // Output Toggle bit for this pin //add
#define GPIO_GPDTOGGLE_GPIO122   0x4000000U    // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO123   0x8000000U    // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO124   0x10000000U   // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO125   0x20000000U   // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO126   0x40000000U   // Output Toggle bit for this pin
#define GPIO_GPDTOGGLE_GPIO127   0x80000000U   // Output Toggle bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPEDAT register
//
//*************************************************************************************************
#define GPIO_GPEDAT_GPIO128   0x1U          // Data Register for this pin
#define GPIO_GPEDAT_GPIO129   0x2U          // Data Register for this pin
#define GPIO_GPEDAT_GPIO130   0x4U          // Data Register for this pin
#define GPIO_GPEDAT_GPIO131   0x8U          // Data Register for this pin
#define GPIO_GPEDAT_GPIO132   0x10U         // Data Register for this pin
#define GPIO_GPEDAT_GPIO133   0x20U         // Data Register for this pin
#define GPIO_GPEDAT_GPIO134   0x40U         // Data Register for this pin
#define GPIO_GPEDAT_GPIO135   0x80U         // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO136   0x100U        // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO137   0x200U        // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO138   0x400U        // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO139   0x800U        // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO140   0x1000U       // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO141   0x2000U       // Data Register for this pin
#define GPIO_GPEDAT_GPIO142   0x4000U       // Data Register for this pin
#define GPIO_GPEDAT_GPIO143   0x8000U       // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO144   0x10000U      // Data Register for this pin //add
#define GPIO_GPEDAT_GPIO145   0x20000U      // Data Register for this pin
#define GPIO_GPEDAT_GPIO146   0x40000U      // Data Register for this pin
#define GPIO_GPEDAT_GPIO147   0x80000U      // Data Register for this pin
#define GPIO_GPEDAT_GPIO148   0x100000U     // Data Register for this pin
#define GPIO_GPEDAT_GPIO149   0x200000U     // Data Register for this pin
#define GPIO_GPEDAT_GPIO150   0x400000U     // Data Register for this pin
#define GPIO_GPEDAT_GPIO151   0x800000U     // Data Register for this pin
#define GPIO_GPEDAT_GPIO152   0x1000000U    // Data Register for this pin
#define GPIO_GPEDAT_GPIO153   0x2000000U    // Data Register for this pin
#define GPIO_GPEDAT_GPIO154   0x4000000U    // Data Register for this pin
#define GPIO_GPEDAT_GPIO155   0x8000000U    // Data Register for this pin
#define GPIO_GPEDAT_GPIO156   0x10000000U   // Data Register for this pin
#define GPIO_GPEDAT_GPIO157   0x20000000U   // Data Register for this pin
#define GPIO_GPEDAT_GPIO158   0x40000000U   // Data Register for this pin
#define GPIO_GPEDAT_GPIO159   0x80000000U   // Data Register for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPESET register
//
//*************************************************************************************************
#define GPIO_GPESET_GPIO128   0x1U          // Output Set bit for this pin
#define GPIO_GPESET_GPIO129   0x2U          // Output Set bit for this pin
#define GPIO_GPESET_GPIO130   0x4U          // Output Set bit for this pin
#define GPIO_GPESET_GPIO131   0x8U          // Output Set bit for this pin
#define GPIO_GPESET_GPIO132   0x10U         // Output Set bit for this pin
#define GPIO_GPESET_GPIO133   0x20U         // Output Set bit for this pin
#define GPIO_GPESET_GPIO134   0x40U         // Output Set bit for this pin
#define GPIO_GPESET_GPIO135   0x80U         // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO136   0x100U        // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO137   0x200U        // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO138   0x400U        // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO139   0x800U        // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO140   0x1000U       // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO141   0x2000U       // Output Set bit for this pin
#define GPIO_GPESET_GPIO142   0x4000U       // Output Set bit for this pin
#define GPIO_GPESET_GPIO143   0x8000U       // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO144   0x10000U      // Output Set bit for this pin //add
#define GPIO_GPESET_GPIO145   0x20000U      // Output Set bit for this pin
#define GPIO_GPESET_GPIO146   0x40000U      // Output Set bit for this pin
#define GPIO_GPESET_GPIO147   0x80000U      // Output Set bit for this pin
#define GPIO_GPESET_GPIO148   0x100000U     // Output Set bit for this pin
#define GPIO_GPESET_GPIO149   0x200000U     // Output Set bit for this pin
#define GPIO_GPESET_GPIO150   0x400000U     // Output Set bit for this pin
#define GPIO_GPESET_GPIO151   0x800000U     // Output Set bit for this pin
#define GPIO_GPESET_GPIO152   0x1000000U    // Output Set bit for this pin
#define GPIO_GPESET_GPIO153   0x2000000U    // Output Set bit for this pin
#define GPIO_GPESET_GPIO154   0x4000000U    // Output Set bit for this pin
#define GPIO_GPESET_GPIO155   0x8000000U    // Output Set bit for this pin
#define GPIO_GPESET_GPIO156   0x10000000U   // Output Set bit for this pin
#define GPIO_GPESET_GPIO157   0x20000000U   // Output Set bit for this pin
#define GPIO_GPESET_GPIO158   0x40000000U   // Output Set bit for this pin
#define GPIO_GPESET_GPIO159   0x80000000U   // Output Set bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPECLEAR register
//
//*************************************************************************************************
#define GPIO_GPECLEAR_GPIO128   0x1U          // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO129   0x2U          // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO130   0x4U          // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO131   0x8U          // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO132   0x10U         // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO133   0x20U         // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO134   0x40U         // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO135   0x80U         // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO136   0x100U        // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO137   0x200U        // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO138   0x400U        // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO139   0x800U        // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO140   0x1000U       // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO141   0x2000U       // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO142   0x4000U       // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO143   0x8000U       // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO144   0x10000U      // Output Clear bit for this pin //add
#define GPIO_GPECLEAR_GPIO145   0x20000U      // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO146   0x40000U      // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO147   0x80000U      // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO148   0x100000U     // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO149   0x200000U     // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO150   0x400000U     // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO151   0x800000U     // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO152   0x1000000U    // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO153   0x2000000U    // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO154   0x4000000U    // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO155   0x8000000U    // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO156   0x10000000U   // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO157   0x20000000U   // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO158   0x40000000U   // Output Clear bit for this pin
#define GPIO_GPECLEAR_GPIO159   0x80000000U   // Output Clear bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPETOGGLE register
//
//*************************************************************************************************
#define GPIO_GPETOGGLE_GPIO128   0x1U          // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO129   0x2U          // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO130   0x4U          // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO131   0x8U          // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO132   0x10U         // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO133   0x20U         // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO134   0x40U         // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO135   0x80U         // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO136   0x100U        // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO137   0x200U        // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO138   0x400U        // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO139   0x800U        // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO140   0x1000U       // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO141   0x2000U       // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO142   0x4000U       // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO143   0x8000U       // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO144   0x10000U      // Output Toggle bit for this pin //add
#define GPIO_GPETOGGLE_GPIO145   0x20000U      // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO146   0x40000U      // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO147   0x80000U      // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO148   0x100000U     // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO149   0x200000U     // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO150   0x400000U     // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO151   0x800000U     // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO152   0x1000000U    // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO153   0x2000000U    // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO154   0x4000000U    // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO155   0x8000000U    // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO156   0x10000000U   // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO157   0x20000000U   // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO158   0x40000000U   // Output Toggle bit for this pin
#define GPIO_GPETOGGLE_GPIO159   0x80000000U   // Output Toggle bit for this pin

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFDAT register
//
//*************************************************************************************************
#define GPIO_GPFDAT_GPIO160   0x1U     // Data Register for this pin
#define GPIO_GPFDAT_GPIO161   0x2U     // Data Register for this pin
#define GPIO_GPFDAT_GPIO162   0x4U     // Data Register for this pin
#define GPIO_GPFDAT_GPIO163   0x8U     // Data Register for this pin
#define GPIO_GPFDAT_GPIO164   0x10U    // Data Register for this pin
#define GPIO_GPFDAT_GPIO165   0x20U    // Data Register for this pin
#define GPIO_GPFDAT_GPIO166   0x40U    // Data Register for this pin
#define GPIO_GPFDAT_GPIO167   0x80U    // Data Register for this pin
#define GPIO_GPFDAT_GPIO168   0x100U   // Data Register for this pin
#define GPIO_GPFDAT_GPIO169   0x200U      // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO170   0x400U      // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO171   0x800U      // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO172   0x1000U     // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO173   0x2000U     // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO174   0x4000U     // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO175   0x8000U     // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO176   0x10000U    // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO177   0x20000U    // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO178   0x40000U    // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO179   0x80000U    // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO180   0x100000U   // Data Register for this pin  //add
#define GPIO_GPFDAT_GPIO181   0x200000U   // Data Register for this pin  //add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFSET register
//
//*************************************************************************************************
#define GPIO_GPFSET_GPIO160   0x1U     // Output Set bit for this pin
#define GPIO_GPFSET_GPIO161   0x2U     // Output Set bit for this pin
#define GPIO_GPFSET_GPIO162   0x4U     // Output Set bit for this pin
#define GPIO_GPFSET_GPIO163   0x8U     // Output Set bit for this pin
#define GPIO_GPFSET_GPIO164   0x10U    // Output Set bit for this pin
#define GPIO_GPFSET_GPIO165   0x20U    // Output Set bit for this pin
#define GPIO_GPFSET_GPIO166   0x40U    // Output Set bit for this pin
#define GPIO_GPFSET_GPIO167   0x80U    // Output Set bit for this pin
#define GPIO_GPFSET_GPIO168   0x100U   // Output Set bit for this pin
#define GPIO_GPFSET_GPIO169   0x200U      // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO170   0x400U      // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO171   0x800U      // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO172   0x1000U     // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO173   0x2000U     // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO174   0x4000U     // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO175   0x8000U     // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO176   0x10000U    // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO177   0x20000U    // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO178   0x40000U    // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO179   0x80000U    // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO180   0x100000U   // Output Set bit for this pin //add
#define GPIO_GPFSET_GPIO181   0x200000U   // Output Set bit for this pin //add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFCLEAR register
//
//*************************************************************************************************
#define GPIO_GPFCLEAR_GPIO160   0x1U     // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO161   0x2U     // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO162   0x4U     // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO163   0x8U     // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO164   0x10U    // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO165   0x20U    // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO166   0x40U    // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO167   0x80U    // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO168   0x100U   // Output Clear bit for this pin
#define GPIO_GPFCLEAR_GPIO169   0x200U      // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO170   0x400U      // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO171   0x800U      // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO172   0x1000U     // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO173   0x2000U     // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO174   0x4000U     // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO175   0x8000U     // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO176   0x10000U    // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO177   0x20000U    // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO178   0x40000U    // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO179   0x80000U    // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO180   0x100000U   // Output Clear bit for this pin //add
#define GPIO_GPFCLEAR_GPIO181   0x200000U   // Output Clear bit for this pin //add

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPFTOGGLE register
//
//*************************************************************************************************
#define GPIO_GPFTOGGLE_GPIO160   0x1U     // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO161   0x2U     // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO162   0x4U     // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO163   0x8U     // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO164   0x10U    // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO165   0x20U    // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO166   0x40U    // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO167   0x80U    // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO168   0x100U   // Output Toggle bit for this pin
#define GPIO_GPFTOGGLE_GPIO169   0x200U      // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO170   0x400U      // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO171   0x800U      // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO172   0x1000U     // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO173   0x2000U     // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO174   0x4000U     // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO175   0x8000U     // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO176   0x10000U    // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO177   0x20000U    // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO178   0x40000U    // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO179   0x80000U    // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO180   0x100000U   // Output Toggle bit for this pin //add
#define GPIO_GPFTOGGLE_GPIO181   0x200000U   // Output Toggle bit for this pin //add


#endif



#endif
