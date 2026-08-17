/** 
  ************************************************************************************* 
  * @file sci.h 
  * @brief This file contains the definition of sci driver. 
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

#ifndef __SCI_H
#define __SCI_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup sci_api SCI
//! @{
//
//*****************************************************************************

#include "hw_common.h"
#include "hw_sci.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/*Save register values because the write only property of the register */
static uint32_t FCR_value = 0;
/* None */


/*
 * @brief Gets current receiver status flags.
 * @param base is the base address of the SCI port.
 * @return This function returns the current receiver status flags
 *          SCI_RXSTATUS_READY, SCI_RXSTATUS_OVERRUN, SCI_RXSTATUS_PARITY
 *          SCI_RXSTATUS_FRAMING, SCI_RXSTATUS_BREAK, SCI_TXREG_EMPTY
 *          SCI_TXSTATUS_EMPTY, SCI_RXFIFO_ERROR
 */
__STATIC_INLINE uint16_t
SCI_getLineStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //base
    // Return the current value of the receive status register.
    //
    return(HWREG(base + SCI_O_LSR));
}


/*
 * @brief Gets current sci status.
 * @param base is the base address of the SCI port.
 * @return the value of USR register
 *         value & SCI_UART_STATUS_BUSY
 *         value & SCI_UART_STATUS_TF_NOT_FULL
 *         value & SCI_UART_STATUS_TF_EMPTY
 *         value & SCI_UART_STATUS_RF_NOT_EMPTY
 *         value & SCI_UART_SYATUS_RF_FULL ? receive fifo full : not full
 */
__STATIC_INLINE uint32_t
SCI_getSCIStatusRegister(uint32_t base)
{

    ASSERT(SCI_isBaseValid(base));

    return(HWREG(base + SCI_O_USR));
}

/*
 * @brief read the transmit fifo status
 * @param base is the base address of SCI port
 * @return true the fifo is full
 *         false the fifo is not full
 */
__STATIC_INLINE bool
SCI_isTxFifoFull(uint32_t base)
{

    ASSERT(SCI_isBaseValid(base));

    return ((HWREG(base + SCI_O_USR) & SCI_USR_TFNF)==0);
}

/*
 * @brief Sets the type of parity.
 * @param base is the base address of the SCI port.
 *        parity specifies the type of parity to use.
 *               SCI_CONFIG_PAR_NONE/ SCI_CONFIG_PAR_EVEN/ SCI_CONFIG_PAR_ODD
 * @return None
 */
__STATIC_INLINE void
SCI_setParityMode(uint32_t base, SCI_ParityType parity)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    // if the sci is busy, can't write to the LCR
    while (SCI_getSCIStatusRegister(base) & SCI_UART_STATUS_BUSY)
    {

    }

    //
    // Set the parity mode.
    //
    HWREG(base + SCI_O_LCR) = ((HWREG(base + SCI_O_LCR) &
                                 ~(SCI_CONFIG_PAR_M)) | (uint16_t)parity);
}

/*
 * @brief gets the type of parity.
 * @param base is the base address of the SCI port.
 *
 * @return SCI_ParityType specifies the type of parity to use.
 *               SCI_CONFIG_PAR_NONE/ SCI_CONFIG_PAR_EVEN/ SCI_CONFIG_PAR_ODD
 */
__STATIC_INLINE SCI_ParityType
SCI_getParityMode(uint32_t base)
{
    uint16_t parity;

    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Return the current parity setting.
    //
    parity = (HWREG(base + SCI_O_LCR) & (SCI_CONFIG_PAR_M));

    return((SCI_ParityType)parity);
}



/*
 * @brief Sets the FIFO interrupt level at which interrupts are generated.
 * @param base is the base address of the SCI port.
 *        txLevel is the transmit FIFO interrupt level
 *              SCI_FIFO_TX0/SCI_FIFO_TX2/SCI_FIFO_TX4/SCI_FIFO_TX8
 *        rxLevel is the receive FIFO interrupt level
 *              SCI_FIFO_RX1/SCI_FIFO_RX4/SCI_FIFO_RX8/SCI_FIFO_RX14
 * @return None
 */
