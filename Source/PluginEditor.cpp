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

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PolySynthAudioProcessorEditor::PolySynthAudioProcessorEditor (PolySynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (interWSlider = new Slider ("interWSlider"));
    interWSlider->setRange (0, 1, 0);
    interWSlider->setSliderStyle (Slider::LinearVertical);
    interWSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    interWSlider->addListener (this);

    addAndMakeVisible (interSSlider = new Slider ("interSSlider"));
    interSSlider->setRange (0, 1, 0);
    interSSlider->setSliderStyle (Slider::LinearHorizontal);
    interSSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    interSSlider->addListener (this);

    addAndMakeVisible (fmRatioSlider = new Slider ("FM Ratio Slider"));
    fmRatioSlider->setRange (0, 10, 0.1);
    fmRatioSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fmRatioSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    fmRatioSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    fmRatioSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    fmRatioSlider->addListener (this);

    addAndMakeVisible (fmIndexSlider = new Slider ("FM Index Slider"));
    fmIndexSlider->setRange (0, 10, 0);
    fmIndexSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fmIndexSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    fmIndexSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    fmIndexSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    fmIndexSlider->addListener (this);

    addAndMakeVisible (amIndexSlider = new Slider ("AM Index Slider"));
    amIndexSlider->setRange (0, 1, 0);
    amIndexSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amIndexSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    amIndexSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    amIndexSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    amIndexSlider->addListener (this);

    addAndMakeVisible (amRatioSlider = new Slider ("AM Rartio Slider"));
    amRatioSlider->setRange (0, 10, 0.1);
    amRatioSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amRatioSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    amRatioSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    amRatioSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    amRatioSlider->addListener (this);

    addAndMakeVisible (rmRatioSlider = new Slider ("RM Ratio Slider"));
    rmRatioSlider->setRange (0, 10, 0.1);
    rmRatioSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    rmRatioSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    rmRatioSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    rmRatioSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    rmRatioSlider->addListener (this);

    addAndMakeVisible (attackSlider = new Slider ("Attack Slider"));
    attackSlider->setRange (0, 150, 0);
    attackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    attackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    attackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    attackSlider->addListener (this);

    addAndMakeVisible (decaySlider = new Slider ("Decay Slider"));
    decaySlider->setRange (0, 150, 0);
    decaySlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    decaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    decaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    decaySlider->addListener (this);

    addAndMakeVisible (sustainSlider = new Slider ("Sustain Slider"));
    sustainSlider->setRange (-60, 0, 0);
    sustainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sustainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    sustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    sustainSlider->addListener (this);

    addAndMakeVisible (releaseSlider = new Slider ("Release Slider"));
    releaseSlider->setRange (0, 500, 0);
    releaseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    releaseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    releaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    releaseSlider->addListener (this);

    addAndMakeVisible (volSlider = new Slider ("volSlider"));
    volSlider->setRange (-60, 12, 0);
    volSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    volSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    volSlider->addListener (this);

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 1, 0);
    slider->setSliderStyle (Slider::LinearHorizontal);
    slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 1, 0);
    slider2->setSliderStyle (Slider::LinearHorizontal);
    slider2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (slider3 = new Slider ("new slider"));
    slider3->setRange (0, 1, 0);
    slider3->setSliderStyle (Slider::LinearHorizontal);
    slider3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider3->addListener (this);

    addAndMakeVisible (tremDepthSlider = new Slider ("Tremolo Depth Slider"));
    tremDepthSlider->setRange (0, 1, 0);
    tremDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    tremDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    tremDepthSlider->addListener (this);

    addAndMakeVisible (tremFreqSlider = new Slider ("Tremolo Frequency Slider"));
    tremFreqSlider->setRange (0, 20, 0);
    tremFreqSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    tremFreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    tremFreqSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PolySynthAudioProcessorEditor::~PolySynthAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    interWSlider = nullptr;
    interSSlider = nullptr;
    fmRatioSlider = nullptr;
    fmIndexSlider = nullptr;
    amIndexSlider = nullptr;
    amRatioSlider = nullptr;
    rmRatioSlider = nullptr;
    attackSlider = nullptr;
    decaySlider = nullptr;
    sustainSlider = nullptr;
    releaseSlider = nullptr;
    volSlider = nullptr;
    slider = nullptr;
    slider2 = nullptr;
    slider3 = nullptr;
    tremDepthSlider = nullptr;
    tremFreqSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PolySynthAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xff2aa596));
    g.fillPath (internalPath1);

    g.setColour (Colour (0xff9ba52a));
    g.fillRect (189, 110, 194, 194);

    g.setGradientFill (ColourGradient (Colour (0xff929292),
                                       310.0f, 213.0f,
                                       Colour (0xff353535),
                                       298.0f, 198.0f,
                                       true));
    g.fillEllipse (275.0f, 188.0f, 40.0f, 40.0f);

    g.setColour (Colours::black);
    g.setFont (Font (49.20f, Font::plain));
    g.drawText (TRANS("PolySynth"),
                25, 9, 221, 68,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("JuanSaudio"),
                154, 54, 89, 29,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("FM"),
                268, 24, 36, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("AM"),
                105, 186, 36, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("RingMod"),
                425, 190, 60, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Index"),
                87, 144, 49, 32,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Index"),
                315, 83, 49, 32,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Ratio"),
                87, 216, 49, 32,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Ratio"),
                207, 83, 49, 32,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Ratio"),
                429, 148, 49, 32,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..


//	g.setGradientFill (ColourGradient (Colour (0xff929292),
//									   310.0f, 213.0f,
//									   Colour (0xff353535),
//									   298.0f, 198.0f,
//									   true));
//	float x = 189 + matrixX * 194;
//	float y = 244 + matrixY * 194;
//	float w = 97;
//
//	g.fillEllipse (x, y, 40.f, 40.f);
    //[/UserPaint]
}

void PolySynthAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    interWSlider->setBounds (171, 101, 29, 208);
    interSSlider->setBounds (180, 295, 207, 24);
    fmRatioSlider->setBounds (244, 49, 39, 56);
    fmIndexSlider->setBounds (290, 49, 39, 56);
    amIndexSlider->setBounds (143, 151, 39, 56);
    amRatioSlider->setBounds (142, 210, 39, 56);
    rmRatioSlider->setBounds (389, 149, 39, 56);
    attackSlider->setBounds (225, 312, 29, 42);
    decaySlider->setBounds (259, 312, 29, 42);
    sustainSlider->setBounds (289, 313, 29, 42);
    releaseSlider->setBounds (322, 314, 29, 42);
    volSlider->setBounds (461, 291, 125, 103);
    slider->setBounds (432, 16, 150, 24);
    slider2->setBounds (432, 40, 150, 24);
    slider3->setBounds (432, 64, 150, 24);
    tremDepthSlider->setBounds (32, 312, 48, 56);
    tremFreqSlider->setBounds (96, 312, 48, 56);
    internalPath1.clear();
    internalPath1.startNewSubPath (288.0f, 24.0f);
    internalPath1.lineTo (467.0f, 202.0f);
    internalPath1.lineTo (288.0f, 384.0f);
    internalPath1.lineTo (104.0f, 200.0f);
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PolySynthAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == interWSlider)
    {
        //[UserSliderCode_interWSlider] -- add your slider handling code here..
//		matrixX = (interWSlider->getValue() + interESlider->getValue())/2;
//		*processor.xPos = matrixX;

		*processor.yPos = interWSlider->getValue();
        //[/UserSliderCode_interWSlider]
    }
    else if (sliderThatWasMoved == interSSlider)
    {
        //[UserSliderCode_interSSlider] -- add your slider handling code here..
//		matrixY = (interNSlider->getValue() + interSSlider->getValue())/2;
//		*processor.yPos = matrixY;
		*processor.xPos = interSSlider->getValue();
        //[/UserSliderCode_interSSlider]
    }
    else if (sliderThatWasMoved == fmRatioSlider)
    {
        //[UserSliderCode_fmRatioSlider] -- add your slider handling code here..
		*processor.fmRatio = fmRatioSlider->getValue();
        //[/UserSliderCode_fmRatioSlider]
    }
    else if (sliderThatWasMoved == fmIndexSlider)
    {
        //[UserSliderCode_fmIndexSlider] -- add your slider handling code here..
		*processor.fmIndex = fmIndexSlider->getValue();
        //[/UserSliderCode_fmIndexSlider]
    }
    else if (sliderThatWasMoved == amIndexSlider)
    {
        //[UserSliderCode_amIndexSlider] -- add your slider handling code here..
		*processor.amIndex = amIndexSlider->getValue();
        //[/UserSliderCode_amIndexSlider]
    }
    else if (sliderThatWasMoved == amRatioSlider)
    {
        //[UserSliderCode_amRatioSlider] -- add your slider handling code here..
		*processor.amRatio = amRatioSlider->getValue();
        //[/UserSliderCode_amRatioSlider]
    }
    else if (sliderThatWasMoved == rmRatioSlider)
    {
        //[UserSliderCode_rmRatioSlider] -- add your slider handling code here..
		*processor.rmRatio = rmRatioSlider->getValue();
        //[/UserSliderCode_rmRatioSlider]
    }
    else if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
		*processor.attack = attackSlider->getValue();
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == decaySlider)
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
		*processor.decay = decaySlider->getValue();
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == sustainSlider)
    {
        //[UserSliderCode_sustainSlider] -- add your slider handling code here..
		*processor.sustain = sustainSlider->getValue();
        //[/UserSliderCode_sustainSlider]
    }
    else if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
		*processor.release = releaseSlider->getValue();
        //[/UserSliderCode_releaseSlider]
    }
    else if (sliderThatWasMoved == volSlider)
    {
        //[UserSliderCode_volSlider] -- add your slider handling code here..
		*processor.vol = volSlider->getValue();
        //[/UserSliderCode_volSlider]
    }
    else if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
		for (int i = 0; i < 20; i++){
			processor.synthVoice[i]->getGenerator()->setAmGain(slider->getValue());
		}
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
		for (int i = 0; i < 20; i++){
			processor.synthVoice[i]->getGenerator()->setFmGain(slider2->getValue());
		}
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
		for (int i = 0; i < 20; i++){
			processor.synthVoice[i]->getGenerator()->setRmGain(slider3->getValue());
		}
        //[/UserSliderCode_slider3]
    }
    else if (sliderThatWasMoved == tremDepthSlider)
    {
        //[UserSliderCode_tremDepthSlider] -- add your slider handling code here..
		processor.tremolo.setDepth(tremDepthSlider->getValue());
        //[/UserSliderCode_tremDepthSlider]
    }
    else if (sliderThatWasMoved == tremFreqSlider)
    {
        //[UserSliderCode_tremFreqSlider] -- add your slider handling code here..
		processor.tremolo.setFreq(tremFreqSlider->getValue());
        //[/UserSliderCode_tremFreqSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PolySynthAudioProcessorEditor::timerCallback() {
	repaint();
	if(processor.getGUIFlag()){}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PolySynthAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="PolySynthAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <PATH pos="0 0 100 100" fill="solid: ff2aa596" hasStroke="0" nonZeroWinding="1">s 288 24 l 467 202 l 288 384 l 104 200 x</PATH>
    <RECT pos="189 110 194 194" fill="solid: ff9ba52a" hasStroke="0"/>
    <ELLIPSE pos="275 188 40 40" fill=" radial: 310 213, 298 198, 0=ff929292, 1=ff353535"
             hasStroke="0"/>
    <TEXT pos="25 9 221 68" fill="solid: ff000000" hasStroke="0" text="PolySynth"
          fontname="Default font" fontsize="49.200000000000002842" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="154 54 89 29" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="268 24 36 30" fill="solid: ff000000" hasStroke="0" text="FM"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="105 186 36 30" fill="solid: ff000000" hasStroke="0" text="AM"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="425 190 60 30" fill="solid: ff000000" hasStroke="0" text="RingMod"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="87 144 49 32" fill="solid: ff000000" hasStroke="0" text="Index"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="315 83 49 32" fill="solid: ff000000" hasStroke="0" text="Index"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="87 216 49 32" fill="solid: ff000000" hasStroke="0" text="Ratio"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="207 83 49 32" fill="solid: ff000000" hasStroke="0" text="Ratio"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="429 148 49 32" fill="solid: ff000000" hasStroke="0" text="Ratio"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="interWSlider" id="9f5e4de401e2d219" memberName="interWSlider"
          virtualName="" explicitFocusOrder="0" pos="171 101 29 208" min="0"
          max="1" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="interSSlider" id="ea0d1c28cb487d37" memberName="interSSlider"
          virtualName="" explicitFocusOrder="0" pos="180 295 207 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="FM Ratio Slider" id="98186883b7300eb0" memberName="fmRatioSlider"
          virtualName="" explicitFocusOrder="0" pos="244 49 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000000555"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="FM Index Slider" id="6c2821e02be2e615" memberName="fmIndexSlider"
          virtualName="" explicitFocusOrder="0" pos="290 49 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="AM Index Slider" id="f9b19e9d28bbf663" memberName="amIndexSlider"
          virtualName="" explicitFocusOrder="0" pos="143 151 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="1" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="AM Rartio Slider" id="c773ef2d3b92e5eb" memberName="amRatioSlider"
          virtualName="" explicitFocusOrder="0" pos="142 210 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000000555"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="RM Ratio Slider" id="bc8eb6df476c4dc2" memberName="rmRatioSlider"
          virtualName="" explicitFocusOrder="0" pos="389 149 39 56" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000000555"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Attack Slider" id="8064ba916d68a97" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="225 312 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="150" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Decay Slider" id="6238842593d6ca20" memberName="decaySlider"
          virtualName="" explicitFocusOrder="0" pos="259 312 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="150" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Sustain Slider" id="e11d7a640b170d54" memberName="sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="289 313 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="-60" max="0" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Release Slider" id="c0c0c7c384a8c4f6" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="322 314 29 42" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="500" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="volSlider" id="487e94bbc2b9cfb" memberName="volSlider"
          virtualName="" explicitFocusOrder="0" pos="461 291 125 103" min="-60"
          max="12" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="38b363b656ff15f6" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="432 16 150 24" min="0" max="1" int="0"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="54196f3eb7260ecc" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="432 40 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="4f02dbfe2ffc1a09" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="432 64 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Tremolo Depth Slider" id="2d314adf3f8202e5" memberName="tremDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="32 312 48 56" min="0"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Tremolo Frequency Slider" id="42bfc725f732a7a3" memberName="tremFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="96 312 48 56" min="0"
          max="20" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
