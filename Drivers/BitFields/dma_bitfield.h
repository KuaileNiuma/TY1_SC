 
#ifndef REGS_DMA_H
#define REGS_DMA_H

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

//*****************************************************************************
//
//! The following are defines for the AHB DMAC VERSION.
//
//*****************************************************************************



/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
// DMA Individual Register Bit Definitions:

struct RAWTFR_L_BITS {			// bits   description
	uint32_t	RAW:8;			// 7:0   Raw Status for IntTfr Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union RAWTFR_L_REG {
	uint32_t 		 all;
	struct RAWTFR_L_BITS 		 bit;
};

struct RAWTFR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union RAWTFR_H_REG {
	uint32_t 		 all;
	struct RAWTFR_H_BITS 		 bit;
};

struct RAWBLOCK_L_BITS {			// bits   description
	uint32_t	RAW:8;			// 7:0   Raw Status for IntBlock Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union RAWBLOCK_L_REG {
	uint32_t 		 all;
	struct RAWBLOCK_L_BITS 		 bit;
};

struct RAWBLOCK_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union RAWBLOCK_H_REG {
	uint32_t 		 all;
	struct RAWBLOCK_H_BITS 		 bit;
};

struct RAWSRCTRAN_L_BITS {			// bits   description
	uint32_t	RAW:8;			// 7:0   Raw Status for IntSrcTran Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union RAWSRCTRAN_L_REG {
	uint32_t 		 all;
	struct RAWSRCTRAN_L_BITS 		 bit;
};

struct RAWSRCTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union RAWSRCTRAN_H_REG {
	uint32_t 		 all;
	struct RAWSRCTRAN_H_BITS 		 bit;
};

struct RAWDSTTRAN_L_BITS {			// bits   description
	uint32_t	RAW:8;			// 7:0   Raw Status for IntDstTran Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union RAWDSTTRAN_L_REG {
	uint32_t 		 all;
	struct RAWDSTTRAN_L_BITS 		 bit;
};

struct RAWDSTTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union RAWDSTTRAN_H_REG {
	uint32_t 		 all;
	struct RAWDSTTRAN_H_BITS 		 bit;
};

struct RAWERR_L_BITS {			// bits   description
	uint32_t	RAW:8;			// 7:0   Raw Status for IntErr Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union RAWERR_L_REG {
	uint32_t 		 all;
	struct RAWERR_L_BITS 		 bit;
};

struct RAWERR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union RAWERR_H_REG {
	uint32_t 		 all;
	struct RAWERR_H_BITS 		 bit;
};

struct STATUSTFR_L_BITS {			// bits   description
	uint32_t	STATUS:8;			// 7:0   Status for IntTfr Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union STATUSTFR_L_REG {
	uint32_t 		 all;
	struct STATUSTFR_L_BITS 		 bit;
};

struct STATUSTFR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union STATUSTFR_H_REG {
	uint32_t 		 all;
	struct STATUSTFR_H_BITS 		 bit;
};

struct STATUSBLOCK_L_BITS {			// bits   description
	uint32_t	STATUS:8;			// 7:0   Status for IntBlock Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union STATUSBLOCK_L_REG {
	uint32_t 		 all;
	struct STATUSBLOCK_L_BITS 		 bit;
};

struct STATUSBLOCK_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union STATUSBLOCK_H_REG {
	uint32_t 		 all;
	struct STATUSBLOCK_H_BITS 		 bit;
};

struct STATUSSRCTRAN_L_BITS {			// bits   description
	uint32_t	STATUS:8;			// 7:0   Status for IntSrcTran Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union STATUSSRCTRAN_L_REG {
	uint32_t 		 all;
	struct STATUSSRCTRAN_L_BITS 		 bit;
};

struct STATUSSRCTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union STATUSSRCTRAN_H_REG {
	uint32_t 		 all;
	struct STATUSSRCTRAN_H_BITS 		 bit;
};

struct STATUSDSTTRAN_L_BITS {			// bits   description
	uint32_t	STATUS:8;			// 7:0   Status for IntDstTran Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union STATUSDSTTRAN_L_REG {
	uint32_t 		 all;
	struct STATUSDSTTRAN_L_BITS 		 bit;
};

struct STATUSDSTTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union STATUSDSTTRAN_H_REG {
	uint32_t 		 all;
	struct STATUSDSTTRAN_H_BITS 		 bit;
};

struct STATUSERR_L_BITS {			// bits   description
	uint32_t	STATUS:8;			// 7:0   Status for IntErr Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union STATUSERR_L_REG {
	uint32_t 		 all;
	struct STATUSERR_L_BITS 		 bit;
};

struct STATUSERR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union STATUSERR_H_REG {
	uint32_t 		 all;
	struct STATUSERR_H_BITS 		 bit;
};

struct MASKTFR_L_BITS {			// bits   description
	uint32_t	INT_MASK:8;			// 7:0   Mask for IntTfr Interrupt
	uint32_t	INT_MASK_WE:8;			// 15:8   Interrupt Mask Write Enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union MASKTFR_L_REG {
	uint32_t 		 all;
	struct MASKTFR_L_BITS 		 bit;
};

struct MASKTFR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field- read-only
};

union MASKTFR_H_REG {
	uint32_t 		 all;
	struct MASKTFR_H_BITS 		 bit;
};

struct MASKBLOCK_L_BITS {			// bits   description
	uint32_t	INT_MASK:8;			// 7:0   Mask for IntBlock Interrupt
	uint32_t	INT_MASK_WE:8;			// 15:8   Interrupt Mask Write Enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union MASKBLOCK_L_REG {
	uint32_t 		 all;
	struct MASKBLOCK_L_BITS 		 bit;
};

