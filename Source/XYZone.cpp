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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "XYZone.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
XYZone::XYZone (PolySynthAudioProcessorEditor& e)
    : editor(e)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

XYZone::~XYZone()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void XYZone::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff5e5e5e));

    g.setGradientFill (ColourGradient (Colour (0xff878787),
                                       4.0f, 2.0f,
                                       Colour (0xff636363),
                                       192.0f, 191.0f,
                                       false));
    g.fillRoundedRectangle (3.0f, 2.0f, 195.0f, 195.0f, 10.000f);

    //[UserPaint] Add your own custom painting code here..

    g.setGradientFill (ColourGradient (Colours::white,
                                       xPos - 7.f, yPos - 6.f,
                                       Colour (0xff979797),
                                       xPos + 10.f, yPos + 12.f,
                                       false));
	g.fillEllipse (xPos - radi, yPos - radi, 2 * radi, 2 * radi);
    //[/UserPaint]
}

void XYZone::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void XYZone::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
	if (e.position.x >= xPos - radi && e.position.x <= xPos + radi) {
		if (e.position.y >= yPos - radi && e.position.y <= yPos + radi) {
			cursorHit = true;
		}
	}
    //[/UserCode_mouseDown]
}

void XYZone::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
	if (cursorHit) {
		setValues(e.position.x, e.position.y, sendNotification);
	}
    //[/UserCode_mouseDrag]
}

void XYZone::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
	cursorHit = false;
    //[/UserCode_mouseUp]
}

void XYZone::mouseDoubleClick (const MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...
	DBG("MouseUp");
	setValues(e.position.x, e.position.y, sendNotification);
    //[/UserCode_mouseDoubleClick]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void XYZone::setValues(float newXPos, float newYPos, NotificationType n){
	xPos = jmax(jmin(newXPos, getWidth() - radi), radi);
	yPos = jmax(jmin(newYPos, getHeight()- radi), radi);
	if (n != dontSendNotification){
		editor.xyZoneChange(xPos, yPos);
	}
	repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="XYZone" componentName=""
                 parentClasses="public Component" constructorParams="PolySynthAudioProcessorEditor&amp; e"
                 variableInitialisers="editor(e)" snapPixels="8" snapActive="0"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="200"
                 initialHeight="200">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDoubleClick (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff5e5e5e">
    <ROUNDRECT pos="3 2 195 195" cornerSize="10" fill="linear: 4 2, 192 191, 0=ff878787, 1=ff636363"
               hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
