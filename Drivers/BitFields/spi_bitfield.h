

#ifndef REGS_SPI_H
#define REGS_SPI_H

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
/** @brief SPI Individual Register Bit Definitions: */

struct CTRLR0_BITS {                /** @brief bits description                    */
    uint32_t    rsvd1:4;            /** @brief 3:0      Reserved                   */
    uint32_t    rsvd2:2;            /** @brief 5:4      Reserved                   */
    uint32_t    SCPH:1;             /** @brief 6        Serial Clock Phase         */
    uint32_t    SCPOL:1;            /** @brief 7        Serial Clock Polarity      */
    uint32_t    TMOD:2;             /** @brief 9:8      Transfer Mode              */
    uint32_t    SLV_OE:1;           /** @brief 10       Slave Output Enable        */
    uint32_t    SRL:1;              /** @brief 11       Shift Register Loop        */
    uint32_t    CFS:4;              /** @brief 15:12    Control Frame Size         */
    uint32_t    DFS_32:5;           /** @brief 20:16    Data Frame Size            */
    uint32_t    rsvd3:2;            /** @brief 22:21    Reserved                   */
    uint32_t    rsvd4:1;            /** @brief 23       Reserved                   */
    uint32_t    SSTE:1;             /** @brief 24       Slave Select Toggle Enable */
    uint32_t    rsvd5:1;            /** @brief 25       Reserved                   */
    uint32_t    rsvd6:6;            /** @brief 31:26    Reserved                   */
};

union CTRLR0_REG {
    uint32_t    all;
    struct      CTRLR0_BITS bit;
};

struct CTRLR1_BITS {                /** @brief bits description           */
    uint32_t    NDF:16;             /** @brief 15:0 Number of Data Frames */
    uint32_t    rsvd1:16;           /** @brief 31:16 Reserved             */
};

union CTRLR1_REG {
    uint32_t    all;
    struct      CTRLR1_BITS  bit;
};

struct SSIENR_BITS {                /** @brief bits description */
    uint32_t    SSI_EN:1;           /** @brief 0 SSI Enable     */
    uint32_t    rsvd1:31;           /** @brief 31:1 Reserved    */
};

union SSIENR_REG {
    uint32_t    all;
    struct      SSIENR_BITS  bit;
};

struct MWCR_BITS {                  /** @brief bits description          */
    uint32_t    MWMOD:1;            /** @brief 0 Microwire Transfer Mode */
    uint32_t    MDD:1;              /** @brief 1 Microwire Control       */
    uint32_t    MHS:1;              /** @brief 2 Microwire Handshaking   */
    uint32_t    rsvd1:29;           /** @brief 31:3 Reserved             */
};

union MWCR_REG {
    uint32_t    all;
    struct      MWCR_BITS   bit;
};

struct	SER_BITS {                  /** @brief bits description           */
    uint32_t    SER:1;              /** @brief 0 Slave Select Enable Flag */
    uint32_t    rsvd1:31;           /** @brief 31:1 Reserved              */
};

union SER_REG {
    uint32_t    all;
    struct      SER_BITS    bit;
};

struct BAUDR_BITS {                 /** @brief bits description        */
    uint32_t    SCKDV:16;           /** @brief 15:0 SSI Clock Divider  */
    uint32_t    rsdv1:16;           /** @brief 31:16 Reserved          */
};

union BAUDR_REG {
    uint32_t    all;
    struct      BAUDR_BITS  bit;
};

struct TXFTLR_BITS {                /** @brief bits description            */
    uint32_t    TFT:4;              /** @brief 3:0 Transmit FIFO Threshold */
    uint32_t    rsvd1:28;           /** @brief 31:4 Reserved               */
};

union TXFTLR_REG {
    uint32_t    all;
    struct      TXFTLR_BITS bit;
};

struct RXFTLR_BITS {                /** @brief bits description           */
    uint32_t    RFT:4;              /** @brief 3:0 Receive FIFO Threshold */
    uint32_t    rsvd1:28;           /** @brief 31:4 Reserved              */
};

union RXFTLR_REG {
    uint32_t    all;
    struct      RXFTLR_BITS bit;
};

struct TXFLR_BITS {                 /** @brief bits description         */
    uint32_t    TXTFL:5;            /** @brief 5:0	Transmit FIFO Level */
    uint32_t    rsvd1:27;           /** @brief 31:6 Reserved            */
};

