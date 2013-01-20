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
  int midiflowerIndex = -1;
  StringArray midiDevices = MidiOutput::getDevices();
  for (int i = 0; i < midiDevices.size(); i++) {
    String deviceName = midiDevices[i];
    if (deviceName.equalsIgnoreCase("Midiflower")) {
      printf("Midiflower found at index %d\n", i);
      midiflowerIndex = i;
      break;
    }
  }

  if (midiflowerIndex >= 0) {
    midiOutput = MidiOutput::openDevice(midiflowerIndex);
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
