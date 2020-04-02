//
// Created by alice on 16/03/2020.
//

#include "Window.h"
#include <math.h>
#define RAYGUI_IMPLEMENTATION

#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

Window::Window(int h, int w) {
InitWindow(h,w,"test");
}

void Window::UpdateLoop() {
    BeginDrawing();
    ClearBackground(WHITE);

    //     GuiLock();
    for(auto & Panel : m_Drawbuffer)
    {
    switch(Panel.controller->WidgetType)
    {
        case(slider):{

            Panel.controller->DataFloat = GuiSliderBar(Rectangle{(float)Panel.x,(float)Panel.y,(float)Panel.width,(float)Panel.height},
                    Panel.controller->WidgetName.c_str(), "",
                    Panel.controller->DataFloat, Panel.controller->WidgetMinValue,Panel.controller->WidgetMaxValue);

            break;
        }
        case(toggle): {
            Panel.controller->DataBool = GuiToggle(
                    Rectangle{(float) Panel.x, (float) Panel.y, (float) Panel.width, (float) Panel.height},
                    Panel.controller->WidgetName.c_str(), Panel.controller->DataBool);
            break;
        }

        case(pushButton):{
            Panel.controller->DataBool= GuiButton(Rectangle{(float) Panel.x, (float) Panel.y, (float) Panel.width, (float) Panel.height},
             Panel.controller->WidgetName.c_str());
            break;
        }
    }
    }


    //  GuiUnlock();
    EndDrawing();
}

void Window::getWidgets(std::vector<ControlWidget> *widgets) {
m_widgets = widgets;
}

void Window::GenerateUI() {
    int xpos = 100;
    int ypos = 10;


    int max_Height = 50;
    int max_Width = 600;

    //calculate base panel size

    int Panel_Width = 600;

for(auto & widget : *m_widgets)
{
    Panel tmp;
    //TODO add XML based UI scheme system for custom UI's
    tmp.x = xpos;
    tmp.y = ypos;
    tmp.width = Panel_Width;
    tmp.height = max_Height;
    tmp.controller = &widget;
    xpos += Panel_Width + 50;
    if(xpos >= 600)
    {
        xpos = 100;
        ypos+= max_Height + 10;
    }
    m_Drawbuffer.push_back(tmp);
}
}
