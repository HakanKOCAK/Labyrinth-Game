#ifndef gate_hpp
#define gate_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Gate{
    
private:
    //Position
    Vector2f m_Position;
    
    Sprite m_Sprite;
    Texture m_Texture;
    int m_gateNumber;
    bool m_isOpen = false;
    
public:
    
    Gate();
    
    // Send a copy of the sprite to main
    Sprite getSprite();
    
    // Where is the wall
    FloatRect getPosition();
    
    void setPosition(int x, int y);
    
    void setGateNumber(int num);
    int getGateNumber();
    
    void setRotation(float angle);
    void openTheGate();
    bool isGateOpen();
};

#endif /* gate_hpp */
