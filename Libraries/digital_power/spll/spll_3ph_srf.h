/** 
  *************************************************************************************
  * @file spll_3ph_srf.h 
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

#ifndef SPLL_3PH_SRF_H
#define SPLL_3PH_SRF_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "../inc/hw_types.h"
#include <math.h>
#include <stdint.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 * \brief          Defines the coefficients for a loop filter
 *
 * \details        Loop filter coefficients
 *
 *
 */
typedef struct {
    float32_t b1;
    float32_t b0;
} SPLL_3PH_SRF_LPF_COEFF;

/**
 * \brief          Defines the SPLL_3PH_SRF structure
 *
 * \details        This software module implements a software phase lock loop
 *                 based on synchronous reference frame for
 *                grid connection to three phase grid
 */
typedef struct {
    float32_t v_q[2];                 //!< Rotating reference frame Q-axis value
    float32_t ylf[2];                 //!< Data buffer for loop filter output
    float32_t fo;                     //!< Output frequency of PLL
    float32_t fn;                     //!< Nominal frequency
    float32_t theta[2];               //!< Grid phase angle
    float32_t sine;                   //!< Sin of the grid frequency angle
    float32_t delta_t;                //!< Inverse of the ISR rate at which module is called
    SPLL_3PH_SRF_LPF_COEFF lpf_coeff; //!< Loop filter coefficients
} SPLL_3PH_SRF;

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

/* None */

/**
 * \brief              Initialize SPLL_3PH_SRF module
 * \param grid_freq    The grid frequency
 * \param delta_t      1/Frequency of calling the PLL routine
 * \param *spll_obj     The SPLL_3PH_SRF structure
 * \return None
 */
__STATIC_INLINE void
SPLL_3PH_SRF_init(float32_t grid_freq, float32_t delta_t,
                  SPLL_3PH_SRF *spll_obj) {
    spll_obj->v_q[0] = 0.0f;
    spll_obj->v_q[1] = 0.0f;

    spll_obj->ylf[0] = 0.0f;
    spll_obj->ylf[1] = 0.0f;

    spll_obj->fo = 0.0f;
    spll_obj->fn = (float32_t)(grid_freq);

    spll_obj->theta[0] = 0.0f;
    spll_obj->theta[1] = 0.0f;

    spll_obj->delta_t = (float32_t)delta_t;
}

/**
 * \brief              Reset SPLL_3PH_SRF module
 * \param *spll_obj     The SPLL_3PH_SRF structure
 * \return None
 */
__STATIC_INLINE void
SPLL_3PH_SRF_reset(SPLL_3PH_SRF *spll_obj) {
    spll_obj->v_q[0] = 0.0f;
    spll_obj->v_q[1] = 0.0f;

    spll_obj->ylf[0] = 0.0f;
    spll_obj->ylf[1] = 0.0f;

    spll_obj->fo = 0.0f;

    spll_obj->theta[0] = 0.0f;
    spll_obj->theta[1] = 0.0f;
}

/**
 * \brief              Run SPLL_3PH_SRF module
 * \param v_q          Q component of the grid voltage
 * \param *spll_obj     The SPLL_3PH_SRF structure
 */
__STATIC_INLINE void
SPLL_3PH_SRF_run(float32_t v_q, SPLL_3PH_SRF *spll_obj) {

    //
    // Update the spll_obj->v_q[0] with the grid value
    //
    spll_obj->v_q[0] = v_q;

    //
    // Loop Filter
    //
    spll_obj->ylf[0] = spll_obj->ylf[1] + (spll_obj->lpf_coeff.b0 * spll_obj->v_q[0]) + (spll_obj->lpf_coeff.b1 * spll_obj->v_q[1]);
    spll_obj->ylf[1] = spll_obj->ylf[0];
    spll_obj->v_q[1] = spll_obj->v_q[0];

    spll_obj->ylf[0] = (spll_obj->ylf[0] > (float32_t)(200.0)) ? (float32_t)(200.0) : spll_obj->ylf[0];

    //
    // VCO
    //
    spll_obj->fo = spll_obj->fn + spll_obj->ylf[0];

#ifdef ZHANLU
    spll_obj->theta[0] = spll_obj->theta[1] + __builtin_riscv_mpy2pif32(spll_obj->fo * spll_obj->delta_t);
#else
    spll_obj->theta[0] = spll_obj->theta[1] +
                         ((spll_obj->fo * spll_obj->delta_t) *
                          (float32_t)(2.0f * 3.1415926f));
#endif
    if (spll_obj->theta[0] > (float32_t)(2.0f * 3.1415926f)) {
        spll_obj->theta[0] = spll_obj->theta[0] - (float32_t)(2.0f * 3.1415926f);
    }

    spll_obj->theta[1] = spll_obj->theta[0];
#ifdef ZHANLU
    spll_obj->sine = __builtin_riscv_sinpuf32(spll_obj->theta[1]);
#else
    spll_obj->sine = sinf(spll_obj->theta[1]);
#endif
}

#ifdef __cplusplus
}
#endif

#endif /*SPLL_3PH_SRF_H*/
