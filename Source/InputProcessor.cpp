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

  howlAnalyzer = NULL;
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

  if (howlAnalyzer) {
    delete howlAnalyzer;
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
  struct AudioDeviceManager::AudioDeviceSetup audioDeviceSetup;
  deviceManager->getAudioDeviceSetup(audioDeviceSetup);
  audioDeviceSetup.bufferSize = kBufferSize;
  deviceManager->setAudioDeviceSetup(audioDeviceSetup, false);
  deviceManager->addAudioCallback(this);
  outputDevice = new OutputDevice();
  outputDevice->initialize();

#if ANALYSIS_MODE
  howlAnalyzer = new HowlAnalyzer();
  howlAnalyzer->initialize();
#else
  howlDetector = new HowlDetector();
  howlDetector->setCallback(outputDevice);
#endif
  fftWrapper = new FFTWrapper();
  fftData = new float[kBufferSize];

  printf("Initialized\n");
}

void InputProcessor::audioDeviceStopped() {
  printf("Audio device stopped\n");
}

void InputProcessor::audioDeviceAboutToStart(AudioIODevice *device) {
  printf("Audio device starting\n");
}

void InputProcessor::audioDeviceIOCallback(const float **inputChannelData, int numInputChannels,
  float **outputChannelData, int numOutputChannels, int numSamples) {
  // Sanity checking
  if (numSamples != kBufferSize) {
    printf("Cannot process, wanted buffer size of %d, got %d\n", kBufferSize, numSamples);
    return;
  }
  if (!fftData) {
    printf("Waiting for initialization... ");
    return;
  }

  // Clear out old FFT data, just to be on the safe side
  for (int i = 0; i < kBufferSize; ++i) {
    fftData[i] = 0.0f;
  }

  // Force mono, we don't really care about stereo processing
  fftWrapper->doFFT(inputChannelData[0], fftData);
#if ANALYSIS_MODE
  howlAnalyzer->processFFTData(fftData);
#else
  howlDetector->processFFTData(fftData);
#endif
}
