/** 
  *************************************************************************************
  * @file NLPID.h 
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

#ifndef DEVICE_NLPID_H
#define DEVICE_NLPID_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "DCL.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

//--- Non-linear PID controllers ---------------------------------------------
/*
 * @brief          Defines the shadow DCL_NLPID controller structure
 */
typedef struct dcl_nlpid_sps {
    float32_t Kp;      // Linear proportional gain
    float32_t Ki;      // Linear integral gain
    float32_t Kd;      // Linear derivative gain
    float32_t alpha_p; // P path non-linear exponent
    float32_t alpha_i; // I path non-linear exponent
    float32_t alpha_d; // D path non-linear exponent
    float32_t delta_p; // P path linearized range
    float32_t delta_i; // I path linearized range
    float32_t delta_d; // D path linearized range
    float32_t gamma_p; // P path gain limit
    float32_t gamma_i; // I path gain limit
    float32_t gamma_d; // D path gain limit
    float32_t c1;      // D path filter coefficient 1
    float32_t c2;      // D path filter coefficient 2
    float32_t Umax;    // Upper saturation limit
    float32_t Umin;    // Lower saturation limit
} DCL_NLPID_SPS;

/*
 * @brief          Defines default values to initialize the DCL_NLPID structure
 */
#define NLPID_SPS_DEFAULTS                                                                              \
    do {                                                                                                \
        1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.1f, 0.1f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f \
    } while (0)

/*
 * @brief          Defines the active DCL_NLPID controller structure
 */
typedef struct dcl_nlpid {
    float32_t Kp;       // Linear proportional gain
    float32_t Ki;       // Linear integral gain
    float32_t Kd;       // Linear derivative gain
    float32_t alpha_p;  // P path non-linear exponent
    float32_t alpha_i;  // I path non-linear exponent
    float32_t alpha_d;  // D path non-linear exponent
    float32_t delta_p;  // P path linearized range
    float32_t delta_i;  // I path linearized range
    float32_t delta_d;  // D path linearized range
    float32_t gamma_p;  // P path gain limit
    float32_t gamma_i;  // I path gain limit
    float32_t gamma_d;  // D path gain limit
    float32_t c1;       // D path filter coefficient 1
    float32_t c2;       // D path filter coefficient 2
    float32_t d2;       // D path filter intermediate storage 1
    float32_t d3;       // D path filter intermediate storage 2
    float32_t i7;       // I path intermediate storage
    float32_t i16;      // Intermediate saturation storage
    float32_t i18;      // Spare
    float32_t Umax;     // Upper saturation limit
    float32_t Umin;     // Lower saturation limit
    DCL_NLPID_SPS *sps; // Pointer to shadow parameter structure
    DCL_CSS *css;       // Pointer to controller support structure
} DCL_NLPID;

/*
 * @brief          Defines default values to initialize the DCL_NLPID structure
 */
#define NLPID_DEFAULTS                                                                                              \
    do {                                                                                                            \
        1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.1f, 0.1f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, \
            0.0f, 1.0f, -1.0f, NULL_ADDR, NULL_ADDR                                                                 \
    } while (0)

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

//--- Non-linear PID controllers ---------------------------------------------
/*
 * @brief          Resets DCL_NLPID internal storage data
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @return         None
 */
__STATIC_INLINE void DCL_resetNLPID(DCL_NLPID *p) {
    p->d2 = p->d3 = p->i7 = 0.0f;
    p->i16 = 1.0f;
}

/*
 * @brief          Copies control parameters from one DCL_NLPID structure to another
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @return         None
 */
