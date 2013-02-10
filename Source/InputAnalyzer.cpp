/*
  ==============================================================================

    InputAnalyzer.cpp
    Created: 20 Jan 2013 8:49:41am
    Author:  Nik Reiman

  ==============================================================================
*/

#include "InputAnalyzer.h"
#include "Constants.h"

InputAnalyzer::InputAnalyzer() {
  outputFile = NULL;
}

InputAnalyzer::~InputAnalyzer() {
  if (outputFile) {
    printTopBuckets();
    fprintf(outputFile, "--- Analysis finished ---\n");
    fflush(outputFile);
    fclose(outputFile);
    outputFile = NULL;
  }
}

void InputAnalyzer::initialize() {
  outputFile = fopen("/tmp/howl-analysis.txt", "w");
  fprintf(outputFile, "--- Starting analysis ---\n");
  for (int i = 0; i < kBufferSize; ++i) {
    bucketHits[i] = 0;
  }
}

void InputAnalyzer::processFFTData(const float *fftData) {
  for (int i = 0; i < kNumBucketsToDisplay; ++i) {
    topBucketIndexes[i] = 0;
    topBucketValues[i] = 0.0f;
  }

  for (int i = 0; i < kBufferSize; ++i) {
    for (int j = 0; j < kNumBucketsToDisplay; ++j) {
      if (fftData[i] > topBucketValues[j]) {
        // Shift all remaining top bucket values down
        for (int k = kNumBucketsToDisplay - 1; k > j; --k) {
          topBucketValues[k] = topBucketValues[k - 1];
          topBucketIndexes[k] = topBucketIndexes[k - 1];
        }
        topBucketValues[j] = fftData[i];
        topBucketIndexes[j] = i;
        break;
      }
    }
  }

  if (topBucketIndexes[0] > 0) {
    for (int i = 0; i < kNumBucketsToDisplay; ++i) {
      bucketHits[topBucketIndexes[i]]++;
      fprintf(outputFile, "%03d: %.02f\t ", topBucketIndexes[i], topBucketValues[i]);
    }
    fprintf(outputFile, "\n");
  }
}

void InputAnalyzer::printTopBuckets() {
  fprintf(outputFile, "-- All non-zero buckets --\n");
  for (int i = 0; i < kBufferSize; ++i) {
    if (bucketHits[i] > 0) {
      fprintf(outputFile, "  %d: %d\n", i, bucketHits[i]);
    }
  }
}