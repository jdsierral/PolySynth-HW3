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
#include "SynthSound.h"
#include "Oscillator.h"


struct SynthSound :				public SynthesiserSound
{
	SynthSound() {}
	
	bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
	bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};

class SynthVoice :				public SynthesiserVoice
{
public:
	SynthVoice();
	
	bool canPlaySound (SynthesiserSound* sound) override;
	
	void startNote (int midiNoteNumber, float velocity,
					SynthesiserSound*, int /*currentPitchWheelPosition*/) override;
	
	void stopNote (float /*velocity*/, bool allowTailOff) override;
	
	void pitchWheelMoved (int /*newValue*/) override;
	
	void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override;
	
	void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
	
private:
	ScopedPointer<Oscillator> osc;
	
	double level, freq;
	bool onOff, tailOff;
};



#endif  // SYNTHVOICE_H_INCLUDED
