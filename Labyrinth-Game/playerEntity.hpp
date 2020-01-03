#ifndef playerEntity_hpp
#define playerEntity_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayerEntity{
public:
    const float HEALTH = 100;
    const float SPEED = 250;
    
    // Where is the playerEntity
    Vector2f m_Position;
    
    //Sprite and Texture of the entity
    Sprite m_Sprite;
    Texture m_Texture;
    
    
    // How much health has the entity got?
    int m_Health;
    
    // Speed in pixels per second
    float m_Speed;
    
    // Which directions is the playerEntity currently moving in
    int m_Direction = 0; // 1 = Up, 2 = Down, 3 = Left, 4 = Right
    
    //Check if player can move to the given direction
    bool m_CanMoveUp = true;
    bool m_CanMoveLeft = true;
    bool m_CanMoveDown = true;
    bool m_CanMoveRight = true;
    
    //For Clear collision
    RectangleShape m_Rect;
    
    // Where is the enemy
    FloatRect getPosition();
    
    // Send a copy of the sprite to main
    Sprite getSprite();
    
    // How much health has the enemy currently got?
    int getHealth();
};

#endif /* playerEntity_hpp */
