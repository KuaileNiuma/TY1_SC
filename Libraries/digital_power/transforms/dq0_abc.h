/** 
  *************************************************************************************
  * @file dq0_abc.h 
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

#ifndef DQ0_ABC_H
#define DQ0_ABC_H

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
 * \brief          Defines the DQ0_ABC transform structure
 *
 * \details        This block stores variables used to transform
 *                 DQ0 domain to ABC domain
 */
typedef struct {
    float32_t a;     //!< Output: A phase in 3PH AC Signal Component (alpha beta -> a,b,c)
    float32_t b;     //!< Output: B phase in 3PH AC Signal Component (alpha beta -> a,b,c)
    float32_t c;     //!< Output: C phase in 3PH AC Signal Component (alpha beta -> a,b,c)
    float32_t alpha; //!< Output: Alpha component (abc-> alpha beta)
    float32_t beta;  //!< Output: Beta component  (abc-> alpha beta)
} DQ0_ABC;

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
 * \brief       Resets internal data to zero
 * \param *v    The DQ0_ABC structure pointer
 * \return None
 */
static inline void
DQ0_ABC_reset(DQ0_ABC *v) {
    v->a = 0;
    v->b = 0;
    v->c = 0;
    v->alpha = 0;
    v->beta = 0;
}

/**
 * \brief       Run DQ0_ABC module
 * \param *v    The DQ0_ABC structure pointer
 * \param d     d ref value
 * \param q     q ref value
 * \param z     z ref value
 * \param sine_val    sine value of the grid angle
 * \param cosine_val  cosine value of the grid angle
 * \return None
 */
static inline void
DQ0_ABC_run(DQ0_ABC *v,
            float32_t d, float32_t q, float32_t z,
            float32_t sine_val, float32_t cosine_val) {
    v->alpha = d * cosine_val - q * sine_val;
    v->beta = d * sine_val + q * cosine_val;

    v->a = v->alpha + 0.5f * z;
    v->b = -0.5f * v->alpha + 0.8660254f * v->beta + 0.5f * z;
    v->c = -0.5f * v->alpha - 0.8660254f * v->beta + 0.5f * z;

}

#ifdef __cplusplus
}
#endif

#endif /*DQ0_ABC_H*/
