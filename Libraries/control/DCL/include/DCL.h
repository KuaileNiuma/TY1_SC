/** 
  *************************************************************************************
  * @file DCL.h 
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
#ifndef DEVICE_DCL_H
#define DEVICE_DCL_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <complex.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <../inc/hw_types.h>
#include "zhanlu_nice.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

// #define RAND_MAX 32767
/*
 * @brief          Local definitions of mathematical constants
 */
#define CONST_PI_32 3.14159265358979323846f
#define CONST_2PI_32 2.0f * CONST_PI_32

// #define CONST_PI_64 3.1415926535897932384626433832795028841971693993751058209749445923078164062L
// #define CONST_2PI_64 2.0L * CONST_PI_64

/*
 * @brief          Defines 32-bit null address for pointer initialization
 */
#define NULL_ADDR 0x00000000

/*
 * @brief          Define the acceptable FPU numerical tolerances
 */
#define DEFAULT_FPU32_TOL 1.0e-06f
// #define DEFAULT_FPU64_TOL 1.0e-10f

/*
 * @brief          Determines numerical proximity to specified value
 */
#define F32_IS_VALUE(x, y) (((x < (y + DEFAULT_FPU32_TOL)) && (x > (y - DEFAULT_FPU32_TOL))) ? 1 : 0)
// #define F64_IS_VALUE(x, y) (((x < (y + DEFAULT_FPU64_TOL)) && (x > (y - DEFAULT_FPU64_TOL))) ? 1 : 0)

/*
 * @brief          Determines numerical proximity to zero
 */
#define F32_IS_ZERO(x) F32_IS_VALUE(x, 0.0f)
// #define F64_IS_ZERO(x) F64_IS_VALUE(x, 0.0f)

/*
 * @brief          Returns a random floating point result between -1.0 and +1.0
 *                 where 'a' is a single or double precision float.
 *                 Useful for initialization of arrays and matrices during test.
 *					Ensure compiler switch "--fp_mode = relaxed" is set to ensure h/w division.
 */
// float32_t s = DCL_randf(1.0f);
#ifdef ZHANLU
#define DCL_randf(a) (a * __builtin_riscv_sub1f32(__builtin_riscv_divf32((float32_t)rand(),(float32_t)(RAND_MAX >> 1))))
#else
#define DCL_randf(a) (a * ((float32_t)rand() / (float32_t)(RAND_MAX >> 1) - 1.0f))
#endif

// #define DCL_randf64(a) (a * ((float64_t)rand() / (float64_t)(RAND_MAX >> 1) - 1.0L))

/*
 * @brief          Defines the lower limit on derivative filter coefficient c2
 *                 in order for fc to lie below the Nyquist frequency
 */
#ifdef ZHANLU
#define DCL_C2_LIMIT_32 __builtin_riscv_divf32(__builtin_riscv_naddcstf32(CONST_PI_32,2),(2.0f + CONST_PI_32))
#else
#define DCL_C2_LIMIT_32 ((2.0f - CONST_PI_32) / (2.0f + CONST_PI_32))
#endif

// #define DCL_C2_LIMIT_64 ((2.0L - CONST_PI_64) / (2.0L + CONST_PI_64))

/*
 * @brief          Define the default control period in seconds
 */
#define DCL_DEFAULT_T_F32 100.0e-06f
// #define DCL_DEFAULT_T_F64 100.0e-06L

/*
 * @brief          Build the library with controller test points enabled
 */
#define DCL_TESTPOINTS_ENABLED

/*
 * @brief          Build the library with break points enabled
 */
// #define DCL_BREAK_POINTS_ENABLED
/*
 * @brief          Defines a debug break point
 */
// #ifdef DCL_BREAK_POINTS_ENABLED
// #define DCL_BREAK_POINT asm(" ESTOP0")
// #else
// #define DCL_BREAK_POINT ;
// #endif
/*
 * @brief          Re-definition of legacy controller period call
 */
#define DCL_SET_SAMPLE_RATE DCL_SET_CONTROLLER_PERIOD //  DCL_SET_CONTROLLER_PERIOD

/*********** DCL_refgen.h - Reference generator module header file************/
/*
 * @brief          Defines the minimum normalized increment
 */
