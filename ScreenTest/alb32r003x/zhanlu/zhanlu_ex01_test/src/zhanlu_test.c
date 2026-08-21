/**
 *************************************************************************************
 * @file zhanlu_test.c
 * @brief This file contains the source file for example zhanlu_test.
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
#include <stdio.h>
#include "device.h"
#include <math.h>
#include "zhanlu_test.h"
#include <string.h>
#include "my_float.h"
#include <stdlib.h>
#include "alb32r003x_screenTest.h"

uint16_t pass = 0, fail = 0;

#define CRC32_POLYNOMIAL 0x04C11DB7
#define TWO_PI (6.28318530717958647692f)
uint32_t crc32_mpeg2(const uint8_t *ptr, int len)
{
    unsigned int i;
    unsigned int crc = 0xFFFFFFFF;

    while (len--)
    {
        crc ^= (unsigned int) (*ptr++) << 24;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 0x80000000)
                crc = (crc << 1) ^ CRC32_POLYNOMIAL;
            else
                crc <<= 1;
        }
    }
    return crc;
}

int test_crc(void)
{
    uint32_t val = 0;
    uint32_t ncsrval;
    uint32_t x = 0x78;
    uint32_t y = 0;
    __alb_fcsr_w(0);
    __alb_icsr_w(0);
    __alb_crccr_w(0);
    __alb_crcrr_w(0xFFFFFFFF); //init
    __alb_crcsr_w(31 | (31 << 16)); //vcrc32 bit多项式， vcrc 32-bit
    __alb_crcpr_w(0x04C11DB7); //多项式用作计算
    __alb_crc32p1_byte(0);
    __alb_crc32p1_byte(0);
    __alb_crc32p1_byte(0);
    __alb_crc32p1_byte(x); //input data to the CRC hardware
    y = __alb_crcrr_r();
    x = 0x78000000;
    val = crc32_mpeg2((const uint8_t*) &x, 4);
    __alb_crcrr_w(0xFFFFFFFF);
    __alb_vcrc(0x78); //高位先计算，
    y = __alb_crcrr_r();
    if (y != val)
    {
        printf("result:%f,expect:%f\n", y, val);
        return -1;
    }

    return 0;
}
extern float sin_math[1024 + 1];
extern float cos_math[1024 + 1];
extern float atan_math[1024 + 1];


#define TEST_512(func, __xmin, __xmax, __inst, __sw)        \
int func(void)                                             \
{                                                          \
    float xmin = (__xmin);                                 \
    float xmax = (__xmax);                                 \
    float xStep = (xmax - xmin) / 512.0f;                  \
                                                           \
    int pass_cnt = 0;                                      \
    int fail_cnt = 0;                                      \
                                                           \
    for (int i = 0; i <= 512; i++)                          \
    {                                                      \
        float x = xmin + (float)i * xStep;                 \
                                                           \
        float y_inst = (__inst);                            \
        float y_sw   = (__sw);                              \
                                                           \
        /* bit-level compare (safe) */                      \
        int32_t y_inst_i, y_sw_i;                           \
        memcpy(&y_inst_i, &y_inst, sizeof(int32_t));       \
        memcpy(&y_sw_i,   &y_sw,   sizeof(int32_t));       \
                                                           \
        float diff = fabsf(y_inst - y_sw);                 \
                                                           \
        if ((diff < FLT_TOLERANCE) ||                       \
            (abs(y_inst_i - y_sw_i) <= 1))                 \
        {                                                  \
            pass_cnt++;                                    \
        }                                                  \
        else                                               \
        {                                                  \
            fail_cnt++;                                    \
            printf("[FAIL] i=%d x=%f inst=%f sw=%f diff=%e\n", \
                   i, x, y_inst, y_sw, diff);              \
        }                                                  \
    }                                                      \
                                                           \
    if (fail_cnt != 0)                                     \
    {                                                      \
        printf("[TEST %s] FAIL: %d failed\n",        \
               #func, fail_cnt);                           \
        return -1;                                         \
    }                                                      \
                                                           \
    return 0;                                              \
}

