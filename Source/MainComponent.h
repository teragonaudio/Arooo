/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public Component
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void logText(const String& message);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* background_png;
    static const int background_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextEditor> logOutput;
    ScopedPointer<teragon::IndicatorLight> eventLight;
    ScopedPointer<teragon::ImageKnobSmall> toleranceKnob;
    ScopedPointer<teragon::ImageKnobSmall> cooldownKnob;
    ScopedPointer<teragon::ToggleButton> analyzeButton;
    ScopedPointer<teragon::ToggleButton> loadSampleButton;
    ScopedPointer<teragon::PushButton> normalizeSampleButton;
    ScopedPointer<teragon::PushButton> playSampleButton;
    ScopedPointer<teragon::PushButton> sendMidiButton;
    ScopedPointer<teragon::PushButton> noteOrCcButton;
    ScopedPointer<teragon::ImageKnobSmall> midiChannelKnob;
    ScopedPointer<teragon::ImageKnobSmall> midiNoteKnob;
    ScopedPointer<teragon::ImageKnobSmall> midiVelocityKnob;
    ScopedPointer<teragon::PushButton> runScriptButton;
    ScopedPointer<teragon::ToggleButton> editScriptButton;
    Image cachedImage_background_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9002020A4DD09B20__
