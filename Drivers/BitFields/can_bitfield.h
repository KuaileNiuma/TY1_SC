
 
#ifndef REGS_CAN_H
#define REGS_CAN_H

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
// CAN Individual Register Bit Definitions:

struct RBUF0TO3_BITS {			// bits   description
	uint32_t	ID:11;			// 10:0   ID Message
	uint32_t	rsvd1:20;			// 30:11   reserved
	uint32_t	ESI:1;			// 31:31   The protocol machine automatically embeds the correct value of ESI into transmitted frames. ESI 
};

union RBUF0TO3_REG {
	uint32_t 		 all;
	struct RBUF0TO3_BITS 		 bit;
};

struct RBUF4TO7_BITS {			// bits   description
	uint32_t	DLC:4;			// 3:0   DLC   Frame Type  Payload in Bytes
	uint32_t	BRS:1;			// 4:4   Bit Rate Switch
	uint32_t	FDF:1;			// 5:5   CAN FD frame
	uint32_t	RTR:1;			// 6:6   Remote Transmission Request
	uint32_t	IDE:1;			// 7:7   IDentifier Extension
	uint32_t	rsvd1:4;			// 11:8   reserved
	uint32_t	TX:1;			// 12:12   Status bit TX in RBUF is set to 1 if the loop back mode is activated and the core has 
	uint32_t	KOER:3;			// 15:13   KOER in RBUF has the same meaning as the bits KOER in register EALCAP. KOER in RBUF becomes 
	uint32_t	CYCLE_TIME:16;			// 31:16   The time-stamp CYCLE_TIME will be stored in RBUF only in TTCAN mode.
};

union RBUF4TO7_REG {
	uint32_t 		 all;
	struct RBUF4TO7_BITS 		 bit;
};

struct RBUF8TO11_BITS {			// bits   description
	uint32_t	D1:8;			// 7:0   databyte1
	uint32_t	D2:8;			// 15:8   databyte2
	uint32_t	D3:8;			// 23:16   databyte3
	uint32_t	D4:8;			// 31:24   databyte4
};

union RBUF8TO11_REG {
	uint32_t 		 all;
	struct RBUF8TO11_BITS 		 bit;
};

struct RBUF12TO15_BITS {			// bits   description
	uint32_t	D5:8;			// 7:0   databyte5
	uint32_t	D6:8;			// 15:8   databyte6
	uint32_t	D7:8;			// 23:16   databyte7
	uint32_t	D8:8;			// 31:24   databyte8
};

union RBUF12TO15_REG {
	uint32_t 		 all;
	struct RBUF12TO15_BITS 		 bit;
};

struct RBUF16TO19_BITS {			// bits   description
	uint32_t	D9:8;			// 7:0   databyte9
	uint32_t	D10:8;			// 15:8   databyte10
	uint32_t	D11:8;			// 23:16   databyte11
	uint32_t	D12:8;			// 31:24   databyte12
};

union RBUF16TO19_REG {
	uint32_t 		 all;
	struct RBUF16TO19_BITS 		 bit;
};

struct RBUF20TO23_BITS {			// bits   description
	uint32_t	D13:8;			// 7:0   databyte13
	uint32_t	D14:8;			// 15:8   databyte14
	uint32_t	D15:8;			// 23:16   databyte15
	uint32_t	D16:8;			// 31:24   databyte16
};

union RBUF20TO23_REG {
	uint32_t 		 all;
	struct RBUF20TO23_BITS 		 bit;
};

struct RBUF24TO27_BITS {			// bits   description
	uint32_t	D17:8;			// 7:0   databyte17
	uint32_t	D18:8;			// 15:8   databyte18
	uint32_t	D19:8;			// 23:16   databyte19
	uint32_t	D20:8;			// 31:24   databyte20
};

union RBUF24TO27_REG {
	uint32_t 		 all;
	struct RBUF24TO27_BITS 		 bit;
};

struct RBUF28TO31_BITS {			// bits   description
	uint32_t	D21:8;			// 7:0   databyte21
	uint32_t	D22:8;			// 15:8   databyte22
	uint32_t	D23:8;			// 23:16   databyte23
	uint32_t	D24:8;			// 31:24   databyte24
};

union RBUF28TO31_REG {
	uint32_t 		 all;
	struct RBUF28TO31_BITS 		 bit;
};

struct RBUF32TO35_BITS {			// bits   description
	uint32_t	D25:8;			// 7:0   databyte25
	uint32_t	D26:8;			// 15:8   databyte26
	uint32_t	D27:8;			// 23:16   databyte27
	uint32_t	D28:8;			// 31:24   databyte28
};

union RBUF32TO35_REG {
	uint32_t 		 all;
	struct RBUF32TO35_BITS 		 bit;
};

struct RBUF36TO39_BITS {			// bits   description
	uint32_t	D29:8;			// 7:0   databyte29
	uint32_t	D30:8;			// 15:8   databyte30
	uint32_t	D31:8;			// 23:16   databyte31
	uint32_t	D32:8;			// 31:24   databyte32
};

union RBUF36TO39_REG {
	uint32_t 		 all;
	struct RBUF36TO39_BITS 		 bit;
};

struct RBUF40TO43_BITS {			// bits   description
	uint32_t	D33:8;			// 7:0   databyte33
	uint32_t	D34:8;			// 15:8   databyte34
	uint32_t	D35:8;			// 23:16   databyte35
	uint32_t	D36:8;			// 31:24   databyte36
};

union RBUF40TO43_REG {
	uint32_t 		 all;
	struct RBUF40TO43_BITS 		 bit;
};

struct RBUF44TO47_BITS {			// bits   description
	uint32_t	D37:8;			// 7:0   databyte37
	uint32_t	D38:8;			// 15:8   databyte38
	uint32_t	D39:8;			// 23:16   databyte39
	uint32_t	D40:8;			// 31:24   databyte40
};

union RBUF44TO47_REG {
	uint32_t 		 all;
	struct RBUF44TO47_BITS 		 bit;
};

struct RBUF48TO51_BITS {			// bits   description
	uint32_t	D41:8;			// 7:0   databyte41
	uint32_t	D42:8;			// 15:8   databyte42
	uint32_t	D43:8;			// 23:16   databyte43
	uint32_t	D44:8;			// 31:24   databyte44
};

union RBUF48TO51_REG {
	uint32_t 		 all;
	struct RBUF48TO51_BITS 		 bit;
};

struct RBUF52TO55_BITS {			// bits   description
	uint32_t	D45:8;			// 7:0   databyte45
	uint32_t	D46:8;			// 15:8   databyte46
	uint32_t	D47:8;			// 23:16   databyte47
	uint32_t	D48:8;			// 31:24   databyte48
};

union RBUF52TO55_REG {
	uint32_t 		 all;
	struct RBUF52TO55_BITS 		 bit;
};

struct RBUF56TO59_BITS {			// bits   description
	uint32_t	D49:8;			// 7:0   databyte49
	uint32_t	D50:8;			// 15:8   databyte50
	uint32_t	D51:8;			// 23:16   databyte51
	uint32_t	D52:8;			// 31:24   databyte52
};

union RBUF56TO59_REG {
	uint32_t 		 all;
	struct RBUF56TO59_BITS 		 bit;
};

struct RBUF60TO63_BITS {			// bits   description
	uint32_t	D53:8;			// 7:0   databyte53
	uint32_t	D54:8;			// 15:8   databyte54
	uint32_t	D55:8;			// 23:16   databyte55
	uint32_t	D56:8;			// 31:24   databyte56
};

union RBUF60TO63_REG {
	uint32_t 		 all;
	struct RBUF60TO63_BITS 		 bit;
};

struct RBUF64TO67_BITS {			// bits   description
	uint32_t	D57:8;			// 7:0   databyte57
	uint32_t	D58:8;			// 15:8   databyte58
	uint32_t	D59:8;			// 23:16   databyte59
	uint32_t	D60:8;			// 31:24   databyte60
};

union RBUF64TO67_REG {
	uint32_t 		 all;
	struct RBUF64TO67_BITS 		 bit;
};

struct RBUF68TO71_BITS {			// bits   description
	uint32_t	D61:8;			// 7:0   databyte61
	uint32_t	D62:8;			// 15:8   databyte62
	uint32_t	D63:8;			// 23:16   databyte63
	uint32_t	D64:8;			// 31:24   databyte64
};

union RBUF68TO71_REG {
	uint32_t 		 all;
	struct RBUF68TO71_BITS 		 bit;
};

struct RBUF72TO75_BITS {			// bits   description
	uint32_t	RTS7_0:8;			// 7:0   The Reception Time Stamps (RTS) for CiA 603 time-stamping are stored for each received message at 
	uint32_t	RTS15_8:8;			// 15:8   The Reception Time Stamps (RTS) for CiA 603 time-stamping are stored for each received message at 
	uint32_t	RTS23_16:8;			// 23:16   The Reception Time Stamps (RTS) for CiA 603 time-stamping are stored for each received message at 
	uint32_t	RTS31_24:8;			// 31:24   The Reception Time Stamps (RTS) for CiA 603 time-stamping are stored for each received message at 
};

union RBUF72TO75_REG {
	uint32_t 		 all;
	struct RBUF72TO75_BITS 		 bit;
};

struct RBUF76TO79_BITS {			// bits   description
	uint32_t	RTS39_32:8;			// 7:0   The Reception Time Stamps (RTS) for CiA 606 time-stamping are stored for each received message at 
	uint32_t	RTS47_40:8;			// 15:8   The Reception Time Stamps (RTS) for CiA 605 time-stamping are stored for each received message at 
	uint32_t	RTS55_48:8;			// 23:16   The Reception Time Stamps (RTS) for CiA 604 time-stamping are stored for each received message at 
	uint32_t	RTS63_56:8;			// 31:24   The Reception Time Stamps (RTS) for CiA 603 time-stamping are stored for each received message at 
};

union RBUF76TO79_REG {
	uint32_t 		 all;
	struct RBUF76TO79_BITS 		 bit;
};

struct TBUF0TO3_BITS {			// bits   description
	uint32_t	ID:11;			// 10:0   ID value
	uint32_t	rsvd1:20;			// 30:11   reserved
	uint32_t	TTSEN:1;			// 31:31   Transmit Time-Stamp ENable
};

union TBUF0TO3_REG {
	uint32_t 		 all;
	struct TBUF0TO3_BITS 		 bit;
};

