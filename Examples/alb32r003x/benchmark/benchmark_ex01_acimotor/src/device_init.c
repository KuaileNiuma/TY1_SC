/*
 * device_init.c
 *
 */

#include "parameter.h"
#include "device_init.h"
#include "alb32r003x_evb.h"
#include "device.h"
#include "adc.h"
#include "epwm.h"

extern void aci_irq_entry(void);

//
// ADC constants
//
#define ADC_SAMPLE_PERIOD (DEVICE_SYSCLK_FREQ * SAMPLING_PERIOD)
#define ADC_ACQWIN 8

//
// PWM constants
//
uint32_t PWM_PERIOD_MAX = ADC_SAMPLE_PERIOD/2;
uint32_t PWM_HALF_MAX = ADC_SAMPLE_PERIOD/4;

//
// Function declarations
//


//*****************************************************************************
//
// Initialize ADC for reading two ADC inputs triggered by PWM
//
//*****************************************************************************
void initADC()
{
    //
    // Reset the ADC.  This is good programming practice.
    //
//    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_ADCA);     // Reset ADC

    //
    // Configure the ADC-A base registers
    //
    ADC_disableConverter(ADCA_BASE);                                    // Power down ADC for configuration
//    ADC_setVREF(ADCA_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V); // VREF internal 3.3V
    ADC_setPrescaler(ADCA_BASE, ADC_CLK_DIV_1_0);

    //
    // Configure INT pulse generation at end of acquisition (early interrupt)
    //
    ADC_setInterruptPulseMode(ADCA_BASE, ADC_PULSE_END_OF_ACQ_WIN);

    //
    // SOC configuration - Trigger using ePWM1-ADCSOCA
    //
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN3, ADC_ACQWIN);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN7, ADC_ACQWIN);

    //
    // No ADC interrupt triggers SOC0 (TRIGSEL determined by SOC and not ADCINT1 or ADCINT2)
    //
    ADC_setInterruptSOCTrigger(ADCA_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
    ADC_setInterruptSOCTrigger(ADCA_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);

    //
    // All SOCs handled in round-robin mode
    //
    ADC_setSOCPriority(ADCA_BASE, ADC_PRI_ALL_ROUND_ROBIN);

    //
    // ADCA1 interrupt configuration
    //
    ADC_disableContinuousMode(ADCA_BASE, ADC_INT_NUMBER1);                       // Interrupt pulses regardless of flag state
    ADC_setInterruptSource(ADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);        // SOC0 triggers the interrupt

    //
    // Enable ADCA1 interrupt and specify interrupt handler (ISR)
    //
    Interrupt_register(ADCA_IRQn, aci_irq_entry);
    Interrupt_enable(ADCA_IRQn);
    //
    // Power up ADC
    //
    ADC_enableConverter(ADCA_BASE);

    //
    // Wait 1 ms after power-up before using the ADC
    //
    DEVICE_DELAY_US(1000);

}

//*****************************************************************************
//
// Helper function to configure PWM
//
//*****************************************************************************
void initPWMx(uint32_t base)
{

    //
    // Configure PWM in up down mode
    //
    EPWM_enablePhaseShiftLoad(base);
    EPWM_setEmulationMode(base, EPWM_EMULATION_FREE_RUN);                         // Ignore emulation suspend
    EPWM_setPeriodLoadMode(base, EPWM_PERIOD_DIRECT_LOAD);
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP_DOWN);                 // Enable the timer in count up down mode
    EPWM_setClockPrescaler(base, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);   // TBCLK = EPWMCLK
    EPWM_setCountModeAfterSync(base, EPWM_COUNT_MODE_UP_AFTER_SYNC);

    //
    // Configure timer poeriod
    //
    EPWM_setTimeBasePeriod(base, PWM_PERIOD_MAX);
    EPWM_setPhaseShift(base, 0);

    //
    // Set counter to reload on 0
    //
    EPWM_setCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    // Setup action qualifier
    //
    EPWM_setActionQualifierActionComplete(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH_DOWN_CMPA | EPWM_AQ_OUTPUT_LOW_UP_CMPA);

}

//*********************************************************************** ******
//
// Initialize the PWM modules (1, 2, 3)
//
//*****************************************************************************
void initPWM(void)
{
    //
    // Must disable the clock to the ePWM modules to have all ePWM modules synchronized
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Reset all PWMs
    //
//    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_EPWM1);
//    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_EPWM2);
//    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_EPWM3);

    //
    // Initialize all PWMs
    //
    initPWMx(EPWM1_BASE);
    initPWMx(EPWM2_BASE);
    initPWMx(EPWM3_BASE);

    //
    // Enable PWM1 to trigger ADCA SOC
    //
    EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);                               // Enable ADC SOCA event
    EPWM_setADCTriggerSource(EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);     // Set SOCA on PRD event
    EPWM_setADCTriggerEventPrescale(EPWM1_BASE, EPWM_SOC_A, 1);                  // Generate SOCA on first event
}

//*****************************************************************************
//
// Initialize the DAC modules (A, B)
//
//*****************************************************************************
void initDAC(void)
{
#if defined  (DACA_BASE) && defined  (DACB_BASE)
    //
    // Note: DAC is being configured to use the VREFHI internal voltage reference. For proper operation,
    // the reference modes for ADC-A and ADC-B must be configured. When using the internal reference of
    // 3.3V, the DAC gain of x2 should be set.
    //

    ADC_setVREF(ADCA_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);
    ADC_setVREF(ADCB_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);

    //
    // Set VREFHI as as the DAC reference voltage
    //
    DAC_setReferenceVoltage(DACB_BASE, DAC_REF_ADC_VREFHI);
    DAC_setReferenceVoltage(DACA_BASE, DAC_REF_ADC_VREFHI);

    //
    // Set X 2 gain
    //
    DAC_setGainMode(DACB_BASE, DAC_GAIN_TWO);
    DAC_setGainMode(DACA_BASE, DAC_GAIN_TWO);

    //
    // Set load mode as load on next SYSCLK
    //
    DAC_setLoadMode(DACB_BASE, DAC_LOAD_SYSCLK);
    DAC_setLoadMode(DACA_BASE, DAC_LOAD_SYSCLK);

    //
    // Enable DAC output
    //
    DAC_enableOutput(DACB_BASE);                    // Enable DAC output
    DAC_enableOutput(DACA_BASE);                    // Enable DAC output

    //
    // Initialize DAC output to 0
    //
    DAC_setShadowValue(DACB_BASE, ADJUST_Ia_OUTPUT(0));
    DAC_setShadowValue(DACA_BASE, ADJUST_Ib_OUTPUT(0));

    //
    // Required delay after enabling the DAC (delay for DAC to power up)
    //
    DEVICE_DELAY_US(1000);
#endif
}


//*****************************************************************************
//
// This function configures the device and the relevant peripherals like
// ADC, PWM and DAC for this application.
//
//*****************************************************************************
void Device_setup()
{

    //
    // Initialize peripherals
    //
    initADC();
    initDAC();
    initPWM();

    SysCtl_enableExtADCSOCSource(0);
    EPWM_setSyncInPulseSource(EPWM1_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);

}

