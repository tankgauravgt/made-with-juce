/*
  ==============================================================================

    SynthSound.h
    Created: 15 May 2020 5:50:48pm
    Author:  tankgauravgt

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public SynthesiserSound
{
public:
    
    bool appliesToNote(int) override;
    bool appliesToChannel(int) override;

private:



};