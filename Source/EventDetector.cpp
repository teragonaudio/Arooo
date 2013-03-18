/*
  ==============================================================================

    EventDetector.cpp
    Created: 19 Jan 2013 2:56:01pm
    Author:  Nik Reiman

  ==============================================================================
*/

#include <stdio.h>
#include "../JuceLibraryCode/JuceHeader.h"
#include "EventDetector.h"
#include "Constants.h"

EventDetector::EventDetector() {
  callback = NULL;
  resetBucketPoints();
}

EventDetector::~EventDetector() {

}

void EventDetector::resetBucketPoints() {
  for (int i = 0; i < kHowlBucketNumIndexes; ++i) {
    bucketPoints[i] = 0;
  }
}

void EventDetector::processFFTData(float const *fftData) {
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
    howlDetected();
  }
}

void EventDetector::howlDetected() {
  Time currentTime = Time::getCurrentTime();
  String message = "Howl detected at ";
  message += currentTime.formatted("%H:%M.%S");
  Logger::getCurrentLogger()->writeToLog(message);

  if (callback != NULL) {
    callback->howlDetected();
  }
  resetBucketPoints();
}

void EventDetector::setCallback(EventDetectorCallback *callback) {
  this->callback = callback;
}



