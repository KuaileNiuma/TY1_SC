
#ifndef REGS_UART_H
#define REGS_UART_H



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
// SCI Individual Register Bit Definitions:

//struct RBR_THR_DLL_BITS {			// bits   description
//	uint32_t	RBR_THR_DLL:8;			// 7:0   bit0-7 of Receive Buffer, Transmit Holding, Divisor Latch (Low).
//	uint32_t	RBRBIT8_THRBIT8:1;			// 8:8   bit8 of Receive Buffer, Transmit Holding.
//	uint32_t	rsvd1:23;			// 31:9   reserved
//};

//union RBR_THR_DLL_REG {
//	uint32_t 		 all;
//	struct RBR_THR_DLL_BITS 		 bit;
//};

struct RBR_BITS {			// bits   description
	uint32_t	RBR:8;			// 7:0   bit0-7 of Receive Buffer
	uint32_t	RBRBIT8:1;			// 8:8   bit8 of Receive Buffer
	uint32_t	rsvd1:23;			// 31:9   reserved
};

struct THR_BITS {			// bits   description
	uint32_t	THR:8;			// 7:0   bit0-7 of Transmit Holding
	uint32_t	THRBIT8:1;			// 8:8   bit8 of Transmit Holding
	uint32_t	rsvd1:23;			// 31:9   reserved
};

struct DLL_BITS {			// bits   description
	uint32_t	DLL:8;			// 7:0   bit0-7 of Transmit Holding
	uint32_t	rsvd2:24;			// 31:8   reserved
};

union REG0_REG {
	uint32_t 		 all;
	struct RBR_BITS  RBR_all;
	struct THR_BITS  THR_all;
	struct DLL_BITS  DLL_all;
};

struct IER_DLH_BITS {			// bits   description
	uint32_t	ERBFI_DLHBIT0:1;			// 0:0   Enable Received Data Available Interrupt register, bit0 of register Divisor Latch (High).
	uint32_t	ETBEI_DLHBIT1:1;			// 1:1   Enable Transmit Holding Register Empty Interrupt register, bit1 of register Divisor Latch (High).
	uint32_t	ELSI_DLHBIT2:1;			// 2:2   Enable Receiver Line Status Interrupt register, bit2 of register Divisor Latch (High).
	uint32_t	EDSSI_DLHBIT3:1;			// 3:3   Enable Modem Status Interrupt register, bit3 of register Divisor Latch (High).
	uint32_t	ELCOLR_DLHBIT4:1;			// 4:4   Interrupt Enable Register, bit4 of register Divisor Latch (High).
	uint32_t	DLHBIT5TO6:2;			// 6:5   bit5-6 of register Divisor Latch (High).
	uint32_t	PTIME_DLHBIT7:1;			// 7:7   Programmable THRE Interrupt Mode Enable register, bit7 of register Divisor Latch (High).
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union IER_DLH_REG {
	uint32_t 		 all;
	struct IER_DLH_BITS 		 bit;
};

struct IIR_FCR_BITS {			// bits   description
	uint32_t	IIDBIT0_FIFOE:1;			// 0:0   Bit3 of Interrupt ID (or IID) register, FIFO Enable (or FIFOE) register.
	uint32_t	IIDBIT1_RFIFOR:1;			// 1:1   Bit3 of Interrupt ID (or IID) register, RCVR FIFO Reset (or RFIFOR) register.
	uint32_t	IIDBIT2_XFIFOR:1;			// 2:2   Bit3 of Interrupt ID (or IID) register, XMIT FIFO Reset (or XFIFOR) register. 
	uint32_t	IIDBIT3_DMAM:1;			// 3:3   Bit3 of Interrupt ID (or IID) register, DMA Mode (or DMAM) register.
	uint32_t	TET:2;			// 5:4   TX Empty Trigger (or TET) register. 
	uint32_t	FIFOSE_RT:2;			// 7:6    
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union IIR_FCR_REG {
	uint32_t 		 all;
	struct IIR_FCR_BITS 		 bit;
};

struct LCR_BITS {			// bits   description
	uint32_t	DLS:2;			// 1:0   Data Length Select (or CLS as used in legacy).

