/** 
  *************************************************************************************
  * @file spll_3ph_ddsrf.h 
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

#ifndef SPLL_3PH_DDSRF_H
#define SPLL_3PH_DDSRF_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#ifdef ZHANLU
#include "zhanlu_nice.h"
#endif
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
 */
typedef struct {
    float32_t b1;
    float32_t b0;
} SPLL_3PH_DDSRF_LPF_COEFF;

/**
 * \brief          Defines the SPLL_3PH_DDSRF structure
 *
 * \details        This software module implements a software phase lock loop
 *                 based on decoupled double synchronous reference frame for
 *                 grid connection to three phase grid
 * \return None
 */
typedef struct {
    float32_t d_p_decoupl; //!< Positive Rotating reference Frame D-axis value
    float32_t d_n_decoupl; //!< Negative Rotating reference Frame D-axis value
    float32_t q_p_decoupl; //!< Positive Rotating reference Frame Q-axis value
    float32_t q_n_decoupl; //!< Negative Rotating reference Frame Q-axis value

    float32_t cos_2theta; //!< Cos of twice the grid frequency angle
    float32_t sin_2theta; //!< Sin of twice the grid frequency angle

    float32_t y[2];            //!< Used to store history for filtering the decoupled D and Q axis components
    float32_t x[2];            //!< Used to store history for filtering the decoupled D and Q axis components
    float32_t w[2];            //!< Used to store history for filtering the decoupled D and Q axis components
    float32_t z[2];            //!< Used to store history for filtering the decoupled D and Q axis components
    float32_t k1;              //!< Lpf coefficient
    float32_t k2;              //!< Lpf coefficient
    float32_t d_p_decoupl_lpf; //!< Decoupled positive sequence D-axis component filtered
    float32_t d_n_decoupl_lpf; //!< Decoupled negative sequence D-axis component filtered
    float32_t q_p_decoupl_lpf; //!< Decoupled positive sequence Q-axis component filtered
    float32_t q_n_decoupl_lpf; //!< Decoupled negative sequence Q-axis component filtered

    float32_t v_q[2];
    float32_t theta[2]; //!< Grid phase angle
    float32_t ylf[2];   //!< Internal Data Buffer for Loop Filter output
    float32_t fo;       //!< Instantaneous Grid Frequency in Hz
    float32_t fn;       //!< Nominal Grid Frequency in Hz
    float32_t delta_t;  //!< 1/Frequency of calling the PLL routine
    SPLL_3PH_DDSRF_LPF_COEFF lpf_coeff;
} SPLL_3PH_DDSRF;

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
/**
 * \brief              Initialize SPLL_3PH_DDSRF module
 * \param grid_freq    The grid frequency
 * \param delta_t      1/Frequency of calling the PLL routine
 * \param k1           parameter
 * \param k2           parameter
 * \param *spll_obj    The SPLL_3PH_DDSRF structure
 * \return None
 */
__STATIC_INLINE void
SPLL_3PH_DDSRF_init(float32_t grid_freq, float32_t delta_t,
                    float32_t k1, float32_t k2,
                    SPLL_3PH_DDSRF *spll_obj) {
    spll_obj->d_p_decoupl = 0.0f;
    spll_obj->d_n_decoupl = 0.0f;

    spll_obj->q_p_decoupl = 0.0f;
    spll_obj->q_n_decoupl = 0.0f;

    spll_obj->d_p_decoupl_lpf = 0.0f;
    spll_obj->d_n_decoupl_lpf = 0.0f;

    spll_obj->q_p_decoupl_lpf = 0.0f;
    spll_obj->q_n_decoupl_lpf = 0.0f;

    spll_obj->y[0] = 0.0f;
    spll_obj->y[1] = 0.0f;

    spll_obj->x[0] = 0.0f;
    spll_obj->x[1] = 0.0f;

    spll_obj->w[0] = 0.0f;
    spll_obj->w[1] = 0.0f;

    spll_obj->z[0] = 0.0f;
    spll_obj->z[1] = 0.0f;

    spll_obj->k1 = k1;
    spll_obj->k2 = k2;

    spll_obj->v_q[0] = 0.0f;
    spll_obj->v_q[1] = 0.0f;

    spll_obj->ylf[0] = 0.0f;
    spll_obj->ylf[1] = 0.0f;

    spll_obj->fo = 0.0f;
    spll_obj->fn = (float32_t)(grid_freq);

    spll_obj->theta[0] = 0.0f;
    spll_obj->theta[1] = 0.0f;

    spll_obj->delta_t = delta_t;
}

/**
 * \brief              Reset SPLL_3PH_DDSRF module
 * \param *spll_obj    The SPLL_3PH_DDSRF structure
 * \return None
 */
__STATIC_INLINE void
SPLL_3PH_DDSRF_reset(SPLL_3PH_DDSRF *spll_obj) {
    spll_obj->d_p_decoupl = 0.0f;
    spll_obj->d_n_decoupl = 0.0f;

    spll_obj->q_p_decoupl = 0.0f;
    spll_obj->q_n_decoupl = 0.0f;

    spll_obj->d_p_decoupl_lpf = 0.0f;
    spll_obj->d_n_decoupl_lpf = 0.0f;

    spll_obj->q_p_decoupl_lpf = 0.0f;
    spll_obj->q_n_decoupl_lpf = 0.0f;

    spll_obj->y[0] = 0.0f;
    spll_obj->y[1] = 0.0f;

    spll_obj->x[0] = 0.0f;
    spll_obj->x[1] = 0.0f;

    spll_obj->w[0] = 0.0f;
    spll_obj->w[1] = 0.0f;

    spll_obj->z[0] = 0.0f;
    spll_obj->z[1] = 0.0f;

    spll_obj->v_q[0] = 0.0f;
    spll_obj->v_q[1] = 0.0f;

    spll_obj->ylf[0] = 0.0f;
    spll_obj->ylf[1] = 0.0f;

    spll_obj->fo = 0.0f;

    spll_obj->theta[0] = 0.0f;
    spll_obj->theta[1] = 0.0f;
}

