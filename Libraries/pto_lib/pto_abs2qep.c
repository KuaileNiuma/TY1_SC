/** 
  *************************************************************************************
  * @file pto_abs2qep.c 
  * @author Albatross 
  * @brief This file contains the source file. 
  * @version 1.0.0 
  * @date 2025-07-30 
  *************************************************************************************
  * @copyright Copyright (c) 2025 Albatross  Semiconductor( Hangzhou ) Co ., Ltd . 
  * BSD-3-Clause License 
  * 
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted provided that the following conditions are met: 
  * 
  * 1. Redistributions of source code must retain the above copyright notice, this 
  *    list of conditions and the following disclaimer. 
  * 
  * 2. Redistributions in binary form must reproduce the above copyright notice, 
  *    this list of conditions and the following disclaimer in the documentation 
  *    and/or other materials provided with the distribution. 
  * 
  * 3. Neither the name of the copyright holder nor the names of its 
  *    contributors may be used to endorse or promote products derived from 
  *    this software without specific prior written permission. 
  * 
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
  ************************************************************************************
  */
//
// Included Files
//
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "pto_abs2qep.h"
#include "clb.h"
#include "xbar.h"
#include "device.h"

//
// Globals
//


//*****************************************************************************
//
//! Initialize the CLB XBAR-connect
//!
//! \param None
//!
//! This function configures Output-XBars to route CLB outputs to GPIO pins
//!
//! \return None
//
//*****************************************************************************
void
pto_abs2qep_initCLBXBAR(void)
{
    //
    // PTO-QEP-A output
    //
    XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT1, XBAR_OUT_MUX05_CLB1_OUT5);
    XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT1, XBAR_MUX05);

    //
    // PTO-QEP-B output
    //
    XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT2, XBAR_OUT_MUX06_CLB1_OUT6);
    XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT2, XBAR_MUX06);
    //
    // PTO-QEP-I output
    //
    XBAR_setOutputMuxConfig(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT3, XBAR_OUT_MUX03_CLB1_OUT3);
    XBAR_enableOutputMux(CLBOUTPUTXBAR_BASE,XBAR_OUTPUT3, XBAR_MUX03);


}

//*****************************************************************************
//
//! Setup CLB tiles
//!
//! \param None
//!
//! Setup the CLB and other interconnect XBARs used in this application.
//! This is called during the CLB initialization.
//!
//! \return None
//
//*****************************************************************************
void
pto_abs2qep_setupPeriph(void)
{
    //
    // The init of the tile must be done first. This
    // will configure the whole tile, including the
    // HLC program.
    //
    // When enabled, the HLC will receive a rising edge
    // on the e2 input. This corresponds to the end
    // of a PTO, and will set the expected INTERRUPT
    // TAG.
    //
    initTILE1(CLB1_BASE);


    //
    // Unused Inputs below
    //
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_EPWM1A);

    //
    // Inputs set to GP register
    //
    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);


    //
    // Unused inputs to GP register
    //
    CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_GP_REG);

    CLB_selectInputFilter(CLB1_BASE, CLB_IN0, CLB_FILTER_RISING_EDGE);
    //
    // Initialize the CLB XBAR
    //
    pto_abs2qep_initCLBXBAR();

    //
    // OUT2 (QEP-I) overrides PWM1B
    // OUT0 (RUN/HALT) overrides PWM1A
    //

    //
    // Sending a position 0 will setup the CLB
    // modules and set the interrupt tag to indicate
    // a PTO is not running.
    //
    pto_abs2qep_translatePosition(0);
    pto_abs2qep_runPulseGen(PTO_ABS2QEP_CLOCKWISE_PTO);
}

//*****************************************************************************
//
//! Start the PTO Generation
//!
//! \param pto_direction is either forward (PTO_ABS2QEP_CLOCKWISE_PTO) 
//!        or reverse (PTO_ABS2QEP_COUNTERCLOCKWISE_PTO)
//!
//! This function confirms that the previous PTO has completed and then
//! triggers the load event to the HLC
//!
//! pto_abs2qep_translatePostion() must be called before this function
//! to load the HLC pullData FIFO
//!
//!
//! \return None
//
//*****************************************************************************

