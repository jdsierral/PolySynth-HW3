/*
  ==============================================================================

    Distortion.h
    Created: 26 Oct 2016 12:00:10pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef DISTORTION_H_INCLUDED
#define DISTORTION_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "OnePoleLPF.h"

class Distortion
{
public:
	Distortion(){
		distAmount.set(0);
		gain.set(1);
	};
	~Distortion(){};
		
    void setAmount(float newValue){
        distAmount.set(newValue);
    }

    void setGain(float newValue){
		gain.set(Decibels::decibelsToGain(newValue, -60.f));
    }
    
    float getDistortion(){
		return distAmount.get();
    }
    
    float getGain(){
		return Decibels::gainToDecibels(gain.get());
    }
    
    float process(float data){
	    int sign = data/std::fabs(data);
	    return gain.tick() * sign * powf(fabs(data), powf(1.2, distAmount.tick()));
    }
private:
    ValueFilter distAmount;
    ValueFilter gain;
    
};



#endif  // DISTORTION_H_INCLUDED