#define DCL_REFGEN_MIN_INC 1.0e-06f

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

//--- Controller Common Support Structure ------------------------------------
/*
 * @brief          Defines the controller common support structure
 *
 * @details         The CSS is accessed via a pointer in most of the DCL
 *                 controller structs.  It contains data used for testing and
 *                 configuring the controller, as well as for error checking.
 */
typedef struct dcl_css {
	float32_t tpt; // Test point
	float32_t T;   // Controller period in seconds
	uint32_t sts;  // Status word
	uint32_t err;  // Error code
	uint32_t loc;  // Error location
} DCL_CSS;

/*
 * @brief          Default values to initialize the CSS structure
 */
#define DCL_CSS_DEFAULTS \
    { 0.0f, DCL_DEFAULT_T_F32, 0UL, 0UL, 0UL }

/*
 * @brief          Loads the controller period in the CSS
 *                 CSS pointer must be configured first
 * @param[in] p    Pointer to the controller structure
 * @param[in] a    Sample period in seconds
 * @return         None
 */
#define DCL_SET_CONTROLLER_PERIOD(p, a) ((p)->css->T = a)

//--- Status word ------------------------------------------------------------

/*
 * @brief          Defines the library enumerated status bits
 *
 * @details        To perform a safe parameter update, the user first loads new
 *                 parameters into the controller shadow parameter set, then sets
 *                 the STS_UPDATE_PENDING bit in the controller status word.  The
 *                 next call to the update function performs the "shadow-to-
 *                 active" set copy while global interrupts are disabled.
 */
enum dcl_status_bits {
	STS_NONE = 0UL,                      // Status empty
	STS_UPDATE_PENDING = (1UL << 0),     // Parameter update pending
	STS_CONTROLLER_RUNNING = (1UL << 1), // Controller operation in progress
	STS_ADJUSTMENT_RUNNING = (1UL << 2)  // Parameter adjustment in progress
};

/*
 * @brief          Macros to set the update flag in the status word to initiate
 *                 controller parameter update on next DCL_update() call, and to
 *                 clear the flag on completion.
 */
#define DCL_REQUEST_UPDATE(p) ((p)->css->sts |= STS_UPDATE_PENDING)
#define DCL_CLEAR_UPDATE_REQUEST(p) ((p)->css->sts &= ~STS_UPDATE_PENDING)

/*
 * @brief          Macro to determine whether a parameter update is pending
 *                 based on the STS_UPDATE_PENDING bit in the status word.
 */
#define DCL_UPDATE_WAITING(p) (0UL != ((p)->css->sts & STS_UPDATE_PENDING))

/*
 * @brief          Macros placed at the beginning and end of the controller
 *                 so that other functions know a control operation is in
 *                 progress.  Typically only used with complex controllers
 *                 which may not be atomic.
 */
#define DCL_CONTROLLER_BEGIN(p) ((p)->css->sts |= STS_CONTROLLER_RUNNING)
#define DCL_CONTROLLER_END(p) ((p)->css->sts &= ~STS_CONTROLLER_RUNNING)

/*
 * @rief          Macro to determine whether a controller is being executed
 *                based on the DCL_CONTROLLER_RUNNING bit in the status word.
 */
#define DCL_CONTROLLER_IN_PROGRESS(p) (0UL != ((p)->css->sts & STS_CONTROLLER_RUNNING))

/*
 * @brief          Macros to set the flag in the status word to denote
 *                 that parameter adjustment is in progress, and to
 *                 clear the flag when the target is reached.
 */
#define DCL_ADJUSTMENT_RUNNING(p) ((p)->css->sts |= STS_ADJUSTMENT_RUNNING)
#define DCL_ADJUSTMENT_COMPLETE(p) ((p)->css->sts &= ~STS_ADJUSTMENT_RUNNING)

/*
 * @brief          Macro to determine whether parameter adjustment is underway
 *                 based on the DCL_ADJUSTMENT_RUNNING bit in the status word.
 */
#define DCL_ADJUSTMENT_IN_PROGRESS(p) (0UL != ((p)->css->sts & STS_ADJUSTMENT_RUNNING))