struct TBUF4TO7_BITS {			// bits   description
	uint32_t	DLC:4;			// 3:0   The Data Length Code (DLC) in RBUF and TBUF defines the length of the payload 
	uint32_t	BRS:1;			// 4:4   Bit Rate Switch
	uint32_t	FDF:1;			// 5:5   CAN FD frame
	uint32_t	RTR:1;			// 6:6   Remote Transmission Request
	uint32_t	IDE:1;			// 7:7   IDentifier Extension
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union TBUF4TO7_REG {
	uint32_t 		 all;
	struct TBUF4TO7_BITS 		 bit;
};

struct TBUF8TO11_BITS {			// bits   description
	uint32_t	D1:8;			// 7:0   databyte1
	uint32_t	D2:8;			// 15:8   databyte2
	uint32_t	D3:8;			// 23:16   databyte3
	uint32_t	D4:8;			// 31:24   databyte4
};

union TBUF8TO11_REG {
	uint32_t 		 all;
	struct TBUF8TO11_BITS 		 bit;
};

struct TBUF12TO15_BITS {			// bits   description
	uint32_t	D5:8;			// 7:0   databyte5
	uint32_t	D6:8;			// 15:8   databyte6
	uint32_t	D7:8;			// 23:16   databyte7
	uint32_t	D8:8;			// 31:24   databyte8
};

union TBUF12TO15_REG {
	uint32_t 		 all;
	struct TBUF12TO15_BITS 		 bit;
};

struct TBUF16TO19_BITS {			// bits   description
	uint32_t	D9:8;			// 7:0   databyte9
	uint32_t	D10:8;			// 15:8   databyte10
	uint32_t	D11:8;			// 23:16   databyte11
	uint32_t	D12:8;			// 31:24   databyte12
};

union TBUF16TO19_REG {
	uint32_t 		 all;
	struct TBUF16TO19_BITS 		 bit;
};

struct TBUF20TO23_BITS {			// bits   description
	uint32_t	D13:8;			// 7:0   databyte13
	uint32_t	D14:8;			// 15:8   databyte14
	uint32_t	D15:8;			// 23:16   databyte15
	uint32_t	D16:8;			// 31:24   databyte16
};

union TBUF20TO23_REG {
	uint32_t 		 all;
	struct TBUF20TO23_BITS 		 bit;
};

struct TBUF24TO27_BITS {			// bits   description
	uint32_t	D17:8;			// 7:0   databyte17
	uint32_t	D18:8;			// 15:8   databyte18
	uint32_t	D19:8;			// 23:16   databyte19
	uint32_t	D20:8;			// 31:24   databyte20
};

union TBUF24TO27_REG {
	uint32_t 		 all;
	struct TBUF24TO27_BITS 		 bit;
};

struct TBUF28TO31_BITS {			// bits   description
	uint32_t	D21:8;			// 7:0   databyte21
	uint32_t	D22:8;			// 15:8   databyte22
	uint32_t	D23:8;			// 23:16   databyte23
	uint32_t	D24:8;			// 31:24   databyte24
};

union TBUF28TO31_REG {
	uint32_t 		 all;
	struct TBUF28TO31_BITS 		 bit;
};

struct TBUF32TO35_BITS {			// bits   description
	uint32_t	D25:8;			// 7:0   databyte25
	uint32_t	D26:8;			// 15:8   databyte26
	uint32_t	D27:8;			// 23:16   databyte27
	uint32_t	D28:8;			// 31:24   databyte28
};

union TBUF32TO35_REG {
	uint32_t 		 all;
	struct TBUF32TO35_BITS 		 bit;
};

struct TBUF36TO39_BITS {			// bits   description
	uint32_t	D29:8;			// 7:0   databyte29
	uint32_t	D30:8;			// 15:8   databyte30
	uint32_t	D31:8;			// 23:16   databyte31
	uint32_t	D32:8;			// 31:24   databyte32
};

union TBUF36TO39_REG {
	uint32_t 		 all;
	struct TBUF36TO39_BITS 		 bit;
};

struct TBUF40TO43_BITS {			// bits   description
	uint32_t	D33:8;			// 7:0   databyte33
	uint32_t	D34:8;			// 15:8   databyte34
	uint32_t	D35:8;			// 23:16   databyte35
	uint32_t	D36:8;			// 31:24   databyte36
};

union TBUF40TO43_REG {
	uint32_t 		 all;
	struct TBUF40TO43_BITS 		 bit;
};

struct TBUF44TO47_BITS {			// bits   description
	uint32_t	D37:8;			// 7:0   databyte37
	uint32_t	D38:8;			// 15:8   databyte38
	uint32_t	D39:8;			// 23:16   databyte39
	uint32_t	D40:8;			// 31:24   databyte40
};

union TBUF44TO47_REG {
	uint32_t 		 all;
	struct TBUF44TO47_BITS 		 bit;
};

struct TBUF48TO51_BITS {			// bits   description
	uint32_t	D41:8;			// 7:0   databyte41
	uint32_t	D42:8;			// 15:8   databyte42
	uint32_t	D43:8;			// 23:16   databyte43
	uint32_t	D44:8;			// 31:24   databyte44
};

union TBUF48TO51_REG {
	uint32_t 		 all;
	struct TBUF48TO51_BITS 		 bit;
};

struct TBUF52TO55_BITS {			// bits   description
	uint32_t	D45:8;			// 7:0   databyte45
	uint32_t	D46:8;			// 15:8   databyte46
	uint32_t	D47:8;			// 23:16   databyte47
	uint32_t	D48:8;			// 31:24   databyte48
};

union TBUF52TO55_REG {
	uint32_t 		 all;
	struct TBUF52TO55_BITS 		 bit;
};

struct TBUF56TO59_BITS {			// bits   description
	uint32_t	D49:8;			// 7:0   databyte49
	uint32_t	D50:8;			// 15:8   databyte50
	uint32_t	D51:8;			// 23:16   databyte51
	uint32_t	D52:8;			// 31:24   databyte52
};

union TBUF56TO59_REG {
	uint32_t 		 all;
	struct TBUF56TO59_BITS 		 bit;
};

struct TBUF60TO63_BITS {			// bits   description
	uint32_t	D53:8;			// 7:0   databyte53
	uint32_t	D54:8;			// 15:8   databyte54
	uint32_t	D55:8;			// 23:16   databyte55
	uint32_t	D56:8;			// 31:24   databyte56
};

union TBUF60TO63_REG {
	uint32_t 		 all;
	struct TBUF60TO63_BITS 		 bit;
};

struct TBUF64TO67_BITS {			// bits   description
	uint32_t	D57:8;			// 7:0   databyte57
	uint32_t	D58:8;			// 15:8   databyte58
	uint32_t	D59:8;			// 23:16   databyte59
	uint32_t	D60:8;			// 31:24   databyte60
};

union TBUF64TO67_REG {
	uint32_t 		 all;
	struct TBUF64TO67_BITS 		 bit;
};

struct TBUF68TO71_BITS {			// bits   description
	uint32_t	D61:8;			// 7:0   databyte61
	uint32_t	D62:8;			// 15:8   databyte62
	uint32_t	D63:8;			// 23:16   databyte63
	uint32_t	D64:8;			// 31:24   databyte64
};

union TBUF68TO71_REG {
	uint32_t 		 all;
	struct TBUF68TO71_BITS 		 bit;
};

struct TTS_L_BITS {			// bits   description
	uint32_t	TRANSMISSION_TIME_STAMP_L:32;			// 31:0   Transmission Time Stamp
};

union TTS_L_REG {
	uint32_t 		 all;
	struct TTS_L_BITS 		 bit;
};

struct TTS_H_BITS {			// bits   description
	uint32_t	TRANSMISSION_TIME_STAMP_H:32;			// 31:0   Transmission Time Stamp
};

union TTS_H_REG {
	uint32_t 		 all;
	struct TTS_H_BITS 		 bit;
};

struct CFG_STAT_TCMD_TCTRL_RCTRL_BITS {			// bits   description
	uint32_t	BUSOFF:1;			// 0:0   Bus Off 
	uint32_t	TACTIVE:1;			// 1:1   Transmission ACTIVE (Transmit Status bit)
	uint32_t	RACTIVE:1;			// 2:2   Reception ACTIVE (Receive Status bit)
	uint32_t	TSSS:1;			// 3:3   Transmission Secondary Single Shot mode for STB 
	uint32_t	TPSS:1;			// 4:4   Transmission Primary Single Shot mode for PTB
	uint32_t	LBMI:1;			// 5:5   Loop Back Mode, Internal
	uint32_t	LBME:1;			// 6:6   Loop Back Mode, External
	uint32_t	RESET:1;			// 7:7   RESET request bit
	uint32_t	TSA:1;			// 8:8   Transmit Secondary Abort
	uint32_t	TSALL:1;			// 9:9   Transmit Secondary ALL frames
	uint32_t	TSONE:1;			// 10:10   Transmit Secondary ONE frame
	uint32_t	TPA:1;			// 11:11   Transmit Primary Abort
	uint32_t	TPE:1;			// 12:12   Transmit Primary Enable 
	uint32_t	STBY:1;			// 13:13   Transceiver Standby Mode  
	uint32_t	LOM:1;			// 14:14   Listen Only Mode
	uint32_t	TBSEL:1;			// 15:15   Transmit Buffer Select
	uint32_t	TSSTAT:2;			// 17:16   Transmission Secondary STATus bits
	uint32_t	rsvd1:2;			// 19:18   reserved
	uint32_t	TTTBM:1;			// 20:20   TTCAN Transmit Buffer Mode
	uint32_t	TSMODE:1;			// 21:21   Transmit buffer Secondary operation MODE
	uint32_t	TSNEXT:1;			// 22:22   Transmit buffer Secondary NEXT
	uint32_t	FD_ISO:1;			// 23:23   CAN FD ISO mode
	uint32_t	RSTAT:2;			// 25:24   Receive buffer STATus 
	uint32_t	rsvd2:1;			// 26:26   reserved
	uint32_t	RBALL:1;			// 27:27   Receive Buffer stores ALL data frames
	uint32_t	RREL:1;			// 28:28   Receive buffer RELease
	uint32_t	ROV:1;			// 29:29   Receive buffer OVerflow
	uint32_t	ROM:1;			// 30:30   Receive buffer Overflow Mode
	uint32_t	SACK:1;			// 31:31   Self-ACKnowledge
};

union CFG_STAT_TCMD_TCTRL_RCTRL_REG {
	uint32_t 		 all;
	struct CFG_STAT_TCMD_TCTRL_RCTRL_BITS 		 bit;
};

struct RTIE_RTIE_ERRINT_LIMIT_BITS {			// bits   description
	uint32_t	TSFF:1;			// 0:0   If TTEN=0 or TTTBM=0: Transmit Secondary buffer Full Flag
	uint32_t	EIE:1;			// 1:1   Error Interrupt Enable
	uint32_t	TSIE:1;			// 2:2   Transmission Secondary Interrupt Enable
	uint32_t	TPIE:1;			// 3:3   Transmission Primary Interrupt Enable
	uint32_t	RAFIE:1;			// 4:4   RB Almost Full Interrupt Enable
	uint32_t	RFIE:1;			// 5:5   RB Full Interrupt Enable
	uint32_t	ROIE:1;			// 6:6   RB Overrun Interrupt Enable
	uint32_t	RIE:1;			// 7:7   Receive Interrupt Enable
	uint32_t	AIF:1;			// 8:8   Abort Interrupt Flag
	uint32_t	EIF:1;			// 9:9   Error Interrupt Flag
	uint32_t	TSIF:1;			// 10:10   Transmission Secondary Interrupt Flag
	uint32_t	TPIF:1;			// 11:11   Transmission Primary Interrupt Flag
	uint32_t	RAFIF:1;			// 12:12   RB Almost Full Interrupt Flag
	uint32_t	RFIF:1;			// 13:13   RB Full Interrupt Flag
	uint32_t	ROIF:1;			// 14:14   RB Overrun Interrupt Flag
	uint32_t	RIF:1;			// 15:15   Receive Interrupt Flag
	uint32_t	BEIF:1;			// 16:16   Bus Error Interrupt Flag
	uint32_t	BEIE:1;			// 17:17   Bus Error Interrupt Enable
	uint32_t	ALIF:1;			// 18:18   Arbitration Lost Interrupt Flag
	uint32_t	ALIE:1;			// 19:19   Arbitration Lost Interrupt Enable
	uint32_t	EPIF:1;			// 20:20   Error Passive Interrupt Flag. EPIF will be activated if the error status changes from error 
	uint32_t	EPIE:1;			// 21:21   Error Passive Interrupt Enable
	uint32_t	EPASS:1;			// 22:22   Error Passive mode active
	uint32_t	EWARN:1;			// 23:23   Error WARNing limit reached
	uint32_t	EWL:4;			// 27:24   Programmable Error Warning Limit = (EWL+1)*8. Possible Limit values: 8, 16, ...128.
	uint32_t	AFWL:4;			// 31:28   receive buffer Almost Full Warning Limit
};

union RTIE_RTIE_ERRINT_LIMIT_REG {
	uint32_t 		 all;
	struct RTIE_RTIE_ERRINT_LIMIT_BITS 		 bit;
};

struct S_SEG_1_S_SEG_2_S_SJW_S_PRESC_BITS {			// bits   description
	uint32_t	S_SEG_1:8;			// 7:0   Bit Timing Segment 1 (slow speed)
	uint32_t	S_SEG_2:7;			// 14:8   Bit Timing Segment 2 (slow speed)
	uint32_t	rsvd1:1;			// 15:15   reserved
	uint32_t	S_SJW:7;			// 22:16   Synchronization Jump Width (slow speed)
	uint32_t	rsvd2:1;			// 23:23   reserved
	uint32_t	S_PRESC:8;			// 31:24   Prescaler (slow speed)
};

union S_SEG_1_S_SEG_2_S_SJW_S_PRESC_REG {
	uint32_t 		 all;
	struct S_SEG_1_S_SEG_2_S_SJW_S_PRESC_BITS 		 bit;
};

struct F_SEG_1_F_SEG_2_F_SJW_F_PRESC_BITS {			// bits   description
	uint32_t	F_SEG_1:5;			// 4:0   Bit Timing Segment 1 (fast speed)
	uint32_t	rsvd1:3;			// 7:5   reserved
	uint32_t	F_SEG_2:4;			// 11:8   Bit Timing Segment 2 (fast speed)
	uint32_t	rsvd2:4;			// 15:12   reserved
	uint32_t	F_SJW:4;			// 19:16   Synchronization Jump Width (fast speed)
	uint32_t	rsvd3:4;			// 23:20   reserved
	uint32_t	F_PRESC:8;			// 31:24   Prescaler (fast speed)
};

union F_SEG_1_F_SEG_2_F_SJW_F_PRESC_REG {
	uint32_t 		 all;
	struct F_SEG_1_F_SEG_2_F_SJW_F_PRESC_BITS 		 bit;
};

struct EALCAP_TDC_RECNT_TECNT_BITS {			// bits   description
	uint32_t	ALC:5;			// 4:0   Arbitration Lost Capture (bit position in the frame 
	uint32_t	KOER:3;			// 7:5   Kind Of ERror (Error code)
	uint32_t	SSPOFF:7;			// 14:8   Secondary Sample Point OFFset
	uint32_t	TDCEN:1;			// 15:15   Transmitter Delay Compensation ENable
	uint32_t	TECNT:8;			// 23:16   Transmit Error CouNT (number of errors during transmission) TECNT is incremented and decremented as defined
	uint32_t	RECNT:8;			// 31:24   Receive Error CouNT (number of errors during reception)
};

union EALCAP_TDC_RECNT_TECNT_REG {
	uint32_t 		 all;
	struct EALCAP_TDC_RECNT_TECNT_BITS 		 bit;
};

struct ACFCTRL_TIMECFG_ACF_EN_0_ACF_EN_1_BITS {			// bits   description
	uint32_t	ACFADR:4;			// 3:0   acceptance filter address
	uint32_t	rsvd1:1;			// 4:4   reserved
	uint32_t	SELMASK:1;			// 5:5   SELect acceptance MASK
	uint32_t	rsvd2:2;			// 7:6   reserved
	uint32_t	TIMEEN:1;			// 8:8   TIME-stamping ENable
	uint32_t	TIMEPOS:1;			// 9:9   TIME-stamping POSition
	uint32_t	rsvd3:6;			// 15:10   reserved
	uint32_t	AE_0:1;			// 16:16   Acceptance filter Enable
	uint32_t	AE_1:1;			// 17:17   Acceptance filter Enable
	uint32_t	AE_2:1;			// 18:18   Acceptance filter Enable
	uint32_t	AE_3:1;			// 19:19   Acceptance filter Enable
	uint32_t	AE_4:1;			// 20:20   Acceptance filter Enable
	uint32_t	AE_5:1;			// 21:21   Acceptance filter Enable
	uint32_t	AE_6:1;			// 22:22   Acceptance filter Enable
	uint32_t	AE_7:1;			// 23:23   Acceptance filter Enable
	uint32_t	AE_8:1;			// 24:24   Acceptance filter Enable
	uint32_t	AE_9:1;			// 25:25   Acceptance filter Enable
	uint32_t	AE_10:1;			// 26:26   Acceptance filter Enable
	uint32_t	AE_11:1;			// 27:27   Acceptance filter Enable
	uint32_t	AE_12:1;			// 28:28   Acceptance filter Enable
	uint32_t	AE_13:1;			// 29:29   Acceptance filter Enable
	uint32_t	AE_14:1;			// 30:30   Acceptance filter Enable
	uint32_t	AE_15:1;			// 31:31   Acceptance filter Enable
};

union ACFCTRL_TIMECFG_ACF_EN_0_ACF_EN_1_REG {
	uint32_t 		 all;
	struct ACFCTRL_TIMECFG_ACF_EN_0_ACF_EN_1_BITS 		 bit;
};

struct ACF_BITS {			// bits   description
	uint32_t	ACODE_X_AMASK_X:29;			// 28:0   Acceptance MASK
	uint32_t	AIDE:1;			// 29:29   Acceptance mask IDE bit value
	uint32_t	AIDEE:1;			// 30:30   Acceptance mask IDE bit check enable
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union ACF_REG {
	uint32_t 		 all;
	struct ACF_BITS 		 bit;
};

struct VER_0_VER_1_TBSLOT_TTCFG_BITS {			// bits   description
	uint32_t	CAN_VERSION:16;			// 15:0   Version of CAN-CTRL, given as decimal value. VER_1 holds the major version and
	uint32_t	TBPTR:6;			// 21:16   Pointer to a TB message slot.
	uint32_t	TBF:1;			// 22:22   set TB slot to "Filled"
	uint32_t	TBE:1;			// 23:23   set TB slot to "Empty"
	uint32_t	TTEN:1;			// 24:24   Time Trigger Enable
	uint32_t	T_PRESC:2;			// 26:25   TTCAN Timer PRESCaler
	uint32_t	TTIF:1;			// 27:27   Time Trigger Interrupt Flag
	uint32_t	TTIE:1;			// 28:28   Time Trigger Interrupt Enable
	uint32_t	TEIF:1;			// 29:29   Trigger Error Interrupt Flag
	uint32_t	WTIF:1;			// 30:30   Watch Trigger Interrupt Flag
	uint32_t	WTIE:1;			// 31:31   Watch Trigger Interrupt Enable
};

union VER_0_VER_1_TBSLOT_TTCFG_REG {
	uint32_t 		 all;
	struct VER_0_VER_1_TBSLOT_TTCFG_BITS 		 bit;
};

struct REF_MSG_0_REF_MSG_1_REF_MSG_2_REF_MSG_3_BITS {			// bits   description
	uint32_t	REF_ID:29;			// 28:0   REFerence message IDentifier.
	uint32_t	rsvd1:2;			// 30:29   reserved
	uint32_t	REF_IDE:1;			// 31:31   REFerence message IDE bit.
};

union REF_MSG_0_REF_MSG_1_REF_MSG_2_REF_MSG_3_REG {
	uint32_t 		 all;
	struct REF_MSG_0_REF_MSG_1_REF_MSG_2_REF_MSG_3_BITS 		 bit;
};

struct TRIG_CFG_0_TRIG_CFG_1_TT_TRIG_0_TT_TRIG_1_BITS {			// bits   description
	uint32_t	TTPTR:6;			// 5:0   Transmit Trigger TB slot Pointer
	uint32_t	rsvd1:2;			// 7:6   reserved
	uint32_t	TTYPE:3;			// 10:8   Trigger Type
	uint32_t	rsvd2:1;			// 11:11   reserved
	uint32_t	TEW:4;			// 15:12   Transmit Enable Window
	uint32_t	TT_TRIG:16;			// 31:16   Trigger Time
};

union TRIG_CFG_0_TRIG_CFG_1_TT_TRIG_0_TT_TRIG_1_REG {
	uint32_t 		 all;
	struct TRIG_CFG_0_TRIG_CFG_1_TT_TRIG_0_TT_TRIG_1_BITS 		 bit;
};

struct TT_WTRIG_0_TT_WTRIG_1_MEM_PROT_MEM_STAT_BITS {			// bits   description
	uint32_t	TT_WTRIG:16;			// 15:0   Watch Trigger Time
	uint32_t	MPEN:1;			// 16:16   Memory Protection Enable
	uint32_t	MDWIE:1;			// 17:17   Memory: Data Warning Interrupt Enable
	uint32_t	MDWIF:1;			// 18:18   Memory: Data Warning Interrupt Flag
	uint32_t	MDEIF:1;			// 19:19   Memory: Data Error Interrupt Flag
	uint32_t	MAEIF:1;			// 20:20   Memory: Address Error Interrupt Flag
	uint32_t	rsvd1:3;			// 23:21   reserved
	uint32_t	ACFA:1;			// 24:24   Acceptance Filter Accept
	uint32_t	TXS:1;			// 25:25   Transmission Stop
	uint32_t	TXB:1;			// 26:26   Transmission Block
	uint32_t	HELOC:2;			// 28:27   Host side memory error location
	uint32_t	rsvd2:3;			// 31:29   reserved
};

union TT_WTRIG_0_TT_WTRIG_1_MEM_PROT_MEM_STAT_REG {
	uint32_t 		 all;
	struct TT_WTRIG_0_TT_WTRIG_1_MEM_PROT_MEM_STAT_BITS 		 bit;
};

struct MEM_ES_0_MEM_ES_1_MEM_ES_2_MEM_ES_3_BITS {			// bits   description
	uint32_t	MEBP1:6;			// 5:0   Memory Error: Bit Position 1
	uint32_t	ME1EE:1;			// 6:6   Memory Error: 1st Error Enable
	uint32_t	MEAEE:1;			// 7:7   Memory Error: Address Error Enable
	uint32_t	MEBP2:6;			// 13:8   Memory Error: Bit Position 2
	uint32_t	ME2EE:1;			// 14:14   Memory Error: 2nd Error Enable
	uint32_t	rsvd1:1;			// 15:15   reserved
	uint32_t	MEEEC:4;			// 19:16   Memory Error: Error Enable Counter
	uint32_t	MENEC:4;			// 23:20   Memory Error: No Error Counter
	uint32_t	MEL:2;			// 25:24   Memory Error Location
	uint32_t	MES:1;			// 26:26   Memory Error Side
	uint32_t	rsvd2:5;			// 31:27   reserved
};

union MEM_ES_0_MEM_ES_1_MEM_ES_2_MEM_ES_3_REG {
	uint32_t 		 all;
	struct MEM_ES_0_MEM_ES_1_MEM_ES_2_MEM_ES_3_BITS 		 bit;
};

struct SCFG_BITS {			// bits   description
	uint32_t	XMREN:1;			// 0:0   DMR / TMR enable
	uint32_t	SEIF:1;			// 1:1   DMR / TMR: Safety Error Interrupt Flag
	uint32_t	SWIE:1;			// 2:2   DMR / TMR: Safety Warning Interrupt Enable
	uint32_t	SWIF:1;			// 3:3   DMR / TMR: Safety warning interrupt flag
	uint32_t	FSTIM:3;			// 6:4   Fault Stimulation
	uint32_t	rsvd1:25;			// 31:7   reserved
};

union SCFG_REG {
	uint32_t 		 all;
	struct SCFG_BITS 		 bit;
};


// CAN Register Definitions:

struct CAN_REGS {
	union  RBUF0TO3_REG			RBUF0TO3;
	union  RBUF4TO7_REG			RBUF4TO7;
	union  RBUF8TO11_REG			RBUF8TO11;
	union  RBUF12TO15_REG			RBUF12TO15;
	union  RBUF16TO19_REG			RBUF16TO19;
	union  RBUF20TO23_REG			RBUF20TO23;
	union  RBUF24TO27_REG			RBUF24TO27;
	union  RBUF28TO31_REG			RBUF28TO31;
	union  RBUF32TO35_REG			RBUF32TO35;
	union  RBUF36TO39_REG			RBUF36TO39;
	union  RBUF40TO43_REG			RBUF40TO43;
	union  RBUF44TO47_REG			RBUF44TO47;
	union  RBUF48TO51_REG			RBUF48TO51;
	union  RBUF52TO55_REG			RBUF52TO55;
	union  RBUF56TO59_REG			RBUF56TO59;
	union  RBUF60TO63_REG			RBUF60TO63;
	union  RBUF64TO67_REG			RBUF64TO67;
	union  RBUF68TO71_REG			RBUF68TO71;
	union  RBUF72TO75_REG			RBUF72TO75;
	union  RBUF76TO79_REG			RBUF76TO79;
	union  TBUF0TO3_REG			TBUF0TO3;
	union  TBUF4TO7_REG			TBUF4TO7;
	union  TBUF8TO11_REG			TBUF8TO11;
	union  TBUF12TO15_REG			TBUF12TO15;
	union  TBUF16TO19_REG			TBUF16TO19;
	union  TBUF20TO23_REG			TBUF20TO23;
	union  TBUF24TO27_REG			TBUF24TO27;
	union  TBUF28TO31_REG			TBUF28TO31;
	union  TBUF32TO35_REG			TBUF32TO35;
	union  TBUF36TO39_REG			TBUF36TO39;
	union  TBUF40TO43_REG			TBUF40TO43;
	union  TBUF44TO47_REG			TBUF44TO47;
	union  TBUF48TO51_REG			TBUF48TO51;
	union  TBUF52TO55_REG			TBUF52TO55;
	union  TBUF56TO59_REG			TBUF56TO59;
	union  TBUF60TO63_REG			TBUF60TO63;
	union  TBUF64TO67_REG			TBUF64TO67;
	union  TBUF68TO71_REG			TBUF68TO71;
	union  TTS_L_REG			TTS_L;
	union  TTS_H_REG			TTS_H;
	union  CFG_STAT_TCMD_TCTRL_RCTRL_REG			CFG_STAT_TCMD_TCTRL_RCTRL;
	union  RTIE_RTIE_ERRINT_LIMIT_REG			RTIE_RTIE_ERRINT_LIMIT;
	union  S_SEG_1_S_SEG_2_S_SJW_S_PRESC_REG			S_SEG_1_S_SEG_2_S_SJW_S_PRESC;
	union  F_SEG_1_F_SEG_2_F_SJW_F_PRESC_REG			F_SEG_1_F_SEG_2_F_SJW_F_PRESC;
	union  EALCAP_TDC_RECNT_TECNT_REG			EALCAP_TDC_RECNT_TECNT;
	union  ACFCTRL_TIMECFG_ACF_EN_0_ACF_EN_1_REG			ACFCTRL_TIMECFG_ACF_EN_0_ACF_EN_1;
	union  ACF_REG			ACF;
	union  VER_0_VER_1_TBSLOT_TTCFG_REG			VER_0_VER_1_TBSLOT_TTCFG;
	union  REF_MSG_0_REF_MSG_1_REF_MSG_2_REF_MSG_3_REG			REF_MSG_0_REF_MSG_1_REF_MSG_2_REF_MSG_3;
	union  TRIG_CFG_0_TRIG_CFG_1_TT_TRIG_0_TT_TRIG_1_REG			TRIG_CFG_0_TRIG_CFG_1_TT_TRIG_0_TT_TRIG_1;
	union  TT_WTRIG_0_TT_WTRIG_1_MEM_PROT_MEM_STAT_REG			TT_WTRIG_0_TT_WTRIG_1_MEM_PROT_MEM_STAT;
	union  MEM_ES_0_MEM_ES_1_MEM_ES_2_MEM_ES_3_REG			MEM_ES_0_MEM_ES_1_MEM_ES_2_MEM_ES_3;
	union  SCFG_REG			SCFG;
};

//structure define for CAN buffers only
struct CAN_BUF_REGS {
	union  RBUF0TO3_REG			RBUF0TO3;
	union  RBUF4TO7_REG			RBUF4TO7;
	union  RBUF8TO11_REG			RBUF8TO11;
	union  RBUF12TO15_REG			RBUF12TO15;
	union  RBUF16TO19_REG			RBUF16TO19;
	union  RBUF20TO23_REG			RBUF20TO23;
	union  RBUF24TO27_REG			RBUF24TO27;
	union  RBUF28TO31_REG			RBUF28TO31;
	union  RBUF32TO35_REG			RBUF32TO35;
	union  RBUF36TO39_REG			RBUF36TO39;
	union  RBUF40TO43_REG			RBUF40TO43;
	union  RBUF44TO47_REG			RBUF44TO47;
	union  RBUF48TO51_REG			RBUF48TO51;
	union  RBUF52TO55_REG			RBUF52TO55;
	union  RBUF56TO59_REG			RBUF56TO59;
	union  RBUF60TO63_REG			RBUF60TO63;
	union  RBUF64TO67_REG			RBUF64TO67;
	union  RBUF68TO71_REG			RBUF68TO71;
	union  RBUF72TO75_REG			RBUF72TO75;
	union  RBUF76TO79_REG			RBUF76TO79;
	union  TBUF0TO3_REG			TBUF0TO3;
	union  TBUF4TO7_REG			TBUF4TO7;
	union  TBUF8TO11_REG			TBUF8TO11;
	union  TBUF12TO15_REG			TBUF12TO15;
	union  TBUF16TO19_REG			TBUF16TO19;
	union  TBUF20TO23_REG			TBUF20TO23;
	union  TBUF24TO27_REG			TBUF24TO27;
	union  TBUF28TO31_REG			TBUF28TO31;
	union  TBUF32TO35_REG			TBUF32TO35;
	union  TBUF36TO39_REG			TBUF36TO39;
	union  TBUF40TO43_REG			TBUF40TO43;
	union  TBUF44TO47_REG			TBUF44TO47;
	union  TBUF48TO51_REG			TBUF48TO51;
	union  TBUF52TO55_REG			TBUF52TO55;
	union  TBUF56TO59_REG			TBUF56TO59;
	union  TBUF60TO63_REG			TBUF60TO63;
	union  TBUF64TO67_REG			TBUF64TO67;
	union  TBUF68TO71_REG			TBUF68TO71;
	union  TTS_L_REG			TTS_L;
	union  TTS_H_REG			TTS_H;
};

/*
	union  CFG_STAT_TCMD_TCTRL_RCTRL_REG			CFG_STAT_TCMD_TCTRL_RCTRL;
	union  RTIE_RTIE_ERRINT_LIMIT_REG			RTIE_RTIE_ERRINT_LIMIT;
	union  S_SEG_1_S_SEG_2_S_SJW_S_PRESC_REG			S_SEG_1_S_SEG_2_S_SJW_S_PRESC;
	union  F_SEG_1_F_SEG_2_F_SJW_F_PRESC_REG			F_SEG_1_F_SEG_2_F_SJW_F_PRESC;
	union  EALCAP_TDC_RECNT_TECNT_REG			EALCAP_TDC_RECNT_TECNT;
	union  ACFCTRL_TIMECFG_ACF_EN_0_ACF_EN_1_REG			ACFCTRL_TIMECFG_ACF_EN_0_ACF_EN_1;
	union  ACF_REG			ACF;
	union  VER_0_VER_1_TBSLOT_TTCFG_REG			VER_0_VER_1_TBSLOT_TTCFG;
	union  REF_MSG_0_REF_MSG_1_REF_MSG_2_REF_MSG_3_REG			REF_MSG_0_REF_MSG_1_REF_MSG_2_REF_MSG_3;
	union  TRIG_CFG_0_TRIG_CFG_1_TT_TRIG_0_TT_TRIG_1_REG			TRIG_CFG_0_TRIG_CFG_1_TT_TRIG_0_TT_TRIG_1;
	union  TT_WTRIG_0_TT_WTRIG_1_MEM_PROT_MEM_STAT_REG			TT_WTRIG_0_TT_WTRIG_1_MEM_PROT_MEM_STAT;
	union  MEM_ES_0_MEM_ES_1_MEM_ES_2_MEM_ES_3_REG			MEM_ES_0_MEM_ES_1_MEM_ES_2_MEM_ES_3;
	union  SCFG_REG			SCFG;

 */


//*****************************************************************************
//
//! The following are defines for HW CAN based on CAN Frame domain registers.
//
//*****************************************************************************
//!
//! CAN Message RAM ID Register bit definitions  (x: 1~2)
//!
struct CAN_MSGx_ID_BITS {
    // Message Identifier
    // ID[28:0] 29-bit Identifier ("Extended Frame")
    // ID[11:0] 11-bit Identifier ("Standard Frame")
    uint32_t ID:29;         //28:0
    uint32_t rsvd1:2;       //30:29

