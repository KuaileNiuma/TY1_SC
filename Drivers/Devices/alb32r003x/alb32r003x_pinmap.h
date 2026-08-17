/**
  *************************************************************************************
  * @file pin_map.h
  * @brief This file contains the definition of pin_map driver.
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

#ifndef __ALB32R003X_PINMAP_H
#define __ALB32R003X_PINMAP_H

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


//*****************************************************************************
// 0x00000003 = MUX register value
// 0x0000000C = GMUX register value
// 0x0000FF00 = Shift amount within mux registers
// 0xFFFF0000 = Offset of MUX register
//*****************************************************************************
#define GPIO_0_GPIO0                    0x00000000U
#define GPIO_0_EPWM1_A                  0x00000001U
#define GPIO_0_SPIC_STE                 0x00000002U     // newly added
#define GPIO_0_OUTPUTXBAR7              0x00000003U     // newly added
#define GPIO_0_SCIA_RX                 0x00000005U     // newly added
#define GPIO_0_I2CA_SDA                 0x00000006U
#define GPIO_0_SPIA_STE                 0x00000007U
#define GPIO_0_FSIRXA_CLK               0x00000009U
#define GPIO_0_CANB_RX                  0x0000000AU     // CAN2_RX
#define GPIO_0_CLB_OUTPUTXBAR8          0x0000000BU
#define GPIO_0_EQEP1_INDEX              0x0000000DU
#define GPIO_0_HIC_D7                   0x0000000EU     // does not exist
#define GPIO_0_HIC_BASESEL1             0x0000000FU     // EPWM3_A

#define GPIO_1_GPIO1                    0x00000400U
#define GPIO_1_EPWM1_B                  0x00000401U
#define GPIO_1_SPIC_SOMI                0x00000402U     // newly added
#define GPIO_1_TIMER6_ETR               0x00000403U     // newly added
#define GPIO_1_SCIA_TX                  0x00000405U     // newly added
#define GPIO_1_I2CA_SCL                 0x00000406U
#define GPIO_1_SPIA_SOMI                0x00000407U
#define GPIO_1_EQEP1_STROBE             0x00000409U     // newly added
#define GPIO_1_CANB_TX                  0x0000040AU     // CAN2_TX
#define GPIO_1_CLB_OUTPUTXBAR7          0x0000040BU
#define GPIO_1_HIC_A2                   0x0000040DU     // EPWM10_B
#define GPIO_1_FSITXA_TDM_D1            0x0000040EU
#define GPIO_1_HIC_D10                  0x0000040FU     // EPWM3_B

#define GPIO_2_GPIO2                    0x00000800U
#define GPIO_2_EPWM2_A                  0x00000801U
#define GPIO_2_ATIM1_BKIN               0x00000802U     // newly added
#define GPIO_2_SPIC_SIMO                0x00000803U     // newly added
#define GPIO_2_OUTPUTXBAR1              0x00000805U
#define GPIO_2_PMBUSA_SDA               0x00000806U     // I2C3_SDA
#define GPIO_2_SPIA_SIMO                0x00000807U
#define GPIO_2_SCIA_TX                  0x00000809U     // UART1_TX
#define GPIO_2_FSIRXA_D1                0x0000080AU
#define GPIO_2_I2CB_SDA                 0x0000080BU
#define GPIO_2_HIC_A1                   0x0000080DU     // EPWM10_A
#define GPIO_2_CANA_TX                  0x0000080EU
#define GPIO_2_HIC_D9                   0x0000080FU     // EPWM4_A

#define GPIO_3_GPIO3                    0x00000C00U
#define GPIO_3_EPWM2_B                  0x00000C01U
#define GPIO_3_OUTPUTXBAR2              0x00000C02U
#define GPIO_3_SPIC_CLK                 0x00000C03U     // newly added
//#define GPIO_3_OUTPUTXBAR2              0x00000C05U     // newly added
#define GPIO_3_PMBUSA_SCL               0x00000C06U     // I2C3_SCL
#define GPIO_3_SPIA_CLK                 0x00000C07U
#define GPIO_3_SCIA_RX                  0x00000C09U     // UART1_RX
#define GPIO_3_FSIRXA_D0                0x00000C0AU
#define GPIO_3_I2CB_SCL                 0x00000C0BU
#define GPIO_3_HIC_NOE                  0x00000C0DU     // TIMER6_CH1
#define GPIO_3_CANA_RX                  0x00000C0EU
#define GPIO_3_HIC_D4                   0x00000C0FU     // EPWM1_A

#define GPIO_4_GPIO4                    0x00001000U
#define GPIO_4_EPWM3_A                  0x00001001U
#define GPIO_4_I2CA_SCL                 0x00001002U     // newly added
#define GPIO_4_CANB_TX                  0x00001003U     // CAN2_TX
#define GPIO_4_OUTPUTXBAR3              0x00001005U
#define GPIO_4_CANA_TX                  0x00001006U
#define GPIO_4_SPIB_CLK                 0x00001007U
#define GPIO_4_EQEP2_STROBE             0x00001009U
#define GPIO_4_FSIRXA_CLK               0x0000100AU
#define GPIO_4_CLB_OUTPUTXBAR6          0x0000100BU
#define GPIO_4_HIC_BASESEL2             0x0000100DU     // EPWM11_B
#define GPIO_4_SPIA_SOMI                0x0000100EU     // newly added
#define GPIO_4_HIC_NWE                  0x0000100FU     // EPWM1_A

#define GPIO_5_GPIO5                    0x00001400U
#define GPIO_5_EPWM3_B                  0x00001401U
#define GPIO_5_I2CA_SDA                 0x00001402U
#define GPIO_5_OUTPUTXBAR3              0x00001403U
#define GPIO_5_CANB_RX                  0x00001405U     // CAN2_RX
#define GPIO_5_CANA_RX                  0x00001406U     // CAN1_RX
#define GPIO_5_SPIA_STE                 0x00001407U     // SPI1_STE
#define GPIO_5_FSITXA_D1                0x00001409U
#define GPIO_5_CLB_OUTPUTXBAR5          0x0000140AU
#define GPIO_5_UART1_RX                 0x0000140BU     // newly added
#define GPIO_5_HIC_A7                   0x0000140DU     // TIMER6_CH2
#define GPIO_5_HIC_D4                   0x0000140EU     // does not exist
#define GPIO_5_HIC_D15                  0x0000140FU     // EPWM1_B

#define GPIO_6_GPIO6                    0x00001800U
#define GPIO_6_EPWM4_A                  0x00001801U
#define GPIO_6_OUTPUTXBAR4              0x00001802U
#define GPIO_6_SYNCOUT                  0x00001803U
#define GPIO_6_EQEP1_A                  0x00001805U
#define GPIO_6_SPIC_SOMI                0x00001806U     // newly added
#define GPIO_6_SPIB_SOMI                0x00001807U
#define GPIO_6_FSITXA_D0                0x00001809U
#define GPIO_6_SPID_SOMI                0x0000180AU     // newly added
#define GPIO_6_FSITXA_D1                0x0000180BU
#define GPIO_6_HIC_NBE1                 0x0000180DU     // UART4_TX
#define GPIO_6_CLB_OUTPUTXBAR8          0x0000180EU
#define GPIO_6_HIC_D14                  0x0000180FU     // EPWM2_A

#define GPIO_7_GPIO7                    0x00001C00U
#define GPIO_7_EPWM4_B                  0x00001C01U
#define GPIO_7_EPWM2_A                  0x00001C02U     // newly added
#define GPIO_7_OUTPUTXBAR5              0x00001C03U
#define GPIO_7_EQEP1_B                  0x00001C05U
#define GPIO_7_SPIC_SIMO                0x00001C06U     // newly added
#define GPIO_7_SPIB_SIMO                0x00001C07U
#define GPIO_7_FSITXA_CLK               0x00001C09U
#define GPIO_7_CLB_OUTPUTXBAR2          0x00001C0AU
#define GPIO_7_UART1_TX                 0x00001C0BU     // newly added
#define GPIO_7_HIC_A6                   0x00001C0DU     // UART4_RX
#define GPIO_7_CAN2_TX                  0x00001C0EU     // newly added
#define GPIO_7_HIC_D14                  0x00001C0FU     // EPWM2_B

#define GPIO_8_GPIO8                    0x00040000U
#define GPIO_8_EPWM5_A                  0x00040001U
#define GPIO_8_ATIM1_ETR                0x00040002U     // newly added
#define GPIO_8_ADCSOCAO                 0x00040003U
#define GPIO_8_EQEP1_STROBE             0x00040005U
#define GPIO_8_SCIA_TX                  0x00040006U     // UART1_TX
#define GPIO_8_SPIA_SIMO                0x00040007U
#define GPIO_8_I2CA_SCL                 0x00040009U
#define GPIO_8_FSITXA_D1                0x0004000AU
#define GPIO_8_CLB_OUTPUTXBAR5          0x0004000BU
#define GPIO_8_HIC_A0                   0x0004000DU     // EPWM11_A
#define GPIO_8_FSITXA_TDM_CLK           0x0004000EU
#define GPIO_8_HIC_D8                   0x0004000FU     // does not exist

#define GPIO_9_GPIO9                    0x00040400U
#define GPIO_9_EPWM5_B                  0x00040401U
#define GPIO_9_SCIB_TX                  0x00040402U     // UART2_TX
#define GPIO_9_OUTPUTXBAR6              0x00040403U
#define GPIO_9_EQEP1_INDEX              0x00040405U
#define GPIO_9_SCIA_RX                  0x00040406U     // UART1_RX
#define GPIO_9_SPIA_CLK                 0x00040407U
#define GPIO_9_I2CA_SCL                 0x00040409U     // newly added
#define GPIO_9_FSITXA_D0                0x0004040AU
#define GPIO_9_LINB_RX                  0x0004040BU
#define GPIO_9_HIC_BASESEL0             0x0004040DU     // I2CC_SCL
#define GPIO_9_I2CB_SCL                 0x0004040EU
#define GPIO_9_HIC_NRDY                 0x0004040FU     // EQEP3_B

#define GPIO_10_GPIO10                  0x00040800U
#define GPIO_10_EPWM6_A                 0x00040801U
#define GPIO_10_ATIM1_CH1               0x00040802U     // newly added
#define GPIO_10_ADCSOCBO                0x00040803U
#define GPIO_10_EQEP1_A                 0x00040805U
#define GPIO_10_SCIB_TX                 0x00040806U     // UART2_TX
#define GPIO_10_SPIA_SOMI               0x00040807U
#define GPIO_10_I2CA_SDA                0x00040809U
#define GPIO_10_FSITXA_CLK              0x0004080AU
#define GPIO_10_LINB_TX                 0x0004080BU
#define GPIO_10_HIC_NWE                 0x0004080DU     // EQEP3_STROBE
#define GPIO_10_FSITXA_TDM_D0           0x0004080EU
#define GPIO_10_CLB_OUTPUTXBAR4         0x0004080FU

#define GPIO_11_GPIO11                  0x00040C00U
#define GPIO_11_EPWM6_B                 0x00040C01U
#define GPIO_11_CAN2_RX                 0x00040C02U     // newly added
#define GPIO_11_OUTPUTXBAR7             0x00040C03U
#define GPIO_11_EQEP1_B                 0x00040C05U
#define GPIO_11_SCIB_RX                 0x00040C06U     // UART2_RX
#define GPIO_11_SPIA_STE                0x00040C07U
#define GPIO_11_FSIRXA_D1               0x00040C09U
#define GPIO_11_LINB_RX                 0x00040C0AU
#define GPIO_11_EQEP2_A                 0x00040C0BU
#define GPIO_11_SPIA_SIMO               0x00040C0DU
#define GPIO_11_HIC_D6                  0x00040C0EU     // SPID_SIMO
#define GPIO_11_HIC_NBE0                0x00040C0FU     // EQEP3_INDEX

#define GPIO_12_GPIO12                  0x00041000U
#define GPIO_12_EPWM7_A                 0x00041001U
#define GPIO_12_ATIM1_CH1N              0x00041002U     // newly added
#define GPIO_12_CANB_RX                 0x00041003U     // CAN2_RX
#define GPIO_12_EQEP1_STROBE            0x00041005U
#define GPIO_12_SCIB_TX                 0x00041006U     // UART2_TX
#define GPIO_12_PMBUSA_CTL              0x00041007U     // I2CD_SCL
#define GPIO_12_FSIRXA_D0               0x00041009U
#define GPIO_12_LINB_TX                 0x0004100AU
#define GPIO_12_SPIA_CLK                0x0004100BU
#define GPIO_12_CANA_RX                 0x0004100DU
#define GPIO_12_HIC_D13                 0x0004100EU     // SPI4_CLK
#define GPIO_12_HIC_INT                 0x0004100FU     // TIMER6_CH3

#define GPIO_13_GPIO13                  0x00041400U
#define GPIO_13_EPWM7_B                 0x00041401U
#define GPIO_13_ATIM1_CH2               0x00041402U     // newly added
#define GPIO_13_CANB_TX                 0x00041403U     // CAN2_TX
#define GPIO_13_EQEP1_INDEX             0x00041405U
#define GPIO_13_SCIB_RX                 0x00041406U     // UART2_RX
#define GPIO_13_PMBUSA_ALERT            0x00041407U     // I2CD_SDA
#define GPIO_13_FSIRXA_CLK              0x00041409U
#define GPIO_13_LINB_RX                 0x0004140AU
#define GPIO_13_SPIA_SOMI               0x0004140BU
#define GPIO_13_CANA_TX                 0x0004140DU
#define GPIO_13_HIC_D11                 0x0004140EU     // SPI4_SOMI
#define GPIO_13_HIC_D5                  0x0004140FU     // TIMER6_CH4

#define GPIO_14_GPIO14                  0x00041800U
#define GPIO_14_EPWM8_A                 0x00041801U
#define GPIO_14_SCIB_TX                 0x00041802U     // UART2_TX
#define GPIO_14_SPIC_CLK                0x00041803U     // newly added
#define GPIO_14_I2CB_SDA                0x00041805U
#define GPIO_14_OUTPUTXBAR3             0x00041806U
#define GPIO_14_PMBUSA_SDA              0x00041807U     // I2CC_SDA
#define GPIO_14_SPIB_CLK                0x00041809U
#define GPIO_14_EQEP2_A                 0x0004180AU
#define GPIO_14_LINB_TX                 0x0004180BU
#define GPIO_14_EPWM3_A                 0x0004180DU
#define GPIO_14_CLB_OUTPUTXBAR7         0x0004180EU
#define GPIO_14_HIC_D15                 0x0004180FU     // ATIM1_CH2N

#define GPIO_15_GPIO15                  0x00041C00U
#define GPIO_15_EPWM8_B                 0x00041C01U
#define GPIO_15_SCIB_RX                 0x00041C02U     // UART2_RX
#define GPIO_15_SPIC_STE                0x00041C03U     // newly added
#define GPIO_15_I2CB_SCL                0x00041C05U
#define GPIO_15_OUTPUTXBAR4             0x00041C06U
#define GPIO_15_PMBUSA_SCL              0x00041C07U     // I2CC_SCL
#define GPIO_15_SPIB_STE                0x00041C09U
#define GPIO_15_EQEP2_B                 0x00041C0AU
#define GPIO_15_LINB_RX                 0x00041C0BU
#define GPIO_15_EPWM3_B                 0x00041C0DU
#define GPIO_15_CLB_OUTPUTXBAR6         0x00041C0EU
#define GPIO_15_HIC_D12                 0x00041C0FU     // ATIM1_CH3

#define GPIO_16_GPIO16                  0x00080000U
#define GPIO_16_SPIA_SIMO               0x00080001U
#define GPIO_16_EPWM9_A                 0x00080002U     // newly added
#define GPIO_16_OUTPUTXBAR7             0x00080003U
#define GPIO_16_EPWM5_A                 0x00080005U
#define GPIO_16_SCIA_TX                 0x00080006U     // UART1_TX
#define GPIO_16_SD1_D1                  0x00080007U
#define GPIO_16_EQEP1_STROBE            0x00080009U
#define GPIO_16_PMBUSA_SCL              0x0008000AU     // I2CC_SCL
#define GPIO_16_XCLKOUT                 0x0008000BU
#define GPIO_16_EQEP2_B                 0x0008000DU
#define GPIO_16_SPIB_SOMI               0x0008000EU
#define GPIO_16_HIC_D1                  0x0008000FU     // EQEP3_STROBE

#define GPIO_17_GPIO17                  0x00080400U
#define GPIO_17_SPIA_SOMI               0x00080401U
#define GPIO_17_EPWM9_B                 0x00080402U     // newly added
#define GPIO_17_OUTPUTXBAR8             0x00080403U
#define GPIO_17_EPWM5_B                 0x00080405U
#define GPIO_17_SCIA_RX                 0x00080406U     // UART1_RX
#define GPIO_17_SD1_C1                  0x00080407U
#define GPIO_17_EQEP1_INDEX             0x00080409U
#define GPIO_17_PMBUSA_SDA              0x0008040AU     // I2CC_SDA
#define GPIO_17_CANA_TX                 0x0008040BU
#define GPIO_17_CAN2_TX                 0x0008040DU     // newly added
#define GPIO_17_EPWM6_A                 0x0008040EU     // newly added
#define GPIO_17_HIC_D2                  0x0008040FU     // ATIM1_CH3N

#define GPIO_18_GPIO18                  0x00080800U
#define GPIO_18_SPIA_CLK                0x00080801U
#define GPIO_18_SCIB_TX                 0x00080802U     // UART2_TX
#define GPIO_18_CANA_RX                 0x00080803U
#define GPIO_18_EPWM6_A                 0x00080805U
#define GPIO_18_I2CA_SCL                0x00080806U
#define GPIO_18_SD1_D2                  0x00080807U
#define GPIO_18_EQEP2_A                 0x00080809U
#define GPIO_18_PMBUSA_CTL              0x0008080AU     // I2CD_SCL
#define GPIO_18_XCLKOUT                 0x0008080BU
#define GPIO_18_LINB_TX                 0x0008080DU
#define GPIO_18_FSITXA_TDM_CLK          0x0008080EU
#define GPIO_18_HIC_INT                 0x0008080FU     // EQEP3_INDEX

#define GPIO_19_GPIO19                  0x00080C00U
#define GPIO_19_SPIA_STE                0x00080C01U
#define GPIO_19_SCIB_RX                 0x00080C02U     // UART2_RX
#define GPIO_19_CANA_TX                 0x00080C03U
#define GPIO_19_EPWM6_B                 0x00080C05U
#define GPIO_19_I2CA_SDA                0x00080C06U
#define GPIO_19_SD1_C2                  0x00080C07U
#define GPIO_19_EQEP2_B                 0x00080C09U
#define GPIO_19_PMBUSA_ALERT            0x00080C0AU     // I2CD_SDA
#define GPIO_19_CLB_OUTPUTXBAR1         0x00080C0BU
#define GPIO_19_LINB_RX                 0x00080C0DU
#define GPIO_19_FSITXA_TDM_D0           0x00080C0EU
#define GPIO_19_HIC_NBE0                0x00080C0FU     // ATIM1_CH4

#define GPIO_20_GPIO20                  0x00081000U
#define GPIO_20_EQEP1_A                 0x00081001U
#define GPIO_20_EPWM13_A                0x00081002U     // newly added
#define GPIO_20_SPID_SIMO               0x00081003U     // newly added
#define GPIO_20_EPWM12_A                0x00081005U     // newly added
#define GPIO_20_SPIB_SIMO               0x00081006U
#define GPIO_20_SD1_D3                  0x00081007U
#define GPIO_20_CANB_TX                 0x00081009U     // CAN2_TX
#define GPIO_20_ADCE_EXTMUXSELO         0x0008100AU     // newly added
#define GPIO_20_I2CA_SCL                0x0008100BU     // newly added
#define GPIO_20_FSIRX2_CLK              0x0008100DU     // newly added
#define GPIO_20_ATIM1_CH4N              0x0008100EU     // newly added
#define GPIO_UART3_TX                   0x0008100FU     // newly added

#define GPIO_21_GPIO21                  0x00081400U
#define GPIO_21_EQEP1_B                 0x00081401U
#define GPIO_21_EPWM13_B                0x00081402U     // newly added
#define GPIO_21_SPID_SOMI               0x00081403U     // newly added
#define GPIO_21_EPWM12_B                0x00081405U     // newly added
#define GPIO_21_SPIB_SOMI               0x00081406U
#define GPIO_21_SD1_C3                  0x00081407U
#define GPIO_21_CANB_RX                 0x00081409U     // CAN2_RX
#define GPIO_21_ADCE_EXTMUXSEL1         0x0008140AU     // newly added
#define GPIO_21_I2CA_SDA                0x0008140BU     // newly added
#define GPIO_21_FSIRX2_DO               0x0008140DU     // newly added
#define GPIO_21_ATIM2_BKIN              0x0008140EU     // newly added
#define GPIO_21_UART3_RX                0x0008140FU     // newly added

#define GPIO_22_GPIO22                  0x00081800U
#define GPIO_22_EQEP1_STROBE            0x00081801U
#define GPIO_22_EPWM14_A                0x00081802U     // newly added
#define GPIO_22_SCIB_TX                 0x00081803U     // UART2_TX
#define GPIO_22_SPID_CLK                0x00081805U     // newly added
#define GPIO_22_SPIB_CLK                0x00081806U
#define GPIO_22_SD1_D4                  0x00081807U
#define GPIO_22_USARTA_TX                 0x00081809U
#define GPIO_22_CLB_OUTPUTXBAR1         0x0008180AU
#define GPIO_22_LINB_TX                 0x0008180BU
#define GPIO_22_HIC_A5                  0x0008180DU     // FSIRX0_D1
#define GPIO_22_EPWM4_A                 0x0008180EU
#define GPIO_22_HIC_D13                 0x0008180FU     // EQEP3_A

#define GPIO_23_GPIO23                  0x00081C00U
#define GPIO_23_EQEP1_INDEX             0x00081C01U
#define GPIO_23_EPWM14_B                0x00081C02U     // newly added
#define GPIO_23_SCIB_RX                 0x00081C03U     // UART2_RX
#define GPIO_23_SPID_STE                0x00081C05U     // newly added
#define GPIO_23_SPIB_STE                0x00081C06U
#define GPIO_23_SD1_C4                  0x00081C07U
#define GPIO_23_USARTA_RX                 0x00081C09U
#define GPIO_23_CLB_OUTPUTXBAR3         0x00081C0AU
#define GPIO_23_LINB_RX                 0x00081C0BU
#define GPIO_23_HIC_A3                  0x00081C0DU     // EPWM12_A
#define GPIO_23_EPWM4_B                 0x00081C0EU
#define GPIO_23_HIC_D11                 0x00081C0FU     // ATIM2_ETR

#define GPIO_24_GPIO24                  0x000C0000U
#define GPIO_24_OUTPUTXBAR1             0x000C0001U
#define GPIO_24_EQEP2_A                 0x000C0002U
#define GPIO_24_SPIA_STE                0x000C0003U     // newly added
#define GPIO_24_EPWM8_A                 0x000C0005U
#define GPIO_24_SPIB_SIMO               0x000C0006U
#define GPIO_24_SD2_D1                  0x000C0007U
#define GPIO_24_LINB_TX                 0x000C0009U
#define GPIO_24_PMBUSA_SCL              0x000C000AU    // I2CC_SCL
#define GPIO_24_SCIA_TX                 0x000C000BU    // UART1_TX
#define GPIO_24_ERRORSTS                0x000C000DU
#define GPIO_24_HIC_D3                  0x000C000FU    // EPWM9_A

#define GPIO_25_GPIO25                  0x000C0400U
#define GPIO_25_OUTPUTXBAR2             0x000C0401U
#define GPIO_25_EQEP2_B                 0x000C0402U
#define GPIO_25_FSITXB_TDM_CLK          0x000C0403U    // newly added
#define GPIO_25_EQEP1_A                 0x000C0405U
#define GPIO_25_SPIB_SOMI               0x000C0406U
#define GPIO_25_SD2_C1                  0x000C0407U
#define GPIO_25_FSITXA_D1               0x000C0409U
#define GPIO_25_PMBUSA_SDA              0x000C040AU    // I2CC_SDA
#define GPIO_25_SCIA_RX                 0x000C040BU    // UART1_RX
#define GPIO_25_EQEP3_A                 0x000C040DU    // newly added
#define GPIO_25_HIC_BASESEL0            0x000C040EU    // does not exist
#define GPIO_25_ATIM2_CH1N              0x000C040FU    // newly added

#define GPIO_26_GPIO26                  0x000C0800U
#define GPIO_26_OUTPUTXBAR3             0x000C0801U
#define GPIO_26_EQEP2_INDEX             0x000C0802U
#define GPIO_26_UART4_TX                0x000C0803U    // newly added
//#define GPIO_26_OUTPUTXBAR3             0x000C0805U    // newly added
#define GPIO_26_SPIB_CLK                0x000C0806U
#define GPIO_26_SD2_D2                  0x000C0807U
#define GPIO_26_FSITXA_D0               0x000C0809U
#define GPIO_26_PMBUSA_CTL              0x000C080AU    // I2CD_SCL
#define GPIO_26_I2CA_SDA                0x000C080BU
#define GPIO_26_EQEP3_B                 0x000C080DU    // newly added
#define GPIO_26_HIC_D0                  0x000C080EU    // does not exist
#define GPIO_26_HIC_A1                  0x000C080FU    // ATIM2_CH2

#define GPIO_27_GPIO27                  0x000C0C00U
#define GPIO_27_OUTPUTXBAR4             0x000C0C01U
#define GPIO_27_EQEP2_STROBE            0x000C0C02U
#define GPIO_27_UART4_RX                0x000C0C03U    // newly added
//#define GPIO_27_OUTPUTXBAR4             0x000C0C05U    // newly added
#define GPIO_27_SPIB_STE                0x000C0C06U
#define GPIO_27_SD2_C2                  0x000C0C07U
#define GPIO_27_FSITXA_CLK              0x000C0C09U
#define GPIO_27_PMBUSA_ALERT            0x000C0C0AU    // I2CD_SDA
#define GPIO_27_I2CA_SCL                0x000C0C0BU
#define GPIO_27_EQEP3_STROBE            0x000C0C0DU    // newly added
#define GPIO_27_HIC_D1                  0x000C0C0EU    // does not exist
#define GPIO_27_HIC_A4                  0x000C0C0FU    // ATIM2_CH2N

#define GPIO_28_GPIO28                  0x000C1000U
#define GPIO_28_SCIA_RX                 0x000C1001U    // UART1_RX
#define GPIO_28_FSITX2_TDM_DO           0x000C1002U    // newly added
#define GPIO_28_EPWM7_A                 0x000C1003U
#define GPIO_28_OUTPUTXBAR5             0x000C1005U
#define GPIO_28_EQEP1_A                 0x000C1006U
#define GPIO_28_SD2_D3                  0x000C1007U
#define GPIO_28_EQEP2_STROBE            0x000C1009U
#define GPIO_28_LINA_TX                 0x000C100AU
#define GPIO_28_SPIB_CLK                0x000C100BU
#define GPIO_28_ERRORSTS                0x000C100DU
#define GPIO_28_I2CB_SDA                0x000C100EU
#define GPIO_28_HIC_NOE                 0x000C100FU    // SPIC_CLK

#define GPIO_29_GPIO29                  0x000C1400U
#define GPIO_29_SCIA_TX                 0x000C1401U    // UART1_TX
#define GPIO_29_FSITXB_TDM_D1           0x000C1402U    // newly added
#define GPIO_29_EPWM7_B                 0x000C1403U
#define GPIO_29_OUTPUTXBAR6             0x000C1405U
#define GPIO_29_EQEP1_B                 0x000C1406U
#define GPIO_29_SD2_C3                  0x000C1407U
#define GPIO_29_EQEP2_INDEX             0x000C1409U
#define GPIO_29_LINA_RX                 0x000C140AU
#define GPIO_29_SPIB_STE                0x000C140BU
#define GPIO_29_ERRORSTS                0x000C140DU
#define GPIO_29_I2CB_SCL                0x000C140EU
#define GPIO_29_HIC_NCS                 0x000C140FU    // SPIC_STE

#define GPIO_30_GPIO30                  0x000C1800U
#define GPIO_30_CANA_RX                 0x000C1801U
#define GPIO_30_SPID_SIMO               0x000C1802U    // newly added
#define GPIO_30_SPIB_SIMO               0x000C1803U
#define GPIO_30_OUTPUTXBAR7             0x000C1805U
#define GPIO_30_EQEP1_STROBE            0x000C1806U
#define GPIO_30_SD2_D4                  0x000C1807U
#define GPIO_30_FSIRXA_CLK              0x000C1809U
#define GPIO_30_CANB_RX                 0x000C180AU    // CAN2_RX
#define GPIO_30_EPWM1_A                 0x000C180BU
#define GPIO_30_EQEP3_INDEX             0x000C180DU    // newly added
#define GPIO_30_HIC_D8                  0x000C180EU    // UART4_TX
#define GPIO_30_SPIC_SIMO               0x000C180FU    // newly added

#define GPIO_31_GPIO31                  0x000C1C00U
#define GPIO_31_CANA_TX                 0x000C1C01U
#define GPIO_31_SPID_SOMI               0x000C1C02U    // newly added
#define GPIO_31_SPIB_SOMI               0x000C1C03U
#define GPIO_31_OUTPUTXBAR8             0x000C1C05U
#define GPIO_31_EQEP1_INDEX             0x000C1C06U
#define GPIO_31_SD2_C4                  0x000C1C07U
#define GPIO_31_FSIRXA_D1               0x000C1C09U
#define GPIO_31_CANB_TX                 0x000C1C0AU    // CAN2_TX
#define GPIO_31_EPWM1_B                 0x000C1C0BU
#define GPIO_ATIM2_CH3                  0x000C1C0DU    // newly added
#define GPIO_31_HIC_D10                 0x000C1C0EU    // UART4_RX
#define GPIO_31_SPIC_SOMI               0x000C1C0FU    // newly added

#define GPIO_32_GPIO32                  0x00100000U
#define GPIO_32_I2CA_SDA                0x00100001U
#define GPIO_32_EQEP1_INDEX             0x00100002U    // newly added
#define GPIO_32_SPIB_CLK                0x00100003U
#define GPIO_32_EPWM8_B                 0x00100005U
#define GPIO_32_LINA_TX                 0x00100006U
#define GPIO_32_SD1_D2                  0x00100007U
#define GPIO_32_FSIRXA_D0               0x00100009U
#define GPIO_32_CANA_TX                 0x0010000AU
#define GPIO_32_PMBUSA_SDA              0x0010000BU    // I2CC_SDA
#define GPIO_32_ADCSOCBO                0x0010000DU
#define GPIO_32_ATIM2_CH3N              0x0010000EU    // newly added
#define GPIO_32_HIC_INT                 0x0010000FU    // does not exist

#define GPIO_33_GPIO33                  0x00100400U
#define GPIO_33_I2CA_SCL                0x00100401U
#define GPIO_33_EPWM15_A                0x00100402U    // newly added
#define GPIO_33_SPIB_STE                0x00100403U
#define GPIO_33_OUTPUTXBAR4             0x00100405U
#define GPIO_33_LINA_RX                 0x00100406U
#define GPIO_33_SD1_C2                  0x00100407U
#define GPIO_33_FSIRXA_CLK              0x00100409U
#define GPIO_33_CANA_RX                 0x0010040AU
#define GPIO_33_EQEP2_B                 0x0010040BU
#define GPIO_33_ADCSOCAO                0x0010040DU
#define GPIO_33_SD1_C1                  0x0010040EU
#define GPIO_33_HIC_D0                  0x0010040FU    // UART3_RX

#define GPIO_34_GPIO34                  0x00100800U
#define GPIO_34_OUTPUTXBAR1             0x00100801U
#define GPIO_34_EPWM15_B                0x00100802U    // newly added
#define GPIO_34_TIMER4_ETR              0x00100803U    // newly added
#define GPIO_34_PMBUSA_SDA              0x00100806U
#define GPIO_34_HIC_NBE1                0x0010080DU    // does not exist
#define GPIO_34_I2CB_SDA                0x0010080EU
#define GPIO_34_HIC_D9                  0x0010080FU    // ATIM2_CH4

#define GPIO_35_GPIO35                  0x00100C00U
#define GPIO_35_SCIA_RX                 0x00100C01U    // UART1_RX
#define GPIO_35_SPIA_SOMI               0x00100C02U    // newly added
#define GPIO_35_I2CA_SDA                0x00100C03U
#define GPIO_35_CANA_RX                 0x00100C05U
#define GPIO_35_PMBUSA_SCL              0x00100C06U
#define GPIO_35_LINA_RX                 0x00100C07U
#define GPIO_35_EQEP1_A                 0x00100C09U
#define GPIO_35_PMBUSA_CTL              0x00100C0AU    // I2CD_SCL
#define GPIO_35_EPWM5_B                 0x00100C0BU
#define GPIO_35_SD2_C1                  0x00100C0DU
#define GPIO_35_HIC_NWE                 0x00100C0EU    // CAN2_RX
#define GPIO_35_TDI                     0x00100C0FU

#define GPIO_37_GPIO37                  0x00101400U
#define GPIO_37_OUTPUTXBAR2             0x00101401U
#define GPIO_37_SPIA_STE                0x00101402U    // newly added
#define GPIO_37_I2CA_SCL                0x00101403U
#define GPIO_37_SCIA_TX                 0x00101405U    // UART1_TX
#define GPIO_37_CANA_TX                 0x00101406U
#define GPIO_37_LINA_TX                 0x00101407U
#define GPIO_37_EQEP1_B                 0x00101409U
#define GPIO_37_PMBUSA_ALERT            0x0010140AU    // I2CD_SDA
#define GPIO_37_EPWM5_A                 0x0010140BU    // newly added
#define GPIO_37_ATIM2_CH4N              0x0010140DU    // newly added
#define GPIO_37_HIC_NRDY                0x0010140EU    // CAN2_TX
#define GPIO_37_TDO                     0x0010140FU

#define GPIO_39_GPIO39                  0x00101C00U    // does not exist
#define GPIO_39_CANB_RX                 0x00101C06U    // does not exist
#define GPIO_39_FSIRXA_CLK              0x00101C07U    // does not exist
#define GPIO_39_EQEP2_INDEX             0x00101C09U    // does not exist
#define GPIO_39_CLB_OUTPUTXBAR2         0x00101C0BU    // does not exist
#define GPIO_39_SYNCOUT                 0x00101C0DU    // does not exist
#define GPIO_39_EQEP1_INDEX             0x00101C0EU    // does not exist
#define GPIO_39_HIC_D7                  0x00101C0FU    // does not exist

#define GPIO_40_GPIO40                  0x00140000U
#define GPIO_40_SPIB_SIMO               0x00140001U
#define GPIO_40_SPID_SIMO               0x00140002U    // newly added
#define GPIO_40_ATIM2_CH2               0x00140003U    // newly added
#define GPIO_40_EPWM2_B                 0x00140005U
#define GPIO_40_PMBUSA_SDA              0x00140006U    // I2CC_SDA
#define GPIO_40_FSIRXA_D0               0x00140007U
#define GPIO_40_SCIB_TX                 0x00140009U    // UART2_TX
#define GPIO_40_EQEP1_A                 0x0014000AU
#define GPIO_40_LINB_TX                 0x0014000BU
#define GPIO_40_TIMER1_ETR              0x0014000DU    // newly added
#define GPIO_40_HIC_NBE1                0x0014000EU    // CLB_OUTPUTXBAR4
#define GPIO_40_HIC_D5                  0x0014000FU    // EQEP3_STROBE

#define GPIO_41_GPIO41                  0x00140400U
#define GPIO_41_EPWM7_A                 0x00140401U    // newly added
#define GPIO_41_SPID_SOMI               0x00140402U    // newly added
#define GPIO_41_ATIM2_CH2N              0x00140403U    // newly added
#define GPIO_41_EPWM2_A                 0x00140405U
#define GPIO_41_PMBUSA_SCL              0x00140406U    // I2CC_SCL
#define GPIO_41_FSIRXA_D1               0x00140407U
#define GPIO_41_SCIB_RX                 0x00140409U    // UART2_RX
#define GPIO_41_EQEP1_B                 0x0014040AU
#define GPIO_41_LINB_RX                 0x0014040BU
#define GPIO_41_HIC_A4                  0x0014040DU    // EPWM12_B
#define GPIO_41_SPIB_SOMI               0x0014040EU
#define GPIO_41_HIC_D12                 0x0014040FU    // does not exist

#define GPIO_42_GPIO42                  0x00140800U    // does not exist
#define GPIO_42_LINA_RX                 0x00140802U    // does not exist
#define GPIO_42_OUTPUTXBAR5             0x00140803U    // does not exist
#define GPIO_42_PMBUSA_CTL              0x00140805U    // does not exist
#define GPIO_42_I2CA_SDA                0x00140806U    // does not exist
#define GPIO_42_EQEP1_STROBE            0x0014080AU    // does not exist
#define GPIO_42_CLB_OUTPUTXBAR3         0x0014080BU    // does not exist
#define GPIO_42_HIC_D2                  0x0014080EU    // does not exist
#define GPIO_42_HIC_A6                  0x0014080FU    // does not exist

#define GPIO_43_GPIO43                  0x00140C00U    // does not exist
#define GPIO_43_OUTPUTXBAR6             0x00140C03U    // does not exist
#define GPIO_43_PMBUSA_ALERT            0x00140C05U    // does not exist
#define GPIO_43_I2CA_SCL                0x00140C06U    // does not exist
#define GPIO_43_EQEP1_INDEX             0x00140C0AU    // does not exist
#define GPIO_43_CLB_OUTPUTXBAR4         0x00140C0BU    // does not exist
#define GPIO_43_SD2_D3                  0x00140C0DU    // does not exist
#define GPIO_43_HIC_D3                  0x00140C0EU    // does not exist
#define GPIO_43_HIC_A7                  0x00140C0FU    // does not exist

#define GPIO_44_GPIO44                  0x00141000U
#define GPIO_44_SPID_CLK                0x00141001U    // newly added
#define GPIO_44_EPWM16_A                0x00141002U    // newly added
#define GPIO_44_OUTPUTXBAR7             0x00141003U
#define GPIO_44_EQEP1_A                 0x00141005U
#define GPIO_44_PMBUSA_SDA              0x00141006U    // I2CC_SDA
#define GPIO_44_FSITXA_CLK              0x00141007U
#define GPIO_44_PMBUSA_CTL              0x00141009U    // I2CD_SCL
#define GPIO_44_CLB_OUTPUTXBAR3         0x0014100AU
#define GPIO_44_FSIRXA_D0               0x0014100BU
#define GPIO_44_HIC_D7                  0x0014100DU    // TIMER1_CH1
#define GPIO_44_LINB_TX                 0x0014100EU
#define GPIO_44_HIC_D5                  0x0014100FU    // SPIC_CLK

#define GPIO_45_GPIO45                  0x00141400U    // does not exist
#define GPIO_45_OUTPUTXBAR8             0x00141403U    // does not exist
#define GPIO_45_FSITXA_D0               0x00141407U    // does not exist
#define GPIO_45_PMBUSA_ALERT            0x00141409U    // does not exist
#define GPIO_45_CLB_OUTPUTXBAR4         0x0014140AU    // does not exist
#define GPIO_45_SD2_C3                  0x0014140DU    // does not exist
#define GPIO_45_HIC_D6                  0x0014140FU    // does not exist

#define GPIO_46_GPIO46                  0x00141800U    // does not exist
#define GPIO_46_LINA_TX                 0x00141803U    // does not exist
#define GPIO_46_CANB_TX                 0x00141805U    // does not exist
#define GPIO_46_FSITXA_D1               0x00141807U    // does not exist
#define GPIO_46_PMBUSA_SDA              0x00141809U    // does not exist
#define GPIO_46_SD2_C4                  0x0014180DU    // does not exist
#define GPIO_46_HIC_NWE                 0x0014180FU    // does not exist

#define GPIO_47_GPIO47                  0x00141C00U
#define GPIO_47_SPID_STE                0x00141C01U    // newly added
#define GPIO_47_EPWM16_B                0x00141C02U    // newly added
#define GPIO_47_LINA_RX                 0x00141C03U
#define GPIO_47_CANB_RX                 0x00141C05U    // CAN2_RX
#define GPIO_47_TIMER1_CH2              0x00141C06U    // newly added
#define GPIO_47_CLB_OUTPUTXBAR2         0x00141C07U
#define GPIO_47_PMBUSA_SCL              0x00141C09U    // I2CC_SCL
#define GPIO_47_TIMER2_ETR              0x00141C0AU    // newly added
#define GPIO_47_SD2_D4                  0x00141C0DU
#define GPIO_47_FSITXA_TDM_CLK          0x00141C0EU
#define GPIO_47_HIC_A6                  0x00141C0FU    // SPIC_STE

#define GPIO_48_GPIO48                  0x00180000U
#define GPIO_48_OUTPUTXBAR3             0x00180001U
#define GPIO_48_EPWM17_A                0x00180002U    // newly added
#define GPIO_48_CANA_TX                 0x00180003U
#define GPIO_48_CAN2_TX                 0x00180005U    // newly added
#define GPIO_48_SCIA_TX                 0x00180006U    // UART1_TX
#define GPIO_48_SD1_D1                  0x00180007U
#define GPIO_48_PMBUSA_SDA              0x00180009U    // I2CC_SDA
#define GPIO_48_SPID_CLK                0x0018000AU    // newly added
#define GPIO_48_ATIM1_CH1               0x0018000BU    // newly added
#define GPIO_48_TIMER3_ETR              0x0018000DU    // newly added
#define GPIO_48_HIC_A7                  0x0018000FU    // SPI3_SIMO

#define GPIO_49_GPIO49                  0x00180400U
#define GPIO_49_OUTPUTXBAR4             0x00180401U
#define GPIO_49_EPWM17_B                0x00180402U    // newly added
#define GPIO_49_CANA_RX                 0x00180403U
#define GPIO_49_CAN2_RX                 0x00180405U    // newly added
#define GPIO_49_SCIA_RX                 0x00180406U    // UART1_RX
#define GPIO_49_SD1_C1                  0x00180407U
#define GPIO_49_LINA_RX                 0x00180409U
#define GPIO_49_SPID_STE                0x0018040AU    // newly added
#define GPIO_49_ATIM1_CH1N              0x0018040BU    // newly added
#define GPIO_49_SD2_D1                  0x0018040DU
#define GPIO_49_FSITXA_D0               0x0018040EU
#define GPIO_49_HIC_D2                  0x0018040FU    // SPIC_SOMI

#define GPIO_50_GPIO50                  0x00180800U
#define GPIO_50_EQEP1_A                 0x00180801U
#define GPIO_EPWM18_A                   0x00180802U    // newly added
#define GPIO_TIMER1_CH3                 0x00180803U    // newly added
#define GPIO_50_CANB_TX                 0x00180805U    // CAN2_TX
#define GPIO_50_SPIB_SIMO               0x00180806U
#define GPIO_50_SD1_D2                  0x00180807U
#define GPIO_50_I2CB_SDA                0x00180809U
#define GPIO_50_SPID_SIMO               0x0018080AU    // newly added
#define GPIO_50_ATIM1_CH2               0x0018080BU    // newly added
#define GPIO_50_SD2_D2                  0x0018080DU
#define GPIO_50_FSITXA_D1               0x0018080EU
#define GPIO_50_HIC_D3                  0x0018080FU    // UART3_TX

#define GPIO_51_GPIO51                  0x00180C00U
#define GPIO_51_EQEP1_B                 0x00180C01U
#define GPIO_51_EPWM18_B                0x00180C02U    // newly added
#define GPIO_51_TIMER1_CH4              0x00180C03U    // newly added
#define GPIO_51_CANB_RX                 0x00180C05U    // CAN2_RX
#define GPIO_51_SPIB_SOMI               0x00180C06U
#define GPIO_51_SD1_C2                  0x00180C07U
#define GPIO_51_I2CB_SCL                0x00180C09U
#define GPIO_51_SPID_SOMI               0x00180C0AU    // newly added
#define GPIO_51_ATIM1_CH2N              0x00180C0BU    // newly added
#define GPIO_51_SD2_D3                  0x00180C0DU
#define GPIO_51_FSITXA_CLK              0x00180C0EU
#define GPIO_51_HIC_D6                  0x00180C0FU    // UART3_RX

#define GPIO_52_GPIO52                  0x00181000U
#define GPIO_52_EQEP1_STROBE            0x00181001U
#define GPIO_52_EPWM13_A                0x00181002U    // newly added
#define GPIO_52_SPIC_CLK                0x00181003U    // newly added
#define GPIO_52_CLB_OUTPUTXBAR5         0x00181005U
#define GPIO_52_SPIB_CLK                0x00181006U
#define GPIO_52_SD1_D3                  0x00181007U
#define GPIO_52_SYNCOUT                 0x00181009U
#define GPIO_52_ATIM1_BKIN              0x0018100AU    // newly added
#define GPIO_52_TIMER2_CH1              0x0018100BU    // newly added
#define GPIO_52_SD2_D4                  0x0018100DU
#define GPIO_52_FSIRXA_D0               0x0018100EU
#define GPIO_52_HIC_NWE                 0x0018100FU    // I2CD_SCL

#define GPIO_53_GPIO53                  0x00181400U
#define GPIO_53_EQEP1_INDEX             0x00181401U
#define GPIO_53_EPWM13_B                0x00181402U    // newly added
#define GPIO_53_SPIC_STE                0x00181403U    // newly added
#define GPIO_53_CLB_OUTPUTXBAR6         0x00181405U
#define GPIO_53_SPIB_STE                0x00181406U
#define GPIO_53_SD1_C3                  0x00181407U
#define GPIO_53_ADCSOCAO                0x00181409U
#define GPIO_53_CANA_RX                 0x0018140AU
#define GPIO_53_TIMER2_CH2              0x0018140BU    // newly added
#define GPIO_53_SD1_C1                  0x0018140DU
#define GPIO_53_FSIRXA_D1               0x0018140EU
#define GPIO_53_I2CD_SDA                0x0018140FU    // newly added

#define GPIO_54_GPIO54                  0x00181800U
#define GPIO_54_SPIA_SIMO               0x00181801U
#define GPIO_54_EPWM14_A                0x00181802U    // newly added
#define GPIO_54_SPIC_SIMO               0x00181803U    // newly added
#define GPIO_54_EQEP2_A                 0x00181805U
#define GPIO_54_OUTPUTXBAR2             0x00181806U
#define GPIO_54_SD1_D4                  0x00181807U
#define GPIO_54_ADCSOCBO                0x00181809U
#define GPIO_54_LINB_TX                 0x0018180AU
#define GPIO_54_TIMER2_CH3              0x0018180BU    // newly added
#define GPIO_54_SD1_C2                  0x0018180DU
#define GPIO_54_FSIRXA_CLK              0x0018180EU
#define GPIO_54_FSITXA_TDM_D1           0x0018180FU

#define GPIO_55_GPIO55                  0x00181C00U
#define GPIO_55_SPIA_SOMI               0x00181C01U
#define GPIO_55_EPWM14_B                0x00181C02U    // newly added
#define GPIO_55_SPIC_SOMI               0x00181C03U    // newly added
#define GPIO_55_EQEP2_B                 0x00181C05U
#define GPIO_55_OUTPUTXBAR3             0x00181C06U
#define GPIO_55_SD1_C4                  0x00181C07U
#define GPIO_55_ERRORSTS                0x00181C09U
#define GPIO_55_LINB_RX                 0x00181C0AU
#define GPIO_55_TIMER2_CH4              0x00181C0BU    // newly added
#define GPIO_55_SD1_C3                  0x00181C0DU
#define GPIO_55_FSITXB_CLK              0x00181C0EU    // newly added
#define GPIO_55_XFLASH_SCLK             0x00181C0FU    // XFLASH_SCLK

#define GPIO_56_GPIO56                  0x001C0000U
#define GPIO_56_SPIA_CLK                0x001C0001U
#define GPIO_56_CLB_OUTPUTXBAR7         0x001C0002U
#define GPIO_56_CANB_TX                 0x001C0003U    // CAN2_TX
#define GPIO_56_EQEP2_STROBE            0x001C0005U
#define GPIO_56_SCIB_TX                 0x001C0006U    // UART2_TX
#define GPIO_56_SD2_D1                  0x001C0007U
#define GPIO_56_SPIB_SIMO               0x001C0009U
#define GPIO_56_I2CA_SDA                0x001C000AU
#define GPIO_56_EQEP1_A                 0x001C000BU
#define GPIO_56_SD1_C4                  0x001C000DU
#define GPIO_56_FSIRXA_D1               0x001C000EU
#define GPIO_56_XFLASH_SSN              0x001C000FU    // XFLASH_SSN

#define GPIO_57_GPIO57                  0x001C0400U
#define GPIO_57_SPIA_STE                0x001C0401U
#define GPIO_57_CLB_OUTPUTXBAR8         0x001C0402U
#define GPIO_57_CANB_RX                 0x001C0403U    // CAN2_RX
#define GPIO_57_EQEP2_INDEX             0x001C0405U
#define GPIO_57_SCIB_RX                 0x001C0406U    // UART2_RX
#define GPIO_57_SD2_C1                  0x001C0407U
#define GPIO_57_SPIB_SOMI               0x001C0409U
#define GPIO_57_I2CA_SCL                0x001C040AU
#define GPIO_57_EQEP1_B                 0x001C040BU
#define GPIO_57_ATIM1_ETR               0x001C040DU    // newly added
#define GPIO_57_FSIRXA_CLK              0x001C040EU
#define GPIO_57_XFLASH_D0               0x001C040FU    // XFLASH_DO

#define GPIO_58_GPIO58                  0x001C0800U
#define GPIO_58_TIMER3_CH1              0x001C0801U    // newly added
#define GPIO_58_EPWM15_A                0x001C0802U    // newly added
#define GPIO_58_ATIM2_CH1               0x001C0803U    // newly added
#define GPIO_58_OUTPUTXBAR1             0x001C0805U
#define GPIO_58_SPIB_CLK                0x001C0806U
#define GPIO_58_SD2_D2                  0x001C0807U
#define GPIO_58_LINA_TX                 0x001C0809U
#define GPIO_58_CANA_TX                 0x001C080AU
#define GPIO_58_EQEP1_STROBE            0x001C080BU
#define GPIO_58_SD2_C2                  0x001C080DU
#define GPIO_58_FSIRXA_D0               0x001C080EU
#define GPIO_58_XFLASH_D1               0x001C080FU    // XFLASH_D1

#define GPIO_59_GPIO59                  0x001C0C00U
#define GPIO_59_TIMER3_CH2              0x001C0C01U    // newly added
#define GPIO_59_EPWM15_B                0x001C0C02U    // newly added
#define GPIO_59_ATIM2_CH1N              0x001C0C03U    // newly added
#define GPIO_59_OUTPUTXBAR2             0x001C0C05U
#define GPIO_59_SPIB_STE                0x001C0C06U
#define GPIO_59_SD2_C2                  0x001C0C07U
#define GPIO_59_LINA_RX                 0x001C0C09U
#define GPIO_59_CANA_RX                 0x001C0C0AU
#define GPIO_59_EQEP1_INDEX             0x001C0C0BU
#define GPIO_59_SD2_C3                  0x001C0C0DU
#define GPIO_59_FSITXA_TDM_D1           0x001C0C0EU
#define GPIO_59_XFLASH_D2               0x001C0C0FU    // newly added

#define GPIO_60_GPIO60                  0x001C1000U
#define GPIO_60_EPWM12_B                0x001C1001U    // newly added
#define GPIO_60_EPWM16_A                0x001C1002U    // newly added
#define GPIO_60_CANB_TX                 0x001C1003U    // CAN2_TX
#define GPIO_60_OUTPUTXBAR3             0x001C1005U
#define GPIO_60_SPIB_SIMO               0x001C1006U
#define GPIO_60_SD2_D3                  0x001C1007U
#define GPIO_60_FSITXB_D0               0x001C1009U    // newly added
#define GPIO_60_TIMER3_CH3              0x001C100AU    // newly added
#define GPIO_60_ATIM1_CH3               0x001C100BU    // newly added
#define GPIO_60_SD2_C4                  0x001C100DU
#define GPIO_60_UART4_TX                0x001C100EU    // newly added
#define GPIO_60_XFLASH_D3               0x001C100FU    // XFLASH_D3

#define GPIO_61_GPIO61                  0x001C1400U
#define GPIO_61_ATIM2_BKIN              0x001C1401U    // newly added
#define GPIO_61_EPWM16_B                0x001C1402U    // newly added
#define GPIO_61_CANB_RX                 0x001C1403U    // CAN2_RX
#define GPIO_61_OUTPUTXBAR4             0x001C1405U
#define GPIO_61_SPIB_SOMI               0x001C1406U
#define GPIO_61_SD2_C3                  0x001C1407U
#define GPIO_61_FSITXB_D1               0x001C1409U    // newly added
#define GPIO_61_TIMER3_CH4              0x001C140AU    // newly added
#define GPIO_61_ATIM1_CH3N              0x001C140BU    // newly added
#define GPIO_61_UART4_RX                0x001C140DU    // newly added
#define GPIO_61_CANA_RX                 0x001C140EU
#define GPIO_61_CSPI1                   0x001C140FU    // newly added

#define GPIO_62_GPIO62                  0x001C1800U
#define GPIO_62_EPWM10_A                0x001C1801U    // newly added
#define GPIO_62_OUTPUTXBAR3             0x001C1802U    // newly added
#define GPIO_62_EPWM17_A                0x001C1803U    // newly added
#define GPIO_62_CAN2_TX                 0x001C1805U    // newly added
#define GPIO_62_UART1_TX                0x001C1806U    // newly added
#define GPIO_62_FSIRXB_CLK              0x001C1807U    // newly added
#define GPIO_62_I2CC_SDA                0x001C1809U    // newly added
#define GPIO_62_TIMER4_CH1              0x001C180AU    // newly added
#define GPIO_62_ATIM1_CH4               0x001C180BU    // newly added
#define GPIO_62_UART3_TX                0x001C180DU    // newly added
#define GPIO_62_CSPI2                   0x001C180FU    // newly added

#define GPIO_63_GPIO63                  0x001C1C00U
#define GPIO_63_EPWM10_B                0x001C1C01U    // newly added
#define GPIO_63_OUTPUTXBAR4             0x001C1C02U    // newly added
#define GPIO_63_EPWM17_B                0x001C1C03U    // newly added
#define GPIO_63_CAN2_RX                 0x001C1C05U    // newly added
#define GPIO_63_UART1_RX                0x001C1C06U    // newly added
#define GPIO_63_FSIRXB_D0               0x001C1C07U    // newly added
#define GPIO_63_LINA_RX                 0x001C1C09U    // newly added
#define GPIO_63_TIMER4_CH2              0x001C1C0AU    // newly added
#define GPIO_63_ATIM1_CH4N              0x001C1C0BU    // newly added
#define GPIO_63_UART3_RX                0x001C1C0DU    // newly added
#define GPIO_63_CSPI3                   0x001C1C0FU    // newly added

#define GPIO_224_GPIO224                0x00200000U
#define GPIO_224_EPWM11_B               0x00200001U    // newly added
#define GPIO_224_SD2_D3                 0x00200002U
#define GPIO_224_ATIM2_ETR              0x00200003U    // newly added
#define GPIO_224_OUTPUTXBAR3            0x00200005U    // newly added
#define GPIO_224_SPIA_SIMO              0x00200006U    // newly added
#define GPIO_224_FSIRX2_D1              0x00200007U    // newly added
#define GPIO_224_EPWM1_A                0x00200009U    // newly added
#define GPIO_224_CAN2_TX                0x0020000AU    // newly added
#define GPIO_224_EQEP1_A                0x0020000BU    // newly added
#define GPIO_224_ADCE_EXTMUXSEL3        0x0020000DU    // newly added
#define GPIO_224_UART3_TX               0x0020000EU    // newly added
#define GPIO_224_HIC_A3                 0x0020000FU    // CSPI4

#define GPIO_225_GPIO225                0x00200400U
#define GPIO_225_SD2_C2                 0x00200402U
#define GPIO_225_HIC_NWE                0x0020040FU    // does not exist

#define GPIO_226_GPIO226                0x00200800U
#define GPIO_226_EPWM10_B               0x00200801U    // newly added
#define GPIO_226_SD2_D4                 0x00200802U
#define GPIO_226_LINA_RX                0x00200803U    // newly added
#define GPIO_226_EPWM6_A                0x00200805U    // newly added
#define GPIO_226_SPIA_CLK               0x00200806U    // newly added
#define GPIO_226_FSITX2_CLK             0x00200807U    // newly added
#define GPIO_226_EPWM1_B                0x00200809U    // newly added
#define GPIO_226_TIMER4_CH3             0x0020080AU    // newly added
#define GPIO_226_EQEP1_STROBE           0x0020080BU    // newly added
#define GPIO_226_ADCE_EXTMUXSEL1        0x0020080DU    // newly added
#define GPIO_226_UART3_RX               0x0020080EU    // newly added
#define GPIO_226_HIC_A1                 0x0020080FU    // CSPI5

#define GPIO_227_GPIO227                0x00200C00U
#define GPIO_227_I2CB_SCL               0x00200C01U    // newly added
#define GPIO_227_SD1_C3                 0x00200C02U
#define GPIO_227_EPWM3_A                0x00200C03U    // newly added
#define GPIO_227_OUTPUTXBAR1            0x00200C05U    // newly added
#define GPIO_227_EPWM2_B                0x00200C06U    // newly added
#define GPIO_227_FSITXB_D0              0x00200C07U    // newly added
#define GPIO_227_TIMER4_CH4             0x00200C0AU    // newly added
#define GPIO_227_UART4_TX               0x00200C0EU    // newly added
#define GPIO_227_HIC_NBE0               0x00200C0FU    // CSPI6

#define GPIO_228_GPIO228                0x00201000U
#define GPIO_228_EPWM10_A               0x00201001U    // newly added
#define GPIO_228_SD2_C1                 0x00201002U
#define GPIO_228_ADCSOCAO               0x00201003U    // newly added
#define GPIO_228_CAN2_TX                0x00201005U    // newly added
#define GPIO_228_SPIA_SOMI              0x00201006U    // newly added
#define GPIO_228_FSITXB_D1              0x00201007U    // newly added
#define GPIO_228_EPWM2_B                0x00201009U    // newly added
#define GPIO_228_TIMER5_ETR             0x0020100AU    // newly added
#define GPIO_228_EQEP1_B                0x0020100BU    // newly added
#define GPIO_228_ADCE_EXTMUXSEL0        0x0020100DU    // newly added
#define GPIO_228_UART4_RX               0x0020100EU    // newly added
#define GPIO_228_HIC_A0                 0x0020100FU    // CSPI7

#define GPIO_229_GPIO229                0x00201400U

#define GPIO_230_GPIO230                0x00201800U
#define GPIO_230_I2CB_SDA               0x00201801U    // newly added
#define GPIO_230_SD1_C4                 0x00201802U
#define GPIO_230_EPWM3_B                0x00201803U    // newly added
#define GPIO_230_CAN2_RX                0x00201805U    // newly added
#define GPIO_230_EPWM2_A                0x00201806U    // newly added
#define GPIO_230_I2CA_SDA               0x00201807U    // newly added
#define GPIO_230_I2CC_SCL               0x00201809U    // newly added
#define GPIO_230_TIMER5_CH1             0x0020180AU    // newly added
#define GPIO_230_ATIM2_CH3              0x0020180BU    // newly added
#define GPIO_230_HIC_BASESEL2           0x0020180FU    // CSPI8

#define GPIO_231_GPIO231                0x00201C00U
#define GPIO_231_SD1_C1                 0x00201C02U
#define GPIO_231_HIC_BASESEL1           0x00201C0FU    // does not exist

#define GPIO_232_GPIO232                0x00240000U
#define GPIO_232_SD1_D4                 0x00240002U
#define GPIO_232_HIC_BASESEL0           0x0024000FU    // does not exist

#define GPIO_233_GPIO233                0x00240400U    // does not exist
#define GPIO_233_SD2_D1                 0x00240402U    // does not exist
#define GPIO_233_HIC_A4                 0x0024040FU    // does not exist

#define GPIO_234_GPIO234                0x00240800U    // does not exist

#define GPIO_235_GPIO235                0x00240C00U    // does not exist

#define GPIO_236_GPIO236                0x00241000U
#define GPIO_236_EPWM7_A                0x00241001U    // newly added
#define GPIO_236_EQEP1_INDEX            0x00241005U    // newly added
#define GPIO_236_SPID_CLK               0x00241007U    // newly added
#define GPIO_236_EPWM12_A               0x00241009U    // newly added
#define GPIO_236_TIMER5_CH2             0x0024100AU    // newly added
#define GPIO_236_ATIM2_CH3N             0x0024100BU    // newly added
#define GPIO_236_CSPI9                  0x0024100FU    // newly added

#define GPIO_237_GPIO237                0x00241400U
#define GPIO_237_SD1_D2                 0x00241402U
#define GPIO_237_HIC_A6                 0x0024140FU    // does not exist

#define GPIO_238_GPIO238                0x00241800U
#define GPIO_238_SD2_C3                 0x00241802U
#define GPIO_238_HIC_NCS                0x0024180FU    // does not exist

#define GPIO_239_GPIO239                0x00241C00U
#define GPIO_239_SD1_D1                 0x00241C02U
#define GPIO_239_HIC_A5                 0x00241C0FU    // does not exist

#define GPIO_240_GPIO240                0x00280000U
#define GPIO_240_SD2_C1                 0x00280002U
#define GPIO_240_HIC_NBE1               0x0028000FU    // does not exist

#define GPIO_241_GPIO241                0x00280400U    // does not exist
#define GPIO_241_SD2_C1                 0x00280402U    // does not exist
#define GPIO_241_HIC_NBE1               0x0028040FU    // does not exist

#define GPIO_242_GPIO242                0x00280800U
#define GPIO_242_EPWM11_A               0x00280801U    // newly added
#define GPIO_242_SD2_D2                 0x00280802U
#define GPIO_242_FSITXB_TDM_CLK         0x00280803U    // newly added
#define GPIO_242_OUTPUTXBAR2            0x00280805U    // newly added
#define GPIO_242_SPIA_STE               0x00280806U    // newly added
#define GPIO_242_SPID_STE               0x00280807U    // newly added
#define GPIO_242_EPWM3_A                0x00280809U    // newly added
#define GPIO_242_CAN2_RX                0x0028080AU    // newly added
#define GPIO_242_EQEP1_INDEX            0x0028080BU    // newly added
#define GPIO_242_ADCE_EXTMUXSEL2        0x0028080DU    // newly added
#define GPIO_242_HIC_A2                 0x0028080FU    // CSPI10

#define GPIO_243_GPIO243                0x00280C00U    // does not exist

#define GPIO_244_GPIO244                0x00281000U
#define GPIO_244_SD1_D3                 0x00281002U
#define GPIO_244_HIC_A7                 0x0028100FU    // does not exist

#define GPIO_245_GPIO245                0x00281400U
#define GPIO_245_SD1_C2                 0x00281402U
#define GPIO_245_HIC_NOE                0x0028140FU    // does not exist

#define GPIO_246_GPIO246                0x00281800U    // does not exist

#define GPIO_247_GPIO247                0x00281C00U
#define GPIO_247_EPWM12_B               0x00281C01U    // newly added
#define GPIO_247_EPWM18_A               0x00281C02U    // newly added
#define GPIO_247_FSITXB_TDM_D0          0x00281C03U    // newly added
#define GPIO_247_TIMER5_CH3             0x00281C05U    // newly added
#define GPIO_247_ATIM2_CH4              0x00281C06U    // newly added
#define GPIO_247_SPID_SIMO              0x00281C07U    // newly added
#define GPIO_247_UART3_TX               0x00281C09U    // newly added
#define GPIO_247_UART4_TX               0x00281C0AU    // newly added
#define GPIO_247_CSPI11                 0x00281C0FU    // newly added

#define GPIO_248_GPIO248                0x002C0000U

#define GPIO_249_GPIO249                0x002C0400U

#define GPIO_250_GPIO250                0x002C0800U    // does not exist

#define GPIO_251_GPIO251                0x002C0C00U

#define GPIO_252_GPIO252                0x002C1000U
#define GPIO_252_SD2_C4                 0x002C1002U

#define GPIO_253_GPIO253                0x002C1400U
#define GPIO_253_EPWM12_A               0x002C1401U    // newly added
#define GPIO_253_EPWM18_B               0x002C1402U    // newly added
#define GPIO_253_FSITXB_TDM_D1          0x002C1403U    // newly added
#define GPIO_253_TIMER5_CH4             0x002C1405U    // newly added
#define GPIO_253_ATIM2_CH4N             0x002C1406U    // newly added
#define GPIO_253_SPID_SOMI              0x002C1407U    // newly added
#define GPIO_253_UART3_RX               0x002C1409U    // newly added
#define GPIO_253_UART4_RX               0x002C140AU    // newly added
#define GPIO_253_CSPI12                 0x002C140FU    // newly added

#define GPIO_254_GPIO253                0x002C1800U    // does not exist

#define GPIO_255_GPIO255                0x002C1C00U    // does not exist

#define GPIO_256_GPIO256                0x00300000U
#define GPIO_256_XFLASH_SCLK            0x00300001U    // newly added
#define GPIO_256_QSPI1_SCLK             0x00300002U    // newly added

#define GPIO_257_GPIO257                0x00300400U
#define GPIO_257_XFLASH_SSN             0x00300401U    // newly added
#define GPIO_257_QSPI1_SSN              0x00300402U    // newly added

#define GPIO_258_GPIO258                0x00300800U
#define GPIO_258_XFLASH_D0              0x00300801U    // newly added
#define GPIO_258_QSPI1_D0               0x00300802U    // newly added

#define GPIO_259_GPIO259                0x00300C00U
#define GPIO_259_XFLASH_D1              0x00300C01U    // newly added
#define GPIO_259_QSPI1_D1               0x00300C02U    // newly added

#define GPIO_260_GPIO260                0x00301000U
#define GPIO_260_XFLASH_D2              0x00301001U    // newly added
#define GPIO_260_QSPI1_D2               0x00301002U    // newly added

#define GPIO_261_GPIO261                0x00301400U
#define GPIO_261_XFLASH_D3              0x00301401U    // newly added
#define GPIO_261_QSPI1_D3               0x00301402U    // newly added

#define GPIO_262_GPIO262                0x00301800U
#define GPIO_262_HAC1                   0x00301801U    // newly added
#define GPIO_263_GPIO263                0x00301C00U
#define GPIO_263_HAC2                   0x00301C01U    // newly added
#define GPIO_264_GPIO264                0x00340000U
#define GPIO_264_HAC3                   0x00340001U    // newly added
#define GPIO_265_GPIO265                0x00340400U
#define GPIO_265_HAC4                   0x00340401U    // newly added
#define GPIO_266_GPIO266                0x00340800U
#define GPIO_266_HAC5                   0x00340801U    // newly added
#define GPIO_267_GPIO267                0x00340C00U
#define GPIO_267_HAC6                   0x00340C01U    // newly added
#define GPIO_268_GPIO268                0x00341000U
#define GPIO_268_HAC7                   0x00341001U    // newly added
#define GPIO_269_GPIO269                0x00341400U
#define GPIO_269_HAC8                   0x00341401U    // newly added
#define GPIO_270_GPIO270                0x00341800U
#define GPIO_270_HAC9                   0x00341801U    // newly added
#define GPIO_271_GPIO271                0x00341C00U
#define GPIO_271_HAC10                  0x00341C01U    // newly added
#define GPIO_272_GPIO272                0x00380000U
#define GPIO_272_HAC11                  0x00380001U    // newly added
#define GPIO_273_GPIO273                0x00380400U
#define GPIO_273_HAC12                  0x00380401U    // newly added
#define GPIO_274_GPIO274                0x00380800U
#define GPIO_274_HAC13                  0x00380801U    // newly added
#define GPIO_275_GPIO275                0x00380C00U
#define GPIO_275_HAC14                  0x00380C01U    // newly added
#define GPIO_276_GPIO276                0x00381000U
#define GPIO_276_HAC15                  0x00381001U    // newly added
#define GPIO_277_GPIO277                0x00381400U
#define GPIO_277_HAC16                  0x00381401U    // newly added
#define GPIO_278_GPIO278                0x00381800U
#define GPIO_278_HAC17                  0x00381801U    // newly added
#define GPIO_279_GPIO279                0x00381C00U
#define GPIO_279_HAC18                  0x00381C01U    // newly added
#define GPIO_280_GPIO280                0x003C0000U
#define GPIO_280_HAC19                  0x003C0001U    // newly added
#define GPIO_281_GPIO281                0x003C0400U
#define GPIO_281_HAC20                  0x003C0401U    // newly added
#define GPIO_281_CSPI1                  0x003C0402U    // newly added

#define GPIO_282_GPIO282                0x003C0800U
#define GPIO_282_HAC21                  0x003C0801U    // newly added
#define GPIO_282_CSPI2                  0x003C0802U    // newly added

#define GPIO_283_GPIO283                0x003C0C00U
#define GPIO_283_HAC22                  0x003C0C01U    // newly added
#define GPIO_283_CSPI3                  0x003C0C02U    // newly added

#define GPIO_284_GPIO284                0x003C1000U
#define GPIO_284_HAC23                  0x003C1001U    // newly added
#define GPIO_284_CSPI4                  0x003C1002U    // newly added

#define GPIO_285_GPIO285                0x003C1400U
#define GPIO_285_HAC24                  0x003C1401U    // newly added
#define GPIO_285_CSPI5                  0x003C1402U    // newly added

#define GPIO_286_GPIO286                0x003C1800U
#define GPIO_286_HAC25                  0x003C1801U    // newly added
#define GPIO_286_CSPI6                  0x003C1802U    // newly added

#define GPIO_287_GPIO287                0x003C1C00U
#define GPIO_287_HAC26                  0x003C1C01U    // newly added
#define GPIO_287_CSPI7                  0x003C1C02U    // newly added

#define GPIO_288_GPIO288                0x00400000U
#define GPIO_288_HAC27                  0x00400001U    // newly added
#define GPIO_288_CSPI8                  0x00400002U    // newly added

#define GPIO_289_GPIO289                0x00400400U
#define GPIO_289_HAC28                  0x00400401U    // newly added
#define GPIO_289_CSPI9                  0x00400402U    // newly added

#define GPIO_290_GPIO290                0x00400800U
#define GPIO_290_HAC29                  0x00400801U    // newly added
#define GPIO_290_CSPI10                 0x00400802U    // newly added

#define GPIO_291_GPIO291                0x00400C00U
#define GPIO_291_HAC30                  0x00400C01U    // newly added
#define GPIO_291_CSPI11                 0x00400C02U    // newly added

#define GPIO_292_GPIO292                0x00401000U
#define GPIO_292_HAC31                  0x00401001U    // newly added
#define GPIO_292_CSPI12                 0x00401002U    // newly added

#define GPIO_293_GPIO293                0x00401400U
#define GPIO_293_HAC32                  0x00401401U    // newly added
#define GPIO_294_GPIO294                0x00401800U
#define GPIO_294_HAC33                  0x00401801U    // newly added
#define GPIO_295_GPIO295                0x00401C00U
#define GPIO_295_HAC34                  0x00401C01U    // newly added
#define GPIO_296_GPIO296                0x00440000U
#define GPIO_296_HAC35                  0x00440001U    // newly added
#define GPIO_297_GPIO297                0x00440400U
#define GPIO_297_HAC36                  0x00440401U    // newly added
#define GPIO_298_GPIO298                0x00440800U
#define GPIO_298_HAC37                  0x00440801U    // newly added
#define GPIO_299_GPIO299                0x00440C00U
#define GPIO_299_HAC38                  0x00440C01U    // newly added
#define GPIO_300_GPIO300                0x00441000U
#define GPIO_300_HAC39                  0x00441001U    // newly added
#define GPIO_301_GPIO301                0x00441400U
#define GPIO_301_HAC40                  0x00441401U    // newly added
#define GPIO_302_GPIO302                0x00441800U
#define GPIO_302_HAC41                  0x00441801U    // newly added
#define GPIO_303_GPIO303                0x00441C00U
#define GPIO_303_HAC42                  0x00441C01U    // newly added
#define GPIO_304_GPIO304                0x00480000U
#define GPIO_304_HAC43                  0x00480001U    // newly added
#define GPIO_305_GPIO305                0x00480400U
#define GPIO_305_HAC44                  0x00480401U    // newly added
#define GPIO_306_GPIO306                0x00480800U
#define GPIO_306_HAC45                  0x00480001U    // newly added
#define GPIO_307_GPIO307                0x00480C00U
#define GPIO_307_HAC46                  0x00480C01U    // newly added
#define GPIO_308_GPIO308                0x00481000U
#define GPIO_308_HAC47                  0x00481001U    // newly added
#define GPIO_309_GPIO309                0x00481400U
#define GPIO_309_HAC48                  0x00481401U    // newly added
#define GPIO_310_GPIO310                0x00481800U
#define GPIO_310_HAC49                  0x00481801U    // newly added
#define GPIO_311_GPIO311                0x00481C00U
#define GPIO_311_HAC50                  0x00481C01U    // newly added

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __ALB32R003X_PINMAP_H