__STATIC_INLINE void DCL_updateNLPID(DCL_NLPID *p) {

    if (p->css->sts == STS_UPDATE_PENDING) {
        p->Kp = p->sps->Kp;
        p->Ki = p->sps->Ki;
        p->Kd = p->sps->Kd;
        p->alpha_p = p->sps->alpha_p;
        p->alpha_i = p->sps->alpha_i;
        p->alpha_d = p->sps->alpha_d;
        p->delta_p = p->sps->delta_p;
        p->delta_i = p->sps->delta_i;
        p->delta_d = p->sps->delta_d;
        p->gamma_p = p->sps->gamma_p;
        p->gamma_i = p->sps->gamma_i;
        p->gamma_d = p->sps->gamma_d;
        p->c1 = p->sps->c1;
        p->c2 = p->sps->c2;
        p->Umax = p->sps->Umax;
        p->Umin = p->sps->Umin;
        DCL_CLEAR_UPDATE_REQUEST(p);
    }
}

/*
 * @brief          Loads the shadow derivative LP filter coefficients
 *                 Note: active coefficients unchanged DCL_updateNLPID() called
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @param[in] fc   The desired filter bandwidth in Hz
 * @return         None
 */
__STATIC_INLINE void DCL_setNLPIDfilterBW(DCL_NLPID *p, float32_t fc) {
#ifdef ZHANLU
	float32_t tau2;
	float32_t tau = __builtin_riscv_divf32(1.0f,__builtin_riscv_mpy2pif32(fc));
	tau2 = __builtin_riscv_mpy2f32(tau);
    p->sps->c1 = __builtin_riscv_divf32(2.0f,(p->css->T + tau2));
    p->sps->c2 = __builtin_riscv_divf32((p->css->T - tau2),(p->css->T + tau2));
#else
    float32_t tau = 1.0f / (2.0f * CONST_PI_32 * fc);

    p->sps->c1 = 2.0f / (p->css->T + 2.0f * tau);
    p->sps->c2 = (p->css->T - 2.0f * tau) / (p->css->T + 2.0f * tau);
#endif
}

/*
 * @brief          Loads the NLPID derivative path filter active coefficients
 *                 Note: new coefficients take effect immediately.  SPS &
 *                 CSS contents are unaffected.
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @param[in] fc   The desired filter bandwidth in Hz
 * @param[in] T    The controller update rate in seconds
 * @return         None
 */
__STATIC_INLINE void DCL_setActiveNLPIDfilterBW(DCL_NLPID *p, float32_t fc, float32_t T) {
	float32_t tau;
#ifdef ZHANLU
    float32_t tau2;
    tau = __builtin_riscv_divf32(1.0f,__builtin_riscv_mpy2pif32(fc));
    tau2 = __builtin_riscv_mpy2f32(tau);
    p->c1 = __builtin_riscv_divf32(2.0f,(T + tau2));
    p->c2 = __builtin_riscv_divf32((T - tau2),(T + tau2));
#else
    tau = 1.0f / (2.0f * CONST_PI_32 * fc);
    p->c1 = 2.0f / (T + 2.0f * tau);
    p->c2 = (T - 2.0f * tau) / (T + 2.0f * tau);
#endif
}

/*
 * @brief          Returns the derivative LP filter bandwidth in Hz
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @return         The filter bandwidth in Hz
 */
__STATIC_INLINE float32_t DCL_getNLPIDfilterBW(DCL_NLPID *p) {
#ifdef ZHANLU
    float32_t tau;
    tau = __builtin_riscv_divf32((__builtin_riscv_naddcstf32(p->c1 * p->css->T,2)),__builtin_riscv_mpy2f32(p->c1));
    return __builtin_riscv_divf32(1.0f,__builtin_riscv_mpy2pif32(tau));
#else
    float32_t tau = ((2.0f - p->c1 * p->css->T) / (2.0f * p->c1));
    return (1.0f / (2.0f * CONST_PI_32 * tau));
#endif
}

/*
 * @brief          Returns the linearized region gain for specified (alpha,delta)
 * @param[in] alpha    The non-linear gain
 * @param[in] delta    The linear region semi-width
 * @return         The linear region gain
 */
__STATIC_INLINE float32_t DCL_getNLPIDgamma(float32_t alpha, float32_t delta) {
#ifdef ZHANLU
    return ((float32_t)powf(delta, __builtin_riscv_sub1f32(alpha)));
#else
    return ((float32_t)powf(delta, (alpha - 1.0f)));
#endif
}