__STATIC_INLINE void
SCI_setFIFOInterruptLevel(uint32_t base, SCI_TxFIFOLevel txLevel,
                          SCI_RxFIFOLevel rxLevel)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));
    FCR_value = 0;

    FCR_value |= (((txLevel << SCI_FFTX_TET_S) | (rxLevel << SCI_FFRX_RT_S)));

    HWREG(base + SCI_O_IER_DLH) |= SCI_IER_PTIME;

    HWREG(base + SCI_O_IIR_FCR) = FCR_value | SCI_FCR_FIFOE;
}

/*
 * @brief Gets the FIFO interrupt level at which interrupts are generated.
 * @param base is the base address of the SCI port.
 *        txLevel is point to the transmit FIFO interrupt level
 *              SCI_FIFO_TX0/SCI_FIFO_TX2/SCI_FIFO_TX4/SCI_FIFO_TX8
 *        rxLevel is is point to the receive FIFO interrupt level
 *              SCI_FIFO_RX1/SCI_FIFO_RX4/SCI_FIFO_RX8/SCI_FIFO_RX14
 * @return None
 */
__STATIC_INLINE void
SCI_getFIFOInterruptLevel(uint32_t base, SCI_TxFIFOLevel *txLevel,
                          SCI_RxFIFOLevel *rxLevel)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Extract the transmit and receive FIFO levels.
    //
    *txLevel = (SCI_TxFIFOLevel)((FCR_value & SCI_FFTX_TXFFIL_M) >> SCI_FFTX_TET_S);
    *rxLevel = (SCI_RxFIFOLevel)((FCR_value & SCI_FFRX_RXFFIL_M) >> SCI_FFRX_RT_S);
}

/*
 * @brief Gets the current configuration of a SCI.
 * @param base is the base address of the SCI port.
 *        lspclkHz is the rate of the clock supplied to the SCI module.This is the LSPCLK
 *         baud is a pointer to storage for the baud rate.
 *         config is a pointer to storage for the data format.
 *
 * @return None
 */
__STATIC_INLINE void
SCI_getConfig(uint32_t base, uint32_t lspclkHz, uint32_t *baud,
              uint32_t *config)
{

    ASSERT(SCI_isBaseValid(base));

    while (SCI_getSCIStatusRegister(base) & SCI_UART_STATUS_BUSY)
    {

    }

    //
    // Compute the baud rate.
    //
    HWREG(base + SCI_O_LCR) |= SCI_LCR_DLAB;
    *baud = lspclkHz /
            ((uint32_t)((HWREG(base + SCI_O_IER_DLH) << 8U) | HWREG(base + SCI_O_RBR_THR_DLL)) * 16U);
    HWREG(base + SCI_O_LCR) &= ~SCI_LCR_DLAB;

    //
    // Get the parity, data length, and number of stop bits.
    //
    *config = HWREG(base + SCI_O_LCR) & (SCI_CONFIG_PAR_M |
                                          SCI_CONFIG_STOP_M |
                                          SCI_CONFIG_WLEN_M);
}

/*
 * @brief Sets the configuration of a SCI.
 * @param base is the base address of the SCI port.
 *        SCI_ParityType is the parity type
 *              SCI_CONFIG_PAR_NONE/SCI_CONFIG_PAR_EVEN/SCI_CONFIG_PAR_ODD
 *        SCI_DataLenSelect is the number of data bits
 *              SCI_CHAR_5BITS/SCI_CHAR_6BITS/SCI_CHAR_7BITS/SCI_CHAR_8BITS
 *
 * @return None
 */
__STATIC_INLINE void
SCI_setInitConfig(uint32_t base, SCI_ParityType parity, SCI_StopBit stop_bit, SCI_DataLenSelect data_len)
{
    uint32_t LCR_value = 0;

    ASSERT(SCI_isBaseValid(base));

//    while (SCI_getSCIStatusRegister(base) & SCI_UART_STATUS_BUSY)
//    {
//
//    }

    LCR_value = (HWREG(base + SCI_O_LCR) & (~(SCI_CONFIG_PAR_M | SCI_CONFIG_STOP_M | SCI_CONFIG_WLEN_M)));

    LCR_value |= (parity | stop_bit | data_len);

    HWREG(base + SCI_O_LCR) = LCR_value;
}