	uint32_t	STOP:1;			// 2:2   Number of stop bits.

	uint32_t	PEN:1;			// 3:3   Parity Enable.

	uint32_t	EPS:1;			// 4:4   Even Parity Select.

	uint32_t	SP:1;			// 5:5   Stick Parity.

	uint32_t	BC:1;			// 6:6   Break Control Bit.

	uint32_t	DLAB:1;			// 7:7   Divisor Latch Access Bit.

	uint32_t	rsvd1:24;			// 31:8   reserved
};

union LCR_REG {
	uint32_t 		 all;
	struct LCR_BITS 		 bit;
};

struct MCR_BITS {			// bits   description
	uint32_t	DTR:1;			// 0:0   Data Terminal Ready.

	uint32_t	RTS:1;			// 1:1   Request to Send.

	uint32_t	OUT1:1;			// 2:2   OUT1

	uint32_t	OUT2:1;			// 3:3   OUT2

	uint32_t	LOOPBACK:1;			// 4:4   LoopBack Bit

	uint32_t	AFCE:1;			// 5:5   Auto Flow Control Enable

	uint32_t	SIRE:1;			// 6:6   SIR Mode Enable

	uint32_t	rsvd1:25;			// 31:7   reserved
};

union MCR_REG {
	uint32_t 		 all;
	struct MCR_BITS 		 bit;
};

struct LSR_BITS {			// bits   description
	uint32_t	DR:1;			// 0:0   Data Ready bit.

	uint32_t	OE:1;			// 1:1   Overrun error bit.

	uint32_t	PE:1;			// 2:2   Parity Error bit.

	uint32_t	FE:1;			// 3:3   Framing Error bit.

	uint32_t	BI:1;			// 4:4   Break Interrupt bit.

	uint32_t	THRE:1;			// 5:5   Transmit Holding Register Empty bit.

	uint32_t	TEMT:1;			// 6:6   Transmitter Empty bit.

	uint32_t	RFE:1;			// 7:7   Receiver FIFO Error bit.

	uint32_t	ADDR_RCVD:1;			// 8:8   Address Received Bit.

	uint32_t	rsvd1:23;			// 31:9   reserved
};

union LSR_REG {
	uint32_t 		 all;
	struct LSR_BITS 		 bit;
};

struct MSR_BITS {			// bits   description
	uint32_t	DCTS:1;			// 0:0   Delta Clear to Send.

	uint32_t	DDSR:1;			// 1:1   Delta Data Set Ready.

	uint32_t	TERI:1;			// 2:2   Trailing Edge of Ring Indicator.

	uint32_t	DDCD:1;			// 3:3   Delta Data Carrier Detect.

	uint32_t	CTS:1;			// 4:4   Clear to Send.

	uint32_t	DSR:1;			// 5:5   Data Set Ready.

	uint32_t	RI:1;			// 6:6   Ring Indicator.

	uint32_t	DCD:1;			// 7:7   Data Carrier Detect.

	uint32_t	rsvd1:24;			// 31:8   reserved
};

union MSR_REG {
	uint32_t 		 all;
	struct MSR_BITS 		 bit;
};

struct SCR_BITS {			// bits   description
	uint32_t	SCR:8;			// 7:0   This register is for programmers to use as a temporary storage space. It has no defined purpose in the
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union SCR_REG {
	uint32_t 		 all;
	struct SCR_BITS 		 bit;
};

struct LPDLL_BITS {			// bits   description
	uint32_t	LPDLL:8;			// 7:0   This register makes up the lower 8-bits of a 16-bit, read/write, Low Power Divisor Latch register that
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union LPDLL_REG {
	uint32_t 		 all;
	struct LPDLL_BITS 		 bit;
};

struct LPDLH_BITS {			// bits   description
	uint32_t	LPDLH:8;			// 7:0   This register makes up the upper 8-bits of a 16-bit, read/write, Low Power Divisor Latch register that
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union LPDLH_REG {
	uint32_t 		 all;
	struct LPDLH_BITS 		 bit;
};

struct FAR_BITS {			// bits   description
	uint32_t	FAR:1;			// 0:0   Writes will have no effect when FIFO_ACCESS == No, always readable. This register is use to enable a
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union FAR_REG {
	uint32_t 		 all;
	struct FAR_BITS 		 bit;
};

struct USR_BITS {			// bits   description
	uint32_t	BUSY:1;			// 0:0   SCI Busy.

