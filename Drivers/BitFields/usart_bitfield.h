

#ifndef DRIVERLIB_REGS_REGS_LIN_H_
#define DRIVERLIB_REGS_REGS_LIN_H_



#ifdef __cplusplus
extern "C" {
#endif

struct LIN_US_CR_BIT{		// bits   	description
	uint32_t rsvd1:2;		// 0:1		reserved
	uint32_t RSTRX:1;		// 2:2
	uint32_t RSTTX:1;		// 3:3
	uint32_t RXEN:1;		// 4:4
	uint32_t RXDIS:1;		// 5:5
	uint32_t TXEN:1;		// 6:6
	uint32_t TXDIS:1;		// 7:7
	uint32_t RSTSTA:1;		// 8:8
	uint32_t STTBRK:1;		// 9:9
	uint32_t STPBRK:1;		// 10:10
	uint32_t STTTO:1;		// 11:11
	uint32_t SENDA:1;		// 12:12
	uint32_t RSTIT:1;		// 13:13
	uint32_t RSTNACK:1;		// 14:14
	uint32_t RETTO:1;		// 15:15
	uint32_t DTREN:1;		// 16:16
	uint32_t DTRDIS:1;		// 17:17
	uint32_t RTSEN:1;		// 18:18
	uint32_t RTSDIS:1;		// 19:19
	uint32_t LINABT:1;		// 20:20
	uint32_t LINWKUP:1;		// 21:21
	uint32_t rsvd2:10;		// 22:31
};

union US_CR_REG{
	uint32_t all;
	struct LIN_US_CR_BIT bit;
};

struct LIN_US_MR_BIT{			// bits   	description
	uint32_t USART_MODE:4;		// 0:3
	uint32_t USCLKS:2;			// 4:5
	uint32_t CHRL:2;			// 6:7
	uint32_t SYNC:1;			// 8:8
	uint32_t PAR:3;				// 9:11
	uint32_t NBSTOP:2;			// 12:13
	uint32_t CHMODE:2;			// 14:15
	uint32_t MSBF:1;			// 16:16
	uint32_t MODE9:1;			// 17:17
	uint32_t CLKO:1;			// 18:18
	uint32_t OVER:1;			// 19:19
	uint32_t INACK:1;			// 20:20
	uint32_t DSNACK:1;			// 21:21
	uint32_t VAR_SYNC:1;		// 22:22
	uint32_t INVDATA:1;			// 23:23
	uint32_t MAX_ITERATION:3;	// 24:26
	uint32_t rsvd1:1;			// 27:27
	uint32_t FILTER:1;			// 28:28
	uint32_t MAN:1;				// 29:29
	uint32_t MODSYNC:1;			// 30:30
	uint32_t ONEBIT:1;			// 31:31
};

union US_MR_REG{
	uint32_t all;
	struct LIN_US_MR_BIT bit;
};

struct LIN_US_IER_BIT{	// bits   	description
	uint32_t RXRDY:1;	// 0:0
	uint32_t TXRDY:1;	// 1:1
	uint32_t rsvd1:1;	// 2:2
	uint32_t ENDRX:1;	// 3:3
	uint32_t ENDTX:1;	// 4:4
	uint32_t OVRE:1;	// 5:5
	uint32_t FRAME:1;	// 6:6
	uint32_t PARE:1;	// 7:7
	uint32_t TIMEOUT:1;	// 8:8
	uint32_t TXEMPTY:1;	// 9:8
	uint32_t rsvd2:1;	// 10:10
	uint32_t TXBUFE:1;	// 11:11
	uint32_t RXBUFF:1;	// 12:12
	uint32_t LINBK:1;	// 13:13
	uint32_t LINID:1;	// 14:14
	uint32_t LINTC:1;	// 15:15
	uint32_t rsvd3:9;	// 16:24
	uint32_t LINBE:1;	// 25:25
	uint32_t LINSFE:1;	// 26:26
	uint32_t LINIPE:1;	// 27:27
	uint32_t LINCE:1;	// 28:28
	uint32_t LINSNRE:1;	// 29:29
	uint32_t LINSTE:1;	// 30:30
	uint32_t LINHTE:1;	// 31:31
};

struct USART_US_IER_BIT{	// bits   	description
	uint32_t RXRDY:1;		// 0:0
	uint32_t TXRDY:1;		// 1:1
	uint32_t RXBRK:1;		// 2:2
	uint32_t ENDRX:1;		// 3:3
	uint32_t ENDTX:1;		// 4:4
	uint32_t OVRE:1;		// 5:5
	uint32_t FRAME:1;		// 6:6
	uint32_t PARE:1;		// 7:7
	uint32_t TIMEOUT:1;		// 8:8
	uint32_t TXEMPTY:1;		// 9:9
	uint32_t ITER:1;		// 10:10
	uint32_t TXBUFE:1;		// 11:11
	uint32_t RXBUFF:1;		// 12:12
	uint32_t NACK:1;		// 13:13
	uint32_t rsvd1:2;		// 14:15
	uint32_t RIIC:1;		// 16:16
	uint32_t DSRIC:1;		// 17:17
	uint32_t DCDIC:1;		// 18:18
	uint32_t CTSIC:1;		// 19:19
	uint32_t MANE:1;		// 20:20
	uint32_t rsvd2:11;		// 21:31
};

union US_IER_REG{
	uint32_t all;
	struct USART_US_IER_BIT bit1;
	struct LIN_US_IER_BIT bit2;
};

struct USART_US_IDR_BIT{	// bits   	description
	uint32_t RXRDY:1;		// 0:0
	uint32_t TXRDY:1;		// 1:1
	uint32_t RXBRK:1;		// 2:2
	uint32_t ENDRX:1;		// 3:3
	uint32_t ENDTX:1;		// 4:4
	uint32_t OVRE:1;		// 5:5
	uint32_t FRAME:1;		// 6:6
	uint32_t PARE:1;		// 7:7
	uint32_t TIMEOUT:1;		// 8:8
	uint32_t TXEMPTY:1;		// 9:9
	uint32_t ITER:1;		// 10:10
	uint32_t TXBUFE:1;		// 11:11
	uint32_t RXBUFF:1;		// 12:12
	uint32_t NACK:1;		// 13:13
	uint32_t rsvd1:2;		// 14:15
	uint32_t RIIC:1;		// 16:16
	uint32_t DSRIC:1;		// 17:17
	uint32_t DCDIC:1;		// 18:18
	uint32_t CTSIC:1;		// 19:19
	uint32_t MANE:1;		// 20:20
	uint32_t rsvd2:11;		// 21:31
};

struct LIN_US_IDR_BIT{	// bits   	description
	uint32_t RXRDY:1;	// 0:0
	uint32_t TXRDY:1;	// 1:1
	uint32_t rsvd1:1;	// 2:2
	uint32_t ENDRX:1;	// 3:3
	uint32_t ENDTX:1;	// 4:4
	uint32_t OVRE:1;	// 5:5
	uint32_t FRAME:1;	// 6:6
	uint32_t PARE:1;	// 7:7
	uint32_t TIMEOUT:1;	// 8:8
	uint32_t TXEMPTY:1;	// 9:8
	uint32_t rsvd2:1;	// 10:10
	uint32_t TXBUFE:1;	// 11:11
	uint32_t RXBUFF:1;	// 12:12
	uint32_t LINBK:1;	// 13:13
	uint32_t LINID:1;	// 14:14
	uint32_t LINTC:1;	// 15:15
	uint32_t rsvd3:9;	// 16:24
	uint32_t LINBE:1;	// 25:25
	uint32_t LINSFE:1;	// 26:26
	uint32_t LINIPE:1;	// 27:27
	uint32_t LINCE:1;	// 28:28
	uint32_t LINSNRE:1;	// 29:29
	uint32_t LINSTE:1;	// 30:30
	uint32_t LINHTE:1;	// 31:31
};

union US_IDR_REG{
	uint32_t all;
	struct USART_US_IDR_BIT bit1;
	struct LIN_US_IDR_BIT bit2;
};

struct USART_US_IMR_BIT{	// bits   	description
	uint32_t RXRDY:1;		// 0:0
	uint32_t TXRDY:1;		// 1:1
	uint32_t RXBRK:1;		// 2:2
	uint32_t ENDRX:1;		// 3:3
	uint32_t ENDTX:1;		// 4:4
	uint32_t OVRE:1;		// 5:5
	uint32_t FRAME:1;		// 6:6
	uint32_t PARE:1;		// 7:7
	uint32_t TIMEOUT:1;		// 8:8
	uint32_t TXEMPTY:1;		// 9:9
	uint32_t ITER:1;		// 10:10
	uint32_t TXBUFE:1;		// 11:11
	uint32_t RXBUFF:1;		// 12:12
	uint32_t NACK:1;		// 13:13
	uint32_t rsvd1:2;		// 14:15
	uint32_t RIIC:1;		// 16:16
	uint32_t DSRIC:1;		// 17:17
	uint32_t DCDIC:1;		// 18:18
	uint32_t CTSIC:1;		// 19:19
	uint32_t MANE:1;		// 20:20
	uint32_t rsvd2:11;		// 21:31
};

struct LIN_US_IMR_BIT{	// bits   	description
	uint32_t RXRDY:1;	// 0:0
	uint32_t TXRDY:1;	// 1:1
	uint32_t rsvd1:1;	// 2:2
	uint32_t ENDRX:1;	// 3:3
	uint32_t ENDTX:1;	// 4:4
	uint32_t OVRE:1;	// 5:5
	uint32_t FRAME:1;	// 6:6
	uint32_t PARE:1;	// 7:7
	uint32_t TIMEOUT:1;	// 8:8
	uint32_t TXEMPTY:1;	// 9:8
	uint32_t rsvd2:1;	// 10:10
	uint32_t TXBUFE:1;	// 11:11
	uint32_t RXBUFF:1;	// 12:12
	uint32_t LINBK:1;	// 13:13
	uint32_t LINID:1;	// 14:14
	uint32_t LINTC:1;	// 15:15
	uint32_t rsvd3:9;	// 16:24
	uint32_t LINBE:1;	// 25:25
	uint32_t LINSFE:1;	// 26:26
	uint32_t LINIPE:1;	// 27:27
	uint32_t LINCE:1;	// 28:28
	uint32_t LINSNRE:1;	// 29:29
	uint32_t LINSTE:1;	// 30:30
	uint32_t LINHTE:1;	// 31:31
};

union US_IMR_REG{
	uint32_t all;
	struct USART_US_IMR_BIT bit1;
	struct LIN_US_IMR_BIT bit2;
};

struct USART_US_CSR_BIT{	// bits   	description
	uint32_t RXRDY:1;		// 0:0
	uint32_t TXRDY:1;		// 1:1
	uint32_t RXBRK:1;		// 2:2
	uint32_t ENDRX:1;		// 3:3
	uint32_t ENDTX:1;		// 4:4
	uint32_t OVRE:1;		// 5:5
	uint32_t FRAME:1;		// 6:6
	uint32_t PARE:1;		// 7:7
	uint32_t TIMEOUT:1;		// 8:8
	uint32_t TXEMPTY:1;		// 9:9
	uint32_t ITER:1;		// 10:10
	uint32_t TXBUFE:1;		// 11:11
	uint32_t RXBUFF:1;		// 12:12
	uint32_t NACK:1;		// 13:13
	uint32_t rsvd1:2;		// 14:15
	uint32_t RIIC:1;		// 16:16
	uint32_t DSRIC:1;		// 17:17
	uint32_t DCDIC:1;		// 18:18
	uint32_t CTSIC:1;		// 19:19
	uint32_t RI:1;			// 20:20
	uint32_t DSR:1;			// 21:21
	uint32_t DCD:1;			// 22:22
	uint32_t CTS:1;			// 23:23
	uint32_t MANERR:1;		// 24:24
	uint32_t rsvd2:7;		// 25:31
};

struct LIN_US_CSR_BIT{		// bits   	description
	uint32_t RXRDY:1;		// 0:0
	uint32_t TXRDY:1;		// 1:1
	uint32_t rsvd1:1;		// 2:2
	uint32_t ENDRX:1;		// 3:3
	uint32_t ENDTX:1;		// 4:4
	uint32_t OVRE:1;		// 5:5
	uint32_t FRAME:1;		// 6:6
	uint32_t PARE:1;		// 7:7
	uint32_t TIMEOUT:1;		// 8:8
	uint32_t TXEMPTY:1;		// 9:9
	uint32_t rsvd2:1;		// 10:10
	uint32_t TXBUFE:1;		// 11:11
	uint32_t RXBUFF:1;		// 12:12
	uint32_t LINBK:1;		// 13:13
	uint32_t LINID:1;		// 14:14
	uint32_t LINTC:1;		// 15:15
	uint32_t rsvd3:7;		// 16:22
	uint32_t LINBLS:1;		// 23:23
	uint32_t rsvd4:1;		// 24:24
	uint32_t LINBE:1;		// 25:25
	uint32_t LINISFE:1;		// 26:26
	uint32_t LINIPE:1;		// 27:27
	uint32_t LINCE:1;		// 28:28
	uint32_t LINSNRE:1;		// 29:29
	uint32_t LINSTE:1;		// 30:30
	uint32_t LINHTE:1;		// 31:31
};

union US_CSR_REG{
	uint32_t all;
	struct USART_US_CSR_BIT bit1;
	struct LIN_US_CSR_BIT bit2;
};

struct LIN_US_RHR_BIT{	// bits   	description
	uint32_t RXCHR:9;	// 0:8
	uint32_t rsvd1:6;	// 9:14
	uint32_t RXSYNH:1;	// 15:15
	uint32_t rsvd2:16;	// 16:31
};

union US_RHR_REG{
	uint32_t all;
	struct LIN_US_RHR_BIT bit;
};

struct LIN_US_THR_BIT{	// bits   	description
	uint32_t TXCHR:9;	// 0:8
	uint32_t rsvd1:6;	// 9:14
	uint32_t TXSYNH:1;	// 15:15
	uint32_t rsvd2:16;	// 16:31
};

union US_THR_REG{
	uint32_t all;
	struct LIN_US_THR_BIT bit;
};

struct LIN_US_BRGR_BIT{		// bits   	description
	uint32_t CD:16;			// 0:15
	uint32_t FP:3;			// 16:18
	uint32_t rsvd1:13;		// 19:31
};

union US_BRGR_REG{
	uint32_t all;
	struct LIN_US_BRGR_BIT bit;
};

struct LIN_US_RTOR_BIT{	// bits   	description
	uint32_t TO:17;		// 0:16
	uint32_t rsvd1:15;	// 17:31
};

union US_RTOR_REG{
	uint32_t all;
	struct LIN_US_RTOR_BIT bit;
};

struct LIN_US_TTGR_BIT{	// bits   	description
	uint32_t TG:8;		// 0:7
	uint32_t rsvd1:24;	// 8:31
};

union US_TTGR_REG{
	uint32_t all;
	struct LIN_US_TTGR_BIT bit;
};

struct LIN_US_FIDI_BIT{			// bits   	description
	uint32_t FI_DI_RATIO:16;	// 0:15
	uint32_t rsvd1:16;			// 16:31
};

union US_FIDI_REG{
	uint32_t all;
	struct LIN_US_FIDI_BIT bit;
};

struct LIN_US_NER_BIT{		// bits   	description
	uint32_t NB_ERRORS:8;	// 0:7
	uint32_t rsvd1:24;		// 8:31
};

union US_NER_REG{
	uint32_t all;
	struct LIN_US_NER_BIT bit;
};

struct LIN_US_IF_BIT{		// bits   	description
	uint32_t IRDA_FILTER:8; // 0:7
	uint32_t rsvd1:24;		// 8:31
};

union US_IF_REG{
	uint32_t all;
	struct LIN_US_IF_BIT bit;
};

struct LIN_US_MAN_BIT{		// bits   	description
	uint32_t TX_PL:4;		// 0:3
	uint32_t rsvd1:4;		// 4:7
	uint32_t TX_PP:2;		// 8:9
	uint32_t rsvd2:2;		// 10:11
	uint32_t TX_MPOL:1;		// 12:12
	uint32_t rsvd3:3;		// 13:15
	uint32_t RX_PL:4;		// 16:19
	uint32_t rsvd4:4;		// 20:23
	uint32_t RX_PP:2;		// 24:25
	uint32_t rsvd5:2;		// 26:27
	uint32_t RX_MPOL:1;		// 28:28
	uint32_t ONE:1;			// 29:29
	uint32_t DRIFT:1;		// 30:30
	uint32_t rsvd6:1;		// 31:31
};

union US_MAN_REG{
	uint32_t all;
	struct LIN_US_MAN_BIT bit;
};

struct LIN_US_LINMR_BIT{	// bits   	description
	uint32_t NACT:2;		// 0:1
	uint32_t PARDIS:1;		// 2:2
	uint32_t CHKDIS:1;		// 3:3
	uint32_t CHKTYP:1;		// 4:4
	uint32_t DLM:1;			// 5:5
	uint32_t FSDIS:1;		// 6:6
	uint32_t WKUPTYP:1;		// 7:7
	uint32_t DLC:8;			// 8:15
	uint32_t PDCM:1;		// 16:16
	uint32_t SYNCDIS:1;		// 17:17
	uint32_t rsvd1:14;		// 18:31
};

union US_LINMR_REG{
	uint32_t all;
	struct LIN_US_LINMR_BIT bit;
};

struct LIN_US_LINIR_BIT{	// bits   	description
	uint32_t IDCHR:8;		// 0:7
	uint32_t rsvd1:24;		// 8:31
};

union US_LINIR_REG{
	uint32_t all;
	struct LIN_US_LINIR_BIT bit;
};

struct LIN_US_LINBRR_BIT{	// bits   	description
	uint32_t LINCD:16;		// 0:15
	uint32_t LINFP:3;		// 16:18
	uint32_t rsvd1:13;		// 19:31
};

union US_LINBRR_REG{
	uint32_t all;
	struct LIN_US_LINBRR_BIT bit;
};

struct LIN_US_ICDIFF_BIT{	// bits   	description
	uint32_t ICDIFF:4;		// 0:3
	uint32_t rsvd1:28;		// 4:31
};

union US_ICDIFF_REG{
	uint32_t all;
	struct LIN_US_ICDIFF_BIT bit;
};

struct LIN_US_WPMR_BIT{		// bits   	description
	uint32_t WPEN:1;		// 0:0
	uint32_t rsvd1:7;		// 1:7
	uint32_t WPKEY:24;		// 8:31
};

union US_WPMR_REG{
	uint32_t all;
	struct LIN_US_WPMR_BIT bit;
};

struct LIN_US_WPSR_BIT{		// bits   	description
	uint32_t WPVS:1;		// 0:0
	uint32_t rsvd1:7;		// 1:7
	uint32_t WPVSRC:16;		// 8:23
	uint32_t rsvd2:8;		// 24:31
};

union US_WPSR_REG{
	uint32_t all;
	struct LIN_US_WPSR_BIT bit;
};

struct LIN_US_VERSION_BIT{	// bits   	description
	uint32_t VERSION:12;	// 0:11
	uint32_t rsvd1:4;		// 12:15
	uint32_t MFN:3;			// 16:18
	uint32_t rsvd2:13;		// 19:31
};

union US_VERSION_REG{
	uint32_t all;
	struct LIN_US_VERSION_BIT bit;
};

struct LIN_REGS{
	union US_CR_REG US_CR;
	union US_MR_REG US_MR;
	union US_IER_REG US_IER;
	union US_IDR_REG US_IDR;
	union US_IMR_REG US_IMR;
	union US_CSR_REG US_CSR;
	union US_RHR_REG US_RHR;
	union US_THR_REG US_THR;
	union US_BRGR_REG US_BRGR;
	union US_RTOR_REG US_RTOR;
	union US_TTGR_REG US_TTGR;
	uint32_t rsvd1[5];
	union US_FIDI_REG US_FIDI;
	union US_NER_REG US_NER;
	uint32_t rsvd2;
	union US_IF_REG US_IF;
	union US_MAN_REG US_MAN;
	union US_LINMR_REG US_LINMR;
	union US_LINIR_REG US_LINIR;
	union US_LINBRR_REG US_LINBRR;
	uint32_t rsvd3[10];
	union US_ICDIFF_REG US_ICDIFF;
	uint32_t rsvd4[22];
	union US_WPMR_REG US_WPMR;
	union US_WPSR_REG US_WPSR;
	uint32_t rsvd5[4];
	union US_VERSION_REG US_VERSION;
};

extern volatile struct LIN_REGS LinaRegs;
extern volatile struct LIN_REGS LinbRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif
