/*
  ==============================================================================

    InputAnalyzer.h
    Created: 20 Jan 2013 8:49:41am
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __InputAnalyzer_H_2F555109__
#define __InputAnalyzer_H_2F555109__

#include "FFTWrapper.h"

static const int kNumBucketsToDisplay = 4;

class FrequencyAnalyzer {
public:
  FrequencyAnalyzer(const FFTWrapper &fft);

  virtual ~FrequencyAnalyzer() {}

  void initialize();
  void processFFTData(const float* fftData);

protected:
  void printTopBuckets();

private:
    const FFTWrapper &fftWrapper;

  int topBucketIndexes[kNumBucketsToDisplay];
  float topBucketValues[kNumBucketsToDisplay];
  int bucketHits[kBufferSize];
};

#endif  // __InputAnalyzer_H_2F555109__