struct MASKBLOCK_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union MASKBLOCK_H_REG {
	uint32_t 		 all;
	struct MASKBLOCK_H_BITS 		 bit;
};

struct MASKSRCTRAN_L_BITS {			// bits   description
	uint32_t	INT_MASK:8;			// 7:0   Mask for IntSrcTran Interrupt
	uint32_t	INT_MASK_WE:8;			// 15:8   Interrupt Mask Write Enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union MASKSRCTRAN_L_REG {
	uint32_t 		 all;
	struct MASKSRCTRAN_L_BITS 		 bit;
};

struct MASKSRCTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union MASKSRCTRAN_H_REG {
	uint32_t 		 all;
	struct MASKSRCTRAN_H_BITS 		 bit;
};

struct MASKDSTTRAN_L_BITS {			// bits   description
	uint32_t	INT_MASK:8;			// 7:0   Mask for IntDstTran Interrupt
	uint32_t	INT_MASK_WE:8;			// 15:8   Interrupt Mask Write Enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union MASKDSTTRAN_L_REG {
	uint32_t 		 all;
	struct MASKDSTTRAN_L_BITS 		 bit;
};

struct MASKDSTTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   63:y Rsvd_1_MaskDstTran R Reserved field - read-only
};

union MASKDSTTRAN_H_REG {
	uint32_t 		 all;
	struct MASKDSTTRAN_H_BITS 		 bit;
};

struct MASKERR_L_BITS {			// bits   description
	uint32_t	INT_MASK:8;			// 7:0   Mask for IntErr Interrupt
	uint32_t	INT_MASK_WE:8;			// 15:8   Interrupt Mask Write Enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union MASKERR_L_REG {
	uint32_t 		 all;
	struct MASKERR_L_BITS 		 bit;
};

struct MASKERR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field- read-only
};

union MASKERR_H_REG {
	uint32_t 		 all;
	struct MASKERR_H_BITS 		 bit;
};

struct CLEARTFR_L_BITS {			// bits   description
	uint32_t	CLEAR:8;			// 7:0   Clear for IntTfr Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union CLEARTFR_L_REG {
	uint32_t 		 all;
	struct CLEARTFR_L_BITS 		 bit;
};

struct CLEARTFR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field
};

union CLEARTFR_H_REG {
	uint32_t 		 all;
	struct CLEARTFR_H_BITS 		 bit;
};

struct CLEARBLOCK_L_BITS {			// bits   description
	uint32_t	CLEAR:8;			// 7:0   Clear for IntBlock Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union CLEARBLOCK_L_REG {
	uint32_t 		 all;
	struct CLEARBLOCK_L_BITS 		 bit;
};

struct CLEARBLOCK_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field
};

union CLEARBLOCK_H_REG {
	uint32_t 		 all;
	struct CLEARBLOCK_H_BITS 		 bit;
};

struct CLEARSRCTRAN_L_BITS {			// bits   description
	uint32_t	CLEAR:8;			// 7:0   Clear for IntSrcTran Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union CLEARSRCTRAN_L_REG {
	uint32_t 		 all;
	struct CLEARSRCTRAN_L_BITS 		 bit;
};

struct CLEARSRCTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field
};

union CLEARSRCTRAN_H_REG {
	uint32_t 		 all;
	struct CLEARSRCTRAN_H_BITS 		 bit;
};

struct CLEARDSTTRAN_L_BITS {			// bits   description
	uint32_t	CLEAR:8;			// 7:0   Clear for IntDstTran Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union CLEARDSTTRAN_L_REG {
	uint32_t 		 all;
	struct CLEARDSTTRAN_L_BITS 		 bit;
};

struct CLEARDSTTRAN_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field
};

union CLEARDSTTRAN_H_REG {
	uint32_t 		 all;
	struct CLEARDSTTRAN_H_BITS 		 bit;
};

struct CLEARERR_L_BITS {			// bits   description
	uint32_t	CLEAR:8;			// 7:0   Clear for IntErr Interrupt
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union CLEARERR_L_REG {
	uint32_t 		 all;
	struct CLEARERR_L_BITS 		 bit;
};

struct CLEARERR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field
};

union CLEARERR_H_REG {
	uint32_t 		 all;
	struct CLEARERR_H_BITS 		 bit;
};

struct STATUSINT_L_BITS {			// bits   description
	uint32_t	TFR:1;			// 0:0   OR of the contents of StatusTfr register
	uint32_t	BLOCK:1;			// 1:1   OR of the contents of StatusBlock register
	uint32_t	SRCT:1;			// 2:2   OR of the contents of StatusSrcTran
	uint32_t	DSTT:1;			// 3:3   OR of the contents of StatusDstTran
	uint32_t	ERR:1;			// 4:4   OR of the contents of StatusErr
	uint32_t	rsvd1:27;			// 31:5   reserved
};

union STATUSINT_L_REG {
	uint32_t 		 all;
	struct STATUSINT_L_BITS 		 bit;
};

struct STATUSINT_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field- read-only
};

union STATUSINT_H_REG {
	uint32_t 		 all;
	struct STATUSINT_H_BITS 		 bit;
};

struct REQSRCREG_L_BITS {			// bits   description
	uint32_t	SRC_REQ:8;			// 7:0   Source Software Transaction Request
	uint32_t	SRC_REQ_WE:8;			// 15:8   Source Software Transaction Request write enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union REQSRCREG_L_REG {
	uint32_t 		 all;
	struct REQSRCREG_L_BITS 		 bit;
};

