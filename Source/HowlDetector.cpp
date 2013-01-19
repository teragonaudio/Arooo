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
  resetBucketPoints();
}

HowlDetector::~HowlDetector() {

}

void HowlDetector::resetBucketPoints() {
  for (int i = 0; i < kHowlBucketNumIndexes; ++i) {
    bucketPoints[i] = 0;
  }
}

void HowlDetector::processFFTData(float const *fftData) {
  int howlDetectionPoints = 0;
  for (int i = 0; i < kHowlBucketNumIndexes; ++i) {
    if (fftData[kHowlBucketIndexes[i]] >= kBucketMinimumStrength) {
      //printf("Bucket %d has potential hit, %d total\n", kHowlBucketIndexes[i], bucketPoints[i]);
      bucketPoints[i] += 2;
    }
    else {
      if (bucketPoints[i] > 0) {
        //printf("Bucket %d no longer hitting, %d total\n", kHowlBucketIndexes[i], bucketPoints[i]);
        bucketPoints[i]--;
      }
    }

    howlDetectionPoints += bucketPoints[i];
  }

  if (howlDetectionPoints > kHowlDetectionNumPointsNeeded) {
    howlDetected();
  }
}

void HowlDetector::howlDetected() {
  printf("Howl detected!\n");
  if (callback != NULL) {
    callback->howlDetected();
  }
  resetBucketPoints();
}

void HowlDetector::setCallback(HowlDetectorCallback *callback) {
  this->callback = callback;
}



