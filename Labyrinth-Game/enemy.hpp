#ifndef enemy_hpp
#define enemy_hpp

#include "playerEntity.hpp"

using namespace sf;

class Enemy: public PlayerEntity{
private:
    //Walking speed
    const float WALK_SPEED = 75;
    //Wait for
    int waitFor = 0;
    
    //Run to the player
    bool m_IsFocused = false;
    
public:
    bool m_GenerateRandom = true;
    
    void spawn(float startX, float startY);
    
    // Handle the player getting hit by a enemy
    bool hit();

    void runToThePlayer(bool isFocused);

    void setSpeed();
    // We will call this function once every frame
    void update();
    void updateMovement(float elapsedTime);
};


#endif /* player_hpp */
