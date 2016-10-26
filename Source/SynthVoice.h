/*
  ==============================================================================

    SynthVoice.h
    Created: 22 Oct 2016 11:11:59am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SYNTHVOICE_H_INCLUDED
#define SYNTHVOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Enveloper.h"
#include "Generator.h"


struct SynthSound :				public SynthesiserSound
{
	SynthSound() {}
	
	bool appliesToNote (int /*midiNoteNumber*/) override { return true; }
	bool appliesToChannel (int /*midiChannel*/) override { return true; }
};

class SynthVoice :				public SynthesiserVoice
{
public:
	SynthVoice();
	~SynthVoice();
	
	bool canPlaySound (SynthesiserSound* sound) override;
	
	void startNote (int midiNoteNumber, float velocity,
					SynthesiserSound*, int /*currentPitchWheelPosition*/) override;
	
	void stopNote (float /*velocity*/, bool allowTailOff) override;
	
	void pitchWheelMoved (int /*newValue*/) override;
	
	void controllerMoved (int ccNum, int ccVal) override;
	
	void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
	
	Generator* getGenerator () {
		return gen;
	}
	
	Enveloper* getEnveloper () {
		return env;
	}
	
private:
	ScopedPointer<Generator>	gen;
	ScopedPointer<Enveloper>	env;
	
	bool tailOff;
	float level;
};



#endif  // SYNTHVOICE_H_INCLUDED
