/**
  *************************************************************************************
  * @file rtos_ex01_main.c
  * @brief This file contains the source file for example rtos_ex01_main.
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

#include <stdint.h>
#include <ucos_ii.h>

#include <stdio.h>
#include "device.h"
#include "timer.h"
#include "debug.h"
#include "alb32r003x_evb.h"

#define mainQUEUE_LENGTH (1)
static void prvSetupHardware(void);
extern void idle_task(void);

void prvSetupHardware(void)
{
}

#define STK_LEN 256

OS_STK task1_stk[STK_LEN];
OS_STK task2_stk[STK_LEN];
OS_STK task3_stk[STK_LEN];
OS_STK start_stk[STK_LEN];

#define TASK1_PRIO 13
#define TASK2_PRIO 12
#define TASK3_PRIO 11
#define TASK_START_PRIO 10

void task1(void* args)
{
    int cnt = 0;
    for (;;) {
        cnt++;
        printf("task1 is running... %d\r\n", cnt);
        OSTimeDlyHMSM(0, 0, 0, 500);
    }
}

void task2(void* args)
{
    int cnt = 0;
    for (;;) {
        cnt++;
        printf("task2 is running... %d\r\n", cnt);
        OSTimeDlyHMSM(0, 0, 0, 250);
    }
}

void task3(void* args)
{
    int cnt = 0;
    for (;;) {
        cnt++;
        printf("task3 is running... %d\r\n", cnt);
        OSTimeDlyHMSM(0, 0, 0, 250);
#ifdef CFG_SIMULATION
        if (cnt > 2) {
            // directly exit if in nuclei internally simulation
            SIMULATION_EXIT(0);
        }
#endif
    }
}

void start_task(void* args)
{
    printf("start all task...\r\n");
    OSTaskCreate(task1, NULL, &task1_stk[STK_LEN - 1], TASK1_PRIO);
    OSTaskCreate(task2, NULL, &task2_stk[STK_LEN - 1], TASK2_PRIO);
    OSTaskCreate(task3, NULL, &task3_stk[STK_LEN - 1], TASK3_PRIO);
    OSTaskSuspend(TASK_START_PRIO);
}

int main(void)
{
    alb32r003x_evb_init();
    printf("Start ucosii...\r\n");
    prvSetupHardware();
    OSInit();
    OSTaskCreate(start_task, NULL, &start_stk[STK_LEN - 1], TASK_START_PRIO);
    printf("create start task success\r\n");
    OSStart();
    while (1) {
    }
}
