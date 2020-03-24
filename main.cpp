#include <iostream>
#include "AudioBackend.h"
#include "Window.h"
#include "PureData_AudioProcessorDevice.h"

#define RAYGUI_IMPLEMENTATION

#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

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
    }



}