/*
 * @brief Enables the transmit and receive FIFOs.
 * @param base is the base address of the SCI port.
 *
 * @return None
 */
__STATIC_INLINE void
SCI_enableFIFO(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    FCR_value |= (SCI_FCR_RFIFOR | SCI_FCR_XFIFOR | SCI_FCR_FIFOE);

    //
    // Enable the FIFO.
    //
    HWREG(base + SCI_O_IIR_FCR) = (SCI_FCR_RFIFOR | SCI_FCR_XFIFOR | SCI_FCR_FIFOE);
}


/*
 * @brief get the recvive error status
 * @param base if the base address of SCI port
 *
 * @return the value of LSR register
 *         (bit(4): break interrupt bit)
 *         (bit(3): framing error)
 *         (bit(2): parity error bit)
 *         (bit(1): overrun error bit)
 *
 */
__STATIC_INLINE uint32_t
SCI_getRxError(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    return (HWREG(base + SCI_O_LSR) & (SCI_LSR_FE | SCI_LSR_PE | SCI_LSR_BI | SCI_LSR_OE));
}

/*
 * @brief disable the transmit and receive fifo
 * @param base is the base address of the SCI poart
 *
 * @return None
 */
__STATIC_INLINE void
SCI_disableFIFO(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Disable the FIFO.
    //
    FCR_value &= ~SCI_FCR_FIFOE;
    HWREG(base + SCI_O_IIR_FCR) = FCR_value;
}


/*
 * @brief Determines if the FIFO enhancement is enabled.
 * @param base is the base address of the SCI port.
 *
 * @return TRUE if the FIFO enhancement is enabled
 *         FALSE if the FIFO enhancement is disabled
 */
__STATIC_INLINE bool
SCI_isFIFOEnabled(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Return TRUE if the FIFO is enabled and FALSE if it is disabled.
    //
    return(((HWREG(base + SCI_O_IIR_FCR) & SCI_IIR_RO_FIFOSE_M) ==
            SCI_IIR_RO_FIFOSE_M) ? TRUE : FALSE);
}

/*
 * @brief Resets the receive FIFO
 * @param base is the base address of the SCI port.
 *
 * @return None
 */
__STATIC_INLINE void
SCI_resetRxFIFO(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Reset the specified FIFO.
    //
    FCR_value |= SCI_FCR_RFIFOR ;
    HWREG(base + SCI_O_IIR_FCR) = FCR_value;
    FCR_value &= ~SCI_FCR_RFIFOR ;
}

/*
 * @brief Resets the transmit FIFO
 * @param base is the base address of the SCI port.
 *
 * @return None
 */
__STATIC_INLINE void
SCI_resetTxFIFO(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Reset the specified FIFO.
    //
    FCR_value |= SCI_FCR_XFIFOR ;
    HWREG(base + SCI_O_IIR_FCR) = FCR_value;
    FCR_value &= ~SCI_FCR_XFIFOR ;
}

/*
 * @brief Resets the SCI Transmit and Receive Channels
 * @param base is the base address of the SCI port.
 *
 * @return None
 */
__STATIC_INLINE void
SCI_resetChannels(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Reset the Tx and Rx Channels
    //
    FCR_value |= (SCI_FCR_RFIFOR | SCI_FCR_XFIFOR);
    HWREG(base + SCI_O_IIR_FCR) = FCR_value;
    FCR_value &= ~(SCI_FCR_RFIFOR | SCI_FCR_XFIFOR);
}

/*
 * @brief Determines if there are any characters in the receive buffer when the FIFO enhancement is not enabled.
 * @param base is the base address of the SCI port.
 *
 * @return TRUE if there is data in the receive buffer
 *         False if there is no data in the receive buffer.
 */
__STATIC_INLINE bool
SCI_isDataAvailable(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Return the availability of characters with FIFO disabled.
    //
    return(((SCI_getLineStatus(base) & SCI_LSR_DR) ==
            SCI_LSR_DR) ? TRUE : FALSE);
}