void pto_abs2qep_runPulseGen(uint16_t pto_direction)
{

    // Confirm that the previous PTO has completed
    // Start the load of a new configuration
    // Set the direction appropriately
    //
    // The GPIO is a visual marker for the start and
    // direction of the QEP-A/B signals and can be 
    // removed in an application
    //

	CLB_enableCLB(CLB1_BASE);
	// CNT1.MATCH1=0xFFFFFFFF
	// CNT1.MATCH2=0              --- PTO_DONE, HALT,INTR=2,
	CLB_configCounterLoadMatch(CLB1_BASE, CLB_CTR1, TILE1_COUNTER_0_LOAD_VAL, 0xFFFFFFFF, 0);
	// CNT1.MATCH1=0              --- CLEAR LATCH,RUN,
	// CNT1.MATCH2=0xFFFFFFFF     --- PTO_DONE,
    CLB_configCounterLoadMatch(CLB1_BASE, CLB_CTR1, TILE1_COUNTER_0_LOAD_VAL, 0, 0xFFFFFFFF);

//    while(CLB_getInterruptTag(CLB1_BASE) != PTO_ABS2QEP_PTO_DONE_TAG )
//    {
//    }
    CLB_setGPREG(CLB1_BASE, 0);
    CLB_clearInterruptTag(CLB1_BASE);
    if(pto_direction == PTO_ABS2QEP_CLOCKWISE_PTO)
    {
        CLB_setGPREG(CLB1_BASE, PTO_ABS2QEP_SET_CLOCKWISE |                    \
                     PTO_ABS2QEP_SET_LOAD);
        GPIO_writePin(PTO_ABSQEP_TEST_PIN_1, 1);
        CLB_setGPREG(CLB1_BASE,2);
    }
    else
    {
        CLB_setGPREG(CLB1_BASE, PTO_ABS2QEP_SET_COUNTERCLOCKWISE |             \
                     PTO_ABS2QEP_SET_LOAD);
        GPIO_writePin(PTO_ABSQEP_TEST_PIN_1, 0);
    }

}

//*****************************************************************************
//
//! Translate a change in absolute position to QEP pulses
//!
//! \param  PositionNew is the new absolute position
//!
//! This function calculates the delta from the previous position and
//! translates it to an equivalent number of QCLKs needed to generate
//! QEP-A, QEP-B and QEP-I.
//!
//! The HLC FIFO is loaded with the configuration.
//!
//! \return None
//
//*****************************************************************************

