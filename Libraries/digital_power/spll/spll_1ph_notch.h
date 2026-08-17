/** 
  *************************************************************************************
  * @file spll_1ph_notch.h 
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

#ifndef SPLL_1PH_NOTCH_H
#define SPLL_1PH_NOTCH_H

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
 * \brief Defines the SPLL_1PH_NOTCH_COEFF structure
 */
typedef struct {
    float32_t b2;
    float32_t b1;
    float32_t b0;
    float32_t a2;
    float32_t a1;
} SPLL_1PH_NOTCH_COEFF;

/**
 * \brief Defines the SPLL_1PH_NOTCH_LPF_COEFF structure
 */
typedef struct {
    float32_t b1;
    float32_t b0;
    float32_t a1;
} SPLL_1PH_NOTCH_LPF_COEFF;

/**
 * \brief Defines the SPLL_1PH_NOTCH
 *        structure
 *
 * \details The SPLL_1PH_NOTCH can be used to extract the phase of
 *          the ac grid from the sensed single phase grid voltage
 */
typedef struct {
    float32_t upd[3];                   //!< Phase detect buffer
    float32_t y_notch1[3];              //!< Notch filter1 data storage
    float32_t y_notch2[3];              //!< Notch filter2 data storage
    float32_t ylf[2];                   //!< Loop filter data storage
    float32_t fo;                       //!< Output frequency of PLL(Hz)
    float32_t fn;                       //!< Nominal frequency (Hz)
    float32_t theta;                    //!< Angle output (0-2*pi)
    float32_t cosine;                   //!< Cosine value of the PLL angle
    float32_t sine;                     //!< Sine value of the PLL angle
    float32_t delta_t;                  //!< Inverse of the ISR rate at which module is called
    SPLL_1PH_NOTCH_COEFF notch_coeff;   //!< Notch filter coeffcient structure
    SPLL_1PH_NOTCH_LPF_COEFF lpf_coeff; //!< Loop filter coeffcient structure
} SPLL_1PH_NOTCH;

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
 * \brief Resets internal data to zero,
 * \param *spll_obj The SPLL_1PH_NOTCH structure pointer
 * \return None
 */
__STATIC_INLINE void
SPLL_1PH_NOTCH_reset(SPLL_1PH_NOTCH *spll_obj) {
    spll_obj->upd[0] = (float32_t)(0.0);
    spll_obj->upd[1] = (float32_t)(0.0);

    spll_obj->y_notch1[0] = (float32_t)(0.0);
    spll_obj->y_notch1[1] = (float32_t)(0.0);
    spll_obj->y_notch1[2] = (float32_t)(0.0);

    spll_obj->y_notch2[0] = (float32_t)(0.0);
    spll_obj->y_notch2[1] = (float32_t)(0.0);
    spll_obj->y_notch2[2] = (float32_t)(0.0);

    spll_obj->ylf[0] = (float32_t)(0.0);
    spll_obj->ylf[1] = (float32_t)(0.0);

    spll_obj->fo = (float32_t)(0.0);

    spll_obj->theta = (float32_t)(0.0);

    spll_obj->sine = (float32_t)(0.0);
    spll_obj->cosine = (float32_t)(0.0);
}

/**
 * \brief Calculates the coefficients for SPLL_1PH_NOTCH filter
 * \param *spll_obj The SPLL_1PH_NOTCH structure pointer
 * \param c1 c1 Notch paramater
 * \param c2 c2 Notch Parameter
 * \return None
 */
