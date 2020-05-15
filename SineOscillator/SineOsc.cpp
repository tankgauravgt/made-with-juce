#include "SineOsc.hpp"

SineOsc::SineOsc(unsigned int sr)
{
    samplerate = sr;
    wavetable.reset(new float[sr]);

    for(int i=0; i<sr; i++) {
        float phase = 2 * M_PI * (float(i) / float(sr));
        wavetable.get()[i] = (float) sin(float(phase));
    }

    current_phase = 0;
}

SineOsc::~SineOsc()
{

}

void SineOsc::setSampleRate(unsigned int sr)
{
    samplerate = sr;
    wavetable.reset(new float[sr]);

    for(int i=0; i<sr; i++) {
        float phase = 2 * M_PI * (float(i) / float(sr));
        wavetable.get()[i] = (float) sin(float(phase));
    }

    current_phase = 0.0f;
}

void SineOsc::setPhase(float newPhase)
{
    assert((newPhase < (2 * M_PI)) && (newPhase >= 0.0f));
    current_phase = (2 * M_PI * ((samplerate * newPhase) / (2 * M_PI)));
}

float SineOsc::tick(float freq)
{
    float out = wavetable.get()[int(current_phase)];
    (current_phase + freq) >= samplerate ? current_phase = (current_phase + freq) - samplerate : current_phase = (current_phase + freq);
    return out;
}
