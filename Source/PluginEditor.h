/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
using namespace juce;
//==============================================================================
/**
*/
class GainPluginAudioProcessorEditor  : public juce::AudioProcessorEditor, public Slider::Listener
{
public:
    GainPluginAudioProcessorEditor (GainPluginAudioProcessor&);
    ~GainPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;
   

private:
 
    Slider mGainSlider;
    
    GainPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainPluginAudioProcessorEditor)
};
