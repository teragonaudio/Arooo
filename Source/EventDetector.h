/*
  ==============================================================================

    EventDetector.h
    Created: 19 Jan 2013 2:56:01pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __EventDetector_H_F359D429__
#define __EventDetector_H_F359D429__

#include "Constants.h"

class EventDetectorCallback {
public:
  EventDetectorCallback() {}
  virtual ~EventDetectorCallback() {}

  virtual void howlDetected() = 0;
};

class EventDetector {
public:
  EventDetector();
  virtual ~EventDetector();

  void processFFTData(const float* fftData);

  void setCallback(EventDetectorCallback *callback);

private:
  void howlDetected();
  void resetBucketPoints();

  EventDetectorCallback *callback;
  int bucketPoints[kHowlBucketNumIndexes];
};

#endif  // __EventDetector_H_F359D429__
