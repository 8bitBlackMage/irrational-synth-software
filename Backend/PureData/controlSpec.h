//
// Created by alice on 15/03/2020.
//

#ifndef IRRATIONALBACKEND_CONTROLSPEC_H
#define IRRATIONALBACKEND_CONTROLSPEC_H

#include <string>
#include <vector>

enum WidgetTypeIndex{
    toggle,
    slider,
    pushButton

};




struct ControlWidget
{
WidgetTypeIndex WidgetType;
std::string WidgetName;
float WidgetMinValue;
float WidgetMaxValue;
bool WidgetDefaultState;
float DataFloat;
bool DataBool;
};



class ControlSpec
{
public:
virtual std::vector<ControlWidget>& getVector() = 0;
};




#endif //IRRATIONALBACKEND_CONTROLSPEC_H