	uint32_t	RSVD_TFNF:1;			// 1:1   Transmit FIFO Not Full.

	uint32_t	RSVD_TFE:1;			// 2:2   Transmit FIFO Empty.

	uint32_t	RSVD_RFNE:1;			// 3:3   Receive FIFO Not Empty.

	uint32_t	RSVD_RFF:1;			// 4:4   Receive FIFO Full.

	uint32_t	rsvd1:27;			// 31:5   reserved
};

union USR_REG {
	uint32_t 		 all;
	struct USR_BITS 		 bit;
};

struct TFL_BITS {			// bits   description
	uint32_t	TFL:5;			// 4:0   Transmit FIFO Level.
	uint32_t	rsvd1:27;			// 31:5   reserved
};

union TFL_REG {
	uint32_t 		 all;
	struct TFL_BITS 		 bit;
};

struct RFL_BITS {			// bits   description
	uint32_t	RFL:5;			// 4:0   Receive FIFO Level.
	uint32_t	rsvd1:27;			// 31:5   reserved
};

union RFL_REG {
	uint32_t 		 all;
	struct RFL_BITS 		 bit;
};

struct HTX_BITS {			// bits   description
	uint32_t	HTX:1;			// 0:0   Halt TX.

	uint32_t	rsvd1:31;			// 31:1   reserved
};

union HTX_REG {
	uint32_t 		 all;
	struct HTX_BITS 		 bit;
};

struct DMASA_BITS {			// bits   description
	uint32_t	DMASA:1;			// 0:0   DMA Software Acknowledge.

	uint32_t	rsvd1:31;			// 31:1   reserved
};

union DMASA_REG {
	uint32_t 		 all;
	struct DMASA_BITS 		 bit;
};

struct TCR_BITS {			// bits   description
	uint32_t	RS485_EN:1;			// 0:0   RS485 Transfer Enable.

	uint32_t	RE_POL:1;			// 1:1   Receiver Enable Polarity.

	uint32_t	DE_POL:1;			// 2:2   Driver Enable Polarity.

	uint32_t	XFER_MODE:2;			// 4:3   Transfer Mode.

	uint32_t	rsvd1:27;			// 31:5   reserved
};

union TCR_REG {
	uint32_t 		 all;
	struct TCR_BITS 		 bit;
};

struct DE_EN_BITS {			// bits   description
	uint32_t	DE_ENABLE:1;			// 0:0   DE Enable control.

	uint32_t	rsvd1:31;			// 31:1   reserved
};

union DE_EN_REG {
	uint32_t 		 all;
	struct DE_EN_BITS 		 bit;
};

struct RE_EN_BITS {			// bits   description
	uint32_t	RE_ENABLE:1;			// 0:0   RE Enable control.

	uint32_t	rsvd1:31;			// 31:1   reserved
};

union RE_EN_REG {
	uint32_t 		 all;
	struct RE_EN_BITS 		 bit;
};

struct DET_BITS {			// bits   description
	uint32_t	DE_ASSERTION_TIME:8;			// 7:0   Driver Enable assertion time.

	uint32_t	rsvd1:8;			// 15:8   reserved
	uint32_t	DE_DEASSERTION_TIME:8;			// 23:16   Driver Enable de-assertion time.

	uint32_t	rsvd2:8;			// 31:24   reserved
};

union DET_REG {
	uint32_t 		 all;
	struct DET_BITS 		 bit;
};

struct TAT_BITS {			// bits   description
	uint32_t	DE_TO_RE:16;			// 15:0   Driver Enable to Receiver Enable TurnAround time.