struct REQSRCREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union REQSRCREG_H_REG {
	uint32_t 		 all;
	struct REQSRCREG_H_BITS 		 bit;
};

struct REQDSTREG_L_BITS {			// bits   description
	uint32_t	DST_REQ:8;			// 7:0   Destination Software Transaction Request
	uint32_t	DST_REQ_WE:8;			// 15:8   Destination Software Transaction Request write enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union REQDSTREG_L_REG {
	uint32_t 		 all;
	struct REQDSTREG_L_BITS 		 bit;
};

struct REQDSTREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union REQDSTREG_H_REG {
	uint32_t 		 all;
	struct REQDSTREG_H_BITS 		 bit;
};

struct SGLRQSRCREG_L_BITS {			// bits   description
	uint32_t	SRC_SGLREQ:8;			// 7:0   Source Single Transaction Request
	uint32_t	SRC_SGLREQ_WE:8;			// 15:8   Source Single Transaction Request write enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union SGLRQSRCREG_L_REG {
	uint32_t 		 all;
	struct SGLRQSRCREG_L_BITS 		 bit;
};

struct SGLRQSRCREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union SGLRQSRCREG_H_REG {
	uint32_t 		 all;
	struct SGLRQSRCREG_H_BITS 		 bit;
};

struct SGLRQDSTREG_L_BITS {			// bits   description
	uint32_t	DST_SGLREQ:8;			// 7:0   Destination Single Transaction Request
	uint32_t	DST_SGLREQ_WE:8;			// 15:8   Destination Single Transaction Request write enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union SGLRQDSTREG_L_REG {
	uint32_t 		 all;
	struct SGLRQDSTREG_L_BITS 		 bit;
};

struct SGLRQDSTREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union SGLRQDSTREG_H_REG {
	uint32_t 		 all;
	struct SGLRQDSTREG_H_BITS 		 bit;
};

struct LSTSRCREG_L_BITS {			// bits   description
	uint32_t	LSTSRC:8;			// 7:0   Source Last Transaction Request register
	uint32_t	LSTSRC_WE:8;			// 15:8   Source Last Transaction Request write enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union LSTSRCREG_L_REG {
	uint32_t 		 all;
	struct LSTSRCREG_L_BITS 		 bit;
};

struct LSTSRCREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field- read-only
};

union LSTSRCREG_H_REG {
	uint32_t 		 all;
	struct LSTSRCREG_H_BITS 		 bit;
};

