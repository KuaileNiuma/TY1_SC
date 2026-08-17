

#ifndef REGS_SDFM_H_
#define REGS_SDFM_H_

#ifdef __cplusplus
extern "C" {
#endif



/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define SDFM_TYPE_CTRL 				  0x70CU  // Control SD CLK type Register

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
// SDFM Individual Register Bit Definitions:

struct SDIFLG_BITS {				// bits   description
	uint32_t FLT1_FLG_CEVT1:1;		// 0:0    High-level Interrupt flag for Ch1
	uint32_t FLT1_FLG_CEVT2:1;		// 1:1	  Low-level Interrupt flag for Ch1
	uint32_t FLT2_FLG_CEVT1:1;		// 2:2	  High-level Interrupt flag for Ch2
	uint32_t FLT2_FLG_CEVT2:1;		// 3:3	  Low-level Interrupt flag for Ch2
	uint32_t FLT3_FLG_CEVT1:1;		// 4:4	  High-level Interrupt flag for Ch3
	uint32_t FLT3_FLG_CEVT2:1;		// 5:5	  Low-level Interrupt flag for Ch3
	uint32_t FLT4_FLG_CEVT1:1;		// 6:6	  High-level Interrupt flag for Ch4
	uint32_t FLT4_FLG_CEVT2:1;		// 7:7	  Low-level Interrupt flag for Ch4
	uint32_t MF1:1;					// 8:8	  Modulator Failure for Filter 1
	uint32_t MF2:1;					// 9:9	  Modulator Failure for Filter 2
	uint32_t MF3:1;					// 10:10  Modulator Failure for Filter 3
	uint32_t MF4:1;					// 11:11  Modulator Failure for Filter 4
	uint32_t AF1:1;					// 12:12  Acknowledge flag for Filter 1
	uint32_t AF2:1;					// 13:13  Acknowledge flag for Filter 2
	uint32_t AF3:1;					// 14:14  Acknowledge flag for Filter 3
	uint32_t AF4:1;					// 15:15  Acknowledge flag for Filter 4
	uint32_t SDFFOVF1:1;			// 16:16  FIFO Overflow Flag for Ch1
	uint32_t SDFFOVF2:1;			// 17:17  FIFO Overflow Flag for Ch2
	uint32_t SDFFOVF3:1;			// 18:18  FIFO Overflow Flag for Ch3
	uint32_t SDFFOVF4:1;			// 19:19  FIFO Overflow Flag for Ch4
	uint32_t SDFFINT1:1;			// 20:20  SDFIFO interrupt for Ch1
	uint32_t SDFFINT2:1;			// 21:21  SDFIFO interrupt for Ch2
	uint32_t SDFFINT3:1;			// 22:22  SDFIFO interrupt for Ch3
	uint32_t SDFFINT4:1;			// 23:23  SDFIFO interrupt for Ch4

	uint32_t rsvd1:7;				// 30:24  reserved

	uint32_t FLT5_FLG_CEVT1:1;		// 24:24  High-level Interrupt flag for Ch5
	uint32_t FLT5_FLG_CEVT2:1;		// 25:25  Low-level Interrupt flag for Ch5
	uint32_t MF5:1;					// 26:26  Modulator Failure for Filter 5
	uint32_t AF5:1;					// 27:27  Acknowledge flag for Filter 5
	uint32_t SDFFOVF5:1;			// 28:28  FIFO Overflow Flag for Ch5
	uint32_t SDFFINT5:1;			// 29:29  SDFIFO interrupt for Ch5
	uint32_t rsvd1:1;				// 30:30  reserved

	uint32_t MIF:1;					// 31:31  Master Interrupt Flag
};

union SDIFLG_REG {
	uint32_t all;
	struct SDIFLG_BITS bit;
};

struct SDIFLGCLR_BITS {				// bits   description
	uint32_t FLT1_FLG_CEVT1:1;		// 0:0	  High-level Interrupt flag for Ch1
	uint32_t FLT1_FLG_CEVT2:1;		// 1:1	  Low-level Interrupt flag for Ch1
	uint32_t FLT2_FLG_CEVT1:1;		// 2:2	  High-level Interrupt flag for Ch2
	uint32_t FLT2_FLG_CEVT2:1;		// 3:3	  Low-level Interrupt flag for Ch2
	uint32_t FLT3_FLG_CEVT1:1;		// 4:4	  High-level Interrupt flag for Ch3
	uint32_t FLT3_FLG_CEVT2:1;		// 5:5	  Low-level Interrupt flag for Ch3
	uint32_t FLT4_FLG_CEVT1:1;		// 6:6	  High-level Interrupt flag for Ch4
	uint32_t FLT4_FLG_CEVT2:1;		// 7:7	  Low-level Interrupt flag for Ch4
	uint32_t MF1:1;					// 8:8	  Modulator Failure for Filter 1
	uint32_t MF2:1;					// 9:9	  Modulator Failure for Filter 2
	uint32_t MF3:1;					// 10:10  Modulator Failure for Filter 3
	uint32_t MF4:1;					// 11:11  Modulator Failure for Filter 4
	uint32_t AF1:1;					// 12:12  Acknowledge flag for Filter 1
	uint32_t AF2:1;					// 13:13  Acknowledge flag for Filter 2
	uint32_t AF3:1;					// 14:14  Acknowledge flag for Filter 3
	uint32_t AF4:1;					// 15:15  Acknowledge flag for Filter 4
	uint32_t SDFFOVF1:1;			// 16:16  SDFIFO overflow clear Ch1
	uint32_t SDFFOVF2:1;			// 17:17  SDFIFO overflow clear Ch2
	uint32_t SDFFOVF3:1;			// 18:18  SDFIFO overflow clear Ch3
	uint32_t SDFFOVF4:1;			// 19:19  SDFIFO overflow clear Ch4
	uint32_t SDFFINT1:1;			// 20:20  SDFIFO Interrupt flag-clear bit for Ch1
	uint32_t SDFFINT2:1;			// 21:21  SDFIFO Interrupt flag-clear bit for Ch2
	uint32_t SDFFINT3:1;			// 22:22  SDFIFO Interrupt flag-clear bit for Ch3
	uint32_t SDFFINT4:1;			// 23:23  SDFIFO Interrupt flag-clear bit for Ch4

	uint32_t rsvd1:7;				// 30:24  reserved

	uint32_t FLT5_FLG_CEVT1:1;		// 24:24  High-level Interrupt flag for Ch5
	uint32_t FLT5_FLG_CEVT2:1;		// 25:25  Low-level Interrupt flag for Ch5
	uint32_t MF5:1;					// 26:26  Modulator Failure for Filter 5
	uint32_t AF5:1;					// 27:27  Acknowledge flag for Filter 5
	uint32_t SDFFOVF5:1;			// 28:28  FIFO Overflow Flag for Ch5
	uint32_t SDFFINT5:1;			// 29:29  SDFIFO interrupt for Ch5
	uint32_t rsvd1:1;				// 30:30  reserved

	uint32_t MIF:1;					// 31:31  Master Interrupt Flag
};

union SDIFLGCLR_REG {
	uint32_t all;
	struct SDIFLGCLR_BITS bit;
};

struct SDCTL_BITS {					// bits   description
	uint16_t HZ1:1;					// 0:0	  High-level Threshold crossing (Z) flag Ch1
	uint16_t HZ2:1;					// 1:1	  High-level Threshold crossing (Z) flag Ch2
	uint16_t HZ3:1;					// 2:2	  High-level Threshold crossing (Z) flag Ch3
	uint16_t HZ4:1;					// 3:3	  High-level Threshold crossing (Z) flag Ch4

	uint16_t rsvd1:9;				// 12:4   reserved

	uint16_t HZ5:1;					// 4:4	  High-level Threshold crossing (Z) flag Ch5
	uint16_t rsvd1:8;				// 12:5   reserved

	uint16_t MIE:1;					// 13:13  Master SDy_ERR Interrupt enable
	uint16_t rsvd2:2;				// 15:14  reserved
};

union SDCTL_REG {
	uint16_t all;
	struct SDCTL_BITS bit;
};

struct SDMFILEN_BITS {				// bits   description
	uint16_t rsvd1:11;				// 10:0   reserved
	uint16_t MFE:1;					// 11:11  Master Filter Enable
	uint16_t rsvd2:4;				// 15:12  reserved
};

union SDMFILEN_REG {
	uint16_t all;
	struct SDMFILEN_BITS bit;
};

struct SDSTATUS_BITS {				// bits   description
	uint16_t HZ1:1;					// 0:0    High-level Threshold crossing (Z) flag Ch1
	uint16_t HZ2:1;					// 1:1	  High-level Threshold crossing (Z) flag Ch2
	uint16_t HZ3:1;					// 2:2	  High-level Threshold crossing (Z) flag Ch3
	uint16_t HZ4:1;					// 3:3	  High-level Threshold crossing (Z) flag Ch4

	uint16_t rsvd1:12;				// 15:4   reserved

	uint16_t HZ5:1;					// 4:4	  High-level Threshold crossing (Z) flag Ch5
	uint16_t rsvd1:11;				// 15:5   reserved	

};

union SDSTATUS_REG {
	uint16_t all;
	struct SDSTATUS_BITS bit;
};

struct SDCTLPARM1_BITS {			// bits   description
	uint16_t MOD:2;					// 1:0	  Modulator clocking modes
	uint16_t rsvd1:1;				// 2:2    reserved
	uint16_t SDCLKSEL:1;			// 3:3	  SD1 Clock source select
	uint16_t SDCLKSYNC:1;			// 4:4    Enable Synchronizer on SD clock
	uint16_t rsvd2:1;				// 5:5    reserved
	uint16_t SDDATASYNC:1;			// 6:6	  Enable Synchronizer on SD data
	uint16_t rsvd3:9;				// 15:7   reserved
};

union SDCTLPARM1_REG {
	uint16_t all;
	struct SDCTLPARM1_BITS bit;
};

struct SDDFPARM1_BITS {				// bits   description
	uint16_t DOSR:8;				// 7:0	  Data Filter Oversample Ratio= DOSR+1
	uint16_t FEN:1;					// 8:8	  Filter Enable
	uint16_t AE:1;					// 9:9	  Ack Enable
	uint16_t SST:2;					// 11:10  Data filter Structure (SincFast/1/2/3)
	uint16_t SDSYNCEN:1;			// 12:12  Data Filter Reset Enable
	uint16_t rsvd1:3;				// 15:13  reserved
};

union SDDFPARM1_REG {
	uint16_t all;
	struct SDDFPARM1_BITS bit;
};

struct SDDPARM1_BITS {				// bits   description
	uint16_t rsvd1:10;				// 9:0    reserved
	uint16_t DR:1;					// 10:10  Data Representation (0/1 = 16/32b 2's complement)
	uint16_t SH:5;					// 15:11  Shift Control (# bits to shift in 16b mode)
};

union SDDPARM1_REG {
	uint16_t all;
	struct SDDPARM1_BITS bit;
};

struct SDFLT1CMPH1_BITS {			// bits   description
	uint16_t HLT:15;				// 14:0   High-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT1CMPH1_REG {
	uint16_t all;
	struct SDFLT1CMPH1_BITS bit;
};

struct SDFLT1CMPL1_BITS {			// bits   description
	uint16_t LLT:15;				// 14:0	  Low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT1CMPL1_REG {
	uint16_t all;
	struct SDFLT1CMPL1_BITS bit;
};

struct SDCPARM1_BITS {				// bits   description
	uint16_t COSR:5;				// 4:0	  Comparator Oversample Ratio. Actual rate COSR+1
	uint16_t EN_CEVT1:1;			// 5:5	  CEVT1 Interrupt enable
	uint16_t EN_CEVT2:1;			// 6:6	  CEVT2 Interrupt enable
	uint16_t CS1_CS0:2;				// 8:7    Comparator Filter Structure (SincFast/1/2/3)
	uint16_t MFIE:1;				// 9:9	  Modulator Failure Interrupt enable
	uint16_t HZEN:1;				// 10:10  High level (Z) Threshold crossing output enable
	uint16_t CEVT1SEL:2;			// 12:11  Comparator Event1 select
	uint16_t CEN:1;					// 13:13  Comparator Enable
	uint16_t CEVT2SEL:2;			// 15:14  Comparator Event2 select
};

union SDCPARM1_REG {
	uint16_t all;
	struct SDCPARM1_BITS bit;
};

struct SDDATA1_BITS {				// bits   description
	uint32_t DATA16:16;				// 15:0	  Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA1_REG {
	uint32_t all;
	struct SDDATA1_BITS bit;
};

struct SDDATFIFO1_BITS {			// bits   description
	uint32_t DATA16:16;				// 15:0	  Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO1_REG {
	uint32_t all;
	struct SDDATFIFO1_BITS bit;
};

struct SDCDATA1_BITS {				// bits   description
	uint16_t DATA16:16;				// 15:0
};

union SDCDATA1_REG {
	uint16_t all;
	struct SDCDATA1_BITS bit;
};

struct SDFLT1CMPH2_BITS {			// bits   description
	uint16_t HLT2:15;				// 14:0   Second High level threshold
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT1CMPH2_REG {
	uint16_t all;
	struct SDFLT1CMPH2_BITS bit;
};

struct SDFLT1CMPHZ_BITS {			// bits   description
	uint16_t HLTZ:15;				// 14:0	  High-level threshold (Z) for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT1CMPHZ_REG {
	uint16_t all;
	struct SDFLT1CMPHZ_BITS bit;
};

struct SDFIFOCTL1_BITS {			// bits   description
	uint16_t SDFFIL:5;				// 4:0	  SDFIFO Interrupt Level
	uint16_t rsvd1:1;				// 5:5    reserved
	uint16_t SDFFST:5;				// 10:6	  SDFIFO Status
	uint16_t rsvd2:1;				// 11:11  reserved
	uint16_t FFIEN:1;				// 12:12  SDFIFO data ready Interrupt Enable
	uint16_t FFEN:1;				// 13:13  SDFIFO Enable
	uint16_t DRINTSEL:1;			// 14:14  Data-Ready Interrupt Source Select
	uint16_t OVFIEN:1;				// 15:15  SDFIFO Overflow interrupt enable
};

union SDFIFOCTL1_REG {
	uint16_t all;
	struct SDFIFOCTL1_BITS bit;
};

struct SDSYNC1_BITS {				// bits   description
	uint16_t SYNCSEL:6;				// 5:0	  SDSYNC Source Select
	uint16_t WTSYNCEN:1;			// 6:6	  Wait-for-Sync Enable
	uint16_t WTSYNFLG:1;			// 7:7	  Wait-for-Sync Flag
	uint16_t WTSYNCLR:1;			// 8:8	  Wait-for-Sync Flag Clear
	uint16_t FFSYNCCLREN:1;			// 9:9	  FIFO Clear-on-SDSYNC Enable
	uint16_t WTSCLREN:1;			// 10:10  WTSYNFLG Clear-on-FIFOINT Enable
	uint16_t rsvd1:5;				// 15:11  reserved
};

union SDSYNC1_REG {
	uint16_t all;
	struct SDSYNC1_BITS bit;
};

struct SDFLT1CMPL2_BITS {			// bits   description
	uint16_t LLT2:15;				// 14:0	  Second low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT1CMPL2_REG {
	uint16_t all;
	struct SDFLT1CMPL2_BITS bit;
};

struct SDCTLPARM2_BITS {			// bits   description
	uint16_t MOD:2;					// 1:0	  Modulator clocking modes
	uint16_t rsvd1:1;				// 2:2    reserved
	uint16_t SDCLKSEL:1;			// 3:3	  SD2 Clock source select
	uint16_t SDCLKSYNC:1;			// 4:4	  Enable Synchronizer on SD clock
	uint16_t rsvd2:1;				// 5:5    reserved
	uint16_t SDDATASYNC:1;			// 6:6	  Enable Synchronizer on SD data
	uint16_t rsvd3:9;				// 15:7   reserved
};

union SDCTLPARM2_REG {
	uint16_t all;
	struct SDCTLPARM2_BITS bit;
};

struct SDDFPARM2_BITS {				// bits   description
	uint16_t DOSR:8;				// 7:0	  Data Filter Oversample Ratio= DOSR+1
	uint16_t FEN:1;					// 8:8	  Filter Enable
	uint16_t AE:1;					// 9:9	  Ack Enable
	uint16_t SST:2;					// 11:10  Data filter Structure (SincFast/1/2/3)
	uint16_t SDSYNCEN:1;			// 12:12  Data Filter Reset Enable
	uint16_t rsvd1:3;				// 15:13  reserved
};

union SDDFPARM2_REG {
	uint16_t all;
	struct SDDFPARM2_BITS bit;
};

struct SDDPARM2_BITS {				// bits   description
	uint16_t rsvd1:10;				// 9:0    reserved
	uint16_t DR:1;					// 10:10  Data Representation (0/1 = 16/32b 2's complement)
	uint16_t SH:5;					// 15:11  Shift Control (# bits to shift in 16b mode)
};

union SDDPARM2_REG {
	uint16_t all;
	struct SDDPARM2_BITS bit;
};

struct SDFLT2CMPH1_BITS {			// bits   description
	uint16_t HLT:15;				// 14:0   High-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT2CMPH1_REG {
	uint16_t all;
	struct SDFLT2CMPH1_BITS bit;
};

struct SDFLT2CMPL1_BITS {			// bits   description
	uint16_t LLT:15;				// 14:0	  Low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT2CMPL1_REG {
	uint16_t all;
	struct SDFLT2CMPL1_BITS bit;
};

struct SDCPARM2_BITS {				// bits   description
	uint16_t COSR:5;				// 4:0	  Comparator Oversample Ratio. Actual rate COSR+1
	uint16_t EN_CEVT1:1;			// 5:5	  CEVT1 Interrupt enable
	uint16_t EN_CEVT2:1;			// 6:6	  CEVT2 Interrupt enable
	uint16_t CS1_CS0:2;				// 8:7	  Comparator Filter Structure (SincFast/1/2/3)
	uint16_t MFIE:1;				// 9:9	  Modulator Failure Interrupt enable
	uint16_t HZEN:1;				// 10:10  High level (Z) Threshold crossing output enable
	uint16_t CEVT1SEL:2;			// 12:11  Comparator Event1 select
	uint16_t CEN:1;					// 13:13  Comparator Enable
	uint16_t CEVT2SEL:2;			// 15:14  Comparator Event2 select
};

union SDCPARM2_REG {
	uint16_t all;
	struct SDCPARM2_BITS bit;
};

struct SDDATA2_BITS {				// bits   description
	uint32_t DATA16:16;				// 15:0   Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA2_REG {
	uint32_t all;
	struct SDDATA2_BITS bit;
};

struct SDDATFIFO2_BITS {			// bits   description
	uint32_t DATA16:16;				// 15:0   Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO2_REG {
	uint32_t all;
	struct SDDATFIFO2_BITS bit;
};

struct SDCDATA2_BITS {				// bits   description
	uint16_t DATA16:16;				// 15:0
};

union SDCDATA2_REG {
	uint16_t all;
	struct SDCDATA2_BITS bit;
};

struct SDFLT2CMPH2_BITS {			// bits   description
	uint16_t HLT2:15;				// 14:0	  Second High level threshold
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT2CMPH2_REG {
	uint16_t all;
	struct SDFLT2CMPH2_BITS bit;
};

struct SDFLT2CMPHZ_BITS {			// bits   description
	uint16_t HLTZ:15;				// 14:0	  High-level threshold (Z) for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT2CMPHZ_REG {
	uint16_t all;
	struct SDFLT2CMPHZ_BITS bit;
};

struct SDFIFOCTL2_BITS {			// bits   description
	uint16_t SDFFIL:5;				// 4:0	  SDFIFO Interrupt Level
	uint16_t rsvd1:1;				// 5:5    reserved
	uint16_t SDFFST:5;				// 10:6	  SDFIFO Status
	uint16_t rsvd2:1;				// 11:11  reserved
	uint16_t FFIEN:1;				// 12:12  SDFIFO data ready Interrupt Enable
	uint16_t FFEN:1;				// 13:13  SDFIFO Enable
	uint16_t DRINTSEL:1;			// 14:14  Data-Ready Interrupt Source Select
	uint16_t OVFIEN:1;				// 15:15  SDFIFO Overflow interrupt enable
};

union SDFIFOCTL2_REG {
	uint16_t all;
	struct SDFIFOCTL2_BITS bit;
};

struct SDSYNC2_BITS {				// bits   description
	uint16_t SYNCSEL:6;				// 5:0	  SDSYNC Source Select
	uint16_t WTSYNCEN:1;			// 6:6	  Wait-for-Sync Enable
	uint16_t WTSYNFLG:1;			// 7:7	  Wait-for-Sync Flag
	uint16_t WTSYNCLR:1;			// 8:8	  Wait-for-Sync Flag Clear
	uint16_t FFSYNCCLREN:1;			// 9:9	  FIFO Clear-on-SDSYNC Enable
	uint16_t WTSCLREN:1;			// 10:10  WTSYNFLG Clear-on-FIFOINT Enable
	uint16_t rsvd1:5;				// 15:11  reserved
};

union SDSYNC2_REG {
	uint16_t all;
	struct SDSYNC2_BITS bit;
};

struct SDFLT2CMPL2_BITS {			// bits   description
	uint16_t LLT2:15;				// 14:0	  Second low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT2CMPL2_REG {
	uint16_t all;
	struct SDFLT2CMPL2_BITS bit;
};

struct SDCTLPARM3_BITS {			// bits   description
	uint16_t MOD:2;					// 1:0	  Modulator clocking modes
	uint16_t rsvd1:1;				// 2:2    reserved
	uint16_t SDCLKSEL:1;			// 3:3    SD3 Clock source select
	uint16_t SDCLKSYNC:1;			// 4:4	  Enable Synchronizer on SD clock
	uint16_t rsvd2:1;				// 5:5    reserved
	uint16_t SDDATASYNC:1;			// 6:6	  Enable Synchronizer on SD data
	uint16_t rsvd3:9;				// 15:7   reserved
};

union SDCTLPARM3_REG {
	uint16_t all;
	struct SDCTLPARM3_BITS bit;
};

struct SDDFPARM3_BITS {				// bits   description
	uint16_t DOSR:8;				// 7:0	  Data Filter Oversample Ratio= DOSR+1
	uint16_t FEN:1;					// 8:8	  Filter Enable
	uint16_t AE:1;					// 9:9	  Ack Enable
	uint16_t SST:2;					// 11:10  Data filter Structure (SincFast/1/2/3)
	uint16_t SDSYNCEN:1;			// 12:12  Data Filter Reset Enable
	uint16_t rsvd1:3;				// 15:13  reserved
};

union SDDFPARM3_REG {
	uint16_t all;
	struct SDDFPARM3_BITS bit;
};

struct SDDPARM3_BITS {				// bits   description
	uint16_t rsvd1:10;				// 9:0    reserved
	uint16_t DR:1;					// 10:10  Data Representation (0/1 = 16/32b 2's complement)
	uint16_t SH:5;					// 15:11  Shift Control (# bits to shift in 16b mode)
};

union SDDPARM3_REG {
	uint16_t all;
	struct SDDPARM3_BITS bit;
};

struct SDFLT3CMPH1_BITS {			// bits   description
	uint16_t HLT:15;				// 14:0	  High-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT3CMPH1_REG {
	uint16_t all;
	struct SDFLT3CMPH1_BITS bit;
};

struct SDFLT3CMPL1_BITS {			// bits   description
	uint16_t LLT:15;				// 14:0	  Low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT3CMPL1_REG {
	uint16_t all;
	struct SDFLT3CMPL1_BITS bit;
};

struct SDCPARM3_BITS {				// bits   description
	uint16_t COSR:5;				// 4:0	  Comparator Oversample Ratio. Actual rate COSR+1
	uint16_t EN_CEVT1:1;			// 5:5	  CEVT1 Interrupt enable
	uint16_t EN_CEVT2:1;			// 6:6	  CEVT2 Interrupt enable
	uint16_t CS1_CS0:2;				// 8:7	  Comparator Filter Structure (SincFast/1/2/3)
	uint16_t MFIE:1;				// 9:9	  Modulator Failure Interrupt enable
	uint16_t HZEN:1;				// 10:10  High level (Z) Threshold crossing output enable
	uint16_t CEVT1SEL:2;			// 12:11  Comparator Event1 select
	uint16_t CEN:1;					// 13:13  Comparator Enable
	uint16_t CEVT2SEL:2;			// 15:14  Comparator Event2 select
};

union SDCPARM3_REG {
	uint16_t all;
	struct SDCPARM3_BITS bit;
};

struct SDDATA3_BITS {				// bits   description
	uint32_t DATA16:16;				// 15:0	  Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA3_REG {
	uint32_t all;
	struct SDDATA3_BITS bit;
};

struct SDDATFIFO3_BITS {			// bits   description
	uint32_t DATA16:16;				// 15:0   Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO3_REG {
	uint32_t all;
	struct SDDATFIFO3_BITS bit;
};

struct SDCDATA3_BITS {				// bits   description
	uint16_t DATA16:16;				// 15:0
};

union SDCDATA3_REG {
	uint16_t all;
	struct SDCDATA3_BITS bit;
};

struct SDFLT3CMPH2_BITS {			// bits   description
	uint16_t HLT2:15;				// 14:0   Second High level threshold
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT3CMPH2_REG {
	uint16_t all;
	struct SDFLT3CMPH2_BITS bit;
};

struct SDFLT3CMPHZ_BITS {			// bits   description
	uint16_t HLTZ:15;				// 14:0	  High-level threshold (Z) for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT3CMPHZ_REG {
	uint16_t all;
	struct SDFLT3CMPHZ_BITS bit;
};

struct SDFIFOCTL3_BITS {			// bits   description
	uint16_t SDFFIL:5;				// 4:0	  SDFIFO Interrupt Level
	uint16_t rsvd1:1;				// 5:5    reserved
	uint16_t SDFFST:5;				// 10:6	  SDFIFO Status
	uint16_t rsvd2:1;				// 11:11  reserved
	uint16_t FFIEN:1;				// 12:12  SDFIFO data ready Interrupt Enable
	uint16_t FFEN:1;				// 13:13  SDFIFO Enable
	uint16_t DRINTSEL:1;			// 14:14  Data-Ready Interrupt Source Select
	uint16_t OVFIEN:1;				// 15:15  SDFIFO Overflow interrupt enable
};

union SDFIFOCTL3_REG {
	uint16_t all;
	struct SDFIFOCTL3_BITS bit;
};

struct SDSYNC3_BITS {				// bits   description
	uint16_t SYNCSEL:6;				// 5:0	  SDSYNC Source Select
	uint16_t WTSYNCEN:1;			// 6:6	  Wait-for-Sync Enable
	uint16_t WTSYNFLG:1;			// 7:7	  Wait-for-Sync Flag
	uint16_t WTSYNCLR:1;			// 8:8	  Wait-for-Sync Flag Clear
	uint16_t FFSYNCCLREN:1;			// 9:9	  FIFO Clear-on-SDSYNC Enable
	uint16_t WTSCLREN:1;			// 10:10  WTSYNFLG Clear-on-FIFOINT Enable
	uint16_t rsvd1:5;				// 15:11  reserved
};

union SDSYNC3_REG {
	uint16_t all;
	struct SDSYNC3_BITS bit;
};

struct SDFLT3CMPL2_BITS {			// bits   description
	uint16_t LLT2:15;				// 14:0   Second low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT3CMPL2_REG {
	uint16_t all;
	struct SDFLT2CMPL2_BITS bit;
};

struct SDCTLPARM4_BITS {			// bits   description
	uint16_t MOD:2;					// 1:0	  Modulator clocking modes
	uint16_t rsvd1:1;				// 2:2    reserved
	uint16_t SDCLKSEL:1;			// 3:3	  SD4 Clock source select
	uint16_t SDCLKSYNC:1;			// 4:4	  Enable Synchronizer on SD clock
	uint16_t rsvd2:1;				// 5:5    reserved
	uint16_t SDDATASYNC:1;			// 6:6	  Enable Synchronizer on SD data
	uint16_t rsvd3:9;				// 15:7   reserved
};

union SDCTLPARM4_REG {
	uint16_t all;
	struct SDCTLPARM4_BITS bit;
};

struct SDDFPARM4_BITS {				// bits   description
	uint16_t DOSR:8;				// 7:0	  Data Filter Oversample Ratio= DOSR+1
	uint16_t FEN:1;					// 8:8	  Filter Enable
	uint16_t AE:1;					// 9:9	  Ack Enable
	uint16_t SST:2;					// 11:10  Data filter Structure (SincFast/1/2/3)
	uint16_t SDSYNCEN:1;			// 12:12  Data Filter Reset Enable
	uint16_t rsvd1:3;				// 15:13  reserved
};

union SDDFPARM4_REG {
	uint16_t all;
	struct SDDFPARM4_BITS bit;
};

struct SDDPARM4_BITS {				// bits   description
	uint16_t rsvd1:10;				// 9:0    reserved
	uint16_t DR:1;					// 10:10  Data Representation (0/1 = 16/32b 2's complement)
	uint16_t SH:5;					// 15:11  Shift Control (# bits to shift in 16b mode)
};

union SDDPARM4_REG {
	uint16_t all;
	struct SDDPARM4_BITS bit;
};

struct SDFLT4CMPH1_BITS {			// bits   description
	uint16_t HLT:15;				// 14:0	  High-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT4CMPH1_REG {
	uint16_t all;
	struct SDFLT4CMPH1_BITS bit;
};

struct SDFLT4CMPL1_BITS {			// bits   description
	uint16_t LLT:15;				// 14:0	  Low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT4CMPL1_REG {
	uint16_t all;
	struct SDFLT4CMPL1_BITS bit;
};

struct SDCPARM4_BITS {				// bits   description
	uint16_t COSR:5;				// 4:0	  Comparator Oversample Ratio. Actual rate COSR+1
	uint16_t EN_CEVT1:1;			// 5:5	  CEVT1 Interrupt enable
	uint16_t EN_CEVT2:1;			// 6:6	  CEVT2 Interrupt enable
	uint16_t CS1_CS0:2;				// 8:7	  Comparator Filter Structure (SincFast/1/2/3)
	uint16_t MFIE:1;				// 9:9	  Modulator Failure Interrupt enable
	uint16_t HZEN:1;				// 10:10  High level (Z) Threshold crossing output enable
	uint16_t CEVT1SEL:2;			// 12:11  Comparator Event1 select
	uint16_t CEN:1;					// 13:13  Comparator Enable
	uint16_t CEVT2SEL:2;			// 15:14  Comparator Event2 select
};

union SDCPARM4_REG {
	uint16_t all;
	struct SDCPARM4_BITS bit;
};

struct SDDATA4_BITS {				// bits   description
	uint32_t DATA16:16;				// 15:0   Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA4_REG {
	uint32_t all;
	struct SDDATA4_BITS bit;
};

struct SDDATFIFO4_BITS {			// bits   description
	uint32_t DATA16:16;				// 15:0	  Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO4_REG {
	uint32_t all;
	struct SDDATFIFO4_BITS bit;
};

struct SDCDATA4_BITS {				// bits   description
	uint16_t DATA16:16;				// 15:0
};

union SDCDATA4_REG {
	uint16_t all;
	struct SDCDATA4_BITS bit;
};

struct SDFLT4CMPH2_BITS {			// bits   description
	uint16_t HLT2:15;				// 14:0	  Second High level threshold
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT4CMPH2_REG {
	uint16_t all;
	struct SDFLT4CMPH2_BITS bit;
};

struct SDFLT4CMPHZ_BITS {			// bits   description
	uint16_t HLTZ:15;				// 14:0	  High-level threshold (Z) for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT4CMPHZ_REG {
	uint16_t all;
	struct SDFLT4CMPHZ_BITS bit;
};

struct SDFIFOCTL4_BITS {			// bits   description
	uint16_t SDFFIL:5;				// 4:0	  SDFIFO Interrupt Level
	uint16_t rsvd1:1;				// 5:5    reserved
	uint16_t SDFFST:5;				// 10:6	  SDFIFO Status
	uint16_t rsvd2:1;				// 11:11  reserved
	uint16_t FFIEN:1;				// 12:12  SDFIFO data ready Interrupt Enable
	uint16_t FFEN:1;				// 13:13  SDFIFO Enable
	uint16_t DRINTSEL:1;			// 14:14  Data-Ready Interrupt Source Select
	uint16_t OVFIEN:1;				// 15:15  SDFIFO Overflow interrupt enable
};

union SDFIFOCTL4_REG {
	uint16_t all;
	struct SDFIFOCTL4_BITS bit;
};

struct SDSYNC4_BITS {				// bits   description
	uint16_t SYNCSEL:6;				// 5:0	  SDSYNC Source Select
	uint16_t WTSYNCEN:1;			// 6:6	  Wait-for-Sync Enable
	uint16_t WTSYNFLG:1;			// 7:7	  Wait-for-Sync Flag
	uint16_t WTSYNCLR:1;			// 8:8	  Wait-for-Sync Flag Clear
	uint16_t FFSYNCCLREN:1;			// 9:9    FIFO Clear-on-SDSYNC Enable
	uint16_t WTSCLREN:1;			// 10:10  WTSYNFLG Clear-on-FIFOINT Enable
	uint16_t rsvd1:5;				// 15:11  reserved
};

union SDSYNC4_REG {
	uint16_t all;
	struct SDSYNC4_BITS bit;
};

struct SDFLT4CMPL2_BITS {			// bits   description
	uint16_t LLT2:15;				// 14:0	  Second low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT4CMPL2_REG {
	uint16_t all;
	struct SDFLT4CMPL2_BITS bit;
};

struct SDCOMP1CTL_BITS {			// bits   description
	uint16_t rsvd1:2;				// 1:0    reserved
	uint16_t CEVT1DIGFILTSEL:2;		// 3:2    High Comparator Trip Select
	uint16_t rsvd2:6;				// 9:4    reserved
	uint16_t CEVT2DIGFILTSEL:2;		// 11:10  Low Comparator Trip Select
	uint16_t rsvd3:4;				// 15:12  reserved
};

union SDCOMP1CTL_REG {
	uint16_t all;
	struct SDCOMP1CTL_BITS bit;
};

struct SDCOMP1EVT2FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15     Filter Initialization Bit
};

union SDCOMP1EVT2FLTCTL_REG {
	uint16_t all;
	struct SDCOMP1EVT2FLTCTL_BITS bit;
};

struct SDCOMP1EVT2FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP1EVT2FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP1EVT2FLTCLKCTL_BITS bit;
};

struct SDCOMP1EVT1FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15	  Filter Initialization Bit
};

union SDCOMP1EVT1FLTCTL_REG {
	uint16_t all;
	struct SDCOMP1EVT1FLTCTL_BITS bit;
};

struct SDCOMP1EVT1FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP1EVT1FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP1EVT1FLTCLKCTL_BITS bit;
};

struct SDCOMP2CTL_BITS {			// bits   description
	uint16_t rsvd1:2;				// 1:0    reserved
	uint16_t CEVT1DIGFILTSEL:2;		// 3:2    High Comparator Trip Select
	uint16_t rsvd2:6;				// 9:4    reserved
	uint16_t CEVT2DIGFILTSEL:2;		// 11:10  Low Comparator Trip Select
	uint16_t rsvd3:4;				// 15:12  reserved
};

union SDCOMP2CTL_REG {
	uint16_t all;
	struct SDCOMP2CTL_BITS bit;
};

struct SDCOMP2EVT2FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15	  Filter Initialization Bit
};