    // 1.ESI: Error State Indicator
    // This is a read-only status bit for RBUF and is not available in TBUF. The protocol machine
    // automatically embeds the correct value of ESI into transmitted frames. ESI is only included
    // in CAN FD frames and does not exist in CAN 2.0 frames.
    // 0: CAN node is error active
    // 1: CAN node is error passive
    // ESI in RBUF is always low for CAN 2.0 frames. The error state for transmission is shown 
    // with bit EPASS in register ERRINT.
    // 2.TTSEN: Transmit Time-Stamp ENable
    // For CiA 603 time-stamping the acquisition of a transmit time stamp TTS can be selected in 
    // the TBUF:
    // 0: no acquisition of a transmit time stamp for this frame
    // 1: TTS update enabled    
    uint32_t ESI_TTSEN:1;         //31
};

//!
//! CAN Message RAM ID Register  (x: 0~31)
//!
union CAN_MSGx_ID_REG{
    uint32_t                       all;
    struct CAN_MSGx_ID_BITS        bit;
};

//!
//! CAN Message RAM Ctrl Register bit definitions  (x: 1~2)
//!
struct CAN_MSGx_CTRL_BITS {
    // Data length code
    // 0-8: Data frame has 0-8 data bytes, both for CAN2.0 and CANFD.
    // 9-15: Data frame has 8 data bytes, only for CAN2.0.
    // 9: Data frame has 12 data bytes, only for CANFD.
    // 10: Data frame has 16 data bytes, only for CANFD.
    // 11: Data frame has 20 data bytes, only for CANFD.
    // 12: Data frame has 24 data bytes, only for CANFD.
    // 13: Data frame has 32 data bytes, only for CANFD.
    // 14: Data frame has 48 data bytes, only for CANFD.
    // 15: Data frame has 64 data bytes, only for CANFD.    
    uint32_t DLC:4;         //3:0

