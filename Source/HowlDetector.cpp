/*
  ==============================================================================

    HowlDetector.cpp
    Created: 19 Jan 2013 2:56:01pm
    Author:  Nik Reiman

  ==============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include "HowlDetector.h"
#include "Constants.h"

HowlDetector::HowlDetector() {
  callback = NULL;
  resetNumHits();
}

HowlDetector::~HowlDetector() {

}

void HowlDetector::resetNumHits() {
  for (int i = 0; i < BUCKET_NUM_INDEXES; ++i) {
    numHits[i] = 0;
  }
}

void HowlDetector::processFFTData(float const *fftData) {
  int howlDetectionPoints = 0;
  for (int i = 0; i < BUCKET_NUM_INDEXES; ++i) {
    if (fftData[kHowlBucketIndexes[i]] >= BUCKET_MINIMUM_STRENGTH) {
      numHits[i]++;
    }

    if (numHits[i] > HOWL_FOUND_NUM_HITS) {
      howlDetectionPoints++;
    }
  }

  if (howlDetectionPoints == BUCKET_NUM_INDEXES) {
    howlDetected();
  }
}

void HowlDetector::howlDetected() {
  printf("Howl detected!\n");
  if (callback != NULL) {
    callback->howlDetected();
  }
  resetNumHits();
}

void HowlDetector::setCallback(HowlDetectorCallback *callback) {
  this->callback = callback;
}



