/*
  ==============================================================================

    Oscillator.h
    Created: 22 Oct 2016 11:12:45am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "OnePoleLPF.h"

class Oscillator
{
public:
	
	Oscillator(float newGain, float newFreq);
	~Oscillator();
	
	static void setSampleRate (double newSampleRate);
	
	void setFreq (float newFreq);
	void setGainIndB (float gainInDecibels);
	void setGain (float newGain);
	
	void setAngleInDegrees(float newAngleInDegrees);
	void clearAngle();
	
	float get();
	float tick();
	
	
	
private:
	
	// notice static Double so that it changes in all
	// of the instances of this class during application live
	
	const double PIx2 = M_PI * 2;
	static double sampleRate;
	
	// each oscillator is also responsible for its own gain
	
	
	ScopedPointer<ValueFilter> gain;
	ScopedPointer<ValueFilter> angleDelta;
	float freq;
	float angle;
};


#endif  // OSCILLATOR_H_INCLUDED
