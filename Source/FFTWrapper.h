/*
  ==============================================================================

    FFTWrapper.h
    Created: 19 Jan 2013 1:34:46pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __FFTWRAPPER_H_D77FAC66__
#define __FFTWRAPPER_H_D77FAC66__

#include "Constants.h"

#if USE_FFT_FIXED_SIZE
#include "FFTRealFixLen.h"
#else
#include "FFTReal.h"
#endif

class FFTWrapper {
public:
  FFTWrapper();
  ~FFTWrapper();

  void doFFT(const float *inputs, float *fftData);

private:
#if USE_FFT_FIXED_SIZE
  ffft::FFTRealFixLen<kBufferSizeBase2> *fftProcessor;
#else
  ffft::FFTReal<float> *fftProcessor;
#endif
};

#endif  // __FFTWRAPPER_H_D77FAC66__
