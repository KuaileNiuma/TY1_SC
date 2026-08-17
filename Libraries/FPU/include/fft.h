/** 
  *************************************************************************************
  * @file fft.h 
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

#ifndef _FFT_H_
#define _FFT_H_

//*****************************************************************************
// the includes
//*****************************************************************************
#include "dsp_assert.h"
#include "dsp.h"
#include "zhanlu_nice.h"
//!
//! \defgroup DSP_FFT The FFT (Fast Fourier Transform) Module

//! 
//! \ingroup DSP_FFT
//@{
    
#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
// defines
//*****************************************************************************
#define TWIDDLE_TABLE_SIZE  (1024U)
#define USE_ALT_RFFT2       (1U)
//*****************************************************************************
// typedefs
//*****************************************************************************
//! \brief Type of the FFT
//!
typedef enum{
    COMPLEX_RADIX_2,
    COMPLEX_RADIX_4,
    REAL_RADIX_2,
    REAL_RADIX_4,
    ALT_REAL_RADIX_2
}FFT_type_e;

//! \brief a function pointer with a void pointer argument returning nothing
//!
typedef void (*v_pfn_v)(void *);

//! \brief the FFT structure
//!
typedef struct _FFT{
    FFT_type_e type;       //!< Type of FFT
    uint16_t size;         //!< FFT Size
    uint16_t nstages;      //!< Number of FFT stages
    uint16_t skipfactor;   //!< Twiddle Factor Skip Factor
    uint16_t tftblsize;    //!< Twiddle Factor Table Size
    fsize_t *twiddles;     //!< Pointer to the Twiddle Factor Table
    fsize_t *windowtbl;    //!< Pointer to a windowing table
    fsize_t *iobuffer;     //!< Pointer to the input/output buffer 
    fsize_t *iobuffer2;    //!< Pointer to a second input/output buffer (rfft)
    fsize_t *magbuffer;    //!< Pointer to a magnitude buffer
    fsize_t *phasebuffer;  //!< Pointer to a phase buffer
    v_pfn_v run;           //!< Pointer to the function that implements an FFT
    v_pfn_v bitrev;        //!< Pointer to the bit reversal function
    v_pfn_v magnitude;     //!< Pointer to the Magnitude function
    v_pfn_v phase;         //!< Pointer to the Phase function
    v_pfn_v window;        //!< Pointer to the Windowing function
}FFT;

//! \brief Handle (pointer) type for the FFT Object
//!
typedef FFT *FFTHandle;

//*****************************************************************************
//globals3+
//*****************************************************************************
extern fsize_t DSP_twiddleFactorTbl[];
extern fsize_t DSP_rfftTwiddleFactorTbl[];
extern fsize_t DSP_window[];
//*****************************************************************************
// 'inline' function
//*****************************************************************************
//! \brief Set the type of the FFT
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] type, FFT type
//!
static inline void FFT_setType(FFTHandle fh, const FFT_type_e type)
{
    fh->type = type;
}

//! \brief Get the type of the FFT
//! \param[in] fh , handle to the 'FFT' object
//! \return type, FFT Type
//!
static inline uint16_t FFT_getType(FFTHandle fh)
{
    return(fh->type);
}

//! \brief Set the size of the FFT
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] size , FFT Size
//!
static inline void FFT_setSize(FFTHandle fh, const uint16_t size)
{
    fh->size = size;
}

//! \brief Get the size of the FFT
//! \param[in] fh , handle to the 'FFT' object
//! \return size , FFT Size
//!
static inline uint16_t FFT_getSize(FFTHandle fh)
{
    return(fh->size);
}

//! \brief Set the number of stages for the FFT
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] nstages , number of stages for the FFT
//!
static inline void FFT_setNStages(FFTHandle fh, const uint16_t nstages)
{
    fh->nstages = nstages;
}

//! \brief Get the number of stages for the FFT
//! \param[in] fh , handle to the 'FFT' object
//! \return nstages , number of stages for the FFT
//!
static inline uint16_t FFT_getNStages(FFTHandle fh)
{
    return(fh->nstages);
}

//! \brief Set the Twiddle Table skip factor
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] skipfactor , Twiddle Table skip factor
//!
static inline void FFT_setSkipFactor(FFTHandle fh, const uint16_t skipfactor)
{
    fh->skipfactor = skipfactor;
}

//! \brief Get the Twiddle Table skip factor
//! \param[in] fh , handle to the 'FFT' object
//! \return skipfactor , Twiddle Table skip factor
//!
static inline uint16_t FFT_getSkipFactor(FFTHandle fh)
{
    return(fh->skipfactor);
}

//! \brief Set the Twiddle Table Size
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] tftblsize , Twiddle Table Size
//!
static inline void FFT_setTfTblSize(FFTHandle fh, const uint16_t tftblsize)
{
    fh->tftblsize = tftblsize;
}

//! \brief Get the Twiddle Table Size
//! \param[in] fh , handle to the 'FFT' object
//! \return tftblsize , Twiddle Table Size
//!
static inline uint16_t FFT_getTfTblSize(FFTHandle fh)
{
    return(fh->tftblsize);
}

//! \brief Set the twiddle table pointer
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] ptf , pointer to the twiddle factor table
//!
static inline void FFT_setTwiddlePtr(FFTHandle fh, fsize_t *ptf)
{
    fh->twiddles = ptf;
}

//! \brief Get the twiddle table pointer
//! \param[in] fh , handle to the 'FFT' object
//! \return ptf , pointer to the twiddle factor table
//!
static inline fsize_t * FFT_getTwiddlePtr(FFTHandle fh)
{
    return(fh->twiddles);
}

//! \brief Set the Window table pointer
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pwd , pointer to the window table
//!
static inline void FFT_setWindowTblPtr(FFTHandle fh, fsize_t *pwd)
{
    fh->windowtbl = pwd;
}

//! \brief Get the Window table pointer
//! \param[in] fh , handle to the 'FFT' object
//! \return pwd , pointer to the window table
//!
static inline fsize_t * FFT_getWindowTblPtr(FFTHandle fh)
{
    return(fh->windowtbl);
}

//! \brief Set the IO Buffer pointer
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pio , pointer to the io buffer
//!
static inline void FFT_setIOBufferPtr(FFTHandle fh, fsize_t *pio)
{
    fh->iobuffer = pio;
}

//! \brief Get the IO Buffer pointer
//! \param[in] fh , handle to the 'FFT' object
//! \return pio , pointer to the io buffer
//!
static inline fsize_t * FFT_getIOBufferPtr(FFTHandle fh)
{
    return(fh->iobuffer);
}

//! \brief Set the IO Buffer2 pointer
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pio , pointer to the io buffer
//!
static inline void FFT_setIOBuffer2Ptr(FFTHandle fh, fsize_t *pio)
{
    fh->iobuffer2 = pio;
}

//! \brief Get the IO Buffer2 pointer
//! \param[in] fh , handle to the 'FFT' object
//! \return pio , pointer to the io buffer
//!
static inline fsize_t * FFT_getIOBuffer2Ptr(FFTHandle fh)
{
    return(fh->iobuffer2);
}

//! \brief Set the Magnitude buffer pointer
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pmag , pointer to the mag buffer
//!
static inline void FFT_setMagBufferPtr(FFTHandle fh, fsize_t *pmag)
{
    fh->magbuffer = pmag;
}

//! \brief Get the Magnitude Buffer pointer
//! \param[in] fh , handle to the 'FFT' object
//! \return pmag , pointer to the mag buffer
//!
static inline fsize_t * FFT_getMagBufferPtr(FFTHandle fh)
{
    return(fh->magbuffer);
}

//! \brief Set the Phase buffer pointer
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pph , pointer to the phase buffer
//!
static inline void FFT_setPhaseBufferPtr(FFTHandle fh, fsize_t *pph)
{
    fh->phasebuffer = pph;
}

//! \brief Get the Phase Buffer pointer
//! \param[in] fh , handle to the 'FFT' object
//! \return pph , pointer to the phase buffer
//!
static inline fsize_t * FFT_getPhaseBufferPtr(FFTHandle fh)
{
    return(fh->phasebuffer);
}

//! \brief Set the run function
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pfn , pointer to the run function
//!
static inline void FFT_setRunFunction(FFTHandle fh, const v_pfn_v pfn)
{
    fh->run = pfn;
}

//! \brief Get the run function
//! \param[in] fh , handle to the 'FFT' object
//! \return pfn , pointer to the run function
//!
static inline v_pfn_v FFT_getRunFunction(FFTHandle fh)
{
    return(fh->run);
}

//! \brief Set the bit-reversal function
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pfn , pointer to the bit-reversal function
//!
static inline void FFT_setBitrevFunction(FFTHandle fh, const v_pfn_v pfn)
{
    fh->bitrev = pfn;
}

//! \brief Get the bit-reversal function
//! \param[in] fh , handle to the 'FFT' object
//! \return pfn , pointer to the bit-reversal function
//!
static inline v_pfn_v FFT_getBitrevFunction(FFTHandle fh)
{
    return(fh->bitrev);
}

//! \brief Set the magnitude function
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pfn , pointer to the magnitude function
//!
static inline void FFT_setMagnitudeFunction(FFTHandle fh, const v_pfn_v pfn)
{
    fh->magnitude = pfn;
}

//! \brief Get the magnitude function
//! \param[in] fh , handle to the 'FFT' object
//! \return pfn , pointer to the magnitude function
//!
static inline v_pfn_v FFT_getMagnitudeFunction(FFTHandle fh)
{
    return(fh->magnitude);
}

//! \brief Set the phase function
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pfn , pointer to the phase function
//!
static inline void FFT_setPhaseFunction(FFTHandle fh, const v_pfn_v pfn)
{
    fh->phase = pfn;
}

//! \brief Get the phase function
//! \param[in] fh , handle to the 'FFT' object
//! \return pfn , pointer to the phase function
//!
static inline v_pfn_v FFT_getPhaseFunction(FFTHandle fh)
{
    return(fh->phase);
}

//! \brief Set the window function
//! \param[in] fh , handle to the 'FFT' object
//! \param[in] pfn , pointer to the window function
//!
static inline void FFT_setWindowFunction(FFTHandle fh, const v_pfn_v pfn)
{
    fh->window = pfn;
}

//! \brief Get the window function
//! \param[in] fh , handle to the 'FFT' object
//! \return pfn , pointer to the window function
//!
static inline v_pfn_v FFT_getWindowFunction(FFTHandle fh)
{
    return(fh->window);
}
//*****************************************************************************
// 'extern' function prototypes
//*****************************************************************************
//! \brief The complex FFT (Radix 2)
//! \param hnd handle to an FFT object
//!
extern void FFT_runCFFT2(FFTHandle hnd);

//! \brief The complex FFT (Radix 4)
//! \param hnd handle to an FFT object
//!
extern void FFT_runCFFT4(FFTHandle hnd);
      
//! \brief The complex Inverse FFT (Radix 2)
//! \param hnd handle to an FFT object
//!
extern void FFT_runICFFT2(FFTHandle hnd);
      
//! \brief The complex Inverse FFT (Radix 4)
//! \param hnd handle to an FFT object
//!
extern void FFT_runICFFT4(FFTHandle hnd);
      
//! \brief The unpack function
//! \param hnd handle to an FFT object
//! The Real FFT uses the unpack function to get the true spectrum of the 
//! input (real data only). The real portion of the spectrum is symmetric
//! about the Nyquist point while the imaginary portion is antisymmetric.
//!
extern void FFT_unpack(FFTHandle hnd);

//! \brief The pack function
//! \param hnd handle to an FFT object
//! The spectrum of the Real FFT must be "packed" before an N/2 point inverse
//! FFT is applied to get the original real input signal.
//! \note the output of the pack ends up in the io2 buffer, the 
//! io and io2 pointers must be exchanged before running the N/2 point
//! inverse complex FFT
//!
extern void FFT_pack(FFTHandle hnd);

//! \brief The Real FFT
//! \param hnd handle to an FFT object
//! The real FFT for an N-point real data vector will first, treat the input
//! as an N/2 point complex vector, with even data points forming the real part
//! and odd data points the imaginary part, and running a complex FFT on it. 
//! The output must then be "unpacked" to get the true spectrum of the real
//! input
//!
extern void FFT_runRFFT(FFTHandle hnd);

//! \brief The real FFT (Radix 2)
//! \param hnd handle to an FFT object
//!
extern void FFT_runRFFT2(FFTHandle hnd);

//! \brief The Inverse Real FFT
//! \param hnd handle to an FFT object
//! The inverse real FFT will first "pack" the data before running an 
//! N/2 point inverse complex FFT to get the real input
//!
extern void FFT_runIRFFT(FFTHandle hnd);

//! \brief The Magnitude Function
//! \param hnd handle to an FFT object
//! The magnitude function expects the output of the FFT to be in the I/O 2
//! buffer.
//!
extern void FFT_getMagnitude(FFTHandle hnd);

//! \brief The Phase Function
//! \param hnd handle to an FFT object
//! The phase function expects the output of the FFT to be in the I/O 2
//! buffer.
//!
extern void FFT_getPhase(FFTHandle hnd);

//! \brief The Windowing Function
//! \param hnd handle to an FFT object
//! The magnitude function expects the input to the FFT to be in the I/O
//! buffer.
//!
extern void FFT_applyWindow(FFTHandle hnd);

//! \brief Get a bit-reversed index
//! \param idx index to bit-reversed
//! \param nbits number of bits to reverse
//!
extern uint32_t FFT_bitReverseIndex(uint32_t idx, uint16_t nbits);


//! \brief Bit-reverse the FFT input
//! \param hnd handle to an FFT object
//!
extern void FFT_bitReverseInput(FFTHandle hnd);


extern void CFFT2_run(int16_t size, fsize_t *input, fsize_t *output);

extern void CFFT4_run(int16_t size, fsize_t *input, fsize_t *output);

extern void ICFFT2_run(int16_t size, fsize_t *input, fsize_t *output);

extern void ICFFT4_run(int16_t size, fsize_t *input, fsize_t *output);

extern void IRFFT2_run(int16_t size, fsize_t *input, fsize_t *output);

extern void IRFFT4_run(int16_t size, fsize_t *input, fsize_t *output);

extern void RFFT2_run(int16_t size, fsize_t *input, fsize_t *output);

extern void RFFT4_run(int16_t size, fsize_t *input, fsize_t *output);

extern void WCFFT2_run(int16_t size, fsize_t *input, fsize_t *output);

extern void WCFFT4_run(int16_t size, fsize_t *input, fsize_t *output);

extern void WRFFT2_run(int16_t size, fsize_t *input, fsize_t *output);

extern void WRFFT4_run(int16_t size, fsize_t *input, fsize_t *output);

#ifdef __cplusplus
}
#endif //extern "C"

//@} //ingroup

#endif // end of _FFT_H_ definition
