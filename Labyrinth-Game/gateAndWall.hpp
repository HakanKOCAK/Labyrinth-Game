#ifndef gateAndWall_hpp
#define gateAndWall_hpp

#include <SFML/Graphics.hpp>
using namespace sf;

class GateAndWall{
public:
    //Position
    Vector2f m_Position;
    
    //Sprite and Texture
    Sprite m_Sprite;
    Texture m_Texture;
    
    // Send a copy of the sprite to main
    Sprite getSprite();
    
    // Where is the gate or wall
    FloatRect getPosition();
    
    void setPosition(int x, int y);
    
};
#endif /* GateAndWall_hpp */
