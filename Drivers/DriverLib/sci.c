/**
 *************************************************************************************
 * @file sci.c
 * @brief This file implements the function of uart driver.
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
 
 #include "sci.h"

#define UART_PARITYBIT_Pos      0x9U
#define UART_BIT0_Msk           0x1U

//*****************************************************************************
//
// SCI_setConfig
//
//*****************************************************************************
void
SCI_setConfig(uint32_t base, uint32_t lspclkHz, uint32_t baud, uint32_t config)
{
    SCI_setBaud(base, lspclkHz, baud);

    //
    // Set parity, data length, and number of stop bits.
    //
    HWREG(base + SCI_O_LCR) = ((HWREG(base + SCI_O_LCR) &
                                 ~(SCI_CONFIG_PAR_M |
                                   SCI_CONFIG_STOP_M |
                                   SCI_CONFIG_WLEN_M)) | config);
}

//*****************************************************************************
//
// SCI_writeCharArray
// note difference from SCI_writeCharrArray: the parameter "array" is uint8_t *
//
//*****************************************************************************
void
UART_writeCharArray(uint32_t base, const uint8_t * const array,
                   uint32_t length)
{
    uint32_t i;
    char *pArray = (char *)array;

    //
    // Check if FIFO enhancement is enabled.
    //
    if(SCI_isFIFOEnabled(base))
    {
        //
        // FIFO is enabled.
        // For loop to write (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until space is available in the transmit FIFO.
            //
            while(!SCI_isSpaceAvailableNonFIFO(base))
            {
            }

            //
            // Send a char.
            //
            HWREG(base + SCI_O_RBR_THR_DLL) = pArray[i];
        }
    }
    else
    {
        //
        // FIFO is not enabled.
        // For loop to write (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until space is available in the transmit buffer.
            //
            while(!SCI_isSpaceAvailableNonFIFO(base))
            {
            }

            //
            // Send a char.
            //
            HWREG(base + SCI_O_RBR_THR_DLL) = pArray[i];
        }
    }
}

//*****************************************************************************
//
// SCI_writeCharArray,
// note difference from SCI_writeCharrArray: the parameter "array" is uint16_t *,
// but only lower 8bit is written into Tx Register
//
//*****************************************************************************
void
SCI_writeCharArray(uint32_t base, const uint16_t * const array,
                   uint32_t length)
{
    uint32_t i;
    uint16_t *pArray = (uint16_t *)array;

    //
    // Check if FIFO enhancement is enabled.
    //
    if(SCI_isFIFOEnabled(base))
    {
        //
        // FIFO is enabled.
        // For loop to write (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until space is available in the transmit FIFO.
            //
            //while(SCI_getTxFIFOStatus(base) == SCI_FIFO_TX16) //1.0没锟斤拷实锟斤拷锟斤拷锟斤拷拇锟斤拷锟�?
            while(!SCI_isSpaceAvailableNonFIFO(base))
            {
            }

            //
            // Send a char.
            //
            HWREG(base + SCI_O_RBR_THR_DLL) = pArray[i];
        }
    }
    else
    {
        //
        // FIFO is not enabled.
        // For loop to write (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until space is available in the transmit buffer.
            //
            while(!SCI_isSpaceAvailableNonFIFO(base))
            {
            }

            //
            // Send a char.
            //
            HWREG(base + SCI_O_RBR_THR_DLL) = pArray[i];
        }
    }
}

//*****************************************************************************
//
// SCI_readCharArray
//
//*****************************************************************************
void
UART_readCharArray(uint32_t base, uint8_t * const array, uint32_t length)
{
    uint16_t i;
    char *pArray = (char *)array;

    //
    // Check if FIFO enhancement is enabled.
    //
    if(SCI_isFIFOEnabled(base))
    {
        //
        // FIFO is enabled.
        // For loop to read (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until a character is available in the receive FIFO.
            //
            //while(SCI_getRxFIFOStatus(base) == 0) //1.0没锟斤拷实锟斤拷锟斤拷锟斤拷拇锟斤拷锟�?
            while(!SCI_isDataAvailable(base))
            {
            }

            //
            // Return the character from the receive buffer.
            //
            pArray[i] = (HWREG(base + SCI_O_RBR_THR_DLL) & SCI_RXBUF_SAR_M);
        }
    }
    else
    {
        //
        // FIFO is not enabled.
        // For loop to read (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until a character is available in the receive buffer.
            //
            while(!SCI_isDataAvailable(base))
            {
            }

            //
            // Return the character from the receive buffer.
            //
            pArray[i] = (HWREG(base + SCI_O_RBR_THR_DLL) & SCI_RXBUF_SAR_M);
        }
    }
}

//*****************************************************************************
//
// SCI_readCharArray
//
//*****************************************************************************
void
SCI_readCharArray(uint32_t base, uint16_t * const array, uint32_t length)
{
    uint16_t i;
    uint16_t *pArray = (uint16_t *)array;

    //
    // Check if FIFO enhancement is enabled.
    //
    if(SCI_isFIFOEnabled(base))
    {
        //
        // FIFO is enabled.
        // For loop to read (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until a character is available in the receive FIFO.
            //
            //while(SCI_getRxFIFOStatus(base) == 0) //1.0没锟斤拷实锟斤拷锟斤拷锟斤拷拇锟斤拷锟�?
            while(!SCI_isDataAvailable(base))
            {
            }

            //
            // Return the character from the receive buffer.
            //
            pArray[i] = (HWREG(base + SCI_O_RBR_THR_DLL) & SCI_RXBUF_SAR_M);
        }
    }
    else
    {
        //
        // FIFO is not enabled.
        // For loop to read (Blocking) 'length' number of characters
        //
        for(i = 0U; i < length; i++)
        {
            //
            // Wait until a character is available in the receive buffer.
            //
            while(!SCI_isDataAvailable(base))
            {
            }

            //
            // Return the character from the receive buffer.
            //
            pArray[i] = (HWREG(base + SCI_O_RBR_THR_DLL) & SCI_RXBUF_SAR_M);
        }
    }
}

//*****************************************************************************
//
// SCI_setBaud
//
//*****************************************************************************
void SCI_setBaud(uint32_t base, uint32_t lspclkHz, uint32_t baud)
{
    uint32_t divider;

    //
    // Compute the baud rate divider {ROUND TO NEAREST INTEGER}
    //
    divider = ((float)((float)lspclkHz / ((float)baud * 16.0F))) + 0.5F;

    //
    // Set the baud rate.
    //
    HWREG(base + SCI_O_LCR) |= SCI_LCR_DLAB;
    HWREG(base + SCI_O_IER_DLH) = (divider & 0xFF00U) >> 8U;
    HWREG(base + SCI_O_RBR_THR_DLL) = divider & 0x00FFU;
    HWREG(base + SCI_O_LCR) &= ~SCI_LCR_DLAB;

}


 void SCI_clearInterruptFlag(uint32_t base, SCI_INT_STATUS intFlags)
{
    //
    // Check the arguments.
    //
    uint32_t value = 0;

    if (intFlags == SCI_MODEM_STATUS)
    {
        value = HWREG(base + SCI_O_MSR);
    }
    else if (intFlags == SCI_THR_EMPTY)
    {
        value = HWREG(base + SCI_O_IIR_FCR);
    }
    else if (intFlags == SCI_RX_DATA_AVAILABLE || intFlags == SCI_CHARACTER_TIMEOUT)
    {

    }
    else if (intFlags == SCI_RX_LINE_STATUS)
    {
        value = SCI_getLineStatus(base);
    }
    else if (intFlags == SCI_BUSY_DETECT)
    {
        value = SCI_getSCIStatusRegister(base);
    }
}