TEST_512(test_sqrtf32, 0.0f, FLT_MAX, __alb_sqrtf32(x), sqrtf(x));
TEST_512(test_sinpuf32, -2.0f, 2.0f, __alb_sinpuf32(x), sin_math[i++]);
TEST_512(test_cospuf32, -2.0f, 2.0f, __alb_cospuf32(x), cos_math[i++]);
TEST_512(test_atanpuf32, -1.0f, 1.0f, __alb_atanpuf32(x), atan_math[i++]);
TEST_512(test_expf32, -126.0f, 127.0f, __alb_expf32(x), exp2f(x));
TEST_512(test_log2f32, FLT_EPSILON, 100000.0f, __alb_log2f32(x), log2f(x));

#define TEST_1023(func,__xmin,__xmax,__inst,__sw)	\
		int func(void)\
		{\
		    float xmin = __xmin;\
		    float xmax =__xmax;\
		    float x= xmin;\
		    float xstep = (xmax-xmin)/1023;\
		    float y;\
		    float y_math;\
		    int e_1023 = 0;\
			int32_t yint;\
			int32_t yint_math;\
			int i =0;\
		    for(;x<=xmax;x+=xstep)\
		    {\
		    	y=__inst;\
		    	y_math = __sw;\
		    	yint =*(int32_t*)(&y);\
		    	yint_math =*(int32_t*)(&y_math);\
		    	if (fabsf(y-y_math)<FLT_TOLERANCE || fabs(yint-yint_math)<=1)\
				{\
		    		pass++;\
				}\
				else{\
					e_1023 = 1;\
					}\
		    }\
			if(e_1023){\
				printf("result:%f,expect:%f\n",y,y_math);\
				return -1;\
			}\
			return 0;\
		}\

TEST_1023(test_aexpf32, -127.0f, 127.0f, __alb_aexpf32(x), exp2f(fabsf(x)));
TEST_1023(test_nexpf32, -127.0f, 126.0f, __alb_nexpf32(x), exp2f(-x));
TEST_1023(test_iexpf32, -126.0f, 126.0f, __alb_iexpf32(x), exp2f(-fabsf(x)));
TEST_1023(test_mpy2pif32, -FLT_MAX/(M_TWOPI+0.0000001f), FLT_MAX/(M_TWOPI+0.0000001f), __alb_mpy2pif32(x), x*M_TWOPI);
TEST_1023(test_div2pif32, -FLT_MAX, FLT_MAX, __alb_div2pif32(x), x/M_TWOPI);
TEST_1023(test_nmpy2pif32, -FLT_MAX/(M_TWOPI+0.0000001f), FLT_MAX/(M_TWOPI+0.0000001f), __alb_nmpy2pif32(x),
        -x*M_TWOPI);

int test_divf32(void)
{
    float x0min = -1000.0f;
    float x0max = 1000.0f;
    float x0 = x0min;
    float x1min = -10000.0f;
    float x1max = 10000.0f;
    float x1 = x1min;
    float x0step = (x0max - x0min) / 512;
    float x1step = (x1max - x1min) / 13000;
    float y;
    float y_math;
    int32_t yint;
    int32_t yint_math;
    int e_13000 = 0;
    for (x0 = x0min; x0 <= x0max; x0 += x0step)
    {
        for (x1 = x1min; x1 <= x1max; x1 += x1step)
        {
            if (*(int32_t*) (&x1) == 0x00000000 || *(int32_t*) (&x1) == 0x80000000)
            {
                continue;
            }
            y = __alb_divf32(x0, x1); //hardware instruction
            y_math = x0 / x1;         //software lib func
            yint = *(int32_t*) (&y);
            yint_math = *(int32_t*) (&y_math);					//compare with HEX
            if (fabsf(y - y_math) < FLT_TOLERANCE || fabs(yint - yint_math) <= 1)
            {
                pass++;
            }
            else
            {
                e_13000 = 1;
            }
        }
    }
    if (e_13000)
    {
        printf("result:%f,expect:%f\n", y, y_math);
        return -1;
    }
    return 0;
}

