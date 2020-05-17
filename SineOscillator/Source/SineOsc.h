/*
  ==============================================================================

    SineOscillator.h
    Created: 15 May 2020 3:49:56pm
    Author:  tankgauravgt

  ==============================================================================
*/

#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <cassert>
#include <iostream>

class SineOsc
{

public:

    SineOsc(unsigned int sr);
    ~SineOsc();

    void setSampleRate(unsigned int sr);
    void setPhase(float newPhase);

    float tick(float freq);

private:

    float current_phase;
    unsigned int samplerate;
    std::unique_ptr<float> wavetable;
};