	uint32_t	RE_TO_DE:16;			// 31:16   Receiver Enable to Driver Enable TurnAround time.

};

union TAT_REG {
	uint32_t 		 all;
	struct TAT_BITS 		 bit;
};

struct RAR_BITS {			// bits   description
	uint32_t	RAR:8;			// 7:0   This is an address matching register during receive mode. If the 9-th bit is set in the incoming character
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union RAR_REG {
	uint32_t 		 all;
	struct RAR_BITS 		 bit;
};

struct TAR_BITS {			// bits   description
	uint32_t	TAR:8;			// 7:0   This is an address matching register during transmit mode. If DLS_E (LCR_EXT[0]) bit is enabled, then
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union TAR_REG {
	uint32_t 		 all;
	struct TAR_BITS 		 bit;
};

struct LCR_EXT_BITS {			// bits   description
	uint32_t	DLS_E:1;			// 0:0   Extension for DLS. This bit is used to enable 9-bit data for transmit and receive transfers.
	uint32_t	ADDR_MATCH:1;			// 1:1   Address Match Mode.This bit is used to enable the address match feature during receive.

	uint32_t	SEND_ADDR:1;			// 2:2   Send address control bit. This bit is used as a control knob for the user to determine when to send the
	uint32_t	TRANSMIT_MODE:1;			// 3:3   Transmit mode control bit. This bit is used to control the type of transmit mode during 9-bit data transfers.

