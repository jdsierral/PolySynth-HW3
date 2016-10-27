/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "SynthVoice.h"
#include "PluginParams.h"
#include "OnePoleLPF.h"
#include "Tremolo.h"


//==============================================================================
/**
*/
class PolySynthAudioProcessor  : public AudioProcessor
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
	
	//==============================================================================
	//==============================================================================
	
	void setGUIFlag() {
		guiFlag = true;
	}
	
	void clearGUIFlag() {
		guiFlag = false;
	}
	
	bool getGUIFlag() {
		return guiFlag;
	}
	
	//==============================================================================
	//==============================================================================
	

	AudioParameterCustomFloat* fmIndex;
	AudioParameterCustomFloat* amIndex;
	AudioParameterCustomFloat* fmRatio;
	AudioParameterCustomFloat* amRatio;
	AudioParameterCustomFloat* rmRatio;
	AudioParameterCustomFloat* xPos;
	AudioParameterCustomFloat* yPos;
	AudioParameterCustomFloat* attack;
	AudioParameterCustomFloat* decay;
	AudioParameterCustomFloat* sustain;
	AudioParameterCustomFloat* release;
	AudioParameterCustomFloat* tremDepth;
	AudioParameterCustomFloat* tremFreq;
	AudioParameterCustomFloat* tremPhase;
	AudioParameterCustomFloat* distDrive;
	AudioParameterCustomFloat* distGain;
	AudioParameterCustomFloat* vol;
	
	
	SynthVoice* synthVoice[20];
private:
	Synthesiser synth;
	Tremolo tremolo;
	//==============================================================================
	//==============================================================================
	bool guiFlag;
	ValueFilter mainVol;
	const int numVoices = 20;
	
	//==============================================================================
	//==============================================================================
	
	

	
	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PolySynthAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