union TXFLR_REG {
    uint32_t    all;
    struct      TXFLR_BITS  bit;
};

struct RXFLR_BITS {                 /** @brief bits description         */
    uint32_t    RXTFL:5;            /** @brief 4:0	Transmit FIFO Level */
    uint32_t    rsvd1:27;           /** @brief 31:5 Reserved            */
};

union RXFLR_REG {
    uint32_t    all;
    struct      RXFLR_BITS  bit;
};

struct SR_BITS {                    /** @brief bits description          */
    uint32_t    BUSY:1;             /** @brief 0 SSI Busy Flag           */
    uint32_t    TFNF:1;             /** @brief 1 Transmit FIFO Not Full  */
    uint32_t    TFE:1;              /** @brief 2 Transmit FIFO Empty     */
    uint32_t    RFNE:1;             /** @brief 3 Receive FIFO Not Empty  */
    uint32_t    RFF:1;              /** @brief 4 Receive FIFO Full       */
    uint32_t    TXE:1;              /** @brief 5 Transmission Error      */
    uint32_t    DCOL:1;             /** @brief 6 Data Collision Error    */
    uint32_t    rsvd1:25;           /** @brief 31:7 Reserved             */
};

union SR_REG {
    uint32_t    all;
    struct      SR_BITS bit;
};

struct IMR_BITS {                   /** @brief bits description                          */
    uint32_t    TXEIM:1;            /** @brief 0 Transmit FIFO Empty Interrupt Mask      */
    uint32_t    TXOIM:1;            /** @brief 1 Transmit FIFO Overflow Interrupt Mask   */
    uint32_t    RXUIM:1;            /** @brief 2 Transmit FIFO Overflow Interrupt Mask   */
    uint32_t    RXOIM:1;            /** @brief 3 Receive FIFO Overflow Interrupt Mask    */
    uint32_t    RXFIM:1;            /** @brief 4 Receive FIFO Full Interrupt Mask        */
    uint32_t    MSTIM:1;            /** @brief 5 Multi-Master Contention Interrupt Mask  */
    uint32_t    rsvd1:26;           /** @brief 31:6	Reserved                             */
};

union IMR_REG {
    uint32_t all;
    struct   IMR_BITS   bit;
};

struct ISR_BITS {                   /** @brief bits description                           */
    uint32_t    TXEIS:1;            /** @brief 0 Transmit FIFO Empty Interrupt Status     */
    uint32_t    TXOIS:1;            /** @brief 1 Transmit FIFO Overflow Interrupt Status  */
    uint32_t    RXUIS:1;            /** @brief 2 Receive FIFO Underflow Interrupt Status  */
    uint32_t    RXOIS:1;            /** @brief 3 Receive FIFO Overflow Interrupt Status   */
    uint32_t    RXFIS:1;            /** @brief 4 Receive FIFO Full Interrupt Status       */
    uint32_t    MSTIS:1;            /** @brief 5 Multi-Master Contention Interrupt Status */
    uint32_t    rsvd1:26;           /** @brief 31:6 Reserved                              */
};

union ISR_REG {
    uint32_t all;
    struct   ISR_BITS   bit;
};

struct RISR_BITS {                  /** @brief bits description                               */
    uint32_t    TXEIR:1;            /** @brief 0 Transmit FIFO Empty Raw Interrupt Status     */
    uint32_t    TXOIR:1;            /** @brief 1 Transmit FIFO Overflow Raw Interrupt Status  */
    uint32_t    RXUIR:1;            /** @brief 2 Receive FIFO Underflow Raw Interrupt Status  */
    uint32_t    RXOIR:1;            /** @brief 3 Receive FIFO Overflow Raw Interrupt Status   */
    uint32_t    RXFIR:1;            /** @brief 4 Receive FIFO Full Raw Interrupt Status       */
    uint32_t    MSTIR:1;            /** @brief 5 Multi-Master Contention Raw Interrupt Status */
    uint32_t    rsvd1:26;           /** @brief 31:6 Reserved                                  */
};

union RISR_REG {
    uint32_t    all;
    struct      RISR_BITS   bit;
};

