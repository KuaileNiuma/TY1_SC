/*
 *
 *   All rights reserved.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *  @file    regs_xbar.h
 *  @brief   
 *  Commit History
 *  20240416, Jason, add support for 1.1ES
*/


#ifndef REGS_XBAR_H
#define REGS_XBAR_H

extern volatile struct XBAR_REGS XbarRegs;

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
// XBAR Individual Register Bit Definitions:

// struct XBAR_INPUT1SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT1SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT1SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT2SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT2SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT2SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT3SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT3SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT3SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT4SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT4SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT4SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT5SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT5SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT5SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT6SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT6SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT6SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT7SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT7SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT7SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT8SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT8SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT8SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT9SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT9SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT9SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT10SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT10SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT10SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT11SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT11SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT11SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT12SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT12SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT12SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT13SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT13SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT13SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT14SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT14SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT14SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT15SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT15SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT15SELECT_BITS 		 bit;
// };

// struct XBAR_INPUT16SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_INPUT16SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_INPUT16SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT1SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT1SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT1SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT2SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT2SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT2SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT3SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT3SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT3SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT4SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT4SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT4SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT5SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT5SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT5SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT6SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT6SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT6SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT7SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT7SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT7SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT8SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT8SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT8SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT9SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT9SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT9SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT10SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT10SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT10SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT11SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT11SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT11SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT12SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT12SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT12SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT13SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT13SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT13SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT14SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT14SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT14SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT15SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT15SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT15SELECT_BITS 		 bit;
// };

// struct XBAR_PLU_INPUT16SELECT_BITS {			// bits   description
// 	uint16_t	SELECT:16;			// 15:0   
// };

// union XBAR_PLU_INPUT16SELECT_REG {
// 	uint16_t 		 all;
// 	struct XBAR_PLU_INPUT16SELECT_BITS 		 bit;
// };
struct XBARFLG1_BITS {			// bits   description
	uint32_t	CMPSS1_CTRIPL:1;			// 0:0 
	uint32_t	CMPSS1_CTRIPH:1;			// 1:1   
	uint32_t	CMPSS2_CTRIPL:1;			// 2:2   
	uint32_t	CMPSS2_CTRIPH:1;			// 3:3   
	uint32_t	CMPSS3_CTRIPL:1;			// 4:4   
	uint32_t	CMPSS3_CTRIPH:1;			// 5:5   
	uint32_t	CMPSS4_CTRIPL:1;			// 6:6   
	uint32_t	CMPSS4_CTRIPH:1;			// 7:7   
	uint32_t	CMPSS5_CTRIPL:1;			// 8:8   
	uint32_t	CMPSS5_CTRIPH:1;			// 9:9   
	uint32_t	CMPSS6_CTRIPL:1;			// 10:10   
	uint32_t	CMPSS6_CTRIPH:1;			// 11:11   
	uint32_t	CMPSS7_CTRIPL:1;			// 12:12   
	uint32_t	CMPSS7_CTRIPH:1;			// 13:13   
	uint32_t	rsvd1:1;			// 14:14   reserved
	uint32_t	rsvd2:1;			// 15:15   reserved
	uint32_t	CMPSS1_CTRIPOUTL:1;			// 16:16   
	uint32_t	CMPSS1_CTRIPOUTH:1;			// 17:17   
	uint32_t	CMPSS2_CTRIPOUTL:1;			// 18:18   
	uint32_t	CMPSS2_CTRIPOUTH:1;			// 19:19   
	uint32_t	CMPSS3_CTRIPOUTL:1;			// 20:20   
	uint32_t	CMPSS3_CTRIPOUTH:1;			// 21:21   
	uint32_t	CMPSS4_CTRIPOUTL:1;			// 22:22   
	uint32_t	CMPSS4_CTRIPOUTH:1;			// 23:23   
	uint32_t	CMPSS5_CTRIPOUTL:1;			// 24:24   
	uint32_t	CMPSS5_CTRIPOUTH:1;			// 25:25   
	uint32_t	CMPSS6_CTRIPOUTL:1;			// 26:26   
	uint32_t	CMPSS6_CTRIPOUTH:1;			// 27:27   
	uint32_t	CMPSS7_CTRIPOUTL:1;			// 28:28   
	uint32_t	CMPSS7_CTRIPOUTH:1;			// 29:29   
	uint32_t	rsvd3:1;			// 30:30   reserved
	uint32_t	rsvd4:1;			// 31:31   reserved

};


union XBARFLG1_REG {
	uint32_t 		 all;
	struct XBARFLG1_BITS 		 bit;
};

struct XBARFLG2_BITS {			// bits   description
	uint32_t	INPUT1:1;			// 0:0   
	uint32_t	INPUT2:1;			// 1:1   
	uint32_t	INPUT3:1;			// 2:2   
	uint32_t	INPUT4:1;			// 3:3   
	uint32_t	INPUT5:1;			// 4:4   
	uint32_t	INPUT6:1;			// 5:5   
	uint32_t	ADCSOCA:1;			// 6:6   
	uint32_t	ADCSOCB:1;			// 7:7   
	uint32_t	INPUT7:1;			// 8:8   
	uint32_t	INPUT8:1;			// 9:9   
	uint32_t	INPUT9:1;			// 10:10   
	uint32_t	INPUT10:1;			// 11:11   
	uint32_t	INPUT11:1;			// 12:12   
	uint32_t	INPUT12:1;			// 13:13   
	uint32_t	INPUT13:1;			// 14:14   
	uint32_t	INPUT14:1;			// 15:15   
	uint32_t	ECAP1_OUT:1;			// 16:16   
	uint32_t	ECAP2_OUT:1;			// 17:17   
	uint32_t	ECAP3_OUT:1;			// 18:18   
	uint32_t	ECAP4_OUT:1;			// 19:19   
	uint32_t	ECAP5_OUT:1;			// 20:20   
	uint32_t	ECAP6_OUT:1;			// 21:21   
	uint32_t	EXTSYNCOUT:1;			// 22:22   
	uint32_t	ADCAEVT1:1;			// 23:23   
	uint32_t	ADCAEVT2:1;			// 24:24   
	uint32_t	ADCAEVT3:1;			// 25:25   
	uint32_t	ADCAEVT4:1;			// 26:26   
	uint32_t	ADCBEVT1:1;			// 27:27   
	uint32_t	ADCBEVT2:1;			// 28:28   
	uint32_t	ADCBEVT3:1;			// 29:29   
	uint32_t	ADCBEVT4:1;			// 30:30   
	uint32_t	ADCCEVT1:1;			// 31:31   
};

union XBARFLG2_REG {
	uint32_t 		 all;
	struct XBARFLG2_BITS 		 bit;
};

struct XBARFLG3_BITS {                  // bits description
    Uint16 ADCCEVT2:1;                  // 0 Input Flag for ADCCEVT2 Signal
    Uint16 ADCCEVT3:1;                  // 1 Input Flag for ADCCEVT3 Signal
    Uint16 ADCCEVT4:1;                  // 2 Input Flag for ADCCEVT4 Signal
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:1;                     // 4 Reserved
    Uint16 rsvd3:1;                     // 5 Reserved
    Uint16 rsvd4:1;                     // 6 Reserved
    Uint16 SD1FLT1_COMPL:1;             // 7 Input Flag for SD1FLT1.COMPL Signal
    Uint16 SD1FLT1_COMPH:1;             // 8 Input Flag for SD1FLT1.COMPH Signal
    Uint16 SD1FLT2_COMPL:1;             // 9 Input Flag for SD1FLT2.COMPL Signal
    Uint16 SD1FLT2_COMPH:1;             // 10 Input Flag for SD1FLT2.COMPH Signal
    Uint16 SD1FLT3_COMPL:1;             // 11 Input Flag for SD1FLT3.COMPL Signal
    Uint16 SD1FLT3_COMPH:1;             // 12 Input Flag for SD1FLT3.COMPH Signal
    Uint16 SD1FLT4_COMPL:1;             // 13 Input Flag for SD1FLT4.COMPL Signal
    Uint16 SD1FLT4_COMPH:1;             // 14 Input Flag for SD1FLT4.COMPH Signal
    Uint16 SD2FLT1_COMPL:1;             // 15 Input Flag for SD2FLT1.COMPL Signal
    Uint16 SD2FLT1_COMPH:1;             // 16 Input Flag for SD2FLT1.COMPH Signal
    Uint16 SD2FLT2_COMPL:1;             // 17 Input Flag for SD2FLT2.COMPL Signal
    Uint16 SD2FLT2_COMPH:1;             // 18 Input Flag for SD2FLT2.COMPH Signal
    Uint16 SD2FLT3_COMPL:1;             // 19 Input Flag for SD2FLT3.COMPL Signal
    Uint16 SD2FLT3_COMPH:1;             // 20 Input Flag for SD2FLT3.COMPH Signal
    Uint16 SD2FLT4_COMPL:1;             // 21 Input Flag for SD2FLT4.COMPL Signal
    Uint16 SD2FLT4_COMPH:1;             // 22 Input Flag for SD2FLT4.COMPH Signal
    Uint16 ECAP7_OUT:1;                 // 23 Input Flag for ECAP7.OUT Signal
    Uint16 SD1FLT1_COMPZ:1;             // 24 Input Flag for SD1FLT1.COMPZ Signal
    Uint16 SD1FLT1_DRINT:1;             // 25 Input Flag for SD1FLT1.DRINT Signal
    Uint16 SD1FLT2_COMPZ:1;             // 26 Input Flag for SD1FLT2.COMPZ Signal
    Uint16 SD1FLT2_DRINT:1;             // 27 Input Flag for SD1FLT2.DRINT Signal
    Uint16 SD1FLT3_COMPZ:1;             // 28 Input Flag for SD1FLT3.COMPZ Signal
    Uint16 SD1FLT3_DRINT:1;             // 29 Input Flag for SD1FLT3.DRINT Signal
    Uint16 SD1FLT4_COMPZ:1;             // 30 Input Flag for SD1FLT4.COMPZ Signal
    Uint16 SD1FLT4_DRINT:1;             // 31 Input Flag for SD1FLT4.DRINT Signal
};

