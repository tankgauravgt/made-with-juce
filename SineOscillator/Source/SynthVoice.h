/*
  ==============================================================================

    SynthVoice.h
    Created: 15 May 2020 5:51:02pm
    Author:  tankgauravgt

  ==============================================================================
*/

#pragma once
#include "SynthSound.h"
#include "SineOsc.h"

class SynthVoice : public SynthesiserVoice
{

public:

    SynthVoice();
    ~SynthVoice();

    bool canPlaySound(SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;

    void setCurrentPlaybackSampleRate(double newRate) override;

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples);

private:

    float level;
    float freq;

    ADSR adsr;

    SineOsc left;
    SineOsc right;
};
