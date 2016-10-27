/*
  ==============================================================================

    Generator.cpp
    Created: 24 Oct 2016 12:12:08pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "Generator.h"



Generator::Generator(int sampleRate)
{
	fmRatio.set(3);
	amRatio.set(2);
	rmRatio.set(2);
	fmIndex.set(10);
	amIndex.set(1);
	rmIndex.set(0.5);
	fmGain.set(1);
	amGain.set(1);
	rmGain.set(1);
	
	Oscillator::setSampleRate(sampleRate);
	fmOsc = new Oscillator(1, 0);
	amOsc = new Oscillator(1, 0);
	rmOsc = new Oscillator(1, 0);
	
	fmMod = new Oscillator(1, 0);
	amMod = new Oscillator(1, 0);
	rmMod = new Oscillator(1, 0);
}

Generator::~Generator() {
	fmOsc = nullptr;
	amOsc = nullptr;
	rmOsc = nullptr;
	fmMod = nullptr;
	amMod = nullptr;
	rmMod = nullptr;
}

void Generator::setPitch(float newVal){
	fmOsc->setFreq(newVal);
	amOsc->setFreq(newVal);
	rmOsc->setFreq(newVal);
	
	fmBaseFreq = newVal * fmRatio.get();
	fmMod->setFreq(fmBaseFreq.get());
	amMod->setFreq(newVal * amRatio.get());
	rmMod->setFreq(newVal * rmRatio.get());
}
void Generator::setFmIndex(float newVal){
	fmIndex.set(powf(2, newVal));
	DBG("Actual FM Index: "<<fmIndex.get());
}
void Generator::setAmIndex(float newVal){
	amIndex = newVal;
	DBG("Actual AM Index: "<<amIndex.get());
}
void Generator::setRmIndex(float newVal){
	rmIndex = newVal;
	DBG("Actual RM Index: "<<rmIndex.get());
}
void Generator::setFmRatio(float newVal){
	fmRatio = newVal;
	DBG("Actual FM Ratio: "<<fmRatio.get());
}
void Generator::setAmRatio(float newVal){
	amRatio = newVal;
	DBG("Actual AM Ratio: "<<amRatio.get());
}
void Generator::setRmRatio(float newVal){
	rmRatio = newVal;
	DBG("Actual RM Ratio: "<<rmRatio.get());
}

void Generator::setXWeight(float newVal){
	rmGain = sqrt(newVal);
	amGain = sqrt(1 - newVal);
}
void Generator::setYWeight(float newVal){
	fmGain = newVal;
}

void Generator::setFmGain(float newVal){
	fmGain = newVal;
	DBG("Actual FM Gain: "<<fmGain.get());
}
void Generator::setAmGain(float newVal){
	amGain = newVal;
	DBG("Actual AM Gain: "<<amGain.get());
}
void Generator::setRmGain(float newVal){
	rmGain = newVal;
	DBG("Actual RM Gain: "<<rmGain.get());
}

float Generator::tick(){
	float amSample = amGain.tick() * amOsc->tick() * (1 + amIndex.tick() * amMod->tick());
	float rmSample = rmGain.tick() * rmOsc->tick() * rmMod->tick();
	fmOsc->setFreq(fmBaseFreq.tick() + fmIndex.tick() * fmMod->tick());
	float fmSample = fmGain.tick() * fmOsc->tick();
	
	
	return (fmSample + amSample + rmSample)/6 ;
}
