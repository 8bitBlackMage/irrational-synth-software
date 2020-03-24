//
// Created by alice on 08/03/2020.
//

#ifndef IRRATIONALBACKEND_AUDIOPROCESSORDEVICE_H
#define IRRATIONALBACKEND_AUDIOPROCESSORDEVICE_H


class AudioProcessorDevice{


public:
    //audio loop function does all processing DO NOT STICK SLOW STUFF IN HERE YOU DOLT!!!!!!!
   virtual void ProcessBuffer(void * inputBuffer, void * outputBuffer, unsigned int nFrames) = 0;

   //slow loop, called on non audio thread,use for interacting with rest of the system
   virtual void UpdateLoop() = 0;


   //prep function called before playback begins
   virtual void PrepareToPlay(unsigned int SampleRate, unsigned int NumChannels) = 0;
};


#endif //IRRATIONALBACKEND_AUDIOPROCESSORDEVICE_H