//*****************************************************************************
//
//! Indicates that the receiver contains at least one character.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function checks if the receiver contains at least one character.
//! 
//! \return Returns 0x0 if data is not ready or 0x1 if data is ready.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
SCI_rxDataReady(uint32_t base)
{

    ASSERT(SCI_isBaseValid(base));

    //
    // Return the availability of characters with FIFO disabled.
    //
    return (SCI_getLineStatus(base) & SCI_LSR_DR);
}

//*****************************************************************************
//
//! Reads the data byte received on serial input port.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function reads the data byte received on the serial input port.
//! 
//! \return Returns the received data byte as uint32_t.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
SCI_readData(uint32_t base)
{

    ASSERT(SCI_isBaseValid(base));

    //
    // Return the availability of characters with FIFO disabled.
    //
    return ((HWREG(base + SCI_O_RBR_THR_DLL) & 0xff));
}

//*****************************************************************************
//
//! Determines if there is any space in the transmit buffer when the FIFO enhancement is not enabled.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function checks whether there is any space available in the transmit buffer
//! when the FIFO enhancement is not enabled.
//! 
//! \return Returns \b true if there is space available in the transmit buffer
//! or \b false if there is no space available in the transmit buffer.
//
//*****************************************************************************
__STATIC_INLINE bool
SCI_isSpaceAvailableNonFIFO(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Return the availability of space.
    //
    return(((SCI_getLineStatus(base) & SCI_LSR_TEMT) ==
            SCI_LSR_TEMT) ? TRUE : FALSE);
}

//*****************************************************************************
//
//! Determines whether the transmitter is empty.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function checks whether the transmitter is empty.
//! 
//! \return Returns \b true if the transmitter is empty or \b false if the transmitter is not empty.
//
//*****************************************************************************
__STATIC_INLINE bool
SCI_isTxEmpty(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Return the availability of space.
    //
    return(((SCI_getLineStatus(base) & SCI_LSR_TEMT) ==
            SCI_LSR_TEMT) ? TRUE : FALSE);
}

//*****************************************************************************
//
//! Gets the transmit FIFO status.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function retrieves the current number of data entries in the transmit FIFO.
//! 
//! \return Returns the current number of data entries in the transmit FIFO:
//! SCI_FIFO_TX0, SCI_FIFO_TX1, SCI_FIFO_TX2, SCI_FIFO_TX3, ..., SCI_FIFO_TX16.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
SCI_getTxFIFOStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Get the current FIFO status
    //
    return (SCI_TxFIFOLevel)(HWREG(base + SCI_O_TFL) & SCI_TFL_M);
}

//*****************************************************************************
//
//! Gets the receive FIFO status.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function retrieves the current number of words in the receive FIFO.
//! 
//! \return Returns the current number (0~16) of words in the receive FIFO.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
SCI_getRxFIFOStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Get the current FIFO status
    //
    return (SCI_RxFIFOStatus)(HWREG(base + SCI_O_RFL) & SCI_RFL_M);
}

//*****************************************************************************
//
//! Determines whether the SCI transmitter is busy or not.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function checks whether the SCI transmitter is busy or not.
//! 
//! \return Returns \b true if the SCI is transmitting or \b false if transmissions are complete.
//
//*****************************************************************************
__STATIC_INLINE bool
SCI_isTransmitterBusy(uint32_t base)
{
    //
    // Check the argument.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Check if FIFO enhancement is enabled.
    //
    if(SCI_isFIFOEnabled(base))
    {
        //
        // With FIFO enhancement, determine if the SCI is busy.
        //
        return(((HWREGH(base + SCI_O_TFL) & SCI_TFL_M) != 0) ? TRUE : FALSE);
    }
    else
    {
        //
        // Without FIFO enhancement, determine if the SCI is busy.
        // Check if the transmit buffer and shift register empty.
        //
        return(((SCI_getLineStatus(base) & SCI_LSR_TEMT) != SCI_LSR_TEMT) ? TRUE : FALSE);
    }
}