    // Bit Rate Switch
    // 0: nominal / slow bit rate for the complete frame
    // 1: switch to data / fast bit rate for the data payload and the CRC
    // Only CAN FD frames can switch the bitrate. Therefore BRS is forced to 0 if FDF =0.    
    uint32_t BRS:1;         //4

    // CAN FD frame
    // 0: CAN 2.0 frame (up to 8 bytes payload)
    // 1: CAN FD frame (up to 64 bytes payload)
    uint32_t FDF:1;         //5

    // Remote Transmission Request
    // 0: data frame
    // 1: remote frame
    // Only CAN 2.0 frames can be remote frames. There is no remote frame for CAN FD. Therefore RTR 
    // is forced to 0 if FDF =1 in TBUF and RBUF. If a CAN FD frame is received with bit RRS=1, 
    // then this is ignored, a data payload is expected for reception instead and RTR in RBUF is 
    // overridden but the CRC of the frame is calculated with RRS=1.    
    uint32_t RTR:1;         //6   in HAL CAN, the fild name is @RmtEn

    
    // Extended Identifier
    // 0: The 11-bit ("standard") Identifier is used for this message object.
    // 1: The 29-bit ("extended") Identifier is used for this message object.    
    uint32_t IDE:1;         //7   in HAL CAN, the filed name is @xtd.       
    uint32_t rsvd1:4;       //11:8


    // Transmit a frame.
    // Status bit TX in RBUF is set to 1 if the loop back mode (Chapter 3.9.10.4) is activated and 
    // the core has received its own transmitted frame. This can be useful if LBME=1 and other nodes
    // in the network do also transmissions
    uint32_t TX:1;          //12

    // Kind Of ERror (Error code)
    // 0: no error
    // 1: BIT ERROR
    // 2: FORM ERROR
    // 3: STUFF ERROR
    // 4: ACKNOWLEDGEMENT ERROR
    // 5: CRC ERROR
    // 6: OTHER ERROR. dominant bits after own error flag, received active Error Flag too long,
    //    dominant bit during Passive-Error-Flag after ACK error).
    // 7: not used.
    // KOER is updated with each new error. Therefore it stays untouched when frames are successfully
    // transmitted or received.    
    uint32_t KOER:3;        //15:13
    
