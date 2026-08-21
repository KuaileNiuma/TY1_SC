/**
 *************************************************************************************
 * @file aes_ex02_interrupt.c
 * @brief This file contains the definition of source file for example aes_ex02_interrupt.
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
#include <stdio.h>
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"

uint32_t aes_key[8];
uint32_t aes_din[4];
uint32_t aes_dout[4];
uint32_t aes_expect[4] = {0x70B4C55A, 0xD8CDB780, 0x6A7B0430, 0x69C4E0D8};

void aes_key_init(void)
{
    aes_key[0] = 0x0c0d0e0f;
    aes_key[1] = 0x08090a0b;
    aes_key[2] = 0x04050607;
    aes_key[3] = 0x00010203;
}

void aes_din_init(void)
{
	aes_din[0] = 0xccddeeff;
	aes_din[1] = 0x8899aabb;
	aes_din[2] = 0x44556677;
	aes_din[3] = 0x00112233;
}

__INTERRUPT void AESISR(void)
{
	AES_ClearCompleteFlag();
	printf("aes interrupt\r\n");
}

//*****************************************************************************
//
// main
//
//*****************************************************************************
int main(void)
{
    uint32_t i;

    aes_key_init();
    aes_din_init();
    alb32r003x_evb_init();
    printf("AES EX02 INTERRUPT.\r\n");
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_AES);
    //
    // Enable global interrupt
    //
    CPU_enableIrq();

    //
    // Register the AES interrupt handler
    //
    Interrupt_register(AES_IRQn, AESISR);

    //
    // Set the AES interrupt priority to highest
    //
    Interrupt_setPriority(AES_IRQn, 0, 0);

    //
    // Enable the AES interrupt
    //
    Interrupt_enable(AES_IRQn);

    AES_EnableInt();
    AES_ModeSelect(128, aes_key, AES_Encode);
    AES_WriteDIN(aes_din);
    AES_Start();


    delay_ms(5);
	AES_ReadDout(aes_dout);
    for(i = 0; i < 4;i++)
    {
        printf("0x%X\r\n",aes_dout[i]);
    }

    for(i = 0; i < 4; i++)
    {
        if(aes_dout[i] != aes_expect[i])
        {
            printf("AES EX02 INTERRUPT FAIL, index %d: expect 0x%X, actual 0x%X\r\n", i, aes_expect[i], aes_dout[i]);
            return SC_FAIL;
        }
    }
    printf("AES EX02 INTERRUPT PASS.\r\n");

    return SC_PASS;
}


