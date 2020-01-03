#ifndef player_hpp
#define player_hpp

#include "playerEntity.hpp"
#include <math.h>       /* atan2 */

using namespace sf;

class Player: public PlayerEntity{
private:
    // What is the screen resolution
    Vector2f m_Resolution;
   
    // How big is each tile of the arena
    int m_TileSize;
    
    // When was the player last hit
    Time m_LastHit;
    
    //Check if player has key
    bool m_HasKey;
    
public:
    
    Player();
    
    void spawn(Vector2f resolution);
    
    // Call this at the end of every game
    void resetPlayerStats();
    
    // Handle the player getting hit by a enemy
    bool hit(Time timeHit);
    
    // How long ago was the player last hit
    Time getLastHitTime();
    
    // Which angle is the player facing?
    float getRotation();
    
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
