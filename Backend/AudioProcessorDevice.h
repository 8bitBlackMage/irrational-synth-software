//
// Created by alice on 08/03/2020.
//

#ifndef IRRATIONALBACKEND_AUDIOPROCESSORDEVICE_H
#define IRRATIONALBACKEND_AUDIOPROCESSORDEVICE_H



//this is the skeleton class definition for creating subclasses that can be called by the backend
class AudioProcessorDevice{
public:
   //buffer processing function, called in the time critical audio thread, thus has to be managed carefully
   //takes void ptr buffers which can be converted to a more manageable format in the function
   //also takes an int value to tell the function how big the buffer is in frames.
   virtual void ProcessBuffer(void * inputBuffer, void * outputBuffer, unsigned int nFrames) = 0;

   //slow loop, called on the Frontend update Loop, use for interacting with frontend and other non audio thread critical functions
   virtual void UpdateLoop() = 0;


   //preparation function for audio loop function, called just before an audio stream opens
   //takes a uint for sample rate and number of output channels
   virtual void PrepareToPlay(unsigned int SampleRate, unsigned int NumChannels) = 0;
};


#endif //IRRATIONALBACKEND_AUDIOPROCESSORDEVICE_H
