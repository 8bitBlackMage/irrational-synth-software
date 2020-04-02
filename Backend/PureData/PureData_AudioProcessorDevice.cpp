//
// Created by alice on 09/03/2020.
//

#include "PureData_AudioProcessorDevice.h"
#include "assert.h"
void PureData_AudioProcessorDevice::ProcessBuffer(void *inputBuffer, void *outputBuffer, unsigned int nFrames) {
    int ticks = nFrames / 64;
    m_lpd.processFloat(ticks, (float*)inputBuffer, (float*)outputBuffer);
}

void PureData_AudioProcessorDevice::PrepareToPlay(unsigned int SampleRate, unsigned int NumChannels)
{
    if(!m_lpd.init(0,NumChannels,SampleRate,false)) {
        return;
    }

    std::cout << "PD opened " << std::endl;
    m_lpd.receiveMessages();
    std::vector<ControlWidget>  Test = m_receiver.getVector();
    for(int i = 0; i < Test.size(); i++ )
    {
        std::cout << Test[i].WidgetName << " " << Test[i].WidgetType << " " << std::endl;
        
    }std::vector<ControlWidget>m_widgets;
    m_lpd.computeAudio(true);


}

PureData_AudioProcessorDevice::PureData_AudioProcessorDevice(std::string PatchName, std::string PatchPath):m_patchName(PatchName),
m_pathToPatch(PatchPath){

    m_lpd.init(0,0,0,false);
    m_lpd.setReceiver(&m_receiver);
    m_lpd.subscribe("toCPP");
    m_Patch = m_lpd.openPatch(m_patchName ,m_pathToPatch );

}

void PureData_AudioProcessorDevice::UpdateLoop() {
for(auto & Item : m_receiver.getVector())
{
    switch(Item.WidgetType){
        case(slider):
        {

         m_lpd.sendFloat(Item.WidgetName, Item.DataFloat);
         //printf("%f \n", Item.DataFloat);
        }

        case(toggle):
        {
            m_lpd.sendFloat(Item.WidgetName, Item.DataBool);
        }
    }
}
}

PDObject *PureData_AudioProcessorDevice::GetReciver() {
    return &m_receiver;
}
