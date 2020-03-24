//
// Created by alice on 16/03/2020.
//

#ifndef IRRATIONALBACKEND_WINDOW_H
#define IRRATIONALBACKEND_WINDOW_H

#include <raylib.h>
//#define RAYGUI_IMPLEMENTATION
//#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "ricons.h"
#undef RAYGUI_IMPLIMENTATION
#include <vector>
#include "controlSpec.h"


//custom panel struct to store x, y, width and height values along with a reference to the message controller they modifying
struct Panel{
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    ControlWidget  *controller =0;
};



class Window {
    std::vector<ControlWidget> *m_widgets = 0;
    std::vector<Panel> m_Drawbuffer;


public:
    Window(int h, int w);
    void getWidgets(std::vector<ControlWidget> *widgets);
    void UpdateLoop();

    void GenerateUI();
};


#endif //IRRATIONALBACKEND_WINDOW_H