    // The time-stamp CYCLE_TIME will be stored in RBUF only in TTCAN mode.
    uint32_t CYCLE_TIME:16; //31:16    
};

//!
//! CAN Message RAM RX Ctrl Register  (x: 1~2)
//!
union CAN_MSGx_CTRL_REG{
    uint32_t                       all;
    struct CAN_MSGx_CTRL_BITS      bit;
};

//!
//! CAN Message RAM Data Register bit definitions  (x: 1~2)
//!
struct CAN_MSGx_DATA_BITS {

    // Data Byte 0
    uint32_t Data_0:8;      //7:0

    // Data Byte 1
    uint32_t Data_1:8;      //15:8
    
    // Data Byte 2
    uint32_t Data_2:8;      //23:16

    // Data Byte 3
    uint32_t Data_3:8;      //31:24   
};

//!
//! CAN Message RAM Data Register  (x: 0~31)
//!
union CAN_MSGx_DATA_REG{
    uint32_t                       all;
    struct CAN_MSGx_DATA_BITS      bit;
};

//!
//!
//! CAN Message RTS Register bit definitions  (x: 1~2)
struct CAN_MSGx_RTS_BITS {

    // Data Byte 0
    uint32_t RTS:32;        //31: 0
};

//!
//! CAN Message RTS Register  (x: 0~31)
//!
union CAN_MSGx_RTS_REG{
    uint32_t                       all;
    struct CAN_MSGx_RTS_BITS       bit;
};

//!
//!
//! CAN Message TTS Register bit definitions  
struct CAN_MSG_TTS_BITS {

    // Transmission Time Stamp
    // TTS holds the time stamp of the last transmitted frame for CiA 603 time stamping. Every new 
    // frame overwrites TTS if TTSEN=1. Depending on a generic parameter (Chapter 3.2) the time-stamp
    // can be 32 or 64 wide. Unused bits are forced to 0. The TTS is intended to be used by the time
    // master to acquire the time-stamp of the SYNC message.
    uint32_t TTS:32;        //31: 0
};

//!
//! CAN Message TTS Register  (x: 0~31)
//!
union CAN_MSGx_TTS_REG{
    uint32_t                       all;
    struct CAN_MSG_TTS_BITS        bit;
};


//*****************************************************************************
//
//! The following are defines for CAN_based on DCAN Control domain registers.
//
//*****************************************************************************

//!
//! CAN Control Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!  
//! CFG_STAT Reg: RESET, LBME, LBMI, TPSS, TSSS, RACTIVE, TACTIVE, BUSOFF
//! TCMD Reg: TBSEL, LOM, STBY, TPE, TPA, TSONE, TSALL, TSA
//! TCTRL Reg: FD_ISO, TSNEXT, TSMODE, TTTBM, TSSTAT
//! RCTRL Reg: SACK, ROM, ROV, RREL, RBALL, RSTAT
//!
struct CAN_CTRL_BITS {
    // Bus Off 
    // 1: The controller status is "bus off".
    // 0: The controller status is "bus on".
    // Writing a 1 to BUSOFF will reset TECNT and RECNT. This should be done only for debugging.
    uint32_t BUSOFF:1;      //0


    //Transmission ACTIVE (Transmit Status bit)
    // 1: The controller is currently transmitting a frame.
    // 0: No transmit activity.  
    uint32_t TACTIVE:1;     //1
    
    // Reception ACTIVE (Receive Status bit)
    // 1: The controller is currently receiving a frame.
    // 0:  No receive activity.    
    uint32_t RACTIVE:1;     //2

    // Transmission Secondary Single Shot mode for STB 
    // 0:  Disabled
    // 1:   Enabled    
    uint32_t TSSS:1;        //3
    
    // Transmission Primary Single Shot mode for PTB 
    // 0: Disabled
    // 1: Enabled    
    uint32_t TPSS:1;        //4
    
    // Loop Back Mode, Internal 
    // 0: Disabled
    // 1: Enabled
    //LBMI should not be enabled while a transmission is active.
    uint32_t LBMI:1;        //5
    
    // Loop Back Mode, External 
    // 0: Disabled
    // 1: Enabled
    // LBME should not be enabled while a transmission is active.
    uint32_t LBME:1;        //6
    
    // RESET request bit
    // 1: The host controller performs a local reset of CAN-CTRL.
    // 0: no local reset of CAN-CTRL
    // The some register (e.g for node configuration) can only be modified if RESET=1. Bit RESET forces
    // several components to a reset state.    
    uint32_t RESET:1;       //7

    // Transmit Secondary Abort
    // 1: Aborts a transmission from STB which has been requested but not started yet. For a TSONE 
    //    transmission, only one frame is aborted while for a TSALL Transmission, all frames are aborted.
    //    One or all message slots will be released which updates TSSTAT. All aborted messages are lost 
    //    because they are not accessible any more. If in priority mode a TSONE transmission is aborted, 
    //    then it is not clear which frame will be aborted if new frames are written to the STB meanwhile.
    // 0: no abort
    // The bit has to be set by the host controller and will be reset by CAN-CTRL. Setting TSA, automatically
    // de-asserts TSONE or TSALL respectively. The host controller can set TSA to 1 but can not reset it to 0.
    // The bit will be reset to the hardware reset value if RESET=1. TSA should not be set simultaneously 
    // with TSONE or TSALL.
    uint32_t TSA:1;         //8

    // Transmit Secondary ALL frames
    // 1: Transmission enable of all messages in the STB. The controller starts the transmission as soon 
    //    as the bus becomes vacant and no request of the PTB (bit TPE) is pending.
    // 0: No transmission for the STB. 
    // TSALL stays set until all messages have been transmitted successfully or they are aborted using TSA.
    // The host controller can set TSALL to 1 but can not reset it to 0. This would only be possible 
    // using TSA and aborting the messages. The bit will be reset to the hardware reset value if RESET=1, 
    // STBY=1, (LOM=1 and LBME=0) or (TTEN=1 and TTTBM=1). If during a transmission the STB is loaded with
    // a new frame then the new frame will be transmitted too. In other words: a transmission initiated by
    // TSALL is finished when the STB becomes empty.    
    uint32_t TSALL:1;       //9

    // Transmit Secondary ONE frame
    // 1: Transmission enable of one in the STB. In FIFO mode this is the oldest message and in priority 
    //    mode this is the one with the highest priority. TSONE in priority mode is difficult to handle, 
    //    because it is not always clear which message will be transmitted if new messages are written 
    //    to the STB meanwhile. The controller starts the transmission as soon as the bus becomes vacant 
    //    and no request of the PTB (bit TPE) is pending.
    // 0:  No transmission for the STB.
    // TSONE stays set until the message has been transmitted successfully or it is aborted using TSA.
    // The host controller can set TSONE to 1 but can not reset it to 0. This would only be possible using
    // TSA and aborting the message. The bit will be reset to the hardware reset value if RESET=1, STBY=1, 
    // (LOM=1 and LBME=0) or (TTEN=1 and TTTBM=1).    
    uint32_t TSONE:1;       //10
    
    // Transmit Primary Abort
    // 1: Aborts a transmission from PTB which has been requested by TPE=1 but not started yet. (The data 
    //    bytes of the message remains in the PTB.)
    // 0: no abort
    // The bit has to be set by the host controller and will be reset by CAN-CTRL. Setting TPA automatically
    // de-asserts TPE. The host controller can set TPA to 1 but can not reset it to 0. During the short time 
    // while the CAN-CTRL core resets the bit, it cannot be set by the host. The bit will be reset to the 
    // hardware reset value if RESET=1 or (TTEN=1 and TTTBM=1). TPA should not be set simultaneously with TPE.
    uint32_t TPA:1;         //11
    
    // Transmit Primary Enable 
    // 1: Transmission enable for the message in the high-priority PTB
    // 0: No transmission for the PTB
    // If TPE is set, the message from the PTB will be transmitted at the next possible transmit position.
    // A started transmission from the STB will be completed before, but pending new messages are delayed
    // until the PTB message has been transmitted. TPE stays set until the message has been transmitted 
    // successfully or it is aborted using TPA.The host controller can set TPE to 1 but can not reset it 
    // to 0. This would only be possible using TPA and aborting the message. The bit will be reset to the
    // hardware reset value if RESET=1, STBY=1, (LOM=1 and LBME=0) or (TTEN=1 and TTTBM=1).    
    uint32_t TPE:1;         //12
    
    // Transceiver Standby Mode
    // 0: Disabled
    // 1: Enabled
    // This register bit is connected to the output signal stby which can be used to control a standby 
    // mode of a transceiver.
    // STBY cannot be set to 1 if TPE=1, TSONE=1 or TSALL=1. If the host sets STBY to 0 then the host 
    // needs to wait for the time required by the transceiver to start up before the host requests a 
    // new transmission.
    uint32_t STBY:1;        //13
    
    // Listen Only Mode 
    // 0: Disabled
    // 1: Enabled
    // LOM cannot be set if TPE, TSONE or TSALL is set. No transmission can be started if LOM is enabled
    // and LBME is disabled.
    // LOM=1 and LBME=0 disables all transmissions.
    // LOM=1 and LBME=1 disables the ACK for received frames and error frames, but enables the transmission 
    // of own frames
    uint32_t LOM:1;         //14
    
    // Transmit Buffer Select
    // Selects the transmit buffer to be loaded with a message. Use the TBUF registers for access. TBSEL
    // needs to be stable all the time the TBUF registers are written and when TSNEXT is set.
    // 0: PTB (high-priority buffer)
    // 1: STB
    // The bit will be reset to the hardware reset value if (TTEN=1 and TTTBM=1).      
    uint32_t TBSEL:1;       //15

    // Transmission Secondary STATus bits
    // If TTEN=0 or TTTBM=0:
    // 0: STB is empty
    // 1: STB is less than or equal to half full
    // 2: STB is more than half full
    // 3: STB is full
    // If the STB is disabled using STB_DISABLE, then TSSTAT=00.
    // If TTEN=1 and TTTBM=1:
    // 0: PTB and STB are empty
    // 1: PTB and STB are not empty and not full
    // 3: PTB and STB are full    
    uint32_t TSSTAT:2;      //17:16    
    uint32_t rsvd2:2;       //19:18

    // TTCAN Transmit Buffer Mode
    // If TTEN=0 then TTTBM is ignored, otherwise the following is valid:
    // 0: separate PTB and STB, behavior defined by TSMODE
    // 1: full TTCAN support: buffer slots selectable by TBPTR and TTPTR
    // For event-driven CAN communication (TTEN=0), the system provides PTB and STB and the behavior of 
    // the STB is defined by TSMODE. Then TTTBM is ignored. For time-triggered CAN communication (TTEN=1)
    // with full support of all features including time-triggered transmissions, TTTBM=1 needs to be chosen. 
    // Then the all TB slots are addressable using TTPTR and TBPTR. For time-triggered CAN communication 
    // (TTEN=1) with only support of reception timestamps, TTTBM=0 can be chosen. Then the transmit buffer
    // acts as in event-driven mode and the behavior can be selected by TSMODE. TTTBM shall be switched 
    // only if the TBUF is empty.    
    uint32_t TTTBM:1;       //20

    // Transmit buffer Secondary operation MODE
    // 0: FIFO mode
    // 1: priority decision mode
    // In FIFO mode frames are transmitted in the order in that they are written into the STB. In priority 
    // decision mode the frame with the highest priority in the STB is automatically transmitted first. The 
    // ID of a frame is used for the priority decision. A lower ID means a higher priority of a frame. A 
    // frame in the PTB has always the highest priority regardless of the ID. TSMODE shall be switched only
    // if the STB if empty.    
    uint32_t TSMODE:1;      //21
    