union XBARFLG3_REG {
	uint32_t 		 all;
	struct XBARFLG3_BITS 		 bit;
};

struct XBARFLG4_BITS {			// bits   description
	uint32_t	SD2FLT1_COMPZ:1;			// 0:0
	uint32_t	SD2FLT1_DRINT:1;			// 1:1
	uint32_t	SD2FLT2_COMPZ:1;			// 2:2
	uint32_t	SD2FLT2_DRINT:1;			// 3:3
	uint32_t	SD2FLT3_COMPZ:1;			// 4:4
	uint32_t	SD2FLT3_DRINT:1;			// 5:5
	uint32_t	SD2FLT4_COMPZ:1;			// 6:6
	uint32_t	SD2FLT4_DRINT:1;			// 7:7
	uint32_t	rsvd1:1;					// 8:8
	uint32_t	MCANA_FEVT0:1;				// 9:9
	uint32_t	MCANA_FEVT1:1;			// 10:10
	uint32_t	MCANA_FEVT2:1;			// 11:11
	uint32_t	PLU7_LC2_OUT0:1;			// 12:12
	uint32_t	PLU7_LC2_OUT1:1;			// 13:13
	uint32_t	PLU8_LC2_OUT0:1;			// 14:14
	uint32_t	PLU8_LC2_OUT1:1;			// 15:15
	uint32_t	PLU1_LC2_OUT0:1;			// 16:16
	uint32_t	PLU1_LC2_OUT1:1;			// 17:17
	uint32_t	PLU2_LC2_OUT0:1;			// 18:18
	uint32_t	PLU2_LC2_OUT1:1;			// 19:19
	uint32_t	PLU3_LC2_OUT0:1;			// 20:20
	uint32_t	PLU3_LC2_OUT1:1;			// 21:21
	uint32_t	PLU4_LC2_OUT0:1;			// 22:22
	uint32_t	PLU4_LC2_OUT1:1;			// 23:23
	uint32_t	PLU5_LC2_OUT0:1;			// 24:24
	uint32_t	PLU5_LC2_OUT1:1;			// 25:25
	uint32_t	PLU6_LC2_OUT0:1;			// 26:26
	uint32_t	PLU6_LC2_OUT1:1;			// 27:27
	uint32_t	ERRORSTS_IN:1;		 		// 28:28
	uint32_t	ECAT_SYNC0:1;				// 29:29
	uint32_t	ECAT_SYNC1:1;				// 30:30
	uint32_t	CPU_HALT_IN:1;				// 31:31
};

union XBARFLG4_REG {
	uint32_t 		 all;
	struct XBARFLG4_BITS 		 bit;
};

/* to be modified later */
struct XBARFLG5_BITS {			// bits   description
	uint32_t	EPWM1_TRIPOUT:1;			// 0:0
	uint32_t	EPWM2_TRIPOUT:1;			// 1:1
	uint32_t	EPWM3_TRIPOUT:1;			// 2:2
	uint32_t	EPWM4_TRIPOUT:1;			// 3:3
	uint32_t	EPWM5_TRIPOUT:1;			// 4:4
	uint32_t	EPWM6_TRIPOUT:1;			// 5:5
	uint32_t	EPWM7_TRIPOUT:1;			// 6:6
	uint32_t	EPWM8_TRIPOUT:1;			// 7:7
	uint32_t	EPWM9_TRIPOUT:1;			// 8:8
	uint32_t	EPWM10_TRIPOUT:1;			// 9:9
	uint32_t	EPWM11_TRIPOUT:1;			// 10:10
	uint32_t	EPWM12_TRIPOUT:1;			// 11:11
	uint32_t	EPWM13_TRIPOUT:1;			// 12:12
	uint32_t	EPWM14_TRIPOUT:1;			// 13:13
	uint32_t	EPWM15_TRIPOUT:1;			// 14:14
	uint32_t	EPWM16_TRIPOUT:1;			// 15:15
	uint32_t	EPWM17_TRIPOUT:1;			// 16:16
	uint32_t	EPWM18_TRIPOUT:1;			// 17:17
	uint32_t	rsvd1:12;				    // 18:29
	uint32_t	XBAR_INPUT_SEL15_OUT:1;		// 30:30
	uint32_t	XBAR_INPUT_SEL16_OUT:1;		// 31:31
};
union XBARFLG5_REG {
	uint32_t 		 all;
	struct XBARFLG5_BITS 		 bit;
};

struct XBARFLG6_BITS {			// bits   description
	uint32_t	EPWM1_DEMONTRIP:1;			// 0:0
	uint32_t	EPWM2_DEMONTRIP:1;			// 1:1
	uint32_t	EPWM3_DEMONTRIP:1;			// 2:2
	uint32_t	EPWM4_DEMONTRIP:1;			// 3:3
	uint32_t	EPWM5_DEMONTRIP:1;			// 4:4
	uint32_t	EPWM6_DEMONTRIP:1;			// 5:5
	uint32_t	EPWM7_DEMONTRIP:1;			// 6:6
	uint32_t	EPWM8_DEMONTRIP:1;			// 7:7
	uint32_t	EPWM9_DEMONTRIP:1;			// 8:8
	uint32_t	EPWM10_DEMONTRIP:1;			// 9:9
	uint32_t	EPWM11_DEMONTRIP:1;			// 10:10
	uint32_t	EPWM12_DEMONTRIP:1;			// 11:11
	uint32_t	EPWM13_DEMONTRIP:1;			// 12:12
	uint32_t	EPWM14_DEMONTRIP:1;			// 13:13
	uint32_t	EPWM15_DEMONTRIP:1;			// 14:14
	uint32_t	EPWM16_DEMONTRIP:1;			// 15:15
	uint32_t	EPWM17_DEMONTRIP:1;			// 16:16
	uint32_t	EPWM18_DEMONTRIP:1;			// 17:17
	uint32_t	rsvd1:14;				    // 18:31
};
union XBARFLG6_REG {
	uint32_t 		 all;
	struct XBARFLG6_BITS 		 bit;
};

struct XBARFLG7_BITS {			// bits   description
	uint32_t	EPWM1_DEACTIVE:1;			// 0:0
	uint32_t	EPWM2_DEACTIVE:1;			// 1:1
	uint32_t	EPWM3_DEACTIVE:1;			// 2:2
	uint32_t	EPWM4_DEACTIVE:1;			// 3:3
	uint32_t	EPWM5_DEACTIVE:1;			// 4:4
	uint32_t	EPWM6_DEACTIVE:1;			// 5:5
	uint32_t	EPWM7_DEACTIVE:1;			// 6:6
	uint32_t	EPWM8_DEACTIVE:1;			// 7:7
	uint32_t	EPWM9_DEACTIVE:1;			// 8:8
	uint32_t	EPWM10_DEACTIVE:1;			// 9:9
	uint32_t	EPWM11_DEACTIVE:1;			// 10:10
	uint32_t	EPWM12_DEACTIVE:1;			// 11:11
	uint32_t	EPWM13_DEACTIVE:1;			// 12:12
	uint32_t	EPWM14_DEACTIVE:1;			// 13:13
	uint32_t	EPWM15_DEACTIVE:1;			// 14:14
	uint32_t	EPWM16_DEACTIVE:1;			// 15:15
	uint32_t	EPWM17_DEACTIVE:1;			// 16:16
	uint32_t	EPWM18_DEACTIVE:1;			// 17:17
	uint32_t	rsvd1:14;				    // 18:31
};
union XBARFLG7_REG {
	uint32_t 		 all;
	struct XBARFLG7_BITS 		 bit;
};

