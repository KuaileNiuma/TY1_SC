
#ifndef REGS_CMPSS_H
#define REGS_CMPSS_H


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
//---------------------------------------------------------------------------
// CMPSS Individual Register Bit Definitions:

struct COMPCTL_BITS {                   // bits description
	uint16_t COMPHSOURCE:1;               // 0 High Comparator Source Select
	uint16_t COMPHINV:1;                  // 1 High Comparator Invert Select
	uint16_t CTRIPHSEL:2;                 // 3:2 High Comparator Trip Select
	uint16_t CTRIPOUTHSEL:2;              // 5:4 High Comparator Trip Output Select
	uint16_t ASYNCHEN:1;                  // 6 High Comparator Asynchronous Path Enable
	uint16_t rsvd1:1;                     // 7 Reserved
	uint16_t COMPLSOURCE:1;               // 8 Low Comparator Source Select
	uint16_t COMPLINV:1;                  // 9 Low Comparator Invert Select
	uint16_t CTRIPLSEL:2;                 // 11:10 Low Comparator Trip Select
	uint16_t CTRIPOUTLSEL:2;              // 13:12 Low Comparator Trip Output Select
	uint16_t ASYNCLEN:1;                  // 14 Low Comparator Asynchronous Path Enable
	uint16_t COMPDACE:1;                  // 15 Comparator/DAC Enable
};

union COMPCTL_REG {
	uint16_t  all;
    struct  COMPCTL_BITS  bit;
};

struct COMPHYSCTL_BITS {                // bits description
	uint16_t COMPHYS:4;                   // 3:0 Comparator Hysteresis Trim
	uint16_t rsvd1:12;                    // 15:4 Reserved
};

union COMPHYSCTL_REG {
	uint16_t  all;
    struct  COMPHYSCTL_BITS  bit;
};

struct COMPSTS_BITS {                   // bits description
	uint16_t COMPHSTS:1;                  // 0 High Comparator Status
	uint16_t COMPHLATCH:1;                // 1 High Comparator Latched Status
	uint16_t rsvd1:6;                     // 7:2 Reserved
	uint16_t COMPLSTS:1;                  // 8 Low Comparator Status
	uint16_t COMPLLATCH:1;                // 9 Low Comparator Latched Status
	uint16_t rsvd2:6;                     // 15:10 Reserved
};

union COMPSTS_REG {
	uint16_t  all;
    struct  COMPSTS_BITS  bit;
};

struct COMPSTSCLR_BITS {                // bits description
	uint16_t rsvd1:1;                     // 0 Reserved
	uint16_t HLATCHCLR:1;                 // 1 High Comparator Latched Status Clear
	uint16_t HSYNCCLREN:1;                // 2 High Comparator EPWMSYNCPER Clear Enable
	uint16_t rsvd2:6;                     // 8:3 Reserved
	uint16_t LLATCHCLR:1;                 // 9 Low Comparator Latched Status Clear
	uint16_t LSYNCCLREN:1;                // 10 Low Comparator EPWMSYNCPER Clear Enable
	uint16_t rsvd3:5;                     // 15:11 Reserved
};

union COMPSTSCLR_REG {
	uint16_t  all;
    struct  COMPSTSCLR_BITS  bit;
};



struct COMPDACCTL_BITS {                // bits description
	uint16_t DACSOURCE:1;                 // 0 DAC Source Control
	uint16_t RAMPSOURCE:4;                // 4:1 Ramp Generator Source Control
	uint16_t SELREF:1;                    // 5 DAC Reference Select
	uint16_t RAMPLOADSEL:1;               // 6 Ramp Load Select
	uint16_t SWLOADSEL:1;                 // 7 Software Load Select
	uint16_t BLANKSOURCE:4;               // 11:8 EPWMBLANK Source Select
	uint16_t BLANKEN:1;                   // 12 EPWMBLANK Enable
	uint16_t rsvd1:1;                     // 13 Reserved
	uint16_t FREESOFT:2;                  // 15:14 Free/Soft Emulation Bits
};

union COMPDACCTL_REG {
	uint16_t  all;
    struct  COMPDACCTL_BITS  bit;
};

struct DACHVALS_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACHVALS_REG {
	uint16_t  all;
    struct  DACHVALS_BITS  bit;
};

struct DACHVALA_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACHVALA_REG {
	uint16_t  all;
    struct  DACHVALA_BITS  bit;
};

struct DACLVALS_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACLVALS_REG {
	uint16_t  all;
    struct  DACLVALS_BITS  bit;
};

struct DACLVALA_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACLVALA_REG {
	uint16_t  all;
    struct  DACLVALA_BITS  bit;
};

struct RAMPDLYA_BITS {                  // bits description
	uint16_t DELAY:13;                    // 12:0 Ramp Delay Value
	uint16_t rsvd1:3;                     // 15:13 Reserved
};

union RAMPDLYA_REG {
	uint16_t  all;
    struct  RAMPDLYA_BITS  bit;
};

struct RAMPDLYS_BITS {                  // bits description
	uint16_t DELAY:13;                    // 12:0 Ramp Delay Value
	uint16_t rsvd1:3;                     // 15:13 Reserved
};

union RAMPDLYS_REG {
	uint16_t  all;
    struct  RAMPDLYS_BITS  bit;
};

struct CTRIPLFILCTL_BITS {              // bits description
	uint16_t rsvd1:4;                     // 3:0 Reserved
	uint16_t SAMPWIN:5;                   // 8:4 Sample Window
	uint16_t THRESH:5;                    // 13:9 Majority Voting Threshold
	uint16_t rsvd2:1;                     // 14 Reserved
	uint16_t FILINIT:1;                   // 15 Filter Initialization Bit
};

union CTRIPLFILCTL_REG {
	uint16_t  all;
    struct  CTRIPLFILCTL_BITS  bit;
};