struct LSTDSTREG_L_BITS {			// bits   description
	uint32_t	LSTDST:8;			// 7:0   Destination Last Transaction Request
	uint32_t	LSTDST_WE:8;			// 15:8   Source Last Transaction Request write enable
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union LSTDSTREG_L_REG {
	uint32_t 		 all;
	struct LSTDSTREG_L_BITS 		 bit;
};

struct LSTDSTREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union LSTDSTREG_H_REG {
	uint32_t 		 all;
	struct LSTDSTREG_H_BITS 		 bit;
};

struct DMACFGREG_L_BITS {			// bits   description
	uint32_t	DMA_EN:1;			// 0:0   DW_ahb_dmac Enable bit.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union DMACFGREG_L_REG {
	uint32_t 		 all;
	struct DMACFGREG_L_BITS 		 bit;
};

struct DMACFGREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union DMACFGREG_H_REG {
	uint32_t 		 all;
	struct DMACFGREG_H_BITS 		 bit;
};

struct CHENREG_L_BITS {			// bits   description
	uint32_t	CH_EN:8;			// 7:0   Channel Enable. The ChEnReg.CH_EN bit is automatically 
	uint32_t	CH_EN_WE:8;			// 15:8   Channel enable register
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union CHENREG_L_REG {
	uint32_t 		 all;
	struct CHENREG_L_BITS 		 bit;
};

struct CHENREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union CHENREG_H_REG {
	uint32_t 		 all;
	struct CHENREG_H_BITS 		 bit;
};

struct DMAIDREG_L_BITS {			// bits   description
	uint32_t	DMA_ID:32;			// 31:0   Hardcoded DW_ahb_dmac peripheral ID.
};

union DMAIDREG_L_REG {
	uint32_t 		 all;
	struct DMAIDREG_L_BITS 		 bit;
};

struct DMAIDREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union DMAIDREG_H_REG {
	uint32_t 		 all;
	struct DMAIDREG_H_BITS 		 bit;
};

struct DMATESTREG_L_BITS {			// bits   description
	uint32_t	TEST_SLV_IF:1;			// 0:0   DMA Test register
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union DMATESTREG_L_REG {
	uint32_t 		 all;
	struct DMATESTREG_L_BITS 		 bit;
};

struct DMATESTREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field- read-only
};

union DMATESTREG_H_REG {
	uint32_t 		 all;
	struct DMATESTREG_H_BITS 		 bit;
};

struct DMALPTIMEOUTREG_L_BITS {			// bits   description
	uint32_t	DMA_LP_TIMEOUT:1;			// 0:0   This field holds timeout value of low power counter register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union DMALPTIMEOUTREG_L_REG {
	uint32_t 		 all;
	struct DMALPTIMEOUTREG_L_BITS 		 bit;
};

struct DMALPTIMEOUTREG_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union DMALPTIMEOUTREG_H_REG {
	uint32_t 		 all;
	struct DMALPTIMEOUTREG_H_BITS 		 bit;
};

struct DMA_COMP_PARAMS_6_L_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union DMA_COMP_PARAMS_6_L_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_6_L_BITS 		 bit;
};

struct DMA_COMP_PARAMS_6_H_BITS {			// bits   description
	uint32_t	CH7_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH7_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH7_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH7_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH7_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH7_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH7_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH7_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH7_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH7_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH7_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH7_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH7_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH7_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH7_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH7_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_6_H_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_6_H_BITS 		 bit;
};

struct DMA_COMP_PARAMS_5_L_BITS {			// bits   description
	uint32_t	CH6_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH6_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH6_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH6_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH6_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH6_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH6_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH6_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH6_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH6_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH6_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH6_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH6_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH6_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH6_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH6_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_5_L_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_5_L_BITS 		 bit;
};

struct DMA_COMP_PARAMS_5_H_BITS {			// bits   description
	uint32_t	CH5_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH5_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH5_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH5_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH5_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH5_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH5_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH5_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH5_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH5_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH5_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH5_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH5_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH5_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH5_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH5_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_5_H_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_5_H_BITS 		 bit;
};

struct DMA_COMP_PARAMS_4_L_BITS {			// bits   description
	uint32_t	CH4_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH4_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH4_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH4_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH4_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH4_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH4_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH4_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH4_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH4_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH4_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH4_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH4_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH4_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH4_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH4_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_4_L_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_4_L_BITS 		 bit;
};

struct DMA_COMP_PARAMS_4_H_BITS {			// bits   description
	uint32_t	CH3_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH3_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH3_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH3_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH3_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH3_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH3_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH3_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH3_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH3_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH3_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH3_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH3_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH3_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH3_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH3_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_4_H_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_4_H_BITS 		 bit;
};

struct DMA_COMP_PARAMS_3_L_BITS {			// bits   description
	uint32_t	CH2_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH2_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH2_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH2_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH2_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH2_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH2_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH2_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH2_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH2_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH2_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH2_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH2_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH2_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH2_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH2_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_3_L_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_3_L_BITS 		 bit;
};

struct DMA_COMP_PARAMS_3_H_BITS {			// bits   description
	uint32_t	CH1_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH1_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH1_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH1_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH1_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH1_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH1_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH1_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH1_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH1_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH1_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH1_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH1_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH1_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH1_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH1_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_3_H_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_3_H_BITS 		 bit;
};

struct DMA_COMP_PARAMS_2_L_BITS {			// bits   description
	uint32_t	CH0_DTW:3;			// 2:0   The value of this register is derived from the 
	uint32_t	CH0_STW:3;			// 5:3   The value of this register is derived from the 
	uint32_t	CH0_STAT_DST:1;			// 6:6   The value of this register is derived from the 
	uint32_t	CH0_STAT_SRC:1;			// 7:7   The value of this register is derived from the 
	uint32_t	CH0_DST_SCA_EN:1;			// 8:8   The value of this register is derived from the 
	uint32_t	CH0_SRC_GAT_EN:1;			// 9:9   The value of this register is derived from the 
	uint32_t	CH0_LOCK_EN:1;			// 10:10   The value of this register is derived from the 
	uint32_t	CH0_MULTI_BLK_EN:1;			// 11:11   The value of this register is derived from the 
	uint32_t	CH0_CTL_WB_EN:1;			// 12:12   The value of this register is derived from the 
	uint32_t	CH0_HC_LLP:1;			// 13:13   The value of this register is derived from the 
	uint32_t	CH0_FC:2;			// 15:14   The value of this register is derived from the 
	uint32_t	CH0_MAX_MULT_SIZE:3;			// 18:16   The value of this register is derived from the 
	uint32_t	CH0_DMS:3;			// 21:19   The value of this register is derived from the 
	uint32_t	CH0_LMS:3;			// 24:22   The value of this register is derived from the 
	uint32_t	CH0_SMS:3;			// 27:25   The value of this register is derived from the 
	uint32_t	CH0_FIFO_DEPTH:3;			// 30:28   The value of this register is derived from the 
	uint32_t	rsvd1:1;			// 31:31   reserved
};

union DMA_COMP_PARAMS_2_L_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_2_L_BITS 		 bit;
};

struct DMA_COMP_PARAMS_2_H_BITS {			// bits   description
	uint32_t	CHO_MULTI_BLK_TYPE:4;			// 3:0   The values of these bit fields are derived from the 
	uint32_t	CH1_MULTI_BLK_TYPE:4;			// 7:4   The values of these bit fields are derived from the 
	uint32_t	CH2_MULTI_BLK_TYPE:4;			// 11:8   The values of these bit fields are derived from the 
	uint32_t	CH3_MULTI_BLK_TYPE:4;			// 15:12   The values of these bit fields are derived from the 
	uint32_t	CH4_MULTI_BLK_TYPE:4;			// 19:16   The values of these bit fields are derived from the 
	uint32_t	CH5_MULTI_BLK_TYPE:4;			// 23:20   The values of these bit fields are derived from the 
	uint32_t	CH6_MULTI_BLK_TYPE:4;			// 27:24   The values of these bit fields are derived from the 
	uint32_t	CH7_MULTI_BLK_TYPE:4;			// 31:28   The values of these bit fields are derived from the 
};

union DMA_COMP_PARAMS_2_H_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_2_H_BITS 		 bit;
};

