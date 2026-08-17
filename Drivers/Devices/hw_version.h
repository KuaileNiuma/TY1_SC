

#ifndef __HW_VERSION_DEF_H
#define __HW_VERSION_DEF_H

#if defined(IS_ALB32R003X)

    #define DMAC_HW_VER    0
    #define GPIO_HW_VER    0
    #define EPWM_HW_VER    0
    #define XBAR_HW_VER    0
    #define CLB_HW_VER     0
    #define EQEP_HW_VER    0
    #define SDFM_HW_VER    0
    #define ECAP_HW_VER    0
    #define ADC_HW_VER     0
    #define CMPSS_HW_VER   0
    #define HRPWM_HW_VER   0
    #define XFLASHC_HW_VER 0
    #define LPM_HW_VER     0
    #define RCC_HW_VER     0
    #define SYSCTL_HW_VER  0

#elif defined(IS_ALB32RP55)

    #define DMAC_HW_VER    1
    #define GPIO_HW_VER    1
    #define EPWM_HW_VER    1
    #define XBAR_HW_VER    1
    #define CLB_HW_VER     1
    #define EQEP_HW_VER    1
    #define ECAP_HW_VER    1
    #define ADC_HW_VER     1
    #define CMPSS_HW_VER   1
    #define HRPWM_HW_VER   1
    #define XFLASHC_HW_VER 1//4.0.1
    #define SYSCTL_HW_VER  1
    #define RCC_HW_VER     1

#elif defined(IS_ALB32RP65)

    #define DMAC_HW_VER    1
    #define GPIO_HW_VER    1
    #define EPWM_HW_VER    1
    #define XBAR_HW_VER    1
    #define CLB_HW_VER     1
    #define EQEP_HW_VER    1
    #define SDFM_HW_VER    1
    #define ECAP_HW_VER    1
    #define ADC_HW_VER     1
    #define CMPSS_HW_VER   1
    #define HRPWM_HW_VER   1
    #define XFLASHC_HW_VER 1
    #define LPM_HW_VER     1
    #define RCC_HW_VER     1
    #define ESCSS_HW_VER   1
    #define SYSCTL_HW_VER  2

#else
    #error "Error hardware version defined"
#endif

#endif