/**
 * \brief              Run spll_3PH_srf module
 * \param *spll_obj    The spll_3PH_ddsrf structure
 * \param d_p          D Positive seq component of the grid voltage
 * \param d_n          D Negative seq component of the grid voltage
 * \param q_p          Q Positive seq component of the grid voltage
 * \param q_n          Q Negative seq component of the grid voltage
 * \return None
 */
__STATIC_INLINE void
SPLL_3PH_DDSRF_run(SPLL_3PH_DDSRF *spll_obj,
                   float32_t d_p, float32_t d_n,
                   float32_t q_p, float32_t q_n) {
    //
    // before calling this routine run the ABC_DQ0_Pos & Neg run routines
    // pass updated values for d_p,d_n,q_p,q_n
    // and update the cos_2theta and sin_2theta values with the prev angle
    //

    //
    // Decoupling Network
    //
    spll_obj->d_p_decoupl = d_p - (spll_obj->d_n_decoupl_lpf * spll_obj->cos_2theta) - (spll_obj->q_n_decoupl * spll_obj->sin_2theta);
    spll_obj->q_p_decoupl = q_p + (spll_obj->d_n_decoupl_lpf * spll_obj->sin_2theta) - (spll_obj->q_n_decoupl * spll_obj->cos_2theta);

    spll_obj->d_n_decoupl = d_n - (spll_obj->d_p_decoupl_lpf * spll_obj->cos_2theta) + (spll_obj->q_p_decoupl * spll_obj->sin_2theta);
    spll_obj->q_n_decoupl = q_n - (spll_obj->d_p_decoupl_lpf * spll_obj->sin_2theta) - (spll_obj->q_p_decoupl * spll_obj->cos_2theta);

    //
    // Low pass filter
    //

    spll_obj->y[1] = (spll_obj->d_p_decoupl * spll_obj->k1) - (spll_obj->y[0] * spll_obj->k2);
    spll_obj->d_p_decoupl_lpf = spll_obj->y[1] + spll_obj->y[0];
    spll_obj->y[0] = spll_obj->y[1];

    spll_obj->x[1] = (spll_obj->q_p_decoupl * spll_obj->k1) - (spll_obj->x[0] * spll_obj->k2);
    spll_obj->q_p_decoupl_lpf = spll_obj->x[1] + spll_obj->x[0];
    spll_obj->x[0] = spll_obj->x[1];

    spll_obj->w[1] = (spll_obj->d_n_decoupl * spll_obj->k1) - (spll_obj->w[0] * spll_obj->k2);
    spll_obj->d_n_decoupl_lpf = spll_obj->w[1] + spll_obj->w[0];
    spll_obj->w[0] = spll_obj->w[1];

    spll_obj->z[1] = (spll_obj->q_n_decoupl * spll_obj->k1) - (spll_obj->z[0] * spll_obj->k2);
    spll_obj->q_n_decoupl_lpf = spll_obj->z[1] + spll_obj->z[0];
    spll_obj->z[0] = spll_obj->z[1];

    spll_obj->v_q[0] = spll_obj->q_p_decoupl;

    //
    // Loop Filter
    //
    spll_obj->ylf[0] = spll_obj->ylf[1] + (spll_obj->lpf_coeff.b0 * spll_obj->v_q[0]) + (spll_obj->lpf_coeff.b1 * spll_obj->v_q[1]);
    spll_obj->ylf[1] = spll_obj->ylf[0];
    spll_obj->v_q[1] = spll_obj->v_q[0];

    //
    // VCO
    //
    spll_obj->fo = spll_obj->fn + spll_obj->ylf[0];

#ifdef ZHANLU
    spll_obj->theta[0] = spll_obj->theta[1] + __builtin_riscv_mpy2pif32(spll_obj->fo * spll_obj->delta_t);
#else
    spll_obj->theta[0] = spll_obj->theta[1] +
                         ((spll_obj->fo * spll_obj->delta_t) * (float32_t)(2.0f * 3.1415926f));
#endif
    if (spll_obj->theta[0] > (float32_t)(2.0f * 3.1415926f)) {
        spll_obj->theta[0] = spll_obj->theta[0] -
                             (float32_t)(2.0f * 3.1415926f);
    }

    spll_obj->theta[1] = spll_obj->theta[0];

#ifdef ZHANLU
    spll_obj->cos_2theta = __builtin_riscv_cospuf32(spll_obj->theta[1] * 2.0f);
    spll_obj->sin_2theta = __builtin_riscv_sinpuf32(spll_obj->theta[1] * 2.0f);
#else
    spll_obj->cos_2theta = cosf(spll_obj->theta[1] * 2.0f);
    spll_obj->sin_2theta = sinf(spll_obj->theta[1] * 2.0f);
#endif
}

#ifdef __cplusplus
}
#endif

#endif /*SPLL_3PH_DDSRF_H*/
