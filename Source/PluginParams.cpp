/*
  ==============================================================================

    PluginParams.cpp
    Created: 24 Oct 2016 1:12:30am
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "PluginParams.h"


#include "PluginParams.h"


//=================================================================
//=================================================================

AudioParameterCustomFloat::AudioParameterCustomFloat
(String pid, String nm, NormalisableRange<float> r, float def)
: AudioProcessorParameterWithID (pid, nm), range (r), value (def), defaultValue (def) {
    
}


AudioParameterCustomFloat::AudioParameterCustomFloat
(String pid, String nm, float minValue, float maxValue, float def, std::function<void(float)> initSetValueCallback)
: AudioProcessorParameterWithID (pid, nm), range (minValue, maxValue), value (def), defaultValue (def) {
    setValueCallback = initSetValueCallback;
}


AudioParameterCustomFloat::~AudioParameterCustomFloat() {}

float AudioParameterCustomFloat::getValue() const {
    return range.convertTo0to1 (value);
}


void AudioParameterCustomFloat::setValue (float newValue) {
    value = range.convertFrom0to1 (newValue);
    if (setValueCallback != nullptr) {
        setValueCallback(value);
    }
}


float AudioParameterCustomFloat::getDefaultValue() const {
    return range.convertTo0to1 (defaultValue);
}


int AudioParameterCustomFloat::getNumSteps() const {
    return AudioProcessorParameterWithID::getNumSteps();
}


float AudioParameterCustomFloat::getValueForText (const String& text) const {
    return range.convertTo0to1 (text.getFloatValue());
}


String AudioParameterCustomFloat::getText (float v, int length) const {
    String asText (range.convertFrom0to1 (v), 2);
    return length > 0 ? asText.substring (0, length) : asText;
}


AudioParameterCustomFloat& AudioParameterCustomFloat::operator= (float newValue) {
    if (value != newValue)
        setValueNotifyingHost (range.convertTo0to1 (newValue));
    
    return *this;
}

//=================================================================
//=================================================================


AudioParameterCustomInt::AudioParameterCustomInt
(String pid, String nm, int mn, int mx, int def, std::function<void(float)> initSetValueCallback)
: AudioProcessorParameterWithID (pid, nm),
minValue (mn), maxValue (mx),
value ((float) def),
defaultValue (convertTo0to1 (def)) {
    jassert (minValue < maxValue); // must have a non-zero range of values!
    
    setValueCallback = initSetValueCallback;
}


AudioParameterCustomInt::~AudioParameterCustomInt() {}


int AudioParameterCustomInt::limitRange (int v) const noexcept {
    return jlimit (minValue, maxValue, v);
}


float AudioParameterCustomInt::convertTo0to1 (int v) const noexcept {
    return (limitRange (v) - minValue) / (float) (maxValue - minValue);
}


int AudioParameterCustomInt::convertFrom0to1 (float v) const noexcept {
    return limitRange (roundToInt ((v * (float) (maxValue - minValue)) + minValue));
}


float AudioParameterCustomInt::getValue() const {
    return convertTo0to1 (roundToInt (value));
}


void AudioParameterCustomInt::setValue (float newValue) {
    value = (float) convertFrom0to1 (newValue);
    if (setValueCallback != nullptr) {
        setValueCallback(value);
    }
}


float AudioParameterCustomInt::getDefaultValue() const {
    return defaultValue;
}


int AudioParameterCustomInt::getNumSteps() const {
    return AudioProcessorParameterWithID::getNumSteps();
}


float AudioParameterCustomInt::getValueForText (const String& text) const {
    return convertTo0to1 (text.getIntValue());
}


String AudioParameterCustomInt::getText (float v, int /*length*/) const {
    return String (convertFrom0to1 (v));
}


AudioParameterCustomInt& AudioParameterCustomInt::operator= (int newValue) {
    if (get() != newValue)
        setValueNotifyingHost (convertTo0to1 (newValue));
    
    return *this;
}


//=================================================================
//=================================================================



AudioParameterCustomBool::AudioParameterCustomBool
(String pid, String nm, bool def, std::function<void(float)> initSetValueCallback)
: AudioProcessorParameterWithID (pid, nm),
value (def ? 1.0f : 0.0f),
defaultValue (value) {
    setValueCallback = initSetValueCallback;
}

AudioParameterCustomBool::~AudioParameterCustomBool() {}

float AudioParameterCustomBool::getValue() const {
    return value;
}


void AudioParameterCustomBool::setValue (float newValue) {
    value = newValue;
    if (setValueCallback != nullptr) {
        setValueCallback(value);
    }
    
}


float AudioParameterCustomBool::getDefaultValue() const {
    return defaultValue;
}


int AudioParameterCustomBool::getNumSteps() const {
    return 2;
}


float AudioParameterCustomBool::getValueForText (const String& text) const {
    return text.getIntValue() != 0 ? 1.0f : 0.0f;
}


String AudioParameterCustomBool::getText (float v, int /*length*/) const {
    return String ((int) (v > 0.5f ? 1 : 0));
}

AudioParameterCustomBool& AudioParameterCustomBool::operator= (bool newValue) {
    if (get() != newValue)
        setValueNotifyingHost (newValue ? 1.0f : 0.0f);
    return *this;
}



//=================================================================
//=================================================================


AudioParameterCustomChoice::AudioParameterCustomChoice
(String pid, String nm, const StringArray& c, int def, std::function<void(float)> initSetValueCallback)
: AudioProcessorParameterWithID (pid, nm), choices (c),
value ((float) def),
defaultValue (convertTo0to1 (def)) {
    jassert (choices.size() > 0); // you must supply an actual set of items to choose from!
    
    setValueCallback = initSetValueCallback;
}


AudioParameterCustomChoice::~AudioParameterCustomChoice() {}


int AudioParameterCustomChoice::limitRange (int v) const noexcept {
    return jlimit (0, choices.size() - 1, v);
}


float AudioParameterCustomChoice::convertTo0to1 (int v) const noexcept {
    return jlimit (0.0f, 1.0f, (v + 0.5f) / (float) choices.size());
}


int AudioParameterCustomChoice::convertFrom0to1 (float v) const noexcept {
    return limitRange ((int) (v * (float) choices.size()));
}


float AudioParameterCustomChoice::getValue() const {
    return convertTo0to1 (roundToInt (value));
}


void AudioParameterCustomChoice::setValue (float newValue) {
    value = (float) convertFrom0to1 (newValue);
    if (setValueCallback != nullptr) {
        setValueCallback(value);
    }
}


float AudioParameterCustomChoice::getDefaultValue() const {
    return defaultValue;
}


int AudioParameterCustomChoice::getNumSteps() const {
    return choices.size();
}


float AudioParameterCustomChoice::getValueForText (const String& text) const {
    return convertTo0to1 (choices.indexOf (text));
}


String AudioParameterCustomChoice::getText (float v, int /*length*/) const {
    return choices [convertFrom0to1 (v)];
}


AudioParameterCustomChoice& AudioParameterCustomChoice::operator= (int newValue) {
    if (getIndex() != newValue)
        setValueNotifyingHost (convertTo0to1 (newValue));
    
    return *this;
}

float AudioParameterCustomChoice::normalizeValue(int v){
    return convertFrom0to1(v);
}