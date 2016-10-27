/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_4920857A81D2C719__
#define __JUCE_HEADER_4920857A81D2C719__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
class XYZone;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PolySynthAudioProcessorEditor  : public AudioProcessorEditor,
                                       public Timer,
                                       public SliderListener
{
public:
    //==============================================================================
    PolySynthAudioProcessorEditor (PolySynthAudioProcessor& p);
    ~PolySynthAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void xyZoneChange(float xVal, float yVal);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void childrenChanged() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	void timerCallback() override;
    PolySynthAudioProcessor& processor;

	float matrixX = 0;
	float matrixY = 0;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> fmRatioSlider;
    ScopedPointer<Slider> fmIndexSlider;
    ScopedPointer<Slider> amIndexSlider;
    ScopedPointer<Slider> amRatioSlider;
    ScopedPointer<Slider> rmRatioSlider;
    ScopedPointer<Slider> attackSlider;
    ScopedPointer<Slider> decaySlider;
    ScopedPointer<Slider> sustainSlider;
    ScopedPointer<Slider> releaseSlider;
    ScopedPointer<Slider> volSlider;
    ScopedPointer<Slider> tremDepthSlider;
    ScopedPointer<Slider> tremFreqSlider;
    ScopedPointer<Slider> tremPhaseSlider;
    ScopedPointer<Slider> distDriveSlider;
    ScopedPointer<Slider> distGainSlider;
    ScopedPointer<XYZone> xyZone;
    Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PolySynthAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_4920857A81D2C719__
