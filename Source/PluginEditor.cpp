/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "XYZone.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

//[/MiscUserDefs]

//==============================================================================
PolySynthAudioProcessorEditor::PolySynthAudioProcessorEditor (PolySynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
	setLookAndFeel(&plugGUI);

    //[/Constructor_pre]

    addAndMakeVisible (fmRatioSlider = new Slider ("FM Ratio Slider"));
    fmRatioSlider->setRange (0, 10, 0.1);
    fmRatioSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fmRatioSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    fmRatioSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    fmRatioSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    fmRatioSlider->addListener (this);

    addAndMakeVisible (fmIndexSlider = new Slider ("FM Index Slider"));
    fmIndexSlider->setRange (0, 10, 0);
    fmIndexSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    fmIndexSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    fmIndexSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    fmIndexSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    fmIndexSlider->addListener (this);

    addAndMakeVisible (amIndexSlider = new Slider ("AM Index Slider"));
    amIndexSlider->setRange (0, 1, 0);
    amIndexSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amIndexSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    amIndexSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    amIndexSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    amIndexSlider->addListener (this);

    addAndMakeVisible (amRatioSlider = new Slider ("AM Rartio Slider"));
    amRatioSlider->setRange (0, 10, 0.1);
    amRatioSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    amRatioSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    amRatioSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    amRatioSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    amRatioSlider->addListener (this);

    addAndMakeVisible (rmRatioSlider = new Slider ("RM Ratio Slider"));
    rmRatioSlider->setRange (0, 10, 0.1);
    rmRatioSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    rmRatioSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
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
    volSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volSlider->addListener (this);

    addAndMakeVisible (tremDepthSlider = new Slider ("Tremolo Depth Slider"));
    tremDepthSlider->setRange (0, 1, 0);
    tremDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    tremDepthSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    tremDepthSlider->addListener (this);

    addAndMakeVisible (tremFreqSlider = new Slider ("Tremolo Frequency Slider"));
    tremFreqSlider->setRange (0, 20, 0);
    tremFreqSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    tremFreqSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    tremFreqSlider->addListener (this);

    addAndMakeVisible (tremPhaseSlider = new Slider ("Tremolo Phase Slider"));
    tremPhaseSlider->setRange (0, 180, 1);
    tremPhaseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    tremPhaseSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    tremPhaseSlider->addListener (this);

    addAndMakeVisible (distDriveSlider = new Slider ("Distortion Drive Slider"));
    distDriveSlider->setRange (-5, 5, 0);
    distDriveSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    distDriveSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    distDriveSlider->addListener (this);

    addAndMakeVisible (distGainSlider = new Slider ("Distortion Gain Slider"));
    distGainSlider->setRange (-60, 0, 0);
    distGainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    distGainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    distGainSlider->addListener (this);

    addAndMakeVisible (xyZone = new XYZone (*this));
    xyZone->setName ("XY Zone");

    addAndMakeVisible (distDriveLabel = new Label ("Distortion Drive Label",
                                                   TRANS("Drive")));
    distDriveLabel->setFont (Font (15.00f, Font::plain));
    distDriveLabel->setJustificationType (Justification::centred);
    distDriveLabel->setEditable (true, true, false);
    distDriveLabel->setColour (TextEditor::textColourId, Colours::black);
    distDriveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    distDriveLabel->addListener (this);

    addAndMakeVisible (volLabel = new Label ("Volume Label",
                                             TRANS("vol")));
    volLabel->setFont (Font (15.00f, Font::plain));
    volLabel->setJustificationType (Justification::centred);
    volLabel->setEditable (true, true, false);
    volLabel->setColour (TextEditor::textColourId, Colours::black);
    volLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    volLabel->addListener (this);

    addAndMakeVisible (distGainLabel = new Label ("Distortion Gain Label",
                                                  TRANS("Gain")));
    distGainLabel->setFont (Font (15.00f, Font::plain));
    distGainLabel->setJustificationType (Justification::centred);
    distGainLabel->setEditable (true, true, false);
    distGainLabel->setColour (TextEditor::textColourId, Colours::black);
    distGainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    distGainLabel->addListener (this);

    addAndMakeVisible (tremPhaseLabel = new Label ("Tremolo Phase Label",
                                                   CharPointer_UTF8 ("\xc3\xb8")));
    tremPhaseLabel->setFont (Font (15.00f, Font::plain));
    tremPhaseLabel->setJustificationType (Justification::centred);
    tremPhaseLabel->setEditable (true, true, false);
    tremPhaseLabel->setColour (TextEditor::textColourId, Colours::black);
    tremPhaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    tremPhaseLabel->addListener (this);

    addAndMakeVisible (tremFreqLabel = new Label ("Tremolo Frequency Label",
                                                  TRANS("Speed")));
    tremFreqLabel->setFont (Font (15.00f, Font::plain));
    tremFreqLabel->setJustificationType (Justification::centred);
    tremFreqLabel->setEditable (true, true, false);
    tremFreqLabel->setColour (TextEditor::textColourId, Colours::black);
    tremFreqLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    tremFreqLabel->addListener (this);

    addAndMakeVisible (tremDepthLabel = new Label ("Tremolo Depth Label",
                                                   TRANS("Depth")));
    tremDepthLabel->setFont (Font (15.00f, Font::plain));
    tremDepthLabel->setJustificationType (Justification::centred);
    tremDepthLabel->setEditable (true, true, false);
    tremDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    tremDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    tremDepthLabel->addListener (this);

    addAndMakeVisible (rmRatioLabel = new Label ("Rm Ratio Label",
                                                 TRANS("Ratio")));
    rmRatioLabel->setFont (Font (15.00f, Font::plain));
    rmRatioLabel->setJustificationType (Justification::centred);
    rmRatioLabel->setEditable (true, true, false);
    rmRatioLabel->setColour (TextEditor::textColourId, Colours::black);
    rmRatioLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    rmRatioLabel->addListener (this);

    addAndMakeVisible (amIndexLabel = new Label ("Am Index Label",
                                                 TRANS("Index")));
    amIndexLabel->setFont (Font (15.00f, Font::plain));
    amIndexLabel->setJustificationType (Justification::centred);
    amIndexLabel->setEditable (true, true, false);
    amIndexLabel->setColour (TextEditor::textColourId, Colours::black);
    amIndexLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    amIndexLabel->addListener (this);

    addAndMakeVisible (fmRatioLabel = new Label ("Fm Ratio Label",
                                                 TRANS("Ratio")));
    fmRatioLabel->setFont (Font (15.00f, Font::plain));
    fmRatioLabel->setJustificationType (Justification::centred);
    fmRatioLabel->setEditable (true, true, false);
    fmRatioLabel->setColour (TextEditor::textColourId, Colours::black);
    fmRatioLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    fmRatioLabel->addListener (this);

    addAndMakeVisible (fmIndexLabel = new Label ("Fm Index Label",
                                                 TRANS("Index")));
    fmIndexLabel->setFont (Font (15.00f, Font::plain));
    fmIndexLabel->setJustificationType (Justification::centred);
    fmIndexLabel->setEditable (true, true, false);
    fmIndexLabel->setColour (TextEditor::textColourId, Colours::black);
    fmIndexLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    fmIndexLabel->addListener (this);

    addAndMakeVisible (amRatioLabel = new Label ("Am Ratio Label",
                                                 TRANS("Ratio")));
    amRatioLabel->setFont (Font (15.00f, Font::plain));
    amRatioLabel->setJustificationType (Justification::centred);
    amRatioLabel->setEditable (true, true, false);
    amRatioLabel->setColour (TextEditor::textColourId, Colours::black);
    amRatioLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    amRatioLabel->addListener (this);


    //[UserPreSize]

    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
		startTimer(50);
    //[/Constructor]
}

