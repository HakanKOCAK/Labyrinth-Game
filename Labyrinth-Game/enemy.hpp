#ifndef enemy_hpp
#define enemy_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy{
private:
    const float HEALTH = 100;
    const float RUN_SPEED = 250;
    const float WALK_SPEED = 75;
    
    // Where is the enemy
    Vector2f m_Position;
    
    Sprite m_Sprite;
    Texture m_Texture;
    
    // What is the screen resolution
    Vector2f m_Resolution;
    
    // How big is each tile of the arena
    int m_TileSize;
    
    // How much health has the enemy got?
    int m_Health;
    
    // Speed in pixels per second
    float m_Speed;
    
    
    //Wait for
    int waitFor = 0;
    
public:
    
    // Which directions is the enemy currently moving in
    int m_Direction = 0; // 1 = Up, 2 = Down, 3 = Left, 4 = Right
    
    //Check if enemy can move to the given direction
    bool m_CanMoveUp = true;
    bool m_CanMoveLeft = true;
    bool m_CanMoveDown = true;
    bool m_CanMoveRight = true;
    
    bool m_GenerateRandom = true;
    //For Clear collision
    RectangleShape m_Rect;
    
    void spawn(float startX, float startY);
    
    // Handle the player getting hit by a enemy
    bool hit();
    
    // Where is the enemy
    FloatRect getPosition();
 
    // Send a copy of the sprite to main
    Sprite getSprite();
    
    // How much health has the enemy currently got?
    int getHealth();

    // We will call this function once every frame
    void update();
    void updateMovement(float elapsedTime);
};


#endif /* player_hpp */
