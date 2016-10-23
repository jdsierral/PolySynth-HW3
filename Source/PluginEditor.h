/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class PolySynthAudioProcessorEditor  :  public AudioProcessorEditor,
										public SliderListener,
										public ComboBoxListener
{
public:
    PolySynthAudioProcessorEditor (PolySynthAudioProcessor&);
    ~PolySynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void sliderValueChanged (Slider* slider) override;
	void comboBoxChanged (ComboBox* comboBox) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
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
	
	PolySynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PolySynthAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