__STATIC_INLINE void
SPLL_1PH_NOTCH_coeff_calc(SPLL_1PH_NOTCH *spll_obj,
                          float32_t c1, float32_t c2) {
    float32_t notch_freq;
    float32_t temp1, temp2;
    float32_t wn2;
    float32_t Ts, Fs;

#ifdef ZHANLU
    float32_t Fs4;
    float32_t Wn2_2,Wn2_4;

    notch_freq = __builtin_riscv_mpy2pif32(spll_obj->fn);
    Ts = spll_obj->delta_t;
    Fs = __builtin_riscv_divf32(1.0f,Ts);
    //
    // pre warp the notch frequency
    //
    wn2 = __builtin_riscv_mpy2f32(Fs * tanf(notch_freq * ((float32_t)3.141592653589) * Ts));

    Fs4 = __builtin_riscv_mpy2f32(__builtin_riscv_mpy2f32(Fs * Fs));
    Wn2_2 = __builtin_riscv_mpy2f32(wn2);
    Wn2_4 = __builtin_riscv_mpy2f32(__builtin_riscv_mpy2f32(wn2));

    temp1 = Fs4 + Wn2_4 * c2 * Fs + wn2 * wn2;
    temp2 = __builtin_riscv_divf32(1.0f,(Fs4 + Wn2_4 * c1 * Fs + wn2 * wn2));

    spll_obj->notch_coeff.b0 = temp1 * temp2;
    spll_obj->notch_coeff.b1 = (-8 * Fs * Fs + Wn2_2 * wn2) * temp2;
    spll_obj->notch_coeff.b2 = (Fs4 - Wn2_4 * c2 * Fs + wn2 * wn2) * temp2;
    spll_obj->notch_coeff.a1 = (-8 * Fs * Fs + Wn2_2 * wn2) * temp2;
    spll_obj->notch_coeff.a2 = (Fs4 - Wn2_4 * c1 * Fs + wn2 * wn2) * temp2;
#else
    notch_freq = 2 * 3.14159265f * spll_obj->fn;
    Ts = spll_obj->delta_t;
    Fs = 1 / Ts;

    //
    // pre warp the notch frequency
    //
    wn2 = 2 * Fs * tanf(notch_freq * ((float32_t)3.141592653589) * Ts);

    temp1 = 4 * Fs * Fs + 4 * wn2 * c2 * Fs + wn2 * wn2;
    temp2 = 1 / (4 * Fs * Fs + 4 * wn2 * c1 * Fs + wn2 * wn2);

    spll_obj->notch_coeff.b0 = temp1 * temp2;
    spll_obj->notch_coeff.b1 = (-8 * Fs * Fs + 2 * wn2 * wn2) * temp2;
    spll_obj->notch_coeff.b2 = (4 * Fs * Fs - 4 * wn2 * c2 * Fs + wn2 * wn2) * temp2;
    spll_obj->notch_coeff.a1 = (-8 * Fs * Fs + 2 * wn2 * wn2) * temp2;
    spll_obj->notch_coeff.a2 = (4 * Fs * Fs - 4 * wn2 * c1 * Fs + wn2 * wn2) * temp2;
#endif

}

/**
 * \brief  Configures the SPLL_1PH_NOTCH module
 * \param  *spll_obj The SPLL_1PH_NOTCH structure pointer
 * \param  acFreq Nominal AC frequency for the SPLL Module
 * \param  isrFrequency Nominal AC frequency for the SPLL Module
 * \param  lpf_b0 B0 coefficient of LPF of SPLL
 * \param  lpf_b1 B1 coefficient of LPF of SPLL
 * \param  c1 c1 Notch paramater
 * \param  c2 c2 Notch Parameter
 * \return None
 */
__STATIC_INLINE void
SPLL_1PH_NOTCH_config(SPLL_1PH_NOTCH *spll_obj,
                      float32_t acFreq,
                      float32_t isrFrequency,
                      float32_t lpf_b0,
                      float32_t lpf_b1,
                      float32_t c1,
                      float32_t c2) {
    spll_obj->fn = acFreq;
#ifdef ZHANLU
    spll_obj->delta_t = __builtin_riscv_divf32((1.0f),isrFrequency);
#else
    spll_obj->delta_t = ((1.0f) / isrFrequency);
#endif

    SPLL_1PH_NOTCH_coeff_calc(spll_obj,
                              c1,
                              c2);

    spll_obj->lpf_coeff.b0 = lpf_b0;
    spll_obj->lpf_coeff.b1 = lpf_b1;
}

