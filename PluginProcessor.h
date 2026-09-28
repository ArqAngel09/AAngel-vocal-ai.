#pragma once
#include <JuceHeader.h>
class AngelVocalAIProcessor:public juce::AudioProcessor{
public:
 AngelVocalAIProcessor(); ~AngelVocalAIProcessor() override=default;
 void prepareToPlay(double,int) override; void releaseResources() override;
 bool isBusesLayoutSupported(const BusesLayout&)const override;
 void processBlock(juce::AudioBuffer<float>&,juce::MidiBuffer&)override;
 juce::AudioProcessorEditor* createEditor()override; bool hasEditor()const override{return true;}
 const juce::String getName()const override{return "Angel Vocal AI";} bool acceptsMidi()const override{return false;}
 bool producesMidi()const override{return false;} bool isMidiEffect()const override{return false;}
 double getTailLengthSeconds()const override{return 1.5;} int getNumPrograms()override{return 1;}
 int getCurrentProgram()override{return 0;} void setCurrentProgram(int)override{} const juce::String getProgramName(int)override{return {};}
 void changeProgramName(int,const juce::String&)override{} void getStateInformation(juce::MemoryBlock&)override;
 void setStateInformation(const void*,int)override; void startAnalysis(); bool analysisRunning()const{return analysing.load();}
 bool analysisReady()const{return analyzed.load();} float analysisProgress()const{return target>0?juce::jlimit(0.f,1.f,(float)samples/(float)target):0.f;}
private:
 juce::dsp::IIR::Filter<float> hp,presence,air,deesser; juce::dsp::Compressor<float> comp; juce::dsp::Gain<float> makeup;
 std::atomic<bool> analysing{false},analyzed{false}; juce::int64 samples=0,target=0; double sr=44100;
 float sumSq=0,peak=0,low=0,high=0,prev=0; juce::int64 count=0;
 float hpHz=70,presDb=2,airDb=1.5,threshold=-18,ratio=3,makeupDb=2,deEssDb=1.5,outDb=0;
 void applySettings(); JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AngelVocalAIProcessor)
};
