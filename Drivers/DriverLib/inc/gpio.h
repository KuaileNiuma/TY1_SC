/**
  *************************************************************************************
  * @file gpio.h
  * @brief This file contains the definition of gpio driver.
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

#ifndef __GPIO_H_
#define __GPIO_H_

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup gpio_api GPIO
//! @{
//
//*****************************************************************************

#include "hw_common.h"
#include "hw_gpio.h"
// #include "xbar.h"

#if GPIO_HW_VER==0x00
/**
  * @brief GPIO
  */
typedef struct {
    __IOM uint32_t SWPORT_DR;       /* Offset: 0x00 (W/R)  PortA data register           */
    __IOM uint32_t SWPORT_DDR;      /* Offset: 0x04 (W/R)  PortA data direction register */
    __IOM uint32_t PORT_CTL;        /* Offset: 0x08 (W/R)  PortA source register         */
          uint32_t Reserved[9];     /* Offset: 0x0C ~ 0x02C                              */
    __IOM uint32_t INTEN;           /* Offset: 0x30 (W/R)  Interrupt enable register     */
    __IOM uint32_t INTMASK;         /* Offset: 0x34 (W/R)  Interrupt mask register       */
    __IOM uint32_t INTTYPE;         /* Offset: 0x38 (W/R)  Interrupt type register       */
    __IOM uint32_t INTPOLARITY;     /* Offset: 0x3c (W/R)  Interrupt polarity register   */
    __IM  uint32_t INTSTATUS;       /* Offset: 0x40 (R)    Interrupt status of Port      */
    __IM  uint32_t RAWINTSTATUS;    /* Offset: 0x44 (W/R)  Raw interrupt status of Port  */
    __IOM uint32_t DBEN;            /* Offset: 0x48 (W/R)  debounce control register     */
    __OM  uint32_t EOI;             /* Offset: 0x4c (W/R)  Port clear interrupt register */
    __IM  uint32_t EXT_PORTA;       /* Offset: 0x50 (W/R)  PortA external port register  */
          uint32_t Reserved2[3];    /* Offset: 0x54 ~ 0x5C                               */
    __IOM uint32_t LSSYNC;          /* Offset: 0x60 (W/R)  Level-sensitive synchronization enable register  */
    __IM  uint32_t ID;              /* Offset: 0x64 (R)  GPIO ID code  */  //add
    __IOM uint32_t INTBOTHEDGE;     /* Offset: 0x68 (W/R)  Interrupt both edge enable    */
    __IM  uint32_t VER_ID;          /* Offset: 0x6C (R)  GPIO Component Version  */  //add
    __IM  uint32_t CONFIG_REG2;     /* Offset: 0x70 (R)  GPIO Configuration Register2  */  //add
    __IM  uint32_t CONFIG_REG1;     /* Offset: 0x74 (R)  GPIO Configuration Register1  */  //add
          uint32_t Reserved3[2];    /* Offset: 0x6C ~ 0x7C                               */
} GPIO_TypeDef;


#define GPIO1               ((GPIO_TypeDef *) GPIO1_BASE)
#define GPIO2               ((GPIO_TypeDef *) GPIO2_BASE)
#define GPIO3               ((GPIO_TypeDef *) GPIO3_BASE)
#define GPIO4               ((GPIO_TypeDef *) GPIO4_BASE)
#define GPIO5               ((GPIO_TypeDef *) GPIO5_BASE)
#define GPIO_BASE_ADDR_STEP         0x1000

#ifndef DOXYGEN_PDF_IGNORE
//*****************************************************************************
//
// Values that can be passed to GPIO_setPadConfig() as the pinType parameter
// and returned by GPIO_getPadConfig().
//
//*****************************************************************************
#define GPIO_PIN_TYPE_STD       0x0000U //!< Push-pull output or floating input
#define GPIO_PIN_TYPE_PULLUP    0x0001U //!< Pull-up enable for input
#define GPIO_PIN_TYPE_INVERT    0x0002U //!< Invert polarity on input
#define GPIO_PIN_TYPE_OD        0x0004U //!< Open-drain on output
#endif


//*****************************************************************************
//
//! Values that can be passed to GPIO_setDirectionMode() as the \e pinIO
//! parameter and returned from GPIO_getDirectionMode().
//
//*****************************************************************************
typedef enum
{
    GPIO_DIR_MODE_IN,                   //!< Pin is a GPIO input
    GPIO_DIR_MODE_OUT                   //!< Pin is a GPIO output
} GPIO_Direction;


#define  GPIO_EXTI_INT_LEVEL                    0
#define  GPIO_EXTI_INT_EDGE                     1
#define  GPIO_EXTI_INT_NEG                      0
#define  GPIO_EXTI_INT_POS                      2
#define  GPIO_EXTI_INT_BOTH                     4

#define  GPIO_EXTI_INT_HIGH_LEVEL               (GPIO_EXTI_INT_LEVEL | GPIO_EXTI_INT_POS)
#define  GPIO_EXTI_INT_LOW_LEVEL                (GPIO_EXTI_INT_LEVEL | GPIO_EXTI_INT_NEG)
#define  GPIO_EXTI_INT_RISE_EDGE                (GPIO_EXTI_INT_EDGE  | GPIO_EXTI_INT_POS)
#define  GPIO_EXTI_INT_FALL_EDGE                (GPIO_EXTI_INT_EDGE  | GPIO_EXTI_INT_NEG)
#define  GPIO_EXTI_INT_BOTH_EDGE                (GPIO_EXTI_INT_EDGE  | GPIO_EXTI_INT_BOTH)
//*****************************************************************************
//
//! Values that can be passed to GPIO_setInterruptType() as the \e intType
//! parameter and returned from GPIO_getInterruptType().
//
//*****************************************************************************
typedef enum
{
    GPIO_INT_TYPE_HIGH_LEVEL = GPIO_EXTI_INT_HIGH_LEVEL,   //!< Interrupt on high level
    GPIO_INT_TYPE_LOW_LEVEL  = GPIO_EXTI_INT_LOW_LEVEL,    //!< Interrupt on low level
    GPIO_INT_TYPE_FALLING_EDGE = GPIO_EXTI_INT_FALL_EDGE,   //!< Interrupt on falling edge
    GPIO_INT_TYPE_RISING_EDGE  = GPIO_EXTI_INT_RISE_EDGE,   //!< Interrupt on rising edge
    GPIO_INT_TYPE_BOTH_EDGES   = GPIO_EXTI_INT_BOTH_EDGE    //!< Interrupt on both edges
} GPIO_IntType;


//*****************************************************************************
//
//! Values that can be passed to GPIO_readPortData(), GPIO_setPortPins(),
//! GPIO_clearPortPins(), and GPIO_togglePortPins() as the \e port parameter.
//
//*****************************************************************************
typedef enum
{
    GPIO_PORT_A = 0,                    //!< GPIO port A, GPIO0-31
    GPIO_PORT_B = 1,                    //!< GPIO port B, GPIO32-63
    GPIO_PORT_H = 7,                     //!< GPIO port H, GPIO224-255
    GPIO_PORT_I = 8,                     //!< GPIO port I, GPIO256-287
    GPIO_PORT_J = 9,                     //!< GPIO port J, GPIO288-319
} GPIO_Port;

//*****************************************************************************
//
//! Values that can be passed to GPIO_setInterruptPin(),
//! GPIO_setInterruptType(), GPIO_getInterruptType(), GPIO_enableInterrupt(),
//! GPIO_disableInterrupt(), as the \e extIntNum parameter.
//
//*****************************************************************************
typedef enum
{
    GPIO_INT_XINT1,                     //!< External Interrupt 1
    GPIO_INT_XINT2,                     //!< External Interrupt 2
    GPIO_INT_XINT3,                     //!< External Interrupt 3
    GPIO_INT_XINT4,                     //!< External Interrupt 4
    GPIO_INT_XINT5                      //!< External Interrupt 5
} GPIO_ExternalIntNum;


//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! \internal
//! Checks that a pin number is valid for a device.
//!
//! Note that this function reflects the highest possible GPIO number of a
//! device on its biggest package. Check the datasheet to see what the actual
//! range of valid pin numbers is for a specific package.
//!
//! \return None.
//
//*****************************************************************************
#ifdef DEBUG
static inline bool
GPIO_isPinValid(uint32_t pin)
{
    return((pin <= 63U) || ((pin >= 224U) && (pin <= 311U)));
}

static inline bool
GPIO_isPinValid(GPIO_Port port)
{
    bool ret = false;
    if(port<=GPIO_PORT_B || ((port >= GPIO_PORT_H && port <= GPIO_PORT_J))
    {
        RegValue = true;
    }
    return ret;
}
#endif

static inline void
GPIO_setInterruptType(uint16_t pin, GPIO_IntType intType)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;


    if (intType & GPIO_EXTI_INT_EDGE)
    {
        HWREG(gpioBaseAddr+GPIO_INTTYPE_LEVEL) |= (1 << (pin % 32));/* interrupt by edge mode                    */
    }
    else
    {
        HWREG(gpioBaseAddr+GPIO_INTTYPE_LEVEL) &= ~(1 << (pin % 32));/* interrupt by level mode                   */
    }
    if (intType & GPIO_EXTI_INT_POS)
    {
        HWREG(gpioBaseAddr+GPIO_INT_POLARITY) |= (1 << (pin % 32)); /* interrupt by postive edeg or high level   */
    }
    else
    {
        HWREG(gpioBaseAddr+GPIO_INT_POLARITY) &= ~(1 << (pin % 32));/* interrupt by negetive edeg or low level   */
    }

    if (intType & GPIO_EXTI_INT_BOTH)
    {
        HWREG(gpioBaseAddr+GPIO_INT_BOTHEDGE) |= (1 << (pin % 32));  /* enable interrupt by both edge            */

    }
    else
    {
        HWREG(gpioBaseAddr+GPIO_INT_BOTHEDGE) &= ~(1 << (pin % 32)); /* disable interrupt by both edge            */
    }

}


static inline GPIO_IntType
GPIO_getInterruptType(uint16_t pin)
{
    uint32_t  gpioBaseAddr = 0;
    uint8_t edge = 0;
    uint8_t polarity = 0;
    uint8_t bothEdge = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    edge = (HWREG(gpioBaseAddr+GPIO_INTTYPE_LEVEL) >> (pin%32)) & 0x01;
    polarity = (HWREG(gpioBaseAddr+GPIO_INT_POLARITY) >> (pin % 32)) & 0x01;
    bothEdge = (HWREG(gpioBaseAddr+GPIO_INT_BOTHEDGE) >> (pin % 32)) &0x01;
    return ((GPIO_IntType)(edge | (polarity << 1) | (bothEdge<<2)));
}




static inline void
GPIO_enableInterrupt(uint16_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_INTEN) |= (1 << (pin % 32));

}


static inline void
GPIO_disableInterrupt(uint16_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_INTEN) &= ~(1<<(pin%32));
}



//INT_MASK
static inline void
GPIO_enableInterruptMask(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;
    if(pin>=244)
    {
        gpioBaseAddr = GPIO1_BASE + (pin / 32 - 5) * GPIO_BASE_ADDR_STEP;
    }
    else
    {
        gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;
    }
    HWREG(gpioBaseAddr+GPIO_INTMASK) |= (1 << (pin % 32));

}

static inline void
GPIO_disableInterruptMask(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_INTMASK) &= ~(1 << (pin % 32));
}

static inline uint32_t
GPIO_readInterruptState(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;
    uint32_t  intState = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    intState = HWREG(gpioBaseAddr+GPIO_INTEN) >> (pin%32) &0x01;
    intState &= ~(HWREG(gpioBaseAddr+GPIO_INTMASK) >> (pin%32) &0x01);
    return intState;
}

static inline void
GPIO_enableDebounce(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_PORT_DEBOUNCE) |= (1 << (pin % 32));

}
static inline void
GPIO_disableDebounce(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_PORT_DEBOUNCE) &= ~(1 << (pin % 32));
}
//*****************************************************************************
//
//! Reads the value present on the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! The value at the specified pin are read, as specified by \e pin. The value
//! is returned for both input and output pins.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return Returns the value in the data register for the specified pin.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPin(uint32_t pin)
{
    return (HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP+GPIO_BITBAND_RD + 0x04 * (pin % 32)) & 0x01U);
}

static inline uint32_t
GPIO_readPin_classic(uint32_t pin)
{
    return (HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP + GPIO_EXT_PORT) >> (pin%32)) & 0x01U;
}

//*****************************************************************************
//
//! Writes a value to the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param outVal is the value to write to the pin.
//!
//! Writes the corresponding bit values to the output pin specified by
//! \e pin.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_writePin(uint32_t pin, uint32_t outVal)
{

    if (outVal == 0)
    {
    	HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP + GPIO_BITBAND_WR + 0x04 * (pin % 32)) = 0;
    }
    else
    {
    	HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP+GPIO_BITBAND_WR + 0x04 * (pin % 32))= 1;
    }
}

static inline void
GPIO_writePin_classic(uint32_t pin, uint32_t outVal)
{

    if (outVal == 0)
    {
        HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP+GPIO_SWPORT_DR) &= ~(1 << (pin % 32));
    }
    else
    {
        HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP+GPIO_SWPORT_DR) |= (1 << (pin % 32));
    }
}

//*****************************************************************************
//
//! Toggles the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! Writes the corresponding bit values to the output pin specified by
//! \e pin.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_togglePin(uint32_t pin)
{
	if (GPIO_readPin(pin))
	{
		HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP+GPIO_BITBAND_WR + 0x04*(pin%32)) = 0;
	}
	else
	{
		HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP+GPIO_BITBAND_WR + 0x04*(pin%32)) = 1;
	}
}

static inline void
GPIO_togglePin_classic(uint32_t pin)
{
    HWREG(GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP+GPIO_SWPORT_DR) ^= (1 << (pin % 32));
}


//*****************************************************************************
//
//! Reads the data on the specified port.
//!
//! \param port is the GPIO port being accessed in the form of \b GPIO_PORTX
//! where X is the port letter.
//!
//! \return Returns the value available on pin for the specified port. Each
//! bit of the the return value represents a pin on the port, where bit 0
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPortData(GPIO_Port port)
{
    uint32_t RegValue = 0;

    RegValue = HWREG(GPIO1_BASE + GPIO_EXT_PORT + port * GPIO_BASE_ADDR_STEP);

    return(RegValue);
}


//*****************************************************************************
//
//! Writes the data into the specified port.
//!
//! \param port is the GPIO port being accessed in the form of \b GPIO_PORTX
//! where X is the port letter.
//!
//! \param data is the value on pin for the specified port. Each
//! bit of the the value represents a pin on the port, where bit 0
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.

//! \return none
//
//*****************************************************************************
static inline void
GPIO_writePortData(GPIO_Port port, uint32_t outVal)
{
    uint32_t gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + port * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_SWPORT_DR) = outVal;
    return;
}

static inline void
GPIO_setPortPin(GPIO_Port port, uint32_t pinMask)
{
    uint32_t gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + port * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_SWPORT_DR) |= pinMask;
    return;
}

static inline void
GPIO_clearPortPin(GPIO_Port port, uint32_t pinMask)
{
    uint32_t gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + port * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_SWPORT_DR) &= ~pinMask;
    return;
}


static inline void
GPIO_togglePortPin(GPIO_Port port, uint32_t pinMask)
{
    uint32_t gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + port * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_SWPORT_DR) ^= pinMask;
    return;
}

static inline uint32_t
GPIO_getPinInterruptStatus(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    return HWREG(gpioBaseAddr+GPIO_INTSTATUS) >> (pin%32);
}

static inline void
GPIO_clearPinInterruptStatus(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_PORT_EOI) |= 1<<(pin%32);
}

static inline uint32_t
GPIO_getPortInterruptStatus(GPIO_Port port)
{
    uint32_t gpioBaseAddr = 0;

     gpioBaseAddr = GPIO1_BASE + port * GPIO_BASE_ADDR_STEP;


    return HWREG(gpioBaseAddr+GPIO_INTSTATUS);
}

static inline void
GPIO_clearPortInterruptStatus(GPIO_Port port)
{
    uint32_t gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + port * GPIO_BASE_ADDR_STEP;

    HWREG(gpioBaseAddr+GPIO_PORT_EOI) = 0xFFFFFFFF;
}

static inline uint32_t
GPIO_getPinRawInterruptStatus(uint32_t pin)
{
    uint32_t  gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (pin / 32) * GPIO_BASE_ADDR_STEP;

    return HWREG(gpioBaseAddr+GPIO_RAW_INTSTATUS) >> (pin%32);
}

static inline uint32_t
GPIO_getPortRawInterruptStatus(GPIO_Port port)
{
    uint32_t gpioBaseAddr = 0;

    gpioBaseAddr = GPIO1_BASE + (port) * GPIO_BASE_ADDR_STEP;

    return HWREG(gpioBaseAddr+GPIO_RAW_INTSTATUS);
}

//*****************************************************************************
//
//! Sets the direction and mode of the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param pinIO is the pin direction mode.
//!
//! This function configures the specified pin on the selected GPIO port as
//! either input or output.
//!
//! The parameter \e pinIO is an enumerated data type that can be one of the
//! following values:
//!
//! - \b GPIO_DIR_MODE_IN
//! - \b GPIO_DIR_MODE_OUT
//!
//! where \b GPIO_DIR_MODE_IN specifies that the pin is programmed as an input
//! and \b GPIO_DIR_MODE_OUT specifies that the pin is programmed as an output.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setDirectionMode(uint32_t pin, GPIO_Direction pinIO);

//*****************************************************************************
//
//! Gets the direction mode of a pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! This function gets the direction mode for a specified pin.  The pin can be
//! configured as either an input or output The type of direction is returned
//! as an enumerated data type.
//!
//! \return Returns one of the enumerated data types described for
//! GPIO_setDirectionMode().
//
//*****************************************************************************
extern GPIO_Direction
GPIO_getDirectionMode(uint32_t pin);


//*****************************************************************************
//
//! Sets the pin for the specified external interrupt.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param extIntNum specifies the external interrupt.
//!
//! This function sets which pin triggers the selected external interrupt.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//! - \b GPIO_INT_XINT4
//! - \b GPIO_INT_XINT5
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \sa XBAR_setInputPin()
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum extIntNum);


//*****************************************************************************
//
//! Configures the alternate function of a GPIO pin.
//!
//! \param pinConfig is the pin configuration value, specified as only one
//! of the \b GPIO_PIN_xxx values.
//!
//! This function configures the pin mux that selects the peripheral function
//! associated with a particular GPIO pin.  Only one peripheral function at a
//! time can be associated with a GPIO pin, and each peripheral function should
//! only be associated with a single GPIO pin at a time (despite the fact that
//! many of them can be associated with more than one GPIO pin).
//!
//! The available mappings are supplied in <tt>pin_map.h</tt>.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setPinConfig(uint32_t pinConfig);

extern void
GPIO_setDBClock(uint32_t base,uint32_t clock);

#endif
#if GPIO_HW_VER==0x01
//*****************************************************************************
//
// Useful defines used within the driver functions to access gpio registers.
// Not intended for use by application code.
//
// Divide by 2 is for C28x which has word access
//
//*****************************************************************************

#define GPIO_CTRL_REGS_STEP     ((GPIO_O_GPBCTRL - GPIO_O_GPACTRL)/4U)
#define GPIO_DATA_REGS_STEP     ((GPIO_O_GPBDAT - GPIO_O_GPADAT)/4U)
#define GPIO_DATA_READ_REGS_STEP ((GPIO_O_GPBDAT_R - GPIO_O_GPADAT_R)/4U)

#define GPIO_GPxCTRL_INDEX      (GPIO_O_GPACTRL /4U)
#define GPIO_GPxQSEL_INDEX      (GPIO_O_GPAQSEL1 /4U)
#define GPIO_GPxQSEL2_INDEX     (GPIO_O_GPAQSEL2 /4U)
#define GPIO_GPxMUX_INDEX       (GPIO_O_GPAMUX1 /4U)
#define GPIO_GPxMUX2_INDEX      (GPIO_O_GPAMUX2 /4U)
#define GPIO_GPxDIR_INDEX       (GPIO_O_GPADIR /4U)
#define GPIO_GPxPUD_INDEX       (GPIO_O_GPAPUD /4U)
#define GPIO_GPxINV_INDEX       (GPIO_O_GPAINV /4U)
#define GPIO_GPxODR_INDEX       (GPIO_O_GPAODR /4U)
#define GPIO_GPxPUDEN_INDEX     (GPIO_O_GPAPUDEN /4U)
#define GPIO_GPxAMSEL_INDEX     ((GPIO_O_GPBAMSEL-GPIO_O_GPBCTRL)/4U) // Address rsvd for GPAAMSEL
#define GPIO_GPxGMUX_INDEX      (GPIO_O_GPAGMUX1 /4U)
#define GPIO_GPxGMUX2_INDEX     (GPIO_O_GPAGMUX2 /4U)
#define GPIO_GPxCSEL_INDEX      (GPIO_O_GPACSEL1 /4U)
#define GPIO_GPxLOCK_INDEX      (GPIO_O_GPALOCK /4U)
#define GPIO_GPxCR_INDEX        (GPIO_O_GPACR /4U)

#define GPIO_GPxDAT_INDEX       (GPIO_O_GPADAT/4U)
#define GPIO_GPxSET_INDEX       (GPIO_O_GPASET/4U)
#define GPIO_GPxCLEAR_INDEX     (GPIO_O_GPACLEAR/4U)
#define GPIO_GPxTOGGLE_INDEX    (GPIO_O_GPATOGGLE/4U)

#define GPIO_GPxDAT_R_INDEX     (GPIO_O_GPADAT_R/4U)

#define GPIO_MUX_TO_GMUX        (GPIO_O_GPAGMUX1 - GPIO_O_GPAMUX1)

#ifndef DOXYGEN_PDF_IGNORE
//*****************************************************************************
//
// Values that can be passed to GPIO_setPadConfig() as the pinType parameter
// and returned by GPIO_getPadConfig().
//
//*****************************************************************************
#define GPIO_PIN_TYPE_STD       0x0000U //!< Push-pull output or floating input
#define GPIO_PIN_TYPE_PULLUP    0x0001U //!< Pull-up enable for input
#define GPIO_PIN_TYPE_INVERT    0x0002U //!< Invert polarity on input
#define GPIO_PIN_TYPE_OD        0x0004U //!< Open-drain on output
#endif

//*****************************************************************************
//
//! Values that can be passed to GPIO_setDirectionMode() as the \e pinIO
//! parameter and returned from GPIO_getDirectionMode().
//
//*****************************************************************************
typedef enum
{
    GPIO_DIR_MODE_IN,                   //!< Pin is a GPIO input
    GPIO_DIR_MODE_OUT                   //!< Pin is a GPIO output
} GPIO_Direction;

//*****************************************************************************
//
//! Values that can be passed to GPIO_setInterruptType() as the \e intType
//! parameter and returned from GPIO_getInterruptType().
//
//*****************************************************************************
typedef enum
{
    GPIO_INT_TYPE_FALLING_EDGE = 0x00,   //!< Interrupt on falling edge
    GPIO_INT_TYPE_RISING_EDGE  = 0x04,   //!< Interrupt on rising edge
    GPIO_INT_TYPE_BOTH_EDGES   = 0x0C    //!< Interrupt on both edges
} GPIO_IntType;

//*****************************************************************************
//
//! Values that can be passed to GPIO_setQualificationMode() as the
//! \e qualification parameter and returned by GPIO_getQualificationMode().
//
//*****************************************************************************
typedef enum
{
    GPIO_QUAL_SYNC,                     //!< Synchronization to SYSCLK
    GPIO_QUAL_3SAMPLE,                  //!< Qualified with 3 samples
    GPIO_QUAL_6SAMPLE,                  //!< Qualified with 6 samples
    GPIO_QUAL_ASYNC                     //!< No synchronization
} GPIO_QualificationMode;

//*****************************************************************************
//
//! Values that can be passed to GPIO_setAnalogMode() as the \e mode parameter.
//
//*****************************************************************************
typedef enum
{
    GPIO_ANALOG_DISABLED,       //!< Pin is in digital mode
    GPIO_ANALOG_ENABLED         //!< Pin is in analog mode
} GPIO_AnalogMode;

//*****************************************************************************
//
//! Values that can be passed to GPIO_setControllerCore() as the \e core
//! parameter.
//
//*****************************************************************************
typedef enum
{
    GPIO_CORE_CPU1,             //!< CPU1 selected as controller core
    GPIO_CORE_CPU1_CLA1,        //!< CPU1's CLA1 selected as controller core
    GPIO_CORE_CPU2,             //!< CPU2 selected as controller core
} GPIO_CoreSelect;

//*****************************************************************************
//
//! Values that can be passed to GPIO_readPortData(), GPIO_setPortPins(),
//! GPIO_clearPortPins(), and GPIO_togglePortPins() as the \e port parameter.
//
//*****************************************************************************
typedef enum
{
    GPIO_PORT_A = 0,                    //!< GPIO port A
    GPIO_PORT_B = 1,                    //!< GPIO port B
    GPIO_PORT_C = 2,                    //!< GPIO port C
    GPIO_PORT_D = 3,                    //!< GPIO port D
    GPIO_PORT_E = 4,                    //!< GPIO port E
    GPIO_PORT_F = 5,                    //!< GPIO port F
    GPIO_PORT_G = 6,                    //!< GPIO port G
    GPIO_PORT_H = 7,                    //!< GPIO port H
} GPIO_Port;

//*****************************************************************************
//
//! Values that can be passed to GPIO_setInterruptPin(),
//! GPIO_setInterruptType(), GPIO_getInterruptType(), GPIO_enableInterrupt(),
//! GPIO_disableInterrupt(), as the \e extIntNum parameter.
//
//*****************************************************************************
typedef enum
{
    GPIO_INT_XINT1,                     //!< External Interrupt 1
    GPIO_INT_XINT2,                     //!< External Interrupt 2
    GPIO_INT_XINT3,                     //!< External Interrupt 3
    GPIO_INT_XINT4,                     //!< External Interrupt 4
    GPIO_INT_XINT5                      //!< External Interrupt 5
} GPIO_ExternalIntNum;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! \internal
//! Checks that a pin number is valid for a device.
//!
//! Note that this function reflects the highest possible GPIO number of a
//! device on its biggest package. Check the datasheet to see what the actual
//! range of valid pin numbers is for a specific package.
//!
//! \return None.
//
//*****************************************************************************
#ifdef DEBUG
static inline bool
GPIO_isPinValid(uint32_t pin)
{
    return((pin <= 168U) || ((pin >= 198U) && (pin <= 242U)));
}
#endif

//*****************************************************************************
//
//! Reads the value present on the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! The value at the specified pin are read, as specified by \e pin. The value
//! is returned for both input and output pins.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return Returns the value in the data register for the specified pin.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPin(uint32_t pin)
{
    volatile uint32_t *gpioDataReg;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((pin / 32U) * GPIO_DATA_REGS_STEP);

    return((gpioDataReg[GPIO_GPxDAT_INDEX] >> (pin % 32U)) & (uint32_t)0x1U);
}

//*****************************************************************************
//
//! Reads the data register value for specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! The value available at the data register for the specified pin is read, as
//! specified by \e pin. The value is returned for both input and output pins.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \sa GPIO_readPin()
//!
//! \return Returns the value in the data register for the specified pin.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPinDataRegister(uint32_t pin)
{
    volatile uint32_t *gpioDataReg;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATAREAD_BASE +
                  ((pin / 32U) * GPIO_DATA_READ_REGS_STEP);

    return((gpioDataReg[GPIO_GPxDAT_R_INDEX] >> (pin % 32U)) & (uint32_t)0x1U);
}

//*****************************************************************************
//
//! Writes a value to the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param outVal is the value to write to the pin.
//!
//! Writes the corresponding bit values to the output pin specified by
//! \e pin.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_writePin(uint32_t pin, uint32_t outVal)
{
    volatile uint32_t *gpioDataReg;
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((pin / 32U) * GPIO_DATA_REGS_STEP);

    pinMask = (uint32_t)1U << (pin % 32U);

    if(outVal == 0U)
    {
        gpioDataReg[GPIO_GPxCLEAR_INDEX] = pinMask;
    }
    else
    {
        gpioDataReg[GPIO_GPxSET_INDEX] = pinMask;
    }
}

//*****************************************************************************
//
//! Toggles the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! Writes the corresponding bit values to the output pin specified by
//! \e pin.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_togglePin(uint32_t pin)
{
    volatile uint32_t *gpioDataReg;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((pin / 32U) * GPIO_DATA_REGS_STEP);

    gpioDataReg[GPIO_GPxTOGGLE_INDEX] = (uint32_t)1U << (pin % 32U);
}

//*****************************************************************************
//
//! Reads the data on the specified port.
//!
//! \param port is the GPIO port being accessed in the form of \b GPIO_PORT_X
//! where X is the port letter.
//!
//! \return Returns the value available on pin for the specified port. Each
//! bit of the the return value represents a pin on the port, where bit 0
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPortData(GPIO_Port port)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and return DATA.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((uint32_t)port * GPIO_DATA_REGS_STEP);

    return(gpioDataReg[GPIO_GPxDAT_INDEX]);
}

//*****************************************************************************
//
//! Reads the data written in GPIO Data Register.
//!
//! \param port is the GPIO port being accessed in the form of \b GPIO_PORT_X
//! where X is the port letter.
//!
//! Reads the data written in GPIO Data Register for the specified port. In
//! previous devices, read of GPIO data registers resulted in read of
//! corespoinding pins. The function \b GPIO_readPortData() returns the value
//! on pin.
//!
//! \sa GPIO_readPortData()
//!
//! \return Returns the value in the data register for the specified port. Each
//! bit of the the return value represents a pin on the port, where bit 0
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//
//*****************************************************************************
static inline uint32_t
GPIO_readPortDataRegister(GPIO_Port port)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and return DATA.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATAREAD_BASE +
                  ((uint32_t)port * GPIO_DATA_READ_REGS_STEP);

    return(gpioDataReg[GPIO_GPxDAT_R_INDEX]);
}

//*****************************************************************************
//
//! Writes a value to the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param outVal is the value to write to the port.
//!
//! This function writes the value \e outVal to the port specified by the
//! \e port parameter which takes a value in the form of \b GPIO_PORT_X where X
//! is the port letter. For example, use \b GPIO_PORT_A to affect port A
//! (GPIOs 0-31).
//!
//! The \e outVal is a bit-packed value, where each bit represents a bit on a
//! GPIO port. Bit 0 represents GPIO port pin 0, bit 1 represents GPIO port
//! pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_writePortData(GPIO_Port port, uint32_t outVal)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and write to DATA.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((uint32_t)port * GPIO_DATA_REGS_STEP);

    gpioDataReg[GPIO_GPxDAT_INDEX] = outVal;
}

//*****************************************************************************
//
//! Sets all of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function sets all of the pins specified by the \e pinMask parameter on
//! the port specified by the \e port parameter which takes a value in the
//! form of \b GPIO_PORT_X where X is the port letter. For example, use
//! \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be set. Bit 0 represents GPIO port pin 0, bit 1 represents GPIO
//! port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_setPortPins(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and write to SET.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((uint32_t)port * GPIO_DATA_REGS_STEP);

    gpioDataReg[GPIO_GPxSET_INDEX] = pinMask;
}

//*****************************************************************************
//
//! Clears all of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function clears all of the pins specified by the \e pinMask parameter
//! on the port specified by the \e port parameter which takes a value in the
//! form of \b GPIO_PORT_X where X is the port letter. For example, use
//! \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is \b set
//! identifies the pin to be cleared. Bit 0 represents GPIO port pin 0, bit 1
//! represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_clearPortPins(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and write to CLEAR.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((uint32_t)port * GPIO_DATA_REGS_STEP);

    gpioDataReg[GPIO_GPxCLEAR_INDEX] = pinMask;
}

//*****************************************************************************
//
//! Toggles all of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function toggles all of the pins specified by the \e pinMask parameter
//! on the port specified by the \e port parameter which takes a value in the
//! form of \b GPIO_PORT_X where X is the port letter. For example, use
//! \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be toggled. Bit 0 represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_togglePortPins(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and write to TOGGLE.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIODATA_BASE +
                  ((uint32_t)port * GPIO_DATA_REGS_STEP);

    gpioDataReg[GPIO_GPxTOGGLE_INDEX] = pinMask;
}

//*****************************************************************************
//
//! Locks the configuration of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function locks the configuration registers of the pins specified by
//! the \e pinMask parameter on the port specified by the \e port parameter
//! which takes a value in the form of \b GPIO_PORT_X where X is the port
//! letter. For example, use \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be locked. Bit 0 represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, 0xFFFFFFFF represents all pins on that port, and so on.
//!
//! Note that this function is for locking the configuration of a pin such as
//! the pin muxing, direction, open drain mode, and other settings. It does not
//! affect the ability to change the value of the pin.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_lockPortConfig(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and write to the lock.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIOCTRL_BASE +
                  ((uint32_t)port * GPIO_CTRL_REGS_STEP);

    EALLOW;
    gpioDataReg[GPIO_GPxLOCK_INDEX] |= pinMask;
    EDIS;
}

//*****************************************************************************
//
//! Unlocks the configuration of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function unlocks the configuration registers of the pins specified by
//! the \e pinMask parameter on the port specified by the \e port parameter
//! which takes a value in the form of \b GPIO_PORT_X where X is the port
//! letter. For example, use \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be unlocked. Bit 0 represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, 0xFFFFFFFF represents all pins on that port, and so on.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_unlockPortConfig(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and write to the lock.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIOCTRL_BASE +
                  ((uint32_t)port * GPIO_CTRL_REGS_STEP);

    EALLOW;
    gpioDataReg[GPIO_GPxLOCK_INDEX] &= ~pinMask;
    EDIS;
}

//*****************************************************************************
//
//! Commits the lock configuration of the specified pins on the specified port.
//!
//! \param port is the GPIO port being accessed.
//! \param pinMask is a mask of which of the 32 pins on the port are affected.
//!
//! This function commits the lock configuration registers of the pins
//! specified by the \e pinMask parameter on the port specified by the \e port
//! parameter which takes a value in the form of \b GPIO_PORT_X where X is the
//! port letter. For example, use \b GPIO_PORT_A to affect port A (GPIOs 0-31).
//!
//! The \e pinMask is a bit-packed value, where each bit that is set identifies
//! the pin to be locked. Bit 0 represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, 0xFFFFFFFF represents all pins on that port, and so on.
//!
//! Note that once this function is called, GPIO_lockPortConfig() and
//! GPIO_unlockPortConfig() will no longer have any effect on the specified
//! pins.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GPIO_commitPortConfig(GPIO_Port port, uint32_t pinMask)
{
    volatile uint32_t *gpioDataReg;

    //
    // Get the starting address of the port's registers and write to the lock.
    //
    gpioDataReg = (uint32_t *)(uintptr_t)GPIOCTRL_BASE +
                  ((uint32_t)port * GPIO_CTRL_REGS_STEP);

    EALLOW;
    gpioDataReg[GPIO_GPxCR_INDEX] |= pinMask;
    EDIS;
}

//*****************************************************************************
//
//! Sets the direction and mode of the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param pinIO is the pin direction mode.
//!
//! This function configures the specified pin on the selected GPIO port as
//! either input or output.
//!
//! The parameter \e pinIO is an enumerated data type that can be one of the
//! following values:
//!
//! - \b GPIO_DIR_MODE_IN
//! - \b GPIO_DIR_MODE_OUT
//!
//! where \b GPIO_DIR_MODE_IN specifies that the pin is programmed as an input
//! and \b GPIO_DIR_MODE_OUT specifies that the pin is programmed as an output.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setDirectionMode(uint32_t pin, GPIO_Direction pinIO);

//*****************************************************************************
//
//! Gets the direction mode of a pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! This function gets the direction mode for a specified pin.  The pin can be
//! configured as either an input or output The type of direction is returned
//! as an enumerated data type.
//!
//! \return Returns one of the enumerated data types described for
//! GPIO_setDirectionMode().
//
//*****************************************************************************
extern GPIO_Direction
GPIO_getDirectionMode(uint32_t pin);

extern void
GPIO_enablePullup(uint32_t pin);

extern void
GPIO_enablePulldown(uint32_t pin);

extern void
GPIO_enablePullmode(uint32_t pin);

extern void
GPIO_disablePullmode(uint32_t pin);

extern void
GPIO_enableInputInvert(uint32_t pin);

extern void
GPIO_disableInputInvert(uint32_t pin);

extern void
GPIO_enableOpenDrain(uint32_t pin);

extern void
GPIO_disableOpenDrain(uint32_t pin);

//*****************************************************************************
//
//! Sets the pin for the specified external interrupt.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param extIntNum specifies the external interrupt.
//!
//! This function sets which pin triggers the selected external interrupt.
//!
//! The following defines can be used to specify the external interrupt for the
//! \e extIntNum parameter:
//!
//! - \b GPIO_INT_XINT1
//! - \b GPIO_INT_XINT2
//! - \b GPIO_INT_XINT3
//! - \b GPIO_INT_XINT4
//! - \b GPIO_INT_XINT5
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \sa XBAR_setInputPin()
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum extIntNum);

//*****************************************************************************
//
//! Sets the pad configuration for the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param pinType specifies the pin type.
//!
//! This function sets the pin type for the specified pin. The parameter
//! \e pinType can be the following values:
//!
//! - \b GPIO_PIN_TYPE_STD specifies a push-pull output or a floating input
//! - \b GPIO_PIN_TYPE_PULLUP specifies the pull-up is enabled for an input
//! - \b GPIO_PIN_TYPE_OD specifies an open-drain output pin
//! - \b GPIO_PIN_TYPE_INVERT specifies inverted polarity on an input
//!
//! \b GPIO_PIN_TYPE_INVERT may be OR-ed with \b GPIO_PIN_TYPE_STD or
//! \b GPIO_PIN_TYPE_PULLUP.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setPadConfig(uint32_t pin, uint32_t pinType);

//*****************************************************************************
//
//! Gets the pad configuration for a pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! This function returns the pin type for the specified pin.  The value
//! returned corresponds to the values used in GPIO_setPadConfig().
//!
//! \return Returns a bit field of the values \b GPIO_PIN_TYPE_STD,
//! \b GPIO_PIN_TYPE_PULLUP, \b GPIO_PIN_TYPE_OD, and \b GPIO_PIN_TYPE_INVERT.
//
//*****************************************************************************
extern uint32_t
GPIO_getPadConfig(uint32_t pin);

//*****************************************************************************
//
//! Sets the qualification mode for the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param qualification specifies the qualification mode of the pin.
//!
//! This function sets the qualification mode for the specified pin. The
//! parameter \e qualification can be one of the following values:
//! - \b GPIO_QUAL_SYNC
//! - \b GPIO_QUAL_3SAMPLE
//! - \b GPIO_QUAL_6SAMPLE
//! - \b GPIO_QUAL_ASYNC
//!
//! To set the qualification sampling period, use
//! GPIO_setQualificationPeriod().
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode qualification);

//*****************************************************************************
//
//! Gets the qualification type for the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//!
//! \return Returns the qualification mode in the form of one of the values
//! \b GPIO_QUAL_SYNC, \b GPIO_QUAL_3SAMPLE, \b GPIO_QUAL_6SAMPLE, or
//! \b GPIO_QUAL_ASYNC.
//
//*****************************************************************************
extern GPIO_QualificationMode
GPIO_getQualificationMode(uint32_t pin);

//*****************************************************************************
//
//! Sets the qualification period for a set of pins
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param divider specifies the output drive strength.
//!
//! This function sets the qualification period for a set of \b 8 \b pins,
//! specified by the \e pin parameter. For instance, passing in 3 as the value
//! of \e pin will set the qualification period for GPIO0 through GPIO7, and a
//! value of 98 will set the qualification period for GPIO96 through GPIO103.
//! This is because the register field that configures the divider is shared.
//!
//! To think of this in terms of an equation, configuring \e pin as \b n will
//! configure GPIO (n & ~(7)) through GPIO ((n & ~(7)) + 7).
//!
//! \e divider is the value by which the frequency of SYSCLKOUT is divided. It
//! can be 1 or an even value between 2 and 510 inclusive.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setQualificationPeriod(uint32_t pin, uint32_t divider);

//*****************************************************************************
//
//! Selects the controller core of a specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param core is the core that is controller of the specified pin.
//!
//! This function configures which core owns the specified pin's data registers
//! (DATA, SET, CLEAR, and TOGGLE). The \e core parameter is an enumerated data
//! type that specifies the core, such as \b GPIO_CORE_CPU1_CLA1 to make CPU1's
//! CLA1 controller of the pin.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setControllerCore(uint32_t pin, GPIO_CoreSelect core);

//*****************************************************************************
//
//! Sets the analog mode of the specified pin.
//!
//! \param pin is the identifying GPIO number of the pin.
//! \param mode is the selected analog mode.
//!
//! This function configures the specified pin for either analog or digital
//! mode. Not all GPIO pins have the ability to be switched to analog mode,
//! so refer to the technical reference manual for details. This setting should
//! be thought of as another level of muxing.
//!
//! The parameter \e mode is an enumerated data type that can be one of the
//! following values:
//!
//! - \b GPIO_ANALOG_DISABLED - Pin is in digital mode
//! - \b GPIO_ANALOG_ENABLED - Pin is in analog mode
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin.
//!
//! \b Note: The pin parameter is applicable for both AIO and GPIO because
//! the GPAxMSEL.GPIOy register configures for both
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setAnalogMode(uint32_t pin, GPIO_AnalogMode mode);

//*****************************************************************************
//
//! Configures the alternate function of a GPIO pin.
//!
//! \param pinConfig is the pin configuration value, specified as only one
//! of the \b GPIO_PIN_xxx values.
//!
//! This function configures the pin mux that selects the peripheral function
//! associated with a particular GPIO pin.  Only one peripheral function at a
//! time can be associated with a GPIO pin, and each peripheral function should
//! only be associated with a single GPIO pin at a time (despite the fact that
//! many of them can be associated with more than one GPIO pin).
//!
//! The available mappings are supplied in <tt>pin_map.h</tt>.
//!
//! \return None.
//
//*****************************************************************************
extern void
GPIO_setPinConfig(uint32_t pinConfig);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif



#endif //  GPIO_H
