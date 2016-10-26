/*
  ==============================================================================

    OnePoleLPF.h
    Created: 22 Oct 2016 11:12:34am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef ONEPOLELPF_H_INCLUDED
#define ONEPOLELPF_H_INCLUDED

class OnePoleLPF{
private:
	double delay,p;
	
public:
	OnePoleLPF():delay(0.0),p(0.0){}
	
	// set the smoothing (pole)
	void setPole(double newPole){
		p = newPole;
	}
	
	// compute one sample
	double tick(double input){
		double currentSample = input * (1.0-p);
		currentSample = currentSample + delay;
		delay = currentSample * p;
		return currentSample;
	}
};


class ValueFilter{
public:
	ValueFilter() : delay(0.0), p(0.99), value(0) {
	}
	
	ValueFilter(float newVal) : delay(0.0), p(0.99), value(newVal) {
	}
	
	// set the smoothing (pole)
	void setPole(double newPole){
		p = newPole;
	}
	
	void set(double newValue) {
		value = newValue;
	}
	
	// compute one sample
	double tick(){
		double currentSample = value * (1.0 - p);
		currentSample = currentSample + delay;
		delay = currentSample * p;
		return currentSample;
	}
	
	// gets current value without computing smoothing
	double get(){
		return value;
	}
	
private:
	double delay, p, value;
};




#endif  // ONEPOLELPF_H_INCLUDED
