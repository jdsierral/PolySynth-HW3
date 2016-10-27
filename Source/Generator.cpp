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
	fmRatio.set(3.f);
	amRatio.set(2.f);
	rmRatio.set(2.f);
	fmIndex.set(10.f);
	amIndex.set(1.f);
	fmGain.set(1.f);
	amGain.set(0.f);
	rmGain.set(0.f);
	
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
	
	fmBaseFreq.set(newVal * fmRatio.get());
	fmMod->setFreq(fmBaseFreq.get());
	amMod->setFreq(newVal * amRatio.get());
	rmMod->setFreq(newVal * rmRatio.get());
}
void Generator::setFmIndex(float newVal){
	fmIndex.set(fmBaseFreq.get() * powf(2, newVal));
//	DBG("Actual FM Index: "<<fmIndex.get());
}
void Generator::setAmIndex(float newVal){
	amIndex.set(newVal);
//	DBG("Actual AM Index: "<<amIndex.get());
}
void Generator::setFmRatio(float newVal){
	fmRatio.set(newVal);
//	DBG("Actual FM Ratio: "<<fmRatio.get());
}
void Generator::setAmRatio(float newVal){
	amRatio.set(newVal);
//	DBG("Actual AM Ratio: "<<amRatio.get());
}
void Generator::setRmRatio(float newVal){
	rmRatio.set(newVal);
//	DBG("Actual RM Ratio: "<<rmRatio.get());
}

void Generator::setXWeight(float newVal){
	rmGain.set(sqrt(newVal));
	amGain.set(sqrt(1 - newVal));
//	DBG("AmGain: "<<amGain.get()<<" RmGain: "<<rmGain.get()<<" FmGain: "<<fmGain.get());
}
void Generator::setYWeight(float newVal){
	fmGain.set(1 - newVal);
}

float Generator::tick(){
	float amSample = amGain.tick() * amOsc->tick() * (1 + amIndex.tick() * amMod->tick());
	float rmSample = rmGain.tick() * rmOsc->tick() * rmMod->tick();
	fmOsc->setFreq(fmBaseFreq.tick() + fmIndex.tick() * fmMod->tick());
	float fmSample = fmGain.tick() * fmOsc->tick();
	return (fmSample + amSample + rmSample)/6 ;
}
