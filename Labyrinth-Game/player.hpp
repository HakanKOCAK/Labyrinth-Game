//
//  player.hpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 2.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <SFML/Graphics.hpp>
#include <math.h>       /* atan2 */

using namespace sf;

class Player
{
private:
    const float HEALTH = 100;
    const float SPEED = 200;
    
    // Where is the player
    Vector2f m_Position;
    
    Sprite m_Sprite;
    Texture m_Texture;
    
    // What is the screen resolution
    Vector2f m_Resolution;
    
    // What size is the current arena
    IntRect m_Arena;
    
    // How big is each tile of the arena
    int m_TileSize;
    
    // Which directions is the player currently moving in
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
    
    // How much health has the player got?
    int m_Health;
    
    // When was the player last hit
    Time m_LastHit;
    
    // Speed in pixels per second
    float m_Speed;
    
public:
    
    Player();
    
    void spawn(IntRect arena, Vector2f resolution, int tileSize);
    
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
    
    // The next four functions move the player
    void moveLeft();
    
    void moveRight();
    
    void moveUp();
    
    void moveDown();
    
    // Stop the player moving in a specific direction
    void stopLeft();
    
    void stopRight();
    
    void stopUp();
    
    void stopDown();
    
    // We will call this function once every frame
    void update(float elapsedTime, Vector2i mousePosition);
    
    // Give player a speed boost
    void upgradeSpeed();
    
    // Give the player some health
    void upgradeHealth();
    
    // Increase the maximum amount of health the player can have
    void increaseHealthLevel(int amount);
    
    
};


#endif /* player_hpp */