uint16_t
pto_abs2qep_translatePosition(uint32_t positionNew)
{
    uint16_t numQclkSend;
    uint16_t ptoDirection;
    int32_t  positionDelta;
    uint32_t indexHighEdge;
    uint16_t pulseWidth;
    float32_t numQclkFloat;
    float32_t numQclkFrac;
    int16_t numQclkAdjust;
    static float32_t numQclkTotalFrac = 0.0f;
    static float32_t numQclkCarry = 0.0f;
    static uint32_t positionPrevious = 0ul;
    static uint32_t positionCurrent = 0ul;
    float32_t numQclkInt;
    bool positionZeroCross;

    //
    // Uncomment the following to halt the CLB on a CPU halt.
    // EALLOW;
    // HWREG(CLB1_BASE + CLB_LOGICCTL + CLB_O_LOAD_EN) |= CLB_LOAD_EN_STOP;
    // EDIS;
    //
    //
    // Archive old absolute position
    // Find the delta between old and current position
    // Determine if change in position crosses the absolute zero position
    //
    positionPrevious = positionCurrent;
    positionCurrent = positionNew;
    positionDelta = positionCurrent - positionPrevious;

    //
    // Check if absolute zero is crossed over during the position delta
    // If so, adjust the calculations for the delta position value to
    // account for crossover.
    // Calculate the delta in two parts as described in the
    // user's guide.
    // Calculate the match 1 and match2 values that will
    // be used in counter 2 to generate the QEP index signal
    //
    positionZeroCross = labs(positionDelta) >
                   (PTO_ABS2QEP_ABS_MAX_DELTA_PER_SAMPLE) ? true : false;

    if(positionZeroCross)
    {
        //
        // Crossed zero in the reverse direction
        // Change sign to indicate reverse
        //
        if(positionDelta > 0)
        {
            positionDelta = -1 *
                    (int32_t)((positionPrevious - 0) +
                         (PTO_ABS2QEP_ABS_MAX_POSITION - positionCurrent));
            indexHighEdge =
                    (int32_t)(positionPrevious * PTO_ABS2QEP_ABS_TO_INCR);
        }
        else
        {
            positionDelta =
                    (int32_t)((PTO_ABS2QEP_ABS_MAX_POSITION -
                                positionPrevious) +
                                positionCurrent);
            indexHighEdge =
                    (int32_t)((PTO_ABS2QEP_ABS_MAX_POSITION -
                                positionPrevious) *
                                PTO_ABS2QEP_ABS_TO_INCR);
        }
    }
    //
    // If zero was not crossed, use a large value so the match never occurs.
    //
    else
    {
        indexHighEdge = 0xFFFFFFFE;
    }
    //
    // Check to see if the QEP index signal occurs at 0
    // If it does, offset by 1 so it is not missed.
    //

    if(indexHighEdge == 0)
    {
        indexHighEdge += 1;
    }
    //
    // Calculate the number of QCLKs based on the delta
    // between the old and new absolute encoder positions.
    //
    // Determine the integer and fractional number of pulses.
    // If the accumulated fractional portion is > 1 or < -1,
    // increase the integer number of pulses by 1.
    //
    numQclkFloat = positionDelta * PTO_ABS2QEP_ABS_TO_INCR;
    numQclkFrac = modff(numQclkFloat, &numQclkInt);

    numQclkTotalFrac = numQclkCarry + numQclkFrac;

    if(numQclkTotalFrac >= 1.0f)
    {
        numQclkAdjust = 1;
    }
    else if(numQclkTotalFrac <= -1.0f)
    {
        numQclkAdjust = -1;
    }
    else
    {
        numQclkAdjust = 0;
    }
    numQclkCarry = numQclkTotalFrac - numQclkAdjust;
    numQclkSend = abs( (int16_t)numQclkInt + numQclkAdjust);

    //
    // Calculate the PTO pulse width in CLB clocks (width of each pulse)
    //
    // For the zero pulse case, set the width to a non-zero value. This
    // will prevent the pulse width generation CLB counter from issuing
    // a match1 signal before the CLB is halted.
    //

    if(numQclkSend != 0)
    {
        pulseWidth = (PTO_ABS2QEP_SAMPLING_RATIO / numQclkSend);
    }
    else
    {
        pulseWidth = 0xFFFF;
    }

    //
    // Write the updated counter match values to the FIFO
    //
    uint32_t bufferFIFO[4];
    bufferFIFO[0] = (uint32_t)numQclkSend;            // COUNTER 1 MATCH 2
    bufferFIFO[1] = (uint32_t)pulseWidth;             // COUNTER 0 MATCH 1
    bufferFIFO[2] = indexHighEdge;                    // COUNTER 2 MATCH 1
    bufferFIFO[3] = indexHighEdge + 1U;                 // COUNTER 2 MATCH 2

    CLB_setHLCRegisters(CLB1_BASE, numQclkSend,pulseWidth,indexHighEdge,indexHighEdge + 1U);

    //
    // Log the direction information for when the PTO is
    // started by the application
    //

    if(positionDelta > 0)
    {
        ptoDirection = PTO_ABS2QEP_CLOCKWISE_PTO;
    }
    else
    {
        ptoDirection = PTO_ABS2QEP_COUNTERCLOCKWISE_PTO;

    }
    return(ptoDirection);
}

const uint32_t TILE1_HLC_initFIFOData[4] = {TILE1_HLC_FIFO0_INIT, TILE1_HLC_FIFO1_INIT, TILE1_HLC_FIFO2_INIT, TILE1_HLC_FIFO3_INIT};

