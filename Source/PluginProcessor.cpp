#include "PluginProcessor.h"

#if WIN32
#define _USE_MATH_DEFINES
#include <math.h>
#endif

AroooAudioProcessor::AroooAudioProcessor() :
AudioProcessor(),
ParameterObserver() {
    parameters.add(new VoidParameter("Event Active"));
    parameters.add(new VoidParameter("Analyze"));
    parameters.add(new IntegerParameter("Tolerance", 0, 100, 75));
    parameters.add(new FloatParameter("Cooldown", 0, 10, 0))->setUnit("Sec");
    parameters.add(new BooleanParameter("Play Sample", false));
    parameters.add(new VoidParameter("Load Sample"));
    parameters.add(new BooleanParameter("Normalize Sample", true));
    parameters.add(new BooleanParameter("Send MIDI", false));
    parameters.add(new BooleanParameter("Send MIDI Note/CC", false));
    parameters.add(new IntegerParameter("MIDI Channel", 0, 16, 0));
    parameters.add(new IntegerParameter("MIDI Note", 0, 127, 0));
    parameters.add(new IntegerParameter("MIDI Velocity", 0, 127, 127));
    parameters.add(new BooleanParameter("Run Script", false));
    parameters.add(new VoidParameter("Edit Script"));
    parameters.add(new StringParameter("Log Output"));

    ParameterString version = ProjectInfo::projectName;
    version.append(" version ").append(ProjectInfo::versionString);
    parameters.add(new StringParameter("Version", version));

    parameters.pause();
    reset();
}

void AroooAudioProcessor::prepareToPlay(double sampleRate, int) {
    parameters.resume();
}

void AroooAudioProcessor::processBlock(AudioSampleBuffer &buffer, MidiBuffer &midiMessages) {
    parameters.processRealtimeEvents();

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for(int i = getNumInputChannels(); i < getNumOutputChannels(); ++i) {
        buffer.clear(i, 0, buffer.getNumSamples());
    }
}

void AroooAudioProcessor::releaseResources() {
    parameters.pause();
}

void AroooAudioProcessor::reset() {
}

void AroooAudioProcessor::onParameterUpdated(const Parameter *) {
}

void AroooAudioProcessor::getStateInformation(MemoryBlock &destData) {
    XmlElement xml(getName());
    for(size_t i = 0; i < parameters.size(); i++) {
        Parameter *parameter = parameters[i];
        xml.setAttribute(parameter->getSafeName().c_str(), parameter->getValue());
    }
    copyXmlToBinary(xml, destData);
}

void AroooAudioProcessor::setStateInformation(const void *data, int sizeInBytes) {
    ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if(xmlState != 0 && xmlState->hasTagName(getName())) {
        for(size_t i = 0; i < parameters.size(); i++) {
            Parameter *parameter = parameters[i];
            if(xmlState->hasAttribute(parameter->getSafeName().c_str())) {
                parameters.set(parameter, xmlState->getDoubleAttribute(parameter->getSafeName().c_str()));
            }
        }
        parameters.processRealtimeEvents();
        reset();
    }
}

AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new AroooAudioProcessor();
}
