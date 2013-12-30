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

  inputAnalyzer = NULL;
  eventDetector = NULL;
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

  if (inputAnalyzer) {
    delete inputAnalyzer;
  }
  if (eventDetector) {
    delete eventDetector;
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
  outputDevice = new MidiResponder();
  outputDevice->initialize();

#if ANALYSIS_MODE
  inputAnalyzer = new FrequencyAnalyzer();
  FrequencyAnalyzer->initialize();
#else
  eventDetector = new EventDetector();
  eventDetector->setCallback(outputDevice);
#endif
  fftWrapper = new FFTWrapper();
  fftData = new float[kBufferSize];

  FileLogger::getCurrentLogger()->writeToLog("Ready");
}

void InputProcessor::audioDeviceStopped() {
  FileLogger::getCurrentLogger()->writeToLog("Audio device stopped");
}

void InputProcessor::audioDeviceAboutToStart(AudioIODevice *device) {
  String message = "Starting audio device: ";
  message += device->getName();
  FileLogger::getCurrentLogger()->writeToLog(message);
}

void InputProcessor::audioDeviceIOCallback(const float **inputChannelData, int numInputChannels,
  float **outputChannelData, int numOutputChannels, int numSamples) {
  // Sanity checking
  if (numSamples != kBufferSize) {
    String message = String::formatted("Cannot process, wanted buffer size of %d, got %d", kBufferSize, numSamples);
    FileLogger::getCurrentLogger()->writeToLog(message);
    return;
  }
  if (!fftData) {
    // Still initializing
    return;
  }

  // Clear out old FFT data, just to be on the safe side
  for (int i = 0; i < kBufferSize; ++i) {
    fftData[i] = 0.0f;
  }

  // Force mono, we don't really care about stereo processing
  fftWrapper->doFFT(inputChannelData[0], fftData);
#if ANALYSIS_MODE
  inputAnalyzer->processFFTData(fftData);
#else
  eventDetector->processFFTData(fftData);
#endif
}
