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
#include "HowlDetector.h"

class MidiEventTimer : public Timer {
public:
  MidiEventTimer(MidiOutput *output) : Timer(), midiOutput(output) {}
  virtual ~MidiEventTimer() {}

  virtual void timerCallback() {
    MidiMessage noteOffMessage;
    noteOffMessage.allNotesOff(kOutputMidiChannel);
    midiOutput->sendMessageNow(noteOffMessage);
    stopTimer();
  }

private:
  MidiOutput *midiOutput;
};

class OutputDevice : public HowlDetectorCallback {
public:
  OutputDevice();
  virtual ~OutputDevice();

  void initialize();
protected:
  virtual void howlDetected();

private:
  MidiOutput *midiOutput;
  MidiEventTimer *midiEventTimer;
};

#endif  // __OUTPUTDEVICE_H_B9E839E__