//--- Error handling ---------------------------------------------------------
/*
 * @brief          Build the library with error handling enabled
 */
#define DCL_ERROR_HANDLING_ENABLED

/*
 * @brief          Defines the library enumerated error codes
 *                 These will be applied as bit masks in the error handler
 */
enum dcl_error_codes {
	ERR_NONE = 0UL,                 // No error
	ERR_PARAM_RANGE = (1UL << 0),   // Parameter range exceeded
	ERR_PARAM_INVALID = (1UL << 1), // Parameter not valid
	ERR_PARAM_WARN = (1UL << 2),    // Parameter warning
	ERR_INPUT_RANGE = (1UL << 3),   // Input range exceeded
	ERR_OVERFLOW = (1UL << 4),      // Numerical overflow
	ERR_UNDERFLOW = (1UL << 5),     // Numerical underflow
	ERR_VERSION = (1UL << 6),       // Incorrect DCL version
	ERR_DEVICE = (1UL << 7),        // Device not supported
	ERR_CONTROLLER = (1UL << 8),    // Controller operation not completed
	ERR_TIMING = (1UL << 9),        // Timing error
	ERR_COMPUTATION = (1UL << 10)   // Computation error
};

/*
 * @brief          Macro to clear stored error code in CSS
 */
#define DCL_CLEAR_ERROR_CODE(p) (p->css->err = ERR_NONE)

/*
 * @rief          Macro to store code location of error in CSS
 */
#define DCL_GET_ERROR_LOC(n) (n->loc = (ERR_NONE == n->err) ? NULL_ADDR : __LINE__)

/*
 * @brief          Define error handling routine
 */
#define DCL_RUN_ERROR_HANDLER(n) DCL_runErrorHandler(n)

//--- ZPK3 structure ---------------------------------------------------------

/*
 * @brief          Defines the DCL_ZPK3 controller structure.
 *
 * @etails        Allows controllers to be defined in terms of complex pole
 *                 and zero frequencies.  The common structure consists of
 *                 three complex zeros, three complex poles, and a real gain.
 *                 All frequencies must be specified in radians/sec.
 */
typedef struct dcl_zpk3 {
	float complex z1;float complex z2;float complex z3;float complex p1;float complex p2;float complex p3;
	float32_t K;
} DCL_ZPK3;

/*
 * @brief          Defines default values to initialize the DCL_ZPK3 structure
 */
#define ZPK3_DEFAULTS                                          \
    do {                                                       \
        0.0f + 0.0f * I, 0.0f + 0.0f * I, 0.0f + 0.0f * I,     \
            0.0f + 0.0f * I, 0.0f + 0.0f * I, 0.0f + 0.0f * I, \
            1.0f                                               \
    } while (0)

//*********** DCL_refgen.h - Reference generator module header file************//
/*
 * @brief          Defines the REFGEN operating modes
 */
enum dcl_rgen_modes {
	REFGEN_OFF = 0,
	REFGEN_STATIC,
	REFGEN_SINE,
	REFGEN_SQUARE,
	REFGEN_SAW,
	REFGEN_TRIANGLE,
	REFGEN_PULSE,
	REFGEN_SINE2,
	REFGEN_SINE3
};

/*
 * @brief          Defines the DCL_REFGEN structure
 */
typedef volatile struct dcl_refgen {
	float32_t rtgt;  // Target ramp value
	float32_t rinc;  // Ramp increment
	float32_t amtgt; // Target amplitude value
	float32_t aminc; // Amplitude increment
	float32_t fmtgt; // Frequency ramp value
	float32_t fminc; // Frequency increment
	float32_t thinc; // Angular increment
	float32_t duty;  // Pulse duty cycle
	float32_t umax;  // Maximum allowable output
	float32_t umin;  // Minimum allowable output
	float32_t yr;    // Ramp generator output
	float32_t ampl;  // Dynamic amplitude
	float32_t freq;  // Dynamic frequency
	float32_t theta; // Normalized angle - phase A
	float32_t thetb; // Normalized angle - phase B
	float32_t thetc; // Normalized angle - phase C
	float32_t ya;    // Phase A output
	float32_t yb;    // Phase B output
	float32_t yc;    // Phase C output
	int16_t mode;    // Operating mode
	int16_t spare;   // Spare for alignment
	DCL_CSS *css;    // Pointer to the common support structure
} DCL_REFGEN;