union SDCOMP2EVT2FLTCTL_REG {
	uint16_t all;
	struct SDCOMP2EVT2FLTCTL_BITS bit;
};

struct SDCOMP2EVT2FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP2EVT2FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP2EVT2FLTCLKCTL_BITS bit;
};

struct SDCOMP2EVT1FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15	  Filter Initialization Bit
};

union SDCOMP2EVT1FLTCTL_REG {
	uint16_t all;
	struct SDCOMP2EVT1FLTCTL_BITS bit;
};

struct SDCOMP2EVT1FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP2EVT1FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP2EVT1FLTCLKCTL_BITS bit;
};

struct SDCOMP3CTL_BITS {			// bits   description
	uint16_t rsvd1:2;				// 1:0    reserved
	uint16_t CEVT1DIGFILTSEL:2;		// 3:2    High Comparator Trip Select
	uint16_t rsvd2:6;				// 9:4    reserved
	uint16_t CEVT2DIGFILTSEL:2;		// 11:10  Low Comparator Trip Select
	uint16_t rsvd3:4;				// 15:12  reserved
};

union SDCOMP3CTL_REG {
	uint16_t all;
	struct SDCOMP3CTL_BITS bit;
};

struct SDCOMP3EVT2FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15	  Filter Initialization Bit
};