struct CTRIPHFILCTL_BITS {              // bits description
	uint16_t rsvd1:4;                     // 3:0 Reserved
    uint16_t SAMPWIN:5;                   // 8:4 Sample Window
    uint16_t THRESH:5;                    // 13:9 Majority Voting Threshold
    uint16_t rsvd2:1;                     // 14 Reserved
    uint16_t FILINIT:1;                   // 15 Filter Initialization Bit
};

union CTRIPHFILCTL_REG {
	uint16_t  all;
    struct  CTRIPHFILCTL_BITS  bit;
};


struct CALIBOFFSETH_BITS {			// bits   description
	uint32_t	CALIBOFFSETH:13;			// 12:0
	uint32_t	OFFSETHEN:1;			// 13:13
	uint32_t	CAL_START_H:1;			// 14:14
	uint32_t	rsvd1:17;			// 31:15   reserved
};

union CALIBOFFSETH_REG {
	uint32_t 		 all;
	struct CALIBOFFSETH_BITS 		 bit;
};



struct CALIBOFFSETL_BITS {			// bits   description
	uint32_t	CALIBOFFSETL:13;			// 12:0
	uint32_t	OFFSETLEN:1;			// 13:13
	uint32_t	CAL_START_L:1;			// 14:14
	uint32_t	rsvd1:17;			// 31:15   reserved
};

union CALIBOFFSETL_REG {
	uint32_t 		 all;
	struct CALIBOFFSETL_BITS 		 bit;
};

struct ANACLKCFG_BITS {			// bits   description            1.2
	uint32_t	ANACLKDIV:16;			// 15:0   ANACLK period configuration    2h = Divide by 2    4h = Divide by 4    0h = reserved
	uint32_t	ANACLKPHADLY:18;			// 31:16   ANACLK phase delay configuration
};

union ANACLKCFG_REG {
	uint32_t 		 all;
	struct ANACLKCFG_BITS 		 bit;
};

struct CALIBFSMSTATUS_BITS {			// bits   description    1.2
	uint32_t	CMPL_FSM_STATUS:8;			// 7:0   Calibration Current FSM State Value:
	uint32_t	CMPH_FSM_STATUS:8;			// 15:8   Calibration Current FSM State Value:
	uint32_t    rsvd1:16;                  //31:16
};

union CALIBFSMSTATUS_REG {
	uint32_t 		 all;
	struct CALIBFSMSTATUS_BITS 		 bit;
};

