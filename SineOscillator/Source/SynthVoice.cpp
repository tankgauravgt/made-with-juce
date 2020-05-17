/*
  ==============================================================================

    SynthVoice.cpp
    Created: 15 May 2020 5:51:02pm
    Author:  tankgauravgt

  ==============================================================================
*/

#include "SynthVoice.h"

SynthVoice::SynthVoice() : left(getSampleRate()), right(getSampleRate()), freq(0.00)
{
    adsr.setSampleRate(getSampleRate());
    adsr.setParameters({ 0.001f, 0.001, 1.0f, 0.05f });
}

SynthVoice::~SynthVoice()
{
}

bool SynthVoice::canPlaySound(SynthesiserSound* sound)
{
	return dynamic_cast<SynthSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
    left.setPhase(0.0f);
    right.setPhase(0.0f);

    freq = (float) MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    level = velocity / 6.0f;
    adsr.noteOn();
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    adsr.noteOff();
    allowTailOff = true;

    if (velocity == 0) {
        clearCurrentNote();
    }
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
}

void SynthVoice::setCurrentPlaybackSampleRate(double newRate)
{
    left.setSampleRate((unsigned int)newRate);
    right.setSampleRate((unsigned int)newRate);
}

void SynthVoice::renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    for (int sample = 0; sample < numSamples; sample++) 
    {
        outputBuffer.addSample(0, sample, level * adsr.getNextSample() * left.tick(freq));
        outputBuffer.addSample(1, sample, level * adsr.getNextSample() * right.tick(freq));
    }
}
