/*
  ==============================================================================

    SineOscillator.cpp
    Created: 15 May 2020 3:49:56pm
    Author:  tankgauravgt

  ==============================================================================
*/

#include "SineOsc.h"

SineOsc::SineOsc(unsigned int sr)
{
    // assert(sr > 0);
    samplerate = sr;
    wavetable.reset(new float[sr]);

    for(unsigned int i=0; i<sr; i++) {
        float phase = (float) (2 * M_PI * (float(i) / float(sr)));
        wavetable.get()[i] = (float) sin(float(phase));
    }

    current_phase = 0;
}

SineOsc::~SineOsc()
{

}

void SineOsc::setSampleRate(unsigned int sr)
{
    // assert(sr > 0);
    samplerate = sr;
    wavetable.reset(new float[sr]);

    for(unsigned int i=0; i<sr; i++) {
        float phase = float(2 * M_PI * (float(i) / float(sr)));
        wavetable.get()[i] = (float) sin(float(phase));
    }

    current_phase = 0.0f;
}

void SineOsc::setPhase(float newPhase)
{
    assert((newPhase < (2 * M_PI)) && (newPhase >= 0.0f));
    current_phase = float((samplerate * newPhase) / (2 * M_PI));
}

float SineOsc::tick(float freq)
{
    float out = wavetable.get()[int(current_phase)];
    (current_phase + freq) >= samplerate ? current_phase = (current_phase + freq) - samplerate : current_phase = (current_phase + freq);
    return out;
}