    // Transmit buffer Secondary NEXT
    // 0: no action
    // 1: STB slot filled, select next slot.
    // After all frame bytes are written to the TBUF registers, the host controller has to set TSNEXT to 
    // signal that this slot has been filled. Then the CAN-CTRL core connects the TBUF registers to the 
    // next slot. Once a slot is marked as filled a transmission can be started using TSONE or TSALL.
    // It is possible to set TSNEXT and TSONE or TSALL together in one write access. TSNEXT has to be set
    // by the host controller and is automatically reset by the CAN-CTRL core immediately after it was set.
    // Setting TSNEXT is meaningless if TBSEL=0. In this case TSNEXT is ignored and automatically cleared.
    // It does not do any harm. If all slots of the STB are filled, TSNEXT stays set until a slot becomes 
    // TSNEXT has no meaning in TTCAN mode and is fixed to 0.
    uint32_t TSNEXT:1;      //22
    
    // CAN FD ISO mode
    // 0: Bosch CAN FD (non-ISO) mode
    // 1: ISO CAN FD mode (ISO 11898-1:2015)
    // ISO CAN FD mode has a different CRC initialization value and an additional stuff bit count. Both 
    // modes are incompatible and must not be mixed in one CAN network. This bit has no impact to CAN 2.0B.
    // This bit is only writeable if RESET=1   
    uint32_t FDISO:1;       //23

    // Receive buffer STATus 
    // 0: empty
    // 1: empty and almost full (AFWL)
    // 2: almost full (programmable threshold by AFWL) but not full and no overflow
    // 3: full (stays set in case of overflow - for overflow signaling see ROV)    
    uint32_t RSTAT:2;       //25:24 
    uint32_t rsvd1:1;       //26
    
    // Receive Buffer stores ALL data frames
    // 0: normal operation 
    // 1: RB stores correct data frames as well as data frames with error
    uint32_t RBALL:1;       //27

    // Receive buffer RELease
    // The host controller has read the actual RB slot and releases it. Afterwards the CAN-CTRL core 
    // points to the next RB slot. RSTAT gets updated.
    // 1: Release: The host has read the RB.
    // 0: No release
    uint32_t RREL:1;        //28

    // Receive buffer OVerflow
    // 1: Overflow. At least one message is lost.
    // 0: No Overflow.
    // ROV is cleared by setting RREL=1.
    uint32_t ROV:1;         //29
    
    // Receive buffer Overflow Mode
    // In case of a full RBUF when a new message is received, then ROM selects the following:
    // 1: The new message will not be stored.
    // 0: The oldest message will be overwritten.
    uint32_t ROM:1;         //30

    // Self-ACKnowledge
    // 0: no self-ACK 
    // 1: self-ACK when LBME=1    
    uint32_t SACK:1;        //31
};

//!
//! CAN Control Register
//!
union CAN_CTRL_REG{
    uint32_t                    all;
    struct CAN_CTRL_BITS        bit;
};

//!
//! CAN INT Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!  
//! RTIE Reg: RIE, ROIE, RFIE, RAFIE, TPIE, TSIE, EIE, TSFF
//! RTIF Reg: RIF, ROIF, RFIF, RAFIF, TPIF, TSIF, EIF, AIF
//! ERRINT Reg: EWARN, EPASS, EPIE, EPIF, ALIE, ALIF, BEIE, BEIF
//! LIMIT Reg: AFWL, EWL
//!
struct CAN_INT_BITS {
    // If TTEN=0 or TTTBM=0: Transmit Secondary buffer Full Flag
    // 1: The STB is filled with the maximal number of messages.
    // 0: The STB is not filled with the maximal number of messages
    // If the STB is disabled using STB_DISABLE, then TSFF=0.
    // If TTEN=1 and TTTBM=1: Transmit buffer Slot Full Flag
    // 1: The buffer slot selected by TBPTR is filled.
    // 0: The buffer slot selected by TBPTR is empty.
    uint32_t TSFF:1;        //0

    // Error Interrupt Enable
    // 0: Disabled
    // 1: Enabled    
    uint32_t EIE:1;         //1

    // Transmission Secondary Interrupt Enable
    // 0: Disabled
    // 1: Enabled
    uint32_t TSIE:1;        //2

    // RB Almost Full Interrupt Enable
    // 0: Disabled,
    // 1: Enabled    
    uint32_t TPIE:1;        //3
    
    // RB Almost Full Interrupt Enable
    // 0: Disabled
    // 1: Enabled
    uint32_t RAFIE:1;       //4

    // RB Full Interrupt Enable
    // 0: Disabled
    // 1: Enabled    
    uint32_t RFIE:1;        //5

    // RB Overrun Interrupt Enable
    // 0: Disabled
    // 1: Enabled    
    uint32_t ROIE:1;        //6

    // Receive Interrupt Enable
    // 0: Disabled
    // 1: Enabled    
    uint32_t RIE:1;         //7

    // Abort Interrupt Flag
    // 1: After setting TPA or TSA the appropriated message(s) have been aborted. It is recommended to
    //    not set both TPA and TSA simultaneously because both source AIF.
    // 0: No abort has been executed. The AIF does not have an associated enable register.
    uint32_t AIF:1;        //8

    // Error Interrupt Flag
    // 1: The border of the error warning limit has been crossed in either direction,
    //    or the BUSOFF bit has been changed in either direction.
    // 0: There has been no change.    
    uint32_t EIF:1;         //9
    
    // Transmission Secondary Interrupt Flag
    // 1: The requested transmission of the STB has been successfully completed.
    // 0:  No transmission of the STB has been completed successfully.
    // In TTCAN mode TSIF will signal all successful transmissions, regardless of storage location of 
    // the message.    
    uint32_t TSIF:1;        //10
    
    // Transmission Primary Interrupt Flag
    // 1: The requested transmission of the PTB has been successfully completed.
    // 0: No transmission of the PTB has been completed.
    // In TTCAN mode, TPIF will never be set. Then only TSIF is valid.    
    uint32_t TPIF:1;        //11

    // RB Almost Full Interrupt Flag
    // 1: number of filled RB slots >= AFWL_i
    // 0: number of filled RB slots < AFWL_i    
    uint32_t RAFIF:1;       //12
    
    // RB Full Interrupt Flag
    // 1: All RBs are full. If no RB will be released until the next valid message is received, the oldest
    //    message will be lost.
    // 0: The RB FIFO is not full.    
    uint32_t RFIF:1;        //13
    
    // RB Overrun Interrupt Flag
    // 1: At least one received message has been overwritten in the RB.
    // 0: No RB overwritten.
    // In case of an overrun both ROIF and RFIF will be set.    
    uint32_t ROIF:1;        //14

    // Receive Interrupt Flag
    // 1: Data or a remote frame has been received and is available in the receive buffer.
    // 0: No frame has been received.    
    uint32_t RIF:1;         //15

    // Bus Error Interrupt Flag
    uint32_t BEIF:1;        //16
    
    // Bus Error Interrupt Enable
    uint32_t BEIE:1;        //17

    // Arbitration Lost Interrupt Flag
    uint32_t ALIF:1;        //18

    // Arbitration Lost Interrupt Enable
    uint32_t ALIE:1;        //19
    
    // Error Passive Interrupt Flag. 
    // EPIF will be activated if the error status changes from error active to error passive or vice 
    // versa and if this interrupt is enabled.    
    uint32_t EPIF:1;        //20
    
    // Error Passive Interrupt Enable    
    uint32_t EPIE:1;        //21

    // Error Passive mode active
    // 0: not active (node is error active)
    // 1: active (node is error passive)    
    uint32_t EPASS:1;       //22

    // Error WARNing limit reached
    // 1: One of the error counters RECNT or TECNT is equal or bigger than EWL
    // 0: The values in both counters are less than EWL.    
    uint32_t EWARN:1;       //23

    // receive buffer Almost Full Warning Limit
    uint32_t EWL:4;         //27:24

    // Programmable Error Warning Limit = (EWL+1)*8. Possible Limit values: 8, 16, ...128.
    // The value of EWL controls EIF.
    // EWL needs to be transferred using CDC from host to CAN clock domain. During transfer EWL register
    // bits are write-locked for the host for a few clocks until CDC is complete.
    uint32_t AFWL:4;        //31:28
};

//!
//! CAN INT Register
//!
union CAN_INT_REG{
    uint32_t                    all;
    struct CAN_INT_BITS         bit;
};


//!
//! CAN Slow Timing Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! S_Seg_1 Reg: SEG1
//! S_Seg_2 Reg: SEG2
//! S_SJW Reg: SJW
//! S_PRESC: PRESC
//!
struct CAN_STIME_BITS {
    // Bit Timing Segment 1 (slow speed)
    // T(Seg1) = (Seg_1 + 2) X TQ 
    uint32_t SEG1:8;        //7:0

    // Bit Timing Segment 2 (slow speed)
    // T(Seg2) = (Seg_2 + 1) X TQ 
    uint32_t SEG2:7;        //14:8
    uint32_t rsvd2:1;       //15

    // Synchronization Jump Width (slow speed)
    // The Synchronization Jump Width T(SJW) = (SJW + 1) X TQ is the maximum time for shortening
    // or lengthening the Bit Time for resynchronization, where TQ is a time quanta.
    uint32_t SJW:7;         //22:16

    uint32_t rsvd1:1;       //23

    // Prescaler (slow speed)
    // The prescaler divides the system clock to get the time quanta clock tq_clk. Valid range PRESC
    // =[0x00, 0xff] results in divider values 1 to 256.
    uint32_t PRESC:8;       //31:24
};

//!
//! CAN S Timing Register
//!
union CAN_STIME_REG{
    uint32_t                    all;
    struct CAN_STIME_BITS        bit;
};


//!
//! CAN Fast Timing Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! F_Seg_1 Reg: SEG1
//! F_Seg_2 Reg: SEG2
//! F_SJW Reg: SJW
//! F_PRESC Reg: PRESC
//!
struct CAN_FTIME_BITS {
    // Bit Timing Segment 1 (fast speed)
    // T(Seg1) = (Seg1 + 2) X TQ.
    uint32_t SEG1:5;        //4:0  
    uint32_t rsvd3:3;       //7:5
    
    // Bit Timing Segment 2 (fast speed)
    // T(Seg2) = (Seg2 + 1) X TQ.  
    uint32_t SEG2:4;        //11:8
    uint32_t rsvd2:4;       //15:12

    // Synchronization Jump Width (fast speed)
    // The Synchronization Jump Width T(Sjw) = (SJW +1) X TQ is the maximum time for shortening 
    // or lengthening the Bit Time for resynchronization, where TQ is a time quanta.
    uint32_t SJW:4;         //19:16
    uint32_t rsvd1:4;       //23:20

    // Prescaler (fast speed)
    // The prescaler divides the system clock to get the time quanta clock tq_clk. Valid range PRESC
    // =[0x00, 0xff] results in divider values 1 to 256.
    uint32_t PRSEC:8;       //31:24
};

//!
//! CAN S Timing Register
//!
union CAN_FTIME_REG{
    uint32_t                    all;
    struct CAN_FTIME_BITS       bit;
};

//!
//! CAN CNT Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! EALCAP Reg: KOER, ALC
//! TDC Reg: TDCEN, SSPOFF
//! RECNT Reg: RECNT
//! TECNT Reg: TECNT
//!
struct CAN_CNT_BITS {

    // Arbitration Lost Capture (bit position in the frame where the arbitration has been lost)
    uint32_t ALC:5;         //4:0

    // Kind Of ERror (Error code)
    // 0: no error
    // 1: BIT ERROR
    // 2: FORM ERROR
    // 3: STUFF ERROR
    // 4: ACKNOWLEDGEMENT ERROR
    // 5: CRC ERROR
    // 6: OTHER ERROR
    // (dominant bits after own error flag, received active Error Flag too long, dominant bit during 
    // Passive-Error-Flag after ACK error) 111 - not used KOER is updated with each new error. 
    // Therefore it stays untouched when frames are successfully transmitted or received.
    uint32_t KOER:3;        //7:5
    
    // Secondary Sample Point OFFset
    // The transmitter delay plus SSPOFF defines the time of the secondary sample point for TDC.
    // SSPOFF is given as a number of TQ.    
    uint32_t SSPOFF:7;      //14:8
    
    // Transmitter Delay Compensation ENable
    // TDC will be activated during the data phase of a CAN FD frame if BRS is active if TDCEN=1.
    uint32_t TDCEN:1;       //15