struct XBARFLG8_BITS {			// bits   description
	uint32_t	EPWM1A_DB_NO_HR:1;			// 0:0
	uint32_t	EPWM1B_DB_NO_HR:1;			// 1:1
	uint32_t	EPWM2A_DB_NO_HR:1;			// 2:2
	uint32_t	EPWM2B_DB_NO_HR:1;			// 3:3
	uint32_t	EPWM3A_DB_NO_HR:1;			// 4:4
	uint32_t	EPWM3B_DB_NO_HR:1;			// 5:5
	uint32_t	EPWM4A_DB_NO_HR:1;			// 6:6
	uint32_t	EPWM4B_DB_NO_HR:1;			// 7:7
	uint32_t	EPWM5A_DB_NO_HR:1;			// 8:8
	uint32_t	EPWM5B_DB_NO_HR:1;			// 9:9
	uint32_t	EPWM6A_DB_NO_HR:1;			// 10:10
	uint32_t	EPWM6B_DB_NO_HR:1;			// 11:11
	uint32_t	EPWM7A_DB_NO_HR:1;			// 12:12
	uint32_t	EPWM7B_DB_NO_HR:1;			// 13:13
	uint32_t	EPWM8A_DB_NO_HR:1;			// 14:14
	uint32_t	EPWM8B_DB_NO_HR:1;			// 15:15
	uint32_t	EPWM9A_DB_NO_HR:1;			// 16:16
	uint32_t	EPWM9B_DB_NO_HR:1;			// 17:17
	uint32_t	EPWM10A_DB_NO_HR:1;			// 18:18
	uint32_t	EPWM10B_DB_NO_HR:1;			// 19:19
	uint32_t	EPWM11A_DB_NO_HR:1;			// 20:20
	uint32_t	EPWM11B_DB_NO_HR:1;			// 21:21
	uint32_t	EPWM12A_DB_NO_HR:1;			// 22:22
	uint32_t	EPWM12B_DB_NO_HR:1;			// 23:23
	uint32_t	EPWM13A_DB_NO_HR:1;			// 24:24
	uint32_t	EPWM13B_DB_NO_HR:1;			// 25:25
	uint32_t	EPWM14A_DB_NO_HR:1;			// 26:26
	uint32_t	EPWM14B_DB_NO_HR:1;			// 27:27
	uint32_t	EPWM15A_DB_NO_HR:1;		 	// 28:28
	uint32_t	EPWM15B_DB_NO_HR:1;			// 29:29
	uint32_t	EPWM16A_DB_NO_HR:1;			// 30:30
	uint32_t	EPWM16B_DB_NO_HR:1;			// 31:31
};
union XBARFLG8_REG {
	uint32_t 		 all;
	struct XBARFLG8_BITS 		 bit;
};

struct XBARFLG9_BITS {			// bits   description
	uint32_t	EPWM17A_DB_NO_HR:1;			// 0:0
	uint32_t	EPWM17B_DB_NO_HR:1;			// 1:1
	uint32_t	EPWM18A_DB_NO_HR:1;			// 2:2
	uint32_t	EPWM18B_DB_NO_HR:1;			// 3:3
	uint32_t	rsvd1:12;					// 4:15
	uint32_t	ADCD_EXT_MUXSEL0:1;			// 16:16
	uint32_t	ADCD_EXT_MUXSEL1:1;			// 17:17
	uint32_t	ADCD_EXT_MUXSEL2:1;			// 18:18
	uint32_t	ADCD_EXT_MUXSEL3:1;			// 19:19
	uint32_t	PLU7_LC1_OUT0:1;			// 20:20
	uint32_t	PLU7_LC1_OUT1:1;			// 21:21
	uint32_t	PLU7_LC1_OUT2:1;			// 22:22
	uint32_t	PLU7_LC1_OUT3:1;			// 23:23
	uint32_t	PLU7_LC2_OUT2:1;			// 24:24
	uint32_t	PLU7_LC2_OUT3:1;			// 25:25
	uint32_t	PLU8_LC1_OUT0:1;			// 26:26
	uint32_t	PLU8_LC1_OUT1:1;			// 27:27
	uint32_t	PLU8_LC1_OUT2:1;		 	// 28:28
	uint32_t	PLU8_LC1_OUT3:1;			// 29:29
	uint32_t	PLU8_LC2_OUT2:1;			// 30:30
	uint32_t	PLU8_LC2_OUT3:1;			// 31:31
};
union XBARFLG9_REG {
	uint32_t 		 all;
	struct XBARFLG9_BITS 		 bit;
};

struct XBARFLG10_BITS {			// bits   description
	uint32_t	EPWM1A_MINDB:1;			// 0:0
	uint32_t	EPWM1B_MINDB:1;			// 1:1
	uint32_t	EPWM2A_MINDB:1;			// 2:2
	uint32_t	EPWM2B_MINDB:1;			// 3:3
	uint32_t	EPWM3A_MINDB:1;			// 4:4
	uint32_t	EPWM3B_MINDB:1;			// 5:5
	uint32_t	EPWM4A_MINDB:1;			// 6:6
	uint32_t	EPWM4B_MINDB:1;			// 7:7
	uint32_t	EPWM5A_MINDB:1;			// 8:8
	uint32_t	EPWM5B_MINDB:1;			// 9:9
	uint32_t	EPWM6A_MINDB:1;			// 10:10
	uint32_t	EPWM6B_MINDB:1;			// 11:11
	uint32_t	EPWM7A_MINDB:1;			// 12:12
	uint32_t	EPWM7B_MINDB:1;			// 13:13
	uint32_t	EPWM8A_MINDB:1;			// 14:14
	uint32_t	EPWM8B_MINDB:1;			// 15:15
	uint32_t	EPWM9A_MINDB:1;			// 16:16
	uint32_t	EPWM9B_MINDB:1;			// 17:17
	uint32_t	EPWM10A_MINDB:1;		// 18:18
	uint32_t	EPWM10B_MINDB:1;		// 19:19
	uint32_t	EPWM11A_MINDB:1;		// 20:20
	uint32_t	EPWM11B_MINDB:1;		// 21:21
	uint32_t	EPWM12A_MINDB:1;		// 22:22
	uint32_t	EPWM12B_MINDB:1;		// 23:23
	uint32_t	EPWM13A_MINDB:1;		// 24:24
	uint32_t	EPWM13B_MINDB:1;		// 25:25
	uint32_t	EPWM14A_MINDB:1;		// 26:26
	uint32_t	EPWM14B_MINDB:1;		// 27:27
	uint32_t	EPWM15A_MINDB:1;	 	// 28:28
	uint32_t	EPWM15B_MINDB:1;		// 29:29
	uint32_t	EPWM16A_MINDB:1;		// 30:30
	uint32_t	EPWM16B_MINDB:1;		// 31:31
};
union XBARFLG10_REG {
	uint32_t 		 all;
	struct XBARFLG10_BITS 		 bit;
};

struct XBARFLG11_BITS {			// bits   description
	uint32_t	EPWM17A_MINDB:1;			// 0:0
	uint32_t	EPWM17B_MINDB:1;			// 1:1
	uint32_t	EPWM18A_MINDB:1;			// 2:2
	uint32_t	EPWM18B_MINDB:1;			// 3:3
	uint32_t	rsvd1:12;		        	// 4:15
	uint32_t	SD4FLT1_COMPZ:1;			// 16:16
	uint32_t	SD4FLT1_DRINT:1;			// 17:17
	uint32_t	SD4FLT2_COMPZ:1;			// 18:18
	uint32_t	SD4FLT2_DRINT:1;			// 19:19
	uint32_t	SD4FLT3_COMPZ:1;			// 20:20
	uint32_t	SD4FLT3_DRINT:1;			// 21:21
	uint32_t	SD4FLT4_COMPZ:1;			// 22:22
	uint32_t	SD4FLT4_DRINT:1;			// 23:23
	uint32_t	SD3FLT1_COMPZ:1;			// 24:24
	uint32_t	SD3FLT1_DRINT:1;			// 25:25
	uint32_t	SD3FLT2_COMPZ:1;			// 26:26
	uint32_t	SD3FLT2_DRINT:1;			// 27:27
	uint32_t	SD3FLT3_COMPZ:1;		 	// 28:28
	uint32_t	SD3FLT3_DRINT:1;			// 29:29
	uint32_t	SD3FLT4_COMPZ:1;			// 30:30
	uint32_t	SD3FLT4_DRINT:1;			// 31:31
};
union XBARFLG11_REG {
	uint32_t 		 all;
	struct XBARFLG11_BITS 		 bit;
};

