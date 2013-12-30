/*
  ==============================================================================

    EventDetector.cpp
    Created: 19 Jan 2013 2:56:01pm
    Author:  Nik Reiman

  ==============================================================================
*/

#include "EventDetector.h"

EventDetector::EventDetector(ConcurrentParameterSet &inParameters) :
parameters(inParameters) {
  resetBucketPoints();
}

void EventDetector::resetBucketPoints() {
  for (int i = 0; i < kHowlBucketNumIndexes; ++i) {
    bucketPoints[i] = 0;
  }
}

void EventDetector::processFFTData(const float *fftData) {
  int howlDetectionPoints = 0;
  for (int i = 0; i < kHowlBucketNumIndexes; ++i) {
    if (fftData[kHowlBucketIndexes[i]] >= kBucketMinimumStrength) {
      bucketPoints[i] += 2;
    }
    else {
      if (bucketPoints[i] > 0) {
        bucketPoints[i]--;
      }
    }

    howlDetectionPoints += bucketPoints[i];
  }

  if (howlDetectionPoints > kHowlDetectionNumPointsNeeded) {
      parameters.set(eventDetected, 1.0, this);
      resetBucketPoints();
  }
}

void EventDetector::onParameterUpdated(const Parameter *parameter) {
    // TODO: Set tolerance, cooldown
}