    // Receive Error CouNT (number of errors during reception)
    // RECNT is incremented and decremented as defined in the CAN specification. RECNT does not overflow.
    // If TXB = 1, then the error counters are frozen.
    uint32_t RECNT:8;        //23:16

    // Transmit Error CouNT (number of errors during transmission)
    // TECNT is incremented and decremented as defined in the CAN specification. 
    // If TXB=1, then the error counters are frozen.
    uint32_t TECNT:8;       //31:24
};

//!
//! CAN S Timing Register
//!
union CAN_CNT_REG{
    uint32_t                    all;
    struct CAN_CNT_BITS         bit;
};

//!
//! CAN ACF Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! ACFCTRL Reg: SELMASK, ACFADR
//! TIMECFG Reg: TIMEPOS, TIMEEN
//! ACF_EN_0 Reg: AE7 ~ AE0
//! ACF_EN_1 Reg: AE15 ~ AE8
//!
struct CAN_ACFCTRL_BITS {

    // Acceptance filter address
    // ACFADR points to a specific acceptance filter. The selected filter is accessible using the registers
    // ACF_x. Bit SELMASK selects between acceptance code and mask for the selected acceptance filter. 
    // A value of ACFADR>ACF_NUMBER-1 is meaningless and automatically treated as value ACF_NUMBER-1.
    uint32_t ACFADR:4;      //3:0
    uint32_t rsvd3:1;       //4
    
    // SELect acceptance MASK
    // 0: Registers ACF_x point to acceptance code
    // 1: Registers ACF_x point to acceptance mask.    
    uint32_t SELMASK:1;     //5
    uint32_t rsvd2:2;       //7:6

    // TIME-stamping ENable
    // 0: disabled
    // 1: enabled
    uint32_t TIMEEN:1;      //8
    // TIME-stamping POSition
    // 0: SOF
    // 1: EOF (see Chapter 7)
    // TIMEPOS can only be changed if TIMEEN=0, but it is possible to modify TIMPOS with the same write 
    // access that sets TIMEEN=1.    
    uint32_t TIMEPOS:1;     //9
    uint32_t rsvd1:6;       //15:10

    // Acceptance filter Enable (x: 0~15)
    // 1: acceptance filter enabled
    // 0: acceptance filter disable
    // Each acceptance filter (AMASK / ACODE) can be individually enabled or disabled. Only filter 
    // number 0 is enabled by default after hardware reset. Disabled filters reject a message. Only 
    // enabled filters can accept a message if the appropriate AMASK / ACODE configuration matches.
    // To accept all messages one filter x has to be enabled by setting AE_x=1, AMASK_x=0xff and 
    // ACODE_x=0x00. This is the default configuration after hardware reset for filter x=0 while all
    // other filters are disabled.
    uint32_t AE0:1;         //16
    uint32_t AE1:1;         //17
    uint32_t AE2:1;         //18
    uint32_t AE3:1;         //19 
    uint32_t AE4:1;         //20
    uint32_t AE5:1;         //21
    uint32_t AE6:1;         //22
    uint32_t AE7:1;         //23

    uint32_t AE8:1;         //24
    uint32_t AE9:1;         //25
    uint32_t AE10:1;        //26
    uint32_t AE11:1;        //27
    uint32_t AE12:1;        //28
    uint32_t AE13:1;        //29
    uint32_t AE14:1;        //30
    uint32_t AE15:1;        //31
};

//!
//! CAN S Timing Register
//!
union CAN_ACFCTRL_REG{
    uint32_t                    all;
    struct CAN_ACFCTRL_BITS     bit;
};

//!
//! CAN ACF Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! ACF_0 Reg: ACODE_AMASK[7:0]
//! ACF_1 Reg: ACODE_AMASK[15:8]
//! ACF_2 Reg: ACODE AMASK[23:16]
//! ACF_3 Reg: AIDEE, AIDE, ACODE_AMASK[28:24]
//!
struct CAN_ACF_BITS {
    // case 1: Acceptance CODE
    // 1: ACC bit value to compare with ID bit of the received message
    // 0: ACC bit value to compare with ID bit of the received message
    // ACODE_x(10:0) will be used for extended frames.
    // ACODE_x(28:0) will be used for extended frames.
    // Only filter 0 is affected by the power-on reset. All other filters stay uninitialized.
    // case 2: Acceptance MASK
    // 1: acceptance check for these bits of receive identifier disabled
    // 0: acceptance check for these bits of receive identifier enable
    // AMASK_x(10:0) will be used for extended frames.
    // AMASK_x(28:0) will be used for extended frames.
    // Disabled bits result in accepting the message. Therefore the default configuration after 
    // reset for filter 0 accepts all messages. Only filter 0 is affected by the power-on reset. 
    // All other filters stay uninitialized.    
    uint32_t ACODE_MASK:29;     //28:0

    // Acceptance mask IDE bit value
    // If AIDEE=1 then:
    // 1: acceptance filter accepts only extended frames
    // 0: acceptance filter accepts only standard frames
    // Only filter 0 is affected by the power-on reset. All other filters stay uninitialized.    
    uint32_t AIDE:1;            //29
    
    // Acceptance mask IDE bit check enable
    // 1: acceptance filter accepts either standard or extended as defined by AIDE
    // 0: acceptance filter accepts both standard or extended frames
    // Only filter 0 is affected by the power-on reset. All other filters stay uninitialized.    
    uint32_t AIDEE:1;           //30
    uint32_t rsvd1:1;           //31
};

//!
//! CAN S Timing Register
//!
union CAN_ACF_REG{
    uint32_t                    all;
    struct CAN_ACF_BITS         bit;
};

//!
//! CAN TTB Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! VER0_1 Reg: VERSION[7:0] (VER_0)
//! VER1_1 Reg: VERSION[15:8] (VER_1)
//! TBSLOT Reg: TBE, TBF, TBPTR
//! TTCFG Reg: WTIE, WTIF, TEIF, TTIE, TTIF, T_PRESC, TTEN
//!
struct CAN_TTB_BITS {
    // Version of CAN-CTRL, given as decimal value. 
    // VER_1 holds the major version and 
    // VER_0 the minor version.
    // Example: version 5x16N00S00 is represented by VER_1=5 and VER_0=16.
    uint32_t VER_0:8;           //7:0
    uint32_t VER_1:8;           //15:8

    // Pointer to a TB message slot.
    // 0: Pointer to the PTB
    // others: Pointer to a slot in the STB
    // The message slot pointed to by TBPTR is readable / writable using the TBUF registers. Write 
    // access is only possible if TSFF=0. Setting TBF to 1 marks the selected slot as filled and 
    // setting TBE to 1 marks the selected slot as empty. 
    // TBSEL and TSNEXT are unused in TTCAN mode and have no meaning.
    // TBPTR can only point to buffer slots, that exist in the hardware. Unusable bits of TBPTR are
    // fixed to 0.
    // TBPTR is limited to the PTB and 63 STB slots. More slots cannot be used in TTCAN mode.
    // If TBPTR is too big and points to a slot that is not available, then TBF and TBE are reset 
    // automatically and no action takes place.    
    uint32_t TBPTR:6;           //21:16

    // set TB slot to "Filled"
    // 1: slot selected by TBPTR shall be marked as "filled"
    // 0: no action
    // TBF is automatically reset to 0 as soon as the slot is marked as filled and TSFF=1. If both 
    // TBF and TBE are set, then TBE wins.    
    uint32_t TBF:1;             //22
    
    // set TB slot to "Empty"
    // 1: slot selected by TBPTR shall be marked as "empty"
    // 0: no action
    // TBE is automatically reset to 0 as soon as the slot is marked as empty and TSFF=0. If a 
    // transmission from this slot is active, then TBE stays set as long as either the transmission
    // completes or after a transmission error or arbitration loss the transmission is not 
    // active any more. If both TBF and TBE are set, then TBE wins    
    uint32_t TBE:1;             //23

    // Time Trigger Enable
    // 1 - TTCAN enabled, timer is running
    // 0 - disabled    
    uint32_t TTEN:1;            //24

    // TTCAN Timer PRESCaler
    // 0:  1
    // 1:  2
    // 2:  4
    // 3:  8
    // The TTCAN time base is a CAN bittime defined by S_PRES, S_SEG_1 and S_SEG_2. With T_PRESC an
    // additional prescaling factor of 1, 2, 4 or 8 is defined. T_PRESC can only be modified if TTEN=0,
    // but it is possible to modify T_PRESC and set TTEN simultaneously with one write access.    
    uint32_t T_PRESC:2;         //26:25

    // Time Trigger Interrupt Flag
    // TTIF will be set if TTIE is set and the cycle time is equal to the trigger time TT_TRIG. Writing
    // an one to TTIF resets it. Writing a zero has no impact.TTIF will be set only once. If TT_TRIG 
    // gets not updated, then TTIF will be not set again in the next basic cycle.    
    uint32_t TTIF:1;            //27

    // Time Trigger Interrupt Enable
    // If TTIE is set, then TTIF will be set if the cycle time is equal to the trigger time TT_TRIG.    
    uint32_t TTIE:1;            //28

    // Trigger Error Interrupt Flag
    // The conditions when TEIF will be set, are defined in Chapter 6.4. There is no bit to enable or 
    // disable the handling of TEIF.    
    uint32_t TEIF:1;            //29

    // Watch Trigger Interrupt Flag
    // WTIF will be set if the cycle count reaches the limited defined by TT_WTRIG and WTIE is set.    
    uint32_t WTIF:1;            //30

    // Watch Trigger Interrupt Enable
    uint32_t WTIE:1;            //31
};

//!
//! CAN TTB Register
//!
union CAN_TTB_REG{
    uint32_t                     all;
    struct CAN_TTB_BITS          bit;
};

//!
//! CAN REF_NSG Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! REF_MSG_0 Reg: REF_ID[7:0]
//! REF_MSG_1 Reg: REF_ID[15:8]
//! REF_MSG_2 Reg: REF_ID[23:16]
//! REF_MSG_3 Reg: REF_IDE, REF_ID[28:24]
//!
struct CAN_REFMSG_BITS {

    // REFerence message IDentifier.
    // If REF_IDE is
    // 1: REF_ID(28:0) is valid (extended ID)
    // 0: REF_ID(10:0) is valid (standard ID)
    // REF_ID is used in TTCAN mode to detect a reference message. This holds for time slaves (reception) 
    // as well as for the time master (transmission). If the reference message is detected and there are
    // no errors, then the Sync_Mark of this frame will become the Ref_Mark.
    // REF_ID(2:0) is not tested and therefore the appropriate register bits are forced to 0. These bits
    // are used for up to 8 potential time masters. CAN-CTRL recognizes the reference message only by ID. 
    // The payload is not tested. Additional note: A time master will transmit a reference message in the
    // same way as a normal frame. REF_ID is intended for detection of a successful transmission of a 
    // reference message.
    uint32_t REF_ID:29;          //28:0    
    uint32_t rsvd1:1;           //30
    
    // REFerence message IDE bit.
    uint32_t REF_IDE:1;         //31
};

//!
//! CAN S Timing Register
//!
union CAN_REFMSG_REG{
    uint32_t                    all;
    struct CAN_REFMSG_BITS      bit;
};


//!
//! CAN TRIG Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! TRIG_CFG_0 Reg: TTPTR
//! TRIG_CFG_1 Reg: TEW, TTYPE
//! TT_TRIG_0 Reg: TT_TRIG[7:0]
//! TT_TRIG_1 Reg: TT_TRIG[15:8]
//!
struct CAN_TRIG_BITS {
    // Transmit Trigger TB slot Pointer
    // If TTPTR is too big and points to a slot that is not available, then TEIF is set and no new trigger
    // can be activated after a write access to TT_TRIG_1. If TTPTR points to an empty slot, then TEIF will
    // be set at the moment, when the trigger time is reached.
    uint32_t TTPTR:6;           //5:0    
    uint32_t rsvd2:2;           //7:6