//*****************************************************************************
//
//! Waits to send a character from the specified port when the FIFO enhancement is enabled.
//! 
//! \param base is the base address of the SCI port.
//! \param data is the character to be transmitted.
//! 
//! This function waits until space is available in the transmit FIFO and then sends
//! the specified character from the specified port when the FIFO enhancement is enabled.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
UART_writeCharBlockingFIFO(uint32_t base, uint8_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Wait until space is available in the transmit FIFO.
    //
    while(SCI_isTxFifoFull(base))
    {
    }

    //
    // Send a char.
    //
    HWREG(base + SCI_O_RBR_THR_DLL) = data;
}

//*****************************************************************************
//
//! Waits to send a character from the specified port when the FIFO enhancement is enabled.
//! 
//! \param base is the base address of the SCI port.
//! \param data is the character to be transmitted.
//! 
//! This function waits until space is available in the transmit FIFO and then sends
//! the specified character from the specified port when the FIFO enhancement is enabled.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_writeCharBlockingFIFO(uint32_t base, uint16_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Wait until space is available in the transmit FIFO.
    //
    while(SCI_isTxFifoFull(base))
    {
    }

    //
    // Send a char.
    //
    HWREG(base + SCI_O_RBR_THR_DLL) = data;
}

//*****************************************************************************
//
//! Waits to send a character from the specified port when the FIFO enhancement is disabled.
//! 
//! \param base is the base address of the SCI port.
//! \param data is the character to be transmitted.
//! 
//! This function waits until space is available in the transmit buffer and then sends
//! the specified character from the specified port when the FIFO enhancement is disabled.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_writeCharBlockingNonFIFO(uint32_t base, uint16_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Wait until space is available in the transmit buffer.
    //
    while(!SCI_isSpaceAvailableNonFIFO(base))
    {
    }

    //
    // Send a char.
    //
    HWREG(base + SCI_O_RBR_THR_DLL) = data;
}

//*****************************************************************************
//
//! Waits to send a character from the specified port when the FIFO enhancement is disabled.
//! 
//! \param base is the base address of the SCI port.
//! \param data is the character to be transmitted.
//! 
//! This function waits until space is available in the transmit buffer and then sends
//! the specified character from the specified port when the FIFO enhancement is disabled.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
UART_writeCharBlockingNonFIFO(uint32_t base, uint8_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Wait until space is available in the transmit buffer.
    //
    while(!SCI_isSpaceAvailableNonFIFO(base))
    {
    }

    //
    // Send a char.
    //
    HWREG(base + SCI_O_RBR_THR_DLL) = data;
}

//*****************************************************************************
//
//! Sends a character to the specified port.
//! 
//! \param base is the base address of the SCI port.
//! \param data is the character to be transmitted.
//! 
//! This function sends a character to the specified port. It does not block and only writes to the transmit buffer.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_writeCharNonBlocking(uint32_t base, uint16_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Send a char.
    //
    HWREG(base + SCI_O_RBR_THR_DLL) = data;
}


//*****************************************************************************
//
//! Sends a character to the specified port.
//! 
//! \param base is the base address of the SCI port.
//! \param data is the character to be transmitted.
//! 
//! This function sends a character to the specified port. It does not block and only writes to the transmit buffer.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
UART_writeCharNonBlocking(uint32_t base, uint8_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Send a char.
    //
    HWREG(base + SCI_O_RBR_THR_DLL) = data;
}

//*****************************************************************************
//
//! Waits for a character from the specified port when the FIFO enhancement is enabled.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function waits for a character from the specified port when the FIFO enhancement is enabled.
//! If there is any error, it returns 0x0.
//! 
//! \return Returns the character read from the specified port as uint16_t
//! or 0x0 in case of error. The application must use SCI_getLineStatus()
//! API to check if some error occurred before consuming the data.
//
//*****************************************************************************
__STATIC_INLINE uint16_t
SCI_readCharBlockingFIFO(uint32_t base)
{

    ASSERT(SCI_isBaseValid(base));

    // Wait until a character is available in the receive FIFO.
    while(SCI_getRxFIFOStatus(base) == SCI_RX_FIFO_0)
    {
        //
        //If there is any error return
        //
        if((SCI_getLineStatus(base) & (SCI_LSR_FE | SCI_LSR_PE | SCI_LSR_OE)) != 0U)
        {
            return(0U);
        }
    }

    //
    // Return the character from the receive buffer.
    //
    return((uint16_t)(HWREG(base + SCI_O_RBR_THR_DLL) & SCI_RBR_SAR_M));
}

