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

#include "GUIGuide.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUIGuide::GUIGuide ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (valWSlider = new Slider ("valWSlider"));
    valWSlider->setRange (0, 10, 0);
    valWSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    valWSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    valWSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    valWSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    valWSlider->addListener (this);

    addAndMakeVisible (valNSlider = new Slider ("valWSlider"));
    valNSlider->setRange (0, 10, 0);
    valNSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    valNSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    valNSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    valNSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    valNSlider->addListener (this);

    addAndMakeVisible (valESlider = new Slider ("valESlider"));
    valESlider->setRange (0, 10, 0);
    valESlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    valESlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    valESlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    valESlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    valESlider->addListener (this);

    addAndMakeVisible (attackSlider = new Slider ("attackSlider"));
    attackSlider->setRange (0, 10, 0);
    attackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    attackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    attackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    attackSlider->addListener (this);

    addAndMakeVisible (interNSlider = new Slider ("interNSlider"));
    interNSlider->setRange (0, 10, 0);
    interNSlider->setSliderStyle (Slider::LinearHorizontal);
    interNSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    interNSlider->addListener (this);

    addAndMakeVisible (interSSlider = new Slider ("interSSlider"));
    interSSlider->setRange (0, 10, 0);
    interSSlider->setSliderStyle (Slider::LinearHorizontal);
    interSSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    interSSlider->addListener (this);

    addAndMakeVisible (interESlider = new Slider ("interESlider"));
    interESlider->setRange (0, 10, 0);
    interESlider->setSliderStyle (Slider::LinearVertical);
    interESlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    interESlider->addListener (this);

    addAndMakeVisible (interWSlider = new Slider ("interWSlider"));
    interWSlider->setRange (0, 10, 0);
    interWSlider->setSliderStyle (Slider::LinearVertical);
    interWSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    interWSlider->addListener (this);

    addAndMakeVisible (decaySlider = new Slider ("decaySlider"));
    decaySlider->setRange (0, 10, 0);
    decaySlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    decaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    decaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    decaySlider->addListener (this);

    addAndMakeVisible (sustainSlider = new Slider ("sustainSlider"));
    sustainSlider->setRange (0, 10, 0);
    sustainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sustainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    sustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    sustainSlider->addListener (this);

    addAndMakeVisible (releaseSlider = new Slider ("releaseSlider"));
    releaseSlider->setRange (0, 10, 0);
    releaseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    releaseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    releaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    releaseSlider->addListener (this);

    addAndMakeVisible (volSlider = new Slider ("volSlider"));
    volSlider->setRange (0, 10, 0);
    volSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    volSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    volSlider->addListener (this);

    addAndMakeVisible (midiSelBox = new ComboBox ("Midi Selector Box"));
    midiSelBox->setEditableText (false);
    midiSelBox->setJustificationType (Justification::centredLeft);
    midiSelBox->setTextWhenNothingSelected (String());
    midiSelBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiSelBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUIGuide::~GUIGuide()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    valWSlider = nullptr;
    valNSlider = nullptr;
    valESlider = nullptr;
    attackSlider = nullptr;
    interNSlider = nullptr;
    interSSlider = nullptr;
    interESlider = nullptr;
    interWSlider = nullptr;
    decaySlider = nullptr;
    sustainSlider = nullptr;
    releaseSlider = nullptr;
    volSlider = nullptr;
    midiSelBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUIGuide::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xff2aa596));
    g.fillPath (internalPath1);

    g.setColour (Colour (0xff9ba52a));
    g.fillRect (197, 110, 194, 194);

    g.setGradientFill (ColourGradient (Colour (0xff929292),
                                       310.0f, 213.0f,
                                       Colour (0xff353535),
                                       298.0f, 198.0f,
                                       true));
    g.fillEllipse (283.0f, 188.0f, 40.0f, 40.0f);

    g.setColour (Colours::black);
    g.setFont (Font (49.20f, Font::plain));
    g.drawText (TRANS("PolySynth"),
                33, 9, 221, 68,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("JuanSaudio"),
                162, 54, 89, 29,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("FM"),
                276, 24, 36, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("AM"),
                113, 186, 36, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("RingMod"),
                433, 190, 60, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUIGuide::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    valWSlider->setBounds (152, 176, 39, 56);
    valNSlider->setBounds (272, 48, 39, 56);
    valESlider->setBounds (400, 176, 39, 56);
    attackSlider->setBounds (233, 312, 29, 42);
    interNSlider->setBounds (191, 95, 207, 24);
    interSSlider->setBounds (188, 295, 207, 24);
    interESlider->setBounds (380, 103, 29, 208);
    interWSlider->setBounds (179, 101, 29, 208);
    decaySlider->setBounds (267, 312, 29, 42);
    sustainSlider->setBounds (297, 313, 29, 42);
    releaseSlider->setBounds (330, 314, 29, 42);
    volSlider->setBounds (469, 291, 125, 103);
    midiSelBox->setBounds (431, 19, 150, 24);
    internalPath1.clear();
    internalPath1.startNewSubPath (296.0f, 24.0f);
    internalPath1.lineTo (475.0f, 202.0f);
    internalPath1.lineTo (296.0f, 384.0f);
    internalPath1.lineTo (112.0f, 200.0f);
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUIGuide::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == valWSlider)
    {
        //[UserSliderCode_valWSlider] -- add your slider handling code here..
        //[/UserSliderCode_valWSlider]
    }
    else if (sliderThatWasMoved == valNSlider)
    {
        //[UserSliderCode_valNSlider] -- add your slider handling code here..
        //[/UserSliderCode_valNSlider]
    }
    else if (sliderThatWasMoved == valESlider)
    {
        //[UserSliderCode_valESlider] -- add your slider handling code here..
        //[/UserSliderCode_valESlider]
    }
    else if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == interNSlider)
    {
        //[UserSliderCode_interNSlider] -- add your slider handling code here..
        //[/UserSliderCode_interNSlider]
    }
    else if (sliderThatWasMoved == interSSlider)
    {
        //[UserSliderCode_interSSlider] -- add your slider handling code here..
        //[/UserSliderCode_interSSlider]
    }
    else if (sliderThatWasMoved == interESlider)
    {
        //[UserSliderCode_interESlider] -- add your slider handling code here..
        //[/UserSliderCode_interESlider]
    }
    else if (sliderThatWasMoved == interWSlider)
    {
        //[UserSliderCode_interWSlider] -- add your slider handling code here..
        //[/UserSliderCode_interWSlider]
    }
    else if (sliderThatWasMoved == decaySlider)
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == sustainSlider)
    {
        //[UserSliderCode_sustainSlider] -- add your slider handling code here..
        //[/UserSliderCode_sustainSlider]
    }
    else if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_releaseSlider]
    }
    else if (sliderThatWasMoved == volSlider)
    {
        //[UserSliderCode_volSlider] -- add your slider handling code here..
        //[/UserSliderCode_volSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUIGuide::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == midiSelBox)
    {
        //[UserComboBoxCode_midiSelBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiSelBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUIGuide" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <PATH pos="0 0 100 100" fill="solid: ff2aa596" hasStroke="0" nonZeroWinding="1">s 296 24 l 475 202 l 296 384 l 112 200 x</PATH>
    <RECT pos="197 110 194 194" fill="solid: ff9ba52a" hasStroke="0"/>
    <ELLIPSE pos="283 188 40 40" fill=" radial: 310 213, 298 198, 0=ff929292, 1=ff353535"
             hasStroke="0"/>
    <TEXT pos="33 9 221 68" fill="solid: ff000000" hasStroke="0" text="PolySynth"
          fontname="Default font" fontsize="49.200000000000002842" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="162 54 89 29" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="276 24 36 30" fill="solid: ff000000" hasStroke="0" text="FM"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="113 186 36 30" fill="solid: ff000000" hasStroke="0" text="AM"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="433 190 60 30" fill="solid: ff000000" hasStroke="0" text="RingMod"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="valWSlider" id="f9b19e9d28bbf663" memberName="valWSlider"
          virtualName="" explicitFocusOrder="0" pos="152 176 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="valWSlider" id="133dec8e0074a1ab" memberName="valNSlider"
          virtualName="" explicitFocusOrder="0" pos="272 48 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="valESlider" id="eb09575c8b3f3e8b" memberName="valESlider"
          virtualName="" explicitFocusOrder="0" pos="400 176 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="attackSlider" id="8064ba916d68a97" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="233 312 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="interNSlider" id="9609df0478b21ffa" memberName="interNSlider"
          virtualName="" explicitFocusOrder="0" pos="191 95 207 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="interSSlider" id="ea0d1c28cb487d37" memberName="interSSlider"
          virtualName="" explicitFocusOrder="0" pos="188 295 207 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="interESlider" id="9ea3f2372d8ef8dc" memberName="interESlider"
          virtualName="" explicitFocusOrder="0" pos="380 103 29 208" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="interWSlider" id="9f5e4de401e2d219" memberName="interWSlider"
          virtualName="" explicitFocusOrder="0" pos="179 101 29 208" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="decaySlider" id="6238842593d6ca20" memberName="decaySlider"
          virtualName="" explicitFocusOrder="0" pos="267 312 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="sustainSlider" id="e11d7a640b170d54" memberName="sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="297 313 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="releaseSlider" id="c0c0c7c384a8c4f6" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="330 314 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="volSlider" id="487e94bbc2b9cfb" memberName="volSlider"
          virtualName="" explicitFocusOrder="0" pos="469 291 125 103" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <COMBOBOX name="Midi Selector Box" id="92c8e8d5e0c9bf7" memberName="midiSelBox"
            virtualName="" explicitFocusOrder="0" pos="431 19 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
