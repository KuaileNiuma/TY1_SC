/**
 *************************************************************************************
 * @file wwdt_ex01_reset.c
 * @brief This file contains the source file for example wwdt_ex01_reset.
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
 
#include "alb32r003x_evb.h"
#include "alb32r003x_screenTest.h"
#include "cpufeature.h"
#include "system_cpu.h"


typedef struct {
    uint32_t WWDG_Prescaler;   //!< WWDT prescaler value
    uint8_t timeVal;           //!< WWDT counter value
    uint8_t windowVal;         //!< WWDT window value
} wwdg_param_t;

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************
static const wwdg_param_t wwdg_params =
{
    WWDG_Prescaler_8,          //!< Prescaler set to 8
    0x7F,                      //!< Maximum counter value
    0x5F,                       //!< Window value set to 0x5F
};


//*****************************************************************************
//
// Initializes the Window Watchdog Timer
// 
//*****************************************************************************
void my_wwdt_init(wwdg_param_t wwdg_params)
{
    //
    // Set the WWDT prescaler
    //
    WWDG_SetPrescaler(WWDG1_BASE,wwdg_params.WWDG_Prescaler);
    
    //
    // Set the WWDT window value
    //
    WWDG_SetWindowValue(WWDG1_BASE,wwdg_params.windowVal);
    
    //
    // Set the WWDT counter value
    //
    WWDG_SetCounter(WWDG1_BASE,wwdg_params.timeVal);
}


//*****************************************************************************
//
// Performs WWDT system reset test
//  
//*****************************************************************************
void wwdt_system_reset_test(void)
{
    //
    // Initialize WWDT with predefined parameters
    //
    my_wwdt_init(wwdg_params);
    
    //
    // Enable WWDT with initial counter value 0x7F
    //
    WWDG_Enable(WWDG1_BASE,0x7F);
}

//*****************************************************************************
//
// Main function
// 
//*****************************************************************************
int main(void)
{
    uint64_t start_cycle;
    uint64_t timeout_cycle;
    uint32_t sys_clk;
    uint32_t cur0;
    uint32_t cur1;

	alb32r003x_evb_init();


	SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_WWDT);
	SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_WWDT);
    //
    // Access RCC register directly to modify clock settings
    //
	RCC_enableWWDGReset();
    
    //
    // Enable global interrupts
    //
    CPU_enableIrq();
    
    //
    // Start WWDT system reset test
    //
    wwdt_system_reset_test();

    //
    // Compute a CPU-cycle timeout in seconds
    //
    sys_clk = SystemClock_Get();
    if (sys_clk == 0)
    {
        sys_clk = 180000000U;
    }
    timeout_cycle = 5ULL * sys_clk;

    //
    // Verify the WWDT counter is running: the current down-counter value is the
    // T[6:0] field of the CR register. Read it twice; if it decreases, the
    // watchdog is working and a system reset is imminent.
    //
    cur0 = HWREG(WWDG1_BASE + WWDG_O_CR) & WWDG_CR_T;
    start_cycle = __get_rv_cycle();
    while (1)
    {
        cur1 = HWREG(WWDG1_BASE + WWDG_O_CR) & WWDG_CR_T;
        if (cur1 != cur0)
        {
            break;
        }
        if ((__get_rv_cycle() - start_cycle) > timeout_cycle)
        {
            printf("WWDT system reset test FAIL: counter is not running.\r\n");
            return SC_FAIL;
        }
    }

    if (cur1 < cur0)
    {
        printf("WWDT system reset test OK: counter running, system will be reset soon.\r\n");
        return SC_PASS;
    }

    printf("WWDT system reset test FAIL.\r\n");
    return SC_FAIL;
}
