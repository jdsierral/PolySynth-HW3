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

class Oscillator
{
public:
	
	Oscillator(float newGain, float newFreq);
	
	void setSampleRate (double newSampleRate);
	void setFreq (float newFreq);
	void setGain (float gainInDecibels);
	
	//Complexity is a nonlinear operation that causes distortion to add harmonic complexity
	void setComplexity (float comp);
	float tick();
	
	void clearAngle ();
	
	
private:
	
	// notice static Double so that it changes in all
	// of the instances of this class during application live
	
	const double PIx2 = M_PI * 2;
	static double sampleRate;
	
	// each oscillator is also responsible for its own gain
	
	float gain, freq;
	float angle, angleDelta;
	float comp;
	
	
};


#endif  // OSCILLATOR_H_INCLUDED