union SDCOMP3EVT2FLTCTL_REG {
	uint16_t all;
	struct SDCOMP3EVT2FLTCTL_BITS bit;
};

struct SDCOMP3EVT2FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP3EVT2FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP3EVT2FLTCLKCTL_BITS bit;
};

struct SDCOMP3EVT1FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15	  Filter Initialization Bit
};

union SDCOMP3EVT1FLTCTL_REG {
	uint16_t all;
	struct SDCOMP3EVT1FLTCTL_BITS bit;
};

struct SDCOMP3EVT1FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP3EVT1FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP3EVT1FLTCLKCTL_BITS bit;
};

struct SDCOMP4CTL_BITS {			// bits   description
	uint16_t rsvd1:2;				// 1:0    reserved
	uint16_t CEVT1DIGFILTSEL:2;		// 3:2    High Comparator Trip Select
	uint16_t rsvd2:6;				// 9:4    reserved
	uint16_t CEVT2DIGFILTSEL:2;		// 11:10  Low Comparator Trip Select
	uint16_t rsvd3:4;				// 15:12  reserved
};

union SDCOMP4CTL_REG {
	uint16_t all;
	struct SDCOMP4CTL_BITS bit;
};

struct SDCOMP4EVT2FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15     Filter Initialization Bit
};

