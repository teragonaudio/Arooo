/*
  ==============================================================================

    OutputDevice.cpp
    Created: 19 Jan 2013 5:13:34pm
    Author:  Nik Reiman

  ==============================================================================
*/

#include "OutputDevice.h"

OutputDevice::OutputDevice() {
  midiOutput = NULL;
  midiEventTimer = NULL;
  notePlaying = false;
}

OutputDevice::~OutputDevice() {
  if (midiOutput) {
    midiOutput->clearAllPendingMessages();
    midiOutput->stopBackgroundThread();
    delete midiOutput;
  }

  if (midiEventTimer) {
    midiEventTimer->stopTimer();
    delete midiEventTimer;
  }
}

void OutputDevice::initialize() {
  // Search for the Midiflower output device
  int midiOutputDeviceIndex = -1;
  StringArray midiDevices = MidiOutput::getDevices();
  for (int i = 0; i < midiDevices.size(); i++) {
    String deviceName = midiDevices[i];
    if (deviceName.equalsIgnoreCase("Midiflower")) {
      midiOutputDeviceIndex = i;
      break;
    }
#if USE_IAC_DRIVER
    if (deviceName.equalsIgnoreCase("IAC Driver")) {
      midiOutputDeviceIndex = i;
      break;
    }
#endif
  }

  if (midiOutputDeviceIndex >= 0) {
    midiOutput = MidiOutput::openDevice(midiOutputDeviceIndex);
    printf("Using MIDI output device: ");
    std::cout << midiDevices[midiOutputDeviceIndex] << std::endl;
    midiOutput->startBackgroundThread();
    midiEventTimer = new MidiEventTimer(midiOutput);
  }
}

void OutputDevice::howlDetected() {
  if (midiOutput && !notePlaying) {
    MidiMessage noteOnMessage = MidiMessage::noteOn(kOutputMidiChannel,
      kOutputMidiNoteNumber, (uint8)kOutputMidiNoteVelocity);
    midiOutput->sendMessageNow(noteOnMessage);
    MidiMessage noteOffMessage = MidiMessage::noteOff(kOutputMidiChannel,
      kOutputMidiNoteNumber, (uint8)kOutputMidiNoteVelocity);
    midiEventTimer->setMessage(noteOffMessage);
    midiEventTimer->setNotePlaying(&notePlaying);
    midiEventTimer->startTimer(kOutputMidiNoteDurationMs);
    notePlaying = true;
  }
}