/*
 * @brief          Returns the semi-width of the linear gain region for specified (alpha,gamma)
 * @param[in] alpha    The non-linear gain
 * @param[in] gamma    The linear region gain
 * @return         The linear region semi-width
 */
__STATIC_INLINE float32_t DCL_getNLPIDdelta(float32_t alpha, float32_t gamma) {
#ifdef ZHANLU
    return ((float32_t)powf(gamma, __builtin_riscv_divf32(1.0f,__builtin_riscv_sub1f32(alpha))));
#else
    return ((float32_t)powf(gamma, (1.0f / (alpha - 1.0f))));
#endif
}

/*
 * @brief          Computes the linearized gains for each path
 *                 Note: active coefficients not update DCL_updateNLPID() called
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @return         None
 */
__STATIC_INLINE void DCL_setNLPIDgamma(DCL_NLPID *p) {
#ifdef ZHANLU
    float32_t xP = (float32_t)powf(p->sps->delta_p, __builtin_riscv_sub1f32(p->sps->alpha_p));
    float32_t xI = (float32_t)powf(p->sps->delta_i, __builtin_riscv_sub1f32(p->sps->alpha_i));
    float32_t xD = (float32_t)powf(p->sps->delta_d, __builtin_riscv_sub1f32(p->sps->alpha_d));
#else
    float32_t xP = (float32_t)powf(p->sps->delta_p, (p->sps->alpha_p - 1.0f));
    float32_t xI = (float32_t)powf(p->sps->delta_i, (p->sps->alpha_i - 1.0f));
    float32_t xD = (float32_t)powf(p->sps->delta_d, (p->sps->alpha_d - 1.0f));
#endif

    p->sps->gamma_p = xP;
    p->sps->gamma_i = xI;
    p->sps->gamma_d = xD;
}

/*
 * @rief          Computes the linearized gains for each path and loads the
 *                 parameters in the active NLPID structure
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @return         None
 */
__STATIC_INLINE void DCL_setActiveNLPIDgamma(DCL_NLPID *p) {
#ifdef ZHANLU
    float32_t xP = (float32_t)powf(p->delta_p, __builtin_riscv_sub1f32(p->alpha_p));
    float32_t xI = (float32_t)powf(p->delta_i, __builtin_riscv_sub1f32(p->alpha_i));
    float32_t xD = (float32_t)powf(p->delta_d, __builtin_riscv_sub1f32(p->alpha_d));
#else
    float32_t xP = (float32_t)powf(p->delta_p, (p->alpha_p - 1.0f));
    float32_t xI = (float32_t)powf(p->delta_i, (p->alpha_i - 1.0f));
    float32_t xD = (float32_t)powf(p->delta_d, (p->alpha_d - 1.0f));
#endif
    p->gamma_p = xP;
    p->gamma_i = xI;
    p->gamma_d = xD;
}

/*
 * @brief          Executes a parallel form non-linear PID controller on the FPU32
 * @param[in] p    Pointer to the DCL_NLPID structure
 * @param[in] rk   The controller set-point reference
 * @param[in] yk   The measured feedback value
 * @param[in] lk   External output clamp flag
 * @return         The control effort
 */