//*****************************************************************************
//
//! Reads a character from the specified port when the FIFO enhancement is not enabled.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function waits until a character is available and then reads it
//! from the specified port when the FIFO enhancement is not enabled.
//! 
//! \return Returns the character read from the specified port as uint16_t.
//
//*****************************************************************************
__STATIC_INLINE uint16_t
SCI_readCharBlockingNonFIFO(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Wait until a character is available in the receive FIFO.
    //
    while(!SCI_isDataAvailable(base))
    {
    }

    //
    // Return the character from the receive buffer.
    //
    return((uint16_t)(HWREG(base + SCI_O_RBR_THR_DLL) & SCI_RBR_SAR_M));
}

//*****************************************************************************
//
//! Gets a character from the receive buffer for the specified port.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function reads a character from the receive buffer for the specified port.
//! It does not block and only reads the receive buffer.
//! 
//! \return Returns the character read from the receive buffer as uint16_t.
//
//*****************************************************************************
__STATIC_INLINE uint16_t
SCI_readCharNonBlocking(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Return the character from the receive buffer.
    //
    return((uint16_t)(HWREG(base + SCI_O_RBR_THR_DLL) & SCI_RBR_SAR_M));
}

//*****************************************************************************
//
//! Performs a software reset of the SCI and clears all reported receiver status flags.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function performs a software reset of the SCI and clears all reported receiver status flags.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_performSoftwareReset(uint32_t base)
{

    ASSERT(SCI_isBaseValid(base));

    //
    // To clear all errors a sw reset of the module is required
    //
    ////HWREG(base + SCI_O_CTL1) &= ~SCI_CTL1_SWRESET;
    ////HWREG(base + SCI_O_CTL1) |= SCI_CTL1_SWRESET;
    //clear SCI_O_LSR
    SCI_getLineStatus(base);
}

//*****************************************************************************
//
//! Gets the current value of the receive status register.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function retrieves the current value of the receive status register.
//! 
//! \return Returns the current value of the receive status register.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
SCI_getRxStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //base
    // Return the current value of the receive status register.
    //
    return(HWREG(base + SCI_O_LSR));
}

//*****************************************************************************
//
//! Enables Loop Back Test Mode.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function enables the Loop Back Test Mode for the SCI port.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_enableLoopback(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Set the loop back mode.
    //
    HWREG(base + SCI_O_MCR) |= SCI_MCR_LOOPBACK;
}

//*****************************************************************************
//
//! Disables Loop Back Test Mode.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function disables the Loop Back Test Mode for the SCI port.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_disableLoopback(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Clear the loop back mode.
    //
    HWREG(base + SCI_O_MCR) &= ~SCI_MCR_LOOPBACK;
}


//*****************************************************************************
//
//! Gets the receive FIFO Overflow flag status.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function checks whether a receive FIFO overflow has occurred.
//! 
//! \return Returns \b true if an overflow has occurred or \b false if an overflow hasn't occurred.
//
//*****************************************************************************
__STATIC_INLINE bool
SCI_getOverflowStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Return the current FIFO overflow status
    //
    return((SCI_getLineStatus(base) & SCI_LSR_OE) == SCI_LSR_OE);
}

//*****************************************************************************
//
//! Clears the receive FIFO Overflow flag status.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function clears the receive FIFO Overflow flag status.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_clearOverflowStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Clear the current FIFO overflow status
    //
    SCI_getLineStatus(base);
}