PolySynthAudioProcessorEditor::~PolySynthAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

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
    tremDepthSlider = nullptr;
    tremFreqSlider = nullptr;
    tremPhaseSlider = nullptr;
    distDriveSlider = nullptr;
    distGainSlider = nullptr;
    xyZone = nullptr;
    distDriveLabel = nullptr;
    volLabel = nullptr;
    distGainLabel = nullptr;
    tremPhaseLabel = nullptr;
    tremFreqLabel = nullptr;
    tremDepthLabel = nullptr;
    rmRatioLabel = nullptr;
    amIndexLabel = nullptr;
    fmRatioLabel = nullptr;
    fmIndexLabel = nullptr;
    amRatioLabel = nullptr;


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
    g.drawText (TRANS("RM"),
                423, 188, 33, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("ADSR"),
                266, 343, 40, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PolySynthAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    fmRatioSlider->setBounds (244, 56, 39, 39);
    fmIndexSlider->setBounds (290, 56, 39, 39);
    amIndexSlider->setBounds (142, 154, 39, 39);
    amRatioSlider->setBounds (142, 206, 39, 38);
    rmRatioSlider->setBounds (385, 186, 39, 39);
    attackSlider->setBounds (225, 312, 29, 42);
    decaySlider->setBounds (259, 312, 29, 42);
    sustainSlider->setBounds (289, 313, 29, 42);
    releaseSlider->setBounds (322, 314, 29, 42);
    volSlider->setBounds (473, 290, 102, 102);
    tremDepthSlider->setBounds (64, 264, 48, 48);
    tremFreqSlider->setBounds (24, 328, 48, 49);
    tremPhaseSlider->setBounds (104, 328, 48, 48);
    distDriveSlider->setBounds (500, 223, 48, 48);
    distGainSlider->setBounds (396, 325, 48, 48);
    xyZone->setBounds (184, 105, 200, 200);
    distDriveLabel->setBounds (484, 265, 82, 12);
    volLabel->setBounds (510, 373, 28, 12);
    distGainLabel->setBounds (400, 366, 41, 12);
    tremPhaseLabel->setBounds (114, 369, 28, 12);
    tremFreqLabel->setBounds (28, 370, 39, 12);
    tremDepthLabel->setBounds (68, 307, 39, 12);
    rmRatioLabel->setBounds (387, 220, 35, 12);
    amIndexLabel->setBounds (144, 187, 36, 12);
    fmRatioLabel->setBounds (247, 87, 36, 12);
    fmIndexLabel->setBounds (292, 87, 36, 12);
    amRatioLabel->setBounds (146, 239, 35, 12);
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

    if (sliderThatWasMoved == fmRatioSlider)
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
    else if (sliderThatWasMoved == tremDepthSlider)
    {
        //[UserSliderCode_tremDepthSlider] -- add your slider handling code here..
		*processor.tremDepth = tremDepthSlider->getValue();
        //[/UserSliderCode_tremDepthSlider]
    }
    else if (sliderThatWasMoved == tremFreqSlider)
    {
        //[UserSliderCode_tremFreqSlider] -- add your slider handling code here..
		*processor.tremFreq = tremFreqSlider->getValue();
        //[/UserSliderCode_tremFreqSlider]
    }
    else if (sliderThatWasMoved == tremPhaseSlider)
    {
        //[UserSliderCode_tremPhaseSlider] -- add your slider handling code here..
		*processor.tremPhase = tremPhaseSlider->getValue();
        //[/UserSliderCode_tremPhaseSlider]
    }
    else if (sliderThatWasMoved == distDriveSlider)
    {
        //[UserSliderCode_distDriveSlider] -- add your slider handling code here..
		*processor.distDrive = distDriveSlider->getValue();
        //[/UserSliderCode_distDriveSlider]
    }
    else if (sliderThatWasMoved == distGainSlider)
    {
        //[UserSliderCode_distGainSlider] -- add your slider handling code here..
		*processor.distGain = distGainSlider->getValue();
        //[/UserSliderCode_distGainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PolySynthAudioProcessorEditor::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == distDriveLabel)
    {
        //[UserLabelCode_distDriveLabel] -- add your label text handling code here..
		distDriveSlider->setValue(distDriveLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_distDriveLabel]
    }
    else if (labelThatHasChanged == volLabel)
    {
        //[UserLabelCode_volLabel] -- add your label text handling code here..
		volSlider->setValue(volLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_volLabel]
    }
    else if (labelThatHasChanged == distGainLabel)
    {
        //[UserLabelCode_distGainLabel] -- add your label text handling code here..
		distGainSlider->setValue(distGainLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_distGainLabel]
    }
    else if (labelThatHasChanged == tremPhaseLabel)
    {
        //[UserLabelCode_tremPhaseLabel] -- add your label text handling code here..
		tremPhaseSlider->setValue(tremPhaseLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_tremPhaseLabel]
    }
    else if (labelThatHasChanged == tremFreqLabel)
    {
        //[UserLabelCode_tremFreqLabel] -- add your label text handling code here..
		tremFreqSlider->setValue(tremFreqLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_tremFreqLabel]
    }
    else if (labelThatHasChanged == tremDepthLabel)
    {
        //[UserLabelCode_tremDepthLabel] -- add your label text handling code here..
		tremDepthSlider->setValue(tremDepthLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_tremDepthLabel]
    }
    else if (labelThatHasChanged == rmRatioLabel)
    {
        //[UserLabelCode_rmRatioLabel] -- add your label text handling code here..
		rmRatioSlider->setValue(rmRatioLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_rmRatioLabel]
    }
    else if (labelThatHasChanged == amIndexLabel)
    {
        //[UserLabelCode_amIndexLabel] -- add your label text handling code here..
		amIndexSlider->setValue(amIndexLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_amIndexLabel]
    }
    else if (labelThatHasChanged == fmRatioLabel)
    {
        //[UserLabelCode_fmRatioLabel] -- add your label text handling code here..
		fmRatioSlider->setValue(fmRatioLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_fmRatioLabel]
    }
    else if (labelThatHasChanged == fmIndexLabel)
    {
        //[UserLabelCode_fmIndexLabel] -- add your label text handling code here..
		fmIndexSlider->setValue(fmIndexLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_fmIndexLabel]
    }
    else if (labelThatHasChanged == amRatioLabel)
    {
        //[UserLabelCode_amRatioLabel] -- add your label text handling code here..
		amRatioSlider->setValue(amRatioLabel->getText().getDoubleValue(), sendNotification);
        //[/UserLabelCode_amRatioLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void PolySynthAudioProcessorEditor::childrenChanged()
{
    //[UserCode_childrenChanged] -- Add your code here...
    //[/UserCode_childrenChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PolySynthAudioProcessorEditor::xyZoneChange(float xVal, float yVal) {
	*processor.xPos = (xVal - 10)/180.f;
	*processor.yPos = (yVal - 10)/180.f;
}

void PolySynthAudioProcessorEditor::timerCallback() {
	if(processor.getGUIFlag()){

		xyZone->setValues(*processor.xPos * 180.f + 10, *processor.yPos * 180.f + 10, dontSendNotification);

		fmRatioSlider->setValue(*processor.fmRatio, dontSendNotification);
		fmIndexSlider->setValue(*processor.fmIndex, dontSendNotification);
		amRatioSlider->setValue(*processor.amRatio, dontSendNotification);
		amIndexSlider->setValue(*processor.amIndex, dontSendNotification);
		rmRatioSlider->setValue(*processor.rmRatio, dontSendNotification);

		attackSlider->setValue(*processor.attack, dontSendNotification);
		decaySlider->setValue(*processor.decay, dontSendNotification);
		sustainSlider->setValue(*processor.sustain, dontSendNotification);
		releaseSlider->setValue(*processor.release, dontSendNotification);

		volSlider->setValue(*processor.vol, dontSendNotification);

		tremDepthSlider->setValue(*processor.tremDepth, dontSendNotification);
		tremFreqSlider->setValue(*processor.tremFreq, dontSendNotification);
		tremPhaseSlider->setValue(*processor.tremPhase, dontSendNotification);

		distDriveSlider->setValue(*processor.distDrive, dontSendNotification);
		distGainSlider->setValue(*processor.distGain, dontSendNotification);
	}
	if (!volLabel->isBeingEdited()) {
		if (volSlider->isMouseOverOrDragging() || volLabel->isMouseOver())
			volLabel->setText(Decibels::toString<float>(volSlider->getValue(), 1.f, -60.f), dontSendNotification);
		else
			volLabel->setText("Vol", dontSendNotification);
	}

	if (!distDriveLabel->isBeingEdited()) {
		if (distDriveSlider->isMouseOverOrDragging() || distDriveLabel->isMouseOver())
			distDriveLabel->setText((String)distDriveSlider->getValue(), dontSendNotification);
		else
			distDriveLabel->setText("Drive", dontSendNotification);
	}

	if (!distGainLabel->isBeingEdited()) {
		if (distGainSlider->isMouseOverOrDragging() || distGainLabel->isMouseOver())
			distGainLabel->setText((String)distGainSlider->getValue(), dontSendNotification);
		else
			distGainLabel->setText("Gain", dontSendNotification);
	}

	if (!tremPhaseLabel->isBeingEdited()) {
		if (tremPhaseSlider->isMouseOverOrDragging() || tremPhaseLabel->isMouseOver())
			tremPhaseLabel->setText((String)tremPhaseSlider->getValue(), dontSendNotification);
		else
			tremPhaseLabel->setText("Phase", dontSendNotification);
	}

	if (!tremFreqLabel->isBeingEdited()) {
		if (tremFreqSlider->isMouseOverOrDragging() || tremFreqLabel->isMouseOver())
			tremFreqLabel->setText((String)tremFreqSlider->getValue(), dontSendNotification);
		else
			tremFreqLabel->setText("Speed", dontSendNotification);
	}

	if (!tremDepthLabel->isBeingEdited()) {
		if (tremDepthSlider->isMouseOverOrDragging() || tremDepthLabel->isMouseOver())
			tremDepthLabel->setText((String)tremDepthSlider->getValue(), dontSendNotification);
		else
			tremDepthLabel->setText("Depth", dontSendNotification);
	}

	if (!rmRatioLabel->isBeingEdited()) {
		if (rmRatioSlider->isMouseOverOrDragging() || rmRatioLabel->isMouseOver())
			rmRatioLabel->setText((String)rmRatioSlider->getValue(), dontSendNotification);
		else
			rmRatioLabel->setText("Ratio", dontSendNotification);
	}

	if (!amIndexLabel->isBeingEdited()) {
		if (amIndexSlider->isMouseOverOrDragging() || amIndexLabel->isMouseOver())
			amIndexLabel->setText((String)amIndexSlider->getValue(), dontSendNotification);
		else
			amIndexLabel->setText("Index", dontSendNotification);
	}

	if (!fmRatioLabel->isBeingEdited()) {
		if (fmRatioSlider->isMouseOverOrDragging() || fmRatioLabel->isMouseOver())
			fmRatioLabel->setText((String)fmRatioSlider->getValue(), dontSendNotification);
		else
			fmRatioLabel->setText("Ratio", dontSendNotification);
	}

	if (!fmIndexLabel->isBeingEdited()) {
		if (fmIndexSlider->isMouseOverOrDragging() || fmIndexLabel->isMouseOver())
			fmIndexLabel->setText((String)fmIndexSlider->getValue(), dontSendNotification);
		else
			fmIndexLabel->setText("Index", dontSendNotification);
	}

	if (!amRatioLabel->isBeingEdited()) {
		if (amRatioSlider->isMouseOverOrDragging() || amRatioLabel->isMouseOver())
			amRatioLabel->setText((String)amRatioSlider->getValue(), dontSendNotification);
		else
			amRatioLabel->setText("Ratio", dontSendNotification);
	}
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
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="childrenChanged()"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff">
    <PATH pos="0 0 100 100" fill="solid: ff2aa596" hasStroke="0" nonZeroWinding="1">s 288 24 l 467 202 l 288 384 l 104 200 x</PATH>
    <TEXT pos="25 9 221 68" fill="solid: ff000000" hasStroke="0" text="PolySynth"
          fontname="Default font" fontsize="49.200000000000002842" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="154 54 89 29" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="268 24 36 30" fill="solid: ff000000" hasStroke="0" text="FM"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="105 186 36 30" fill="solid: ff000000" hasStroke="0" text="AM"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="423 188 33 30" fill="solid: ff000000" hasStroke="0" text="RM"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="266 343 40 30" fill="solid: ff000000" hasStroke="0" text="ADSR"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="FM Ratio Slider" id="98186883b7300eb0" memberName="fmRatioSlider"
          virtualName="" explicitFocusOrder="0" pos="244 56 39 39" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000000555"
          style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="FM Index Slider" id="6c2821e02be2e615" memberName="fmIndexSlider"
          virtualName="" explicitFocusOrder="0" pos="290 56 39 39" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="AM Index Slider" id="f9b19e9d28bbf663" memberName="amIndexSlider"
          virtualName="" explicitFocusOrder="0" pos="142 154 39 39" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="1" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="AM Rartio Slider" id="c773ef2d3b92e5eb" memberName="amRatioSlider"
          virtualName="" explicitFocusOrder="0" pos="142 206 39 38" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000000555"
          style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="RM Ratio Slider" id="bc8eb6df476c4dc2" memberName="rmRatioSlider"
          virtualName="" explicitFocusOrder="0" pos="385 186 39 39" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000000555"
          style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
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
          virtualName="" explicitFocusOrder="0" pos="473 290 102 102" min="-60"
          max="12" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Tremolo Depth Slider" id="2d314adf3f8202e5" memberName="tremDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="64 264 48 48" min="0"
          max="1" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Tremolo Frequency Slider" id="42bfc725f732a7a3" memberName="tremFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="24 328 48 49" min="0"
          max="20" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Tremolo Phase Slider" id="e7c3e361c80fee6a" memberName="tremPhaseSlider"
          virtualName="" explicitFocusOrder="0" pos="104 328 48 48" min="0"
          max="180" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Distortion Drive Slider" id="69d68112913a4fab" memberName="distDriveSlider"
          virtualName="" explicitFocusOrder="0" pos="500 223 48 48" min="-5"
          max="5" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Distortion Gain Slider" id="3ae04b2000770346" memberName="distGainSlider"
          virtualName="" explicitFocusOrder="0" pos="396 325 48 48" min="-60"
          max="0" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <GENERICCOMPONENT name="XY Zone" id="b9f0823d5bc0bf89" memberName="xyZone" virtualName=""
                    explicitFocusOrder="0" pos="184 105 200 200" class="XYZone" params="*this"/>
  <LABEL name="Distortion Drive Label" id="2e29fe9fd6db2f4a" memberName="distDriveLabel"
         virtualName="" explicitFocusOrder="0" pos="484 265 82 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Drive" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Volume Label" id="a37af896210db59f" memberName="volLabel"
         virtualName="" explicitFocusOrder="0" pos="510 373 28 12" edTextCol="ff000000"
         edBkgCol="0" labelText="vol" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Distortion Gain Label" id="15865652c3c7c4b8" memberName="distGainLabel"
         virtualName="" explicitFocusOrder="0" pos="400 366 41 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Tremolo Phase Label" id="f9e1644bb9deca8" memberName="tremPhaseLabel"
         virtualName="" explicitFocusOrder="0" pos="114 369 28 12" edTextCol="ff000000"
         edBkgCol="0" labelText="&#248;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Tremolo Frequency Label" id="36bf485d6a4e009a" memberName="tremFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="28 370 39 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Speed" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Tremolo Depth Label" id="5b77e9d9d3222b88" memberName="tremDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="68 307 39 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Rm Ratio Label" id="e438c3e7e5041413" memberName="rmRatioLabel"
         virtualName="" explicitFocusOrder="0" pos="387 220 35 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Ratio" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Am Index Label" id="f6c709d04516ae78" memberName="amIndexLabel"
         virtualName="" explicitFocusOrder="0" pos="144 187 36 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Index" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Fm Ratio Label" id="2a2ac7087a7853c1" memberName="fmRatioLabel"
         virtualName="" explicitFocusOrder="0" pos="247 87 36 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Ratio" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Fm Index Label" id="8c0b0c98c9a379ef" memberName="fmIndexLabel"
         virtualName="" explicitFocusOrder="0" pos="292 87 36 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Index" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Am Ratio Label" id="db27f1c7625deb0a" memberName="amRatioLabel"
         virtualName="" explicitFocusOrder="0" pos="146 239 35 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Ratio" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
