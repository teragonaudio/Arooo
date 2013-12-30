#ifndef __PLUGINPROCESSOR_H_A4C75B3B__
#define __PLUGINPROCESSOR_H_A4C75B3B__

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginEditor.h"
#include "PluginParameters.h"
#include "Resources.h"
#include "FFTWrapper.h"
#include "FrequencyAnalyzer.h"
#include "EventDetector.h"
#include "MidiResponder.h"

using namespace teragon;

class AroooAudioProcessor : public AudioProcessor, public ParameterObserver {
public:
    AroooAudioProcessor();
    ~AroooAudioProcessor() {}

    // Playback
    void prepareToPlay(double sampleRate, int samplesPerBlock);
    void processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    void releaseResources();
    void reset();

    // Editor
    AudioProcessorEditor *createEditor() { return new PluginEditor(this, parameters, Resources::getCache()); }
    bool hasEditor() const { return true; };

    // Parameter methods
    int getNumParameters() { return parameters.size(); }
    float getParameter(int index) { return (float)parameters[index]->getScaledValue(); }
    void setParameter(int index, float newValue) { parameters.setScaled(index, newValue); }
    const String getParameterName(int index) { return parameters[index]->getName().c_str(); }
    const String getParameterText(int index) { return parameters[index]->getDisplayText().c_str(); }

    // Plugin properties and basic information
    const String getName() const { return JucePlugin_Name; }
    const String getInputChannelName(int channelIndex) const { return String(channelIndex + 1); };
    const String getOutputChannelName(int channelIndex) const { return String(channelIndex + 1); };
    bool isInputChannelStereoPair(int index) const { return true; };
    bool isOutputChannelStereoPair(int index) const { return true; };
    bool acceptsMidi() const { return false; };
    bool producesMidi() const { return false; };
    bool silenceInProducesSilenceOut() const { return true; }
    double getTailLengthSeconds() const { return 0.0; }

    // Program support (not needed by this plugin)
    int getNumPrograms() { return 0; };
    int getCurrentProgram() { return 0; };
    void setCurrentProgram(int index) {};
    const String getProgramName(int index) { return String::empty; };
    void changeProgramName(int index, const String& newName) {};

    // State save/restore
    void getStateInformation(MemoryBlock& destData);
    void setStateInformation(const void *data, int sizeInBytes);

    // ParameterObserver methods
    bool isRealtimePriority() const { return true; }
    void onParameterUpdated(const Parameter *parameter);

private:
    // ParameterSet and cached parameters
    ConcurrentParameterSet parameters;
    VoidParameter *eventDetected;

    FFTWrapper fftWrapper;
    FrequencyAnalyzer frequencyAnalyzer;
    EventDetector eventDetector;
    float *fftData;

    // Output responders
    MidiResponder midiResponder;
    bool sendMidi;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AroooAudioProcessor);
};

#endif  // __PLUGINPROCESSOR_H_A4C75B3B__
