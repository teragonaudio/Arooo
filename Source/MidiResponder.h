/*
  ==============================================================================

    OutputDevice.h
    Created: 19 Jan 2013 5:13:34pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __OUTPUTDEVICE_H_B9E839E__
#define __OUTPUTDEVICE_H_B9E839E__

#include "../JuceLibraryCode/JuceHeader.h"
#include "Constants.h"
#include "EventDetector.h"

class MidiEventTimer : public Timer {
public:
  MidiEventTimer(MidiOutput *output) : Timer(), midiOutput(output), notePlaying(NULL) {}
  virtual ~MidiEventTimer() {}

  virtual void timerCallback() {
    midiOutput->sendMessageNow(message);
    if (notePlaying) { *notePlaying = false; }
    stopTimer();
  }

  void setMessage(MidiMessage &message) {
    this->message = message;
  }

  void setNotePlaying(bool *notePlaying) {
    this->notePlaying = notePlaying;
  }

private:
  MidiOutput *midiOutput;
  MidiMessage message;
  bool *notePlaying;
};

class MidiResponder : public EventDetectorCallback {
public:
  MidiResponder();
  virtual ~MidiResponder();

  void initialize();
protected:
  virtual void howlDetected();

private:
  MidiOutput *midiOutput;
  MidiEventTimer *midiEventTimer;
  bool notePlaying;
};

#endif  // __OUTPUTDEVICE_H_B9E839E__
