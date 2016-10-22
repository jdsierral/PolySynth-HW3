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

#ifndef __JUCE_HEADER_B3C94D25B95B4EE6__
#define __JUCE_HEADER_B3C94D25B95B4EE6__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUIGuide  : public Component,
                  public SliderListener,
                  public ComboBoxListener
{
public:
    //==============================================================================
    GUIGuide ();
    ~GUIGuide();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> valWSlider;
    ScopedPointer<Slider> valNSlider;
    ScopedPointer<Slider> valESlider;
    ScopedPointer<Slider> attackSlider;
    ScopedPointer<Slider> interNSlider;
    ScopedPointer<Slider> interSSlider;
    ScopedPointer<Slider> interESlider;
    ScopedPointer<Slider> interWSlider;
    ScopedPointer<Slider> decaySlider;
    ScopedPointer<Slider> sustainSlider;
    ScopedPointer<Slider> releaseSlider;
    ScopedPointer<Slider> volSlider;
    ScopedPointer<ComboBox> midiSelBox;
    Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIGuide)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_B3C94D25B95B4EE6__
