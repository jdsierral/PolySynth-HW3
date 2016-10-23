/*
  ==============================================================================

    Envelope.h
    Created: 22 Oct 2016 5:28:36pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef ENVELOPER_H_INCLUDED
#define ENVELOPER_H_INCLUDED

class Enveloper

{
	// states made to simulate asdr
	// in order to simulate the different states a different pole
	// is used on the same onePoleLPF
	
	enum state {
		off = 0,
		attack,
		decay,
		sustain,
		release
	};
	
public:
	
	// Different constructors are provided although we are using
	// the second on the initialization of this object on
	// the processors constructor
	
	Enveloper();
	Enveloper(float a, float d, float s, float r);
	~Enveloper();
	
	// required sampleRate to calculate poles based on realtime
	
	bool isOn();
	
	void setSampleRate(float newSampleRate);
	
	// sets attack time which sets its corresponding pole
	void setAttackTime(float newTime);
	void setDecayTime(float newTime);
	void setSustainLevel(float newLevel);
	void setReleaseTime(float newTime);
	
	// set Start and stop methods for calling enveloper activity
	
	void start();
	void stop();
	
	// get updates the level output. It doesnt require any input
	float tick();
	float get();
	bool isPlaying();
	
private:
	
	// notice how each state has its own pole
	
	state curState;
	
	bool noteOn;
	float level;
	float delay;
	float sampleRate;
	
	float attackTime;
	float attackPole;
	
	float decayTime;
	float decayPole;
	
	float sustainLevel;
	
	float releaseTime;
	float releasePole;
	
};



#endif  // ENVELOPER_H_INCLUDED