int test_sumsqf32(void)
{
    float x0min = -1000.0f;
    float x0max = 1000.0f;
    float x0 = x0min;
    float x1min = -1000.0f;
    float x1max = 1000.0f;
    float x1 = x1min;
    float x0step = (x0max - x0min) / 1017;
    float x1step = (x1max - x1min) / 1300;
    float y;
    float y_math;
    int32_t yint;
    int32_t yint_math;
    int e_1300 = 0;
    for (; x0 <= x0max; x0 += x0step)
    {
        for (x1 = x1min; x1 <= x1max; x1 += x1step)
        {
            y = __alb_sumsqf32(x0, x1);
            y_math = x0 * x0 + x1 * x1;
            yint = *(int32_t*) (&y);
            yint_math = *(int32_t*) (&y_math);
            if (fabsf(y - y_math) < FLT_TOLERANCE || fabs(yint - yint_math) <= 1)
            {
                pass++;
            }
            else
            {
                e_1300 = 1;
            }
        }
    }
    if (e_1300)
    {
        printf("result:%f,expect:%f\n", y, y_math);
        return -1;
    }
    return 0;
}

float my_atan2divf32(float x, float y)
{
    float ratio = 0.0f;
    if (fabsf(y) <= fabsf(x) && (x >= 0))
    {
        if ((y == 0) && (x == 0))
        {
            ratio = 0.0f;
        }
        else
        {
            ratio = y / x;
        }
    }
    else if (fabsf(y) > fabsf(x) && (y >= 0))
    {
        ratio = -x / y;
    }
    else if (fabsf(y) <= fabsf(x) && (x < 0) && (y >= 0))
    {
        ratio = y / x;

    }
    else if (fabsf(y) <= fabsf(x) && (x < 0) && (y < 0))
    {
        ratio = y / x;
    }
    else if (fabsf(y) > fabsf(x) && (y < 0))
    {
        ratio = -x / y;
    }
    return ratio;
}

float my_atan2quadf32(float x, float y)
{
    float quadrant = 0.0f;
    if (fabsf(y) <= fabsf(x) && (x >= 0))
    {
        quadrant = 0.0f;
    }
    else if (fabsf(y) > fabsf(x) && (y >= 0))
    {
        quadrant = 0.25f;
    }
    else if (fabsf(y) <= fabsf(x) && (x < 0) && (y >= 0))
    {
        quadrant = 0.5f;
    }
    else if (fabsf(y) <= fabsf(x) && (x < 0) && (y < 0))
    {
        quadrant = -0.5f;
    }
    else if (fabsf(y) > fabsf(x) && (y < 0))
    {
        quadrant = -0.25f;
    }
    return quadrant;
}

int test_quadf32(void)
{
    float x0min = -1000.0f;
    float x0max = 1000.0f;
    float x0 = x0min;
    float x1min = -1000.0f;
    float x1max = 1000.0f;
    float x1 = x1min;
    float x0step = (x0max - x0min) / 512;
    float x1step = (x1max - x1min) / 1300;
    float ratio;
    float ratio_my;
    float quadrant;
    float quadrant_my;
    int32_t quadrant_int;
    int32_t quadrant_my_int;
    int e_quad = 0;
    for (x0 = x0min; x0 <= x0max; x0 += x0step)
    {
        for (x1 = x1min; x1 <= x1max; x1 += x1step)
        {
            ratio = __alb_atan2divf32(x0, x1);
            ratio_my = my_atan2divf32(x1, x0);
            quadrant = __alb_atan2quadf32(x0, x1);
            quadrant_my = my_atan2quadf32(x1, x0);
            quadrant_int = *(int32_t*) (&quadrant);
            quadrant_my_int = *(int32_t*) (&quadrant_my);
//			if (fabsf(ratio-ratio_my)<FLT_TOLERANCE  && fabsf(quadrant-quadrant_my)<FLT_TOLERANCE)
            if ((fabsf(ratio - ratio_my) < FLT_TOLERANCE && quadrant_int == quadrant_my_int))
            {
                pass++;
            }
            else
            {
                e_quad = 1;
            }
        }
    }
    if (e_quad)
    {
        printf("atdiv_result:%f,atdiv_expect:%f\n", ratio, ratio_my);
        printf("atquad_result:%f,atquad_expect:%f\n", quadrant, quadrant_my);
        return -1;
    }
    return 0;
}

