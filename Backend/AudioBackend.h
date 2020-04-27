//
// Created by alice on 08/03/2020.
//

#ifndef IRRATIONALBACKEND_AUDIOBACKEND_H
#define IRRATIONALBACKEND_AUDIOBACKEND_H

#include <RtAudio.h>
#include "AudioProcessorDevice.h"
#include <memory>




class AudioBackend{
    AudioBackend(RtAudio::Api apiToUse, unsigned int Channels,  unsigned int buffersize,int samplerate, unsigned int nbuffers, int device);
    ~AudioBackend();
    std::shared_ptr<RtAudio> soundDevice;
    unsigned int m_BufferSize;
    unsigned int m_SampleRate;
    unsigned int m_nBuffers;
    unsigned int m_Device;
    unsigned int m_Channels;



public:
    static AudioBackend& getWrapper();
    static AudioBackend& getWrapper(RtAudio::Api api_to_use, int Channels, int buffersize,int samplerate,int nbuffers, int device);

    void OpenStream();



    //delete constructors and copy function to make it a singleton
    AudioBackend (AudioBackend const&) = delete;
    void operator = (AudioBackend const&)  =delete;


    std::vector<AudioProcessorDevice*> m_Processors;




};


#endif //IRRATIONALBACKEND_AUDIOBACKEND_H
