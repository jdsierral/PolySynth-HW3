/*
  ==============================================================================

    PluginParams.h
    Created: 24 Oct 2016 1:12:30am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef PLUGINPARAMS_H_INCLUDED
#define PLUGINPARAMS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
//==============================================================================


class  AudioParameterCustomFloat  : public AudioProcessorParameterWithID
{
public:
    /** Creates a AudioParameterFloat with an ID, name, and range.
     On creation, its value is set to the default value.
     */
    AudioParameterCustomFloat (String parameterID, String name,
                               NormalisableRange<float> normalisableRange,
                               float defaultValue);
    
    /** Creates a AudioParameterFloat with an ID, name, and range.
     On creation, its value is set to the default value.
     For control over skew factors, you can use the other
     constructor and provide a NormalisableRange.
     */
    AudioParameterCustomFloat (String parameterID, String name,
                               float minValue,
                               float maxValue,
                               float defaultValue,
                               std::function<void(float)> initSetValueCallback);
    
    /** Destructor. */
    ~AudioParameterCustomFloat();
    
    /** Returns the parameter's current value. */
    float get() const noexcept                  { return value; }
    /** Returns the parameter's current value. */
    operator float() const noexcept             { return value; }
    
    /** Changes the parameter's current value. */
    AudioParameterCustomFloat& operator= (float newValue);
    
    /** Provides access to the parameter's range. */
    NormalisableRange<float> range;
    
    
private:
    //==============================================================================
    float value, defaultValue;
    
    float getValue() const override;
    void setValue (float newValue) override;
    float getDefaultValue() const override;
    int getNumSteps() const override;
    String getText (float, int) const override;
    float getValueForText (const String&) const override;
    
    std::function<void(float)> setValueCallback = nullptr;
    
};

//==============================================================================
//==============================================================================


class AudioParameterCustomInt  : public AudioProcessorParameterWithID
{
public:
    /** Creates an AudioParameterInt with an ID, name, and range.
     Note that the min and max range values are inclusive.
     On creation, its value is set to the default value.
     */
    AudioParameterCustomInt (String parameterID, String name,
                             int minValue, int maxValue,
                             int defaultValue, std::function<void(float)> initSetValueCallback);
    
    /** Destructor. */
    ~AudioParameterCustomInt();
    
    /** Returns the parameter's current value as an integer. */
    int get() const noexcept                    { return roundToInt (value); }
    /** Returns the parameter's current value as an integer. */
    operator int() const noexcept               { return get(); }
    
    /** Changes the parameter's current value to a new integer.
     The value passed in will be snapped to the permitted range before being used.
     */
    AudioParameterCustomInt& operator= (int newValue);
    
    /** Returns the parameter's range. */
    Range<int> getRange() const noexcept        { return Range<int> (minValue, maxValue); }
    
    
private:
    //==============================================================================
    int minValue, maxValue;
    float value, defaultValue;
    
    float getValue() const override;
    void setValue (float newValue) override;
    float getDefaultValue() const override;
    int getNumSteps() const override;
    String getText (float, int) const override;
    float getValueForText (const String&) const override;
    
    int limitRange (int) const noexcept;
    float convertTo0to1 (int) const noexcept;
    int convertFrom0to1 (float) const noexcept;
    
    std::function<void(float)> setValueCallback;
};

//==============================================================================
//==============================================================================

class AudioParameterCustomBool  : public AudioProcessorParameterWithID
{
public:
    /** Creates a AudioParameterBool with an ID and name.
     On creation, its value is set to the default value.
     */
    
    AudioParameterCustomBool
    (String parameterID, String name, bool defaultValue, std::function<void(float)> initSetValueCallback);
    
    /** Destructor. */
    ~AudioParameterCustomBool();
    
    /** Returns the parameter's current boolean value. */
    bool get() const noexcept          { return value >= 0.5f; }
    /** Returns the parameter's current boolean value. */
    operator bool() const noexcept     { return get(); }
    
    /** Changes the parameter's current value to a new boolean. */
    AudioParameterCustomBool& operator= (bool newValue);
    
    
private:
    //==============================================================================
    float value, defaultValue;
    
    float getValue() const override;
    void setValue (float newValue) override;
    float getDefaultValue() const override;
    int getNumSteps() const override;
    String getText (float, int) const override;
    float getValueForText (const String&) const override;
    
    std::function<void(float)> setValueCallback = nullptr;
    
    
};

//==============================================================================
//==============================================================================


class AudioParameterCustomChoice  : public AudioProcessorParameterWithID
{
public:
    /** Creates a AudioParameterChoice with an ID, name, and list of items.
     On creation, its value is set to the default index.
     */
    AudioParameterCustomChoice (String parameterID, String name,
                                const StringArray& choices,
                                int defaultItemIndex, std::function<void(float)> initSetValueCallback);
    
    /** Destructor. */
    ~AudioParameterCustomChoice();
    
    /** Returns the current index of the selected item. */
    int getIndex() const noexcept                   { return roundToInt (value); }
    /** Returns the current index of the selected item. */
    operator int() const noexcept                   { return getIndex(); }
    
    /** Returns the name of the currently selected item. */
    String getCurrentChoiceName() const noexcept    { return choices[getIndex()]; }
    /** Returns the name of the currently selected item. */
    operator String() const noexcept                { return getCurrentChoiceName(); }
    
    /** Changes the selected item to a new index. */
    AudioParameterCustomChoice& operator= (int newValue);
    
    /** Provides access to the list of choices that this parameter is working with. */
    const StringArray choices;
    
    float normalizeValue (int);
    
    
private:
    //==============================================================================
    float value, defaultValue;
    
    float getValue() const override;
    void setValue (float newValue) override;
    float getDefaultValue() const override;
    int getNumSteps() const override;
    String getText (float, int) const override;
    float getValueForText (const String&) const override;
    
    int limitRange (int) const noexcept;
    float convertTo0to1 (int) const noexcept;
    int convertFrom0to1 (float) const noexcept;
    
    std::function<void(float)> setValueCallback;
};



#endif  // PLUGINPARAMS_H_INCLUDED
