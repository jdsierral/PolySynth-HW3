/*
  ==============================================================================

    Tremolo.cpp
    Created: 25 Oct 2016 9:52:03pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "Tremolo.h"


Tremolo::Tremolo(){
	oscL = new Oscillator(1,1);
	oscR = new Oscillator(1,1);
}

Tremolo::~Tremolo(){
	oscL = nullptr;
	oscR = nullptr;
}


void Tremolo::setFreq(float newValue){
	oscL->setFreq(newValue);
	oscR->setFreq(newValue);
	DBG("TremFreq: "<<newValue);
}
void Tremolo::setDepth(float newValue){
	oscL->setGain(newValue);
	oscR->setGain(newValue);
	DBG("TremDepth: "<<newValue);
}

void Tremolo::setPhaseDelta(float newValue) {
	oscL->clearAngle();
	oscR->clearAngle();
	oscR->setAngleInDegrees(newValue);
	DBG("TremPhase: "<<newValue);
	
}


float Tremolo::get(int channel){
	if (channel == 0)
		return oscL->get();
	else if (channel == 1)
		return oscR->get();
	else
		return 0;
	
}

float Tremolo::tick(int channel){
	if (channel == 0)
		return oscL->tick();
	else if (channel == 1)
		return oscR->tick();
	else
		return 0;
}
