/*
  ==============================================================================

    Tremolo.h
    Created: 25 Oct 2016 9:52:03pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef TREMOLO_H_INCLUDED
#define TREMOLO_H_INCLUDED

#include "OnePoleLPF.h"
#include "Oscillator.h"


class Tremolo {
	
public:
	Tremolo();
	Tremolo(float sampleRate);
	~Tremolo();
	
	
	void setFreq(float newValue);
	void setDepth(float newValue);
	void setPhaseDelta(float newValue);
	
	float get(int channel);
	
	float tick(int channel);

private:
	float sampleRate;
	
	ScopedPointer<Oscillator> oscL;
	ScopedPointer<Oscillator> oscR;
	ValueFilter freq;
	ValueFilter Depth;
	float phase;
};



#endif  // TREMOLO_H_INCLUDED
