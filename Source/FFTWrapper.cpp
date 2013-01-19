/*
  ==============================================================================

    FFTWrapper.cpp
    Created: 19 Jan 2013 1:34:46pm
    Author:  Nik Reiman

  ==============================================================================
*/

#include "FFTWrapper.h"
#include "Constants.h"

FFTWrapper::FFTWrapper() {
#if USE_FFT_FIXED_SIZE
  fftProcessor = new ffft::FFTRealFixLen<BUFFER_SIZE_BASE>;
#else
  fftProcessor = new ffft::FFTReal<float>(BUFFER_SIZE);
#endif
}

FFTWrapper::~FFTWrapper() {
  if (fftProcessor) {
    delete fftProcessor;
  }
}

void FFTWrapper::doFFT(float const *inputs, float *fftData) {
  fftProcessor->do_fft(fftData, inputs);
}