struct XBARFLG12_BITS {			// bits   description
	uint32_t	PLU1_LC1_OUT0:1;			// 0:0
	uint32_t	PLU1_LC1_OUT1:1;			// 1:1
	uint32_t	PLU1_LC1_OUT2:1;			// 2:2
	uint32_t	PLU1_LC1_OUT3:1;			// 3:3
	uint32_t	PLU1_LC2_OUT2:1;			// 4:4
	uint32_t	PLU1_LC2_OUT3:1;			// 5:5
	uint32_t	PLU2_LC1_OUT0:1;			// 6:6
	uint32_t	PLU2_LC1_OUT1:1;			// 7:7
	uint32_t	PLU2_LC1_OUT2:1;			// 8:8
	uint32_t	PLU2_LC1_OUT3:1;			// 9:9
	uint32_t	PLU2_LC2_OUT2:1;			// 10:10
	uint32_t	PLU2_LC2_OUT3:1;			// 11:11
	uint32_t	PLU3_LC1_OUT0:1;			// 12:12
	uint32_t	PLU3_LC1_OUT1:1;			// 13:13
	uint32_t	PLU3_LC1_OUT2:1;			// 14:14
	uint32_t	PLU3_LC1_OUT3:1;			// 15:15
	uint32_t	PLU3_LC2_OUT2:1;			// 16:16
	uint32_t	PLU3_LC2_OUT3:1;			// 17:17
	uint32_t	PLU4_LC1_OUT0:1;			// 18:18
	uint32_t	PLU4_LC1_OUT1:1;			// 19:19
	uint32_t	PLU4_LC1_OUT2:1;			// 20:20
	uint32_t	PLU4_LC1_OUT3:1;			// 21:21
	uint32_t	PLU4_LC2_OUT2:1;			// 22:22
	uint32_t	PLU4_LC2_OUT3:1;			// 23:23
	uint32_t	PLU5_LC1_OUT0:1;			// 24:24
	uint32_t	PLU5_LC1_OUT1:1;			// 25:25
	uint32_t	PLU5_LC1_OUT2:1;			// 26:26
	uint32_t	PLU5_LC1_OUT3:1;			// 27:27
	uint32_t	PLU5_LC2_OUT2:1;		 	// 28:28
	uint32_t	PLU5_LC2_OUT3:1;			// 29:29
	uint32_t	PLU6_LC1_OUT0:1;			// 30:30
	uint32_t	PLU6_LC1_OUT1:1;			// 31:31
};

union XBARFLG12_REG {
	uint32_t 		 all;
	struct XBARFLG12_BITS 		 bit;
};

struct XBARFLG13_BITS {			// bits   description
	uint32_t	PLU6_LC1_OUT2:1;			// 0:0
	uint32_t	PLU6_LC1_OUT3:1;			// 1:1
	uint32_t	PLU6_LC2_OUT2:1;			// 2:2
	uint32_t	PLU6_LC2_OUT3:1;			// 3:3
	uint32_t	rsvd1:8;		        	// 4:11
	uint32_t	ADCA_EVT_MUXSEL0:1;			// 12:12
	uint32_t	ADCA_EVT_MUXSEL1:1;			// 13:13
	uint32_t	ADCA_EVT_MUXSEL2:1;			// 14:14
	uint32_t	ADCA_EVT_MUXSEL3:1;			// 15:15
	uint32_t	ADCB_EVT_MUXSEL0:1;			// 16:16
	uint32_t	ADCB_EVT_MUXSEL1:1;			// 17:17
	uint32_t	ADCB_EVT_MUXSEL2:1;			// 18:18
	uint32_t	ADCB_EVT_MUXSEL3:1;			// 19:19
	uint32_t	ADCC_EVT_MUXSEL0:1;			// 20:20
	uint32_t	ADCC_EVT_MUXSEL1:1;			// 21:21
	uint32_t	ADCC_EVT_MUXSEL2:1;			// 22:22
	uint32_t	ADCC_EVT_MUXSEL3:1;			// 23:23
	uint32_t	rsvd2:2;					// 24:25
	uint32_t	TOP_PWM_TRIP15IN:1;			// 26:26
	uint32_t	TOP_PWM_TRIP14IN:1;			// 27:27
	uint32_t	EPG_XBAR_OUT0:1;		 	// 28:28
	uint32_t	EPG_XBAR_OUT1:1;			// 29:29
	uint32_t	EPG_XBAR_OUT2:1;			// 30:30
	uint32_t	EPG_XBAR_OUT3:1;			// 31:31
};

union XBARFLG13_REG {
	uint32_t 		 all;
	struct XBARFLG13_BITS 		 bit;
};

struct XBARFLG14_BITS {			// bits   description
	uint32_t	SD3FLT1_1CEVT:1;			// 0:0
	uint32_t	SD3FLT1_2CEVT:1;			// 1:1
	uint32_t	SD3FLT2_1CEVT:1;			// 2:2
	uint32_t	SD3FLT2_2CEVT:1;			// 3:3
	uint32_t	SD3FLT3_1CEVT:1;			// 4:4
	uint32_t	SD3FLT3_2CEVT:1;			// 5:5
	uint32_t	SD3FLT4_1CEVT:1;			// 6:6
	uint32_t	SD3FLT4_2CEVT:1;			// 7:7
	uint32_t	SD4FLT1_1CEVT:1;			// 8:8
	uint32_t	SD4FLT1_2CEVT:1;			// 9:9
	uint32_t	SD4FLT2_1CEVT:1;			// 10:10
	uint32_t	SD4FLT2_2CEVT:1;			// 11:11
	uint32_t	SD4FLT3_1CEVT:1;			// 12:12
	uint32_t	SD4FLT3_2CEVT:1;			// 13:13
	uint32_t	SD4FLT4_1CEVT:1;			// 14:14
	uint32_t	SD4FLT4_2CEVT:1;			// 15:15
	uint32_t	rsvd1:1;					// 16:16
	uint32_t	XBAR_CLB_INPUT_SEL10_OUT:1;			// 17:17
	uint32_t	XBAR_CLB_INPUT_SEL11_OUT:1;			// 18:18
	uint32_t	XBAR_CLB_INPUT_SEL12_OUT:1;			// 19:19
	uint32_t	XBAR_CLB_INPUT_SEL13_OUT:1;			// 20:20
	uint32_t	XBAR_CLB_INPUT_SEL14_OUT:1;			// 21:21
	uint32_t	XBAR_CLB_INPUT_SEL7_OUT:1;			// 22:22
	uint32_t	XBAR_CLB_INPUT_SEL8_OUT:1;			// 23:23
	uint32_t	XBAR_CLB_INPUT_SEL9_OUT:1;			// 24:24
	uint32_t	MCANB_FEVT0:1;			// 25:25
	uint32_t	MCANB_FEVT1:1;			// 26:26
	uint32_t	MCANB_FEVT2:1;			// 27:27
	uint32_t	rsvd2:4;		 	// 28:31
};
union XBARFLG14_REG {
	uint32_t 		 all;
	struct XBARFLG14_BITS 		 bit;
};

struct XBARFLG15_BITS {			// bits   description
	uint32_t	rsvd1:8;			// 0:7
	uint32_t	ECAP1_TRIPOUT:1;			// 8:8
	uint32_t	ECAP2_TRIPOUT:1;			// 9:9
	uint32_t	ECAP3_TRIPOUT:1;			// 10:10
	uint32_t	ECAP4_TRIPOUT:1;			// 11:11
	uint32_t	ECAP5_TRIPOUT:1;			// 12:12
	uint32_t	ECAP6_TRIPOUT:1;			// 13:13
	uint32_t	ERAD_SEC_EVENT3:1;			// 14:14
	uint32_t	ERAD_SEC_EVENT2:1;			// 15:15
	uint32_t	ERAD_SEC_EVENT1:1;			// 16:16
	uint32_t	ERAD_SEC_EVENT0:1;			// 17:17
	uint32_t	rsvd2:4;					// 18:21
	uint32_t	ERAD_EBC_EVENT5:1;			// 22:22
	uint32_t	ERAD_EBC_EVENT4:1;			// 23:23
	uint32_t	ERAD_EBC_EVENT3:1;			// 24:24
	uint32_t	ERAD_EBC_EVENT2:1;			// 25:25
	uint32_t	rsvd3:4;					// 26:29
	uint32_t	ERAD_EBC_EVENT1:1;			// 30:30
	uint32_t	ERAD_EBC_EVENT0:1;			// 31:31
};
union XBARFLG15_REG {
	uint32_t 		 all;
	struct XBARFLG15_BITS 		 bit;
};

struct XBARFLG16_BITS {			// bits   description
	uint32_t	CMPSS9_CTRIPH:1;			// 0:0
	uint32_t	CMPSS9_CTRIPL:1;			// 1:1
	uint32_t	CMPSS9_CTRIPOUTH:1;			// 2:2
	uint32_t	CMPSS9_CTRIPOUTL:1;			// 3:3
	uint32_t	CMPSS10_CTRIPH:1;			// 4:4
	uint32_t	CMPSS10_CTRIPL:1;			// 5:5
	uint32_t	CMPSS10_CTRIPOUTH:1;		// 6:6
	uint32_t	CMPSS10_CTRIPOUTL:1;		// 7:7
	uint32_t	CMPSS11_CTRIPH:1;			// 8:8
	uint32_t	CMPSS11_CTRIPL:1;			// 9:9
	uint32_t	CMPSS11_CTRIPOUTH:1;	  	// 10:10
	uint32_t	CMPSS11_CTRIPOUTL:1;		// 11:11
	uint32_t	CMPSS12_CTRIPH:1;			// 12:12
	uint32_t	CMPSS12_CTRIPL:1;			// 13:13
	uint32_t	CMPSS12_CTRIPOUTH:1;		// 14:14
	uint32_t	CMPSS12_CTRIPOUTL:1;		// 15:15
	uint32_t	ECAP7_TRIPOUT:1;			// 16:16
	uint32_t	SD1FLT5_COMPZ:1;			// 17:17
	uint32_t	SD1FLT5_DRINT:1;			// 18:18
	uint32_t	SD1FLT5_2ECVT:1;			// 19:19
	uint32_t	SD1FLT5_1ECVT:1;			// 20:20
	uint32_t	rsvd1:11;					// 21:31
};
union XBARFLG16_REG {
	uint32_t 		 all;
	struct XBARFLG16_BITS 		 bit;
};

