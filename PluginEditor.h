#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
class AngelVocalAIEditor:public juce::AudioProcessorEditor,private juce::Timer{public:explicit AngelVocalAIEditor(AngelVocalAIProcessor&);void paint(juce::Graphics&)override;void resized()override;private:AngelVocalAIProcessor&p;juce::TextButton b{"ANALYZE 15 SEC"};juce::Label s;void timerCallback()override;JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AngelVocalAIEditor)};
