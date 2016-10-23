/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PolySynthAudioProcessorEditor::PolySynthAudioProcessorEditor (PolySynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	
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
	
	
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
    setSize (400, 300);
}

PolySynthAudioProcessorEditor::~PolySynthAudioProcessorEditor()
{
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
}

//==============================================================================
void PolySynthAudioProcessorEditor::paint (Graphics& g)
{
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
}

void PolySynthAudioProcessorEditor::resized()
{
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
}

void PolySynthAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
	if (slider == valWSlider)
	{
	}
	else if (slider == valNSlider)
	{
	}
	else if (slider == valESlider)
	{
	}
	else if (slider == attackSlider)
	{
	}
	else if (slider == interNSlider)
	{
	}
	else if (slider == interSSlider)
	{
	}
	else if (slider == interESlider)
	{
	}
	else if (slider == interWSlider)
	{
	}
	else if (slider == decaySlider)
	{
	}
	else if (slider == sustainSlider)
	{
	}
	else if (slider == releaseSlider)
	{
	}
	else if (slider == volSlider)
	{
	}
}

void PolySynthAudioProcessorEditor::comboBoxChanged (ComboBox* comboBox)
{
	if (comboBox == midiSelBox)
	{
	}
}