struct XBARCLR1_BITS {			// bits   description
	uint32_t	CMPSS1_CTRIPL:1;			// 0:0   
	uint32_t	CMPSS1_CTRIPH:1;			// 1:1   
	uint32_t	CMPSS2_CTRIPL:1;			// 2:2   
	uint32_t	CMPSS2_CTRIPH:1;			// 3:3   
	uint32_t	CMPSS3_CTRIPL:1;			// 4:4   
	uint32_t	CMPSS3_CTRIPH:1;			// 5:5   
	uint32_t	CMPSS4_CTRIPL:1;			// 6:6   
	uint32_t	CMPSS4_CTRIPH:1;			// 7:7   
	uint32_t	CMPSS5_CTRIPL:1;			// 8:8   
	uint32_t	CMPSS5_CTRIPH:1;			// 9:9   
	uint32_t	CMPSS6_CTRIPL:1;			// 10:10   
	uint32_t	CMPSS6_CTRIPH:1;			// 11:11   
	uint32_t	CMPSS7_CTRIPL:1;			// 12:12   
	uint32_t	CMPSS7_CTRIPH:1;			// 13:13   
	uint32_t	rsvd1:1;			// 14:14   reserved
	uint32_t	rsvd2:1;			// 15:15   reserved
	uint32_t	CMPSS1_CTRIPOUTL:1;			// 16:16   
	uint32_t	CMPSS1_CTRIPOUTH:1;			// 17:17   
	uint32_t	CMPSS2_CTRIPOUTL:1;			// 18:18   
	uint32_t	CMPSS2_CTRIPOUTH:1;			// 19:19   
	uint32_t	CMPSS3_CTRIPOUTL:1;			// 20:20   
	uint32_t	CMPSS3_CTRIPOUTH:1;			// 21:21   
	uint32_t	CMPSS4_CTRIPOUTL:1;			// 22:22   
	uint32_t	CMPSS4_CTRIPOUTH:1;			// 23:23   
	uint32_t	CMPSS5_CTRIPOUTL:1;			// 24:24   
	uint32_t	CMPSS5_CTRIPOUTH:1;			// 25:25   
	uint32_t	CMPSS6_CTRIPOUTL:1;			// 26:26   
	uint32_t	CMPSS6_CTRIPOUTH:1;			// 27:27   
	uint32_t	CMPSS7_CTRIPOUTL:1;			// 28:28   
	uint32_t	CMPSS7_CTRIPOUTH:1;			// 29:29   
	uint32_t	rsvd3:1;			// 30:30   reserved
	uint32_t	rsvd4:1;			// 31:31   reserved
};

union XBARCLR1_REG {
	uint32_t 		 all;
	struct XBARCLR1_BITS 		 bit;
};

struct XBARCLR2_BITS {			// bits   description
	uint32_t	INPUT1:1;			// 0:0   
	uint32_t	INPUT2:1;			// 1:1   
	uint32_t	INPUT3:1;			// 2:2   
	uint32_t	INPUT4:1;			// 3:3   
	uint32_t	INPUT5:1;			// 4:4   
	uint32_t	INPUT6:1;			// 5:5   
	uint32_t	ADCSOCA:1;			// 6:6   
	uint32_t	ADCSOCB:1;			// 7:7   
	uint32_t	INPUT7:1;			// 8:8   
	uint32_t	INPUT8:1;			// 9:9   
	uint32_t	INPUT9:1;			// 10:10   
	uint32_t	INPUT10:1;			// 11:11   
	uint32_t	INPUT11:1;			// 12:12   
	uint32_t	INPUT12:1;			// 13:13   
	uint32_t	INPUT13:1;			// 14:14   
	uint32_t	INPUT14:1;			// 15:15   
	uint32_t	ECAP1_OUT:1;			// 16:16   
	uint32_t	ECAP2_OUT:1;			// 17:17   
	uint32_t	ECAP3_OUT:1;			// 18:18   
	uint32_t	ECAP4_OUT:1;			// 19:19   
	uint32_t	ECAP5_OUT:1;			// 20:20   
	uint32_t	ECAP6_OUT:1;			// 21:21   
	uint32_t	EXTSYNCOUT:1;			// 22:22   
	uint32_t	ADCAEVT1:1;			// 23:23   
	uint32_t	ADCAEVT2:1;			// 24:24   
	uint32_t	ADCAEVT3:1;			// 25:25   
	uint32_t	ADCAEVT4:1;			// 26:26   
	uint32_t	ADCBEVT1:1;			// 27:27   
	uint32_t	ADCBEVT2:1;			// 28:28   
	uint32_t	ADCBEVT3:1;			// 29:29   
	uint32_t	ADCBEVT4:1;			// 30:30   
	uint32_t	ADCCEVT1:1;			// 31:31   
};

union XBARCLR2_REG {
	uint32_t 		 all;
	struct XBARCLR2_BITS 		 bit;
};

union XBARCLR3_REG {
	uint32_t 		 all;
	struct XBARFLG3_BITS 		 bit;
};


union XBARCLR4_REG {
	uint32_t 		 all;
	struct XBARFLG4_BITS 		 bit;
};

union XBARCLR5_REG {
	uint32_t 		 all;
	struct XBARFLG5_BITS 		 bit;
};

union XBARCLR6_REG {
	uint32_t 		 all;
	struct XBARFLG6_BITS 		 bit;
};

union XBARCLR7_REG {
	uint32_t 		 all;
	struct XBARFLG7_BITS 		 bit;
};

union XBARCLR8_REG {
	uint32_t 		 all;
	struct XBARFLG8_BITS 		 bit;
};


union XBARCLR9_REG {
	uint32_t 		 all;
	struct XBARFLG9_BITS 		 bit;
};

union XBARCLR10_REG {
	uint32_t 		 all;
	struct XBARFLG10_BITS 		 bit;
};

union XBARCLR11_REG {
	uint32_t 		 all;
	struct XBARFLG11_BITS 		 bit;
};

union XBARCLR12_REG {
	uint32_t 		 all;
	struct XBARFLG12_BITS 		 bit;
};

union XBARCLR13_REG {
	uint32_t 		 all;
	struct XBARFLG13_BITS 		 bit;
};


union XBARCLR14_REG {
	uint32_t 		 all;
	struct XBARFLG14_BITS 		 bit;
};

union XBARCLR15_REG {
	uint32_t 		 all;
	struct XBARFLG15_BITS 		 bit;
};

union XBARCLR16_REG {
	uint32_t 		 all;
	struct XBARFLG16_BITS 		 bit;
};

// struct PLUOUTPUT1MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT1MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT1MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT1MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT1MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT1MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT2MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT2MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT2MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT2MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT2MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT2MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT3MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT3MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT3MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT3MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT3MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT3MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT4MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT4MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT4MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT4MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT4MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT4MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT5MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT5MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT5MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT5MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT5MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT5MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT6MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT6MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT6MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT6MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT6MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT6MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT7MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT7MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT7MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT7MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT7MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT7MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT8MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union PLUOUTPUT8MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT8MUX0TO15CFG_BITS 		 bit;
// };

// struct PLUOUTPUT8MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union PLUOUTPUT8MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT8MUX16TO31CFG_BITS 		 bit;
// };

// struct PLUOUTPUT1MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT1MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT1MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUT2MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT2MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT2MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUT3MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT3MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT3MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUT4MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT4MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT4MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUT5MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT5MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT5MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUT6MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT6MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT6MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUT7MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT7MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT7MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUT8MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union PLUOUTPUT8MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUT8MUXENABLE_BITS 		 bit;
// };

// struct PLUOUTPUTLATCH_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union PLUOUTPUTLATCH_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUTLATCH_BITS 		 bit;
// };

// struct PLUOUTPUTLATCHCLR_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union PLUOUTPUTLATCHCLR_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUTLATCHCLR_BITS 		 bit;
// };

// struct PLUOUTPUTLATCHFRC_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union PLUOUTPUTLATCHFRC_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUTLATCHFRC_BITS 		 bit;
// };

// struct PLUOUTPUTLATCHENABLE_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union PLUOUTPUTLATCHENABLE_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUTLATCHENABLE_BITS 		 bit;
// };

// struct PLUOUTPUTINV_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union PLUOUTPUTINV_REG {
// 	uint32_t 		 all;
// 	struct PLUOUTPUTINV_BITS 		 bit;
// };

// struct TRIP4MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP4MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP4MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP4MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP4MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP4MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP5MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP5MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP5MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP5MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP5MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP5MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP7MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP7MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP7MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP7MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP7MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP7MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP8MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP8MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP8MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP8MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP8MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP8MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP9MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP9MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP9MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP9MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP9MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP9MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP10MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP10MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP10MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP10MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP10MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP10MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP11MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP11MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP11MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP11MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP11MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP11MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP12MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union TRIP12MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP12MUX0TO15CFG_BITS 		 bit;
// };