uint16_t TILE1HLCInstr[CLB_NUM_HLC_INSTR + 1] =
{
    TILE1_HLCINSTR_0,
    TILE1_HLCINSTR_1,
    TILE1_HLCINSTR_2,
    TILE1_HLCINSTR_3,
    TILE1_HLCINSTR_4,
    TILE1_HLCINSTR_5,
    TILE1_HLCINSTR_6,
    TILE1_HLCINSTR_7,
    TILE1_HLCINSTR_8,
    TILE1_HLCINSTR_9,
    TILE1_HLCINSTR_10,
    TILE1_HLCINSTR_11,
    TILE1_HLCINSTR_12,
    TILE1_HLCINSTR_13,
    TILE1_HLCINSTR_14,
    TILE1_HLCINSTR_15,
    TILE1_HLCINSTR_16,
    TILE1_HLCINSTR_17,
    TILE1_HLCINSTR_18,
    TILE1_HLCINSTR_19,
    TILE1_HLCINSTR_20,
    TILE1_HLCINSTR_21,
    TILE1_HLCINSTR_22,
    TILE1_HLCINSTR_23,
    TILE1_HLCINSTR_24,
    TILE1_HLCINSTR_25,
    TILE1_HLCINSTR_26,
    TILE1_HLCINSTR_27,
    TILE1_HLCINSTR_28,
    TILE1_HLCINSTR_29,
    TILE1_HLCINSTR_30,
    TILE1_HLCINSTR_31
};



