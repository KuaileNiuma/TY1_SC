/** 
  *************************************************************************************
  * @file spll_1ph_sogi.h 
  * @author Albatross 
  * @brief This file contains the header file. 
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

#ifndef SPLL_1PH_SOGI_H
#define SPLL_1PH_SOGI_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#if __riscv && NICE_ENABLE
#include "gj320_math.h"
#else
#include "../inc/hw_types.h"
#include <math.h>
#include <stdint.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

//! \brief  Defines the SPLL_1PH_SOGI_OSG_COEFF structure
//!
typedef struct {
    float32_t osg_k;
    float32_t osg_x;
    float32_t osg_y;
    float32_t osg_b0;
    float32_t osg_b2;
    float32_t osg_a1;
    float32_t osg_a2;
    float32_t osg_qb0;
    float32_t osg_qb1;
    float32_t osg_qb2;
} SPLL_1PH_SOGI_OSG_COEFF;

//! \brief  Defines the SPLL_1PH_SOGI_LPF_COEFF structure
//!
typedef struct {
    float32_t b1;
    float32_t b0;
} SPLL_1PH_SOGI_LPF_COEFF;

//! \brief Defines the Orthogonal Signal Generator SPLL_1PH_SOGI
//!        structure
//!
//! \details The SPLL_1PH_SOGI can be used to generate the
//!          orthogonal signal from the sensed single phase grid voltage
//!          and use that information to provide phase of the grid voltage
//!
typedef struct {
    float32_t u[3];                    //!< AC input data buffer
    float32_t osg_u[3];                //!< Orthogonal signal generator data buffer
    float32_t osg_qu[3];               //!< Orthogonal signal generator quadrature data buffer
    float32_t u_Q[2];                  //!< Q-axis component
    float32_t u_D[2];                  //!< D-axis component
    float32_t ylf[2];                  //!< Loop filter data storage
    float32_t fo;                      //!< Output frequency of PLL(Hz)
    float32_t fn;                      //!< Nominal frequency (Hz)
    float32_t theta;                   //!< Angle output (0-2*pi)
    float32_t cosine;                  //!< Cosine value of the PLL angle
    float32_t sine;                    //!< Sine value of the PLL angle
    float32_t delta_t;                 //!< Inverse of the ISR rate at which module is called
    SPLL_1PH_SOGI_OSG_COEFF osg_coeff; //!< Orthogonal signal generator coefficient
    SPLL_1PH_SOGI_LPF_COEFF lpf_coeff; //!< Loop filter coeffcient structure
} SPLL_1PH_SOGI;

/* ========================================================================== */
/*                            Global Constants                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Global Functions Declarations                      */
/* ========================================================================== */
//! \brief Resets internal storage data of the module
//! \param *spll_obj The SPLL_1PH_SOGI structure pointer
//! \return None
//!
__STATIC_INLINE void
SPLL_1PH_SOGI_reset(SPLL_1PH_SOGI *spll_obj) {
    spll_obj->u[0] = 0.0f;
    spll_obj->u[1] = 0.0f;
    spll_obj->u[2] = 0.0f;

    spll_obj->osg_u[0] = 0.0f;
    spll_obj->osg_u[1] = 0.0f;
    spll_obj->osg_u[2] = 0.0f;

    spll_obj->osg_qu[0] = 0.0f;
    spll_obj->osg_qu[1] = 0.0f;
    spll_obj->osg_qu[2] = 0.0f;

    spll_obj->u_Q[0] = 0.0f;
    spll_obj->u_Q[1] = 0.0f;

    spll_obj->u_D[0] = 0.0f;
    spll_obj->u_D[1] = 0.0f;

    spll_obj->ylf[0] = 0.0f;
    spll_obj->ylf[1] = 0.0f;

    spll_obj->fo = 0.0f;

    spll_obj->theta = 0.0f;

    spll_obj->sine = 0.0f;
    spll_obj->cosine = 0.0f;
}