#define TEST_2047(func,__xmin,__xmax,__inst,__sw) \
		int func(void)\
		{\
		    float xmin = __xmin;\
		    float xmax = __xmax;\
		    float x= xmin;\
		    float xstep = xmax/2047;\
		    float y;\
		    float y_math;\
		    int e_2047 = 0;\
		    int32_t yint;\
		    int32_t yint_math;\
		    for(;x<=xmax;x+=xstep)\
		    {\
		    	y=__inst;\
		    	y_math = __sw;\
		    	yint =*(int32_t*)(&y);\
		    	yint_math =*(int32_t*)(&y_math);\
		    	if (fabsf(y-y_math)<FLT_TOLERANCE  || fabs(yint-yint_math)<=1)\
				{\
					pass++;\
				}\
				else{\
					e_2047 = 1;\
				}\
		    }\
			if(e_2047){\
				printf("result:%f,expect:%f\n",y,y_math);\
				return -1;\
			}\
			return 0;\
		}\

#ifdef ZHNALU
TEST_2047(test_ndiv2pif32,-FLT_MAX,FLT_MAX,ndiv2pif32(x),-x/M_TWOPI);
TEST_2047(test_mpy2f32,-FLT_MAX/2,FLT_MAX/2,mpy2f32(x),x*2);
TEST_2047(test_mpy2div3f32,-FLT_MAX,FLT_MAX,mpy2div3f32(x),x/3*2);
TEST_2047(test_div2f32,-FLT_MAX,FLT_MAX,div2f32(x),x/2);
TEST_2047(test_div3f32,-FLT_MAX,FLT_MAX,div3f32(x),x/3);
#else
TEST_2047(test_ndiv2pif32, -FLT_MAX, FLT_MAX, __alb_ndiv2pif32(x), -x/M_TWOPI);
TEST_2047(test_mpy2f32, -FLT_MAX/2, FLT_MAX/2, __alb_mpy2f32(x), x * 2);
TEST_2047(test_mpy2div3f32, -FLT_MAX, FLT_MAX, __alb_mpy2div3f32(x), x / 3 * 2);
TEST_2047(test_div2f32, -FLT_MAX, FLT_MAX, __alb_div2f32(x), x / 2);
TEST_2047(test_div3f32, -FLT_MAX, FLT_MAX, __alb_div3f32(x), x / 3);
#endif

#define TEST_4091(func,__xmin,__xmax,__inst,__sw) \
		int func(void)\
		{\
		    float xmin = __xmin;\
		    float xmax =__xmax;\
		    float x= xmin;\
		    float xstep = FLT_MAX/4091;\
		    float y;\
		    float y_math;\
		    int e_4091 = 0;\
		    int32_t yint;\
		    int32_t yint_math;\
		    for(;x<=xmax;x+=xstep)\
		    {\
		    	y=__inst;\
		    	y_math = __sw;\
		    	yint =*(int32_t*)(&y);\
		    	yint_math =*(int32_t*)(&y_math);\
		    	if (fabsf(y-y_math)<FLT_TOLERANCE || fabs(yint-yint_math)<=1)\
				{\
					pass++;\
				}\
				else{\
					e_4091 = 1;\
				}\
		    }\
			if(e_4091){\
				printf("result:%f,expect:%f\n",y,y_math);\
				return -1;\
				}\
			return 0;\
		}\

TEST_4091(test_div4f32, -FLT_MAX, FLT_MAX, __alb_div4f32(x), x / 4);
TEST_4091(test_mpysqrt3f32, -FLT_MAX/M_SQRT3, FLT_MAX/M_SQRT3, __alb_mpysqrt3f32(x), x*M_SQRT3);
TEST_4091(test_mpysqrt3div2f32, -FLT_MAX, FLT_MAX, __alb_mpysqrt3div2f32(x), x/2*M_SQRT3);
TEST_4091(test_mpysqrt3div6f32, -FLT_MAX, FLT_MAX, __alb_mpysqrt3div6f32(x), x/6*M_SQRT3);

