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

#ifndef __JUCE_HEADER_3582E52E256AD4DA__
#define __JUCE_HEADER_3582E52E256AD4DA__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginEditor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class XYZone  : public Component
{
public:
    //==============================================================================
    XYZone (PolySynthAudioProcessorEditor& e);
    ~XYZone();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void setPos(float newPosX, float newPosY);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent& e) override;
    void mouseDoubleClick (const MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	float posX;
	float posY;
	float radi = 10;
	bool cursorHit;

	PolySynthAudioProcessorEditor& editor;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XYZone)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3582E52E256AD4DA__
