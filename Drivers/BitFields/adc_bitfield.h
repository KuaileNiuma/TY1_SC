

#ifndef REGS_ADC_H
#define REGS_ADC_H

#ifdef __cplusplus
extern "C" {
#endif


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

// ADC Individual Register Bit Definitions:

//
// ADC Post Processing Block 1 Result Register
//
struct ADCPPB1RESULT_BITS {			// bits   description
	uint32_t	RESULT:16;			// 15:0   ADC Post Processing Block Result 1
	uint32_t	RESULT_SIGN:16;			// 31:16   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB1RESULT_REG {
	uint32_t 		 all;
	struct ADCPPB1RESULT_BITS 		 bit;
};

//
// ADC Post Processing Block 2 Result Register
//
struct ADCPPB2RESULT_BITS {			// bits   description
	uint32_t	RESULT:16;			// 15:0   ADC Post Processing Block Result 2
	uint32_t	RESULT_SIGN:16;			// 31:16   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB2RESULT_REG {
	uint32_t 		 all;
	struct ADCPPB2RESULT_BITS 		 bit;
};

//
// ADC Post Processing Block 3 Result Register
//
struct ADCPPB3RESULT_BITS {			// bits   description
	uint32_t	RESULT:16;			// 15:0   ADC Post Processing Block Result 3
	uint32_t	RESULT_SIGN:16;			// 31:16   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB3RESULT_REG {
	uint32_t 		 all;
	struct ADCPPB3RESULT_BITS 		 bit;
};

//
// ADC Post Processing Block 4 Result Register
//
struct ADCPPB4RESULT_BITS {			// bits   description
	uint32_t	RESULT:16;			// 15:0   ADC Post Processing Block Result 4
	uint32_t	RESULT_SIGN:16;			// 31:16   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB4RESULT_REG {
	uint32_t 		 all;
	struct ADCPPB4RESULT_BITS 		 bit;
};

//
// ADC PPB 1 Final Max Result Register
//
struct ADCPPB1MAX_BITS {			// bits   description
	uint32_t	MAX:17;			// 16:0   Post Processing Block 1 Oversampling Final Max. When either a
	uint32_t	MAX_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB1MAX_REG {
	uint32_t 		 all;
	struct ADCPPB1MAX_BITS 		 bit;
};

//
// ADC PPB 1 Final Min Result Register
//
struct ADCPPB1MIN_BITS {			// bits   description
	uint32_t	MIN:17;			// 16:0   Post Processing Block 1 Oversampling Final Min. When either a
	uint32_t	MIN_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB1MIN_REG {
	uint32_t 		 all;
	struct ADCPPB1MIN_BITS 		 bit;
};

//
// ADC PPB 2 Final Max Result Register
//
struct ADCPPB2MAX_BITS {			// bits   description
	uint32_t	MAX:17;			// 16:0   Post Processing Block 2 Oversampling Final Max. When either a
	uint32_t	MAX_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB2MAX_REG {
	uint32_t 		 all;
	struct ADCPPB2MAX_BITS 		 bit;
};

//
// ADC PPB 2 Final Min Result Register
//
struct ADCPPB2MIN_BITS {			// bits   description
	uint32_t	MIN:17;			// 16:0   Post Processing Block 2 Oversampling Final Min. When either a
	uint32_t	MIN_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB2MIN_REG {
	uint32_t 		 all;
	struct ADCPPB2MIN_BITS 		 bit;
};

//
// ADC PPB 3 Final Max Result Register
//
struct ADCPPB3MAX_BITS {			// bits   description
	uint32_t	MAX:17;			// 16:0   Post Processing Block 3 Oversampling Final Max. When either a
	uint32_t	MAX_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB3MAX_REG {
	uint32_t 		 all;
	struct ADCPPB3MAX_BITS 		 bit;
};

//
// ADC PPB 3 Final Min Result Register
//
struct ADCPPB3MIN_BITS {			// bits   description
	uint32_t	MIN:17;			// 16:0   Post Processing Block 3 Oversampling Final Min. When either a
	uint32_t	MIN_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB3MIN_REG {
	uint32_t 		 all;
	struct ADCPPB3MIN_BITS 		 bit;
};

//
// ADC PPB 4 Final Max Result Register
//
struct ADCPPB4MAX_BITS {			// bits   description
	uint32_t	MAX:17;			// 16:0   Post Processing Block 4 Oversampling Final Max. When either a
	uint32_t	MAX_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB4MAX_REG {
	uint32_t 		 all;
	struct ADCPPB4MAX_BITS 		 bit;
};

//
// ADC PPB 4 Final Min Result Register
//
struct ADCPPB4MIN_BITS {			// bits   description
	uint32_t	MIN:17;			// 16:0   Post Processing Block 4 Oversampling Final Min. When either a
	uint32_t	MIN_SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB4MIN_REG {
	uint32_t 		 all;
	struct ADCPPB4MIN_BITS 		 bit;
};

struct ADCMEANEN_BITS {			// bits   description
	uint32_t	SOC0_MEAN0_EN:1;			// 0:0   SOC0 enable on mean group 0
	uint32_t	SOC0_MEAN1_EN:1;			// 1:1   SOC0 enable on mean group 1
	uint32_t	SOC1_MEAN0_EN:1;			// 2:2   SOC1 enable on mean group 0
	uint32_t	SOC1_MEAN1_EN:1;			// 3:3   SOC1 enable on mean group 1
	uint32_t	SOC2_MEAN0_EN:1;			// 4:4   SOC2 enable on mean group 0
	uint32_t	SOC2_MEAN1_EN:1;			// 5:5   SOC2 enable on mean group 1
	uint32_t	SOC3_MEAN0_EN:1;			// 6:6   SOC3 enable on mean group 0
	uint32_t	SOC3_MEAN1_EN:1;			// 7:7   SOC3 enable on mean group 1
	uint32_t	SOC4_MEAN0_EN:1;			// 8:8   SOC4 enable on mean group 0
	uint32_t	SOC4_MEAN1_EN:1;			// 9:9   SOC4 enable on mean group 1
	uint32_t	SOC5_MEAN0_EN:1;			// 10:10  SOC5 enable on mean group 0 
	uint32_t	SOC5_MEAN1_EN:1;			// 11:11  SOC5 enable on mean group 1 
	uint32_t	SOC6_MEAN0_EN:1;			// 12:12  SOC6 enable on mean group 0 
	uint32_t	SOC6_MEAN1_EN:1;			// 13:13  SOC6 enable on mean group 1 
	uint32_t	SOC7_MEAN0_EN:1;			// 14:14  SOC7 enable on mean group 0 
	uint32_t	SOC7_MEAN1_EN:1;			// 15:15  SOC7 enable on mean group 1 
	uint32_t	SOC8_MEAN0_EN:1;			// 16:16  SOC8 enable on mean group 0 
	uint32_t	SOC8_MEAN1_EN:1;			// 17:17  SOC8 enable on mean group 1 
	uint32_t	SOC9_MEAN0_EN:1;			// 18:18  SOC9 enable on mean group 0 
	uint32_t	SOC9_MEAN1_EN:1;			// 19:19  SOC9 enable on mean group 1 
	uint32_t	SOC10_MEAN0_EN:1;			// 20:20  SOC10 enable on mean group 0 
	uint32_t	SOC10_MEAN1_EN:1;			// 21:21  SOC10 enable on mean group 1 
	uint32_t	SOC11_MEAN0_EN:1;			// 22:22  SOC11 enable on mean group 0 
	uint32_t	SOC11_MEAN1_EN:1;			// 23:23  SOC11 enable on mean group 1 
	uint32_t	SOC12_MEAN0_EN:1;			// 24:24  SOC12 enable on mean group 0 
	uint32_t	SOC12_MEAN1_EN:1;			// 25:25  SOC12 enable on mean group 1 
	uint32_t	SOC13_MEAN0_EN:1;			// 26:26  SOC13 enable on mean group 0 
	uint32_t	SOC13_MEAN1_EN:1;			// 27:27  SOC13 enable on mean group 1 
	uint32_t	SOC14_MEAN0_EN:1;			// 28:28  SOC14 enable on mean group 0 
	uint32_t	SOC14_MEAN1_EN:1;			// 29:29  SOC14 enable on mean group 1 
	uint32_t	SOC15_MEAN0_EN:1;			// 30:30  SOC15 enable on mean group 0 
	uint32_t	SOC15_MEAN1_EN:1;			// 31:31  SOC15 enable on mean group 0 
};

union ADCMEANEN_REG {
	uint32_t 		 all;
	struct ADCMEANEN_BITS 		 bit;
};

struct ADCMEANEN2_BITS {			// bits   description
	uint32_t	SOC16_MEAN0_EN:1;			// 0:0   SOC16 enable on mean group 0
	uint32_t	SOC16_MEAN1_EN:1;			// 1:1   SOC16 enable on mean group 1
	uint32_t	SOC17_MEAN0_EN:1;			// 2:2   SOC17 enable on mean group 0
	uint32_t	SOC17_MEAN1_EN:1;			// 3:3   SOC17 enable on mean group 1
	uint32_t	SOC18_MEAN0_EN:1;			// 4:4   SOC18 enable on mean group 0
	uint32_t	SOC18_MEAN1_EN:1;			// 5:5   SOC18 enable on mean group 1
	uint32_t	SOC19_MEAN0_EN:1;			// 6:6   SOC19 enable on mean group 0
	uint32_t	SOC19_MEAN1_EN:1;			// 7:7   SOC19 enable on mean group 1
	uint32_t	rsvd1:24;			// 31:8   Reserved
};

union ADCMEANEN2_REG {
	uint32_t 		 all;
	struct ADCMEANEN2_BITS 		 bit;
};

struct ADCFPRND_BITS {			// bits   description
	uint32_t	CFG_FP_RND:3;			// 2:0   
	uint32_t	rsvd1:1;			// 3:3   Reserved
	uint32_t	MEAN_MODE:1;			// 4:4  
	uint32_t	rsvd2:27;			// 31:5   Reserved
};

union ADCFPRND_REG {
	uint32_t 		 all;
	struct ADCFPRND_BITS 		 bit;
};

struct ADCSMPSEL_BITS {			// bits   description
	uint32_t	SMP_SEL:8;			// 7:0  
	uint32_t	rsvd1:24;			// 31:8   Reserved
};

union ADCSMPSEL_REG {
	uint32_t 		 all;
	struct ADCSMPSEL_BITS 		 bit;
};


/**
 * @brief ADC Control Registers
 */
//
// ADC Control 1 Register
//
struct ADCCTL1_BITS {			// bits   description
	uint16_t	rsvd1:2;			// 1:0   Reserved
	uint16_t	INTPULSEPOS:1;			// 2:2   ADC Interrupt Pulse Position.
	uint16_t	rsvd2:4;			// 6:3   Reserved
	uint16_t	ADCPWDNZ:1;			// 7:7   ADC Power Down (active low). This bit controls the power up and
	uint16_t	ADCBSYCHN:5;			// 12:8   ADC Busy Channel. Set when an ADC Start of Conversion (SOC) is
	uint16_t	ADCBSY:1;			// 13:13   ADC Busy. Set when ADC SOC is generated, cleared by hardware
	uint16_t	EXTMUXPRESELECTEN:1;  // 14 External Mux Preselect Enable
	uint16_t	TDMAEN:1;			 // 15 Enable Alternate DMA Timings
};

union ADCCTL1_REG {
	uint16_t 		 all;
	struct ADCCTL1_BITS 		 bit;
};

//
// ADC Control 2 Register
//
struct ADCCTL2_BITS {			// bits   description
	uint16_t	PRESCALE:4;			// 3:0   ADC Clock Prescaler.
	uint16_t	rsvd1:9;			// 12:4   Reserved
	uint16_t	rsvd2:3;			// 15:13   Reserved
};

union ADCCTL2_REG {
	uint16_t 		 all;
	struct ADCCTL2_BITS 		 bit;
};

//
// ADC Burst Control Register
//
struct ADCBURSTCTL_BITS {			// bits   description
	uint16_t	TRIGSEL:7;			// 6:0   SOC Burst Trigger Source Select. Configures which trigger will start
	uint16_t	rsvd1:1;			// 7:7   Reserved
	uint16_t	BURSTSIZE:5;		// 12:8   SOC Burst Size Select. This bit field determines how many SOCs
	uint16_t	rsvd2:2;			// 14:13   Reserved
	uint16_t	BURST_EN:1;			// 15:15   SOC Burst Mode Enable. This bit enables the SOC Burst Mode of
};

union ADCBURSTCTL_REG {
	uint16_t 		 all;
	struct ADCBURSTCTL_BITS 		 bit;
};

//
// ADC Interrupt Flag Register
//
struct ADCINTFLG_BITS {			// bits   description
	uint16_t	ADCINT1:1;			// 0:0   ADC Interrupt 1 Flag. Reading these flags indicates if the associated
	uint16_t	ADCINT2:1;			// 1:1   ADC Interrupt 2 Flag. Reading these flags indicates if the associated
	uint16_t	ADCINT3:1;			// 2:2   ADC Interrupt 3 Flag. Reading these flags indicates if the associated
	uint16_t	ADCINT4:1;			// 3:3   ADC Interrupt 4 Flag. Reading these flags indicates if the associated
	uint16_t	rsvd1:12;			// 15:4   Reserved
#endif
};

union ADCINTFLG_REG {
	uint16_t 		 all;
	struct ADCINTFLG_BITS 		 bit;
};

//
// ADC Interrupt Flag Clear Register
//
struct ADCINTFLGCLR_BITS {			// bits   description
	uint16_t	ADCINT1:1;			// 0:0   ADC Interrupt 1 Flag Clear. Reads return 0.
	uint16_t	ADCINT2:1;			// 1:1   ADC Interrupt 2 Flag Clear. Reads return 0.
	uint16_t	ADCINT3:1;			// 2:2   ADC Interrupt 3 Flag Clear. Reads return 0.
	uint16_t	ADCINT4:1;			// 3:3   ADC Interrupt 4 Flag Clear. Reads return 0.
	uint16_t	rsvd1:12;			// 15:4   Reserved
};

union ADCINTFLGCLR_REG {
	uint16_t 		 all;
	struct ADCINTFLGCLR_BITS 		 bit;
};

//
// ADC Interrupt Overflow Register
//
struct ADCINTOVF_BITS {			// bits   description
	uint16_t	ADCINT1:1;			// 0:0   ADC Interrupt 1 Overflow Flags
	uint16_t	ADCINT2:1;			// 1:1   ADC Interrupt 2 Overflow Flags
	uint16_t	ADCINT3:1;			// 2:2   ADC Interrupt 3 Overflow Flags
	uint16_t	ADCINT4:1;			// 3:3   ADC Interrupt 4 Overflow Flags
	uint16_t	rsvd1:12;			// 15:4   Reserved
};

union ADCINTOVF_REG {
	uint16_t 		 all;
	struct ADCINTOVF_BITS 		 bit;
};

//
// ADC Interrupt Overflow Clear Register
//
struct ADCINTOVFCLR_BITS {			// bits   description
	uint16_t	ADCINT1:1;			// 0:0   ADC Interrupt 1 Overflow Clear Bits
	uint16_t	ADCINT2:1;			// 1:1   ADC Interrupt 2 Overflow Clear Bits
	uint16_t	ADCINT3:1;			// 2:2   ADC Interrupt 3 Overflow Clear Bits
	uint16_t	ADCINT4:1;			// 3:3   ADC Interrupt 4 Overflow Clear Bits
	uint16_t	rsvd1:12;			// 15:4   Reserved
};

union ADCINTOVFCLR_REG {
	uint16_t 		 all;
	struct ADCINTOVFCLR_BITS 		 bit;
};

//
// ADC Interrupt 1 and 2 Selection Register
//
struct ADCINTSEL1N2_BITS {			// bits   description
	uint16_t	INT1SEL:5;			// 4:0   ADCINT1  EOC  Source  Select
	uint16_t	INT1E:1;			// 5:5   ADCINT1  Interrupt  Enable
	uint16_t	INT1CONT:1;			// 6:6   ADCINT1 Continue to Interrupt Mode
	uint16_t	rsvd1:1;			// 7:7   Reserved
	uint16_t	INT2SEL:5;			// 12:8   ADCINT2  EOC  Source  Select
	uint16_t	INT2E:1;			// 13:13   ADCINT2  Interrupt Enable
	uint16_t	INT2CONT:1;			// 14:14   ADCINT2 Continue to Interrupt Mode
	uint16_t	rsvd2:1;			// 15:15   Reserved
};

union ADCINTSEL1N2_REG {
	uint16_t 		 all;
	struct ADCINTSEL1N2_BITS 		 bit;
};

//
// ADC Interrupt 3 and 4 Selection Register
//
struct ADCINTSEL3N4_BITS {			// bits   description
	uint16_t	INT3SEL:5;			// 4:0   ADCINT3  EOC  Source  Select
	uint16_t	INT3E:1;			// 5:5   ADCINT3  Interrupt  Enable
	uint16_t	INT3CONT:1;			// 6:6   ADCINT3 Continue to Interrupt Mode
	uint16_t	rsvd1:1;			// 7:7   Reserved
	uint16_t	INT4SEL:5;			// 12:8   ADCINT4  EOC  Source  Select
	uint16_t	INT4E:1;			// 13:13   ADCINT4  Interrupt  Enable
	uint16_t	INT4CONT:1;			// 14:14   ADCINT4 Continue to Interrupt Mode
	uint16_t	rsvd2:1;			// 15:15   Reserved
};

union ADCINTSEL3N4_REG {
	uint16_t 		 all;
	struct ADCINTSEL3N4_BITS 		 bit;
};

//
// ADC SOC Priority Control Register
//
struct ADCSOCPRICTL_BITS {			// bits   description
	uint16_t	SOCPRIORITY:5;			// 4:0   SOC Priority
	uint16_t	RRPOINTER:5;			// 9:5   Round Robin Pointer. Holds the value of the last converted round
	uint16_t	rsvd1:6;			// 15:10   Reserved
};

union ADCSOCPRICTL_REG {
	uint16_t 		 all;
	struct ADCSOCPRICTL_BITS 		 bit;
};

//
// ADC Interrupt SOC Selection 1 Register
//
struct ADCINTSOCSEL1_BITS {			// bits   description
	uint16_t	SOC0:2;			// 1:0   SOCO ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC1:2;			// 3:2   SOC1 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC2:2;			// 5:4   SOC2 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC3:2;			// 7:6   SOC3 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC4:2;			// 9:8   SOC4 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC5:2;			// 11:10   SOC5 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC6:2;			// 13:12   SOC6 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC7:2;			// 15:14   SOC7 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
};

union ADCINTSOCSEL1_REG {
	uint16_t 		 all;
	struct ADCINTSOCSEL1_BITS 		 bit;
};

//
// ADC Interrupt SOC Selection 2 Register
//
struct ADCINTSOCSEL2_BITS {			// bits   description
	uint16_t	SOC8:2;			// 1:0   SOC8 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC9:2;			// 3:2   SOC9 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC10:2;			// 5:4   SOC10 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC11:2;			// 7:6   SOC11 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC12:2;			// 9:8   SOC12 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC13:2;			// 11:10   SOC13 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC14:2;			// 13:12   SOC14 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	SOC15:2;			// 15:14   SOC15 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
};

union ADCINTSOCSEL2_REG {
	uint16_t 		 all;
	struct ADCINTSOCSEL2_BITS 		 bit;
};

//
// ADC SOC Flag 1 Register
//
struct ADCSOCFLG1_BITS {			// bits   description
	uint16_t	SOC0:1;			// 0:0   SOCO Start of Conversion Flag. Indicates the state of SOCO
	uint16_t	SOC1:1;			// 1:1   SOC1 Start of Conversion Flag. Indicates the state of SOC1
	uint16_t	SOC2:1;			// 2:2   SOC2 Start of Conversion Flag. Indicates the state of SOC2
	uint16_t	SOC3:1;			// 3:3   SOC3 Start of Conversion Flag. Indicates the state of SOC3
	uint16_t	SOC4:1;			// 4:4   SOC4 Start of Conversion Flag. Indicates the state of SOC4
	uint16_t	SOC5:1;			// 5:5   SOC5 Start of Conversion Flag. Indicates the state of SOC5
	uint16_t	SOC6:1;			// 6:6   SOC6 Start of Conversion Flag. Indicates the state of SOC6
	uint16_t	SOC7:1;			// 7:7   SOC7 Start of Conversion Flag. Indicates the state of SOC7
	uint16_t	SOC8:1;			// 8:8   SOC8 Start of Conversion Flag. Indicates the state of SOC8
	uint16_t	SOC9:1;			// 9:9   SOC9 Start of Conversion Flag. Indicates the state of SOC9
	uint16_t	SOC10:1;			// 10:10   SOC10 Start of Conversion Flag. Indicates the state of SOC10
	uint16_t	SOC11:1;			// 11:11   SOC11 Start of Conversion Flag. Indicates the state of SOC11
	uint16_t	SOC12:1;			// 12:12   SOC12 Start of Conversion Flag. Indicates the state of SOC12
	uint16_t	SOC13:1;			// 13:13   SOC13 Start of Conversion Flag. Indicates the state of SOC13
	uint16_t	SOC14:1;			// 14:14   SOC14 Start of Conversion Flag. Indicates the state of SOC14
	uint16_t	SOC15:1;			// 15:15   SOC15 Start of Conversion Flag. Indicates the state of SOC15
};

union ADCSOCFLG1_REG {
	uint16_t 		 all;
	struct ADCSOCFLG1_BITS 		 bit;
};

//
// ADC SOC Force 1 Register
//
struct ADCSOCFRC1_BITS {			// bits   description
	uint16_t	SOC0:1;			// 0:0   SOC0 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC1:1;			// 1:1   SOC1 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC2:1;			// 2:2   SOC2 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC3:1;			// 3:3   SOC3 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC4:1;			// 4:4   SOC4 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC5:1;			// 5:5   SOC5 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC6:1;			// 6:6   SOC6 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC7:1;			// 7:7   SOC7 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC8:1;			// 8:8   SOC8 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC9:1;			// 9:9   SOC9 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC10:1;			// 10:10   SOC10 Force Start of Conversion Bit. Writing a 1 will force to 1
	uint16_t	SOC11:1;			// 11:11   SOC11 Force Start of Conversion Bit. Writing a 1 will force to 1
	uint16_t	SOC12:1;			// 12:12   SOC12 Force Start of Conversion Bit. Writing a 1 will force to 1
	uint16_t	SOC13:1;			// 13:13   SOC13 Force Start of Conversion Bit. Writing a 1 will force to 1
	uint16_t	SOC14:1;			// 14:14   SOC14 Force Start of Conversion Bit. Writing a 1 will force to 1
	uint16_t	SOC15:1;			// 15:15   SOC15 Force Start of Conversion Bit. Writing a 1 will force to 1
};

union ADCSOCFRC1_REG {
	uint16_t 		 all;
	struct ADCSOCFRC1_BITS 		 bit;
};

//
// ADC SOC Overflow 1 Register
//
struct ADCSOCOVF1_BITS {			// bits   description
	uint16_t	SOC0:1;			// 0:0   SOC0 Start of Conversion Overflow Flag. Indicates an SOCo event
	uint16_t	SOC1:1;			// 1:1   SOC1 Start of Conversion Overflow Flag. Indicates an SOC1 event
	uint16_t	SOC2:1;			// 2:2   SOC2 Start of Conversion Overflow Flag. Indicates an SOC2 event
	uint16_t	SOC3:1;			// 3:3   SOC3 Start of Conversion Overflow Flag. Indicates an SOC3 event
	uint16_t	SOC4:1;			// 4:4   SOC4 Start of Conversion Overflow Flag. Indicates an SOC4 event
	uint16_t	SOC5:1;			// 5:5   SOC5 Start of Conversion Overflow Flag. Indicates an SOC5 event
	uint16_t	SOC6:1;			// 6:6   SOC6 Start of Conversion Overflow Flag. Indicates an SOC6 event
	uint16_t	SOC7:1;			// 7:7   SOC7 Start of Conversion Overflow Flag. Indicates an SOC7 event
	uint16_t	SOC8:1;			// 8:8   SOC8 Start of Conversion Overflow Flag. Indicates an SOC8 event
	uint16_t	SOC9:1;			// 9:9   SOC9 Start of Conversion Overflow Flag. Indicates an SOC9 event
	uint16_t	SOC10:1;			// 10:10   SOC10 Start of Conversion Overflow Flag. Indicates an SOC10
	uint16_t	SOC11:1;			// 11:11   SOC11 Start of Conversion Overflow Flag. Indicates an SOC11
	uint16_t	SOC12:1;			// 12:12   SOC12 Start of Conversion Overflow Flag. Indicates an SOC12
	uint16_t	SOC13:1;			// 13:13   SOC13 Start of Conversion Overflow Flag. Indicates an SOC13
	uint16_t	SOC14:1;			// 14:14   SOC14 Start of Conversion Overflow Flag. Indicates an SOC14
	uint16_t	SOC15:1;			// 15:15   SOC15 Start of Conversion Overflow Flag. Indicates an SOC15
};

union ADCSOCOVF1_REG {
	uint16_t 		 all;
	struct ADCSOCOVF1_BITS 		 bit;
};

//
// ADC SOC Overflow Clear 1 Register
//
struct ADCSOCOVFCLR1_BITS {			// bits   description
	uint16_t	SOC0:1;			// 0:0   SOC0 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC1:1;			// 1:1   SOC1 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC2:1;			// 2:2   SOC2 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC3:1;			// 3:3   SOC3 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC4:1;			// 4:4   SOC4 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC5:1;			// 5:5   SOC5 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC6:1;			// 6:6   SOC6 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC7:1;			// 7:7   SOC7 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC8:1;			// 8:8   SOC8 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC9:1;			// 9:9   SOC9 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC10:1;			// 10:10   SOC10 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC11:1;			// 11:11   SOC11 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC12:1;			// 12:12   SOC12 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC13:1;			// 13:13   SOC13 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC14:1;			// 14:14   SOC14 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC15:1;			// 15:15   SOC15 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
};

union ADCSOCOVFCLR1_REG {
	uint16_t 		 all;
	struct ADCSOCOVFCLR1_BITS 		 bit;
};

//
// ADC SOC0 Control Register
//
struct ADCSOC0CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOCO Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOCO Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC0 Trigger Source Select. Along with the SOC0 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC0CTL_REG {
	uint32_t 		 all;
	struct ADCSOC0CTL_BITS 		 bit;
};

//
// ADC SOC1 Control Register
//
struct ADCSOC1CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC1 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC1 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC1 Trigger Source Select. Along with the SOC1 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC1CTL_REG {
	uint32_t 		 all;
	struct ADCSOC1CTL_BITS 		 bit;
};

//
// ADC SOC2 Control Register
//
struct ADCSOC2CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC2 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC2 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC2 Trigger Source Select. Along with the SOC2 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC2CTL_REG {
	uint32_t 		 all;
	struct ADCSOC2CTL_BITS 		 bit;
};

//
// ADC SOC3 Control Register
//
struct ADCSOC3CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC3 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC3 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC3 Trigger Source Select. Along with the SOC3 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC3CTL_REG {
	uint32_t 		 all;
	struct ADCSOC3CTL_BITS 		 bit;
};

//
// ADC SOC4 Control Register
//
struct ADCSOC4CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC4 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC4 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC4 Trigger Source Select. Along with the SOC4 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC4CTL_REG {
	uint32_t 		 all;
	struct ADCSOC4CTL_BITS 		 bit;
};

//
// ADC SOC5 Control Register
//
struct ADCSOC5CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC5 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC5 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC5 Trigger Source Select. Along with the SOC5 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC5CTL_REG {
	uint32_t 		 all;
	struct ADCSOC5CTL_BITS 		 bit;
};

//
// ADC SOC6 Control Register
//
struct ADCSOC6CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC6 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC6 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC6 Trigger Source Select. Along with the SOC6 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC6CTL_REG {
	uint32_t 		 all;
	struct ADCSOC6CTL_BITS 		 bit;
};

//
// ADC SOC7 Control Register
//
struct ADCSOC7CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC7 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC7 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC7 Trigger Source Select. Along with the SOC7 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC7CTL_REG {
	uint32_t 		 all;
	struct ADCSOC7CTL_BITS 		 bit;
};

//
// ADC SOC8 Control Register
//
struct ADCSOC8CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC8 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC8 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC8 Trigger Source Select. Along with the SOC8 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC8CTL_REG {
	uint32_t 		 all;
	struct ADCSOC8CTL_BITS 		 bit;
};

//
// ADC SOC9 Control Register
//
struct ADCSOC9CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC9 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC9 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC9 Trigger Source Select. Along with the SOC9 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC9CTL_REG {
	uint32_t 		 all;
	struct ADCSOC9CTL_BITS 		 bit;
};

//
// ADC SOC10 Control Register
//
struct ADCSOC10CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC10 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC10 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC10 Trigger Source Select. Along with the SOC10 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC10CTL_REG {
	uint32_t 		 all;
	struct ADCSOC10CTL_BITS 		 bit;
};

//
// ADC SOC11 Control Register
//
struct ADCSOC11CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC11 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC11 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC11 Trigger Source Select. Along with the SOC11 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC11CTL_REG {
	uint32_t 		 all;
	struct ADCSOC11CTL_BITS 		 bit;
};

//
// ADC SOC12 Control Register
//
struct ADCSOC12CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC12 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC12 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC12 Trigger Source Select. Along with the SOC12 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC12CTL_REG {
	uint32_t 		 all;
	struct ADCSOC12CTL_BITS 		 bit;
};

//
// ADC SOC13 Control Register
//
struct ADCSOC13CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC13 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC13 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC13 Trigger Source Select. Along with the SOC13 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC13CTL_REG {
	uint32_t 		 all;
	struct ADCSOC13CTL_BITS 		 bit;
};

//
// ADC SOC14 Control Register
//
struct ADCSOC14CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC14 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC14 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC14 Trigger Source Select. Along with the SOC14 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC14CTL_REG {
	uint32_t 		 all;
	struct ADCSOC14CTL_BITS 		 bit;
};

//
// ADC SOC15 Control Register
//
struct ADCSOC15CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC15 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC15 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC15 Trigger Source Select. Along with the SOC15 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC15CTL_REG {
	uint32_t 		 all;
	struct ADCSOC15CTL_BITS 		 bit;
};

//
// ADC Event Status Register
//
struct ADCEVTSTAT_BITS {			// bits   description
	uint16_t	PPB1TRIPHI:1;			// 0:0   Post Processing Block 1 Trip High Flag. When set indicates a digital
	uint16_t	PPB1TRIPLO:1;			// 1:1   Post Processing Block 1 Trip Low Flag. When set indicates a digital
	uint16_t	PPB1ZERO:1;			// 2:2   Post Processing Block 1 Zero Crossing Flag. When set indicates the
	uint16_t	rsvd1:1;			// 3:3   Reserved
	uint16_t	PPB2TRIPHI:1;			// 4:4   Post Processing Block 2 Trip High Flag. When set indicates a digital
	uint16_t	PPB2TRIPLO:1;			// 5:5   Post Processing Block 2 Trip Low Flag. When set indicates a digital
	uint16_t	PPB2ZERO:1;			// 6:6   Post Processing Block 2 Zero Crossing Flag. When set indicates the
	uint16_t	rsvd2:1;			// 7:7   Reserved
	uint16_t	PPB3TRIPHI:1;			// 8:8   Post Processing Block 3 Trip High Flag. When set indicates a digital
	uint16_t	PPB3TRIPLO:1;			// 9:9   Post Processing Block 3 Trip Low Flag. When set indicates a digital
	uint16_t	PPB3ZERO:1;			// 10:10   Post Processing Block 3 Zero Crossing Flag. When set indicates the
	uint16_t	rsvd3:1;			// 11:11   Reserved
	uint16_t	PPB4TRIPHI:1;			// 12:12   Post Processing Block 4 Trip High Flag. When set indicates a digital
	uint16_t	PPB4TRIPLO:1;			// 13:13   Post Processing Block 4 Trip Low Flag. When set indicates a digital
	uint16_t	PPB4ZERO:1;			// 14:14   Post Processing Block 4 Zero Crossing Flag. When set indicates the
	uint16_t	rsvd4:1;			// 15:15   Reserved
};

union ADCEVTSTAT_REG {
	uint16_t 		 all;
	struct ADCEVTSTAT_BITS 		 bit;
};

//
// ADC Event Clear Register
//
struct ADCEVTCLR_BITS {			// bits   description
	uint16_t	PPB1TRIPHI:1;			// 0:0   Post Processing Block 1 Trip High Clear. Clears the corresponding
	uint16_t	PPB1TRIPLO:1;			// 1:1   Post Processing Block 1 Trip Low Clear. Clears the correspondin g
	uint16_t	PPB1ZERO:1;			// 2:2   Post Processing Block 1 Zero Crossing Clear. Clears the
	uint16_t	rsvd1:1;			// 3:3   Reserved
	uint16_t	PPB2TRIPHI:1;			// 4:4   Post Processing Block 2 Trip High Clear. Clears the corresponding
	uint16_t	PPB2TRIPLO:1;			// 5:5   Post Processing Block 2 Trip Low Clear. Clears the corresponding
	uint16_t	PPB2ZERO:1;			// 6:6   Post Processing Block 2 Zero Crossing Clear. Clears the
	uint16_t	rsvd2:1;			// 7:7   Reserved
	uint16_t	PPB3TRIPHI:1;			// 8:8   Post Processing Block 3 Trip High Clear. Clears the corresponding
	uint16_t	PPB3TRIPLO:1;			// 9:9   Post Processing Block 3 Trip Low Clear. Clears the corresponding
	uint16_t	PPB3ZERO:1;			// 10:10   Post Processing Block 3 Zero Crossing Clear. Clears the
	uint16_t	rsvd3:1;			// 11:11   Reserved
	uint16_t	PPB4TRIPHI:1;			// 12:12   Post Processing Block 4 Trip High Clear. Clears the corresponding
	uint16_t	PPB4TRIPLO:1;			// 13:13   Post Processing Block 4 Trip Low Clear. Clears the corresponding
	uint16_t	PPB4ZERO:1;			// 14:14   Post Processing Block 4 Zero Crossing Clear. Clears the
	uint16_t	rsvd4:1;			// 15:15   Reserved
};

union ADCEVTCLR_REG {
	uint16_t 		 all;
	struct ADCEVTCLR_BITS 		 bit;
};

//
// ADC Event Selection Register
//
struct ADCEVTSEL_BITS {			// bits   description
	uint16_t	PPB1TRIPHI:1;			// 0:0   Post Processing Block 1 Trip High Event Enable. Setting this bit
	uint16_t	PPB1TRIPLO:1;			// 1:1   Post Processing Block 1 Trip Low Event Enable. Setting this bit
	uint16_t	PPB1ZERO:1;			// 2:2   Post Processing Block 1 Zero Crossing Event Enable. Setting this
	uint16_t	rsvd1:1;			// 3:3   Reserved
	uint16_t	PPB2TRIPHI:1;			// 4:4   Post Processing Block 2 Trip High Event Enable. Setting this bit
	uint16_t	PPB2TRIPLO:1;			// 5:5   Post Processing Block 2 Trip Low Event Enable. Setting this bit
	uint16_t	PPB2ZERO:1;			// 6:6   Post Processing Block 2 Zero Crossing Event Enable. Setting this
	uint16_t	rsvd2:1;			// 7:7   Reserved
	uint16_t	PPB3TRIPHI:1;			// 8:8   Post Processing Block 3 Trip High Event Enable. Setting this bit
	uint16_t	PPB3TRIPLO:1;			// 9:9   Post Processing Block 3 Trip Low Event Enable. Setting this bit
	uint16_t	PPB3ZERO:1;			// 10:10   Post Processing Block 3 Zero Crossing Event Enable. Setting this
	uint16_t	rsvd3:1;			// 11:11   Reserved
	uint16_t	PPB4TRIPHI:1;			// 12:12   Post Processing Block 4 Trip High Event Enable. Setting this bit
	uint16_t	PPB4TRIPLO:1;			// 13:13   Post Processing Block 4 Trip Low Event Enable. Setting this bit
	uint16_t	PPB4ZERO:1;			// 14:14   Post Processing Block 4 Zero Crossing Event Enable. Setting this
	uint16_t	rsvd4:1;			// 15:15   Reserved
};

union ADCEVTSEL_REG {
	uint16_t 		 all;
	struct ADCEVTSEL_BITS 		 bit;
};

//
// ADC Event Interrupt Selection Register
//
struct ADCEVTINTSEL_BITS {			// bits   description
	uint16_t	PPB1TRIPHI:1;			// 0:0   Post Processing Block 1 Trip High Interrupt Enable. Setting this bit
	uint16_t	PPB1TRIPLO:1;			// 1:1   Post Processing Block 1 Trip Low Interrupt Enable. Setting this bit
	uint16_t	PPB1ZERO:1;			// 2:2   Post Processing Block 1 Zero Crossing Interrupt Enable. Setting this
	uint16_t	rsvd1:1;			// 3:3   Reserved
	uint16_t	PPB2TRIPHI:1;			// 4:4   Post Processing Block 2 Trip High Interrupt Enable. Setting this bit
	uint16_t	PPB2TRIPLO:1;			// 5:5   Post Processing Block 2 Trip Low Interrupt Enable. Setting this bit
	uint16_t	PPB2ZERO:1;			// 6:6   Post  Processing Block  2  Zero  Crossing  Interrupt  Enable.  Setting  this
	uint16_t	rsvd2:1;			// 7:7   Reserved
	uint16_t	PPB3TRIPHI:1;			// 8:8   Post Processing Block 3 Trip High Interrupt Enable. Setting this bit
	uint16_t	PPB3TRIPLO:1;			// 9:9   Post Processing Block 3 Trip Low Interrupt Enable. Setting this bit
	uint16_t	PPB3ZERO:1;			// 10:10   Post Processing Block  3 Zero Crossing  Interrup t  Enable.  Setting  this
	uint16_t	rsvd3:1;			// 11:11   Reserved
	uint16_t	PPB4TRIPHI:1;			// 12:12   Post Processing Block 4 Trip High Interrupt Enable. Setting this bit
	uint16_t	PPB4TRIPLO:1;			// 13:13   Post Processing Block 4 Trip Low Interrupt Enable. Setting this bit
	uint16_t	PPB4ZERO:1;			// 14:14   Post Processing Block 4 Zero Crossing  Interrup t  Enable.  Setting  this
	uint16_t	rsvd4:1;			// 15:15   Reserved
};

union ADCEVTINTSEL_REG {
	uint16_t 		 all;
	struct ADCEVTINTSEL_BITS 		 bit;
};

//
// ADC Open and Shorts Detect Register
//
struct ADCOSDETECT_BITS {			// bits   description
	uint16_t	DETECTCFG:3;			// 2:0   ADC Opens and Shorts Detect Configuration. This bit field defines
	uint16_t	rsvd1:13;			// 15:3   Reserved
};

union ADCOSDETECT_REG {
	uint16_t 		 all;
	struct ADCOSDETECT_BITS 		 bit;
};

//
// ADC Counter Register
//
struct ADCCOUNTER_BITS {			// bits   description
	uint16_t	FREECOUNT:12;			// 11:0   ADC Free Running Counter Value. This bit field reflects the status of
	uint16_t	rsvd1:4;			// 15:12   Reserved
};

union ADCCOUNTER_REG {
	uint16_t 		 all;
	struct ADCCOUNTER_BITS 		 bit;
};

//
// ADC Offset Trim Register
//
struct ADCOFFTRIM_BITS {			// bits   description
	uint16_t	OFFTRIM:8;			// 7:0   ADC Offset Trim
	uint16_t	rsvd1:4;			// 11:8   Reserved
	uint16_t	rsvd2:4;			// 15:12   Reserved
};

union ADCOFFTRIM_REG {
	uint16_t 		 all;
	struct ADCOFFTRIM_BITS 		 bit;
};

//
// ADC PPB1 Config Register
//
struct ADCPPB1CONFIG_BITS {			// bits   description
	uint16_t	CONFIG:4;			// 3:0   ADC Post Processing Block 1 Configuration. This bit field defines
	uint16_t	TWOSCOMPEN:1;			// 4:4   ADC Post Processing Block  1 Two's Complement Enable. When  set
	uint16_t	CBCEN:1;			// 5:5   ADC Post Processing Block Cycle By Cycle Enable. When set,
	uint16_t	ABSEN:1;			// 6:6   ADC Post Processing Block 1 Absolute Value Enable. When set
	uint16_t	CONFIG_EXP:1;			// 7:7   
	uint16_t	rsvd1:8;			// 15:8   Reserved
};

union ADCPPB1CONFIG_REG {
	uint16_t 		 all;
	struct ADCPPB1CONFIG_BITS 		 bit;
};

//
// ADC PPB1 Sample Delay Time Stamp Register
//
struct ADCPPB1STAMP_BITS {			// bits   description
	uint16_t	DLYSTAMP:12;			// 11:0   ADC Post Processing Block 1 Delay Time Stamp. When an SOC
	uint16_t	rsvd1:4;			// 15:12   Reserved
};

union ADCPPB1STAMP_REG {
	uint16_t 		 all;
	struct ADCPPB1STAMP_BITS 		 bit;
};

//
// ADC PPB1 Offset Calibration Register
//
struct ADCPPB1OFFCAL_BITS {			// bits   description
	uint16_t	OFFCAL:10;			// 9:0   ADC Post Processing Block 1 Offset Correction. This bit field can
	uint16_t	rsvd1:6;			// 15:10   Reserved
};

union ADCPPB1OFFCAL_REG {
	uint16_t 		 all;
	struct ADCPPB1OFFCAL_BITS 		 bit;
};

//
// ADC PPB1 Trip Low/Trigger Time Stamp Register
//
struct ADCPPB1TRIPLO_BITS {			// bits   description
	uint32_t	LIMITLO:16;			// 15:0   ADC Post Processing Block 1 Trip Low Limit. This value sets
	uint32_t	LSIGN:1;			// 16:16   Low Limit Sign Bit. This is the sign bit (17th bit) to the LIMITLO bit
	uint32_t	rsvd1:2;			// 18:17   Reserved
	uint32_t	LIMITLO_EN:1;			// 19:19   Extended Low Limit 2 Enable.
	uint32_t	PPBREQ_1STAMP:12;			// 31:20   ADC Post Processing Block 1 Request Time Stamp. When a trigger
};

union ADCPPB1TRIPLO_REG {
	uint32_t 		 all;
	struct ADCPPB1TRIPLO_BITS 		 bit;
};

//
// ADC PPB2 Config Register
//
struct ADCPPB2CONFIG_BITS {			// bits   description
	uint16_t	CONFIG:4;			// 3:0   ADC Post Processing Block 2 Configuration. This bit field defines
	uint16_t	TWOSCOMPEN:1;			// 4:4   ADC Post Processing Block 2 Two's Complement Enable. When set
	uint16_t	CBCEN:1;			// 5:5   ADC Post Processing Block Cycle By Cycle Enable. When set,
	uint16_t	ABSEN:1;			// 6:6   ADC Post Processing Block 2 Absolute Value Enable. When set this bit enables absolute value calculation
	uint16_t	CONFIG_EXP:1;			// 7:7   
	uint16_t	rsvd1:8;			// 15:8   Reserved
};

union ADCPPB2CONFIG_REG {
	uint16_t 		 all;
	struct ADCPPB2CONFIG_BITS 		 bit;
};

//
// ADC PPB2 Sample Delay Time Stamp Register
//
struct ADCPPB2STAMP_BITS {			// bits   description
	uint16_t	DLYSTAMP:12;			// 11:0   ADC Post Processing Block 2 Delay Time Stamp. When an SOC
	uint16_t	rsvd1:4;			// 15:12   Reserved
};

union ADCPPB2STAMP_REG {
	uint16_t 		 all;
	struct ADCPPB2STAMP_BITS 		 bit;
};

//
// ADC PPB2 Offset Calibration Register
//
struct ADCPPB2OFFCAL_BITS {			// bits   description
	uint16_t	OFFCAL:10;			// 9:0   ADC Post Processing Block 2 Offset Correction. This bit field can
	uint16_t	rsvd1:6;			// 15:10   Reserved
};

union ADCPPB2OFFCAL_REG {
	uint16_t 		 all;
	struct ADCPPB2OFFCAL_BITS 		 bit;
};

//
// ADC PPB2 Trip Low/Trigger Time Stamp Register
//
struct ADCPPB2TRIPLO_BITS {			// bits   description
	uint32_t	LIMITLO:16;			// 15:0   ADC Post Processing Block 2 Trip Low Limit. This value sets
	uint32_t	LSIGN:1;			// 16:16   Low Limit Sign Bit. This is the sign bit (17th bit) to the LIMITLO bit
	uint32_t	rsvd1:2;			// 18:17   Reserved
	uint32_t	LIMITLO2EN:1;			// 19:19   Extended Low Limit 2 Enable.
	uint32_t	REQSTAMP:12;			// 31:20   ADC Post Processing Block 2 Request Time Stamp. When a trigger
};

union ADCPPB2TRIPLO_REG {
	uint32_t 		 all;
	struct ADCPPB2TRIPLO_BITS 		 bit;
};

//
// ADC PPB3 Config Register
//
struct ADCPPB3CONFIG_BITS {			// bits   description
	uint16_t	CONFIG:4;			// 3:0   ADC Post Processing Block 3 Configuration. This bit field defines
	uint16_t	TWOSCOMPEN:1;			// 4:4   ADC Post Processing Block  3 Two's Complement Enable. When  set
	uint16_t	CBCEN:1;			// 5:5   ADC Post Processing Block Cycle By Cycle Enable. When set,
	uint16_t	ABSEN:1;			// 6:6   ADC Post Processing Block 3 Absolute Value Enable. When set this bit enables absolute value calculation
	uint16_t	CONFIG_EXP:1;			// 7:7   
	uint16_t	rsvd1:8;			// 15:8   Reserved
};

union ADCPPB3CONFIG_REG {
	uint16_t 		 all;
	struct ADCPPB3CONFIG_BITS 		 bit;
};

//
// ADC PPB3 Sample Delay Time Stamp Register
//
struct ADCPPB3STAMP_BITS {			// bits   description
	uint16_t	PPBDLY_3STAMP:12;			// 11:0   ADC Post Processing Block 3 Delay Time Stamp. When an SOC
	uint16_t	rsvd1:4;			// 15:12   Reserved
};

union ADCPPB3STAMP_REG {
	uint16_t 		 all;
	struct ADCPPB3STAMP_BITS 		 bit;
};

//
// ADC PPB3 Offset Calibration Register
//
struct ADCPPB3OFFCAL_BITS {			// bits   description
	uint16_t	PPB3OFFCAL:10;			// 9:0   ADC Post Processing Block 3 Offset Correction. This bit field can
	uint16_t	rsvd1:6;			// 15:10   Reserved
};

union ADCPPB3OFFCAL_REG {
	uint16_t 		 all;
	struct ADCPPB3OFFCAL_BITS 		 bit;
};

//
// ADC PPB3 Trip Low/Trigger Time Stamp Register
//
struct ADCPPB3TRIPLO_BITS {			// bits   description
	uint32_t	PPB3LIMITLO:16;			// 15:0   ADC Post Processing Block 3 Trip Low Limit. This value sets
	uint32_t	PPB3LSIGN:1;			// 16:16   Low Limit Sign Bit. This is the sign bit (17th bit) to the LIMITLO bit
	uint32_t	rsvd1:2;			// 18:17   Reserved
	uint32_t	LIMITLO_EN:1;			// 19:19   Extended Low Limit 2 Enable.
	uint32_t	PPBREQ_3STAMP:12;			// 31:20   ADC Post Processing Block 3 Request Time Stamp. When a trigger
};

union ADCPPB3TRIPLO_REG {
	uint32_t 		 all;
	struct ADCPPB3TRIPLO_BITS 		 bit;
};

//
// ADC PPB4 Config Register
//
struct ADCPPB4CONFIG_BITS {			// bits   description
	uint16_t	CONFIG:4;			// 3:0   ADC Post Processing Block 4 Configuration. This bit field defines
	uint16_t	TWOSCOMPEN:1;			// 4:4   ADC Post Processing Block 4 Two's Complement Enable. When set
	uint16_t	CBCEN:1;			// 5:5   ADC Post Processing Block Cycle By Cycle Enable. When set,
	uint16_t	ABSEN:1;			// 6:6   ADC Post Processing Block 4 Absolute Value Enable. When set
	uint16_t	CONFIG_EXP:1;			// 7:7   
	uint16_t	rsvd1:8;			// 15:8   Reserved
};

union ADCPPB4CONFIG_REG {
	uint16_t 		 all;
	struct ADCPPB4CONFIG_BITS 		 bit;
};

//
// ADC PPB4 Sample Delay Time Stamp Register
//
struct ADCPPB4STAMP_BITS {			// bits   description
	uint16_t	DLYSTAMP:12;			// 11:0   ADC Post Processing Block 4 Delay Time Stamp. When an SOC
	uint16_t	rsvd1:4;			// 15:12   Reserved
};

union ADCPPB4STAMP_REG {
	uint16_t 		 all;
	struct ADCPPB4STAMP_BITS 		 bit;
};

//
// ADC PPB4 Offset Calibration Register
//
struct ADCPPB4OFFCAL_BITS {			// bits   description
	uint16_t	OFFCAL:10;			// 9:0   ADC Post Processing Block 4 Offset Correction. This bit field can
	uint16_t	rsvd1:6;			// 15:10   Reserved
};

union ADCPPB4OFFCAL_REG {
	uint16_t 		 all;
	struct ADCPPB4OFFCAL_BITS 		 bit;
};

//
// ADC PPB4 Trip Low/Trigger Time Stamp Register
//
struct ADCPPB4TRIPLO_BITS {			// bits   description
	uint32_t	LIMITLO:16;			// 15:0   ADC Post Processing Block 4 Trip Low Limit. This value sets
	uint32_t	HSIGN:1;			// 16:16   Low Limit Sign Bit. This is the sign bit (17th bit) to the LIMITLO bit
	uint32_t	rsvd1:2;			// 18:17   Reserved
	uint32_t	LIMITLO2EN:1;			// 19:19   Extended Low Limit 2 Enable.
	uint32_t	REQSTAMP:12;			// 31:20   ADC Post Processing Block 4 Request Time Stamp. When a trigger
};

union ADCPPB4TRIPLO_REG {
	uint32_t 		 all;
	struct ADCPPB4TRIPLO_BITS 		 bit;
};

//
// ADC PPB INT CLR Register
//
struct ADC_PPB_INT_CLR_BITS {			// bits   description
	uint16_t	ADC_PPB1_TRIPLO_INT_CLR:1;			// 0:0   
	uint16_t	ADC_PPB1_TRIPHI_INT_CLR:1;			// 1:1   
	uint16_t	ADC_PPB1_ZERO_INT_CLR:1;			// 2:2   
	uint16_t	ADC_PPB2_TRIPLO_INT_CLR:1;			// 3:3   
	uint16_t	ADC_PPB2_TRIPHI_INT_CLR:1;			// 4:4   
	uint16_t	ADC_PPB2_ZERO_INT_CLR:1;			// 5:5   
	uint16_t	ADC_PPB3_TRIPLO_INT_CLR:1;			// 6:6   
	uint16_t	ADC_PPB3_TRIPHI_INT_CLR:1;			// 7:7   
	uint16_t	ADC_PPB3_ZERO_INT_CLR:1;			// 8:8   
	uint16_t	ADC_PPB4_TRIPLO_INT_CLR:1;			// 9:9   
	uint16_t	ADC_PPB4_TRIPHI_INT_CLR:1;			// 10:10   
	uint16_t	ADC_PPB4_ZERO_INT_CLR:1;			// 11:11   
	uint16_t	rsvd1:4;			// 15:12   Reserved
};

union ADC_PPB_INT_CLR_REG {
	uint16_t 		 all;
	struct ADC_PPB_INT_CLR_BITS 		 bit;
};

//
// ADC PPB INT Flag Register
//
struct ADC_PPB_INT_FLAG_BITS {			// bits   description
	uint16_t	ADC_PPB1_TRIPLO_INT_FLAG:1;			// 0:0   
	uint16_t	ADC_PPB1_TRIPHI_INT_FLAG:1;			// 1:1   
	uint16_t	ADC_PPB1_ZERO_INT_FLAG:1;			// 2:2   
	uint16_t	ADC_PPB2_TRIPLO_INT_FLAG:1;			// 3:3   
	uint16_t	ADC_PPB2_TRIPHI_INT_FLAG:1;			// 4:4   
	uint16_t	ADC_PPB2_ZERO_INT_FLAG:1;			// 5:5   
	uint16_t	ADC_PPB3_TRIPLO_INT_FLAG:1;			// 6:6   
	uint16_t	ADC_PPB3_TRIPHI_INT_FLAG:1;			// 7:7   
	uint16_t	ADC_PPB3_ZERO_INT_FLAG:1;			// 8:8   
	uint16_t	ADC_PPB4_TRIPLO_INT_FLAG:1;			// 9:9   
	uint16_t	ADC_PPB4_TRIPHI_INT_FLAG:1;			// 10:10   
	uint16_t	ADC_PPB4_ZERO_INT_FLAG:1;			// 11:11   
	uint16_t	rsvd1:4;			// 15:12   Reserved
};

union ADC_PPB_INT_FLAG_REG {
	uint16_t 		 all;
	struct ADC_PPB_INT_FLAG_BITS 		 bit;
};

//
// ADC PPB INT Mode Register
//
struct ADC_PPB_INT_MODE_BITS {			// bits   description
	uint16_t	ADC_PPB_INT_MODE:1;			// 0:0   
	uint16_t	rsvd1:15;			// 15:1   Reserved
};

union ADC_PPB_INT_MODE_REG {
	uint16_t 		 all;
	struct ADC_PPB_INT_MODE_BITS 		 bit;
};

//
// ADC Trigger Repeater 1 Control Register
//
struct REP1CTL_BITS {			// bits   description
	uint32_t	MODE:1;			// 0:0   ADC trigger repeater 1 mode selection. Select either oversampling or
	uint32_t	ACTIVEMODE:1;			// 1:1   When a trigger is recived in oversampling or undersampling mode
	uint32_t	rsvd1:1;			// 2:2   Reserved
	uint32_t	MODULEBUSY:1;			// 3:3   ADC Trigger Repeater 1 Module Busy indicator. In oversampling
	uint32_t	rsvd2:2;			// 5:4   Reserved
	uint32_t	PHASEOVF:1;			// 6:6   ADC Trigger Repeater 1 Phase Delay Overflow.
	uint32_t	TRIGGEROVF:1;			// 7:7   ADC Trigger Repeater 1 Oversampled Trigger Overflow
	uint32_t	TRIGGER:7;			// 14:8   ADC Trigger Repeater 1 Trigger Select. Selects the trigger to modify
	uint32_t	rsvd3:1;			// 15:15   Reserved
	uint32_t	SYNCINSEL:5;			// 20:16   Trigger repeater 1 sync. input select. On a sync. event, all registers
	uint32_t	rsvd4:2;			// 22:21   Reserved
	uint32_t	SWSYNC:1;			// 23:23   Trigger repeater 1 software force sync. On a sync.event, all registers
	uint32_t	TRIGGEROVF_EN:1;			// 24:24   
	uint32_t	rsvd5:7;			// 31:25   Reserved
};

union REP1CTL_REG {
	uint32_t 		 all;
	struct REP1CTL_BITS 		 bit;
};

//
// ADC Trigger Repeater 1 N Select Register
//
struct REP1N_BITS {			// bits   description
	uint32_t	NSEL:16;			// 15:0   ADC Trigger Repeater 1 selection of number of triggers.
	uint32_t	NCOUNT:16;			// 31:16   ADC trigger repeater 1 trigger count.
};

union REP1N_REG {
	uint32_t 		 all;
	struct REP1N_BITS 		 bit;
};

//
// ADC Trigger Repeater 1 Phase Select Register
//
struct REP1PHASE_BITS {			// bits   description
	uint32_t	PHASE:16;			// 15:0   ADC trigger repeater 1 phase delay configuration. Defines the
	uint32_t	PHASECOUNT:16;			// 31:16   ADC trigger repeater 1 phase delay status. When the trigger
};

union REP1PHASE_REG {
	uint32_t 		 all;
	struct REP1PHASE_BITS 		 bit;
};

//
// ADC Trigger Repeater 1 Spread Select Register
//
struct REP1SPREAD_BITS {			// bits   description
	uint32_t	SPREAD:16;			// 15:0   ADC trigger repeater 1 spread delay configuration. In oversampling
	uint32_t	SPREADCOUNT:16;			// 31:16   ADC trigger repeater 1 spread status. When a trigger is sent to the
};

union REP1SPREAD_REG {
	uint32_t 		 all;
	struct REP1SPREAD_BITS 		 bit;
};

//
// ADC Trigger Repeater 1 Software Force Register
//
struct REP1FRC_BITS {			// bits   description
	uint16_t	SWFRC:1;			// 0:0   Write 1 to force a trigger to repeat block 1 input regardless of the
	uint16_t	rsvd1:15;			// 15:1   Reserved
};

union REP1FRC_REG {
	uint16_t 		 all;
	struct REP1FRC_BITS 		 bit;
};

//
// ADC Trigger Repeater 2 Control Register
//
struct REP2CTL_BITS {			// bits   description
	uint32_t	MODE:1;			// 0:0   ADC trigger repeater 2 mode selection. Select either oversampling or
	uint32_t	ACTIVEMODE:1;			// 1:1   When a trigger is recived in oversampling or undersampling mode
	uint32_t	rsvd1:1;			// 2:2   Reserved
	uint32_t	MODULEBUSY:1;			// 3:3   ADC Trigger Repeater 2 Module Busy indicator. In oversampling
	uint32_t	rsvd2:2;			// 5:4   Reserved
	uint32_t	PHASEOVF:1;			// 6:6   ADC Trigger Repeater 2 Phase Delay Overflow.
	uint32_t	TRIGGEROVF:1;			// 7:7   ADC Trigger Repeater 2 Oversampled Trigger Overflow
	uint32_t	TRIGGER:7;			// 14:8   ADC Trigger Repeater 2 Trigger Select. Selects the trigger to modify
	uint32_t	rsvd3:1;			// 15:15   Reserved
	uint32_t	SYNCINSEL:5;			// 20:16   Trigger repeater 2 sync. input select. On a sync. event, all registers
	uint32_t	rsvd4:2;			// 22:21   Reserved
	uint32_t	SWSYNC:1;			// 23:23   Trigger repeater 2 software force sync. On a sync.event, all registers
	uint32_t	TRIGGEROVF_EN:1;			// 24:24   Write 1 to force a trigger to repeat block 1 input regardless of the
	uint32_t	rsvd5:7;			// 31:25   Reserved
};

union REP2CTL_REG {
	uint32_t 		 all;
	struct REP2CTL_BITS 		 bit;
};

//
// ADC Trigger Repeater 2 N Select Register
//
struct REP2N_BITS {			// bits   description
	uint32_t	NSEL:16;			// 15:0   ADC Trigger Repeater 2 selection of number of triggers.
	uint32_t	NCOUNT:16;			// 31:16   ADC trigger repeater 2 trigger count.
};

union REP2N_REG {
	uint32_t 		 all;
	struct REP2N_BITS 		 bit;
};

//
// ADC Trigger Repeater 2 Phase Select Register
//
struct REP2PHASE_BITS {			// bits   description
	uint32_t	PHASE:16;			// 15:0   ADC trigger repeater 2 phase delay configuration. Defines the
	uint32_t	PHASECOUNT:16;			// 31:16   ADC trigger repeater 2 phase delay status. When the trigger
};

union REP2PHASE_REG {
	uint32_t 		 all;
	struct REP2PHASE_BITS 		 bit;
};

//
// ADC Trigger Repeater 2 Spread Select Register
//
struct REP2SPREAD_BITS {			// bits   description
	uint32_t	SPREAD:16;			// 15:0   ADC trigger repeater 2 spread delay configuration. In oversampling
	uint32_t	SPREADCOUNT:16;			// 31:16   ADC trigger repeater 2 spread status. When a trigger is sent to the
};

union REP2SPREAD_REG {
	uint32_t 		 all;
	struct REP2SPREAD_BITS 		 bit;
};

//
// ADC Trigger Repeater 2 Software Force Register
//
struct REP2FRC_BITS {			// bits   description
	uint16_t	SWFRC:1;			// 0:0   Write 1 to force a trigger to repeat block 2 input regardless of the
	uint16_t	rsvd1:15;			// 15:1   Reserved
};

union REP2FRC_REG {
	uint16_t 		 all;
	struct REP2FRC_BITS 		 bit;
};

//
// ADC PPB1 Sum Shift Register
//
struct ADCPPB1CONFIG2_BITS {			// bits   description
	uint16_t	SHIFT:4;			// 3:0   Post Processing Block 1 right shift. Defines the number of bits to
	uint16_t	SYNCINSEL:5;			// 8:4   PPB 1 sync. input select. On a sync. event, all partial registers
	uint16_t	LIMIT_EARLY_EN:1;			// 9:9   Reserved
	uint16_t	LIMIT_EARLY_FLAG:1;			// 10:10   Reserved
	uint16_t	SWSYNC:1;			// 11:11   PPB 1 software force sync. On a sync.event, all partial registers
	uint16_t	OSINTSEL:1;			// 12:12   Post Processing Block 1 Interrupt Source Select.
	uint16_t	rsvd1:1;			// 13:13   Reserved
	uint16_t	COMPSEL:2;			// 15:14   Post Processing Block 1 Compare Source Select. This field
};

union ADCPPB1CONFIG2_REG {
	uint16_t 		 all;
	struct ADCPPB1CONFIG2_BITS 		 bit;
};

//
// ADC PPB1 Partial Max Register
//
struct ADCPPB1PMAX_BITS {			// bits   description
	uint32_t	PMAX:17;			// 16:0   Post Processing Block 1 Oversampling Partial Max. Each time a
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB1PMAX_REG {
	uint32_t 		 all;
	struct ADCPPB1PMAX_BITS 		 bit;
};

//
// ADC PPB1 Partial MIN Register
//
struct ADCPPB1PMIN_BITS {			// bits   description
	uint32_t	PMIN:17;			// 16:0   Post Processing Block 1 Oversampling Partial Min. Each time a new
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB1PMIN_REG {
	uint32_t 		 all;
	struct ADCPPB1PMIN_BITS 		 bit;
};

//
// ADC PPB2 Sum Shift Register
//
struct ADCPPB2CONFIG2_BITS {			// bits   description
	uint16_t	SHIFT:4;			// 3:0   Post Processing Block 2 right shift. Defines the number of bits to
	uint16_t	SYNCINSEL:5;			// 8:4   PPB 2 sync.input select. On a sync. event, all partial registers
	uint16_t	LIMIT_EARLY_EN:1;			// 9:9   Reserved
	uint16_t	LIMIT_EARLY_FLAG:1;			// 10:10   Reserved
	uint16_t	SWSYNC:1;			// 11:11   PPB 2 software force sync. On a sync.event, all partial registers
	uint16_t	OSINTSEL:1;			// 12:12   Post Processing Block 2 Interrupt Source Select.
	uint16_t	rsvd1:1;			// 13:13   Reserved
	uint16_t	COMPSEL:2;			// 15:14   Post Processing Block 2 Compare Source Select. This field
};

union ADCPPB2CONFIG2_REG {
	uint16_t 		 all;
	struct ADCPPB2CONFIG2_BITS 		 bit;
};

//
// ADC PPB2 Partial Max Register
//
struct ADCPPB2PMAX_BITS {			// bits   description
	uint32_t	PMAX:17;			// 16:0   Post Processing Block 2 Oversampling Partial Max. Each time a
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB2PMAX_REG {
	uint32_t 		 all;
	struct ADCPPB2PMAX_BITS 		 bit;
};

//
// ADC PPB2 Partial MIN Register
//
struct ADCPPB2PMIN_BITS {			// bits   description
	uint32_t	PMIN:17;			// 16:0   Post Processing Block 2 Oversampling Partial Min. Each time a new
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB2PMIN_REG {
	uint32_t 		 all;
	struct ADCPPB2PMIN_BITS 		 bit;
};

//
// ADC PPB3 Sum Shift Register
//
struct ADCPPB3CONFIG2_BITS {			// bits   description
	uint16_t	SHIFT:4;			// 3:0   Post Processing Block 3 right shift. Defines the number of bits to
	uint16_t	SYNCINSEL:5;			// 8:4   PPB 3 sync.input select. On a sync. event, all partial registers
	uint16_t	LIMIT_EARLY_EN:1;			// 9:9   Reserved
	uint16_t	LIMIT_EARLY_FLAG:1;			// 10:10   Reserved
	uint16_t	SWSYNC:1;			// 11:11   PPB 3 software force sync. On a sync.event, all partial registers
	uint16_t	OSINTSEL:1;			// 12:12   Post Processing Block 3 Interrupt Source Select.
	uint16_t	rsvd1:1;			// 13:13   Reserved
	uint16_t	COMPSEL:2;			// 15:14   Post Processing Block 3 Compare Source Select. This field
};

union ADCPPB3CONFIG2_REG {
	uint16_t 		 all;
	struct ADCPPB3CONFIG2_BITS 		 bit;
};

//
// ADC PPB3 Partial Max Register
//
struct ADCPPB3PMAX_BITS {			// bits   description
	uint32_t	PMAX:17;			// 16:0   Post Processing Block 3 Oversampling Partial Max. Each time a
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB3PMAX_REG {
	uint32_t 		 all;
	struct ADCPPB3PMAX_BITS 		 bit;
};

//
// ADC PPB3 Partial MIN Register
//
struct ADCPPB3PMIN_BITS {			// bits   description
	uint32_t	PMIN:17;			// 16:0   Post Processing Block 3 Oversampling Partial Min. Each time a new
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB3PMIN_REG {
	uint32_t 		 all;
	struct ADCPPB3PMIN_BITS 		 bit;
};

//
// ADC PPB4 Sum Shift Register
//
struct ADCPPB4CONFIG2_BITS {			// bits   description
	uint16_t	SHIFT:4;			// 3:0   Post Processing Block 4 right shift. Defines the number of bits to
	uint16_t	SYNCINSEL:5;			// 8:4   PPB 4 sync.input select. On a sync. event, all partial registers
	uint16_t	LIMIT_EARLY_EN:1;			// 9:9   Reserved
	uint16_t	LIMIT_EARLY_FLAG:1;			// 10:10   Reserved
	uint16_t	SWSYNC:1;			// 11:11   PPB 4 software force sync. On a sync.event, all partial registers
	uint16_t	OSINTSEL:1;			// 12:12   Post Processing Block 4 Interrupt Source Select.
	uint16_t	rsvd1:1;			// 13:13   Reserved
	uint16_t	COMPSEL:2;			// 15:14   Post Processing Block 4 Compare Source Select. This field
};

union ADCPPB4CONFIG2_REG {
	uint16_t 		 all;
	struct ADCPPB4CONFIG2_BITS 		 bit;
};

//
// ADC PPB4 Partial Max Register
//
struct ADCPPB4PMAX_BITS {			// bits   description
	uint32_t	PMAX:17;			// 16:0   Post Processing Block 4 Oversampling Partial Max. Each time a
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB4PMAX_REG {
	uint32_t 		 all;
	struct ADCPPB4PMAX_BITS 		 bit;
};

//
// ADC PPB4 Partial MIN Register
//
struct ADCPPB4PMIN_BITS {			// bits   description
	uint32_t	PMIN:17;			// 16:0   Post Processing Block 4 Oversampling Partial Min. Each time a new
	uint32_t	SIGN:15;			// 31:17   Sign Extended Bits. These bits reflect the same value as bit 16.
};

union ADCPPB4PMIN_REG {
	uint32_t 		 all;
	struct ADCPPB4PMIN_BITS 		 bit;
};

//
// ADC SOC Priority Control Register
//
struct ADCSOCPRICTL2_BITS {			// bits   description
	uint16_t	SOC_PRIORITY2:5;			// 4:0   SOC Priority
	uint16_t	SOC_RRPOINTER2:5;			// 9:5   Round Robin Pointer. Holds the value of the last converted round
	uint16_t	SOC_MODE:1;			// 10:10   
	uint16_t	rsvd1:5;			// 15:11   Reserved
};

union ADCSOCPRICTL2_REG {
	uint16_t 		 all;
	struct ADCSOCPRICTL2_BITS 		 bit;
};

//
// ADC Interrupt SOC Selection 3 Register
//
struct ADCINTSOCSEL3_BITS {			// bits   description
	uint16_t	INT_SOC_16SEL:2;			// 1:0   SOC8 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	INT_SOC_17SEL:2;			// 3:2   SOC9 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	INT_SOC_18SEL:2;			// 5:4   SOC10 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	INT_SOC_19SEL:2;			// 7:6   SOC11 ADC Interrupt Trigger Select. Selects which, if any, ADCINT
	uint16_t	rsvd1:8;			// 15:8   Reserved
};

union ADCINTSOCSEL3_REG {
	uint16_t 		 all;
	struct ADCINTSOCSEL3_BITS 		 bit;
};

//
// ADC SOC Flag 2 Register
//
struct ADCSOCFLG2_BITS {			// bits   description
	uint16_t	SOC_16FLAG:1;			// 0:0   SOCO Start of Conversion Flag. Indicates the state of SOCO
	uint16_t	SOC_17FLAG:1;			// 1:1   SOC1 Start of Conversion Flag. Indicates the state of SOC1
	uint16_t	SOC_18FLAG:1;			// 2:2   SOC2 Start of Conversion Flag. Indicates the state of SOC2
	uint16_t	SOC_19FLAG:1;			// 3:3   SOC3 Start of Conversion Flag. Indicates the state of SOC3
	uint16_t	rsvd1:12;			// 15:4   Reserved
};

union ADCSOCFLG2_REG {
	uint16_t 		 all;
	struct ADCSOCFLG2_BITS 		 bit;
};

//
// ADC SOC Force 2 Register
//
struct ADCSOCFRC2_BITS {			// bits   description
	uint16_t	SOC_16FRC:1;			// 0:0   SOC0 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC_17FRC:1;			// 1:1   SOC1 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC_18FRC:1;			// 2:2   SOC2 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	SOC_19FRC:1;			// 3:3   SOC3 Force Start of Conversion Bit. Writing a 1 will force to 1 the
	uint16_t	rsvd1:12;			// 15:4   Reserved
};

union ADCSOCFRC2_REG {
	uint16_t 		 all;
	struct ADCSOCFRC2_BITS 		 bit;
};

//
// ADC SOC Overflow 2 Register
//
struct ADCSOCOVF2_BITS {			// bits   description
	uint16_t	SOC_16OVF:1;			// 0:0   SOC0 Start of Conversion Overflow Flag. Indicates an SOCo event
	uint16_t	SOC_17OVF:1;			// 1:1   SOC1 Start of Conversion Overflow Flag. Indicates an SOC1 event
	uint16_t	SOC_18OVF:1;			// 2:2   SOC2 Start of Conversion Overflow Flag. Indicates an SOC2 event
	uint16_t	SOC_19OVF:1;			// 3:3   SOC3 Start of Conversion Overflow Flag. Indicates an SOC3 event
	uint16_t	rsvd1:12;			// 15:4   Reserved
};

union ADCSOCOVF2_REG {
	uint16_t 		 all;
	struct ADCSOCOVF2_BITS 		 bit;
};

//
// ADC SOC Overflow Clear 2 Register
//
struct ADCSOCOVFCLR2_BITS {			// bits   description
	uint16_t	SOC_OVF_16CLR:1;			// 0:0   SOC0 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC_OVF_17CLR:1;			// 1:1   SOC1 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC_OVF_18CLR:1;			// 2:2   SOC2 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	SOC_OVF_19CLR:1;			// 3:3   SOC3 Clear Start of Conversion Overflow Bit. Writing a 1 will clear
	uint16_t	rsvd1:12;			// 15:4   Reserved
};

union ADCSOCOVFCLR2_REG {
	uint16_t 		 all;
	struct ADCSOCOVFCLR2_BITS 		 bit;
};

//
// ADC SOC16 Control Register
//
struct ADCSOC16CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC12 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC12 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC12 Trigger Source Select. Along with the SOC12 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC16CTL_REG {
	uint32_t 		 all;
	struct ADCSOC16CTL_BITS 		 bit;
};

//
// ADC SOC17 Control Register
//
struct ADCSOC17CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC13 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC13 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC13 Trigger Source Select. Along with the SOC13 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC17CTL_REG {
	uint32_t 		 all;
	struct ADCSOC17CTL_BITS 		 bit;
};

//
// ADC SOC18 Control Register
//
struct ADCSOC18CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC14 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC14 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC14 Trigger Source Select. Along with the SOC14 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC18CTL_REG {
	uint32_t 		 all;
	struct ADCSOC18CTL_BITS 		 bit;
};

//
// ADC SOC19 Control Register
//
struct ADCSOC19CTL_BITS {			// bits   description
	uint32_t	ACQPS:9;			// 8:0   SOC15 Acquisition Prescale. Controls the sample and hold window
	uint32_t	rsvd1:6;			// 14:9   Reserved
	uint32_t	CHSEL:5;			// 19:15   SOC15 Channel Select. Selects the channel to be converted when
	uint32_t	TRIGSEL:7;			// 26:20   SOC15 Trigger Source Select. Along with the SOC15 field in the
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union ADCSOC19CTL_REG {
	uint32_t 		 all;
	struct ADCSOC19CTL_BITS 		 bit;
};

struct MAP_1CFG_BITS {			// bits   description
	uint32_t	MAP_2CFG:13;			// 12:0   
	uint32_t	rsvd1:3;			// 15:13   Reserved
	uint32_t	MAP_1CFG:13;			// 28:16   
	uint32_t	rsvd2:3;			// 31:29   Reserved
};

union MAP_1CFG_REG {
	uint32_t 		 all;
	struct MAP_1CFG_BITS 		 bit;
};

struct MAP_2CFG_BITS {			// bits   description
	uint32_t	MAP_4CFG:11;			// 10:0   
	uint32_t	rsvd1:5;			// 15:11   Reserved
	uint32_t	MAP_3CFG:12;			// 27:16   
	uint32_t	rsvd2:4;			// 31:28   Reserved
};

union MAP_2CFG_REG {
	uint32_t 		 all;
	struct MAP_2CFG_BITS 		 bit;
};

struct MAP_3CFG_BITS {			// bits   description
	uint32_t	MAP_6CFG:10;			// 9:0   
	uint32_t	rsvd1:6;			// 15:10   Reserved
	uint32_t	MAP_5CFG:11;			// 26:16   
	uint32_t	rsvd2:5;			// 31:27   Reserved
};

union MAP_3CFG_REG {
	uint32_t 		 all;
	struct MAP_3CFG_BITS 		 bit;
};

struct MAP_4CFG_BITS {			// bits   description
	uint32_t	MAP_8CFG:8;			// 7:0   
	uint32_t	rsvd1:8;			// 15:8   Reserved
	uint32_t	MAP_7CFG:9;			// 24:16   
	uint32_t	rsvd2:3;			// 27:25   Reserved
	uint32_t	MAP_EN:1;			// 28:28   
	uint32_t	rsvd3:3;			// 31:29   Reserved
};

union MAP_4CFG_REG {
	uint32_t 		 all;
	struct MAP_4CFG_BITS 		 bit;
};

struct MAP_5CFG_BITS {			// bits   description
	uint32_t	MAP_10CFG:7;			// 6:0   
	uint32_t	rsvd1:9;			// 15:7   Reserved
	uint32_t	MAP_9CFG:8;			// 23:16   
	uint32_t	rsvd2:8;			// 31:24   Reserved
};

union MAP_5CFG_REG {
	uint32_t 		 all;
	struct MAP_5CFG_BITS 		 bit;
};

struct MAP_6CFG_BITS {			// bits   description
	uint32_t	MAP_12CFG:5;			// 4:0   
	uint32_t	rsvd1:11;			// 15:5   Reserved
	uint32_t	MAP_11CFG:6;			// 21:16   
	uint32_t	rsvd2:10;			// 31:22   Reserved
};

union MAP_6CFG_REG {
	uint32_t 		 all;
	struct MAP_6CFG_BITS 		 bit;
};

struct MAP_7CFG_BITS {			// bits   description
	uint32_t	MAP_14CFG:4;			// 3:0   
	uint32_t	rsvd1:12;			// 15:4   Reserved
	uint32_t	MAP_13CFG:4;			// 19:16   
	uint32_t	rsvd2:12;			// 31:20   Reserved
};

union MAP_7CFG_REG {
	uint32_t 		 all;
	struct MAP_7CFG_BITS 		 bit;
};

struct PRE_CTL_BITS {			// bits   description
	uint32_t	PRE_EN:1;			// 0:0   
	uint32_t	rsvd1:3;			// 3:1   Reserved
	uint32_t	PRE_CH_SEL:5;			// 8:4   
	uint32_t	rsvd2:7;			// 15:9   Reserved
	uint32_t	PRE_PERIOD:16;			// 31:16   
};

union PRE_CTL_REG {
	uint32_t 		 all;
	struct PRE_CTL_BITS 		 bit;
};

struct PRE_FRC_BITS {			// bits   description
	uint32_t	PRE_FRC:1;			// 0:0  
	uint32_t	rsvd1:3;			// 3:1   Reserved
	uint32_t	PRE_MODE:1;			// 4:4   
	uint32_t	rsvd2:27;			// 31:5   Reserved
};

union PRE_FRC_REG {
	uint32_t 		 all;
	struct PRE_FRC_BITS 		 bit;
};

struct PRE_GAIN_BITS {			// bits   description
	uint32_t	PRE_GAIN:12;			// 11:0   
	uint32_t	rsvd1:20;			// 31:12   Reserved
};

union PRE_GAIN_REG {
	uint32_t 		 all;
	struct PRE_GAIN_BITS 		 bit;
};

struct PRE_OFFSET_BITS {			// bits   description
	uint32_t	PRE_OFFSET:10;			// 9:0   
	uint32_t	rsvd1:6;			// 15:10   Reserved
	uint32_t	PRE_PRO_EN:1;			// 16:16   
	uint32_t	rsvd2:15;			// 31:17   Reserved
};

union PRE_OFFSET_REG {
	uint32_t 		 all;
	struct PRE_OFFSET_BITS 		 bit;
};


// ADC Register Definitions:

struct ADC_RESULT_REGS {
	uint16_t  						ADCRESULT0;
	uint16_t  						ADCRESULT1;
	uint16_t  						ADCRESULT2;
	uint16_t  						ADCRESULT3;
	uint16_t  						ADCRESULT4;
	uint16_t  						ADCRESULT5;
	uint16_t  						ADCRESULT6;
	uint16_t  						ADCRESULT7;
	uint16_t  						ADCRESULT8;
	uint16_t  						ADCRESULT9;
	uint16_t  						ADCRESULT10;
	uint16_t  						ADCRESULT11;
	uint16_t  						ADCRESULT12;
	uint16_t  						ADCRESULT13;
	uint16_t  						ADCRESULT14;
	uint16_t  						ADCRESULT15;
	union  ADCPPB1RESULT_REG		ADCPPB1RESULT;
	union  ADCPPB2RESULT_REG		ADCPPB2RESULT;
	union  ADCPPB3RESULT_REG		ADCPPB3RESULT;
	union  ADCPPB4RESULT_REG		ADCPPB4RESULT;
	uint32_t  						ADCPPB1SUM;
	uint16_t  						ADCPPB1COUNT;
	uint16_t 						rsvd1; 		 // Reserved
	uint32_t  						ADCPPB2SUM;
	uint16_t  						ADCPPB2COUNT;
	uint16_t 						rsvd2; 		 // Reserved
	uint32_t  						ADCPPB3SUM;
	uint16_t  						ADCPPB3COUNT;
	uint16_t 						rsvd3; 		 // Reserved
	uint32_t  						ADCPPB4SUM;
	uint16_t  						ADCPPB4COUNT;
	uint16_t 						rsvd4; 		 // Reserved
	union  ADCPPB1MAX_REG			ADCPPB1MAX;
	uint16_t  						ADCPPB1MAXI;
	uint16_t 						rsvd5; 		 // Reserved
	union  ADCPPB1MIN_REG			ADCPPB1MIN;
	uint16_t  						ADCPPB1MINI;
	uint16_t 						rsvd6; 		 // Reserved
	union  ADCPPB2MAX_REG			ADCPPB2MAX;
	uint16_t  						ADCPPB2MAXI;
	uint16_t 						rsvd7; 		 // Reserved
	union  ADCPPB2MIN_REG			ADCPPB2MIN;
	uint16_t  						ADCPPB2MINI;
	uint16_t 						rsvd8; 		 // Reserved
	union  ADCPPB3MAX_REG			ADCPPB3MAX;
	uint16_t  						ADCPPB3MAXI;
	uint16_t 						rsvd9; 		 // Reserved
	union  ADCPPB3MIN_REG			ADCPPB3MIN;
	uint16_t  						ADCPPB3MINI;
	uint16_t 						rsvd10; 		 // Reserved
	union  ADCPPB4MAX_REG			ADCPPB4MAX;
	uint16_t  						ADCPPB4MAXI;
	uint16_t 						rsvd11; 		 // Reserved
	union  ADCPPB4MIN_REG			ADCPPB4MIN;
	uint16_t  						ADCPPB4MINI;
	uint16_t 						rsvd12[41]; 		 // Reserved
	uint16_t  						ADCRESULT16;
	uint16_t  						ADCRESULT17;
	uint16_t  						ADCRESULT18;
	uint16_t  						ADCRESULT19;
	uint16_t 						rsvd13[4]; 		 // Reserved
	union  ADCMEANEN_REG			ADCMEANEN;
	union  ADCMEANEN2_REG			ADCMEANEN2;
	union  ADCFPRND_REG				ADCFPRND;
	union  ADCSMPSEL_REG			ADCSMPSEL;
	uint32_t  						ADC32RESULT0;
	uint32_t  						ADC32RESULT1;
	uint32_t  						ADC32RESULT2;
	uint32_t  						ADC32RESULT3;
	uint32_t  						ADC32RESULT4;
	uint32_t  						ADC32RESULT5;
	uint32_t  						ADC32RESULT6;
	uint32_t  						ADC32RESULT7;
	uint32_t  						ADC32RESULT8;
	uint32_t  						ADC32RESULT9;
	uint32_t  						ADC32RESULT10;
	uint32_t  						ADC32RESULT11;
	uint32_t  						ADC32RESULT12;
	uint32_t  						ADC32RESULT13;
	uint32_t  						ADC32RESULT14;
	uint32_t  						ADC32RESULT15;
	uint32_t  						ADC32RESULT16;
	uint32_t  						ADC32RESULT17;
	uint32_t  						ADC32RESULT18;
	uint32_t  						ADC32RESULT19;
	uint32_t  						ADCSCALE0;
	uint32_t  						ADCSCALE1;
	uint32_t  						ADCSCALE2;
	uint32_t  						ADCSCALE3;
	uint32_t  						ADCSCALE4;
	uint32_t  						ADCSCALE5;
	uint32_t  						ADCSCALE6;
	uint32_t  						ADCSCALE7;
	uint32_t  						ADCSCALE8;
	uint32_t  						ADCSCALE9;
	uint32_t  						ADCSCALE10;
	uint32_t  						ADCSCALE11;
	uint32_t  						ADCSCALE12;
	uint32_t  						ADCSCALE13;
	uint32_t  						ADCSCALE14;
	uint32_t  						ADCSCALE15;
	uint32_t  						ADCSCALE16;
	uint32_t  						ADCSCALE17;
	uint32_t  						ADCSCALE18;
	uint32_t  						ADCSCALE19;
	uint32_t  						ADCOFFSET0;
	uint32_t  						ADCOFFSET1;
	uint32_t  						ADCOFFSET2;
	uint32_t  						ADCOFFSET3;
	uint32_t  						ADCOFFSET4;
	uint32_t  						ADCOFFSET5;
	uint32_t  						ADCOFFSET6;
	uint32_t  						ADCOFFSET7;
	uint32_t  						ADCOFFSET8;
	uint32_t  						ADCOFFSET9;
	uint32_t  						ADCOFFSET10;
	uint32_t  						ADCOFFSET11;
	uint32_t  						ADCOFFSET12;
	uint32_t  						ADCOFFSET13;
	uint32_t  						ADCOFFSET14;
	uint32_t  						ADCOFFSET15;
	uint32_t  						ADCOFFSET16;
	uint32_t  						ADCOFFSET17;
	uint32_t  						ADCOFFSET18;
	uint32_t  						ADCOFFSET19;
};

struct ADC_REGS {
	union  ADCCTL1_REG				ADCCTL1;
	union  ADCCTL2_REG				ADCCTL2;
	union  ADCBURSTCTL_REG			ADCBURSTCTL;
	union  ADCINTFLG_REG			ADCINTFLG;
	union  ADCINTFLGCLR_REG			ADCINTFLGCLR;
	union  ADCINTOVF_REG			ADCINTOVF;
	union  ADCINTOVFCLR_REG			ADCINTOVFCLR;
	union  ADCINTSEL1N2_REG			ADCINTSEL1N2;
	union  ADCINTSEL3N4_REG			ADCINTSEL3N4;
	union  ADCSOCPRICTL_REG			ADCSOCPRICTL;
	union  ADCINTSOCSEL1_REG		ADCINTSOCSEL1;
	union  ADCINTSOCSEL2_REG		ADCINTSOCSEL2;
	union  ADCSOCFLG1_REG			ADCSOCFLG1;
	union  ADCSOCFRC1_REG			ADCSOCFRC1;
	union  ADCSOCOVF1_REG			ADCSOCOVF1;
	union  ADCSOCOVFCLR1_REG		ADCSOCOVFCLR1;
	union  ADCSOC0CTL_REG			ADCSOC0CTL;
	union  ADCSOC1CTL_REG			ADCSOC1CTL;
	union  ADCSOC2CTL_REG			ADCSOC2CTL;
	union  ADCSOC3CTL_REG			ADCSOC3CTL;
	union  ADCSOC4CTL_REG			ADCSOC4CTL;
	union  ADCSOC5CTL_REG			ADCSOC5CTL;
	union  ADCSOC6CTL_REG			ADCSOC6CTL;
	union  ADCSOC7CTL_REG			ADCSOC7CTL;
	union  ADCSOC8CTL_REG			ADCSOC8CTL;
	union  ADCSOC9CTL_REG			ADCSOC9CTL;
	union  ADCSOC10CTL_REG			ADCSOC10CTL;
	union  ADCSOC11CTL_REG			ADCSOC11CTL;
	union  ADCSOC12CTL_REG			ADCSOC12CTL;
	union  ADCSOC13CTL_REG			ADCSOC13CTL;
	union  ADCSOC14CTL_REG			ADCSOC14CTL;
	union  ADCSOC15CTL_REG			ADCSOC15CTL;
	union  ADCEVTSTAT_REG			ADCEVTSTAT;
	uint16_t 						rsvd1; 		 // Reserved
	union  ADCEVTCLR_REG			ADCEVTCLR;
	uint16_t 						rsvd2; 		 // Reserved
	union  ADCEVTSEL_REG			ADCEVTSEL;
	uint16_t 						rsvd3; 		 // Reserved
	union  ADCEVTINTSEL_REG			ADCEVTINTSEL;
	uint16_t 						rsvd4; 		 // Reserved
	union  ADCOSDETECT_REG			ADCOSDETECT;
	union  ADCCOUNTER_REG			ADCCOUNTER;
	uint16_t 						rsvd5; 		 // Reserved
	union  ADCOFFTRIM_REG			ADCOFFTRIM;
	uint16_t 						rsvd6[4]; 		 // Reserved
	union  ADCPPB1CONFIG_REG		ADCPPB1CONFIG;
	union  ADCPPB1STAMP_REG			ADCPPB1STAMP;
	union  ADCPPB1OFFCAL_REG		ADCPPB1OFFCAL;
	uint16_t  						ADCPPB1OFFREF;
	uint32_t  						ADCPPB1TRIPHI;
	union  ADCPPB1TRIPLO_REG		ADCPPB1TRIPLO;
	union  ADCPPB2CONFIG_REG		ADCPPB2CONFIG;
	union  ADCPPB2STAMP_REG			ADCPPB2STAMP;
	union  ADCPPB2OFFCAL_REG		ADCPPB2OFFCAL;
	uint16_t  						ADCPPB2OFFREF;
	uint32_t  						ADCPPB2TRIPHI;
	union  ADCPPB2TRIPLO_REG		ADCPPB2TRIPLO;
	union  ADCPPB3CONFIG_REG		ADCPPB3CONFIG;
	union  ADCPPB3STAMP_REG			ADCPPB3STAMP;
	union  ADCPPB3OFFCAL_REG		ADCPPB3OFFCAL;
	uint16_t  						ADCPPB3OFFREF;
	uint32_t  						ADCPPB3TRIPHI;
	union  ADCPPB3TRIPLO_REG		ADCPPB3TRIPLO;
	union  ADCPPB4CONFIG_REG		ADCPPB4CONFIG;
	union  ADCPPB4STAMP_REG			ADCPPB4STAMP;
	union  ADCPPB4OFFCAL_REG		ADCPPB4OFFCAL;
	uint16_t  						ADCPPB4OFFREF;
	uint32_t  						ADCPPB4TRIPHI;
	union  ADCPPB4TRIPLO_REG		ADCPPB4TRIPLO;
	uint32_t 						rsvd7[5]; 		 // Reserved
	union  ADC_PPB_INT_CLR_REG		PPBINT_CLR;
	union  ADC_PPB_INT_FLAG_REG		PPBINT_FLAG;
	union  ADC_PPB_INT_MODE_REG		PPBINT_MODE;
	uint16_t 						rsvd8[2]; 		 // Reserved
	uint16_t  						ADCINTCYCLE;
	uint32_t  						ADCINLTRIM1;
	uint32_t  						ADCINLTRIM2;
	uint32_t  						ADCINLTRIM3;
	uint32_t 						rsvd9[5]; 		 // Reserved
	union  REP1CTL_REG				REP1CTL;
	union  REP1N_REG				REP1N;
	union  REP1PHASE_REG			REP1PHASE;
	union  REP1SPREAD_REG			REP1SPREAD;
	union  REP1FRC_REG				REP1FRC;
	uint16_t 						rsvd10[7]; 		 // Reserved
	union  REP2CTL_REG				REP2CTL;
	union  REP2N_REG				REP2N;
	union  REP2PHASE_REG			REP2PHASE;
	union  REP2SPREAD_REG			REP2SPREAD;
	union  REP2FRC_REG				REP2FRC;
	uint16_t 						rsvd11[7]; 		 // Reserved
	uint16_t  						ADCPPB1LIMIT;
	uint16_t 						rsvd12; 		 // Reserved
	uint16_t  						ADCPPBP1COUNT;
	uint16_t 						rsvd13; 		 // Reserved
	union  ADCPPB1CONFIG2_REG		ADCPPB1CONFIG2;
	uint16_t 						rsvd14; 		 // Reserved
	uint32_t  						ADCPPB1PSUM;
	union  ADCPPB1PMAX_REG			ADCPPB1PMAX;
	uint16_t  						ADCPPB1PMAXI;
	uint16_t 						rsvd15; 		 // Reserved
	union  ADCPPB1PMIN_REG			ADCPPB1PMIN;
	uint16_t  						ADCPPB1PMINI;
	uint16_t 						rsvd16; 		 // Reserved
	uint32_t  						ADCPPB1TRIPLO2;
	uint32_t 						rsvd17[4]; 		 // Reserved
	uint16_t  						ADCPPB2LIMIT;
	uint16_t 						rsvd18; 		 // Reserved
	uint16_t  						ADCPPBP2COUNT;
	uint16_t 						rsvd19; 		 // Reserved
	union  ADCPPB2CONFIG2_REG		ADCPPB2CONFIG2;
	uint16_t 						rsvd20; 		 // Reserved
	uint32_t  						ADCPPB2PSUM;
	union  ADCPPB2PMAX_REG			ADCPPB2PMAX;
	uint16_t  						ADCPPB2PMAXI;
	uint16_t 						rsvd21; 		 // Reserved
	union  ADCPPB2PMIN_REG			ADCPPB2PMIN;
	uint16_t  						ADCPPB2PMINI;
	uint16_t 						rsvd22; 		 // Reserved
	uint32_t  						ADCPPB2TRIPLO2;
	uint32_t 						rsvd23[4]; 		 // Reserved
	uint16_t  						ADCPPB3LIMIT;
	uint16_t 						rsvd24; 		 // Reserved
	uint16_t  						ADCPPBP3COUNT;
	uint16_t 						rsvd25; 		 // Reserved
	union  ADCPPB3CONFIG2_REG		ADCPPB3CONFIG2;
	uint16_t 						rsvd26; 		 // Reserved
	uint32_t  						ADCPPB3PSUM;
	union  ADCPPB3PMAX_REG			ADCPPB3PMAX;
	uint16_t  						ADCPPB3PMAXI;
	uint16_t 						rsvd27; 		 // Reserved
	union  ADCPPB3PMIN_REG			ADCPPB3PMIN;
	uint16_t  						ADCPPB3PMINI;
	uint16_t 						rsvd28; 		 // Reserved
	uint32_t  						ADCPPB3TRIPLO2;
	uint32_t 						rsvd29[4]; 		 // Reserved
	uint16_t  						ADCPPB4LIMIT;
	uint16_t 						rsvd30; 		 // Reserved
	uint16_t  						ADCPPBP4COUNT;
	uint16_t 						rsvd31; 		 // Reserved
	union  ADCPPB4CONFIG2_REG		ADCPPB4CONFIG2;
	uint16_t 						rsvd32; 		 // Reserved
	uint32_t  						ADCPPB4PSUM;
	union  ADCPPB4PMAX_REG			ADCPPB4PMAX;
	uint16_t  						ADCPPB4PMAXI;
	uint16_t 						rsvd33; 		 // Reserved
	union  ADCPPB4PMIN_REG			ADCPPB4PMIN;
	uint16_t  						ADCPPB4PMINI;
	uint16_t 						rsvd34; 		 // Reserved
	uint32_t  						ADCPPB4TRIPLO2;
	union  ADCSOCPRICTL2_REG		ADCSOCPRICTL2;
	union  ADCINTSOCSEL3_REG		ADCINTSOCSEL3;
	union  ADCSOCFLG2_REG			ADCSOCFLG2;
	union  ADCSOCFRC2_REG			ADCSOCFRC2;
	union  ADCSOCOVF2_REG			ADCSOCOVF2;
	union  ADCSOCOVFCLR2_REG		ADCSOCOVFCLR2;
	uint16_t 						rsvd35[2]; 		 // Reserved
	union  ADCSOC16CTL_REG			ADCSOC16CTL;
	union  ADCSOC17CTL_REG			ADCSOC17CTL;
	union  ADCSOC18CTL_REG			ADCSOC18CTL;
	union  ADCSOC19CTL_REG			ADCSOC19CTL;
	union  MAP_1CFG_REG				MAP_1CFG;
	union  MAP_2CFG_REG				MAP_2CFG;
	union  MAP_3CFG_REG				MAP_3CFG;
	union  MAP_4CFG_REG				MAP_4CFG;
	union  MAP_5CFG_REG				MAP_5CFG;
	union  MAP_6CFG_REG				MAP_6CFG;
	union  MAP_7CFG_REG				MAP_7CFG;
	union  PRE_CTL_REG				PRE_CTL;
	union  PRE_FRC_REG				PRE_FRC;
	union  PRE_GAIN_REG				PRE_GAIN;
	union  PRE_OFFSET_REG			PRE_OFFSET;
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

// ADC External References & Function Declarations

extern volatile struct ADC_RESULT_REGS adcresultRegs;
extern volatile struct ADC_REGS adcRegs;

/**
 * \brief   "add brief description of this function"
 *
 * \param   parameter1   description of parameter1
 * \param   parameter2   description of parameter2
 *
 * \retval  None
 */

#ifdef __cplusplus
}
#endif      /* extern "C" */


#endif      // end of REGS_ADC_H definition