struct DMA_COMP_PARAMS_1_L_BITS {			// bits   description
	uint32_t	CHO_MAX_BLK_SIZE:4;			// 3:0   The values of these bit fields are derived from the 
	uint32_t	CH1_MAX_BLK_SIZE:4;			// 7:4   The values of these bit fields are derived from the 
	uint32_t	CH2_MAX_BLK_SIZE:4;			// 11:8   The values of these bit fields are derived from the 
	uint32_t	CH3_MAX_BLK_SIZE:4;			// 15:12   The values of these bit fields are derived from the 
	uint32_t	CH4_MAX_BLK_SIZE:4;			// 19:16   The values of these bit fields are derived from the 
	uint32_t	CH5_MAX_BLK_SIZE:4;			// 23:20   The values of these bit fields are derived from the 
	uint32_t	CH6_MAX_BLK_SIZE:4;			// 27:24   The values of these bit fields are derived from the 
	uint32_t	CH7_MAX_BLK_SIZE:4;			// 31:28   The values of these bit fields are derived from the 
};

union DMA_COMP_PARAMS_1_L_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_1_L_BITS 		 bit;
};

struct DMA_COMP_PARAMS_1_H_BITS {			// bits   description
	uint32_t	DMA_BIG_ENDIAN:1;			// 0:0   The value of this register is derived from the 
	uint32_t	INTR_IO:2;			// 2:1   The value of this register is derived from the 
	uint32_t	MAX_ABRST:1;			// 3:3   The value of this register is derived from the 
	uint32_t	RSVD_DMA_COMP_PARAMS_1:4;			// 7:4   Reserved field- read-only
	uint32_t	NUM_CHANNELS:3;			// 10:8   The value of this register is derived from the 
	uint32_t	NUM_MASTER_INT:2;			// 12:11   The value of this register is derived from the 
	uint32_t	S_HDATA_WIDTH:2;			// 14:13   The value of this register is derived from the 
	uint32_t	M4_HDATA_WIDTH:2;			// 16:15   The value of this register is derived from the 
	uint32_t	M3_HDATA_WIDTH:2;			// 18:17   The value of this register is derived from the 
	uint32_t	M2_HDATA_WIDTH:2;			// 20:19   The value of this register is derived from the 
	uint32_t	M1_HDATA_WIDTH:2;			// 22:21   The value of this register is derived from the 
	uint32_t	NUM_HS_INT:5;			// 27:23   The value of this register is derived from the 
	uint32_t	ADD_ENCODED_PARAMS:1;			// 28:28   The value of this register is derived from the 
	uint32_t	STATIC_ENDIAN_SELECT:1;			// 29:29   The value of this register is derived from the 
	uint32_t	rsvd1:2;			// 31:30   reserved
};

union DMA_COMP_PARAMS_1_H_REG {
	uint32_t 		 all;
	struct DMA_COMP_PARAMS_1_H_BITS 		 bit;
};

struct DMACOMPSID_L_BITS {			// bits   description
	uint32_t	DMA_COMP_TYPE:32;			// 31:0   DMA Component Version - See release notes.
};

union DMACOMPSID_L_REG {
	uint32_t 		 all;
	struct DMACOMPSID_L_BITS 		 bit;
};

struct DMACOMPSID_H_BITS {			// bits   description
	uint32_t	DMA_COMP_VERSION:32;			// 31:0   31:0 DMA_COMP_TYPE R DMA Component Type Number = `h44571110. This 
};

union DMACOMPSID_H_REG {
	uint32_t 		 all;
	struct DMACOMPSID_H_BITS 		 bit;
};

struct BORCHx_L_BITS {           // bits   description
    uint32_t    BLK_OFFST:16;       // 15: 0 Address offset complement indicates a negative number
    uint32_t    BLK_OFFST_EN:1;     // 16   enable singal for block offset in auto_reload-contiguous
    uint32_t    rsvd1:15;           // 31:17   reserved
};

union BORCHx_L_REG {
	uint32_t        all;
	struct BORCHx_L_BITS         bit;
};

struct BORCHx_H_BITS {           // bits   description
	uint32_t    RSVD:32;            // 31:0   Reserved field - read-only
};

union BORCHx_H_REG {
    uint32_t        all;
    
    struct BORCHx_H_BITS         bit;
};

struct BLKCNTCHx_L_BITS {           // bits   description
    uint32_t    BLK_CNT:16;         // 15: 0 block count: Number of blocks
    uint32_t    BLK_CNT_EN:1;       // 16   enable singal for block cnt in auto_reload-contiguous
    uint32_t    rsvd1:16;           // 31:16   reserved
};

union BLKCNTCHx_L_REG {
	uint32_t        all;
	struct BLKCNTCHx_L_BITS         bit;
};

struct BLKCNTCHx_H_BITS {           // bits   description
	uint32_t    RSVD:32;            // 31:0   Reserved field - read-only
};

union BLKCNTCHx_H_REG {
    uint32_t        all;
    struct BLKCNTCHx_H_BITS         bit;
};

struct MASKFDI_L_BITS {             // bits   description
    uint32_t    FDI_MASK:8;         // 7: 0   first-data-intr mask of channe
    uint32_t    rsvd1:24;           // 31:8   reserved
};

union MASKFDI_L_REG {
	uint32_t        all;
	struct MASKFDI_L_BITS         bit;
};

struct MASKFDI_H_BITS {             // bits   description
	uint32_t    RSVD:32;            // 31:0   Reserved field - read-only
};

union MASKFDI_H_REG {
    uint32_t        all;
    struct MASKFDI_H_BITS         bit;
};

struct FDI_L_BITS {                 // bits   description
    uint32_t    FDI:8;              // 7: 0   first-data-intr of channe
    uint32_t    rsvd1:24;           // 31:8   reserved
};

union FDI_L_REG {
	uint32_t        all;
	struct FDI_L_BITS             bit;
};

struct FDI_H_BITS {                 // bits   description
	uint32_t    RSVD:32;            // 31:0   Reserved field - read-only
};

union FDI_H_REG {
    uint32_t        all;
    struct FDI_H_BITS             bit;
};