/**
 * \brief  Runs the SPLL_1PH_NOTCH module
 * \param  *spll_obj The SPLL_1PH_NOTCH structure pointer
 * \param  acValue AC grid voltage in per unit (pu)
 * \return None
 */
__STATIC_INLINE void
SPLL_1PH_NOTCH_run(SPLL_1PH_NOTCH *spll_obj,
                   float32_t acValue) {
    //
    // Phase detect
    //
    spll_obj->upd[0] = acValue * spll_obj->cosine;

    //
    // Notch Filter
    //
    spll_obj->y_notch1[0] = -spll_obj->y_notch1[1] * spll_obj->notch_coeff.a1 - spll_obj->y_notch1[2] * spll_obj->notch_coeff.a2 + spll_obj->upd[0] * spll_obj->notch_coeff.b0 + spll_obj->upd[1] * spll_obj->notch_coeff.b1 + spll_obj->upd[2] * spll_obj->notch_coeff.b2;

    spll_obj->y_notch2[0] = -spll_obj->y_notch2[1] * spll_obj->notch_coeff.a1 - spll_obj->y_notch2[2] * spll_obj->notch_coeff.a2 + spll_obj->y_notch1[0] * spll_obj->notch_coeff.b0 + spll_obj->y_notch1[1] * spll_obj->notch_coeff.b1 + spll_obj->y_notch1[2] * spll_obj->notch_coeff.b2;

    //
    // Loop Filter
    //
    spll_obj->ylf[0] = spll_obj->ylf[1] + (spll_obj->lpf_coeff.b0 * spll_obj->y_notch2[0]) + (spll_obj->lpf_coeff.b1 * spll_obj->y_notch2[1]);

    // spll_obj->ylf[0] = (spll_obj->ylf[0]>100)?100:spll_obj->ylf[0];
    // spll_obj->ylf[0] = (spll_obj->ylf[0]<-100)?-100:spll_obj->ylf[0];

    //
    // update the Upd array for future sample
    //
    spll_obj->upd[2] = spll_obj->upd[1];
    spll_obj->upd[1] = spll_obj->upd[0];

    spll_obj->y_notch1[2] = spll_obj->y_notch1[1];
    spll_obj->y_notch1[1] = spll_obj->y_notch1[0];

    spll_obj->y_notch2[2] = spll_obj->y_notch2[1];
    spll_obj->y_notch2[1] = spll_obj->y_notch2[0];

    spll_obj->ylf[1] = spll_obj->ylf[0];

    //
    // VCO
    //
    spll_obj->fo = spll_obj->fn + spll_obj->ylf[0];

#ifdef ZHANLU
    spll_obj->theta = spll_obj->theta + __builtin_riscv_mpy2pif32((spll_obj->fo * spll_obj->delta_t));
#else
    spll_obj->theta = spll_obj->theta + (spll_obj->fo * spll_obj->delta_t) * (float32_t)(2.0 * 3.1415926);
#endif

    if (spll_obj->theta > (float32_t)(2.0 * 3.1415926)) {
        spll_obj->theta = spll_obj->theta - (float32_t)(2.0 * 3.1415926);
    }
#ifdef ZHANLU
    spll_obj->sine = __builtin_riscv_sinpuf32(spll_obj->theta);
    spll_obj->cosine = __builtin_riscv_cospuf32(spll_obj->theta);
#else
    spll_obj->sine = (float32_t)sinf(spll_obj->theta);
    spll_obj->cosine = (float32_t)cosf(spll_obj->theta);
#endif
}

#ifdef __cplusplus
}
#endif

#endif /*SPLL_1PH_NOTCH_H*/
