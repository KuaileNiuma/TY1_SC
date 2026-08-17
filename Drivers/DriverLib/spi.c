/**
 *************************************************************************************
 * @file spi.c
 * @brief This file implements the function of spi driver.
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
#include "spi.h"

//*****************************************************************************
//
// SPI_setConfig
//
//*****************************************************************************
void
SPI_setConfig(uint32_t base, uint32_t lspclkHz, SPI_TransferProtocol protocol,
              SPI_Mode mode, uint32_t bitRate, uint16_t dataWidth)
{
    uint32_t regValue = 0;
    uint32_t baud;


    //
    // Set polarity and phase
    //
    regValue = protocol;

    //
    // Set Trandfer Mode
    //
    regValue |= (mode & SPI_CTRLR0_TMOD_M);

    //
    // Set data width
    //
    regValue |= ((uint32_t)(dataWidth - 1) << SPI_CTRLR0_DFS_32_S);


    uint32_t cfgMasterSlaveMask = 0;


    if(base == SPI1_BASE)
    {
        cfgMasterSlaveMask = SPIA_CFG_MASTER_MASK;
    }
    else if(base == SPI2_BASE)
    {
        cfgMasterSlaveMask = SPIB_CFG_MASTER_MASK;
    }
    else if(base == SPI3_BASE)
    {
        cfgMasterSlaveMask = SPIB_CFG_MASTER_MASK;
    }
    else if(base == SPI4_BASE)
    {
        cfgMasterSlaveMask = SPIB_CFG_MASTER_MASK;
    }
    //
    // Check that the master/slave mode
    // 1 is the host mode and 0 is the slave mode
    //
    if((mode&SPI_MASTER_M))
    {
        //
        // set master mode
        //
    	switch(base)
    	{
    	case SPI1_BASE:
    		SPI_setModeControl(SYSCTL_BSPI1_MASTER_EN);
    		break;
    	case SPI2_BASE:
    		SPI_setModeControl(SYSCTL_BSPI2_MASTER_EN);
    		break;
    	case SPI3_BASE:
    		SPI_setModeControl(SYSCTL_BSPI3_MASTER_EN);
    		break;
    	case SPI4_BASE:
    		SPI_setModeControl(SYSCTL_BSPI4_MASTER_EN);
    		break;
    	}
        //
        // set baud
        //
        HWREG(base+SPI_O_BAUDR) = (lspclkHz / bitRate) & (~0x00000001U);

        HWREG(base+SPI_O_SER)    |= SPI_SER_SER;
    }
    else
    {
        //
        // set slave mode
        //
    	switch(base)
    	{
    	case SPI1_BASE:
    		SPI_setModeControl(SYSCTL_BSPI1_SLAVE_EN);
    		break;
    	case SPI2_BASE:
    		SPI_setModeControl(SYSCTL_BSPI2_SLAVE_EN);
    		break;
    	case SPI3_BASE:
    		SPI_setModeControl(SYSCTL_BSPI3_SLAVE_EN);
    		break;
    	case SPI4_BASE:
    		SPI_setModeControl(SYSCTL_BSPI4_SLAVE_EN);
    		break;
    	}
    }

    HWREG(base+SPI_O_CTRLR0) = regValue;

}


//*****************************************************************************
//
// SPI_clearInterruptStatus
//
//*****************************************************************************
void
SPI_clearInterruptStatus(uint32_t base, uint32_t intFlags)
{
    uint32_t status;

    if(intFlags & SPI_INT_RXFF_OVERFLOW)
    {
        status = HWREG(base+SPI_O_RXOICR);
    }

    if(intFlags & SPI_INT_TXFF_OF)
    {
        status = HWREG(base+SPI_O_TXOICR);
    }

    if(intFlags & SPI_INT_RXFF_UNDERFLOW)
    {
        status = HWREG(base+SPI_O_RXUICR);
    }

    if(intFlags & SPI_INT_MST)
    {
        status = HWREG(base+SPI_O_MSTICR);
    }
}