//*****************************************************************************
//
//! Sets the configuration of a SCI.
//! 
//! \param base is the base address of the SCI port.
//! \param lspclkHz is the rate of the clock supplied to the SCI module.
//! \param baud is the desired baud rate.
//! \param config is the data format for the port (number of data bits, number of stop bits, and parity).
//! 
//! Valid values for number of data bits:
//! - SCI_CONFIG_WLEN_8, SCI_CONFIG_WLEN_7, ...., SCI_CONFIG_WLEN_1
//! 
//! Valid values for number of stop bits:
//! - SCI_CONFIG_STOP_ONE
//! - SCI_CONFIG_STOP_TWO
//! 
//! Valid values for parity:
//! - SCI_CONFIG_PAR_NONE
//! - SCI_CONFIG_PAR_EVEN
//! - SCI_CONFIG_PAR_ODD
//! 
//! This function configures the SCI module with the specified parameters including
//! baud rate, data format, stop bits, and parity settings.
//! 
//! \return None.
//
//*****************************************************************************
extern void
SCI_setConfig(uint32_t base, uint32_t lspclkHz, uint32_t baud,
              uint32_t config);

//*****************************************************************************
//
//! Sends an array of characters from the specified port.
//! 
//! \param base is the base address of the SCI port.
//! \param array is the address of the array of characters to be transmitted.
//! \param length is the number of characters in the array to be transmitted.
//! 
//! This function transmits an array of characters through the specified SCI port.
//! 
//! \return None.
//
//*****************************************************************************
extern void
SCI_writeCharArray(uint32_t base, const uint16_t * const array,
                   uint32_t length);
extern void
UART_writeCharArray(uint32_t base, const uint8_t * const array,
                   uint32_t length);

//*****************************************************************************
//
//! Reads an array of characters from the specified port.
//! 
//! \param base is the base address of the SCI port.
//! \param array is the address of the array where the received characters will be stored.
//! \param length is the number of characters to read from the port.
//! 
//! This function reads an array of characters from the specified SCI port and stores them
//! in the provided array.
//! 
//! \return None.
//
//*****************************************************************************
extern void
UART_readCharArray(uint32_t base, uint8_t * const array, uint32_t length);
//*****************************************************************************
//
//! Reads an array of characters from the specified port.
//! 
//! \param base is the base address of the SCI port.
//! \param array is the address of the array where the received characters will be stored.
//! \param length is the number of characters to read from the port.
//! 
//! This function reads an array of characters from the specified SCI port and stores them
//! in the provided array.
//! 
//! \return None.
//
//*****************************************************************************
extern void
SCI_readCharArray(uint32_t base, uint16_t * const array, uint32_t length);

//*****************************************************************************
//
//! Enables individual SCI interrupt sources.
//! 
//! \param base is the base address of the SCI port.
//! \param intFlags is the bit mask of the interrupt sources to be enabled.
//! 
//! Valid values for intFlags include:
//! - SCI_RX_DATA_AVAILABLE_INT       - Enable Received Data Available Interrupt
//! - SCI_TX_EMPTY_INT                - Enable Transmit Holding Register Empty Interrupt.
//! - SCI_LINE_STATUS_INT             - Enable Receiver Line Status Interrupt
//! - SCI_MODEN_STATUS_INT            - Enable Modem Status Interrupt
//! - SCI_LSR_CLEAR_METHOD            - Method for clearing the status in the LSR
//! - SCI_THRE_INT_MODE               - Programmable THRE Interrupt Mode Enable
//! 
//! This function enables the specified interrupt sources for the SCI port.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_enableInterrupt(uint32_t base, uint32_t intFlags)
{

    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Enable the specified interrupts.
    //
    HWREG(base + SCI_O_IER_DLH) |= intFlags;
}