union SDCOMP4EVT2FLTCTL_REG {
	uint16_t all;
	struct SDCOMP4EVT2FLTCTL_BITS bit;
};

struct SDCOMP4EVT2FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP4EVT2FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP4EVT2FLTCLKCTL_BITS bit;
};

struct SDCOMP4EVT1FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15	  Filter Initialization Bit
};

union SDCOMP4EVT1FLTCTL_REG {
	uint16_t all;
	struct SDCOMP4EVT1FLTCTL_BITS bit;
};

struct SDCOMP4EVT1FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP4EVT1FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP4EVT1FLTCLKCTL_BITS bit;
};

struct SDREGSLOCK_BITS {			// bits   description
	uint32_t REGSLOCK;				// 31:0   lock registers
};

union SDREGSLOCK_REG {
	uint32_t all;
	struct SDREGSLOCK_BITS bit;
};

struct SD_CLKERR_PERIOD_BITS {		// bits   description
	uint32_t CLKERR_PERIOD:10;		// 9:0
	uint32_t rsvd1:22;				// 31:10
};

union SD_CLKERR_PERIOD_REG {
	uint32_t all;
	struct SD_CLKERR_PERIOD_BITS bit;
};


struct SD_TYPE_BITS {				// bits   description
	uint32_t CLKERR_PERIOD:2;		// 1:0
	uint32_t rsvd1:30;				// 31:2
};