struct SAR_L_BITS {			// bits   description
	uint32_t	SAR:32;			// 31:0   Current Source Address of DMA transfer. Updated after 
};

union SAR_L_REG {
	uint32_t 		 all;
	struct SAR_L_BITS 		 bit;
};

struct SAR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union SAR_H_REG {
	uint32_t 		 all;
	struct SAR_H_BITS 		 bit;
};

struct DAR_L_BITS {			// bits   description
	uint32_t	DAR:32;			// 31:0   Current Destination address of DMA transfer. Updated 
};

union DAR_L_REG {
	uint32_t 		 all;
	struct DAR_L_BITS 		 bit;
};

struct DAR_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union DAR_H_REG {
	uint32_t 		 all;
	struct DAR_H_BITS 		 bit;
};

struct LLP_L_BITS {			// bits   description
	uint32_t	LMS:1;			// 0:0   List Master Select. Identifies the AHB layer/interface where 
	uint32_t	LOC:31;			// 31:1   Starting Address In Memory of next LLI if block chaining is 
};

union LLP_L_REG {
	uint32_t 		 all;
	struct LLP_L_BITS 		 bit;
};

struct LLP_H_BITS {			// bits   description
	uint32_t	RSVD:32;			// 31:0   Reserved field - read-only
};

union LLP_H_REG {
	uint32_t 		 all;
	struct LLP_H_BITS 		 bit;
};

struct CTL_L_BITS {			// bits   description
	uint32_t	INT_EN:1;			// 0:0   Interrupt Enable Bit. If set, then all interrupt-generating 
	uint32_t	DST_TR_WIDTH:3;			// 3:1   Destination Transfer Width. Mapped to AHB bus hsize. For 
	uint32_t	SRC_TR_WIDTH:3;			// 6:4   Source Transfer Width. Mapped to AHB bus hsize. For a 
	uint32_t	DINC:2;			// 8:7   Destination Address Increment. Indicates whether to 
	uint32_t	SINC:2;			// 10:9   Source Address Increment. Indicates whether to increment 
	uint32_t	DEST_MSIZE:3;			// 13:11   Destination Burst Transaction Length. Number of data 
	uint32_t	SRC_MSIZE:3;			// 16:14   Source Burst Transaction Length. Number of data items, 
	uint32_t	SRC_GATHER_EN:1;			// 17:17   Source gather enable. Gather on the source side is 
	uint32_t	DST_SCATTER_EN:1;			// 18:18   Destination scatter enable. Scatter on the destination side 
	uint32_t	rsvd1:1;			// 19:19   reserved
	uint32_t	TT_FC:3;			// 22:20   Transfer Type and Flow Control. Flow control can be 
	uint32_t	DMS:2;			// 24:23   Destination Master Select. Identifies the Master Interface 
	uint32_t	SMS:2;			// 26:25   Source Master Select. Identifies the Master Interface layer 
	uint32_t	LLP_DST_EN:1;			// 27:27   Block chaining is enabled on the destination side only if 
	uint32_t	LLP_SRC_EN:1;			// 28:28   Block chaining is enabled on the source side only if the 
	uint32_t	rsvd2:3;			// 31:29   reserved
};

union CTL_L_REG {
	uint32_t 		 all;
	struct CTL_L_BITS 		 bit;
};

struct CTL_H_BITS {             // bits   description
#if (DMAC_VERSION == 0x30)
    uint32_t    BLOCK_TS:15;    // 14:0   Block Transfer Size.
    uint32_t    DONE:1;         // 15     Done bit.
    uint32_t    rsvd1:6;        // 31:16  reserved
#else
    uint32_t    BLOCK_TS:12;    // 11:0   Block Transfer Size.
    uint32_t    DONE:1;         // 12     Done bit.
    uint32_t    rsvd1:19;       // 31:13  reserved
#endif    
};

union CTL_H_REG {
	uint32_t 		 all;
	struct CTL_H_BITS 		 bit;
};

struct CFG_L_BITS {			// bits   description
	uint32_t	rsvd1:5;			// 4:0   reserved
	uint32_t	CH_PRIOR:3;			// 7:5   Channel Priority. A priority of 7 is the highest priority, and 0 
	uint32_t	CH_SUSP:1;			// 8:8   Channel Suspend. Suspends all DMA data transfers from 
	uint32_t	FIFO_EMPTY:1;			// 9:9   Channel FIFO status. Indicates if there is data left in the 
	uint32_t	HS_SEL_DST:1;			// 10:10   Destination Software or Hardware Handshaking Select.
	uint32_t	HS_SEL_SRC:1;			// 11:11   Source Software or Hardware Handshaking Select. This 
	uint32_t	LOCK_CH_L:2;			// 13:12   Channel Local Level. Indicates the duration over which 
	uint32_t	LOCK_B_L:2;			// 15:14   Bus lock level. Indicates the duration over which 
	uint32_t	LOCK_CH:1;			// 16:16   Channel Lock Bit. When the channel is granted control of 
	uint32_t	LOCK_B:1;			// 17:17   Bus Lock Bit. When active, the AHB bus master signal 
	uint32_t	DST_HS_POL:1;			// 18:18   Destination Handshaking Interface Polarity.
	uint32_t	SRC_HS_POL:1;			// 19:19   Source Handshaking Interface Polarity.
	uint32_t	MAX_ABRST:10;			// 29:20   Maximum AMBA Burst Length. Maximum AMBA burst 
	uint32_t	RELOAD_SRC:1;			// 30:30   Automatic Source Reload. The SARx register can be 
	uint32_t	RELOAD_DST:1;			// 31:31   Automatic Destination Reload. The DARx register can be 
};

