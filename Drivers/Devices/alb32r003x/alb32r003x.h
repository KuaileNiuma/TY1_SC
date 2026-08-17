/** 
  ************************************************************************************* 
  * @file alb32r003x.h
  * @brief This file contains the definition of alb32r003x driver. 
  * @version 1.0.0 
  ************************************************************************************* 
  * @copyright Copyright (c) 2025 Albatross Semiconductor(Hangzhou) Co.,Ltd. 
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

#ifndef __ALB32R003X_H__
#define __ALB32R003X_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// NOTE: this cpufeature.h header file
#include "alb32r003x_feature.h"
#include "alb32r003x_int.h"
#include "alb32r003x_mmap.h"
#include "alb32r003x_pinmap.h"

/**
 * @brief In the following line adjust the value of External High Speed oscillator (HSE)
 used in your application

 Tip: To avoid modifying this file each time you need to use different HSE, you
 can define the HSE value in your toolchain compiler preprocessor.
 */

#define HSI1_CLOCK        14000000
#define HSI2_CLOCK        12000000
#define HSE_CLOCK         20000000
#define DEVICE_CLOCK_SRC  HSE_CLOCK


/** \brief SoC Download mode definition */
typedef enum {
	DOWNLOAD_MODE_FLASHXIP = 0, /*!< Flashxip download mode */
	DOWNLOAD_MODE_FLASH = 1, /*!< Flash download mode */
	DOWNLOAD_MODE_ILM = 2, /*!< ilm download mode */
	DOWNLOAD_MODE_SRAM = 3, /*!< sram download mode */
	DOWNLOAD_MODE_MRAM = 4, /*!< mram download mode */
	DOWNLOAD_MODE_MAX,
} DownloadMode_Type;


/** @} *//* End of group alb32r003x */


#ifdef __cplusplus
}
#endif

#endif  /* __ALB32R003X_H__ */