union SD_TYPE_REG {
	uint32_t all;
	struct SD_TYPE_BITS bit;
};

struct SD_MANCHESTER_ERR_MODE_BITS {// bits   description
	uint32_t MANCHESTER_ERR_MODE:2;	// 1:0
	uint32_t rsvd1:30;				// 31:2
};

union SD_MANCHESTER_ERR_MODE_REG {
	uint32_t all;
	struct SD_MANCHESTER_ERR_MODE_BITS bit;
};


struct SD_MANCHESTER_ERR_MODE_BITS {// bits   description
	uint32_t MANCHESTER_ERR_MODE:2;	// 1:0
	uint32_t rsvd1:30;				// 31:2
};

union SD_MANCHESTER_ERR_MODE_REG {
	uint32_t all;
	struct SD_MANCHESTER_ERR_MODE_BITS bit;
};

struct SDMODEEN_BITS {				// bits   description
	uint32_t SINCFASTEN:1;			// 0:0
	uint32_t rsvd1:3;				// 3:1
	uint32_t OSREN:1;				// 4:4
	uint32_t rsvd2:3;				// 7:5
	uint32_t INEN:1;				// 8:8
	uint32_t rsvd3:3;				// 11:9
	uint32_t OSROVFEN:1;			// 12:12
	uint32_t rsvd4:19;				// 31:13
};

union SDMODEEN_REG {
	uint32_t all;
	struct SDMODEEN_BITS bit;
};

struct SDCOMP1EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT1COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT1COMP:1;	// 1:1
	uint16_t rsvd1:14;				// 15:2

};

union SDCOMP1EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP1EVTFLTEN_BITS bit;
};

struct SDCOMP2EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT2COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT2COMP:1;	// 1:1
	uint16_t rsvd1:14;				// 15:2

};

union SDCOMP2EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP2EVTFLTEN_BITS bit;
};

struct SDCOMP3EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT3COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT3COMP:1;	// 1:1
	uint16_t rsvd1:14;				// 15:2

};

union SDCOMP3EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP3EVTFLTEN_BITS bit;
};

struct SDCOMP4EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT4COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT4COMP:1;	// 1:1
	uint16_t rsvd1:14;				// 15:2

};

union SDCOMP4EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP4EVTFLTEN_BITS bit;
};

struct SDINMUX_BITS {				// bits   description
	uint32_t INMUX:1;				// 0:0
	uint32_t rsvd1:31;				// 31:1

};

union SDINMUX_REG {
	uint32_t all;
	struct SDINMUX_BITS bit;
};

struct SD_MANCHESTER_ERR_MODE_BITS {// bits   description
	uint32_t MANCHESTER_ERR_MODE:2;	// 1:0
	uint32_t rsvd1:30;				// 31:2
};

union SD_MANCHESTER_ERR_MODE_REG {
	uint32_t all;
	struct SD_MANCHESTER_ERR_MODE_BITS bit;
};

struct SDMODEEN_BITS {				// bits   description
	uint32_t SINCFASTEN:1;			// 0:0
	uint32_t rsvd1:3;				// 3:1
	uint32_t OSREN:1;				// 4:4
	uint32_t rsvd2:3;				// 7:5
	uint32_t INEN:1;				// 8:8
	uint32_t rsvd3:3;				// 11:9
	uint32_t OSROVFEN:1;			// 12:12
	uint32_t rsvd4:19;				// 31:13
};

union SDMODEEN_REG {
	uint32_t all;
	struct SDMODEEN_BITS bit;
};

struct SDCOMP1EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT1COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT1COMP:1;	// 1:1
	uint16_t rsvd1:14;				// 15:2

};

union SDCOMP1EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP1EVTFLTEN_BITS bit;
};

struct SDCOMP2EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT2COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT2COMP:1;	// 1:1
	uint16_t rsvd1:14;				// 15:2

};

union SDCOMP2EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP2EVTFLTEN_BITS bit;
};

