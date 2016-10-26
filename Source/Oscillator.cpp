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
: freq(newFreq), angle(0.0)
{
	gain = new ValueFilter(newGain);
	angleDelta = new ValueFilter();
}

Oscillator::~Oscillator() {
	gain = nullptr;
	angleDelta = nullptr;
}

void Oscillator::setSampleRate(double newSampleRate) {
	sampleRate = newSampleRate;
}

void Oscillator::setFreq(float newFreq) {
	const double cyclesPerSample = newFreq / sampleRate;
	angleDelta->set(cyclesPerSample * PIx2);
}

void Oscillator::setGainIndB (float gainInDecibels) {
	gain->set(Decibels::decibelsToGain<float>(gainInDecibels, -60));
}

void Oscillator::setGain(float newGain) {
	gain->set(newGain);
}

float Oscillator::tick(){
	float tempAng = angle;
	angle = tempAng + angleDelta->tick();
	if (angle > PIx2)	angle -= PIx2;
	return gain->tick() * std::sin(angle);;
}

float Oscillator::get(){
	return angle;
}

void Oscillator::clearAngle() {
	angle = 0;
}

void Oscillator::setAngleInDegrees(float newAngleInDegrees){
	angle = degreesToRadians(newAngleInDegrees);
}
