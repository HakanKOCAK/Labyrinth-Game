#ifndef pickup_hpp
#define pickup_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Pickup
{
private:
    //Start value for health pickups
    const int HEALTH_VALUE = 50;
    const int AMMO_VALUE = 10;
    const int KEY_VALUE = 1;

    // The sprite that represents this pickup
    Sprite m_Sprite;
    
    // The arena it exists in
    IntRect m_Arena;
    
    // How much is this pickup worth?
    int m_Value;
    
    //Check if its still in the arena
    bool m_Spawned;
    
    // What type of pickup is this?
    // 1 = health, 2 = ammo, 3 = key
    int m_Type;
    
    //Check if is still in the arena
    bool m_IsInTheArena;
    
public:
    
    Pickup(int type);

    void setPosition(int x, int y);
    
    // Check the position of a pickup
    FloatRect getPosition();
    
    // Get the sprite for drawing
    Sprite getSprite();
    
    // Let the pickup update itself each frame
    void update(float elapsedTime);
    
    // Is this pickup currently in the arena?
    bool isInTheArena();
    
    int returnType();
    
    // Get the goodness from the pickup
    int gotIt();
};

#endif /* pickup_hpp */
