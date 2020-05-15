/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor (GainPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    auto& params = processor.getParameters();
    auto* mGainParameter = (AudioParameterFloat*)params.getUnchecked(0);

    mGainControlSlider.setValue(*(AudioParameterFloat*)params.getUnchecked(0));

    addAndMakeVisible(mGainControlSlider);
    mGainControlSlider.setBounds((getWidth() / 2) - (50), (getHeight() / 2) - (50), 100, 100);
    mGainControlSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mGainControlSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 25);
    mGainControlSlider.setRange(0.0, 1.0, 0.01);
    
    mGainControlSlider.onDragStart = [mGainParameter]() {
        mGainParameter->beginChangeGesture();
    };

    mGainControlSlider.onValueChange = [this, mGainParameter]() {
        *mGainParameter = (float) mGainControlSlider.getValue();
    };
    
    mGainControlSlider.onDragEnd = [mGainParameter]() {
        mGainParameter->endChangeGesture();
    };

}

GainPluginAudioProcessorEditor::~GainPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainPluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void GainPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
