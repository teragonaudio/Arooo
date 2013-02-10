/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  23 Jan 2013 8:52:25pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
    : logOutput (0),
      analyzeFileButton (0),
      statusLabel (0),
      eventLogLabel (0)
{
    addAndMakeVisible (logOutput = new TextEditor ("Log Output"));
    logOutput->setMultiLine (true);
    logOutput->setReturnKeyStartsNewLine (true);
    logOutput->setReadOnly (true);
    logOutput->setScrollbarsShown (true);
    logOutput->setCaretVisible (false);
    logOutput->setPopupMenuEnabled (true);
    logOutput->setText (String::empty);

    addAndMakeVisible (analyzeFileButton = new TextButton ("Analyze File Button"));
    analyzeFileButton->setButtonText ("Analyze File");
    analyzeFileButton->addListener (this);

    addAndMakeVisible (statusLabel = new Label ("Status Label",
                                                "Status"));
    statusLabel->setFont (Font (15.0000f, Font::plain));
    statusLabel->setJustificationType (Justification::centredLeft);
    statusLabel->setEditable (false, false, false);
    statusLabel->setColour (TextEditor::textColourId, Colours::black);
    statusLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (eventLogLabel = new Label ("Event Log Label",
                                                  "Event log"));
    eventLogLabel->setFont (Font (15.0000f, Font::plain));
    eventLogLabel->setJustificationType (Justification::centredLeft);
    eventLogLabel->setEditable (false, false, false);
    eventLogLabel->setColour (TextEditor::textColourId, Colours::black);
    eventLogLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (logOutput);
    deleteAndZero (analyzeFileButton);
    deleteAndZero (statusLabel);
    deleteAndZero (eventLogLabel);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    logOutput->setBounds (16, 96, 568, 256);
    analyzeFileButton->setBounds (480, 8, 102, 24);
    statusLabel->setBounds (16, 360, 568, 24);
    eventLogLabel->setBounds (16, 64, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == analyzeFileButton)
    {
        //[UserButtonCode_analyzeFileButton] -- add your button handler code here..
        //[/UserButtonCode_analyzeFileButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainComponent::logText(const String& message) {
  logOutput->insertTextAtCaret(message);
  logOutput->insertTextAtCaret("\n");
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTEDITOR name="Log Output" id="4288934ade3e4dde" memberName="logOutput"
              virtualName="" explicitFocusOrder="0" pos="16 96 568 256" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TEXTBUTTON name="Analyze File Button" id="8abd1f5c1eea203a" memberName="analyzeFileButton"
              virtualName="" explicitFocusOrder="0" pos="480 8 102 24" buttonText="Analyze File"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Status Label" id="5093acf9357e9fe3" memberName="statusLabel"
         virtualName="" explicitFocusOrder="0" pos="16 360 568 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Status" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Event Log Label" id="708b4a47a4d62ead" memberName="eventLogLabel"
         virtualName="" explicitFocusOrder="0" pos="16 64 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Event log" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif



//[EndFile] You can add extra defines here...
//[/EndFile]
