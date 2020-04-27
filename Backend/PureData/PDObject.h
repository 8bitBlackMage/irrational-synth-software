//
// Created by alice on 15/03/2020.
//

#ifndef IRRATIONALBACKEND_PDOBJECT_H
#define IRRATIONALBACKEND_PDOBJECT_H

#include <libpd/PdBase.hpp>
#include "controlSpec.h"
#include <vector>



//Pure Data message Parsing class
class PDObject : public pd::PdReceiver, public ControlSpec {

public:

    // pd message receiver callbacks
//    void print(const std::string& message);
//
//    void receiveBang(const std::string& dest);
//    void receiveFloat(const std::string& dest, float num);
//    void receiveSymbol(const std::string& dest, const std::string& symbol);
//    void receiveList(const std::string& dest, const pd::List& list);
    void receiveMessage(const std::string& dest, const std::string& msg, const pd::List& list);
    void ProcessControlMessage(const std::string& msg, const pd::List& list);
    std::vector<ControlWidget> & getVector() override;




    // pd midi receiver callbacks
//    void receiveNoteOn(const int channel, const int pitch, const int velocity);
//    void receiveControlChange(const int channel, const int controller, const int value);
//    void receiveProgramChange(const int channel, const int value);
//    void receivePitchBend(const int channel, const int value);
//    void receiveAftertouch(const int channel, const int value);
//    void receivePolyAftertouch(const int channel, const int pitch, const int value);
//
//    void receiveMidiByte(const int port, const int byte);


private:
    //storage for control objects
    std::vector<ControlWidget>m_specContainer;

};


#endif //IRRATIONALBACKEND_PDOBJECT_H
