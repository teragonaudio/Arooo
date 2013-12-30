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
#include "PluginParameters.h"

using namespace teragon;

class EventDetector : public ParameterObserver {
public:
    EventDetector(ConcurrentParameterSet &parameters);

    virtual ~EventDetector() {}

    void processFFTData(const float *fftData);

    virtual bool isRealtimePriority() const { return true; }
    virtual void setParameter(Parameter *parameter) { eventDetected = parameter; }

    virtual void onParameterUpdated(const Parameter *parameter);

private:
    void resetBucketPoints();

    ConcurrentParameterSet &parameters;
    Parameter *eventDetected;
    int bucketPoints[kHowlBucketNumIndexes];
};

#endif  // __EventDetector_H_F359D429__
