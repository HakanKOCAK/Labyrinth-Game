#ifndef gate_hpp
#define gate_hpp

#include "gateAndWall.hpp"

class Gate: public GateAndWall{
    
private:
    int m_gateNumber;
    bool m_isOpen = false;
    
public:
    Gate();
    
    void setGateNumber(int num);
    int getGateNumber();
    
    void setRotation(float angle);
    void openTheGate();
    bool isGateOpen();
};

#endif /* gate_hpp */
