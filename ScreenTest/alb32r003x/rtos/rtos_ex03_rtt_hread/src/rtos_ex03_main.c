/**
  *************************************************************************************
  * @file rtos_ex03_main.c
  * @brief This file contains the source file for example rtos_ex03_main.
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


#include "device.h"
#include <rtthread.h>
#include "alb32r003x_evb.h"

#define THREAD_PRIORITY 2
#define THREAD_STACK_SIZE 512
#define THREAD_TIMESLICE 5
#define THREAD_NUM      5

/* Align stack when using static thread */
ALIGN(RT_ALIGN_SIZE)
static rt_uint8_t thread_stack[THREAD_NUM][THREAD_STACK_SIZE];
static struct rt_thread tid[THREAD_NUM];

/* Thread entry function */
static void thread_entry(void* parameter)
{
    rt_uint32_t count = 0;

    while (1) {
        rt_kprintf("thread %d count: %d\n", (rt_uint32_t)parameter, count++);
        rt_thread_mdelay(250);
    }
}

/* Thread demo */
int create_thread_demo(void)
{
    unsigned long i;
    for (i = 0; i < THREAD_NUM; i ++) {
        /* Create static threads */
        rt_thread_init(&tid[i], "thread", thread_entry, (void*)i, thread_stack[i],
                       THREAD_STACK_SIZE, THREAD_PRIORITY, THREAD_TIMESLICE);
    }

    /* Startup threads  */
    for (i = 0; i < THREAD_NUM; i ++) {
        rt_thread_startup(&tid[i]);
    }

    return 0;
}

int main(void)
{
    rt_uint32_t count = 0;

    alb32r003x_evb_init();
    create_thread_demo();

    while (1) {
        rt_kprintf("Main thread count: %d\n", count++);
        rt_thread_mdelay(500);
#ifdef CFG_SIMULATION
        if (count > 2) {
            // directly exit if in nuclei internally simulation
            SIMULATION_EXIT(0);
        }
#endif
    }
}
