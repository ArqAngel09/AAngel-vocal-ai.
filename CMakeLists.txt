cmake_minimum_required(VERSION 3.22)
project(AngelVocalAI VERSION 1.0.0)
include(FetchContent)
FetchContent_Declare(juce GIT_REPOSITORY https://github.com/juce-framework/JUCE.git GIT_TAG 8.0.8 GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(juce)
juce_add_plugin(AngelVocalAI
 COMPANY_NAME "Angel Ortiz" PLUGIN_MANUFACTURER_CODE Angl PLUGIN_CODE Avai
 FORMATS VST3 PRODUCT_NAME "Angel Vocal AI" IS_SYNTH FALSE NEEDS_MIDI_INPUT FALSE
 NEEDS_MIDI_OUTPUT FALSE IS_MIDI_EFFECT FALSE COPY_PLUGIN_AFTER_BUILD TRUE
 VST3_CATEGORIES "Fx" "Dynamics")
target_sources(AngelVocalAI PRIVATE src/PluginProcessor.cpp src/PluginProcessor.h src/PluginEditor.cpp src/PluginEditor.h)
target_compile_features(AngelVocalAI PRIVATE cxx_std_17)
target_link_libraries(AngelVocalAI PRIVATE juce::juce_audio_utils juce::juce_dsp)
juce_generate_juce_header(AngelVocalAI)
