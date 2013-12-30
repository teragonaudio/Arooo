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
#include "PluginParameters.h"

using namespace teragon;

class MidiResponder : public ParameterObserver {
public:
    MidiResponder();
    virtual ~MidiResponder() {}

    virtual bool isRealtimePriority() const { return false; }

    virtual void onParameterUpdated(const Parameter *parameter);

    virtual MidiBuffer &getMessages() { return messages; }

private:
    void onEventDetected();

private:
    MidiBuffer messages;
    bool sendNotes;
    unsigned short channel;
    unsigned short noteNumber;
    unsigned short velocity;
};

#endif  // __OUTPUTDEVICE_H_B9E839E__
