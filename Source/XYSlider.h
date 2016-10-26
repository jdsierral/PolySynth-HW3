/*
  ==============================================================================

    XYSlider.h
    Created: 25 Oct 2016 9:53:07pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef XYSLIDER_H_INCLUDED
#define XYSLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class XYSlider    : public Component
{
public:
    XYSlider();
    ~XYSlider();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XYSlider)
};


#endif  // XYSLIDER_H_INCLUDED