#define TEST_10000(func,__xmin,__xmax,__inst,__sw) \
		int func(void)\
		{\
		    float xmin = __xmin;\
		    float xmax =__xmax;\
		    float x= xmin;\
		    float xstep = FLT_MAX/10000;\
		    float y;\
		    float y_math;\
		    int e_10000 = 0;\
		    int32_t yint;\
		    int32_t yint_math;\
		    for(;x<=xmax;x+=xstep)\
		    {\
		    	y=__inst;\
		    	y_math = __sw;\
		    	yint =*(int32_t*)(&y);\
		    	yint_math =*(int32_t*)(&y_math);\
		    	if (fabsf(y-y_math)<FLT_TOLERANCE || fabs(yint-yint_math)<=1)\
				{\
					pass++;\
				}\
				else{\
					e_10000 = 1;\
				}\
		    }\
			if(e_10000){\
				printf("result:%f,expect:%f\n",y,y_math);\
				return -1;\
			}\
			return 0;\
		}\


TEST_10000(test_divsqrt3f32, -FLT_MAX, FLT_MAX, __alb_divsqrt3f32(x), x/M_SQRT3);
TEST_10000(test_mpy2divsqrt3f32, -FLT_MAX/2*M_SQRT3, FLT_MAX/2*M_SQRT3, __alb_mpy2divsqrt3f32(x), x/M_SQRT3*2);

#define MY_LOG2_E    1.4426950408889634074

int test_mpylog2ef32(void)
{
#if 1
    float xmin = -1000.0f;
    float xmax = 1000.0f;
    float x = xmin;
    float xstep = (xmax - xmin) / 2047;
#else
    float xmin = -FLT_MAX/MY_LOG2_E;
    float xmax = FLT_MAX/MY_LOG2_E;

    float x= xmin;
    float xstep = FLT_MAX/1001;
#endif
    float y;
    float y_math;
    int32_t yint;
    int32_t yint_math;
    int e_log2e = 0;
    for (; x <= xmax; x += xstep)
    {
        y = __alb_mpylog2ef32(x);
        y_math = x * MY_LOG2_E;
        yint = *(int32_t*) (&y);
        yint_math = *(int32_t*) (&y_math);
        if (fabsf(y - y_math) < FLT_TOLERANCE || fabs(yint - yint_math) <= 1)
        {
            pass++;
        }
        else
        {
            e_log2e = 1;
        }
    }
    if (e_log2e)
    {
        printf("result:%f,expect:%f\n", y, y_math);
        return -1;
    }
    return 0;
}

int test_nmpylog2ef32(void)
{
#if 1
    float xmin = -1000.0f;
    float xmax = 1000.0f;
    float x = xmin;
    float xstep = (xmax - xmin) / 2047;
#else
    float xmin = -FLT_MAX/MY_LOG2_E;
    float xmax = FLT_MAX/MY_LOG2_E;
    float x= xmin;
    float xstep = FLT_MAX/10001;
#endif
    float y;
    float y_math;
    int32_t yint;
    int32_t yint_math;
    int e_nlog2e = 0;
    for (; x <= xmax; x += xstep)
    {
        y = __alb_nmpylog2ef32(x);
        y_math = -x * MY_LOG2_E;
        yint = *(int32_t*) (&y);
        yint_math = *(int32_t*) (&y_math);
        if (fabsf(y - y_math) < FLT_TOLERANCE || fabs(yint - yint_math) <= 1)
        {
            pass++;
        }
        else
        {
            e_nlog2e = 1;
        }
    }
    if (e_nlog2e)
    {
        printf("result:%f,expect:%f\n", y, y_math);
        return -1;
    }
    return 0;
}

#define TEST_10001(func,__xmin,__xmax,__inst,__sw)\
		int func(void)\
		{\
		    float xmin = __xmin;\
		    float xmax = __xmax;\
		    float x= xmin;\
		    float xstep = FLT_MAX/10001;\
		    float y;\
		    float y_math;\
		    int32_t yint;\
		    int32_t yint_math;\
		    int e_10001 = 0;\
		    for(;x<=xmax;x+=xstep)\
		    {\
		    	y=__inst;\
		    	y_math = __sw;\
		    	yint =*(int32_t*)(&y);\
		    	yint_math =*(int32_t*)(&y_math);\
		    	if (fabsf(y-y_math)<FLT_TOLERANCE || fabs(yint-yint_math)<=1)\
				{\
					pass++;\
				}\
				else{\
					e_10001 = 1;\
				}\
		    }\
			if(e_10001){\
				printf("result:%f,expect:%f\n",y,y_math);\
				return -1;\
			}\
			return 0;\
		}\

