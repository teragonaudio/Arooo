/*
  ==============================================================================

    InputAnalyzer.h
    Created: 20 Jan 2013 8:49:41am
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __InputAnalyzer_H_2F555109__
#define __InputAnalyzer_H_2F555109__

#include <stdio.h>
#include "Constants.h"

static const int kNumBucketsToDisplay = 4;

class FrequencyAnalyzer {
public:
  FrequencyAnalyzer();
  virtual ~FrequencyAnalyzer();

  void initialize();
  void processFFTData(const float* fftData);

protected:
  void printTopBuckets();
private:
  FILE* outputFile;
  int topBucketIndexes[kNumBucketsToDisplay];
  float topBucketValues[kNumBucketsToDisplay];
  int bucketHits[kBufferSize];
};

#endif  // __InputAnalyzer_H_2F555109__