struct SDCOMP3EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT3COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT3COMP:1;	// 1:1
	uint16_t rsvd1:14;				// 15:2

};

union SDCOMP3EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP3EVTFLTEN_BITS bit;
};

struct SDCOMP4EVTFLTEN_BITS {		// bits   description
	uint16_t DIGFILTEN1EVT4COMP:1;	// 0:0
	uint16_t DIGFILTEN2EVT4COMP:1;	// 1:1
	uint16_t DIGFILTEN1EVT5COMP:1;	// 2:2
	uint16_t DIGFILTEN2EVT5COMP:1;	// 3:3
	uint16_t rsvd1:12;				// 15:4

};

union SDCOMP4EVTFLTEN_REG {
	uint16_t all;
	struct SDCOMP4EVTFLTEN_BITS bit;
};

struct SDINMUX_BITS {				// bits   description
	uint32_t INMUX:1;				// 0:0
	uint32_t rsvd1:3;				// 1:3
	uint32_t SD1CSEL:1;				// 4:4
	uint32_t SD2CSEL:1;				// 5:5
	uint32_t SD3CSEL:1;				// 6:6
	uint32_t SD4CSEL:1;				// 7:7
	uint32_t SD1DSEL:1;				// 8:8
	uint32_t SD2DSEL:1;				// 9:9
	uint32_t SD3DSEL:1;				// 10:10
	uint32_t SD4DSEL:1;				// 11:11
	uint32_t SD5CSEL:2;				// 12:13
	uint32_t SD5DSEL:2;				// 14:15
	uint32_t rsvd2:16;				// 31:16
};

union SDINMUX_REG {
	uint32_t all;
	struct SDINMUX_BITS bit;
};

struct SDCTLPARM5_BITS {			// bits   description
	uint16_t MOD:2;					// 1:0	  Modulator clocking modes
	uint16_t rsvd1:1;				// 2:2    reserved
	uint16_t SDCLKSEL:1;			// 3:3	  SD1 Clock source select
	uint16_t SDCLKSYNC:1;			// 4:4    Enable Synchronizer on SD clock
	uint16_t rsvd2:1;				// 5:5    reserved
	uint16_t SDDATASYNC:1;			// 6:6	  Enable Synchronizer on SD data
	uint16_t rsvd3:9;				// 15:7   reserved
};

union SDCTLPARM5_REG {
	uint16_t all;
	struct SDCTLPARM5_BITS bit;
};

struct SDDFPARM5_BITS {				// bits   description
	uint16_t DOSR:8;				// 7:0	  Data Filter Oversample Ratio= DOSR+1
	uint16_t FEN:1;					// 8:8	  Filter Enable
	uint16_t AE:1;					// 9:9	  Ack Enable
	uint16_t SST:2;					// 11:10  Data filter Structure (SincFast/1/2/3)
	uint16_t SDSYNCEN:1;			// 12:12  Data Filter Reset Enable
	uint16_t rsvd1:3;				// 15:13  reserved
};

union SDDFPARM5_REG {
	uint16_t all;
	struct SDDFPARM5_BITS bit;
};

struct SDDPARM5_BITS {				// bits   description
	uint16_t rsvd1:10;				// 9:0    reserved
	uint16_t DR:1;					// 10:10  Data Representation (0/1 = 16/32b 2's complement)
	uint16_t SH:5;					// 15:11  Shift Control (# bits to shift in 16b mode)
};

union SDDPARM5_REG {
	uint16_t all;
	struct SDDPARM5_BITS bit;
};

struct SDFLT5CMPH1_BITS {			// bits   description
	uint16_t HLT:15;				// 14:0   High-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT5CMPH1_REG {
	uint16_t all;
	struct SDFLT5CMPH1_BITS bit;
};

struct SDFLT5CMPL1_BITS {			// bits   description
	uint16_t LLT:15;				// 14:0	  Low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT5CMPL1_REG {
	uint16_t all;
	struct SDFLT5CMPL1_BITS bit;
};

struct SDCPARM5_BITS {				// bits   description
	uint16_t COSR:5;				// 4:0	  Comparator Oversample Ratio. Actual rate COSR+1
	uint16_t EN_CEVT1:1;			// 5:5	  CEVT1 Interrupt enable
	uint16_t EN_CEVT2:1;			// 6:6	  CEVT2 Interrupt enable
	uint16_t CS1_CS0:2;				// 8:7    Comparator Filter Structure (SincFast/1/2/3)
	uint16_t MFIE:1;				// 9:9	  Modulator Failure Interrupt enable
	uint16_t HZEN:1;				// 10:10  High level (Z) Threshold crossing output enable
	uint16_t CEVT1SEL:2;			// 12:11  Comparator Event1 select
	uint16_t CEN:1;					// 13:13  Comparator Enable
	uint16_t CEVT2SEL:2;			// 15:14  Comparator Event2 select
};

union SDCPARM5_REG {
	uint16_t all;
	struct SDCPARM5_BITS bit;
};

struct SDDATA5_BITS {				// bits   description
	uint32_t DATA16:16;				// 15:0	  Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA5_REG {
	uint32_t all;
	struct SDDATA5_BITS bit;
};

struct SDDATFIFO5_BITS {			// bits   description
	uint32_t DATA16:16;				// 15:0	  Lo-order 16b in 32b mode
	uint32_t DATA32HI:16;			// 31:16  Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO5_REG {
	uint32_t all;
	struct SDDATFIFO5_BITS bit;
};

struct SDCDATA5_BITS {				// bits   description
	uint16_t DATA16:16;				// 15:0
};

union SDCDATA5_REG {
	uint16_t all;
	struct SDCDATA5_BITS bit;
};

struct SDFLT5CMPH2_BITS {			// bits   description
	uint16_t HLT2:15;				// 14:0   Second High level threshold
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT5CMPH2_REG {
	uint16_t all;
	struct SDFLT5CMPH2_BITS bit;
};

struct SDFLT5CMPHZ_BITS {			// bits   description
	uint16_t HLTZ:15;				// 14:0	  High-level threshold (Z) for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT5CMPHZ_REG {
	uint16_t all;
	struct SDFLT5CMPHZ_BITS bit;
};

struct SDFIFOCTL5_BITS {			// bits   description
	uint16_t SDFFIL:5;				// 4:0	  SDFIFO Interrupt Level
	uint16_t rsvd1:1;				// 5:5    reserved
	uint16_t SDFFST:5;				// 10:6	  SDFIFO Status
	uint16_t rsvd2:1;				// 11:11  reserved
	uint16_t FFIEN:1;				// 12:12  SDFIFO data ready Interrupt Enable
	uint16_t FFEN:1;				// 13:13  SDFIFO Enable
	uint16_t DRINTSEL:1;			// 14:14  Data-Ready Interrupt Source Select
	uint16_t OVFIEN:1;				// 15:15  SDFIFO Overflow interrupt enable
};

union SDFIFOCTL5_REG {
	uint16_t all;
	struct SDFIFOCTL5_BITS bit;
};

struct SDSYNC5_BITS {				// bits   description
	uint16_t SYNCSEL:6;				// 5:0	  SDSYNC Source Select
	uint16_t WTSYNCEN:1;			// 6:6	  Wait-for-Sync Enable
	uint16_t WTSYNFLG:1;			// 7:7	  Wait-for-Sync Flag
	uint16_t WTSYNCLR:1;			// 8:8	  Wait-for-Sync Flag Clear
	uint16_t FFSYNCCLREN:1;			// 9:9	  FIFO Clear-on-SDSYNC Enable
	uint16_t WTSCLREN:1;			// 10:10  WTSYNFLG Clear-on-FIFOINT Enable
	uint16_t rsvd1:5;				// 15:11  reserved
};

union SDSYNC5_REG {
	uint16_t all;
	struct SDSYNC5_BITS bit;
};

struct SDFLT5CMPL2_BITS {			// bits   description
	uint16_t LLT2:15;				// 14:0	  Second low-level threshold for the comparator filter output
	uint16_t rsvd1:1;				// 15:15  reserved
};

union SDFLT5CMPL2_REG {
	uint16_t all;
	struct SDFLT5CMPL2_BITS bit;
};

struct SDCOMP5CTL_BITS {			// bits   description
	uint16_t rsvd1:2;				// 1:0    reserved
	uint16_t CEVT1DIGFILTSEL:2;		// 3:2    High Comparator Trip Select
	uint16_t rsvd2:6;				// 9:4    reserved
	uint16_t CEVT2DIGFILTSEL:2;		// 11:10  Low Comparator Trip Select
	uint16_t rsvd3:4;				// 15:12  reserved
};

union SDCOMP5CTL_REG {
	uint16_t all;
	struct SDCOMP5CTL_BITS bit;
};

struct SDCOMP5EVT2FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15:15  Filter Initialization Bit
};