union CFG_L_REG {
	uint32_t 		 all;
	struct CFG_L_BITS 		 bit;
};

struct CFG_H_BITS {			// bits   description
	uint32_t	FCMODE:1;			// 0:0   Flow Control Mode. Determines when source transaction 
	uint32_t	FIFO_MODE:1;			// 1:1   FIFO Mode Select. Determines how much space or data 
	uint32_t	PROTCTL:3;			// 4:2   Protection Control bits used to drive the AHB HPROT[3:1] 
	uint32_t	DS_UPD_EN:1;			// 5:5   Destination Status Update Enable. Destination status 
	uint32_t	SS_UPD_EN:1;			// 6:6   Source Status Update Enable. Source status information is 
	uint32_t	SRC_PER:4;			// 10:7   Source Hardware Interface..
	uint32_t	DEST_PER:4;			// 14:11   Destination hardware interface.
	uint32_t	rsvd1:17;			// 31:15   reserved
};

union CFG_H_REG {
	uint32_t 		 all;
	struct CFG_H_BITS 		 bit;
};

struct SGR_L_BITS {             // bits   description
    uint32_t    SGI:20;         // 19:0   Source Gather Interval.
#if (DMAC_VERSION == 0x30)
    uint32_t    rsvd1:12;       // 31:20   reserved.
#else
    uint32_t    SGC:12;         // 31:20   Source Gather Count. Source contiguous transfer count 

#endif    
};

union SGR_L_REG {
	uint32_t 		 all;
	struct SGR_L_BITS 		 bit;
};

struct SGR_H_BITS {             // bits   description
#if (DMAC_VERSION == 0x30)
    uint32_t    SGC:15;        // 14:0   Source Gather Count. Source contiguous transfer count 
    uint32_t    rsvd1:17;       // 31:15   Reserved field - read-only
#else
    uint32_t    RSVD:32;        // 31:0   Reserved field - read-only
#endif
};

union SGR_H_REG {
	uint32_t 		 all;
	struct SGR_H_BITS 		 bit;
};

struct DSR_L_BITS {             // bits   description
    uint32_t    DSI:20;         // 19:0   Destination Scatter Interval.
#if (DMAC_VERSION == 0x30)
    uint32_t    rsvd1:12;       // 31:20  Reserved
#else    
    uint32_t    DSC:12;         // 31:20  Destination Scatter Count. Destination contiguous transfer
#endif
};

union DSR_L_REG {
	uint32_t 		 all;
	struct DSR_L_BITS 		 bit;
};

struct DSR_H_BITS {             // bits   description
#if (DMAC_VERSION == 0x30)
    uint32_t    DSC:15;         // 14:0    Destination Scatter Count. Destination contiguous transfer 
    uint32_t    RSVD:17;        // 31:15   Reserved field - read-only
#else
    uint32_t    RSVD:32;        // 31:0   Reserved field - read-only
#endif
};

union DSR_H_REG {
	uint32_t 		 all;
	struct DSR_H_BITS 		 bit;
};


typedef struct _DMA_EXT_CHNx_EGS {

    union  BORCHx_L_REG          DMA_BOR_L;
    union  BORCHx_H_REG          DMA_BOR_H;  
    union  BLKCNTCHx_L_REG       DMA_BLKCNT_L;
    union  BLKCNTCHx_H_REG       DMA_BLKCNT_H; 
    uint32_t                        ext_chns_rsvd[16];        // reserved
}DMA_EXT_CHNx_REGS;
    

// DMA Register Definitions:

struct DMA_CTL_STA_REGS {
	union  RAWTFR_L_REG			RAWTFR_L;
	union  RAWTFR_H_REG			RAWTFR_H;
	union  RAWBLOCK_L_REG			RAWBLOCK_L;
	union  RAWBLOCK_H_REG			RAWBLOCK_H;
	union  RAWSRCTRAN_L_REG			RAWSRCTRAN_L;
	union  RAWSRCTRAN_H_REG			RAWSRCTRAN_H;
	union  RAWDSTTRAN_L_REG			RAWDSTTRAN_L;
	union  RAWDSTTRAN_H_REG			RAWDSTTRAN_H;
	union  RAWERR_L_REG			RAWERR_L;
	union  RAWERR_H_REG			RAWERR_H;
	union  STATUSTFR_L_REG			STATUSTFR_L;
	union  STATUSTFR_H_REG			STATUSTFR_H;
	union  STATUSBLOCK_L_REG			STATUSBLOCK_L;
	union  STATUSBLOCK_H_REG			STATUSBLOCK_H;
	union  STATUSSRCTRAN_L_REG			STATUSSRCTRAN_L;
	union  STATUSSRCTRAN_H_REG			STATUSSRCTRAN_H;
	union  STATUSDSTTRAN_L_REG			STATUSDSTTRAN_L;
	union  STATUSDSTTRAN_H_REG			STATUSDSTTRAN_H;
	union  STATUSERR_L_REG			STATUSERR_L;
	union  STATUSERR_H_REG			STATUSERR_H;
	union  MASKTFR_L_REG			MASKTFR_L;
	union  MASKTFR_H_REG			MASKTFR_H;
	union  MASKBLOCK_L_REG			MASKBLOCK_L;
	union  MASKBLOCK_H_REG			MASKBLOCK_H;
	union  MASKSRCTRAN_L_REG			MASKSRCTRAN_L;
	union  MASKSRCTRAN_H_REG			MASKSRCTRAN_H;
	union  MASKDSTTRAN_L_REG			MASKDSTTRAN_L;
	union  MASKDSTTRAN_H_REG			MASKDSTTRAN_H;
	union  MASKERR_L_REG			MASKERR_L;
	union  MASKERR_H_REG			MASKERR_H;
	union  CLEARTFR_L_REG			CLEARTFR_L;
	union  CLEARTFR_H_REG			CLEARTFR_H;
	union  CLEARBLOCK_L_REG			CLEARBLOCK_L;
	union  CLEARBLOCK_H_REG			CLEARBLOCK_H;
	union  CLEARSRCTRAN_L_REG			CLEARSRCTRAN_L;
	union  CLEARSRCTRAN_H_REG			CLEARSRCTRAN_H;
	union  CLEARDSTTRAN_L_REG			CLEARDSTTRAN_L;
	union  CLEARDSTTRAN_H_REG			CLEARDSTTRAN_H;
	union  CLEARERR_L_REG			CLEARERR_L;
	union  CLEARERR_H_REG			CLEARERR_H;
	union  STATUSINT_L_REG			STATUSINT_L;
	union  STATUSINT_H_REG			STATUSINT_H;
	union  REQSRCREG_L_REG			REQSRCREG_L;
	union  REQSRCREG_H_REG			REQSRCREG_H;
	union  REQDSTREG_L_REG			REQDSTREG_L;
	union  REQDSTREG_H_REG			REQDSTREG_H;
	union  SGLRQSRCREG_L_REG			SGLRQSRCREG_L;
	union  SGLRQSRCREG_H_REG			SGLRQSRCREG_H;
	union  SGLRQDSTREG_L_REG			SGLRQDSTREG_L;
	union  SGLRQDSTREG_H_REG			SGLRQDSTREG_H;
	union  LSTSRCREG_L_REG			LSTSRCREG_L;
	union  LSTSRCREG_H_REG			LSTSRCREG_H;
	union  LSTDSTREG_L_REG			LSTDSTREG_L;
	union  LSTDSTREG_H_REG			LSTDSTREG_H;
	union  DMACFGREG_L_REG			DMACFGREG_L;
	union  DMACFGREG_H_REG			DMACFGREG_H;
	union  CHENREG_L_REG			CHENREG_L;
	union  CHENREG_H_REG			CHENREG_H;
	union  DMAIDREG_L_REG			DMAIDREG_L;
	union  DMAIDREG_H_REG			DMAIDREG_H;
	union  DMATESTREG_L_REG			DMATESTREG_L;
	union  DMATESTREG_H_REG			DMATESTREG_H;
	union  DMALPTIMEOUTREG_L_REG			DMALPTIMEOUTREG_L;
	union  DMALPTIMEOUTREG_H_REG			DMALPTIMEOUTREG_H;
	uint32_t 						rsvd1[2]; 		 // reserved
	union  DMA_COMP_PARAMS_6_L_REG			DMA_COMP_PARAMS_6_L;
	union  DMA_COMP_PARAMS_6_H_REG			DMA_COMP_PARAMS_6_H;
	union  DMA_COMP_PARAMS_5_L_REG			DMA_COMP_PARAMS_5_L;
	union  DMA_COMP_PARAMS_5_H_REG			DMA_COMP_PARAMS_5_H;
	union  DMA_COMP_PARAMS_4_L_REG			DMA_COMP_PARAMS_4_L;
	union  DMA_COMP_PARAMS_4_H_REG			DMA_COMP_PARAMS_4_H;
	union  DMA_COMP_PARAMS_3_L_REG			DMA_COMP_PARAMS_3_L;
	union  DMA_COMP_PARAMS_3_H_REG			DMA_COMP_PARAMS_3_H;
	union  DMA_COMP_PARAMS_2_L_REG			DMA_COMP_PARAMS_2_L;
	union  DMA_COMP_PARAMS_2_H_REG			DMA_COMP_PARAMS_2_H;
	union  DMA_COMP_PARAMS_1_L_REG			DMA_COMP_PARAMS_1_L;
	union  DMA_COMP_PARAMS_1_H_REG			DMA_COMP_PARAMS_1_H;
	union  DMACOMPSID_L_REG			DMACOMPSID_L;
	union  DMACOMPSID_H_REG			DMACOMPSID_H;
    DMA_EXT_CHNx_REGS            ext_chnx[8];
    union  MASKFDI_L_REG            MASKFDI_L;
    union  MASKFDI_H_REG            MASKFDI_H;    
    union  FDI_L_REG                FDI_L;
    union  FDI_H_REG                FDI_H;
};

struct DMA_CH_REGS {
	union  SAR_L_REG			SAR_L;
	union  SAR_H_REG			SAR_H;
	union  DAR_L_REG			DAR_L;
	union  DAR_H_REG			DAR_H;
	union  LLP_L_REG			LLP_L;
	union  LLP_H_REG			LLP_H;
	union  CTL_L_REG			CTL_L;
	union  CTL_H_REG			CTL_H;
	uint32_t 						rsvd1[8]; 		 // reserved
	union  CFG_L_REG			CFG_L;
	union  CFG_H_REG			CFG_H;
	union  SGR_L_REG			SGR_L;
	union  SGR_H_REG			SGR_H;
	union  DSR_L_REG			DSR_L;
	union  DSR_H_REG			DSR_H;
};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
// DMA External References & Function Declarations

extern volatile struct DMA_CTL_STA_REGS DMACTLSTARegs;
extern volatile struct DMA_CH_REGS DMACHRegs;

#ifdef __cplusplus
}
#endif 


#endif  // end of REGS_DMA_H definition
