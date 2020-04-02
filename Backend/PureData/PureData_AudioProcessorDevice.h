//
// Created by alice on 09/03/2020.
//

#ifndef IRRATIONALBACKEND_PUREDATA_AUDIOPROCESSORDEVCE_H
#define IRRATIONALBACKEND_PUREDATA_AUDIOPROCESSORDEVCE_H

#include "AudioProcessorDevice.h"
#include "PDObject.h"
#include <libpd/PdBase.hpp>

class PureData_AudioProcessorDevice: public AudioProcessorDevice{

   //libPD instance (will convert to Shared Pointer for multi device usage eventually)
    pd::PdBase m_lpd;
    PDObject m_receiver;
    //patch being processed
    pd::Patch m_Patch;
    //string to store Patch Path
    std::string m_pathToPatch;

    std::string m_patchName;

public:

    PureData_AudioProcessorDevice(std::string PatchName, std::string PatchPath = "./../patch");

    //process PD Patch
     void ProcessBuffer(void * inputBuffer, void * outputBuffer, unsigned int nFrames) override ;

     void UpdateLoop() override;

    //init PD and load patch
     void PrepareToPlay(unsigned int SampleRate, unsigned int NumChannels) override;
    PDObject* GetReciver();


};


#endif //IRRATIONALBACKEND_PUREDATA_AUDIOPROCESSORDEVCE_H
