/*
 * device_init.h
 *
 */

#ifndef ACI_MOTORBENCHMARK_DEVICE_INIT_H_
#define ACI_MOTORBENCHMARK_DEVICE_INIT_H_

#include "stdint.h"
#include "device.h"
#include "adc.h"
#include "epwm.h"

#define DEVICE_SYSCLK_FREQ  200*1000*1000
#define ADC_INT_NUMBER	ADC_INT_NUMBER1


#define DEVICE_DELAY_US  delay_us


//*****************************************************************************
//
// Adjust the modeled current so that it can be output by DAC and read from
// ADC correctly as the modeled current is between 1.0 and -1.0
//
//*****************************************************************************
#define Ia_ADJUST_FACTOR 1000
#define Ia_ADJUST_BASELINE 2700

#define ADJUST_Ia_OUTPUT(x) ( ((x) * Ia_ADJUST_FACTOR) + Ia_ADJUST_BASELINE )
#define ADJUST_Ia_INPUT(x)  ( (x - Ia_ADJUST_BASELINE) / Ia_ADJUST_FACTOR )

#define Ib_ADJUST_FACTOR 500
#define Ib_ADJUST_BASELINE 1500

#define ADJUST_Ib_OUTPUT(x) ( ((x) * Ib_ADJUST_FACTOR) + Ib_ADJUST_BASELINE )
#define ADJUST_Ib_INPUT(x)  ( (x - Ib_ADJUST_BASELINE) / Ib_ADJUST_FACTOR )

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
extern void Device_setup(void);

//
// ADC read functions
//
__STATIC_INLINE uint16_t ADC_getIa()
{
//    return AdcaResult.ADCRESULT0;
	return ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER3);
}

__STATIC_INLINE uint16_t ADC_getIb()
{
//    return AdcaResult.ADCRESULT1;
	return ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER7);
}

//
// Interrupt handling functions
//
__STATIC_INLINE void ADCInt_ack()
{
    //
    // Enable more interrupts from this timer
    //
//    *(uint16_t *)(ADCA_BASE+ADC_O_INTFLG) |= ADC_INTFLG_ADCINT1;

    //
    // Acknowledge interrupt to recieve more interrupts from PIE group 1
    //
//    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
	ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER);
}

__STATIC_INLINE void ADCInt_enable()
{
    //
    // Enable ADC interrupt
    //
    ADC_enableInterrupt(ADCA_BASE, ADC_INT_NUMBER1);

    Interrupt_enable(ADCA2_IRQn);

    //
    // Enable the clock to synchronously enable all the ePWMs
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

__STATIC_INLINE void ADCInt_disable()
{
    //
    // Disable PWMs by disabling clocks
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Disable ADC interrupt
    //
    Interrupt_disable(ADCA2_IRQn);
    ADC_disableInterrupt(ADCA_BASE, ADC_INT_NUMBER1);

}

//*****************************************************************************
//
// PWM functions
//
//*****************************************************************************
__STATIC_INLINE void PWM_setUa(uint16_t Ua)
{
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, Ua);
}

__STATIC_INLINE void PWM_setUb(uint16_t Ub)
{
    EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, Ub);
}

__STATIC_INLINE void PWM_setUc(uint16_t Uc)
{
    EPWM_setCounterCompareValue(EPWM3_BASE, EPWM_COUNTER_COMPARE_A, Uc);
}

//*****************************************************************************
//
// DAC functions
//
//*****************************************************************************
__STATIC_INLINE void DAC_setIa(uint16_t value)
{
//    DAC_setShadowValue(DACA_BASE, value);
	CMPSS_setDACValueHigh(CMPSS1_BASE, value);
}

__STATIC_INLINE void DAC_setIb(uint16_t value)
{
//    DAC_setShadowValue(DACB_BASE, value);
	CMPSS_setDACValueLow(CMPSS1_BASE, value);
}

#endif /* ACI_MOTORBENCHMARK_DEVICE_INIT_H_ */