void initTILE1(uint32_t base)
{
    uint16_t i;
    //
    //  Output LUT
    //
    //
    //  Equation for Output Look-Up Table Block 0 for TILE1: i0
    //
    CLB_configOutputLUT(base, CLB_OUT0, TILE1_CFG_OUTLUT_0);

    CLB_configOutputLUT(base, CLB_OUT1, TILE1_CFG_OUTLUT_1);

    //
    //  Equation for Output Look-Up Table Block 2 for TILE1: i0
    //
    //
    //  User Description for Output Look-Up Table 2 for TILE1
    /*
        PTO_QEP_I
    */
    //
    CLB_configOutputLUT(base, CLB_OUT2, TILE1_CFG_OUTLUT_2);

    //
    //  Equation for Output Look-Up Table Block 3 for TILE1: 0
    //
    CLB_configOutputLUT(base, CLB_OUT3, TILE1_CFG_OUTLUT_3);

    //
    //  Equation for Output Look-Up Table Block 4 for TILE1: i0
    //
    //
    //  User Description for Output Look-Up Table 4 for TILE1
    /*
        PTO_QEP_A
    */
    //
    CLB_configOutputLUT(base, CLB_OUT4, TILE1_CFG_OUTLUT_4);

    //
    //  Equation for Output Look-Up Table Block 5 for TILE1: i0
    //
    //
    //  User Description for Output Look-Up Table 5 for TILE1
    /*
        PTO_QEP_B
    */
    //
    CLB_configOutputLUT(base, CLB_OUT5, TILE1_CFG_OUTLUT_5);
    
    CLB_configOutputLUT(base, CLB_OUT6, TILE1_CFG_OUTLUT_6);

    CLB_configOutputLUT(base, CLB_OUT7, TILE1_CFG_OUTLUT_7);

    //
    //  AOC
    //
    CLB_configAOC(base, CLB_AOC0, TILE1_OUTPUT_COND_CTR_0);
    CLB_configAOC(base, CLB_AOC1, TILE1_OUTPUT_COND_CTR_1);
    CLB_configAOC(base, CLB_AOC2, TILE1_OUTPUT_COND_CTR_2);
    CLB_configAOC(base, CLB_AOC3, TILE1_OUTPUT_COND_CTR_3);
    CLB_configAOC(base, CLB_AOC4, TILE1_OUTPUT_COND_CTR_4);
    CLB_configAOC(base, CLB_AOC5, TILE1_OUTPUT_COND_CTR_5);
    CLB_configAOC(base, CLB_AOC6, TILE1_OUTPUT_COND_CTR_6);
    CLB_configAOC(base, CLB_AOC7, TILE1_OUTPUT_COND_CTR_7);

    //
    // LUT 0 - 2 are configured as macros in clb_config.h; these macros are used in
    // CLB_selectLUT4Inputs and CLB_configLUT4Function
    //

    //
    //  LUT Configuration
    //
    CLB_selectLUT4Inputs(base, TILE1_CFG_LUT4_IN0, TILE1_CFG_LUT4_IN1, TILE1_CFG_LUT4_IN2, TILE1_CFG_LUT4_IN3);
    CLB_configLUT4Function(base, TILE1_CFG_LUT4_FN10, TILE1_CFG_LUT4_FN2);

    //
    // FSM 0 - 2 are configured in <file>
    //
    //  State 0 output equation for Finite State Machine 0 for TILE1: (s0 & !e1) | (e0 & !s1 & e1) | (!e0 & s1 & e1)
    //  State 1 output equation for Finite State Machine 0 for TILE1: (s1 & !e1) | (e0  & s0 & e1) | (!e0 & !s0 & e1)
    //
    //  User Description for Finite State Machine 0 for TILE1
    /*
        QEP-A/B signal generation
		e0: DIRECTION via GPREG 0=reverse, 1=forward
		e1: QCLK
		s0: QEP-A
		s1: QEP-B
    */
    //
    //  Output equation for Finite State Machine 1 for TILE1: !(s0 | e1)
    //  State 0 output equation for Finite State Machine 1 for TILE1: (s0 & !e1) | (e0 & ! e1)
    //  User Description for Finite State Machine 1 for TILE1
    /*
        Latch HALT state when PTO is complete
		e0: PTO_DONE
		e1: HALT/CLEAR LATCH
		out: 0=HALT 1=RUN
    */
    //  State 0 output equation for Finite State Machine 2 for TILE1: (e0 & !e1) | (s0 & !e0 & !e1)
    //  User Description for Finite State Machine 2 for TILE1
    /*
        QEP-I generation
		e0: QEP-I HIGH
		e1: QEP-I LOW
		s0: QEP-I
    */

    //
    //  FSM
    //
    CLB_selectFSMInputs(base, TILE1_CFG_FSM_EXT_IN0, TILE1_CFG_FSM_EXT_IN1, TILE1_CFG_FSM_EXTRA_IN0, TILE1_CFG_FSM_EXTRA_IN1);
    CLB_configFSMNextState(base, TILE1_CFG_FSM_NEXT_STATE_0, TILE1_CFG_FSM_NEXT_STATE_1, TILE1_CFG_FSM_NEXT_STATE_2);
    CLB_configFSMLUTFunction(base, TILE1_CFG_FSM_LUT_FN10, TILE1_CFG_FSM_LUT_FN2);

    //
    // Counter 0 - 2 are configured in <file>
    //
    //  User Description for Counter 0 for TILE1
    /*
        Pulse width control
		match1: QCLK
		match2: width control
		mode0: RUN / HALT
		reset: WIDTH_CONTROL
    */
    //  User Description for Counter 1 for TILE1
    /*
        Detect end of PTO, count sent edges
		match1: HALT/CLEAR LATCH
		match2: PTO_DONE
		event: QCLK, add 1
		reset: PTO_DONE
    */
    //  User Description for Counter 2 for TILE1
    /*
        QEP-I control, count sent edges
		match1: QEP-I HIGH
		match2: QEP-I LOW
		event: QCLK, incrment by 1
		reset: PTO_DONE
    */

    //
    //  Counters
    //
    CLB_selectCounterInputs(base, TILE1_CFG_COUNTER_RESET, TILE1_CFG_COUNTER_EVENT, TILE1_CFG_COUNTER_MODE_0, TILE1_CFG_COUNTER_MODE_1);
    CLB_configMiscCtrlModes(base, TILE1_CFG_MISC_CONTROL);
    CLB_configCounterLoadMatch(base, CLB_CTR0, TILE1_COUNTER_0_LOAD_VAL, TILE1_COUNTER_0_MATCH1_VAL, TILE1_COUNTER_0_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR1, TILE1_COUNTER_1_LOAD_VAL, TILE1_COUNTER_1_MATCH1_VAL, TILE1_COUNTER_1_MATCH2_VAL);
    CLB_configCounterLoadMatch(base, CLB_CTR2, TILE1_COUNTER_2_LOAD_VAL, TILE1_COUNTER_2_MATCH1_VAL, TILE1_COUNTER_2_MATCH2_VAL);
    CLB_configCounterTapSelects(base, TILE1_CFG_TAP_SEL);

    //
    // HLC is configured in <file>
    //
    //  User Description for the High Level Controller for TILE1
    /*
        
    */
    //
    // HLC
    //
    //GP[0] as EVENT0
    CLB_configHLCEventSelect(base,TILE1_HLC_EVENT_SEL);
    CLB_setHLCRegisters(base,TILE1_HLC_R0_INIT,TILE1_HLC_R1_INIT,TILE1_HLC_R2_INIT,TILE1_HLC_R3_INIT);

    for(i = 0;i <= CLB_NUM_HLC_INSTR;i++)
    {
    	CLB_programHLCInstruction(base,i,TILE1HLCInstr[i]);
    }

}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//
// End of File
//

