/*
  ==============================================================================

    InputProcessor.h
    Created: 19 Jan 2013 11:41:19am
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __INPUTPROCESSOR_H_4B9E1D4F__
#define __INPUTPROCESSOR_H_4B9E1D4F__

#include "../JuceLibraryCode/JuceHeader.h"
#include "Constants.h"
#include "FFTWrapper.h"
#include "EventDetector.h"
#include "OutputDevice.h"
#include "InputAnalyzer.h"

class InputProcessor : public AudioIODeviceCallback {
public:
  InputProcessor();
  virtual ~InputProcessor();

  void initialize();

protected:
  virtual void audioDeviceStopped();
  virtual void audioDeviceAboutToStart(AudioIODevice *device);
  virtual void audioDeviceIOCallback(float const **inputChannelData, int numInputChannels, float **outputChannelData, int numOutputChannels, int numSamples);

private:
  AudioDeviceManager *deviceManager;
  OutputDevice *outputDevice;

  InputAnalyzer *inputAnalyzer;
  EventDetector *eventDetector;
  FFTWrapper *fftWrapper;
  float *fftData;
};

#endif  // __INPUTPROCESSOR_H_4B9E1D4F__
