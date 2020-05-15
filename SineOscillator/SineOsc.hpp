#ifndef SINEOSC_HPP
#define SINEOSC_HPP

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

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

#endif