/*
 * @brief          Defines default values to initialize the DCL_REFGEN structure
 */
#define DCL_REFGEN_DEFAULTS                \
    {                                   \
        0.0f, 0.0f,                        \
            0.0f, 0.0f,                    \
            0.0f, 0.0f, 0.0f,              \
            0.0f, 1.0f, 1.0f, 1.0f, -1.0f, \
            0.0f, 0.0f, 0.0f, 0.0f,        \
            0.0f, 0.0f, 0.0f,              \
            REFGEN_OFF, 0, NULL_ADDR       \
    }

//*********** DCL_refgen.h - Reference generator module header file************//

/*
 * @brief          Resets DCL_REFGEN dynamic data
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @return         None
 */
__STATIC_INLINE void DCL_resetRefgen(DCL_REFGEN *p) {
	p->ampl = 0.0f;
	p->freq = 0.0f;
	p->rinc = 0.0f;
	p->theta = 0.0f;
	p->thetb = 0.0f;
	p->thetc = 0.0f;
	p->thinc = 0.0f;
	p->yr = 0.0f;
	p->ya = 0.0f;
	p->yb = 0.0f;
	p->yc = 0.0f;
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
//--- Error handling ---------------------------------------------------------
/*
 * @brief          Prototype for external basic error handler [DCL_error.c]
 * @param[in] p    Pointer to DCL_CSS structure
 * @return         None
 */
// extern void DCL_runErrorHandler(DCL_CSS *p);
__STATIC_INLINE void DCL_runErrorHandler(DCL_CSS *p) {
	if (ERR_NONE != p->err) {
		//        DCL_BREAK_POINT;
		while (1)
			;
	}
}

//--- Polynomial stability functions -----------------------------------------
/*
 * @brief          Determines stability of a first order real polynomial
 *                 P(z) = z + a1
 * @param[in] a1   Coefficient a1
 * @return         'true' if the root has magnitude less than 1, 'false' otherwise
 */
__STATIC_INLINE bool DCL_isStablePn1(float32_t a1) {
	return (((a1 * a1) < 1.0f) ? true : false);
}

/*
 * @brief          Determines stability of a second order polynomial with real coefficients
 *                 P(z) = a0 z^2 + a1 z + a2
 * @param[in] a1   Coefficient a1
 * @param[in] a2   Coefficient a2
 * @return         'true' if both roots have magnitude less than 1, 'false' otherwise
 */
__STATIC_INLINE bool DCL_isStablePn2(float32_t a0, float32_t a1, float32_t a2) {
	float32_t b0, b1, c0;
#ifdef ZHANLU
	b0 = a0 - a2 * __builtin_riscv_divf32(a2, a0);
	b1 = a1 - a1 * __builtin_riscv_divf32(a2, a0);
	c0 = b0 - b1 * __builtin_riscv_divf32(b1, b0);
#else
    b0 = a0 - a2 * a2 / a0;
    b1 = a1 - a1 * a2 / a0;
    c0 = b0 - b1 * b1 / b0;
#endif
	if ((a0 > 0.0f) && (b0 > 0.0f) && (c0 > 0.0f)) {
		return (true);
	} else {
		return (false);
	}
}

/*
 * @brief          Determines stability of a third order polynomial with real coefficients
 *                 P(z) = a0 z^3 + a1 z^2 + a2 z + a3
 * @param[in] a1   Coefficient a1
 * @param[in] a2   Coefficient a2
 * @param[in] a3   Coefficient a3
 * @return         'true' if all roots have magnitude less than 1, 'false' otherwise
 */
__STATIC_INLINE bool DCL_isStablePn3(float32_t a0, float32_t a1, float32_t a2,
		float32_t a3) {
	float32_t b0, b1, b2, c0, c1, d0;
#ifdef ZHANLU
	float32_t tmp;
	tmp = __builtin_riscv_divf32(a3, a0);
	b0 = a0 - a3 * tmp;
	b1 = a1 - a2 * tmp;
	b2 = a2 - a1 * tmp;
	c0 = b0 - b2 * __builtin_riscv_divf32(b2, b0);
	c1 = b1 - b1 * __builtin_riscv_divf32(b2, b0);
	d0 = c0 - c1 * __builtin_riscv_divf32(c1, c0);
#else
    b0 = a0 - a3 * a3 / a0;
    b1 = a1 - a2 * a3 / a0;
    b2 = a2 - a1 * a3 / a0;
    c0 = b0 - b2 * b2 / b0;
    c1 = b1 - b1 * b2 / b0;
    d0 = c0 - c1 * c1 / c0;
#endif

	if ((a0 > 0.0f) && (b0 > 0.0f) && (c0 > 0.0f) && (d0 > 0.0f)) {
		return (true);
	} else {
		return (false);
	}
}

//--- ZPK3 structure ---------------------------------------------------------
/*
 * @brief          Determines stability of a ZPK3 representation by checking pole magnitude
 * @param[in] q    Pointer to DCL_ZPK3 structure
 * @return         'true' if all poles have magnitude less than 1, 'false' otherwise
 */
__STATIC_INLINE bool DCL_isStableZpk3(DCL_ZPK3 *q) {
	return (((cabsf(q->p1) < 1.0f) && (cabsf(q->p2) < 1.0f)
			&& (cabsf(q->p3) < 1.0f)) ? true : false);
}

//*********** DCL_refgen.h - Reference generator module header file************//
/*
 * @brief          Loads the REFGEN ramp parameters
 *
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @param[in] tgt  The new static reference target
 * @param[in] tr   The time interval to reach the new target
 * @return         Void
 */
__STATIC_INLINE void DCL_setRefgenRamp(DCL_REFGEN *p, float32_t tgt,
		float32_t tr) {
	// compute ramp increment
	tr = (tr < p->css->T) ? p->css->T : tr;
	p->rtgt = tgt;

#ifdef ZHANLU
	p->rinc = p->css->T * __builtin_riscv_divf32((tgt - p->yr), tr);
#else
    p->rinc = p->css->T * (tgt - p->yr) / tr;
#endif
	// clamp minimum ramp increment
	if (!(0.0f == p->rinc) && (fabsf(p->rinc) < DCL_REFGEN_MIN_INC)) {
		if (signbit(p->rinc)) {
			p->rinc = -DCL_REFGEN_MIN_INC;
		} else {
			p->rinc = DCL_REFGEN_MIN_INC;
		}
	}
}

/*
 * @brief          Loads the REFGEN dynamic amplitude
 *
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @param[in] ampl The new target amplitude
 * @param[in] tr   The time interval to reach the new target
 * @return         Void
 */
__STATIC_INLINE void DCL_setRefgenAmpl(DCL_REFGEN *p, float32_t ampl,
		float32_t tr) {
	// compute amplitude increment
	tr = (tr < p->css->T) ? p->css->T : tr;
	p->amtgt = ampl;
#ifdef ZHANLU
	p->aminc = p->css->T * __builtin_riscv_divf32((ampl - p->ampl), tr);
#else
    p->aminc = p->css->T * (ampl - p->ampl) / tr;
#endif
	// clamp minimum amplitude increment
	if ((p->aminc > 0.0f) && (fabsf(p->aminc) < DCL_REFGEN_MIN_INC)) {
		if (signbit(p->aminc)) {
			p->aminc = -DCL_REFGEN_MIN_INC;
		} else {
			p->aminc = DCL_REFGEN_MIN_INC;
		}
	}
}

/*
 * @brief          Loads the REFGEN frequency
 *
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @param[in] freq The new frequency in Hz
 * @param[in] tr   The time interval to reach the new target
 * @return         Void
 */
__STATIC_INLINE void DCL_setRefgenFreq(DCL_REFGEN *p, float32_t freq,
		float32_t tr) {
	// compute frequency increment
	tr = (tr < p->css->T) ? p->css->T : tr;
	p->fmtgt = freq;
#ifdef ZHANLU
	p->fminc = p->css->T * __builtin_riscv_divf32((freq - p->freq), tr);
#else
    p->fminc = p->css->T * (freq - p->freq) / tr;
#endif
	// clamp minimum frequency increment
	if ((p->fminc > 0.0f) && (fabsf(p->fminc) < DCL_REFGEN_MIN_INC)) {
		if (signbit(p->fminc)) {
			p->fminc = -DCL_REFGEN_MIN_INC;
		} else {
			p->fminc = DCL_REFGEN_MIN_INC;
		}
	}
}

/*
 * @brief          Loads the REFGEN pulse duty cycle
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @param[in] duty The new per-unit duty cycle
 * @return         None
 */
__STATIC_INLINE void DCL_setRefgenDuty(DCL_REFGEN *p, float32_t duty) {
	p->duty = duty;
}

/*
 * @brief          Loads the REFGEN output clam limits
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @param[in] max  The upper limit
 * @param[in] min  The lower limit
 * @return         None
 */
__STATIC_INLINE void DCL_setRefgenClamp(DCL_REFGEN *p, float32_t max,
		float32_t min) {
	p->umax = max;
	p->umin = min;
}

/*
 * @brief          Sets the REFGEN operating mode
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @param[in] mode The new operating mode
 * @return         None
 */
__STATIC_INLINE void DCL_setRefgenMode(DCL_REFGEN *p, int16_t mode) {
	p->mode = mode;
}

/*
 * @brief          Runs the REFGEN module
 * @param[in] p    Pointer to the DCL_REFGEN structure
 * @return         None
 */
__STATIC_INLINE void DCL_runRefgen(DCL_REFGEN *p) {
	// static offset generator
	if (!F32_IS_ZERO(p->rinc)) {
		if (fabsf(p->rinc) > fabsf(p->rtgt - p->yr)) {
			p->yr = p->rtgt;
			p->rinc = 0.0f;
			DCL_ADJUSTMENT_COMPLETE(p);
		} else {
			p->yr += p->rinc;
			DCL_ADJUSTMENT_RUNNING(p);
		}
	}
	// amplitude modulator
	if (!F32_IS_ZERO(p->aminc)) {
		if (fabsf(p->aminc) > fabsf(p->amtgt - p->ampl)) {
			p->ampl = p->amtgt;
			p->aminc = 0.0f;
		} else {
			p->ampl += p->aminc;
		}
	}
	// frequency modulator
	if (!F32_IS_ZERO(p->fminc)) {
		if (fabsf(p->fminc) > fabsf(p->fmtgt - p->freq)) {
			p->freq = p->fmtgt;
			p->fminc = 0.0f;
		} else {
			p->freq += p->fminc;
		}
	}
	// angle increment
	if (p->freq > 0.0f) {
		p->thinc = p->css->T * p->freq;
		if (p->thinc < DCL_REFGEN_MIN_INC) {
			p->thinc = DCL_REFGEN_MIN_INC;
		}
	} else {
		p->thinc = 0.0f;
	}

	p->theta += p->thinc;
	p->theta -= (p->theta >= 1.0f) ? 1.0f : 0.0f;
	// dynamic signal generator
	switch (p->mode) //{
	{
	case REFGEN_STATIC:
		p->ya = 0.0f;
		p->yb = 0.0f;
		p->yc = 0.0f;
		break;

	case REFGEN_SINE:
#ifdef ZHANLU
		p->ya = __builtin_riscv_sinpuf32(p->theta);
#else
        p->ya = sinf(CONST_2PI_32 * p->theta);
#endif
		p->yb = 0.0f;
		p->yc = 0.0f;
		break;
	case REFGEN_SQUARE:
		p->ya = (p->theta > 0.5f) ? 1.0f : 0.0f;
		p->yb = 0.0f;
		p->yc = 0.0f;
		break;

	case REFGEN_SAW:
		p->ya = p->theta;
		p->yb = 0.0f;
		p->yc = 0.0f;
		break;

	case REFGEN_TRIANGLE:
#ifdef ZHANLU
		if (p->theta < 0.5f) {
			p->ya = __builtin_riscv_mpy2f32(p->theta);

		} else {
			p->ya = __builtin_riscv_nadd1f32(__builtin_riscv_mpy2f32(p->theta - 0.5f));
		}
#else
		if (p->theta < 0.5f) {
			p->ya = 2.0f * p->theta;
		} else {
			p->ya = 1.0f - 2.0f * (p->theta - 0.5f);
		}

#endif
		p->yb = 0.0f;
		p->yc = 0.0f;
		break;

	case REFGEN_PULSE:
		p->ya = (p->theta > p->duty) ? 0.0f : 1.0f;
		p->yb = 0.0f;
		p->yc = 0.0f;
		break;

	case REFGEN_SINE2:
#ifdef ZHANLU
		p->ya = __builtin_riscv_sinpuf32(p->theta);
		p->yb = __builtin_riscv_cospuf32(p->theta);
#else
		p->ya = sinf(CONST_2PI_32 * p->theta);
		p->yb = cosf(CONST_2PI_32 * p->theta);
#endif
		p->yc = 0.0f;
		break;

	case REFGEN_SINE3:
		p->thetb = p->theta + 0.3333333333333f;
		p->thetc = p->theta + 0.6666666666667f;
		p->thetb -= (p->thetb >= 1.0f) ? 1.0f : 0.0f;
		p->thetc -= (p->thetc >= 1.0f) ? 1.0f : 0.0f;
#ifdef ZHANLU
		p->ya = __builtin_riscv_sinpuf32(p->theta);
		p->yb = __builtin_riscv_sinpuf32(p->thetb);
		p->yc = __builtin_riscv_sinpuf32(p->thetc);
#else
		p->ya = sinf(CONST_2PI_32 * p->theta);
		p->yb = sinf(CONST_2PI_32 * p->thetb);
		p->yc = sinf(CONST_2PI_32 * p->thetc);
#endif

		break;

	case REFGEN_OFF:
	default:
		p->yr = 0.0f;
		p->ya = 0.0f;
		p->yb = 0.0f;
		p->yc = 0.0f;
	}
	// output sum & saturation
#ifdef ZHANLU
	p->ya = satf32((p->ampl * p->ya + p->yr), p->umax, p->umin);
	p->yb = satf32((p->ampl * p->yb + p->yr), p->umax, p->umin);
	p->yc = satf32((p->ampl * p->yc + p->yr), p->umax, p->umin);
#else
	p->ya = ((p->ampl * p->ya + p->yr) > p->umax) ?
			p->umax : (p->ampl * p->ya + p->yr);
	p->ya = (p->ya < p->umin) ? p->umin : p->ya; //__fsat(p->ampl * p->ya + p->yr, p->umax, p->umin);
	p->yb = ((p->ampl * p->yb + p->yr) > p->umax) ?
			p->umax : (p->ampl * p->yb + p->yr);
	p->yb = (p->yb < p->umin) ? p->umin : p->yb; // p->yb = __fsat(p->ampl * p->yb + p->yr, p->umax, p->umin);
	p->yc = ((p->ampl * p->yc + p->yr) > p->umax) ?
			p->umax : (p->ampl * p->yc + p->yr);
	p->yc = (p->yc < p->umin) ? p->umin : p->yc; // p->yc = __fsat(p->ampl * p->yc + p->yr, p->umax, p->umin);
#endif

}

/*
 * @brief          Returns the phase reference output
 * @param[in] p    Pointer to the active DCL_REFGEN structure
 * @return         The phase A reference output
 */
__STATIC_INLINE float32_t
DCL_getRefgenPhaseA(DCL_REFGEN *p) {
	return (p->ya);
}

/*
 * @brief          Returns the phase reference output
 * @param[in] p    Pointer to the active DCL_REFGEN structure
 * @return         The phase B reference output
 */
__STATIC_INLINE float32_t
DCL_getRefgenPhaseB(DCL_REFGEN *p) {
	return (p->yb);
}

/*
 * @brief          Returns the phase reference output
 * @param[in] p    Pointer to the active DCL_REFGEN structure
 * @return         The phase C reference output
 */
__STATIC_INLINE float32_t
DCL_getRefgenPhaseC(DCL_REFGEN *p) {
	return (p->yc);
}

#ifdef __cplusplus
}
#endif

#endif // end of DEVICE_DCL_H definition
