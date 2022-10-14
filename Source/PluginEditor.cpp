/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor (GainPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    mGainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(-60.0f ,0.0f,0.01f);
    mGainSlider.setValue(-20.0f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);
    setSize (200, 300);
}

GainPluginAudioProcessorEditor::~GainPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(Colours::black);
    g.setColour(Colours:: white);
    g.setFont(30.0f);
    g.drawFittedText("Happy Gain", getLocalBounds(), Justification::centredTop, 3);
    
}

void GainPluginAudioProcessorEditor::resized()
{
    mGainSlider.setBounds(getWidth() / 2 -50,getHeight()/ 2 -75 ,100 , 150);
}


void GainPluginAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    
    if(slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}
