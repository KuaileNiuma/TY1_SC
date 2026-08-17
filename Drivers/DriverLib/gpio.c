/**
 *************************************************************************************
 * @file gpio.c
 * @brief This file implements the function of gpio driver.
 * @version 1.0.0
 *************************************************************************************
 * @copyright Copyright (c) 2025 Albatross Semiconductor(Hangzhou) Co.,Ltd.
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

#include "gpio.h"

#if GPIO_HW_VER==0x00
#define GPIO_NUMBER           6U

//*****************************************************************************
//
// GPIO_setDirectionMode
//
//*****************************************************************************
void
GPIO_setDirectionMode(uint32_t pin, GPIO_Direction pinIO)
{
    GPIO_TypeDef  *instance = NULL;
    uint32_t pinMask = (uint32_t)1U << (pin % 32U);
    instance = (GPIO_TypeDef  *)(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP);


    if(pinIO == GPIO_DIR_MODE_OUT)
    {
        //
        // Output
        //
        instance->SWPORT_DDR |= pinMask;
    }
    else
    {
        //
        // Input
        //
        instance->SWPORT_DDR &= ~pinMask;
    }
}

//*****************************************************************************
//
// GPIO_getDirectionMode
//
//*****************************************************************************
GPIO_Direction GPIO_getDirectionMode(uint32_t pin)
{
    GPIO_TypeDef  *instance = NULL;

    instance = (GPIO_TypeDef  *)(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP);

    return((GPIO_Direction)((uint32_t)(( instance->SWPORT_DDR  >> (pin % 32U)) & 1U)));
}

//*****************************************************************************
//
// GPIO_setInterruptPin
//
//*****************************************************************************
void
GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum extIntNum)
{
//	XBAR_InputNum input;
//
//    //
//    // Check the arguments.
//    //
//    ASSERT(GPIO_isPinValid(pin));
//
//    //
//    //Pick the X-BAR input that corresponds to the requested XINT
//    //
//
//    switch(extIntNum)
//    {
//    	case GPIO_INT_XINT1:
//    		input=XBAR_INPUT4;
//    		break;
//    	case GPIO_INT_XINT2:
//    		input=XBAR_INPUT5;
//    		break;
//    	case GPIO_INT_XINT3:
//    		input=XBAR_INPUT6;
//    		break;
//    	case GPIO_INT_XINT4:
//    		input=XBAR_INPUT13;
//    		break;
//    	case GPIO_INT_XINT5:
//    		input=XBAR_INPUT14;
//    		break;
//    	default:
//    		input=XBAR_INPUT1;
//    		break;
//    }
//
//    if(input!=XBAR_INPUT1)
//    {
//    	XBAR_setInputPin(INPUTXBAR_BASE,input,(uint16_t)pin);
//    }
}
//*****************************************************************************
//
// GPIO_setPinConfig
//
//*****************************************************************************
void
GPIO_setPinConfig(uint32_t pinConfig)
{
    uint32_t muxRegAddr;
    uint32_t pinMask, shiftAmt;

    muxRegAddr = (uint32_t) (SYSCTL_BASE + (pinConfig >> 16));
    shiftAmt = ((pinConfig >> 8) & (uint32_t) 0xFFU);
    pinMask = (uint32_t) 0xFU << shiftAmt;

    //
    // Clear fields in MUX register first to avoid glitches
    //
    HWREG(muxRegAddr) &= ~pinMask;

    //
    // Write value into GMUX register
    //
    HWREG(muxRegAddr) = (HWREG(muxRegAddr) & ~pinMask)
            | ((pinConfig & (uint32_t) 0xFU) << shiftAmt);
}


void GPIO_setDBClock(uint32_t base,uint32_t clock)
{
    switch(base)
    {
    case GPIO1_BASE:
        HWREG(SYSCTL_BASE+0x8c)|=clock;
        break;
    case GPIO2_BASE:
        HWREG(SYSCTL_BASE+0x90)|=clock;
        break;
    case GPIO3_BASE:
        HWREG(SYSCTL_BASE+0x94)|=clock;
        break;
    case GPIO4_BASE:
        HWREG(SYSCTL_BASE+0x98)|=clock;
        break;
    case GPIO5_BASE:
        HWREG(SYSCTL_BASE+0x9c)|=clock;
        break;

    }

}
#endif
#if GPIO_HW_VER == 0x01
//*****************************************************************************
//
// GPIO_setDirectionMode
//
//*****************************************************************************
void
GPIO_setDirectionMode(uint32_t pin, GPIO_Direction pinIO)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;

    //
    // Set the data direction
    //
    if(pinIO == GPIO_DIR_MODE_OUT)
    {
        //
        // Output
        //
        gpioBaseAddr[GPIO_GPxDIR_INDEX] |= pinMask;
    }
    else
    {
        //
        // Input
        //
        gpioBaseAddr[GPIO_GPxDIR_INDEX] &= ~pinMask;
    }

    EDIS;
}

//*****************************************************************************
//
// GPIO_getDirectionMode
//
//*****************************************************************************
GPIO_Direction
GPIO_getDirectionMode(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);

    return((GPIO_Direction)((uint32_t)((gpioBaseAddr[GPIO_GPxDIR_INDEX] >>
                             (pin % 32U)) & 1U)));

}

//*****************************************************************************
//
// GPIO_enablePullup
//
//*****************************************************************************

void
GPIO_enablePullup(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxPUD_INDEX] |= pinMask;

    EDIS;

}


//*****************************************************************************
//
// GPIO_enablePulldown
//
//*****************************************************************************

void
GPIO_enablePulldown(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxPUD_INDEX] &= ~pinMask;

    EDIS;

}



//*****************************************************************************
//
// GPIO_enablePullmode
//
//*****************************************************************************

void
GPIO_enablePullmode(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxPUDEN_INDEX] |= pinMask;

    EDIS;

}

//*****************************************************************************
//
// GPIO_disablePullmode
//
//*****************************************************************************

void
GPIO_disablePullmode(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxPUDEN_INDEX] &=~ pinMask;

    EDIS;
}

//*****************************************************************************
//
// GPIO_enableInputInvert
//
//*****************************************************************************

void
GPIO_enableInputInvert(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxINV_INDEX] |= pinMask;

    EDIS;
}


//*****************************************************************************
//
// GPIO_disableInputInvert
//
//*****************************************************************************
void
GPIO_disableInputInvert(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxINV_INDEX] &=~ pinMask;

    EDIS;
}


//*****************************************************************************
//
// GPIO_enableOpenDrain
//
//*****************************************************************************
void
GPIO_enableOpenDrain(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxODR_INDEX] |=pinMask;

    EDIS;
}



//*****************************************************************************
//
// GPIO_disableOpenDrain
//
//*****************************************************************************
void
GPIO_disableOpenDrain(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;
        gpioBaseAddr[GPIO_GPxODR_INDEX] &=~pinMask;

    EDIS;
}

//*****************************************************************************
//
// GPIO_setInterruptPin
//
//*****************************************************************************
void
GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum extIntNum)
{
//	XBAR_InputNum input;
//
//    //
//    // Check the arguments.
//    //
//    ASSERT(GPIO_isPinValid(pin));
//
//    //
//    //Pick the X-BAR input that corresponds to the requested XINT
//    //
//
//    switch(extIntNum)
//    {
//    	case GPIO_INT_XINT1:
//    		input=XBAR_INPUT4;
//    		break;
//    	case GPIO_INT_XINT2:
//    		input=XBAR_INPUT5;
//    		break;
//    	case GPIO_INT_XINT3:
//    		input=XBAR_INPUT6;
//    		break;
//    	case GPIO_INT_XINT4:
//    		input=XBAR_INPUT13;
//    		break;
//    	case GPIO_INT_XINT5:
//    		input=XBAR_INPUT14;
//    		break;
//    	default:
//    		input=XBAR_INPUT1;
//    		break;
//    }
//
//    if(input!=XBAR_INPUT1)
//    {
//    	XBAR_setInputPin(INPUTXBAR_BASE,input,(uint16_t)pin);
//    }
}

//*****************************************************************************
//
// GPIO_setPadConfig
//
//*****************************************************************************
void
GPIO_setPadConfig(uint32_t pin, uint32_t pinType)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;

    //
    // Enable open drain if necessary
    //
    if((pinType & GPIO_PIN_TYPE_OD) != 0U)
    {
        gpioBaseAddr[GPIO_GPxODR_INDEX] |= pinMask;
    }
    else
    {
        gpioBaseAddr[GPIO_GPxODR_INDEX] &= ~pinMask;
    }

    //
    // Enable pull-up if necessary
    //
    if((pinType & GPIO_PIN_TYPE_PULLUP) != 0U)
    {
        gpioBaseAddr[GPIO_GPxPUD_INDEX] &= ~pinMask;
    }
    else
    {
        gpioBaseAddr[GPIO_GPxPUD_INDEX] |= pinMask;
    }

    //
    // Invert polarity if necessary
    //
    if((pinType & GPIO_PIN_TYPE_INVERT) != 0U)
    {
        gpioBaseAddr[GPIO_GPxINV_INDEX] |= pinMask;
    }
    else
    {
        gpioBaseAddr[GPIO_GPxINV_INDEX] &= ~pinMask;
    }

    EDIS;
}

//*****************************************************************************
//
// GPIO_getPadConfig
//
//*****************************************************************************
uint32_t
GPIO_getPadConfig(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;
    uint32_t pinTypeRes;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    pinTypeRes = GPIO_PIN_TYPE_STD;

    //
    // Get open drain value
    //
    if((gpioBaseAddr[GPIO_GPxODR_INDEX] & pinMask) != 0U)
    {
        pinTypeRes |= GPIO_PIN_TYPE_OD;
    }

    //
    // Get pull-up value
    //
    if((gpioBaseAddr[GPIO_GPxPUD_INDEX] & pinMask) == 0U)
    {
        pinTypeRes |= GPIO_PIN_TYPE_PULLUP;
    }

    //
    // Get polarity value
    //
    if((gpioBaseAddr[GPIO_GPxINV_INDEX] & pinMask) != 0U)
    {
        pinTypeRes |= GPIO_PIN_TYPE_INVERT;
    }

    return(pinTypeRes);
}

//*****************************************************************************
//
// GPIO_setQualificationMode
//
//*****************************************************************************
void
GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode qualification)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t qSelIndex;
    uint32_t shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    shiftAmt = (uint32_t)GPIO_GPAQSEL1_GPIO1_S * (pin % 16U);
    qSelIndex = GPIO_GPxQSEL_INDEX + ((pin % 32U) / 16U);

    //
    // Write the input qualification mode to the register.
    //
    EALLOW;

    gpioBaseAddr[qSelIndex] &= ~((uint32_t)GPIO_GPAQSEL1_GPIO0_M << shiftAmt);
    gpioBaseAddr[qSelIndex] |= (uint32_t)qualification << shiftAmt;

    EDIS;
}

//*****************************************************************************
//
// GPIO_getQualificationMode
//
//*****************************************************************************
GPIO_QualificationMode
GPIO_getQualificationMode(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t qSelIndex;
    uint32_t qualRes;
    uint32_t shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    shiftAmt = (uint32_t)GPIO_GPAQSEL1_GPIO1_S * (pin % 16U);
    qSelIndex = GPIO_GPxQSEL_INDEX + ((pin % 32U) / 16U);

    //
    // Read the qualification mode register and shift and mask to get the
    // value for the specified pin.
    //
    qualRes = (gpioBaseAddr[qSelIndex] >> shiftAmt) &
              (uint32_t)GPIO_GPAQSEL1_GPIO0_M;
    return((GPIO_QualificationMode)qualRes);
}

//*****************************************************************************
//
// GPIO_setQualificationPeriod
//
//*****************************************************************************
void
GPIO_setQualificationPeriod(uint32_t pin, uint32_t divider) //divider-even-0~510
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask, regVal, shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));
    ASSERT((divider >= 1U) && (divider <= 510U));

    shiftAmt = (pin % 32U) & ~((uint32_t)0x7U);
    pinMask = (uint32_t)0xFFU << shiftAmt;

    //
    // Divide divider by two to get the value that needs to go into the field.
    // Then shift it into the right place.
    //
    regVal = (divider / 2U) << shiftAmt;

    //
    // Write the divider parameter into the register.
    //
    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);

    EALLOW;
    gpioBaseAddr[GPIO_GPxCTRL_INDEX] &= ~pinMask;
    gpioBaseAddr[GPIO_GPxCTRL_INDEX] |= regVal;
    EDIS;
}

//*****************************************************************************
//
// GPIO_setControllerCore
//
//*****************************************************************************
void
GPIO_setControllerCore(uint32_t pin, GPIO_CoreSelect core)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t cSelIndex;
    uint32_t shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);



    shiftAmt = (uint32_t)GPIO_GPACSEL1_GPIO1_S*(pin%8U);
    cSelIndex = GPIO_GPxCSEL_INDEX + ((pin%32U)/8U);

    //
    // Write the core parameter into the register.
    //

    EALLOW;
    gpioBaseAddr[cSelIndex] &= ~((uint32_t)GPIO_GPACSEL1_GPIO1_M<<shiftAmt);
    gpioBaseAddr[cSelIndex] |= (uint32_t)core<<shiftAmt;
    EDIS;
}

//*****************************************************************************
//
// GPIO_setAnalogMode
//
//*****************************************************************************
void
GPIO_setAnalogMode(uint32_t pin, GPIO_AnalogMode mode)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //

    pinMask=(uint32_t)1U<<(pin%32U);
    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);

    //
    // Set the analog mode selection
    //

    if(mode==GPIO_ANALOG_ENABLED)
    {
    	gpioBaseAddr[GPIO_GPxAMSEL_INDEX]|=pinMask;
    }
    else
    {
    	gpioBaseAddr[GPIO_GPxAMSEL_INDEX]&=~pinMask;
    }

}


//*****************************************************************************
//
// GPIO_setPinConfig
//
//*****************************************************************************
void
GPIO_setPinConfig(uint32_t pinConfig)
{
    uint32_t muxRegAddr;
    uint32_t pinMask, shiftAmt;

    muxRegAddr = (uint32_t)GPIOCTRL_BASE + (pinConfig >> 16);
    shiftAmt = ((pinConfig >> 8) & (uint32_t)0xFFU);
    pinMask = (uint32_t)0x3U << shiftAmt;

    EALLOW;

    //
    // Clear fields in MUX register first to avoid glitches
    //
    HWREG(muxRegAddr) &= ~pinMask;

    //
    // Write value into GMUX register
    //
    HWREG(muxRegAddr + GPIO_MUX_TO_GMUX) =
        (HWREG(muxRegAddr + GPIO_MUX_TO_GMUX) & ~pinMask) |
        (((pinConfig >> 2) & (uint32_t)0x3U) << shiftAmt);

    //
    // Write value into MUX register
    //
    HWREG(muxRegAddr) |= ((pinConfig & (uint32_t)0x3U) << shiftAmt);
    EDIS;
}

#endif
