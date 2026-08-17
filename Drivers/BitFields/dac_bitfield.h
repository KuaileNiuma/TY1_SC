

#ifndef REGS_DAC_H
#define REGS_DAC_H

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
// DAC Individual Register Bit Definitions:

struct DACCTL_BITS {			// bits   description
	uint16_t	DACREFSEL:1;			// 0:0   
	uint16_t	MODE:1;			// 1:1   
	uint16_t	LOADMODE:1;			// 2:2   
	uint16_t	rsvd1:1;			// 3:3   reserved
	uint16_t	SYNCSEL:4;			// 7:4   
	uint16_t	rsvd2:8;			// 15:8   reserved
};

union DACCTL_REG {
	uint16_t 		 all;
	struct DACCTL_BITS 		 bit;
};

struct DACVALA_BITS {			// bits   description
	uint16_t	DACVALA:12;			// 11:0   
	uint16_t	rsvd1:4;			// 15:12   reserved
};

union DACVALA_REG {
	uint16_t 		 all;
	struct DACVALA_BITS 		 bit;
};

struct DACVALS_BITS {			// bits   description
	uint16_t	DACVALS:12;			// 11:0   
	uint16_t	rsvd1:4;			// 15:12   reserved
};

union DACVALS_REG {
	uint16_t 		 all;
	struct DACVALS_BITS 		 bit;
};

struct DACOUTEN_BITS {			// bits   description
	uint16_t	DACOUTEN:1;			// 0:0   
	uint16_t	rsvd1:15;			// 15:1   reserved
};

union DACOUTEN_REG {
	uint16_t 		 all;
	struct DACOUTEN_BITS 		 bit;
};

struct DAC_CAL_EN_BITS {			// bits   description
	uint16_t	DAC_CAL_EN:1;			// 0:0   
	uint16_t	rsvd1:15;			// 15:1   reserved
};

union DAC_CAL_EN_REG {
	uint16_t 		 all;
	struct DAC_CAL_EN_BITS 		 bit;
};

struct DAC_EN_BITS {			// bits   description
	uint16_t	DAC_EN:1;			// 0:0   
	uint16_t	rsvd1:15;			// 15:1   reserved
};

union DAC_EN_REG {
	uint16_t 		 all;
	struct DAC_EN_BITS 		 bit;
};

struct DAC_PHASE_DELAY_BITS {			// bits   description
	uint32_t	DAC_PHASE_DELAY:18;			// 17:0   
	uint32_t	rsvd1:14;			// 31:18   reserved
};

union DAC_PHASE_DELAY_REG {
	uint32_t 		 all;
	struct DAC_PHASE_DELAY_BITS 		 bit;
};

struct DAC_ANACLKFREQSEL_BITS {			// bits   description
	uint32_t	DAC_ANACLKFREQSEL:2;			// 1:0   
	uint32_t	rsvd1:30;			// 31:2   reserved
};

union DAC_ANACLKFREQSEL_REG {
	uint32_t 		 all;
	struct DAC_ANACLKFREQSEL_BITS 		 bit;
};


// DAC Register Definitions:

struct DAC_REGS {
	uint16_t 				rsvd0;
	union  DACCTL_REG			DACCTL;
	union  DACVALA_REG			DACVALA;
	union  DACVALS_REG			DACVALS;
	union  DACOUTEN_REG			DACOUTEN;
	uint16_t 						rsvd1[3]; 		 // reserved
	union  DAC_CAL_EN_REG			DAC_CAL_EN;
	union  DAC_EN_REG			DAC_EN;
	union  DAC_PHASE_DELAY_REG			DAC_PHASE_DELAY;
	union  DAC_ANACLKFREQSEL_REG			DAC_ANACLKFREQSEL;
};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
// DAC External References & Function Declarations

extern volatile struct DAC_REGS dacRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of REGS_DAC_H definition