struct TXOICR_BITS {                /** @brief bits description                         */
    uint32_t    TXOICR:1;           /** @brief 0 Clear Transmit FIFO Overflow Interrupt */
    uint32_t    rsvd1:31;           /** @brief 31:1 Reserved                            */
};

union TXOICR_REG {
    uint32_t    all;
    struct      TXOICR_BITS bit;
};

struct RXOICR_BITS {                /** @brief bits description                         */
    uint32_t    RXOICR:1;           /** @brief 0 Clear Receive FIFO Overflow Interrupt  */
    uint32_t    rsvd1:31;           /** @brief 31:1 Reserved                            */
};

union RXOICR_REG {
    uint32_t    all;
    struct      RXOICR_BITS bit;
};

struct RXUICR_BITS {                /** @brief bits description                          */
    uint32_t    RXUICR:1;           /** @brief 0 Clear Receive FIFO Underflow Interrupt  */
    uint32_t    rsvd1:31;           /** @brief 31:1 Reserved                             */
};

union RXUICR_REG {
    uint32_t    all;
    struct      RXUICR_BITS bit;
};

struct MSTICR_BITS {                /** @brief bits description                          */
    uint32_t    MSTICR:1;           /** @brief 0 Clear Multi-Master Contention Interrupt */
    uint32_t    rsvd1:31;           /** @brief 31:1 Reserved                             */
};

union MSTICR_REG {
    uint32_t    all;
    struct      MSTICR_BITS bit;
};

struct ICR_BITS {                   /** @brief bits description     */
    uint32_t    ICR:1;              /** @brief 0 Clear Interrupts   */
    uint32_t    rsvd1:31;           /** @brief 31:1 Reserved        */
};

union ICR_REG {
    uint32_t    all;
    struct      ICR_BITS    bit;
};

struct DMACR_BITS {                 /** @brief bits description      */
    uint32_t    RDMAE:1;            /** @brief 0 Receive DMA Enable  */
    uint32_t    TDMAE:1;            /** @brief 1 Transmit DMA Enable */
    uint32_t    rsvd1:31;           /** @brief 31:2 Reserved         */
};

union DMACR_REG {
    uint32_t    all;
    struct      DMACR_BITS  bit;
};

struct DMATDLR_BITS {               /** @brief bits description        */
    uint32_t    DMATDL:4;           /** @brief 3:0 Transmit Data Level */
    uint32_t    rsvd1:28;           /** @brief 31:4 Reserved           */
};

union DMATDLR_REG {
    uint32_t    all;
    struct      DMATDLR_BITS    bit;
};

struct DMARDLR_BITS {               /** @brief bits description        */
    uint32_t    DMARDL:4;           /** @brief 3:0 Receive Data Level  */
    uint32_t    rsvd1:28;           /** @brief 31:4 Reserved           */
};

union DMARDLR_REG {
    uint32_t    all;
    struct      DMARDLR_BITS    bit;
};

struct SPI_REGS {
    union CTRLR0_REG    CTRLR0;
    union CTRLR1_REG    CTRLR1;
    union SSIENR_REG    SSIENR;
    union MWCR_REG      MWCR;
    union SER_REG       SER;
    union BAUDR_REG     BAUDR;
    union TXFTLR_REG    TXFTLR;
    union RXFTLR_REG    RXFTLR;
    union TXFLR_REG     TXFLR;
    union RXFLR_REG     RXFLR;
    union SR_REG        SR;
    union IMR_REG       IMR;
    union ISR_REG       ISR;
    union RISR_REG      RISR;
    union TXOICR_REG    TXOICR;
    union RXOICR_REG    RXOICR;
    union RXUICR_REG    RXUICR;
    union MSTICR_REG    MSTICR;
    union ICR_REG       ICR;
    union DMACR_REG     DMACR;
    union DMATDLR_REG   DMATDLR;
    union DMARDLR_REG   DMARDLR;
    uint32_t            IDR;
    uint32_t            SSI_VERSION_ID;
    uint32_t            DRx_REG[36];
};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
extern volatile struct SPI_REGS SpiaRegs;
extern volatile struct SPI_REGS SpibRegs;

extern volatile struct SPI_REGS SpicRegs;
extern volatile struct SPI_REGS SpidRegs;



#ifdef __cplusplus
}
#endif /** @brief extern "C" */

#endif  /** @brief end of REGS_SPI_H definition */
