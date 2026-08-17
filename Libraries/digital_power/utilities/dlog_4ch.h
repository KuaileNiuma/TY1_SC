/** 
  *************************************************************************************
  * @file dlog_4ch.h 
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

#ifndef DLOG_4CH_H
#define DLOG_4CH_H

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
 * \brief Defines the Four Channel Data Logger (DLOG_4CH) structure
 *
 * \details The dlog can be used to perform data logging to emulate an
 *          oscilloscope in software to graphically observe system
 *          variables
 */
typedef volatile struct {
    float32_t *inputPtr1;
    float32_t *inputPtr2;
    float32_t *inputPtr3;
    float32_t *inputPtr4;
    float32_t *outputPtr1;
    float32_t *outputPtr2;
    float32_t *outputPtr3;
    float32_t *outputPtr4;
    float32_t prevValue;
    float32_t trigValue;
    int16_t status;
    int16_t preScalar;
    int16_t skipCount;
    int16_t size;
    int16_t count;
} DLOG_4CH;

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
 * \brief resets internal storage data
 * \param *v The DLOG_4CH structure pointer
 * \return None
 */
static inline void
DLOG_4CH_reset(DLOG_4CH *v) {
    v->prevValue = 0;
    v->trigValue = 0;
    v->status = 0;
    v->skipCount = 0;
    v->count = 0;
}

/**
 * \brief Configures DLOG_4CH module
 * \param *v The pointer to DLOG_4CH structure pointer
 * \param input_ptr1 Pointer to data being buffered in the first buffer
 * \param input_ptr2 Pointer to data being buffered in the second buffer
 * \param input_ptr3 Pointer to data being buffered in the third buffer
 * \param input_ptr4 Pointer to data being buffered in the fourth buffer
 * \param output_ptr1 Pointer to where first array of buffered data is stored
 * \param output_ptr2 Pointer to where second array of buffered data is stored
 * \param output_ptr3 Pointer to where third array of buffered data is stored
 * \param output_ptr4 Pointer to where fourth array of buffered data is stored
 * \param size Data buffer size
 * \param trigValue Trigger point for the datalogger
 * \param preScalar Variable to skip data logging points
 * \return None
 */
static inline void
DLOG_4CH_config(DLOG_4CH *v,
                float32_t *inputPtr1,
                float32_t *inputPtr2,
                float32_t *inputPtr3,
                float32_t *inputPtr4,
                float32_t *outputPtr1,
                float32_t *outputPtr2,
                float32_t *outputPtr3,
                float32_t *outputPtr4,
                float32_t size,
                float32_t trigValue,
                float32_t preScalar) {
    v->inputPtr1 = inputPtr1;
    v->inputPtr2 = inputPtr2;
    v->inputPtr3 = inputPtr3;
    v->inputPtr4 = inputPtr4;
    v->outputPtr1 = outputPtr1;
    v->outputPtr2 = outputPtr2;
    v->outputPtr3 = outputPtr3;
    v->outputPtr4 = outputPtr4;
    v->prevValue = (float32_t)(0);
    v->trigValue = (float32_t)(trigValue);
    v->status = 1;
    v->preScalar = preScalar;
    v->skipCount = 0;
    v->size = size;
    v->count = 0;
}

/**
 * \brief Run the DLOG_4CH module
 * \param *v The DLOG_4CH structure pointer
 * \return None
 */
static inline void
DLOG_4CH_run(DLOG_4CH *v) {
    switch (v->status) {
        //
        // wait for trigger
        //
        case 1:
            if (*v->inputPtr1 > v->trigValue && v->prevValue < v->trigValue) {
                //
                // rising edge detected start logging data
                //
                v->status = 2;
            }
            break;
        case 2:
            v->skipCount++;
            if (v->skipCount == v->preScalar) {
                v->skipCount = 0;
                v->outputPtr1[v->count] = *v->inputPtr1;
                v->outputPtr2[v->count] = *v->inputPtr2;
                v->outputPtr3[v->count] = *v->inputPtr3;
                v->outputPtr4[v->count] = *v->inputPtr4;
                v->count++;
                if (v->count == v->size) {
                    v->count = 0;
                    v->status = 1;
                }
            }
            break;
    }
    v->prevValue = *v->inputPtr1;
}

#ifdef __cplusplus
}
#endif

#endif /*DLOG_4CH_H*/
