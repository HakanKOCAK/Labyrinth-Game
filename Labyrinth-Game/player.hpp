#ifndef player_hpp
#define player_hpp

#include <SFML/Graphics.hpp>
#include <math.h>       /* atan2 */

using namespace sf;

class Player
{
private:
    const float HEALTH = 100;
    const float SPEED = 250;
    
    // Where is the player
    Vector2f m_Position;
    
    Sprite m_Sprite;
    Texture m_Texture;
    
    // What is the screen resolution
    Vector2f m_Resolution;
   
    // How big is each tile of the arena
    int m_TileSize;
    
    // How much health has the player got?
    int m_Health;
    
    // When was the player last hit
    Time m_LastHit;
    
    // Speed in pixels per second
    float m_Speed;
    
    //Check if player has key
    bool m_HasKey;
    
public:
    
    Player();
    
    // Which directions is the player currently moving in
    int m_Direction = 0; // 1 = Up, 2 = Down, 3 = Left, 4 = Right
    
    //Check if player can move to the given direction
    bool m_CanMoveUp = true;
    bool m_CanMoveLeft = true;
    bool m_CanMoveDown = true;
    bool m_CanMoveRight = true;
    
    RectangleShape rect;
    
    void spawn(Vector2f resolution, int tileSize);
    
    // Call this at the end of every game
    void resetPlayerStats();
    
    // Handle the player getting hit by a zombie
    bool hit(Time timeHit);
    
    // How long ago was the player last hit
    Time getLastHitTime();
    
    // Where is the player
    FloatRect getPosition();
    
    // Where is the center of the player?
    Vector2f getCenter();
    
    // Which angle is the player facing?
    float getRotation();
    
    // Send a copy of the sprite to main
    Sprite getSprite();
    
    // How much health has the player currently got?
    int getHealth();
    
    //Check if player has a key
    bool doHaveAKey();
    
    //Set to have a key
    void setKey(bool haveAKey);
    
    // We will call this function once every frame
    void update(Vector2i mousePosition);
    void updateMovement(float elapsedTime);
    
    // Increase the maximum amount of health the player can have
    void increaseHealthLevel(int amount);
};


#endif /* player_hpp */