TEST_10001(test_add1f32, -FLT_MAX, FLT_MAX-1, __alb_add1f32(x), x + 1);
TEST_10001(test_sub1f32, -FLT_MAX+1, FLT_MAX, __alb_sub1f32(x), x - 1);

TEST_10001(test_nadd1f32, -FLT_MAX+1, FLT_MAX, __alb_nadd1f32(x), -x + 1);
TEST_10001(test_nsub1f32, -FLT_MAX, FLT_MAX-1, __alb_nsub1f32(x), -x - 1);

TEST_10001(test_addsqrt3f32, -FLT_MAX, FLT_MAX-M_SQRT3, __alb_addsqrt3f32(x), x+M_SQRT3);
TEST_10001(test_subsqrt3f32, -FLT_MAX+M_SQRT3, FLT_MAX, __alb_subsqrt3f32(x), x-M_SQRT3);

TEST_10001(test_naddsqrt3f32, -FLT_MAX+M_SQRT3, FLT_MAX, __alb_naddsqrt3f32(x), -x+M_SQRT3);
TEST_10001(test_nsubsqrt3f32, -FLT_MAX, FLT_MAX-M_SQRT3, __alb_nsubsqrt3f32(x), -x-M_SQRT3);

TEST_10001(test_addpid3f32, -FLT_MAX, FLT_MAX-M_PI/3, __alb_addpid3f32(x), x+M_PI/3);
TEST_10001(test_subpid3f32, -FLT_MAX+M_PI/3, FLT_MAX, __alb_subpid3f32(x), x-M_PI/3);

TEST_10001(test_naddpid3f32, -FLT_MAX+M_PI/3, FLT_MAX, __alb_naddpid3f32(x), -x+M_PI/3);
TEST_10001(test_nsubpid3f32, -FLT_MAX, FLT_MAX-M_PI/3, __alb_nsubpid3f32(x), -x-M_PI/3);

TEST_10001(test_truncf32, -FLT_MAX, FLT_MAX, __alb_truncf32(x), truncf(x));
TEST_10001(test_fractf32, -FLT_MAX, FLT_MAX, __alb_fractf32(x), x - truncf(x));

#define  CONST_X  (15)  //0~31 const

TEST_10001(test_naddcstf32, -FLT_MAX+CONST_X, FLT_MAX, __alb_naddcstf32(x,CONST_X), -x+CONST_X);
TEST_10001(test_nsubcstf32, -FLT_MAX, FLT_MAX-CONST_X, __alb_nsubcstf32(x,CONST_X), -x-CONST_X);

int test_satf32(void)
{
    float dinmin = -1000.0f;
    float dinmax = 1000.0f;
    float din = dinmin;
    float dinstep = (dinmax - dinmin) / 11;
    float x0min = -1000.0f;
    float x0max = 1000.0f;
    float x0 = x0min;
    float x0step = (x0max - x0min) / 2047;
    float x1min = -1000.0f;
    float x1max = 1000.0f;
    float x1 = x1min;
    float x1step = (x0max - x0min) / 23;
    float y;
//    float y_math;
//    int32_t yint;
//    int32_t yint_math;
    int e_f1 = 0;
    int e_f2 = 0;
    for (din = dinmin; din <= dinmax; din += dinstep)
    {
        for (x0 = x0min; x0 <= x0max; x0 += x0step)
        {
            for (x1 = x1min; x1 <= x1max; x1 += x1step)
            {
                if (x0 < x1)
                {
                    y = __alb_satf32(din, x1, x0);

                    if (y <= x1 && y >= x0)
                    {
//						printf("y:%f,x1:%f,x0:%f\n",y,x1,x0);
                        pass++;
                    }
                    else
                    {
                        printf("y:%f,x1:%f,x0:%f\n", y, x1, x0);
                        e_f1 = 1;
                    }
                }
                else
                {
                    y = __alb_satf32(din, x0, x1);
                    if (y <= x0 && y >= x1)
                    {
//						printf("y:%f,x1:%f,x0:%f\n",y,x1,x0);
                        pass++;
                    }
                    else
                    {
                        printf("y:%f,x1:%f,x0:%f\n", y, x1, x0);
                        e_f2 = 1;
                    }
                }
            }
        }
    }
    if (e_f1 || e_f2)
    {
        return -1;
    }
    return 0;
}
// hyperbolic
static inline ThreeFloats_T __alb_hypf32(float din)
{
  ThreeFloats_T results;
  float din_log2e,exp2,nexp2,sinhx_num,coshx_num;

  din_log2e = __alb_mpylog2ef32(din);
  exp2      = __alb_expf32(din_log2e);
  nexp2     = __alb_nexpf32(din_log2e);
  sinhx_num  = exp2 - nexp2;
  coshx_num  = exp2 + nexp2;
  results.result1 = __alb_div2f32(sinhx_num);          // sinhx(din)
  results.result3 = __alb_divf32(sinhx_num,coshx_num); // tanhx(din)
  results.result2 = __alb_div2f32(coshx_num);          // coshx(din)

  return results;
}
int zhanlu_test(void)
{
    int result;
    int p_sum = 0;
    int f_sum = 0;
    ThreeFloats_T temp = __alb_hypf32(1.0f);
    result = test_crc();
    printf("%s\n", result == 0 ? "PASS --test_crc" : "FAIL --test_crc");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_sqrtf32();					//2
    printf("%s\n", result == 0 ? "PASS --test_sqrtf32" : "FAIL --test_sqrtf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_sinpuf32();					//3
    printf("%s\n", result == 0 ? "PASS --test_sinpuf32" : "FAIL --test_sinpuf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_cospuf32();				//4
    printf("%s\n", result == 0 ? "PASS --test_cospuf32" : "FAIL --test_cospuf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_atanpuf32();					//5
    printf("%s\n", result == 0 ? "PASS --test_atanpuf32" : "FAIL --test_atanpuf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_expf32();					//6
    printf("%s\n", result == 0 ? "PASS --test_expf32" : "FAIL --test_expf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_aexpf32();					//7
    printf("%s\n", result == 0 ? "PASS --test_aexpf32" : "FAIL --test_aexpf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nexpf32();				//8
    printf("%s\n", result == 0 ? "PASS --test_nexpf32" : "FAIL --test_nexpf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_iexpf32();					//9
    printf("%s\n", result == 0 ? "PASS --test_iexpf32" : "FAIL --test_iexpf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_log2f32();					//10
    printf("%s\n", result == 0 ? "PASS --test_log2f32" : "FAIL --test_log2f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_divf32();						//11
    printf("%s\n", result == 0 ? "PASS --test_divf32" : "FAIL --test_divf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_quadf32();					//12
    printf("%s\n", result == 0 ? "PASS --test_quadf32" : "FAIL --test_quadf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_sumsqf32();					//13
    printf("%s\n", result == 0 ? "PASS --test_sumsqf32" : "FAIL --test_sumsqf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpy2pif32();					//14
    printf("%s\n", result == 0 ? "PASS --test_mpy2pif32" : "FAIL --test_mpy2pif32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_div2pif32();				//15
    printf("%s\n", result == 0 ? "PASS --test_div2pif32" : "FAIL --test_div2pif32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nmpy2pif32();					//16
    printf("%s\n", result == 0 ? "PASS --test_nmpy2pif32" : "FAIL --test_nmpy2pif32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_ndiv2pif32();				//17
    printf("%s\n", result == 0 ? "PASS --test_ndiv2pif32" : "FAIL --test_ndiv2pif32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpy2f32();					//18
    printf("%s\n", result == 0 ? "PASS --test_mpy2f32" : "FAIL --test_mpy2f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpy2div3f32();				//19
    printf("%s\n", result == 0 ? "PASS --test_mpy2div3f32" : "FAIL --test_mpy2div3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_div2f32();					//20
    printf("%s\n", result == 0 ? "PASS --test_div2f32" : "FAIL --test_div2f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_div3f32();					//21
    printf("%s\n", result == 0 ? "PASS --test_div3f32" : "FAIL --test_div3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_div4f32();					//22
    printf("%s\n", result == 0 ? "PASS --test_div4f32" : "FAIL --test_div4f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpysqrt3f32();				//23
    printf("%s\n", result == 0 ? "PASS --test_mpysqrt3f32" : "FAIL --test_mpysqrt3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpysqrt3div2f32();		//24
    printf("%s\n", result == 0 ? "PASS --test_mpysqrt3div2f32" : "FAIL --test_mpysqrt3div2f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpysqrt3div6f32();			//25
    printf("%s\n", result == 0 ? "PASS --test_mpysqrt3div6f32" : "FAIL --test_mpysqrt3div6f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_divsqrt3f32();			//26
    printf("%s\n", result == 0 ? "PASS --test_divsqrt3f32" : "FAIL --test_divsqrt3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpy2divsqrt3f32();			//27
    printf("%s\n", result == 0 ? "PASS --test_mpy2divsqrt3f32" : "FAIL --test_mpy2divsqrt3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_mpylog2ef32();			//28
    printf("%s\n", result == 0 ? "PASS --test_mpylog2ef32" : "FAIL --test_mpylog2ef32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nmpylog2ef32();				//29
    printf("%s\n", result == 0 ? "PASS --test_nmpylog2ef32" : "FAIL --test_nmpylog2ef32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_add1f32();					//30
    printf("%s\n", result == 0 ? "PASS --test_add1f32" : "FAIL --test_add1f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_sub1f32();					//31
    printf("%s\n", result == 0 ? "PASS --test_sub1f32" : "FAIL --test_sub1f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nadd1f32();					//32
    printf("%s\n", result == 0 ? "PASS --test_nadd1f32" : "FAIL --test_nadd1f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nsub1f32();					//33
    printf("%s\n", result == 0 ? "PASS --test_nsub1f32" : "FAIL --test_nsub1f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_addsqrt3f32();				//34
    printf("%s\n", result == 0 ? "PASS --test_addsqrt3f32" : "FAIL --test_addsqrt3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_subsqrt3f32();				//35
    printf("%s\n", result == 0 ? "PASS --test_subsqrt3f32" : "FAIL --test_subsqrt3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_naddsqrt3f32();				//36
    printf("%s\n", result == 0 ? "PASS --test_naddsqrt3f32" : "FAIL --test_naddsqrt3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nsubsqrt3f32();				//37
    printf("%s\n", result == 0 ? "PASS --test_nsubsqrt3f32" : "FAIL --test_nsubsqrt3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_addpid3f32();					//38
    printf("%s\n", result == 0 ? "PASS --test_addpid3f32" : "FAIL --test_addpid3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_subpid3f32();					//39
    printf("%s\n", result == 0 ? "PASS --test_subpid3f32" : "FAIL --test_subpid3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_naddpid3f32();				//40
    printf("%s\n", result == 0 ? "PASS --test_naddpid3f32" : "FAIL --test_naddpid3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nsubpid3f32();				//41
    printf("%s\n", result == 0 ? "PASS --test_nsubpid3f32" : "FAIL --test_nsubpid3f32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_truncf32();					//42
    printf("%s\n", result == 0 ? "PASS --test_truncf32" : "FAIL --test_truncf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_fractf32();					//43
    printf("%s\n", result == 0 ? "PASS --test_fractf32" : "FAIL --test_fractf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_naddcstf32();					//44
    printf("%s\n", result == 0 ? "PASS --test_naddcstf32" : "FAIL --test_naddcstf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_nsubcstf32();					//45
    printf("%s\n", result == 0 ? "PASS --test_nsubcstf32" : "FAIL --test_nsubcstf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    result = test_satf32();						//46
    printf("%s\n", result == 0 ? "PASS --test_satf32" : "FAIL --test_satf32");
    if (result == 0)
    {
        p_sum++;
    }
    else
    {
        f_sum++;
    }
    printf("PASS:%d,FAIL:%d\n\r", p_sum, f_sum);

    return (f_sum == 0) ? SC_PASS : SC_FAIL;
}
