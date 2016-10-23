/*
  ==============================================================================

    SynthVoice.cpp
    Created: 22 Oct 2016 11:11:59am
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "SynthVoice.h"


SynthVoice::SynthVoice():
level(0.0),
onOff (false),
tailOff(true)
{
	osc = new Oscillator(0, 0);
	env = new Enveloper(1, 10, -6, 200);
	osc->setSampleRate(getSampleRate());
	env->setSampleRate(getSampleRate());
};

SynthVoice::~SynthVoice(){
	osc = nullptr;
	env = nullptr;
}


bool SynthVoice::canPlaySound (SynthesiserSound* sound)
{
	return dynamic_cast<SynthSound*> (sound) != nullptr;
}

void SynthVoice::startNote (int midiNoteNumber, float velocity,
							SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
	osc->setFreq(MidiMessage::getMidiNoteInHertz(midiNoteNumber));
	osc->setGain(0);
	level = velocity;
	if (level > 0) env->start();
}

void SynthVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
	env->stop();
	tailOff = allowTailOff;
}

void SynthVoice::pitchWheelMoved (int /*newValue*/)
{
	// Pitch wheel is an important standard MIDI feature that should be implemented
}

void SynthVoice::controllerMoved (int /*controllerNumber*/, int /*newValue*/)
{
	// Thats where you would change the value of the modulator index and frequency
	// if you wanted to control them with MIDI controllers
}

void SynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	float* outL = outputBuffer.getWritePointer(0);
	float* outR = outputBuffer.getWritePointer(1);
	
	if (onOff) {
		for (int i = 0; i < numSamples; i++) {
			outL[i] = osc->tick() * level * env->tick();
			outR[i] = outL[i];
		}
	}
	
	if(!env->isOn() && !env->isPlaying()){
		clearCurrentNote();
	}
}