// struct TRIP12MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union TRIP12MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct TRIP12MUX16TO31CFG_BITS 		 bit;
// };

// struct TRIP4MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP4MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP4MUXENABLE_BITS 		 bit;
// };

// struct TRIP5MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP5MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP5MUXENABLE_BITS 		 bit;
// };

// struct TRIP7MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP7MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP7MUXENABLE_BITS 		 bit;
// };

// struct TRIP8MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP8MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP8MUXENABLE_BITS 		 bit;
// };

// struct TRIP9MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP9MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP9MUXENABLE_BITS 		 bit;
// };

// struct TRIP10MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP10MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP10MUXENABLE_BITS 		 bit;
// };

// struct TRIP11MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP11MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP11MUXENABLE_BITS 		 bit;
// };

// struct TRIP12MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union TRIP12MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct TRIP12MUXENABLE_BITS 		 bit;
// };

// struct TRIPOUTINV_BITS {			// bits   description
// 	uint32_t	TRIP4:1;			// 0:0   
// 	uint32_t	TRIP5:1;			// 1:1   
// 	uint32_t	TRIP7:1;			// 2:2   
// 	uint32_t	TRIP8:1;			// 3:3   
// 	uint32_t	TRIP9:1;			// 4:4   
// 	uint32_t	TRIP10:1;			// 5:5   
// 	uint32_t	TRIP11:1;			// 6:6   
// 	uint32_t	TRIP12:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union TRIPOUTINV_REG {
// 	uint32_t 		 all;
// 	struct TRIPOUTINV_BITS 		 bit;
// };

// struct OUTPUT1MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT1MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT1MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT1MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT1MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT1MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT2MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT2MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT2MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT2MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT2MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT2MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT3MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT3MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT3MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT3MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT3MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT3MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT4MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT4MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT4MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT4MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT4MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT4MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT5MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT5MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT5MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT5MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT5MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT5MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT6MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT6MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT6MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT6MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT6MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT6MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT7MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT7MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT7MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT7MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT7MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT7MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT8MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union OUTPUT8MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT8MUX0TO15CFG_BITS 		 bit;
// };

// struct OUTPUT8MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union OUTPUT8MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT8MUX16TO31CFG_BITS 		 bit;
// };

// struct OUTPUT1MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT1MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT1MUXENABLE_BITS 		 bit;
// };

// struct OUTPUT2MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT2MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT2MUXENABLE_BITS 		 bit;
// };

// struct OUTPUT3MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT3MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT3MUXENABLE_BITS 		 bit;
// };

// struct OUTPUT4MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT4MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT4MUXENABLE_BITS 		 bit;
// };

// struct OUTPUT5MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT5MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT5MUXENABLE_BITS 		 bit;
// };

// struct OUTPUT6MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT6MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT6MUXENABLE_BITS 		 bit;
// };

// struct OUTPUT7MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT7MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT7MUXENABLE_BITS 		 bit;
// };

// struct OUTPUT8MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union OUTPUT8MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUT8MUXENABLE_BITS 		 bit;
// };

// struct OUTPUTLATCH_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union OUTPUTLATCH_REG {
// 	uint32_t 		 all;
// 	struct OUTPUTLATCH_BITS 		 bit;
// };

// struct OUTPUTLATCHCLR_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union OUTPUTLATCHCLR_REG {
// 	uint32_t 		 all;
// 	struct OUTPUTLATCHCLR_BITS 		 bit;
// };

// struct OUTPUTLATCHFRC_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union OUTPUTLATCHFRC_REG {
// 	uint32_t 		 all;
// 	struct OUTPUTLATCHFRC_BITS 		 bit;
// };

// struct OUTPUTLATCHENABLE_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union OUTPUTLATCHENABLE_REG {
// 	uint32_t 		 all;
// 	struct OUTPUTLATCHENABLE_BITS 		 bit;
// };

// struct OUTPUTINV_BITS {			// bits   description
// 	uint32_t	OUT1:1;			// 0:0   
// 	uint32_t	OUT2:1;			// 1:1   
// 	uint32_t	OUT3:1;			// 2:2   
// 	uint32_t	OUT4:1;			// 3:3   
// 	uint32_t	OUT5:1;			// 4:4   
// 	uint32_t	OUT6:1;			// 5:5   
// 	uint32_t	OUT7:1;			// 6:6   
// 	uint32_t	OUT8:1;			// 7:7   
// 	uint32_t	rsvd1:8;			// 15:8   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union OUTPUTINV_REG {
// 	uint32_t 		 all;
// 	struct OUTPUTINV_BITS 		 bit;
// };

// struct AUXSIG0MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG0MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG0MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG0MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG0MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG0MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG1MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG1MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG1MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG1MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG1MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG1MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG2MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG2MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG2MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG2MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG2MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG2MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG3MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG3MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG3MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG3MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG3MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG3MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG4MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG4MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG4MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG4MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG4MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG4MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG5MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG5MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG5MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG5MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG5MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG5MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG6MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG6MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG6MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG6MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG6MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG6MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG7MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG7MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG7MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG7MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG7MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG7MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG0MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG0MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG0MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG1MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG1MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG1MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG2MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG2MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG2MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG3MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG3MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG3MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG4MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG4MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG4MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG5MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG5MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG5MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG6MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG6MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG6MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG7MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG7MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG7MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG8MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG8MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG8MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG8MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG8MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG8MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG9MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG9MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG9MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG9MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG9MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG9MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG10MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG10MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG10MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG10MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG10MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG10MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG11MUX0TO15CFG_BITS {			// bits   description
// 	uint32_t	MUX0:2;			// 1:0   
// 	uint32_t	MUX1:2;			// 3:2   
// 	uint32_t	MUX2:2;			// 5:4   
// 	uint32_t	MUX3:2;			// 7:6   
// 	uint32_t	MUX4:2;			// 9:8   
// 	uint32_t	MUX5:2;			// 11:10   
// 	uint32_t	MUX6:2;			// 13:12   
// 	uint32_t	MUX7:2;			// 15:14   
// 	uint32_t	MUX8:2;			// 17:16   
// 	uint32_t	MUX9:2;			// 19:18   
// 	uint32_t	MUX10:2;			// 21:20   
// 	uint32_t	MUX11:2;			// 23:22   
// 	uint32_t	MUX12:2;			// 25:24   
// 	uint32_t	MUX13:2;			// 27:26   
// 	uint32_t	MUX14:2;			// 29:28   
// 	uint32_t	MUX15:2;			// 31:30   
// };

// union AUXSIG11MUX0TO15CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG11MUX0TO15CFG_BITS 		 bit;
// };

// struct AUXSIG11MUX16TO31CFG_BITS {			// bits   description
// 	uint32_t	MUX16:2;			// 1:0   
// 	uint32_t	MUX17:2;			// 3:2   
// 	uint32_t	MUX18:2;			// 5:4   
// 	uint32_t	MUX19:2;			// 7:6   
// 	uint32_t	MUX20:2;			// 9:8   
// 	uint32_t	MUX21:2;			// 11:10   
// 	uint32_t	MUX22:2;			// 13:12   
// 	uint32_t	MUX23:2;			// 15:14   
// 	uint32_t	MUX24:2;			// 17:16   
// 	uint32_t	MUX25:2;			// 19:18   
// 	uint32_t	MUX26:2;			// 21:20   
// 	uint32_t	MUX27:2;			// 23:22   
// 	uint32_t	MUX28:2;			// 25:24   
// 	uint32_t	MUX29:2;			// 27:26   
// 	uint32_t	MUX30:2;			// 29:28   
// 	uint32_t	MUX31:2;			// 31:30   
// };

// union AUXSIG11MUX16TO31CFG_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG11MUX16TO31CFG_BITS 		 bit;
// };

// struct AUXSIG8MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG8MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG8MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG9MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG9MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG9MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG10MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG10MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG10MUXENABLE_BITS 		 bit;
// };

