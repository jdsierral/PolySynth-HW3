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
	osc->setSampleRate(getSampleRate());
};

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
	if (level > 0) onOff = true;
}

void SynthVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
	onOff = false; // end the note
	level = 0; // ramp envelope to 0 if tail off is allowe
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
			outL[i] = osc->tick() * level;
			outR[i] = outL[i];
		}
	}
	
	if(!onOff && (!tailOff)){
		// check envelope level and clear it to 0 under certain threshold
		
		clearCurrentNote();
	}
}
