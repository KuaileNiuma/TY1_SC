/** 
 *************************************************************************************
 * @file board.c
 * @author Albatross
 * @brief This file implements the function of alb32r003x_evb driver.
 * @version 1.0.0
 * @date 2025-07-30
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

#include "board.h"

/**
 * \brief      Variable to hold the system core clock value
 * \details
 * Holds the system core clock, which is the system clock frequency supplied to the SysTick
 * timer and the processor core clock. This variable can be used by debuggers to query the
 * frequency of the debug timer or to configure the trace clock speed.
 *
 * \attention
 * Compilers must be configured to avoid removing this variable in case the application
 * program is not using it. Debugging systems require the variable to be physically
 * present in memory so that it can be examined to configure the debugger.
 */


/*!
 *  \brief      configure COM port
 *  \param[in]  com: COM on the board
 *  \arg        EVAL_COM0: COM0 on the board
 *  \param[out] none
 *  \retval     none
 */

void debug_com_init(uint32_t uart_base)
{
#ifdef DEBUG_COM
    GPIO_setPinConfig(DEBUG_COM_UART_TX);
    GPIO_setPinConfig(DEBUG_COM_UART_RX);
    SCI_setBaud(uart_base, DEBUG_COM_UART_CLK, DEBUG_COM_UART_BAUD);
    SCI_setInitConfig(uart_base, SCI_CONFIG_PAR_NONE, SCI_STOP_1BIT,
            SCI_CHAR_8BITS);

    SCI_enableFIFO(uart_base);
    SCI_setFIFOInterruptLevel(uart_base, SCI_FIFO_TX0, SCI_FIFO_RX1);
#endif
}

/** Banner Print for SDK */
static void BannerPrint(void)
{
#ifdef DEBUG_PRINT
#if defined(ALB_SDK_BANNER) && (ALB_SDK_BANNER == 1)
    log_printf("ALB R003x SDK Build Time: %s, %s\r\n", __DATE__, __TIME__);
    log_printf("CPU Frequency %u Hz\r\n", (unsigned int)SystemClock_Get());
    log_printf("CPU HartID: %u\r\n", (unsigned int)__get_hart_id());
#endif
#endif
}


int putchar(int dat)
{
#if defined DEBUG_PRINT && defined DEBUG_COM_UART
    UART_writeCharArray(DEBUG_COM_UART, (const uint8_t *)&dat, 1);
#endif
    return dat;
}

int getchar(void)
{
    int dat;

#if defined DEBUG_PRINT && defined DEBUG_COM_UART
    UART_readCharArray(DEBUG_COM_UART, (uint8_t *)&dat, 1);
    #ifdef UART_AUTO_ECHO
        uart_write(DEBUG_COM_UART, (uint8_t)dat);
    #endif
#endif
    return dat;
}
//*****************************************************************************
//
// SetSysClockTo240
//
//*****************************************************************************
void SystemClock_Set240MHz( OSC_SRC_SEL src )
{
    FLASH_setLatency(FLASH_LETENCY_MAX);
    if(src == OSCSRC_HSI)
    {
        // 12 * 20 / 1 = 240
        RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 20, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
    }
    else
    {
#if (EVB_HSE_CLK==12000000)
            // 12 * 20 / 1 = 240
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 20, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#else
        // 20 * 12 / 1 = 240
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 12, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#endif
    }
    Flash_matchLatency(240000000);

    SystemClock_Update(240000000);
}
//*****************************************************************************
//
// SetSysClockTo240
//
//*****************************************************************************
void SystemClock_Set200MHz( OSC_SRC_SEL src )
{
    FLASH_setLatency(FLASH_LETENCY_MAX);
    if(src == OSCSRC_HSI)
    {
        // 12 * 50 / 3 = 200
        RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 50, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE4);
    }
    else
    {
#if (EVB_HSE_CLK==12000000)
            // 12 * 50 / 3 = 200
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 50, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE4);
#else
        // 20 * 10 / 1 = 200
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 10, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE4);
#endif
    }
    Flash_matchLatency(200000000);

    SystemClock_Update(200000000);
}

//*****************************************************************************
//
// SetSysClockTo180
//
//*****************************************************************************
void SystemClock_Set180MHz( OSC_SRC_SEL src )
{
    FLASH_setLatency(FLASH_LETENCY_MAX);
    if(src == OSCSRC_HSI)
    {
        // 12 * 15 = 180
        RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 15, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
    }
    else
    {
#if  (EVB_HSE_CLK==12000000)
            // 12 * 15 = 180
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 15, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#else
        // 20 * 9 = 180
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 9, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#endif
    }
    Flash_matchLatency(180000000);

    SystemClock_Update(180000000);
}

