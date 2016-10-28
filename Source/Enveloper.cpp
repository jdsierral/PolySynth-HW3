/*
  ==============================================================================

    Envelope.cpp
    Created: 22 Oct 2016 5:28:36pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "Enveloper.h"
#include "../JuceLibraryCode/JuceHeader.h"


Enveloper::Enveloper(int sampleRate)
: curState(off), noteOn(false), level(0), delay(0)
{
	setAttackTime(2.0/1000.0);
	setDecayTime(2.0/1000.0);
	setSustainLevel(-6.0);
	setReleaseTime(70.0/1000.0);
}

Enveloper::Enveloper(float a, float d, float s, float r)
: curState(off), noteOn(false), level(0), delay(0)
{
	setAttackTime(a/1000);
	setDecayTime(d/1000);
	setSustainLevel(s);
	setReleaseTime(r/1000);
}

Enveloper::~Enveloper() {
}

double Enveloper::sampleRate = 0.0;

bool Enveloper::isOn() {
	return noteOn;
}

void Enveloper::setSampleRate(float newSampleRate) {
	sampleRate = newSampleRate;
}


void Enveloper::setAttackTime(float newTime){
	// setting pole taking care its corresponding time is no lower than 0.001
	
	attackTime = std::fmax(newTime, 0.001);
	attackPole = (exp(-1/(sampleRate * (attackTime))));
}

void Enveloper::setDecayTime(float newTime){
	// setting pole taking care its corresponding time is no lower than 0.001
	
	decayTime = std::fmax(newTime, 0.001);
	decayPole = (exp(-1/(sampleRate * (decayTime))));
}

void Enveloper::setSustainLevel(float newLevel){
	// sustain level is accessed via decibel value but transformed to gain
	
	sustainLevel = std::fmin(Decibels::decibelsToGain(newLevel), 1);
}

void Enveloper::setReleaseTime(float newTime){
	// setting pole taking care its corresponding time is no lower than 0.001
	
	releaseTime = std::fmax(newTime, 0.001);
	releasePole = (exp(-1/(sampleRate * (releaseTime))));
}

void Enveloper::start() {
	// start makes noteOn true and changes state to attack
	noteOn = true;
	curState = attack;
}

void Enveloper::stop() {
	// notice how this implementation allow for release state to be
	// accessed even though the attack hasnt ended
	
	noteOn = false;
	curState = release;
}

// compute one sample
float Enveloper::tick(){
	switch (curState) {
		case off:
			level = 0;
			break;
		case attack:
			// simplification of onePoleLPF as target is 1
			level = (1.0 - attackPole);
			level = level + delay;
			delay = level * attackPole;
			
			// comparisons in floats are tricky and onePoleLPF
			// doesnt actually get to a real 1 after many seconds
			
			if (level >= attackPole - 0.1) curState = decay;
			break;
		case decay:
			level = sustainLevel * (1.0 - decayPole);
			level = level + delay;
			delay = level * decayPole;
			
			// comparisons in floats are tricky and onePoleLPF
			// doesnt actually get to the real sustainLevel after many seconds
			
			if (level <= sustainLevel + 0.1) curState = sustain;
			
			break;
		case sustain:
			
			//just Wait on the same level for something to change
			level = sustainLevel * (1.0 - 0.99);
			level = level + delay;
			delay = level * decayPole;
			break;
		case release:
			
			// simplification of onePoleLPF as target is 0
			
			level = 0;
			level = delay;
			delay = level * releasePole;
			
			// comparisons in floats are tricky and onePoleLPF
			// doesnt actually get to a real 0 after many seconds
			// even though this jump might be heard, it will be smoothed
			// by the smoother in the processBlock of main application
			
			if (level < 0.0001) curState = off;
			break;
		default:
			break;
	}
	return level;
}

//returns the current value without computing a new one
float Enveloper::get() {
	return level;
}

//returns true if the envelope is not off
bool Enveloper::isPlaying() {
	if (curState == off) return false;
	else return true;
}