//! \brief Calculates the SPLL_1PH_SOGI coefficient
//! \param *spll_obj The SPLL_1PH_SOGI structure
//! \return None
//!
__STATIC_INLINE void
SPLL_1PH_SOGI_coeff_calc(SPLL_1PH_SOGI *spll_obj) {
    float32_t osgx, osgy, temp, wn;
#ifdef ZHANLU
    wn = __builtin_riscv_mpy2pif32(spll_obj->fn);
    spll_obj->osg_coeff.osg_k = (float32_t)(0.5);
    osgx = (float32_t)__builtin_riscv_mpy2f32(0.5f * wn * spll_obj->delta_t);
    spll_obj->osg_coeff.osg_x = (float32_t)(osgx);
    osgy = (float32_t)(wn * spll_obj->delta_t * wn * spll_obj->delta_t);
    spll_obj->osg_coeff.osg_y = (float32_t)(osgy);
    temp = __builtin_riscv_divf32(1.0f,(osgx + osgy + 4.0f));
    spll_obj->osg_coeff.osg_b0 = ((float32_t)osgx * temp);
    spll_obj->osg_coeff.osg_b2 = ((float32_t)(-1.0f) * spll_obj->osg_coeff.osg_b0);
    spll_obj->osg_coeff.osg_a1 = temp * __builtin_riscv_mpy2f32(__builtin_riscv_naddcstf32(osgy,4));
    spll_obj->osg_coeff.osg_a2 = ((float32_t)(osgx - osgy - 4) * temp);
    spll_obj->osg_coeff.osg_qb0 = ((float32_t)(0.5f * osgy) * temp);
    spll_obj->osg_coeff.osg_qb1 = __builtin_riscv_mpy2f32(spll_obj->osg_coeff.osg_qb0);
    spll_obj->osg_coeff.osg_qb2 = spll_obj->osg_coeff.osg_qb0;
#else
    wn = spll_obj->fn * (float32_t)2.0f * (float32_t)3.14159265f;
    spll_obj->osg_coeff.osg_k = (float32_t)(0.5);
    osgx = (float32_t)(2.0f * 0.5f * wn * spll_obj->delta_t);
    spll_obj->osg_coeff.osg_x = (float32_t)(osgx);
    osgy = (float32_t)(wn * spll_obj->delta_t * wn * spll_obj->delta_t);
    spll_obj->osg_coeff.osg_y = (float32_t)(osgy);
    temp = (float32_t)1.0 / (osgx + osgy + 4.0f);
    spll_obj->osg_coeff.osg_b0 = ((float32_t)osgx * temp);
    spll_obj->osg_coeff.osg_b2 = ((float32_t)(-1.0f) * spll_obj->osg_coeff.osg_b0);
    spll_obj->osg_coeff.osg_a1 = ((float32_t)(2.0 * (4.0f - osgy)) * temp);
    spll_obj->osg_coeff.osg_a2 = ((float32_t)(osgx - osgy - 4) * temp);
    spll_obj->osg_coeff.osg_qb0 = ((float32_t)(0.5f * osgy) * temp);
    spll_obj->osg_coeff.osg_qb1 = (spll_obj->osg_coeff.osg_qb0 * (float32_t)(2.0));
    spll_obj->osg_coeff.osg_qb2 = spll_obj->osg_coeff.osg_qb0;
#endif
}

//! \brief Configures the SPLL_1PH_SOGI module
//! \param *spll_obj The SPLL_1PH_SOGI structure
//! \param acFreq Nominal AC frequency for the SPLL Module
//! \param isrFrequency Frequency at which SPLL module is run
//! \param lpf_b0 B0 coefficient of LPF of SPLL
//! \param lpf_b1 B1 coefficient of LPF of SPLL
//! \return None
//!
__STATIC_INLINE void
SPLL_1PH_SOGI_config(SPLL_1PH_SOGI *spll_obj,
                     float32_t acFreq,
                     float32_t isrFrequency,
                     float32_t lpf_b0,
                     float32_t lpf_b1) {
    spll_obj->fn = acFreq;
#ifdef ZHANLU
    spll_obj->delta_t = divf32((1.0f),isrFrequency);
#else
    spll_obj->delta_t = ((1.0f) / isrFrequency);
#endif
    SPLL_1PH_SOGI_coeff_calc(spll_obj);

    spll_obj->lpf_coeff.b0 = lpf_b0;
    spll_obj->lpf_coeff.b1 = lpf_b1;
}