	uint32_t	rsvd1:28;			// 31:4   reserved
};

union LCR_EXT_REG {
	uint32_t 		 all;
	struct LCR_EXT_BITS 		 bit;
};


// SCI Register Definitions:

struct SCI_REGS {
	//union  RBR_THR_DLL_REG			RBR_THR_DLL;
	union  REG0_REG			REG0;
	union  IER_DLH_REG		IER_DLH;
	union  IIR_FCR_REG		IIR_FCR;
	union  LCR_REG			LCR;
	union  MCR_REG			MCR;
	union  LSR_REG			LSR;
	union  MSR_REG			MSR;
	union  SCR_REG			SCR;
	union  LPDLL_REG		LPDLL;
	union  LPDLH_REG		LPDLH;
	uint32_t 				rsvd1[18]; 		 // reserved
	union  FAR_REG			FAR;
	uint32_t 				rsvd2[2]; 		 // reserved
	union  USR_REG			USR;
	union  TFL_REG			TFL;
	union  RFL_REG			RFL;
	uint32_t 				rsvd3[7]; 		 // reserved
	union  HTX_REG			HTX;
	union  DMASA_REG		DMASA;
	union  TCR_REG			TCR;
	union  DE_EN_REG		DE_EN;
	union  RE_EN_REG		RE_EN;
	union  DET_REG			DET;
	union  TAT_REG			TAT;
	uint32_t 				rsvd4; 		 // reserved
	union  RAR_REG			RAR;
	union  TAR_REG			TAR;
	union  LCR_EXT_REG		LCR_EXT;
};

struct SCICCR_BITS {                    // bits description
    Uint16 SCICHAR:3;                   // 2:0 Character length control
    Uint16 ADDRIDLE_MODE:1;             // 3 ADDR/IDLE Mode control
    Uint16 LOOPBKENA:1;                 // 4 Loop Back enable
    Uint16 PARITYENA:1;                 // 5 Parity enable
    Uint16 PARITY:1;                    // 6 Even or Odd Parity
    Uint16 STOPBITS:1;                  // 7 Number of Stop Bits
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union SCICCR_REG
{
	uint16 all;
	struct SCICCR_BITS   bit;
};

struct SCICTL1_BITS {                   // bits description
    Uint16 RXENA:1;                     // 0 SCI receiver enable
    Uint16 TXENA:1;                     // 1 SCI transmitter enable
    Uint16 SLEEP:1;                     // 2 SCI sleep
    Uint16 TXWAKE:1;                    // 3 Transmitter wakeup method
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 SWRESET:1;                   // 5 Software reset
    Uint16 RXERRINTENA:1;               // 6 Receive error interrupt enable
    Uint16 rsvd2:9;                     // 15:7 Reserved
};

union SCICTL1_REG {
    Uint16  all;
    struct  SCICTL1_BITS  bit;
};

struct SCIHBAUD_BITS {                  // bits description
    Uint16 BAUD:8;                      // 7:0 SCI 16-bit baud selection Registers SCIHBAUD
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union SCIHBAUD_REG {
    Uint16  all;
    struct  SCIHBAUD_BITS  bit;
};

struct SCILBAUD_BITS {                  // bits description
    Uint16 BAUD:8;                      // 7:0 SCI 16-bit baud selection Registers SCILBAUD
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union SCILBAUD_REG {
    Uint16  all;
    struct  SCILBAUD_BITS  bit;
};

struct SCICTL2_BITS {                   // bits description
    Uint16 TXINTENA:1;                  // 0 Transmit __interrupt enable
    Uint16 RXBKINTENA:1;                // 1 Receiver-buffer break enable
    Uint16 rsvd1:4;                     // 5:2 Reserved
    Uint16 TXEMPTY:1;                   // 6 Transmitter empty flag
    Uint16 TXRDY:1;                     // 7 Transmitter ready flag
    Uint16 rsvd2:8;                     // 15:8 Reserved
};

union SCICTL2_REG {
    Uint16  all;
    struct  SCICTL2_BITS  bit;
};

struct SCIRXST_BITS {                   // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 RXWAKE:1;                    // 1 Receiver wakeup detect flag
    Uint16 PE:1;                        // 2 Parity error flag
    Uint16 OE:1;                        // 3 Overrun error flag
    Uint16 FE:1;                        // 4 Framing error flag
    Uint16 BRKDT:1;                     // 5 Break-detect flag
    Uint16 RXRDY:1;                     // 6 Receiver ready flag
    Uint16 RXERROR:1;                   // 7 Receiver error flag
    Uint16 rsvd2:8;                     // 15:8 Reserved
};

union SCIRXST_REG {
    Uint16  all;
    struct  SCIRXST_BITS  bit;
};

struct SCIRXEMU_BITS {                  // bits description
    Uint16 ERXDT:8;                     // 7:0 Receive emulation buffer data
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union SCIRXEMU_REG {
    Uint16  all;
    struct  SCIRXEMU_BITS  bit;
};

struct SCIRXBUF_BITS {                  // bits description
    Uint16 SAR:8;                       // 7:0 Receive Character bits
    Uint16 rsvd1:6;                     // 13:8 Reserved
    Uint16 SCIFFPE:1;                   // 14 Receiver error flag
    Uint16 SCIFFFE:1;                   // 15 Receiver error flag
};

union SCIRXBUF_REG {
    Uint16  all;
    struct  SCIRXBUF_BITS  bit;
};

struct SCITXBUF_BITS {                  // bits description
    Uint16 TXDT:8;                      // 7:0 Transmit data buffer
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union SCITXBUF_REG {
    Uint16  all;
    struct  SCITXBUF_BITS  bit;
};

struct SCIFFTX_BITS {                   // bits description
    Uint16 TXFFIL:5;                    // 4:0 Interrupt level
    Uint16 TXFFIENA:1;                  // 5 Interrupt enable
    Uint16 TXFFINTCLR:1;                // 6 Clear INT flag
    Uint16 TXFFINT:1;                   // 7 INT flag
    Uint16 TXFFST:5;                    // 12:8 FIFO status
    Uint16 TXFIFORESET:1;               // 13 FIFO reset
    Uint16 SCIFFENA:1;                  // 14 Enhancement enable
    Uint16 SCIRST:1;                    // 15 SCI reset rx/tx channels
};

union SCIFFTX_REG {
    Uint16  all;
    struct  SCIFFTX_BITS  bit;
};

struct SCIFFRX_BITS {                   // bits description
    Uint16 RXFFIL:5;                    // 4:0 Interrupt level
    Uint16 RXFFIENA:1;                  // 5 Interrupt enable
    Uint16 RXFFINTCLR:1;                // 6 Clear INT flag
    Uint16 RXFFINT:1;                   // 7 INT flag
    Uint16 RXFFST:5;                    // 12:8 FIFO status
    Uint16 RXFIFORESET:1;               // 13 FIFO reset
    Uint16 RXFFOVRCLR:1;                // 14 Clear overflow
    Uint16 RXFFOVF:1;                   // 15 FIFO overflow
};

union SCIFFRX_REG {
    Uint16  all;
    struct  SCIFFRX_BITS  bit;
};

struct SCIFFCT_BITS {                   // bits description
    Uint16 FFTXDLY:8;                   // 7:0 FIFO transmit delay
    Uint16 rsvd1:5;                     // 12:8 Reserved
    Uint16 CDC:1;                       // 13 Auto baud mode enable
    Uint16 ABDCLR:1;                    // 14 Auto baud clear
    Uint16 ABD:1;                       // 15 Auto baud detect
};

union SCIFFCT_REG {
    Uint16  all;
    struct  SCIFFCT_BITS  bit;
};

struct SCIPRI_BITS {                    // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 FREESOFT:2;                  // 4:3 Emulation modes
    Uint16 rsvd2:3;                     // 7:5 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
};

union SCIPRI_REG {
    Uint16  all;
    struct  SCIPRI_BITS  bit;
};

struct SCIDBG_CFG_REG{
	uint32 cfg:3;
	uint32 rsvd:29;
};

union SCIDBG_CFG{
	uint32_t all;
	struct SCIDBG_CFG_REG   bit;
};

struct SCI_RX_TIMEOUT_VAL_CFG{
	uint32 val_set: 32;
};

union SCIRX_TIMEOUT_VALUE{
	uint32_t all;
	struct SCI_RX_TIMEOUT_VAL_CFG bit;
};

struct SCI_RX_TIMEOUT_INT{
	uint32 TIMEOUT_INT_FLAG:1;
	uint32 TIMEOUT_INT_EN:1;
	uint32 TIMEOUT_INT_CLR:1;
	uint32 TIMEOUT_INT_TRIGGER:1;
	uint32 rsvd:28;
};

union SCIRX_TIMEOUT_INT
{
	uint32 all;
	struct SCI_RX_TIMEOUT_INT bit;
};

struct SCI_DLF{
	uint32_t DLF_VAL:6;
	uint32_t rsvd:26;
};

union SCIDLF_REG
{
	uint32_t all;
	struct SCI_DLF bit;
};

struct SCI_REGS {
    union   SCICCR_REG                       SCICCR;                       // Communications control register
    union   SCICTL1_REG                      SCICTL1;                      // Control register 1
    union   SCIHBAUD_REG                     SCIHBAUD;                     // Baud rate (high) register
    union   SCILBAUD_REG                     SCILBAUD;                     // Baud rate (low) register
    union   SCICTL2_REG                      SCICTL2;                      // Control register 2
    union   SCIRXST_REG                      SCIRXST;                      // Receive status register
    union   SCIRXEMU_REG                     SCIRXEMU;                     // Receive emulation buffer register
    union   SCIRXBUF_REG                     SCIRXBUF;                     // Receive data buffer
    Uint16                                   rsvd1;                        // Reserved
    union   SCITXBUF_REG                     SCITXBUF;                     // Transmit data buffer
    union   SCIFFTX_REG                      SCIFFTX;                      // FIFO transmit register
    union   SCIFFRX_REG                      SCIFFRX;                      // FIFO receive register
    union   SCIFFCT_REG                      SCIFFCT;                      // FIFO control register
    Uint16                                   rsvd2[2];                     // Reserved
    union   SCIPRI_REG                       SCIPRI;                       // SCI priority control
    union   SCIDBG_CFG                       SCI_DBG_CFG;
    union   SCIRX_TIMEOUT_VALUE              SCI_RX_TIMEOUT_VAL_CFG;
    union   SCIRX_TIMEOUT_INT                SCI_RX_TIMEOUT_INT;
    uint16                                   rsvd4[201];
    union   SCIDLF_REG                       SCIDLF;
};


#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
// SCI External References & Function Declarations
extern volatile struct SCI_REGS SciaRegs;
extern volatile struct SCI_REGS ScibRegs;
extern volatile struct SCI_REGS ScicRegs;

extern volatile struct SCI_REGS ScidRegs;
extern volatile struct SCI_REGS ScieRegs;



#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of REGS_SCI_H definition
