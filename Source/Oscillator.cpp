/*
  ==============================================================================

    Oscillator.cpp
    Created: 22 Oct 2016 11:12:45am
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "Oscillator.h"

double Oscillator::sampleRate = 0.0;

Oscillator::Oscillator(float newGain, float newFreq)
: gain (newGain), freq(newFreq), angle(0.0), angleDelta(0.0)
{
}

void Oscillator::setSampleRate(double newSampleRate) {
	sampleRate = newSampleRate;
	setFreq(freq);
}

void Oscillator::setFreq(float newFreq) {
	const double cyclesPerSample = newFreq / sampleRate;
	angleDelta = cyclesPerSample * PIx2;
}

void Oscillator::setGain(float gainInDecibels) {
	gain = Decibels::decibelsToGain<float>(gainInDecibels, -60);
}

void Oscillator::setComplexity(float newComp) {
	comp = newComp;
}

float Oscillator::tick(){
	
	// Notice calculations through potential functions to generate distortio or harmonic complexity.
	// having a positive value for complexity gives a narrower pulse like signal
	// having a negative value gives a broader one similar to a square wave
	float tempAng = angle;
	angle = (tempAng + angleDelta > PIx2 ? tempAng + angleDelta - PIx2 : tempAng + angleDelta);
	float sine = std::sin(angle);
	int sign = sine/std::fabs(sine);
	return gain * sign * powf(fabs(sine), powf(1.2, comp));
}

void Oscillator::clearAngle() {
	angle = 0;
}