__STATIC_INLINE float32_t DCL_runNLPID_C1(DCL_NLPID *p, float32_t rk, float32_t yk, float32_t lk) {
    float32_t v1, v2, v3, v4, v5, v8, v9, v10, v12, v13, v14, v15;

    // pre-conditioning block
    v1 = (rk - yk) * 0.5f;
    v2 = (v1 < 0.0f) ? -1.0f : 1.0f;
    v3 = fabsf(v1);

    // non-linear modules
    v4 = ((v3 > p->delta_p) ? (v2 * (float32_t)powf(v3, p->alpha_p)) : (v1 * p->gamma_p));
    v5 = ((v3 > p->delta_i) ? (v2 * (float32_t)powf(v3, p->alpha_i)) : (v1 * p->gamma_i));
    v9 = ((v3 > p->delta_d) ? (v2 * (float32_t)powf(v3, p->alpha_d)) : (v1 * p->gamma_d));

    // integral path
    v8 = (v5 * p->Kp * p->Ki * p->i16) + p->i7;
    p->i7 = v8;

    // derivative path
    v10 = v9 * p->Kd * p->c1;
    v12 = v10 - p->d2 - p->d3;
    p->d2 = v10;
    p->d3 = v12 * p->c2;

    // output sum & clamp
    v13 = (p->Kp * (v4 + v12)) + v8;
#ifdef ZHANLU
    v14=satf32(v13,p->Umax,p->Umin);
#else
    v14 = (v13 > p->Umax) ? p->Umax : v13;
    v14 = (v14 < p->Umin) ? p->Umin : v14;
#endif
    v15 = (v14 == v13) ? 1.0f : 0.0f;
    p->i16 = v15 * lk;

    return (v14);
}

/*
 * @rief          Executes a series form non-linear PID controller on the FPU32
 * @aram[in] p    Pointer to the DCL_NLPID structure
 * @aram[in] rk   The controller set-point reference
 * @param[in] yk   The measured feedback value
 * @aram[in] lk   External output clamp flag
 * @return         The control effort
 */
__STATIC_INLINE float32_t DCL_runNLPID_C2(DCL_NLPID *p, float32_t rk, float32_t yk, float32_t lk) {
    float32_t v1, v2, vd2, v3, vd3, v4, v5, v6, v8, v9, v12, v15, v16, v17;

    // pre-conditioning block for P & I
    v1 = (rk - yk) * 0.5f;
    v2 = (v1 < 0.0f) ? -1.0f : 1.0f;
    v3 = fabsf(v1);

    // P & I non-linear modules
    v4 = ((v3 > p->delta_p) ? (v2 * (float32_t)powf(v3, p->alpha_p)) : (v1 * p->gamma_p));
    v5 = ((v3 > p->delta_i) ? (v2 * (float32_t)powf(v3, p->alpha_i)) : (v1 * p->gamma_i));

    // D path non-linear block
    vd2 = (yk < 0.0f) ? -1.0f : 1.0f;
    vd3 = fabsf(yk);
    v6 = ((vd3 > p->delta_d) ? (vd2 * (float32_t)powf(vd3, p->alpha_d)) : (yk * p->gamma_d));

    // integral path
    v8 = (v5 * p->Kp * p->Ki * p->i16) + p->i7;
    p->i7 = v8;

    // derivative path
    v15 = v6 * p->Kd * p->c1;
    v16 = v15 - p->d2 - p->d3;
    p->d2 = v15;
    p->d3 = v16 * p->c2;

    // output sum & clamp
    v9 = (p->Kp * (v4 - v16)) + v8;

#ifdef ZHANLU
    v17=satf32(v9,p->Umax,p->Umin);
#else
    v17 = (v9 > p->Umax) ? p->Umax : v9;
    v17 = (v17 < p->Umin) ? p->Umin : v17;
#endif


    v12 = (v17 == v9) ? 1.0f : 0.0f;
    p->i16 = v12 * lk;

    return (v17);
}

//--- Basic non-linear function ----------------------------------------------
/*
 * @brief          Executes the non-linear control function on the FPU32
 * @param[in] x    The input variable
 * @param[in] alpha    The non-linear exponent
 * @param[in] delta    The linear region semi-width
 * @return         The non-linear output
 */
__STATIC_INLINE float32_t DCL_runNLF_C1(float32_t x, float32_t alpha, float32_t delta) {
    float32_t v2 = (x < 0.0f) ? -1.0f : 1.0f;
    float32_t v3 = fabsf(x);

    return ((v3 > delta) ? (v2 * (float32_t)powf(v3, alpha)) : (x * powf(delta, (alpha - 1.0f))));
}

#ifdef __cplusplus
}
#endif

#endif // end of DEVICE_NLPID_H definition