union SDCOMP5EVT2FLTCTL_REG {
	uint16_t all;
	struct SDCOMP5EVT2FLTCTL_BITS bit;
};

struct SDCOMP5EVT2FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP5EVT2FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP5EVT2FLTCLKCTL_BITS bit;
};

struct SDCOMP5EVT1FLTCTL_BITS {		// bits   description
	uint16_t rsvd1:4;				// 3:0    reserved
	uint16_t SAMPWIN:5;				// 8:4    Sample Window
	uint16_t THRESH:5;				// 13:9   Majority Voting Threshold
	uint16_t rsvd2:1;				// 14:14  reserved
	uint16_t FILINIT:1;				// 15:15  Filter Initialization Bit
};

union SDCOMP5EVT1FLTCTL_REG {
	uint16_t all;
	struct SDCOMP5EVT1FLTCTL_BITS bit;
};

struct SDCOMP5EVT1FLTCLKCTL_BITS {	// bits   description
	uint16_t CLKPRESCALE:10;		// 9:0    Sample Clock Prescale
	uint16_t rsvd1:6;				// 15:10  reserved
};

union SDCOMP5EVT1FLTCLKCTL_REG {
	uint16_t all;
	struct SDCOMP5EVT1FLTCLKCTL_BITS bit;
};

struct SDFILTERMODE_BITS{
	uint16_t SD1FILTERMODE:1;		// 0:0
	uint16_t SD2FILTERMODE:1;		// 1:1
	uint16_t SD3FILTERMODE:1;		// 2:2
	uint16_t SD4FILTERMODE:1;		// 3:3
	uint16_t SDFILTERNUM:2;			// 5:4
	uint16_t rsvd1:10;				// 15:6
};

union SDFILTERMODE_REG{
	uint16_t all;
	struct SDFILTERMODE_BITS bit;
};

struct SDFILTERDRPNUM1_BITS{
	uint32_t SD1FILTERDRPNUM:8;		// 7:0
	uint32_t SD2FILTERDRPNUM:8;		// 15:8
	uint32_t SD3FILTERDRPNUM:8;		// 23:16
	uint32_t SD4FILTERDRPNUM:8;		// 31:24
};

union SDFILTERDRPNUM1_REG{
	uint32_t all;
	struct	SDFILTERDRPNUM1_BITS bit;
};

struct SDFILTERDRPNUM2_BITS{
	uint32_t SD5FILTERDRPNUM:8;		// 7:0
	uint32_t rsvd1:24;				// 31:8
};

union SDFILTERDRPNUM2_REG{
	uint32_t all;
	struct SDFILTERDRPNUM2_BITS bit;
};

struct SDFILTERSYNCMODE_BITS{
	uint16_t SD1FILTERSYNCMODE:2;	// 1:0
	uint16_t SD2FILTERSYNCMODE:2;	// 3:2
	uint16_t SD3FILTERSYNCMODE:2;	// 5:4
	uint16_t SD4FILTERSYNCMODE:2;	// 7:6
	uint16_t rsvd1:8;				// 15:8
};

union SDFILTERSYNCMODE_REG{
	uint16_t all;
	struct SDFILTERSYNCMODE_BITS bit;
};

struct SDFILTERSYNCCLR_BITS{
	uint16_t SD1FILTERSYNCCLR:1;	// 0:0
	uint16_t SD2FILTERSYNCCLR:1;	// 1:1
	uint16_t SD3FILTERSYNCCLR:1;	// 2:2
	uint16_t SD4FILTERSYNCCLR:1;	// 3:3
	uint16_t rsvd1:12;				// 15:4
};

union SDFILTERSYNCCLR_REG{
	uint16_t all;
	struct SDFILTERSYNCCLR_BITS bit;
};



// SDFM Register Definitions:

struct SDFM_REGS {
	union SDIFLG_REG 				SDIFLG;					// SD Interrupt Flag Register
	union SDIFLGCLR_REG				SDIFLGCLR;				// SD Interrupt Flag Clear Register
	union SDCTL_REG					SDCTL;					// SD Control Register
	uint16_t 						rsvd1;					// reserved
	union SDMFILEN_REG				SDMFILEN;				// SD Master Filter Enable
	union SDSTATUS_REG				SDSTATUS;				// SD Status Register
	uint32_t						rsvd2[4];				// reserved
	union SDCTLPARM1_REG			SDCTLPARM1;				// Control Parameter Register for Ch1
	union SDDFPARM1_REG				SDDFPARM1;				// Data Filter Parameter Register for Ch1
	union SDDPARM1_REG				SDDPARM1;				// Data Parameter Register for Ch1
	union SDFLT1CMPH1_REG			SDFLT1CMPH1;			// High-level Threshold Register for Ch1
	union SDFLT1CMPL1_REG			SDFLT1CMPL1;			// Low-level Threshold Register for Ch1
	union SDCPARM1_REG				SDCPARM1;				// Comparator Filter Parameter Register for Ch1
	union SDDATA1_REG				SDDATA1;				// Data Filter Data Register (16 or 32bit) for Ch1
	union SDDATFIFO1_REG			SDDATFIFO1;				// Filter Data FIFO Output(32b) for Ch1
	union SDCDATA1_REG				SDCDATA1;				// Comparator Filter Data Register (16b) for Ch1
	union SDFLT1CMPH2_REG			SDFLT1CMPH2;			// Second high level threhold  for CH1
	union SDFLT1CMPHZ_REG			SDFLT1CMPHZ;			// High-level (Z) Threshold Register for Ch1
	union SDFIFOCTL1_REG			SDFIFOCTL1;				// FIFO Control Register for Ch1
	union SDSYNC1_REG				SDSYNC1;				// SD Filter Sync control for Ch1
	union SDFLT1CMPL2_REG			SDFLT1CMPL2;			// Second low level threhold  for CH1
	union SDCTLPARM2_REG			SDCTLPARM2; 			// Control Parameter Register for Ch2
	union SDDFPARM2_REG				SDDFPARM2;				// Data Filter Parameter Register for Ch2
	union SDDPARM2_REG				SDDPARM2;				// Data Parameter Register for Ch2
	union SDFLT2CMPH1_REG			SDFLT2CMPH1;			// High-level Threshold Register for Ch2
	union SDFLT2CMPL1_REG			SDFLT2CMPL1;			// Low-level Threshold Register for Ch2
	union SDCPARM2_REG				SDCPARM2;				// Comparator Filter Parameter Register for Ch2
	union SDDATA2_REG				SDDATA2;				// Data Filter Data Register (16 or 32bit) for Ch2
	union SDDATFIFO2_REG			SDDATFIFO2;				// Filter Data FIFO Output(32b) for Ch2
	union SDCDATA2_REG				SDCDATA2;				// Comparator Filter Data Register (16b) for Ch2
	union SDFLT2CMPH2_REG			SDFLT2CMPH2;			// Second high level threhold  for CH2
	union SDFLT2CMPHZ_REG 			SDFLT2CMPHZ;			// High-level (Z) Threshold Register for Ch2
	union SDFIFOCTL2_REG			SDFIFOCTL2;				// FIFO Control Register for Ch2
	union SDSYNC2_REG				SDSYNC2;				// SD Filter Sync control for Ch2
	union SDFLT2CMPL2_REG			SDFLT2CMPL2;			// Second low level threhold  for CH2
	union SDCTLPARM3_REG			SDCTLPARM3;				// Control Parameter Register for Ch3
	union SDDFPARM3_REG				SDDFPARM3;				// Data Filter Parameter Register for Ch3
	union SDDPARM3_REG				SDDPARM3;				// Data Parameter Register for Ch3
	union SDFLT3CMPH1_REG			SDFLT3CMPH1;			// High-level Threshold Register for Ch3
	union SDFLT3CMPL1_REG			SDFLT3CMPL1;			// Low-level Threshold Register for Ch3
	union SDCPARM3_REG				SDCPARM3;				// Comparator Filter Parameter Register for Ch3
	union SDDATA3_REG				SDDATA3;				// Data Filter Data Register (16 or 32bit) for Ch3
	union SDDATFIFO3_REG			SDDATFIFO3;				// Filter Data FIFO Output(32b) for Ch3
	union SDCDATA3_REG				SDCDATA3;				// Comparator Filter Data Register (16b) for Ch3
	union SDFLT3CMPH2_REG			SDFLT3CMPH2;			// Second high level threhold  for CH3
	union SDFLT3CMPHZ_REG			SDFLT3CMPHZ;			// High-level (Z) Threshold Register for Ch3
	union SDFIFOCTL3_REG			SDFIFOCTL3;				// FIFO Control Register for Ch3
	union SDSYNC3_REG				SDSYNC3;				// SD Filter Sync control for Ch3
	union SDFLT3CMPL2_REG			SDFLT3CMPL2;			// Second low level threhold  for CH3
	union SDCTLPARM4_REG			SDCTLPARM4;				// Control Parameter Register for Ch4
	union SDDFPARM4_REG				SDDFPARM4;				// Data Filter Parameter Register for Ch4
	union SDDPARM4_REG				SDDPARM4;				// Data Parameter Register for Ch4
	union SDFLT4CMPH1_REG			SDFLT4CMPH1;			// High-level Threshold Register for Ch4
	union SDFLT4CMPL1_REG			SDFLT4CMPL1;			// Low-level Threshold Register for Ch4
	union SDCPARM4_REG				SDCPARM4;				// Comparator Filter Parameter Register for Ch4
	union SDDATA4_REG				SDDATA4;				// Data Filter Data Register (16 or 32bit) for Ch4
	union SDDATFIFO4_REG			SDDATFIFO4;				// Filter Data FIFO Output(32b) for Ch4
	union SDCDATA4_REG				SDCDATA4;				// Comparator Filter Data Register (16b) for Ch4
	union SDFLT4CMPH2_REG			SDFLT4CMPH2;			// Second high level threhold  for CH4
	union SDFLT4CMPHZ_REG			SDFLT4CMPHZ;			// High-level (Z) Threshold Register for Ch4
	union SDFIFOCTL4_REG			SDFIFOCTL4;				// FIFO Control Register for Ch4
	union SDSYNC4_REG				SDSYNC4;				// SD Filter Sync control for Ch4
	union SDFLT4CMPL2_REG			SDFLT4CMPL2;			// Second low level threhold  for CH4
	uint32_t						rsvd3[8];				// reserved
	union SDCOMP1CTL_REG			SDCOMP1CTL;				// SD Comparator event filter1 Control Register
	union SDCOMP1EVT2FLTCTL_REG		SDCOMP1EVT2FLTCTL;		// COMPL/CEVT2 Digital filter1 Control Register
	union SDCOMP1EVT2FLTCLKCTL_REG	SDCOMP1EVT2FLTCLKCTL;	// COMPL/CEVT2 Digital filter1 Clock Control Register
	union SDCOMP1EVT1FLTCTL_REG		SDCOMP1EVT1FLTCTL;		// COMPH/CEVT1 Digital filter1 Control Register
	union SDCOMP1EVT1FLTCLKCTL_REG	SDCOMP1EVT1FLTCLKCTL;	// COMPH/CEVT1 Digital filter1 Clock Control Register
	uint16_t						rsvd4[3];				// reserved
	union SDCOMP2CTL_REG			SDCOMP2CTL;				// SD Comparator event filter2 Control Register
	union SDCOMP2EVT2FLTCTL_REG		SDCOMP2EVT2FLTCTL;		// COMPL/CEVT2 Digital filter2 Control Register
	union SDCOMP2EVT2FLTCLKCTL_REG	SDCOMP2EVT2FLTCLKCTL;	// COMPL/CEVT2 Digital filter2 Clock Control Register
	union SDCOMP2EVT1FLTCTL_REG		SDCOMP2EVT1FLTCTL;		// COMPH/CEVT1 Digital filter2 Control Register
	union SDCOMP2EVT1FLTCLKCTL_REG	SDCOMP2EVT1FLTCLKCTL;	// COMPH/CEVT1 Digital filter2 Clock Control Register
	uint16_t						rsvd5[3];				// reserved
	union SDCOMP3CTL_REG			SDCOMP3CTL;				// SD Comparator event filter3 Control Register
	union SDCOMP3EVT2FLTCTL_REG		SDCOMP3EVT2FLTCTL;		// COMPL/CEVT2 Digital filter3 Control Register
	union SDCOMP3EVT2FLTCLKCTL_REG	SDCOMP3EVT2FLTCLKCTL;	// COMPL/CEVT2 Digital filter3 Clock Control Register
	union SDCOMP3EVT1FLTCTL_REG		SDCOMP3EVT1FLTCTL;		// COMPH/CEVT1 Digital filter3 Control Register
	union SDCOMP3EVT1FLTCLKCTL_REG	SDCOMP3EVT1FLTCLKCTL;	// COMPH/CEVT1 Digital filter3 Clock Control Register
	uint16_t						rsvd6[3];				// reserved
	union SDCOMP4CTL_REG			SDCOMP4CTL;				// SD Comparator event filter4 Control Register
	union SDCOMP4EVT2FLTCTL_REG		SDCOMP4EVT2FLTCTL;		// COMPL/CEVT2 Digital filter4 Control Register
	union SDCOMP4EVT2FLTCLKCTL_REG	SDCOMP4EVT2FLTCLKCTL;	// COMPL/CEVT2 Digital filter4 Clock Control Register
	union SDCOMP4EVT1FLTCTL_REG		SDCOMP4EVT1FLTCTL;		// COMPH/CEVT1 Digital filter4 Control Register
	union SDCOMP4EVT1FLTCLKCTL_REG	SDCOMP4EVT1FLTCLKCTL;	// COMPH/CEVT1 Digital filter4 Clock Control Register
	uint16_t						rsvd7[3];				// reserved
	union SDREGSLOCK_REG			SDREGSLOCK;
	union SD_CLKERR_PERIOD_REG		SD_CLKERR_PERIOD;


	union SD_TYPE_REG				SD_TYPE;
	union SD_MANCHESTER_ERR_MODE_REG	MANCHESTER_ERR_MODE;

	union SD_MANCHESTER_ERR_MODE_REG	MANCHESTER_ERR_MODE;
	union SDMODEEN_REG					MODE_EN;
	union SDCOMP1EVTFLTEN_REG			SDCOMP1EVTFLTEN;
	union SDCOMP2EVTFLTEN_REG			SDCOMP2EVTFLTEN;
	union SDCOMP3EVTFLTEN_REG			SDCOMP3EVTFLTEN;
	union SDCOMP4EVTFLTEN_REG			SDCOMP4EVTFLTEN;
	union SDINMUX_REG					SDINMUX;

	union SD_MANCHESTER_ERR_MODE_REG	MANCHESTER_ERR_MODE;	
	union SDMODEEN_REG					MODE_EN;				
	union SDCOMP1EVTFLTEN_REG			SDCOMP1EVTFLTEN;		
	union SDCOMP2EVTFLTEN_REG			SDCOMP2EVTFLTEN;		
	union SDCOMP3EVTFLTEN_REG			SDCOMP3EVTFLTEN;		
	union SDCOMP4EVTFLTEN_REG			SDCOMP4EVTFLTEN;		
	union SDINMUX_REG					SDINMUX;				
	uint32_t							rsvd8;
	union SDCTLPARM5_REG				SDCTLPARM5;				
	union SDDFPARM5_REG					SDDFPARM5;				
	union SDDPARM5_REG					SDDPARM5;				
	union SDFLT5CMPH1_REG				SDFLT5CMPH1;
	union SDFLT5CMPL1_REG				SDFLT5CMPL1;
	union SDCPARM5_REG					SDCPARM5;				
	union SDDATA5_REG					SDDATA5;				
	union SDDATFIFO5_REG				SDDATFIFO5;				
	union SDCDATA5_REG					SDCDATA5;				
	union SDFLT5CMPH2_REG				SDFLT5CMPH2;			
	union SDFLT5CMPHZ_REG				SDFLT5CMPHZ;			
	union SDFIFOCTL5_REG				SDFIFOCTL5;				
	union SDSYNC5_REG					SDSYNC5;				
	union SDFLT5CMPL2_REG				SDFLT5CMPL2;			
	uint32_t							rsvd9[32];				
	union SDCOMP5CTL_REG				SDCOMP5CTL;				
	union SDCOMP5EVT2FLTCTL_REG			SDCOMP5EVT2FLTCTL;		
	union SDCOMP5EVT2FLTCLKCTL_REG		SDCOMP5EVT2FLTCLKCTL;	
	union SDCOMP5EVT1FLTCTL_REG			SDCOMP5EVT1FLTCTL;		
	union SDCOMP5EVT1FLTCLKCTL_REG		SDCOMP5EVT1FLTCLKCTL;	
	uint16_t							rsvd10[3];				
	union SDFILTERMODE_REG				SDFILTERMODE;			
	uint16_t							rsvd11;					
	union SDFILTERDRPNUM1_REG			SDFILTERDRPNUM1;		
	union SDFILTERDRPNUM2_REG			SDFILTERDRPNUM2;		
	union SDFILTERSYNCMODE_REG			SDFILTERSYNCMODE;		
	union SDFILTERSYNCCLR_REG			SDFILTERSYNCCLR;		

};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

// SDFM External References & Function Declarations
extern volatile struct SDFM_REGS Sdfm1Regs;
extern volatile struct SDFM_REGS Sdfm2Regs;
#endif

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif /* DRIVERLIB_REGS_REGS_SDFM_H_ */