// struct AUXSIG11MUXENABLE_BITS {			// bits   description
// 	uint32_t	MUX0:1;			// 0:0   
// 	uint32_t	MUX1:1;			// 1:1   
// 	uint32_t	MUX2:1;			// 2:2   
// 	uint32_t	MUX3:1;			// 3:3   
// 	uint32_t	MUX4:1;			// 4:4   
// 	uint32_t	MUX5:1;			// 5:5   
// 	uint32_t	MUX6:1;			// 6:6   
// 	uint32_t	MUX7:1;			// 7:7   
// 	uint32_t	MUX8:1;			// 8:8   
// 	uint32_t	MUX9:1;			// 9:9   
// 	uint32_t	MUX10:1;			// 10:10   
// 	uint32_t	MUX11:1;			// 11:11   
// 	uint32_t	MUX12:1;			// 12:12   
// 	uint32_t	MUX13:1;			// 13:13   
// 	uint32_t	MUX14:1;			// 14:14   
// 	uint32_t	MUX15:1;			// 15:15   
// 	uint32_t	MUX16:1;			// 16:16   
// 	uint32_t	MUX17:1;			// 17:17   
// 	uint32_t	MUX18:1;			// 18:18   
// 	uint32_t	MUX19:1;			// 19:19   
// 	uint32_t	MUX20:1;			// 20:20   
// 	uint32_t	MUX21:1;			// 21:21   
// 	uint32_t	MUX22:1;			// 22:22   
// 	uint32_t	MUX23:1;			// 23:23   
// 	uint32_t	MUX24:1;			// 24:24   
// 	uint32_t	MUX25:1;			// 25:25   
// 	uint32_t	MUX26:1;			// 26:26   
// 	uint32_t	MUX27:1;			// 27:27   
// 	uint32_t	MUX28:1;			// 28:28   
// 	uint32_t	MUX29:1;			// 29:29   
// 	uint32_t	MUX30:1;			// 30:30   
// 	uint32_t	MUX31:1;			// 31:31   
// };

// union AUXSIG11MUXENABLE_REG {
// 	uint32_t 		 all;
// 	struct AUXSIG11MUXENABLE_BITS 		 bit;
// };

// struct AUXSIGOUTINV_BITS {			// bits   description
// 	uint32_t	OUT0:1;			// 0:0   
// 	uint32_t	OUT1:1;			// 1:1   
// 	uint32_t	OUT2:1;			// 2:2   
// 	uint32_t	OUT3:1;			// 3:3   
// 	uint32_t	OUT4:1;			// 4:4   
// 	uint32_t	OUT5:1;			// 5:5   
// 	uint32_t	OUT6:1;			// 6:6   
// 	uint32_t	OUT7:1;			// 7:7   
// 	uint32_t	OUT8:1;			// 8:8   
// 	uint32_t	OUT9:1;			// 9:9   
// 	uint32_t	OUT10:1;			// 10:10   
// 	uint32_t	OUT11:1;			// 11:11   
// 	uint32_t	rsvd1:4;			// 15:12   reserved
// 	uint32_t	rsvd2:16;			// 31:16   reserved
// };

// union AUXSIGOUTINV_REG {
// 	uint32_t 		 all;
// 	struct AUXSIGOUTINV_BITS 		 bit;
// };

struct PLU1SYNCSEL_BITS {			// bits   description
	uint32_t	PLU1_SYNC_0SEL:8;			// 7:0   
	uint32_t	PLU1_SYNC_1SEL:8;			// 15:8   
	uint32_t	PLU1_SYNC_2SEL:8;			// 23:16   
	uint32_t	PLU1_SYNC_3SEL:8;			// 31:24   
};

union PLU1SYNCSEL_REG {
	uint32_t 		 all;
	struct PLU1SYNCSEL_BITS 		 bit;
};

struct PLU1FORCESEL_BITS {			// bits   description
	uint32_t	PLU1_FORCE_0SEL:8;			// 7:0   
	uint32_t	PLU1_FORCE_1SEL:8;			// 15:8   
	uint32_t	PLU1_FORCE_2SEL:8;			// 23:16   
	uint32_t	PLU1_FORCE_3SEL:8;			// 31:24   
};

union PLU1FORCESEL_REG {
	uint32_t 		 all;
	struct PLU1FORCESEL_BITS 		 bit;
};

struct XBARINPUTINV_BITS {			// bits   description
	uint32_t	XBAR_INPUT0_INV_CFG:1;			// 0:0   
	uint32_t	XBAR_INPUT1_INV_CFG:1;			// 1:1   
	uint32_t	XBAR_INPUT2_INV_CFG:1;			// 2:2   
	uint32_t	XBAR_INPUT3_INV_CFG:1;			// 3:3   
	uint32_t	XBAR_INPUT4_INV_CFG:1;			// 4:4   
	uint32_t	XBAR_INPUT5_INV_CFG:1;			// 5:5   
	uint32_t	XBAR_INPUT6_INV_CFG:1;			// 6:6   
	uint32_t	XBAR_INPUT7_INV_CFG:1;			// 7:7   
	uint32_t	XBAR_INPUT8_INV_CFG:1;			// 8:8   
	uint32_t	XBAR_INPUT9_INV_CFG:1;			// 9:9   
	uint32_t	XBAR_INPUT10_INV_CFG:1;			// 10:10   
	uint32_t	XBAR_INPUT11_INV_CFG:1;			// 11:11   
	uint32_t	XBAR_INPUT12_INV_CFG:1;			// 12:12   
	uint32_t	XBAR_INPUT13_INV_CFG:1;			// 13:13   
	uint32_t	XBAR_INPUT14_INV_CFG:1;			// 14:14   
	uint32_t	XBAR_INPUT15_INV_CFG:1;			// 15:15   
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union XBARINPUTINV_REG {
	uint32_t 		 all;
	struct XBARINPUTINV_BITS 		 bit;
};

struct XBARPLUINPUTINV_BITS {			// bits   description
	uint32_t	XBAR_PLU_INPUT0_INV_CFG:1;			// 0:0   
	uint32_t	XBAR_PLU_INPUT1_INV_CFG:1;			// 1:1   
	uint32_t	XBAR_PLU_INPUT2_INV_CFG:1;			// 2:2   
	uint32_t	XBAR_PLU_INPUT3_INV_CFG:1;			// 3:3   
	uint32_t	XBAR_PLU_INPUT4_INV_CFG:1;			// 4:4   
	uint32_t	XBAR_PLU_INPUT5_INV_CFG:1;			// 5:5   
	uint32_t	XBAR_PLU_INPUT6_INV_CFG:1;			// 6:6   
	uint32_t	XBAR_PLU_INPUT7_INV_CFG:1;			// 7:7   
	uint32_t	XBAR_PLU_INPUT8_INV_CFG:1;			// 8:8   
	uint32_t	XBAR_PLU_INPUT9_INV_CFG:1;			// 9:9   
	uint32_t	XBAR_PLU_INPUT10_INV_CFG:1;			// 10:10   
	uint32_t	XBAR_PLU_INPUT11_INV_CFG:1;			// 11:11   
	uint32_t	XBAR_PLU_INPUT12_INV_CFG:1;			// 12:12   
	uint32_t	XBAR_PLU_INPUT13_INV_CFG:1;			// 13:13   
	uint32_t	XBAR_PLU_INPUT14_INV_CFG:1;			// 14:14   
	uint32_t	XBAR_PLU_INPUT15_INV_CFG:1;			// 15:15   
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union XBARPLUINPUTINV_REG {
	uint32_t 		 all;
	struct XBARPLUINPUTINV_BITS 		 bit;
};

struct XBARHALTEN_BITS {			// bits   description
	uint32_t	XBAR_HALT_EN:2;			// 1:0   
	uint32_t	rsvd1:30;			// 31:2   reserved
};

union XBARHALTEN_REG {
	uint32_t 		 all;
	struct XBARHALTEN_BITS 		 bit;
};

struct PLU2SYNCSEL_BITS {			// bits   description
	uint32_t	PLU2_SYNC_0SEL:8;			// 7:0   
	uint32_t	PLU2_SYNC_1SEL:8;			// 15:8   
	uint32_t	PLU2_SYNC_2SEL:8;			// 23:16   
	uint32_t	PLU2_SYNC_3SEL:8;			// 31:24   
};

union PLU2SYNCSEL_REG {
	uint32_t 		 all;
	struct PLU2SYNCSEL_BITS 		 bit;
};

struct PLU2FORCESEL_BITS {			// bits   description
	uint32_t	PLU2_FORCE_0SEL:8;			// 7:0   
	uint32_t	PLU2_FORCE_1SEL:8;			// 15:8   
	uint32_t	PLU2_FORCE_2SEL:8;			// 23:16   
	uint32_t	PLU2_FORCE_3SEL:8;			// 31:24   
};

union PLU2FORCESEL_REG {
	uint32_t 		 all;
	struct PLU2FORCESEL_BITS 		 bit;
};

struct PLU3SYNCSEL_BITS {			// bits   description
	uint32_t	PLU3_SYNC_0SEL:8;			// 7:0
	uint32_t	PLU3_SYNC_1SEL:8;			// 15:8
	uint32_t	PLU3_SYNC_2SEL:8;			// 23:16
	uint32_t	PLU3_SYNC_3SEL:8;			// 31:24
};

union PLU3SYNCSEL_REG {
	uint32_t 		 all;
	struct PLU3SYNCSEL_BITS 		 bit;
};

struct PLU3FORCESEL_BITS {			// bits   description
	uint32_t	PLU3_FORCE_0SEL:8;			// 7:0
	uint32_t	PLU3_FORCE_1SEL:8;			// 15:8
	uint32_t	PLU3_FORCE_2SEL:8;			// 23:16
	uint32_t	PLU3_FORCE_3SEL:8;			// 31:24
};

union PLU3FORCESEL_REG {
	uint32_t 		 all;
	struct PLU3FORCESEL_BITS 		 bit;
};

struct PLU4SYNCSEL_BITS {			// bits   description
	uint32_t	PLU4_SYNC_0SEL:8;			// 7:0
	uint32_t	PLU4_SYNC_1SEL:8;			// 15:8
	uint32_t	PLU4_SYNC_2SEL:8;			// 23:16
	uint32_t	PLU4_SYNC_3SEL:8;			// 31:24
};

union PLU4SYNCSEL_REG {
	uint32_t 		 all;
	struct PLU4SYNCSEL_BITS 		 bit;
};

struct PLU4FORCESEL_BITS {			// bits   description
	uint32_t	PLU4_FORCE_0SEL:8;			// 7:0
	uint32_t	PLU4_FORCE_1SEL:8;			// 15:8
	uint32_t	PLU4_FORCE_2SEL:8;			// 23:16
	uint32_t	PLU4_FORCE_3SEL:8;			// 31:24
};

union PLU4FORCESEL_REG {
	uint32_t 		 all;
	struct PLU4FORCESEL_BITS 		 bit;
};

