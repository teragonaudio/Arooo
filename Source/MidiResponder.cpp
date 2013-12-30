/*
  ==============================================================================

    OutputDevice.cpp
    Created: 19 Jan 2013 5:13:34pm
    Author:  Nik Reiman

  ==============================================================================
*/

#include "MidiResponder.h"

MidiResponder::MidiResponder() : ParameterObserver(),
messages(), sendNotes(false), channel(0), noteNumber(0), velocity(127) {
}

#if 0
void MidiResponder::initialize() {
  if (midiOutputDeviceIndex >= 0) {
    midiOutput = MidiOutput::openDevice(midiOutputDeviceIndex);
    String message = "Using MIDI output device: ";
    message += midiDevices[midiOutputDeviceIndex];
    FileLogger::getCurrentLogger()->writeToLog(message);
    midiOutput->startBackgroundThread();
    midiEventTimer = new MidiEventTimer(midiOutput);
  }
  else {
    FileLogger::getCurrentLogger()->writeToLog("No preferred MIDI device found");
  }
}
#endif

void MidiResponder::onParameterUpdated(const Parameter *parameter) {
    if(parameter->getName() == "Event Detected") {
        onEventDetected();
    }
    else if(parameter->getName() == "Send MIDI Note/CC") {
        sendNotes = (parameter->getValue() > 0.5);
    }
    else if(parameter->getName() == "MIDI Channel") {
        channel = (unsigned short)parameter->getValue();
    }
    else if(parameter->getName() == "MIDI Note") {
        noteNumber = (unsigned short)parameter->getValue();
    }
    else if(parameter->getName() == "MIDI Velocity") {
        velocity = (unsigned short)parameter->getValue();
    }
}

void MidiResponder::onEventDetected() {
    // TODO: Should send a corresponding note off message later if sending notes -- how to do this?
    MidiMessage message;
    if(sendNotes) {
        message = MidiMessage::noteOn(channel, noteNumber, (uint8)velocity);
    }
    else {
        message = MidiMessage::controllerEvent(channel, noteNumber, velocity);
    }
    messages.addEvent(message, 0);
}
