/** 
  ************************************************************************************* 
  * @file sysctl.h 
  * @author Albatross 
  * @brief This file contains the definition of sysctl driver. 
  * @version 1.0.0 
  * @date 2025-07-30 
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
#ifndef __SYSCTL_H__
#define __SYSCTL_H__

#include "alb32r003x.h"


#define SYSCTL_BASE                 0x40000000U
#define SYSCTL                      ((SYSCTL_REGS *)SYSCTL_BASE)


// MSP1 Configuration Register
struct SYSCTL_MSPICFG_BITS {
    uint32_t    XIP_EN:1;           // 0:0     XIP Enable
    uint32_t    XIP_READ_LE:1;      // 1:1     XIP Read Little Endian
    uint32_t    NON_XIP_READ_LE:1;  // 2:2     Non-XIP Read Little Endian
    uint32_t    PSN_IC_WRITE_LE:1;  // 3:3     PSN-IC Write Little Endian
    uint32_t    rsvd1:27;           // 30:4    Reserved
    uint32_t    MSP1_XFLASH0_SEL:1; // 31:31   1:MSP1 0:XFLASH0
};

union SYSCTL_MSPICFG_REG {
    uint32_t            all;
    struct SYSCTL_MSPICFG_BITS bit;
};

// BSPI1 Configuration Register
struct SYSCTL_BSPI1CFG_BITS {
    uint32_t    MODE:1;             // 0:0     1:master 0:slave
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_BSPI1CFG_REG {
    uint32_t            all;
    struct SYSCTL_BSPI1CFG_BITS bit;
};

// BSPI2 Configuration Register (same as BSPI11)
struct SYSCTL_BSPI2CFG_BITS {
    uint32_t    MODE:1;             // 0:0     1:master 0:slave
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_BSPI2CFG_REG {
    uint32_t            all;
    struct SYSCTL_BSPI2CFG_BITS bit;
};

// BSPI3 Configuration Register (same as BSPI11)
struct SYSCTL_BSPI3CFG_BITS {
    uint32_t    MODE:1;             // 0:0     1:master 0:slave
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_BSPI3CFG_REG {
    uint32_t            all;
    struct SYSCTL_BSPI3CFG_BITS bit;
};

// BSPI34 Configuration Register (same as BSPI11)
struct SYSCTL_BSPI4CFG_BITS {
    uint32_t    MODE:1;             // 0:0     1:master 0:slave
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_BSPI4CFG_REG {
    uint32_t            all;
    struct SYSCTL_BSPI4CFG_BITS bit;
};

// CTRL_SUB Configuration Register
struct SYSCTL_CTRLSUB_CFG_BITS {
    uint32_t    AQ_ORI:1;           // 0:0     AQ Original Function
    uint32_t    PC_ORI:1;           // 1:1     PC Original Function
    uint32_t    F28X_MODE:2;        // 3:2     00:0039 mode, 01:P55 mode, 1x:P65 mode
    uint32_t    BYPASS_WIDTH:4;     // 7:4     Max width of delay chain
    uint32_t    AUXS16:8;           // 15:8    Reserved
    uint32_t    GBCLKSYNC:1;        // 16:16   EPWM Time Base Clock Global sync
    uint32_t    CPU1TBOLKSYNC:1;    // 17:17   EPWM Time Base Clock sync to CPU1
    uint32_t    CPU2TBOLKSYNC:1;    // 18:18   EPWM Time Base Clock sync to CPU2
    uint32_t    rsvd1:13;           // 31:19   Reserved
};

union SYSCTL_CTRLSUB_CFG_REG {
    uint32_t            all;
    struct SYSCTL_CTRLSUB_CFG_BITS bit;
};

//*****************************************************************************
// SMCM Configuration Register (SYSCTL_SMCMCFG)
//*****************************************************************************
// SYSCTL_SMCMCFG - SMCM Configuration Register
struct SYSCTL_SMCMCFG_BITS {
    uint32_t    HW_CONFIG_SEL:4;    // 3:0     Hardware Configuration Select
    uint32_t    rsvd1:28;           // 31:4    Reserved
};

union SYSCTL_SMCMCFG_REG {
    uint32_t            all;
    struct SYSCTL_SMCMCFG_BITS bit;
};


// CORE NMI Wake Enable Register
struct SYSCTL_CORE_NMIWK_EN_BITS {
    uint32_t    CORE1_NMI_WK_EN:1;  // 0:0     core1 nmi wake enable
    uint32_t    CORE2_NMI_WK_EN:1;  // 1:1     core2 nmi wake enable
    uint32_t    rsvd1:30;           // 31:2    Reserved
};

union SYSCTL_CORE_NMIWK_EN_REG {
    uint32_t            all;
    struct SYSCTL_CORE_NMIWK_EN_BITS bit;
};

// MTX4 Configuration Register
struct SYSCTL_MTX4CFG_BITS {
    uint32_t    REMAP:4;            // 3:0     MTX4_REMAP (0000,0010,0100)
    uint32_t    rsvd1:28;           // 31:4    Reserved
};

union SYSCTL_MTX4CFG_REG {
    uint32_t            all;
    struct SYSCTL_MTX4CFG_BITS bit;
};

// EQEP Configuration Register 1
struct SYSCTL_EQEP1CFG_BITS {
    uint32_t    EQEP1A_SEL:4;       // 3:0     eqep1a select
    uint32_t    EQEP1B_SEL:4;       // 7:4     eqep1b select
    uint32_t    EQEP1I_SEL:4;       // 11:8    eqep1i select
    uint32_t    rsvd1:23;           // 31:9   Reserved
};

union SYSCTL_EQEP1CFG_REG {
    uint32_t            all;
    struct SYSCTL_EQEP1CFG_BITS bit;
};

// EQEP Configuration Register 2
struct SYSCTL_EQEP2CFG_BITS {
    uint32_t    EQEP2A_SEL:4;       // 3:0     eqep2a select
    uint32_t    EQEP2B_SEL:4;       // 7:4     eqep2b select
    uint32_t    EQEP2I_SEL:4;       // 11:8    eqep2i select
    uint32_t    rsvd1:23;           // 31:9   Reserved
};

union SYSCTL_EQEP2CFG_REG {
    uint32_t            all;
    struct SYSCTL_EQEP2CFG_BITS bit;
};

// EQEP Configuration Register 3
struct SYSCTL_EQEP3CFG_BITS {
    uint32_t    EQEP3A_SEL:4;       // 3:0     eqep3a select
    uint32_t    EQEP3B_SEL:4;       // 7:4     eqep3b select
    uint32_t    EQEP3I_SEL:4;       // 11:8    eqep3i select
    uint32_t    rsvd1:23;           // 31:9   Reserved
};

union SYSCTL_EQEP3CFG_REG {
    uint32_t            all;
    struct SYSCTL_EQEP3CFG_BITS bit;
};


// ECAP1 Sync Select Registers
struct SYSCTL_ECAP1_SYNCSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     syncin select
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_ECAP1_SYNCSEL_REG {
    uint32_t            all;
    struct SYSCTL_ECAP1_SYNCSEL_BITS bit;
};

// ECAP2 Sync Select Registers
struct SYSCTL_ECAP2_SYNCSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     syncin select
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_ECAP2_SYNCSEL_REG {
    uint32_t            all;
    struct SYSCTL_ECAP2_SYNCSEL_BITS bit;
};

// ECAP3 Sync Select Registers
struct SYSCTL_ECAP3_SYNCSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     syncin select
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_ECAP3_SYNCSEL_REG {
    uint32_t            all;
    struct SYSCTL_ECAP3_SYNCSEL_BITS bit;
};

// ECAP4 Sync Select Registers
struct SYSCTL_ECAP4_SYNCSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     syncin select
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_ECAP4_SYNCSEL_REG {
    uint32_t            all;
    struct SYSCTL_ECAP4_SYNCSEL_BITS bit;
};



// TIMER Status Register
struct SYSCTL_TIMERSTAT_BITS {
    uint32_t    TIMER1_EN:2;         // 1:0     gtim1 enable
    uint32_t    TIMER2_EN:2;         // 3:2     gtim2 enable
    uint32_t    TIMER3_EN:2;         // 5:4     gtim3 enable
    uint32_t    TIMER4_EN:2;         // 7:6     gtim4 enable
    uint32_t    rsvd1:24;           // 31:8    Reserved
};

union SYSCTL_TIMERSTAT_REG {
    uint32_t            all;
    struct SYSCTL_TIMERSTAT_BITS bit;
};

// EPWM1 Sync In Select Register
struct SYSCTL_EPWM1_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM1 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM1_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM1_SYNCINSEL_BITS bit;
};

// EPWM2 Sync In Select Register
struct SYSCTL_EPWM2_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM2 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM2_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM2_SYNCINSEL_BITS bit;
};

// EPWM3 Sync In Select Register
struct SYSCTL_EPWM3_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM3 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM3_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM3_SYNCINSEL_BITS bit;
};

// EPWM4 Sync In Select Register
struct SYSCTL_EPWM4_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM4 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM4_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM4_SYNCINSEL_BITS bit;
};

// EPWM5 Sync In Select Register
struct SYSCTL_EPWM5_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM5 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM5_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM5_SYNCINSEL_BITS bit;
};

// EPWM6 Sync In Select Register
struct SYSCTL_EPWM6_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM6 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM6_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM6_SYNCINSEL_BITS bit;
};

// EPWM7 Sync In Select Register
struct SYSCTL_EPWM7_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM7 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM7_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM7_SYNCINSEL_BITS bit;
};

// EPWM8 Sync In Select Register
struct SYSCTL_EPWM8_SYNCINSEL_BITS {
    uint32_t    SYNCIN_SEL:7;       // 6:0     EPWM8 syncin source select (0x00 disable)
    uint32_t    rsvd1:25;           // 31:7    Reserved
};

union SYSCTL_EPWM8_SYNCINSEL_REG {
    uint32_t            all;
    struct SYSCTL_EPWM8_SYNCINSEL_BITS bit;
};


// ADC SOC A Out Select Register
struct SYSCTL_ADCSOCA_OUTSELECT_BITS {
    uint32_t    PWM1_SOCA_EN:1;     // 0:0     PWM1 SOCA enable
    uint32_t    PWM2_SOCA_EN:1;     // 1:1     PWM2 SOCA enable
    uint32_t    PWM3_SOCA_EN:1;     // 2:2     PWM3 SOCA enable
    uint32_t    PWM4_SOCA_EN:1;     // 3:3     PWM4 SOCA enable
    uint32_t    PWM5_SOCA_EN:1;     // 4:4     PWM5 SOCA enable
    uint32_t    PWM6_SOCA_EN:1;     // 5:5     PWM6 SOCA enable
    uint32_t    PWM7_SOCA_EN:1;     // 6:6     PWM7 SOCA enable
    uint32_t    PWM8_SOCA_EN:1;     // 7:7     PWM8 SOCA enable
    uint32_t    rsvd1:24;           // 31:8    Reserved
};

union SYSCTL_ADCSOCA_OUTSELECT_REG {
    uint32_t            all;
    struct SYSCTL_ADCSOCA_OUTSELECT_BITS bit;
};

// ADC SOC B Out Select Register
struct SYSCTL_ADCSOCB_OUTSELECT_BITS {
    uint32_t    PWM1_SOCB_EN:1;     // 0:0     PWM1 SOCB enable
    uint32_t    PWM2_SOCB_EN:1;     // 1:1     PWM2 SOCB enable
    uint32_t    PWM3_SOCB_EN:1;     // 2:2     PWM3 SOCB enable
    uint32_t    PWM4_SOCB_EN:1;     // 3:3     PWM4 SOCB enable
    uint32_t    PWM5_SOCB_EN:1;     // 4:4     PWM5 SOCB enable
    uint32_t    PWM6_SOCB_EN:1;     // 5:5     PWM6 SOCB enable
    uint32_t    PWM7_SOCB_EN:1;     // 6:6     PWM7 SOCB enable
    uint32_t    PWM8_SOCB_EN:1;     // 7:7     PWM8 SOCB enable
    uint32_t    rsvd1:24;           // 31:8   Reserved
};

union SYSCTL_ADCSOCB_OUTSELECT_REG {
    uint32_t            all;
    struct SYSCTL_ADCSOCB_OUTSELECT_BITS bit;
};

// HRPWM Clock Enable Register
struct SYSCTL_EPWMPCLKCRO_BITS {
    uint32_t    CLKEN_HRPWM:1;      // 0:0     1:enable HRPWM clock, 0:disable
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_EPWMPCLKCRO_REG {
    uint32_t            all;
    struct SYSCTL_HRPWM_CLKEN_BITS bit;
};

// Sync Out Select Register
struct SYSCTL_SYNOSELECT_BITS {
    uint32_t    rsvd1:24;           // 23:0    Reserved
    uint32_t    SYNCOUTSEL:5;       // 28:24     Syncout source select
    uint32_t    rsvd2:3;           // 31:29    Reserved
};

union SYSCTL_SYNOSELECT_REG {
    uint32_t            all;
    struct SYSCTL_SYNOSELECT_BITS bit;
};

// Boot Mode Register
struct SYSCTL_BOOT_MODE_BITS {
    uint32_t    SYSCTL_BOOT_MODE:6;        // 5:0     Boot mode from GPIO pins
    uint32_t    rsvd1:26;           // 31:6    Reserved
};

union SYSCTL_BOOT_MODE_REG {
    uint32_t            all;
    struct SYSCTL_BOOT_MODE_BITS bit;
};

// Debug Configuration Register
struct SYSCTL_DBGCFG_BITS {
    uint32_t    DEBUG_MODE:1;       // 0:0     debug mode
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_DBGCFG_REG {
    uint32_t            all;
    struct SYSCTL_DBGCFG_BITS bit;
};

// LPM Configuration Register
struct SYSCTL_LPMCFG_BITS {
    uint32_t    EXTI_WAKEUP_EN:1;   // 0:0     external interrupt wakeup enable
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_LPMCFG_REG {
    uint32_t            all;
    struct SYSCTL_LPMCFG_BITS bit;
};

// DCC Configuration Register
struct SYSCTL_DCC_CFGR_BITS {
    uint32_t    DCC_NMI_IRQ_EN:1;   // 0:0     dcc nmi interrupt enable
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_DCC_CFGR_REG {
    uint32_t            all;
    struct SYSCTL_DCC_CFGR_BITS bit;
};

// Analog Internal Test Control Register
struct SYSCTL_INTERNALTESTCTL_BITS {
    uint32_t    TEST_CTL:5;         // 4:0     Internal test control (write requires 0xA5A5 in high 16 bits)
    uint32_t    rsvd1:27;           // 31:5    Reserved
};

union SYSCTL_INTERNALTESTCTL_REG {
    uint32_t            all;
    struct SYSCTL_INTERNALTESTCTL_BITS bit;
};

// Analog Configuration Lock Register
struct SYSCTL_CONFIGLOCK_BITS {
    uint32_t    LOCK:5;             // 4:0     Configuration lock (write once)
    uint32_t    rsvd1:27;           // 31:5    Reserved
};

union SYSCTL_CONFIGLOCK_REG {
    uint32_t            all;
    struct SYSCTL_CONFIGLOCK_BITS bit;
};

// Temperature Sensor Control Register
struct SYSCTL_TSNSCTL_BITS {
    uint32_t    TSNS_EN:1;          // 0:0     Temperature sensor enable
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_TSNSCTL_REG {
    uint32_t            all;
    struct SYSCTL_TSNSCTL_BITS bit;
};

// Analog Reference Control Register
struct SYSCTL_ANAREFCTL_BITS {
    uint32_t    ANAREFCTL:11;      // 10:0     
    uint32_t    rsvd1:21;            // 31:11    Reserved
};

union SYSCTL_ANAREFCTL_REG {
    uint32_t            all;
    struct SYSCTL_ANAREFCTL_BITS bit;
};

// Voltage Monitor Control Register
struct SYSCTL_VMONCTL_BITS {
    uint32_t    BORL_EN:9;          // 8:0     BORL monitor VDDIO enable
    uint32_t    rsvd1:23;           // 31:9    Reserved
};

union SYSCTL_VMONCTL_REG {
    uint32_t            all;
    struct SYSCTL_VMONCTL_BITS bit;
};

// Comparator Positive High MUX Select Register
struct SYSCTL_CMPHPMXSEL_BITS {
    uint32_t    SEL:12;              // 11:0     CMPHPMXSEL control signal
    uint32_t    rsvd1:20;           // 31:12    Reserved
};

union SYSCTL_CMPHPMXSEL_REG {
    uint32_t            all;
    struct SYSCTL_CMPHPMXSEL_BITS bit;
};

// Comparator Positive Low MUX Select Register
struct SYSCTL_CMPLPMXSEL_BITS {
    uint32_t    SEL:12;              // 11:0     CMPLPMXSEL control signal
    uint32_t    rsvd1:20;           // 31:12    Reserved
};

union SYSCTL_CMPLPMXSEL_REG {
    uint32_t            all;
    struct SYSCTL_CMPLPMXSEL_BITS bit;
};

// Comparator Negative High MUX Select Register
struct SYSCTL_CMPHNMXSEL_BITS {
    uint32_t    SEL:4;              // 3:0     CMPHNMXSEL control signal
    uint32_t    rsvd1:28;           // 31:4    Reserved
};

union SYSCTL_CMPHNMXSEL_REG {
    uint32_t            all;
    struct SYSCTL_CMPHNMXSEL_BITS bit;
};

// Comparator Negative Low MUX Select Register
struct SYSCTL_CMPLNMXSEL_BITS {
    uint32_t    SEL:4;              // 3:0     CMPLNMXSEL control signal
    uint32_t    rsvd1:28;           // 31:4    Reserved
};

union SYSCTL_CMPLNMXSEL_REG {
    uint32_t            all;
    struct SYSCTL_CMPLNMXSEL_BITS bit;
};

// ADC DAC Loopback Control Register
struct SYSCTL_ADCDACLOOPBACK_BITS {
    uint32_t    LOOPBACK_EN:3;      // 2:0     ADC DAC loopback enable (write requires 0xA5A5 in high 16 bits)
    uint32_t    rsvd1:29;           // 31:3    Reserved
};

union SYSCTL_ADCDACLOOPBACK_REG {
    uint32_t            all;
    struct SYSCTL_ADCDACLOOPBACK_BITS bit;
};



// Analog Lock Register
struct SYSCTL_ANALOGLOCK_BITS {
    uint32_t    LOCK:10;             // 9:0     Analog lock
    uint32_t    rsvd1:22;           // 31:10    Reserved
};

union SYSCTL_ANALOGLOCK_REG {
    uint32_t            all;
    struct SYSCTL_ANALOGLOCK_BITS bit;
};

// AGPIO Control Register A
struct SYSCTL_AGPIOCTRLA_BITS {
    uint32_t    AGPIOCTRLA:1;       // 21:0    AGPIO Control A
    uint32_t    rsvd1:10;           // 31:22   Reserved
};

union SYSCTL_AGPIOCTRLA_REG {
    uint32_t            all;
    struct SYSCTL_AGPIOCTRLA_BITS bit;
};

// Debug Control Register
struct SYSCTL_DBGCTRL_BITS {
    uint32_t    WWDT1_DBG_STOP:1;   // 0:0     wwdt1 debug watchdog stop
    uint32_t    rsvd1:1;            // 1:1     Reserved
    uint32_t    LPM_DBG_SLEEP:1;    // 2:2     lpm debug sleep mode
    uint32_t    LPM_DBG_STOP:1;     // 3:3     lpm debug stop mode
    uint32_t    LPM_DBG_STANDBY:1;  // 4:4     lpm debug standby mode
    uint32_t    rsvd2:27;           // 31:5    Reserved
};

union SYSCTL_DBGCTRL_REG {
    uint32_t            all;
    struct SYSCTL_DBGCTRL_BITS bit;
};

// SMCM Hardware Interrupt Register
struct SYSCTL_SMCM_HWINT_BITS {
    uint32_t    HW_INT:8;           // 7:0     SMCM hardware interrupt
    uint32_t    rsvd1:24;           // 31:8    Reserved
};

union SYSCTL_SMCM_HWINT_REG {
    uint32_t            all;
    struct SYSCTL_SMCM_HWINT_BITS bit;
};

// Timer Prescaler Register for Timer 1 (TIMER1)
struct SYSCTL_TIMER1_PRESC_BITS {
    uint32_t    TIMER1_CH1_PRESCALE:4;     // 15:0     Channel 1 prescale
    uint32_t    TIMER1_CH2_PRESCALE:4;     // 31:16     Channel 2 prescale
};

union SYSCTL_TIMER1_PRESC_REG {
    uint32_t            all;
    struct SYSCTL_TIMER1_PRESC_BITS bit;
};

// Timer Prescaler Register for Timer 2 (TIMER2)
struct SYSCTL_TIMER2_PRESC_BITS {
    uint32_t    TIMER2_CH1_PRESCALE:4;     // 15:0     Channel 1 prescale
    uint32_t    TIMER1_CH2_PRESCALE:4;     // 31:16     Channel 2 prescale
};

union TIMER2_PRESC_REG {
    uint32_t            all;
    struct SYSCTL_TIMER2_PRESC_BITS bit;
};

// Timer Prescaler Register for Timer 3 (TIMER3)
struct SYSCTL_TIMER3_PRESC_BITS {
    uint32_t    TIMER2_CH1_PRESCALE:4;     // 15:0     Channel 1 prescale
    uint32_t    TIMER2_CH2_PRESCALE:4;     // 31:16     Channel 2 prescale
};

union TIMER2_PRESC_REG {
    uint32_t            all;
    struct SYSCTL_TIMER3_PRESC_BITS bit;
};

// Timer Prescaler Register for Timer 4 (TIMER4)
struct SYSCTL_TIMER4_PRESC_BITS {
    uint32_t    TIMER3_CH1_PRESCALE:4;     // 15:0     Channel 1 prescale
    uint32_t    TIMER3_CH2_PRESCALE:4;     // 31:16     Channel 2 prescale
};

union TIMER3_PRESC_REG {
    uint32_t            all;
    struct TIMER4_PRESC_BITS bit;
};

// Timer Prescaler Register for Timer 4 (TIMER4)
struct SYSCTL_TIMER4_PRESC_BITS {
    uint32_t    TIMER4_CH1_PRESCALE:4;     // 15:0     Channel 1 prescale
    uint32_t    TIMER4_CH2_PRESCALE:4;     // 31:16     Channel 2 prescale
};

union SYSCTL_TIMER4_PRESC_REG {
    uint32_t            all;
    struct SYSCTL_TIMER4_PRESC_BITS bit;
};

// Option Byte Select Register
struct SYSCTL_OBSEL_BITS {
    uint32_t    OPTION_BYTE_SEL:1;  // 0:0     0:EFLASH/XFLASH, 1:SYSCTL
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_OBSEL_REG {
    uint32_t            all;
    struct SYSCTL_OBSEL_BITS bit;
};

// Option Byte Register  
struct SYSCTL_OPTION_BYTE0_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE0_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE0_BITS bit;
};

struct SYSCTL_OPTION_BYTE1_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE1_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE1_BITS bit;
};

struct SYSCTL_OPTION_BYTE2_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE2_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE2_BITS bit;
};

struct SYSCTL_OPTION_BYTE3_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE3_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE3_BITS bit;
};

struct SYSCTL_OPTION_BYTE4_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE4_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE4_BITS bit;
};

struct SYSCTL_OPTION_BYTE5_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE5_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE5_BITS bit;
};

struct SYSCTL_OPTION_BYTE6_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE6_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE6_BITS bit;
};

struct SYSCTL_OPTION_BYTE7_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE7_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE7_BITS bit;
};

struct SYSCTL_OPTION_BYTE8_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE8_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE8_BITS bit;
};

struct SYSCTL_OPTION_BYTE9_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE9_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE9_BITS bit;
};

struct SYSCTL_OPTION_BYTE10_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE10_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE10_BITS bit;
};

struct SYSCTL_OPTION_BYTE11_BITS {
    uint32_t    VALUE:32;           // 31:0    Option byte value
};

union SYSCTL_OPTION_BYTE11_REG {
    uint32_t            all;
    struct SYSCTL_OPTION_BYTE11_BITS bit;
};



// Watchdog Speedup Register
struct SYSCTL_WDT_SPEEDUP_BITS {
    uint32_t    SPEED_UP:1;         // 0:0     Watchdog speedup control
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_WDT_SPEEDUP_REG {
    uint32_t            all;
    struct SYSCTL_WDT_SPEEDUP_BITS bit;
};

// SMCM ECC Error Register
struct SYSCTL_SMCM_ECCERR_BITS {
    uint32_t    ECC_ERR:18;          // 17:0     SMCM mem ECC error indication
    uint32_t    rsvd1:14;            // 31:18    Reserved
};

union SYSCTL_SMCM_ECCERR_REG {
    uint32_t            all;
    struct SYSCTL_SMCM_ECCERR_BITS bit;
};

// Sync SOC Lock Register
struct SYSCTL_SYNCSOCLOCK_BITS {
    uint32_t    ADCSOCOUTSELECT_LOCK:1;       // 0:0     ADCSOCOUTSELECT register lock
    uint32_t    SYNCSELECT_LOCK:1;            // 1:1     SYNCSOC register lock
    uint32_t    rsvd1:31;                     // 31:2    Reserved
};

union SYSCTL_SYNCSOCLOCK_REG {
    uint32_t            all;
    struct SYSCTL_SYNCSOCLOCK_BITS bit;
};


// Error Status Register
struct SYSCTL_ERRORSTS_BITS {
    uint32_t    ERROR:1;            // 0:0     Error status
    uint32_t    PINSTS:1;           // 1:1     Pin status
    uint32_t    rsvd1:30;           // 31:2    Reserved
};

union SYSCTL_ERRORSTS_REG {
    uint32_t            all;
    struct SYSCTL_ERRORSTS_BITS bit;
};

// Error Status Clear Register
struct SYSCTL_ERRORSTSCLR_BITS {
    uint32_t    CLR:1;              // 0:0     Clear error status
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_ERRORSTSCLR_REG {
    uint32_t            all;
    struct SYSCTL_ERRORSTSCLR_BITS bit;
};

// Error Status Force Register
struct SYSCTL_ERRORSTSFRC_BITS {
    uint32_t    FRC:1;              // 0:0     Force error status
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_ERRORSTSFRC_REG {
    uint32_t            all;
    struct SYSCTL_ERRORSTSFRC_BITS bit;
};

// Error Control Register
struct SYSCTL_ERRORCTL_BITS {
    uint32_t    ERROR_POL_SEL:1;    // 0:0     Error polarity selection
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_ERRORCTL_REG {
    uint32_t            all;
    struct SYSCTL_ERRORCTL_BITS bit;
};

// Error Lock Register
struct SYSCTL_ERRORLOCK_BITS {
    uint32_t    LOCK:1;             // 0:0     Error control register lock
    uint32_t    rsvd1:31;           // 31:1    Reserved
};

union SYSCTL_ERRORLOCK_REG {
    uint32_t            all;
    struct SYSCTL_ERRORLOCK_BITS bit;
};

// CMPSS Configuration Register
struct SYSCTL_CMPSSCFG_BITS {
    uint32_t    CMPSS1_CLK_HP:4;    // 3:0     CMPSS1 clock high period
    uint32_t    CMPSS2_CLK_HP:4;    // 7:4     CMPSS2 clock high period
    uint32_t    CMPSS3_CLK_HP:4;    // 11:8    CMPSS3 clock high period
    uint32_t    CMPSS4_CLK_HP:4;    // 15:12   CMPSS4 clock high period
    uint32_t    rsvd1:16;           // 31:16   Reserved
};

union SYSCTL_CMPSSCFG_REG {
    uint32_t            all;
    struct SYSCTL_CMPSSCFG_BITS bit;
};



// DACC Configuration Register
struct SYSCTL_DACCCFG_BITS {
    uint32_t    DAC1_CLK_HP:4;      // 3:0     DAC1 clock high period
    uint32_t    DAC2_CLK_HP:4;      // 7:4     DAC2 clock high period
    uint32_t    rsvd1:24;           // 31:8    Reserved
};

union SYSCTL_DACCCFG_REG {
    uint32_t            all;
    struct SYSCTL_DACCCFG_BITS bit;
};

// XFLASHC Control Register
struct SYSCTL_XFLASHC_CTRL_BITS {
    uint32_t    USR_OB_PEEN:1;      // 0:0     User option byte program/erase enable
    uint32_t    CIR_OB_PEEN:1;      // 1:1     Circuit option byte program/erase enable
    uint32_t    OTP_OB_PEEN:1;      // 2:2     OTP region erase enable
    uint32_t    rsvd1:29;           // 31:3    Reserved
};

union SYSCTL_XFLASHC_CTRL_REG {
    uint32_t            all;
    struct SYSCTL_XFLASHC_CTRL_BITS bit;
};

// GPIO SYSCTL_REUSE Register (x: 0~31)
struct SYSCTL_REUSE_BITS {
    uint32_t    PAD0_MUX:4;         // 3:0     PAD[8*x+0] multiplex function
    uint32_t    PAD1_MUX:4;         // 7:4     PAD[8*x+1] multiplex function
    uint32_t    PAD2_MUX:4;         // 11:8    PAD[8*x+2] multiplex function
    uint32_t    PAD3_MUX:4;         // 15:12   PAD[8*x+3] multiplex function
    uint32_t    PAD4_MUX:4;         // 19:16   PAD[8*x+4] multiplex function
    uint32_t    PAD5_MUX:4;         // 23:20   PAD[8*x+5] multiplex function
    uint32_t    PAD6_MUX:4;         // 27:24   PAD[8*x+6] multiplex function
    uint32_t    PAD7_MUX:4;         // 31:28   PAD[8*x+7] multiplex function
};

union SYSCTL_REUSE_REG {
    uint32_t            all;
    struct SYSCTL_REUSE_BITS   bit;
};
///

//*****************************************************************************
// GPIO Register Address Offset Definitions
//*****************************************************************************

// GPIO Group Definitions (32 GPIO ports per group)
#define GPIO_GROUP_0    0   // GPIO port 0-31
#define GPIO_GROUP_1    1   // GPIO port 32-63
#define GPIO_GROUP_2    2   // GPIO port 64-95
#define GPIO_GROUP_3    3   // GPIO port 96-127
#define GPIO_GROUP_4    4   // GPIO port 128-159
#define GPIO_GROUP_5    5   // GPIO port 160-191

// Maximum number of GPIO ports
#define MAX_GPIO_PORTS  192

//*****************************************************************************
// GPIO Debounce Value Register
//*****************************************************************************

// GP10x_DEBOUNCE_VAL - Debounce Counter Period Register
// Shared by 32 GPIO ports per group
struct SYSCTLGPIO_DEBOUNCE_VAL_BITS {
    uint32_t    DEBOUNCE_VAL:32;    // 31:0    Debounce counter period value
};

union SYSCTLGPIO_DEBOUNCE_VAL_REG {
    uint32_t                    all;
    struct SYSCTLGPIO_DEBOUNCE_VAL_BITS bit;
};

//*****************************************************************************
// GPIO Qualification Period Register
//*****************************************************************************

// QUAL_PRDx - Sampling Period Register(x:0~23)
// Each GPIO port occupies 8 bits
struct SYSCTLGPIO_QUAL_PRDx_BITS {
    uint32_t    PORT0_QUAL_PRD:8;   // 7:0     Port0 sampling period
    uint32_t    PORT1_QUAL_PRD:8;   // 15:8    Port1 sampling period
    uint32_t    PORT2_QUAL_PRD:8;   // 23:16   Port2 sampling period
    uint32_t    PORT3_QUAL_PRD:8;   // 31:24   Port3 sampling period
};

union SYSCTLGPIO_QUAL_PRDx_REG {
    uint32_t                    all;
    struct SYSCTLGPIO_QUAL_PRDx_BITS   bit;
};


//*****************************************************************************
// GPIO Qualification Mode Register
//*****************************************************************************

// QUAL_MODEx - Sampling Mode Register(x:0~5)
// Each GPIO port occupies 2 bits
struct SYSCTLGPIO_QUAL_MODEx_BITS {
    uint32_t    PORT0_QUAL_MODE:2;  // 1:0     Port0 sampling mode
    uint32_t    PORT1_QUAL_MODE:2;  // 3:2     Port1 sampling mode
    uint32_t    PORT2_QUAL_MODE:2;  // 5:4     Port2 sampling mode
    uint32_t    PORT3_QUAL_MODE:2;  // 7:6     Port3 sampling mode
    uint32_t    PORT4_QUAL_MODE:2;  // 9:8     Port4 sampling mode
    uint32_t    PORT5_QUAL_MODE:2;  // 11:10   Port5 sampling mode
    uint32_t    PORT6_QUAL_MODE:2;  // 13:12   Port6 sampling mode
    uint32_t    PORT7_QUAL_MODE:2;  // 15:14   Port7 sampling mode
    uint32_t    PORT8_QUAL_MODE:2;  // 17:16   Port8 sampling mode
    uint32_t    PORT9_QUAL_MODE:2;  // 19:18   Port9 sampling mode
    uint32_t    PORT10_QUAL_MODE:2; // 21:20   Port10 sampling mode
    uint32_t    PORT11_QUAL_MODE:2; // 23:22   Port11 sampling mode
    uint32_t    PORT12_QUAL_MODE:2; // 25:24   Port12 sampling mode
    uint32_t    PORT13_QUAL_MODE:2; // 27:26   Port13 sampling mode
    uint32_t    PORT14_QUAL_MODE:2; // 29:28   Port14 sampling mode
    uint32_t    PORT15_QUAL_MODE:2; // 31:30   Port15 sampling mode
};

union SYSCTLGPIO_QUAL_MODEx_REG {
    uint32_t                    all;
    struct SYSCTLGPIO_QUAL_MODEx_BITS  bit;
};


//*****************************************************************************
// GPIO Input Invert Register
//*****************************************************************************

// INPUT_INVx - Input Inversion Register (x: 0~3)
// Each GPIO port occupies 1 bit
struct SYSCTLGPIO_INPUT_INVx_BITS {
    uint32_t    PORT0_INV:1;        // 0:0     Port0 input inversion
    uint32_t    PORT1_INV:1;        // 1:1     Port1 input inversion
    uint32_t    PORT2_INV:1;        // 2:2     Port2 input inversion
    uint32_t    PORT3_INV:1;        // 3:3     Port3 input inversion
    uint32_t    PORT4_INV:1;        // 4:4     Port4 input inversion
    uint32_t    PORT5_INV:1;        // 5:5     Port5 input inversion
    uint32_t    PORT6_INV:1;        // 6:6     Port6 input inversion
    uint32_t    PORT7_INV:1;        // 7:7     Port7 input inversion
    uint32_t    PORT8_INV:1;        // 8:8     Port8 input inversion
    uint32_t    PORT9_INV:1;        // 9:9     Port9 input inversion
    uint32_t    PORT10_INV:1;       // 10:10   Port10 input inversion
    uint32_t    PORT11_INV:1;       // 11:11   Port11 input inversion
    uint32_t    PORT12_INV:1;       // 12:12   Port12 input inversion
    uint32_t    PORT13_INV:1;       // 13:13   Port13 input inversion
    uint32_t    PORT14_INV:1;       // 14:14   Port14 input inversion
    uint32_t    PORT15_INV:1;       // 15:15   Port15 input inversion
    uint32_t    PORT16_INV:1;       // 16:16   Port16 input inversion
    uint32_t    PORT17_INV:1;       // 17:17   Port17 input inversion
    uint32_t    PORT18_INV:1;       // 18:18   Port18 input inversion
    uint32_t    PORT19_INV:1;       // 19:19   Port19 input inversion
    uint32_t    PORT20_INV:1;       // 20:20   Port20 input inversion
    uint32_t    PORT21_INV:1;       // 21:21   Port21 input inversion
    uint32_t    PORT22_INV:1;       // 22:22   Port22 input inversion
    uint32_t    PORT23_INV:1;       // 23:23   Port23 input inversion
    uint32_t    PORT24_INV:1;       // 24:24   Port24 input inversion
    uint32_t    PORT25_INV:1;       // 25:25   Port25 input inversion
    uint32_t    PORT26_INV:1;       // 26:26   Port26 input inversion
    uint32_t    PORT27_INV:1;       // 27:27   Port27 input inversion
    uint32_t    PORT28_INV:1;       // 28:28   Port28 input inversion
    uint32_t    PORT29_INV:1;       // 29:29   Port29 input inversion
    uint32_t    PORT30_INV:1;       // 30:30   Port30 input inversion
    uint32_t    PORT31_INV:1;       // 31:31   Port31 input inversion
};

union SYSCTLGPIO_INPUT_INVx_REG {
    uint32_t                    all;
    struct SYSCTLGPIO_INPUT_INVx_BITS  bit;
};


//*****************************************************************************
// PAD Pull Enable Register (PEx)
//*****************************************************************************

// PEx - Pull Enable Register (x: 0~3)
// Each PAD occupies 1 bit
struct SYSCTL_PEx_BITS {
    uint32_t    PAD0_PE:1;          // 0:0     PAD0 pull enable
    uint32_t    PAD1_PE:1;          // 1:1     PAD1 pull enable
    uint32_t    PAD2_PE:1;          // 2:2     PAD2 pull enable
    uint32_t    PAD3_PE:1;          // 3:3     PAD3 pull enable
    uint32_t    PAD4_PE:1;          // 4:4     PAD4 pull enable
    uint32_t    PAD5_PE:1;          // 5:5     PAD5 pull enable
    uint32_t    PAD6_PE:1;          // 6:6     PAD6 pull enable
    uint32_t    PAD7_PE:1;          // 7:7     PAD7 pull enable
    uint32_t    PAD8_PE:1;          // 8:8     PAD8 pull enable
    uint32_t    PAD9_PE:1;          // 9:9     PAD9 pull enable
    uint32_t    PAD10_PE:1;         // 10:10   PAD10 pull enable
    uint32_t    PAD11_PE:1;         // 11:11   PAD11 pull enable
    uint32_t    PAD12_PE:1;         // 12:12   PAD12 pull enable
    uint32_t    PAD13_PE:1;         // 13:13   PAD13 pull enable
    uint32_t    PAD14_PE:1;         // 14:14   PAD14 pull enable
    uint32_t    PAD15_PE:1;         // 15:15   PAD15 pull enable
    uint32_t    PAD16_PE:1;         // 16:16   PAD16 pull enable
    uint32_t    PAD17_PE:1;         // 17:17   PAD17 pull enable
    uint32_t    PAD18_PE:1;         // 18:18   PAD18 pull enable
    uint32_t    PAD19_PE:1;         // 19:19   PAD19 pull enable
    uint32_t    PAD20_PE:1;         // 20:20   PAD20 pull enable
    uint32_t    PAD21_PE:1;         // 21:21   PAD21 pull enable
    uint32_t    PAD22_PE:1;         // 22:22   PAD22 pull enable
    uint32_t    PAD23_PE:1;         // 23:23   PAD23 pull enable
    uint32_t    PAD24_PE:1;         // 24:24   PAD24 pull enable
    uint32_t    PAD25_PE:1;         // 25:25   PAD25 pull enable
    uint32_t    PAD26_PE:1;         // 26:26   PAD26 pull enable
    uint32_t    PAD27_PE:1;         // 27:27   PAD27 pull enable
    uint32_t    PAD28_PE:1;         // 28:28   PAD28 pull enable
    uint32_t    PAD29_PE:1;         // 29:29   PAD29 pull enable
    uint32_t    PAD30_PE:1;         // 30:30   PAD30 pull enable
    uint32_t    PAD31_PE:1;         // 31:31   PAD31 pull enable
};

union SYSCTL_PEx_REG {
    uint32_t                all;
    struct SYSCTL_PEx_BITS bit;
};


//*****************************************************************************
// PAD Pull Select Register (PSx)
//*****************************************************************************

// PSx - Pull Select Register (x: 0~3)
// Each PAD occupies 1 bit
struct SYSCTL_PSx_BITS {
    uint32_t    PAD0_PS:1;          // 0:0     PAD0 pull select
    uint32_t    PAD1_PS:1;          // 1:1     PAD1 pull select
    uint32_t    PAD2_PS:1;          // 2:2     PAD2 pull select
    uint32_t    PAD3_PS:1;          // 3:3     PAD3 pull select
    uint32_t    PAD4_PS:1;          // 4:4     PAD4 pull select
    uint32_t    PAD5_PS:1;          // 5:5     PAD5 pull select
    uint32_t    PAD6_PS:1;          // 6:6     PAD6 pull select
    uint32_t    PAD7_PS:1;          // 7:7     PAD7 pull select
    uint32_t    PAD8_PS:1;          // 8:8     PAD8 pull select
    uint32_t    PAD9_PS:1;          // 9:9     PAD9 pull select
    uint32_t    PAD10_PS:1;         // 10:10   PAD10 pull select
    uint32_t    PAD11_PS:1;         // 11:11   PAD11 pull select
    uint32_t    PAD12_PS:1;         // 12:12   PAD12 pull select
    uint32_t    PAD13_PS:1;         // 13:13   PAD13 pull select
    uint32_t    PAD14_PS:1;         // 14:14   PAD14 pull select
    uint32_t    PAD15_PS:1;         // 15:15   PAD15 pull select
    uint32_t    PAD16_PS:1;         // 16:16   PAD16 pull select
    uint32_t    PAD17_PS:1;         // 17:17   PAD17 pull select
    uint32_t    PAD18_PS:1;         // 18:18   PAD18 pull select
    uint32_t    PAD19_PS:1;         // 19:19   PAD19 pull select
    uint32_t    PAD20_PS:1;         // 20:20   PAD20 pull select
    uint32_t    PAD21_PS:1;         // 21:21   PAD21 pull select
    uint32_t    PAD22_PS:1;         // 22:22   PAD22 pull select
    uint32_t    PAD23_PS:1;         // 23:23   PAD23 pull select
    uint32_t    PAD24_PS:1;         // 24:24   PAD24 pull select
    uint32_t    PAD25_PS:1;         // 25:25   PAD25 pull select
    uint32_t    PAD26_PS:1;         // 26:26   PAD26 pull select
    uint32_t    PAD27_PS:1;         // 27:27   PAD27 pull select
    uint32_t    PAD28_PS:1;         // 28:28   PAD28 pull select
    uint32_t    PAD29_PS:1;         // 29:29   PAD29 pull select
    uint32_t    PAD30_PS:1;         // 30:30   PAD30 pull select
    uint32_t    PAD31_PS:1;         // 31:31   PAD31 pull select
};

union SYSCTL_PSx_REG {
    uint32_t                all;
    struct SYSCTL_PSx_BITS bit;
};


//*****************************************************************************
// PAD Input Select Register (ISx)
//*****************************************************************************

// ISx - Input Select Register (x: 0~3)
// Each PAD occupies 1 bit
struct SYSCTL_ISx_BITS {
    uint32_t    PAD0_IS:1;          // 0:0     PAD0 input select
    uint32_t    PAD1_IS:1;          // 1:1     PAD1 input select
    uint32_t    PAD2_IS:1;          // 2:2     PAD2 input select
    uint32_t    PAD3_IS:1;          // 3:3     PAD3 input select
    uint32_t    PAD4_IS:1;          // 4:4     PAD4 input select
    uint32_t    PAD5_IS:1;          // 5:5     PAD5 input select
    uint32_t    PAD6_IS:1;          // 6:6     PAD6 input select
    uint32_t    PAD7_IS:1;          // 7:7     PAD7 input select
    uint32_t    PAD8_IS:1;          // 8:8     PAD8 input select
    uint32_t    PAD9_IS:1;          // 9:9     PAD9 input select
    uint32_t    PAD10_IS:1;         // 10:10   PAD10 input select
    uint32_t    PAD11_IS:1;         // 11:11   PAD11 input select
    uint32_t    PAD12_IS:1;         // 12:12   PAD12 input select
    uint32_t    PAD13_IS:1;         // 13:13   PAD13 input select
    uint32_t    PAD14_IS:1;         // 14:14   PAD14 input select
    uint32_t    PAD15_IS:1;         // 15:15   PAD15 input select
    uint32_t    PAD16_IS:1;         // 16:16   PAD16 input select
    uint32_t    PAD17_IS:1;         // 17:17   PAD17 input select
    uint32_t    PAD18_IS:1;         // 18:18   PAD18 input select
    uint32_t    PAD19_IS:1;         // 19:19   PAD19 input select
    uint32_t    PAD20_IS:1;         // 20:20   PAD20 input select
    uint32_t    PAD21_IS:1;         // 21:21   PAD21 input select
    uint32_t    PAD22_IS:1;         // 22:22   PAD22 input select
    uint32_t    PAD23_IS:1;         // 23:23   PAD23 input select
    uint32_t    PAD24_IS:1;         // 24:24   PAD24 input select
    uint32_t    PAD25_IS:1;         // 25:25   PAD25 input select
    uint32_t    PAD26_IS:1;         // 26:26   PAD26 input select
    uint32_t    PAD27_IS:1;         // 27:27   PAD27 input select
    uint32_t    PAD28_IS:1;         // 28:28   PAD28 input select
    uint32_t    PAD29_IS:1;         // 29:29   PAD29 input select
    uint32_t    PAD30_IS:1;         // 30:30   PAD30 input select
    uint32_t    PAD31_IS:1;         // 31:31   PAD31 input select
};

union SYSCTL_ISx_REG {
    uint32_t                all;
    struct SYSCTL_ISx_BITS bit;
};


//*****************************************************************************
// PAD Drive Register (DRx)
//*****************************************************************************

// DRx - Drive Strength Register (x: 0~6)
// Each PAD occupies 2 bits
struct SYSCTL_DRx_BITS {
    uint32_t    PAD0_DR:2;          // 1:0     PAD0 drive strength
    uint32_t    PAD1_DR:2;          // 3:2     PAD1 drive strength
    uint32_t    PAD2_DR:2;          // 5:4     PAD2 drive strength
    uint32_t    PAD3_DR:2;          // 7:6     PAD3 drive strength
    uint32_t    PAD4_DR:2;          // 9:8     PAD4 drive strength
    uint32_t    PAD5_DR:2;          // 11:10   PAD5 drive strength
    uint32_t    PAD6_DR:2;          // 13:12   PAD6 drive strength
    uint32_t    PAD7_DR:2;          // 15:14   PAD7 drive strength
    uint32_t    PAD8_DR:2;          // 17:16   PAD8 drive strength
    uint32_t    PAD9_DR:2;          // 19:18   PAD9 drive strength
    uint32_t    PAD10_DR:2;         // 21:20   PAD10 drive strength
    uint32_t    PAD11_DR:2;         // 23:22   PAD11 drive strength
    uint32_t    PAD12_DR:2;         // 25:24   PAD12 drive strength
    uint32_t    PAD13_DR:2;         // 27:26   PAD13 drive strength
    uint32_t    PAD14_DR:2;         // 29:28   PAD14 drive strength
    uint32_t    PAD15_DR:2;         // 31:30   PAD15 drive strength
};

union SYSCTL_DRx_REG {
    uint32_t                all;
    struct SYSCTL_DRx_BITS   bit;
};


//*****************************************************************************
// GPIO Analog Mode Select Register (GP103_AMSEL)
//*****************************************************************************

// GP103_AMSEL - Analog Mode Select Register
// Each PAD occupies 1 bit (only for PAD 64-95)
struct SYSCTL_GP103_AMSEL_BITS {
    uint32_t    PAD64_AM:1;         // 0:0     PAD64 analog mode
    uint32_t    PAD65_AM:1;         // 1:1     PAD65 analog mode
    uint32_t    PAD66_AM:1;         // 2:2     PAD66 analog mode
    uint32_t    PAD67_AM:1;         // 3:3     PAD67 analog mode
    uint32_t    PAD68_AM:1;         // 4:4     PAD68 analog mode
    uint32_t    PAD69_AM:1;         // 5:5     PAD69 analog mode
    uint32_t    PAD70_AM:1;         // 6:6     PAD70 analog mode
    uint32_t    PAD71_AM:1;         // 7:7     PAD71 analog mode
    uint32_t    PAD72_AM:1;         // 8:8     PAD72 analog mode
    uint32_t    PAD73_AM:1;         // 9:9     PAD73 analog mode
    uint32_t    PAD74_AM:1;         // 10:10   PAD74 analog mode
    uint32_t    PAD75_AM:1;         // 11:11   PAD75 analog mode
    uint32_t    PAD76_AM:1;         // 12:12   PAD76 analog mode
    uint32_t    PAD77_AM:1;         // 13:13   PAD77 analog mode
    uint32_t    PAD78_AM:1;         // 14:14   PAD78 analog mode
    uint32_t    PAD79_AM:1;         // 15:15   PAD79 analog mode
    uint32_t    PAD80_AM:1;         // 16:16   PAD80 analog mode
    uint32_t    PAD81_AM:1;         // 17:17   PAD81 analog mode
    uint32_t    PAD82_AM:1;         // 18:18   PAD82 analog mode
    uint32_t    PAD83_AM:1;         // 19:19   PAD83 analog mode
    uint32_t    PAD84_AM:1;         // 20:20   PAD84 analog mode
    uint32_t    PAD85_AM:1;         // 21:21   PAD85 analog mode
    uint32_t    PAD86_AM:1;         // 22:22   PAD86 analog mode
    uint32_t    PAD87_AM:1;         // 23:23   PAD87 analog mode
    uint32_t    PAD88_AM:1;         // 24:24   PAD88 analog mode
    uint32_t    PAD89_AM:1;         // 25:25   PAD89 analog mode
    uint32_t    PAD90_AM:1;         // 26:26   PAD90 analog mode
    uint32_t    PAD91_AM:1;         // 27:27   PAD91 analog mode
    uint32_t    PAD92_AM:1;         // 28:28   PAD92 analog mode
    uint32_t    PAD93_AM:1;         // 29:29   PAD93 analog mode
    uint32_t    PAD94_AM:1;         // 30:30   PAD94 analog mode
    uint32_t    PAD95_AM:1;         // 31:31   PAD95 analog mode
};

union SYSCTL_GP103_AMSEL_REG {
    uint32_t                    all;
    struct SYSCTL_GP103_AMSEL_BITS bit;
};


//*****************************************************************************
// SYSCTL Register Structure Definition
//*****************************************************************************
struct SYSCTL_REGS {
    // IOMUX multiplexing registers (0x000+4*x)
    union   SYSCTL_REUSE_REG                REUSE[32];      // Multiplex control register, 4 bits per PAD @0x000-0x07F
    
    // GPIO debounce value (0x80+4*x)
    union   SYSCTLGPIO_DEBOUNCE_VAL_REG    GPIO_DEBOUNCE_VAL[6];  // GPIO debounce period @0x080-0x098
    
    uint32_t                                rsvd1[0x1E];    // Reserved 0x09C-0x0FC
    
    // XFLASH control (Note: this offset is special)
    union   SYSCTL_XFLASHC_REG              XFLASHC;        // XFLASH control register @0x0C0
    
    uint32_t                                rsvd2[0xD];     // Reserved 0x0C4-0x0FC
    
    // 0x100 region - Note: multiple IPs use same offset, may be in different banks
    union   SYSCTL_MSPICFG_REG              MSPI_CFG;       // MSPI configuration register @0x100
    union   SYSCTL_SMCMCFG_REG              SMCM_CFG;       // SMCM configuration register @0x100 (may be in different bank)
    union   SYSCTL_SMCM_HWINT_REG           SMCM_HWINT;     // SMCM hardware interrupt @0x104
    union   SYSCTL_SMCM_ECCERR_REG          SMCM_ECCERR;    // SMCM ECC error @0x108
    
    uint32_t                                rsvd3[0xD];     // Reserved 0x10C-0x13C
    
    // BSP configuration registers
    union   SYSCTL_BSP11CFG_REG             BSP11_CFG;      // BSP11 configuration @0x140
    union   SYSCTL_BSP12CFG_REG             BSP12_CFG;      // BSP12 configuration @0x144
    union   SYSCTL_BSP13CFG_REG             BSP13_CFG;      // BSP13 configuration @0x148
    union   SYSCTL_BSP14CFG_REG             BSP14_CFG;      // BSP14 configuration @0x14C
    
    uint32_t                                rsvd4[0xC];     // Reserved 0x150-0x17C
    
    // CTRL_SUB configuration
    union   SYSCTL_CTRLSUB_CFG_REG          CTRL_SUB_CFG;   // CTRL_SUB configuration @0x180
    
    uint32_t                                rsvd5[0x1E];    // Reserved 0x184-0x1FC
    
    // GORE2 and N310 related
    uint32_t                                GORE2_CFG4;     // GORE2 configuration 4 @0x200
    uint32_t                                GORE2_CFG2;     // GORE2 configuration 2 @0x204
    union   SYSCTL_CORE_NMIWK_EN_REG        CORE_NMI_WK_EN; // Core NMI wake enable @0x208
    
    uint32_t                                rsvd6[0xD];     // Reserved 0x20C-0x23C
    
    // MATRIX4 configuration
    union   SYSCTL_MTX4CFG_REG              MTX4_CFG;       // MTX4 configuration @0x240
    
    uint32_t                                rsvd7[0xF];     // Reserved 0x244-0x27C
    
    // EQEP configuration
    union   SYSCTL_EQEP1CFG_REG             EQEP1_CFG;      // EQEP1 configuration @0x280
    union   SYSCTL_EQEP2CFG_REG             EQEP2_CFG;      // EQEP2 configuration @0x284
    union   SYSCTL_EQEP3CFG_REG             EQEP3_CFG;      // EQEP3 configuration @0x288
    
    uint32_t                                rsvd8[0xE];     // Reserved 0x28C-0x2BC
    
    // ECAP sync select
    union   SYSCTL_ECAP1_SYNCSEL_REG        ECAP1_SYNCSEL;  // ECAP1 sync select @0x2C0
    union   SYSCTL_ECAP2_SYNCSEL_REG        ECAP2_SYNCSEL;  // ECAP2 sync select @0x2C4
    union   SYSCTL_ECAP3_SYNCSEL_REG        ECAP3_SYNCSEL;  // ECAP3 sync select @0x2C8
    union   SYSCTL_ECAP4_SYNCSEL_REG        ECAP4_SYNCSEL;  // ECAP4 sync select @0x2CC
    
    uint32_t                                rsvd9[0xC];     // Reserved 0x2D0-0x2FC
    
    // Timer related
    union   SYSCTL_TIMERSTAT_REG            TIMERx_STAT;     // Timer status @0x300
    union   SYSCTL_DBG_CTRL_REG             DBG_CTRL;       // Debug control @0x304
    
    // Timer prescaler
    union   SYSCTL_TIMER1_PRESC_REG         TIMER1_PRESC;    // TIMER1 prescaler @0x308
    union   SYSCTL_TIMER2_PRESC_REG         TIMER2_PRESC;    // TIMER2 prescaler @0x30C
    union   SYSCTL_TIMER3_PRESC_REG         TIMER3_PRESC;    // TIMER3 prescaler @0x310
    union   SYSCTL_TIMER4_PRESC_REG         TIMER4_PRESC;    // TIMER4 prescaler @0x314
    
    uint32_t                                rsvd10[0xB];    // Reserved 0x318-0x33C
    
    // EPWM sync input select (0x340+4x)
    union   SYSCTL_EPWM1_SYNCINSEL_REG      EPWM1SYNC_INSEL;  // EPWM1 sync input @0x340
    union   SYSCTL_EPWM2_SYNCINSEL_REG      EPWM2SYNC_INSEL;  // EPWM2 sync input @0x344
    union   SYSCTL_EPWM3_SYNCINSEL_REG      EPWM3SYNC_INSEL;  // EPWM3 sync input @0x348
    union   SYSCTL_EPWM4_SYNCINSEL_REG      EPWM4SYNC_INSEL;  // EPWM4 sync input @0x34C
    union   SYSCTL_EPWM5_SYNCINSEL_REG      EPWM5SYNC_INSEL;  // EPWM5 sync input @0x350
    union   SYSCTL_EPWM6_SYNCINSEL_REG      EPWM6SYNC_INSEL;  // EPWM6 sync input @0x354
    union   SYSCTL_EPWM7_SYNCINSEL_REG      EPWM7SYNC_INSEL;  // EPWM7 sync input @0x358
    union   SYSCTL_EPWM8_SYNCINSEL_REG      EPWM8SYNC_INSEL;  // EPWM8 sync input @0x35C
    uint32_t                                EPWM9SYNC_INSEL;  // EPWM9 sync input @0x360
    uint32_t                                EPWM10SYNC_INSEL; // EPWM10 sync input @0x364
    uint32_t                                EPWM11SYNC_INSEL; // EPWM11 sync input @0x368
    uint32_t                                EPWM12SYNC_INSEL; // EPWM12 sync input @0x36C
    
    // EPWM SOC and clock control
    union   SYSCTL_ADCSOCA_OUTSELECT_REG     ADCSOCAOUTSELECT;  // ADC SOCA output select @0x370
    union   SYSCTL_ADCSOCB_OUTSELECT_REG     ADCSOCBOUTSELECT;  // ADC SOCB output select @0x374
    union   SYSCTL_EPWMPCLKCRO_REG            POLKCRO;           // HRPWM clock enable @0x378
    union   SYSCTL_SYNOSELECT_REG           SYNOSELECT;        // Sync output select @0x37C
    
    // Boot mode and related
    union   SYSCTL_BOOT_MODE_REG            BOOT_MODE;         // Boot mode @0x380
    union   SYSCTL_ADCSOCOUTSELECT_REG      ADCSOCOUTSELECT;   // ADC SOC output select @0x380
    union   SYSCTL_SYNCSOCLOCK_REG          SYNCSOCLOCK;       // Sync SOC lock @0x380
    
    uint32_t                                rsvd11[0x1F];     // Reserved 0x384-0x3FC
    
    // Debug configuration
    union   SYSCTL_DBGCFG_REG               DBG_CFG;           // Debug configuration @0x3C0
    
    uint32_t                                rsvd12[0xF];      // Reserved 0x3C4-0x3FC
    
    // LPM configuration
    union   SYSCTL_LPMCFG_REG               LPM_CFG;           // Low power mode configuration @0x400
    
    uint32_t                                rsvd13[0xB];      // Reserved 0x404-0x42C
    
    // DCC configuration
    union   SYSCTL_DCC_CFGR_REG             DCC_CFGR;          // DCC configuration @0x440
    
    uint32_t                                rsvd16[0xF];      // Reserved 0x444-0x47C
    
    // Internal test and analog control (0x480-0x4A4)
    union   SYSCTL_INTERNALTESTCTL_REG      INTERNALTESTCTL;   // Internal test control @0x480
    union   SYSCTL_CONFIGLOCK_REG           CONFIGLOCK;        // Configuration lock @0x484
    union   SYSCTL_TSNSCTL_REG              TSNSCTL;           // Temperature sensor control @0x488
    union   SYSCTL_ANAREFCTL_REG            ANAREFCTL;         // Analog reference control @0x48C
    union   SYSCTL_VMONCTL_REG              VMONCTL;           // Voltage monitor control @0x490
    union   SYSCTL_CMPHPMXSEL_REG           CMPHPMXSEL;        // CMPHPMX select @0x494
    union   SYSCTL_CMPLPMXSEL_REG           CMPLPMXSEL;        // CMPLPMX select @0x498
    union   SYSCTL_CMPHNMXSEL_REG           CMPHNMXSEL;        // CMPHNMX select @0x49C
    union   SYSCTL_CMPLNMXSEL_REG           CMPLNMXSEL;        // CMPLNMX select @0x4A0
    union   SYSCTL_ADCDACLOOPBACK_REG       ADCDACLOOPBACK;    // ADC/DAC loopback @0x4A4
    
    // Analog submodule control
    union   SYSCTL_LOCK_REG                 LOCK;              // Lock @0x4A8
    union   SYSCTL_AGP10CTRLA_REG           AGP10CTRLA;        // AGP10 control A @0x4AC
    
    uint32_t                                rsvd17[0x3];      // Reserved 0x4B0-0x4B8
    
    // OB_SEL and option bytes
    union   SYSCTL_OBSEL_REG                OB_SEL;            // Option byte select @0x4C0
    union   SYSCTL_OPTION_BYTE0_REG         OPTION_BYTE0;      // Option byte 0 @0x4C4
    union   SYSCTL_OPTION_BYTE1_REG         OPTION_BYTE1;      // Option byte 1 @0x4C8
    union   SYSCTL_OPTION_BYTE2_REG         OPTION_BYTE2;      // Option byte 2 @0x4CC
    union   SYSCTL_OPTION_BYTE3_REG         OPTION_BYTE3;      // Option byte 3 @0x4D0
    union   SYSCTL_OPTION_BYTE4_REG         OPTION_BYTE4;      // Option byte 4 @0x4D4
    union   SYSCTL_OPTION_BYTE5_REG         OPTION_BYTE5;      // Option byte 5 @0x4D8
    union   SYSCTL_OPTION_BYTE6_REG         OPTION_BYTE6;      // Option byte 6 @0x4DC
    union   SYSCTL_OPTION_BYTE7_REG         OPTION_BYTE7;      // Option byte 7 @0x4E0
    union   SYSCTL_OPTION_BYTE8_REG         OPTION_BYTE8;      // Option byte 8 @0x4E4
    union   SYSCTL_OPTION_BYTE9_REG         OPTION_BYTE9;      // Option byte 9 @0x4E8
    union   SYSCTL_OPTION_BYTE10_REG        OPTION_BYTE10;     // Option byte 10 @0x4EC
    union   SYSCTL_OPTION_BYTE11_REG        OPTION_BYTE11;     // Option byte 11 @0x4F0
    
    uint32_t                                rsvd14[0x3];      // Reserved 0x4F4-0x4FC
    
    // WDT speed up
    union   SYSCTL_WDT_SPEEDUP_REG          WDT_SPEED_UP;      // WDT speed up @0x500
    
    uint32_t                                rsvd15[0xF];      // Reserved 0x504-0x53C
    
    // Error status and control
    union   SYSCTL_ERRORSTS_REG             ERRORSTS;          // Error status @0x540
    union   SYSCTL_ERRORSTSCLR_REG          ERRORSTSCLR;       // Error status clear @0x544
    union   SYSCTL_ERRORSTSFRC_REG          ERRORSTSFRC;       // Error status force @0x548
    union   SYSCTL_ERRORCTL_REG             ERRORCTL;          // Error control @0x54C
    union   SYSCTL_ERRORLOCK_REG            ERRORLOCK;         // Error lock @0x550
    
    uint32_t                                rsvd18[0xC];      // Reserved 0x554-0x57C
    
    // CMPSS configuration
    union   SYSCTL_CMPSSCFG_REG             CMPSS_CFG;         // CMPSS configuration @0x580
    
    uint32_t                                rsvd19[0xF];      // Reserved 0x584-0x5BC
    
    // DACC configuration
    union   SYSCTL_DACCCFG_REG              DACC_CFG;          // DACC configuration @0x5C0
    
    uint32_t                                rsvd20[0xF];      // Reserved 0x5C4-0x5FC
    
    // GPIO related registers (0x600-0x884)
    // PAD control registers (0x600+4*x)
    union   SYSCTL_PEx_REG                  PE[8];            // Pull enable (x=0~7 corresponds to 0x600-0x61C)
    
    // PSx (0x620+4*x)
    union   SYSCTL_PSx_REG                  PS[8];            // Pull select (x=0~7 corresponds to 0x620-0x63C)
    
    // ISx (0x640+4*x)
    union   SYSCTL_ISx_REG                  IS[8];            // Input mode select (x=0~7 corresponds to 0x640-0x65C)
    
    // DRx (0x660+4*x)
    union   SYSCTL_DRx_REG                  DR[8];            // Drive strength select (x=0~7 corresponds to 0x660-0x67C)
    
    uint32_t                                rsvd21[0x6E];     // Reserved 0x680-0x880
    
    // GP103 analog select
    union   SYSCTL_GP103_AMSEL_REG          GP103_AMSEL;       // GP103 analog select @0x884

};

extern volatile struct SYSCTL_REGS sysctlRegs;

#endif // __SYSCTL_H__