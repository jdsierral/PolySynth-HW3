/*
  ==============================================================================

    Generator.h
    Created: 24 Oct 2016 12:12:08pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "Oscillator.h"
#include "OnePoleLPF.h"

class Generator
{
public:
	Generator(int sampleRate);
	
	~Generator();
	
	void setPitch(float newVal);
	
	void setFmIndex(float newVal);
	void setAmIndex(float newVal);
	void setRmIndex(float newVal);
	void setFmRatio(float newVal);
	void setAmRatio(float newVal);
	void setRmRatio(float newVal);
	
	void setXWeight(float newVal);
	void setYWeight(float newVal);
	
	void setFmGain(float newVal);
	void setAmGain(float newVal);
	void setRmGain(float newVal);
	
	float tick();

private:
	
	ValueFilter fmRatio;
	ValueFilter amRatio;
	ValueFilter rmRatio;
	
	ValueFilter fmGain;
	ValueFilter amGain;
	ValueFilter rmGain;
	
	ValueFilter fmIndex;
	ValueFilter amIndex;
	ValueFilter rmIndex;
	
	
	ValueFilter fmBaseFreq;
	
	ScopedPointer<Oscillator>	fmOsc;
	ScopedPointer<Oscillator>   fmMod;
	ScopedPointer<Oscillator>	amOsc;
	ScopedPointer<Oscillator>	amMod;
	ScopedPointer<Oscillator>	rmOsc;
	ScopedPointer<Oscillator>   rmMod;
};



#endif  // GENERATOR_H_INCLUDED
