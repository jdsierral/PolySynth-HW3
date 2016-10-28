/*
  ==============================================================================

    SynthVoice.cpp
    Created: 22 Oct 2016 11:11:59am
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "SynthVoice.h"


SynthVoice::SynthVoice():
tailOff(true)
{
	gen = new Generator(getSampleRate());
	env = new Enveloper(getSampleRate());
};

SynthVoice::~SynthVoice(){
	gen = nullptr;
	env = nullptr;
}


bool SynthVoice::canPlaySound (SynthesiserSound* sound) {
	return dynamic_cast<SynthSound*> (sound) != nullptr;
}

void SynthVoice::startNote (int midiNoteNumber, float velocity,
							SynthesiserSound*, int /*currentPitchWheelPosition*/) {
	level = velocity;
	gen->setPitch(MidiMessage::getMidiNoteInHertz(midiNoteNumber));
	DBG("MidiNote: "<<midiNoteNumber);
	if (velocity > 0) env->start();
//	DBG("Velocity: "<<velocity);
}

void SynthVoice::stopNote (float /*velocity*/, bool allowTailOff) {
	env->stop();
	tailOff = allowTailOff;
}

void SynthVoice::pitchWheelMoved (int /*newValue*/) {
}

void SynthVoice::controllerMoved (int ccNum, int ccVal) {
}

void SynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) {
	if(env->isPlaying() || env->isOn()){
		while (--numSamples >= 0){
			float out = (float)gen->tick();
			
			out = dist.process(out);
			out = out * env->tick() * level;
			for (int i = outputBuffer.getNumChannels(); --i >= 0;)
			{
				outputBuffer.addSample (i, startSample, out);
			}
			++startSample;
			if(!env->isOn() && (!env->isPlaying() || !tailOff)){
				clearCurrentNote();
			}
		}
	}
}
