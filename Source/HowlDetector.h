/*
  ==============================================================================

    HowlDetector.h
    Created: 19 Jan 2013 2:56:01pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __HOWLDETECTOR_H_F359D429__
#define __HOWLDETECTOR_H_F359D429__

#include "Constants.h"

class HowlDetectorCallback {
public:
  HowlDetectorCallback() {}
  virtual ~HowlDetectorCallback() {}

  virtual void howlDetected() = 0;
};

class HowlDetector {
public:
  HowlDetector();
  virtual ~HowlDetector();

  void processFFTData(const float* fftData);

  void setCallback(HowlDetectorCallback *callback);

private:
  void howlDetected();
  void resetNumHits();

  HowlDetectorCallback *callback;
  int numHits[BUCKET_NUM_INDEXES];
};

#endif  // __HOWLDETECTOR_H_F359D429__