struct EPWMBLANKCTRL_BITS {			// bits   description
	uint32_t	BLANK_INV:1;			// 0:0   Control the polarity of EPWMBLANK signal
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union EPWMBLANKCTRL_REG {
	uint32_t 		 all;
	struct EPWMBLANKCTRL_BITS 		 bit;
};



struct CMPDACCTRL_BITS{
	uint32_t     LPSOURCE:1;       // 0
	uint32_t     LCLOCKDELAY:2;    //2:1
	uint32_t     rsvd1:13;      //15:3
	uint32_t     HPSOURCE:1;       //16
	uint32_t     HCLOCKDELAY:2;    //18:17
	uint32_t     rsvd2:13;      //31:19

};
union CMPDACCTRL_REG{
	uint32_t 		 all;
	struct CMPDACCTRL_BITS   bit;
};
struct DBG_CFG_BITS{
	uint32_t    ARM_MASK:1;        //0
	uint32_t    DSP_MASK:1;         //1
	uint32_t	rsvd1:30;        //31:2
};
union DBG_CFG_REG{
	uint32_t 		 all;
	struct DBG_CFG_BITS   bit;
};


struct CMPSS_REGS {
    union   COMPCTL_REG                      COMPCTL;                      // CMPSS Comparator Control Register            //offset 0 ,sub_offset 2
    union   COMPHYSCTL_REG                   COMPHYSCTL;                   // CMPSS Comparator Hysteresis Control Register //offset 2 ,sub_offset 2
    union   COMPSTS_REG                      COMPSTS;                      // CMPSS Comparator Status Register             //offset 4 ,sub_offset 2
    union   COMPSTSCLR_REG                   COMPSTSCLR;                   // CMPSS Comparator Status Clear Register       //offset 6 ,sub_offset 2
    union   COMPDACCTL_REG                   COMPDACCTL;                   // CMPSS DAC Control Register                   //offset 8 ,sub_offset 2
    uint16_t                                   rsvd1;                        // Reserved                                   //offset 10 ,sub_offset 2
    union   DACHVALS_REG                     DACHVALS;                     // CMPSS High DAC Value Shadow Register         //offset C ,sub_offset 2
    union   DACHVALA_REG                     DACHVALA;                     // CMPSS High DAC Value Active Register         //offset E ,sub_offset 2
    uint16_t                                   RAMPMAXREFA;                  // CMPSS Ramp Max Reference Active Register   //offset 10 ,sub_offset 2
    uint16_t                                   rsvd2;                        // Reserved                                   //offset 12 ,sub_offset 2
    uint16_t                                   RAMPMAXREFS;                  // CMPSS Ramp Max Reference Shadow Register   //offset 14 ,sub_offset 2
    uint16_t                                   rsvd3;                        // Reserved                                   //offset 16 ,sub_offset 2
    uint16_t                                   RAMPDECVALA;                  // CMPSS Ramp Decrement Value Active Register //offset 18 ,sub_offset 2
    uint16_t                                   rsvd4;                        // Reserved                                   //offset 1A ,sub_offset 2
    uint16_t                                   RAMPDECVALS;                  // CMPSS Ramp Decrement Value Shadow Register //offset 1C ,sub_offset 2
    uint16_t                                   rsvd5;                        // Reserved                                   //offset 1E ,sub_offset 2
    uint16_t                                   RAMPSTS;                      // CMPSS Ramp Status Register                 //offset 20 ,sub_offset 2
    uint16_t                                   rsvd6;                        // Reserved                                   //offset 22 ,sub_offset 2
    union   DACLVALS_REG                     DACLVALS;                     // CMPSS Low DAC Value Shadow Register          //offset 24 ,sub_offset 2
    union   DACLVALA_REG                     DACLVALA;                     // CMPSS Low DAC Value Active Register          //offset 26 ,sub_offset 2
    union   RAMPDLYA_REG                     RAMPDLYA;                     // CMPSS Ramp Delay Active Register             //offset 28 ,sub_offset 2
    union   RAMPDLYS_REG                     RAMPDLYS;                     // CMPSS Ramp Delay Shadow Register             //offset 2A ,sub_offset 2
    union   CTRIPLFILCTL_REG                 CTRIPLFILCTL;                 // CTRIPL Filter Control Register               //offset 2C ,sub_offset 2
    uint16_t                                 CTRIPLFILCLKCTL;              // CTRIPL Filter Clock Control Register         //offset 2E ,sub_offset 2
    union   CTRIPHFILCTL_REG                 CTRIPHFILCTL;                 // CTRIPH Filter Control Register               //offset 30 ,sub_offset 2
    uint16_t                                 CTRIPHFILCLKCTL;              // CTRIPH Filter Clock Control Register         //offset 32 ,sub_offset 2
    uint32_t                                 COMPLOCK;                     // CMPSS Lock Register 1.2                    //offset 34 ,sub_offset 4
    uint32_t 			                     CMPHSETUPTIME;                // High Comparator Setup Time  1.2              //offset 38 ,sub_offset 4
	union  CALIBOFFSETH_REG			         CALIBOFFSETH;                //High Comparator Calibration Register1.2           //offset 3C ,sub_offset 4
	uint32_t			                     CMPLSETUPTIME;               //Low Comparator Setup Time 1.2                  //offset 40 ,sub_offset 4
	union  CALIBOFFSETL_REG			         CALIBOFFSETL;                //Low Comparator Calibration Register 1.2        //offset 44 ,sub_offset 4
	union  ANACLKCFG_REG			         ANACLKCFG;     //ANACLK Signal Frequency and Phase Delay Configuration 1.2    //offset 48 ,sub_offset 4
	union  CALIBFSMSTATUS_REG			     CALIBFSMSTATUS;   // Calibration FSM Status Register 1.2                      //offset 4C ,sub_offset 4
	union  EPWMBLANKCTRL_REG			     EPWMBLANKCTRL;        //EPWMBLANK signal polarity configuration 1.2              //offset 50 ,sub_offset 4
	union  CMPDACCTRL_REG                    CMPDACCTRL;              //Analog comparator and inner DAC configuration 1.2  //offset 54 ,sub_offset4
	union  DBG_CFG_REG                       DBG_CFG;                  //Core Halt Signal Mask Configuration 1.2           //offset 5C ,sub_offset4
};




struct COMPDACCTL2_BITS {                // bits description
	uint16_t  rsvd1:8;              //7:0
	uint16_t  BLANKSOURCEUSEL:1;   //8   0: Selects EPWM1 to 16 as BLANK source for COMPH/L   1: Selects EPWM17 to 32 as BLANK source for COMPH/L
	uint16_t  rsvd2:1;             //9
	uint16_t  RAMPSOURCEUSEL:1;    //10
	uint16_t  rsvd3:5;             //15:11
};

union COMPDACCTL2_REG {
	uint16_t  all;
    struct  COMPDACCTL2_BITS  bit;
};





struct CMPDACCTRL_BITS{                             //2.2
	uint32_t     LPSOURCE:1;               // 0
	uint32_t     LCLOCKDELAY:2;           //2:1
	uint32_t     IDAC_LOFFSETTRIM:8;      //10:3  Low inner DAC Offset Trim
	uint32_t     rsvd1:5;                  //15:11
	uint32_t     HPSOURCE:1;             //16
	uint32_t     HCLOCKDELAY:2;          //18:17
	uint32_t     IDAC_HOFFSETTRIM:8;      //26:19 high inner DAC Offset Trim
	uint32_t     rsvd2:5;                //31:27

};
union CMPDACCTRL_REG{
	uint32_t 		 all;
	struct CMPDACCTRL_BITS   bit;
};
struct CMPDAC_INL_TRIM_BITS{
	uint32_t     DAC_L_INL_TRIM:16;     //15:0  Low comparator inner DAC trim value
	uint32_t     DAC_H_INL_TRIM:16;     //31:16  HIGH comparator inner DAC trim value
};
union CMPDAC_INL_TRIM_REG{
	uint32_t 		 all;
		struct CMPDAC_INL_TRIM_BITS   bit;
};
struct DBG_CFG_BITS{
	uint32_t    ARM_MASK:1;        //0
	uint32_t    DSP0_MASK:1;         //1
	uint32_t    DSP1_MASK:1;         //2
	uint32_t	rsvd1:30;        //31:3
};
union DBG_CFG_REG{
	uint32_t 		 all;
	struct DBG_CFG_BITS   bit;
};



// CMPSS Register Definitions:

struct CMPSS_REGS {
    union   COMPCTL_REG                      COMPCTL;                      // CMPSS Comparator Control Register            //offset 0 ,sub_offset 2
    union   COMPHYSCTL_REG                   COMPHYSCTL;                   // CMPSS Comparator Hysteresis Control Register //offset 2 ,sub_offset 2
    union   COMPSTS_REG                      COMPSTS;                      // CMPSS Comparator Status Register             //offset 4 ,sub_offset 2
    union   COMPSTSCLR_REG                   COMPSTSCLR;                   // CMPSS Comparator Status Clear Register       //offset 6 ,sub_offset 2
    union   COMPDACCTL_REG                   COMPDACCTL;                   // CMPSS DAC Control Register                   //offset 8 ,sub_offset 2
    union   COMPDACCTL2_REG                  COMPDACCTL2;                  //CMPSS inner DAC Control Register 2   2.2      //offset A ,sub_offset 2
    union   DACHVALS_REG                     DACHVALS;                     // CMPSS High DAC Value Shadow Register         //offset C ,sub_offset 2
    union   DACHVALA_REG                     DACHVALA;                     // CMPSS High DAC Value Active Register         //offset E ,sub_offset 2
    uint16_t                                   RAMPMAXREFA;                  // CMPSS Ramp Max Reference Active Register   //offset 10 ,sub_offset 2
    uint16_t                                   rsvd1;                        // Reserved                                   //offset 12 ,sub_offset 2
    uint16_t                                   RAMPMAXREFS;                  // CMPSS Ramp Max Reference Shadow Register   //offset 14 ,sub_offset 2
    uint16_t                                   rsvd2;                        // Reserved                                   //offset 16 ,sub_offset 2
    uint16_t                                   RAMPDECVALA;                  // CMPSS Ramp Decrement Value Active Register //offset 18 ,sub_offset 2
    uint16_t                                   rsvd3;                        // Reserved                                   //offset 1A ,sub_offset 2
    uint16_t                                   RAMPDECVALS;                  // CMPSS Ramp Decrement Value Shadow Register //offset 1C ,sub_offset 2
    uint16_t                                   rsvd4;                        // Reserved                                   //offset 1E ,sub_offset 2
    uint16_t                                   RAMPSTS;                      // CMPSS Ramp Status Register                 //offset 20 ,sub_offset 2
    uint16_t                                   rsvd5;                        // Reserved                                   //offset 22 ,sub_offset 2
    union   DACLVALS_REG                     DACLVALS;                     // CMPSS Low DAC Value Shadow Register          //offset 24 ,sub_offset 2
    union   DACLVALA_REG                     DACLVALA;                     // CMPSS Low DAC Value Active Register          //offset 26 ,sub_offset 2
    union   RAMPDLYA_REG                     RAMPDLYA;                     // CMPSS Ramp Delay Active Register             //offset 28 ,sub_offset 2
    union   RAMPDLYS_REG                     RAMPDLYS;                     // CMPSS Ramp Delay Shadow Register             //offset 2A ,sub_offset 2
    union   CTRIPLFILCTL_REG                 CTRIPLFILCTL;                 // CTRIPL Filter Control Register               //offset 2C ,sub_offset 2
    uint16_t                                 CTRIPLFILCLKCTL;              // CTRIPL Filter Clock Control Register         //offset 2E ,sub_offset 2
    union   CTRIPHFILCTL_REG                 CTRIPHFILCTL;                 // CTRIPH Filter Control Register               //offset 30 ,sub_offset 2
    uint16_t                                 CTRIPHFILCLKCTL;              // CTRIPH Filter Clock Control Register         //offset 32 ,sub_offset 2
    uint32_t                                 COMPLOCK;                     // CMPSS Lock Register                    //offset 34 ,sub_offset 4
    uint32_t 			                     CMPHSETUPTIME;                // High Comparator Setup Time               //offset 38 ,sub_offset 4
	union  CALIBOFFSETH_REG			         CALIBOFFSETH;                //High Comparator Calibration Register          //offset 3C ,sub_offset 4
	uint32_t			                     CMPLSETUPTIME;               //Low Comparator Setup Time                   //offset 40 ,sub_offset 4
	union  CALIBOFFSETL_REG			         CALIBOFFSETL;                //Low Comparator Calibration Register         //offset 44 ,sub_offset 4
	union  ANACLKCFG_REG			         ANACLKCFG;     //ANACLK Signal Frequency and Phase Delay Configuration     //offset 48 ,sub_offset 4
	union  CALIBFSMSTATUS_REG			     CALIBFSMSTATUS;   // Calibration FSM Status Register                      //offset 4C ,sub_offset 4
	union  EPWMBLANKCTRL_REG			     EPWMBLANKCTRL;        //EPWMBLANK signal polarity configuration               //offset 50 ,sub_offset 4
	union  CMPDACCTRL_REG                    CMPDACCTRL;              //Analog comparator and inner DAC configuration   //offset 54 ,sub_offset4
	union  CMPDAC_INL_TRIM_REG               CMPDAC_INL_TRIM;           //Analog comparator inner DAC trim configuration 2.2   //offset 58 ,sub_offset4
	union  DBG_CFG_REG                       DBG_CFG;                  //Core Halt Signal Mask Configuration           //offset 5C ,sub_offset4
};




struct COMPDACHCTL_BITS {                // bits description
	uint16_t DACSOURCE:1;                 // 0 DAC Source Control
	uint16_t RAMPSOURCE:4;                // 4:1 Ramp Generator Source Control
	uint16_t SELREF:1;                    // 5 DAC Reference Select
	uint16_t RAMPLOADSEL:1;               // 6 Ramp Load Select
	uint16_t SWLOADSEL:1;                 // 7 Software Load Select
	uint16_t BLANKSOURCE:4;               // 11:8 EPWMBLANK Source Select
	uint16_t BLANKEN:1;                   // 12 EPWMBLANK Enable
	uint16_t RAMPDIR:1;                     //�Ķ� 13 High Ramp Generator Direction control bit. 0 Decrementing Ramp.1 Incrementing Ramp.
	uint16_t FREESOFT:2;                  // 15:14 Free/Soft Emulation Bits
};
union COMPDACHCTL_REG{
	uint16_t  all;
    struct  COMPDACHCTL_BITS  bit;
};

struct COMPDACHCTL2_BITS {                // bits description
	uint16_t DEENABLE:1;                 // 0  Diode Emulation mode enable.
	uint16_t DEACTIVESEL:5;                // 5:1 DEACTIVE source select. This bit field determines whichEPWMn.DEACTIVE is passed on as the DEACTIVE signal.Where n represents the maximum number of EPWMDEACTIVEsignals available on the device:
	uint16_t rsvd1:2;                    //7:6
	uint16_t BLANKSOURCEUSEL:1;               // 8    0: Selects EPWM1 to 16 as BLANK source for COMPH 1: Selects EPWM17 to 32 as BLANK source for COMPH
	uint16_t rsvd2:1;                 // 9
	uint16_t RAMPSOURCEUSEL:1;               // 10    0: Selects EPWM1 to 16 as RAMP source for RAMPH 1: Selects EPWM17 to 32 as RAMP source for RAMPH
	uint16_t rsvd3:1;                   // 11
	uint16_t XTRIGCFG:2;                     // 13:12  High Ramp Generator Direction control bit. 0 Decrementing Ramp.1 Incrementing Ramp.
	uint16_t rsvd4:2;                  // 15:14
};
union COMPDACHCTL2_REG{
	uint16_t  all;
    struct  COMPDACHCTL2_BITS  bit;
};

struct DACHVALS_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACHVALS_REG {
	uint16_t  all;
    struct  DACHVALS_BITS  bit;
};


struct DACHVALA_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACHVALA_REG {
	uint16_t  all;
    struct  DACHVALA_BITS  bit;
};

struct DACLVALS_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACLVALS_REG {
	uint16_t  all;
    struct  DACLVALS_BITS  bit;
};

struct DACLVALA_BITS {                  // bits description
	uint16_t DACVAL:12;                   // 11:0 DAC Value Control
	uint16_t rsvd1:4;                     // 15:12 Reserved
};

union DACLVALA_REG {
	uint16_t  all;
    struct  DACLVALA_BITS  bit;
};


struct RAMPHDLYA_BITS {                  // bits description
	uint16_t DELAY:13;                    // 12:0 High ramp delay active value. Latched value of the number of cycles to delay the start of the ramp generator stepper after aEPWMSYNCPER is received.
	uint16_t rsvd1:3;                     // 15:13 Reserved
};

union RAMPHDLYA_REG {
	uint16_t  all;
    struct  RAMPHDLYA_BITS  bit;
};

struct RAMPHDLYS_BITS {                  // bits description
	uint16_t DELAY:13;                    // 12:0 High ramp delay shadow value. Unlatched value to be loaded into RAMPHDLYA.
	uint16_t rsvd1:3;                     // 15:13 Reserved
};

union RAMPHDLYS_REG {
	uint16_t  all;
    struct  RAMPHDLYS_BITS  bit;
};

struct CTRIPLFILCTL_BITS {              // bits description   111
	uint16_t FILTINSEL:3;                     // 2:0 0 Selects the COMPL output as the filter input 1 Selects the external signal EXT_FILTIN_L[1] as the filter input   7....
	uint16_t SAMPWIN:6;                   // 8:3 Low filter sample window size. Number of samples to monitor is SAMPWIN+1.
	uint16_t THRESH:6;                    // 14:9 Low filter majority voting threshold. At least THRESH samples of the opposite state must appear within the sample window in order for the output to change state. Threshold used is THRESH+1.
	uint16_t FILINIT:1;                      // 15 Filter Initialization Bit
};

union CTRIPLFILCTL_REG {
	uint16_t  all;
    struct  CTRIPLFILCTL_BITS  bit;
};

struct CTRIPHFILCTL_BITS {              // bits description      111111
	uint16_t FILTINSEL:3;                   // 2:0 Reserved
	uint16_t SAMPWIN:6;               // 8:3 Sample Window
	uint16_t THRESH:6;                      // 14:9 Majority Voting Threshold
    uint16_t FILINIT:1;                   // 15 Filter InQitialization Bit
};

union CTRIPHFILCTL_REG {
	uint16_t  all;
    struct  CTRIPHFILCTL_BITS  bit;
};
struct DACHVALS2_BITS{
	uint16_t DACVAL:12;                 //11:0High DAC shadow register2 value. WhenCOMPDACHCTL[DACSOURCE]=0, the value of DACHVALS2 isloaded into DACHVALA when DE mode is enabled and selectedDEACTIVE input is asserted.
	uint16_t rsvd1:4;                    //15:12
};
union  DACHVALS2_REG{
	uint16_t  all;
	struct DACHVALS2_BITS   bit;
};
struct DACLVALS2_BITS{
	uint16_t DACVAL:12;                 //11:0 Low DAC shadow register2 value. WhenCOMPDACLCTL[DACSOURCE]=0, the value of DACLVALS2 is loadedinto DACLVALA when DE mode is enabled and selected DEACTIVEinput is asserted.
	uint16_t rsvd1:4;                    //15:12
};
union  DACLVALS2_REG{
	uint16_t  all;
	struct DACLVALS2_BITS   bit;
};
struct COMPDACLCTL_BITS{
	uint16_t  DACSOURCE:1;   //0  0 DACLVALA is updated from DACLVALS  1 DACLVALA is updated from the low ramp generator
	uint16_t  RAMPSOURCE:4;   //4:1 0 EPWM1SYNCPER  1 EPWM2SYNCPER  2 EPWM3SYNCPER
	uint16_t  rsvd1:1;        //5
	uint16_t  RAMPLOADSEL:1;   //6
	uint16_t  rsvd2:1;       //7
	uint16_t  BLANKSOURCE:4;   //11:8   0 EPWM1BLANK  1 EPWM2BLANK   2 EPWM3BLANK
	uint16_t  BLANKEN:1;         //12   0 EPWMBLANK signal is disabled.  1 EPWMBLANK signal is enabled.
	uint16_t  RAMPDIR:1;       //13       0 Decrementing Ramp.  1 Incrementing Ramp.
	uint16_t  rsvd3:2;        //15:14
};
union COMPDACLCTL_REG{
	uint16_t  all;
	struct COMPDACLCTL_BITS  bit;
};


struct COMPDACLCTL2_BITS{
	uint16_t    rsvd1:8;             //7:0
	uint16_t    BLANKSOURCEUSEL:1;  //8  0: Selects EPWM1 to 16 as BLANK source for COMPL 1: Selects EPWM17 to 32 as BLANK source for COMPL
	uint16_t    rsvd2:1;             //9
	uint16_t    RAMPSOURCEUSEL:1;  //10  0: Selects EPWM1 to 16 as RAMP source for RAMPL    1: Selects EPWM17 to 32 as RAMP source for RAMPL
	uint16_t	rsvd3:5;         //15:11
};
union COMPDACLCTL2_REG{
	uint16_t  all;
	struct COMPDACLCTL2_BITS  bit;
};
struct RAMPLDLYA_BITS{
	uint16_t     DELAY:13;  //12:0  Low ramp delay active value. Latched value of the number of cycles to delay the start of the ramp generator stepper after a EPWMSYNCPER is received.
	uint16_t     rsvd1:3;       //15:13
};
union RAMPLDLYA_REG{
	uint16_t  all;
	struct RAMPLDLYA_BITS  bit;
};
struct RAMPLDLYS_BITS{
	uint16_t     DELAY:13;  //12:0  Low ramp delay shadow value. Unlatched value to be loaded into  RAMPLDLYA.
	uint16_t     rsvd1:3;       //15:13
};
union  RAMPLDLYS_REG{
	uint16_t  all;
	struct RAMPLDLYS_BITS  bit;
};
struct CALIBOFFSETH_BITS{
	uint32_t     CALIBOFFSETH:13;     //12:0 High Comparator Offset ValueContains the offset value after the calibration is done.The 13th bit is the sign bit, so the value in this register falls in the range of (-4096, 4095)
	uint32_t     OFFSETHEN:1;         //13  1. apply the offset on the DAC value   2. don't apply the offset on the DAC value
	uint32_t     CAL_START_H:1;         //14   High Compartor Calibration StartWrite a '1' to this bit to start the calibration process.
	uint32_t     rsvd1:17;            //31:15
};
union  CALIBOFFSETH_REG{
	uint32_t 		 all;
	struct   CALIBOFFSETH_BITS  bit;
};
struct CALIBOFFSETL_BITS{
	uint32_t     CALIBOFFSETL:13;   //12:0 Low Comparator Offset ValueContains the offset value after the calibration is done.The 13th bit is the sign bit, so the value in this register falls in the range of (-4096, 4095)
	uint32_t     OFFSETLEN:1;    //13 Low Comparator Offset EnableConfigure if the DAC value, either from DACHVALS or from ramp_gen, should apply the offset before sending out to analog part.1. apply the offset on the DAC value2. don't apply the offset on the DAC value
	uint32_t     CAL_START_L:1;  //14   Low Calibration StartWrite a '1' to this bit to start the calibration process.
	uint32_t     rsvd1:17;     //31:15
};
union CALIBOFFSETL_REG{
	uint32_t   all;
	struct CALIBOFFSETL_BITS  bit;
};
struct ANACLKCFG_BITS{
	uint32_t     ANACLKDIV:16;     //15:0ANACLK period configuration ����anaclk�ķ�Ƶϵ����anaclk��clk_sys��Ƶ�õ�����������Ϊ���з����ż������;����ʵ�ֲ�֧��������Ƶ������������Ƶ�����ڲ��Զ���Ϊ-1���ż����Ƶ 0h = reserved 2h = Divide by 2 4h = Divide by 4
	uint32_t     ANACLKPHADLY:16;   //16:31 ANACLK phase delay configuration����anaclk�����������DACֵ�仯��ʱ���ӳٶ��ٸ�clk_sys���ڽ�������ֵ��ΧΪ[0, anaclkdiv��
};

union  ANACLKCFG_REG{
	uint32_t       all;
	struct ANACLKCFG_BITS  bit;
};
struct CALIBFSMSTATUS_BITS{
	uint32_t     CMPL_FSM_STATUS:8;     //7:0 01: IDLE 8'h02: DEC_DACVAL8'h04: WAIT_CMP8'h10: CLR_LATCH8'h20: EN_LATCH8'h40: CHECKother values: illegal valueFor debug purpose
	uint32_t     CMPH_FSM_STATUS:8;     //15:8   High Comparator Calibration Current FSM State Value: 8'h01: IDLE8'h02: DEC_DACVAL8'h04: WAIT_CMP8'h10: CLR_LATCH8'h20: EN_LATCH8'h40: CHECKother values: illegal valueFor debug purpose
	uint32_t     rsvd1:16;           //31:16
};
union CALIBFSMSTATUS_REG{
	uint32_t   all;
	struct CALIBFSMSTATUS_BITS  bit;
};
struct EPWMBLANKCTRL_BITS{
	uint32_t       BLANK_INV:1;     //0 0: when EPWMBLANK is low, the synchronizer/digital filter/latch will keep reset. 1: when EPWMBLANK is high, the synchronizer/digital filter/latch will keep reset.
	uint32_t       rsvd1:31;         //31:1

};
union EPWMBLANKCTRL_REG{
	uint32_t  all;
	struct EPWMBLANKCTRL_BITS  bit;
};
struct CMPDACCTRL_BITS{
	uint32_t      rsvd1:1;     //0
	uint32_t      LCLOCKDELAY:2;  //2:1  Low inner  DAC INPUT CLOCK
	uint32_t      rsvd2:14;       //16:3
	uint32_t      HCLOCKDELAY:2;    //18:17   High inner INPUT CLOCK
	uint32_t      rsvd3:13;      //31:19
};
union CMPDACCTRL_REG{
	uint32_t  all;
	struct CMPDACCTRL_BITS  bit;
};
struct DBG_CFG_BITS{
	uint32_t      rsvd1:1;    //0
	uint32_t      DSP0_MASK:1;  //1  Configure if the emulation behavior controled by DSP0 1: ignore the stop signal from DSP0 0: internal counter will behave as expected when it sees stop signal from DSP0
	uint32_t      rsvd2:1;      //2
	uint32_t      rsvd3:29;     //31:3
};
union DBG_CFG_REG{
	uint32_t     all;
	struct DBG_CFG_BITS   bit;

};
struct COMPHYSTCTL_TYPE0_BITS{
	uint32_t         COMPH_HYST_DISABLE:1;    //0  High Comparator Hysteresis disable.  0: Hysteresis enabled
	uint32_t         COMPL_HYST_DISABLE:1;     //1  Low Comparator Hysteresis disable. 0: Hysteresis enabled 1: Hysteresis disabled
	uint32_t         rsvd1:30;     //31:2
};
union COMPHYSTCTL_TYPE0_REG{
	uint32_t   all;
	struct COMPHYSTCTL_TYPE0_BITS   bit;
};
struct CMPDACEN_BITS{
	uint32_t          CMP_DACL_EN:1;   //0    Comparator DACL enable 0: Comparator DACL disable 1: Comparator DACL enable
	uint32_t          CMP_DACH_EN:1;    //1   Comparator DACH enable 0: Comparator DACH disable 1: Comparator DACH enable
	uint32_t          rsvd1:30;     //31:2
};
union CMPDACEN_REG{
	uint32_t   all;
	struct CMPDACEN_BITS  bit;

};




struct CMPSS_REGS {
    union   COMPCTL_REG                      COMPCTL;                      // CMPSS Comparator Control Register            //offset 0 ,sub_offset 2
    union   COMPHYSCTL_REG                   COMPHYSCTL;                   // CMPSS Comparator Hysteresis Control Register //offset 2 ,sub_offset 2
    union   COMPSTS_REG                      COMPSTS;                      // CMPSS Comparator Status Register             //offset 4 ,sub_offset 2
    union   COMPSTSCLR_REG                   COMPSTSCLR;                   // CMPSS Comparator Status Clear Register       //offset 6 ,sub_offset 2
    union   COMPDACHCTL_REG                  COMPDACHCTL;                  // CMPSS DAC Control Register                   //offset 8 ,sub_offset 2
    union   COMPDACHCTL2_REG                 COMPDACHCTL2;                 // Ramp Generator Cross Trigger Configuration   //offset A ,sub_offset 2
    union   DACHVALS_REG                     DACHVALS;                     // CMPSS High DAC Value Shadow Register         //offset C ,sub_offset 2
    union   DACHVALA_REG                     DACHVALA;                     //CMPSS High DAC Value Active Register          //offset E ,sub_offset 2
    uint16_t                                   RAMPHREFA;                  //CMPSS Ramp Max Reference Active Register     //offset 10 ,sub_offset 2
    uint16_t                                   rsvd1;                      // Reserved                                   //offset 12 ,sub_offset 2
    uint16_t                                   RAMPHREFS;                  // CMPSS Ramp Max Reference Shadow Register   //offset 14 ,sub_offset 2
    uint16_t                                   rsvd2;                      // Reserved                                   //offset 16 ,sub_offset 2
   uint16_t                                   RAMPHSTEPVALA;               // CMPSS Ramp Decrement Value Active Register //offset 18 ,sub_offset 2
   uint16_t                                   RAMPHCTLA;                   // Ramp High Clock Divider Active Value        //offset 1A ,sub_offset 2
    uint16_t                                  RAMPHSTEPVALS;               //CMPSS Ramp Decrement Value Shadow Register   //offset 1C ,sub_offset 2
    uint16_t                                  RAMPHCTLS;                   //Ramp High Clock Divider Shadow Value         //offset 1E ,sub_offset 2
    uint16_t                                   RAMPHSTS;                   //CMPSS Ramp Status Register                   //offset 20 ,sub_offset 2
    uint16_t                                   rsvd3;                      // Reserved
    union   DACLVALS_REG                     DACLVALS;                     // CMPSS Low DAC Value Shadow Register          //offset 24 ,sub_offset 2
    union   DACLVALA_REG                     DACLVALA;                     //CMPSS Low DAC Value Active Register          //offset 26 ,sub_offset 2
    union   RAMPHDLYA_REG                     RAMPHDLYA;                   // CMPSS Ramp Delay Active Register             //offset 28 ,sub_offset 2
    union   RAMPHDLYS_REG                     RAMPHDLYS;                   // CMPSS Ramp Delay Shadow Register             //offset 2A ,sub_offset 2
    union   CTRIPLFILCTL_REG                 CTRIPLFILCTL;                 //CTRIPL Filter Control Register                //offset 2C ,sub_offset 2
    uint16_t                                 CTRIPLFILCLKCTL;              //CTRIPL Filter Clock Control Register         //offset 2E ,sub_offset 2
    union   CTRIPHFILCTL_REG                 CTRIPHFILCTL;                 //CTRIPH Filter Control Register               //offset 30 ,sub_offset 2
    uint16_t                                 CTRIPHFILCLKCTL;              //CTRIPH Filter Clock Control Register         //offset 32 ,sub_offset 2
    uint32_t                                 COMPLOCK;                   //CMPSS Lock Register                          //offset 34 ,sub_offset 4
    uint16_t                                  rsvd4;                      // Reserved
    union  DACHVALS2_REG                     DACHVALS2;                   //    High DAC shadow register2                   //offset 38 ,sub_offset 2
    union  DACLVALS2_REG                     DACLVALS2;                   //    Low DAC shadow register2                   //offset 3A ,sub_offset 2
    uint16_t                                   rsvd5[6];                     // Reserved
    union  COMPDACLCTL_REG                   COMPDACLCTL;                 //    CMPSS Low DAC Control Register            //offset 48 ,sub_offset 2
    union  COMPDACLCTL2_REG                  COMPDACLCTL2;                //   CMPSS Low DAC Control Register 2          //offset 4A ,sub_offset 2
    uint16_t                                   rsvd6[2];                     // Reserved
    uint16_t                                 RAMPLREFA;                   //     CMPSS Low Ramp Reference Active Register   //offset 50 ,sub_offset 2
    uint16_t                                   rsvd7;                        // Reserved
    uint16_t                                 RAMPLREFS;                   //    CMPSS Low Ramp Reference Shadow Register   //offset 54 ,sub_offset 2
    uint16_t                                   rsvd8;                        // Reserved
    uint16_t                                 RAMPLSTEPVALA;              //     CMPSS Low Ramp Step Value Active Register  //offset 58 ,sub_offset 2
    uint16_t                                 RAMPLCTLA;                  //     CMPSS Low Ramp Control Active Register     //offset 5A ,sub_offset 2
	uint16_t                                 RAMPLSTEPVALS;              //   CMPSS Low Ramp Step Value Shadow Register  //offset 5C ,sub_offset 2
	uint16_t                                 RAMPLCTLS;                  // CMPSS Low Ramp Control Active Register     //offset 5E ,sub_offset 2
	uint16_t                                 RAMPLSTS;                   //    CMPSS Low Ramp Status Register             //offset 60 ,sub_offset 2
	uint16_t                                   rsvd9[3];                     // Reserved
	union  RAMPLDLYA_REG                     RAMPLDLYA;                  //   CMPSS Low Ramp Delay Active Register       //offset 68 ,sub_offset 2
	union  RAMPLDLYS_REG                     RAMPLDLYS;                  //  CMPSS Low Ramp Delay Shadow Register       //offset 6A ,sub_offset 2
	uint16_t                                  rsvd10;                   // Reserved
	uint16_t                                 CTRIPLFILCLKCTL2;          //   CTRIPL Filter Clock Control Register 2     //offset 6E ,sub_offset 2
	uint16_t                                 rsvd11;                       // Reserved
	uint16_t                                 CTRIPHFILCLKCTL2;          //   CTRIPH Filter Clock Control Register 2     //offset 72 ,sub_offset 2
	uint32_t                                 CMPHSETUPTIME;             //    High Comparator Setup Time                 //offset 100 ,sub_offset 4
    union  CALIBOFFSETH_REG                  CALIBOFFSETH;              //     High Comparator Calibration Register       //offset 104 ,sub_offset 4
    uint32_t                                 CMPLSETUPTIME;             //     Low Comparator Setup Time                  //offset 108 ,sub_offset 4
    union  CALIBOFFSETL_REG                  CALIBOFFSETL;              //    Low Comparator Calibration Register        //offset 10C ,sub_offset 4
    union  ANACLKCFG_REG                     ANACLKCFG;                 //  ANACLK Signal Frequency and Phase Delay Configuration  //offset 110 ,sub_offset 4
    union  CALIBFSMSTATUS_REG                CALIBFSMSTATUS;            //    Calibration FSM Status Register                 //offset 110 ,sub_offset 4
    union  EPWMBLANKCTRL_REG                 EPWMBLANKCTRL;             //         EPWMBLANK signal polarity configuration    //offset 118 ,sub_offset 4
    union  CMPDACCTRL_REG                    CMPDACCTRL;                //           Analog comparator and inner DAC configuration  //offset 11C ,sub_offset 4
    union  DBG_CFG_REG                       DBG_CFG;                   //          Core Halt Signal Mask Configuration          //offset 124 ,sub_offset 4
    union  COMPHYSTCTL_TYPE0_REG             COMPHYSTCTL_TYPE0;         //         Comparator Hysteresis Control Register       //offset 128 ,sub_offset 4
    union  CMPDACEN_REG                      CMPDACEN;                  //      CMPSS DACL Enable                             //offset 12C,sub_offset 4
};



/* ========================================================================== */
/*                            Global Constants                                */
/* ========================================================================== */

//COMPCTL Register

#define COMPHSOURCE_INTERN_DAC  0
#define COMPHSOURCE_EXTERN_PIN  1
#define COMPLSOURCE_INTERN_DAC  0
#define COMPLSOURCE_EXTERN_PIN  1

//COMPDACCTL Register
#define UPDATE_FORM_DACHVALS 0
#define UPDATE_FORM_RAMP_GENERATOR 1

#define DACREF_VDDA_ENABLE 0
#define DACREF_VDAC_ENABLE 1

#define UPDATE_DACxVALS_SYSCLK 0
#define UPDATE_DACxVALS_EPWMSYNCPER 1

#define TRIP_ASYNCHRONOUS_COMP 0
#define TRIP_SYNCHRONOUS_COMP 1
#define TRIP_DIGITAL_FILTER_OUTPUT 2
#define TRIP_DIGITAL_FILTER_OUTPUT_LATCH 3

#define TRIPOUT_ASYNCHRONOUS_COMP 0
#define TRIPOUT_SYNCHRONOUS_COMP 1
#define TRIPOUT_DIGITAL_FILTER_OUTPUT 2
#define TRIPOUT_DIGITAL_FILTER_OUTPUT_LATCH 3


#define CMPSS_RAMPLOADSEL_DISABLE 0
#define CMPSS_RAMPLOADSEL_ENABLE 1

#define EPWMBLANK_DISABLE 0
#define EPWMBLANK_ENABLE 1
//COMPSTSCLR Register
#define EPWMSYNCPER_NOT_RESET_LATCH 0
#define EPWMSYNCPER_RESET_LATCH 1

#define EPWM_TZ_FLAG   1

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
// CMPSS External References & Function Declarations

extern volatile struct CMPSS_REGS cmpssRegs;



#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of REGS_CMPSS_H definition
