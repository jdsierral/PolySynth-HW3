/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
PolySynthAudioProcessor::PolySynthAudioProcessor()
{
	auto xPosCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getGenerator()->setXWeight(newValue);
		}
		setGUIFlag();
		DBG("XPos: "<<newValue);
	};
	auto yPosCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getGenerator()->setYWeight(newValue);
		}
		setGUIFlag();
		DBG("yPos: "<<newValue);
	};
	auto fmRatioCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getGenerator()->setFmRatio(newValue);
		}
		setGUIFlag();
		DBG("fmRatio: "<<newValue);
	};
	auto fmIndexCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getGenerator()->setFmIndex(newValue);
		}
		setGUIFlag();
		DBG("fmIndex: "<<newValue);
	};
	auto amRatioCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getGenerator()->setAmRatio(newValue);
		}
		setGUIFlag();
		DBG("amRatio: "<<newValue);
	};
	auto amIndexCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getGenerator()->setAmIndex(newValue);
		}
		setGUIFlag();
		DBG("amIndex: "<<newValue);
	};
	auto rmRatioCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getGenerator()->setRmRatio(newValue);
		}
		setGUIFlag();
		DBG("rmRatio: "<<newValue);
	};
	auto attackCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getEnveloper()->setAttackTime(newValue/1000.f);
		}
		setGUIFlag();
		DBG("Attak: "<<newValue);
	};
	auto decayCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getEnveloper()->setDecayTime(newValue/1000.f);
		}
		setGUIFlag();
		DBG("Deachy: "<<newValue);
	};
	auto sustainCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getEnveloper()->setSustainLevel(newValue);
		}
		setGUIFlag();
		DBG("Sust: "<<newValue);
	};
	auto releaseCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getEnveloper()->setReleaseTime(newValue/1000.f);
		}
		setGUIFlag();
		DBG("Rela: "<<newValue);
	};
	
	auto tremDepthCallback = [this] (float newValue) {
		tremolo.setDepth(newValue);
		DBG("Depth: "<<newValue);
	};
	
	auto tremFreqCallback = [this] (float newValue) {
		tremolo.setFreq(newValue);
		DBG("TFreq: "<<newValue);
	};

	auto tremPhaseCallback = [this] (float newValue) {
		tremolo.setPhaseDelta(newValue);
		setGUIFlag();
		DBG("phaseD: "<<newValue);
	};
	
	auto distDriveCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getDistortion()->setAmount(newValue);
		}
		DBG("DistDrive: "<<newValue);
		setGUIFlag();
	};
	auto distGainCallback = [this] (float newValue) {
		for(int i = 0; i < synth.getNumVoices(); i++) {
			synthVoice[i]->getDistortion()->setGain(newValue);
		}
		DBG("DistGain: " <<newValue);
	};
	
	auto volCallback = [this] (float newValue) {
		mainVol.set(Decibels::decibelsToGain(newValue));
		setGUIFlag();
		DBG("Vol: "<<newValue);
	};
	
	
	
	fmIndex = new AudioParameterCustomFloat
	("fmIndex", "FM Index", 0.f, 10.f, 0.f, fmIndexCallback);
	amIndex = new AudioParameterCustomFloat
	("amIndex", "AM Index", 0.f, 1.f, 0.f, amIndexCallback);
	
	fmRatio = new AudioParameterCustomFloat
	("fmRatio", "FM Ratio", 0.f, 10.f, 0.f, fmRatioCallback);
	amRatio = new AudioParameterCustomFloat
	("amRatio", "AM Ratio", 0.f, 10.f, 0.f, amRatioCallback);
	rmRatio = new AudioParameterCustomFloat
	("rmRatio", "RM Ratio", 0.f, 10.f, 0.f, rmRatioCallback);
	
	xPos = new AudioParameterCustomFloat
	("xPos", "X Pos", 0.f, 1.f, 0.f, xPosCallback);
	yPos = new AudioParameterCustomFloat
	("yPos", "Y Pos", 0.f, 1.f, 0.f, yPosCallback);
	
	attack = new AudioParameterCustomFloat
	("attack", "Attack", 0.f, 150.f, 10.f, attackCallback);
	decay = new AudioParameterCustomFloat
	("decay", "Decay", 0.f, 150.f, 10.f, decayCallback);
	sustain = new AudioParameterCustomFloat
	("sustain", "Sustain", -60.f, 0.f, -6.f, sustainCallback);
	release = new AudioParameterCustomFloat
	("release", "Release", 0.f, 500.f, 200.f, releaseCallback);
	
	tremDepth = new AudioParameterCustomFloat
	("tremDepth", "Tremolo Depth", 0.0, 1.0f, 0.f, tremDepthCallback);
	tremFreq = new AudioParameterCustomFloat
	("tremFreq", "Tremolo Frequency", 0.f, 20.f, 0.f, tremFreqCallback);
	tremPhase = new AudioParameterCustomFloat
	("phase", "Phase Delta", 0, 180, 0, tremPhaseCallback);
	
	distDrive = new AudioParameterCustomFloat
	("distDrive", "Distortion Drive", -5, 5, 0, distDriveCallback);
	distGain = new AudioParameterCustomFloat
	("distGain", "Distortion Gain", -60, 0, 0, distGainCallback);
	
	vol = new AudioParameterCustomFloat
	("vol", "Volume", -60, 12, -12, volCallback);
	
	
	addParameter(fmIndex);
	addParameter(amIndex);
	addParameter(fmRatio);
	addParameter(amRatio);
	addParameter(rmRatio);
	addParameter(xPos);
	addParameter(yPos);
	addParameter(attack);
	addParameter(decay);
	addParameter(sustain);
	addParameter(release);
	addParameter(tremDepth);
	addParameter(tremFreq);
	addParameter(tremPhase);
	addParameter(distDrive);
	addParameter(distGain);
	addParameter(vol);
	
	
	
	for (int i = numVoices; --i >= 0;) {
		synthVoice[i] = new SynthVoice();
		synth.addVoice(synthVoice[i]);
	}
	
	synth.clearSounds();
	synth.addSound (new SynthSound());
}

PolySynthAudioProcessor::~PolySynthAudioProcessor()
{
}

//==============================================================================
const String PolySynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PolySynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PolySynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double PolySynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PolySynthAudioProcessor::getNumPrograms()
{
    return 1;
}

int PolySynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PolySynthAudioProcessor::setCurrentProgram (int index)
{
}

const String PolySynthAudioProcessor::getProgramName (int index)
{
    return String();
}

void PolySynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PolySynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	synth.setCurrentPlaybackSampleRate (sampleRate);
	Oscillator::setSampleRate(sampleRate);
	Enveloper::setSampleRate(sampleRate);
}

void PolySynthAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PolySynthAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void PolySynthAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	int bufSize = buffer.getNumSamples();
	buffer.clear();
	synth.renderNextBlock(buffer, midiMessages, 0, bufSize);
	
	for(int chan = 0; chan < buffer.getNumChannels(); chan++) {
		float* data = buffer.getWritePointer(chan);
		for (int i = 0; i < bufSize; i++) {
			if (data[i] > 1.0f) DBG("Clip!!!");
			data[i] = data[i] * mainVol.tick() * (1 + tremolo.tick(chan));
		}
	}
}

//==============================================================================
//==============================================================================


//==============================================================================
//==============================================================================
bool PolySynthAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* PolySynthAudioProcessor::createEditor()
{
    return new PolySynthAudioProcessorEditor (*this);
}

//==============================================================================
void PolySynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PolySynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PolySynthAudioProcessor();
}
