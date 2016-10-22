/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthVoice.h"


//==============================================================================
/**
*/
class PolySynthAudioProcessor  : public AudioProcessor,
								 public MidiInputCallback
{
public:
    //==============================================================================
    PolySynthAudioProcessor();
    ~PolySynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
	
	// this collects real-time midi messages from the midi input device, and
	// turns them into blocks that we can process in our audio callback
	MidiMessageCollector midiCollector;
	
	// this represents the state of which keys on our on-screen keyboard are held
	// down. When the mouse is clicked on the keyboard component, this object also
	// generates midi messages for this, which we can pass on to our synth.
//	MidiKeyboardState& keyboardState;
	
	// the synth itself!
	Synthesiser synth;
	
	AudioDeviceManager		audioDeviceManager;
	MidiKeyboardState		keyboardState;
	ScopedPointer<MidiKeyboardComponent>	keyboardComponent;
	AudioSourcePlayer		audioSourcePlayer;
//	SynthAudioSource		synthAudioSource;
	
	int lastMidiInputIndex;
	
	void setMidiInput (int index) {
		const StringArray list (MidiInput::getDevices());
		
		audioDeviceManager.removeMidiInputCallback (list[lastMidiInputIndex], this);
		
		const String newInput (list[index]);
		
		if (!audioDeviceManager.isMidiInputEnabled (newInput))
			audioDeviceManager.setMidiInputEnabled (newInput, true);
		
		audioDeviceManager.addMidiInputCallback (newInput, this);
//		midiInputList.setSelectedId (index + 1, dontSendNotification);
		
		lastMidiInputIndex = index;
	}
	
	// Needed virtual function
	void handleIncomingMidiMessage (MidiInput*, const MidiMessage& message) override {}
	
	
	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PolySynthAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
