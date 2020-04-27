#include <iostream>
#include "AudioBackend.h"
#include "Window.h"
#include "PureData_AudioProcessorDevice.h"

// use this for apendix generation https://superuser.com/questions/601198/how-can-i-automatically-convert-all-source-code-files-in-a-folder-recursively
int main() {
    AudioBackend &Device = AudioBackend::getWrapper();
    PureData_AudioProcessorDevice TestDevice("Messagetest.pd");
    Window TestWin(800,480);

    Device.m_Processors.push_back(&TestDevice);
    TestWin.getWidgets(&TestDevice.GetReciver()->getVector());
    TestWin.GenerateUI();
    Device.OpenStream();
    while(!WindowShouldClose())
    {
    TestWin.UpdateLoop();
    TestDevice.UpdateLoop();
    }



}