//*****************************************************************************
//
// SetSysClockTo160
//
//*****************************************************************************
void SystemClock_Set160MHz( OSC_SRC_SEL src )
{
    FLASH_setLatency(FLASH_LETENCY_MAX);
    if(src == OSCSRC_HSI)
    {
        // 12 * 40 / 3 = 160
        RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 40, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
    }
    else
    {
#if (EVB_HSE_CLK==12000000)
            // 12 * 40 / 3 = 160
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 40, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#else
        // 20 * 8 = 160
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 8, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#endif
    }
    Flash_matchLatency(160000000);

    SystemClock_Update(160000000);
}


//*****************************************************************************
//
// SetSysClockTo140
//
//*****************************************************************************
void SystemClock_Set140MHz( OSC_SRC_SEL src )
{
    FLASH_setLatency(FLASH_LETENCY_MAX);
    if(src == OSCSRC_HSI)
    {
        // 12 * 35 / 3 = 140
        RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 35, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
    }
    else
    {
#if (EVB_HSE_CLK==12000000)
            // 12 * 35 / 3 = 140
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 35, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#else
        // 20 * 7 = 140
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 7, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#endif
    }
    Flash_matchLatency(140000000);

    SystemClock_Update(140000000);
}


//*****************************************************************************
//
// SetSysClockTo120
//
//*****************************************************************************
void SystemClock_Set120MHz( OSC_SRC_SEL src )
{
    FLASH_setLatency(FLASH_LETENCY_MAX);
    if(src == OSCSRC_HSI)
    {
        // 12 * 10 /1 = 120
        RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 10, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
    }
    else
    {
#if (EVB_HSE_CLK==12000000)
            // 12 * 10 = 120
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 10, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#else
        // 20 * 6 / 1 = 120
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 6, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#endif
    }
    Flash_matchLatency(120000000);

    SystemClock_Update(120000000);

}

//*****************************************************************************
//
// SetSysClockTo100
//
//*****************************************************************************
void SystemClock_Set100MHz( OSC_SRC_SEL src )
{
    FLASH_setLatency(FLASH_LETENCY_MAX);
    if(src == OSCSRC_HSI)
    {
        // 12 * 25 / 3 = 100
        RCC_ClkConfig(SW_PLL, OSCSRC_HSI, 25, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
    }
    else
    {
#if (EVB_HSE_CLK==12000000)
            // 12 * 25 / 3 = 100
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 25, PLL_PRE_DIV3,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#else
        // 20 * 5 = 100
        RCC_ClkConfig(SW_PLL, OSCSRC_HSE, 5, PLL_PRE_DIV1,
                AHB_PRE1, APBH_PRE1, APBL_PRE2);
#endif
    }
    Flash_matchLatency(100000000);

    SystemClock_Update(100000000);

}


void OptionBytes_init()
{
	uint32_t option_byte_key;
	uint32_t option_byte0;
	uint32_t option_byte1;
	uint32_t option_byte3;
	uint32_t hsi1;
	uint32_t hsi2;
	uint32_t vref;

	if( HWREG(OB_BASE + OB_VALID_KEY_O) != OB_VALID_KEY)
	{
		return ;
	}

	hsi1 = HWREG(OB_BASE + OB_HSI1_O) & 0xFFFF;
	hsi2 = HWREG(OB_BASE + OB_HSI2_O) & 0xFFFF;
	vref = HWREG(OB_BASE + OB_VREF_O) & 0xFFFF;

	option_byte1 = HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1);
	option_byte0 = hsi1 | (hsi2 << 16);
	option_byte1 = (option_byte1 & 0xFFFF) | (vref << 16);
	option_byte3 = ((HWREG(0x1FFF7B28) & 0xFFFF) | ((HWREG(0x1FFF7B2C) & 0xFFFF) << 16));

	HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE0) = option_byte0;
	HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE1) = option_byte1;
	HWREG(SYSCTL_BASE + SYSCTL_O_OPTION_BYTE3) = option_byte3;
	SysCtl_setOBSource(SYSCTCL_OB);
}


void board_init()
{
    SystemClock_Set200MHz(OSCSRC_HSI);
    /* configure USART */
    debug_com_init(DEBUG_COM_UART);
    /* configure OptionBytes */
    OptionBytes_init();

    /* Display banner after UART initialized */
    BannerPrint();
}