//! \brief Run the SPLL_1PH_SOGI module
//! \param *spll_obj The SPLL_1PH_SOGI structure pointer
//! \param acValue AC grid voltage in per unit (pu)
//! \return None
//!
__STATIC_INLINE void
SPLL_1PH_SOGI_run(SPLL_1PH_SOGI *spll_obj,
                  float32_t acValue) {
    // Update the spll_obj->u[0] with the grid value
    spll_obj->u[0] = acValue;

    //
    // Orthogonal Signal Generator
    //
    spll_obj->osg_u[0] = (spll_obj->osg_coeff.osg_b0 *
                          (spll_obj->u[0] - spll_obj->u[2])) +
                         (spll_obj->osg_coeff.osg_a1 * spll_obj->osg_u[1]) +
                         (spll_obj->osg_coeff.osg_a2 * spll_obj->osg_u[2]);

    spll_obj->osg_u[2] = spll_obj->osg_u[1];
    spll_obj->osg_u[1] = spll_obj->osg_u[0];

    spll_obj->osg_qu[0] = (spll_obj->osg_coeff.osg_qb0 * spll_obj->u[0]) +
                          (spll_obj->osg_coeff.osg_qb1 * spll_obj->u[1]) +
                          (spll_obj->osg_coeff.osg_qb2 * spll_obj->u[2]) +
                          (spll_obj->osg_coeff.osg_a1 * spll_obj->osg_qu[1]) +
                          (spll_obj->osg_coeff.osg_a2 * spll_obj->osg_qu[2]);

    spll_obj->osg_qu[2] = spll_obj->osg_qu[1];
    spll_obj->osg_qu[1] = spll_obj->osg_qu[0];

    spll_obj->u[2] = spll_obj->u[1];
    spll_obj->u[1] = spll_obj->u[0];

    //
    // Park Transform from alpha beta to d-q axis
    //
    spll_obj->u_Q[0] = (spll_obj->cosine * spll_obj->osg_u[0]) +
                       (spll_obj->sine * spll_obj->osg_qu[0]);
    spll_obj->u_D[0] = (spll_obj->cosine * spll_obj->osg_qu[0]) -
                       (spll_obj->sine * spll_obj->osg_u[0]);

    //
    // Loop Filter
    //
    spll_obj->ylf[0] = spll_obj->ylf[1] +
                       (spll_obj->lpf_coeff.b0 * spll_obj->u_Q[0]) +
                       (spll_obj->lpf_coeff.b1 * spll_obj->u_Q[1]);
    spll_obj->ylf[1] = spll_obj->ylf[0];

    spll_obj->u_Q[1] = spll_obj->u_Q[0];

    //
    // VCO
    //
    spll_obj->fo = spll_obj->fn + spll_obj->ylf[0];

#ifdef ZHANLU
    spll_obj->theta = spll_obj->theta + mpy2pif32(spll_obj->fo * spll_obj->delta_t);
#else
    spll_obj->theta = spll_obj->theta + (spll_obj->fo * spll_obj->delta_t) *
                                            (float32_t)(2.0f * 3.1415926f);
#endif
    if (spll_obj->theta > (float32_t)(2.0f * 3.1415926f)) {
        spll_obj->theta = spll_obj->theta - (float32_t)(2.0f * 3.1415926f);
        // spll_obj->theta=0;
    }
#ifdef ZHANLU
    spll_obj->sine = sinpuf32(spll_obj->theta);
    spll_obj->cosine = cospuf32(spll_obj->theta);
#else
    spll_obj->sine = (float32_t)sinf(spll_obj->theta);
    spll_obj->cosine = (float32_t)cosf(spll_obj->theta);
#endif
}

#ifdef __cplusplus
}
#endif

#endif /*SPLL_1PH_SOGI_H*/