//*****************************************************************************
//
//! Disables individual SCI interrupt sources.
//! 
//! \param base is the base address of the SCI port.
//! \param intFlags is the bit mask of the interrupt sources to be disabled.
//! 
//! Valid values for intFlags include:
//! - SCI_RX_DATA_AVAILABLE_INT       - Disable Received Data Available Interrupt
//! - SCI_TX_EMPTY_INT                - Disable Transmit Holding Register Empty Interrupt.
//! - SCI_LINE_STATUS_INT             - Disable Receiver Line Status Interrupt
//! - SCI_MODEN_STATUS_INT            - Disable Modem Status Interrupt
//! - SCI_LSR_CLEAR_METHOD            - Method for clearing the status in the LSR
//! - SCI_THRE_INT_MODE               - Programmable THRE Interrupt Mode Disable
//! 
//! This function disables the specified interrupt sources for the SCI port.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_disableInterrupt(uint32_t base, uint32_t intFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Disable the specified interrupts.
    //
    HWREG(base + SCI_O_IER_DLH) &= (~intFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function returns the current interrupt status of the SCI port.
//! 
//! \return Returns the current interrupt status, which can be one of the following values:
//! - SCI_MODEM_STATUS         = 0x00
//! - SCI_NO_INTERRUPT_PENDING = 0x01
//! - SCI_THR_EMPTY            = 0x02
//! - SCI_RX_DATA_AVAILABLE    = 0x04
//! - SCI_RX_LINE_STATUS       = 0x06
//! - SCI_BUSY_DETECT          = 0x07
//! - SCI_CHARACTER_TIMEOUT    = 0x0c
//
//*****************************************************************************
__STATIC_INLINE SCI_INT_STATUS
SCI_getInterruptStatus(uint32_t base)
{

    ASSERT(SCI_isBaseValid(base));

    //
    // Return the interrupt status.
    //

    return (SCI_INT_STATUS)(HWREG(base + SCI_O_IIR_FCR) & 0x0f);
}

//*****************************************************************************
//
//! Clears SCI interrupt sources.
//! 
//! \param base is the base address of the SCI port.
//! 
//! This function clears the interrupt sources by reading the line status register.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_clearInterruptStatus(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(SCI_isBaseValid(base));

    //
    // Clear the requested interrupt sources.
    //
    SCI_getLineStatus(base);
}


//*****************************************************************************
//
//! Clears SCI interrupt sources.
//! 
//! \param base is the base address of the SCI port.
//! \param intFlags is the interrupt source to clear.
//! 
//! Valid values for intFlags include:
//! - SCI_MODEM_STATUS         = 0x00
//! - SCI_NO_INTERRUPT_PENDING = 0x01
//! - SCI_THR_EMPTY            = 0x02
//! - SCI_RX_DATA_AVAILABLE    = 0x04
//! - SCI_RX_LINE_STATUS       = 0x06
//! - SCI_BUSY_DETECT          = 0x07
//! - SCI_CHARACTER_TIMEOUT    = 0x0c
//! 
//! This function clears the specified interrupt sources for the SCI port.
//! 
//! \return None.
//
//*****************************************************************************
extern void
SCI_clearInterruptFlag(uint32_t base, SCI_INT_STATUS intFlags);

//*****************************************************************************
//
//! Sets SCI Baud rate.
//! 
//! \param base is the base address of the SCI port.
//! \param lspclkHz is the rate of the clock supplied to the SCI module. This is the LSPCLK.
//! \param baud is the desired baud rate.
//! 
//! This function configures the SCI baud rate using the specified clock rate and desired baud rate.
//! 
//! \return None.
//
//*****************************************************************************
extern void
SCI_setBaud(uint32_t base, uint32_t lspclkHz, uint32_t baud);

//*****************************************************************************
//
//! Sets SCI Fractional Baud rate.
//! 
//! \param base is the base address of the SCI port.
//! \param lspclkHz is the rate of the clock supplied to the SCI module.
//! \param baud is the desired baud rate.
//! 
//! This function configures the SCI fractional baud rate using the specified clock rate and desired baud rate.
//! 
//! \return None.
//
//*****************************************************************************
extern void
SCI_setFractionalBaudRate(uint32_t base, uint32_t lspclkHz, uint32_t baud);



//*****************************************************************************
//
//! Sets the DMA mode for the SCI port.
//! 
//! \param base is the base address of the SCI port.
//! \param mode is the desired DMA mode to be set.
//! 
//! Valid values for mode include:
//! - DMAM_0
//! - DMAM_1
//! 
//! This function configures the DMA mode for the SCI port.
//! 
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
SCI_setDmaMode(uint32_t base, SCI_DmaMode mode)
{
    if(mode == DMAM_0)
    {
        FCR_value &= ~SCI_FCR_DMAM;
    }
    else
    {
        FCR_value |= SCI_FCR_DMAM;
    }

    HWREG(base + SCI_O_IIR_FCR) = FCR_value;
}

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif /* __SCI_H */

