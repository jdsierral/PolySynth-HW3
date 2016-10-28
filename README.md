# PolySynth-HW3

256A Third homework submission


## Summary



This is an FM + Am + RM (ring Modulation) synthesis synthesizer.

It is a plugin in AU, VST, VST3 and AU3 format. The Center xy Zone allows an intuitive mix of the three synthesis techniques of the polyphonic synthesizer. Additionally it also has a stereo Tremolo, a distortion algorithm and an envelope generator.
All of the processing code was written by Juan Sierra.

All of the synthesis techniques require a couple of oscillators that interact in certain ways to achieve the desired sound. The FM uses a carrier whose frequency is modulated by a modulator. In this case the Index of modulation is the amplitude of the modulator and the ratio is the proportion between the frequencies of the carrier and the modulator. The Am Synthesis uses a Carrier whose amplitude is modulated by the modulator. In this case the proportion of the two frequencies is also defined by the ratio knob. Finally the RM (Ring Modulation) synthesis is a product of two oscillators whose frequency proportion is defined by the ration knob aswell

Additionally each of the oscillators has a "complexity" parameter which is a distortion generator.

$y=\frac{\left| \left( \sin \left( x \right) \right) \right|^{1.2^{20}}}{1}$

Finally the tremolo allows for stereo amplitude modulation to produce a stereo effect.

## Usage

It is intended to be used inside a DAW with the midi messages generated from within the DAW. Additionally it is completely optimized to allow for automation and save and recall presets as a regular plugin would.

## Code Description

The whole project is structured on the AudioProcessor class and the AudioEditor class.
The MainProcessor will be the holder for all the audio related stuff. It is holding the Synthsizer class which manages the sound class and the voice class. Inside the voice class lives the generator class which holds all the oscillators. The voice Class is also owner of the Enveloper Class.

Regarding the Tremolo, it lives inside the processor class as it affects the output of the synthesizer class.

The MainEditor will be responsible for all the gui and the interaction with the user through sliders and mouseListeners
therefore it will inherit from sliderListener class.

There is a special relation between the processor and the editor.
The editor is created by the processor which during its initialization passes a pointer to the editor object of itself;
therefore the editor has access to all of the processor's public methods and fields and the processor has access to all of
the editors public methods and fields and is actually the holder for the editor taking care of its lifetime.

Take into account that this requires a circular inclusion of the processor's header on the  editor's header and also of the editor's header in the processor's header. To avoid this a dummy class is created on the processor's header for it to be able to create the pointer that will store, during initialization, the address of the editor. This is the main reason for splitting the project into .cpp and .h files in the editor as well as in the processor part of the program

Finally all the information between the editor and the processor is handled by the AudioProcessorEditor class which allows for correct scaling and reports to the DAW so that all of its parameters are automation-ready. This also allows for independance between the editor and the GUI as the GUI wont actually exist if the window of the plugin is not opened, however the processor must be able to continue its job when this happends. 

## Example of Use

see this youTube video to check how the synthesizer works and sounds ;)


https://youtu.be/9c0S9eRqLmk


## History

Single Commit repo

## Contributing

Created by Juan Sierra
Contributions and greatly appreciated advices by Megan and Rahul

## License

MIT License

Copyright (c) 2016 - Juan Sierra, JuanSaudio

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE
