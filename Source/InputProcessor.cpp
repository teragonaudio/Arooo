/*
  ==============================================================================

    InputProcessor.cpp
    Created: 19 Jan 2013 11:41:19am
    Author:  Nik Reiman

  ==============================================================================
*/

#include "InputProcessor.h"

InputProcessor::InputProcessor() {
  deviceManager = NULL;
  inputDevice = NULL;
  fftWrapper = NULL;
  fftData = NULL;
}

InputProcessor::~InputProcessor() {
  if (deviceManager) {
    deviceManager->closeAudioDevice();
    delete deviceManager;
  }

  if (inputDevice) {
    if (inputDevice->isOpen()) {
      inputDevice->close();
    }
    delete inputDevice;
  }

  if (fftWrapper) {
    delete fftWrapper;
  }

  if (fftData) {
    delete [] fftData;
  }
}

void InputProcessor::initialize() {
  deviceManager = new AudioDeviceManager();
  deviceManager->initialise(2, 0, NULL, true, String::empty, NULL);
  deviceManager->addAudioCallback(this);

  fftWrapper = new FFTWrapper();
  fftData = new float[BUFFER_SIZE];
}

void InputProcessor::audioDeviceStopped() {
  printf("Audio device stopped\n");
}

void InputProcessor::audioDeviceAboutToStart(AudioIODevice *device) {
  printf("Audio device about to start\n");
}

void InputProcessor::audioDeviceIOCallback(float const **inputChannelData, int numInputChannels,
  float **outputChannelData, int numOutputChannels, int numSamples) {
  // Force mono, we don't really care about stereo processing
  memset(fftData, 0, sizeof(float) * BUFFER_SIZE);
  fftWrapper->doFFT(inputChannelData[0], fftData);
  int i = 0;
  float highBucketValue = 0.0f;
  int highBucketIndex = 0;
  for (i = 0; i < BUFFER_SIZE; ++i) {
    if (fftData[i] > highBucketValue) {
      highBucketIndex = i;
      highBucketValue = fftData[i];
    }
  }
  printf("High bucket is %d\n", highBucketIndex);
}