    // Trigger Type
    // 0: Immediate Trigger for immediate transmission
    // 1: Time Trigger for receive triggers
    // 2: Single Shot Transmit Trigger for exclusive time windows
    // 3: Transmit Start Trigger for merged arbitrating time windows
    // 4; Transmit Stop Trigger for merged arbitrating time windows
    // others: no action
    // The time of the trigger is defined by TT_TRIG. TTPTR selects the TB slot for the transmit triggers.
    uint32_t TTYPE:3;           //10:8    
    uint32_t rsvd1:1;           //11

    // Transmit Enable Window
    // For a single shot transmit trigger there is a time of up to 16 ticks of the cycle time where the 
    // frame is allowed to start. TWE+1 defines the number of ticks. 
    // TEW=0 is a valid setting and shortens the transmit enable window to 1 tick.    
    uint32_t TEW:4;             //15:12

    // Trigger Time
    // TT_TRIG(15:0) defines the cycle time for a trigger. For a transmission trigger the earliest point
    // of transmission of the SOF of the appropriate frame will be TT_TRIG+1.
    uint32_t TT_TRIG:16;        //31:16
};

//!
//! CAN S Timing Register
//!
union CAN_TRIG_REG{
    uint32_t                    all;
    struct CAN_TRIG_BITS        bit;
};

//!
//! CAN WTRIG Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! TT_WTRIG_0 Reg: TT_WTRIG[7:0]
//! TI_WTRIG_1 Reg: TT_WTRIG[15:8]
//! MEM_PORT Reg: MAEIF, MDEIF, MDWIF, MDWIE, MPEN
//! MEM_STAT Reg: HELOC, TXB, TXS, ACFA
//!
struct CAN_WTRIG_BITS {

    // Watch Trigger Time
    // TT_WTRIG(15:0) defines the cycle time for a watch trigger. The initial watch trigger is the maximum
    // cycle time 0xffff. See Chapter 6.5 for more details.
    uint32_t TT_WTRIG:16;       //15:0

    // Memory Protection Enable
    // 0: disabled
    // 1: enabled
    // MPEN is only writable if RESET=1.
    // If synthesis parameter RAM_ECC=0 then this bit is always 0.
    uint32_t MPEN:1;            //16

    // Memory: Data Warning Interrupt Enable
    // 0: disabled
    // 1: enabled
    // If synthesis parameter RAM_ECC=0 then this bit is always 0.    
    uint32_t MDWIE:1;           //17

    // Memory: Data Warning Interrupt Flag
    // MDWIF will be set if MDWIE is set and memory protection has detected an error in the data which has
    // been automatically corrected. The system continues operation.    
    uint32_t MDWIF:1;           //18

    // Memory: Data Error Interrupt Flag
    // MDEIF will be set if memory protection has detected an error in the data which was not correctable    
    uint32_t MDEIF:1;           //19

    // Memory: Address Error Interrupt Flag
    // MAEIF will be set if memory protection has detected an error in the address. The error was not corrected.    
    uint32_t MAEIF:1;           //20    
    uint32_t rsvd2:3;           //23:21

    // Acceptance Filter Accept
    // 0: normal operation of ACF
    // 1: ACF disabled: all received frames are accepted
    // If MDEIF or MAEIF is set because of an error in the address range of the ACF, ACFA is set. Then acceptance
    // filtering is disabled and all frames will be accepted.
    // ACFA can be reset similar to an interrupt flag by writing a 1 to it. But because ACFA will be set while the
    // reception is still active, it is required to reset if later after the reception has been completed and e.g.
    // RIF has been set. ACFA is also reset if RESET=1.
    uint32_t ACFA:1;            //24

    // Transmission Stop
    // 0 normal operation
    // 1 transmission stopped
    // If MDEIF or MAEIF is set because of an error while the priority reordering machine accesses the memory, 
    // then any new transmission is stopped. If there is an active transmission, this will be completed before 
    // the stop, but if an error occurs during this transmission then no retransmission will be started. 
    // TXS is reset if RESET=1.    
    uint32_t TXS:1;             //25

    // Transmission Block
    // 0: normal operation
    // 1: transmission blocked
    // If MDEIF or MAEIF is set because of an error while the CAN protocol machine is reading data for 
    // transmission, then the transmission is immediately blocked. 
    // If SEIF is set, then the transmission is immediately blocked too.  If TXB=1, then the error counters
    // are frozen. TXB is reset if RESET=1.    
    uint32_t TXB:1;             //26

    // Host side memory error location
    // 0: no error during access from host side
    // 1: error during access from host side in TBUF
    // 2: error during access from host side in RBUF
    // 3: error during access from host side in ACF
    // HELOC will be updated with every new error during a read access from the host side. This is sufficient, 
    // because read errors during read accesses from the CAN side will be signaled by ACFA, TXS and TXB.
    // HELOC will only be updated in case of an error, but not in case of a warning caused by a corrected 
    // single bit error.    
    uint32_t HELOC:2;           //28:27    
    uint32_t rsvd1:3;           //31:29
};

//!
//! CAN S WTRIG Register
//!
union CAN_WTRIG_REG{
    uint32_t                    all;
    struct CAN_WTRIG_BITS      bit;
};

//!
//! CAN MEMES Register bit definitions
//! This 32bit Register contain four 8-bit register, 
//! and each register's bit filed defines below.
//!
//! MEM_ES_0 Reg: MEAEE, ME1EE, MEBP1
//! MEM_ES_1 Reg: ME2EE, MEBP2
//! MEM_ES_2 Reg: MENEC, MEEEC
//!
struct CAN_MEMES_BITS {
    // Memory Error: Bit Position 1
    // MEBP1 defines the position of one single bit error during memory read.
    uint32_t MEBP1:6;           //5:0

    // Memory Error: 1st Error Enable
    // 0: disabled
    // 1: enabled
    // If ME1EE E=1 then MEBP1 is used to do stimulation of a single bit error. To stimulate a dual bit error,
    // MEBP2 and ME2EE needs to be used too. The error is only triggered for the access defined by MEEEC, 
    // MENEC, MEL and MES.    
    uint32_t ME1EE:1;           //6
    
    // Memory Error: Address Error Enable
    // 0: disabled
    // 1: enabled
    // If MEAEE=1 then the address bit 2 is flipped. The result is an access to the neighbor 32 bit word. 
    // The error is only triggered for the access defined by MEEEC, MENEC, MEL and MES.
    // If synthesis parameter RAM_ECC#2 then this bit is always 0.
    uint32_t MEAEE:1;           //7

    // Memory Error: Bit Position 2
    // MEBP2 defines the position of one single bit error during memory read. To stimulate a dual bit error, 
    // MEBP1 and ME1EE needs to be used too.
    uint32_t MEBP2:6;           //13:8

    // Memory Error: 2nd Error Enable
    // 0: disabled
    // 1: enabled
    // If ME2EE E=1 then MEBP2 is used to do stimulation of a single bit error. The error is only triggered
    // for the access defined by MEEEC, MENEC, MEL and MES.    
    uint32_t ME2EE:1;           //14
    uint32_t rsvd2:1;           //15

    // Memory Error: Error Enable Counter
    // Error stimulation is activated if MENEC=0 and MEEEC>0. MEEEC is automatically decremented after each
    // event of an error stimulation (defined by MEL and MES) until it reaches the value 0x0.
    uint32_t MEEEC:4;           //19:16

    // Memory Error: No Error Counter
    // Error stimulation is delayed if MENEC>0. MENEC is automatically decremented after each memory read 
    // access (defined by MEL and MES) until it reaches the value 0x0.
    uint32_t MENEC:4;           //23:20

    // Memory Error Location
    // 0: ACF
    // 1: TBUF
    // 2: RBUF
    // 3: ACF
    // MEL defines the memory area which will be hit by the next memory error together with MES.
    uint32_t MEL:2;             //25:24

    // Memory Error Side
    // 0: Host side
    // 1: CAN side
    // MES defines the side which will be hit by the next memory error together with MEL.    
    uint32_t MES:1;             //26
    uint32_t rsvd1:5;           //31:27
};

//!
//! CAN MEMES Register
//!
union CAN_MEMES_REG{
    uint32_t                    all;
    struct CAN_MEMES_BITS       bit;
};


//!
//! CAN SCFG Register bit definitions
//! This 32bit Register contain One 8-bit register, 
//! and each register's bit filed defines below.
//! 
//! SCFG Reg: FSTIM, SWIF, SWIE, SEIF, XMREN
//!
struct CAN_SCFG_BITS {
    // DMR / TMR enable
    // 0: disabled
    // 1: enabled
    // It depends on the synthesis parameter SAFETY_ENABLE if DMR or TMR is available. XMREN can only
    // be modified if RESET=1.
    uint32_t XMREN:1;           //0

    // DMR / TMR: Safety Error Interrupt Flag
    // 0: no interrupt
    // 1: interrupt pending
    // If XMREN=1 and if there is a not correctable mismatch between the redundant instances, then 
    // SEIF and TXB will be set.    
    uint32_t SEIF:1;            //1

    // DMR / TMR: Safety Warning Interrupt Enable
    // 0: SWIF disabled
    // 1: SWIF enable    
    uint32_t SWIE:1;            //2

    // DMR / TMR: Safety warning interrupt flag
    // 0: no interrupt
    // 1: interrupt pending
    // If XMREN=1 and if there is a correctable mismatch between the redundant instances, then SWIF
    // will be set if SWIE=1.    
    uint32_t SWIF:1;            //3

    // Fault Stimulation
    // Fault stimulation is only possible, if XMREN=1.
    uint32_t FSTIM:3;           //6:4    
    uint32_t rsvd1:25;          //31:7
};

//!
//! CAN MEMES Register
//!
union CAN_SCFG_REG{
    uint32_t                    all;
    struct CAN_SCFG_BITS       bit;
};

//!
//! CAN Control Domain Register Objects;
//!
struct CAN_REGS_ONLY{
    __IO union CAN_CTRL_REG      CTRL;
    __IO union CAN_INT_REG       INT;
    __IO union CAN_STIME_REG     STIMING;
    __IO union CAN_FTIME_REG     FTIMING;
    __IO union CAN_CNT_REG       CNT;
    __IO union CAN_ACFCTRL_REG   ACFCTL;
    __IO union CAN_ACF_REG       ACF;
    __IO union CAN_TTB_REG       TTB;
    __IO union CAN_REFMSG_REG    REFMSG;
    __IO union CAN_TRIG_REG      TRIG;
    __IO union CAN_WTRIG_REG     WTRIG;
    __IO union CAN_MEMES_REG     MEMES;
    __IO union CAN_SCFG_REG      SCFG;
};

//!
//! CAN Message RAM Objects;
//!
typedef struct{
    __IO union CAN_MSGx_ID_REG      ID;
    __IO union CAN_MSGx_CTRL_REG    CTRL;
    __IO union CAN_MSGx_DATA_REG    Data[16];
    __IO union CAN_MSGx_RTS_REG     RTS[2];
} CAN_MSGx;

//*****************************************************************************
//
//! The following are defines for HW CAN register offset.
//
//*****************************************************************************
#define CAN_RXBUF_OFFSET         (0x000U) /*!< CAN Receive Buffer Registers and Reception Time Stamp */
#define CAN_TXBUF_OFFSET         (0x050U) /*!< CAN Transmit Buffer Registers */
#define CAN_REG_OFFSET           (0x0A0U) /*!< CAN Control domain Register. */


#define PTR_TO_CAN_REGS(base)                  ((struct CAN_REGS_ONLY *)((base) + CAN_REG_OFFSET))
#define PTR_TO_CAN_RXBUF(base)                 ((CAN_MSGx *)((base) + CAN_RXBUF_OFFSET))
#define PTR_TO_CAN_TXBUF(base)                 ((CAN_MSGx *)((base) + CAN_TXBUF_OFFSET))

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
// CAN External References & Function Declarations
extern volatile struct CAN_BUF_REGS CanaBufRegs;
extern volatile struct CAN_BUF_REGS CanbBufRegs;
extern volatile struct CAN_BUF_REGS CancBufRegs;
extern volatile struct CAN_BUF_REGS CandBufRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of REGS_CAN_H definition