 struct XBAR_PLU1_OUT_SEL_BITS {           // bits description
     Uint16 PLU1_OUT0_SEL:1;             // 2:0
     Uint16 rsvd1:1;              		// 3:3
     Uint16 PLU1_OUT1_SEL:1;             // 6:4
     Uint16 rsvd2:1;               		// 7:7
     Uint16 PLU1_OUT2_SEL:1;             // 10:8
     Uint16 rsvd3:1;              		// 11:11
     Uint16 PLU1_OUT3_SEL:1;             // 14:12
     Uint16 rsvd4:1;              		// 15:15
     Uint16 PLU1_OUT4_SEL:1;             // 18:16
     Uint16 rsvd5:1;             		// 19:19
     Uint16 PLU1_OUT5_SEL:1;             // 22:20
     Uint16 rsvd6:1;             		// 23:23
     Uint16 PLU1_OUT6_SEL:1;             // 26:24
     Uint16 rsvd7:1;             		// 27:27
     Uint16 PLU1_OUT7_SEL:1;             // 30:28
     Uint16 rsvd8:1;            		// 31:31
 };

 union PLU1_OUT_SEL_REG {
     Uint32  all;
     struct  XBAR_PLU1_OUT_SEL_BITS   bit;
 };

 struct PLU2_OUT_SEL_BITS {           // bits description
     Uint16 PLU2_OUT0_SEL:1;             // 2:0
     Uint16 rsvd1:1;              		// 3:3
     Uint16 PLU2_OUT1_SEL:1;             // 6:4
     Uint16 rsvd2:1;               		// 7:7
     Uint16 PLU2_OUT2_SEL:1;             // 10:8
     Uint16 rsvd3:1;              		// 11:11
     Uint16 PLU2_OUT3_SEL:1;             // 14:12
     Uint16 rsvd4:1;              		// 15:15
     Uint16 PLU2_OUT4_SEL:1;             // 18:16
     Uint16 rsvd5:1;             		// 19:19
     Uint16 PLU2_OUT5_SEL:1;             // 22:20
     Uint16 rsvd6:1;             		// 23:23
     Uint16 PLU2_OUT6_SEL:1;             // 26:24
     Uint16 rsvd7:1;             		// 27:27
     Uint16 PLU2_OUT7_SEL:1;             // 30:28
     Uint16 rsvd8:1;            		// 31:31
 };
 union PLU2_OUT_SEL_REG {
     Uint32  all;
     struct  PLU2_OUT_SEL_BITS  bit;
 };
// XBAR Register Definitions:




// struct INPUTSELECTLOCK_BITS {           // bits description
//     Uint16 INPUT1SELECT:1;              // 0 Lock bit for INPUT1SELECT Register
//     Uint16 INPUT2SELECT:1;              // 1 Lock bit for INPUT2SELECT Register
//     Uint16 INPUT3SELECT:1;              // 2 Lock bit for INPUT3SELECT Register
//     Uint16 INPUT4SELECT:1;              // 3 Lock bit for INPUT4SELECT Register
//     Uint16 INPUT5SELECT:1;              // 4 Lock bit for INPUT5SELECT Register
//     Uint16 INPUT6SELECT:1;              // 5 Lock bit for INPUT6SELECT Register
//     Uint16 INPUT7SELECT:1;              // 6 Lock bit for INPUT7SELECT Register
//     Uint16 INPUT8SELECT:1;              // 7 Lock bit for INPUT8SELECT Register
//     Uint16 INPUT9SELECT:1;              // 8 Lock bit for INPUT9SELECT Register
//     Uint16 INPUT10SELECT:1;             // 9 Lock bit for INPUT10SELECT Register
//     Uint16 INPUT11SELECT:1;             // 10 Lock bit for INPUT11SELECT Register
//     Uint16 INPUT12SELECT:1;             // 11 Lock bit for INPUT12SELECT Register
//     Uint16 INPUT13SELECT:1;             // 12 Lock bit for INPUT13SELECT Register
//     Uint16 INPUT14SELECT:1;             // 13 Lock bit for INPUT14SELECT Register
//     Uint16 INPUT15SELECT:1;             // 14 Lock bit for INPUT15SELECT Register
//     Uint16 INPUT16SELECT:1;             // 15 Lock bit for INPUT16SELECT Register
//     Uint16 rsvd1:16;                    // 31:16 Reserved
// };

// union INPUTSELECTLOCK_REG {
//     Uint32  all;
//     struct  INPUTSELECTLOCK_BITS  bit;
// };



// struct OUTPUTLOCK_BITS {                // bits description
//     Uint16 LOCK:1;                      // 0 Locks the configuration for OUTPUT-XBAR
//     Uint16 rsvd1:15;                    // 15:1 Reserved
//     Uint16 KEY:16;                      // 31:16 Write Protection KEY
// };

// union OUTPUTLOCK_REG {
//     Uint32  all;
//     struct  OUTPUTLOCK_BITS  bit;
// };



struct XBAR_REGS {
	 union  XBARFLG1_REG			XBARFLG1;
	 union  XBARFLG2_REG			XBARFLG2;
	 union  XBARFLG3_REG			XBARFLG3;
	 union  XBARFLG4_REG			XBARFLG4;
	 union  XBARCLR1_REG			XBARCLR1;
	 union  XBARCLR2_REG			XBARCLR2;
	 union  XBARCLR3_REG			XBARCLR3;
	 union  XBARCLR4_REG			XBARCLR4;
	 union  XBARFLG9_REG			XBARFLG9;
	 union  XBARFLG10_REG			XBARFLG10;
	 union  XBARFLG11_REG			XBARFLG11;
	 union  XBARFLG12_REG			XBARFLG12;
	 union  XBARFLG13_REG			XBARFLG13;
	 union  XBARFLG14_REG			XBARFLG14;
	 union  XBARFLG15_REG			XBARFLG15;
	 union  XBARFLG16_REG			XBARFLG16;
	 union  XBARFLG5_REG			XBARFLG5;
	 union  XBARFLG6_REG			XBARFLG6;
	 union  XBARFLG7_REG			XBARFLG7;
	 union  XBARFLG8_REG			XBARFLG8;
	 union  XBARCLR5_REG			XBARCLR5;
	 union  XBARCLR6_REG			XBARCLR6;
	 union  XBARCLR7_REG			XBARCLR7;
	 union  XBARCLR8_REG			XBARCLR8;
	 union  XBARCLR9_REG			XBARCLR9;
	 union  XBARCLR10_REG			XBARCLR10;
	 union  XBARCLR11_REG			XBARCLR11;
	 union  XBARCLR12_REG			XBARCLR12;
	 union  XBARCLR13_REG			XBARCLR13;
	 union  XBARCLR14_REG			XBARCLR14;
	 union  XBARCLR15_REG			XBARCLR15;
	 union  XBARCLR16_REG			XBARCLR16;
};
struct XBAR_top_REGS {

	union  PLU1SYNCSEL_REG			         PLU1SYNCSEL;
	union  PLU1FORCESEL_REG			         PLU1FORCESEL;
	union  XBARINPUTINV_REG			         XBARINPUTINV;
	union  XBARPLUINPUTINV_REG		         XBARPLUINPUTINV;
	union  XBARHALTEN_REG			         XBARHALTEN;
	union  PLU2SYNCSEL_REG			         PLU2SYNCSEL;
	union  PLU2FORCESEL_REG			         PLU2FORCESEL;

	union  PLU3SYNCSEL_REG			         PLU3SYNCSEL;
	union  PLU3FORCESEL_REG			         PLU3FORCESEL;
	union  PLU4SYNCSEL_REG			         PLU4SYNCSEL;
	union  PLU4FORCESEL_REG			         PLU4FORCESEL;
	uint32_t 						         rsvd1[8]; 		 // reserved
	union  PLU1_OUT_SEL_REG			         PLU1_OUT_SEL;
	union  PLU2_OUT_SEL_REG			         PLU2_OUT_SEL;

};





/* ========================================================================== */
/*                            Global Constants                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Global Functions Declarations                      */
/* ========================================================================== */
// XBAR External References & Function Declarations



#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of REGS_XBAR_H definition
