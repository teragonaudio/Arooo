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
  outputDevice = NULL;

  howlDetector = NULL;
  fftWrapper = NULL;
  fftData = NULL;
}

InputProcessor::~InputProcessor() {
  if (deviceManager) {
    deviceManager->closeAudioDevice();
    delete deviceManager;
  }
  if (outputDevice) {
    delete outputDevice;
  }

  if (howlDetector) {
    delete howlDetector;
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
  outputDevice = new OutputDevice();
  outputDevice->initialize();

  howlDetector = new HowlDetector();
  howlDetector->setCallback(outputDevice);
  fftWrapper = new FFTWrapper();
  fftData = new float[BUFFER_SIZE];
  printf("Initialized\n");
}

void InputProcessor::audioDeviceStopped() {
  printf("Audio device stopped\n");
}

void InputProcessor::audioDeviceAboutToStart(AudioIODevice *device) {
  printf("Audio device starting\n");
}

void InputProcessor::audioDeviceIOCallback(float const **inputChannelData, int numInputChannels,
  float **outputChannelData, int numOutputChannels, int numSamples) {
  if (fftData) {
    // Clear out old FFT data, just to be sure
    for (int i = 0; i < BUFFER_SIZE; ++i) {
      fftData[i] = 0.0f;
    }
    // Force mono, we don't really care about stereo processing
    fftWrapper->doFFT(inputChannelData[0], fftData);
    howlDetector->processFFTData(fftData);
  }
  else {
    printf("Waiting for initialization...");
  }
}
