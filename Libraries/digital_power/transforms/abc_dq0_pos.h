/** 
  *************************************************************************************
  * @file abc_dq0_pos.h 
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

#ifndef ABC_DQ0_POS_H
#define ABC_DQ0_POS_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "../inc/hw_types.h"
#include <math.h>
#include <stdint.h>
#ifdef ZHANLU
#include "zhanlu_nice.h"
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief          Defines the ABC_DQ0_POS transform structure
 *
 * \details        This block stores variables used to transforms
 *                 ABC domain variables to dq domain
 */
typedef struct {
    float32_t alpha; //!< Output: Alpha component (abc-> alpha beta)
    float32_t beta;  //!< Output: Beta component (abc-> alpha beta)
    float32_t d;     //!< Output: D axis component (alpha beta -> d,q,z)
    float32_t q;     //!< Output: Q axis component (alpha beta -> d,q,z)
    float32_t z;     //!< Output: Z axis component (alpha beta -> d,q,z)
} ABC_DQ0_POS;

/**
 * \brief       Resets internal data to zero
 * \param *v    The ABC_DQ0_POS structure pointer
 * \return None
 */
static inline void
ABC_DQ0_POS_reset(ABC_DQ0_POS *v) {
    v->alpha = 0;
    v->beta = 0;
    v->d = 0;
    v->q = 0;
    v->z = 0;
}

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
 * \brief             Run ABC_DQ0_POS routine
 * \param *v          The ABC_DQ0_POS structure pointer
 * \param a           Phase a value
 * \param b           Phase b value
 * \param c           Phase c value
 * \param sine_val    sine value of the grid angle
 * \param cosine_val  cosine value of the grid angle
 * \return None
 */
static inline void
ABC_DQ0_POS_run(ABC_DQ0_POS *v,
                float32_t a, float32_t b, float32_t c,
                float32_t sine_val, float32_t cosine_val) {
    v->alpha = (0.66666666677f) * (a - 0.5f * (b + c));
    v->beta = (0.57735026913f) * (b - c);
    v->z = (0.57735026913f) * (a + b + c);
    v->d = v->alpha * cosine_val + v->beta * sine_val;
    v->q = -v->alpha * sine_val + v->beta * cosine_val;
}

#ifdef __cplusplus
}
#endif

#endif /*ABC_DQ0_POS_H*/
