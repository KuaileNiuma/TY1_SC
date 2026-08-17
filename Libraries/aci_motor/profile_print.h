/** 
  *************************************************************************************
  * @file profile_print.h 
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

#ifndef _PROFILE_PRINT_H
#define _PROFILE_PRINT_H

//
// Include files
//
#include    "string.h"
#include    "stdio.h"
#include    "stdint.h"

#include "../aci_motor/profile.h"


#define PRINT_HEADER "\r\n                                    \t AVG \t MAX \t MIN"
#define PRINT_ST_0 "\r\n INT Response (trigger to ISR entry) :\t %d  \t %d  \t %d"
#define PRINT_ST_1 "\r\n Read 2 ADC, convert float           :\t %d  \t %d  \t %d"
#define PRINT_ST_2 "\r\n Clarke Transform                    :\t %d  \t %d  \t %d"
#define PRINT_ST_3 "\r\n 3 PID Controller Transforms         :\t %d  \t %d  \t %d"
#define PRINT_ST_4 "\r\n Inverse Park Transform              :\t %d  \t %d  \t %d"
#define PRINT_ST_5 "\r\n ACI Motor Modeling                  :\t %d  \t %d  \t %d"
#define PRINT_ST_6 "\r\n Flux Estimator                      :\t %d  \t %d  \t %d"
#define PRINT_ST_7 "\r\n Speed Estimator                     :\t %d  \t %d  \t %d"
#define PRINT_ST_8 "\r\n Park Transform                      :\t %d  \t %d  \t %d"
#define PRINT_ST_9 "\r\n SVGen Transform                     :\t %d  \t %d  \t %d"
#define PRINT_ST_10 "\r\n Write 3 PWM                         :\t %d  \t %d  \t %d"
#define PRINT_ST_TOTAL "\r\n Total                               :\t %ld  \t %ld  \t %ld"
#define PRINT_ST_LINE  "\r\n-------------------------------------------------------------------------"

#define IOBmrk_print() printf(PRINT_ST_0, (int) ((((float) IOBmrk_Sum) / ((float)IOBmrk_Count))), (int) IOBmrk_Max, (int) IOBmrk_Min);
#define Bmrk_print(n) printf(PRINT_ST_##n, (int) (((float) Bmrk_Sum[n-1]) / ((float)Bmrk_Count[n-1])), (int) Bmrk_Max[n-1], (int) Bmrk_Min[n-1]);

#define Bmrk_print_total()  printf(PRINT_ST_LINE); \
                                         printf(PRINT_ST_TOTAL, Bmrk_TotalAvg, Bmrk_TotalMax, Bmrk_TotalMin); \
                                         printf(PRINT_ST_LINE);

#define Bmrk_add_IO()   Bmrk_TotalAvg += (int)((float)IOBmrk_Sum / (float)IOBmrk_Count); \
                        Bmrk_TotalMax += IOBmrk_Max; \
                        Bmrk_TotalMin += IOBmrk_Min;

#define Bmrk_add(n)  Bmrk_TotalAvg += (int)((float)Bmrk_Sum[n-1] / (float)Bmrk_Count[n-1]); \
                     Bmrk_TotalMax += Bmrk_Max[n-1]; \
                     Bmrk_TotalMin += Bmrk_Min[n-1];

#define Bmrk_printHeader()    printf(PRINT_ST_LINE); \
                              printf(PRINT_HEADER);

#endif  // _PROFILE_PRINT_H
